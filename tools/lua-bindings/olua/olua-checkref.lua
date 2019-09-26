local olua = require "olua.olua-io"

local function checkFunc(cls, fn, refmap)
    if not fn.STATIC and refmap[fn.RET.TYPE.CPPCLS] then
        if not (fn.RET.ATTR.UNREF or fn.RET.ATTR.REF) then
            print('not specify ref: ' .. cls.CPPCLS .. ' => ' .. fn.DECLFUNC)
        end
    end
end

local function checkClass(cls, refmap)
    for _, fns in ipairs(cls.FUNCS) do
        for _, fn in ipairs(fns) do
            checkFunc(cls, fn, refmap)
        end
    end
end

local function checkShouldRef(cls, refmap, classmap)
    if cls then
        local NAME = cls.CPPCLS .. ' *'
        if refmap[NAME] == nil then
            if cls.SUPERCLS and checkShouldRef(classmap[cls.SUPERCLS], refmap, classmap) then
                refmap[NAME] = true
                return true
            end
        elseif refmap[NAME] then
            return true
        end
    end
end

function olua.checkref(conf)
    local classmap = olua.classmap()
    local refmap = {}
    for _, v in ipairs(conf.REF) do
        refmap[v] = true
    end
    for _, cls in pairs(classmap) do
        checkShouldRef(cls, refmap, classmap)
    end
    for _, cls in pairs(classmap) do
        checkClass(cls, refmap)
    end
end

return olua