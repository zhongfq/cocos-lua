-- AUTO BUILD, DON'T MODIFY!

require "autobuild.cocos2d-action-types"

local olua = require "olua"
local typeconv = olua.typeconv
local typecls = olua.typecls
local cls = nil
local M = {}

M.NAME = "cocos2d_action"
M.PATH = "../../frameworks/libxgame/src/lua-bindings"
M.INCLUDES = [[
#include "lua-bindings/lua_cocos2d.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cocos2d.h"
#include "xgame/xlua.h"
]]

M.CONVS = {
}

M.CLASSES = {}

cls = typecls 'cocos2d::Action'
cls.SUPERCLS = "cocos2d::Ref"
cls.const('INVALID_TAG', 'cocos2d::Action::INVALID_TAG', 'const int')
cls.funcs [[
    std::string description()
    cocos2d::Action *clone()
    cocos2d::Action *reverse()
    bool isDone()
    void startWithTarget(cocos2d::Node *target)
    void stop()
    void step(float dt)
    void update(float time)
    cocos2d::Node *getTarget()
    void setTarget(cocos2d::Node *target)
    cocos2d::Node *getOriginalTarget()
    void setOriginalTarget(cocos2d::Node *originalTarget)
    int getTag()
    void setTag(int tag)
    unsigned int getFlags()
    void setFlags(unsigned int flags)
]]
cls.props [[
    done
    target
    originalTarget
    tag
    flags
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FiniteTimeAction'
cls.SUPERCLS = "cocos2d::Action"
cls.funcs [[
    float getDuration()
    void setDuration(float duration)
]]
cls.props [[
    duration
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Speed'
cls.SUPERCLS = "cocos2d::Action"
cls.funcs [[
    static cocos2d::Speed *create(@addref(innerAction ^) cocos2d::ActionInterval *action, float speed)
    float getSpeed()
    void setSpeed(float speed)
    void setInnerAction(@addref(innerAction ^) cocos2d::ActionInterval *action)
    @addref(innerAction ^) cocos2d::ActionInterval *getInnerAction()
]]
cls.props [[
    speed
    innerAction
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Follow'
cls.SUPERCLS = "cocos2d::Action"
cls.funcs [[
    static cocos2d::Follow *create(cocos2d::Node *followedNode, @optional const cocos2d::Rect &rect)
    static cocos2d::Follow *createWithOffset(cocos2d::Node *followedNode, float xOffset, float yOffset, @optional const cocos2d::Rect &rect)
    bool isBoundarySet()
    void setBoundarySet(bool value)
    bool initWithTarget(cocos2d::Node *followedNode, @optional const cocos2d::Rect &rect)
    bool initWithTargetAndOffset(cocos2d::Node *followedNode, float xOffset, float yOffset, @optional const cocos2d::Rect &rect)
]]
cls.props [[
    boundarySet
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::tweenfunc'
cls.REG_LUATYPE = false
cls.funcs [[
    static float easeIn(float time, float rate)
    static float easeOut(float time, float rate)
    static float easeInOut(float time, float rate)
    static float bezieratFunction(float a, float b, float c, float d, float t)
    static float quadraticIn(float time)
    static float quadraticOut(float time)
    static float quadraticInOut(float time)
    static float linear(float time)
    static float sineEaseIn(float time)
    static float sineEaseOut(float time)
    static float sineEaseInOut(float time)
    static float quadEaseIn(float time)
    static float quadEaseOut(float time)
    static float quadEaseInOut(float time)
    static float cubicEaseIn(float time)
    static float cubicEaseOut(float time)
    static float cubicEaseInOut(float time)
    static float quartEaseIn(float time)
    static float quartEaseOut(float time)
    static float quartEaseInOut(float time)
    static float quintEaseIn(float time)
    static float quintEaseOut(float time)
    static float quintEaseInOut(float time)
    static float expoEaseIn(float time)
    static float expoEaseOut(float time)
    static float expoEaseInOut(float time)
    static float circEaseIn(float time)
    static float circEaseOut(float time)
    static float circEaseInOut(float time)
    static float elasticEaseIn(float time, float period)
    static float elasticEaseOut(float time, float period)
    static float elasticEaseInOut(float time, float period)
    static float backEaseIn(float time)
    static float backEaseOut(float time)
    static float backEaseInOut(float time)
    static float bounceEaseIn(float time)
    static float bounceEaseOut(float time)
    static float bounceEaseInOut(float time)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ActionInterval'
cls.SUPERCLS = "cocos2d::FiniteTimeAction"
cls.funcs [[
    float getElapsed()
    void setAmplitudeRate(float amp)
    float getAmplitudeRate()
]]
cls.props [[
    elapsed
    amplitudeRate
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Sequence'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static cocos2d::Sequence *createWithTwoActions(@addref(autoref |) cocos2d::FiniteTimeAction *actionOne, @addref(autoref |) cocos2d::FiniteTimeAction *actionTwo)
]]
cls.func('create', [[{
    cocos2d::Vector<cocos2d::FiniteTimeAction *> actions;
    int n = lua_gettop(L);
    actions.reserve(n);

    auto ret = new cocos2d::Sequence();
    ret->autorelease();
    olua_push_cppobj<cocos2d::Sequence>(L, ret);

    for (int i = 1; i <= n; i++) {
        auto obj = olua_checkobj<cocos2d::FiniteTimeAction>(L, i);
        actions.pushBack(obj);
        olua_addref(L, -1, ".autoref", i, OLUA_MODE_MULTIPLE);
    }

    ret->init(actions);

    return 1;
}]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Repeat'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static cocos2d::Repeat *create(@addref(innerAction ^) cocos2d::FiniteTimeAction *action, unsigned int times)
    void setInnerAction(@addref(innerAction ^) cocos2d::FiniteTimeAction *action)
    @addref(innerAction ^) cocos2d::FiniteTimeAction *getInnerAction()
]]
cls.props [[
    innerAction
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::RepeatForever'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static cocos2d::RepeatForever *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    void setInnerAction(@addref(innerAction ^) cocos2d::ActionInterval *action)
    @addref(innerAction ^) cocos2d::ActionInterval *getInnerAction()
]]
cls.props [[
    innerAction
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Spawn'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static cocos2d::Spawn *createWithTwoActions(@addref(autoref |) cocos2d::FiniteTimeAction *action1, @addref(autoref |) cocos2d::FiniteTimeAction *action2)
]]
cls.func('create', [[{
    cocos2d::Vector<cocos2d::FiniteTimeAction *> actions;
    int n = lua_gettop(L);
    actions.reserve(n);

    auto ret = new cocos2d::Spawn();
    ret->autorelease();
    olua_push_cppobj<cocos2d::Spawn>(L, ret);

    for (int i = 1; i <= n; i++) {
        auto obj = olua_checkobj<cocos2d::FiniteTimeAction>(L, i);
        actions.pushBack(obj);
        olua_addref(L, -1, ".autoref", i, OLUA_MODE_MULTIPLE);
    }

    ret->init(actions);

    return 1;
}]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::RotateTo'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static cocos2d::RotateTo *create(float duration, float dstAngleX, float dstAngleY)
    static cocos2d::RotateTo *create(float duration, float dstAngle)
    static cocos2d::RotateTo *create(float duration, const cocos2d::Vec3 &dstAngle3D)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::RotateBy'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static cocos2d::RotateBy *create(float duration, float deltaAngle)
    static cocos2d::RotateBy *create(float duration, float deltaAngleZ_X, float deltaAngleZ_Y)
    static cocos2d::RotateBy *create(float duration, const cocos2d::Vec3 &deltaAngle3D)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::MoveBy'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static cocos2d::MoveBy *create(float duration, @pack const cocos2d::Vec2 &deltaPosition)
    static cocos2d::MoveBy *create(float duration, @pack const cocos2d::Vec3 &deltaPosition)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::MoveTo'
cls.SUPERCLS = "cocos2d::MoveBy"
cls.funcs [[
    static cocos2d::MoveTo *create(float duration, @pack const cocos2d::Vec2 &position)
    static cocos2d::MoveTo *create(float duration, @pack const cocos2d::Vec3 &position)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::SkewTo'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static cocos2d::SkewTo *create(float t, float sx, float sy)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::SkewBy'
cls.SUPERCLS = "cocos2d::SkewTo"
cls.funcs [[
    static cocos2d::SkewBy *create(float t, float deltaSkewX, float deltaSkewY)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ResizeTo'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static cocos2d::ResizeTo *create(float duration, const cocos2d::Size &final_size)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ResizeBy'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static cocos2d::ResizeBy *create(float duration, const cocos2d::Size &deltaSize)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::BezierBy'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static cocos2d::BezierBy *create(float t, @pack const cocos2d::ccBezierConfig &c)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::BezierTo'
cls.SUPERCLS = "cocos2d::BezierBy"
cls.funcs [[
    static cocos2d::BezierTo *create(float t, @pack const cocos2d::ccBezierConfig &c)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::JumpBy'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static cocos2d::JumpBy *create(float duration, @pack const cocos2d::Vec2 &position, float height, int jumps)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::JumpTo'
cls.SUPERCLS = "cocos2d::JumpBy"
cls.funcs [[
    static cocos2d::JumpTo *create(float duration, @pack const cocos2d::Vec2 &position, float height, int jumps)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ScaleTo'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static cocos2d::ScaleTo *create(float duration, float s)
    static cocos2d::ScaleTo *create(float duration, float sx, float sy)
    static cocos2d::ScaleTo *create(float duration, float sx, float sy, float sz)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ScaleBy'
cls.SUPERCLS = "cocos2d::ScaleTo"
cls.funcs [[
    static cocos2d::ScaleBy *create(float duration, float s)
    static cocos2d::ScaleBy *create(float duration, float sx, float sy)
    static cocos2d::ScaleBy *create(float duration, float sx, float sy, float sz)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Blink'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static cocos2d::Blink *create(float duration, int blinks)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FadeTo'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static cocos2d::FadeTo *create(float duration, uint8_t opacity)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FadeIn'
cls.SUPERCLS = "cocos2d::FadeTo"
cls.funcs [[
    static cocos2d::FadeIn *create(float d)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FadeOut'
cls.SUPERCLS = "cocos2d::FadeTo"
cls.funcs [[
    static cocos2d::FadeOut *create(float d)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TintTo'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static cocos2d::TintTo *create(float duration, uint8_t red, uint8_t green, uint8_t blue)
    static cocos2d::TintTo *create(float duration, const cocos2d::Color3B &color)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TintBy'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static cocos2d::TintBy *create(float duration, int16_t deltaRed, int16_t deltaGreen, int16_t deltaBlue)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::DelayTime'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static cocos2d::DelayTime *create(float d)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ReverseTime'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static cocos2d::ReverseTime *create(@addref(autoref |) cocos2d::FiniteTimeAction *action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Animate'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static cocos2d::Animate *create(cocos2d::Animation *animation)
    void setAnimation(cocos2d::Animation *animation)
    cocos2d::Animation *getAnimation()
    int getCurrentFrameIndex()
]]
cls.props [[
    animation
    currentFrameIndex
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TargetedAction'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static cocos2d::TargetedAction *create(cocos2d::Node *target, @addref(autoref |) cocos2d::FiniteTimeAction *action)
    void setForcedTarget(cocos2d::Node *forcedTarget)
    cocos2d::Node *getForcedTarget()
    bool initWithTarget(cocos2d::Node *target, cocos2d::FiniteTimeAction *action)
]]
cls.props [[
    forcedTarget
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ActionFloat'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
]]
cls.callback {
    FUNCS =  {
        'static cocos2d::ActionFloat *create(float duration, float from, float to, @local std::function<void (float)> callback)'
    },
    TAG_MAKER = 'ActionFloat',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = "return",
    TAG_SCOPE = 'object',
}
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ProgressTo'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static cocos2d::ProgressTo *create(float duration, float percent)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ProgressFromTo'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static cocos2d::ProgressFromTo *create(float duration, float fromPercentage, float toPercentage)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ActionEase'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    @addref(innerAction ^) cocos2d::ActionInterval *getInnerAction()
]]
cls.props [[
    innerAction
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseRateAction'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseRateAction *create(@addref(innerAction ^) cocos2d::ActionInterval *action, float rate)
    void setRate(float rate)
    float getRate()
]]
cls.props [[
    rate
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseExponentialIn'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseExponentialIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseExponentialOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseExponentialOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseExponentialInOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseExponentialInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseSineIn'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseSineIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseSineOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseSineOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseSineInOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseSineInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseBounceIn'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseBounceIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseBounceOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseBounceOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseBounceInOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseBounceInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseBackIn'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseBackIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseBackOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseBackOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseBackInOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseBackInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseQuadraticActionIn'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseQuadraticActionIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseQuadraticActionOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseQuadraticActionOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseQuadraticActionInOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseQuadraticActionInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseQuarticActionIn'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseQuarticActionIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseQuarticActionOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseQuarticActionOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseQuarticActionInOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseQuarticActionInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseQuinticActionIn'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseQuinticActionIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseQuinticActionOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseQuinticActionOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseQuinticActionInOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseQuinticActionInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseCircleActionIn'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseCircleActionIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseCircleActionOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseCircleActionOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseCircleActionInOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseCircleActionInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseCubicActionIn'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseCubicActionIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseCubicActionOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseCubicActionOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseCubicActionInOut'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseCubicActionInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseIn'
cls.SUPERCLS = "cocos2d::EaseRateAction"
cls.funcs [[
    static cocos2d::EaseIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action, float rate)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseOut'
cls.SUPERCLS = "cocos2d::EaseRateAction"
cls.funcs [[
    static cocos2d::EaseOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, float rate)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseInOut'
cls.SUPERCLS = "cocos2d::EaseRateAction"
cls.funcs [[
    static cocos2d::EaseInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, float rate)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseElastic'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    float getPeriod()
    void setPeriod(float fPeriod)
]]
cls.props [[
    period
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseElasticIn'
cls.SUPERCLS = "cocos2d::EaseElastic"
cls.funcs [[
    static cocos2d::EaseElasticIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseElasticOut'
cls.SUPERCLS = "cocos2d::EaseElastic"
cls.funcs [[
    static cocos2d::EaseElasticOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseElasticInOut'
cls.SUPERCLS = "cocos2d::EaseElastic"
cls.funcs [[
    static cocos2d::EaseElasticInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseBezierAction'
cls.SUPERCLS = "cocos2d::ActionEase"
cls.funcs [[
    static cocos2d::EaseBezierAction *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    void setBezierParamer(float p0, float p1, float p2, float p3)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PointArray'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    static cocos2d::PointArray *create(ssize_t capacity)
    bool initWithCapacity(ssize_t capacity)
    void addControlPoint(const cocos2d::Vec2 &controlPoint)
    void insertControlPoint(const cocos2d::Vec2 &controlPoint, ssize_t index)
    void replaceControlPoint(const cocos2d::Vec2 &controlPoint, ssize_t index)
    const cocos2d::Vec2 &getControlPointAtIndex(ssize_t index)
    void removeControlPointAtIndex(ssize_t index)
    ssize_t count()
    cocos2d::PointArray *reverse()
    void reverseInline()
    cocos2d::PointArray *clone()
    const std::vector<Vec2> &getControlPoints()
    void setControlPoints(std::vector<Vec2> controlPoints)
]]
cls.props [[
    controlPoints
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CardinalSplineTo'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static cocos2d::CardinalSplineTo *create(float duration, cocos2d::PointArray *points, float tension)
    void updatePosition(const cocos2d::Vec2 &newPos)
    cocos2d::PointArray *getPoints()
    void setPoints(cocos2d::PointArray *points)
]]
cls.props [[
    points
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CardinalSplineBy'
cls.SUPERCLS = "cocos2d::CardinalSplineTo"
cls.funcs [[
    static cocos2d::CardinalSplineBy *create(float duration, cocos2d::PointArray *points, float tension)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CatmullRomTo'
cls.SUPERCLS = "cocos2d::CardinalSplineTo"
cls.funcs [[
    static cocos2d::CatmullRomTo *create(float dt, cocos2d::PointArray *points)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CatmullRomBy'
cls.SUPERCLS = "cocos2d::CardinalSplineBy"
cls.funcs [[
    static cocos2d::CatmullRomBy *create(float dt, cocos2d::PointArray *points)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ActionInstant'
cls.SUPERCLS = "cocos2d::FiniteTimeAction"
cls.funcs [[
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Show'
cls.SUPERCLS = "cocos2d::ActionInstant"
cls.funcs [[
    static cocos2d::Show *create()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Hide'
cls.SUPERCLS = "cocos2d::ActionInstant"
cls.funcs [[
    static cocos2d::Hide *create()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ToggleVisibility'
cls.SUPERCLS = "cocos2d::ActionInstant"
cls.funcs [[
    static cocos2d::ToggleVisibility *create()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::RemoveSelf'
cls.SUPERCLS = "cocos2d::ActionInstant"
cls.funcs [[
    static cocos2d::RemoveSelf *create(@optional bool isNeedCleanUp)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FlipX'
cls.SUPERCLS = "cocos2d::ActionInstant"
cls.funcs [[
    static cocos2d::FlipX *create(bool x)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FlipY'
cls.SUPERCLS = "cocos2d::ActionInstant"
cls.funcs [[
    static cocos2d::FlipY *create(bool y)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Place'
cls.SUPERCLS = "cocos2d::ActionInstant"
cls.funcs [[
    static cocos2d::Place *create(const cocos2d::Vec2 &pos)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CallFunc'
cls.SUPERCLS = "cocos2d::ActionInstant"
cls.funcs [[
    void execute()
]]
cls.callback {
    FUNCS =  {
        'static cocos2d::CallFunc *create(@local const std::function<void ()> &func)'
    },
    TAG_MAKER = 'CallFunc',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = "return",
    TAG_SCOPE = 'object',
}
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ActionCamera'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    void setEye(const cocos2d::Vec3 &eye)
    void setEye(float x, float y, float z)
    const cocos2d::Vec3 &getEye()
    void setCenter(const cocos2d::Vec3 &center)
    const cocos2d::Vec3 &getCenter()
    void setUp(const cocos2d::Vec3 &up)
    const cocos2d::Vec3 &getUp()
]]
cls.props [[
    eye
    center
    up
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::OrbitCamera'
cls.SUPERCLS = "cocos2d::ActionCamera"
cls.funcs [[
    static cocos2d::OrbitCamera *create(float t, float radius, float deltaRadius, float angleZ, float deltaAngleZ, float angleX, float deltaAngleX)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::GridBase'
cls.SUPERCLS = "cocos2d::Ref"
cls.funcs [[
    void beforeBlit()
    void afterBlit()
    void blit()
    void reuse()
    void calculateVertexPoints()
    bool initWithSize(const cocos2d::Size &gridSize)
    bool initWithSize(const cocos2d::Size &gridSize, const cocos2d::Rect &rect)
    bool initWithSize(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped)
    bool initWithSize(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped, const cocos2d::Rect &rect)
    bool isActive()
    void setActive(bool active)
    int getReuseGrid()
    void setReuseGrid(int reuseGrid)
    const cocos2d::Size &getGridSize()
    void setGridSize(const cocos2d::Size &gridSize)
    const cocos2d::Vec2 &getStep()
    void setStep(const cocos2d::Vec2 &step)
    bool isTextureFlipped()
    void setTextureFlipped(bool flipped)
    void beforeDraw()
    void afterDraw(cocos2d::Node *target)
    void set2DProjection()
    void setGridRect(const cocos2d::Rect &rect)
    const cocos2d::Rect &getGridRect()
]]
cls.props [[
    active
    reuseGrid
    gridSize
    step
    textureFlipped
    gridRect
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Grid3D'
cls.SUPERCLS = "cocos2d::GridBase"
cls.funcs [[
    static cocos2d::Grid3D *create(const cocos2d::Size &gridSize)
    static cocos2d::Grid3D *create(const cocos2d::Size &gridSize, const cocos2d::Rect &rect)
    static cocos2d::Grid3D *create(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped)
    static cocos2d::Grid3D *create(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped, const cocos2d::Rect &rect)
    cocos2d::Vec3 getVertex(const cocos2d::Vec2 &pos)
    cocos2d::Vec3 getOriginalVertex(const cocos2d::Vec2 &pos)
    void setVertex(const cocos2d::Vec2 &pos, const cocos2d::Vec3 &vertex)
    void setNeedDepthTestForBlit(bool neededDepthTest)
    bool getNeedDepthTestForBlit()
]]
cls.props [[
    needDepthTestForBlit
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TiledGrid3D'
cls.SUPERCLS = "cocos2d::GridBase"
cls.funcs [[
    static cocos2d::TiledGrid3D *create(const cocos2d::Size &gridSize)
    static cocos2d::TiledGrid3D *create(const cocos2d::Size &gridSize, const cocos2d::Rect &rect)
    static cocos2d::TiledGrid3D *create(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped)
    static cocos2d::TiledGrid3D *create(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped, const cocos2d::Rect &rect)
    cocos2d::Quad3 getTile(const cocos2d::Vec2 &pos)
    cocos2d::Quad3 getOriginalTile(const cocos2d::Vec2 &pos)
    void setTile(const cocos2d::Vec2 &pos, const cocos2d::Quad3 &coords)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::NodeGrid'
cls.SUPERCLS = "cocos2d::Node"
cls.funcs [[
    static cocos2d::NodeGrid *create()
    static cocos2d::NodeGrid *create(const cocos2d::Rect &rect)
    cocos2d::GridBase *getGrid()
    void setGrid(cocos2d::GridBase *grid)
    void setTarget(cocos2d::Node *target)
    void setGridRect(const cocos2d::Rect &gridRect)
    const cocos2d::Rect &getGridRect()
]]
cls.props [[
    grid
    gridRect
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::GridAction'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    cocos2d::GridBase *getGrid()
]]
cls.props [[
    grid
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Grid3DAction'
cls.SUPERCLS = "cocos2d::GridAction"
cls.funcs [[
    cocos2d::Vec3 getVertex(const cocos2d::Vec2 &position)
    cocos2d::Vec3 getOriginalVertex(const cocos2d::Vec2 &position)
    void setVertex(const cocos2d::Vec2 &position, const cocos2d::Vec3 &vertex)
    cocos2d::Rect getGridRect()
]]
cls.props [[
    gridRect
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TiledGrid3DAction'
cls.SUPERCLS = "cocos2d::GridAction"
cls.funcs [[
    static cocos2d::TiledGrid3DAction *create(float duration, const cocos2d::Size &gridSize)
    cocos2d::Quad3 getTile(const cocos2d::Vec2 &position)
    cocos2d::Quad3 getOriginalTile(const cocos2d::Vec2 &position)
    void setTile(const cocos2d::Vec2 &position, const cocos2d::Quad3 &coords)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::AccelDeccelAmplitude'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static cocos2d::AccelDeccelAmplitude *create(cocos2d::Action *action, float duration)
    float getRate()
    void setRate(float rate)
]]
cls.props [[
    rate
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::AccelAmplitude'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static cocos2d::AccelAmplitude *create(cocos2d::Action *action, float duration)
    float getRate()
    void setRate(float rate)
]]
cls.props [[
    rate
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::DeccelAmplitude'
cls.SUPERCLS = "cocos2d::ActionInterval"
cls.funcs [[
    static cocos2d::DeccelAmplitude *create(cocos2d::Action *action, float duration)
    float getRate()
    void setRate(float rate)
]]
cls.props [[
    rate
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::StopGrid'
cls.SUPERCLS = "cocos2d::ActionInstant"
cls.funcs [[
    static cocos2d::StopGrid *create()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ReuseGrid'
cls.SUPERCLS = "cocos2d::ActionInstant"
cls.funcs [[
    static cocos2d::ReuseGrid *create(int times)
    bool initWithTimes(int times)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Waves3D'
cls.SUPERCLS = "cocos2d::Grid3DAction"
cls.funcs [[
    static cocos2d::Waves3D *create(float duration, const cocos2d::Size &gridSize, unsigned int waves, float amplitude)
    float getAmplitude()
    void setAmplitude(float amplitude)
]]
cls.props [[
    amplitude
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FlipX3D'
cls.SUPERCLS = "cocos2d::Grid3DAction"
cls.funcs [[
    static cocos2d::FlipX3D *create(float duration)
    bool initWithSize(const cocos2d::Size &gridSize, float duration)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FlipY3D'
cls.SUPERCLS = "cocos2d::FlipX3D"
cls.funcs [[
    static cocos2d::FlipY3D *create(float duration)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Lens3D'
cls.SUPERCLS = "cocos2d::Grid3DAction"
cls.funcs [[
    static cocos2d::Lens3D *create(float duration, const cocos2d::Size &gridSize, const cocos2d::Vec2 &position, float radius)
    float getLensEffect()
    void setLensEffect(float lensEffect)
    void setConcave(bool concave)
    const cocos2d::Vec2 &getPosition()
    void setPosition(const cocos2d::Vec2 &position)
]]
cls.props [[
    lensEffect
    position
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Ripple3D'
cls.SUPERCLS = "cocos2d::Grid3DAction"
cls.funcs [[
    static cocos2d::Ripple3D *create(float duration, const cocos2d::Size &gridSize, const cocos2d::Vec2 &position, float radius, unsigned int waves, float amplitude)
    const cocos2d::Vec2 &getPosition()
    void setPosition(const cocos2d::Vec2 &position)
    float getAmplitude()
    void setAmplitude(float fAmplitude)
]]
cls.props [[
    position
    amplitude
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Shaky3D'
cls.SUPERCLS = "cocos2d::Grid3DAction"
cls.funcs [[
    static cocos2d::Shaky3D *create(float initWithDuration, const cocos2d::Size &gridSize, int range, bool shakeZ)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Liquid'
cls.SUPERCLS = "cocos2d::Grid3DAction"
cls.funcs [[
    static cocos2d::Liquid *create(float duration, const cocos2d::Size &gridSize, unsigned int waves, float amplitude)
    float getAmplitude()
    void setAmplitude(float amplitude)
]]
cls.props [[
    amplitude
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Waves'
cls.SUPERCLS = "cocos2d::Grid3DAction"
cls.funcs [[
    static cocos2d::Waves *create(float duration, const cocos2d::Size &gridSize, unsigned int waves, float amplitude, bool horizontal, bool vertical)
    float getAmplitude()
    void setAmplitude(float amplitude)
]]
cls.props [[
    amplitude
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Twirl'
cls.SUPERCLS = "cocos2d::Grid3DAction"
cls.funcs [[
    static cocos2d::Twirl *create(float duration, const cocos2d::Size &gridSize, const cocos2d::Vec2 &position, unsigned int twirls, float amplitude)
    const cocos2d::Vec2 &getPosition()
    void setPosition(const cocos2d::Vec2 &position)
    float getAmplitude()
    void setAmplitude(float amplitude)
]]
cls.props [[
    position
    amplitude
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PageTurn3D'
cls.SUPERCLS = "cocos2d::Grid3DAction"
cls.funcs [[
    static cocos2d::PageTurn3D *create(float duration, const cocos2d::Size &gridSize)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ShakyTiles3D'
cls.SUPERCLS = "cocos2d::TiledGrid3DAction"
cls.funcs [[
    static cocos2d::ShakyTiles3D *create(float duration, const cocos2d::Size &gridSize, int range, bool shakeZ)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ShatteredTiles3D'
cls.SUPERCLS = "cocos2d::TiledGrid3DAction"
cls.funcs [[
    static cocos2d::ShatteredTiles3D *create(float duration, const cocos2d::Size &gridSize, int range, bool shatterZ)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ShuffleTiles'
cls.SUPERCLS = "cocos2d::TiledGrid3DAction"
cls.funcs [[
    static cocos2d::ShuffleTiles *create(float duration, const cocos2d::Size &gridSize, unsigned int seed)
    cocos2d::Size getDelta(const cocos2d::Size &pos)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FadeOutTRTiles'
cls.SUPERCLS = "cocos2d::TiledGrid3DAction"
cls.funcs [[
    static cocos2d::FadeOutTRTiles *create(float duration, const cocos2d::Size &gridSize)
    float testFunc(const cocos2d::Size &pos, float time)
    void turnOnTile(const cocos2d::Vec2 &pos)
    void turnOffTile(const cocos2d::Vec2 &pos)
    void transformTile(const cocos2d::Vec2 &pos, float distance)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FadeOutBLTiles'
cls.SUPERCLS = "cocos2d::FadeOutTRTiles"
cls.funcs [[
    static cocos2d::FadeOutBLTiles *create(float duration, const cocos2d::Size &gridSize)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FadeOutUpTiles'
cls.SUPERCLS = "cocos2d::FadeOutTRTiles"
cls.funcs [[
    static cocos2d::FadeOutUpTiles *create(float duration, const cocos2d::Size &gridSize)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FadeOutDownTiles'
cls.SUPERCLS = "cocos2d::FadeOutUpTiles"
cls.funcs [[
    static cocos2d::FadeOutDownTiles *create(float duration, const cocos2d::Size &gridSize)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TurnOffTiles'
cls.SUPERCLS = "cocos2d::TiledGrid3DAction"
cls.funcs [[
    static cocos2d::TurnOffTiles *create(float duration, const cocos2d::Size &gridSize)
    static cocos2d::TurnOffTiles *create(float duration, const cocos2d::Size &gridSize, unsigned int seed)
    void turnOnTile(const cocos2d::Vec2 &pos)
    void turnOffTile(const cocos2d::Vec2 &pos)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::WavesTiles3D'
cls.SUPERCLS = "cocos2d::TiledGrid3DAction"
cls.funcs [[
    static cocos2d::WavesTiles3D *create(float duration, const cocos2d::Size &gridSize, unsigned int waves, float amplitude)
    float getAmplitude()
    void setAmplitude(float amplitude)
]]
cls.props [[
    amplitude
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::JumpTiles3D'
cls.SUPERCLS = "cocos2d::TiledGrid3DAction"
cls.funcs [[
    static cocos2d::JumpTiles3D *create(float duration, const cocos2d::Size &gridSize, unsigned int numberOfJumps, float amplitude)
    float getAmplitude()
    void setAmplitude(float amplitude)
]]
cls.props [[
    amplitude
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::SplitRows'
cls.SUPERCLS = "cocos2d::TiledGrid3DAction"
cls.funcs [[
    static cocos2d::SplitRows *create(float duration, unsigned int rows)
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::SplitCols'
cls.SUPERCLS = "cocos2d::TiledGrid3DAction"
cls.funcs [[
    static cocos2d::SplitCols *create(float duration, unsigned int cols)
]]
M.CLASSES[#M.CLASSES + 1] = cls

return M
