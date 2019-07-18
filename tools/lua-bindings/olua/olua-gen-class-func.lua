local olua = require "olua.olua-io"

local format = olua.format

local function genSnippetFunc(cls, fi, write)
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

local function genFuncArgs(cls, fi, func)
    local idx = 0

    if not fi.STATIC then
        -- first argument is cpp userdata object
        func.TOTAL_ARGS = func.TOTAL_ARGS + 1
        idx = idx + 1
        local ti = olua.typeinfo(cls.CPPCLS .. "*")
        local OLUA_TO_TYPE = olua.convfunc(ti, 'to')
        olua.nowarning(OLUA_TO_TYPE)
        func.DECL_ARGS:push(format([[
            ${cls.CPPCLS} *self = nullptr;
        ]]))
        func.CHECK_ARGS:push(format([[
            ${OLUA_TO_TYPE}(L, 1, (void **)&self, "${ti.LUACLS}");
        ]]))
    end

    for i, ai in ipairs(fi.ARGS) do
        local ARG_NAME = "arg" .. i
        local SPACE = string.find(ai.TYPE.DECLTYPE, '[ *&]$') and '' or ' '
        local FUNC_CHECK_VALUE = olua.convfunc(ai.TYPE, 'check')
        local ARGN = idx + 1
        idx = ARGN

        if ai.TYPE.CPPCLS == 'std::function' then
            olua.assert(fi.CALLBACK_OPT, 'no callback option')
        end

        -- function call args
        -- see 'olua-basictype.lua'
        if ai.TYPE.DECLTYPE ~= ai.TYPE.CPPCLS and not ai.CALLBACK.ARGS then
            func.CALLER_ARGS:push(format([[(${ai.TYPE.CPPCLS})${ARG_NAME}]]))
        else
            func.CALLER_ARGS:push(format([[${ARG_NAME}]]))
        end

        -- args declare
        if ai.TYPE.INIT_VALUE then
            func.DECL_ARGS:push(format([[
                ${ai.TYPE.DECLTYPE}${SPACE}${ARG_NAME} = ${ai.TYPE.INIT_VALUE};   /** ${ai.VARNAME} */
            ]]))
        elseif ai.TYPE.SUBTYPE then
            -- ai.DECLTYPE = std::vector<std::string>
            -- ai.TYPE.DECLTYPE = std::vector
            func.DECL_ARGS:push(format([[
                ${ai.DECLTYPE}${SPACE}${ARG_NAME};       /** ${ai.VARNAME} */
            ]]))
        else
            func.DECL_ARGS:push(format([[
                ${ai.TYPE.DECLTYPE}${SPACE}${ARG_NAME};       /** ${ai.VARNAME} */
            ]]))
        end

        -- lua value to cpp value
        if (ai.DEFAULT or ai.ATTR.NULLABLE) and not fi.CALLBACK_OPT then
            local OLUA_OPT_VALUE = olua.convfunc(ai.TYPE, 'opt')
            local DEFAULT = ai.DEFAULT or "nullptr"
            olua.nowarning(OLUA_OPT_VALUE, DEFAULT)
            if ai.TYPE.LUACLS and not olua.isvaluetype(ai.TYPE) then
                func.CHECK_ARGS:push(format([[
                    ${OLUA_OPT_VALUE}(L, ${ARGN}, (void **)&${ARG_NAME}, "${ai.TYPE.LUACLS}", ${DEFAULT});
                ]]))
            else
                func.CHECK_ARGS:push(format([[
                    ${OLUA_OPT_VALUE}(L, ${ARGN}, &${ARG_NAME}, (${ai.TYPE.DECLTYPE})${DEFAULT});
                ]]))
            end
        elseif ai.TYPE.LUACLS and not olua.isvaluetype(ai.TYPE) then
            func.CHECK_ARGS:push(format([[
                ${FUNC_CHECK_VALUE}(L, ${ARGN}, (void **)&${ARG_NAME}, "${ai.TYPE.LUACLS}");
            ]]))
        elseif ai.TYPE.SUBTYPE then
            local SUBTYPE = ai.TYPE.SUBTYPE
            if SUBTYPE.LUACLS and not olua.isvaluetype(ai.TYPE) then
                func.CHECK_ARGS:push(format([[
                    ${FUNC_CHECK_VALUE}(L, ${ARGN}, ${ARG_NAME}, "${SUBTYPE.LUACLS}");
                ]]))
            else
                local SUBTYPE_CHECK_FUNC = olua.convfunc(SUBTYPE, 'check')
                local SUBTYPE_CAST = olua.typecast(SUBTYPE, true)
                local CHECK_VALUETYPE = format(ai.TYPE.CHECK_VALUETYPE)
                olua.nowarning(SUBTYPE_CHECK_FUNC, SUBTYPE_CAST, CHECK_VALUETYPE)
                func.CHECK_ARGS:push(format([[
                    luaL_checktype(L, ${ARGN}, LUA_TTABLE);
                    ${CHECK_VALUETYPE}
                ]]))
            end
        elseif not ai.CALLBACK.ARGS then
            if ai.ATTR.PACK then
                FUNC_CHECK_VALUE = olua.convfunc(ai.TYPE, 'pack')
                func.TOTAL_ARGS = ai.TYPE.VARS + func.TOTAL_ARGS - 1
                idx = idx + ai.TYPE.VARS - 1
            end
            func.CHECK_ARGS:push(format([[
                ${FUNC_CHECK_VALUE}(L, ${ARGN}, &${ARG_NAME});
            ]]))
        end

        olua.nowarning(ARG_NAME, SPACE, FUNC_CHECK_VALUE)

        -- ref or unref
        if ai.ATTR.REF then
            olua.assert(not fi.STATIC or (fi.RET.NUM > 0 and fi.RET.TYPE.LUACLS))
            local REF = assert(ai.ATTR.REF[1], fi.CPPFUNC .. ' no ref action')
            local REFNAME = assert(ai.ATTR.REF[2], fi.CPPFUNC .. ' no refname')
            local WHERE = ai.ATTR.REF[3] or (fi.STATIC and -1 or 1)
            olua.nowarning(REFNAME, WHERE)
            if REF == 'map' then
                func.INJECT_AFTER:push(format([[
                    olua_mapref(L, ${WHERE}, "${REFNAME}", ${ARGN});
                ]]))
            elseif REF == "single" then
                func.INJECT_AFTER:push(format([[
                    olua_singleref(L, ${WHERE}, "${REFNAME}", ${ARGN});
                ]]))
            else
                error('no support ref action: ' .. REF)
            end
        end
        if ai.ATTR.UNREF then
            olua.assert(not fi.STATIC or (fi.RET.NUM > 0 and fi.RET.TYPE.LUACLS))
            local REF = assert(ai.ATTR.UNREF[1], fi.CPPFUNC .. ' no ref action')
            local REFNAME = assert(ai.ATTR.UNREF[2], fi.CPPFUNC .. ' no refname')
            local WHERE = ai.ATTR.UNREF[3] or (fi.STATIC and -1 or 1)
            olua.nowarning(REFNAME, WHERE)
            if REF == 'map' then
                func.INJECT_AFTER:push(format([[
                    olua_mapunref(L, ${WHERE}, "${REFNAME}", ${ARGN});
                ]]))
            elseif REF == "single" then
                func.INJECT_AFTER:push(format([[
                    olua_singleunref(L, ${WHERE}, "${REFNAME}", ${ARGN});
                ]]))
            else
                error('no support ref action: ' .. REF)
            end
        end
    end
end

local function genFuncRet(cls, fi, func)
    if fi.RET.NUM > 0 then
        local DECLTYPE = fi.RET.DECLTYPE
        local OLUA_PUSH_VALUE = olua.convfunc(fi.RET.TYPE, 'push')
        local SPACE = string.find(DECLTYPE, '[ *&]$') and '' or ' '

        func.RET_EXP = format('${DECLTYPE}${SPACE}ret = (${DECLTYPE})')

        if fi.RET.TYPE.LUACLS and not olua.isvaluetype(fi.RET.TYPE) then
            func.PUSH_RET = format('int num_ret = ${OLUA_PUSH_VALUE}(L, ret, "${fi.RET.TYPE.LUACLS}");')
        elseif fi.RET.TYPE.SUBTYPE then
            local SUBTYPE = fi.RET.TYPE.SUBTYPE
            if SUBTYPE.LUACLS and not olua.isvaluetype(SUBTYPE) then
                func.PUSH_RET = format('int num_ret = ${OLUA_PUSH_VALUE}(L, ret, "${SUBTYPE.LUACLS}");')
            else
                local ARG_NAME = "ret"
                local SUBTYPE_CAST = olua.pointercast(SUBTYPE) .. olua.typecast(SUBTYPE)
                local SUBTYPE_PUSH_FUNC = olua.convfunc(SUBTYPE, 'push')
                local TYPE_CAST = string.gsub(DECLTYPE, '^const _*', '')
                local PUSH_VALUETYPE = format(fi.RET.TYPE.PUSH_VALUETYPE)
                olua.nowarning(ARG_NAME, SUBTYPE_CAST, SUBTYPE_PUSH_FUNC, TYPE_CAST, PUSH_VALUETYPE)
                func.PUSH_RET = format [[
                    int num_ret = 1;
                    ${PUSH_VALUETYPE}
                ]]
            end
        else
            if fi.RET.ATTR.UNPACK then
                OLUA_PUSH_VALUE = olua.convfunc(fi.RET.TYPE, 'unpack')
            end
            local TYPE_CAST = ""
            if fi.RET.TYPE.DECLTYPE ~= fi.RET.TYPE.CPPCLS then
                TYPE_CAST = string.format("(%s)", fi.RET.TYPE.DECLTYPE)
            elseif not olua.isvaluetype(fi.RET.TYPE) then
                if not string.find(DECLTYPE, '*$') then
                    TYPE_CAST = '&'
                end
            end
            olua.nowarning(OLUA_PUSH_VALUE, SPACE, TYPE_CAST)
            func.PUSH_RET = format('int num_ret = ${OLUA_PUSH_VALUE}(L, ${TYPE_CAST}ret);')
        end

        if #func.PUSH_RET > 0 then
            func.NUM_RET = "num_ret"
        end
    end

    if fi.RET.ATTR.REF then
        local REF = olua.assert(fi.RET.ATTR.REF[1], fi.CPPFUNC .. ' no ref name')
        local REFNAME = olua.assert(fi.RET.ATTR.REF[2], fi.CPPFUNC .. ' no ref name')
        local WHERE = fi.RET.ATTR.REF[3] or (fi.STATIC and -1 or 1)
        local IDX = -1

        if fi.RET.TYPE.CPPCLS == 'void' then
            olua.assert(not fi.STATIC, 'no ref object')
            IDX = 1
            WHERE = olua.assert(fi.RET.ATTR.REF[3], 'no store obj')
        elseif fi.RET.TYPE.SUBTYPE then
            olua.assert(REF == 'map', 'map ref only support the type with subtype')
            olua.assert(fi.RET.TYPE.SUBTYPE.LUACLS, fi.CPPFUNC .. ' sub ref object must be a userdata')
        else
            olua.assert(fi.RET.TYPE.LUACLS, fi.CPPFUNC .. ' ref object must be a userdata')
        end

        olua.assert(not fi.STATIC, fi.CPPFUNC .. ' only support instance func')
        olua.nowarning(REFNAME, WHERE, IDX)

        if REF == 'single' then
            func.INJECT_AFTER:push(format([[
                olua_singleref(L, ${WHERE}, "${REFNAME}", ${IDX});
            ]]))
        elseif REF == 'map' then
            if fi.RET.TYPE.SUBTYPE then
                func.INJECT_AFTER:push(format([[
                    olua_maprefarray(L, ${WHERE}, "${REFNAME}", ${IDX});
                ]]))
            else
                func.INJECT_AFTER:push(format([[
                    olua_mapref(L, ${WHERE}, "${REFNAME}", ${IDX});
                ]]))
            end
        else
            error('no support ref action: ' .. REF)
        end
    end

    if fi.RET.ATTR.UNREF then
        local REF = olua.assert(fi.RET.ATTR.UNREF[1], fi.CPPFUNC .. ' no ref name')
        local REFNAME = olua.assert(fi.RET.ATTR.UNREF[2], fi.CPPFUNC .. ' no ref name')
        local WHERE = fi.RET.ATTR.UNREF[3] or (fi.STATIC and -1 or 1)
        local IDX = -1

        if REF == 'map' then
            WHERE = olua.assert(fi.RET.ATTR.UNREF[3], 'no obj')
            IDX = 1
        else
            olua.assert(REF == 'cmp' or REF == 'all', fi.CPPFUNC .. ' void type only support cmpunref')
            olua.assert(not fi.STATIC, fi.CPPFUNC .. ' only support instance func')
        end

        olua.nowarning(REFNAME, WHERE, IDX)

        if REF == 'cmp' then
            func.INJECT_BEFORE:push(format([[
                olua_startcmpunref(L, ${WHERE}, "${REFNAME}");
            ]]))
            func.INJECT_AFTER:push(format([[
                olua_endcmpunref(L, ${WHERE}, "${REFNAME}");
            ]]))
        elseif REF == 'all' then
            func.INJECT_AFTER:push(format([[
                olua_unrefall(L, ${WHERE}, "${REFNAME}");
            ]]))
        elseif REF == 'map' then
            func.INJECT_AFTER:push(format([[
                olua_mapunref(L, ${WHERE}, "${REFNAME}", ${IDX});
            ]]))
        else
            error('no support ref action: ' .. REF)
        end
    end
end

local function genOneFunc(cls, fi, write, funcidx, exported)
    local CPPCLS_PATH = olua.topath(cls.CPPCLS)
    local FUNC_INDEX = funcidx or ''
    local CALLER = fi.STATIC and (cls.CPPCLS .. '::') or 'self->'
    local CPPFUNC = not fi.VARIABLE and fi.CPPFUNC or fi.VARNAME
    local ARGS_BEGIN = not fi.VARIABLE and '(' or (fi.RET.NUM > 0 and '' or ' = ')
    local ARGS_END = not fi.VARIABLE and ')' or ''

    local FUNC = {
        TOTAL_ARGS = #fi.ARGS,
        DECL_ARGS = olua.newarray(),
        CHECK_ARGS = olua.newarray(),
        CALLER_ARGS = olua.newarray(),
        INJECT_AFTER = olua.newarray(fi.INJECT.AFTER),
        INJECT_BEFORE = olua.newarray(fi.INJECT.BEFORE),
        PUSH_RET = "",
        RET_EXP = "",
        NUM_RET = "0",
        CALLBACK = "",
    }

    olua.message(fi.DECLFUNC)

    local funcname = format([[_${CPPCLS_PATH}_${fi.CPPFUNC}${FUNC_INDEX}]])
    if exported[funcname] then
        return
    end
    exported[funcname] = true

    if fi.CPPFUNC_SNIPPET then
        genSnippetFunc(cls, fi, write)
        return
    end

    genFuncArgs(cls, fi, FUNC)
    genFuncRet(cls, fi, FUNC)

    if fi.CALLBACK_OPT then
        FUNC.CALLBACK = olua.gencallback(cls, fi, write)

        -- user-defined the new block
        --[=[
            CALLBACK_OPT = {
                ...
                CPPFUNC = 'init',
                NEW = [[
                    auto *self = new ${DECLTYPE}();
                    auto *ret = self;
                    self->autorelease();
                    olua_push_cppobj<${DECLTYPE}>(L, self);
                ]],
            }
        ]=]
        if fi.STATIC and fi.CALLBACK_OPT.CPPFUNC and fi.RET.TYPE.LUACLS then
            local DECLTYPE = string.gsub(fi.RET.TYPE.DECLTYPE, ' *%*$', '')
            local LUACLS = fi.RET.TYPE.LUACLS
            olua.nowarning(DECLTYPE, LUACLS)
            FUNC.CALLBACK = format(fi.CALLBACK_OPT.NEW) .. '\n\n' .. FUNC.CALLBACK
            FUNC.RET_EXP = ''
            CALLER = 'self->'
            CPPFUNC = fi.CALLBACK_OPT.CPPFUNC
        end
    end

    if #FUNC.INJECT_BEFORE > 0 then
        table.insert(FUNC.INJECT_BEFORE, 1, '// inject code before call')
    end

    if #FUNC.INJECT_AFTER > 0 then
        table.insert(FUNC.INJECT_AFTER, 1, '// inject code after call')
    end

    FUNC.INJECT_AFTER = table.concat(FUNC.INJECT_AFTER, '\n')
    FUNC.INJECT_BEFORE = table.concat(FUNC.INJECT_BEFORE, '\n')
    FUNC.DECL_ARGS = table.concat(FUNC.DECL_ARGS, '\n')
    FUNC.CHECK_ARGS = table.concat(FUNC.CHECK_ARGS, '\n')
    FUNC.CALLER_ARGS = table.concat(FUNC.CALLER_ARGS, ', ')

    olua.nowarning(CPPCLS_PATH, FUNC_INDEX, CPPFUNC, CALLER, ARGS_BEGIN, ARGS_END)
    write(format([[
        static int _${CPPCLS_PATH}_${fi.CPPFUNC}${FUNC_INDEX}(lua_State *L)
        {
            lua_settop(L, ${FUNC.TOTAL_ARGS});

            ${FUNC.DECL_ARGS}

            ${FUNC.CHECK_ARGS}

            ${FUNC.INJECT_BEFORE}

            ${FUNC.CALLBACK}

            // ${fi.DECLFUNC}
            ${FUNC.RET_EXP}${CALLER}${CPPFUNC}${ARGS_BEGIN}${FUNC.CALLER_ARGS}${ARGS_END};
            ${FUNC.PUSH_RET}

            ${FUNC.INJECT_AFTER}

            return ${FUNC.NUM_RET};
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
                local OLUA_IS_VALUE = olua.convfunc(ai.TYPE, 'is')
                local TEST_NULL = ""

                MAX_VARS = math.max(ai.TYPE.VARS or 1, MAX_VARS)

                if ai.ATTR.PACK then
                    OLUA_IS_VALUE = olua.convfunc(ai.TYPE, 'ispack')
                end

                if ai.DEFAULT or ai.ATTR.NULLABLE then
                    TEST_NULL = ' ' .. format('|| olua_isnil(L, ${ARG_NAME})')
                end

                olua.nowarning(ARG_NAME, TEST_NULL, OLUA_IS_VALUE)
                if ai.TYPE.LUACLS and not olua.isvaluetype(ai.TYPE) then
                    TEST_ARGS[#TEST_ARGS + 1] = format([[
                        (${OLUA_IS_VALUE}(L, ${ARG_NAME}, "${ai.TYPE.LUACLS}")${TEST_NULL})
                    ]])
                else
                    TEST_ARGS[#TEST_ARGS + 1] = format([[
                        (${OLUA_IS_VALUE}(L, ${ARG_NAME})${TEST_NULL})
                    ]])
                end
            end

            TEST_ARGS = table.concat(TEST_ARGS, " && ")
            olua.nowarning(CPPCLS_PATH, TEST_ARGS)
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

local function genMultiFunc(cls, fis, write, exported)
    local CPPCLS_PATH = olua.topath(cls.CPPCLS)
    local CPPFUNC = fis[1].CPPFUNC
    local SUBONE = fis[1].STATIC and "" or " - 1"
    local IF_CHUNK = {}

    for _, fi in ipairs(fis) do
        genOneFunc(cls, fi, write, fi.INDEX, exported)
    end

    local funcname = format([[_${CPPCLS_PATH}_${CPPFUNC}]])
    assert(not exported[funcname], cls.CPPCLS .. ' ' .. CPPFUNC)
    exported[funcname] = true

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
    olua.nowarning(CPPCLS_PATH, SUBONE, IF_CHUNK)
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

function olua.genclassfunc(cls, fis, write, exported)
    if #fis == 1 then
        genOneFunc(cls, fis[1], write, nil, exported)
    else
        genMultiFunc(cls, fis, write, exported)
    end
end
