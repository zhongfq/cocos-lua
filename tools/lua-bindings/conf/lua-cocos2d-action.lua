module 'cocos2d_action'

path '../../frameworks/libxgame/src/lua-bindings'

headers [[
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "lua-bindings/LuaCocosAdapter.h"
#include "cocos2d.h"
]]

luacls(function (cppname)
    cppname = string.gsub(cppname, "^cocos2d::", "cc.")
    cppname = string.gsub(cppname, "::", ".")
    return cppname
end)

local function typeconf(cppcls)
    local cls = _ENV.typeconf(cppcls)
    cls.exclude 'new'
    return cls
end

typeconf 'cocos2d::tweenfunc::TweenType'

typeconf 'cocos2d::Action'
    .exclude 'calculateAngles'
    .exclude 'createWithVariableList'
    .exclude 'init'
    .exclude 'initWithAction'
    .exclude 'initWithAnimation'
    .exclude 'initWithDuration'
    .exclude 'initWithFlipX'
    .exclude 'initWithFlipY'
    .exclude 'initWithFunction'
    .exclude 'initWithPosition'
    .exclude 'initWithTwoActions'
    .exclude 'setReverseAction'

typeconf 'cocos2d::FiniteTimeAction'

typeconf 'cocos2d::Speed'
    .func 'create'
        .arg1 '@addref(innerAction ^)'
    .func 'setInnerAction'
        .arg1 '@addref(innerAction ^)'
    .func 'getInnerAction'
        .ret '@addref(innerAction ^)'

typeconf 'cocos2d::Follow'
typeconf 'cocos2d::tweenfunc'
typeconf 'cocos2d::ActionInterval'
typeconf 'cocos2d::ActionTween'

typeconf 'cocos2d::Sequence'
    .func 'createWithTwoActions'
        .arg1 '@addref(actions |)'
        .arg2 '@addref(actions |)'
    .func 'create'
        .arg1 '@pack@addref(actions |)'

typeconf 'cocos2d::Repeat'
    .func 'create'
        .arg1 '@addref(innerAction ^)'
    .func 'setInnerAction'
        .arg1 '@addref(innerAction ^)'
    .func 'getInnerAction'
        .ret '@addref(innerAction ^)'

typeconf 'cocos2d::RepeatForever'
    .func 'create'
        .arg1 '@addref(innerAction ^)'
    .func 'setInnerAction'
        .arg1 '@addref(innerAction ^)'
    .func 'getInnerAction'
        .ret '@addref(innerAction ^)'

typeconf 'cocos2d::Spawn'
    .func 'createWithTwoActions'
        .arg1 '@addref(actions |)'
        .arg2 '@addref(actions |)'
    .func 'create'
        .arg1 '@pack@addref(actions |)'

typeconf 'cocos2d::RotateTo'
typeconf 'cocos2d::RotateFrom'
typeconf 'cocos2d::RotateBy'

typeconf 'cocos2d::MoveBy'
    .func 'create'
        .arg2 '@pack'

typeconf 'cocos2d::MoveTo'
    .func 'create'
        .arg2 '@pack'

typeconf 'cocos2d::MoveFrom'
    .func 'create'
        .arg2 '@pack'

typeconf 'cocos2d::SkewTo'
typeconf 'cocos2d::SkewBy'
typeconf 'cocos2d::ResizeTo'
typeconf 'cocos2d::ResizeBy'

typeconf 'cocos2d::BezierBy'
    .func 'create'
        .arg2 '@pack'

typeconf 'cocos2d::BezierTo'
    .func 'create'
        .arg2 '@pack'

typeconf 'cocos2d::JumpBy'
    .func 'create'
        .arg2 '@pack'

typeconf 'cocos2d::JumpTo'
    .func 'create'
        .arg2 '@pack'

typeconf 'cocos2d::ScaleTo'
typeconf 'cocos2d::ScaleBy'
typeconf 'cocos2d::ScaleFrom'
typeconf 'cocos2d::Blink'
typeconf 'cocos2d::FadeTo'
typeconf 'cocos2d::FadeFrom'
typeconf 'cocos2d::FadeIn'
typeconf 'cocos2d::FadeOut'
typeconf 'cocos2d::TintTo'
typeconf 'cocos2d::TintBy'
typeconf 'cocos2d::DelayTime'

typeconf 'cocos2d::ReverseTime'
    .func 'create'
        .arg1 '@addref(actions |)'

typeconf 'cocos2d::Animate'

typeconf 'cocos2d::TargetedAction'
    .func 'create'
        .arg2 '@addref(actions |)'

typeconf 'cocos2d::ActionFloat::ActionFloatCallback'

typeconf 'cocos2d::ActionFloat'
    .callback 'create'
        .tag_maker 'ActionFloat'
        .tag_mode 'new'
        .tag_store '-1'

typeconf 'cocos2d::ProgressTo'
typeconf 'cocos2d::ProgressFromTo'

typeconf 'cocos2d::ActionEase'
    .func 'getInnerAction'
        .ret '@addref(innerAction ^)'

local function typeease(name)
    local cls = typeconf(name)
    cls.func 'create' .arg1 '@addref(innerAction ^)'
    return cls
end

typeease 'cocos2d::EaseRateAction'
typeease 'cocos2d::EaseExponentialIn'
typeease 'cocos2d::EaseExponentialOut'
typeease 'cocos2d::EaseExponentialInOut'
typeease 'cocos2d::EaseSineIn'
typeease 'cocos2d::EaseSineOut'
typeease 'cocos2d::EaseSineInOut'
typeease 'cocos2d::EaseBounceIn'
typeease 'cocos2d::EaseBounceOut'
typeease 'cocos2d::EaseBounceInOut'
typeease 'cocos2d::EaseBackIn'
typeease 'cocos2d::EaseBackOut'
typeease 'cocos2d::EaseBackInOut'
typeease 'cocos2d::EaseQuadraticActionIn'
typeease 'cocos2d::EaseQuadraticActionOut'
typeease 'cocos2d::EaseQuadraticActionInOut'
typeease 'cocos2d::EaseQuarticActionIn'
typeease 'cocos2d::EaseQuarticActionOut'
typeease 'cocos2d::EaseQuarticActionInOut'
typeease 'cocos2d::EaseQuinticActionIn'
typeease 'cocos2d::EaseQuinticActionOut'
typeease 'cocos2d::EaseQuinticActionInOut'
typeease 'cocos2d::EaseCircleActionIn'
typeease 'cocos2d::EaseCircleActionOut'
typeease 'cocos2d::EaseCircleActionInOut'
typeease 'cocos2d::EaseCubicActionIn'
typeease 'cocos2d::EaseCubicActionOut'
typeease 'cocos2d::EaseCubicActionInOut'
typeease 'cocos2d::EaseIn'
typeease 'cocos2d::EaseOut'
typeease 'cocos2d::EaseInOut'
typeease 'cocos2d::EaseElastic'
typeease 'cocos2d::EaseElasticIn'
typeease 'cocos2d::EaseElasticOut'
typeease 'cocos2d::EaseElasticInOut'
typeease 'cocos2d::EaseBezierAction'

typeconf 'cocos2d::PointArray'
typeconf 'cocos2d::CardinalSplineTo'
typeconf 'cocos2d::CardinalSplineBy'
typeconf 'cocos2d::CatmullRomTo'
typeconf 'cocos2d::CatmullRomBy'
typeconf "cocos2d::ActionInstant"
typeconf "cocos2d::Show"
typeconf "cocos2d::Hide"
typeconf "cocos2d::ToggleVisibility"
typeconf "cocos2d::RemoveSelf"
typeconf "cocos2d::FlipX"
typeconf "cocos2d::FlipY"
typeconf "cocos2d::Place"

typeconf "cocos2d::CallFunc"
    .callback 'create'
        .tag_maker 'CallFunc'
        .tag_mode 'new'
        .tag_store '-1'

typeconf 'cocos2d::ActionCamera'
typeconf 'cocos2d::OrbitCamera'
typeconf 'cocos2d::GridBase'
typeconf 'cocos2d::Grid3D'
typeconf 'cocos2d::TiledGrid3D'
typeconf 'cocos2d::NodeGrid'
typeconf 'cocos2d::GridAction'
typeconf 'cocos2d::Grid3DAction'
typeconf 'cocos2d::TiledGrid3DAction'
typeconf 'cocos2d::AccelDeccelAmplitude'
typeconf 'cocos2d::AccelAmplitude'
typeconf 'cocos2d::DeccelAmplitude'
typeconf 'cocos2d::StopGrid'
typeconf 'cocos2d::ReuseGrid'
typeconf 'cocos2d::Waves3D'
typeconf 'cocos2d::FlipX3D'
typeconf 'cocos2d::FlipY3D'
typeconf 'cocos2d::Lens3D'
typeconf 'cocos2d::Ripple3D'
typeconf 'cocos2d::Shaky3D'
typeconf 'cocos2d::Liquid'
typeconf 'cocos2d::Waves'
typeconf 'cocos2d::Twirl'
typeconf 'cocos2d::PageTurn3D'
typeconf 'cocos2d::ShakyTiles3D'
typeconf 'cocos2d::ShatteredTiles3D'
typeconf 'cocos2d::ShuffleTiles'
typeconf 'cocos2d::FadeOutTRTiles'
typeconf 'cocos2d::FadeOutBLTiles'
typeconf 'cocos2d::FadeOutUpTiles'
typeconf 'cocos2d::FadeOutDownTiles'
typeconf 'cocos2d::TurnOffTiles'
typeconf 'cocos2d::WavesTiles3D'
typeconf 'cocos2d::JumpTiles3D'
typeconf 'cocos2d::SplitRows'
typeconf 'cocos2d::SplitCols'
