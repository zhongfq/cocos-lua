local type_info_map = {}

local function trim_redundance_space(t)
    -- t = '   const    type   *   '
    t = string.gsub(t, '^[ ]*', '') -- t = 'const    type   *   '
    t = string.gsub(t, '[ ]*$', '') -- t = 'const    type   *'
    t = string.gsub(t, '[ ]+', ' ') -- t = 'const type *'
    return t
end

function get_type_info(t)
    t = string.gsub(t, '[ ]*%*', '*')
    t = string.gsub(t, '[ ]*[&]+', '')
    t = string.gsub(t, '[ ]*$', '')

    return assert(type_info_map[t], t)
end

local function parse_ret(rt)
    local static = false
    if string.find(rt, 'static') then
        static = true
        rt = string.gsub(rt, 'static', '')
    end

    rt = trim_redundance_space(rt)

    get_type_info(rt)

    return static, rt
end

local function parse_args(func_decl)
    local args = {}
    local args_str = string.match(func_decl, '%(([^()]*)%)')

    for arg in string.gmatch(args_str, '[^,]+') do
        arg = trim_redundance_space(arg)
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
                TYPE = get_type_info(t),
                DECL_TYPE = string.gsub(t, '[ &]*$', ''),
                VALUE = d,
            }
        end
    end

    return args
end

local function parse_func(name, ...)
    local arr = {MAX_ARGS = 0}

    local is_static_func

    for i, func_decl in ipairs({...}) do
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

            if is_static_func == nil then
                is_static_func = static
            else
                assert(is_static_func == static, func_decl)
            end
        end
        fi.INDEX = i
        arr[#arr + 1] = fi
        arr.MAX_ARGS = math.max(arr.MAX_ARGS, #fi.ARGS)
    end

    return arr
end

local function parse_prop(name, func_get, func_set)
    local pi = {}
    pi.NAME = assert(name)
    pi.GET = func_get and parse_func(name, func_get)[1] or nil
    pi.SET = func_set and parse_func(name, func_set)[1] or nil
    assert(pi.GET.RETURN.NUM > 0, func_get)
    return pi
end

function class()
    local cls = {}
    cls.FUNCS = {}
    cls.CONSTS = {}
    cls.PROPS = {}

    function cls.func(name, ...)
        cls.FUNCS[#cls.FUNCS + 1] = parse_func(name, ...)
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

    return cls
end

function include(file)
    local value = dofile(file)
    assert(type(value) == "table", file)
    return value
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

function REG_TYPE(option)
    for n in string.gmatch(option.NAME, '[^|]+') do
        local type_name = string.gsub(n, '[ ]*%*', '*')
        local info = setmetatable({}, {__index = option})
        info.NAME = type_name
        type_info_map[type_name] = info
        type_info_map['const ' .. type_name] = info

        info.FUNC_PUSH_VALUE = string.gsub(info.CONV, '$ACTION', "push")
        info.FUNC_TO_VALUE = string.gsub(info.CONV, '$ACTION', "to")
        info.FUNC_OPT_VALUE = string.gsub(info.CONV, '$ACTION', "opt")
        info.FUNC_IS_VALUE = string.gsub(info.CONV, '$ACTION', "is")

        if info.LUACLS then
            if type(info.LUACLS) == "function" then
                info.LUACLS = info.LUACLS(type_name)
            elseif type(info.LUACLS) ~= "string" then
                error("not support: " .. type(info.LUACLS))
            end
        end
    end
end