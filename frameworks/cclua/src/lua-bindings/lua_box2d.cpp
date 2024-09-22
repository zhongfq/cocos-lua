//
// AUTO GENERATED, DO NOT MODIFY!
//
#include "lua_box2d.h"
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "box2d/box2d.h"
#include "box2d/box2d-2dx.h"

static int _olua_module_box2d(lua_State *L);

static int _olua_fun_b2Vec2___add(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec2 *arg1;       /** a */
    b2Vec2 *arg2;       /** b */

    olua_check_object(L, 1, &arg1, "b2.Vec2");
    olua_check_object(L, 2, &arg2, "b2.Vec2");

    // @operator(operator+) static b2Vec2 operator+(const b2Vec2 &a, const b2Vec2 &b)
    b2Vec2 ret = (*arg1) + (*arg2);
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Vec2___eq(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec2 *arg1;       /** a */
    b2Vec2 *arg2;       /** b */

    olua_check_object(L, 1, &arg1, "b2.Vec2");
    olua_check_object(L, 2, &arg2, "b2.Vec2");

    // @operator(operator==) static bool operator==(const b2Vec2 &a, const b2Vec2 &b)
    bool ret = (*arg1) == (*arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Vec2___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Vec2 *)olua_toobj(L, 1, "b2.Vec2");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Vec2___sub(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec2 *arg1;       /** a */
    b2Vec2 *arg2;       /** b */

    olua_check_object(L, 1, &arg1, "b2.Vec2");
    olua_check_object(L, 2, &arg2, "b2.Vec2");

    // @operator(operator-) static b2Vec2 operator-(const b2Vec2 &a, const b2Vec2 &b)
    b2Vec2 ret = (*arg1) - (*arg2);
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Vec2___unm(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec2 *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Vec2");

    // @operator(operator-) b2Vec2 operator-()
    b2Vec2 ret = -(*self);
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Vec2_isValid(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec2 *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Vec2");

    // bool IsValid()
    bool ret = self->IsValid();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Vec2_length(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec2 *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Vec2");

    // float Length()
    float ret = self->Length();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Vec2_lengthSquared(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec2 *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Vec2");

    // float LengthSquared()
    float ret = self->LengthSquared();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Vec2_new$1(lua_State *L)
{
    olua_startinvoke(L);

    // b2Vec2()
    b2Vec2 *ret = new b2Vec2();
    int num_ret = olua_push_object(L, ret, "b2.Vec2");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Vec2_new$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** xIn */
    float arg2 = 0;       /** yIn */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // b2Vec2(float xIn, float yIn)
    b2Vec2 *ret = new b2Vec2(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "b2.Vec2");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Vec2_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // b2Vec2()
        return _olua_fun_b2Vec2_new$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2))) {
            // b2Vec2(float xIn, float yIn)
            return _olua_fun_b2Vec2_new$2(L);
        // }
    }

    luaL_error(L, "method 'b2Vec2::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Vec2_normalize(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec2 *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Vec2");

    // float Normalize()
    float ret = self->Normalize();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Vec2_set(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec2 *self = nullptr;
    float arg1 = 0;       /** x_ */
    float arg2 = 0;       /** y_ */

    olua_to_object(L, 1, &self, "b2.Vec2");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void Set(float x_, float y_)
    self->Set(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Vec2_setZero(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec2 *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Vec2");

    // void SetZero()
    self->SetZero();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Vec2_skew(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec2 *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Vec2");

    // b2Vec2 Skew()
    b2Vec2 ret = self->Skew();
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Vec2_x$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec2 *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Vec2");

    // float x
    float ret = self->x;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Vec2_x$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec2 *self = nullptr;
    float arg1 = 0;       /** x */

    olua_to_object(L, 1, &self, "b2.Vec2");
    olua_check_number(L, 2, &arg1);

    // float x
    self->x = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Vec2_x(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float x
        return _olua_fun_b2Vec2_x$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Vec2")) && (olua_is_number(L, 2))) {
            // float x
            return _olua_fun_b2Vec2_x$2(L);
        // }
    }

    luaL_error(L, "method 'b2Vec2::x' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Vec2_y$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec2 *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Vec2");

    // float y
    float ret = self->y;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Vec2_y$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec2 *self = nullptr;
    float arg1 = 0;       /** y */

    olua_to_object(L, 1, &self, "b2.Vec2");
    olua_check_number(L, 2, &arg1);

    // float y
    self->y = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Vec2_y(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float y
        return _olua_fun_b2Vec2_y$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Vec2")) && (olua_is_number(L, 2))) {
            // float y
            return _olua_fun_b2Vec2_y$2(L);
        // }
    }

    luaL_error(L, "method 'b2Vec2::y' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_Vec2(lua_State *L)
{
    oluacls_class<b2Vec2>(L, "b2.Vec2");
    oluacls_func(L, "__add", _olua_fun_b2Vec2___add);
    oluacls_func(L, "__eq", _olua_fun_b2Vec2___eq);
    oluacls_func(L, "__gc", _olua_fun_b2Vec2___gc);
    oluacls_func(L, "__sub", _olua_fun_b2Vec2___sub);
    oluacls_func(L, "__unm", _olua_fun_b2Vec2___unm);
    oluacls_func(L, "isValid", _olua_fun_b2Vec2_isValid);
    oluacls_func(L, "length", _olua_fun_b2Vec2_length);
    oluacls_func(L, "lengthSquared", _olua_fun_b2Vec2_lengthSquared);
    oluacls_func(L, "new", _olua_fun_b2Vec2_new);
    oluacls_func(L, "normalize", _olua_fun_b2Vec2_normalize);
    oluacls_func(L, "set", _olua_fun_b2Vec2_set);
    oluacls_func(L, "setZero", _olua_fun_b2Vec2_setZero);
    oluacls_func(L, "skew", _olua_fun_b2Vec2_skew);
    oluacls_prop(L, "valid", _olua_fun_b2Vec2_isValid, nullptr);
    oluacls_prop(L, "x", _olua_fun_b2Vec2_x, _olua_fun_b2Vec2_x);
    oluacls_prop(L, "y", _olua_fun_b2Vec2_y, _olua_fun_b2Vec2_y);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_Vec2(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.Vec2")) {
        luaL_error(L, "class not found: b2Vec2");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2Vec3___add(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec3 *arg1;       /** a */
    b2Vec3 *arg2;       /** b */

    olua_check_object(L, 1, &arg1, "b2.Vec3");
    olua_check_object(L, 2, &arg2, "b2.Vec3");

    // @operator(operator+) static b2Vec3 operator+(const b2Vec3 &a, const b2Vec3 &b)
    b2Vec3 ret = (*arg1) + (*arg2);
    int num_ret = olua_copy_object(L, ret, "b2.Vec3");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Vec3___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Vec3 *)olua_toobj(L, 1, "b2.Vec3");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Vec3___sub(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec3 *arg1;       /** a */
    b2Vec3 *arg2;       /** b */

    olua_check_object(L, 1, &arg1, "b2.Vec3");
    olua_check_object(L, 2, &arg2, "b2.Vec3");

    // @operator(operator-) static b2Vec3 operator-(const b2Vec3 &a, const b2Vec3 &b)
    b2Vec3 ret = (*arg1) - (*arg2);
    int num_ret = olua_copy_object(L, ret, "b2.Vec3");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Vec3___unm(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec3 *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Vec3");

    // @operator(operator-) b2Vec3 operator-()
    b2Vec3 ret = -(*self);
    int num_ret = olua_copy_object(L, ret, "b2.Vec3");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Vec3_new$1(lua_State *L)
{
    olua_startinvoke(L);

    // b2Vec3()
    b2Vec3 *ret = new b2Vec3();
    int num_ret = olua_push_object(L, ret, "b2.Vec3");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Vec3_new$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** xIn */
    float arg2 = 0;       /** yIn */
    float arg3 = 0;       /** zIn */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // b2Vec3(float xIn, float yIn, float zIn)
    b2Vec3 *ret = new b2Vec3(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "b2.Vec3");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Vec3_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // b2Vec3()
        return _olua_fun_b2Vec3_new$1(L);
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // b2Vec3(float xIn, float yIn, float zIn)
            return _olua_fun_b2Vec3_new$2(L);
        // }
    }

    luaL_error(L, "method 'b2Vec3::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Vec3_set(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec3 *self = nullptr;
    float arg1 = 0;       /** x_ */
    float arg2 = 0;       /** y_ */
    float arg3 = 0;       /** z_ */

    olua_to_object(L, 1, &self, "b2.Vec3");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // void Set(float x_, float y_, float z_)
    self->Set(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Vec3_setZero(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec3 *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Vec3");

    // void SetZero()
    self->SetZero();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Vec3_x$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec3 *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Vec3");

    // float x
    float ret = self->x;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Vec3_x$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec3 *self = nullptr;
    float arg1 = 0;       /** x */

    olua_to_object(L, 1, &self, "b2.Vec3");
    olua_check_number(L, 2, &arg1);

    // float x
    self->x = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Vec3_x(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float x
        return _olua_fun_b2Vec3_x$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Vec3")) && (olua_is_number(L, 2))) {
            // float x
            return _olua_fun_b2Vec3_x$2(L);
        // }
    }

    luaL_error(L, "method 'b2Vec3::x' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Vec3_y$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec3 *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Vec3");

    // float y
    float ret = self->y;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Vec3_y$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec3 *self = nullptr;
    float arg1 = 0;       /** y */

    olua_to_object(L, 1, &self, "b2.Vec3");
    olua_check_number(L, 2, &arg1);

    // float y
    self->y = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Vec3_y(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float y
        return _olua_fun_b2Vec3_y$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Vec3")) && (olua_is_number(L, 2))) {
            // float y
            return _olua_fun_b2Vec3_y$2(L);
        // }
    }

    luaL_error(L, "method 'b2Vec3::y' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Vec3_z$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec3 *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Vec3");

    // float z
    float ret = self->z;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Vec3_z$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec3 *self = nullptr;
    float arg1 = 0;       /** z */

    olua_to_object(L, 1, &self, "b2.Vec3");
    olua_check_number(L, 2, &arg1);

    // float z
    self->z = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Vec3_z(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float z
        return _olua_fun_b2Vec3_z$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Vec3")) && (olua_is_number(L, 2))) {
            // float z
            return _olua_fun_b2Vec3_z$2(L);
        // }
    }

    luaL_error(L, "method 'b2Vec3::z' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_Vec3(lua_State *L)
{
    oluacls_class<b2Vec3>(L, "b2.Vec3");
    oluacls_func(L, "__add", _olua_fun_b2Vec3___add);
    oluacls_func(L, "__gc", _olua_fun_b2Vec3___gc);
    oluacls_func(L, "__sub", _olua_fun_b2Vec3___sub);
    oluacls_func(L, "__unm", _olua_fun_b2Vec3___unm);
    oluacls_func(L, "new", _olua_fun_b2Vec3_new);
    oluacls_func(L, "set", _olua_fun_b2Vec3_set);
    oluacls_func(L, "setZero", _olua_fun_b2Vec3_setZero);
    oluacls_prop(L, "x", _olua_fun_b2Vec3_x, _olua_fun_b2Vec3_x);
    oluacls_prop(L, "y", _olua_fun_b2Vec3_y, _olua_fun_b2Vec3_y);
    oluacls_prop(L, "z", _olua_fun_b2Vec3_z, _olua_fun_b2Vec3_z);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_Vec3(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.Vec3")) {
        luaL_error(L, "class not found: b2Vec3");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2ContactID___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ContactID *)olua_toobj(L, 1, "b2.ContactID");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2ContactID_cf$1(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactID *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ContactID");

    // b2ContactFeature cf
    b2ContactFeature &ret = self->cf;
    int num_ret = olua_copy_object(L, ret, "b2.ContactFeature");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2ContactID_cf$2(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactID *self = nullptr;
    b2ContactFeature *arg1;       /** cf */

    olua_to_object(L, 1, &self, "b2.ContactID");
    olua_check_object(L, 2, &arg1, "b2.ContactFeature");

    // b2ContactFeature cf
    self->cf = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2ContactID_cf(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2ContactFeature cf
        return _olua_fun_b2ContactID_cf$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.ContactID")) && (olua_is_object(L, 2, "b2.ContactFeature"))) {
            // b2ContactFeature cf
            return _olua_fun_b2ContactID_cf$2(L);
        // }
    }

    luaL_error(L, "method 'b2ContactID::cf' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2ContactID_key$1(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactID *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ContactID");

    // uint32 key
    uint32 ret = self->key;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2ContactID_key$2(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactID *self = nullptr;
    uint32 arg1 = 0;       /** key */

    olua_to_object(L, 1, &self, "b2.ContactID");
    olua_check_integer(L, 2, &arg1);

    // uint32 key
    self->key = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2ContactID_key(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // uint32 key
        return _olua_fun_b2ContactID_key$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.ContactID")) && (olua_is_integer(L, 2))) {
            // uint32 key
            return _olua_fun_b2ContactID_key$2(L);
        // }
    }

    luaL_error(L, "method 'b2ContactID::key' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_ContactID(lua_State *L)
{
    oluacls_class<b2ContactID>(L, "b2.ContactID");
    oluacls_func(L, "__gc", _olua_fun_b2ContactID___gc);
    oluacls_prop(L, "cf", _olua_fun_b2ContactID_cf, _olua_fun_b2ContactID_cf);
    oluacls_prop(L, "key", _olua_fun_b2ContactID_key, _olua_fun_b2ContactID_key);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_ContactID(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.ContactID")) {
        luaL_error(L, "class not found: b2ContactID");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2ContactFeature___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ContactFeature *)olua_toobj(L, 1, "b2.ContactFeature");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2ContactFeature_indexA$1(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactFeature *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ContactFeature");

    // uint8 indexA
    uint8 ret = self->indexA;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2ContactFeature_indexA$2(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactFeature *self = nullptr;
    uint8 arg1 = 0;       /** indexA */

    olua_to_object(L, 1, &self, "b2.ContactFeature");
    olua_check_integer(L, 2, &arg1);

    // uint8 indexA
    self->indexA = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2ContactFeature_indexA(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // uint8 indexA
        return _olua_fun_b2ContactFeature_indexA$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.ContactFeature")) && (olua_is_integer(L, 2))) {
            // uint8 indexA
            return _olua_fun_b2ContactFeature_indexA$2(L);
        // }
    }

    luaL_error(L, "method 'b2ContactFeature::indexA' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2ContactFeature_indexB$1(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactFeature *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ContactFeature");

    // uint8 indexB
    uint8 ret = self->indexB;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2ContactFeature_indexB$2(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactFeature *self = nullptr;
    uint8 arg1 = 0;       /** indexB */

    olua_to_object(L, 1, &self, "b2.ContactFeature");
    olua_check_integer(L, 2, &arg1);

    // uint8 indexB
    self->indexB = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2ContactFeature_indexB(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // uint8 indexB
        return _olua_fun_b2ContactFeature_indexB$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.ContactFeature")) && (olua_is_integer(L, 2))) {
            // uint8 indexB
            return _olua_fun_b2ContactFeature_indexB$2(L);
        // }
    }

    luaL_error(L, "method 'b2ContactFeature::indexB' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2ContactFeature_typeA$1(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactFeature *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ContactFeature");

    // uint8 typeA
    uint8 ret = self->typeA;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2ContactFeature_typeA$2(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactFeature *self = nullptr;
    uint8 arg1 = 0;       /** typeA */

    olua_to_object(L, 1, &self, "b2.ContactFeature");
    olua_check_integer(L, 2, &arg1);

    // uint8 typeA
    self->typeA = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2ContactFeature_typeA(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // uint8 typeA
        return _olua_fun_b2ContactFeature_typeA$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.ContactFeature")) && (olua_is_integer(L, 2))) {
            // uint8 typeA
            return _olua_fun_b2ContactFeature_typeA$2(L);
        // }
    }

    luaL_error(L, "method 'b2ContactFeature::typeA' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2ContactFeature_typeB$1(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactFeature *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ContactFeature");

    // uint8 typeB
    uint8 ret = self->typeB;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2ContactFeature_typeB$2(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactFeature *self = nullptr;
    uint8 arg1 = 0;       /** typeB */

    olua_to_object(L, 1, &self, "b2.ContactFeature");
    olua_check_integer(L, 2, &arg1);

    // uint8 typeB
    self->typeB = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2ContactFeature_typeB(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // uint8 typeB
        return _olua_fun_b2ContactFeature_typeB$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.ContactFeature")) && (olua_is_integer(L, 2))) {
            // uint8 typeB
            return _olua_fun_b2ContactFeature_typeB$2(L);
        // }
    }

    luaL_error(L, "method 'b2ContactFeature::typeB' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_ContactFeature(lua_State *L)
{
    oluacls_class<b2ContactFeature>(L, "b2.ContactFeature");
    oluacls_func(L, "__gc", _olua_fun_b2ContactFeature___gc);
    oluacls_prop(L, "indexA", _olua_fun_b2ContactFeature_indexA, _olua_fun_b2ContactFeature_indexA);
    oluacls_prop(L, "indexB", _olua_fun_b2ContactFeature_indexB, _olua_fun_b2ContactFeature_indexB);
    oluacls_prop(L, "typeA", _olua_fun_b2ContactFeature_typeA, _olua_fun_b2ContactFeature_typeA);
    oluacls_prop(L, "typeB", _olua_fun_b2ContactFeature_typeB, _olua_fun_b2ContactFeature_typeB);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_ContactFeature(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.ContactFeature")) {
        luaL_error(L, "class not found: b2ContactFeature");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2Color___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Color *)olua_toobj(L, 1, "b2.Color");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Color_a$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Color *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Color");

    // float a
    float ret = self->a;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Color_a$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Color *self = nullptr;
    float arg1 = 0;       /** a */

    olua_to_object(L, 1, &self, "b2.Color");
    olua_check_number(L, 2, &arg1);

    // float a
    self->a = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Color_a(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float a
        return _olua_fun_b2Color_a$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Color")) && (olua_is_number(L, 2))) {
            // float a
            return _olua_fun_b2Color_a$2(L);
        // }
    }

    luaL_error(L, "method 'b2Color::a' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Color_b$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Color *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Color");

    // float b
    float ret = self->b;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Color_b$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Color *self = nullptr;
    float arg1 = 0;       /** b */

    olua_to_object(L, 1, &self, "b2.Color");
    olua_check_number(L, 2, &arg1);

    // float b
    self->b = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Color_b(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float b
        return _olua_fun_b2Color_b$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Color")) && (olua_is_number(L, 2))) {
            // float b
            return _olua_fun_b2Color_b$2(L);
        // }
    }

    luaL_error(L, "method 'b2Color::b' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Color_g$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Color *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Color");

    // float g
    float ret = self->g;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Color_g$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Color *self = nullptr;
    float arg1 = 0;       /** g */

    olua_to_object(L, 1, &self, "b2.Color");
    olua_check_number(L, 2, &arg1);

    // float g
    self->g = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Color_g(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float g
        return _olua_fun_b2Color_g$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Color")) && (olua_is_number(L, 2))) {
            // float g
            return _olua_fun_b2Color_g$2(L);
        // }
    }

    luaL_error(L, "method 'b2Color::g' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Color_new$1(lua_State *L)
{
    olua_startinvoke(L);

    // b2Color()
    b2Color *ret = new b2Color();
    int num_ret = olua_push_object(L, ret, "b2.Color");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Color_new$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** rIn */
    float arg2 = 0;       /** gIn */
    float arg3 = 0;       /** bIn */
    float arg4 = 0;       /** aIn */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // b2Color(float rIn, float gIn, float bIn, @optional float aIn)
    b2Color *ret = new b2Color(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "b2.Color");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Color_new$3(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** rIn */
    float arg2 = 0;       /** gIn */
    float arg3 = 0;       /** bIn */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // b2Color(float rIn, float gIn, float bIn)
    b2Color *ret = new b2Color(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "b2.Color");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Color_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // b2Color()
        return _olua_fun_b2Color_new$1(L);
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // b2Color(float rIn, float gIn, float bIn)
            return _olua_fun_b2Color_new$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4))) {
            // b2Color(float rIn, float gIn, float bIn, @optional float aIn)
            return _olua_fun_b2Color_new$2(L);
        // }
    }

    luaL_error(L, "method 'b2Color::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Color_r$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Color *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Color");

    // float r
    float ret = self->r;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Color_r$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Color *self = nullptr;
    float arg1 = 0;       /** r */

    olua_to_object(L, 1, &self, "b2.Color");
    olua_check_number(L, 2, &arg1);

    // float r
    self->r = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Color_r(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float r
        return _olua_fun_b2Color_r$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Color")) && (olua_is_number(L, 2))) {
            // float r
            return _olua_fun_b2Color_r$2(L);
        // }
    }

    luaL_error(L, "method 'b2Color::r' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Color_set$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Color *self = nullptr;
    float arg1 = 0;       /** rIn */
    float arg2 = 0;       /** gIn */
    float arg3 = 0;       /** bIn */
    float arg4 = 0;       /** aIn */

    olua_to_object(L, 1, &self, "b2.Color");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // void Set(float rIn, float gIn, float bIn, @optional float aIn)
    self->Set(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Color_set$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Color *self = nullptr;
    float arg1 = 0;       /** rIn */
    float arg2 = 0;       /** gIn */
    float arg3 = 0;       /** bIn */

    olua_to_object(L, 1, &self, "b2.Color");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // void Set(float rIn, float gIn, float bIn)
    self->Set(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Color_set(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "b2.Color")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4))) {
            // void Set(float rIn, float gIn, float bIn)
            return _olua_fun_b2Color_set$2(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "b2.Color")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5))) {
            // void Set(float rIn, float gIn, float bIn, @optional float aIn)
            return _olua_fun_b2Color_set$1(L);
        // }
    }

    luaL_error(L, "method 'b2Color::set' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_Color(lua_State *L)
{
    oluacls_class<b2Color>(L, "b2.Color");
    oluacls_func(L, "__gc", _olua_fun_b2Color___gc);
    oluacls_func(L, "new", _olua_fun_b2Color_new);
    oluacls_func(L, "set", _olua_fun_b2Color_set);
    oluacls_prop(L, "r", _olua_fun_b2Color_r, _olua_fun_b2Color_r);
    oluacls_prop(L, "g", _olua_fun_b2Color_g, _olua_fun_b2Color_g);
    oluacls_prop(L, "b", _olua_fun_b2Color_b, _olua_fun_b2Color_b);
    oluacls_prop(L, "a", _olua_fun_b2Color_a, _olua_fun_b2Color_a);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_Color(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.Color")) {
        luaL_error(L, "class not found: b2Color");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2FixtureUserData___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2FixtureUserData *)olua_toobj(L, 1, "b2.FixtureUserData");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2FixtureUserData_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2FixtureUserData()
    b2FixtureUserData *ret = new b2FixtureUserData();
    int num_ret = olua_push_object(L, ret, "b2.FixtureUserData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2FixtureUserData_pointer$1(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureUserData *self = nullptr;

    olua_to_object(L, 1, &self, "b2.FixtureUserData");

    // uintptr_t pointer
    uintptr_t ret = self->pointer;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2FixtureUserData_pointer$2(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureUserData *self = nullptr;
    uintptr_t arg1 = 0;       /** pointer */

    olua_to_object(L, 1, &self, "b2.FixtureUserData");
    olua_check_integer(L, 2, &arg1);

    // uintptr_t pointer
    self->pointer = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2FixtureUserData_pointer(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // uintptr_t pointer
        return _olua_fun_b2FixtureUserData_pointer$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.FixtureUserData")) && (olua_is_integer(L, 2))) {
            // uintptr_t pointer
            return _olua_fun_b2FixtureUserData_pointer$2(L);
        // }
    }

    luaL_error(L, "method 'b2FixtureUserData::pointer' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_FixtureUserData(lua_State *L)
{
    oluacls_class<b2FixtureUserData>(L, "b2.FixtureUserData");
    oluacls_func(L, "__gc", _olua_fun_b2FixtureUserData___gc);
    oluacls_func(L, "new", _olua_fun_b2FixtureUserData_new);
    oluacls_prop(L, "pointer", _olua_fun_b2FixtureUserData_pointer, _olua_fun_b2FixtureUserData_pointer);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_FixtureUserData(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.FixtureUserData")) {
        luaL_error(L, "class not found: b2FixtureUserData");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2Filter___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Filter *)olua_toobj(L, 1, "b2.Filter");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Filter_categoryBits$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Filter *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Filter");

    // uint16 categoryBits
    uint16 ret = self->categoryBits;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Filter_categoryBits$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Filter *self = nullptr;
    uint16 arg1 = 0;       /** categoryBits */

    olua_to_object(L, 1, &self, "b2.Filter");
    olua_check_integer(L, 2, &arg1);

    // uint16 categoryBits
    self->categoryBits = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Filter_categoryBits(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // uint16 categoryBits
        return _olua_fun_b2Filter_categoryBits$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Filter")) && (olua_is_integer(L, 2))) {
            // uint16 categoryBits
            return _olua_fun_b2Filter_categoryBits$2(L);
        // }
    }

    luaL_error(L, "method 'b2Filter::categoryBits' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Filter_groupIndex$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Filter *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Filter");

    // int16 groupIndex
    int16 ret = self->groupIndex;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Filter_groupIndex$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Filter *self = nullptr;
    int16 arg1 = 0;       /** groupIndex */

    olua_to_object(L, 1, &self, "b2.Filter");
    olua_check_integer(L, 2, &arg1);

    // int16 groupIndex
    self->groupIndex = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Filter_groupIndex(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // int16 groupIndex
        return _olua_fun_b2Filter_groupIndex$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Filter")) && (olua_is_integer(L, 2))) {
            // int16 groupIndex
            return _olua_fun_b2Filter_groupIndex$2(L);
        // }
    }

    luaL_error(L, "method 'b2Filter::groupIndex' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Filter_maskBits$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Filter *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Filter");

    // uint16 maskBits
    uint16 ret = self->maskBits;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Filter_maskBits$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Filter *self = nullptr;
    uint16 arg1 = 0;       /** maskBits */

    olua_to_object(L, 1, &self, "b2.Filter");
    olua_check_integer(L, 2, &arg1);

    // uint16 maskBits
    self->maskBits = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Filter_maskBits(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // uint16 maskBits
        return _olua_fun_b2Filter_maskBits$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Filter")) && (olua_is_integer(L, 2))) {
            // uint16 maskBits
            return _olua_fun_b2Filter_maskBits$2(L);
        // }
    }

    luaL_error(L, "method 'b2Filter::maskBits' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Filter_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2Filter()
    b2Filter *ret = new b2Filter();
    int num_ret = olua_push_object(L, ret, "b2.Filter");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_b2_Filter(lua_State *L)
{
    oluacls_class<b2Filter>(L, "b2.Filter");
    oluacls_func(L, "__gc", _olua_fun_b2Filter___gc);
    oluacls_func(L, "new", _olua_fun_b2Filter_new);
    oluacls_prop(L, "categoryBits", _olua_fun_b2Filter_categoryBits, _olua_fun_b2Filter_categoryBits);
    oluacls_prop(L, "maskBits", _olua_fun_b2Filter_maskBits, _olua_fun_b2Filter_maskBits);
    oluacls_prop(L, "groupIndex", _olua_fun_b2Filter_groupIndex, _olua_fun_b2Filter_groupIndex);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_Filter(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.Filter")) {
        luaL_error(L, "class not found: b2Filter");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2ManifoldPoint___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ManifoldPoint *)olua_toobj(L, 1, "b2.ManifoldPoint");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2ManifoldPoint_id$1(lua_State *L)
{
    olua_startinvoke(L);

    b2ManifoldPoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ManifoldPoint");

    // b2ContactID id
    b2ContactID &ret = self->id;
    int num_ret = olua_copy_object(L, ret, "b2.ContactID");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2ManifoldPoint_id$2(lua_State *L)
{
    olua_startinvoke(L);

    b2ManifoldPoint *self = nullptr;
    b2ContactID *arg1;       /** id */

    olua_to_object(L, 1, &self, "b2.ManifoldPoint");
    olua_check_object(L, 2, &arg1, "b2.ContactID");

    // b2ContactID id
    self->id = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2ManifoldPoint_id(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2ContactID id
        return _olua_fun_b2ManifoldPoint_id$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.ManifoldPoint")) && (olua_is_object(L, 2, "b2.ContactID"))) {
            // b2ContactID id
            return _olua_fun_b2ManifoldPoint_id$2(L);
        // }
    }

    luaL_error(L, "method 'b2ManifoldPoint::id' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2ManifoldPoint_localPoint$1(lua_State *L)
{
    olua_startinvoke(L);

    b2ManifoldPoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ManifoldPoint");

    // b2Vec2 localPoint
    b2Vec2 &ret = self->localPoint;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2ManifoldPoint_localPoint$2(lua_State *L)
{
    olua_startinvoke(L);

    b2ManifoldPoint *self = nullptr;
    b2Vec2 *arg1;       /** localPoint */

    olua_to_object(L, 1, &self, "b2.ManifoldPoint");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localPoint
    self->localPoint = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2ManifoldPoint_localPoint(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 localPoint
        return _olua_fun_b2ManifoldPoint_localPoint$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.ManifoldPoint")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 localPoint
            return _olua_fun_b2ManifoldPoint_localPoint$2(L);
        // }
    }

    luaL_error(L, "method 'b2ManifoldPoint::localPoint' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2ManifoldPoint_normalImpulse$1(lua_State *L)
{
    olua_startinvoke(L);

    b2ManifoldPoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ManifoldPoint");

    // float normalImpulse
    float ret = self->normalImpulse;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2ManifoldPoint_normalImpulse$2(lua_State *L)
{
    olua_startinvoke(L);

    b2ManifoldPoint *self = nullptr;
    float arg1 = 0;       /** normalImpulse */

    olua_to_object(L, 1, &self, "b2.ManifoldPoint");
    olua_check_number(L, 2, &arg1);

    // float normalImpulse
    self->normalImpulse = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2ManifoldPoint_normalImpulse(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float normalImpulse
        return _olua_fun_b2ManifoldPoint_normalImpulse$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.ManifoldPoint")) && (olua_is_number(L, 2))) {
            // float normalImpulse
            return _olua_fun_b2ManifoldPoint_normalImpulse$2(L);
        // }
    }

    luaL_error(L, "method 'b2ManifoldPoint::normalImpulse' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2ManifoldPoint_tangentImpulse$1(lua_State *L)
{
    olua_startinvoke(L);

    b2ManifoldPoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ManifoldPoint");

    // float tangentImpulse
    float ret = self->tangentImpulse;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2ManifoldPoint_tangentImpulse$2(lua_State *L)
{
    olua_startinvoke(L);

    b2ManifoldPoint *self = nullptr;
    float arg1 = 0;       /** tangentImpulse */

    olua_to_object(L, 1, &self, "b2.ManifoldPoint");
    olua_check_number(L, 2, &arg1);

    // float tangentImpulse
    self->tangentImpulse = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2ManifoldPoint_tangentImpulse(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float tangentImpulse
        return _olua_fun_b2ManifoldPoint_tangentImpulse$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.ManifoldPoint")) && (olua_is_number(L, 2))) {
            // float tangentImpulse
            return _olua_fun_b2ManifoldPoint_tangentImpulse$2(L);
        // }
    }

    luaL_error(L, "method 'b2ManifoldPoint::tangentImpulse' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_ManifoldPoint(lua_State *L)
{
    oluacls_class<b2ManifoldPoint>(L, "b2.ManifoldPoint");
    oluacls_func(L, "__gc", _olua_fun_b2ManifoldPoint___gc);
    oluacls_prop(L, "localPoint", _olua_fun_b2ManifoldPoint_localPoint, _olua_fun_b2ManifoldPoint_localPoint);
    oluacls_prop(L, "normalImpulse", _olua_fun_b2ManifoldPoint_normalImpulse, _olua_fun_b2ManifoldPoint_normalImpulse);
    oluacls_prop(L, "tangentImpulse", _olua_fun_b2ManifoldPoint_tangentImpulse, _olua_fun_b2ManifoldPoint_tangentImpulse);
    oluacls_prop(L, "id", _olua_fun_b2ManifoldPoint_id, _olua_fun_b2ManifoldPoint_id);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_ManifoldPoint(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.ManifoldPoint")) {
        luaL_error(L, "class not found: b2ManifoldPoint");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2Rot___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Rot *)olua_toobj(L, 1, "b2.Rot");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Rot_c$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Rot *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Rot");

    // float c
    float ret = self->c;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Rot_c$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Rot *self = nullptr;
    float arg1 = 0;       /** c */

    olua_to_object(L, 1, &self, "b2.Rot");
    olua_check_number(L, 2, &arg1);

    // float c
    self->c = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Rot_c(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float c
        return _olua_fun_b2Rot_c$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Rot")) && (olua_is_number(L, 2))) {
            // float c
            return _olua_fun_b2Rot_c$2(L);
        // }
    }

    luaL_error(L, "method 'b2Rot::c' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Rot_getAngle(lua_State *L)
{
    olua_startinvoke(L);

    b2Rot *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Rot");

    // float GetAngle()
    float ret = self->GetAngle();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Rot_getXAxis(lua_State *L)
{
    olua_startinvoke(L);

    b2Rot *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Rot");

    // b2Vec2 GetXAxis()
    b2Vec2 ret = self->GetXAxis();
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Rot_getYAxis(lua_State *L)
{
    olua_startinvoke(L);

    b2Rot *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Rot");

    // b2Vec2 GetYAxis()
    b2Vec2 ret = self->GetYAxis();
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Rot_new$1(lua_State *L)
{
    olua_startinvoke(L);

    // b2Rot()
    b2Rot *ret = new b2Rot();
    int num_ret = olua_push_object(L, ret, "b2.Rot");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Rot_new$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** angle */

    olua_check_number(L, 1, &arg1);

    // b2Rot(float angle)
    b2Rot *ret = new b2Rot(arg1);
    int num_ret = olua_push_object(L, ret, "b2.Rot");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Rot_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // b2Rot()
        return _olua_fun_b2Rot_new$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_number(L, 1))) {
            // b2Rot(float angle)
            return _olua_fun_b2Rot_new$2(L);
        // }
    }

    luaL_error(L, "method 'b2Rot::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Rot_s$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Rot *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Rot");

    // float s
    float ret = self->s;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Rot_s$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Rot *self = nullptr;
    float arg1 = 0;       /** s */

    olua_to_object(L, 1, &self, "b2.Rot");
    olua_check_number(L, 2, &arg1);

    // float s
    self->s = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Rot_s(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float s
        return _olua_fun_b2Rot_s$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Rot")) && (olua_is_number(L, 2))) {
            // float s
            return _olua_fun_b2Rot_s$2(L);
        // }
    }

    luaL_error(L, "method 'b2Rot::s' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Rot_set(lua_State *L)
{
    olua_startinvoke(L);

    b2Rot *self = nullptr;
    float arg1 = 0;       /** angle */

    olua_to_object(L, 1, &self, "b2.Rot");
    olua_check_number(L, 2, &arg1);

    // void Set(float angle)
    self->Set(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Rot_setIdentity(lua_State *L)
{
    olua_startinvoke(L);

    b2Rot *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Rot");

    // void SetIdentity()
    self->SetIdentity();

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_b2_Rot(lua_State *L)
{
    oluacls_class<b2Rot>(L, "b2.Rot");
    oluacls_func(L, "__gc", _olua_fun_b2Rot___gc);
    oluacls_func(L, "getAngle", _olua_fun_b2Rot_getAngle);
    oluacls_func(L, "getXAxis", _olua_fun_b2Rot_getXAxis);
    oluacls_func(L, "getYAxis", _olua_fun_b2Rot_getYAxis);
    oluacls_func(L, "new", _olua_fun_b2Rot_new);
    oluacls_func(L, "set", _olua_fun_b2Rot_set);
    oluacls_func(L, "setIdentity", _olua_fun_b2Rot_setIdentity);
    oluacls_prop(L, "angle", _olua_fun_b2Rot_getAngle, nullptr);
    oluacls_prop(L, "xAxis", _olua_fun_b2Rot_getXAxis, nullptr);
    oluacls_prop(L, "yAxis", _olua_fun_b2Rot_getYAxis, nullptr);
    oluacls_prop(L, "s", _olua_fun_b2Rot_s, _olua_fun_b2Rot_s);
    oluacls_prop(L, "c", _olua_fun_b2Rot_c, _olua_fun_b2Rot_c);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_Rot(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.Rot")) {
        luaL_error(L, "class not found: b2Rot");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2Draw___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Draw *)olua_toobj(L, 1, "b2.interface.Draw");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_b2_interface_Draw(lua_State *L)
{
    oluacls_class<b2Draw>(L, "b2.interface.Draw");
    oluacls_func(L, "__gc", _olua_fun_b2Draw___gc);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_interface_Draw(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.interface.Draw")) {
        luaL_error(L, "class not found: b2Draw");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2DestructionListener___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2DestructionListener *)olua_toobj(L, 1, "b2.interface.DestructionListener");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_b2_interface_DestructionListener(lua_State *L)
{
    oluacls_class<b2DestructionListener>(L, "b2.interface.DestructionListener");
    oluacls_func(L, "__gc", _olua_fun_b2DestructionListener___gc);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_interface_DestructionListener(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.interface.DestructionListener")) {
        luaL_error(L, "class not found: b2DestructionListener");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2ContactFilter___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ContactFilter *)olua_toobj(L, 1, "b2.interface.ContactFilter");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_b2_interface_ContactFilter(lua_State *L)
{
    oluacls_class<b2ContactFilter>(L, "b2.interface.ContactFilter");
    oluacls_func(L, "__gc", _olua_fun_b2ContactFilter___gc);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_interface_ContactFilter(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.interface.ContactFilter")) {
        luaL_error(L, "class not found: b2ContactFilter");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2ContactListener___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ContactListener *)olua_toobj(L, 1, "b2.interface.ContactListener");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_b2_interface_ContactListener(lua_State *L)
{
    oluacls_class<b2ContactListener>(L, "b2.interface.ContactListener");
    oluacls_func(L, "__gc", _olua_fun_b2ContactListener___gc);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_interface_ContactListener(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.interface.ContactListener")) {
        luaL_error(L, "class not found: b2ContactListener");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2QueryCallback___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2QueryCallback *)olua_toobj(L, 1, "b2.interface.QueryCallback");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_b2_interface_QueryCallback(lua_State *L)
{
    oluacls_class<b2QueryCallback>(L, "b2.interface.QueryCallback");
    oluacls_func(L, "__gc", _olua_fun_b2QueryCallback___gc);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_interface_QueryCallback(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.interface.QueryCallback")) {
        luaL_error(L, "class not found: b2QueryCallback");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2RayCastCallback___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2RayCastCallback *)olua_toobj(L, 1, "b2.interface.RayCastCallback");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_b2_interface_RayCastCallback(lua_State *L)
{
    oluacls_class<b2RayCastCallback>(L, "b2.interface.RayCastCallback");
    oluacls_func(L, "__gc", _olua_fun_b2RayCastCallback___gc);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_interface_RayCastCallback(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.interface.RayCastCallback")) {
        luaL_error(L, "class not found: b2RayCastCallback");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_box2d_Vec2Array___gc(lua_State *L)
{
    olua_startinvoke(L);

    box2d::Vec2Array *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Vec2Array");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_box2d_Vec2Array___index(lua_State *L)
{
    olua_startinvoke(L);

    box2d::Vec2Array *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "b2.Vec2Array");
    olua_check_integer(L, 2, &arg1);

    // b2Vec2 __index(unsigned int idx)
    b2Vec2 ret = self->__index(arg1);
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_box2d_Vec2Array___newindex(lua_State *L)
{
    olua_startinvoke(L);

    box2d::Vec2Array *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    b2Vec2 *arg2;       /** v */

    olua_to_object(L, 1, &self, "b2.Vec2Array");
    olua_check_integer(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "b2.Vec2");

    // void __newindex(unsigned int idx, const b2Vec2 &v)
    self->__newindex(arg1, *arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_box2d_Vec2Array_buffer(lua_State *L)
{
    olua_startinvoke(L);

    box2d::Vec2Array *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Vec2Array");

    // @getter @type(void *) b2Vec2 *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_box2d_Vec2Array_length(lua_State *L)
{
    olua_startinvoke(L);

    box2d::Vec2Array *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Vec2Array");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_box2d_Vec2Array_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // box2d::Vec2Array(@optional size_t len)
    box2d::Vec2Array *ret = new box2d::Vec2Array(arg1);
    int num_ret = olua_push_object(L, ret, "b2.Vec2Array");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_box2d_Vec2Array_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // box2d::Vec2Array()
    box2d::Vec2Array *ret = new box2d::Vec2Array();
    int num_ret = olua_push_object(L, ret, "b2.Vec2Array");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_box2d_Vec2Array_new$3(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec2 *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_object(L, 1, &arg1, "b2.Vec2");
    olua_check_integer(L, 2, &arg2);

    // box2d::Vec2Array(b2Vec2 *v, @optional size_t len)
    box2d::Vec2Array *ret = new box2d::Vec2Array(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "b2.Vec2Array");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_box2d_Vec2Array_new$4(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec2 *arg1 = nullptr;       /** v */

    olua_check_object(L, 1, &arg1, "b2.Vec2");

    // box2d::Vec2Array(b2Vec2 *v)
    box2d::Vec2Array *ret = new box2d::Vec2Array(arg1);
    int num_ret = olua_push_object(L, ret, "b2.Vec2Array");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_box2d_Vec2Array_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // box2d::Vec2Array()
        return _olua_fun_box2d_Vec2Array_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // box2d::Vec2Array(@optional size_t len)
            return _olua_fun_box2d_Vec2Array_new$1(L);
        }

        // if ((olua_is_object(L, 1, "b2.Vec2"))) {
            // box2d::Vec2Array(b2Vec2 *v)
            return _olua_fun_box2d_Vec2Array_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Vec2")) && (olua_is_integer(L, 2))) {
            // box2d::Vec2Array(b2Vec2 *v, @optional size_t len)
            return _olua_fun_box2d_Vec2Array_new$3(L);
        // }
    }

    luaL_error(L, "method 'box2d::Vec2Array::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_box2d_Vec2Array_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    box2d::Vec2Array *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "b2.Vec2Array");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew box2d::Vec2Array *slice(size_t from, @optional size_t to)
    box2d::Vec2Array *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "b2.Vec2Array");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_box2d_Vec2Array_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    box2d::Vec2Array *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "b2.Vec2Array");
    olua_check_integer(L, 2, &arg1);

    // @postnew box2d::Vec2Array *slice(size_t from)
    box2d::Vec2Array *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "b2.Vec2Array");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_box2d_Vec2Array_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Vec2Array")) && (olua_is_integer(L, 2))) {
            // @postnew box2d::Vec2Array *slice(size_t from)
            return _olua_fun_box2d_Vec2Array_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "b2.Vec2Array")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew box2d::Vec2Array *slice(size_t from, @optional size_t to)
            return _olua_fun_box2d_Vec2Array_slice$1(L);
        // }
    }

    luaL_error(L, "method 'box2d::Vec2Array::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_box2d_Vec2Array_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    box2d::Vec2Array *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "b2.Vec2Array");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew box2d::Vec2Array *sub(size_t from, @optional size_t to)
    box2d::Vec2Array *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "b2.Vec2Array");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_box2d_Vec2Array_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    box2d::Vec2Array *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "b2.Vec2Array");
    olua_check_integer(L, 2, &arg1);

    // @postnew box2d::Vec2Array *sub(size_t from)
    box2d::Vec2Array *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "b2.Vec2Array");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_box2d_Vec2Array_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Vec2Array")) && (olua_is_integer(L, 2))) {
            // @postnew box2d::Vec2Array *sub(size_t from)
            return _olua_fun_box2d_Vec2Array_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "b2.Vec2Array")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew box2d::Vec2Array *sub(size_t from, @optional size_t to)
            return _olua_fun_box2d_Vec2Array_sub$1(L);
        // }
    }

    luaL_error(L, "method 'box2d::Vec2Array::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_box2d_Vec2Array_take(lua_State *L)
{
    olua_startinvoke(L);

    box2d::Vec2Array *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Vec2Array");

    // box2d::Vec2Array *take()
    box2d::Vec2Array *ret = self->take();
    int num_ret = olua_push_object(L, ret, "b2.Vec2Array");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_box2d_Vec2Array_tostring(lua_State *L)
{
    olua_startinvoke(L);

    box2d::Vec2Array *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "b2.Vec2Array");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_box2d_Vec2Array_value$1(lua_State *L)
{
    olua_startinvoke(L);

    box2d::Vec2Array *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Vec2Array");

    // @getter const b2Vec2 &value()
    const b2Vec2 &ret = self->value();
    int num_ret = olua_push_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_box2d_Vec2Array_value$2(lua_State *L)
{
    olua_startinvoke(L);

    box2d::Vec2Array *self = nullptr;
    b2Vec2 *arg1;       /** v */

    olua_to_object(L, 1, &self, "b2.Vec2Array");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // @setter void value(const b2Vec2 &v)
    self->value(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_box2d_Vec2Array_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const b2Vec2 &value()
        return _olua_fun_box2d_Vec2Array_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Vec2Array")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // @setter void value(const b2Vec2 &v)
            return _olua_fun_box2d_Vec2Array_value$2(L);
        // }
    }

    luaL_error(L, "method 'box2d::Vec2Array::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_Vec2Array(lua_State *L)
{
    oluacls_class<box2d::Vec2Array>(L, "b2.Vec2Array");
    oluacls_func(L, "__gc", _olua_fun_box2d_Vec2Array___gc);
    oluacls_func(L, "__index", _olua_fun_box2d_Vec2Array___index);
    oluacls_func(L, "__newindex", _olua_fun_box2d_Vec2Array___newindex);
    oluacls_func(L, "new", _olua_fun_box2d_Vec2Array_new);
    oluacls_func(L, "slice", _olua_fun_box2d_Vec2Array_slice);
    oluacls_func(L, "sub", _olua_fun_box2d_Vec2Array_sub);
    oluacls_func(L, "take", _olua_fun_box2d_Vec2Array_take);
    oluacls_func(L, "tostring", _olua_fun_box2d_Vec2Array_tostring);
    oluacls_prop(L, "buffer", _olua_fun_box2d_Vec2Array_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_box2d_Vec2Array_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_box2d_Vec2Array_value, _olua_fun_box2d_Vec2Array_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_Vec2Array(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.Vec2Array")) {
        luaL_error(L, "class not found: box2d::Vec2Array");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_box2d_DestructionListener_new(lua_State *L)
{
    olua_startinvoke(L);

    // box2d::DestructionListener()
    box2d::DestructionListener *ret = new box2d::DestructionListener();
    int num_ret = olua_push_object(L, ret, "b2.DestructionListener");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_box2d_DestructionListener_sayGoodbyeToFixture$1(lua_State *L)
{
    olua_startinvoke(L);

    box2d::DestructionListener *self = nullptr;

    olua_to_object(L, 1, &self, "b2.DestructionListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "sayGoodbyeToFixture";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // std::function<void (b2Fixture *)> sayGoodbyeToFixture
    std::function<void (b2Fixture *)> ret = self->sayGoodbyeToFixture;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_box2d_DestructionListener_sayGoodbyeToFixture$2(lua_State *L)
{
    olua_startinvoke(L);

    box2d::DestructionListener *self = nullptr;
    std::function<void (b2Fixture *)> arg1;       /** sayGoodbyeToFixture */

    olua_to_object(L, 1, &self, "b2.DestructionListener");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "sayGoodbyeToFixture";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        // lua_State *ML = olua_mainthread(L);
        arg1 = [cb_store, cb_name, cb_ctx /*, ML */](b2Fixture *cb_arg1) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_object(L, cb_arg1, "b2.Fixture");
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

    // std::function<void (b2Fixture *)> sayGoodbyeToFixture
    self->sayGoodbyeToFixture = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_box2d_DestructionListener_sayGoodbyeToFixture(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::function<void (b2Fixture *)> sayGoodbyeToFixture
        return _olua_fun_box2d_DestructionListener_sayGoodbyeToFixture$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.DestructionListener")) && (olua_is_callback(L, 2, "std.function") || olua_isnil(L, 2))) {
            // std::function<void (b2Fixture *)> sayGoodbyeToFixture
            return _olua_fun_box2d_DestructionListener_sayGoodbyeToFixture$2(L);
        // }
    }

    luaL_error(L, "method 'box2d::DestructionListener::sayGoodbyeToFixture' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_box2d_DestructionListener_sayGoodbyeToJoint$1(lua_State *L)
{
    olua_startinvoke(L);

    box2d::DestructionListener *self = nullptr;

    olua_to_object(L, 1, &self, "b2.DestructionListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "sayGoodbyeToJoint";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // std::function<void (b2Joint *)> sayGoodbyeToJoint
    std::function<void (b2Joint *)> ret = self->sayGoodbyeToJoint;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_box2d_DestructionListener_sayGoodbyeToJoint$2(lua_State *L)
{
    olua_startinvoke(L);

    box2d::DestructionListener *self = nullptr;
    std::function<void (b2Joint *)> arg1;       /** sayGoodbyeToJoint */

    olua_to_object(L, 1, &self, "b2.DestructionListener");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "sayGoodbyeToJoint";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        // lua_State *ML = olua_mainthread(L);
        arg1 = [cb_store, cb_name, cb_ctx /*, ML */](b2Joint *cb_arg1) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_object(L, cb_arg1, "b2.Joint");
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

    // std::function<void (b2Joint *)> sayGoodbyeToJoint
    self->sayGoodbyeToJoint = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_box2d_DestructionListener_sayGoodbyeToJoint(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::function<void (b2Joint *)> sayGoodbyeToJoint
        return _olua_fun_box2d_DestructionListener_sayGoodbyeToJoint$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.DestructionListener")) && (olua_is_callback(L, 2, "std.function") || olua_isnil(L, 2))) {
            // std::function<void (b2Joint *)> sayGoodbyeToJoint
            return _olua_fun_box2d_DestructionListener_sayGoodbyeToJoint$2(L);
        // }
    }

    luaL_error(L, "method 'box2d::DestructionListener::sayGoodbyeToJoint' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_DestructionListener(lua_State *L)
{
    oluacls_class<box2d::DestructionListener, b2DestructionListener>(L, "b2.DestructionListener");
    oluacls_func(L, "new", _olua_fun_box2d_DestructionListener_new);
    oluacls_prop(L, "sayGoodbyeToJoint", _olua_fun_box2d_DestructionListener_sayGoodbyeToJoint, _olua_fun_box2d_DestructionListener_sayGoodbyeToJoint);
    oluacls_prop(L, "sayGoodbyeToFixture", _olua_fun_box2d_DestructionListener_sayGoodbyeToFixture, _olua_fun_box2d_DestructionListener_sayGoodbyeToFixture);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_DestructionListener(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.DestructionListener")) {
        luaL_error(L, "class not found: box2d::DestructionListener");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_box2d_ContactFilter_new(lua_State *L)
{
    olua_startinvoke(L);

    // box2d::ContactFilter()
    box2d::ContactFilter *ret = new box2d::ContactFilter();
    int num_ret = olua_push_object(L, ret, "b2.ContactFilter");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_box2d_ContactFilter_shouldCollide$1(lua_State *L)
{
    olua_startinvoke(L);

    box2d::ContactFilter *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ContactFilter");

    void *cb_store = (void *)self;
    std::string cb_tag = "shouldCollide";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // std::function<bool (b2Fixture *, b2Fixture *)> shouldCollide
    std::function<bool (b2Fixture *, b2Fixture *)> ret = self->shouldCollide;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_box2d_ContactFilter_shouldCollide$2(lua_State *L)
{
    olua_startinvoke(L);

    box2d::ContactFilter *self = nullptr;
    std::function<bool (b2Fixture *, b2Fixture *)> arg1;       /** shouldCollide */

    olua_to_object(L, 1, &self, "b2.ContactFilter");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "shouldCollide";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        // lua_State *ML = olua_mainthread(L);
        arg1 = [cb_store, cb_name, cb_ctx /*, ML */](b2Fixture *cb_arg1, b2Fixture *cb_arg2) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();
            bool ret = false;       /** ret */
            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_object(L, cb_arg1, "b2.Fixture");
                olua_push_object(L, cb_arg2, "b2.Fixture");
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

    // std::function<bool (b2Fixture *, b2Fixture *)> shouldCollide
    self->shouldCollide = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_box2d_ContactFilter_shouldCollide(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::function<bool (b2Fixture *, b2Fixture *)> shouldCollide
        return _olua_fun_box2d_ContactFilter_shouldCollide$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.ContactFilter")) && (olua_is_callback(L, 2, "std.function") || olua_isnil(L, 2))) {
            // std::function<bool (b2Fixture *, b2Fixture *)> shouldCollide
            return _olua_fun_box2d_ContactFilter_shouldCollide$2(L);
        // }
    }

    luaL_error(L, "method 'box2d::ContactFilter::shouldCollide' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_ContactFilter(lua_State *L)
{
    oluacls_class<box2d::ContactFilter, b2ContactFilter>(L, "b2.ContactFilter");
    oluacls_func(L, "new", _olua_fun_box2d_ContactFilter_new);
    oluacls_prop(L, "shouldCollide", _olua_fun_box2d_ContactFilter_shouldCollide, _olua_fun_box2d_ContactFilter_shouldCollide);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_ContactFilter(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.ContactFilter")) {
        luaL_error(L, "class not found: box2d::ContactFilter");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_box2d_ContactListener_beginContact$1(lua_State *L)
{
    olua_startinvoke(L);

    box2d::ContactListener *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ContactListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "beginContact";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // std::function<void (b2Contact *)> beginContact
    std::function<void (b2Contact *)> ret = self->beginContact;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_box2d_ContactListener_beginContact$2(lua_State *L)
{
    olua_startinvoke(L);

    box2d::ContactListener *self = nullptr;
    std::function<void (b2Contact *)> arg1;       /** beginContact */

    olua_to_object(L, 1, &self, "b2.ContactListener");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "beginContact";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        // lua_State *ML = olua_mainthread(L);
        arg1 = [cb_store, cb_name, cb_ctx /*, ML */](b2Contact *cb_arg1) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_object(L, cb_arg1, "b2.Contact");
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

    // std::function<void (b2Contact *)> beginContact
    self->beginContact = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_box2d_ContactListener_beginContact(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::function<void (b2Contact *)> beginContact
        return _olua_fun_box2d_ContactListener_beginContact$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.ContactListener")) && (olua_is_callback(L, 2, "std.function") || olua_isnil(L, 2))) {
            // std::function<void (b2Contact *)> beginContact
            return _olua_fun_box2d_ContactListener_beginContact$2(L);
        // }
    }

    luaL_error(L, "method 'box2d::ContactListener::beginContact' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_box2d_ContactListener_endContact$1(lua_State *L)
{
    olua_startinvoke(L);

    box2d::ContactListener *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ContactListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "endContact";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // std::function<void (b2Contact *)> endContact
    std::function<void (b2Contact *)> ret = self->endContact;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_box2d_ContactListener_endContact$2(lua_State *L)
{
    olua_startinvoke(L);

    box2d::ContactListener *self = nullptr;
    std::function<void (b2Contact *)> arg1;       /** endContact */

    olua_to_object(L, 1, &self, "b2.ContactListener");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "endContact";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        // lua_State *ML = olua_mainthread(L);
        arg1 = [cb_store, cb_name, cb_ctx /*, ML */](b2Contact *cb_arg1) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_object(L, cb_arg1, "b2.Contact");
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

    // std::function<void (b2Contact *)> endContact
    self->endContact = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_box2d_ContactListener_endContact(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::function<void (b2Contact *)> endContact
        return _olua_fun_box2d_ContactListener_endContact$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.ContactListener")) && (olua_is_callback(L, 2, "std.function") || olua_isnil(L, 2))) {
            // std::function<void (b2Contact *)> endContact
            return _olua_fun_box2d_ContactListener_endContact$2(L);
        // }
    }

    luaL_error(L, "method 'box2d::ContactListener::endContact' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_box2d_ContactListener_new(lua_State *L)
{
    olua_startinvoke(L);

    // box2d::ContactListener()
    box2d::ContactListener *ret = new box2d::ContactListener();
    int num_ret = olua_push_object(L, ret, "b2.ContactListener");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_box2d_ContactListener_postSolve$1(lua_State *L)
{
    olua_startinvoke(L);

    box2d::ContactListener *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ContactListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "postSolve";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // std::function<void (b2Contact *, const b2ContactImpulse *)> postSolve
    std::function<void (b2Contact *, const b2ContactImpulse *)> ret = self->postSolve;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_box2d_ContactListener_postSolve$2(lua_State *L)
{
    olua_startinvoke(L);

    box2d::ContactListener *self = nullptr;
    std::function<void (b2Contact *, const b2ContactImpulse *)> arg1;       /** postSolve */

    olua_to_object(L, 1, &self, "b2.ContactListener");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "postSolve";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        // lua_State *ML = olua_mainthread(L);
        arg1 = [cb_store, cb_name, cb_ctx /*, ML */](b2Contact *cb_arg1, const b2ContactImpulse *cb_arg2) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_object(L, cb_arg1, "b2.Contact");
                olua_push_object(L, cb_arg2, "b2.ContactImpulse");
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

    // std::function<void (b2Contact *, const b2ContactImpulse *)> postSolve
    self->postSolve = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_box2d_ContactListener_postSolve(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::function<void (b2Contact *, const b2ContactImpulse *)> postSolve
        return _olua_fun_box2d_ContactListener_postSolve$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.ContactListener")) && (olua_is_callback(L, 2, "std.function") || olua_isnil(L, 2))) {
            // std::function<void (b2Contact *, const b2ContactImpulse *)> postSolve
            return _olua_fun_box2d_ContactListener_postSolve$2(L);
        // }
    }

    luaL_error(L, "method 'box2d::ContactListener::postSolve' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_box2d_ContactListener_preSolve$1(lua_State *L)
{
    olua_startinvoke(L);

    box2d::ContactListener *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ContactListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "preSolve";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // std::function<void (b2Contact *, const b2Manifold *)> preSolve
    std::function<void (b2Contact *, const b2Manifold *)> ret = self->preSolve;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_box2d_ContactListener_preSolve$2(lua_State *L)
{
    olua_startinvoke(L);

    box2d::ContactListener *self = nullptr;
    std::function<void (b2Contact *, const b2Manifold *)> arg1;       /** preSolve */

    olua_to_object(L, 1, &self, "b2.ContactListener");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "preSolve";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        // lua_State *ML = olua_mainthread(L);
        arg1 = [cb_store, cb_name, cb_ctx /*, ML */](b2Contact *cb_arg1, const b2Manifold *cb_arg2) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_object(L, cb_arg1, "b2.Contact");
                olua_push_object(L, cb_arg2, "b2.Manifold");
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

    // std::function<void (b2Contact *, const b2Manifold *)> preSolve
    self->preSolve = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_box2d_ContactListener_preSolve(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::function<void (b2Contact *, const b2Manifold *)> preSolve
        return _olua_fun_box2d_ContactListener_preSolve$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.ContactListener")) && (olua_is_callback(L, 2, "std.function") || olua_isnil(L, 2))) {
            // std::function<void (b2Contact *, const b2Manifold *)> preSolve
            return _olua_fun_box2d_ContactListener_preSolve$2(L);
        // }
    }

    luaL_error(L, "method 'box2d::ContactListener::preSolve' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_ContactListener(lua_State *L)
{
    oluacls_class<box2d::ContactListener, b2ContactListener>(L, "b2.ContactListener");
    oluacls_func(L, "new", _olua_fun_box2d_ContactListener_new);
    oluacls_prop(L, "beginContact", _olua_fun_box2d_ContactListener_beginContact, _olua_fun_box2d_ContactListener_beginContact);
    oluacls_prop(L, "endContact", _olua_fun_box2d_ContactListener_endContact, _olua_fun_box2d_ContactListener_endContact);
    oluacls_prop(L, "preSolve", _olua_fun_box2d_ContactListener_preSolve, _olua_fun_box2d_ContactListener_preSolve);
    oluacls_prop(L, "postSolve", _olua_fun_box2d_ContactListener_postSolve, _olua_fun_box2d_ContactListener_postSolve);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_ContactListener(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.ContactListener")) {
        luaL_error(L, "class not found: box2d::ContactListener");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_box2d_QueryCallback_new(lua_State *L)
{
    olua_startinvoke(L);

    // box2d::QueryCallback()
    box2d::QueryCallback *ret = new box2d::QueryCallback();
    int num_ret = olua_push_object(L, ret, "b2.QueryCallback");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_box2d_QueryCallback_reportFixture$1(lua_State *L)
{
    olua_startinvoke(L);

    box2d::QueryCallback *self = nullptr;

    olua_to_object(L, 1, &self, "b2.QueryCallback");

    void *cb_store = (void *)self;
    std::string cb_tag = "reportFixture";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // std::function<bool (b2Fixture *)> reportFixture
    std::function<bool (b2Fixture *)> ret = self->reportFixture;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_box2d_QueryCallback_reportFixture$2(lua_State *L)
{
    olua_startinvoke(L);

    box2d::QueryCallback *self = nullptr;
    std::function<bool (b2Fixture *)> arg1;       /** reportFixture */

    olua_to_object(L, 1, &self, "b2.QueryCallback");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "reportFixture";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        // lua_State *ML = olua_mainthread(L);
        arg1 = [cb_store, cb_name, cb_ctx /*, ML */](b2Fixture *cb_arg1) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();
            bool ret = false;       /** ret */
            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_object(L, cb_arg1, "b2.Fixture");
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

    // std::function<bool (b2Fixture *)> reportFixture
    self->reportFixture = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_box2d_QueryCallback_reportFixture(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::function<bool (b2Fixture *)> reportFixture
        return _olua_fun_box2d_QueryCallback_reportFixture$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.QueryCallback")) && (olua_is_callback(L, 2, "std.function") || olua_isnil(L, 2))) {
            // std::function<bool (b2Fixture *)> reportFixture
            return _olua_fun_box2d_QueryCallback_reportFixture$2(L);
        // }
    }

    luaL_error(L, "method 'box2d::QueryCallback::reportFixture' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_QueryCallback(lua_State *L)
{
    oluacls_class<box2d::QueryCallback, b2QueryCallback>(L, "b2.QueryCallback");
    oluacls_func(L, "new", _olua_fun_box2d_QueryCallback_new);
    oluacls_prop(L, "reportFixture", _olua_fun_box2d_QueryCallback_reportFixture, _olua_fun_box2d_QueryCallback_reportFixture);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_QueryCallback(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.QueryCallback")) {
        luaL_error(L, "class not found: box2d::QueryCallback");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_box2d_RayCastCallback_new(lua_State *L)
{
    olua_startinvoke(L);

    // box2d::RayCastCallback()
    box2d::RayCastCallback *ret = new box2d::RayCastCallback();
    int num_ret = olua_push_object(L, ret, "b2.RayCastCallback");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_box2d_RayCastCallback_reportFixture$1(lua_State *L)
{
    olua_startinvoke(L);

    box2d::RayCastCallback *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RayCastCallback");

    void *cb_store = (void *)self;
    std::string cb_tag = "reportFixture";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // std::function<float (b2Fixture *, const b2Vec2 &, const b2Vec2 &, float)> reportFixture
    std::function<float (b2Fixture *, const b2Vec2 &, const b2Vec2 &, float)> ret = self->reportFixture;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_box2d_RayCastCallback_reportFixture$2(lua_State *L)
{
    olua_startinvoke(L);

    box2d::RayCastCallback *self = nullptr;
    std::function<float (b2Fixture *, const b2Vec2 &, const b2Vec2 &, float)> arg1;       /** reportFixture */

    olua_to_object(L, 1, &self, "b2.RayCastCallback");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_callback(L, 2, &arg1, "std.function");
    }

    void *cb_store = (void *)self;
    std::string cb_tag = "reportFixture";
    std::string cb_name;
    if (olua_isfunction(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        // lua_State *ML = olua_mainthread(L);
        arg1 = [cb_store, cb_name, cb_ctx /*, ML */](b2Fixture *cb_arg1, const b2Vec2 &cb_arg2, const b2Vec2 &cb_arg3, float cb_arg4) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();
            float ret = 0;       /** ret */
            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_object(L, cb_arg1, "b2.Fixture");
                olua_push_object(L, cb_arg2, "b2.Vec2");
                olua_push_object(L, cb_arg3, "b2.Vec2");
                olua_push_number(L, cb_arg4);
                olua_disable_objpool(L);

                olua_callback(L, cb_store, cb_name.c_str(), 4);

                if (olua_is_number(L, -1)) {
                    olua_check_number(L, -1, &ret);
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

    // std::function<float (b2Fixture *, const b2Vec2 &, const b2Vec2 &, float)> reportFixture
    self->reportFixture = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_box2d_RayCastCallback_reportFixture(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::function<float (b2Fixture *, const b2Vec2 &, const b2Vec2 &, float)> reportFixture
        return _olua_fun_box2d_RayCastCallback_reportFixture$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.RayCastCallback")) && (olua_is_callback(L, 2, "std.function") || olua_isnil(L, 2))) {
            // std::function<float (b2Fixture *, const b2Vec2 &, const b2Vec2 &, float)> reportFixture
            return _olua_fun_box2d_RayCastCallback_reportFixture$2(L);
        // }
    }

    luaL_error(L, "method 'box2d::RayCastCallback::reportFixture' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_RayCastCallback(lua_State *L)
{
    oluacls_class<box2d::RayCastCallback, b2RayCastCallback>(L, "b2.RayCastCallback");
    oluacls_func(L, "new", _olua_fun_box2d_RayCastCallback_new);
    oluacls_prop(L, "reportFixture", _olua_fun_box2d_RayCastCallback_reportFixture, _olua_fun_box2d_RayCastCallback_reportFixture);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_RayCastCallback(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.RayCastCallback")) {
        luaL_error(L, "class not found: box2d::RayCastCallback");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_b2_DebugNode_Flags(lua_State *L)
{
    oluacls_class<box2d::DebugNode::Flags>(L, "b2.DebugNode.Flags");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "AABB", (lua_Integer)box2d::DebugNode::Flags::AABB);
    oluacls_enum(L, "CENTER_OF_MASS", (lua_Integer)box2d::DebugNode::Flags::CENTER_OF_MASS);
    oluacls_enum(L, "JOINT", (lua_Integer)box2d::DebugNode::Flags::JOINT);
    oluacls_enum(L, "PAIRE", (lua_Integer)box2d::DebugNode::Flags::PAIRE);
    oluacls_enum(L, "SHAPE", (lua_Integer)box2d::DebugNode::Flags::SHAPE);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_DebugNode_Flags(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.DebugNode.Flags")) {
        luaL_error(L, "class not found: box2d::DebugNode::Flags");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_box2d_DebugNode_appendFlags(lua_State *L)
{
    olua_startinvoke(L);

    box2d::DebugNode *self = nullptr;
    uint32 arg1 = 0;       /** flags */

    olua_to_object(L, 1, &self, "b2.DebugNode");
    olua_check_integer(L, 2, &arg1);

    // void appendFlags(uint32 flags)
    self->appendFlags(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_box2d_DebugNode_as(lua_State *L)
{
    olua_startinvoke(L);

    box2d::DebugNode *self = nullptr;
    const char *arg1 = nullptr;       /** cls */

    olua_to_object(L, 1, &self, "b2.DebugNode");
    olua_check_string(L, 2, &arg1);

    do {
        if (olua_isa(L, 1, arg1)) {
            lua_pushvalue(L, 1);
            break;
        }
        if (olua_strequal(arg1, "b2.interface.Draw")) {
            olua_pushobj_as<b2Draw>(L, 1, self, "as.b2.interface.Draw");
            break;
        }

        luaL_error(L, "'box2d::DebugNode' can't cast to '%s'", arg1);
    } while (0);

    olua_endinvoke(L);

    return 1;
}

static int _olua_fun_box2d_DebugNode_clearFlags(lua_State *L)
{
    olua_startinvoke(L);

    box2d::DebugNode *self = nullptr;
    uint32 arg1 = 0;       /** flags */

    olua_to_object(L, 1, &self, "b2.DebugNode");
    olua_check_integer(L, 2, &arg1);

    // void clearFlags(uint32 flags)
    self->clearFlags(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_box2d_DebugNode_create(lua_State *L)
{
    olua_startinvoke(L);

    b2World *arg1 = nullptr;       /** world */

    olua_check_object(L, 1, &arg1, "b2.World");

    // static box2d::DebugNode *create(@addref(world ^) b2World *world)
    box2d::DebugNode *ret = box2d::DebugNode::create(arg1);
    int num_ret = olua_push_object(L, ret, "b2.DebugNode");

    // insert code after call
    olua_addref(L, -1, "world", 1, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_box2d_DebugNode_getFlags(lua_State *L)
{
    olua_startinvoke(L);

    box2d::DebugNode *self = nullptr;

    olua_to_object(L, 1, &self, "b2.DebugNode");

    // uint32 getFlags()
    uint32 ret = self->getFlags();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_box2d_DebugNode_setFlags(lua_State *L)
{
    olua_startinvoke(L);

    box2d::DebugNode *self = nullptr;
    uint32 arg1 = 0;       /** flags */

    olua_to_object(L, 1, &self, "b2.DebugNode");
    olua_check_integer(L, 2, &arg1);

    // void setFlags(uint32 flags)
    self->setFlags(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_b2_DebugNode(lua_State *L)
{
    oluacls_class<box2d::DebugNode, cocos2d::DrawNode>(L, "b2.DebugNode");
    oluacls_func(L, "appendFlags", _olua_fun_box2d_DebugNode_appendFlags);
    oluacls_func(L, "as", _olua_fun_box2d_DebugNode_as);
    oluacls_func(L, "clearFlags", _olua_fun_box2d_DebugNode_clearFlags);
    oluacls_func(L, "create", _olua_fun_box2d_DebugNode_create);
    oluacls_func(L, "getFlags", _olua_fun_box2d_DebugNode_getFlags);
    oluacls_func(L, "setFlags", _olua_fun_box2d_DebugNode_setFlags);
    oluacls_prop(L, "flags", _olua_fun_box2d_DebugNode_getFlags, _olua_fun_box2d_DebugNode_setFlags);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_DebugNode(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.DebugNode")) {
        luaL_error(L, "class not found: box2d::DebugNode");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2MassData_I$1(lua_State *L)
{
    olua_startinvoke(L);

    b2MassData *self = nullptr;

    olua_to_object(L, 1, &self, "b2.MassData");

    // float I
    float ret = self->I;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2MassData_I$2(lua_State *L)
{
    olua_startinvoke(L);

    b2MassData *self = nullptr;
    float arg1 = 0;       /** I */

    olua_to_object(L, 1, &self, "b2.MassData");
    olua_check_number(L, 2, &arg1);

    // float I
    self->I = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2MassData_I(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float I
        return _olua_fun_b2MassData_I$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.MassData")) && (olua_is_number(L, 2))) {
            // float I
            return _olua_fun_b2MassData_I$2(L);
        // }
    }

    luaL_error(L, "method 'b2MassData::I' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2MassData___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2MassData *)olua_toobj(L, 1, "b2.MassData");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2MassData_center$1(lua_State *L)
{
    olua_startinvoke(L);

    b2MassData *self = nullptr;

    olua_to_object(L, 1, &self, "b2.MassData");

    // b2Vec2 center
    b2Vec2 &ret = self->center;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2MassData_center$2(lua_State *L)
{
    olua_startinvoke(L);

    b2MassData *self = nullptr;
    b2Vec2 *arg1;       /** center */

    olua_to_object(L, 1, &self, "b2.MassData");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 center
    self->center = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2MassData_center(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 center
        return _olua_fun_b2MassData_center$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.MassData")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 center
            return _olua_fun_b2MassData_center$2(L);
        // }
    }

    luaL_error(L, "method 'b2MassData::center' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2MassData_mass$1(lua_State *L)
{
    olua_startinvoke(L);

    b2MassData *self = nullptr;

    olua_to_object(L, 1, &self, "b2.MassData");

    // float mass
    float ret = self->mass;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2MassData_mass$2(lua_State *L)
{
    olua_startinvoke(L);

    b2MassData *self = nullptr;
    float arg1 = 0;       /** mass */

    olua_to_object(L, 1, &self, "b2.MassData");
    olua_check_number(L, 2, &arg1);

    // float mass
    self->mass = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2MassData_mass(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float mass
        return _olua_fun_b2MassData_mass$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.MassData")) && (olua_is_number(L, 2))) {
            // float mass
            return _olua_fun_b2MassData_mass$2(L);
        // }
    }

    luaL_error(L, "method 'b2MassData::mass' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_MassData(lua_State *L)
{
    oluacls_class<b2MassData>(L, "b2.MassData");
    oluacls_func(L, "__gc", _olua_fun_b2MassData___gc);
    oluacls_prop(L, "mass", _olua_fun_b2MassData_mass, _olua_fun_b2MassData_mass);
    oluacls_prop(L, "center", _olua_fun_b2MassData_center, _olua_fun_b2MassData_center);
    oluacls_prop(L, "I", _olua_fun_b2MassData_I, _olua_fun_b2MassData_I);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_MassData(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.MassData")) {
        luaL_error(L, "class not found: b2MassData");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2Transform___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Transform *)olua_toobj(L, 1, "b2.Transform");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Transform_new$1(lua_State *L)
{
    olua_startinvoke(L);

    // b2Transform()
    b2Transform *ret = new b2Transform();
    int num_ret = olua_push_object(L, ret, "b2.Transform");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Transform_new$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec2 *arg1;       /** position */
    b2Rot *arg2;       /** rotation */

    olua_check_object(L, 1, &arg1, "b2.Vec2");
    olua_check_object(L, 2, &arg2, "b2.Rot");

    // b2Transform(const b2Vec2 &position, const b2Rot &rotation)
    b2Transform *ret = new b2Transform(*arg1, *arg2);
    int num_ret = olua_push_object(L, ret, "b2.Transform");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Transform_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // b2Transform()
        return _olua_fun_b2Transform_new$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Vec2")) && (olua_is_object(L, 2, "b2.Rot"))) {
            // b2Transform(const b2Vec2 &position, const b2Rot &rotation)
            return _olua_fun_b2Transform_new$2(L);
        // }
    }

    luaL_error(L, "method 'b2Transform::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Transform_p$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Transform *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Transform");

    // b2Vec2 p
    b2Vec2 &ret = self->p;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Transform_p$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Transform *self = nullptr;
    b2Vec2 *arg1;       /** p */

    olua_to_object(L, 1, &self, "b2.Transform");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 p
    self->p = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Transform_p(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 p
        return _olua_fun_b2Transform_p$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Transform")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 p
            return _olua_fun_b2Transform_p$2(L);
        // }
    }

    luaL_error(L, "method 'b2Transform::p' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Transform_q$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Transform *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Transform");

    // b2Rot q
    b2Rot &ret = self->q;
    int num_ret = olua_copy_object(L, ret, "b2.Rot");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Transform_q$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Transform *self = nullptr;
    b2Rot *arg1;       /** q */

    olua_to_object(L, 1, &self, "b2.Transform");
    olua_check_object(L, 2, &arg1, "b2.Rot");

    // b2Rot q
    self->q = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Transform_q(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Rot q
        return _olua_fun_b2Transform_q$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Transform")) && (olua_is_object(L, 2, "b2.Rot"))) {
            // b2Rot q
            return _olua_fun_b2Transform_q$2(L);
        // }
    }

    luaL_error(L, "method 'b2Transform::q' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Transform_set(lua_State *L)
{
    olua_startinvoke(L);

    b2Transform *self = nullptr;
    b2Vec2 *arg1;       /** position */
    float arg2 = 0;       /** angle */

    olua_to_object(L, 1, &self, "b2.Transform");
    olua_check_object(L, 2, &arg1, "b2.Vec2");
    olua_check_number(L, 3, &arg2);

    // void Set(const b2Vec2 &position, float angle)
    self->Set(*arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Transform_setIdentity(lua_State *L)
{
    olua_startinvoke(L);

    b2Transform *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Transform");

    // void SetIdentity()
    self->SetIdentity();

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_b2_Transform(lua_State *L)
{
    oluacls_class<b2Transform>(L, "b2.Transform");
    oluacls_func(L, "__gc", _olua_fun_b2Transform___gc);
    oluacls_func(L, "new", _olua_fun_b2Transform_new);
    oluacls_func(L, "set", _olua_fun_b2Transform_set);
    oluacls_func(L, "setIdentity", _olua_fun_b2Transform_setIdentity);
    oluacls_prop(L, "p", _olua_fun_b2Transform_p, _olua_fun_b2Transform_p);
    oluacls_prop(L, "q", _olua_fun_b2Transform_q, _olua_fun_b2Transform_q);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_Transform(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.Transform")) {
        luaL_error(L, "class not found: b2Transform");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2RayCastInput___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2RayCastInput *)olua_toobj(L, 1, "b2.RayCastInput");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2RayCastInput_maxFraction$1(lua_State *L)
{
    olua_startinvoke(L);

    b2RayCastInput *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RayCastInput");

    // float maxFraction
    float ret = self->maxFraction;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2RayCastInput_maxFraction$2(lua_State *L)
{
    olua_startinvoke(L);

    b2RayCastInput *self = nullptr;
    float arg1 = 0;       /** maxFraction */

    olua_to_object(L, 1, &self, "b2.RayCastInput");
    olua_check_number(L, 2, &arg1);

    // float maxFraction
    self->maxFraction = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2RayCastInput_maxFraction(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float maxFraction
        return _olua_fun_b2RayCastInput_maxFraction$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.RayCastInput")) && (olua_is_number(L, 2))) {
            // float maxFraction
            return _olua_fun_b2RayCastInput_maxFraction$2(L);
        // }
    }

    luaL_error(L, "method 'b2RayCastInput::maxFraction' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2RayCastInput_p1$1(lua_State *L)
{
    olua_startinvoke(L);

    b2RayCastInput *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RayCastInput");

    // b2Vec2 p1
    b2Vec2 &ret = self->p1;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2RayCastInput_p1$2(lua_State *L)
{
    olua_startinvoke(L);

    b2RayCastInput *self = nullptr;
    b2Vec2 *arg1;       /** p1 */

    olua_to_object(L, 1, &self, "b2.RayCastInput");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 p1
    self->p1 = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2RayCastInput_p1(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 p1
        return _olua_fun_b2RayCastInput_p1$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.RayCastInput")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 p1
            return _olua_fun_b2RayCastInput_p1$2(L);
        // }
    }

    luaL_error(L, "method 'b2RayCastInput::p1' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2RayCastInput_p2$1(lua_State *L)
{
    olua_startinvoke(L);

    b2RayCastInput *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RayCastInput");

    // b2Vec2 p2
    b2Vec2 &ret = self->p2;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2RayCastInput_p2$2(lua_State *L)
{
    olua_startinvoke(L);

    b2RayCastInput *self = nullptr;
    b2Vec2 *arg1;       /** p2 */

    olua_to_object(L, 1, &self, "b2.RayCastInput");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 p2
    self->p2 = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2RayCastInput_p2(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 p2
        return _olua_fun_b2RayCastInput_p2$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.RayCastInput")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 p2
            return _olua_fun_b2RayCastInput_p2$2(L);
        // }
    }

    luaL_error(L, "method 'b2RayCastInput::p2' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_RayCastInput(lua_State *L)
{
    oluacls_class<b2RayCastInput>(L, "b2.RayCastInput");
    oluacls_func(L, "__gc", _olua_fun_b2RayCastInput___gc);
    oluacls_prop(L, "p1", _olua_fun_b2RayCastInput_p1, _olua_fun_b2RayCastInput_p1);
    oluacls_prop(L, "p2", _olua_fun_b2RayCastInput_p2, _olua_fun_b2RayCastInput_p2);
    oluacls_prop(L, "maxFraction", _olua_fun_b2RayCastInput_maxFraction, _olua_fun_b2RayCastInput_maxFraction);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_RayCastInput(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.RayCastInput")) {
        luaL_error(L, "class not found: b2RayCastInput");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2RayCastOutput___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2RayCastOutput *)olua_toobj(L, 1, "b2.RayCastOutput");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2RayCastOutput_fraction$1(lua_State *L)
{
    olua_startinvoke(L);

    b2RayCastOutput *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RayCastOutput");

    // float fraction
    float ret = self->fraction;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2RayCastOutput_fraction$2(lua_State *L)
{
    olua_startinvoke(L);

    b2RayCastOutput *self = nullptr;
    float arg1 = 0;       /** fraction */

    olua_to_object(L, 1, &self, "b2.RayCastOutput");
    olua_check_number(L, 2, &arg1);

    // float fraction
    self->fraction = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2RayCastOutput_fraction(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float fraction
        return _olua_fun_b2RayCastOutput_fraction$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.RayCastOutput")) && (olua_is_number(L, 2))) {
            // float fraction
            return _olua_fun_b2RayCastOutput_fraction$2(L);
        // }
    }

    luaL_error(L, "method 'b2RayCastOutput::fraction' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2RayCastOutput_normal$1(lua_State *L)
{
    olua_startinvoke(L);

    b2RayCastOutput *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RayCastOutput");

    // b2Vec2 normal
    b2Vec2 &ret = self->normal;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2RayCastOutput_normal$2(lua_State *L)
{
    olua_startinvoke(L);

    b2RayCastOutput *self = nullptr;
    b2Vec2 *arg1;       /** normal */

    olua_to_object(L, 1, &self, "b2.RayCastOutput");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 normal
    self->normal = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2RayCastOutput_normal(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 normal
        return _olua_fun_b2RayCastOutput_normal$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.RayCastOutput")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 normal
            return _olua_fun_b2RayCastOutput_normal$2(L);
        // }
    }

    luaL_error(L, "method 'b2RayCastOutput::normal' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_RayCastOutput(lua_State *L)
{
    oluacls_class<b2RayCastOutput>(L, "b2.RayCastOutput");
    oluacls_func(L, "__gc", _olua_fun_b2RayCastOutput___gc);
    oluacls_prop(L, "normal", _olua_fun_b2RayCastOutput_normal, _olua_fun_b2RayCastOutput_normal);
    oluacls_prop(L, "fraction", _olua_fun_b2RayCastOutput_fraction, _olua_fun_b2RayCastOutput_fraction);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_RayCastOutput(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.RayCastOutput")) {
        luaL_error(L, "class not found: b2RayCastOutput");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_b2_Shape_Type(lua_State *L)
{
    oluacls_class<b2Shape::Type>(L, "b2.Shape.Type");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "chain", (lua_Integer)b2Shape::Type::e_chain);
    oluacls_enum(L, "circle", (lua_Integer)b2Shape::Type::e_circle);
    oluacls_enum(L, "edge", (lua_Integer)b2Shape::Type::e_edge);
    oluacls_enum(L, "polygon", (lua_Integer)b2Shape::Type::e_polygon);
    oluacls_enum(L, "typeCount", (lua_Integer)b2Shape::Type::e_typeCount);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_Shape_Type(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.Shape.Type")) {
        luaL_error(L, "class not found: b2Shape::Type");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2Shape___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Shape *)olua_toobj(L, 1, "b2.Shape");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Shape_computeAABB(lua_State *L)
{
    olua_startinvoke(L);

    b2Shape *self = nullptr;
    b2AABB *arg1 = nullptr;       /** aabb */
    b2Transform *arg2;       /** xf */
    int32 arg3 = 0;       /** childIndex */

    olua_to_object(L, 1, &self, "b2.Shape");
    olua_check_object(L, 2, &arg1, "b2.AABB");
    olua_check_object(L, 3, &arg2, "b2.Transform");
    olua_check_integer(L, 4, &arg3);

    // void ComputeAABB(b2AABB *aabb, const b2Transform &xf, int32 childIndex)
    self->ComputeAABB(arg1, *arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Shape_computeMass(lua_State *L)
{
    olua_startinvoke(L);

    b2Shape *self = nullptr;
    b2MassData *arg1 = nullptr;       /** massData */
    float arg2 = 0;       /** density */

    olua_to_object(L, 1, &self, "b2.Shape");
    olua_check_object(L, 2, &arg1, "b2.MassData");
    olua_check_number(L, 3, &arg2);

    // void ComputeMass(b2MassData *massData, float density)
    self->ComputeMass(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Shape_getChildCount(lua_State *L)
{
    olua_startinvoke(L);

    b2Shape *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Shape");

    // int32 GetChildCount()
    int32 ret = self->GetChildCount();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Shape_getType(lua_State *L)
{
    olua_startinvoke(L);

    b2Shape *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Shape");

    // b2Shape::Type GetType()
    b2Shape::Type ret = self->GetType();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Shape_rayCast(lua_State *L)
{
    olua_startinvoke(L);

    b2Shape *self = nullptr;
    b2RayCastOutput *arg1 = nullptr;       /** output */
    b2RayCastInput *arg2;       /** input */
    b2Transform *arg3;       /** transform */
    int32 arg4 = 0;       /** childIndex */

    olua_to_object(L, 1, &self, "b2.Shape");
    olua_check_object(L, 2, &arg1, "b2.RayCastOutput");
    olua_check_object(L, 3, &arg2, "b2.RayCastInput");
    olua_check_object(L, 4, &arg3, "b2.Transform");
    olua_check_integer(L, 5, &arg4);

    // bool RayCast(b2RayCastOutput *output, const b2RayCastInput &input, const b2Transform &transform, int32 childIndex)
    bool ret = self->RayCast(arg1, *arg2, *arg3, arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Shape_testPoint(lua_State *L)
{
    olua_startinvoke(L);

    b2Shape *self = nullptr;
    b2Transform *arg1;       /** xf */
    b2Vec2 *arg2;       /** p */

    olua_to_object(L, 1, &self, "b2.Shape");
    olua_check_object(L, 2, &arg1, "b2.Transform");
    olua_check_object(L, 3, &arg2, "b2.Vec2");

    // bool TestPoint(const b2Transform &xf, const b2Vec2 &p)
    bool ret = self->TestPoint(*arg1, *arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_b2_Shape(lua_State *L)
{
    oluacls_class<b2Shape>(L, "b2.Shape");
    oluacls_func(L, "__gc", _olua_fun_b2Shape___gc);
    oluacls_func(L, "computeAABB", _olua_fun_b2Shape_computeAABB);
    oluacls_func(L, "computeMass", _olua_fun_b2Shape_computeMass);
    oluacls_func(L, "getChildCount", _olua_fun_b2Shape_getChildCount);
    oluacls_func(L, "getType", _olua_fun_b2Shape_getType);
    oluacls_func(L, "rayCast", _olua_fun_b2Shape_rayCast);
    oluacls_func(L, "testPoint", _olua_fun_b2Shape_testPoint);
    oluacls_prop(L, "childCount", _olua_fun_b2Shape_getChildCount, nullptr);
    oluacls_prop(L, "type", _olua_fun_b2Shape_getType, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_Shape(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.Shape")) {
        luaL_error(L, "class not found: b2Shape");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2PolygonShape_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2PolygonShape()
    b2PolygonShape *ret = new b2PolygonShape();
    int num_ret = olua_push_object(L, ret, "b2.PolygonShape");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PolygonShape_set(lua_State *L)
{
    olua_startinvoke(L);

    b2PolygonShape *self = nullptr;
    b2Vec2 *arg1 = nullptr;       /** points */
    int32 arg2 = 0;       /** count */

    olua_to_object(L, 1, &self, "b2.PolygonShape");
    olua_check_object(L, 2, &arg1, "b2.Vec2");
    olua_check_integer(L, 3, &arg2);

    // void Set(const b2Vec2 *points, int32 count)
    self->Set(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2PolygonShape_setAsBox$1(lua_State *L)
{
    olua_startinvoke(L);

    b2PolygonShape *self = nullptr;
    float arg1 = 0;       /** hx */
    float arg2 = 0;       /** hy */

    olua_to_object(L, 1, &self, "b2.PolygonShape");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void SetAsBox(float hx, float hy)
    self->SetAsBox(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2PolygonShape_setAsBox$2(lua_State *L)
{
    olua_startinvoke(L);

    b2PolygonShape *self = nullptr;
    float arg1 = 0;       /** hx */
    float arg2 = 0;       /** hy */
    b2Vec2 *arg3;       /** center */
    float arg4 = 0;       /** angle */

    olua_to_object(L, 1, &self, "b2.PolygonShape");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_object(L, 4, &arg3, "b2.Vec2");
    olua_check_number(L, 5, &arg4);

    // void SetAsBox(float hx, float hy, const b2Vec2 &center, float angle)
    self->SetAsBox(arg1, arg2, *arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2PolygonShape_setAsBox(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "b2.PolygonShape")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // void SetAsBox(float hx, float hy)
            return _olua_fun_b2PolygonShape_setAsBox$1(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "b2.PolygonShape")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_object(L, 4, "b2.Vec2")) && (olua_is_number(L, 5))) {
            // void SetAsBox(float hx, float hy, const b2Vec2 &center, float angle)
            return _olua_fun_b2PolygonShape_setAsBox$2(L);
        // }
    }

    luaL_error(L, "method 'b2PolygonShape::setAsBox' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2PolygonShape_validate(lua_State *L)
{
    olua_startinvoke(L);

    b2PolygonShape *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PolygonShape");

    // bool Validate()
    bool ret = self->Validate();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_b2_PolygonShape(lua_State *L)
{
    oluacls_class<b2PolygonShape, b2Shape>(L, "b2.PolygonShape");
    oluacls_func(L, "new", _olua_fun_b2PolygonShape_new);
    oluacls_func(L, "set", _olua_fun_b2PolygonShape_set);
    oluacls_func(L, "setAsBox", _olua_fun_b2PolygonShape_setAsBox);
    oluacls_func(L, "validate", _olua_fun_b2PolygonShape_validate);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_PolygonShape(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.PolygonShape")) {
        luaL_error(L, "class not found: b2PolygonShape");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2EdgeShape_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2EdgeShape()
    b2EdgeShape *ret = new b2EdgeShape();
    int num_ret = olua_push_object(L, ret, "b2.EdgeShape");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2EdgeShape_setOneSided(lua_State *L)
{
    olua_startinvoke(L);

    b2EdgeShape *self = nullptr;
    b2Vec2 *arg1;       /** v0 */
    b2Vec2 *arg2;       /** v1 */
    b2Vec2 *arg3;       /** v2 */
    b2Vec2 *arg4;       /** v3 */

    olua_to_object(L, 1, &self, "b2.EdgeShape");
    olua_check_object(L, 2, &arg1, "b2.Vec2");
    olua_check_object(L, 3, &arg2, "b2.Vec2");
    olua_check_object(L, 4, &arg3, "b2.Vec2");
    olua_check_object(L, 5, &arg4, "b2.Vec2");

    // void SetOneSided(const b2Vec2 &v0, const b2Vec2 &v1, const b2Vec2 &v2, const b2Vec2 &v3)
    self->SetOneSided(*arg1, *arg2, *arg3, *arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2EdgeShape_setTwoSided(lua_State *L)
{
    olua_startinvoke(L);

    b2EdgeShape *self = nullptr;
    b2Vec2 *arg1;       /** v1 */
    b2Vec2 *arg2;       /** v2 */

    olua_to_object(L, 1, &self, "b2.EdgeShape");
    olua_check_object(L, 2, &arg1, "b2.Vec2");
    olua_check_object(L, 3, &arg2, "b2.Vec2");

    // void SetTwoSided(const b2Vec2 &v1, const b2Vec2 &v2)
    self->SetTwoSided(*arg1, *arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_b2_EdgeShape(lua_State *L)
{
    oluacls_class<b2EdgeShape, b2Shape>(L, "b2.EdgeShape");
    oluacls_func(L, "new", _olua_fun_b2EdgeShape_new);
    oluacls_func(L, "setOneSided", _olua_fun_b2EdgeShape_setOneSided);
    oluacls_func(L, "setTwoSided", _olua_fun_b2EdgeShape_setTwoSided);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_EdgeShape(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.EdgeShape")) {
        luaL_error(L, "class not found: b2EdgeShape");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2CircleShape_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2CircleShape()
    b2CircleShape *ret = new b2CircleShape();
    int num_ret = olua_push_object(L, ret, "b2.CircleShape");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_b2_CircleShape(lua_State *L)
{
    oluacls_class<b2CircleShape, b2Shape>(L, "b2.CircleShape");
    oluacls_func(L, "new", _olua_fun_b2CircleShape_new);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_CircleShape(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.CircleShape")) {
        luaL_error(L, "class not found: b2CircleShape");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2ChainShape_clear(lua_State *L)
{
    olua_startinvoke(L);

    b2ChainShape *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ChainShape");

    // void Clear()
    self->Clear();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2ChainShape_createChain(lua_State *L)
{
    olua_startinvoke(L);

    b2ChainShape *self = nullptr;
    b2Vec2 *arg1 = nullptr;       /** vertices */
    int32 arg2 = 0;       /** count */
    b2Vec2 *arg3;       /** prevVertex */
    b2Vec2 *arg4;       /** nextVertex */

    olua_to_object(L, 1, &self, "b2.ChainShape");
    olua_check_object(L, 2, &arg1, "b2.Vec2");
    olua_check_integer(L, 3, &arg2);
    olua_check_object(L, 4, &arg3, "b2.Vec2");
    olua_check_object(L, 5, &arg4, "b2.Vec2");

    // void CreateChain(const b2Vec2 *vertices, int32 count, const b2Vec2 &prevVertex, const b2Vec2 &nextVertex)
    self->CreateChain(arg1, arg2, *arg3, *arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2ChainShape_createLoop(lua_State *L)
{
    olua_startinvoke(L);

    b2ChainShape *self = nullptr;
    b2Vec2 *arg1 = nullptr;       /** vertices */
    int32 arg2 = 0;       /** count */

    olua_to_object(L, 1, &self, "b2.ChainShape");
    olua_check_object(L, 2, &arg1, "b2.Vec2");
    olua_check_integer(L, 3, &arg2);

    // void CreateLoop(const b2Vec2 *vertices, int32 count)
    self->CreateLoop(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2ChainShape_getChildEdge(lua_State *L)
{
    olua_startinvoke(L);

    b2ChainShape *self = nullptr;
    b2EdgeShape *arg1 = nullptr;       /** edge */
    int32 arg2 = 0;       /** index */

    olua_to_object(L, 1, &self, "b2.ChainShape");
    olua_check_object(L, 2, &arg1, "b2.EdgeShape");
    olua_check_integer(L, 3, &arg2);

    // void GetChildEdge(b2EdgeShape *edge, int32 index)
    self->GetChildEdge(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2ChainShape_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2ChainShape()
    b2ChainShape *ret = new b2ChainShape();
    int num_ret = olua_push_object(L, ret, "b2.ChainShape");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_b2_ChainShape(lua_State *L)
{
    oluacls_class<b2ChainShape, b2Shape>(L, "b2.ChainShape");
    oluacls_func(L, "clear", _olua_fun_b2ChainShape_clear);
    oluacls_func(L, "createChain", _olua_fun_b2ChainShape_createChain);
    oluacls_func(L, "createLoop", _olua_fun_b2ChainShape_createLoop);
    oluacls_func(L, "getChildEdge", _olua_fun_b2ChainShape_getChildEdge);
    oluacls_func(L, "new", _olua_fun_b2ChainShape_new);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_ChainShape(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.ChainShape")) {
        luaL_error(L, "class not found: b2ChainShape");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2BodyDef___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2BodyDef *)olua_toobj(L, 1, "b2.BodyDef");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2BodyDef_allowSleep$1(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.BodyDef");

    // bool allowSleep
    bool ret = self->allowSleep;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2BodyDef_allowSleep$2(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    bool arg1 = false;       /** allowSleep */

    olua_to_object(L, 1, &self, "b2.BodyDef");
    olua_check_bool(L, 2, &arg1);

    // bool allowSleep
    self->allowSleep = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2BodyDef_allowSleep(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool allowSleep
        return _olua_fun_b2BodyDef_allowSleep$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.BodyDef")) && (olua_is_bool(L, 2))) {
            // bool allowSleep
            return _olua_fun_b2BodyDef_allowSleep$2(L);
        // }
    }

    luaL_error(L, "method 'b2BodyDef::allowSleep' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2BodyDef_angle$1(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.BodyDef");

    // float angle
    float ret = self->angle;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2BodyDef_angle$2(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    float arg1 = 0;       /** angle */

    olua_to_object(L, 1, &self, "b2.BodyDef");
    olua_check_number(L, 2, &arg1);

    // float angle
    self->angle = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2BodyDef_angle(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float angle
        return _olua_fun_b2BodyDef_angle$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.BodyDef")) && (olua_is_number(L, 2))) {
            // float angle
            return _olua_fun_b2BodyDef_angle$2(L);
        // }
    }

    luaL_error(L, "method 'b2BodyDef::angle' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2BodyDef_angularDamping$1(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.BodyDef");

    // float angularDamping
    float ret = self->angularDamping;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2BodyDef_angularDamping$2(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    float arg1 = 0;       /** angularDamping */

    olua_to_object(L, 1, &self, "b2.BodyDef");
    olua_check_number(L, 2, &arg1);

    // float angularDamping
    self->angularDamping = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2BodyDef_angularDamping(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float angularDamping
        return _olua_fun_b2BodyDef_angularDamping$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.BodyDef")) && (olua_is_number(L, 2))) {
            // float angularDamping
            return _olua_fun_b2BodyDef_angularDamping$2(L);
        // }
    }

    luaL_error(L, "method 'b2BodyDef::angularDamping' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2BodyDef_angularVelocity$1(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.BodyDef");

    // float angularVelocity
    float ret = self->angularVelocity;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2BodyDef_angularVelocity$2(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    float arg1 = 0;       /** angularVelocity */

    olua_to_object(L, 1, &self, "b2.BodyDef");
    olua_check_number(L, 2, &arg1);

    // float angularVelocity
    self->angularVelocity = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2BodyDef_angularVelocity(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float angularVelocity
        return _olua_fun_b2BodyDef_angularVelocity$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.BodyDef")) && (olua_is_number(L, 2))) {
            // float angularVelocity
            return _olua_fun_b2BodyDef_angularVelocity$2(L);
        // }
    }

    luaL_error(L, "method 'b2BodyDef::angularVelocity' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2BodyDef_awake$1(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.BodyDef");

    // bool awake
    bool ret = self->awake;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2BodyDef_awake$2(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    bool arg1 = false;       /** awake */

    olua_to_object(L, 1, &self, "b2.BodyDef");
    olua_check_bool(L, 2, &arg1);

    // bool awake
    self->awake = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2BodyDef_awake(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool awake
        return _olua_fun_b2BodyDef_awake$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.BodyDef")) && (olua_is_bool(L, 2))) {
            // bool awake
            return _olua_fun_b2BodyDef_awake$2(L);
        // }
    }

    luaL_error(L, "method 'b2BodyDef::awake' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2BodyDef_bullet$1(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.BodyDef");

    // bool bullet
    bool ret = self->bullet;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2BodyDef_bullet$2(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    bool arg1 = false;       /** bullet */

    olua_to_object(L, 1, &self, "b2.BodyDef");
    olua_check_bool(L, 2, &arg1);

    // bool bullet
    self->bullet = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2BodyDef_bullet(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool bullet
        return _olua_fun_b2BodyDef_bullet$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.BodyDef")) && (olua_is_bool(L, 2))) {
            // bool bullet
            return _olua_fun_b2BodyDef_bullet$2(L);
        // }
    }

    luaL_error(L, "method 'b2BodyDef::bullet' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2BodyDef_enabled$1(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.BodyDef");

    // bool enabled
    bool ret = self->enabled;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2BodyDef_enabled$2(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    bool arg1 = false;       /** enabled */

    olua_to_object(L, 1, &self, "b2.BodyDef");
    olua_check_bool(L, 2, &arg1);

    // bool enabled
    self->enabled = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2BodyDef_enabled(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool enabled
        return _olua_fun_b2BodyDef_enabled$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.BodyDef")) && (olua_is_bool(L, 2))) {
            // bool enabled
            return _olua_fun_b2BodyDef_enabled$2(L);
        // }
    }

    luaL_error(L, "method 'b2BodyDef::enabled' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2BodyDef_fixedRotation$1(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.BodyDef");

    // bool fixedRotation
    bool ret = self->fixedRotation;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2BodyDef_fixedRotation$2(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    bool arg1 = false;       /** fixedRotation */

    olua_to_object(L, 1, &self, "b2.BodyDef");
    olua_check_bool(L, 2, &arg1);

    // bool fixedRotation
    self->fixedRotation = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2BodyDef_fixedRotation(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool fixedRotation
        return _olua_fun_b2BodyDef_fixedRotation$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.BodyDef")) && (olua_is_bool(L, 2))) {
            // bool fixedRotation
            return _olua_fun_b2BodyDef_fixedRotation$2(L);
        // }
    }

    luaL_error(L, "method 'b2BodyDef::fixedRotation' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2BodyDef_gravityScale$1(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.BodyDef");

    // float gravityScale
    float ret = self->gravityScale;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2BodyDef_gravityScale$2(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    float arg1 = 0;       /** gravityScale */

    olua_to_object(L, 1, &self, "b2.BodyDef");
    olua_check_number(L, 2, &arg1);

    // float gravityScale
    self->gravityScale = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2BodyDef_gravityScale(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float gravityScale
        return _olua_fun_b2BodyDef_gravityScale$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.BodyDef")) && (olua_is_number(L, 2))) {
            // float gravityScale
            return _olua_fun_b2BodyDef_gravityScale$2(L);
        // }
    }

    luaL_error(L, "method 'b2BodyDef::gravityScale' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2BodyDef_linearDamping$1(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.BodyDef");

    // float linearDamping
    float ret = self->linearDamping;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2BodyDef_linearDamping$2(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    float arg1 = 0;       /** linearDamping */

    olua_to_object(L, 1, &self, "b2.BodyDef");
    olua_check_number(L, 2, &arg1);

    // float linearDamping
    self->linearDamping = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2BodyDef_linearDamping(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float linearDamping
        return _olua_fun_b2BodyDef_linearDamping$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.BodyDef")) && (olua_is_number(L, 2))) {
            // float linearDamping
            return _olua_fun_b2BodyDef_linearDamping$2(L);
        // }
    }

    luaL_error(L, "method 'b2BodyDef::linearDamping' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2BodyDef_linearVelocity$1(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.BodyDef");

    // b2Vec2 linearVelocity
    b2Vec2 &ret = self->linearVelocity;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2BodyDef_linearVelocity$2(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    b2Vec2 *arg1;       /** linearVelocity */

    olua_to_object(L, 1, &self, "b2.BodyDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 linearVelocity
    self->linearVelocity = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2BodyDef_linearVelocity(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 linearVelocity
        return _olua_fun_b2BodyDef_linearVelocity$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.BodyDef")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 linearVelocity
            return _olua_fun_b2BodyDef_linearVelocity$2(L);
        // }
    }

    luaL_error(L, "method 'b2BodyDef::linearVelocity' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2BodyDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2BodyDef()
    b2BodyDef *ret = new b2BodyDef();
    int num_ret = olua_push_object(L, ret, "b2.BodyDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2BodyDef_position$1(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.BodyDef");

    // b2Vec2 position
    b2Vec2 &ret = self->position;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2BodyDef_position$2(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    b2Vec2 *arg1;       /** position */

    olua_to_object(L, 1, &self, "b2.BodyDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 position
    self->position = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2BodyDef_position(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 position
        return _olua_fun_b2BodyDef_position$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.BodyDef")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 position
            return _olua_fun_b2BodyDef_position$2(L);
        // }
    }

    luaL_error(L, "method 'b2BodyDef::position' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2BodyDef_type$1(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.BodyDef");

    // b2BodyType type
    b2BodyType ret = self->type;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2BodyDef_type$2(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    b2BodyType arg1 = (b2BodyType)0;       /** type */

    olua_to_object(L, 1, &self, "b2.BodyDef");
    olua_check_enum(L, 2, &arg1);

    // b2BodyType type
    self->type = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2BodyDef_type(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2BodyType type
        return _olua_fun_b2BodyDef_type$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.BodyDef")) && (olua_is_enum(L, 2))) {
            // b2BodyType type
            return _olua_fun_b2BodyDef_type$2(L);
        // }
    }

    luaL_error(L, "method 'b2BodyDef::type' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2BodyDef_userData$1(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.BodyDef");

    // b2BodyUserData userData
    b2BodyUserData &ret = self->userData;
    int num_ret = olua_copy_object(L, ret, "b2.BodyUserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2BodyDef_userData$2(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    b2BodyUserData *arg1;       /** userData */

    olua_to_object(L, 1, &self, "b2.BodyDef");
    olua_check_object(L, 2, &arg1, "b2.BodyUserData");

    // b2BodyUserData userData
    self->userData = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2BodyDef_userData(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2BodyUserData userData
        return _olua_fun_b2BodyDef_userData$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.BodyDef")) && (olua_is_object(L, 2, "b2.BodyUserData"))) {
            // b2BodyUserData userData
            return _olua_fun_b2BodyDef_userData$2(L);
        // }
    }

    luaL_error(L, "method 'b2BodyDef::userData' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_BodyDef(lua_State *L)
{
    oluacls_class<b2BodyDef>(L, "b2.BodyDef");
    oluacls_func(L, "__gc", _olua_fun_b2BodyDef___gc);
    oluacls_func(L, "new", _olua_fun_b2BodyDef_new);
    oluacls_prop(L, "type", _olua_fun_b2BodyDef_type, _olua_fun_b2BodyDef_type);
    oluacls_prop(L, "position", _olua_fun_b2BodyDef_position, _olua_fun_b2BodyDef_position);
    oluacls_prop(L, "angle", _olua_fun_b2BodyDef_angle, _olua_fun_b2BodyDef_angle);
    oluacls_prop(L, "linearVelocity", _olua_fun_b2BodyDef_linearVelocity, _olua_fun_b2BodyDef_linearVelocity);
    oluacls_prop(L, "angularVelocity", _olua_fun_b2BodyDef_angularVelocity, _olua_fun_b2BodyDef_angularVelocity);
    oluacls_prop(L, "linearDamping", _olua_fun_b2BodyDef_linearDamping, _olua_fun_b2BodyDef_linearDamping);
    oluacls_prop(L, "angularDamping", _olua_fun_b2BodyDef_angularDamping, _olua_fun_b2BodyDef_angularDamping);
    oluacls_prop(L, "allowSleep", _olua_fun_b2BodyDef_allowSleep, _olua_fun_b2BodyDef_allowSleep);
    oluacls_prop(L, "awake", _olua_fun_b2BodyDef_awake, _olua_fun_b2BodyDef_awake);
    oluacls_prop(L, "fixedRotation", _olua_fun_b2BodyDef_fixedRotation, _olua_fun_b2BodyDef_fixedRotation);
    oluacls_prop(L, "bullet", _olua_fun_b2BodyDef_bullet, _olua_fun_b2BodyDef_bullet);
    oluacls_prop(L, "enabled", _olua_fun_b2BodyDef_enabled, _olua_fun_b2BodyDef_enabled);
    oluacls_prop(L, "userData", _olua_fun_b2BodyDef_userData, _olua_fun_b2BodyDef_userData);
    oluacls_prop(L, "gravityScale", _olua_fun_b2BodyDef_gravityScale, _olua_fun_b2BodyDef_gravityScale);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_BodyDef(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.BodyDef")) {
        luaL_error(L, "class not found: b2BodyDef");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_b2_BodyType(lua_State *L)
{
    oluacls_class<b2BodyType>(L, "b2.BodyType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "dynamicBody", (lua_Integer)b2BodyType::b2_dynamicBody);
    oluacls_enum(L, "kinematicBody", (lua_Integer)b2BodyType::b2_kinematicBody);
    oluacls_enum(L, "staticBody", (lua_Integer)b2BodyType::b2_staticBody);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_BodyType(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.BodyType")) {
        luaL_error(L, "class not found: b2BodyType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2Body_applyAngularImpulse(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    float arg1 = 0;       /** impulse */
    bool arg2 = false;       /** wake */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void ApplyAngularImpulse(float impulse, bool wake)
    self->ApplyAngularImpulse(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Body_applyForce(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 *arg1;       /** force */
    b2Vec2 *arg2;       /** point */
    bool arg3 = false;       /** wake */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_object(L, 2, &arg1, "b2.Vec2");
    olua_check_object(L, 3, &arg2, "b2.Vec2");
    olua_check_bool(L, 4, &arg3);

    // void ApplyForce(const b2Vec2 &force, const b2Vec2 &point, bool wake)
    self->ApplyForce(*arg1, *arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Body_applyForceToCenter(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 *arg1;       /** force */
    bool arg2 = false;       /** wake */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_object(L, 2, &arg1, "b2.Vec2");
    olua_check_bool(L, 3, &arg2);

    // void ApplyForceToCenter(const b2Vec2 &force, bool wake)
    self->ApplyForceToCenter(*arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Body_applyLinearImpulse(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 *arg1;       /** impulse */
    b2Vec2 *arg2;       /** point */
    bool arg3 = false;       /** wake */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_object(L, 2, &arg1, "b2.Vec2");
    olua_check_object(L, 3, &arg2, "b2.Vec2");
    olua_check_bool(L, 4, &arg3);

    // void ApplyLinearImpulse(const b2Vec2 &impulse, const b2Vec2 &point, bool wake)
    self->ApplyLinearImpulse(*arg1, *arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Body_applyLinearImpulseToCenter(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 *arg1;       /** impulse */
    bool arg2 = false;       /** wake */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_object(L, 2, &arg1, "b2.Vec2");
    olua_check_bool(L, 3, &arg2);

    // void ApplyLinearImpulseToCenter(const b2Vec2 &impulse, bool wake)
    self->ApplyLinearImpulseToCenter(*arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Body_applyTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    float arg1 = 0;       /** torque */
    bool arg2 = false;       /** wake */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_number(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void ApplyTorque(float torque, bool wake)
    self->ApplyTorque(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Body_createFixture$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2FixtureDef *arg1 = nullptr;       /** def */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_object(L, 2, &arg1, "b2.FixtureDef");

    // b2Fixture *CreateFixture(const b2FixtureDef *def)
    b2Fixture *ret = self->CreateFixture(arg1);
    int num_ret = olua_push_object(L, ret, "b2.Fixture");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_createFixture$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Shape *arg1 = nullptr;       /** shape */
    float arg2 = 0;       /** density */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_object(L, 2, &arg1, "b2.Shape");
    olua_check_number(L, 3, &arg2);

    // b2Fixture *CreateFixture(const b2Shape *shape, float density)
    b2Fixture *ret = self->CreateFixture(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "b2.Fixture");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_createFixture(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Body")) && (olua_is_object(L, 2, "b2.FixtureDef"))) {
            // b2Fixture *CreateFixture(const b2FixtureDef *def)
            return _olua_fun_b2Body_createFixture$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "b2.Body")) && (olua_is_object(L, 2, "b2.Shape")) && (olua_is_number(L, 3))) {
            // b2Fixture *CreateFixture(const b2Shape *shape, float density)
            return _olua_fun_b2Body_createFixture$2(L);
        // }
    }

    luaL_error(L, "method 'b2Body::createFixture' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Body_destroyFixture(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Fixture *arg1 = nullptr;       /** fixture */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_object(L, 2, &arg1, "b2.Fixture");

    // void DestroyFixture(b2Fixture *fixture)
    self->DestroyFixture(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Body_dump(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // void Dump()
    self->Dump();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Body_getAngle(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // float GetAngle()
    float ret = self->GetAngle();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_getAngularDamping(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // float GetAngularDamping()
    float ret = self->GetAngularDamping();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_getAngularVelocity(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // float GetAngularVelocity()
    float ret = self->GetAngularVelocity();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_getContactList(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // b2ContactEdge *GetContactList()
    b2ContactEdge *ret = self->GetContactList();
    int num_ret = olua_push_object(L, ret, "b2.ContactEdge");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_getFixtureList(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // b2Fixture *GetFixtureList()
    b2Fixture *ret = self->GetFixtureList();
    int num_ret = olua_push_object(L, ret, "b2.Fixture");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_getGravityScale(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // float GetGravityScale()
    float ret = self->GetGravityScale();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_getInertia(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // float GetInertia()
    float ret = self->GetInertia();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_getJointList(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // b2JointEdge *GetJointList()
    b2JointEdge *ret = self->GetJointList();
    int num_ret = olua_push_object(L, ret, "b2.JointEdge");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_getLinearDamping(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // float GetLinearDamping()
    float ret = self->GetLinearDamping();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_getLinearVelocity(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // const b2Vec2 &GetLinearVelocity()
    const b2Vec2 &ret = self->GetLinearVelocity();
    int num_ret = olua_push_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_getLinearVelocityFromLocalPoint(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 *arg1;       /** localPoint */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 GetLinearVelocityFromLocalPoint(const b2Vec2 &localPoint)
    b2Vec2 ret = self->GetLinearVelocityFromLocalPoint(*arg1);
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_getLinearVelocityFromWorldPoint(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 *arg1;       /** worldPoint */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 GetLinearVelocityFromWorldPoint(const b2Vec2 &worldPoint)
    b2Vec2 ret = self->GetLinearVelocityFromWorldPoint(*arg1);
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_getLocalCenter(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // const b2Vec2 &GetLocalCenter()
    const b2Vec2 &ret = self->GetLocalCenter();
    int num_ret = olua_push_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_getLocalPoint(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 *arg1;       /** worldPoint */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 GetLocalPoint(const b2Vec2 &worldPoint)
    b2Vec2 ret = self->GetLocalPoint(*arg1);
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_getLocalVector(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 *arg1;       /** worldVector */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 GetLocalVector(const b2Vec2 &worldVector)
    b2Vec2 ret = self->GetLocalVector(*arg1);
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_getMass(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // float GetMass()
    float ret = self->GetMass();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_getMassData(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // b2MassData GetMassData()
    b2MassData ret = self->GetMassData();
    int num_ret = olua_copy_object(L, ret, "b2.MassData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_getNext(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // b2Body *GetNext()
    b2Body *ret = self->GetNext();
    int num_ret = olua_push_object(L, ret, "b2.Body");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_getPosition(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // const b2Vec2 &GetPosition()
    const b2Vec2 &ret = self->GetPosition();
    int num_ret = olua_push_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_getTransform(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // const b2Transform &GetTransform()
    const b2Transform &ret = self->GetTransform();
    int num_ret = olua_push_object(L, ret, "b2.Transform");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_getType(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // b2BodyType GetType()
    b2BodyType ret = self->GetType();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_getUserData(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // b2BodyUserData &GetUserData()
    b2BodyUserData &ret = self->GetUserData();
    int num_ret = olua_push_object(L, &ret, "b2.BodyUserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_getWorld(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // b2World *GetWorld()
    b2World *ret = self->GetWorld();
    int num_ret = olua_push_object(L, ret, "b2.World");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_getWorldCenter(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // const b2Vec2 &GetWorldCenter()
    const b2Vec2 &ret = self->GetWorldCenter();
    int num_ret = olua_push_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_getWorldPoint(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 *arg1;       /** localPoint */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 GetWorldPoint(const b2Vec2 &localPoint)
    b2Vec2 ret = self->GetWorldPoint(*arg1);
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_getWorldVector(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 *arg1;       /** localVector */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 GetWorldVector(const b2Vec2 &localVector)
    b2Vec2 ret = self->GetWorldVector(*arg1);
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_isAwake(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // bool IsAwake()
    bool ret = self->IsAwake();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_isBullet(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // bool IsBullet()
    bool ret = self->IsBullet();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_isEnabled(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // bool IsEnabled()
    bool ret = self->IsEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_isFixedRotation(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // bool IsFixedRotation()
    bool ret = self->IsFixedRotation();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_isSleepingAllowed(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // bool IsSleepingAllowed()
    bool ret = self->IsSleepingAllowed();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Body_resetMassData(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // void ResetMassData()
    self->ResetMassData();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Body_setAngularDamping(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    float arg1 = 0;       /** angularDamping */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_number(L, 2, &arg1);

    // void SetAngularDamping(float angularDamping)
    self->SetAngularDamping(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Body_setAngularVelocity(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    float arg1 = 0;       /** omega */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_number(L, 2, &arg1);

    // void SetAngularVelocity(float omega)
    self->SetAngularVelocity(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Body_setAwake(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_bool(L, 2, &arg1);

    // void SetAwake(bool flag)
    self->SetAwake(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Body_setBullet(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_bool(L, 2, &arg1);

    // void SetBullet(bool flag)
    self->SetBullet(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Body_setEnabled(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_bool(L, 2, &arg1);

    // void SetEnabled(bool flag)
    self->SetEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Body_setFixedRotation(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_bool(L, 2, &arg1);

    // void SetFixedRotation(bool flag)
    self->SetFixedRotation(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Body_setGravityScale(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    float arg1 = 0;       /** scale */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_number(L, 2, &arg1);

    // void SetGravityScale(float scale)
    self->SetGravityScale(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Body_setLinearDamping(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    float arg1 = 0;       /** linearDamping */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_number(L, 2, &arg1);

    // void SetLinearDamping(float linearDamping)
    self->SetLinearDamping(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Body_setLinearVelocity(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 *arg1;       /** v */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // void SetLinearVelocity(const b2Vec2 &v)
    self->SetLinearVelocity(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Body_setMassData(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2MassData *arg1 = nullptr;       /** data */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_object(L, 2, &arg1, "b2.MassData");

    // void SetMassData(const b2MassData *data)
    self->SetMassData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Body_setSleepingAllowed(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_bool(L, 2, &arg1);

    // void SetSleepingAllowed(bool flag)
    self->SetSleepingAllowed(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Body_setTransform(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 *arg1;       /** position */
    float arg2 = 0;       /** angle */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_object(L, 2, &arg1, "b2.Vec2");
    olua_check_number(L, 3, &arg2);

    // void SetTransform(const b2Vec2 &position, float angle)
    self->SetTransform(*arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Body_setType(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2BodyType arg1 = (b2BodyType)0;       /** type */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_enum(L, 2, &arg1);

    // void SetType(b2BodyType type)
    self->SetType(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_b2_Body(lua_State *L)
{
    oluacls_class<b2Body>(L, "b2.Body");
    oluacls_func(L, "applyAngularImpulse", _olua_fun_b2Body_applyAngularImpulse);
    oluacls_func(L, "applyForce", _olua_fun_b2Body_applyForce);
    oluacls_func(L, "applyForceToCenter", _olua_fun_b2Body_applyForceToCenter);
    oluacls_func(L, "applyLinearImpulse", _olua_fun_b2Body_applyLinearImpulse);
    oluacls_func(L, "applyLinearImpulseToCenter", _olua_fun_b2Body_applyLinearImpulseToCenter);
    oluacls_func(L, "applyTorque", _olua_fun_b2Body_applyTorque);
    oluacls_func(L, "createFixture", _olua_fun_b2Body_createFixture);
    oluacls_func(L, "destroyFixture", _olua_fun_b2Body_destroyFixture);
    oluacls_func(L, "dump", _olua_fun_b2Body_dump);
    oluacls_func(L, "getAngle", _olua_fun_b2Body_getAngle);
    oluacls_func(L, "getAngularDamping", _olua_fun_b2Body_getAngularDamping);
    oluacls_func(L, "getAngularVelocity", _olua_fun_b2Body_getAngularVelocity);
    oluacls_func(L, "getContactList", _olua_fun_b2Body_getContactList);
    oluacls_func(L, "getFixtureList", _olua_fun_b2Body_getFixtureList);
    oluacls_func(L, "getGravityScale", _olua_fun_b2Body_getGravityScale);
    oluacls_func(L, "getInertia", _olua_fun_b2Body_getInertia);
    oluacls_func(L, "getJointList", _olua_fun_b2Body_getJointList);
    oluacls_func(L, "getLinearDamping", _olua_fun_b2Body_getLinearDamping);
    oluacls_func(L, "getLinearVelocity", _olua_fun_b2Body_getLinearVelocity);
    oluacls_func(L, "getLinearVelocityFromLocalPoint", _olua_fun_b2Body_getLinearVelocityFromLocalPoint);
    oluacls_func(L, "getLinearVelocityFromWorldPoint", _olua_fun_b2Body_getLinearVelocityFromWorldPoint);
    oluacls_func(L, "getLocalCenter", _olua_fun_b2Body_getLocalCenter);
    oluacls_func(L, "getLocalPoint", _olua_fun_b2Body_getLocalPoint);
    oluacls_func(L, "getLocalVector", _olua_fun_b2Body_getLocalVector);
    oluacls_func(L, "getMass", _olua_fun_b2Body_getMass);
    oluacls_func(L, "getMassData", _olua_fun_b2Body_getMassData);
    oluacls_func(L, "getNext", _olua_fun_b2Body_getNext);
    oluacls_func(L, "getPosition", _olua_fun_b2Body_getPosition);
    oluacls_func(L, "getTransform", _olua_fun_b2Body_getTransform);
    oluacls_func(L, "getType", _olua_fun_b2Body_getType);
    oluacls_func(L, "getUserData", _olua_fun_b2Body_getUserData);
    oluacls_func(L, "getWorld", _olua_fun_b2Body_getWorld);
    oluacls_func(L, "getWorldCenter", _olua_fun_b2Body_getWorldCenter);
    oluacls_func(L, "getWorldPoint", _olua_fun_b2Body_getWorldPoint);
    oluacls_func(L, "getWorldVector", _olua_fun_b2Body_getWorldVector);
    oluacls_func(L, "isAwake", _olua_fun_b2Body_isAwake);
    oluacls_func(L, "isBullet", _olua_fun_b2Body_isBullet);
    oluacls_func(L, "isEnabled", _olua_fun_b2Body_isEnabled);
    oluacls_func(L, "isFixedRotation", _olua_fun_b2Body_isFixedRotation);
    oluacls_func(L, "isSleepingAllowed", _olua_fun_b2Body_isSleepingAllowed);
    oluacls_func(L, "resetMassData", _olua_fun_b2Body_resetMassData);
    oluacls_func(L, "setAngularDamping", _olua_fun_b2Body_setAngularDamping);
    oluacls_func(L, "setAngularVelocity", _olua_fun_b2Body_setAngularVelocity);
    oluacls_func(L, "setAwake", _olua_fun_b2Body_setAwake);
    oluacls_func(L, "setBullet", _olua_fun_b2Body_setBullet);
    oluacls_func(L, "setEnabled", _olua_fun_b2Body_setEnabled);
    oluacls_func(L, "setFixedRotation", _olua_fun_b2Body_setFixedRotation);
    oluacls_func(L, "setGravityScale", _olua_fun_b2Body_setGravityScale);
    oluacls_func(L, "setLinearDamping", _olua_fun_b2Body_setLinearDamping);
    oluacls_func(L, "setLinearVelocity", _olua_fun_b2Body_setLinearVelocity);
    oluacls_func(L, "setMassData", _olua_fun_b2Body_setMassData);
    oluacls_func(L, "setSleepingAllowed", _olua_fun_b2Body_setSleepingAllowed);
    oluacls_func(L, "setTransform", _olua_fun_b2Body_setTransform);
    oluacls_func(L, "setType", _olua_fun_b2Body_setType);
    oluacls_prop(L, "angle", _olua_fun_b2Body_getAngle, nullptr);
    oluacls_prop(L, "angularDamping", _olua_fun_b2Body_getAngularDamping, _olua_fun_b2Body_setAngularDamping);
    oluacls_prop(L, "angularVelocity", _olua_fun_b2Body_getAngularVelocity, _olua_fun_b2Body_setAngularVelocity);
    oluacls_prop(L, "awake", _olua_fun_b2Body_isAwake, _olua_fun_b2Body_setAwake);
    oluacls_prop(L, "bullet", _olua_fun_b2Body_isBullet, _olua_fun_b2Body_setBullet);
    oluacls_prop(L, "contactList", _olua_fun_b2Body_getContactList, nullptr);
    oluacls_prop(L, "enabled", _olua_fun_b2Body_isEnabled, _olua_fun_b2Body_setEnabled);
    oluacls_prop(L, "fixedRotation", _olua_fun_b2Body_isFixedRotation, _olua_fun_b2Body_setFixedRotation);
    oluacls_prop(L, "fixtureList", _olua_fun_b2Body_getFixtureList, nullptr);
    oluacls_prop(L, "gravityScale", _olua_fun_b2Body_getGravityScale, _olua_fun_b2Body_setGravityScale);
    oluacls_prop(L, "inertia", _olua_fun_b2Body_getInertia, nullptr);
    oluacls_prop(L, "jointList", _olua_fun_b2Body_getJointList, nullptr);
    oluacls_prop(L, "linearDamping", _olua_fun_b2Body_getLinearDamping, _olua_fun_b2Body_setLinearDamping);
    oluacls_prop(L, "linearVelocity", _olua_fun_b2Body_getLinearVelocity, _olua_fun_b2Body_setLinearVelocity);
    oluacls_prop(L, "localCenter", _olua_fun_b2Body_getLocalCenter, nullptr);
    oluacls_prop(L, "mass", _olua_fun_b2Body_getMass, nullptr);
    oluacls_prop(L, "massData", _olua_fun_b2Body_getMassData, _olua_fun_b2Body_setMassData);
    oluacls_prop(L, "next", _olua_fun_b2Body_getNext, nullptr);
    oluacls_prop(L, "position", _olua_fun_b2Body_getPosition, nullptr);
    oluacls_prop(L, "sleepingAllowed", _olua_fun_b2Body_isSleepingAllowed, _olua_fun_b2Body_setSleepingAllowed);
    oluacls_prop(L, "type", _olua_fun_b2Body_getType, _olua_fun_b2Body_setType);
    oluacls_prop(L, "userData", _olua_fun_b2Body_getUserData, nullptr);
    oluacls_prop(L, "world", _olua_fun_b2Body_getWorld, nullptr);
    oluacls_prop(L, "worldCenter", _olua_fun_b2Body_getWorldCenter, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_Body(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.Body")) {
        luaL_error(L, "class not found: b2Body");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2BodyUserData___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2BodyUserData *)olua_toobj(L, 1, "b2.BodyUserData");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2BodyUserData_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2BodyUserData()
    b2BodyUserData *ret = new b2BodyUserData();
    int num_ret = olua_push_object(L, ret, "b2.BodyUserData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2BodyUserData_pointer$1(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyUserData *self = nullptr;

    olua_to_object(L, 1, &self, "b2.BodyUserData");

    // uintptr_t pointer
    uintptr_t ret = self->pointer;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2BodyUserData_pointer$2(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyUserData *self = nullptr;
    uintptr_t arg1 = 0;       /** pointer */

    olua_to_object(L, 1, &self, "b2.BodyUserData");
    olua_check_integer(L, 2, &arg1);

    // uintptr_t pointer
    self->pointer = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2BodyUserData_pointer(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // uintptr_t pointer
        return _olua_fun_b2BodyUserData_pointer$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.BodyUserData")) && (olua_is_integer(L, 2))) {
            // uintptr_t pointer
            return _olua_fun_b2BodyUserData_pointer$2(L);
        // }
    }

    luaL_error(L, "method 'b2BodyUserData::pointer' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_BodyUserData(lua_State *L)
{
    oluacls_class<b2BodyUserData>(L, "b2.BodyUserData");
    oluacls_func(L, "__gc", _olua_fun_b2BodyUserData___gc);
    oluacls_func(L, "new", _olua_fun_b2BodyUserData_new);
    oluacls_prop(L, "pointer", _olua_fun_b2BodyUserData_pointer, _olua_fun_b2BodyUserData_pointer);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_BodyUserData(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.BodyUserData")) {
        luaL_error(L, "class not found: b2BodyUserData");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2FixtureDef___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2FixtureDef *)olua_toobj(L, 1, "b2.FixtureDef");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2FixtureDef_density$1(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.FixtureDef");

    // float density
    float ret = self->density;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2FixtureDef_density$2(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;
    float arg1 = 0;       /** density */

    olua_to_object(L, 1, &self, "b2.FixtureDef");
    olua_check_number(L, 2, &arg1);

    // float density
    self->density = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2FixtureDef_density(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float density
        return _olua_fun_b2FixtureDef_density$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.FixtureDef")) && (olua_is_number(L, 2))) {
            // float density
            return _olua_fun_b2FixtureDef_density$2(L);
        // }
    }

    luaL_error(L, "method 'b2FixtureDef::density' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2FixtureDef_filter$1(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.FixtureDef");

    // b2Filter filter
    b2Filter &ret = self->filter;
    int num_ret = olua_copy_object(L, ret, "b2.Filter");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2FixtureDef_filter$2(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;
    b2Filter *arg1;       /** filter */

    olua_to_object(L, 1, &self, "b2.FixtureDef");
    olua_check_object(L, 2, &arg1, "b2.Filter");

    // b2Filter filter
    self->filter = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2FixtureDef_filter(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Filter filter
        return _olua_fun_b2FixtureDef_filter$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.FixtureDef")) && (olua_is_object(L, 2, "b2.Filter"))) {
            // b2Filter filter
            return _olua_fun_b2FixtureDef_filter$2(L);
        // }
    }

    luaL_error(L, "method 'b2FixtureDef::filter' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2FixtureDef_friction$1(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.FixtureDef");

    // float friction
    float ret = self->friction;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2FixtureDef_friction$2(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;
    float arg1 = 0;       /** friction */

    olua_to_object(L, 1, &self, "b2.FixtureDef");
    olua_check_number(L, 2, &arg1);

    // float friction
    self->friction = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2FixtureDef_friction(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float friction
        return _olua_fun_b2FixtureDef_friction$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.FixtureDef")) && (olua_is_number(L, 2))) {
            // float friction
            return _olua_fun_b2FixtureDef_friction$2(L);
        // }
    }

    luaL_error(L, "method 'b2FixtureDef::friction' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2FixtureDef_isSensor$1(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.FixtureDef");

    // bool isSensor
    bool ret = self->isSensor;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2FixtureDef_isSensor$2(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;
    bool arg1 = false;       /** isSensor */

    olua_to_object(L, 1, &self, "b2.FixtureDef");
    olua_check_bool(L, 2, &arg1);

    // bool isSensor
    self->isSensor = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2FixtureDef_isSensor(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool isSensor
        return _olua_fun_b2FixtureDef_isSensor$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.FixtureDef")) && (olua_is_bool(L, 2))) {
            // bool isSensor
            return _olua_fun_b2FixtureDef_isSensor$2(L);
        // }
    }

    luaL_error(L, "method 'b2FixtureDef::isSensor' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2FixtureDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2FixtureDef()
    b2FixtureDef *ret = new b2FixtureDef();
    int num_ret = olua_push_object(L, ret, "b2.FixtureDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2FixtureDef_restitution$1(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.FixtureDef");

    // float restitution
    float ret = self->restitution;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2FixtureDef_restitution$2(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;
    float arg1 = 0;       /** restitution */

    olua_to_object(L, 1, &self, "b2.FixtureDef");
    olua_check_number(L, 2, &arg1);

    // float restitution
    self->restitution = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2FixtureDef_restitution(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float restitution
        return _olua_fun_b2FixtureDef_restitution$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.FixtureDef")) && (olua_is_number(L, 2))) {
            // float restitution
            return _olua_fun_b2FixtureDef_restitution$2(L);
        // }
    }

    luaL_error(L, "method 'b2FixtureDef::restitution' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2FixtureDef_restitutionThreshold$1(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.FixtureDef");

    // float restitutionThreshold
    float ret = self->restitutionThreshold;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2FixtureDef_restitutionThreshold$2(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;
    float arg1 = 0;       /** restitutionThreshold */

    olua_to_object(L, 1, &self, "b2.FixtureDef");
    olua_check_number(L, 2, &arg1);

    // float restitutionThreshold
    self->restitutionThreshold = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2FixtureDef_restitutionThreshold(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float restitutionThreshold
        return _olua_fun_b2FixtureDef_restitutionThreshold$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.FixtureDef")) && (olua_is_number(L, 2))) {
            // float restitutionThreshold
            return _olua_fun_b2FixtureDef_restitutionThreshold$2(L);
        // }
    }

    luaL_error(L, "method 'b2FixtureDef::restitutionThreshold' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2FixtureDef_shape$1(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.FixtureDef");

    // const b2Shape *shape
    const b2Shape *ret = self->shape;
    int num_ret = olua_push_object(L, ret, "b2.Shape");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2FixtureDef_shape$2(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;
    b2Shape *arg1 = nullptr;       /** shape */

    olua_to_object(L, 1, &self, "b2.FixtureDef");
    olua_check_object(L, 2, &arg1, "b2.Shape");

    // const b2Shape *shape
    self->shape = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2FixtureDef_shape(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // const b2Shape *shape
        return _olua_fun_b2FixtureDef_shape$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.FixtureDef")) && (olua_is_object(L, 2, "b2.Shape"))) {
            // const b2Shape *shape
            return _olua_fun_b2FixtureDef_shape$2(L);
        // }
    }

    luaL_error(L, "method 'b2FixtureDef::shape' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2FixtureDef_userData$1(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.FixtureDef");

    // b2FixtureUserData userData
    b2FixtureUserData &ret = self->userData;
    int num_ret = olua_copy_object(L, ret, "b2.FixtureUserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2FixtureDef_userData$2(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;
    b2FixtureUserData *arg1;       /** userData */

    olua_to_object(L, 1, &self, "b2.FixtureDef");
    olua_check_object(L, 2, &arg1, "b2.FixtureUserData");

    // b2FixtureUserData userData
    self->userData = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2FixtureDef_userData(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2FixtureUserData userData
        return _olua_fun_b2FixtureDef_userData$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.FixtureDef")) && (olua_is_object(L, 2, "b2.FixtureUserData"))) {
            // b2FixtureUserData userData
            return _olua_fun_b2FixtureDef_userData$2(L);
        // }
    }

    luaL_error(L, "method 'b2FixtureDef::userData' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_FixtureDef(lua_State *L)
{
    oluacls_class<b2FixtureDef>(L, "b2.FixtureDef");
    oluacls_func(L, "__gc", _olua_fun_b2FixtureDef___gc);
    oluacls_func(L, "new", _olua_fun_b2FixtureDef_new);
    oluacls_prop(L, "shape", _olua_fun_b2FixtureDef_shape, _olua_fun_b2FixtureDef_shape);
    oluacls_prop(L, "userData", _olua_fun_b2FixtureDef_userData, _olua_fun_b2FixtureDef_userData);
    oluacls_prop(L, "friction", _olua_fun_b2FixtureDef_friction, _olua_fun_b2FixtureDef_friction);
    oluacls_prop(L, "restitution", _olua_fun_b2FixtureDef_restitution, _olua_fun_b2FixtureDef_restitution);
    oluacls_prop(L, "restitutionThreshold", _olua_fun_b2FixtureDef_restitutionThreshold, _olua_fun_b2FixtureDef_restitutionThreshold);
    oluacls_prop(L, "density", _olua_fun_b2FixtureDef_density, _olua_fun_b2FixtureDef_density);
    oluacls_prop(L, "isSensor", _olua_fun_b2FixtureDef_isSensor, _olua_fun_b2FixtureDef_isSensor);
    oluacls_prop(L, "filter", _olua_fun_b2FixtureDef_filter, _olua_fun_b2FixtureDef_filter);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_FixtureDef(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.FixtureDef")) {
        luaL_error(L, "class not found: b2FixtureDef");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2Fixture___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Fixture *)olua_toobj(L, 1, "b2.Fixture");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Fixture_dump(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;
    int32 arg1 = 0;       /** bodyIndex */

    olua_to_object(L, 1, &self, "b2.Fixture");
    olua_check_integer(L, 2, &arg1);

    // void Dump(int32 bodyIndex)
    self->Dump(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Fixture_getAABB(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;
    int32 arg1 = 0;       /** childIndex */

    olua_to_object(L, 1, &self, "b2.Fixture");
    olua_check_integer(L, 2, &arg1);

    // const b2AABB &GetAABB(int32 childIndex)
    const b2AABB &ret = self->GetAABB(arg1);
    int num_ret = olua_push_object(L, ret, "b2.AABB");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Fixture_getBody(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Fixture");

    // b2Body *GetBody()
    b2Body *ret = self->GetBody();
    int num_ret = olua_push_object(L, ret, "b2.Body");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Fixture_getDensity(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Fixture");

    // float GetDensity()
    float ret = self->GetDensity();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Fixture_getFilterData(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Fixture");

    // const b2Filter &GetFilterData()
    const b2Filter &ret = self->GetFilterData();
    int num_ret = olua_push_object(L, ret, "b2.Filter");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Fixture_getFriction(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Fixture");

    // float GetFriction()
    float ret = self->GetFriction();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Fixture_getMassData(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;
    b2MassData *arg1 = nullptr;       /** massData */

    olua_to_object(L, 1, &self, "b2.Fixture");
    olua_check_object(L, 2, &arg1, "b2.MassData");

    // void GetMassData(b2MassData *massData)
    self->GetMassData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Fixture_getNext(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Fixture");

    // b2Fixture *GetNext()
    b2Fixture *ret = self->GetNext();
    int num_ret = olua_push_object(L, ret, "b2.Fixture");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Fixture_getRestitution(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Fixture");

    // float GetRestitution()
    float ret = self->GetRestitution();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Fixture_getRestitutionThreshold(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Fixture");

    // float GetRestitutionThreshold()
    float ret = self->GetRestitutionThreshold();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Fixture_getShape(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Fixture");

    // b2Shape *GetShape()
    b2Shape *ret = self->GetShape();
    int num_ret = olua_push_object(L, ret, "b2.Shape");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Fixture_getType(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Fixture");

    // b2Shape::Type GetType()
    b2Shape::Type ret = self->GetType();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Fixture_getUserData(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Fixture");

    // b2FixtureUserData &GetUserData()
    b2FixtureUserData &ret = self->GetUserData();
    int num_ret = olua_push_object(L, &ret, "b2.FixtureUserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Fixture_isSensor(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Fixture");

    // bool IsSensor()
    bool ret = self->IsSensor();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Fixture_rayCast(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;
    b2RayCastOutput *arg1 = nullptr;       /** output */
    b2RayCastInput *arg2;       /** input */
    int32 arg3 = 0;       /** childIndex */

    olua_to_object(L, 1, &self, "b2.Fixture");
    olua_check_object(L, 2, &arg1, "b2.RayCastOutput");
    olua_check_object(L, 3, &arg2, "b2.RayCastInput");
    olua_check_integer(L, 4, &arg3);

    // bool RayCast(b2RayCastOutput *output, const b2RayCastInput &input, int32 childIndex)
    bool ret = self->RayCast(arg1, *arg2, arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Fixture_refilter(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Fixture");

    // void Refilter()
    self->Refilter();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Fixture_setDensity(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;
    float arg1 = 0;       /** density */

    olua_to_object(L, 1, &self, "b2.Fixture");
    olua_check_number(L, 2, &arg1);

    // void SetDensity(float density)
    self->SetDensity(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Fixture_setFilterData(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;
    b2Filter *arg1;       /** filter */

    olua_to_object(L, 1, &self, "b2.Fixture");
    olua_check_object(L, 2, &arg1, "b2.Filter");

    // void SetFilterData(const b2Filter &filter)
    self->SetFilterData(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Fixture_setFriction(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;
    float arg1 = 0;       /** friction */

    olua_to_object(L, 1, &self, "b2.Fixture");
    olua_check_number(L, 2, &arg1);

    // void SetFriction(float friction)
    self->SetFriction(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Fixture_setRestitution(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;
    float arg1 = 0;       /** restitution */

    olua_to_object(L, 1, &self, "b2.Fixture");
    olua_check_number(L, 2, &arg1);

    // void SetRestitution(float restitution)
    self->SetRestitution(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Fixture_setRestitutionThreshold(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;
    float arg1 = 0;       /** threshold */

    olua_to_object(L, 1, &self, "b2.Fixture");
    olua_check_number(L, 2, &arg1);

    // void SetRestitutionThreshold(float threshold)
    self->SetRestitutionThreshold(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Fixture_setSensor(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;
    bool arg1 = false;       /** sensor */

    olua_to_object(L, 1, &self, "b2.Fixture");
    olua_check_bool(L, 2, &arg1);

    // void SetSensor(bool sensor)
    self->SetSensor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Fixture_testPoint(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;
    b2Vec2 *arg1;       /** p */

    olua_to_object(L, 1, &self, "b2.Fixture");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // bool TestPoint(const b2Vec2 &p)
    bool ret = self->TestPoint(*arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_b2_Fixture(lua_State *L)
{
    oluacls_class<b2Fixture>(L, "b2.Fixture");
    oluacls_func(L, "__gc", _olua_fun_b2Fixture___gc);
    oluacls_func(L, "dump", _olua_fun_b2Fixture_dump);
    oluacls_func(L, "getAABB", _olua_fun_b2Fixture_getAABB);
    oluacls_func(L, "getBody", _olua_fun_b2Fixture_getBody);
    oluacls_func(L, "getDensity", _olua_fun_b2Fixture_getDensity);
    oluacls_func(L, "getFilterData", _olua_fun_b2Fixture_getFilterData);
    oluacls_func(L, "getFriction", _olua_fun_b2Fixture_getFriction);
    oluacls_func(L, "getMassData", _olua_fun_b2Fixture_getMassData);
    oluacls_func(L, "getNext", _olua_fun_b2Fixture_getNext);
    oluacls_func(L, "getRestitution", _olua_fun_b2Fixture_getRestitution);
    oluacls_func(L, "getRestitutionThreshold", _olua_fun_b2Fixture_getRestitutionThreshold);
    oluacls_func(L, "getShape", _olua_fun_b2Fixture_getShape);
    oluacls_func(L, "getType", _olua_fun_b2Fixture_getType);
    oluacls_func(L, "getUserData", _olua_fun_b2Fixture_getUserData);
    oluacls_func(L, "isSensor", _olua_fun_b2Fixture_isSensor);
    oluacls_func(L, "rayCast", _olua_fun_b2Fixture_rayCast);
    oluacls_func(L, "refilter", _olua_fun_b2Fixture_refilter);
    oluacls_func(L, "setDensity", _olua_fun_b2Fixture_setDensity);
    oluacls_func(L, "setFilterData", _olua_fun_b2Fixture_setFilterData);
    oluacls_func(L, "setFriction", _olua_fun_b2Fixture_setFriction);
    oluacls_func(L, "setRestitution", _olua_fun_b2Fixture_setRestitution);
    oluacls_func(L, "setRestitutionThreshold", _olua_fun_b2Fixture_setRestitutionThreshold);
    oluacls_func(L, "setSensor", _olua_fun_b2Fixture_setSensor);
    oluacls_func(L, "testPoint", _olua_fun_b2Fixture_testPoint);
    oluacls_prop(L, "body", _olua_fun_b2Fixture_getBody, nullptr);
    oluacls_prop(L, "density", _olua_fun_b2Fixture_getDensity, _olua_fun_b2Fixture_setDensity);
    oluacls_prop(L, "filterData", _olua_fun_b2Fixture_getFilterData, _olua_fun_b2Fixture_setFilterData);
    oluacls_prop(L, "friction", _olua_fun_b2Fixture_getFriction, _olua_fun_b2Fixture_setFriction);
    oluacls_prop(L, "next", _olua_fun_b2Fixture_getNext, nullptr);
    oluacls_prop(L, "restitution", _olua_fun_b2Fixture_getRestitution, _olua_fun_b2Fixture_setRestitution);
    oluacls_prop(L, "restitutionThreshold", _olua_fun_b2Fixture_getRestitutionThreshold, _olua_fun_b2Fixture_setRestitutionThreshold);
    oluacls_prop(L, "sensor", _olua_fun_b2Fixture_isSensor, _olua_fun_b2Fixture_setSensor);
    oluacls_prop(L, "shape", _olua_fun_b2Fixture_getShape, nullptr);
    oluacls_prop(L, "type", _olua_fun_b2Fixture_getType, nullptr);
    oluacls_prop(L, "userData", _olua_fun_b2Fixture_getUserData, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_Fixture(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.Fixture")) {
        luaL_error(L, "class not found: b2Fixture");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2JointDef___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2JointDef *)olua_toobj(L, 1, "b2.JointDef");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2JointDef_bodyA$1(lua_State *L)
{
    olua_startinvoke(L);

    b2JointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.JointDef");

    // b2Body *bodyA
    b2Body *ret = self->bodyA;
    int num_ret = olua_push_object(L, ret, "b2.Body");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2JointDef_bodyA$2(lua_State *L)
{
    olua_startinvoke(L);

    b2JointDef *self = nullptr;
    b2Body *arg1 = nullptr;       /** bodyA */

    olua_to_object(L, 1, &self, "b2.JointDef");
    olua_check_object(L, 2, &arg1, "b2.Body");

    // b2Body *bodyA
    self->bodyA = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2JointDef_bodyA(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Body *bodyA
        return _olua_fun_b2JointDef_bodyA$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.JointDef")) && (olua_is_object(L, 2, "b2.Body"))) {
            // b2Body *bodyA
            return _olua_fun_b2JointDef_bodyA$2(L);
        // }
    }

    luaL_error(L, "method 'b2JointDef::bodyA' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2JointDef_bodyB$1(lua_State *L)
{
    olua_startinvoke(L);

    b2JointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.JointDef");

    // b2Body *bodyB
    b2Body *ret = self->bodyB;
    int num_ret = olua_push_object(L, ret, "b2.Body");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2JointDef_bodyB$2(lua_State *L)
{
    olua_startinvoke(L);

    b2JointDef *self = nullptr;
    b2Body *arg1 = nullptr;       /** bodyB */

    olua_to_object(L, 1, &self, "b2.JointDef");
    olua_check_object(L, 2, &arg1, "b2.Body");

    // b2Body *bodyB
    self->bodyB = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2JointDef_bodyB(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Body *bodyB
        return _olua_fun_b2JointDef_bodyB$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.JointDef")) && (olua_is_object(L, 2, "b2.Body"))) {
            // b2Body *bodyB
            return _olua_fun_b2JointDef_bodyB$2(L);
        // }
    }

    luaL_error(L, "method 'b2JointDef::bodyB' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2JointDef_collideConnected$1(lua_State *L)
{
    olua_startinvoke(L);

    b2JointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.JointDef");

    // bool collideConnected
    bool ret = self->collideConnected;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2JointDef_collideConnected$2(lua_State *L)
{
    olua_startinvoke(L);

    b2JointDef *self = nullptr;
    bool arg1 = false;       /** collideConnected */

    olua_to_object(L, 1, &self, "b2.JointDef");
    olua_check_bool(L, 2, &arg1);

    // bool collideConnected
    self->collideConnected = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2JointDef_collideConnected(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool collideConnected
        return _olua_fun_b2JointDef_collideConnected$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.JointDef")) && (olua_is_bool(L, 2))) {
            // bool collideConnected
            return _olua_fun_b2JointDef_collideConnected$2(L);
        // }
    }

    luaL_error(L, "method 'b2JointDef::collideConnected' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2JointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2JointDef()
    b2JointDef *ret = new b2JointDef();
    int num_ret = olua_push_object(L, ret, "b2.JointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2JointDef_type$1(lua_State *L)
{
    olua_startinvoke(L);

    b2JointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.JointDef");

    // b2JointType type
    b2JointType ret = self->type;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2JointDef_type$2(lua_State *L)
{
    olua_startinvoke(L);

    b2JointDef *self = nullptr;
    b2JointType arg1 = (b2JointType)0;       /** type */

    olua_to_object(L, 1, &self, "b2.JointDef");
    olua_check_enum(L, 2, &arg1);

    // b2JointType type
    self->type = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2JointDef_type(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2JointType type
        return _olua_fun_b2JointDef_type$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.JointDef")) && (olua_is_enum(L, 2))) {
            // b2JointType type
            return _olua_fun_b2JointDef_type$2(L);
        // }
    }

    luaL_error(L, "method 'b2JointDef::type' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2JointDef_userData$1(lua_State *L)
{
    olua_startinvoke(L);

    b2JointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.JointDef");

    // b2JointUserData userData
    b2JointUserData &ret = self->userData;
    int num_ret = olua_copy_object(L, ret, "b2.JointUserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2JointDef_userData$2(lua_State *L)
{
    olua_startinvoke(L);

    b2JointDef *self = nullptr;
    b2JointUserData *arg1;       /** userData */

    olua_to_object(L, 1, &self, "b2.JointDef");
    olua_check_object(L, 2, &arg1, "b2.JointUserData");

    // b2JointUserData userData
    self->userData = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2JointDef_userData(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2JointUserData userData
        return _olua_fun_b2JointDef_userData$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.JointDef")) && (olua_is_object(L, 2, "b2.JointUserData"))) {
            // b2JointUserData userData
            return _olua_fun_b2JointDef_userData$2(L);
        // }
    }

    luaL_error(L, "method 'b2JointDef::userData' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_JointDef(lua_State *L)
{
    oluacls_class<b2JointDef>(L, "b2.JointDef");
    oluacls_func(L, "__gc", _olua_fun_b2JointDef___gc);
    oluacls_func(L, "new", _olua_fun_b2JointDef_new);
    oluacls_prop(L, "type", _olua_fun_b2JointDef_type, _olua_fun_b2JointDef_type);
    oluacls_prop(L, "userData", _olua_fun_b2JointDef_userData, _olua_fun_b2JointDef_userData);
    oluacls_prop(L, "bodyA", _olua_fun_b2JointDef_bodyA, _olua_fun_b2JointDef_bodyA);
    oluacls_prop(L, "bodyB", _olua_fun_b2JointDef_bodyB, _olua_fun_b2JointDef_bodyB);
    oluacls_prop(L, "collideConnected", _olua_fun_b2JointDef_collideConnected, _olua_fun_b2JointDef_collideConnected);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_JointDef(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.JointDef")) {
        luaL_error(L, "class not found: b2JointDef");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_b2_JointType(lua_State *L)
{
    oluacls_class<b2JointType>(L, "b2.JointType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "distanceJoint", (lua_Integer)b2JointType::e_distanceJoint);
    oluacls_enum(L, "frictionJoint", (lua_Integer)b2JointType::e_frictionJoint);
    oluacls_enum(L, "gearJoint", (lua_Integer)b2JointType::e_gearJoint);
    oluacls_enum(L, "motorJoint", (lua_Integer)b2JointType::e_motorJoint);
    oluacls_enum(L, "mouseJoint", (lua_Integer)b2JointType::e_mouseJoint);
    oluacls_enum(L, "prismaticJoint", (lua_Integer)b2JointType::e_prismaticJoint);
    oluacls_enum(L, "pulleyJoint", (lua_Integer)b2JointType::e_pulleyJoint);
    oluacls_enum(L, "revoluteJoint", (lua_Integer)b2JointType::e_revoluteJoint);
    oluacls_enum(L, "unknownJoint", (lua_Integer)b2JointType::e_unknownJoint);
    oluacls_enum(L, "weldJoint", (lua_Integer)b2JointType::e_weldJoint);
    oluacls_enum(L, "wheelJoint", (lua_Integer)b2JointType::e_wheelJoint);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_JointType(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.JointType")) {
        luaL_error(L, "class not found: b2JointType");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2Joint_draw(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;
    b2Draw *arg1 = nullptr;       /** draw */

    olua_to_object(L, 1, &self, "b2.Joint");
    olua_check_object(L, 2, &arg1, "b2.interface.Draw");

    // void Draw(b2Draw *draw)
    self->Draw(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Joint_dump(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Joint");

    // void Dump()
    self->Dump();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Joint_getAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Joint");

    // b2Vec2 GetAnchorA()
    b2Vec2 ret = self->GetAnchorA();
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Joint_getAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Joint");

    // b2Vec2 GetAnchorB()
    b2Vec2 ret = self->GetAnchorB();
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Joint_getBodyA(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Joint");

    // b2Body *GetBodyA()
    b2Body *ret = self->GetBodyA();
    int num_ret = olua_push_object(L, ret, "b2.Body");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Joint_getBodyB(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Joint");

    // b2Body *GetBodyB()
    b2Body *ret = self->GetBodyB();
    int num_ret = olua_push_object(L, ret, "b2.Body");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Joint_getCollideConnected(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Joint");

    // bool GetCollideConnected()
    bool ret = self->GetCollideConnected();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Joint_getNext(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Joint");

    // b2Joint *GetNext()
    b2Joint *ret = self->GetNext();
    int num_ret = olua_push_object(L, ret, "b2.Joint");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Joint_getReactionForce(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;
    float arg1 = 0;       /** inv_dt */

    olua_to_object(L, 1, &self, "b2.Joint");
    olua_check_number(L, 2, &arg1);

    // b2Vec2 GetReactionForce(float inv_dt)
    b2Vec2 ret = self->GetReactionForce(arg1);
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Joint_getReactionTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;
    float arg1 = 0;       /** inv_dt */

    olua_to_object(L, 1, &self, "b2.Joint");
    olua_check_number(L, 2, &arg1);

    // float GetReactionTorque(float inv_dt)
    float ret = self->GetReactionTorque(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Joint_getType(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Joint");

    // b2JointType GetType()
    b2JointType ret = self->GetType();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Joint_getUserData(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Joint");

    // b2JointUserData &GetUserData()
    b2JointUserData &ret = self->GetUserData();
    int num_ret = olua_push_object(L, &ret, "b2.JointUserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Joint_isEnabled(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Joint");

    // bool IsEnabled()
    bool ret = self->IsEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Joint_shiftOrigin(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;
    b2Vec2 *arg1;       /** newOrigin */

    olua_to_object(L, 1, &self, "b2.Joint");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // void ShiftOrigin(const b2Vec2 &newOrigin)
    self->ShiftOrigin(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_b2_Joint(lua_State *L)
{
    oluacls_class<b2Joint>(L, "b2.Joint");
    oluacls_func(L, "draw", _olua_fun_b2Joint_draw);
    oluacls_func(L, "dump", _olua_fun_b2Joint_dump);
    oluacls_func(L, "getAnchorA", _olua_fun_b2Joint_getAnchorA);
    oluacls_func(L, "getAnchorB", _olua_fun_b2Joint_getAnchorB);
    oluacls_func(L, "getBodyA", _olua_fun_b2Joint_getBodyA);
    oluacls_func(L, "getBodyB", _olua_fun_b2Joint_getBodyB);
    oluacls_func(L, "getCollideConnected", _olua_fun_b2Joint_getCollideConnected);
    oluacls_func(L, "getNext", _olua_fun_b2Joint_getNext);
    oluacls_func(L, "getReactionForce", _olua_fun_b2Joint_getReactionForce);
    oluacls_func(L, "getReactionTorque", _olua_fun_b2Joint_getReactionTorque);
    oluacls_func(L, "getType", _olua_fun_b2Joint_getType);
    oluacls_func(L, "getUserData", _olua_fun_b2Joint_getUserData);
    oluacls_func(L, "isEnabled", _olua_fun_b2Joint_isEnabled);
    oluacls_func(L, "shiftOrigin", _olua_fun_b2Joint_shiftOrigin);
    oluacls_prop(L, "anchorA", _olua_fun_b2Joint_getAnchorA, nullptr);
    oluacls_prop(L, "anchorB", _olua_fun_b2Joint_getAnchorB, nullptr);
    oluacls_prop(L, "bodyA", _olua_fun_b2Joint_getBodyA, nullptr);
    oluacls_prop(L, "bodyB", _olua_fun_b2Joint_getBodyB, nullptr);
    oluacls_prop(L, "collideConnected", _olua_fun_b2Joint_getCollideConnected, nullptr);
    oluacls_prop(L, "enabled", _olua_fun_b2Joint_isEnabled, nullptr);
    oluacls_prop(L, "next", _olua_fun_b2Joint_getNext, nullptr);
    oluacls_prop(L, "type", _olua_fun_b2Joint_getType, nullptr);
    oluacls_prop(L, "userData", _olua_fun_b2Joint_getUserData, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_Joint(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.Joint")) {
        luaL_error(L, "class not found: b2Joint");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2DistanceJointDef_damping$1(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.DistanceJointDef");

    // float damping
    float ret = self->damping;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2DistanceJointDef_damping$2(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;
    float arg1 = 0;       /** damping */

    olua_to_object(L, 1, &self, "b2.DistanceJointDef");
    olua_check_number(L, 2, &arg1);

    // float damping
    self->damping = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2DistanceJointDef_damping(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float damping
        return _olua_fun_b2DistanceJointDef_damping$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.DistanceJointDef")) && (olua_is_number(L, 2))) {
            // float damping
            return _olua_fun_b2DistanceJointDef_damping$2(L);
        // }
    }

    luaL_error(L, "method 'b2DistanceJointDef::damping' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2DistanceJointDef_initialize(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;
    b2Body *arg1 = nullptr;       /** bodyA */
    b2Body *arg2 = nullptr;       /** bodyB */
    b2Vec2 *arg3;       /** anchorA */
    b2Vec2 *arg4;       /** anchorB */

    olua_to_object(L, 1, &self, "b2.DistanceJointDef");
    olua_check_object(L, 2, &arg1, "b2.Body");
    olua_check_object(L, 3, &arg2, "b2.Body");
    olua_check_object(L, 4, &arg3, "b2.Vec2");
    olua_check_object(L, 5, &arg4, "b2.Vec2");

    // void Initialize(b2Body *bodyA, b2Body *bodyB, const b2Vec2 &anchorA, const b2Vec2 &anchorB)
    self->Initialize(arg1, arg2, *arg3, *arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2DistanceJointDef_length$1(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.DistanceJointDef");

    // float length
    float ret = self->length;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2DistanceJointDef_length$2(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;
    float arg1 = 0;       /** length */

    olua_to_object(L, 1, &self, "b2.DistanceJointDef");
    olua_check_number(L, 2, &arg1);

    // float length
    self->length = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2DistanceJointDef_length(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float length
        return _olua_fun_b2DistanceJointDef_length$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.DistanceJointDef")) && (olua_is_number(L, 2))) {
            // float length
            return _olua_fun_b2DistanceJointDef_length$2(L);
        // }
    }

    luaL_error(L, "method 'b2DistanceJointDef::length' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2DistanceJointDef_localAnchorA$1(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.DistanceJointDef");

    // b2Vec2 localAnchorA
    b2Vec2 &ret = self->localAnchorA;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2DistanceJointDef_localAnchorA$2(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;
    b2Vec2 *arg1;       /** localAnchorA */

    olua_to_object(L, 1, &self, "b2.DistanceJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAnchorA
    self->localAnchorA = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2DistanceJointDef_localAnchorA(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 localAnchorA
        return _olua_fun_b2DistanceJointDef_localAnchorA$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.DistanceJointDef")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 localAnchorA
            return _olua_fun_b2DistanceJointDef_localAnchorA$2(L);
        // }
    }

    luaL_error(L, "method 'b2DistanceJointDef::localAnchorA' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2DistanceJointDef_localAnchorB$1(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.DistanceJointDef");

    // b2Vec2 localAnchorB
    b2Vec2 &ret = self->localAnchorB;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2DistanceJointDef_localAnchorB$2(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;
    b2Vec2 *arg1;       /** localAnchorB */

    olua_to_object(L, 1, &self, "b2.DistanceJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAnchorB
    self->localAnchorB = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2DistanceJointDef_localAnchorB(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 localAnchorB
        return _olua_fun_b2DistanceJointDef_localAnchorB$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.DistanceJointDef")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 localAnchorB
            return _olua_fun_b2DistanceJointDef_localAnchorB$2(L);
        // }
    }

    luaL_error(L, "method 'b2DistanceJointDef::localAnchorB' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2DistanceJointDef_maxLength$1(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.DistanceJointDef");

    // float maxLength
    float ret = self->maxLength;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2DistanceJointDef_maxLength$2(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;
    float arg1 = 0;       /** maxLength */

    olua_to_object(L, 1, &self, "b2.DistanceJointDef");
    olua_check_number(L, 2, &arg1);

    // float maxLength
    self->maxLength = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2DistanceJointDef_maxLength(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float maxLength
        return _olua_fun_b2DistanceJointDef_maxLength$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.DistanceJointDef")) && (olua_is_number(L, 2))) {
            // float maxLength
            return _olua_fun_b2DistanceJointDef_maxLength$2(L);
        // }
    }

    luaL_error(L, "method 'b2DistanceJointDef::maxLength' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2DistanceJointDef_minLength$1(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.DistanceJointDef");

    // float minLength
    float ret = self->minLength;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2DistanceJointDef_minLength$2(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;
    float arg1 = 0;       /** minLength */

    olua_to_object(L, 1, &self, "b2.DistanceJointDef");
    olua_check_number(L, 2, &arg1);

    // float minLength
    self->minLength = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2DistanceJointDef_minLength(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float minLength
        return _olua_fun_b2DistanceJointDef_minLength$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.DistanceJointDef")) && (olua_is_number(L, 2))) {
            // float minLength
            return _olua_fun_b2DistanceJointDef_minLength$2(L);
        // }
    }

    luaL_error(L, "method 'b2DistanceJointDef::minLength' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2DistanceJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2DistanceJointDef()
    b2DistanceJointDef *ret = new b2DistanceJointDef();
    int num_ret = olua_push_object(L, ret, "b2.DistanceJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2DistanceJointDef_stiffness$1(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.DistanceJointDef");

    // float stiffness
    float ret = self->stiffness;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2DistanceJointDef_stiffness$2(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;
    float arg1 = 0;       /** stiffness */

    olua_to_object(L, 1, &self, "b2.DistanceJointDef");
    olua_check_number(L, 2, &arg1);

    // float stiffness
    self->stiffness = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2DistanceJointDef_stiffness(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float stiffness
        return _olua_fun_b2DistanceJointDef_stiffness$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.DistanceJointDef")) && (olua_is_number(L, 2))) {
            // float stiffness
            return _olua_fun_b2DistanceJointDef_stiffness$2(L);
        // }
    }

    luaL_error(L, "method 'b2DistanceJointDef::stiffness' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_DistanceJointDef(lua_State *L)
{
    oluacls_class<b2DistanceJointDef, b2JointDef>(L, "b2.DistanceJointDef");
    oluacls_func(L, "initialize", _olua_fun_b2DistanceJointDef_initialize);
    oluacls_func(L, "new", _olua_fun_b2DistanceJointDef_new);
    oluacls_prop(L, "localAnchorA", _olua_fun_b2DistanceJointDef_localAnchorA, _olua_fun_b2DistanceJointDef_localAnchorA);
    oluacls_prop(L, "localAnchorB", _olua_fun_b2DistanceJointDef_localAnchorB, _olua_fun_b2DistanceJointDef_localAnchorB);
    oluacls_prop(L, "length", _olua_fun_b2DistanceJointDef_length, _olua_fun_b2DistanceJointDef_length);
    oluacls_prop(L, "minLength", _olua_fun_b2DistanceJointDef_minLength, _olua_fun_b2DistanceJointDef_minLength);
    oluacls_prop(L, "maxLength", _olua_fun_b2DistanceJointDef_maxLength, _olua_fun_b2DistanceJointDef_maxLength);
    oluacls_prop(L, "stiffness", _olua_fun_b2DistanceJointDef_stiffness, _olua_fun_b2DistanceJointDef_stiffness);
    oluacls_prop(L, "damping", _olua_fun_b2DistanceJointDef_damping, _olua_fun_b2DistanceJointDef_damping);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_DistanceJointDef(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.DistanceJointDef")) {
        luaL_error(L, "class not found: b2DistanceJointDef");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2DistanceJoint___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2DistanceJoint *)olua_toobj(L, 1, "b2.DistanceJoint");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2DistanceJoint_getCurrentLength(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.DistanceJoint");

    // float GetCurrentLength()
    float ret = self->GetCurrentLength();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2DistanceJoint_getDamping(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.DistanceJoint");

    // float GetDamping()
    float ret = self->GetDamping();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2DistanceJoint_getLength(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.DistanceJoint");

    // float GetLength()
    float ret = self->GetLength();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2DistanceJoint_getLocalAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.DistanceJoint");

    // const b2Vec2 &GetLocalAnchorA()
    const b2Vec2 &ret = self->GetLocalAnchorA();
    int num_ret = olua_push_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2DistanceJoint_getLocalAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.DistanceJoint");

    // const b2Vec2 &GetLocalAnchorB()
    const b2Vec2 &ret = self->GetLocalAnchorB();
    int num_ret = olua_push_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2DistanceJoint_getMaxLength(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.DistanceJoint");

    // float GetMaxLength()
    float ret = self->GetMaxLength();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2DistanceJoint_getMinLength(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.DistanceJoint");

    // float GetMinLength()
    float ret = self->GetMinLength();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2DistanceJoint_getStiffness(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.DistanceJoint");

    // float GetStiffness()
    float ret = self->GetStiffness();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2DistanceJoint_setDamping(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJoint *self = nullptr;
    float arg1 = 0;       /** damping */

    olua_to_object(L, 1, &self, "b2.DistanceJoint");
    olua_check_number(L, 2, &arg1);

    // void SetDamping(float damping)
    self->SetDamping(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2DistanceJoint_setLength(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJoint *self = nullptr;
    float arg1 = 0;       /** length */

    olua_to_object(L, 1, &self, "b2.DistanceJoint");
    olua_check_number(L, 2, &arg1);

    // float SetLength(float length)
    float ret = self->SetLength(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2DistanceJoint_setMaxLength(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJoint *self = nullptr;
    float arg1 = 0;       /** maxLength */

    olua_to_object(L, 1, &self, "b2.DistanceJoint");
    olua_check_number(L, 2, &arg1);

    // float SetMaxLength(float maxLength)
    float ret = self->SetMaxLength(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2DistanceJoint_setMinLength(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJoint *self = nullptr;
    float arg1 = 0;       /** minLength */

    olua_to_object(L, 1, &self, "b2.DistanceJoint");
    olua_check_number(L, 2, &arg1);

    // float SetMinLength(float minLength)
    float ret = self->SetMinLength(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2DistanceJoint_setStiffness(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJoint *self = nullptr;
    float arg1 = 0;       /** stiffness */

    olua_to_object(L, 1, &self, "b2.DistanceJoint");
    olua_check_number(L, 2, &arg1);

    // void SetStiffness(float stiffness)
    self->SetStiffness(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_b2_DistanceJoint(lua_State *L)
{
    oluacls_class<b2DistanceJoint, b2Joint>(L, "b2.DistanceJoint");
    oluacls_func(L, "__gc", _olua_fun_b2DistanceJoint___gc);
    oluacls_func(L, "getCurrentLength", _olua_fun_b2DistanceJoint_getCurrentLength);
    oluacls_func(L, "getDamping", _olua_fun_b2DistanceJoint_getDamping);
    oluacls_func(L, "getLength", _olua_fun_b2DistanceJoint_getLength);
    oluacls_func(L, "getLocalAnchorA", _olua_fun_b2DistanceJoint_getLocalAnchorA);
    oluacls_func(L, "getLocalAnchorB", _olua_fun_b2DistanceJoint_getLocalAnchorB);
    oluacls_func(L, "getMaxLength", _olua_fun_b2DistanceJoint_getMaxLength);
    oluacls_func(L, "getMinLength", _olua_fun_b2DistanceJoint_getMinLength);
    oluacls_func(L, "getStiffness", _olua_fun_b2DistanceJoint_getStiffness);
    oluacls_func(L, "setDamping", _olua_fun_b2DistanceJoint_setDamping);
    oluacls_func(L, "setLength", _olua_fun_b2DistanceJoint_setLength);
    oluacls_func(L, "setMaxLength", _olua_fun_b2DistanceJoint_setMaxLength);
    oluacls_func(L, "setMinLength", _olua_fun_b2DistanceJoint_setMinLength);
    oluacls_func(L, "setStiffness", _olua_fun_b2DistanceJoint_setStiffness);
    oluacls_prop(L, "currentLength", _olua_fun_b2DistanceJoint_getCurrentLength, nullptr);
    oluacls_prop(L, "damping", _olua_fun_b2DistanceJoint_getDamping, _olua_fun_b2DistanceJoint_setDamping);
    oluacls_prop(L, "length", _olua_fun_b2DistanceJoint_getLength, _olua_fun_b2DistanceJoint_setLength);
    oluacls_prop(L, "localAnchorA", _olua_fun_b2DistanceJoint_getLocalAnchorA, nullptr);
    oluacls_prop(L, "localAnchorB", _olua_fun_b2DistanceJoint_getLocalAnchorB, nullptr);
    oluacls_prop(L, "maxLength", _olua_fun_b2DistanceJoint_getMaxLength, _olua_fun_b2DistanceJoint_setMaxLength);
    oluacls_prop(L, "minLength", _olua_fun_b2DistanceJoint_getMinLength, _olua_fun_b2DistanceJoint_setMinLength);
    oluacls_prop(L, "stiffness", _olua_fun_b2DistanceJoint_getStiffness, _olua_fun_b2DistanceJoint_setStiffness);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_DistanceJoint(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.DistanceJoint")) {
        luaL_error(L, "class not found: b2DistanceJoint");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2FrictionJointDef_initialize(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJointDef *self = nullptr;
    b2Body *arg1 = nullptr;       /** bodyA */
    b2Body *arg2 = nullptr;       /** bodyB */
    b2Vec2 *arg3;       /** anchor */

    olua_to_object(L, 1, &self, "b2.FrictionJointDef");
    olua_check_object(L, 2, &arg1, "b2.Body");
    olua_check_object(L, 3, &arg2, "b2.Body");
    olua_check_object(L, 4, &arg3, "b2.Vec2");

    // void Initialize(b2Body *bodyA, b2Body *bodyB, const b2Vec2 &anchor)
    self->Initialize(arg1, arg2, *arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2FrictionJointDef_localAnchorA$1(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.FrictionJointDef");

    // b2Vec2 localAnchorA
    b2Vec2 &ret = self->localAnchorA;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2FrictionJointDef_localAnchorA$2(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJointDef *self = nullptr;
    b2Vec2 *arg1;       /** localAnchorA */

    olua_to_object(L, 1, &self, "b2.FrictionJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAnchorA
    self->localAnchorA = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2FrictionJointDef_localAnchorA(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 localAnchorA
        return _olua_fun_b2FrictionJointDef_localAnchorA$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.FrictionJointDef")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 localAnchorA
            return _olua_fun_b2FrictionJointDef_localAnchorA$2(L);
        // }
    }

    luaL_error(L, "method 'b2FrictionJointDef::localAnchorA' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2FrictionJointDef_localAnchorB$1(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.FrictionJointDef");

    // b2Vec2 localAnchorB
    b2Vec2 &ret = self->localAnchorB;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2FrictionJointDef_localAnchorB$2(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJointDef *self = nullptr;
    b2Vec2 *arg1;       /** localAnchorB */

    olua_to_object(L, 1, &self, "b2.FrictionJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAnchorB
    self->localAnchorB = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2FrictionJointDef_localAnchorB(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 localAnchorB
        return _olua_fun_b2FrictionJointDef_localAnchorB$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.FrictionJointDef")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 localAnchorB
            return _olua_fun_b2FrictionJointDef_localAnchorB$2(L);
        // }
    }

    luaL_error(L, "method 'b2FrictionJointDef::localAnchorB' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2FrictionJointDef_maxForce$1(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.FrictionJointDef");

    // float maxForce
    float ret = self->maxForce;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2FrictionJointDef_maxForce$2(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJointDef *self = nullptr;
    float arg1 = 0;       /** maxForce */

    olua_to_object(L, 1, &self, "b2.FrictionJointDef");
    olua_check_number(L, 2, &arg1);

    // float maxForce
    self->maxForce = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2FrictionJointDef_maxForce(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float maxForce
        return _olua_fun_b2FrictionJointDef_maxForce$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.FrictionJointDef")) && (olua_is_number(L, 2))) {
            // float maxForce
            return _olua_fun_b2FrictionJointDef_maxForce$2(L);
        // }
    }

    luaL_error(L, "method 'b2FrictionJointDef::maxForce' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2FrictionJointDef_maxTorque$1(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.FrictionJointDef");

    // float maxTorque
    float ret = self->maxTorque;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2FrictionJointDef_maxTorque$2(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJointDef *self = nullptr;
    float arg1 = 0;       /** maxTorque */

    olua_to_object(L, 1, &self, "b2.FrictionJointDef");
    olua_check_number(L, 2, &arg1);

    // float maxTorque
    self->maxTorque = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2FrictionJointDef_maxTorque(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float maxTorque
        return _olua_fun_b2FrictionJointDef_maxTorque$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.FrictionJointDef")) && (olua_is_number(L, 2))) {
            // float maxTorque
            return _olua_fun_b2FrictionJointDef_maxTorque$2(L);
        // }
    }

    luaL_error(L, "method 'b2FrictionJointDef::maxTorque' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2FrictionJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2FrictionJointDef()
    b2FrictionJointDef *ret = new b2FrictionJointDef();
    int num_ret = olua_push_object(L, ret, "b2.FrictionJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_b2_FrictionJointDef(lua_State *L)
{
    oluacls_class<b2FrictionJointDef, b2JointDef>(L, "b2.FrictionJointDef");
    oluacls_func(L, "initialize", _olua_fun_b2FrictionJointDef_initialize);
    oluacls_func(L, "new", _olua_fun_b2FrictionJointDef_new);
    oluacls_prop(L, "localAnchorA", _olua_fun_b2FrictionJointDef_localAnchorA, _olua_fun_b2FrictionJointDef_localAnchorA);
    oluacls_prop(L, "localAnchorB", _olua_fun_b2FrictionJointDef_localAnchorB, _olua_fun_b2FrictionJointDef_localAnchorB);
    oluacls_prop(L, "maxForce", _olua_fun_b2FrictionJointDef_maxForce, _olua_fun_b2FrictionJointDef_maxForce);
    oluacls_prop(L, "maxTorque", _olua_fun_b2FrictionJointDef_maxTorque, _olua_fun_b2FrictionJointDef_maxTorque);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_FrictionJointDef(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.FrictionJointDef")) {
        luaL_error(L, "class not found: b2FrictionJointDef");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2FrictionJoint___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2FrictionJoint *)olua_toobj(L, 1, "b2.FrictionJoint");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2FrictionJoint_getLocalAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.FrictionJoint");

    // const b2Vec2 &GetLocalAnchorA()
    const b2Vec2 &ret = self->GetLocalAnchorA();
    int num_ret = olua_push_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2FrictionJoint_getLocalAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.FrictionJoint");

    // const b2Vec2 &GetLocalAnchorB()
    const b2Vec2 &ret = self->GetLocalAnchorB();
    int num_ret = olua_push_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2FrictionJoint_getMaxForce(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.FrictionJoint");

    // float GetMaxForce()
    float ret = self->GetMaxForce();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2FrictionJoint_getMaxTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.FrictionJoint");

    // float GetMaxTorque()
    float ret = self->GetMaxTorque();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2FrictionJoint_setMaxForce(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJoint *self = nullptr;
    float arg1 = 0;       /** force */

    olua_to_object(L, 1, &self, "b2.FrictionJoint");
    olua_check_number(L, 2, &arg1);

    // void SetMaxForce(float force)
    self->SetMaxForce(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2FrictionJoint_setMaxTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJoint *self = nullptr;
    float arg1 = 0;       /** torque */

    olua_to_object(L, 1, &self, "b2.FrictionJoint");
    olua_check_number(L, 2, &arg1);

    // void SetMaxTorque(float torque)
    self->SetMaxTorque(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_b2_FrictionJoint(lua_State *L)
{
    oluacls_class<b2FrictionJoint, b2Joint>(L, "b2.FrictionJoint");
    oluacls_func(L, "__gc", _olua_fun_b2FrictionJoint___gc);
    oluacls_func(L, "getLocalAnchorA", _olua_fun_b2FrictionJoint_getLocalAnchorA);
    oluacls_func(L, "getLocalAnchorB", _olua_fun_b2FrictionJoint_getLocalAnchorB);
    oluacls_func(L, "getMaxForce", _olua_fun_b2FrictionJoint_getMaxForce);
    oluacls_func(L, "getMaxTorque", _olua_fun_b2FrictionJoint_getMaxTorque);
    oluacls_func(L, "setMaxForce", _olua_fun_b2FrictionJoint_setMaxForce);
    oluacls_func(L, "setMaxTorque", _olua_fun_b2FrictionJoint_setMaxTorque);
    oluacls_prop(L, "localAnchorA", _olua_fun_b2FrictionJoint_getLocalAnchorA, nullptr);
    oluacls_prop(L, "localAnchorB", _olua_fun_b2FrictionJoint_getLocalAnchorB, nullptr);
    oluacls_prop(L, "maxForce", _olua_fun_b2FrictionJoint_getMaxForce, _olua_fun_b2FrictionJoint_setMaxForce);
    oluacls_prop(L, "maxTorque", _olua_fun_b2FrictionJoint_getMaxTorque, _olua_fun_b2FrictionJoint_setMaxTorque);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_FrictionJoint(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.FrictionJoint")) {
        luaL_error(L, "class not found: b2FrictionJoint");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2GearJointDef_joint1$1(lua_State *L)
{
    olua_startinvoke(L);

    b2GearJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.GearJointDef");

    // b2Joint *joint1
    b2Joint *ret = self->joint1;
    int num_ret = olua_push_object(L, ret, "b2.Joint");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2GearJointDef_joint1$2(lua_State *L)
{
    olua_startinvoke(L);

    b2GearJointDef *self = nullptr;
    b2Joint *arg1 = nullptr;       /** joint1 */

    olua_to_object(L, 1, &self, "b2.GearJointDef");
    olua_check_object(L, 2, &arg1, "b2.Joint");

    // b2Joint *joint1
    self->joint1 = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2GearJointDef_joint1(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Joint *joint1
        return _olua_fun_b2GearJointDef_joint1$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.GearJointDef")) && (olua_is_object(L, 2, "b2.Joint"))) {
            // b2Joint *joint1
            return _olua_fun_b2GearJointDef_joint1$2(L);
        // }
    }

    luaL_error(L, "method 'b2GearJointDef::joint1' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2GearJointDef_joint2$1(lua_State *L)
{
    olua_startinvoke(L);

    b2GearJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.GearJointDef");

    // b2Joint *joint2
    b2Joint *ret = self->joint2;
    int num_ret = olua_push_object(L, ret, "b2.Joint");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2GearJointDef_joint2$2(lua_State *L)
{
    olua_startinvoke(L);

    b2GearJointDef *self = nullptr;
    b2Joint *arg1 = nullptr;       /** joint2 */

    olua_to_object(L, 1, &self, "b2.GearJointDef");
    olua_check_object(L, 2, &arg1, "b2.Joint");

    // b2Joint *joint2
    self->joint2 = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2GearJointDef_joint2(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Joint *joint2
        return _olua_fun_b2GearJointDef_joint2$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.GearJointDef")) && (olua_is_object(L, 2, "b2.Joint"))) {
            // b2Joint *joint2
            return _olua_fun_b2GearJointDef_joint2$2(L);
        // }
    }

    luaL_error(L, "method 'b2GearJointDef::joint2' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2GearJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2GearJointDef()
    b2GearJointDef *ret = new b2GearJointDef();
    int num_ret = olua_push_object(L, ret, "b2.GearJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2GearJointDef_ratio$1(lua_State *L)
{
    olua_startinvoke(L);

    b2GearJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.GearJointDef");

    // float ratio
    float ret = self->ratio;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2GearJointDef_ratio$2(lua_State *L)
{
    olua_startinvoke(L);

    b2GearJointDef *self = nullptr;
    float arg1 = 0;       /** ratio */

    olua_to_object(L, 1, &self, "b2.GearJointDef");
    olua_check_number(L, 2, &arg1);

    // float ratio
    self->ratio = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2GearJointDef_ratio(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float ratio
        return _olua_fun_b2GearJointDef_ratio$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.GearJointDef")) && (olua_is_number(L, 2))) {
            // float ratio
            return _olua_fun_b2GearJointDef_ratio$2(L);
        // }
    }

    luaL_error(L, "method 'b2GearJointDef::ratio' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_GearJointDef(lua_State *L)
{
    oluacls_class<b2GearJointDef, b2JointDef>(L, "b2.GearJointDef");
    oluacls_func(L, "new", _olua_fun_b2GearJointDef_new);
    oluacls_prop(L, "joint1", _olua_fun_b2GearJointDef_joint1, _olua_fun_b2GearJointDef_joint1);
    oluacls_prop(L, "joint2", _olua_fun_b2GearJointDef_joint2, _olua_fun_b2GearJointDef_joint2);
    oluacls_prop(L, "ratio", _olua_fun_b2GearJointDef_ratio, _olua_fun_b2GearJointDef_ratio);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_GearJointDef(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.GearJointDef")) {
        luaL_error(L, "class not found: b2GearJointDef");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2GearJoint___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2GearJoint *)olua_toobj(L, 1, "b2.GearJoint");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2GearJoint_getJoint1(lua_State *L)
{
    olua_startinvoke(L);

    b2GearJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.GearJoint");

    // b2Joint *GetJoint1()
    b2Joint *ret = self->GetJoint1();
    int num_ret = olua_push_object(L, ret, "b2.Joint");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2GearJoint_getJoint2(lua_State *L)
{
    olua_startinvoke(L);

    b2GearJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.GearJoint");

    // b2Joint *GetJoint2()
    b2Joint *ret = self->GetJoint2();
    int num_ret = olua_push_object(L, ret, "b2.Joint");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2GearJoint_getRatio(lua_State *L)
{
    olua_startinvoke(L);

    b2GearJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.GearJoint");

    // float GetRatio()
    float ret = self->GetRatio();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2GearJoint_setRatio(lua_State *L)
{
    olua_startinvoke(L);

    b2GearJoint *self = nullptr;
    float arg1 = 0;       /** ratio */

    olua_to_object(L, 1, &self, "b2.GearJoint");
    olua_check_number(L, 2, &arg1);

    // void SetRatio(float ratio)
    self->SetRatio(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_b2_GearJoint(lua_State *L)
{
    oluacls_class<b2GearJoint, b2Joint>(L, "b2.GearJoint");
    oluacls_func(L, "__gc", _olua_fun_b2GearJoint___gc);
    oluacls_func(L, "getJoint1", _olua_fun_b2GearJoint_getJoint1);
    oluacls_func(L, "getJoint2", _olua_fun_b2GearJoint_getJoint2);
    oluacls_func(L, "getRatio", _olua_fun_b2GearJoint_getRatio);
    oluacls_func(L, "setRatio", _olua_fun_b2GearJoint_setRatio);
    oluacls_prop(L, "joint1", _olua_fun_b2GearJoint_getJoint1, nullptr);
    oluacls_prop(L, "joint2", _olua_fun_b2GearJoint_getJoint2, nullptr);
    oluacls_prop(L, "ratio", _olua_fun_b2GearJoint_getRatio, _olua_fun_b2GearJoint_setRatio);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_GearJoint(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.GearJoint")) {
        luaL_error(L, "class not found: b2GearJoint");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2MotorJointDef_angularOffset$1(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.MotorJointDef");

    // float angularOffset
    float ret = self->angularOffset;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2MotorJointDef_angularOffset$2(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJointDef *self = nullptr;
    float arg1 = 0;       /** angularOffset */

    olua_to_object(L, 1, &self, "b2.MotorJointDef");
    olua_check_number(L, 2, &arg1);

    // float angularOffset
    self->angularOffset = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2MotorJointDef_angularOffset(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float angularOffset
        return _olua_fun_b2MotorJointDef_angularOffset$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.MotorJointDef")) && (olua_is_number(L, 2))) {
            // float angularOffset
            return _olua_fun_b2MotorJointDef_angularOffset$2(L);
        // }
    }

    luaL_error(L, "method 'b2MotorJointDef::angularOffset' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2MotorJointDef_correctionFactor$1(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.MotorJointDef");

    // float correctionFactor
    float ret = self->correctionFactor;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2MotorJointDef_correctionFactor$2(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJointDef *self = nullptr;
    float arg1 = 0;       /** correctionFactor */

    olua_to_object(L, 1, &self, "b2.MotorJointDef");
    olua_check_number(L, 2, &arg1);

    // float correctionFactor
    self->correctionFactor = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2MotorJointDef_correctionFactor(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float correctionFactor
        return _olua_fun_b2MotorJointDef_correctionFactor$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.MotorJointDef")) && (olua_is_number(L, 2))) {
            // float correctionFactor
            return _olua_fun_b2MotorJointDef_correctionFactor$2(L);
        // }
    }

    luaL_error(L, "method 'b2MotorJointDef::correctionFactor' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2MotorJointDef_initialize(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJointDef *self = nullptr;
    b2Body *arg1 = nullptr;       /** bodyA */
    b2Body *arg2 = nullptr;       /** bodyB */

    olua_to_object(L, 1, &self, "b2.MotorJointDef");
    olua_check_object(L, 2, &arg1, "b2.Body");
    olua_check_object(L, 3, &arg2, "b2.Body");

    // void Initialize(b2Body *bodyA, b2Body *bodyB)
    self->Initialize(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2MotorJointDef_linearOffset$1(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.MotorJointDef");

    // b2Vec2 linearOffset
    b2Vec2 &ret = self->linearOffset;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2MotorJointDef_linearOffset$2(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJointDef *self = nullptr;
    b2Vec2 *arg1;       /** linearOffset */

    olua_to_object(L, 1, &self, "b2.MotorJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 linearOffset
    self->linearOffset = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2MotorJointDef_linearOffset(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 linearOffset
        return _olua_fun_b2MotorJointDef_linearOffset$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.MotorJointDef")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 linearOffset
            return _olua_fun_b2MotorJointDef_linearOffset$2(L);
        // }
    }

    luaL_error(L, "method 'b2MotorJointDef::linearOffset' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2MotorJointDef_maxForce$1(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.MotorJointDef");

    // float maxForce
    float ret = self->maxForce;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2MotorJointDef_maxForce$2(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJointDef *self = nullptr;
    float arg1 = 0;       /** maxForce */

    olua_to_object(L, 1, &self, "b2.MotorJointDef");
    olua_check_number(L, 2, &arg1);

    // float maxForce
    self->maxForce = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2MotorJointDef_maxForce(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float maxForce
        return _olua_fun_b2MotorJointDef_maxForce$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.MotorJointDef")) && (olua_is_number(L, 2))) {
            // float maxForce
            return _olua_fun_b2MotorJointDef_maxForce$2(L);
        // }
    }

    luaL_error(L, "method 'b2MotorJointDef::maxForce' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2MotorJointDef_maxTorque$1(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.MotorJointDef");

    // float maxTorque
    float ret = self->maxTorque;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2MotorJointDef_maxTorque$2(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJointDef *self = nullptr;
    float arg1 = 0;       /** maxTorque */

    olua_to_object(L, 1, &self, "b2.MotorJointDef");
    olua_check_number(L, 2, &arg1);

    // float maxTorque
    self->maxTorque = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2MotorJointDef_maxTorque(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float maxTorque
        return _olua_fun_b2MotorJointDef_maxTorque$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.MotorJointDef")) && (olua_is_number(L, 2))) {
            // float maxTorque
            return _olua_fun_b2MotorJointDef_maxTorque$2(L);
        // }
    }

    luaL_error(L, "method 'b2MotorJointDef::maxTorque' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2MotorJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2MotorJointDef()
    b2MotorJointDef *ret = new b2MotorJointDef();
    int num_ret = olua_push_object(L, ret, "b2.MotorJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_b2_MotorJointDef(lua_State *L)
{
    oluacls_class<b2MotorJointDef, b2JointDef>(L, "b2.MotorJointDef");
    oluacls_func(L, "initialize", _olua_fun_b2MotorJointDef_initialize);
    oluacls_func(L, "new", _olua_fun_b2MotorJointDef_new);
    oluacls_prop(L, "linearOffset", _olua_fun_b2MotorJointDef_linearOffset, _olua_fun_b2MotorJointDef_linearOffset);
    oluacls_prop(L, "angularOffset", _olua_fun_b2MotorJointDef_angularOffset, _olua_fun_b2MotorJointDef_angularOffset);
    oluacls_prop(L, "maxForce", _olua_fun_b2MotorJointDef_maxForce, _olua_fun_b2MotorJointDef_maxForce);
    oluacls_prop(L, "maxTorque", _olua_fun_b2MotorJointDef_maxTorque, _olua_fun_b2MotorJointDef_maxTorque);
    oluacls_prop(L, "correctionFactor", _olua_fun_b2MotorJointDef_correctionFactor, _olua_fun_b2MotorJointDef_correctionFactor);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_MotorJointDef(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.MotorJointDef")) {
        luaL_error(L, "class not found: b2MotorJointDef");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2MotorJoint___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2MotorJoint *)olua_toobj(L, 1, "b2.MotorJoint");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2MotorJoint_getAngularOffset(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.MotorJoint");

    // float GetAngularOffset()
    float ret = self->GetAngularOffset();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2MotorJoint_getCorrectionFactor(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.MotorJoint");

    // float GetCorrectionFactor()
    float ret = self->GetCorrectionFactor();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2MotorJoint_getLinearOffset(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.MotorJoint");

    // const b2Vec2 &GetLinearOffset()
    const b2Vec2 &ret = self->GetLinearOffset();
    int num_ret = olua_push_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2MotorJoint_getMaxForce(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.MotorJoint");

    // float GetMaxForce()
    float ret = self->GetMaxForce();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2MotorJoint_getMaxTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.MotorJoint");

    // float GetMaxTorque()
    float ret = self->GetMaxTorque();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2MotorJoint_setAngularOffset(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJoint *self = nullptr;
    float arg1 = 0;       /** angularOffset */

    olua_to_object(L, 1, &self, "b2.MotorJoint");
    olua_check_number(L, 2, &arg1);

    // void SetAngularOffset(float angularOffset)
    self->SetAngularOffset(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2MotorJoint_setCorrectionFactor(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJoint *self = nullptr;
    float arg1 = 0;       /** factor */

    olua_to_object(L, 1, &self, "b2.MotorJoint");
    olua_check_number(L, 2, &arg1);

    // void SetCorrectionFactor(float factor)
    self->SetCorrectionFactor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2MotorJoint_setLinearOffset(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJoint *self = nullptr;
    b2Vec2 *arg1;       /** linearOffset */

    olua_to_object(L, 1, &self, "b2.MotorJoint");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // void SetLinearOffset(const b2Vec2 &linearOffset)
    self->SetLinearOffset(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2MotorJoint_setMaxForce(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJoint *self = nullptr;
    float arg1 = 0;       /** force */

    olua_to_object(L, 1, &self, "b2.MotorJoint");
    olua_check_number(L, 2, &arg1);

    // void SetMaxForce(float force)
    self->SetMaxForce(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2MotorJoint_setMaxTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJoint *self = nullptr;
    float arg1 = 0;       /** torque */

    olua_to_object(L, 1, &self, "b2.MotorJoint");
    olua_check_number(L, 2, &arg1);

    // void SetMaxTorque(float torque)
    self->SetMaxTorque(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_b2_MotorJoint(lua_State *L)
{
    oluacls_class<b2MotorJoint, b2Joint>(L, "b2.MotorJoint");
    oluacls_func(L, "__gc", _olua_fun_b2MotorJoint___gc);
    oluacls_func(L, "getAngularOffset", _olua_fun_b2MotorJoint_getAngularOffset);
    oluacls_func(L, "getCorrectionFactor", _olua_fun_b2MotorJoint_getCorrectionFactor);
    oluacls_func(L, "getLinearOffset", _olua_fun_b2MotorJoint_getLinearOffset);
    oluacls_func(L, "getMaxForce", _olua_fun_b2MotorJoint_getMaxForce);
    oluacls_func(L, "getMaxTorque", _olua_fun_b2MotorJoint_getMaxTorque);
    oluacls_func(L, "setAngularOffset", _olua_fun_b2MotorJoint_setAngularOffset);
    oluacls_func(L, "setCorrectionFactor", _olua_fun_b2MotorJoint_setCorrectionFactor);
    oluacls_func(L, "setLinearOffset", _olua_fun_b2MotorJoint_setLinearOffset);
    oluacls_func(L, "setMaxForce", _olua_fun_b2MotorJoint_setMaxForce);
    oluacls_func(L, "setMaxTorque", _olua_fun_b2MotorJoint_setMaxTorque);
    oluacls_prop(L, "angularOffset", _olua_fun_b2MotorJoint_getAngularOffset, _olua_fun_b2MotorJoint_setAngularOffset);
    oluacls_prop(L, "correctionFactor", _olua_fun_b2MotorJoint_getCorrectionFactor, _olua_fun_b2MotorJoint_setCorrectionFactor);
    oluacls_prop(L, "linearOffset", _olua_fun_b2MotorJoint_getLinearOffset, _olua_fun_b2MotorJoint_setLinearOffset);
    oluacls_prop(L, "maxForce", _olua_fun_b2MotorJoint_getMaxForce, _olua_fun_b2MotorJoint_setMaxForce);
    oluacls_prop(L, "maxTorque", _olua_fun_b2MotorJoint_getMaxTorque, _olua_fun_b2MotorJoint_setMaxTorque);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_MotorJoint(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.MotorJoint")) {
        luaL_error(L, "class not found: b2MotorJoint");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2MouseJointDef_damping$1(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.MouseJointDef");

    // float damping
    float ret = self->damping;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2MouseJointDef_damping$2(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJointDef *self = nullptr;
    float arg1 = 0;       /** damping */

    olua_to_object(L, 1, &self, "b2.MouseJointDef");
    olua_check_number(L, 2, &arg1);

    // float damping
    self->damping = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2MouseJointDef_damping(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float damping
        return _olua_fun_b2MouseJointDef_damping$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.MouseJointDef")) && (olua_is_number(L, 2))) {
            // float damping
            return _olua_fun_b2MouseJointDef_damping$2(L);
        // }
    }

    luaL_error(L, "method 'b2MouseJointDef::damping' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2MouseJointDef_maxForce$1(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.MouseJointDef");

    // float maxForce
    float ret = self->maxForce;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2MouseJointDef_maxForce$2(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJointDef *self = nullptr;
    float arg1 = 0;       /** maxForce */

    olua_to_object(L, 1, &self, "b2.MouseJointDef");
    olua_check_number(L, 2, &arg1);

    // float maxForce
    self->maxForce = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2MouseJointDef_maxForce(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float maxForce
        return _olua_fun_b2MouseJointDef_maxForce$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.MouseJointDef")) && (olua_is_number(L, 2))) {
            // float maxForce
            return _olua_fun_b2MouseJointDef_maxForce$2(L);
        // }
    }

    luaL_error(L, "method 'b2MouseJointDef::maxForce' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2MouseJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2MouseJointDef()
    b2MouseJointDef *ret = new b2MouseJointDef();
    int num_ret = olua_push_object(L, ret, "b2.MouseJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2MouseJointDef_stiffness$1(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.MouseJointDef");

    // float stiffness
    float ret = self->stiffness;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2MouseJointDef_stiffness$2(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJointDef *self = nullptr;
    float arg1 = 0;       /** stiffness */

    olua_to_object(L, 1, &self, "b2.MouseJointDef");
    olua_check_number(L, 2, &arg1);

    // float stiffness
    self->stiffness = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2MouseJointDef_stiffness(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float stiffness
        return _olua_fun_b2MouseJointDef_stiffness$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.MouseJointDef")) && (olua_is_number(L, 2))) {
            // float stiffness
            return _olua_fun_b2MouseJointDef_stiffness$2(L);
        // }
    }

    luaL_error(L, "method 'b2MouseJointDef::stiffness' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2MouseJointDef_target$1(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.MouseJointDef");

    // b2Vec2 target
    b2Vec2 &ret = self->target;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2MouseJointDef_target$2(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJointDef *self = nullptr;
    b2Vec2 *arg1;       /** target */

    olua_to_object(L, 1, &self, "b2.MouseJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 target
    self->target = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2MouseJointDef_target(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 target
        return _olua_fun_b2MouseJointDef_target$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.MouseJointDef")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 target
            return _olua_fun_b2MouseJointDef_target$2(L);
        // }
    }

    luaL_error(L, "method 'b2MouseJointDef::target' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_MouseJointDef(lua_State *L)
{
    oluacls_class<b2MouseJointDef, b2JointDef>(L, "b2.MouseJointDef");
    oluacls_func(L, "new", _olua_fun_b2MouseJointDef_new);
    oluacls_prop(L, "target", _olua_fun_b2MouseJointDef_target, _olua_fun_b2MouseJointDef_target);
    oluacls_prop(L, "maxForce", _olua_fun_b2MouseJointDef_maxForce, _olua_fun_b2MouseJointDef_maxForce);
    oluacls_prop(L, "stiffness", _olua_fun_b2MouseJointDef_stiffness, _olua_fun_b2MouseJointDef_stiffness);
    oluacls_prop(L, "damping", _olua_fun_b2MouseJointDef_damping, _olua_fun_b2MouseJointDef_damping);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_MouseJointDef(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.MouseJointDef")) {
        luaL_error(L, "class not found: b2MouseJointDef");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2MouseJoint___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2MouseJoint *)olua_toobj(L, 1, "b2.MouseJoint");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2MouseJoint_getDamping(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.MouseJoint");

    // float GetDamping()
    float ret = self->GetDamping();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2MouseJoint_getMaxForce(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.MouseJoint");

    // float GetMaxForce()
    float ret = self->GetMaxForce();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2MouseJoint_getStiffness(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.MouseJoint");

    // float GetStiffness()
    float ret = self->GetStiffness();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2MouseJoint_getTarget(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.MouseJoint");

    // const b2Vec2 &GetTarget()
    const b2Vec2 &ret = self->GetTarget();
    int num_ret = olua_push_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2MouseJoint_setDamping(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJoint *self = nullptr;
    float arg1 = 0;       /** damping */

    olua_to_object(L, 1, &self, "b2.MouseJoint");
    olua_check_number(L, 2, &arg1);

    // void SetDamping(float damping)
    self->SetDamping(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2MouseJoint_setMaxForce(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJoint *self = nullptr;
    float arg1 = 0;       /** force */

    olua_to_object(L, 1, &self, "b2.MouseJoint");
    olua_check_number(L, 2, &arg1);

    // void SetMaxForce(float force)
    self->SetMaxForce(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2MouseJoint_setStiffness(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJoint *self = nullptr;
    float arg1 = 0;       /** stiffness */

    olua_to_object(L, 1, &self, "b2.MouseJoint");
    olua_check_number(L, 2, &arg1);

    // void SetStiffness(float stiffness)
    self->SetStiffness(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2MouseJoint_setTarget(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJoint *self = nullptr;
    b2Vec2 *arg1;       /** target */

    olua_to_object(L, 1, &self, "b2.MouseJoint");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // void SetTarget(const b2Vec2 &target)
    self->SetTarget(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_b2_MouseJoint(lua_State *L)
{
    oluacls_class<b2MouseJoint, b2Joint>(L, "b2.MouseJoint");
    oluacls_func(L, "__gc", _olua_fun_b2MouseJoint___gc);
    oluacls_func(L, "getDamping", _olua_fun_b2MouseJoint_getDamping);
    oluacls_func(L, "getMaxForce", _olua_fun_b2MouseJoint_getMaxForce);
    oluacls_func(L, "getStiffness", _olua_fun_b2MouseJoint_getStiffness);
    oluacls_func(L, "getTarget", _olua_fun_b2MouseJoint_getTarget);
    oluacls_func(L, "setDamping", _olua_fun_b2MouseJoint_setDamping);
    oluacls_func(L, "setMaxForce", _olua_fun_b2MouseJoint_setMaxForce);
    oluacls_func(L, "setStiffness", _olua_fun_b2MouseJoint_setStiffness);
    oluacls_func(L, "setTarget", _olua_fun_b2MouseJoint_setTarget);
    oluacls_prop(L, "damping", _olua_fun_b2MouseJoint_getDamping, _olua_fun_b2MouseJoint_setDamping);
    oluacls_prop(L, "maxForce", _olua_fun_b2MouseJoint_getMaxForce, _olua_fun_b2MouseJoint_setMaxForce);
    oluacls_prop(L, "stiffness", _olua_fun_b2MouseJoint_getStiffness, _olua_fun_b2MouseJoint_setStiffness);
    oluacls_prop(L, "target", _olua_fun_b2MouseJoint_getTarget, _olua_fun_b2MouseJoint_setTarget);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_MouseJoint(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.MouseJoint")) {
        luaL_error(L, "class not found: b2MouseJoint");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2PrismaticJointDef_enableLimit$1(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PrismaticJointDef");

    // bool enableLimit
    bool ret = self->enableLimit;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PrismaticJointDef_enableLimit$2(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;
    bool arg1 = false;       /** enableLimit */

    olua_to_object(L, 1, &self, "b2.PrismaticJointDef");
    olua_check_bool(L, 2, &arg1);

    // bool enableLimit
    self->enableLimit = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2PrismaticJointDef_enableLimit(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool enableLimit
        return _olua_fun_b2PrismaticJointDef_enableLimit$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.PrismaticJointDef")) && (olua_is_bool(L, 2))) {
            // bool enableLimit
            return _olua_fun_b2PrismaticJointDef_enableLimit$2(L);
        // }
    }

    luaL_error(L, "method 'b2PrismaticJointDef::enableLimit' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2PrismaticJointDef_enableMotor$1(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PrismaticJointDef");

    // bool enableMotor
    bool ret = self->enableMotor;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PrismaticJointDef_enableMotor$2(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;
    bool arg1 = false;       /** enableMotor */

    olua_to_object(L, 1, &self, "b2.PrismaticJointDef");
    olua_check_bool(L, 2, &arg1);

    // bool enableMotor
    self->enableMotor = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2PrismaticJointDef_enableMotor(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool enableMotor
        return _olua_fun_b2PrismaticJointDef_enableMotor$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.PrismaticJointDef")) && (olua_is_bool(L, 2))) {
            // bool enableMotor
            return _olua_fun_b2PrismaticJointDef_enableMotor$2(L);
        // }
    }

    luaL_error(L, "method 'b2PrismaticJointDef::enableMotor' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2PrismaticJointDef_initialize(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;
    b2Body *arg1 = nullptr;       /** bodyA */
    b2Body *arg2 = nullptr;       /** bodyB */
    b2Vec2 *arg3;       /** anchor */
    b2Vec2 *arg4;       /** axis */

    olua_to_object(L, 1, &self, "b2.PrismaticJointDef");
    olua_check_object(L, 2, &arg1, "b2.Body");
    olua_check_object(L, 3, &arg2, "b2.Body");
    olua_check_object(L, 4, &arg3, "b2.Vec2");
    olua_check_object(L, 5, &arg4, "b2.Vec2");

    // void Initialize(b2Body *bodyA, b2Body *bodyB, const b2Vec2 &anchor, const b2Vec2 &axis)
    self->Initialize(arg1, arg2, *arg3, *arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2PrismaticJointDef_localAnchorA$1(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PrismaticJointDef");

    // b2Vec2 localAnchorA
    b2Vec2 &ret = self->localAnchorA;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PrismaticJointDef_localAnchorA$2(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;
    b2Vec2 *arg1;       /** localAnchorA */

    olua_to_object(L, 1, &self, "b2.PrismaticJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAnchorA
    self->localAnchorA = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2PrismaticJointDef_localAnchorA(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 localAnchorA
        return _olua_fun_b2PrismaticJointDef_localAnchorA$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.PrismaticJointDef")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 localAnchorA
            return _olua_fun_b2PrismaticJointDef_localAnchorA$2(L);
        // }
    }

    luaL_error(L, "method 'b2PrismaticJointDef::localAnchorA' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2PrismaticJointDef_localAnchorB$1(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PrismaticJointDef");

    // b2Vec2 localAnchorB
    b2Vec2 &ret = self->localAnchorB;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PrismaticJointDef_localAnchorB$2(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;
    b2Vec2 *arg1;       /** localAnchorB */

    olua_to_object(L, 1, &self, "b2.PrismaticJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAnchorB
    self->localAnchorB = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2PrismaticJointDef_localAnchorB(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 localAnchorB
        return _olua_fun_b2PrismaticJointDef_localAnchorB$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.PrismaticJointDef")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 localAnchorB
            return _olua_fun_b2PrismaticJointDef_localAnchorB$2(L);
        // }
    }

    luaL_error(L, "method 'b2PrismaticJointDef::localAnchorB' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2PrismaticJointDef_localAxisA$1(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PrismaticJointDef");

    // b2Vec2 localAxisA
    b2Vec2 &ret = self->localAxisA;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PrismaticJointDef_localAxisA$2(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;
    b2Vec2 *arg1;       /** localAxisA */

    olua_to_object(L, 1, &self, "b2.PrismaticJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAxisA
    self->localAxisA = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2PrismaticJointDef_localAxisA(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 localAxisA
        return _olua_fun_b2PrismaticJointDef_localAxisA$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.PrismaticJointDef")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 localAxisA
            return _olua_fun_b2PrismaticJointDef_localAxisA$2(L);
        // }
    }

    luaL_error(L, "method 'b2PrismaticJointDef::localAxisA' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2PrismaticJointDef_lowerTranslation$1(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PrismaticJointDef");

    // float lowerTranslation
    float ret = self->lowerTranslation;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PrismaticJointDef_lowerTranslation$2(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;
    float arg1 = 0;       /** lowerTranslation */

    olua_to_object(L, 1, &self, "b2.PrismaticJointDef");
    olua_check_number(L, 2, &arg1);

    // float lowerTranslation
    self->lowerTranslation = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2PrismaticJointDef_lowerTranslation(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float lowerTranslation
        return _olua_fun_b2PrismaticJointDef_lowerTranslation$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.PrismaticJointDef")) && (olua_is_number(L, 2))) {
            // float lowerTranslation
            return _olua_fun_b2PrismaticJointDef_lowerTranslation$2(L);
        // }
    }

    luaL_error(L, "method 'b2PrismaticJointDef::lowerTranslation' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2PrismaticJointDef_maxMotorForce$1(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PrismaticJointDef");

    // float maxMotorForce
    float ret = self->maxMotorForce;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PrismaticJointDef_maxMotorForce$2(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;
    float arg1 = 0;       /** maxMotorForce */

    olua_to_object(L, 1, &self, "b2.PrismaticJointDef");
    olua_check_number(L, 2, &arg1);

    // float maxMotorForce
    self->maxMotorForce = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2PrismaticJointDef_maxMotorForce(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float maxMotorForce
        return _olua_fun_b2PrismaticJointDef_maxMotorForce$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.PrismaticJointDef")) && (olua_is_number(L, 2))) {
            // float maxMotorForce
            return _olua_fun_b2PrismaticJointDef_maxMotorForce$2(L);
        // }
    }

    luaL_error(L, "method 'b2PrismaticJointDef::maxMotorForce' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2PrismaticJointDef_motorSpeed$1(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PrismaticJointDef");

    // float motorSpeed
    float ret = self->motorSpeed;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PrismaticJointDef_motorSpeed$2(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;
    float arg1 = 0;       /** motorSpeed */

    olua_to_object(L, 1, &self, "b2.PrismaticJointDef");
    olua_check_number(L, 2, &arg1);

    // float motorSpeed
    self->motorSpeed = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2PrismaticJointDef_motorSpeed(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float motorSpeed
        return _olua_fun_b2PrismaticJointDef_motorSpeed$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.PrismaticJointDef")) && (olua_is_number(L, 2))) {
            // float motorSpeed
            return _olua_fun_b2PrismaticJointDef_motorSpeed$2(L);
        // }
    }

    luaL_error(L, "method 'b2PrismaticJointDef::motorSpeed' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2PrismaticJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2PrismaticJointDef()
    b2PrismaticJointDef *ret = new b2PrismaticJointDef();
    int num_ret = olua_push_object(L, ret, "b2.PrismaticJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PrismaticJointDef_referenceAngle$1(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PrismaticJointDef");

    // float referenceAngle
    float ret = self->referenceAngle;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PrismaticJointDef_referenceAngle$2(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;
    float arg1 = 0;       /** referenceAngle */

    olua_to_object(L, 1, &self, "b2.PrismaticJointDef");
    olua_check_number(L, 2, &arg1);

    // float referenceAngle
    self->referenceAngle = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2PrismaticJointDef_referenceAngle(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float referenceAngle
        return _olua_fun_b2PrismaticJointDef_referenceAngle$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.PrismaticJointDef")) && (olua_is_number(L, 2))) {
            // float referenceAngle
            return _olua_fun_b2PrismaticJointDef_referenceAngle$2(L);
        // }
    }

    luaL_error(L, "method 'b2PrismaticJointDef::referenceAngle' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2PrismaticJointDef_upperTranslation$1(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PrismaticJointDef");

    // float upperTranslation
    float ret = self->upperTranslation;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PrismaticJointDef_upperTranslation$2(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;
    float arg1 = 0;       /** upperTranslation */

    olua_to_object(L, 1, &self, "b2.PrismaticJointDef");
    olua_check_number(L, 2, &arg1);

    // float upperTranslation
    self->upperTranslation = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2PrismaticJointDef_upperTranslation(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float upperTranslation
        return _olua_fun_b2PrismaticJointDef_upperTranslation$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.PrismaticJointDef")) && (olua_is_number(L, 2))) {
            // float upperTranslation
            return _olua_fun_b2PrismaticJointDef_upperTranslation$2(L);
        // }
    }

    luaL_error(L, "method 'b2PrismaticJointDef::upperTranslation' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_PrismaticJointDef(lua_State *L)
{
    oluacls_class<b2PrismaticJointDef, b2JointDef>(L, "b2.PrismaticJointDef");
    oluacls_func(L, "initialize", _olua_fun_b2PrismaticJointDef_initialize);
    oluacls_func(L, "new", _olua_fun_b2PrismaticJointDef_new);
    oluacls_prop(L, "localAnchorA", _olua_fun_b2PrismaticJointDef_localAnchorA, _olua_fun_b2PrismaticJointDef_localAnchorA);
    oluacls_prop(L, "localAnchorB", _olua_fun_b2PrismaticJointDef_localAnchorB, _olua_fun_b2PrismaticJointDef_localAnchorB);
    oluacls_prop(L, "localAxisA", _olua_fun_b2PrismaticJointDef_localAxisA, _olua_fun_b2PrismaticJointDef_localAxisA);
    oluacls_prop(L, "referenceAngle", _olua_fun_b2PrismaticJointDef_referenceAngle, _olua_fun_b2PrismaticJointDef_referenceAngle);
    oluacls_prop(L, "enableLimit", _olua_fun_b2PrismaticJointDef_enableLimit, _olua_fun_b2PrismaticJointDef_enableLimit);
    oluacls_prop(L, "lowerTranslation", _olua_fun_b2PrismaticJointDef_lowerTranslation, _olua_fun_b2PrismaticJointDef_lowerTranslation);
    oluacls_prop(L, "upperTranslation", _olua_fun_b2PrismaticJointDef_upperTranslation, _olua_fun_b2PrismaticJointDef_upperTranslation);
    oluacls_prop(L, "enableMotor", _olua_fun_b2PrismaticJointDef_enableMotor, _olua_fun_b2PrismaticJointDef_enableMotor);
    oluacls_prop(L, "maxMotorForce", _olua_fun_b2PrismaticJointDef_maxMotorForce, _olua_fun_b2PrismaticJointDef_maxMotorForce);
    oluacls_prop(L, "motorSpeed", _olua_fun_b2PrismaticJointDef_motorSpeed, _olua_fun_b2PrismaticJointDef_motorSpeed);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_PrismaticJointDef(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.PrismaticJointDef")) {
        luaL_error(L, "class not found: b2PrismaticJointDef");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2PrismaticJoint___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2PrismaticJoint *)olua_toobj(L, 1, "b2.PrismaticJoint");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2PrismaticJoint_enableLimit(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_object(L, 1, &self, "b2.PrismaticJoint");
    olua_check_bool(L, 2, &arg1);

    // void EnableLimit(bool flag)
    self->EnableLimit(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2PrismaticJoint_enableMotor(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_object(L, 1, &self, "b2.PrismaticJoint");
    olua_check_bool(L, 2, &arg1);

    // void EnableMotor(bool flag)
    self->EnableMotor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2PrismaticJoint_getJointSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PrismaticJoint");

    // float GetJointSpeed()
    float ret = self->GetJointSpeed();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PrismaticJoint_getJointTranslation(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PrismaticJoint");

    // float GetJointTranslation()
    float ret = self->GetJointTranslation();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PrismaticJoint_getLocalAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PrismaticJoint");

    // const b2Vec2 &GetLocalAnchorA()
    const b2Vec2 &ret = self->GetLocalAnchorA();
    int num_ret = olua_push_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PrismaticJoint_getLocalAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PrismaticJoint");

    // const b2Vec2 &GetLocalAnchorB()
    const b2Vec2 &ret = self->GetLocalAnchorB();
    int num_ret = olua_push_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PrismaticJoint_getLocalAxisA(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PrismaticJoint");

    // const b2Vec2 &GetLocalAxisA()
    const b2Vec2 &ret = self->GetLocalAxisA();
    int num_ret = olua_push_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PrismaticJoint_getLowerLimit(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PrismaticJoint");

    // float GetLowerLimit()
    float ret = self->GetLowerLimit();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PrismaticJoint_getMaxMotorForce(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PrismaticJoint");

    // float GetMaxMotorForce()
    float ret = self->GetMaxMotorForce();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PrismaticJoint_getMotorForce(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;
    float arg1 = 0;       /** inv_dt */

    olua_to_object(L, 1, &self, "b2.PrismaticJoint");
    olua_check_number(L, 2, &arg1);

    // float GetMotorForce(float inv_dt)
    float ret = self->GetMotorForce(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PrismaticJoint_getMotorSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PrismaticJoint");

    // float GetMotorSpeed()
    float ret = self->GetMotorSpeed();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PrismaticJoint_getReferenceAngle(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PrismaticJoint");

    // float GetReferenceAngle()
    float ret = self->GetReferenceAngle();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PrismaticJoint_getUpperLimit(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PrismaticJoint");

    // float GetUpperLimit()
    float ret = self->GetUpperLimit();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PrismaticJoint_isLimitEnabled(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PrismaticJoint");

    // bool IsLimitEnabled()
    bool ret = self->IsLimitEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PrismaticJoint_isMotorEnabled(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PrismaticJoint");

    // bool IsMotorEnabled()
    bool ret = self->IsMotorEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PrismaticJoint_setLimits(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;
    float arg1 = 0;       /** lower */
    float arg2 = 0;       /** upper */

    olua_to_object(L, 1, &self, "b2.PrismaticJoint");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void SetLimits(float lower, float upper)
    self->SetLimits(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2PrismaticJoint_setMaxMotorForce(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;
    float arg1 = 0;       /** force */

    olua_to_object(L, 1, &self, "b2.PrismaticJoint");
    olua_check_number(L, 2, &arg1);

    // void SetMaxMotorForce(float force)
    self->SetMaxMotorForce(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2PrismaticJoint_setMotorSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJoint *self = nullptr;
    float arg1 = 0;       /** speed */

    olua_to_object(L, 1, &self, "b2.PrismaticJoint");
    olua_check_number(L, 2, &arg1);

    // void SetMotorSpeed(float speed)
    self->SetMotorSpeed(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_b2_PrismaticJoint(lua_State *L)
{
    oluacls_class<b2PrismaticJoint, b2Joint>(L, "b2.PrismaticJoint");
    oluacls_func(L, "__gc", _olua_fun_b2PrismaticJoint___gc);
    oluacls_func(L, "enableLimit", _olua_fun_b2PrismaticJoint_enableLimit);
    oluacls_func(L, "enableMotor", _olua_fun_b2PrismaticJoint_enableMotor);
    oluacls_func(L, "getJointSpeed", _olua_fun_b2PrismaticJoint_getJointSpeed);
    oluacls_func(L, "getJointTranslation", _olua_fun_b2PrismaticJoint_getJointTranslation);
    oluacls_func(L, "getLocalAnchorA", _olua_fun_b2PrismaticJoint_getLocalAnchorA);
    oluacls_func(L, "getLocalAnchorB", _olua_fun_b2PrismaticJoint_getLocalAnchorB);
    oluacls_func(L, "getLocalAxisA", _olua_fun_b2PrismaticJoint_getLocalAxisA);
    oluacls_func(L, "getLowerLimit", _olua_fun_b2PrismaticJoint_getLowerLimit);
    oluacls_func(L, "getMaxMotorForce", _olua_fun_b2PrismaticJoint_getMaxMotorForce);
    oluacls_func(L, "getMotorForce", _olua_fun_b2PrismaticJoint_getMotorForce);
    oluacls_func(L, "getMotorSpeed", _olua_fun_b2PrismaticJoint_getMotorSpeed);
    oluacls_func(L, "getReferenceAngle", _olua_fun_b2PrismaticJoint_getReferenceAngle);
    oluacls_func(L, "getUpperLimit", _olua_fun_b2PrismaticJoint_getUpperLimit);
    oluacls_func(L, "isLimitEnabled", _olua_fun_b2PrismaticJoint_isLimitEnabled);
    oluacls_func(L, "isMotorEnabled", _olua_fun_b2PrismaticJoint_isMotorEnabled);
    oluacls_func(L, "setLimits", _olua_fun_b2PrismaticJoint_setLimits);
    oluacls_func(L, "setMaxMotorForce", _olua_fun_b2PrismaticJoint_setMaxMotorForce);
    oluacls_func(L, "setMotorSpeed", _olua_fun_b2PrismaticJoint_setMotorSpeed);
    oluacls_prop(L, "jointSpeed", _olua_fun_b2PrismaticJoint_getJointSpeed, nullptr);
    oluacls_prop(L, "jointTranslation", _olua_fun_b2PrismaticJoint_getJointTranslation, nullptr);
    oluacls_prop(L, "limitEnabled", _olua_fun_b2PrismaticJoint_isLimitEnabled, nullptr);
    oluacls_prop(L, "localAnchorA", _olua_fun_b2PrismaticJoint_getLocalAnchorA, nullptr);
    oluacls_prop(L, "localAnchorB", _olua_fun_b2PrismaticJoint_getLocalAnchorB, nullptr);
    oluacls_prop(L, "localAxisA", _olua_fun_b2PrismaticJoint_getLocalAxisA, nullptr);
    oluacls_prop(L, "lowerLimit", _olua_fun_b2PrismaticJoint_getLowerLimit, nullptr);
    oluacls_prop(L, "maxMotorForce", _olua_fun_b2PrismaticJoint_getMaxMotorForce, _olua_fun_b2PrismaticJoint_setMaxMotorForce);
    oluacls_prop(L, "motorEnabled", _olua_fun_b2PrismaticJoint_isMotorEnabled, nullptr);
    oluacls_prop(L, "motorSpeed", _olua_fun_b2PrismaticJoint_getMotorSpeed, _olua_fun_b2PrismaticJoint_setMotorSpeed);
    oluacls_prop(L, "referenceAngle", _olua_fun_b2PrismaticJoint_getReferenceAngle, nullptr);
    oluacls_prop(L, "upperLimit", _olua_fun_b2PrismaticJoint_getUpperLimit, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_PrismaticJoint(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.PrismaticJoint")) {
        luaL_error(L, "class not found: b2PrismaticJoint");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2PulleyJointDef_groundAnchorA$1(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PulleyJointDef");

    // b2Vec2 groundAnchorA
    b2Vec2 &ret = self->groundAnchorA;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PulleyJointDef_groundAnchorA$2(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;
    b2Vec2 *arg1;       /** groundAnchorA */

    olua_to_object(L, 1, &self, "b2.PulleyJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 groundAnchorA
    self->groundAnchorA = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2PulleyJointDef_groundAnchorA(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 groundAnchorA
        return _olua_fun_b2PulleyJointDef_groundAnchorA$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.PulleyJointDef")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 groundAnchorA
            return _olua_fun_b2PulleyJointDef_groundAnchorA$2(L);
        // }
    }

    luaL_error(L, "method 'b2PulleyJointDef::groundAnchorA' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2PulleyJointDef_groundAnchorB$1(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PulleyJointDef");

    // b2Vec2 groundAnchorB
    b2Vec2 &ret = self->groundAnchorB;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PulleyJointDef_groundAnchorB$2(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;
    b2Vec2 *arg1;       /** groundAnchorB */

    olua_to_object(L, 1, &self, "b2.PulleyJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 groundAnchorB
    self->groundAnchorB = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2PulleyJointDef_groundAnchorB(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 groundAnchorB
        return _olua_fun_b2PulleyJointDef_groundAnchorB$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.PulleyJointDef")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 groundAnchorB
            return _olua_fun_b2PulleyJointDef_groundAnchorB$2(L);
        // }
    }

    luaL_error(L, "method 'b2PulleyJointDef::groundAnchorB' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2PulleyJointDef_initialize(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;
    b2Body *arg1 = nullptr;       /** bodyA */
    b2Body *arg2 = nullptr;       /** bodyB */
    b2Vec2 *arg3;       /** groundAnchorA */
    b2Vec2 *arg4;       /** groundAnchorB */
    b2Vec2 *arg5;       /** anchorA */
    b2Vec2 *arg6;       /** anchorB */
    float arg7 = 0;       /** ratio */

    olua_to_object(L, 1, &self, "b2.PulleyJointDef");
    olua_check_object(L, 2, &arg1, "b2.Body");
    olua_check_object(L, 3, &arg2, "b2.Body");
    olua_check_object(L, 4, &arg3, "b2.Vec2");
    olua_check_object(L, 5, &arg4, "b2.Vec2");
    olua_check_object(L, 6, &arg5, "b2.Vec2");
    olua_check_object(L, 7, &arg6, "b2.Vec2");
    olua_check_number(L, 8, &arg7);

    // void Initialize(b2Body *bodyA, b2Body *bodyB, const b2Vec2 &groundAnchorA, const b2Vec2 &groundAnchorB, const b2Vec2 &anchorA, const b2Vec2 &anchorB, float ratio)
    self->Initialize(arg1, arg2, *arg3, *arg4, *arg5, *arg6, arg7);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2PulleyJointDef_lengthA$1(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PulleyJointDef");

    // float lengthA
    float ret = self->lengthA;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PulleyJointDef_lengthA$2(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;
    float arg1 = 0;       /** lengthA */

    olua_to_object(L, 1, &self, "b2.PulleyJointDef");
    olua_check_number(L, 2, &arg1);

    // float lengthA
    self->lengthA = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2PulleyJointDef_lengthA(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float lengthA
        return _olua_fun_b2PulleyJointDef_lengthA$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.PulleyJointDef")) && (olua_is_number(L, 2))) {
            // float lengthA
            return _olua_fun_b2PulleyJointDef_lengthA$2(L);
        // }
    }

    luaL_error(L, "method 'b2PulleyJointDef::lengthA' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2PulleyJointDef_lengthB$1(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PulleyJointDef");

    // float lengthB
    float ret = self->lengthB;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PulleyJointDef_lengthB$2(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;
    float arg1 = 0;       /** lengthB */

    olua_to_object(L, 1, &self, "b2.PulleyJointDef");
    olua_check_number(L, 2, &arg1);

    // float lengthB
    self->lengthB = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2PulleyJointDef_lengthB(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float lengthB
        return _olua_fun_b2PulleyJointDef_lengthB$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.PulleyJointDef")) && (olua_is_number(L, 2))) {
            // float lengthB
            return _olua_fun_b2PulleyJointDef_lengthB$2(L);
        // }
    }

    luaL_error(L, "method 'b2PulleyJointDef::lengthB' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2PulleyJointDef_localAnchorA$1(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PulleyJointDef");

    // b2Vec2 localAnchorA
    b2Vec2 &ret = self->localAnchorA;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PulleyJointDef_localAnchorA$2(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;
    b2Vec2 *arg1;       /** localAnchorA */

    olua_to_object(L, 1, &self, "b2.PulleyJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAnchorA
    self->localAnchorA = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2PulleyJointDef_localAnchorA(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 localAnchorA
        return _olua_fun_b2PulleyJointDef_localAnchorA$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.PulleyJointDef")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 localAnchorA
            return _olua_fun_b2PulleyJointDef_localAnchorA$2(L);
        // }
    }

    luaL_error(L, "method 'b2PulleyJointDef::localAnchorA' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2PulleyJointDef_localAnchorB$1(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PulleyJointDef");

    // b2Vec2 localAnchorB
    b2Vec2 &ret = self->localAnchorB;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PulleyJointDef_localAnchorB$2(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;
    b2Vec2 *arg1;       /** localAnchorB */

    olua_to_object(L, 1, &self, "b2.PulleyJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAnchorB
    self->localAnchorB = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2PulleyJointDef_localAnchorB(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 localAnchorB
        return _olua_fun_b2PulleyJointDef_localAnchorB$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.PulleyJointDef")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 localAnchorB
            return _olua_fun_b2PulleyJointDef_localAnchorB$2(L);
        // }
    }

    luaL_error(L, "method 'b2PulleyJointDef::localAnchorB' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2PulleyJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2PulleyJointDef()
    b2PulleyJointDef *ret = new b2PulleyJointDef();
    int num_ret = olua_push_object(L, ret, "b2.PulleyJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PulleyJointDef_ratio$1(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PulleyJointDef");

    // float ratio
    float ret = self->ratio;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PulleyJointDef_ratio$2(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;
    float arg1 = 0;       /** ratio */

    olua_to_object(L, 1, &self, "b2.PulleyJointDef");
    olua_check_number(L, 2, &arg1);

    // float ratio
    self->ratio = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2PulleyJointDef_ratio(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float ratio
        return _olua_fun_b2PulleyJointDef_ratio$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.PulleyJointDef")) && (olua_is_number(L, 2))) {
            // float ratio
            return _olua_fun_b2PulleyJointDef_ratio$2(L);
        // }
    }

    luaL_error(L, "method 'b2PulleyJointDef::ratio' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_PulleyJointDef(lua_State *L)
{
    oluacls_class<b2PulleyJointDef, b2JointDef>(L, "b2.PulleyJointDef");
    oluacls_func(L, "initialize", _olua_fun_b2PulleyJointDef_initialize);
    oluacls_func(L, "new", _olua_fun_b2PulleyJointDef_new);
    oluacls_prop(L, "groundAnchorA", _olua_fun_b2PulleyJointDef_groundAnchorA, _olua_fun_b2PulleyJointDef_groundAnchorA);
    oluacls_prop(L, "groundAnchorB", _olua_fun_b2PulleyJointDef_groundAnchorB, _olua_fun_b2PulleyJointDef_groundAnchorB);
    oluacls_prop(L, "localAnchorA", _olua_fun_b2PulleyJointDef_localAnchorA, _olua_fun_b2PulleyJointDef_localAnchorA);
    oluacls_prop(L, "localAnchorB", _olua_fun_b2PulleyJointDef_localAnchorB, _olua_fun_b2PulleyJointDef_localAnchorB);
    oluacls_prop(L, "lengthA", _olua_fun_b2PulleyJointDef_lengthA, _olua_fun_b2PulleyJointDef_lengthA);
    oluacls_prop(L, "lengthB", _olua_fun_b2PulleyJointDef_lengthB, _olua_fun_b2PulleyJointDef_lengthB);
    oluacls_prop(L, "ratio", _olua_fun_b2PulleyJointDef_ratio, _olua_fun_b2PulleyJointDef_ratio);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_PulleyJointDef(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.PulleyJointDef")) {
        luaL_error(L, "class not found: b2PulleyJointDef");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2PulleyJoint___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2PulleyJoint *)olua_toobj(L, 1, "b2.PulleyJoint");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2PulleyJoint_getCurrentLengthA(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PulleyJoint");

    // float GetCurrentLengthA()
    float ret = self->GetCurrentLengthA();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PulleyJoint_getCurrentLengthB(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PulleyJoint");

    // float GetCurrentLengthB()
    float ret = self->GetCurrentLengthB();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PulleyJoint_getGroundAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PulleyJoint");

    // b2Vec2 GetGroundAnchorA()
    b2Vec2 ret = self->GetGroundAnchorA();
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PulleyJoint_getGroundAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PulleyJoint");

    // b2Vec2 GetGroundAnchorB()
    b2Vec2 ret = self->GetGroundAnchorB();
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PulleyJoint_getLengthA(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PulleyJoint");

    // float GetLengthA()
    float ret = self->GetLengthA();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PulleyJoint_getLengthB(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PulleyJoint");

    // float GetLengthB()
    float ret = self->GetLengthB();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2PulleyJoint_getRatio(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PulleyJoint");

    // float GetRatio()
    float ret = self->GetRatio();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_b2_PulleyJoint(lua_State *L)
{
    oluacls_class<b2PulleyJoint, b2Joint>(L, "b2.PulleyJoint");
    oluacls_func(L, "__gc", _olua_fun_b2PulleyJoint___gc);
    oluacls_func(L, "getCurrentLengthA", _olua_fun_b2PulleyJoint_getCurrentLengthA);
    oluacls_func(L, "getCurrentLengthB", _olua_fun_b2PulleyJoint_getCurrentLengthB);
    oluacls_func(L, "getGroundAnchorA", _olua_fun_b2PulleyJoint_getGroundAnchorA);
    oluacls_func(L, "getGroundAnchorB", _olua_fun_b2PulleyJoint_getGroundAnchorB);
    oluacls_func(L, "getLengthA", _olua_fun_b2PulleyJoint_getLengthA);
    oluacls_func(L, "getLengthB", _olua_fun_b2PulleyJoint_getLengthB);
    oluacls_func(L, "getRatio", _olua_fun_b2PulleyJoint_getRatio);
    oluacls_prop(L, "currentLengthA", _olua_fun_b2PulleyJoint_getCurrentLengthA, nullptr);
    oluacls_prop(L, "currentLengthB", _olua_fun_b2PulleyJoint_getCurrentLengthB, nullptr);
    oluacls_prop(L, "groundAnchorA", _olua_fun_b2PulleyJoint_getGroundAnchorA, nullptr);
    oluacls_prop(L, "groundAnchorB", _olua_fun_b2PulleyJoint_getGroundAnchorB, nullptr);
    oluacls_prop(L, "lengthA", _olua_fun_b2PulleyJoint_getLengthA, nullptr);
    oluacls_prop(L, "lengthB", _olua_fun_b2PulleyJoint_getLengthB, nullptr);
    oluacls_prop(L, "ratio", _olua_fun_b2PulleyJoint_getRatio, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_PulleyJoint(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.PulleyJoint")) {
        luaL_error(L, "class not found: b2PulleyJoint");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2RevoluteJointDef_enableLimit$1(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RevoluteJointDef");

    // bool enableLimit
    bool ret = self->enableLimit;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2RevoluteJointDef_enableLimit$2(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;
    bool arg1 = false;       /** enableLimit */

    olua_to_object(L, 1, &self, "b2.RevoluteJointDef");
    olua_check_bool(L, 2, &arg1);

    // bool enableLimit
    self->enableLimit = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2RevoluteJointDef_enableLimit(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool enableLimit
        return _olua_fun_b2RevoluteJointDef_enableLimit$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.RevoluteJointDef")) && (olua_is_bool(L, 2))) {
            // bool enableLimit
            return _olua_fun_b2RevoluteJointDef_enableLimit$2(L);
        // }
    }

    luaL_error(L, "method 'b2RevoluteJointDef::enableLimit' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2RevoluteJointDef_enableMotor$1(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RevoluteJointDef");

    // bool enableMotor
    bool ret = self->enableMotor;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2RevoluteJointDef_enableMotor$2(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;
    bool arg1 = false;       /** enableMotor */

    olua_to_object(L, 1, &self, "b2.RevoluteJointDef");
    olua_check_bool(L, 2, &arg1);

    // bool enableMotor
    self->enableMotor = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2RevoluteJointDef_enableMotor(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool enableMotor
        return _olua_fun_b2RevoluteJointDef_enableMotor$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.RevoluteJointDef")) && (olua_is_bool(L, 2))) {
            // bool enableMotor
            return _olua_fun_b2RevoluteJointDef_enableMotor$2(L);
        // }
    }

    luaL_error(L, "method 'b2RevoluteJointDef::enableMotor' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2RevoluteJointDef_initialize(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;
    b2Body *arg1 = nullptr;       /** bodyA */
    b2Body *arg2 = nullptr;       /** bodyB */
    b2Vec2 *arg3;       /** anchor */

    olua_to_object(L, 1, &self, "b2.RevoluteJointDef");
    olua_check_object(L, 2, &arg1, "b2.Body");
    olua_check_object(L, 3, &arg2, "b2.Body");
    olua_check_object(L, 4, &arg3, "b2.Vec2");

    // void Initialize(b2Body *bodyA, b2Body *bodyB, const b2Vec2 &anchor)
    self->Initialize(arg1, arg2, *arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2RevoluteJointDef_localAnchorA$1(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RevoluteJointDef");

    // b2Vec2 localAnchorA
    b2Vec2 &ret = self->localAnchorA;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2RevoluteJointDef_localAnchorA$2(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;
    b2Vec2 *arg1;       /** localAnchorA */

    olua_to_object(L, 1, &self, "b2.RevoluteJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAnchorA
    self->localAnchorA = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2RevoluteJointDef_localAnchorA(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 localAnchorA
        return _olua_fun_b2RevoluteJointDef_localAnchorA$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.RevoluteJointDef")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 localAnchorA
            return _olua_fun_b2RevoluteJointDef_localAnchorA$2(L);
        // }
    }

    luaL_error(L, "method 'b2RevoluteJointDef::localAnchorA' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2RevoluteJointDef_localAnchorB$1(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RevoluteJointDef");

    // b2Vec2 localAnchorB
    b2Vec2 &ret = self->localAnchorB;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2RevoluteJointDef_localAnchorB$2(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;
    b2Vec2 *arg1;       /** localAnchorB */

    olua_to_object(L, 1, &self, "b2.RevoluteJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAnchorB
    self->localAnchorB = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2RevoluteJointDef_localAnchorB(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 localAnchorB
        return _olua_fun_b2RevoluteJointDef_localAnchorB$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.RevoluteJointDef")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 localAnchorB
            return _olua_fun_b2RevoluteJointDef_localAnchorB$2(L);
        // }
    }

    luaL_error(L, "method 'b2RevoluteJointDef::localAnchorB' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2RevoluteJointDef_lowerAngle$1(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RevoluteJointDef");

    // float lowerAngle
    float ret = self->lowerAngle;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2RevoluteJointDef_lowerAngle$2(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;
    float arg1 = 0;       /** lowerAngle */

    olua_to_object(L, 1, &self, "b2.RevoluteJointDef");
    olua_check_number(L, 2, &arg1);

    // float lowerAngle
    self->lowerAngle = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2RevoluteJointDef_lowerAngle(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float lowerAngle
        return _olua_fun_b2RevoluteJointDef_lowerAngle$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.RevoluteJointDef")) && (olua_is_number(L, 2))) {
            // float lowerAngle
            return _olua_fun_b2RevoluteJointDef_lowerAngle$2(L);
        // }
    }

    luaL_error(L, "method 'b2RevoluteJointDef::lowerAngle' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2RevoluteJointDef_maxMotorTorque$1(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RevoluteJointDef");

    // float maxMotorTorque
    float ret = self->maxMotorTorque;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2RevoluteJointDef_maxMotorTorque$2(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;
    float arg1 = 0;       /** maxMotorTorque */

    olua_to_object(L, 1, &self, "b2.RevoluteJointDef");
    olua_check_number(L, 2, &arg1);

    // float maxMotorTorque
    self->maxMotorTorque = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2RevoluteJointDef_maxMotorTorque(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float maxMotorTorque
        return _olua_fun_b2RevoluteJointDef_maxMotorTorque$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.RevoluteJointDef")) && (olua_is_number(L, 2))) {
            // float maxMotorTorque
            return _olua_fun_b2RevoluteJointDef_maxMotorTorque$2(L);
        // }
    }

    luaL_error(L, "method 'b2RevoluteJointDef::maxMotorTorque' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2RevoluteJointDef_motorSpeed$1(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RevoluteJointDef");

    // float motorSpeed
    float ret = self->motorSpeed;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2RevoluteJointDef_motorSpeed$2(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;
    float arg1 = 0;       /** motorSpeed */

    olua_to_object(L, 1, &self, "b2.RevoluteJointDef");
    olua_check_number(L, 2, &arg1);

    // float motorSpeed
    self->motorSpeed = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2RevoluteJointDef_motorSpeed(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float motorSpeed
        return _olua_fun_b2RevoluteJointDef_motorSpeed$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.RevoluteJointDef")) && (olua_is_number(L, 2))) {
            // float motorSpeed
            return _olua_fun_b2RevoluteJointDef_motorSpeed$2(L);
        // }
    }

    luaL_error(L, "method 'b2RevoluteJointDef::motorSpeed' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2RevoluteJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2RevoluteJointDef()
    b2RevoluteJointDef *ret = new b2RevoluteJointDef();
    int num_ret = olua_push_object(L, ret, "b2.RevoluteJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2RevoluteJointDef_referenceAngle$1(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RevoluteJointDef");

    // float referenceAngle
    float ret = self->referenceAngle;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2RevoluteJointDef_referenceAngle$2(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;
    float arg1 = 0;       /** referenceAngle */

    olua_to_object(L, 1, &self, "b2.RevoluteJointDef");
    olua_check_number(L, 2, &arg1);

    // float referenceAngle
    self->referenceAngle = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2RevoluteJointDef_referenceAngle(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float referenceAngle
        return _olua_fun_b2RevoluteJointDef_referenceAngle$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.RevoluteJointDef")) && (olua_is_number(L, 2))) {
            // float referenceAngle
            return _olua_fun_b2RevoluteJointDef_referenceAngle$2(L);
        // }
    }

    luaL_error(L, "method 'b2RevoluteJointDef::referenceAngle' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2RevoluteJointDef_upperAngle$1(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RevoluteJointDef");

    // float upperAngle
    float ret = self->upperAngle;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2RevoluteJointDef_upperAngle$2(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;
    float arg1 = 0;       /** upperAngle */

    olua_to_object(L, 1, &self, "b2.RevoluteJointDef");
    olua_check_number(L, 2, &arg1);

    // float upperAngle
    self->upperAngle = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2RevoluteJointDef_upperAngle(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float upperAngle
        return _olua_fun_b2RevoluteJointDef_upperAngle$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.RevoluteJointDef")) && (olua_is_number(L, 2))) {
            // float upperAngle
            return _olua_fun_b2RevoluteJointDef_upperAngle$2(L);
        // }
    }

    luaL_error(L, "method 'b2RevoluteJointDef::upperAngle' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_RevoluteJointDef(lua_State *L)
{
    oluacls_class<b2RevoluteJointDef, b2JointDef>(L, "b2.RevoluteJointDef");
    oluacls_func(L, "initialize", _olua_fun_b2RevoluteJointDef_initialize);
    oluacls_func(L, "new", _olua_fun_b2RevoluteJointDef_new);
    oluacls_prop(L, "localAnchorA", _olua_fun_b2RevoluteJointDef_localAnchorA, _olua_fun_b2RevoluteJointDef_localAnchorA);
    oluacls_prop(L, "localAnchorB", _olua_fun_b2RevoluteJointDef_localAnchorB, _olua_fun_b2RevoluteJointDef_localAnchorB);
    oluacls_prop(L, "referenceAngle", _olua_fun_b2RevoluteJointDef_referenceAngle, _olua_fun_b2RevoluteJointDef_referenceAngle);
    oluacls_prop(L, "enableLimit", _olua_fun_b2RevoluteJointDef_enableLimit, _olua_fun_b2RevoluteJointDef_enableLimit);
    oluacls_prop(L, "lowerAngle", _olua_fun_b2RevoluteJointDef_lowerAngle, _olua_fun_b2RevoluteJointDef_lowerAngle);
    oluacls_prop(L, "upperAngle", _olua_fun_b2RevoluteJointDef_upperAngle, _olua_fun_b2RevoluteJointDef_upperAngle);
    oluacls_prop(L, "enableMotor", _olua_fun_b2RevoluteJointDef_enableMotor, _olua_fun_b2RevoluteJointDef_enableMotor);
    oluacls_prop(L, "motorSpeed", _olua_fun_b2RevoluteJointDef_motorSpeed, _olua_fun_b2RevoluteJointDef_motorSpeed);
    oluacls_prop(L, "maxMotorTorque", _olua_fun_b2RevoluteJointDef_maxMotorTorque, _olua_fun_b2RevoluteJointDef_maxMotorTorque);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_RevoluteJointDef(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.RevoluteJointDef")) {
        luaL_error(L, "class not found: b2RevoluteJointDef");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2RevoluteJoint___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2RevoluteJoint *)olua_toobj(L, 1, "b2.RevoluteJoint");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2RevoluteJoint_enableLimit(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_object(L, 1, &self, "b2.RevoluteJoint");
    olua_check_bool(L, 2, &arg1);

    // void EnableLimit(bool flag)
    self->EnableLimit(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2RevoluteJoint_enableMotor(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_object(L, 1, &self, "b2.RevoluteJoint");
    olua_check_bool(L, 2, &arg1);

    // void EnableMotor(bool flag)
    self->EnableMotor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2RevoluteJoint_getJointAngle(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RevoluteJoint");

    // float GetJointAngle()
    float ret = self->GetJointAngle();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2RevoluteJoint_getJointSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RevoluteJoint");

    // float GetJointSpeed()
    float ret = self->GetJointSpeed();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2RevoluteJoint_getLocalAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RevoluteJoint");

    // const b2Vec2 &GetLocalAnchorA()
    const b2Vec2 &ret = self->GetLocalAnchorA();
    int num_ret = olua_push_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2RevoluteJoint_getLocalAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RevoluteJoint");

    // const b2Vec2 &GetLocalAnchorB()
    const b2Vec2 &ret = self->GetLocalAnchorB();
    int num_ret = olua_push_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2RevoluteJoint_getLowerLimit(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RevoluteJoint");

    // float GetLowerLimit()
    float ret = self->GetLowerLimit();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2RevoluteJoint_getMaxMotorTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RevoluteJoint");

    // float GetMaxMotorTorque()
    float ret = self->GetMaxMotorTorque();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2RevoluteJoint_getMotorSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RevoluteJoint");

    // float GetMotorSpeed()
    float ret = self->GetMotorSpeed();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2RevoluteJoint_getMotorTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;
    float arg1 = 0;       /** inv_dt */

    olua_to_object(L, 1, &self, "b2.RevoluteJoint");
    olua_check_number(L, 2, &arg1);

    // float GetMotorTorque(float inv_dt)
    float ret = self->GetMotorTorque(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2RevoluteJoint_getReferenceAngle(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RevoluteJoint");

    // float GetReferenceAngle()
    float ret = self->GetReferenceAngle();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2RevoluteJoint_getUpperLimit(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RevoluteJoint");

    // float GetUpperLimit()
    float ret = self->GetUpperLimit();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2RevoluteJoint_isLimitEnabled(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RevoluteJoint");

    // bool IsLimitEnabled()
    bool ret = self->IsLimitEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2RevoluteJoint_isMotorEnabled(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RevoluteJoint");

    // bool IsMotorEnabled()
    bool ret = self->IsMotorEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2RevoluteJoint_setLimits(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;
    float arg1 = 0;       /** lower */
    float arg2 = 0;       /** upper */

    olua_to_object(L, 1, &self, "b2.RevoluteJoint");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void SetLimits(float lower, float upper)
    self->SetLimits(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2RevoluteJoint_setMaxMotorTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;
    float arg1 = 0;       /** torque */

    olua_to_object(L, 1, &self, "b2.RevoluteJoint");
    olua_check_number(L, 2, &arg1);

    // void SetMaxMotorTorque(float torque)
    self->SetMaxMotorTorque(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2RevoluteJoint_setMotorSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJoint *self = nullptr;
    float arg1 = 0;       /** speed */

    olua_to_object(L, 1, &self, "b2.RevoluteJoint");
    olua_check_number(L, 2, &arg1);

    // void SetMotorSpeed(float speed)
    self->SetMotorSpeed(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_b2_RevoluteJoint(lua_State *L)
{
    oluacls_class<b2RevoluteJoint, b2Joint>(L, "b2.RevoluteJoint");
    oluacls_func(L, "__gc", _olua_fun_b2RevoluteJoint___gc);
    oluacls_func(L, "enableLimit", _olua_fun_b2RevoluteJoint_enableLimit);
    oluacls_func(L, "enableMotor", _olua_fun_b2RevoluteJoint_enableMotor);
    oluacls_func(L, "getJointAngle", _olua_fun_b2RevoluteJoint_getJointAngle);
    oluacls_func(L, "getJointSpeed", _olua_fun_b2RevoluteJoint_getJointSpeed);
    oluacls_func(L, "getLocalAnchorA", _olua_fun_b2RevoluteJoint_getLocalAnchorA);
    oluacls_func(L, "getLocalAnchorB", _olua_fun_b2RevoluteJoint_getLocalAnchorB);
    oluacls_func(L, "getLowerLimit", _olua_fun_b2RevoluteJoint_getLowerLimit);
    oluacls_func(L, "getMaxMotorTorque", _olua_fun_b2RevoluteJoint_getMaxMotorTorque);
    oluacls_func(L, "getMotorSpeed", _olua_fun_b2RevoluteJoint_getMotorSpeed);
    oluacls_func(L, "getMotorTorque", _olua_fun_b2RevoluteJoint_getMotorTorque);
    oluacls_func(L, "getReferenceAngle", _olua_fun_b2RevoluteJoint_getReferenceAngle);
    oluacls_func(L, "getUpperLimit", _olua_fun_b2RevoluteJoint_getUpperLimit);
    oluacls_func(L, "isLimitEnabled", _olua_fun_b2RevoluteJoint_isLimitEnabled);
    oluacls_func(L, "isMotorEnabled", _olua_fun_b2RevoluteJoint_isMotorEnabled);
    oluacls_func(L, "setLimits", _olua_fun_b2RevoluteJoint_setLimits);
    oluacls_func(L, "setMaxMotorTorque", _olua_fun_b2RevoluteJoint_setMaxMotorTorque);
    oluacls_func(L, "setMotorSpeed", _olua_fun_b2RevoluteJoint_setMotorSpeed);
    oluacls_prop(L, "jointAngle", _olua_fun_b2RevoluteJoint_getJointAngle, nullptr);
    oluacls_prop(L, "jointSpeed", _olua_fun_b2RevoluteJoint_getJointSpeed, nullptr);
    oluacls_prop(L, "limitEnabled", _olua_fun_b2RevoluteJoint_isLimitEnabled, nullptr);
    oluacls_prop(L, "localAnchorA", _olua_fun_b2RevoluteJoint_getLocalAnchorA, nullptr);
    oluacls_prop(L, "localAnchorB", _olua_fun_b2RevoluteJoint_getLocalAnchorB, nullptr);
    oluacls_prop(L, "lowerLimit", _olua_fun_b2RevoluteJoint_getLowerLimit, nullptr);
    oluacls_prop(L, "maxMotorTorque", _olua_fun_b2RevoluteJoint_getMaxMotorTorque, _olua_fun_b2RevoluteJoint_setMaxMotorTorque);
    oluacls_prop(L, "motorEnabled", _olua_fun_b2RevoluteJoint_isMotorEnabled, nullptr);
    oluacls_prop(L, "motorSpeed", _olua_fun_b2RevoluteJoint_getMotorSpeed, _olua_fun_b2RevoluteJoint_setMotorSpeed);
    oluacls_prop(L, "referenceAngle", _olua_fun_b2RevoluteJoint_getReferenceAngle, nullptr);
    oluacls_prop(L, "upperLimit", _olua_fun_b2RevoluteJoint_getUpperLimit, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_RevoluteJoint(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.RevoluteJoint")) {
        luaL_error(L, "class not found: b2RevoluteJoint");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2WeldJointDef_damping$1(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WeldJointDef");

    // float damping
    float ret = self->damping;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WeldJointDef_damping$2(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJointDef *self = nullptr;
    float arg1 = 0;       /** damping */

    olua_to_object(L, 1, &self, "b2.WeldJointDef");
    olua_check_number(L, 2, &arg1);

    // float damping
    self->damping = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WeldJointDef_damping(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float damping
        return _olua_fun_b2WeldJointDef_damping$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.WeldJointDef")) && (olua_is_number(L, 2))) {
            // float damping
            return _olua_fun_b2WeldJointDef_damping$2(L);
        // }
    }

    luaL_error(L, "method 'b2WeldJointDef::damping' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2WeldJointDef_initialize(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJointDef *self = nullptr;
    b2Body *arg1 = nullptr;       /** bodyA */
    b2Body *arg2 = nullptr;       /** bodyB */
    b2Vec2 *arg3;       /** anchor */

    olua_to_object(L, 1, &self, "b2.WeldJointDef");
    olua_check_object(L, 2, &arg1, "b2.Body");
    olua_check_object(L, 3, &arg2, "b2.Body");
    olua_check_object(L, 4, &arg3, "b2.Vec2");

    // void Initialize(b2Body *bodyA, b2Body *bodyB, const b2Vec2 &anchor)
    self->Initialize(arg1, arg2, *arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WeldJointDef_localAnchorA$1(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WeldJointDef");

    // b2Vec2 localAnchorA
    b2Vec2 &ret = self->localAnchorA;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WeldJointDef_localAnchorA$2(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJointDef *self = nullptr;
    b2Vec2 *arg1;       /** localAnchorA */

    olua_to_object(L, 1, &self, "b2.WeldJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAnchorA
    self->localAnchorA = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WeldJointDef_localAnchorA(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 localAnchorA
        return _olua_fun_b2WeldJointDef_localAnchorA$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.WeldJointDef")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 localAnchorA
            return _olua_fun_b2WeldJointDef_localAnchorA$2(L);
        // }
    }

    luaL_error(L, "method 'b2WeldJointDef::localAnchorA' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2WeldJointDef_localAnchorB$1(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WeldJointDef");

    // b2Vec2 localAnchorB
    b2Vec2 &ret = self->localAnchorB;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WeldJointDef_localAnchorB$2(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJointDef *self = nullptr;
    b2Vec2 *arg1;       /** localAnchorB */

    olua_to_object(L, 1, &self, "b2.WeldJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAnchorB
    self->localAnchorB = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WeldJointDef_localAnchorB(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 localAnchorB
        return _olua_fun_b2WeldJointDef_localAnchorB$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.WeldJointDef")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 localAnchorB
            return _olua_fun_b2WeldJointDef_localAnchorB$2(L);
        // }
    }

    luaL_error(L, "method 'b2WeldJointDef::localAnchorB' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2WeldJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2WeldJointDef()
    b2WeldJointDef *ret = new b2WeldJointDef();
    int num_ret = olua_push_object(L, ret, "b2.WeldJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WeldJointDef_referenceAngle$1(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WeldJointDef");

    // float referenceAngle
    float ret = self->referenceAngle;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WeldJointDef_referenceAngle$2(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJointDef *self = nullptr;
    float arg1 = 0;       /** referenceAngle */

    olua_to_object(L, 1, &self, "b2.WeldJointDef");
    olua_check_number(L, 2, &arg1);

    // float referenceAngle
    self->referenceAngle = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WeldJointDef_referenceAngle(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float referenceAngle
        return _olua_fun_b2WeldJointDef_referenceAngle$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.WeldJointDef")) && (olua_is_number(L, 2))) {
            // float referenceAngle
            return _olua_fun_b2WeldJointDef_referenceAngle$2(L);
        // }
    }

    luaL_error(L, "method 'b2WeldJointDef::referenceAngle' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2WeldJointDef_stiffness$1(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WeldJointDef");

    // float stiffness
    float ret = self->stiffness;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WeldJointDef_stiffness$2(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJointDef *self = nullptr;
    float arg1 = 0;       /** stiffness */

    olua_to_object(L, 1, &self, "b2.WeldJointDef");
    olua_check_number(L, 2, &arg1);

    // float stiffness
    self->stiffness = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WeldJointDef_stiffness(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float stiffness
        return _olua_fun_b2WeldJointDef_stiffness$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.WeldJointDef")) && (olua_is_number(L, 2))) {
            // float stiffness
            return _olua_fun_b2WeldJointDef_stiffness$2(L);
        // }
    }

    luaL_error(L, "method 'b2WeldJointDef::stiffness' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_WeldJointDef(lua_State *L)
{
    oluacls_class<b2WeldJointDef, b2JointDef>(L, "b2.WeldJointDef");
    oluacls_func(L, "initialize", _olua_fun_b2WeldJointDef_initialize);
    oluacls_func(L, "new", _olua_fun_b2WeldJointDef_new);
    oluacls_prop(L, "localAnchorA", _olua_fun_b2WeldJointDef_localAnchorA, _olua_fun_b2WeldJointDef_localAnchorA);
    oluacls_prop(L, "localAnchorB", _olua_fun_b2WeldJointDef_localAnchorB, _olua_fun_b2WeldJointDef_localAnchorB);
    oluacls_prop(L, "referenceAngle", _olua_fun_b2WeldJointDef_referenceAngle, _olua_fun_b2WeldJointDef_referenceAngle);
    oluacls_prop(L, "stiffness", _olua_fun_b2WeldJointDef_stiffness, _olua_fun_b2WeldJointDef_stiffness);
    oluacls_prop(L, "damping", _olua_fun_b2WeldJointDef_damping, _olua_fun_b2WeldJointDef_damping);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_WeldJointDef(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.WeldJointDef")) {
        luaL_error(L, "class not found: b2WeldJointDef");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2WeldJoint___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2WeldJoint *)olua_toobj(L, 1, "b2.WeldJoint");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WeldJoint_getDamping(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WeldJoint");

    // float GetDamping()
    float ret = self->GetDamping();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WeldJoint_getLocalAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WeldJoint");

    // const b2Vec2 &GetLocalAnchorA()
    const b2Vec2 &ret = self->GetLocalAnchorA();
    int num_ret = olua_push_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WeldJoint_getLocalAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WeldJoint");

    // const b2Vec2 &GetLocalAnchorB()
    const b2Vec2 &ret = self->GetLocalAnchorB();
    int num_ret = olua_push_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WeldJoint_getReferenceAngle(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WeldJoint");

    // float GetReferenceAngle()
    float ret = self->GetReferenceAngle();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WeldJoint_getStiffness(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WeldJoint");

    // float GetStiffness()
    float ret = self->GetStiffness();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WeldJoint_setDamping(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJoint *self = nullptr;
    float arg1 = 0;       /** damping */

    olua_to_object(L, 1, &self, "b2.WeldJoint");
    olua_check_number(L, 2, &arg1);

    // void SetDamping(float damping)
    self->SetDamping(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WeldJoint_setStiffness(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJoint *self = nullptr;
    float arg1 = 0;       /** stiffness */

    olua_to_object(L, 1, &self, "b2.WeldJoint");
    olua_check_number(L, 2, &arg1);

    // void SetStiffness(float stiffness)
    self->SetStiffness(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_b2_WeldJoint(lua_State *L)
{
    oluacls_class<b2WeldJoint, b2Joint>(L, "b2.WeldJoint");
    oluacls_func(L, "__gc", _olua_fun_b2WeldJoint___gc);
    oluacls_func(L, "getDamping", _olua_fun_b2WeldJoint_getDamping);
    oluacls_func(L, "getLocalAnchorA", _olua_fun_b2WeldJoint_getLocalAnchorA);
    oluacls_func(L, "getLocalAnchorB", _olua_fun_b2WeldJoint_getLocalAnchorB);
    oluacls_func(L, "getReferenceAngle", _olua_fun_b2WeldJoint_getReferenceAngle);
    oluacls_func(L, "getStiffness", _olua_fun_b2WeldJoint_getStiffness);
    oluacls_func(L, "setDamping", _olua_fun_b2WeldJoint_setDamping);
    oluacls_func(L, "setStiffness", _olua_fun_b2WeldJoint_setStiffness);
    oluacls_prop(L, "damping", _olua_fun_b2WeldJoint_getDamping, _olua_fun_b2WeldJoint_setDamping);
    oluacls_prop(L, "localAnchorA", _olua_fun_b2WeldJoint_getLocalAnchorA, nullptr);
    oluacls_prop(L, "localAnchorB", _olua_fun_b2WeldJoint_getLocalAnchorB, nullptr);
    oluacls_prop(L, "referenceAngle", _olua_fun_b2WeldJoint_getReferenceAngle, nullptr);
    oluacls_prop(L, "stiffness", _olua_fun_b2WeldJoint_getStiffness, _olua_fun_b2WeldJoint_setStiffness);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_WeldJoint(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.WeldJoint")) {
        luaL_error(L, "class not found: b2WeldJoint");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2WheelJointDef_damping$1(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WheelJointDef");

    // float damping
    float ret = self->damping;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WheelJointDef_damping$2(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;
    float arg1 = 0;       /** damping */

    olua_to_object(L, 1, &self, "b2.WheelJointDef");
    olua_check_number(L, 2, &arg1);

    // float damping
    self->damping = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WheelJointDef_damping(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float damping
        return _olua_fun_b2WheelJointDef_damping$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.WheelJointDef")) && (olua_is_number(L, 2))) {
            // float damping
            return _olua_fun_b2WheelJointDef_damping$2(L);
        // }
    }

    luaL_error(L, "method 'b2WheelJointDef::damping' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2WheelJointDef_enableLimit$1(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WheelJointDef");

    // bool enableLimit
    bool ret = self->enableLimit;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WheelJointDef_enableLimit$2(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;
    bool arg1 = false;       /** enableLimit */

    olua_to_object(L, 1, &self, "b2.WheelJointDef");
    olua_check_bool(L, 2, &arg1);

    // bool enableLimit
    self->enableLimit = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WheelJointDef_enableLimit(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool enableLimit
        return _olua_fun_b2WheelJointDef_enableLimit$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.WheelJointDef")) && (olua_is_bool(L, 2))) {
            // bool enableLimit
            return _olua_fun_b2WheelJointDef_enableLimit$2(L);
        // }
    }

    luaL_error(L, "method 'b2WheelJointDef::enableLimit' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2WheelJointDef_enableMotor$1(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WheelJointDef");

    // bool enableMotor
    bool ret = self->enableMotor;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WheelJointDef_enableMotor$2(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;
    bool arg1 = false;       /** enableMotor */

    olua_to_object(L, 1, &self, "b2.WheelJointDef");
    olua_check_bool(L, 2, &arg1);

    // bool enableMotor
    self->enableMotor = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WheelJointDef_enableMotor(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool enableMotor
        return _olua_fun_b2WheelJointDef_enableMotor$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.WheelJointDef")) && (olua_is_bool(L, 2))) {
            // bool enableMotor
            return _olua_fun_b2WheelJointDef_enableMotor$2(L);
        // }
    }

    luaL_error(L, "method 'b2WheelJointDef::enableMotor' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2WheelJointDef_initialize(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;
    b2Body *arg1 = nullptr;       /** bodyA */
    b2Body *arg2 = nullptr;       /** bodyB */
    b2Vec2 *arg3;       /** anchor */
    b2Vec2 *arg4;       /** axis */

    olua_to_object(L, 1, &self, "b2.WheelJointDef");
    olua_check_object(L, 2, &arg1, "b2.Body");
    olua_check_object(L, 3, &arg2, "b2.Body");
    olua_check_object(L, 4, &arg3, "b2.Vec2");
    olua_check_object(L, 5, &arg4, "b2.Vec2");

    // void Initialize(b2Body *bodyA, b2Body *bodyB, const b2Vec2 &anchor, const b2Vec2 &axis)
    self->Initialize(arg1, arg2, *arg3, *arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WheelJointDef_localAnchorA$1(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WheelJointDef");

    // b2Vec2 localAnchorA
    b2Vec2 &ret = self->localAnchorA;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WheelJointDef_localAnchorA$2(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;
    b2Vec2 *arg1;       /** localAnchorA */

    olua_to_object(L, 1, &self, "b2.WheelJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAnchorA
    self->localAnchorA = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WheelJointDef_localAnchorA(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 localAnchorA
        return _olua_fun_b2WheelJointDef_localAnchorA$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.WheelJointDef")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 localAnchorA
            return _olua_fun_b2WheelJointDef_localAnchorA$2(L);
        // }
    }

    luaL_error(L, "method 'b2WheelJointDef::localAnchorA' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2WheelJointDef_localAnchorB$1(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WheelJointDef");

    // b2Vec2 localAnchorB
    b2Vec2 &ret = self->localAnchorB;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WheelJointDef_localAnchorB$2(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;
    b2Vec2 *arg1;       /** localAnchorB */

    olua_to_object(L, 1, &self, "b2.WheelJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAnchorB
    self->localAnchorB = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WheelJointDef_localAnchorB(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 localAnchorB
        return _olua_fun_b2WheelJointDef_localAnchorB$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.WheelJointDef")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 localAnchorB
            return _olua_fun_b2WheelJointDef_localAnchorB$2(L);
        // }
    }

    luaL_error(L, "method 'b2WheelJointDef::localAnchorB' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2WheelJointDef_localAxisA$1(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WheelJointDef");

    // b2Vec2 localAxisA
    b2Vec2 &ret = self->localAxisA;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WheelJointDef_localAxisA$2(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;
    b2Vec2 *arg1;       /** localAxisA */

    olua_to_object(L, 1, &self, "b2.WheelJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAxisA
    self->localAxisA = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WheelJointDef_localAxisA(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 localAxisA
        return _olua_fun_b2WheelJointDef_localAxisA$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.WheelJointDef")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 localAxisA
            return _olua_fun_b2WheelJointDef_localAxisA$2(L);
        // }
    }

    luaL_error(L, "method 'b2WheelJointDef::localAxisA' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2WheelJointDef_lowerTranslation$1(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WheelJointDef");

    // float lowerTranslation
    float ret = self->lowerTranslation;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WheelJointDef_lowerTranslation$2(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;
    float arg1 = 0;       /** lowerTranslation */

    olua_to_object(L, 1, &self, "b2.WheelJointDef");
    olua_check_number(L, 2, &arg1);

    // float lowerTranslation
    self->lowerTranslation = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WheelJointDef_lowerTranslation(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float lowerTranslation
        return _olua_fun_b2WheelJointDef_lowerTranslation$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.WheelJointDef")) && (olua_is_number(L, 2))) {
            // float lowerTranslation
            return _olua_fun_b2WheelJointDef_lowerTranslation$2(L);
        // }
    }

    luaL_error(L, "method 'b2WheelJointDef::lowerTranslation' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2WheelJointDef_maxMotorTorque$1(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WheelJointDef");

    // float maxMotorTorque
    float ret = self->maxMotorTorque;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WheelJointDef_maxMotorTorque$2(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;
    float arg1 = 0;       /** maxMotorTorque */

    olua_to_object(L, 1, &self, "b2.WheelJointDef");
    olua_check_number(L, 2, &arg1);

    // float maxMotorTorque
    self->maxMotorTorque = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WheelJointDef_maxMotorTorque(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float maxMotorTorque
        return _olua_fun_b2WheelJointDef_maxMotorTorque$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.WheelJointDef")) && (olua_is_number(L, 2))) {
            // float maxMotorTorque
            return _olua_fun_b2WheelJointDef_maxMotorTorque$2(L);
        // }
    }

    luaL_error(L, "method 'b2WheelJointDef::maxMotorTorque' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2WheelJointDef_motorSpeed$1(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WheelJointDef");

    // float motorSpeed
    float ret = self->motorSpeed;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WheelJointDef_motorSpeed$2(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;
    float arg1 = 0;       /** motorSpeed */

    olua_to_object(L, 1, &self, "b2.WheelJointDef");
    olua_check_number(L, 2, &arg1);

    // float motorSpeed
    self->motorSpeed = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WheelJointDef_motorSpeed(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float motorSpeed
        return _olua_fun_b2WheelJointDef_motorSpeed$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.WheelJointDef")) && (olua_is_number(L, 2))) {
            // float motorSpeed
            return _olua_fun_b2WheelJointDef_motorSpeed$2(L);
        // }
    }

    luaL_error(L, "method 'b2WheelJointDef::motorSpeed' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2WheelJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2WheelJointDef()
    b2WheelJointDef *ret = new b2WheelJointDef();
    int num_ret = olua_push_object(L, ret, "b2.WheelJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WheelJointDef_stiffness$1(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WheelJointDef");

    // float stiffness
    float ret = self->stiffness;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WheelJointDef_stiffness$2(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;
    float arg1 = 0;       /** stiffness */

    olua_to_object(L, 1, &self, "b2.WheelJointDef");
    olua_check_number(L, 2, &arg1);

    // float stiffness
    self->stiffness = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WheelJointDef_stiffness(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float stiffness
        return _olua_fun_b2WheelJointDef_stiffness$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.WheelJointDef")) && (olua_is_number(L, 2))) {
            // float stiffness
            return _olua_fun_b2WheelJointDef_stiffness$2(L);
        // }
    }

    luaL_error(L, "method 'b2WheelJointDef::stiffness' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2WheelJointDef_upperTranslation$1(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WheelJointDef");

    // float upperTranslation
    float ret = self->upperTranslation;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WheelJointDef_upperTranslation$2(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;
    float arg1 = 0;       /** upperTranslation */

    olua_to_object(L, 1, &self, "b2.WheelJointDef");
    olua_check_number(L, 2, &arg1);

    // float upperTranslation
    self->upperTranslation = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WheelJointDef_upperTranslation(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float upperTranslation
        return _olua_fun_b2WheelJointDef_upperTranslation$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.WheelJointDef")) && (olua_is_number(L, 2))) {
            // float upperTranslation
            return _olua_fun_b2WheelJointDef_upperTranslation$2(L);
        // }
    }

    luaL_error(L, "method 'b2WheelJointDef::upperTranslation' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_WheelJointDef(lua_State *L)
{
    oluacls_class<b2WheelJointDef, b2JointDef>(L, "b2.WheelJointDef");
    oluacls_func(L, "initialize", _olua_fun_b2WheelJointDef_initialize);
    oluacls_func(L, "new", _olua_fun_b2WheelJointDef_new);
    oluacls_prop(L, "localAnchorA", _olua_fun_b2WheelJointDef_localAnchorA, _olua_fun_b2WheelJointDef_localAnchorA);
    oluacls_prop(L, "localAnchorB", _olua_fun_b2WheelJointDef_localAnchorB, _olua_fun_b2WheelJointDef_localAnchorB);
    oluacls_prop(L, "localAxisA", _olua_fun_b2WheelJointDef_localAxisA, _olua_fun_b2WheelJointDef_localAxisA);
    oluacls_prop(L, "enableLimit", _olua_fun_b2WheelJointDef_enableLimit, _olua_fun_b2WheelJointDef_enableLimit);
    oluacls_prop(L, "lowerTranslation", _olua_fun_b2WheelJointDef_lowerTranslation, _olua_fun_b2WheelJointDef_lowerTranslation);
    oluacls_prop(L, "upperTranslation", _olua_fun_b2WheelJointDef_upperTranslation, _olua_fun_b2WheelJointDef_upperTranslation);
    oluacls_prop(L, "enableMotor", _olua_fun_b2WheelJointDef_enableMotor, _olua_fun_b2WheelJointDef_enableMotor);
    oluacls_prop(L, "maxMotorTorque", _olua_fun_b2WheelJointDef_maxMotorTorque, _olua_fun_b2WheelJointDef_maxMotorTorque);
    oluacls_prop(L, "motorSpeed", _olua_fun_b2WheelJointDef_motorSpeed, _olua_fun_b2WheelJointDef_motorSpeed);
    oluacls_prop(L, "stiffness", _olua_fun_b2WheelJointDef_stiffness, _olua_fun_b2WheelJointDef_stiffness);
    oluacls_prop(L, "damping", _olua_fun_b2WheelJointDef_damping, _olua_fun_b2WheelJointDef_damping);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_WheelJointDef(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.WheelJointDef")) {
        luaL_error(L, "class not found: b2WheelJointDef");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2WheelJoint___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2WheelJoint *)olua_toobj(L, 1, "b2.WheelJoint");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WheelJoint_enableLimit(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_object(L, 1, &self, "b2.WheelJoint");
    olua_check_bool(L, 2, &arg1);

    // void EnableLimit(bool flag)
    self->EnableLimit(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WheelJoint_enableMotor(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_object(L, 1, &self, "b2.WheelJoint");
    olua_check_bool(L, 2, &arg1);

    // void EnableMotor(bool flag)
    self->EnableMotor(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WheelJoint_getDamping(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WheelJoint");

    // float GetDamping()
    float ret = self->GetDamping();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WheelJoint_getJointAngle(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WheelJoint");

    // float GetJointAngle()
    float ret = self->GetJointAngle();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WheelJoint_getJointAngularSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WheelJoint");

    // float GetJointAngularSpeed()
    float ret = self->GetJointAngularSpeed();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WheelJoint_getJointLinearSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WheelJoint");

    // float GetJointLinearSpeed()
    float ret = self->GetJointLinearSpeed();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WheelJoint_getJointTranslation(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WheelJoint");

    // float GetJointTranslation()
    float ret = self->GetJointTranslation();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WheelJoint_getLocalAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WheelJoint");

    // const b2Vec2 &GetLocalAnchorA()
    const b2Vec2 &ret = self->GetLocalAnchorA();
    int num_ret = olua_push_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WheelJoint_getLocalAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WheelJoint");

    // const b2Vec2 &GetLocalAnchorB()
    const b2Vec2 &ret = self->GetLocalAnchorB();
    int num_ret = olua_push_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WheelJoint_getLocalAxisA(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WheelJoint");

    // const b2Vec2 &GetLocalAxisA()
    const b2Vec2 &ret = self->GetLocalAxisA();
    int num_ret = olua_push_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WheelJoint_getLowerLimit(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WheelJoint");

    // float GetLowerLimit()
    float ret = self->GetLowerLimit();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WheelJoint_getMaxMotorTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WheelJoint");

    // float GetMaxMotorTorque()
    float ret = self->GetMaxMotorTorque();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WheelJoint_getMotorSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WheelJoint");

    // float GetMotorSpeed()
    float ret = self->GetMotorSpeed();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WheelJoint_getMotorTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;
    float arg1 = 0;       /** inv_dt */

    olua_to_object(L, 1, &self, "b2.WheelJoint");
    olua_check_number(L, 2, &arg1);

    // float GetMotorTorque(float inv_dt)
    float ret = self->GetMotorTorque(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WheelJoint_getStiffness(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WheelJoint");

    // float GetStiffness()
    float ret = self->GetStiffness();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WheelJoint_getUpperLimit(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WheelJoint");

    // float GetUpperLimit()
    float ret = self->GetUpperLimit();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WheelJoint_isLimitEnabled(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WheelJoint");

    // bool IsLimitEnabled()
    bool ret = self->IsLimitEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WheelJoint_isMotorEnabled(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WheelJoint");

    // bool IsMotorEnabled()
    bool ret = self->IsMotorEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WheelJoint_setDamping(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;
    float arg1 = 0;       /** damping */

    olua_to_object(L, 1, &self, "b2.WheelJoint");
    olua_check_number(L, 2, &arg1);

    // void SetDamping(float damping)
    self->SetDamping(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WheelJoint_setLimits(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;
    float arg1 = 0;       /** lower */
    float arg2 = 0;       /** upper */

    olua_to_object(L, 1, &self, "b2.WheelJoint");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void SetLimits(float lower, float upper)
    self->SetLimits(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WheelJoint_setMaxMotorTorque(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;
    float arg1 = 0;       /** torque */

    olua_to_object(L, 1, &self, "b2.WheelJoint");
    olua_check_number(L, 2, &arg1);

    // void SetMaxMotorTorque(float torque)
    self->SetMaxMotorTorque(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WheelJoint_setMotorSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;
    float arg1 = 0;       /** speed */

    olua_to_object(L, 1, &self, "b2.WheelJoint");
    olua_check_number(L, 2, &arg1);

    // void SetMotorSpeed(float speed)
    self->SetMotorSpeed(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WheelJoint_setStiffness(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJoint *self = nullptr;
    float arg1 = 0;       /** stiffness */

    olua_to_object(L, 1, &self, "b2.WheelJoint");
    olua_check_number(L, 2, &arg1);

    // void SetStiffness(float stiffness)
    self->SetStiffness(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_b2_WheelJoint(lua_State *L)
{
    oluacls_class<b2WheelJoint, b2Joint>(L, "b2.WheelJoint");
    oluacls_func(L, "__gc", _olua_fun_b2WheelJoint___gc);
    oluacls_func(L, "enableLimit", _olua_fun_b2WheelJoint_enableLimit);
    oluacls_func(L, "enableMotor", _olua_fun_b2WheelJoint_enableMotor);
    oluacls_func(L, "getDamping", _olua_fun_b2WheelJoint_getDamping);
    oluacls_func(L, "getJointAngle", _olua_fun_b2WheelJoint_getJointAngle);
    oluacls_func(L, "getJointAngularSpeed", _olua_fun_b2WheelJoint_getJointAngularSpeed);
    oluacls_func(L, "getJointLinearSpeed", _olua_fun_b2WheelJoint_getJointLinearSpeed);
    oluacls_func(L, "getJointTranslation", _olua_fun_b2WheelJoint_getJointTranslation);
    oluacls_func(L, "getLocalAnchorA", _olua_fun_b2WheelJoint_getLocalAnchorA);
    oluacls_func(L, "getLocalAnchorB", _olua_fun_b2WheelJoint_getLocalAnchorB);
    oluacls_func(L, "getLocalAxisA", _olua_fun_b2WheelJoint_getLocalAxisA);
    oluacls_func(L, "getLowerLimit", _olua_fun_b2WheelJoint_getLowerLimit);
    oluacls_func(L, "getMaxMotorTorque", _olua_fun_b2WheelJoint_getMaxMotorTorque);
    oluacls_func(L, "getMotorSpeed", _olua_fun_b2WheelJoint_getMotorSpeed);
    oluacls_func(L, "getMotorTorque", _olua_fun_b2WheelJoint_getMotorTorque);
    oluacls_func(L, "getStiffness", _olua_fun_b2WheelJoint_getStiffness);
    oluacls_func(L, "getUpperLimit", _olua_fun_b2WheelJoint_getUpperLimit);
    oluacls_func(L, "isLimitEnabled", _olua_fun_b2WheelJoint_isLimitEnabled);
    oluacls_func(L, "isMotorEnabled", _olua_fun_b2WheelJoint_isMotorEnabled);
    oluacls_func(L, "setDamping", _olua_fun_b2WheelJoint_setDamping);
    oluacls_func(L, "setLimits", _olua_fun_b2WheelJoint_setLimits);
    oluacls_func(L, "setMaxMotorTorque", _olua_fun_b2WheelJoint_setMaxMotorTorque);
    oluacls_func(L, "setMotorSpeed", _olua_fun_b2WheelJoint_setMotorSpeed);
    oluacls_func(L, "setStiffness", _olua_fun_b2WheelJoint_setStiffness);
    oluacls_prop(L, "damping", _olua_fun_b2WheelJoint_getDamping, _olua_fun_b2WheelJoint_setDamping);
    oluacls_prop(L, "jointAngle", _olua_fun_b2WheelJoint_getJointAngle, nullptr);
    oluacls_prop(L, "jointAngularSpeed", _olua_fun_b2WheelJoint_getJointAngularSpeed, nullptr);
    oluacls_prop(L, "jointLinearSpeed", _olua_fun_b2WheelJoint_getJointLinearSpeed, nullptr);
    oluacls_prop(L, "jointTranslation", _olua_fun_b2WheelJoint_getJointTranslation, nullptr);
    oluacls_prop(L, "limitEnabled", _olua_fun_b2WheelJoint_isLimitEnabled, nullptr);
    oluacls_prop(L, "localAnchorA", _olua_fun_b2WheelJoint_getLocalAnchorA, nullptr);
    oluacls_prop(L, "localAnchorB", _olua_fun_b2WheelJoint_getLocalAnchorB, nullptr);
    oluacls_prop(L, "localAxisA", _olua_fun_b2WheelJoint_getLocalAxisA, nullptr);
    oluacls_prop(L, "lowerLimit", _olua_fun_b2WheelJoint_getLowerLimit, nullptr);
    oluacls_prop(L, "maxMotorTorque", _olua_fun_b2WheelJoint_getMaxMotorTorque, _olua_fun_b2WheelJoint_setMaxMotorTorque);
    oluacls_prop(L, "motorEnabled", _olua_fun_b2WheelJoint_isMotorEnabled, nullptr);
    oluacls_prop(L, "motorSpeed", _olua_fun_b2WheelJoint_getMotorSpeed, _olua_fun_b2WheelJoint_setMotorSpeed);
    oluacls_prop(L, "stiffness", _olua_fun_b2WheelJoint_getStiffness, _olua_fun_b2WheelJoint_setStiffness);
    oluacls_prop(L, "upperLimit", _olua_fun_b2WheelJoint_getUpperLimit, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_WheelJoint(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.WheelJoint")) {
        luaL_error(L, "class not found: b2WheelJoint");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2JointEdge___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2JointEdge *)olua_toobj(L, 1, "b2.JointEdge");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2JointEdge_joint$1(lua_State *L)
{
    olua_startinvoke(L);

    b2JointEdge *self = nullptr;

    olua_to_object(L, 1, &self, "b2.JointEdge");

    // b2Joint *joint
    b2Joint *ret = self->joint;
    int num_ret = olua_push_object(L, ret, "b2.Joint");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2JointEdge_joint$2(lua_State *L)
{
    olua_startinvoke(L);

    b2JointEdge *self = nullptr;
    b2Joint *arg1 = nullptr;       /** joint */

    olua_to_object(L, 1, &self, "b2.JointEdge");
    olua_check_object(L, 2, &arg1, "b2.Joint");

    // b2Joint *joint
    self->joint = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2JointEdge_joint(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Joint *joint
        return _olua_fun_b2JointEdge_joint$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.JointEdge")) && (olua_is_object(L, 2, "b2.Joint"))) {
            // b2Joint *joint
            return _olua_fun_b2JointEdge_joint$2(L);
        // }
    }

    luaL_error(L, "method 'b2JointEdge::joint' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2JointEdge_next$1(lua_State *L)
{
    olua_startinvoke(L);

    b2JointEdge *self = nullptr;

    olua_to_object(L, 1, &self, "b2.JointEdge");

    // b2JointEdge *next
    b2JointEdge *ret = self->next;
    int num_ret = olua_push_object(L, ret, "b2.JointEdge");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2JointEdge_next$2(lua_State *L)
{
    olua_startinvoke(L);

    b2JointEdge *self = nullptr;
    b2JointEdge *arg1 = nullptr;       /** next */

    olua_to_object(L, 1, &self, "b2.JointEdge");
    olua_check_object(L, 2, &arg1, "b2.JointEdge");

    // b2JointEdge *next
    self->next = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2JointEdge_next(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2JointEdge *next
        return _olua_fun_b2JointEdge_next$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.JointEdge")) && (olua_is_object(L, 2, "b2.JointEdge"))) {
            // b2JointEdge *next
            return _olua_fun_b2JointEdge_next$2(L);
        // }
    }

    luaL_error(L, "method 'b2JointEdge::next' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2JointEdge_other$1(lua_State *L)
{
    olua_startinvoke(L);

    b2JointEdge *self = nullptr;

    olua_to_object(L, 1, &self, "b2.JointEdge");

    // b2Body *other
    b2Body *ret = self->other;
    int num_ret = olua_push_object(L, ret, "b2.Body");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2JointEdge_other$2(lua_State *L)
{
    olua_startinvoke(L);

    b2JointEdge *self = nullptr;
    b2Body *arg1 = nullptr;       /** other */

    olua_to_object(L, 1, &self, "b2.JointEdge");
    olua_check_object(L, 2, &arg1, "b2.Body");

    // b2Body *other
    self->other = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2JointEdge_other(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Body *other
        return _olua_fun_b2JointEdge_other$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.JointEdge")) && (olua_is_object(L, 2, "b2.Body"))) {
            // b2Body *other
            return _olua_fun_b2JointEdge_other$2(L);
        // }
    }

    luaL_error(L, "method 'b2JointEdge::other' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2JointEdge_prev$1(lua_State *L)
{
    olua_startinvoke(L);

    b2JointEdge *self = nullptr;

    olua_to_object(L, 1, &self, "b2.JointEdge");

    // b2JointEdge *prev
    b2JointEdge *ret = self->prev;
    int num_ret = olua_push_object(L, ret, "b2.JointEdge");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2JointEdge_prev$2(lua_State *L)
{
    olua_startinvoke(L);

    b2JointEdge *self = nullptr;
    b2JointEdge *arg1 = nullptr;       /** prev */

    olua_to_object(L, 1, &self, "b2.JointEdge");
    olua_check_object(L, 2, &arg1, "b2.JointEdge");

    // b2JointEdge *prev
    self->prev = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2JointEdge_prev(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2JointEdge *prev
        return _olua_fun_b2JointEdge_prev$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.JointEdge")) && (olua_is_object(L, 2, "b2.JointEdge"))) {
            // b2JointEdge *prev
            return _olua_fun_b2JointEdge_prev$2(L);
        // }
    }

    luaL_error(L, "method 'b2JointEdge::prev' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_JointEdge(lua_State *L)
{
    oluacls_class<b2JointEdge>(L, "b2.JointEdge");
    oluacls_func(L, "__gc", _olua_fun_b2JointEdge___gc);
    oluacls_prop(L, "other", _olua_fun_b2JointEdge_other, _olua_fun_b2JointEdge_other);
    oluacls_prop(L, "joint", _olua_fun_b2JointEdge_joint, _olua_fun_b2JointEdge_joint);
    oluacls_prop(L, "prev", _olua_fun_b2JointEdge_prev, _olua_fun_b2JointEdge_prev);
    oluacls_prop(L, "next", _olua_fun_b2JointEdge_next, _olua_fun_b2JointEdge_next);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_JointEdge(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.JointEdge")) {
        luaL_error(L, "class not found: b2JointEdge");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2JointUserData___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2JointUserData *)olua_toobj(L, 1, "b2.JointUserData");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2JointUserData_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2JointUserData()
    b2JointUserData *ret = new b2JointUserData();
    int num_ret = olua_push_object(L, ret, "b2.JointUserData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2JointUserData_pointer$1(lua_State *L)
{
    olua_startinvoke(L);

    b2JointUserData *self = nullptr;

    olua_to_object(L, 1, &self, "b2.JointUserData");

    // uintptr_t pointer
    uintptr_t ret = self->pointer;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2JointUserData_pointer$2(lua_State *L)
{
    olua_startinvoke(L);

    b2JointUserData *self = nullptr;
    uintptr_t arg1 = 0;       /** pointer */

    olua_to_object(L, 1, &self, "b2.JointUserData");
    olua_check_integer(L, 2, &arg1);

    // uintptr_t pointer
    self->pointer = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2JointUserData_pointer(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // uintptr_t pointer
        return _olua_fun_b2JointUserData_pointer$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.JointUserData")) && (olua_is_integer(L, 2))) {
            // uintptr_t pointer
            return _olua_fun_b2JointUserData_pointer$2(L);
        // }
    }

    luaL_error(L, "method 'b2JointUserData::pointer' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_JointUserData(lua_State *L)
{
    oluacls_class<b2JointUserData>(L, "b2.JointUserData");
    oluacls_func(L, "__gc", _olua_fun_b2JointUserData___gc);
    oluacls_func(L, "new", _olua_fun_b2JointUserData_new);
    oluacls_prop(L, "pointer", _olua_fun_b2JointUserData_pointer, _olua_fun_b2JointUserData_pointer);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_JointUserData(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.JointUserData")) {
        luaL_error(L, "class not found: b2JointUserData");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2ContactEdge___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ContactEdge *)olua_toobj(L, 1, "b2.ContactEdge");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2ContactEdge_contact$1(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactEdge *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ContactEdge");

    // b2Contact *contact
    b2Contact *ret = self->contact;
    int num_ret = olua_push_object(L, ret, "b2.Contact");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2ContactEdge_contact$2(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactEdge *self = nullptr;
    b2Contact *arg1 = nullptr;       /** contact */

    olua_to_object(L, 1, &self, "b2.ContactEdge");
    olua_check_object(L, 2, &arg1, "b2.Contact");

    // b2Contact *contact
    self->contact = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2ContactEdge_contact(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Contact *contact
        return _olua_fun_b2ContactEdge_contact$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.ContactEdge")) && (olua_is_object(L, 2, "b2.Contact"))) {
            // b2Contact *contact
            return _olua_fun_b2ContactEdge_contact$2(L);
        // }
    }

    luaL_error(L, "method 'b2ContactEdge::contact' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2ContactEdge_next$1(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactEdge *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ContactEdge");

    // b2ContactEdge *next
    b2ContactEdge *ret = self->next;
    int num_ret = olua_push_object(L, ret, "b2.ContactEdge");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2ContactEdge_next$2(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactEdge *self = nullptr;
    b2ContactEdge *arg1 = nullptr;       /** next */

    olua_to_object(L, 1, &self, "b2.ContactEdge");
    olua_check_object(L, 2, &arg1, "b2.ContactEdge");

    // b2ContactEdge *next
    self->next = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2ContactEdge_next(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2ContactEdge *next
        return _olua_fun_b2ContactEdge_next$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.ContactEdge")) && (olua_is_object(L, 2, "b2.ContactEdge"))) {
            // b2ContactEdge *next
            return _olua_fun_b2ContactEdge_next$2(L);
        // }
    }

    luaL_error(L, "method 'b2ContactEdge::next' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2ContactEdge_other$1(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactEdge *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ContactEdge");

    // b2Body *other
    b2Body *ret = self->other;
    int num_ret = olua_push_object(L, ret, "b2.Body");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2ContactEdge_other$2(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactEdge *self = nullptr;
    b2Body *arg1 = nullptr;       /** other */

    olua_to_object(L, 1, &self, "b2.ContactEdge");
    olua_check_object(L, 2, &arg1, "b2.Body");

    // b2Body *other
    self->other = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2ContactEdge_other(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Body *other
        return _olua_fun_b2ContactEdge_other$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.ContactEdge")) && (olua_is_object(L, 2, "b2.Body"))) {
            // b2Body *other
            return _olua_fun_b2ContactEdge_other$2(L);
        // }
    }

    luaL_error(L, "method 'b2ContactEdge::other' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2ContactEdge_prev$1(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactEdge *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ContactEdge");

    // b2ContactEdge *prev
    b2ContactEdge *ret = self->prev;
    int num_ret = olua_push_object(L, ret, "b2.ContactEdge");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2ContactEdge_prev$2(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactEdge *self = nullptr;
    b2ContactEdge *arg1 = nullptr;       /** prev */

    olua_to_object(L, 1, &self, "b2.ContactEdge");
    olua_check_object(L, 2, &arg1, "b2.ContactEdge");

    // b2ContactEdge *prev
    self->prev = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2ContactEdge_prev(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2ContactEdge *prev
        return _olua_fun_b2ContactEdge_prev$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.ContactEdge")) && (olua_is_object(L, 2, "b2.ContactEdge"))) {
            // b2ContactEdge *prev
            return _olua_fun_b2ContactEdge_prev$2(L);
        // }
    }

    luaL_error(L, "method 'b2ContactEdge::prev' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_ContactEdge(lua_State *L)
{
    oluacls_class<b2ContactEdge>(L, "b2.ContactEdge");
    oluacls_func(L, "__gc", _olua_fun_b2ContactEdge___gc);
    oluacls_prop(L, "other", _olua_fun_b2ContactEdge_other, _olua_fun_b2ContactEdge_other);
    oluacls_prop(L, "contact", _olua_fun_b2ContactEdge_contact, _olua_fun_b2ContactEdge_contact);
    oluacls_prop(L, "prev", _olua_fun_b2ContactEdge_prev, _olua_fun_b2ContactEdge_prev);
    oluacls_prop(L, "next", _olua_fun_b2ContactEdge_next, _olua_fun_b2ContactEdge_next);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_ContactEdge(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.ContactEdge")) {
        luaL_error(L, "class not found: b2ContactEdge");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2ContactManager___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ContactManager *)olua_toobj(L, 1, "b2.ContactManager");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2ContactManager_addPair(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactManager *self = nullptr;
    void *arg1 = nullptr;       /** proxyUserDataA */
    void *arg2 = nullptr;       /** proxyUserDataB */

    olua_to_object(L, 1, &self, "b2.ContactManager");
    olua_check_object(L, 2, &arg1, "void *");
    olua_check_object(L, 3, &arg2, "void *");

    // void AddPair(void *proxyUserDataA, void *proxyUserDataB)
    self->AddPair(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2ContactManager_collide(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactManager *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ContactManager");

    // void Collide()
    self->Collide();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2ContactManager_destroy(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactManager *self = nullptr;
    b2Contact *arg1 = nullptr;       /** c */

    olua_to_object(L, 1, &self, "b2.ContactManager");
    olua_check_object(L, 2, &arg1, "b2.Contact");

    // void Destroy(b2Contact *c)
    self->Destroy(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2ContactManager_findNewContacts(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactManager *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ContactManager");

    // void FindNewContacts()
    self->FindNewContacts();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2ContactManager_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2ContactManager()
    b2ContactManager *ret = new b2ContactManager();
    int num_ret = olua_push_object(L, ret, "b2.ContactManager");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_b2_ContactManager(lua_State *L)
{
    oluacls_class<b2ContactManager>(L, "b2.ContactManager");
    oluacls_func(L, "__gc", _olua_fun_b2ContactManager___gc);
    oluacls_func(L, "addPair", _olua_fun_b2ContactManager_addPair);
    oluacls_func(L, "collide", _olua_fun_b2ContactManager_collide);
    oluacls_func(L, "destroy", _olua_fun_b2ContactManager_destroy);
    oluacls_func(L, "findNewContacts", _olua_fun_b2ContactManager_findNewContacts);
    oluacls_func(L, "new", _olua_fun_b2ContactManager_new);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_ContactManager(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.ContactManager")) {
        luaL_error(L, "class not found: b2ContactManager");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2Profile___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Profile *)olua_toobj(L, 1, "b2.Profile");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Profile_broadphase$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Profile");

    // float broadphase
    float ret = self->broadphase;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Profile_broadphase$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;
    float arg1 = 0;       /** broadphase */

    olua_to_object(L, 1, &self, "b2.Profile");
    olua_check_number(L, 2, &arg1);

    // float broadphase
    self->broadphase = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Profile_broadphase(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float broadphase
        return _olua_fun_b2Profile_broadphase$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Profile")) && (olua_is_number(L, 2))) {
            // float broadphase
            return _olua_fun_b2Profile_broadphase$2(L);
        // }
    }

    luaL_error(L, "method 'b2Profile::broadphase' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Profile_collide$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Profile");

    // float collide
    float ret = self->collide;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Profile_collide$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;
    float arg1 = 0;       /** collide */

    olua_to_object(L, 1, &self, "b2.Profile");
    olua_check_number(L, 2, &arg1);

    // float collide
    self->collide = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Profile_collide(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float collide
        return _olua_fun_b2Profile_collide$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Profile")) && (olua_is_number(L, 2))) {
            // float collide
            return _olua_fun_b2Profile_collide$2(L);
        // }
    }

    luaL_error(L, "method 'b2Profile::collide' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Profile_solve$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Profile");

    // float solve
    float ret = self->solve;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Profile_solve$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;
    float arg1 = 0;       /** solve */

    olua_to_object(L, 1, &self, "b2.Profile");
    olua_check_number(L, 2, &arg1);

    // float solve
    self->solve = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Profile_solve(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float solve
        return _olua_fun_b2Profile_solve$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Profile")) && (olua_is_number(L, 2))) {
            // float solve
            return _olua_fun_b2Profile_solve$2(L);
        // }
    }

    luaL_error(L, "method 'b2Profile::solve' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Profile_solveInit$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Profile");

    // float solveInit
    float ret = self->solveInit;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Profile_solveInit$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;
    float arg1 = 0;       /** solveInit */

    olua_to_object(L, 1, &self, "b2.Profile");
    olua_check_number(L, 2, &arg1);

    // float solveInit
    self->solveInit = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Profile_solveInit(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float solveInit
        return _olua_fun_b2Profile_solveInit$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Profile")) && (olua_is_number(L, 2))) {
            // float solveInit
            return _olua_fun_b2Profile_solveInit$2(L);
        // }
    }

    luaL_error(L, "method 'b2Profile::solveInit' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Profile_solvePosition$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Profile");

    // float solvePosition
    float ret = self->solvePosition;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Profile_solvePosition$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;
    float arg1 = 0;       /** solvePosition */

    olua_to_object(L, 1, &self, "b2.Profile");
    olua_check_number(L, 2, &arg1);

    // float solvePosition
    self->solvePosition = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Profile_solvePosition(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float solvePosition
        return _olua_fun_b2Profile_solvePosition$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Profile")) && (olua_is_number(L, 2))) {
            // float solvePosition
            return _olua_fun_b2Profile_solvePosition$2(L);
        // }
    }

    luaL_error(L, "method 'b2Profile::solvePosition' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Profile_solveTOI$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Profile");

    // float solveTOI
    float ret = self->solveTOI;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Profile_solveTOI$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;
    float arg1 = 0;       /** solveTOI */

    olua_to_object(L, 1, &self, "b2.Profile");
    olua_check_number(L, 2, &arg1);

    // float solveTOI
    self->solveTOI = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Profile_solveTOI(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float solveTOI
        return _olua_fun_b2Profile_solveTOI$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Profile")) && (olua_is_number(L, 2))) {
            // float solveTOI
            return _olua_fun_b2Profile_solveTOI$2(L);
        // }
    }

    luaL_error(L, "method 'b2Profile::solveTOI' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Profile_solveVelocity$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Profile");

    // float solveVelocity
    float ret = self->solveVelocity;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Profile_solveVelocity$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;
    float arg1 = 0;       /** solveVelocity */

    olua_to_object(L, 1, &self, "b2.Profile");
    olua_check_number(L, 2, &arg1);

    // float solveVelocity
    self->solveVelocity = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Profile_solveVelocity(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float solveVelocity
        return _olua_fun_b2Profile_solveVelocity$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Profile")) && (olua_is_number(L, 2))) {
            // float solveVelocity
            return _olua_fun_b2Profile_solveVelocity$2(L);
        // }
    }

    luaL_error(L, "method 'b2Profile::solveVelocity' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Profile_step$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Profile");

    // float step
    float ret = self->step;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Profile_step$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Profile *self = nullptr;
    float arg1 = 0;       /** step */

    olua_to_object(L, 1, &self, "b2.Profile");
    olua_check_number(L, 2, &arg1);

    // float step
    self->step = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Profile_step(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float step
        return _olua_fun_b2Profile_step$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Profile")) && (olua_is_number(L, 2))) {
            // float step
            return _olua_fun_b2Profile_step$2(L);
        // }
    }

    luaL_error(L, "method 'b2Profile::step' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_Profile(lua_State *L)
{
    oluacls_class<b2Profile>(L, "b2.Profile");
    oluacls_func(L, "__gc", _olua_fun_b2Profile___gc);
    oluacls_prop(L, "step", _olua_fun_b2Profile_step, _olua_fun_b2Profile_step);
    oluacls_prop(L, "collide", _olua_fun_b2Profile_collide, _olua_fun_b2Profile_collide);
    oluacls_prop(L, "solve", _olua_fun_b2Profile_solve, _olua_fun_b2Profile_solve);
    oluacls_prop(L, "solveInit", _olua_fun_b2Profile_solveInit, _olua_fun_b2Profile_solveInit);
    oluacls_prop(L, "solveVelocity", _olua_fun_b2Profile_solveVelocity, _olua_fun_b2Profile_solveVelocity);
    oluacls_prop(L, "solvePosition", _olua_fun_b2Profile_solvePosition, _olua_fun_b2Profile_solvePosition);
    oluacls_prop(L, "broadphase", _olua_fun_b2Profile_broadphase, _olua_fun_b2Profile_broadphase);
    oluacls_prop(L, "solveTOI", _olua_fun_b2Profile_solveTOI, _olua_fun_b2Profile_solveTOI);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_Profile(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.Profile")) {
        luaL_error(L, "class not found: b2Profile");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2BroadPhase___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2BroadPhase *)olua_toobj(L, 1, "b2.BroadPhase");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2BroadPhase_createProxy(lua_State *L)
{
    olua_startinvoke(L);

    b2BroadPhase *self = nullptr;
    b2AABB *arg1;       /** aabb */
    void *arg2 = nullptr;       /** userData */

    olua_to_object(L, 1, &self, "b2.BroadPhase");
    olua_check_object(L, 2, &arg1, "b2.AABB");
    olua_check_object(L, 3, &arg2, "void *");

    // int32 CreateProxy(const b2AABB &aabb, void *userData)
    int32 ret = self->CreateProxy(*arg1, arg2);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2BroadPhase_destroyProxy(lua_State *L)
{
    olua_startinvoke(L);

    b2BroadPhase *self = nullptr;
    int32 arg1 = 0;       /** proxyId */

    olua_to_object(L, 1, &self, "b2.BroadPhase");
    olua_check_integer(L, 2, &arg1);

    // void DestroyProxy(int32 proxyId)
    self->DestroyProxy(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2BroadPhase_getFatAABB(lua_State *L)
{
    olua_startinvoke(L);

    b2BroadPhase *self = nullptr;
    int32 arg1 = 0;       /** proxyId */

    olua_to_object(L, 1, &self, "b2.BroadPhase");
    olua_check_integer(L, 2, &arg1);

    // const b2AABB &GetFatAABB(int32 proxyId)
    const b2AABB &ret = self->GetFatAABB(arg1);
    int num_ret = olua_push_object(L, ret, "b2.AABB");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2BroadPhase_getProxyCount(lua_State *L)
{
    olua_startinvoke(L);

    b2BroadPhase *self = nullptr;

    olua_to_object(L, 1, &self, "b2.BroadPhase");

    // int32 GetProxyCount()
    int32 ret = self->GetProxyCount();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2BroadPhase_getTreeBalance(lua_State *L)
{
    olua_startinvoke(L);

    b2BroadPhase *self = nullptr;

    olua_to_object(L, 1, &self, "b2.BroadPhase");

    // int32 GetTreeBalance()
    int32 ret = self->GetTreeBalance();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2BroadPhase_getTreeHeight(lua_State *L)
{
    olua_startinvoke(L);

    b2BroadPhase *self = nullptr;

    olua_to_object(L, 1, &self, "b2.BroadPhase");

    // int32 GetTreeHeight()
    int32 ret = self->GetTreeHeight();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2BroadPhase_getTreeQuality(lua_State *L)
{
    olua_startinvoke(L);

    b2BroadPhase *self = nullptr;

    olua_to_object(L, 1, &self, "b2.BroadPhase");

    // float GetTreeQuality()
    float ret = self->GetTreeQuality();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2BroadPhase_getUserData(lua_State *L)
{
    olua_startinvoke(L);

    b2BroadPhase *self = nullptr;
    int32 arg1 = 0;       /** proxyId */

    olua_to_object(L, 1, &self, "b2.BroadPhase");
    olua_check_integer(L, 2, &arg1);

    // void *GetUserData(int32 proxyId)
    void *ret = self->GetUserData(arg1);
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2BroadPhase_moveProxy(lua_State *L)
{
    olua_startinvoke(L);

    b2BroadPhase *self = nullptr;
    int32 arg1 = 0;       /** proxyId */
    b2AABB *arg2;       /** aabb */
    b2Vec2 *arg3;       /** displacement */

    olua_to_object(L, 1, &self, "b2.BroadPhase");
    olua_check_integer(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "b2.AABB");
    olua_check_object(L, 4, &arg3, "b2.Vec2");

    // void MoveProxy(int32 proxyId, const b2AABB &aabb, const b2Vec2 &displacement)
    self->MoveProxy(arg1, *arg2, *arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2BroadPhase_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2BroadPhase()
    b2BroadPhase *ret = new b2BroadPhase();
    int num_ret = olua_push_object(L, ret, "b2.BroadPhase");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2BroadPhase_shiftOrigin(lua_State *L)
{
    olua_startinvoke(L);

    b2BroadPhase *self = nullptr;
    b2Vec2 *arg1;       /** newOrigin */

    olua_to_object(L, 1, &self, "b2.BroadPhase");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // void ShiftOrigin(const b2Vec2 &newOrigin)
    self->ShiftOrigin(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2BroadPhase_testOverlap(lua_State *L)
{
    olua_startinvoke(L);

    b2BroadPhase *self = nullptr;
    int32 arg1 = 0;       /** proxyIdA */
    int32 arg2 = 0;       /** proxyIdB */

    olua_to_object(L, 1, &self, "b2.BroadPhase");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // bool TestOverlap(int32 proxyIdA, int32 proxyIdB)
    bool ret = self->TestOverlap(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2BroadPhase_touchProxy(lua_State *L)
{
    olua_startinvoke(L);

    b2BroadPhase *self = nullptr;
    int32 arg1 = 0;       /** proxyId */

    olua_to_object(L, 1, &self, "b2.BroadPhase");
    olua_check_integer(L, 2, &arg1);

    // void TouchProxy(int32 proxyId)
    self->TouchProxy(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_b2_BroadPhase(lua_State *L)
{
    oluacls_class<b2BroadPhase>(L, "b2.BroadPhase");
    oluacls_func(L, "__gc", _olua_fun_b2BroadPhase___gc);
    oluacls_func(L, "createProxy", _olua_fun_b2BroadPhase_createProxy);
    oluacls_func(L, "destroyProxy", _olua_fun_b2BroadPhase_destroyProxy);
    oluacls_func(L, "getFatAABB", _olua_fun_b2BroadPhase_getFatAABB);
    oluacls_func(L, "getProxyCount", _olua_fun_b2BroadPhase_getProxyCount);
    oluacls_func(L, "getTreeBalance", _olua_fun_b2BroadPhase_getTreeBalance);
    oluacls_func(L, "getTreeHeight", _olua_fun_b2BroadPhase_getTreeHeight);
    oluacls_func(L, "getTreeQuality", _olua_fun_b2BroadPhase_getTreeQuality);
    oluacls_func(L, "getUserData", _olua_fun_b2BroadPhase_getUserData);
    oluacls_func(L, "moveProxy", _olua_fun_b2BroadPhase_moveProxy);
    oluacls_func(L, "new", _olua_fun_b2BroadPhase_new);
    oluacls_func(L, "shiftOrigin", _olua_fun_b2BroadPhase_shiftOrigin);
    oluacls_func(L, "testOverlap", _olua_fun_b2BroadPhase_testOverlap);
    oluacls_func(L, "touchProxy", _olua_fun_b2BroadPhase_touchProxy);
    oluacls_prop(L, "proxyCount", _olua_fun_b2BroadPhase_getProxyCount, nullptr);
    oluacls_prop(L, "treeBalance", _olua_fun_b2BroadPhase_getTreeBalance, nullptr);
    oluacls_prop(L, "treeHeight", _olua_fun_b2BroadPhase_getTreeHeight, nullptr);
    oluacls_prop(L, "treeQuality", _olua_fun_b2BroadPhase_getTreeQuality, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_BroadPhase(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.BroadPhase")) {
        luaL_error(L, "class not found: b2BroadPhase");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2AABB___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2AABB *)olua_toobj(L, 1, "b2.AABB");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2AABB_combine$1(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;
    b2AABB *arg1;       /** aabb */

    olua_to_object(L, 1, &self, "b2.AABB");
    olua_check_object(L, 2, &arg1, "b2.AABB");

    // void Combine(const b2AABB &aabb)
    self->Combine(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2AABB_combine$2(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;
    b2AABB *arg1;       /** aabb1 */
    b2AABB *arg2;       /** aabb2 */

    olua_to_object(L, 1, &self, "b2.AABB");
    olua_check_object(L, 2, &arg1, "b2.AABB");
    olua_check_object(L, 3, &arg2, "b2.AABB");

    // void Combine(const b2AABB &aabb1, const b2AABB &aabb2)
    self->Combine(*arg1, *arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2AABB_combine(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.AABB")) && (olua_is_object(L, 2, "b2.AABB"))) {
            // void Combine(const b2AABB &aabb)
            return _olua_fun_b2AABB_combine$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "b2.AABB")) && (olua_is_object(L, 2, "b2.AABB")) && (olua_is_object(L, 3, "b2.AABB"))) {
            // void Combine(const b2AABB &aabb1, const b2AABB &aabb2)
            return _olua_fun_b2AABB_combine$2(L);
        // }
    }

    luaL_error(L, "method 'b2AABB::combine' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2AABB_contains(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;
    b2AABB *arg1;       /** aabb */

    olua_to_object(L, 1, &self, "b2.AABB");
    olua_check_object(L, 2, &arg1, "b2.AABB");

    // bool Contains(const b2AABB &aabb)
    bool ret = self->Contains(*arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2AABB_getCenter(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;

    olua_to_object(L, 1, &self, "b2.AABB");

    // b2Vec2 GetCenter()
    b2Vec2 ret = self->GetCenter();
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2AABB_getExtents(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;

    olua_to_object(L, 1, &self, "b2.AABB");

    // b2Vec2 GetExtents()
    b2Vec2 ret = self->GetExtents();
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2AABB_getPerimeter(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;

    olua_to_object(L, 1, &self, "b2.AABB");

    // float GetPerimeter()
    float ret = self->GetPerimeter();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2AABB_isValid(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;

    olua_to_object(L, 1, &self, "b2.AABB");

    // bool IsValid()
    bool ret = self->IsValid();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2AABB_lowerBound$1(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;

    olua_to_object(L, 1, &self, "b2.AABB");

    // b2Vec2 lowerBound
    b2Vec2 &ret = self->lowerBound;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2AABB_lowerBound$2(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;
    b2Vec2 *arg1;       /** lowerBound */

    olua_to_object(L, 1, &self, "b2.AABB");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 lowerBound
    self->lowerBound = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2AABB_lowerBound(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 lowerBound
        return _olua_fun_b2AABB_lowerBound$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.AABB")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 lowerBound
            return _olua_fun_b2AABB_lowerBound$2(L);
        // }
    }

    luaL_error(L, "method 'b2AABB::lowerBound' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2AABB_rayCast(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;
    b2RayCastOutput *arg1 = nullptr;       /** output */
    b2RayCastInput *arg2;       /** input */

    olua_to_object(L, 1, &self, "b2.AABB");
    olua_check_object(L, 2, &arg1, "b2.RayCastOutput");
    olua_check_object(L, 3, &arg2, "b2.RayCastInput");

    // bool RayCast(b2RayCastOutput *output, const b2RayCastInput &input)
    bool ret = self->RayCast(arg1, *arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2AABB_upperBound$1(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;

    olua_to_object(L, 1, &self, "b2.AABB");

    // b2Vec2 upperBound
    b2Vec2 &ret = self->upperBound;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2AABB_upperBound$2(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;
    b2Vec2 *arg1;       /** upperBound */

    olua_to_object(L, 1, &self, "b2.AABB");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 upperBound
    self->upperBound = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2AABB_upperBound(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 upperBound
        return _olua_fun_b2AABB_upperBound$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.AABB")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 upperBound
            return _olua_fun_b2AABB_upperBound$2(L);
        // }
    }

    luaL_error(L, "method 'b2AABB::upperBound' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_AABB(lua_State *L)
{
    oluacls_class<b2AABB>(L, "b2.AABB");
    oluacls_func(L, "__gc", _olua_fun_b2AABB___gc);
    oluacls_func(L, "combine", _olua_fun_b2AABB_combine);
    oluacls_func(L, "contains", _olua_fun_b2AABB_contains);
    oluacls_func(L, "getCenter", _olua_fun_b2AABB_getCenter);
    oluacls_func(L, "getExtents", _olua_fun_b2AABB_getExtents);
    oluacls_func(L, "getPerimeter", _olua_fun_b2AABB_getPerimeter);
    oluacls_func(L, "isValid", _olua_fun_b2AABB_isValid);
    oluacls_func(L, "rayCast", _olua_fun_b2AABB_rayCast);
    oluacls_prop(L, "center", _olua_fun_b2AABB_getCenter, nullptr);
    oluacls_prop(L, "extents", _olua_fun_b2AABB_getExtents, nullptr);
    oluacls_prop(L, "perimeter", _olua_fun_b2AABB_getPerimeter, nullptr);
    oluacls_prop(L, "valid", _olua_fun_b2AABB_isValid, nullptr);
    oluacls_prop(L, "lowerBound", _olua_fun_b2AABB_lowerBound, _olua_fun_b2AABB_lowerBound);
    oluacls_prop(L, "upperBound", _olua_fun_b2AABB_upperBound, _olua_fun_b2AABB_upperBound);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_AABB(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.AABB")) {
        luaL_error(L, "class not found: b2AABB");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2Contact_evaluate(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;
    b2Manifold *arg1 = nullptr;       /** manifold */
    b2Transform *arg2;       /** xfA */
    b2Transform *arg3;       /** xfB */

    olua_to_object(L, 1, &self, "b2.Contact");
    olua_check_object(L, 2, &arg1, "b2.Manifold");
    olua_check_object(L, 3, &arg2, "b2.Transform");
    olua_check_object(L, 4, &arg3, "b2.Transform");

    // void Evaluate(b2Manifold *manifold, const b2Transform &xfA, const b2Transform &xfB)
    self->Evaluate(arg1, *arg2, *arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Contact_getChildIndexA(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Contact");

    // int32 GetChildIndexA()
    int32 ret = self->GetChildIndexA();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Contact_getChildIndexB(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Contact");

    // int32 GetChildIndexB()
    int32 ret = self->GetChildIndexB();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Contact_getFixtureA(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Contact");

    // b2Fixture *GetFixtureA()
    b2Fixture *ret = self->GetFixtureA();
    int num_ret = olua_push_object(L, ret, "b2.Fixture");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Contact_getFixtureB(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Contact");

    // b2Fixture *GetFixtureB()
    b2Fixture *ret = self->GetFixtureB();
    int num_ret = olua_push_object(L, ret, "b2.Fixture");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Contact_getFriction(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Contact");

    // float GetFriction()
    float ret = self->GetFriction();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Contact_getManifold(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Contact");

    // b2Manifold *GetManifold()
    b2Manifold *ret = self->GetManifold();
    int num_ret = olua_push_object(L, ret, "b2.Manifold");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Contact_getNext(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Contact");

    // b2Contact *GetNext()
    b2Contact *ret = self->GetNext();
    int num_ret = olua_push_object(L, ret, "b2.Contact");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Contact_getRestitution(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Contact");

    // float GetRestitution()
    float ret = self->GetRestitution();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Contact_getRestitutionThreshold(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Contact");

    // float GetRestitutionThreshold()
    float ret = self->GetRestitutionThreshold();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Contact_getTangentSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Contact");

    // float GetTangentSpeed()
    float ret = self->GetTangentSpeed();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Contact_getWorldManifold(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;
    b2WorldManifold *arg1 = nullptr;       /** worldManifold */

    olua_to_object(L, 1, &self, "b2.Contact");
    olua_check_object(L, 2, &arg1, "b2.WorldManifold");

    // void GetWorldManifold(b2WorldManifold *worldManifold)
    self->GetWorldManifold(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Contact_isEnabled(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Contact");

    // bool IsEnabled()
    bool ret = self->IsEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Contact_isTouching(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Contact");

    // bool IsTouching()
    bool ret = self->IsTouching();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Contact_resetFriction(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Contact");

    // void ResetFriction()
    self->ResetFriction();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Contact_resetRestitution(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Contact");

    // void ResetRestitution()
    self->ResetRestitution();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Contact_resetRestitutionThreshold(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Contact");

    // void ResetRestitutionThreshold()
    self->ResetRestitutionThreshold();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Contact_setEnabled(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_object(L, 1, &self, "b2.Contact");
    olua_check_bool(L, 2, &arg1);

    // void SetEnabled(bool flag)
    self->SetEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Contact_setFriction(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;
    float arg1 = 0;       /** friction */

    olua_to_object(L, 1, &self, "b2.Contact");
    olua_check_number(L, 2, &arg1);

    // void SetFriction(float friction)
    self->SetFriction(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Contact_setRestitution(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;
    float arg1 = 0;       /** restitution */

    olua_to_object(L, 1, &self, "b2.Contact");
    olua_check_number(L, 2, &arg1);

    // void SetRestitution(float restitution)
    self->SetRestitution(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Contact_setRestitutionThreshold(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;
    float arg1 = 0;       /** threshold */

    olua_to_object(L, 1, &self, "b2.Contact");
    olua_check_number(L, 2, &arg1);

    // void SetRestitutionThreshold(float threshold)
    self->SetRestitutionThreshold(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Contact_setTangentSpeed(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;
    float arg1 = 0;       /** speed */

    olua_to_object(L, 1, &self, "b2.Contact");
    olua_check_number(L, 2, &arg1);

    // void SetTangentSpeed(float speed)
    self->SetTangentSpeed(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_b2_Contact(lua_State *L)
{
    oluacls_class<b2Contact>(L, "b2.Contact");
    oluacls_func(L, "evaluate", _olua_fun_b2Contact_evaluate);
    oluacls_func(L, "getChildIndexA", _olua_fun_b2Contact_getChildIndexA);
    oluacls_func(L, "getChildIndexB", _olua_fun_b2Contact_getChildIndexB);
    oluacls_func(L, "getFixtureA", _olua_fun_b2Contact_getFixtureA);
    oluacls_func(L, "getFixtureB", _olua_fun_b2Contact_getFixtureB);
    oluacls_func(L, "getFriction", _olua_fun_b2Contact_getFriction);
    oluacls_func(L, "getManifold", _olua_fun_b2Contact_getManifold);
    oluacls_func(L, "getNext", _olua_fun_b2Contact_getNext);
    oluacls_func(L, "getRestitution", _olua_fun_b2Contact_getRestitution);
    oluacls_func(L, "getRestitutionThreshold", _olua_fun_b2Contact_getRestitutionThreshold);
    oluacls_func(L, "getTangentSpeed", _olua_fun_b2Contact_getTangentSpeed);
    oluacls_func(L, "getWorldManifold", _olua_fun_b2Contact_getWorldManifold);
    oluacls_func(L, "isEnabled", _olua_fun_b2Contact_isEnabled);
    oluacls_func(L, "isTouching", _olua_fun_b2Contact_isTouching);
    oluacls_func(L, "resetFriction", _olua_fun_b2Contact_resetFriction);
    oluacls_func(L, "resetRestitution", _olua_fun_b2Contact_resetRestitution);
    oluacls_func(L, "resetRestitutionThreshold", _olua_fun_b2Contact_resetRestitutionThreshold);
    oluacls_func(L, "setEnabled", _olua_fun_b2Contact_setEnabled);
    oluacls_func(L, "setFriction", _olua_fun_b2Contact_setFriction);
    oluacls_func(L, "setRestitution", _olua_fun_b2Contact_setRestitution);
    oluacls_func(L, "setRestitutionThreshold", _olua_fun_b2Contact_setRestitutionThreshold);
    oluacls_func(L, "setTangentSpeed", _olua_fun_b2Contact_setTangentSpeed);
    oluacls_prop(L, "childIndexA", _olua_fun_b2Contact_getChildIndexA, nullptr);
    oluacls_prop(L, "childIndexB", _olua_fun_b2Contact_getChildIndexB, nullptr);
    oluacls_prop(L, "enabled", _olua_fun_b2Contact_isEnabled, _olua_fun_b2Contact_setEnabled);
    oluacls_prop(L, "fixtureA", _olua_fun_b2Contact_getFixtureA, nullptr);
    oluacls_prop(L, "fixtureB", _olua_fun_b2Contact_getFixtureB, nullptr);
    oluacls_prop(L, "friction", _olua_fun_b2Contact_getFriction, _olua_fun_b2Contact_setFriction);
    oluacls_prop(L, "manifold", _olua_fun_b2Contact_getManifold, nullptr);
    oluacls_prop(L, "next", _olua_fun_b2Contact_getNext, nullptr);
    oluacls_prop(L, "restitution", _olua_fun_b2Contact_getRestitution, _olua_fun_b2Contact_setRestitution);
    oluacls_prop(L, "restitutionThreshold", _olua_fun_b2Contact_getRestitutionThreshold, _olua_fun_b2Contact_setRestitutionThreshold);
    oluacls_prop(L, "tangentSpeed", _olua_fun_b2Contact_getTangentSpeed, _olua_fun_b2Contact_setTangentSpeed);
    oluacls_prop(L, "touching", _olua_fun_b2Contact_isTouching, nullptr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_Contact(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.Contact")) {
        luaL_error(L, "class not found: b2Contact");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2ContactImpulse___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ContactImpulse *)olua_toobj(L, 1, "b2.ContactImpulse");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2ContactImpulse_count$1(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactImpulse *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ContactImpulse");

    // int32 count
    int32 ret = self->count;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2ContactImpulse_count$2(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactImpulse *self = nullptr;
    int32 arg1 = 0;       /** count */

    olua_to_object(L, 1, &self, "b2.ContactImpulse");
    olua_check_integer(L, 2, &arg1);

    // int32 count
    self->count = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2ContactImpulse_count(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // int32 count
        return _olua_fun_b2ContactImpulse_count$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.ContactImpulse")) && (olua_is_integer(L, 2))) {
            // int32 count
            return _olua_fun_b2ContactImpulse_count$2(L);
        // }
    }

    luaL_error(L, "method 'b2ContactImpulse::count' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_ContactImpulse(lua_State *L)
{
    oluacls_class<b2ContactImpulse>(L, "b2.ContactImpulse");
    oluacls_func(L, "__gc", _olua_fun_b2ContactImpulse___gc);
    oluacls_prop(L, "count", _olua_fun_b2ContactImpulse_count, _olua_fun_b2ContactImpulse_count);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_ContactImpulse(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.ContactImpulse")) {
        luaL_error(L, "class not found: b2ContactImpulse");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2Manifold___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Manifold *)olua_toobj(L, 1, "b2.Manifold");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Manifold_localNormal$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Manifold *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Manifold");

    // b2Vec2 localNormal
    b2Vec2 &ret = self->localNormal;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Manifold_localNormal$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Manifold *self = nullptr;
    b2Vec2 *arg1;       /** localNormal */

    olua_to_object(L, 1, &self, "b2.Manifold");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localNormal
    self->localNormal = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Manifold_localNormal(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 localNormal
        return _olua_fun_b2Manifold_localNormal$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Manifold")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 localNormal
            return _olua_fun_b2Manifold_localNormal$2(L);
        // }
    }

    luaL_error(L, "method 'b2Manifold::localNormal' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Manifold_localPoint$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Manifold *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Manifold");

    // b2Vec2 localPoint
    b2Vec2 &ret = self->localPoint;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Manifold_localPoint$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Manifold *self = nullptr;
    b2Vec2 *arg1;       /** localPoint */

    olua_to_object(L, 1, &self, "b2.Manifold");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localPoint
    self->localPoint = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Manifold_localPoint(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 localPoint
        return _olua_fun_b2Manifold_localPoint$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Manifold")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 localPoint
            return _olua_fun_b2Manifold_localPoint$2(L);
        // }
    }

    luaL_error(L, "method 'b2Manifold::localPoint' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Manifold_pointCount$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Manifold *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Manifold");

    // int32 pointCount
    int32 ret = self->pointCount;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Manifold_pointCount$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Manifold *self = nullptr;
    int32 arg1 = 0;       /** pointCount */

    olua_to_object(L, 1, &self, "b2.Manifold");
    olua_check_integer(L, 2, &arg1);

    // int32 pointCount
    self->pointCount = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Manifold_pointCount(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // int32 pointCount
        return _olua_fun_b2Manifold_pointCount$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Manifold")) && (olua_is_integer(L, 2))) {
            // int32 pointCount
            return _olua_fun_b2Manifold_pointCount$2(L);
        // }
    }

    luaL_error(L, "method 'b2Manifold::pointCount' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_b2Manifold_type$1(lua_State *L)
{
    olua_startinvoke(L);

    b2Manifold *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Manifold");

    // b2Manifold::Type type
    b2Manifold::Type ret = self->type;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2Manifold_type$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Manifold *self = nullptr;
    b2Manifold::Type arg1 = (b2Manifold::Type)0;       /** type */

    olua_to_object(L, 1, &self, "b2.Manifold");
    olua_check_enum(L, 2, &arg1);

    // b2Manifold::Type type
    self->type = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2Manifold_type(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Manifold::Type type
        return _olua_fun_b2Manifold_type$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Manifold")) && (olua_is_enum(L, 2))) {
            // b2Manifold::Type type
            return _olua_fun_b2Manifold_type$2(L);
        // }
    }

    luaL_error(L, "method 'b2Manifold::type' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_Manifold(lua_State *L)
{
    oluacls_class<b2Manifold>(L, "b2.Manifold");
    oluacls_func(L, "__gc", _olua_fun_b2Manifold___gc);
    oluacls_prop(L, "localNormal", _olua_fun_b2Manifold_localNormal, _olua_fun_b2Manifold_localNormal);
    oluacls_prop(L, "localPoint", _olua_fun_b2Manifold_localPoint, _olua_fun_b2Manifold_localPoint);
    oluacls_prop(L, "type", _olua_fun_b2Manifold_type, _olua_fun_b2Manifold_type);
    oluacls_prop(L, "pointCount", _olua_fun_b2Manifold_pointCount, _olua_fun_b2Manifold_pointCount);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_Manifold(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.Manifold")) {
        luaL_error(L, "class not found: b2Manifold");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_cls_b2_Manifold_Type(lua_State *L)
{
    oluacls_class<b2Manifold::Type>(L, "b2.Manifold.Type");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "circles", (lua_Integer)b2Manifold::Type::e_circles);
    oluacls_enum(L, "faceA", (lua_Integer)b2Manifold::Type::e_faceA);
    oluacls_enum(L, "faceB", (lua_Integer)b2Manifold::Type::e_faceB);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_Manifold_Type(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.Manifold.Type")) {
        luaL_error(L, "class not found: b2Manifold::Type");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2World___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2World *)olua_toobj(L, 1, "b2.World");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2World_clearForces(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_object(L, 1, &self, "b2.World");

    // void ClearForces()
    self->ClearForces();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2World_createBody(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2BodyDef *arg1 = nullptr;       /** def */

    olua_to_object(L, 1, &self, "b2.World");
    olua_check_object(L, 2, &arg1, "b2.BodyDef");

    // b2Body *CreateBody(const b2BodyDef *def)
    b2Body *ret = self->CreateBody(arg1);
    int num_ret = olua_push_object(L, ret, "b2.Body");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2World_createJoint(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2JointDef *arg1 = nullptr;       /** def */

    olua_to_object(L, 1, &self, "b2.World");
    olua_check_object(L, 2, &arg1, "b2.JointDef");

    // b2Joint *CreateJoint(const b2JointDef *def)
    b2Joint *ret = self->CreateJoint(arg1);
    int num_ret = olua_push_object(L, ret, "b2.Joint");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2World_debugDraw(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_object(L, 1, &self, "b2.World");

    // void DebugDraw()
    self->DebugDraw();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2World_destroyBody(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2Body *arg1 = nullptr;       /** body */

    olua_to_object(L, 1, &self, "b2.World");
    olua_check_object(L, 2, &arg1, "b2.Body");

    // void DestroyBody(b2Body *body)
    self->DestroyBody(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2World_destroyJoint(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2Joint *arg1 = nullptr;       /** joint */

    olua_to_object(L, 1, &self, "b2.World");
    olua_check_object(L, 2, &arg1, "b2.Joint");

    // void DestroyJoint(b2Joint *joint)
    self->DestroyJoint(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2World_dump(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_object(L, 1, &self, "b2.World");

    // void Dump()
    self->Dump();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2World_getAllowSleeping(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_object(L, 1, &self, "b2.World");

    // bool GetAllowSleeping()
    bool ret = self->GetAllowSleeping();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2World_getAutoClearForces(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_object(L, 1, &self, "b2.World");

    // bool GetAutoClearForces()
    bool ret = self->GetAutoClearForces();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2World_getBodyCount(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_object(L, 1, &self, "b2.World");

    // int32 GetBodyCount()
    int32 ret = self->GetBodyCount();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2World_getBodyList(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_object(L, 1, &self, "b2.World");

    // b2Body *GetBodyList()
    b2Body *ret = self->GetBodyList();
    int num_ret = olua_push_object(L, ret, "b2.Body");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2World_getContactCount(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_object(L, 1, &self, "b2.World");

    // int32 GetContactCount()
    int32 ret = self->GetContactCount();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2World_getContactList(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_object(L, 1, &self, "b2.World");

    // b2Contact *GetContactList()
    b2Contact *ret = self->GetContactList();
    int num_ret = olua_push_object(L, ret, "b2.Contact");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2World_getContactManager(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_object(L, 1, &self, "b2.World");

    // const b2ContactManager &GetContactManager()
    const b2ContactManager &ret = self->GetContactManager();
    int num_ret = olua_push_object(L, ret, "b2.ContactManager");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2World_getContinuousPhysics(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_object(L, 1, &self, "b2.World");

    // bool GetContinuousPhysics()
    bool ret = self->GetContinuousPhysics();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2World_getGravity(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_object(L, 1, &self, "b2.World");

    // b2Vec2 GetGravity()
    b2Vec2 ret = self->GetGravity();
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2World_getJointCount(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_object(L, 1, &self, "b2.World");

    // int32 GetJointCount()
    int32 ret = self->GetJointCount();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2World_getJointList(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_object(L, 1, &self, "b2.World");

    // b2Joint *GetJointList()
    b2Joint *ret = self->GetJointList();
    int num_ret = olua_push_object(L, ret, "b2.Joint");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2World_getProfile(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_object(L, 1, &self, "b2.World");

    // const b2Profile &GetProfile()
    const b2Profile &ret = self->GetProfile();
    int num_ret = olua_push_object(L, ret, "b2.Profile");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2World_getProxyCount(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_object(L, 1, &self, "b2.World");

    // int32 GetProxyCount()
    int32 ret = self->GetProxyCount();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2World_getSubStepping(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_object(L, 1, &self, "b2.World");

    // bool GetSubStepping()
    bool ret = self->GetSubStepping();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2World_getTreeBalance(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_object(L, 1, &self, "b2.World");

    // int32 GetTreeBalance()
    int32 ret = self->GetTreeBalance();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2World_getTreeHeight(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_object(L, 1, &self, "b2.World");

    // int32 GetTreeHeight()
    int32 ret = self->GetTreeHeight();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2World_getTreeQuality(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_object(L, 1, &self, "b2.World");

    // float GetTreeQuality()
    float ret = self->GetTreeQuality();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2World_getWarmStarting(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_object(L, 1, &self, "b2.World");

    // bool GetWarmStarting()
    bool ret = self->GetWarmStarting();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2World_isLocked(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_object(L, 1, &self, "b2.World");

    // bool IsLocked()
    bool ret = self->IsLocked();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2World_new(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec2 *arg1;       /** gravity */

    olua_check_object(L, 1, &arg1, "b2.Vec2");

    // b2World(const b2Vec2 &gravity)
    b2World *ret = new b2World(*arg1);
    int num_ret = olua_push_object(L, ret, "b2.World");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2World_queryAABB(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2QueryCallback *arg1 = nullptr;       /** callback */
    b2AABB *arg2;       /** aabb */

    olua_to_object(L, 1, &self, "b2.World");
    olua_check_object(L, 2, &arg1, "b2.interface.QueryCallback");
    olua_check_object(L, 3, &arg2, "b2.AABB");

    // void QueryAABB(b2QueryCallback *callback, const b2AABB &aabb)
    self->QueryAABB(arg1, *arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2World_rayCast(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2RayCastCallback *arg1 = nullptr;       /** callback */
    b2Vec2 *arg2;       /** point1 */
    b2Vec2 *arg3;       /** point2 */

    olua_to_object(L, 1, &self, "b2.World");
    olua_check_object(L, 2, &arg1, "b2.interface.RayCastCallback");
    olua_check_object(L, 3, &arg2, "b2.Vec2");
    olua_check_object(L, 4, &arg3, "b2.Vec2");

    // void RayCast(b2RayCastCallback *callback, const b2Vec2 &point1, const b2Vec2 &point2)
    self->RayCast(arg1, *arg2, *arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2World_setAllowSleeping(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_object(L, 1, &self, "b2.World");
    olua_check_bool(L, 2, &arg1);

    // void SetAllowSleeping(bool flag)
    self->SetAllowSleeping(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2World_setAutoClearForces(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_object(L, 1, &self, "b2.World");
    olua_check_bool(L, 2, &arg1);

    // void SetAutoClearForces(bool flag)
    self->SetAutoClearForces(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2World_setContactFilter(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2ContactFilter *arg1 = nullptr;       /** filter */

    olua_to_object(L, 1, &self, "b2.World");
    olua_check_object(L, 2, &arg1, "b2.interface.ContactFilter");

    // void SetContactFilter(@addref(^) b2ContactFilter *filter)
    self->SetContactFilter(arg1);

    // insert code after call
    olua_addref(L, 1, "contactfilter", 2, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2World_setContactListener(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2ContactListener *arg1 = nullptr;       /** listener */

    olua_to_object(L, 1, &self, "b2.World");
    olua_check_object(L, 2, &arg1, "b2.interface.ContactListener");

    // void SetContactListener(@addref(^) b2ContactListener *listener)
    self->SetContactListener(arg1);

    // insert code after call
    olua_addref(L, 1, "contactlistener", 2, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2World_setContinuousPhysics(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_object(L, 1, &self, "b2.World");
    olua_check_bool(L, 2, &arg1);

    // void SetContinuousPhysics(bool flag)
    self->SetContinuousPhysics(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2World_setDebugDraw(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2Draw *arg1 = nullptr;       /** debugDraw */

    olua_to_object(L, 1, &self, "b2.World");
    olua_check_object(L, 2, &arg1, "b2.interface.Draw");

    // void SetDebugDraw(@addref(^) b2Draw *debugDraw)
    self->SetDebugDraw(arg1);

    // insert code after call
    olua_addref(L, 1, "debugdraw", 2, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2World_setDestructionListener(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2DestructionListener *arg1 = nullptr;       /** listener */

    olua_to_object(L, 1, &self, "b2.World");
    olua_check_object(L, 2, &arg1, "b2.interface.DestructionListener");

    // void SetDestructionListener(@addref(^) b2DestructionListener *listener)
    self->SetDestructionListener(arg1);

    // insert code after call
    olua_addref(L, 1, "destructionlistener", 2, OLUA_REF_ALONE);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2World_setGravity(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2Vec2 *arg1;       /** gravity */

    olua_to_object(L, 1, &self, "b2.World");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // void SetGravity(const b2Vec2 &gravity)
    self->SetGravity(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2World_setSubStepping(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_object(L, 1, &self, "b2.World");
    olua_check_bool(L, 2, &arg1);

    // void SetSubStepping(bool flag)
    self->SetSubStepping(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2World_setWarmStarting(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    bool arg1 = false;       /** flag */

    olua_to_object(L, 1, &self, "b2.World");
    olua_check_bool(L, 2, &arg1);

    // void SetWarmStarting(bool flag)
    self->SetWarmStarting(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2World_shiftOrigin(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2Vec2 *arg1;       /** newOrigin */

    olua_to_object(L, 1, &self, "b2.World");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // void ShiftOrigin(const b2Vec2 &newOrigin)
    self->ShiftOrigin(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2World_step(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    float arg1 = 0;       /** timeStep */
    int32 arg2 = 0;       /** velocityIterations */
    int32 arg3 = 0;       /** positionIterations */

    olua_to_object(L, 1, &self, "b2.World");
    olua_check_number(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);
    olua_check_integer(L, 4, &arg3);

    // void Step(float timeStep, int32 velocityIterations, int32 positionIterations)
    self->Step(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_b2_World(lua_State *L)
{
    oluacls_class<b2World>(L, "b2.World");
    oluacls_func(L, "__gc", _olua_fun_b2World___gc);
    oluacls_func(L, "clearForces", _olua_fun_b2World_clearForces);
    oluacls_func(L, "createBody", _olua_fun_b2World_createBody);
    oluacls_func(L, "createJoint", _olua_fun_b2World_createJoint);
    oluacls_func(L, "debugDraw", _olua_fun_b2World_debugDraw);
    oluacls_func(L, "destroyBody", _olua_fun_b2World_destroyBody);
    oluacls_func(L, "destroyJoint", _olua_fun_b2World_destroyJoint);
    oluacls_func(L, "dump", _olua_fun_b2World_dump);
    oluacls_func(L, "getAllowSleeping", _olua_fun_b2World_getAllowSleeping);
    oluacls_func(L, "getAutoClearForces", _olua_fun_b2World_getAutoClearForces);
    oluacls_func(L, "getBodyCount", _olua_fun_b2World_getBodyCount);
    oluacls_func(L, "getBodyList", _olua_fun_b2World_getBodyList);
    oluacls_func(L, "getContactCount", _olua_fun_b2World_getContactCount);
    oluacls_func(L, "getContactList", _olua_fun_b2World_getContactList);
    oluacls_func(L, "getContactManager", _olua_fun_b2World_getContactManager);
    oluacls_func(L, "getContinuousPhysics", _olua_fun_b2World_getContinuousPhysics);
    oluacls_func(L, "getGravity", _olua_fun_b2World_getGravity);
    oluacls_func(L, "getJointCount", _olua_fun_b2World_getJointCount);
    oluacls_func(L, "getJointList", _olua_fun_b2World_getJointList);
    oluacls_func(L, "getProfile", _olua_fun_b2World_getProfile);
    oluacls_func(L, "getProxyCount", _olua_fun_b2World_getProxyCount);
    oluacls_func(L, "getSubStepping", _olua_fun_b2World_getSubStepping);
    oluacls_func(L, "getTreeBalance", _olua_fun_b2World_getTreeBalance);
    oluacls_func(L, "getTreeHeight", _olua_fun_b2World_getTreeHeight);
    oluacls_func(L, "getTreeQuality", _olua_fun_b2World_getTreeQuality);
    oluacls_func(L, "getWarmStarting", _olua_fun_b2World_getWarmStarting);
    oluacls_func(L, "isLocked", _olua_fun_b2World_isLocked);
    oluacls_func(L, "new", _olua_fun_b2World_new);
    oluacls_func(L, "queryAABB", _olua_fun_b2World_queryAABB);
    oluacls_func(L, "rayCast", _olua_fun_b2World_rayCast);
    oluacls_func(L, "setAllowSleeping", _olua_fun_b2World_setAllowSleeping);
    oluacls_func(L, "setAutoClearForces", _olua_fun_b2World_setAutoClearForces);
    oluacls_func(L, "setContactFilter", _olua_fun_b2World_setContactFilter);
    oluacls_func(L, "setContactListener", _olua_fun_b2World_setContactListener);
    oluacls_func(L, "setContinuousPhysics", _olua_fun_b2World_setContinuousPhysics);
    oluacls_func(L, "setDebugDraw", _olua_fun_b2World_setDebugDraw);
    oluacls_func(L, "setDestructionListener", _olua_fun_b2World_setDestructionListener);
    oluacls_func(L, "setGravity", _olua_fun_b2World_setGravity);
    oluacls_func(L, "setSubStepping", _olua_fun_b2World_setSubStepping);
    oluacls_func(L, "setWarmStarting", _olua_fun_b2World_setWarmStarting);
    oluacls_func(L, "shiftOrigin", _olua_fun_b2World_shiftOrigin);
    oluacls_func(L, "step", _olua_fun_b2World_step);
    oluacls_prop(L, "allowSleeping", _olua_fun_b2World_getAllowSleeping, _olua_fun_b2World_setAllowSleeping);
    oluacls_prop(L, "autoClearForces", _olua_fun_b2World_getAutoClearForces, _olua_fun_b2World_setAutoClearForces);
    oluacls_prop(L, "bodyCount", _olua_fun_b2World_getBodyCount, nullptr);
    oluacls_prop(L, "bodyList", _olua_fun_b2World_getBodyList, nullptr);
    oluacls_prop(L, "contactCount", _olua_fun_b2World_getContactCount, nullptr);
    oluacls_prop(L, "contactList", _olua_fun_b2World_getContactList, nullptr);
    oluacls_prop(L, "contactManager", _olua_fun_b2World_getContactManager, nullptr);
    oluacls_prop(L, "continuousPhysics", _olua_fun_b2World_getContinuousPhysics, _olua_fun_b2World_setContinuousPhysics);
    oluacls_prop(L, "gravity", _olua_fun_b2World_getGravity, _olua_fun_b2World_setGravity);
    oluacls_prop(L, "jointCount", _olua_fun_b2World_getJointCount, nullptr);
    oluacls_prop(L, "jointList", _olua_fun_b2World_getJointList, nullptr);
    oluacls_prop(L, "locked", _olua_fun_b2World_isLocked, nullptr);
    oluacls_prop(L, "profile", _olua_fun_b2World_getProfile, nullptr);
    oluacls_prop(L, "proxyCount", _olua_fun_b2World_getProxyCount, nullptr);
    oluacls_prop(L, "subStepping", _olua_fun_b2World_getSubStepping, _olua_fun_b2World_setSubStepping);
    oluacls_prop(L, "treeBalance", _olua_fun_b2World_getTreeBalance, nullptr);
    oluacls_prop(L, "treeHeight", _olua_fun_b2World_getTreeHeight, nullptr);
    oluacls_prop(L, "treeQuality", _olua_fun_b2World_getTreeQuality, nullptr);
    oluacls_prop(L, "warmStarting", _olua_fun_b2World_getWarmStarting, _olua_fun_b2World_setWarmStarting);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_World(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.World")) {
        luaL_error(L, "class not found: b2World");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_b2WorldManifold___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2WorldManifold *)olua_toobj(L, 1, "b2.WorldManifold");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WorldManifold_initialize(lua_State *L)
{
    olua_startinvoke(L);

    b2WorldManifold *self = nullptr;
    b2Manifold *arg1 = nullptr;       /** manifold */
    b2Transform *arg2;       /** xfA */
    float arg3 = 0;       /** radiusA */
    b2Transform *arg4;       /** xfB */
    float arg5 = 0;       /** radiusB */

    olua_to_object(L, 1, &self, "b2.WorldManifold");
    olua_check_object(L, 2, &arg1, "b2.Manifold");
    olua_check_object(L, 3, &arg2, "b2.Transform");
    olua_check_number(L, 4, &arg3);
    olua_check_object(L, 5, &arg4, "b2.Transform");
    olua_check_number(L, 6, &arg5);

    // void Initialize(const b2Manifold *manifold, const b2Transform &xfA, float radiusA, const b2Transform &xfB, float radiusB)
    self->Initialize(arg1, *arg2, arg3, *arg4, arg5);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WorldManifold_normal$1(lua_State *L)
{
    olua_startinvoke(L);

    b2WorldManifold *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WorldManifold");

    // b2Vec2 normal
    b2Vec2 &ret = self->normal;
    int num_ret = olua_copy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_b2WorldManifold_normal$2(lua_State *L)
{
    olua_startinvoke(L);

    b2WorldManifold *self = nullptr;
    b2Vec2 *arg1;       /** normal */

    olua_to_object(L, 1, &self, "b2.WorldManifold");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 normal
    self->normal = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_b2WorldManifold_normal(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // b2Vec2 normal
        return _olua_fun_b2WorldManifold_normal$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.WorldManifold")) && (olua_is_object(L, 2, "b2.Vec2"))) {
            // b2Vec2 normal
            return _olua_fun_b2WorldManifold_normal$2(L);
        // }
    }

    luaL_error(L, "method 'b2WorldManifold::normal' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_b2_WorldManifold(lua_State *L)
{
    oluacls_class<b2WorldManifold>(L, "b2.WorldManifold");
    oluacls_func(L, "__gc", _olua_fun_b2WorldManifold___gc);
    oluacls_func(L, "initialize", _olua_fun_b2WorldManifold_initialize);
    oluacls_prop(L, "normal", _olua_fun_b2WorldManifold_normal, _olua_fun_b2WorldManifold_normal);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2_WorldManifold(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);
    if (!olua_getclass(L, "b2.WorldManifold")) {
        luaL_error(L, "class not found: b2WorldManifold");
    }
    return 1;
}
OLUA_END_DECLS

int _olua_module_box2d(lua_State *L)
{
    olua_require(L, "b2.Vec2", _olua_cls_b2_Vec2);
    olua_require(L, "b2.Vec3", _olua_cls_b2_Vec3);
    olua_require(L, "b2.ContactID", _olua_cls_b2_ContactID);
    olua_require(L, "b2.ContactFeature", _olua_cls_b2_ContactFeature);
    olua_require(L, "b2.Color", _olua_cls_b2_Color);
    olua_require(L, "b2.FixtureUserData", _olua_cls_b2_FixtureUserData);
    olua_require(L, "b2.Filter", _olua_cls_b2_Filter);
    olua_require(L, "b2.ManifoldPoint", _olua_cls_b2_ManifoldPoint);
    olua_require(L, "b2.Rot", _olua_cls_b2_Rot);
    olua_require(L, "b2.interface.Draw", _olua_cls_b2_interface_Draw);
    olua_require(L, "b2.interface.DestructionListener", _olua_cls_b2_interface_DestructionListener);
    olua_require(L, "b2.interface.ContactFilter", _olua_cls_b2_interface_ContactFilter);
    olua_require(L, "b2.interface.ContactListener", _olua_cls_b2_interface_ContactListener);
    olua_require(L, "b2.interface.QueryCallback", _olua_cls_b2_interface_QueryCallback);
    olua_require(L, "b2.interface.RayCastCallback", _olua_cls_b2_interface_RayCastCallback);
    olua_require(L, "b2.Vec2Array", _olua_cls_b2_Vec2Array);
    olua_require(L, "b2.DestructionListener", _olua_cls_b2_DestructionListener);
    olua_require(L, "b2.ContactFilter", _olua_cls_b2_ContactFilter);
    olua_require(L, "b2.ContactListener", _olua_cls_b2_ContactListener);
    olua_require(L, "b2.QueryCallback", _olua_cls_b2_QueryCallback);
    olua_require(L, "b2.RayCastCallback", _olua_cls_b2_RayCastCallback);
    olua_require(L, "b2.DebugNode.Flags", _olua_cls_b2_DebugNode_Flags);
    olua_require(L, "b2.DebugNode", _olua_cls_b2_DebugNode);
    olua_require(L, "b2.MassData", _olua_cls_b2_MassData);
    olua_require(L, "b2.Transform", _olua_cls_b2_Transform);
    olua_require(L, "b2.RayCastInput", _olua_cls_b2_RayCastInput);
    olua_require(L, "b2.RayCastOutput", _olua_cls_b2_RayCastOutput);
    olua_require(L, "b2.Shape.Type", _olua_cls_b2_Shape_Type);
    olua_require(L, "b2.Shape", _olua_cls_b2_Shape);
    olua_require(L, "b2.PolygonShape", _olua_cls_b2_PolygonShape);
    olua_require(L, "b2.EdgeShape", _olua_cls_b2_EdgeShape);
    olua_require(L, "b2.CircleShape", _olua_cls_b2_CircleShape);
    olua_require(L, "b2.ChainShape", _olua_cls_b2_ChainShape);
    olua_require(L, "b2.BodyDef", _olua_cls_b2_BodyDef);
    olua_require(L, "b2.BodyType", _olua_cls_b2_BodyType);
    olua_require(L, "b2.Body", _olua_cls_b2_Body);
    olua_require(L, "b2.BodyUserData", _olua_cls_b2_BodyUserData);
    olua_require(L, "b2.FixtureDef", _olua_cls_b2_FixtureDef);
    olua_require(L, "b2.Fixture", _olua_cls_b2_Fixture);
    olua_require(L, "b2.JointDef", _olua_cls_b2_JointDef);
    olua_require(L, "b2.JointType", _olua_cls_b2_JointType);
    olua_require(L, "b2.Joint", _olua_cls_b2_Joint);
    olua_require(L, "b2.DistanceJointDef", _olua_cls_b2_DistanceJointDef);
    olua_require(L, "b2.DistanceJoint", _olua_cls_b2_DistanceJoint);
    olua_require(L, "b2.FrictionJointDef", _olua_cls_b2_FrictionJointDef);
    olua_require(L, "b2.FrictionJoint", _olua_cls_b2_FrictionJoint);
    olua_require(L, "b2.GearJointDef", _olua_cls_b2_GearJointDef);
    olua_require(L, "b2.GearJoint", _olua_cls_b2_GearJoint);
    olua_require(L, "b2.MotorJointDef", _olua_cls_b2_MotorJointDef);
    olua_require(L, "b2.MotorJoint", _olua_cls_b2_MotorJoint);
    olua_require(L, "b2.MouseJointDef", _olua_cls_b2_MouseJointDef);
    olua_require(L, "b2.MouseJoint", _olua_cls_b2_MouseJoint);
    olua_require(L, "b2.PrismaticJointDef", _olua_cls_b2_PrismaticJointDef);
    olua_require(L, "b2.PrismaticJoint", _olua_cls_b2_PrismaticJoint);
    olua_require(L, "b2.PulleyJointDef", _olua_cls_b2_PulleyJointDef);
    olua_require(L, "b2.PulleyJoint", _olua_cls_b2_PulleyJoint);
    olua_require(L, "b2.RevoluteJointDef", _olua_cls_b2_RevoluteJointDef);
    olua_require(L, "b2.RevoluteJoint", _olua_cls_b2_RevoluteJoint);
    olua_require(L, "b2.WeldJointDef", _olua_cls_b2_WeldJointDef);
    olua_require(L, "b2.WeldJoint", _olua_cls_b2_WeldJoint);
    olua_require(L, "b2.WheelJointDef", _olua_cls_b2_WheelJointDef);
    olua_require(L, "b2.WheelJoint", _olua_cls_b2_WheelJoint);
    olua_require(L, "b2.JointEdge", _olua_cls_b2_JointEdge);
    olua_require(L, "b2.JointUserData", _olua_cls_b2_JointUserData);
    olua_require(L, "b2.ContactEdge", _olua_cls_b2_ContactEdge);
    olua_require(L, "b2.ContactManager", _olua_cls_b2_ContactManager);
    olua_require(L, "b2.Profile", _olua_cls_b2_Profile);
    olua_require(L, "b2.BroadPhase", _olua_cls_b2_BroadPhase);
    olua_require(L, "b2.AABB", _olua_cls_b2_AABB);
    olua_require(L, "b2.Contact", _olua_cls_b2_Contact);
    olua_require(L, "b2.ContactImpulse", _olua_cls_b2_ContactImpulse);
    olua_require(L, "b2.Manifold", _olua_cls_b2_Manifold);
    olua_require(L, "b2.Manifold.Type", _olua_cls_b2_Manifold_Type);
    olua_require(L, "b2.World", _olua_cls_b2_World);
    olua_require(L, "b2.WorldManifold", _olua_cls_b2_WorldManifold);

    cclua::runtime::registerFeature("box2d", true);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_box2d(lua_State *L)
{
    olua_require(L, "box2d",  _olua_module_box2d);

    return 0;
}
OLUA_END_DECLS
