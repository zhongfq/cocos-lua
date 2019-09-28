local olua = require "olua.olua-io"

local format = olua.format

local function getCallbackStore(fi, idx)
    idx = idx or fi.CALLBACK_OPT.TAG_STORE or 0
    if idx < 0 then
        idx = idx + #fi.ARGS + 1
    end
    olua.assert(idx <= #fi.ARGS and idx >= 0, "store index '%d' out of range", idx)

    return idx
end

local function genCallbackTag(cls, fi, write)
    if not fi.CALLBACK_OPT.TAG_MAKER then
        olua.error("no tag maker: %s.%s", cls.CPPCLS, fi.LUAFUNC)
    end

    return string.gsub(fi.CALLBACK_OPT.TAG_MAKER, '#(%-?%d+)', function (n)
        local idx = getCallbackStore(fi, tonumber(n))
        return idx == 0 and 'self' or ('arg' .. idx)
    end)
end

local function checkCallbackStore(fi, idx)
    if idx > 0 then
        local ai = fi.ARGS[idx]
        olua.assert(olua.ispointee(ai.TYPE), 'arg #%d is not a userdata', idx)
    end
end

local function genRemoveCallback(cls, fi, write)
    local TAG_MODE = fi.CALLBACK_OPT.TAG_MODE
    local TAG_MAKER = genCallbackTag(cls, fi, write)
    local CALLBACK_STORE_OBJ
    local TAG_STORE = getCallbackStore(fi)

    if TAG_STORE == 0 then
        CALLBACK_STORE_OBJ = 'self'
        if fi.STATIC then
            CALLBACK_STORE_OBJ = format('olua_getstoreobj(L, "${cls.LUACLS}")')
        end
    else
        CALLBACK_STORE_OBJ = 'arg' .. TAG_STORE
        checkCallbackStore(fi, TAG_STORE)
    end

    local block = format([[
        std::string tag = ${TAG_MAKER};
        void *callback_store_obj = (void *)${CALLBACK_STORE_OBJ};
        olua_removecallback(L, callback_store_obj, tag.c_str(), ${TAG_MODE});
    ]])
    olua.nowarning(TAG_MODE, TAG_MAKER, CALLBACK_STORE_OBJ)
    return block
end

local function genRetCallback(cls, fi, write)
    local TAG_MODE = fi.CALLBACK_OPT.TAG_MODE
    local TAG_MAKER = genCallbackTag(cls, fi, write)
    local CALLBACK_STORE_OBJ
    local TAG_STORE = getCallbackStore(fi)

    if TAG_STORE == 0 then
        CALLBACK_STORE_OBJ = 'self'
    else
        CALLBACK_STORE_OBJ = 'arg' .. TAG_STORE
        checkCallbackStore(TAG_STORE)
    end

    local block = format([[
        void *callback_store_obj = (void *)${CALLBACK_STORE_OBJ};
        std::string tag = ${TAG_MAKER};
        olua_getcallback(L, callback_store_obj, tag.c_str(), ${TAG_MODE});
    ]])
    olua.nowarning(TAG_MODE, TAG_MAKER, CALLBACK_STORE_OBJ)
    return block
end

function olua.genCallback(cls, fi, write)
    if fi.CALLBACK_OPT.REMOVE then
        return genRemoveCallback(cls, fi, write)
    end

    if fi.RET.TYPE.CPPCLS == "std::function" then
        return genRetCallback(cls, fi, write)
    end

    local ai
    local IDX = not fi.STATIC and 1 or 0
    local CALLBACK_ARG_NAME = ""

    for i, v in ipairs(fi.ARGS) do
        IDX = IDX + 1
        if v.CALLBACK.ARGS then
            CALLBACK_ARG_NAME = 'arg' .. i
            ai = v
            break
        end
    end

    if not ai then
        return ''
    end

    local OLUA_CALLBACK_TAG = assert(fi.CALLBACK_OPT.TAG_MODE, 'no tag mode')
    local TAG_MAKER = genCallbackTag(cls, fi, write)
    local CALLBACK_STORE_OBJ
    local TAG_STORE
   
    local enablepool = false

    local CALLBACK = {
        ARGS = olua.newarray(),
        NUM_ARGS = #ai.CALLBACK.ARGS,
        PUSH_ARGS = olua.newarray(),
        REMOVE_CALLBACK = "",
        POP_OBJPOOL = "",
        DECL_RESULT = "",
        RETURN_RESULT = "",
        CHECK_RESULT = "",
        INJECT_BEFORE = olua.newarray(fi.INJECT.CALLBACK_BEFORE),
        INJECT_AFTER = olua.newarray(fi.INJECT.CALLBACK_AFTER),
    }

    for _, v in ipairs(ai.CALLBACK.ARGS) do
        if v.ATTR.LOCAL then
            CALLBACK.PUSH_ARGS:push( "size_t last = olua_push_objpool(L);")
            CALLBACK.POP_OBJPOOL = format([[
                //pop stack value
                olua_pop_objpool(L, last);
            ]])
           break
        end
    end

    for i, v in ipairs(ai.CALLBACK.ARGS) do
        local ARG_NAME = 'arg' .. i

        if v.ATTR.LOCAL then
            if not enablepool then
                enablepool = true
                CALLBACK.PUSH_ARGS:push("olua_enable_objpool(L);")
            end
        elseif enablepool then
            enablepool = false
            CALLBACK.PUSH_ARGS:push("olua_disable_objpool(L);")
        end

        olua.genPushExp(v, ARG_NAME, CALLBACK)

        local SPACE = string.find(v.RAW_DECLTYPE, '[*&]$') and '' or ' '
        CALLBACK.ARGS:push(format([[
            ${v.RAW_DECLTYPE}${SPACE}${ARG_NAME}
        ]]))
        olua.nowarning(SPACE)
    end

    if enablepool then
        CALLBACK.PUSH_ARGS:push("olua_disable_objpool(L);")
        enablepool = false
    end

    if fi.CALLBACK_OPT.CALLONCE then
        CALLBACK.REMOVE_CALLBACK = format([[
            olua_removecallback(L, callback_store_obj, func.c_str(), OLUA_TAG_NONE);
        ]])
    end

    local RET = ai.CALLBACK.RET
    if RET.TYPE.CPPCLS ~= "void" then
        local OUT = {
            DECL_ARGS = olua.newarray(),
            CHECK_ARGS = olua.newarray(),
            PUSH_ARGS = olua.newarray(),
        }
        olua.genDeclExp(RET, 'ret', OUT)
        olua.genCheckExp(RET, 'ret', -1, OUT)
        CALLBACK.DECL_RESULT = OUT.DECL_ARGS
        CALLBACK.CHECK_RESULT = OUT.CHECK_ARGS

        local OLUA_IS_VALUE = olua.convfunc(RET.TYPE, 'is')
        if olua.ispointee(RET.TYPE) then
            CALLBACK.CHECK_RESULT = format([[
                if (${OLUA_IS_VALUE}(L, -1, "${RET.TYPE.LUACLS}")) {
                    ${CALLBACK.CHECK_RESULT}
                }
            ]])
        else
            CALLBACK.CHECK_RESULT = format([[
                if (${OLUA_IS_VALUE}(L, -1)) {
                    ${CALLBACK.CHECK_RESULT}
                }
            ]])
        end

        if RET.TYPE.DECLTYPE ~= RET.TYPE.CPPCLS then
            CALLBACK.RETURN_RESULT = format([[return (${RET.TYPE.CPPCLS})ret;]])
        else
            CALLBACK.RETURN_RESULT = "return ret;"
        end

        olua.nowarning(OLUA_IS_VALUE)
    end

    TAG_STORE = getCallbackStore(fi) + 1
    if TAG_STORE == 1 then
        CALLBACK_STORE_OBJ = 'self'
        if fi.STATIC and fi.RET.TYPE.CPPCLS == 'void' then
            CALLBACK_STORE_OBJ = format('olua_getstoreobj(L, "${cls.LUACLS}")')
        end
    else
        CALLBACK_STORE_OBJ = 'arg' .. (TAG_STORE - 1)
    end

    CALLBACK.ARGS = table.concat(CALLBACK.ARGS, ", ")

    if #CALLBACK.INJECT_BEFORE > 0 then
        CALLBACK.INJECT_BEFORE = format [[
            // inject code before call
            ${CALLBACK.INJECT_BEFORE}
        ]]
    end

    if #CALLBACK.INJECT_AFTER > 0 then
        CALLBACK.INJECT_AFTER = format [[
            // inject code after call
            ${CALLBACK.INJECT_AFTER}
        ]]
    end

    olua.assert(OLUA_CALLBACK_TAG == 'OLUA_TAG_REPLACE' or
        OLUA_CALLBACK_TAG == 'OLUA_TAG_NEW',
        "expect '%s' or '%s', got '%s'",
        'OLUA_TAG_REPLACE', 'OLUA_TAG_NEW',
        OLUA_CALLBACK_TAG
    )

    local CALLBACK_CHUNK = format([[
        void *callback_store_obj = (void *)${CALLBACK_STORE_OBJ};
        std::string tag = ${TAG_MAKER};
        std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), ${IDX}, ${OLUA_CALLBACK_TAG});
        lua_State *MT = olua_mainthread();
        ${CALLBACK_ARG_NAME} = [callback_store_obj, func, MT](${CALLBACK.ARGS}) {
            lua_State *L = olua_mainthread();
            ${CALLBACK.DECL_RESULT}
            if (MT == L) {
                int top = lua_gettop(L);
                ${CALLBACK.PUSH_ARGS}

                ${CALLBACK.INJECT_BEFORE}

                olua_callback(L, callback_store_obj, func.c_str(), ${CALLBACK.NUM_ARGS});
                
                ${CALLBACK.CHECK_RESULT}

                ${CALLBACK.INJECT_AFTER}

                ${CALLBACK.REMOVE_CALLBACK}
                
                ${CALLBACK.POP_OBJPOOL}
                lua_settop(L, top);
            }
            ${CALLBACK.RETURN_RESULT}
        };
    ]])

    if ai.CALLBACK.DEFAULT or ai.ATTR.NULLABLE then
        local DEFAULT = ai.CALLBACK.DEFAULT or "nullptr"
        local OLUA_IS_VALUE = olua.convfunc(ai.TYPE, 'is')
        CALLBACK_CHUNK = format([[
            if (${OLUA_IS_VALUE}(L, ${IDX})) {
                ${CALLBACK_CHUNK}
            } else {
                void *callback_store_obj = (void *)${CALLBACK_STORE_OBJ};
                std::string tag = ${TAG_MAKER};
                olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_TAG_EQUAL);
                ${CALLBACK_ARG_NAME} = ${DEFAULT};
            }
        ]])
        olua.nowarning(DEFAULT, OLUA_IS_VALUE)
    end

    olua.nowarning(CALLBACK_ARG_NAME, TAG_MAKER, CALLBACK_STORE_OBJ)

    return CALLBACK_CHUNK
end