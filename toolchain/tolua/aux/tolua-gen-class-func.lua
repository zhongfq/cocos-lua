local function gen_snippet_func(cls, fi, write)
    local CPPCLS_PATH = class_path(cls.CPPCLS)
    local CPPFUNC = fi.CPPFUNC
    local CPPFUNC_SNIPPET = fi.CPPFUNC_SNIPPET
    write(format_snippet([[
        static int _${CPPCLS_PATH}_${CPPFUNC}(lua_State *L)
        ${CPPFUNC_SNIPPET}
    ]]))
end

local function gen_one_func(cls, fi, write, funcidx)
    if fi.CPPFUNC_SNIPPET then
        gen_snippet_func(cls, fi, write)
        return
    end

    local CPPCLS_PATH = class_path(cls.CPPCLS)
    local CPPFUNC = fi.CPPFUNC
    local FUNC_INDEX = funcidx or ""
    local ARGS_CHUNK = {}
    local DECL_CHUNK = {}
    local LUA_SETTOP = "lua_settop(L, %d);"
    local RET_VALUE = ""
    local PUSH_RET = "";
    local CALLER = "self->"
    local CALLER_ARGS = {}
    local idx = 0
    local TOTAL_ARGS = #fi.ARGS

    if fi.STATIC then
        CALLER = cls.CPPCLS .. '::'
    else
        TOTAL_ARGS = TOTAL_ARGS + 1
        idx = idx + 1
        local ti = get_typeinfo(cls.CPPCLS .. "*")
        local DECL_TYPE = cls.CPPCLS
        local LUACLS = ti.LUACLS
        local FUNC_CHECK_VALUE = ti.FUNC_CHECK_VALUE
        local FUNC_TO_VALUE = ti.FUNC_TO_VALUE
        DECL_CHUNK[#DECL_CHUNK + 1] = format_snippet([[
            ${DECL_TYPE} *self = nullptr;
        ]])
        ARGS_CHUNK[#ARGS_CHUNK + 1] = format_snippet([[
            ${FUNC_TO_VALUE}(L, 1, (void **)&self, "${LUACLS}");
        ]])
    end

    for i, ai in ipairs(fi.ARGS) do
        idx = idx + 1
        if ai.TYPE.DECL_TYPE ~= ai.TYPE.TYPENAME then
            CALLER_ARGS[#CALLER_ARGS + 1] = '(' .. ai.TYPE.TYPENAME .. ')arg' .. i
        else
            CALLER_ARGS[#CALLER_ARGS + 1] = 'arg' .. i
        end

        local DECL_TYPE = ai.TYPE.DECL_TYPE
        local INIT_VALUE = ai.TYPE.INIT_VALUE
        local ARG_N = "arg" .. i
        local SPACE = " "
        local FUNC_CHECK_VALUE = ai.TYPE.FUNC_CHECK_VALUE
        local IDX = idx

        if string.find(DECL_TYPE, '[ *&]$') then
            SPACE = ""
        end

        if INIT_VALUE then
            DECL_CHUNK[#DECL_CHUNK + 1] = format_snippet([[
                ${DECL_TYPE}${SPACE}${ARG_N} = ${INIT_VALUE};
            ]])
        elseif ai.TYPE.SUBTYPE then
            DECL_TYPE = ai.DECL_TYPE
            DECL_CHUNK[#DECL_CHUNK + 1] = format_snippet([[
                ${DECL_TYPE}${SPACE}${ARG_N};
            ]])
        else
            DECL_CHUNK[#DECL_CHUNK + 1] = format_snippet([[
                ${DECL_TYPE}${SPACE}${ARG_N};
            ]])
        end

        if ai.VALUE then
            local FUNC_OPT_VALUE = ai.TYPE.FUNC_OPT_VALUE
            local VALUE = ai.VALUE
            ARGS_CHUNK[#ARGS_CHUNK + 1] = format_snippet([[
                ${FUNC_OPT_VALUE}(L, ${IDX}, &${ARG_N}, ${VALUE});
            ]])
        elseif ai.TYPE.LUACLS then
            local LUACLS = ai.TYPE.LUACLS
            ARGS_CHUNK[#ARGS_CHUNK + 1] = format_snippet([[
                ${FUNC_CHECK_VALUE}(L, ${IDX}, (void **)&${ARG_N}, "${LUACLS}");
            ]])
        elseif ai.TYPE.SUBTYPE then
            local SUBTYPE = assert(ai.TYPE.SUBTYPE.LUACLS, ai.TYPE.DECL_TYPE)
            ARGS_CHUNK[#ARGS_CHUNK + 1] = format_snippet([[
                ${FUNC_CHECK_VALUE}(L, ${IDX}, ${ARG_N}, "${SUBTYPE}");
            ]])
        else
            if ai.PACK then
                FUNC_CHECK_VALUE = ai.TYPE.FUNC_PACK_VALUE
                TOTAL_ARGS = ai.TYPE.VARS + TOTAL_ARGS - 1
                idx = idx + ai.TYPE.VARS - 1
            end
            ARGS_CHUNK[#ARGS_CHUNK + 1] = format_snippet([[
                ${FUNC_CHECK_VALUE}(L, ${IDX}, &${ARG_N});
            ]])
        end
    end

    LUA_SETTOP = string.format(LUA_SETTOP, TOTAL_ARGS)

    if fi.RET.NUM > 0 then
        local DECL_TYPE = fi.RET.DECL_TYPE
        local FUNC_PUSH_VALUE = fi.RET.TYPE.FUNC_PUSH_VALUE
        local SPACE = " "
        if string.find(DECL_TYPE, '[ *&]$') then
            SPACE = ""
        end
        RET_VALUE = format_snippet('${DECL_TYPE}${SPACE}ret = (${DECL_TYPE})')
        if fi.RET.TYPE.LUACLS then
            local LUACLS = fi.RET.TYPE.LUACLS
            PUSH_RET = format_snippet('${FUNC_PUSH_VALUE}(L, ret, "${LUACLS}")')
        elseif fi.RET.TYPE.SUBTYPE then
            local SUBTYPE = assert(fi.RET.TYPE.SUBTYPE.LUACLS, fi.RET.DECL_TYPE)
            PUSH_RET = format_snippet('${FUNC_PUSH_VALUE}(L, ret, "${SUBTYPE}")')
        else
            if fi.RET.UNPACK then
                FUNC_PUSH_VALUE = fi.RET.TYPE.FUNC_UNPACK_VALUE
            end
            local CAST = ""
            if fi.RET.TYPE.DECL_TYPE ~= fi.RET.TYPE.TYPENAME then
                CAST = string.format("(%s)", fi.RET.TYPE.DECL_TYPE)
            end
            PUSH_RET = format_snippet('${FUNC_PUSH_VALUE}(L, ${CAST}ret)')
        end
    else
        PUSH_RET = "0"
    end

    ARGS_CHUNK = table.concat(ARGS_CHUNK, "\n")
    DECL_CHUNK = table.concat(DECL_CHUNK, "\n")
    CALLER_ARGS = table.concat(CALLER_ARGS, ", ")

    write(format_snippet([[
        static int _${CPPCLS_PATH}_${CPPFUNC}${FUNC_INDEX}(lua_State *L)
        {
            ${LUA_SETTOP}

            ${DECL_CHUNK}

            ${ARGS_CHUNK}

            ${RET_VALUE}${CALLER}${CPPFUNC}(${CALLER_ARGS});
            
            return ${PUSH_RET};
        }
    ]]))
end

local function get_func_n(fis, n)
    local arr = {}
    for _, v in ipairs(fis) do
        if #v.ARGS == n then
            arr[#arr + 1] = v
        end
    end
    return arr
end

local function gen_test_and_call(cls, fns)
    local CALL_CHUNK = {}

    for fn, fi in ipairs(fns) do
        local FUNC_INDEX = fi.INDEX
        local CPPFUNC = fi.CPPFUNC
        local CPPCLS_PATH = class_path(cls.CPPCLS)

        if #fi.ARGS > 0 then
            local TEST_ARGS = {}
            for i, ai in ipairs(fi.ARGS) do
                local IDX = (fi.STATIC and 0 or 1) + i
                local FUNC_IS_VALUE = ai.TYPE.FUNC_IS_VALUE
                if ai.TYPE.LUACLS then
                    local LUACLS = ai.TYPE.LUACLS
                    TEST_ARGS[#TEST_ARGS + 1] = format_snippet([[
                        ${FUNC_IS_VALUE}(L, ${IDX}, "${LUACLS}")
                    ]])
                else
                    TEST_ARGS[#TEST_ARGS + 1] = format_snippet([[
                        ${FUNC_IS_VALUE}(L, ${IDX})
                    ]])
                end
            end

            TEST_ARGS = table.concat(TEST_ARGS, " && ")

            if fn == #fns then
                CALL_CHUNK[#CALL_CHUNK + 1] = format_snippet([[
                    // if (${TEST_ARGS}) {
                        return _${CPPCLS_PATH}_${CPPFUNC}${FUNC_INDEX}(L);
                    // }
                ]])
            else
                CALL_CHUNK[#CALL_CHUNK + 1] = format_snippet([[
                    if (${TEST_ARGS}) {
                        return _${CPPCLS_PATH}_${CPPFUNC}${FUNC_INDEX}(L);
                    }
                ]])
            end
        else
            assert(#fns == 1)
            CALL_CHUNK[#CALL_CHUNK + 1] = format_snippet([[
                return _${CPPCLS_PATH}_${CPPFUNC}${FUNC_INDEX}(L);
            ]])
        end
    end

    return table.concat(CALL_CHUNK, "\n\n")
end

function gen_multi_func(cls, fis, write)
    local NUM_ARGS = fis.MAX_ARGS
    local CPPCLS = cls.CPPCLS
    local CPPCLS_PATH = class_path(cls.CPPCLS)
    local CPPFUNC = fis[1].CPPFUNC
    local HAS_OBJ = fis[1].STATIC and "" or " - 1"
    local IF_CHUNK = {}

    for _, fi in ipairs(fis) do
        gen_one_func(cls, fi, write, fi.INDEX)
        write('')
    end

    for i = 0, NUM_ARGS do
        local fns = get_func_n(fis, i)
        if #fns > 0 then
            local CUR_ARGS = i
            local TEST_AND_CALL = gen_test_and_call(cls, fns)
            IF_CHUNK[#IF_CHUNK + 1] = format_snippet([[
                if (num_args == ${CUR_ARGS}) {
                    ${TEST_AND_CALL}
                }
            ]])
        end
    end

    IF_CHUNK = table.concat(IF_CHUNK, "\n\n")
    write(format_snippet([[
        static int _${CPPCLS_PATH}_${CPPFUNC}(lua_State *L)
        {
            int num_args = lua_gettop(L)${HAS_OBJ};

            ${IF_CHUNK}

            luaL_error(L, "method '${CPPCLS}::${CPPFUNC}' not support '%d' arguments", num_args);

            return 0;
        }
    ]]))
end

function gen_class_func(cls, fis, write)
    if #fis == 1 then
        gen_one_func(cls, fis[1], write)
    else
        gen_multi_func(cls, fis, write)
    end
end