local type_info = {}

local function to_type(t)
    t = string.gsub(t, '^[ ]*', '')
    t = string.gsub(t, '[ ]*$', '')
    t = string.gsub(t, '[ ]+', ' ')
    return t
end

function get_type_info(t)
    t = string.gsub(t, '[ ]*%*', '*')
    t = string.gsub(t, '[ ]*[&]+', '')
    t = string.gsub(t, '[ ]*$', '')

    return type_info[t]
end

local function parse_ret(rt)
    local static = false
    if string.find(rt, 'static') then
        static = true
        rt = string.gsub(rt, 'static', '')
    end

    rt = to_type(rt)

    if not get_type_info(rt) then
        error(string.format("not support type: %s", rt))
    end

    return static, rt
end

local function parse_args(func_decl)
    local args = {}
    local args_str = string.match(func_decl, '%(([^()]*)%)')

    for arg in string.gmatch(args_str, '[^,]+') do
        arg = to_type(arg)
        if arg ~= 'void' then
            local t = string.match(arg, '(.+[ *&])')
            local t, n, d = string.match(arg, '(.+[ *&])([^ *&]+) *= *([^ ]*)')
            if not t then
                if string.find(arg, '[&*]$') then
                    t = arg
                else
                    t, n = string.match(arg, '(.+[ *&])([^ *&]+)')
                end
            end
            assert(t, arg)
            t = string.gsub(t, '[ ]*$', '')
            args[#args + 1] = {
                TYPE = assert(get_type_info(t), t),
                DECL_TYPE = string.gsub(t, '[ &]*$', ''),
                VALUE = d,
            }
        end
    end

    return args
end

local function parse_func(name, func_decl)
    local fi = {RETURN = {}}

    if string.find(func_decl, '{') then
        fi.NAME = assert(name)
        fi.FUNC = name
        fi.FUNC_SNIPPET = func_decl
        fi.RETURN.NUM = 0
        fi.RETURN.TYPE = get_type_info('void')
        fi.ARGS = {}
    else
        local rt, func = string.match(func_decl, "([^()]+[ *&])([^ ]+)[ ]*%(")
        local static, rt = parse_ret(rt)

        fi.NAME = name or func
        fi.FUNC = func
        fi.STATIC = static
        fi.RETURN.NUM = rt == "void" and 0 or 1
        fi.RETURN.TYPE = get_type_info(rt)
        fi.RETURN.DECL_TYPE = string.gsub(rt, '[ &]*$', '')
        fi.ARGS = parse_args(func_decl)
    end

    return fi
end

local function parse_prop(name, func_get, func_set)
    local pi = {}
    pi.NAME = assert(name)
    pi.GET = func_get and parse_func(name, func_get) or nil
    pi.SET = func_set and parse_func(name, func_set) or nil
    assert(pi.GET.RETURN.NUM > 0, func_get)
    return pi
end

function class(module)
    local cls = {}
    cls.FUNCS = {}
    cls.CONSTS = {}
    cls.PROPS = {}

    function cls.func(name, func_decl)
        cls.FUNCS[#cls.FUNCS + 1] = parse_func(name, func_decl)
    end

    function cls.prop(name, func_get, func_set)
        cls.PROPS[#cls.PROPS + 1] = parse_prop(name, func_get, func_set)
    end

    function cls.const(name, value)
        local tv = type(value)
        assert(tv == "boolean" or tv == "number" or tv == "string", tv)
        cls.CONSTS[#cls.CONSTS + 1] = {
            NAME = assert(name),
            VALUE = value,
            TYPE = tv == "number" and (math.type(value)) or tv,
        }
    end

    module.CLASSES[#module.CLASSES + 1] = cls

    return cls
end

function class_path(classname)
    return string.gsub(classname, '%.', '_')
end

function stringfy(value)
    if value then
        return '"' .. tostring(value) .. '"'
    else
        return nil
    end
end

function register_type(option)
    for n in string.gmatch(option.NAME, '[^|]+') do
        local type_name = string.gsub(n, '[ ]*%*', '*')
        local info = setmetatable({}, {__index = option})
        info.NAME = type_name
        type_info[type_name] = info
        type_info['const ' .. type_name] = info

        info.PUSH = string.gsub(info.CONV, '$ACTION', "push")
        info.TO = string.gsub(info.CONV, '$ACTION', "to")
        info.OPT = string.gsub(info.CONV, '$ACTION', "opt")

        if info.CLASS then
            if type(info.CLASS) == "function" then
                info.CLASS = info.CLASS(type_name)
            elseif type(info.CLASS) ~= "string" then
                error("not support: " .. type(info.CLASS))
            end
        end
    end
end