local olua = require "olua.olua-io"

local format = olua.format

local function gen_snippet_func(cls, fi, write)
    local CPPCLS_PATH = olua.topath(cls.CPPCLS)
    local CPPFUNC = fi.CPPFUNC
    local CPPFUNC_SNIPPET = fi.CPPFUNC_SNIPPET
    olua.nowarning(CPPCLS_PATH, CPPFUNC, CPPFUNC_SNIPPET)
    write(format([[
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
        local ti = olua.typeinfo(cls.CPPCLS .. "*")
        olua.nowarning(ti)
        DECL_CHUNK[#DECL_CHUNK + 1] = format([[
            ${cls.CPPCLS} *self = nullptr;
        ]])
        ARGS_CHUNK[#ARGS_CHUNK + 1] = format([[
            ${ti.FUNC_TO_VALUE}(L, 1, (void **)&self, "${ti.LUACLS}");
        ]])
    elseif fi.ISVAR then
        TOTAL_ARGS = TOTAL_ARGS + 1
        idx = idx + 1
    end

    for i, ai in ipairs(fi.ARGS) do
        local DECLTYPE = ai.TYPE.DECLTYPE
        local INIT_VALUE = ai.TYPE.INIT_VALUE
        local ARG_NAME = "arg" .. i
        local SPACE = " "
        local FUNC_CHECK_VALUE = ai.TYPE.FUNC_CHECK_VALUE
        local ARGN = idx + 1
        idx = ARGN

        if ai.TYPE.CPPCLS == 'std::function' then
            assert(fi.CALLBACK_OPT, fi.DECLFUNC)
        end

        if ai.TYPE.DECLTYPE ~= ai.TYPE.CPPCLS and not ai.CALLBACK.ARGS then
            CALLER_ARGS[#CALLER_ARGS + 1] = format([[(${ai.TYPE.CPPCLS})${ARG_NAME}]])
        else
            CALLER_ARGS[#CALLER_ARGS + 1] = format([[${ARG_NAME}]])
        end

        if string.find(DECLTYPE, '[ *&]$') then
            SPACE = ""
        end

        if INIT_VALUE then
            DECL_CHUNK[#DECL_CHUNK + 1] = format([[
                ${DECLTYPE}${SPACE}${ARG_NAME} = ${INIT_VALUE};   /** ${ai.VARNAME} */
            ]])
        elseif ai.TYPE.SUBTYPE then
            DECLTYPE = ai.DECLTYPE
            DECL_CHUNK[#DECL_CHUNK + 1] = format([[
                ${DECLTYPE}${SPACE}${ARG_NAME};       /** ${ai.VARNAME} */
            ]])
        else
            DECL_CHUNK[#DECL_CHUNK + 1] = format([[
                ${DECLTYPE}${SPACE}${ARG_NAME};       /** ${ai.VARNAME} */
            ]])
        end

        if (ai.DEFAULT or ai.ATTR.NULLABLE) and not fi.CALLBACK_OPT then
            local FUNC_OPT_VALUE = ai.TYPE.FUNC_OPT_VALUE
            local DEFAULT = ai.DEFAULT or "nullptr"
            if ai.TYPE.LUACLS and ai.TYPE.DECLTYPE ~= 'lua_Unsigned' then
                local FUNC_OPT_VALUE = ai.TYPE.FUNC_OPT_VALUE
                ARGS_CHUNK[#ARGS_CHUNK + 1] = format([[
                    ${FUNC_OPT_VALUE}(L, ${ARGN}, (void **)&${ARG_NAME}, "${ai.TYPE.LUACLS}", nullptr);
                ]])
            else
                ARGS_CHUNK[#ARGS_CHUNK + 1] = format([[
                    ${FUNC_OPT_VALUE}(L, ${ARGN}, &${ARG_NAME}, (${DECLTYPE})${DEFAULT});
                ]])
            end
        elseif ai.TYPE.LUACLS and ai.TYPE.DECLTYPE ~= 'lua_Unsigned' then
            ARGS_CHUNK[#ARGS_CHUNK + 1] = format([[
                ${FUNC_CHECK_VALUE}(L, ${ARGN}, (void **)&${ARG_NAME}, "${ai.TYPE.LUACLS}");
            ]])
        elseif ai.TYPE.SUBTYPE then
            assert(ai.TYPE.IS_ARRAY)
            local SUBTYPE = ai.TYPE.SUBTYPE
            if SUBTYPE.LUACLS then
                local SUB_LUACLS = SUBTYPE.LUACLS
                ARGS_CHUNK[#ARGS_CHUNK + 1] = format([[
                    ${FUNC_CHECK_VALUE}(L, ${ARGN}, ${ARG_NAME}, "${SUB_LUACLS}");
                ]])
            else
                local CAST = ""
                local SUBTYPE_CHECK_FUNC = SUBTYPE.FUNC_CHECK_VALUE
                local SUBTYPE_DECLTYPE = SUBTYPE.DECLTYPE
                local RESERVE_CHUNK = ''
                local FN_PUSH_BACK = ai.TYPE.FN_PUSH_BACK
                if SUBTYPE.DECLTYPE ~= SUBTYPE.CPPCLS then
                    CAST = string.format("(%s)", SUBTYPE.CPPCLS)
                end
                if ai.TYPE.FN_RESERVE then
                    local FN_RESERVE = ai.TYPE.FN_RESERVE
                    RESERVE_CHUNK = format [[
                        ${ARG_NAME}.${FN_RESERVE}(${ARG_NAME}_total);
                    ]]
                end
                ARGS_CHUNK[#ARGS_CHUNK + 1] = format([[
                    luaL_checktype(L, ${ARGN}, LUA_TTABLE);
                    size_t ${ARG_NAME}_total = lua_rawlen(L, ${ARGN});
                    ${RESERVE_CHUNK}
                    for (int i = 1; i <= ${ARG_NAME}_total; i++) {
                        ${SUBTYPE_DECLTYPE} obj;
                        lua_rawgeti(L, ${ARGN}, i);
                        ${SUBTYPE_CHECK_FUNC}(L, -1, &obj);
                        ${ARG_NAME}.${FN_PUSH_BACK}(${CAST}obj);
                        lua_pop(L, 1);
                    }
                ]])
            end
        elseif not ai.CALLBACK.ARGS then
            if ai.ATTR.PACK then
                FUNC_CHECK_VALUE = ai.TYPE.FUNC_PACK_VALUE
                TOTAL_ARGS = ai.TYPE.VARS + TOTAL_ARGS - 1
                idx = idx + ai.TYPE.VARS - 1
            end
            ARGS_CHUNK[#ARGS_CHUNK + 1] = format([[
                ${FUNC_CHECK_VALUE}(L, ${ARGN}, &${ARG_NAME});
            ]])
        end

        if ai.ATTR.REF then
            assert(not fi.STATIC or (fi.RET.NUM > 0 and fi.RET.TYPE.LUACLS), fi.CPPFUNC)
            local REF = assert(ai.ATTR.REF[1], fi.CPPFUNC .. ' no ref action')
            local REFNAME = assert(ai.ATTR.REF[2], fi.CPPFUNC .. ' no refname')
            local WHICH_OBJ = ai.ATTR.REF[3] or (fi.STATIC and -1 or 1)
            if REF == 'map' then
                REF_CHUNK[#REF_CHUNK + 1] = format([[
                    olua_mapref(L, ${WHICH_OBJ}, "${REFNAME}", ${ARGN});
                ]])
            elseif REF == "single" then
                REF_CHUNK[#REF_CHUNK + 1] = format([[
                    olua_singleref(L, ${WHICH_OBJ}, "${REFNAME}", ${ARGN});
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
                REF_CHUNK[#REF_CHUNK + 1] = format([[
                    olua_mapunref(L, ${WHICH_OBJ}, "${REFNAME}", ${ARGN});
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
        local DECLTYPE = fi.RET.DECLTYPE
        local FUNC_PUSH_VALUE = fi.RET.TYPE.FUNC_PUSH_VALUE
        local SPACE = " "
        if string.find(DECLTYPE, '[ *&]$') then
            SPACE = ""
        end
        RET_EXP = format('${DECLTYPE}${SPACE}ret = (${DECLTYPE})')
        if fi.RET.TYPE.LUACLS and not olua.isvaluetype(fi.RET.TYPE) then
            RET_PUSH = format('int num_ret = ${FUNC_PUSH_VALUE}(L, ret, "${fi.RET.TYPE.LUACLS}");')
        elseif fi.RET.TYPE.SUBTYPE then
            local SUBTYPE = fi.RET.TYPE.SUBTYPE
            if SUBTYPE.LUACLS then
                RET_PUSH = format('int num_ret = ${FUNC_PUSH_VALUE}(L, ret, "${SUBTYPE.LUACLS}");')
            else
                local CAST = ""
                local SUBTYPE_PUSH_FUNC = SUBTYPE.FUNC_PUSH_VALUE
                if SUBTYPE.DECLTYPE ~= SUBTYPE.CPPCLS then
                    CAST = string.format("(%s)", SUBTYPE.DECLTYPE)
                end
                local DECLTYPE_NO_CONST = string.gsub(DECLTYPE, '^const _*', '')
                local POINT = olua.isvaluetype(fi.RET.TYPE.SUBTYPE) and '' or '&'
                if SUBTYPE.DECLTYPE == 'lua_Unsigned'
                    or SUBTYPE.DECLTYPE == 'lua_Number'
                    or SUBTYPE.CPPCLS == 'bool'
                    or SUBTYPE.DECLTYPE == 'lua_Integer' then
                    if fi.RET.TYPE.FN_ITERATOR then
                        RET_PUSH = format([[
                            int num_ret = 1;
                            int num_eles = 1;
                            lua_createtable(L, (int)ret.size(), 0);
                            for (auto it : ret) {
                                ${SUBTYPE_PUSH_FUNC}(L, ${POINT}${CAST}it);
                                lua_rawseti(L, -2, num_eles++);
                            }
                        ]])
                    else
                        RET_PUSH = format([[
                            int num_ret = 1;
                            int num_eles = 1;
                            lua_createtable(L, (int)ret.size(), 0);
                            for (int i = 0, n = (int)ret.size(); i < n; i++) {
                                ${SUBTYPE_PUSH_FUNC}(L, ${POINT}${CAST}((${DECLTYPE_NO_CONST})ret)[i]);
                                lua_rawseti(L, -2, num_eles++);
                            }
                        ]])
                    end
                else
                    if fi.RET.TYPE.FN_ITERATOR then
                        RET_PUSH = format([[
                            int num_ret = 1;
                            int num_eles = 1;
                            lua_createtable(L, (int)ret.size(), 0);
                            for (const auto &it : ret) {
                                ${SUBTYPE_PUSH_FUNC}(L, ${POINT}${CAST}it);
                                lua_rawseti(L, -2, num_eles++);
                            }
                        ]])
                    else
                        RET_PUSH = format([[
                            int num_ret = 1;
                            int num_eles = 1;
                            lua_createtable(L, (int)ret.size(), 0);
                            for (int i = 0, n = (int)ret.size(); i < n; i++) {
                                ${SUBTYPE_PUSH_FUNC}(L, ${POINT}${CAST}((${DECLTYPE_NO_CONST})ret)[i]);
                                lua_rawseti(L, -2, num_eles++);
                            }
                        ]])
                    end
                end
            end
        else
            if fi.RET.ATTR.UNPACK then
                FUNC_PUSH_VALUE = fi.RET.TYPE.FUNC_UNPACK_VALUE
            end
            local CAST = ""
            if fi.RET.TYPE.DECLTYPE ~= fi.RET.TYPE.CPPCLS then
                CAST = string.format("(%s)", fi.RET.TYPE.DECLTYPE)
            elseif not olua.isvaluetype(fi.RET.TYPE) then
                if not string.find(DECLTYPE, '*$') then
                    CAST = '&'
                end
            end
            RET_PUSH = format('int num_ret = ${FUNC_PUSH_VALUE}(L, ${CAST}ret);')
        end

        if #RET_PUSH > 0 then
            RET_NUM = "num_ret"
        end
    end

    return RET_EXP, RET_PUSH, RET_NUM
end

local function genOneFunc(cls, fi, write, funcidx, func_filter)
    local CPPCLS_PATH = olua.topath(cls.CPPCLS)
    local CALLFUNC = fi.CPPFUNC
    local FUNC_INDEX = funcidx or ""
    local CALLER = "self->"
    local ARGS_BEGIN = "("
    local ARGS_END = ")"
    local INJECT_BEFORE = fi.INJECT.BEFORE and {fi.INJECT.BEFORE} or {}
    local INJECT_AFTER = fi.INJECT.AFTER and {fi.INJECT.AFTER} or {}

    local funcname = format([[_${CPPCLS_PATH}_${fi.CPPFUNC}${FUNC_INDEX}]])
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
            local DECLTYPE = string.gsub(fi.RET.DECLTYPE, ' *%*$', '')
            local LUACLS = fi.RET.TYPE.LUACLS
            local snippet = format([[
                ${DECLTYPE} *self = new ${DECLTYPE}();
                ${DECLTYPE} *ret = self;
                self->autorelease();
                olua_push_cppobj<${DECLTYPE}>(L, self, "${LUACLS}");
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

        if fi.RET.TYPE.CPPCLS == 'void' then
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
            INJECT_AFTER[#INJECT_AFTER + 1] = format([[
                olua_singleref(L, ${WHICH_OBJ}, "${REFNAME}", ${IDX});
            ]])
        elseif REF == 'map' then
            if fi.RET.TYPE.IS_ARRAY then
                INJECT_AFTER[#INJECT_AFTER + 1] = format([[
                    olua_maprefarray(L, ${WHICH_OBJ}, "${REFNAME}", ${IDX});
                ]])
            else
                INJECT_AFTER[#INJECT_AFTER + 1] = format([[
                    olua_mapref(L, ${WHICH_OBJ}, "${REFNAME}", ${IDX});
                ]])
            end
        elseif REF == 'cmpunref' then
            INJECT_BEFORE[#INJECT_BEFORE + 1] = format([[
                olua_startcmpunref(L, ${WHICH_OBJ}, "${REFNAME}");
            ]])
            INJECT_AFTER[#INJECT_AFTER + 1] = format([[
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
            INJECT_BEFORE[#INJECT_BEFORE + 1] = format([[
                olua_startcmpunref(L, ${WHICH_OBJ}, "${REFNAME}");
            ]])
            INJECT_AFTER[#INJECT_AFTER + 1] = format([[
                olua_endcmpunref(L, ${WHICH_OBJ}, "${REFNAME}");
            ]])
        elseif REF == 'all' then
            INJECT_AFTER[#INJECT_AFTER + 1] = format([[
                olua_unrefall(L, ${WHICH_OBJ}, "${REFNAME}");
            ]])
        elseif REF == 'map' then
            INJECT_AFTER[#INJECT_AFTER + 1] = format([[
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

    write(format([[
        static int _${CPPCLS_PATH}_${fi.CPPFUNC}${FUNC_INDEX}(lua_State *L)
        {
            lua_settop(L, ${TOTAL_ARGS});

            ${DECL_CHUNK}

            ${ARGS_CHUNK}

            ${INJECT_BEFORE}

            ${CALLBACK}

            // ${fi.DECLFUNC}
            ${RET_EXP}${CALLER}${CALLFUNC}${ARGS_BEGIN}${CALLER_ARGS}${ARGS_END};
            ${RET_PUSH}

            ${INJECT_AFTER}

            return ${RET_NUM};
        }
    ]]))
    write('')
end

local function getFuncNArgs(fis, n)
    local arr = {}
    for _, v in ipairs(fis) do
        if v.MAX_ARGS == n then
            arr[#arr + 1] = v
        end
    end
    return arr
end

local function genTestAndCall(cls, fns)
    local CALL_CHUNK = {}
    for _, fi in ipairs(fns) do
        local CPPCLS_PATH = olua.topath(cls.CPPCLS)
        if #fi.ARGS > 0 then
            local TEST_ARGS = {}
            local MAX_VARS = 1
            for i, ai in ipairs(fi.ARGS) do
                local ARG_NAME = (fi.STATIC and 0 or 1) + i
                local FUNC_IS_VALUE = ai.TYPE.FUNC_IS_VALUE
                local TEST_NULL = ""

                MAX_VARS = math.max(ai.TYPE.VARS or 1, MAX_VARS)

                if ai.ATTR.PACK then
                    FUNC_IS_VALUE = assert(ai.TYPE.FUNC_ISPACK_VALUE, ai.TYPE.CPPCLS)
                end

                if ai.DEFAULT or ai.ATTR.NULLABLE then
                    TEST_NULL = ' ' .. format('|| olua_isnil(L, ${ARG_NAME})')
                end

                olua.nowarning(ARG_NAME, TEST_NULL, FUNC_IS_VALUE)
                if ai.TYPE.LUACLS and ai.TYPE.DECLTYPE ~= 'lua_Unsigned' then
                    TEST_ARGS[#TEST_ARGS + 1] = format([[
                        (${FUNC_IS_VALUE}(L, ${ARG_NAME}, "${ai.TYPE.LUACLS}")${TEST_NULL})
                    ]])
                else
                    TEST_ARGS[#TEST_ARGS + 1] = format([[
                        (${FUNC_IS_VALUE}(L, ${ARG_NAME})${TEST_NULL})
                    ]])
                end
            end

            olua.nowarning(CPPCLS_PATH)
            TEST_ARGS = table.concat(TEST_ARGS, " && ")
            CALL_CHUNK[#CALL_CHUNK + 1] = {
                MAX_VARS = MAX_VARS,
                EXP1 = format([[
                    // if (${TEST_ARGS}) {
                        return _${CPPCLS_PATH}_${fi.CPPFUNC}${fi.INDEX}(L);
                    // }
                ]]),
                EXP2 = format([[
                    if (${TEST_ARGS}) {
                        return _${CPPCLS_PATH}_${fi.CPPFUNC}${fi.INDEX}(L);
                    }
                ]]),
            }
        else
            if #fns > 1 then
                for _, v in ipairs(fns) do
                    print("same func", v, v.CPPFUNC)
                end
            end
            assert(#fns == 1, fi.CPPFUNC)
            CALL_CHUNK[#CALL_CHUNK + 1] = {
                MAX_VARS = 1,
                EXP1 = format([[
                    return _${CPPCLS_PATH}_${fi.CPPFUNC}${fi.INDEX}(L);
                ]])
            }
        end
    end

    table.sort(CALL_CHUNK, function (a, b)
        return a.MAX_VARS > b.MAX_VARS
    end)

    if #CALL_CHUNK > 1 then
        for i, v in ipairs(CALL_CHUNK) do
            CALL_CHUNK[i] = i == #CALL_CHUNK and v.EXP1 or v.EXP2
        end
    else
        CALL_CHUNK[1] = CALL_CHUNK[1].EXP1
    end

    return table.concat(CALL_CHUNK, "\n\n")
end

local function genMultiFunc(cls, fis, write, func_filter)
    local CPPCLS_PATH = olua.topath(cls.CPPCLS)
    local CPPFUNC = fis[1].CPPFUNC
    local SUBONE = fis[1].STATIC and "" or " - 1"
    local IF_CHUNK = {}

    for _, fi in ipairs(fis) do
        genOneFunc(cls, fi, write, fi.INDEX, func_filter)
    end

    local funcname = format([[_${CPPCLS_PATH}_${CPPFUNC}]])
    assert(not func_filter[funcname], cls.CPPCLS .. ' ' .. CPPFUNC)
    func_filter[funcname] = true

    for i = 0, fis.MAX_ARGS do
        local fns = getFuncNArgs(fis, i)
        if #fns > 0 then
            local TEST_AND_CALL = genTestAndCall(cls, fns)
            olua.nowarning(TEST_AND_CALL)
            IF_CHUNK[#IF_CHUNK + 1] = format([[
                if (num_args == ${i}) {
                    ${TEST_AND_CALL}
                }
            ]])
        end
    end

    IF_CHUNK = table.concat(IF_CHUNK, "\n\n")
    olua.nowarning(CPPCLS_PATH, SUBONE)
    write(format([[
        static int _${CPPCLS_PATH}_${CPPFUNC}(lua_State *L)
        {
            int num_args = lua_gettop(L)${SUBONE};

            ${IF_CHUNK}

            luaL_error(L, "method '${cls.CPPCLS}::${CPPFUNC}' not support '%d' arguments", num_args);

            return 0;
        }
    ]]))
    write('')
end

function olua.genclassfunc(cls, fis, write, func_filter)
    if #fis == 1 then
        genOneFunc(cls, fis[1], write, nil, func_filter)
    else
        genMultiFunc(cls, fis, write, func_filter)
    end
end
