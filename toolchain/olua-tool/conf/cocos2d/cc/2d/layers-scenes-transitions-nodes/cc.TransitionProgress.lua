local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionProgress"
cls.LUACLS = "cc.TransitionProgress"
cls.SUPERCLS = "cc.TransitionScene"
cls.funcs([[
    static TransitionProgress* create(float t, @ref Scene* scene)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionProgressRadialCCW"
cls.LUACLS = "cc.TransitionProgressRadialCCW"
cls.SUPERCLS = "cc.TransitionProgress"
cls.funcs([[
    static TransitionProgressRadialCCW* create(float t, @ref Scene* scene)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionProgressRadialCW"
cls.LUACLS = "cc.TransitionProgressRadialCW"
cls.SUPERCLS = "cc.TransitionProgress"
cls.funcs([[
    static TransitionProgressRadialCW* create(float t, @ref Scene* scene)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionProgressHorizontal"
cls.LUACLS = "cc.TransitionProgressHorizontal"
cls.SUPERCLS = "cc.TransitionProgress"
cls.funcs([[
    static TransitionProgressHorizontal* create(float t, @ref Scene* scene)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionProgressVertical"
cls.LUACLS = "cc.TransitionProgressVertical"
cls.SUPERCLS = "cc.TransitionProgress"
cls.funcs([[
    static TransitionProgressVertical* create(float t, @ref Scene* scene)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionProgressInOut"
cls.LUACLS = "cc.TransitionProgressInOut"
cls.SUPERCLS = "cc.TransitionProgress"
cls.funcs([[
    static TransitionProgressInOut* create(float t, @ref Scene* scene)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TransitionProgressOutIn"
cls.LUACLS = "cc.TransitionProgressOutIn"
cls.SUPERCLS = "cc.TransitionProgress"
cls.funcs([[
    static TransitionProgressOutIn* create(float t, @ref Scene* scene)
]])

return M