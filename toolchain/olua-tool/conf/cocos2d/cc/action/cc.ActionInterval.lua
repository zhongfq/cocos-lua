local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::ActionInterval"
cls.LUACLS = "cc.ActionInterval"
cls.SUPERCLS = "cc.FiniteTimeAction"
cls.prop('amplitudeRate', 'float getAmplitudeRate()', 'void setAmplitudeRate(float amp)')
cls.prop('elapsed', 'float getElapsed()')
cls.funcs([[
    float getElapsed()
    void setAmplitudeRate(float amp)
    float getAmplitudeRate()
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::Sequence"
cls.LUACLS = "cc.Sequence"
cls.SUPERCLS = "cc.ActionInterval"
cls.func('create', [[
{
    cocos2d::Vector<cocos2d::FiniteTimeAction *> actions;
    int n = lua_gettop(L);
    actions.reserve(n);

    for (int i = 1; i <= n; i++) {
        cocos2d::FiniteTimeAction *obj;
        olua_check_cppobj(L, i, (void **)&obj, "cc.FiniteTimeAction");
        actions.pushBack(obj);
    }
    
    cocos2d::Sequence *ret = (cocos2d::Sequence *)cocos2d::Sequence::create(actions);
    return olua_push_cppobj<cocos2d::Sequence>(L, ret, "cc.Sequence");
}
]])
cls.funcs([[
    static Sequence* createWithTwoActions(FiniteTimeAction *actionOne, FiniteTimeAction *actionTwo);
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::Repeat"
cls.LUACLS = "cc.Repeat"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs([[
    static Repeat* create(FiniteTimeAction *action, unsigned int times)
    void setInnerAction(FiniteTimeAction *action)
    FiniteTimeAction* getInnerAction()
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::RepeatForever"
cls.LUACLS = "cc.RepeatForever"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs([[
    static RepeatForever* create(ActionInterval *action)
    void setInnerAction(ActionInterval *action)
    ActionInterval* getInnerAction()
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::Spawn"
cls.LUACLS = "cc.Spawn"
cls.SUPERCLS = "cc.ActionInterval"
cls.func('create', [[
{
    cocos2d::Vector<cocos2d::FiniteTimeAction *> actions;
    int n = lua_gettop(L);
    actions.reserve(n);

    for (int i = 1; i <= n; i++) {
        cocos2d::FiniteTimeAction *obj;
        olua_check_cppobj(L, i, (void **)&obj, "cc.FiniteTimeAction");
        actions.pushBack(obj);
    }
    
    cocos2d::Spawn *ret = (cocos2d::Spawn *)cocos2d::Spawn::create(actions);
    return olua_push_cppobj<cocos2d::Spawn>(L, ret, "cc.Spawn");
}
]])
cls.funcs([[
    static Spawn* createWithTwoActions(FiniteTimeAction *action1, FiniteTimeAction *action2);
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::RotateTo"
cls.LUACLS = "cc.RotateTo"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs([[
    static RotateTo* create(float duration, float dstAngleX, float dstAngleY)
    static RotateTo* create(float duration, float dstAngle)
    static RotateTo* create(float duration, const Vec3& dstAngle3D)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::RotateBy"
cls.LUACLS = "cc.RotateBy"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs([[
    static RotateBy* create(float duration, float deltaAngle)
    static RotateBy* create(float duration, float deltaAngleZ_X, float deltaAngleZ_Y)
    static RotateBy* create(float duration, const Vec3& deltaAngle3D)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::MoveBy"
cls.LUACLS = "cc.MoveBy"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs([[
    static MoveBy* create(float duration, @pack const Vec2& deltaPosition)
    static MoveBy* create(float duration, @pack const Vec3& deltaPosition)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::MoveTo"
cls.LUACLS = "cc.MoveTo"
cls.SUPERCLS = "cc.MoveBy"
cls.funcs([[
    static MoveTo* create(float duration, @pack const Vec2& position)
    static MoveTo* create(float duration, @pack const Vec3& position)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::SkewTo"
cls.LUACLS = "cc.SkewTo"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs([[
    static SkewTo* create(float t, float sx, float sy);
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::SkewBy"
cls.LUACLS = "cc.SkewBy"
cls.SUPERCLS = "cc.SkewTo"
cls.funcs([[
    static SkewBy* create(float t, float deltaSkewX, float deltaSkewY);
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::ResizeTo"
cls.LUACLS = "cc.ResizeTo"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs([[
    static ResizeTo* create(float duration, @pack const cocos2d::Size& final_size);
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::ResizeBy"
cls.LUACLS = "cc.ResizeBy"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs([[
     static ResizeBy* create(float duration, @pack const cocos2d::Size& deltaSize);
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::JumpBy"
cls.LUACLS = "cc.JumpBy"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs([[
    static JumpBy* create(float duration, @pack const Vec2& position, float height, int jumps);
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::JumpTo"
cls.LUACLS = "cc.JumpTo"
cls.SUPERCLS = "cc.JumpBy"
cls.funcs([[
    static JumpTo* create(float duration, @pack const Vec2& position, float height, int jumps);
]])

return M