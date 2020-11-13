-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/cocos2d-action-types.lua"

local olua = require "olua"
local typeconv = olua.typeconv
local typecls = olua.typecls
local cls = nil
local M = {}

M.NAME = "cocos2d_action"
M.PATH = "../../frameworks/libxgame/src/lua-bindings"
M.INCLUDES = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "lua-bindings/LuaCocosAdapter.h"
    #include "cocos2d.h"
    #include "xgame/xlua.h"
]]
M.CHUNK = nil

M.CONVS = {
}

M.CLASSES = {}

cls = typecls 'cocos2d::Action'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.const('INVALID_TAG', 'cocos2d::Action::INVALID_TAG', 'const int')
cls.func(nil, 'std::string description()')
cls.func(nil, 'cocos2d::Action *clone()')
cls.func(nil, 'cocos2d::Action *reverse()')
cls.func(nil, 'bool isDone()')
cls.func(nil, 'void startWithTarget(cocos2d::Node *target)')
cls.func(nil, 'void stop()')
cls.func(nil, 'void step(float dt)')
cls.func(nil, 'void update(float time)')
cls.func(nil, 'cocos2d::Node *getTarget()')
cls.func(nil, 'void setTarget(cocos2d::Node *target)')
cls.func(nil, 'cocos2d::Node *getOriginalTarget()')
cls.func(nil, 'void setOriginalTarget(cocos2d::Node *originalTarget)')
cls.func(nil, 'int getTag()')
cls.func(nil, 'void setTag(int tag)')
cls.func(nil, 'unsigned int getFlags()')
cls.func(nil, 'void setFlags(unsigned int flags)')
cls.prop('done', nil, nil)
cls.prop('target', nil, nil)
cls.prop('originalTarget', nil, nil)
cls.prop('tag', nil, nil)
cls.prop('flags', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FiniteTimeAction'
cls.SUPERCLS = 'cocos2d::Action'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'float getDuration()')
cls.func(nil, 'void setDuration(float duration)')
cls.prop('duration', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Speed'
cls.SUPERCLS = 'cocos2d::Action'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Speed *create(@addref(innerAction ^) cocos2d::ActionInterval *action, float speed)')
cls.func(nil, 'float getSpeed()')
cls.func(nil, 'void setSpeed(float speed)')
cls.func(nil, 'void setInnerAction(@addref(innerAction ^) cocos2d::ActionInterval *action)')
cls.func(nil, '@addref(innerAction ^) cocos2d::ActionInterval *getInnerAction()')
cls.prop('speed', nil, nil)
cls.prop('innerAction', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Follow'
cls.SUPERCLS = 'cocos2d::Action'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Follow *create(cocos2d::Node *followedNode, @optional const cocos2d::Rect &rect)')
cls.func(nil, 'static cocos2d::Follow *createWithOffset(cocos2d::Node *followedNode, float xOffset, float yOffset, @optional const cocos2d::Rect &rect)')
cls.func(nil, 'bool isBoundarySet()')
cls.func(nil, 'void setBoundarySet(bool value)')
cls.func(nil, 'bool initWithTarget(cocos2d::Node *followedNode, @optional const cocos2d::Rect &rect)')
cls.func(nil, 'bool initWithTargetAndOffset(cocos2d::Node *followedNode, float xOffset, float yOffset, @optional const cocos2d::Rect &rect)')
cls.prop('boundarySet', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::tweenfunc'
cls.SUPERCLS = nil
cls.REG_LUATYPE = false
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static float easeIn(float time, float rate)')
cls.func(nil, 'static float easeOut(float time, float rate)')
cls.func(nil, 'static float easeInOut(float time, float rate)')
cls.func(nil, 'static float bezieratFunction(float a, float b, float c, float d, float t)')
cls.func(nil, 'static float quadraticIn(float time)')
cls.func(nil, 'static float quadraticOut(float time)')
cls.func(nil, 'static float quadraticInOut(float time)')
cls.func(nil, 'static float linear(float time)')
cls.func(nil, 'static float sineEaseIn(float time)')
cls.func(nil, 'static float sineEaseOut(float time)')
cls.func(nil, 'static float sineEaseInOut(float time)')
cls.func(nil, 'static float quadEaseIn(float time)')
cls.func(nil, 'static float quadEaseOut(float time)')
cls.func(nil, 'static float quadEaseInOut(float time)')
cls.func(nil, 'static float cubicEaseIn(float time)')
cls.func(nil, 'static float cubicEaseOut(float time)')
cls.func(nil, 'static float cubicEaseInOut(float time)')
cls.func(nil, 'static float quartEaseIn(float time)')
cls.func(nil, 'static float quartEaseOut(float time)')
cls.func(nil, 'static float quartEaseInOut(float time)')
cls.func(nil, 'static float quintEaseIn(float time)')
cls.func(nil, 'static float quintEaseOut(float time)')
cls.func(nil, 'static float quintEaseInOut(float time)')
cls.func(nil, 'static float expoEaseIn(float time)')
cls.func(nil, 'static float expoEaseOut(float time)')
cls.func(nil, 'static float expoEaseInOut(float time)')
cls.func(nil, 'static float circEaseIn(float time)')
cls.func(nil, 'static float circEaseOut(float time)')
cls.func(nil, 'static float circEaseInOut(float time)')
cls.func(nil, 'static float elasticEaseIn(float time, float period)')
cls.func(nil, 'static float elasticEaseOut(float time, float period)')
cls.func(nil, 'static float elasticEaseInOut(float time, float period)')
cls.func(nil, 'static float backEaseIn(float time)')
cls.func(nil, 'static float backEaseOut(float time)')
cls.func(nil, 'static float backEaseInOut(float time)')
cls.func(nil, 'static float bounceEaseIn(float time)')
cls.func(nil, 'static float bounceEaseOut(float time)')
cls.func(nil, 'static float bounceEaseInOut(float time)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ActionInterval'
cls.SUPERCLS = 'cocos2d::FiniteTimeAction'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'float getElapsed()')
cls.func(nil, 'void setAmplitudeRate(float amp)')
cls.func(nil, 'float getAmplitudeRate()')
cls.prop('elapsed', nil, nil)
cls.prop('amplitudeRate', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ActionTween'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ActionTween *create(float duration, const std::string &key, float from, float to)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Sequence'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Sequence *create(@pack@addref(actions |) const Vector<cocos2d::FiniteTimeAction *> &arrayOfActions)')
cls.func(nil, 'static cocos2d::Sequence *createWithTwoActions(@addref(actions |) cocos2d::FiniteTimeAction *actionOne, @addref(actions |) cocos2d::FiniteTimeAction *actionTwo)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Repeat'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Repeat *create(@addref(innerAction ^) cocos2d::FiniteTimeAction *action, unsigned int times)')
cls.func(nil, 'void setInnerAction(@addref(innerAction ^) cocos2d::FiniteTimeAction *action)')
cls.func(nil, '@addref(innerAction ^) cocos2d::FiniteTimeAction *getInnerAction()')
cls.prop('innerAction', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::RepeatForever'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::RepeatForever *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
cls.func(nil, 'void setInnerAction(@addref(innerAction ^) cocos2d::ActionInterval *action)')
cls.func(nil, '@addref(innerAction ^) cocos2d::ActionInterval *getInnerAction()')
cls.prop('innerAction', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Spawn'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Spawn *create(@pack@addref(actions |) const Vector<cocos2d::FiniteTimeAction *> &arrayOfActions)')
cls.func(nil, 'static cocos2d::Spawn *createWithTwoActions(@addref(actions |) cocos2d::FiniteTimeAction *action1, @addref(actions |) cocos2d::FiniteTimeAction *action2)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::RotateTo'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::RotateTo *create(float duration, float dstAngleX, float dstAngleY)', 'static cocos2d::RotateTo *create(float duration, float dstAngle)', 'static cocos2d::RotateTo *create(float duration, const cocos2d::Vec3 &dstAngle3D)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::RotateFrom'
cls.SUPERCLS = 'cocos2d::RotateTo'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::RotateFrom *create(float duration, float fromAngleX, float fromAngleY)', 'static cocos2d::RotateFrom *create(float duration, float fromAngle)', 'static cocos2d::RotateFrom *create(float duration, const cocos2d::Vec3 &fromAngle3D)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::RotateBy'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::RotateBy *create(float duration, float deltaAngle)', 'static cocos2d::RotateBy *create(float duration, float deltaAngleZ_X, float deltaAngleZ_Y)', 'static cocos2d::RotateBy *create(float duration, const cocos2d::Vec3 &deltaAngle3D)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::MoveBy'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::MoveBy *create(float duration, @pack const cocos2d::Vec2 &deltaPosition)', 'static cocos2d::MoveBy *create(float duration, @pack const cocos2d::Vec3 &deltaPosition)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::MoveTo'
cls.SUPERCLS = 'cocos2d::MoveBy'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::MoveTo *create(float duration, @pack const cocos2d::Vec2 &position)', 'static cocos2d::MoveTo *create(float duration, @pack const cocos2d::Vec3 &position)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::MoveFrom'
cls.SUPERCLS = 'cocos2d::MoveBy'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::MoveFrom *create(float duration, @pack const cocos2d::Vec2 &position)', 'static cocos2d::MoveFrom *create(float duration, @pack const cocos2d::Vec3 &position)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::SkewTo'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::SkewTo *create(float t, float sx, float sy)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::SkewBy'
cls.SUPERCLS = 'cocos2d::SkewTo'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::SkewBy *create(float t, float deltaSkewX, float deltaSkewY)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ResizeTo'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ResizeTo *create(float duration, const cocos2d::Size &final_size)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ResizeBy'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ResizeBy *create(float duration, const cocos2d::Size &deltaSize)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::BezierBy'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::BezierBy *create(float t, @pack const cocos2d::ccBezierConfig &c)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::BezierTo'
cls.SUPERCLS = 'cocos2d::BezierBy'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::BezierTo *create(float t, @pack const cocos2d::ccBezierConfig &c)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::JumpBy'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::JumpBy *create(float duration, @pack const cocos2d::Vec2 &position, float height, int jumps)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::JumpTo'
cls.SUPERCLS = 'cocos2d::JumpBy'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::JumpTo *create(float duration, @pack const cocos2d::Vec2 &position, float height, int jumps)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ScaleTo'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ScaleTo *create(float duration, float s)', 'static cocos2d::ScaleTo *create(float duration, float sx, float sy)', 'static cocos2d::ScaleTo *create(float duration, float sx, float sy, float sz)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ScaleBy'
cls.SUPERCLS = 'cocos2d::ScaleTo'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ScaleBy *create(float duration, float s)', 'static cocos2d::ScaleBy *create(float duration, float sx, float sy)', 'static cocos2d::ScaleBy *create(float duration, float sx, float sy, float sz)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ScaleFrom'
cls.SUPERCLS = 'cocos2d::ScaleTo'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ScaleFrom *create(float duration, float s)', 'static cocos2d::ScaleFrom *create(float duration, float sx, float sy)', 'static cocos2d::ScaleFrom *create(float duration, float sx, float sy, float sz)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Blink'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Blink *create(float duration, int blinks)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FadeTo'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::FadeTo *create(float duration, uint8_t opacity)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FadeFrom'
cls.SUPERCLS = 'cocos2d::FadeTo'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::FadeFrom *create(float d, uint8_t opacity)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FadeIn'
cls.SUPERCLS = 'cocos2d::FadeTo'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::FadeIn *create(float d)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FadeOut'
cls.SUPERCLS = 'cocos2d::FadeTo'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::FadeOut *create(float d)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TintTo'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TintTo *create(float duration, uint8_t red, uint8_t green, uint8_t blue)', 'static cocos2d::TintTo *create(float duration, const cocos2d::Color3B &color)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TintBy'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TintBy *create(float duration, int16_t deltaRed, int16_t deltaGreen, int16_t deltaBlue)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::DelayTime'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::DelayTime *create(float d)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ReverseTime'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ReverseTime *create(@addref(actions |) cocos2d::FiniteTimeAction *action)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Animate'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Animate *create(cocos2d::Animation *animation)')
cls.func(nil, 'void setAnimation(cocos2d::Animation *animation)')
cls.func(nil, 'cocos2d::Animation *getAnimation()')
cls.func(nil, 'int getCurrentFrameIndex()')
cls.prop('animation', nil, nil)
cls.prop('currentFrameIndex', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TargetedAction'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TargetedAction *create(cocos2d::Node *target, @addref(actions |) cocos2d::FiniteTimeAction *action)')
cls.func(nil, 'void setForcedTarget(cocos2d::Node *forcedTarget)')
cls.func(nil, 'cocos2d::Node *getForcedTarget()')
cls.func(nil, 'bool initWithTarget(cocos2d::Node *target, cocos2d::FiniteTimeAction *action)')
cls.prop('forcedTarget', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ActionFloat'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
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
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ProgressTo *create(float duration, float percent)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ProgressFromTo'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ProgressFromTo *create(float duration, float fromPercentage, float toPercentage)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ActionEase'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, '@addref(innerAction ^) cocos2d::ActionInterval *getInnerAction()')
cls.prop('innerAction', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseRateAction'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseRateAction *create(@addref(innerAction ^) cocos2d::ActionInterval *action, float rate)')
cls.func(nil, 'void setRate(float rate)')
cls.func(nil, 'float getRate()')
cls.prop('rate', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseExponentialIn'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseExponentialIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseExponentialOut'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseExponentialOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseExponentialInOut'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseExponentialInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseSineIn'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseSineIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseSineOut'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseSineOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseSineInOut'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseSineInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseBounceIn'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseBounceIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseBounceOut'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseBounceOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseBounceInOut'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseBounceInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseBackIn'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseBackIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseBackOut'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseBackOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseBackInOut'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseBackInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseQuadraticActionIn'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseQuadraticActionIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseQuadraticActionOut'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseQuadraticActionOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseQuadraticActionInOut'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseQuadraticActionInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseQuarticActionIn'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseQuarticActionIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseQuarticActionOut'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseQuarticActionOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseQuarticActionInOut'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseQuarticActionInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseQuinticActionIn'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseQuinticActionIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseQuinticActionOut'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseQuinticActionOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseQuinticActionInOut'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseQuinticActionInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseCircleActionIn'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseCircleActionIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseCircleActionOut'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseCircleActionOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseCircleActionInOut'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseCircleActionInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseCubicActionIn'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseCubicActionIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseCubicActionOut'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseCubicActionOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseCubicActionInOut'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseCubicActionInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseIn'
cls.SUPERCLS = 'cocos2d::EaseRateAction'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action, float rate)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseOut'
cls.SUPERCLS = 'cocos2d::EaseRateAction'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, float rate)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseInOut'
cls.SUPERCLS = 'cocos2d::EaseRateAction'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, float rate)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseElastic'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'float getPeriod()')
cls.func(nil, 'void setPeriod(float fPeriod)')
cls.prop('period', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseElasticIn'
cls.SUPERCLS = 'cocos2d::EaseElastic'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseElasticIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseElasticOut'
cls.SUPERCLS = 'cocos2d::EaseElastic'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseElasticOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseElasticInOut'
cls.SUPERCLS = 'cocos2d::EaseElastic'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseElasticInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::EaseBezierAction'
cls.SUPERCLS = 'cocos2d::ActionEase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::EaseBezierAction *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
cls.func(nil, 'void setBezierParamer(float p0, float p1, float p2, float p3)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PointArray'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::PointArray *create(ssize_t capacity)')
cls.func(nil, 'bool initWithCapacity(ssize_t capacity)')
cls.func(nil, 'void addControlPoint(const cocos2d::Vec2 &controlPoint)')
cls.func(nil, 'void insertControlPoint(const cocos2d::Vec2 &controlPoint, ssize_t index)')
cls.func(nil, 'void replaceControlPoint(const cocos2d::Vec2 &controlPoint, ssize_t index)')
cls.func(nil, 'const cocos2d::Vec2 &getControlPointAtIndex(ssize_t index)')
cls.func(nil, 'void removeControlPointAtIndex(ssize_t index)')
cls.func(nil, 'ssize_t count()')
cls.func(nil, 'cocos2d::PointArray *reverse()')
cls.func(nil, 'void reverseInline()')
cls.func(nil, 'cocos2d::PointArray *clone()')
cls.func(nil, 'const std::vector<Vec2> &getControlPoints()')
cls.func(nil, 'void setControlPoints(std::vector<Vec2> controlPoints)')
cls.prop('controlPoints', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CardinalSplineTo'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::CardinalSplineTo *create(float duration, cocos2d::PointArray *points, float tension)')
cls.func(nil, 'void updatePosition(const cocos2d::Vec2 &newPos)')
cls.func(nil, 'cocos2d::PointArray *getPoints()')
cls.func(nil, 'void setPoints(cocos2d::PointArray *points)')
cls.prop('points', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CardinalSplineBy'
cls.SUPERCLS = 'cocos2d::CardinalSplineTo'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::CardinalSplineBy *create(float duration, cocos2d::PointArray *points, float tension)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CatmullRomTo'
cls.SUPERCLS = 'cocos2d::CardinalSplineTo'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::CatmullRomTo *create(float dt, cocos2d::PointArray *points)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CatmullRomBy'
cls.SUPERCLS = 'cocos2d::CardinalSplineBy'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::CatmullRomBy *create(float dt, cocos2d::PointArray *points)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ActionInstant'
cls.SUPERCLS = 'cocos2d::FiniteTimeAction'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Show'
cls.SUPERCLS = 'cocos2d::ActionInstant'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Show *create()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Hide'
cls.SUPERCLS = 'cocos2d::ActionInstant'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Hide *create()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ToggleVisibility'
cls.SUPERCLS = 'cocos2d::ActionInstant'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ToggleVisibility *create()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::RemoveSelf'
cls.SUPERCLS = 'cocos2d::ActionInstant'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::RemoveSelf *create(@optional bool isNeedCleanUp)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FlipX'
cls.SUPERCLS = 'cocos2d::ActionInstant'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::FlipX *create(bool x)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FlipY'
cls.SUPERCLS = 'cocos2d::ActionInstant'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::FlipY *create(bool y)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Place'
cls.SUPERCLS = 'cocos2d::ActionInstant'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Place *create(const cocos2d::Vec2 &pos)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::CallFunc'
cls.SUPERCLS = 'cocos2d::ActionInstant'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'void execute()')
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
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'void setEye(const cocos2d::Vec3 &eye)', 'void setEye(float x, float y, float z)')
cls.func(nil, 'const cocos2d::Vec3 &getEye()')
cls.func(nil, 'void setCenter(const cocos2d::Vec3 &center)')
cls.func(nil, 'const cocos2d::Vec3 &getCenter()')
cls.func(nil, 'void setUp(const cocos2d::Vec3 &up)')
cls.func(nil, 'const cocos2d::Vec3 &getUp()')
cls.prop('eye', nil, nil)
cls.prop('center', nil, nil)
cls.prop('up', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::OrbitCamera'
cls.SUPERCLS = 'cocos2d::ActionCamera'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::OrbitCamera *create(float t, float radius, float deltaRadius, float angleZ, float deltaAngleZ, float angleX, float deltaAngleX)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::GridBase'
cls.SUPERCLS = 'cocos2d::Ref'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'void beforeBlit()')
cls.func(nil, 'void afterBlit()')
cls.func(nil, 'void blit()')
cls.func(nil, 'void reuse()')
cls.func(nil, 'void calculateVertexPoints()')
cls.func(nil, 'bool initWithSize(const cocos2d::Size &gridSize)', 'bool initWithSize(const cocos2d::Size &gridSize, const cocos2d::Rect &rect)', 'bool initWithSize(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped)', 'bool initWithSize(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped, const cocos2d::Rect &rect)')
cls.func(nil, 'bool isActive()')
cls.func(nil, 'void setActive(bool active)')
cls.func(nil, 'int getReuseGrid()')
cls.func(nil, 'void setReuseGrid(int reuseGrid)')
cls.func(nil, 'const cocos2d::Size &getGridSize()')
cls.func(nil, 'void setGridSize(const cocos2d::Size &gridSize)')
cls.func(nil, 'const cocos2d::Vec2 &getStep()')
cls.func(nil, 'void setStep(const cocos2d::Vec2 &step)')
cls.func(nil, 'bool isTextureFlipped()')
cls.func(nil, 'void setTextureFlipped(bool flipped)')
cls.func(nil, 'void beforeDraw()')
cls.func(nil, 'void afterDraw(cocos2d::Node *target)')
cls.func(nil, 'void set2DProjection()')
cls.func(nil, 'void setGridRect(const cocos2d::Rect &rect)')
cls.func(nil, 'const cocos2d::Rect &getGridRect()')
cls.prop('active', nil, nil)
cls.prop('reuseGrid', nil, nil)
cls.prop('gridSize', nil, nil)
cls.prop('step', nil, nil)
cls.prop('textureFlipped', nil, nil)
cls.prop('gridRect', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Grid3D'
cls.SUPERCLS = 'cocos2d::GridBase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Grid3D *create(const cocos2d::Size &gridSize)', 'static cocos2d::Grid3D *create(const cocos2d::Size &gridSize, const cocos2d::Rect &rect)', 'static cocos2d::Grid3D *create(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped)', 'static cocos2d::Grid3D *create(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped, const cocos2d::Rect &rect)')
cls.func(nil, 'cocos2d::Vec3 getVertex(const cocos2d::Vec2 &pos)')
cls.func(nil, 'cocos2d::Vec3 getOriginalVertex(const cocos2d::Vec2 &pos)')
cls.func(nil, 'void setVertex(const cocos2d::Vec2 &pos, const cocos2d::Vec3 &vertex)')
cls.func(nil, 'void setNeedDepthTestForBlit(bool neededDepthTest)')
cls.func(nil, 'bool getNeedDepthTestForBlit()')
cls.prop('needDepthTestForBlit', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TiledGrid3D'
cls.SUPERCLS = 'cocos2d::GridBase'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TiledGrid3D *create(const cocos2d::Size &gridSize)', 'static cocos2d::TiledGrid3D *create(const cocos2d::Size &gridSize, const cocos2d::Rect &rect)', 'static cocos2d::TiledGrid3D *create(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped)', 'static cocos2d::TiledGrid3D *create(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped, const cocos2d::Rect &rect)')
cls.func(nil, 'cocos2d::Quad3 getTile(const cocos2d::Vec2 &pos)')
cls.func(nil, 'cocos2d::Quad3 getOriginalTile(const cocos2d::Vec2 &pos)')
cls.func(nil, 'void setTile(const cocos2d::Vec2 &pos, const cocos2d::Quad3 &coords)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::NodeGrid'
cls.SUPERCLS = 'cocos2d::Node'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::NodeGrid *create()', 'static cocos2d::NodeGrid *create(const cocos2d::Rect &rect)')
cls.func(nil, 'cocos2d::GridBase *getGrid()')
cls.func(nil, 'void setGrid(cocos2d::GridBase *grid)')
cls.func(nil, 'void setTarget(cocos2d::Node *target)')
cls.func(nil, 'void setGridRect(const cocos2d::Rect &gridRect)')
cls.func(nil, 'const cocos2d::Rect &getGridRect()')
cls.prop('grid', nil, nil)
cls.prop('gridRect', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::GridAction'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'cocos2d::GridBase *getGrid()')
cls.prop('grid', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Grid3DAction'
cls.SUPERCLS = 'cocos2d::GridAction'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'cocos2d::Vec3 getVertex(const cocos2d::Vec2 &position)')
cls.func(nil, 'cocos2d::Vec3 getOriginalVertex(const cocos2d::Vec2 &position)')
cls.func(nil, 'void setVertex(const cocos2d::Vec2 &position, const cocos2d::Vec3 &vertex)')
cls.func(nil, 'cocos2d::Rect getGridRect()')
cls.prop('gridRect', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TiledGrid3DAction'
cls.SUPERCLS = 'cocos2d::GridAction'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TiledGrid3DAction *create(float duration, const cocos2d::Size &gridSize)')
cls.func(nil, 'cocos2d::Quad3 getTile(const cocos2d::Vec2 &position)')
cls.func(nil, 'cocos2d::Quad3 getOriginalTile(const cocos2d::Vec2 &position)')
cls.func(nil, 'void setTile(const cocos2d::Vec2 &position, const cocos2d::Quad3 &coords)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::AccelDeccelAmplitude'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::AccelDeccelAmplitude *create(cocos2d::Action *action, float duration)')
cls.func(nil, 'float getRate()')
cls.func(nil, 'void setRate(float rate)')
cls.prop('rate', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::AccelAmplitude'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::AccelAmplitude *create(cocos2d::Action *action, float duration)')
cls.func(nil, 'float getRate()')
cls.func(nil, 'void setRate(float rate)')
cls.prop('rate', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::DeccelAmplitude'
cls.SUPERCLS = 'cocos2d::ActionInterval'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::DeccelAmplitude *create(cocos2d::Action *action, float duration)')
cls.func(nil, 'float getRate()')
cls.func(nil, 'void setRate(float rate)')
cls.prop('rate', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::StopGrid'
cls.SUPERCLS = 'cocos2d::ActionInstant'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::StopGrid *create()')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ReuseGrid'
cls.SUPERCLS = 'cocos2d::ActionInstant'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ReuseGrid *create(int times)')
cls.func(nil, 'bool initWithTimes(int times)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Waves3D'
cls.SUPERCLS = 'cocos2d::Grid3DAction'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Waves3D *create(float duration, const cocos2d::Size &gridSize, unsigned int waves, float amplitude)')
cls.func(nil, 'float getAmplitude()')
cls.func(nil, 'void setAmplitude(float amplitude)')
cls.prop('amplitude', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FlipX3D'
cls.SUPERCLS = 'cocos2d::Grid3DAction'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::FlipX3D *create(float duration)')
cls.func(nil, 'bool initWithSize(const cocos2d::Size &gridSize, float duration)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FlipY3D'
cls.SUPERCLS = 'cocos2d::FlipX3D'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::FlipY3D *create(float duration)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Lens3D'
cls.SUPERCLS = 'cocos2d::Grid3DAction'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Lens3D *create(float duration, const cocos2d::Size &gridSize, const cocos2d::Vec2 &position, float radius)')
cls.func(nil, 'float getLensEffect()')
cls.func(nil, 'void setLensEffect(float lensEffect)')
cls.func(nil, 'void setConcave(bool concave)')
cls.func(nil, 'const cocos2d::Vec2 &getPosition()')
cls.func(nil, 'void setPosition(const cocos2d::Vec2 &position)')
cls.prop('lensEffect', nil, nil)
cls.prop('position', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Ripple3D'
cls.SUPERCLS = 'cocos2d::Grid3DAction'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Ripple3D *create(float duration, const cocos2d::Size &gridSize, const cocos2d::Vec2 &position, float radius, unsigned int waves, float amplitude)')
cls.func(nil, 'const cocos2d::Vec2 &getPosition()')
cls.func(nil, 'void setPosition(const cocos2d::Vec2 &position)')
cls.func(nil, 'float getAmplitude()')
cls.func(nil, 'void setAmplitude(float fAmplitude)')
cls.prop('position', nil, nil)
cls.prop('amplitude', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Shaky3D'
cls.SUPERCLS = 'cocos2d::Grid3DAction'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Shaky3D *create(float initWithDuration, const cocos2d::Size &gridSize, int range, bool shakeZ)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Liquid'
cls.SUPERCLS = 'cocos2d::Grid3DAction'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Liquid *create(float duration, const cocos2d::Size &gridSize, unsigned int waves, float amplitude)')
cls.func(nil, 'float getAmplitude()')
cls.func(nil, 'void setAmplitude(float amplitude)')
cls.prop('amplitude', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Waves'
cls.SUPERCLS = 'cocos2d::Grid3DAction'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Waves *create(float duration, const cocos2d::Size &gridSize, unsigned int waves, float amplitude, bool horizontal, bool vertical)')
cls.func(nil, 'float getAmplitude()')
cls.func(nil, 'void setAmplitude(float amplitude)')
cls.prop('amplitude', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::Twirl'
cls.SUPERCLS = 'cocos2d::Grid3DAction'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::Twirl *create(float duration, const cocos2d::Size &gridSize, const cocos2d::Vec2 &position, unsigned int twirls, float amplitude)')
cls.func(nil, 'const cocos2d::Vec2 &getPosition()')
cls.func(nil, 'void setPosition(const cocos2d::Vec2 &position)')
cls.func(nil, 'float getAmplitude()')
cls.func(nil, 'void setAmplitude(float amplitude)')
cls.prop('position', nil, nil)
cls.prop('amplitude', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::PageTurn3D'
cls.SUPERCLS = 'cocos2d::Grid3DAction'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::PageTurn3D *create(float duration, const cocos2d::Size &gridSize)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ShakyTiles3D'
cls.SUPERCLS = 'cocos2d::TiledGrid3DAction'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ShakyTiles3D *create(float duration, const cocos2d::Size &gridSize, int range, bool shakeZ)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ShatteredTiles3D'
cls.SUPERCLS = 'cocos2d::TiledGrid3DAction'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ShatteredTiles3D *create(float duration, const cocos2d::Size &gridSize, int range, bool shatterZ)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::ShuffleTiles'
cls.SUPERCLS = 'cocos2d::TiledGrid3DAction'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::ShuffleTiles *create(float duration, const cocos2d::Size &gridSize, unsigned int seed)')
cls.func(nil, 'cocos2d::Size getDelta(const cocos2d::Size &pos)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FadeOutTRTiles'
cls.SUPERCLS = 'cocos2d::TiledGrid3DAction'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::FadeOutTRTiles *create(float duration, const cocos2d::Size &gridSize)')
cls.func(nil, 'float testFunc(const cocos2d::Size &pos, float time)')
cls.func(nil, 'void turnOnTile(const cocos2d::Vec2 &pos)')
cls.func(nil, 'void turnOffTile(const cocos2d::Vec2 &pos)')
cls.func(nil, 'void transformTile(const cocos2d::Vec2 &pos, float distance)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FadeOutBLTiles'
cls.SUPERCLS = 'cocos2d::FadeOutTRTiles'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::FadeOutBLTiles *create(float duration, const cocos2d::Size &gridSize)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FadeOutUpTiles'
cls.SUPERCLS = 'cocos2d::FadeOutTRTiles'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::FadeOutUpTiles *create(float duration, const cocos2d::Size &gridSize)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::FadeOutDownTiles'
cls.SUPERCLS = 'cocos2d::FadeOutUpTiles'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::FadeOutDownTiles *create(float duration, const cocos2d::Size &gridSize)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::TurnOffTiles'
cls.SUPERCLS = 'cocos2d::TiledGrid3DAction'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::TurnOffTiles *create(float duration, const cocos2d::Size &gridSize)', 'static cocos2d::TurnOffTiles *create(float duration, const cocos2d::Size &gridSize, unsigned int seed)')
cls.func(nil, 'void turnOnTile(const cocos2d::Vec2 &pos)')
cls.func(nil, 'void turnOffTile(const cocos2d::Vec2 &pos)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::WavesTiles3D'
cls.SUPERCLS = 'cocos2d::TiledGrid3DAction'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::WavesTiles3D *create(float duration, const cocos2d::Size &gridSize, unsigned int waves, float amplitude)')
cls.func(nil, 'float getAmplitude()')
cls.func(nil, 'void setAmplitude(float amplitude)')
cls.prop('amplitude', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::JumpTiles3D'
cls.SUPERCLS = 'cocos2d::TiledGrid3DAction'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::JumpTiles3D *create(float duration, const cocos2d::Size &gridSize, unsigned int numberOfJumps, float amplitude)')
cls.func(nil, 'float getAmplitude()')
cls.func(nil, 'void setAmplitude(float amplitude)')
cls.prop('amplitude', nil, nil)
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::SplitRows'
cls.SUPERCLS = 'cocos2d::TiledGrid3DAction'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::SplitRows *create(float duration, unsigned int rows)')
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'cocos2d::SplitCols'
cls.SUPERCLS = 'cocos2d::TiledGrid3DAction'
cls.REG_LUATYPE = true
cls.DEFIF = nil
cls.CHUNK = nil
cls.func(nil, 'static cocos2d::SplitCols *create(float duration, unsigned int cols)')
M.CLASSES[#M.CLASSES + 1] = cls

return M
