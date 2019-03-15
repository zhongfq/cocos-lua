local typeinfo_map = {}

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

function get_typeinfo(typename, cls)
    local typename = to_pretty_typename(typename)
    local typeinfo
    local subtypeinfo, subtypename -- for typename<T>

    if string.find(typename, '<') then
        subtypename = string.match(typename, '<(.*)>')
        subtypeinfo, subtypename = get_typeinfo(subtypename, cls)
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
                return ns .. s
            end)
            tn = to_real_typename(tn)
            return typeinfo_map[tn], tn
        end

        local ti, tn = try_namespace(string.gsub(cls.CPPCLS, '[^:]+$', ''), typename)
        if not ti then
            ti, tn = try_namespace(cls.CPPCLS .. '::', typename)
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

    if not typeinfo then
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

local function paser_attr(arg)
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
                attr[string.upper(opt)] = true
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
    local attr, str = paser_attr(str)
    local typename = string.match(str, '^[^<>(),]*%b<>[ &*]*')
    if not typename then
        local from, to
        while true do
            from, to = string.find(str, ' *[^ (),]+[ &*]*', to)
            if not from then
                break
            end
            typename = string.sub(str, from, to)
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
        RET = get_typeinfo(rt),
        RET_ATTR = rt_attr,
        ARGS_DECL = cb_args_decl,
    }
end

function parse_args(cls, args_str)
    local args = {}
    args_str = string.match(args_str, '%((.*)%)')

    while #args_str > 0 do
        local typename, attr, varname, default
        typename, attr, args_str = parse_def(args_str)
        if typename == 'void' then
            return args
        end

        varname, default = string.match(args_str, '^([^ ]+) *= *([^ ,]*)')
        if not varname then
            varname = string.match(args_str, '^ *[^ ,]+')
        end

        args_str = string.gsub(args_str, '^[^,]*,? *', '')

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
    end

    return args
end

local function parse_func(cls, name, ...)
    local arr = {MAX_ARGS = 0}
    local is_static_func
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
        else
            local typename, attr, str = parse_def(func_decl)
            fi.CPPFUNC = string.match(str, '[^ ()]+')
            fi.LUAFUNC = name or fi.CPPFUNC
            fi.STATIC = attr.STATIC
            fi.FUNC_DECL = func_decl
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
                fi.RET.NUM = fi.RET.TYPE.TYPENAME == "void" and 0 or 1
                fi.RET.DECL_TYPE = to_decl_type(cls, typename, false, true)
                fi.RET.ATTR = attr
            end
            fi.ARGS = parse_args(cls, string.sub(str, #fi.CPPFUNC + 1))

            if is_static_func == nil then
                is_static_func = fi.STATIC
            else
                assert(is_static_func == fi.STATIC, func_decl)
            end
        end
        assert(not string.find(fi.LUAFUNC, '[^_%w]+'), '"' .. fi.LUAFUNC .. '"')
        fi.INDEX = i
        arr[#arr + 1] = fi
        arr.MAX_ARGS = math.max(arr.MAX_ARGS, #fi.ARGS)
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

    if func_get then
        pi.GET = func_get and parse_func(cls, name, func_get)[1] or nil
    else
        for _, v in ipairs(cls.FUNCS) do
            for _, f in ipairs(v) do
                if to_prop_func_name(name, 'get') == f.CPPFUNC or
                    to_prop_func_name(name, 'is') == f.CPPFUNC then
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
                if to_prop_func_name(name, 'set') == f.CPPFUNC then
                    assert(#f.ARGS == 1, f.CPPFUNC)
                    pi.SET = f
                end
            end
        end
    end
    
    assert(pi.GET.RET.NUM > 0, func_get)
    return pi
end

function class(collection)
    local cls = {}
    cls.FUNCS = {}
    cls.CONSTS = {}
    cls.ENUMS = {}
    cls.PROPS = {}
    cls.VARS = {}
    cls.REG_LUATYPE = true

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
            if not string.find(func_decl, '^ *//') then
                local _, str = paser_attr(func_decl)
                local fn = string.match(str, '([^ ]+)%(')
                local t = dict[fn]
                if not t then
                    t = {}
                    arr[#arr + 1] = t
                    dict[fn] = t
                end
                t[#t + 1] = string.gsub(func_decl, '^ *', '')
            end
        end
        for _, v in ipairs(arr) do
            cls.func(nil, table.unpack(v))
        end
    end

    function cls.callback(name, opt, ...)
        cls.FUNCS[#cls.FUNCS + 1] = parse_func(cls, name, ...)
        for i, v in ipairs(cls.FUNCS[#cls.FUNCS]) do
            v.CALLBACK_OPT = assert(opt)
            if type(v.CALLBACK_OPT.CALLBACK_MAKER) == 'table' then
                v.CALLBACK_OPT = setmetatable({
                    CALLBACK_MAKER = assert(v.CALLBACK_OPT.CALLBACK_MAKER[i])
                }, {__index = v.CALLBACK_OPT})
            end
        end
    end

    function cls.var(name, var_decl)
        local ARGS = parse_args(cls, '(' .. var_decl .. ')')
        local CALLBACK_OPT
        name = name or ARGS[1].VARNAME
        if ARGS[1].CALLBACK.ARGS then
            CALLBACK_OPT = {
                CALLBACK_MAKER = 'olua_makecallbacktag("' .. name .. '")',
                CALLBACK_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
                CALLBACK_REPLACE = true,
            }
        end
        cls.VARS[#cls.VARS + 1] = {
            VARNAME = assert(name),
            GET = {
                LUAFUNC = name,
                CPPFUNC = 'get_' .. ARGS[1].VARNAME,
                VARNAME = ARGS[1].VARNAME,
                FUNC_DECL = '<function var>',
                RET = {
                    NUM = 1,
                    TYPE = ARGS[1].TYPE,
                    DECL_TYPE = ARGS[1].DECL_TYPE,
                    ATTR = {},
                },
                ISVAR = true,
                ARGS = {},
                INDEX = 0,
                CALLBACK_OPT = CALLBACK_OPT,
            },
            SET = {
                LUAFUNC = name,
                CPPFUNC = 'set_' .. ARGS[1].VARNAME,
                VARNAME = ARGS[1].VARNAME,
                FUNC_DECL = '<function var>',
                RET = {
                    NUM = 0,
                    TYPE = get_typeinfo('void', cls),
                    ATTR = {},
                },
                ISVAR = true,
                ARGS = ARGS,
                INDEX = 0,
                CALLBACK_OPT = CALLBACK_OPT,
            },
        }
    end

    function cls.prop(name, func_get, func_set)
        assert(not string.find(name, '[^_%w]+'), '"' .. name .. '"')
        cls.PROPS[#cls.PROPS + 1] = parse_prop(cls, name, func_get, func_set)
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

    return cls
end

function include(file)
    local value = dofile(file)
    assert(type(value) == "table", file)
    return value
end

function merge(t, file)
    local ret = include(file)
    if #ret > 0 then
        for _, v in ipairs(include(file)) do
            t[#t + 1] = v
        end
    else
        t[#t + 1] = ret
    end
end

function class_path(classname)
    return string.gsub(classname, '[.:]+', '_')
end

function stringfy(value)
    if value then
        return '"' .. tostring(value) .. '"'
    else
        return nil
    end
end

function REG_TYPE(typeinfo)
    for n in string.gmatch(typeinfo.TYPENAME, '[^|]+') do
        local typename = to_pretty_typename(n)
        local info = setmetatable({}, {__index = typeinfo})
        info.TYPENAME = typename
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

        info.FUNC_PUSH_VALUE = string.gsub(info.CONV_FUNC, '[$]+', "push")
        info.FUNC_TO_VALUE = string.gsub(info.CONV_FUNC, '[$]+', "to")
        info.FUNC_CHECK_VALUE = string.gsub(info.CONV_FUNC, '[$]+', "check")
        info.FUNC_OPT_VALUE = string.gsub(info.CONV_FUNC, '[$]+', "opt")
        info.FUNC_IS_VALUE = string.gsub(info.CONV_FUNC, '[$]+', "is")
        -- multi ret
        info.FUNC_PACK_VALUE = string.gsub(info.CONV_FUNC, '[$]+', "pack")
        info.FUNC_UNPACK_VALUE = string.gsub(info.CONV_FUNC, '[$]+', "unpack")

        if info.LUACLS then
            if type(info.LUACLS) == "function" then
                info.LUACLS = info.LUACLS(typename)
            elseif type(info.LUACLS) ~= "string" then
                error("not support: " .. type(info.LUACLS))
            end
        end
    end
end

function REG_CONV(ci)
    ci.PROPS = {}
    for line in string.gmatch(assert(ci.DEF, 'no DEF'), '[^\n\r]+') do
        local typename, varname, luaname = string.match(line, '([^{} ]+[ *&])([^ *&]+) *= *([^ ;]*)')
        if not typename then
            typename, varname = string.match(line, '([^{} ]+[ *&])([^ *&;]+)')
        end
        if typename then
            typename = to_pretty_typename(typename)
            varname = to_pretty_typename(varname)
            luaname = to_pretty_typename(luaname or varname)
            local typeinfo, typename = get_typeinfo(typename)
            ci.PROPS[#ci.PROPS + 1] = {
                TYPE = typeinfo,
                VARNAME = varname,
                LUANAME = luaname,
            }
        end
    end
    return ci
end
