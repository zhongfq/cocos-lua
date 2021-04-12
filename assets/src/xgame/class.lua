local type = type
local rawset = rawset
local setmetatable = setmetatable
local assert = assert

local tracecount = 0
local tracebacks = setmetatable({}, {__mode = "k"})

local function cppclass(classname, super)
    local olua = require "olua"
    local cls = olua.class(classname, super)

    cls.Get = cls.class['.get']
    cls.Set = cls.class['.set']
    cls.ctor = false

    function cls.new(...)
        assert(olua.iscfunc(super.create), "super.create expect c function")
        local self = super.create()
        olua.setmetatable(self, classname)
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

local function luaclass(classname, super)
    local cls = {}

    cls.classname = classname
    cls.class = cls
    cls.classtype = 'lua'
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

local function class(classname, super)
    if type(super) == 'table' and super.classtype == 'native' then
        return cppclass(classname, super)
    else
        return luaclass(classname, super)
    end
end

return class
