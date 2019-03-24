local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::ActionInterval"
cls.LUACLS = "cc.ActionInterval"
cls.SUPERCLS = "cc.FiniteTimeAction"
cls.funcs([[
    float getElapsed()
    void setAmplitudeRate(float amp)
    float getAmplitudeRate()
]])
cls.prop("amplitudeRate")
cls.prop("elapsed")

local cls = class(M)
cls.CPPCLS = "cocos2d::Sequence"
cls.LUACLS = "cc.Sequence"
cls.SUPERCLS = "cc.ActionInterval"
cls.func('create', [[
{
    cocos2d::Vector<cocos2d::FiniteTimeAction *> actions;
    int n = lua_gettop(L);
    actions.reserve(n);

    cocos2d::Sequence *ret = new cocos2d::Sequence();
    ret->autorelease();
    olua_push_cppobj<cocos2d::Sequence>(L, ret, "cc.Sequence");

    for (int i = 1; i <= n; i++) {
        cocos2d::FiniteTimeAction *obj;
        olua_check_cppobj(L, i, (void **)&obj, "cc.FiniteTimeAction");
        actions.pushBack(obj);
        olua_mapref(L, -1, ".autoref", i);
    }

    ret->init(actions);
    
    return 1;
}
]])
cls.funcs([[
    static Sequence* createWithTwoActions(@ref FiniteTimeAction *actionOne, @ref FiniteTimeAction *actionTwo);
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::Repeat"
cls.LUACLS = "cc.Repeat"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs([[
    static Repeat* create(@ref(single innerAction) FiniteTimeAction *action, unsigned int times)
    void setInnerAction(@ref(single innerAction) FiniteTimeAction *action)
    @ref(single innerAction) FiniteTimeAction* getInnerAction()
]])
cls.prop('innerAction')

local cls = class(M)
cls.CPPCLS = "cocos2d::RepeatForever"
cls.LUACLS = "cc.RepeatForever"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs([[
    static RepeatForever* create(@ref(single innerAction) ActionInterval *action)
    void setInnerAction(@ref(single innerAction) ActionInterval *action)
    @ref(single innerAction) ActionInterval* getInnerAction()
]])
cls.prop("innerAction")

local cls = class(M)
cls.CPPCLS = "cocos2d::Spawn"
cls.LUACLS = "cc.Spawn"
cls.SUPERCLS = "cc.ActionInterval"
cls.func('create', [[
{
    cocos2d::Vector<cocos2d::FiniteTimeAction *> actions;
    int n = lua_gettop(L);
    actions.reserve(n);

    cocos2d::Spawn *ret = new cocos2d::Spawn();
    ret->autorelease();
    olua_push_cppobj<cocos2d::Spawn>(L, ret, "cc.Spawn");

    for (int i = 1; i <= n; i++) {
        cocos2d::FiniteTimeAction *obj;
        olua_check_cppobj(L, i, (void **)&obj, "cc.FiniteTimeAction");
        actions.pushBack(obj);
        olua_mapref(L, -1, ".autoref", i);
    }
    
    ret->init(actions);

    return 1;
}
]])
cls.funcs([[
    static Spawn* createWithTwoActions(@ref FiniteTimeAction *action1, @ref FiniteTimeAction *action2);
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
    static MoveBy* create(float duration, Vec2& deltaPosition)
    static MoveBy* create(float duration, Vec3& deltaPosition)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::MoveTo"
cls.LUACLS = "cc.MoveTo"
cls.SUPERCLS = "cc.MoveBy"
cls.funcs([[
    static MoveTo* create(float duration, Vec2& position)
    static MoveTo* create(float duration, Vec3& position)
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
    static ResizeTo* create(float duration, cocos2d::Size& final_size);
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::ResizeBy"
cls.LUACLS = "cc.ResizeBy"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs([[
     static ResizeBy* create(float duration, cocos2d::Size& deltaSize);
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::JumpBy"
cls.LUACLS = "cc.JumpBy"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs([[
    static JumpBy* create(float duration, Vec2& position, float height, int jumps);
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::JumpTo"
cls.LUACLS = "cc.JumpTo"
cls.SUPERCLS = "cc.JumpBy"
cls.funcs([[
    static JumpTo* create(float duration, Vec2& position, float height, int jumps);
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::BezierBy"
cls.LUACLS = "cc.BezierBy"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs([[
    static BezierBy* create(float t, @pack ccBezierConfig& c);
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::BezierTo"
cls.LUACLS = "cc.BezierTo"
cls.SUPERCLS = "cc.BezierBy"
cls.funcs([[
    static BezierTo* create(float t, @pack ccBezierConfig& c);
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::ScaleTo"
cls.LUACLS = "cc.ScaleTo"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs([[
    static ScaleTo* create(float duration, float s)
    static ScaleTo* create(float duration, float sx, float sy)
    static ScaleTo* create(float duration, float sx, float sy, float sz)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::ScaleBy"
cls.LUACLS = "cc.ScaleBy"
cls.SUPERCLS = "cc.ScaleTo"
cls.funcs([[
    static ScaleBy* create(float duration, float s)
    static ScaleBy* create(float duration, float sx, float sy)
    static ScaleBy* create(float duration, float sx, float sy, float sz)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::Blink"
cls.LUACLS = "cc.Blink"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs([[
    static Blink* create(float duration, int blinks)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::FadeTo"
cls.LUACLS = "cc.FadeTo"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs([[
    static FadeTo* create(float duration, GLubyte opacity)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::FadeIn"
cls.LUACLS = "cc.FadeIn"
cls.SUPERCLS = "cc.FadeTo"
cls.funcs([[
    static FadeIn* create(float d)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::FadeOut"
cls.LUACLS = "cc.FadeOut"
cls.SUPERCLS = "cc.FadeTo"
cls.funcs([[
    static FadeOut* create(float d)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TintTo"
cls.LUACLS = "cc.TintTo"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs([[
    static TintTo* create(float duration, GLubyte red, GLubyte green, GLubyte blue)
    static TintTo* create(float duration, const Color3B& color)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::TintBy"
cls.LUACLS = "cc.TintBy"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs([[
    static TintBy* create(float duration, GLshort deltaRed, GLshort deltaGreen, GLshort deltaBlue)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::DelayTime"
cls.LUACLS = "cc.DelayTime"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs([[
    static DelayTime* create(float d)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::ReverseTime"
cls.LUACLS = "cc.ReverseTime"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs([[
    static ReverseTime* create(@ref FiniteTimeAction *action)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::Animate"
cls.LUACLS = "cc.Animate"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs([[
    static Animate* create(Animation *animation)
    void setAnimation(Animation* animation)
    Animation* getAnimation()
    int getCurrentFrameIndex()
]])
cls.prop('animation')
cls.prop('currentFrameIndex')

local cls = class(M)
cls.CPPCLS = "cocos2d::TargetedAction"
cls.LUACLS = "cc.TargetedAction"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs([[
    static TargetedAction* create(Node* target, @ref FiniteTimeAction* action)
    void setForcedTarget(Node* forcedTarget)
    Node* getForcedTarget()
]])
cls.prop("forcedTarget")

local cls = class(M)
cls.CPPCLS = "cocos2d::ActionFloat"
cls.LUACLS = "cc.ActionFloat"
cls.SUPERCLS = "cc.ActionInterval"
cls.callback(
    'static ActionFloat* create(float duration, float from, float to, std::function<void(float value)> callback)', 
    {
        CALLBACK_MAKER = 'olua_makecallbacktag("ActionFloat")',
        CALLBACK_INITFUNC = 'initWithDuration'
    }
)

return M