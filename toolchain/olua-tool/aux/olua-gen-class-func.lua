local function gen_snippet_func(cls, fi, write)
    local CPPCLS_PATH = class_path(cls.RAWCPPCLS or cls.CPPCLS)
    local CPPFUNC = fi.CPPFUNC
    local CPPFUNC_SNIPPET = fi.CPPFUNC_SNIPPET
    write(format_snippet([[
        static int _${CPPCLS_PATH}_${CPPFUNC}(lua_State *L)
        ${CPPFUNC_SNIPPET}
    ]]))
    write('')
end

local function gen_func_args(cls, fi)
    local idx = 0
    local DECL_CHUNK = {}
    local CALLER_ARGS = {}
    local ARGS_CHUNK = {}
    local REF_CHUNK = {}
    local TOTAL_ARGS = #fi.ARGS

    if not fi.STATIC then
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
        local DECL_TYPE = ai.TYPE.DECL_TYPE
        local INIT_VALUE = ai.TYPE.INIT_VALUE
        local VARNAME = ai.VARNAME or ""
        local ARG_N = "arg" .. i
        local SPACE = " "
        local FUNC_CHECK_VALUE = ai.TYPE.FUNC_CHECK_VALUE
        local IDX = idx + 1
        idx = IDX

        if ai.TYPE.TYPENAME == 'std::function' then
            assert(fi.CALLBACK_OPT, fi.FUNC_DECL)
        end

        if ai.TYPE.DECL_TYPE ~= ai.TYPE.TYPENAME and not ai.CALLBACK.ARGS then
            local TYPENAME = ai.TYPE.TYPENAME
            CALLER_ARGS[#CALLER_ARGS + 1] = format_snippet([[
                (${TYPENAME})${ARG_N}
            ]])
        else
            CALLER_ARGS[#CALLER_ARGS + 1] = format_snippet([[
                ${ARG_N}
            ]])
        end

        if string.find(DECL_TYPE, '[ *&]$') then
            SPACE = ""
        end

        if INIT_VALUE then
            DECL_CHUNK[#DECL_CHUNK + 1] = format_snippet([[
                ${DECL_TYPE}${SPACE}${ARG_N} = ${INIT_VALUE};   /** ${VARNAME} */
            ]])
        elseif ai.TYPE.SUBTYPE then
            DECL_TYPE = ai.DECL_TYPE
            DECL_CHUNK[#DECL_CHUNK + 1] = format_snippet([[
                ${DECL_TYPE}${SPACE}${ARG_N};       /** ${VARNAME} */
            ]])
        else
            DECL_CHUNK[#DECL_CHUNK + 1] = format_snippet([[
                ${DECL_TYPE}${SPACE}${ARG_N};       /** $VARNAME */
            ]])
        end

        if ai.DEFAULT then
            local FUNC_OPT_VALUE = ai.TYPE.FUNC_OPT_VALUE
            local DEFAULT = ai.DEFAULT
            if ai.TYPE.LUACLS then
                local LUACLS = ai.TYPE.LUACLS
                local FUNC_IS_VALUE = ai.TYPE.FUNC_IS_VALUE
                ARGS_CHUNK[#ARGS_CHUNK + 1] = format_snippet([[
                    if (${FUNC_IS_VALUE}(L, ${IDX}, "${LUACLS}")) {
                        ${FUNC_CHECK_VALUE}(L, ${IDX}, (void **)&${ARG_N}, "${LUACLS}");
                    }
                ]])
            else
                ARGS_CHUNK[#ARGS_CHUNK + 1] = format_snippet([[
                    ${FUNC_OPT_VALUE}(L, ${IDX}, &${ARG_N}, ${DEFAULT});
                ]])
            end
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
        elseif not ai.CALLBACK.ARGS then
            if ai.ATTR.PACK then
                FUNC_CHECK_VALUE = ai.TYPE.FUNC_PACK_VALUE
                TOTAL_ARGS = ai.TYPE.VARS + TOTAL_ARGS - 1
                idx = idx + ai.TYPE.VARS - 1
            end
            ARGS_CHUNK[#ARGS_CHUNK + 1] = format_snippet([[
                ${FUNC_CHECK_VALUE}(L, ${IDX}, &${ARG_N});
            ]])
        end

        if ai.ATTR.REF then
            assert(not fi.STATIC or (fi.RET.NUM > 0 and fi.RET.TYPE.LUACLS), fi.CPPFUNC)
            local WHICH_OBJ = fi.STATIC and -1 or 1
            if ai.ATTR.REF == true then
                REF_CHUNK[#REF_CHUNK + 1] = format_snippet([[
                    olua_mapref(L, ${WHICH_OBJ}, ".autoref", ${IDX});
                ]])
            elseif ai.ATTR.REF[1] == "single" then
                local REF_NAME = assert(ai.ATTR.REF[2], 'no ref name')
                REF_CHUNK[#REF_CHUNK + 1] = format_snippet([[
                    olua_singleref(L, ${WHICH_OBJ}, "${REF_NAME", ${IDX});
                ]])
            else
                error(ai.ATTR.REF[1])
            end
        end
    end

    if #REF_CHUNK > 0 then
        table.insert(REF_CHUNK, 1, "// ref value")
    end

    ARGS_CHUNK = table.concat(ARGS_CHUNK, "\n")
    DECL_CHUNK = table.concat(DECL_CHUNK, "\n")
    CALLER_ARGS = table.concat(CALLER_ARGS, ", ")

    return DECL_CHUNK, ARGS_CHUNK, CALLER_ARGS, TOTAL_ARGS, REF_CHUNK
end

local function gen_func_ret(cls, fi)
    local RET_EXP = ""
    local RET_NUM = "0"
    local RET_PUSH = ""

    if fi.RET.NUM > 0 then
        local DECL_TYPE = fi.RET.DECL_TYPE
        local FUNC_PUSH_VALUE = fi.RET.TYPE.FUNC_PUSH_VALUE
        local SPACE = " "
        if string.find(DECL_TYPE, '[ *&]$') then
            SPACE = ""
        end
        RET_EXP = format_snippet('${DECL_TYPE}${SPACE}ret = (${DECL_TYPE})')
        if fi.RET.TYPE.LUACLS then
            local LUACLS = fi.RET.TYPE.LUACLS
            if FUNC_PUSH_VALUE == "olua_push_cppobj" then
                local TYPENAME = string.gsub(fi.RET.TYPE.TYPENAME, '[ *]*$', '')
                RET_PUSH = format_snippet('int num_ret = ${FUNC_PUSH_VALUE}<${TYPENAME}>(L, ret, "${LUACLS}");')
            else
                RET_PUSH = format_snippet('int num_ret = ${FUNC_PUSH_VALUE}(L, ret, "${LUACLS}");')
            end
        elseif fi.RET.TYPE.SUBTYPE then
            local SUBTYPE = assert(fi.RET.TYPE.SUBTYPE.LUACLS, fi.RET.DECL_TYPE)
            RET_PUSH = format_snippet('int num_ret = ${FUNC_PUSH_VALUE}(L, ret, "${SUBTYPE}");')
        else
            if fi.RET.ATTR.UNPACK then
                FUNC_PUSH_VALUE = fi.RET.TYPE.FUNC_UNPACK_VALUE
            end
            local CAST = ""
            if fi.RET.TYPE.DECL_TYPE ~= fi.RET.TYPE.TYPENAME then
                assert(not string.find(FUNC_PUSH_VALUE, '^auto_luacv'))
                CAST = string.format("(%s)", fi.RET.TYPE.DECL_TYPE)
            elseif not fi.RET.TYPE.VALUE_TYPE then
                if not string.find(DECL_TYPE, '*$') then
                    CAST = '&'
                end
            end
            RET_PUSH = format_snippet('int num_ret = ${FUNC_PUSH_VALUE}(L, ${CAST}ret)')
        end

        if #RET_PUSH > 0 then
            RET_NUM = "num_ret"
        end
    end

    return RET_EXP, RET_PUSH, RET_NUM
end

local function gen_one_func(cls, fi, write, funcidx, func_filter)
    if fi.CPPFUNC_SNIPPET then
        gen_snippet_func(cls, fi, write)
        return
    end

    local CPPCLS_PATH = class_path(cls.RAWCPPCLS or cls.CPPCLS)
    local CPPFUNC = fi.CPPFUNC
    local CALLFUNC = CPPFUNC
    local FUNC_DECL = fi.FUNC_DECL
    local FUNC_INDEX = funcidx or ""
    local CALLER = "self->"
    local ARGS_BEGIN = "("
    local ARGS_END = ")"

    local funcname = format_snippet([[
        _${CPPCLS_PATH}_${CPPFUNC}${FUNC_INDEX}
    ]])
    if func_filter[funcname] then
        return
    end
    func_filter[funcname] = true

    if fi.STATIC then
        CALLER = cls.CPPCLS .. '::'
    end

    local DECL_CHUNK, ARGS_CHUNK, CALLER_ARGS, TOTAL_ARGS, REF_CHUNK = gen_func_args(cls, fi)
    local RET_EXP, RET_PUSH, RET_NUM = gen_func_ret(cls, fi)
    local CALLBACK = ""

    if fi.CALLBACK_OPT then
        CALLBACK = gen_callback(cls, fi, write)
    end

    if fi.ISVAR then
        ARGS_END = ""
        CALLFUNC = fi.VARNAME
        if fi.RET.NUM > 0 then
            ARGS_BEGIN = ""
        else
            ARGS_BEGIN = " = "
        end
    end

    if fi.RET.ATTR.REF then
        assert(not fi.STATIC or (fi.RET.NUM > 0 and fi.RET.TYPE.LUACLS), fi.CPPFUNC)
        if fi.RET.ATTR.REF == true then
            REF_CHUNK[#REF_CHUNK + 1] = format_snippet([[
                olua_mapref(L, 1, ".autoref", -1);
            ]])
        elseif fi.RET.ATTR.REF[1] == "single" then
            local REF_NAME = assert(fi.RET.ATTR.REF[2], 'no ref name')
            REF_CHUNK[#REF_CHUNK + 1] = format_snippet([[
                olua_singleref(L, 1, "${REF_NAME", -1);
            ]])
        else
            error(fi.RET.ATTR.REF[1])
        end
    end

    REF_CHUNK = table.concat(REF_CHUNK, "\n")

    if #REF_CHUNK > 0 then
        REF_CHUNK = '\n' .. REF_CHUNK .. '\n'
    elseif #RET_PUSH > 0 then
        RET_NUM = string.gsub(RET_PUSH, 'int num_ret = ', '')
        RET_NUM = string.gsub(RET_NUM, ';$', '')
        RET_PUSH = ""
    end

    write(format_snippet([[
        static int _${CPPCLS_PATH}_${CPPFUNC}${FUNC_INDEX}(lua_State *L)
        {
            lua_settop(L, ${TOTAL_ARGS});

            ${DECL_CHUNK}

            ${ARGS_CHUNK}

            ${CALLBACK}

            // ${FUNC_DECL}
            ${RET_EXP}${CALLER}${CALLFUNC}${ARGS_BEGIN}${CALLER_ARGS}${ARGS_END};
            ${RET_PUSH}
            ${REF_CHUNK}
            return ${RET_NUM};
        }
    ]]))
    write('')
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
        local CPPCLS_PATH = class_path(cls.RAWCPPCLS or cls.CPPCLS)

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
            if #fns > 1 then
                for fn, fi in ipairs(fns) do
                    print("same func", fi, fi.CPPFUNC)
                end
            end
            assert(#fns == 1, fi.CPPFUNC)
            CALL_CHUNK[#CALL_CHUNK + 1] = format_snippet([[
                return _${CPPCLS_PATH}_${CPPFUNC}${FUNC_INDEX}(L);
            ]])
        end
    end

    return table.concat(CALL_CHUNK, "\n\n")
end

function gen_multi_func(cls, fis, write, func_filter)
    local NUM_ARGS = fis.MAX_ARGS
    local CPPCLS = cls.CPPCLS
    local CPPCLS_PATH = class_path(cls.RAWCPPCLS or cls.CPPCLS)
    local CPPFUNC = fis[1].CPPFUNC
    local HAS_OBJ = fis[1].STATIC and "" or " - 1"
    local IF_CHUNK = {}

    for _, fi in ipairs(fis) do
        gen_one_func(cls, fi, write, fi.INDEX, func_filter)
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
    write('')
end

function gen_class_func(cls, fis, write, func_filter)
    if #fis == 1 then
        gen_one_func(cls, fis[1], write, nil, func_filter)
    else
        gen_multi_func(cls, fis, write, func_filter)
    end
end
