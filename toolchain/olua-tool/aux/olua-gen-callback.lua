local function get_tag_store(fi, idx)
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
        local idx = get_tag_store(fi, tonumber(n))
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
    local TAG_STORE_OBJ
    local TAG_STORE = get_tag_store(fi)

    if TAG_STORE == 0 then
        TAG_STORE_OBJ = 'self'
    else
        TAG_STORE_OBJ = 'arg' .. TAG_STORE
    end

    local block = format_snippet([[
        std::string tag = ${TAG_MAKER};
        void *tag_store_obj = (void *)${TAG_STORE_OBJ};
        olua_removecallback(L, tag_store_obj, tag.c_str(), ${TAG_MODE});
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
        if v.CALLBACK_ARGS then
            ARG_N = 'arg' .. i
            ai = v
            break
        end
    end

    if not ai then
        return gen_remove_callback(cls, fi, write)
    end

    local TAG_MAKER = gen_maker(cls, fi, write)
    local REMOVE_CALLBACK = ""
    local OLUA_CALLBACK_TAG = "OLUA_CALLBACK_TAG_NEW"
    local NUM_ARGS = #ai.CALLBACK_ARGS
    local ARGS = {}
    local PUSH_ARGS = {}
    local TAG_STORE_OBJ
    local TAG_STORE
    local RESULT_DECL = ""
    local RESULT_RET = ""
    local RESULT_GET = ""

    for i, v in ipairs(ai.CALLBACK_ARGS) do
        local ARG_N = 'arg' .. i
        local PUSH_FUNC = v.TYPE.FUNC_PUSH_VALUE
    
        if v.IGNORE then
            NUM_ARGS = NUM_ARGS - 1
        else
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
        end

        local DECL_TYPE = v.FUNC_ARG_DECL_TYPE
        local SPACE = string.find(DECL_TYPE, '[*&]$') and '' or ' '
        ARGS[#ARGS + 1] = format_snippet([[
            ${DECL_TYPE}${SPACE}${ARG_N}
        ]])
    end

    ARGS = table.concat(ARGS, ", ")
    PUSH_ARGS = table.concat(PUSH_ARGS, "\n")

    if fi.CALLBACK_OPT.REMOVED then
        local TAG_MODE = fi.CALLBACK_OPT.TAG_MODE
        REMOVE_CALLBACK = format_snippet([[
            olua_removecallback(L, tag_store_obj, func.c_str(), ${TAG_MODE});
        ]])
    end

    if fi.CALLBACK_OPT.ONLYONE then
        OLUA_CALLBACK_TAG = "OLUA_CALLBACK_TAG_REPLACE"
    end

    if ai.CALLBACK_RET.TYPENAME ~= "void" then
        local DECL_TYPE = ai.CALLBACK_RET.DECL_TYPE
        local INIT_VALUE = ai.CALLBACK_RET.INIT_VALUE
        local FUNC_OPT_VALUE = ai.CALLBACK_RET.FUNC_OPT_VALUE
        RESULT_DECL = format_snippet([[
            ${DECL_TYPE} ret = ${INIT_VALUE};
        ]])
        RESULT_GET = format_snippet([[
            ${FUNC_OPT_VALUE}(L, -1, &ret, ${INIT_VALUE});
        ]])
        RESULT_RET = "return ret;"
    end

    TAG_STORE = get_tag_store(fi) + 1
    if TAG_STORE == 1 then
        TAG_STORE_OBJ = 'self'
    else
        TAG_STORE_OBJ = 'arg' .. (TAG_STORE - 1)
    end

    local CALLBACK_CHUNK = format_snippet([[
        void *tag_store_obj = (void *)${TAG_STORE_OBJ};
        std::string tag = ${TAG_MAKER};
        std::string func = olua_setcallback(L, tag_store_obj, tag.c_str(), ${IDX}, ${OLUA_CALLBACK_TAG});
        ${ARG_N} = [tag_store_obj, func, tag](${ARGS}) {
            lua_State *L = xlua_cocosthread();
            int top = lua_gettop(L);
            ${RESULT_DECL}
            ${PUSH_ARGS}
            olua_callback(L, tag_store_obj, func.c_str(), ${NUM_ARGS});
            ${RESULT_GET}
            ${REMOVE_CALLBACK}
            lua_settop(L, top);
            ${RESULT_RET}
        };
    ]])
    if ai.CALLBACK_DEFAULT then
        local CALLBACK_DEFAULT = ai.CALLBACK_DEFAULT
        local FUNC_IS_VALUE = ai.TYPE.FUNC_IS_VALUE
        CALLBACK_CHUNK = format_snippet([[
            if (${FUNC_IS_VALUE}(L, ${IDX})) {
                ${CALLBACK_CHUNK}
            } else {
                ${ARG_N} = ${CALLBACK_DEFAULT};
            }
        ]])
    else
    end

    return CALLBACK_CHUNK
end