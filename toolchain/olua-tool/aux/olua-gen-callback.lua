local function get_callback_store(fi, idx)
    local idx = idx or fi.CALLBACK_OPT.CALLBACK_STORE or 0
    if idx < 0 then
        idx = idx + #fi.ARGS + 1
        assert(idx >= 0, fi.CALLBACK_OPT.CALLBACK_MAKER)
    end
    assert(idx <= #fi.ARGS)
    return idx
end

local function gen_maker(cls, fi, write)
    if not fi.CALLBACK_OPT.CALLBACK_MAKER then
        error(string.format("no tag maker: %s.%s", cls.CPPCLS, fi.LUAFUNC))
    end

    local maker = string.gsub(fi.CALLBACK_OPT.CALLBACK_MAKER, '#(%-?%d+)', function (n)
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
    local CALLBACK_MODE = fi.CALLBACK_OPT.CALLBACK_MODE
    local CALLBACK_MAKER = gen_maker(cls, fi, write)
    local CALLBACK_STORE_OBJ
    local CALLBACK_STORE = get_callback_store(fi)

    if CALLBACK_STORE == 0 then
        CALLBACK_STORE_OBJ = 'self'
        if fi.STATIC then
            local LUACLS = cls.LUACLS
            CALLBACK_STORE_OBJ = format_snippet('olua_callbackstore(L, "${LUACLS}")')
        end
    else
        CALLBACK_STORE_OBJ = 'arg' .. CALLBACK_STORE
    end

    local block = format_snippet([[
        std::string tag = ${CALLBACK_MAKER};
        void *callback_store_obj = (void *)${CALLBACK_STORE_OBJ};
        olua_removecallback(L, callback_store_obj, tag.c_str(), ${CALLBACK_MODE});
    ]])
    return block
end

function gen_ret_callback(cls, fi, write)
    local CALLBACK_MODE = fi.CALLBACK_OPT.CALLBACK_MODE
    local CALLBACK_MAKER = gen_maker(cls, fi, write)
    local CALLBACK_STORE_OBJ
    local CALLBACK_STORE = get_callback_store(fi)

    if CALLBACK_STORE == 0 then
        CALLBACK_STORE_OBJ = 'self'
    else
        CALLBACK_STORE_OBJ = 'arg' .. CALLBACK_STORE
    end

    local block = format_snippet([[
        void *callback_store_obj = (void *)${CALLBACK_STORE_OBJ};
        std::string tag = ${CALLBACK_MAKER};
        olua_getcallback(L, callback_store_obj, tag.c_str(), ${CALLBACK_MODE});
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

    if fi.CALLBACK_OPT.CALLBACK_REMOVE then
        return gen_remove_callback(cls, fi, write)
    end

    if fi.RET.TYPE.TYPENAME == "std::function" then
        return gen_ret_callback(cls, fi, write)
    end

    assert(ai, cls.CPPCLS .. '::' .. fi.FUNC_DECL)

    local CALLBACK_MAKER = gen_maker(cls, fi, write)
    local REMOVE_CALLBACK = ""
    local OLUA_CALLBACK_TAG = "OLUA_CALLBACK_TAG_NEW"
    local NUM_ARGS = #ai.CALLBACK.ARGS
    local ARGS = {}
    local PUSH_ARGS = {}
    local INSTACKS = {}
    local CALLBACK_STORE_OBJ
    local CALLBACK_STORE
    local RESULT_DECL = ""
    local RESULT_RET = ""
    local RESULT_GET = ""

    for i, v in ipairs(ai.CALLBACK.ARGS) do
        local ARG_N = 'arg' .. i
        local PUSH_FUNC = v.TYPE.FUNC_PUSH_VALUE
    
        if v.TYPE.LUACLS then
            local LUACLS = v.TYPE.LUACLS
            if PUSH_FUNC == "olua_push_cppobj" then
                local TYPENAME = string.gsub(v.TYPE.TYPENAME, '[ *]*$', '')
                PUSH_ARGS[#PUSH_ARGS + 1] = format_snippet([[
                    ${PUSH_FUNC}<${TYPENAME}>(L, ${ARG_N}, "${LUACLS}");
                ]])
            else
                PUSH_ARGS[#PUSH_ARGS + 1] = format_snippet([[
                    ${PUSH_FUNC}(L, ${ARG_N}, "${LUACLS}");
                ]])
            end
        elseif v.TYPE.SUBTYPE then
            local SUBTYPE = assert(v.TYPE.SUBTYPE.LUACLS, v.TYPE.DECL_TYPE)
            PUSH_ARGS[#PUSH_ARGS + 1] = format_snippet([[
                ${PUSH_FUNC}(L, ${ARG_N}, "${SUBTYPE}");
            ]])
        else
            local CAST = ""
            if v.TYPE.DECL_TYPE ~= v.TYPE.TYPENAME then
                assert(not string.find(PUSH_FUNC, '^auto_luacv'))
                CAST = string.format("(%s)", v.TYPE.DECL_TYPE)
            end
            PUSH_ARGS[#PUSH_ARGS + 1] = format_snippet([[
                ${PUSH_FUNC}(L, ${CAST}${ARG_N});
            ]])
        end

        if v.ATTR.STACK then
            local PUSH_VALUE = PUSH_ARGS[#PUSH_ARGS]
            if #INSTACKS == 0 then
                INSTACKS[#INSTACKS + 1] = "//may be stack value"
            end
            if v.TYPE.SUBTYPE then
                assert(v.TYPE.TYPENAME == 'std::vector')
                INSTACKS[#INSTACKS + 1] = format_snippet([[
                    ${PUSH_VALUE}
                    olua_callgc(L, -1, true);
                ]])
            else
                INSTACKS[#INSTACKS + 1] = format_snippet([[
                    ${PUSH_VALUE}
                    olua_callgc(L, -1, false);
                ]])
            end
        end

        local DECL_TYPE = v.FUNC_ARG_DECL_TYPE
        local SPACE = string.find(DECL_TYPE, '[*&]$') and '' or ' '
        ARGS[#ARGS + 1] = format_snippet([[
            ${DECL_TYPE}${SPACE}${ARG_N}
        ]])
    end

    ARGS = table.concat(ARGS, ", ")
    PUSH_ARGS = table.concat(PUSH_ARGS, "\n")
    INSTACKS = table.concat(INSTACKS, "\n")

    if fi.CALLBACK_OPT.CALLBACK_CALLONCE then
        local CALLBACK_MODE = fi.CALLBACK_OPT.CALLBACK_MODE
        REMOVE_CALLBACK = format_snippet([[
            olua_removecallback(L, callback_store_obj, func.c_str(), OLUA_CALLBACK_TAG_EQUAL);
        ]])
    end

    if fi.CALLBACK_OPT.CALLBACK_REPLACE then
        OLUA_CALLBACK_TAG = "OLUA_CALLBACK_TAG_REPLACE"
    end

    if ai.CALLBACK.RET.TYPENAME ~= "void" then
        local DECL_TYPE = ai.CALLBACK.RET.DECL_TYPE
        local INIT_VALUE = ai.CALLBACK.RET.INIT_VALUE
        local FUNC_OPT_VALUE = ai.CALLBACK.RET.FUNC_OPT_VALUE
        RESULT_DECL = format_snippet([[
            ${DECL_TYPE} ret = ${INIT_VALUE};
        ]])
        if ai.CALLBACK.RET.LUACLS then
            local LUACLS = ai.CALLBACK.RET.LUACLS
            RESULT_GET = format_snippet([[
                ${FUNC_OPT_VALUE}(L, -1, (void **)&ret, "${LUACLS}", ${INIT_VALUE});
            ]])
        else
            RESULT_GET = format_snippet([[
                ${FUNC_OPT_VALUE}(L, -1, &ret, ${INIT_VALUE});
            ]])
        end
        RESULT_RET = "return ret;"
    end

    CALLBACK_STORE = get_callback_store(fi) + 1
    if CALLBACK_STORE == 1 then
        CALLBACK_STORE_OBJ = 'self'
        if fi.STATIC and fi.RET.TYPE.TYPENAME == 'void' then
            local LUACLS = cls.LUACLS
            CALLBACK_STORE_OBJ = format_snippet('olua_callbackstore(L, "${LUACLS}")')
        end
    else
        CALLBACK_STORE_OBJ = 'arg' .. (CALLBACK_STORE - 1)
    end

    local CALLBACK_CHUNK = format_snippet([[
        void *callback_store_obj = (void *)${CALLBACK_STORE_OBJ};
        std::string tag = ${CALLBACK_MAKER};
        std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), ${IDX}, ${OLUA_CALLBACK_TAG});
        ${ARG_N} = [callback_store_obj, func, tag](${ARGS}) {
            lua_State *L = olua_mainthread();
            int top = lua_gettop(L);
            ${RESULT_DECL}
            ${PUSH_ARGS}
            olua_callback(L, callback_store_obj, func.c_str(), ${NUM_ARGS});
            ${RESULT_GET}
            ${REMOVE_CALLBACK}
            
            ${INSTACKS}

            lua_settop(L, top);
            ${RESULT_RET}
        };
    ]])
    if ai.CALLBACK.DEFAULT or ai.ATTR.NULLABLE then
        local DEFAULT = ai.CALLBACK.DEFAULT or "nullptr"
        local FUNC_IS_VALUE = ai.TYPE.FUNC_IS_VALUE
        local CALLBACK_MODE = fi.CALLBACK_OPT.CALLBACK_MODE
        CALLBACK_CHUNK = format_snippet([[
            if (${FUNC_IS_VALUE}(L, ${IDX})) {
                ${CALLBACK_CHUNK}
            } else {
                void *callback_store_obj = (void *)${CALLBACK_STORE_OBJ};
                std::string tag = ${CALLBACK_MAKER};
                olua_removecallback(L, callback_store_obj, tag.c_str(), ${CALLBACK_MODE});
                ${ARG_N} = ${DEFAULT};
            }
        ]])
    end

    return CALLBACK_CHUNK
end