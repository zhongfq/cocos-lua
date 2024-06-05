//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_cocos2d_action.h"
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cocos2d.h"

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_tweenfunc_TweenType(lua_State *L)
{
    oluacls_class<cocos2d::tweenfunc::TweenType>(L, "cc.tweenfunc.TweenType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "Back_EaseIn", (lua_Integer)cocos2d::tweenfunc::TweenType::Back_EaseIn);
    oluacls_enum(L, "Back_EaseInOut", (lua_Integer)cocos2d::tweenfunc::TweenType::Back_EaseInOut);
    oluacls_enum(L, "Back_EaseOut", (lua_Integer)cocos2d::tweenfunc::TweenType::Back_EaseOut);
    oluacls_enum(L, "Bounce_EaseIn", (lua_Integer)cocos2d::tweenfunc::TweenType::Bounce_EaseIn);
    oluacls_enum(L, "Bounce_EaseInOut", (lua_Integer)cocos2d::tweenfunc::TweenType::Bounce_EaseInOut);
    oluacls_enum(L, "Bounce_EaseOut", (lua_Integer)cocos2d::tweenfunc::TweenType::Bounce_EaseOut);
    oluacls_enum(L, "CUSTOM_EASING", (lua_Integer)cocos2d::tweenfunc::TweenType::CUSTOM_EASING);
    oluacls_enum(L, "Circ_EaseIn", (lua_Integer)cocos2d::tweenfunc::TweenType::Circ_EaseIn);
    oluacls_enum(L, "Circ_EaseInOut", (lua_Integer)cocos2d::tweenfunc::TweenType::Circ_EaseInOut);
    oluacls_enum(L, "Circ_EaseOut", (lua_Integer)cocos2d::tweenfunc::TweenType::Circ_EaseOut);
    oluacls_enum(L, "Cubic_EaseIn", (lua_Integer)cocos2d::tweenfunc::TweenType::Cubic_EaseIn);
    oluacls_enum(L, "Cubic_EaseInOut", (lua_Integer)cocos2d::tweenfunc::TweenType::Cubic_EaseInOut);
    oluacls_enum(L, "Cubic_EaseOut", (lua_Integer)cocos2d::tweenfunc::TweenType::Cubic_EaseOut);
    oluacls_enum(L, "Elastic_EaseIn", (lua_Integer)cocos2d::tweenfunc::TweenType::Elastic_EaseIn);
    oluacls_enum(L, "Elastic_EaseInOut", (lua_Integer)cocos2d::tweenfunc::TweenType::Elastic_EaseInOut);
    oluacls_enum(L, "Elastic_EaseOut", (lua_Integer)cocos2d::tweenfunc::TweenType::Elastic_EaseOut);
    oluacls_enum(L, "Expo_EaseIn", (lua_Integer)cocos2d::tweenfunc::TweenType::Expo_EaseIn);
    oluacls_enum(L, "Expo_EaseInOut", (lua_Integer)cocos2d::tweenfunc::TweenType::Expo_EaseInOut);
    oluacls_enum(L, "Expo_EaseOut", (lua_Integer)cocos2d::tweenfunc::TweenType::Expo_EaseOut);
    oluacls_enum(L, "Linear", (lua_Integer)cocos2d::tweenfunc::TweenType::Linear);
    oluacls_enum(L, "Quad_EaseIn", (lua_Integer)cocos2d::tweenfunc::TweenType::Quad_EaseIn);
    oluacls_enum(L, "Quad_EaseInOut", (lua_Integer)cocos2d::tweenfunc::TweenType::Quad_EaseInOut);
    oluacls_enum(L, "Quad_EaseOut", (lua_Integer)cocos2d::tweenfunc::TweenType::Quad_EaseOut);
    oluacls_enum(L, "Quart_EaseIn", (lua_Integer)cocos2d::tweenfunc::TweenType::Quart_EaseIn);
    oluacls_enum(L, "Quart_EaseInOut", (lua_Integer)cocos2d::tweenfunc::TweenType::Quart_EaseInOut);
    oluacls_enum(L, "Quart_EaseOut", (lua_Integer)cocos2d::tweenfunc::TweenType::Quart_EaseOut);
    oluacls_enum(L, "Quint_EaseIn", (lua_Integer)cocos2d::tweenfunc::TweenType::Quint_EaseIn);
    oluacls_enum(L, "Quint_EaseInOut", (lua_Integer)cocos2d::tweenfunc::TweenType::Quint_EaseInOut);
    oluacls_enum(L, "Quint_EaseOut", (lua_Integer)cocos2d::tweenfunc::TweenType::Quint_EaseOut);
    oluacls_enum(L, "Sine_EaseIn", (lua_Integer)cocos2d::tweenfunc::TweenType::Sine_EaseIn);
    oluacls_enum(L, "Sine_EaseInOut", (lua_Integer)cocos2d::tweenfunc::TweenType::Sine_EaseInOut);
    oluacls_enum(L, "Sine_EaseOut", (lua_Integer)cocos2d::tweenfunc::TweenType::Sine_EaseOut);
    oluacls_enum(L, "TWEEN_EASING_MAX", (lua_Integer)cocos2d::tweenfunc::TweenType::TWEEN_EASING_MAX);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_Action_as(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;
    const char *arg1 = nullptr;       /** cls */

    olua_to_object(L, 1, &self, "cc.Action");
    olua_check_string(L, 2, &arg1);

    do {
        if (olua_isa(L, 1, arg1)) {
            lua_pushvalue(L, 1);
            break;
        }
        if (olua_strequal(arg1, "cc.Clonable")) {
            olua_pushobj_as<cocos2d::Clonable>(L, 1, self, "as.cc.Clonable");
            break;
        }

        luaL_error(L, "'cocos2d::Action' can't cast to '%s'", arg1);
    } while (0);

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_Action_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Action");

    // cocos2d::Action *clone()
    cocos2d::Action *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.Action");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Action_description(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Action");

    // std::string description()
    std::string ret = self->description();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Action_getFlags(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Action");

    // unsigned int getFlags()
    unsigned int ret = self->getFlags();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Action_getOriginalTarget(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Action");

    // cocos2d::Node *getOriginalTarget()
    cocos2d::Node *ret = self->getOriginalTarget();
    int num_ret = olua_push_object(L, ret, "cc.Node");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Action_getTag(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Action");

    // int getTag()
    int ret = self->getTag();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Action_getTarget(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Action");

    // cocos2d::Node *getTarget()
    cocos2d::Node *ret = self->getTarget();
    int num_ret = olua_push_object(L, ret, "cc.Node");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Action_isDone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Action");

    // bool isDone()
    bool ret = self->isDone();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Action_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Action");

    // cocos2d::Action *reverse()
    cocos2d::Action *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.Action");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Action_setFlags(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;
    unsigned int arg1 = 0;       /** flags */

    olua_to_object(L, 1, &self, "cc.Action");
    olua_check_integer(L, 2, &arg1);

    // void setFlags(unsigned int flags)
    self->setFlags(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_Action_setOriginalTarget(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** originalTarget */

    olua_to_object(L, 1, &self, "cc.Action");
    olua_check_object(L, 2, &arg1, "cc.Node");

    // void setOriginalTarget(cocos2d::Node *originalTarget)
    self->setOriginalTarget(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_Action_setTag(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;
    int arg1 = 0;       /** tag */

    olua_to_object(L, 1, &self, "cc.Action");
    olua_check_integer(L, 2, &arg1);

    // void setTag(int tag)
    self->setTag(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_Action_setTarget(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** target */

    olua_to_object(L, 1, &self, "cc.Action");
    olua_check_object(L, 2, &arg1, "cc.Node");

    // void setTarget(cocos2d::Node *target)
    self->setTarget(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_Action_startWithTarget(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** target */

    olua_to_object(L, 1, &self, "cc.Action");
    olua_check_object(L, 2, &arg1, "cc.Node");

    // void startWithTarget(cocos2d::Node *target)
    self->startWithTarget(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_Action_step(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;
    float arg1 = 0;       /** dt */

    olua_to_object(L, 1, &self, "cc.Action");
    olua_check_number(L, 2, &arg1);

    // void step(float dt)
    self->step(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_Action_stop(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Action");

    // void stop()
    self->stop();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_Action_update(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;
    float arg1 = 0;       /** time */

    olua_to_object(L, 1, &self, "cc.Action");
    olua_check_number(L, 2, &arg1);

    // void update(float time)
    self->update(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_Action(lua_State *L)
{
    oluacls_class<cocos2d::Action, cocos2d::Ref>(L, "cc.Action");
    oluacls_func(L, "as", _cocos2d_Action_as);
    oluacls_func(L, "clone", _cocos2d_Action_clone);
    oluacls_func(L, "description", _cocos2d_Action_description);
    oluacls_func(L, "getFlags", _cocos2d_Action_getFlags);
    oluacls_func(L, "getOriginalTarget", _cocos2d_Action_getOriginalTarget);
    oluacls_func(L, "getTag", _cocos2d_Action_getTag);
    oluacls_func(L, "getTarget", _cocos2d_Action_getTarget);
    oluacls_func(L, "isDone", _cocos2d_Action_isDone);
    oluacls_func(L, "reverse", _cocos2d_Action_reverse);
    oluacls_func(L, "setFlags", _cocos2d_Action_setFlags);
    oluacls_func(L, "setOriginalTarget", _cocos2d_Action_setOriginalTarget);
    oluacls_func(L, "setTag", _cocos2d_Action_setTag);
    oluacls_func(L, "setTarget", _cocos2d_Action_setTarget);
    oluacls_func(L, "startWithTarget", _cocos2d_Action_startWithTarget);
    oluacls_func(L, "step", _cocos2d_Action_step);
    oluacls_func(L, "stop", _cocos2d_Action_stop);
    oluacls_func(L, "update", _cocos2d_Action_update);
    oluacls_prop(L, "done", _cocos2d_Action_isDone, nullptr);
    oluacls_prop(L, "flags", _cocos2d_Action_getFlags, _cocos2d_Action_setFlags);
    oluacls_prop(L, "originalTarget", _cocos2d_Action_getOriginalTarget, _cocos2d_Action_setOriginalTarget);
    oluacls_prop(L, "tag", _cocos2d_Action_getTag, _cocos2d_Action_setTag);
    oluacls_prop(L, "target", _cocos2d_Action_getTarget, _cocos2d_Action_setTarget);
    oluacls_const(L, "INVALID_TAG", cocos2d::Action::INVALID_TAG);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_ActionTweenDelegate___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ActionTweenDelegate *)olua_toobj(L, 1, "cc.ActionTweenDelegate");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ActionTweenDelegate___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ActionTweenDelegate *)olua_toobj(L, 1, "cc.ActionTweenDelegate");
    olua_push_object(L, self, "cc.ActionTweenDelegate");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ActionTweenDelegate_updateTweenAction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionTweenDelegate *self = nullptr;
    float arg1 = 0;       /** value */
    std::string arg2;       /** key */

    olua_to_object(L, 1, &self, "cc.ActionTweenDelegate");
    olua_check_number(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // void updateTweenAction(float value, const std::string &key)
    self->updateTweenAction(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_ActionTweenDelegate(lua_State *L)
{
    oluacls_class<cocos2d::ActionTweenDelegate>(L, "cc.ActionTweenDelegate");
    oluacls_func(L, "__gc", _cocos2d_ActionTweenDelegate___gc);
    oluacls_func(L, "__olua_move", _cocos2d_ActionTweenDelegate___olua_move);
    oluacls_func(L, "updateTweenAction", _cocos2d_ActionTweenDelegate_updateTweenAction);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_FiniteTimeAction_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *self = nullptr;

    olua_to_object(L, 1, &self, "cc.FiniteTimeAction");

    // cocos2d::FiniteTimeAction *clone()
    cocos2d::FiniteTimeAction *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.FiniteTimeAction");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_FiniteTimeAction_getDuration(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *self = nullptr;

    olua_to_object(L, 1, &self, "cc.FiniteTimeAction");

    // float getDuration()
    float ret = self->getDuration();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_FiniteTimeAction_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *self = nullptr;

    olua_to_object(L, 1, &self, "cc.FiniteTimeAction");

    // cocos2d::FiniteTimeAction *reverse()
    cocos2d::FiniteTimeAction *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.FiniteTimeAction");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_FiniteTimeAction_setDuration(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *self = nullptr;
    float arg1 = 0;       /** duration */

    olua_to_object(L, 1, &self, "cc.FiniteTimeAction");
    olua_check_number(L, 2, &arg1);

    // void setDuration(float duration)
    self->setDuration(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_FiniteTimeAction(lua_State *L)
{
    oluacls_class<cocos2d::FiniteTimeAction, cocos2d::Action>(L, "cc.FiniteTimeAction");
    oluacls_func(L, "clone", _cocos2d_FiniteTimeAction_clone);
    oluacls_func(L, "getDuration", _cocos2d_FiniteTimeAction_getDuration);
    oluacls_func(L, "reverse", _cocos2d_FiniteTimeAction_reverse);
    oluacls_func(L, "setDuration", _cocos2d_FiniteTimeAction_setDuration);
    oluacls_prop(L, "duration", _cocos2d_FiniteTimeAction_getDuration, _cocos2d_FiniteTimeAction_setDuration);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_Speed_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Speed *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Speed");

    // cocos2d::Speed *clone()
    cocos2d::Speed *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.Speed");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Speed_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */
    float arg2 = 0;       /** speed */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");
    olua_check_number(L, 2, &arg2);

    // static cocos2d::Speed *create(@addref(innerAction ^) cocos2d::ActionInterval *action, float speed)
    cocos2d::Speed *ret = cocos2d::Speed::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.Speed");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Speed_getInnerAction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Speed *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Speed");

    // @addref(innerAction ^) cocos2d::ActionInterval *getInnerAction()
    cocos2d::ActionInterval *ret = self->getInnerAction();
    int num_ret = olua_push_object(L, ret, "cc.ActionInterval");

    // insert code after call
    olua_addref(L, 1, "innerAction", -1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Speed_getSpeed(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Speed *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Speed");

    // float getSpeed()
    float ret = self->getSpeed();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Speed_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Speed *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Speed");

    // cocos2d::Speed *reverse()
    cocos2d::Speed *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.Speed");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Speed_setInnerAction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Speed *self = nullptr;
    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_to_object(L, 1, &self, "cc.Speed");
    olua_check_object(L, 2, &arg1, "cc.ActionInterval");

    // void setInnerAction(@addref(innerAction ^) cocos2d::ActionInterval *action)
    self->setInnerAction(arg1);

    // insert code after call
    olua_addref(L, 1, "innerAction", 2, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_Speed_setSpeed(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Speed *self = nullptr;
    float arg1 = 0;       /** speed */

    olua_to_object(L, 1, &self, "cc.Speed");
    olua_check_number(L, 2, &arg1);

    // void setSpeed(float speed)
    self->setSpeed(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_Speed(lua_State *L)
{
    oluacls_class<cocos2d::Speed, cocos2d::Action>(L, "cc.Speed");
    oluacls_func(L, "clone", _cocos2d_Speed_clone);
    oluacls_func(L, "create", _cocos2d_Speed_create);
    oluacls_func(L, "getInnerAction", _cocos2d_Speed_getInnerAction);
    oluacls_func(L, "getSpeed", _cocos2d_Speed_getSpeed);
    oluacls_func(L, "reverse", _cocos2d_Speed_reverse);
    oluacls_func(L, "setInnerAction", _cocos2d_Speed_setInnerAction);
    oluacls_func(L, "setSpeed", _cocos2d_Speed_setSpeed);
    oluacls_prop(L, "innerAction", _cocos2d_Speed_getInnerAction, _cocos2d_Speed_setInnerAction);
    oluacls_prop(L, "speed", _cocos2d_Speed_getSpeed, _cocos2d_Speed_setSpeed);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_Follow_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Follow *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Follow");

    // cocos2d::Follow *clone()
    cocos2d::Follow *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.Follow");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Follow_create$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Node *arg1 = nullptr;       /** followedNode */
    cocos2d::Rect arg2;       /** rect */

    olua_check_object(L, 1, &arg1, "cc.Node");
    olua_check_object(L, 2, &arg2, "cc.Rect");

    // static cocos2d::Follow *create(cocos2d::Node *followedNode, @optional const cocos2d::Rect &rect)
    cocos2d::Follow *ret = cocos2d::Follow::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.Follow");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Follow_create$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Node *arg1 = nullptr;       /** followedNode */

    olua_check_object(L, 1, &arg1, "cc.Node");

    // static cocos2d::Follow *create(cocos2d::Node *followedNode, @optional const cocos2d::Rect &rect)
    cocos2d::Follow *ret = cocos2d::Follow::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.Follow");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Follow_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_object(L, 1, "cc.Node"))) {
            // static cocos2d::Follow *create(cocos2d::Node *followedNode, @optional const cocos2d::Rect &rect)
            return _cocos2d_Follow_create$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Node")) && (olua_is_object(L, 2, "cc.Rect"))) {
            // static cocos2d::Follow *create(cocos2d::Node *followedNode, @optional const cocos2d::Rect &rect)
            return _cocos2d_Follow_create$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Follow::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_Follow_createWithOffset$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Node *arg1 = nullptr;       /** followedNode */
    float arg2 = 0;       /** xOffset */
    float arg3 = 0;       /** yOffset */
    cocos2d::Rect arg4;       /** rect */

    olua_check_object(L, 1, &arg1, "cc.Node");
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_object(L, 4, &arg4, "cc.Rect");

    // static cocos2d::Follow *createWithOffset(cocos2d::Node *followedNode, float xOffset, float yOffset, @optional const cocos2d::Rect &rect)
    cocos2d::Follow *ret = cocos2d::Follow::createWithOffset(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.Follow");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Follow_createWithOffset$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Node *arg1 = nullptr;       /** followedNode */
    float arg2 = 0;       /** xOffset */
    float arg3 = 0;       /** yOffset */

    olua_check_object(L, 1, &arg1, "cc.Node");
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static cocos2d::Follow *createWithOffset(cocos2d::Node *followedNode, float xOffset, float yOffset, @optional const cocos2d::Rect &rect)
    cocos2d::Follow *ret = cocos2d::Follow::createWithOffset(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.Follow");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Follow_createWithOffset(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Node")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // static cocos2d::Follow *createWithOffset(cocos2d::Node *followedNode, float xOffset, float yOffset, @optional const cocos2d::Rect &rect)
            return _cocos2d_Follow_createWithOffset$2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.Node")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_object(L, 4, "cc.Rect"))) {
            // static cocos2d::Follow *createWithOffset(cocos2d::Node *followedNode, float xOffset, float yOffset, @optional const cocos2d::Rect &rect)
            return _cocos2d_Follow_createWithOffset$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Follow::createWithOffset' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_Follow_initWithTarget$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Follow *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** followedNode */
    cocos2d::Rect arg2;       /** rect */

    olua_to_object(L, 1, &self, "cc.Follow");
    olua_check_object(L, 2, &arg1, "cc.Node");
    olua_check_object(L, 3, &arg2, "cc.Rect");

    // bool initWithTarget(cocos2d::Node *followedNode, @optional const cocos2d::Rect &rect)
    bool ret = self->initWithTarget(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Follow_initWithTarget$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Follow *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** followedNode */

    olua_to_object(L, 1, &self, "cc.Follow");
    olua_check_object(L, 2, &arg1, "cc.Node");

    // bool initWithTarget(cocos2d::Node *followedNode, @optional const cocos2d::Rect &rect)
    bool ret = self->initWithTarget(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Follow_initWithTarget(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_object(L, 2, "cc.Node"))) {
            // bool initWithTarget(cocos2d::Node *followedNode, @optional const cocos2d::Rect &rect)
            return _cocos2d_Follow_initWithTarget$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 2, "cc.Node")) && (olua_is_object(L, 3, "cc.Rect"))) {
            // bool initWithTarget(cocos2d::Node *followedNode, @optional const cocos2d::Rect &rect)
            return _cocos2d_Follow_initWithTarget$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Follow::initWithTarget' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_Follow_initWithTargetAndOffset$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Follow *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** followedNode */
    float arg2 = 0;       /** xOffset */
    float arg3 = 0;       /** yOffset */
    cocos2d::Rect arg4;       /** rect */

    olua_to_object(L, 1, &self, "cc.Follow");
    olua_check_object(L, 2, &arg1, "cc.Node");
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_object(L, 5, &arg4, "cc.Rect");

    // bool initWithTargetAndOffset(cocos2d::Node *followedNode, float xOffset, float yOffset, @optional const cocos2d::Rect &rect)
    bool ret = self->initWithTargetAndOffset(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Follow_initWithTargetAndOffset$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Follow *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** followedNode */
    float arg2 = 0;       /** xOffset */
    float arg3 = 0;       /** yOffset */

    olua_to_object(L, 1, &self, "cc.Follow");
    olua_check_object(L, 2, &arg1, "cc.Node");
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // bool initWithTargetAndOffset(cocos2d::Node *followedNode, float xOffset, float yOffset, @optional const cocos2d::Rect &rect)
    bool ret = self->initWithTargetAndOffset(arg1, arg2, arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Follow_initWithTargetAndOffset(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 3) {
        // if ((olua_is_object(L, 2, "cc.Node")) && (olua_is_number(L, 3)) && (olua_is_number(L, 4))) {
            // bool initWithTargetAndOffset(cocos2d::Node *followedNode, float xOffset, float yOffset, @optional const cocos2d::Rect &rect)
            return _cocos2d_Follow_initWithTargetAndOffset$2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 2, "cc.Node")) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_object(L, 5, "cc.Rect"))) {
            // bool initWithTargetAndOffset(cocos2d::Node *followedNode, float xOffset, float yOffset, @optional const cocos2d::Rect &rect)
            return _cocos2d_Follow_initWithTargetAndOffset$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Follow::initWithTargetAndOffset' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_Follow_isBoundarySet(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Follow *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Follow");

    // bool isBoundarySet()
    bool ret = self->isBoundarySet();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Follow_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Follow *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Follow");

    // cocos2d::Follow *reverse()
    cocos2d::Follow *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.Follow");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Follow_setBoundarySet(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Follow *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_object(L, 1, &self, "cc.Follow");
    olua_check_bool(L, 2, &arg1);

    // void setBoundarySet(bool value)
    self->setBoundarySet(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_Follow(lua_State *L)
{
    oluacls_class<cocos2d::Follow, cocos2d::Action>(L, "cc.Follow");
    oluacls_func(L, "clone", _cocos2d_Follow_clone);
    oluacls_func(L, "create", _cocos2d_Follow_create);
    oluacls_func(L, "createWithOffset", _cocos2d_Follow_createWithOffset);
    oluacls_func(L, "initWithTarget", _cocos2d_Follow_initWithTarget);
    oluacls_func(L, "initWithTargetAndOffset", _cocos2d_Follow_initWithTargetAndOffset);
    oluacls_func(L, "isBoundarySet", _cocos2d_Follow_isBoundarySet);
    oluacls_func(L, "reverse", _cocos2d_Follow_reverse);
    oluacls_func(L, "setBoundarySet", _cocos2d_Follow_setBoundarySet);
    oluacls_prop(L, "boundarySet", _cocos2d_Follow_isBoundarySet, _cocos2d_Follow_setBoundarySet);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_tweenfunc_backEaseIn(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float backEaseIn(float time)
    float ret = cocos2d::tweenfunc::backEaseIn(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_backEaseInOut(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float backEaseInOut(float time)
    float ret = cocos2d::tweenfunc::backEaseInOut(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_backEaseOut(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float backEaseOut(float time)
    float ret = cocos2d::tweenfunc::backEaseOut(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_bezieratFunction(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** a */
    float arg2 = 0;       /** b */
    float arg3 = 0;       /** c */
    float arg4 = 0;       /** d */
    float arg5 = 0;       /** t */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);
    olua_check_number(L, 5, &arg5);

    // static float bezieratFunction(float a, float b, float c, float d, float t)
    float ret = cocos2d::tweenfunc::bezieratFunction(arg1, arg2, arg3, arg4, arg5);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_bounceEaseIn(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float bounceEaseIn(float time)
    float ret = cocos2d::tweenfunc::bounceEaseIn(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_bounceEaseInOut(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float bounceEaseInOut(float time)
    float ret = cocos2d::tweenfunc::bounceEaseInOut(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_bounceEaseOut(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float bounceEaseOut(float time)
    float ret = cocos2d::tweenfunc::bounceEaseOut(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_circEaseIn(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float circEaseIn(float time)
    float ret = cocos2d::tweenfunc::circEaseIn(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_circEaseInOut(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float circEaseInOut(float time)
    float ret = cocos2d::tweenfunc::circEaseInOut(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_circEaseOut(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float circEaseOut(float time)
    float ret = cocos2d::tweenfunc::circEaseOut(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_cubicEaseIn(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float cubicEaseIn(float time)
    float ret = cocos2d::tweenfunc::cubicEaseIn(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_cubicEaseInOut(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float cubicEaseInOut(float time)
    float ret = cocos2d::tweenfunc::cubicEaseInOut(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_cubicEaseOut(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float cubicEaseOut(float time)
    float ret = cocos2d::tweenfunc::cubicEaseOut(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_customEase(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */
    float *arg2 = nullptr;       /** easingParam */

    olua_check_number(L, 1, &arg1);
    olua_check_pointer(L, 2, &arg2, "olua.float");

    // static float customEase(float time, float *easingParam)
    float ret = cocos2d::tweenfunc::customEase(arg1, arg2);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_easeIn(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */
    float arg2 = 0;       /** rate */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static float easeIn(float time, float rate)
    float ret = cocos2d::tweenfunc::easeIn(arg1, arg2);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_easeInOut(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */
    float arg2 = 0;       /** rate */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static float easeInOut(float time, float rate)
    float ret = cocos2d::tweenfunc::easeInOut(arg1, arg2);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_easeOut(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */
    float arg2 = 0;       /** rate */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static float easeOut(float time, float rate)
    float ret = cocos2d::tweenfunc::easeOut(arg1, arg2);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_elasticEaseIn(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */
    float arg2 = 0;       /** period */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static float elasticEaseIn(float time, float period)
    float ret = cocos2d::tweenfunc::elasticEaseIn(arg1, arg2);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_elasticEaseInOut(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */
    float arg2 = 0;       /** period */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static float elasticEaseInOut(float time, float period)
    float ret = cocos2d::tweenfunc::elasticEaseInOut(arg1, arg2);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_elasticEaseOut(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */
    float arg2 = 0;       /** period */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static float elasticEaseOut(float time, float period)
    float ret = cocos2d::tweenfunc::elasticEaseOut(arg1, arg2);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_expoEaseIn(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float expoEaseIn(float time)
    float ret = cocos2d::tweenfunc::expoEaseIn(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_expoEaseInOut(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float expoEaseInOut(float time)
    float ret = cocos2d::tweenfunc::expoEaseInOut(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_expoEaseOut(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float expoEaseOut(float time)
    float ret = cocos2d::tweenfunc::expoEaseOut(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_linear(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float linear(float time)
    float ret = cocos2d::tweenfunc::linear(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_quadEaseIn(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float quadEaseIn(float time)
    float ret = cocos2d::tweenfunc::quadEaseIn(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_quadEaseInOut(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float quadEaseInOut(float time)
    float ret = cocos2d::tweenfunc::quadEaseInOut(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_quadEaseOut(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float quadEaseOut(float time)
    float ret = cocos2d::tweenfunc::quadEaseOut(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_quadraticIn(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float quadraticIn(float time)
    float ret = cocos2d::tweenfunc::quadraticIn(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_quadraticInOut(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float quadraticInOut(float time)
    float ret = cocos2d::tweenfunc::quadraticInOut(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_quadraticOut(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float quadraticOut(float time)
    float ret = cocos2d::tweenfunc::quadraticOut(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_quartEaseIn(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float quartEaseIn(float time)
    float ret = cocos2d::tweenfunc::quartEaseIn(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_quartEaseInOut(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float quartEaseInOut(float time)
    float ret = cocos2d::tweenfunc::quartEaseInOut(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_quartEaseOut(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float quartEaseOut(float time)
    float ret = cocos2d::tweenfunc::quartEaseOut(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_quintEaseIn(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float quintEaseIn(float time)
    float ret = cocos2d::tweenfunc::quintEaseIn(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_quintEaseInOut(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float quintEaseInOut(float time)
    float ret = cocos2d::tweenfunc::quintEaseInOut(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_quintEaseOut(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float quintEaseOut(float time)
    float ret = cocos2d::tweenfunc::quintEaseOut(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_sineEaseIn(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float sineEaseIn(float time)
    float ret = cocos2d::tweenfunc::sineEaseIn(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_sineEaseInOut(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float sineEaseInOut(float time)
    float ret = cocos2d::tweenfunc::sineEaseInOut(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_sineEaseOut(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float sineEaseOut(float time)
    float ret = cocos2d::tweenfunc::sineEaseOut(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_tweenTo(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** time */
    cocos2d::tweenfunc::TweenType arg2 = (cocos2d::tweenfunc::TweenType)0;       /** type */
    float *arg3 = nullptr;       /** easingParam */

    olua_check_number(L, 1, &arg1);
    olua_check_enum(L, 2, &arg2);
    olua_check_pointer(L, 3, &arg3, "olua.float");

    // static float tweenTo(float time, cocos2d::tweenfunc::TweenType type, float *easingParam)
    float ret = cocos2d::tweenfunc::tweenTo(arg1, arg2, arg3);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_tweenfunc(lua_State *L)
{
    oluacls_class(L, "cc.tweenfunc", nullptr);
    oluacls_func(L, "backEaseIn", _cocos2d_tweenfunc_backEaseIn);
    oluacls_func(L, "backEaseInOut", _cocos2d_tweenfunc_backEaseInOut);
    oluacls_func(L, "backEaseOut", _cocos2d_tweenfunc_backEaseOut);
    oluacls_func(L, "bezieratFunction", _cocos2d_tweenfunc_bezieratFunction);
    oluacls_func(L, "bounceEaseIn", _cocos2d_tweenfunc_bounceEaseIn);
    oluacls_func(L, "bounceEaseInOut", _cocos2d_tweenfunc_bounceEaseInOut);
    oluacls_func(L, "bounceEaseOut", _cocos2d_tweenfunc_bounceEaseOut);
    oluacls_func(L, "circEaseIn", _cocos2d_tweenfunc_circEaseIn);
    oluacls_func(L, "circEaseInOut", _cocos2d_tweenfunc_circEaseInOut);
    oluacls_func(L, "circEaseOut", _cocos2d_tweenfunc_circEaseOut);
    oluacls_func(L, "cubicEaseIn", _cocos2d_tweenfunc_cubicEaseIn);
    oluacls_func(L, "cubicEaseInOut", _cocos2d_tweenfunc_cubicEaseInOut);
    oluacls_func(L, "cubicEaseOut", _cocos2d_tweenfunc_cubicEaseOut);
    oluacls_func(L, "customEase", _cocos2d_tweenfunc_customEase);
    oluacls_func(L, "easeIn", _cocos2d_tweenfunc_easeIn);
    oluacls_func(L, "easeInOut", _cocos2d_tweenfunc_easeInOut);
    oluacls_func(L, "easeOut", _cocos2d_tweenfunc_easeOut);
    oluacls_func(L, "elasticEaseIn", _cocos2d_tweenfunc_elasticEaseIn);
    oluacls_func(L, "elasticEaseInOut", _cocos2d_tweenfunc_elasticEaseInOut);
    oluacls_func(L, "elasticEaseOut", _cocos2d_tweenfunc_elasticEaseOut);
    oluacls_func(L, "expoEaseIn", _cocos2d_tweenfunc_expoEaseIn);
    oluacls_func(L, "expoEaseInOut", _cocos2d_tweenfunc_expoEaseInOut);
    oluacls_func(L, "expoEaseOut", _cocos2d_tweenfunc_expoEaseOut);
    oluacls_func(L, "linear", _cocos2d_tweenfunc_linear);
    oluacls_func(L, "quadEaseIn", _cocos2d_tweenfunc_quadEaseIn);
    oluacls_func(L, "quadEaseInOut", _cocos2d_tweenfunc_quadEaseInOut);
    oluacls_func(L, "quadEaseOut", _cocos2d_tweenfunc_quadEaseOut);
    oluacls_func(L, "quadraticIn", _cocos2d_tweenfunc_quadraticIn);
    oluacls_func(L, "quadraticInOut", _cocos2d_tweenfunc_quadraticInOut);
    oluacls_func(L, "quadraticOut", _cocos2d_tweenfunc_quadraticOut);
    oluacls_func(L, "quartEaseIn", _cocos2d_tweenfunc_quartEaseIn);
    oluacls_func(L, "quartEaseInOut", _cocos2d_tweenfunc_quartEaseInOut);
    oluacls_func(L, "quartEaseOut", _cocos2d_tweenfunc_quartEaseOut);
    oluacls_func(L, "quintEaseIn", _cocos2d_tweenfunc_quintEaseIn);
    oluacls_func(L, "quintEaseInOut", _cocos2d_tweenfunc_quintEaseInOut);
    oluacls_func(L, "quintEaseOut", _cocos2d_tweenfunc_quintEaseOut);
    oluacls_func(L, "sineEaseIn", _cocos2d_tweenfunc_sineEaseIn);
    oluacls_func(L, "sineEaseInOut", _cocos2d_tweenfunc_sineEaseInOut);
    oluacls_func(L, "sineEaseOut", _cocos2d_tweenfunc_sineEaseOut);
    oluacls_func(L, "tweenTo", _cocos2d_tweenfunc_tweenTo);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_ActionInterval_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ActionInterval");

    // cocos2d::ActionInterval *clone()
    cocos2d::ActionInterval *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.ActionInterval");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ActionInterval_getAmplitudeRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ActionInterval");

    // float getAmplitudeRate()
    float ret = self->getAmplitudeRate();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ActionInterval_getElapsed(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ActionInterval");

    // float getElapsed()
    float ret = self->getElapsed();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ActionInterval_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ActionInterval");

    // cocos2d::ActionInterval *reverse()
    cocos2d::ActionInterval *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionInterval");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ActionInterval_setAmplitudeRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *self = nullptr;
    float arg1 = 0;       /** amp */

    olua_to_object(L, 1, &self, "cc.ActionInterval");
    olua_check_number(L, 2, &arg1);

    // void setAmplitudeRate(float amp)
    self->setAmplitudeRate(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_ActionInterval(lua_State *L)
{
    oluacls_class<cocos2d::ActionInterval, cocos2d::FiniteTimeAction>(L, "cc.ActionInterval");
    oluacls_func(L, "clone", _cocos2d_ActionInterval_clone);
    oluacls_func(L, "getAmplitudeRate", _cocos2d_ActionInterval_getAmplitudeRate);
    oluacls_func(L, "getElapsed", _cocos2d_ActionInterval_getElapsed);
    oluacls_func(L, "reverse", _cocos2d_ActionInterval_reverse);
    oluacls_func(L, "setAmplitudeRate", _cocos2d_ActionInterval_setAmplitudeRate);
    oluacls_prop(L, "amplitudeRate", _cocos2d_ActionInterval_getAmplitudeRate, _cocos2d_ActionInterval_setAmplitudeRate);
    oluacls_prop(L, "elapsed", _cocos2d_ActionInterval_getElapsed, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_ActionTween_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionTween *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ActionTween");

    // cocos2d::ActionTween *clone()
    cocos2d::ActionTween *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.ActionTween");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ActionTween_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    std::string arg2;       /** key */
    float arg3 = 0;       /** from */
    float arg4 = 0;       /** to */

    olua_check_number(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // static cocos2d::ActionTween *create(float duration, const std::string &key, float from, float to)
    cocos2d::ActionTween *ret = cocos2d::ActionTween::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.ActionTween");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ActionTween_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionTween *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ActionTween");

    // cocos2d::ActionTween *reverse()
    cocos2d::ActionTween *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionTween");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_ActionTween(lua_State *L)
{
    oluacls_class<cocos2d::ActionTween, cocos2d::ActionInterval>(L, "cc.ActionTween");
    oluacls_func(L, "clone", _cocos2d_ActionTween_clone);
    oluacls_func(L, "create", _cocos2d_ActionTween_create);
    oluacls_func(L, "reverse", _cocos2d_ActionTween_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_Sequence_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Sequence *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Sequence");

    // cocos2d::Sequence *clone()
    cocos2d::Sequence *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.Sequence");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Sequence_create$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */
    cocos2d::FiniteTimeAction *arg4 = nullptr;       /** action1_$3 */
    cocos2d::FiniteTimeAction *arg5 = nullptr;       /** action1_$4 */
    cocos2d::FiniteTimeAction *arg6 = nullptr;       /** action1_$5 */
    cocos2d::FiniteTimeAction *arg7 = nullptr;       /** action1_$6 */
    cocos2d::FiniteTimeAction *arg8 = nullptr;       /** action1_$7 */
    cocos2d::FiniteTimeAction *arg9 = nullptr;       /** action1_$8 */
    cocos2d::FiniteTimeAction *arg10 = nullptr;       /** action1_$9 */
    cocos2d::FiniteTimeAction *arg11 = nullptr;       /** action1_$10 */
    cocos2d::FiniteTimeAction *arg12 = nullptr;       /** action1_$11 */
    cocos2d::FiniteTimeAction *arg13 = nullptr;       /** action1_$12 */
    cocos2d::FiniteTimeAction *arg14 = nullptr;       /** action1_$13 */
    cocos2d::FiniteTimeAction *arg15 = nullptr;       /** action1_$14 */
    cocos2d::FiniteTimeAction *arg16 = nullptr;       /** action1_$15 */
    cocos2d::FiniteTimeAction *arg17 = nullptr;       /** action1_$16 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");
    olua_check_object(L, 4, &arg4, "cc.FiniteTimeAction");
    olua_check_object(L, 5, &arg5, "cc.FiniteTimeAction");
    olua_check_object(L, 6, &arg6, "cc.FiniteTimeAction");
    olua_check_object(L, 7, &arg7, "cc.FiniteTimeAction");
    olua_check_object(L, 8, &arg8, "cc.FiniteTimeAction");
    olua_check_object(L, 9, &arg9, "cc.FiniteTimeAction");
    olua_check_object(L, 10, &arg10, "cc.FiniteTimeAction");
    olua_check_object(L, 11, &arg11, "cc.FiniteTimeAction");
    olua_check_object(L, 12, &arg12, "cc.FiniteTimeAction");
    olua_check_object(L, 13, &arg13, "cc.FiniteTimeAction");
    olua_check_object(L, 14, &arg14, "cc.FiniteTimeAction");
    olua_check_object(L, 15, &arg15, "cc.FiniteTimeAction");
    olua_check_object(L, 16, &arg16, "cc.FiniteTimeAction");
    olua_check_object(L, 17, &arg17, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Sequence *ret = cocos2d::Sequence::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Sequence");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 4, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 5, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 6, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 7, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 8, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 9, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 10, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 11, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 12, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 13, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 14, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 15, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 16, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 17, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Sequence_create$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vector<cocos2d::FiniteTimeAction *> arg1;       /** arrayOfActions */

    olua_check_array<cocos2d::FiniteTimeAction *>(L, 1, arg1, [L](cocos2d::FiniteTimeAction **arg1) {
        olua_check_object(L, -1, arg1, "cc.FiniteTimeAction");
    });

    // static cocos2d::Sequence *create(@addref(actions |) const cocos2d::Vector<cocos2d::FiniteTimeAction *> &arrayOfActions)
    cocos2d::Sequence *ret = cocos2d::Sequence::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.Sequence");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI | OLUA_REF_TABLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Sequence_create$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Sequence *ret = cocos2d::Sequence::create(arg1, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Sequence");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Sequence_create$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Sequence *ret = cocos2d::Sequence::create(arg1, arg2, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Sequence");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Sequence_create$5(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Sequence *ret = cocos2d::Sequence::create(arg1, arg2, arg3, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Sequence");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Sequence_create$6(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */
    cocos2d::FiniteTimeAction *arg4 = nullptr;       /** action1_$3 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");
    olua_check_object(L, 4, &arg4, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Sequence *ret = cocos2d::Sequence::create(arg1, arg2, arg3, arg4, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Sequence");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 4, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Sequence_create$7(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */
    cocos2d::FiniteTimeAction *arg4 = nullptr;       /** action1_$3 */
    cocos2d::FiniteTimeAction *arg5 = nullptr;       /** action1_$4 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");
    olua_check_object(L, 4, &arg4, "cc.FiniteTimeAction");
    olua_check_object(L, 5, &arg5, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Sequence *ret = cocos2d::Sequence::create(arg1, arg2, arg3, arg4, arg5, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Sequence");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 4, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 5, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Sequence_create$8(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */
    cocos2d::FiniteTimeAction *arg4 = nullptr;       /** action1_$3 */
    cocos2d::FiniteTimeAction *arg5 = nullptr;       /** action1_$4 */
    cocos2d::FiniteTimeAction *arg6 = nullptr;       /** action1_$5 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");
    olua_check_object(L, 4, &arg4, "cc.FiniteTimeAction");
    olua_check_object(L, 5, &arg5, "cc.FiniteTimeAction");
    olua_check_object(L, 6, &arg6, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Sequence *ret = cocos2d::Sequence::create(arg1, arg2, arg3, arg4, arg5, arg6, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Sequence");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 4, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 5, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 6, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Sequence_create$9(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */
    cocos2d::FiniteTimeAction *arg4 = nullptr;       /** action1_$3 */
    cocos2d::FiniteTimeAction *arg5 = nullptr;       /** action1_$4 */
    cocos2d::FiniteTimeAction *arg6 = nullptr;       /** action1_$5 */
    cocos2d::FiniteTimeAction *arg7 = nullptr;       /** action1_$6 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");
    olua_check_object(L, 4, &arg4, "cc.FiniteTimeAction");
    olua_check_object(L, 5, &arg5, "cc.FiniteTimeAction");
    olua_check_object(L, 6, &arg6, "cc.FiniteTimeAction");
    olua_check_object(L, 7, &arg7, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Sequence *ret = cocos2d::Sequence::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Sequence");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 4, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 5, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 6, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 7, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Sequence_create$10(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */
    cocos2d::FiniteTimeAction *arg4 = nullptr;       /** action1_$3 */
    cocos2d::FiniteTimeAction *arg5 = nullptr;       /** action1_$4 */
    cocos2d::FiniteTimeAction *arg6 = nullptr;       /** action1_$5 */
    cocos2d::FiniteTimeAction *arg7 = nullptr;       /** action1_$6 */
    cocos2d::FiniteTimeAction *arg8 = nullptr;       /** action1_$7 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");
    olua_check_object(L, 4, &arg4, "cc.FiniteTimeAction");
    olua_check_object(L, 5, &arg5, "cc.FiniteTimeAction");
    olua_check_object(L, 6, &arg6, "cc.FiniteTimeAction");
    olua_check_object(L, 7, &arg7, "cc.FiniteTimeAction");
    olua_check_object(L, 8, &arg8, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Sequence *ret = cocos2d::Sequence::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Sequence");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 4, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 5, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 6, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 7, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 8, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Sequence_create$11(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */
    cocos2d::FiniteTimeAction *arg4 = nullptr;       /** action1_$3 */
    cocos2d::FiniteTimeAction *arg5 = nullptr;       /** action1_$4 */
    cocos2d::FiniteTimeAction *arg6 = nullptr;       /** action1_$5 */
    cocos2d::FiniteTimeAction *arg7 = nullptr;       /** action1_$6 */
    cocos2d::FiniteTimeAction *arg8 = nullptr;       /** action1_$7 */
    cocos2d::FiniteTimeAction *arg9 = nullptr;       /** action1_$8 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");
    olua_check_object(L, 4, &arg4, "cc.FiniteTimeAction");
    olua_check_object(L, 5, &arg5, "cc.FiniteTimeAction");
    olua_check_object(L, 6, &arg6, "cc.FiniteTimeAction");
    olua_check_object(L, 7, &arg7, "cc.FiniteTimeAction");
    olua_check_object(L, 8, &arg8, "cc.FiniteTimeAction");
    olua_check_object(L, 9, &arg9, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Sequence *ret = cocos2d::Sequence::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Sequence");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 4, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 5, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 6, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 7, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 8, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 9, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Sequence_create$12(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */
    cocos2d::FiniteTimeAction *arg4 = nullptr;       /** action1_$3 */
    cocos2d::FiniteTimeAction *arg5 = nullptr;       /** action1_$4 */
    cocos2d::FiniteTimeAction *arg6 = nullptr;       /** action1_$5 */
    cocos2d::FiniteTimeAction *arg7 = nullptr;       /** action1_$6 */
    cocos2d::FiniteTimeAction *arg8 = nullptr;       /** action1_$7 */
    cocos2d::FiniteTimeAction *arg9 = nullptr;       /** action1_$8 */
    cocos2d::FiniteTimeAction *arg10 = nullptr;       /** action1_$9 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");
    olua_check_object(L, 4, &arg4, "cc.FiniteTimeAction");
    olua_check_object(L, 5, &arg5, "cc.FiniteTimeAction");
    olua_check_object(L, 6, &arg6, "cc.FiniteTimeAction");
    olua_check_object(L, 7, &arg7, "cc.FiniteTimeAction");
    olua_check_object(L, 8, &arg8, "cc.FiniteTimeAction");
    olua_check_object(L, 9, &arg9, "cc.FiniteTimeAction");
    olua_check_object(L, 10, &arg10, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Sequence *ret = cocos2d::Sequence::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Sequence");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 4, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 5, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 6, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 7, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 8, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 9, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 10, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Sequence_create$13(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */
    cocos2d::FiniteTimeAction *arg4 = nullptr;       /** action1_$3 */
    cocos2d::FiniteTimeAction *arg5 = nullptr;       /** action1_$4 */
    cocos2d::FiniteTimeAction *arg6 = nullptr;       /** action1_$5 */
    cocos2d::FiniteTimeAction *arg7 = nullptr;       /** action1_$6 */
    cocos2d::FiniteTimeAction *arg8 = nullptr;       /** action1_$7 */
    cocos2d::FiniteTimeAction *arg9 = nullptr;       /** action1_$8 */
    cocos2d::FiniteTimeAction *arg10 = nullptr;       /** action1_$9 */
    cocos2d::FiniteTimeAction *arg11 = nullptr;       /** action1_$10 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");
    olua_check_object(L, 4, &arg4, "cc.FiniteTimeAction");
    olua_check_object(L, 5, &arg5, "cc.FiniteTimeAction");
    olua_check_object(L, 6, &arg6, "cc.FiniteTimeAction");
    olua_check_object(L, 7, &arg7, "cc.FiniteTimeAction");
    olua_check_object(L, 8, &arg8, "cc.FiniteTimeAction");
    olua_check_object(L, 9, &arg9, "cc.FiniteTimeAction");
    olua_check_object(L, 10, &arg10, "cc.FiniteTimeAction");
    olua_check_object(L, 11, &arg11, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Sequence *ret = cocos2d::Sequence::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Sequence");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 4, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 5, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 6, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 7, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 8, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 9, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 10, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 11, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Sequence_create$14(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */
    cocos2d::FiniteTimeAction *arg4 = nullptr;       /** action1_$3 */
    cocos2d::FiniteTimeAction *arg5 = nullptr;       /** action1_$4 */
    cocos2d::FiniteTimeAction *arg6 = nullptr;       /** action1_$5 */
    cocos2d::FiniteTimeAction *arg7 = nullptr;       /** action1_$6 */
    cocos2d::FiniteTimeAction *arg8 = nullptr;       /** action1_$7 */
    cocos2d::FiniteTimeAction *arg9 = nullptr;       /** action1_$8 */
    cocos2d::FiniteTimeAction *arg10 = nullptr;       /** action1_$9 */
    cocos2d::FiniteTimeAction *arg11 = nullptr;       /** action1_$10 */
    cocos2d::FiniteTimeAction *arg12 = nullptr;       /** action1_$11 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");
    olua_check_object(L, 4, &arg4, "cc.FiniteTimeAction");
    olua_check_object(L, 5, &arg5, "cc.FiniteTimeAction");
    olua_check_object(L, 6, &arg6, "cc.FiniteTimeAction");
    olua_check_object(L, 7, &arg7, "cc.FiniteTimeAction");
    olua_check_object(L, 8, &arg8, "cc.FiniteTimeAction");
    olua_check_object(L, 9, &arg9, "cc.FiniteTimeAction");
    olua_check_object(L, 10, &arg10, "cc.FiniteTimeAction");
    olua_check_object(L, 11, &arg11, "cc.FiniteTimeAction");
    olua_check_object(L, 12, &arg12, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Sequence *ret = cocos2d::Sequence::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Sequence");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 4, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 5, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 6, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 7, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 8, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 9, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 10, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 11, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 12, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Sequence_create$15(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */
    cocos2d::FiniteTimeAction *arg4 = nullptr;       /** action1_$3 */
    cocos2d::FiniteTimeAction *arg5 = nullptr;       /** action1_$4 */
    cocos2d::FiniteTimeAction *arg6 = nullptr;       /** action1_$5 */
    cocos2d::FiniteTimeAction *arg7 = nullptr;       /** action1_$6 */
    cocos2d::FiniteTimeAction *arg8 = nullptr;       /** action1_$7 */
    cocos2d::FiniteTimeAction *arg9 = nullptr;       /** action1_$8 */
    cocos2d::FiniteTimeAction *arg10 = nullptr;       /** action1_$9 */
    cocos2d::FiniteTimeAction *arg11 = nullptr;       /** action1_$10 */
    cocos2d::FiniteTimeAction *arg12 = nullptr;       /** action1_$11 */
    cocos2d::FiniteTimeAction *arg13 = nullptr;       /** action1_$12 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");
    olua_check_object(L, 4, &arg4, "cc.FiniteTimeAction");
    olua_check_object(L, 5, &arg5, "cc.FiniteTimeAction");
    olua_check_object(L, 6, &arg6, "cc.FiniteTimeAction");
    olua_check_object(L, 7, &arg7, "cc.FiniteTimeAction");
    olua_check_object(L, 8, &arg8, "cc.FiniteTimeAction");
    olua_check_object(L, 9, &arg9, "cc.FiniteTimeAction");
    olua_check_object(L, 10, &arg10, "cc.FiniteTimeAction");
    olua_check_object(L, 11, &arg11, "cc.FiniteTimeAction");
    olua_check_object(L, 12, &arg12, "cc.FiniteTimeAction");
    olua_check_object(L, 13, &arg13, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Sequence *ret = cocos2d::Sequence::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Sequence");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 4, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 5, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 6, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 7, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 8, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 9, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 10, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 11, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 12, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 13, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Sequence_create$16(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */
    cocos2d::FiniteTimeAction *arg4 = nullptr;       /** action1_$3 */
    cocos2d::FiniteTimeAction *arg5 = nullptr;       /** action1_$4 */
    cocos2d::FiniteTimeAction *arg6 = nullptr;       /** action1_$5 */
    cocos2d::FiniteTimeAction *arg7 = nullptr;       /** action1_$6 */
    cocos2d::FiniteTimeAction *arg8 = nullptr;       /** action1_$7 */
    cocos2d::FiniteTimeAction *arg9 = nullptr;       /** action1_$8 */
    cocos2d::FiniteTimeAction *arg10 = nullptr;       /** action1_$9 */
    cocos2d::FiniteTimeAction *arg11 = nullptr;       /** action1_$10 */
    cocos2d::FiniteTimeAction *arg12 = nullptr;       /** action1_$11 */
    cocos2d::FiniteTimeAction *arg13 = nullptr;       /** action1_$12 */
    cocos2d::FiniteTimeAction *arg14 = nullptr;       /** action1_$13 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");
    olua_check_object(L, 4, &arg4, "cc.FiniteTimeAction");
    olua_check_object(L, 5, &arg5, "cc.FiniteTimeAction");
    olua_check_object(L, 6, &arg6, "cc.FiniteTimeAction");
    olua_check_object(L, 7, &arg7, "cc.FiniteTimeAction");
    olua_check_object(L, 8, &arg8, "cc.FiniteTimeAction");
    olua_check_object(L, 9, &arg9, "cc.FiniteTimeAction");
    olua_check_object(L, 10, &arg10, "cc.FiniteTimeAction");
    olua_check_object(L, 11, &arg11, "cc.FiniteTimeAction");
    olua_check_object(L, 12, &arg12, "cc.FiniteTimeAction");
    olua_check_object(L, 13, &arg13, "cc.FiniteTimeAction");
    olua_check_object(L, 14, &arg14, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Sequence *ret = cocos2d::Sequence::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Sequence");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 4, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 5, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 6, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 7, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 8, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 9, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 10, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 11, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 12, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 13, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 14, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Sequence_create$17(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */
    cocos2d::FiniteTimeAction *arg4 = nullptr;       /** action1_$3 */
    cocos2d::FiniteTimeAction *arg5 = nullptr;       /** action1_$4 */
    cocos2d::FiniteTimeAction *arg6 = nullptr;       /** action1_$5 */
    cocos2d::FiniteTimeAction *arg7 = nullptr;       /** action1_$6 */
    cocos2d::FiniteTimeAction *arg8 = nullptr;       /** action1_$7 */
    cocos2d::FiniteTimeAction *arg9 = nullptr;       /** action1_$8 */
    cocos2d::FiniteTimeAction *arg10 = nullptr;       /** action1_$9 */
    cocos2d::FiniteTimeAction *arg11 = nullptr;       /** action1_$10 */
    cocos2d::FiniteTimeAction *arg12 = nullptr;       /** action1_$11 */
    cocos2d::FiniteTimeAction *arg13 = nullptr;       /** action1_$12 */
    cocos2d::FiniteTimeAction *arg14 = nullptr;       /** action1_$13 */
    cocos2d::FiniteTimeAction *arg15 = nullptr;       /** action1_$14 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");
    olua_check_object(L, 4, &arg4, "cc.FiniteTimeAction");
    olua_check_object(L, 5, &arg5, "cc.FiniteTimeAction");
    olua_check_object(L, 6, &arg6, "cc.FiniteTimeAction");
    olua_check_object(L, 7, &arg7, "cc.FiniteTimeAction");
    olua_check_object(L, 8, &arg8, "cc.FiniteTimeAction");
    olua_check_object(L, 9, &arg9, "cc.FiniteTimeAction");
    olua_check_object(L, 10, &arg10, "cc.FiniteTimeAction");
    olua_check_object(L, 11, &arg11, "cc.FiniteTimeAction");
    olua_check_object(L, 12, &arg12, "cc.FiniteTimeAction");
    olua_check_object(L, 13, &arg13, "cc.FiniteTimeAction");
    olua_check_object(L, 14, &arg14, "cc.FiniteTimeAction");
    olua_check_object(L, 15, &arg15, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Sequence *ret = cocos2d::Sequence::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Sequence");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 4, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 5, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 6, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 7, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 8, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 9, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 10, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 11, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 12, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 13, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 14, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 15, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Sequence_create$18(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */
    cocos2d::FiniteTimeAction *arg4 = nullptr;       /** action1_$3 */
    cocos2d::FiniteTimeAction *arg5 = nullptr;       /** action1_$4 */
    cocos2d::FiniteTimeAction *arg6 = nullptr;       /** action1_$5 */
    cocos2d::FiniteTimeAction *arg7 = nullptr;       /** action1_$6 */
    cocos2d::FiniteTimeAction *arg8 = nullptr;       /** action1_$7 */
    cocos2d::FiniteTimeAction *arg9 = nullptr;       /** action1_$8 */
    cocos2d::FiniteTimeAction *arg10 = nullptr;       /** action1_$9 */
    cocos2d::FiniteTimeAction *arg11 = nullptr;       /** action1_$10 */
    cocos2d::FiniteTimeAction *arg12 = nullptr;       /** action1_$11 */
    cocos2d::FiniteTimeAction *arg13 = nullptr;       /** action1_$12 */
    cocos2d::FiniteTimeAction *arg14 = nullptr;       /** action1_$13 */
    cocos2d::FiniteTimeAction *arg15 = nullptr;       /** action1_$14 */
    cocos2d::FiniteTimeAction *arg16 = nullptr;       /** action1_$15 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");
    olua_check_object(L, 4, &arg4, "cc.FiniteTimeAction");
    olua_check_object(L, 5, &arg5, "cc.FiniteTimeAction");
    olua_check_object(L, 6, &arg6, "cc.FiniteTimeAction");
    olua_check_object(L, 7, &arg7, "cc.FiniteTimeAction");
    olua_check_object(L, 8, &arg8, "cc.FiniteTimeAction");
    olua_check_object(L, 9, &arg9, "cc.FiniteTimeAction");
    olua_check_object(L, 10, &arg10, "cc.FiniteTimeAction");
    olua_check_object(L, 11, &arg11, "cc.FiniteTimeAction");
    olua_check_object(L, 12, &arg12, "cc.FiniteTimeAction");
    olua_check_object(L, 13, &arg13, "cc.FiniteTimeAction");
    olua_check_object(L, 14, &arg14, "cc.FiniteTimeAction");
    olua_check_object(L, 15, &arg15, "cc.FiniteTimeAction");
    olua_check_object(L, 16, &arg16, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Sequence *ret = cocos2d::Sequence::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Sequence");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 4, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 5, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 6, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 7, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 8, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 9, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 10, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 11, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 12, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 13, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 14, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 15, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 16, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Sequence_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        if ((olua_is_array(L, 1))) {
            // static cocos2d::Sequence *create(@addref(actions |) const cocos2d::Vector<cocos2d::FiniteTimeAction *> &arrayOfActions)
            return _cocos2d_Sequence_create$2(L);
        }

        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Sequence_create$3(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Sequence_create$4(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Sequence_create$5(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction")) && (olua_is_object(L, 4, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Sequence_create$6(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction")) && (olua_is_object(L, 4, "cc.FiniteTimeAction")) && (olua_is_object(L, 5, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Sequence_create$7(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction")) && (olua_is_object(L, 4, "cc.FiniteTimeAction")) && (olua_is_object(L, 5, "cc.FiniteTimeAction")) && (olua_is_object(L, 6, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Sequence_create$8(L);
        // }
    }

    if (num_args == 7) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction")) && (olua_is_object(L, 4, "cc.FiniteTimeAction")) && (olua_is_object(L, 5, "cc.FiniteTimeAction")) && (olua_is_object(L, 6, "cc.FiniteTimeAction")) && (olua_is_object(L, 7, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Sequence_create$9(L);
        // }
    }

    if (num_args == 8) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction")) && (olua_is_object(L, 4, "cc.FiniteTimeAction")) && (olua_is_object(L, 5, "cc.FiniteTimeAction")) && (olua_is_object(L, 6, "cc.FiniteTimeAction")) && (olua_is_object(L, 7, "cc.FiniteTimeAction")) && (olua_is_object(L, 8, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Sequence_create$10(L);
        // }
    }

    if (num_args == 9) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction")) && (olua_is_object(L, 4, "cc.FiniteTimeAction")) && (olua_is_object(L, 5, "cc.FiniteTimeAction")) && (olua_is_object(L, 6, "cc.FiniteTimeAction")) && (olua_is_object(L, 7, "cc.FiniteTimeAction")) && (olua_is_object(L, 8, "cc.FiniteTimeAction")) && (olua_is_object(L, 9, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Sequence_create$11(L);
        // }
    }

    if (num_args == 10) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction")) && (olua_is_object(L, 4, "cc.FiniteTimeAction")) && (olua_is_object(L, 5, "cc.FiniteTimeAction")) && (olua_is_object(L, 6, "cc.FiniteTimeAction")) && (olua_is_object(L, 7, "cc.FiniteTimeAction")) && (olua_is_object(L, 8, "cc.FiniteTimeAction")) && (olua_is_object(L, 9, "cc.FiniteTimeAction")) && (olua_is_object(L, 10, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Sequence_create$12(L);
        // }
    }

    if (num_args == 11) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction")) && (olua_is_object(L, 4, "cc.FiniteTimeAction")) && (olua_is_object(L, 5, "cc.FiniteTimeAction")) && (olua_is_object(L, 6, "cc.FiniteTimeAction")) && (olua_is_object(L, 7, "cc.FiniteTimeAction")) && (olua_is_object(L, 8, "cc.FiniteTimeAction")) && (olua_is_object(L, 9, "cc.FiniteTimeAction")) && (olua_is_object(L, 10, "cc.FiniteTimeAction")) && (olua_is_object(L, 11, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Sequence_create$13(L);
        // }
    }

    if (num_args == 12) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction")) && (olua_is_object(L, 4, "cc.FiniteTimeAction")) && (olua_is_object(L, 5, "cc.FiniteTimeAction")) && (olua_is_object(L, 6, "cc.FiniteTimeAction")) && (olua_is_object(L, 7, "cc.FiniteTimeAction")) && (olua_is_object(L, 8, "cc.FiniteTimeAction")) && (olua_is_object(L, 9, "cc.FiniteTimeAction")) && (olua_is_object(L, 10, "cc.FiniteTimeAction")) && (olua_is_object(L, 11, "cc.FiniteTimeAction")) && (olua_is_object(L, 12, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Sequence_create$14(L);
        // }
    }

    if (num_args == 13) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction")) && (olua_is_object(L, 4, "cc.FiniteTimeAction")) && (olua_is_object(L, 5, "cc.FiniteTimeAction")) && (olua_is_object(L, 6, "cc.FiniteTimeAction")) && (olua_is_object(L, 7, "cc.FiniteTimeAction")) && (olua_is_object(L, 8, "cc.FiniteTimeAction")) && (olua_is_object(L, 9, "cc.FiniteTimeAction")) && (olua_is_object(L, 10, "cc.FiniteTimeAction")) && (olua_is_object(L, 11, "cc.FiniteTimeAction")) && (olua_is_object(L, 12, "cc.FiniteTimeAction")) && (olua_is_object(L, 13, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Sequence_create$15(L);
        // }
    }

    if (num_args == 14) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction")) && (olua_is_object(L, 4, "cc.FiniteTimeAction")) && (olua_is_object(L, 5, "cc.FiniteTimeAction")) && (olua_is_object(L, 6, "cc.FiniteTimeAction")) && (olua_is_object(L, 7, "cc.FiniteTimeAction")) && (olua_is_object(L, 8, "cc.FiniteTimeAction")) && (olua_is_object(L, 9, "cc.FiniteTimeAction")) && (olua_is_object(L, 10, "cc.FiniteTimeAction")) && (olua_is_object(L, 11, "cc.FiniteTimeAction")) && (olua_is_object(L, 12, "cc.FiniteTimeAction")) && (olua_is_object(L, 13, "cc.FiniteTimeAction")) && (olua_is_object(L, 14, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Sequence_create$16(L);
        // }
    }

    if (num_args == 15) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction")) && (olua_is_object(L, 4, "cc.FiniteTimeAction")) && (olua_is_object(L, 5, "cc.FiniteTimeAction")) && (olua_is_object(L, 6, "cc.FiniteTimeAction")) && (olua_is_object(L, 7, "cc.FiniteTimeAction")) && (olua_is_object(L, 8, "cc.FiniteTimeAction")) && (olua_is_object(L, 9, "cc.FiniteTimeAction")) && (olua_is_object(L, 10, "cc.FiniteTimeAction")) && (olua_is_object(L, 11, "cc.FiniteTimeAction")) && (olua_is_object(L, 12, "cc.FiniteTimeAction")) && (olua_is_object(L, 13, "cc.FiniteTimeAction")) && (olua_is_object(L, 14, "cc.FiniteTimeAction")) && (olua_is_object(L, 15, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Sequence_create$17(L);
        // }
    }

    if (num_args == 16) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction")) && (olua_is_object(L, 4, "cc.FiniteTimeAction")) && (olua_is_object(L, 5, "cc.FiniteTimeAction")) && (olua_is_object(L, 6, "cc.FiniteTimeAction")) && (olua_is_object(L, 7, "cc.FiniteTimeAction")) && (olua_is_object(L, 8, "cc.FiniteTimeAction")) && (olua_is_object(L, 9, "cc.FiniteTimeAction")) && (olua_is_object(L, 10, "cc.FiniteTimeAction")) && (olua_is_object(L, 11, "cc.FiniteTimeAction")) && (olua_is_object(L, 12, "cc.FiniteTimeAction")) && (olua_is_object(L, 13, "cc.FiniteTimeAction")) && (olua_is_object(L, 14, "cc.FiniteTimeAction")) && (olua_is_object(L, 15, "cc.FiniteTimeAction")) && (olua_is_object(L, 16, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Sequence_create$18(L);
        // }
    }

    if (num_args == 17) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction")) && (olua_is_object(L, 4, "cc.FiniteTimeAction")) && (olua_is_object(L, 5, "cc.FiniteTimeAction")) && (olua_is_object(L, 6, "cc.FiniteTimeAction")) && (olua_is_object(L, 7, "cc.FiniteTimeAction")) && (olua_is_object(L, 8, "cc.FiniteTimeAction")) && (olua_is_object(L, 9, "cc.FiniteTimeAction")) && (olua_is_object(L, 10, "cc.FiniteTimeAction")) && (olua_is_object(L, 11, "cc.FiniteTimeAction")) && (olua_is_object(L, 12, "cc.FiniteTimeAction")) && (olua_is_object(L, 13, "cc.FiniteTimeAction")) && (olua_is_object(L, 14, "cc.FiniteTimeAction")) && (olua_is_object(L, 15, "cc.FiniteTimeAction")) && (olua_is_object(L, 16, "cc.FiniteTimeAction")) && (olua_is_object(L, 17, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Sequence *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Sequence_create$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Sequence::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_Sequence_createWithTwoActions(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** actionOne */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** actionTwo */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");

    // static cocos2d::Sequence *createWithTwoActions(@addref(actions |) cocos2d::FiniteTimeAction *actionOne, @addref(actions |) cocos2d::FiniteTimeAction *actionTwo)
    cocos2d::Sequence *ret = cocos2d::Sequence::createWithTwoActions(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.Sequence");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Sequence_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Sequence *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Sequence");

    // cocos2d::Sequence *reverse()
    cocos2d::Sequence *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.Sequence");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_Sequence(lua_State *L)
{
    oluacls_class<cocos2d::Sequence, cocos2d::ActionInterval>(L, "cc.Sequence");
    oluacls_func(L, "clone", _cocos2d_Sequence_clone);
    oluacls_func(L, "create", _cocos2d_Sequence_create);
    oluacls_func(L, "createWithTwoActions", _cocos2d_Sequence_createWithTwoActions);
    oluacls_func(L, "reverse", _cocos2d_Sequence_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_Repeat_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Repeat *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Repeat");

    // cocos2d::Repeat *clone()
    cocos2d::Repeat *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.Repeat");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Repeat_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action */
    unsigned int arg2 = 0;       /** times */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_integer(L, 2, &arg2);

    // static cocos2d::Repeat *create(@addref(innerAction ^) cocos2d::FiniteTimeAction *action, unsigned int times)
    cocos2d::Repeat *ret = cocos2d::Repeat::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.Repeat");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Repeat_getInnerAction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Repeat *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Repeat");

    // @addref(innerAction ^) cocos2d::FiniteTimeAction *getInnerAction()
    cocos2d::FiniteTimeAction *ret = self->getInnerAction();
    int num_ret = olua_push_object(L, ret, "cc.FiniteTimeAction");

    // insert code after call
    olua_addref(L, 1, "innerAction", -1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Repeat_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Repeat *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Repeat");

    // cocos2d::Repeat *reverse()
    cocos2d::Repeat *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.Repeat");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Repeat_setInnerAction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Repeat *self = nullptr;
    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action */

    olua_to_object(L, 1, &self, "cc.Repeat");
    olua_check_object(L, 2, &arg1, "cc.FiniteTimeAction");

    // void setInnerAction(@addref(innerAction ^) cocos2d::FiniteTimeAction *action)
    self->setInnerAction(arg1);

    // insert code after call
    olua_addref(L, 1, "innerAction", 2, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_Repeat(lua_State *L)
{
    oluacls_class<cocos2d::Repeat, cocos2d::ActionInterval>(L, "cc.Repeat");
    oluacls_func(L, "clone", _cocos2d_Repeat_clone);
    oluacls_func(L, "create", _cocos2d_Repeat_create);
    oluacls_func(L, "getInnerAction", _cocos2d_Repeat_getInnerAction);
    oluacls_func(L, "reverse", _cocos2d_Repeat_reverse);
    oluacls_func(L, "setInnerAction", _cocos2d_Repeat_setInnerAction);
    oluacls_prop(L, "innerAction", _cocos2d_Repeat_getInnerAction, _cocos2d_Repeat_setInnerAction);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_RepeatForever_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::RepeatForever *self = nullptr;

    olua_to_object(L, 1, &self, "cc.RepeatForever");

    // cocos2d::RepeatForever *clone()
    cocos2d::RepeatForever *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.RepeatForever");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_RepeatForever_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::RepeatForever *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::RepeatForever *ret = cocos2d::RepeatForever::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.RepeatForever");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_RepeatForever_getInnerAction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::RepeatForever *self = nullptr;

    olua_to_object(L, 1, &self, "cc.RepeatForever");

    // @addref(innerAction ^) cocos2d::ActionInterval *getInnerAction()
    cocos2d::ActionInterval *ret = self->getInnerAction();
    int num_ret = olua_push_object(L, ret, "cc.ActionInterval");

    // insert code after call
    olua_addref(L, 1, "innerAction", -1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_RepeatForever_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::RepeatForever *self = nullptr;

    olua_to_object(L, 1, &self, "cc.RepeatForever");

    // cocos2d::RepeatForever *reverse()
    cocos2d::RepeatForever *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.RepeatForever");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_RepeatForever_setInnerAction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::RepeatForever *self = nullptr;
    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_to_object(L, 1, &self, "cc.RepeatForever");
    olua_check_object(L, 2, &arg1, "cc.ActionInterval");

    // void setInnerAction(@addref(innerAction ^) cocos2d::ActionInterval *action)
    self->setInnerAction(arg1);

    // insert code after call
    olua_addref(L, 1, "innerAction", 2, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_RepeatForever(lua_State *L)
{
    oluacls_class<cocos2d::RepeatForever, cocos2d::ActionInterval>(L, "cc.RepeatForever");
    oluacls_func(L, "clone", _cocos2d_RepeatForever_clone);
    oluacls_func(L, "create", _cocos2d_RepeatForever_create);
    oluacls_func(L, "getInnerAction", _cocos2d_RepeatForever_getInnerAction);
    oluacls_func(L, "reverse", _cocos2d_RepeatForever_reverse);
    oluacls_func(L, "setInnerAction", _cocos2d_RepeatForever_setInnerAction);
    oluacls_prop(L, "innerAction", _cocos2d_RepeatForever_getInnerAction, _cocos2d_RepeatForever_setInnerAction);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_Spawn_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Spawn *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Spawn");

    // cocos2d::Spawn *clone()
    cocos2d::Spawn *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.Spawn");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Spawn_create$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */
    cocos2d::FiniteTimeAction *arg4 = nullptr;       /** action1_$3 */
    cocos2d::FiniteTimeAction *arg5 = nullptr;       /** action1_$4 */
    cocos2d::FiniteTimeAction *arg6 = nullptr;       /** action1_$5 */
    cocos2d::FiniteTimeAction *arg7 = nullptr;       /** action1_$6 */
    cocos2d::FiniteTimeAction *arg8 = nullptr;       /** action1_$7 */
    cocos2d::FiniteTimeAction *arg9 = nullptr;       /** action1_$8 */
    cocos2d::FiniteTimeAction *arg10 = nullptr;       /** action1_$9 */
    cocos2d::FiniteTimeAction *arg11 = nullptr;       /** action1_$10 */
    cocos2d::FiniteTimeAction *arg12 = nullptr;       /** action1_$11 */
    cocos2d::FiniteTimeAction *arg13 = nullptr;       /** action1_$12 */
    cocos2d::FiniteTimeAction *arg14 = nullptr;       /** action1_$13 */
    cocos2d::FiniteTimeAction *arg15 = nullptr;       /** action1_$14 */
    cocos2d::FiniteTimeAction *arg16 = nullptr;       /** action1_$15 */
    cocos2d::FiniteTimeAction *arg17 = nullptr;       /** action1_$16 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");
    olua_check_object(L, 4, &arg4, "cc.FiniteTimeAction");
    olua_check_object(L, 5, &arg5, "cc.FiniteTimeAction");
    olua_check_object(L, 6, &arg6, "cc.FiniteTimeAction");
    olua_check_object(L, 7, &arg7, "cc.FiniteTimeAction");
    olua_check_object(L, 8, &arg8, "cc.FiniteTimeAction");
    olua_check_object(L, 9, &arg9, "cc.FiniteTimeAction");
    olua_check_object(L, 10, &arg10, "cc.FiniteTimeAction");
    olua_check_object(L, 11, &arg11, "cc.FiniteTimeAction");
    olua_check_object(L, 12, &arg12, "cc.FiniteTimeAction");
    olua_check_object(L, 13, &arg13, "cc.FiniteTimeAction");
    olua_check_object(L, 14, &arg14, "cc.FiniteTimeAction");
    olua_check_object(L, 15, &arg15, "cc.FiniteTimeAction");
    olua_check_object(L, 16, &arg16, "cc.FiniteTimeAction");
    olua_check_object(L, 17, &arg17, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Spawn *ret = cocos2d::Spawn::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Spawn");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 4, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 5, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 6, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 7, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 8, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 9, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 10, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 11, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 12, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 13, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 14, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 15, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 16, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 17, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Spawn_create$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vector<cocos2d::FiniteTimeAction *> arg1;       /** arrayOfActions */

    olua_check_array<cocos2d::FiniteTimeAction *>(L, 1, arg1, [L](cocos2d::FiniteTimeAction **arg1) {
        olua_check_object(L, -1, arg1, "cc.FiniteTimeAction");
    });

    // static cocos2d::Spawn *create(@addref(actions |) const cocos2d::Vector<cocos2d::FiniteTimeAction *> &arrayOfActions)
    cocos2d::Spawn *ret = cocos2d::Spawn::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.Spawn");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI | OLUA_REF_TABLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Spawn_create$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Spawn *ret = cocos2d::Spawn::create(arg1, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Spawn");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Spawn_create$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Spawn *ret = cocos2d::Spawn::create(arg1, arg2, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Spawn");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Spawn_create$5(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Spawn *ret = cocos2d::Spawn::create(arg1, arg2, arg3, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Spawn");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Spawn_create$6(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */
    cocos2d::FiniteTimeAction *arg4 = nullptr;       /** action1_$3 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");
    olua_check_object(L, 4, &arg4, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Spawn *ret = cocos2d::Spawn::create(arg1, arg2, arg3, arg4, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Spawn");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 4, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Spawn_create$7(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */
    cocos2d::FiniteTimeAction *arg4 = nullptr;       /** action1_$3 */
    cocos2d::FiniteTimeAction *arg5 = nullptr;       /** action1_$4 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");
    olua_check_object(L, 4, &arg4, "cc.FiniteTimeAction");
    olua_check_object(L, 5, &arg5, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Spawn *ret = cocos2d::Spawn::create(arg1, arg2, arg3, arg4, arg5, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Spawn");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 4, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 5, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Spawn_create$8(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */
    cocos2d::FiniteTimeAction *arg4 = nullptr;       /** action1_$3 */
    cocos2d::FiniteTimeAction *arg5 = nullptr;       /** action1_$4 */
    cocos2d::FiniteTimeAction *arg6 = nullptr;       /** action1_$5 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");
    olua_check_object(L, 4, &arg4, "cc.FiniteTimeAction");
    olua_check_object(L, 5, &arg5, "cc.FiniteTimeAction");
    olua_check_object(L, 6, &arg6, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Spawn *ret = cocos2d::Spawn::create(arg1, arg2, arg3, arg4, arg5, arg6, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Spawn");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 4, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 5, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 6, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Spawn_create$9(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */
    cocos2d::FiniteTimeAction *arg4 = nullptr;       /** action1_$3 */
    cocos2d::FiniteTimeAction *arg5 = nullptr;       /** action1_$4 */
    cocos2d::FiniteTimeAction *arg6 = nullptr;       /** action1_$5 */
    cocos2d::FiniteTimeAction *arg7 = nullptr;       /** action1_$6 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");
    olua_check_object(L, 4, &arg4, "cc.FiniteTimeAction");
    olua_check_object(L, 5, &arg5, "cc.FiniteTimeAction");
    olua_check_object(L, 6, &arg6, "cc.FiniteTimeAction");
    olua_check_object(L, 7, &arg7, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Spawn *ret = cocos2d::Spawn::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Spawn");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 4, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 5, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 6, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 7, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Spawn_create$10(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */
    cocos2d::FiniteTimeAction *arg4 = nullptr;       /** action1_$3 */
    cocos2d::FiniteTimeAction *arg5 = nullptr;       /** action1_$4 */
    cocos2d::FiniteTimeAction *arg6 = nullptr;       /** action1_$5 */
    cocos2d::FiniteTimeAction *arg7 = nullptr;       /** action1_$6 */
    cocos2d::FiniteTimeAction *arg8 = nullptr;       /** action1_$7 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");
    olua_check_object(L, 4, &arg4, "cc.FiniteTimeAction");
    olua_check_object(L, 5, &arg5, "cc.FiniteTimeAction");
    olua_check_object(L, 6, &arg6, "cc.FiniteTimeAction");
    olua_check_object(L, 7, &arg7, "cc.FiniteTimeAction");
    olua_check_object(L, 8, &arg8, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Spawn *ret = cocos2d::Spawn::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Spawn");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 4, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 5, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 6, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 7, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 8, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Spawn_create$11(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */
    cocos2d::FiniteTimeAction *arg4 = nullptr;       /** action1_$3 */
    cocos2d::FiniteTimeAction *arg5 = nullptr;       /** action1_$4 */
    cocos2d::FiniteTimeAction *arg6 = nullptr;       /** action1_$5 */
    cocos2d::FiniteTimeAction *arg7 = nullptr;       /** action1_$6 */
    cocos2d::FiniteTimeAction *arg8 = nullptr;       /** action1_$7 */
    cocos2d::FiniteTimeAction *arg9 = nullptr;       /** action1_$8 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");
    olua_check_object(L, 4, &arg4, "cc.FiniteTimeAction");
    olua_check_object(L, 5, &arg5, "cc.FiniteTimeAction");
    olua_check_object(L, 6, &arg6, "cc.FiniteTimeAction");
    olua_check_object(L, 7, &arg7, "cc.FiniteTimeAction");
    olua_check_object(L, 8, &arg8, "cc.FiniteTimeAction");
    olua_check_object(L, 9, &arg9, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Spawn *ret = cocos2d::Spawn::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Spawn");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 4, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 5, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 6, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 7, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 8, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 9, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Spawn_create$12(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */
    cocos2d::FiniteTimeAction *arg4 = nullptr;       /** action1_$3 */
    cocos2d::FiniteTimeAction *arg5 = nullptr;       /** action1_$4 */
    cocos2d::FiniteTimeAction *arg6 = nullptr;       /** action1_$5 */
    cocos2d::FiniteTimeAction *arg7 = nullptr;       /** action1_$6 */
    cocos2d::FiniteTimeAction *arg8 = nullptr;       /** action1_$7 */
    cocos2d::FiniteTimeAction *arg9 = nullptr;       /** action1_$8 */
    cocos2d::FiniteTimeAction *arg10 = nullptr;       /** action1_$9 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");
    olua_check_object(L, 4, &arg4, "cc.FiniteTimeAction");
    olua_check_object(L, 5, &arg5, "cc.FiniteTimeAction");
    olua_check_object(L, 6, &arg6, "cc.FiniteTimeAction");
    olua_check_object(L, 7, &arg7, "cc.FiniteTimeAction");
    olua_check_object(L, 8, &arg8, "cc.FiniteTimeAction");
    olua_check_object(L, 9, &arg9, "cc.FiniteTimeAction");
    olua_check_object(L, 10, &arg10, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Spawn *ret = cocos2d::Spawn::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Spawn");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 4, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 5, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 6, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 7, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 8, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 9, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 10, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Spawn_create$13(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */
    cocos2d::FiniteTimeAction *arg4 = nullptr;       /** action1_$3 */
    cocos2d::FiniteTimeAction *arg5 = nullptr;       /** action1_$4 */
    cocos2d::FiniteTimeAction *arg6 = nullptr;       /** action1_$5 */
    cocos2d::FiniteTimeAction *arg7 = nullptr;       /** action1_$6 */
    cocos2d::FiniteTimeAction *arg8 = nullptr;       /** action1_$7 */
    cocos2d::FiniteTimeAction *arg9 = nullptr;       /** action1_$8 */
    cocos2d::FiniteTimeAction *arg10 = nullptr;       /** action1_$9 */
    cocos2d::FiniteTimeAction *arg11 = nullptr;       /** action1_$10 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");
    olua_check_object(L, 4, &arg4, "cc.FiniteTimeAction");
    olua_check_object(L, 5, &arg5, "cc.FiniteTimeAction");
    olua_check_object(L, 6, &arg6, "cc.FiniteTimeAction");
    olua_check_object(L, 7, &arg7, "cc.FiniteTimeAction");
    olua_check_object(L, 8, &arg8, "cc.FiniteTimeAction");
    olua_check_object(L, 9, &arg9, "cc.FiniteTimeAction");
    olua_check_object(L, 10, &arg10, "cc.FiniteTimeAction");
    olua_check_object(L, 11, &arg11, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Spawn *ret = cocos2d::Spawn::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Spawn");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 4, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 5, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 6, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 7, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 8, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 9, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 10, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 11, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Spawn_create$14(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */
    cocos2d::FiniteTimeAction *arg4 = nullptr;       /** action1_$3 */
    cocos2d::FiniteTimeAction *arg5 = nullptr;       /** action1_$4 */
    cocos2d::FiniteTimeAction *arg6 = nullptr;       /** action1_$5 */
    cocos2d::FiniteTimeAction *arg7 = nullptr;       /** action1_$6 */
    cocos2d::FiniteTimeAction *arg8 = nullptr;       /** action1_$7 */
    cocos2d::FiniteTimeAction *arg9 = nullptr;       /** action1_$8 */
    cocos2d::FiniteTimeAction *arg10 = nullptr;       /** action1_$9 */
    cocos2d::FiniteTimeAction *arg11 = nullptr;       /** action1_$10 */
    cocos2d::FiniteTimeAction *arg12 = nullptr;       /** action1_$11 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");
    olua_check_object(L, 4, &arg4, "cc.FiniteTimeAction");
    olua_check_object(L, 5, &arg5, "cc.FiniteTimeAction");
    olua_check_object(L, 6, &arg6, "cc.FiniteTimeAction");
    olua_check_object(L, 7, &arg7, "cc.FiniteTimeAction");
    olua_check_object(L, 8, &arg8, "cc.FiniteTimeAction");
    olua_check_object(L, 9, &arg9, "cc.FiniteTimeAction");
    olua_check_object(L, 10, &arg10, "cc.FiniteTimeAction");
    olua_check_object(L, 11, &arg11, "cc.FiniteTimeAction");
    olua_check_object(L, 12, &arg12, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Spawn *ret = cocos2d::Spawn::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Spawn");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 4, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 5, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 6, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 7, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 8, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 9, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 10, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 11, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 12, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Spawn_create$15(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */
    cocos2d::FiniteTimeAction *arg4 = nullptr;       /** action1_$3 */
    cocos2d::FiniteTimeAction *arg5 = nullptr;       /** action1_$4 */
    cocos2d::FiniteTimeAction *arg6 = nullptr;       /** action1_$5 */
    cocos2d::FiniteTimeAction *arg7 = nullptr;       /** action1_$6 */
    cocos2d::FiniteTimeAction *arg8 = nullptr;       /** action1_$7 */
    cocos2d::FiniteTimeAction *arg9 = nullptr;       /** action1_$8 */
    cocos2d::FiniteTimeAction *arg10 = nullptr;       /** action1_$9 */
    cocos2d::FiniteTimeAction *arg11 = nullptr;       /** action1_$10 */
    cocos2d::FiniteTimeAction *arg12 = nullptr;       /** action1_$11 */
    cocos2d::FiniteTimeAction *arg13 = nullptr;       /** action1_$12 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");
    olua_check_object(L, 4, &arg4, "cc.FiniteTimeAction");
    olua_check_object(L, 5, &arg5, "cc.FiniteTimeAction");
    olua_check_object(L, 6, &arg6, "cc.FiniteTimeAction");
    olua_check_object(L, 7, &arg7, "cc.FiniteTimeAction");
    olua_check_object(L, 8, &arg8, "cc.FiniteTimeAction");
    olua_check_object(L, 9, &arg9, "cc.FiniteTimeAction");
    olua_check_object(L, 10, &arg10, "cc.FiniteTimeAction");
    olua_check_object(L, 11, &arg11, "cc.FiniteTimeAction");
    olua_check_object(L, 12, &arg12, "cc.FiniteTimeAction");
    olua_check_object(L, 13, &arg13, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Spawn *ret = cocos2d::Spawn::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Spawn");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 4, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 5, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 6, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 7, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 8, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 9, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 10, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 11, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 12, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 13, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Spawn_create$16(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */
    cocos2d::FiniteTimeAction *arg4 = nullptr;       /** action1_$3 */
    cocos2d::FiniteTimeAction *arg5 = nullptr;       /** action1_$4 */
    cocos2d::FiniteTimeAction *arg6 = nullptr;       /** action1_$5 */
    cocos2d::FiniteTimeAction *arg7 = nullptr;       /** action1_$6 */
    cocos2d::FiniteTimeAction *arg8 = nullptr;       /** action1_$7 */
    cocos2d::FiniteTimeAction *arg9 = nullptr;       /** action1_$8 */
    cocos2d::FiniteTimeAction *arg10 = nullptr;       /** action1_$9 */
    cocos2d::FiniteTimeAction *arg11 = nullptr;       /** action1_$10 */
    cocos2d::FiniteTimeAction *arg12 = nullptr;       /** action1_$11 */
    cocos2d::FiniteTimeAction *arg13 = nullptr;       /** action1_$12 */
    cocos2d::FiniteTimeAction *arg14 = nullptr;       /** action1_$13 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");
    olua_check_object(L, 4, &arg4, "cc.FiniteTimeAction");
    olua_check_object(L, 5, &arg5, "cc.FiniteTimeAction");
    olua_check_object(L, 6, &arg6, "cc.FiniteTimeAction");
    olua_check_object(L, 7, &arg7, "cc.FiniteTimeAction");
    olua_check_object(L, 8, &arg8, "cc.FiniteTimeAction");
    olua_check_object(L, 9, &arg9, "cc.FiniteTimeAction");
    olua_check_object(L, 10, &arg10, "cc.FiniteTimeAction");
    olua_check_object(L, 11, &arg11, "cc.FiniteTimeAction");
    olua_check_object(L, 12, &arg12, "cc.FiniteTimeAction");
    olua_check_object(L, 13, &arg13, "cc.FiniteTimeAction");
    olua_check_object(L, 14, &arg14, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Spawn *ret = cocos2d::Spawn::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Spawn");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 4, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 5, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 6, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 7, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 8, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 9, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 10, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 11, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 12, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 13, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 14, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Spawn_create$17(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */
    cocos2d::FiniteTimeAction *arg4 = nullptr;       /** action1_$3 */
    cocos2d::FiniteTimeAction *arg5 = nullptr;       /** action1_$4 */
    cocos2d::FiniteTimeAction *arg6 = nullptr;       /** action1_$5 */
    cocos2d::FiniteTimeAction *arg7 = nullptr;       /** action1_$6 */
    cocos2d::FiniteTimeAction *arg8 = nullptr;       /** action1_$7 */
    cocos2d::FiniteTimeAction *arg9 = nullptr;       /** action1_$8 */
    cocos2d::FiniteTimeAction *arg10 = nullptr;       /** action1_$9 */
    cocos2d::FiniteTimeAction *arg11 = nullptr;       /** action1_$10 */
    cocos2d::FiniteTimeAction *arg12 = nullptr;       /** action1_$11 */
    cocos2d::FiniteTimeAction *arg13 = nullptr;       /** action1_$12 */
    cocos2d::FiniteTimeAction *arg14 = nullptr;       /** action1_$13 */
    cocos2d::FiniteTimeAction *arg15 = nullptr;       /** action1_$14 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");
    olua_check_object(L, 4, &arg4, "cc.FiniteTimeAction");
    olua_check_object(L, 5, &arg5, "cc.FiniteTimeAction");
    olua_check_object(L, 6, &arg6, "cc.FiniteTimeAction");
    olua_check_object(L, 7, &arg7, "cc.FiniteTimeAction");
    olua_check_object(L, 8, &arg8, "cc.FiniteTimeAction");
    olua_check_object(L, 9, &arg9, "cc.FiniteTimeAction");
    olua_check_object(L, 10, &arg10, "cc.FiniteTimeAction");
    olua_check_object(L, 11, &arg11, "cc.FiniteTimeAction");
    olua_check_object(L, 12, &arg12, "cc.FiniteTimeAction");
    olua_check_object(L, 13, &arg13, "cc.FiniteTimeAction");
    olua_check_object(L, 14, &arg14, "cc.FiniteTimeAction");
    olua_check_object(L, 15, &arg15, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Spawn *ret = cocos2d::Spawn::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Spawn");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 4, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 5, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 6, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 7, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 8, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 9, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 10, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 11, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 12, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 13, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 14, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 15, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Spawn_create$18(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action1_$1 */
    cocos2d::FiniteTimeAction *arg3 = nullptr;       /** action1_$2 */
    cocos2d::FiniteTimeAction *arg4 = nullptr;       /** action1_$3 */
    cocos2d::FiniteTimeAction *arg5 = nullptr;       /** action1_$4 */
    cocos2d::FiniteTimeAction *arg6 = nullptr;       /** action1_$5 */
    cocos2d::FiniteTimeAction *arg7 = nullptr;       /** action1_$6 */
    cocos2d::FiniteTimeAction *arg8 = nullptr;       /** action1_$7 */
    cocos2d::FiniteTimeAction *arg9 = nullptr;       /** action1_$8 */
    cocos2d::FiniteTimeAction *arg10 = nullptr;       /** action1_$9 */
    cocos2d::FiniteTimeAction *arg11 = nullptr;       /** action1_$10 */
    cocos2d::FiniteTimeAction *arg12 = nullptr;       /** action1_$11 */
    cocos2d::FiniteTimeAction *arg13 = nullptr;       /** action1_$12 */
    cocos2d::FiniteTimeAction *arg14 = nullptr;       /** action1_$13 */
    cocos2d::FiniteTimeAction *arg15 = nullptr;       /** action1_$14 */
    cocos2d::FiniteTimeAction *arg16 = nullptr;       /** action1_$15 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");
    olua_check_object(L, 3, &arg3, "cc.FiniteTimeAction");
    olua_check_object(L, 4, &arg4, "cc.FiniteTimeAction");
    olua_check_object(L, 5, &arg5, "cc.FiniteTimeAction");
    olua_check_object(L, 6, &arg6, "cc.FiniteTimeAction");
    olua_check_object(L, 7, &arg7, "cc.FiniteTimeAction");
    olua_check_object(L, 8, &arg8, "cc.FiniteTimeAction");
    olua_check_object(L, 9, &arg9, "cc.FiniteTimeAction");
    olua_check_object(L, 10, &arg10, "cc.FiniteTimeAction");
    olua_check_object(L, 11, &arg11, "cc.FiniteTimeAction");
    olua_check_object(L, 12, &arg12, "cc.FiniteTimeAction");
    olua_check_object(L, 13, &arg13, "cc.FiniteTimeAction");
    olua_check_object(L, 14, &arg14, "cc.FiniteTimeAction");
    olua_check_object(L, 15, &arg15, "cc.FiniteTimeAction");
    olua_check_object(L, 16, &arg16, "cc.FiniteTimeAction");

    // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
    cocos2d::Spawn *ret = cocos2d::Spawn::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, nullptr);
    int num_ret = olua_push_object(L, ret, "cc.Spawn");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 3, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 4, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 5, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 6, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 7, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 8, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 9, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 10, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 11, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 12, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 13, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 14, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 15, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 16, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Spawn_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        if ((olua_is_array(L, 1))) {
            // static cocos2d::Spawn *create(@addref(actions |) const cocos2d::Vector<cocos2d::FiniteTimeAction *> &arrayOfActions)
            return _cocos2d_Spawn_create$2(L);
        }

        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Spawn_create$3(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Spawn_create$4(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Spawn_create$5(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction")) && (olua_is_object(L, 4, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Spawn_create$6(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction")) && (olua_is_object(L, 4, "cc.FiniteTimeAction")) && (olua_is_object(L, 5, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Spawn_create$7(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction")) && (olua_is_object(L, 4, "cc.FiniteTimeAction")) && (olua_is_object(L, 5, "cc.FiniteTimeAction")) && (olua_is_object(L, 6, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Spawn_create$8(L);
        // }
    }

    if (num_args == 7) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction")) && (olua_is_object(L, 4, "cc.FiniteTimeAction")) && (olua_is_object(L, 5, "cc.FiniteTimeAction")) && (olua_is_object(L, 6, "cc.FiniteTimeAction")) && (olua_is_object(L, 7, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Spawn_create$9(L);
        // }
    }

    if (num_args == 8) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction")) && (olua_is_object(L, 4, "cc.FiniteTimeAction")) && (olua_is_object(L, 5, "cc.FiniteTimeAction")) && (olua_is_object(L, 6, "cc.FiniteTimeAction")) && (olua_is_object(L, 7, "cc.FiniteTimeAction")) && (olua_is_object(L, 8, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Spawn_create$10(L);
        // }
    }

    if (num_args == 9) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction")) && (olua_is_object(L, 4, "cc.FiniteTimeAction")) && (olua_is_object(L, 5, "cc.FiniteTimeAction")) && (olua_is_object(L, 6, "cc.FiniteTimeAction")) && (olua_is_object(L, 7, "cc.FiniteTimeAction")) && (olua_is_object(L, 8, "cc.FiniteTimeAction")) && (olua_is_object(L, 9, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Spawn_create$11(L);
        // }
    }

    if (num_args == 10) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction")) && (olua_is_object(L, 4, "cc.FiniteTimeAction")) && (olua_is_object(L, 5, "cc.FiniteTimeAction")) && (olua_is_object(L, 6, "cc.FiniteTimeAction")) && (olua_is_object(L, 7, "cc.FiniteTimeAction")) && (olua_is_object(L, 8, "cc.FiniteTimeAction")) && (olua_is_object(L, 9, "cc.FiniteTimeAction")) && (olua_is_object(L, 10, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Spawn_create$12(L);
        // }
    }

    if (num_args == 11) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction")) && (olua_is_object(L, 4, "cc.FiniteTimeAction")) && (olua_is_object(L, 5, "cc.FiniteTimeAction")) && (olua_is_object(L, 6, "cc.FiniteTimeAction")) && (olua_is_object(L, 7, "cc.FiniteTimeAction")) && (olua_is_object(L, 8, "cc.FiniteTimeAction")) && (olua_is_object(L, 9, "cc.FiniteTimeAction")) && (olua_is_object(L, 10, "cc.FiniteTimeAction")) && (olua_is_object(L, 11, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Spawn_create$13(L);
        // }
    }

    if (num_args == 12) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction")) && (olua_is_object(L, 4, "cc.FiniteTimeAction")) && (olua_is_object(L, 5, "cc.FiniteTimeAction")) && (olua_is_object(L, 6, "cc.FiniteTimeAction")) && (olua_is_object(L, 7, "cc.FiniteTimeAction")) && (olua_is_object(L, 8, "cc.FiniteTimeAction")) && (olua_is_object(L, 9, "cc.FiniteTimeAction")) && (olua_is_object(L, 10, "cc.FiniteTimeAction")) && (olua_is_object(L, 11, "cc.FiniteTimeAction")) && (olua_is_object(L, 12, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Spawn_create$14(L);
        // }
    }

    if (num_args == 13) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction")) && (olua_is_object(L, 4, "cc.FiniteTimeAction")) && (olua_is_object(L, 5, "cc.FiniteTimeAction")) && (olua_is_object(L, 6, "cc.FiniteTimeAction")) && (olua_is_object(L, 7, "cc.FiniteTimeAction")) && (olua_is_object(L, 8, "cc.FiniteTimeAction")) && (olua_is_object(L, 9, "cc.FiniteTimeAction")) && (olua_is_object(L, 10, "cc.FiniteTimeAction")) && (olua_is_object(L, 11, "cc.FiniteTimeAction")) && (olua_is_object(L, 12, "cc.FiniteTimeAction")) && (olua_is_object(L, 13, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Spawn_create$15(L);
        // }
    }

    if (num_args == 14) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction")) && (olua_is_object(L, 4, "cc.FiniteTimeAction")) && (olua_is_object(L, 5, "cc.FiniteTimeAction")) && (olua_is_object(L, 6, "cc.FiniteTimeAction")) && (olua_is_object(L, 7, "cc.FiniteTimeAction")) && (olua_is_object(L, 8, "cc.FiniteTimeAction")) && (olua_is_object(L, 9, "cc.FiniteTimeAction")) && (olua_is_object(L, 10, "cc.FiniteTimeAction")) && (olua_is_object(L, 11, "cc.FiniteTimeAction")) && (olua_is_object(L, 12, "cc.FiniteTimeAction")) && (olua_is_object(L, 13, "cc.FiniteTimeAction")) && (olua_is_object(L, 14, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Spawn_create$16(L);
        // }
    }

    if (num_args == 15) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction")) && (olua_is_object(L, 4, "cc.FiniteTimeAction")) && (olua_is_object(L, 5, "cc.FiniteTimeAction")) && (olua_is_object(L, 6, "cc.FiniteTimeAction")) && (olua_is_object(L, 7, "cc.FiniteTimeAction")) && (olua_is_object(L, 8, "cc.FiniteTimeAction")) && (olua_is_object(L, 9, "cc.FiniteTimeAction")) && (olua_is_object(L, 10, "cc.FiniteTimeAction")) && (olua_is_object(L, 11, "cc.FiniteTimeAction")) && (olua_is_object(L, 12, "cc.FiniteTimeAction")) && (olua_is_object(L, 13, "cc.FiniteTimeAction")) && (olua_is_object(L, 14, "cc.FiniteTimeAction")) && (olua_is_object(L, 15, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Spawn_create$17(L);
        // }
    }

    if (num_args == 16) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction")) && (olua_is_object(L, 4, "cc.FiniteTimeAction")) && (olua_is_object(L, 5, "cc.FiniteTimeAction")) && (olua_is_object(L, 6, "cc.FiniteTimeAction")) && (olua_is_object(L, 7, "cc.FiniteTimeAction")) && (olua_is_object(L, 8, "cc.FiniteTimeAction")) && (olua_is_object(L, 9, "cc.FiniteTimeAction")) && (olua_is_object(L, 10, "cc.FiniteTimeAction")) && (olua_is_object(L, 11, "cc.FiniteTimeAction")) && (olua_is_object(L, 12, "cc.FiniteTimeAction")) && (olua_is_object(L, 13, "cc.FiniteTimeAction")) && (olua_is_object(L, 14, "cc.FiniteTimeAction")) && (olua_is_object(L, 15, "cc.FiniteTimeAction")) && (olua_is_object(L, 16, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Spawn_create$18(L);
        // }
    }

    if (num_args == 17) {
        // if ((olua_is_object(L, 1, "cc.FiniteTimeAction")) && (olua_is_object(L, 2, "cc.FiniteTimeAction")) && (olua_is_object(L, 3, "cc.FiniteTimeAction")) && (olua_is_object(L, 4, "cc.FiniteTimeAction")) && (olua_is_object(L, 5, "cc.FiniteTimeAction")) && (olua_is_object(L, 6, "cc.FiniteTimeAction")) && (olua_is_object(L, 7, "cc.FiniteTimeAction")) && (olua_is_object(L, 8, "cc.FiniteTimeAction")) && (olua_is_object(L, 9, "cc.FiniteTimeAction")) && (olua_is_object(L, 10, "cc.FiniteTimeAction")) && (olua_is_object(L, 11, "cc.FiniteTimeAction")) && (olua_is_object(L, 12, "cc.FiniteTimeAction")) && (olua_is_object(L, 13, "cc.FiniteTimeAction")) && (olua_is_object(L, 14, "cc.FiniteTimeAction")) && (olua_is_object(L, 15, "cc.FiniteTimeAction")) && (olua_is_object(L, 16, "cc.FiniteTimeAction")) && (olua_is_object(L, 17, "cc.FiniteTimeAction"))) {
            // @variadic static cocos2d::Spawn *create(@addref(actions |) cocos2d::FiniteTimeAction *action1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$1, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$2, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$3, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$4, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$5, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$6, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$7, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$8, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$9, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$10, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$11, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$12, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$13, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$14, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$15, @optional @addref(actions |) cocos2d::FiniteTimeAction *action1_$16)
            return _cocos2d_Spawn_create$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Spawn::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_Spawn_createWithTwoActions(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action2 */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");

    // static cocos2d::Spawn *createWithTwoActions(@addref(actions |) cocos2d::FiniteTimeAction *action1, @addref(actions |) cocos2d::FiniteTimeAction *action2)
    cocos2d::Spawn *ret = cocos2d::Spawn::createWithTwoActions(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.Spawn");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Spawn_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Spawn *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Spawn");

    // cocos2d::Spawn *reverse()
    cocos2d::Spawn *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.Spawn");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_Spawn(lua_State *L)
{
    oluacls_class<cocos2d::Spawn, cocos2d::ActionInterval>(L, "cc.Spawn");
    oluacls_func(L, "clone", _cocos2d_Spawn_clone);
    oluacls_func(L, "create", _cocos2d_Spawn_create);
    oluacls_func(L, "createWithTwoActions", _cocos2d_Spawn_createWithTwoActions);
    oluacls_func(L, "reverse", _cocos2d_Spawn_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_RotateTo_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::RotateTo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.RotateTo");

    // cocos2d::RotateTo *clone()
    cocos2d::RotateTo *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.RotateTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_RotateTo_create$1(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    float arg2 = 0;       /** dstAngleX */
    float arg3 = 0;       /** dstAngleY */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static cocos2d::RotateTo *create(float duration, float dstAngleX, float dstAngleY)
    cocos2d::RotateTo *ret = cocos2d::RotateTo::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.RotateTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_RotateTo_create$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    float arg2 = 0;       /** dstAngle */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static cocos2d::RotateTo *create(float duration, float dstAngle)
    cocos2d::RotateTo *ret = cocos2d::RotateTo::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.RotateTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_RotateTo_create$3(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Vec3 arg2;       /** dstAngle3D */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Vec3");

    // static cocos2d::RotateTo *create(float duration, const cocos2d::Vec3 &dstAngle3D)
    cocos2d::RotateTo *ret = cocos2d::RotateTo::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.RotateTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_RotateTo_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_number(L, 1)) && (olua_is_object(L, 2, "cc.Vec3"))) {
            // static cocos2d::RotateTo *create(float duration, const cocos2d::Vec3 &dstAngle3D)
            return _cocos2d_RotateTo_create$3(L);
        }

        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2))) {
            // static cocos2d::RotateTo *create(float duration, float dstAngle)
            return _cocos2d_RotateTo_create$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // static cocos2d::RotateTo *create(float duration, float dstAngleX, float dstAngleY)
            return _cocos2d_RotateTo_create$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::RotateTo::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_RotateTo_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::RotateTo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.RotateTo");

    // cocos2d::RotateTo *reverse()
    cocos2d::RotateTo *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.RotateTo");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_RotateTo(lua_State *L)
{
    oluacls_class<cocos2d::RotateTo, cocos2d::ActionInterval>(L, "cc.RotateTo");
    oluacls_func(L, "clone", _cocos2d_RotateTo_clone);
    oluacls_func(L, "create", _cocos2d_RotateTo_create);
    oluacls_func(L, "reverse", _cocos2d_RotateTo_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_RotateFrom_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::RotateFrom *self = nullptr;

    olua_to_object(L, 1, &self, "cc.RotateFrom");

    // cocos2d::RotateFrom *clone()
    cocos2d::RotateFrom *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.RotateFrom");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_RotateFrom_create$1(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    float arg2 = 0;       /** fromAngleX */
    float arg3 = 0;       /** fromAngleY */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static cocos2d::RotateFrom *create(float duration, float fromAngleX, float fromAngleY)
    cocos2d::RotateFrom *ret = cocos2d::RotateFrom::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.RotateFrom");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_RotateFrom_create$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    float arg2 = 0;       /** fromAngle */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static cocos2d::RotateFrom *create(float duration, float fromAngle)
    cocos2d::RotateFrom *ret = cocos2d::RotateFrom::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.RotateFrom");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_RotateFrom_create$3(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Vec3 arg2;       /** fromAngle3D */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Vec3");

    // static cocos2d::RotateFrom *create(float duration, const cocos2d::Vec3 &fromAngle3D)
    cocos2d::RotateFrom *ret = cocos2d::RotateFrom::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.RotateFrom");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_RotateFrom_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_number(L, 1)) && (olua_is_object(L, 2, "cc.Vec3"))) {
            // static cocos2d::RotateFrom *create(float duration, const cocos2d::Vec3 &fromAngle3D)
            return _cocos2d_RotateFrom_create$3(L);
        }

        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2))) {
            // static cocos2d::RotateFrom *create(float duration, float fromAngle)
            return _cocos2d_RotateFrom_create$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // static cocos2d::RotateFrom *create(float duration, float fromAngleX, float fromAngleY)
            return _cocos2d_RotateFrom_create$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::RotateFrom::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_RotateFrom_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::RotateFrom *self = nullptr;

    olua_to_object(L, 1, &self, "cc.RotateFrom");

    // cocos2d::RotateFrom *reverse()
    cocos2d::RotateFrom *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.RotateFrom");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_RotateFrom(lua_State *L)
{
    oluacls_class<cocos2d::RotateFrom, cocos2d::RotateTo>(L, "cc.RotateFrom");
    oluacls_func(L, "clone", _cocos2d_RotateFrom_clone);
    oluacls_func(L, "create", _cocos2d_RotateFrom_create);
    oluacls_func(L, "reverse", _cocos2d_RotateFrom_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_RotateBy_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::RotateBy *self = nullptr;

    olua_to_object(L, 1, &self, "cc.RotateBy");

    // cocos2d::RotateBy *clone()
    cocos2d::RotateBy *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.RotateBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_RotateBy_create$1(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    float arg2 = 0;       /** deltaAngle */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static cocos2d::RotateBy *create(float duration, float deltaAngle)
    cocos2d::RotateBy *ret = cocos2d::RotateBy::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.RotateBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_RotateBy_create$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    float arg2 = 0;       /** deltaAngleZ_X */
    float arg3 = 0;       /** deltaAngleZ_Y */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static cocos2d::RotateBy *create(float duration, float deltaAngleZ_X, float deltaAngleZ_Y)
    cocos2d::RotateBy *ret = cocos2d::RotateBy::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.RotateBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_RotateBy_create$3(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Vec3 arg2;       /** deltaAngle3D */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Vec3");

    // static cocos2d::RotateBy *create(float duration, const cocos2d::Vec3 &deltaAngle3D)
    cocos2d::RotateBy *ret = cocos2d::RotateBy::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.RotateBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_RotateBy_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_number(L, 1)) && (olua_is_object(L, 2, "cc.Vec3"))) {
            // static cocos2d::RotateBy *create(float duration, const cocos2d::Vec3 &deltaAngle3D)
            return _cocos2d_RotateBy_create$3(L);
        }

        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2))) {
            // static cocos2d::RotateBy *create(float duration, float deltaAngle)
            return _cocos2d_RotateBy_create$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // static cocos2d::RotateBy *create(float duration, float deltaAngleZ_X, float deltaAngleZ_Y)
            return _cocos2d_RotateBy_create$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::RotateBy::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_RotateBy_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::RotateBy *self = nullptr;

    olua_to_object(L, 1, &self, "cc.RotateBy");

    // cocos2d::RotateBy *reverse()
    cocos2d::RotateBy *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.RotateBy");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_RotateBy(lua_State *L)
{
    oluacls_class<cocos2d::RotateBy, cocos2d::ActionInterval>(L, "cc.RotateBy");
    oluacls_func(L, "clone", _cocos2d_RotateBy_clone);
    oluacls_func(L, "create", _cocos2d_RotateBy_create);
    oluacls_func(L, "reverse", _cocos2d_RotateBy_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_MoveBy_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::MoveBy *self = nullptr;

    olua_to_object(L, 1, &self, "cc.MoveBy");

    // cocos2d::MoveBy *clone()
    cocos2d::MoveBy *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.MoveBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_MoveBy_create$1(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Vec2 arg2;       /** deltaPosition */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Vec2");

    // static cocos2d::MoveBy *create(float duration, const cocos2d::Vec2 &deltaPosition)
    cocos2d::MoveBy *ret = cocos2d::MoveBy::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.MoveBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_MoveBy_create$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Vec2 arg2;       /** deltaPosition */

    olua_check_number(L, 1, &arg1);
    olua_pack_object(L, 2, &arg2);

    // static cocos2d::MoveBy *create(float duration, @pack const cocos2d::Vec2 &deltaPosition)
    cocos2d::MoveBy *ret = cocos2d::MoveBy::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.MoveBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_MoveBy_create$3(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Vec3 arg2;       /** deltaPosition */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Vec3");

    // static cocos2d::MoveBy *create(float duration, const cocos2d::Vec3 &deltaPosition)
    cocos2d::MoveBy *ret = cocos2d::MoveBy::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.MoveBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_MoveBy_create$4(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Vec3 arg2;       /** deltaPosition */

    olua_check_number(L, 1, &arg1);
    olua_pack_object(L, 2, &arg2);

    // static cocos2d::MoveBy *create(float duration, @pack const cocos2d::Vec3 &deltaPosition)
    cocos2d::MoveBy *ret = cocos2d::MoveBy::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.MoveBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_MoveBy_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_number(L, 1)) && (olua_is_object(L, 2, "cc.Vec3"))) {
            // static cocos2d::MoveBy *create(float duration, const cocos2d::Vec3 &deltaPosition)
            return _cocos2d_MoveBy_create$3(L);
        }

        // if ((olua_is_number(L, 1)) && (olua_is_object(L, 2, "cc.Vec2"))) {
            // static cocos2d::MoveBy *create(float duration, const cocos2d::Vec2 &deltaPosition)
            return _cocos2d_MoveBy_create$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (olua_canpack_object(L, 2, (cocos2d::Vec2 *)nullptr))) {
            // static cocos2d::MoveBy *create(float duration, @pack const cocos2d::Vec2 &deltaPosition)
            return _cocos2d_MoveBy_create$2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_number(L, 1)) && (olua_canpack_object(L, 2, (cocos2d::Vec3 *)nullptr))) {
            // static cocos2d::MoveBy *create(float duration, @pack const cocos2d::Vec3 &deltaPosition)
            return _cocos2d_MoveBy_create$4(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::MoveBy::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_MoveBy_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::MoveBy *self = nullptr;

    olua_to_object(L, 1, &self, "cc.MoveBy");

    // cocos2d::MoveBy *reverse()
    cocos2d::MoveBy *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.MoveBy");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_MoveBy(lua_State *L)
{
    oluacls_class<cocos2d::MoveBy, cocos2d::ActionInterval>(L, "cc.MoveBy");
    oluacls_func(L, "clone", _cocos2d_MoveBy_clone);
    oluacls_func(L, "create", _cocos2d_MoveBy_create);
    oluacls_func(L, "reverse", _cocos2d_MoveBy_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_MoveTo_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::MoveTo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.MoveTo");

    // cocos2d::MoveTo *clone()
    cocos2d::MoveTo *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.MoveTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_MoveTo_create$1(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Vec2 arg2;       /** position */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Vec2");

    // static cocos2d::MoveTo *create(float duration, const cocos2d::Vec2 &position)
    cocos2d::MoveTo *ret = cocos2d::MoveTo::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.MoveTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_MoveTo_create$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Vec2 arg2;       /** position */

    olua_check_number(L, 1, &arg1);
    olua_pack_object(L, 2, &arg2);

    // static cocos2d::MoveTo *create(float duration, @pack const cocos2d::Vec2 &position)
    cocos2d::MoveTo *ret = cocos2d::MoveTo::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.MoveTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_MoveTo_create$3(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Vec3 arg2;       /** position */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Vec3");

    // static cocos2d::MoveTo *create(float duration, const cocos2d::Vec3 &position)
    cocos2d::MoveTo *ret = cocos2d::MoveTo::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.MoveTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_MoveTo_create$4(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Vec3 arg2;       /** position */

    olua_check_number(L, 1, &arg1);
    olua_pack_object(L, 2, &arg2);

    // static cocos2d::MoveTo *create(float duration, @pack const cocos2d::Vec3 &position)
    cocos2d::MoveTo *ret = cocos2d::MoveTo::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.MoveTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_MoveTo_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_number(L, 1)) && (olua_is_object(L, 2, "cc.Vec3"))) {
            // static cocos2d::MoveTo *create(float duration, const cocos2d::Vec3 &position)
            return _cocos2d_MoveTo_create$3(L);
        }

        // if ((olua_is_number(L, 1)) && (olua_is_object(L, 2, "cc.Vec2"))) {
            // static cocos2d::MoveTo *create(float duration, const cocos2d::Vec2 &position)
            return _cocos2d_MoveTo_create$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (olua_canpack_object(L, 2, (cocos2d::Vec2 *)nullptr))) {
            // static cocos2d::MoveTo *create(float duration, @pack const cocos2d::Vec2 &position)
            return _cocos2d_MoveTo_create$2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_number(L, 1)) && (olua_canpack_object(L, 2, (cocos2d::Vec3 *)nullptr))) {
            // static cocos2d::MoveTo *create(float duration, @pack const cocos2d::Vec3 &position)
            return _cocos2d_MoveTo_create$4(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::MoveTo::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_MoveTo_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::MoveTo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.MoveTo");

    // cocos2d::MoveTo *reverse()
    cocos2d::MoveTo *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.MoveTo");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_MoveTo(lua_State *L)
{
    oluacls_class<cocos2d::MoveTo, cocos2d::MoveBy>(L, "cc.MoveTo");
    oluacls_func(L, "clone", _cocos2d_MoveTo_clone);
    oluacls_func(L, "create", _cocos2d_MoveTo_create);
    oluacls_func(L, "reverse", _cocos2d_MoveTo_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_MoveFrom_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::MoveFrom *self = nullptr;

    olua_to_object(L, 1, &self, "cc.MoveFrom");

    // cocos2d::MoveFrom *clone()
    cocos2d::MoveFrom *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.MoveFrom");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_MoveFrom_create$1(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Vec2 arg2;       /** position */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Vec2");

    // static cocos2d::MoveFrom *create(float duration, const cocos2d::Vec2 &position)
    cocos2d::MoveFrom *ret = cocos2d::MoveFrom::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.MoveFrom");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_MoveFrom_create$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Vec2 arg2;       /** position */

    olua_check_number(L, 1, &arg1);
    olua_pack_object(L, 2, &arg2);

    // static cocos2d::MoveFrom *create(float duration, @pack const cocos2d::Vec2 &position)
    cocos2d::MoveFrom *ret = cocos2d::MoveFrom::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.MoveFrom");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_MoveFrom_create$3(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Vec3 arg2;       /** position */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Vec3");

    // static cocos2d::MoveFrom *create(float duration, const cocos2d::Vec3 &position)
    cocos2d::MoveFrom *ret = cocos2d::MoveFrom::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.MoveFrom");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_MoveFrom_create$4(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Vec3 arg2;       /** position */

    olua_check_number(L, 1, &arg1);
    olua_pack_object(L, 2, &arg2);

    // static cocos2d::MoveFrom *create(float duration, @pack const cocos2d::Vec3 &position)
    cocos2d::MoveFrom *ret = cocos2d::MoveFrom::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.MoveFrom");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_MoveFrom_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_number(L, 1)) && (olua_is_object(L, 2, "cc.Vec3"))) {
            // static cocos2d::MoveFrom *create(float duration, const cocos2d::Vec3 &position)
            return _cocos2d_MoveFrom_create$3(L);
        }

        // if ((olua_is_number(L, 1)) && (olua_is_object(L, 2, "cc.Vec2"))) {
            // static cocos2d::MoveFrom *create(float duration, const cocos2d::Vec2 &position)
            return _cocos2d_MoveFrom_create$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (olua_canpack_object(L, 2, (cocos2d::Vec2 *)nullptr))) {
            // static cocos2d::MoveFrom *create(float duration, @pack const cocos2d::Vec2 &position)
            return _cocos2d_MoveFrom_create$2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_number(L, 1)) && (olua_canpack_object(L, 2, (cocos2d::Vec3 *)nullptr))) {
            // static cocos2d::MoveFrom *create(float duration, @pack const cocos2d::Vec3 &position)
            return _cocos2d_MoveFrom_create$4(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::MoveFrom::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_MoveFrom_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::MoveFrom *self = nullptr;

    olua_to_object(L, 1, &self, "cc.MoveFrom");

    // cocos2d::MoveFrom *reverse()
    cocos2d::MoveFrom *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.MoveFrom");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_MoveFrom(lua_State *L)
{
    oluacls_class<cocos2d::MoveFrom, cocos2d::MoveBy>(L, "cc.MoveFrom");
    oluacls_func(L, "clone", _cocos2d_MoveFrom_clone);
    oluacls_func(L, "create", _cocos2d_MoveFrom_create);
    oluacls_func(L, "reverse", _cocos2d_MoveFrom_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_SkewTo_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::SkewTo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.SkewTo");

    // cocos2d::SkewTo *clone()
    cocos2d::SkewTo *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.SkewTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_SkewTo_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** t */
    float arg2 = 0;       /** sx */
    float arg3 = 0;       /** sy */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static cocos2d::SkewTo *create(float t, float sx, float sy)
    cocos2d::SkewTo *ret = cocos2d::SkewTo::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.SkewTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_SkewTo_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::SkewTo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.SkewTo");

    // cocos2d::SkewTo *reverse()
    cocos2d::SkewTo *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.SkewTo");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_SkewTo(lua_State *L)
{
    oluacls_class<cocos2d::SkewTo, cocos2d::ActionInterval>(L, "cc.SkewTo");
    oluacls_func(L, "clone", _cocos2d_SkewTo_clone);
    oluacls_func(L, "create", _cocos2d_SkewTo_create);
    oluacls_func(L, "reverse", _cocos2d_SkewTo_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_SkewBy_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::SkewBy *self = nullptr;

    olua_to_object(L, 1, &self, "cc.SkewBy");

    // cocos2d::SkewBy *clone()
    cocos2d::SkewBy *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.SkewBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_SkewBy_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** t */
    float arg2 = 0;       /** deltaSkewX */
    float arg3 = 0;       /** deltaSkewY */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static cocos2d::SkewBy *create(float t, float deltaSkewX, float deltaSkewY)
    cocos2d::SkewBy *ret = cocos2d::SkewBy::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.SkewBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_SkewBy_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::SkewBy *self = nullptr;

    olua_to_object(L, 1, &self, "cc.SkewBy");

    // cocos2d::SkewBy *reverse()
    cocos2d::SkewBy *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.SkewBy");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_SkewBy(lua_State *L)
{
    oluacls_class<cocos2d::SkewBy, cocos2d::SkewTo>(L, "cc.SkewBy");
    oluacls_func(L, "clone", _cocos2d_SkewBy_clone);
    oluacls_func(L, "create", _cocos2d_SkewBy_create);
    oluacls_func(L, "reverse", _cocos2d_SkewBy_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_ResizeTo_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ResizeTo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ResizeTo");

    // cocos2d::ResizeTo *clone()
    cocos2d::ResizeTo *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.ResizeTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ResizeTo_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** final_size */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Size");

    // static cocos2d::ResizeTo *create(float duration, const cocos2d::Size &final_size)
    cocos2d::ResizeTo *ret = cocos2d::ResizeTo::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.ResizeTo");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_ResizeTo(lua_State *L)
{
    oluacls_class<cocos2d::ResizeTo, cocos2d::ActionInterval>(L, "cc.ResizeTo");
    oluacls_func(L, "clone", _cocos2d_ResizeTo_clone);
    oluacls_func(L, "create", _cocos2d_ResizeTo_create);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_ResizeBy_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ResizeBy *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ResizeBy");

    // cocos2d::ResizeBy *clone()
    cocos2d::ResizeBy *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.ResizeBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ResizeBy_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** deltaSize */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Size");

    // static cocos2d::ResizeBy *create(float duration, const cocos2d::Size &deltaSize)
    cocos2d::ResizeBy *ret = cocos2d::ResizeBy::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.ResizeBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ResizeBy_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ResizeBy *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ResizeBy");

    // cocos2d::ResizeBy *reverse()
    cocos2d::ResizeBy *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ResizeBy");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_ResizeBy(lua_State *L)
{
    oluacls_class<cocos2d::ResizeBy, cocos2d::ActionInterval>(L, "cc.ResizeBy");
    oluacls_func(L, "clone", _cocos2d_ResizeBy_clone);
    oluacls_func(L, "create", _cocos2d_ResizeBy_create);
    oluacls_func(L, "reverse", _cocos2d_ResizeBy_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_BezierBy_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::BezierBy *self = nullptr;

    olua_to_object(L, 1, &self, "cc.BezierBy");

    // cocos2d::BezierBy *clone()
    cocos2d::BezierBy *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.BezierBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_BezierBy_create$1(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** t */
    cocos2d::ccBezierConfig arg2;       /** c */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.ccBezierConfig");

    // static cocos2d::BezierBy *create(float t, const cocos2d::ccBezierConfig &c)
    cocos2d::BezierBy *ret = cocos2d::BezierBy::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.BezierBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_BezierBy_create$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** t */
    cocos2d::ccBezierConfig arg2;       /** c */

    olua_check_number(L, 1, &arg1);
    olua_pack_object(L, 2, &arg2);

    // static cocos2d::BezierBy *create(float t, @pack const cocos2d::ccBezierConfig &c)
    cocos2d::BezierBy *ret = cocos2d::BezierBy::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.BezierBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_BezierBy_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_number(L, 1)) && (olua_is_object(L, 2, "cc.ccBezierConfig"))) {
            // static cocos2d::BezierBy *create(float t, const cocos2d::ccBezierConfig &c)
            return _cocos2d_BezierBy_create$1(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_number(L, 1)) && (olua_canpack_object(L, 2, (cocos2d::ccBezierConfig *)nullptr))) {
            // static cocos2d::BezierBy *create(float t, @pack const cocos2d::ccBezierConfig &c)
            return _cocos2d_BezierBy_create$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::BezierBy::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_BezierBy_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::BezierBy *self = nullptr;

    olua_to_object(L, 1, &self, "cc.BezierBy");

    // cocos2d::BezierBy *reverse()
    cocos2d::BezierBy *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.BezierBy");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_BezierBy(lua_State *L)
{
    oluacls_class<cocos2d::BezierBy, cocos2d::ActionInterval>(L, "cc.BezierBy");
    oluacls_func(L, "clone", _cocos2d_BezierBy_clone);
    oluacls_func(L, "create", _cocos2d_BezierBy_create);
    oluacls_func(L, "reverse", _cocos2d_BezierBy_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_BezierTo_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::BezierTo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.BezierTo");

    // cocos2d::BezierTo *clone()
    cocos2d::BezierTo *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.BezierTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_BezierTo_create$1(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** t */
    cocos2d::ccBezierConfig arg2;       /** c */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.ccBezierConfig");

    // static cocos2d::BezierTo *create(float t, const cocos2d::ccBezierConfig &c)
    cocos2d::BezierTo *ret = cocos2d::BezierTo::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.BezierTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_BezierTo_create$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** t */
    cocos2d::ccBezierConfig arg2;       /** c */

    olua_check_number(L, 1, &arg1);
    olua_pack_object(L, 2, &arg2);

    // static cocos2d::BezierTo *create(float t, @pack const cocos2d::ccBezierConfig &c)
    cocos2d::BezierTo *ret = cocos2d::BezierTo::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.BezierTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_BezierTo_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_number(L, 1)) && (olua_is_object(L, 2, "cc.ccBezierConfig"))) {
            // static cocos2d::BezierTo *create(float t, const cocos2d::ccBezierConfig &c)
            return _cocos2d_BezierTo_create$1(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_number(L, 1)) && (olua_canpack_object(L, 2, (cocos2d::ccBezierConfig *)nullptr))) {
            // static cocos2d::BezierTo *create(float t, @pack const cocos2d::ccBezierConfig &c)
            return _cocos2d_BezierTo_create$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::BezierTo::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_BezierTo_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::BezierTo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.BezierTo");

    // cocos2d::BezierTo *reverse()
    cocos2d::BezierTo *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.BezierTo");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_BezierTo(lua_State *L)
{
    oluacls_class<cocos2d::BezierTo, cocos2d::BezierBy>(L, "cc.BezierTo");
    oluacls_func(L, "clone", _cocos2d_BezierTo_clone);
    oluacls_func(L, "create", _cocos2d_BezierTo_create);
    oluacls_func(L, "reverse", _cocos2d_BezierTo_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_JumpBy_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::JumpBy *self = nullptr;

    olua_to_object(L, 1, &self, "cc.JumpBy");

    // cocos2d::JumpBy *clone()
    cocos2d::JumpBy *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.JumpBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_JumpBy_create$1(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Vec2 arg2;       /** position */
    float arg3 = 0;       /** height */
    int arg4 = 0;       /** jumps */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Vec2");
    olua_check_number(L, 3, &arg3);
    olua_check_integer(L, 4, &arg4);

    // static cocos2d::JumpBy *create(float duration, const cocos2d::Vec2 &position, float height, int jumps)
    cocos2d::JumpBy *ret = cocos2d::JumpBy::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.JumpBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_JumpBy_create$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Vec2 arg2;       /** position */
    float arg3 = 0;       /** height */
    int arg4 = 0;       /** jumps */

    olua_check_number(L, 1, &arg1);
    olua_pack_object(L, 2, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_integer(L, 5, &arg4);

    // static cocos2d::JumpBy *create(float duration, @pack const cocos2d::Vec2 &position, float height, int jumps)
    cocos2d::JumpBy *ret = cocos2d::JumpBy::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.JumpBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_JumpBy_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 4) {
        // if ((olua_is_number(L, 1)) && (olua_is_object(L, 2, "cc.Vec2")) && (olua_is_number(L, 3)) && (olua_is_integer(L, 4))) {
            // static cocos2d::JumpBy *create(float duration, const cocos2d::Vec2 &position, float height, int jumps)
            return _cocos2d_JumpBy_create$1(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_number(L, 1)) && (olua_canpack_object(L, 2, (cocos2d::Vec2 *)nullptr)) && (olua_is_number(L, 4)) && (olua_is_integer(L, 5))) {
            // static cocos2d::JumpBy *create(float duration, @pack const cocos2d::Vec2 &position, float height, int jumps)
            return _cocos2d_JumpBy_create$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::JumpBy::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_JumpBy_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::JumpBy *self = nullptr;

    olua_to_object(L, 1, &self, "cc.JumpBy");

    // cocos2d::JumpBy *reverse()
    cocos2d::JumpBy *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.JumpBy");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_JumpBy(lua_State *L)
{
    oluacls_class<cocos2d::JumpBy, cocos2d::ActionInterval>(L, "cc.JumpBy");
    oluacls_func(L, "clone", _cocos2d_JumpBy_clone);
    oluacls_func(L, "create", _cocos2d_JumpBy_create);
    oluacls_func(L, "reverse", _cocos2d_JumpBy_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_JumpTo_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::JumpTo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.JumpTo");

    // cocos2d::JumpTo *clone()
    cocos2d::JumpTo *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.JumpTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_JumpTo_create$1(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Vec2 arg2;       /** position */
    float arg3 = 0;       /** height */
    int arg4 = 0;       /** jumps */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Vec2");
    olua_check_number(L, 3, &arg3);
    olua_check_integer(L, 4, &arg4);

    // static cocos2d::JumpTo *create(float duration, const cocos2d::Vec2 &position, float height, int jumps)
    cocos2d::JumpTo *ret = cocos2d::JumpTo::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.JumpTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_JumpTo_create$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Vec2 arg2;       /** position */
    float arg3 = 0;       /** height */
    int arg4 = 0;       /** jumps */

    olua_check_number(L, 1, &arg1);
    olua_pack_object(L, 2, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_integer(L, 5, &arg4);

    // static cocos2d::JumpTo *create(float duration, @pack const cocos2d::Vec2 &position, float height, int jumps)
    cocos2d::JumpTo *ret = cocos2d::JumpTo::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.JumpTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_JumpTo_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 4) {
        // if ((olua_is_number(L, 1)) && (olua_is_object(L, 2, "cc.Vec2")) && (olua_is_number(L, 3)) && (olua_is_integer(L, 4))) {
            // static cocos2d::JumpTo *create(float duration, const cocos2d::Vec2 &position, float height, int jumps)
            return _cocos2d_JumpTo_create$1(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_number(L, 1)) && (olua_canpack_object(L, 2, (cocos2d::Vec2 *)nullptr)) && (olua_is_number(L, 4)) && (olua_is_integer(L, 5))) {
            // static cocos2d::JumpTo *create(float duration, @pack const cocos2d::Vec2 &position, float height, int jumps)
            return _cocos2d_JumpTo_create$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::JumpTo::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_JumpTo_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::JumpTo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.JumpTo");

    // cocos2d::JumpTo *reverse()
    cocos2d::JumpTo *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.JumpTo");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_JumpTo(lua_State *L)
{
    oluacls_class<cocos2d::JumpTo, cocos2d::JumpBy>(L, "cc.JumpTo");
    oluacls_func(L, "clone", _cocos2d_JumpTo_clone);
    oluacls_func(L, "create", _cocos2d_JumpTo_create);
    oluacls_func(L, "reverse", _cocos2d_JumpTo_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_ScaleTo_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ScaleTo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ScaleTo");

    // cocos2d::ScaleTo *clone()
    cocos2d::ScaleTo *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.ScaleTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ScaleTo_create$1(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    float arg2 = 0;       /** s */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static cocos2d::ScaleTo *create(float duration, float s)
    cocos2d::ScaleTo *ret = cocos2d::ScaleTo::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.ScaleTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ScaleTo_create$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    float arg2 = 0;       /** sx */
    float arg3 = 0;       /** sy */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static cocos2d::ScaleTo *create(float duration, float sx, float sy)
    cocos2d::ScaleTo *ret = cocos2d::ScaleTo::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.ScaleTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ScaleTo_create$3(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    float arg2 = 0;       /** sx */
    float arg3 = 0;       /** sy */
    float arg4 = 0;       /** sz */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // static cocos2d::ScaleTo *create(float duration, float sx, float sy, float sz)
    cocos2d::ScaleTo *ret = cocos2d::ScaleTo::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.ScaleTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ScaleTo_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2))) {
            // static cocos2d::ScaleTo *create(float duration, float s)
            return _cocos2d_ScaleTo_create$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // static cocos2d::ScaleTo *create(float duration, float sx, float sy)
            return _cocos2d_ScaleTo_create$2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4))) {
            // static cocos2d::ScaleTo *create(float duration, float sx, float sy, float sz)
            return _cocos2d_ScaleTo_create$3(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ScaleTo::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ScaleTo_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ScaleTo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ScaleTo");

    // cocos2d::ScaleTo *reverse()
    cocos2d::ScaleTo *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ScaleTo");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_ScaleTo(lua_State *L)
{
    oluacls_class<cocos2d::ScaleTo, cocos2d::ActionInterval>(L, "cc.ScaleTo");
    oluacls_func(L, "clone", _cocos2d_ScaleTo_clone);
    oluacls_func(L, "create", _cocos2d_ScaleTo_create);
    oluacls_func(L, "reverse", _cocos2d_ScaleTo_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_ScaleBy_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ScaleBy *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ScaleBy");

    // cocos2d::ScaleBy *clone()
    cocos2d::ScaleBy *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.ScaleBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ScaleBy_create$1(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    float arg2 = 0;       /** s */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static cocos2d::ScaleBy *create(float duration, float s)
    cocos2d::ScaleBy *ret = cocos2d::ScaleBy::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.ScaleBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ScaleBy_create$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    float arg2 = 0;       /** sx */
    float arg3 = 0;       /** sy */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static cocos2d::ScaleBy *create(float duration, float sx, float sy)
    cocos2d::ScaleBy *ret = cocos2d::ScaleBy::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.ScaleBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ScaleBy_create$3(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    float arg2 = 0;       /** sx */
    float arg3 = 0;       /** sy */
    float arg4 = 0;       /** sz */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // static cocos2d::ScaleBy *create(float duration, float sx, float sy, float sz)
    cocos2d::ScaleBy *ret = cocos2d::ScaleBy::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.ScaleBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ScaleBy_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2))) {
            // static cocos2d::ScaleBy *create(float duration, float s)
            return _cocos2d_ScaleBy_create$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // static cocos2d::ScaleBy *create(float duration, float sx, float sy)
            return _cocos2d_ScaleBy_create$2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4))) {
            // static cocos2d::ScaleBy *create(float duration, float sx, float sy, float sz)
            return _cocos2d_ScaleBy_create$3(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ScaleBy::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ScaleBy_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ScaleBy *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ScaleBy");

    // cocos2d::ScaleBy *reverse()
    cocos2d::ScaleBy *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ScaleBy");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_ScaleBy(lua_State *L)
{
    oluacls_class<cocos2d::ScaleBy, cocos2d::ScaleTo>(L, "cc.ScaleBy");
    oluacls_func(L, "clone", _cocos2d_ScaleBy_clone);
    oluacls_func(L, "create", _cocos2d_ScaleBy_create);
    oluacls_func(L, "reverse", _cocos2d_ScaleBy_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_ScaleFrom_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ScaleFrom *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ScaleFrom");

    // cocos2d::ScaleFrom *clone()
    cocos2d::ScaleFrom *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.ScaleFrom");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ScaleFrom_create$1(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    float arg2 = 0;       /** s */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static cocos2d::ScaleFrom *create(float duration, float s)
    cocos2d::ScaleFrom *ret = cocos2d::ScaleFrom::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.ScaleFrom");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ScaleFrom_create$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    float arg2 = 0;       /** sx */
    float arg3 = 0;       /** sy */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static cocos2d::ScaleFrom *create(float duration, float sx, float sy)
    cocos2d::ScaleFrom *ret = cocos2d::ScaleFrom::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.ScaleFrom");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ScaleFrom_create$3(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    float arg2 = 0;       /** sx */
    float arg3 = 0;       /** sy */
    float arg4 = 0;       /** sz */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // static cocos2d::ScaleFrom *create(float duration, float sx, float sy, float sz)
    cocos2d::ScaleFrom *ret = cocos2d::ScaleFrom::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.ScaleFrom");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ScaleFrom_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2))) {
            // static cocos2d::ScaleFrom *create(float duration, float s)
            return _cocos2d_ScaleFrom_create$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // static cocos2d::ScaleFrom *create(float duration, float sx, float sy)
            return _cocos2d_ScaleFrom_create$2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4))) {
            // static cocos2d::ScaleFrom *create(float duration, float sx, float sy, float sz)
            return _cocos2d_ScaleFrom_create$3(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ScaleFrom::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ScaleFrom_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ScaleFrom *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ScaleFrom");

    // cocos2d::ScaleFrom *reverse()
    cocos2d::ScaleFrom *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ScaleFrom");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_ScaleFrom(lua_State *L)
{
    oluacls_class<cocos2d::ScaleFrom, cocos2d::ScaleTo>(L, "cc.ScaleFrom");
    oluacls_func(L, "clone", _cocos2d_ScaleFrom_clone);
    oluacls_func(L, "create", _cocos2d_ScaleFrom_create);
    oluacls_func(L, "reverse", _cocos2d_ScaleFrom_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_Blink_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Blink *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Blink");

    // cocos2d::Blink *clone()
    cocos2d::Blink *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.Blink");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Blink_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    int arg2 = 0;       /** blinks */

    olua_check_number(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);

    // static cocos2d::Blink *create(float duration, int blinks)
    cocos2d::Blink *ret = cocos2d::Blink::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.Blink");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Blink_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Blink *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Blink");

    // cocos2d::Blink *reverse()
    cocos2d::Blink *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.Blink");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_Blink(lua_State *L)
{
    oluacls_class<cocos2d::Blink, cocos2d::ActionInterval>(L, "cc.Blink");
    oluacls_func(L, "clone", _cocos2d_Blink_clone);
    oluacls_func(L, "create", _cocos2d_Blink_create);
    oluacls_func(L, "reverse", _cocos2d_Blink_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_FadeTo_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FadeTo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.FadeTo");

    // cocos2d::FadeTo *clone()
    cocos2d::FadeTo *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.FadeTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_FadeTo_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    uint8_t arg2 = 0;       /** opacity */

    olua_check_number(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);

    // static cocos2d::FadeTo *create(float duration, uint8_t opacity)
    cocos2d::FadeTo *ret = cocos2d::FadeTo::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.FadeTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_FadeTo_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FadeTo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.FadeTo");

    // cocos2d::FadeTo *reverse()
    cocos2d::FadeTo *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.FadeTo");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_FadeTo(lua_State *L)
{
    oluacls_class<cocos2d::FadeTo, cocos2d::ActionInterval>(L, "cc.FadeTo");
    oluacls_func(L, "clone", _cocos2d_FadeTo_clone);
    oluacls_func(L, "create", _cocos2d_FadeTo_create);
    oluacls_func(L, "reverse", _cocos2d_FadeTo_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_FadeFrom_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FadeFrom *self = nullptr;

    olua_to_object(L, 1, &self, "cc.FadeFrom");

    // cocos2d::FadeFrom *clone()
    cocos2d::FadeFrom *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.FadeFrom");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_FadeFrom_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** d */
    uint8_t arg2 = 0;       /** opacity */

    olua_check_number(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);

    // static cocos2d::FadeFrom *create(float d, uint8_t opacity)
    cocos2d::FadeFrom *ret = cocos2d::FadeFrom::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.FadeFrom");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_FadeFrom_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FadeFrom *self = nullptr;

    olua_to_object(L, 1, &self, "cc.FadeFrom");

    // cocos2d::FadeFrom *reverse()
    cocos2d::FadeFrom *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.FadeFrom");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_FadeFrom(lua_State *L)
{
    oluacls_class<cocos2d::FadeFrom, cocos2d::FadeTo>(L, "cc.FadeFrom");
    oluacls_func(L, "clone", _cocos2d_FadeFrom_clone);
    oluacls_func(L, "create", _cocos2d_FadeFrom_create);
    oluacls_func(L, "reverse", _cocos2d_FadeFrom_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_FadeIn_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FadeIn *self = nullptr;

    olua_to_object(L, 1, &self, "cc.FadeIn");

    // cocos2d::FadeIn *clone()
    cocos2d::FadeIn *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.FadeIn");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_FadeIn_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** d */

    olua_check_number(L, 1, &arg1);

    // static cocos2d::FadeIn *create(float d)
    cocos2d::FadeIn *ret = cocos2d::FadeIn::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.FadeIn");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_FadeIn(lua_State *L)
{
    oluacls_class<cocos2d::FadeIn, cocos2d::FadeTo>(L, "cc.FadeIn");
    oluacls_func(L, "clone", _cocos2d_FadeIn_clone);
    oluacls_func(L, "create", _cocos2d_FadeIn_create);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_FadeOut_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FadeOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.FadeOut");

    // cocos2d::FadeOut *clone()
    cocos2d::FadeOut *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.FadeOut");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_FadeOut_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** d */

    olua_check_number(L, 1, &arg1);

    // static cocos2d::FadeOut *create(float d)
    cocos2d::FadeOut *ret = cocos2d::FadeOut::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.FadeOut");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_FadeOut(lua_State *L)
{
    oluacls_class<cocos2d::FadeOut, cocos2d::FadeTo>(L, "cc.FadeOut");
    oluacls_func(L, "clone", _cocos2d_FadeOut_clone);
    oluacls_func(L, "create", _cocos2d_FadeOut_create);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_TintTo_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TintTo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.TintTo");

    // cocos2d::TintTo *clone()
    cocos2d::TintTo *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.TintTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TintTo_create$1(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    uint8_t arg2 = 0;       /** red */
    uint8_t arg3 = 0;       /** green */
    uint8_t arg4 = 0;       /** blue */

    olua_check_number(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);
    olua_check_integer(L, 4, &arg4);

    // static cocos2d::TintTo *create(float duration, uint8_t red, uint8_t green, uint8_t blue)
    cocos2d::TintTo *ret = cocos2d::TintTo::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.TintTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TintTo_create$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Color3B arg2;       /** color */

    olua_check_number(L, 1, &arg1);
    olua_check_cocos2d_Color3B(L, 2, &arg2);

    // static cocos2d::TintTo *create(float duration, const cocos2d::Color3B &color)
    cocos2d::TintTo *ret = cocos2d::TintTo::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.TintTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TintTo_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_number(L, 1)) && (olua_is_cocos2d_Color3B(L, 2))) {
            // static cocos2d::TintTo *create(float duration, const cocos2d::Color3B &color)
            return _cocos2d_TintTo_create$2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_number(L, 1)) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3)) && (olua_is_integer(L, 4))) {
            // static cocos2d::TintTo *create(float duration, uint8_t red, uint8_t green, uint8_t blue)
            return _cocos2d_TintTo_create$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::TintTo::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_TintTo_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TintTo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.TintTo");

    // cocos2d::TintTo *reverse()
    cocos2d::TintTo *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.TintTo");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_TintTo(lua_State *L)
{
    oluacls_class<cocos2d::TintTo, cocos2d::ActionInterval>(L, "cc.TintTo");
    oluacls_func(L, "clone", _cocos2d_TintTo_clone);
    oluacls_func(L, "create", _cocos2d_TintTo_create);
    oluacls_func(L, "reverse", _cocos2d_TintTo_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_TintBy_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TintBy *self = nullptr;

    olua_to_object(L, 1, &self, "cc.TintBy");

    // cocos2d::TintBy *clone()
    cocos2d::TintBy *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.TintBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TintBy_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    int16_t arg2 = 0;       /** deltaRed */
    int16_t arg3 = 0;       /** deltaGreen */
    int16_t arg4 = 0;       /** deltaBlue */

    olua_check_number(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);
    olua_check_integer(L, 3, &arg3);
    olua_check_integer(L, 4, &arg4);

    // static cocos2d::TintBy *create(float duration, int16_t deltaRed, int16_t deltaGreen, int16_t deltaBlue)
    cocos2d::TintBy *ret = cocos2d::TintBy::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.TintBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TintBy_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TintBy *self = nullptr;

    olua_to_object(L, 1, &self, "cc.TintBy");

    // cocos2d::TintBy *reverse()
    cocos2d::TintBy *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.TintBy");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_TintBy(lua_State *L)
{
    oluacls_class<cocos2d::TintBy, cocos2d::ActionInterval>(L, "cc.TintBy");
    oluacls_func(L, "clone", _cocos2d_TintBy_clone);
    oluacls_func(L, "create", _cocos2d_TintBy_create);
    oluacls_func(L, "reverse", _cocos2d_TintBy_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_DelayTime_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::DelayTime *self = nullptr;

    olua_to_object(L, 1, &self, "cc.DelayTime");

    // cocos2d::DelayTime *clone()
    cocos2d::DelayTime *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.DelayTime");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_DelayTime_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** d */

    olua_check_number(L, 1, &arg1);

    // static cocos2d::DelayTime *create(float d)
    cocos2d::DelayTime *ret = cocos2d::DelayTime::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.DelayTime");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_DelayTime_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::DelayTime *self = nullptr;

    olua_to_object(L, 1, &self, "cc.DelayTime");

    // cocos2d::DelayTime *reverse()
    cocos2d::DelayTime *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.DelayTime");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_DelayTime(lua_State *L)
{
    oluacls_class<cocos2d::DelayTime, cocos2d::ActionInterval>(L, "cc.DelayTime");
    oluacls_func(L, "clone", _cocos2d_DelayTime_clone);
    oluacls_func(L, "create", _cocos2d_DelayTime_create);
    oluacls_func(L, "reverse", _cocos2d_DelayTime_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_ReverseTime_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ReverseTime *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ReverseTime");

    // cocos2d::ReverseTime *clone()
    cocos2d::ReverseTime *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.ReverseTime");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ReverseTime_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.FiniteTimeAction");

    // static cocos2d::ReverseTime *create(@addref(actions |) cocos2d::FiniteTimeAction *action)
    cocos2d::ReverseTime *ret = cocos2d::ReverseTime::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.ReverseTime");

    // insert code after call
    olua_addref(L, -1, "actions", 1, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ReverseTime_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ReverseTime *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ReverseTime");

    // cocos2d::ReverseTime *reverse()
    cocos2d::ReverseTime *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ReverseTime");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_ReverseTime(lua_State *L)
{
    oluacls_class<cocos2d::ReverseTime, cocos2d::ActionInterval>(L, "cc.ReverseTime");
    oluacls_func(L, "clone", _cocos2d_ReverseTime_clone);
    oluacls_func(L, "create", _cocos2d_ReverseTime_create);
    oluacls_func(L, "reverse", _cocos2d_ReverseTime_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_Animate_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Animate *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Animate");

    // cocos2d::Animate *clone()
    cocos2d::Animate *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.Animate");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Animate_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Animation *arg1 = nullptr;       /** animation */

    olua_check_object(L, 1, &arg1, "cc.Animation");

    // static cocos2d::Animate *create(cocos2d::Animation *animation)
    cocos2d::Animate *ret = cocos2d::Animate::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.Animate");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Animate_getAnimation(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Animate *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Animate");

    // cocos2d::Animation *getAnimation()
    cocos2d::Animation *ret = self->getAnimation();
    int num_ret = olua_push_object(L, ret, "cc.Animation");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Animate_getCurrentFrameIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Animate *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Animate");

    // int getCurrentFrameIndex()
    int ret = self->getCurrentFrameIndex();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Animate_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Animate *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Animate");

    // cocos2d::Animate *reverse()
    cocos2d::Animate *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.Animate");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Animate_setAnimation(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Animate *self = nullptr;
    cocos2d::Animation *arg1 = nullptr;       /** animation */

    olua_to_object(L, 1, &self, "cc.Animate");
    olua_check_object(L, 2, &arg1, "cc.Animation");

    // void setAnimation(cocos2d::Animation *animation)
    self->setAnimation(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_Animate(lua_State *L)
{
    oluacls_class<cocos2d::Animate, cocos2d::ActionInterval>(L, "cc.Animate");
    oluacls_func(L, "clone", _cocos2d_Animate_clone);
    oluacls_func(L, "create", _cocos2d_Animate_create);
    oluacls_func(L, "getAnimation", _cocos2d_Animate_getAnimation);
    oluacls_func(L, "getCurrentFrameIndex", _cocos2d_Animate_getCurrentFrameIndex);
    oluacls_func(L, "reverse", _cocos2d_Animate_reverse);
    oluacls_func(L, "setAnimation", _cocos2d_Animate_setAnimation);
    oluacls_prop(L, "animation", _cocos2d_Animate_getAnimation, _cocos2d_Animate_setAnimation);
    oluacls_prop(L, "currentFrameIndex", _cocos2d_Animate_getCurrentFrameIndex, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_TargetedAction_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TargetedAction *self = nullptr;

    olua_to_object(L, 1, &self, "cc.TargetedAction");

    // cocos2d::TargetedAction *clone()
    cocos2d::TargetedAction *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.TargetedAction");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TargetedAction_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Node *arg1 = nullptr;       /** target */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.Node");
    olua_check_object(L, 2, &arg2, "cc.FiniteTimeAction");

    // static cocos2d::TargetedAction *create(cocos2d::Node *target, @addref(actions |) cocos2d::FiniteTimeAction *action)
    cocos2d::TargetedAction *ret = cocos2d::TargetedAction::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.TargetedAction");

    // insert code after call
    olua_addref(L, -1, "actions", 2, OLUA_REF_MULTI);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TargetedAction_getForcedTarget(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TargetedAction *self = nullptr;

    olua_to_object(L, 1, &self, "cc.TargetedAction");

    // cocos2d::Node *getForcedTarget()
    cocos2d::Node *ret = self->getForcedTarget();
    int num_ret = olua_push_object(L, ret, "cc.Node");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TargetedAction_initWithTarget(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TargetedAction *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** target */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action */

    olua_to_object(L, 1, &self, "cc.TargetedAction");
    olua_check_object(L, 2, &arg1, "cc.Node");
    olua_check_object(L, 3, &arg2, "cc.FiniteTimeAction");

    // bool initWithTarget(cocos2d::Node *target, cocos2d::FiniteTimeAction *action)
    bool ret = self->initWithTarget(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TargetedAction_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TargetedAction *self = nullptr;

    olua_to_object(L, 1, &self, "cc.TargetedAction");

    // cocos2d::TargetedAction *reverse()
    cocos2d::TargetedAction *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.TargetedAction");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TargetedAction_setForcedTarget(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TargetedAction *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** forcedTarget */

    olua_to_object(L, 1, &self, "cc.TargetedAction");
    olua_check_object(L, 2, &arg1, "cc.Node");

    // void setForcedTarget(cocos2d::Node *forcedTarget)
    self->setForcedTarget(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_TargetedAction(lua_State *L)
{
    oluacls_class<cocos2d::TargetedAction, cocos2d::ActionInterval>(L, "cc.TargetedAction");
    oluacls_func(L, "clone", _cocos2d_TargetedAction_clone);
    oluacls_func(L, "create", _cocos2d_TargetedAction_create);
    oluacls_func(L, "getForcedTarget", _cocos2d_TargetedAction_getForcedTarget);
    oluacls_func(L, "initWithTarget", _cocos2d_TargetedAction_initWithTarget);
    oluacls_func(L, "reverse", _cocos2d_TargetedAction_reverse);
    oluacls_func(L, "setForcedTarget", _cocos2d_TargetedAction_setForcedTarget);
    oluacls_prop(L, "forcedTarget", _cocos2d_TargetedAction_getForcedTarget, _cocos2d_TargetedAction_setForcedTarget);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_ActionFloat_ActionFloatCallback___call(lua_State *L)
{
    olua_startinvoke(L);

    luaL_checktype(L, -1, LUA_TFUNCTION);
    olua_push_callback(L, (cocos2d::ActionFloat::ActionFloatCallback *)nullptr, "cc.ActionFloat.ActionFloatCallback");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_ActionFloat_ActionFloatCallback(lua_State *L)
{
    oluacls_class<cocos2d::ActionFloat::ActionFloatCallback>(L, "cc.ActionFloat.ActionFloatCallback");
    oluacls_func(L, "__call", _cocos2d_ActionFloat_ActionFloatCallback___call);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_ActionFloat_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionFloat *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ActionFloat");

    // cocos2d::ActionFloat *clone()
    cocos2d::ActionFloat *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.ActionFloat");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ActionFloat_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    float arg2 = 0;       /** from */
    float arg3 = 0;       /** to */
    cocos2d::ActionFloat::ActionFloatCallback arg4;       /** callback */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_callback(L, 4, &arg4, "cc.ActionFloat.ActionFloatCallback");

    void *cb_store = (void *)olua_newobjstub(L, "cc.ActionFloat");
    std::string cb_tag = "ActionFloat";
    std::string cb_name = olua_setcallback(L, cb_store,  4, cb_tag.c_str(), OLUA_TAG_NEW);
    olua_Context cb_ctx = olua_context(L);
    arg4 = [cb_store, cb_name, cb_ctx](float arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_number(L, arg1);

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            lua_settop(L, top);
        }
    };

    // static cocos2d::ActionFloat *create(float duration, float from, float to, @localvar cocos2d::ActionFloat::ActionFloatCallback callback)
    cocos2d::ActionFloat *ret = cocos2d::ActionFloat::create(arg1, arg2, arg3, arg4);
    if (olua_pushobjstub(L, ret, cb_store, "cc.ActionFloat") == OLUA_OBJ_EXIST) {
        lua_pushstring(L, cb_name.c_str());
        lua_pushvalue(L, 4);
        olua_setvariable(L, -3);
    } else {
        olua_postpush(L, ret, OLUA_OBJ_NEW);
    };

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ActionFloat_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionFloat *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ActionFloat");

    // cocos2d::ActionFloat *reverse()
    cocos2d::ActionFloat *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionFloat");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_ActionFloat(lua_State *L)
{
    oluacls_class<cocos2d::ActionFloat, cocos2d::ActionInterval>(L, "cc.ActionFloat");
    oluacls_func(L, "clone", _cocos2d_ActionFloat_clone);
    oluacls_func(L, "create", _cocos2d_ActionFloat_create);
    oluacls_func(L, "reverse", _cocos2d_ActionFloat_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_ProgressTo_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ProgressTo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ProgressTo");

    // cocos2d::ProgressTo *clone()
    cocos2d::ProgressTo *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.ProgressTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ProgressTo_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    float arg2 = 0;       /** percent */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static cocos2d::ProgressTo *create(float duration, float percent)
    cocos2d::ProgressTo *ret = cocos2d::ProgressTo::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.ProgressTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ProgressTo_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ProgressTo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ProgressTo");

    // cocos2d::ProgressTo *reverse()
    cocos2d::ProgressTo *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ProgressTo");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_ProgressTo(lua_State *L)
{
    oluacls_class<cocos2d::ProgressTo, cocos2d::ActionInterval>(L, "cc.ProgressTo");
    oluacls_func(L, "clone", _cocos2d_ProgressTo_clone);
    oluacls_func(L, "create", _cocos2d_ProgressTo_create);
    oluacls_func(L, "reverse", _cocos2d_ProgressTo_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_ProgressFromTo_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ProgressFromTo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ProgressFromTo");

    // cocos2d::ProgressFromTo *clone()
    cocos2d::ProgressFromTo *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.ProgressFromTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ProgressFromTo_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    float arg2 = 0;       /** fromPercentage */
    float arg3 = 0;       /** toPercentage */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static cocos2d::ProgressFromTo *create(float duration, float fromPercentage, float toPercentage)
    cocos2d::ProgressFromTo *ret = cocos2d::ProgressFromTo::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.ProgressFromTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ProgressFromTo_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ProgressFromTo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ProgressFromTo");

    // cocos2d::ProgressFromTo *reverse()
    cocos2d::ProgressFromTo *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ProgressFromTo");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_ProgressFromTo(lua_State *L)
{
    oluacls_class<cocos2d::ProgressFromTo, cocos2d::ActionInterval>(L, "cc.ProgressFromTo");
    oluacls_func(L, "clone", _cocos2d_ProgressFromTo_clone);
    oluacls_func(L, "create", _cocos2d_ProgressFromTo_create);
    oluacls_func(L, "reverse", _cocos2d_ProgressFromTo_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_ActionEase_getInnerAction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionEase *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ActionEase");

    // @addref(innerAction ^) cocos2d::ActionInterval *getInnerAction()
    cocos2d::ActionInterval *ret = self->getInnerAction();
    int num_ret = olua_push_object(L, ret, "cc.ActionInterval");

    // insert code after call
    olua_addref(L, 1, "innerAction", -1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_ActionEase(lua_State *L)
{
    oluacls_class<cocos2d::ActionEase, cocos2d::ActionInterval>(L, "cc.ActionEase");
    oluacls_func(L, "getInnerAction", _cocos2d_ActionEase_getInnerAction);
    oluacls_prop(L, "innerAction", _cocos2d_ActionEase_getInnerAction, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseRateAction_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */
    float arg2 = 0;       /** rate */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");
    olua_check_number(L, 2, &arg2);

    // static cocos2d::EaseRateAction *create(@addref(innerAction ^) cocos2d::ActionInterval *action, float rate)
    cocos2d::EaseRateAction *ret = cocos2d::EaseRateAction::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.EaseRateAction");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseRateAction_getRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseRateAction *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseRateAction");

    // float getRate()
    float ret = self->getRate();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseRateAction_setRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseRateAction *self = nullptr;
    float arg1 = 0;       /** rate */

    olua_to_object(L, 1, &self, "cc.EaseRateAction");
    olua_check_number(L, 2, &arg1);

    // void setRate(float rate)
    self->setRate(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseRateAction(lua_State *L)
{
    oluacls_class<cocos2d::EaseRateAction, cocos2d::ActionEase>(L, "cc.EaseRateAction");
    oluacls_func(L, "create", _cocos2d_EaseRateAction_create);
    oluacls_func(L, "getRate", _cocos2d_EaseRateAction_getRate);
    oluacls_func(L, "setRate", _cocos2d_EaseRateAction_setRate);
    oluacls_prop(L, "rate", _cocos2d_EaseRateAction_getRate, _cocos2d_EaseRateAction_setRate);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseExponentialIn_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseExponentialIn *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseExponentialIn");

    // cocos2d::EaseExponentialIn *clone()
    cocos2d::EaseExponentialIn *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseExponentialIn");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseExponentialIn_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseExponentialIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseExponentialIn *ret = cocos2d::EaseExponentialIn::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseExponentialIn");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseExponentialIn_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseExponentialIn *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseExponentialIn");

    // cocos2d::ActionEase *reverse()
    cocos2d::ActionEase *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionEase");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseExponentialIn(lua_State *L)
{
    oluacls_class<cocos2d::EaseExponentialIn, cocos2d::ActionEase>(L, "cc.EaseExponentialIn");
    oluacls_func(L, "clone", _cocos2d_EaseExponentialIn_clone);
    oluacls_func(L, "create", _cocos2d_EaseExponentialIn_create);
    oluacls_func(L, "reverse", _cocos2d_EaseExponentialIn_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseExponentialOut_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseExponentialOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseExponentialOut");

    // cocos2d::EaseExponentialOut *clone()
    cocos2d::EaseExponentialOut *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseExponentialOut");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseExponentialOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseExponentialOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseExponentialOut *ret = cocos2d::EaseExponentialOut::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseExponentialOut");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseExponentialOut_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseExponentialOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseExponentialOut");

    // cocos2d::ActionEase *reverse()
    cocos2d::ActionEase *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionEase");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseExponentialOut(lua_State *L)
{
    oluacls_class<cocos2d::EaseExponentialOut, cocos2d::ActionEase>(L, "cc.EaseExponentialOut");
    oluacls_func(L, "clone", _cocos2d_EaseExponentialOut_clone);
    oluacls_func(L, "create", _cocos2d_EaseExponentialOut_create);
    oluacls_func(L, "reverse", _cocos2d_EaseExponentialOut_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseExponentialInOut_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseExponentialInOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseExponentialInOut");

    // cocos2d::EaseExponentialInOut *clone()
    cocos2d::EaseExponentialInOut *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseExponentialInOut");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseExponentialInOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseExponentialInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseExponentialInOut *ret = cocos2d::EaseExponentialInOut::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseExponentialInOut");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseExponentialInOut_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseExponentialInOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseExponentialInOut");

    // cocos2d::ActionEase *reverse()
    cocos2d::ActionEase *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionEase");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseExponentialInOut(lua_State *L)
{
    oluacls_class<cocos2d::EaseExponentialInOut, cocos2d::ActionEase>(L, "cc.EaseExponentialInOut");
    oluacls_func(L, "clone", _cocos2d_EaseExponentialInOut_clone);
    oluacls_func(L, "create", _cocos2d_EaseExponentialInOut_create);
    oluacls_func(L, "reverse", _cocos2d_EaseExponentialInOut_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseSineIn_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseSineIn *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseSineIn");

    // cocos2d::EaseSineIn *clone()
    cocos2d::EaseSineIn *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseSineIn");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseSineIn_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseSineIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseSineIn *ret = cocos2d::EaseSineIn::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseSineIn");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseSineIn_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseSineIn *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseSineIn");

    // cocos2d::ActionEase *reverse()
    cocos2d::ActionEase *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionEase");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseSineIn(lua_State *L)
{
    oluacls_class<cocos2d::EaseSineIn, cocos2d::ActionEase>(L, "cc.EaseSineIn");
    oluacls_func(L, "clone", _cocos2d_EaseSineIn_clone);
    oluacls_func(L, "create", _cocos2d_EaseSineIn_create);
    oluacls_func(L, "reverse", _cocos2d_EaseSineIn_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseSineOut_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseSineOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseSineOut");

    // cocos2d::EaseSineOut *clone()
    cocos2d::EaseSineOut *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseSineOut");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseSineOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseSineOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseSineOut *ret = cocos2d::EaseSineOut::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseSineOut");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseSineOut_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseSineOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseSineOut");

    // cocos2d::ActionEase *reverse()
    cocos2d::ActionEase *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionEase");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseSineOut(lua_State *L)
{
    oluacls_class<cocos2d::EaseSineOut, cocos2d::ActionEase>(L, "cc.EaseSineOut");
    oluacls_func(L, "clone", _cocos2d_EaseSineOut_clone);
    oluacls_func(L, "create", _cocos2d_EaseSineOut_create);
    oluacls_func(L, "reverse", _cocos2d_EaseSineOut_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseSineInOut_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseSineInOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseSineInOut");

    // cocos2d::EaseSineInOut *clone()
    cocos2d::EaseSineInOut *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseSineInOut");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseSineInOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseSineInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseSineInOut *ret = cocos2d::EaseSineInOut::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseSineInOut");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseSineInOut_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseSineInOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseSineInOut");

    // cocos2d::ActionEase *reverse()
    cocos2d::ActionEase *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionEase");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseSineInOut(lua_State *L)
{
    oluacls_class<cocos2d::EaseSineInOut, cocos2d::ActionEase>(L, "cc.EaseSineInOut");
    oluacls_func(L, "clone", _cocos2d_EaseSineInOut_clone);
    oluacls_func(L, "create", _cocos2d_EaseSineInOut_create);
    oluacls_func(L, "reverse", _cocos2d_EaseSineInOut_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseBounceIn_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseBounceIn *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseBounceIn");

    // cocos2d::EaseBounceIn *clone()
    cocos2d::EaseBounceIn *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseBounceIn");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseBounceIn_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseBounceIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseBounceIn *ret = cocos2d::EaseBounceIn::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseBounceIn");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseBounceIn_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseBounceIn *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseBounceIn");

    // cocos2d::ActionEase *reverse()
    cocos2d::ActionEase *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionEase");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseBounceIn(lua_State *L)
{
    oluacls_class<cocos2d::EaseBounceIn, cocos2d::ActionEase>(L, "cc.EaseBounceIn");
    oluacls_func(L, "clone", _cocos2d_EaseBounceIn_clone);
    oluacls_func(L, "create", _cocos2d_EaseBounceIn_create);
    oluacls_func(L, "reverse", _cocos2d_EaseBounceIn_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseBounceOut_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseBounceOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseBounceOut");

    // cocos2d::EaseBounceOut *clone()
    cocos2d::EaseBounceOut *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseBounceOut");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseBounceOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseBounceOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseBounceOut *ret = cocos2d::EaseBounceOut::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseBounceOut");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseBounceOut_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseBounceOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseBounceOut");

    // cocos2d::ActionEase *reverse()
    cocos2d::ActionEase *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionEase");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseBounceOut(lua_State *L)
{
    oluacls_class<cocos2d::EaseBounceOut, cocos2d::ActionEase>(L, "cc.EaseBounceOut");
    oluacls_func(L, "clone", _cocos2d_EaseBounceOut_clone);
    oluacls_func(L, "create", _cocos2d_EaseBounceOut_create);
    oluacls_func(L, "reverse", _cocos2d_EaseBounceOut_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseBounceInOut_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseBounceInOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseBounceInOut");

    // cocos2d::EaseBounceInOut *clone()
    cocos2d::EaseBounceInOut *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseBounceInOut");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseBounceInOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseBounceInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseBounceInOut *ret = cocos2d::EaseBounceInOut::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseBounceInOut");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseBounceInOut_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseBounceInOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseBounceInOut");

    // cocos2d::ActionEase *reverse()
    cocos2d::ActionEase *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionEase");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseBounceInOut(lua_State *L)
{
    oluacls_class<cocos2d::EaseBounceInOut, cocos2d::ActionEase>(L, "cc.EaseBounceInOut");
    oluacls_func(L, "clone", _cocos2d_EaseBounceInOut_clone);
    oluacls_func(L, "create", _cocos2d_EaseBounceInOut_create);
    oluacls_func(L, "reverse", _cocos2d_EaseBounceInOut_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseBackIn_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseBackIn *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseBackIn");

    // cocos2d::EaseBackIn *clone()
    cocos2d::EaseBackIn *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseBackIn");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseBackIn_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseBackIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseBackIn *ret = cocos2d::EaseBackIn::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseBackIn");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseBackIn_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseBackIn *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseBackIn");

    // cocos2d::ActionEase *reverse()
    cocos2d::ActionEase *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionEase");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseBackIn(lua_State *L)
{
    oluacls_class<cocos2d::EaseBackIn, cocos2d::ActionEase>(L, "cc.EaseBackIn");
    oluacls_func(L, "clone", _cocos2d_EaseBackIn_clone);
    oluacls_func(L, "create", _cocos2d_EaseBackIn_create);
    oluacls_func(L, "reverse", _cocos2d_EaseBackIn_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseBackOut_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseBackOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseBackOut");

    // cocos2d::EaseBackOut *clone()
    cocos2d::EaseBackOut *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseBackOut");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseBackOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseBackOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseBackOut *ret = cocos2d::EaseBackOut::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseBackOut");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseBackOut_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseBackOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseBackOut");

    // cocos2d::ActionEase *reverse()
    cocos2d::ActionEase *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionEase");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseBackOut(lua_State *L)
{
    oluacls_class<cocos2d::EaseBackOut, cocos2d::ActionEase>(L, "cc.EaseBackOut");
    oluacls_func(L, "clone", _cocos2d_EaseBackOut_clone);
    oluacls_func(L, "create", _cocos2d_EaseBackOut_create);
    oluacls_func(L, "reverse", _cocos2d_EaseBackOut_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseBackInOut_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseBackInOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseBackInOut");

    // cocos2d::EaseBackInOut *clone()
    cocos2d::EaseBackInOut *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseBackInOut");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseBackInOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseBackInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseBackInOut *ret = cocos2d::EaseBackInOut::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseBackInOut");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseBackInOut_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseBackInOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseBackInOut");

    // cocos2d::ActionEase *reverse()
    cocos2d::ActionEase *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionEase");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseBackInOut(lua_State *L)
{
    oluacls_class<cocos2d::EaseBackInOut, cocos2d::ActionEase>(L, "cc.EaseBackInOut");
    oluacls_func(L, "clone", _cocos2d_EaseBackInOut_clone);
    oluacls_func(L, "create", _cocos2d_EaseBackInOut_create);
    oluacls_func(L, "reverse", _cocos2d_EaseBackInOut_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseQuadraticActionIn_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseQuadraticActionIn *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseQuadraticActionIn");

    // cocos2d::EaseQuadraticActionIn *clone()
    cocos2d::EaseQuadraticActionIn *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseQuadraticActionIn");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseQuadraticActionIn_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseQuadraticActionIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseQuadraticActionIn *ret = cocos2d::EaseQuadraticActionIn::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseQuadraticActionIn");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseQuadraticActionIn_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseQuadraticActionIn *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseQuadraticActionIn");

    // cocos2d::ActionEase *reverse()
    cocos2d::ActionEase *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionEase");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseQuadraticActionIn(lua_State *L)
{
    oluacls_class<cocos2d::EaseQuadraticActionIn, cocos2d::ActionEase>(L, "cc.EaseQuadraticActionIn");
    oluacls_func(L, "clone", _cocos2d_EaseQuadraticActionIn_clone);
    oluacls_func(L, "create", _cocos2d_EaseQuadraticActionIn_create);
    oluacls_func(L, "reverse", _cocos2d_EaseQuadraticActionIn_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseQuadraticActionOut_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseQuadraticActionOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseQuadraticActionOut");

    // cocos2d::EaseQuadraticActionOut *clone()
    cocos2d::EaseQuadraticActionOut *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseQuadraticActionOut");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseQuadraticActionOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseQuadraticActionOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseQuadraticActionOut *ret = cocos2d::EaseQuadraticActionOut::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseQuadraticActionOut");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseQuadraticActionOut_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseQuadraticActionOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseQuadraticActionOut");

    // cocos2d::ActionEase *reverse()
    cocos2d::ActionEase *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionEase");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseQuadraticActionOut(lua_State *L)
{
    oluacls_class<cocos2d::EaseQuadraticActionOut, cocos2d::ActionEase>(L, "cc.EaseQuadraticActionOut");
    oluacls_func(L, "clone", _cocos2d_EaseQuadraticActionOut_clone);
    oluacls_func(L, "create", _cocos2d_EaseQuadraticActionOut_create);
    oluacls_func(L, "reverse", _cocos2d_EaseQuadraticActionOut_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseQuadraticActionInOut_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseQuadraticActionInOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseQuadraticActionInOut");

    // cocos2d::EaseQuadraticActionInOut *clone()
    cocos2d::EaseQuadraticActionInOut *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseQuadraticActionInOut");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseQuadraticActionInOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseQuadraticActionInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseQuadraticActionInOut *ret = cocos2d::EaseQuadraticActionInOut::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseQuadraticActionInOut");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseQuadraticActionInOut_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseQuadraticActionInOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseQuadraticActionInOut");

    // cocos2d::ActionEase *reverse()
    cocos2d::ActionEase *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionEase");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseQuadraticActionInOut(lua_State *L)
{
    oluacls_class<cocos2d::EaseQuadraticActionInOut, cocos2d::ActionEase>(L, "cc.EaseQuadraticActionInOut");
    oluacls_func(L, "clone", _cocos2d_EaseQuadraticActionInOut_clone);
    oluacls_func(L, "create", _cocos2d_EaseQuadraticActionInOut_create);
    oluacls_func(L, "reverse", _cocos2d_EaseQuadraticActionInOut_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseQuarticActionIn_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseQuarticActionIn *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseQuarticActionIn");

    // cocos2d::EaseQuarticActionIn *clone()
    cocos2d::EaseQuarticActionIn *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseQuarticActionIn");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseQuarticActionIn_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseQuarticActionIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseQuarticActionIn *ret = cocos2d::EaseQuarticActionIn::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseQuarticActionIn");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseQuarticActionIn_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseQuarticActionIn *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseQuarticActionIn");

    // cocos2d::ActionEase *reverse()
    cocos2d::ActionEase *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionEase");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseQuarticActionIn(lua_State *L)
{
    oluacls_class<cocos2d::EaseQuarticActionIn, cocos2d::ActionEase>(L, "cc.EaseQuarticActionIn");
    oluacls_func(L, "clone", _cocos2d_EaseQuarticActionIn_clone);
    oluacls_func(L, "create", _cocos2d_EaseQuarticActionIn_create);
    oluacls_func(L, "reverse", _cocos2d_EaseQuarticActionIn_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseQuarticActionOut_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseQuarticActionOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseQuarticActionOut");

    // cocos2d::EaseQuarticActionOut *clone()
    cocos2d::EaseQuarticActionOut *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseQuarticActionOut");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseQuarticActionOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseQuarticActionOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseQuarticActionOut *ret = cocos2d::EaseQuarticActionOut::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseQuarticActionOut");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseQuarticActionOut_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseQuarticActionOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseQuarticActionOut");

    // cocos2d::ActionEase *reverse()
    cocos2d::ActionEase *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionEase");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseQuarticActionOut(lua_State *L)
{
    oluacls_class<cocos2d::EaseQuarticActionOut, cocos2d::ActionEase>(L, "cc.EaseQuarticActionOut");
    oluacls_func(L, "clone", _cocos2d_EaseQuarticActionOut_clone);
    oluacls_func(L, "create", _cocos2d_EaseQuarticActionOut_create);
    oluacls_func(L, "reverse", _cocos2d_EaseQuarticActionOut_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseQuarticActionInOut_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseQuarticActionInOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseQuarticActionInOut");

    // cocos2d::EaseQuarticActionInOut *clone()
    cocos2d::EaseQuarticActionInOut *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseQuarticActionInOut");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseQuarticActionInOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseQuarticActionInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseQuarticActionInOut *ret = cocos2d::EaseQuarticActionInOut::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseQuarticActionInOut");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseQuarticActionInOut_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseQuarticActionInOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseQuarticActionInOut");

    // cocos2d::ActionEase *reverse()
    cocos2d::ActionEase *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionEase");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseQuarticActionInOut(lua_State *L)
{
    oluacls_class<cocos2d::EaseQuarticActionInOut, cocos2d::ActionEase>(L, "cc.EaseQuarticActionInOut");
    oluacls_func(L, "clone", _cocos2d_EaseQuarticActionInOut_clone);
    oluacls_func(L, "create", _cocos2d_EaseQuarticActionInOut_create);
    oluacls_func(L, "reverse", _cocos2d_EaseQuarticActionInOut_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseQuinticActionIn_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseQuinticActionIn *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseQuinticActionIn");

    // cocos2d::EaseQuinticActionIn *clone()
    cocos2d::EaseQuinticActionIn *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseQuinticActionIn");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseQuinticActionIn_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseQuinticActionIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseQuinticActionIn *ret = cocos2d::EaseQuinticActionIn::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseQuinticActionIn");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseQuinticActionIn_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseQuinticActionIn *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseQuinticActionIn");

    // cocos2d::ActionEase *reverse()
    cocos2d::ActionEase *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionEase");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseQuinticActionIn(lua_State *L)
{
    oluacls_class<cocos2d::EaseQuinticActionIn, cocos2d::ActionEase>(L, "cc.EaseQuinticActionIn");
    oluacls_func(L, "clone", _cocos2d_EaseQuinticActionIn_clone);
    oluacls_func(L, "create", _cocos2d_EaseQuinticActionIn_create);
    oluacls_func(L, "reverse", _cocos2d_EaseQuinticActionIn_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseQuinticActionOut_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseQuinticActionOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseQuinticActionOut");

    // cocos2d::EaseQuinticActionOut *clone()
    cocos2d::EaseQuinticActionOut *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseQuinticActionOut");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseQuinticActionOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseQuinticActionOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseQuinticActionOut *ret = cocos2d::EaseQuinticActionOut::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseQuinticActionOut");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseQuinticActionOut_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseQuinticActionOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseQuinticActionOut");

    // cocos2d::ActionEase *reverse()
    cocos2d::ActionEase *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionEase");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseQuinticActionOut(lua_State *L)
{
    oluacls_class<cocos2d::EaseQuinticActionOut, cocos2d::ActionEase>(L, "cc.EaseQuinticActionOut");
    oluacls_func(L, "clone", _cocos2d_EaseQuinticActionOut_clone);
    oluacls_func(L, "create", _cocos2d_EaseQuinticActionOut_create);
    oluacls_func(L, "reverse", _cocos2d_EaseQuinticActionOut_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseQuinticActionInOut_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseQuinticActionInOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseQuinticActionInOut");

    // cocos2d::EaseQuinticActionInOut *clone()
    cocos2d::EaseQuinticActionInOut *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseQuinticActionInOut");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseQuinticActionInOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseQuinticActionInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseQuinticActionInOut *ret = cocos2d::EaseQuinticActionInOut::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseQuinticActionInOut");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseQuinticActionInOut_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseQuinticActionInOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseQuinticActionInOut");

    // cocos2d::ActionEase *reverse()
    cocos2d::ActionEase *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionEase");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseQuinticActionInOut(lua_State *L)
{
    oluacls_class<cocos2d::EaseQuinticActionInOut, cocos2d::ActionEase>(L, "cc.EaseQuinticActionInOut");
    oluacls_func(L, "clone", _cocos2d_EaseQuinticActionInOut_clone);
    oluacls_func(L, "create", _cocos2d_EaseQuinticActionInOut_create);
    oluacls_func(L, "reverse", _cocos2d_EaseQuinticActionInOut_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseCircleActionIn_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseCircleActionIn *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseCircleActionIn");

    // cocos2d::EaseCircleActionIn *clone()
    cocos2d::EaseCircleActionIn *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseCircleActionIn");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseCircleActionIn_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseCircleActionIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseCircleActionIn *ret = cocos2d::EaseCircleActionIn::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseCircleActionIn");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseCircleActionIn_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseCircleActionIn *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseCircleActionIn");

    // cocos2d::ActionEase *reverse()
    cocos2d::ActionEase *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionEase");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseCircleActionIn(lua_State *L)
{
    oluacls_class<cocos2d::EaseCircleActionIn, cocos2d::ActionEase>(L, "cc.EaseCircleActionIn");
    oluacls_func(L, "clone", _cocos2d_EaseCircleActionIn_clone);
    oluacls_func(L, "create", _cocos2d_EaseCircleActionIn_create);
    oluacls_func(L, "reverse", _cocos2d_EaseCircleActionIn_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseCircleActionOut_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseCircleActionOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseCircleActionOut");

    // cocos2d::EaseCircleActionOut *clone()
    cocos2d::EaseCircleActionOut *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseCircleActionOut");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseCircleActionOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseCircleActionOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseCircleActionOut *ret = cocos2d::EaseCircleActionOut::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseCircleActionOut");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseCircleActionOut_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseCircleActionOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseCircleActionOut");

    // cocos2d::ActionEase *reverse()
    cocos2d::ActionEase *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionEase");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseCircleActionOut(lua_State *L)
{
    oluacls_class<cocos2d::EaseCircleActionOut, cocos2d::ActionEase>(L, "cc.EaseCircleActionOut");
    oluacls_func(L, "clone", _cocos2d_EaseCircleActionOut_clone);
    oluacls_func(L, "create", _cocos2d_EaseCircleActionOut_create);
    oluacls_func(L, "reverse", _cocos2d_EaseCircleActionOut_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseCircleActionInOut_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseCircleActionInOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseCircleActionInOut");

    // cocos2d::EaseCircleActionInOut *clone()
    cocos2d::EaseCircleActionInOut *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseCircleActionInOut");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseCircleActionInOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseCircleActionInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseCircleActionInOut *ret = cocos2d::EaseCircleActionInOut::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseCircleActionInOut");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseCircleActionInOut_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseCircleActionInOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseCircleActionInOut");

    // cocos2d::ActionEase *reverse()
    cocos2d::ActionEase *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionEase");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseCircleActionInOut(lua_State *L)
{
    oluacls_class<cocos2d::EaseCircleActionInOut, cocos2d::ActionEase>(L, "cc.EaseCircleActionInOut");
    oluacls_func(L, "clone", _cocos2d_EaseCircleActionInOut_clone);
    oluacls_func(L, "create", _cocos2d_EaseCircleActionInOut_create);
    oluacls_func(L, "reverse", _cocos2d_EaseCircleActionInOut_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseCubicActionIn_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseCubicActionIn *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseCubicActionIn");

    // cocos2d::EaseCubicActionIn *clone()
    cocos2d::EaseCubicActionIn *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseCubicActionIn");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseCubicActionIn_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseCubicActionIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseCubicActionIn *ret = cocos2d::EaseCubicActionIn::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseCubicActionIn");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseCubicActionIn_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseCubicActionIn *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseCubicActionIn");

    // cocos2d::ActionEase *reverse()
    cocos2d::ActionEase *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionEase");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseCubicActionIn(lua_State *L)
{
    oluacls_class<cocos2d::EaseCubicActionIn, cocos2d::ActionEase>(L, "cc.EaseCubicActionIn");
    oluacls_func(L, "clone", _cocos2d_EaseCubicActionIn_clone);
    oluacls_func(L, "create", _cocos2d_EaseCubicActionIn_create);
    oluacls_func(L, "reverse", _cocos2d_EaseCubicActionIn_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseCubicActionOut_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseCubicActionOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseCubicActionOut");

    // cocos2d::EaseCubicActionOut *clone()
    cocos2d::EaseCubicActionOut *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseCubicActionOut");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseCubicActionOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseCubicActionOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseCubicActionOut *ret = cocos2d::EaseCubicActionOut::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseCubicActionOut");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseCubicActionOut_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseCubicActionOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseCubicActionOut");

    // cocos2d::ActionEase *reverse()
    cocos2d::ActionEase *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionEase");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseCubicActionOut(lua_State *L)
{
    oluacls_class<cocos2d::EaseCubicActionOut, cocos2d::ActionEase>(L, "cc.EaseCubicActionOut");
    oluacls_func(L, "clone", _cocos2d_EaseCubicActionOut_clone);
    oluacls_func(L, "create", _cocos2d_EaseCubicActionOut_create);
    oluacls_func(L, "reverse", _cocos2d_EaseCubicActionOut_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseCubicActionInOut_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseCubicActionInOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseCubicActionInOut");

    // cocos2d::EaseCubicActionInOut *clone()
    cocos2d::EaseCubicActionInOut *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseCubicActionInOut");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseCubicActionInOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseCubicActionInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseCubicActionInOut *ret = cocos2d::EaseCubicActionInOut::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseCubicActionInOut");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseCubicActionInOut_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseCubicActionInOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseCubicActionInOut");

    // cocos2d::ActionEase *reverse()
    cocos2d::ActionEase *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionEase");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseCubicActionInOut(lua_State *L)
{
    oluacls_class<cocos2d::EaseCubicActionInOut, cocos2d::ActionEase>(L, "cc.EaseCubicActionInOut");
    oluacls_func(L, "clone", _cocos2d_EaseCubicActionInOut_clone);
    oluacls_func(L, "create", _cocos2d_EaseCubicActionInOut_create);
    oluacls_func(L, "reverse", _cocos2d_EaseCubicActionInOut_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseIn_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseIn *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseIn");

    // cocos2d::EaseIn *clone()
    cocos2d::EaseIn *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseIn");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseIn_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */
    float arg2 = 0;       /** rate */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");
    olua_check_number(L, 2, &arg2);

    // static cocos2d::EaseIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action, float rate)
    cocos2d::EaseIn *ret = cocos2d::EaseIn::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.EaseIn");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseIn_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseIn *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseIn");

    // cocos2d::EaseRateAction *reverse()
    cocos2d::EaseRateAction *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.EaseRateAction");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseIn(lua_State *L)
{
    oluacls_class<cocos2d::EaseIn, cocos2d::EaseRateAction>(L, "cc.EaseIn");
    oluacls_func(L, "clone", _cocos2d_EaseIn_clone);
    oluacls_func(L, "create", _cocos2d_EaseIn_create);
    oluacls_func(L, "reverse", _cocos2d_EaseIn_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseOut_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseOut");

    // cocos2d::EaseOut *clone()
    cocos2d::EaseOut *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseOut");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */
    float arg2 = 0;       /** rate */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");
    olua_check_number(L, 2, &arg2);

    // static cocos2d::EaseOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, float rate)
    cocos2d::EaseOut *ret = cocos2d::EaseOut::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.EaseOut");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseOut_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseOut");

    // cocos2d::EaseRateAction *reverse()
    cocos2d::EaseRateAction *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.EaseRateAction");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseOut(lua_State *L)
{
    oluacls_class<cocos2d::EaseOut, cocos2d::EaseRateAction>(L, "cc.EaseOut");
    oluacls_func(L, "clone", _cocos2d_EaseOut_clone);
    oluacls_func(L, "create", _cocos2d_EaseOut_create);
    oluacls_func(L, "reverse", _cocos2d_EaseOut_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseInOut_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseInOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseInOut");

    // cocos2d::EaseInOut *clone()
    cocos2d::EaseInOut *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseInOut");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseInOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */
    float arg2 = 0;       /** rate */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");
    olua_check_number(L, 2, &arg2);

    // static cocos2d::EaseInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, float rate)
    cocos2d::EaseInOut *ret = cocos2d::EaseInOut::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.EaseInOut");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseInOut_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseInOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseInOut");

    // cocos2d::EaseRateAction *reverse()
    cocos2d::EaseRateAction *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.EaseRateAction");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseInOut(lua_State *L)
{
    oluacls_class<cocos2d::EaseInOut, cocos2d::EaseRateAction>(L, "cc.EaseInOut");
    oluacls_func(L, "clone", _cocos2d_EaseInOut_clone);
    oluacls_func(L, "create", _cocos2d_EaseInOut_create);
    oluacls_func(L, "reverse", _cocos2d_EaseInOut_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseElastic_getPeriod(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseElastic *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseElastic");

    // float getPeriod()
    float ret = self->getPeriod();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseElastic_setPeriod(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseElastic *self = nullptr;
    float arg1 = 0;       /** fPeriod */

    olua_to_object(L, 1, &self, "cc.EaseElastic");
    olua_check_number(L, 2, &arg1);

    // void setPeriod(float fPeriod)
    self->setPeriod(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseElastic(lua_State *L)
{
    oluacls_class<cocos2d::EaseElastic, cocos2d::ActionEase>(L, "cc.EaseElastic");
    oluacls_func(L, "getPeriod", _cocos2d_EaseElastic_getPeriod);
    oluacls_func(L, "setPeriod", _cocos2d_EaseElastic_setPeriod);
    oluacls_prop(L, "period", _cocos2d_EaseElastic_getPeriod, _cocos2d_EaseElastic_setPeriod);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseElasticIn_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseElasticIn *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseElasticIn");

    // cocos2d::EaseElasticIn *clone()
    cocos2d::EaseElasticIn *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseElasticIn");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseElasticIn_create$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */
    float arg2 = 0;       /** rate */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");
    olua_check_number(L, 2, &arg2);

    // static cocos2d::EaseElasticIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)
    cocos2d::EaseElasticIn *ret = cocos2d::EaseElasticIn::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.EaseElasticIn");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseElasticIn_create$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseElasticIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)
    cocos2d::EaseElasticIn *ret = cocos2d::EaseElasticIn::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseElasticIn");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseElasticIn_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_object(L, 1, "cc.ActionInterval"))) {
            // static cocos2d::EaseElasticIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)
            return _cocos2d_EaseElasticIn_create$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.ActionInterval")) && (olua_is_number(L, 2))) {
            // static cocos2d::EaseElasticIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)
            return _cocos2d_EaseElasticIn_create$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::EaseElasticIn::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_EaseElasticIn_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseElasticIn *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseElasticIn");

    // cocos2d::EaseElastic *reverse()
    cocos2d::EaseElastic *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.EaseElastic");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseElasticIn(lua_State *L)
{
    oluacls_class<cocos2d::EaseElasticIn, cocos2d::EaseElastic>(L, "cc.EaseElasticIn");
    oluacls_func(L, "clone", _cocos2d_EaseElasticIn_clone);
    oluacls_func(L, "create", _cocos2d_EaseElasticIn_create);
    oluacls_func(L, "reverse", _cocos2d_EaseElasticIn_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseElasticOut_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseElasticOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseElasticOut");

    // cocos2d::EaseElasticOut *clone()
    cocos2d::EaseElasticOut *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseElasticOut");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseElasticOut_create$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */
    float arg2 = 0;       /** rate */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");
    olua_check_number(L, 2, &arg2);

    // static cocos2d::EaseElasticOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)
    cocos2d::EaseElasticOut *ret = cocos2d::EaseElasticOut::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.EaseElasticOut");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseElasticOut_create$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseElasticOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)
    cocos2d::EaseElasticOut *ret = cocos2d::EaseElasticOut::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseElasticOut");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseElasticOut_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_object(L, 1, "cc.ActionInterval"))) {
            // static cocos2d::EaseElasticOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)
            return _cocos2d_EaseElasticOut_create$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.ActionInterval")) && (olua_is_number(L, 2))) {
            // static cocos2d::EaseElasticOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)
            return _cocos2d_EaseElasticOut_create$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::EaseElasticOut::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_EaseElasticOut_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseElasticOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseElasticOut");

    // cocos2d::EaseElastic *reverse()
    cocos2d::EaseElastic *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.EaseElastic");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseElasticOut(lua_State *L)
{
    oluacls_class<cocos2d::EaseElasticOut, cocos2d::EaseElastic>(L, "cc.EaseElasticOut");
    oluacls_func(L, "clone", _cocos2d_EaseElasticOut_clone);
    oluacls_func(L, "create", _cocos2d_EaseElasticOut_create);
    oluacls_func(L, "reverse", _cocos2d_EaseElasticOut_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseElasticInOut_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseElasticInOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseElasticInOut");

    // cocos2d::EaseElasticInOut *clone()
    cocos2d::EaseElasticInOut *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseElasticInOut");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseElasticInOut_create$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */
    float arg2 = 0;       /** rate */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");
    olua_check_number(L, 2, &arg2);

    // static cocos2d::EaseElasticInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)
    cocos2d::EaseElasticInOut *ret = cocos2d::EaseElasticInOut::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.EaseElasticInOut");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseElasticInOut_create$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseElasticInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)
    cocos2d::EaseElasticInOut *ret = cocos2d::EaseElasticInOut::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseElasticInOut");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseElasticInOut_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_object(L, 1, "cc.ActionInterval"))) {
            // static cocos2d::EaseElasticInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)
            return _cocos2d_EaseElasticInOut_create$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.ActionInterval")) && (olua_is_number(L, 2))) {
            // static cocos2d::EaseElasticInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)
            return _cocos2d_EaseElasticInOut_create$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::EaseElasticInOut::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_EaseElasticInOut_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseElasticInOut *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseElasticInOut");

    // cocos2d::EaseElastic *reverse()
    cocos2d::EaseElastic *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.EaseElastic");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseElasticInOut(lua_State *L)
{
    oluacls_class<cocos2d::EaseElasticInOut, cocos2d::EaseElastic>(L, "cc.EaseElasticInOut");
    oluacls_func(L, "clone", _cocos2d_EaseElasticInOut_clone);
    oluacls_func(L, "create", _cocos2d_EaseElasticInOut_create);
    oluacls_func(L, "reverse", _cocos2d_EaseElasticInOut_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_EaseBezierAction_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseBezierAction *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseBezierAction");

    // cocos2d::EaseBezierAction *clone()
    cocos2d::EaseBezierAction *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EaseBezierAction");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseBezierAction_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_object(L, 1, &arg1, "cc.ActionInterval");

    // static cocos2d::EaseBezierAction *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseBezierAction *ret = cocos2d::EaseBezierAction::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EaseBezierAction");

    // insert code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseBezierAction_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseBezierAction *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EaseBezierAction");

    // cocos2d::EaseBezierAction *reverse()
    cocos2d::EaseBezierAction *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.EaseBezierAction");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseBezierAction_setBezierParamer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseBezierAction *self = nullptr;
    float arg1 = 0;       /** p0 */
    float arg2 = 0;       /** p1 */
    float arg3 = 0;       /** p2 */
    float arg4 = 0;       /** p3 */

    olua_to_object(L, 1, &self, "cc.EaseBezierAction");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // void setBezierParamer(float p0, float p1, float p2, float p3)
    self->setBezierParamer(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EaseBezierAction(lua_State *L)
{
    oluacls_class<cocos2d::EaseBezierAction, cocos2d::ActionEase>(L, "cc.EaseBezierAction");
    oluacls_func(L, "clone", _cocos2d_EaseBezierAction_clone);
    oluacls_func(L, "create", _cocos2d_EaseBezierAction_create);
    oluacls_func(L, "reverse", _cocos2d_EaseBezierAction_reverse);
    oluacls_func(L, "setBezierParamer", _cocos2d_EaseBezierAction_setBezierParamer);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_PointArray_addControlPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PointArray *self = nullptr;
    cocos2d::Vec2 arg1;       /** controlPoint */

    olua_to_object(L, 1, &self, "cc.PointArray");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void addControlPoint(const cocos2d::Vec2 &controlPoint)
    self->addControlPoint(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PointArray_as(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PointArray *self = nullptr;
    const char *arg1 = nullptr;       /** cls */

    olua_to_object(L, 1, &self, "cc.PointArray");
    olua_check_string(L, 2, &arg1);

    do {
        if (olua_isa(L, 1, arg1)) {
            lua_pushvalue(L, 1);
            break;
        }
        if (olua_strequal(arg1, "cc.Clonable")) {
            olua_pushobj_as<cocos2d::Clonable>(L, 1, self, "as.cc.Clonable");
            break;
        }

        luaL_error(L, "'cocos2d::PointArray' can't cast to '%s'", arg1);
    } while (0);

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PointArray_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PointArray *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PointArray");

    // cocos2d::PointArray *clone()
    cocos2d::PointArray *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.PointArray");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PointArray_count(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PointArray *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PointArray");

    // ssize_t count()
    ssize_t ret = self->count();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PointArray_create(lua_State *L)
{
    olua_startinvoke(L);

    ssize_t arg1 = 0;       /** capacity */

    olua_check_integer(L, 1, &arg1);

    // static cocos2d::PointArray *create(ssize_t capacity)
    cocos2d::PointArray *ret = cocos2d::PointArray::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.PointArray");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PointArray_getControlPointAtIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PointArray *self = nullptr;
    ssize_t arg1 = 0;       /** index */

    olua_to_object(L, 1, &self, "cc.PointArray");
    olua_check_integer(L, 2, &arg1);

    // const cocos2d::Vec2 &getControlPointAtIndex(ssize_t index)
    const cocos2d::Vec2 &ret = self->getControlPointAtIndex(arg1);
    int num_ret = olua_push_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PointArray_getControlPoints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PointArray *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PointArray");

    // const std::vector<cocos2d::Vec2> &getControlPoints()
    const std::vector<cocos2d::Vec2> &ret = self->getControlPoints();
    int num_ret = olua_push_array<cocos2d::Vec2>(L, ret, [L](cocos2d::Vec2 &arg1) {
        olua_pushcopy_object(L, arg1, "cc.Vec2");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PointArray_initWithCapacity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PointArray *self = nullptr;
    ssize_t arg1 = 0;       /** capacity */

    olua_to_object(L, 1, &self, "cc.PointArray");
    olua_check_integer(L, 2, &arg1);

    // bool initWithCapacity(ssize_t capacity)
    bool ret = self->initWithCapacity(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PointArray_insertControlPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PointArray *self = nullptr;
    cocos2d::Vec2 arg1;       /** controlPoint */
    ssize_t arg2 = 0;       /** index */

    olua_to_object(L, 1, &self, "cc.PointArray");
    olua_check_object(L, 2, &arg1, "cc.Vec2");
    olua_check_integer(L, 3, &arg2);

    // void insertControlPoint(const cocos2d::Vec2 &controlPoint, ssize_t index)
    self->insertControlPoint(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PointArray_removeControlPointAtIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PointArray *self = nullptr;
    ssize_t arg1 = 0;       /** index */

    olua_to_object(L, 1, &self, "cc.PointArray");
    olua_check_integer(L, 2, &arg1);

    // void removeControlPointAtIndex(ssize_t index)
    self->removeControlPointAtIndex(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PointArray_replaceControlPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PointArray *self = nullptr;
    cocos2d::Vec2 arg1;       /** controlPoint */
    ssize_t arg2 = 0;       /** index */

    olua_to_object(L, 1, &self, "cc.PointArray");
    olua_check_object(L, 2, &arg1, "cc.Vec2");
    olua_check_integer(L, 3, &arg2);

    // void replaceControlPoint(const cocos2d::Vec2 &controlPoint, ssize_t index)
    self->replaceControlPoint(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PointArray_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PointArray *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PointArray");

    // cocos2d::PointArray *reverse()
    cocos2d::PointArray *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.PointArray");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PointArray_reverseInline(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PointArray *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PointArray");

    // void reverseInline()
    self->reverseInline();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PointArray_setControlPoints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PointArray *self = nullptr;
    std::vector<cocos2d::Vec2> arg1;       /** controlPoints */

    olua_to_object(L, 1, &self, "cc.PointArray");
    olua_check_array<cocos2d::Vec2>(L, 2, arg1, [L](cocos2d::Vec2 *arg1) {
        olua_check_object(L, -1, arg1, "cc.Vec2");
    });

    // void setControlPoints(std::vector<cocos2d::Vec2> controlPoints)
    self->setControlPoints(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PointArray(lua_State *L)
{
    oluacls_class<cocos2d::PointArray, cocos2d::Ref>(L, "cc.PointArray");
    oluacls_func(L, "addControlPoint", _cocos2d_PointArray_addControlPoint);
    oluacls_func(L, "as", _cocos2d_PointArray_as);
    oluacls_func(L, "clone", _cocos2d_PointArray_clone);
    oluacls_func(L, "count", _cocos2d_PointArray_count);
    oluacls_func(L, "create", _cocos2d_PointArray_create);
    oluacls_func(L, "getControlPointAtIndex", _cocos2d_PointArray_getControlPointAtIndex);
    oluacls_func(L, "getControlPoints", _cocos2d_PointArray_getControlPoints);
    oluacls_func(L, "initWithCapacity", _cocos2d_PointArray_initWithCapacity);
    oluacls_func(L, "insertControlPoint", _cocos2d_PointArray_insertControlPoint);
    oluacls_func(L, "removeControlPointAtIndex", _cocos2d_PointArray_removeControlPointAtIndex);
    oluacls_func(L, "replaceControlPoint", _cocos2d_PointArray_replaceControlPoint);
    oluacls_func(L, "reverse", _cocos2d_PointArray_reverse);
    oluacls_func(L, "reverseInline", _cocos2d_PointArray_reverseInline);
    oluacls_func(L, "setControlPoints", _cocos2d_PointArray_setControlPoints);
    oluacls_prop(L, "controlPoints", _cocos2d_PointArray_getControlPoints, _cocos2d_PointArray_setControlPoints);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_CardinalSplineTo_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::CardinalSplineTo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.CardinalSplineTo");

    // cocos2d::CardinalSplineTo *clone()
    cocos2d::CardinalSplineTo *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.CardinalSplineTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CardinalSplineTo_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::PointArray *arg2 = nullptr;       /** points */
    float arg3 = 0;       /** tension */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.PointArray");
    olua_check_number(L, 3, &arg3);

    // static cocos2d::CardinalSplineTo *create(float duration, cocos2d::PointArray *points, float tension)
    cocos2d::CardinalSplineTo *ret = cocos2d::CardinalSplineTo::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.CardinalSplineTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CardinalSplineTo_getPoints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::CardinalSplineTo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.CardinalSplineTo");

    // cocos2d::PointArray *getPoints()
    cocos2d::PointArray *ret = self->getPoints();
    int num_ret = olua_push_object(L, ret, "cc.PointArray");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CardinalSplineTo_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::CardinalSplineTo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.CardinalSplineTo");

    // cocos2d::CardinalSplineTo *reverse()
    cocos2d::CardinalSplineTo *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.CardinalSplineTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CardinalSplineTo_setPoints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::CardinalSplineTo *self = nullptr;
    cocos2d::PointArray *arg1 = nullptr;       /** points */

    olua_to_object(L, 1, &self, "cc.CardinalSplineTo");
    olua_check_object(L, 2, &arg1, "cc.PointArray");

    // void setPoints(cocos2d::PointArray *points)
    self->setPoints(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_CardinalSplineTo_updatePosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::CardinalSplineTo *self = nullptr;
    cocos2d::Vec2 arg1;       /** newPos */

    olua_to_object(L, 1, &self, "cc.CardinalSplineTo");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void updatePosition(const cocos2d::Vec2 &newPos)
    self->updatePosition(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_CardinalSplineTo(lua_State *L)
{
    oluacls_class<cocos2d::CardinalSplineTo, cocos2d::ActionInterval>(L, "cc.CardinalSplineTo");
    oluacls_func(L, "clone", _cocos2d_CardinalSplineTo_clone);
    oluacls_func(L, "create", _cocos2d_CardinalSplineTo_create);
    oluacls_func(L, "getPoints", _cocos2d_CardinalSplineTo_getPoints);
    oluacls_func(L, "reverse", _cocos2d_CardinalSplineTo_reverse);
    oluacls_func(L, "setPoints", _cocos2d_CardinalSplineTo_setPoints);
    oluacls_func(L, "updatePosition", _cocos2d_CardinalSplineTo_updatePosition);
    oluacls_prop(L, "points", _cocos2d_CardinalSplineTo_getPoints, _cocos2d_CardinalSplineTo_setPoints);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_CardinalSplineBy_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::CardinalSplineBy *self = nullptr;

    olua_to_object(L, 1, &self, "cc.CardinalSplineBy");

    // cocos2d::CardinalSplineBy *clone()
    cocos2d::CardinalSplineBy *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.CardinalSplineBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CardinalSplineBy_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::PointArray *arg2 = nullptr;       /** points */
    float arg3 = 0;       /** tension */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.PointArray");
    olua_check_number(L, 3, &arg3);

    // static cocos2d::CardinalSplineBy *create(float duration, cocos2d::PointArray *points, float tension)
    cocos2d::CardinalSplineBy *ret = cocos2d::CardinalSplineBy::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.CardinalSplineBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CardinalSplineBy_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::CardinalSplineBy *self = nullptr;

    olua_to_object(L, 1, &self, "cc.CardinalSplineBy");

    // cocos2d::CardinalSplineBy *reverse()
    cocos2d::CardinalSplineBy *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.CardinalSplineBy");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_CardinalSplineBy(lua_State *L)
{
    oluacls_class<cocos2d::CardinalSplineBy, cocos2d::CardinalSplineTo>(L, "cc.CardinalSplineBy");
    oluacls_func(L, "clone", _cocos2d_CardinalSplineBy_clone);
    oluacls_func(L, "create", _cocos2d_CardinalSplineBy_create);
    oluacls_func(L, "reverse", _cocos2d_CardinalSplineBy_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_CatmullRomTo_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::CatmullRomTo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.CatmullRomTo");

    // cocos2d::CatmullRomTo *clone()
    cocos2d::CatmullRomTo *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.CatmullRomTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CatmullRomTo_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** dt */
    cocos2d::PointArray *arg2 = nullptr;       /** points */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.PointArray");

    // static cocos2d::CatmullRomTo *create(float dt, cocos2d::PointArray *points)
    cocos2d::CatmullRomTo *ret = cocos2d::CatmullRomTo::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.CatmullRomTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CatmullRomTo_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::CatmullRomTo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.CatmullRomTo");

    // cocos2d::CatmullRomTo *reverse()
    cocos2d::CatmullRomTo *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.CatmullRomTo");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_CatmullRomTo(lua_State *L)
{
    oluacls_class<cocos2d::CatmullRomTo, cocos2d::CardinalSplineTo>(L, "cc.CatmullRomTo");
    oluacls_func(L, "clone", _cocos2d_CatmullRomTo_clone);
    oluacls_func(L, "create", _cocos2d_CatmullRomTo_create);
    oluacls_func(L, "reverse", _cocos2d_CatmullRomTo_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_CatmullRomBy_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::CatmullRomBy *self = nullptr;

    olua_to_object(L, 1, &self, "cc.CatmullRomBy");

    // cocos2d::CatmullRomBy *clone()
    cocos2d::CatmullRomBy *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.CatmullRomBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CatmullRomBy_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** dt */
    cocos2d::PointArray *arg2 = nullptr;       /** points */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.PointArray");

    // static cocos2d::CatmullRomBy *create(float dt, cocos2d::PointArray *points)
    cocos2d::CatmullRomBy *ret = cocos2d::CatmullRomBy::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.CatmullRomBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CatmullRomBy_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::CatmullRomBy *self = nullptr;

    olua_to_object(L, 1, &self, "cc.CatmullRomBy");

    // cocos2d::CatmullRomBy *reverse()
    cocos2d::CatmullRomBy *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.CatmullRomBy");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_CatmullRomBy(lua_State *L)
{
    oluacls_class<cocos2d::CatmullRomBy, cocos2d::CardinalSplineBy>(L, "cc.CatmullRomBy");
    oluacls_func(L, "clone", _cocos2d_CatmullRomBy_clone);
    oluacls_func(L, "create", _cocos2d_CatmullRomBy_create);
    oluacls_func(L, "reverse", _cocos2d_CatmullRomBy_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_ActionInstant_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInstant *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ActionInstant");

    // cocos2d::ActionInstant *clone()
    cocos2d::ActionInstant *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.ActionInstant");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ActionInstant_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInstant *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ActionInstant");

    // cocos2d::ActionInstant *reverse()
    cocos2d::ActionInstant *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionInstant");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_ActionInstant(lua_State *L)
{
    oluacls_class<cocos2d::ActionInstant, cocos2d::FiniteTimeAction>(L, "cc.ActionInstant");
    oluacls_func(L, "clone", _cocos2d_ActionInstant_clone);
    oluacls_func(L, "reverse", _cocos2d_ActionInstant_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_Show_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Show *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Show");

    // cocos2d::Show *clone()
    cocos2d::Show *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.Show");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Show_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Show *create()
    cocos2d::Show *ret = cocos2d::Show::create();
    int num_ret = olua_push_object(L, ret, "cc.Show");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_Show(lua_State *L)
{
    oluacls_class<cocos2d::Show, cocos2d::ActionInstant>(L, "cc.Show");
    oluacls_func(L, "clone", _cocos2d_Show_clone);
    oluacls_func(L, "create", _cocos2d_Show_create);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_Hide_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Hide *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Hide");

    // cocos2d::Hide *clone()
    cocos2d::Hide *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.Hide");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Hide_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Hide *create()
    cocos2d::Hide *ret = cocos2d::Hide::create();
    int num_ret = olua_push_object(L, ret, "cc.Hide");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_Hide(lua_State *L)
{
    oluacls_class<cocos2d::Hide, cocos2d::ActionInstant>(L, "cc.Hide");
    oluacls_func(L, "clone", _cocos2d_Hide_clone);
    oluacls_func(L, "create", _cocos2d_Hide_create);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_ToggleVisibility_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ToggleVisibility *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ToggleVisibility");

    // cocos2d::ToggleVisibility *clone()
    cocos2d::ToggleVisibility *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.ToggleVisibility");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ToggleVisibility_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ToggleVisibility *create()
    cocos2d::ToggleVisibility *ret = cocos2d::ToggleVisibility::create();
    int num_ret = olua_push_object(L, ret, "cc.ToggleVisibility");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ToggleVisibility_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ToggleVisibility *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ToggleVisibility");

    // cocos2d::ToggleVisibility *reverse()
    cocos2d::ToggleVisibility *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ToggleVisibility");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_ToggleVisibility(lua_State *L)
{
    oluacls_class<cocos2d::ToggleVisibility, cocos2d::ActionInstant>(L, "cc.ToggleVisibility");
    oluacls_func(L, "clone", _cocos2d_ToggleVisibility_clone);
    oluacls_func(L, "create", _cocos2d_ToggleVisibility_create);
    oluacls_func(L, "reverse", _cocos2d_ToggleVisibility_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_RemoveSelf_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::RemoveSelf *self = nullptr;

    olua_to_object(L, 1, &self, "cc.RemoveSelf");

    // cocos2d::RemoveSelf *clone()
    cocos2d::RemoveSelf *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.RemoveSelf");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_RemoveSelf_create$1(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** isNeedCleanUp */

    olua_check_bool(L, 1, &arg1);

    // static cocos2d::RemoveSelf *create(@optional bool isNeedCleanUp)
    cocos2d::RemoveSelf *ret = cocos2d::RemoveSelf::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.RemoveSelf");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_RemoveSelf_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::RemoveSelf *create(@optional bool isNeedCleanUp)
    cocos2d::RemoveSelf *ret = cocos2d::RemoveSelf::create();
    int num_ret = olua_push_object(L, ret, "cc.RemoveSelf");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_RemoveSelf_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::RemoveSelf *create(@optional bool isNeedCleanUp)
        return _cocos2d_RemoveSelf_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_bool(L, 1))) {
            // static cocos2d::RemoveSelf *create(@optional bool isNeedCleanUp)
            return _cocos2d_RemoveSelf_create$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::RemoveSelf::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_RemoveSelf_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::RemoveSelf *self = nullptr;

    olua_to_object(L, 1, &self, "cc.RemoveSelf");

    // cocos2d::RemoveSelf *reverse()
    cocos2d::RemoveSelf *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.RemoveSelf");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_RemoveSelf(lua_State *L)
{
    oluacls_class<cocos2d::RemoveSelf, cocos2d::ActionInstant>(L, "cc.RemoveSelf");
    oluacls_func(L, "clone", _cocos2d_RemoveSelf_clone);
    oluacls_func(L, "create", _cocos2d_RemoveSelf_create);
    oluacls_func(L, "reverse", _cocos2d_RemoveSelf_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_FlipX_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FlipX *self = nullptr;

    olua_to_object(L, 1, &self, "cc.FlipX");

    // cocos2d::FlipX *clone()
    cocos2d::FlipX *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.FlipX");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_FlipX_create(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** x */

    olua_check_bool(L, 1, &arg1);

    // static cocos2d::FlipX *create(bool x)
    cocos2d::FlipX *ret = cocos2d::FlipX::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.FlipX");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_FlipX_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FlipX *self = nullptr;

    olua_to_object(L, 1, &self, "cc.FlipX");

    // cocos2d::FlipX *reverse()
    cocos2d::FlipX *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.FlipX");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_FlipX(lua_State *L)
{
    oluacls_class<cocos2d::FlipX, cocos2d::ActionInstant>(L, "cc.FlipX");
    oluacls_func(L, "clone", _cocos2d_FlipX_clone);
    oluacls_func(L, "create", _cocos2d_FlipX_create);
    oluacls_func(L, "reverse", _cocos2d_FlipX_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_FlipY_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FlipY *self = nullptr;

    olua_to_object(L, 1, &self, "cc.FlipY");

    // cocos2d::FlipY *clone()
    cocos2d::FlipY *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.FlipY");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_FlipY_create(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** y */

    olua_check_bool(L, 1, &arg1);

    // static cocos2d::FlipY *create(bool y)
    cocos2d::FlipY *ret = cocos2d::FlipY::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.FlipY");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_FlipY_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FlipY *self = nullptr;

    olua_to_object(L, 1, &self, "cc.FlipY");

    // cocos2d::FlipY *reverse()
    cocos2d::FlipY *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.FlipY");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_FlipY(lua_State *L)
{
    oluacls_class<cocos2d::FlipY, cocos2d::ActionInstant>(L, "cc.FlipY");
    oluacls_func(L, "clone", _cocos2d_FlipY_clone);
    oluacls_func(L, "create", _cocos2d_FlipY_create);
    oluacls_func(L, "reverse", _cocos2d_FlipY_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_Place_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Place *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Place");

    // cocos2d::Place *clone()
    cocos2d::Place *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.Place");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Place_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 arg1;       /** pos */

    olua_check_object(L, 1, &arg1, "cc.Vec2");

    // static cocos2d::Place *create(const cocos2d::Vec2 &pos)
    cocos2d::Place *ret = cocos2d::Place::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.Place");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Place_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Place *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Place");

    // cocos2d::Place *reverse()
    cocos2d::Place *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.Place");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_Place(lua_State *L)
{
    oluacls_class<cocos2d::Place, cocos2d::ActionInstant>(L, "cc.Place");
    oluacls_func(L, "clone", _cocos2d_Place_clone);
    oluacls_func(L, "create", _cocos2d_Place_create);
    oluacls_func(L, "reverse", _cocos2d_Place_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_CallFunc_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::CallFunc *self = nullptr;

    olua_to_object(L, 1, &self, "cc.CallFunc");

    // cocos2d::CallFunc *clone()
    cocos2d::CallFunc *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.CallFunc");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CallFunc_create(lua_State *L)
{
    olua_startinvoke(L);

    std::function<void ()> arg1;       /** func */

    olua_check_callback(L, 1, &arg1, "std.function");

    void *cb_store = (void *)olua_newobjstub(L, "cc.CallFunc");
    std::string cb_tag = "CallFunc";
    std::string cb_name = olua_setcallback(L, cb_store,  1, cb_tag.c_str(), OLUA_TAG_NEW);
    olua_Context cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx]() {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);

            olua_callback(L, cb_store, cb_name.c_str(), 0);

            lua_settop(L, top);
        }
    };

    // static cocos2d::CallFunc *create(@localvar const std::function<void ()> &func)
    cocos2d::CallFunc *ret = cocos2d::CallFunc::create(arg1);
    if (olua_pushobjstub(L, ret, cb_store, "cc.CallFunc") == OLUA_OBJ_EXIST) {
        lua_pushstring(L, cb_name.c_str());
        lua_pushvalue(L, 1);
        olua_setvariable(L, -3);
    } else {
        olua_postpush(L, ret, OLUA_OBJ_NEW);
    };

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_CallFunc_execute(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::CallFunc *self = nullptr;

    olua_to_object(L, 1, &self, "cc.CallFunc");

    // void execute()
    self->execute();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_CallFunc_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::CallFunc *self = nullptr;

    olua_to_object(L, 1, &self, "cc.CallFunc");

    // cocos2d::CallFunc *reverse()
    cocos2d::CallFunc *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.CallFunc");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_CallFunc(lua_State *L)
{
    oluacls_class<cocos2d::CallFunc, cocos2d::ActionInstant>(L, "cc.CallFunc");
    oluacls_func(L, "clone", _cocos2d_CallFunc_clone);
    oluacls_func(L, "create", _cocos2d_CallFunc_create);
    oluacls_func(L, "execute", _cocos2d_CallFunc_execute);
    oluacls_func(L, "reverse", _cocos2d_CallFunc_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_ActionCamera_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionCamera *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ActionCamera");

    // cocos2d::ActionCamera *clone()
    cocos2d::ActionCamera *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.ActionCamera");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ActionCamera_getCenter(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionCamera *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ActionCamera");

    // const cocos2d::Vec3 &getCenter()
    const cocos2d::Vec3 &ret = self->getCenter();
    int num_ret = olua_push_object(L, ret, "cc.Vec3");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ActionCamera_getEye(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionCamera *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ActionCamera");

    // const cocos2d::Vec3 &getEye()
    const cocos2d::Vec3 &ret = self->getEye();
    int num_ret = olua_push_object(L, ret, "cc.Vec3");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ActionCamera_getUp(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionCamera *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ActionCamera");

    // const cocos2d::Vec3 &getUp()
    const cocos2d::Vec3 &ret = self->getUp();
    int num_ret = olua_push_object(L, ret, "cc.Vec3");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ActionCamera_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionCamera *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ActionCamera");

    // cocos2d::ActionCamera *reverse()
    cocos2d::ActionCamera *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ActionCamera");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ActionCamera_setCenter(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionCamera *self = nullptr;
    cocos2d::Vec3 arg1;       /** center */

    olua_to_object(L, 1, &self, "cc.ActionCamera");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // void setCenter(const cocos2d::Vec3 &center)
    self->setCenter(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ActionCamera_setEye$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionCamera *self = nullptr;
    cocos2d::Vec3 arg1;       /** eye */

    olua_to_object(L, 1, &self, "cc.ActionCamera");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // void setEye(const cocos2d::Vec3 &eye)
    self->setEye(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ActionCamera_setEye$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionCamera *self = nullptr;
    float arg1 = 0;       /** x */
    float arg2 = 0;       /** y */
    float arg3 = 0;       /** z */

    olua_to_object(L, 1, &self, "cc.ActionCamera");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // void setEye(float x, float y, float z)
    self->setEye(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ActionCamera_setEye(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_object(L, 2, "cc.Vec3"))) {
            // void setEye(const cocos2d::Vec3 &eye)
            return _cocos2d_ActionCamera_setEye$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4))) {
            // void setEye(float x, float y, float z)
            return _cocos2d_ActionCamera_setEye$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ActionCamera::setEye' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_ActionCamera_setUp(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionCamera *self = nullptr;
    cocos2d::Vec3 arg1;       /** up */

    olua_to_object(L, 1, &self, "cc.ActionCamera");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // void setUp(const cocos2d::Vec3 &up)
    self->setUp(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_ActionCamera(lua_State *L)
{
    oluacls_class<cocos2d::ActionCamera, cocos2d::ActionInterval>(L, "cc.ActionCamera");
    oluacls_func(L, "clone", _cocos2d_ActionCamera_clone);
    oluacls_func(L, "getCenter", _cocos2d_ActionCamera_getCenter);
    oluacls_func(L, "getEye", _cocos2d_ActionCamera_getEye);
    oluacls_func(L, "getUp", _cocos2d_ActionCamera_getUp);
    oluacls_func(L, "reverse", _cocos2d_ActionCamera_reverse);
    oluacls_func(L, "setCenter", _cocos2d_ActionCamera_setCenter);
    oluacls_func(L, "setEye", _cocos2d_ActionCamera_setEye);
    oluacls_func(L, "setUp", _cocos2d_ActionCamera_setUp);
    oluacls_prop(L, "center", _cocos2d_ActionCamera_getCenter, _cocos2d_ActionCamera_setCenter);
    oluacls_prop(L, "eye", _cocos2d_ActionCamera_getEye, _cocos2d_ActionCamera_setEye);
    oluacls_prop(L, "up", _cocos2d_ActionCamera_getUp, _cocos2d_ActionCamera_setUp);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_OrbitCamera_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::OrbitCamera *self = nullptr;

    olua_to_object(L, 1, &self, "cc.OrbitCamera");

    // cocos2d::OrbitCamera *clone()
    cocos2d::OrbitCamera *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.OrbitCamera");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_OrbitCamera_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** t */
    float arg2 = 0;       /** radius */
    float arg3 = 0;       /** deltaRadius */
    float arg4 = 0;       /** angleZ */
    float arg5 = 0;       /** deltaAngleZ */
    float arg6 = 0;       /** angleX */
    float arg7 = 0;       /** deltaAngleX */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);
    olua_check_number(L, 5, &arg5);
    olua_check_number(L, 6, &arg6);
    olua_check_number(L, 7, &arg7);

    // static cocos2d::OrbitCamera *create(float t, float radius, float deltaRadius, float angleZ, float deltaAngleZ, float angleX, float deltaAngleX)
    cocos2d::OrbitCamera *ret = cocos2d::OrbitCamera::create(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    int num_ret = olua_push_object(L, ret, "cc.OrbitCamera");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_OrbitCamera_sphericalRadius(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::OrbitCamera *self = nullptr;
    float *arg1 = nullptr;       /** r */
    float *arg2 = nullptr;       /** zenith */
    float *arg3 = nullptr;       /** azimuth */

    olua_to_object(L, 1, &self, "cc.OrbitCamera");
    olua_check_pointer(L, 2, &arg1, "olua.float");
    olua_check_pointer(L, 3, &arg2, "olua.float");
    olua_check_pointer(L, 4, &arg3, "olua.float");

    // void sphericalRadius(float *r, float *zenith, float *azimuth)
    self->sphericalRadius(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_OrbitCamera(lua_State *L)
{
    oluacls_class<cocos2d::OrbitCamera, cocos2d::ActionCamera>(L, "cc.OrbitCamera");
    oluacls_func(L, "clone", _cocos2d_OrbitCamera_clone);
    oluacls_func(L, "create", _cocos2d_OrbitCamera_create);
    oluacls_func(L, "sphericalRadius", _cocos2d_OrbitCamera_sphericalRadius);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_GridBase_afterBlit(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;

    olua_to_object(L, 1, &self, "cc.GridBase");

    // void afterBlit()
    self->afterBlit();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_GridBase_afterDraw(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** target */

    olua_to_object(L, 1, &self, "cc.GridBase");
    olua_check_object(L, 2, &arg1, "cc.Node");

    // void afterDraw(cocos2d::Node *target)
    self->afterDraw(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_GridBase_beforeBlit(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;

    olua_to_object(L, 1, &self, "cc.GridBase");

    // void beforeBlit()
    self->beforeBlit();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_GridBase_beforeDraw(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;

    olua_to_object(L, 1, &self, "cc.GridBase");

    // void beforeDraw()
    self->beforeDraw();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_GridBase_blit(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;

    olua_to_object(L, 1, &self, "cc.GridBase");

    // void blit()
    self->blit();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_GridBase_calculateVertexPoints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;

    olua_to_object(L, 1, &self, "cc.GridBase");

    // void calculateVertexPoints()
    self->calculateVertexPoints();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_GridBase_getGridRect(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;

    olua_to_object(L, 1, &self, "cc.GridBase");

    // const cocos2d::Rect &getGridRect()
    const cocos2d::Rect &ret = self->getGridRect();
    int num_ret = olua_push_object(L, ret, "cc.Rect");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_GridBase_getGridSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;

    olua_to_object(L, 1, &self, "cc.GridBase");

    // const cocos2d::Size &getGridSize()
    const cocos2d::Size &ret = self->getGridSize();
    int num_ret = olua_push_object(L, ret, "cc.Size");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_GridBase_getReuseGrid(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;

    olua_to_object(L, 1, &self, "cc.GridBase");

    // int getReuseGrid()
    int ret = self->getReuseGrid();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_GridBase_getStep(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;

    olua_to_object(L, 1, &self, "cc.GridBase");

    // const cocos2d::Vec2 &getStep()
    const cocos2d::Vec2 &ret = self->getStep();
    int num_ret = olua_push_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_GridBase_initWithSize$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;
    cocos2d::Size arg1;       /** gridSize */

    olua_to_object(L, 1, &self, "cc.GridBase");
    olua_check_object(L, 2, &arg1, "cc.Size");

    // bool initWithSize(const cocos2d::Size &gridSize)
    bool ret = self->initWithSize(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_GridBase_initWithSize$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;
    cocos2d::Size arg1;       /** gridSize */
    cocos2d::Rect arg2;       /** rect */

    olua_to_object(L, 1, &self, "cc.GridBase");
    olua_check_object(L, 2, &arg1, "cc.Size");
    olua_check_object(L, 3, &arg2, "cc.Rect");

    // bool initWithSize(const cocos2d::Size &gridSize, const cocos2d::Rect &rect)
    bool ret = self->initWithSize(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_GridBase_initWithSize$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;
    cocos2d::Size arg1;       /** gridSize */
    cocos2d::Texture2D *arg2 = nullptr;       /** texture */
    bool arg3 = false;       /** flipped */

    olua_to_object(L, 1, &self, "cc.GridBase");
    olua_check_object(L, 2, &arg1, "cc.Size");
    olua_check_object(L, 3, &arg2, "cc.Texture2D");
    olua_check_bool(L, 4, &arg3);

    // bool initWithSize(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped)
    bool ret = self->initWithSize(arg1, arg2, arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_GridBase_initWithSize$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;
    cocos2d::Size arg1;       /** gridSize */
    cocos2d::Texture2D *arg2 = nullptr;       /** texture */
    bool arg3 = false;       /** flipped */
    cocos2d::Rect arg4;       /** rect */

    olua_to_object(L, 1, &self, "cc.GridBase");
    olua_check_object(L, 2, &arg1, "cc.Size");
    olua_check_object(L, 3, &arg2, "cc.Texture2D");
    olua_check_bool(L, 4, &arg3);
    olua_check_object(L, 5, &arg4, "cc.Rect");

    // bool initWithSize(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped, const cocos2d::Rect &rect)
    bool ret = self->initWithSize(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_GridBase_initWithSize(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_object(L, 2, "cc.Size"))) {
            // bool initWithSize(const cocos2d::Size &gridSize)
            return _cocos2d_GridBase_initWithSize$1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 2, "cc.Size")) && (olua_is_object(L, 3, "cc.Rect"))) {
            // bool initWithSize(const cocos2d::Size &gridSize, const cocos2d::Rect &rect)
            return _cocos2d_GridBase_initWithSize$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 2, "cc.Size")) && (olua_is_object(L, 3, "cc.Texture2D")) && (olua_is_bool(L, 4))) {
            // bool initWithSize(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped)
            return _cocos2d_GridBase_initWithSize$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 2, "cc.Size")) && (olua_is_object(L, 3, "cc.Texture2D")) && (olua_is_bool(L, 4)) && (olua_is_object(L, 5, "cc.Rect"))) {
            // bool initWithSize(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped, const cocos2d::Rect &rect)
            return _cocos2d_GridBase_initWithSize$4(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::GridBase::initWithSize' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_GridBase_isActive(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;

    olua_to_object(L, 1, &self, "cc.GridBase");

    // bool isActive()
    bool ret = self->isActive();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_GridBase_isTextureFlipped(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;

    olua_to_object(L, 1, &self, "cc.GridBase");

    // bool isTextureFlipped()
    bool ret = self->isTextureFlipped();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_GridBase_reuse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;

    olua_to_object(L, 1, &self, "cc.GridBase");

    // void reuse()
    self->reuse();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_GridBase_set2DProjection(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;

    olua_to_object(L, 1, &self, "cc.GridBase");

    // void set2DProjection()
    self->set2DProjection();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_GridBase_setActive(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;
    bool arg1 = false;       /** active */

    olua_to_object(L, 1, &self, "cc.GridBase");
    olua_check_bool(L, 2, &arg1);

    // void setActive(bool active)
    self->setActive(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_GridBase_setGridRect(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;
    cocos2d::Rect arg1;       /** rect */

    olua_to_object(L, 1, &self, "cc.GridBase");
    olua_check_object(L, 2, &arg1, "cc.Rect");

    // void setGridRect(const cocos2d::Rect &rect)
    self->setGridRect(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_GridBase_setGridSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;
    cocos2d::Size arg1;       /** gridSize */

    olua_to_object(L, 1, &self, "cc.GridBase");
    olua_check_object(L, 2, &arg1, "cc.Size");

    // void setGridSize(const cocos2d::Size &gridSize)
    self->setGridSize(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_GridBase_setReuseGrid(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;
    int arg1 = 0;       /** reuseGrid */

    olua_to_object(L, 1, &self, "cc.GridBase");
    olua_check_integer(L, 2, &arg1);

    // void setReuseGrid(int reuseGrid)
    self->setReuseGrid(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_GridBase_setStep(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;
    cocos2d::Vec2 arg1;       /** step */

    olua_to_object(L, 1, &self, "cc.GridBase");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void setStep(const cocos2d::Vec2 &step)
    self->setStep(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_GridBase_setTextureFlipped(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;
    bool arg1 = false;       /** flipped */

    olua_to_object(L, 1, &self, "cc.GridBase");
    olua_check_bool(L, 2, &arg1);

    // void setTextureFlipped(bool flipped)
    self->setTextureFlipped(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_GridBase(lua_State *L)
{
    oluacls_class<cocos2d::GridBase, cocos2d::Ref>(L, "cc.GridBase");
    oluacls_func(L, "afterBlit", _cocos2d_GridBase_afterBlit);
    oluacls_func(L, "afterDraw", _cocos2d_GridBase_afterDraw);
    oluacls_func(L, "beforeBlit", _cocos2d_GridBase_beforeBlit);
    oluacls_func(L, "beforeDraw", _cocos2d_GridBase_beforeDraw);
    oluacls_func(L, "blit", _cocos2d_GridBase_blit);
    oluacls_func(L, "calculateVertexPoints", _cocos2d_GridBase_calculateVertexPoints);
    oluacls_func(L, "getGridRect", _cocos2d_GridBase_getGridRect);
    oluacls_func(L, "getGridSize", _cocos2d_GridBase_getGridSize);
    oluacls_func(L, "getReuseGrid", _cocos2d_GridBase_getReuseGrid);
    oluacls_func(L, "getStep", _cocos2d_GridBase_getStep);
    oluacls_func(L, "initWithSize", _cocos2d_GridBase_initWithSize);
    oluacls_func(L, "isActive", _cocos2d_GridBase_isActive);
    oluacls_func(L, "isTextureFlipped", _cocos2d_GridBase_isTextureFlipped);
    oluacls_func(L, "reuse", _cocos2d_GridBase_reuse);
    oluacls_func(L, "set2DProjection", _cocos2d_GridBase_set2DProjection);
    oluacls_func(L, "setActive", _cocos2d_GridBase_setActive);
    oluacls_func(L, "setGridRect", _cocos2d_GridBase_setGridRect);
    oluacls_func(L, "setGridSize", _cocos2d_GridBase_setGridSize);
    oluacls_func(L, "setReuseGrid", _cocos2d_GridBase_setReuseGrid);
    oluacls_func(L, "setStep", _cocos2d_GridBase_setStep);
    oluacls_func(L, "setTextureFlipped", _cocos2d_GridBase_setTextureFlipped);
    oluacls_prop(L, "active", _cocos2d_GridBase_isActive, _cocos2d_GridBase_setActive);
    oluacls_prop(L, "gridRect", _cocos2d_GridBase_getGridRect, _cocos2d_GridBase_setGridRect);
    oluacls_prop(L, "gridSize", _cocos2d_GridBase_getGridSize, _cocos2d_GridBase_setGridSize);
    oluacls_prop(L, "reuseGrid", _cocos2d_GridBase_getReuseGrid, _cocos2d_GridBase_setReuseGrid);
    oluacls_prop(L, "step", _cocos2d_GridBase_getStep, _cocos2d_GridBase_setStep);
    oluacls_prop(L, "textureFlipped", _cocos2d_GridBase_isTextureFlipped, _cocos2d_GridBase_setTextureFlipped);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_Grid3D_create$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** gridSize */

    olua_check_object(L, 1, &arg1, "cc.Size");

    // static cocos2d::Grid3D *create(const cocos2d::Size &gridSize)
    cocos2d::Grid3D *ret = cocos2d::Grid3D::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.Grid3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Grid3D_create$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** gridSize */
    cocos2d::Rect arg2;       /** rect */

    olua_check_object(L, 1, &arg1, "cc.Size");
    olua_check_object(L, 2, &arg2, "cc.Rect");

    // static cocos2d::Grid3D *create(const cocos2d::Size &gridSize, const cocos2d::Rect &rect)
    cocos2d::Grid3D *ret = cocos2d::Grid3D::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.Grid3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Grid3D_create$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** gridSize */
    cocos2d::Texture2D *arg2 = nullptr;       /** texture */
    bool arg3 = false;       /** flipped */

    olua_check_object(L, 1, &arg1, "cc.Size");
    olua_check_object(L, 2, &arg2, "cc.Texture2D");
    olua_check_bool(L, 3, &arg3);

    // static cocos2d::Grid3D *create(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped)
    cocos2d::Grid3D *ret = cocos2d::Grid3D::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.Grid3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Grid3D_create$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** gridSize */
    cocos2d::Texture2D *arg2 = nullptr;       /** texture */
    bool arg3 = false;       /** flipped */
    cocos2d::Rect arg4;       /** rect */

    olua_check_object(L, 1, &arg1, "cc.Size");
    olua_check_object(L, 2, &arg2, "cc.Texture2D");
    olua_check_bool(L, 3, &arg3);
    olua_check_object(L, 4, &arg4, "cc.Rect");

    // static cocos2d::Grid3D *create(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped, const cocos2d::Rect &rect)
    cocos2d::Grid3D *ret = cocos2d::Grid3D::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.Grid3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Grid3D_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_object(L, 1, "cc.Size"))) {
            // static cocos2d::Grid3D *create(const cocos2d::Size &gridSize)
            return _cocos2d_Grid3D_create$1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Size")) && (olua_is_object(L, 2, "cc.Rect"))) {
            // static cocos2d::Grid3D *create(const cocos2d::Size &gridSize, const cocos2d::Rect &rect)
            return _cocos2d_Grid3D_create$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Size")) && (olua_is_object(L, 2, "cc.Texture2D")) && (olua_is_bool(L, 3))) {
            // static cocos2d::Grid3D *create(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped)
            return _cocos2d_Grid3D_create$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.Size")) && (olua_is_object(L, 2, "cc.Texture2D")) && (olua_is_bool(L, 3)) && (olua_is_object(L, 4, "cc.Rect"))) {
            // static cocos2d::Grid3D *create(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped, const cocos2d::Rect &rect)
            return _cocos2d_Grid3D_create$4(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Grid3D::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_Grid3D_getNeedDepthTestForBlit(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Grid3D *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Grid3D");

    // bool getNeedDepthTestForBlit()
    bool ret = self->getNeedDepthTestForBlit();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Grid3D_getOriginalVertex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Grid3D *self = nullptr;
    cocos2d::Vec2 arg1;       /** pos */

    olua_to_object(L, 1, &self, "cc.Grid3D");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // cocos2d::Vec3 getOriginalVertex(const cocos2d::Vec2 &pos)
    cocos2d::Vec3 ret = self->getOriginalVertex(arg1);
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec3");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Grid3D_getVertex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Grid3D *self = nullptr;
    cocos2d::Vec2 arg1;       /** pos */

    olua_to_object(L, 1, &self, "cc.Grid3D");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // cocos2d::Vec3 getVertex(const cocos2d::Vec2 &pos)
    cocos2d::Vec3 ret = self->getVertex(arg1);
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec3");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Grid3D_setNeedDepthTestForBlit(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Grid3D *self = nullptr;
    bool arg1 = false;       /** neededDepthTest */

    olua_to_object(L, 1, &self, "cc.Grid3D");
    olua_check_bool(L, 2, &arg1);

    // void setNeedDepthTestForBlit(bool neededDepthTest)
    self->setNeedDepthTestForBlit(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_Grid3D_setVertex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Grid3D *self = nullptr;
    cocos2d::Vec2 arg1;       /** pos */
    cocos2d::Vec3 arg2;       /** vertex */

    olua_to_object(L, 1, &self, "cc.Grid3D");
    olua_check_object(L, 2, &arg1, "cc.Vec2");
    olua_check_object(L, 3, &arg2, "cc.Vec3");

    // void setVertex(const cocos2d::Vec2 &pos, const cocos2d::Vec3 &vertex)
    self->setVertex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_Grid3D(lua_State *L)
{
    oluacls_class<cocos2d::Grid3D, cocos2d::GridBase>(L, "cc.Grid3D");
    oluacls_func(L, "create", _cocos2d_Grid3D_create);
    oluacls_func(L, "getNeedDepthTestForBlit", _cocos2d_Grid3D_getNeedDepthTestForBlit);
    oluacls_func(L, "getOriginalVertex", _cocos2d_Grid3D_getOriginalVertex);
    oluacls_func(L, "getVertex", _cocos2d_Grid3D_getVertex);
    oluacls_func(L, "setNeedDepthTestForBlit", _cocos2d_Grid3D_setNeedDepthTestForBlit);
    oluacls_func(L, "setVertex", _cocos2d_Grid3D_setVertex);
    oluacls_prop(L, "needDepthTestForBlit", _cocos2d_Grid3D_getNeedDepthTestForBlit, _cocos2d_Grid3D_setNeedDepthTestForBlit);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_TiledGrid3D_create$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** gridSize */

    olua_check_object(L, 1, &arg1, "cc.Size");

    // static cocos2d::TiledGrid3D *create(const cocos2d::Size &gridSize)
    cocos2d::TiledGrid3D *ret = cocos2d::TiledGrid3D::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.TiledGrid3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TiledGrid3D_create$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** gridSize */
    cocos2d::Rect arg2;       /** rect */

    olua_check_object(L, 1, &arg1, "cc.Size");
    olua_check_object(L, 2, &arg2, "cc.Rect");

    // static cocos2d::TiledGrid3D *create(const cocos2d::Size &gridSize, const cocos2d::Rect &rect)
    cocos2d::TiledGrid3D *ret = cocos2d::TiledGrid3D::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.TiledGrid3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TiledGrid3D_create$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** gridSize */
    cocos2d::Texture2D *arg2 = nullptr;       /** texture */
    bool arg3 = false;       /** flipped */

    olua_check_object(L, 1, &arg1, "cc.Size");
    olua_check_object(L, 2, &arg2, "cc.Texture2D");
    olua_check_bool(L, 3, &arg3);

    // static cocos2d::TiledGrid3D *create(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped)
    cocos2d::TiledGrid3D *ret = cocos2d::TiledGrid3D::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.TiledGrid3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TiledGrid3D_create$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** gridSize */
    cocos2d::Texture2D *arg2 = nullptr;       /** texture */
    bool arg3 = false;       /** flipped */
    cocos2d::Rect arg4;       /** rect */

    olua_check_object(L, 1, &arg1, "cc.Size");
    olua_check_object(L, 2, &arg2, "cc.Texture2D");
    olua_check_bool(L, 3, &arg3);
    olua_check_object(L, 4, &arg4, "cc.Rect");

    // static cocos2d::TiledGrid3D *create(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped, const cocos2d::Rect &rect)
    cocos2d::TiledGrid3D *ret = cocos2d::TiledGrid3D::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.TiledGrid3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TiledGrid3D_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_object(L, 1, "cc.Size"))) {
            // static cocos2d::TiledGrid3D *create(const cocos2d::Size &gridSize)
            return _cocos2d_TiledGrid3D_create$1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Size")) && (olua_is_object(L, 2, "cc.Rect"))) {
            // static cocos2d::TiledGrid3D *create(const cocos2d::Size &gridSize, const cocos2d::Rect &rect)
            return _cocos2d_TiledGrid3D_create$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Size")) && (olua_is_object(L, 2, "cc.Texture2D")) && (olua_is_bool(L, 3))) {
            // static cocos2d::TiledGrid3D *create(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped)
            return _cocos2d_TiledGrid3D_create$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.Size")) && (olua_is_object(L, 2, "cc.Texture2D")) && (olua_is_bool(L, 3)) && (olua_is_object(L, 4, "cc.Rect"))) {
            // static cocos2d::TiledGrid3D *create(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped, const cocos2d::Rect &rect)
            return _cocos2d_TiledGrid3D_create$4(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::TiledGrid3D::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_TiledGrid3D_getOriginalTile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TiledGrid3D *self = nullptr;
    cocos2d::Vec2 arg1;       /** pos */

    olua_to_object(L, 1, &self, "cc.TiledGrid3D");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // cocos2d::Quad3 getOriginalTile(const cocos2d::Vec2 &pos)
    cocos2d::Quad3 ret = self->getOriginalTile(arg1);
    int num_ret = olua_pushcopy_object(L, ret, "cc.Quad3");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TiledGrid3D_getTile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TiledGrid3D *self = nullptr;
    cocos2d::Vec2 arg1;       /** pos */

    olua_to_object(L, 1, &self, "cc.TiledGrid3D");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // cocos2d::Quad3 getTile(const cocos2d::Vec2 &pos)
    cocos2d::Quad3 ret = self->getTile(arg1);
    int num_ret = olua_pushcopy_object(L, ret, "cc.Quad3");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TiledGrid3D_setTile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TiledGrid3D *self = nullptr;
    cocos2d::Vec2 arg1;       /** pos */
    cocos2d::Quad3 arg2;       /** coords */

    olua_to_object(L, 1, &self, "cc.TiledGrid3D");
    olua_check_object(L, 2, &arg1, "cc.Vec2");
    olua_check_object(L, 3, &arg2, "cc.Quad3");

    // void setTile(const cocos2d::Vec2 &pos, const cocos2d::Quad3 &coords)
    self->setTile(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_TiledGrid3D(lua_State *L)
{
    oluacls_class<cocos2d::TiledGrid3D, cocos2d::GridBase>(L, "cc.TiledGrid3D");
    oluacls_func(L, "create", _cocos2d_TiledGrid3D_create);
    oluacls_func(L, "getOriginalTile", _cocos2d_TiledGrid3D_getOriginalTile);
    oluacls_func(L, "getTile", _cocos2d_TiledGrid3D_getTile);
    oluacls_func(L, "setTile", _cocos2d_TiledGrid3D_setTile);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_NodeGrid_create$1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::NodeGrid *create()
    cocos2d::NodeGrid *ret = cocos2d::NodeGrid::create();
    int num_ret = olua_push_object(L, ret, "cc.NodeGrid");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_NodeGrid_create$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Rect arg1;       /** rect */

    olua_check_object(L, 1, &arg1, "cc.Rect");

    // static cocos2d::NodeGrid *create(const cocos2d::Rect &rect)
    cocos2d::NodeGrid *ret = cocos2d::NodeGrid::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.NodeGrid");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_NodeGrid_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::NodeGrid *create()
        return _cocos2d_NodeGrid_create$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_object(L, 1, "cc.Rect"))) {
            // static cocos2d::NodeGrid *create(const cocos2d::Rect &rect)
            return _cocos2d_NodeGrid_create$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::NodeGrid::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_NodeGrid_getGrid(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::NodeGrid *self = nullptr;

    olua_to_object(L, 1, &self, "cc.NodeGrid");

    // cocos2d::GridBase *getGrid()
    cocos2d::GridBase *ret = self->getGrid();
    int num_ret = olua_push_object(L, ret, "cc.GridBase");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_NodeGrid_getGridRect(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::NodeGrid *self = nullptr;

    olua_to_object(L, 1, &self, "cc.NodeGrid");

    // const cocos2d::Rect &getGridRect()
    const cocos2d::Rect &ret = self->getGridRect();
    int num_ret = olua_push_object(L, ret, "cc.Rect");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_NodeGrid_setGrid(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::NodeGrid *self = nullptr;
    cocos2d::GridBase *arg1 = nullptr;       /** grid */

    olua_to_object(L, 1, &self, "cc.NodeGrid");
    olua_check_object(L, 2, &arg1, "cc.GridBase");

    // void setGrid(cocos2d::GridBase *grid)
    self->setGrid(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_NodeGrid_setGridRect(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::NodeGrid *self = nullptr;
    cocos2d::Rect arg1;       /** gridRect */

    olua_to_object(L, 1, &self, "cc.NodeGrid");
    olua_check_object(L, 2, &arg1, "cc.Rect");

    // void setGridRect(const cocos2d::Rect &gridRect)
    self->setGridRect(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_NodeGrid_setTarget(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::NodeGrid *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** target */

    olua_to_object(L, 1, &self, "cc.NodeGrid");
    olua_check_object(L, 2, &arg1, "cc.Node");

    // void setTarget(cocos2d::Node *target)
    self->setTarget(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_NodeGrid(lua_State *L)
{
    oluacls_class<cocos2d::NodeGrid, cocos2d::Node>(L, "cc.NodeGrid");
    oluacls_func(L, "create", _cocos2d_NodeGrid_create);
    oluacls_func(L, "getGrid", _cocos2d_NodeGrid_getGrid);
    oluacls_func(L, "getGridRect", _cocos2d_NodeGrid_getGridRect);
    oluacls_func(L, "setGrid", _cocos2d_NodeGrid_setGrid);
    oluacls_func(L, "setGridRect", _cocos2d_NodeGrid_setGridRect);
    oluacls_func(L, "setTarget", _cocos2d_NodeGrid_setTarget);
    oluacls_prop(L, "grid", _cocos2d_NodeGrid_getGrid, _cocos2d_NodeGrid_setGrid);
    oluacls_prop(L, "gridRect", _cocos2d_NodeGrid_getGridRect, _cocos2d_NodeGrid_setGridRect);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_GridAction_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridAction *self = nullptr;

    olua_to_object(L, 1, &self, "cc.GridAction");

    // cocos2d::GridAction *clone()
    cocos2d::GridAction *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.GridAction");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_GridAction_getGrid(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridAction *self = nullptr;

    olua_to_object(L, 1, &self, "cc.GridAction");

    // cocos2d::GridBase *getGrid()
    cocos2d::GridBase *ret = self->getGrid();
    int num_ret = olua_push_object(L, ret, "cc.GridBase");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_GridAction_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridAction *self = nullptr;

    olua_to_object(L, 1, &self, "cc.GridAction");

    // cocos2d::GridAction *reverse()
    cocos2d::GridAction *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.GridAction");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_GridAction(lua_State *L)
{
    oluacls_class<cocos2d::GridAction, cocos2d::ActionInterval>(L, "cc.GridAction");
    oluacls_func(L, "clone", _cocos2d_GridAction_clone);
    oluacls_func(L, "getGrid", _cocos2d_GridAction_getGrid);
    oluacls_func(L, "reverse", _cocos2d_GridAction_reverse);
    oluacls_prop(L, "grid", _cocos2d_GridAction_getGrid, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_Grid3DAction_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Grid3DAction *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Grid3DAction");

    // cocos2d::Grid3DAction *clone()
    cocos2d::Grid3DAction *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.Grid3DAction");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Grid3DAction_getGridRect(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Grid3DAction *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Grid3DAction");

    // cocos2d::Rect getGridRect()
    cocos2d::Rect ret = self->getGridRect();
    int num_ret = olua_pushcopy_object(L, ret, "cc.Rect");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Grid3DAction_getOriginalVertex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Grid3DAction *self = nullptr;
    cocos2d::Vec2 arg1;       /** position */

    olua_to_object(L, 1, &self, "cc.Grid3DAction");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // cocos2d::Vec3 getOriginalVertex(const cocos2d::Vec2 &position)
    cocos2d::Vec3 ret = self->getOriginalVertex(arg1);
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec3");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Grid3DAction_getVertex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Grid3DAction *self = nullptr;
    cocos2d::Vec2 arg1;       /** position */

    olua_to_object(L, 1, &self, "cc.Grid3DAction");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // cocos2d::Vec3 getVertex(const cocos2d::Vec2 &position)
    cocos2d::Vec3 ret = self->getVertex(arg1);
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec3");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Grid3DAction_setVertex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Grid3DAction *self = nullptr;
    cocos2d::Vec2 arg1;       /** position */
    cocos2d::Vec3 arg2;       /** vertex */

    olua_to_object(L, 1, &self, "cc.Grid3DAction");
    olua_check_object(L, 2, &arg1, "cc.Vec2");
    olua_check_object(L, 3, &arg2, "cc.Vec3");

    // void setVertex(const cocos2d::Vec2 &position, const cocos2d::Vec3 &vertex)
    self->setVertex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_Grid3DAction(lua_State *L)
{
    oluacls_class<cocos2d::Grid3DAction, cocos2d::GridAction>(L, "cc.Grid3DAction");
    oluacls_func(L, "clone", _cocos2d_Grid3DAction_clone);
    oluacls_func(L, "getGridRect", _cocos2d_Grid3DAction_getGridRect);
    oluacls_func(L, "getOriginalVertex", _cocos2d_Grid3DAction_getOriginalVertex);
    oluacls_func(L, "getVertex", _cocos2d_Grid3DAction_getVertex);
    oluacls_func(L, "setVertex", _cocos2d_Grid3DAction_setVertex);
    oluacls_prop(L, "gridRect", _cocos2d_Grid3DAction_getGridRect, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_TiledGrid3DAction_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TiledGrid3DAction *self = nullptr;

    olua_to_object(L, 1, &self, "cc.TiledGrid3DAction");

    // cocos2d::TiledGrid3DAction *clone()
    cocos2d::TiledGrid3DAction *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.TiledGrid3DAction");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TiledGrid3DAction_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Size");

    // static cocos2d::TiledGrid3DAction *create(float duration, const cocos2d::Size &gridSize)
    cocos2d::TiledGrid3DAction *ret = cocos2d::TiledGrid3DAction::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.TiledGrid3DAction");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TiledGrid3DAction_getOriginalTile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TiledGrid3DAction *self = nullptr;
    cocos2d::Vec2 arg1;       /** position */

    olua_to_object(L, 1, &self, "cc.TiledGrid3DAction");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // cocos2d::Quad3 getOriginalTile(const cocos2d::Vec2 &position)
    cocos2d::Quad3 ret = self->getOriginalTile(arg1);
    int num_ret = olua_pushcopy_object(L, ret, "cc.Quad3");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TiledGrid3DAction_getTile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TiledGrid3DAction *self = nullptr;
    cocos2d::Vec2 arg1;       /** position */

    olua_to_object(L, 1, &self, "cc.TiledGrid3DAction");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // cocos2d::Quad3 getTile(const cocos2d::Vec2 &position)
    cocos2d::Quad3 ret = self->getTile(arg1);
    int num_ret = olua_pushcopy_object(L, ret, "cc.Quad3");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TiledGrid3DAction_setTile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TiledGrid3DAction *self = nullptr;
    cocos2d::Vec2 arg1;       /** position */
    cocos2d::Quad3 arg2;       /** coords */

    olua_to_object(L, 1, &self, "cc.TiledGrid3DAction");
    olua_check_object(L, 2, &arg1, "cc.Vec2");
    olua_check_object(L, 3, &arg2, "cc.Quad3");

    // void setTile(const cocos2d::Vec2 &position, const cocos2d::Quad3 &coords)
    self->setTile(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_TiledGrid3DAction(lua_State *L)
{
    oluacls_class<cocos2d::TiledGrid3DAction, cocos2d::GridAction>(L, "cc.TiledGrid3DAction");
    oluacls_func(L, "clone", _cocos2d_TiledGrid3DAction_clone);
    oluacls_func(L, "create", _cocos2d_TiledGrid3DAction_create);
    oluacls_func(L, "getOriginalTile", _cocos2d_TiledGrid3DAction_getOriginalTile);
    oluacls_func(L, "getTile", _cocos2d_TiledGrid3DAction_getTile);
    oluacls_func(L, "setTile", _cocos2d_TiledGrid3DAction_setTile);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_AccelDeccelAmplitude_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::AccelDeccelAmplitude *self = nullptr;

    olua_to_object(L, 1, &self, "cc.AccelDeccelAmplitude");

    // cocos2d::AccelDeccelAmplitude *clone()
    cocos2d::AccelDeccelAmplitude *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.AccelDeccelAmplitude");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_AccelDeccelAmplitude_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *arg1 = nullptr;       /** action */
    float arg2 = 0;       /** duration */

    olua_check_object(L, 1, &arg1, "cc.Action");
    olua_check_number(L, 2, &arg2);

    // static cocos2d::AccelDeccelAmplitude *create(cocos2d::Action *action, float duration)
    cocos2d::AccelDeccelAmplitude *ret = cocos2d::AccelDeccelAmplitude::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.AccelDeccelAmplitude");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_AccelDeccelAmplitude_getRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::AccelDeccelAmplitude *self = nullptr;

    olua_to_object(L, 1, &self, "cc.AccelDeccelAmplitude");

    // float getRate()
    float ret = self->getRate();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_AccelDeccelAmplitude_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::AccelDeccelAmplitude *self = nullptr;

    olua_to_object(L, 1, &self, "cc.AccelDeccelAmplitude");

    // cocos2d::AccelDeccelAmplitude *reverse()
    cocos2d::AccelDeccelAmplitude *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.AccelDeccelAmplitude");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_AccelDeccelAmplitude_setRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::AccelDeccelAmplitude *self = nullptr;
    float arg1 = 0;       /** rate */

    olua_to_object(L, 1, &self, "cc.AccelDeccelAmplitude");
    olua_check_number(L, 2, &arg1);

    // void setRate(float rate)
    self->setRate(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_AccelDeccelAmplitude(lua_State *L)
{
    oluacls_class<cocos2d::AccelDeccelAmplitude, cocos2d::ActionInterval>(L, "cc.AccelDeccelAmplitude");
    oluacls_func(L, "clone", _cocos2d_AccelDeccelAmplitude_clone);
    oluacls_func(L, "create", _cocos2d_AccelDeccelAmplitude_create);
    oluacls_func(L, "getRate", _cocos2d_AccelDeccelAmplitude_getRate);
    oluacls_func(L, "reverse", _cocos2d_AccelDeccelAmplitude_reverse);
    oluacls_func(L, "setRate", _cocos2d_AccelDeccelAmplitude_setRate);
    oluacls_prop(L, "rate", _cocos2d_AccelDeccelAmplitude_getRate, _cocos2d_AccelDeccelAmplitude_setRate);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_AccelAmplitude_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::AccelAmplitude *self = nullptr;

    olua_to_object(L, 1, &self, "cc.AccelAmplitude");

    // cocos2d::AccelAmplitude *clone()
    cocos2d::AccelAmplitude *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.AccelAmplitude");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_AccelAmplitude_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *arg1 = nullptr;       /** action */
    float arg2 = 0;       /** duration */

    olua_check_object(L, 1, &arg1, "cc.Action");
    olua_check_number(L, 2, &arg2);

    // static cocos2d::AccelAmplitude *create(cocos2d::Action *action, float duration)
    cocos2d::AccelAmplitude *ret = cocos2d::AccelAmplitude::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.AccelAmplitude");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_AccelAmplitude_getRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::AccelAmplitude *self = nullptr;

    olua_to_object(L, 1, &self, "cc.AccelAmplitude");

    // float getRate()
    float ret = self->getRate();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_AccelAmplitude_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::AccelAmplitude *self = nullptr;

    olua_to_object(L, 1, &self, "cc.AccelAmplitude");

    // cocos2d::AccelAmplitude *reverse()
    cocos2d::AccelAmplitude *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.AccelAmplitude");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_AccelAmplitude_setRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::AccelAmplitude *self = nullptr;
    float arg1 = 0;       /** rate */

    olua_to_object(L, 1, &self, "cc.AccelAmplitude");
    olua_check_number(L, 2, &arg1);

    // void setRate(float rate)
    self->setRate(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_AccelAmplitude(lua_State *L)
{
    oluacls_class<cocos2d::AccelAmplitude, cocos2d::ActionInterval>(L, "cc.AccelAmplitude");
    oluacls_func(L, "clone", _cocos2d_AccelAmplitude_clone);
    oluacls_func(L, "create", _cocos2d_AccelAmplitude_create);
    oluacls_func(L, "getRate", _cocos2d_AccelAmplitude_getRate);
    oluacls_func(L, "reverse", _cocos2d_AccelAmplitude_reverse);
    oluacls_func(L, "setRate", _cocos2d_AccelAmplitude_setRate);
    oluacls_prop(L, "rate", _cocos2d_AccelAmplitude_getRate, _cocos2d_AccelAmplitude_setRate);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_DeccelAmplitude_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::DeccelAmplitude *self = nullptr;

    olua_to_object(L, 1, &self, "cc.DeccelAmplitude");

    // cocos2d::DeccelAmplitude *clone()
    cocos2d::DeccelAmplitude *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.DeccelAmplitude");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_DeccelAmplitude_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *arg1 = nullptr;       /** action */
    float arg2 = 0;       /** duration */

    olua_check_object(L, 1, &arg1, "cc.Action");
    olua_check_number(L, 2, &arg2);

    // static cocos2d::DeccelAmplitude *create(cocos2d::Action *action, float duration)
    cocos2d::DeccelAmplitude *ret = cocos2d::DeccelAmplitude::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.DeccelAmplitude");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_DeccelAmplitude_getRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::DeccelAmplitude *self = nullptr;

    olua_to_object(L, 1, &self, "cc.DeccelAmplitude");

    // float getRate()
    float ret = self->getRate();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_DeccelAmplitude_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::DeccelAmplitude *self = nullptr;

    olua_to_object(L, 1, &self, "cc.DeccelAmplitude");

    // cocos2d::DeccelAmplitude *reverse()
    cocos2d::DeccelAmplitude *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.DeccelAmplitude");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_DeccelAmplitude_setRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::DeccelAmplitude *self = nullptr;
    float arg1 = 0;       /** rate */

    olua_to_object(L, 1, &self, "cc.DeccelAmplitude");
    olua_check_number(L, 2, &arg1);

    // void setRate(float rate)
    self->setRate(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_DeccelAmplitude(lua_State *L)
{
    oluacls_class<cocos2d::DeccelAmplitude, cocos2d::ActionInterval>(L, "cc.DeccelAmplitude");
    oluacls_func(L, "clone", _cocos2d_DeccelAmplitude_clone);
    oluacls_func(L, "create", _cocos2d_DeccelAmplitude_create);
    oluacls_func(L, "getRate", _cocos2d_DeccelAmplitude_getRate);
    oluacls_func(L, "reverse", _cocos2d_DeccelAmplitude_reverse);
    oluacls_func(L, "setRate", _cocos2d_DeccelAmplitude_setRate);
    oluacls_prop(L, "rate", _cocos2d_DeccelAmplitude_getRate, _cocos2d_DeccelAmplitude_setRate);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_StopGrid_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::StopGrid *self = nullptr;

    olua_to_object(L, 1, &self, "cc.StopGrid");

    // cocos2d::StopGrid *clone()
    cocos2d::StopGrid *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.StopGrid");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_StopGrid_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::StopGrid *create()
    cocos2d::StopGrid *ret = cocos2d::StopGrid::create();
    int num_ret = olua_push_object(L, ret, "cc.StopGrid");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_StopGrid_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::StopGrid *self = nullptr;

    olua_to_object(L, 1, &self, "cc.StopGrid");

    // cocos2d::StopGrid *reverse()
    cocos2d::StopGrid *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.StopGrid");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_StopGrid(lua_State *L)
{
    oluacls_class<cocos2d::StopGrid, cocos2d::ActionInstant>(L, "cc.StopGrid");
    oluacls_func(L, "clone", _cocos2d_StopGrid_clone);
    oluacls_func(L, "create", _cocos2d_StopGrid_create);
    oluacls_func(L, "reverse", _cocos2d_StopGrid_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_ReuseGrid_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ReuseGrid *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ReuseGrid");

    // cocos2d::ReuseGrid *clone()
    cocos2d::ReuseGrid *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.ReuseGrid");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ReuseGrid_create(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** times */

    olua_check_integer(L, 1, &arg1);

    // static cocos2d::ReuseGrid *create(int times)
    cocos2d::ReuseGrid *ret = cocos2d::ReuseGrid::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.ReuseGrid");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ReuseGrid_initWithTimes(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ReuseGrid *self = nullptr;
    int arg1 = 0;       /** times */

    olua_to_object(L, 1, &self, "cc.ReuseGrid");
    olua_check_integer(L, 2, &arg1);

    // bool initWithTimes(int times)
    bool ret = self->initWithTimes(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ReuseGrid_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ReuseGrid *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ReuseGrid");

    // cocos2d::ReuseGrid *reverse()
    cocos2d::ReuseGrid *ret = self->reverse();
    int num_ret = olua_push_object(L, ret, "cc.ReuseGrid");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_ReuseGrid(lua_State *L)
{
    oluacls_class<cocos2d::ReuseGrid, cocos2d::ActionInstant>(L, "cc.ReuseGrid");
    oluacls_func(L, "clone", _cocos2d_ReuseGrid_clone);
    oluacls_func(L, "create", _cocos2d_ReuseGrid_create);
    oluacls_func(L, "initWithTimes", _cocos2d_ReuseGrid_initWithTimes);
    oluacls_func(L, "reverse", _cocos2d_ReuseGrid_reverse);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_Waves3D_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Waves3D *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Waves3D");

    // cocos2d::Waves3D *clone()
    cocos2d::Waves3D *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.Waves3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Waves3D_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */
    unsigned int arg3 = 0;       /** waves */
    float arg4 = 0;       /** amplitude */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Size");
    olua_check_integer(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // static cocos2d::Waves3D *create(float duration, const cocos2d::Size &gridSize, unsigned int waves, float amplitude)
    cocos2d::Waves3D *ret = cocos2d::Waves3D::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.Waves3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Waves3D_getAmplitude(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Waves3D *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Waves3D");

    // float getAmplitude()
    float ret = self->getAmplitude();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Waves3D_setAmplitude(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Waves3D *self = nullptr;
    float arg1 = 0;       /** amplitude */

    olua_to_object(L, 1, &self, "cc.Waves3D");
    olua_check_number(L, 2, &arg1);

    // void setAmplitude(float amplitude)
    self->setAmplitude(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_Waves3D(lua_State *L)
{
    oluacls_class<cocos2d::Waves3D, cocos2d::Grid3DAction>(L, "cc.Waves3D");
    oluacls_func(L, "clone", _cocos2d_Waves3D_clone);
    oluacls_func(L, "create", _cocos2d_Waves3D_create);
    oluacls_func(L, "getAmplitude", _cocos2d_Waves3D_getAmplitude);
    oluacls_func(L, "setAmplitude", _cocos2d_Waves3D_setAmplitude);
    oluacls_prop(L, "amplitude", _cocos2d_Waves3D_getAmplitude, _cocos2d_Waves3D_setAmplitude);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_FlipX3D_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FlipX3D *self = nullptr;

    olua_to_object(L, 1, &self, "cc.FlipX3D");

    // cocos2d::FlipX3D *clone()
    cocos2d::FlipX3D *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.FlipX3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_FlipX3D_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */

    olua_check_number(L, 1, &arg1);

    // static cocos2d::FlipX3D *create(float duration)
    cocos2d::FlipX3D *ret = cocos2d::FlipX3D::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.FlipX3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_FlipX3D_initWithSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FlipX3D *self = nullptr;
    cocos2d::Size arg1;       /** gridSize */
    float arg2 = 0;       /** duration */

    olua_to_object(L, 1, &self, "cc.FlipX3D");
    olua_check_object(L, 2, &arg1, "cc.Size");
    olua_check_number(L, 3, &arg2);

    // bool initWithSize(const cocos2d::Size &gridSize, float duration)
    bool ret = self->initWithSize(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_FlipX3D(lua_State *L)
{
    oluacls_class<cocos2d::FlipX3D, cocos2d::Grid3DAction>(L, "cc.FlipX3D");
    oluacls_func(L, "clone", _cocos2d_FlipX3D_clone);
    oluacls_func(L, "create", _cocos2d_FlipX3D_create);
    oluacls_func(L, "initWithSize", _cocos2d_FlipX3D_initWithSize);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_FlipY3D_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FlipY3D *self = nullptr;

    olua_to_object(L, 1, &self, "cc.FlipY3D");

    // cocos2d::FlipY3D *clone()
    cocos2d::FlipY3D *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.FlipY3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_FlipY3D_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */

    olua_check_number(L, 1, &arg1);

    // static cocos2d::FlipY3D *create(float duration)
    cocos2d::FlipY3D *ret = cocos2d::FlipY3D::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.FlipY3D");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_FlipY3D(lua_State *L)
{
    oluacls_class<cocos2d::FlipY3D, cocos2d::FlipX3D>(L, "cc.FlipY3D");
    oluacls_func(L, "clone", _cocos2d_FlipY3D_clone);
    oluacls_func(L, "create", _cocos2d_FlipY3D_create);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_Lens3D_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Lens3D *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Lens3D");

    // cocos2d::Lens3D *clone()
    cocos2d::Lens3D *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.Lens3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Lens3D_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */
    cocos2d::Vec2 arg3;       /** position */
    float arg4 = 0;       /** radius */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Size");
    olua_check_object(L, 3, &arg3, "cc.Vec2");
    olua_check_number(L, 4, &arg4);

    // static cocos2d::Lens3D *create(float duration, const cocos2d::Size &gridSize, const cocos2d::Vec2 &position, float radius)
    cocos2d::Lens3D *ret = cocos2d::Lens3D::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.Lens3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Lens3D_getLensEffect(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Lens3D *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Lens3D");

    // float getLensEffect()
    float ret = self->getLensEffect();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Lens3D_getPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Lens3D *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Lens3D");

    // const cocos2d::Vec2 &getPosition()
    const cocos2d::Vec2 &ret = self->getPosition();
    int num_ret = olua_push_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Lens3D_setConcave(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Lens3D *self = nullptr;
    bool arg1 = false;       /** concave */

    olua_to_object(L, 1, &self, "cc.Lens3D");
    olua_check_bool(L, 2, &arg1);

    // void setConcave(bool concave)
    self->setConcave(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_Lens3D_setLensEffect(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Lens3D *self = nullptr;
    float arg1 = 0;       /** lensEffect */

    olua_to_object(L, 1, &self, "cc.Lens3D");
    olua_check_number(L, 2, &arg1);

    // void setLensEffect(float lensEffect)
    self->setLensEffect(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_Lens3D_setPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Lens3D *self = nullptr;
    cocos2d::Vec2 arg1;       /** position */

    olua_to_object(L, 1, &self, "cc.Lens3D");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void setPosition(const cocos2d::Vec2 &position)
    self->setPosition(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_Lens3D(lua_State *L)
{
    oluacls_class<cocos2d::Lens3D, cocos2d::Grid3DAction>(L, "cc.Lens3D");
    oluacls_func(L, "clone", _cocos2d_Lens3D_clone);
    oluacls_func(L, "create", _cocos2d_Lens3D_create);
    oluacls_func(L, "getLensEffect", _cocos2d_Lens3D_getLensEffect);
    oluacls_func(L, "getPosition", _cocos2d_Lens3D_getPosition);
    oluacls_func(L, "setConcave", _cocos2d_Lens3D_setConcave);
    oluacls_func(L, "setLensEffect", _cocos2d_Lens3D_setLensEffect);
    oluacls_func(L, "setPosition", _cocos2d_Lens3D_setPosition);
    oluacls_prop(L, "lensEffect", _cocos2d_Lens3D_getLensEffect, _cocos2d_Lens3D_setLensEffect);
    oluacls_prop(L, "position", _cocos2d_Lens3D_getPosition, _cocos2d_Lens3D_setPosition);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_Ripple3D_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Ripple3D *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Ripple3D");

    // cocos2d::Ripple3D *clone()
    cocos2d::Ripple3D *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.Ripple3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Ripple3D_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */
    cocos2d::Vec2 arg3;       /** position */
    float arg4 = 0;       /** radius */
    unsigned int arg5 = 0;       /** waves */
    float arg6 = 0;       /** amplitude */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Size");
    olua_check_object(L, 3, &arg3, "cc.Vec2");
    olua_check_number(L, 4, &arg4);
    olua_check_integer(L, 5, &arg5);
    olua_check_number(L, 6, &arg6);

    // static cocos2d::Ripple3D *create(float duration, const cocos2d::Size &gridSize, const cocos2d::Vec2 &position, float radius, unsigned int waves, float amplitude)
    cocos2d::Ripple3D *ret = cocos2d::Ripple3D::create(arg1, arg2, arg3, arg4, arg5, arg6);
    int num_ret = olua_push_object(L, ret, "cc.Ripple3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Ripple3D_getAmplitude(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Ripple3D *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Ripple3D");

    // float getAmplitude()
    float ret = self->getAmplitude();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Ripple3D_getPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Ripple3D *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Ripple3D");

    // const cocos2d::Vec2 &getPosition()
    const cocos2d::Vec2 &ret = self->getPosition();
    int num_ret = olua_push_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Ripple3D_setAmplitude(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Ripple3D *self = nullptr;
    float arg1 = 0;       /** fAmplitude */

    olua_to_object(L, 1, &self, "cc.Ripple3D");
    olua_check_number(L, 2, &arg1);

    // void setAmplitude(float fAmplitude)
    self->setAmplitude(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_Ripple3D_setPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Ripple3D *self = nullptr;
    cocos2d::Vec2 arg1;       /** position */

    olua_to_object(L, 1, &self, "cc.Ripple3D");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void setPosition(const cocos2d::Vec2 &position)
    self->setPosition(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_Ripple3D(lua_State *L)
{
    oluacls_class<cocos2d::Ripple3D, cocos2d::Grid3DAction>(L, "cc.Ripple3D");
    oluacls_func(L, "clone", _cocos2d_Ripple3D_clone);
    oluacls_func(L, "create", _cocos2d_Ripple3D_create);
    oluacls_func(L, "getAmplitude", _cocos2d_Ripple3D_getAmplitude);
    oluacls_func(L, "getPosition", _cocos2d_Ripple3D_getPosition);
    oluacls_func(L, "setAmplitude", _cocos2d_Ripple3D_setAmplitude);
    oluacls_func(L, "setPosition", _cocos2d_Ripple3D_setPosition);
    oluacls_prop(L, "amplitude", _cocos2d_Ripple3D_getAmplitude, _cocos2d_Ripple3D_setAmplitude);
    oluacls_prop(L, "position", _cocos2d_Ripple3D_getPosition, _cocos2d_Ripple3D_setPosition);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_Shaky3D_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Shaky3D *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Shaky3D");

    // cocos2d::Shaky3D *clone()
    cocos2d::Shaky3D *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.Shaky3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Shaky3D_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** initWithDuration */
    cocos2d::Size arg2;       /** gridSize */
    int arg3 = 0;       /** range */
    bool arg4 = false;       /** shakeZ */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Size");
    olua_check_integer(L, 3, &arg3);
    olua_check_bool(L, 4, &arg4);

    // static cocos2d::Shaky3D *create(float initWithDuration, const cocos2d::Size &gridSize, int range, bool shakeZ)
    cocos2d::Shaky3D *ret = cocos2d::Shaky3D::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.Shaky3D");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_Shaky3D(lua_State *L)
{
    oluacls_class<cocos2d::Shaky3D, cocos2d::Grid3DAction>(L, "cc.Shaky3D");
    oluacls_func(L, "clone", _cocos2d_Shaky3D_clone);
    oluacls_func(L, "create", _cocos2d_Shaky3D_create);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_Liquid_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Liquid *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Liquid");

    // cocos2d::Liquid *clone()
    cocos2d::Liquid *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.Liquid");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Liquid_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */
    unsigned int arg3 = 0;       /** waves */
    float arg4 = 0;       /** amplitude */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Size");
    olua_check_integer(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // static cocos2d::Liquid *create(float duration, const cocos2d::Size &gridSize, unsigned int waves, float amplitude)
    cocos2d::Liquid *ret = cocos2d::Liquid::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.Liquid");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Liquid_getAmplitude(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Liquid *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Liquid");

    // float getAmplitude()
    float ret = self->getAmplitude();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Liquid_setAmplitude(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Liquid *self = nullptr;
    float arg1 = 0;       /** amplitude */

    olua_to_object(L, 1, &self, "cc.Liquid");
    olua_check_number(L, 2, &arg1);

    // void setAmplitude(float amplitude)
    self->setAmplitude(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_Liquid(lua_State *L)
{
    oluacls_class<cocos2d::Liquid, cocos2d::Grid3DAction>(L, "cc.Liquid");
    oluacls_func(L, "clone", _cocos2d_Liquid_clone);
    oluacls_func(L, "create", _cocos2d_Liquid_create);
    oluacls_func(L, "getAmplitude", _cocos2d_Liquid_getAmplitude);
    oluacls_func(L, "setAmplitude", _cocos2d_Liquid_setAmplitude);
    oluacls_prop(L, "amplitude", _cocos2d_Liquid_getAmplitude, _cocos2d_Liquid_setAmplitude);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_Waves_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Waves *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Waves");

    // cocos2d::Waves *clone()
    cocos2d::Waves *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.Waves");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Waves_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */
    unsigned int arg3 = 0;       /** waves */
    float arg4 = 0;       /** amplitude */
    bool arg5 = false;       /** horizontal */
    bool arg6 = false;       /** vertical */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Size");
    olua_check_integer(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);
    olua_check_bool(L, 5, &arg5);
    olua_check_bool(L, 6, &arg6);

    // static cocos2d::Waves *create(float duration, const cocos2d::Size &gridSize, unsigned int waves, float amplitude, bool horizontal, bool vertical)
    cocos2d::Waves *ret = cocos2d::Waves::create(arg1, arg2, arg3, arg4, arg5, arg6);
    int num_ret = olua_push_object(L, ret, "cc.Waves");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Waves_getAmplitude(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Waves *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Waves");

    // float getAmplitude()
    float ret = self->getAmplitude();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Waves_setAmplitude(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Waves *self = nullptr;
    float arg1 = 0;       /** amplitude */

    olua_to_object(L, 1, &self, "cc.Waves");
    olua_check_number(L, 2, &arg1);

    // void setAmplitude(float amplitude)
    self->setAmplitude(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_Waves(lua_State *L)
{
    oluacls_class<cocos2d::Waves, cocos2d::Grid3DAction>(L, "cc.Waves");
    oluacls_func(L, "clone", _cocos2d_Waves_clone);
    oluacls_func(L, "create", _cocos2d_Waves_create);
    oluacls_func(L, "getAmplitude", _cocos2d_Waves_getAmplitude);
    oluacls_func(L, "setAmplitude", _cocos2d_Waves_setAmplitude);
    oluacls_prop(L, "amplitude", _cocos2d_Waves_getAmplitude, _cocos2d_Waves_setAmplitude);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_Twirl_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Twirl *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Twirl");

    // cocos2d::Twirl *clone()
    cocos2d::Twirl *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.Twirl");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Twirl_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */
    cocos2d::Vec2 arg3;       /** position */
    unsigned int arg4 = 0;       /** twirls */
    float arg5 = 0;       /** amplitude */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Size");
    olua_check_object(L, 3, &arg3, "cc.Vec2");
    olua_check_integer(L, 4, &arg4);
    olua_check_number(L, 5, &arg5);

    // static cocos2d::Twirl *create(float duration, const cocos2d::Size &gridSize, const cocos2d::Vec2 &position, unsigned int twirls, float amplitude)
    cocos2d::Twirl *ret = cocos2d::Twirl::create(arg1, arg2, arg3, arg4, arg5);
    int num_ret = olua_push_object(L, ret, "cc.Twirl");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Twirl_getAmplitude(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Twirl *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Twirl");

    // float getAmplitude()
    float ret = self->getAmplitude();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Twirl_getPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Twirl *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Twirl");

    // const cocos2d::Vec2 &getPosition()
    const cocos2d::Vec2 &ret = self->getPosition();
    int num_ret = olua_push_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Twirl_setAmplitude(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Twirl *self = nullptr;
    float arg1 = 0;       /** amplitude */

    olua_to_object(L, 1, &self, "cc.Twirl");
    olua_check_number(L, 2, &arg1);

    // void setAmplitude(float amplitude)
    self->setAmplitude(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_Twirl_setPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Twirl *self = nullptr;
    cocos2d::Vec2 arg1;       /** position */

    olua_to_object(L, 1, &self, "cc.Twirl");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void setPosition(const cocos2d::Vec2 &position)
    self->setPosition(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_Twirl(lua_State *L)
{
    oluacls_class<cocos2d::Twirl, cocos2d::Grid3DAction>(L, "cc.Twirl");
    oluacls_func(L, "clone", _cocos2d_Twirl_clone);
    oluacls_func(L, "create", _cocos2d_Twirl_create);
    oluacls_func(L, "getAmplitude", _cocos2d_Twirl_getAmplitude);
    oluacls_func(L, "getPosition", _cocos2d_Twirl_getPosition);
    oluacls_func(L, "setAmplitude", _cocos2d_Twirl_setAmplitude);
    oluacls_func(L, "setPosition", _cocos2d_Twirl_setPosition);
    oluacls_prop(L, "amplitude", _cocos2d_Twirl_getAmplitude, _cocos2d_Twirl_setAmplitude);
    oluacls_prop(L, "position", _cocos2d_Twirl_getPosition, _cocos2d_Twirl_setPosition);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_PageTurn3D_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PageTurn3D *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PageTurn3D");

    // cocos2d::PageTurn3D *clone()
    cocos2d::PageTurn3D *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.PageTurn3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PageTurn3D_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Size");

    // static cocos2d::PageTurn3D *create(float duration, const cocos2d::Size &gridSize)
    cocos2d::PageTurn3D *ret = cocos2d::PageTurn3D::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.PageTurn3D");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PageTurn3D(lua_State *L)
{
    oluacls_class<cocos2d::PageTurn3D, cocos2d::Grid3DAction>(L, "cc.PageTurn3D");
    oluacls_func(L, "clone", _cocos2d_PageTurn3D_clone);
    oluacls_func(L, "create", _cocos2d_PageTurn3D_create);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_ShakyTiles3D_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ShakyTiles3D *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ShakyTiles3D");

    // cocos2d::ShakyTiles3D *clone()
    cocos2d::ShakyTiles3D *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.ShakyTiles3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ShakyTiles3D_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */
    int arg3 = 0;       /** range */
    bool arg4 = false;       /** shakeZ */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Size");
    olua_check_integer(L, 3, &arg3);
    olua_check_bool(L, 4, &arg4);

    // static cocos2d::ShakyTiles3D *create(float duration, const cocos2d::Size &gridSize, int range, bool shakeZ)
    cocos2d::ShakyTiles3D *ret = cocos2d::ShakyTiles3D::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.ShakyTiles3D");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_ShakyTiles3D(lua_State *L)
{
    oluacls_class<cocos2d::ShakyTiles3D, cocos2d::TiledGrid3DAction>(L, "cc.ShakyTiles3D");
    oluacls_func(L, "clone", _cocos2d_ShakyTiles3D_clone);
    oluacls_func(L, "create", _cocos2d_ShakyTiles3D_create);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_ShatteredTiles3D_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ShatteredTiles3D *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ShatteredTiles3D");

    // cocos2d::ShatteredTiles3D *clone()
    cocos2d::ShatteredTiles3D *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.ShatteredTiles3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ShatteredTiles3D_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */
    int arg3 = 0;       /** range */
    bool arg4 = false;       /** shatterZ */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Size");
    olua_check_integer(L, 3, &arg3);
    olua_check_bool(L, 4, &arg4);

    // static cocos2d::ShatteredTiles3D *create(float duration, const cocos2d::Size &gridSize, int range, bool shatterZ)
    cocos2d::ShatteredTiles3D *ret = cocos2d::ShatteredTiles3D::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.ShatteredTiles3D");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_ShatteredTiles3D(lua_State *L)
{
    oluacls_class<cocos2d::ShatteredTiles3D, cocos2d::TiledGrid3DAction>(L, "cc.ShatteredTiles3D");
    oluacls_func(L, "clone", _cocos2d_ShatteredTiles3D_clone);
    oluacls_func(L, "create", _cocos2d_ShatteredTiles3D_create);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_ShuffleTiles_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ShuffleTiles *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ShuffleTiles");

    // cocos2d::ShuffleTiles *clone()
    cocos2d::ShuffleTiles *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.ShuffleTiles");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ShuffleTiles_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */
    unsigned int arg3 = 0;       /** seed */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Size");
    olua_check_integer(L, 3, &arg3);

    // static cocos2d::ShuffleTiles *create(float duration, const cocos2d::Size &gridSize, unsigned int seed)
    cocos2d::ShuffleTiles *ret = cocos2d::ShuffleTiles::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.ShuffleTiles");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ShuffleTiles_getDelta(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ShuffleTiles *self = nullptr;
    cocos2d::Size arg1;       /** pos */

    olua_to_object(L, 1, &self, "cc.ShuffleTiles");
    olua_check_object(L, 2, &arg1, "cc.Size");

    // cocos2d::Size getDelta(const cocos2d::Size &pos)
    cocos2d::Size ret = self->getDelta(arg1);
    int num_ret = olua_pushcopy_object(L, ret, "cc.Size");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ShuffleTiles_shuffle(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ShuffleTiles *self = nullptr;
    unsigned int *arg1 = nullptr;       /** array */
    unsigned int arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "cc.ShuffleTiles");
    olua_check_pointer(L, 2, &arg1, "olua.uint");
    olua_check_integer(L, 3, &arg2);

    // void shuffle(unsigned int *array, unsigned int len)
    self->shuffle(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_ShuffleTiles(lua_State *L)
{
    oluacls_class<cocos2d::ShuffleTiles, cocos2d::TiledGrid3DAction>(L, "cc.ShuffleTiles");
    oluacls_func(L, "clone", _cocos2d_ShuffleTiles_clone);
    oluacls_func(L, "create", _cocos2d_ShuffleTiles_create);
    oluacls_func(L, "getDelta", _cocos2d_ShuffleTiles_getDelta);
    oluacls_func(L, "shuffle", _cocos2d_ShuffleTiles_shuffle);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_FadeOutTRTiles_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FadeOutTRTiles *self = nullptr;

    olua_to_object(L, 1, &self, "cc.FadeOutTRTiles");

    // cocos2d::FadeOutTRTiles *clone()
    cocos2d::FadeOutTRTiles *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.FadeOutTRTiles");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_FadeOutTRTiles_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Size");

    // static cocos2d::FadeOutTRTiles *create(float duration, const cocos2d::Size &gridSize)
    cocos2d::FadeOutTRTiles *ret = cocos2d::FadeOutTRTiles::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.FadeOutTRTiles");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_FadeOutTRTiles_testFunc(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FadeOutTRTiles *self = nullptr;
    cocos2d::Size arg1;       /** pos */
    float arg2 = 0;       /** time */

    olua_to_object(L, 1, &self, "cc.FadeOutTRTiles");
    olua_check_object(L, 2, &arg1, "cc.Size");
    olua_check_number(L, 3, &arg2);

    // float testFunc(const cocos2d::Size &pos, float time)
    float ret = self->testFunc(arg1, arg2);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_FadeOutTRTiles_transformTile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FadeOutTRTiles *self = nullptr;
    cocos2d::Vec2 arg1;       /** pos */
    float arg2 = 0;       /** distance */

    olua_to_object(L, 1, &self, "cc.FadeOutTRTiles");
    olua_check_object(L, 2, &arg1, "cc.Vec2");
    olua_check_number(L, 3, &arg2);

    // void transformTile(const cocos2d::Vec2 &pos, float distance)
    self->transformTile(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_FadeOutTRTiles_turnOffTile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FadeOutTRTiles *self = nullptr;
    cocos2d::Vec2 arg1;       /** pos */

    olua_to_object(L, 1, &self, "cc.FadeOutTRTiles");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void turnOffTile(const cocos2d::Vec2 &pos)
    self->turnOffTile(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_FadeOutTRTiles_turnOnTile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FadeOutTRTiles *self = nullptr;
    cocos2d::Vec2 arg1;       /** pos */

    olua_to_object(L, 1, &self, "cc.FadeOutTRTiles");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void turnOnTile(const cocos2d::Vec2 &pos)
    self->turnOnTile(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_FadeOutTRTiles(lua_State *L)
{
    oluacls_class<cocos2d::FadeOutTRTiles, cocos2d::TiledGrid3DAction>(L, "cc.FadeOutTRTiles");
    oluacls_func(L, "clone", _cocos2d_FadeOutTRTiles_clone);
    oluacls_func(L, "create", _cocos2d_FadeOutTRTiles_create);
    oluacls_func(L, "testFunc", _cocos2d_FadeOutTRTiles_testFunc);
    oluacls_func(L, "transformTile", _cocos2d_FadeOutTRTiles_transformTile);
    oluacls_func(L, "turnOffTile", _cocos2d_FadeOutTRTiles_turnOffTile);
    oluacls_func(L, "turnOnTile", _cocos2d_FadeOutTRTiles_turnOnTile);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_FadeOutBLTiles_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FadeOutBLTiles *self = nullptr;

    olua_to_object(L, 1, &self, "cc.FadeOutBLTiles");

    // cocos2d::FadeOutBLTiles *clone()
    cocos2d::FadeOutBLTiles *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.FadeOutBLTiles");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_FadeOutBLTiles_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Size");

    // static cocos2d::FadeOutBLTiles *create(float duration, const cocos2d::Size &gridSize)
    cocos2d::FadeOutBLTiles *ret = cocos2d::FadeOutBLTiles::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.FadeOutBLTiles");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_FadeOutBLTiles(lua_State *L)
{
    oluacls_class<cocos2d::FadeOutBLTiles, cocos2d::FadeOutTRTiles>(L, "cc.FadeOutBLTiles");
    oluacls_func(L, "clone", _cocos2d_FadeOutBLTiles_clone);
    oluacls_func(L, "create", _cocos2d_FadeOutBLTiles_create);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_FadeOutUpTiles_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FadeOutUpTiles *self = nullptr;

    olua_to_object(L, 1, &self, "cc.FadeOutUpTiles");

    // cocos2d::FadeOutUpTiles *clone()
    cocos2d::FadeOutUpTiles *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.FadeOutUpTiles");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_FadeOutUpTiles_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Size");

    // static cocos2d::FadeOutUpTiles *create(float duration, const cocos2d::Size &gridSize)
    cocos2d::FadeOutUpTiles *ret = cocos2d::FadeOutUpTiles::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.FadeOutUpTiles");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_FadeOutUpTiles(lua_State *L)
{
    oluacls_class<cocos2d::FadeOutUpTiles, cocos2d::FadeOutTRTiles>(L, "cc.FadeOutUpTiles");
    oluacls_func(L, "clone", _cocos2d_FadeOutUpTiles_clone);
    oluacls_func(L, "create", _cocos2d_FadeOutUpTiles_create);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_FadeOutDownTiles_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FadeOutDownTiles *self = nullptr;

    olua_to_object(L, 1, &self, "cc.FadeOutDownTiles");

    // cocos2d::FadeOutDownTiles *clone()
    cocos2d::FadeOutDownTiles *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.FadeOutDownTiles");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_FadeOutDownTiles_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Size");

    // static cocos2d::FadeOutDownTiles *create(float duration, const cocos2d::Size &gridSize)
    cocos2d::FadeOutDownTiles *ret = cocos2d::FadeOutDownTiles::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.FadeOutDownTiles");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_FadeOutDownTiles(lua_State *L)
{
    oluacls_class<cocos2d::FadeOutDownTiles, cocos2d::FadeOutUpTiles>(L, "cc.FadeOutDownTiles");
    oluacls_func(L, "clone", _cocos2d_FadeOutDownTiles_clone);
    oluacls_func(L, "create", _cocos2d_FadeOutDownTiles_create);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_TurnOffTiles_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TurnOffTiles *self = nullptr;

    olua_to_object(L, 1, &self, "cc.TurnOffTiles");

    // cocos2d::TurnOffTiles *clone()
    cocos2d::TurnOffTiles *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.TurnOffTiles");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TurnOffTiles_create$1(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Size");

    // static cocos2d::TurnOffTiles *create(float duration, const cocos2d::Size &gridSize)
    cocos2d::TurnOffTiles *ret = cocos2d::TurnOffTiles::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.TurnOffTiles");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TurnOffTiles_create$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */
    unsigned int arg3 = 0;       /** seed */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Size");
    olua_check_integer(L, 3, &arg3);

    // static cocos2d::TurnOffTiles *create(float duration, const cocos2d::Size &gridSize, unsigned int seed)
    cocos2d::TurnOffTiles *ret = cocos2d::TurnOffTiles::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.TurnOffTiles");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TurnOffTiles_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_number(L, 1)) && (olua_is_object(L, 2, "cc.Size"))) {
            // static cocos2d::TurnOffTiles *create(float duration, const cocos2d::Size &gridSize)
            return _cocos2d_TurnOffTiles_create$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (olua_is_object(L, 2, "cc.Size")) && (olua_is_integer(L, 3))) {
            // static cocos2d::TurnOffTiles *create(float duration, const cocos2d::Size &gridSize, unsigned int seed)
            return _cocos2d_TurnOffTiles_create$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::TurnOffTiles::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_TurnOffTiles_shuffle(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TurnOffTiles *self = nullptr;
    unsigned int *arg1 = nullptr;       /** array */
    unsigned int arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "cc.TurnOffTiles");
    olua_check_pointer(L, 2, &arg1, "olua.uint");
    olua_check_integer(L, 3, &arg2);

    // void shuffle(unsigned int *array, unsigned int len)
    self->shuffle(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_TurnOffTiles_turnOffTile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TurnOffTiles *self = nullptr;
    cocos2d::Vec2 arg1;       /** pos */

    olua_to_object(L, 1, &self, "cc.TurnOffTiles");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void turnOffTile(const cocos2d::Vec2 &pos)
    self->turnOffTile(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_TurnOffTiles_turnOnTile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TurnOffTiles *self = nullptr;
    cocos2d::Vec2 arg1;       /** pos */

    olua_to_object(L, 1, &self, "cc.TurnOffTiles");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void turnOnTile(const cocos2d::Vec2 &pos)
    self->turnOnTile(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_TurnOffTiles(lua_State *L)
{
    oluacls_class<cocos2d::TurnOffTiles, cocos2d::TiledGrid3DAction>(L, "cc.TurnOffTiles");
    oluacls_func(L, "clone", _cocos2d_TurnOffTiles_clone);
    oluacls_func(L, "create", _cocos2d_TurnOffTiles_create);
    oluacls_func(L, "shuffle", _cocos2d_TurnOffTiles_shuffle);
    oluacls_func(L, "turnOffTile", _cocos2d_TurnOffTiles_turnOffTile);
    oluacls_func(L, "turnOnTile", _cocos2d_TurnOffTiles_turnOnTile);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_WavesTiles3D_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::WavesTiles3D *self = nullptr;

    olua_to_object(L, 1, &self, "cc.WavesTiles3D");

    // cocos2d::WavesTiles3D *clone()
    cocos2d::WavesTiles3D *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.WavesTiles3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_WavesTiles3D_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */
    unsigned int arg3 = 0;       /** waves */
    float arg4 = 0;       /** amplitude */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Size");
    olua_check_integer(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // static cocos2d::WavesTiles3D *create(float duration, const cocos2d::Size &gridSize, unsigned int waves, float amplitude)
    cocos2d::WavesTiles3D *ret = cocos2d::WavesTiles3D::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.WavesTiles3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_WavesTiles3D_getAmplitude(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::WavesTiles3D *self = nullptr;

    olua_to_object(L, 1, &self, "cc.WavesTiles3D");

    // float getAmplitude()
    float ret = self->getAmplitude();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_WavesTiles3D_setAmplitude(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::WavesTiles3D *self = nullptr;
    float arg1 = 0;       /** amplitude */

    olua_to_object(L, 1, &self, "cc.WavesTiles3D");
    olua_check_number(L, 2, &arg1);

    // void setAmplitude(float amplitude)
    self->setAmplitude(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_WavesTiles3D(lua_State *L)
{
    oluacls_class<cocos2d::WavesTiles3D, cocos2d::TiledGrid3DAction>(L, "cc.WavesTiles3D");
    oluacls_func(L, "clone", _cocos2d_WavesTiles3D_clone);
    oluacls_func(L, "create", _cocos2d_WavesTiles3D_create);
    oluacls_func(L, "getAmplitude", _cocos2d_WavesTiles3D_getAmplitude);
    oluacls_func(L, "setAmplitude", _cocos2d_WavesTiles3D_setAmplitude);
    oluacls_prop(L, "amplitude", _cocos2d_WavesTiles3D_getAmplitude, _cocos2d_WavesTiles3D_setAmplitude);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_JumpTiles3D_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::JumpTiles3D *self = nullptr;

    olua_to_object(L, 1, &self, "cc.JumpTiles3D");

    // cocos2d::JumpTiles3D *clone()
    cocos2d::JumpTiles3D *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.JumpTiles3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_JumpTiles3D_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */
    unsigned int arg3 = 0;       /** numberOfJumps */
    float arg4 = 0;       /** amplitude */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Size");
    olua_check_integer(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // static cocos2d::JumpTiles3D *create(float duration, const cocos2d::Size &gridSize, unsigned int numberOfJumps, float amplitude)
    cocos2d::JumpTiles3D *ret = cocos2d::JumpTiles3D::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.JumpTiles3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_JumpTiles3D_getAmplitude(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::JumpTiles3D *self = nullptr;

    olua_to_object(L, 1, &self, "cc.JumpTiles3D");

    // float getAmplitude()
    float ret = self->getAmplitude();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_JumpTiles3D_setAmplitude(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::JumpTiles3D *self = nullptr;
    float arg1 = 0;       /** amplitude */

    olua_to_object(L, 1, &self, "cc.JumpTiles3D");
    olua_check_number(L, 2, &arg1);

    // void setAmplitude(float amplitude)
    self->setAmplitude(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_JumpTiles3D(lua_State *L)
{
    oluacls_class<cocos2d::JumpTiles3D, cocos2d::TiledGrid3DAction>(L, "cc.JumpTiles3D");
    oluacls_func(L, "clone", _cocos2d_JumpTiles3D_clone);
    oluacls_func(L, "create", _cocos2d_JumpTiles3D_create);
    oluacls_func(L, "getAmplitude", _cocos2d_JumpTiles3D_getAmplitude);
    oluacls_func(L, "setAmplitude", _cocos2d_JumpTiles3D_setAmplitude);
    oluacls_prop(L, "amplitude", _cocos2d_JumpTiles3D_getAmplitude, _cocos2d_JumpTiles3D_setAmplitude);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_SplitRows_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::SplitRows *self = nullptr;

    olua_to_object(L, 1, &self, "cc.SplitRows");

    // cocos2d::SplitRows *clone()
    cocos2d::SplitRows *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.SplitRows");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_SplitRows_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    unsigned int arg2 = 0;       /** rows */

    olua_check_number(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);

    // static cocos2d::SplitRows *create(float duration, unsigned int rows)
    cocos2d::SplitRows *ret = cocos2d::SplitRows::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.SplitRows");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_SplitRows(lua_State *L)
{
    oluacls_class<cocos2d::SplitRows, cocos2d::TiledGrid3DAction>(L, "cc.SplitRows");
    oluacls_func(L, "clone", _cocos2d_SplitRows_clone);
    oluacls_func(L, "create", _cocos2d_SplitRows_create);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_SplitCols_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::SplitCols *self = nullptr;

    olua_to_object(L, 1, &self, "cc.SplitCols");

    // cocos2d::SplitCols *clone()
    cocos2d::SplitCols *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.SplitCols");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_SplitCols_create(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** duration */
    unsigned int arg2 = 0;       /** cols */

    olua_check_number(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);

    // static cocos2d::SplitCols *create(float duration, unsigned int cols)
    cocos2d::SplitCols *ret = cocos2d::SplitCols::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.SplitCols");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_SplitCols(lua_State *L)
{
    oluacls_class<cocos2d::SplitCols, cocos2d::TiledGrid3DAction>(L, "cc.SplitCols");
    oluacls_func(L, "clone", _cocos2d_SplitCols_clone);
    oluacls_func(L, "create", _cocos2d_SplitCols_create);

    return 1;
}
OLUA_END_DECLS

static int _cocos2d_LuaTweenNode_as(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::LuaTweenNode *self = nullptr;
    const char *arg1 = nullptr;       /** cls */

    olua_to_object(L, 1, &self, "cc.LuaTweenNode");
    olua_check_string(L, 2, &arg1);

    do {
        if (olua_isa(L, 1, arg1)) {
            lua_pushvalue(L, 1);
            break;
        }
        if (olua_strequal(arg1, "cc.ActionTweenDelegate")) {
            olua_pushobj_as<cocos2d::ActionTweenDelegate>(L, 1, self, "as.cc.ActionTweenDelegate");
            break;
        }

        luaL_error(L, "'cocos2d::LuaTweenNode' can't cast to '%s'", arg1);
    } while (0);

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_LuaTweenNode_create(lua_State *L)
{
    olua_startinvoke(L);

    std::function<void (float, const std::string &)> arg1;       /** callback */

    olua_check_callback(L, 1, &arg1, "std.function");

    void *cb_store = (void *)olua_newobjstub(L, "cc.LuaTweenNode");
    std::string cb_tag = "ActionTween";
    std::string cb_name = olua_setcallback(L, cb_store,  1, cb_tag.c_str(), OLUA_TAG_NEW);
    olua_Context cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](float arg1, const std::string &arg2) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_number(L, arg1);
            olua_push_string(L, arg2);

            olua_callback(L, cb_store, cb_name.c_str(), 2);

            lua_settop(L, top);
        }
    };

    // static cocos2d::LuaTweenNode *create(@localvar const std::function<void (float, const std::string &)> &callback)
    cocos2d::LuaTweenNode *ret = cocos2d::LuaTweenNode::create(arg1);
    if (olua_pushobjstub(L, ret, cb_store, "cc.LuaTweenNode") == OLUA_OBJ_EXIST) {
        lua_pushstring(L, cb_name.c_str());
        lua_pushvalue(L, 1);
        olua_setvariable(L, -3);
    } else {
        olua_postpush(L, ret, OLUA_OBJ_NEW);
    };

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_LuaTweenNode_updateTweenAction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::LuaTweenNode *self = nullptr;
    float arg1 = 0;       /** value */
    std::string arg2;       /** key */

    olua_to_object(L, 1, &self, "cc.LuaTweenNode");
    olua_check_number(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // void updateTweenAction(float value, const std::string &key)
    self->updateTweenAction(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_LuaTweenNode(lua_State *L)
{
    oluacls_class<cocos2d::LuaTweenNode, cocos2d::Node>(L, "cc.LuaTweenNode");
    oluacls_func(L, "as", _cocos2d_LuaTweenNode_as);
    oluacls_func(L, "create", _cocos2d_LuaTweenNode_create);
    oluacls_func(L, "updateTweenAction", _cocos2d_LuaTweenNode_updateTweenAction);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_action(lua_State *L)
{
    olua_require(L, "cc.tweenfunc.TweenType", luaopen_cocos2d_tweenfunc_TweenType);
    olua_require(L, "cc.Action", luaopen_cocos2d_Action);
    olua_require(L, "cc.ActionTweenDelegate", luaopen_cocos2d_ActionTweenDelegate);
    olua_require(L, "cc.FiniteTimeAction", luaopen_cocos2d_FiniteTimeAction);
    olua_require(L, "cc.Speed", luaopen_cocos2d_Speed);
    olua_require(L, "cc.Follow", luaopen_cocos2d_Follow);
    olua_require(L, "cc.tweenfunc", luaopen_cocos2d_tweenfunc);
    olua_require(L, "cc.ActionInterval", luaopen_cocos2d_ActionInterval);
    olua_require(L, "cc.ActionTween", luaopen_cocos2d_ActionTween);
    olua_require(L, "cc.Sequence", luaopen_cocos2d_Sequence);
    olua_require(L, "cc.Repeat", luaopen_cocos2d_Repeat);
    olua_require(L, "cc.RepeatForever", luaopen_cocos2d_RepeatForever);
    olua_require(L, "cc.Spawn", luaopen_cocos2d_Spawn);
    olua_require(L, "cc.RotateTo", luaopen_cocos2d_RotateTo);
    olua_require(L, "cc.RotateFrom", luaopen_cocos2d_RotateFrom);
    olua_require(L, "cc.RotateBy", luaopen_cocos2d_RotateBy);
    olua_require(L, "cc.MoveBy", luaopen_cocos2d_MoveBy);
    olua_require(L, "cc.MoveTo", luaopen_cocos2d_MoveTo);
    olua_require(L, "cc.MoveFrom", luaopen_cocos2d_MoveFrom);
    olua_require(L, "cc.SkewTo", luaopen_cocos2d_SkewTo);
    olua_require(L, "cc.SkewBy", luaopen_cocos2d_SkewBy);
    olua_require(L, "cc.ResizeTo", luaopen_cocos2d_ResizeTo);
    olua_require(L, "cc.ResizeBy", luaopen_cocos2d_ResizeBy);
    olua_require(L, "cc.BezierBy", luaopen_cocos2d_BezierBy);
    olua_require(L, "cc.BezierTo", luaopen_cocos2d_BezierTo);
    olua_require(L, "cc.JumpBy", luaopen_cocos2d_JumpBy);
    olua_require(L, "cc.JumpTo", luaopen_cocos2d_JumpTo);
    olua_require(L, "cc.ScaleTo", luaopen_cocos2d_ScaleTo);
    olua_require(L, "cc.ScaleBy", luaopen_cocos2d_ScaleBy);
    olua_require(L, "cc.ScaleFrom", luaopen_cocos2d_ScaleFrom);
    olua_require(L, "cc.Blink", luaopen_cocos2d_Blink);
    olua_require(L, "cc.FadeTo", luaopen_cocos2d_FadeTo);
    olua_require(L, "cc.FadeFrom", luaopen_cocos2d_FadeFrom);
    olua_require(L, "cc.FadeIn", luaopen_cocos2d_FadeIn);
    olua_require(L, "cc.FadeOut", luaopen_cocos2d_FadeOut);
    olua_require(L, "cc.TintTo", luaopen_cocos2d_TintTo);
    olua_require(L, "cc.TintBy", luaopen_cocos2d_TintBy);
    olua_require(L, "cc.DelayTime", luaopen_cocos2d_DelayTime);
    olua_require(L, "cc.ReverseTime", luaopen_cocos2d_ReverseTime);
    olua_require(L, "cc.Animate", luaopen_cocos2d_Animate);
    olua_require(L, "cc.TargetedAction", luaopen_cocos2d_TargetedAction);
    olua_require(L, "cc.ActionFloat.ActionFloatCallback", luaopen_cocos2d_ActionFloat_ActionFloatCallback);
    olua_require(L, "cc.ActionFloat", luaopen_cocos2d_ActionFloat);
    olua_require(L, "cc.ProgressTo", luaopen_cocos2d_ProgressTo);
    olua_require(L, "cc.ProgressFromTo", luaopen_cocos2d_ProgressFromTo);
    olua_require(L, "cc.ActionEase", luaopen_cocos2d_ActionEase);
    olua_require(L, "cc.EaseRateAction", luaopen_cocos2d_EaseRateAction);
    olua_require(L, "cc.EaseExponentialIn", luaopen_cocos2d_EaseExponentialIn);
    olua_require(L, "cc.EaseExponentialOut", luaopen_cocos2d_EaseExponentialOut);
    olua_require(L, "cc.EaseExponentialInOut", luaopen_cocos2d_EaseExponentialInOut);
    olua_require(L, "cc.EaseSineIn", luaopen_cocos2d_EaseSineIn);
    olua_require(L, "cc.EaseSineOut", luaopen_cocos2d_EaseSineOut);
    olua_require(L, "cc.EaseSineInOut", luaopen_cocos2d_EaseSineInOut);
    olua_require(L, "cc.EaseBounceIn", luaopen_cocos2d_EaseBounceIn);
    olua_require(L, "cc.EaseBounceOut", luaopen_cocos2d_EaseBounceOut);
    olua_require(L, "cc.EaseBounceInOut", luaopen_cocos2d_EaseBounceInOut);
    olua_require(L, "cc.EaseBackIn", luaopen_cocos2d_EaseBackIn);
    olua_require(L, "cc.EaseBackOut", luaopen_cocos2d_EaseBackOut);
    olua_require(L, "cc.EaseBackInOut", luaopen_cocos2d_EaseBackInOut);
    olua_require(L, "cc.EaseQuadraticActionIn", luaopen_cocos2d_EaseQuadraticActionIn);
    olua_require(L, "cc.EaseQuadraticActionOut", luaopen_cocos2d_EaseQuadraticActionOut);
    olua_require(L, "cc.EaseQuadraticActionInOut", luaopen_cocos2d_EaseQuadraticActionInOut);
    olua_require(L, "cc.EaseQuarticActionIn", luaopen_cocos2d_EaseQuarticActionIn);
    olua_require(L, "cc.EaseQuarticActionOut", luaopen_cocos2d_EaseQuarticActionOut);
    olua_require(L, "cc.EaseQuarticActionInOut", luaopen_cocos2d_EaseQuarticActionInOut);
    olua_require(L, "cc.EaseQuinticActionIn", luaopen_cocos2d_EaseQuinticActionIn);
    olua_require(L, "cc.EaseQuinticActionOut", luaopen_cocos2d_EaseQuinticActionOut);
    olua_require(L, "cc.EaseQuinticActionInOut", luaopen_cocos2d_EaseQuinticActionInOut);
    olua_require(L, "cc.EaseCircleActionIn", luaopen_cocos2d_EaseCircleActionIn);
    olua_require(L, "cc.EaseCircleActionOut", luaopen_cocos2d_EaseCircleActionOut);
    olua_require(L, "cc.EaseCircleActionInOut", luaopen_cocos2d_EaseCircleActionInOut);
    olua_require(L, "cc.EaseCubicActionIn", luaopen_cocos2d_EaseCubicActionIn);
    olua_require(L, "cc.EaseCubicActionOut", luaopen_cocos2d_EaseCubicActionOut);
    olua_require(L, "cc.EaseCubicActionInOut", luaopen_cocos2d_EaseCubicActionInOut);
    olua_require(L, "cc.EaseIn", luaopen_cocos2d_EaseIn);
    olua_require(L, "cc.EaseOut", luaopen_cocos2d_EaseOut);
    olua_require(L, "cc.EaseInOut", luaopen_cocos2d_EaseInOut);
    olua_require(L, "cc.EaseElastic", luaopen_cocos2d_EaseElastic);
    olua_require(L, "cc.EaseElasticIn", luaopen_cocos2d_EaseElasticIn);
    olua_require(L, "cc.EaseElasticOut", luaopen_cocos2d_EaseElasticOut);
    olua_require(L, "cc.EaseElasticInOut", luaopen_cocos2d_EaseElasticInOut);
    olua_require(L, "cc.EaseBezierAction", luaopen_cocos2d_EaseBezierAction);
    olua_require(L, "cc.PointArray", luaopen_cocos2d_PointArray);
    olua_require(L, "cc.CardinalSplineTo", luaopen_cocos2d_CardinalSplineTo);
    olua_require(L, "cc.CardinalSplineBy", luaopen_cocos2d_CardinalSplineBy);
    olua_require(L, "cc.CatmullRomTo", luaopen_cocos2d_CatmullRomTo);
    olua_require(L, "cc.CatmullRomBy", luaopen_cocos2d_CatmullRomBy);
    olua_require(L, "cc.ActionInstant", luaopen_cocos2d_ActionInstant);
    olua_require(L, "cc.Show", luaopen_cocos2d_Show);
    olua_require(L, "cc.Hide", luaopen_cocos2d_Hide);
    olua_require(L, "cc.ToggleVisibility", luaopen_cocos2d_ToggleVisibility);
    olua_require(L, "cc.RemoveSelf", luaopen_cocos2d_RemoveSelf);
    olua_require(L, "cc.FlipX", luaopen_cocos2d_FlipX);
    olua_require(L, "cc.FlipY", luaopen_cocos2d_FlipY);
    olua_require(L, "cc.Place", luaopen_cocos2d_Place);
    olua_require(L, "cc.CallFunc", luaopen_cocos2d_CallFunc);
    olua_require(L, "cc.ActionCamera", luaopen_cocos2d_ActionCamera);
    olua_require(L, "cc.OrbitCamera", luaopen_cocos2d_OrbitCamera);
    olua_require(L, "cc.GridBase", luaopen_cocos2d_GridBase);
    olua_require(L, "cc.Grid3D", luaopen_cocos2d_Grid3D);
    olua_require(L, "cc.TiledGrid3D", luaopen_cocos2d_TiledGrid3D);
    olua_require(L, "cc.NodeGrid", luaopen_cocos2d_NodeGrid);
    olua_require(L, "cc.GridAction", luaopen_cocos2d_GridAction);
    olua_require(L, "cc.Grid3DAction", luaopen_cocos2d_Grid3DAction);
    olua_require(L, "cc.TiledGrid3DAction", luaopen_cocos2d_TiledGrid3DAction);
    olua_require(L, "cc.AccelDeccelAmplitude", luaopen_cocos2d_AccelDeccelAmplitude);
    olua_require(L, "cc.AccelAmplitude", luaopen_cocos2d_AccelAmplitude);
    olua_require(L, "cc.DeccelAmplitude", luaopen_cocos2d_DeccelAmplitude);
    olua_require(L, "cc.StopGrid", luaopen_cocos2d_StopGrid);
    olua_require(L, "cc.ReuseGrid", luaopen_cocos2d_ReuseGrid);
    olua_require(L, "cc.Waves3D", luaopen_cocos2d_Waves3D);
    olua_require(L, "cc.FlipX3D", luaopen_cocos2d_FlipX3D);
    olua_require(L, "cc.FlipY3D", luaopen_cocos2d_FlipY3D);
    olua_require(L, "cc.Lens3D", luaopen_cocos2d_Lens3D);
    olua_require(L, "cc.Ripple3D", luaopen_cocos2d_Ripple3D);
    olua_require(L, "cc.Shaky3D", luaopen_cocos2d_Shaky3D);
    olua_require(L, "cc.Liquid", luaopen_cocos2d_Liquid);
    olua_require(L, "cc.Waves", luaopen_cocos2d_Waves);
    olua_require(L, "cc.Twirl", luaopen_cocos2d_Twirl);
    olua_require(L, "cc.PageTurn3D", luaopen_cocos2d_PageTurn3D);
    olua_require(L, "cc.ShakyTiles3D", luaopen_cocos2d_ShakyTiles3D);
    olua_require(L, "cc.ShatteredTiles3D", luaopen_cocos2d_ShatteredTiles3D);
    olua_require(L, "cc.ShuffleTiles", luaopen_cocos2d_ShuffleTiles);
    olua_require(L, "cc.FadeOutTRTiles", luaopen_cocos2d_FadeOutTRTiles);
    olua_require(L, "cc.FadeOutBLTiles", luaopen_cocos2d_FadeOutBLTiles);
    olua_require(L, "cc.FadeOutUpTiles", luaopen_cocos2d_FadeOutUpTiles);
    olua_require(L, "cc.FadeOutDownTiles", luaopen_cocos2d_FadeOutDownTiles);
    olua_require(L, "cc.TurnOffTiles", luaopen_cocos2d_TurnOffTiles);
    olua_require(L, "cc.WavesTiles3D", luaopen_cocos2d_WavesTiles3D);
    olua_require(L, "cc.JumpTiles3D", luaopen_cocos2d_JumpTiles3D);
    olua_require(L, "cc.SplitRows", luaopen_cocos2d_SplitRows);
    olua_require(L, "cc.SplitCols", luaopen_cocos2d_SplitCols);
    olua_require(L, "cc.LuaTweenNode", luaopen_cocos2d_LuaTweenNode);

    return 0;
}
OLUA_END_DECLS
