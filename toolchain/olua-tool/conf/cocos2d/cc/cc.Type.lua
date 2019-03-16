local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::Acceleration"
cls.LUACLS = "cc.Acceleration"
cls.SUPERCLS = "cc.Ref"

local cls = class(M)
cls.CPPCLS = "cocos2d::Vec3"
cls.LUACLS = "cc.Vec3"
cls.func('new', newcppobj(cls))
cls.func('__gc', gccppobj(cls))
cls.vars [[
    float x;
    float y;
    float z;
]]

return M