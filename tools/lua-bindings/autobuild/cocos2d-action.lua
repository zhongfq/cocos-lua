-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/cocos2d-action-types.lua"

NAME = "cocos2d_action"
PATH = "../../frameworks/libxgame/src/lua-bindings"
HEADERS = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "lua-bindings/LuaCocosAdapter.h"
    #include "cocos2d.h"
    #include "cclua/xlua.h"
]]
CHUNK = nil


typeconf 'cocos2d::tweenfunc::TweenType'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('CUSTOM_EASING', 'cocos2d::tweenfunc::TweenType::CUSTOM_EASING')
    .enum('Linear', 'cocos2d::tweenfunc::TweenType::Linear')
    .enum('Sine_EaseIn', 'cocos2d::tweenfunc::TweenType::Sine_EaseIn')
    .enum('Sine_EaseOut', 'cocos2d::tweenfunc::TweenType::Sine_EaseOut')
    .enum('Sine_EaseInOut', 'cocos2d::tweenfunc::TweenType::Sine_EaseInOut')
    .enum('Quad_EaseIn', 'cocos2d::tweenfunc::TweenType::Quad_EaseIn')
    .enum('Quad_EaseOut', 'cocos2d::tweenfunc::TweenType::Quad_EaseOut')
    .enum('Quad_EaseInOut', 'cocos2d::tweenfunc::TweenType::Quad_EaseInOut')
    .enum('Cubic_EaseIn', 'cocos2d::tweenfunc::TweenType::Cubic_EaseIn')
    .enum('Cubic_EaseOut', 'cocos2d::tweenfunc::TweenType::Cubic_EaseOut')
    .enum('Cubic_EaseInOut', 'cocos2d::tweenfunc::TweenType::Cubic_EaseInOut')
    .enum('Quart_EaseIn', 'cocos2d::tweenfunc::TweenType::Quart_EaseIn')
    .enum('Quart_EaseOut', 'cocos2d::tweenfunc::TweenType::Quart_EaseOut')
    .enum('Quart_EaseInOut', 'cocos2d::tweenfunc::TweenType::Quart_EaseInOut')
    .enum('Quint_EaseIn', 'cocos2d::tweenfunc::TweenType::Quint_EaseIn')
    .enum('Quint_EaseOut', 'cocos2d::tweenfunc::TweenType::Quint_EaseOut')
    .enum('Quint_EaseInOut', 'cocos2d::tweenfunc::TweenType::Quint_EaseInOut')
    .enum('Expo_EaseIn', 'cocos2d::tweenfunc::TweenType::Expo_EaseIn')
    .enum('Expo_EaseOut', 'cocos2d::tweenfunc::TweenType::Expo_EaseOut')
    .enum('Expo_EaseInOut', 'cocos2d::tweenfunc::TweenType::Expo_EaseInOut')
    .enum('Circ_EaseIn', 'cocos2d::tweenfunc::TweenType::Circ_EaseIn')
    .enum('Circ_EaseOut', 'cocos2d::tweenfunc::TweenType::Circ_EaseOut')
    .enum('Circ_EaseInOut', 'cocos2d::tweenfunc::TweenType::Circ_EaseInOut')
    .enum('Elastic_EaseIn', 'cocos2d::tweenfunc::TweenType::Elastic_EaseIn')
    .enum('Elastic_EaseOut', 'cocos2d::tweenfunc::TweenType::Elastic_EaseOut')
    .enum('Elastic_EaseInOut', 'cocos2d::tweenfunc::TweenType::Elastic_EaseInOut')
    .enum('Back_EaseIn', 'cocos2d::tweenfunc::TweenType::Back_EaseIn')
    .enum('Back_EaseOut', 'cocos2d::tweenfunc::TweenType::Back_EaseOut')
    .enum('Back_EaseInOut', 'cocos2d::tweenfunc::TweenType::Back_EaseInOut')
    .enum('Bounce_EaseIn', 'cocos2d::tweenfunc::TweenType::Bounce_EaseIn')
    .enum('Bounce_EaseOut', 'cocos2d::tweenfunc::TweenType::Bounce_EaseOut')
    .enum('Bounce_EaseInOut', 'cocos2d::tweenfunc::TweenType::Bounce_EaseInOut')
    .enum('TWEEN_EASING_MAX', 'cocos2d::tweenfunc::TweenType::TWEEN_EASING_MAX')

typeconf 'cocos2d::Action'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .const('INVALID_TAG', 'cocos2d::Action::INVALID_TAG', 'const int')
    .func(nil, 'std::string description()')
    .func(nil, 'cocos2d::Action *clone()')
    .func(nil, 'cocos2d::Action *reverse()')
    .func(nil, 'bool isDone()')
    .func(nil, 'void startWithTarget(cocos2d::Node *target)')
    .func(nil, 'void stop()')
    .func(nil, 'void step(float dt)')
    .func(nil, 'void update(float time)')
    .func(nil, 'cocos2d::Node *getTarget()')
    .func(nil, 'void setTarget(cocos2d::Node *target)')
    .func(nil, 'cocos2d::Node *getOriginalTarget()')
    .func(nil, 'void setOriginalTarget(cocos2d::Node *originalTarget)')
    .func(nil, 'int getTag()')
    .func(nil, 'void setTag(int tag)')
    .func(nil, 'unsigned int getFlags()')
    .func(nil, 'void setFlags(unsigned int flags)')
    .prop('done', nil, nil)
    .prop('target', nil, nil)
    .prop('originalTarget', nil, nil)
    .prop('tag', nil, nil)
    .prop('flags', nil, nil)

typeconf 'cocos2d::FiniteTimeAction'
    .supercls('cocos2d::Action')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'float getDuration()')
    .func(nil, 'void setDuration(float duration)')
    .prop('duration', nil, nil)

typeconf 'cocos2d::Speed'
    .supercls('cocos2d::Action')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::Speed *create(@addref(innerAction ^) cocos2d::ActionInterval *action, float speed)')
    .func(nil, 'float getSpeed()')
    .func(nil, 'void setSpeed(float speed)')
    .func(nil, 'void setInnerAction(@addref(innerAction ^) cocos2d::ActionInterval *action)')
    .func(nil, '@addref(innerAction ^) cocos2d::ActionInterval *getInnerAction()')
    .prop('speed', nil, nil)
    .prop('innerAction', nil, nil)

typeconf 'cocos2d::Follow'
    .supercls('cocos2d::Action')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::Follow *create(cocos2d::Node *followedNode, @optional const cocos2d::Rect &rect)')
    .func(nil, 'static cocos2d::Follow *createWithOffset(cocos2d::Node *followedNode, float xOffset, float yOffset, @optional const cocos2d::Rect &rect)')
    .func(nil, 'bool isBoundarySet()')
    .func(nil, 'void setBoundarySet(bool value)')
    .func(nil, 'bool initWithTarget(cocos2d::Node *followedNode, @optional const cocos2d::Rect &rect)')
    .func(nil, 'bool initWithTargetAndOffset(cocos2d::Node *followedNode, float xOffset, float yOffset, @optional const cocos2d::Rect &rect)')
    .prop('boundarySet', nil, nil)

typeconf 'cocos2d::tweenfunc'
    .supercls(nil)
    .reg_luatype(false)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static float easeIn(float time, float rate)')
    .func(nil, 'static float easeOut(float time, float rate)')
    .func(nil, 'static float easeInOut(float time, float rate)')
    .func(nil, 'static float bezieratFunction(float a, float b, float c, float d, float t)')
    .func(nil, 'static float quadraticIn(float time)')
    .func(nil, 'static float quadraticOut(float time)')
    .func(nil, 'static float quadraticInOut(float time)')
    .func(nil, 'static float linear(float time)')
    .func(nil, 'static float sineEaseIn(float time)')
    .func(nil, 'static float sineEaseOut(float time)')
    .func(nil, 'static float sineEaseInOut(float time)')
    .func(nil, 'static float quadEaseIn(float time)')
    .func(nil, 'static float quadEaseOut(float time)')
    .func(nil, 'static float quadEaseInOut(float time)')
    .func(nil, 'static float cubicEaseIn(float time)')
    .func(nil, 'static float cubicEaseOut(float time)')
    .func(nil, 'static float cubicEaseInOut(float time)')
    .func(nil, 'static float quartEaseIn(float time)')
    .func(nil, 'static float quartEaseOut(float time)')
    .func(nil, 'static float quartEaseInOut(float time)')
    .func(nil, 'static float quintEaseIn(float time)')
    .func(nil, 'static float quintEaseOut(float time)')
    .func(nil, 'static float quintEaseInOut(float time)')
    .func(nil, 'static float expoEaseIn(float time)')
    .func(nil, 'static float expoEaseOut(float time)')
    .func(nil, 'static float expoEaseInOut(float time)')
    .func(nil, 'static float circEaseIn(float time)')
    .func(nil, 'static float circEaseOut(float time)')
    .func(nil, 'static float circEaseInOut(float time)')
    .func(nil, 'static float elasticEaseIn(float time, float period)')
    .func(nil, 'static float elasticEaseOut(float time, float period)')
    .func(nil, 'static float elasticEaseInOut(float time, float period)')
    .func(nil, 'static float backEaseIn(float time)')
    .func(nil, 'static float backEaseOut(float time)')
    .func(nil, 'static float backEaseInOut(float time)')
    .func(nil, 'static float bounceEaseIn(float time)')
    .func(nil, 'static float bounceEaseOut(float time)')
    .func(nil, 'static float bounceEaseInOut(float time)')

typeconf 'cocos2d::ActionInterval'
    .supercls('cocos2d::FiniteTimeAction')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'float getElapsed()')
    .func(nil, 'void setAmplitudeRate(float amp)')
    .func(nil, 'float getAmplitudeRate()')
    .prop('elapsed', nil, nil)
    .prop('amplitudeRate', nil, nil)

typeconf 'cocos2d::ActionTween'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ActionTween *create(float duration, const std::string &key, float from, float to)')

typeconf 'cocos2d::Sequence'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::Sequence *create(@pack@addref(actions |) const Vector<cocos2d::FiniteTimeAction *> &arrayOfActions)')
    .func(nil, 'static cocos2d::Sequence *createWithTwoActions(@addref(actions |) cocos2d::FiniteTimeAction *actionOne, @addref(actions |) cocos2d::FiniteTimeAction *actionTwo)')

typeconf 'cocos2d::Repeat'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::Repeat *create(@addref(innerAction ^) cocos2d::FiniteTimeAction *action, unsigned int times)')
    .func(nil, 'void setInnerAction(@addref(innerAction ^) cocos2d::FiniteTimeAction *action)')
    .func(nil, '@addref(innerAction ^) cocos2d::FiniteTimeAction *getInnerAction()')
    .prop('innerAction', nil, nil)

typeconf 'cocos2d::RepeatForever'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::RepeatForever *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
    .func(nil, 'void setInnerAction(@addref(innerAction ^) cocos2d::ActionInterval *action)')
    .func(nil, '@addref(innerAction ^) cocos2d::ActionInterval *getInnerAction()')
    .prop('innerAction', nil, nil)

typeconf 'cocos2d::Spawn'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::Spawn *create(@pack@addref(actions |) const Vector<cocos2d::FiniteTimeAction *> &arrayOfActions)')
    .func(nil, 'static cocos2d::Spawn *createWithTwoActions(@addref(actions |) cocos2d::FiniteTimeAction *action1, @addref(actions |) cocos2d::FiniteTimeAction *action2)')

typeconf 'cocos2d::RotateTo'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::RotateTo *create(float duration, float dstAngleX, float dstAngleY)', 'static cocos2d::RotateTo *create(float duration, float dstAngle)', 'static cocos2d::RotateTo *create(float duration, const cocos2d::Vec3 &dstAngle3D)')

typeconf 'cocos2d::RotateFrom'
    .supercls('cocos2d::RotateTo')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::RotateFrom *create(float duration, float fromAngleX, float fromAngleY)', 'static cocos2d::RotateFrom *create(float duration, float fromAngle)', 'static cocos2d::RotateFrom *create(float duration, const cocos2d::Vec3 &fromAngle3D)')

typeconf 'cocos2d::RotateBy'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::RotateBy *create(float duration, float deltaAngle)', 'static cocos2d::RotateBy *create(float duration, float deltaAngleZ_X, float deltaAngleZ_Y)', 'static cocos2d::RotateBy *create(float duration, const cocos2d::Vec3 &deltaAngle3D)')

typeconf 'cocos2d::MoveBy'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::MoveBy *create(float duration, @pack const cocos2d::Vec2 &deltaPosition)', 'static cocos2d::MoveBy *create(float duration, @pack const cocos2d::Vec3 &deltaPosition)')

typeconf 'cocos2d::MoveTo'
    .supercls('cocos2d::MoveBy')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::MoveTo *create(float duration, @pack const cocos2d::Vec2 &position)', 'static cocos2d::MoveTo *create(float duration, @pack const cocos2d::Vec3 &position)')

typeconf 'cocos2d::MoveFrom'
    .supercls('cocos2d::MoveBy')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::MoveFrom *create(float duration, @pack const cocos2d::Vec2 &position)', 'static cocos2d::MoveFrom *create(float duration, @pack const cocos2d::Vec3 &position)')

typeconf 'cocos2d::SkewTo'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::SkewTo *create(float t, float sx, float sy)')

typeconf 'cocos2d::SkewBy'
    .supercls('cocos2d::SkewTo')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::SkewBy *create(float t, float deltaSkewX, float deltaSkewY)')

typeconf 'cocos2d::ResizeTo'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ResizeTo *create(float duration, const cocos2d::Size &final_size)')

typeconf 'cocos2d::ResizeBy'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ResizeBy *create(float duration, const cocos2d::Size &deltaSize)')

typeconf 'cocos2d::BezierBy'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::BezierBy *create(float t, @pack const cocos2d::ccBezierConfig &c)')

typeconf 'cocos2d::BezierTo'
    .supercls('cocos2d::BezierBy')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::BezierTo *create(float t, @pack const cocos2d::ccBezierConfig &c)')

typeconf 'cocos2d::JumpBy'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::JumpBy *create(float duration, @pack const cocos2d::Vec2 &position, float height, int jumps)')

typeconf 'cocos2d::JumpTo'
    .supercls('cocos2d::JumpBy')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::JumpTo *create(float duration, @pack const cocos2d::Vec2 &position, float height, int jumps)')

typeconf 'cocos2d::ScaleTo'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ScaleTo *create(float duration, float s)', 'static cocos2d::ScaleTo *create(float duration, float sx, float sy)', 'static cocos2d::ScaleTo *create(float duration, float sx, float sy, float sz)')

typeconf 'cocos2d::ScaleBy'
    .supercls('cocos2d::ScaleTo')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ScaleBy *create(float duration, float s)', 'static cocos2d::ScaleBy *create(float duration, float sx, float sy)', 'static cocos2d::ScaleBy *create(float duration, float sx, float sy, float sz)')

typeconf 'cocos2d::ScaleFrom'
    .supercls('cocos2d::ScaleTo')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ScaleFrom *create(float duration, float s)', 'static cocos2d::ScaleFrom *create(float duration, float sx, float sy)', 'static cocos2d::ScaleFrom *create(float duration, float sx, float sy, float sz)')

typeconf 'cocos2d::Blink'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::Blink *create(float duration, int blinks)')

typeconf 'cocos2d::FadeTo'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::FadeTo *create(float duration, uint8_t opacity)')

typeconf 'cocos2d::FadeFrom'
    .supercls('cocos2d::FadeTo')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::FadeFrom *create(float d, uint8_t opacity)')

typeconf 'cocos2d::FadeIn'
    .supercls('cocos2d::FadeTo')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::FadeIn *create(float d)')

typeconf 'cocos2d::FadeOut'
    .supercls('cocos2d::FadeTo')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::FadeOut *create(float d)')

typeconf 'cocos2d::TintTo'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TintTo *create(float duration, uint8_t red, uint8_t green, uint8_t blue)', 'static cocos2d::TintTo *create(float duration, const cocos2d::Color3B &color)')

typeconf 'cocos2d::TintBy'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TintBy *create(float duration, int16_t deltaRed, int16_t deltaGreen, int16_t deltaBlue)')

typeconf 'cocos2d::DelayTime'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::DelayTime *create(float d)')

typeconf 'cocos2d::ReverseTime'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ReverseTime *create(@addref(actions |) cocos2d::FiniteTimeAction *action)')

typeconf 'cocos2d::Animate'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::Animate *create(cocos2d::Animation *animation)')
    .func(nil, 'void setAnimation(cocos2d::Animation *animation)')
    .func(nil, 'cocos2d::Animation *getAnimation()')
    .func(nil, 'int getCurrentFrameIndex()')
    .prop('animation', nil, nil)
    .prop('currentFrameIndex', nil, nil)

typeconf 'cocos2d::TargetedAction'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TargetedAction *create(cocos2d::Node *target, @addref(actions |) cocos2d::FiniteTimeAction *action)')
    .func(nil, 'void setForcedTarget(cocos2d::Node *forcedTarget)')
    .func(nil, 'cocos2d::Node *getForcedTarget()')
    .func(nil, 'bool initWithTarget(cocos2d::Node *target, cocos2d::FiniteTimeAction *action)')
    .prop('forcedTarget', nil, nil)

typeconf 'cocos2d::ActionFloat::ActionFloatCallback'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)

typeconf 'cocos2d::ActionFloat'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .callback {
        FUNCS =  {
            'static cocos2d::ActionFloat *create(float duration, float from, float to, @local cocos2d::ActionFloat::ActionFloatCallback callback)'
        },
        TAG_MAKER = 'ActionFloat',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_STORE = "return",
        TAG_SCOPE = 'object',
    }

typeconf 'cocos2d::ProgressTo'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ProgressTo *create(float duration, float percent)')

typeconf 'cocos2d::ProgressFromTo'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ProgressFromTo *create(float duration, float fromPercentage, float toPercentage)')

typeconf 'cocos2d::ActionEase'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, '@addref(innerAction ^) cocos2d::ActionInterval *getInnerAction()')
    .prop('innerAction', nil, nil)

typeconf 'cocos2d::EaseRateAction'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseRateAction *create(@addref(innerAction ^) cocos2d::ActionInterval *action, float rate)')
    .func(nil, 'void setRate(float rate)')
    .func(nil, 'float getRate()')
    .prop('rate', nil, nil)

typeconf 'cocos2d::EaseExponentialIn'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseExponentialIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')

typeconf 'cocos2d::EaseExponentialOut'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseExponentialOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')

typeconf 'cocos2d::EaseExponentialInOut'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseExponentialInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')

typeconf 'cocos2d::EaseSineIn'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseSineIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')

typeconf 'cocos2d::EaseSineOut'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseSineOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')

typeconf 'cocos2d::EaseSineInOut'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseSineInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')

typeconf 'cocos2d::EaseBounceIn'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseBounceIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')

typeconf 'cocos2d::EaseBounceOut'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseBounceOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')

typeconf 'cocos2d::EaseBounceInOut'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseBounceInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')

typeconf 'cocos2d::EaseBackIn'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseBackIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')

typeconf 'cocos2d::EaseBackOut'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseBackOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')

typeconf 'cocos2d::EaseBackInOut'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseBackInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')

typeconf 'cocos2d::EaseQuadraticActionIn'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseQuadraticActionIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')

typeconf 'cocos2d::EaseQuadraticActionOut'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseQuadraticActionOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')

typeconf 'cocos2d::EaseQuadraticActionInOut'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseQuadraticActionInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')

typeconf 'cocos2d::EaseQuarticActionIn'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseQuarticActionIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')

typeconf 'cocos2d::EaseQuarticActionOut'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseQuarticActionOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')

typeconf 'cocos2d::EaseQuarticActionInOut'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseQuarticActionInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')

typeconf 'cocos2d::EaseQuinticActionIn'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseQuinticActionIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')

typeconf 'cocos2d::EaseQuinticActionOut'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseQuinticActionOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')

typeconf 'cocos2d::EaseQuinticActionInOut'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseQuinticActionInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')

typeconf 'cocos2d::EaseCircleActionIn'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseCircleActionIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')

typeconf 'cocos2d::EaseCircleActionOut'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseCircleActionOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')

typeconf 'cocos2d::EaseCircleActionInOut'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseCircleActionInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')

typeconf 'cocos2d::EaseCubicActionIn'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseCubicActionIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')

typeconf 'cocos2d::EaseCubicActionOut'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseCubicActionOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')

typeconf 'cocos2d::EaseCubicActionInOut'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseCubicActionInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')

typeconf 'cocos2d::EaseIn'
    .supercls('cocos2d::EaseRateAction')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action, float rate)')

typeconf 'cocos2d::EaseOut'
    .supercls('cocos2d::EaseRateAction')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, float rate)')

typeconf 'cocos2d::EaseInOut'
    .supercls('cocos2d::EaseRateAction')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, float rate)')

typeconf 'cocos2d::EaseElastic'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'float getPeriod()')
    .func(nil, 'void setPeriod(float fPeriod)')
    .prop('period', nil, nil)

typeconf 'cocos2d::EaseElasticIn'
    .supercls('cocos2d::EaseElastic')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseElasticIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)')

typeconf 'cocos2d::EaseElasticOut'
    .supercls('cocos2d::EaseElastic')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseElasticOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)')

typeconf 'cocos2d::EaseElasticInOut'
    .supercls('cocos2d::EaseElastic')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseElasticInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)')

typeconf 'cocos2d::EaseBezierAction'
    .supercls('cocos2d::ActionEase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::EaseBezierAction *create(@addref(innerAction ^) cocos2d::ActionInterval *action)')
    .func(nil, 'void setBezierParamer(float p0, float p1, float p2, float p3)')

typeconf 'cocos2d::PointArray'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::PointArray *create(ssize_t capacity)')
    .func(nil, 'bool initWithCapacity(ssize_t capacity)')
    .func(nil, 'void addControlPoint(const cocos2d::Vec2 &controlPoint)')
    .func(nil, 'void insertControlPoint(const cocos2d::Vec2 &controlPoint, ssize_t index)')
    .func(nil, 'void replaceControlPoint(const cocos2d::Vec2 &controlPoint, ssize_t index)')
    .func(nil, 'const cocos2d::Vec2 &getControlPointAtIndex(ssize_t index)')
    .func(nil, 'void removeControlPointAtIndex(ssize_t index)')
    .func(nil, 'ssize_t count()')
    .func(nil, 'cocos2d::PointArray *reverse()')
    .func(nil, 'void reverseInline()')
    .func(nil, 'cocos2d::PointArray *clone()')
    .func(nil, 'const std::vector<Vec2> &getControlPoints()')
    .func(nil, 'void setControlPoints(std::vector<Vec2> controlPoints)')
    .prop('controlPoints', nil, nil)

typeconf 'cocos2d::CardinalSplineTo'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::CardinalSplineTo *create(float duration, cocos2d::PointArray *points, float tension)')
    .func(nil, 'void updatePosition(const cocos2d::Vec2 &newPos)')
    .func(nil, 'cocos2d::PointArray *getPoints()')
    .func(nil, 'void setPoints(cocos2d::PointArray *points)')
    .prop('points', nil, nil)

typeconf 'cocos2d::CardinalSplineBy'
    .supercls('cocos2d::CardinalSplineTo')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::CardinalSplineBy *create(float duration, cocos2d::PointArray *points, float tension)')

typeconf 'cocos2d::CatmullRomTo'
    .supercls('cocos2d::CardinalSplineTo')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::CatmullRomTo *create(float dt, cocos2d::PointArray *points)')

typeconf 'cocos2d::CatmullRomBy'
    .supercls('cocos2d::CardinalSplineBy')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::CatmullRomBy *create(float dt, cocos2d::PointArray *points)')

typeconf 'cocos2d::ActionInstant'
    .supercls('cocos2d::FiniteTimeAction')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)

typeconf 'cocos2d::Show'
    .supercls('cocos2d::ActionInstant')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::Show *create()')

typeconf 'cocos2d::Hide'
    .supercls('cocos2d::ActionInstant')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::Hide *create()')

typeconf 'cocos2d::ToggleVisibility'
    .supercls('cocos2d::ActionInstant')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ToggleVisibility *create()')

typeconf 'cocos2d::RemoveSelf'
    .supercls('cocos2d::ActionInstant')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::RemoveSelf *create(@optional bool isNeedCleanUp)')

typeconf 'cocos2d::FlipX'
    .supercls('cocos2d::ActionInstant')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::FlipX *create(bool x)')

typeconf 'cocos2d::FlipY'
    .supercls('cocos2d::ActionInstant')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::FlipY *create(bool y)')

typeconf 'cocos2d::Place'
    .supercls('cocos2d::ActionInstant')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::Place *create(const cocos2d::Vec2 &pos)')

typeconf 'cocos2d::CallFunc'
    .supercls('cocos2d::ActionInstant')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'void execute()')
    .callback {
        FUNCS =  {
            'static cocos2d::CallFunc *create(@local const std::function<void ()> &func)'
        },
        TAG_MAKER = 'CallFunc',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_STORE = "return",
        TAG_SCOPE = 'object',
    }

typeconf 'cocos2d::ActionCamera'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'void setEye(const cocos2d::Vec3 &eye)', 'void setEye(float x, float y, float z)')
    .func(nil, 'const cocos2d::Vec3 &getEye()')
    .func(nil, 'void setCenter(const cocos2d::Vec3 &center)')
    .func(nil, 'const cocos2d::Vec3 &getCenter()')
    .func(nil, 'void setUp(const cocos2d::Vec3 &up)')
    .func(nil, 'const cocos2d::Vec3 &getUp()')
    .prop('eye', nil, nil)
    .prop('center', nil, nil)
    .prop('up', nil, nil)

typeconf 'cocos2d::OrbitCamera'
    .supercls('cocos2d::ActionCamera')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::OrbitCamera *create(float t, float radius, float deltaRadius, float angleZ, float deltaAngleZ, float angleX, float deltaAngleX)')

typeconf 'cocos2d::GridBase'
    .supercls('cocos2d::Ref')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'void beforeBlit()')
    .func(nil, 'void afterBlit()')
    .func(nil, 'void blit()')
    .func(nil, 'void reuse()')
    .func(nil, 'void calculateVertexPoints()')
    .func(nil, 'bool initWithSize(const cocos2d::Size &gridSize)', 'bool initWithSize(const cocos2d::Size &gridSize, const cocos2d::Rect &rect)', 'bool initWithSize(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped)', 'bool initWithSize(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped, const cocos2d::Rect &rect)')
    .func(nil, 'bool isActive()')
    .func(nil, 'void setActive(bool active)')
    .func(nil, 'int getReuseGrid()')
    .func(nil, 'void setReuseGrid(int reuseGrid)')
    .func(nil, 'const cocos2d::Size &getGridSize()')
    .func(nil, 'void setGridSize(const cocos2d::Size &gridSize)')
    .func(nil, 'const cocos2d::Vec2 &getStep()')
    .func(nil, 'void setStep(const cocos2d::Vec2 &step)')
    .func(nil, 'bool isTextureFlipped()')
    .func(nil, 'void setTextureFlipped(bool flipped)')
    .func(nil, 'void beforeDraw()')
    .func(nil, 'void afterDraw(cocos2d::Node *target)')
    .func(nil, 'void set2DProjection()')
    .func(nil, 'void setGridRect(const cocos2d::Rect &rect)')
    .func(nil, 'const cocos2d::Rect &getGridRect()')
    .prop('active', nil, nil)
    .prop('reuseGrid', nil, nil)
    .prop('gridSize', nil, nil)
    .prop('step', nil, nil)
    .prop('textureFlipped', nil, nil)
    .prop('gridRect', nil, nil)

typeconf 'cocos2d::Grid3D'
    .supercls('cocos2d::GridBase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::Grid3D *create(const cocos2d::Size &gridSize)', 'static cocos2d::Grid3D *create(const cocos2d::Size &gridSize, const cocos2d::Rect &rect)', 'static cocos2d::Grid3D *create(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped)', 'static cocos2d::Grid3D *create(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped, const cocos2d::Rect &rect)')
    .func(nil, 'cocos2d::Vec3 getVertex(const cocos2d::Vec2 &pos)')
    .func(nil, 'cocos2d::Vec3 getOriginalVertex(const cocos2d::Vec2 &pos)')
    .func(nil, 'void setVertex(const cocos2d::Vec2 &pos, const cocos2d::Vec3 &vertex)')
    .func(nil, 'void setNeedDepthTestForBlit(bool neededDepthTest)')
    .func(nil, 'bool getNeedDepthTestForBlit()')
    .prop('needDepthTestForBlit', nil, nil)

typeconf 'cocos2d::TiledGrid3D'
    .supercls('cocos2d::GridBase')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TiledGrid3D *create(const cocos2d::Size &gridSize)', 'static cocos2d::TiledGrid3D *create(const cocos2d::Size &gridSize, const cocos2d::Rect &rect)', 'static cocos2d::TiledGrid3D *create(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped)', 'static cocos2d::TiledGrid3D *create(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped, const cocos2d::Rect &rect)')
    .func(nil, 'cocos2d::Quad3 getTile(const cocos2d::Vec2 &pos)')
    .func(nil, 'cocos2d::Quad3 getOriginalTile(const cocos2d::Vec2 &pos)')
    .func(nil, 'void setTile(const cocos2d::Vec2 &pos, const cocos2d::Quad3 &coords)')

typeconf 'cocos2d::NodeGrid'
    .supercls('cocos2d::Node')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::NodeGrid *create()', 'static cocos2d::NodeGrid *create(const cocos2d::Rect &rect)')
    .func(nil, 'cocos2d::GridBase *getGrid()')
    .func(nil, 'void setGrid(cocos2d::GridBase *grid)')
    .func(nil, 'void setTarget(cocos2d::Node *target)')
    .func(nil, 'void setGridRect(const cocos2d::Rect &gridRect)')
    .func(nil, 'const cocos2d::Rect &getGridRect()')
    .prop('grid', nil, nil)
    .prop('gridRect', nil, nil)

typeconf 'cocos2d::GridAction'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'cocos2d::GridBase *getGrid()')
    .prop('grid', nil, nil)

typeconf 'cocos2d::Grid3DAction'
    .supercls('cocos2d::GridAction')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'cocos2d::Vec3 getVertex(const cocos2d::Vec2 &position)')
    .func(nil, 'cocos2d::Vec3 getOriginalVertex(const cocos2d::Vec2 &position)')
    .func(nil, 'void setVertex(const cocos2d::Vec2 &position, const cocos2d::Vec3 &vertex)')
    .func(nil, 'cocos2d::Rect getGridRect()')
    .prop('gridRect', nil, nil)

typeconf 'cocos2d::TiledGrid3DAction'
    .supercls('cocos2d::GridAction')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TiledGrid3DAction *create(float duration, const cocos2d::Size &gridSize)')
    .func(nil, 'cocos2d::Quad3 getTile(const cocos2d::Vec2 &position)')
    .func(nil, 'cocos2d::Quad3 getOriginalTile(const cocos2d::Vec2 &position)')
    .func(nil, 'void setTile(const cocos2d::Vec2 &position, const cocos2d::Quad3 &coords)')

typeconf 'cocos2d::AccelDeccelAmplitude'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::AccelDeccelAmplitude *create(cocos2d::Action *action, float duration)')
    .func(nil, 'float getRate()')
    .func(nil, 'void setRate(float rate)')
    .prop('rate', nil, nil)

typeconf 'cocos2d::AccelAmplitude'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::AccelAmplitude *create(cocos2d::Action *action, float duration)')
    .func(nil, 'float getRate()')
    .func(nil, 'void setRate(float rate)')
    .prop('rate', nil, nil)

typeconf 'cocos2d::DeccelAmplitude'
    .supercls('cocos2d::ActionInterval')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::DeccelAmplitude *create(cocos2d::Action *action, float duration)')
    .func(nil, 'float getRate()')
    .func(nil, 'void setRate(float rate)')
    .prop('rate', nil, nil)

typeconf 'cocos2d::StopGrid'
    .supercls('cocos2d::ActionInstant')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::StopGrid *create()')

typeconf 'cocos2d::ReuseGrid'
    .supercls('cocos2d::ActionInstant')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ReuseGrid *create(int times)')
    .func(nil, 'bool initWithTimes(int times)')

typeconf 'cocos2d::Waves3D'
    .supercls('cocos2d::Grid3DAction')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::Waves3D *create(float duration, const cocos2d::Size &gridSize, unsigned int waves, float amplitude)')
    .func(nil, 'float getAmplitude()')
    .func(nil, 'void setAmplitude(float amplitude)')
    .prop('amplitude', nil, nil)

typeconf 'cocos2d::FlipX3D'
    .supercls('cocos2d::Grid3DAction')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::FlipX3D *create(float duration)')
    .func(nil, 'bool initWithSize(const cocos2d::Size &gridSize, float duration)')

typeconf 'cocos2d::FlipY3D'
    .supercls('cocos2d::FlipX3D')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::FlipY3D *create(float duration)')

typeconf 'cocos2d::Lens3D'
    .supercls('cocos2d::Grid3DAction')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::Lens3D *create(float duration, const cocos2d::Size &gridSize, const cocos2d::Vec2 &position, float radius)')
    .func(nil, 'float getLensEffect()')
    .func(nil, 'void setLensEffect(float lensEffect)')
    .func(nil, 'void setConcave(bool concave)')
    .func(nil, 'const cocos2d::Vec2 &getPosition()')
    .func(nil, 'void setPosition(const cocos2d::Vec2 &position)')
    .prop('lensEffect', nil, nil)
    .prop('position', nil, nil)

typeconf 'cocos2d::Ripple3D'
    .supercls('cocos2d::Grid3DAction')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::Ripple3D *create(float duration, const cocos2d::Size &gridSize, const cocos2d::Vec2 &position, float radius, unsigned int waves, float amplitude)')
    .func(nil, 'const cocos2d::Vec2 &getPosition()')
    .func(nil, 'void setPosition(const cocos2d::Vec2 &position)')
    .func(nil, 'float getAmplitude()')
    .func(nil, 'void setAmplitude(float fAmplitude)')
    .prop('position', nil, nil)
    .prop('amplitude', nil, nil)

typeconf 'cocos2d::Shaky3D'
    .supercls('cocos2d::Grid3DAction')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::Shaky3D *create(float initWithDuration, const cocos2d::Size &gridSize, int range, bool shakeZ)')

typeconf 'cocos2d::Liquid'
    .supercls('cocos2d::Grid3DAction')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::Liquid *create(float duration, const cocos2d::Size &gridSize, unsigned int waves, float amplitude)')
    .func(nil, 'float getAmplitude()')
    .func(nil, 'void setAmplitude(float amplitude)')
    .prop('amplitude', nil, nil)

typeconf 'cocos2d::Waves'
    .supercls('cocos2d::Grid3DAction')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::Waves *create(float duration, const cocos2d::Size &gridSize, unsigned int waves, float amplitude, bool horizontal, bool vertical)')
    .func(nil, 'float getAmplitude()')
    .func(nil, 'void setAmplitude(float amplitude)')
    .prop('amplitude', nil, nil)

typeconf 'cocos2d::Twirl'
    .supercls('cocos2d::Grid3DAction')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::Twirl *create(float duration, const cocos2d::Size &gridSize, const cocos2d::Vec2 &position, unsigned int twirls, float amplitude)')
    .func(nil, 'const cocos2d::Vec2 &getPosition()')
    .func(nil, 'void setPosition(const cocos2d::Vec2 &position)')
    .func(nil, 'float getAmplitude()')
    .func(nil, 'void setAmplitude(float amplitude)')
    .prop('position', nil, nil)
    .prop('amplitude', nil, nil)

typeconf 'cocos2d::PageTurn3D'
    .supercls('cocos2d::Grid3DAction')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::PageTurn3D *create(float duration, const cocos2d::Size &gridSize)')

typeconf 'cocos2d::ShakyTiles3D'
    .supercls('cocos2d::TiledGrid3DAction')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ShakyTiles3D *create(float duration, const cocos2d::Size &gridSize, int range, bool shakeZ)')

typeconf 'cocos2d::ShatteredTiles3D'
    .supercls('cocos2d::TiledGrid3DAction')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ShatteredTiles3D *create(float duration, const cocos2d::Size &gridSize, int range, bool shatterZ)')

typeconf 'cocos2d::ShuffleTiles'
    .supercls('cocos2d::TiledGrid3DAction')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::ShuffleTiles *create(float duration, const cocos2d::Size &gridSize, unsigned int seed)')
    .func(nil, 'cocos2d::Size getDelta(const cocos2d::Size &pos)')

typeconf 'cocos2d::FadeOutTRTiles'
    .supercls('cocos2d::TiledGrid3DAction')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::FadeOutTRTiles *create(float duration, const cocos2d::Size &gridSize)')
    .func(nil, 'float testFunc(const cocos2d::Size &pos, float time)')
    .func(nil, 'void turnOnTile(const cocos2d::Vec2 &pos)')
    .func(nil, 'void turnOffTile(const cocos2d::Vec2 &pos)')
    .func(nil, 'void transformTile(const cocos2d::Vec2 &pos, float distance)')

typeconf 'cocos2d::FadeOutBLTiles'
    .supercls('cocos2d::FadeOutTRTiles')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::FadeOutBLTiles *create(float duration, const cocos2d::Size &gridSize)')

typeconf 'cocos2d::FadeOutUpTiles'
    .supercls('cocos2d::FadeOutTRTiles')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::FadeOutUpTiles *create(float duration, const cocos2d::Size &gridSize)')

typeconf 'cocos2d::FadeOutDownTiles'
    .supercls('cocos2d::FadeOutUpTiles')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::FadeOutDownTiles *create(float duration, const cocos2d::Size &gridSize)')

typeconf 'cocos2d::TurnOffTiles'
    .supercls('cocos2d::TiledGrid3DAction')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::TurnOffTiles *create(float duration, const cocos2d::Size &gridSize)', 'static cocos2d::TurnOffTiles *create(float duration, const cocos2d::Size &gridSize, unsigned int seed)')
    .func(nil, 'void turnOnTile(const cocos2d::Vec2 &pos)')
    .func(nil, 'void turnOffTile(const cocos2d::Vec2 &pos)')

typeconf 'cocos2d::WavesTiles3D'
    .supercls('cocos2d::TiledGrid3DAction')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::WavesTiles3D *create(float duration, const cocos2d::Size &gridSize, unsigned int waves, float amplitude)')
    .func(nil, 'float getAmplitude()')
    .func(nil, 'void setAmplitude(float amplitude)')
    .prop('amplitude', nil, nil)

typeconf 'cocos2d::JumpTiles3D'
    .supercls('cocos2d::TiledGrid3DAction')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::JumpTiles3D *create(float duration, const cocos2d::Size &gridSize, unsigned int numberOfJumps, float amplitude)')
    .func(nil, 'float getAmplitude()')
    .func(nil, 'void setAmplitude(float amplitude)')
    .prop('amplitude', nil, nil)

typeconf 'cocos2d::SplitRows'
    .supercls('cocos2d::TiledGrid3DAction')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::SplitRows *create(float duration, unsigned int rows)')

typeconf 'cocos2d::SplitCols'
    .supercls('cocos2d::TiledGrid3DAction')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cocos2d::SplitCols *create(float duration, unsigned int cols)')
