local olua = require "olua.olua-io"

local format = olua.format

local function get_callback_store(fi, idx)
    local idx = idx or fi.CALLBACK_OPT.TAG_STORE or 0
    if idx < 0 then
        idx = idx + #fi.ARGS + 1
        assert(idx >= 0, fi.CALLBACK_OPT.TAG_MAKER)
    end
    assert(idx <= #fi.ARGS)
    return idx
end

local function gen_maker(cls, fi, write)
    if not fi.CALLBACK_OPT.TAG_MAKER then
        error(string.format("no tag maker: %s.%s", cls.CPPCLS, fi.LUAFUNC))
    end

    local maker = string.gsub(fi.CALLBACK_OPT.TAG_MAKER, '#(%-?%d+)', function (n)
        local idx = get_callback_store(fi, tonumber(n))
        if idx == 0 then
            return "self"
        else
            return "arg" .. idx
        end
    end)
    return string.gsub(maker, '%(%)', '("")')
end

local function gen_remove_callback(cls, fi, write)
    local TAG_MODE = fi.CALLBACK_OPT.TAG_MODE
    local TAG_MAKER = gen_maker(cls, fi, write)
    local CALLBACK_STORE_OBJ
    local TAG_STORE = get_callback_store(fi)

    if TAG_STORE == 0 then
        CALLBACK_STORE_OBJ = 'self'
        if fi.STATIC then
            local LUACLS = cls.LUACLS
            CALLBACK_STORE_OBJ = format('olua_getstoreobj(L, "${LUACLS}")')
        end
    else
        CALLBACK_STORE_OBJ = 'arg' .. TAG_STORE
    end

    local block = format([[
        std::string tag = ${TAG_MAKER};
        void *callback_store_obj = (void *)${CALLBACK_STORE_OBJ};
        olua_removecallback(L, callback_store_obj, tag.c_str(), ${TAG_MODE});
    ]])
    return block
end

function gen_ret_callback(cls, fi, write)
    local TAG_MODE = fi.CALLBACK_OPT.TAG_MODE
    local TAG_MAKER = gen_maker(cls, fi, write)
    local CALLBACK_STORE_OBJ
    local TAG_STORE = get_callback_store(fi)

    if TAG_STORE == 0 then
        CALLBACK_STORE_OBJ = 'self'
    else
        CALLBACK_STORE_OBJ = 'arg' .. TAG_STORE
    end

    local block = format([[
        void *callback_store_obj = (void *)${CALLBACK_STORE_OBJ};
        std::string tag = ${TAG_MAKER};
        olua_getcallback(L, callback_store_obj, tag.c_str(), ${TAG_MODE});
    ]])
    return block
end

function gen_callback(cls, fi, write)
    local ai
    local IDX = 0
    local ARG_N = ""

    if not fi.STATIC then
        IDX = IDX + 1
    end

    for i, v in ipairs(fi.ARGS) do
        IDX = IDX + 1
        if v.CALLBACK.ARGS then
            ARG_N = 'arg' .. i
            ai = v
            break
        end
    end

    if fi.CALLBACK_OPT.REMOVE then
        return gen_remove_callback(cls, fi, write)
    end

    if fi.RET.TYPE.CPPCLS == "std::function" then
        return gen_ret_callback(cls, fi, write)
    end

    if not ai then
        return ''
    end

    local TAG_MAKER = gen_maker(cls, fi, write)
    local REMOVE_CALLBACK = ""
    local OLUA_CALLBACK_TAG = assert(fi.CALLBACK_OPT.TAG_MODE, 'no tag mode')
    local NUM_ARGS = #ai.CALLBACK.ARGS
    local ARGS = {}
    local PUSH_ARGS = {}
    local POP_OBJPOOL = ""
    local CALLBACK_STORE_OBJ
    local TAG_STORE
    local RESULT_DECL = ""
    local RESULT_RET = ""
    local RESULT_GET = ""
    local INJECT_CALLBACK_AFTER = fi.INJECT.CALLBACK_AFTER or ''
    local INJECT_CALLBACK_BEFORE = fi.INJECT.CALLBACK_BEFORE or ''
    local HAS_STACK_BEGIN = false

    for _, v in ipairs(ai.CALLBACK.ARGS) do
        if v.ATTR.TEMP then
            PUSH_ARGS[#PUSH_ARGS + 1] = "size_t last = olua_push_objpool(L);"
            POP_OBJPOOL = format([[
                //pop stack value
                olua_pop_objpool(L, last);
            ]])
           break
        end
    end

    for i, v in ipairs(ai.CALLBACK.ARGS) do
        local ARG_N = 'arg' .. i
        local PUSH_FUNC = v.TYPE.FUNC_PUSH_VALUE

        if v.ATTR.TEMP then
            if not HAS_STACK_BEGIN then
                HAS_STACK_BEGIN = true
                PUSH_ARGS[#PUSH_ARGS + 1] = "olua_enable_objpool(L);"
            end
        elseif HAS_STACK_BEGIN then
            HAS_STACK_BEGIN = false
            PUSH_ARGS[#PUSH_ARGS + 1] = "olua_disable_objpool(L);"
        end
    
        if v.TYPE.LUACLS and v.TYPE.DECL_TYPE ~= 'lua_Unsigned' then
            local LUACLS = v.TYPE.LUACLS
            if PUSH_FUNC == "olua_push_cppobj" then
                local CPPCLS = string.gsub(v.TYPE.CPPCLS, '[ *]*$', '')
                PUSH_ARGS[#PUSH_ARGS + 1] = format([[
                    ${PUSH_FUNC}<${CPPCLS}>(L, ${ARG_N}, "${LUACLS}");
                ]])
            else
                PUSH_ARGS[#PUSH_ARGS + 1] = format([[
                    ${PUSH_FUNC}(L, ${ARG_N}, "${LUACLS}");
                ]])
            end
        elseif v.TYPE.SUBTYPE then
            local SUBTYPE = assert(v.TYPE.SUBTYPE.LUACLS, v.TYPE.DECL_TYPE)
            PUSH_ARGS[#PUSH_ARGS + 1] = format([[
                ${PUSH_FUNC}(L, ${ARG_N}, "${SUBTYPE}");
            ]])
        else
            local CAST = ""
            if v.TYPE.DECL_TYPE ~= v.TYPE.CPPCLS then
                CAST = string.format("(%s)", v.TYPE.DECL_TYPE)
            elseif not olua.isvaluetype(v.TYPE) then
                if not string.find(v.TYPE.DECL_TYPE, '*$') then
                    CAST = '&'
                end
            end
            PUSH_ARGS[#PUSH_ARGS + 1] = format([[
                ${PUSH_FUNC}(L, ${CAST}${ARG_N});
            ]])
        end

        local DECL_TYPE = v.FUNC_ARG_DECL_TYPE
        local SPACE = string.find(DECL_TYPE, '[*&]$') and '' or ' '
        ARGS[#ARGS + 1] = format([[
            ${DECL_TYPE}${SPACE}${ARG_N}
        ]])
    end

    if HAS_STACK_BEGIN then
        PUSH_ARGS[#PUSH_ARGS + 1] = "olua_disable_objpool(L);"
        HAS_STACK_BEGIN = false
    end

    ARGS = table.concat(ARGS, ", ")
    PUSH_ARGS = table.concat(PUSH_ARGS, "\n")

    if fi.CALLBACK_OPT.CALLONCE then
        REMOVE_CALLBACK = format([[
            olua_removecallback(L, callback_store_obj, func.c_str(), OLUA_CALLBACK_TAG_EQUAL);
        ]])
    end

    if fi.CALLBACK_OPT.CALLBACK_REPLACE then
        OLUA_CALLBACK_TAG = "OLUA_CALLBACK_TAG_REPLACE"
    end

    if ai.CALLBACK.RET.CPPCLS ~= "void" then
        local DECL_TYPE = ai.CALLBACK.RET.DECL_TYPE
        local INIT_VALUE = ai.CALLBACK.RET.INIT_VALUE
        local FUNC_CHECK_VALUE = ai.CALLBACK.RET.FUNC_CHECK_VALUE
        if INIT_VALUE then
            RESULT_DECL = format([[
                ${DECL_TYPE} ret = ${INIT_VALUE};
            ]])
        else
             RESULT_DECL = format([[
                ${DECL_TYPE} ret;
            ]])
        end
        if ai.CALLBACK.RET.LUACLS then
            local LUACLS = ai.CALLBACK.RET.LUACLS
            RESULT_GET = format([[
                ${FUNC_CHECK_VALUE}(L, -1, (void **)&ret, "${LUACLS}");
            ]])
        else
            RESULT_GET = format([[
                ${FUNC_CHECK_VALUE}(L, -1, &ret);
            ]])
        end
        RESULT_RET = "return ret;"
    end

    TAG_STORE = get_callback_store(fi) + 1
    if TAG_STORE == 1 then
        CALLBACK_STORE_OBJ = 'self'
        if fi.STATIC and fi.RET.TYPE.CPPCLS == 'void' then
            local LUACLS = cls.LUACLS
            CALLBACK_STORE_OBJ = format('olua_getstoreobj(L, "${LUACLS}")')
        end
    else
        CALLBACK_STORE_OBJ = 'arg' .. (TAG_STORE - 1)
    end

    if #INJECT_CALLBACK_BEFORE > 0 then
        INJECT_CALLBACK_BEFORE = format [[
            // inject code before call
            ${INJECT_CALLBACK_BEFORE}
        ]]
    end

    if #INJECT_CALLBACK_AFTER > 0 then
        INJECT_CALLBACK_AFTER = format [[
            // inject code after call
            ${INJECT_CALLBACK_AFTER}
        ]]
    end

    assert(OLUA_CALLBACK_TAG == 'OLUA_CALLBACK_TAG_REPLACE' or
        OLUA_CALLBACK_TAG == 'OLUA_CALLBACK_TAG_NEW', OLUA_CALLBACK_TAG)

    local CALLBACK_CHUNK = format([[
        void *callback_store_obj = (void *)${CALLBACK_STORE_OBJ};
        std::string tag = ${TAG_MAKER};
        std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), ${IDX}, ${OLUA_CALLBACK_TAG});
        ${ARG_N} = [callback_store_obj, func, tag](${ARGS}) {
            lua_State *L = olua_mainthread();
            int top = lua_gettop(L);
            ${RESULT_DECL}
            ${PUSH_ARGS}

            ${INJECT_CALLBACK_BEFORE}

            olua_callback(L, callback_store_obj, func.c_str(), ${NUM_ARGS});
            ${RESULT_GET}

            ${INJECT_CALLBACK_AFTER}

            ${REMOVE_CALLBACK}
            
            ${POP_OBJPOOL}

            lua_settop(L, top);
            ${RESULT_RET}
        };
    ]])
    if ai.CALLBACK.DEFAULT or ai.ATTR.NULLABLE then
        local DEFAULT = ai.CALLBACK.DEFAULT or "nullptr"
        local FUNC_IS_VALUE = ai.TYPE.FUNC_IS_VALUE
        CALLBACK_CHUNK = format([[
            if (${FUNC_IS_VALUE}(L, ${IDX})) {
                ${CALLBACK_CHUNK}
            } else {
                void *callback_store_obj = (void *)${CALLBACK_STORE_OBJ};
                std::string tag = ${TAG_MAKER};
                olua_removecallback(L, callback_store_obj, tag.c_str(), OLUA_CALLBACK_TAG_ENDWITH);
                ${ARG_N} = ${DEFAULT};
            }
        ]])
    end

    return CALLBACK_CHUNK
end