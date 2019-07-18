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
        olua.assert(ai.TYPE.LUACLS and not olua.isvaluetype(ai.TYPE),
            'arg #%d is not a userdata', idx)
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

function olua.gencallback(cls, fi, write)
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
        if v.ATTR.TEMP then
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
        local OLUA_PUSH_VALUE = olua.convfunc(v.TYPE, 'push')

        if v.ATTR.TEMP then
            if not enablepool then
                enablepool = true
                CALLBACK.PUSH_ARGS:push("olua_enable_objpool(L);")
            end
        elseif enablepool then
            enablepool = false
            CALLBACK.PUSH_ARGS:push("olua_disable_objpool(L);")
        end
    
        if v.TYPE.LUACLS and not olua.isvaluetype(v.TYPE) then
            CALLBACK.PUSH_ARGS:push(format([[
                ${OLUA_PUSH_VALUE}(L, ${ARG_NAME}, "${v.TYPE.LUACLS}");
            ]]))
        elseif v.TYPE.SUBTYPE then
            local SUBTYPE = v.TYPE.SUBTYPE
            if SUBTYPE.LUACLS and not olua.isvaluetype(SUBTYPE) then
                CALLBACK.PUSH_ARGS:push(format([[
                    ${OLUA_PUSH_VALUE}(L, ${ARG_NAME}, "${SUBTYPE.LUACLS}");
                ]]))
            else
                local SUBTYPE_CAST = olua.pointercast(SUBTYPE) .. olua.typecast(SUBTYPE)
                local SUBTYPE_PUSH_FUNC = olua.convfunc(SUBTYPE, 'push')
                local TYPE_CAST = string.gsub(v.DECLTYPE, '^const _*', '')
                local PUSH_VALUETYPE = format(fi.RET.TYPE.PUSH_VALUETYPE)
                CALLBACK.PUSH_ARGS:push(format(fi.RET.TYPE.PUSH_VALUETYPE))
                olua.nowarning(ARG_NAME, SUBTYPE_CAST, SUBTYPE_PUSH_FUNC, TYPE_CAST, PUSH_VALUETYPE)
            end
        else
            local TYPE_CAST = ""
            if v.TYPE.DECLTYPE ~= v.TYPE.CPPCLS then
                TYPE_CAST = string.format("(%s)", v.TYPE.DECLTYPE)
            elseif not olua.isvaluetype(v.TYPE) then
                if not string.find(v.TYPE.DECLTYPE, '*$') then
                    TYPE_CAST = '&'
                end
            end
            CALLBACK.PUSH_ARGS:push(format([[
                ${OLUA_PUSH_VALUE}(L, ${TYPE_CAST}${ARG_NAME});
            ]]))
            olua.nowarning(TYPE_CAST)
        end

        local SPACE = string.find(v.RAW_DECLTYPE, '[*&]$') and '' or ' '
        CALLBACK.ARGS:push(format([[
            ${v.RAW_DECLTYPE}${SPACE}${ARG_NAME}
        ]]))
        olua.nowarning(SPACE, OLUA_PUSH_VALUE)
    end

    if enablepool then
        CALLBACK.PUSH_ARGS:push("olua_disable_objpool(L);")
        enablepool = false
    end

    if fi.CALLBACK_OPT.CALLONCE then
        CALLBACK.REMOVE_CALLBACK = format([[
            olua_removecallback(L, callback_store_obj, func.c_str(), OLUA_CALLBACK_TAG_EQUAL);
        ]])
    end

    if fi.CALLBACK_OPT.CALLBACK_REPLACE then
        OLUA_CALLBACK_TAG = "OLUA_CALLBACK_TAG_REPLACE"
    end

    local RET = ai.CALLBACK.RET
    if RET.TYPE.CPPCLS ~= "void" then
        local FUNC_CHECK_VALUE = olua.convfunc(RET.TYPE, 'check')
        if RET.TYPE.INIT_VALUE then
            CALLBACK.DECL_RESULT = format([[
                ${RET.TYPE.DECLTYPE} ret = ${RET.TYPE.INIT_VALUE};
            ]])
        else
            CALLBACK.DECL_RESULT = format([[
                ${RET.TYPE.DECLTYPE} ret;
            ]])
        end
        if RET.TYPE.LUACLS and not olua.isvaluetype(RET.TYPE) then
            CALLBACK.CHECK_RESULT = format([[
                ${FUNC_CHECK_VALUE}(L, -1, (void **)&ret, "${RET.TYPE.LUACLS}");
            ]])
        elseif RET.TYPE.SUBTYPE then
            local SUBTYPE = RET.TYPE.SUBTYPE
            if SUBTYPE.LUACLS and not olua.isvaluetype(RET.TYPE) then
                CALLBACK.CHECK_RESULT = format([[
                    ${FUNC_CHECK_VALUE}(L, -1, ret, "${SUBTYPE.LUACLS}");
                ]])
            else
                local ARG_NAME = "ret"
                local SUBTYPE_CHECK_FUNC = olua.convfunc(SUBTYPE, 'check')
                local SUBTYPE_CAST = olua.typecast(SUBTYPE, true)
                local CHECK_VALUETYPE = format(RET.TYPE.CHECK_VALUETYPE)
                olua.nowarning(ARG_NAME, SUBTYPE_CHECK_FUNC, SUBTYPE_CAST, CHECK_VALUETYPE)
                CALLBACK.CHECK_RESULT = format([[
                    luaL_checktype(L, -1, LUA_TTABLE);
                    ${CHECK_VALUETYPE}
                ]])
            end
        else
            CALLBACK.CHECK_RESULT = format([[
                ${FUNC_CHECK_VALUE}(L, -1, &ret);
            ]])
        end
        if RET.TYPE.DECLTYPE ~= RET.TYPE.CPPCLS then
            CALLBACK.RETURN_RESULT = format([[return (${RET.TYPE.CPPCLS})ret;]])
        else
            CALLBACK.RETURN_RESULT = "return ret;"
        end
        olua.nowarning(FUNC_CHECK_VALUE)
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
    CALLBACK.PUSH_ARGS = table.concat(CALLBACK.PUSH_ARGS, "\n")
    CALLBACK.INJECT_BEFORE = table.concat(CALLBACK.INJECT_BEFORE, '\n')
    CALLBACK.INJECT_AFTER = table.concat(CALLBACK.INJECT_AFTER, '\n')

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

    olua.assert(OLUA_CALLBACK_TAG == 'OLUA_CALLBACK_TAG_REPLACE' or
        OLUA_CALLBACK_TAG == 'OLUA_CALLBACK_TAG_NEW',
        "expect '%s' or '%s', got '%s'",
        'OLUA_CALLBACK_TAG_REPLACE', 'OLUA_CALLBACK_TAG_NEW',
        OLUA_CALLBACK_TAG
    )

    local CALLBACK_CHUNK = format([[
        void *callback_store_obj = (void *)${CALLBACK_STORE_OBJ};
        std::string tag = ${TAG_MAKER};
        std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), ${IDX}, ${OLUA_CALLBACK_TAG});
        ${CALLBACK_ARG_NAME} = [callback_store_obj, func, tag](${CALLBACK.ARGS}) {
            lua_State *L = olua_mainthread();
            int top = lua_gettop(L);
            ${CALLBACK.DECL_RESULT}
            ${CALLBACK.PUSH_ARGS}

            ${CALLBACK.INJECT_BEFORE}

            olua_callback(L, callback_store_obj, func.c_str(), ${CALLBACK.NUM_ARGS});
            ${CALLBACK.CHECK_RESULT}

            ${CALLBACK.INJECT_AFTER}

            ${CALLBACK.REMOVE_CALLBACK}
            
            ${CALLBACK.POP_OBJPOOL}

            lua_settop(L, top);
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
                olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_CALLBACK_TAG_ENDWITH);
                ${CALLBACK_ARG_NAME} = ${DEFAULT};
            }
        ]])
        olua.nowarning(DEFAULT, OLUA_IS_VALUE)
    end

    olua.nowarning(CALLBACK_ARG_NAME, TAG_MAKER, CALLBACK_STORE_OBJ)

    return CALLBACK_CHUNK
end