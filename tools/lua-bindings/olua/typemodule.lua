local function class(cls)
    cls.ATTR = setmetatable({}, {__call = function (_, name, attr)
        cls.ATTR[name] = attr
    end})
    cls.EXCLUDE = setmetatable({}, {__call = function (_, func)
        cls.EXCLUDE[func] = true
    end})
    cls.FUNC = setmetatable({}, {__call = function (_, func, snippet)
        cls.EXCLUDE[func] = true
        cls.FUNC[#cls.FUNC + 1] = {FUNC = func, SNIPPET = snippet}
    end})
    cls.CALLBACK = setmetatable({}, {__call = function (_, func, opt)
        cls.EXCLUDE[func] = true
        opt.NAME = func
        cls.CALLBACK[#cls.CALLBACK + 1] = opt
    end})
    cls.PROP = setmetatable({}, {__call = function (_, name, get, set)
        cls.PROP[#cls.PROP + 1] = {NAME = name, GET = get, SET = set}
    end})
    cls.VAR = setmetatable({}, {__call = function (_, name, snippet)
        cls.EXCLUDE[name] = true
        cls.VAR[#cls.VAR + 1] = {NAME = name, SNIPPET = snippet}
    end})
    cls.ENUM = setmetatable({}, {__call = function (_, name, value)
        cls.ENUM[#cls.ENUM + 1] = {NAME = name, VALUE = value}
    end})
    cls.INJECT = setmetatable({}, {__call = function (_, names, codes)
        cls.INJECT[#cls.INJECT + 1] = {NAMES = names, CODES = codes}
    end})
    return cls
end

function typemodule(name)
    local module = {
        CLASSES = {},
        EXCLUDE_TYPE = {},
        NAME = name,
    }

    function module.typeconf(name)
        local cls = {
            NAME = name,
            EXCLUDE_PATTERN = function () end
        }
        module.CLASSES[#module.CLASSES + 1] = cls
        return class(cls)
    end

    module.EXCLUDE_TYPE = setmetatable({}, {__call = function (_, tn)
        module.EXCLUDE_TYPE[tn] = true
    end})

    return module
end