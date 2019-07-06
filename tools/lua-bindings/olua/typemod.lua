local function createCommand(func)
    return setmetatable({}, {__call = func})
end

local function class(cls)
    cls.ATTR = createCommand(function (_, name, attr)
        cls.ATTR[name] = attr
    end)
    cls.ALIAS = createCommand(function (_, name, alias)
        cls.ALIAS[#cls.ALIAS + 1] = {NAME = name, ALIAS = alias}
    end)
    cls.EXCLUDE = createCommand(function (_, func)
        cls.EXCLUDE[func] = true
    end)
    cls.FUNC = createCommand(function (_, func, snippet)
        cls.EXCLUDE[func] = true
        cls.FUNC[#cls.FUNC + 1] = {FUNC = func, SNIPPET = snippet}
    end)
    cls.CALLBACK = createCommand(function (_, func, opt)
        assert(#func > 0, 'no callback function name')
        cls.EXCLUDE[func] = true
        opt.NAME = func
        cls.CALLBACK[#cls.CALLBACK + 1] = opt
    end)
    cls.PROP = createCommand(function (_, name, get, set)
        cls.PROP[#cls.PROP + 1] = {NAME = name, GET = get, SET = set}
    end)
    cls.VAR = createCommand(function (_, name, snippet)
        cls.EXCLUDE[name] = true
        cls.VAR[#cls.VAR + 1] = {NAME = name, SNIPPET = snippet}
    end)
    cls.ENUM = createCommand(function (_, name, value)
        cls.ENUM[#cls.ENUM + 1] = {NAME = name, VALUE = value}
    end)
    cls.INJECT = createCommand(function (_, names, codes)
        cls.INJECT[#cls.INJECT + 1] = {NAMES = names, CODES = codes}
    end)
    return cls
end

function typemod(name)
    local module = {
        CLASSES = {},
        CONVS = {},
        EXCLUDE_TYPE = {},
        TYPEDEFS = {},
        NAME = name,
        EXCLUDE_PATTERN = function () end
    }

    function module.typeconf(name)
        local cls = {
            NAME = name,
            EXCLUDE_PATTERN = function () end
        }
        module.CLASSES[#module.CLASSES + 1] = cls
        return class(cls)
    end

    function module.typedef(info)
        module.TYPEDEFS[#module.TYPEDEFS + 1] = info
    end

    function module.include(path)
        loadfile(path)(module)
    end

    module.EXCLUDE_TYPE = createCommand(function (_, tn)
        module.EXCLUDE_TYPE[tn] = true
    end)

    function module.typeconv(info)
        module.CONVS[#module.CONVS + 1] = {
            CPPCLS = assert(info.CPPCLS),
            DEF = format(assert(info.DEF)),
        }
    end

    return module
end