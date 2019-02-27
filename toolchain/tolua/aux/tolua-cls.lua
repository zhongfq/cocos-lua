local arg_type = {}

local function to_type(t)
    t = string.gsub(t, '^[ ]*', '')
    t = string.gsub(t, '[ ]*$', '')
    t = string.gsub(t, '[ ]+', ' ')
    return t
end

local function get_type_info(t)
    t = string.gsub(t, '[ ]*%*', '*')
    t = string.gsub(t, '[ ]*[&]+', '')

    return arg_type[t]
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
            local arg_type = string.match(arg, '(.+[ *&])')
            assert(arg_type, arg)
            args[#args + 1] = {
                TYPE = assert(get_type_info(arg_type), arg_type),
                DECL_TYPE = arg_type,
            }
        end
    end

    return args
end

local function parse_func(name, func_decl)
    local fi = {RETURN = {}}

    local rt, func = string.match(func_decl, "(.+[ *&])([^ ]+)[ ]*%(")
    local static, rt = parse_ret(rt)

    fi.NAME = name or func
    fi.FUNC = func
    fi.STATIC = static
    fi.RETURN.NUM = rt == "void" and 0 or 1
    fi.RETURN.TYPE = get_type_info(rt)
    fi.RETURN.DECL_TYPE = rt
    fi.ARGS = parse_args(func_decl)

    return fi
end

function register_type(type_name, option)
    type_name = string.gsub(type_name, '[ ]*%*', '*')
    option = option or {}
    assert(not option.TYPE_NAME)
    option.NAME = type_name
    arg_type[type_name] = option
    arg_type['const ' .. type_name] = option

    if not option.PUSH then
        if type_name == "bool" then
            option.PUSH = 'xluacv_push_bool'
            option.TO = 'xluacv_to_bool'
        end
        if type_name == "std::string" then
            option.PUSH = 'xluacv_push_std_string'
            option.TO = 'xluacv_to_std_string'
        end
    end
end

function class(module)
    local cls = {}
    cls.FUNCS = {}
    cls.CONSTS = {}
    cls.PROPERTIES = {}

    function cls.func(name, func_decl)
        cls.FUNCS[#cls.FUNCS + 1] = parse_func(name, func_decl)
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