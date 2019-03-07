local function gen_maker(cls, fi, write)
    if not fi.CALLBACK_OPT.MAKER then
        error(string.format("no tag maker: %s.%s", cls.CPPCLS, fi.LUAFUNC))
    end

    local maker = string.gsub(fi.CALLBACK_OPT.MAKER, '#(%-?%d+)', function (n)
        n = tonumber(n)
        assert(n, fi.CALLBACK_OPT.MAKER)
        if n < 0 then
            n = n + #fi.ARGS + 1
            assert(n > 0, fi.CALLBACK_OPT.MAKER)
        end
        return "arg" .. n
    end)
    return string.gsub(maker, '%(%)', '("")')
end

local function gen_remove_callback(cls, fi, write)
    local REMOVED_MODE = fi.CALLBACK_OPT.REMOVED_MODE
    local MAKER = gen_maker(cls, fi, write)
    local block = format_snippet([[
        std::string tag = ${MAKER};
        tolua_removecallback(L, 1, tag.c_str(), ${REMOVED_MODE});
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

    local MAKER = gen_maker(cls, fi, write)
    local REMOVE_CALLBACK = ""
    local STANDALONE = ""
    local NUM_ARGS = #ai.CALLBACK_ARGS
    local ARGS = {}
    local PUSH_ARGS = {}

    for i, v in ipairs(ai.CALLBACK_ARGS) do
        local ARG_N = 'arg' .. i
        local PUSH_FUNC = v.TYPE.FUNC_PUSH_VALUE
    
        if v.TYPE.LUACLS then
            local LUACLS = v.TYPE.LUACLS
            PUSH_ARGS[#PUSH_ARGS + 1] = format_snippet([[
                ${PUSH_FUNC}(L, ${ARG_N}, "${LUACLS}");
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

        local DECL_TYPE = v.DECL_TYPE
        local SPACE = string.find(DECL_TYPE, '[*&]$') and '' or ' '
        ARGS[#ARGS + 1] = format_snippet([[
            ${DECL_TYPE}${SPACE}${ARG_N}
        ]])
    end

    ARGS = table.concat(ARGS, ", ")
    PUSH_ARGS = table.concat(PUSH_ARGS, "\n")

    if fi.CALLBACK_OPT.REMOVED then
        local REMOVED_MODE = fi.CALLBACK_OPT.REMOVED_MODE
        REMOVE_CALLBACK = format_snippet([[
            if (tolua_getobj(L, self)) {
                tolua_removecallback(L, -1, func.c_str(), ${REMOVED_MODE});
            }
        ]])
    end

    if fi.CALLBACK_OPT.STANDALONE then
        STANDALONE = 'tolua_removecallback(L, 1, tag.c_str(), TOLUA_CALLBACK_TAG_ENDWITH);'
    end

    local block = format_snippet([[
        std::string tag = ${MAKER};
        ${STANDALONE}
        std::string func = tolua_setcallback(L, 1, tag.c_str(), ${IDX});
        ${ARG_N} = [self, func, tag](${ARGS}) {
            lua_State *L = xlua_cocosthread();
            int top = lua_gettop(L);
            ${PUSH_ARGS}
            tolua_callback(L, self, func.c_str(), ${NUM_ARGS});
            ${REMOVE_CALLBACK}
            lua_settop(L, top);
        };
    ]])

    return block
end