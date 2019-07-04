local function gen_snippet_func(cls, fi, write)
    local CPPCLS_PATH = class_path(cls)
    local CPPFUNC = fi.CPPFUNC
    local CPPFUNC_SNIPPET = fi.CPPFUNC_SNIPPET
    local INJECT_AFTER = fi.INJECT.AFTER or ""
    local INJECT_BEFORE = fi.INJECT.BEFORE or ""
    write(format_snippet(format_snippet([[
        static int _${CPPCLS_PATH}_${CPPFUNC}(lua_State *L)
        ${CPPFUNC_SNIPPET}
    ]])))
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
    elseif fi.ISVAR then
        TOTAL_ARGS = TOTAL_ARGS + 1
        idx = idx + 1
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
                ${DECL_TYPE}${SPACE}${ARG_N};       /** ${VARNAME} */
            ]])
        end

        if (ai.DEFAULT or ai.ATTR.NULLABLE) and not fi.CALLBACK_OPT then
            local FUNC_OPT_VALUE = ai.TYPE.FUNC_OPT_VALUE
            local DEFAULT = ai.DEFAULT or "nullptr"
            if ai.TYPE.LUACLS and ai.TYPE.DECL_TYPE ~= 'lua_Unsigned' then
                local LUACLS = ai.TYPE.LUACLS
                local FUNC_OPT_VALUE = ai.TYPE.FUNC_OPT_VALUE
                ARGS_CHUNK[#ARGS_CHUNK + 1] = format_snippet([[
                    ${FUNC_OPT_VALUE}(L, ${IDX}, (void **)&${ARG_N}, "${LUACLS}", nullptr);
                ]])
            else
                ARGS_CHUNK[#ARGS_CHUNK + 1] = format_snippet([[
                    ${FUNC_OPT_VALUE}(L, ${IDX}, &${ARG_N}, (${DECL_TYPE})${DEFAULT});
                ]])
            end
        elseif ai.TYPE.LUACLS and ai.TYPE.DECL_TYPE ~= 'lua_Unsigned' then
            local LUACLS = ai.TYPE.LUACLS
            ARGS_CHUNK[#ARGS_CHUNK + 1] = format_snippet([[
                ${FUNC_CHECK_VALUE}(L, ${IDX}, (void **)&${ARG_N}, "${LUACLS}");
            ]])
        elseif ai.TYPE.SUBTYPE then
            local SUBTYPE = ai.TYPE.SUBTYPE
            if SUBTYPE.LUACLS then
                local SUB_LUACLS = SUBTYPE.LUACLS
                ARGS_CHUNK[#ARGS_CHUNK + 1] = format_snippet([[
                    ${FUNC_CHECK_VALUE}(L, ${IDX}, ${ARG_N}, "${SUB_LUACLS}");
                ]])
            elseif ai.TYPE.TYPENAME == 'std::vector' then
                local CAST = ""
                local SUBTYPE_CHECK_FUNC = SUBTYPE.FUNC_CHECK_VALUE
                local SUBTYPE_DECL_TYPE = SUBTYPE.DECL_TYPE
                if SUBTYPE.DECL_TYPE ~= SUBTYPE.TYPENAME then
                    if not SUBTYPE.VALUE_TYPE then
                        print(SUBTYPE.DECL_TYPE, SUBTYPE.TYPENAME)
                        error(SUBTYPE.TYPENAME)
                    end
                    CAST = string.format("(%s)", SUBTYPE.TYPENAME)
                end
                ARGS_CHUNK[#ARGS_CHUNK + 1] = format_snippet([[
                    luaL_checktype(L, ${IDX}, LUA_TTABLE);
                    size_t ${ARG_N}_total = lua_rawlen(L, ${IDX});
                    ${ARG_N}.reserve(${ARG_N}_total);
                    for (int i = 1; i <= ${ARG_N}_total; i++) {
                        ${SUBTYPE_DECL_TYPE} obj;
                        lua_rawgeti(L, ${IDX}, i);
                        ${SUBTYPE_CHECK_FUNC}(L, -1, &obj);
                        ${ARG_N}.push_back(${CAST}obj);
                        lua_pop(L, 1);
                    }
                ]])
            elseif ai.TYPE.TYPENAME == 'std::set' then
                local CAST = ""
                local SUBTYPE_CHECK_FUNC = SUBTYPE.FUNC_CHECK_VALUE
                local SUBTYPE_DECL_TYPE = SUBTYPE.DECL_TYPE
                if SUBTYPE.DECL_TYPE ~= SUBTYPE.TYPENAME then
                    if not SUBTYPE.VALUE_TYPE then
                        print(SUBTYPE.DECL_TYPE, SUBTYPE.TYPENAME)
                        error(SUBTYPE.TYPENAME)
                    end
                    CAST = string.format("(%s)", SUBTYPE.DECL_TYPE)
                end
                ARGS_CHUNK[#ARGS_CHUNK + 1] = format_snippet([[
                    luaL_checktype(L, ${IDX}, LUA_TTABLE);
                    size_t ${ARG_N}_total = lua_rawlen(L, ${IDX});
                    for (int i = 1; i <= ${ARG_N}_total; i++) {
                        ${SUBTYPE_DECL_TYPE} obj;
                        lua_rawgeti(L, ${IDX}, i);
                        ${SUBTYPE_CHECK_FUNC}(L, -1, &obj);
                        ${ARG_N}.insert(${CAST}obj);
                        lua_pop(L, 1);
                    }
                ]])
            else
                error(ai.TYPE.TYPENAME)
            end
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
            local REF = assert(ai.ATTR.REF[1], fi.CPPFUNC .. ' no ref action')
            local REFNAME = assert(ai.ATTR.REF[2], fi.CPPFUNC .. ' no refname')
            local WHICH_OBJ = ai.ATTR.REF[3] or (fi.STATIC and -1 or 1)
            if REF == 'map' then
                REF_CHUNK[#REF_CHUNK + 1] = format_snippet([[
                    olua_mapref(L, ${WHICH_OBJ}, "${REFNAME}", ${IDX});
                ]])
            elseif REF == "single" then
                REF_CHUNK[#REF_CHUNK + 1] = format_snippet([[
                    olua_singleref(L, ${WHICH_OBJ}, "${REFNAME}", ${IDX});
                ]])
            else
                error('no support ref action: ' .. REF)
            end
        end
        if ai.ATTR.UNREF then
            assert(not fi.STATIC or (fi.RET.NUM > 0 and fi.RET.TYPE.LUACLS), fi.CPPFUNC)
            local REF = assert(ai.ATTR.UNREF[1], fi.CPPFUNC .. ' no ref action')
            local REFNAME = assert(ai.ATTR.UNREF[2], fi.CPPFUNC .. ' no refname')
            local WHICH_OBJ = ai.ATTR.UNREF[3] or (fi.STATIC and -1 or 1)
            if REF == 'map' then
                REF_CHUNK[#REF_CHUNK + 1] = format_snippet([[
                    olua_mapunref(L, ${WHICH_OBJ}, "${REFNAME}", ${IDX});
                ]])
            else
                error('no support ref action: ' .. REF)
            end
        end
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
        if fi.RET.TYPE.LUACLS and fi.RET.TYPE.DECL_TYPE ~= 'lua_Unsigned' then
            local LUACLS = fi.RET.TYPE.LUACLS
            if FUNC_PUSH_VALUE == "olua_push_cppobj" then
                local TYPENAME = string.gsub(fi.RET.TYPE.TYPENAME, '[ *]*$', '')
                if string.find(DECL_TYPE, '^const') then
                    RET_PUSH = format_snippet('int num_ret = ${FUNC_PUSH_VALUE}<${TYPENAME}>(L, (${TYPENAME} *)ret, "${LUACLS}");')
                else
                    RET_PUSH = format_snippet('int num_ret = ${FUNC_PUSH_VALUE}<${TYPENAME}>(L, ret, "${LUACLS}");')
                end
            else
                RET_PUSH = format_snippet('int num_ret = ${FUNC_PUSH_VALUE}(L, ret, "${LUACLS}");')
            end
        elseif fi.RET.TYPE.SUBTYPE then
            local SUBTYPE = fi.RET.TYPE.SUBTYPE
            if SUBTYPE.LUACLS then
                local SUB_LUACLS = SUBTYPE.LUACLS
                RET_PUSH = format_snippet('int num_ret = ${FUNC_PUSH_VALUE}(L, ret, "${SUB_LUACLS}");')
            else
                local CAST = ""
                local SUBTYPE_PUSH_FUNC = SUBTYPE.FUNC_PUSH_VALUE
                if SUBTYPE.DECL_TYPE ~= SUBTYPE.TYPENAME then
                    if not SUBTYPE.VALUE_TYPE then
                        print(SUBTYPE.DECL_TYPE, SUBTYPE.TYPENAME)
                        error(SUBTYPE.TYPENAME)
                    end
                    CAST = string.format("(%s)", SUBTYPE.DECL_TYPE)
                end
                if SUBTYPE.DECL_TYPE == 'lua_Unsigned'
                    or SUBTYPE.DECL_TYPE == 'lua_Number'
                    or SUBTYPE.TYPENAME == 'bool'
                    or SUBTYPE.DECL_TYPE == 'lua_Integer' then
                    RET_PUSH = format_snippet([[
                        int num_ret = 1;
                        int num_eles = 1;
                        lua_createtable(L, (int)ret.size(), 0);
                        for (auto it : ret) {
                            ${SUBTYPE_PUSH_FUNC}(L, ${CAST}it);
                            lua_rawseti(L, -2, num_eles++);
                        }
                    ]])
                else
                    RET_PUSH = format_snippet([[
                        int num_ret = 1;
                        int num_eles = 1;
                        lua_createtable(L, (int)ret.size(), 0);
                        for (const auto &it : ret) {
                            ${SUBTYPE_PUSH_FUNC}(L, ${CAST}it);
                            lua_rawseti(L, -2, num_eles++);
                        }
                    ]])
                end
            end
        else
            if fi.RET.ATTR.UNPACK then
                FUNC_PUSH_VALUE = fi.RET.TYPE.FUNC_UNPACK_VALUE
            end
            local CAST = ""
            if fi.RET.TYPE.DECL_TYPE ~= fi.RET.TYPE.TYPENAME then
                if not fi.RET.TYPE.VALUE_TYPE then
                    print(fi.RET.TYPE.DECL_TYPE, fi.RET.TYPE.TYPENAME)
                    error(fi.RET.TYPE.TYPENAME)
                end
                CAST = string.format("(%s)", fi.RET.TYPE.DECL_TYPE)
            elseif not fi.RET.TYPE.VALUE_TYPE then
                if not string.find(DECL_TYPE, '*$') then
                    CAST = '&'
                end
            end
            RET_PUSH = format_snippet('int num_ret = ${FUNC_PUSH_VALUE}(L, ${CAST}ret);')
        end

        if #RET_PUSH > 0 then
            RET_NUM = "num_ret"
        end
    end

    return RET_EXP, RET_PUSH, RET_NUM
end

local function gen_one_func(cls, fi, write, funcidx, func_filter)
    local CPPCLS_PATH = class_path(cls)
    local CPPFUNC = fi.CPPFUNC
    local CALLFUNC = CPPFUNC
    local FUNC_DECL = fi.FUNC_DECL
    local FUNC_INDEX = funcidx or ""
    local CALLER = "self->"
    local ARGS_BEGIN = "("
    local ARGS_END = ")"
    local INJECT_BEFORE = fi.INJECT.BEFORE and {fi.INJECT.BEFORE} or {}
    local INJECT_AFTER = fi.INJECT.AFTER and {fi.INJECT.AFTER} or {}

    local funcname = format_snippet([[
        _${CPPCLS_PATH}_${CPPFUNC}${FUNC_INDEX}
    ]])

    if func_filter[funcname] then
        return
    end
    func_filter[funcname] = true

    if fi.CPPFUNC_SNIPPET then
        gen_snippet_func(cls, fi, write)
        return
    end

    if fi.STATIC then
        CALLER = cls.CPPCLS .. '::'
    end

    local DECL_CHUNK, ARGS_CHUNK, CALLER_ARGS, TOTAL_ARGS, REF_CHUNK = gen_func_args(cls, fi)
    local RET_EXP, RET_PUSH, RET_NUM = gen_func_ret(cls, fi)
    local CALLBACK = ""

    if fi.CALLBACK_OPT then
        CALLBACK = gen_callback(cls, fi, write)
        if fi.STATIC and not fi.CALLBACK_OPT.TAG_STORE and fi.RET.TYPE.LUACLS then
            local DECL_TYPE = string.gsub(fi.RET.DECL_TYPE, ' *%*$', '')
            local LUACLS = fi.RET.TYPE.LUACLS
            local snippet = format_snippet([[
                ${DECL_TYPE} *self = new ${DECL_TYPE}();
                ${DECL_TYPE} *ret = self;
                self->autorelease();
                olua_push_cppobj<${DECL_TYPE}>(L, self, "${LUACLS}");
            ]])
            CALLBACK = snippet .. '\n\n' .. CALLBACK
            RET_EXP = ''
            CALLER = 'self->'
            CALLFUNC = assert(fi.CALLBACK_OPT.INIT_FUNC, 'no init func')
        end
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

    for _, v in ipairs(REF_CHUNK) do
        INJECT_AFTER[#INJECT_AFTER + 1] = v
    end

    if fi.RET.ATTR.REF then
        local REF = assert(fi.RET.ATTR.REF[1], fi.CPPFUNC .. ' no ref name')
        local REFNAME = assert(fi.RET.ATTR.REF[2], fi.CPPFUNC .. ' no ref name')
        local WHICH_OBJ = fi.RET.ATTR.REF[3] or (fi.STATIC and -1 or 1)
        local IDX = -1

        if fi.RET.TYPE.TYPENAME == 'void' then
            assert(not fi.STATIC, 'no ref object')
            IDX = 1
            WHICH_OBJ = assert(fi.RET.ATTR.REF[3], 'no store obj')
        elseif fi.RET.TYPE.IS_ARRAY then
            assert(REF == 'map')
            assert(fi.RET.TYPE.SUBTYPE.LUACLS, fi.CPPFUNC .. ' sub ref object must be a userdata')
        else
            assert(fi.RET.TYPE.LUACLS, fi.CPPFUNC .. ' ref object must be a userdata')
        end
        assert(not fi.STATIC, fi.CPPFUNC .. ' only support instance func')

        if REF == 'single' then
            INJECT_AFTER[#INJECT_AFTER + 1] = format_snippet([[
                olua_singleref(L, ${WHICH_OBJ}, "${REFNAME}", ${IDX});
            ]])
        elseif REF == 'map' then
            if fi.RET.TYPE.IS_ARRAY then
                INJECT_AFTER[#INJECT_AFTER + 1] = format_snippet([[
                    olua_maprefarray(L, ${WHICH_OBJ}, "${REFNAME}", ${IDX});
                ]])
            else
                INJECT_AFTER[#INJECT_AFTER + 1] = format_snippet([[
                    olua_mapref(L, ${WHICH_OBJ}, "${REFNAME}", ${IDX});
                ]])
            end
        elseif REF == 'cmpunref' then
            INJECT_BEFORE[#INJECT_BEFORE + 1] = format_snippet([[
                olua_startcmpunref(L, ${WHICH_OBJ}, "${REFNAME}");
            ]])
            INJECT_AFTER[#INJECT_AFTER + 1] = format_snippet([[
                olua_endcmpunref(L, ${WHICH_OBJ}, "${REFNAME}");
            ]])
        else
            error('no support ref action: ' .. REF)
        end
    end

    if fi.RET.ATTR.UNREF then
        local REF = assert(fi.RET.ATTR.UNREF[1], fi.CPPFUNC .. ' no ref name')
        local REFNAME = assert(fi.RET.ATTR.UNREF[2], fi.CPPFUNC .. ' no ref name')
        local WHICH_OBJ = fi.RET.ATTR.UNREF[3] or (fi.STATIC and -1 or 1)
        local IDX = -1

        if REF == 'map' then
            WHICH_OBJ = assert(fi.RET.ATTR.UNREF[3], 'no obj')
            IDX = 1
        else
            assert(REF == 'cmp' or REF == 'all', fi.CPPFUNC .. ' void type only support cmpunref')
            assert(not fi.STATIC, fi.CPPFUNC .. ' only support instance func')
        end

        if REF == 'cmp' then
            INJECT_BEFORE[#INJECT_BEFORE + 1] = format_snippet([[
                olua_startcmpunref(L, ${WHICH_OBJ}, "${REFNAME}");
            ]])
            INJECT_AFTER[#INJECT_AFTER + 1] = format_snippet([[
                olua_endcmpunref(L, ${WHICH_OBJ}, "${REFNAME}");
            ]])
        elseif REF == 'all' then
            INJECT_AFTER[#INJECT_AFTER + 1] = format_snippet([[
                olua_unrefall(L, ${WHICH_OBJ}, "${REFNAME}");
            ]])
        elseif REF == 'map' then
            INJECT_AFTER[#INJECT_AFTER + 1] = format_snippet([[
            olua_mapunref(L, ${WHICH_OBJ}, "${REFNAME}", ${IDX});
            ]])
        else
            error('no support ref action: ' .. REF)
        end
    end

    if #INJECT_BEFORE > 0 then
        table.insert(INJECT_BEFORE, 1, '// inject code before call')
    end

    if #INJECT_AFTER > 0 then
        table.insert(INJECT_AFTER, 1, '// inject code after call')
    end

    INJECT_AFTER = table.concat(INJECT_AFTER, '\n')
    INJECT_BEFORE = table.concat(INJECT_BEFORE, '\n')

    write(format_snippet([[
        static int _${CPPCLS_PATH}_${CPPFUNC}${FUNC_INDEX}(lua_State *L)
        {
            lua_settop(L, ${TOTAL_ARGS});

            ${DECL_CHUNK}

            ${ARGS_CHUNK}

            ${INJECT_BEFORE}

            ${CALLBACK}

            // ${FUNC_DECL}
            ${RET_EXP}${CALLER}${CALLFUNC}${ARGS_BEGIN}${CALLER_ARGS}${ARGS_END};
            ${RET_PUSH}

            ${INJECT_AFTER}

            return ${RET_NUM};
        }
    ]]))
    write('')
end

local function get_func_n(fis, n)
    local arr = {}
    for _, v in ipairs(fis) do
        if v.MAX_ARGS == n then
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
        local CPPCLS_PATH = class_path(cls)

        if #fi.ARGS > 0 then
            local TEST_ARGS = {}
            local MAX_VARS = 1
            for i, ai in ipairs(fi.ARGS) do
                local IDX = (fi.STATIC and 0 or 1) + i
                local FUNC_IS_VALUE = ai.TYPE.FUNC_IS_VALUE
                local NULLABLE_BEGIN = ""
                local NULLABLE_END = ""

                MAX_VARS = math.max(ai.TYPE.VARS or 1, MAX_VARS)

                if ai.ATTR.PACK then
                    FUNC_IS_VALUE = assert(ai.TYPE.FUNC_ISPACK_VALUE, ai.TYPE.TYPENAME)
                end

                if ai.DEFAULT or ai.ATTR.NULLABLE then
                    NULLABLE_BEGIN = '('
                    NULLABLE_END = ' ' .. format_snippet('|| olua_isnil(L, ${IDX}))')
                end

                if ai.TYPE.LUACLS and ai.TYPE.DECL_TYPE ~= 'lua_Unsigned' then
                    local LUACLS = ai.TYPE.LUACLS
                    TEST_ARGS[#TEST_ARGS + 1] = format_snippet([[
                        ${NULLABLE_BEGIN}${FUNC_IS_VALUE}(L, ${IDX}, "${LUACLS}")${NULLABLE_END}
                    ]])
                else
                    TEST_ARGS[#TEST_ARGS + 1] = format_snippet([[
                        ${NULLABLE_BEGIN}${FUNC_IS_VALUE}(L, ${IDX})${NULLABLE_END}
                    ]])
                end
            end

            TEST_ARGS = table.concat(TEST_ARGS, " && ")

            CALL_CHUNK[#CALL_CHUNK + 1] = {
                MAX_VARS = MAX_VARS,
                EXP1 = format_snippet([[
                    // if (${TEST_ARGS}) {
                        return _${CPPCLS_PATH}_${CPPFUNC}${FUNC_INDEX}(L);
                    // }
                ]]),
                EXP2 = format_snippet([[
                    if (${TEST_ARGS}) {
                        return _${CPPCLS_PATH}_${CPPFUNC}${FUNC_INDEX}(L);
                    }
                ]]),
            }
        else
            if #fns > 1 then
                for fn, fi in ipairs(fns) do
                    print("same func", fi, fi.CPPFUNC)
                end
            end
            assert(#fns == 1, fi.CPPFUNC)
            CALL_CHUNK[#CALL_CHUNK + 1] = {
                MAX_VARS = 1,
                EXP1 = format_snippet([[
                    return _${CPPCLS_PATH}_${CPPFUNC}${FUNC_INDEX}(L);
                ]])
            }
        end
    end

    table.sort(CALL_CHUNK, function (a, b)
        return a.MAX_VARS > b.MAX_VARS
    end)

    if #CALL_CHUNK > 1 then
        for i, v in ipairs(CALL_CHUNK) do
            if i == #CALL_CHUNK then
                CALL_CHUNK[i] = v.EXP1
            else
                CALL_CHUNK[i] = v.EXP2
            end
        end
    else
        CALL_CHUNK[1] = CALL_CHUNK[1].EXP1
    end

    return table.concat(CALL_CHUNK, "\n\n")
end

function gen_multi_func(cls, fis, write, func_filter)
    local NUM_ARGS = fis.MAX_ARGS
    local CPPCLS = cls.CPPCLS
    local CPPCLS_PATH = class_path(cls)
    local CPPFUNC = fis[1].CPPFUNC
    local HAS_OBJ = fis[1].STATIC and "" or " - 1"
    local IF_CHUNK = {}

    for _, fi in ipairs(fis) do
        gen_one_func(cls, fi, write, fi.INDEX, func_filter)
    end

    local funcname = format_snippet([[
        _${CPPCLS_PATH}_${CPPFUNC}
    ]])
    assert(not func_filter[funcname], cls.CPPCLS .. ' ' .. CPPFUNC)
    func_filter[funcname] = true

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
