local olua = require "olua"

local function command(func)
    return setmetatable({}, {__call = func})
end

local function addcmd(cls)
    cls.ATTR = command(function (_, name, attr)
        cls.ATTR[name] = attr
    end)
    cls.ALIAS = command(function (_, name, alias)
        cls.ALIAS[#cls.ALIAS + 1] = {NAME = name, ALIAS = alias}
    end)
    cls.EXCLUDE = command(function (_, func)
        cls.EXCLUDE[func] = true
    end)
    cls.FUNC = command(function (_, func, snippet)
        cls.EXCLUDE[func] = true
        cls.FUNC[#cls.FUNC + 1] = {FUNC = func, SNIPPET = snippet}
    end)
    cls.CALLBACK = command(function (_, opt)
        local func = olua.funcname(opt.FUNCS[1])
        assert(#func > 0, 'no callback function name')
        cls.EXCLUDE[func] = true
        opt.NAME = func
        cls.CALLBACK[#cls.CALLBACK + 1] = opt
    end)
    cls.PROP = command(function (_, name, get, set)
        cls.PROP[#cls.PROP + 1] = {NAME = name, GET = get, SET = set}
    end)
    cls.VAR = command(function (_, name, snippet)
        local varname = olua.funcname(snippet)
        assert(#varname > 0, 'no variable name')
        cls.EXCLUDE[varname] = true
        cls.VAR[#cls.VAR + 1] = {NAME = name, SNIPPET = snippet}
    end)
    cls.ENUM = command(function (_, name, value)
        cls.ENUM[#cls.ENUM + 1] = {NAME = name, VALUE = value}
    end)
    cls.INJECT = command(function (_, names, codes)
        cls.INJECT[#cls.INJECT + 1] = {NAMES = names, CODES = codes}
    end)
    return cls
end

-- function typemod
return function (name)
    local module = {
        CLASSES = {},
        CONVS = {},
        EXCLUDE_TYPE = {},
        TYPEDEFS = {},
        NAME = name,
        EXCLUDE_PATTERN = function () end
    }

    module.EXCLUDE_TYPE = command(function (_, tn)
        module.EXCLUDE_TYPE[tn] = true
    end)

    function module.include(path)
        loadfile(path)(module)
    end

    function module.typeconf(name)
        local cls = {
            CPPCLS = name,
        }
        module.CLASSES[#module.CLASSES + 1] = cls
        return addcmd(cls)
    end

    function module.typedef(info)
        module.TYPEDEFS[#module.TYPEDEFS + 1] = info
    end

    function module.typeconv(info)
        module.CONVS[#module.CONVS + 1] = {
            CPPCLS = assert(info.CPPCLS),
            DEF = olua.format(assert(info.DEF)),
            FUNC = info.FUNC,
        }
    end

    return module
end