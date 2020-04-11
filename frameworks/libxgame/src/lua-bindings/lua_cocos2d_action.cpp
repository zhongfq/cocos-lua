//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua-bindings/lua_cocos2d.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cocos2d.h"
#include "xgame/xlua.h"

static int _cocos2d_Action___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Action *)olua_toobj(L, 1, "cc.Action");
    olua_push_cppobj(L, self, "cc.Action");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_Action_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.Action");

    // cocos2d::Action *clone()
    cocos2d::Action *ret = (cocos2d::Action *)self->clone();
    int num_ret = olua_push_cppobj(L, ret, "cc.Action");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Action_description(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.Action");

    // std::string description()
    std::string ret = (std::string)self->description();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Action_getFlags(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.Action");

    // unsigned int getFlags()
    unsigned int ret = (unsigned int)self->getFlags();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Action_getOriginalTarget(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.Action");

    // cocos2d::Node *getOriginalTarget()
    cocos2d::Node *ret = (cocos2d::Node *)self->getOriginalTarget();
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Action_getTag(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.Action");

    // int getTag()
    int ret = (int)self->getTag();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Action_getTarget(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.Action");

    // cocos2d::Node *getTarget()
    cocos2d::Node *ret = (cocos2d::Node *)self->getTarget();
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Action_isDone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.Action");

    // bool isDone()
    bool ret = (bool)self->isDone();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Action_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.Action");

    // cocos2d::Action *reverse()
    cocos2d::Action *ret = (cocos2d::Action *)self->reverse();
    int num_ret = olua_push_cppobj(L, ret, "cc.Action");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Action_setFlags(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;
    lua_Unsigned arg1 = 0;       /** flags */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Action");
    olua_check_uint(L, 2, &arg1);

    // void setFlags(unsigned int flags)
    self->setFlags((unsigned int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_Action_setOriginalTarget(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** originalTarget */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Action");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Node");

    // void setOriginalTarget(cocos2d::Node *originalTarget)
    self->setOriginalTarget(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_Action_setTag(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;
    lua_Integer arg1 = 0;       /** tag */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Action");
    olua_check_int(L, 2, &arg1);

    // void setTag(int tag)
    self->setTag((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_Action_setTarget(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** target */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Action");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Node");

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.Action");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Node");

    // void startWithTarget(cocos2d::Node *target)
    self->startWithTarget(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_Action_step(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;
    lua_Number arg1 = 0;       /** dt */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Action");
    olua_check_number(L, 2, &arg1);

    // void step(float dt)
    self->step((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_Action_stop(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.Action");

    // void stop()
    self->stop();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_Action_update(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *self = nullptr;
    lua_Number arg1 = 0;       /** time */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Action");
    olua_check_number(L, 2, &arg1);

    // void update(float time)
    self->update((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_Action(lua_State *L)
{
    oluacls_class(L, "cc.Action", "cc.Ref");
    oluacls_func(L, "__move", _cocos2d_Action___move);
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
    oluacls_const_integer(L, "INVALID_TAG", (lua_Integer)cocos2d::Action::INVALID_TAG);

    olua_registerluatype<cocos2d::Action>(L, "cc.Action");

    return 1;
}

static int _cocos2d_FiniteTimeAction___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::FiniteTimeAction *)olua_toobj(L, 1, "cc.FiniteTimeAction");
    olua_push_cppobj(L, self, "cc.FiniteTimeAction");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_FiniteTimeAction_getDuration(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.FiniteTimeAction");

    // float getDuration()
    float ret = (float)self->getDuration();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_FiniteTimeAction_setDuration(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *self = nullptr;
    lua_Number arg1 = 0;       /** duration */

    olua_to_cppobj(L, 1, (void **)&self, "cc.FiniteTimeAction");
    olua_check_number(L, 2, &arg1);

    // void setDuration(float duration)
    self->setDuration((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_FiniteTimeAction(lua_State *L)
{
    oluacls_class(L, "cc.FiniteTimeAction", "cc.Action");
    oluacls_func(L, "__move", _cocos2d_FiniteTimeAction___move);
    oluacls_func(L, "getDuration", _cocos2d_FiniteTimeAction_getDuration);
    oluacls_func(L, "setDuration", _cocos2d_FiniteTimeAction_setDuration);
    oluacls_prop(L, "duration", _cocos2d_FiniteTimeAction_getDuration, _cocos2d_FiniteTimeAction_setDuration);

    olua_registerluatype<cocos2d::FiniteTimeAction>(L, "cc.FiniteTimeAction");

    return 1;
}

static int _cocos2d_Speed___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Speed *)olua_toobj(L, 1, "cc.Speed");
    olua_push_cppobj(L, self, "cc.Speed");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_Speed_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */
    lua_Number arg2 = 0;       /** speed */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");
    olua_check_number(L, 2, &arg2);

    // static cocos2d::Speed *create(@addref(innerAction ^) cocos2d::ActionInterval *action, float speed)
    cocos2d::Speed *ret = (cocos2d::Speed *)cocos2d::Speed::create(arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.Speed");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Speed_getInnerAction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Speed *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.Speed");

    // @addref(innerAction ^) cocos2d::ActionInterval *getInnerAction()
    cocos2d::ActionInterval *ret = (cocos2d::ActionInterval *)self->getInnerAction();
    int num_ret = olua_push_cppobj(L, ret, "cc.ActionInterval");

    // inject code after call
    olua_addref(L, 1, "innerAction", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Speed_getSpeed(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Speed *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.Speed");

    // float getSpeed()
    float ret = (float)self->getSpeed();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Speed_setInnerAction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Speed *self = nullptr;
    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Speed");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.ActionInterval");

    // void setInnerAction(@addref(innerAction ^) cocos2d::ActionInterval *action)
    self->setInnerAction(arg1);

    // inject code after call
    olua_addref(L, 1, "innerAction", 2, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_Speed_setSpeed(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Speed *self = nullptr;
    lua_Number arg1 = 0;       /** speed */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Speed");
    olua_check_number(L, 2, &arg1);

    // void setSpeed(float speed)
    self->setSpeed((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_Speed(lua_State *L)
{
    oluacls_class(L, "cc.Speed", "cc.Action");
    oluacls_func(L, "__move", _cocos2d_Speed___move);
    oluacls_func(L, "create", _cocos2d_Speed_create);
    oluacls_func(L, "getInnerAction", _cocos2d_Speed_getInnerAction);
    oluacls_func(L, "getSpeed", _cocos2d_Speed_getSpeed);
    oluacls_func(L, "setInnerAction", _cocos2d_Speed_setInnerAction);
    oluacls_func(L, "setSpeed", _cocos2d_Speed_setSpeed);
    oluacls_prop(L, "innerAction", _cocos2d_Speed_getInnerAction, _cocos2d_Speed_setInnerAction);
    oluacls_prop(L, "speed", _cocos2d_Speed_getSpeed, _cocos2d_Speed_setSpeed);

    olua_registerluatype<cocos2d::Speed>(L, "cc.Speed");

    return 1;
}

static int _cocos2d_Follow___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Follow *)olua_toobj(L, 1, "cc.Follow");
    olua_push_cppobj(L, self, "cc.Follow");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_Follow_create1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Node *arg1 = nullptr;       /** followedNode */
    cocos2d::Rect arg2;       /** rect */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Node");
    manual_olua_check_cocos2d_Rect(L, 2, &arg2);

    // static cocos2d::Follow *create(cocos2d::Node *followedNode, @optional const cocos2d::Rect &rect)
    cocos2d::Follow *ret = (cocos2d::Follow *)cocos2d::Follow::create(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.Follow");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Follow_create2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Node *arg1 = nullptr;       /** followedNode */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Node");

    // static cocos2d::Follow *create(cocos2d::Node *followedNode, @optional const cocos2d::Rect &rect)
    cocos2d::Follow *ret = (cocos2d::Follow *)cocos2d::Follow::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.Follow");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Follow_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 1, "cc.Node"))) {
            // static cocos2d::Follow *create(cocos2d::Node *followedNode, @optional const cocos2d::Rect &rect)
            return _cocos2d_Follow_create2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 1, "cc.Node")) && (manual_olua_is_cocos2d_Rect(L, 2))) {
            // static cocos2d::Follow *create(cocos2d::Node *followedNode, @optional const cocos2d::Rect &rect)
            return _cocos2d_Follow_create1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Follow::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_Follow_createWithOffset1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Node *arg1 = nullptr;       /** followedNode */
    lua_Number arg2 = 0;       /** xOffset */
    lua_Number arg3 = 0;       /** yOffset */
    cocos2d::Rect arg4;       /** rect */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Node");
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    manual_olua_check_cocos2d_Rect(L, 4, &arg4);

    // static cocos2d::Follow *createWithOffset(cocos2d::Node *followedNode, float xOffset, float yOffset, @optional const cocos2d::Rect &rect)
    cocos2d::Follow *ret = (cocos2d::Follow *)cocos2d::Follow::createWithOffset(arg1, (float)arg2, (float)arg3, arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.Follow");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Follow_createWithOffset2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Node *arg1 = nullptr;       /** followedNode */
    lua_Number arg2 = 0;       /** xOffset */
    lua_Number arg3 = 0;       /** yOffset */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Node");
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static cocos2d::Follow *createWithOffset(cocos2d::Node *followedNode, float xOffset, float yOffset, @optional const cocos2d::Rect &rect)
    cocos2d::Follow *ret = (cocos2d::Follow *)cocos2d::Follow::createWithOffset(arg1, (float)arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "cc.Follow");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Follow_createWithOffset(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 3) {
        // if ((olua_is_cppobj(L, 1, "cc.Node")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // static cocos2d::Follow *createWithOffset(cocos2d::Node *followedNode, float xOffset, float yOffset, @optional const cocos2d::Rect &rect)
            return _cocos2d_Follow_createWithOffset2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_cppobj(L, 1, "cc.Node")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (manual_olua_is_cocos2d_Rect(L, 4))) {
            // static cocos2d::Follow *createWithOffset(cocos2d::Node *followedNode, float xOffset, float yOffset, @optional const cocos2d::Rect &rect)
            return _cocos2d_Follow_createWithOffset1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Follow::createWithOffset' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_Follow_initWithTarget1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Follow *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** followedNode */
    cocos2d::Rect arg2;       /** rect */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Follow");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Node");
    manual_olua_check_cocos2d_Rect(L, 3, &arg2);

    // bool initWithTarget(cocos2d::Node *followedNode, @optional const cocos2d::Rect &rect)
    bool ret = (bool)self->initWithTarget(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Follow_initWithTarget2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Follow *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** followedNode */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Follow");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Node");

    // bool initWithTarget(cocos2d::Node *followedNode, @optional const cocos2d::Rect &rect)
    bool ret = (bool)self->initWithTarget(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Follow_initWithTarget(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 2, "cc.Node"))) {
            // bool initWithTarget(cocos2d::Node *followedNode, @optional const cocos2d::Rect &rect)
            return _cocos2d_Follow_initWithTarget2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 2, "cc.Node")) && (manual_olua_is_cocos2d_Rect(L, 3))) {
            // bool initWithTarget(cocos2d::Node *followedNode, @optional const cocos2d::Rect &rect)
            return _cocos2d_Follow_initWithTarget1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Follow::initWithTarget' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_Follow_initWithTargetAndOffset1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Follow *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** followedNode */
    lua_Number arg2 = 0;       /** xOffset */
    lua_Number arg3 = 0;       /** yOffset */
    cocos2d::Rect arg4;       /** rect */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Follow");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Node");
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    manual_olua_check_cocos2d_Rect(L, 5, &arg4);

    // bool initWithTargetAndOffset(cocos2d::Node *followedNode, float xOffset, float yOffset, @optional const cocos2d::Rect &rect)
    bool ret = (bool)self->initWithTargetAndOffset(arg1, (float)arg2, (float)arg3, arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Follow_initWithTargetAndOffset2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Follow *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** followedNode */
    lua_Number arg2 = 0;       /** xOffset */
    lua_Number arg3 = 0;       /** yOffset */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Follow");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Node");
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // bool initWithTargetAndOffset(cocos2d::Node *followedNode, float xOffset, float yOffset, @optional const cocos2d::Rect &rect)
    bool ret = (bool)self->initWithTargetAndOffset(arg1, (float)arg2, (float)arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Follow_initWithTargetAndOffset(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 3) {
        // if ((olua_is_cppobj(L, 2, "cc.Node")) && (olua_is_number(L, 3)) && (olua_is_number(L, 4))) {
            // bool initWithTargetAndOffset(cocos2d::Node *followedNode, float xOffset, float yOffset, @optional const cocos2d::Rect &rect)
            return _cocos2d_Follow_initWithTargetAndOffset2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_cppobj(L, 2, "cc.Node")) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (manual_olua_is_cocos2d_Rect(L, 5))) {
            // bool initWithTargetAndOffset(cocos2d::Node *followedNode, float xOffset, float yOffset, @optional const cocos2d::Rect &rect)
            return _cocos2d_Follow_initWithTargetAndOffset1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Follow::initWithTargetAndOffset' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_Follow_isBoundarySet(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Follow *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.Follow");

    // bool isBoundarySet()
    bool ret = (bool)self->isBoundarySet();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Follow_setBoundarySet(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Follow *self = nullptr;
    bool arg1 = false;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Follow");
    olua_check_bool(L, 2, &arg1);

    // void setBoundarySet(bool value)
    self->setBoundarySet(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_Follow(lua_State *L)
{
    oluacls_class(L, "cc.Follow", "cc.Action");
    oluacls_func(L, "__move", _cocos2d_Follow___move);
    oluacls_func(L, "create", _cocos2d_Follow_create);
    oluacls_func(L, "createWithOffset", _cocos2d_Follow_createWithOffset);
    oluacls_func(L, "initWithTarget", _cocos2d_Follow_initWithTarget);
    oluacls_func(L, "initWithTargetAndOffset", _cocos2d_Follow_initWithTargetAndOffset);
    oluacls_func(L, "isBoundarySet", _cocos2d_Follow_isBoundarySet);
    oluacls_func(L, "setBoundarySet", _cocos2d_Follow_setBoundarySet);
    oluacls_prop(L, "boundarySet", _cocos2d_Follow_isBoundarySet, _cocos2d_Follow_setBoundarySet);

    olua_registerluatype<cocos2d::Follow>(L, "cc.Follow");

    return 1;
}

static int _cocos2d_tweenfunc_backEaseIn(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float backEaseIn(float time)
    float ret = (float)cocos2d::tweenfunc::backEaseIn((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_backEaseInOut(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float backEaseInOut(float time)
    float ret = (float)cocos2d::tweenfunc::backEaseInOut((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_backEaseOut(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float backEaseOut(float time)
    float ret = (float)cocos2d::tweenfunc::backEaseOut((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_bezieratFunction(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** a */
    lua_Number arg2 = 0;       /** b */
    lua_Number arg3 = 0;       /** c */
    lua_Number arg4 = 0;       /** d */
    lua_Number arg5 = 0;       /** t */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);
    olua_check_number(L, 5, &arg5);

    // static float bezieratFunction(float a, float b, float c, float d, float t)
    float ret = (float)cocos2d::tweenfunc::bezieratFunction((float)arg1, (float)arg2, (float)arg3, (float)arg4, (float)arg5);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_bounceEaseIn(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float bounceEaseIn(float time)
    float ret = (float)cocos2d::tweenfunc::bounceEaseIn((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_bounceEaseInOut(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float bounceEaseInOut(float time)
    float ret = (float)cocos2d::tweenfunc::bounceEaseInOut((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_bounceEaseOut(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float bounceEaseOut(float time)
    float ret = (float)cocos2d::tweenfunc::bounceEaseOut((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_circEaseIn(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float circEaseIn(float time)
    float ret = (float)cocos2d::tweenfunc::circEaseIn((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_circEaseInOut(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float circEaseInOut(float time)
    float ret = (float)cocos2d::tweenfunc::circEaseInOut((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_circEaseOut(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float circEaseOut(float time)
    float ret = (float)cocos2d::tweenfunc::circEaseOut((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_cubicEaseIn(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float cubicEaseIn(float time)
    float ret = (float)cocos2d::tweenfunc::cubicEaseIn((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_cubicEaseInOut(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float cubicEaseInOut(float time)
    float ret = (float)cocos2d::tweenfunc::cubicEaseInOut((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_cubicEaseOut(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float cubicEaseOut(float time)
    float ret = (float)cocos2d::tweenfunc::cubicEaseOut((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_easeIn(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */
    lua_Number arg2 = 0;       /** rate */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static float easeIn(float time, float rate)
    float ret = (float)cocos2d::tweenfunc::easeIn((float)arg1, (float)arg2);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_easeInOut(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */
    lua_Number arg2 = 0;       /** rate */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static float easeInOut(float time, float rate)
    float ret = (float)cocos2d::tweenfunc::easeInOut((float)arg1, (float)arg2);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_easeOut(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */
    lua_Number arg2 = 0;       /** rate */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static float easeOut(float time, float rate)
    float ret = (float)cocos2d::tweenfunc::easeOut((float)arg1, (float)arg2);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_elasticEaseIn(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */
    lua_Number arg2 = 0;       /** period */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static float elasticEaseIn(float time, float period)
    float ret = (float)cocos2d::tweenfunc::elasticEaseIn((float)arg1, (float)arg2);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_elasticEaseInOut(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */
    lua_Number arg2 = 0;       /** period */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static float elasticEaseInOut(float time, float period)
    float ret = (float)cocos2d::tweenfunc::elasticEaseInOut((float)arg1, (float)arg2);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_elasticEaseOut(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */
    lua_Number arg2 = 0;       /** period */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static float elasticEaseOut(float time, float period)
    float ret = (float)cocos2d::tweenfunc::elasticEaseOut((float)arg1, (float)arg2);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_expoEaseIn(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float expoEaseIn(float time)
    float ret = (float)cocos2d::tweenfunc::expoEaseIn((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_expoEaseInOut(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float expoEaseInOut(float time)
    float ret = (float)cocos2d::tweenfunc::expoEaseInOut((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_expoEaseOut(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float expoEaseOut(float time)
    float ret = (float)cocos2d::tweenfunc::expoEaseOut((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_linear(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float linear(float time)
    float ret = (float)cocos2d::tweenfunc::linear((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_quadEaseIn(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float quadEaseIn(float time)
    float ret = (float)cocos2d::tweenfunc::quadEaseIn((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_quadEaseInOut(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float quadEaseInOut(float time)
    float ret = (float)cocos2d::tweenfunc::quadEaseInOut((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_quadEaseOut(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float quadEaseOut(float time)
    float ret = (float)cocos2d::tweenfunc::quadEaseOut((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_quadraticIn(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float quadraticIn(float time)
    float ret = (float)cocos2d::tweenfunc::quadraticIn((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_quadraticInOut(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float quadraticInOut(float time)
    float ret = (float)cocos2d::tweenfunc::quadraticInOut((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_quadraticOut(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float quadraticOut(float time)
    float ret = (float)cocos2d::tweenfunc::quadraticOut((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_quartEaseIn(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float quartEaseIn(float time)
    float ret = (float)cocos2d::tweenfunc::quartEaseIn((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_quartEaseInOut(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float quartEaseInOut(float time)
    float ret = (float)cocos2d::tweenfunc::quartEaseInOut((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_quartEaseOut(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float quartEaseOut(float time)
    float ret = (float)cocos2d::tweenfunc::quartEaseOut((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_quintEaseIn(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float quintEaseIn(float time)
    float ret = (float)cocos2d::tweenfunc::quintEaseIn((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_quintEaseInOut(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float quintEaseInOut(float time)
    float ret = (float)cocos2d::tweenfunc::quintEaseInOut((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_quintEaseOut(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float quintEaseOut(float time)
    float ret = (float)cocos2d::tweenfunc::quintEaseOut((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_sineEaseIn(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float sineEaseIn(float time)
    float ret = (float)cocos2d::tweenfunc::sineEaseIn((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_sineEaseInOut(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float sineEaseInOut(float time)
    float ret = (float)cocos2d::tweenfunc::sineEaseInOut((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_tweenfunc_sineEaseOut(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */

    olua_check_number(L, 1, &arg1);

    // static float sineEaseOut(float time)
    float ret = (float)cocos2d::tweenfunc::sineEaseOut((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_tweenfunc(lua_State *L)
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

    return 1;
}

static int _cocos2d_ActionInterval___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ActionInterval *)olua_toobj(L, 1, "cc.ActionInterval");
    olua_push_cppobj(L, self, "cc.ActionInterval");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ActionInterval_getAmplitudeRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.ActionInterval");

    // float getAmplitudeRate()
    float ret = (float)self->getAmplitudeRate();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ActionInterval_getElapsed(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.ActionInterval");

    // float getElapsed()
    float ret = (float)self->getElapsed();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ActionInterval_setAmplitudeRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *self = nullptr;
    lua_Number arg1 = 0;       /** amp */

    olua_to_cppobj(L, 1, (void **)&self, "cc.ActionInterval");
    olua_check_number(L, 2, &arg1);

    // void setAmplitudeRate(float amp)
    self->setAmplitudeRate((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ActionInterval(lua_State *L)
{
    oluacls_class(L, "cc.ActionInterval", "cc.FiniteTimeAction");
    oluacls_func(L, "__move", _cocos2d_ActionInterval___move);
    oluacls_func(L, "getAmplitudeRate", _cocos2d_ActionInterval_getAmplitudeRate);
    oluacls_func(L, "getElapsed", _cocos2d_ActionInterval_getElapsed);
    oluacls_func(L, "setAmplitudeRate", _cocos2d_ActionInterval_setAmplitudeRate);
    oluacls_prop(L, "amplitudeRate", _cocos2d_ActionInterval_getAmplitudeRate, _cocos2d_ActionInterval_setAmplitudeRate);
    oluacls_prop(L, "elapsed", _cocos2d_ActionInterval_getElapsed, nullptr);

    olua_registerluatype<cocos2d::ActionInterval>(L, "cc.ActionInterval");

    return 1;
}

static int _cocos2d_Sequence___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Sequence *)olua_toobj(L, 1, "cc.Sequence");
    olua_push_cppobj(L, self, "cc.Sequence");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_Sequence_create(lua_State *L)
{
    olua_startinvoke(L);

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

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_Sequence_createWithTwoActions(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** actionOne */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** actionTwo */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.FiniteTimeAction");
    olua_check_cppobj(L, 2, (void **)&arg2, "cc.FiniteTimeAction");

    // static cocos2d::Sequence *createWithTwoActions(@addref(autoref |) cocos2d::FiniteTimeAction *actionOne, @addref(autoref |) cocos2d::FiniteTimeAction *actionTwo)
    cocos2d::Sequence *ret = (cocos2d::Sequence *)cocos2d::Sequence::createWithTwoActions(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.Sequence");

    // inject code after call
    olua_addref(L, -1, "autoref", 1, OLUA_MODE_MULTIPLE);
    olua_addref(L, -1, "autoref", 2, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_Sequence(lua_State *L)
{
    oluacls_class(L, "cc.Sequence", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_Sequence___move);
    oluacls_func(L, "create", _cocos2d_Sequence_create);
    oluacls_func(L, "createWithTwoActions", _cocos2d_Sequence_createWithTwoActions);

    olua_registerluatype<cocos2d::Sequence>(L, "cc.Sequence");

    return 1;
}

static int _cocos2d_Repeat___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Repeat *)olua_toobj(L, 1, "cc.Repeat");
    olua_push_cppobj(L, self, "cc.Repeat");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_Repeat_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action */
    lua_Unsigned arg2 = 0;       /** times */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.FiniteTimeAction");
    olua_check_uint(L, 2, &arg2);

    // static cocos2d::Repeat *create(@addref(innerAction ^) cocos2d::FiniteTimeAction *action, unsigned int times)
    cocos2d::Repeat *ret = (cocos2d::Repeat *)cocos2d::Repeat::create(arg1, (unsigned int)arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.Repeat");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Repeat_getInnerAction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Repeat *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.Repeat");

    // @addref(innerAction ^) cocos2d::FiniteTimeAction *getInnerAction()
    cocos2d::FiniteTimeAction *ret = (cocos2d::FiniteTimeAction *)self->getInnerAction();
    int num_ret = olua_push_cppobj(L, ret, "cc.FiniteTimeAction");

    // inject code after call
    olua_addref(L, 1, "innerAction", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Repeat_setInnerAction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Repeat *self = nullptr;
    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Repeat");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.FiniteTimeAction");

    // void setInnerAction(@addref(innerAction ^) cocos2d::FiniteTimeAction *action)
    self->setInnerAction(arg1);

    // inject code after call
    olua_addref(L, 1, "innerAction", 2, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_Repeat(lua_State *L)
{
    oluacls_class(L, "cc.Repeat", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_Repeat___move);
    oluacls_func(L, "create", _cocos2d_Repeat_create);
    oluacls_func(L, "getInnerAction", _cocos2d_Repeat_getInnerAction);
    oluacls_func(L, "setInnerAction", _cocos2d_Repeat_setInnerAction);
    oluacls_prop(L, "innerAction", _cocos2d_Repeat_getInnerAction, _cocos2d_Repeat_setInnerAction);

    olua_registerluatype<cocos2d::Repeat>(L, "cc.Repeat");

    return 1;
}

static int _cocos2d_RepeatForever___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::RepeatForever *)olua_toobj(L, 1, "cc.RepeatForever");
    olua_push_cppobj(L, self, "cc.RepeatForever");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_RepeatForever_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::RepeatForever *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::RepeatForever *ret = (cocos2d::RepeatForever *)cocos2d::RepeatForever::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.RepeatForever");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_RepeatForever_getInnerAction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::RepeatForever *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.RepeatForever");

    // @addref(innerAction ^) cocos2d::ActionInterval *getInnerAction()
    cocos2d::ActionInterval *ret = (cocos2d::ActionInterval *)self->getInnerAction();
    int num_ret = olua_push_cppobj(L, ret, "cc.ActionInterval");

    // inject code after call
    olua_addref(L, 1, "innerAction", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_RepeatForever_setInnerAction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::RepeatForever *self = nullptr;
    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_to_cppobj(L, 1, (void **)&self, "cc.RepeatForever");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.ActionInterval");

    // void setInnerAction(@addref(innerAction ^) cocos2d::ActionInterval *action)
    self->setInnerAction(arg1);

    // inject code after call
    olua_addref(L, 1, "innerAction", 2, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_RepeatForever(lua_State *L)
{
    oluacls_class(L, "cc.RepeatForever", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_RepeatForever___move);
    oluacls_func(L, "create", _cocos2d_RepeatForever_create);
    oluacls_func(L, "getInnerAction", _cocos2d_RepeatForever_getInnerAction);
    oluacls_func(L, "setInnerAction", _cocos2d_RepeatForever_setInnerAction);
    oluacls_prop(L, "innerAction", _cocos2d_RepeatForever_getInnerAction, _cocos2d_RepeatForever_setInnerAction);

    olua_registerluatype<cocos2d::RepeatForever>(L, "cc.RepeatForever");

    return 1;
}

static int _cocos2d_Spawn___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Spawn *)olua_toobj(L, 1, "cc.Spawn");
    olua_push_cppobj(L, self, "cc.Spawn");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_Spawn_create(lua_State *L)
{
    olua_startinvoke(L);

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

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_Spawn_createWithTwoActions(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action1 */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action2 */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.FiniteTimeAction");
    olua_check_cppobj(L, 2, (void **)&arg2, "cc.FiniteTimeAction");

    // static cocos2d::Spawn *createWithTwoActions(@addref(autoref |) cocos2d::FiniteTimeAction *action1, @addref(autoref |) cocos2d::FiniteTimeAction *action2)
    cocos2d::Spawn *ret = (cocos2d::Spawn *)cocos2d::Spawn::createWithTwoActions(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.Spawn");

    // inject code after call
    olua_addref(L, -1, "autoref", 1, OLUA_MODE_MULTIPLE);
    olua_addref(L, -1, "autoref", 2, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_Spawn(lua_State *L)
{
    oluacls_class(L, "cc.Spawn", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_Spawn___move);
    oluacls_func(L, "create", _cocos2d_Spawn_create);
    oluacls_func(L, "createWithTwoActions", _cocos2d_Spawn_createWithTwoActions);

    olua_registerluatype<cocos2d::Spawn>(L, "cc.Spawn");

    return 1;
}

static int _cocos2d_RotateTo___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::RotateTo *)olua_toobj(L, 1, "cc.RotateTo");
    olua_push_cppobj(L, self, "cc.RotateTo");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_RotateTo_create1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    lua_Number arg2 = 0;       /** dstAngleX */
    lua_Number arg3 = 0;       /** dstAngleY */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static cocos2d::RotateTo *create(float duration, float dstAngleX, float dstAngleY)
    cocos2d::RotateTo *ret = (cocos2d::RotateTo *)cocos2d::RotateTo::create((float)arg1, (float)arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "cc.RotateTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_RotateTo_create2(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    lua_Number arg2 = 0;       /** dstAngle */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static cocos2d::RotateTo *create(float duration, float dstAngle)
    cocos2d::RotateTo *ret = (cocos2d::RotateTo *)cocos2d::RotateTo::create((float)arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.RotateTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_RotateTo_create3(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Vec3 arg2;       /** dstAngle3D */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Vec3(L, 2, &arg2);

    // static cocos2d::RotateTo *create(float duration, const cocos2d::Vec3 &dstAngle3D)
    cocos2d::RotateTo *ret = (cocos2d::RotateTo *)cocos2d::RotateTo::create((float)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.RotateTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_RotateTo_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_number(L, 1)) && (auto_olua_is_cocos2d_Vec3(L, 2))) {
            // static cocos2d::RotateTo *create(float duration, const cocos2d::Vec3 &dstAngle3D)
            return _cocos2d_RotateTo_create3(L);
        }

        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2))) {
            // static cocos2d::RotateTo *create(float duration, float dstAngle)
            return _cocos2d_RotateTo_create2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // static cocos2d::RotateTo *create(float duration, float dstAngleX, float dstAngleY)
            return _cocos2d_RotateTo_create1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::RotateTo::create' not support '%d' arguments", num_args);

    return 0;
}

static int luaopen_cocos2d_RotateTo(lua_State *L)
{
    oluacls_class(L, "cc.RotateTo", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_RotateTo___move);
    oluacls_func(L, "create", _cocos2d_RotateTo_create);

    olua_registerluatype<cocos2d::RotateTo>(L, "cc.RotateTo");

    return 1;
}

static int _cocos2d_RotateBy___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::RotateBy *)olua_toobj(L, 1, "cc.RotateBy");
    olua_push_cppobj(L, self, "cc.RotateBy");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_RotateBy_create1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    lua_Number arg2 = 0;       /** deltaAngle */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static cocos2d::RotateBy *create(float duration, float deltaAngle)
    cocos2d::RotateBy *ret = (cocos2d::RotateBy *)cocos2d::RotateBy::create((float)arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.RotateBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_RotateBy_create2(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    lua_Number arg2 = 0;       /** deltaAngleZ_X */
    lua_Number arg3 = 0;       /** deltaAngleZ_Y */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static cocos2d::RotateBy *create(float duration, float deltaAngleZ_X, float deltaAngleZ_Y)
    cocos2d::RotateBy *ret = (cocos2d::RotateBy *)cocos2d::RotateBy::create((float)arg1, (float)arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "cc.RotateBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_RotateBy_create3(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Vec3 arg2;       /** deltaAngle3D */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Vec3(L, 2, &arg2);

    // static cocos2d::RotateBy *create(float duration, const cocos2d::Vec3 &deltaAngle3D)
    cocos2d::RotateBy *ret = (cocos2d::RotateBy *)cocos2d::RotateBy::create((float)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.RotateBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_RotateBy_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_number(L, 1)) && (auto_olua_is_cocos2d_Vec3(L, 2))) {
            // static cocos2d::RotateBy *create(float duration, const cocos2d::Vec3 &deltaAngle3D)
            return _cocos2d_RotateBy_create3(L);
        }

        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2))) {
            // static cocos2d::RotateBy *create(float duration, float deltaAngle)
            return _cocos2d_RotateBy_create1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // static cocos2d::RotateBy *create(float duration, float deltaAngleZ_X, float deltaAngleZ_Y)
            return _cocos2d_RotateBy_create2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::RotateBy::create' not support '%d' arguments", num_args);

    return 0;
}

static int luaopen_cocos2d_RotateBy(lua_State *L)
{
    oluacls_class(L, "cc.RotateBy", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_RotateBy___move);
    oluacls_func(L, "create", _cocos2d_RotateBy_create);

    olua_registerluatype<cocos2d::RotateBy>(L, "cc.RotateBy");

    return 1;
}

static int _cocos2d_MoveBy___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::MoveBy *)olua_toobj(L, 1, "cc.MoveBy");
    olua_push_cppobj(L, self, "cc.MoveBy");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_MoveBy_create1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Vec2 arg2;       /** deltaPosition */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Vec2(L, 2, &arg2);

    // static cocos2d::MoveBy *create(float duration, const cocos2d::Vec2 &deltaPosition)
    cocos2d::MoveBy *ret = (cocos2d::MoveBy *)cocos2d::MoveBy::create((float)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.MoveBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_MoveBy_create2(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Vec2 arg2;       /** deltaPosition */

    olua_check_number(L, 1, &arg1);
    auto_olua_pack_cocos2d_Vec2(L, 2, &arg2);

    // static cocos2d::MoveBy *create(float duration, @pack const cocos2d::Vec2 &deltaPosition)
    cocos2d::MoveBy *ret = (cocos2d::MoveBy *)cocos2d::MoveBy::create((float)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.MoveBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_MoveBy_create3(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Vec3 arg2;       /** deltaPosition */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Vec3(L, 2, &arg2);

    // static cocos2d::MoveBy *create(float duration, const cocos2d::Vec3 &deltaPosition)
    cocos2d::MoveBy *ret = (cocos2d::MoveBy *)cocos2d::MoveBy::create((float)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.MoveBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_MoveBy_create4(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Vec3 arg2;       /** deltaPosition */

    olua_check_number(L, 1, &arg1);
    auto_olua_pack_cocos2d_Vec3(L, 2, &arg2);

    // static cocos2d::MoveBy *create(float duration, @pack const cocos2d::Vec3 &deltaPosition)
    cocos2d::MoveBy *ret = (cocos2d::MoveBy *)cocos2d::MoveBy::create((float)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.MoveBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_MoveBy_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_number(L, 1)) && (auto_olua_is_cocos2d_Vec3(L, 2))) {
            // static cocos2d::MoveBy *create(float duration, const cocos2d::Vec3 &deltaPosition)
            return _cocos2d_MoveBy_create3(L);
        }

        // if ((olua_is_number(L, 1)) && (auto_olua_is_cocos2d_Vec2(L, 2))) {
            // static cocos2d::MoveBy *create(float duration, const cocos2d::Vec2 &deltaPosition)
            return _cocos2d_MoveBy_create1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (auto_olua_ispack_cocos2d_Vec2(L, 2))) {
            // static cocos2d::MoveBy *create(float duration, @pack const cocos2d::Vec2 &deltaPosition)
            return _cocos2d_MoveBy_create2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_number(L, 1)) && (auto_olua_ispack_cocos2d_Vec3(L, 2))) {
            // static cocos2d::MoveBy *create(float duration, @pack const cocos2d::Vec3 &deltaPosition)
            return _cocos2d_MoveBy_create4(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::MoveBy::create' not support '%d' arguments", num_args);

    return 0;
}

static int luaopen_cocos2d_MoveBy(lua_State *L)
{
    oluacls_class(L, "cc.MoveBy", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_MoveBy___move);
    oluacls_func(L, "create", _cocos2d_MoveBy_create);

    olua_registerluatype<cocos2d::MoveBy>(L, "cc.MoveBy");

    return 1;
}

static int _cocos2d_MoveTo___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::MoveTo *)olua_toobj(L, 1, "cc.MoveTo");
    olua_push_cppobj(L, self, "cc.MoveTo");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_MoveTo_create1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Vec2 arg2;       /** position */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Vec2(L, 2, &arg2);

    // static cocos2d::MoveTo *create(float duration, const cocos2d::Vec2 &position)
    cocos2d::MoveTo *ret = (cocos2d::MoveTo *)cocos2d::MoveTo::create((float)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.MoveTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_MoveTo_create2(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Vec2 arg2;       /** position */

    olua_check_number(L, 1, &arg1);
    auto_olua_pack_cocos2d_Vec2(L, 2, &arg2);

    // static cocos2d::MoveTo *create(float duration, @pack const cocos2d::Vec2 &position)
    cocos2d::MoveTo *ret = (cocos2d::MoveTo *)cocos2d::MoveTo::create((float)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.MoveTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_MoveTo_create3(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Vec3 arg2;       /** position */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Vec3(L, 2, &arg2);

    // static cocos2d::MoveTo *create(float duration, const cocos2d::Vec3 &position)
    cocos2d::MoveTo *ret = (cocos2d::MoveTo *)cocos2d::MoveTo::create((float)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.MoveTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_MoveTo_create4(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Vec3 arg2;       /** position */

    olua_check_number(L, 1, &arg1);
    auto_olua_pack_cocos2d_Vec3(L, 2, &arg2);

    // static cocos2d::MoveTo *create(float duration, @pack const cocos2d::Vec3 &position)
    cocos2d::MoveTo *ret = (cocos2d::MoveTo *)cocos2d::MoveTo::create((float)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.MoveTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_MoveTo_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_number(L, 1)) && (auto_olua_is_cocos2d_Vec3(L, 2))) {
            // static cocos2d::MoveTo *create(float duration, const cocos2d::Vec3 &position)
            return _cocos2d_MoveTo_create3(L);
        }

        // if ((olua_is_number(L, 1)) && (auto_olua_is_cocos2d_Vec2(L, 2))) {
            // static cocos2d::MoveTo *create(float duration, const cocos2d::Vec2 &position)
            return _cocos2d_MoveTo_create1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (auto_olua_ispack_cocos2d_Vec2(L, 2))) {
            // static cocos2d::MoveTo *create(float duration, @pack const cocos2d::Vec2 &position)
            return _cocos2d_MoveTo_create2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_number(L, 1)) && (auto_olua_ispack_cocos2d_Vec3(L, 2))) {
            // static cocos2d::MoveTo *create(float duration, @pack const cocos2d::Vec3 &position)
            return _cocos2d_MoveTo_create4(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::MoveTo::create' not support '%d' arguments", num_args);

    return 0;
}

static int luaopen_cocos2d_MoveTo(lua_State *L)
{
    oluacls_class(L, "cc.MoveTo", "cc.MoveBy");
    oluacls_func(L, "__move", _cocos2d_MoveTo___move);
    oluacls_func(L, "create", _cocos2d_MoveTo_create);

    olua_registerluatype<cocos2d::MoveTo>(L, "cc.MoveTo");

    return 1;
}

static int _cocos2d_SkewTo___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::SkewTo *)olua_toobj(L, 1, "cc.SkewTo");
    olua_push_cppobj(L, self, "cc.SkewTo");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_SkewTo_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** t */
    lua_Number arg2 = 0;       /** sx */
    lua_Number arg3 = 0;       /** sy */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static cocos2d::SkewTo *create(float t, float sx, float sy)
    cocos2d::SkewTo *ret = (cocos2d::SkewTo *)cocos2d::SkewTo::create((float)arg1, (float)arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "cc.SkewTo");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_SkewTo(lua_State *L)
{
    oluacls_class(L, "cc.SkewTo", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_SkewTo___move);
    oluacls_func(L, "create", _cocos2d_SkewTo_create);

    olua_registerluatype<cocos2d::SkewTo>(L, "cc.SkewTo");

    return 1;
}

static int _cocos2d_SkewBy___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::SkewBy *)olua_toobj(L, 1, "cc.SkewBy");
    olua_push_cppobj(L, self, "cc.SkewBy");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_SkewBy_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** t */
    lua_Number arg2 = 0;       /** deltaSkewX */
    lua_Number arg3 = 0;       /** deltaSkewY */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static cocos2d::SkewBy *create(float t, float deltaSkewX, float deltaSkewY)
    cocos2d::SkewBy *ret = (cocos2d::SkewBy *)cocos2d::SkewBy::create((float)arg1, (float)arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "cc.SkewBy");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_SkewBy(lua_State *L)
{
    oluacls_class(L, "cc.SkewBy", "cc.SkewTo");
    oluacls_func(L, "__move", _cocos2d_SkewBy___move);
    oluacls_func(L, "create", _cocos2d_SkewBy_create);

    olua_registerluatype<cocos2d::SkewBy>(L, "cc.SkewBy");

    return 1;
}

static int _cocos2d_ResizeTo___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ResizeTo *)olua_toobj(L, 1, "cc.ResizeTo");
    olua_push_cppobj(L, self, "cc.ResizeTo");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ResizeTo_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** final_size */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Size(L, 2, &arg2);

    // static cocos2d::ResizeTo *create(float duration, const cocos2d::Size &final_size)
    cocos2d::ResizeTo *ret = (cocos2d::ResizeTo *)cocos2d::ResizeTo::create((float)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.ResizeTo");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_ResizeTo(lua_State *L)
{
    oluacls_class(L, "cc.ResizeTo", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_ResizeTo___move);
    oluacls_func(L, "create", _cocos2d_ResizeTo_create);

    olua_registerluatype<cocos2d::ResizeTo>(L, "cc.ResizeTo");

    return 1;
}

static int _cocos2d_ResizeBy___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ResizeBy *)olua_toobj(L, 1, "cc.ResizeBy");
    olua_push_cppobj(L, self, "cc.ResizeBy");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ResizeBy_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** deltaSize */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Size(L, 2, &arg2);

    // static cocos2d::ResizeBy *create(float duration, const cocos2d::Size &deltaSize)
    cocos2d::ResizeBy *ret = (cocos2d::ResizeBy *)cocos2d::ResizeBy::create((float)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.ResizeBy");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_ResizeBy(lua_State *L)
{
    oluacls_class(L, "cc.ResizeBy", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_ResizeBy___move);
    oluacls_func(L, "create", _cocos2d_ResizeBy_create);

    olua_registerluatype<cocos2d::ResizeBy>(L, "cc.ResizeBy");

    return 1;
}

static int _cocos2d_BezierBy___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::BezierBy *)olua_toobj(L, 1, "cc.BezierBy");
    olua_push_cppobj(L, self, "cc.BezierBy");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_BezierBy_create1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** t */
    cocos2d::ccBezierConfig arg2;       /** c */

    olua_check_number(L, 1, &arg1);
    manual_olua_check_cocos2d_ccBezierConfig(L, 2, &arg2);

    // static cocos2d::BezierBy *create(float t, const cocos2d::ccBezierConfig &c)
    cocos2d::BezierBy *ret = (cocos2d::BezierBy *)cocos2d::BezierBy::create((float)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.BezierBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_BezierBy_create2(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** t */
    cocos2d::ccBezierConfig arg2;       /** c */

    olua_check_number(L, 1, &arg1);
    manual_olua_pack_cocos2d_ccBezierConfig(L, 2, &arg2);

    // static cocos2d::BezierBy *create(float t, @pack const cocos2d::ccBezierConfig &c)
    cocos2d::BezierBy *ret = (cocos2d::BezierBy *)cocos2d::BezierBy::create((float)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.BezierBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_BezierBy_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_number(L, 1)) && (manual_olua_is_cocos2d_ccBezierConfig(L, 2))) {
            // static cocos2d::BezierBy *create(float t, const cocos2d::ccBezierConfig &c)
            return _cocos2d_BezierBy_create1(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_number(L, 1)) && (manual_olua_ispack_cocos2d_ccBezierConfig(L, 2))) {
            // static cocos2d::BezierBy *create(float t, @pack const cocos2d::ccBezierConfig &c)
            return _cocos2d_BezierBy_create2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::BezierBy::create' not support '%d' arguments", num_args);

    return 0;
}

static int luaopen_cocos2d_BezierBy(lua_State *L)
{
    oluacls_class(L, "cc.BezierBy", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_BezierBy___move);
    oluacls_func(L, "create", _cocos2d_BezierBy_create);

    olua_registerluatype<cocos2d::BezierBy>(L, "cc.BezierBy");

    return 1;
}

static int _cocos2d_BezierTo___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::BezierTo *)olua_toobj(L, 1, "cc.BezierTo");
    olua_push_cppobj(L, self, "cc.BezierTo");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_BezierTo_create1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** t */
    cocos2d::ccBezierConfig arg2;       /** c */

    olua_check_number(L, 1, &arg1);
    manual_olua_check_cocos2d_ccBezierConfig(L, 2, &arg2);

    // static cocos2d::BezierTo *create(float t, const cocos2d::ccBezierConfig &c)
    cocos2d::BezierTo *ret = (cocos2d::BezierTo *)cocos2d::BezierTo::create((float)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.BezierTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_BezierTo_create2(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** t */
    cocos2d::ccBezierConfig arg2;       /** c */

    olua_check_number(L, 1, &arg1);
    manual_olua_pack_cocos2d_ccBezierConfig(L, 2, &arg2);

    // static cocos2d::BezierTo *create(float t, @pack const cocos2d::ccBezierConfig &c)
    cocos2d::BezierTo *ret = (cocos2d::BezierTo *)cocos2d::BezierTo::create((float)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.BezierTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_BezierTo_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_number(L, 1)) && (manual_olua_is_cocos2d_ccBezierConfig(L, 2))) {
            // static cocos2d::BezierTo *create(float t, const cocos2d::ccBezierConfig &c)
            return _cocos2d_BezierTo_create1(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_number(L, 1)) && (manual_olua_ispack_cocos2d_ccBezierConfig(L, 2))) {
            // static cocos2d::BezierTo *create(float t, @pack const cocos2d::ccBezierConfig &c)
            return _cocos2d_BezierTo_create2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::BezierTo::create' not support '%d' arguments", num_args);

    return 0;
}

static int luaopen_cocos2d_BezierTo(lua_State *L)
{
    oluacls_class(L, "cc.BezierTo", "cc.BezierBy");
    oluacls_func(L, "__move", _cocos2d_BezierTo___move);
    oluacls_func(L, "create", _cocos2d_BezierTo_create);

    olua_registerluatype<cocos2d::BezierTo>(L, "cc.BezierTo");

    return 1;
}

static int _cocos2d_JumpBy___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::JumpBy *)olua_toobj(L, 1, "cc.JumpBy");
    olua_push_cppobj(L, self, "cc.JumpBy");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_JumpBy_create1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Vec2 arg2;       /** position */
    lua_Number arg3 = 0;       /** height */
    lua_Integer arg4 = 0;       /** jumps */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Vec2(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_int(L, 4, &arg4);

    // static cocos2d::JumpBy *create(float duration, const cocos2d::Vec2 &position, float height, int jumps)
    cocos2d::JumpBy *ret = (cocos2d::JumpBy *)cocos2d::JumpBy::create((float)arg1, arg2, (float)arg3, (int)arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.JumpBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_JumpBy_create2(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Vec2 arg2;       /** position */
    lua_Number arg3 = 0;       /** height */
    lua_Integer arg4 = 0;       /** jumps */

    olua_check_number(L, 1, &arg1);
    auto_olua_pack_cocos2d_Vec2(L, 2, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_int(L, 5, &arg4);

    // static cocos2d::JumpBy *create(float duration, @pack const cocos2d::Vec2 &position, float height, int jumps)
    cocos2d::JumpBy *ret = (cocos2d::JumpBy *)cocos2d::JumpBy::create((float)arg1, arg2, (float)arg3, (int)arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.JumpBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_JumpBy_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 4) {
        // if ((olua_is_number(L, 1)) && (auto_olua_is_cocos2d_Vec2(L, 2)) && (olua_is_number(L, 3)) && (olua_is_int(L, 4))) {
            // static cocos2d::JumpBy *create(float duration, const cocos2d::Vec2 &position, float height, int jumps)
            return _cocos2d_JumpBy_create1(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_number(L, 1)) && (auto_olua_ispack_cocos2d_Vec2(L, 2)) && (olua_is_number(L, 3)) && (olua_is_int(L, 4))) {
            // static cocos2d::JumpBy *create(float duration, @pack const cocos2d::Vec2 &position, float height, int jumps)
            return _cocos2d_JumpBy_create2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::JumpBy::create' not support '%d' arguments", num_args);

    return 0;
}

static int luaopen_cocos2d_JumpBy(lua_State *L)
{
    oluacls_class(L, "cc.JumpBy", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_JumpBy___move);
    oluacls_func(L, "create", _cocos2d_JumpBy_create);

    olua_registerluatype<cocos2d::JumpBy>(L, "cc.JumpBy");

    return 1;
}

static int _cocos2d_JumpTo___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::JumpTo *)olua_toobj(L, 1, "cc.JumpTo");
    olua_push_cppobj(L, self, "cc.JumpTo");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_JumpTo_create1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Vec2 arg2;       /** position */
    lua_Number arg3 = 0;       /** height */
    lua_Integer arg4 = 0;       /** jumps */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Vec2(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_int(L, 4, &arg4);

    // static cocos2d::JumpTo *create(float duration, const cocos2d::Vec2 &position, float height, int jumps)
    cocos2d::JumpTo *ret = (cocos2d::JumpTo *)cocos2d::JumpTo::create((float)arg1, arg2, (float)arg3, (int)arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.JumpTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_JumpTo_create2(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Vec2 arg2;       /** position */
    lua_Number arg3 = 0;       /** height */
    lua_Integer arg4 = 0;       /** jumps */

    olua_check_number(L, 1, &arg1);
    auto_olua_pack_cocos2d_Vec2(L, 2, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_int(L, 5, &arg4);

    // static cocos2d::JumpTo *create(float duration, @pack const cocos2d::Vec2 &position, float height, int jumps)
    cocos2d::JumpTo *ret = (cocos2d::JumpTo *)cocos2d::JumpTo::create((float)arg1, arg2, (float)arg3, (int)arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.JumpTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_JumpTo_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 4) {
        // if ((olua_is_number(L, 1)) && (auto_olua_is_cocos2d_Vec2(L, 2)) && (olua_is_number(L, 3)) && (olua_is_int(L, 4))) {
            // static cocos2d::JumpTo *create(float duration, const cocos2d::Vec2 &position, float height, int jumps)
            return _cocos2d_JumpTo_create1(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_number(L, 1)) && (auto_olua_ispack_cocos2d_Vec2(L, 2)) && (olua_is_number(L, 3)) && (olua_is_int(L, 4))) {
            // static cocos2d::JumpTo *create(float duration, @pack const cocos2d::Vec2 &position, float height, int jumps)
            return _cocos2d_JumpTo_create2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::JumpTo::create' not support '%d' arguments", num_args);

    return 0;
}

static int luaopen_cocos2d_JumpTo(lua_State *L)
{
    oluacls_class(L, "cc.JumpTo", "cc.JumpBy");
    oluacls_func(L, "__move", _cocos2d_JumpTo___move);
    oluacls_func(L, "create", _cocos2d_JumpTo_create);

    olua_registerluatype<cocos2d::JumpTo>(L, "cc.JumpTo");

    return 1;
}

static int _cocos2d_ScaleTo___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ScaleTo *)olua_toobj(L, 1, "cc.ScaleTo");
    olua_push_cppobj(L, self, "cc.ScaleTo");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ScaleTo_create1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    lua_Number arg2 = 0;       /** s */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static cocos2d::ScaleTo *create(float duration, float s)
    cocos2d::ScaleTo *ret = (cocos2d::ScaleTo *)cocos2d::ScaleTo::create((float)arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.ScaleTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ScaleTo_create2(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    lua_Number arg2 = 0;       /** sx */
    lua_Number arg3 = 0;       /** sy */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static cocos2d::ScaleTo *create(float duration, float sx, float sy)
    cocos2d::ScaleTo *ret = (cocos2d::ScaleTo *)cocos2d::ScaleTo::create((float)arg1, (float)arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "cc.ScaleTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ScaleTo_create3(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    lua_Number arg2 = 0;       /** sx */
    lua_Number arg3 = 0;       /** sy */
    lua_Number arg4 = 0;       /** sz */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // static cocos2d::ScaleTo *create(float duration, float sx, float sy, float sz)
    cocos2d::ScaleTo *ret = (cocos2d::ScaleTo *)cocos2d::ScaleTo::create((float)arg1, (float)arg2, (float)arg3, (float)arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.ScaleTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ScaleTo_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2))) {
            // static cocos2d::ScaleTo *create(float duration, float s)
            return _cocos2d_ScaleTo_create1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // static cocos2d::ScaleTo *create(float duration, float sx, float sy)
            return _cocos2d_ScaleTo_create2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4))) {
            // static cocos2d::ScaleTo *create(float duration, float sx, float sy, float sz)
            return _cocos2d_ScaleTo_create3(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ScaleTo::create' not support '%d' arguments", num_args);

    return 0;
}

static int luaopen_cocos2d_ScaleTo(lua_State *L)
{
    oluacls_class(L, "cc.ScaleTo", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_ScaleTo___move);
    oluacls_func(L, "create", _cocos2d_ScaleTo_create);

    olua_registerluatype<cocos2d::ScaleTo>(L, "cc.ScaleTo");

    return 1;
}

static int _cocos2d_ScaleBy___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ScaleBy *)olua_toobj(L, 1, "cc.ScaleBy");
    olua_push_cppobj(L, self, "cc.ScaleBy");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ScaleBy_create1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    lua_Number arg2 = 0;       /** s */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static cocos2d::ScaleBy *create(float duration, float s)
    cocos2d::ScaleBy *ret = (cocos2d::ScaleBy *)cocos2d::ScaleBy::create((float)arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.ScaleBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ScaleBy_create2(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    lua_Number arg2 = 0;       /** sx */
    lua_Number arg3 = 0;       /** sy */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static cocos2d::ScaleBy *create(float duration, float sx, float sy)
    cocos2d::ScaleBy *ret = (cocos2d::ScaleBy *)cocos2d::ScaleBy::create((float)arg1, (float)arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "cc.ScaleBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ScaleBy_create3(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    lua_Number arg2 = 0;       /** sx */
    lua_Number arg3 = 0;       /** sy */
    lua_Number arg4 = 0;       /** sz */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // static cocos2d::ScaleBy *create(float duration, float sx, float sy, float sz)
    cocos2d::ScaleBy *ret = (cocos2d::ScaleBy *)cocos2d::ScaleBy::create((float)arg1, (float)arg2, (float)arg3, (float)arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.ScaleBy");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ScaleBy_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2))) {
            // static cocos2d::ScaleBy *create(float duration, float s)
            return _cocos2d_ScaleBy_create1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // static cocos2d::ScaleBy *create(float duration, float sx, float sy)
            return _cocos2d_ScaleBy_create2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4))) {
            // static cocos2d::ScaleBy *create(float duration, float sx, float sy, float sz)
            return _cocos2d_ScaleBy_create3(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ScaleBy::create' not support '%d' arguments", num_args);

    return 0;
}

static int luaopen_cocos2d_ScaleBy(lua_State *L)
{
    oluacls_class(L, "cc.ScaleBy", "cc.ScaleTo");
    oluacls_func(L, "__move", _cocos2d_ScaleBy___move);
    oluacls_func(L, "create", _cocos2d_ScaleBy_create);

    olua_registerluatype<cocos2d::ScaleBy>(L, "cc.ScaleBy");

    return 1;
}

static int _cocos2d_Blink___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Blink *)olua_toobj(L, 1, "cc.Blink");
    olua_push_cppobj(L, self, "cc.Blink");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_Blink_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    lua_Integer arg2 = 0;       /** blinks */

    olua_check_number(L, 1, &arg1);
    olua_check_int(L, 2, &arg2);

    // static cocos2d::Blink *create(float duration, int blinks)
    cocos2d::Blink *ret = (cocos2d::Blink *)cocos2d::Blink::create((float)arg1, (int)arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.Blink");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_Blink(lua_State *L)
{
    oluacls_class(L, "cc.Blink", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_Blink___move);
    oluacls_func(L, "create", _cocos2d_Blink_create);

    olua_registerluatype<cocos2d::Blink>(L, "cc.Blink");

    return 1;
}

static int _cocos2d_FadeTo___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::FadeTo *)olua_toobj(L, 1, "cc.FadeTo");
    olua_push_cppobj(L, self, "cc.FadeTo");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_FadeTo_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    lua_Unsigned arg2 = 0;       /** opacity */

    olua_check_number(L, 1, &arg1);
    olua_check_uint(L, 2, &arg2);

    // static cocos2d::FadeTo *create(float duration, uint8_t opacity)
    cocos2d::FadeTo *ret = (cocos2d::FadeTo *)cocos2d::FadeTo::create((float)arg1, (uint8_t)arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.FadeTo");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_FadeTo(lua_State *L)
{
    oluacls_class(L, "cc.FadeTo", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_FadeTo___move);
    oluacls_func(L, "create", _cocos2d_FadeTo_create);

    olua_registerluatype<cocos2d::FadeTo>(L, "cc.FadeTo");

    return 1;
}

static int _cocos2d_FadeIn___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::FadeIn *)olua_toobj(L, 1, "cc.FadeIn");
    olua_push_cppobj(L, self, "cc.FadeIn");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_FadeIn_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** d */

    olua_check_number(L, 1, &arg1);

    // static cocos2d::FadeIn *create(float d)
    cocos2d::FadeIn *ret = (cocos2d::FadeIn *)cocos2d::FadeIn::create((float)arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.FadeIn");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_FadeIn(lua_State *L)
{
    oluacls_class(L, "cc.FadeIn", "cc.FadeTo");
    oluacls_func(L, "__move", _cocos2d_FadeIn___move);
    oluacls_func(L, "create", _cocos2d_FadeIn_create);

    olua_registerluatype<cocos2d::FadeIn>(L, "cc.FadeIn");

    return 1;
}

static int _cocos2d_FadeOut___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::FadeOut *)olua_toobj(L, 1, "cc.FadeOut");
    olua_push_cppobj(L, self, "cc.FadeOut");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_FadeOut_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** d */

    olua_check_number(L, 1, &arg1);

    // static cocos2d::FadeOut *create(float d)
    cocos2d::FadeOut *ret = (cocos2d::FadeOut *)cocos2d::FadeOut::create((float)arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.FadeOut");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_FadeOut(lua_State *L)
{
    oluacls_class(L, "cc.FadeOut", "cc.FadeTo");
    oluacls_func(L, "__move", _cocos2d_FadeOut___move);
    oluacls_func(L, "create", _cocos2d_FadeOut_create);

    olua_registerluatype<cocos2d::FadeOut>(L, "cc.FadeOut");

    return 1;
}

static int _cocos2d_TintTo___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::TintTo *)olua_toobj(L, 1, "cc.TintTo");
    olua_push_cppobj(L, self, "cc.TintTo");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_TintTo_create1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    lua_Unsigned arg2 = 0;       /** red */
    lua_Unsigned arg3 = 0;       /** green */
    lua_Unsigned arg4 = 0;       /** blue */

    olua_check_number(L, 1, &arg1);
    olua_check_uint(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);
    olua_check_uint(L, 4, &arg4);

    // static cocos2d::TintTo *create(float duration, uint8_t red, uint8_t green, uint8_t blue)
    cocos2d::TintTo *ret = (cocos2d::TintTo *)cocos2d::TintTo::create((float)arg1, (uint8_t)arg2, (uint8_t)arg3, (uint8_t)arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.TintTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TintTo_create2(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Color3B arg2;       /** color */

    olua_check_number(L, 1, &arg1);
    manual_olua_check_cocos2d_Color3B(L, 2, &arg2);

    // static cocos2d::TintTo *create(float duration, const cocos2d::Color3B &color)
    cocos2d::TintTo *ret = (cocos2d::TintTo *)cocos2d::TintTo::create((float)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.TintTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TintTo_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_number(L, 1)) && (manual_olua_is_cocos2d_Color3B(L, 2))) {
            // static cocos2d::TintTo *create(float duration, const cocos2d::Color3B &color)
            return _cocos2d_TintTo_create2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_number(L, 1)) && (olua_is_uint(L, 2)) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // static cocos2d::TintTo *create(float duration, uint8_t red, uint8_t green, uint8_t blue)
            return _cocos2d_TintTo_create1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::TintTo::create' not support '%d' arguments", num_args);

    return 0;
}

static int luaopen_cocos2d_TintTo(lua_State *L)
{
    oluacls_class(L, "cc.TintTo", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_TintTo___move);
    oluacls_func(L, "create", _cocos2d_TintTo_create);

    olua_registerluatype<cocos2d::TintTo>(L, "cc.TintTo");

    return 1;
}

static int _cocos2d_TintBy___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::TintBy *)olua_toobj(L, 1, "cc.TintBy");
    olua_push_cppobj(L, self, "cc.TintBy");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_TintBy_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    lua_Integer arg2 = 0;       /** deltaRed */
    lua_Integer arg3 = 0;       /** deltaGreen */
    lua_Integer arg4 = 0;       /** deltaBlue */

    olua_check_number(L, 1, &arg1);
    olua_check_int(L, 2, &arg2);
    olua_check_int(L, 3, &arg3);
    olua_check_int(L, 4, &arg4);

    // static cocos2d::TintBy *create(float duration, int16_t deltaRed, int16_t deltaGreen, int16_t deltaBlue)
    cocos2d::TintBy *ret = (cocos2d::TintBy *)cocos2d::TintBy::create((float)arg1, (int16_t)arg2, (int16_t)arg3, (int16_t)arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.TintBy");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_TintBy(lua_State *L)
{
    oluacls_class(L, "cc.TintBy", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_TintBy___move);
    oluacls_func(L, "create", _cocos2d_TintBy_create);

    olua_registerluatype<cocos2d::TintBy>(L, "cc.TintBy");

    return 1;
}

static int _cocos2d_DelayTime___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::DelayTime *)olua_toobj(L, 1, "cc.DelayTime");
    olua_push_cppobj(L, self, "cc.DelayTime");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_DelayTime_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** d */

    olua_check_number(L, 1, &arg1);

    // static cocos2d::DelayTime *create(float d)
    cocos2d::DelayTime *ret = (cocos2d::DelayTime *)cocos2d::DelayTime::create((float)arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.DelayTime");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_DelayTime(lua_State *L)
{
    oluacls_class(L, "cc.DelayTime", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_DelayTime___move);
    oluacls_func(L, "create", _cocos2d_DelayTime_create);

    olua_registerluatype<cocos2d::DelayTime>(L, "cc.DelayTime");

    return 1;
}

static int _cocos2d_ReverseTime___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ReverseTime *)olua_toobj(L, 1, "cc.ReverseTime");
    olua_push_cppobj(L, self, "cc.ReverseTime");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ReverseTime_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FiniteTimeAction *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.FiniteTimeAction");

    // static cocos2d::ReverseTime *create(@addref(autoref |) cocos2d::FiniteTimeAction *action)
    cocos2d::ReverseTime *ret = (cocos2d::ReverseTime *)cocos2d::ReverseTime::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.ReverseTime");

    // inject code after call
    olua_addref(L, -1, "autoref", 1, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_ReverseTime(lua_State *L)
{
    oluacls_class(L, "cc.ReverseTime", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_ReverseTime___move);
    oluacls_func(L, "create", _cocos2d_ReverseTime_create);

    olua_registerluatype<cocos2d::ReverseTime>(L, "cc.ReverseTime");

    return 1;
}

static int _cocos2d_Animate___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Animate *)olua_toobj(L, 1, "cc.Animate");
    olua_push_cppobj(L, self, "cc.Animate");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_Animate_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Animation *arg1 = nullptr;       /** animation */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Animation");

    // static cocos2d::Animate *create(cocos2d::Animation *animation)
    cocos2d::Animate *ret = (cocos2d::Animate *)cocos2d::Animate::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.Animate");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Animate_getAnimation(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Animate *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.Animate");

    // cocos2d::Animation *getAnimation()
    cocos2d::Animation *ret = (cocos2d::Animation *)self->getAnimation();
    int num_ret = olua_push_cppobj(L, ret, "cc.Animation");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Animate_getCurrentFrameIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Animate *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.Animate");

    // int getCurrentFrameIndex()
    int ret = (int)self->getCurrentFrameIndex();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Animate_setAnimation(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Animate *self = nullptr;
    cocos2d::Animation *arg1 = nullptr;       /** animation */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Animate");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Animation");

    // void setAnimation(cocos2d::Animation *animation)
    self->setAnimation(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_Animate(lua_State *L)
{
    oluacls_class(L, "cc.Animate", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_Animate___move);
    oluacls_func(L, "create", _cocos2d_Animate_create);
    oluacls_func(L, "getAnimation", _cocos2d_Animate_getAnimation);
    oluacls_func(L, "getCurrentFrameIndex", _cocos2d_Animate_getCurrentFrameIndex);
    oluacls_func(L, "setAnimation", _cocos2d_Animate_setAnimation);
    oluacls_prop(L, "animation", _cocos2d_Animate_getAnimation, _cocos2d_Animate_setAnimation);
    oluacls_prop(L, "currentFrameIndex", _cocos2d_Animate_getCurrentFrameIndex, nullptr);

    olua_registerluatype<cocos2d::Animate>(L, "cc.Animate");

    return 1;
}

static int _cocos2d_TargetedAction___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::TargetedAction *)olua_toobj(L, 1, "cc.TargetedAction");
    olua_push_cppobj(L, self, "cc.TargetedAction");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_TargetedAction_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Node *arg1 = nullptr;       /** target */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Node");
    olua_check_cppobj(L, 2, (void **)&arg2, "cc.FiniteTimeAction");

    // static cocos2d::TargetedAction *create(cocos2d::Node *target, @addref(autoref |) cocos2d::FiniteTimeAction *action)
    cocos2d::TargetedAction *ret = (cocos2d::TargetedAction *)cocos2d::TargetedAction::create(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.TargetedAction");

    // inject code after call
    olua_addref(L, -1, "autoref", 2, OLUA_MODE_MULTIPLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TargetedAction_getForcedTarget(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TargetedAction *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.TargetedAction");

    // cocos2d::Node *getForcedTarget()
    cocos2d::Node *ret = (cocos2d::Node *)self->getForcedTarget();
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TargetedAction_initWithTarget(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TargetedAction *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** target */
    cocos2d::FiniteTimeAction *arg2 = nullptr;       /** action */

    olua_to_cppobj(L, 1, (void **)&self, "cc.TargetedAction");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Node");
    olua_check_cppobj(L, 3, (void **)&arg2, "cc.FiniteTimeAction");

    // bool initWithTarget(cocos2d::Node *target, cocos2d::FiniteTimeAction *action)
    bool ret = (bool)self->initWithTarget(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TargetedAction_setForcedTarget(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TargetedAction *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** forcedTarget */

    olua_to_cppobj(L, 1, (void **)&self, "cc.TargetedAction");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Node");

    // void setForcedTarget(cocos2d::Node *forcedTarget)
    self->setForcedTarget(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_TargetedAction(lua_State *L)
{
    oluacls_class(L, "cc.TargetedAction", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_TargetedAction___move);
    oluacls_func(L, "create", _cocos2d_TargetedAction_create);
    oluacls_func(L, "getForcedTarget", _cocos2d_TargetedAction_getForcedTarget);
    oluacls_func(L, "initWithTarget", _cocos2d_TargetedAction_initWithTarget);
    oluacls_func(L, "setForcedTarget", _cocos2d_TargetedAction_setForcedTarget);
    oluacls_prop(L, "forcedTarget", _cocos2d_TargetedAction_getForcedTarget, _cocos2d_TargetedAction_setForcedTarget);

    olua_registerluatype<cocos2d::TargetedAction>(L, "cc.TargetedAction");

    return 1;
}

static int _cocos2d_ActionFloat___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ActionFloat *)olua_toobj(L, 1, "cc.ActionFloat");
    olua_push_cppobj(L, self, "cc.ActionFloat");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ActionFloat_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    lua_Number arg2 = 0;       /** from */
    lua_Number arg3 = 0;       /** to */
    std::function<void(float)> arg4;       /** callback */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    void *callback_store_obj = (void *)olua_allocobjstub(L, "cc.ActionFloat");
    std::string tag = "ActionFloat";
    std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 4, OLUA_TAG_NEW);
    lua_State *MT = olua_mainthread();
    arg4 = [callback_store_obj, func, MT](float arg1) {
        lua_State *L = olua_mainthread();

        if (MT == L) {
            int top = lua_gettop(L);
            olua_push_number(L, (lua_Number)arg1);

            olua_callback(L, callback_store_obj, func.c_str(), 1);

            lua_settop(L, top);
        }
    };

    // static cocos2d::ActionFloat *create(float duration, float from, float to, @local std::function<void (float)> callback)
    cocos2d::ActionFloat *ret = (cocos2d::ActionFloat *)cocos2d::ActionFloat::create((float)arg1, (float)arg2, (float)arg3, arg4);
    const char *cls = olua_getluatype(L, ret, "cc.ActionFloat");
    if (olua_pushobjstub(L, ret, callback_store_obj, cls) == OLUA_OBJ_EXIST) {
        lua_pushstring(L, func.c_str());
        lua_pushvalue(L, 4);
        olua_setvariable(L, -3);
    } else {
        olua_postpush(L, ret, OLUA_OBJ_NEW);
    };

    olua_endinvoke(L);

    return 1;
}

static int luaopen_cocos2d_ActionFloat(lua_State *L)
{
    oluacls_class(L, "cc.ActionFloat", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_ActionFloat___move);
    oluacls_func(L, "create", _cocos2d_ActionFloat_create);

    olua_registerluatype<cocos2d::ActionFloat>(L, "cc.ActionFloat");

    return 1;
}

static int _cocos2d_ProgressTo___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ProgressTo *)olua_toobj(L, 1, "cc.ProgressTo");
    olua_push_cppobj(L, self, "cc.ProgressTo");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ProgressTo_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    lua_Number arg2 = 0;       /** percent */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static cocos2d::ProgressTo *create(float duration, float percent)
    cocos2d::ProgressTo *ret = (cocos2d::ProgressTo *)cocos2d::ProgressTo::create((float)arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.ProgressTo");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_ProgressTo(lua_State *L)
{
    oluacls_class(L, "cc.ProgressTo", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_ProgressTo___move);
    oluacls_func(L, "create", _cocos2d_ProgressTo_create);

    olua_registerluatype<cocos2d::ProgressTo>(L, "cc.ProgressTo");

    return 1;
}

static int _cocos2d_ProgressFromTo___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ProgressFromTo *)olua_toobj(L, 1, "cc.ProgressFromTo");
    olua_push_cppobj(L, self, "cc.ProgressFromTo");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ProgressFromTo_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    lua_Number arg2 = 0;       /** fromPercentage */
    lua_Number arg3 = 0;       /** toPercentage */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static cocos2d::ProgressFromTo *create(float duration, float fromPercentage, float toPercentage)
    cocos2d::ProgressFromTo *ret = (cocos2d::ProgressFromTo *)cocos2d::ProgressFromTo::create((float)arg1, (float)arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "cc.ProgressFromTo");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_ProgressFromTo(lua_State *L)
{
    oluacls_class(L, "cc.ProgressFromTo", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_ProgressFromTo___move);
    oluacls_func(L, "create", _cocos2d_ProgressFromTo_create);

    olua_registerluatype<cocos2d::ProgressFromTo>(L, "cc.ProgressFromTo");

    return 1;
}

static int _cocos2d_ActionEase___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ActionEase *)olua_toobj(L, 1, "cc.ActionEase");
    olua_push_cppobj(L, self, "cc.ActionEase");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ActionEase_getInnerAction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionEase *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.ActionEase");

    // @addref(innerAction ^) cocos2d::ActionInterval *getInnerAction()
    cocos2d::ActionInterval *ret = (cocos2d::ActionInterval *)self->getInnerAction();
    int num_ret = olua_push_cppobj(L, ret, "cc.ActionInterval");

    // inject code after call
    olua_addref(L, 1, "innerAction", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_ActionEase(lua_State *L)
{
    oluacls_class(L, "cc.ActionEase", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_ActionEase___move);
    oluacls_func(L, "getInnerAction", _cocos2d_ActionEase_getInnerAction);
    oluacls_prop(L, "innerAction", _cocos2d_ActionEase_getInnerAction, nullptr);

    olua_registerluatype<cocos2d::ActionEase>(L, "cc.ActionEase");

    return 1;
}

static int _cocos2d_EaseRateAction___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseRateAction *)olua_toobj(L, 1, "cc.EaseRateAction");
    olua_push_cppobj(L, self, "cc.EaseRateAction");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseRateAction_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */
    lua_Number arg2 = 0;       /** rate */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");
    olua_check_number(L, 2, &arg2);

    // static cocos2d::EaseRateAction *create(@addref(innerAction ^) cocos2d::ActionInterval *action, float rate)
    cocos2d::EaseRateAction *ret = (cocos2d::EaseRateAction *)cocos2d::EaseRateAction::create(arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseRateAction");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseRateAction_getRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseRateAction *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.EaseRateAction");

    // float getRate()
    float ret = (float)self->getRate();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseRateAction_setRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseRateAction *self = nullptr;
    lua_Number arg1 = 0;       /** rate */

    olua_to_cppobj(L, 1, (void **)&self, "cc.EaseRateAction");
    olua_check_number(L, 2, &arg1);

    // void setRate(float rate)
    self->setRate((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_EaseRateAction(lua_State *L)
{
    oluacls_class(L, "cc.EaseRateAction", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseRateAction___move);
    oluacls_func(L, "create", _cocos2d_EaseRateAction_create);
    oluacls_func(L, "getRate", _cocos2d_EaseRateAction_getRate);
    oluacls_func(L, "setRate", _cocos2d_EaseRateAction_setRate);
    oluacls_prop(L, "rate", _cocos2d_EaseRateAction_getRate, _cocos2d_EaseRateAction_setRate);

    olua_registerluatype<cocos2d::EaseRateAction>(L, "cc.EaseRateAction");

    return 1;
}

static int _cocos2d_EaseExponentialIn___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseExponentialIn *)olua_toobj(L, 1, "cc.EaseExponentialIn");
    olua_push_cppobj(L, self, "cc.EaseExponentialIn");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseExponentialIn_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseExponentialIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseExponentialIn *ret = (cocos2d::EaseExponentialIn *)cocos2d::EaseExponentialIn::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseExponentialIn");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseExponentialIn(lua_State *L)
{
    oluacls_class(L, "cc.EaseExponentialIn", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseExponentialIn___move);
    oluacls_func(L, "create", _cocos2d_EaseExponentialIn_create);

    olua_registerluatype<cocos2d::EaseExponentialIn>(L, "cc.EaseExponentialIn");

    return 1;
}

static int _cocos2d_EaseExponentialOut___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseExponentialOut *)olua_toobj(L, 1, "cc.EaseExponentialOut");
    olua_push_cppobj(L, self, "cc.EaseExponentialOut");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseExponentialOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseExponentialOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseExponentialOut *ret = (cocos2d::EaseExponentialOut *)cocos2d::EaseExponentialOut::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseExponentialOut");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseExponentialOut(lua_State *L)
{
    oluacls_class(L, "cc.EaseExponentialOut", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseExponentialOut___move);
    oluacls_func(L, "create", _cocos2d_EaseExponentialOut_create);

    olua_registerluatype<cocos2d::EaseExponentialOut>(L, "cc.EaseExponentialOut");

    return 1;
}

static int _cocos2d_EaseExponentialInOut___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseExponentialInOut *)olua_toobj(L, 1, "cc.EaseExponentialInOut");
    olua_push_cppobj(L, self, "cc.EaseExponentialInOut");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseExponentialInOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseExponentialInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseExponentialInOut *ret = (cocos2d::EaseExponentialInOut *)cocos2d::EaseExponentialInOut::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseExponentialInOut");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseExponentialInOut(lua_State *L)
{
    oluacls_class(L, "cc.EaseExponentialInOut", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseExponentialInOut___move);
    oluacls_func(L, "create", _cocos2d_EaseExponentialInOut_create);

    olua_registerluatype<cocos2d::EaseExponentialInOut>(L, "cc.EaseExponentialInOut");

    return 1;
}

static int _cocos2d_EaseSineIn___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseSineIn *)olua_toobj(L, 1, "cc.EaseSineIn");
    olua_push_cppobj(L, self, "cc.EaseSineIn");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseSineIn_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseSineIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseSineIn *ret = (cocos2d::EaseSineIn *)cocos2d::EaseSineIn::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseSineIn");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseSineIn(lua_State *L)
{
    oluacls_class(L, "cc.EaseSineIn", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseSineIn___move);
    oluacls_func(L, "create", _cocos2d_EaseSineIn_create);

    olua_registerluatype<cocos2d::EaseSineIn>(L, "cc.EaseSineIn");

    return 1;
}

static int _cocos2d_EaseSineOut___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseSineOut *)olua_toobj(L, 1, "cc.EaseSineOut");
    olua_push_cppobj(L, self, "cc.EaseSineOut");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseSineOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseSineOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseSineOut *ret = (cocos2d::EaseSineOut *)cocos2d::EaseSineOut::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseSineOut");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseSineOut(lua_State *L)
{
    oluacls_class(L, "cc.EaseSineOut", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseSineOut___move);
    oluacls_func(L, "create", _cocos2d_EaseSineOut_create);

    olua_registerluatype<cocos2d::EaseSineOut>(L, "cc.EaseSineOut");

    return 1;
}

static int _cocos2d_EaseSineInOut___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseSineInOut *)olua_toobj(L, 1, "cc.EaseSineInOut");
    olua_push_cppobj(L, self, "cc.EaseSineInOut");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseSineInOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseSineInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseSineInOut *ret = (cocos2d::EaseSineInOut *)cocos2d::EaseSineInOut::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseSineInOut");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseSineInOut(lua_State *L)
{
    oluacls_class(L, "cc.EaseSineInOut", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseSineInOut___move);
    oluacls_func(L, "create", _cocos2d_EaseSineInOut_create);

    olua_registerluatype<cocos2d::EaseSineInOut>(L, "cc.EaseSineInOut");

    return 1;
}

static int _cocos2d_EaseBounceIn___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseBounceIn *)olua_toobj(L, 1, "cc.EaseBounceIn");
    olua_push_cppobj(L, self, "cc.EaseBounceIn");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseBounceIn_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseBounceIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseBounceIn *ret = (cocos2d::EaseBounceIn *)cocos2d::EaseBounceIn::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseBounceIn");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseBounceIn(lua_State *L)
{
    oluacls_class(L, "cc.EaseBounceIn", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseBounceIn___move);
    oluacls_func(L, "create", _cocos2d_EaseBounceIn_create);

    olua_registerluatype<cocos2d::EaseBounceIn>(L, "cc.EaseBounceIn");

    return 1;
}

static int _cocos2d_EaseBounceOut___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseBounceOut *)olua_toobj(L, 1, "cc.EaseBounceOut");
    olua_push_cppobj(L, self, "cc.EaseBounceOut");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseBounceOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseBounceOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseBounceOut *ret = (cocos2d::EaseBounceOut *)cocos2d::EaseBounceOut::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseBounceOut");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseBounceOut(lua_State *L)
{
    oluacls_class(L, "cc.EaseBounceOut", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseBounceOut___move);
    oluacls_func(L, "create", _cocos2d_EaseBounceOut_create);

    olua_registerluatype<cocos2d::EaseBounceOut>(L, "cc.EaseBounceOut");

    return 1;
}

static int _cocos2d_EaseBounceInOut___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseBounceInOut *)olua_toobj(L, 1, "cc.EaseBounceInOut");
    olua_push_cppobj(L, self, "cc.EaseBounceInOut");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseBounceInOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseBounceInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseBounceInOut *ret = (cocos2d::EaseBounceInOut *)cocos2d::EaseBounceInOut::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseBounceInOut");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseBounceInOut(lua_State *L)
{
    oluacls_class(L, "cc.EaseBounceInOut", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseBounceInOut___move);
    oluacls_func(L, "create", _cocos2d_EaseBounceInOut_create);

    olua_registerluatype<cocos2d::EaseBounceInOut>(L, "cc.EaseBounceInOut");

    return 1;
}

static int _cocos2d_EaseBackIn___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseBackIn *)olua_toobj(L, 1, "cc.EaseBackIn");
    olua_push_cppobj(L, self, "cc.EaseBackIn");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseBackIn_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseBackIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseBackIn *ret = (cocos2d::EaseBackIn *)cocos2d::EaseBackIn::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseBackIn");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseBackIn(lua_State *L)
{
    oluacls_class(L, "cc.EaseBackIn", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseBackIn___move);
    oluacls_func(L, "create", _cocos2d_EaseBackIn_create);

    olua_registerluatype<cocos2d::EaseBackIn>(L, "cc.EaseBackIn");

    return 1;
}

static int _cocos2d_EaseBackOut___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseBackOut *)olua_toobj(L, 1, "cc.EaseBackOut");
    olua_push_cppobj(L, self, "cc.EaseBackOut");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseBackOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseBackOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseBackOut *ret = (cocos2d::EaseBackOut *)cocos2d::EaseBackOut::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseBackOut");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseBackOut(lua_State *L)
{
    oluacls_class(L, "cc.EaseBackOut", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseBackOut___move);
    oluacls_func(L, "create", _cocos2d_EaseBackOut_create);

    olua_registerluatype<cocos2d::EaseBackOut>(L, "cc.EaseBackOut");

    return 1;
}

static int _cocos2d_EaseBackInOut___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseBackInOut *)olua_toobj(L, 1, "cc.EaseBackInOut");
    olua_push_cppobj(L, self, "cc.EaseBackInOut");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseBackInOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseBackInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseBackInOut *ret = (cocos2d::EaseBackInOut *)cocos2d::EaseBackInOut::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseBackInOut");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseBackInOut(lua_State *L)
{
    oluacls_class(L, "cc.EaseBackInOut", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseBackInOut___move);
    oluacls_func(L, "create", _cocos2d_EaseBackInOut_create);

    olua_registerluatype<cocos2d::EaseBackInOut>(L, "cc.EaseBackInOut");

    return 1;
}

static int _cocos2d_EaseQuadraticActionIn___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseQuadraticActionIn *)olua_toobj(L, 1, "cc.EaseQuadraticActionIn");
    olua_push_cppobj(L, self, "cc.EaseQuadraticActionIn");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseQuadraticActionIn_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseQuadraticActionIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseQuadraticActionIn *ret = (cocos2d::EaseQuadraticActionIn *)cocos2d::EaseQuadraticActionIn::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseQuadraticActionIn");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseQuadraticActionIn(lua_State *L)
{
    oluacls_class(L, "cc.EaseQuadraticActionIn", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseQuadraticActionIn___move);
    oluacls_func(L, "create", _cocos2d_EaseQuadraticActionIn_create);

    olua_registerluatype<cocos2d::EaseQuadraticActionIn>(L, "cc.EaseQuadraticActionIn");

    return 1;
}

static int _cocos2d_EaseQuadraticActionOut___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseQuadraticActionOut *)olua_toobj(L, 1, "cc.EaseQuadraticActionOut");
    olua_push_cppobj(L, self, "cc.EaseQuadraticActionOut");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseQuadraticActionOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseQuadraticActionOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseQuadraticActionOut *ret = (cocos2d::EaseQuadraticActionOut *)cocos2d::EaseQuadraticActionOut::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseQuadraticActionOut");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseQuadraticActionOut(lua_State *L)
{
    oluacls_class(L, "cc.EaseQuadraticActionOut", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseQuadraticActionOut___move);
    oluacls_func(L, "create", _cocos2d_EaseQuadraticActionOut_create);

    olua_registerluatype<cocos2d::EaseQuadraticActionOut>(L, "cc.EaseQuadraticActionOut");

    return 1;
}

static int _cocos2d_EaseQuadraticActionInOut___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseQuadraticActionInOut *)olua_toobj(L, 1, "cc.EaseQuadraticActionInOut");
    olua_push_cppobj(L, self, "cc.EaseQuadraticActionInOut");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseQuadraticActionInOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseQuadraticActionInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseQuadraticActionInOut *ret = (cocos2d::EaseQuadraticActionInOut *)cocos2d::EaseQuadraticActionInOut::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseQuadraticActionInOut");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseQuadraticActionInOut(lua_State *L)
{
    oluacls_class(L, "cc.EaseQuadraticActionInOut", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseQuadraticActionInOut___move);
    oluacls_func(L, "create", _cocos2d_EaseQuadraticActionInOut_create);

    olua_registerluatype<cocos2d::EaseQuadraticActionInOut>(L, "cc.EaseQuadraticActionInOut");

    return 1;
}

static int _cocos2d_EaseQuarticActionIn___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseQuarticActionIn *)olua_toobj(L, 1, "cc.EaseQuarticActionIn");
    olua_push_cppobj(L, self, "cc.EaseQuarticActionIn");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseQuarticActionIn_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseQuarticActionIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseQuarticActionIn *ret = (cocos2d::EaseQuarticActionIn *)cocos2d::EaseQuarticActionIn::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseQuarticActionIn");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseQuarticActionIn(lua_State *L)
{
    oluacls_class(L, "cc.EaseQuarticActionIn", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseQuarticActionIn___move);
    oluacls_func(L, "create", _cocos2d_EaseQuarticActionIn_create);

    olua_registerluatype<cocos2d::EaseQuarticActionIn>(L, "cc.EaseQuarticActionIn");

    return 1;
}

static int _cocos2d_EaseQuarticActionOut___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseQuarticActionOut *)olua_toobj(L, 1, "cc.EaseQuarticActionOut");
    olua_push_cppobj(L, self, "cc.EaseQuarticActionOut");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseQuarticActionOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseQuarticActionOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseQuarticActionOut *ret = (cocos2d::EaseQuarticActionOut *)cocos2d::EaseQuarticActionOut::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseQuarticActionOut");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseQuarticActionOut(lua_State *L)
{
    oluacls_class(L, "cc.EaseQuarticActionOut", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseQuarticActionOut___move);
    oluacls_func(L, "create", _cocos2d_EaseQuarticActionOut_create);

    olua_registerluatype<cocos2d::EaseQuarticActionOut>(L, "cc.EaseQuarticActionOut");

    return 1;
}

static int _cocos2d_EaseQuarticActionInOut___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseQuarticActionInOut *)olua_toobj(L, 1, "cc.EaseQuarticActionInOut");
    olua_push_cppobj(L, self, "cc.EaseQuarticActionInOut");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseQuarticActionInOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseQuarticActionInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseQuarticActionInOut *ret = (cocos2d::EaseQuarticActionInOut *)cocos2d::EaseQuarticActionInOut::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseQuarticActionInOut");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseQuarticActionInOut(lua_State *L)
{
    oluacls_class(L, "cc.EaseQuarticActionInOut", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseQuarticActionInOut___move);
    oluacls_func(L, "create", _cocos2d_EaseQuarticActionInOut_create);

    olua_registerluatype<cocos2d::EaseQuarticActionInOut>(L, "cc.EaseQuarticActionInOut");

    return 1;
}

static int _cocos2d_EaseQuinticActionIn___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseQuinticActionIn *)olua_toobj(L, 1, "cc.EaseQuinticActionIn");
    olua_push_cppobj(L, self, "cc.EaseQuinticActionIn");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseQuinticActionIn_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseQuinticActionIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseQuinticActionIn *ret = (cocos2d::EaseQuinticActionIn *)cocos2d::EaseQuinticActionIn::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseQuinticActionIn");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseQuinticActionIn(lua_State *L)
{
    oluacls_class(L, "cc.EaseQuinticActionIn", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseQuinticActionIn___move);
    oluacls_func(L, "create", _cocos2d_EaseQuinticActionIn_create);

    olua_registerluatype<cocos2d::EaseQuinticActionIn>(L, "cc.EaseQuinticActionIn");

    return 1;
}

static int _cocos2d_EaseQuinticActionOut___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseQuinticActionOut *)olua_toobj(L, 1, "cc.EaseQuinticActionOut");
    olua_push_cppobj(L, self, "cc.EaseQuinticActionOut");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseQuinticActionOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseQuinticActionOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseQuinticActionOut *ret = (cocos2d::EaseQuinticActionOut *)cocos2d::EaseQuinticActionOut::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseQuinticActionOut");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseQuinticActionOut(lua_State *L)
{
    oluacls_class(L, "cc.EaseQuinticActionOut", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseQuinticActionOut___move);
    oluacls_func(L, "create", _cocos2d_EaseQuinticActionOut_create);

    olua_registerluatype<cocos2d::EaseQuinticActionOut>(L, "cc.EaseQuinticActionOut");

    return 1;
}

static int _cocos2d_EaseQuinticActionInOut___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseQuinticActionInOut *)olua_toobj(L, 1, "cc.EaseQuinticActionInOut");
    olua_push_cppobj(L, self, "cc.EaseQuinticActionInOut");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseQuinticActionInOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseQuinticActionInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseQuinticActionInOut *ret = (cocos2d::EaseQuinticActionInOut *)cocos2d::EaseQuinticActionInOut::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseQuinticActionInOut");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseQuinticActionInOut(lua_State *L)
{
    oluacls_class(L, "cc.EaseQuinticActionInOut", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseQuinticActionInOut___move);
    oluacls_func(L, "create", _cocos2d_EaseQuinticActionInOut_create);

    olua_registerluatype<cocos2d::EaseQuinticActionInOut>(L, "cc.EaseQuinticActionInOut");

    return 1;
}

static int _cocos2d_EaseCircleActionIn___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseCircleActionIn *)olua_toobj(L, 1, "cc.EaseCircleActionIn");
    olua_push_cppobj(L, self, "cc.EaseCircleActionIn");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseCircleActionIn_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseCircleActionIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseCircleActionIn *ret = (cocos2d::EaseCircleActionIn *)cocos2d::EaseCircleActionIn::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseCircleActionIn");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseCircleActionIn(lua_State *L)
{
    oluacls_class(L, "cc.EaseCircleActionIn", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseCircleActionIn___move);
    oluacls_func(L, "create", _cocos2d_EaseCircleActionIn_create);

    olua_registerluatype<cocos2d::EaseCircleActionIn>(L, "cc.EaseCircleActionIn");

    return 1;
}

static int _cocos2d_EaseCircleActionOut___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseCircleActionOut *)olua_toobj(L, 1, "cc.EaseCircleActionOut");
    olua_push_cppobj(L, self, "cc.EaseCircleActionOut");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseCircleActionOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseCircleActionOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseCircleActionOut *ret = (cocos2d::EaseCircleActionOut *)cocos2d::EaseCircleActionOut::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseCircleActionOut");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseCircleActionOut(lua_State *L)
{
    oluacls_class(L, "cc.EaseCircleActionOut", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseCircleActionOut___move);
    oluacls_func(L, "create", _cocos2d_EaseCircleActionOut_create);

    olua_registerluatype<cocos2d::EaseCircleActionOut>(L, "cc.EaseCircleActionOut");

    return 1;
}

static int _cocos2d_EaseCircleActionInOut___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseCircleActionInOut *)olua_toobj(L, 1, "cc.EaseCircleActionInOut");
    olua_push_cppobj(L, self, "cc.EaseCircleActionInOut");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseCircleActionInOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseCircleActionInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseCircleActionInOut *ret = (cocos2d::EaseCircleActionInOut *)cocos2d::EaseCircleActionInOut::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseCircleActionInOut");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseCircleActionInOut(lua_State *L)
{
    oluacls_class(L, "cc.EaseCircleActionInOut", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseCircleActionInOut___move);
    oluacls_func(L, "create", _cocos2d_EaseCircleActionInOut_create);

    olua_registerluatype<cocos2d::EaseCircleActionInOut>(L, "cc.EaseCircleActionInOut");

    return 1;
}

static int _cocos2d_EaseCubicActionIn___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseCubicActionIn *)olua_toobj(L, 1, "cc.EaseCubicActionIn");
    olua_push_cppobj(L, self, "cc.EaseCubicActionIn");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseCubicActionIn_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseCubicActionIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseCubicActionIn *ret = (cocos2d::EaseCubicActionIn *)cocos2d::EaseCubicActionIn::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseCubicActionIn");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseCubicActionIn(lua_State *L)
{
    oluacls_class(L, "cc.EaseCubicActionIn", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseCubicActionIn___move);
    oluacls_func(L, "create", _cocos2d_EaseCubicActionIn_create);

    olua_registerluatype<cocos2d::EaseCubicActionIn>(L, "cc.EaseCubicActionIn");

    return 1;
}

static int _cocos2d_EaseCubicActionOut___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseCubicActionOut *)olua_toobj(L, 1, "cc.EaseCubicActionOut");
    olua_push_cppobj(L, self, "cc.EaseCubicActionOut");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseCubicActionOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseCubicActionOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseCubicActionOut *ret = (cocos2d::EaseCubicActionOut *)cocos2d::EaseCubicActionOut::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseCubicActionOut");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseCubicActionOut(lua_State *L)
{
    oluacls_class(L, "cc.EaseCubicActionOut", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseCubicActionOut___move);
    oluacls_func(L, "create", _cocos2d_EaseCubicActionOut_create);

    olua_registerluatype<cocos2d::EaseCubicActionOut>(L, "cc.EaseCubicActionOut");

    return 1;
}

static int _cocos2d_EaseCubicActionInOut___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseCubicActionInOut *)olua_toobj(L, 1, "cc.EaseCubicActionInOut");
    olua_push_cppobj(L, self, "cc.EaseCubicActionInOut");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseCubicActionInOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseCubicActionInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseCubicActionInOut *ret = (cocos2d::EaseCubicActionInOut *)cocos2d::EaseCubicActionInOut::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseCubicActionInOut");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseCubicActionInOut(lua_State *L)
{
    oluacls_class(L, "cc.EaseCubicActionInOut", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseCubicActionInOut___move);
    oluacls_func(L, "create", _cocos2d_EaseCubicActionInOut_create);

    olua_registerluatype<cocos2d::EaseCubicActionInOut>(L, "cc.EaseCubicActionInOut");

    return 1;
}

static int _cocos2d_EaseIn___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseIn *)olua_toobj(L, 1, "cc.EaseIn");
    olua_push_cppobj(L, self, "cc.EaseIn");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseIn_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */
    lua_Number arg2 = 0;       /** rate */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");
    olua_check_number(L, 2, &arg2);

    // static cocos2d::EaseIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action, float rate)
    cocos2d::EaseIn *ret = (cocos2d::EaseIn *)cocos2d::EaseIn::create(arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseIn");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseIn(lua_State *L)
{
    oluacls_class(L, "cc.EaseIn", "cc.EaseRateAction");
    oluacls_func(L, "__move", _cocos2d_EaseIn___move);
    oluacls_func(L, "create", _cocos2d_EaseIn_create);

    olua_registerluatype<cocos2d::EaseIn>(L, "cc.EaseIn");

    return 1;
}

static int _cocos2d_EaseOut___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseOut *)olua_toobj(L, 1, "cc.EaseOut");
    olua_push_cppobj(L, self, "cc.EaseOut");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */
    lua_Number arg2 = 0;       /** rate */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");
    olua_check_number(L, 2, &arg2);

    // static cocos2d::EaseOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, float rate)
    cocos2d::EaseOut *ret = (cocos2d::EaseOut *)cocos2d::EaseOut::create(arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseOut");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseOut(lua_State *L)
{
    oluacls_class(L, "cc.EaseOut", "cc.EaseRateAction");
    oluacls_func(L, "__move", _cocos2d_EaseOut___move);
    oluacls_func(L, "create", _cocos2d_EaseOut_create);

    olua_registerluatype<cocos2d::EaseOut>(L, "cc.EaseOut");

    return 1;
}

static int _cocos2d_EaseInOut___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseInOut *)olua_toobj(L, 1, "cc.EaseInOut");
    olua_push_cppobj(L, self, "cc.EaseInOut");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseInOut_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */
    lua_Number arg2 = 0;       /** rate */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");
    olua_check_number(L, 2, &arg2);

    // static cocos2d::EaseInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, float rate)
    cocos2d::EaseInOut *ret = (cocos2d::EaseInOut *)cocos2d::EaseInOut::create(arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseInOut");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EaseInOut(lua_State *L)
{
    oluacls_class(L, "cc.EaseInOut", "cc.EaseRateAction");
    oluacls_func(L, "__move", _cocos2d_EaseInOut___move);
    oluacls_func(L, "create", _cocos2d_EaseInOut_create);

    olua_registerluatype<cocos2d::EaseInOut>(L, "cc.EaseInOut");

    return 1;
}

static int _cocos2d_EaseElastic___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseElastic *)olua_toobj(L, 1, "cc.EaseElastic");
    olua_push_cppobj(L, self, "cc.EaseElastic");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseElastic_getPeriod(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseElastic *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.EaseElastic");

    // float getPeriod()
    float ret = (float)self->getPeriod();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseElastic_setPeriod(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseElastic *self = nullptr;
    lua_Number arg1 = 0;       /** fPeriod */

    olua_to_cppobj(L, 1, (void **)&self, "cc.EaseElastic");
    olua_check_number(L, 2, &arg1);

    // void setPeriod(float fPeriod)
    self->setPeriod((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_EaseElastic(lua_State *L)
{
    oluacls_class(L, "cc.EaseElastic", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseElastic___move);
    oluacls_func(L, "getPeriod", _cocos2d_EaseElastic_getPeriod);
    oluacls_func(L, "setPeriod", _cocos2d_EaseElastic_setPeriod);
    oluacls_prop(L, "period", _cocos2d_EaseElastic_getPeriod, _cocos2d_EaseElastic_setPeriod);

    olua_registerluatype<cocos2d::EaseElastic>(L, "cc.EaseElastic");

    return 1;
}

static int _cocos2d_EaseElasticIn___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseElasticIn *)olua_toobj(L, 1, "cc.EaseElasticIn");
    olua_push_cppobj(L, self, "cc.EaseElasticIn");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseElasticIn_create1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */
    lua_Number arg2 = 0;       /** rate */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");
    olua_check_number(L, 2, &arg2);

    // static cocos2d::EaseElasticIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)
    cocos2d::EaseElasticIn *ret = (cocos2d::EaseElasticIn *)cocos2d::EaseElasticIn::create(arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseElasticIn");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseElasticIn_create2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseElasticIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)
    cocos2d::EaseElasticIn *ret = (cocos2d::EaseElasticIn *)cocos2d::EaseElasticIn::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseElasticIn");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseElasticIn_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 1, "cc.ActionInterval"))) {
            // static cocos2d::EaseElasticIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)
            return _cocos2d_EaseElasticIn_create2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 1, "cc.ActionInterval")) && (olua_is_number(L, 2))) {
            // static cocos2d::EaseElasticIn *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)
            return _cocos2d_EaseElasticIn_create1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::EaseElasticIn::create' not support '%d' arguments", num_args);

    return 0;
}

static int luaopen_cocos2d_EaseElasticIn(lua_State *L)
{
    oluacls_class(L, "cc.EaseElasticIn", "cc.EaseElastic");
    oluacls_func(L, "__move", _cocos2d_EaseElasticIn___move);
    oluacls_func(L, "create", _cocos2d_EaseElasticIn_create);

    olua_registerluatype<cocos2d::EaseElasticIn>(L, "cc.EaseElasticIn");

    return 1;
}

static int _cocos2d_EaseElasticOut___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseElasticOut *)olua_toobj(L, 1, "cc.EaseElasticOut");
    olua_push_cppobj(L, self, "cc.EaseElasticOut");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseElasticOut_create1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */
    lua_Number arg2 = 0;       /** rate */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");
    olua_check_number(L, 2, &arg2);

    // static cocos2d::EaseElasticOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)
    cocos2d::EaseElasticOut *ret = (cocos2d::EaseElasticOut *)cocos2d::EaseElasticOut::create(arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseElasticOut");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseElasticOut_create2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseElasticOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)
    cocos2d::EaseElasticOut *ret = (cocos2d::EaseElasticOut *)cocos2d::EaseElasticOut::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseElasticOut");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseElasticOut_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 1, "cc.ActionInterval"))) {
            // static cocos2d::EaseElasticOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)
            return _cocos2d_EaseElasticOut_create2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 1, "cc.ActionInterval")) && (olua_is_number(L, 2))) {
            // static cocos2d::EaseElasticOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)
            return _cocos2d_EaseElasticOut_create1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::EaseElasticOut::create' not support '%d' arguments", num_args);

    return 0;
}

static int luaopen_cocos2d_EaseElasticOut(lua_State *L)
{
    oluacls_class(L, "cc.EaseElasticOut", "cc.EaseElastic");
    oluacls_func(L, "__move", _cocos2d_EaseElasticOut___move);
    oluacls_func(L, "create", _cocos2d_EaseElasticOut_create);

    olua_registerluatype<cocos2d::EaseElasticOut>(L, "cc.EaseElasticOut");

    return 1;
}

static int _cocos2d_EaseElasticInOut___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseElasticInOut *)olua_toobj(L, 1, "cc.EaseElasticInOut");
    olua_push_cppobj(L, self, "cc.EaseElasticInOut");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseElasticInOut_create1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */
    lua_Number arg2 = 0;       /** rate */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");
    olua_check_number(L, 2, &arg2);

    // static cocos2d::EaseElasticInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)
    cocos2d::EaseElasticInOut *ret = (cocos2d::EaseElasticInOut *)cocos2d::EaseElasticInOut::create(arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseElasticInOut");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseElasticInOut_create2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseElasticInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)
    cocos2d::EaseElasticInOut *ret = (cocos2d::EaseElasticInOut *)cocos2d::EaseElasticInOut::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseElasticInOut");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseElasticInOut_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 1, "cc.ActionInterval"))) {
            // static cocos2d::EaseElasticInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)
            return _cocos2d_EaseElasticInOut_create2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 1, "cc.ActionInterval")) && (olua_is_number(L, 2))) {
            // static cocos2d::EaseElasticInOut *create(@addref(innerAction ^) cocos2d::ActionInterval *action, @optional float rate)
            return _cocos2d_EaseElasticInOut_create1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::EaseElasticInOut::create' not support '%d' arguments", num_args);

    return 0;
}

static int luaopen_cocos2d_EaseElasticInOut(lua_State *L)
{
    oluacls_class(L, "cc.EaseElasticInOut", "cc.EaseElastic");
    oluacls_func(L, "__move", _cocos2d_EaseElasticInOut___move);
    oluacls_func(L, "create", _cocos2d_EaseElasticInOut_create);

    olua_registerluatype<cocos2d::EaseElasticInOut>(L, "cc.EaseElasticInOut");

    return 1;
}

static int _cocos2d_EaseBezierAction___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EaseBezierAction *)olua_toobj(L, 1, "cc.EaseBezierAction");
    olua_push_cppobj(L, self, "cc.EaseBezierAction");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EaseBezierAction_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionInterval *arg1 = nullptr;       /** action */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.ActionInterval");

    // static cocos2d::EaseBezierAction *create(@addref(innerAction ^) cocos2d::ActionInterval *action)
    cocos2d::EaseBezierAction *ret = (cocos2d::EaseBezierAction *)cocos2d::EaseBezierAction::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EaseBezierAction");

    // inject code after call
    olua_addref(L, -1, "innerAction", 1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EaseBezierAction_setBezierParamer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EaseBezierAction *self = nullptr;
    lua_Number arg1 = 0;       /** p0 */
    lua_Number arg2 = 0;       /** p1 */
    lua_Number arg3 = 0;       /** p2 */
    lua_Number arg4 = 0;       /** p3 */

    olua_to_cppobj(L, 1, (void **)&self, "cc.EaseBezierAction");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // void setBezierParamer(float p0, float p1, float p2, float p3)
    self->setBezierParamer((float)arg1, (float)arg2, (float)arg3, (float)arg4);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_EaseBezierAction(lua_State *L)
{
    oluacls_class(L, "cc.EaseBezierAction", "cc.ActionEase");
    oluacls_func(L, "__move", _cocos2d_EaseBezierAction___move);
    oluacls_func(L, "create", _cocos2d_EaseBezierAction_create);
    oluacls_func(L, "setBezierParamer", _cocos2d_EaseBezierAction_setBezierParamer);

    olua_registerluatype<cocos2d::EaseBezierAction>(L, "cc.EaseBezierAction");

    return 1;
}

static int _cocos2d_PointArray___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PointArray *)olua_toobj(L, 1, "cc.PointArray");
    olua_push_cppobj(L, self, "cc.PointArray");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PointArray_addControlPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PointArray *self = nullptr;
    cocos2d::Vec2 arg1;       /** controlPoint */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PointArray");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void addControlPoint(const cocos2d::Vec2 &controlPoint)
    self->addControlPoint(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PointArray_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PointArray *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PointArray");

    // cocos2d::PointArray *clone()
    cocos2d::PointArray *ret = (cocos2d::PointArray *)self->clone();
    int num_ret = olua_push_cppobj(L, ret, "cc.PointArray");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PointArray_count(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PointArray *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PointArray");

    // ssize_t count()
    ssize_t ret = (ssize_t)self->count();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PointArray_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** capacity */

    olua_check_int(L, 1, &arg1);

    // static cocos2d::PointArray *create(ssize_t capacity)
    cocos2d::PointArray *ret = (cocos2d::PointArray *)cocos2d::PointArray::create((ssize_t)arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.PointArray");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PointArray_getControlPointAtIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PointArray *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PointArray");
    olua_check_int(L, 2, &arg1);

    // const cocos2d::Vec2 &getControlPointAtIndex(ssize_t index)
    const cocos2d::Vec2 &ret = (const cocos2d::Vec2 &)self->getControlPointAtIndex((ssize_t)arg1);
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PointArray_getControlPoints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PointArray *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PointArray");

    // const std::vector<Vec2> &getControlPoints()
    const std::vector<cocos2d::Vec2> &ret = (const std::vector<cocos2d::Vec2> &)self->getControlPoints();
    int num_ret = 1;
    int ret_size = (int)ret.size();
    lua_createtable(L, ret_size, 0);
    for (int i = 0; i < ret_size; i++) {
        auto_olua_push_cocos2d_Vec2(L, &((std::vector<cocos2d::Vec2> &)ret)[i]);
        lua_rawseti(L, -2, i + 1);
    }

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PointArray_initWithCapacity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PointArray *self = nullptr;
    lua_Integer arg1 = 0;       /** capacity */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PointArray");
    olua_check_int(L, 2, &arg1);

    // bool initWithCapacity(ssize_t capacity)
    bool ret = (bool)self->initWithCapacity((ssize_t)arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PointArray_insertControlPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PointArray *self = nullptr;
    cocos2d::Vec2 arg1;       /** controlPoint */
    lua_Integer arg2 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PointArray");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // void insertControlPoint(const cocos2d::Vec2 &controlPoint, ssize_t index)
    self->insertControlPoint(arg1, (ssize_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PointArray_removeControlPointAtIndex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PointArray *self = nullptr;
    lua_Integer arg1 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PointArray");
    olua_check_int(L, 2, &arg1);

    // void removeControlPointAtIndex(ssize_t index)
    self->removeControlPointAtIndex((ssize_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PointArray_replaceControlPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PointArray *self = nullptr;
    cocos2d::Vec2 arg1;       /** controlPoint */
    lua_Integer arg2 = 0;       /** index */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PointArray");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // void replaceControlPoint(const cocos2d::Vec2 &controlPoint, ssize_t index)
    self->replaceControlPoint(arg1, (ssize_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PointArray_reverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PointArray *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PointArray");

    // cocos2d::PointArray *reverse()
    cocos2d::PointArray *ret = (cocos2d::PointArray *)self->reverse();
    int num_ret = olua_push_cppobj(L, ret, "cc.PointArray");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PointArray_reverseInline(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PointArray *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PointArray");

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.PointArray");
    luaL_checktype(L, 2, LUA_TTABLE);
    size_t arg1_total = lua_rawlen(L, 2);
    arg1.reserve(arg1_total);
    for (int i = 1; i <= arg1_total; i++) {
        cocos2d::Vec2 obj;
        lua_rawgeti(L, 2, i);
        auto_olua_check_cocos2d_Vec2(L, -1, &obj);
        arg1.push_back(obj);
        lua_pop(L, 1);
    }

    // void setControlPoints(std::vector<Vec2> controlPoints)
    self->setControlPoints(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_PointArray(lua_State *L)
{
    oluacls_class(L, "cc.PointArray", "cc.Ref");
    oluacls_func(L, "__move", _cocos2d_PointArray___move);
    oluacls_func(L, "addControlPoint", _cocos2d_PointArray_addControlPoint);
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

    olua_registerluatype<cocos2d::PointArray>(L, "cc.PointArray");

    return 1;
}

static int _cocos2d_CardinalSplineTo___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::CardinalSplineTo *)olua_toobj(L, 1, "cc.CardinalSplineTo");
    olua_push_cppobj(L, self, "cc.CardinalSplineTo");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_CardinalSplineTo_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::PointArray *arg2 = nullptr;       /** points */
    lua_Number arg3 = 0;       /** tension */

    olua_check_number(L, 1, &arg1);
    olua_check_cppobj(L, 2, (void **)&arg2, "cc.PointArray");
    olua_check_number(L, 3, &arg3);

    // static cocos2d::CardinalSplineTo *create(float duration, cocos2d::PointArray *points, float tension)
    cocos2d::CardinalSplineTo *ret = (cocos2d::CardinalSplineTo *)cocos2d::CardinalSplineTo::create((float)arg1, arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "cc.CardinalSplineTo");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CardinalSplineTo_getPoints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::CardinalSplineTo *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.CardinalSplineTo");

    // cocos2d::PointArray *getPoints()
    cocos2d::PointArray *ret = (cocos2d::PointArray *)self->getPoints();
    int num_ret = olua_push_cppobj(L, ret, "cc.PointArray");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_CardinalSplineTo_setPoints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::CardinalSplineTo *self = nullptr;
    cocos2d::PointArray *arg1 = nullptr;       /** points */

    olua_to_cppobj(L, 1, (void **)&self, "cc.CardinalSplineTo");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.PointArray");

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.CardinalSplineTo");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void updatePosition(const cocos2d::Vec2 &newPos)
    self->updatePosition(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_CardinalSplineTo(lua_State *L)
{
    oluacls_class(L, "cc.CardinalSplineTo", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_CardinalSplineTo___move);
    oluacls_func(L, "create", _cocos2d_CardinalSplineTo_create);
    oluacls_func(L, "getPoints", _cocos2d_CardinalSplineTo_getPoints);
    oluacls_func(L, "setPoints", _cocos2d_CardinalSplineTo_setPoints);
    oluacls_func(L, "updatePosition", _cocos2d_CardinalSplineTo_updatePosition);
    oluacls_prop(L, "points", _cocos2d_CardinalSplineTo_getPoints, _cocos2d_CardinalSplineTo_setPoints);

    olua_registerluatype<cocos2d::CardinalSplineTo>(L, "cc.CardinalSplineTo");

    return 1;
}

static int _cocos2d_CardinalSplineBy___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::CardinalSplineBy *)olua_toobj(L, 1, "cc.CardinalSplineBy");
    olua_push_cppobj(L, self, "cc.CardinalSplineBy");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_CardinalSplineBy_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::PointArray *arg2 = nullptr;       /** points */
    lua_Number arg3 = 0;       /** tension */

    olua_check_number(L, 1, &arg1);
    olua_check_cppobj(L, 2, (void **)&arg2, "cc.PointArray");
    olua_check_number(L, 3, &arg3);

    // static cocos2d::CardinalSplineBy *create(float duration, cocos2d::PointArray *points, float tension)
    cocos2d::CardinalSplineBy *ret = (cocos2d::CardinalSplineBy *)cocos2d::CardinalSplineBy::create((float)arg1, arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "cc.CardinalSplineBy");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_CardinalSplineBy(lua_State *L)
{
    oluacls_class(L, "cc.CardinalSplineBy", "cc.CardinalSplineTo");
    oluacls_func(L, "__move", _cocos2d_CardinalSplineBy___move);
    oluacls_func(L, "create", _cocos2d_CardinalSplineBy_create);

    olua_registerluatype<cocos2d::CardinalSplineBy>(L, "cc.CardinalSplineBy");

    return 1;
}

static int _cocos2d_CatmullRomTo___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::CatmullRomTo *)olua_toobj(L, 1, "cc.CatmullRomTo");
    olua_push_cppobj(L, self, "cc.CatmullRomTo");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_CatmullRomTo_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** dt */
    cocos2d::PointArray *arg2 = nullptr;       /** points */

    olua_check_number(L, 1, &arg1);
    olua_check_cppobj(L, 2, (void **)&arg2, "cc.PointArray");

    // static cocos2d::CatmullRomTo *create(float dt, cocos2d::PointArray *points)
    cocos2d::CatmullRomTo *ret = (cocos2d::CatmullRomTo *)cocos2d::CatmullRomTo::create((float)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.CatmullRomTo");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_CatmullRomTo(lua_State *L)
{
    oluacls_class(L, "cc.CatmullRomTo", "cc.CardinalSplineTo");
    oluacls_func(L, "__move", _cocos2d_CatmullRomTo___move);
    oluacls_func(L, "create", _cocos2d_CatmullRomTo_create);

    olua_registerluatype<cocos2d::CatmullRomTo>(L, "cc.CatmullRomTo");

    return 1;
}

static int _cocos2d_CatmullRomBy___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::CatmullRomBy *)olua_toobj(L, 1, "cc.CatmullRomBy");
    olua_push_cppobj(L, self, "cc.CatmullRomBy");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_CatmullRomBy_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** dt */
    cocos2d::PointArray *arg2 = nullptr;       /** points */

    olua_check_number(L, 1, &arg1);
    olua_check_cppobj(L, 2, (void **)&arg2, "cc.PointArray");

    // static cocos2d::CatmullRomBy *create(float dt, cocos2d::PointArray *points)
    cocos2d::CatmullRomBy *ret = (cocos2d::CatmullRomBy *)cocos2d::CatmullRomBy::create((float)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.CatmullRomBy");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_CatmullRomBy(lua_State *L)
{
    oluacls_class(L, "cc.CatmullRomBy", "cc.CardinalSplineBy");
    oluacls_func(L, "__move", _cocos2d_CatmullRomBy___move);
    oluacls_func(L, "create", _cocos2d_CatmullRomBy_create);

    olua_registerluatype<cocos2d::CatmullRomBy>(L, "cc.CatmullRomBy");

    return 1;
}

static int _cocos2d_ActionInstant___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ActionInstant *)olua_toobj(L, 1, "cc.ActionInstant");
    olua_push_cppobj(L, self, "cc.ActionInstant");

    olua_endinvoke(L);

    return 1;
}

static int luaopen_cocos2d_ActionInstant(lua_State *L)
{
    oluacls_class(L, "cc.ActionInstant", "cc.FiniteTimeAction");
    oluacls_func(L, "__move", _cocos2d_ActionInstant___move);

    olua_registerluatype<cocos2d::ActionInstant>(L, "cc.ActionInstant");

    return 1;
}

static int _cocos2d_Show___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Show *)olua_toobj(L, 1, "cc.Show");
    olua_push_cppobj(L, self, "cc.Show");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_Show_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Show *create()
    cocos2d::Show *ret = (cocos2d::Show *)cocos2d::Show::create();
    int num_ret = olua_push_cppobj(L, ret, "cc.Show");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_Show(lua_State *L)
{
    oluacls_class(L, "cc.Show", "cc.ActionInstant");
    oluacls_func(L, "__move", _cocos2d_Show___move);
    oluacls_func(L, "create", _cocos2d_Show_create);

    olua_registerluatype<cocos2d::Show>(L, "cc.Show");

    return 1;
}

static int _cocos2d_Hide___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Hide *)olua_toobj(L, 1, "cc.Hide");
    olua_push_cppobj(L, self, "cc.Hide");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_Hide_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::Hide *create()
    cocos2d::Hide *ret = (cocos2d::Hide *)cocos2d::Hide::create();
    int num_ret = olua_push_cppobj(L, ret, "cc.Hide");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_Hide(lua_State *L)
{
    oluacls_class(L, "cc.Hide", "cc.ActionInstant");
    oluacls_func(L, "__move", _cocos2d_Hide___move);
    oluacls_func(L, "create", _cocos2d_Hide_create);

    olua_registerluatype<cocos2d::Hide>(L, "cc.Hide");

    return 1;
}

static int _cocos2d_ToggleVisibility___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ToggleVisibility *)olua_toobj(L, 1, "cc.ToggleVisibility");
    olua_push_cppobj(L, self, "cc.ToggleVisibility");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ToggleVisibility_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ToggleVisibility *create()
    cocos2d::ToggleVisibility *ret = (cocos2d::ToggleVisibility *)cocos2d::ToggleVisibility::create();
    int num_ret = olua_push_cppobj(L, ret, "cc.ToggleVisibility");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_ToggleVisibility(lua_State *L)
{
    oluacls_class(L, "cc.ToggleVisibility", "cc.ActionInstant");
    oluacls_func(L, "__move", _cocos2d_ToggleVisibility___move);
    oluacls_func(L, "create", _cocos2d_ToggleVisibility_create);

    olua_registerluatype<cocos2d::ToggleVisibility>(L, "cc.ToggleVisibility");

    return 1;
}

static int _cocos2d_RemoveSelf___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::RemoveSelf *)olua_toobj(L, 1, "cc.RemoveSelf");
    olua_push_cppobj(L, self, "cc.RemoveSelf");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_RemoveSelf_create1(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** isNeedCleanUp */

    olua_check_bool(L, 1, &arg1);

    // static cocos2d::RemoveSelf *create(@optional bool isNeedCleanUp)
    cocos2d::RemoveSelf *ret = (cocos2d::RemoveSelf *)cocos2d::RemoveSelf::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.RemoveSelf");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_RemoveSelf_create2(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::RemoveSelf *create(@optional bool isNeedCleanUp)
    cocos2d::RemoveSelf *ret = (cocos2d::RemoveSelf *)cocos2d::RemoveSelf::create();
    int num_ret = olua_push_cppobj(L, ret, "cc.RemoveSelf");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_RemoveSelf_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::RemoveSelf *create(@optional bool isNeedCleanUp)
        return _cocos2d_RemoveSelf_create2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_bool(L, 1))) {
            // static cocos2d::RemoveSelf *create(@optional bool isNeedCleanUp)
            return _cocos2d_RemoveSelf_create1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::RemoveSelf::create' not support '%d' arguments", num_args);

    return 0;
}

static int luaopen_cocos2d_RemoveSelf(lua_State *L)
{
    oluacls_class(L, "cc.RemoveSelf", "cc.ActionInstant");
    oluacls_func(L, "__move", _cocos2d_RemoveSelf___move);
    oluacls_func(L, "create", _cocos2d_RemoveSelf_create);

    olua_registerluatype<cocos2d::RemoveSelf>(L, "cc.RemoveSelf");

    return 1;
}

static int _cocos2d_FlipX___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::FlipX *)olua_toobj(L, 1, "cc.FlipX");
    olua_push_cppobj(L, self, "cc.FlipX");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_FlipX_create(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** x */

    olua_check_bool(L, 1, &arg1);

    // static cocos2d::FlipX *create(bool x)
    cocos2d::FlipX *ret = (cocos2d::FlipX *)cocos2d::FlipX::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.FlipX");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_FlipX(lua_State *L)
{
    oluacls_class(L, "cc.FlipX", "cc.ActionInstant");
    oluacls_func(L, "__move", _cocos2d_FlipX___move);
    oluacls_func(L, "create", _cocos2d_FlipX_create);

    olua_registerluatype<cocos2d::FlipX>(L, "cc.FlipX");

    return 1;
}

static int _cocos2d_FlipY___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::FlipY *)olua_toobj(L, 1, "cc.FlipY");
    olua_push_cppobj(L, self, "cc.FlipY");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_FlipY_create(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** y */

    olua_check_bool(L, 1, &arg1);

    // static cocos2d::FlipY *create(bool y)
    cocos2d::FlipY *ret = (cocos2d::FlipY *)cocos2d::FlipY::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.FlipY");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_FlipY(lua_State *L)
{
    oluacls_class(L, "cc.FlipY", "cc.ActionInstant");
    oluacls_func(L, "__move", _cocos2d_FlipY___move);
    oluacls_func(L, "create", _cocos2d_FlipY_create);

    olua_registerluatype<cocos2d::FlipY>(L, "cc.FlipY");

    return 1;
}

static int _cocos2d_Place___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Place *)olua_toobj(L, 1, "cc.Place");
    olua_push_cppobj(L, self, "cc.Place");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_Place_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 arg1;       /** pos */

    auto_olua_check_cocos2d_Vec2(L, 1, &arg1);

    // static cocos2d::Place *create(const cocos2d::Vec2 &pos)
    cocos2d::Place *ret = (cocos2d::Place *)cocos2d::Place::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.Place");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_Place(lua_State *L)
{
    oluacls_class(L, "cc.Place", "cc.ActionInstant");
    oluacls_func(L, "__move", _cocos2d_Place___move);
    oluacls_func(L, "create", _cocos2d_Place_create);

    olua_registerluatype<cocos2d::Place>(L, "cc.Place");

    return 1;
}

static int _cocos2d_CallFunc___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::CallFunc *)olua_toobj(L, 1, "cc.CallFunc");
    olua_push_cppobj(L, self, "cc.CallFunc");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_CallFunc_create(lua_State *L)
{
    olua_startinvoke(L);

    std::function<void()> arg1;       /** func */

    void *callback_store_obj = (void *)olua_allocobjstub(L, "cc.CallFunc");
    std::string tag = "CallFunc";
    std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 1, OLUA_TAG_NEW);
    lua_State *MT = olua_mainthread();
    arg1 = [callback_store_obj, func, MT]() {
        lua_State *L = olua_mainthread();

        if (MT == L) {
            int top = lua_gettop(L);

            olua_callback(L, callback_store_obj, func.c_str(), 0);

            lua_settop(L, top);
        }
    };

    // static cocos2d::CallFunc *create(@local const std::function<void ()> &func)
    cocos2d::CallFunc *ret = (cocos2d::CallFunc *)cocos2d::CallFunc::create(arg1);
    const char *cls = olua_getluatype(L, ret, "cc.CallFunc");
    if (olua_pushobjstub(L, ret, callback_store_obj, cls) == OLUA_OBJ_EXIST) {
        lua_pushstring(L, func.c_str());
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

    olua_to_cppobj(L, 1, (void **)&self, "cc.CallFunc");

    // void execute()
    self->execute();

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_CallFunc(lua_State *L)
{
    oluacls_class(L, "cc.CallFunc", "cc.ActionInstant");
    oluacls_func(L, "__move", _cocos2d_CallFunc___move);
    oluacls_func(L, "create", _cocos2d_CallFunc_create);
    oluacls_func(L, "execute", _cocos2d_CallFunc_execute);

    olua_registerluatype<cocos2d::CallFunc>(L, "cc.CallFunc");

    return 1;
}

static int _cocos2d_ActionCamera___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ActionCamera *)olua_toobj(L, 1, "cc.ActionCamera");
    olua_push_cppobj(L, self, "cc.ActionCamera");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ActionCamera_getCenter(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionCamera *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.ActionCamera");

    // const cocos2d::Vec3 &getCenter()
    const cocos2d::Vec3 &ret = (const cocos2d::Vec3 &)self->getCenter();
    int num_ret = auto_olua_push_cocos2d_Vec3(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ActionCamera_getEye(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionCamera *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.ActionCamera");

    // const cocos2d::Vec3 &getEye()
    const cocos2d::Vec3 &ret = (const cocos2d::Vec3 &)self->getEye();
    int num_ret = auto_olua_push_cocos2d_Vec3(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ActionCamera_getUp(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionCamera *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.ActionCamera");

    // const cocos2d::Vec3 &getUp()
    const cocos2d::Vec3 &ret = (const cocos2d::Vec3 &)self->getUp();
    int num_ret = auto_olua_push_cocos2d_Vec3(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ActionCamera_setCenter(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionCamera *self = nullptr;
    cocos2d::Vec3 arg1;       /** center */

    olua_to_cppobj(L, 1, (void **)&self, "cc.ActionCamera");
    auto_olua_check_cocos2d_Vec3(L, 2, &arg1);

    // void setCenter(const cocos2d::Vec3 &center)
    self->setCenter(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ActionCamera_setEye1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionCamera *self = nullptr;
    cocos2d::Vec3 arg1;       /** eye */

    olua_to_cppobj(L, 1, (void **)&self, "cc.ActionCamera");
    auto_olua_check_cocos2d_Vec3(L, 2, &arg1);

    // void setEye(const cocos2d::Vec3 &eye)
    self->setEye(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ActionCamera_setEye2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ActionCamera *self = nullptr;
    lua_Number arg1 = 0;       /** x */
    lua_Number arg2 = 0;       /** y */
    lua_Number arg3 = 0;       /** z */

    olua_to_cppobj(L, 1, (void **)&self, "cc.ActionCamera");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // void setEye(float x, float y, float z)
    self->setEye((float)arg1, (float)arg2, (float)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_ActionCamera_setEye(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((auto_olua_is_cocos2d_Vec3(L, 2))) {
            // void setEye(const cocos2d::Vec3 &eye)
            return _cocos2d_ActionCamera_setEye1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4))) {
            // void setEye(float x, float y, float z)
            return _cocos2d_ActionCamera_setEye2(L);
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

    olua_to_cppobj(L, 1, (void **)&self, "cc.ActionCamera");
    auto_olua_check_cocos2d_Vec3(L, 2, &arg1);

    // void setUp(const cocos2d::Vec3 &up)
    self->setUp(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_ActionCamera(lua_State *L)
{
    oluacls_class(L, "cc.ActionCamera", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_ActionCamera___move);
    oluacls_func(L, "getCenter", _cocos2d_ActionCamera_getCenter);
    oluacls_func(L, "getEye", _cocos2d_ActionCamera_getEye);
    oluacls_func(L, "getUp", _cocos2d_ActionCamera_getUp);
    oluacls_func(L, "setCenter", _cocos2d_ActionCamera_setCenter);
    oluacls_func(L, "setEye", _cocos2d_ActionCamera_setEye);
    oluacls_func(L, "setUp", _cocos2d_ActionCamera_setUp);
    oluacls_prop(L, "center", _cocos2d_ActionCamera_getCenter, _cocos2d_ActionCamera_setCenter);
    oluacls_prop(L, "eye", _cocos2d_ActionCamera_getEye, _cocos2d_ActionCamera_setEye);
    oluacls_prop(L, "up", _cocos2d_ActionCamera_getUp, _cocos2d_ActionCamera_setUp);

    olua_registerluatype<cocos2d::ActionCamera>(L, "cc.ActionCamera");

    return 1;
}

static int _cocos2d_OrbitCamera___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::OrbitCamera *)olua_toobj(L, 1, "cc.OrbitCamera");
    olua_push_cppobj(L, self, "cc.OrbitCamera");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_OrbitCamera_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** t */
    lua_Number arg2 = 0;       /** radius */
    lua_Number arg3 = 0;       /** deltaRadius */
    lua_Number arg4 = 0;       /** angleZ */
    lua_Number arg5 = 0;       /** deltaAngleZ */
    lua_Number arg6 = 0;       /** angleX */
    lua_Number arg7 = 0;       /** deltaAngleX */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);
    olua_check_number(L, 5, &arg5);
    olua_check_number(L, 6, &arg6);
    olua_check_number(L, 7, &arg7);

    // static cocos2d::OrbitCamera *create(float t, float radius, float deltaRadius, float angleZ, float deltaAngleZ, float angleX, float deltaAngleX)
    cocos2d::OrbitCamera *ret = (cocos2d::OrbitCamera *)cocos2d::OrbitCamera::create((float)arg1, (float)arg2, (float)arg3, (float)arg4, (float)arg5, (float)arg6, (float)arg7);
    int num_ret = olua_push_cppobj(L, ret, "cc.OrbitCamera");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_OrbitCamera(lua_State *L)
{
    oluacls_class(L, "cc.OrbitCamera", "cc.ActionCamera");
    oluacls_func(L, "__move", _cocos2d_OrbitCamera___move);
    oluacls_func(L, "create", _cocos2d_OrbitCamera_create);

    olua_registerluatype<cocos2d::OrbitCamera>(L, "cc.OrbitCamera");

    return 1;
}

static int _cocos2d_GridBase___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::GridBase *)olua_toobj(L, 1, "cc.GridBase");
    olua_push_cppobj(L, self, "cc.GridBase");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_GridBase_afterBlit(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.GridBase");

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.GridBase");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Node");

    // void afterDraw(cocos2d::Node *target)
    self->afterDraw(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_GridBase_beforeBlit(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.GridBase");

    // void beforeBlit()
    self->beforeBlit();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_GridBase_beforeDraw(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.GridBase");

    // void beforeDraw()
    self->beforeDraw();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_GridBase_blit(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.GridBase");

    // void blit()
    self->blit();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_GridBase_calculateVertexPoints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.GridBase");

    // void calculateVertexPoints()
    self->calculateVertexPoints();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_GridBase_getGridRect(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.GridBase");

    // const cocos2d::Rect &getGridRect()
    const cocos2d::Rect &ret = (const cocos2d::Rect &)self->getGridRect();
    int num_ret = manual_olua_push_cocos2d_Rect(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_GridBase_getGridSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.GridBase");

    // const cocos2d::Size &getGridSize()
    const cocos2d::Size &ret = (const cocos2d::Size &)self->getGridSize();
    int num_ret = auto_olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_GridBase_getReuseGrid(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.GridBase");

    // int getReuseGrid()
    int ret = (int)self->getReuseGrid();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_GridBase_getStep(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.GridBase");

    // const cocos2d::Vec2 &getStep()
    const cocos2d::Vec2 &ret = (const cocos2d::Vec2 &)self->getStep();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_GridBase_initWithSize1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;
    cocos2d::Size arg1;       /** gridSize */

    olua_to_cppobj(L, 1, (void **)&self, "cc.GridBase");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);

    // bool initWithSize(const cocos2d::Size &gridSize)
    bool ret = (bool)self->initWithSize(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_GridBase_initWithSize2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;
    cocos2d::Size arg1;       /** gridSize */
    cocos2d::Rect arg2;       /** rect */

    olua_to_cppobj(L, 1, (void **)&self, "cc.GridBase");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);
    manual_olua_check_cocos2d_Rect(L, 3, &arg2);

    // bool initWithSize(const cocos2d::Size &gridSize, const cocos2d::Rect &rect)
    bool ret = (bool)self->initWithSize(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_GridBase_initWithSize3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;
    cocos2d::Size arg1;       /** gridSize */
    cocos2d::Texture2D *arg2 = nullptr;       /** texture */
    bool arg3 = false;       /** flipped */

    olua_to_cppobj(L, 1, (void **)&self, "cc.GridBase");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "cc.Texture2D");
    olua_check_bool(L, 4, &arg3);

    // bool initWithSize(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped)
    bool ret = (bool)self->initWithSize(arg1, arg2, arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_GridBase_initWithSize4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;
    cocos2d::Size arg1;       /** gridSize */
    cocos2d::Texture2D *arg2 = nullptr;       /** texture */
    bool arg3 = false;       /** flipped */
    cocos2d::Rect arg4;       /** rect */

    olua_to_cppobj(L, 1, (void **)&self, "cc.GridBase");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);
    olua_check_cppobj(L, 3, (void **)&arg2, "cc.Texture2D");
    olua_check_bool(L, 4, &arg3);
    manual_olua_check_cocos2d_Rect(L, 5, &arg4);

    // bool initWithSize(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped, const cocos2d::Rect &rect)
    bool ret = (bool)self->initWithSize(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_GridBase_initWithSize(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((auto_olua_is_cocos2d_Size(L, 2))) {
            // bool initWithSize(const cocos2d::Size &gridSize)
            return _cocos2d_GridBase_initWithSize1(L);
        // }
    }

    if (num_args == 2) {
        // if ((auto_olua_is_cocos2d_Size(L, 2)) && (manual_olua_is_cocos2d_Rect(L, 3))) {
            // bool initWithSize(const cocos2d::Size &gridSize, const cocos2d::Rect &rect)
            return _cocos2d_GridBase_initWithSize2(L);
        // }
    }

    if (num_args == 3) {
        // if ((auto_olua_is_cocos2d_Size(L, 2)) && (olua_is_cppobj(L, 3, "cc.Texture2D")) && (olua_is_bool(L, 4))) {
            // bool initWithSize(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped)
            return _cocos2d_GridBase_initWithSize3(L);
        // }
    }

    if (num_args == 4) {
        // if ((auto_olua_is_cocos2d_Size(L, 2)) && (olua_is_cppobj(L, 3, "cc.Texture2D")) && (olua_is_bool(L, 4)) && (manual_olua_is_cocos2d_Rect(L, 5))) {
            // bool initWithSize(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped, const cocos2d::Rect &rect)
            return _cocos2d_GridBase_initWithSize4(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::GridBase::initWithSize' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_GridBase_isActive(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.GridBase");

    // bool isActive()
    bool ret = (bool)self->isActive();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_GridBase_isTextureFlipped(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.GridBase");

    // bool isTextureFlipped()
    bool ret = (bool)self->isTextureFlipped();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_GridBase_reuse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.GridBase");

    // void reuse()
    self->reuse();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_GridBase_set2DProjection(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.GridBase");

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.GridBase");
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

    olua_to_cppobj(L, 1, (void **)&self, "cc.GridBase");
    manual_olua_check_cocos2d_Rect(L, 2, &arg1);

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.GridBase");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);

    // void setGridSize(const cocos2d::Size &gridSize)
    self->setGridSize(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_GridBase_setReuseGrid(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;
    lua_Integer arg1 = 0;       /** reuseGrid */

    olua_to_cppobj(L, 1, (void **)&self, "cc.GridBase");
    olua_check_int(L, 2, &arg1);

    // void setReuseGrid(int reuseGrid)
    self->setReuseGrid((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_GridBase_setStep(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridBase *self = nullptr;
    cocos2d::Vec2 arg1;       /** step */

    olua_to_cppobj(L, 1, (void **)&self, "cc.GridBase");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.GridBase");
    olua_check_bool(L, 2, &arg1);

    // void setTextureFlipped(bool flipped)
    self->setTextureFlipped(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_GridBase(lua_State *L)
{
    oluacls_class(L, "cc.GridBase", "cc.Ref");
    oluacls_func(L, "__move", _cocos2d_GridBase___move);
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

    olua_registerluatype<cocos2d::GridBase>(L, "cc.GridBase");

    return 1;
}

static int _cocos2d_Grid3D___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Grid3D *)olua_toobj(L, 1, "cc.Grid3D");
    olua_push_cppobj(L, self, "cc.Grid3D");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_Grid3D_create1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** gridSize */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);

    // static cocos2d::Grid3D *create(const cocos2d::Size &gridSize)
    cocos2d::Grid3D *ret = (cocos2d::Grid3D *)cocos2d::Grid3D::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.Grid3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Grid3D_create2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** gridSize */
    cocos2d::Rect arg2;       /** rect */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);
    manual_olua_check_cocos2d_Rect(L, 2, &arg2);

    // static cocos2d::Grid3D *create(const cocos2d::Size &gridSize, const cocos2d::Rect &rect)
    cocos2d::Grid3D *ret = (cocos2d::Grid3D *)cocos2d::Grid3D::create(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.Grid3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Grid3D_create3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** gridSize */
    cocos2d::Texture2D *arg2 = nullptr;       /** texture */
    bool arg3 = false;       /** flipped */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);
    olua_check_cppobj(L, 2, (void **)&arg2, "cc.Texture2D");
    olua_check_bool(L, 3, &arg3);

    // static cocos2d::Grid3D *create(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped)
    cocos2d::Grid3D *ret = (cocos2d::Grid3D *)cocos2d::Grid3D::create(arg1, arg2, arg3);
    int num_ret = olua_push_cppobj(L, ret, "cc.Grid3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Grid3D_create4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** gridSize */
    cocos2d::Texture2D *arg2 = nullptr;       /** texture */
    bool arg3 = false;       /** flipped */
    cocos2d::Rect arg4;       /** rect */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);
    olua_check_cppobj(L, 2, (void **)&arg2, "cc.Texture2D");
    olua_check_bool(L, 3, &arg3);
    manual_olua_check_cocos2d_Rect(L, 4, &arg4);

    // static cocos2d::Grid3D *create(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped, const cocos2d::Rect &rect)
    cocos2d::Grid3D *ret = (cocos2d::Grid3D *)cocos2d::Grid3D::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.Grid3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Grid3D_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((auto_olua_is_cocos2d_Size(L, 1))) {
            // static cocos2d::Grid3D *create(const cocos2d::Size &gridSize)
            return _cocos2d_Grid3D_create1(L);
        // }
    }

    if (num_args == 2) {
        // if ((auto_olua_is_cocos2d_Size(L, 1)) && (manual_olua_is_cocos2d_Rect(L, 2))) {
            // static cocos2d::Grid3D *create(const cocos2d::Size &gridSize, const cocos2d::Rect &rect)
            return _cocos2d_Grid3D_create2(L);
        // }
    }

    if (num_args == 3) {
        // if ((auto_olua_is_cocos2d_Size(L, 1)) && (olua_is_cppobj(L, 2, "cc.Texture2D")) && (olua_is_bool(L, 3))) {
            // static cocos2d::Grid3D *create(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped)
            return _cocos2d_Grid3D_create3(L);
        // }
    }

    if (num_args == 4) {
        // if ((auto_olua_is_cocos2d_Size(L, 1)) && (olua_is_cppobj(L, 2, "cc.Texture2D")) && (olua_is_bool(L, 3)) && (manual_olua_is_cocos2d_Rect(L, 4))) {
            // static cocos2d::Grid3D *create(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped, const cocos2d::Rect &rect)
            return _cocos2d_Grid3D_create4(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Grid3D::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_Grid3D_getNeedDepthTestForBlit(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Grid3D *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.Grid3D");

    // bool getNeedDepthTestForBlit()
    bool ret = (bool)self->getNeedDepthTestForBlit();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Grid3D_getOriginalVertex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Grid3D *self = nullptr;
    cocos2d::Vec2 arg1;       /** pos */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Grid3D");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // cocos2d::Vec3 getOriginalVertex(const cocos2d::Vec2 &pos)
    cocos2d::Vec3 ret = (cocos2d::Vec3)self->getOriginalVertex(arg1);
    int num_ret = auto_olua_push_cocos2d_Vec3(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Grid3D_getVertex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Grid3D *self = nullptr;
    cocos2d::Vec2 arg1;       /** pos */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Grid3D");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // cocos2d::Vec3 getVertex(const cocos2d::Vec2 &pos)
    cocos2d::Vec3 ret = (cocos2d::Vec3)self->getVertex(arg1);
    int num_ret = auto_olua_push_cocos2d_Vec3(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Grid3D_setNeedDepthTestForBlit(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Grid3D *self = nullptr;
    bool arg1 = false;       /** neededDepthTest */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Grid3D");
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

    olua_to_cppobj(L, 1, (void **)&self, "cc.Grid3D");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);
    auto_olua_check_cocos2d_Vec3(L, 3, &arg2);

    // void setVertex(const cocos2d::Vec2 &pos, const cocos2d::Vec3 &vertex)
    self->setVertex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_Grid3D(lua_State *L)
{
    oluacls_class(L, "cc.Grid3D", "cc.GridBase");
    oluacls_func(L, "__move", _cocos2d_Grid3D___move);
    oluacls_func(L, "create", _cocos2d_Grid3D_create);
    oluacls_func(L, "getNeedDepthTestForBlit", _cocos2d_Grid3D_getNeedDepthTestForBlit);
    oluacls_func(L, "getOriginalVertex", _cocos2d_Grid3D_getOriginalVertex);
    oluacls_func(L, "getVertex", _cocos2d_Grid3D_getVertex);
    oluacls_func(L, "setNeedDepthTestForBlit", _cocos2d_Grid3D_setNeedDepthTestForBlit);
    oluacls_func(L, "setVertex", _cocos2d_Grid3D_setVertex);
    oluacls_prop(L, "needDepthTestForBlit", _cocos2d_Grid3D_getNeedDepthTestForBlit, _cocos2d_Grid3D_setNeedDepthTestForBlit);

    olua_registerluatype<cocos2d::Grid3D>(L, "cc.Grid3D");

    return 1;
}

static int _cocos2d_TiledGrid3D___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::TiledGrid3D *)olua_toobj(L, 1, "cc.TiledGrid3D");
    olua_push_cppobj(L, self, "cc.TiledGrid3D");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_TiledGrid3D_create1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** gridSize */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);

    // static cocos2d::TiledGrid3D *create(const cocos2d::Size &gridSize)
    cocos2d::TiledGrid3D *ret = (cocos2d::TiledGrid3D *)cocos2d::TiledGrid3D::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.TiledGrid3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TiledGrid3D_create2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** gridSize */
    cocos2d::Rect arg2;       /** rect */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);
    manual_olua_check_cocos2d_Rect(L, 2, &arg2);

    // static cocos2d::TiledGrid3D *create(const cocos2d::Size &gridSize, const cocos2d::Rect &rect)
    cocos2d::TiledGrid3D *ret = (cocos2d::TiledGrid3D *)cocos2d::TiledGrid3D::create(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.TiledGrid3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TiledGrid3D_create3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** gridSize */
    cocos2d::Texture2D *arg2 = nullptr;       /** texture */
    bool arg3 = false;       /** flipped */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);
    olua_check_cppobj(L, 2, (void **)&arg2, "cc.Texture2D");
    olua_check_bool(L, 3, &arg3);

    // static cocos2d::TiledGrid3D *create(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped)
    cocos2d::TiledGrid3D *ret = (cocos2d::TiledGrid3D *)cocos2d::TiledGrid3D::create(arg1, arg2, arg3);
    int num_ret = olua_push_cppobj(L, ret, "cc.TiledGrid3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TiledGrid3D_create4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** gridSize */
    cocos2d::Texture2D *arg2 = nullptr;       /** texture */
    bool arg3 = false;       /** flipped */
    cocos2d::Rect arg4;       /** rect */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);
    olua_check_cppobj(L, 2, (void **)&arg2, "cc.Texture2D");
    olua_check_bool(L, 3, &arg3);
    manual_olua_check_cocos2d_Rect(L, 4, &arg4);

    // static cocos2d::TiledGrid3D *create(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped, const cocos2d::Rect &rect)
    cocos2d::TiledGrid3D *ret = (cocos2d::TiledGrid3D *)cocos2d::TiledGrid3D::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.TiledGrid3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TiledGrid3D_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((auto_olua_is_cocos2d_Size(L, 1))) {
            // static cocos2d::TiledGrid3D *create(const cocos2d::Size &gridSize)
            return _cocos2d_TiledGrid3D_create1(L);
        // }
    }

    if (num_args == 2) {
        // if ((auto_olua_is_cocos2d_Size(L, 1)) && (manual_olua_is_cocos2d_Rect(L, 2))) {
            // static cocos2d::TiledGrid3D *create(const cocos2d::Size &gridSize, const cocos2d::Rect &rect)
            return _cocos2d_TiledGrid3D_create2(L);
        // }
    }

    if (num_args == 3) {
        // if ((auto_olua_is_cocos2d_Size(L, 1)) && (olua_is_cppobj(L, 2, "cc.Texture2D")) && (olua_is_bool(L, 3))) {
            // static cocos2d::TiledGrid3D *create(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped)
            return _cocos2d_TiledGrid3D_create3(L);
        // }
    }

    if (num_args == 4) {
        // if ((auto_olua_is_cocos2d_Size(L, 1)) && (olua_is_cppobj(L, 2, "cc.Texture2D")) && (olua_is_bool(L, 3)) && (manual_olua_is_cocos2d_Rect(L, 4))) {
            // static cocos2d::TiledGrid3D *create(const cocos2d::Size &gridSize, cocos2d::Texture2D *texture, bool flipped, const cocos2d::Rect &rect)
            return _cocos2d_TiledGrid3D_create4(L);
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

    olua_to_cppobj(L, 1, (void **)&self, "cc.TiledGrid3D");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // cocos2d::Quad3 getOriginalTile(const cocos2d::Vec2 &pos)
    cocos2d::Quad3 ret = (cocos2d::Quad3)self->getOriginalTile(arg1);
    int num_ret = auto_olua_push_cocos2d_Quad3(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TiledGrid3D_getTile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TiledGrid3D *self = nullptr;
    cocos2d::Vec2 arg1;       /** pos */

    olua_to_cppobj(L, 1, (void **)&self, "cc.TiledGrid3D");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // cocos2d::Quad3 getTile(const cocos2d::Vec2 &pos)
    cocos2d::Quad3 ret = (cocos2d::Quad3)self->getTile(arg1);
    int num_ret = auto_olua_push_cocos2d_Quad3(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TiledGrid3D_setTile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TiledGrid3D *self = nullptr;
    cocos2d::Vec2 arg1;       /** pos */
    cocos2d::Quad3 arg2;       /** coords */

    olua_to_cppobj(L, 1, (void **)&self, "cc.TiledGrid3D");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);
    auto_olua_check_cocos2d_Quad3(L, 3, &arg2);

    // void setTile(const cocos2d::Vec2 &pos, const cocos2d::Quad3 &coords)
    self->setTile(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_TiledGrid3D(lua_State *L)
{
    oluacls_class(L, "cc.TiledGrid3D", "cc.GridBase");
    oluacls_func(L, "__move", _cocos2d_TiledGrid3D___move);
    oluacls_func(L, "create", _cocos2d_TiledGrid3D_create);
    oluacls_func(L, "getOriginalTile", _cocos2d_TiledGrid3D_getOriginalTile);
    oluacls_func(L, "getTile", _cocos2d_TiledGrid3D_getTile);
    oluacls_func(L, "setTile", _cocos2d_TiledGrid3D_setTile);

    olua_registerluatype<cocos2d::TiledGrid3D>(L, "cc.TiledGrid3D");

    return 1;
}

static int _cocos2d_NodeGrid___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::NodeGrid *)olua_toobj(L, 1, "cc.NodeGrid");
    olua_push_cppobj(L, self, "cc.NodeGrid");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_NodeGrid_create1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::NodeGrid *create()
    cocos2d::NodeGrid *ret = (cocos2d::NodeGrid *)cocos2d::NodeGrid::create();
    int num_ret = olua_push_cppobj(L, ret, "cc.NodeGrid");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_NodeGrid_create2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Rect arg1;       /** rect */

    manual_olua_check_cocos2d_Rect(L, 1, &arg1);

    // static cocos2d::NodeGrid *create(const cocos2d::Rect &rect)
    cocos2d::NodeGrid *ret = (cocos2d::NodeGrid *)cocos2d::NodeGrid::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.NodeGrid");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_NodeGrid_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::NodeGrid *create()
        return _cocos2d_NodeGrid_create1(L);
    }

    if (num_args == 1) {
        // if ((manual_olua_is_cocos2d_Rect(L, 1))) {
            // static cocos2d::NodeGrid *create(const cocos2d::Rect &rect)
            return _cocos2d_NodeGrid_create2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::NodeGrid::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_NodeGrid_getGrid(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::NodeGrid *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.NodeGrid");

    // cocos2d::GridBase *getGrid()
    cocos2d::GridBase *ret = (cocos2d::GridBase *)self->getGrid();
    int num_ret = olua_push_cppobj(L, ret, "cc.GridBase");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_NodeGrid_getGridRect(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::NodeGrid *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.NodeGrid");

    // const cocos2d::Rect &getGridRect()
    const cocos2d::Rect &ret = (const cocos2d::Rect &)self->getGridRect();
    int num_ret = manual_olua_push_cocos2d_Rect(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_NodeGrid_setGrid(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::NodeGrid *self = nullptr;
    cocos2d::GridBase *arg1 = nullptr;       /** grid */

    olua_to_cppobj(L, 1, (void **)&self, "cc.NodeGrid");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.GridBase");

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.NodeGrid");
    manual_olua_check_cocos2d_Rect(L, 2, &arg1);

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.NodeGrid");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.Node");

    // void setTarget(cocos2d::Node *target)
    self->setTarget(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_NodeGrid(lua_State *L)
{
    oluacls_class(L, "cc.NodeGrid", "cc.Node");
    oluacls_func(L, "__move", _cocos2d_NodeGrid___move);
    oluacls_func(L, "create", _cocos2d_NodeGrid_create);
    oluacls_func(L, "getGrid", _cocos2d_NodeGrid_getGrid);
    oluacls_func(L, "getGridRect", _cocos2d_NodeGrid_getGridRect);
    oluacls_func(L, "setGrid", _cocos2d_NodeGrid_setGrid);
    oluacls_func(L, "setGridRect", _cocos2d_NodeGrid_setGridRect);
    oluacls_func(L, "setTarget", _cocos2d_NodeGrid_setTarget);
    oluacls_prop(L, "grid", _cocos2d_NodeGrid_getGrid, _cocos2d_NodeGrid_setGrid);
    oluacls_prop(L, "gridRect", _cocos2d_NodeGrid_getGridRect, _cocos2d_NodeGrid_setGridRect);

    olua_registerluatype<cocos2d::NodeGrid>(L, "cc.NodeGrid");

    return 1;
}

static int _cocos2d_GridAction___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::GridAction *)olua_toobj(L, 1, "cc.GridAction");
    olua_push_cppobj(L, self, "cc.GridAction");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_GridAction_getGrid(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::GridAction *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.GridAction");

    // cocos2d::GridBase *getGrid()
    cocos2d::GridBase *ret = (cocos2d::GridBase *)self->getGrid();
    int num_ret = olua_push_cppobj(L, ret, "cc.GridBase");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_GridAction(lua_State *L)
{
    oluacls_class(L, "cc.GridAction", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_GridAction___move);
    oluacls_func(L, "getGrid", _cocos2d_GridAction_getGrid);
    oluacls_prop(L, "grid", _cocos2d_GridAction_getGrid, nullptr);

    olua_registerluatype<cocos2d::GridAction>(L, "cc.GridAction");

    return 1;
}

static int _cocos2d_Grid3DAction___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Grid3DAction *)olua_toobj(L, 1, "cc.Grid3DAction");
    olua_push_cppobj(L, self, "cc.Grid3DAction");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_Grid3DAction_getGridRect(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Grid3DAction *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.Grid3DAction");

    // cocos2d::Rect getGridRect()
    cocos2d::Rect ret = (cocos2d::Rect)self->getGridRect();
    int num_ret = manual_olua_push_cocos2d_Rect(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Grid3DAction_getOriginalVertex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Grid3DAction *self = nullptr;
    cocos2d::Vec2 arg1;       /** position */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Grid3DAction");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // cocos2d::Vec3 getOriginalVertex(const cocos2d::Vec2 &position)
    cocos2d::Vec3 ret = (cocos2d::Vec3)self->getOriginalVertex(arg1);
    int num_ret = auto_olua_push_cocos2d_Vec3(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Grid3DAction_getVertex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Grid3DAction *self = nullptr;
    cocos2d::Vec2 arg1;       /** position */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Grid3DAction");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // cocos2d::Vec3 getVertex(const cocos2d::Vec2 &position)
    cocos2d::Vec3 ret = (cocos2d::Vec3)self->getVertex(arg1);
    int num_ret = auto_olua_push_cocos2d_Vec3(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Grid3DAction_setVertex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Grid3DAction *self = nullptr;
    cocos2d::Vec2 arg1;       /** position */
    cocos2d::Vec3 arg2;       /** vertex */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Grid3DAction");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);
    auto_olua_check_cocos2d_Vec3(L, 3, &arg2);

    // void setVertex(const cocos2d::Vec2 &position, const cocos2d::Vec3 &vertex)
    self->setVertex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_Grid3DAction(lua_State *L)
{
    oluacls_class(L, "cc.Grid3DAction", "cc.GridAction");
    oluacls_func(L, "__move", _cocos2d_Grid3DAction___move);
    oluacls_func(L, "getGridRect", _cocos2d_Grid3DAction_getGridRect);
    oluacls_func(L, "getOriginalVertex", _cocos2d_Grid3DAction_getOriginalVertex);
    oluacls_func(L, "getVertex", _cocos2d_Grid3DAction_getVertex);
    oluacls_func(L, "setVertex", _cocos2d_Grid3DAction_setVertex);
    oluacls_prop(L, "gridRect", _cocos2d_Grid3DAction_getGridRect, nullptr);

    olua_registerluatype<cocos2d::Grid3DAction>(L, "cc.Grid3DAction");

    return 1;
}

static int _cocos2d_TiledGrid3DAction___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::TiledGrid3DAction *)olua_toobj(L, 1, "cc.TiledGrid3DAction");
    olua_push_cppobj(L, self, "cc.TiledGrid3DAction");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_TiledGrid3DAction_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Size(L, 2, &arg2);

    // static cocos2d::TiledGrid3DAction *create(float duration, const cocos2d::Size &gridSize)
    cocos2d::TiledGrid3DAction *ret = (cocos2d::TiledGrid3DAction *)cocos2d::TiledGrid3DAction::create((float)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.TiledGrid3DAction");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TiledGrid3DAction_getOriginalTile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TiledGrid3DAction *self = nullptr;
    cocos2d::Vec2 arg1;       /** position */

    olua_to_cppobj(L, 1, (void **)&self, "cc.TiledGrid3DAction");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // cocos2d::Quad3 getOriginalTile(const cocos2d::Vec2 &position)
    cocos2d::Quad3 ret = (cocos2d::Quad3)self->getOriginalTile(arg1);
    int num_ret = auto_olua_push_cocos2d_Quad3(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TiledGrid3DAction_getTile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TiledGrid3DAction *self = nullptr;
    cocos2d::Vec2 arg1;       /** position */

    olua_to_cppobj(L, 1, (void **)&self, "cc.TiledGrid3DAction");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // cocos2d::Quad3 getTile(const cocos2d::Vec2 &position)
    cocos2d::Quad3 ret = (cocos2d::Quad3)self->getTile(arg1);
    int num_ret = auto_olua_push_cocos2d_Quad3(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TiledGrid3DAction_setTile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TiledGrid3DAction *self = nullptr;
    cocos2d::Vec2 arg1;       /** position */
    cocos2d::Quad3 arg2;       /** coords */

    olua_to_cppobj(L, 1, (void **)&self, "cc.TiledGrid3DAction");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);
    auto_olua_check_cocos2d_Quad3(L, 3, &arg2);

    // void setTile(const cocos2d::Vec2 &position, const cocos2d::Quad3 &coords)
    self->setTile(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_TiledGrid3DAction(lua_State *L)
{
    oluacls_class(L, "cc.TiledGrid3DAction", "cc.GridAction");
    oluacls_func(L, "__move", _cocos2d_TiledGrid3DAction___move);
    oluacls_func(L, "create", _cocos2d_TiledGrid3DAction_create);
    oluacls_func(L, "getOriginalTile", _cocos2d_TiledGrid3DAction_getOriginalTile);
    oluacls_func(L, "getTile", _cocos2d_TiledGrid3DAction_getTile);
    oluacls_func(L, "setTile", _cocos2d_TiledGrid3DAction_setTile);

    olua_registerluatype<cocos2d::TiledGrid3DAction>(L, "cc.TiledGrid3DAction");

    return 1;
}

static int _cocos2d_AccelDeccelAmplitude___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::AccelDeccelAmplitude *)olua_toobj(L, 1, "cc.AccelDeccelAmplitude");
    olua_push_cppobj(L, self, "cc.AccelDeccelAmplitude");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_AccelDeccelAmplitude_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *arg1 = nullptr;       /** action */
    lua_Number arg2 = 0;       /** duration */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Action");
    olua_check_number(L, 2, &arg2);

    // static cocos2d::AccelDeccelAmplitude *create(cocos2d::Action *action, float duration)
    cocos2d::AccelDeccelAmplitude *ret = (cocos2d::AccelDeccelAmplitude *)cocos2d::AccelDeccelAmplitude::create(arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.AccelDeccelAmplitude");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_AccelDeccelAmplitude_getRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::AccelDeccelAmplitude *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.AccelDeccelAmplitude");

    // float getRate()
    float ret = (float)self->getRate();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_AccelDeccelAmplitude_setRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::AccelDeccelAmplitude *self = nullptr;
    lua_Number arg1 = 0;       /** rate */

    olua_to_cppobj(L, 1, (void **)&self, "cc.AccelDeccelAmplitude");
    olua_check_number(L, 2, &arg1);

    // void setRate(float rate)
    self->setRate((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_AccelDeccelAmplitude(lua_State *L)
{
    oluacls_class(L, "cc.AccelDeccelAmplitude", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_AccelDeccelAmplitude___move);
    oluacls_func(L, "create", _cocos2d_AccelDeccelAmplitude_create);
    oluacls_func(L, "getRate", _cocos2d_AccelDeccelAmplitude_getRate);
    oluacls_func(L, "setRate", _cocos2d_AccelDeccelAmplitude_setRate);
    oluacls_prop(L, "rate", _cocos2d_AccelDeccelAmplitude_getRate, _cocos2d_AccelDeccelAmplitude_setRate);

    olua_registerluatype<cocos2d::AccelDeccelAmplitude>(L, "cc.AccelDeccelAmplitude");

    return 1;
}

static int _cocos2d_AccelAmplitude___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::AccelAmplitude *)olua_toobj(L, 1, "cc.AccelAmplitude");
    olua_push_cppobj(L, self, "cc.AccelAmplitude");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_AccelAmplitude_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *arg1 = nullptr;       /** action */
    lua_Number arg2 = 0;       /** duration */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Action");
    olua_check_number(L, 2, &arg2);

    // static cocos2d::AccelAmplitude *create(cocos2d::Action *action, float duration)
    cocos2d::AccelAmplitude *ret = (cocos2d::AccelAmplitude *)cocos2d::AccelAmplitude::create(arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.AccelAmplitude");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_AccelAmplitude_getRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::AccelAmplitude *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.AccelAmplitude");

    // float getRate()
    float ret = (float)self->getRate();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_AccelAmplitude_setRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::AccelAmplitude *self = nullptr;
    lua_Number arg1 = 0;       /** rate */

    olua_to_cppobj(L, 1, (void **)&self, "cc.AccelAmplitude");
    olua_check_number(L, 2, &arg1);

    // void setRate(float rate)
    self->setRate((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_AccelAmplitude(lua_State *L)
{
    oluacls_class(L, "cc.AccelAmplitude", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_AccelAmplitude___move);
    oluacls_func(L, "create", _cocos2d_AccelAmplitude_create);
    oluacls_func(L, "getRate", _cocos2d_AccelAmplitude_getRate);
    oluacls_func(L, "setRate", _cocos2d_AccelAmplitude_setRate);
    oluacls_prop(L, "rate", _cocos2d_AccelAmplitude_getRate, _cocos2d_AccelAmplitude_setRate);

    olua_registerluatype<cocos2d::AccelAmplitude>(L, "cc.AccelAmplitude");

    return 1;
}

static int _cocos2d_DeccelAmplitude___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::DeccelAmplitude *)olua_toobj(L, 1, "cc.DeccelAmplitude");
    olua_push_cppobj(L, self, "cc.DeccelAmplitude");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_DeccelAmplitude_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Action *arg1 = nullptr;       /** action */
    lua_Number arg2 = 0;       /** duration */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Action");
    olua_check_number(L, 2, &arg2);

    // static cocos2d::DeccelAmplitude *create(cocos2d::Action *action, float duration)
    cocos2d::DeccelAmplitude *ret = (cocos2d::DeccelAmplitude *)cocos2d::DeccelAmplitude::create(arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.DeccelAmplitude");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_DeccelAmplitude_getRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::DeccelAmplitude *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.DeccelAmplitude");

    // float getRate()
    float ret = (float)self->getRate();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_DeccelAmplitude_setRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::DeccelAmplitude *self = nullptr;
    lua_Number arg1 = 0;       /** rate */

    olua_to_cppobj(L, 1, (void **)&self, "cc.DeccelAmplitude");
    olua_check_number(L, 2, &arg1);

    // void setRate(float rate)
    self->setRate((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_DeccelAmplitude(lua_State *L)
{
    oluacls_class(L, "cc.DeccelAmplitude", "cc.ActionInterval");
    oluacls_func(L, "__move", _cocos2d_DeccelAmplitude___move);
    oluacls_func(L, "create", _cocos2d_DeccelAmplitude_create);
    oluacls_func(L, "getRate", _cocos2d_DeccelAmplitude_getRate);
    oluacls_func(L, "setRate", _cocos2d_DeccelAmplitude_setRate);
    oluacls_prop(L, "rate", _cocos2d_DeccelAmplitude_getRate, _cocos2d_DeccelAmplitude_setRate);

    olua_registerluatype<cocos2d::DeccelAmplitude>(L, "cc.DeccelAmplitude");

    return 1;
}

static int _cocos2d_StopGrid___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::StopGrid *)olua_toobj(L, 1, "cc.StopGrid");
    olua_push_cppobj(L, self, "cc.StopGrid");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_StopGrid_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::StopGrid *create()
    cocos2d::StopGrid *ret = (cocos2d::StopGrid *)cocos2d::StopGrid::create();
    int num_ret = olua_push_cppobj(L, ret, "cc.StopGrid");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_StopGrid(lua_State *L)
{
    oluacls_class(L, "cc.StopGrid", "cc.ActionInstant");
    oluacls_func(L, "__move", _cocos2d_StopGrid___move);
    oluacls_func(L, "create", _cocos2d_StopGrid_create);

    olua_registerluatype<cocos2d::StopGrid>(L, "cc.StopGrid");

    return 1;
}

static int _cocos2d_ReuseGrid___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ReuseGrid *)olua_toobj(L, 1, "cc.ReuseGrid");
    olua_push_cppobj(L, self, "cc.ReuseGrid");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ReuseGrid_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** times */

    olua_check_int(L, 1, &arg1);

    // static cocos2d::ReuseGrid *create(int times)
    cocos2d::ReuseGrid *ret = (cocos2d::ReuseGrid *)cocos2d::ReuseGrid::create((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.ReuseGrid");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ReuseGrid_initWithTimes(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ReuseGrid *self = nullptr;
    lua_Integer arg1 = 0;       /** times */

    olua_to_cppobj(L, 1, (void **)&self, "cc.ReuseGrid");
    olua_check_int(L, 2, &arg1);

    // bool initWithTimes(int times)
    bool ret = (bool)self->initWithTimes((int)arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_ReuseGrid(lua_State *L)
{
    oluacls_class(L, "cc.ReuseGrid", "cc.ActionInstant");
    oluacls_func(L, "__move", _cocos2d_ReuseGrid___move);
    oluacls_func(L, "create", _cocos2d_ReuseGrid_create);
    oluacls_func(L, "initWithTimes", _cocos2d_ReuseGrid_initWithTimes);

    olua_registerluatype<cocos2d::ReuseGrid>(L, "cc.ReuseGrid");

    return 1;
}

static int _cocos2d_Waves3D___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Waves3D *)olua_toobj(L, 1, "cc.Waves3D");
    olua_push_cppobj(L, self, "cc.Waves3D");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_Waves3D_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */
    lua_Unsigned arg3 = 0;       /** waves */
    lua_Number arg4 = 0;       /** amplitude */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Size(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // static cocos2d::Waves3D *create(float duration, const cocos2d::Size &gridSize, unsigned int waves, float amplitude)
    cocos2d::Waves3D *ret = (cocos2d::Waves3D *)cocos2d::Waves3D::create((float)arg1, arg2, (unsigned int)arg3, (float)arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.Waves3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Waves3D_getAmplitude(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Waves3D *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.Waves3D");

    // float getAmplitude()
    float ret = (float)self->getAmplitude();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Waves3D_setAmplitude(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Waves3D *self = nullptr;
    lua_Number arg1 = 0;       /** amplitude */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Waves3D");
    olua_check_number(L, 2, &arg1);

    // void setAmplitude(float amplitude)
    self->setAmplitude((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_Waves3D(lua_State *L)
{
    oluacls_class(L, "cc.Waves3D", "cc.Grid3DAction");
    oluacls_func(L, "__move", _cocos2d_Waves3D___move);
    oluacls_func(L, "create", _cocos2d_Waves3D_create);
    oluacls_func(L, "getAmplitude", _cocos2d_Waves3D_getAmplitude);
    oluacls_func(L, "setAmplitude", _cocos2d_Waves3D_setAmplitude);
    oluacls_prop(L, "amplitude", _cocos2d_Waves3D_getAmplitude, _cocos2d_Waves3D_setAmplitude);

    olua_registerluatype<cocos2d::Waves3D>(L, "cc.Waves3D");

    return 1;
}

static int _cocos2d_FlipX3D___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::FlipX3D *)olua_toobj(L, 1, "cc.FlipX3D");
    olua_push_cppobj(L, self, "cc.FlipX3D");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_FlipX3D_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */

    olua_check_number(L, 1, &arg1);

    // static cocos2d::FlipX3D *create(float duration)
    cocos2d::FlipX3D *ret = (cocos2d::FlipX3D *)cocos2d::FlipX3D::create((float)arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.FlipX3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_FlipX3D_initWithSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FlipX3D *self = nullptr;
    cocos2d::Size arg1;       /** gridSize */
    lua_Number arg2 = 0;       /** duration */

    olua_to_cppobj(L, 1, (void **)&self, "cc.FlipX3D");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // bool initWithSize(const cocos2d::Size &gridSize, float duration)
    bool ret = (bool)self->initWithSize(arg1, (float)arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_FlipX3D(lua_State *L)
{
    oluacls_class(L, "cc.FlipX3D", "cc.Grid3DAction");
    oluacls_func(L, "__move", _cocos2d_FlipX3D___move);
    oluacls_func(L, "create", _cocos2d_FlipX3D_create);
    oluacls_func(L, "initWithSize", _cocos2d_FlipX3D_initWithSize);

    olua_registerluatype<cocos2d::FlipX3D>(L, "cc.FlipX3D");

    return 1;
}

static int _cocos2d_FlipY3D___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::FlipY3D *)olua_toobj(L, 1, "cc.FlipY3D");
    olua_push_cppobj(L, self, "cc.FlipY3D");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_FlipY3D_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */

    olua_check_number(L, 1, &arg1);

    // static cocos2d::FlipY3D *create(float duration)
    cocos2d::FlipY3D *ret = (cocos2d::FlipY3D *)cocos2d::FlipY3D::create((float)arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.FlipY3D");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_FlipY3D(lua_State *L)
{
    oluacls_class(L, "cc.FlipY3D", "cc.FlipX3D");
    oluacls_func(L, "__move", _cocos2d_FlipY3D___move);
    oluacls_func(L, "create", _cocos2d_FlipY3D_create);

    olua_registerluatype<cocos2d::FlipY3D>(L, "cc.FlipY3D");

    return 1;
}

static int _cocos2d_Lens3D___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Lens3D *)olua_toobj(L, 1, "cc.Lens3D");
    olua_push_cppobj(L, self, "cc.Lens3D");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_Lens3D_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */
    cocos2d::Vec2 arg3;       /** position */
    lua_Number arg4 = 0;       /** radius */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Size(L, 2, &arg2);
    auto_olua_check_cocos2d_Vec2(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // static cocos2d::Lens3D *create(float duration, const cocos2d::Size &gridSize, const cocos2d::Vec2 &position, float radius)
    cocos2d::Lens3D *ret = (cocos2d::Lens3D *)cocos2d::Lens3D::create((float)arg1, arg2, arg3, (float)arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.Lens3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Lens3D_getLensEffect(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Lens3D *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.Lens3D");

    // float getLensEffect()
    float ret = (float)self->getLensEffect();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Lens3D_getPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Lens3D *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.Lens3D");

    // const cocos2d::Vec2 &getPosition()
    const cocos2d::Vec2 &ret = (const cocos2d::Vec2 &)self->getPosition();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Lens3D_setConcave(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Lens3D *self = nullptr;
    bool arg1 = false;       /** concave */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Lens3D");
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
    lua_Number arg1 = 0;       /** lensEffect */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Lens3D");
    olua_check_number(L, 2, &arg1);

    // void setLensEffect(float lensEffect)
    self->setLensEffect((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_Lens3D_setPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Lens3D *self = nullptr;
    cocos2d::Vec2 arg1;       /** position */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Lens3D");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void setPosition(const cocos2d::Vec2 &position)
    self->setPosition(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_Lens3D(lua_State *L)
{
    oluacls_class(L, "cc.Lens3D", "cc.Grid3DAction");
    oluacls_func(L, "__move", _cocos2d_Lens3D___move);
    oluacls_func(L, "create", _cocos2d_Lens3D_create);
    oluacls_func(L, "getLensEffect", _cocos2d_Lens3D_getLensEffect);
    oluacls_func(L, "getPosition", _cocos2d_Lens3D_getPosition);
    oluacls_func(L, "setConcave", _cocos2d_Lens3D_setConcave);
    oluacls_func(L, "setLensEffect", _cocos2d_Lens3D_setLensEffect);
    oluacls_func(L, "setPosition", _cocos2d_Lens3D_setPosition);
    oluacls_prop(L, "lensEffect", _cocos2d_Lens3D_getLensEffect, _cocos2d_Lens3D_setLensEffect);
    oluacls_prop(L, "position", _cocos2d_Lens3D_getPosition, _cocos2d_Lens3D_setPosition);

    olua_registerluatype<cocos2d::Lens3D>(L, "cc.Lens3D");

    return 1;
}

static int _cocos2d_Ripple3D___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Ripple3D *)olua_toobj(L, 1, "cc.Ripple3D");
    olua_push_cppobj(L, self, "cc.Ripple3D");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_Ripple3D_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */
    cocos2d::Vec2 arg3;       /** position */
    lua_Number arg4 = 0;       /** radius */
    lua_Unsigned arg5 = 0;       /** waves */
    lua_Number arg6 = 0;       /** amplitude */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Size(L, 2, &arg2);
    auto_olua_check_cocos2d_Vec2(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);
    olua_check_uint(L, 5, &arg5);
    olua_check_number(L, 6, &arg6);

    // static cocos2d::Ripple3D *create(float duration, const cocos2d::Size &gridSize, const cocos2d::Vec2 &position, float radius, unsigned int waves, float amplitude)
    cocos2d::Ripple3D *ret = (cocos2d::Ripple3D *)cocos2d::Ripple3D::create((float)arg1, arg2, arg3, (float)arg4, (unsigned int)arg5, (float)arg6);
    int num_ret = olua_push_cppobj(L, ret, "cc.Ripple3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Ripple3D_getAmplitude(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Ripple3D *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.Ripple3D");

    // float getAmplitude()
    float ret = (float)self->getAmplitude();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Ripple3D_getPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Ripple3D *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.Ripple3D");

    // const cocos2d::Vec2 &getPosition()
    const cocos2d::Vec2 &ret = (const cocos2d::Vec2 &)self->getPosition();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Ripple3D_setAmplitude(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Ripple3D *self = nullptr;
    lua_Number arg1 = 0;       /** fAmplitude */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Ripple3D");
    olua_check_number(L, 2, &arg1);

    // void setAmplitude(float fAmplitude)
    self->setAmplitude((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_Ripple3D_setPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Ripple3D *self = nullptr;
    cocos2d::Vec2 arg1;       /** position */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Ripple3D");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void setPosition(const cocos2d::Vec2 &position)
    self->setPosition(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_Ripple3D(lua_State *L)
{
    oluacls_class(L, "cc.Ripple3D", "cc.Grid3DAction");
    oluacls_func(L, "__move", _cocos2d_Ripple3D___move);
    oluacls_func(L, "create", _cocos2d_Ripple3D_create);
    oluacls_func(L, "getAmplitude", _cocos2d_Ripple3D_getAmplitude);
    oluacls_func(L, "getPosition", _cocos2d_Ripple3D_getPosition);
    oluacls_func(L, "setAmplitude", _cocos2d_Ripple3D_setAmplitude);
    oluacls_func(L, "setPosition", _cocos2d_Ripple3D_setPosition);
    oluacls_prop(L, "amplitude", _cocos2d_Ripple3D_getAmplitude, _cocos2d_Ripple3D_setAmplitude);
    oluacls_prop(L, "position", _cocos2d_Ripple3D_getPosition, _cocos2d_Ripple3D_setPosition);

    olua_registerluatype<cocos2d::Ripple3D>(L, "cc.Ripple3D");

    return 1;
}

static int _cocos2d_Shaky3D___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Shaky3D *)olua_toobj(L, 1, "cc.Shaky3D");
    olua_push_cppobj(L, self, "cc.Shaky3D");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_Shaky3D_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** initWithDuration */
    cocos2d::Size arg2;       /** gridSize */
    lua_Integer arg3 = 0;       /** range */
    bool arg4 = false;       /** shakeZ */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Size(L, 2, &arg2);
    olua_check_int(L, 3, &arg3);
    olua_check_bool(L, 4, &arg4);

    // static cocos2d::Shaky3D *create(float initWithDuration, const cocos2d::Size &gridSize, int range, bool shakeZ)
    cocos2d::Shaky3D *ret = (cocos2d::Shaky3D *)cocos2d::Shaky3D::create((float)arg1, arg2, (int)arg3, arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.Shaky3D");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_Shaky3D(lua_State *L)
{
    oluacls_class(L, "cc.Shaky3D", "cc.Grid3DAction");
    oluacls_func(L, "__move", _cocos2d_Shaky3D___move);
    oluacls_func(L, "create", _cocos2d_Shaky3D_create);

    olua_registerluatype<cocos2d::Shaky3D>(L, "cc.Shaky3D");

    return 1;
}

static int _cocos2d_Liquid___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Liquid *)olua_toobj(L, 1, "cc.Liquid");
    olua_push_cppobj(L, self, "cc.Liquid");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_Liquid_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */
    lua_Unsigned arg3 = 0;       /** waves */
    lua_Number arg4 = 0;       /** amplitude */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Size(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // static cocos2d::Liquid *create(float duration, const cocos2d::Size &gridSize, unsigned int waves, float amplitude)
    cocos2d::Liquid *ret = (cocos2d::Liquid *)cocos2d::Liquid::create((float)arg1, arg2, (unsigned int)arg3, (float)arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.Liquid");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Liquid_getAmplitude(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Liquid *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.Liquid");

    // float getAmplitude()
    float ret = (float)self->getAmplitude();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Liquid_setAmplitude(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Liquid *self = nullptr;
    lua_Number arg1 = 0;       /** amplitude */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Liquid");
    olua_check_number(L, 2, &arg1);

    // void setAmplitude(float amplitude)
    self->setAmplitude((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_Liquid(lua_State *L)
{
    oluacls_class(L, "cc.Liquid", "cc.Grid3DAction");
    oluacls_func(L, "__move", _cocos2d_Liquid___move);
    oluacls_func(L, "create", _cocos2d_Liquid_create);
    oluacls_func(L, "getAmplitude", _cocos2d_Liquid_getAmplitude);
    oluacls_func(L, "setAmplitude", _cocos2d_Liquid_setAmplitude);
    oluacls_prop(L, "amplitude", _cocos2d_Liquid_getAmplitude, _cocos2d_Liquid_setAmplitude);

    olua_registerluatype<cocos2d::Liquid>(L, "cc.Liquid");

    return 1;
}

static int _cocos2d_Waves___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Waves *)olua_toobj(L, 1, "cc.Waves");
    olua_push_cppobj(L, self, "cc.Waves");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_Waves_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */
    lua_Unsigned arg3 = 0;       /** waves */
    lua_Number arg4 = 0;       /** amplitude */
    bool arg5 = false;       /** horizontal */
    bool arg6 = false;       /** vertical */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Size(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);
    olua_check_bool(L, 5, &arg5);
    olua_check_bool(L, 6, &arg6);

    // static cocos2d::Waves *create(float duration, const cocos2d::Size &gridSize, unsigned int waves, float amplitude, bool horizontal, bool vertical)
    cocos2d::Waves *ret = (cocos2d::Waves *)cocos2d::Waves::create((float)arg1, arg2, (unsigned int)arg3, (float)arg4, arg5, arg6);
    int num_ret = olua_push_cppobj(L, ret, "cc.Waves");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Waves_getAmplitude(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Waves *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.Waves");

    // float getAmplitude()
    float ret = (float)self->getAmplitude();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Waves_setAmplitude(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Waves *self = nullptr;
    lua_Number arg1 = 0;       /** amplitude */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Waves");
    olua_check_number(L, 2, &arg1);

    // void setAmplitude(float amplitude)
    self->setAmplitude((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_Waves(lua_State *L)
{
    oluacls_class(L, "cc.Waves", "cc.Grid3DAction");
    oluacls_func(L, "__move", _cocos2d_Waves___move);
    oluacls_func(L, "create", _cocos2d_Waves_create);
    oluacls_func(L, "getAmplitude", _cocos2d_Waves_getAmplitude);
    oluacls_func(L, "setAmplitude", _cocos2d_Waves_setAmplitude);
    oluacls_prop(L, "amplitude", _cocos2d_Waves_getAmplitude, _cocos2d_Waves_setAmplitude);

    olua_registerluatype<cocos2d::Waves>(L, "cc.Waves");

    return 1;
}

static int _cocos2d_Twirl___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Twirl *)olua_toobj(L, 1, "cc.Twirl");
    olua_push_cppobj(L, self, "cc.Twirl");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_Twirl_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */
    cocos2d::Vec2 arg3;       /** position */
    lua_Unsigned arg4 = 0;       /** twirls */
    lua_Number arg5 = 0;       /** amplitude */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Size(L, 2, &arg2);
    auto_olua_check_cocos2d_Vec2(L, 3, &arg3);
    olua_check_uint(L, 4, &arg4);
    olua_check_number(L, 5, &arg5);

    // static cocos2d::Twirl *create(float duration, const cocos2d::Size &gridSize, const cocos2d::Vec2 &position, unsigned int twirls, float amplitude)
    cocos2d::Twirl *ret = (cocos2d::Twirl *)cocos2d::Twirl::create((float)arg1, arg2, arg3, (unsigned int)arg4, (float)arg5);
    int num_ret = olua_push_cppobj(L, ret, "cc.Twirl");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Twirl_getAmplitude(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Twirl *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.Twirl");

    // float getAmplitude()
    float ret = (float)self->getAmplitude();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Twirl_getPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Twirl *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.Twirl");

    // const cocos2d::Vec2 &getPosition()
    const cocos2d::Vec2 &ret = (const cocos2d::Vec2 &)self->getPosition();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_Twirl_setAmplitude(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Twirl *self = nullptr;
    lua_Number arg1 = 0;       /** amplitude */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Twirl");
    olua_check_number(L, 2, &arg1);

    // void setAmplitude(float amplitude)
    self->setAmplitude((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_Twirl_setPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Twirl *self = nullptr;
    cocos2d::Vec2 arg1;       /** position */

    olua_to_cppobj(L, 1, (void **)&self, "cc.Twirl");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void setPosition(const cocos2d::Vec2 &position)
    self->setPosition(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_Twirl(lua_State *L)
{
    oluacls_class(L, "cc.Twirl", "cc.Grid3DAction");
    oluacls_func(L, "__move", _cocos2d_Twirl___move);
    oluacls_func(L, "create", _cocos2d_Twirl_create);
    oluacls_func(L, "getAmplitude", _cocos2d_Twirl_getAmplitude);
    oluacls_func(L, "getPosition", _cocos2d_Twirl_getPosition);
    oluacls_func(L, "setAmplitude", _cocos2d_Twirl_setAmplitude);
    oluacls_func(L, "setPosition", _cocos2d_Twirl_setPosition);
    oluacls_prop(L, "amplitude", _cocos2d_Twirl_getAmplitude, _cocos2d_Twirl_setAmplitude);
    oluacls_prop(L, "position", _cocos2d_Twirl_getPosition, _cocos2d_Twirl_setPosition);

    olua_registerluatype<cocos2d::Twirl>(L, "cc.Twirl");

    return 1;
}

static int _cocos2d_PageTurn3D___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PageTurn3D *)olua_toobj(L, 1, "cc.PageTurn3D");
    olua_push_cppobj(L, self, "cc.PageTurn3D");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PageTurn3D_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Size(L, 2, &arg2);

    // static cocos2d::PageTurn3D *create(float duration, const cocos2d::Size &gridSize)
    cocos2d::PageTurn3D *ret = (cocos2d::PageTurn3D *)cocos2d::PageTurn3D::create((float)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.PageTurn3D");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_PageTurn3D(lua_State *L)
{
    oluacls_class(L, "cc.PageTurn3D", "cc.Grid3DAction");
    oluacls_func(L, "__move", _cocos2d_PageTurn3D___move);
    oluacls_func(L, "create", _cocos2d_PageTurn3D_create);

    olua_registerluatype<cocos2d::PageTurn3D>(L, "cc.PageTurn3D");

    return 1;
}

static int _cocos2d_ShakyTiles3D___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ShakyTiles3D *)olua_toobj(L, 1, "cc.ShakyTiles3D");
    olua_push_cppobj(L, self, "cc.ShakyTiles3D");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ShakyTiles3D_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */
    lua_Integer arg3 = 0;       /** range */
    bool arg4 = false;       /** shakeZ */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Size(L, 2, &arg2);
    olua_check_int(L, 3, &arg3);
    olua_check_bool(L, 4, &arg4);

    // static cocos2d::ShakyTiles3D *create(float duration, const cocos2d::Size &gridSize, int range, bool shakeZ)
    cocos2d::ShakyTiles3D *ret = (cocos2d::ShakyTiles3D *)cocos2d::ShakyTiles3D::create((float)arg1, arg2, (int)arg3, arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.ShakyTiles3D");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_ShakyTiles3D(lua_State *L)
{
    oluacls_class(L, "cc.ShakyTiles3D", "cc.TiledGrid3DAction");
    oluacls_func(L, "__move", _cocos2d_ShakyTiles3D___move);
    oluacls_func(L, "create", _cocos2d_ShakyTiles3D_create);

    olua_registerluatype<cocos2d::ShakyTiles3D>(L, "cc.ShakyTiles3D");

    return 1;
}

static int _cocos2d_ShatteredTiles3D___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ShatteredTiles3D *)olua_toobj(L, 1, "cc.ShatteredTiles3D");
    olua_push_cppobj(L, self, "cc.ShatteredTiles3D");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ShatteredTiles3D_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */
    lua_Integer arg3 = 0;       /** range */
    bool arg4 = false;       /** shatterZ */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Size(L, 2, &arg2);
    olua_check_int(L, 3, &arg3);
    olua_check_bool(L, 4, &arg4);

    // static cocos2d::ShatteredTiles3D *create(float duration, const cocos2d::Size &gridSize, int range, bool shatterZ)
    cocos2d::ShatteredTiles3D *ret = (cocos2d::ShatteredTiles3D *)cocos2d::ShatteredTiles3D::create((float)arg1, arg2, (int)arg3, arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.ShatteredTiles3D");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_ShatteredTiles3D(lua_State *L)
{
    oluacls_class(L, "cc.ShatteredTiles3D", "cc.TiledGrid3DAction");
    oluacls_func(L, "__move", _cocos2d_ShatteredTiles3D___move);
    oluacls_func(L, "create", _cocos2d_ShatteredTiles3D_create);

    olua_registerluatype<cocos2d::ShatteredTiles3D>(L, "cc.ShatteredTiles3D");

    return 1;
}

static int _cocos2d_ShuffleTiles___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ShuffleTiles *)olua_toobj(L, 1, "cc.ShuffleTiles");
    olua_push_cppobj(L, self, "cc.ShuffleTiles");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_ShuffleTiles_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */
    lua_Unsigned arg3 = 0;       /** seed */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Size(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);

    // static cocos2d::ShuffleTiles *create(float duration, const cocos2d::Size &gridSize, unsigned int seed)
    cocos2d::ShuffleTiles *ret = (cocos2d::ShuffleTiles *)cocos2d::ShuffleTiles::create((float)arg1, arg2, (unsigned int)arg3);
    int num_ret = olua_push_cppobj(L, ret, "cc.ShuffleTiles");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_ShuffleTiles_getDelta(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ShuffleTiles *self = nullptr;
    cocos2d::Size arg1;       /** pos */

    olua_to_cppobj(L, 1, (void **)&self, "cc.ShuffleTiles");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);

    // cocos2d::Size getDelta(const cocos2d::Size &pos)
    cocos2d::Size ret = (cocos2d::Size)self->getDelta(arg1);
    int num_ret = auto_olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_ShuffleTiles(lua_State *L)
{
    oluacls_class(L, "cc.ShuffleTiles", "cc.TiledGrid3DAction");
    oluacls_func(L, "__move", _cocos2d_ShuffleTiles___move);
    oluacls_func(L, "create", _cocos2d_ShuffleTiles_create);
    oluacls_func(L, "getDelta", _cocos2d_ShuffleTiles_getDelta);

    olua_registerluatype<cocos2d::ShuffleTiles>(L, "cc.ShuffleTiles");

    return 1;
}

static int _cocos2d_FadeOutTRTiles___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::FadeOutTRTiles *)olua_toobj(L, 1, "cc.FadeOutTRTiles");
    olua_push_cppobj(L, self, "cc.FadeOutTRTiles");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_FadeOutTRTiles_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Size(L, 2, &arg2);

    // static cocos2d::FadeOutTRTiles *create(float duration, const cocos2d::Size &gridSize)
    cocos2d::FadeOutTRTiles *ret = (cocos2d::FadeOutTRTiles *)cocos2d::FadeOutTRTiles::create((float)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.FadeOutTRTiles");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_FadeOutTRTiles_testFunc(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FadeOutTRTiles *self = nullptr;
    cocos2d::Size arg1;       /** pos */
    lua_Number arg2 = 0;       /** time */

    olua_to_cppobj(L, 1, (void **)&self, "cc.FadeOutTRTiles");
    auto_olua_check_cocos2d_Size(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // float testFunc(const cocos2d::Size &pos, float time)
    float ret = (float)self->testFunc(arg1, (float)arg2);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_FadeOutTRTiles_transformTile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FadeOutTRTiles *self = nullptr;
    cocos2d::Vec2 arg1;       /** pos */
    lua_Number arg2 = 0;       /** distance */

    olua_to_cppobj(L, 1, (void **)&self, "cc.FadeOutTRTiles");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void transformTile(const cocos2d::Vec2 &pos, float distance)
    self->transformTile(arg1, (float)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_FadeOutTRTiles_turnOffTile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::FadeOutTRTiles *self = nullptr;
    cocos2d::Vec2 arg1;       /** pos */

    olua_to_cppobj(L, 1, (void **)&self, "cc.FadeOutTRTiles");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.FadeOutTRTiles");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void turnOnTile(const cocos2d::Vec2 &pos)
    self->turnOnTile(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_FadeOutTRTiles(lua_State *L)
{
    oluacls_class(L, "cc.FadeOutTRTiles", "cc.TiledGrid3DAction");
    oluacls_func(L, "__move", _cocos2d_FadeOutTRTiles___move);
    oluacls_func(L, "create", _cocos2d_FadeOutTRTiles_create);
    oluacls_func(L, "testFunc", _cocos2d_FadeOutTRTiles_testFunc);
    oluacls_func(L, "transformTile", _cocos2d_FadeOutTRTiles_transformTile);
    oluacls_func(L, "turnOffTile", _cocos2d_FadeOutTRTiles_turnOffTile);
    oluacls_func(L, "turnOnTile", _cocos2d_FadeOutTRTiles_turnOnTile);

    olua_registerluatype<cocos2d::FadeOutTRTiles>(L, "cc.FadeOutTRTiles");

    return 1;
}

static int _cocos2d_FadeOutBLTiles___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::FadeOutBLTiles *)olua_toobj(L, 1, "cc.FadeOutBLTiles");
    olua_push_cppobj(L, self, "cc.FadeOutBLTiles");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_FadeOutBLTiles_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Size(L, 2, &arg2);

    // static cocos2d::FadeOutBLTiles *create(float duration, const cocos2d::Size &gridSize)
    cocos2d::FadeOutBLTiles *ret = (cocos2d::FadeOutBLTiles *)cocos2d::FadeOutBLTiles::create((float)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.FadeOutBLTiles");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_FadeOutBLTiles(lua_State *L)
{
    oluacls_class(L, "cc.FadeOutBLTiles", "cc.FadeOutTRTiles");
    oluacls_func(L, "__move", _cocos2d_FadeOutBLTiles___move);
    oluacls_func(L, "create", _cocos2d_FadeOutBLTiles_create);

    olua_registerluatype<cocos2d::FadeOutBLTiles>(L, "cc.FadeOutBLTiles");

    return 1;
}

static int _cocos2d_FadeOutUpTiles___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::FadeOutUpTiles *)olua_toobj(L, 1, "cc.FadeOutUpTiles");
    olua_push_cppobj(L, self, "cc.FadeOutUpTiles");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_FadeOutUpTiles_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Size(L, 2, &arg2);

    // static cocos2d::FadeOutUpTiles *create(float duration, const cocos2d::Size &gridSize)
    cocos2d::FadeOutUpTiles *ret = (cocos2d::FadeOutUpTiles *)cocos2d::FadeOutUpTiles::create((float)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.FadeOutUpTiles");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_FadeOutUpTiles(lua_State *L)
{
    oluacls_class(L, "cc.FadeOutUpTiles", "cc.FadeOutTRTiles");
    oluacls_func(L, "__move", _cocos2d_FadeOutUpTiles___move);
    oluacls_func(L, "create", _cocos2d_FadeOutUpTiles_create);

    olua_registerluatype<cocos2d::FadeOutUpTiles>(L, "cc.FadeOutUpTiles");

    return 1;
}

static int _cocos2d_FadeOutDownTiles___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::FadeOutDownTiles *)olua_toobj(L, 1, "cc.FadeOutDownTiles");
    olua_push_cppobj(L, self, "cc.FadeOutDownTiles");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_FadeOutDownTiles_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Size(L, 2, &arg2);

    // static cocos2d::FadeOutDownTiles *create(float duration, const cocos2d::Size &gridSize)
    cocos2d::FadeOutDownTiles *ret = (cocos2d::FadeOutDownTiles *)cocos2d::FadeOutDownTiles::create((float)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.FadeOutDownTiles");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_FadeOutDownTiles(lua_State *L)
{
    oluacls_class(L, "cc.FadeOutDownTiles", "cc.FadeOutUpTiles");
    oluacls_func(L, "__move", _cocos2d_FadeOutDownTiles___move);
    oluacls_func(L, "create", _cocos2d_FadeOutDownTiles_create);

    olua_registerluatype<cocos2d::FadeOutDownTiles>(L, "cc.FadeOutDownTiles");

    return 1;
}

static int _cocos2d_TurnOffTiles___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::TurnOffTiles *)olua_toobj(L, 1, "cc.TurnOffTiles");
    olua_push_cppobj(L, self, "cc.TurnOffTiles");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_TurnOffTiles_create1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Size(L, 2, &arg2);

    // static cocos2d::TurnOffTiles *create(float duration, const cocos2d::Size &gridSize)
    cocos2d::TurnOffTiles *ret = (cocos2d::TurnOffTiles *)cocos2d::TurnOffTiles::create((float)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.TurnOffTiles");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TurnOffTiles_create2(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */
    lua_Unsigned arg3 = 0;       /** seed */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Size(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);

    // static cocos2d::TurnOffTiles *create(float duration, const cocos2d::Size &gridSize, unsigned int seed)
    cocos2d::TurnOffTiles *ret = (cocos2d::TurnOffTiles *)cocos2d::TurnOffTiles::create((float)arg1, arg2, (unsigned int)arg3);
    int num_ret = olua_push_cppobj(L, ret, "cc.TurnOffTiles");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_TurnOffTiles_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_number(L, 1)) && (auto_olua_is_cocos2d_Size(L, 2))) {
            // static cocos2d::TurnOffTiles *create(float duration, const cocos2d::Size &gridSize)
            return _cocos2d_TurnOffTiles_create1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (auto_olua_is_cocos2d_Size(L, 2)) && (olua_is_uint(L, 3))) {
            // static cocos2d::TurnOffTiles *create(float duration, const cocos2d::Size &gridSize, unsigned int seed)
            return _cocos2d_TurnOffTiles_create2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::TurnOffTiles::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_TurnOffTiles_turnOffTile(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TurnOffTiles *self = nullptr;
    cocos2d::Vec2 arg1;       /** pos */

    olua_to_cppobj(L, 1, (void **)&self, "cc.TurnOffTiles");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.TurnOffTiles");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void turnOnTile(const cocos2d::Vec2 &pos)
    self->turnOnTile(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_TurnOffTiles(lua_State *L)
{
    oluacls_class(L, "cc.TurnOffTiles", "cc.TiledGrid3DAction");
    oluacls_func(L, "__move", _cocos2d_TurnOffTiles___move);
    oluacls_func(L, "create", _cocos2d_TurnOffTiles_create);
    oluacls_func(L, "turnOffTile", _cocos2d_TurnOffTiles_turnOffTile);
    oluacls_func(L, "turnOnTile", _cocos2d_TurnOffTiles_turnOnTile);

    olua_registerluatype<cocos2d::TurnOffTiles>(L, "cc.TurnOffTiles");

    return 1;
}

static int _cocos2d_WavesTiles3D___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::WavesTiles3D *)olua_toobj(L, 1, "cc.WavesTiles3D");
    olua_push_cppobj(L, self, "cc.WavesTiles3D");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_WavesTiles3D_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */
    lua_Unsigned arg3 = 0;       /** waves */
    lua_Number arg4 = 0;       /** amplitude */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Size(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // static cocos2d::WavesTiles3D *create(float duration, const cocos2d::Size &gridSize, unsigned int waves, float amplitude)
    cocos2d::WavesTiles3D *ret = (cocos2d::WavesTiles3D *)cocos2d::WavesTiles3D::create((float)arg1, arg2, (unsigned int)arg3, (float)arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.WavesTiles3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_WavesTiles3D_getAmplitude(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::WavesTiles3D *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.WavesTiles3D");

    // float getAmplitude()
    float ret = (float)self->getAmplitude();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_WavesTiles3D_setAmplitude(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::WavesTiles3D *self = nullptr;
    lua_Number arg1 = 0;       /** amplitude */

    olua_to_cppobj(L, 1, (void **)&self, "cc.WavesTiles3D");
    olua_check_number(L, 2, &arg1);

    // void setAmplitude(float amplitude)
    self->setAmplitude((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_WavesTiles3D(lua_State *L)
{
    oluacls_class(L, "cc.WavesTiles3D", "cc.TiledGrid3DAction");
    oluacls_func(L, "__move", _cocos2d_WavesTiles3D___move);
    oluacls_func(L, "create", _cocos2d_WavesTiles3D_create);
    oluacls_func(L, "getAmplitude", _cocos2d_WavesTiles3D_getAmplitude);
    oluacls_func(L, "setAmplitude", _cocos2d_WavesTiles3D_setAmplitude);
    oluacls_prop(L, "amplitude", _cocos2d_WavesTiles3D_getAmplitude, _cocos2d_WavesTiles3D_setAmplitude);

    olua_registerluatype<cocos2d::WavesTiles3D>(L, "cc.WavesTiles3D");

    return 1;
}

static int _cocos2d_JumpTiles3D___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::JumpTiles3D *)olua_toobj(L, 1, "cc.JumpTiles3D");
    olua_push_cppobj(L, self, "cc.JumpTiles3D");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_JumpTiles3D_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    cocos2d::Size arg2;       /** gridSize */
    lua_Unsigned arg3 = 0;       /** numberOfJumps */
    lua_Number arg4 = 0;       /** amplitude */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_Size(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // static cocos2d::JumpTiles3D *create(float duration, const cocos2d::Size &gridSize, unsigned int numberOfJumps, float amplitude)
    cocos2d::JumpTiles3D *ret = (cocos2d::JumpTiles3D *)cocos2d::JumpTiles3D::create((float)arg1, arg2, (unsigned int)arg3, (float)arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.JumpTiles3D");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_JumpTiles3D_getAmplitude(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::JumpTiles3D *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.JumpTiles3D");

    // float getAmplitude()
    float ret = (float)self->getAmplitude();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_JumpTiles3D_setAmplitude(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::JumpTiles3D *self = nullptr;
    lua_Number arg1 = 0;       /** amplitude */

    olua_to_cppobj(L, 1, (void **)&self, "cc.JumpTiles3D");
    olua_check_number(L, 2, &arg1);

    // void setAmplitude(float amplitude)
    self->setAmplitude((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_JumpTiles3D(lua_State *L)
{
    oluacls_class(L, "cc.JumpTiles3D", "cc.TiledGrid3DAction");
    oluacls_func(L, "__move", _cocos2d_JumpTiles3D___move);
    oluacls_func(L, "create", _cocos2d_JumpTiles3D_create);
    oluacls_func(L, "getAmplitude", _cocos2d_JumpTiles3D_getAmplitude);
    oluacls_func(L, "setAmplitude", _cocos2d_JumpTiles3D_setAmplitude);
    oluacls_prop(L, "amplitude", _cocos2d_JumpTiles3D_getAmplitude, _cocos2d_JumpTiles3D_setAmplitude);

    olua_registerluatype<cocos2d::JumpTiles3D>(L, "cc.JumpTiles3D");

    return 1;
}

static int _cocos2d_SplitRows___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::SplitRows *)olua_toobj(L, 1, "cc.SplitRows");
    olua_push_cppobj(L, self, "cc.SplitRows");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_SplitRows_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    lua_Unsigned arg2 = 0;       /** rows */

    olua_check_number(L, 1, &arg1);
    olua_check_uint(L, 2, &arg2);

    // static cocos2d::SplitRows *create(float duration, unsigned int rows)
    cocos2d::SplitRows *ret = (cocos2d::SplitRows *)cocos2d::SplitRows::create((float)arg1, (unsigned int)arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.SplitRows");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_SplitRows(lua_State *L)
{
    oluacls_class(L, "cc.SplitRows", "cc.TiledGrid3DAction");
    oluacls_func(L, "__move", _cocos2d_SplitRows___move);
    oluacls_func(L, "create", _cocos2d_SplitRows_create);

    olua_registerluatype<cocos2d::SplitRows>(L, "cc.SplitRows");

    return 1;
}

static int _cocos2d_SplitCols___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::SplitCols *)olua_toobj(L, 1, "cc.SplitCols");
    olua_push_cppobj(L, self, "cc.SplitCols");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_SplitCols_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** duration */
    lua_Unsigned arg2 = 0;       /** cols */

    olua_check_number(L, 1, &arg1);
    olua_check_uint(L, 2, &arg2);

    // static cocos2d::SplitCols *create(float duration, unsigned int cols)
    cocos2d::SplitCols *ret = (cocos2d::SplitCols *)cocos2d::SplitCols::create((float)arg1, (unsigned int)arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.SplitCols");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_SplitCols(lua_State *L)
{
    oluacls_class(L, "cc.SplitCols", "cc.TiledGrid3DAction");
    oluacls_func(L, "__move", _cocos2d_SplitCols___move);
    oluacls_func(L, "create", _cocos2d_SplitCols_create);

    olua_registerluatype<cocos2d::SplitCols>(L, "cc.SplitCols");

    return 1;
}

int luaopen_cocos2d_action(lua_State *L)
{
    olua_require(L, "cc.Action", luaopen_cocos2d_Action);
    olua_require(L, "cc.FiniteTimeAction", luaopen_cocos2d_FiniteTimeAction);
    olua_require(L, "cc.Speed", luaopen_cocos2d_Speed);
    olua_require(L, "cc.Follow", luaopen_cocos2d_Follow);
    olua_require(L, "cc.tweenfunc", luaopen_cocos2d_tweenfunc);
    olua_require(L, "cc.ActionInterval", luaopen_cocos2d_ActionInterval);
    olua_require(L, "cc.Sequence", luaopen_cocos2d_Sequence);
    olua_require(L, "cc.Repeat", luaopen_cocos2d_Repeat);
    olua_require(L, "cc.RepeatForever", luaopen_cocos2d_RepeatForever);
    olua_require(L, "cc.Spawn", luaopen_cocos2d_Spawn);
    olua_require(L, "cc.RotateTo", luaopen_cocos2d_RotateTo);
    olua_require(L, "cc.RotateBy", luaopen_cocos2d_RotateBy);
    olua_require(L, "cc.MoveBy", luaopen_cocos2d_MoveBy);
    olua_require(L, "cc.MoveTo", luaopen_cocos2d_MoveTo);
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
    olua_require(L, "cc.Blink", luaopen_cocos2d_Blink);
    olua_require(L, "cc.FadeTo", luaopen_cocos2d_FadeTo);
    olua_require(L, "cc.FadeIn", luaopen_cocos2d_FadeIn);
    olua_require(L, "cc.FadeOut", luaopen_cocos2d_FadeOut);
    olua_require(L, "cc.TintTo", luaopen_cocos2d_TintTo);
    olua_require(L, "cc.TintBy", luaopen_cocos2d_TintBy);
    olua_require(L, "cc.DelayTime", luaopen_cocos2d_DelayTime);
    olua_require(L, "cc.ReverseTime", luaopen_cocos2d_ReverseTime);
    olua_require(L, "cc.Animate", luaopen_cocos2d_Animate);
    olua_require(L, "cc.TargetedAction", luaopen_cocos2d_TargetedAction);
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
    return 0;
}
