//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_cocos2d_physics.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "lua-bindings/LuaCocosAdapter.h"
#include "xgame/xlua.h"
#include "cocos2d.h"

using namespace cocos2d;

int auto_olua_push_cocos2d_PhysicsMaterial(lua_State *L, const cocos2d::PhysicsMaterial *value)
{
    if (value) {
        lua_createtable(L, 0, 3);

        olua_push_number(L, (lua_Number)value->density);
        olua_setfield(L, -2, "density");

        olua_push_number(L, (lua_Number)value->restitution);
        olua_setfield(L, -2, "restitution");

        olua_push_number(L, (lua_Number)value->friction);
        olua_setfield(L, -2, "friction");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_cocos2d_PhysicsMaterial(lua_State *L, int idx, cocos2d::PhysicsMaterial *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    lua_Number arg1 = 0;       /** density */
    lua_Number arg2 = 0;       /** restitution */
    lua_Number arg3 = 0;       /** friction */

    olua_getfield(L, idx, "density");
    olua_check_number(L, -1, &arg1);
    value->density = (float)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "restitution");
    olua_check_number(L, -1, &arg2);
    value->restitution = (float)arg2;
    lua_pop(L, 1);

    olua_getfield(L, idx, "friction");
    olua_check_number(L, -1, &arg3);
    value->friction = (float)arg3;
    lua_pop(L, 1);
}

bool auto_olua_is_cocos2d_PhysicsMaterial(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "friction") && olua_hasfield(L, idx, "restitution") && olua_hasfield(L, idx, "density");
}

void auto_olua_pack_cocos2d_PhysicsMaterial(lua_State *L, int idx, cocos2d::PhysicsMaterial *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    lua_Number arg1 = 0;       /** density */
    lua_Number arg2 = 0;       /** restitution */
    lua_Number arg3 = 0;       /** friction */

    olua_check_number(L, idx + 0, &arg1);
    value->density = (float)arg1;

    olua_check_number(L, idx + 1, &arg2);
    value->restitution = (float)arg2;

    olua_check_number(L, idx + 2, &arg3);
    value->friction = (float)arg3;
}

int auto_olua_unpack_cocos2d_PhysicsMaterial(lua_State *L, const cocos2d::PhysicsMaterial *value)
{
    if (value) {
        olua_push_number(L, (lua_Number)value->density);
        olua_push_number(L, (lua_Number)value->restitution);
        olua_push_number(L, (lua_Number)value->friction);
    } else {
        for (int i = 0; i < 3; i++) {
            lua_pushnil(L);
        }
    }

    return 3;
}

bool auto_olua_ispack_cocos2d_PhysicsMaterial(lua_State *L, int idx)
{
    return olua_is_number(L, idx + 0) && olua_is_number(L, idx + 1) && olua_is_number(L, idx + 2);
}

static int _cocos2d_EventListenerPhysicsContact___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EventListenerPhysicsContact *)olua_toobj(L, 1, "cc.EventListenerPhysicsContact");
    olua_push_cppobj(L, self, "cc.EventListenerPhysicsContact");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EventListenerPhysicsContact_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::EventListenerPhysicsContact *create()
    cocos2d::EventListenerPhysicsContact *ret = cocos2d::EventListenerPhysicsContact::create();
    int num_ret = olua_push_cppobj(L, ret, "cc.EventListenerPhysicsContact");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EventListenerPhysicsContact_get_onContactBegin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EventListenerPhysicsContact *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.EventListenerPhysicsContact");

    void *cb_store = (void *)self;
    std::string cb_tag = "onContactBegin";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);

    // @nullable @local std::function<bool (PhysicsContact &)> onContactBegin
    std::function<bool(cocos2d::PhysicsContact &)> ret = self->onContactBegin;
    int num_ret = olua_push_std_function(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EventListenerPhysicsContact_set_onContactBegin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EventListenerPhysicsContact *self = nullptr;
    std::function<bool(cocos2d::PhysicsContact &)> arg1;       /** onContactBegin */

    olua_to_cppobj(L, 1, (void **)&self, "cc.EventListenerPhysicsContact");

    void *cb_store = (void *)self;
    std::string cb_tag = "onContactBegin";
    std::string cb_name;
    if (olua_is_std_function(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, cb_tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_Integer cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](cocos2d::PhysicsContact &arg1) {
            lua_State *L = olua_mainthread(NULL);
            bool ret = false;       
            if (L != NULL && olua_context(L) == cb_ctx) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_cppobj(L, &arg1, "cc.PhysicsContact");
                olua_disable_objpool(L);

                olua_callback(L, cb_store, cb_name.c_str(), 1);

                if (olua_is_bool(L, -1)) {
                    olua_check_bool(L, -1, &ret);
                }

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
            return (bool)ret;
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // @nullable @local std::function<bool (PhysicsContact &)> onContactBegin
    self->onContactBegin = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_EventListenerPhysicsContact_get_onContactPostSolve(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EventListenerPhysicsContact *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.EventListenerPhysicsContact");

    void *cb_store = (void *)self;
    std::string cb_tag = "onContactPostSolve";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);

    // @nullable @local std::function<void (PhysicsContact &, const PhysicsContactPostSolve &)> onContactPostSolve
    std::function<void(cocos2d::PhysicsContact &, const cocos2d::PhysicsContactPostSolve &)> ret = self->onContactPostSolve;
    int num_ret = olua_push_std_function(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EventListenerPhysicsContact_set_onContactPostSolve(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EventListenerPhysicsContact *self = nullptr;
    std::function<void(cocos2d::PhysicsContact &, const cocos2d::PhysicsContactPostSolve &)> arg1;       /** onContactPostSolve */

    olua_to_cppobj(L, 1, (void **)&self, "cc.EventListenerPhysicsContact");

    void *cb_store = (void *)self;
    std::string cb_tag = "onContactPostSolve";
    std::string cb_name;
    if (olua_is_std_function(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, cb_tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_Integer cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](cocos2d::PhysicsContact &arg1, const cocos2d::PhysicsContactPostSolve &arg2) {
            lua_State *L = olua_mainthread(NULL);

            if (L != NULL && olua_context(L) == cb_ctx) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_cppobj(L, &arg1, "cc.PhysicsContact");
                olua_push_cppobj(L, &arg2, "cc.PhysicsContactPostSolve");
                olua_disable_objpool(L);

                olua_callback(L, cb_store, cb_name.c_str(), 2);

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // @nullable @local std::function<void (PhysicsContact &, const PhysicsContactPostSolve &)> onContactPostSolve
    self->onContactPostSolve = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_EventListenerPhysicsContact_get_onContactPreSolve(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EventListenerPhysicsContact *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.EventListenerPhysicsContact");

    void *cb_store = (void *)self;
    std::string cb_tag = "onContactPreSolve";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);

    // @nullable @local std::function<bool (PhysicsContact &, PhysicsContactPreSolve &)> onContactPreSolve
    std::function<bool(cocos2d::PhysicsContact &, cocos2d::PhysicsContactPreSolve &)> ret = self->onContactPreSolve;
    int num_ret = olua_push_std_function(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EventListenerPhysicsContact_set_onContactPreSolve(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EventListenerPhysicsContact *self = nullptr;
    std::function<bool(cocos2d::PhysicsContact &, cocos2d::PhysicsContactPreSolve &)> arg1;       /** onContactPreSolve */

    olua_to_cppobj(L, 1, (void **)&self, "cc.EventListenerPhysicsContact");

    void *cb_store = (void *)self;
    std::string cb_tag = "onContactPreSolve";
    std::string cb_name;
    if (olua_is_std_function(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, cb_tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_Integer cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](cocos2d::PhysicsContact &arg1, cocos2d::PhysicsContactPreSolve &arg2) {
            lua_State *L = olua_mainthread(NULL);
            bool ret = false;       
            if (L != NULL && olua_context(L) == cb_ctx) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_cppobj(L, &arg1, "cc.PhysicsContact");
                olua_push_cppobj(L, &arg2, "cc.PhysicsContactPreSolve");
                olua_disable_objpool(L);

                olua_callback(L, cb_store, cb_name.c_str(), 2);

                if (olua_is_bool(L, -1)) {
                    olua_check_bool(L, -1, &ret);
                }

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
            return (bool)ret;
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // @nullable @local std::function<bool (PhysicsContact &, PhysicsContactPreSolve &)> onContactPreSolve
    self->onContactPreSolve = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_EventListenerPhysicsContact_get_onContactSeparate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EventListenerPhysicsContact *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.EventListenerPhysicsContact");

    void *cb_store = (void *)self;
    std::string cb_tag = "onContactSeparate";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);

    // @nullable @local std::function<void (PhysicsContact &)> onContactSeparate
    std::function<void(cocos2d::PhysicsContact &)> ret = self->onContactSeparate;
    int num_ret = olua_push_std_function(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EventListenerPhysicsContact_set_onContactSeparate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EventListenerPhysicsContact *self = nullptr;
    std::function<void(cocos2d::PhysicsContact &)> arg1;       /** onContactSeparate */

    olua_to_cppobj(L, 1, (void **)&self, "cc.EventListenerPhysicsContact");

    void *cb_store = (void *)self;
    std::string cb_tag = "onContactSeparate";
    std::string cb_name;
    if (olua_is_std_function(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, cb_tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_Integer cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](cocos2d::PhysicsContact &arg1) {
            lua_State *L = olua_mainthread(NULL);

            if (L != NULL && olua_context(L) == cb_ctx) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_cppobj(L, &arg1, "cc.PhysicsContact");
                olua_disable_objpool(L);

                olua_callback(L, cb_store, cb_name.c_str(), 1);

                //pop stack value
                olua_pop_objpool(L, last);
                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // @nullable @local std::function<void (PhysicsContact &)> onContactSeparate
    self->onContactSeparate = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_EventListenerPhysicsContact(lua_State *L)
{
    oluacls_class(L, "cc.EventListenerPhysicsContact", "cc.EventListenerCustom");
    oluacls_func(L, "__move", _cocos2d_EventListenerPhysicsContact___move);
    oluacls_func(L, "create", _cocos2d_EventListenerPhysicsContact_create);
    oluacls_prop(L, "onContactBegin", _cocos2d_EventListenerPhysicsContact_get_onContactBegin, _cocos2d_EventListenerPhysicsContact_set_onContactBegin);
    oluacls_prop(L, "onContactPostSolve", _cocos2d_EventListenerPhysicsContact_get_onContactPostSolve, _cocos2d_EventListenerPhysicsContact_set_onContactPostSolve);
    oluacls_prop(L, "onContactPreSolve", _cocos2d_EventListenerPhysicsContact_get_onContactPreSolve, _cocos2d_EventListenerPhysicsContact_set_onContactPreSolve);
    oluacls_prop(L, "onContactSeparate", _cocos2d_EventListenerPhysicsContact_get_onContactSeparate, _cocos2d_EventListenerPhysicsContact_set_onContactSeparate);

    olua_registerluatype<cocos2d::EventListenerPhysicsContact>(L, "cc.EventListenerPhysicsContact");

    return 1;
}

static int _cocos2d_EventListenerPhysicsContactWithGroup___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EventListenerPhysicsContactWithGroup *)olua_toobj(L, 1, "cc.EventListenerPhysicsContactWithGroup");
    olua_push_cppobj(L, self, "cc.EventListenerPhysicsContactWithGroup");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EventListenerPhysicsContactWithGroup_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** group */

    olua_check_int(L, 1, &arg1);

    // static cocos2d::EventListenerPhysicsContactWithGroup *create(int group)
    cocos2d::EventListenerPhysicsContactWithGroup *ret = cocos2d::EventListenerPhysicsContactWithGroup::create((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.EventListenerPhysicsContactWithGroup");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EventListenerPhysicsContactWithGroup_hitTest(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EventListenerPhysicsContactWithGroup *self = nullptr;
    cocos2d::PhysicsShape *arg1 = nullptr;       /** shapeA */
    cocos2d::PhysicsShape *arg2 = nullptr;       /** shapeB */

    olua_to_cppobj(L, 1, (void **)&self, "cc.EventListenerPhysicsContactWithGroup");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.PhysicsShape");
    olua_check_cppobj(L, 3, (void **)&arg2, "cc.PhysicsShape");

    // bool hitTest(cocos2d::PhysicsShape *shapeA, cocos2d::PhysicsShape *shapeB)
    bool ret = self->hitTest(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EventListenerPhysicsContactWithGroup(lua_State *L)
{
    oluacls_class(L, "cc.EventListenerPhysicsContactWithGroup", "cc.EventListenerPhysicsContact");
    oluacls_func(L, "__move", _cocos2d_EventListenerPhysicsContactWithGroup___move);
    oluacls_func(L, "create", _cocos2d_EventListenerPhysicsContactWithGroup_create);
    oluacls_func(L, "hitTest", _cocos2d_EventListenerPhysicsContactWithGroup_hitTest);

    olua_registerluatype<cocos2d::EventListenerPhysicsContactWithGroup>(L, "cc.EventListenerPhysicsContactWithGroup");

    return 1;
}

static int _cocos2d_EventListenerPhysicsContactWithBodies___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EventListenerPhysicsContactWithBodies *)olua_toobj(L, 1, "cc.EventListenerPhysicsContactWithBodies");
    olua_push_cppobj(L, self, "cc.EventListenerPhysicsContactWithBodies");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EventListenerPhysicsContactWithBodies_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** bodyA */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** bodyB */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.PhysicsBody");
    olua_check_cppobj(L, 2, (void **)&arg2, "cc.PhysicsBody");

    // static cocos2d::EventListenerPhysicsContactWithBodies *create(cocos2d::PhysicsBody *bodyA, cocos2d::PhysicsBody *bodyB)
    cocos2d::EventListenerPhysicsContactWithBodies *ret = cocos2d::EventListenerPhysicsContactWithBodies::create(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.EventListenerPhysicsContactWithBodies");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EventListenerPhysicsContactWithBodies_hitTest(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EventListenerPhysicsContactWithBodies *self = nullptr;
    cocos2d::PhysicsShape *arg1 = nullptr;       /** shapeA */
    cocos2d::PhysicsShape *arg2 = nullptr;       /** shapeB */

    olua_to_cppobj(L, 1, (void **)&self, "cc.EventListenerPhysicsContactWithBodies");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.PhysicsShape");
    olua_check_cppobj(L, 3, (void **)&arg2, "cc.PhysicsShape");

    // bool hitTest(cocos2d::PhysicsShape *shapeA, cocos2d::PhysicsShape *shapeB)
    bool ret = self->hitTest(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EventListenerPhysicsContactWithBodies(lua_State *L)
{
    oluacls_class(L, "cc.EventListenerPhysicsContactWithBodies", "cc.EventListenerPhysicsContact");
    oluacls_func(L, "__move", _cocos2d_EventListenerPhysicsContactWithBodies___move);
    oluacls_func(L, "create", _cocos2d_EventListenerPhysicsContactWithBodies_create);
    oluacls_func(L, "hitTest", _cocos2d_EventListenerPhysicsContactWithBodies_hitTest);

    olua_registerluatype<cocos2d::EventListenerPhysicsContactWithBodies>(L, "cc.EventListenerPhysicsContactWithBodies");

    return 1;
}

static int _cocos2d_EventListenerPhysicsContactWithShapes___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::EventListenerPhysicsContactWithShapes *)olua_toobj(L, 1, "cc.EventListenerPhysicsContactWithShapes");
    olua_push_cppobj(L, self, "cc.EventListenerPhysicsContactWithShapes");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_EventListenerPhysicsContactWithShapes_create(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *arg1 = nullptr;       /** shapeA */
    cocos2d::PhysicsShape *arg2 = nullptr;       /** shapeB */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.PhysicsShape");
    olua_check_cppobj(L, 2, (void **)&arg2, "cc.PhysicsShape");

    // static cocos2d::EventListenerPhysicsContactWithShapes *create(cocos2d::PhysicsShape *shapeA, cocos2d::PhysicsShape *shapeB)
    cocos2d::EventListenerPhysicsContactWithShapes *ret = cocos2d::EventListenerPhysicsContactWithShapes::create(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.EventListenerPhysicsContactWithShapes");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_EventListenerPhysicsContactWithShapes_hitTest(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::EventListenerPhysicsContactWithShapes *self = nullptr;
    cocos2d::PhysicsShape *arg1 = nullptr;       /** shapeA */
    cocos2d::PhysicsShape *arg2 = nullptr;       /** shapeB */

    olua_to_cppobj(L, 1, (void **)&self, "cc.EventListenerPhysicsContactWithShapes");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.PhysicsShape");
    olua_check_cppobj(L, 3, (void **)&arg2, "cc.PhysicsShape");

    // bool hitTest(cocos2d::PhysicsShape *shapeA, cocos2d::PhysicsShape *shapeB)
    bool ret = self->hitTest(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_EventListenerPhysicsContactWithShapes(lua_State *L)
{
    oluacls_class(L, "cc.EventListenerPhysicsContactWithShapes", "cc.EventListenerPhysicsContact");
    oluacls_func(L, "__move", _cocos2d_EventListenerPhysicsContactWithShapes___move);
    oluacls_func(L, "create", _cocos2d_EventListenerPhysicsContactWithShapes_create);
    oluacls_func(L, "hitTest", _cocos2d_EventListenerPhysicsContactWithShapes_hitTest);

    olua_registerluatype<cocos2d::EventListenerPhysicsContactWithShapes>(L, "cc.EventListenerPhysicsContactWithShapes");

    return 1;
}

static int _cocos2d_PhysicsBody___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsBody *)olua_toobj(L, 1, "cc.PhysicsBody");
    olua_push_cppobj(L, self, "cc.PhysicsBody");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsBody_addMass(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    lua_Number arg1 = 0;       /** mass */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    olua_check_number(L, 2, &arg1);

    // void addMass(float mass)
    self->addMass((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_addMoment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    lua_Number arg1 = 0;       /** moment */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    olua_check_number(L, 2, &arg1);

    // void addMoment(float moment)
    self->addMoment((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_addShape1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    cocos2d::PhysicsShape *arg1 = nullptr;       /** shape */
    bool arg2 = false;       /** addMassAndMoment */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.PhysicsShape");
    olua_check_bool(L, 3, &arg2);

    // cocos2d::PhysicsShape *addShape(cocos2d::PhysicsShape *shape, @optional bool addMassAndMoment)
    cocos2d::PhysicsShape *ret = self->addShape(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsShape");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_addShape2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    cocos2d::PhysicsShape *arg1 = nullptr;       /** shape */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.PhysicsShape");

    // cocos2d::PhysicsShape *addShape(cocos2d::PhysicsShape *shape, @optional bool addMassAndMoment)
    cocos2d::PhysicsShape *ret = self->addShape(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsShape");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_addShape(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 2, "cc.PhysicsShape"))) {
            // cocos2d::PhysicsShape *addShape(cocos2d::PhysicsShape *shape, @optional bool addMassAndMoment)
            return _cocos2d_PhysicsBody_addShape2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 2, "cc.PhysicsShape")) && (olua_is_bool(L, 3))) {
            // cocos2d::PhysicsShape *addShape(cocos2d::PhysicsShape *shape, @optional bool addMassAndMoment)
            return _cocos2d_PhysicsBody_addShape1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsBody::addShape' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsBody_applyForce1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    cocos2d::Vec2 arg1;       /** force */
    cocos2d::Vec2 arg2;       /** offset */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);
    auto_olua_check_cocos2d_Vec2(L, 3, &arg2);

    // void applyForce(const cocos2d::Vec2 &force, @optional const cocos2d::Vec2 &offset)
    self->applyForce(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_applyForce2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    cocos2d::Vec2 arg1;       /** force */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void applyForce(const cocos2d::Vec2 &force, @optional const cocos2d::Vec2 &offset)
    self->applyForce(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_applyForce(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((auto_olua_is_cocos2d_Vec2(L, 2))) {
            // void applyForce(const cocos2d::Vec2 &force, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_applyForce2(L);
        // }
    }

    if (num_args == 2) {
        // if ((auto_olua_is_cocos2d_Vec2(L, 2)) && (auto_olua_is_cocos2d_Vec2(L, 3))) {
            // void applyForce(const cocos2d::Vec2 &force, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_applyForce1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsBody::applyForce' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsBody_applyImpulse1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    cocos2d::Vec2 arg1;       /** impulse */
    cocos2d::Vec2 arg2;       /** offset */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);
    auto_olua_check_cocos2d_Vec2(L, 3, &arg2);

    // void applyImpulse(const cocos2d::Vec2 &impulse, @optional const cocos2d::Vec2 &offset)
    self->applyImpulse(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_applyImpulse2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    cocos2d::Vec2 arg1;       /** impulse */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void applyImpulse(const cocos2d::Vec2 &impulse, @optional const cocos2d::Vec2 &offset)
    self->applyImpulse(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_applyImpulse(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((auto_olua_is_cocos2d_Vec2(L, 2))) {
            // void applyImpulse(const cocos2d::Vec2 &impulse, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_applyImpulse2(L);
        // }
    }

    if (num_args == 2) {
        // if ((auto_olua_is_cocos2d_Vec2(L, 2)) && (auto_olua_is_cocos2d_Vec2(L, 3))) {
            // void applyImpulse(const cocos2d::Vec2 &impulse, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_applyImpulse1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsBody::applyImpulse' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsBody_applyTorque(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    lua_Number arg1 = 0;       /** torque */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    olua_check_number(L, 2, &arg1);

    // void applyTorque(float torque)
    self->applyTorque((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_create1(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::PhysicsBody *create()
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::create();
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_create2(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** mass */

    olua_check_number(L, 1, &arg1);

    // static cocos2d::PhysicsBody *create(float mass)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::create((float)arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_create3(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** mass */
    lua_Number arg2 = 0;       /** moment */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static cocos2d::PhysicsBody *create(float mass, float moment)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::create((float)arg1, (float)arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static cocos2d::PhysicsBody *create()
        return _cocos2d_PhysicsBody_create1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_number(L, 1))) {
            // static cocos2d::PhysicsBody *create(float mass)
            return _cocos2d_PhysicsBody_create2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2))) {
            // static cocos2d::PhysicsBody *create(float mass, float moment)
            return _cocos2d_PhysicsBody_create3(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsBody::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsBody_createBox1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    cocos2d::PhysicsMaterial arg2;       /** material */
    cocos2d::Vec2 arg3;       /** offset */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);
    auto_olua_check_cocos2d_PhysicsMaterial(L, 2, &arg2);
    auto_olua_check_cocos2d_Vec2(L, 3, &arg3);

    // static cocos2d::PhysicsBody *createBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createBox(arg1, arg2, arg3);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createBox2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);

    // static cocos2d::PhysicsBody *createBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createBox(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createBox3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    cocos2d::PhysicsMaterial arg2;       /** material */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);
    auto_olua_check_cocos2d_PhysicsMaterial(L, 2, &arg2);

    // static cocos2d::PhysicsBody *createBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createBox(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createBox(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((auto_olua_is_cocos2d_Size(L, 1))) {
            // static cocos2d::PhysicsBody *createBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_createBox2(L);
        // }
    }

    if (num_args == 2) {
        // if ((auto_olua_is_cocos2d_Size(L, 1)) && (auto_olua_is_cocos2d_PhysicsMaterial(L, 2))) {
            // static cocos2d::PhysicsBody *createBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_createBox3(L);
        // }
    }

    if (num_args == 3) {
        // if ((auto_olua_is_cocos2d_Size(L, 1)) && (auto_olua_is_cocos2d_PhysicsMaterial(L, 2)) && (auto_olua_is_cocos2d_Vec2(L, 3))) {
            // static cocos2d::PhysicsBody *createBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_createBox1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsBody::createBox' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsBody_createCircle1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** radius */
    cocos2d::PhysicsMaterial arg2;       /** material */
    cocos2d::Vec2 arg3;       /** offset */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_PhysicsMaterial(L, 2, &arg2);
    auto_olua_check_cocos2d_Vec2(L, 3, &arg3);

    // static cocos2d::PhysicsBody *createCircle(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createCircle((float)arg1, arg2, arg3);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createCircle2(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** radius */

    olua_check_number(L, 1, &arg1);

    // static cocos2d::PhysicsBody *createCircle(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createCircle((float)arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createCircle3(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** radius */
    cocos2d::PhysicsMaterial arg2;       /** material */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_PhysicsMaterial(L, 2, &arg2);

    // static cocos2d::PhysicsBody *createCircle(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createCircle((float)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createCircle(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_number(L, 1))) {
            // static cocos2d::PhysicsBody *createCircle(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_createCircle2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_number(L, 1)) && (auto_olua_is_cocos2d_PhysicsMaterial(L, 2))) {
            // static cocos2d::PhysicsBody *createCircle(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_createCircle3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (auto_olua_is_cocos2d_PhysicsMaterial(L, 2)) && (auto_olua_is_cocos2d_Vec2(L, 3))) {
            // static cocos2d::PhysicsBody *createCircle(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_createCircle1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsBody::createCircle' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsBody_createEdgeBox1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    cocos2d::PhysicsMaterial arg2;       /** material */
    lua_Number arg3 = 0;       /** border */
    cocos2d::Vec2 arg4;       /** offset */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);
    auto_olua_check_cocos2d_PhysicsMaterial(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    auto_olua_check_cocos2d_Vec2(L, 4, &arg4);

    // static cocos2d::PhysicsBody *createEdgeBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createEdgeBox(arg1, arg2, (float)arg3, arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createEdgeBox2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);

    // static cocos2d::PhysicsBody *createEdgeBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createEdgeBox(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createEdgeBox3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    cocos2d::PhysicsMaterial arg2;       /** material */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);
    auto_olua_check_cocos2d_PhysicsMaterial(L, 2, &arg2);

    // static cocos2d::PhysicsBody *createEdgeBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createEdgeBox(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createEdgeBox4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    cocos2d::PhysicsMaterial arg2;       /** material */
    lua_Number arg3 = 0;       /** border */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);
    auto_olua_check_cocos2d_PhysicsMaterial(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static cocos2d::PhysicsBody *createEdgeBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createEdgeBox(arg1, arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createEdgeBox(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((auto_olua_is_cocos2d_Size(L, 1))) {
            // static cocos2d::PhysicsBody *createEdgeBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_createEdgeBox2(L);
        // }
    }

    if (num_args == 2) {
        // if ((auto_olua_is_cocos2d_Size(L, 1)) && (auto_olua_is_cocos2d_PhysicsMaterial(L, 2))) {
            // static cocos2d::PhysicsBody *createEdgeBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_createEdgeBox3(L);
        // }
    }

    if (num_args == 3) {
        // if ((auto_olua_is_cocos2d_Size(L, 1)) && (auto_olua_is_cocos2d_PhysicsMaterial(L, 2)) && (olua_is_number(L, 3))) {
            // static cocos2d::PhysicsBody *createEdgeBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_createEdgeBox4(L);
        // }
    }

    if (num_args == 4) {
        // if ((auto_olua_is_cocos2d_Size(L, 1)) && (auto_olua_is_cocos2d_PhysicsMaterial(L, 2)) && (olua_is_number(L, 3)) && (auto_olua_is_cocos2d_Vec2(L, 4))) {
            // static cocos2d::PhysicsBody *createEdgeBox(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsBody_createEdgeBox1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsBody::createEdgeBox' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsBody_createEdgeSegment1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 arg1;       /** a */
    cocos2d::Vec2 arg2;       /** b */
    cocos2d::PhysicsMaterial arg3;       /** material */
    lua_Number arg4 = 0;       /** border */

    auto_olua_check_cocos2d_Vec2(L, 1, &arg1);
    auto_olua_check_cocos2d_Vec2(L, 2, &arg2);
    auto_olua_check_cocos2d_PhysicsMaterial(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // static cocos2d::PhysicsBody *createEdgeSegment(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createEdgeSegment(arg1, arg2, arg3, (float)arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createEdgeSegment2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 arg1;       /** a */
    cocos2d::Vec2 arg2;       /** b */

    auto_olua_check_cocos2d_Vec2(L, 1, &arg1);
    auto_olua_check_cocos2d_Vec2(L, 2, &arg2);

    // static cocos2d::PhysicsBody *createEdgeSegment(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createEdgeSegment(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createEdgeSegment3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 arg1;       /** a */
    cocos2d::Vec2 arg2;       /** b */
    cocos2d::PhysicsMaterial arg3;       /** material */

    auto_olua_check_cocos2d_Vec2(L, 1, &arg1);
    auto_olua_check_cocos2d_Vec2(L, 2, &arg2);
    auto_olua_check_cocos2d_PhysicsMaterial(L, 3, &arg3);

    // static cocos2d::PhysicsBody *createEdgeSegment(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
    cocos2d::PhysicsBody *ret = cocos2d::PhysicsBody::createEdgeSegment(arg1, arg2, arg3);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_createEdgeSegment(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((auto_olua_is_cocos2d_Vec2(L, 1)) && (auto_olua_is_cocos2d_Vec2(L, 2))) {
            // static cocos2d::PhysicsBody *createEdgeSegment(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
            return _cocos2d_PhysicsBody_createEdgeSegment2(L);
        // }
    }

    if (num_args == 3) {
        // if ((auto_olua_is_cocos2d_Vec2(L, 1)) && (auto_olua_is_cocos2d_Vec2(L, 2)) && (auto_olua_is_cocos2d_PhysicsMaterial(L, 3))) {
            // static cocos2d::PhysicsBody *createEdgeSegment(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
            return _cocos2d_PhysicsBody_createEdgeSegment3(L);
        // }
    }

    if (num_args == 4) {
        // if ((auto_olua_is_cocos2d_Vec2(L, 1)) && (auto_olua_is_cocos2d_Vec2(L, 2)) && (auto_olua_is_cocos2d_PhysicsMaterial(L, 3)) && (olua_is_number(L, 4))) {
            // static cocos2d::PhysicsBody *createEdgeSegment(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
            return _cocos2d_PhysicsBody_createEdgeSegment1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsBody::createEdgeSegment' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsBody_getAngularDamping(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");

    // float getAngularDamping()
    float ret = self->getAngularDamping();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getAngularVelocity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");

    // float getAngularVelocity()
    float ret = self->getAngularVelocity();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getAngularVelocityLimit(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");

    // float getAngularVelocityLimit()
    float ret = self->getAngularVelocityLimit();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getCategoryBitmask(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");

    // int getCategoryBitmask()
    int ret = self->getCategoryBitmask();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getCollisionBitmask(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");

    // int getCollisionBitmask()
    int ret = self->getCollisionBitmask();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getContactTestBitmask(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");

    // int getContactTestBitmask()
    int ret = self->getContactTestBitmask();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getFirstShape(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");

    // cocos2d::PhysicsShape *getFirstShape()
    cocos2d::PhysicsShape *ret = self->getFirstShape();
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsShape");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getGroup(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");

    // int getGroup()
    int ret = self->getGroup();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getJoints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");

    // const std::vector<PhysicsJoint *> &getJoints()
    const std::vector<cocos2d::PhysicsJoint *> &ret = self->getJoints();
    int num_ret = olua_push_std_vector(L, ret, "cc.PhysicsJoint");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getLinearDamping(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");

    // float getLinearDamping()
    float ret = self->getLinearDamping();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getMass(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");

    // float getMass()
    float ret = self->getMass();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getMoment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");

    // float getMoment()
    float ret = self->getMoment();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getNode(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");

    // cocos2d::Node *getNode()
    cocos2d::Node *ret = self->getNode();
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getPosition(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");

    // cocos2d::Vec2 getPosition()
    cocos2d::Vec2 ret = self->getPosition();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getPositionOffset(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");

    // const cocos2d::Vec2 &getPositionOffset()
    const cocos2d::Vec2 &ret = self->getPositionOffset();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getRotation(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");

    // float getRotation()
    float ret = self->getRotation();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getRotationOffset(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");

    // float getRotationOffset()
    float ret = self->getRotationOffset();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getShape(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    lua_Integer arg1 = 0;       /** tag */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    olua_check_int(L, 2, &arg1);

    // cocos2d::PhysicsShape *getShape(int tag)
    cocos2d::PhysicsShape *ret = self->getShape((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsShape");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getShapes(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");

    // const Vector<cocos2d::PhysicsShape *> &getShapes()
    const cocos2d::Vector<cocos2d::PhysicsShape *> &ret = self->getShapes();
    int num_ret = manual_olua_push_cocos2d_Vector(L, ret, "cc.PhysicsShape");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getTag(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");

    // int getTag()
    int ret = self->getTag();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getVelocity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");

    // cocos2d::Vec2 getVelocity()
    cocos2d::Vec2 ret = self->getVelocity();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getVelocityAtLocalPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    cocos2d::Vec2 arg1;       /** point */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // cocos2d::Vec2 getVelocityAtLocalPoint(const cocos2d::Vec2 &point)
    cocos2d::Vec2 ret = self->getVelocityAtLocalPoint(arg1);
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getVelocityAtWorldPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    cocos2d::Vec2 arg1;       /** point */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // cocos2d::Vec2 getVelocityAtWorldPoint(const cocos2d::Vec2 &point)
    cocos2d::Vec2 ret = self->getVelocityAtWorldPoint(arg1);
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getVelocityLimit(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");

    // float getVelocityLimit()
    float ret = self->getVelocityLimit();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_getWorld(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");

    // cocos2d::PhysicsWorld *getWorld()
    cocos2d::PhysicsWorld *ret = self->getWorld();
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsWorld");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_isDynamic(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // cocos2d::Vec2 local2World(const cocos2d::Vec2 &point)
    cocos2d::Vec2 ret = self->local2World(arg1);
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsBody_removeAllShapes1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    bool arg1 = false;       /** reduceMassAndMoment */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    olua_check_bool(L, 2, &arg1);

    // void removeAllShapes(@optional bool reduceMassAndMoment)
    self->removeAllShapes(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_removeAllShapes2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");

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
        return _cocos2d_PhysicsBody_removeAllShapes2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_bool(L, 2))) {
            // void removeAllShapes(@optional bool reduceMassAndMoment)
            return _cocos2d_PhysicsBody_removeAllShapes1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsBody::removeAllShapes' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsBody_removeFromWorld(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");

    // void removeFromWorld()
    self->removeFromWorld();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_removeShape1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    cocos2d::PhysicsShape *arg1 = nullptr;       /** shape */
    bool arg2 = false;       /** reduceMassAndMoment */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.PhysicsShape");
    olua_check_bool(L, 3, &arg2);

    // void removeShape(cocos2d::PhysicsShape *shape, @optional bool reduceMassAndMoment)
    self->removeShape(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_removeShape2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    lua_Integer arg1 = 0;       /** tag */
    bool arg2 = false;       /** reduceMassAndMoment */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    olua_check_int(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void removeShape(int tag, @optional bool reduceMassAndMoment)
    self->removeShape((int)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_removeShape3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    cocos2d::PhysicsShape *arg1 = nullptr;       /** shape */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.PhysicsShape");

    // void removeShape(cocos2d::PhysicsShape *shape, @optional bool reduceMassAndMoment)
    self->removeShape(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_removeShape4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    lua_Integer arg1 = 0;       /** tag */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    olua_check_int(L, 2, &arg1);

    // void removeShape(int tag, @optional bool reduceMassAndMoment)
    self->removeShape((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_removeShape(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        if ((olua_is_cppobj(L, 2, "cc.PhysicsShape"))) {
            // void removeShape(cocos2d::PhysicsShape *shape, @optional bool reduceMassAndMoment)
            return _cocos2d_PhysicsBody_removeShape3(L);
        }

        // if ((olua_is_int(L, 2))) {
            // void removeShape(int tag, @optional bool reduceMassAndMoment)
            return _cocos2d_PhysicsBody_removeShape4(L);
        // }
    }

    if (num_args == 2) {
        if ((olua_is_cppobj(L, 2, "cc.PhysicsShape")) && (olua_is_bool(L, 3))) {
            // void removeShape(cocos2d::PhysicsShape *shape, @optional bool reduceMassAndMoment)
            return _cocos2d_PhysicsBody_removeShape1(L);
        }

        // if ((olua_is_int(L, 2)) && (olua_is_bool(L, 3))) {
            // void removeShape(int tag, @optional bool reduceMassAndMoment)
            return _cocos2d_PhysicsBody_removeShape2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsBody::removeShape' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsBody_resetForces(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");

    // void resetForces()
    self->resetForces();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setAngularDamping(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    lua_Number arg1 = 0;       /** damping */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    olua_check_number(L, 2, &arg1);

    // void setAngularDamping(float damping)
    self->setAngularDamping((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setAngularVelocity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    lua_Number arg1 = 0;       /** velocity */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    olua_check_number(L, 2, &arg1);

    // void setAngularVelocity(float velocity)
    self->setAngularVelocity((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setAngularVelocityLimit(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    lua_Number arg1 = 0;       /** limit */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    olua_check_number(L, 2, &arg1);

    // void setAngularVelocityLimit(float limit)
    self->setAngularVelocityLimit((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setCategoryBitmask(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    lua_Integer arg1 = 0;       /** bitmask */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    olua_check_int(L, 2, &arg1);

    // void setCategoryBitmask(int bitmask)
    self->setCategoryBitmask((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setCollisionBitmask(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    lua_Integer arg1 = 0;       /** bitmask */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    olua_check_int(L, 2, &arg1);

    // void setCollisionBitmask(int bitmask)
    self->setCollisionBitmask((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setContactTestBitmask(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    lua_Integer arg1 = 0;       /** bitmask */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    olua_check_int(L, 2, &arg1);

    // void setContactTestBitmask(int bitmask)
    self->setContactTestBitmask((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setDynamic(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    bool arg1 = false;       /** dynamic */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
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

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
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
    lua_Integer arg1 = 0;       /** group */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    olua_check_int(L, 2, &arg1);

    // void setGroup(int group)
    self->setGroup((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setLinearDamping(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    lua_Number arg1 = 0;       /** damping */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    olua_check_number(L, 2, &arg1);

    // void setLinearDamping(float damping)
    self->setLinearDamping((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setMass(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    lua_Number arg1 = 0;       /** mass */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    olua_check_number(L, 2, &arg1);

    // void setMass(float mass)
    self->setMass((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setMoment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    lua_Number arg1 = 0;       /** moment */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    olua_check_number(L, 2, &arg1);

    // void setMoment(float moment)
    self->setMoment((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setPositionOffset(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    cocos2d::Vec2 arg1;       /** position */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
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

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
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
    lua_Number arg1 = 0;       /** rotation */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    olua_check_number(L, 2, &arg1);

    // void setRotationOffset(float rotation)
    self->setRotationOffset((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setTag(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    lua_Integer arg1 = 0;       /** tag */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    olua_check_int(L, 2, &arg1);

    // void setTag(int tag)
    self->setTag((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setVelocity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    cocos2d::Vec2 arg1;       /** velocity */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void setVelocity(const cocos2d::Vec2 &velocity)
    self->setVelocity(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_setVelocityLimit(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    lua_Number arg1 = 0;       /** limit */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    olua_check_number(L, 2, &arg1);

    // void setVelocityLimit(float limit)
    self->setVelocityLimit((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsBody_world2Local(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *self = nullptr;
    cocos2d::Vec2 arg1;       /** point */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsBody");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // cocos2d::Vec2 world2Local(const cocos2d::Vec2 &point)
    cocos2d::Vec2 ret = self->world2Local(arg1);
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_PhysicsBody(lua_State *L)
{
    oluacls_class(L, "cc.PhysicsBody", "cc.Component");
    oluacls_func(L, "__move", _cocos2d_PhysicsBody___move);
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
    oluacls_func(L, "createEdgeSegment", _cocos2d_PhysicsBody_createEdgeSegment);
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
    oluacls_const_string(L, "COMPONENT_NAME", (const char *)cocos2d::PhysicsBody::COMPONENT_NAME.c_str());

    olua_registerluatype<cocos2d::PhysicsBody>(L, "cc.PhysicsBody");

    return 1;
}

static int luaopen_cocos2d_PhysicsContact_EventCode(lua_State *L)
{
    oluacls_class(L, "cc.PhysicsContact.EventCode", nullptr);
    oluacls_const_integer(L, "BEGIN", (lua_Integer)cocos2d::PhysicsContact::EventCode::BEGIN);
    oluacls_const_integer(L, "NONE", (lua_Integer)cocos2d::PhysicsContact::EventCode::NONE);
    oluacls_const_integer(L, "POSTSOLVE", (lua_Integer)cocos2d::PhysicsContact::EventCode::POSTSOLVE);
    oluacls_const_integer(L, "PRESOLVE", (lua_Integer)cocos2d::PhysicsContact::EventCode::PRESOLVE);
    oluacls_const_integer(L, "SEPARATE", (lua_Integer)cocos2d::PhysicsContact::EventCode::SEPARATE);

    olua_registerluatype<cocos2d::PhysicsContact::EventCode>(L, "cc.PhysicsContact.EventCode");

    return 1;
}

static int _cocos2d_PhysicsContact___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsContact *)olua_toobj(L, 1, "cc.PhysicsContact");
    olua_push_cppobj(L, self, "cc.PhysicsContact");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsContact_getData(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContact *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsContact");

    // void *getData()
    void *ret = self->getData();
    int num_ret = olua_push_obj(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsContact_getEventCode(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContact *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsContact");

    // cocos2d::PhysicsContact::EventCode getEventCode()
    cocos2d::PhysicsContact::EventCode ret = self->getEventCode();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsContact_getShapeA(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContact *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsContact");

    // cocos2d::PhysicsShape *getShapeA()
    cocos2d::PhysicsShape *ret = self->getShapeA();
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsShape");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsContact_getShapeB(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContact *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsContact");

    // cocos2d::PhysicsShape *getShapeB()
    cocos2d::PhysicsShape *ret = self->getShapeB();
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsShape");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsContact_setData(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContact *self = nullptr;
    void *arg1 = nullptr;       /** data */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsContact");
    olua_check_obj(L, 2, (void **)&arg1, "void *");

    // void setData(void *data)
    self->setData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_PhysicsContact(lua_State *L)
{
    oluacls_class(L, "cc.PhysicsContact", "cc.EventCustom");
    oluacls_func(L, "__move", _cocos2d_PhysicsContact___move);
    oluacls_func(L, "getData", _cocos2d_PhysicsContact_getData);
    oluacls_func(L, "getEventCode", _cocos2d_PhysicsContact_getEventCode);
    oluacls_func(L, "getShapeA", _cocos2d_PhysicsContact_getShapeA);
    oluacls_func(L, "getShapeB", _cocos2d_PhysicsContact_getShapeB);
    oluacls_func(L, "setData", _cocos2d_PhysicsContact_setData);
    oluacls_prop(L, "data", _cocos2d_PhysicsContact_getData, _cocos2d_PhysicsContact_setData);
    oluacls_prop(L, "eventCode", _cocos2d_PhysicsContact_getEventCode, nullptr);
    oluacls_prop(L, "shapeA", _cocos2d_PhysicsContact_getShapeA, nullptr);
    oluacls_prop(L, "shapeB", _cocos2d_PhysicsContact_getShapeB, nullptr);

    olua_registerluatype<cocos2d::PhysicsContact>(L, "cc.PhysicsContact");

    return 1;
}

static int _cocos2d_PhysicsContactPostSolve___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsContactPostSolve *)olua_toobj(L, 1, "cc.PhysicsContactPostSolve");
    olua_push_cppobj(L, self, "cc.PhysicsContactPostSolve");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsContactPostSolve_getFriction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContactPostSolve *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsContactPostSolve");

    // float getFriction()
    float ret = self->getFriction();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsContactPostSolve_getRestitution(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContactPostSolve *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsContactPostSolve");

    // float getRestitution()
    float ret = self->getRestitution();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsContactPostSolve_getSurfaceVelocity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContactPostSolve *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsContactPostSolve");

    // cocos2d::Vec2 getSurfaceVelocity()
    cocos2d::Vec2 ret = self->getSurfaceVelocity();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_PhysicsContactPostSolve(lua_State *L)
{
    oluacls_class(L, "cc.PhysicsContactPostSolve", nullptr);
    oluacls_func(L, "__move", _cocos2d_PhysicsContactPostSolve___move);
    oluacls_func(L, "getFriction", _cocos2d_PhysicsContactPostSolve_getFriction);
    oluacls_func(L, "getRestitution", _cocos2d_PhysicsContactPostSolve_getRestitution);
    oluacls_func(L, "getSurfaceVelocity", _cocos2d_PhysicsContactPostSolve_getSurfaceVelocity);
    oluacls_prop(L, "friction", _cocos2d_PhysicsContactPostSolve_getFriction, nullptr);
    oluacls_prop(L, "restitution", _cocos2d_PhysicsContactPostSolve_getRestitution, nullptr);
    oluacls_prop(L, "surfaceVelocity", _cocos2d_PhysicsContactPostSolve_getSurfaceVelocity, nullptr);

    olua_registerluatype<cocos2d::PhysicsContactPostSolve>(L, "cc.PhysicsContactPostSolve");

    return 1;
}

static int _cocos2d_PhysicsContactPreSolve___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsContactPreSolve *)olua_toobj(L, 1, "cc.PhysicsContactPreSolve");
    olua_push_cppobj(L, self, "cc.PhysicsContactPreSolve");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsContactPreSolve_getFriction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContactPreSolve *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsContactPreSolve");

    // float getFriction()
    float ret = self->getFriction();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsContactPreSolve_getRestitution(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContactPreSolve *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsContactPreSolve");

    // float getRestitution()
    float ret = self->getRestitution();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsContactPreSolve_getSurfaceVelocity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContactPreSolve *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsContactPreSolve");

    // cocos2d::Vec2 getSurfaceVelocity()
    cocos2d::Vec2 ret = self->getSurfaceVelocity();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsContactPreSolve_ignore(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContactPreSolve *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsContactPreSolve");

    // void ignore()
    self->ignore();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsContactPreSolve_setFriction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContactPreSolve *self = nullptr;
    lua_Number arg1 = 0;       /** friction */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsContactPreSolve");
    olua_check_number(L, 2, &arg1);

    // void setFriction(float friction)
    self->setFriction((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsContactPreSolve_setRestitution(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContactPreSolve *self = nullptr;
    lua_Number arg1 = 0;       /** restitution */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsContactPreSolve");
    olua_check_number(L, 2, &arg1);

    // void setRestitution(float restitution)
    self->setRestitution((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsContactPreSolve_setSurfaceVelocity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsContactPreSolve *self = nullptr;
    cocos2d::Vec2 arg1;       /** velocity */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsContactPreSolve");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void setSurfaceVelocity(const cocos2d::Vec2 &velocity)
    self->setSurfaceVelocity(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_PhysicsContactPreSolve(lua_State *L)
{
    oluacls_class(L, "cc.PhysicsContactPreSolve", nullptr);
    oluacls_func(L, "__move", _cocos2d_PhysicsContactPreSolve___move);
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

    olua_registerluatype<cocos2d::PhysicsContactPreSolve>(L, "cc.PhysicsContactPreSolve");

    return 1;
}

static int _cocos2d_PhysicsJoint___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsJoint *)olua_toobj(L, 1, "cc.PhysicsJoint");
    olua_push_cppobj(L, self, "cc.PhysicsJoint");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsJoint_getBodyA(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJoint");

    // cocos2d::PhysicsBody *getBodyA()
    cocos2d::PhysicsBody *ret = self->getBodyA();
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJoint_getBodyB(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJoint");

    // cocos2d::PhysicsBody *getBodyB()
    cocos2d::PhysicsBody *ret = self->getBodyB();
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJoint_getMaxForce(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJoint");

    // float getMaxForce()
    float ret = self->getMaxForce();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJoint_getTag(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJoint");

    // int getTag()
    int ret = self->getTag();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJoint_getWorld(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJoint");

    // cocos2d::PhysicsWorld *getWorld()
    cocos2d::PhysicsWorld *ret = self->getWorld();
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsWorld");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJoint_isCollisionEnabled(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJoint *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJoint");

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJoint");

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJoint");

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJoint");
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

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJoint");
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
    lua_Number arg1 = 0;       /** force */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJoint");
    olua_check_number(L, 2, &arg1);

    // void setMaxForce(float force)
    self->setMaxForce((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJoint_setTag(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJoint *self = nullptr;
    lua_Integer arg1 = 0;       /** tag */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJoint");
    olua_check_int(L, 2, &arg1);

    // void setTag(int tag)
    self->setTag((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_PhysicsJoint(lua_State *L)
{
    oluacls_class(L, "cc.PhysicsJoint", nullptr);
    oluacls_func(L, "__move", _cocos2d_PhysicsJoint___move);
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

    olua_registerluatype<cocos2d::PhysicsJoint>(L, "cc.PhysicsJoint");

    return 1;
}

static int _cocos2d_PhysicsJointDistance___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsJointDistance *)olua_toobj(L, 1, "cc.PhysicsJointDistance");
    olua_push_cppobj(L, self, "cc.PhysicsJointDistance");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsJointDistance_construct(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** a */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** b */
    cocos2d::Vec2 arg3;       /** anchr1 */
    cocos2d::Vec2 arg4;       /** anchr2 */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.PhysicsBody");
    olua_check_cppobj(L, 2, (void **)&arg2, "cc.PhysicsBody");
    auto_olua_check_cocos2d_Vec2(L, 3, &arg3);
    auto_olua_check_cocos2d_Vec2(L, 4, &arg4);

    // static cocos2d::PhysicsJointDistance *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2)
    cocos2d::PhysicsJointDistance *ret = cocos2d::PhysicsJointDistance::construct(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsJointDistance");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointDistance_createConstraints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointDistance *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointDistance");

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointDistance");

    // float getDistance()
    float ret = self->getDistance();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointDistance_setDistance(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointDistance *self = nullptr;
    lua_Number arg1 = 0;       /** distance */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointDistance");
    olua_check_number(L, 2, &arg1);

    // void setDistance(float distance)
    self->setDistance((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_PhysicsJointDistance(lua_State *L)
{
    oluacls_class(L, "cc.PhysicsJointDistance", "cc.PhysicsJoint");
    oluacls_func(L, "__move", _cocos2d_PhysicsJointDistance___move);
    oluacls_func(L, "construct", _cocos2d_PhysicsJointDistance_construct);
    oluacls_func(L, "createConstraints", _cocos2d_PhysicsJointDistance_createConstraints);
    oluacls_func(L, "getDistance", _cocos2d_PhysicsJointDistance_getDistance);
    oluacls_func(L, "setDistance", _cocos2d_PhysicsJointDistance_setDistance);
    oluacls_prop(L, "distance", _cocos2d_PhysicsJointDistance_getDistance, _cocos2d_PhysicsJointDistance_setDistance);

    olua_registerluatype<cocos2d::PhysicsJointDistance>(L, "cc.PhysicsJointDistance");

    return 1;
}

static int _cocos2d_PhysicsJointFixed___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsJointFixed *)olua_toobj(L, 1, "cc.PhysicsJointFixed");
    olua_push_cppobj(L, self, "cc.PhysicsJointFixed");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsJointFixed_construct(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** a */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** b */
    cocos2d::Vec2 arg3;       /** anchr */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.PhysicsBody");
    olua_check_cppobj(L, 2, (void **)&arg2, "cc.PhysicsBody");
    auto_olua_check_cocos2d_Vec2(L, 3, &arg3);

    // static cocos2d::PhysicsJointFixed *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr)
    cocos2d::PhysicsJointFixed *ret = cocos2d::PhysicsJointFixed::construct(arg1, arg2, arg3);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsJointFixed");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointFixed_createConstraints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointFixed *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointFixed");

    // bool createConstraints()
    bool ret = self->createConstraints();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_PhysicsJointFixed(lua_State *L)
{
    oluacls_class(L, "cc.PhysicsJointFixed", "cc.PhysicsJoint");
    oluacls_func(L, "__move", _cocos2d_PhysicsJointFixed___move);
    oluacls_func(L, "construct", _cocos2d_PhysicsJointFixed_construct);
    oluacls_func(L, "createConstraints", _cocos2d_PhysicsJointFixed_createConstraints);

    olua_registerluatype<cocos2d::PhysicsJointFixed>(L, "cc.PhysicsJointFixed");

    return 1;
}

static int _cocos2d_PhysicsJointGear___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsJointGear *)olua_toobj(L, 1, "cc.PhysicsJointGear");
    olua_push_cppobj(L, self, "cc.PhysicsJointGear");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsJointGear_construct(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** a */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** b */
    lua_Number arg3 = 0;       /** phase */
    lua_Number arg4 = 0;       /** ratio */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.PhysicsBody");
    olua_check_cppobj(L, 2, (void **)&arg2, "cc.PhysicsBody");
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // static cocos2d::PhysicsJointGear *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, float phase, float ratio)
    cocos2d::PhysicsJointGear *ret = cocos2d::PhysicsJointGear::construct(arg1, arg2, (float)arg3, (float)arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsJointGear");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointGear_createConstraints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointGear *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointGear");

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointGear");

    // float getPhase()
    float ret = self->getPhase();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointGear_getRatio(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointGear *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointGear");

    // float getRatio()
    float ret = self->getRatio();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointGear_setPhase(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointGear *self = nullptr;
    lua_Number arg1 = 0;       /** phase */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointGear");
    olua_check_number(L, 2, &arg1);

    // void setPhase(float phase)
    self->setPhase((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJointGear_setRatio(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointGear *self = nullptr;
    lua_Number arg1 = 0;       /** ratchet */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointGear");
    olua_check_number(L, 2, &arg1);

    // void setRatio(float ratchet)
    self->setRatio((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_PhysicsJointGear(lua_State *L)
{
    oluacls_class(L, "cc.PhysicsJointGear", "cc.PhysicsJoint");
    oluacls_func(L, "__move", _cocos2d_PhysicsJointGear___move);
    oluacls_func(L, "construct", _cocos2d_PhysicsJointGear_construct);
    oluacls_func(L, "createConstraints", _cocos2d_PhysicsJointGear_createConstraints);
    oluacls_func(L, "getPhase", _cocos2d_PhysicsJointGear_getPhase);
    oluacls_func(L, "getRatio", _cocos2d_PhysicsJointGear_getRatio);
    oluacls_func(L, "setPhase", _cocos2d_PhysicsJointGear_setPhase);
    oluacls_func(L, "setRatio", _cocos2d_PhysicsJointGear_setRatio);
    oluacls_prop(L, "phase", _cocos2d_PhysicsJointGear_getPhase, _cocos2d_PhysicsJointGear_setPhase);
    oluacls_prop(L, "ratio", _cocos2d_PhysicsJointGear_getRatio, _cocos2d_PhysicsJointGear_setRatio);

    olua_registerluatype<cocos2d::PhysicsJointGear>(L, "cc.PhysicsJointGear");

    return 1;
}

static int _cocos2d_PhysicsJointGroove___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsJointGroove *)olua_toobj(L, 1, "cc.PhysicsJointGroove");
    olua_push_cppobj(L, self, "cc.PhysicsJointGroove");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsJointGroove_construct(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** a */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** b */
    cocos2d::Vec2 arg3;       /** grooveA */
    cocos2d::Vec2 arg4;       /** grooveB */
    cocos2d::Vec2 arg5;       /** anchr2 */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.PhysicsBody");
    olua_check_cppobj(L, 2, (void **)&arg2, "cc.PhysicsBody");
    auto_olua_check_cocos2d_Vec2(L, 3, &arg3);
    auto_olua_check_cocos2d_Vec2(L, 4, &arg4);
    auto_olua_check_cocos2d_Vec2(L, 5, &arg5);

    // static cocos2d::PhysicsJointGroove *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &grooveA, const cocos2d::Vec2 &grooveB, const cocos2d::Vec2 &anchr2)
    cocos2d::PhysicsJointGroove *ret = cocos2d::PhysicsJointGroove::construct(arg1, arg2, arg3, arg4, arg5);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsJointGroove");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointGroove_createConstraints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointGroove *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointGroove");

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointGroove");

    // cocos2d::Vec2 getAnchr2()
    cocos2d::Vec2 ret = self->getAnchr2();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointGroove_getGrooveA(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointGroove *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointGroove");

    // cocos2d::Vec2 getGrooveA()
    cocos2d::Vec2 ret = self->getGrooveA();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointGroove_getGrooveB(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointGroove *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointGroove");

    // cocos2d::Vec2 getGrooveB()
    cocos2d::Vec2 ret = self->getGrooveB();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointGroove_setAnchr2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointGroove *self = nullptr;
    cocos2d::Vec2 arg1;       /** anchr2 */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointGroove");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointGroove");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointGroove");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void setGrooveB(const cocos2d::Vec2 &grooveB)
    self->setGrooveB(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_PhysicsJointGroove(lua_State *L)
{
    oluacls_class(L, "cc.PhysicsJointGroove", "cc.PhysicsJoint");
    oluacls_func(L, "__move", _cocos2d_PhysicsJointGroove___move);
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

    olua_registerluatype<cocos2d::PhysicsJointGroove>(L, "cc.PhysicsJointGroove");

    return 1;
}

static int _cocos2d_PhysicsJointLimit___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsJointLimit *)olua_toobj(L, 1, "cc.PhysicsJointLimit");
    olua_push_cppobj(L, self, "cc.PhysicsJointLimit");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsJointLimit_construct1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** a */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** b */
    cocos2d::Vec2 arg3;       /** anchr1 */
    cocos2d::Vec2 arg4;       /** anchr2 */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.PhysicsBody");
    olua_check_cppobj(L, 2, (void **)&arg2, "cc.PhysicsBody");
    auto_olua_check_cocos2d_Vec2(L, 3, &arg3);
    auto_olua_check_cocos2d_Vec2(L, 4, &arg4);

    // static cocos2d::PhysicsJointLimit *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2)
    cocos2d::PhysicsJointLimit *ret = cocos2d::PhysicsJointLimit::construct(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsJointLimit");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointLimit_construct2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** a */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** b */
    cocos2d::Vec2 arg3;       /** anchr1 */
    cocos2d::Vec2 arg4;       /** anchr2 */
    lua_Number arg5 = 0;       /** min */
    lua_Number arg6 = 0;       /** max */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.PhysicsBody");
    olua_check_cppobj(L, 2, (void **)&arg2, "cc.PhysicsBody");
    auto_olua_check_cocos2d_Vec2(L, 3, &arg3);
    auto_olua_check_cocos2d_Vec2(L, 4, &arg4);
    olua_check_number(L, 5, &arg5);
    olua_check_number(L, 6, &arg6);

    // static cocos2d::PhysicsJointLimit *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2, float min, float max)
    cocos2d::PhysicsJointLimit *ret = cocos2d::PhysicsJointLimit::construct(arg1, arg2, arg3, arg4, (float)arg5, (float)arg6);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsJointLimit");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointLimit_construct(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 4) {
        // if ((olua_is_cppobj(L, 1, "cc.PhysicsBody")) && (olua_is_cppobj(L, 2, "cc.PhysicsBody")) && (auto_olua_is_cocos2d_Vec2(L, 3)) && (auto_olua_is_cocos2d_Vec2(L, 4))) {
            // static cocos2d::PhysicsJointLimit *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2)
            return _cocos2d_PhysicsJointLimit_construct1(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_cppobj(L, 1, "cc.PhysicsBody")) && (olua_is_cppobj(L, 2, "cc.PhysicsBody")) && (auto_olua_is_cocos2d_Vec2(L, 3)) && (auto_olua_is_cocos2d_Vec2(L, 4)) && (olua_is_number(L, 5)) && (olua_is_number(L, 6))) {
            // static cocos2d::PhysicsJointLimit *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2, float min, float max)
            return _cocos2d_PhysicsJointLimit_construct2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsJointLimit::construct' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsJointLimit_createConstraints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointLimit *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointLimit");

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointLimit");

    // cocos2d::Vec2 getAnchr1()
    cocos2d::Vec2 ret = self->getAnchr1();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointLimit_getAnchr2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointLimit *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointLimit");

    // cocos2d::Vec2 getAnchr2()
    cocos2d::Vec2 ret = self->getAnchr2();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointLimit_getMax(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointLimit *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointLimit");

    // float getMax()
    float ret = self->getMax();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointLimit_getMin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointLimit *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointLimit");

    // float getMin()
    float ret = self->getMin();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointLimit_setAnchr1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointLimit *self = nullptr;
    cocos2d::Vec2 arg1;       /** anchr1 */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointLimit");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointLimit");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void setAnchr2(const cocos2d::Vec2 &anchr2)
    self->setAnchr2(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJointLimit_setMax(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointLimit *self = nullptr;
    lua_Number arg1 = 0;       /** max */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointLimit");
    olua_check_number(L, 2, &arg1);

    // void setMax(float max)
    self->setMax((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJointLimit_setMin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointLimit *self = nullptr;
    lua_Number arg1 = 0;       /** min */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointLimit");
    olua_check_number(L, 2, &arg1);

    // void setMin(float min)
    self->setMin((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_PhysicsJointLimit(lua_State *L)
{
    oluacls_class(L, "cc.PhysicsJointLimit", "cc.PhysicsJoint");
    oluacls_func(L, "__move", _cocos2d_PhysicsJointLimit___move);
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

    olua_registerluatype<cocos2d::PhysicsJointLimit>(L, "cc.PhysicsJointLimit");

    return 1;
}

static int _cocos2d_PhysicsJointMotor___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsJointMotor *)olua_toobj(L, 1, "cc.PhysicsJointMotor");
    olua_push_cppobj(L, self, "cc.PhysicsJointMotor");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsJointMotor_construct(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** a */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** b */
    lua_Number arg3 = 0;       /** rate */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.PhysicsBody");
    olua_check_cppobj(L, 2, (void **)&arg2, "cc.PhysicsBody");
    olua_check_number(L, 3, &arg3);

    // static cocos2d::PhysicsJointMotor *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, float rate)
    cocos2d::PhysicsJointMotor *ret = cocos2d::PhysicsJointMotor::construct(arg1, arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsJointMotor");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointMotor_createConstraints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointMotor *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointMotor");

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointMotor");

    // float getRate()
    float ret = self->getRate();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointMotor_setRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointMotor *self = nullptr;
    lua_Number arg1 = 0;       /** rate */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointMotor");
    olua_check_number(L, 2, &arg1);

    // void setRate(float rate)
    self->setRate((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_PhysicsJointMotor(lua_State *L)
{
    oluacls_class(L, "cc.PhysicsJointMotor", "cc.PhysicsJoint");
    oluacls_func(L, "__move", _cocos2d_PhysicsJointMotor___move);
    oluacls_func(L, "construct", _cocos2d_PhysicsJointMotor_construct);
    oluacls_func(L, "createConstraints", _cocos2d_PhysicsJointMotor_createConstraints);
    oluacls_func(L, "getRate", _cocos2d_PhysicsJointMotor_getRate);
    oluacls_func(L, "setRate", _cocos2d_PhysicsJointMotor_setRate);
    oluacls_prop(L, "rate", _cocos2d_PhysicsJointMotor_getRate, _cocos2d_PhysicsJointMotor_setRate);

    olua_registerluatype<cocos2d::PhysicsJointMotor>(L, "cc.PhysicsJointMotor");

    return 1;
}

static int _cocos2d_PhysicsJointPin___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsJointPin *)olua_toobj(L, 1, "cc.PhysicsJointPin");
    olua_push_cppobj(L, self, "cc.PhysicsJointPin");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsJointPin_construct1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** a */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** b */
    cocos2d::Vec2 arg3;       /** pivot */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.PhysicsBody");
    olua_check_cppobj(L, 2, (void **)&arg2, "cc.PhysicsBody");
    auto_olua_check_cocos2d_Vec2(L, 3, &arg3);

    // static cocos2d::PhysicsJointPin *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &pivot)
    cocos2d::PhysicsJointPin *ret = cocos2d::PhysicsJointPin::construct(arg1, arg2, arg3);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsJointPin");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointPin_construct2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** a */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** b */
    cocos2d::Vec2 arg3;       /** anchr1 */
    cocos2d::Vec2 arg4;       /** anchr2 */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.PhysicsBody");
    olua_check_cppobj(L, 2, (void **)&arg2, "cc.PhysicsBody");
    auto_olua_check_cocos2d_Vec2(L, 3, &arg3);
    auto_olua_check_cocos2d_Vec2(L, 4, &arg4);

    // static cocos2d::PhysicsJointPin *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2)
    cocos2d::PhysicsJointPin *ret = cocos2d::PhysicsJointPin::construct(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsJointPin");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointPin_construct(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 3) {
        // if ((olua_is_cppobj(L, 1, "cc.PhysicsBody")) && (olua_is_cppobj(L, 2, "cc.PhysicsBody")) && (auto_olua_is_cocos2d_Vec2(L, 3))) {
            // static cocos2d::PhysicsJointPin *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &pivot)
            return _cocos2d_PhysicsJointPin_construct1(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_cppobj(L, 1, "cc.PhysicsBody")) && (olua_is_cppobj(L, 2, "cc.PhysicsBody")) && (auto_olua_is_cocos2d_Vec2(L, 3)) && (auto_olua_is_cocos2d_Vec2(L, 4))) {
            // static cocos2d::PhysicsJointPin *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2)
            return _cocos2d_PhysicsJointPin_construct2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsJointPin::construct' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsJointPin_createConstraints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointPin *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointPin");

    // bool createConstraints()
    bool ret = self->createConstraints();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_PhysicsJointPin(lua_State *L)
{
    oluacls_class(L, "cc.PhysicsJointPin", "cc.PhysicsJoint");
    oluacls_func(L, "__move", _cocos2d_PhysicsJointPin___move);
    oluacls_func(L, "construct", _cocos2d_PhysicsJointPin_construct);
    oluacls_func(L, "createConstraints", _cocos2d_PhysicsJointPin_createConstraints);

    olua_registerluatype<cocos2d::PhysicsJointPin>(L, "cc.PhysicsJointPin");

    return 1;
}

static int _cocos2d_PhysicsJointRatchet___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsJointRatchet *)olua_toobj(L, 1, "cc.PhysicsJointRatchet");
    olua_push_cppobj(L, self, "cc.PhysicsJointRatchet");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsJointRatchet_construct(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** a */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** b */
    lua_Number arg3 = 0;       /** phase */
    lua_Number arg4 = 0;       /** ratchet */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.PhysicsBody");
    olua_check_cppobj(L, 2, (void **)&arg2, "cc.PhysicsBody");
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // static cocos2d::PhysicsJointRatchet *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, float phase, float ratchet)
    cocos2d::PhysicsJointRatchet *ret = cocos2d::PhysicsJointRatchet::construct(arg1, arg2, (float)arg3, (float)arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsJointRatchet");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointRatchet_createConstraints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRatchet *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointRatchet");

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointRatchet");

    // float getAngle()
    float ret = self->getAngle();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointRatchet_getPhase(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRatchet *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointRatchet");

    // float getPhase()
    float ret = self->getPhase();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointRatchet_getRatchet(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRatchet *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointRatchet");

    // float getRatchet()
    float ret = self->getRatchet();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointRatchet_setAngle(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRatchet *self = nullptr;
    lua_Number arg1 = 0;       /** angle */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointRatchet");
    olua_check_number(L, 2, &arg1);

    // void setAngle(float angle)
    self->setAngle((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJointRatchet_setPhase(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRatchet *self = nullptr;
    lua_Number arg1 = 0;       /** phase */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointRatchet");
    olua_check_number(L, 2, &arg1);

    // void setPhase(float phase)
    self->setPhase((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJointRatchet_setRatchet(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRatchet *self = nullptr;
    lua_Number arg1 = 0;       /** ratchet */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointRatchet");
    olua_check_number(L, 2, &arg1);

    // void setRatchet(float ratchet)
    self->setRatchet((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_PhysicsJointRatchet(lua_State *L)
{
    oluacls_class(L, "cc.PhysicsJointRatchet", "cc.PhysicsJoint");
    oluacls_func(L, "__move", _cocos2d_PhysicsJointRatchet___move);
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

    olua_registerluatype<cocos2d::PhysicsJointRatchet>(L, "cc.PhysicsJointRatchet");

    return 1;
}

static int _cocos2d_PhysicsJointRotaryLimit___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsJointRotaryLimit *)olua_toobj(L, 1, "cc.PhysicsJointRotaryLimit");
    olua_push_cppobj(L, self, "cc.PhysicsJointRotaryLimit");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsJointRotaryLimit_construct1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** a */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** b */
    lua_Number arg3 = 0;       /** min */
    lua_Number arg4 = 0;       /** max */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.PhysicsBody");
    olua_check_cppobj(L, 2, (void **)&arg2, "cc.PhysicsBody");
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // static cocos2d::PhysicsJointRotaryLimit *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, float min, float max)
    cocos2d::PhysicsJointRotaryLimit *ret = cocos2d::PhysicsJointRotaryLimit::construct(arg1, arg2, (float)arg3, (float)arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsJointRotaryLimit");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointRotaryLimit_construct2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** a */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** b */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.PhysicsBody");
    olua_check_cppobj(L, 2, (void **)&arg2, "cc.PhysicsBody");

    // static cocos2d::PhysicsJointRotaryLimit *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b)
    cocos2d::PhysicsJointRotaryLimit *ret = cocos2d::PhysicsJointRotaryLimit::construct(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsJointRotaryLimit");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointRotaryLimit_construct(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 1, "cc.PhysicsBody")) && (olua_is_cppobj(L, 2, "cc.PhysicsBody"))) {
            // static cocos2d::PhysicsJointRotaryLimit *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b)
            return _cocos2d_PhysicsJointRotaryLimit_construct2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_cppobj(L, 1, "cc.PhysicsBody")) && (olua_is_cppobj(L, 2, "cc.PhysicsBody")) && (olua_is_number(L, 3)) && (olua_is_number(L, 4))) {
            // static cocos2d::PhysicsJointRotaryLimit *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, float min, float max)
            return _cocos2d_PhysicsJointRotaryLimit_construct1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsJointRotaryLimit::construct' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsJointRotaryLimit_createConstraints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRotaryLimit *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointRotaryLimit");

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointRotaryLimit");

    // float getMax()
    float ret = self->getMax();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointRotaryLimit_getMin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRotaryLimit *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointRotaryLimit");

    // float getMin()
    float ret = self->getMin();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointRotaryLimit_setMax(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRotaryLimit *self = nullptr;
    lua_Number arg1 = 0;       /** max */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointRotaryLimit");
    olua_check_number(L, 2, &arg1);

    // void setMax(float max)
    self->setMax((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJointRotaryLimit_setMin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRotaryLimit *self = nullptr;
    lua_Number arg1 = 0;       /** min */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointRotaryLimit");
    olua_check_number(L, 2, &arg1);

    // void setMin(float min)
    self->setMin((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_PhysicsJointRotaryLimit(lua_State *L)
{
    oluacls_class(L, "cc.PhysicsJointRotaryLimit", "cc.PhysicsJoint");
    oluacls_func(L, "__move", _cocos2d_PhysicsJointRotaryLimit___move);
    oluacls_func(L, "construct", _cocos2d_PhysicsJointRotaryLimit_construct);
    oluacls_func(L, "createConstraints", _cocos2d_PhysicsJointRotaryLimit_createConstraints);
    oluacls_func(L, "getMax", _cocos2d_PhysicsJointRotaryLimit_getMax);
    oluacls_func(L, "getMin", _cocos2d_PhysicsJointRotaryLimit_getMin);
    oluacls_func(L, "setMax", _cocos2d_PhysicsJointRotaryLimit_setMax);
    oluacls_func(L, "setMin", _cocos2d_PhysicsJointRotaryLimit_setMin);
    oluacls_prop(L, "max", _cocos2d_PhysicsJointRotaryLimit_getMax, _cocos2d_PhysicsJointRotaryLimit_setMax);
    oluacls_prop(L, "min", _cocos2d_PhysicsJointRotaryLimit_getMin, _cocos2d_PhysicsJointRotaryLimit_setMin);

    olua_registerluatype<cocos2d::PhysicsJointRotaryLimit>(L, "cc.PhysicsJointRotaryLimit");

    return 1;
}

static int _cocos2d_PhysicsJointRotarySpring___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsJointRotarySpring *)olua_toobj(L, 1, "cc.PhysicsJointRotarySpring");
    olua_push_cppobj(L, self, "cc.PhysicsJointRotarySpring");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsJointRotarySpring_construct(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** a */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** b */
    lua_Number arg3 = 0;       /** stiffness */
    lua_Number arg4 = 0;       /** damping */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.PhysicsBody");
    olua_check_cppobj(L, 2, (void **)&arg2, "cc.PhysicsBody");
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // static cocos2d::PhysicsJointRotarySpring *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, float stiffness, float damping)
    cocos2d::PhysicsJointRotarySpring *ret = cocos2d::PhysicsJointRotarySpring::construct(arg1, arg2, (float)arg3, (float)arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsJointRotarySpring");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointRotarySpring_createConstraints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRotarySpring *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointRotarySpring");

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointRotarySpring");

    // float getDamping()
    float ret = self->getDamping();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointRotarySpring_getRestAngle(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRotarySpring *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointRotarySpring");

    // float getRestAngle()
    float ret = self->getRestAngle();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointRotarySpring_getStiffness(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRotarySpring *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointRotarySpring");

    // float getStiffness()
    float ret = self->getStiffness();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointRotarySpring_setDamping(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRotarySpring *self = nullptr;
    lua_Number arg1 = 0;       /** damping */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointRotarySpring");
    olua_check_number(L, 2, &arg1);

    // void setDamping(float damping)
    self->setDamping((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJointRotarySpring_setRestAngle(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRotarySpring *self = nullptr;
    lua_Number arg1 = 0;       /** restAngle */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointRotarySpring");
    olua_check_number(L, 2, &arg1);

    // void setRestAngle(float restAngle)
    self->setRestAngle((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJointRotarySpring_setStiffness(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointRotarySpring *self = nullptr;
    lua_Number arg1 = 0;       /** stiffness */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointRotarySpring");
    olua_check_number(L, 2, &arg1);

    // void setStiffness(float stiffness)
    self->setStiffness((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_PhysicsJointRotarySpring(lua_State *L)
{
    oluacls_class(L, "cc.PhysicsJointRotarySpring", "cc.PhysicsJoint");
    oluacls_func(L, "__move", _cocos2d_PhysicsJointRotarySpring___move);
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

    olua_registerluatype<cocos2d::PhysicsJointRotarySpring>(L, "cc.PhysicsJointRotarySpring");

    return 1;
}

static int _cocos2d_PhysicsJointSpring___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsJointSpring *)olua_toobj(L, 1, "cc.PhysicsJointSpring");
    olua_push_cppobj(L, self, "cc.PhysicsJointSpring");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsJointSpring_construct(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsBody *arg1 = nullptr;       /** a */
    cocos2d::PhysicsBody *arg2 = nullptr;       /** b */
    cocos2d::Vec2 arg3;       /** anchr1 */
    cocos2d::Vec2 arg4;       /** anchr2 */
    lua_Number arg5 = 0;       /** stiffness */
    lua_Number arg6 = 0;       /** damping */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.PhysicsBody");
    olua_check_cppobj(L, 2, (void **)&arg2, "cc.PhysicsBody");
    auto_olua_check_cocos2d_Vec2(L, 3, &arg3);
    auto_olua_check_cocos2d_Vec2(L, 4, &arg4);
    olua_check_number(L, 5, &arg5);
    olua_check_number(L, 6, &arg6);

    // static cocos2d::PhysicsJointSpring *construct(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b, const cocos2d::Vec2 &anchr1, const cocos2d::Vec2 &anchr2, float stiffness, float damping)
    cocos2d::PhysicsJointSpring *ret = cocos2d::PhysicsJointSpring::construct(arg1, arg2, arg3, arg4, (float)arg5, (float)arg6);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsJointSpring");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointSpring_createConstraints(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointSpring *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointSpring");

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointSpring");

    // cocos2d::Vec2 getAnchr1()
    cocos2d::Vec2 ret = self->getAnchr1();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointSpring_getAnchr2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointSpring *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointSpring");

    // cocos2d::Vec2 getAnchr2()
    cocos2d::Vec2 ret = self->getAnchr2();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointSpring_getDamping(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointSpring *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointSpring");

    // float getDamping()
    float ret = self->getDamping();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointSpring_getRestLength(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointSpring *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointSpring");

    // float getRestLength()
    float ret = self->getRestLength();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointSpring_getStiffness(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointSpring *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointSpring");

    // float getStiffness()
    float ret = self->getStiffness();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsJointSpring_setAnchr1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointSpring *self = nullptr;
    cocos2d::Vec2 arg1;       /** anchr1 */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointSpring");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointSpring");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void setAnchr2(const cocos2d::Vec2 &anchr2)
    self->setAnchr2(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJointSpring_setDamping(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointSpring *self = nullptr;
    lua_Number arg1 = 0;       /** damping */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointSpring");
    olua_check_number(L, 2, &arg1);

    // void setDamping(float damping)
    self->setDamping((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJointSpring_setRestLength(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointSpring *self = nullptr;
    lua_Number arg1 = 0;       /** restLength */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointSpring");
    olua_check_number(L, 2, &arg1);

    // void setRestLength(float restLength)
    self->setRestLength((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsJointSpring_setStiffness(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsJointSpring *self = nullptr;
    lua_Number arg1 = 0;       /** stiffness */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsJointSpring");
    olua_check_number(L, 2, &arg1);

    // void setStiffness(float stiffness)
    self->setStiffness((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_PhysicsJointSpring(lua_State *L)
{
    oluacls_class(L, "cc.PhysicsJointSpring", "cc.PhysicsJoint");
    oluacls_func(L, "__move", _cocos2d_PhysicsJointSpring___move);
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

    olua_registerluatype<cocos2d::PhysicsJointSpring>(L, "cc.PhysicsJointSpring");

    return 1;
}

static int luaopen_cocos2d_PhysicsShape_Type(lua_State *L)
{
    oluacls_class(L, "cc.PhysicsShape.Type", nullptr);
    oluacls_const_integer(L, "BOX", (lua_Integer)cocos2d::PhysicsShape::Type::BOX);
    oluacls_const_integer(L, "CIRCLE", (lua_Integer)cocos2d::PhysicsShape::Type::CIRCLE);
    oluacls_const_integer(L, "EDGEBOX", (lua_Integer)cocos2d::PhysicsShape::Type::EDGEBOX);
    oluacls_const_integer(L, "EDGECHAIN", (lua_Integer)cocos2d::PhysicsShape::Type::EDGECHAIN);
    oluacls_const_integer(L, "EDGEPOLYGEN", (lua_Integer)cocos2d::PhysicsShape::Type::EDGEPOLYGEN);
    oluacls_const_integer(L, "EDGEPOLYGON", (lua_Integer)cocos2d::PhysicsShape::Type::EDGEPOLYGON);
    oluacls_const_integer(L, "EDGESEGMENT", (lua_Integer)cocos2d::PhysicsShape::Type::EDGESEGMENT);
    oluacls_const_integer(L, "POLYGEN", (lua_Integer)cocos2d::PhysicsShape::Type::POLYGEN);
    oluacls_const_integer(L, "POLYGON", (lua_Integer)cocos2d::PhysicsShape::Type::POLYGON);
    oluacls_const_integer(L, "UNKNOWN", (lua_Integer)cocos2d::PhysicsShape::Type::UNKNOWN);

    olua_registerluatype<cocos2d::PhysicsShape::Type>(L, "cc.PhysicsShape.Type");

    return 1;
}

static int _cocos2d_PhysicsShape___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsShape *)olua_toobj(L, 1, "cc.PhysicsShape");
    olua_push_cppobj(L, self, "cc.PhysicsShape");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsShape_calculateDefaultMoment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");

    // float calculateDefaultMoment()
    float ret = self->calculateDefaultMoment();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_containsPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;
    cocos2d::Vec2 arg1;       /** point */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

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

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");

    // float getArea()
    float ret = self->getArea();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getBody(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");

    // cocos2d::PhysicsBody *getBody()
    cocos2d::PhysicsBody *ret = self->getBody();
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getCategoryBitmask(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");

    // int getCategoryBitmask()
    int ret = self->getCategoryBitmask();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getCenter(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");

    // cocos2d::Vec2 getCenter()
    cocos2d::Vec2 ret = self->getCenter();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getCollisionBitmask(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");

    // int getCollisionBitmask()
    int ret = self->getCollisionBitmask();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getContactTestBitmask(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");

    // int getContactTestBitmask()
    int ret = self->getContactTestBitmask();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getDensity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");

    // float getDensity()
    float ret = self->getDensity();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getFriction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");

    // float getFriction()
    float ret = self->getFriction();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getGroup(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");

    // int getGroup()
    int ret = self->getGroup();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getMass(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");

    // float getMass()
    float ret = self->getMass();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getMaterial(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");

    // const cocos2d::PhysicsMaterial &getMaterial()
    const cocos2d::PhysicsMaterial &ret = self->getMaterial();
    int num_ret = auto_olua_push_cocos2d_PhysicsMaterial(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getMoment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");

    // float getMoment()
    float ret = self->getMoment();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getOffset(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");

    // cocos2d::Vec2 getOffset()
    cocos2d::Vec2 ret = self->getOffset();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getRestitution(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");

    // float getRestitution()
    float ret = self->getRestitution();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getTag(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");

    // int getTag()
    int ret = self->getTag();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_getType(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");

    // cocos2d::PhysicsShape::Type getType()
    cocos2d::PhysicsShape::Type ret = self->getType();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_isSensor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");

    // bool isSensor()
    bool ret = self->isSensor();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShape_setCategoryBitmask(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;
    lua_Integer arg1 = 0;       /** bitmask */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");
    olua_check_int(L, 2, &arg1);

    // void setCategoryBitmask(int bitmask)
    self->setCategoryBitmask((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsShape_setCollisionBitmask(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;
    lua_Integer arg1 = 0;       /** bitmask */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");
    olua_check_int(L, 2, &arg1);

    // void setCollisionBitmask(int bitmask)
    self->setCollisionBitmask((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsShape_setContactTestBitmask(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;
    lua_Integer arg1 = 0;       /** bitmask */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");
    olua_check_int(L, 2, &arg1);

    // void setContactTestBitmask(int bitmask)
    self->setContactTestBitmask((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsShape_setDensity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;
    lua_Number arg1 = 0;       /** density */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");
    olua_check_number(L, 2, &arg1);

    // void setDensity(float density)
    self->setDensity((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsShape_setFriction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;
    lua_Number arg1 = 0;       /** friction */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");
    olua_check_number(L, 2, &arg1);

    // void setFriction(float friction)
    self->setFriction((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsShape_setGroup(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;
    lua_Integer arg1 = 0;       /** group */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");
    olua_check_int(L, 2, &arg1);

    // void setGroup(int group)
    self->setGroup((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsShape_setMass(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;
    lua_Number arg1 = 0;       /** mass */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");
    olua_check_number(L, 2, &arg1);

    // void setMass(float mass)
    self->setMass((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsShape_setMaterial(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;
    cocos2d::PhysicsMaterial arg1;       /** material */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");
    auto_olua_check_cocos2d_PhysicsMaterial(L, 2, &arg1);

    // void setMaterial(const cocos2d::PhysicsMaterial &material)
    self->setMaterial(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsShape_setMoment(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;
    lua_Number arg1 = 0;       /** moment */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");
    olua_check_number(L, 2, &arg1);

    // void setMoment(float moment)
    self->setMoment((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsShape_setRestitution(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;
    lua_Number arg1 = 0;       /** restitution */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");
    olua_check_number(L, 2, &arg1);

    // void setRestitution(float restitution)
    self->setRestitution((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsShape_setSensor(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShape *self = nullptr;
    bool arg1 = false;       /** sensor */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");
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
    lua_Integer arg1 = 0;       /** tag */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShape");
    olua_check_int(L, 2, &arg1);

    // void setTag(int tag)
    self->setTag((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_PhysicsShape(lua_State *L)
{
    oluacls_class(L, "cc.PhysicsShape", "cc.Ref");
    oluacls_func(L, "__move", _cocos2d_PhysicsShape___move);
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
    oluacls_func(L, "getRestitution", _cocos2d_PhysicsShape_getRestitution);
    oluacls_func(L, "getTag", _cocos2d_PhysicsShape_getTag);
    oluacls_func(L, "getType", _cocos2d_PhysicsShape_getType);
    oluacls_func(L, "isSensor", _cocos2d_PhysicsShape_isSensor);
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

    olua_registerluatype<cocos2d::PhysicsShape>(L, "cc.PhysicsShape");

    return 1;
}

static int _cocos2d_PhysicsShapePolygon___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsShapePolygon *)olua_toobj(L, 1, "cc.PhysicsShapePolygon");
    olua_push_cppobj(L, self, "cc.PhysicsShapePolygon");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsShapePolygon_getPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShapePolygon *self = nullptr;
    lua_Integer arg1 = 0;       /** i */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShapePolygon");
    olua_check_int(L, 2, &arg1);

    // cocos2d::Vec2 getPoint(int i)
    cocos2d::Vec2 ret = self->getPoint((int)arg1);
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapePolygon_getPointsCount(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShapePolygon *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShapePolygon");

    // int getPointsCount()
    int ret = self->getPointsCount();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_PhysicsShapePolygon(lua_State *L)
{
    oluacls_class(L, "cc.PhysicsShapePolygon", "cc.PhysicsShape");
    oluacls_func(L, "__move", _cocos2d_PhysicsShapePolygon___move);
    oluacls_func(L, "getPoint", _cocos2d_PhysicsShapePolygon_getPoint);
    oluacls_func(L, "getPointsCount", _cocos2d_PhysicsShapePolygon_getPointsCount);
    oluacls_prop(L, "pointsCount", _cocos2d_PhysicsShapePolygon_getPointsCount, nullptr);

    olua_registerluatype<cocos2d::PhysicsShapePolygon>(L, "cc.PhysicsShapePolygon");

    return 1;
}

static int _cocos2d_PhysicsShapeEdgePolygon___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsShapeEdgePolygon *)olua_toobj(L, 1, "cc.PhysicsShapeEdgePolygon");
    olua_push_cppobj(L, self, "cc.PhysicsShapeEdgePolygon");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsShapeEdgePolygon_getPointsCount(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShapeEdgePolygon *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShapeEdgePolygon");

    // int getPointsCount()
    int ret = self->getPointsCount();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_PhysicsShapeEdgePolygon(lua_State *L)
{
    oluacls_class(L, "cc.PhysicsShapeEdgePolygon", "cc.PhysicsShape");
    oluacls_func(L, "__move", _cocos2d_PhysicsShapeEdgePolygon___move);
    oluacls_func(L, "getPointsCount", _cocos2d_PhysicsShapeEdgePolygon_getPointsCount);
    oluacls_prop(L, "pointsCount", _cocos2d_PhysicsShapeEdgePolygon_getPointsCount, nullptr);

    olua_registerluatype<cocos2d::PhysicsShapeEdgePolygon>(L, "cc.PhysicsShapeEdgePolygon");

    return 1;
}

static int _cocos2d_PhysicsShapeBox___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsShapeBox *)olua_toobj(L, 1, "cc.PhysicsShapeBox");
    olua_push_cppobj(L, self, "cc.PhysicsShapeBox");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsShapeBox_create1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    cocos2d::PhysicsMaterial arg2;       /** material */
    cocos2d::Vec2 arg3;       /** offset */
    lua_Number arg4 = 0;       /** radius */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);
    auto_olua_check_cocos2d_PhysicsMaterial(L, 2, &arg2);
    auto_olua_check_cocos2d_Vec2(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // static cocos2d::PhysicsShapeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset, @optional float radius)
    cocos2d::PhysicsShapeBox *ret = cocos2d::PhysicsShapeBox::create(arg1, arg2, arg3, (float)arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsShapeBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeBox_create2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);

    // static cocos2d::PhysicsShapeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset, @optional float radius)
    cocos2d::PhysicsShapeBox *ret = cocos2d::PhysicsShapeBox::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsShapeBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeBox_create3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    cocos2d::PhysicsMaterial arg2;       /** material */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);
    auto_olua_check_cocos2d_PhysicsMaterial(L, 2, &arg2);

    // static cocos2d::PhysicsShapeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset, @optional float radius)
    cocos2d::PhysicsShapeBox *ret = cocos2d::PhysicsShapeBox::create(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsShapeBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeBox_create4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    cocos2d::PhysicsMaterial arg2;       /** material */
    cocos2d::Vec2 arg3;       /** offset */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);
    auto_olua_check_cocos2d_PhysicsMaterial(L, 2, &arg2);
    auto_olua_check_cocos2d_Vec2(L, 3, &arg3);

    // static cocos2d::PhysicsShapeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset, @optional float radius)
    cocos2d::PhysicsShapeBox *ret = cocos2d::PhysicsShapeBox::create(arg1, arg2, arg3);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsShapeBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeBox_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((auto_olua_is_cocos2d_Size(L, 1))) {
            // static cocos2d::PhysicsShapeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset, @optional float radius)
            return _cocos2d_PhysicsShapeBox_create2(L);
        // }
    }

    if (num_args == 2) {
        // if ((auto_olua_is_cocos2d_Size(L, 1)) && (auto_olua_is_cocos2d_PhysicsMaterial(L, 2))) {
            // static cocos2d::PhysicsShapeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset, @optional float radius)
            return _cocos2d_PhysicsShapeBox_create3(L);
        // }
    }

    if (num_args == 3) {
        // if ((auto_olua_is_cocos2d_Size(L, 1)) && (auto_olua_is_cocos2d_PhysicsMaterial(L, 2)) && (auto_olua_is_cocos2d_Vec2(L, 3))) {
            // static cocos2d::PhysicsShapeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset, @optional float radius)
            return _cocos2d_PhysicsShapeBox_create4(L);
        // }
    }

    if (num_args == 4) {
        // if ((auto_olua_is_cocos2d_Size(L, 1)) && (auto_olua_is_cocos2d_PhysicsMaterial(L, 2)) && (auto_olua_is_cocos2d_Vec2(L, 3)) && (olua_is_number(L, 4))) {
            // static cocos2d::PhysicsShapeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset, @optional float radius)
            return _cocos2d_PhysicsShapeBox_create1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsShapeBox::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsShapeBox_getSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShapeBox *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShapeBox");

    // cocos2d::Size getSize()
    cocos2d::Size ret = self->getSize();
    int num_ret = auto_olua_push_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_PhysicsShapeBox(lua_State *L)
{
    oluacls_class(L, "cc.PhysicsShapeBox", "cc.PhysicsShapePolygon");
    oluacls_func(L, "__move", _cocos2d_PhysicsShapeBox___move);
    oluacls_func(L, "create", _cocos2d_PhysicsShapeBox_create);
    oluacls_func(L, "getSize", _cocos2d_PhysicsShapeBox_getSize);
    oluacls_prop(L, "size", _cocos2d_PhysicsShapeBox_getSize, nullptr);

    olua_registerluatype<cocos2d::PhysicsShapeBox>(L, "cc.PhysicsShapeBox");

    return 1;
}

static int _cocos2d_PhysicsShapeCircle___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsShapeCircle *)olua_toobj(L, 1, "cc.PhysicsShapeCircle");
    olua_push_cppobj(L, self, "cc.PhysicsShapeCircle");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsShapeCircle_calculateArea(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** radius */

    olua_check_number(L, 1, &arg1);

    // static float calculateArea(float radius)
    float ret = cocos2d::PhysicsShapeCircle::calculateArea((float)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeCircle_calculateMoment1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** mass */
    lua_Number arg2 = 0;       /** radius */
    cocos2d::Vec2 arg3;       /** offset */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    auto_olua_check_cocos2d_Vec2(L, 3, &arg3);

    // static float calculateMoment(float mass, float radius, @optional const cocos2d::Vec2 &offset)
    float ret = cocos2d::PhysicsShapeCircle::calculateMoment((float)arg1, (float)arg2, arg3);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeCircle_calculateMoment2(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** mass */
    lua_Number arg2 = 0;       /** radius */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static float calculateMoment(float mass, float radius, @optional const cocos2d::Vec2 &offset)
    float ret = cocos2d::PhysicsShapeCircle::calculateMoment((float)arg1, (float)arg2);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeCircle_calculateMoment(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2))) {
            // static float calculateMoment(float mass, float radius, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsShapeCircle_calculateMoment2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (auto_olua_is_cocos2d_Vec2(L, 3))) {
            // static float calculateMoment(float mass, float radius, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsShapeCircle_calculateMoment1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsShapeCircle::calculateMoment' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsShapeCircle_create1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** radius */
    cocos2d::PhysicsMaterial arg2;       /** material */
    cocos2d::Vec2 arg3;       /** offset */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_PhysicsMaterial(L, 2, &arg2);
    auto_olua_check_cocos2d_Vec2(L, 3, &arg3);

    // static cocos2d::PhysicsShapeCircle *create(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsShapeCircle *ret = cocos2d::PhysicsShapeCircle::create((float)arg1, arg2, arg3);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsShapeCircle");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeCircle_create2(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** radius */

    olua_check_number(L, 1, &arg1);

    // static cocos2d::PhysicsShapeCircle *create(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsShapeCircle *ret = cocos2d::PhysicsShapeCircle::create((float)arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsShapeCircle");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeCircle_create3(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** radius */
    cocos2d::PhysicsMaterial arg2;       /** material */

    olua_check_number(L, 1, &arg1);
    auto_olua_check_cocos2d_PhysicsMaterial(L, 2, &arg2);

    // static cocos2d::PhysicsShapeCircle *create(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsShapeCircle *ret = cocos2d::PhysicsShapeCircle::create((float)arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsShapeCircle");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeCircle_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_number(L, 1))) {
            // static cocos2d::PhysicsShapeCircle *create(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsShapeCircle_create2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_number(L, 1)) && (auto_olua_is_cocos2d_PhysicsMaterial(L, 2))) {
            // static cocos2d::PhysicsShapeCircle *create(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsShapeCircle_create3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (auto_olua_is_cocos2d_PhysicsMaterial(L, 2)) && (auto_olua_is_cocos2d_Vec2(L, 3))) {
            // static cocos2d::PhysicsShapeCircle *create(float radius, @optional const cocos2d::PhysicsMaterial &material, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsShapeCircle_create1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsShapeCircle::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsShapeCircle_getRadius(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShapeCircle *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShapeCircle");

    // float getRadius()
    float ret = self->getRadius();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_PhysicsShapeCircle(lua_State *L)
{
    oluacls_class(L, "cc.PhysicsShapeCircle", "cc.PhysicsShape");
    oluacls_func(L, "__move", _cocos2d_PhysicsShapeCircle___move);
    oluacls_func(L, "calculateArea", _cocos2d_PhysicsShapeCircle_calculateArea);
    oluacls_func(L, "calculateMoment", _cocos2d_PhysicsShapeCircle_calculateMoment);
    oluacls_func(L, "create", _cocos2d_PhysicsShapeCircle_create);
    oluacls_func(L, "getRadius", _cocos2d_PhysicsShapeCircle_getRadius);
    oluacls_prop(L, "radius", _cocos2d_PhysicsShapeCircle_getRadius, nullptr);

    olua_registerluatype<cocos2d::PhysicsShapeCircle>(L, "cc.PhysicsShapeCircle");

    return 1;
}

static int _cocos2d_PhysicsShapeEdgeBox___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsShapeEdgeBox *)olua_toobj(L, 1, "cc.PhysicsShapeEdgeBox");
    olua_push_cppobj(L, self, "cc.PhysicsShapeEdgeBox");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsShapeEdgeBox_create1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    cocos2d::PhysicsMaterial arg2;       /** material */
    lua_Number arg3 = 0;       /** border */
    cocos2d::Vec2 arg4;       /** offset */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);
    auto_olua_check_cocos2d_PhysicsMaterial(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    auto_olua_check_cocos2d_Vec2(L, 4, &arg4);

    // static cocos2d::PhysicsShapeEdgeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsShapeEdgeBox *ret = cocos2d::PhysicsShapeEdgeBox::create(arg1, arg2, (float)arg3, arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsShapeEdgeBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeEdgeBox_create2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);

    // static cocos2d::PhysicsShapeEdgeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsShapeEdgeBox *ret = cocos2d::PhysicsShapeEdgeBox::create(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsShapeEdgeBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeEdgeBox_create3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    cocos2d::PhysicsMaterial arg2;       /** material */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);
    auto_olua_check_cocos2d_PhysicsMaterial(L, 2, &arg2);

    // static cocos2d::PhysicsShapeEdgeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsShapeEdgeBox *ret = cocos2d::PhysicsShapeEdgeBox::create(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsShapeEdgeBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeEdgeBox_create4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    cocos2d::PhysicsMaterial arg2;       /** material */
    lua_Number arg3 = 0;       /** border */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);
    auto_olua_check_cocos2d_PhysicsMaterial(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static cocos2d::PhysicsShapeEdgeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
    cocos2d::PhysicsShapeEdgeBox *ret = cocos2d::PhysicsShapeEdgeBox::create(arg1, arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsShapeEdgeBox");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeEdgeBox_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((auto_olua_is_cocos2d_Size(L, 1))) {
            // static cocos2d::PhysicsShapeEdgeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsShapeEdgeBox_create2(L);
        // }
    }

    if (num_args == 2) {
        // if ((auto_olua_is_cocos2d_Size(L, 1)) && (auto_olua_is_cocos2d_PhysicsMaterial(L, 2))) {
            // static cocos2d::PhysicsShapeEdgeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsShapeEdgeBox_create3(L);
        // }
    }

    if (num_args == 3) {
        // if ((auto_olua_is_cocos2d_Size(L, 1)) && (auto_olua_is_cocos2d_PhysicsMaterial(L, 2)) && (olua_is_number(L, 3))) {
            // static cocos2d::PhysicsShapeEdgeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsShapeEdgeBox_create4(L);
        // }
    }

    if (num_args == 4) {
        // if ((auto_olua_is_cocos2d_Size(L, 1)) && (auto_olua_is_cocos2d_PhysicsMaterial(L, 2)) && (olua_is_number(L, 3)) && (auto_olua_is_cocos2d_Vec2(L, 4))) {
            // static cocos2d::PhysicsShapeEdgeBox *create(const cocos2d::Size &size, @optional const cocos2d::PhysicsMaterial &material, @optional float border, @optional const cocos2d::Vec2 &offset)
            return _cocos2d_PhysicsShapeEdgeBox_create1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsShapeEdgeBox::create' not support '%d' arguments", num_args);

    return 0;
}

static int luaopen_cocos2d_PhysicsShapeEdgeBox(lua_State *L)
{
    oluacls_class(L, "cc.PhysicsShapeEdgeBox", "cc.PhysicsShapeEdgePolygon");
    oluacls_func(L, "__move", _cocos2d_PhysicsShapeEdgeBox___move);
    oluacls_func(L, "create", _cocos2d_PhysicsShapeEdgeBox_create);

    olua_registerluatype<cocos2d::PhysicsShapeEdgeBox>(L, "cc.PhysicsShapeEdgeBox");

    return 1;
}

static int _cocos2d_PhysicsShapeEdgeChain___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsShapeEdgeChain *)olua_toobj(L, 1, "cc.PhysicsShapeEdgeChain");
    olua_push_cppobj(L, self, "cc.PhysicsShapeEdgeChain");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsShapeEdgeChain_getPointsCount(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShapeEdgeChain *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShapeEdgeChain");

    // int getPointsCount()
    int ret = self->getPointsCount();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_PhysicsShapeEdgeChain(lua_State *L)
{
    oluacls_class(L, "cc.PhysicsShapeEdgeChain", "cc.PhysicsShape");
    oluacls_func(L, "__move", _cocos2d_PhysicsShapeEdgeChain___move);
    oluacls_func(L, "getPointsCount", _cocos2d_PhysicsShapeEdgeChain_getPointsCount);
    oluacls_prop(L, "pointsCount", _cocos2d_PhysicsShapeEdgeChain_getPointsCount, nullptr);

    olua_registerluatype<cocos2d::PhysicsShapeEdgeChain>(L, "cc.PhysicsShapeEdgeChain");

    return 1;
}

static int _cocos2d_PhysicsShapeEdgeSegment___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsShapeEdgeSegment *)olua_toobj(L, 1, "cc.PhysicsShapeEdgeSegment");
    olua_push_cppobj(L, self, "cc.PhysicsShapeEdgeSegment");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsShapeEdgeSegment_create1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 arg1;       /** a */
    cocos2d::Vec2 arg2;       /** b */
    cocos2d::PhysicsMaterial arg3;       /** material */
    lua_Number arg4 = 0;       /** border */

    auto_olua_check_cocos2d_Vec2(L, 1, &arg1);
    auto_olua_check_cocos2d_Vec2(L, 2, &arg2);
    auto_olua_check_cocos2d_PhysicsMaterial(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // static cocos2d::PhysicsShapeEdgeSegment *create(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
    cocos2d::PhysicsShapeEdgeSegment *ret = cocos2d::PhysicsShapeEdgeSegment::create(arg1, arg2, arg3, (float)arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsShapeEdgeSegment");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeEdgeSegment_create2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 arg1;       /** a */
    cocos2d::Vec2 arg2;       /** b */

    auto_olua_check_cocos2d_Vec2(L, 1, &arg1);
    auto_olua_check_cocos2d_Vec2(L, 2, &arg2);

    // static cocos2d::PhysicsShapeEdgeSegment *create(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
    cocos2d::PhysicsShapeEdgeSegment *ret = cocos2d::PhysicsShapeEdgeSegment::create(arg1, arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsShapeEdgeSegment");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeEdgeSegment_create3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 arg1;       /** a */
    cocos2d::Vec2 arg2;       /** b */
    cocos2d::PhysicsMaterial arg3;       /** material */

    auto_olua_check_cocos2d_Vec2(L, 1, &arg1);
    auto_olua_check_cocos2d_Vec2(L, 2, &arg2);
    auto_olua_check_cocos2d_PhysicsMaterial(L, 3, &arg3);

    // static cocos2d::PhysicsShapeEdgeSegment *create(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
    cocos2d::PhysicsShapeEdgeSegment *ret = cocos2d::PhysicsShapeEdgeSegment::create(arg1, arg2, arg3);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsShapeEdgeSegment");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeEdgeSegment_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((auto_olua_is_cocos2d_Vec2(L, 1)) && (auto_olua_is_cocos2d_Vec2(L, 2))) {
            // static cocos2d::PhysicsShapeEdgeSegment *create(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
            return _cocos2d_PhysicsShapeEdgeSegment_create2(L);
        // }
    }

    if (num_args == 3) {
        // if ((auto_olua_is_cocos2d_Vec2(L, 1)) && (auto_olua_is_cocos2d_Vec2(L, 2)) && (auto_olua_is_cocos2d_PhysicsMaterial(L, 3))) {
            // static cocos2d::PhysicsShapeEdgeSegment *create(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
            return _cocos2d_PhysicsShapeEdgeSegment_create3(L);
        // }
    }

    if (num_args == 4) {
        // if ((auto_olua_is_cocos2d_Vec2(L, 1)) && (auto_olua_is_cocos2d_Vec2(L, 2)) && (auto_olua_is_cocos2d_PhysicsMaterial(L, 3)) && (olua_is_number(L, 4))) {
            // static cocos2d::PhysicsShapeEdgeSegment *create(const cocos2d::Vec2 &a, const cocos2d::Vec2 &b, @optional const cocos2d::PhysicsMaterial &material, @optional float border)
            return _cocos2d_PhysicsShapeEdgeSegment_create1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsShapeEdgeSegment::create' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsShapeEdgeSegment_getPointA(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShapeEdgeSegment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShapeEdgeSegment");

    // cocos2d::Vec2 getPointA()
    cocos2d::Vec2 ret = self->getPointA();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsShapeEdgeSegment_getPointB(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsShapeEdgeSegment *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsShapeEdgeSegment");

    // cocos2d::Vec2 getPointB()
    cocos2d::Vec2 ret = self->getPointB();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cocos2d_PhysicsShapeEdgeSegment(lua_State *L)
{
    oluacls_class(L, "cc.PhysicsShapeEdgeSegment", "cc.PhysicsShape");
    oluacls_func(L, "__move", _cocos2d_PhysicsShapeEdgeSegment___move);
    oluacls_func(L, "create", _cocos2d_PhysicsShapeEdgeSegment_create);
    oluacls_func(L, "getPointA", _cocos2d_PhysicsShapeEdgeSegment_getPointA);
    oluacls_func(L, "getPointB", _cocos2d_PhysicsShapeEdgeSegment_getPointB);
    oluacls_prop(L, "pointA", _cocos2d_PhysicsShapeEdgeSegment_getPointA, nullptr);
    oluacls_prop(L, "pointB", _cocos2d_PhysicsShapeEdgeSegment_getPointB, nullptr);

    olua_registerluatype<cocos2d::PhysicsShapeEdgeSegment>(L, "cc.PhysicsShapeEdgeSegment");

    return 1;
}

static int _cocos2d_PhysicsRayCastInfo___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsRayCastInfo *)olua_toobj(L, 1, "cc.PhysicsRayCastInfo");
    olua_push_cppobj(L, self, "cc.PhysicsRayCastInfo");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsRayCastInfo_get_contact(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsRayCastInfo *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsRayCastInfo");

    // cocos2d::Vec2 contact
    cocos2d::Vec2 ret = self->contact;
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsRayCastInfo_set_contact(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsRayCastInfo *self = nullptr;
    cocos2d::Vec2 arg1;       /** contact */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsRayCastInfo");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // cocos2d::Vec2 contact
    self->contact = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsRayCastInfo_get_data(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsRayCastInfo *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsRayCastInfo");

    // void *data
    void *ret = self->data;
    int num_ret = olua_push_obj(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsRayCastInfo_set_data(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsRayCastInfo *self = nullptr;
    void *arg1 = nullptr;       /** data */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsRayCastInfo");
    olua_check_obj(L, 2, (void **)&arg1, "void *");

    // void *data
    self->data = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsRayCastInfo_get_end(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsRayCastInfo *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsRayCastInfo");

    // cocos2d::Vec2 end
    cocos2d::Vec2 ret = self->end;
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsRayCastInfo_set_end(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsRayCastInfo *self = nullptr;
    cocos2d::Vec2 arg1;       /** end */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsRayCastInfo");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // cocos2d::Vec2 end
    self->end = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsRayCastInfo_get_fraction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsRayCastInfo *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsRayCastInfo");

    // float fraction
    float ret = self->fraction;
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsRayCastInfo_set_fraction(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsRayCastInfo *self = nullptr;
    lua_Number arg1 = 0;       /** fraction */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsRayCastInfo");
    olua_check_number(L, 2, &arg1);

    // float fraction
    self->fraction = (float)arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsRayCastInfo_get_normal(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsRayCastInfo *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsRayCastInfo");

    // cocos2d::Vec2 normal
    cocos2d::Vec2 ret = self->normal;
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsRayCastInfo_set_normal(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsRayCastInfo *self = nullptr;
    cocos2d::Vec2 arg1;       /** normal */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsRayCastInfo");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // cocos2d::Vec2 normal
    self->normal = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsRayCastInfo_get_shape(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsRayCastInfo *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsRayCastInfo");

    // cocos2d::PhysicsShape *shape
    cocos2d::PhysicsShape *ret = self->shape;
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsShape");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsRayCastInfo_set_shape(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsRayCastInfo *self = nullptr;
    cocos2d::PhysicsShape *arg1 = nullptr;       /** shape */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsRayCastInfo");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.PhysicsShape");

    // cocos2d::PhysicsShape *shape
    self->shape = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsRayCastInfo_get_start(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsRayCastInfo *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsRayCastInfo");

    // cocos2d::Vec2 start
    cocos2d::Vec2 ret = self->start;
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsRayCastInfo_set_start(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsRayCastInfo *self = nullptr;
    cocos2d::Vec2 arg1;       /** start */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsRayCastInfo");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // cocos2d::Vec2 start
    self->start = arg1;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_PhysicsRayCastInfo(lua_State *L)
{
    oluacls_class(L, "cc.PhysicsRayCastInfo", nullptr);
    oluacls_func(L, "__move", _cocos2d_PhysicsRayCastInfo___move);
    oluacls_prop(L, "contact", _cocos2d_PhysicsRayCastInfo_get_contact, _cocos2d_PhysicsRayCastInfo_set_contact);
    oluacls_prop(L, "data", _cocos2d_PhysicsRayCastInfo_get_data, _cocos2d_PhysicsRayCastInfo_set_data);
    oluacls_prop(L, "end", _cocos2d_PhysicsRayCastInfo_get_end, _cocos2d_PhysicsRayCastInfo_set_end);
    oluacls_prop(L, "fraction", _cocos2d_PhysicsRayCastInfo_get_fraction, _cocos2d_PhysicsRayCastInfo_set_fraction);
    oluacls_prop(L, "normal", _cocos2d_PhysicsRayCastInfo_get_normal, _cocos2d_PhysicsRayCastInfo_set_normal);
    oluacls_prop(L, "shape", _cocos2d_PhysicsRayCastInfo_get_shape, _cocos2d_PhysicsRayCastInfo_set_shape);
    oluacls_prop(L, "start", _cocos2d_PhysicsRayCastInfo_get_start, _cocos2d_PhysicsRayCastInfo_set_start);

    olua_registerluatype<cocos2d::PhysicsRayCastInfo>(L, "cc.PhysicsRayCastInfo");

    return 1;
}

static int _cocos2d_PhysicsWorld___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::PhysicsWorld *)olua_toobj(L, 1, "cc.PhysicsWorld");
    olua_push_cppobj(L, self, "cc.PhysicsWorld");

    olua_endinvoke(L);

    return 1;
}

static int _cocos2d_PhysicsWorld_addJoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    cocos2d::PhysicsJoint *arg1 = nullptr;       /** joint */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.PhysicsJoint");

    // void addJoint(cocos2d::PhysicsJoint *joint)
    self->addJoint(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_getAllBodies(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");

    // const Vector<cocos2d::PhysicsBody *> &getAllBodies()
    const cocos2d::Vector<cocos2d::PhysicsBody *> &ret = self->getAllBodies();
    int num_ret = manual_olua_push_cocos2d_Vector(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsWorld_getBody(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    lua_Integer arg1 = 0;       /** tag */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");
    olua_check_int(L, 2, &arg1);

    // cocos2d::PhysicsBody *getBody(int tag)
    cocos2d::PhysicsBody *ret = self->getBody((int)arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsBody");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsWorld_getDebugDrawMask(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");

    // int getDebugDrawMask()
    int ret = self->getDebugDrawMask();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsWorld_getFixedUpdateRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");

    // int getFixedUpdateRate()
    int ret = self->getFixedUpdateRate();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsWorld_getGravity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");

    // cocos2d::Vec2 getGravity()
    cocos2d::Vec2 ret = self->getGravity();
    int num_ret = auto_olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsWorld_getScene(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");

    // cocos2d::Scene &getScene()
    cocos2d::Scene &ret = self->getScene();
    int num_ret = olua_push_cppobj(L, &ret, "cc.Scene");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsWorld_getShape(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    cocos2d::Vec2 arg1;       /** point */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // cocos2d::PhysicsShape *getShape(const cocos2d::Vec2 &point)
    cocos2d::PhysicsShape *ret = self->getShape(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.PhysicsShape");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsWorld_getShapes(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    cocos2d::Vec2 arg1;       /** point */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // Vector<cocos2d::PhysicsShape *> getShapes(const cocos2d::Vec2 &point)
    cocos2d::Vector<cocos2d::PhysicsShape *> ret = self->getShapes(arg1);
    int num_ret = manual_olua_push_cocos2d_Vector(L, ret, "cc.PhysicsShape");

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsWorld_getSpeed(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");

    // float getSpeed()
    float ret = self->getSpeed();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsWorld_getSubsteps(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");

    // int getSubsteps()
    int ret = self->getSubsteps();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsWorld_getUpdateRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");

    // int getUpdateRate()
    int ret = self->getUpdateRate();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cocos2d_PhysicsWorld_isAutoStep(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");

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
    std::function<bool(cocos2d::PhysicsWorld &, cocos2d::PhysicsShape &, void *)> arg1;       /** func */
    cocos2d::Vec2 arg2;       /** point */
    void *arg3 = nullptr;       /** data */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");
    auto_olua_check_cocos2d_Vec2(L, 3, &arg2);
    olua_check_obj(L, 4, (void **)&arg3, "void *");

    void *cb_store = (void *)self;
    std::string cb_tag = "queryPoint";
    std::string cb_name = olua_setcallback(L, cb_store, cb_tag.c_str(), 2, OLUA_TAG_REPLACE);
    lua_Integer cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](cocos2d::PhysicsWorld &arg1, cocos2d::PhysicsShape &arg2, void *arg3) {
        lua_State *L = olua_mainthread(NULL);
        bool ret = false;       
        if (L != NULL && olua_context(L) == cb_ctx) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_cppobj(L, &arg1, "cc.PhysicsWorld");
            olua_push_cppobj(L, &arg2, "cc.PhysicsShape");
            olua_push_obj(L, arg3, "void *");
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 3);

            if (olua_is_bool(L, -1)) {
                olua_check_bool(L, -1, &ret);
            }

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
        return (bool)ret;
    };

    // void queryPoint(@local std::function<bool (PhysicsWorld &, PhysicsShape &, void *)> func, const cocos2d::Vec2 &point, void *data)
    self->queryPoint(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_queryRect(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    std::function<bool(cocos2d::PhysicsWorld &, cocos2d::PhysicsShape &, void *)> arg1;       /** func */
    cocos2d::Rect arg2;       /** rect */
    void *arg3 = nullptr;       /** data */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");
    manual_olua_check_cocos2d_Rect(L, 3, &arg2);
    olua_check_obj(L, 4, (void **)&arg3, "void *");

    void *cb_store = (void *)self;
    std::string cb_tag = "queryRect";
    std::string cb_name = olua_setcallback(L, cb_store, cb_tag.c_str(), 2, OLUA_TAG_REPLACE);
    lua_Integer cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](cocos2d::PhysicsWorld &arg1, cocos2d::PhysicsShape &arg2, void *arg3) {
        lua_State *L = olua_mainthread(NULL);
        bool ret = false;       
        if (L != NULL && olua_context(L) == cb_ctx) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_cppobj(L, &arg1, "cc.PhysicsWorld");
            olua_push_cppobj(L, &arg2, "cc.PhysicsShape");
            olua_push_obj(L, arg3, "void *");
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 3);

            if (olua_is_bool(L, -1)) {
                olua_check_bool(L, -1, &ret);
            }

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
        return (bool)ret;
    };

    // void queryRect(@local std::function<bool (PhysicsWorld &, PhysicsShape &, void *)> func, const cocos2d::Rect &rect, void *data)
    self->queryRect(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_rayCast(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    std::function<bool(cocos2d::PhysicsWorld &, const cocos2d::PhysicsRayCastInfo &, void *)> arg1;       /** func */
    cocos2d::Vec2 arg2;       /** start */
    cocos2d::Vec2 arg3;       /** end */
    void *arg4 = nullptr;       /** data */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");
    auto_olua_check_cocos2d_Vec2(L, 3, &arg2);
    auto_olua_check_cocos2d_Vec2(L, 4, &arg3);
    olua_check_obj(L, 5, (void **)&arg4, "void *");

    void *cb_store = (void *)self;
    std::string cb_tag = "rayCast";
    std::string cb_name = olua_setcallback(L, cb_store, cb_tag.c_str(), 2, OLUA_TAG_REPLACE);
    lua_Integer cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](cocos2d::PhysicsWorld &arg1, const cocos2d::PhysicsRayCastInfo &arg2, void *arg3) {
        lua_State *L = olua_mainthread(NULL);
        bool ret = false;       
        if (L != NULL && olua_context(L) == cb_ctx) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_cppobj(L, &arg1, "cc.PhysicsWorld");
            olua_push_cppobj(L, &arg2, "cc.PhysicsRayCastInfo");
            olua_push_obj(L, arg3, "void *");
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 3);

            if (olua_is_bool(L, -1)) {
                olua_check_bool(L, -1, &ret);
            }

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
        return (bool)ret;
    };

    // void rayCast(@local std::function<bool (PhysicsWorld &, const PhysicsRayCastInfo &, void *)> func, const cocos2d::Vec2 &start, const cocos2d::Vec2 &end, void *data)
    self->rayCast(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_removeAllBodies(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");

    // void removeAllBodies()
    self->removeAllBodies();

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_removeAllJoints1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    bool arg1 = false;       /** destroy */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");
    olua_check_bool(L, 2, &arg1);

    // void removeAllJoints(@optional bool destroy)
    self->removeAllJoints(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_removeAllJoints2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");

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
        return _cocos2d_PhysicsWorld_removeAllJoints2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_bool(L, 2))) {
            // void removeAllJoints(@optional bool destroy)
            return _cocos2d_PhysicsWorld_removeAllJoints1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsWorld::removeAllJoints' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsWorld_removeBody1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    cocos2d::PhysicsBody *arg1 = nullptr;       /** body */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.PhysicsBody");

    // void removeBody(cocos2d::PhysicsBody *body)
    self->removeBody(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_removeBody2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    lua_Integer arg1 = 0;       /** tag */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");
    olua_check_int(L, 2, &arg1);

    // void removeBody(int tag)
    self->removeBody((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_removeBody(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        if ((olua_is_cppobj(L, 2, "cc.PhysicsBody"))) {
            // void removeBody(cocos2d::PhysicsBody *body)
            return _cocos2d_PhysicsWorld_removeBody1(L);
        }

        // if ((olua_is_int(L, 2))) {
            // void removeBody(int tag)
            return _cocos2d_PhysicsWorld_removeBody2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::PhysicsWorld::removeBody' not support '%d' arguments", num_args);

    return 0;
}

static int _cocos2d_PhysicsWorld_removeJoint1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    cocos2d::PhysicsJoint *arg1 = nullptr;       /** joint */
    bool arg2 = false;       /** destroy */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.PhysicsJoint");
    olua_check_bool(L, 3, &arg2);

    // void removeJoint(cocos2d::PhysicsJoint *joint, @optional bool destroy)
    self->removeJoint(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_removeJoint2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    cocos2d::PhysicsJoint *arg1 = nullptr;       /** joint */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");
    olua_check_cppobj(L, 2, (void **)&arg1, "cc.PhysicsJoint");

    // void removeJoint(cocos2d::PhysicsJoint *joint, @optional bool destroy)
    self->removeJoint(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_removeJoint(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 2, "cc.PhysicsJoint"))) {
            // void removeJoint(cocos2d::PhysicsJoint *joint, @optional bool destroy)
            return _cocos2d_PhysicsWorld_removeJoint2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 2, "cc.PhysicsJoint")) && (olua_is_bool(L, 3))) {
            // void removeJoint(cocos2d::PhysicsJoint *joint, @optional bool destroy)
            return _cocos2d_PhysicsWorld_removeJoint1(L);
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

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");
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
    lua_Integer arg1 = 0;       /** mask */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");
    olua_check_int(L, 2, &arg1);

    // void setDebugDrawMask(int mask)
    self->setDebugDrawMask((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_setFixedUpdateRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    lua_Integer arg1 = 0;       /** updatesPerSecond */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");
    olua_check_int(L, 2, &arg1);

    // void setFixedUpdateRate(int updatesPerSecond)
    self->setFixedUpdateRate((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_setGravity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    cocos2d::Vec2 arg1;       /** gravity */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");
    auto_olua_check_cocos2d_Vec2(L, 2, &arg1);

    // void setGravity(const cocos2d::Vec2 &gravity)
    self->setGravity(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_setPostUpdateCallback(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    std::function<void()> arg1;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");

    void *cb_store = (void *)self;
    std::string cb_tag = "PostUpdateCallback";
    std::string cb_name;
    if (olua_is_std_function(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, cb_tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_Integer cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx]() {
            lua_State *L = olua_mainthread(NULL);

            if (L != NULL && olua_context(L) == cb_ctx) {
                int top = lua_gettop(L);

                olua_callback(L, cb_store, cb_name.c_str(), 0);

                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // void setPostUpdateCallback(@nullable @local const std::function<void ()> &callback)
    self->setPostUpdateCallback(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_setPreUpdateCallback(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    std::function<void()> arg1;       /** callback */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");

    void *cb_store = (void *)self;
    std::string cb_tag = "PreUpdateCallback";
    std::string cb_name;
    if (olua_is_std_function(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, cb_tag.c_str(), 2, OLUA_TAG_REPLACE);
        lua_Integer cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx]() {
            lua_State *L = olua_mainthread(NULL);

            if (L != NULL && olua_context(L) == cb_ctx) {
                int top = lua_gettop(L);

                olua_callback(L, cb_store, cb_name.c_str(), 0);

                lua_settop(L, top);
            }
        };
    } else {
        olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);
        arg1 = nullptr;
    }

    // void setPreUpdateCallback(@nullable @local const std::function<void ()> &callback)
    self->setPreUpdateCallback(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_setSpeed(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    lua_Number arg1 = 0;       /** speed */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");
    olua_check_number(L, 2, &arg1);

    // void setSpeed(float speed)
    self->setSpeed((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_setSubsteps(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    lua_Integer arg1 = 0;       /** steps */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");
    olua_check_int(L, 2, &arg1);

    // void setSubsteps(int steps)
    self->setSubsteps((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_setUpdateRate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    lua_Integer arg1 = 0;       /** rate */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");
    olua_check_int(L, 2, &arg1);

    // void setUpdateRate(int rate)
    self->setUpdateRate((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cocos2d_PhysicsWorld_step(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::PhysicsWorld *self = nullptr;
    lua_Number arg1 = 0;       /** delta */

    olua_to_cppobj(L, 1, (void **)&self, "cc.PhysicsWorld");
    olua_check_number(L, 2, &arg1);

    // void step(float delta)
    self->step((float)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cocos2d_PhysicsWorld(lua_State *L)
{
    oluacls_class(L, "cc.PhysicsWorld", nullptr);
    oluacls_func(L, "__move", _cocos2d_PhysicsWorld___move);
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
    oluacls_const_integer(L, "DEBUGDRAW_ALL", (lua_Integer)cocos2d::PhysicsWorld::DEBUGDRAW_ALL);
    oluacls_const_integer(L, "DEBUGDRAW_CONTACT", (lua_Integer)cocos2d::PhysicsWorld::DEBUGDRAW_CONTACT);
    oluacls_const_integer(L, "DEBUGDRAW_JOINT", (lua_Integer)cocos2d::PhysicsWorld::DEBUGDRAW_JOINT);
    oluacls_const_integer(L, "DEBUGDRAW_NONE", (lua_Integer)cocos2d::PhysicsWorld::DEBUGDRAW_NONE);
    oluacls_const_integer(L, "DEBUGDRAW_SHAPE", (lua_Integer)cocos2d::PhysicsWorld::DEBUGDRAW_SHAPE);

    olua_registerluatype<cocos2d::PhysicsWorld>(L, "cc.PhysicsWorld");

    return 1;
}

int luaopen_cocos2d_physics(lua_State *L)
{
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
    return 0;
}
