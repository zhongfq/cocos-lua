//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_cocos2d_physics.h"
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cocos2d.h"

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsMaterial___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_postgc<cocos2d::PhysicsMaterial>(L, 1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsMaterial___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsMaterial *)olua_toobj(L, 1, "cc.PhysicsMaterial");
    olua_push_object(L, self, "cc.PhysicsMaterial");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsMaterial_new$1(lua_State *L)
{
    olua_startinvoke(L);

    // PhysicsMaterial()
    cocos2d::PhysicsMaterial *ret = new cocos2d::PhysicsMaterial();
    int num_ret = olua_push_object(L, ret, "cc.PhysicsMaterial");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsMaterial_new$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** aDensity */
    float arg2 = 0;       /** aRestitution */
    float arg3 = 0;       /** aFriction */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // PhysicsMaterial(float aDensity, float aRestitution, float aFriction)
    cocos2d::PhysicsMaterial *ret = new cocos2d::PhysicsMaterial(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsMaterial");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsMaterial_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // PhysicsMaterial()
        return _cocos2d_PhysicsMaterial_new$1(L);
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // PhysicsMaterial(float aDensity, float aRestitution, float aFriction)
            return _cocos2d_PhysicsMaterial_new$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsMaterial::new' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsMaterial_get_density(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsMaterial *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsMaterial");

    // float density
    float ret = self->density;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsMaterial_set_density(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsMaterial *self = nullptr;
    float arg1 = 0;       /** density */

    olua_to_object(L, 1, &self, "cc.PhysicsMaterial");
    olua_check_number(L, 2, &arg1);

    // float density
    self->density = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsMaterial_get_friction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsMaterial *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsMaterial");

    // float friction
    float ret = self->friction;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsMaterial_set_friction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsMaterial *self = nullptr;
    float arg1 = 0;       /** friction */

    olua_to_object(L, 1, &self, "cc.PhysicsMaterial");
    olua_check_number(L, 2, &arg1);

    // float friction
    self->friction = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsMaterial_get_restitution(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsMaterial *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsMaterial");

    // float restitution
    float ret = self->restitution;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsMaterial_set_restitution(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsMaterial *self = nullptr;
    float arg1 = 0;       /** restitution */

    olua_to_object(L, 1, &self, "cc.PhysicsMaterial");
    olua_check_number(L, 2, &arg1);

    // float restitution
    self->restitution = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsMaterial(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsMaterial>(L, "cc.PhysicsMaterial");
    oluacls_func(L, "__gc", _cocos2d_PhysicsMaterial___gc);
    oluacls_func(L, "__olua_move", _cocos2d_PhysicsMaterial___olua_move);
    oluacls_func(L, "new", _cocos2d_PhysicsMaterial_new);
    oluacls_prop(L, "density", _cocos2d_PhysicsMaterial_get_density, _cocos2d_PhysicsMaterial_set_density);
    oluacls_prop(L, "friction", _cocos2d_PhysicsMaterial_get_friction, _cocos2d_PhysicsMaterial_set_friction);
    oluacls_prop(L, "restitution", _cocos2d_PhysicsMaterial_get_restitution, _cocos2d_PhysicsMaterial_set_restitution);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsRayCastCallbackFunc___call(lua_State *L)
{
    olua_startinvoke(L);

    luaL_checktype(L, -1, LUA_TFUNCTION);
    olua_push_callback(L, (cocos2d::PhysicsRayCastCallbackFunc *)nullptr, "cc.PhysicsRayCastCallbackFunc");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsRayCastCallbackFunc(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsRayCastCallbackFunc>(L, "cc.PhysicsRayCastCallbackFunc");
    oluacls_func(L, "__call", _cocos2d_PhysicsRayCastCallbackFunc___call);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsQueryRectCallbackFunc___call(lua_State *L)
{
    olua_startinvoke(L);

    luaL_checktype(L, -1, LUA_TFUNCTION);
    olua_push_callback(L, (cocos2d::PhysicsQueryRectCallbackFunc *)nullptr, "cc.PhysicsQueryRectCallbackFunc");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsQueryRectCallbackFunc(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsQueryRectCallbackFunc>(L, "cc.PhysicsQueryRectCallbackFunc");
    oluacls_func(L, "__call", _cocos2d_PhysicsQueryRectCallbackFunc___call);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsQueryPointCallbackFunc___call(lua_State *L)
{
    olua_startinvoke(L);

    luaL_checktype(L, -1, LUA_TFUNCTION);
    olua_push_callback(L, (cocos2d::PhysicsQueryPointCallbackFunc *)nullptr, "cc.PhysicsQueryPointCallbackFunc");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsQueryPointCallbackFunc(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsQueryPointCallbackFunc>(L, "cc.PhysicsQueryPointCallbackFunc");
    oluacls_func(L, "__call", _cocos2d_PhysicsQueryPointCallbackFunc___call);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_EventListenerPhysicsContact_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EventListenerPhysicsContact *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EventListenerPhysicsContact");

    // cocos2d::EventListenerPhysicsContact *clone()
    cocos2d::EventListenerPhysicsContact *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EventListenerPhysicsContact");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EventListenerPhysicsContact_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::EventListenerPhysicsContact *create()
    cocos2d::EventListenerPhysicsContact *ret = cocos2d::EventListenerPhysicsContact::create();
    int num_ret = olua_push_object(L, ret, "cc.EventListenerPhysicsContact");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EventListenerPhysicsContact_get_onContactBegin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EventListenerPhysicsContact *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EventListenerPhysicsContact");

    void *cb_store = (void *)self;
    std::string cb_tag = "onContactBegin";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // @nullable @localvar std::function<bool (cocos2d::PhysicsContact &)> onContactBegin
    std::function<bool (cocos2d::PhysicsContact &)> ret = self->onContactBegin;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EventListenerPhysicsContact_set_onContactBegin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EventListenerPhysicsContact *self = nullptr;
    std::function<bool (cocos2d::PhysicsContact &)> arg1;       /** onContactBegin */

    olua_to_object(L, 1, &self, "cc.EventListenerPhysicsContact");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "onContactBegin";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](cocos2d::PhysicsContact &arg1) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();
            bool ret = false;       /** ret */
            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_object(L, &arg1, "cc.PhysicsContact");
                olua_disable_objpool(L);

                olua_callback(L, cb_store, cb_name.c_str(), 1);

                if (olua_is_bool(L, -1)) {
                    olua_check_bool(L, -1, &ret);
                }

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
            return ret;
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);
        arg1 = nullptr;
    }

    // @nullable @localvar std::function<bool (cocos2d::PhysicsContact &)> onContactBegin
    self->onContactBegin = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_EventListenerPhysicsContact_get_onContactPostSolve(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EventListenerPhysicsContact *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EventListenerPhysicsContact");

    void *cb_store = (void *)self;
    std::string cb_tag = "onContactPostSolve";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // @nullable @localvar std::function<void (cocos2d::PhysicsContact &, const cocos2d::PhysicsContactPostSolve &)> onContactPostSolve
    std::function<void (cocos2d::PhysicsContact &, const cocos2d::PhysicsContactPostSolve &)> ret = self->onContactPostSolve;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EventListenerPhysicsContact_set_onContactPostSolve(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EventListenerPhysicsContact *self = nullptr;
    std::function<void (cocos2d::PhysicsContact &, const cocos2d::PhysicsContactPostSolve &)> arg1;       /** onContactPostSolve */

    olua_to_object(L, 1, &self, "cc.EventListenerPhysicsContact");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "onContactPostSolve";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](cocos2d::PhysicsContact &arg1, const cocos2d::PhysicsContactPostSolve &arg2) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_object(L, &arg1, "cc.PhysicsContact");
                olua_push_object(L, arg2, "cc.PhysicsContactPostSolve");
                olua_disable_objpool(L);

                olua_callback(L, cb_store, cb_name.c_str(), 2);

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);
        arg1 = nullptr;
    }

    // @nullable @localvar std::function<void (cocos2d::PhysicsContact &, const cocos2d::PhysicsContactPostSolve &)> onContactPostSolve
    self->onContactPostSolve = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_EventListenerPhysicsContact_get_onContactPreSolve(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EventListenerPhysicsContact *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EventListenerPhysicsContact");

    void *cb_store = (void *)self;
    std::string cb_tag = "onContactPreSolve";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // @nullable @localvar std::function<bool (cocos2d::PhysicsContact &, cocos2d::PhysicsContactPreSolve &)> onContactPreSolve
    std::function<bool (cocos2d::PhysicsContact &, cocos2d::PhysicsContactPreSolve &)> ret = self->onContactPreSolve;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EventListenerPhysicsContact_set_onContactPreSolve(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EventListenerPhysicsContact *self = nullptr;
    std::function<bool (cocos2d::PhysicsContact &, cocos2d::PhysicsContactPreSolve &)> arg1;       /** onContactPreSolve */

    olua_to_object(L, 1, &self, "cc.EventListenerPhysicsContact");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "onContactPreSolve";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](cocos2d::PhysicsContact &arg1, cocos2d::PhysicsContactPreSolve &arg2) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();
            bool ret = false;       /** ret */
            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_object(L, &arg1, "cc.PhysicsContact");
                olua_push_object(L, &arg2, "cc.PhysicsContactPreSolve");
                olua_disable_objpool(L);

                olua_callback(L, cb_store, cb_name.c_str(), 2);

                if (olua_is_bool(L, -1)) {
                    olua_check_bool(L, -1, &ret);
                }

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
            return ret;
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);
        arg1 = nullptr;
    }

    // @nullable @localvar std::function<bool (cocos2d::PhysicsContact &, cocos2d::PhysicsContactPreSolve &)> onContactPreSolve
    self->onContactPreSolve = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_EventListenerPhysicsContact_get_onContactSeparate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EventListenerPhysicsContact *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EventListenerPhysicsContact");

    void *cb_store = (void *)self;
    std::string cb_tag = "onContactSeparate";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // @nullable @localvar std::function<void (cocos2d::PhysicsContact &)> onContactSeparate
    std::function<void (cocos2d::PhysicsContact &)> ret = self->onContactSeparate;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EventListenerPhysicsContact_set_onContactSeparate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EventListenerPhysicsContact *self = nullptr;
    std::function<void (cocos2d::PhysicsContact &)> arg1;       /** onContactSeparate */

    olua_to_object(L, 1, &self, "cc.EventListenerPhysicsContact");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "onContactSeparate";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](cocos2d::PhysicsContact &arg1) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_object(L, &arg1, "cc.PhysicsContact");
                olua_disable_objpool(L);

                olua_callback(L, cb_store, cb_name.c_str(), 1);

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);
        arg1 = nullptr;
    }

    // @nullable @localvar std::function<void (cocos2d::PhysicsContact &)> onContactSeparate
    self->onContactSeparate = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EventListenerPhysicsContact(lua_State *L)
{
    oluacls_class<cocos2d::EventListenerPhysicsContact, cocos2d::EventListenerCustom>(L, "cc.EventListenerPhysicsContact");
    oluacls_func(L, "clone", _cocos2d_EventListenerPhysicsContact_clone);
    oluacls_func(L, "create", _cocos2d_EventListenerPhysicsContact_create);
    oluacls_prop(L, "onContactBegin", _cocos2d_EventListenerPhysicsContact_get_onContactBegin, _cocos2d_EventListenerPhysicsContact_set_onContactBegin);
    oluacls_prop(L, "onContactPostSolve", _cocos2d_EventListenerPhysicsContact_get_onContactPostSolve, _cocos2d_EventListenerPhysicsContact_set_onContactPostSolve);
    oluacls_prop(L, "onContactPreSolve", _cocos2d_EventListenerPhysicsContact_get_onContactPreSolve, _cocos2d_EventListenerPhysicsContact_set_onContactPreSolve);
    oluacls_prop(L, "onContactSeparate", _cocos2d_EventListenerPhysicsContact_get_onContactSeparate, _cocos2d_EventListenerPhysicsContact_set_onContactSeparate);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_EventListenerPhysicsContactWithGroup_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EventListenerPhysicsContactWithGroup *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EventListenerPhysicsContactWithGroup");

    // cocos2d::EventListenerPhysicsContactWithGroup *clone()
    cocos2d::EventListenerPhysicsContactWithGroup *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EventListenerPhysicsContactWithGroup");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EventListenerPhysicsContactWithGroup_create(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** group */

    olua_check_integer(L, 1, &arg1);

    // static cocos2d::EventListenerPhysicsContactWithGroup *create(int group)
    cocos2d::EventListenerPhysicsContactWithGroup *ret = cocos2d::EventListenerPhysicsContactWithGroup::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.EventListenerPhysicsContactWithGroup");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EventListenerPhysicsContactWithGroup_hitTest(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EventListenerPhysicsContactWithGroup *self = nullptr;
    cocos2d::PhysicsShape *arg1 = nullptr;       /** shapeA */
    cocos2d::PhysicsShape *arg2 = nullptr;       /** shapeB */

    olua_to_object(L, 1, &self, "cc.EventListenerPhysicsContactWithGroup");
    olua_check_object(L, 2, &arg1, "cc.PhysicsShape");
    olua_check_object(L, 3, &arg2, "cc.PhysicsShape");

    // bool hitTest(cocos2d::PhysicsShape *shapeA, cocos2d::PhysicsShape *shapeB)
    bool ret = self->hitTest(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EventListenerPhysicsContactWithGroup(lua_State *L)
{
    oluacls_class<cocos2d::EventListenerPhysicsContactWithGroup, cocos2d::EventListenerPhysicsContact>(L, "cc.EventListenerPhysicsContactWithGroup");
    oluacls_func(L, "clone", _cocos2d_EventListenerPhysicsContactWithGroup_clone);
    oluacls_func(L, "create", _cocos2d_EventListenerPhysicsContactWithGroup_create);
    oluacls_func(L, "hitTest", _cocos2d_EventListenerPhysicsContactWithGroup_hitTest);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_EventListenerPhysicsContactWithBodies_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EventListenerPhysicsContactWithBodies *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EventListenerPhysicsContactWithBodies");

    // cocos2d::EventListenerPhysicsContactWithBodies *clone()
    cocos2d::EventListenerPhysicsContactWithBodies *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EventListenerPhysicsContactWithBodies");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EventListenerPhysicsContactWithBodies_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** bodyA */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** bodyB */

    olua_check_object(L, 1, &arg1, "cc.PhysicsBody");
    olua_check_object(L, 2, &arg2, "cc.PhysicsBody");

    // static cocos2d::EventListenerPhysicsContactWithBodies *create(cocos2d::PhysicsBody *bodyA, cocos2d::PhysicsBody *bodyB)
    cocos2d::EventListenerPhysicsContactWithBodies *ret = cocos2d::EventListenerPhysicsContactWithBodies::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.EventListenerPhysicsContactWithBodies");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EventListenerPhysicsContactWithBodies_hitTest(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EventListenerPhysicsContactWithBodies *self = nullptr;
    cocos2d::PhysicsShape *arg1 = nullptr;       /** shapeA */
    cocos2d::PhysicsShape *arg2 = nullptr;       /** shapeB */

    olua_to_object(L, 1, &self, "cc.EventListenerPhysicsContactWithBodies");
    olua_check_object(L, 2, &arg1, "cc.PhysicsShape");
    olua_check_object(L, 3, &arg2, "cc.PhysicsShape");

    // bool hitTest(cocos2d::PhysicsShape *shapeA, cocos2d::PhysicsShape *shapeB)
    bool ret = self->hitTest(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EventListenerPhysicsContactWithBodies(lua_State *L)
{
    oluacls_class<cocos2d::EventListenerPhysicsContactWithBodies, cocos2d::EventListenerPhysicsContact>(L, "cc.EventListenerPhysicsContactWithBodies");
    oluacls_func(L, "clone", _cocos2d_EventListenerPhysicsContactWithBodies_clone);
    oluacls_func(L, "create", _cocos2d_EventListenerPhysicsContactWithBodies_create);
    oluacls_func(L, "hitTest", _cocos2d_EventListenerPhysicsContactWithBodies_hitTest);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_EventListenerPhysicsContactWithShapes_clone(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EventListenerPhysicsContactWithShapes *self = nullptr;

    olua_to_object(L, 1, &self, "cc.EventListenerPhysicsContactWithShapes");

    // cocos2d::EventListenerPhysicsContactWithShapes *clone()
    cocos2d::EventListenerPhysicsContactWithShapes *ret = self->clone();
    int num_ret = olua_push_object(L, ret, "cc.EventListenerPhysicsContactWithShapes");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EventListenerPhysicsContactWithShapes_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *arg1 = nullptr;       /** shapeA */
    cocos2d::PhysicsShape *arg2 = nullptr;       /** shapeB */

    olua_check_object(L, 1, &arg1, "cc.PhysicsShape");
    olua_check_object(L, 2, &arg2, "cc.PhysicsShape");

    // static cocos2d::EventListenerPhysicsContactWithShapes *create(cocos2d::PhysicsShape *shapeA, cocos2d::PhysicsShape *shapeB)
    cocos2d::EventListenerPhysicsContactWithShapes *ret = cocos2d::EventListenerPhysicsContactWithShapes::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.EventListenerPhysicsContactWithShapes");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EventListenerPhysicsContactWithShapes_hitTest(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EventListenerPhysicsContactWithShapes *self = nullptr;
    cocos2d::PhysicsShape *arg1 = nullptr;       /** shapeA */
    cocos2d::PhysicsShape *arg2 = nullptr;       /** shapeB */

    olua_to_object(L, 1, &self, "cc.EventListenerPhysicsContactWithShapes");
    olua_check_object(L, 2, &arg1, "cc.PhysicsShape");
    olua_check_object(L, 3, &arg2, "cc.PhysicsShape");

    // bool hitTest(cocos2d::PhysicsShape *shapeA, cocos2d::PhysicsShape *shapeB)
    bool ret = self->hitTest(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_EventListenerPhysicsContactWithShapes(lua_State *L)
{
    oluacls_class<cocos2d::EventListenerPhysicsContactWithShapes, cocos2d::EventListenerPhysicsContact>(L, "cc.EventListenerPhysicsContactWithShapes");
    oluacls_func(L, "clone", _cocos2d_EventListenerPhysicsContactWithShapes_clone);
    oluacls_func(L, "create", _cocos2d_EventListenerPhysicsContactWithShapes_create);
    oluacls_func(L, "hitTest", _cocos2d_EventListenerPhysicsContactWithShapes_hitTest);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsBody_addMass(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    float arg1 = 0;       /** mass */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_number(L, 2, &arg1);

    // void addMass(float mass)
    self->addMass(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_addMoment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    float arg1 = 0;       /** moment */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_number(L, 2, &arg1);

    // void addMoment(float moment)
    self->addMoment(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_addShape$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    cocos2d::PhysicsShape *arg1 = nullptr;       /** shape */
    bool arg2 = false;       /** addMassAndMoment */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_object(L, 2, &arg1, "cc.PhysicsShape");
    olua_check_bool(L, 3, &arg2);

    // cocos2d::PhysicsShape *addShape(cocos2d::PhysicsShape *shape, @optional bool addMassAndMoment)
    cocos2d::PhysicsShape *ret = self->addShape(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShape");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_addShape$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    cocos2d::PhysicsShape *arg1 = nullptr;       /** shape */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_object(L, 2, &arg1, "cc.PhysicsShape");

    // cocos2d::PhysicsShape *addShape(cocos2d::PhysicsShape *shape, @optional bool addMassAndMoment)
    cocos2d::PhysicsShape *ret = self->addShape(arg1);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShape");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_addShape(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_object(L, 2, "cc.PhysicsShape"))) {
            // cocos2d::PhysicsShape *addShape(cocos2d::PhysicsShape *shape, @optional bool addMassAndMoment)
            return _cocos2d_PhysicsBody_addShape$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 2, "cc.PhysicsShape")) && (olua_is_bool(L, 3))) {
            // cocos2d::PhysicsShape *addShape(cocos2d::PhysicsShape *shape, @optional bool addMassAndMoment)
            return _cocos2d_PhysicsBody_addShape$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsBody::addShape' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsBody_applyForce$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    cocos2d::Vec2 arg1;       /** force */
    cocos2d::Vec2 arg2;       /** offset */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_object(L, 2, &arg1, "cc.Vec2");
    olua_check_object(L, 3, &arg2, "cc.Vec2");

    // void applyForce(const cocos2d::Vec2 &force, @optional const cocos2d::Vec2 &offset)
    self->applyForce(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_applyForce$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    cocos2d::Vec2 arg1;       /** force */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void applyForce(const cocos2d::Vec2 &force, @optional const cocos2d::Vec2 &offset)
    self->applyForce(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_applyForce(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_object(L, 2, "cc.Vec2"))) {
            // void applyForce(const cocos2d::Vec2 &force, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_applyForce$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 2, "cc.Vec2")) && (olua_is_object(L, 3, "cc.Vec2"))) {
            // void applyForce(const cocos2d::Vec2 &force, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_applyForce$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsBody::applyForce' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsBody_applyImpulse$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    cocos2d::Vec2 arg1;       /** impulse */
    cocos2d::Vec2 arg2;       /** offset */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_object(L, 2, &arg1, "cc.Vec2");
    olua_check_object(L, 3, &arg2, "cc.Vec2");

    // void applyImpulse(const cocos2d::Vec2 &impulse, @optional const cocos2d::Vec2 &offset)
    self->applyImpulse(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_applyImpulse$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    cocos2d::Vec2 arg1;       /** impulse */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void applyImpulse(const cocos2d::Vec2 &impulse, @optional const cocos2d::Vec2 &offset)
    self->applyImpulse(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_applyImpulse(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_object(L, 2, "cc.Vec2"))) {
            // void applyImpulse(const cocos2d::Vec2 &impulse, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_applyImpulse$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 2, "cc.Vec2")) && (olua_is_object(L, 3, "cc.Vec2"))) {
            // void applyImpulse(const cocos2d::Vec2 &impulse, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_applyImpulse$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsBody::applyImpulse' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsBody_applyTorque(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    float arg1 = 0;       /** torque */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_number(L, 2, &arg1);

    // void applyTorque(float torque)
    self->applyTorque(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_create$1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::PhysicsBody *create()
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::create();
    int num_ret = olua_push_object(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_create$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** mass */

    olua_check_number(L, 1, &arg1);

    // static cocos2d::PhysicsBody *create(float mass)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_create$3(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** mass */
    float arg2 = 0;       /** moment */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static cocos2d::PhysicsBody *create(float mass, float moment)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::PhysicsBody *create()
        return _cocos2d_PhysicsBody_create$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_number(L, 1))) {
            // static cocos2d::PhysicsBody *create(float mass)
            return _cocos2d_PhysicsBody_create$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2))) {
            // static cocos2d::PhysicsBody *create(float mass, float moment)
            return _cocos2d_PhysicsBody_create$3(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsBody::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsBody_createBox$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    cocos2d::PhysicsMaterial arg2;       /** material */
    cocos2d::Vec2 arg3;       /** offset */

    olua_check_object(L, 1, &arg1, "cc.Size");
    olua_check_object(L, 2, &arg2, "cc.PhysicsMaterial");
    olua_check_object(L, 3, &arg3, "cc.Vec2");

    // static cocos2d::PhysicsBody *createBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createBox(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createBox$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */

    olua_check_object(L, 1, &arg1, "cc.Size");

    // static cocos2d::PhysicsBody *createBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createBox(arg1);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createBox$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    cocos2d::PhysicsMaterial arg2;       /** material */

    olua_check_object(L, 1, &arg1, "cc.Size");
    olua_check_object(L, 2, &arg2, "cc.PhysicsMaterial");

    // static cocos2d::PhysicsBody *createBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createBox(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createBox(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_object(L, 1, "cc.Size"))) {
            // static cocos2d::PhysicsBody *createBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_createBox$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Size")) && (olua_is_object(L, 2, "cc.PhysicsMaterial"))) {
            // static cocos2d::PhysicsBody *createBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_createBox$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Size")) && (olua_is_object(L, 2, "cc.PhysicsMaterial")) && (olua_is_object(L, 3, "cc.Vec2"))) {
            // static cocos2d::PhysicsBody *createBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_createBox$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsBody::createBox' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsBody_createCircle$1(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** radius */
    cocos2d::PhysicsMaterial arg2;       /** material */
    cocos2d::Vec2 arg3;       /** offset */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.PhysicsMaterial");
    olua_check_object(L, 3, &arg3, "cc.Vec2");

    // static cocos2d::PhysicsBody *createCircle(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createCircle(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createCircle$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** radius */

    olua_check_number(L, 1, &arg1);

    // static cocos2d::PhysicsBody *createCircle(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createCircle(arg1);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createCircle$3(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** radius */
    cocos2d::PhysicsMaterial arg2;       /** material */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.PhysicsMaterial");

    // static cocos2d::PhysicsBody *createCircle(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createCircle(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createCircle(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_number(L, 1))) {
            // static cocos2d::PhysicsBody *createCircle(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_createCircle$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_number(L, 1)) && (olua_is_object(L, 2, "cc.PhysicsMaterial"))) {
            // static cocos2d::PhysicsBody *createCircle(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_createCircle$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (olua_is_object(L, 2, "cc.PhysicsMaterial")) && (olua_is_object(L, 3, "cc.Vec2"))) {
            // static cocos2d::PhysicsBody *createCircle(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_createCircle$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsBody::createCircle' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsBody_createEdgeBox$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    cocos2d::PhysicsMaterial arg2;       /** material */
    float arg3 = 0;       /** border */
    cocos2d::Vec2 arg4;       /** offset */

    olua_check_object(L, 1, &arg1, "cc.Size");
    olua_check_object(L, 2, &arg2, "cc.PhysicsMaterial");
    olua_check_number(L, 3, &arg3);
    olua_check_object(L, 4, &arg4, "cc.Vec2");

    // static cocos2d::PhysicsBody *createEdgeBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createEdgeBox(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createEdgeBox$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */

    olua_check_object(L, 1, &arg1, "cc.Size");

    // static cocos2d::PhysicsBody *createEdgeBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createEdgeBox(arg1);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createEdgeBox$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    cocos2d::PhysicsMaterial arg2;       /** material */

    olua_check_object(L, 1, &arg1, "cc.Size");
    olua_check_object(L, 2, &arg2, "cc.PhysicsMaterial");

    // static cocos2d::PhysicsBody *createEdgeBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createEdgeBox(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createEdgeBox$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    cocos2d::PhysicsMaterial arg2;       /** material */
    float arg3 = 0;       /** border */

    olua_check_object(L, 1, &arg1, "cc.Size");
    olua_check_object(L, 2, &arg2, "cc.PhysicsMaterial");
    olua_check_number(L, 3, &arg3);

    // static cocos2d::PhysicsBody *createEdgeBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createEdgeBox(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createEdgeBox(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_object(L, 1, "cc.Size"))) {
            // static cocos2d::PhysicsBody *createEdgeBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_createEdgeBox$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Size")) && (olua_is_object(L, 2, "cc.PhysicsMaterial"))) {
            // static cocos2d::PhysicsBody *createEdgeBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_createEdgeBox$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Size")) && (olua_is_object(L, 2, "cc.PhysicsMaterial")) && (olua_is_number(L, 3))) {
            // static cocos2d::PhysicsBody *createEdgeBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_createEdgeBox$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.Size")) && (olua_is_object(L, 2, "cc.PhysicsMaterial")) && (olua_is_number(L, 3)) && (olua_is_object(L, 4, "cc.Vec2"))) {
            // static cocos2d::PhysicsBody *createEdgeBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_createEdgeBox$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsBody::createEdgeBox' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsBody_createEdgeChain$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1 = nullptr;       /** points */
    int arg2 = 0;       /** count */
    cocos2d::PhysicsMaterial arg3;       /** material */
    float arg4 = 0;       /** border */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_integer(L, 2, &arg2);
    olua_check_object(L, 3, &arg3, "cc.PhysicsMaterial");
    olua_check_number(L, 4, &arg4);

    // static cocos2d::PhysicsBody *createEdgeChain(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createEdgeChain(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createEdgeChain$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1 = nullptr;       /** points */
    int arg2 = 0;       /** count */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_integer(L, 2, &arg2);

    // static cocos2d::PhysicsBody *createEdgeChain(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createEdgeChain(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createEdgeChain$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1 = nullptr;       /** points */
    int arg2 = 0;       /** count */
    cocos2d::PhysicsMaterial arg3;       /** material */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_integer(L, 2, &arg2);
    olua_check_object(L, 3, &arg3, "cc.PhysicsMaterial");

    // static cocos2d::PhysicsBody *createEdgeChain(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createEdgeChain(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createEdgeChain(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_integer(L, 2))) {
            // static cocos2d::PhysicsBody *createEdgeChain(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
            return _cocos2d_PhysicsBody_createEdgeChain$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_integer(L, 2)) && (olua_is_object(L, 3, "cc.PhysicsMaterial"))) {
            // static cocos2d::PhysicsBody *createEdgeChain(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
            return _cocos2d_PhysicsBody_createEdgeChain$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_integer(L, 2)) && (olua_is_object(L, 3, "cc.PhysicsMaterial")) && (olua_is_number(L, 4))) {
            // static cocos2d::PhysicsBody *createEdgeChain(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
            return _cocos2d_PhysicsBody_createEdgeChain$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsBody::createEdgeChain' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsBody_createEdgePolygon$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1 = nullptr;       /** points */
    int arg2 = 0;       /** count */
    cocos2d::PhysicsMaterial arg3;       /** material */
    float arg4 = 0;       /** border */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_integer(L, 2, &arg2);
    olua_check_object(L, 3, &arg3, "cc.PhysicsMaterial");
    olua_check_number(L, 4, &arg4);

    // static cocos2d::PhysicsBody *createEdgePolygon(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createEdgePolygon(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createEdgePolygon$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1 = nullptr;       /** points */
    int arg2 = 0;       /** count */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_integer(L, 2, &arg2);

    // static cocos2d::PhysicsBody *createEdgePolygon(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createEdgePolygon(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createEdgePolygon$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1 = nullptr;       /** points */
    int arg2 = 0;       /** count */
    cocos2d::PhysicsMaterial arg3;       /** material */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_integer(L, 2, &arg2);
    olua_check_object(L, 3, &arg3, "cc.PhysicsMaterial");

    // static cocos2d::PhysicsBody *createEdgePolygon(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createEdgePolygon(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createEdgePolygon(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_integer(L, 2))) {
            // static cocos2d::PhysicsBody *createEdgePolygon(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
            return _cocos2d_PhysicsBody_createEdgePolygon$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_integer(L, 2)) && (olua_is_object(L, 3, "cc.PhysicsMaterial"))) {
            // static cocos2d::PhysicsBody *createEdgePolygon(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
            return _cocos2d_PhysicsBody_createEdgePolygon$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_integer(L, 2)) && (olua_is_object(L, 3, "cc.PhysicsMaterial")) && (olua_is_number(L, 4))) {
            // static cocos2d::PhysicsBody *createEdgePolygon(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
            return _cocos2d_PhysicsBody_createEdgePolygon$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsBody::createEdgePolygon' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsBody_createEdgeSegment$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 arg1;       /** a */
    cocos2d::Vec2 arg2;       /** b */
    cocos2d::PhysicsMaterial arg3;       /** material */
    float arg4 = 0;       /** border */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_object(L, 2, &arg2, "cc.Vec2");
    olua_check_object(L, 3, &arg3, "cc.PhysicsMaterial");
    olua_check_number(L, 4, &arg4);

    // static cocos2d::PhysicsBody *createEdgeSegment(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createEdgeSegment(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createEdgeSegment$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 arg1;       /** a */
    cocos2d::Vec2 arg2;       /** b */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_object(L, 2, &arg2, "cc.Vec2");

    // static cocos2d::PhysicsBody *createEdgeSegment(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createEdgeSegment(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createEdgeSegment$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 arg1;       /** a */
    cocos2d::Vec2 arg2;       /** b */
    cocos2d::PhysicsMaterial arg3;       /** material */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_object(L, 2, &arg2, "cc.Vec2");
    olua_check_object(L, 3, &arg3, "cc.PhysicsMaterial");

    // static cocos2d::PhysicsBody *createEdgeSegment(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createEdgeSegment(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createEdgeSegment(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_object(L, 2, "cc.Vec2"))) {
            // static cocos2d::PhysicsBody *createEdgeSegment(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
            return _cocos2d_PhysicsBody_createEdgeSegment$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_object(L, 2, "cc.Vec2")) && (olua_is_object(L, 3, "cc.PhysicsMaterial"))) {
            // static cocos2d::PhysicsBody *createEdgeSegment(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
            return _cocos2d_PhysicsBody_createEdgeSegment$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_object(L, 2, "cc.Vec2")) && (olua_is_object(L, 3, "cc.PhysicsMaterial")) && (olua_is_number(L, 4))) {
            // static cocos2d::PhysicsBody *createEdgeSegment(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
            return _cocos2d_PhysicsBody_createEdgeSegment$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsBody::createEdgeSegment' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsBody_createPolygon$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1 = nullptr;       /** points */
    int arg2 = 0;       /** count */
    cocos2d::PhysicsMaterial arg3;       /** material */
    cocos2d::Vec2 arg4;       /** offset */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_integer(L, 2, &arg2);
    olua_check_object(L, 3, &arg3, "cc.PhysicsMaterial");
    olua_check_object(L, 4, &arg4, "cc.Vec2");

    // static cocos2d::PhysicsBody *createPolygon(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createPolygon(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createPolygon$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1 = nullptr;       /** points */
    int arg2 = 0;       /** count */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_integer(L, 2, &arg2);

    // static cocos2d::PhysicsBody *createPolygon(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createPolygon(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createPolygon$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1 = nullptr;       /** points */
    int arg2 = 0;       /** count */
    cocos2d::PhysicsMaterial arg3;       /** material */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_integer(L, 2, &arg2);
    olua_check_object(L, 3, &arg3, "cc.PhysicsMaterial");

    // static cocos2d::PhysicsBody *createPolygon(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createPolygon(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createPolygon(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_integer(L, 2))) {
            // static cocos2d::PhysicsBody *createPolygon(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_createPolygon$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_integer(L, 2)) && (olua_is_object(L, 3, "cc.PhysicsMaterial"))) {
            // static cocos2d::PhysicsBody *createPolygon(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_createPolygon$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_integer(L, 2)) && (olua_is_object(L, 3, "cc.PhysicsMaterial")) && (olua_is_object(L, 4, "cc.Vec2"))) {
            // static cocos2d::PhysicsBody *createPolygon(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_createPolygon$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsBody::createPolygon' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsBody_getAngularDamping(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsBody");

    // float getAngularDamping()
    float ret = self->getAngularDamping();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getAngularVelocity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsBody");

    // float getAngularVelocity()
    float ret = self->getAngularVelocity();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getAngularVelocityLimit(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsBody");

    // float getAngularVelocityLimit()
    float ret = self->getAngularVelocityLimit();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getCategoryBitmask(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsBody");

    // int getCategoryBitmask()
    int ret = self->getCategoryBitmask();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getCollisionBitmask(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsBody");

    // int getCollisionBitmask()
    int ret = self->getCollisionBitmask();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getContactTestBitmask(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsBody");

    // int getContactTestBitmask()
    int ret = self->getContactTestBitmask();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getFirstShape(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsBody");

    // cocos2d::PhysicsShape *getFirstShape()
    cocos2d::PhysicsShape *ret = self->getFirstShape();
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShape");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getGroup(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsBody");

    // int getGroup()
    int ret = self->getGroup();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getJoints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsBody");

    // const std::vector<cocos2d::PhysicsJoint *> &getJoints()
    const std::vector<cocos2d::PhysicsJoint *> &ret = self->getJoints();
    int num_ret = olua_push_vector<cocos2d::PhysicsJoint *>(L, ret, [L](cocos2d::PhysicsJoint *arg1) {
        olua_push_object(L, arg1, "cc.PhysicsJoint");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getLinearDamping(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsBody");

    // float getLinearDamping()
    float ret = self->getLinearDamping();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getMass(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsBody");

    // float getMass()
    float ret = self->getMass();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getMoment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsBody");

    // float getMoment()
    float ret = self->getMoment();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getNode(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsBody");

    // cocos2d::Node *getNode()
    cocos2d::Node *ret = self->getNode();
    int num_ret = olua_push_object(L, ret, "cc.Node");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsBody");

    // cocos2d::Vec2 getPosition()
    cocos2d::Vec2 ret = self->getPosition();
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getPositionOffset(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsBody");

    // const cocos2d::Vec2 &getPositionOffset()
    const cocos2d::Vec2 &ret = self->getPositionOffset();
    int num_ret = olua_push_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getRotation(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsBody");

    // float getRotation()
    float ret = self->getRotation();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getRotationOffset(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsBody");

    // float getRotationOffset()
    float ret = self->getRotationOffset();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getShape(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    int arg1 = 0;       /** tag */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_integer(L, 2, &arg1);

    // cocos2d::PhysicsShape *getShape(int tag)
    cocos2d::PhysicsShape *ret = self->getShape(arg1);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShape");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getShapes(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsBody");

    // const cocos2d::Vector<cocos2d::PhysicsShape *> &getShapes()
    const cocos2d::Vector<cocos2d::PhysicsShape *> &ret = self->getShapes();
    int num_ret = olua_push_vector<cocos2d::PhysicsShape *>(L, ret, [L](cocos2d::PhysicsShape *arg1) {
        olua_push_object(L, arg1, "cc.PhysicsShape");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getTag(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsBody");

    // int getTag()
    int ret = self->getTag();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getVelocity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsBody");

    // cocos2d::Vec2 getVelocity()
    cocos2d::Vec2 ret = self->getVelocity();
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getVelocityAtLocalPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    cocos2d::Vec2 arg1;       /** point */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // cocos2d::Vec2 getVelocityAtLocalPoint(const cocos2d::Vec2 &point)
    cocos2d::Vec2 ret = self->getVelocityAtLocalPoint(arg1);
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getVelocityAtWorldPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    cocos2d::Vec2 arg1;       /** point */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // cocos2d::Vec2 getVelocityAtWorldPoint(const cocos2d::Vec2 &point)
    cocos2d::Vec2 ret = self->getVelocityAtWorldPoint(arg1);
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getVelocityLimit(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsBody");

    // float getVelocityLimit()
    float ret = self->getVelocityLimit();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getWorld(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsBody");

    // cocos2d::PhysicsWorld *getWorld()
    cocos2d::PhysicsWorld *ret = self->getWorld();
    int num_ret = olua_push_object(L, ret, "cc.PhysicsWorld");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_isDynamic(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsBody");

    // bool isDynamic()
    bool ret = self->isDynamic();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_isGravityEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsBody");

    // bool isGravityEnabled()
    bool ret = self->isGravityEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_isResting(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsBody");

    // bool isResting()
    bool ret = self->isResting();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_isRotationEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsBody");

    // bool isRotationEnabled()
    bool ret = self->isRotationEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_local2World(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    cocos2d::Vec2 arg1;       /** point */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // cocos2d::Vec2 local2World(const cocos2d::Vec2 &point)
    cocos2d::Vec2 ret = self->local2World(arg1);
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_removeAllShapes$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    bool arg1 = false;       /** reduceMassAndMoment */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_bool(L, 2, &arg1);

    // void removeAllShapes(@optional bool reduceMassAndMoment)
    self->removeAllShapes(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_removeAllShapes$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsBody");

    // void removeAllShapes(@optional bool reduceMassAndMoment)
    self->removeAllShapes();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_removeAllShapes(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void removeAllShapes(@optional bool reduceMassAndMoment)
        return _cocos2d_PhysicsBody_removeAllShapes$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_bool(L, 2))) {
            // void removeAllShapes(@optional bool reduceMassAndMoment)
            return _cocos2d_PhysicsBody_removeAllShapes$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsBody::removeAllShapes' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsBody_removeFromWorld(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsBody");

    // void removeFromWorld()
    self->removeFromWorld();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_removeShape$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    cocos2d::PhysicsShape *arg1 = nullptr;       /** shape */
    bool arg2 = false;       /** reduceMassAndMoment */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_object(L, 2, &arg1, "cc.PhysicsShape");
    olua_check_bool(L, 3, &arg2);

    // void removeShape(cocos2d::PhysicsShape *shape, @optional bool reduceMassAndMoment)
    self->removeShape(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_removeShape$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    int arg1 = 0;       /** tag */
    bool arg2 = false;       /** reduceMassAndMoment */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_integer(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void removeShape(int tag, @optional bool reduceMassAndMoment)
    self->removeShape(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_removeShape$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    cocos2d::PhysicsShape *arg1 = nullptr;       /** shape */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_object(L, 2, &arg1, "cc.PhysicsShape");

    // void removeShape(cocos2d::PhysicsShape *shape, @optional bool reduceMassAndMoment)
    self->removeShape(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_removeShape$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    int arg1 = 0;       /** tag */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_integer(L, 2, &arg1);

    // void removeShape(int tag, @optional bool reduceMassAndMoment)
    self->removeShape(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_removeShape(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        if ((olua_is_object(L, 2, "cc.PhysicsShape"))) {
            // void removeShape(cocos2d::PhysicsShape *shape, @optional bool reduceMassAndMoment)
            return _cocos2d_PhysicsBody_removeShape$3(L);
        }

        // if ((olua_is_integer(L, 2))) {
            // void removeShape(int tag, @optional bool reduceMassAndMoment)
            return _cocos2d_PhysicsBody_removeShape$4(L);
        // }
    }

    if (num_args == 2) {
        if ((olua_is_object(L, 2, "cc.PhysicsShape")) && (olua_is_bool(L, 3))) {
            // void removeShape(cocos2d::PhysicsShape *shape, @optional bool reduceMassAndMoment)
            return _cocos2d_PhysicsBody_removeShape$1(L);
        }

        // if ((olua_is_integer(L, 2)) && (olua_is_bool(L, 3))) {
            // void removeShape(int tag, @optional bool reduceMassAndMoment)
            return _cocos2d_PhysicsBody_removeShape$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsBody::removeShape' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsBody_resetForces(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsBody");

    // void resetForces()
    self->resetForces();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setAngularDamping(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    float arg1 = 0;       /** damping */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_number(L, 2, &arg1);

    // void setAngularDamping(float damping)
    self->setAngularDamping(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setAngularVelocity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    float arg1 = 0;       /** velocity */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_number(L, 2, &arg1);

    // void setAngularVelocity(float velocity)
    self->setAngularVelocity(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setAngularVelocityLimit(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    float arg1 = 0;       /** limit */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_number(L, 2, &arg1);

    // void setAngularVelocityLimit(float limit)
    self->setAngularVelocityLimit(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setCategoryBitmask(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    int arg1 = 0;       /** bitmask */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_integer(L, 2, &arg1);

    // void setCategoryBitmask(int bitmask)
    self->setCategoryBitmask(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setCollisionBitmask(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    int arg1 = 0;       /** bitmask */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_integer(L, 2, &arg1);

    // void setCollisionBitmask(int bitmask)
    self->setCollisionBitmask(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setContactTestBitmask(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    int arg1 = 0;       /** bitmask */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_integer(L, 2, &arg1);

    // void setContactTestBitmask(int bitmask)
    self->setContactTestBitmask(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setDynamic(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    bool arg1 = false;       /** dynamic */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_bool(L, 2, &arg1);

    // void setDynamic(bool dynamic)
    self->setDynamic(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setGravityEnable(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_bool(L, 2, &arg1);

    // void setGravityEnable(bool enable)
    self->setGravityEnable(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setGroup(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    int arg1 = 0;       /** group */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_integer(L, 2, &arg1);

    // void setGroup(int group)
    self->setGroup(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setLinearDamping(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    float arg1 = 0;       /** damping */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_number(L, 2, &arg1);

    // void setLinearDamping(float damping)
    self->setLinearDamping(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setMass(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    float arg1 = 0;       /** mass */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_number(L, 2, &arg1);

    // void setMass(float mass)
    self->setMass(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setMoment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    float arg1 = 0;       /** moment */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_number(L, 2, &arg1);

    // void setMoment(float moment)
    self->setMoment(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setPositionOffset(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    cocos2d::Vec2 arg1;       /** position */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void setPositionOffset(const cocos2d::Vec2 &position)
    self->setPositionOffset(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setResting(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    bool arg1 = false;       /** rest */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_bool(L, 2, &arg1);

    // void setResting(bool rest)
    self->setResting(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setRotationEnable(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_bool(L, 2, &arg1);

    // void setRotationEnable(bool enable)
    self->setRotationEnable(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setRotationOffset(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    float arg1 = 0;       /** rotation */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_number(L, 2, &arg1);

    // void setRotationOffset(float rotation)
    self->setRotationOffset(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setTag(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    int arg1 = 0;       /** tag */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_integer(L, 2, &arg1);

    // void setTag(int tag)
    self->setTag(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setVelocity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    cocos2d::Vec2 arg1;       /** velocity */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void setVelocity(const cocos2d::Vec2 &velocity)
    self->setVelocity(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setVelocityLimit(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    float arg1 = 0;       /** limit */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_number(L, 2, &arg1);

    // void setVelocityLimit(float limit)
    self->setVelocityLimit(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_world2Local(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    cocos2d::Vec2 arg1;       /** point */

    olua_to_object(L, 1, &self, "cc.PhysicsBody");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // cocos2d::Vec2 world2Local(const cocos2d::Vec2 &point)
    cocos2d::Vec2 ret = self->world2Local(arg1);
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsBody(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsBody, cocos2d::Component>(L, "cc.PhysicsBody");
    oluacls_func(L, "addMass", _cocos2d_PhysicsBody_addMass);
    oluacls_func(L, "addMoment", _cocos2d_PhysicsBody_addMoment);
    oluacls_func(L, "addShape", _cocos2d_PhysicsBody_addShape);
    oluacls_func(L, "applyForce", _cocos2d_PhysicsBody_applyForce);
    oluacls_func(L, "applyImpulse", _cocos2d_PhysicsBody_applyImpulse);
    oluacls_func(L, "applyTorque", _cocos2d_PhysicsBody_applyTorque);
    oluacls_func(L, "create", _cocos2d_PhysicsBody_create);
    oluacls_func(L, "createBox", _cocos2d_PhysicsBody_createBox);
    oluacls_func(L, "createCircle", _cocos2d_PhysicsBody_createCircle);
    oluacls_func(L, "createEdgeBox", _cocos2d_PhysicsBody_createEdgeBox);
    oluacls_func(L, "createEdgeChain", _cocos2d_PhysicsBody_createEdgeChain);
    oluacls_func(L, "createEdgePolygon", _cocos2d_PhysicsBody_createEdgePolygon);
    oluacls_func(L, "createEdgeSegment", _cocos2d_PhysicsBody_createEdgeSegment);
    oluacls_func(L, "createPolygon", _cocos2d_PhysicsBody_createPolygon);
    oluacls_func(L, "getAngularDamping", _cocos2d_PhysicsBody_getAngularDamping);
    oluacls_func(L, "getAngularVelocity", _cocos2d_PhysicsBody_getAngularVelocity);
    oluacls_func(L, "getAngularVelocityLimit", _cocos2d_PhysicsBody_getAngularVelocityLimit);
    oluacls_func(L, "getCategoryBitmask", _cocos2d_PhysicsBody_getCategoryBitmask);
    oluacls_func(L, "getCollisionBitmask", _cocos2d_PhysicsBody_getCollisionBitmask);
    oluacls_func(L, "getContactTestBitmask", _cocos2d_PhysicsBody_getContactTestBitmask);
    oluacls_func(L, "getFirstShape", _cocos2d_PhysicsBody_getFirstShape);
    oluacls_func(L, "getGroup", _cocos2d_PhysicsBody_getGroup);
    oluacls_func(L, "getJoints", _cocos2d_PhysicsBody_getJoints);
    oluacls_func(L, "getLinearDamping", _cocos2d_PhysicsBody_getLinearDamping);
    oluacls_func(L, "getMass", _cocos2d_PhysicsBody_getMass);
    oluacls_func(L, "getMoment", _cocos2d_PhysicsBody_getMoment);
    oluacls_func(L, "getNode", _cocos2d_PhysicsBody_getNode);
    oluacls_func(L, "getPosition", _cocos2d_PhysicsBody_getPosition);
    oluacls_func(L, "getPositionOffset", _cocos2d_PhysicsBody_getPositionOffset);
    oluacls_func(L, "getRotation", _cocos2d_PhysicsBody_getRotation);
    oluacls_func(L, "getRotationOffset", _cocos2d_PhysicsBody_getRotationOffset);
    oluacls_func(L, "getShape", _cocos2d_PhysicsBody_getShape);
    oluacls_func(L, "getShapes", _cocos2d_PhysicsBody_getShapes);
    oluacls_func(L, "getTag", _cocos2d_PhysicsBody_getTag);
    oluacls_func(L, "getVelocity", _cocos2d_PhysicsBody_getVelocity);
    oluacls_func(L, "getVelocityAtLocalPoint", _cocos2d_PhysicsBody_getVelocityAtLocalPoint);
    oluacls_func(L, "getVelocityAtWorldPoint", _cocos2d_PhysicsBody_getVelocityAtWorldPoint);
    oluacls_func(L, "getVelocityLimit", _cocos2d_PhysicsBody_getVelocityLimit);
    oluacls_func(L, "getWorld", _cocos2d_PhysicsBody_getWorld);
    oluacls_func(L, "isDynamic", _cocos2d_PhysicsBody_isDynamic);
    oluacls_func(L, "isGravityEnabled", _cocos2d_PhysicsBody_isGravityEnabled);
    oluacls_func(L, "isResting", _cocos2d_PhysicsBody_isResting);
    oluacls_func(L, "isRotationEnabled", _cocos2d_PhysicsBody_isRotationEnabled);
    oluacls_func(L, "local2World", _cocos2d_PhysicsBody_local2World);
    oluacls_func(L, "removeAllShapes", _cocos2d_PhysicsBody_removeAllShapes);
    oluacls_func(L, "removeFromWorld", _cocos2d_PhysicsBody_removeFromWorld);
    oluacls_func(L, "removeShape", _cocos2d_PhysicsBody_removeShape);
    oluacls_func(L, "resetForces", _cocos2d_PhysicsBody_resetForces);
    oluacls_func(L, "setAngularDamping", _cocos2d_PhysicsBody_setAngularDamping);
    oluacls_func(L, "setAngularVelocity", _cocos2d_PhysicsBody_setAngularVelocity);
    oluacls_func(L, "setAngularVelocityLimit", _cocos2d_PhysicsBody_setAngularVelocityLimit);
    oluacls_func(L, "setCategoryBitmask", _cocos2d_PhysicsBody_setCategoryBitmask);
    oluacls_func(L, "setCollisionBitmask", _cocos2d_PhysicsBody_setCollisionBitmask);
    oluacls_func(L, "setContactTestBitmask", _cocos2d_PhysicsBody_setContactTestBitmask);
    oluacls_func(L, "setDynamic", _cocos2d_PhysicsBody_setDynamic);
    oluacls_func(L, "setGravityEnable", _cocos2d_PhysicsBody_setGravityEnable);
    oluacls_func(L, "setGroup", _cocos2d_PhysicsBody_setGroup);
    oluacls_func(L, "setLinearDamping", _cocos2d_PhysicsBody_setLinearDamping);
    oluacls_func(L, "setMass", _cocos2d_PhysicsBody_setMass);
    oluacls_func(L, "setMoment", _cocos2d_PhysicsBody_setMoment);
    oluacls_func(L, "setPositionOffset", _cocos2d_PhysicsBody_setPositionOffset);
    oluacls_func(L, "setResting", _cocos2d_PhysicsBody_setResting);
    oluacls_func(L, "setRotationEnable", _cocos2d_PhysicsBody_setRotationEnable);
    oluacls_func(L, "setRotationOffset", _cocos2d_PhysicsBody_setRotationOffset);
    oluacls_func(L, "setTag", _cocos2d_PhysicsBody_setTag);
    oluacls_func(L, "setVelocity", _cocos2d_PhysicsBody_setVelocity);
    oluacls_func(L, "setVelocityLimit", _cocos2d_PhysicsBody_setVelocityLimit);
    oluacls_func(L, "world2Local", _cocos2d_PhysicsBody_world2Local);
    oluacls_prop(L, "angularDamping", _cocos2d_PhysicsBody_getAngularDamping, _cocos2d_PhysicsBody_setAngularDamping);
    oluacls_prop(L, "angularVelocity", _cocos2d_PhysicsBody_getAngularVelocity, _cocos2d_PhysicsBody_setAngularVelocity);
    oluacls_prop(L, "angularVelocityLimit", _cocos2d_PhysicsBody_getAngularVelocityLimit, _cocos2d_PhysicsBody_setAngularVelocityLimit);
    oluacls_prop(L, "categoryBitmask", _cocos2d_PhysicsBody_getCategoryBitmask, _cocos2d_PhysicsBody_setCategoryBitmask);
    oluacls_prop(L, "collisionBitmask", _cocos2d_PhysicsBody_getCollisionBitmask, _cocos2d_PhysicsBody_setCollisionBitmask);
    oluacls_prop(L, "contactTestBitmask", _cocos2d_PhysicsBody_getContactTestBitmask, _cocos2d_PhysicsBody_setContactTestBitmask);
    oluacls_prop(L, "dynamic", _cocos2d_PhysicsBody_isDynamic, _cocos2d_PhysicsBody_setDynamic);
    oluacls_prop(L, "firstShape", _cocos2d_PhysicsBody_getFirstShape, nullptr);
    oluacls_prop(L, "gravityEnabled", _cocos2d_PhysicsBody_isGravityEnabled, nullptr);
    oluacls_prop(L, "group", _cocos2d_PhysicsBody_getGroup, _cocos2d_PhysicsBody_setGroup);
    oluacls_prop(L, "joints", _cocos2d_PhysicsBody_getJoints, nullptr);
    oluacls_prop(L, "linearDamping", _cocos2d_PhysicsBody_getLinearDamping, _cocos2d_PhysicsBody_setLinearDamping);
    oluacls_prop(L, "mass", _cocos2d_PhysicsBody_getMass, _cocos2d_PhysicsBody_setMass);
    oluacls_prop(L, "moment", _cocos2d_PhysicsBody_getMoment, _cocos2d_PhysicsBody_setMoment);
    oluacls_prop(L, "node", _cocos2d_PhysicsBody_getNode, nullptr);
    oluacls_prop(L, "position", _cocos2d_PhysicsBody_getPosition, nullptr);
    oluacls_prop(L, "positionOffset", _cocos2d_PhysicsBody_getPositionOffset, _cocos2d_PhysicsBody_setPositionOffset);
    oluacls_prop(L, "resting", _cocos2d_PhysicsBody_isResting, _cocos2d_PhysicsBody_setResting);
    oluacls_prop(L, "rotation", _cocos2d_PhysicsBody_getRotation, nullptr);
    oluacls_prop(L, "rotationEnabled", _cocos2d_PhysicsBody_isRotationEnabled, nullptr);
    oluacls_prop(L, "rotationOffset", _cocos2d_PhysicsBody_getRotationOffset, _cocos2d_PhysicsBody_setRotationOffset);
    oluacls_prop(L, "shapes", _cocos2d_PhysicsBody_getShapes, nullptr);
    oluacls_prop(L, "tag", _cocos2d_PhysicsBody_getTag, _cocos2d_PhysicsBody_setTag);
    oluacls_prop(L, "velocity", _cocos2d_PhysicsBody_getVelocity, _cocos2d_PhysicsBody_setVelocity);
    oluacls_prop(L, "velocityLimit", _cocos2d_PhysicsBody_getVelocityLimit, _cocos2d_PhysicsBody_setVelocityLimit);
    oluacls_prop(L, "world", _cocos2d_PhysicsBody_getWorld, nullptr);
    oluacls_const(L, "COMPONENT_NAME", cocos2d::PhysicsBody::COMPONENT_NAME);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsContact_EventCode(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsContact::EventCode>(L, "cc.PhysicsContact.EventCode");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "BEGIN", (lua_Integer)cocos2d::PhysicsContact::EventCode::BEGIN);
    oluacls_enum(L, "NONE", (lua_Integer)cocos2d::PhysicsContact::EventCode::NONE);
    oluacls_enum(L, "POSTSOLVE", (lua_Integer)cocos2d::PhysicsContact::EventCode::POSTSOLVE);
    oluacls_enum(L, "PRESOLVE", (lua_Integer)cocos2d::PhysicsContact::EventCode::PRESOLVE);
    oluacls_enum(L, "SEPARATE", (lua_Integer)cocos2d::PhysicsContact::EventCode::SEPARATE);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsContact_getData(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContact *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsContact");

    // void *getData()
    void *ret = self->getData();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsContact_getEventCode(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContact *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsContact");

    // cocos2d::PhysicsContact::EventCode getEventCode()
    cocos2d::PhysicsContact::EventCode ret = self->getEventCode();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsContact_getShapeA(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContact *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsContact");

    // cocos2d::PhysicsShape *getShapeA()
    cocos2d::PhysicsShape *ret = self->getShapeA();
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShape");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsContact_getShapeB(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContact *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsContact");

    // cocos2d::PhysicsShape *getShapeB()
    cocos2d::PhysicsShape *ret = self->getShapeB();
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShape");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsContact_setData(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContact *self = nullptr;
    void *arg1 = nullptr;       /** data */

    olua_to_object(L, 1, &self, "cc.PhysicsContact");
    olua_check_object(L, 2, &arg1, "void *");

    // void setData(void *data)
    self->setData(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsContact(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsContact, cocos2d::EventCustom>(L, "cc.PhysicsContact");
    oluacls_func(L, "getData", _cocos2d_PhysicsContact_getData);
    oluacls_func(L, "getEventCode", _cocos2d_PhysicsContact_getEventCode);
    oluacls_func(L, "getShapeA", _cocos2d_PhysicsContact_getShapeA);
    oluacls_func(L, "getShapeB", _cocos2d_PhysicsContact_getShapeB);
    oluacls_func(L, "setData", _cocos2d_PhysicsContact_setData);
    oluacls_prop(L, "data", _cocos2d_PhysicsContact_getData, _cocos2d_PhysicsContact_setData);
    oluacls_prop(L, "eventCode", _cocos2d_PhysicsContact_getEventCode, nullptr);
    oluacls_prop(L, "shapeA", _cocos2d_PhysicsContact_getShapeA, nullptr);
    oluacls_prop(L, "shapeB", _cocos2d_PhysicsContact_getShapeB, nullptr);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsContactPostSolve___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsContactPostSolve *)olua_toobj(L, 1, "cc.PhysicsContactPostSolve");
    olua_push_object(L, self, "cc.PhysicsContactPostSolve");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsContactPostSolve_getFriction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContactPostSolve *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsContactPostSolve");

    // float getFriction()
    float ret = self->getFriction();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsContactPostSolve_getRestitution(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContactPostSolve *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsContactPostSolve");

    // float getRestitution()
    float ret = self->getRestitution();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsContactPostSolve_getSurfaceVelocity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContactPostSolve *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsContactPostSolve");

    // cocos2d::Vec2 getSurfaceVelocity()
    cocos2d::Vec2 ret = self->getSurfaceVelocity();
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsContactPostSolve(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsContactPostSolve>(L, "cc.PhysicsContactPostSolve");
    oluacls_func(L, "__olua_move", _cocos2d_PhysicsContactPostSolve___olua_move);
    oluacls_func(L, "getFriction", _cocos2d_PhysicsContactPostSolve_getFriction);
    oluacls_func(L, "getRestitution", _cocos2d_PhysicsContactPostSolve_getRestitution);
    oluacls_func(L, "getSurfaceVelocity", _cocos2d_PhysicsContactPostSolve_getSurfaceVelocity);
    oluacls_prop(L, "friction", _cocos2d_PhysicsContactPostSolve_getFriction, nullptr);
    oluacls_prop(L, "restitution", _cocos2d_PhysicsContactPostSolve_getRestitution, nullptr);
    oluacls_prop(L, "surfaceVelocity", _cocos2d_PhysicsContactPostSolve_getSurfaceVelocity, nullptr);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsContactPreSolve___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsContactPreSolve *)olua_toobj(L, 1, "cc.PhysicsContactPreSolve");
    olua_push_object(L, self, "cc.PhysicsContactPreSolve");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsContactPreSolve_getFriction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContactPreSolve *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsContactPreSolve");

    // float getFriction()
    float ret = self->getFriction();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsContactPreSolve_getRestitution(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContactPreSolve *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsContactPreSolve");

    // float getRestitution()
    float ret = self->getRestitution();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsContactPreSolve_getSurfaceVelocity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContactPreSolve *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsContactPreSolve");

    // cocos2d::Vec2 getSurfaceVelocity()
    cocos2d::Vec2 ret = self->getSurfaceVelocity();
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsContactPreSolve_ignore(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContactPreSolve *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsContactPreSolve");

    // void ignore()
    self->ignore();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsContactPreSolve_setFriction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContactPreSolve *self = nullptr;
    float arg1 = 0;       /** friction */

    olua_to_object(L, 1, &self, "cc.PhysicsContactPreSolve");
    olua_check_number(L, 2, &arg1);

    // void setFriction(float friction)
    self->setFriction(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsContactPreSolve_setRestitution(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContactPreSolve *self = nullptr;
    float arg1 = 0;       /** restitution */

    olua_to_object(L, 1, &self, "cc.PhysicsContactPreSolve");
    olua_check_number(L, 2, &arg1);

    // void setRestitution(float restitution)
    self->setRestitution(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsContactPreSolve_setSurfaceVelocity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContactPreSolve *self = nullptr;
    cocos2d::Vec2 arg1;       /** velocity */

    olua_to_object(L, 1, &self, "cc.PhysicsContactPreSolve");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void setSurfaceVelocity(const cocos2d::Vec2 &velocity)
    self->setSurfaceVelocity(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsContactPreSolve(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsContactPreSolve>(L, "cc.PhysicsContactPreSolve");
    oluacls_func(L, "__olua_move", _cocos2d_PhysicsContactPreSolve___olua_move);
    oluacls_func(L, "getFriction", _cocos2d_PhysicsContactPreSolve_getFriction);
    oluacls_func(L, "getRestitution", _cocos2d_PhysicsContactPreSolve_getRestitution);
    oluacls_func(L, "getSurfaceVelocity", _cocos2d_PhysicsContactPreSolve_getSurfaceVelocity);
    oluacls_func(L, "ignore", _cocos2d_PhysicsContactPreSolve_ignore);
    oluacls_func(L, "setFriction", _cocos2d_PhysicsContactPreSolve_setFriction);
    oluacls_func(L, "setRestitution", _cocos2d_PhysicsContactPreSolve_setRestitution);
    oluacls_func(L, "setSurfaceVelocity", _cocos2d_PhysicsContactPreSolve_setSurfaceVelocity);
    oluacls_prop(L, "friction", _cocos2d_PhysicsContactPreSolve_getFriction, _cocos2d_PhysicsContactPreSolve_setFriction);
    oluacls_prop(L, "restitution", _cocos2d_PhysicsContactPreSolve_getRestitution, _cocos2d_PhysicsContactPreSolve_setRestitution);
    oluacls_prop(L, "surfaceVelocity", _cocos2d_PhysicsContactPreSolve_getSurfaceVelocity, _cocos2d_PhysicsContactPreSolve_setSurfaceVelocity);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsJoint___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsJoint *)olua_toobj(L, 1, "cc.PhysicsJoint");
    olua_push_object(L, self, "cc.PhysicsJoint");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsJoint_getBodyA(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJoint *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJoint");

    // cocos2d::PhysicsBody *getBodyA()
    cocos2d::PhysicsBody *ret = self->getBodyA();
    int num_ret = olua_push_object(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJoint_getBodyB(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJoint *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJoint");

    // cocos2d::PhysicsBody *getBodyB()
    cocos2d::PhysicsBody *ret = self->getBodyB();
    int num_ret = olua_push_object(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJoint_getMaxForce(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJoint *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJoint");

    // float getMaxForce()
    float ret = self->getMaxForce();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJoint_getTag(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJoint *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJoint");

    // int getTag()
    int ret = self->getTag();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJoint_getWorld(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJoint *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJoint");

    // cocos2d::PhysicsWorld *getWorld()
    cocos2d::PhysicsWorld *ret = self->getWorld();
    int num_ret = olua_push_object(L, ret, "cc.PhysicsWorld");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJoint_isCollisionEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJoint *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJoint");

    // bool isCollisionEnabled()
    bool ret = self->isCollisionEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJoint_isEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJoint *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJoint");

    // bool isEnabled()
    bool ret = self->isEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJoint_removeFormWorld(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJoint *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJoint");

    // void removeFormWorld()
    self->removeFormWorld();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJoint_setCollisionEnable(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJoint *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_object(L, 1, &self, "cc.PhysicsJoint");
    olua_check_bool(L, 2, &arg1);

    // void setCollisionEnable(bool enable)
    self->setCollisionEnable(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJoint_setEnable(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJoint *self = nullptr;
    bool arg1 = false;       /** enable */

    olua_to_object(L, 1, &self, "cc.PhysicsJoint");
    olua_check_bool(L, 2, &arg1);

    // void setEnable(bool enable)
    self->setEnable(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJoint_setMaxForce(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJoint *self = nullptr;
    float arg1 = 0;       /** force */

    olua_to_object(L, 1, &self, "cc.PhysicsJoint");
    olua_check_number(L, 2, &arg1);

    // void setMaxForce(float force)
    self->setMaxForce(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJoint_setTag(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJoint *self = nullptr;
    int arg1 = 0;       /** tag */

    olua_to_object(L, 1, &self, "cc.PhysicsJoint");
    olua_check_integer(L, 2, &arg1);

    // void setTag(int tag)
    self->setTag(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsJoint(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsJoint>(L, "cc.PhysicsJoint");
    oluacls_func(L, "__olua_move", _cocos2d_PhysicsJoint___olua_move);
    oluacls_func(L, "getBodyA", _cocos2d_PhysicsJoint_getBodyA);
    oluacls_func(L, "getBodyB", _cocos2d_PhysicsJoint_getBodyB);
    oluacls_func(L, "getMaxForce", _cocos2d_PhysicsJoint_getMaxForce);
    oluacls_func(L, "getTag", _cocos2d_PhysicsJoint_getTag);
    oluacls_func(L, "getWorld", _cocos2d_PhysicsJoint_getWorld);
    oluacls_func(L, "isCollisionEnabled", _cocos2d_PhysicsJoint_isCollisionEnabled);
    oluacls_func(L, "isEnabled", _cocos2d_PhysicsJoint_isEnabled);
    oluacls_func(L, "removeFormWorld", _cocos2d_PhysicsJoint_removeFormWorld);
    oluacls_func(L, "setCollisionEnable", _cocos2d_PhysicsJoint_setCollisionEnable);
    oluacls_func(L, "setEnable", _cocos2d_PhysicsJoint_setEnable);
    oluacls_func(L, "setMaxForce", _cocos2d_PhysicsJoint_setMaxForce);
    oluacls_func(L, "setTag", _cocos2d_PhysicsJoint_setTag);
    oluacls_prop(L, "bodyA", _cocos2d_PhysicsJoint_getBodyA, nullptr);
    oluacls_prop(L, "bodyB", _cocos2d_PhysicsJoint_getBodyB, nullptr);
    oluacls_prop(L, "collisionEnabled", _cocos2d_PhysicsJoint_isCollisionEnabled, nullptr);
    oluacls_prop(L, "enabled", _cocos2d_PhysicsJoint_isEnabled, nullptr);
    oluacls_prop(L, "maxForce", _cocos2d_PhysicsJoint_getMaxForce, _cocos2d_PhysicsJoint_setMaxForce);
    oluacls_prop(L, "tag", _cocos2d_PhysicsJoint_getTag, _cocos2d_PhysicsJoint_setTag);
    oluacls_prop(L, "world", _cocos2d_PhysicsJoint_getWorld, nullptr);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsJointDistance_construct(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** a */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** b */
    cocos2d::Vec2 arg3;       /** anchr1 */
    cocos2d::Vec2 arg4;       /** anchr2 */

    olua_check_object(L, 1, &arg1, "cc.PhysicsBody");
    olua_check_object(L, 2, &arg2, "cc.PhysicsBody");
    olua_check_object(L, 3, &arg3, "cc.Vec2");
    olua_check_object(L, 4, &arg4, "cc.Vec2");

    // static cocos2d::PhysicsJointDistance *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2)
    cocos2d::PhysicsJointDistance *ret = cocos2d::PhysicsJointDistance::construct(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsJointDistance");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointDistance_createConstraints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointDistance *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointDistance");

    // bool createConstraints()
    bool ret = self->createConstraints();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointDistance_getDistance(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointDistance *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointDistance");

    // float getDistance()
    float ret = self->getDistance();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointDistance_setDistance(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointDistance *self = nullptr;
    float arg1 = 0;       /** distance */

    olua_to_object(L, 1, &self, "cc.PhysicsJointDistance");
    olua_check_number(L, 2, &arg1);

    // void setDistance(float distance)
    self->setDistance(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsJointDistance(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsJointDistance, cocos2d::PhysicsJoint>(L, "cc.PhysicsJointDistance");
    oluacls_func(L, "construct", _cocos2d_PhysicsJointDistance_construct);
    oluacls_func(L, "createConstraints", _cocos2d_PhysicsJointDistance_createConstraints);
    oluacls_func(L, "getDistance", _cocos2d_PhysicsJointDistance_getDistance);
    oluacls_func(L, "setDistance", _cocos2d_PhysicsJointDistance_setDistance);
    oluacls_prop(L, "distance", _cocos2d_PhysicsJointDistance_getDistance, _cocos2d_PhysicsJointDistance_setDistance);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsJointFixed_construct(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** a */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** b */
    cocos2d::Vec2 arg3;       /** anchr */

    olua_check_object(L, 1, &arg1, "cc.PhysicsBody");
    olua_check_object(L, 2, &arg2, "cc.PhysicsBody");
    olua_check_object(L, 3, &arg3, "cc.Vec2");

    // static cocos2d::PhysicsJointFixed *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr)
    cocos2d::PhysicsJointFixed *ret = cocos2d::PhysicsJointFixed::construct(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsJointFixed");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointFixed_createConstraints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointFixed *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointFixed");

    // bool createConstraints()
    bool ret = self->createConstraints();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsJointFixed(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsJointFixed, cocos2d::PhysicsJoint>(L, "cc.PhysicsJointFixed");
    oluacls_func(L, "construct", _cocos2d_PhysicsJointFixed_construct);
    oluacls_func(L, "createConstraints", _cocos2d_PhysicsJointFixed_createConstraints);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsJointGear_construct(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** a */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** b */
    float arg3 = 0;       /** phase */
    float arg4 = 0;       /** ratio */

    olua_check_object(L, 1, &arg1, "cc.PhysicsBody");
    olua_check_object(L, 2, &arg2, "cc.PhysicsBody");
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // static cocos2d::PhysicsJointGear *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, float phase, float ratio)
    cocos2d::PhysicsJointGear *ret = cocos2d::PhysicsJointGear::construct(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsJointGear");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointGear_createConstraints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointGear *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointGear");

    // bool createConstraints()
    bool ret = self->createConstraints();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointGear_getPhase(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointGear *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointGear");

    // float getPhase()
    float ret = self->getPhase();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointGear_getRatio(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointGear *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointGear");

    // float getRatio()
    float ret = self->getRatio();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointGear_setPhase(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointGear *self = nullptr;
    float arg1 = 0;       /** phase */

    olua_to_object(L, 1, &self, "cc.PhysicsJointGear");
    olua_check_number(L, 2, &arg1);

    // void setPhase(float phase)
    self->setPhase(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJointGear_setRatio(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointGear *self = nullptr;
    float arg1 = 0;       /** ratchet */

    olua_to_object(L, 1, &self, "cc.PhysicsJointGear");
    olua_check_number(L, 2, &arg1);

    // void setRatio(float ratchet)
    self->setRatio(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsJointGear(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsJointGear, cocos2d::PhysicsJoint>(L, "cc.PhysicsJointGear");
    oluacls_func(L, "construct", _cocos2d_PhysicsJointGear_construct);
    oluacls_func(L, "createConstraints", _cocos2d_PhysicsJointGear_createConstraints);
    oluacls_func(L, "getPhase", _cocos2d_PhysicsJointGear_getPhase);
    oluacls_func(L, "getRatio", _cocos2d_PhysicsJointGear_getRatio);
    oluacls_func(L, "setPhase", _cocos2d_PhysicsJointGear_setPhase);
    oluacls_func(L, "setRatio", _cocos2d_PhysicsJointGear_setRatio);
    oluacls_prop(L, "phase", _cocos2d_PhysicsJointGear_getPhase, _cocos2d_PhysicsJointGear_setPhase);
    oluacls_prop(L, "ratio", _cocos2d_PhysicsJointGear_getRatio, _cocos2d_PhysicsJointGear_setRatio);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsJointGroove_construct(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** a */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** b */
    cocos2d::Vec2 arg3;       /** grooveA */
    cocos2d::Vec2 arg4;       /** grooveB */
    cocos2d::Vec2 arg5;       /** anchr2 */

    olua_check_object(L, 1, &arg1, "cc.PhysicsBody");
    olua_check_object(L, 2, &arg2, "cc.PhysicsBody");
    olua_check_object(L, 3, &arg3, "cc.Vec2");
    olua_check_object(L, 4, &arg4, "cc.Vec2");
    olua_check_object(L, 5, &arg5, "cc.Vec2");

    // static cocos2d::PhysicsJointGroove *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &grooveA, const cocos2d::Vec2 &grooveB, const cocos2d::Vec2 &anchr2)
    cocos2d::PhysicsJointGroove *ret = cocos2d::PhysicsJointGroove::construct(arg1, arg2, arg3, arg4, arg5);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsJointGroove");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointGroove_createConstraints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointGroove *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointGroove");

    // bool createConstraints()
    bool ret = self->createConstraints();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointGroove_getAnchr2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointGroove *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointGroove");

    // cocos2d::Vec2 getAnchr2()
    cocos2d::Vec2 ret = self->getAnchr2();
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointGroove_getGrooveA(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointGroove *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointGroove");

    // cocos2d::Vec2 getGrooveA()
    cocos2d::Vec2 ret = self->getGrooveA();
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointGroove_getGrooveB(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointGroove *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointGroove");

    // cocos2d::Vec2 getGrooveB()
    cocos2d::Vec2 ret = self->getGrooveB();
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointGroove_setAnchr2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointGroove *self = nullptr;
    cocos2d::Vec2 arg1;       /** anchr2 */

    olua_to_object(L, 1, &self, "cc.PhysicsJointGroove");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void setAnchr2(const cocos2d::Vec2 &anchr2)
    self->setAnchr2(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJointGroove_setGrooveA(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointGroove *self = nullptr;
    cocos2d::Vec2 arg1;       /** grooveA */

    olua_to_object(L, 1, &self, "cc.PhysicsJointGroove");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void setGrooveA(const cocos2d::Vec2 &grooveA)
    self->setGrooveA(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJointGroove_setGrooveB(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointGroove *self = nullptr;
    cocos2d::Vec2 arg1;       /** grooveB */

    olua_to_object(L, 1, &self, "cc.PhysicsJointGroove");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void setGrooveB(const cocos2d::Vec2 &grooveB)
    self->setGrooveB(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsJointGroove(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsJointGroove, cocos2d::PhysicsJoint>(L, "cc.PhysicsJointGroove");
    oluacls_func(L, "construct", _cocos2d_PhysicsJointGroove_construct);
    oluacls_func(L, "createConstraints", _cocos2d_PhysicsJointGroove_createConstraints);
    oluacls_func(L, "getAnchr2", _cocos2d_PhysicsJointGroove_getAnchr2);
    oluacls_func(L, "getGrooveA", _cocos2d_PhysicsJointGroove_getGrooveA);
    oluacls_func(L, "getGrooveB", _cocos2d_PhysicsJointGroove_getGrooveB);
    oluacls_func(L, "setAnchr2", _cocos2d_PhysicsJointGroove_setAnchr2);
    oluacls_func(L, "setGrooveA", _cocos2d_PhysicsJointGroove_setGrooveA);
    oluacls_func(L, "setGrooveB", _cocos2d_PhysicsJointGroove_setGrooveB);
    oluacls_prop(L, "anchr2", _cocos2d_PhysicsJointGroove_getAnchr2, _cocos2d_PhysicsJointGroove_setAnchr2);
    oluacls_prop(L, "grooveA", _cocos2d_PhysicsJointGroove_getGrooveA, _cocos2d_PhysicsJointGroove_setGrooveA);
    oluacls_prop(L, "grooveB", _cocos2d_PhysicsJointGroove_getGrooveB, _cocos2d_PhysicsJointGroove_setGrooveB);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsJointLimit_construct$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** a */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** b */
    cocos2d::Vec2 arg3;       /** anchr1 */
    cocos2d::Vec2 arg4;       /** anchr2 */

    olua_check_object(L, 1, &arg1, "cc.PhysicsBody");
    olua_check_object(L, 2, &arg2, "cc.PhysicsBody");
    olua_check_object(L, 3, &arg3, "cc.Vec2");
    olua_check_object(L, 4, &arg4, "cc.Vec2");

    // static cocos2d::PhysicsJointLimit *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2)
    cocos2d::PhysicsJointLimit *ret = cocos2d::PhysicsJointLimit::construct(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsJointLimit");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointLimit_construct$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** a */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** b */
    cocos2d::Vec2 arg3;       /** anchr1 */
    cocos2d::Vec2 arg4;       /** anchr2 */
    float arg5 = 0;       /** min */
    float arg6 = 0;       /** max */

    olua_check_object(L, 1, &arg1, "cc.PhysicsBody");
    olua_check_object(L, 2, &arg2, "cc.PhysicsBody");
    olua_check_object(L, 3, &arg3, "cc.Vec2");
    olua_check_object(L, 4, &arg4, "cc.Vec2");
    olua_check_number(L, 5, &arg5);
    olua_check_number(L, 6, &arg6);

    // static cocos2d::PhysicsJointLimit *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2, float min, float max)
    cocos2d::PhysicsJointLimit *ret = cocos2d::PhysicsJointLimit::construct(arg1, arg2, arg3, arg4, arg5, arg6);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsJointLimit");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointLimit_construct(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.PhysicsBody")) && (olua_is_object(L, 2, "cc.PhysicsBody")) && (olua_is_object(L, 3, "cc.Vec2")) && (olua_is_object(L, 4, "cc.Vec2"))) {
            // static cocos2d::PhysicsJointLimit *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2)
            return _cocos2d_PhysicsJointLimit_construct$1(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_object(L, 1, "cc.PhysicsBody")) && (olua_is_object(L, 2, "cc.PhysicsBody")) && (olua_is_object(L, 3, "cc.Vec2")) && (olua_is_object(L, 4, "cc.Vec2")) && (olua_is_number(L, 5)) && (olua_is_number(L, 6))) {
            // static cocos2d::PhysicsJointLimit *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2, float min, float max)
            return _cocos2d_PhysicsJointLimit_construct$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsJointLimit::construct' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsJointLimit_createConstraints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointLimit *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointLimit");

    // bool createConstraints()
    bool ret = self->createConstraints();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointLimit_getAnchr1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointLimit *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointLimit");

    // cocos2d::Vec2 getAnchr1()
    cocos2d::Vec2 ret = self->getAnchr1();
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointLimit_getAnchr2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointLimit *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointLimit");

    // cocos2d::Vec2 getAnchr2()
    cocos2d::Vec2 ret = self->getAnchr2();
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointLimit_getMax(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointLimit *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointLimit");

    // float getMax()
    float ret = self->getMax();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointLimit_getMin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointLimit *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointLimit");

    // float getMin()
    float ret = self->getMin();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointLimit_setAnchr1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointLimit *self = nullptr;
    cocos2d::Vec2 arg1;       /** anchr1 */

    olua_to_object(L, 1, &self, "cc.PhysicsJointLimit");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void setAnchr1(const cocos2d::Vec2 &anchr1)
    self->setAnchr1(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJointLimit_setAnchr2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointLimit *self = nullptr;
    cocos2d::Vec2 arg1;       /** anchr2 */

    olua_to_object(L, 1, &self, "cc.PhysicsJointLimit");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void setAnchr2(const cocos2d::Vec2 &anchr2)
    self->setAnchr2(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJointLimit_setMax(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointLimit *self = nullptr;
    float arg1 = 0;       /** max */

    olua_to_object(L, 1, &self, "cc.PhysicsJointLimit");
    olua_check_number(L, 2, &arg1);

    // void setMax(float max)
    self->setMax(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJointLimit_setMin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointLimit *self = nullptr;
    float arg1 = 0;       /** min */

    olua_to_object(L, 1, &self, "cc.PhysicsJointLimit");
    olua_check_number(L, 2, &arg1);

    // void setMin(float min)
    self->setMin(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsJointLimit(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsJointLimit, cocos2d::PhysicsJoint>(L, "cc.PhysicsJointLimit");
    oluacls_func(L, "construct", _cocos2d_PhysicsJointLimit_construct);
    oluacls_func(L, "createConstraints", _cocos2d_PhysicsJointLimit_createConstraints);
    oluacls_func(L, "getAnchr1", _cocos2d_PhysicsJointLimit_getAnchr1);
    oluacls_func(L, "getAnchr2", _cocos2d_PhysicsJointLimit_getAnchr2);
    oluacls_func(L, "getMax", _cocos2d_PhysicsJointLimit_getMax);
    oluacls_func(L, "getMin", _cocos2d_PhysicsJointLimit_getMin);
    oluacls_func(L, "setAnchr1", _cocos2d_PhysicsJointLimit_setAnchr1);
    oluacls_func(L, "setAnchr2", _cocos2d_PhysicsJointLimit_setAnchr2);
    oluacls_func(L, "setMax", _cocos2d_PhysicsJointLimit_setMax);
    oluacls_func(L, "setMin", _cocos2d_PhysicsJointLimit_setMin);
    oluacls_prop(L, "anchr1", _cocos2d_PhysicsJointLimit_getAnchr1, _cocos2d_PhysicsJointLimit_setAnchr1);
    oluacls_prop(L, "anchr2", _cocos2d_PhysicsJointLimit_getAnchr2, _cocos2d_PhysicsJointLimit_setAnchr2);
    oluacls_prop(L, "max", _cocos2d_PhysicsJointLimit_getMax, _cocos2d_PhysicsJointLimit_setMax);
    oluacls_prop(L, "min", _cocos2d_PhysicsJointLimit_getMin, _cocos2d_PhysicsJointLimit_setMin);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsJointMotor_construct(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** a */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** b */
    float arg3 = 0;       /** rate */

    olua_check_object(L, 1, &arg1, "cc.PhysicsBody");
    olua_check_object(L, 2, &arg2, "cc.PhysicsBody");
    olua_check_number(L, 3, &arg3);

    // static cocos2d::PhysicsJointMotor *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, float rate)
    cocos2d::PhysicsJointMotor *ret = cocos2d::PhysicsJointMotor::construct(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsJointMotor");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointMotor_createConstraints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointMotor *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointMotor");

    // bool createConstraints()
    bool ret = self->createConstraints();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointMotor_getRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointMotor *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointMotor");

    // float getRate()
    float ret = self->getRate();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointMotor_setRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointMotor *self = nullptr;
    float arg1 = 0;       /** rate */

    olua_to_object(L, 1, &self, "cc.PhysicsJointMotor");
    olua_check_number(L, 2, &arg1);

    // void setRate(float rate)
    self->setRate(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsJointMotor(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsJointMotor, cocos2d::PhysicsJoint>(L, "cc.PhysicsJointMotor");
    oluacls_func(L, "construct", _cocos2d_PhysicsJointMotor_construct);
    oluacls_func(L, "createConstraints", _cocos2d_PhysicsJointMotor_createConstraints);
    oluacls_func(L, "getRate", _cocos2d_PhysicsJointMotor_getRate);
    oluacls_func(L, "setRate", _cocos2d_PhysicsJointMotor_setRate);
    oluacls_prop(L, "rate", _cocos2d_PhysicsJointMotor_getRate, _cocos2d_PhysicsJointMotor_setRate);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsJointPin_construct$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** a */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** b */
    cocos2d::Vec2 arg3;       /** pivot */

    olua_check_object(L, 1, &arg1, "cc.PhysicsBody");
    olua_check_object(L, 2, &arg2, "cc.PhysicsBody");
    olua_check_object(L, 3, &arg3, "cc.Vec2");

    // static cocos2d::PhysicsJointPin *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &pivot)
    cocos2d::PhysicsJointPin *ret = cocos2d::PhysicsJointPin::construct(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsJointPin");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointPin_construct$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** a */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** b */
    cocos2d::Vec2 arg3;       /** anchr1 */
    cocos2d::Vec2 arg4;       /** anchr2 */

    olua_check_object(L, 1, &arg1, "cc.PhysicsBody");
    olua_check_object(L, 2, &arg2, "cc.PhysicsBody");
    olua_check_object(L, 3, &arg3, "cc.Vec2");
    olua_check_object(L, 4, &arg4, "cc.Vec2");

    // static cocos2d::PhysicsJointPin *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2)
    cocos2d::PhysicsJointPin *ret = cocos2d::PhysicsJointPin::construct(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsJointPin");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointPin_construct(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.PhysicsBody")) && (olua_is_object(L, 2, "cc.PhysicsBody")) && (olua_is_object(L, 3, "cc.Vec2"))) {
            // static cocos2d::PhysicsJointPin *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &pivot)
            return _cocos2d_PhysicsJointPin_construct$1(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.PhysicsBody")) && (olua_is_object(L, 2, "cc.PhysicsBody")) && (olua_is_object(L, 3, "cc.Vec2")) && (olua_is_object(L, 4, "cc.Vec2"))) {
            // static cocos2d::PhysicsJointPin *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2)
            return _cocos2d_PhysicsJointPin_construct$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsJointPin::construct' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsJointPin_createConstraints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointPin *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointPin");

    // bool createConstraints()
    bool ret = self->createConstraints();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsJointPin(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsJointPin, cocos2d::PhysicsJoint>(L, "cc.PhysicsJointPin");
    oluacls_func(L, "construct", _cocos2d_PhysicsJointPin_construct);
    oluacls_func(L, "createConstraints", _cocos2d_PhysicsJointPin_createConstraints);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsJointRatchet_construct(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** a */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** b */
    float arg3 = 0;       /** phase */
    float arg4 = 0;       /** ratchet */

    olua_check_object(L, 1, &arg1, "cc.PhysicsBody");
    olua_check_object(L, 2, &arg2, "cc.PhysicsBody");
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // static cocos2d::PhysicsJointRatchet *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, float phase, float ratchet)
    cocos2d::PhysicsJointRatchet *ret = cocos2d::PhysicsJointRatchet::construct(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsJointRatchet");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointRatchet_createConstraints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRatchet *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointRatchet");

    // bool createConstraints()
    bool ret = self->createConstraints();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointRatchet_getAngle(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRatchet *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointRatchet");

    // float getAngle()
    float ret = self->getAngle();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointRatchet_getPhase(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRatchet *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointRatchet");

    // float getPhase()
    float ret = self->getPhase();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointRatchet_getRatchet(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRatchet *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointRatchet");

    // float getRatchet()
    float ret = self->getRatchet();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointRatchet_setAngle(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRatchet *self = nullptr;
    float arg1 = 0;       /** angle */

    olua_to_object(L, 1, &self, "cc.PhysicsJointRatchet");
    olua_check_number(L, 2, &arg1);

    // void setAngle(float angle)
    self->setAngle(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJointRatchet_setPhase(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRatchet *self = nullptr;
    float arg1 = 0;       /** phase */

    olua_to_object(L, 1, &self, "cc.PhysicsJointRatchet");
    olua_check_number(L, 2, &arg1);

    // void setPhase(float phase)
    self->setPhase(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJointRatchet_setRatchet(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRatchet *self = nullptr;
    float arg1 = 0;       /** ratchet */

    olua_to_object(L, 1, &self, "cc.PhysicsJointRatchet");
    olua_check_number(L, 2, &arg1);

    // void setRatchet(float ratchet)
    self->setRatchet(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsJointRatchet(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsJointRatchet, cocos2d::PhysicsJoint>(L, "cc.PhysicsJointRatchet");
    oluacls_func(L, "construct", _cocos2d_PhysicsJointRatchet_construct);
    oluacls_func(L, "createConstraints", _cocos2d_PhysicsJointRatchet_createConstraints);
    oluacls_func(L, "getAngle", _cocos2d_PhysicsJointRatchet_getAngle);
    oluacls_func(L, "getPhase", _cocos2d_PhysicsJointRatchet_getPhase);
    oluacls_func(L, "getRatchet", _cocos2d_PhysicsJointRatchet_getRatchet);
    oluacls_func(L, "setAngle", _cocos2d_PhysicsJointRatchet_setAngle);
    oluacls_func(L, "setPhase", _cocos2d_PhysicsJointRatchet_setPhase);
    oluacls_func(L, "setRatchet", _cocos2d_PhysicsJointRatchet_setRatchet);
    oluacls_prop(L, "angle", _cocos2d_PhysicsJointRatchet_getAngle, _cocos2d_PhysicsJointRatchet_setAngle);
    oluacls_prop(L, "phase", _cocos2d_PhysicsJointRatchet_getPhase, _cocos2d_PhysicsJointRatchet_setPhase);
    oluacls_prop(L, "ratchet", _cocos2d_PhysicsJointRatchet_getRatchet, _cocos2d_PhysicsJointRatchet_setRatchet);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsJointRotaryLimit_construct$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** a */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** b */
    float arg3 = 0;       /** min */
    float arg4 = 0;       /** max */

    olua_check_object(L, 1, &arg1, "cc.PhysicsBody");
    olua_check_object(L, 2, &arg2, "cc.PhysicsBody");
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // static cocos2d::PhysicsJointRotaryLimit *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, float min, float max)
    cocos2d::PhysicsJointRotaryLimit *ret = cocos2d::PhysicsJointRotaryLimit::construct(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsJointRotaryLimit");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointRotaryLimit_construct$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** a */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** b */

    olua_check_object(L, 1, &arg1, "cc.PhysicsBody");
    olua_check_object(L, 2, &arg2, "cc.PhysicsBody");

    // static cocos2d::PhysicsJointRotaryLimit *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b)
    cocos2d::PhysicsJointRotaryLimit *ret = cocos2d::PhysicsJointRotaryLimit::construct(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsJointRotaryLimit");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointRotaryLimit_construct(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.PhysicsBody")) && (olua_is_object(L, 2, "cc.PhysicsBody"))) {
            // static cocos2d::PhysicsJointRotaryLimit *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b)
            return _cocos2d_PhysicsJointRotaryLimit_construct$2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.PhysicsBody")) && (olua_is_object(L, 2, "cc.PhysicsBody")) && (olua_is_number(L, 3)) && (olua_is_number(L, 4))) {
            // static cocos2d::PhysicsJointRotaryLimit *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, float min, float max)
            return _cocos2d_PhysicsJointRotaryLimit_construct$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsJointRotaryLimit::construct' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsJointRotaryLimit_createConstraints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRotaryLimit *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointRotaryLimit");

    // bool createConstraints()
    bool ret = self->createConstraints();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointRotaryLimit_getMax(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRotaryLimit *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointRotaryLimit");

    // float getMax()
    float ret = self->getMax();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointRotaryLimit_getMin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRotaryLimit *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointRotaryLimit");

    // float getMin()
    float ret = self->getMin();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointRotaryLimit_setMax(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRotaryLimit *self = nullptr;
    float arg1 = 0;       /** max */

    olua_to_object(L, 1, &self, "cc.PhysicsJointRotaryLimit");
    olua_check_number(L, 2, &arg1);

    // void setMax(float max)
    self->setMax(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJointRotaryLimit_setMin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRotaryLimit *self = nullptr;
    float arg1 = 0;       /** min */

    olua_to_object(L, 1, &self, "cc.PhysicsJointRotaryLimit");
    olua_check_number(L, 2, &arg1);

    // void setMin(float min)
    self->setMin(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsJointRotaryLimit(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsJointRotaryLimit, cocos2d::PhysicsJoint>(L, "cc.PhysicsJointRotaryLimit");
    oluacls_func(L, "construct", _cocos2d_PhysicsJointRotaryLimit_construct);
    oluacls_func(L, "createConstraints", _cocos2d_PhysicsJointRotaryLimit_createConstraints);
    oluacls_func(L, "getMax", _cocos2d_PhysicsJointRotaryLimit_getMax);
    oluacls_func(L, "getMin", _cocos2d_PhysicsJointRotaryLimit_getMin);
    oluacls_func(L, "setMax", _cocos2d_PhysicsJointRotaryLimit_setMax);
    oluacls_func(L, "setMin", _cocos2d_PhysicsJointRotaryLimit_setMin);
    oluacls_prop(L, "max", _cocos2d_PhysicsJointRotaryLimit_getMax, _cocos2d_PhysicsJointRotaryLimit_setMax);
    oluacls_prop(L, "min", _cocos2d_PhysicsJointRotaryLimit_getMin, _cocos2d_PhysicsJointRotaryLimit_setMin);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsJointRotarySpring_construct(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** a */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** b */
    float arg3 = 0;       /** stiffness */
    float arg4 = 0;       /** damping */

    olua_check_object(L, 1, &arg1, "cc.PhysicsBody");
    olua_check_object(L, 2, &arg2, "cc.PhysicsBody");
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // static cocos2d::PhysicsJointRotarySpring *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, float stiffness, float damping)
    cocos2d::PhysicsJointRotarySpring *ret = cocos2d::PhysicsJointRotarySpring::construct(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsJointRotarySpring");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointRotarySpring_createConstraints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRotarySpring *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointRotarySpring");

    // bool createConstraints()
    bool ret = self->createConstraints();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointRotarySpring_getDamping(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRotarySpring *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointRotarySpring");

    // float getDamping()
    float ret = self->getDamping();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointRotarySpring_getRestAngle(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRotarySpring *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointRotarySpring");

    // float getRestAngle()
    float ret = self->getRestAngle();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointRotarySpring_getStiffness(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRotarySpring *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointRotarySpring");

    // float getStiffness()
    float ret = self->getStiffness();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointRotarySpring_setDamping(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRotarySpring *self = nullptr;
    float arg1 = 0;       /** damping */

    olua_to_object(L, 1, &self, "cc.PhysicsJointRotarySpring");
    olua_check_number(L, 2, &arg1);

    // void setDamping(float damping)
    self->setDamping(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJointRotarySpring_setRestAngle(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRotarySpring *self = nullptr;
    float arg1 = 0;       /** restAngle */

    olua_to_object(L, 1, &self, "cc.PhysicsJointRotarySpring");
    olua_check_number(L, 2, &arg1);

    // void setRestAngle(float restAngle)
    self->setRestAngle(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJointRotarySpring_setStiffness(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRotarySpring *self = nullptr;
    float arg1 = 0;       /** stiffness */

    olua_to_object(L, 1, &self, "cc.PhysicsJointRotarySpring");
    olua_check_number(L, 2, &arg1);

    // void setStiffness(float stiffness)
    self->setStiffness(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsJointRotarySpring(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsJointRotarySpring, cocos2d::PhysicsJoint>(L, "cc.PhysicsJointRotarySpring");
    oluacls_func(L, "construct", _cocos2d_PhysicsJointRotarySpring_construct);
    oluacls_func(L, "createConstraints", _cocos2d_PhysicsJointRotarySpring_createConstraints);
    oluacls_func(L, "getDamping", _cocos2d_PhysicsJointRotarySpring_getDamping);
    oluacls_func(L, "getRestAngle", _cocos2d_PhysicsJointRotarySpring_getRestAngle);
    oluacls_func(L, "getStiffness", _cocos2d_PhysicsJointRotarySpring_getStiffness);
    oluacls_func(L, "setDamping", _cocos2d_PhysicsJointRotarySpring_setDamping);
    oluacls_func(L, "setRestAngle", _cocos2d_PhysicsJointRotarySpring_setRestAngle);
    oluacls_func(L, "setStiffness", _cocos2d_PhysicsJointRotarySpring_setStiffness);
    oluacls_prop(L, "damping", _cocos2d_PhysicsJointRotarySpring_getDamping, _cocos2d_PhysicsJointRotarySpring_setDamping);
    oluacls_prop(L, "restAngle", _cocos2d_PhysicsJointRotarySpring_getRestAngle, _cocos2d_PhysicsJointRotarySpring_setRestAngle);
    oluacls_prop(L, "stiffness", _cocos2d_PhysicsJointRotarySpring_getStiffness, _cocos2d_PhysicsJointRotarySpring_setStiffness);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsJointSpring_construct(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** a */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** b */
    cocos2d::Vec2 arg3;       /** anchr1 */
    cocos2d::Vec2 arg4;       /** anchr2 */
    float arg5 = 0;       /** stiffness */
    float arg6 = 0;       /** damping */

    olua_check_object(L, 1, &arg1, "cc.PhysicsBody");
    olua_check_object(L, 2, &arg2, "cc.PhysicsBody");
    olua_check_object(L, 3, &arg3, "cc.Vec2");
    olua_check_object(L, 4, &arg4, "cc.Vec2");
    olua_check_number(L, 5, &arg5);
    olua_check_number(L, 6, &arg6);

    // static cocos2d::PhysicsJointSpring *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2, float stiffness, float damping)
    cocos2d::PhysicsJointSpring *ret = cocos2d::PhysicsJointSpring::construct(arg1, arg2, arg3, arg4, arg5, arg6);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsJointSpring");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointSpring_createConstraints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointSpring *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointSpring");

    // bool createConstraints()
    bool ret = self->createConstraints();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointSpring_getAnchr1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointSpring *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointSpring");

    // cocos2d::Vec2 getAnchr1()
    cocos2d::Vec2 ret = self->getAnchr1();
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointSpring_getAnchr2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointSpring *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointSpring");

    // cocos2d::Vec2 getAnchr2()
    cocos2d::Vec2 ret = self->getAnchr2();
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointSpring_getDamping(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointSpring *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointSpring");

    // float getDamping()
    float ret = self->getDamping();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointSpring_getRestLength(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointSpring *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointSpring");

    // float getRestLength()
    float ret = self->getRestLength();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointSpring_getStiffness(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointSpring *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsJointSpring");

    // float getStiffness()
    float ret = self->getStiffness();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointSpring_setAnchr1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointSpring *self = nullptr;
    cocos2d::Vec2 arg1;       /** anchr1 */

    olua_to_object(L, 1, &self, "cc.PhysicsJointSpring");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void setAnchr1(const cocos2d::Vec2 &anchr1)
    self->setAnchr1(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJointSpring_setAnchr2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointSpring *self = nullptr;
    cocos2d::Vec2 arg1;       /** anchr2 */

    olua_to_object(L, 1, &self, "cc.PhysicsJointSpring");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void setAnchr2(const cocos2d::Vec2 &anchr2)
    self->setAnchr2(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJointSpring_setDamping(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointSpring *self = nullptr;
    float arg1 = 0;       /** damping */

    olua_to_object(L, 1, &self, "cc.PhysicsJointSpring");
    olua_check_number(L, 2, &arg1);

    // void setDamping(float damping)
    self->setDamping(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJointSpring_setRestLength(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointSpring *self = nullptr;
    float arg1 = 0;       /** restLength */

    olua_to_object(L, 1, &self, "cc.PhysicsJointSpring");
    olua_check_number(L, 2, &arg1);

    // void setRestLength(float restLength)
    self->setRestLength(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJointSpring_setStiffness(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointSpring *self = nullptr;
    float arg1 = 0;       /** stiffness */

    olua_to_object(L, 1, &self, "cc.PhysicsJointSpring");
    olua_check_number(L, 2, &arg1);

    // void setStiffness(float stiffness)
    self->setStiffness(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsJointSpring(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsJointSpring, cocos2d::PhysicsJoint>(L, "cc.PhysicsJointSpring");
    oluacls_func(L, "construct", _cocos2d_PhysicsJointSpring_construct);
    oluacls_func(L, "createConstraints", _cocos2d_PhysicsJointSpring_createConstraints);
    oluacls_func(L, "getAnchr1", _cocos2d_PhysicsJointSpring_getAnchr1);
    oluacls_func(L, "getAnchr2", _cocos2d_PhysicsJointSpring_getAnchr2);
    oluacls_func(L, "getDamping", _cocos2d_PhysicsJointSpring_getDamping);
    oluacls_func(L, "getRestLength", _cocos2d_PhysicsJointSpring_getRestLength);
    oluacls_func(L, "getStiffness", _cocos2d_PhysicsJointSpring_getStiffness);
    oluacls_func(L, "setAnchr1", _cocos2d_PhysicsJointSpring_setAnchr1);
    oluacls_func(L, "setAnchr2", _cocos2d_PhysicsJointSpring_setAnchr2);
    oluacls_func(L, "setDamping", _cocos2d_PhysicsJointSpring_setDamping);
    oluacls_func(L, "setRestLength", _cocos2d_PhysicsJointSpring_setRestLength);
    oluacls_func(L, "setStiffness", _cocos2d_PhysicsJointSpring_setStiffness);
    oluacls_prop(L, "anchr1", _cocos2d_PhysicsJointSpring_getAnchr1, _cocos2d_PhysicsJointSpring_setAnchr1);
    oluacls_prop(L, "anchr2", _cocos2d_PhysicsJointSpring_getAnchr2, _cocos2d_PhysicsJointSpring_setAnchr2);
    oluacls_prop(L, "damping", _cocos2d_PhysicsJointSpring_getDamping, _cocos2d_PhysicsJointSpring_setDamping);
    oluacls_prop(L, "restLength", _cocos2d_PhysicsJointSpring_getRestLength, _cocos2d_PhysicsJointSpring_setRestLength);
    oluacls_prop(L, "stiffness", _cocos2d_PhysicsJointSpring_getStiffness, _cocos2d_PhysicsJointSpring_setStiffness);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsShape_Type(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsShape::Type>(L, "cc.PhysicsShape.Type");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "BOX", (lua_Integer)cocos2d::PhysicsShape::Type::BOX);
    oluacls_enum(L, "CIRCLE", (lua_Integer)cocos2d::PhysicsShape::Type::CIRCLE);
    oluacls_enum(L, "EDGEBOX", (lua_Integer)cocos2d::PhysicsShape::Type::EDGEBOX);
    oluacls_enum(L, "EDGECHAIN", (lua_Integer)cocos2d::PhysicsShape::Type::EDGECHAIN);
    oluacls_enum(L, "EDGEPOLYGEN", (lua_Integer)cocos2d::PhysicsShape::Type::EDGEPOLYGEN);
    oluacls_enum(L, "EDGEPOLYGON", (lua_Integer)cocos2d::PhysicsShape::Type::EDGEPOLYGON);
    oluacls_enum(L, "EDGESEGMENT", (lua_Integer)cocos2d::PhysicsShape::Type::EDGESEGMENT);
    oluacls_enum(L, "POLYGEN", (lua_Integer)cocos2d::PhysicsShape::Type::POLYGEN);
    oluacls_enum(L, "POLYGON", (lua_Integer)cocos2d::PhysicsShape::Type::POLYGON);
    oluacls_enum(L, "UNKNOWN", (lua_Integer)cocos2d::PhysicsShape::Type::UNKNOWN);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsShape_calculateDefaultMoment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsShape");

    // float calculateDefaultMoment()
    float ret = self->calculateDefaultMoment();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_containsPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;
    cocos2d::Vec2 arg1;       /** point */

    olua_to_object(L, 1, &self, "cc.PhysicsShape");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // bool containsPoint(const cocos2d::Vec2 &point)
    bool ret = self->containsPoint(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getArea(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsShape");

    // float getArea()
    float ret = self->getArea();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getBody(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsShape");

    // cocos2d::PhysicsBody *getBody()
    cocos2d::PhysicsBody *ret = self->getBody();
    int num_ret = olua_push_object(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getCategoryBitmask(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsShape");

    // int getCategoryBitmask()
    int ret = self->getCategoryBitmask();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getCenter(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsShape");

    // cocos2d::Vec2 getCenter()
    cocos2d::Vec2 ret = self->getCenter();
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getCollisionBitmask(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsShape");

    // int getCollisionBitmask()
    int ret = self->getCollisionBitmask();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getContactTestBitmask(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsShape");

    // int getContactTestBitmask()
    int ret = self->getContactTestBitmask();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getDensity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsShape");

    // float getDensity()
    float ret = self->getDensity();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getFriction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsShape");

    // float getFriction()
    float ret = self->getFriction();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getGroup(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsShape");

    // int getGroup()
    int ret = self->getGroup();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getMass(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsShape");

    // float getMass()
    float ret = self->getMass();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getMaterial(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsShape");

    // const cocos2d::PhysicsMaterial &getMaterial()
    const cocos2d::PhysicsMaterial &ret = self->getMaterial();
    int num_ret = olua_push_object(L, ret, "cc.PhysicsMaterial");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getMoment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsShape");

    // float getMoment()
    float ret = self->getMoment();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getOffset(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsShape");

    // cocos2d::Vec2 getOffset()
    cocos2d::Vec2 ret = self->getOffset();
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getPolygonCenter(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1 = nullptr;       /** points */
    int arg2 = 0;       /** count */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_integer(L, 2, &arg2);

    // static cocos2d::Vec2 getPolygonCenter(const cocos2d::Vec2 *points, int count)
    cocos2d::Vec2 ret = cocos2d::PhysicsShape::getPolygonCenter(arg1, arg2);
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getRestitution(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsShape");

    // float getRestitution()
    float ret = self->getRestitution();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getTag(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsShape");

    // int getTag()
    int ret = self->getTag();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsShape");

    // cocos2d::PhysicsShape::Type getType()
    cocos2d::PhysicsShape::Type ret = self->getType();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_isSensor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsShape");

    // bool isSensor()
    bool ret = self->isSensor();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_recenterPoints$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1 = nullptr;       /** points */
    int arg2 = 0;       /** count */
    cocos2d::Vec2 arg3;       /** center */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_integer(L, 2, &arg2);
    olua_check_object(L, 3, &arg3, "cc.Vec2");

    // static void recenterPoints(cocos2d::Vec2 *points, int count, @optional const cocos2d::Vec2 &center)
    cocos2d::PhysicsShape::recenterPoints(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsShape_recenterPoints$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1 = nullptr;       /** points */
    int arg2 = 0;       /** count */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_integer(L, 2, &arg2);

    // static void recenterPoints(cocos2d::Vec2 *points, int count, @optional const cocos2d::Vec2 &center)
    cocos2d::PhysicsShape::recenterPoints(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsShape_recenterPoints(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_integer(L, 2))) {
            // static void recenterPoints(cocos2d::Vec2 *points, int count, @optional const cocos2d::Vec2 &center)
            return _cocos2d_PhysicsShape_recenterPoints$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_integer(L, 2)) && (olua_is_object(L, 3, "cc.Vec2"))) {
            // static void recenterPoints(cocos2d::Vec2 *points, int count, @optional const cocos2d::Vec2 &center)
            return _cocos2d_PhysicsShape_recenterPoints$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsShape::recenterPoints' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsShape_setCategoryBitmask(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;
    int arg1 = 0;       /** bitmask */

    olua_to_object(L, 1, &self, "cc.PhysicsShape");
    olua_check_integer(L, 2, &arg1);

    // void setCategoryBitmask(int bitmask)
    self->setCategoryBitmask(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsShape_setCollisionBitmask(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;
    int arg1 = 0;       /** bitmask */

    olua_to_object(L, 1, &self, "cc.PhysicsShape");
    olua_check_integer(L, 2, &arg1);

    // void setCollisionBitmask(int bitmask)
    self->setCollisionBitmask(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsShape_setContactTestBitmask(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;
    int arg1 = 0;       /** bitmask */

    olua_to_object(L, 1, &self, "cc.PhysicsShape");
    olua_check_integer(L, 2, &arg1);

    // void setContactTestBitmask(int bitmask)
    self->setContactTestBitmask(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsShape_setDensity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;
    float arg1 = 0;       /** density */

    olua_to_object(L, 1, &self, "cc.PhysicsShape");
    olua_check_number(L, 2, &arg1);

    // void setDensity(float density)
    self->setDensity(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsShape_setFriction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;
    float arg1 = 0;       /** friction */

    olua_to_object(L, 1, &self, "cc.PhysicsShape");
    olua_check_number(L, 2, &arg1);

    // void setFriction(float friction)
    self->setFriction(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsShape_setGroup(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;
    int arg1 = 0;       /** group */

    olua_to_object(L, 1, &self, "cc.PhysicsShape");
    olua_check_integer(L, 2, &arg1);

    // void setGroup(int group)
    self->setGroup(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsShape_setMass(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;
    float arg1 = 0;       /** mass */

    olua_to_object(L, 1, &self, "cc.PhysicsShape");
    olua_check_number(L, 2, &arg1);

    // void setMass(float mass)
    self->setMass(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsShape_setMaterial(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;
    cocos2d::PhysicsMaterial arg1;       /** material */

    olua_to_object(L, 1, &self, "cc.PhysicsShape");
    olua_check_object(L, 2, &arg1, "cc.PhysicsMaterial");

    // void setMaterial(const cocos2d::PhysicsMaterial &material)
    self->setMaterial(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsShape_setMoment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;
    float arg1 = 0;       /** moment */

    olua_to_object(L, 1, &self, "cc.PhysicsShape");
    olua_check_number(L, 2, &arg1);

    // void setMoment(float moment)
    self->setMoment(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsShape_setRestitution(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;
    float arg1 = 0;       /** restitution */

    olua_to_object(L, 1, &self, "cc.PhysicsShape");
    olua_check_number(L, 2, &arg1);

    // void setRestitution(float restitution)
    self->setRestitution(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsShape_setSensor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;
    bool arg1 = false;       /** sensor */

    olua_to_object(L, 1, &self, "cc.PhysicsShape");
    olua_check_bool(L, 2, &arg1);

    // void setSensor(bool sensor)
    self->setSensor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsShape_setTag(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;
    int arg1 = 0;       /** tag */

    olua_to_object(L, 1, &self, "cc.PhysicsShape");
    olua_check_integer(L, 2, &arg1);

    // void setTag(int tag)
    self->setTag(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsShape(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsShape, cocos2d::Ref>(L, "cc.PhysicsShape");
    oluacls_func(L, "calculateDefaultMoment", _cocos2d_PhysicsShape_calculateDefaultMoment);
    oluacls_func(L, "containsPoint", _cocos2d_PhysicsShape_containsPoint);
    oluacls_func(L, "getArea", _cocos2d_PhysicsShape_getArea);
    oluacls_func(L, "getBody", _cocos2d_PhysicsShape_getBody);
    oluacls_func(L, "getCategoryBitmask", _cocos2d_PhysicsShape_getCategoryBitmask);
    oluacls_func(L, "getCenter", _cocos2d_PhysicsShape_getCenter);
    oluacls_func(L, "getCollisionBitmask", _cocos2d_PhysicsShape_getCollisionBitmask);
    oluacls_func(L, "getContactTestBitmask", _cocos2d_PhysicsShape_getContactTestBitmask);
    oluacls_func(L, "getDensity", _cocos2d_PhysicsShape_getDensity);
    oluacls_func(L, "getFriction", _cocos2d_PhysicsShape_getFriction);
    oluacls_func(L, "getGroup", _cocos2d_PhysicsShape_getGroup);
    oluacls_func(L, "getMass", _cocos2d_PhysicsShape_getMass);
    oluacls_func(L, "getMaterial", _cocos2d_PhysicsShape_getMaterial);
    oluacls_func(L, "getMoment", _cocos2d_PhysicsShape_getMoment);
    oluacls_func(L, "getOffset", _cocos2d_PhysicsShape_getOffset);
    oluacls_func(L, "getPolygonCenter", _cocos2d_PhysicsShape_getPolygonCenter);
    oluacls_func(L, "getRestitution", _cocos2d_PhysicsShape_getRestitution);
    oluacls_func(L, "getTag", _cocos2d_PhysicsShape_getTag);
    oluacls_func(L, "getType", _cocos2d_PhysicsShape_getType);
    oluacls_func(L, "isSensor", _cocos2d_PhysicsShape_isSensor);
    oluacls_func(L, "recenterPoints", _cocos2d_PhysicsShape_recenterPoints);
    oluacls_func(L, "setCategoryBitmask", _cocos2d_PhysicsShape_setCategoryBitmask);
    oluacls_func(L, "setCollisionBitmask", _cocos2d_PhysicsShape_setCollisionBitmask);
    oluacls_func(L, "setContactTestBitmask", _cocos2d_PhysicsShape_setContactTestBitmask);
    oluacls_func(L, "setDensity", _cocos2d_PhysicsShape_setDensity);
    oluacls_func(L, "setFriction", _cocos2d_PhysicsShape_setFriction);
    oluacls_func(L, "setGroup", _cocos2d_PhysicsShape_setGroup);
    oluacls_func(L, "setMass", _cocos2d_PhysicsShape_setMass);
    oluacls_func(L, "setMaterial", _cocos2d_PhysicsShape_setMaterial);
    oluacls_func(L, "setMoment", _cocos2d_PhysicsShape_setMoment);
    oluacls_func(L, "setRestitution", _cocos2d_PhysicsShape_setRestitution);
    oluacls_func(L, "setSensor", _cocos2d_PhysicsShape_setSensor);
    oluacls_func(L, "setTag", _cocos2d_PhysicsShape_setTag);
    oluacls_prop(L, "area", _cocos2d_PhysicsShape_getArea, nullptr);
    oluacls_prop(L, "body", _cocos2d_PhysicsShape_getBody, nullptr);
    oluacls_prop(L, "categoryBitmask", _cocos2d_PhysicsShape_getCategoryBitmask, _cocos2d_PhysicsShape_setCategoryBitmask);
    oluacls_prop(L, "center", _cocos2d_PhysicsShape_getCenter, nullptr);
    oluacls_prop(L, "collisionBitmask", _cocos2d_PhysicsShape_getCollisionBitmask, _cocos2d_PhysicsShape_setCollisionBitmask);
    oluacls_prop(L, "contactTestBitmask", _cocos2d_PhysicsShape_getContactTestBitmask, _cocos2d_PhysicsShape_setContactTestBitmask);
    oluacls_prop(L, "density", _cocos2d_PhysicsShape_getDensity, _cocos2d_PhysicsShape_setDensity);
    oluacls_prop(L, "friction", _cocos2d_PhysicsShape_getFriction, _cocos2d_PhysicsShape_setFriction);
    oluacls_prop(L, "group", _cocos2d_PhysicsShape_getGroup, _cocos2d_PhysicsShape_setGroup);
    oluacls_prop(L, "mass", _cocos2d_PhysicsShape_getMass, _cocos2d_PhysicsShape_setMass);
    oluacls_prop(L, "material", _cocos2d_PhysicsShape_getMaterial, _cocos2d_PhysicsShape_setMaterial);
    oluacls_prop(L, "moment", _cocos2d_PhysicsShape_getMoment, _cocos2d_PhysicsShape_setMoment);
    oluacls_prop(L, "offset", _cocos2d_PhysicsShape_getOffset, nullptr);
    oluacls_prop(L, "restitution", _cocos2d_PhysicsShape_getRestitution, _cocos2d_PhysicsShape_setRestitution);
    oluacls_prop(L, "sensor", _cocos2d_PhysicsShape_isSensor, _cocos2d_PhysicsShape_setSensor);
    oluacls_prop(L, "tag", _cocos2d_PhysicsShape_getTag, _cocos2d_PhysicsShape_setTag);
    oluacls_prop(L, "type", _cocos2d_PhysicsShape_getType, nullptr);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsShapePolygon_calculateArea(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1 = nullptr;       /** points */
    int arg2 = 0;       /** count */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_integer(L, 2, &arg2);

    // static float calculateArea(const cocos2d::Vec2 *points, int count)
    float ret = cocos2d::PhysicsShapePolygon::calculateArea(arg1, arg2);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapePolygon_calculateMoment$1(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** mass */
    cocos2d::Vec2 *arg2 = nullptr;       /** points */
    int arg3 = 0;       /** count */
    cocos2d::Vec2 arg4;       /** offset */
    float arg5 = 0;       /** radius */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Vec2");
    olua_check_integer(L, 3, &arg3);
    olua_check_object(L, 4, &arg4, "cc.Vec2");
    olua_check_number(L, 5, &arg5);

    // static float calculateMoment(float mass, const cocos2d::Vec2 *points, int count, @optional const cocos2d::Vec2 &offset, @optional float radius)
    float ret = cocos2d::PhysicsShapePolygon::calculateMoment(arg1, arg2, arg3, arg4, arg5);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapePolygon_calculateMoment$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** mass */
    cocos2d::Vec2 *arg2 = nullptr;       /** points */
    int arg3 = 0;       /** count */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Vec2");
    olua_check_integer(L, 3, &arg3);

    // static float calculateMoment(float mass, const cocos2d::Vec2 *points, int count, @optional const cocos2d::Vec2 &offset, @optional float radius)
    float ret = cocos2d::PhysicsShapePolygon::calculateMoment(arg1, arg2, arg3);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapePolygon_calculateMoment$3(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** mass */
    cocos2d::Vec2 *arg2 = nullptr;       /** points */
    int arg3 = 0;       /** count */
    cocos2d::Vec2 arg4;       /** offset */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Vec2");
    olua_check_integer(L, 3, &arg3);
    olua_check_object(L, 4, &arg4, "cc.Vec2");

    // static float calculateMoment(float mass, const cocos2d::Vec2 *points, int count, @optional const cocos2d::Vec2 &offset, @optional float radius)
    float ret = cocos2d::PhysicsShapePolygon::calculateMoment(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapePolygon_calculateMoment(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (olua_is_object(L, 2, "cc.Vec2")) && (olua_is_integer(L, 3))) {
            // static float calculateMoment(float mass, const cocos2d::Vec2 *points, int count, @optional const cocos2d::Vec2 &offset, @optional float radius)
            return _cocos2d_PhysicsShapePolygon_calculateMoment$2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_number(L, 1)) && (olua_is_object(L, 2, "cc.Vec2")) && (olua_is_integer(L, 3)) && (olua_is_object(L, 4, "cc.Vec2"))) {
            // static float calculateMoment(float mass, const cocos2d::Vec2 *points, int count, @optional const cocos2d::Vec2 &offset, @optional float radius)
            return _cocos2d_PhysicsShapePolygon_calculateMoment$3(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_number(L, 1)) && (olua_is_object(L, 2, "cc.Vec2")) && (olua_is_integer(L, 3)) && (olua_is_object(L, 4, "cc.Vec2")) && (olua_is_number(L, 5))) {
            // static float calculateMoment(float mass, const cocos2d::Vec2 *points, int count, @optional const cocos2d::Vec2 &offset, @optional float radius)
            return _cocos2d_PhysicsShapePolygon_calculateMoment$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsShapePolygon::calculateMoment' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsShapePolygon_create$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1 = nullptr;       /** points */
    int arg2 = 0;       /** count */
    cocos2d::PhysicsMaterial arg3;       /** material */
    cocos2d::Vec2 arg4;       /** offset */
    float arg5 = 0;       /** radius */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_integer(L, 2, &arg2);
    olua_check_object(L, 3, &arg3, "cc.PhysicsMaterial");
    olua_check_object(L, 4, &arg4, "cc.Vec2");
    olua_check_number(L, 5, &arg5);

    // static cocos2d::PhysicsShapePolygon *create(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset, @optional float radius)
    cocos2d::PhysicsShapePolygon *ret = cocos2d::PhysicsShapePolygon::create(arg1, arg2, arg3, arg4, arg5);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShapePolygon");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapePolygon_create$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1 = nullptr;       /** points */
    int arg2 = 0;       /** count */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_integer(L, 2, &arg2);

    // static cocos2d::PhysicsShapePolygon *create(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset, @optional float radius)
    cocos2d::PhysicsShapePolygon *ret = cocos2d::PhysicsShapePolygon::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShapePolygon");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapePolygon_create$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1 = nullptr;       /** points */
    int arg2 = 0;       /** count */
    cocos2d::PhysicsMaterial arg3;       /** material */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_integer(L, 2, &arg2);
    olua_check_object(L, 3, &arg3, "cc.PhysicsMaterial");

    // static cocos2d::PhysicsShapePolygon *create(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset, @optional float radius)
    cocos2d::PhysicsShapePolygon *ret = cocos2d::PhysicsShapePolygon::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShapePolygon");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapePolygon_create$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1 = nullptr;       /** points */
    int arg2 = 0;       /** count */
    cocos2d::PhysicsMaterial arg3;       /** material */
    cocos2d::Vec2 arg4;       /** offset */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_integer(L, 2, &arg2);
    olua_check_object(L, 3, &arg3, "cc.PhysicsMaterial");
    olua_check_object(L, 4, &arg4, "cc.Vec2");

    // static cocos2d::PhysicsShapePolygon *create(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset, @optional float radius)
    cocos2d::PhysicsShapePolygon *ret = cocos2d::PhysicsShapePolygon::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShapePolygon");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapePolygon_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_integer(L, 2))) {
            // static cocos2d::PhysicsShapePolygon *create(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset, @optional float radius)
            return _cocos2d_PhysicsShapePolygon_create$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_integer(L, 2)) && (olua_is_object(L, 3, "cc.PhysicsMaterial"))) {
            // static cocos2d::PhysicsShapePolygon *create(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset, @optional float radius)
            return _cocos2d_PhysicsShapePolygon_create$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_integer(L, 2)) && (olua_is_object(L, 3, "cc.PhysicsMaterial")) && (olua_is_object(L, 4, "cc.Vec2"))) {
            // static cocos2d::PhysicsShapePolygon *create(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset, @optional float radius)
            return _cocos2d_PhysicsShapePolygon_create$4(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_integer(L, 2)) && (olua_is_object(L, 3, "cc.PhysicsMaterial")) && (olua_is_object(L, 4, "cc.Vec2")) && (olua_is_number(L, 5))) {
            // static cocos2d::PhysicsShapePolygon *create(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset, @optional float radius)
            return _cocos2d_PhysicsShapePolygon_create$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsShapePolygon::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsShapePolygon_getPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShapePolygon *self = nullptr;
    int arg1 = 0;       /** i */

    olua_to_object(L, 1, &self, "cc.PhysicsShapePolygon");
    olua_check_integer(L, 2, &arg1);

    // cocos2d::Vec2 getPoint(int i)
    cocos2d::Vec2 ret = self->getPoint(arg1);
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapePolygon_getPoints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShapePolygon *self = nullptr;
    cocos2d::Vec2 *arg1 = nullptr;       /** outPoints */

    olua_to_object(L, 1, &self, "cc.PhysicsShapePolygon");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void getPoints(cocos2d::Vec2 *outPoints)
    self->getPoints(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsShapePolygon_getPointsCount(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShapePolygon *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsShapePolygon");

    // int getPointsCount()
    int ret = self->getPointsCount();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsShapePolygon(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsShapePolygon, cocos2d::PhysicsShape>(L, "cc.PhysicsShapePolygon");
    oluacls_func(L, "calculateArea", _cocos2d_PhysicsShapePolygon_calculateArea);
    oluacls_func(L, "calculateMoment", _cocos2d_PhysicsShapePolygon_calculateMoment);
    oluacls_func(L, "create", _cocos2d_PhysicsShapePolygon_create);
    oluacls_func(L, "getPoint", _cocos2d_PhysicsShapePolygon_getPoint);
    oluacls_func(L, "getPoints", _cocos2d_PhysicsShapePolygon_getPoints);
    oluacls_func(L, "getPointsCount", _cocos2d_PhysicsShapePolygon_getPointsCount);
    oluacls_prop(L, "pointsCount", _cocos2d_PhysicsShapePolygon_getPointsCount, nullptr);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsShapeEdgePolygon_create$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1 = nullptr;       /** points */
    int arg2 = 0;       /** count */
    cocos2d::PhysicsMaterial arg3;       /** material */
    float arg4 = 0;       /** border */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_integer(L, 2, &arg2);
    olua_check_object(L, 3, &arg3, "cc.PhysicsMaterial");
    olua_check_number(L, 4, &arg4);

    // static cocos2d::PhysicsShapeEdgePolygon *create(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
    cocos2d::PhysicsShapeEdgePolygon *ret = cocos2d::PhysicsShapeEdgePolygon::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShapeEdgePolygon");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeEdgePolygon_create$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1 = nullptr;       /** points */
    int arg2 = 0;       /** count */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_integer(L, 2, &arg2);

    // static cocos2d::PhysicsShapeEdgePolygon *create(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
    cocos2d::PhysicsShapeEdgePolygon *ret = cocos2d::PhysicsShapeEdgePolygon::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShapeEdgePolygon");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeEdgePolygon_create$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1 = nullptr;       /** points */
    int arg2 = 0;       /** count */
    cocos2d::PhysicsMaterial arg3;       /** material */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_integer(L, 2, &arg2);
    olua_check_object(L, 3, &arg3, "cc.PhysicsMaterial");

    // static cocos2d::PhysicsShapeEdgePolygon *create(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
    cocos2d::PhysicsShapeEdgePolygon *ret = cocos2d::PhysicsShapeEdgePolygon::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShapeEdgePolygon");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeEdgePolygon_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_integer(L, 2))) {
            // static cocos2d::PhysicsShapeEdgePolygon *create(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
            return _cocos2d_PhysicsShapeEdgePolygon_create$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_integer(L, 2)) && (olua_is_object(L, 3, "cc.PhysicsMaterial"))) {
            // static cocos2d::PhysicsShapeEdgePolygon *create(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
            return _cocos2d_PhysicsShapeEdgePolygon_create$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_integer(L, 2)) && (olua_is_object(L, 3, "cc.PhysicsMaterial")) && (olua_is_number(L, 4))) {
            // static cocos2d::PhysicsShapeEdgePolygon *create(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
            return _cocos2d_PhysicsShapeEdgePolygon_create$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsShapeEdgePolygon::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsShapeEdgePolygon_getPoints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShapeEdgePolygon *self = nullptr;
    cocos2d::Vec2 *arg1 = nullptr;       /** outPoints */

    olua_to_object(L, 1, &self, "cc.PhysicsShapeEdgePolygon");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void getPoints(cocos2d::Vec2 *outPoints)
    self->getPoints(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsShapeEdgePolygon_getPointsCount(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShapeEdgePolygon *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsShapeEdgePolygon");

    // int getPointsCount()
    int ret = self->getPointsCount();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsShapeEdgePolygon(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsShapeEdgePolygon, cocos2d::PhysicsShape>(L, "cc.PhysicsShapeEdgePolygon");
    oluacls_func(L, "create", _cocos2d_PhysicsShapeEdgePolygon_create);
    oluacls_func(L, "getPoints", _cocos2d_PhysicsShapeEdgePolygon_getPoints);
    oluacls_func(L, "getPointsCount", _cocos2d_PhysicsShapeEdgePolygon_getPointsCount);
    oluacls_prop(L, "pointsCount", _cocos2d_PhysicsShapeEdgePolygon_getPointsCount, nullptr);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsShapeBox_create$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    cocos2d::PhysicsMaterial arg2;       /** material */
    cocos2d::Vec2 arg3;       /** offset */
    float arg4 = 0;       /** radius */

    olua_check_object(L, 1, &arg1, "cc.Size");
    olua_check_object(L, 2, &arg2, "cc.PhysicsMaterial");
    olua_check_object(L, 3, &arg3, "cc.Vec2");
    olua_check_number(L, 4, &arg4);

    // static cocos2d::PhysicsShapeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset, @optional float radius)
    cocos2d::PhysicsShapeBox *ret = cocos2d::PhysicsShapeBox::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShapeBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeBox_create$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */

    olua_check_object(L, 1, &arg1, "cc.Size");

    // static cocos2d::PhysicsShapeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset, @optional float radius)
    cocos2d::PhysicsShapeBox *ret = cocos2d::PhysicsShapeBox::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShapeBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeBox_create$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    cocos2d::PhysicsMaterial arg2;       /** material */

    olua_check_object(L, 1, &arg1, "cc.Size");
    olua_check_object(L, 2, &arg2, "cc.PhysicsMaterial");

    // static cocos2d::PhysicsShapeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset, @optional float radius)
    cocos2d::PhysicsShapeBox *ret = cocos2d::PhysicsShapeBox::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShapeBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeBox_create$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    cocos2d::PhysicsMaterial arg2;       /** material */
    cocos2d::Vec2 arg3;       /** offset */

    olua_check_object(L, 1, &arg1, "cc.Size");
    olua_check_object(L, 2, &arg2, "cc.PhysicsMaterial");
    olua_check_object(L, 3, &arg3, "cc.Vec2");

    // static cocos2d::PhysicsShapeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset, @optional float radius)
    cocos2d::PhysicsShapeBox *ret = cocos2d::PhysicsShapeBox::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShapeBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeBox_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_object(L, 1, "cc.Size"))) {
            // static cocos2d::PhysicsShapeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset, @optional float radius)
            return _cocos2d_PhysicsShapeBox_create$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Size")) && (olua_is_object(L, 2, "cc.PhysicsMaterial"))) {
            // static cocos2d::PhysicsShapeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset, @optional float radius)
            return _cocos2d_PhysicsShapeBox_create$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Size")) && (olua_is_object(L, 2, "cc.PhysicsMaterial")) && (olua_is_object(L, 3, "cc.Vec2"))) {
            // static cocos2d::PhysicsShapeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset, @optional float radius)
            return _cocos2d_PhysicsShapeBox_create$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.Size")) && (olua_is_object(L, 2, "cc.PhysicsMaterial")) && (olua_is_object(L, 3, "cc.Vec2")) && (olua_is_number(L, 4))) {
            // static cocos2d::PhysicsShapeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset, @optional float radius)
            return _cocos2d_PhysicsShapeBox_create$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsShapeBox::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsShapeBox_getSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShapeBox *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsShapeBox");

    // cocos2d::Size getSize()
    cocos2d::Size ret = self->getSize();
    int num_ret = olua_pushcopy_object(L, ret, "cc.Size");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsShapeBox(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsShapeBox, cocos2d::PhysicsShapePolygon>(L, "cc.PhysicsShapeBox");
    oluacls_func(L, "create", _cocos2d_PhysicsShapeBox_create);
    oluacls_func(L, "getSize", _cocos2d_PhysicsShapeBox_getSize);
    oluacls_prop(L, "size", _cocos2d_PhysicsShapeBox_getSize, nullptr);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsShapeCircle_calculateArea(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** radius */

    olua_check_number(L, 1, &arg1);

    // static float calculateArea(float radius)
    float ret = cocos2d::PhysicsShapeCircle::calculateArea(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeCircle_calculateMoment$1(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** mass */
    float arg2 = 0;       /** radius */
    cocos2d::Vec2 arg3;       /** offset */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_object(L, 3, &arg3, "cc.Vec2");

    // static float calculateMoment(float mass, float radius, @optional const cocos2d::Vec2 &offset)
    float ret = cocos2d::PhysicsShapeCircle::calculateMoment(arg1, arg2, arg3);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeCircle_calculateMoment$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** mass */
    float arg2 = 0;       /** radius */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static float calculateMoment(float mass, float radius, @optional const cocos2d::Vec2 &offset)
    float ret = cocos2d::PhysicsShapeCircle::calculateMoment(arg1, arg2);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeCircle_calculateMoment(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2))) {
            // static float calculateMoment(float mass, float radius, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsShapeCircle_calculateMoment$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_object(L, 3, "cc.Vec2"))) {
            // static float calculateMoment(float mass, float radius, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsShapeCircle_calculateMoment$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsShapeCircle::calculateMoment' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsShapeCircle_create$1(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** radius */
    cocos2d::PhysicsMaterial arg2;       /** material */
    cocos2d::Vec2 arg3;       /** offset */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.PhysicsMaterial");
    olua_check_object(L, 3, &arg3, "cc.Vec2");

    // static cocos2d::PhysicsShapeCircle *create(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsShapeCircle *ret = cocos2d::PhysicsShapeCircle::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShapeCircle");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeCircle_create$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** radius */

    olua_check_number(L, 1, &arg1);

    // static cocos2d::PhysicsShapeCircle *create(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsShapeCircle *ret = cocos2d::PhysicsShapeCircle::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShapeCircle");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeCircle_create$3(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** radius */
    cocos2d::PhysicsMaterial arg2;       /** material */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.PhysicsMaterial");

    // static cocos2d::PhysicsShapeCircle *create(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsShapeCircle *ret = cocos2d::PhysicsShapeCircle::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShapeCircle");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeCircle_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_number(L, 1))) {
            // static cocos2d::PhysicsShapeCircle *create(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsShapeCircle_create$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_number(L, 1)) && (olua_is_object(L, 2, "cc.PhysicsMaterial"))) {
            // static cocos2d::PhysicsShapeCircle *create(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsShapeCircle_create$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (olua_is_object(L, 2, "cc.PhysicsMaterial")) && (olua_is_object(L, 3, "cc.Vec2"))) {
            // static cocos2d::PhysicsShapeCircle *create(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsShapeCircle_create$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsShapeCircle::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsShapeCircle_getRadius(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShapeCircle *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsShapeCircle");

    // float getRadius()
    float ret = self->getRadius();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsShapeCircle(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsShapeCircle, cocos2d::PhysicsShape>(L, "cc.PhysicsShapeCircle");
    oluacls_func(L, "calculateArea", _cocos2d_PhysicsShapeCircle_calculateArea);
    oluacls_func(L, "calculateMoment", _cocos2d_PhysicsShapeCircle_calculateMoment);
    oluacls_func(L, "create", _cocos2d_PhysicsShapeCircle_create);
    oluacls_func(L, "getRadius", _cocos2d_PhysicsShapeCircle_getRadius);
    oluacls_prop(L, "radius", _cocos2d_PhysicsShapeCircle_getRadius, nullptr);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsShapeEdgeBox_create$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    cocos2d::PhysicsMaterial arg2;       /** material */
    float arg3 = 0;       /** border */
    cocos2d::Vec2 arg4;       /** offset */

    olua_check_object(L, 1, &arg1, "cc.Size");
    olua_check_object(L, 2, &arg2, "cc.PhysicsMaterial");
    olua_check_number(L, 3, &arg3);
    olua_check_object(L, 4, &arg4, "cc.Vec2");

    // static cocos2d::PhysicsShapeEdgeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsShapeEdgeBox *ret = cocos2d::PhysicsShapeEdgeBox::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShapeEdgeBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeEdgeBox_create$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */

    olua_check_object(L, 1, &arg1, "cc.Size");

    // static cocos2d::PhysicsShapeEdgeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsShapeEdgeBox *ret = cocos2d::PhysicsShapeEdgeBox::create(arg1);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShapeEdgeBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeEdgeBox_create$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    cocos2d::PhysicsMaterial arg2;       /** material */

    olua_check_object(L, 1, &arg1, "cc.Size");
    olua_check_object(L, 2, &arg2, "cc.PhysicsMaterial");

    // static cocos2d::PhysicsShapeEdgeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsShapeEdgeBox *ret = cocos2d::PhysicsShapeEdgeBox::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShapeEdgeBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeEdgeBox_create$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    cocos2d::PhysicsMaterial arg2;       /** material */
    float arg3 = 0;       /** border */

    olua_check_object(L, 1, &arg1, "cc.Size");
    olua_check_object(L, 2, &arg2, "cc.PhysicsMaterial");
    olua_check_number(L, 3, &arg3);

    // static cocos2d::PhysicsShapeEdgeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsShapeEdgeBox *ret = cocos2d::PhysicsShapeEdgeBox::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShapeEdgeBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeEdgeBox_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_object(L, 1, "cc.Size"))) {
            // static cocos2d::PhysicsShapeEdgeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsShapeEdgeBox_create$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Size")) && (olua_is_object(L, 2, "cc.PhysicsMaterial"))) {
            // static cocos2d::PhysicsShapeEdgeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsShapeEdgeBox_create$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Size")) && (olua_is_object(L, 2, "cc.PhysicsMaterial")) && (olua_is_number(L, 3))) {
            // static cocos2d::PhysicsShapeEdgeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsShapeEdgeBox_create$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.Size")) && (olua_is_object(L, 2, "cc.PhysicsMaterial")) && (olua_is_number(L, 3)) && (olua_is_object(L, 4, "cc.Vec2"))) {
            // static cocos2d::PhysicsShapeEdgeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsShapeEdgeBox_create$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsShapeEdgeBox::create' not support '%d' arguments", num_args);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsShapeEdgeBox(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsShapeEdgeBox, cocos2d::PhysicsShapeEdgePolygon>(L, "cc.PhysicsShapeEdgeBox");
    oluacls_func(L, "create", _cocos2d_PhysicsShapeEdgeBox_create);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsShapeEdgeChain_create$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1 = nullptr;       /** points */
    int arg2 = 0;       /** count */
    cocos2d::PhysicsMaterial arg3;       /** material */
    float arg4 = 0;       /** border */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_integer(L, 2, &arg2);
    olua_check_object(L, 3, &arg3, "cc.PhysicsMaterial");
    olua_check_number(L, 4, &arg4);

    // static cocos2d::PhysicsShapeEdgeChain *create(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
    cocos2d::PhysicsShapeEdgeChain *ret = cocos2d::PhysicsShapeEdgeChain::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShapeEdgeChain");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeEdgeChain_create$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1 = nullptr;       /** points */
    int arg2 = 0;       /** count */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_integer(L, 2, &arg2);

    // static cocos2d::PhysicsShapeEdgeChain *create(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
    cocos2d::PhysicsShapeEdgeChain *ret = cocos2d::PhysicsShapeEdgeChain::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShapeEdgeChain");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeEdgeChain_create$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1 = nullptr;       /** points */
    int arg2 = 0;       /** count */
    cocos2d::PhysicsMaterial arg3;       /** material */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_integer(L, 2, &arg2);
    olua_check_object(L, 3, &arg3, "cc.PhysicsMaterial");

    // static cocos2d::PhysicsShapeEdgeChain *create(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
    cocos2d::PhysicsShapeEdgeChain *ret = cocos2d::PhysicsShapeEdgeChain::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShapeEdgeChain");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeEdgeChain_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_integer(L, 2))) {
            // static cocos2d::PhysicsShapeEdgeChain *create(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
            return _cocos2d_PhysicsShapeEdgeChain_create$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_integer(L, 2)) && (olua_is_object(L, 3, "cc.PhysicsMaterial"))) {
            // static cocos2d::PhysicsShapeEdgeChain *create(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
            return _cocos2d_PhysicsShapeEdgeChain_create$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_integer(L, 2)) && (olua_is_object(L, 3, "cc.PhysicsMaterial")) && (olua_is_number(L, 4))) {
            // static cocos2d::PhysicsShapeEdgeChain *create(const cocos2d::Vec2 *points, int count, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
            return _cocos2d_PhysicsShapeEdgeChain_create$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsShapeEdgeChain::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsShapeEdgeChain_getPoints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShapeEdgeChain *self = nullptr;
    cocos2d::Vec2 *arg1 = nullptr;       /** outPoints */

    olua_to_object(L, 1, &self, "cc.PhysicsShapeEdgeChain");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void getPoints(cocos2d::Vec2 *outPoints)
    self->getPoints(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsShapeEdgeChain_getPointsCount(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShapeEdgeChain *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsShapeEdgeChain");

    // int getPointsCount()
    int ret = self->getPointsCount();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsShapeEdgeChain(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsShapeEdgeChain, cocos2d::PhysicsShape>(L, "cc.PhysicsShapeEdgeChain");
    oluacls_func(L, "create", _cocos2d_PhysicsShapeEdgeChain_create);
    oluacls_func(L, "getPoints", _cocos2d_PhysicsShapeEdgeChain_getPoints);
    oluacls_func(L, "getPointsCount", _cocos2d_PhysicsShapeEdgeChain_getPointsCount);
    oluacls_prop(L, "pointsCount", _cocos2d_PhysicsShapeEdgeChain_getPointsCount, nullptr);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsShapeEdgeSegment_create$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 arg1;       /** a */
    cocos2d::Vec2 arg2;       /** b */
    cocos2d::PhysicsMaterial arg3;       /** material */
    float arg4 = 0;       /** border */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_object(L, 2, &arg2, "cc.Vec2");
    olua_check_object(L, 3, &arg3, "cc.PhysicsMaterial");
    olua_check_number(L, 4, &arg4);

    // static cocos2d::PhysicsShapeEdgeSegment *create(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
    cocos2d::PhysicsShapeEdgeSegment *ret = cocos2d::PhysicsShapeEdgeSegment::create(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShapeEdgeSegment");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeEdgeSegment_create$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 arg1;       /** a */
    cocos2d::Vec2 arg2;       /** b */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_object(L, 2, &arg2, "cc.Vec2");

    // static cocos2d::PhysicsShapeEdgeSegment *create(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
    cocos2d::PhysicsShapeEdgeSegment *ret = cocos2d::PhysicsShapeEdgeSegment::create(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShapeEdgeSegment");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeEdgeSegment_create$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 arg1;       /** a */
    cocos2d::Vec2 arg2;       /** b */
    cocos2d::PhysicsMaterial arg3;       /** material */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_object(L, 2, &arg2, "cc.Vec2");
    olua_check_object(L, 3, &arg3, "cc.PhysicsMaterial");

    // static cocos2d::PhysicsShapeEdgeSegment *create(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
    cocos2d::PhysicsShapeEdgeSegment *ret = cocos2d::PhysicsShapeEdgeSegment::create(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShapeEdgeSegment");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeEdgeSegment_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_object(L, 2, "cc.Vec2"))) {
            // static cocos2d::PhysicsShapeEdgeSegment *create(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
            return _cocos2d_PhysicsShapeEdgeSegment_create$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_object(L, 2, "cc.Vec2")) && (olua_is_object(L, 3, "cc.PhysicsMaterial"))) {
            // static cocos2d::PhysicsShapeEdgeSegment *create(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
            return _cocos2d_PhysicsShapeEdgeSegment_create$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_object(L, 2, "cc.Vec2")) && (olua_is_object(L, 3, "cc.PhysicsMaterial")) && (olua_is_number(L, 4))) {
            // static cocos2d::PhysicsShapeEdgeSegment *create(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
            return _cocos2d_PhysicsShapeEdgeSegment_create$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsShapeEdgeSegment::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsShapeEdgeSegment_getPointA(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShapeEdgeSegment *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsShapeEdgeSegment");

    // cocos2d::Vec2 getPointA()
    cocos2d::Vec2 ret = self->getPointA();
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeEdgeSegment_getPointB(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShapeEdgeSegment *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsShapeEdgeSegment");

    // cocos2d::Vec2 getPointB()
    cocos2d::Vec2 ret = self->getPointB();
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsShapeEdgeSegment(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsShapeEdgeSegment, cocos2d::PhysicsShape>(L, "cc.PhysicsShapeEdgeSegment");
    oluacls_func(L, "create", _cocos2d_PhysicsShapeEdgeSegment_create);
    oluacls_func(L, "getPointA", _cocos2d_PhysicsShapeEdgeSegment_getPointA);
    oluacls_func(L, "getPointB", _cocos2d_PhysicsShapeEdgeSegment_getPointB);
    oluacls_prop(L, "pointA", _cocos2d_PhysicsShapeEdgeSegment_getPointA, nullptr);
    oluacls_prop(L, "pointB", _cocos2d_PhysicsShapeEdgeSegment_getPointB, nullptr);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsRayCastInfo___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_postgc<cocos2d::PhysicsRayCastInfo>(L, 1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsRayCastInfo___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsRayCastInfo *)olua_toobj(L, 1, "cc.PhysicsRayCastInfo");
    olua_push_object(L, self, "cc.PhysicsRayCastInfo");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsRayCastInfo_get_contact(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsRayCastInfo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsRayCastInfo");

    // cocos2d::Vec2 contact
    cocos2d::Vec2 &ret = self->contact;
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsRayCastInfo_set_contact(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsRayCastInfo *self = nullptr;
    cocos2d::Vec2 arg1;       /** contact */

    olua_to_object(L, 1, &self, "cc.PhysicsRayCastInfo");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // cocos2d::Vec2 contact
    self->contact = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsRayCastInfo_get_data(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsRayCastInfo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsRayCastInfo");

    // void *data
    void *ret = self->data;
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsRayCastInfo_set_data(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsRayCastInfo *self = nullptr;
    void *arg1 = nullptr;       /** data */

    olua_to_object(L, 1, &self, "cc.PhysicsRayCastInfo");
    olua_check_object(L, 2, &arg1, "void *");

    // void *data
    self->data = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsRayCastInfo_get_end(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsRayCastInfo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsRayCastInfo");

    // cocos2d::Vec2 end
    cocos2d::Vec2 &ret = self->end;
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsRayCastInfo_set_end(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsRayCastInfo *self = nullptr;
    cocos2d::Vec2 arg1;       /** end */

    olua_to_object(L, 1, &self, "cc.PhysicsRayCastInfo");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // cocos2d::Vec2 end
    self->end = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsRayCastInfo_get_fraction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsRayCastInfo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsRayCastInfo");

    // float fraction
    float ret = self->fraction;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsRayCastInfo_set_fraction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsRayCastInfo *self = nullptr;
    float arg1 = 0;       /** fraction */

    olua_to_object(L, 1, &self, "cc.PhysicsRayCastInfo");
    olua_check_number(L, 2, &arg1);

    // float fraction
    self->fraction = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsRayCastInfo_get_normal(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsRayCastInfo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsRayCastInfo");

    // cocos2d::Vec2 normal
    cocos2d::Vec2 &ret = self->normal;
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsRayCastInfo_set_normal(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsRayCastInfo *self = nullptr;
    cocos2d::Vec2 arg1;       /** normal */

    olua_to_object(L, 1, &self, "cc.PhysicsRayCastInfo");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // cocos2d::Vec2 normal
    self->normal = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsRayCastInfo_get_shape(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsRayCastInfo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsRayCastInfo");

    // cocos2d::PhysicsShape *shape
    cocos2d::PhysicsShape *ret = self->shape;
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShape");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsRayCastInfo_set_shape(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsRayCastInfo *self = nullptr;
    cocos2d::PhysicsShape *arg1 = nullptr;       /** shape */

    olua_to_object(L, 1, &self, "cc.PhysicsRayCastInfo");
    olua_check_object(L, 2, &arg1, "cc.PhysicsShape");

    // cocos2d::PhysicsShape *shape
    self->shape = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsRayCastInfo_get_start(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsRayCastInfo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsRayCastInfo");

    // cocos2d::Vec2 start
    cocos2d::Vec2 &ret = self->start;
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsRayCastInfo_set_start(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsRayCastInfo *self = nullptr;
    cocos2d::Vec2 arg1;       /** start */

    olua_to_object(L, 1, &self, "cc.PhysicsRayCastInfo");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // cocos2d::Vec2 start
    self->start = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsRayCastInfo(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsRayCastInfo>(L, "cc.PhysicsRayCastInfo");
    oluacls_func(L, "__gc", _cocos2d_PhysicsRayCastInfo___gc);
    oluacls_func(L, "__olua_move", _cocos2d_PhysicsRayCastInfo___olua_move);
    oluacls_prop(L, "contact", _cocos2d_PhysicsRayCastInfo_get_contact, _cocos2d_PhysicsRayCastInfo_set_contact);
    oluacls_prop(L, "data", _cocos2d_PhysicsRayCastInfo_get_data, _cocos2d_PhysicsRayCastInfo_set_data);
    oluacls_prop(L, "end", _cocos2d_PhysicsRayCastInfo_get_end, _cocos2d_PhysicsRayCastInfo_set_end);
    oluacls_prop(L, "fraction", _cocos2d_PhysicsRayCastInfo_get_fraction, _cocos2d_PhysicsRayCastInfo_set_fraction);
    oluacls_prop(L, "normal", _cocos2d_PhysicsRayCastInfo_get_normal, _cocos2d_PhysicsRayCastInfo_set_normal);
    oluacls_prop(L, "shape", _cocos2d_PhysicsRayCastInfo_get_shape, _cocos2d_PhysicsRayCastInfo_set_shape);
    oluacls_prop(L, "start", _cocos2d_PhysicsRayCastInfo_get_start, _cocos2d_PhysicsRayCastInfo_set_start);

    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_PHYSICS
static int _cocos2d_PhysicsWorld___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsWorld *)olua_toobj(L, 1, "cc.PhysicsWorld");
    olua_push_object(L, self, "cc.PhysicsWorld");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsWorld_addJoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    cocos2d::PhysicsJoint *arg1 = nullptr;       /** joint */

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");
    olua_check_object(L, 2, &arg1, "cc.PhysicsJoint");

    // void addJoint(cocos2d::PhysicsJoint *joint)
    self->addJoint(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_getAllBodies(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");

    // const cocos2d::Vector<cocos2d::PhysicsBody *> &getAllBodies()
    const cocos2d::Vector<cocos2d::PhysicsBody *> &ret = self->getAllBodies();
    int num_ret = olua_push_vector<cocos2d::PhysicsBody *>(L, ret, [L](cocos2d::PhysicsBody *arg1) {
        olua_push_object(L, arg1, "cc.PhysicsBody");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsWorld_getBody(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    int arg1 = 0;       /** tag */

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");
    olua_check_integer(L, 2, &arg1);

    // cocos2d::PhysicsBody *getBody(int tag)
    cocos2d::PhysicsBody *ret = self->getBody(arg1);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsWorld_getDebugDrawMask(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");

    // int getDebugDrawMask()
    int ret = self->getDebugDrawMask();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsWorld_getFixedUpdateRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");

    // int getFixedUpdateRate()
    int ret = self->getFixedUpdateRate();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsWorld_getGravity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");

    // cocos2d::Vec2 getGravity()
    cocos2d::Vec2 ret = self->getGravity();
    int num_ret = olua_pushcopy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsWorld_getScene(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");

    // cocos2d::Scene &getScene()
    cocos2d::Scene &ret = self->getScene();
    int num_ret = olua_push_object(L, &ret, "cc.Scene");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsWorld_getShape(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    cocos2d::Vec2 arg1;       /** point */

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // cocos2d::PhysicsShape *getShape(const cocos2d::Vec2 &point)
    cocos2d::PhysicsShape *ret = self->getShape(arg1);
    int num_ret = olua_push_object(L, ret, "cc.PhysicsShape");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsWorld_getShapes(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    cocos2d::Vec2 arg1;       /** point */

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // cocos2d::Vector<cocos2d::PhysicsShape *> getShapes(const cocos2d::Vec2 &point)
    cocos2d::Vector<cocos2d::PhysicsShape *> ret = self->getShapes(arg1);
    int num_ret = olua_push_vector<cocos2d::PhysicsShape *>(L, ret, [L](cocos2d::PhysicsShape *arg1) {
        olua_push_object(L, arg1, "cc.PhysicsShape");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsWorld_getSpeed(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");

    // float getSpeed()
    float ret = self->getSpeed();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsWorld_getSubsteps(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");

    // int getSubsteps()
    int ret = self->getSubsteps();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsWorld_getUpdateRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");

    // int getUpdateRate()
    int ret = self->getUpdateRate();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsWorld_isAutoStep(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");

    // bool isAutoStep()
    bool ret = self->isAutoStep();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsWorld_queryPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    cocos2d::PhysicsQueryPointCallbackFunc arg1;       /** func */
    cocos2d::Vec2 arg2;       /** point */
    void *arg3 = nullptr;       /** data */

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");
    olua_check_callback(L, 2, &arg1, "cc.PhysicsQueryPointCallbackFunc");
    olua_check_object(L, 3, &arg2, "cc.Vec2");
    olua_check_object(L, 4, &arg3, "void *");

    void *cb_store = (void *)self;
    std::string cb_tag = "queryPoint";
    std::string cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](cocos2d::PhysicsWorld &arg1, cocos2d::PhysicsShape &arg2, void *arg3) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();
        bool ret = false;       /** ret */
        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_object(L, &arg1, "cc.PhysicsWorld");
            olua_push_object(L, &arg2, "cc.PhysicsShape");
            olua_push_object(L, arg3, "void *");
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 3);

            if (olua_is_bool(L, -1)) {
                olua_check_bool(L, -1, &ret);
            }

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
        return ret;
    };

    // void queryPoint(@localvar cocos2d::PhysicsQueryPointCallbackFunc func, const cocos2d::Vec2 &point, void *data)
    self->queryPoint(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_queryRect(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    cocos2d::PhysicsQueryRectCallbackFunc arg1;       /** func */
    cocos2d::Rect arg2;       /** rect */
    void *arg3 = nullptr;       /** data */

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");
    olua_check_callback(L, 2, &arg1, "cc.PhysicsQueryRectCallbackFunc");
    olua_check_object(L, 3, &arg2, "cc.Rect");
    olua_check_object(L, 4, &arg3, "void *");

    void *cb_store = (void *)self;
    std::string cb_tag = "queryRect";
    std::string cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](cocos2d::PhysicsWorld &arg1, cocos2d::PhysicsShape &arg2, void *arg3) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();
        bool ret = false;       /** ret */
        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_object(L, &arg1, "cc.PhysicsWorld");
            olua_push_object(L, &arg2, "cc.PhysicsShape");
            olua_push_object(L, arg3, "void *");
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 3);

            if (olua_is_bool(L, -1)) {
                olua_check_bool(L, -1, &ret);
            }

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
        return ret;
    };

    // void queryRect(@localvar cocos2d::PhysicsQueryRectCallbackFunc func, const cocos2d::Rect &rect, void *data)
    self->queryRect(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_rayCast(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    cocos2d::PhysicsRayCastCallbackFunc arg1;       /** func */
    cocos2d::Vec2 arg2;       /** start */
    cocos2d::Vec2 arg3;       /** end */
    void *arg4 = nullptr;       /** data */

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");
    olua_check_callback(L, 2, &arg1, "cc.PhysicsRayCastCallbackFunc");
    olua_check_object(L, 3, &arg2, "cc.Vec2");
    olua_check_object(L, 4, &arg3, "cc.Vec2");
    olua_check_object(L, 5, &arg4, "void *");

    void *cb_store = (void *)self;
    std::string cb_tag = "rayCast";
    std::string cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](cocos2d::PhysicsWorld &arg1, const cocos2d::PhysicsRayCastInfo &arg2, void *arg3) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();
        bool ret = false;       /** ret */
        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_object(L, &arg1, "cc.PhysicsWorld");
            olua_push_object(L, arg2, "cc.PhysicsRayCastInfo");
            olua_push_object(L, arg3, "void *");
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 3);

            if (olua_is_bool(L, -1)) {
                olua_check_bool(L, -1, &ret);
            }

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
        return ret;
    };

    // void rayCast(@localvar cocos2d::PhysicsRayCastCallbackFunc func, const cocos2d::Vec2 &start, const cocos2d::Vec2 &end, void *data)
    self->rayCast(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_removeAllBodies(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");

    // void removeAllBodies()
    self->removeAllBodies();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_removeAllJoints$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    bool arg1 = false;       /** destroy */

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");
    olua_check_bool(L, 2, &arg1);

    // void removeAllJoints(@optional bool destroy)
    self->removeAllJoints(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_removeAllJoints$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");

    // void removeAllJoints(@optional bool destroy)
    self->removeAllJoints();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_removeAllJoints(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // void removeAllJoints(@optional bool destroy)
        return _cocos2d_PhysicsWorld_removeAllJoints$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_bool(L, 2))) {
            // void removeAllJoints(@optional bool destroy)
            return _cocos2d_PhysicsWorld_removeAllJoints$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsWorld::removeAllJoints' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsWorld_removeBody$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    cocos2d::PhysicsBody *arg1 = nullptr;       /** body */

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");
    olua_check_object(L, 2, &arg1, "cc.PhysicsBody");

    // void removeBody(cocos2d::PhysicsBody *body)
    self->removeBody(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_removeBody$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    int arg1 = 0;       /** tag */

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");
    olua_check_integer(L, 2, &arg1);

    // void removeBody(int tag)
    self->removeBody(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_removeBody(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        if ((olua_is_object(L, 2, "cc.PhysicsBody"))) {
            // void removeBody(cocos2d::PhysicsBody *body)
            return _cocos2d_PhysicsWorld_removeBody$1(L);
        }

        // if ((olua_is_integer(L, 2))) {
            // void removeBody(int tag)
            return _cocos2d_PhysicsWorld_removeBody$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsWorld::removeBody' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsWorld_removeJoint$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    cocos2d::PhysicsJoint *arg1 = nullptr;       /** joint */
    bool arg2 = false;       /** destroy */

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");
    olua_check_object(L, 2, &arg1, "cc.PhysicsJoint");
    olua_check_bool(L, 3, &arg2);

    // void removeJoint(cocos2d::PhysicsJoint *joint, @optional bool destroy)
    self->removeJoint(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_removeJoint$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    cocos2d::PhysicsJoint *arg1 = nullptr;       /** joint */

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");
    olua_check_object(L, 2, &arg1, "cc.PhysicsJoint");

    // void removeJoint(cocos2d::PhysicsJoint *joint, @optional bool destroy)
    self->removeJoint(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_removeJoint(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_object(L, 2, "cc.PhysicsJoint"))) {
            // void removeJoint(cocos2d::PhysicsJoint *joint, @optional bool destroy)
            return _cocos2d_PhysicsWorld_removeJoint$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 2, "cc.PhysicsJoint")) && (olua_is_bool(L, 3))) {
            // void removeJoint(cocos2d::PhysicsJoint *joint, @optional bool destroy)
            return _cocos2d_PhysicsWorld_removeJoint$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsWorld::removeJoint' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsWorld_setAutoStep(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    bool arg1 = false;       /** autoStep */

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");
    olua_check_bool(L, 2, &arg1);

    // void setAutoStep(bool autoStep)
    self->setAutoStep(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_setDebugDrawMask(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    int arg1 = 0;       /** mask */

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");
    olua_check_integer(L, 2, &arg1);

    // void setDebugDrawMask(int mask)
    self->setDebugDrawMask(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_setFixedUpdateRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    int arg1 = 0;       /** updatesPerSecond */

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");
    olua_check_integer(L, 2, &arg1);

    // void setFixedUpdateRate(int updatesPerSecond)
    self->setFixedUpdateRate(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_setGravity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    cocos2d::Vec2 arg1;       /** gravity */

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void setGravity(const cocos2d::Vec2 &gravity)
    self->setGravity(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_setPostUpdateCallback(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    std::function<void ()> arg1;       /** callback */

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "PostUpdateCallback";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
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
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);
        arg1 = nullptr;
    }

    // void setPostUpdateCallback(@localvar @nullable const std::function<void ()> &callback)
    self->setPostUpdateCallback(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_setPreUpdateCallback(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    std::function<void ()> arg1;       /** callback */

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "PreUpdateCallback";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
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
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);
        arg1 = nullptr;
    }

    // void setPreUpdateCallback(@localvar @nullable const std::function<void ()> &callback)
    self->setPreUpdateCallback(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_setSpeed(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    float arg1 = 0;       /** speed */

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");
    olua_check_number(L, 2, &arg1);

    // void setSpeed(float speed)
    self->setSpeed(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_setSubsteps(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    int arg1 = 0;       /** steps */

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");
    olua_check_integer(L, 2, &arg1);

    // void setSubsteps(int steps)
    self->setSubsteps(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_setUpdateRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    int arg1 = 0;       /** rate */

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");
    olua_check_integer(L, 2, &arg1);

    // void setUpdateRate(int rate)
    self->setUpdateRate(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_step(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    float arg1 = 0;       /** delta */

    olua_to_object(L, 1, &self, "cc.PhysicsWorld");
    olua_check_number(L, 2, &arg1);

    // void step(float delta)
    self->step(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_PhysicsWorld(lua_State *L)
{
    oluacls_class<cocos2d::PhysicsWorld>(L, "cc.PhysicsWorld");
    oluacls_func(L, "__olua_move", _cocos2d_PhysicsWorld___olua_move);
    oluacls_func(L, "addJoint", _cocos2d_PhysicsWorld_addJoint);
    oluacls_func(L, "getAllBodies", _cocos2d_PhysicsWorld_getAllBodies);
    oluacls_func(L, "getBody", _cocos2d_PhysicsWorld_getBody);
    oluacls_func(L, "getDebugDrawMask", _cocos2d_PhysicsWorld_getDebugDrawMask);
    oluacls_func(L, "getFixedUpdateRate", _cocos2d_PhysicsWorld_getFixedUpdateRate);
    oluacls_func(L, "getGravity", _cocos2d_PhysicsWorld_getGravity);
    oluacls_func(L, "getScene", _cocos2d_PhysicsWorld_getScene);
    oluacls_func(L, "getShape", _cocos2d_PhysicsWorld_getShape);
    oluacls_func(L, "getShapes", _cocos2d_PhysicsWorld_getShapes);
    oluacls_func(L, "getSpeed", _cocos2d_PhysicsWorld_getSpeed);
    oluacls_func(L, "getSubsteps", _cocos2d_PhysicsWorld_getSubsteps);
    oluacls_func(L, "getUpdateRate", _cocos2d_PhysicsWorld_getUpdateRate);
    oluacls_func(L, "isAutoStep", _cocos2d_PhysicsWorld_isAutoStep);
    oluacls_func(L, "queryPoint", _cocos2d_PhysicsWorld_queryPoint);
    oluacls_func(L, "queryRect", _cocos2d_PhysicsWorld_queryRect);
    oluacls_func(L, "rayCast", _cocos2d_PhysicsWorld_rayCast);
    oluacls_func(L, "removeAllBodies", _cocos2d_PhysicsWorld_removeAllBodies);
    oluacls_func(L, "removeAllJoints", _cocos2d_PhysicsWorld_removeAllJoints);
    oluacls_func(L, "removeBody", _cocos2d_PhysicsWorld_removeBody);
    oluacls_func(L, "removeJoint", _cocos2d_PhysicsWorld_removeJoint);
    oluacls_func(L, "setAutoStep", _cocos2d_PhysicsWorld_setAutoStep);
    oluacls_func(L, "setDebugDrawMask", _cocos2d_PhysicsWorld_setDebugDrawMask);
    oluacls_func(L, "setFixedUpdateRate", _cocos2d_PhysicsWorld_setFixedUpdateRate);
    oluacls_func(L, "setGravity", _cocos2d_PhysicsWorld_setGravity);
    oluacls_func(L, "setPostUpdateCallback", _cocos2d_PhysicsWorld_setPostUpdateCallback);
    oluacls_func(L, "setPreUpdateCallback", _cocos2d_PhysicsWorld_setPreUpdateCallback);
    oluacls_func(L, "setSpeed", _cocos2d_PhysicsWorld_setSpeed);
    oluacls_func(L, "setSubsteps", _cocos2d_PhysicsWorld_setSubsteps);
    oluacls_func(L, "setUpdateRate", _cocos2d_PhysicsWorld_setUpdateRate);
    oluacls_func(L, "step", _cocos2d_PhysicsWorld_step);
    oluacls_prop(L, "allBodies", _cocos2d_PhysicsWorld_getAllBodies, nullptr);
    oluacls_prop(L, "autoStep", _cocos2d_PhysicsWorld_isAutoStep, _cocos2d_PhysicsWorld_setAutoStep);
    oluacls_prop(L, "debugDrawMask", _cocos2d_PhysicsWorld_getDebugDrawMask, _cocos2d_PhysicsWorld_setDebugDrawMask);
    oluacls_prop(L, "fixedUpdateRate", _cocos2d_PhysicsWorld_getFixedUpdateRate, _cocos2d_PhysicsWorld_setFixedUpdateRate);
    oluacls_prop(L, "gravity", _cocos2d_PhysicsWorld_getGravity, _cocos2d_PhysicsWorld_setGravity);
    oluacls_prop(L, "scene", _cocos2d_PhysicsWorld_getScene, nullptr);
    oluacls_prop(L, "speed", _cocos2d_PhysicsWorld_getSpeed, _cocos2d_PhysicsWorld_setSpeed);
    oluacls_prop(L, "substeps", _cocos2d_PhysicsWorld_getSubsteps, _cocos2d_PhysicsWorld_setSubsteps);
    oluacls_prop(L, "updateRate", _cocos2d_PhysicsWorld_getUpdateRate, _cocos2d_PhysicsWorld_setUpdateRate);
    oluacls_const(L, "DEBUGDRAW_ALL", cocos2d::PhysicsWorld::DEBUGDRAW_ALL);
    oluacls_const(L, "DEBUGDRAW_CONTACT", cocos2d::PhysicsWorld::DEBUGDRAW_CONTACT);
    oluacls_const(L, "DEBUGDRAW_JOINT", cocos2d::PhysicsWorld::DEBUGDRAW_JOINT);
    oluacls_const(L, "DEBUGDRAW_NONE", cocos2d::PhysicsWorld::DEBUGDRAW_NONE);
    oluacls_const(L, "DEBUGDRAW_SHAPE", cocos2d::PhysicsWorld::DEBUGDRAW_SHAPE);

    return 1;
}
OLUA_END_DECLS
#endif

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_physics(lua_State *L)
{
#if CC_USE_PHYSICS
    olua_require(L, "cc.PhysicsMaterial", luaopen_cocos2d_PhysicsMaterial);
    olua_require(L, "cc.PhysicsRayCastCallbackFunc", luaopen_cocos2d_PhysicsRayCastCallbackFunc);
    olua_require(L, "cc.PhysicsQueryRectCallbackFunc", luaopen_cocos2d_PhysicsQueryRectCallbackFunc);
    olua_require(L, "cc.PhysicsQueryPointCallbackFunc", luaopen_cocos2d_PhysicsQueryPointCallbackFunc);
    olua_require(L, "cc.EventListenerPhysicsContact", luaopen_cocos2d_EventListenerPhysicsContact);
    olua_require(L, "cc.EventListenerPhysicsContactWithGroup", luaopen_cocos2d_EventListenerPhysicsContactWithGroup);
    olua_require(L, "cc.EventListenerPhysicsContactWithBodies", luaopen_cocos2d_EventListenerPhysicsContactWithBodies);
    olua_require(L, "cc.EventListenerPhysicsContactWithShapes", luaopen_cocos2d_EventListenerPhysicsContactWithShapes);
    olua_require(L, "cc.PhysicsBody", luaopen_cocos2d_PhysicsBody);
    olua_require(L, "cc.PhysicsContact.EventCode", luaopen_cocos2d_PhysicsContact_EventCode);
    olua_require(L, "cc.PhysicsContact", luaopen_cocos2d_PhysicsContact);
    olua_require(L, "cc.PhysicsContactPostSolve", luaopen_cocos2d_PhysicsContactPostSolve);
    olua_require(L, "cc.PhysicsContactPreSolve", luaopen_cocos2d_PhysicsContactPreSolve);
    olua_require(L, "cc.PhysicsJoint", luaopen_cocos2d_PhysicsJoint);
    olua_require(L, "cc.PhysicsJointDistance", luaopen_cocos2d_PhysicsJointDistance);
    olua_require(L, "cc.PhysicsJointFixed", luaopen_cocos2d_PhysicsJointFixed);
    olua_require(L, "cc.PhysicsJointGear", luaopen_cocos2d_PhysicsJointGear);
    olua_require(L, "cc.PhysicsJointGroove", luaopen_cocos2d_PhysicsJointGroove);
    olua_require(L, "cc.PhysicsJointLimit", luaopen_cocos2d_PhysicsJointLimit);
    olua_require(L, "cc.PhysicsJointMotor", luaopen_cocos2d_PhysicsJointMotor);
    olua_require(L, "cc.PhysicsJointPin", luaopen_cocos2d_PhysicsJointPin);
    olua_require(L, "cc.PhysicsJointRatchet", luaopen_cocos2d_PhysicsJointRatchet);
    olua_require(L, "cc.PhysicsJointRotaryLimit", luaopen_cocos2d_PhysicsJointRotaryLimit);
    olua_require(L, "cc.PhysicsJointRotarySpring", luaopen_cocos2d_PhysicsJointRotarySpring);
    olua_require(L, "cc.PhysicsJointSpring", luaopen_cocos2d_PhysicsJointSpring);
    olua_require(L, "cc.PhysicsShape.Type", luaopen_cocos2d_PhysicsShape_Type);
    olua_require(L, "cc.PhysicsShape", luaopen_cocos2d_PhysicsShape);
    olua_require(L, "cc.PhysicsShapePolygon", luaopen_cocos2d_PhysicsShapePolygon);
    olua_require(L, "cc.PhysicsShapeEdgePolygon", luaopen_cocos2d_PhysicsShapeEdgePolygon);
    olua_require(L, "cc.PhysicsShapeBox", luaopen_cocos2d_PhysicsShapeBox);
    olua_require(L, "cc.PhysicsShapeCircle", luaopen_cocos2d_PhysicsShapeCircle);
    olua_require(L, "cc.PhysicsShapeEdgeBox", luaopen_cocos2d_PhysicsShapeEdgeBox);
    olua_require(L, "cc.PhysicsShapeEdgeChain", luaopen_cocos2d_PhysicsShapeEdgeChain);
    olua_require(L, "cc.PhysicsShapeEdgeSegment", luaopen_cocos2d_PhysicsShapeEdgeSegment);
    olua_require(L, "cc.PhysicsRayCastInfo", luaopen_cocos2d_PhysicsRayCastInfo);
    olua_require(L, "cc.PhysicsWorld", luaopen_cocos2d_PhysicsWorld);
#endif

    cclua::runtime::registerFeature("physics", true);

    return 0;
}
OLUA_END_DECLS
