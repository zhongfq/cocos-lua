local olua = require "olua.olua-io"

local format = olua.format

local function genSnippetFunc(cls, fi, write)
    local CPPCLS_PATH = olua.topath(cls.CPPCLS)
    local CPPFUNC = fi.CPPFUNC
    local CPPFUNC_SNIPPET = fi.CPPFUNC_SNIPPET
    olua.nowarning(CPPCLS_PATH, CPPFUNC, CPPFUNC_SNIPPET)
    CPPFUNC_SNIPPET = string.gsub(CPPFUNC_SNIPPET, '^[\n ]*{',
        '{\n    olua_startinvoke(L);\n')
    CPPFUNC_SNIPPET = string.gsub(CPPFUNC_SNIPPET, '(\n)([ ]*)(return )', function (lf, indent, ret)
        local s = format([[
            ${lf}
            
            ${indent}olua_endinvoke(L);

            ${indent}${ret}
        ]])
        return s
    end)
    write(format([[
        static int _${CPPCLS_PATH}_${CPPFUNC}(lua_State *L)
        ${CPPFUNC_SNIPPET}
    ]]))
    write('')
end

function olua.genDeclExp(arg, name, out)
    local SPACE = string.find(arg.TYPE.DECLTYPE, '[ *&]$') and '' or ' '
    local ARG_NAME = name
    local VARNAME = ""
    local INITIALVALUE = ''
    if arg.VARNAME then
        VARNAME = format([[/** ${arg.VARNAME} */]])
    end
    if arg.TYPE.SUBTYPES then
        -- arg.DECLTYPE = std::vector<std::string>
        -- arg.TYPE.DECLTYPE = std::vector
        out.DECL_ARGS:push(format([[
            ${arg.DECLTYPE}${SPACE}${ARG_NAME};       ${VARNAME}
        ]]))
    else
        INITIALVALUE = olua.initialvalue(arg.TYPE)
        if INITIALVALUE and #INITIALVALUE > 0 then
            INITIALVALUE = ' = ' .. INITIALVALUE
        end
        out.DECL_ARGS:push(format([[
            ${arg.TYPE.DECLTYPE}${SPACE}${ARG_NAME}${INITIALVALUE};       ${VARNAME}
        ]]))
    end
    olua.nowarning(SPACE, ARG_NAME, VARNAME)
end

function olua.genCheckExp(arg, name, i, out)
    -- lua value to cpp value
    local ARGN = i
    local ARG_NAME = name
    local OLUA_CHECK_VALUE = olua.convfunc(arg.TYPE, 'check')
    if (arg.DEFAULT or arg.ATTR.NULLABLE) and not next(arg.CALLBACK or {}) then
        local OLUA_OPT_VALUE = olua.convfunc(arg.TYPE, 'opt')
        local DEFAULT = arg.DEFAULT or "nullptr"
        olua.nowarning(OLUA_OPT_VALUE, DEFAULT)
        if olua.ispointee(arg.TYPE) then
            out.CHECK_ARGS:push(format([[
                ${OLUA_OPT_VALUE}(L, ${ARGN}, (void **)&${ARG_NAME}, "${arg.TYPE.LUACLS}", ${DEFAULT});
            ]]))
        else
            out.CHECK_ARGS:push(format([[
                ${OLUA_OPT_VALUE}(L, ${ARGN}, &${ARG_NAME}, (${arg.TYPE.DECLTYPE})${DEFAULT});
            ]]))
        end
    elseif olua.ispointee(arg.TYPE) then
        out.CHECK_ARGS:push(format([[
            ${OLUA_CHECK_VALUE}(L, ${ARGN}, (void **)&${ARG_NAME}, "${arg.TYPE.LUACLS}");
        ]]))
    elseif arg.TYPE.SUBTYPES then
        if #arg.TYPE.SUBTYPES > 1 then
            out.CHECK_ARGS:push(arg.TYPE.CHECK_VALUE(arg, name, i))
        else
            local SUBTYPE = arg.TYPE.SUBTYPES[1]
            if olua.ispointee(SUBTYPE) then
                out.CHECK_ARGS:push(format([[
                    ${OLUA_CHECK_VALUE}(L, ${ARGN}, ${ARG_NAME}, "${SUBTYPE.LUACLS}");
                ]]))
            else
                local SUBTYPE_CHECK_FUNC = olua.convfunc(SUBTYPE, 'check')
                local SUBTYPE_CAST = olua.typecast(SUBTYPE, true)
                local CHECK_VALUE = format(arg.TYPE.CHECK_VALUE)
                olua.nowarning(SUBTYPE_CHECK_FUNC, SUBTYPE_CAST, CHECK_VALUE)
                out.CHECK_ARGS:push(format([[
                    luaL_checktype(L, ${ARGN}, LUA_TTABLE);
                    ${CHECK_VALUE}
                ]]))
            end
        end
    elseif not arg.CALLBACK or not arg.CALLBACK.ARGS then
        if arg.ATTR.PACK then
            OLUA_CHECK_VALUE = olua.convfunc(arg.TYPE, 'pack')
            out.TOTAL_ARGS = arg.TYPE.VARS + out.TOTAL_ARGS - 1
            out.IDX = out.IDX + arg.TYPE.VARS - 1
        end
        out.CHECK_ARGS:push(format([[
            ${OLUA_CHECK_VALUE}(L, ${ARGN}, &${ARG_NAME});
        ]]))
    end

    olua.nowarning(ARG_NAME, ARGN, OLUA_CHECK_VALUE)
end

function olua.genRefExp(fi, arg, i, out)
    if not arg.ATTR.REF then
        return
    end

    olua.assert(not fi.STATIC or fi.RET.TYPE.LUACLS)

    local ARGN = i
    local REF = assert(arg.ATTR.REF[1], fi.CPPFUNC .. ' no ref action')
    local REFNAME = assert(arg.ATTR.REF[2], fi.CPPFUNC .. ' no refname')
    local WHERE = arg.ATTR.REF[3] or (fi.STATIC and -1 or 1)

    if arg.TYPE.CPPCLS == 'void' then
        olua.assert(fi.RET == arg)
        olua.assert(not fi.STATIC, 'no ref object')
        olua.assert(arg.ATTR.REF[3], 'must supply where to hold ref')
        if arg.ATTR.REF[3] then
            ARGN = 1
        end
    elseif arg.TYPE.SUBTYPES then
        local SUBTYPE = arg.TYPE.SUBTYPES[1]
        olua.assert(REF == 'map', 'expect use map ref')
        olua.assert(olua.ispointee(SUBTYPE), "'%s' not a pointer type", SUBTYPE.CPPCLS)
    else
        olua.assert(olua.ispointee(arg.TYPE), "'%s' not a pointer type", arg.TYPE.CPPCLS)
    end

    if REF == 'map' then
        if arg.TYPE.SUBTYPES then
            out.INJECT_AFTER:push(format([[
                olua_maprefarray(L, ${WHERE}, "${REFNAME}", ${ARGN});
            ]]))
        else
            out.INJECT_AFTER:push(format([[
                olua_mapref(L, ${WHERE}, "${REFNAME}", ${ARGN});
            ]]))
        end
    elseif REF == "single" then
        out.INJECT_AFTER:push(format([[
            olua_singleref(L, ${WHERE}, "${REFNAME}", ${ARGN});
        ]]))
    else
        error('no support ref action: ' .. REF)
    end

    olua.nowarning(ARGN, REFNAME, WHERE)
end

function olua.genUnrefExp(fi, arg, i, out)
    if not arg.ATTR.UNREF then
        return
    end

    olua.assert(not fi.STATIC or arg.TYPE.LUACLS)

    local ARGN = i
    local UNREF = assert(arg.ATTR.UNREF[1], fi.CPPFUNC .. ' no ref action')
    local REFNAME = assert(arg.ATTR.UNREF[2], fi.CPPFUNC .. ' no refname')
    local WHERE = arg.ATTR.UNREF[3] or (fi.STATIC and -1 or 1)

    if UNREF == 'map' or UNREF == 'single' then
        if arg.TYPE.CPPCLS  == 'void' then
            olua.assert(not fi.STATIC, 'no ref object')
            olua.assert(arg.ATTR.UNREF[3], 'must supply where to hold ref')
            ARGN = 1
        else
            olua.assert(olua.ispointee(arg.TYPE), "'%s' not a pointer type", arg.TYPE.CPPCLS)
        end
    end

    if UNREF == 'cmp' then
        out.INJECT_BEFORE:push(format([[
            olua_startcmpunref(L, ${WHERE}, "${REFNAME}");
        ]]))
        out.INJECT_AFTER:push(format([[
            olua_endcmpunref(L, ${WHERE}, "${REFNAME}");
        ]]))
    elseif UNREF == 'all' then
        out.INJECT_AFTER:push(format([[
            olua_unrefall(L, ${WHERE}, "${REFNAME}");
        ]]))
    elseif UNREF == 'map' then
        out.INJECT_AFTER:push(format([[
            olua_mapunref(L, ${WHERE}, "${REFNAME}", ${ARGN});
        ]]))
    elseif UNREF == "single" then
        out.INJECT_AFTER:push(format([[
            olua_singleunref(L, ${WHERE}, "${REFNAME}", ${ARGN});
        ]]))
    else
        error('no support ref action: ' .. UNREF)
    end

    olua.nowarning(ARGN, REFNAME, WHERE)
end

local function genFuncArgs(cls, fi, func)
    if not fi.STATIC then
        -- first argument is cpp userdata object
        func.TOTAL_ARGS = func.TOTAL_ARGS + 1
        func.IDX = func.IDX + 1
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
        local ARGN = func.IDX + 1
        func.IDX = ARGN

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

        olua.genDeclExp(ai, ARG_NAME, func)
        olua.genCheckExp(ai, ARG_NAME, ARGN, func)
        olua.genRefExp(fi, ai, ARGN, func)
        olua.genUnrefExp(fi, ai, ARGN, func)
    end
end

function olua.genPushExp(arg, name, out)
    local ARG_NAME = name
    local OLUA_PUSH_VALUE = olua.convfunc(arg.TYPE, 'push')
    if olua.ispointee(arg.TYPE) then
        out.PUSH_ARGS:push(format('${OLUA_PUSH_VALUE}(L, ${ARG_NAME}, "${arg.TYPE.LUACLS}");'))
    elseif arg.TYPE.SUBTYPES then
        if #arg.TYPE.SUBTYPES > 1 then
            out.PUSH_ARGS:push(arg.TYPE.PUSH_VALUE(arg, name))
        else
            local SUBTYPE = arg.TYPE.SUBTYPES[1]
            if olua.ispointee(SUBTYPE) then
                out.PUSH_ARGS:push(format('${OLUA_PUSH_VALUE}(L, ${ARG_NAME}, "${SUBTYPE.LUACLS}");'))
            else
                local SUBTYPE_CAST = olua.pointercast(SUBTYPE) .. olua.typecast(SUBTYPE)
                local SUBTYPE_PUSH_FUNC = olua.convfunc(SUBTYPE, 'push')
                local TYPE_CAST = string.gsub(arg.DECLTYPE, '^const _*', '')
                out.PUSH_ARGS:push(format(arg.TYPE.PUSH_VALUE))
                olua.nowarning(ARG_NAME, SUBTYPE_CAST, SUBTYPE_PUSH_FUNC, TYPE_CAST)
            end
        end
    else
        if arg.ATTR.UNPACK then
            OLUA_PUSH_VALUE = olua.convfunc(arg.TYPE, 'unpack')
        end
        local TYPE_CAST = ""
        if arg.TYPE.DECLTYPE ~= arg.TYPE.CPPCLS then
            TYPE_CAST = string.format("(%s)", arg.TYPE.DECLTYPE)
        elseif not olua.isvaluetype(arg.TYPE) then
            if not string.find(arg.DECLTYPE, '*$') then
                TYPE_CAST = '&'
            end
        end
        olua.nowarning(OLUA_PUSH_VALUE, TYPE_CAST)
        out.PUSH_ARGS:push(format('${OLUA_PUSH_VALUE}(L, ${TYPE_CAST}${ARG_NAME});'))
    end
end

local function genFuncRet(cls, fi, func)
    if fi.RET.NUM > 0 then
        local SPACE = string.find(fi.RET.DECLTYPE, '[ *&]$') and '' or ' '
        func.RET_EXP = format('${fi.RET.DECLTYPE}${SPACE}ret = (${fi.RET.DECLTYPE})')

        local OUT = {PUSH_ARGS = olua.newarray()}
        olua.genPushExp(fi.RET, 'ret', OUT)

        if fi.RET.TYPE.SUBTYPES and not olua.ispointee(fi.RET.TYPE.SUBTYPES[1]) then
            func.PUSH_RET = format([[
                int num_ret = 1;
                ${OUT.PUSH_ARGS}
            ]])
        else
            func.PUSH_RET = format('int num_ret = ${OUT.PUSH_ARGS}')
        end

        if #func.PUSH_RET > 0 then
            func.NUM_RET = "num_ret"
        end

        olua.nowarning(SPACE)
    end

    olua.genRefExp(fi, fi.RET, -1, func)
    olua.genUnrefExp(fi, fi.RET, -1, func)
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
        IDX = 0,
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
        FUNC.CALLBACK = olua.genCallback(cls, fi, write)

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
        if fi.CALLBACK_OPT.NEW then
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

    FUNC.CALLER_ARGS = FUNC.CALLER_ARGS:tostring(', ')

    olua.nowarning(CPPCLS_PATH, FUNC_INDEX, CPPFUNC, CALLER, ARGS_BEGIN, ARGS_END)
    write(format([[
        static int _${CPPCLS_PATH}_${fi.CPPFUNC}${FUNC_INDEX}(lua_State *L)
        {
            olua_startinvoke(L);

            lua_settop(L, ${FUNC.TOTAL_ARGS});

            ${FUNC.DECL_ARGS}

            ${FUNC.CHECK_ARGS}

            ${FUNC.INJECT_BEFORE}

            ${FUNC.CALLBACK}

            // ${fi.DECLFUNC}
            ${FUNC.RET_EXP}${CALLER}${CPPFUNC}${ARGS_BEGIN}${FUNC.CALLER_ARGS}${ARGS_END};
            ${FUNC.PUSH_RET}

            ${FUNC.INJECT_AFTER}

            olua_endinvoke(L);

            return ${FUNC.NUM_RET};
        }
    ]]))
    write('')
end

local function getFuncNArgs(cls, fis, n)
    local arr = {}
    for _, v in ipairs(fis) do
        local min = 0
        for _, arg in ipairs(v.ARGS) do
            if arg.ATTR.PACK or arg.ATTR.UNPACK then
                min = nil
                break
            elseif not arg.ATTR.NULLABLE and
                not arg.CALLBACK.DEFAULT and
                arg.DEFAULT == nil then
                min = (min or 0) + 1
            end
        end
        if v.MAX_ARGS == n or (min and (n >= min and n <= v.MAX_ARGS)) then
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
                local ARGN = (fi.STATIC and 0 or 1) + i
                local OLUA_IS_VALUE = olua.convfunc(ai.TYPE, 'is')
                local TEST_NULL = ""

                MAX_VARS = math.max(ai.TYPE.VARS or 1, MAX_VARS)

                if ai.ATTR.PACK then
                    OLUA_IS_VALUE = olua.convfunc(ai.TYPE, 'ispack')
                end

                if ai.DEFAULT or ai.ATTR.NULLABLE then
                    TEST_NULL = ' ' .. format('|| olua_isnil(L, ${ARGN})')
                end

                olua.nowarning(ARGN, TEST_NULL, OLUA_IS_VALUE)
                if olua.ispointee(ai.TYPE) then
                    TEST_ARGS[#TEST_ARGS + 1] = format([[
                        (${OLUA_IS_VALUE}(L, ${ARGN}, "${ai.TYPE.LUACLS}")${TEST_NULL})
                    ]])
                else
                    TEST_ARGS[#TEST_ARGS + 1] = format([[
                        (${OLUA_IS_VALUE}(L, ${ARGN})${TEST_NULL})
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
        local fns = getFuncNArgs(cls, fis, i)
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

function olua.genClassFunc(cls, fis, write, exported)
    if #fis == 1 then
        genOneFunc(cls, fis[1], write, nil, exported)
    else
        genMultiFunc(cls, fis, write, exported)
    end
end
