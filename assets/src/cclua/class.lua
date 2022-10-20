local type = type
local rawset = rawset
local setmetatable = setmetatable
local assert = assert

local tracecount = 0
local tracebacks = setmetatable({}, {__mode = "k"})

local function cppclass(classname, super)
    local cls = olua.class(classname, super)

    cls.Get = cls.class['.get']
    cls.Set = cls.class['.set']
    cls.ctor = false

    function cls.new(...)
        assert(olua.iscfunc(super.create), "super.create expect c function")
        local self = super.create()
        olua.setmetatable(self, classname)
        local function create(c, ...)
            if c.super then
                create(c.super, ...)
            end
            if c.ctor then
                c.ctor(self, ...)
            end
        end
        create(cls, ...)

        -- debug
        if DEBUG then
            tracecount = tracecount + 1
            tracebacks[self] = tracecount
        end

        return self
    end

    return cls
end

local metamethod = {
    __gc = true, __pairs = true, __len = true, __eq = true, __tostring = true,
    __add = true, __sub = true, __mul = true, __mod = true, __pow = true,
    __div = true, __idiv = true,
    __band = true, __bor = true, __bxor = true, __shl = true, __shr = true,
    __unm = true, __bnot = true, __lt = true, __le = true,
    __concat = true, __call = true, __close = true
}

local function luaclass(classname, super)
    local classagent = {}
    local cls = {}
    local sets = {}
    local gets = {}
    local funcs = {ctor = false}

    do -- const value
        local function const(k, v)
            cls[k] = v
            gets[k] = function ()
                return v
            end
            sets[k] = function ()
                error(string.format('readonly property: %s', k))
            end
        end

        const('classtype', 'lua')
        const('class', cls)
        const('classname', classname)
        const('classagent', classagent)
        const('super', super)
    end

    if super then
        for k in pairs(metamethod) do
            cls[k] = super.class[k]
        end

        local function index_super(t, st)
            setmetatable(t, {__index = function(_, k)
                local v = st[k]
                if v ~= nil then
                    t[k] = v -- cache
                    return v
                end
            end})
        end
        index_super(gets, super.Get)
        index_super(sets, super.Set)
        index_super(funcs, super.Func)
    end

    function cls:__tostring()
        setmetatable(self, nil)
        local s = tostring(self):gsub('^table', classname)
        setmetatable(self, cls)
        return s
    end

    function cls:__index(k)
        local func = funcs[k]
        if func then
            return func
        end

        local getter = gets[k]
        if getter then
            return getter(self)
        end

        local index = funcs.__index
        if index then
            return index(self, k)
        end
    end

    function cls:__newindex(k, v)
        local setter = sets[k]
        if setter then
            setter(self, v)
            return
        end

        local newindex = funcs.__newindex or rawset
        newindex(self, k, v)
    end

    function funcs.new(...)
        local self = setmetatable({}, cls)
        local function create(c, ...)
            if c.super then
                create(c.super, ...)
            end
            if c.ctor then
                c.ctor(self, ...)
            end
        end
        create(classagent, ...)

        -- debug
        if DEBUG then
            tracecount = tracecount + 1
            tracebacks[self] = tracecount
        end

        return self
    end

    local default = {Get = gets, Set = sets, Func = funcs}

    return setmetatable(classagent, {
        __index = function (t, k)
            local func = funcs[k]
            if func then
                return func
            end

            local getter = gets[k]
            if getter then
                return getter(t)
            end

            return default[k]
        end,
        __newindex = function (t, k, v)
            local setter = sets[k]
            if setter then
                setter(t, v)
                return
            end

            if metamethod[k] then
                cls[k] = v
            else
                funcs[k] = v
            end
        end,
    })
end

local function class(classname, super)
    if type(super) == 'table' and super.classtype == 'native' then
        return cppclass(classname, super)
    else
        return luaclass(classname, super)
    end
end

return class
