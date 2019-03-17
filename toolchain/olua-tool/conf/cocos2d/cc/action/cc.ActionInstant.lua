local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::ActionInstant"
cls.LUACLS = "cc.ActionInstant"
cls.SUPERCLS = "cc.FiniteTimeAction"

local cls = class(M)
cls.CPPCLS = "cocos2d::Show"
cls.LUACLS = "cc.Show"
cls.SUPERCLS = "cc.ActionInstant"
cls.funcs([[
    static Show * create()
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::Hide"
cls.LUACLS = "cc.Hide"
cls.SUPERCLS = "cc.ActionInstant"
cls.funcs([[
    static Hide * create()
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::ToggleVisibility"
cls.LUACLS = "cc.ToggleVisibility"
cls.SUPERCLS = "cc.ActionInstant"
cls.funcs([[
    static ToggleVisibility * create()
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::RemoveSelf"
cls.LUACLS = "cc.RemoveSelf"
cls.SUPERCLS = "cc.ActionInstant"
cls.funcs([[
    static RemoveSelf * create(bool isNeedCleanUp = true)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::FlipX"
cls.LUACLS = "cc.FlipX"
cls.SUPERCLS = "cc.ActionInstant"
cls.funcs([[
    static FlipX * create(bool x)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::FlipY"
cls.LUACLS = "cc.FlipY"
cls.SUPERCLS = "cc.ActionInstant"
cls.funcs([[
    static FlipY * create(bool y)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::Place"
cls.LUACLS = "cc.Place"
cls.SUPERCLS = "cc.ActionInstant"
cls.funcs([[
    static Place * create(const Vec2& pos)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::CallFunc"
cls.LUACLS = "cc.CallFunc"
cls.SUPERCLS = "cc.ActionInstant"
cls.callback(nil, 
    {
        CALLBACK_MAKER = 'olua_makecallbacktag("callFunc")',
        CALLBACK_INITFUNC = 'initWithFunction',
    },
    'static CallFunc * create(const std::function<void()>& func)'
)

return M