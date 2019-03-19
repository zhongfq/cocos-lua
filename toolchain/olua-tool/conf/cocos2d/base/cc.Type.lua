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

local cls = class(M)
cls.CPPCLS = "cocos2d::SetIntervalReason"
cls.LUACLS = "cc.SetIntervalReason"
cls.enums [[
    BY_GAME
    BY_ENGINE
    BY_SYSTEM
    BY_SCENE_CHANGE
    BY_DIRECTOR_PAUSE
]]

return M