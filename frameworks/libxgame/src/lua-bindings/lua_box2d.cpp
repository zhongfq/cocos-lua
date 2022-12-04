//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_box2d.h"
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "box2d/box2d.h"
#include "box2d/box2d-2dx.h"

static int _b2Vec2___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Vec2 *)olua_toobj(L, 1, "b2.Vec2");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2Vec2___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Vec2 *)olua_toobj(L, 1, "b2.Vec2");
    olua_push_object(L, self, "b2.Vec2");

    olua_endinvoke(L);

    return 1;
}

static int _b2Vec2_IsValid(lua_State *L)
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

static int _b2Vec2_Length(lua_State *L)
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

static int _b2Vec2_LengthSquared(lua_State *L)
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

static int _b2Vec2_new$1(lua_State *L)
{
    olua_startinvoke(L);

    // b2Vec2()
    b2Vec2 *ret = new b2Vec2();
    int num_ret = olua_push_object(L, ret, "b2.Vec2");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Vec2_new$2(lua_State *L)
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

static int _b2Vec2_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // b2Vec2()
        return _b2Vec2_new$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2))) {
            // b2Vec2(float xIn, float yIn)
            return _b2Vec2_new$2(L);
        // }
    }

    luaL_error(L, "method 'b2Vec2::new' not support '%d' arguments", num_args);

    return 0;
}

static int _b2Vec2_Normalize(lua_State *L)
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

static int _b2Vec2_Set(lua_State *L)
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

static int _b2Vec2_SetZero(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec2 *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Vec2");

    // void SetZero()
    self->SetZero();

    olua_endinvoke(L);

    return 0;
}

static int _b2Vec2_Skew(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec2 *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Vec2");

    // b2Vec2 Skew()
    b2Vec2 ret = self->Skew();
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Vec2_get_x(lua_State *L)
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

static int _b2Vec2_set_x(lua_State *L)
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

static int _b2Vec2_get_y(lua_State *L)
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

static int _b2Vec2_set_y(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2Vec2(lua_State *L)
{
    oluacls_class<b2Vec2>(L, "b2.Vec2");
    oluacls_func(L, "__gc", _b2Vec2___gc);
    oluacls_func(L, "__olua_move", _b2Vec2___olua_move);
    oluacls_func(L, "isValid", _b2Vec2_IsValid);
    oluacls_func(L, "length", _b2Vec2_Length);
    oluacls_func(L, "lengthSquared", _b2Vec2_LengthSquared);
    oluacls_func(L, "new", _b2Vec2_new);
    oluacls_func(L, "normalize", _b2Vec2_Normalize);
    oluacls_func(L, "set", _b2Vec2_Set);
    oluacls_func(L, "setZero", _b2Vec2_SetZero);
    oluacls_func(L, "skew", _b2Vec2_Skew);
    oluacls_prop(L, "valid", _b2Vec2_IsValid, nullptr);
    oluacls_prop(L, "x", _b2Vec2_get_x, _b2Vec2_set_x);
    oluacls_prop(L, "y", _b2Vec2_get_y, _b2Vec2_set_y);

    return 1;
}
OLUA_END_DECLS

static int _b2Vec3___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Vec3 *)olua_toobj(L, 1, "b2.Vec3");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2Vec3___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Vec3 *)olua_toobj(L, 1, "b2.Vec3");
    olua_push_object(L, self, "b2.Vec3");

    olua_endinvoke(L);

    return 1;
}

static int _b2Vec3_new$1(lua_State *L)
{
    olua_startinvoke(L);

    // b2Vec3()
    b2Vec3 *ret = new b2Vec3();
    int num_ret = olua_push_object(L, ret, "b2.Vec3");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Vec3_new$2(lua_State *L)
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

static int _b2Vec3_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // b2Vec3()
        return _b2Vec3_new$1(L);
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // b2Vec3(float xIn, float yIn, float zIn)
            return _b2Vec3_new$2(L);
        // }
    }

    luaL_error(L, "method 'b2Vec3::new' not support '%d' arguments", num_args);

    return 0;
}

static int _b2Vec3_Set(lua_State *L)
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

static int _b2Vec3_SetZero(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec3 *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Vec3");

    // void SetZero()
    self->SetZero();

    olua_endinvoke(L);

    return 0;
}

static int _b2Vec3_get_x(lua_State *L)
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

static int _b2Vec3_set_x(lua_State *L)
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

static int _b2Vec3_get_y(lua_State *L)
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

static int _b2Vec3_set_y(lua_State *L)
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

static int _b2Vec3_get_z(lua_State *L)
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

static int _b2Vec3_set_z(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2Vec3(lua_State *L)
{
    oluacls_class<b2Vec3>(L, "b2.Vec3");
    oluacls_func(L, "__gc", _b2Vec3___gc);
    oluacls_func(L, "__olua_move", _b2Vec3___olua_move);
    oluacls_func(L, "new", _b2Vec3_new);
    oluacls_func(L, "set", _b2Vec3_Set);
    oluacls_func(L, "setZero", _b2Vec3_SetZero);
    oluacls_prop(L, "x", _b2Vec3_get_x, _b2Vec3_set_x);
    oluacls_prop(L, "y", _b2Vec3_get_y, _b2Vec3_set_y);
    oluacls_prop(L, "z", _b2Vec3_get_z, _b2Vec3_set_z);

    return 1;
}
OLUA_END_DECLS

static int _b2ContactID___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ContactID *)olua_toobj(L, 1, "b2.ContactID");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2ContactID___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ContactID *)olua_toobj(L, 1, "b2.ContactID");
    olua_push_object(L, self, "b2.ContactID");

    olua_endinvoke(L);

    return 1;
}

static int _b2ContactID_get_cf(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactID *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ContactID");

    // b2ContactFeature cf
    b2ContactFeature &ret = self->cf;
    int num_ret = olua_pushcopy_object(L, ret, "b2.ContactFeature");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2ContactID_set_cf(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactID *self = nullptr;
    b2ContactFeature arg1;       /** cf */

    olua_to_object(L, 1, &self, "b2.ContactID");
    olua_check_object(L, 2, &arg1, "b2.ContactFeature");

    // b2ContactFeature cf
    self->cf = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2ContactID_get_key(lua_State *L)
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

static int _b2ContactID_set_key(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2ContactID(lua_State *L)
{
    oluacls_class<b2ContactID>(L, "b2.ContactID");
    oluacls_func(L, "__gc", _b2ContactID___gc);
    oluacls_func(L, "__olua_move", _b2ContactID___olua_move);
    oluacls_prop(L, "cf", _b2ContactID_get_cf, _b2ContactID_set_cf);
    oluacls_prop(L, "key", _b2ContactID_get_key, _b2ContactID_set_key);

    return 1;
}
OLUA_END_DECLS

static int _b2ContactFeature___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ContactFeature *)olua_toobj(L, 1, "b2.ContactFeature");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2ContactFeature___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ContactFeature *)olua_toobj(L, 1, "b2.ContactFeature");
    olua_push_object(L, self, "b2.ContactFeature");

    olua_endinvoke(L);

    return 1;
}

static int _b2ContactFeature_get_indexA(lua_State *L)
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

static int _b2ContactFeature_set_indexA(lua_State *L)
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

static int _b2ContactFeature_get_indexB(lua_State *L)
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

static int _b2ContactFeature_set_indexB(lua_State *L)
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

static int _b2ContactFeature_get_typeA(lua_State *L)
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

static int _b2ContactFeature_set_typeA(lua_State *L)
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

static int _b2ContactFeature_get_typeB(lua_State *L)
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

static int _b2ContactFeature_set_typeB(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2ContactFeature(lua_State *L)
{
    oluacls_class<b2ContactFeature>(L, "b2.ContactFeature");
    oluacls_func(L, "__gc", _b2ContactFeature___gc);
    oluacls_func(L, "__olua_move", _b2ContactFeature___olua_move);
    oluacls_prop(L, "indexA", _b2ContactFeature_get_indexA, _b2ContactFeature_set_indexA);
    oluacls_prop(L, "indexB", _b2ContactFeature_get_indexB, _b2ContactFeature_set_indexB);
    oluacls_prop(L, "typeA", _b2ContactFeature_get_typeA, _b2ContactFeature_set_typeA);
    oluacls_prop(L, "typeB", _b2ContactFeature_get_typeB, _b2ContactFeature_set_typeB);

    return 1;
}
OLUA_END_DECLS

static int _b2Color___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Color *)olua_toobj(L, 1, "b2.Color");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2Color___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Color *)olua_toobj(L, 1, "b2.Color");
    olua_push_object(L, self, "b2.Color");

    olua_endinvoke(L);

    return 1;
}

static int _b2Color_new$1(lua_State *L)
{
    olua_startinvoke(L);

    // b2Color()
    b2Color *ret = new b2Color();
    int num_ret = olua_push_object(L, ret, "b2.Color");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Color_new$2(lua_State *L)
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

static int _b2Color_new$3(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** rIn */
    float arg2 = 0;       /** gIn */
    float arg3 = 0;       /** bIn */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // b2Color(float rIn, float gIn, float bIn, @optional float aIn)
    b2Color *ret = new b2Color(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "b2.Color");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Color_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // b2Color()
        return _b2Color_new$1(L);
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // b2Color(float rIn, float gIn, float bIn, @optional float aIn)
            return _b2Color_new$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4))) {
            // b2Color(float rIn, float gIn, float bIn, @optional float aIn)
            return _b2Color_new$2(L);
        // }
    }

    luaL_error(L, "method 'b2Color::new' not support '%d' arguments", num_args);

    return 0;
}

static int _b2Color_Set$1(lua_State *L)
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

static int _b2Color_Set$2(lua_State *L)
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

    // void Set(float rIn, float gIn, float bIn, @optional float aIn)
    self->Set(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _b2Color_Set(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 3) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4))) {
            // void Set(float rIn, float gIn, float bIn, @optional float aIn)
            return _b2Color_Set$2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5))) {
            // void Set(float rIn, float gIn, float bIn, @optional float aIn)
            return _b2Color_Set$1(L);
        // }
    }

    luaL_error(L, "method 'b2Color::Set' not support '%d' arguments", num_args);

    return 0;
}

static int _b2Color_get_a(lua_State *L)
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

static int _b2Color_set_a(lua_State *L)
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

static int _b2Color_get_b(lua_State *L)
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

static int _b2Color_set_b(lua_State *L)
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

static int _b2Color_get_g(lua_State *L)
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

static int _b2Color_set_g(lua_State *L)
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

static int _b2Color_get_r(lua_State *L)
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

static int _b2Color_set_r(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2Color(lua_State *L)
{
    oluacls_class<b2Color>(L, "b2.Color");
    oluacls_func(L, "__gc", _b2Color___gc);
    oluacls_func(L, "__olua_move", _b2Color___olua_move);
    oluacls_func(L, "new", _b2Color_new);
    oluacls_func(L, "set", _b2Color_Set);
    oluacls_prop(L, "a", _b2Color_get_a, _b2Color_set_a);
    oluacls_prop(L, "b", _b2Color_get_b, _b2Color_set_b);
    oluacls_prop(L, "g", _b2Color_get_g, _b2Color_set_g);
    oluacls_prop(L, "r", _b2Color_get_r, _b2Color_set_r);

    return 1;
}
OLUA_END_DECLS

static int _b2FixtureUserData___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2FixtureUserData *)olua_toobj(L, 1, "b2.FixtureUserData");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2FixtureUserData___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2FixtureUserData *)olua_toobj(L, 1, "b2.FixtureUserData");
    olua_push_object(L, self, "b2.FixtureUserData");

    olua_endinvoke(L);

    return 1;
}

static int _b2FixtureUserData_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2FixtureUserData()
    b2FixtureUserData *ret = new b2FixtureUserData();
    int num_ret = olua_push_object(L, ret, "b2.FixtureUserData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2FixtureUserData_get_pointer(lua_State *L)
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

static int _b2FixtureUserData_set_pointer(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2FixtureUserData(lua_State *L)
{
    oluacls_class<b2FixtureUserData>(L, "b2.FixtureUserData");
    oluacls_func(L, "__gc", _b2FixtureUserData___gc);
    oluacls_func(L, "__olua_move", _b2FixtureUserData___olua_move);
    oluacls_func(L, "new", _b2FixtureUserData_new);
    oluacls_prop(L, "pointer", _b2FixtureUserData_get_pointer, _b2FixtureUserData_set_pointer);

    return 1;
}
OLUA_END_DECLS

static int _b2Filter___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Filter *)olua_toobj(L, 1, "b2.Filter");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2Filter___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Filter *)olua_toobj(L, 1, "b2.Filter");
    olua_push_object(L, self, "b2.Filter");

    olua_endinvoke(L);

    return 1;
}

static int _b2Filter_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2Filter()
    b2Filter *ret = new b2Filter();
    int num_ret = olua_push_object(L, ret, "b2.Filter");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Filter_get_categoryBits(lua_State *L)
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

static int _b2Filter_set_categoryBits(lua_State *L)
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

static int _b2Filter_get_groupIndex(lua_State *L)
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

static int _b2Filter_set_groupIndex(lua_State *L)
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

static int _b2Filter_get_maskBits(lua_State *L)
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

static int _b2Filter_set_maskBits(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2Filter(lua_State *L)
{
    oluacls_class<b2Filter>(L, "b2.Filter");
    oluacls_func(L, "__gc", _b2Filter___gc);
    oluacls_func(L, "__olua_move", _b2Filter___olua_move);
    oluacls_func(L, "new", _b2Filter_new);
    oluacls_prop(L, "categoryBits", _b2Filter_get_categoryBits, _b2Filter_set_categoryBits);
    oluacls_prop(L, "groupIndex", _b2Filter_get_groupIndex, _b2Filter_set_groupIndex);
    oluacls_prop(L, "maskBits", _b2Filter_get_maskBits, _b2Filter_set_maskBits);

    return 1;
}
OLUA_END_DECLS

static int _b2ManifoldPoint___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ManifoldPoint *)olua_toobj(L, 1, "b2.ManifoldPoint");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2ManifoldPoint___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ManifoldPoint *)olua_toobj(L, 1, "b2.ManifoldPoint");
    olua_push_object(L, self, "b2.ManifoldPoint");

    olua_endinvoke(L);

    return 1;
}

static int _b2ManifoldPoint_get_id(lua_State *L)
{
    olua_startinvoke(L);

    b2ManifoldPoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ManifoldPoint");

    // b2ContactID id
    b2ContactID &ret = self->id;
    int num_ret = olua_pushcopy_object(L, ret, "b2.ContactID");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2ManifoldPoint_set_id(lua_State *L)
{
    olua_startinvoke(L);

    b2ManifoldPoint *self = nullptr;
    b2ContactID arg1;       /** id */

    olua_to_object(L, 1, &self, "b2.ManifoldPoint");
    olua_check_object(L, 2, &arg1, "b2.ContactID");

    // b2ContactID id
    self->id = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2ManifoldPoint_get_localPoint(lua_State *L)
{
    olua_startinvoke(L);

    b2ManifoldPoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ManifoldPoint");

    // b2Vec2 localPoint
    b2Vec2 &ret = self->localPoint;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2ManifoldPoint_set_localPoint(lua_State *L)
{
    olua_startinvoke(L);

    b2ManifoldPoint *self = nullptr;
    b2Vec2 arg1;       /** localPoint */

    olua_to_object(L, 1, &self, "b2.ManifoldPoint");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localPoint
    self->localPoint = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2ManifoldPoint_get_normalImpulse(lua_State *L)
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

static int _b2ManifoldPoint_set_normalImpulse(lua_State *L)
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

static int _b2ManifoldPoint_get_tangentImpulse(lua_State *L)
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

static int _b2ManifoldPoint_set_tangentImpulse(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2ManifoldPoint(lua_State *L)
{
    oluacls_class<b2ManifoldPoint>(L, "b2.ManifoldPoint");
    oluacls_func(L, "__gc", _b2ManifoldPoint___gc);
    oluacls_func(L, "__olua_move", _b2ManifoldPoint___olua_move);
    oluacls_prop(L, "id", _b2ManifoldPoint_get_id, _b2ManifoldPoint_set_id);
    oluacls_prop(L, "localPoint", _b2ManifoldPoint_get_localPoint, _b2ManifoldPoint_set_localPoint);
    oluacls_prop(L, "normalImpulse", _b2ManifoldPoint_get_normalImpulse, _b2ManifoldPoint_set_normalImpulse);
    oluacls_prop(L, "tangentImpulse", _b2ManifoldPoint_get_tangentImpulse, _b2ManifoldPoint_set_tangentImpulse);

    return 1;
}
OLUA_END_DECLS

static int _b2Rot___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Rot *)olua_toobj(L, 1, "b2.Rot");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2Rot___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Rot *)olua_toobj(L, 1, "b2.Rot");
    olua_push_object(L, self, "b2.Rot");

    olua_endinvoke(L);

    return 1;
}

static int _b2Rot_GetAngle(lua_State *L)
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

static int _b2Rot_GetXAxis(lua_State *L)
{
    olua_startinvoke(L);

    b2Rot *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Rot");

    // b2Vec2 GetXAxis()
    b2Vec2 ret = self->GetXAxis();
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Rot_GetYAxis(lua_State *L)
{
    olua_startinvoke(L);

    b2Rot *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Rot");

    // b2Vec2 GetYAxis()
    b2Vec2 ret = self->GetYAxis();
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Rot_new$1(lua_State *L)
{
    olua_startinvoke(L);

    // b2Rot()
    b2Rot *ret = new b2Rot();
    int num_ret = olua_push_object(L, ret, "b2.Rot");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Rot_new$2(lua_State *L)
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

static int _b2Rot_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // b2Rot()
        return _b2Rot_new$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_number(L, 1))) {
            // b2Rot(float angle)
            return _b2Rot_new$2(L);
        // }
    }

    luaL_error(L, "method 'b2Rot::new' not support '%d' arguments", num_args);

    return 0;
}

static int _b2Rot_Set(lua_State *L)
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

static int _b2Rot_SetIdentity(lua_State *L)
{
    olua_startinvoke(L);

    b2Rot *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Rot");

    // void SetIdentity()
    self->SetIdentity();

    olua_endinvoke(L);

    return 0;
}

static int _b2Rot_get_c(lua_State *L)
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

static int _b2Rot_set_c(lua_State *L)
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

static int _b2Rot_get_s(lua_State *L)
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

static int _b2Rot_set_s(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2Rot(lua_State *L)
{
    oluacls_class<b2Rot>(L, "b2.Rot");
    oluacls_func(L, "__gc", _b2Rot___gc);
    oluacls_func(L, "__olua_move", _b2Rot___olua_move);
    oluacls_func(L, "getAngle", _b2Rot_GetAngle);
    oluacls_func(L, "getXAxis", _b2Rot_GetXAxis);
    oluacls_func(L, "getYAxis", _b2Rot_GetYAxis);
    oluacls_func(L, "new", _b2Rot_new);
    oluacls_func(L, "set", _b2Rot_Set);
    oluacls_func(L, "setIdentity", _b2Rot_SetIdentity);
    oluacls_prop(L, "angle", _b2Rot_GetAngle, nullptr);
    oluacls_prop(L, "xAxis", _b2Rot_GetXAxis, nullptr);
    oluacls_prop(L, "yAxis", _b2Rot_GetYAxis, nullptr);
    oluacls_prop(L, "c", _b2Rot_get_c, _b2Rot_set_c);
    oluacls_prop(L, "s", _b2Rot_get_s, _b2Rot_set_s);

    return 1;
}
OLUA_END_DECLS

static int _b2Draw___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Draw *)olua_toobj(L, 1, "b2.interface.Draw");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2Draw___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Draw *)olua_toobj(L, 1, "b2.interface.Draw");
    olua_push_object(L, self, "b2.interface.Draw");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2Draw(lua_State *L)
{
    oluacls_class<b2Draw>(L, "b2.interface.Draw");
    oluacls_func(L, "__gc", _b2Draw___gc);
    oluacls_func(L, "__olua_move", _b2Draw___olua_move);

    return 1;
}
OLUA_END_DECLS

static int _b2DestructionListener___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2DestructionListener *)olua_toobj(L, 1, "b2.interface.DestructionListener");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2DestructionListener___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2DestructionListener *)olua_toobj(L, 1, "b2.interface.DestructionListener");
    olua_push_object(L, self, "b2.interface.DestructionListener");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2DestructionListener(lua_State *L)
{
    oluacls_class<b2DestructionListener>(L, "b2.interface.DestructionListener");
    oluacls_func(L, "__gc", _b2DestructionListener___gc);
    oluacls_func(L, "__olua_move", _b2DestructionListener___olua_move);

    return 1;
}
OLUA_END_DECLS

static int _b2ContactFilter___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ContactFilter *)olua_toobj(L, 1, "b2.interface.ContactFilter");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2ContactFilter___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ContactFilter *)olua_toobj(L, 1, "b2.interface.ContactFilter");
    olua_push_object(L, self, "b2.interface.ContactFilter");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2ContactFilter(lua_State *L)
{
    oluacls_class<b2ContactFilter>(L, "b2.interface.ContactFilter");
    oluacls_func(L, "__gc", _b2ContactFilter___gc);
    oluacls_func(L, "__olua_move", _b2ContactFilter___olua_move);

    return 1;
}
OLUA_END_DECLS

static int _b2ContactListener___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ContactListener *)olua_toobj(L, 1, "b2.interface.ContactListener");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2ContactListener___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ContactListener *)olua_toobj(L, 1, "b2.interface.ContactListener");
    olua_push_object(L, self, "b2.interface.ContactListener");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2ContactListener(lua_State *L)
{
    oluacls_class<b2ContactListener>(L, "b2.interface.ContactListener");
    oluacls_func(L, "__gc", _b2ContactListener___gc);
    oluacls_func(L, "__olua_move", _b2ContactListener___olua_move);

    return 1;
}
OLUA_END_DECLS

static int _b2QueryCallback___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2QueryCallback *)olua_toobj(L, 1, "b2.interface.QueryCallback");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2QueryCallback___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2QueryCallback *)olua_toobj(L, 1, "b2.interface.QueryCallback");
    olua_push_object(L, self, "b2.interface.QueryCallback");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2QueryCallback(lua_State *L)
{
    oluacls_class<b2QueryCallback>(L, "b2.interface.QueryCallback");
    oluacls_func(L, "__gc", _b2QueryCallback___gc);
    oluacls_func(L, "__olua_move", _b2QueryCallback___olua_move);

    return 1;
}
OLUA_END_DECLS

static int _b2RayCastCallback___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2RayCastCallback *)olua_toobj(L, 1, "b2.interface.RayCastCallback");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2RayCastCallback___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2RayCastCallback *)olua_toobj(L, 1, "b2.interface.RayCastCallback");
    olua_push_object(L, self, "b2.interface.RayCastCallback");

    olua_endinvoke(L);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2RayCastCallback(lua_State *L)
{
    oluacls_class<b2RayCastCallback>(L, "b2.interface.RayCastCallback");
    oluacls_func(L, "__gc", _b2RayCastCallback___gc);
    oluacls_func(L, "__olua_move", _b2RayCastCallback___olua_move);

    return 1;
}
OLUA_END_DECLS

static int _box2d_Vec2Array___gc(lua_State *L)
{
    olua_startinvoke(L);

    box2d::Vec2Array *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Vec2Array");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _box2d_Vec2Array___index(lua_State *L)
{
    olua_startinvoke(L);

    box2d::Vec2Array *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "b2.Vec2Array");
    olua_check_integer(L, 2, &arg1);

    // b2Vec2 __index(unsigned int idx)
    b2Vec2 ret = self->__index(arg1);
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_Vec2Array___newindex(lua_State *L)
{
    olua_startinvoke(L);

    box2d::Vec2Array *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    b2Vec2 arg2;       /** v */

    olua_to_object(L, 1, &self, "b2.Vec2Array");
    olua_check_integer(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "b2.Vec2");

    // void __newindex(unsigned int idx, const b2Vec2 &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _box2d_Vec2Array___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (box2d::Vec2Array *)olua_toobj(L, 1, "b2.Vec2Array");
    olua_push_object(L, self, "b2.Vec2Array");

    olua_endinvoke(L);

    return 1;
}

static int _box2d_Vec2Array_create$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // @postnew @name(new) static box2d::Vec2Array *create(@optional size_t len)
    box2d::Vec2Array *ret = box2d::Vec2Array::create(arg1);
    int num_ret = olua_push_object(L, ret, "b2.Vec2Array");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_Vec2Array_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @postnew @name(new) static box2d::Vec2Array *create(@optional size_t len)
    box2d::Vec2Array *ret = box2d::Vec2Array::create();
    int num_ret = olua_push_object(L, ret, "b2.Vec2Array");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_Vec2Array_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @postnew @name(new) static box2d::Vec2Array *create(@optional size_t len)
        return _box2d_Vec2Array_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 1))) {
            // @postnew @name(new) static box2d::Vec2Array *create(@optional size_t len)
            return _box2d_Vec2Array_create$1(L);
        // }
    }

    luaL_error(L, "method 'box2d::Vec2Array::create' not support '%d' arguments", num_args);

    return 0;
}

static int _box2d_Vec2Array_setstring(lua_State *L)
{
    olua_startinvoke(L);

    box2d::Vec2Array *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "b2.Vec2Array");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setstring(const char *data, size_t len)
    self->setstring(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _box2d_Vec2Array_sub$1(lua_State *L)
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

static int _box2d_Vec2Array_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    box2d::Vec2Array *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "b2.Vec2Array");
    olua_check_integer(L, 2, &arg1);

    // @postnew box2d::Vec2Array *sub(size_t from, @optional size_t to)
    box2d::Vec2Array *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "b2.Vec2Array");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_Vec2Array_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // @postnew box2d::Vec2Array *sub(size_t from, @optional size_t to)
            return _box2d_Vec2Array_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew box2d::Vec2Array *sub(size_t from, @optional size_t to)
            return _box2d_Vec2Array_sub$1(L);
        // }
    }

    luaL_error(L, "method 'box2d::Vec2Array::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _box2d_Vec2Array_take(lua_State *L)
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

static int _box2d_Vec2Array_tostring(lua_State *L)
{
    olua_startinvoke(L);

    box2d::Vec2Array *self = nullptr;
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "b2.Vec2Array");
    olua_check_integer(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _box2d_Vec2Array_data(lua_State *L)
{
    olua_startinvoke(L);

    box2d::Vec2Array *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Vec2Array");

    // @getter @name(data) b2Vec2 *data()
    b2Vec2 *ret = self->data();
    int num_ret = olua_push_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_Vec2Array_length(lua_State *L)
{
    olua_startinvoke(L);

    box2d::Vec2Array *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Vec2Array");

    // @getter @name(length) size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_Vec2Array_rawdata(lua_State *L)
{
    olua_startinvoke(L);

    box2d::Vec2Array *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Vec2Array");

    // @getter @name(rawdata) void *rawdata()
    void *ret = self->rawdata();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_Vec2Array_size(lua_State *L)
{
    olua_startinvoke(L);

    box2d::Vec2Array *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Vec2Array");

    // @getter @name(sizeof) size_t size()
    size_t ret = self->size();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_Vec2Array_value(lua_State *L)
{
    olua_startinvoke(L);

    box2d::Vec2Array *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Vec2Array");

    // @getter @name(value) const b2Vec2 &value()
    const b2Vec2 &ret = self->value();
    int num_ret = olua_push_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_box2d_Vec2Array(lua_State *L)
{
    oluacls_class<box2d::Vec2Array>(L, "b2.Vec2Array");
    oluacls_func(L, "__gc", _box2d_Vec2Array___gc);
    oluacls_func(L, "__index", _box2d_Vec2Array___index);
    oluacls_func(L, "__newindex", _box2d_Vec2Array___newindex);
    oluacls_func(L, "__olua_move", _box2d_Vec2Array___olua_move);
    oluacls_func(L, "new", _box2d_Vec2Array_create);
    oluacls_func(L, "setstring", _box2d_Vec2Array_setstring);
    oluacls_func(L, "sub", _box2d_Vec2Array_sub);
    oluacls_func(L, "take", _box2d_Vec2Array_take);
    oluacls_func(L, "tostring", _box2d_Vec2Array_tostring);
    oluacls_prop(L, "data", _box2d_Vec2Array_data, nullptr);
    oluacls_prop(L, "length", _box2d_Vec2Array_length, _box2d_Vec2Array_length);
    oluacls_prop(L, "rawdata", _box2d_Vec2Array_rawdata, nullptr);
    oluacls_prop(L, "sizeof", _box2d_Vec2Array_size, nullptr);
    oluacls_prop(L, "value", _box2d_Vec2Array_value, _box2d_Vec2Array_value);

    return 1;
}
OLUA_END_DECLS

static int _box2d_DestructionListener_new(lua_State *L)
{
    olua_startinvoke(L);

    // DestructionListener()
    box2d::DestructionListener *ret = new box2d::DestructionListener();
    int num_ret = olua_push_object(L, ret, "b2.DestructionListener");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_DestructionListener_get_sayGoodbyeToFixture(lua_State *L)
{
    olua_startinvoke(L);

    box2d::DestructionListener *self = nullptr;

    olua_to_object(L, 1, &self, "b2.DestructionListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "sayGoodbyeToFixture";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // @nullable @localvar std::function<void (b2Fixture *)> sayGoodbyeToFixture
    std::function<void (b2Fixture *)> ret = self->sayGoodbyeToFixture;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_DestructionListener_set_sayGoodbyeToFixture(lua_State *L)
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
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](b2Fixture *arg1) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_object(L, arg1, "b2.Fixture");
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

    // @nullable @localvar std::function<void (b2Fixture *)> sayGoodbyeToFixture
    self->sayGoodbyeToFixture = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _box2d_DestructionListener_get_sayGoodbyeToJoint(lua_State *L)
{
    olua_startinvoke(L);

    box2d::DestructionListener *self = nullptr;

    olua_to_object(L, 1, &self, "b2.DestructionListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "sayGoodbyeToJoint";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // @nullable @localvar std::function<void (b2Joint *)> sayGoodbyeToJoint
    std::function<void (b2Joint *)> ret = self->sayGoodbyeToJoint;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_DestructionListener_set_sayGoodbyeToJoint(lua_State *L)
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
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](b2Joint *arg1) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_object(L, arg1, "b2.Joint");
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

    // @nullable @localvar std::function<void (b2Joint *)> sayGoodbyeToJoint
    self->sayGoodbyeToJoint = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_box2d_DestructionListener(lua_State *L)
{
    oluacls_class<box2d::DestructionListener, b2DestructionListener>(L, "b2.DestructionListener");
    oluacls_func(L, "new", _box2d_DestructionListener_new);
    oluacls_prop(L, "sayGoodbyeToFixture", _box2d_DestructionListener_get_sayGoodbyeToFixture, _box2d_DestructionListener_set_sayGoodbyeToFixture);
    oluacls_prop(L, "sayGoodbyeToJoint", _box2d_DestructionListener_get_sayGoodbyeToJoint, _box2d_DestructionListener_set_sayGoodbyeToJoint);

    return 1;
}
OLUA_END_DECLS

static int _box2d_ContactFilter_new(lua_State *L)
{
    olua_startinvoke(L);

    // ContactFilter()
    box2d::ContactFilter *ret = new box2d::ContactFilter();
    int num_ret = olua_push_object(L, ret, "b2.ContactFilter");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_ContactFilter_get_shouldCollide(lua_State *L)
{
    olua_startinvoke(L);

    box2d::ContactFilter *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ContactFilter");

    void *cb_store = (void *)self;
    std::string cb_tag = "shouldCollide";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // @nullable @localvar std::function<bool (b2Fixture *, b2Fixture *)> shouldCollide
    std::function<bool (b2Fixture *, b2Fixture *)> ret = self->shouldCollide;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_ContactFilter_set_shouldCollide(lua_State *L)
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
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](b2Fixture *arg1, b2Fixture *arg2) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();
            bool ret = false;       /** ret */
            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_object(L, arg1, "b2.Fixture");
                olua_push_object(L, arg2, "b2.Fixture");
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

    // @nullable @localvar std::function<bool (b2Fixture *, b2Fixture *)> shouldCollide
    self->shouldCollide = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_box2d_ContactFilter(lua_State *L)
{
    oluacls_class<box2d::ContactFilter, b2ContactFilter>(L, "b2.ContactFilter");
    oluacls_func(L, "new", _box2d_ContactFilter_new);
    oluacls_prop(L, "shouldCollide", _box2d_ContactFilter_get_shouldCollide, _box2d_ContactFilter_set_shouldCollide);

    return 1;
}
OLUA_END_DECLS

static int _box2d_ContactListener_new(lua_State *L)
{
    olua_startinvoke(L);

    // ContactListener()
    box2d::ContactListener *ret = new box2d::ContactListener();
    int num_ret = olua_push_object(L, ret, "b2.ContactListener");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_ContactListener_get_beginContact(lua_State *L)
{
    olua_startinvoke(L);

    box2d::ContactListener *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ContactListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "beginContact";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // @nullable @localvar std::function<void (b2Contact *)> beginContact
    std::function<void (b2Contact *)> ret = self->beginContact;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_ContactListener_set_beginContact(lua_State *L)
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
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](b2Contact *arg1) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_object(L, arg1, "b2.Contact");
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

    // @nullable @localvar std::function<void (b2Contact *)> beginContact
    self->beginContact = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _box2d_ContactListener_get_endContact(lua_State *L)
{
    olua_startinvoke(L);

    box2d::ContactListener *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ContactListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "endContact";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // @nullable @localvar std::function<void (b2Contact *)> endContact
    std::function<void (b2Contact *)> ret = self->endContact;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_ContactListener_set_endContact(lua_State *L)
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
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](b2Contact *arg1) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_object(L, arg1, "b2.Contact");
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

    // @nullable @localvar std::function<void (b2Contact *)> endContact
    self->endContact = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _box2d_ContactListener_get_postSolve(lua_State *L)
{
    olua_startinvoke(L);

    box2d::ContactListener *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ContactListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "postSolve";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // @nullable @localvar std::function<void (b2Contact *, const b2ContactImpulse *)> postSolve
    std::function<void (b2Contact *, const b2ContactImpulse *)> ret = self->postSolve;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_ContactListener_set_postSolve(lua_State *L)
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
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](b2Contact *arg1, const b2ContactImpulse *arg2) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_object(L, arg1, "b2.Contact");
                olua_push_object(L, arg2, "b2.ContactImpulse");
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

    // @nullable @localvar std::function<void (b2Contact *, const b2ContactImpulse *)> postSolve
    self->postSolve = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _box2d_ContactListener_get_preSolve(lua_State *L)
{
    olua_startinvoke(L);

    box2d::ContactListener *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ContactListener");

    void *cb_store = (void *)self;
    std::string cb_tag = "preSolve";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // @nullable @localvar std::function<void (b2Contact *, const b2Manifold *)> preSolve
    std::function<void (b2Contact *, const b2Manifold *)> ret = self->preSolve;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_ContactListener_set_preSolve(lua_State *L)
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
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](b2Contact *arg1, const b2Manifold *arg2) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_object(L, arg1, "b2.Contact");
                olua_push_object(L, arg2, "b2.Manifold");
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

    // @nullable @localvar std::function<void (b2Contact *, const b2Manifold *)> preSolve
    self->preSolve = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_box2d_ContactListener(lua_State *L)
{
    oluacls_class<box2d::ContactListener, b2ContactListener>(L, "b2.ContactListener");
    oluacls_func(L, "new", _box2d_ContactListener_new);
    oluacls_prop(L, "beginContact", _box2d_ContactListener_get_beginContact, _box2d_ContactListener_set_beginContact);
    oluacls_prop(L, "endContact", _box2d_ContactListener_get_endContact, _box2d_ContactListener_set_endContact);
    oluacls_prop(L, "postSolve", _box2d_ContactListener_get_postSolve, _box2d_ContactListener_set_postSolve);
    oluacls_prop(L, "preSolve", _box2d_ContactListener_get_preSolve, _box2d_ContactListener_set_preSolve);

    return 1;
}
OLUA_END_DECLS

static int _box2d_QueryCallback_new(lua_State *L)
{
    olua_startinvoke(L);

    // QueryCallback()
    box2d::QueryCallback *ret = new box2d::QueryCallback();
    int num_ret = olua_push_object(L, ret, "b2.QueryCallback");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_QueryCallback_get_reportFixture(lua_State *L)
{
    olua_startinvoke(L);

    box2d::QueryCallback *self = nullptr;

    olua_to_object(L, 1, &self, "b2.QueryCallback");

    void *cb_store = (void *)self;
    std::string cb_tag = "reportFixture";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // @nullable @localvar std::function<bool (b2Fixture *)> reportFixture
    std::function<bool (b2Fixture *)> ret = self->reportFixture;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_QueryCallback_set_reportFixture(lua_State *L)
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
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](b2Fixture *arg1) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();
            bool ret = false;       /** ret */
            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_object(L, arg1, "b2.Fixture");
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

    // @nullable @localvar std::function<bool (b2Fixture *)> reportFixture
    self->reportFixture = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_box2d_QueryCallback(lua_State *L)
{
    oluacls_class<box2d::QueryCallback, b2QueryCallback>(L, "b2.QueryCallback");
    oluacls_func(L, "new", _box2d_QueryCallback_new);
    oluacls_prop(L, "reportFixture", _box2d_QueryCallback_get_reportFixture, _box2d_QueryCallback_set_reportFixture);

    return 1;
}
OLUA_END_DECLS

static int _box2d_RayCastCallback_new(lua_State *L)
{
    olua_startinvoke(L);

    // RayCastCallback()
    box2d::RayCastCallback *ret = new box2d::RayCastCallback();
    int num_ret = olua_push_object(L, ret, "b2.RayCastCallback");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_RayCastCallback_get_reportFixture(lua_State *L)
{
    olua_startinvoke(L);

    box2d::RayCastCallback *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RayCastCallback");

    void *cb_store = (void *)self;
    std::string cb_tag = "reportFixture";
    olua_getcallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // @nullable @localvar std::function<float (b2Fixture *, const b2Vec2 &, const b2Vec2 &, float)> reportFixture
    std::function<float (b2Fixture *, const b2Vec2 &, const b2Vec2 &, float)> ret = self->reportFixture;
    int num_ret = olua_push_callback(L, &ret, "std.function");

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_RayCastCallback_set_reportFixture(lua_State *L)
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
        cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_REPLACE);
        olua_Context cb_ctx = olua_context(L);
        arg1 = [cb_store, cb_name, cb_ctx](b2Fixture *arg1, const b2Vec2 &arg2, const b2Vec2 &arg3, float arg4) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();
            float ret = 0;       /** ret */
            if (olua_contextequal(L, cb_ctx)) {
                int top = lua_gettop(L);
                size_t last = olua_push_objpool(L);
                olua_enable_objpool(L);
                olua_push_object(L, arg1, "b2.Fixture");
                olua_push_object(L, arg2, "b2.Vec2");
                olua_push_object(L, arg3, "b2.Vec2");
                olua_push_number(L, arg4);
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

    // @nullable @localvar std::function<float (b2Fixture *, const b2Vec2 &, const b2Vec2 &, float)> reportFixture
    self->reportFixture = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_box2d_RayCastCallback(lua_State *L)
{
    oluacls_class<box2d::RayCastCallback, b2RayCastCallback>(L, "b2.RayCastCallback");
    oluacls_func(L, "new", _box2d_RayCastCallback_new);
    oluacls_prop(L, "reportFixture", _box2d_RayCastCallback_get_reportFixture, _box2d_RayCastCallback_set_reportFixture);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_box2d_DebugNode_Flags(lua_State *L)
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
OLUA_END_DECLS

static int _box2d_DebugNode_appendFlags(lua_State *L)
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

static int _box2d_DebugNode_as(lua_State *L)
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

static int _box2d_DebugNode_clearFlags(lua_State *L)
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

static int _box2d_DebugNode_create(lua_State *L)
{
    olua_startinvoke(L);

    b2World *arg1 = nullptr;       /** world */

    olua_check_object(L, 1, &arg1, "b2.World");

    // static box2d::DebugNode *create(@addref(world ^) b2World *world)
    box2d::DebugNode *ret = box2d::DebugNode::create(arg1);
    int num_ret = olua_push_object(L, ret, "b2.DebugNode");

    // insert code after call
    olua_addref(L, -1, "world", 1, OLUA_FLAG_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _box2d_DebugNode_getFlags(lua_State *L)
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

static int _box2d_DebugNode_setFlags(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_box2d_DebugNode(lua_State *L)
{
    oluacls_class<box2d::DebugNode, cocos2d::DrawNode>(L, "b2.DebugNode");
    oluacls_func(L, "appendFlags", _box2d_DebugNode_appendFlags);
    oluacls_func(L, "as", _box2d_DebugNode_as);
    oluacls_func(L, "clearFlags", _box2d_DebugNode_clearFlags);
    oluacls_func(L, "create", _box2d_DebugNode_create);
    oluacls_func(L, "getFlags", _box2d_DebugNode_getFlags);
    oluacls_func(L, "setFlags", _box2d_DebugNode_setFlags);
    oluacls_prop(L, "flags", _box2d_DebugNode_getFlags, _box2d_DebugNode_setFlags);

    return 1;
}
OLUA_END_DECLS

static int _b2MassData___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2MassData *)olua_toobj(L, 1, "b2.MassData");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2MassData___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2MassData *)olua_toobj(L, 1, "b2.MassData");
    olua_push_object(L, self, "b2.MassData");

    olua_endinvoke(L);

    return 1;
}

static int _b2MassData_get_I(lua_State *L)
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

static int _b2MassData_set_I(lua_State *L)
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

static int _b2MassData_get_center(lua_State *L)
{
    olua_startinvoke(L);

    b2MassData *self = nullptr;

    olua_to_object(L, 1, &self, "b2.MassData");

    // b2Vec2 center
    b2Vec2 &ret = self->center;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2MassData_set_center(lua_State *L)
{
    olua_startinvoke(L);

    b2MassData *self = nullptr;
    b2Vec2 arg1;       /** center */

    olua_to_object(L, 1, &self, "b2.MassData");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 center
    self->center = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2MassData_get_mass(lua_State *L)
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

static int _b2MassData_set_mass(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2MassData(lua_State *L)
{
    oluacls_class<b2MassData>(L, "b2.MassData");
    oluacls_func(L, "__gc", _b2MassData___gc);
    oluacls_func(L, "__olua_move", _b2MassData___olua_move);
    oluacls_prop(L, "I", _b2MassData_get_I, _b2MassData_set_I);
    oluacls_prop(L, "center", _b2MassData_get_center, _b2MassData_set_center);
    oluacls_prop(L, "mass", _b2MassData_get_mass, _b2MassData_set_mass);

    return 1;
}
OLUA_END_DECLS

static int _b2Transform___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Transform *)olua_toobj(L, 1, "b2.Transform");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2Transform___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Transform *)olua_toobj(L, 1, "b2.Transform");
    olua_push_object(L, self, "b2.Transform");

    olua_endinvoke(L);

    return 1;
}

static int _b2Transform_new$1(lua_State *L)
{
    olua_startinvoke(L);

    // b2Transform()
    b2Transform *ret = new b2Transform();
    int num_ret = olua_push_object(L, ret, "b2.Transform");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Transform_new$2(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec2 arg1;       /** position */
    b2Rot arg2;       /** rotation */

    olua_check_object(L, 1, &arg1, "b2.Vec2");
    olua_check_object(L, 2, &arg2, "b2.Rot");

    // b2Transform(const b2Vec2 &position, const b2Rot &rotation)
    b2Transform *ret = new b2Transform(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "b2.Transform");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Transform_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // b2Transform()
        return _b2Transform_new$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "b2.Vec2")) && (olua_is_object(L, 2, "b2.Rot"))) {
            // b2Transform(const b2Vec2 &position, const b2Rot &rotation)
            return _b2Transform_new$2(L);
        // }
    }

    luaL_error(L, "method 'b2Transform::new' not support '%d' arguments", num_args);

    return 0;
}

static int _b2Transform_Set(lua_State *L)
{
    olua_startinvoke(L);

    b2Transform *self = nullptr;
    b2Vec2 arg1;       /** position */
    float arg2 = 0;       /** angle */

    olua_to_object(L, 1, &self, "b2.Transform");
    olua_check_object(L, 2, &arg1, "b2.Vec2");
    olua_check_number(L, 3, &arg2);

    // void Set(const b2Vec2 &position, float angle)
    self->Set(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _b2Transform_SetIdentity(lua_State *L)
{
    olua_startinvoke(L);

    b2Transform *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Transform");

    // void SetIdentity()
    self->SetIdentity();

    olua_endinvoke(L);

    return 0;
}

static int _b2Transform_get_p(lua_State *L)
{
    olua_startinvoke(L);

    b2Transform *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Transform");

    // b2Vec2 p
    b2Vec2 &ret = self->p;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Transform_set_p(lua_State *L)
{
    olua_startinvoke(L);

    b2Transform *self = nullptr;
    b2Vec2 arg1;       /** p */

    olua_to_object(L, 1, &self, "b2.Transform");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 p
    self->p = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2Transform_get_q(lua_State *L)
{
    olua_startinvoke(L);

    b2Transform *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Transform");

    // b2Rot q
    b2Rot &ret = self->q;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Rot");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Transform_set_q(lua_State *L)
{
    olua_startinvoke(L);

    b2Transform *self = nullptr;
    b2Rot arg1;       /** q */

    olua_to_object(L, 1, &self, "b2.Transform");
    olua_check_object(L, 2, &arg1, "b2.Rot");

    // b2Rot q
    self->q = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2Transform(lua_State *L)
{
    oluacls_class<b2Transform>(L, "b2.Transform");
    oluacls_func(L, "__gc", _b2Transform___gc);
    oluacls_func(L, "__olua_move", _b2Transform___olua_move);
    oluacls_func(L, "new", _b2Transform_new);
    oluacls_func(L, "set", _b2Transform_Set);
    oluacls_func(L, "setIdentity", _b2Transform_SetIdentity);
    oluacls_prop(L, "p", _b2Transform_get_p, _b2Transform_set_p);
    oluacls_prop(L, "q", _b2Transform_get_q, _b2Transform_set_q);

    return 1;
}
OLUA_END_DECLS

static int _b2RayCastInput___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2RayCastInput *)olua_toobj(L, 1, "b2.RayCastInput");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2RayCastInput___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2RayCastInput *)olua_toobj(L, 1, "b2.RayCastInput");
    olua_push_object(L, self, "b2.RayCastInput");

    olua_endinvoke(L);

    return 1;
}

static int _b2RayCastInput_get_maxFraction(lua_State *L)
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

static int _b2RayCastInput_set_maxFraction(lua_State *L)
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

static int _b2RayCastInput_get_p1(lua_State *L)
{
    olua_startinvoke(L);

    b2RayCastInput *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RayCastInput");

    // b2Vec2 p1
    b2Vec2 &ret = self->p1;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RayCastInput_set_p1(lua_State *L)
{
    olua_startinvoke(L);

    b2RayCastInput *self = nullptr;
    b2Vec2 arg1;       /** p1 */

    olua_to_object(L, 1, &self, "b2.RayCastInput");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 p1
    self->p1 = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2RayCastInput_get_p2(lua_State *L)
{
    olua_startinvoke(L);

    b2RayCastInput *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RayCastInput");

    // b2Vec2 p2
    b2Vec2 &ret = self->p2;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RayCastInput_set_p2(lua_State *L)
{
    olua_startinvoke(L);

    b2RayCastInput *self = nullptr;
    b2Vec2 arg1;       /** p2 */

    olua_to_object(L, 1, &self, "b2.RayCastInput");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 p2
    self->p2 = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2RayCastInput(lua_State *L)
{
    oluacls_class<b2RayCastInput>(L, "b2.RayCastInput");
    oluacls_func(L, "__gc", _b2RayCastInput___gc);
    oluacls_func(L, "__olua_move", _b2RayCastInput___olua_move);
    oluacls_prop(L, "maxFraction", _b2RayCastInput_get_maxFraction, _b2RayCastInput_set_maxFraction);
    oluacls_prop(L, "p1", _b2RayCastInput_get_p1, _b2RayCastInput_set_p1);
    oluacls_prop(L, "p2", _b2RayCastInput_get_p2, _b2RayCastInput_set_p2);

    return 1;
}
OLUA_END_DECLS

static int _b2RayCastOutput___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2RayCastOutput *)olua_toobj(L, 1, "b2.RayCastOutput");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2RayCastOutput___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2RayCastOutput *)olua_toobj(L, 1, "b2.RayCastOutput");
    olua_push_object(L, self, "b2.RayCastOutput");

    olua_endinvoke(L);

    return 1;
}

static int _b2RayCastOutput_get_fraction(lua_State *L)
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

static int _b2RayCastOutput_set_fraction(lua_State *L)
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

static int _b2RayCastOutput_get_normal(lua_State *L)
{
    olua_startinvoke(L);

    b2RayCastOutput *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RayCastOutput");

    // b2Vec2 normal
    b2Vec2 &ret = self->normal;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RayCastOutput_set_normal(lua_State *L)
{
    olua_startinvoke(L);

    b2RayCastOutput *self = nullptr;
    b2Vec2 arg1;       /** normal */

    olua_to_object(L, 1, &self, "b2.RayCastOutput");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 normal
    self->normal = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2RayCastOutput(lua_State *L)
{
    oluacls_class<b2RayCastOutput>(L, "b2.RayCastOutput");
    oluacls_func(L, "__gc", _b2RayCastOutput___gc);
    oluacls_func(L, "__olua_move", _b2RayCastOutput___olua_move);
    oluacls_prop(L, "fraction", _b2RayCastOutput_get_fraction, _b2RayCastOutput_set_fraction);
    oluacls_prop(L, "normal", _b2RayCastOutput_get_normal, _b2RayCastOutput_set_normal);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2Shape_Type(lua_State *L)
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
OLUA_END_DECLS

static int _b2Shape___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Shape *)olua_toobj(L, 1, "b2.Shape");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2Shape___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Shape *)olua_toobj(L, 1, "b2.Shape");
    olua_push_object(L, self, "b2.Shape");

    olua_endinvoke(L);

    return 1;
}

static int _b2Shape_ComputeAABB(lua_State *L)
{
    olua_startinvoke(L);

    b2Shape *self = nullptr;
    b2AABB *arg1 = nullptr;       /** aabb */
    b2Transform arg2;       /** xf */
    int32 arg3 = 0;       /** childIndex */

    olua_to_object(L, 1, &self, "b2.Shape");
    olua_check_object(L, 2, &arg1, "b2.AABB");
    olua_check_object(L, 3, &arg2, "b2.Transform");
    olua_check_integer(L, 4, &arg3);

    // void ComputeAABB(b2AABB *aabb, const b2Transform &xf, int32 childIndex)
    self->ComputeAABB(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _b2Shape_ComputeMass(lua_State *L)
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

static int _b2Shape_GetChildCount(lua_State *L)
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

static int _b2Shape_GetType(lua_State *L)
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

static int _b2Shape_RayCast(lua_State *L)
{
    olua_startinvoke(L);

    b2Shape *self = nullptr;
    b2RayCastOutput *arg1 = nullptr;       /** output */
    b2RayCastInput arg2;       /** input */
    b2Transform arg3;       /** transform */
    int32 arg4 = 0;       /** childIndex */

    olua_to_object(L, 1, &self, "b2.Shape");
    olua_check_object(L, 2, &arg1, "b2.RayCastOutput");
    olua_check_object(L, 3, &arg2, "b2.RayCastInput");
    olua_check_object(L, 4, &arg3, "b2.Transform");
    olua_check_integer(L, 5, &arg4);

    // bool RayCast(b2RayCastOutput *output, const b2RayCastInput &input, const b2Transform &transform, int32 childIndex)
    bool ret = self->RayCast(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Shape_TestPoint(lua_State *L)
{
    olua_startinvoke(L);

    b2Shape *self = nullptr;
    b2Transform arg1;       /** xf */
    b2Vec2 arg2;       /** p */

    olua_to_object(L, 1, &self, "b2.Shape");
    olua_check_object(L, 2, &arg1, "b2.Transform");
    olua_check_object(L, 3, &arg2, "b2.Vec2");

    // bool TestPoint(const b2Transform &xf, const b2Vec2 &p)
    bool ret = self->TestPoint(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2Shape(lua_State *L)
{
    oluacls_class<b2Shape>(L, "b2.Shape");
    oluacls_func(L, "__gc", _b2Shape___gc);
    oluacls_func(L, "__olua_move", _b2Shape___olua_move);
    oluacls_func(L, "computeAABB", _b2Shape_ComputeAABB);
    oluacls_func(L, "computeMass", _b2Shape_ComputeMass);
    oluacls_func(L, "getChildCount", _b2Shape_GetChildCount);
    oluacls_func(L, "getType", _b2Shape_GetType);
    oluacls_func(L, "rayCast", _b2Shape_RayCast);
    oluacls_func(L, "testPoint", _b2Shape_TestPoint);
    oluacls_prop(L, "childCount", _b2Shape_GetChildCount, nullptr);
    oluacls_prop(L, "type", _b2Shape_GetType, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _b2PolygonShape_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2PolygonShape()
    b2PolygonShape *ret = new b2PolygonShape();
    int num_ret = olua_push_object(L, ret, "b2.PolygonShape");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PolygonShape_Set(lua_State *L)
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

static int _b2PolygonShape_SetAsBox$1(lua_State *L)
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

static int _b2PolygonShape_SetAsBox$2(lua_State *L)
{
    olua_startinvoke(L);

    b2PolygonShape *self = nullptr;
    float arg1 = 0;       /** hx */
    float arg2 = 0;       /** hy */
    b2Vec2 arg3;       /** center */
    float arg4 = 0;       /** angle */

    olua_to_object(L, 1, &self, "b2.PolygonShape");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_object(L, 4, &arg3, "b2.Vec2");
    olua_check_number(L, 5, &arg4);

    // void SetAsBox(float hx, float hy, const b2Vec2 &center, float angle)
    self->SetAsBox(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _b2PolygonShape_SetAsBox(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 2) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // void SetAsBox(float hx, float hy)
            return _b2PolygonShape_SetAsBox$1(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_object(L, 4, "b2.Vec2")) && (olua_is_number(L, 5))) {
            // void SetAsBox(float hx, float hy, const b2Vec2 &center, float angle)
            return _b2PolygonShape_SetAsBox$2(L);
        // }
    }

    luaL_error(L, "method 'b2PolygonShape::SetAsBox' not support '%d' arguments", num_args);

    return 0;
}

static int _b2PolygonShape_Validate(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2PolygonShape(lua_State *L)
{
    oluacls_class<b2PolygonShape, b2Shape>(L, "b2.PolygonShape");
    oluacls_func(L, "new", _b2PolygonShape_new);
    oluacls_func(L, "set", _b2PolygonShape_Set);
    oluacls_func(L, "setAsBox", _b2PolygonShape_SetAsBox);
    oluacls_func(L, "validate", _b2PolygonShape_Validate);

    return 1;
}
OLUA_END_DECLS

static int _b2EdgeShape_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2EdgeShape()
    b2EdgeShape *ret = new b2EdgeShape();
    int num_ret = olua_push_object(L, ret, "b2.EdgeShape");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2EdgeShape_SetOneSided(lua_State *L)
{
    olua_startinvoke(L);

    b2EdgeShape *self = nullptr;
    b2Vec2 arg1;       /** v0 */
    b2Vec2 arg2;       /** v1 */
    b2Vec2 arg3;       /** v2 */
    b2Vec2 arg4;       /** v3 */

    olua_to_object(L, 1, &self, "b2.EdgeShape");
    olua_check_object(L, 2, &arg1, "b2.Vec2");
    olua_check_object(L, 3, &arg2, "b2.Vec2");
    olua_check_object(L, 4, &arg3, "b2.Vec2");
    olua_check_object(L, 5, &arg4, "b2.Vec2");

    // void SetOneSided(const b2Vec2 &v0, const b2Vec2 &v1, const b2Vec2 &v2, const b2Vec2 &v3)
    self->SetOneSided(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _b2EdgeShape_SetTwoSided(lua_State *L)
{
    olua_startinvoke(L);

    b2EdgeShape *self = nullptr;
    b2Vec2 arg1;       /** v1 */
    b2Vec2 arg2;       /** v2 */

    olua_to_object(L, 1, &self, "b2.EdgeShape");
    olua_check_object(L, 2, &arg1, "b2.Vec2");
    olua_check_object(L, 3, &arg2, "b2.Vec2");

    // void SetTwoSided(const b2Vec2 &v1, const b2Vec2 &v2)
    self->SetTwoSided(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2EdgeShape(lua_State *L)
{
    oluacls_class<b2EdgeShape, b2Shape>(L, "b2.EdgeShape");
    oluacls_func(L, "new", _b2EdgeShape_new);
    oluacls_func(L, "setOneSided", _b2EdgeShape_SetOneSided);
    oluacls_func(L, "setTwoSided", _b2EdgeShape_SetTwoSided);

    return 1;
}
OLUA_END_DECLS

static int _b2CircleShape_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2CircleShape()
    b2CircleShape *ret = new b2CircleShape();
    int num_ret = olua_push_object(L, ret, "b2.CircleShape");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2CircleShape(lua_State *L)
{
    oluacls_class<b2CircleShape, b2Shape>(L, "b2.CircleShape");
    oluacls_func(L, "new", _b2CircleShape_new);

    return 1;
}
OLUA_END_DECLS

static int _b2ChainShape_Clear(lua_State *L)
{
    olua_startinvoke(L);

    b2ChainShape *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ChainShape");

    // void Clear()
    self->Clear();

    olua_endinvoke(L);

    return 0;
}

static int _b2ChainShape_CreateChain(lua_State *L)
{
    olua_startinvoke(L);

    b2ChainShape *self = nullptr;
    b2Vec2 *arg1 = nullptr;       /** vertices */
    int32 arg2 = 0;       /** count */
    b2Vec2 arg3;       /** prevVertex */
    b2Vec2 arg4;       /** nextVertex */

    olua_to_object(L, 1, &self, "b2.ChainShape");
    olua_check_object(L, 2, &arg1, "b2.Vec2");
    olua_check_integer(L, 3, &arg2);
    olua_check_object(L, 4, &arg3, "b2.Vec2");
    olua_check_object(L, 5, &arg4, "b2.Vec2");

    // void CreateChain(const b2Vec2 *vertices, int32 count, const b2Vec2 &prevVertex, const b2Vec2 &nextVertex)
    self->CreateChain(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _b2ChainShape_CreateLoop(lua_State *L)
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

static int _b2ChainShape_GetChildEdge(lua_State *L)
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

static int _b2ChainShape_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2ChainShape()
    b2ChainShape *ret = new b2ChainShape();
    int num_ret = olua_push_object(L, ret, "b2.ChainShape");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2ChainShape(lua_State *L)
{
    oluacls_class<b2ChainShape, b2Shape>(L, "b2.ChainShape");
    oluacls_func(L, "clear", _b2ChainShape_Clear);
    oluacls_func(L, "createChain", _b2ChainShape_CreateChain);
    oluacls_func(L, "createLoop", _b2ChainShape_CreateLoop);
    oluacls_func(L, "getChildEdge", _b2ChainShape_GetChildEdge);
    oluacls_func(L, "new", _b2ChainShape_new);

    return 1;
}
OLUA_END_DECLS

static int _b2BodyDef___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2BodyDef *)olua_toobj(L, 1, "b2.BodyDef");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2BodyDef___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2BodyDef *)olua_toobj(L, 1, "b2.BodyDef");
    olua_push_object(L, self, "b2.BodyDef");

    olua_endinvoke(L);

    return 1;
}

static int _b2BodyDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2BodyDef()
    b2BodyDef *ret = new b2BodyDef();
    int num_ret = olua_push_object(L, ret, "b2.BodyDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BodyDef_get_allowSleep(lua_State *L)
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

static int _b2BodyDef_set_allowSleep(lua_State *L)
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

static int _b2BodyDef_get_angle(lua_State *L)
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

static int _b2BodyDef_set_angle(lua_State *L)
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

static int _b2BodyDef_get_angularDamping(lua_State *L)
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

static int _b2BodyDef_set_angularDamping(lua_State *L)
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

static int _b2BodyDef_get_angularVelocity(lua_State *L)
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

static int _b2BodyDef_set_angularVelocity(lua_State *L)
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

static int _b2BodyDef_get_awake(lua_State *L)
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

static int _b2BodyDef_set_awake(lua_State *L)
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

static int _b2BodyDef_get_bullet(lua_State *L)
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

static int _b2BodyDef_set_bullet(lua_State *L)
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

static int _b2BodyDef_get_enabled(lua_State *L)
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

static int _b2BodyDef_set_enabled(lua_State *L)
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

static int _b2BodyDef_get_fixedRotation(lua_State *L)
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

static int _b2BodyDef_set_fixedRotation(lua_State *L)
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

static int _b2BodyDef_get_gravityScale(lua_State *L)
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

static int _b2BodyDef_set_gravityScale(lua_State *L)
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

static int _b2BodyDef_get_linearDamping(lua_State *L)
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

static int _b2BodyDef_set_linearDamping(lua_State *L)
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

static int _b2BodyDef_get_linearVelocity(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.BodyDef");

    // b2Vec2 linearVelocity
    b2Vec2 &ret = self->linearVelocity;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BodyDef_set_linearVelocity(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    b2Vec2 arg1;       /** linearVelocity */

    olua_to_object(L, 1, &self, "b2.BodyDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 linearVelocity
    self->linearVelocity = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2BodyDef_get_position(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.BodyDef");

    // b2Vec2 position
    b2Vec2 &ret = self->position;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BodyDef_set_position(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    b2Vec2 arg1;       /** position */

    olua_to_object(L, 1, &self, "b2.BodyDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 position
    self->position = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2BodyDef_get_type(lua_State *L)
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

static int _b2BodyDef_set_type(lua_State *L)
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

static int _b2BodyDef_get_userData(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.BodyDef");

    // b2BodyUserData userData
    b2BodyUserData &ret = self->userData;
    int num_ret = olua_pushcopy_object(L, ret, "b2.BodyUserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BodyDef_set_userData(lua_State *L)
{
    olua_startinvoke(L);

    b2BodyDef *self = nullptr;
    b2BodyUserData arg1;       /** userData */

    olua_to_object(L, 1, &self, "b2.BodyDef");
    olua_check_object(L, 2, &arg1, "b2.BodyUserData");

    // b2BodyUserData userData
    self->userData = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2BodyDef(lua_State *L)
{
    oluacls_class<b2BodyDef>(L, "b2.BodyDef");
    oluacls_func(L, "__gc", _b2BodyDef___gc);
    oluacls_func(L, "__olua_move", _b2BodyDef___olua_move);
    oluacls_func(L, "new", _b2BodyDef_new);
    oluacls_prop(L, "allowSleep", _b2BodyDef_get_allowSleep, _b2BodyDef_set_allowSleep);
    oluacls_prop(L, "angle", _b2BodyDef_get_angle, _b2BodyDef_set_angle);
    oluacls_prop(L, "angularDamping", _b2BodyDef_get_angularDamping, _b2BodyDef_set_angularDamping);
    oluacls_prop(L, "angularVelocity", _b2BodyDef_get_angularVelocity, _b2BodyDef_set_angularVelocity);
    oluacls_prop(L, "awake", _b2BodyDef_get_awake, _b2BodyDef_set_awake);
    oluacls_prop(L, "bullet", _b2BodyDef_get_bullet, _b2BodyDef_set_bullet);
    oluacls_prop(L, "enabled", _b2BodyDef_get_enabled, _b2BodyDef_set_enabled);
    oluacls_prop(L, "fixedRotation", _b2BodyDef_get_fixedRotation, _b2BodyDef_set_fixedRotation);
    oluacls_prop(L, "gravityScale", _b2BodyDef_get_gravityScale, _b2BodyDef_set_gravityScale);
    oluacls_prop(L, "linearDamping", _b2BodyDef_get_linearDamping, _b2BodyDef_set_linearDamping);
    oluacls_prop(L, "linearVelocity", _b2BodyDef_get_linearVelocity, _b2BodyDef_set_linearVelocity);
    oluacls_prop(L, "position", _b2BodyDef_get_position, _b2BodyDef_set_position);
    oluacls_prop(L, "type", _b2BodyDef_get_type, _b2BodyDef_set_type);
    oluacls_prop(L, "userData", _b2BodyDef_get_userData, _b2BodyDef_set_userData);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2BodyType(lua_State *L)
{
    oluacls_class<b2BodyType>(L, "b2.BodyType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "dynamicBody", (lua_Integer)b2BodyType::b2_dynamicBody);
    oluacls_enum(L, "kinematicBody", (lua_Integer)b2BodyType::b2_kinematicBody);
    oluacls_enum(L, "staticBody", (lua_Integer)b2BodyType::b2_staticBody);

    return 1;
}
OLUA_END_DECLS

static int _b2Body___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Body *)olua_toobj(L, 1, "b2.Body");
    olua_push_object(L, self, "b2.Body");

    olua_endinvoke(L);

    return 1;
}

static int _b2Body_ApplyAngularImpulse(lua_State *L)
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

static int _b2Body_ApplyForce(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 arg1;       /** force */
    b2Vec2 arg2;       /** point */
    bool arg3 = false;       /** wake */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_object(L, 2, &arg1, "b2.Vec2");
    olua_check_object(L, 3, &arg2, "b2.Vec2");
    olua_check_bool(L, 4, &arg3);

    // void ApplyForce(const b2Vec2 &force, const b2Vec2 &point, bool wake)
    self->ApplyForce(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _b2Body_ApplyForceToCenter(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 arg1;       /** force */
    bool arg2 = false;       /** wake */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_object(L, 2, &arg1, "b2.Vec2");
    olua_check_bool(L, 3, &arg2);

    // void ApplyForceToCenter(const b2Vec2 &force, bool wake)
    self->ApplyForceToCenter(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _b2Body_ApplyLinearImpulse(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 arg1;       /** impulse */
    b2Vec2 arg2;       /** point */
    bool arg3 = false;       /** wake */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_object(L, 2, &arg1, "b2.Vec2");
    olua_check_object(L, 3, &arg2, "b2.Vec2");
    olua_check_bool(L, 4, &arg3);

    // void ApplyLinearImpulse(const b2Vec2 &impulse, const b2Vec2 &point, bool wake)
    self->ApplyLinearImpulse(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _b2Body_ApplyLinearImpulseToCenter(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 arg1;       /** impulse */
    bool arg2 = false;       /** wake */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_object(L, 2, &arg1, "b2.Vec2");
    olua_check_bool(L, 3, &arg2);

    // void ApplyLinearImpulseToCenter(const b2Vec2 &impulse, bool wake)
    self->ApplyLinearImpulseToCenter(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _b2Body_ApplyTorque(lua_State *L)
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

static int _b2Body_CreateFixture$1(lua_State *L)
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

static int _b2Body_CreateFixture$2(lua_State *L)
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

static int _b2Body_CreateFixture(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_object(L, 2, "b2.FixtureDef"))) {
            // b2Fixture *CreateFixture(const b2FixtureDef *def)
            return _b2Body_CreateFixture$1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 2, "b2.Shape")) && (olua_is_number(L, 3))) {
            // b2Fixture *CreateFixture(const b2Shape *shape, float density)
            return _b2Body_CreateFixture$2(L);
        // }
    }

    luaL_error(L, "method 'b2Body::CreateFixture' not support '%d' arguments", num_args);

    return 0;
}

static int _b2Body_DestroyFixture(lua_State *L)
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

static int _b2Body_Dump(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // void Dump()
    self->Dump();

    olua_endinvoke(L);

    return 0;
}

static int _b2Body_GetAngle(lua_State *L)
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

static int _b2Body_GetAngularDamping(lua_State *L)
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

static int _b2Body_GetAngularVelocity(lua_State *L)
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

static int _b2Body_GetContactList(lua_State *L)
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

static int _b2Body_GetFixtureList(lua_State *L)
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

static int _b2Body_GetGravityScale(lua_State *L)
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

static int _b2Body_GetInertia(lua_State *L)
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

static int _b2Body_GetJointList(lua_State *L)
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

static int _b2Body_GetLinearDamping(lua_State *L)
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

static int _b2Body_GetLinearVelocity(lua_State *L)
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

static int _b2Body_GetLinearVelocityFromLocalPoint(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 arg1;       /** localPoint */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 GetLinearVelocityFromLocalPoint(const b2Vec2 &localPoint)
    b2Vec2 ret = self->GetLinearVelocityFromLocalPoint(arg1);
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetLinearVelocityFromWorldPoint(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 arg1;       /** worldPoint */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 GetLinearVelocityFromWorldPoint(const b2Vec2 &worldPoint)
    b2Vec2 ret = self->GetLinearVelocityFromWorldPoint(arg1);
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetLocalCenter(lua_State *L)
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

static int _b2Body_GetLocalPoint(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 arg1;       /** worldPoint */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 GetLocalPoint(const b2Vec2 &worldPoint)
    b2Vec2 ret = self->GetLocalPoint(arg1);
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetLocalVector(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 arg1;       /** worldVector */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 GetLocalVector(const b2Vec2 &worldVector)
    b2Vec2 ret = self->GetLocalVector(arg1);
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetMass(lua_State *L)
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

static int _b2Body_GetMassData(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // b2MassData GetMassData()
    b2MassData ret = self->GetMassData();
    int num_ret = olua_pushcopy_object(L, ret, "b2.MassData");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetNext(lua_State *L)
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

static int _b2Body_GetPosition(lua_State *L)
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

static int _b2Body_GetTransform(lua_State *L)
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

static int _b2Body_GetType(lua_State *L)
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

static int _b2Body_GetUserData(lua_State *L)
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

static int _b2Body_GetWorld(lua_State *L)
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

static int _b2Body_GetWorldCenter(lua_State *L)
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

static int _b2Body_GetWorldPoint(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 arg1;       /** localPoint */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 GetWorldPoint(const b2Vec2 &localPoint)
    b2Vec2 ret = self->GetWorldPoint(arg1);
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_GetWorldVector(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 arg1;       /** localVector */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 GetWorldVector(const b2Vec2 &localVector)
    b2Vec2 ret = self->GetWorldVector(arg1);
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Body_IsAwake(lua_State *L)
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

static int _b2Body_IsBullet(lua_State *L)
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

static int _b2Body_IsEnabled(lua_State *L)
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

static int _b2Body_IsFixedRotation(lua_State *L)
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

static int _b2Body_IsSleepingAllowed(lua_State *L)
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

static int _b2Body_ResetMassData(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Body");

    // void ResetMassData()
    self->ResetMassData();

    olua_endinvoke(L);

    return 0;
}

static int _b2Body_SetAngularDamping(lua_State *L)
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

static int _b2Body_SetAngularVelocity(lua_State *L)
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

static int _b2Body_SetAwake(lua_State *L)
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

static int _b2Body_SetBullet(lua_State *L)
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

static int _b2Body_SetEnabled(lua_State *L)
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

static int _b2Body_SetFixedRotation(lua_State *L)
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

static int _b2Body_SetGravityScale(lua_State *L)
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

static int _b2Body_SetLinearDamping(lua_State *L)
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

static int _b2Body_SetLinearVelocity(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 arg1;       /** v */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // void SetLinearVelocity(const b2Vec2 &v)
    self->SetLinearVelocity(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Body_SetMassData(lua_State *L)
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

static int _b2Body_SetSleepingAllowed(lua_State *L)
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

static int _b2Body_SetTransform(lua_State *L)
{
    olua_startinvoke(L);

    b2Body *self = nullptr;
    b2Vec2 arg1;       /** position */
    float arg2 = 0;       /** angle */

    olua_to_object(L, 1, &self, "b2.Body");
    olua_check_object(L, 2, &arg1, "b2.Vec2");
    olua_check_number(L, 3, &arg2);

    // void SetTransform(const b2Vec2 &position, float angle)
    self->SetTransform(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _b2Body_SetType(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2Body(lua_State *L)
{
    oluacls_class<b2Body>(L, "b2.Body");
    oluacls_func(L, "__olua_move", _b2Body___olua_move);
    oluacls_func(L, "applyAngularImpulse", _b2Body_ApplyAngularImpulse);
    oluacls_func(L, "applyForce", _b2Body_ApplyForce);
    oluacls_func(L, "applyForceToCenter", _b2Body_ApplyForceToCenter);
    oluacls_func(L, "applyLinearImpulse", _b2Body_ApplyLinearImpulse);
    oluacls_func(L, "applyLinearImpulseToCenter", _b2Body_ApplyLinearImpulseToCenter);
    oluacls_func(L, "applyTorque", _b2Body_ApplyTorque);
    oluacls_func(L, "createFixture", _b2Body_CreateFixture);
    oluacls_func(L, "destroyFixture", _b2Body_DestroyFixture);
    oluacls_func(L, "dump", _b2Body_Dump);
    oluacls_func(L, "getAngle", _b2Body_GetAngle);
    oluacls_func(L, "getAngularDamping", _b2Body_GetAngularDamping);
    oluacls_func(L, "getAngularVelocity", _b2Body_GetAngularVelocity);
    oluacls_func(L, "getContactList", _b2Body_GetContactList);
    oluacls_func(L, "getFixtureList", _b2Body_GetFixtureList);
    oluacls_func(L, "getGravityScale", _b2Body_GetGravityScale);
    oluacls_func(L, "getInertia", _b2Body_GetInertia);
    oluacls_func(L, "getJointList", _b2Body_GetJointList);
    oluacls_func(L, "getLinearDamping", _b2Body_GetLinearDamping);
    oluacls_func(L, "getLinearVelocity", _b2Body_GetLinearVelocity);
    oluacls_func(L, "getLinearVelocityFromLocalPoint", _b2Body_GetLinearVelocityFromLocalPoint);
    oluacls_func(L, "getLinearVelocityFromWorldPoint", _b2Body_GetLinearVelocityFromWorldPoint);
    oluacls_func(L, "getLocalCenter", _b2Body_GetLocalCenter);
    oluacls_func(L, "getLocalPoint", _b2Body_GetLocalPoint);
    oluacls_func(L, "getLocalVector", _b2Body_GetLocalVector);
    oluacls_func(L, "getMass", _b2Body_GetMass);
    oluacls_func(L, "getMassData", _b2Body_GetMassData);
    oluacls_func(L, "getNext", _b2Body_GetNext);
    oluacls_func(L, "getPosition", _b2Body_GetPosition);
    oluacls_func(L, "getTransform", _b2Body_GetTransform);
    oluacls_func(L, "getType", _b2Body_GetType);
    oluacls_func(L, "getUserData", _b2Body_GetUserData);
    oluacls_func(L, "getWorld", _b2Body_GetWorld);
    oluacls_func(L, "getWorldCenter", _b2Body_GetWorldCenter);
    oluacls_func(L, "getWorldPoint", _b2Body_GetWorldPoint);
    oluacls_func(L, "getWorldVector", _b2Body_GetWorldVector);
    oluacls_func(L, "isAwake", _b2Body_IsAwake);
    oluacls_func(L, "isBullet", _b2Body_IsBullet);
    oluacls_func(L, "isEnabled", _b2Body_IsEnabled);
    oluacls_func(L, "isFixedRotation", _b2Body_IsFixedRotation);
    oluacls_func(L, "isSleepingAllowed", _b2Body_IsSleepingAllowed);
    oluacls_func(L, "resetMassData", _b2Body_ResetMassData);
    oluacls_func(L, "setAngularDamping", _b2Body_SetAngularDamping);
    oluacls_func(L, "setAngularVelocity", _b2Body_SetAngularVelocity);
    oluacls_func(L, "setAwake", _b2Body_SetAwake);
    oluacls_func(L, "setBullet", _b2Body_SetBullet);
    oluacls_func(L, "setEnabled", _b2Body_SetEnabled);
    oluacls_func(L, "setFixedRotation", _b2Body_SetFixedRotation);
    oluacls_func(L, "setGravityScale", _b2Body_SetGravityScale);
    oluacls_func(L, "setLinearDamping", _b2Body_SetLinearDamping);
    oluacls_func(L, "setLinearVelocity", _b2Body_SetLinearVelocity);
    oluacls_func(L, "setMassData", _b2Body_SetMassData);
    oluacls_func(L, "setSleepingAllowed", _b2Body_SetSleepingAllowed);
    oluacls_func(L, "setTransform", _b2Body_SetTransform);
    oluacls_func(L, "setType", _b2Body_SetType);
    oluacls_prop(L, "angle", _b2Body_GetAngle, nullptr);
    oluacls_prop(L, "angularDamping", _b2Body_GetAngularDamping, _b2Body_SetAngularDamping);
    oluacls_prop(L, "angularVelocity", _b2Body_GetAngularVelocity, _b2Body_SetAngularVelocity);
    oluacls_prop(L, "awake", _b2Body_IsAwake, _b2Body_SetAwake);
    oluacls_prop(L, "bullet", _b2Body_IsBullet, _b2Body_SetBullet);
    oluacls_prop(L, "contactList", _b2Body_GetContactList, nullptr);
    oluacls_prop(L, "enabled", _b2Body_IsEnabled, _b2Body_SetEnabled);
    oluacls_prop(L, "fixedRotation", _b2Body_IsFixedRotation, _b2Body_SetFixedRotation);
    oluacls_prop(L, "fixtureList", _b2Body_GetFixtureList, nullptr);
    oluacls_prop(L, "gravityScale", _b2Body_GetGravityScale, _b2Body_SetGravityScale);
    oluacls_prop(L, "inertia", _b2Body_GetInertia, nullptr);
    oluacls_prop(L, "jointList", _b2Body_GetJointList, nullptr);
    oluacls_prop(L, "linearDamping", _b2Body_GetLinearDamping, _b2Body_SetLinearDamping);
    oluacls_prop(L, "linearVelocity", _b2Body_GetLinearVelocity, _b2Body_SetLinearVelocity);
    oluacls_prop(L, "localCenter", _b2Body_GetLocalCenter, nullptr);
    oluacls_prop(L, "mass", _b2Body_GetMass, nullptr);
    oluacls_prop(L, "massData", _b2Body_GetMassData, _b2Body_SetMassData);
    oluacls_prop(L, "next", _b2Body_GetNext, nullptr);
    oluacls_prop(L, "position", _b2Body_GetPosition, nullptr);
    oluacls_prop(L, "sleepingAllowed", _b2Body_IsSleepingAllowed, _b2Body_SetSleepingAllowed);
    oluacls_prop(L, "type", _b2Body_GetType, _b2Body_SetType);
    oluacls_prop(L, "userData", _b2Body_GetUserData, nullptr);
    oluacls_prop(L, "world", _b2Body_GetWorld, nullptr);
    oluacls_prop(L, "worldCenter", _b2Body_GetWorldCenter, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _b2BodyUserData___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2BodyUserData *)olua_toobj(L, 1, "b2.BodyUserData");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2BodyUserData___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2BodyUserData *)olua_toobj(L, 1, "b2.BodyUserData");
    olua_push_object(L, self, "b2.BodyUserData");

    olua_endinvoke(L);

    return 1;
}

static int _b2BodyUserData_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2BodyUserData()
    b2BodyUserData *ret = new b2BodyUserData();
    int num_ret = olua_push_object(L, ret, "b2.BodyUserData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BodyUserData_get_pointer(lua_State *L)
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

static int _b2BodyUserData_set_pointer(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2BodyUserData(lua_State *L)
{
    oluacls_class<b2BodyUserData>(L, "b2.BodyUserData");
    oluacls_func(L, "__gc", _b2BodyUserData___gc);
    oluacls_func(L, "__olua_move", _b2BodyUserData___olua_move);
    oluacls_func(L, "new", _b2BodyUserData_new);
    oluacls_prop(L, "pointer", _b2BodyUserData_get_pointer, _b2BodyUserData_set_pointer);

    return 1;
}
OLUA_END_DECLS

static int _b2FixtureDef___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2FixtureDef *)olua_toobj(L, 1, "b2.FixtureDef");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2FixtureDef___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2FixtureDef *)olua_toobj(L, 1, "b2.FixtureDef");
    olua_push_object(L, self, "b2.FixtureDef");

    olua_endinvoke(L);

    return 1;
}

static int _b2FixtureDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2FixtureDef()
    b2FixtureDef *ret = new b2FixtureDef();
    int num_ret = olua_push_object(L, ret, "b2.FixtureDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2FixtureDef_get_density(lua_State *L)
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

static int _b2FixtureDef_set_density(lua_State *L)
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

static int _b2FixtureDef_get_filter(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.FixtureDef");

    // b2Filter filter
    b2Filter &ret = self->filter;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Filter");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2FixtureDef_set_filter(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;
    b2Filter arg1;       /** filter */

    olua_to_object(L, 1, &self, "b2.FixtureDef");
    olua_check_object(L, 2, &arg1, "b2.Filter");

    // b2Filter filter
    self->filter = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2FixtureDef_get_friction(lua_State *L)
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

static int _b2FixtureDef_set_friction(lua_State *L)
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

static int _b2FixtureDef_get_isSensor(lua_State *L)
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

static int _b2FixtureDef_set_isSensor(lua_State *L)
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

static int _b2FixtureDef_get_restitution(lua_State *L)
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

static int _b2FixtureDef_set_restitution(lua_State *L)
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

static int _b2FixtureDef_get_restitutionThreshold(lua_State *L)
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

static int _b2FixtureDef_set_restitutionThreshold(lua_State *L)
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

static int _b2FixtureDef_get_shape(lua_State *L)
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

static int _b2FixtureDef_set_shape(lua_State *L)
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

static int _b2FixtureDef_get_userData(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.FixtureDef");

    // b2FixtureUserData userData
    b2FixtureUserData &ret = self->userData;
    int num_ret = olua_pushcopy_object(L, ret, "b2.FixtureUserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2FixtureDef_set_userData(lua_State *L)
{
    olua_startinvoke(L);

    b2FixtureDef *self = nullptr;
    b2FixtureUserData arg1;       /** userData */

    olua_to_object(L, 1, &self, "b2.FixtureDef");
    olua_check_object(L, 2, &arg1, "b2.FixtureUserData");

    // b2FixtureUserData userData
    self->userData = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2FixtureDef(lua_State *L)
{
    oluacls_class<b2FixtureDef>(L, "b2.FixtureDef");
    oluacls_func(L, "__gc", _b2FixtureDef___gc);
    oluacls_func(L, "__olua_move", _b2FixtureDef___olua_move);
    oluacls_func(L, "new", _b2FixtureDef_new);
    oluacls_prop(L, "density", _b2FixtureDef_get_density, _b2FixtureDef_set_density);
    oluacls_prop(L, "filter", _b2FixtureDef_get_filter, _b2FixtureDef_set_filter);
    oluacls_prop(L, "friction", _b2FixtureDef_get_friction, _b2FixtureDef_set_friction);
    oluacls_prop(L, "isSensor", _b2FixtureDef_get_isSensor, _b2FixtureDef_set_isSensor);
    oluacls_prop(L, "restitution", _b2FixtureDef_get_restitution, _b2FixtureDef_set_restitution);
    oluacls_prop(L, "restitutionThreshold", _b2FixtureDef_get_restitutionThreshold, _b2FixtureDef_set_restitutionThreshold);
    oluacls_prop(L, "shape", _b2FixtureDef_get_shape, _b2FixtureDef_set_shape);
    oluacls_prop(L, "userData", _b2FixtureDef_get_userData, _b2FixtureDef_set_userData);

    return 1;
}
OLUA_END_DECLS

static int _b2Fixture___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Fixture *)olua_toobj(L, 1, "b2.Fixture");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2Fixture___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Fixture *)olua_toobj(L, 1, "b2.Fixture");
    olua_push_object(L, self, "b2.Fixture");

    olua_endinvoke(L);

    return 1;
}

static int _b2Fixture_Dump(lua_State *L)
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

static int _b2Fixture_GetAABB(lua_State *L)
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

static int _b2Fixture_GetBody(lua_State *L)
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

static int _b2Fixture_GetDensity(lua_State *L)
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

static int _b2Fixture_GetFilterData(lua_State *L)
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

static int _b2Fixture_GetFriction(lua_State *L)
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

static int _b2Fixture_GetMassData(lua_State *L)
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

static int _b2Fixture_GetNext(lua_State *L)
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

static int _b2Fixture_GetRestitution(lua_State *L)
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

static int _b2Fixture_GetRestitutionThreshold(lua_State *L)
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

static int _b2Fixture_GetShape(lua_State *L)
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

static int _b2Fixture_GetType(lua_State *L)
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

static int _b2Fixture_GetUserData(lua_State *L)
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

static int _b2Fixture_IsSensor(lua_State *L)
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

static int _b2Fixture_RayCast(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;
    b2RayCastOutput *arg1 = nullptr;       /** output */
    b2RayCastInput arg2;       /** input */
    int32 arg3 = 0;       /** childIndex */

    olua_to_object(L, 1, &self, "b2.Fixture");
    olua_check_object(L, 2, &arg1, "b2.RayCastOutput");
    olua_check_object(L, 3, &arg2, "b2.RayCastInput");
    olua_check_integer(L, 4, &arg3);

    // bool RayCast(b2RayCastOutput *output, const b2RayCastInput &input, int32 childIndex)
    bool ret = self->RayCast(arg1, arg2, arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Fixture_Refilter(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Fixture");

    // void Refilter()
    self->Refilter();

    olua_endinvoke(L);

    return 0;
}

static int _b2Fixture_SetDensity(lua_State *L)
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

static int _b2Fixture_SetFilterData(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;
    b2Filter arg1;       /** filter */

    olua_to_object(L, 1, &self, "b2.Fixture");
    olua_check_object(L, 2, &arg1, "b2.Filter");

    // void SetFilterData(const b2Filter &filter)
    self->SetFilterData(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2Fixture_SetFriction(lua_State *L)
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

static int _b2Fixture_SetRestitution(lua_State *L)
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

static int _b2Fixture_SetRestitutionThreshold(lua_State *L)
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

static int _b2Fixture_SetSensor(lua_State *L)
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

static int _b2Fixture_TestPoint(lua_State *L)
{
    olua_startinvoke(L);

    b2Fixture *self = nullptr;
    b2Vec2 arg1;       /** p */

    olua_to_object(L, 1, &self, "b2.Fixture");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // bool TestPoint(const b2Vec2 &p)
    bool ret = self->TestPoint(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2Fixture(lua_State *L)
{
    oluacls_class<b2Fixture>(L, "b2.Fixture");
    oluacls_func(L, "__gc", _b2Fixture___gc);
    oluacls_func(L, "__olua_move", _b2Fixture___olua_move);
    oluacls_func(L, "dump", _b2Fixture_Dump);
    oluacls_func(L, "getAABB", _b2Fixture_GetAABB);
    oluacls_func(L, "getBody", _b2Fixture_GetBody);
    oluacls_func(L, "getDensity", _b2Fixture_GetDensity);
    oluacls_func(L, "getFilterData", _b2Fixture_GetFilterData);
    oluacls_func(L, "getFriction", _b2Fixture_GetFriction);
    oluacls_func(L, "getMassData", _b2Fixture_GetMassData);
    oluacls_func(L, "getNext", _b2Fixture_GetNext);
    oluacls_func(L, "getRestitution", _b2Fixture_GetRestitution);
    oluacls_func(L, "getRestitutionThreshold", _b2Fixture_GetRestitutionThreshold);
    oluacls_func(L, "getShape", _b2Fixture_GetShape);
    oluacls_func(L, "getType", _b2Fixture_GetType);
    oluacls_func(L, "getUserData", _b2Fixture_GetUserData);
    oluacls_func(L, "isSensor", _b2Fixture_IsSensor);
    oluacls_func(L, "rayCast", _b2Fixture_RayCast);
    oluacls_func(L, "refilter", _b2Fixture_Refilter);
    oluacls_func(L, "setDensity", _b2Fixture_SetDensity);
    oluacls_func(L, "setFilterData", _b2Fixture_SetFilterData);
    oluacls_func(L, "setFriction", _b2Fixture_SetFriction);
    oluacls_func(L, "setRestitution", _b2Fixture_SetRestitution);
    oluacls_func(L, "setRestitutionThreshold", _b2Fixture_SetRestitutionThreshold);
    oluacls_func(L, "setSensor", _b2Fixture_SetSensor);
    oluacls_func(L, "testPoint", _b2Fixture_TestPoint);
    oluacls_prop(L, "body", _b2Fixture_GetBody, nullptr);
    oluacls_prop(L, "density", _b2Fixture_GetDensity, _b2Fixture_SetDensity);
    oluacls_prop(L, "filterData", _b2Fixture_GetFilterData, _b2Fixture_SetFilterData);
    oluacls_prop(L, "friction", _b2Fixture_GetFriction, _b2Fixture_SetFriction);
    oluacls_prop(L, "next", _b2Fixture_GetNext, nullptr);
    oluacls_prop(L, "restitution", _b2Fixture_GetRestitution, _b2Fixture_SetRestitution);
    oluacls_prop(L, "restitutionThreshold", _b2Fixture_GetRestitutionThreshold, _b2Fixture_SetRestitutionThreshold);
    oluacls_prop(L, "sensor", _b2Fixture_IsSensor, _b2Fixture_SetSensor);
    oluacls_prop(L, "shape", _b2Fixture_GetShape, nullptr);
    oluacls_prop(L, "type", _b2Fixture_GetType, nullptr);
    oluacls_prop(L, "userData", _b2Fixture_GetUserData, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _b2JointDef___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2JointDef *)olua_toobj(L, 1, "b2.JointDef");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2JointDef___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2JointDef *)olua_toobj(L, 1, "b2.JointDef");
    olua_push_object(L, self, "b2.JointDef");

    olua_endinvoke(L);

    return 1;
}

static int _b2JointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2JointDef()
    b2JointDef *ret = new b2JointDef();
    int num_ret = olua_push_object(L, ret, "b2.JointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2JointDef_get_bodyA(lua_State *L)
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

static int _b2JointDef_set_bodyA(lua_State *L)
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

static int _b2JointDef_get_bodyB(lua_State *L)
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

static int _b2JointDef_set_bodyB(lua_State *L)
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

static int _b2JointDef_get_collideConnected(lua_State *L)
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

static int _b2JointDef_set_collideConnected(lua_State *L)
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

static int _b2JointDef_get_type(lua_State *L)
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

static int _b2JointDef_set_type(lua_State *L)
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

static int _b2JointDef_get_userData(lua_State *L)
{
    olua_startinvoke(L);

    b2JointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.JointDef");

    // b2JointUserData userData
    b2JointUserData &ret = self->userData;
    int num_ret = olua_pushcopy_object(L, ret, "b2.JointUserData");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2JointDef_set_userData(lua_State *L)
{
    olua_startinvoke(L);

    b2JointDef *self = nullptr;
    b2JointUserData arg1;       /** userData */

    olua_to_object(L, 1, &self, "b2.JointDef");
    olua_check_object(L, 2, &arg1, "b2.JointUserData");

    // b2JointUserData userData
    self->userData = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2JointDef(lua_State *L)
{
    oluacls_class<b2JointDef>(L, "b2.JointDef");
    oluacls_func(L, "__gc", _b2JointDef___gc);
    oluacls_func(L, "__olua_move", _b2JointDef___olua_move);
    oluacls_func(L, "new", _b2JointDef_new);
    oluacls_prop(L, "bodyA", _b2JointDef_get_bodyA, _b2JointDef_set_bodyA);
    oluacls_prop(L, "bodyB", _b2JointDef_get_bodyB, _b2JointDef_set_bodyB);
    oluacls_prop(L, "collideConnected", _b2JointDef_get_collideConnected, _b2JointDef_set_collideConnected);
    oluacls_prop(L, "type", _b2JointDef_get_type, _b2JointDef_set_type);
    oluacls_prop(L, "userData", _b2JointDef_get_userData, _b2JointDef_set_userData);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2JointType(lua_State *L)
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
OLUA_END_DECLS

static int _b2Joint___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Joint *)olua_toobj(L, 1, "b2.Joint");
    olua_push_object(L, self, "b2.Joint");

    olua_endinvoke(L);

    return 1;
}

static int _b2Joint_Draw(lua_State *L)
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

static int _b2Joint_Dump(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Joint");

    // void Dump()
    self->Dump();

    olua_endinvoke(L);

    return 0;
}

static int _b2Joint_GetAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Joint");

    // b2Vec2 GetAnchorA()
    b2Vec2 ret = self->GetAnchorA();
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Joint_GetAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Joint");

    // b2Vec2 GetAnchorB()
    b2Vec2 ret = self->GetAnchorB();
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Joint_GetBodyA(lua_State *L)
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

static int _b2Joint_GetBodyB(lua_State *L)
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

static int _b2Joint_GetCollideConnected(lua_State *L)
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

static int _b2Joint_GetNext(lua_State *L)
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

static int _b2Joint_GetReactionForce(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;
    float arg1 = 0;       /** inv_dt */

    olua_to_object(L, 1, &self, "b2.Joint");
    olua_check_number(L, 2, &arg1);

    // b2Vec2 GetReactionForce(float inv_dt)
    b2Vec2 ret = self->GetReactionForce(arg1);
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Joint_GetReactionTorque(lua_State *L)
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

static int _b2Joint_GetType(lua_State *L)
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

static int _b2Joint_GetUserData(lua_State *L)
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

static int _b2Joint_IsEnabled(lua_State *L)
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

static int _b2Joint_ShiftOrigin(lua_State *L)
{
    olua_startinvoke(L);

    b2Joint *self = nullptr;
    b2Vec2 arg1;       /** newOrigin */

    olua_to_object(L, 1, &self, "b2.Joint");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // void ShiftOrigin(const b2Vec2 &newOrigin)
    self->ShiftOrigin(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2Joint(lua_State *L)
{
    oluacls_class<b2Joint>(L, "b2.Joint");
    oluacls_func(L, "__olua_move", _b2Joint___olua_move);
    oluacls_func(L, "draw", _b2Joint_Draw);
    oluacls_func(L, "dump", _b2Joint_Dump);
    oluacls_func(L, "getAnchorA", _b2Joint_GetAnchorA);
    oluacls_func(L, "getAnchorB", _b2Joint_GetAnchorB);
    oluacls_func(L, "getBodyA", _b2Joint_GetBodyA);
    oluacls_func(L, "getBodyB", _b2Joint_GetBodyB);
    oluacls_func(L, "getCollideConnected", _b2Joint_GetCollideConnected);
    oluacls_func(L, "getNext", _b2Joint_GetNext);
    oluacls_func(L, "getReactionForce", _b2Joint_GetReactionForce);
    oluacls_func(L, "getReactionTorque", _b2Joint_GetReactionTorque);
    oluacls_func(L, "getType", _b2Joint_GetType);
    oluacls_func(L, "getUserData", _b2Joint_GetUserData);
    oluacls_func(L, "isEnabled", _b2Joint_IsEnabled);
    oluacls_func(L, "shiftOrigin", _b2Joint_ShiftOrigin);
    oluacls_prop(L, "anchorA", _b2Joint_GetAnchorA, nullptr);
    oluacls_prop(L, "anchorB", _b2Joint_GetAnchorB, nullptr);
    oluacls_prop(L, "bodyA", _b2Joint_GetBodyA, nullptr);
    oluacls_prop(L, "bodyB", _b2Joint_GetBodyB, nullptr);
    oluacls_prop(L, "collideConnected", _b2Joint_GetCollideConnected, nullptr);
    oluacls_prop(L, "enabled", _b2Joint_IsEnabled, nullptr);
    oluacls_prop(L, "next", _b2Joint_GetNext, nullptr);
    oluacls_prop(L, "type", _b2Joint_GetType, nullptr);
    oluacls_prop(L, "userData", _b2Joint_GetUserData, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _b2DistanceJointDef_Initialize(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;
    b2Body *arg1 = nullptr;       /** bodyA */
    b2Body *arg2 = nullptr;       /** bodyB */
    b2Vec2 arg3;       /** anchorA */
    b2Vec2 arg4;       /** anchorB */

    olua_to_object(L, 1, &self, "b2.DistanceJointDef");
    olua_check_object(L, 2, &arg1, "b2.Body");
    olua_check_object(L, 3, &arg2, "b2.Body");
    olua_check_object(L, 4, &arg3, "b2.Vec2");
    olua_check_object(L, 5, &arg4, "b2.Vec2");

    // void Initialize(b2Body *bodyA, b2Body *bodyB, const b2Vec2 &anchorA, const b2Vec2 &anchorB)
    self->Initialize(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _b2DistanceJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2DistanceJointDef()
    b2DistanceJointDef *ret = new b2DistanceJointDef();
    int num_ret = olua_push_object(L, ret, "b2.DistanceJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2DistanceJointDef_get_damping(lua_State *L)
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

static int _b2DistanceJointDef_set_damping(lua_State *L)
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

static int _b2DistanceJointDef_get_length(lua_State *L)
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

static int _b2DistanceJointDef_set_length(lua_State *L)
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

static int _b2DistanceJointDef_get_localAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.DistanceJointDef");

    // b2Vec2 localAnchorA
    b2Vec2 &ret = self->localAnchorA;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2DistanceJointDef_set_localAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAnchorA */

    olua_to_object(L, 1, &self, "b2.DistanceJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAnchorA
    self->localAnchorA = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2DistanceJointDef_get_localAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.DistanceJointDef");

    // b2Vec2 localAnchorB
    b2Vec2 &ret = self->localAnchorB;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2DistanceJointDef_set_localAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2DistanceJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAnchorB */

    olua_to_object(L, 1, &self, "b2.DistanceJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAnchorB
    self->localAnchorB = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2DistanceJointDef_get_maxLength(lua_State *L)
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

static int _b2DistanceJointDef_set_maxLength(lua_State *L)
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

static int _b2DistanceJointDef_get_minLength(lua_State *L)
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

static int _b2DistanceJointDef_set_minLength(lua_State *L)
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

static int _b2DistanceJointDef_get_stiffness(lua_State *L)
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

static int _b2DistanceJointDef_set_stiffness(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2DistanceJointDef(lua_State *L)
{
    oluacls_class<b2DistanceJointDef, b2JointDef>(L, "b2.DistanceJointDef");
    oluacls_func(L, "initialize", _b2DistanceJointDef_Initialize);
    oluacls_func(L, "new", _b2DistanceJointDef_new);
    oluacls_prop(L, "damping", _b2DistanceJointDef_get_damping, _b2DistanceJointDef_set_damping);
    oluacls_prop(L, "length", _b2DistanceJointDef_get_length, _b2DistanceJointDef_set_length);
    oluacls_prop(L, "localAnchorA", _b2DistanceJointDef_get_localAnchorA, _b2DistanceJointDef_set_localAnchorA);
    oluacls_prop(L, "localAnchorB", _b2DistanceJointDef_get_localAnchorB, _b2DistanceJointDef_set_localAnchorB);
    oluacls_prop(L, "maxLength", _b2DistanceJointDef_get_maxLength, _b2DistanceJointDef_set_maxLength);
    oluacls_prop(L, "minLength", _b2DistanceJointDef_get_minLength, _b2DistanceJointDef_set_minLength);
    oluacls_prop(L, "stiffness", _b2DistanceJointDef_get_stiffness, _b2DistanceJointDef_set_stiffness);

    return 1;
}
OLUA_END_DECLS

static int _b2DistanceJoint___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2DistanceJoint *)olua_toobj(L, 1, "b2.DistanceJoint");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2DistanceJoint_GetCurrentLength(lua_State *L)
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

static int _b2DistanceJoint_GetDamping(lua_State *L)
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

static int _b2DistanceJoint_GetLength(lua_State *L)
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

static int _b2DistanceJoint_GetLocalAnchorA(lua_State *L)
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

static int _b2DistanceJoint_GetLocalAnchorB(lua_State *L)
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

static int _b2DistanceJoint_GetMaxLength(lua_State *L)
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

static int _b2DistanceJoint_GetMinLength(lua_State *L)
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

static int _b2DistanceJoint_GetStiffness(lua_State *L)
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

static int _b2DistanceJoint_SetDamping(lua_State *L)
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

static int _b2DistanceJoint_SetLength(lua_State *L)
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

static int _b2DistanceJoint_SetMaxLength(lua_State *L)
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

static int _b2DistanceJoint_SetMinLength(lua_State *L)
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

static int _b2DistanceJoint_SetStiffness(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2DistanceJoint(lua_State *L)
{
    oluacls_class<b2DistanceJoint, b2Joint>(L, "b2.DistanceJoint");
    oluacls_func(L, "__gc", _b2DistanceJoint___gc);
    oluacls_func(L, "getCurrentLength", _b2DistanceJoint_GetCurrentLength);
    oluacls_func(L, "getDamping", _b2DistanceJoint_GetDamping);
    oluacls_func(L, "getLength", _b2DistanceJoint_GetLength);
    oluacls_func(L, "getLocalAnchorA", _b2DistanceJoint_GetLocalAnchorA);
    oluacls_func(L, "getLocalAnchorB", _b2DistanceJoint_GetLocalAnchorB);
    oluacls_func(L, "getMaxLength", _b2DistanceJoint_GetMaxLength);
    oluacls_func(L, "getMinLength", _b2DistanceJoint_GetMinLength);
    oluacls_func(L, "getStiffness", _b2DistanceJoint_GetStiffness);
    oluacls_func(L, "setDamping", _b2DistanceJoint_SetDamping);
    oluacls_func(L, "setLength", _b2DistanceJoint_SetLength);
    oluacls_func(L, "setMaxLength", _b2DistanceJoint_SetMaxLength);
    oluacls_func(L, "setMinLength", _b2DistanceJoint_SetMinLength);
    oluacls_func(L, "setStiffness", _b2DistanceJoint_SetStiffness);
    oluacls_prop(L, "currentLength", _b2DistanceJoint_GetCurrentLength, nullptr);
    oluacls_prop(L, "damping", _b2DistanceJoint_GetDamping, _b2DistanceJoint_SetDamping);
    oluacls_prop(L, "length", _b2DistanceJoint_GetLength, _b2DistanceJoint_SetLength);
    oluacls_prop(L, "localAnchorA", _b2DistanceJoint_GetLocalAnchorA, nullptr);
    oluacls_prop(L, "localAnchorB", _b2DistanceJoint_GetLocalAnchorB, nullptr);
    oluacls_prop(L, "maxLength", _b2DistanceJoint_GetMaxLength, _b2DistanceJoint_SetMaxLength);
    oluacls_prop(L, "minLength", _b2DistanceJoint_GetMinLength, _b2DistanceJoint_SetMinLength);
    oluacls_prop(L, "stiffness", _b2DistanceJoint_GetStiffness, _b2DistanceJoint_SetStiffness);

    return 1;
}
OLUA_END_DECLS

static int _b2FrictionJointDef_Initialize(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJointDef *self = nullptr;
    b2Body *arg1 = nullptr;       /** bodyA */
    b2Body *arg2 = nullptr;       /** bodyB */
    b2Vec2 arg3;       /** anchor */

    olua_to_object(L, 1, &self, "b2.FrictionJointDef");
    olua_check_object(L, 2, &arg1, "b2.Body");
    olua_check_object(L, 3, &arg2, "b2.Body");
    olua_check_object(L, 4, &arg3, "b2.Vec2");

    // void Initialize(b2Body *bodyA, b2Body *bodyB, const b2Vec2 &anchor)
    self->Initialize(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _b2FrictionJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2FrictionJointDef()
    b2FrictionJointDef *ret = new b2FrictionJointDef();
    int num_ret = olua_push_object(L, ret, "b2.FrictionJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2FrictionJointDef_get_localAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.FrictionJointDef");

    // b2Vec2 localAnchorA
    b2Vec2 &ret = self->localAnchorA;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2FrictionJointDef_set_localAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAnchorA */

    olua_to_object(L, 1, &self, "b2.FrictionJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAnchorA
    self->localAnchorA = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2FrictionJointDef_get_localAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.FrictionJointDef");

    // b2Vec2 localAnchorB
    b2Vec2 &ret = self->localAnchorB;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2FrictionJointDef_set_localAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2FrictionJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAnchorB */

    olua_to_object(L, 1, &self, "b2.FrictionJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAnchorB
    self->localAnchorB = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2FrictionJointDef_get_maxForce(lua_State *L)
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

static int _b2FrictionJointDef_set_maxForce(lua_State *L)
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

static int _b2FrictionJointDef_get_maxTorque(lua_State *L)
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

static int _b2FrictionJointDef_set_maxTorque(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2FrictionJointDef(lua_State *L)
{
    oluacls_class<b2FrictionJointDef, b2JointDef>(L, "b2.FrictionJointDef");
    oluacls_func(L, "initialize", _b2FrictionJointDef_Initialize);
    oluacls_func(L, "new", _b2FrictionJointDef_new);
    oluacls_prop(L, "localAnchorA", _b2FrictionJointDef_get_localAnchorA, _b2FrictionJointDef_set_localAnchorA);
    oluacls_prop(L, "localAnchorB", _b2FrictionJointDef_get_localAnchorB, _b2FrictionJointDef_set_localAnchorB);
    oluacls_prop(L, "maxForce", _b2FrictionJointDef_get_maxForce, _b2FrictionJointDef_set_maxForce);
    oluacls_prop(L, "maxTorque", _b2FrictionJointDef_get_maxTorque, _b2FrictionJointDef_set_maxTorque);

    return 1;
}
OLUA_END_DECLS

static int _b2FrictionJoint___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2FrictionJoint *)olua_toobj(L, 1, "b2.FrictionJoint");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2FrictionJoint_GetLocalAnchorA(lua_State *L)
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

static int _b2FrictionJoint_GetLocalAnchorB(lua_State *L)
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

static int _b2FrictionJoint_GetMaxForce(lua_State *L)
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

static int _b2FrictionJoint_GetMaxTorque(lua_State *L)
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

static int _b2FrictionJoint_SetMaxForce(lua_State *L)
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

static int _b2FrictionJoint_SetMaxTorque(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2FrictionJoint(lua_State *L)
{
    oluacls_class<b2FrictionJoint, b2Joint>(L, "b2.FrictionJoint");
    oluacls_func(L, "__gc", _b2FrictionJoint___gc);
    oluacls_func(L, "getLocalAnchorA", _b2FrictionJoint_GetLocalAnchorA);
    oluacls_func(L, "getLocalAnchorB", _b2FrictionJoint_GetLocalAnchorB);
    oluacls_func(L, "getMaxForce", _b2FrictionJoint_GetMaxForce);
    oluacls_func(L, "getMaxTorque", _b2FrictionJoint_GetMaxTorque);
    oluacls_func(L, "setMaxForce", _b2FrictionJoint_SetMaxForce);
    oluacls_func(L, "setMaxTorque", _b2FrictionJoint_SetMaxTorque);
    oluacls_prop(L, "localAnchorA", _b2FrictionJoint_GetLocalAnchorA, nullptr);
    oluacls_prop(L, "localAnchorB", _b2FrictionJoint_GetLocalAnchorB, nullptr);
    oluacls_prop(L, "maxForce", _b2FrictionJoint_GetMaxForce, _b2FrictionJoint_SetMaxForce);
    oluacls_prop(L, "maxTorque", _b2FrictionJoint_GetMaxTorque, _b2FrictionJoint_SetMaxTorque);

    return 1;
}
OLUA_END_DECLS

static int _b2GearJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2GearJointDef()
    b2GearJointDef *ret = new b2GearJointDef();
    int num_ret = olua_push_object(L, ret, "b2.GearJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2GearJointDef_get_joint1(lua_State *L)
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

static int _b2GearJointDef_set_joint1(lua_State *L)
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

static int _b2GearJointDef_get_joint2(lua_State *L)
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

static int _b2GearJointDef_set_joint2(lua_State *L)
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

static int _b2GearJointDef_get_ratio(lua_State *L)
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

static int _b2GearJointDef_set_ratio(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2GearJointDef(lua_State *L)
{
    oluacls_class<b2GearJointDef, b2JointDef>(L, "b2.GearJointDef");
    oluacls_func(L, "new", _b2GearJointDef_new);
    oluacls_prop(L, "joint1", _b2GearJointDef_get_joint1, _b2GearJointDef_set_joint1);
    oluacls_prop(L, "joint2", _b2GearJointDef_get_joint2, _b2GearJointDef_set_joint2);
    oluacls_prop(L, "ratio", _b2GearJointDef_get_ratio, _b2GearJointDef_set_ratio);

    return 1;
}
OLUA_END_DECLS

static int _b2GearJoint___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2GearJoint *)olua_toobj(L, 1, "b2.GearJoint");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2GearJoint_GetJoint1(lua_State *L)
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

static int _b2GearJoint_GetJoint2(lua_State *L)
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

static int _b2GearJoint_GetRatio(lua_State *L)
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

static int _b2GearJoint_SetRatio(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2GearJoint(lua_State *L)
{
    oluacls_class<b2GearJoint, b2Joint>(L, "b2.GearJoint");
    oluacls_func(L, "__gc", _b2GearJoint___gc);
    oluacls_func(L, "getJoint1", _b2GearJoint_GetJoint1);
    oluacls_func(L, "getJoint2", _b2GearJoint_GetJoint2);
    oluacls_func(L, "getRatio", _b2GearJoint_GetRatio);
    oluacls_func(L, "setRatio", _b2GearJoint_SetRatio);
    oluacls_prop(L, "joint1", _b2GearJoint_GetJoint1, nullptr);
    oluacls_prop(L, "joint2", _b2GearJoint_GetJoint2, nullptr);
    oluacls_prop(L, "ratio", _b2GearJoint_GetRatio, _b2GearJoint_SetRatio);

    return 1;
}
OLUA_END_DECLS

static int _b2MotorJointDef_Initialize(lua_State *L)
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

static int _b2MotorJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2MotorJointDef()
    b2MotorJointDef *ret = new b2MotorJointDef();
    int num_ret = olua_push_object(L, ret, "b2.MotorJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2MotorJointDef_get_angularOffset(lua_State *L)
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

static int _b2MotorJointDef_set_angularOffset(lua_State *L)
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

static int _b2MotorJointDef_get_correctionFactor(lua_State *L)
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

static int _b2MotorJointDef_set_correctionFactor(lua_State *L)
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

static int _b2MotorJointDef_get_linearOffset(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.MotorJointDef");

    // b2Vec2 linearOffset
    b2Vec2 &ret = self->linearOffset;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2MotorJointDef_set_linearOffset(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJointDef *self = nullptr;
    b2Vec2 arg1;       /** linearOffset */

    olua_to_object(L, 1, &self, "b2.MotorJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 linearOffset
    self->linearOffset = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2MotorJointDef_get_maxForce(lua_State *L)
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

static int _b2MotorJointDef_set_maxForce(lua_State *L)
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

static int _b2MotorJointDef_get_maxTorque(lua_State *L)
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

static int _b2MotorJointDef_set_maxTorque(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2MotorJointDef(lua_State *L)
{
    oluacls_class<b2MotorJointDef, b2JointDef>(L, "b2.MotorJointDef");
    oluacls_func(L, "initialize", _b2MotorJointDef_Initialize);
    oluacls_func(L, "new", _b2MotorJointDef_new);
    oluacls_prop(L, "angularOffset", _b2MotorJointDef_get_angularOffset, _b2MotorJointDef_set_angularOffset);
    oluacls_prop(L, "correctionFactor", _b2MotorJointDef_get_correctionFactor, _b2MotorJointDef_set_correctionFactor);
    oluacls_prop(L, "linearOffset", _b2MotorJointDef_get_linearOffset, _b2MotorJointDef_set_linearOffset);
    oluacls_prop(L, "maxForce", _b2MotorJointDef_get_maxForce, _b2MotorJointDef_set_maxForce);
    oluacls_prop(L, "maxTorque", _b2MotorJointDef_get_maxTorque, _b2MotorJointDef_set_maxTorque);

    return 1;
}
OLUA_END_DECLS

static int _b2MotorJoint___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2MotorJoint *)olua_toobj(L, 1, "b2.MotorJoint");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2MotorJoint_GetAngularOffset(lua_State *L)
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

static int _b2MotorJoint_GetCorrectionFactor(lua_State *L)
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

static int _b2MotorJoint_GetLinearOffset(lua_State *L)
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

static int _b2MotorJoint_GetMaxForce(lua_State *L)
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

static int _b2MotorJoint_GetMaxTorque(lua_State *L)
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

static int _b2MotorJoint_SetAngularOffset(lua_State *L)
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

static int _b2MotorJoint_SetCorrectionFactor(lua_State *L)
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

static int _b2MotorJoint_SetLinearOffset(lua_State *L)
{
    olua_startinvoke(L);

    b2MotorJoint *self = nullptr;
    b2Vec2 arg1;       /** linearOffset */

    olua_to_object(L, 1, &self, "b2.MotorJoint");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // void SetLinearOffset(const b2Vec2 &linearOffset)
    self->SetLinearOffset(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2MotorJoint_SetMaxForce(lua_State *L)
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

static int _b2MotorJoint_SetMaxTorque(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2MotorJoint(lua_State *L)
{
    oluacls_class<b2MotorJoint, b2Joint>(L, "b2.MotorJoint");
    oluacls_func(L, "__gc", _b2MotorJoint___gc);
    oluacls_func(L, "getAngularOffset", _b2MotorJoint_GetAngularOffset);
    oluacls_func(L, "getCorrectionFactor", _b2MotorJoint_GetCorrectionFactor);
    oluacls_func(L, "getLinearOffset", _b2MotorJoint_GetLinearOffset);
    oluacls_func(L, "getMaxForce", _b2MotorJoint_GetMaxForce);
    oluacls_func(L, "getMaxTorque", _b2MotorJoint_GetMaxTorque);
    oluacls_func(L, "setAngularOffset", _b2MotorJoint_SetAngularOffset);
    oluacls_func(L, "setCorrectionFactor", _b2MotorJoint_SetCorrectionFactor);
    oluacls_func(L, "setLinearOffset", _b2MotorJoint_SetLinearOffset);
    oluacls_func(L, "setMaxForce", _b2MotorJoint_SetMaxForce);
    oluacls_func(L, "setMaxTorque", _b2MotorJoint_SetMaxTorque);
    oluacls_prop(L, "angularOffset", _b2MotorJoint_GetAngularOffset, _b2MotorJoint_SetAngularOffset);
    oluacls_prop(L, "correctionFactor", _b2MotorJoint_GetCorrectionFactor, _b2MotorJoint_SetCorrectionFactor);
    oluacls_prop(L, "linearOffset", _b2MotorJoint_GetLinearOffset, _b2MotorJoint_SetLinearOffset);
    oluacls_prop(L, "maxForce", _b2MotorJoint_GetMaxForce, _b2MotorJoint_SetMaxForce);
    oluacls_prop(L, "maxTorque", _b2MotorJoint_GetMaxTorque, _b2MotorJoint_SetMaxTorque);

    return 1;
}
OLUA_END_DECLS

static int _b2MouseJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2MouseJointDef()
    b2MouseJointDef *ret = new b2MouseJointDef();
    int num_ret = olua_push_object(L, ret, "b2.MouseJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2MouseJointDef_get_damping(lua_State *L)
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

static int _b2MouseJointDef_set_damping(lua_State *L)
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

static int _b2MouseJointDef_get_maxForce(lua_State *L)
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

static int _b2MouseJointDef_set_maxForce(lua_State *L)
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

static int _b2MouseJointDef_get_stiffness(lua_State *L)
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

static int _b2MouseJointDef_set_stiffness(lua_State *L)
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

static int _b2MouseJointDef_get_target(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.MouseJointDef");

    // b2Vec2 target
    b2Vec2 &ret = self->target;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2MouseJointDef_set_target(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJointDef *self = nullptr;
    b2Vec2 arg1;       /** target */

    olua_to_object(L, 1, &self, "b2.MouseJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 target
    self->target = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2MouseJointDef(lua_State *L)
{
    oluacls_class<b2MouseJointDef, b2JointDef>(L, "b2.MouseJointDef");
    oluacls_func(L, "new", _b2MouseJointDef_new);
    oluacls_prop(L, "damping", _b2MouseJointDef_get_damping, _b2MouseJointDef_set_damping);
    oluacls_prop(L, "maxForce", _b2MouseJointDef_get_maxForce, _b2MouseJointDef_set_maxForce);
    oluacls_prop(L, "stiffness", _b2MouseJointDef_get_stiffness, _b2MouseJointDef_set_stiffness);
    oluacls_prop(L, "target", _b2MouseJointDef_get_target, _b2MouseJointDef_set_target);

    return 1;
}
OLUA_END_DECLS

static int _b2MouseJoint___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2MouseJoint *)olua_toobj(L, 1, "b2.MouseJoint");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2MouseJoint_GetDamping(lua_State *L)
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

static int _b2MouseJoint_GetMaxForce(lua_State *L)
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

static int _b2MouseJoint_GetStiffness(lua_State *L)
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

static int _b2MouseJoint_GetTarget(lua_State *L)
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

static int _b2MouseJoint_SetDamping(lua_State *L)
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

static int _b2MouseJoint_SetMaxForce(lua_State *L)
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

static int _b2MouseJoint_SetStiffness(lua_State *L)
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

static int _b2MouseJoint_SetTarget(lua_State *L)
{
    olua_startinvoke(L);

    b2MouseJoint *self = nullptr;
    b2Vec2 arg1;       /** target */

    olua_to_object(L, 1, &self, "b2.MouseJoint");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // void SetTarget(const b2Vec2 &target)
    self->SetTarget(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2MouseJoint(lua_State *L)
{
    oluacls_class<b2MouseJoint, b2Joint>(L, "b2.MouseJoint");
    oluacls_func(L, "__gc", _b2MouseJoint___gc);
    oluacls_func(L, "getDamping", _b2MouseJoint_GetDamping);
    oluacls_func(L, "getMaxForce", _b2MouseJoint_GetMaxForce);
    oluacls_func(L, "getStiffness", _b2MouseJoint_GetStiffness);
    oluacls_func(L, "getTarget", _b2MouseJoint_GetTarget);
    oluacls_func(L, "setDamping", _b2MouseJoint_SetDamping);
    oluacls_func(L, "setMaxForce", _b2MouseJoint_SetMaxForce);
    oluacls_func(L, "setStiffness", _b2MouseJoint_SetStiffness);
    oluacls_func(L, "setTarget", _b2MouseJoint_SetTarget);
    oluacls_prop(L, "damping", _b2MouseJoint_GetDamping, _b2MouseJoint_SetDamping);
    oluacls_prop(L, "maxForce", _b2MouseJoint_GetMaxForce, _b2MouseJoint_SetMaxForce);
    oluacls_prop(L, "stiffness", _b2MouseJoint_GetStiffness, _b2MouseJoint_SetStiffness);
    oluacls_prop(L, "target", _b2MouseJoint_GetTarget, _b2MouseJoint_SetTarget);

    return 1;
}
OLUA_END_DECLS

static int _b2PrismaticJointDef_Initialize(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;
    b2Body *arg1 = nullptr;       /** bodyA */
    b2Body *arg2 = nullptr;       /** bodyB */
    b2Vec2 arg3;       /** anchor */
    b2Vec2 arg4;       /** axis */

    olua_to_object(L, 1, &self, "b2.PrismaticJointDef");
    olua_check_object(L, 2, &arg1, "b2.Body");
    olua_check_object(L, 3, &arg2, "b2.Body");
    olua_check_object(L, 4, &arg3, "b2.Vec2");
    olua_check_object(L, 5, &arg4, "b2.Vec2");

    // void Initialize(b2Body *bodyA, b2Body *bodyB, const b2Vec2 &anchor, const b2Vec2 &axis)
    self->Initialize(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _b2PrismaticJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2PrismaticJointDef()
    b2PrismaticJointDef *ret = new b2PrismaticJointDef();
    int num_ret = olua_push_object(L, ret, "b2.PrismaticJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PrismaticJointDef_get_enableLimit(lua_State *L)
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

static int _b2PrismaticJointDef_set_enableLimit(lua_State *L)
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

static int _b2PrismaticJointDef_get_enableMotor(lua_State *L)
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

static int _b2PrismaticJointDef_set_enableMotor(lua_State *L)
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

static int _b2PrismaticJointDef_get_localAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PrismaticJointDef");

    // b2Vec2 localAnchorA
    b2Vec2 &ret = self->localAnchorA;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PrismaticJointDef_set_localAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAnchorA */

    olua_to_object(L, 1, &self, "b2.PrismaticJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAnchorA
    self->localAnchorA = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2PrismaticJointDef_get_localAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PrismaticJointDef");

    // b2Vec2 localAnchorB
    b2Vec2 &ret = self->localAnchorB;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PrismaticJointDef_set_localAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAnchorB */

    olua_to_object(L, 1, &self, "b2.PrismaticJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAnchorB
    self->localAnchorB = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2PrismaticJointDef_get_localAxisA(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PrismaticJointDef");

    // b2Vec2 localAxisA
    b2Vec2 &ret = self->localAxisA;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PrismaticJointDef_set_localAxisA(lua_State *L)
{
    olua_startinvoke(L);

    b2PrismaticJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAxisA */

    olua_to_object(L, 1, &self, "b2.PrismaticJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAxisA
    self->localAxisA = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2PrismaticJointDef_get_lowerTranslation(lua_State *L)
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

static int _b2PrismaticJointDef_set_lowerTranslation(lua_State *L)
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

static int _b2PrismaticJointDef_get_maxMotorForce(lua_State *L)
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

static int _b2PrismaticJointDef_set_maxMotorForce(lua_State *L)
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

static int _b2PrismaticJointDef_get_motorSpeed(lua_State *L)
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

static int _b2PrismaticJointDef_set_motorSpeed(lua_State *L)
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

static int _b2PrismaticJointDef_get_referenceAngle(lua_State *L)
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

static int _b2PrismaticJointDef_set_referenceAngle(lua_State *L)
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

static int _b2PrismaticJointDef_get_upperTranslation(lua_State *L)
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

static int _b2PrismaticJointDef_set_upperTranslation(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2PrismaticJointDef(lua_State *L)
{
    oluacls_class<b2PrismaticJointDef, b2JointDef>(L, "b2.PrismaticJointDef");
    oluacls_func(L, "initialize", _b2PrismaticJointDef_Initialize);
    oluacls_func(L, "new", _b2PrismaticJointDef_new);
    oluacls_prop(L, "enableLimit", _b2PrismaticJointDef_get_enableLimit, _b2PrismaticJointDef_set_enableLimit);
    oluacls_prop(L, "enableMotor", _b2PrismaticJointDef_get_enableMotor, _b2PrismaticJointDef_set_enableMotor);
    oluacls_prop(L, "localAnchorA", _b2PrismaticJointDef_get_localAnchorA, _b2PrismaticJointDef_set_localAnchorA);
    oluacls_prop(L, "localAnchorB", _b2PrismaticJointDef_get_localAnchorB, _b2PrismaticJointDef_set_localAnchorB);
    oluacls_prop(L, "localAxisA", _b2PrismaticJointDef_get_localAxisA, _b2PrismaticJointDef_set_localAxisA);
    oluacls_prop(L, "lowerTranslation", _b2PrismaticJointDef_get_lowerTranslation, _b2PrismaticJointDef_set_lowerTranslation);
    oluacls_prop(L, "maxMotorForce", _b2PrismaticJointDef_get_maxMotorForce, _b2PrismaticJointDef_set_maxMotorForce);
    oluacls_prop(L, "motorSpeed", _b2PrismaticJointDef_get_motorSpeed, _b2PrismaticJointDef_set_motorSpeed);
    oluacls_prop(L, "referenceAngle", _b2PrismaticJointDef_get_referenceAngle, _b2PrismaticJointDef_set_referenceAngle);
    oluacls_prop(L, "upperTranslation", _b2PrismaticJointDef_get_upperTranslation, _b2PrismaticJointDef_set_upperTranslation);

    return 1;
}
OLUA_END_DECLS

static int _b2PrismaticJoint___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2PrismaticJoint *)olua_toobj(L, 1, "b2.PrismaticJoint");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2PrismaticJoint_EnableLimit(lua_State *L)
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

static int _b2PrismaticJoint_EnableMotor(lua_State *L)
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

static int _b2PrismaticJoint_GetJointSpeed(lua_State *L)
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

static int _b2PrismaticJoint_GetJointTranslation(lua_State *L)
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

static int _b2PrismaticJoint_GetLocalAnchorA(lua_State *L)
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

static int _b2PrismaticJoint_GetLocalAnchorB(lua_State *L)
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

static int _b2PrismaticJoint_GetLocalAxisA(lua_State *L)
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

static int _b2PrismaticJoint_GetLowerLimit(lua_State *L)
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

static int _b2PrismaticJoint_GetMaxMotorForce(lua_State *L)
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

static int _b2PrismaticJoint_GetMotorForce(lua_State *L)
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

static int _b2PrismaticJoint_GetMotorSpeed(lua_State *L)
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

static int _b2PrismaticJoint_GetReferenceAngle(lua_State *L)
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

static int _b2PrismaticJoint_GetUpperLimit(lua_State *L)
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

static int _b2PrismaticJoint_IsLimitEnabled(lua_State *L)
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

static int _b2PrismaticJoint_IsMotorEnabled(lua_State *L)
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

static int _b2PrismaticJoint_SetLimits(lua_State *L)
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

static int _b2PrismaticJoint_SetMaxMotorForce(lua_State *L)
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

static int _b2PrismaticJoint_SetMotorSpeed(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2PrismaticJoint(lua_State *L)
{
    oluacls_class<b2PrismaticJoint, b2Joint>(L, "b2.PrismaticJoint");
    oluacls_func(L, "__gc", _b2PrismaticJoint___gc);
    oluacls_func(L, "enableLimit", _b2PrismaticJoint_EnableLimit);
    oluacls_func(L, "enableMotor", _b2PrismaticJoint_EnableMotor);
    oluacls_func(L, "getJointSpeed", _b2PrismaticJoint_GetJointSpeed);
    oluacls_func(L, "getJointTranslation", _b2PrismaticJoint_GetJointTranslation);
    oluacls_func(L, "getLocalAnchorA", _b2PrismaticJoint_GetLocalAnchorA);
    oluacls_func(L, "getLocalAnchorB", _b2PrismaticJoint_GetLocalAnchorB);
    oluacls_func(L, "getLocalAxisA", _b2PrismaticJoint_GetLocalAxisA);
    oluacls_func(L, "getLowerLimit", _b2PrismaticJoint_GetLowerLimit);
    oluacls_func(L, "getMaxMotorForce", _b2PrismaticJoint_GetMaxMotorForce);
    oluacls_func(L, "getMotorForce", _b2PrismaticJoint_GetMotorForce);
    oluacls_func(L, "getMotorSpeed", _b2PrismaticJoint_GetMotorSpeed);
    oluacls_func(L, "getReferenceAngle", _b2PrismaticJoint_GetReferenceAngle);
    oluacls_func(L, "getUpperLimit", _b2PrismaticJoint_GetUpperLimit);
    oluacls_func(L, "isLimitEnabled", _b2PrismaticJoint_IsLimitEnabled);
    oluacls_func(L, "isMotorEnabled", _b2PrismaticJoint_IsMotorEnabled);
    oluacls_func(L, "setLimits", _b2PrismaticJoint_SetLimits);
    oluacls_func(L, "setMaxMotorForce", _b2PrismaticJoint_SetMaxMotorForce);
    oluacls_func(L, "setMotorSpeed", _b2PrismaticJoint_SetMotorSpeed);
    oluacls_prop(L, "jointSpeed", _b2PrismaticJoint_GetJointSpeed, nullptr);
    oluacls_prop(L, "jointTranslation", _b2PrismaticJoint_GetJointTranslation, nullptr);
    oluacls_prop(L, "limitEnabled", _b2PrismaticJoint_IsLimitEnabled, nullptr);
    oluacls_prop(L, "localAnchorA", _b2PrismaticJoint_GetLocalAnchorA, nullptr);
    oluacls_prop(L, "localAnchorB", _b2PrismaticJoint_GetLocalAnchorB, nullptr);
    oluacls_prop(L, "localAxisA", _b2PrismaticJoint_GetLocalAxisA, nullptr);
    oluacls_prop(L, "lowerLimit", _b2PrismaticJoint_GetLowerLimit, nullptr);
    oluacls_prop(L, "maxMotorForce", _b2PrismaticJoint_GetMaxMotorForce, _b2PrismaticJoint_SetMaxMotorForce);
    oluacls_prop(L, "motorEnabled", _b2PrismaticJoint_IsMotorEnabled, nullptr);
    oluacls_prop(L, "motorSpeed", _b2PrismaticJoint_GetMotorSpeed, _b2PrismaticJoint_SetMotorSpeed);
    oluacls_prop(L, "referenceAngle", _b2PrismaticJoint_GetReferenceAngle, nullptr);
    oluacls_prop(L, "upperLimit", _b2PrismaticJoint_GetUpperLimit, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _b2PulleyJointDef_Initialize(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;
    b2Body *arg1 = nullptr;       /** bodyA */
    b2Body *arg2 = nullptr;       /** bodyB */
    b2Vec2 arg3;       /** groundAnchorA */
    b2Vec2 arg4;       /** groundAnchorB */
    b2Vec2 arg5;       /** anchorA */
    b2Vec2 arg6;       /** anchorB */
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
    self->Initialize(arg1, arg2, arg3, arg4, arg5, arg6, arg7);

    olua_endinvoke(L);

    return 0;
}

static int _b2PulleyJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2PulleyJointDef()
    b2PulleyJointDef *ret = new b2PulleyJointDef();
    int num_ret = olua_push_object(L, ret, "b2.PulleyJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PulleyJointDef_get_groundAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PulleyJointDef");

    // b2Vec2 groundAnchorA
    b2Vec2 &ret = self->groundAnchorA;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PulleyJointDef_set_groundAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;
    b2Vec2 arg1;       /** groundAnchorA */

    olua_to_object(L, 1, &self, "b2.PulleyJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 groundAnchorA
    self->groundAnchorA = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2PulleyJointDef_get_groundAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PulleyJointDef");

    // b2Vec2 groundAnchorB
    b2Vec2 &ret = self->groundAnchorB;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PulleyJointDef_set_groundAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;
    b2Vec2 arg1;       /** groundAnchorB */

    olua_to_object(L, 1, &self, "b2.PulleyJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 groundAnchorB
    self->groundAnchorB = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2PulleyJointDef_get_lengthA(lua_State *L)
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

static int _b2PulleyJointDef_set_lengthA(lua_State *L)
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

static int _b2PulleyJointDef_get_lengthB(lua_State *L)
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

static int _b2PulleyJointDef_set_lengthB(lua_State *L)
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

static int _b2PulleyJointDef_get_localAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PulleyJointDef");

    // b2Vec2 localAnchorA
    b2Vec2 &ret = self->localAnchorA;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PulleyJointDef_set_localAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAnchorA */

    olua_to_object(L, 1, &self, "b2.PulleyJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAnchorA
    self->localAnchorA = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2PulleyJointDef_get_localAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PulleyJointDef");

    // b2Vec2 localAnchorB
    b2Vec2 &ret = self->localAnchorB;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PulleyJointDef_set_localAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAnchorB */

    olua_to_object(L, 1, &self, "b2.PulleyJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAnchorB
    self->localAnchorB = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2PulleyJointDef_get_ratio(lua_State *L)
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

static int _b2PulleyJointDef_set_ratio(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2PulleyJointDef(lua_State *L)
{
    oluacls_class<b2PulleyJointDef, b2JointDef>(L, "b2.PulleyJointDef");
    oluacls_func(L, "initialize", _b2PulleyJointDef_Initialize);
    oluacls_func(L, "new", _b2PulleyJointDef_new);
    oluacls_prop(L, "groundAnchorA", _b2PulleyJointDef_get_groundAnchorA, _b2PulleyJointDef_set_groundAnchorA);
    oluacls_prop(L, "groundAnchorB", _b2PulleyJointDef_get_groundAnchorB, _b2PulleyJointDef_set_groundAnchorB);
    oluacls_prop(L, "lengthA", _b2PulleyJointDef_get_lengthA, _b2PulleyJointDef_set_lengthA);
    oluacls_prop(L, "lengthB", _b2PulleyJointDef_get_lengthB, _b2PulleyJointDef_set_lengthB);
    oluacls_prop(L, "localAnchorA", _b2PulleyJointDef_get_localAnchorA, _b2PulleyJointDef_set_localAnchorA);
    oluacls_prop(L, "localAnchorB", _b2PulleyJointDef_get_localAnchorB, _b2PulleyJointDef_set_localAnchorB);
    oluacls_prop(L, "ratio", _b2PulleyJointDef_get_ratio, _b2PulleyJointDef_set_ratio);

    return 1;
}
OLUA_END_DECLS

static int _b2PulleyJoint___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2PulleyJoint *)olua_toobj(L, 1, "b2.PulleyJoint");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2PulleyJoint_GetCurrentLengthA(lua_State *L)
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

static int _b2PulleyJoint_GetCurrentLengthB(lua_State *L)
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

static int _b2PulleyJoint_GetGroundAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PulleyJoint");

    // b2Vec2 GetGroundAnchorA()
    b2Vec2 ret = self->GetGroundAnchorA();
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PulleyJoint_GetGroundAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2PulleyJoint *self = nullptr;

    olua_to_object(L, 1, &self, "b2.PulleyJoint");

    // b2Vec2 GetGroundAnchorB()
    b2Vec2 ret = self->GetGroundAnchorB();
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2PulleyJoint_GetLengthA(lua_State *L)
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

static int _b2PulleyJoint_GetLengthB(lua_State *L)
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

static int _b2PulleyJoint_GetRatio(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2PulleyJoint(lua_State *L)
{
    oluacls_class<b2PulleyJoint, b2Joint>(L, "b2.PulleyJoint");
    oluacls_func(L, "__gc", _b2PulleyJoint___gc);
    oluacls_func(L, "getCurrentLengthA", _b2PulleyJoint_GetCurrentLengthA);
    oluacls_func(L, "getCurrentLengthB", _b2PulleyJoint_GetCurrentLengthB);
    oluacls_func(L, "getGroundAnchorA", _b2PulleyJoint_GetGroundAnchorA);
    oluacls_func(L, "getGroundAnchorB", _b2PulleyJoint_GetGroundAnchorB);
    oluacls_func(L, "getLengthA", _b2PulleyJoint_GetLengthA);
    oluacls_func(L, "getLengthB", _b2PulleyJoint_GetLengthB);
    oluacls_func(L, "getRatio", _b2PulleyJoint_GetRatio);
    oluacls_prop(L, "currentLengthA", _b2PulleyJoint_GetCurrentLengthA, nullptr);
    oluacls_prop(L, "currentLengthB", _b2PulleyJoint_GetCurrentLengthB, nullptr);
    oluacls_prop(L, "groundAnchorA", _b2PulleyJoint_GetGroundAnchorA, nullptr);
    oluacls_prop(L, "groundAnchorB", _b2PulleyJoint_GetGroundAnchorB, nullptr);
    oluacls_prop(L, "lengthA", _b2PulleyJoint_GetLengthA, nullptr);
    oluacls_prop(L, "lengthB", _b2PulleyJoint_GetLengthB, nullptr);
    oluacls_prop(L, "ratio", _b2PulleyJoint_GetRatio, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _b2RevoluteJointDef_Initialize(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;
    b2Body *arg1 = nullptr;       /** bodyA */
    b2Body *arg2 = nullptr;       /** bodyB */
    b2Vec2 arg3;       /** anchor */

    olua_to_object(L, 1, &self, "b2.RevoluteJointDef");
    olua_check_object(L, 2, &arg1, "b2.Body");
    olua_check_object(L, 3, &arg2, "b2.Body");
    olua_check_object(L, 4, &arg3, "b2.Vec2");

    // void Initialize(b2Body *bodyA, b2Body *bodyB, const b2Vec2 &anchor)
    self->Initialize(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _b2RevoluteJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2RevoluteJointDef()
    b2RevoluteJointDef *ret = new b2RevoluteJointDef();
    int num_ret = olua_push_object(L, ret, "b2.RevoluteJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RevoluteJointDef_get_enableLimit(lua_State *L)
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

static int _b2RevoluteJointDef_set_enableLimit(lua_State *L)
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

static int _b2RevoluteJointDef_get_enableMotor(lua_State *L)
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

static int _b2RevoluteJointDef_set_enableMotor(lua_State *L)
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

static int _b2RevoluteJointDef_get_localAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RevoluteJointDef");

    // b2Vec2 localAnchorA
    b2Vec2 &ret = self->localAnchorA;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RevoluteJointDef_set_localAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAnchorA */

    olua_to_object(L, 1, &self, "b2.RevoluteJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAnchorA
    self->localAnchorA = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2RevoluteJointDef_get_localAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.RevoluteJointDef");

    // b2Vec2 localAnchorB
    b2Vec2 &ret = self->localAnchorB;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2RevoluteJointDef_set_localAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2RevoluteJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAnchorB */

    olua_to_object(L, 1, &self, "b2.RevoluteJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAnchorB
    self->localAnchorB = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2RevoluteJointDef_get_lowerAngle(lua_State *L)
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

static int _b2RevoluteJointDef_set_lowerAngle(lua_State *L)
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

static int _b2RevoluteJointDef_get_maxMotorTorque(lua_State *L)
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

static int _b2RevoluteJointDef_set_maxMotorTorque(lua_State *L)
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

static int _b2RevoluteJointDef_get_motorSpeed(lua_State *L)
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

static int _b2RevoluteJointDef_set_motorSpeed(lua_State *L)
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

static int _b2RevoluteJointDef_get_referenceAngle(lua_State *L)
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

static int _b2RevoluteJointDef_set_referenceAngle(lua_State *L)
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

static int _b2RevoluteJointDef_get_upperAngle(lua_State *L)
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

static int _b2RevoluteJointDef_set_upperAngle(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2RevoluteJointDef(lua_State *L)
{
    oluacls_class<b2RevoluteJointDef, b2JointDef>(L, "b2.RevoluteJointDef");
    oluacls_func(L, "initialize", _b2RevoluteJointDef_Initialize);
    oluacls_func(L, "new", _b2RevoluteJointDef_new);
    oluacls_prop(L, "enableLimit", _b2RevoluteJointDef_get_enableLimit, _b2RevoluteJointDef_set_enableLimit);
    oluacls_prop(L, "enableMotor", _b2RevoluteJointDef_get_enableMotor, _b2RevoluteJointDef_set_enableMotor);
    oluacls_prop(L, "localAnchorA", _b2RevoluteJointDef_get_localAnchorA, _b2RevoluteJointDef_set_localAnchorA);
    oluacls_prop(L, "localAnchorB", _b2RevoluteJointDef_get_localAnchorB, _b2RevoluteJointDef_set_localAnchorB);
    oluacls_prop(L, "lowerAngle", _b2RevoluteJointDef_get_lowerAngle, _b2RevoluteJointDef_set_lowerAngle);
    oluacls_prop(L, "maxMotorTorque", _b2RevoluteJointDef_get_maxMotorTorque, _b2RevoluteJointDef_set_maxMotorTorque);
    oluacls_prop(L, "motorSpeed", _b2RevoluteJointDef_get_motorSpeed, _b2RevoluteJointDef_set_motorSpeed);
    oluacls_prop(L, "referenceAngle", _b2RevoluteJointDef_get_referenceAngle, _b2RevoluteJointDef_set_referenceAngle);
    oluacls_prop(L, "upperAngle", _b2RevoluteJointDef_get_upperAngle, _b2RevoluteJointDef_set_upperAngle);

    return 1;
}
OLUA_END_DECLS

static int _b2RevoluteJoint___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2RevoluteJoint *)olua_toobj(L, 1, "b2.RevoluteJoint");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2RevoluteJoint_EnableLimit(lua_State *L)
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

static int _b2RevoluteJoint_EnableMotor(lua_State *L)
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

static int _b2RevoluteJoint_GetJointAngle(lua_State *L)
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

static int _b2RevoluteJoint_GetJointSpeed(lua_State *L)
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

static int _b2RevoluteJoint_GetLocalAnchorA(lua_State *L)
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

static int _b2RevoluteJoint_GetLocalAnchorB(lua_State *L)
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

static int _b2RevoluteJoint_GetLowerLimit(lua_State *L)
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

static int _b2RevoluteJoint_GetMaxMotorTorque(lua_State *L)
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

static int _b2RevoluteJoint_GetMotorSpeed(lua_State *L)
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

static int _b2RevoluteJoint_GetMotorTorque(lua_State *L)
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

static int _b2RevoluteJoint_GetReferenceAngle(lua_State *L)
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

static int _b2RevoluteJoint_GetUpperLimit(lua_State *L)
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

static int _b2RevoluteJoint_IsLimitEnabled(lua_State *L)
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

static int _b2RevoluteJoint_IsMotorEnabled(lua_State *L)
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

static int _b2RevoluteJoint_SetLimits(lua_State *L)
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

static int _b2RevoluteJoint_SetMaxMotorTorque(lua_State *L)
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

static int _b2RevoluteJoint_SetMotorSpeed(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2RevoluteJoint(lua_State *L)
{
    oluacls_class<b2RevoluteJoint, b2Joint>(L, "b2.RevoluteJoint");
    oluacls_func(L, "__gc", _b2RevoluteJoint___gc);
    oluacls_func(L, "enableLimit", _b2RevoluteJoint_EnableLimit);
    oluacls_func(L, "enableMotor", _b2RevoluteJoint_EnableMotor);
    oluacls_func(L, "getJointAngle", _b2RevoluteJoint_GetJointAngle);
    oluacls_func(L, "getJointSpeed", _b2RevoluteJoint_GetJointSpeed);
    oluacls_func(L, "getLocalAnchorA", _b2RevoluteJoint_GetLocalAnchorA);
    oluacls_func(L, "getLocalAnchorB", _b2RevoluteJoint_GetLocalAnchorB);
    oluacls_func(L, "getLowerLimit", _b2RevoluteJoint_GetLowerLimit);
    oluacls_func(L, "getMaxMotorTorque", _b2RevoluteJoint_GetMaxMotorTorque);
    oluacls_func(L, "getMotorSpeed", _b2RevoluteJoint_GetMotorSpeed);
    oluacls_func(L, "getMotorTorque", _b2RevoluteJoint_GetMotorTorque);
    oluacls_func(L, "getReferenceAngle", _b2RevoluteJoint_GetReferenceAngle);
    oluacls_func(L, "getUpperLimit", _b2RevoluteJoint_GetUpperLimit);
    oluacls_func(L, "isLimitEnabled", _b2RevoluteJoint_IsLimitEnabled);
    oluacls_func(L, "isMotorEnabled", _b2RevoluteJoint_IsMotorEnabled);
    oluacls_func(L, "setLimits", _b2RevoluteJoint_SetLimits);
    oluacls_func(L, "setMaxMotorTorque", _b2RevoluteJoint_SetMaxMotorTorque);
    oluacls_func(L, "setMotorSpeed", _b2RevoluteJoint_SetMotorSpeed);
    oluacls_prop(L, "jointAngle", _b2RevoluteJoint_GetJointAngle, nullptr);
    oluacls_prop(L, "jointSpeed", _b2RevoluteJoint_GetJointSpeed, nullptr);
    oluacls_prop(L, "limitEnabled", _b2RevoluteJoint_IsLimitEnabled, nullptr);
    oluacls_prop(L, "localAnchorA", _b2RevoluteJoint_GetLocalAnchorA, nullptr);
    oluacls_prop(L, "localAnchorB", _b2RevoluteJoint_GetLocalAnchorB, nullptr);
    oluacls_prop(L, "lowerLimit", _b2RevoluteJoint_GetLowerLimit, nullptr);
    oluacls_prop(L, "maxMotorTorque", _b2RevoluteJoint_GetMaxMotorTorque, _b2RevoluteJoint_SetMaxMotorTorque);
    oluacls_prop(L, "motorEnabled", _b2RevoluteJoint_IsMotorEnabled, nullptr);
    oluacls_prop(L, "motorSpeed", _b2RevoluteJoint_GetMotorSpeed, _b2RevoluteJoint_SetMotorSpeed);
    oluacls_prop(L, "referenceAngle", _b2RevoluteJoint_GetReferenceAngle, nullptr);
    oluacls_prop(L, "upperLimit", _b2RevoluteJoint_GetUpperLimit, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _b2WeldJointDef_Initialize(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJointDef *self = nullptr;
    b2Body *arg1 = nullptr;       /** bodyA */
    b2Body *arg2 = nullptr;       /** bodyB */
    b2Vec2 arg3;       /** anchor */

    olua_to_object(L, 1, &self, "b2.WeldJointDef");
    olua_check_object(L, 2, &arg1, "b2.Body");
    olua_check_object(L, 3, &arg2, "b2.Body");
    olua_check_object(L, 4, &arg3, "b2.Vec2");

    // void Initialize(b2Body *bodyA, b2Body *bodyB, const b2Vec2 &anchor)
    self->Initialize(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _b2WeldJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2WeldJointDef()
    b2WeldJointDef *ret = new b2WeldJointDef();
    int num_ret = olua_push_object(L, ret, "b2.WeldJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WeldJointDef_get_damping(lua_State *L)
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

static int _b2WeldJointDef_set_damping(lua_State *L)
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

static int _b2WeldJointDef_get_localAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WeldJointDef");

    // b2Vec2 localAnchorA
    b2Vec2 &ret = self->localAnchorA;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WeldJointDef_set_localAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAnchorA */

    olua_to_object(L, 1, &self, "b2.WeldJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAnchorA
    self->localAnchorA = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2WeldJointDef_get_localAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WeldJointDef");

    // b2Vec2 localAnchorB
    b2Vec2 &ret = self->localAnchorB;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WeldJointDef_set_localAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2WeldJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAnchorB */

    olua_to_object(L, 1, &self, "b2.WeldJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAnchorB
    self->localAnchorB = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2WeldJointDef_get_referenceAngle(lua_State *L)
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

static int _b2WeldJointDef_set_referenceAngle(lua_State *L)
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

static int _b2WeldJointDef_get_stiffness(lua_State *L)
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

static int _b2WeldJointDef_set_stiffness(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2WeldJointDef(lua_State *L)
{
    oluacls_class<b2WeldJointDef, b2JointDef>(L, "b2.WeldJointDef");
    oluacls_func(L, "initialize", _b2WeldJointDef_Initialize);
    oluacls_func(L, "new", _b2WeldJointDef_new);
    oluacls_prop(L, "damping", _b2WeldJointDef_get_damping, _b2WeldJointDef_set_damping);
    oluacls_prop(L, "localAnchorA", _b2WeldJointDef_get_localAnchorA, _b2WeldJointDef_set_localAnchorA);
    oluacls_prop(L, "localAnchorB", _b2WeldJointDef_get_localAnchorB, _b2WeldJointDef_set_localAnchorB);
    oluacls_prop(L, "referenceAngle", _b2WeldJointDef_get_referenceAngle, _b2WeldJointDef_set_referenceAngle);
    oluacls_prop(L, "stiffness", _b2WeldJointDef_get_stiffness, _b2WeldJointDef_set_stiffness);

    return 1;
}
OLUA_END_DECLS

static int _b2WeldJoint___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2WeldJoint *)olua_toobj(L, 1, "b2.WeldJoint");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2WeldJoint_GetDamping(lua_State *L)
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

static int _b2WeldJoint_GetLocalAnchorA(lua_State *L)
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

static int _b2WeldJoint_GetLocalAnchorB(lua_State *L)
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

static int _b2WeldJoint_GetReferenceAngle(lua_State *L)
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

static int _b2WeldJoint_GetStiffness(lua_State *L)
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

static int _b2WeldJoint_SetDamping(lua_State *L)
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

static int _b2WeldJoint_SetStiffness(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2WeldJoint(lua_State *L)
{
    oluacls_class<b2WeldJoint, b2Joint>(L, "b2.WeldJoint");
    oluacls_func(L, "__gc", _b2WeldJoint___gc);
    oluacls_func(L, "getDamping", _b2WeldJoint_GetDamping);
    oluacls_func(L, "getLocalAnchorA", _b2WeldJoint_GetLocalAnchorA);
    oluacls_func(L, "getLocalAnchorB", _b2WeldJoint_GetLocalAnchorB);
    oluacls_func(L, "getReferenceAngle", _b2WeldJoint_GetReferenceAngle);
    oluacls_func(L, "getStiffness", _b2WeldJoint_GetStiffness);
    oluacls_func(L, "setDamping", _b2WeldJoint_SetDamping);
    oluacls_func(L, "setStiffness", _b2WeldJoint_SetStiffness);
    oluacls_prop(L, "damping", _b2WeldJoint_GetDamping, _b2WeldJoint_SetDamping);
    oluacls_prop(L, "localAnchorA", _b2WeldJoint_GetLocalAnchorA, nullptr);
    oluacls_prop(L, "localAnchorB", _b2WeldJoint_GetLocalAnchorB, nullptr);
    oluacls_prop(L, "referenceAngle", _b2WeldJoint_GetReferenceAngle, nullptr);
    oluacls_prop(L, "stiffness", _b2WeldJoint_GetStiffness, _b2WeldJoint_SetStiffness);

    return 1;
}
OLUA_END_DECLS

static int _b2WheelJointDef_Initialize(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;
    b2Body *arg1 = nullptr;       /** bodyA */
    b2Body *arg2 = nullptr;       /** bodyB */
    b2Vec2 arg3;       /** anchor */
    b2Vec2 arg4;       /** axis */

    olua_to_object(L, 1, &self, "b2.WheelJointDef");
    olua_check_object(L, 2, &arg1, "b2.Body");
    olua_check_object(L, 3, &arg2, "b2.Body");
    olua_check_object(L, 4, &arg3, "b2.Vec2");
    olua_check_object(L, 5, &arg4, "b2.Vec2");

    // void Initialize(b2Body *bodyA, b2Body *bodyB, const b2Vec2 &anchor, const b2Vec2 &axis)
    self->Initialize(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _b2WheelJointDef_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2WheelJointDef()
    b2WheelJointDef *ret = new b2WheelJointDef();
    int num_ret = olua_push_object(L, ret, "b2.WheelJointDef");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJointDef_get_damping(lua_State *L)
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

static int _b2WheelJointDef_set_damping(lua_State *L)
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

static int _b2WheelJointDef_get_enableLimit(lua_State *L)
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

static int _b2WheelJointDef_set_enableLimit(lua_State *L)
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

static int _b2WheelJointDef_get_enableMotor(lua_State *L)
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

static int _b2WheelJointDef_set_enableMotor(lua_State *L)
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

static int _b2WheelJointDef_get_localAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WheelJointDef");

    // b2Vec2 localAnchorA
    b2Vec2 &ret = self->localAnchorA;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJointDef_set_localAnchorA(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAnchorA */

    olua_to_object(L, 1, &self, "b2.WheelJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAnchorA
    self->localAnchorA = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2WheelJointDef_get_localAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WheelJointDef");

    // b2Vec2 localAnchorB
    b2Vec2 &ret = self->localAnchorB;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJointDef_set_localAnchorB(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAnchorB */

    olua_to_object(L, 1, &self, "b2.WheelJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAnchorB
    self->localAnchorB = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2WheelJointDef_get_localAxisA(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WheelJointDef");

    // b2Vec2 localAxisA
    b2Vec2 &ret = self->localAxisA;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WheelJointDef_set_localAxisA(lua_State *L)
{
    olua_startinvoke(L);

    b2WheelJointDef *self = nullptr;
    b2Vec2 arg1;       /** localAxisA */

    olua_to_object(L, 1, &self, "b2.WheelJointDef");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localAxisA
    self->localAxisA = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2WheelJointDef_get_lowerTranslation(lua_State *L)
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

static int _b2WheelJointDef_set_lowerTranslation(lua_State *L)
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

static int _b2WheelJointDef_get_maxMotorTorque(lua_State *L)
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

static int _b2WheelJointDef_set_maxMotorTorque(lua_State *L)
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

static int _b2WheelJointDef_get_motorSpeed(lua_State *L)
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

static int _b2WheelJointDef_set_motorSpeed(lua_State *L)
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

static int _b2WheelJointDef_get_stiffness(lua_State *L)
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

static int _b2WheelJointDef_set_stiffness(lua_State *L)
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

static int _b2WheelJointDef_get_upperTranslation(lua_State *L)
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

static int _b2WheelJointDef_set_upperTranslation(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2WheelJointDef(lua_State *L)
{
    oluacls_class<b2WheelJointDef, b2JointDef>(L, "b2.WheelJointDef");
    oluacls_func(L, "initialize", _b2WheelJointDef_Initialize);
    oluacls_func(L, "new", _b2WheelJointDef_new);
    oluacls_prop(L, "damping", _b2WheelJointDef_get_damping, _b2WheelJointDef_set_damping);
    oluacls_prop(L, "enableLimit", _b2WheelJointDef_get_enableLimit, _b2WheelJointDef_set_enableLimit);
    oluacls_prop(L, "enableMotor", _b2WheelJointDef_get_enableMotor, _b2WheelJointDef_set_enableMotor);
    oluacls_prop(L, "localAnchorA", _b2WheelJointDef_get_localAnchorA, _b2WheelJointDef_set_localAnchorA);
    oluacls_prop(L, "localAnchorB", _b2WheelJointDef_get_localAnchorB, _b2WheelJointDef_set_localAnchorB);
    oluacls_prop(L, "localAxisA", _b2WheelJointDef_get_localAxisA, _b2WheelJointDef_set_localAxisA);
    oluacls_prop(L, "lowerTranslation", _b2WheelJointDef_get_lowerTranslation, _b2WheelJointDef_set_lowerTranslation);
    oluacls_prop(L, "maxMotorTorque", _b2WheelJointDef_get_maxMotorTorque, _b2WheelJointDef_set_maxMotorTorque);
    oluacls_prop(L, "motorSpeed", _b2WheelJointDef_get_motorSpeed, _b2WheelJointDef_set_motorSpeed);
    oluacls_prop(L, "stiffness", _b2WheelJointDef_get_stiffness, _b2WheelJointDef_set_stiffness);
    oluacls_prop(L, "upperTranslation", _b2WheelJointDef_get_upperTranslation, _b2WheelJointDef_set_upperTranslation);

    return 1;
}
OLUA_END_DECLS

static int _b2WheelJoint___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2WheelJoint *)olua_toobj(L, 1, "b2.WheelJoint");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2WheelJoint_EnableLimit(lua_State *L)
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

static int _b2WheelJoint_EnableMotor(lua_State *L)
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

static int _b2WheelJoint_GetDamping(lua_State *L)
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

static int _b2WheelJoint_GetJointAngle(lua_State *L)
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

static int _b2WheelJoint_GetJointAngularSpeed(lua_State *L)
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

static int _b2WheelJoint_GetJointLinearSpeed(lua_State *L)
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

static int _b2WheelJoint_GetJointTranslation(lua_State *L)
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

static int _b2WheelJoint_GetLocalAnchorA(lua_State *L)
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

static int _b2WheelJoint_GetLocalAnchorB(lua_State *L)
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

static int _b2WheelJoint_GetLocalAxisA(lua_State *L)
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

static int _b2WheelJoint_GetLowerLimit(lua_State *L)
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

static int _b2WheelJoint_GetMaxMotorTorque(lua_State *L)
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

static int _b2WheelJoint_GetMotorSpeed(lua_State *L)
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

static int _b2WheelJoint_GetMotorTorque(lua_State *L)
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

static int _b2WheelJoint_GetStiffness(lua_State *L)
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

static int _b2WheelJoint_GetUpperLimit(lua_State *L)
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

static int _b2WheelJoint_IsLimitEnabled(lua_State *L)
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

static int _b2WheelJoint_IsMotorEnabled(lua_State *L)
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

static int _b2WheelJoint_SetDamping(lua_State *L)
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

static int _b2WheelJoint_SetLimits(lua_State *L)
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

static int _b2WheelJoint_SetMaxMotorTorque(lua_State *L)
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

static int _b2WheelJoint_SetMotorSpeed(lua_State *L)
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

static int _b2WheelJoint_SetStiffness(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2WheelJoint(lua_State *L)
{
    oluacls_class<b2WheelJoint, b2Joint>(L, "b2.WheelJoint");
    oluacls_func(L, "__gc", _b2WheelJoint___gc);
    oluacls_func(L, "enableLimit", _b2WheelJoint_EnableLimit);
    oluacls_func(L, "enableMotor", _b2WheelJoint_EnableMotor);
    oluacls_func(L, "getDamping", _b2WheelJoint_GetDamping);
    oluacls_func(L, "getJointAngle", _b2WheelJoint_GetJointAngle);
    oluacls_func(L, "getJointAngularSpeed", _b2WheelJoint_GetJointAngularSpeed);
    oluacls_func(L, "getJointLinearSpeed", _b2WheelJoint_GetJointLinearSpeed);
    oluacls_func(L, "getJointTranslation", _b2WheelJoint_GetJointTranslation);
    oluacls_func(L, "getLocalAnchorA", _b2WheelJoint_GetLocalAnchorA);
    oluacls_func(L, "getLocalAnchorB", _b2WheelJoint_GetLocalAnchorB);
    oluacls_func(L, "getLocalAxisA", _b2WheelJoint_GetLocalAxisA);
    oluacls_func(L, "getLowerLimit", _b2WheelJoint_GetLowerLimit);
    oluacls_func(L, "getMaxMotorTorque", _b2WheelJoint_GetMaxMotorTorque);
    oluacls_func(L, "getMotorSpeed", _b2WheelJoint_GetMotorSpeed);
    oluacls_func(L, "getMotorTorque", _b2WheelJoint_GetMotorTorque);
    oluacls_func(L, "getStiffness", _b2WheelJoint_GetStiffness);
    oluacls_func(L, "getUpperLimit", _b2WheelJoint_GetUpperLimit);
    oluacls_func(L, "isLimitEnabled", _b2WheelJoint_IsLimitEnabled);
    oluacls_func(L, "isMotorEnabled", _b2WheelJoint_IsMotorEnabled);
    oluacls_func(L, "setDamping", _b2WheelJoint_SetDamping);
    oluacls_func(L, "setLimits", _b2WheelJoint_SetLimits);
    oluacls_func(L, "setMaxMotorTorque", _b2WheelJoint_SetMaxMotorTorque);
    oluacls_func(L, "setMotorSpeed", _b2WheelJoint_SetMotorSpeed);
    oluacls_func(L, "setStiffness", _b2WheelJoint_SetStiffness);
    oluacls_prop(L, "damping", _b2WheelJoint_GetDamping, _b2WheelJoint_SetDamping);
    oluacls_prop(L, "jointAngle", _b2WheelJoint_GetJointAngle, nullptr);
    oluacls_prop(L, "jointAngularSpeed", _b2WheelJoint_GetJointAngularSpeed, nullptr);
    oluacls_prop(L, "jointLinearSpeed", _b2WheelJoint_GetJointLinearSpeed, nullptr);
    oluacls_prop(L, "jointTranslation", _b2WheelJoint_GetJointTranslation, nullptr);
    oluacls_prop(L, "limitEnabled", _b2WheelJoint_IsLimitEnabled, nullptr);
    oluacls_prop(L, "localAnchorA", _b2WheelJoint_GetLocalAnchorA, nullptr);
    oluacls_prop(L, "localAnchorB", _b2WheelJoint_GetLocalAnchorB, nullptr);
    oluacls_prop(L, "localAxisA", _b2WheelJoint_GetLocalAxisA, nullptr);
    oluacls_prop(L, "lowerLimit", _b2WheelJoint_GetLowerLimit, nullptr);
    oluacls_prop(L, "maxMotorTorque", _b2WheelJoint_GetMaxMotorTorque, _b2WheelJoint_SetMaxMotorTorque);
    oluacls_prop(L, "motorEnabled", _b2WheelJoint_IsMotorEnabled, nullptr);
    oluacls_prop(L, "motorSpeed", _b2WheelJoint_GetMotorSpeed, _b2WheelJoint_SetMotorSpeed);
    oluacls_prop(L, "stiffness", _b2WheelJoint_GetStiffness, _b2WheelJoint_SetStiffness);
    oluacls_prop(L, "upperLimit", _b2WheelJoint_GetUpperLimit, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _b2JointEdge___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2JointEdge *)olua_toobj(L, 1, "b2.JointEdge");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2JointEdge___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2JointEdge *)olua_toobj(L, 1, "b2.JointEdge");
    olua_push_object(L, self, "b2.JointEdge");

    olua_endinvoke(L);

    return 1;
}

static int _b2JointEdge_get_joint(lua_State *L)
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

static int _b2JointEdge_set_joint(lua_State *L)
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

static int _b2JointEdge_get_next(lua_State *L)
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

static int _b2JointEdge_set_next(lua_State *L)
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

static int _b2JointEdge_get_other(lua_State *L)
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

static int _b2JointEdge_set_other(lua_State *L)
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

static int _b2JointEdge_get_prev(lua_State *L)
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

static int _b2JointEdge_set_prev(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2JointEdge(lua_State *L)
{
    oluacls_class<b2JointEdge>(L, "b2.JointEdge");
    oluacls_func(L, "__gc", _b2JointEdge___gc);
    oluacls_func(L, "__olua_move", _b2JointEdge___olua_move);
    oluacls_prop(L, "joint", _b2JointEdge_get_joint, _b2JointEdge_set_joint);
    oluacls_prop(L, "next", _b2JointEdge_get_next, _b2JointEdge_set_next);
    oluacls_prop(L, "other", _b2JointEdge_get_other, _b2JointEdge_set_other);
    oluacls_prop(L, "prev", _b2JointEdge_get_prev, _b2JointEdge_set_prev);

    return 1;
}
OLUA_END_DECLS

static int _b2JointUserData___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2JointUserData *)olua_toobj(L, 1, "b2.JointUserData");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2JointUserData___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2JointUserData *)olua_toobj(L, 1, "b2.JointUserData");
    olua_push_object(L, self, "b2.JointUserData");

    olua_endinvoke(L);

    return 1;
}

static int _b2JointUserData_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2JointUserData()
    b2JointUserData *ret = new b2JointUserData();
    int num_ret = olua_push_object(L, ret, "b2.JointUserData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2JointUserData_get_pointer(lua_State *L)
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

static int _b2JointUserData_set_pointer(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2JointUserData(lua_State *L)
{
    oluacls_class<b2JointUserData>(L, "b2.JointUserData");
    oluacls_func(L, "__gc", _b2JointUserData___gc);
    oluacls_func(L, "__olua_move", _b2JointUserData___olua_move);
    oluacls_func(L, "new", _b2JointUserData_new);
    oluacls_prop(L, "pointer", _b2JointUserData_get_pointer, _b2JointUserData_set_pointer);

    return 1;
}
OLUA_END_DECLS

static int _b2ContactEdge___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ContactEdge *)olua_toobj(L, 1, "b2.ContactEdge");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2ContactEdge___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ContactEdge *)olua_toobj(L, 1, "b2.ContactEdge");
    olua_push_object(L, self, "b2.ContactEdge");

    olua_endinvoke(L);

    return 1;
}

static int _b2ContactEdge_get_contact(lua_State *L)
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

static int _b2ContactEdge_set_contact(lua_State *L)
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

static int _b2ContactEdge_get_next(lua_State *L)
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

static int _b2ContactEdge_set_next(lua_State *L)
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

static int _b2ContactEdge_get_other(lua_State *L)
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

static int _b2ContactEdge_set_other(lua_State *L)
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

static int _b2ContactEdge_get_prev(lua_State *L)
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

static int _b2ContactEdge_set_prev(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2ContactEdge(lua_State *L)
{
    oluacls_class<b2ContactEdge>(L, "b2.ContactEdge");
    oluacls_func(L, "__gc", _b2ContactEdge___gc);
    oluacls_func(L, "__olua_move", _b2ContactEdge___olua_move);
    oluacls_prop(L, "contact", _b2ContactEdge_get_contact, _b2ContactEdge_set_contact);
    oluacls_prop(L, "next", _b2ContactEdge_get_next, _b2ContactEdge_set_next);
    oluacls_prop(L, "other", _b2ContactEdge_get_other, _b2ContactEdge_set_other);
    oluacls_prop(L, "prev", _b2ContactEdge_get_prev, _b2ContactEdge_set_prev);

    return 1;
}
OLUA_END_DECLS

static int _b2ContactManager___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ContactManager *)olua_toobj(L, 1, "b2.ContactManager");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2ContactManager___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ContactManager *)olua_toobj(L, 1, "b2.ContactManager");
    olua_push_object(L, self, "b2.ContactManager");

    olua_endinvoke(L);

    return 1;
}

static int _b2ContactManager_AddPair(lua_State *L)
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

static int _b2ContactManager_Collide(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactManager *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ContactManager");

    // void Collide()
    self->Collide();

    olua_endinvoke(L);

    return 0;
}

static int _b2ContactManager_Destroy(lua_State *L)
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

static int _b2ContactManager_FindNewContacts(lua_State *L)
{
    olua_startinvoke(L);

    b2ContactManager *self = nullptr;

    olua_to_object(L, 1, &self, "b2.ContactManager");

    // void FindNewContacts()
    self->FindNewContacts();

    olua_endinvoke(L);

    return 0;
}

static int _b2ContactManager_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2ContactManager()
    b2ContactManager *ret = new b2ContactManager();
    int num_ret = olua_push_object(L, ret, "b2.ContactManager");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2ContactManager(lua_State *L)
{
    oluacls_class<b2ContactManager>(L, "b2.ContactManager");
    oluacls_func(L, "__gc", _b2ContactManager___gc);
    oluacls_func(L, "__olua_move", _b2ContactManager___olua_move);
    oluacls_func(L, "addPair", _b2ContactManager_AddPair);
    oluacls_func(L, "collide", _b2ContactManager_Collide);
    oluacls_func(L, "destroy", _b2ContactManager_Destroy);
    oluacls_func(L, "findNewContacts", _b2ContactManager_FindNewContacts);
    oluacls_func(L, "new", _b2ContactManager_new);

    return 1;
}
OLUA_END_DECLS

static int _b2Profile___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Profile *)olua_toobj(L, 1, "b2.Profile");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2Profile___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Profile *)olua_toobj(L, 1, "b2.Profile");
    olua_push_object(L, self, "b2.Profile");

    olua_endinvoke(L);

    return 1;
}

static int _b2Profile_get_broadphase(lua_State *L)
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

static int _b2Profile_set_broadphase(lua_State *L)
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

static int _b2Profile_get_collide(lua_State *L)
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

static int _b2Profile_set_collide(lua_State *L)
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

static int _b2Profile_get_solve(lua_State *L)
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

static int _b2Profile_set_solve(lua_State *L)
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

static int _b2Profile_get_solveInit(lua_State *L)
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

static int _b2Profile_set_solveInit(lua_State *L)
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

static int _b2Profile_get_solvePosition(lua_State *L)
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

static int _b2Profile_set_solvePosition(lua_State *L)
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

static int _b2Profile_get_solveTOI(lua_State *L)
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

static int _b2Profile_set_solveTOI(lua_State *L)
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

static int _b2Profile_get_solveVelocity(lua_State *L)
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

static int _b2Profile_set_solveVelocity(lua_State *L)
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

static int _b2Profile_get_step(lua_State *L)
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

static int _b2Profile_set_step(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2Profile(lua_State *L)
{
    oluacls_class<b2Profile>(L, "b2.Profile");
    oluacls_func(L, "__gc", _b2Profile___gc);
    oluacls_func(L, "__olua_move", _b2Profile___olua_move);
    oluacls_prop(L, "broadphase", _b2Profile_get_broadphase, _b2Profile_set_broadphase);
    oluacls_prop(L, "collide", _b2Profile_get_collide, _b2Profile_set_collide);
    oluacls_prop(L, "solve", _b2Profile_get_solve, _b2Profile_set_solve);
    oluacls_prop(L, "solveInit", _b2Profile_get_solveInit, _b2Profile_set_solveInit);
    oluacls_prop(L, "solvePosition", _b2Profile_get_solvePosition, _b2Profile_set_solvePosition);
    oluacls_prop(L, "solveTOI", _b2Profile_get_solveTOI, _b2Profile_set_solveTOI);
    oluacls_prop(L, "solveVelocity", _b2Profile_get_solveVelocity, _b2Profile_set_solveVelocity);
    oluacls_prop(L, "step", _b2Profile_get_step, _b2Profile_set_step);

    return 1;
}
OLUA_END_DECLS

static int _b2BroadPhase___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2BroadPhase *)olua_toobj(L, 1, "b2.BroadPhase");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2BroadPhase___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2BroadPhase *)olua_toobj(L, 1, "b2.BroadPhase");
    olua_push_object(L, self, "b2.BroadPhase");

    olua_endinvoke(L);

    return 1;
}

static int _b2BroadPhase_CreateProxy(lua_State *L)
{
    olua_startinvoke(L);

    b2BroadPhase *self = nullptr;
    b2AABB arg1;       /** aabb */
    void *arg2 = nullptr;       /** userData */

    olua_to_object(L, 1, &self, "b2.BroadPhase");
    olua_check_object(L, 2, &arg1, "b2.AABB");
    olua_check_object(L, 3, &arg2, "void *");

    // int32 CreateProxy(const b2AABB &aabb, void *userData)
    int32 ret = self->CreateProxy(arg1, arg2);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BroadPhase_DestroyProxy(lua_State *L)
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

static int _b2BroadPhase_GetFatAABB(lua_State *L)
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

static int _b2BroadPhase_GetProxyCount(lua_State *L)
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

static int _b2BroadPhase_GetTreeBalance(lua_State *L)
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

static int _b2BroadPhase_GetTreeHeight(lua_State *L)
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

static int _b2BroadPhase_GetTreeQuality(lua_State *L)
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

static int _b2BroadPhase_GetUserData(lua_State *L)
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

static int _b2BroadPhase_MoveProxy(lua_State *L)
{
    olua_startinvoke(L);

    b2BroadPhase *self = nullptr;
    int32 arg1 = 0;       /** proxyId */
    b2AABB arg2;       /** aabb */
    b2Vec2 arg3;       /** displacement */

    olua_to_object(L, 1, &self, "b2.BroadPhase");
    olua_check_integer(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "b2.AABB");
    olua_check_object(L, 4, &arg3, "b2.Vec2");

    // void MoveProxy(int32 proxyId, const b2AABB &aabb, const b2Vec2 &displacement)
    self->MoveProxy(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _b2BroadPhase_new(lua_State *L)
{
    olua_startinvoke(L);

    // b2BroadPhase()
    b2BroadPhase *ret = new b2BroadPhase();
    int num_ret = olua_push_object(L, ret, "b2.BroadPhase");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2BroadPhase_ShiftOrigin(lua_State *L)
{
    olua_startinvoke(L);

    b2BroadPhase *self = nullptr;
    b2Vec2 arg1;       /** newOrigin */

    olua_to_object(L, 1, &self, "b2.BroadPhase");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // void ShiftOrigin(const b2Vec2 &newOrigin)
    self->ShiftOrigin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2BroadPhase_TestOverlap(lua_State *L)
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

static int _b2BroadPhase_TouchProxy(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2BroadPhase(lua_State *L)
{
    oluacls_class<b2BroadPhase>(L, "b2.BroadPhase");
    oluacls_func(L, "__gc", _b2BroadPhase___gc);
    oluacls_func(L, "__olua_move", _b2BroadPhase___olua_move);
    oluacls_func(L, "createProxy", _b2BroadPhase_CreateProxy);
    oluacls_func(L, "destroyProxy", _b2BroadPhase_DestroyProxy);
    oluacls_func(L, "getFatAABB", _b2BroadPhase_GetFatAABB);
    oluacls_func(L, "getProxyCount", _b2BroadPhase_GetProxyCount);
    oluacls_func(L, "getTreeBalance", _b2BroadPhase_GetTreeBalance);
    oluacls_func(L, "getTreeHeight", _b2BroadPhase_GetTreeHeight);
    oluacls_func(L, "getTreeQuality", _b2BroadPhase_GetTreeQuality);
    oluacls_func(L, "getUserData", _b2BroadPhase_GetUserData);
    oluacls_func(L, "moveProxy", _b2BroadPhase_MoveProxy);
    oluacls_func(L, "new", _b2BroadPhase_new);
    oluacls_func(L, "shiftOrigin", _b2BroadPhase_ShiftOrigin);
    oluacls_func(L, "testOverlap", _b2BroadPhase_TestOverlap);
    oluacls_func(L, "touchProxy", _b2BroadPhase_TouchProxy);
    oluacls_prop(L, "proxyCount", _b2BroadPhase_GetProxyCount, nullptr);
    oluacls_prop(L, "treeBalance", _b2BroadPhase_GetTreeBalance, nullptr);
    oluacls_prop(L, "treeHeight", _b2BroadPhase_GetTreeHeight, nullptr);
    oluacls_prop(L, "treeQuality", _b2BroadPhase_GetTreeQuality, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _b2AABB___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2AABB *)olua_toobj(L, 1, "b2.AABB");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2AABB___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2AABB *)olua_toobj(L, 1, "b2.AABB");
    olua_push_object(L, self, "b2.AABB");

    olua_endinvoke(L);

    return 1;
}

static int _b2AABB_Combine$1(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;
    b2AABB arg1;       /** aabb */

    olua_to_object(L, 1, &self, "b2.AABB");
    olua_check_object(L, 2, &arg1, "b2.AABB");

    // void Combine(const b2AABB &aabb)
    self->Combine(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2AABB_Combine$2(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;
    b2AABB arg1;       /** aabb1 */
    b2AABB arg2;       /** aabb2 */

    olua_to_object(L, 1, &self, "b2.AABB");
    olua_check_object(L, 2, &arg1, "b2.AABB");
    olua_check_object(L, 3, &arg2, "b2.AABB");

    // void Combine(const b2AABB &aabb1, const b2AABB &aabb2)
    self->Combine(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _b2AABB_Combine(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_object(L, 2, "b2.AABB"))) {
            // void Combine(const b2AABB &aabb)
            return _b2AABB_Combine$1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 2, "b2.AABB")) && (olua_is_object(L, 3, "b2.AABB"))) {
            // void Combine(const b2AABB &aabb1, const b2AABB &aabb2)
            return _b2AABB_Combine$2(L);
        // }
    }

    luaL_error(L, "method 'b2AABB::Combine' not support '%d' arguments", num_args);

    return 0;
}

static int _b2AABB_Contains(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;
    b2AABB arg1;       /** aabb */

    olua_to_object(L, 1, &self, "b2.AABB");
    olua_check_object(L, 2, &arg1, "b2.AABB");

    // bool Contains(const b2AABB &aabb)
    bool ret = self->Contains(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2AABB_GetCenter(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;

    olua_to_object(L, 1, &self, "b2.AABB");

    // b2Vec2 GetCenter()
    b2Vec2 ret = self->GetCenter();
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2AABB_GetExtents(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;

    olua_to_object(L, 1, &self, "b2.AABB");

    // b2Vec2 GetExtents()
    b2Vec2 ret = self->GetExtents();
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2AABB_GetPerimeter(lua_State *L)
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

static int _b2AABB_IsValid(lua_State *L)
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

static int _b2AABB_RayCast(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;
    b2RayCastOutput *arg1 = nullptr;       /** output */
    b2RayCastInput arg2;       /** input */

    olua_to_object(L, 1, &self, "b2.AABB");
    olua_check_object(L, 2, &arg1, "b2.RayCastOutput");
    olua_check_object(L, 3, &arg2, "b2.RayCastInput");

    // bool RayCast(b2RayCastOutput *output, const b2RayCastInput &input)
    bool ret = self->RayCast(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2AABB_get_lowerBound(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;

    olua_to_object(L, 1, &self, "b2.AABB");

    // b2Vec2 lowerBound
    b2Vec2 &ret = self->lowerBound;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2AABB_set_lowerBound(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;
    b2Vec2 arg1;       /** lowerBound */

    olua_to_object(L, 1, &self, "b2.AABB");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 lowerBound
    self->lowerBound = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2AABB_get_upperBound(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;

    olua_to_object(L, 1, &self, "b2.AABB");

    // b2Vec2 upperBound
    b2Vec2 &ret = self->upperBound;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2AABB_set_upperBound(lua_State *L)
{
    olua_startinvoke(L);

    b2AABB *self = nullptr;
    b2Vec2 arg1;       /** upperBound */

    olua_to_object(L, 1, &self, "b2.AABB");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 upperBound
    self->upperBound = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2AABB(lua_State *L)
{
    oluacls_class<b2AABB>(L, "b2.AABB");
    oluacls_func(L, "__gc", _b2AABB___gc);
    oluacls_func(L, "__olua_move", _b2AABB___olua_move);
    oluacls_func(L, "combine", _b2AABB_Combine);
    oluacls_func(L, "contains", _b2AABB_Contains);
    oluacls_func(L, "getCenter", _b2AABB_GetCenter);
    oluacls_func(L, "getExtents", _b2AABB_GetExtents);
    oluacls_func(L, "getPerimeter", _b2AABB_GetPerimeter);
    oluacls_func(L, "isValid", _b2AABB_IsValid);
    oluacls_func(L, "rayCast", _b2AABB_RayCast);
    oluacls_prop(L, "center", _b2AABB_GetCenter, nullptr);
    oluacls_prop(L, "extents", _b2AABB_GetExtents, nullptr);
    oluacls_prop(L, "perimeter", _b2AABB_GetPerimeter, nullptr);
    oluacls_prop(L, "valid", _b2AABB_IsValid, nullptr);
    oluacls_prop(L, "lowerBound", _b2AABB_get_lowerBound, _b2AABB_set_lowerBound);
    oluacls_prop(L, "upperBound", _b2AABB_get_upperBound, _b2AABB_set_upperBound);

    return 1;
}
OLUA_END_DECLS

static int _b2Contact___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Contact *)olua_toobj(L, 1, "b2.Contact");
    olua_push_object(L, self, "b2.Contact");

    olua_endinvoke(L);

    return 1;
}

static int _b2Contact_Evaluate(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;
    b2Manifold *arg1 = nullptr;       /** manifold */
    b2Transform arg2;       /** xfA */
    b2Transform arg3;       /** xfB */

    olua_to_object(L, 1, &self, "b2.Contact");
    olua_check_object(L, 2, &arg1, "b2.Manifold");
    olua_check_object(L, 3, &arg2, "b2.Transform");
    olua_check_object(L, 4, &arg3, "b2.Transform");

    // void Evaluate(b2Manifold *manifold, const b2Transform &xfA, const b2Transform &xfB)
    self->Evaluate(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _b2Contact_GetChildIndexA(lua_State *L)
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

static int _b2Contact_GetChildIndexB(lua_State *L)
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

static int _b2Contact_GetFixtureA(lua_State *L)
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

static int _b2Contact_GetFixtureB(lua_State *L)
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

static int _b2Contact_GetFriction(lua_State *L)
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

static int _b2Contact_GetManifold(lua_State *L)
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

static int _b2Contact_GetNext(lua_State *L)
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

static int _b2Contact_GetRestitution(lua_State *L)
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

static int _b2Contact_GetRestitutionThreshold(lua_State *L)
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

static int _b2Contact_GetTangentSpeed(lua_State *L)
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

static int _b2Contact_GetWorldManifold(lua_State *L)
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

static int _b2Contact_IsEnabled(lua_State *L)
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

static int _b2Contact_IsTouching(lua_State *L)
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

static int _b2Contact_ResetFriction(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Contact");

    // void ResetFriction()
    self->ResetFriction();

    olua_endinvoke(L);

    return 0;
}

static int _b2Contact_ResetRestitution(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Contact");

    // void ResetRestitution()
    self->ResetRestitution();

    olua_endinvoke(L);

    return 0;
}

static int _b2Contact_ResetRestitutionThreshold(lua_State *L)
{
    olua_startinvoke(L);

    b2Contact *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Contact");

    // void ResetRestitutionThreshold()
    self->ResetRestitutionThreshold();

    olua_endinvoke(L);

    return 0;
}

static int _b2Contact_SetEnabled(lua_State *L)
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

static int _b2Contact_SetFriction(lua_State *L)
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

static int _b2Contact_SetRestitution(lua_State *L)
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

static int _b2Contact_SetRestitutionThreshold(lua_State *L)
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

static int _b2Contact_SetTangentSpeed(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2Contact(lua_State *L)
{
    oluacls_class<b2Contact>(L, "b2.Contact");
    oluacls_func(L, "__olua_move", _b2Contact___olua_move);
    oluacls_func(L, "evaluate", _b2Contact_Evaluate);
    oluacls_func(L, "getChildIndexA", _b2Contact_GetChildIndexA);
    oluacls_func(L, "getChildIndexB", _b2Contact_GetChildIndexB);
    oluacls_func(L, "getFixtureA", _b2Contact_GetFixtureA);
    oluacls_func(L, "getFixtureB", _b2Contact_GetFixtureB);
    oluacls_func(L, "getFriction", _b2Contact_GetFriction);
    oluacls_func(L, "getManifold", _b2Contact_GetManifold);
    oluacls_func(L, "getNext", _b2Contact_GetNext);
    oluacls_func(L, "getRestitution", _b2Contact_GetRestitution);
    oluacls_func(L, "getRestitutionThreshold", _b2Contact_GetRestitutionThreshold);
    oluacls_func(L, "getTangentSpeed", _b2Contact_GetTangentSpeed);
    oluacls_func(L, "getWorldManifold", _b2Contact_GetWorldManifold);
    oluacls_func(L, "isEnabled", _b2Contact_IsEnabled);
    oluacls_func(L, "isTouching", _b2Contact_IsTouching);
    oluacls_func(L, "resetFriction", _b2Contact_ResetFriction);
    oluacls_func(L, "resetRestitution", _b2Contact_ResetRestitution);
    oluacls_func(L, "resetRestitutionThreshold", _b2Contact_ResetRestitutionThreshold);
    oluacls_func(L, "setEnabled", _b2Contact_SetEnabled);
    oluacls_func(L, "setFriction", _b2Contact_SetFriction);
    oluacls_func(L, "setRestitution", _b2Contact_SetRestitution);
    oluacls_func(L, "setRestitutionThreshold", _b2Contact_SetRestitutionThreshold);
    oluacls_func(L, "setTangentSpeed", _b2Contact_SetTangentSpeed);
    oluacls_prop(L, "childIndexA", _b2Contact_GetChildIndexA, nullptr);
    oluacls_prop(L, "childIndexB", _b2Contact_GetChildIndexB, nullptr);
    oluacls_prop(L, "enabled", _b2Contact_IsEnabled, _b2Contact_SetEnabled);
    oluacls_prop(L, "fixtureA", _b2Contact_GetFixtureA, nullptr);
    oluacls_prop(L, "fixtureB", _b2Contact_GetFixtureB, nullptr);
    oluacls_prop(L, "friction", _b2Contact_GetFriction, _b2Contact_SetFriction);
    oluacls_prop(L, "manifold", _b2Contact_GetManifold, nullptr);
    oluacls_prop(L, "next", _b2Contact_GetNext, nullptr);
    oluacls_prop(L, "restitution", _b2Contact_GetRestitution, _b2Contact_SetRestitution);
    oluacls_prop(L, "restitutionThreshold", _b2Contact_GetRestitutionThreshold, _b2Contact_SetRestitutionThreshold);
    oluacls_prop(L, "tangentSpeed", _b2Contact_GetTangentSpeed, _b2Contact_SetTangentSpeed);
    oluacls_prop(L, "touching", _b2Contact_IsTouching, nullptr);

    return 1;
}
OLUA_END_DECLS

static int _b2ContactImpulse___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ContactImpulse *)olua_toobj(L, 1, "b2.ContactImpulse");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2ContactImpulse___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2ContactImpulse *)olua_toobj(L, 1, "b2.ContactImpulse");
    olua_push_object(L, self, "b2.ContactImpulse");

    olua_endinvoke(L);

    return 1;
}

static int _b2ContactImpulse_get_count(lua_State *L)
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

static int _b2ContactImpulse_set_count(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2ContactImpulse(lua_State *L)
{
    oluacls_class<b2ContactImpulse>(L, "b2.ContactImpulse");
    oluacls_func(L, "__gc", _b2ContactImpulse___gc);
    oluacls_func(L, "__olua_move", _b2ContactImpulse___olua_move);
    oluacls_prop(L, "count", _b2ContactImpulse_get_count, _b2ContactImpulse_set_count);

    return 1;
}
OLUA_END_DECLS

static int _b2Manifold___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Manifold *)olua_toobj(L, 1, "b2.Manifold");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2Manifold___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2Manifold *)olua_toobj(L, 1, "b2.Manifold");
    olua_push_object(L, self, "b2.Manifold");

    olua_endinvoke(L);

    return 1;
}

static int _b2Manifold_get_localNormal(lua_State *L)
{
    olua_startinvoke(L);

    b2Manifold *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Manifold");

    // b2Vec2 localNormal
    b2Vec2 &ret = self->localNormal;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Manifold_set_localNormal(lua_State *L)
{
    olua_startinvoke(L);

    b2Manifold *self = nullptr;
    b2Vec2 arg1;       /** localNormal */

    olua_to_object(L, 1, &self, "b2.Manifold");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localNormal
    self->localNormal = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2Manifold_get_localPoint(lua_State *L)
{
    olua_startinvoke(L);

    b2Manifold *self = nullptr;

    olua_to_object(L, 1, &self, "b2.Manifold");

    // b2Vec2 localPoint
    b2Vec2 &ret = self->localPoint;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2Manifold_set_localPoint(lua_State *L)
{
    olua_startinvoke(L);

    b2Manifold *self = nullptr;
    b2Vec2 arg1;       /** localPoint */

    olua_to_object(L, 1, &self, "b2.Manifold");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 localPoint
    self->localPoint = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _b2Manifold_get_pointCount(lua_State *L)
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

static int _b2Manifold_set_pointCount(lua_State *L)
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

static int _b2Manifold_get_type(lua_State *L)
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

static int _b2Manifold_set_type(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2Manifold(lua_State *L)
{
    oluacls_class<b2Manifold>(L, "b2.Manifold");
    oluacls_func(L, "__gc", _b2Manifold___gc);
    oluacls_func(L, "__olua_move", _b2Manifold___olua_move);
    oluacls_prop(L, "localNormal", _b2Manifold_get_localNormal, _b2Manifold_set_localNormal);
    oluacls_prop(L, "localPoint", _b2Manifold_get_localPoint, _b2Manifold_set_localPoint);
    oluacls_prop(L, "pointCount", _b2Manifold_get_pointCount, _b2Manifold_set_pointCount);
    oluacls_prop(L, "type", _b2Manifold_get_type, _b2Manifold_set_type);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2Manifold_Type(lua_State *L)
{
    oluacls_class<b2Manifold::Type>(L, "b2.Manifold.Type");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "circles", (lua_Integer)b2Manifold::Type::e_circles);
    oluacls_enum(L, "faceA", (lua_Integer)b2Manifold::Type::e_faceA);
    oluacls_enum(L, "faceB", (lua_Integer)b2Manifold::Type::e_faceB);

    return 1;
}
OLUA_END_DECLS

static int _b2World___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2World *)olua_toobj(L, 1, "b2.World");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2World___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2World *)olua_toobj(L, 1, "b2.World");
    olua_push_object(L, self, "b2.World");

    olua_endinvoke(L);

    return 1;
}

static int _b2World_ClearForces(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_object(L, 1, &self, "b2.World");

    // void ClearForces()
    self->ClearForces();

    olua_endinvoke(L);

    return 0;
}

static int _b2World_CreateBody(lua_State *L)
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

static int _b2World_CreateJoint(lua_State *L)
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

static int _b2World_DebugDraw(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_object(L, 1, &self, "b2.World");

    // void DebugDraw()
    self->DebugDraw();

    olua_endinvoke(L);

    return 0;
}

static int _b2World_DestroyBody(lua_State *L)
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

static int _b2World_DestroyJoint(lua_State *L)
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

static int _b2World_Dump(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_object(L, 1, &self, "b2.World");

    // void Dump()
    self->Dump();

    olua_endinvoke(L);

    return 0;
}

static int _b2World_GetAllowSleeping(lua_State *L)
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

static int _b2World_GetAutoClearForces(lua_State *L)
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

static int _b2World_GetBodyCount(lua_State *L)
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

static int _b2World_GetBodyList(lua_State *L)
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

static int _b2World_GetContactCount(lua_State *L)
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

static int _b2World_GetContactList(lua_State *L)
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

static int _b2World_GetContactManager(lua_State *L)
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

static int _b2World_GetContinuousPhysics(lua_State *L)
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

static int _b2World_GetGravity(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;

    olua_to_object(L, 1, &self, "b2.World");

    // b2Vec2 GetGravity()
    b2Vec2 ret = self->GetGravity();
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2World_GetJointCount(lua_State *L)
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

static int _b2World_GetJointList(lua_State *L)
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

static int _b2World_GetProfile(lua_State *L)
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

static int _b2World_GetProxyCount(lua_State *L)
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

static int _b2World_GetSubStepping(lua_State *L)
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

static int _b2World_GetTreeBalance(lua_State *L)
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

static int _b2World_GetTreeHeight(lua_State *L)
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

static int _b2World_GetTreeQuality(lua_State *L)
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

static int _b2World_GetWarmStarting(lua_State *L)
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

static int _b2World_IsLocked(lua_State *L)
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

static int _b2World_new(lua_State *L)
{
    olua_startinvoke(L);

    b2Vec2 arg1;       /** gravity */

    olua_check_object(L, 1, &arg1, "b2.Vec2");

    // b2World(const b2Vec2 &gravity)
    b2World *ret = new b2World(arg1);
    int num_ret = olua_push_object(L, ret, "b2.World");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _b2World_QueryAABB(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2QueryCallback *arg1 = nullptr;       /** callback */
    b2AABB arg2;       /** aabb */

    olua_to_object(L, 1, &self, "b2.World");
    olua_check_object(L, 2, &arg1, "b2.interface.QueryCallback");
    olua_check_object(L, 3, &arg2, "b2.AABB");

    // void QueryAABB(b2QueryCallback *callback, const b2AABB &aabb)
    self->QueryAABB(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _b2World_RayCast(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2RayCastCallback *arg1 = nullptr;       /** callback */
    b2Vec2 arg2;       /** point1 */
    b2Vec2 arg3;       /** point2 */

    olua_to_object(L, 1, &self, "b2.World");
    olua_check_object(L, 2, &arg1, "b2.interface.RayCastCallback");
    olua_check_object(L, 3, &arg2, "b2.Vec2");
    olua_check_object(L, 4, &arg3, "b2.Vec2");

    // void RayCast(b2RayCastCallback *callback, const b2Vec2 &point1, const b2Vec2 &point2)
    self->RayCast(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _b2World_SetAllowSleeping(lua_State *L)
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

static int _b2World_SetAutoClearForces(lua_State *L)
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

static int _b2World_SetContactFilter(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2ContactFilter *arg1 = nullptr;       /** filter */

    olua_to_object(L, 1, &self, "b2.World");
    olua_check_object(L, 2, &arg1, "b2.interface.ContactFilter");

    // void SetContactFilter(@addref(^) b2ContactFilter *filter)
    self->SetContactFilter(arg1);

    // insert code after call
    olua_addref(L, 1, "contactfilter", 2, OLUA_FLAG_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int _b2World_SetContactListener(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2ContactListener *arg1 = nullptr;       /** listener */

    olua_to_object(L, 1, &self, "b2.World");
    olua_check_object(L, 2, &arg1, "b2.interface.ContactListener");

    // void SetContactListener(@addref(^) b2ContactListener *listener)
    self->SetContactListener(arg1);

    // insert code after call
    olua_addref(L, 1, "contactlistener", 2, OLUA_FLAG_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int _b2World_SetContinuousPhysics(lua_State *L)
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

static int _b2World_SetDebugDraw(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2Draw *arg1 = nullptr;       /** debugDraw */

    olua_to_object(L, 1, &self, "b2.World");
    olua_check_object(L, 2, &arg1, "b2.interface.Draw");

    // void SetDebugDraw(@addref(^) b2Draw *debugDraw)
    self->SetDebugDraw(arg1);

    // insert code after call
    olua_addref(L, 1, "debugdraw", 2, OLUA_FLAG_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int _b2World_SetDestructionListener(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2DestructionListener *arg1 = nullptr;       /** listener */

    olua_to_object(L, 1, &self, "b2.World");
    olua_check_object(L, 2, &arg1, "b2.interface.DestructionListener");

    // void SetDestructionListener(@addref(^) b2DestructionListener *listener)
    self->SetDestructionListener(arg1);

    // insert code after call
    olua_addref(L, 1, "destructionlistener", 2, OLUA_FLAG_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int _b2World_SetGravity(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2Vec2 arg1;       /** gravity */

    olua_to_object(L, 1, &self, "b2.World");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // void SetGravity(const b2Vec2 &gravity)
    self->SetGravity(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2World_SetSubStepping(lua_State *L)
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

static int _b2World_SetWarmStarting(lua_State *L)
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

static int _b2World_ShiftOrigin(lua_State *L)
{
    olua_startinvoke(L);

    b2World *self = nullptr;
    b2Vec2 arg1;       /** newOrigin */

    olua_to_object(L, 1, &self, "b2.World");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // void ShiftOrigin(const b2Vec2 &newOrigin)
    self->ShiftOrigin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _b2World_Step(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2World(lua_State *L)
{
    oluacls_class<b2World>(L, "b2.World");
    oluacls_func(L, "__gc", _b2World___gc);
    oluacls_func(L, "__olua_move", _b2World___olua_move);
    oluacls_func(L, "clearForces", _b2World_ClearForces);
    oluacls_func(L, "createBody", _b2World_CreateBody);
    oluacls_func(L, "createJoint", _b2World_CreateJoint);
    oluacls_func(L, "debugDraw", _b2World_DebugDraw);
    oluacls_func(L, "destroyBody", _b2World_DestroyBody);
    oluacls_func(L, "destroyJoint", _b2World_DestroyJoint);
    oluacls_func(L, "dump", _b2World_Dump);
    oluacls_func(L, "getAllowSleeping", _b2World_GetAllowSleeping);
    oluacls_func(L, "getAutoClearForces", _b2World_GetAutoClearForces);
    oluacls_func(L, "getBodyCount", _b2World_GetBodyCount);
    oluacls_func(L, "getBodyList", _b2World_GetBodyList);
    oluacls_func(L, "getContactCount", _b2World_GetContactCount);
    oluacls_func(L, "getContactList", _b2World_GetContactList);
    oluacls_func(L, "getContactManager", _b2World_GetContactManager);
    oluacls_func(L, "getContinuousPhysics", _b2World_GetContinuousPhysics);
    oluacls_func(L, "getGravity", _b2World_GetGravity);
    oluacls_func(L, "getJointCount", _b2World_GetJointCount);
    oluacls_func(L, "getJointList", _b2World_GetJointList);
    oluacls_func(L, "getProfile", _b2World_GetProfile);
    oluacls_func(L, "getProxyCount", _b2World_GetProxyCount);
    oluacls_func(L, "getSubStepping", _b2World_GetSubStepping);
    oluacls_func(L, "getTreeBalance", _b2World_GetTreeBalance);
    oluacls_func(L, "getTreeHeight", _b2World_GetTreeHeight);
    oluacls_func(L, "getTreeQuality", _b2World_GetTreeQuality);
    oluacls_func(L, "getWarmStarting", _b2World_GetWarmStarting);
    oluacls_func(L, "isLocked", _b2World_IsLocked);
    oluacls_func(L, "new", _b2World_new);
    oluacls_func(L, "queryAABB", _b2World_QueryAABB);
    oluacls_func(L, "rayCast", _b2World_RayCast);
    oluacls_func(L, "setAllowSleeping", _b2World_SetAllowSleeping);
    oluacls_func(L, "setAutoClearForces", _b2World_SetAutoClearForces);
    oluacls_func(L, "setContactFilter", _b2World_SetContactFilter);
    oluacls_func(L, "setContactListener", _b2World_SetContactListener);
    oluacls_func(L, "setContinuousPhysics", _b2World_SetContinuousPhysics);
    oluacls_func(L, "setDebugDraw", _b2World_SetDebugDraw);
    oluacls_func(L, "setDestructionListener", _b2World_SetDestructionListener);
    oluacls_func(L, "setGravity", _b2World_SetGravity);
    oluacls_func(L, "setSubStepping", _b2World_SetSubStepping);
    oluacls_func(L, "setWarmStarting", _b2World_SetWarmStarting);
    oluacls_func(L, "shiftOrigin", _b2World_ShiftOrigin);
    oluacls_func(L, "step", _b2World_Step);
    oluacls_prop(L, "allowSleeping", _b2World_GetAllowSleeping, _b2World_SetAllowSleeping);
    oluacls_prop(L, "autoClearForces", _b2World_GetAutoClearForces, _b2World_SetAutoClearForces);
    oluacls_prop(L, "bodyCount", _b2World_GetBodyCount, nullptr);
    oluacls_prop(L, "bodyList", _b2World_GetBodyList, nullptr);
    oluacls_prop(L, "contactCount", _b2World_GetContactCount, nullptr);
    oluacls_prop(L, "contactList", _b2World_GetContactList, nullptr);
    oluacls_prop(L, "contactManager", _b2World_GetContactManager, nullptr);
    oluacls_prop(L, "continuousPhysics", _b2World_GetContinuousPhysics, _b2World_SetContinuousPhysics);
    oluacls_prop(L, "gravity", _b2World_GetGravity, _b2World_SetGravity);
    oluacls_prop(L, "jointCount", _b2World_GetJointCount, nullptr);
    oluacls_prop(L, "jointList", _b2World_GetJointList, nullptr);
    oluacls_prop(L, "locked", _b2World_IsLocked, nullptr);
    oluacls_prop(L, "profile", _b2World_GetProfile, nullptr);
    oluacls_prop(L, "proxyCount", _b2World_GetProxyCount, nullptr);
    oluacls_prop(L, "subStepping", _b2World_GetSubStepping, _b2World_SetSubStepping);
    oluacls_prop(L, "treeBalance", _b2World_GetTreeBalance, nullptr);
    oluacls_prop(L, "treeHeight", _b2World_GetTreeHeight, nullptr);
    oluacls_prop(L, "treeQuality", _b2World_GetTreeQuality, nullptr);
    oluacls_prop(L, "warmStarting", _b2World_GetWarmStarting, _b2World_SetWarmStarting);

    return 1;
}
OLUA_END_DECLS

static int _b2WorldManifold___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2WorldManifold *)olua_toobj(L, 1, "b2.WorldManifold");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _b2WorldManifold___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (b2WorldManifold *)olua_toobj(L, 1, "b2.WorldManifold");
    olua_push_object(L, self, "b2.WorldManifold");

    olua_endinvoke(L);

    return 1;
}

static int _b2WorldManifold_Initialize(lua_State *L)
{
    olua_startinvoke(L);

    b2WorldManifold *self = nullptr;
    b2Manifold *arg1 = nullptr;       /** manifold */
    b2Transform arg2;       /** xfA */
    float arg3 = 0;       /** radiusA */
    b2Transform arg4;       /** xfB */
    float arg5 = 0;       /** radiusB */

    olua_to_object(L, 1, &self, "b2.WorldManifold");
    olua_check_object(L, 2, &arg1, "b2.Manifold");
    olua_check_object(L, 3, &arg2, "b2.Transform");
    olua_check_number(L, 4, &arg3);
    olua_check_object(L, 5, &arg4, "b2.Transform");
    olua_check_number(L, 6, &arg5);

    // void Initialize(const b2Manifold *manifold, const b2Transform &xfA, float radiusA, const b2Transform &xfB, float radiusB)
    self->Initialize(arg1, arg2, arg3, arg4, arg5);

    olua_endinvoke(L);

    return 0;
}

static int _b2WorldManifold_get_normal(lua_State *L)
{
    olua_startinvoke(L);

    b2WorldManifold *self = nullptr;

    olua_to_object(L, 1, &self, "b2.WorldManifold");

    // b2Vec2 normal
    b2Vec2 &ret = self->normal;
    int num_ret = olua_pushcopy_object(L, ret, "b2.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _b2WorldManifold_set_normal(lua_State *L)
{
    olua_startinvoke(L);

    b2WorldManifold *self = nullptr;
    b2Vec2 arg1;       /** normal */

    olua_to_object(L, 1, &self, "b2.WorldManifold");
    olua_check_object(L, 2, &arg1, "b2.Vec2");

    // b2Vec2 normal
    self->normal = arg1;

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_b2WorldManifold(lua_State *L)
{
    oluacls_class<b2WorldManifold>(L, "b2.WorldManifold");
    oluacls_func(L, "__gc", _b2WorldManifold___gc);
    oluacls_func(L, "__olua_move", _b2WorldManifold___olua_move);
    oluacls_func(L, "initialize", _b2WorldManifold_Initialize);
    oluacls_prop(L, "normal", _b2WorldManifold_get_normal, _b2WorldManifold_set_normal);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_box2d(lua_State *L)
{
    olua_require(L, "b2.Vec2", luaopen_b2Vec2);
    olua_require(L, "b2.Vec3", luaopen_b2Vec3);
    olua_require(L, "b2.ContactID", luaopen_b2ContactID);
    olua_require(L, "b2.ContactFeature", luaopen_b2ContactFeature);
    olua_require(L, "b2.Color", luaopen_b2Color);
    olua_require(L, "b2.FixtureUserData", luaopen_b2FixtureUserData);
    olua_require(L, "b2.Filter", luaopen_b2Filter);
    olua_require(L, "b2.ManifoldPoint", luaopen_b2ManifoldPoint);
    olua_require(L, "b2.Rot", luaopen_b2Rot);
    olua_require(L, "b2.interface.Draw", luaopen_b2Draw);
    olua_require(L, "b2.interface.DestructionListener", luaopen_b2DestructionListener);
    olua_require(L, "b2.interface.ContactFilter", luaopen_b2ContactFilter);
    olua_require(L, "b2.interface.ContactListener", luaopen_b2ContactListener);
    olua_require(L, "b2.interface.QueryCallback", luaopen_b2QueryCallback);
    olua_require(L, "b2.interface.RayCastCallback", luaopen_b2RayCastCallback);
    olua_require(L, "b2.Vec2Array", luaopen_box2d_Vec2Array);
    olua_require(L, "b2.DestructionListener", luaopen_box2d_DestructionListener);
    olua_require(L, "b2.ContactFilter", luaopen_box2d_ContactFilter);
    olua_require(L, "b2.ContactListener", luaopen_box2d_ContactListener);
    olua_require(L, "b2.QueryCallback", luaopen_box2d_QueryCallback);
    olua_require(L, "b2.RayCastCallback", luaopen_box2d_RayCastCallback);
    olua_require(L, "b2.DebugNode.Flags", luaopen_box2d_DebugNode_Flags);
    olua_require(L, "b2.DebugNode", luaopen_box2d_DebugNode);
    olua_require(L, "b2.MassData", luaopen_b2MassData);
    olua_require(L, "b2.Transform", luaopen_b2Transform);
    olua_require(L, "b2.RayCastInput", luaopen_b2RayCastInput);
    olua_require(L, "b2.RayCastOutput", luaopen_b2RayCastOutput);
    olua_require(L, "b2.Shape.Type", luaopen_b2Shape_Type);
    olua_require(L, "b2.Shape", luaopen_b2Shape);
    olua_require(L, "b2.PolygonShape", luaopen_b2PolygonShape);
    olua_require(L, "b2.EdgeShape", luaopen_b2EdgeShape);
    olua_require(L, "b2.CircleShape", luaopen_b2CircleShape);
    olua_require(L, "b2.ChainShape", luaopen_b2ChainShape);
    olua_require(L, "b2.BodyDef", luaopen_b2BodyDef);
    olua_require(L, "b2.BodyType", luaopen_b2BodyType);
    olua_require(L, "b2.Body", luaopen_b2Body);
    olua_require(L, "b2.BodyUserData", luaopen_b2BodyUserData);
    olua_require(L, "b2.FixtureDef", luaopen_b2FixtureDef);
    olua_require(L, "b2.Fixture", luaopen_b2Fixture);
    olua_require(L, "b2.JointDef", luaopen_b2JointDef);
    olua_require(L, "b2.JointType", luaopen_b2JointType);
    olua_require(L, "b2.Joint", luaopen_b2Joint);
    olua_require(L, "b2.DistanceJointDef", luaopen_b2DistanceJointDef);
    olua_require(L, "b2.DistanceJoint", luaopen_b2DistanceJoint);
    olua_require(L, "b2.FrictionJointDef", luaopen_b2FrictionJointDef);
    olua_require(L, "b2.FrictionJoint", luaopen_b2FrictionJoint);
    olua_require(L, "b2.GearJointDef", luaopen_b2GearJointDef);
    olua_require(L, "b2.GearJoint", luaopen_b2GearJoint);
    olua_require(L, "b2.MotorJointDef", luaopen_b2MotorJointDef);
    olua_require(L, "b2.MotorJoint", luaopen_b2MotorJoint);
    olua_require(L, "b2.MouseJointDef", luaopen_b2MouseJointDef);
    olua_require(L, "b2.MouseJoint", luaopen_b2MouseJoint);
    olua_require(L, "b2.PrismaticJointDef", luaopen_b2PrismaticJointDef);
    olua_require(L, "b2.PrismaticJoint", luaopen_b2PrismaticJoint);
    olua_require(L, "b2.PulleyJointDef", luaopen_b2PulleyJointDef);
    olua_require(L, "b2.PulleyJoint", luaopen_b2PulleyJoint);
    olua_require(L, "b2.RevoluteJointDef", luaopen_b2RevoluteJointDef);
    olua_require(L, "b2.RevoluteJoint", luaopen_b2RevoluteJoint);
    olua_require(L, "b2.WeldJointDef", luaopen_b2WeldJointDef);
    olua_require(L, "b2.WeldJoint", luaopen_b2WeldJoint);
    olua_require(L, "b2.WheelJointDef", luaopen_b2WheelJointDef);
    olua_require(L, "b2.WheelJoint", luaopen_b2WheelJoint);
    olua_require(L, "b2.JointEdge", luaopen_b2JointEdge);
    olua_require(L, "b2.JointUserData", luaopen_b2JointUserData);
    olua_require(L, "b2.ContactEdge", luaopen_b2ContactEdge);
    olua_require(L, "b2.ContactManager", luaopen_b2ContactManager);
    olua_require(L, "b2.Profile", luaopen_b2Profile);
    olua_require(L, "b2.BroadPhase", luaopen_b2BroadPhase);
    olua_require(L, "b2.AABB", luaopen_b2AABB);
    olua_require(L, "b2.Contact", luaopen_b2Contact);
    olua_require(L, "b2.ContactImpulse", luaopen_b2ContactImpulse);
    olua_require(L, "b2.Manifold", luaopen_b2Manifold);
    olua_require(L, "b2.Manifold.Type", luaopen_b2Manifold_Type);
    olua_require(L, "b2.World", luaopen_b2World);
    olua_require(L, "b2.WorldManifold", luaopen_b2WorldManifold);

    cclua::runtime::registerFeature("box2d", true);

    return 0;
}
OLUA_END_DECLS
