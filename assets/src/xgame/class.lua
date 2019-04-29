local type = type
local rawset = rawset
local setmetatable = setmetatable

local tracecount = 0
local tracebacks = setmetatable({}, {__mode = "k"})

local function class(classname, super)
    local cls = {}

    cls.classname = classname
    cls.class = cls
    cls.Get = {}
    cls.Set = {}
    
    local Get = cls.Get
    local Set = cls.Set

    if super then
        -- copy super method 
        for key, value in pairs(super) do
            if type(value) == "function" and key ~= "ctor" then
                cls[key] = value
            end
        end

        -- copy super getter
        for key, value in pairs(super.Get) do
            Get[key] = value
        end
        
        -- copy super setter
        for key, value in pairs(super.Set) do
            Set[key] = value
        end
        
        cls.super = super
    end

    function cls.__index(self, key)
        local func = cls[key]
        if func then
           return func
        end

        local getter = Get[key]
        if getter then
            return getter(self)
        end

        return nil
    end

    function cls.__newindex(self, key, value)
        local setter = Set[key]
        if setter then
            setter(self, value)
            return
        end

        if Get[key] then
            error(string.format("readonly property: %s", key))
        end
        
        rawset(self, key, value)
    end

    function cls.new(...)
        local self = setmetatable({}, cls)
        local function create(cls, ...)
            if cls.super then
                create(cls.super, ...)
            end
            if cls.ctor then
                cls.ctor(self, ...)
            end
        end
        create(cls, ...)
        
        -- debug
        tracecount = tracecount + 1
        tracebacks[self] = tracecount

        return self
    end

    return cls
end

return class
