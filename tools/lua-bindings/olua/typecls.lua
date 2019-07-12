local olua = require "olua.core"

local typeinfo_map = {}
local class_map = {}

local format = olua.format

local function to_pretty_typename(typename)
    -- t = '   const   type   *   &  '
    -- typename = string.gsub(typename, '&', '')   -- t = '   const  type   *    '
    typename = string.gsub(typename, '^ *', '') -- t = 'const  type   *    '
    typename = string.gsub(typename, ' *$', '') -- t = 'const  type   *'
    typename = string.gsub(typename, ' +', ' ') -- t = 'const type *'

    -- const type * * => const type **
    typename = string.gsub(typename, ' %*', '*')
    typename = string.gsub(typename, '%*+', function (str) return " " .. str end)

    typename = string.gsub(typename, ' %&', '&')
    typename = string.gsub(typename, '%&+', function (str) return " " .. str end)

    return typename
end

local function to_real_typename(typename)
    typename = string.gsub(typename, '&', '')
    typename = string.gsub(typename, ' *$', '')

    if typeinfo_map[typename] then
        return typename, true
    end

    local noconst = string.gsub(typename, 'const *', '')
    if typeinfo_map[noconst] then
        return noconst, true
    end
    
    return typename, false
end

function test_typename(typename)
    return typeinfo_map[typename]
end

function get_typeinfo(typename, cls, silence)
    local typename = to_pretty_typename(typename)
    local typeinfo
    local subtypeinfo, subtypename -- for typename<T>

    if string.find(typename, '<') then
        subtypename = string.match(typename, '<(.*)>')
        subtypeinfo, subtypename = get_typeinfo(subtypename, cls, silence)
        typename = string.gsub(typename, '<.*>', '')
    end

    typename = to_real_typename(typename)
    typeinfo = typeinfo_map[typename]

    if typeinfo then
        typeinfo = setmetatable({SUBTYPE = subtypeinfo}, {__index = typeinfo})
        return typeinfo, typename, subtypename
    end

    if cls and cls.CPPCLS then
        local function try_namespace(ns, typename)
            local tn = string.gsub(typename, '[%w:_]+ *%**$', function (s)
                return ns .. '::' .. s
            end)
            tn = to_real_typename(tn)
            return typeinfo_map[tn], tn
        end

        local ti, tn
        local nsarr = {}
        for n in string.gmatch(cls.CPPCLS, '[^:]+') do
            nsarr[#nsarr + 1] = n
        end

        while #nsarr > 0 do
            local ns = table.concat(nsarr, "::")
            ti, tn = try_namespace(ns, typename)
            if not ti then
                nsarr[#nsarr] = nil
            else
                break
            end
        end

        if ti then
            typeinfo = ti
            typename = tn
        end

        if typeinfo then
            typeinfo = setmetatable({SUBTYPE = subtypeinfo}, {__index = typeinfo})
            return typeinfo, typename, subtypename
        end
    end

    if cls and string.find(typename, '::') then
        local ns, t = string.match(typename, '(.*)::([^:]+)$')
        if class_map[ns] then
            return get_typeinfo(t, class_map[ns], silence)
        end
        local ns2, _ = string.match(cls.CPPCLS, '(.*)::([^:]+)$')
        if ns2 then
            ns = ns2 .. '::' .. ns
            if class_map[ns] then
                return get_typeinfo(t, class_map[ns], silence)
            end
        end
    end

    if cls and cls.SUPERCLS then
        cls = assert(class_map[cls.SUPERCLS], cls.SUPERCLS)
        return get_typeinfo(typename, cls, silence)
    end

    if not typeinfo and not silence then
        error(string.format("type info not found: %s", typename))
    end
end

local function to_decl_type(cls, typename, remove_const, keep_ref)
    local ref = string.match(typename, '&+')
    local typeinfo, typename, subtypename = get_typeinfo(typename, cls)

    if subtypename then
        typename = string.format('%s<%s>', typename, subtypename)
        if remove_const then
            typename = string.gsub(typename, 'const *', '')
        end
    end

    if keep_ref and ref then
        typename = typename .. ' ' .. ref
    end

    return typename
end

local function parse_attr(arg)
    local attr = {}
    arg = string.gsub(arg, '^ *', '')
    while true do
        local opt, value = string.match(arg, '^@(%w+)%(([%w ]*)%)')
        if opt then
            local arr = {}
            for v in string.gmatch(value, '[^ ]+') do
                arr[#arr + 1] = v
            end
            attr[string.upper(opt)] = arr
            arg = string.gsub(arg, '^@%w+%([%w ]*%)', '')
        else
            opt = string.match(arg, '^@(%w+)')
            if opt then
                attr[string.upper(opt)] = {}
                arg = string.gsub(arg, '^@%w+', '')
            else
                break
            end
        end
    end
    local arg, static = string.gsub(arg, '^ *static *', '')
    attr.STATIC = static > 0
    return attr, arg
end

local function parse_def(str)
    local KEYWORD = {const = true, signed = true, unsigned = true}
    local attr, str = parse_attr(str)
    local typename = string.match(str, '^[^<>(),]*%b<>[ &*]*')
    if not typename then
        local from, to
        while true do
            from, to = string.find(str, ' *[^&* (),]+[ &*]*', to)
            if not from then
                break
            end
            typename = string.sub(str, from, to)
            local tt = string.gsub(typename, ' ', '')
            if tt == 'signed' or tt == 'unsigned' then
                local substr = string.sub(str, to + 1)
                if not (substr:find('^ *int *')
                    or substr:find('^ *short *')
                    or substr:find('^ *char *')) then
                    str = string.sub(str, to + 1)
                    typename = typename .. ' int'
                    return to_pretty_typename(typename), attr, str
                end
            end
            if not KEYWORD[string.match(typename, '%w+')] then
                typename = string.sub(str, 1, to)
                break
            end
        end
    end
    str = string.sub(str, #typename + 1)
    return to_pretty_typename(typename), attr, str
end

local parse_args

local function parse_callback(cls, typename, default)
    local rt, rt_attr, cb_args_str
    local cb_args_str = string.match(typename, '<(.*)>')
    rt, rt_attr, cb_args_str = parse_def(cb_args_str)
    cb_args_str = string.gsub(cb_args_str, '^[^(]+', '')
    local cb_args = parse_args(cls, cb_args_str)
    local cb_args_decl = {}
    for _, ai in ipairs(cb_args) do
        cb_args_decl[#cb_args_decl + 1] = ai.FUNC_ARG_DECL_TYPE
    end
    cb_args_decl = table.concat(cb_args_decl, ", ")
    cb_args_decl = string.format('std::function<%s(%s)>',
        to_decl_type(cls, rt, false, true), cb_args_decl)
    return {
        DEFAULT = default,
        ARGS = cb_args,
        RET = get_typeinfo(rt, cls),
        RET_ATTR = rt_attr,
        ARGS_DECL = cb_args_decl,
    }
end

function parse_args(cls, args_str)
    local args = {}
    local max_args = 0
    args_str = assert(string.match(args_str, '%((.*)%)'), args_str)

    while #args_str > 0 do
        local typename, attr, varname, default
        typename, attr, args_str = parse_def(args_str)
        if typename == 'void' then
            return args, max_args
        end

        varname, default = string.match(args_str, '^([^ ]+) *= *([^ ,]*)')
        if not varname then
            varname = string.match(args_str, '^ *[^ ,]+')
        end

        args_str = string.gsub(args_str, '^[^,]*,? *', '')

        if default then
            if string.find(default, '%(') then
                if not string.find(default, '%)') then
                    local other = string.match(args_str, '[^)]+%)')
                    assert(other, default .. ' ' .. args_str)
                    default = default .. ', ' .. other
                end
                args_str = string.gsub(args_str, '^[^)]*%),? *', '')
                local deft = string.match(default, '[^(]+')
                local defti = get_typeinfo(deft, cls, true) or get_typeinfo(deft .. ' *', cls)
                default = string.gsub(defti.CPPCLS, ' *%**', '') .. string.match(default, '(%([^()]*%))')
            elseif string.find(default, '::') then
                local deft, def = string.match(default, '(.*)::([^:]+)$')
                local defti = get_typeinfo(deft, cls, true) or  get_typeinfo(deft .. ' *', cls)
                default = string.gsub(defti.CPPCLS, ' *%**', '') .. '::' .. def
            end
        end

        if string.find(typename, 'std::function<') then
            local callback = parse_callback(cls, typename, default)
            args[#args + 1] = {
                TYPE = setmetatable({
                    DECL_TYPE = callback.ARGS_DECL,
                }, {__index = get_typeinfo('std::function', cls)}),
                DECL_TYPE = callback.ARGS_DECL,
                VARNAME = varname,
                ATTR = attr,
                CALLBACK = callback,
            }
        else
            args[#args + 1] = {
                TYPE = get_typeinfo(typename, cls),
                DECL_TYPE = to_decl_type(cls, typename, true),
                FUNC_ARG_DECL_TYPE = to_decl_type(cls, typename, false, true),
                DEFAULT = default,
                VARNAME = varname,
                ATTR = attr,
                CALLBACK = {},
            }
        end

        if attr.PACK then
            max_args = max_args + assert(args[#args].TYPE.VARS, args[#args].TYPE.CPPCLS)
        else
            max_args = max_args + 1
        end
    end

    return args, max_args
end

local function parse_func(cls, name, ...)
    local function copy(t)
        return setmetatable({}, {__index = t})
    end
    local arr = {MAX_ARGS = 0}
    for i, func_decl in ipairs({...}) do
        local fi = {RET = {}}
        if string.find(func_decl, '{') then
            fi.LUAFUNC = assert(name)
            fi.CPPFUNC = name
            fi.CPPFUNC_SNIPPET = func_decl
            fi.FUNC_DECL = '<function snippet>'
            fi.RET.NUM = 0
            fi.RET.TYPE = get_typeinfo('void', cls)
            fi.RET.ATTR = {}
            fi.ARGS = {}
            fi.INJECT = {}
            fi.PROTOTYPE = false
            fi.MAX_ARGS = #fi.ARGS
        else
            local typename, attr, str = parse_def(func_decl)
            fi.CPPFUNC = string.match(str, '[^ ()]+')
            fi.LUAFUNC = name or fi.CPPFUNC
            fi.STATIC = attr.STATIC
            fi.FUNC_DECL = func_decl
            fi.INJECT = {}
            if string.find(typename, 'std::function<') then
                local callback = parse_callback(cls, typename, default)
                fi.RET = {
                    TYPE = setmetatable({
                        DECL_TYPE = callback.ARGS_DECL,
                    }, {__index = get_typeinfo('std::function', cls)}),
                    DECL_TYPE = callback.ARGS_DECL,
                    ATTR = attr,
                    NUM = 1,
                    CALLBACK = callback,
                }
            else
                fi.RET.TYPE = get_typeinfo(typename, cls)
                fi.RET.NUM = fi.RET.TYPE.CPPCLS == "void" and 0 or 1
                fi.RET.DECL_TYPE = to_decl_type(cls, typename, false, true)
                fi.RET.ATTR = attr
            end
            fi.ARGS, fi.MAX_ARGS = parse_args(cls, string.sub(str, #fi.CPPFUNC + 1))

            do
                local ARGS_DECL = {}
                local RET_DECL = fi.RET.SUBTYPE and fi.RET.DECL_TYPE or fi.RET.TYPE.CPPCLS
                local CPPFUNC = fi.CPPFUNC
                local STATIC = fi.STATIC and "static " or ""
                for _, v in ipairs(fi.ARGS) do
                    ARGS_DECL[#ARGS_DECL + 1] = (v.TYPE.SUBTYPE or next(v.CALLBACK)) and v.DECL_TYPE or v.TYPE.CPPCLS
                end
                ARGS_DECL = table.concat(ARGS_DECL, ", ")

                fi.PROTOTYPE = format([[
                    ${STATIC}${RET_DECL} ${CPPFUNC}(${ARGS_DECL})
                ]])
                cls.PROTOTYPES[fi.PROTOTYPE] = true
            end

            -- has @pack? gen one more func
            if fi.MAX_ARGS ~= #fi.ARGS then
                local packarg
                local fi2 = copy(fi)
                fi2.RET = copy(fi.RET)
                fi2.RET.ATTR = copy(fi.RET.ATTR)
                fi2.ARGS = {}
                fi2.FUNC_DECL = string.gsub(fi.FUNC_DECL, '@pack *', '')
                for i in ipairs(fi.ARGS) do
                    fi2.ARGS[i] = copy(fi.ARGS[i])
                    fi2.ARGS[i].ATTR = copy(fi.ARGS[i].ATTR)
                    if fi.ARGS[i].ATTR.PACK then
                        assert(not packarg, 'too many pack args')
                        packarg = fi.ARGS[i]
                        fi2.ARGS[i].ATTR.PACK = false
                        fi2.MAX_ARGS = fi2.MAX_ARGS + 1 - packarg.TYPE.VARS
                    end
                end
                assert(packarg, func_decl)
                if packarg.TYPE.CPPCLS == fi.RET.TYPE.CPPCLS then
                    fi2.RET.ATTR.UNPACK = fi.RET.ATTR.UNPACK or false
                    fi.RET.ATTR.UNPACK = true
                end
                arr[#arr + 1] = fi2
                fi2.INDEX = #arr
            end
        end
        assert(not string.find(fi.LUAFUNC, '[^_%w]+'), '"' .. fi.LUAFUNC .. '"')
        arr[#arr + 1] = fi
        arr.MAX_ARGS = math.max(arr.MAX_ARGS, fi.MAX_ARGS)
        fi.INDEX = #arr
    end

    return arr
end

local function to_prop_func_name(cppfunc, prefix)
    return prefix .. string.gsub(cppfunc, '^%w', function (s)
        return string.upper(s)
    end)
end

local function parse_prop(cls, name, func_get, func_set)
    local pi = {}
    pi.PROP_NAME = assert(name)

    local name2 = string.gsub(name, '^%l+', function (s)
        return string.upper(s)
    end)

    local function test(f, name, op)
        name = to_prop_func_name(name, op)
        return name == f.CPPFUNC or name == f.LUAFUNC
    end

    if func_get then
        pi.GET = func_get and parse_func(cls, name, func_get)[1] or nil
    else
        for _, v in ipairs(cls.FUNCS) do
            for _, f in ipairs(v) do
                if test(f, name, 'get') or
                    test(f, name, 'is') or
                    test(f, name2, 'get') or
                    test(f, name2, 'is') then
                    assert(#f.ARGS == 0, f.CPPFUNC)
                    pi.GET = f
                end
            end
        end
        assert(pi.GET, name)
    end

    if func_set then
        pi.SET = func_set and parse_func(cls, name, func_set)[1] or nil
    else
        for _, v in ipairs(cls.FUNCS) do
            for _, f in ipairs(v) do
                if test(f, name, 'set') or
                    test(f, name2, 'set') then
                    pi.SET = f
                end
            end
        end
    end

    if not pi.GET.CPPFUNC_SNIPPET then
        assert(pi.GET.RET.NUM > 0, func_get)
    elseif func_get then
        pi.GET.CPPFUNC = 'get_' .. pi.GET.CPPFUNC
    end

    if pi.SET and pi.SET.CPPFUNC_SNIPPET and func_set then
        pi.SET.CPPFUNC = 'set_' .. pi.SET.CPPFUNC
    end

    return pi
end

function olua.typecls(collection)
    local cls = {}
    cls.FUNCS = {}
    cls.CONSTS = {}
    cls.ENUMS = {}
    cls.PROPS = {}
    cls.VARS = {}
    cls.PROTOTYPES = {}
    cls.REG_LUATYPE = true

    setmetatable(cls, {__newindex = function (_, k, v)
        rawset(cls, k, v)
        if k == 'CPPCLS' then
            class_map[cls.CPPCLS] = cls
        end
    end})

    if collection then
        collection[#collection + 1] = cls
    end

    function cls.func(name, ...)
        cls.FUNCS[#cls.FUNCS + 1] = parse_func(cls, name, ...)
    end

    function cls.funcs(funcs_str)
        local arr = {}
        local dict = {}
        for func_decl in string.gmatch(funcs_str, '[^\n\r]+') do
            func_decl = string.gsub(func_decl, '^ *', '')
            func_decl = string.gsub(func_decl, ' *inline ', '')
            if #func_decl > 0 then
                if not string.find(func_decl, '^ *//') then
                    local _, str = parse_attr(func_decl)
                    local fn = string.match(str, '([^ ()]+) *%(')
                    local t = dict[fn]
                    assert(fn, func_decl)
                    if not t then
                        t = {}
                        arr[#arr + 1] = t
                        dict[fn] = t
                    end
                    t[#t + 1] = string.gsub(func_decl, '^ *', '')
                end
            end
        end
        for _, v in ipairs(arr) do
            cls.func(nil, table.unpack(v))
        end
    end

    function cls.inject(cppfunc, ...)
        local funcs = type(cppfunc) == "string" and {cppfunc} or cppfunc
        local function join(...)
            local BEFORES = {}
            local AFTERS = {}
            local CALLBACK_BEFORES = {}
            local CALLBACK_AFTERS = {}
            for _, v in ipairs({...}) do
                if v.BEFORE then
                    BEFORES[#BEFORES + 1] = format(v.BEFORE)
                end
                if v.AFTER then
                    AFTERS[#AFTERS + 1] = format(v.AFTER)
                end
                if v.CALLBACK_BEFORE then
                    CALLBACK_BEFORES[#CALLBACK_BEFORES + 1] = format(v.CALLBACK_BEFORE)
                end
                if v.CALLBACK_AFTER then
                    CALLBACK_AFTERS[#CALLBACK_AFTERS + 1] = format(v.CALLBACK_AFTER)
                end
            end
            return {
                BEFORE = #BEFORES > 0 and table.concat(BEFORES, '\n') or nil,
                AFTER = #AFTERS > 0 and table.concat(AFTERS, '\n') or nil,
                CALLBACK_BEFORE = #CALLBACK_BEFORES > 0 and table.concat(CALLBACK_BEFORES, '\n') or nil,
                CALLBACK_AFTER = #CALLBACK_AFTERS > 0 and table.concat(CALLBACK_AFTERS, '\n') or nil,
            }
        end
        local codes = join(...)
        local found
        local function doinject(fi, testname)
            if fi and (fi.CPPFUNC == cppfunc or (testname and fi.LUAFUNC == cppfunc))then
                found = true
                assert(not fi.INJECT.BEFORE or fi.INJECT.BEFORE == codes.BEFORE, 'already has inject before')
                assert(not fi.INJECT.AFTER or fi.INJECT.AFTER == codes.AFTER, 'already has inject after')
                assert(not fi.INJECT.CALLBACK_BEFORE or fi.INJECT.CALLBACK_BEFORE == codes.CALLBACK_BEFORE, 'already has inject callback before')
                assert(not fi.INJECT.CALLBACK_AFTER or fi.INJECT.CALLBACK_AFTER == codes.CALLBACK_AFTER, 'already has inject callback after')
                fi.INJECT.BEFORE = codes.BEFORE
                fi.INJECT.AFTER = codes.AFTER
                fi.INJECT.CALLBACK_BEFORE = codes.CALLBACK_BEFORE
                fi.INJECT.CALLBACK_AFTER = codes.CALLBACK_AFTER
            end
        end

        for _, v in ipairs(funcs) do
            cppfunc = v
            for _, arr in ipairs(cls.FUNCS) do
                for _, fi in ipairs(arr) do
                    doinject(fi)
                end
            end

            for _, pi in ipairs(cls.PROPS) do
                doinject(pi.GET)
                doinject(pi.SET)
            end

            for _, vi in ipairs(cls.VARS) do
                doinject(vi.GET, true)
                doinject(vi.SET, true)
            end
        end

        assert(found, 'func not found: ' .. cppfunc)
    end

    function cls.alias(func, aliasname)
        local funcs = {}
        for _, arr in ipairs(cls.FUNCS) do
            for _, fi in ipairs(arr) do
                if fi.LUAFUNC == func then
                    funcs[#funcs + 1] = setmetatable({LUAFUNC = assert(aliasname)}, {__index = fi})
                end
            end
            if #funcs > 0 then
                cls.FUNCS[#cls.FUNCS + 1] = funcs
                return
            end
        end

        error('func not found: ' .. func)
    end

    function cls.callback(opt)
        cls.FUNCS[#cls.FUNCS + 1] = parse_func(cls, nil, table.unpack(opt.FUNCS))
        for i, v in ipairs(cls.FUNCS[#cls.FUNCS]) do
            v.CALLBACK_OPT = opt
            v.CALLBACK_OPT = setmetatable({}, {__index = opt})
            if type(v.CALLBACK_OPT.TAG_MAKER) == 'table' then
                v.CALLBACK_OPT.TAG_MAKER = assert(v.CALLBACK_OPT.TAG_MAKER[i])
            end
            if type(v.CALLBACK_OPT.TAG_MODE) == 'table' then
                v.CALLBACK_OPT.TAG_MODE = assert(v.CALLBACK_OPT.TAG_MODE[i])
            end
        end
    end

    function cls.var(name, var_decl)
        local var_decl, readonly = string.gsub(var_decl, '@readonly', '')
        var_decl = string.gsub(var_decl, ';*$', '')
        local var_decl, static = string.gsub(var_decl, '^ *static *', '')
        local ARGS = parse_args(cls, '(' .. var_decl .. ')')
        local CALLBACK_OPT_GET
        local CALLBACK_OPT_SET
        name = name or ARGS[1].VARNAME
        if ARGS[1].CALLBACK.ARGS then
            CALLBACK_OPT_SET = {
                TAG_MAKER = 'olua_makecallbacktag("' .. name .. '")',
                TAG_MODE = 'OLUA_CALLBACK_TAG_REPLACE',
            }
            CALLBACK_OPT_GET = {
                TAG_MAKER = 'olua_makecallbacktag("' .. name .. '")',
                TAG_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
            }
        end
        cls.VARS[#cls.VARS + 1] = {
            VARNAME = assert(name),
            GET = {
                LUAFUNC = name,
                CPPFUNC = 'get_' .. ARGS[1].VARNAME,
                VARNAME = ARGS[1].VARNAME,
                INJECT = {},
                FUNC_DECL = '<function var>',
                RET = {
                    NUM = 1,
                    TYPE = ARGS[1].TYPE,
                    DECL_TYPE = ARGS[1].DECL_TYPE,
                    ATTR = {},
                },
                STATIC = static > 0,
                ISVAR = true,
                ARGS = {},
                INDEX = 0,
                CALLBACK_OPT = CALLBACK_OPT_GET,
            },
            SET = {
                LUAFUNC = name,
                CPPFUNC = 'set_' .. ARGS[1].VARNAME,
                VARNAME = ARGS[1].VARNAME,
                INJECT = {},
                STATIC = static > 0,
                FUNC_DECL = '<function var>',
                RET = {
                    NUM = 0,
                    TYPE = get_typeinfo('void', cls),
                    ATTR = {},
                },
                ISVAR = true,
                ARGS = ARGS,
                INDEX = 0,
                CALLBACK_OPT = CALLBACK_OPT_SET,
            },
        }

        if readonly > 0 then
            cls.VARS[#cls.VARS].SET = nil
        end
    end

    function cls.vars(vars_str)
        for line in string.gmatch(vars_str, '[^\n\r]+') do
            line = string.gsub(line, '^ *', '')
            if #line > 0 and not string.find(line, '^ *//') then
                cls.var(nil, line)
            end
        end
    end

    function cls.prop(name, func_get, func_set)
        assert(not string.find(name, '[^_%w]+'), '"' .. name .. '"')
        cls.PROPS[#cls.PROPS + 1] = parse_prop(cls, name, func_get, func_set)
    end

    function cls.props(props_str)
        for line in string.gmatch(props_str, '[^\n\r]+') do
            local name = string.match(line, '%w+')
            if name then
                cls.prop(name)
            end
        end
    end

    function cls.const(name, value)
        local tv = type(value)
        assert(not string.find(name, '[^_%w]+'), '"' .. name .. '"')
        assert(tv == "boolean" or tv == "number" or tv == "string", tv)
        cls.CONSTS[#cls.CONSTS + 1] = {
            CONST_NAME = assert(name),
            CONST_VALUE = value,
            CONST_TYPE = tv == "number" and (math.type(value)) or tv,
        }
    end

    function cls.enum(name, value, type)
        cls.ENUMS[#cls.ENUMS + 1] = {
            ENUM_NAME = name,
            ENUM_VALUE = value or (cls.CPPCLS .. '::' .. name),
            ENUM_TYPE = type,
        }
    end

    function cls.enums(enums_str)
        for line in string.gmatch(enums_str, '[^\n\r]+') do
            local name, value = string.match(line, '([^ ]+) *= *([^ ]+)')
            if not name then
                name = string.match(line, '[%w:_]+')
            elseif not string.find(value, cls.CPPCLS) then
                value = cls.CPPCLS .. '::' .. value
            end
            if name then
                cls.enum(name, value)
            end
        end
    end

    return cls
end

function olua.topath(cls)
    return string.gsub(cls.CPPCLS, '[.:]+', '_')
end

function olua.typedef(typeinfo)
    for n in string.gmatch(typeinfo.CPPCLS, '[^\n\r]+') do
        local typename = to_pretty_typename(n)
        local info = setmetatable({}, {__index = typeinfo})
        info.CPPCLS = typename
        info.DECL_TYPE = info.DECL_TYPE or typename
        typeinfo_map[typename] = info
        typeinfo_map['const ' .. typename] = info

        if info.INIT_VALUE ~= false then
            if not info.INIT_VALUE then
                if typename == 'bool' then
                    info.INIT_VALUE = 'false'
                elseif string.find(typename, '%*$') then
                    info.INIT_VALUE = 'nullptr'
                else
                    info.INIT_VALUE = '0'
                end
            end
        end

        if type(info.CONV_FUNC) == "function" then
            info.CONV_FUNC = info.CONV_FUNC(typename)
        end

        info.FUNC_PUSH_VALUE = string.gsub(info.CONV_FUNC, '[$]+', "push")
        info.FUNC_TO_VALUE = string.gsub(info.CONV_FUNC, '[$]+', "to")
        info.FUNC_CHECK_VALUE = string.gsub(info.CONV_FUNC, '[$]+', "check")
        info.FUNC_OPT_VALUE = string.gsub(info.CONV_FUNC, '[$]+', "opt")
        info.FUNC_IS_VALUE = string.gsub(info.CONV_FUNC, '[$]+', "is")
        -- multi ret
        info.FUNC_PACK_VALUE = string.gsub(info.CONV_FUNC, '[$]+', "pack")
        info.FUNC_UNPACK_VALUE = string.gsub(info.CONV_FUNC, '[$]+', "unpack")

        if info.VARS and info.VARS > 1 then
            info.FUNC_ISPACK_VALUE = string.gsub(info.CONV_FUNC, '[$]+', "ispack")
        end

        if info.LUACLS then
            if type(info.LUACLS) == "function" then
                info.LUACLS = info.LUACLS(typename)
            elseif type(info.LUACLS) ~= "string" then
                error("not support: " .. type(info.LUACLS))
            end
        end
    end
end

function olua.typeconv(ci)
    local func = ci.FUNC or "push|check|pack|unpack|opt|is"
    ci.PROPS = {}
    for line in string.gmatch(assert(ci.DEF, 'no DEF'), '[^\n\r]+') do
        local attr, line = parse_attr(line)

        local typename, attr, varname, default
        if line and #line > 0 then
            typename, attr, line = parse_def(line)
            varname, default = string.match(line, '^([^ ]+) *= *([^ ,;]*)')
            if not varname then
                varname = string.match(line, '^ *[^ ,;]+')
            end
        end
        if typename then
            typename = to_pretty_typename(typename)
            varname = to_pretty_typename(varname)
            local typeinfo, typename = get_typeinfo(typename)
            ci.PROPS[#ci.PROPS + 1] = {
                TYPE = typeinfo,
                VARNAME = varname,
                LUANAME = string.gsub(varname, '^_*', ''),
                DEFAULT = default,
                ATTR = attr,
            }
        end
    end

    ci.FUNC = {}
    for f in string.gmatch(func, '[^|]+') do
        ci.FUNC[string.upper(f)] = true
    end

    local ti = typeinfo_map[ci.CPPCLS] or typeinfo_map[ci.CPPCLS .. ' *']
    assert(ti, ci.CPPCLS)
    if ti.VARS and ti.VARS > 1 then
        ci.FUNC['ISPACK'] = true
    else
        ci.FUNC['UNPACK'] = nil
        ci.FUNC['PACK'] = nil
    end

    ci.FUNC.IS = true
    return ci
end

return olua