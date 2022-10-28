local rawset = rawset
local setmetatable = setmetatable
local assert = assert

local tracecount = 0
local tracebacks = setmetatable({}, {__mode = "k"})

local function cppclass(classname, super)
    local cls = olua.class(classname, super)

    cls.Get = cls['.get']
    cls.Set = cls['.set']
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

local classmap = setmetatable({}, {__mode = 'k'})

local function luaclass(classname, super)
    local cls = {}
    local metaclass = {}
    local sets = {}
    local gets = {}
    local funcs = {ctor = false}

    classmap[cls] = {
        sets = sets,
        gets = gets,
        funcs = funcs,
        metaclass = metaclass,
    }

    do -- const value
        local function const(k, v)
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
        const('super', super)
        const('Get', gets)
        const('Set', sets)
    end

    if super then
        for k in pairs(metamethod) do
            metaclass[k] = classmap[super].metaclass[k]
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
        index_super(gets, classmap[super].gets)
        index_super(sets, classmap[super].sets)
        index_super(funcs, classmap[super].funcs)
    end

    function metaclass:__tostring()
        if self == cls then
            return 'class ' .. classname
        else
            setmetatable(self, nil)
            local s = tostring(self):gsub('^table', classname)
            setmetatable(self, metaclass)
            return s
        end
    end

    function metaclass:__index(k)
        local func = funcs[k]
        if func then
            return func
        end

        local getter = gets[k]
        if getter then
            return getter(self)
        end

        if self ~= cls then
            local index = funcs.__index
            if index then
                return index(self, k)
            end
        end
    end

    function metaclass:__newindex(k, v)
        local setter = sets[k]
        if setter then
            setter(self, v)
            return
        end

        if self ~= cls then
            local newindex = funcs.__newindex or rawset
            newindex(self, k, v)
        elseif metamethod[k] then
            metaclass[k] = v
        else
            funcs[k] = v
        end
    end

    function funcs.construct(obj, ...)
        setmetatable(obj, metaclass)
        local function create(c, ...)
            if c.super then
                create(c.super, ...)
            end
            if c.ctor then
                c.ctor(obj, ...)
            end
        end
        create(cls, ...)
        return obj
    end

    function funcs.new(...)
        local self = funcs.construct({}, ...)
        -- debug
        if DEBUG then
            tracecount = tracecount + 1
            tracebacks[self] = tracecount
        end
        return self
    end

    return setmetatable(cls, metaclass)
end

local function class(classname, super)
    local classtype
    if super then
        classtype = super.classtype
        assert(classtype == 'native' or classtype == 'lua', classtype)
    end
    if classtype == 'native' then
        return cppclass(classname, super)
    else
        return luaclass(classname, super)
    end
end

return class
