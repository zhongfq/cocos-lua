//
// AUTO GENERATED, DO NOT MODIFY!
//
#include "lua_cocos2d_types.h"

static int _olua_module_cocos2d_types(lua_State *L);

OLUA_LIB void olua_pack_object(lua_State *L, int idx, cocos2d::Vec2 *value)
{
    idx = lua_absindex(L, idx);

    float arg1 = 0;       /** x */
    float arg2 = 0;       /** y */

    olua_check_number(L, idx + 0, &arg1);
    value->x = arg1;

    olua_check_number(L, idx + 1, &arg2);
    value->y = arg2;
}

OLUA_LIB int olua_unpack_object(lua_State *L, const cocos2d::Vec2 *value)
{
    olua_push_number(L, value->x);
    olua_push_number(L, value->y);

    return 2;
}

OLUA_LIB bool olua_canpack_object(lua_State *L, int idx, const cocos2d::Vec2 *)
{
    return olua_is_number(L, idx + 0) && olua_is_number(L, idx + 1);
}


OLUA_LIB void olua_pack_object(lua_State *L, int idx, cocos2d::Vec3 *value)
{
    idx = lua_absindex(L, idx);

    float arg1 = 0;       /** x */
    float arg2 = 0;       /** y */
    float arg3 = 0;       /** z */

    olua_check_number(L, idx + 0, &arg1);
    value->x = arg1;

    olua_check_number(L, idx + 1, &arg2);
    value->y = arg2;

    olua_check_number(L, idx + 2, &arg3);
    value->z = arg3;
}

OLUA_LIB int olua_unpack_object(lua_State *L, const cocos2d::Vec3 *value)
{
    olua_push_number(L, value->x);
    olua_push_number(L, value->y);
    olua_push_number(L, value->z);

    return 3;
}

OLUA_LIB bool olua_canpack_object(lua_State *L, int idx, const cocos2d::Vec3 *)
{
    return olua_is_number(L, idx + 0) && olua_is_number(L, idx + 1) && olua_is_number(L, idx + 2);
}


OLUA_LIB void olua_pack_object(lua_State *L, int idx, cocos2d::Vec4 *value)
{
    idx = lua_absindex(L, idx);

    float arg1 = 0;       /** x */
    float arg2 = 0;       /** y */
    float arg3 = 0;       /** z */
    float arg4 = 0;       /** w */

    olua_check_number(L, idx + 0, &arg1);
    value->x = arg1;

    olua_check_number(L, idx + 1, &arg2);
    value->y = arg2;

    olua_check_number(L, idx + 2, &arg3);
    value->z = arg3;

    olua_check_number(L, idx + 3, &arg4);
    value->w = arg4;
}

OLUA_LIB int olua_unpack_object(lua_State *L, const cocos2d::Vec4 *value)
{
    olua_push_number(L, value->x);
    olua_push_number(L, value->y);
    olua_push_number(L, value->z);
    olua_push_number(L, value->w);

    return 4;
}

OLUA_LIB bool olua_canpack_object(lua_State *L, int idx, const cocos2d::Vec4 *)
{
    return olua_is_number(L, idx + 0) && olua_is_number(L, idx + 1) && olua_is_number(L, idx + 2) && olua_is_number(L, idx + 3);
}


OLUA_LIB void olua_pack_object(lua_State *L, int idx, cocos2d::Size *value)
{
    idx = lua_absindex(L, idx);

    float arg1 = 0;       /** width */
    float arg2 = 0;       /** height */

    olua_check_number(L, idx + 0, &arg1);
    value->width = arg1;

    olua_check_number(L, idx + 1, &arg2);
    value->height = arg2;
}

OLUA_LIB int olua_unpack_object(lua_State *L, const cocos2d::Size *value)
{
    olua_push_number(L, value->width);
    olua_push_number(L, value->height);

    return 2;
}

OLUA_LIB bool olua_canpack_object(lua_State *L, int idx, const cocos2d::Size *)
{
    return olua_is_number(L, idx + 0) && olua_is_number(L, idx + 1);
}


OLUA_LIB void olua_pack_object(lua_State *L, int idx, cocos2d::Bounds *value)
{
    idx = lua_absindex(L, idx);

    float arg1 = 0;       /** left */
    float arg2 = 0;       /** right */
    float arg3 = 0;       /** top */
    float arg4 = 0;       /** bottom */

    olua_check_number(L, idx + 0, &arg1);
    value->left = arg1;

    olua_check_number(L, idx + 1, &arg2);
    value->right = arg2;

    olua_check_number(L, idx + 2, &arg3);
    value->top = arg3;

    olua_check_number(L, idx + 3, &arg4);
    value->bottom = arg4;
}

OLUA_LIB int olua_unpack_object(lua_State *L, const cocos2d::Bounds *value)
{
    olua_push_number(L, value->left);
    olua_push_number(L, value->right);
    olua_push_number(L, value->top);
    olua_push_number(L, value->bottom);

    return 4;
}

OLUA_LIB bool olua_canpack_object(lua_State *L, int idx, const cocos2d::Bounds *)
{
    return olua_is_number(L, idx + 0) && olua_is_number(L, idx + 1) && olua_is_number(L, idx + 2) && olua_is_number(L, idx + 3);
}


OLUA_LIB void olua_pack_object(lua_State *L, int idx, cocos2d::ccBezierConfig *value)
{
    idx = lua_absindex(L, idx);

    cocos2d::Vec2 arg1;       /** endPosition */
    cocos2d::Vec2 arg2;       /** controlPoint_1 */
    cocos2d::Vec2 arg3;       /** controlPoint_2 */

    olua_check_object(L, idx + 0, &arg1, "cc.Vec2");
    value->endPosition = arg1;

    olua_check_object(L, idx + 1, &arg2, "cc.Vec2");
    value->controlPoint_1 = arg2;

    olua_check_object(L, idx + 2, &arg3, "cc.Vec2");
    value->controlPoint_2 = arg3;
}

OLUA_LIB int olua_unpack_object(lua_State *L, const cocos2d::ccBezierConfig *value)
{
    olua_copy_object(L, value->endPosition, "cc.Vec2");
    olua_copy_object(L, value->controlPoint_1, "cc.Vec2");
    olua_copy_object(L, value->controlPoint_2, "cc.Vec2");

    return 3;
}

OLUA_LIB bool olua_canpack_object(lua_State *L, int idx, const cocos2d::ccBezierConfig *)
{
    return olua_is_object(L, idx + 0, "cc.Vec2") && olua_is_object(L, idx + 1, "cc.Vec2") && olua_is_object(L, idx + 2, "cc.Vec2");
}


static int _olua_fun_cocos2d_Vec2___add(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    cocos2d::Vec2 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // @operator(operator+) cocos2d::Vec2 operator+(const cocos2d::Vec2 &v)
    cocos2d::Vec2 ret = (*self) + (*arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2___div(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    float arg1 = 0;       /** s */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_number(L, 2, &arg1);

    // @operator(operator/) cocos2d::Vec2 operator/(float s)
    cocos2d::Vec2 ret = (*self) / (arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2___eq(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    cocos2d::Vec2 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // @operator(operator==) bool operator==(const cocos2d::Vec2 &v)
    bool ret = (*self) == (*arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Vec2 *)olua_toobj(L, 1, "cc.Vec2");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec2___lt(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    cocos2d::Vec2 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // @operator(operator<) bool operator<(const cocos2d::Vec2 &v)
    bool ret = (*self) < (*arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2___mul(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    float arg1 = 0;       /** s */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_number(L, 2, &arg1);

    // @operator(operator*) cocos2d::Vec2 operator*(float s)
    cocos2d::Vec2 ret = (*self) * (arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2___sub(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    cocos2d::Vec2 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // @operator(operator-) cocos2d::Vec2 operator-(const cocos2d::Vec2 &v)
    cocos2d::Vec2 ret = (*self) - (*arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2___unm(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec2");

    // @operator(operator-) cocos2d::Vec2 operator-()
    cocos2d::Vec2 ret = -(*self);
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_add$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    cocos2d::Vec2 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void add(const cocos2d::Vec2 &v)
    self->add(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_add$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1;       /** v1 */
    cocos2d::Vec2 *arg2;       /** v2 */
    cocos2d::Vec2 *arg3 = nullptr;       /** dst */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_object(L, 2, &arg2, "cc.Vec2");
    olua_check_object(L, 3, &arg3, "cc.Vec2");

    // static void add(const cocos2d::Vec2 &v1, const cocos2d::Vec2 &v2, cocos2d::Vec2 *dst)
    cocos2d::Vec2::add(*arg1, *arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_add(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_object(L, 2, "cc.Vec2"))) {
            // void add(const cocos2d::Vec2 &v)
            return _olua_fun_cocos2d_Vec2_add$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_object(L, 2, "cc.Vec2")) && (olua_is_object(L, 3, "cc.Vec2"))) {
            // static void add(const cocos2d::Vec2 &v1, const cocos2d::Vec2 &v2, cocos2d::Vec2 *dst)
            return _olua_fun_cocos2d_Vec2_add$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec2::add' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_angle(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1;       /** v1 */
    cocos2d::Vec2 *arg2;       /** v2 */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_object(L, 2, &arg2, "cc.Vec2");

    // static float angle(const cocos2d::Vec2 &v1, const cocos2d::Vec2 &v2)
    float ret = cocos2d::Vec2::angle(*arg1, *arg2);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_clamp$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    cocos2d::Vec2 *arg1;       /** min */
    cocos2d::Vec2 *arg2;       /** max */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_object(L, 2, &arg1, "cc.Vec2");
    olua_check_object(L, 3, &arg2, "cc.Vec2");

    // void clamp(const cocos2d::Vec2 &min, const cocos2d::Vec2 &max)
    self->clamp(*arg1, *arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_clamp$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1;       /** v */
    cocos2d::Vec2 *arg2;       /** min */
    cocos2d::Vec2 *arg3;       /** max */
    cocos2d::Vec2 *arg4 = nullptr;       /** dst */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_object(L, 2, &arg2, "cc.Vec2");
    olua_check_object(L, 3, &arg3, "cc.Vec2");
    olua_check_object(L, 4, &arg4, "cc.Vec2");

    // static void clamp(const cocos2d::Vec2 &v, const cocos2d::Vec2 &min, const cocos2d::Vec2 &max, cocos2d::Vec2 *dst)
    cocos2d::Vec2::clamp(*arg1, *arg2, *arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_clamp(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_object(L, 2, "cc.Vec2")) && (olua_is_object(L, 3, "cc.Vec2"))) {
            // void clamp(const cocos2d::Vec2 &min, const cocos2d::Vec2 &max)
            return _olua_fun_cocos2d_Vec2_clamp$1(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_object(L, 2, "cc.Vec2")) && (olua_is_object(L, 3, "cc.Vec2")) && (olua_is_object(L, 4, "cc.Vec2"))) {
            // static void clamp(const cocos2d::Vec2 &v, const cocos2d::Vec2 &min, const cocos2d::Vec2 &max, cocos2d::Vec2 *dst)
            return _olua_fun_cocos2d_Vec2_clamp$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec2::clamp' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_compOp(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    std::function<float (float)> arg1;       /** function_ */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_callback(L, 2, &arg1, "std.function");

    void *cb_store = (void *)self;
    std::string cb_tag = "compOp";
    std::string cb_name = olua_setcallback(L, cb_store, 2, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    // lua_State *ML = olua_mainthread(L);
    arg1 = [cb_store, cb_name, cb_ctx /*, ML */](float cb_arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();
        float ret = 0;       /** ret */
        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            olua_push_number(L, cb_arg1);

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            if (olua_is_number(L, -1)) {
                olua_check_number(L, -1, &ret);
            }

            lua_settop(L, top);
        }
        return ret;
    };

    // cocos2d::Vec2 compOp(std::function<float (float)> function_)
    cocos2d::Vec2 ret = self->compOp(arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_cross(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    cocos2d::Vec2 *arg1;       /** other */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // float cross(const cocos2d::Vec2 &other)
    float ret = self->cross(*arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_distance(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    cocos2d::Vec2 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // float distance(const cocos2d::Vec2 &v)
    float ret = self->distance(*arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_distanceSquared(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    cocos2d::Vec2 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // float distanceSquared(const cocos2d::Vec2 &v)
    float ret = self->distanceSquared(*arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_dot$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    cocos2d::Vec2 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // float dot(const cocos2d::Vec2 &v)
    float ret = self->dot(*arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_dot$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1;       /** v1 */
    cocos2d::Vec2 *arg2;       /** v2 */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_object(L, 2, &arg2, "cc.Vec2");

    // static float dot(const cocos2d::Vec2 &v1, const cocos2d::Vec2 &v2)
    float ret = cocos2d::Vec2::dot(*arg1, *arg2);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_dot(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_object(L, 2, "cc.Vec2"))) {
            // float dot(const cocos2d::Vec2 &v)
            return _olua_fun_cocos2d_Vec2_dot$1(L);
        }

        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_object(L, 2, "cc.Vec2"))) {
            // static float dot(const cocos2d::Vec2 &v1, const cocos2d::Vec2 &v2)
            return _olua_fun_cocos2d_Vec2_dot$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec2::dot' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_equals(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    cocos2d::Vec2 *arg1;       /** target */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // bool equals(const cocos2d::Vec2 &target)
    bool ret = self->equals(*arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_forAngle(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** a */

    olua_check_number(L, 1, &arg1);

    // static cocos2d::Vec2 forAngle(const float a)
    cocos2d::Vec2 ret = cocos2d::Vec2::forAngle(arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_fuzzyEquals(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    cocos2d::Vec2 *arg1;       /** target */
    float arg2 = 0;       /** variance */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_object(L, 2, &arg1, "cc.Vec2");
    olua_check_number(L, 3, &arg2);

    // bool fuzzyEquals(const cocos2d::Vec2 &target, float variance)
    bool ret = self->fuzzyEquals(*arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_getAngle$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec2");

    // float getAngle()
    float ret = self->getAngle();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_getAngle$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    cocos2d::Vec2 *arg1;       /** other */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // float getAngle(const cocos2d::Vec2 &other)
    float ret = self->getAngle(*arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_getAngle(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float getAngle()
        return _olua_fun_cocos2d_Vec2_getAngle$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_object(L, 2, "cc.Vec2"))) {
            // float getAngle(const cocos2d::Vec2 &other)
            return _olua_fun_cocos2d_Vec2_getAngle$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec2::getAngle' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_getClampPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    cocos2d::Vec2 *arg1;       /** min_inclusive */
    cocos2d::Vec2 *arg2;       /** max_inclusive */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_object(L, 2, &arg1, "cc.Vec2");
    olua_check_object(L, 3, &arg2, "cc.Vec2");

    // cocos2d::Vec2 getClampPoint(const cocos2d::Vec2 &min_inclusive, const cocos2d::Vec2 &max_inclusive)
    cocos2d::Vec2 ret = self->getClampPoint(*arg1, *arg2);
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_getDistance(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    cocos2d::Vec2 *arg1;       /** other */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // float getDistance(const cocos2d::Vec2 &other)
    float ret = self->getDistance(*arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_getDistanceSq(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    cocos2d::Vec2 *arg1;       /** other */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // float getDistanceSq(const cocos2d::Vec2 &other)
    float ret = self->getDistanceSq(*arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_getIntersectPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1;       /** A */
    cocos2d::Vec2 *arg2;       /** B */
    cocos2d::Vec2 *arg3;       /** C */
    cocos2d::Vec2 *arg4;       /** D */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_object(L, 2, &arg2, "cc.Vec2");
    olua_check_object(L, 3, &arg3, "cc.Vec2");
    olua_check_object(L, 4, &arg4, "cc.Vec2");

    // static cocos2d::Vec2 getIntersectPoint(const cocos2d::Vec2 &A, const cocos2d::Vec2 &B, const cocos2d::Vec2 &C, const cocos2d::Vec2 &D)
    cocos2d::Vec2 ret = cocos2d::Vec2::getIntersectPoint(*arg1, *arg2, *arg3, *arg4);
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_getLength(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec2");

    // float getLength()
    float ret = self->getLength();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_getLengthSq(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec2");

    // float getLengthSq()
    float ret = self->getLengthSq();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_getMidpoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    cocos2d::Vec2 *arg1;       /** other */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // cocos2d::Vec2 getMidpoint(const cocos2d::Vec2 &other)
    cocos2d::Vec2 ret = self->getMidpoint(*arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_getNormalized(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec2");

    // cocos2d::Vec2 getNormalized()
    cocos2d::Vec2 ret = self->getNormalized();
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_getPerp(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec2");

    // cocos2d::Vec2 getPerp()
    cocos2d::Vec2 ret = self->getPerp();
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_getRPerp(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec2");

    // cocos2d::Vec2 getRPerp()
    cocos2d::Vec2 ret = self->getRPerp();
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_isLineIntersect$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1;       /** A */
    cocos2d::Vec2 *arg2;       /** B */
    cocos2d::Vec2 *arg3;       /** C */
    cocos2d::Vec2 *arg4;       /** D */
    float *arg5 = nullptr;       /** S */
    float *arg6 = nullptr;       /** T */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_object(L, 2, &arg2, "cc.Vec2");
    olua_check_object(L, 3, &arg3, "cc.Vec2");
    olua_check_object(L, 4, &arg4, "cc.Vec2");
    olua_check_pointer(L, 5, &arg5, "olua.float");
    olua_check_pointer(L, 6, &arg6, "olua.float");

    // static bool isLineIntersect(const cocos2d::Vec2 &A, const cocos2d::Vec2 &B, const cocos2d::Vec2 &C, const cocos2d::Vec2 &D, @optional float *S, @optional float *T)
    bool ret = cocos2d::Vec2::isLineIntersect(*arg1, *arg2, *arg3, *arg4, arg5, arg6);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_isLineIntersect$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1;       /** A */
    cocos2d::Vec2 *arg2;       /** B */
    cocos2d::Vec2 *arg3;       /** C */
    cocos2d::Vec2 *arg4;       /** D */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_object(L, 2, &arg2, "cc.Vec2");
    olua_check_object(L, 3, &arg3, "cc.Vec2");
    olua_check_object(L, 4, &arg4, "cc.Vec2");

    // static bool isLineIntersect(const cocos2d::Vec2 &A, const cocos2d::Vec2 &B, const cocos2d::Vec2 &C, const cocos2d::Vec2 &D)
    bool ret = cocos2d::Vec2::isLineIntersect(*arg1, *arg2, *arg3, *arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_isLineIntersect$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1;       /** A */
    cocos2d::Vec2 *arg2;       /** B */
    cocos2d::Vec2 *arg3;       /** C */
    cocos2d::Vec2 *arg4;       /** D */
    float *arg5 = nullptr;       /** S */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_object(L, 2, &arg2, "cc.Vec2");
    olua_check_object(L, 3, &arg3, "cc.Vec2");
    olua_check_object(L, 4, &arg4, "cc.Vec2");
    olua_check_pointer(L, 5, &arg5, "olua.float");

    // static bool isLineIntersect(const cocos2d::Vec2 &A, const cocos2d::Vec2 &B, const cocos2d::Vec2 &C, const cocos2d::Vec2 &D, @optional float *S)
    bool ret = cocos2d::Vec2::isLineIntersect(*arg1, *arg2, *arg3, *arg4, arg5);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_isLineIntersect(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_object(L, 2, "cc.Vec2")) && (olua_is_object(L, 3, "cc.Vec2")) && (olua_is_object(L, 4, "cc.Vec2"))) {
            // static bool isLineIntersect(const cocos2d::Vec2 &A, const cocos2d::Vec2 &B, const cocos2d::Vec2 &C, const cocos2d::Vec2 &D)
            return _olua_fun_cocos2d_Vec2_isLineIntersect$2(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_object(L, 2, "cc.Vec2")) && (olua_is_object(L, 3, "cc.Vec2")) && (olua_is_object(L, 4, "cc.Vec2")) && (olua_is_pointer(L, 5, "olua.float"))) {
            // static bool isLineIntersect(const cocos2d::Vec2 &A, const cocos2d::Vec2 &B, const cocos2d::Vec2 &C, const cocos2d::Vec2 &D, @optional float *S)
            return _olua_fun_cocos2d_Vec2_isLineIntersect$3(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_object(L, 2, "cc.Vec2")) && (olua_is_object(L, 3, "cc.Vec2")) && (olua_is_object(L, 4, "cc.Vec2")) && (olua_is_pointer(L, 5, "olua.float")) && (olua_is_pointer(L, 6, "olua.float"))) {
            // static bool isLineIntersect(const cocos2d::Vec2 &A, const cocos2d::Vec2 &B, const cocos2d::Vec2 &C, const cocos2d::Vec2 &D, @optional float *S, @optional float *T)
            return _olua_fun_cocos2d_Vec2_isLineIntersect$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec2::isLineIntersect' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_isLineOverlap(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1;       /** A */
    cocos2d::Vec2 *arg2;       /** B */
    cocos2d::Vec2 *arg3;       /** C */
    cocos2d::Vec2 *arg4;       /** D */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_object(L, 2, &arg2, "cc.Vec2");
    olua_check_object(L, 3, &arg3, "cc.Vec2");
    olua_check_object(L, 4, &arg4, "cc.Vec2");

    // static bool isLineOverlap(const cocos2d::Vec2 &A, const cocos2d::Vec2 &B, const cocos2d::Vec2 &C, const cocos2d::Vec2 &D)
    bool ret = cocos2d::Vec2::isLineOverlap(*arg1, *arg2, *arg3, *arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_isLineParallel(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1;       /** A */
    cocos2d::Vec2 *arg2;       /** B */
    cocos2d::Vec2 *arg3;       /** C */
    cocos2d::Vec2 *arg4;       /** D */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_object(L, 2, &arg2, "cc.Vec2");
    olua_check_object(L, 3, &arg3, "cc.Vec2");
    olua_check_object(L, 4, &arg4, "cc.Vec2");

    // static bool isLineParallel(const cocos2d::Vec2 &A, const cocos2d::Vec2 &B, const cocos2d::Vec2 &C, const cocos2d::Vec2 &D)
    bool ret = cocos2d::Vec2::isLineParallel(*arg1, *arg2, *arg3, *arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_isOne(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec2");

    // bool isOne()
    bool ret = self->isOne();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_isSegmentIntersect(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1;       /** A */
    cocos2d::Vec2 *arg2;       /** B */
    cocos2d::Vec2 *arg3;       /** C */
    cocos2d::Vec2 *arg4;       /** D */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_object(L, 2, &arg2, "cc.Vec2");
    olua_check_object(L, 3, &arg3, "cc.Vec2");
    olua_check_object(L, 4, &arg4, "cc.Vec2");

    // static bool isSegmentIntersect(const cocos2d::Vec2 &A, const cocos2d::Vec2 &B, const cocos2d::Vec2 &C, const cocos2d::Vec2 &D)
    bool ret = cocos2d::Vec2::isSegmentIntersect(*arg1, *arg2, *arg3, *arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_isSegmentOverlap$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1;       /** A */
    cocos2d::Vec2 *arg2;       /** B */
    cocos2d::Vec2 *arg3;       /** C */
    cocos2d::Vec2 *arg4;       /** D */
    cocos2d::Vec2 *arg5 = nullptr;       /** S */
    cocos2d::Vec2 *arg6 = nullptr;       /** E */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_object(L, 2, &arg2, "cc.Vec2");
    olua_check_object(L, 3, &arg3, "cc.Vec2");
    olua_check_object(L, 4, &arg4, "cc.Vec2");
    olua_check_object(L, 5, &arg5, "cc.Vec2");
    olua_check_object(L, 6, &arg6, "cc.Vec2");

    // static bool isSegmentOverlap(const cocos2d::Vec2 &A, const cocos2d::Vec2 &B, const cocos2d::Vec2 &C, const cocos2d::Vec2 &D, @optional cocos2d::Vec2 *S, @optional cocos2d::Vec2 *E)
    bool ret = cocos2d::Vec2::isSegmentOverlap(*arg1, *arg2, *arg3, *arg4, arg5, arg6);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_isSegmentOverlap$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1;       /** A */
    cocos2d::Vec2 *arg2;       /** B */
    cocos2d::Vec2 *arg3;       /** C */
    cocos2d::Vec2 *arg4;       /** D */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_object(L, 2, &arg2, "cc.Vec2");
    olua_check_object(L, 3, &arg3, "cc.Vec2");
    olua_check_object(L, 4, &arg4, "cc.Vec2");

    // static bool isSegmentOverlap(const cocos2d::Vec2 &A, const cocos2d::Vec2 &B, const cocos2d::Vec2 &C, const cocos2d::Vec2 &D)
    bool ret = cocos2d::Vec2::isSegmentOverlap(*arg1, *arg2, *arg3, *arg4);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_isSegmentOverlap$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1;       /** A */
    cocos2d::Vec2 *arg2;       /** B */
    cocos2d::Vec2 *arg3;       /** C */
    cocos2d::Vec2 *arg4;       /** D */
    cocos2d::Vec2 *arg5 = nullptr;       /** S */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_object(L, 2, &arg2, "cc.Vec2");
    olua_check_object(L, 3, &arg3, "cc.Vec2");
    olua_check_object(L, 4, &arg4, "cc.Vec2");
    olua_check_object(L, 5, &arg5, "cc.Vec2");

    // static bool isSegmentOverlap(const cocos2d::Vec2 &A, const cocos2d::Vec2 &B, const cocos2d::Vec2 &C, const cocos2d::Vec2 &D, @optional cocos2d::Vec2 *S)
    bool ret = cocos2d::Vec2::isSegmentOverlap(*arg1, *arg2, *arg3, *arg4, arg5);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_isSegmentOverlap(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_object(L, 2, "cc.Vec2")) && (olua_is_object(L, 3, "cc.Vec2")) && (olua_is_object(L, 4, "cc.Vec2"))) {
            // static bool isSegmentOverlap(const cocos2d::Vec2 &A, const cocos2d::Vec2 &B, const cocos2d::Vec2 &C, const cocos2d::Vec2 &D)
            return _olua_fun_cocos2d_Vec2_isSegmentOverlap$2(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_object(L, 2, "cc.Vec2")) && (olua_is_object(L, 3, "cc.Vec2")) && (olua_is_object(L, 4, "cc.Vec2")) && (olua_is_object(L, 5, "cc.Vec2"))) {
            // static bool isSegmentOverlap(const cocos2d::Vec2 &A, const cocos2d::Vec2 &B, const cocos2d::Vec2 &C, const cocos2d::Vec2 &D, @optional cocos2d::Vec2 *S)
            return _olua_fun_cocos2d_Vec2_isSegmentOverlap$3(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_object(L, 2, "cc.Vec2")) && (olua_is_object(L, 3, "cc.Vec2")) && (olua_is_object(L, 4, "cc.Vec2")) && (olua_is_object(L, 5, "cc.Vec2")) && (olua_is_object(L, 6, "cc.Vec2"))) {
            // static bool isSegmentOverlap(const cocos2d::Vec2 &A, const cocos2d::Vec2 &B, const cocos2d::Vec2 &C, const cocos2d::Vec2 &D, @optional cocos2d::Vec2 *S, @optional cocos2d::Vec2 *E)
            return _olua_fun_cocos2d_Vec2_isSegmentOverlap$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec2::isSegmentOverlap' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_isZero(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec2");

    // bool isZero()
    bool ret = self->isZero();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_length(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec2");

    // float length()
    float ret = self->length();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_lengthSquared(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec2");

    // float lengthSquared()
    float ret = self->lengthSquared();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_lerp(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    cocos2d::Vec2 *arg1;       /** other */
    float arg2 = 0;       /** alpha */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_object(L, 2, &arg1, "cc.Vec2");
    olua_check_number(L, 3, &arg2);

    // cocos2d::Vec2 lerp(const cocos2d::Vec2 &other, float alpha)
    cocos2d::Vec2 ret = self->lerp(*arg1, arg2);
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_negate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec2");

    // void negate()
    self->negate();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_new$1(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::Vec2()
    cocos2d::Vec2 *ret = new cocos2d::Vec2();
    int num_ret = olua_push_object(L, ret, "cc.Vec2");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_new$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** xx */
    float arg2 = 0;       /** yy */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // cocos2d::Vec2(float xx, float yy)
    cocos2d::Vec2 *ret = new cocos2d::Vec2(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.Vec2");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_new$3(lua_State *L)
{
    olua_startinvoke(L);

    float *arg1 = nullptr;       /** array */

    olua_check_pointer(L, 1, &arg1, "olua.float");

    // cocos2d::Vec2(const float *array)
    cocos2d::Vec2 *ret = new cocos2d::Vec2(arg1);
    int num_ret = olua_push_object(L, ret, "cc.Vec2");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_new$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1;       /** p1 */
    cocos2d::Vec2 *arg2;       /** p2 */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_object(L, 2, &arg2, "cc.Vec2");

    // cocos2d::Vec2(const cocos2d::Vec2 &p1, const cocos2d::Vec2 &p2)
    cocos2d::Vec2 *ret = new cocos2d::Vec2(*arg1, *arg2);
    int num_ret = olua_push_object(L, ret, "cc.Vec2");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // cocos2d::Vec2()
        return _olua_fun_cocos2d_Vec2_new$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_pointer(L, 1, "olua.float"))) {
            // cocos2d::Vec2(const float *array)
            return _olua_fun_cocos2d_Vec2_new$3(L);
        // }
    }

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_object(L, 2, "cc.Vec2"))) {
            // cocos2d::Vec2(const cocos2d::Vec2 &p1, const cocos2d::Vec2 &p2)
            return _olua_fun_cocos2d_Vec2_new$4(L);
        }

        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2))) {
            // cocos2d::Vec2(float xx, float yy)
            return _olua_fun_cocos2d_Vec2_new$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec2::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_normalize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec2");

    // void normalize()
    self->normalize();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_project(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    cocos2d::Vec2 *arg1;       /** other */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // cocos2d::Vec2 project(const cocos2d::Vec2 &other)
    cocos2d::Vec2 ret = self->project(*arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_rotate$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    cocos2d::Vec2 *arg1;       /** point */
    float arg2 = 0;       /** angle */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_object(L, 2, &arg1, "cc.Vec2");
    olua_check_number(L, 3, &arg2);

    // void rotate(const cocos2d::Vec2 &point, float angle)
    self->rotate(*arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_rotate$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    cocos2d::Vec2 *arg1;       /** other */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // cocos2d::Vec2 rotate(const cocos2d::Vec2 &other)
    cocos2d::Vec2 ret = self->rotate(*arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_rotate(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_object(L, 2, "cc.Vec2"))) {
            // cocos2d::Vec2 rotate(const cocos2d::Vec2 &other)
            return _olua_fun_cocos2d_Vec2_rotate$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_object(L, 2, "cc.Vec2")) && (olua_is_number(L, 3))) {
            // void rotate(const cocos2d::Vec2 &point, float angle)
            return _olua_fun_cocos2d_Vec2_rotate$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec2::rotate' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_rotateByAngle(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    cocos2d::Vec2 *arg1;       /** pivot */
    float arg2 = 0;       /** angle */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_object(L, 2, &arg1, "cc.Vec2");
    olua_check_number(L, 3, &arg2);

    // cocos2d::Vec2 rotateByAngle(const cocos2d::Vec2 &pivot, float angle)
    cocos2d::Vec2 ret = self->rotateByAngle(*arg1, arg2);
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_scale$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    float arg1 = 0;       /** scalar */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_number(L, 2, &arg1);

    // void scale(float scalar)
    self->scale(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_scale$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    cocos2d::Vec2 *arg1;       /** scale */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void scale(const cocos2d::Vec2 &scale)
    self->scale(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_scale(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_number(L, 2))) {
            // void scale(float scalar)
            return _olua_fun_cocos2d_Vec2_scale$1(L);
        }

        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_object(L, 2, "cc.Vec2"))) {
            // void scale(const cocos2d::Vec2 &scale)
            return _olua_fun_cocos2d_Vec2_scale$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec2::scale' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_set$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    float arg1 = 0;       /** xx */
    float arg2 = 0;       /** yy */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void set(float xx, float yy)
    self->set(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_set$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    float *arg1 = nullptr;       /** array */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_pointer(L, 2, &arg1, "olua.float");

    // void set(const float *array)
    self->set(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_set$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    cocos2d::Vec2 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void set(const cocos2d::Vec2 &v)
    self->set(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_set$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    cocos2d::Vec2 *arg1;       /** p1 */
    cocos2d::Vec2 *arg2;       /** p2 */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_object(L, 2, &arg1, "cc.Vec2");
    olua_check_object(L, 3, &arg2, "cc.Vec2");

    // void set(const cocos2d::Vec2 &p1, const cocos2d::Vec2 &p2)
    self->set(*arg1, *arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_set(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_pointer(L, 2, "olua.float"))) {
            // void set(const float *array)
            return _olua_fun_cocos2d_Vec2_set$2(L);
        }

        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_object(L, 2, "cc.Vec2"))) {
            // void set(const cocos2d::Vec2 &v)
            return _olua_fun_cocos2d_Vec2_set$3(L);
        // }
    }

    if (num_args == 3) {
        if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // void set(float xx, float yy)
            return _olua_fun_cocos2d_Vec2_set$1(L);
        }

        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_object(L, 2, "cc.Vec2")) && (olua_is_object(L, 3, "cc.Vec2"))) {
            // void set(const cocos2d::Vec2 &p1, const cocos2d::Vec2 &p2)
            return _olua_fun_cocos2d_Vec2_set$4(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec2::set' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_setPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    float arg1 = 0;       /** xx */
    float arg2 = 0;       /** yy */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void setPoint(float xx, float yy)
    self->setPoint(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_setZero(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec2");

    // void setZero()
    self->setZero();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_smooth(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    cocos2d::Vec2 *arg1;       /** target */
    float arg2 = 0;       /** elapsedTime */
    float arg3 = 0;       /** responseTime */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_object(L, 2, &arg1, "cc.Vec2");
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // void smooth(const cocos2d::Vec2 &target, float elapsedTime, float responseTime)
    self->smooth(*arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_subtract$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    cocos2d::Vec2 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // void subtract(const cocos2d::Vec2 &v)
    self->subtract(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_subtract$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1;       /** v1 */
    cocos2d::Vec2 *arg2;       /** v2 */
    cocos2d::Vec2 *arg3 = nullptr;       /** dst */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_object(L, 2, &arg2, "cc.Vec2");
    olua_check_object(L, 3, &arg3, "cc.Vec2");

    // static void subtract(const cocos2d::Vec2 &v1, const cocos2d::Vec2 &v2, cocos2d::Vec2 *dst)
    cocos2d::Vec2::subtract(*arg1, *arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_subtract(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_object(L, 2, "cc.Vec2"))) {
            // void subtract(const cocos2d::Vec2 &v)
            return _olua_fun_cocos2d_Vec2_subtract$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_object(L, 2, "cc.Vec2")) && (olua_is_object(L, 3, "cc.Vec2"))) {
            // static void subtract(const cocos2d::Vec2 &v1, const cocos2d::Vec2 &v2, cocos2d::Vec2 *dst)
            return _olua_fun_cocos2d_Vec2_subtract$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec2::subtract' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_unrotate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    cocos2d::Vec2 *arg1;       /** other */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // cocos2d::Vec2 unrotate(const cocos2d::Vec2 &other)
    cocos2d::Vec2 ret = self->unrotate(*arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_x$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec2");

    // float x
    float ret = self->x;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_x$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    float arg1 = 0;       /** x */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_number(L, 2, &arg1);

    // float x
    self->x = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_x(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float x
        return _olua_fun_cocos2d_Vec2_x$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_number(L, 2))) {
            // float x
            return _olua_fun_cocos2d_Vec2_x$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec2::x' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_y$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec2");

    // float y
    float ret = self->y;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec2_y$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *self = nullptr;
    float arg1 = 0;       /** y */

    olua_to_object(L, 1, &self, "cc.Vec2");
    olua_check_number(L, 2, &arg1);

    // float y
    self->y = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec2_y(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float y
        return _olua_fun_cocos2d_Vec2_y$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_number(L, 2))) {
            // float y
            return _olua_fun_cocos2d_Vec2_y$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec2::y' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_cc_Vec2(lua_State *L)
{
    oluacls_class<cocos2d::Vec2>(L, "cc.Vec2");
    oluacls_func(L, "__add", _olua_fun_cocos2d_Vec2___add);
    oluacls_func(L, "__div", _olua_fun_cocos2d_Vec2___div);
    oluacls_func(L, "__eq", _olua_fun_cocos2d_Vec2___eq);
    oluacls_func(L, "__gc", _olua_fun_cocos2d_Vec2___gc);
    oluacls_func(L, "__lt", _olua_fun_cocos2d_Vec2___lt);
    oluacls_func(L, "__mul", _olua_fun_cocos2d_Vec2___mul);
    oluacls_func(L, "__sub", _olua_fun_cocos2d_Vec2___sub);
    oluacls_func(L, "__unm", _olua_fun_cocos2d_Vec2___unm);
    oluacls_func(L, "add", _olua_fun_cocos2d_Vec2_add);
    oluacls_func(L, "angle", _olua_fun_cocos2d_Vec2_angle);
    oluacls_func(L, "clamp", _olua_fun_cocos2d_Vec2_clamp);
    oluacls_func(L, "compOp", _olua_fun_cocos2d_Vec2_compOp);
    oluacls_func(L, "cross", _olua_fun_cocos2d_Vec2_cross);
    oluacls_func(L, "distance", _olua_fun_cocos2d_Vec2_distance);
    oluacls_func(L, "distanceSquared", _olua_fun_cocos2d_Vec2_distanceSquared);
    oluacls_func(L, "dot", _olua_fun_cocos2d_Vec2_dot);
    oluacls_func(L, "equals", _olua_fun_cocos2d_Vec2_equals);
    oluacls_func(L, "forAngle", _olua_fun_cocos2d_Vec2_forAngle);
    oluacls_func(L, "fuzzyEquals", _olua_fun_cocos2d_Vec2_fuzzyEquals);
    oluacls_func(L, "getAngle", _olua_fun_cocos2d_Vec2_getAngle);
    oluacls_func(L, "getClampPoint", _olua_fun_cocos2d_Vec2_getClampPoint);
    oluacls_func(L, "getDistance", _olua_fun_cocos2d_Vec2_getDistance);
    oluacls_func(L, "getDistanceSq", _olua_fun_cocos2d_Vec2_getDistanceSq);
    oluacls_func(L, "getIntersectPoint", _olua_fun_cocos2d_Vec2_getIntersectPoint);
    oluacls_func(L, "getLength", _olua_fun_cocos2d_Vec2_getLength);
    oluacls_func(L, "getLengthSq", _olua_fun_cocos2d_Vec2_getLengthSq);
    oluacls_func(L, "getMidpoint", _olua_fun_cocos2d_Vec2_getMidpoint);
    oluacls_func(L, "getNormalized", _olua_fun_cocos2d_Vec2_getNormalized);
    oluacls_func(L, "getPerp", _olua_fun_cocos2d_Vec2_getPerp);
    oluacls_func(L, "getRPerp", _olua_fun_cocos2d_Vec2_getRPerp);
    oluacls_func(L, "isLineIntersect", _olua_fun_cocos2d_Vec2_isLineIntersect);
    oluacls_func(L, "isLineOverlap", _olua_fun_cocos2d_Vec2_isLineOverlap);
    oluacls_func(L, "isLineParallel", _olua_fun_cocos2d_Vec2_isLineParallel);
    oluacls_func(L, "isOne", _olua_fun_cocos2d_Vec2_isOne);
    oluacls_func(L, "isSegmentIntersect", _olua_fun_cocos2d_Vec2_isSegmentIntersect);
    oluacls_func(L, "isSegmentOverlap", _olua_fun_cocos2d_Vec2_isSegmentOverlap);
    oluacls_func(L, "isZero", _olua_fun_cocos2d_Vec2_isZero);
    oluacls_func(L, "length", _olua_fun_cocos2d_Vec2_length);
    oluacls_func(L, "lengthSquared", _olua_fun_cocos2d_Vec2_lengthSquared);
    oluacls_func(L, "lerp", _olua_fun_cocos2d_Vec2_lerp);
    oluacls_func(L, "negate", _olua_fun_cocos2d_Vec2_negate);
    oluacls_func(L, "new", _olua_fun_cocos2d_Vec2_new);
    oluacls_func(L, "normalize", _olua_fun_cocos2d_Vec2_normalize);
    oluacls_func(L, "project", _olua_fun_cocos2d_Vec2_project);
    oluacls_func(L, "rotate", _olua_fun_cocos2d_Vec2_rotate);
    oluacls_func(L, "rotateByAngle", _olua_fun_cocos2d_Vec2_rotateByAngle);
    oluacls_func(L, "scale", _olua_fun_cocos2d_Vec2_scale);
    oluacls_func(L, "set", _olua_fun_cocos2d_Vec2_set);
    oluacls_func(L, "setPoint", _olua_fun_cocos2d_Vec2_setPoint);
    oluacls_func(L, "setZero", _olua_fun_cocos2d_Vec2_setZero);
    oluacls_func(L, "smooth", _olua_fun_cocos2d_Vec2_smooth);
    oluacls_func(L, "subtract", _olua_fun_cocos2d_Vec2_subtract);
    oluacls_func(L, "unrotate", _olua_fun_cocos2d_Vec2_unrotate);
    oluacls_prop(L, "lengthSq", _olua_fun_cocos2d_Vec2_getLengthSq, nullptr);
    oluacls_prop(L, "normalized", _olua_fun_cocos2d_Vec2_getNormalized, nullptr);
    oluacls_prop(L, "one", _olua_fun_cocos2d_Vec2_isOne, nullptr);
    oluacls_prop(L, "perp", _olua_fun_cocos2d_Vec2_getPerp, nullptr);
    oluacls_prop(L, "rPerp", _olua_fun_cocos2d_Vec2_getRPerp, nullptr);
    oluacls_prop(L, "zero", _olua_fun_cocos2d_Vec2_isZero, _olua_fun_cocos2d_Vec2_setZero);
    oluacls_prop(L, "x", _olua_fun_cocos2d_Vec2_x, _olua_fun_cocos2d_Vec2_x);
    oluacls_prop(L, "y", _olua_fun_cocos2d_Vec2_y, _olua_fun_cocos2d_Vec2_y);
    oluacls_const(L, "ANCHOR_BOTTOM_LEFT", &cocos2d::Vec2::ANCHOR_BOTTOM_LEFT);
    oluacls_const(L, "ANCHOR_BOTTOM_RIGHT", &cocos2d::Vec2::ANCHOR_BOTTOM_RIGHT);
    oluacls_const(L, "ANCHOR_MIDDLE", &cocos2d::Vec2::ANCHOR_MIDDLE);
    oluacls_const(L, "ANCHOR_MIDDLE_BOTTOM", &cocos2d::Vec2::ANCHOR_MIDDLE_BOTTOM);
    oluacls_const(L, "ANCHOR_MIDDLE_LEFT", &cocos2d::Vec2::ANCHOR_MIDDLE_LEFT);
    oluacls_const(L, "ANCHOR_MIDDLE_RIGHT", &cocos2d::Vec2::ANCHOR_MIDDLE_RIGHT);
    oluacls_const(L, "ANCHOR_MIDDLE_TOP", &cocos2d::Vec2::ANCHOR_MIDDLE_TOP);
    oluacls_const(L, "ANCHOR_TOP_LEFT", &cocos2d::Vec2::ANCHOR_TOP_LEFT);
    oluacls_const(L, "ANCHOR_TOP_RIGHT", &cocos2d::Vec2::ANCHOR_TOP_RIGHT);
    oluacls_const(L, "ONE", &cocos2d::Vec2::ONE);
    oluacls_const(L, "UNIT_X", &cocos2d::Vec2::UNIT_X);
    oluacls_const(L, "UNIT_Y", &cocos2d::Vec2::UNIT_Y);
    oluacls_const(L, "ZERO", &cocos2d::Vec2::ZERO);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cc_Vec2(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "cc.Vec2")) {
        luaL_error(L, "class not found: cocos2d::Vec2");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_Vec3___add(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;
    cocos2d::Vec3 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec3");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // @operator(operator+) cocos2d::Vec3 operator+(const cocos2d::Vec3 &v)
    cocos2d::Vec3 ret = (*self) + (*arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Vec3");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec3___div(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;
    float arg1 = 0;       /** s */

    olua_to_object(L, 1, &self, "cc.Vec3");
    olua_check_number(L, 2, &arg1);

    // @operator(operator/) cocos2d::Vec3 operator/(float s)
    cocos2d::Vec3 ret = (*self) / (arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Vec3");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec3___eq(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;
    cocos2d::Vec3 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec3");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // @operator(operator==) bool operator==(const cocos2d::Vec3 &v)
    bool ret = (*self) == (*arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec3___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Vec3 *)olua_toobj(L, 1, "cc.Vec3");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec3___lt(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;
    cocos2d::Vec3 *arg1;       /** rhs */

    olua_to_object(L, 1, &self, "cc.Vec3");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // @operator(operator<) bool operator<(const cocos2d::Vec3 &rhs)
    bool ret = (*self) < (*arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec3___mul(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;
    float arg1 = 0;       /** s */

    olua_to_object(L, 1, &self, "cc.Vec3");
    olua_check_number(L, 2, &arg1);

    // @operator(operator*) cocos2d::Vec3 operator*(float s)
    cocos2d::Vec3 ret = (*self) * (arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Vec3");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec3___sub(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;
    cocos2d::Vec3 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec3");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // @operator(operator-) cocos2d::Vec3 operator-(const cocos2d::Vec3 &v)
    cocos2d::Vec3 ret = (*self) - (*arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Vec3");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec3___unm(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec3");

    // @operator(operator-) cocos2d::Vec3 operator-()
    cocos2d::Vec3 ret = -(*self);
    int num_ret = olua_copy_object(L, ret, "cc.Vec3");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec3_add$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;
    cocos2d::Vec3 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec3");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // void add(const cocos2d::Vec3 &v)
    self->add(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_add$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;
    float arg1 = 0;       /** xx */
    float arg2 = 0;       /** yy */
    float arg3 = 0;       /** zz */

    olua_to_object(L, 1, &self, "cc.Vec3");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // void add(float xx, float yy, float zz)
    self->add(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_add$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *arg1;       /** v1 */
    cocos2d::Vec3 *arg2;       /** v2 */
    cocos2d::Vec3 *arg3 = nullptr;       /** dst */

    olua_check_object(L, 1, &arg1, "cc.Vec3");
    olua_check_object(L, 2, &arg2, "cc.Vec3");
    olua_check_object(L, 3, &arg3, "cc.Vec3");

    // static void add(const cocos2d::Vec3 &v1, const cocos2d::Vec3 &v2, cocos2d::Vec3 *dst)
    cocos2d::Vec3::add(*arg1, *arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_add(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec3")) && (olua_is_object(L, 2, "cc.Vec3"))) {
            // void add(const cocos2d::Vec3 &v)
            return _olua_fun_cocos2d_Vec3_add$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Vec3")) && (olua_is_object(L, 2, "cc.Vec3")) && (olua_is_object(L, 3, "cc.Vec3"))) {
            // static void add(const cocos2d::Vec3 &v1, const cocos2d::Vec3 &v2, cocos2d::Vec3 *dst)
            return _olua_fun_cocos2d_Vec3_add$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.Vec3")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4))) {
            // void add(float xx, float yy, float zz)
            return _olua_fun_cocos2d_Vec3_add$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec3::add' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_angle(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *arg1;       /** v1 */
    cocos2d::Vec3 *arg2;       /** v2 */

    olua_check_object(L, 1, &arg1, "cc.Vec3");
    olua_check_object(L, 2, &arg2, "cc.Vec3");

    // static float angle(const cocos2d::Vec3 &v1, const cocos2d::Vec3 &v2)
    float ret = cocos2d::Vec3::angle(*arg1, *arg2);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec3_clamp$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;
    cocos2d::Vec3 *arg1;       /** min */
    cocos2d::Vec3 *arg2;       /** max */

    olua_to_object(L, 1, &self, "cc.Vec3");
    olua_check_object(L, 2, &arg1, "cc.Vec3");
    olua_check_object(L, 3, &arg2, "cc.Vec3");

    // void clamp(const cocos2d::Vec3 &min, const cocos2d::Vec3 &max)
    self->clamp(*arg1, *arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_clamp$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *arg1;       /** v */
    cocos2d::Vec3 *arg2;       /** min */
    cocos2d::Vec3 *arg3;       /** max */
    cocos2d::Vec3 *arg4 = nullptr;       /** dst */

    olua_check_object(L, 1, &arg1, "cc.Vec3");
    olua_check_object(L, 2, &arg2, "cc.Vec3");
    olua_check_object(L, 3, &arg3, "cc.Vec3");
    olua_check_object(L, 4, &arg4, "cc.Vec3");

    // static void clamp(const cocos2d::Vec3 &v, const cocos2d::Vec3 &min, const cocos2d::Vec3 &max, cocos2d::Vec3 *dst)
    cocos2d::Vec3::clamp(*arg1, *arg2, *arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_clamp(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Vec3")) && (olua_is_object(L, 2, "cc.Vec3")) && (olua_is_object(L, 3, "cc.Vec3"))) {
            // void clamp(const cocos2d::Vec3 &min, const cocos2d::Vec3 &max)
            return _olua_fun_cocos2d_Vec3_clamp$1(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.Vec3")) && (olua_is_object(L, 2, "cc.Vec3")) && (olua_is_object(L, 3, "cc.Vec3")) && (olua_is_object(L, 4, "cc.Vec3"))) {
            // static void clamp(const cocos2d::Vec3 &v, const cocos2d::Vec3 &min, const cocos2d::Vec3 &max, cocos2d::Vec3 *dst)
            return _olua_fun_cocos2d_Vec3_clamp$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec3::clamp' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_cross$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;
    cocos2d::Vec3 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec3");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // void cross(const cocos2d::Vec3 &v)
    self->cross(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_cross$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *arg1;       /** v1 */
    cocos2d::Vec3 *arg2;       /** v2 */
    cocos2d::Vec3 *arg3 = nullptr;       /** dst */

    olua_check_object(L, 1, &arg1, "cc.Vec3");
    olua_check_object(L, 2, &arg2, "cc.Vec3");
    olua_check_object(L, 3, &arg3, "cc.Vec3");

    // static void cross(const cocos2d::Vec3 &v1, const cocos2d::Vec3 &v2, cocos2d::Vec3 *dst)
    cocos2d::Vec3::cross(*arg1, *arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_cross(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec3")) && (olua_is_object(L, 2, "cc.Vec3"))) {
            // void cross(const cocos2d::Vec3 &v)
            return _olua_fun_cocos2d_Vec3_cross$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Vec3")) && (olua_is_object(L, 2, "cc.Vec3")) && (olua_is_object(L, 3, "cc.Vec3"))) {
            // static void cross(const cocos2d::Vec3 &v1, const cocos2d::Vec3 &v2, cocos2d::Vec3 *dst)
            return _olua_fun_cocos2d_Vec3_cross$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec3::cross' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_distance(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;
    cocos2d::Vec3 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec3");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // float distance(const cocos2d::Vec3 &v)
    float ret = self->distance(*arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec3_distanceSquared(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;
    cocos2d::Vec3 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec3");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // float distanceSquared(const cocos2d::Vec3 &v)
    float ret = self->distanceSquared(*arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec3_dot$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;
    cocos2d::Vec3 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec3");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // float dot(const cocos2d::Vec3 &v)
    float ret = self->dot(*arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec3_dot$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *arg1;       /** v1 */
    cocos2d::Vec3 *arg2;       /** v2 */

    olua_check_object(L, 1, &arg1, "cc.Vec3");
    olua_check_object(L, 2, &arg2, "cc.Vec3");

    // static float dot(const cocos2d::Vec3 &v1, const cocos2d::Vec3 &v2)
    float ret = cocos2d::Vec3::dot(*arg1, *arg2);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec3_dot(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "cc.Vec3")) && (olua_is_object(L, 2, "cc.Vec3"))) {
            // float dot(const cocos2d::Vec3 &v)
            return _olua_fun_cocos2d_Vec3_dot$1(L);
        }

        // if ((olua_is_object(L, 1, "cc.Vec3")) && (olua_is_object(L, 2, "cc.Vec3"))) {
            // static float dot(const cocos2d::Vec3 &v1, const cocos2d::Vec3 &v2)
            return _olua_fun_cocos2d_Vec3_dot$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec3::dot' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_fromColor(lua_State *L)
{
    olua_startinvoke(L);

    unsigned int arg1 = 0;       /** color */

    olua_check_integer(L, 1, &arg1);

    // static cocos2d::Vec3 fromColor(unsigned int color)
    cocos2d::Vec3 ret = cocos2d::Vec3::fromColor(arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Vec3");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec3_getNormalized(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec3");

    // cocos2d::Vec3 getNormalized()
    cocos2d::Vec3 ret = self->getNormalized();
    int num_ret = olua_copy_object(L, ret, "cc.Vec3");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec3_isOne(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec3");

    // bool isOne()
    bool ret = self->isOne();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec3_isZero(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec3");

    // bool isZero()
    bool ret = self->isZero();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec3_length(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec3");

    // float length()
    float ret = self->length();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec3_lengthSquared(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec3");

    // float lengthSquared()
    float ret = self->lengthSquared();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec3_lerp(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;
    cocos2d::Vec3 *arg1;       /** target */
    float arg2 = 0;       /** alpha */

    olua_to_object(L, 1, &self, "cc.Vec3");
    olua_check_object(L, 2, &arg1, "cc.Vec3");
    olua_check_number(L, 3, &arg2);

    // cocos2d::Vec3 lerp(const cocos2d::Vec3 &target, float alpha)
    cocos2d::Vec3 ret = self->lerp(*arg1, arg2);
    int num_ret = olua_copy_object(L, ret, "cc.Vec3");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec3_negate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec3");

    // void negate()
    self->negate();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_new$1(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::Vec3()
    cocos2d::Vec3 *ret = new cocos2d::Vec3();
    int num_ret = olua_push_object(L, ret, "cc.Vec3");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec3_new$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** xx */
    float arg2 = 0;       /** yy */
    float arg3 = 0;       /** zz */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // cocos2d::Vec3(float xx, float yy, float zz)
    cocos2d::Vec3 *ret = new cocos2d::Vec3(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.Vec3");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec3_new$3(lua_State *L)
{
    olua_startinvoke(L);

    float *arg1 = nullptr;       /** array */

    olua_check_pointer(L, 1, &arg1, "olua.float");

    // cocos2d::Vec3(const float *array)
    cocos2d::Vec3 *ret = new cocos2d::Vec3(arg1);
    int num_ret = olua_push_object(L, ret, "cc.Vec3");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec3_new$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *arg1;       /** p1 */
    cocos2d::Vec3 *arg2;       /** p2 */

    olua_check_object(L, 1, &arg1, "cc.Vec3");
    olua_check_object(L, 2, &arg2, "cc.Vec3");

    // cocos2d::Vec3(const cocos2d::Vec3 &p1, const cocos2d::Vec3 &p2)
    cocos2d::Vec3 *ret = new cocos2d::Vec3(*arg1, *arg2);
    int num_ret = olua_push_object(L, ret, "cc.Vec3");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec3_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // cocos2d::Vec3()
        return _olua_fun_cocos2d_Vec3_new$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_pointer(L, 1, "olua.float"))) {
            // cocos2d::Vec3(const float *array)
            return _olua_fun_cocos2d_Vec3_new$3(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec3")) && (olua_is_object(L, 2, "cc.Vec3"))) {
            // cocos2d::Vec3(const cocos2d::Vec3 &p1, const cocos2d::Vec3 &p2)
            return _olua_fun_cocos2d_Vec3_new$4(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // cocos2d::Vec3(float xx, float yy, float zz)
            return _olua_fun_cocos2d_Vec3_new$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec3::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_normalize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec3");

    // void normalize()
    self->normalize();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_scale(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;
    float arg1 = 0;       /** scalar */

    olua_to_object(L, 1, &self, "cc.Vec3");
    olua_check_number(L, 2, &arg1);

    // void scale(float scalar)
    self->scale(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_set$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;
    float arg1 = 0;       /** xx */
    float arg2 = 0;       /** yy */
    float arg3 = 0;       /** zz */

    olua_to_object(L, 1, &self, "cc.Vec3");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // void set(float xx, float yy, float zz)
    self->set(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_set$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;
    float *arg1 = nullptr;       /** array */

    olua_to_object(L, 1, &self, "cc.Vec3");
    olua_check_pointer(L, 2, &arg1, "olua.float");

    // void set(const float *array)
    self->set(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_set$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;
    cocos2d::Vec3 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec3");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // void set(const cocos2d::Vec3 &v)
    self->set(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_set$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;
    cocos2d::Vec3 *arg1;       /** p1 */
    cocos2d::Vec3 *arg2;       /** p2 */

    olua_to_object(L, 1, &self, "cc.Vec3");
    olua_check_object(L, 2, &arg1, "cc.Vec3");
    olua_check_object(L, 3, &arg2, "cc.Vec3");

    // void set(const cocos2d::Vec3 &p1, const cocos2d::Vec3 &p2)
    self->set(*arg1, *arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_set(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "cc.Vec3")) && (olua_is_pointer(L, 2, "olua.float"))) {
            // void set(const float *array)
            return _olua_fun_cocos2d_Vec3_set$2(L);
        }

        // if ((olua_is_object(L, 1, "cc.Vec3")) && (olua_is_object(L, 2, "cc.Vec3"))) {
            // void set(const cocos2d::Vec3 &v)
            return _olua_fun_cocos2d_Vec3_set$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Vec3")) && (olua_is_object(L, 2, "cc.Vec3")) && (olua_is_object(L, 3, "cc.Vec3"))) {
            // void set(const cocos2d::Vec3 &p1, const cocos2d::Vec3 &p2)
            return _olua_fun_cocos2d_Vec3_set$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.Vec3")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4))) {
            // void set(float xx, float yy, float zz)
            return _olua_fun_cocos2d_Vec3_set$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec3::set' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_setZero(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec3");

    // void setZero()
    self->setZero();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_smooth(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;
    cocos2d::Vec3 *arg1;       /** target */
    float arg2 = 0;       /** elapsedTime */
    float arg3 = 0;       /** responseTime */

    olua_to_object(L, 1, &self, "cc.Vec3");
    olua_check_object(L, 2, &arg1, "cc.Vec3");
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // void smooth(const cocos2d::Vec3 &target, float elapsedTime, float responseTime)
    self->smooth(*arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_subtract$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;
    cocos2d::Vec3 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec3");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // void subtract(const cocos2d::Vec3 &v)
    self->subtract(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_subtract$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *arg1;       /** v1 */
    cocos2d::Vec3 *arg2;       /** v2 */
    cocos2d::Vec3 *arg3 = nullptr;       /** dst */

    olua_check_object(L, 1, &arg1, "cc.Vec3");
    olua_check_object(L, 2, &arg2, "cc.Vec3");
    olua_check_object(L, 3, &arg3, "cc.Vec3");

    // static void subtract(const cocos2d::Vec3 &v1, const cocos2d::Vec3 &v2, cocos2d::Vec3 *dst)
    cocos2d::Vec3::subtract(*arg1, *arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_subtract(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec3")) && (olua_is_object(L, 2, "cc.Vec3"))) {
            // void subtract(const cocos2d::Vec3 &v)
            return _olua_fun_cocos2d_Vec3_subtract$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Vec3")) && (olua_is_object(L, 2, "cc.Vec3")) && (olua_is_object(L, 3, "cc.Vec3"))) {
            // static void subtract(const cocos2d::Vec3 &v1, const cocos2d::Vec3 &v2, cocos2d::Vec3 *dst)
            return _olua_fun_cocos2d_Vec3_subtract$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec3::subtract' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_x$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec3");

    // float x
    float ret = self->x;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec3_x$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;
    float arg1 = 0;       /** x */

    olua_to_object(L, 1, &self, "cc.Vec3");
    olua_check_number(L, 2, &arg1);

    // float x
    self->x = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_x(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float x
        return _olua_fun_cocos2d_Vec3_x$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec3")) && (olua_is_number(L, 2))) {
            // float x
            return _olua_fun_cocos2d_Vec3_x$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec3::x' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_y$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec3");

    // float y
    float ret = self->y;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec3_y$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;
    float arg1 = 0;       /** y */

    olua_to_object(L, 1, &self, "cc.Vec3");
    olua_check_number(L, 2, &arg1);

    // float y
    self->y = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_y(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float y
        return _olua_fun_cocos2d_Vec3_y$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec3")) && (olua_is_number(L, 2))) {
            // float y
            return _olua_fun_cocos2d_Vec3_y$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec3::y' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_z$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec3");

    // float z
    float ret = self->z;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec3_z$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *self = nullptr;
    float arg1 = 0;       /** z */

    olua_to_object(L, 1, &self, "cc.Vec3");
    olua_check_number(L, 2, &arg1);

    // float z
    self->z = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec3_z(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float z
        return _olua_fun_cocos2d_Vec3_z$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec3")) && (olua_is_number(L, 2))) {
            // float z
            return _olua_fun_cocos2d_Vec3_z$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec3::z' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_cc_Vec3(lua_State *L)
{
    oluacls_class<cocos2d::Vec3>(L, "cc.Vec3");
    oluacls_func(L, "__add", _olua_fun_cocos2d_Vec3___add);
    oluacls_func(L, "__div", _olua_fun_cocos2d_Vec3___div);
    oluacls_func(L, "__eq", _olua_fun_cocos2d_Vec3___eq);
    oluacls_func(L, "__gc", _olua_fun_cocos2d_Vec3___gc);
    oluacls_func(L, "__lt", _olua_fun_cocos2d_Vec3___lt);
    oluacls_func(L, "__mul", _olua_fun_cocos2d_Vec3___mul);
    oluacls_func(L, "__sub", _olua_fun_cocos2d_Vec3___sub);
    oluacls_func(L, "__unm", _olua_fun_cocos2d_Vec3___unm);
    oluacls_func(L, "add", _olua_fun_cocos2d_Vec3_add);
    oluacls_func(L, "angle", _olua_fun_cocos2d_Vec3_angle);
    oluacls_func(L, "clamp", _olua_fun_cocos2d_Vec3_clamp);
    oluacls_func(L, "cross", _olua_fun_cocos2d_Vec3_cross);
    oluacls_func(L, "distance", _olua_fun_cocos2d_Vec3_distance);
    oluacls_func(L, "distanceSquared", _olua_fun_cocos2d_Vec3_distanceSquared);
    oluacls_func(L, "dot", _olua_fun_cocos2d_Vec3_dot);
    oluacls_func(L, "fromColor", _olua_fun_cocos2d_Vec3_fromColor);
    oluacls_func(L, "getNormalized", _olua_fun_cocos2d_Vec3_getNormalized);
    oluacls_func(L, "isOne", _olua_fun_cocos2d_Vec3_isOne);
    oluacls_func(L, "isZero", _olua_fun_cocos2d_Vec3_isZero);
    oluacls_func(L, "length", _olua_fun_cocos2d_Vec3_length);
    oluacls_func(L, "lengthSquared", _olua_fun_cocos2d_Vec3_lengthSquared);
    oluacls_func(L, "lerp", _olua_fun_cocos2d_Vec3_lerp);
    oluacls_func(L, "negate", _olua_fun_cocos2d_Vec3_negate);
    oluacls_func(L, "new", _olua_fun_cocos2d_Vec3_new);
    oluacls_func(L, "normalize", _olua_fun_cocos2d_Vec3_normalize);
    oluacls_func(L, "scale", _olua_fun_cocos2d_Vec3_scale);
    oluacls_func(L, "set", _olua_fun_cocos2d_Vec3_set);
    oluacls_func(L, "setZero", _olua_fun_cocos2d_Vec3_setZero);
    oluacls_func(L, "smooth", _olua_fun_cocos2d_Vec3_smooth);
    oluacls_func(L, "subtract", _olua_fun_cocos2d_Vec3_subtract);
    oluacls_prop(L, "normalized", _olua_fun_cocos2d_Vec3_getNormalized, nullptr);
    oluacls_prop(L, "one", _olua_fun_cocos2d_Vec3_isOne, nullptr);
    oluacls_prop(L, "zero", _olua_fun_cocos2d_Vec3_isZero, _olua_fun_cocos2d_Vec3_setZero);
    oluacls_prop(L, "x", _olua_fun_cocos2d_Vec3_x, _olua_fun_cocos2d_Vec3_x);
    oluacls_prop(L, "y", _olua_fun_cocos2d_Vec3_y, _olua_fun_cocos2d_Vec3_y);
    oluacls_prop(L, "z", _olua_fun_cocos2d_Vec3_z, _olua_fun_cocos2d_Vec3_z);
    oluacls_const(L, "ONE", &cocos2d::Vec3::ONE);
    oluacls_const(L, "UNIT_X", &cocos2d::Vec3::UNIT_X);
    oluacls_const(L, "UNIT_Y", &cocos2d::Vec3::UNIT_Y);
    oluacls_const(L, "UNIT_Z", &cocos2d::Vec3::UNIT_Z);
    oluacls_const(L, "ZERO", &cocos2d::Vec3::ZERO);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cc_Vec3(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "cc.Vec3")) {
        luaL_error(L, "class not found: cocos2d::Vec3");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_Vec4___add(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;
    cocos2d::Vec4 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec4");
    olua_check_object(L, 2, &arg1, "cc.Vec4");

    // @operator(operator+) cocos2d::Vec4 operator+(const cocos2d::Vec4 &v)
    cocos2d::Vec4 ret = (*self) + (*arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Vec4");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec4___div(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;
    float arg1 = 0;       /** s */

    olua_to_object(L, 1, &self, "cc.Vec4");
    olua_check_number(L, 2, &arg1);

    // @operator(operator/) cocos2d::Vec4 operator/(float s)
    cocos2d::Vec4 ret = (*self) / (arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Vec4");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec4___eq(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;
    cocos2d::Vec4 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec4");
    olua_check_object(L, 2, &arg1, "cc.Vec4");

    // @operator(operator==) bool operator==(const cocos2d::Vec4 &v)
    bool ret = (*self) == (*arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec4___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Vec4 *)olua_toobj(L, 1, "cc.Vec4");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec4___lt(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;
    cocos2d::Vec4 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec4");
    olua_check_object(L, 2, &arg1, "cc.Vec4");

    // @operator(operator<) bool operator<(const cocos2d::Vec4 &v)
    bool ret = (*self) < (*arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec4___mul(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;
    float arg1 = 0;       /** s */

    olua_to_object(L, 1, &self, "cc.Vec4");
    olua_check_number(L, 2, &arg1);

    // @operator(operator*) cocos2d::Vec4 operator*(float s)
    cocos2d::Vec4 ret = (*self) * (arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Vec4");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec4___sub(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;
    cocos2d::Vec4 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec4");
    olua_check_object(L, 2, &arg1, "cc.Vec4");

    // @operator(operator-) cocos2d::Vec4 operator-(const cocos2d::Vec4 &v)
    cocos2d::Vec4 ret = (*self) - (*arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Vec4");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec4___unm(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec4");

    // @operator(operator-) cocos2d::Vec4 operator-()
    cocos2d::Vec4 ret = -(*self);
    int num_ret = olua_copy_object(L, ret, "cc.Vec4");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec4_add$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;
    cocos2d::Vec4 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec4");
    olua_check_object(L, 2, &arg1, "cc.Vec4");

    // void add(const cocos2d::Vec4 &v)
    self->add(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec4_add$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *arg1;       /** v1 */
    cocos2d::Vec4 *arg2;       /** v2 */
    cocos2d::Vec4 *arg3 = nullptr;       /** dst */

    olua_check_object(L, 1, &arg1, "cc.Vec4");
    olua_check_object(L, 2, &arg2, "cc.Vec4");
    olua_check_object(L, 3, &arg3, "cc.Vec4");

    // static void add(const cocos2d::Vec4 &v1, const cocos2d::Vec4 &v2, cocos2d::Vec4 *dst)
    cocos2d::Vec4::add(*arg1, *arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec4_add(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec4")) && (olua_is_object(L, 2, "cc.Vec4"))) {
            // void add(const cocos2d::Vec4 &v)
            return _olua_fun_cocos2d_Vec4_add$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Vec4")) && (olua_is_object(L, 2, "cc.Vec4")) && (olua_is_object(L, 3, "cc.Vec4"))) {
            // static void add(const cocos2d::Vec4 &v1, const cocos2d::Vec4 &v2, cocos2d::Vec4 *dst)
            return _olua_fun_cocos2d_Vec4_add$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec4::add' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec4_angle(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *arg1;       /** v1 */
    cocos2d::Vec4 *arg2;       /** v2 */

    olua_check_object(L, 1, &arg1, "cc.Vec4");
    olua_check_object(L, 2, &arg2, "cc.Vec4");

    // static float angle(const cocos2d::Vec4 &v1, const cocos2d::Vec4 &v2)
    float ret = cocos2d::Vec4::angle(*arg1, *arg2);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec4_clamp$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;
    cocos2d::Vec4 *arg1;       /** min */
    cocos2d::Vec4 *arg2;       /** max */

    olua_to_object(L, 1, &self, "cc.Vec4");
    olua_check_object(L, 2, &arg1, "cc.Vec4");
    olua_check_object(L, 3, &arg2, "cc.Vec4");

    // void clamp(const cocos2d::Vec4 &min, const cocos2d::Vec4 &max)
    self->clamp(*arg1, *arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec4_clamp$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *arg1;       /** v */
    cocos2d::Vec4 *arg2;       /** min */
    cocos2d::Vec4 *arg3;       /** max */
    cocos2d::Vec4 *arg4 = nullptr;       /** dst */

    olua_check_object(L, 1, &arg1, "cc.Vec4");
    olua_check_object(L, 2, &arg2, "cc.Vec4");
    olua_check_object(L, 3, &arg3, "cc.Vec4");
    olua_check_object(L, 4, &arg4, "cc.Vec4");

    // static void clamp(const cocos2d::Vec4 &v, const cocos2d::Vec4 &min, const cocos2d::Vec4 &max, cocos2d::Vec4 *dst)
    cocos2d::Vec4::clamp(*arg1, *arg2, *arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec4_clamp(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Vec4")) && (olua_is_object(L, 2, "cc.Vec4")) && (olua_is_object(L, 3, "cc.Vec4"))) {
            // void clamp(const cocos2d::Vec4 &min, const cocos2d::Vec4 &max)
            return _olua_fun_cocos2d_Vec4_clamp$1(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.Vec4")) && (olua_is_object(L, 2, "cc.Vec4")) && (olua_is_object(L, 3, "cc.Vec4")) && (olua_is_object(L, 4, "cc.Vec4"))) {
            // static void clamp(const cocos2d::Vec4 &v, const cocos2d::Vec4 &min, const cocos2d::Vec4 &max, cocos2d::Vec4 *dst)
            return _olua_fun_cocos2d_Vec4_clamp$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec4::clamp' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec4_distance(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;
    cocos2d::Vec4 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec4");
    olua_check_object(L, 2, &arg1, "cc.Vec4");

    // float distance(const cocos2d::Vec4 &v)
    float ret = self->distance(*arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec4_distanceSquared(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;
    cocos2d::Vec4 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec4");
    olua_check_object(L, 2, &arg1, "cc.Vec4");

    // float distanceSquared(const cocos2d::Vec4 &v)
    float ret = self->distanceSquared(*arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec4_dot$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;
    cocos2d::Vec4 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec4");
    olua_check_object(L, 2, &arg1, "cc.Vec4");

    // float dot(const cocos2d::Vec4 &v)
    float ret = self->dot(*arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec4_dot$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *arg1;       /** v1 */
    cocos2d::Vec4 *arg2;       /** v2 */

    olua_check_object(L, 1, &arg1, "cc.Vec4");
    olua_check_object(L, 2, &arg2, "cc.Vec4");

    // static float dot(const cocos2d::Vec4 &v1, const cocos2d::Vec4 &v2)
    float ret = cocos2d::Vec4::dot(*arg1, *arg2);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec4_dot(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "cc.Vec4")) && (olua_is_object(L, 2, "cc.Vec4"))) {
            // float dot(const cocos2d::Vec4 &v)
            return _olua_fun_cocos2d_Vec4_dot$1(L);
        }

        // if ((olua_is_object(L, 1, "cc.Vec4")) && (olua_is_object(L, 2, "cc.Vec4"))) {
            // static float dot(const cocos2d::Vec4 &v1, const cocos2d::Vec4 &v2)
            return _olua_fun_cocos2d_Vec4_dot$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec4::dot' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec4_fromColor(lua_State *L)
{
    olua_startinvoke(L);

    unsigned int arg1 = 0;       /** color */

    olua_check_integer(L, 1, &arg1);

    // static cocos2d::Vec4 fromColor(unsigned int color)
    cocos2d::Vec4 ret = cocos2d::Vec4::fromColor(arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Vec4");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec4_getNormalized(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec4");

    // cocos2d::Vec4 getNormalized()
    cocos2d::Vec4 ret = self->getNormalized();
    int num_ret = olua_copy_object(L, ret, "cc.Vec4");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec4_isOne(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec4");

    // bool isOne()
    bool ret = self->isOne();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec4_isZero(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec4");

    // bool isZero()
    bool ret = self->isZero();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec4_length(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec4");

    // float length()
    float ret = self->length();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec4_lengthSquared(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec4");

    // float lengthSquared()
    float ret = self->lengthSquared();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec4_negate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec4");

    // void negate()
    self->negate();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec4_new$1(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::Vec4()
    cocos2d::Vec4 *ret = new cocos2d::Vec4();
    int num_ret = olua_push_object(L, ret, "cc.Vec4");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec4_new$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** xx */
    float arg2 = 0;       /** yy */
    float arg3 = 0;       /** zz */
    float arg4 = 0;       /** ww */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // cocos2d::Vec4(float xx, float yy, float zz, float ww)
    cocos2d::Vec4 *ret = new cocos2d::Vec4(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.Vec4");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec4_new$3(lua_State *L)
{
    olua_startinvoke(L);

    float *arg1 = nullptr;       /** array */

    olua_check_pointer(L, 1, &arg1, "olua.float");

    // cocos2d::Vec4(const float *array)
    cocos2d::Vec4 *ret = new cocos2d::Vec4(arg1);
    int num_ret = olua_push_object(L, ret, "cc.Vec4");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec4_new$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *arg1;       /** p1 */
    cocos2d::Vec4 *arg2;       /** p2 */

    olua_check_object(L, 1, &arg1, "cc.Vec4");
    olua_check_object(L, 2, &arg2, "cc.Vec4");

    // cocos2d::Vec4(const cocos2d::Vec4 &p1, const cocos2d::Vec4 &p2)
    cocos2d::Vec4 *ret = new cocos2d::Vec4(*arg1, *arg2);
    int num_ret = olua_push_object(L, ret, "cc.Vec4");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec4_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // cocos2d::Vec4()
        return _olua_fun_cocos2d_Vec4_new$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_pointer(L, 1, "olua.float"))) {
            // cocos2d::Vec4(const float *array)
            return _olua_fun_cocos2d_Vec4_new$3(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec4")) && (olua_is_object(L, 2, "cc.Vec4"))) {
            // cocos2d::Vec4(const cocos2d::Vec4 &p1, const cocos2d::Vec4 &p2)
            return _olua_fun_cocos2d_Vec4_new$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4))) {
            // cocos2d::Vec4(float xx, float yy, float zz, float ww)
            return _olua_fun_cocos2d_Vec4_new$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec4::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec4_normalize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec4");

    // void normalize()
    self->normalize();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec4_scale(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;
    float arg1 = 0;       /** scalar */

    olua_to_object(L, 1, &self, "cc.Vec4");
    olua_check_number(L, 2, &arg1);

    // void scale(float scalar)
    self->scale(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec4_set$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;
    float arg1 = 0;       /** xx */
    float arg2 = 0;       /** yy */
    float arg3 = 0;       /** zz */
    float arg4 = 0;       /** ww */

    olua_to_object(L, 1, &self, "cc.Vec4");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // void set(float xx, float yy, float zz, float ww)
    self->set(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec4_set$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;
    float *arg1 = nullptr;       /** array */

    olua_to_object(L, 1, &self, "cc.Vec4");
    olua_check_pointer(L, 2, &arg1, "olua.float");

    // void set(const float *array)
    self->set(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec4_set$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;
    cocos2d::Vec4 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec4");
    olua_check_object(L, 2, &arg1, "cc.Vec4");

    // void set(const cocos2d::Vec4 &v)
    self->set(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec4_set$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;
    cocos2d::Vec4 *arg1;       /** p1 */
    cocos2d::Vec4 *arg2;       /** p2 */

    olua_to_object(L, 1, &self, "cc.Vec4");
    olua_check_object(L, 2, &arg1, "cc.Vec4");
    olua_check_object(L, 3, &arg2, "cc.Vec4");

    // void set(const cocos2d::Vec4 &p1, const cocos2d::Vec4 &p2)
    self->set(*arg1, *arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec4_set(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "cc.Vec4")) && (olua_is_pointer(L, 2, "olua.float"))) {
            // void set(const float *array)
            return _olua_fun_cocos2d_Vec4_set$2(L);
        }

        // if ((olua_is_object(L, 1, "cc.Vec4")) && (olua_is_object(L, 2, "cc.Vec4"))) {
            // void set(const cocos2d::Vec4 &v)
            return _olua_fun_cocos2d_Vec4_set$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Vec4")) && (olua_is_object(L, 2, "cc.Vec4")) && (olua_is_object(L, 3, "cc.Vec4"))) {
            // void set(const cocos2d::Vec4 &p1, const cocos2d::Vec4 &p2)
            return _olua_fun_cocos2d_Vec4_set$4(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "cc.Vec4")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5))) {
            // void set(float xx, float yy, float zz, float ww)
            return _olua_fun_cocos2d_Vec4_set$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec4::set' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec4_subtract$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;
    cocos2d::Vec4 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Vec4");
    olua_check_object(L, 2, &arg1, "cc.Vec4");

    // void subtract(const cocos2d::Vec4 &v)
    self->subtract(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec4_subtract$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *arg1;       /** v1 */
    cocos2d::Vec4 *arg2;       /** v2 */
    cocos2d::Vec4 *arg3 = nullptr;       /** dst */

    olua_check_object(L, 1, &arg1, "cc.Vec4");
    olua_check_object(L, 2, &arg2, "cc.Vec4");
    olua_check_object(L, 3, &arg3, "cc.Vec4");

    // static void subtract(const cocos2d::Vec4 &v1, const cocos2d::Vec4 &v2, cocos2d::Vec4 *dst)
    cocos2d::Vec4::subtract(*arg1, *arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec4_subtract(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec4")) && (olua_is_object(L, 2, "cc.Vec4"))) {
            // void subtract(const cocos2d::Vec4 &v)
            return _olua_fun_cocos2d_Vec4_subtract$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Vec4")) && (olua_is_object(L, 2, "cc.Vec4")) && (olua_is_object(L, 3, "cc.Vec4"))) {
            // static void subtract(const cocos2d::Vec4 &v1, const cocos2d::Vec4 &v2, cocos2d::Vec4 *dst)
            return _olua_fun_cocos2d_Vec4_subtract$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec4::subtract' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec4_w$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec4");

    // float w
    float ret = self->w;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec4_w$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;
    float arg1 = 0;       /** w */

    olua_to_object(L, 1, &self, "cc.Vec4");
    olua_check_number(L, 2, &arg1);

    // float w
    self->w = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec4_w(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float w
        return _olua_fun_cocos2d_Vec4_w$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec4")) && (olua_is_number(L, 2))) {
            // float w
            return _olua_fun_cocos2d_Vec4_w$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec4::w' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec4_x$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec4");

    // float x
    float ret = self->x;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec4_x$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;
    float arg1 = 0;       /** x */

    olua_to_object(L, 1, &self, "cc.Vec4");
    olua_check_number(L, 2, &arg1);

    // float x
    self->x = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec4_x(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float x
        return _olua_fun_cocos2d_Vec4_x$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec4")) && (olua_is_number(L, 2))) {
            // float x
            return _olua_fun_cocos2d_Vec4_x$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec4::x' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec4_y$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec4");

    // float y
    float ret = self->y;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec4_y$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;
    float arg1 = 0;       /** y */

    olua_to_object(L, 1, &self, "cc.Vec4");
    olua_check_number(L, 2, &arg1);

    // float y
    self->y = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec4_y(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float y
        return _olua_fun_cocos2d_Vec4_y$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec4")) && (olua_is_number(L, 2))) {
            // float y
            return _olua_fun_cocos2d_Vec4_y$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec4::y' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Vec4_z$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Vec4");

    // float z
    float ret = self->z;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Vec4_z$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec4 *self = nullptr;
    float arg1 = 0;       /** z */

    olua_to_object(L, 1, &self, "cc.Vec4");
    olua_check_number(L, 2, &arg1);

    // float z
    self->z = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Vec4_z(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float z
        return _olua_fun_cocos2d_Vec4_z$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec4")) && (olua_is_number(L, 2))) {
            // float z
            return _olua_fun_cocos2d_Vec4_z$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Vec4::z' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_cc_Vec4(lua_State *L)
{
    oluacls_class<cocos2d::Vec4>(L, "cc.Vec4");
    oluacls_func(L, "__add", _olua_fun_cocos2d_Vec4___add);
    oluacls_func(L, "__div", _olua_fun_cocos2d_Vec4___div);
    oluacls_func(L, "__eq", _olua_fun_cocos2d_Vec4___eq);
    oluacls_func(L, "__gc", _olua_fun_cocos2d_Vec4___gc);
    oluacls_func(L, "__lt", _olua_fun_cocos2d_Vec4___lt);
    oluacls_func(L, "__mul", _olua_fun_cocos2d_Vec4___mul);
    oluacls_func(L, "__sub", _olua_fun_cocos2d_Vec4___sub);
    oluacls_func(L, "__unm", _olua_fun_cocos2d_Vec4___unm);
    oluacls_func(L, "add", _olua_fun_cocos2d_Vec4_add);
    oluacls_func(L, "angle", _olua_fun_cocos2d_Vec4_angle);
    oluacls_func(L, "clamp", _olua_fun_cocos2d_Vec4_clamp);
    oluacls_func(L, "distance", _olua_fun_cocos2d_Vec4_distance);
    oluacls_func(L, "distanceSquared", _olua_fun_cocos2d_Vec4_distanceSquared);
    oluacls_func(L, "dot", _olua_fun_cocos2d_Vec4_dot);
    oluacls_func(L, "fromColor", _olua_fun_cocos2d_Vec4_fromColor);
    oluacls_func(L, "getNormalized", _olua_fun_cocos2d_Vec4_getNormalized);
    oluacls_func(L, "isOne", _olua_fun_cocos2d_Vec4_isOne);
    oluacls_func(L, "isZero", _olua_fun_cocos2d_Vec4_isZero);
    oluacls_func(L, "length", _olua_fun_cocos2d_Vec4_length);
    oluacls_func(L, "lengthSquared", _olua_fun_cocos2d_Vec4_lengthSquared);
    oluacls_func(L, "negate", _olua_fun_cocos2d_Vec4_negate);
    oluacls_func(L, "new", _olua_fun_cocos2d_Vec4_new);
    oluacls_func(L, "normalize", _olua_fun_cocos2d_Vec4_normalize);
    oluacls_func(L, "scale", _olua_fun_cocos2d_Vec4_scale);
    oluacls_func(L, "set", _olua_fun_cocos2d_Vec4_set);
    oluacls_func(L, "subtract", _olua_fun_cocos2d_Vec4_subtract);
    oluacls_prop(L, "normalized", _olua_fun_cocos2d_Vec4_getNormalized, nullptr);
    oluacls_prop(L, "one", _olua_fun_cocos2d_Vec4_isOne, nullptr);
    oluacls_prop(L, "zero", _olua_fun_cocos2d_Vec4_isZero, nullptr);
    oluacls_prop(L, "x", _olua_fun_cocos2d_Vec4_x, _olua_fun_cocos2d_Vec4_x);
    oluacls_prop(L, "y", _olua_fun_cocos2d_Vec4_y, _olua_fun_cocos2d_Vec4_y);
    oluacls_prop(L, "z", _olua_fun_cocos2d_Vec4_z, _olua_fun_cocos2d_Vec4_z);
    oluacls_prop(L, "w", _olua_fun_cocos2d_Vec4_w, _olua_fun_cocos2d_Vec4_w);
    oluacls_const(L, "ONE", &cocos2d::Vec4::ONE);
    oluacls_const(L, "UNIT_W", &cocos2d::Vec4::UNIT_W);
    oluacls_const(L, "UNIT_X", &cocos2d::Vec4::UNIT_X);
    oluacls_const(L, "UNIT_Y", &cocos2d::Vec4::UNIT_Y);
    oluacls_const(L, "UNIT_Z", &cocos2d::Vec4::UNIT_Z);
    oluacls_const(L, "ZERO", &cocos2d::Vec4::ZERO);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cc_Vec4(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "cc.Vec4")) {
        luaL_error(L, "class not found: cocos2d::Vec4");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_Size___add(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size *self = nullptr;
    cocos2d::Size *arg1;       /** right */

    olua_to_object(L, 1, &self, "cc.Size");
    olua_check_object(L, 2, &arg1, "cc.Size");

    // @operator(operator+) cocos2d::Size operator+(const cocos2d::Size &right)
    cocos2d::Size ret = (*self) + (*arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Size");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Size___div(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size *self = nullptr;
    float arg1 = 0;       /** a */

    olua_to_object(L, 1, &self, "cc.Size");
    olua_check_number(L, 2, &arg1);

    // @operator(operator/) cocos2d::Size operator/(float a)
    cocos2d::Size ret = (*self) / (arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Size");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Size___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Size *)olua_toobj(L, 1, "cc.Size");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Size___mul(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size *self = nullptr;
    float arg1 = 0;       /** a */

    olua_to_object(L, 1, &self, "cc.Size");
    olua_check_number(L, 2, &arg1);

    // @operator(operator*) cocos2d::Size operator*(float a)
    cocos2d::Size ret = (*self) * (arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Size");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Size___sub(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size *self = nullptr;
    cocos2d::Size *arg1;       /** right */

    olua_to_object(L, 1, &self, "cc.Size");
    olua_check_object(L, 2, &arg1, "cc.Size");

    // @operator(operator-) cocos2d::Size operator-(const cocos2d::Size &right)
    cocos2d::Size ret = (*self) - (*arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Size");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Size_equals(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size *self = nullptr;
    cocos2d::Size *arg1;       /** target */

    olua_to_object(L, 1, &self, "cc.Size");
    olua_check_object(L, 2, &arg1, "cc.Size");

    // bool equals(const cocos2d::Size &target)
    bool ret = self->equals(*arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Size_height$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Size");

    // float height
    float ret = self->height;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Size_height$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size *self = nullptr;
    float arg1 = 0;       /** height */

    olua_to_object(L, 1, &self, "cc.Size");
    olua_check_number(L, 2, &arg1);

    // float height
    self->height = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Size_height(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float height
        return _olua_fun_cocos2d_Size_height$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Size")) && (olua_is_number(L, 2))) {
            // float height
            return _olua_fun_cocos2d_Size_height$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Size::height' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Size_new$1(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::Size()
    cocos2d::Size *ret = new cocos2d::Size();
    int num_ret = olua_push_object(L, ret, "cc.Size");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Size_new$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** width */
    float arg2 = 0;       /** height */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // cocos2d::Size(float width, float height)
    cocos2d::Size *ret = new cocos2d::Size(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.Size");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Size_new$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1;       /** point */

    olua_check_object(L, 1, &arg1, "cc.Vec2");

    // cocos2d::Size(const cocos2d::Vec2 &point)
    cocos2d::Size *ret = new cocos2d::Size(*arg1);
    int num_ret = olua_push_object(L, ret, "cc.Size");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Size_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // cocos2d::Size()
        return _olua_fun_cocos2d_Size_new$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_object(L, 1, "cc.Vec2"))) {
            // cocos2d::Size(const cocos2d::Vec2 &point)
            return _olua_fun_cocos2d_Size_new$3(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2))) {
            // cocos2d::Size(float width, float height)
            return _olua_fun_cocos2d_Size_new$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Size::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Size_setSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size *self = nullptr;
    float arg1 = 0;       /** width */
    float arg2 = 0;       /** height */

    olua_to_object(L, 1, &self, "cc.Size");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void setSize(float width, float height)
    self->setSize(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Size_width$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Size");

    // float width
    float ret = self->width;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Size_width$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size *self = nullptr;
    float arg1 = 0;       /** width */

    olua_to_object(L, 1, &self, "cc.Size");
    olua_check_number(L, 2, &arg1);

    // float width
    self->width = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Size_width(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float width
        return _olua_fun_cocos2d_Size_width$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Size")) && (olua_is_number(L, 2))) {
            // float width
            return _olua_fun_cocos2d_Size_width$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Size::width' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_cc_Size(lua_State *L)
{
    oluacls_class<cocos2d::Size>(L, "cc.Size");
    oluacls_func(L, "__add", _olua_fun_cocos2d_Size___add);
    oluacls_func(L, "__div", _olua_fun_cocos2d_Size___div);
    oluacls_func(L, "__gc", _olua_fun_cocos2d_Size___gc);
    oluacls_func(L, "__mul", _olua_fun_cocos2d_Size___mul);
    oluacls_func(L, "__sub", _olua_fun_cocos2d_Size___sub);
    oluacls_func(L, "equals", _olua_fun_cocos2d_Size_equals);
    oluacls_func(L, "new", _olua_fun_cocos2d_Size_new);
    oluacls_func(L, "setSize", _olua_fun_cocos2d_Size_setSize);
    oluacls_prop(L, "width", _olua_fun_cocos2d_Size_width, _olua_fun_cocos2d_Size_width);
    oluacls_prop(L, "height", _olua_fun_cocos2d_Size_height, _olua_fun_cocos2d_Size_height);
    oluacls_const(L, "ZERO", &cocos2d::Size::ZERO);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cc_Size(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "cc.Size")) {
        luaL_error(L, "class not found: cocos2d::Size");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_Rect___call(lua_State *L)
{
    olua_startinvoke(L);

    // @extend(cocos2d::RectExtend) static olua_Return __call(lua_State *L)
    olua_Return ret = cocos2d::RectExtend::__call(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_cocos2d_Rect___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Rect *)olua_toobj(L, 1, "cc.Rect");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Rect_containsPoint(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Rect *self = nullptr;
    cocos2d::Vec2 *arg1;       /** point */

    olua_to_object(L, 1, &self, "cc.Rect");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // bool containsPoint(const cocos2d::Vec2 &point)
    bool ret = self->containsPoint(*arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Rect_equals(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Rect *self = nullptr;
    cocos2d::Rect *arg1;       /** rect */

    olua_to_object(L, 1, &self, "cc.Rect");
    olua_check_object(L, 2, &arg1, "cc.Rect");

    // bool equals(const cocos2d::Rect &rect)
    bool ret = self->equals(*arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Rect_getMaxX(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Rect *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Rect");

    // float getMaxX()
    float ret = self->getMaxX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Rect_getMaxY(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Rect *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Rect");

    // float getMaxY()
    float ret = self->getMaxY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Rect_getMidX(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Rect *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Rect");

    // float getMidX()
    float ret = self->getMidX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Rect_getMidY(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Rect *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Rect");

    // float getMidY()
    float ret = self->getMidY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Rect_getMinX(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Rect *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Rect");

    // float getMinX()
    float ret = self->getMinX();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Rect_getMinY(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Rect *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Rect");

    // float getMinY()
    float ret = self->getMinY();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Rect_intersectsCircle(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Rect *self = nullptr;
    cocos2d::Vec2 *arg1;       /** center */
    float arg2 = 0;       /** radius */

    olua_to_object(L, 1, &self, "cc.Rect");
    olua_check_object(L, 2, &arg1, "cc.Vec2");
    olua_check_number(L, 3, &arg2);

    // bool intersectsCircle(const cocos2d::Vec2 &center, float radius)
    bool ret = self->intersectsCircle(*arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Rect_intersectsRect(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Rect *self = nullptr;
    cocos2d::Rect *arg1;       /** rect */

    olua_to_object(L, 1, &self, "cc.Rect");
    olua_check_object(L, 2, &arg1, "cc.Rect");

    // bool intersectsRect(const cocos2d::Rect &rect)
    bool ret = self->intersectsRect(*arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Rect_merge(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Rect *self = nullptr;
    cocos2d::Rect *arg1;       /** rect */

    olua_to_object(L, 1, &self, "cc.Rect");
    olua_check_object(L, 2, &arg1, "cc.Rect");

    // void merge(const cocos2d::Rect &rect)
    self->merge(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Rect_new$1(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::Rect()
    cocos2d::Rect *ret = new cocos2d::Rect();
    int num_ret = olua_push_object(L, ret, "cc.Rect");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Rect_new$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** x */
    float arg2 = 0;       /** y */
    float arg3 = 0;       /** width */
    float arg4 = 0;       /** height */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // cocos2d::Rect(float x, float y, float width, float height)
    cocos2d::Rect *ret = new cocos2d::Rect(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.Rect");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Rect_new$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1;       /** pos */
    cocos2d::Size *arg2;       /** dimension */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_object(L, 2, &arg2, "cc.Size");

    // cocos2d::Rect(const cocos2d::Vec2 &pos, const cocos2d::Size &dimension)
    cocos2d::Rect *ret = new cocos2d::Rect(*arg1, *arg2);
    int num_ret = olua_push_object(L, ret, "cc.Rect");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Rect_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // cocos2d::Rect()
        return _olua_fun_cocos2d_Rect_new$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_object(L, 2, "cc.Size"))) {
            // cocos2d::Rect(const cocos2d::Vec2 &pos, const cocos2d::Size &dimension)
            return _olua_fun_cocos2d_Rect_new$3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4))) {
            // cocos2d::Rect(float x, float y, float width, float height)
            return _olua_fun_cocos2d_Rect_new$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Rect::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Rect_origin$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Rect *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Rect");

    // cocos2d::Vec2 origin
    cocos2d::Vec2 &ret = self->origin;
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Rect_origin$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Rect *self = nullptr;
    cocos2d::Vec2 *arg1;       /** origin */

    olua_to_object(L, 1, &self, "cc.Rect");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // cocos2d::Vec2 origin
    self->origin = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Rect_origin(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::Vec2 origin
        return _olua_fun_cocos2d_Rect_origin$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Rect")) && (olua_is_object(L, 2, "cc.Vec2"))) {
            // cocos2d::Vec2 origin
            return _olua_fun_cocos2d_Rect_origin$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Rect::origin' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Rect_setRect(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Rect *self = nullptr;
    float arg1 = 0;       /** x */
    float arg2 = 0;       /** y */
    float arg3 = 0;       /** width */
    float arg4 = 0;       /** height */

    olua_to_object(L, 1, &self, "cc.Rect");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // void setRect(float x, float y, float width, float height)
    self->setRect(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Rect_size$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Rect *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Rect");

    // cocos2d::Size size
    cocos2d::Size &ret = self->size;
    int num_ret = olua_copy_object(L, ret, "cc.Size");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Rect_size$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Rect *self = nullptr;
    cocos2d::Size *arg1;       /** size */

    olua_to_object(L, 1, &self, "cc.Rect");
    olua_check_object(L, 2, &arg1, "cc.Size");

    // cocos2d::Size size
    self->size = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Rect_size(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::Size size
        return _olua_fun_cocos2d_Rect_size$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Rect")) && (olua_is_object(L, 2, "cc.Size"))) {
            // cocos2d::Size size
            return _olua_fun_cocos2d_Rect_size$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Rect::size' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Rect_unionWithRect(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Rect *self = nullptr;
    cocos2d::Rect *arg1;       /** rect */

    olua_to_object(L, 1, &self, "cc.Rect");
    olua_check_object(L, 2, &arg1, "cc.Rect");

    // cocos2d::Rect unionWithRect(const cocos2d::Rect &rect)
    cocos2d::Rect ret = self->unionWithRect(*arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Rect");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_cc_Rect(lua_State *L)
{
    oluacls_class<cocos2d::Rect>(L, "cc.Rect");
    oluacls_func(L, "__call", _olua_fun_cocos2d_Rect___call);
    oluacls_func(L, "__gc", _olua_fun_cocos2d_Rect___gc);
    oluacls_func(L, "containsPoint", _olua_fun_cocos2d_Rect_containsPoint);
    oluacls_func(L, "equals", _olua_fun_cocos2d_Rect_equals);
    oluacls_func(L, "getMaxX", _olua_fun_cocos2d_Rect_getMaxX);
    oluacls_func(L, "getMaxY", _olua_fun_cocos2d_Rect_getMaxY);
    oluacls_func(L, "getMidX", _olua_fun_cocos2d_Rect_getMidX);
    oluacls_func(L, "getMidY", _olua_fun_cocos2d_Rect_getMidY);
    oluacls_func(L, "getMinX", _olua_fun_cocos2d_Rect_getMinX);
    oluacls_func(L, "getMinY", _olua_fun_cocos2d_Rect_getMinY);
    oluacls_func(L, "intersectsCircle", _olua_fun_cocos2d_Rect_intersectsCircle);
    oluacls_func(L, "intersectsRect", _olua_fun_cocos2d_Rect_intersectsRect);
    oluacls_func(L, "merge", _olua_fun_cocos2d_Rect_merge);
    oluacls_func(L, "new", _olua_fun_cocos2d_Rect_new);
    oluacls_func(L, "setRect", _olua_fun_cocos2d_Rect_setRect);
    oluacls_func(L, "unionWithRect", _olua_fun_cocos2d_Rect_unionWithRect);
    oluacls_prop(L, "maxX", _olua_fun_cocos2d_Rect_getMaxX, nullptr);
    oluacls_prop(L, "maxY", _olua_fun_cocos2d_Rect_getMaxY, nullptr);
    oluacls_prop(L, "midX", _olua_fun_cocos2d_Rect_getMidX, nullptr);
    oluacls_prop(L, "midY", _olua_fun_cocos2d_Rect_getMidY, nullptr);
    oluacls_prop(L, "minX", _olua_fun_cocos2d_Rect_getMinX, nullptr);
    oluacls_prop(L, "minY", _olua_fun_cocos2d_Rect_getMinY, nullptr);
    oluacls_prop(L, "origin", _olua_fun_cocos2d_Rect_origin, _olua_fun_cocos2d_Rect_origin);
    oluacls_prop(L, "size", _olua_fun_cocos2d_Rect_size, _olua_fun_cocos2d_Rect_size);
    oluacls_const(L, "ZERO", &cocos2d::Rect::ZERO);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cc_Rect(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "cc.Rect")) {
        luaL_error(L, "class not found: cocos2d::Rect");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_Bounds___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Bounds *)olua_toobj(L, 1, "cc.Bounds");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Bounds_bottom$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Bounds *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Bounds");

    // float bottom
    float ret = self->bottom;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Bounds_bottom$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Bounds *self = nullptr;
    float arg1 = 0;       /** bottom */

    olua_to_object(L, 1, &self, "cc.Bounds");
    olua_check_number(L, 2, &arg1);

    // float bottom
    self->bottom = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Bounds_bottom(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float bottom
        return _olua_fun_cocos2d_Bounds_bottom$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Bounds")) && (olua_is_number(L, 2))) {
            // float bottom
            return _olua_fun_cocos2d_Bounds_bottom$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Bounds::bottom' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Bounds_left$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Bounds *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Bounds");

    // float left
    float ret = self->left;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Bounds_left$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Bounds *self = nullptr;
    float arg1 = 0;       /** left */

    olua_to_object(L, 1, &self, "cc.Bounds");
    olua_check_number(L, 2, &arg1);

    // float left
    self->left = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Bounds_left(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float left
        return _olua_fun_cocos2d_Bounds_left$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Bounds")) && (olua_is_number(L, 2))) {
            // float left
            return _olua_fun_cocos2d_Bounds_left$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Bounds::left' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Bounds_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::Bounds()
    cocos2d::Bounds *ret = new cocos2d::Bounds();
    int num_ret = olua_push_object(L, ret, "cc.Bounds");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Bounds_right$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Bounds *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Bounds");

    // float right
    float ret = self->right;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Bounds_right$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Bounds *self = nullptr;
    float arg1 = 0;       /** right */

    olua_to_object(L, 1, &self, "cc.Bounds");
    olua_check_number(L, 2, &arg1);

    // float right
    self->right = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Bounds_right(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float right
        return _olua_fun_cocos2d_Bounds_right$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Bounds")) && (olua_is_number(L, 2))) {
            // float right
            return _olua_fun_cocos2d_Bounds_right$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Bounds::right' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Bounds_top$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Bounds *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Bounds");

    // float top
    float ret = self->top;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Bounds_top$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Bounds *self = nullptr;
    float arg1 = 0;       /** top */

    olua_to_object(L, 1, &self, "cc.Bounds");
    olua_check_number(L, 2, &arg1);

    // float top
    self->top = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Bounds_top(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float top
        return _olua_fun_cocos2d_Bounds_top$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Bounds")) && (olua_is_number(L, 2))) {
            // float top
            return _olua_fun_cocos2d_Bounds_top$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Bounds::top' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_cc_Bounds(lua_State *L)
{
    oluacls_class<cocos2d::Bounds>(L, "cc.Bounds");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_Bounds___gc);
    oluacls_func(L, "new", _olua_fun_cocos2d_Bounds_new);
    oluacls_prop(L, "left", _olua_fun_cocos2d_Bounds_left, _olua_fun_cocos2d_Bounds_left);
    oluacls_prop(L, "right", _olua_fun_cocos2d_Bounds_right, _olua_fun_cocos2d_Bounds_right);
    oluacls_prop(L, "top", _olua_fun_cocos2d_Bounds_top, _olua_fun_cocos2d_Bounds_top);
    oluacls_prop(L, "bottom", _olua_fun_cocos2d_Bounds_bottom, _olua_fun_cocos2d_Bounds_bottom);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cc_Bounds(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "cc.Bounds")) {
        luaL_error(L, "class not found: cocos2d::Bounds");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_Mat4___add$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Mat4 *arg1;       /** mat */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Mat4");

    // @operator(operator+) cocos2d::Mat4 operator+(const cocos2d::Mat4 &mat)
    cocos2d::Mat4 ret = (*self) + (*arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Mat4");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Mat4___add$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *arg1 = nullptr;       /** mat1 */
    cocos2d::Mat4 *arg2 = nullptr;       /** mat2 */

    olua_check_object(L, 1, &arg1, "cc.Mat4");
    olua_check_object(L, 2, &arg2, "cc.Mat4");

    // @postnew @extend(cocos2d::Mat4Extend) static cocos2d::Mat4 *__add(cocos2d::Mat4 *mat1, cocos2d::Mat4 *mat2)
    cocos2d::Mat4 *ret = cocos2d::Mat4Extend::__add(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.Mat4");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Mat4___add(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Mat4"))) {
            // @operator(operator+) cocos2d::Mat4 operator+(const cocos2d::Mat4 &mat)
            return _olua_fun_cocos2d_Mat4___add$1(L);
        }

        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Mat4"))) {
            // @postnew @extend(cocos2d::Mat4Extend) static cocos2d::Mat4 *__add(cocos2d::Mat4 *mat1, cocos2d::Mat4 *mat2)
            return _olua_fun_cocos2d_Mat4___add$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Mat4::__add' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Mat4___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Mat4 *)olua_toobj(L, 1, "cc.Mat4");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4___mul$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Mat4 *arg1;       /** mat */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Mat4");

    // @operator(operator*) cocos2d::Mat4 operator*(const cocos2d::Mat4 &mat)
    cocos2d::Mat4 ret = (*self) * (*arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Mat4");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Mat4___mul$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *arg1;       /** m */
    cocos2d::Vec3 *arg2;       /** v */

    olua_check_object(L, 1, &arg1, "cc.Mat4");
    olua_check_object(L, 2, &arg2, "cc.Vec3");

    // @operator(operator*) static cocos2d::Vec3 operator*(const cocos2d::Mat4 &m, const cocos2d::Vec3 &v)
    cocos2d::Vec3 ret = (*arg1) * (*arg2);
    int num_ret = olua_copy_object(L, ret, "cc.Vec3");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Mat4___mul$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *arg1;       /** m */
    cocos2d::Vec4 *arg2;       /** v */

    olua_check_object(L, 1, &arg1, "cc.Mat4");
    olua_check_object(L, 2, &arg2, "cc.Vec4");

    // @operator(operator*) static cocos2d::Vec4 operator*(const cocos2d::Mat4 &m, const cocos2d::Vec4 &v)
    cocos2d::Vec4 ret = (*arg1) * (*arg2);
    int num_ret = olua_copy_object(L, ret, "cc.Vec4");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Mat4___mul$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *arg1 = nullptr;       /** mat1 */
    cocos2d::Mat4 *arg2 = nullptr;       /** mat2 */

    olua_check_object(L, 1, &arg1, "cc.Mat4");
    olua_check_object(L, 2, &arg2, "cc.Mat4");

    // @postnew @extend(cocos2d::Mat4Extend) static cocos2d::Mat4 *__mul(cocos2d::Mat4 *mat1, cocos2d::Mat4 *mat2)
    cocos2d::Mat4 *ret = cocos2d::Mat4Extend::__mul(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.Mat4");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Mat4___mul(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Vec4"))) {
            // @operator(operator*) static cocos2d::Vec4 operator*(const cocos2d::Mat4 &m, const cocos2d::Vec4 &v)
            return _olua_fun_cocos2d_Mat4___mul$3(L);
        }

        if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Vec3"))) {
            // @operator(operator*) static cocos2d::Vec3 operator*(const cocos2d::Mat4 &m, const cocos2d::Vec3 &v)
            return _olua_fun_cocos2d_Mat4___mul$2(L);
        }

        if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Mat4"))) {
            // @operator(operator*) cocos2d::Mat4 operator*(const cocos2d::Mat4 &mat)
            return _olua_fun_cocos2d_Mat4___mul$1(L);
        }

        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Mat4"))) {
            // @postnew @extend(cocos2d::Mat4Extend) static cocos2d::Mat4 *__mul(cocos2d::Mat4 *mat1, cocos2d::Mat4 *mat2)
            return _olua_fun_cocos2d_Mat4___mul$4(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Mat4::__mul' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Mat4___sub$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Mat4 *arg1;       /** mat */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Mat4");

    // @operator(operator-) cocos2d::Mat4 operator-(const cocos2d::Mat4 &mat)
    cocos2d::Mat4 ret = (*self) - (*arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Mat4");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Mat4___sub$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *arg1 = nullptr;       /** mat1 */
    cocos2d::Mat4 *arg2 = nullptr;       /** mat2 */

    olua_check_object(L, 1, &arg1, "cc.Mat4");
    olua_check_object(L, 2, &arg2, "cc.Mat4");

    // @postnew @extend(cocos2d::Mat4Extend) static cocos2d::Mat4 *__sub(cocos2d::Mat4 *mat1, cocos2d::Mat4 *mat2)
    cocos2d::Mat4 *ret = cocos2d::Mat4Extend::__sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.Mat4");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Mat4___sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Mat4"))) {
            // @operator(operator-) cocos2d::Mat4 operator-(const cocos2d::Mat4 &mat)
            return _olua_fun_cocos2d_Mat4___sub$1(L);
        }

        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Mat4"))) {
            // @postnew @extend(cocos2d::Mat4Extend) static cocos2d::Mat4 *__sub(cocos2d::Mat4 *mat1, cocos2d::Mat4 *mat2)
            return _olua_fun_cocos2d_Mat4___sub$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Mat4::__sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Mat4___unm(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Mat4");

    // @operator(operator-) cocos2d::Mat4 operator-()
    cocos2d::Mat4 ret = -(*self);
    int num_ret = olua_copy_object(L, ret, "cc.Mat4");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Mat4_add$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    float arg1 = 0;       /** scalar */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_number(L, 2, &arg1);

    // void add(float scalar)
    self->add(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_add$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    float arg1 = 0;       /** scalar */
    cocos2d::Mat4 *arg2 = nullptr;       /** dst */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_number(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "cc.Mat4");

    // void add(float scalar, cocos2d::Mat4 *dst)
    self->add(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_add$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Mat4 *arg1;       /** mat */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Mat4");

    // void add(const cocos2d::Mat4 &mat)
    self->add(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_add$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *arg1;       /** m1 */
    cocos2d::Mat4 *arg2;       /** m2 */
    cocos2d::Mat4 *arg3 = nullptr;       /** dst */

    olua_check_object(L, 1, &arg1, "cc.Mat4");
    olua_check_object(L, 2, &arg2, "cc.Mat4");
    olua_check_object(L, 3, &arg3, "cc.Mat4");

    // static void add(const cocos2d::Mat4 &m1, const cocos2d::Mat4 &m2, cocos2d::Mat4 *dst)
    cocos2d::Mat4::add(*arg1, *arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_add(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_number(L, 2))) {
            // void add(float scalar)
            return _olua_fun_cocos2d_Mat4_add$1(L);
        }

        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Mat4"))) {
            // void add(const cocos2d::Mat4 &mat)
            return _olua_fun_cocos2d_Mat4_add$3(L);
        // }
    }

    if (num_args == 3) {
        if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_number(L, 2)) && (olua_is_object(L, 3, "cc.Mat4"))) {
            // void add(float scalar, cocos2d::Mat4 *dst)
            return _olua_fun_cocos2d_Mat4_add$2(L);
        }

        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Mat4")) && (olua_is_object(L, 3, "cc.Mat4"))) {
            // static void add(const cocos2d::Mat4 &m1, const cocos2d::Mat4 &m2, cocos2d::Mat4 *dst)
            return _olua_fun_cocos2d_Mat4_add$4(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Mat4::add' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_createBillboard$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *arg1;       /** objectPosition */
    cocos2d::Vec3 *arg2;       /** cameraPosition */
    cocos2d::Vec3 *arg3;       /** cameraUpVector */
    cocos2d::Mat4 *arg4 = nullptr;       /** dst */

    olua_check_object(L, 1, &arg1, "cc.Vec3");
    olua_check_object(L, 2, &arg2, "cc.Vec3");
    olua_check_object(L, 3, &arg3, "cc.Vec3");
    olua_check_object(L, 4, &arg4, "cc.Mat4");

    // static void createBillboard(const cocos2d::Vec3 &objectPosition, const cocos2d::Vec3 &cameraPosition, const cocos2d::Vec3 &cameraUpVector, cocos2d::Mat4 *dst)
    cocos2d::Mat4::createBillboard(*arg1, *arg2, *arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_createBillboard$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *arg1;       /** objectPosition */
    cocos2d::Vec3 *arg2;       /** cameraPosition */
    cocos2d::Vec3 *arg3;       /** cameraUpVector */
    cocos2d::Vec3 *arg4;       /** cameraForwardVector */
    cocos2d::Mat4 *arg5 = nullptr;       /** dst */

    olua_check_object(L, 1, &arg1, "cc.Vec3");
    olua_check_object(L, 2, &arg2, "cc.Vec3");
    olua_check_object(L, 3, &arg3, "cc.Vec3");
    olua_check_object(L, 4, &arg4, "cc.Vec3");
    olua_check_object(L, 5, &arg5, "cc.Mat4");

    // static void createBillboard(const cocos2d::Vec3 &objectPosition, const cocos2d::Vec3 &cameraPosition, const cocos2d::Vec3 &cameraUpVector, const cocos2d::Vec3 &cameraForwardVector, cocos2d::Mat4 *dst)
    cocos2d::Mat4::createBillboard(*arg1, *arg2, *arg3, *arg4, arg5);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_createBillboard(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.Vec3")) && (olua_is_object(L, 2, "cc.Vec3")) && (olua_is_object(L, 3, "cc.Vec3")) && (olua_is_object(L, 4, "cc.Mat4"))) {
            // static void createBillboard(const cocos2d::Vec3 &objectPosition, const cocos2d::Vec3 &cameraPosition, const cocos2d::Vec3 &cameraUpVector, cocos2d::Mat4 *dst)
            return _olua_fun_cocos2d_Mat4_createBillboard$1(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "cc.Vec3")) && (olua_is_object(L, 2, "cc.Vec3")) && (olua_is_object(L, 3, "cc.Vec3")) && (olua_is_object(L, 4, "cc.Vec3")) && (olua_is_object(L, 5, "cc.Mat4"))) {
            // static void createBillboard(const cocos2d::Vec3 &objectPosition, const cocos2d::Vec3 &cameraPosition, const cocos2d::Vec3 &cameraUpVector, const cocos2d::Vec3 &cameraForwardVector, cocos2d::Mat4 *dst)
            return _olua_fun_cocos2d_Mat4_createBillboard$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Mat4::createBillboard' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_createLookAt$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *arg1;       /** eyePosition */
    cocos2d::Vec3 *arg2;       /** targetPosition */
    cocos2d::Vec3 *arg3;       /** up */
    cocos2d::Mat4 *arg4 = nullptr;       /** dst */

    olua_check_object(L, 1, &arg1, "cc.Vec3");
    olua_check_object(L, 2, &arg2, "cc.Vec3");
    olua_check_object(L, 3, &arg3, "cc.Vec3");
    olua_check_object(L, 4, &arg4, "cc.Mat4");

    // static void createLookAt(const cocos2d::Vec3 &eyePosition, const cocos2d::Vec3 &targetPosition, const cocos2d::Vec3 &up, cocos2d::Mat4 *dst)
    cocos2d::Mat4::createLookAt(*arg1, *arg2, *arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_createLookAt$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** eyePositionX */
    float arg2 = 0;       /** eyePositionY */
    float arg3 = 0;       /** eyePositionZ */
    float arg4 = 0;       /** targetCenterX */
    float arg5 = 0;       /** targetCenterY */
    float arg6 = 0;       /** targetCenterZ */
    float arg7 = 0;       /** upX */
    float arg8 = 0;       /** upY */
    float arg9 = 0;       /** upZ */
    cocos2d::Mat4 *arg10 = nullptr;       /** dst */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);
    olua_check_number(L, 5, &arg5);
    olua_check_number(L, 6, &arg6);
    olua_check_number(L, 7, &arg7);
    olua_check_number(L, 8, &arg8);
    olua_check_number(L, 9, &arg9);
    olua_check_object(L, 10, &arg10, "cc.Mat4");

    // static void createLookAt(float eyePositionX, float eyePositionY, float eyePositionZ, float targetCenterX, float targetCenterY, float targetCenterZ, float upX, float upY, float upZ, cocos2d::Mat4 *dst)
    cocos2d::Mat4::createLookAt(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_createLookAt(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.Vec3")) && (olua_is_object(L, 2, "cc.Vec3")) && (olua_is_object(L, 3, "cc.Vec3")) && (olua_is_object(L, 4, "cc.Mat4"))) {
            // static void createLookAt(const cocos2d::Vec3 &eyePosition, const cocos2d::Vec3 &targetPosition, const cocos2d::Vec3 &up, cocos2d::Mat4 *dst)
            return _olua_fun_cocos2d_Mat4_createLookAt$1(L);
        // }
    }

    if (num_args == 10) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5)) && (olua_is_number(L, 6)) && (olua_is_number(L, 7)) && (olua_is_number(L, 8)) && (olua_is_number(L, 9)) && (olua_is_object(L, 10, "cc.Mat4"))) {
            // static void createLookAt(float eyePositionX, float eyePositionY, float eyePositionZ, float targetCenterX, float targetCenterY, float targetCenterZ, float upX, float upY, float upZ, cocos2d::Mat4 *dst)
            return _olua_fun_cocos2d_Mat4_createLookAt$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Mat4::createLookAt' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_createOrthographic(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** width */
    float arg2 = 0;       /** height */
    float arg3 = 0;       /** zNearPlane */
    float arg4 = 0;       /** zFarPlane */
    cocos2d::Mat4 *arg5 = nullptr;       /** dst */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);
    olua_check_object(L, 5, &arg5, "cc.Mat4");

    // static void createOrthographic(float width, float height, float zNearPlane, float zFarPlane, cocos2d::Mat4 *dst)
    cocos2d::Mat4::createOrthographic(arg1, arg2, arg3, arg4, arg5);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_createOrthographicOffCenter(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** left */
    float arg2 = 0;       /** right */
    float arg3 = 0;       /** bottom */
    float arg4 = 0;       /** top */
    float arg5 = 0;       /** zNearPlane */
    float arg6 = 0;       /** zFarPlane */
    cocos2d::Mat4 *arg7 = nullptr;       /** dst */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);
    olua_check_number(L, 5, &arg5);
    olua_check_number(L, 6, &arg6);
    olua_check_object(L, 7, &arg7, "cc.Mat4");

    // static void createOrthographicOffCenter(float left, float right, float bottom, float top, float zNearPlane, float zFarPlane, cocos2d::Mat4 *dst)
    cocos2d::Mat4::createOrthographicOffCenter(arg1, arg2, arg3, arg4, arg5, arg6, arg7);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_createPerspective(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** fieldOfView */
    float arg2 = 0;       /** aspectRatio */
    float arg3 = 0;       /** zNearPlane */
    float arg4 = 0;       /** zFarPlane */
    cocos2d::Mat4 *arg5 = nullptr;       /** dst */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);
    olua_check_object(L, 5, &arg5, "cc.Mat4");

    // static void createPerspective(float fieldOfView, float aspectRatio, float zNearPlane, float zFarPlane, cocos2d::Mat4 *dst)
    cocos2d::Mat4::createPerspective(arg1, arg2, arg3, arg4, arg5);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_createRotation$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *arg1;       /** quat */
    cocos2d::Mat4 *arg2 = nullptr;       /** dst */

    olua_check_object(L, 1, &arg1, "cc.Quaternion");
    olua_check_object(L, 2, &arg2, "cc.Mat4");

    // static void createRotation(const cocos2d::Quaternion &quat, cocos2d::Mat4 *dst)
    cocos2d::Mat4::createRotation(*arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_createRotation$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *arg1;       /** axis */
    float arg2 = 0;       /** angle */
    cocos2d::Mat4 *arg3 = nullptr;       /** dst */

    olua_check_object(L, 1, &arg1, "cc.Vec3");
    olua_check_number(L, 2, &arg2);
    olua_check_object(L, 3, &arg3, "cc.Mat4");

    // static void createRotation(const cocos2d::Vec3 &axis, float angle, cocos2d::Mat4 *dst)
    cocos2d::Mat4::createRotation(*arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_createRotation(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Quaternion")) && (olua_is_object(L, 2, "cc.Mat4"))) {
            // static void createRotation(const cocos2d::Quaternion &quat, cocos2d::Mat4 *dst)
            return _olua_fun_cocos2d_Mat4_createRotation$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Vec3")) && (olua_is_number(L, 2)) && (olua_is_object(L, 3, "cc.Mat4"))) {
            // static void createRotation(const cocos2d::Vec3 &axis, float angle, cocos2d::Mat4 *dst)
            return _olua_fun_cocos2d_Mat4_createRotation$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Mat4::createRotation' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_createRotationX(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** angle */
    cocos2d::Mat4 *arg2 = nullptr;       /** dst */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Mat4");

    // static void createRotationX(float angle, cocos2d::Mat4 *dst)
    cocos2d::Mat4::createRotationX(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_createRotationY(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** angle */
    cocos2d::Mat4 *arg2 = nullptr;       /** dst */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Mat4");

    // static void createRotationY(float angle, cocos2d::Mat4 *dst)
    cocos2d::Mat4::createRotationY(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_createRotationZ(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** angle */
    cocos2d::Mat4 *arg2 = nullptr;       /** dst */

    olua_check_number(L, 1, &arg1);
    olua_check_object(L, 2, &arg2, "cc.Mat4");

    // static void createRotationZ(float angle, cocos2d::Mat4 *dst)
    cocos2d::Mat4::createRotationZ(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_createScale$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *arg1;       /** scale */
    cocos2d::Mat4 *arg2 = nullptr;       /** dst */

    olua_check_object(L, 1, &arg1, "cc.Vec3");
    olua_check_object(L, 2, &arg2, "cc.Mat4");

    // static void createScale(const cocos2d::Vec3 &scale, cocos2d::Mat4 *dst)
    cocos2d::Mat4::createScale(*arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_createScale$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** xScale */
    float arg2 = 0;       /** yScale */
    float arg3 = 0;       /** zScale */
    cocos2d::Mat4 *arg4 = nullptr;       /** dst */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_object(L, 4, &arg4, "cc.Mat4");

    // static void createScale(float xScale, float yScale, float zScale, cocos2d::Mat4 *dst)
    cocos2d::Mat4::createScale(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_createScale(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec3")) && (olua_is_object(L, 2, "cc.Mat4"))) {
            // static void createScale(const cocos2d::Vec3 &scale, cocos2d::Mat4 *dst)
            return _olua_fun_cocos2d_Mat4_createScale$1(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_object(L, 4, "cc.Mat4"))) {
            // static void createScale(float xScale, float yScale, float zScale, cocos2d::Mat4 *dst)
            return _olua_fun_cocos2d_Mat4_createScale$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Mat4::createScale' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_createTranslation$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *arg1;       /** translation */
    cocos2d::Mat4 *arg2 = nullptr;       /** dst */

    olua_check_object(L, 1, &arg1, "cc.Vec3");
    olua_check_object(L, 2, &arg2, "cc.Mat4");

    // static void createTranslation(const cocos2d::Vec3 &translation, cocos2d::Mat4 *dst)
    cocos2d::Mat4::createTranslation(*arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_createTranslation$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** xTranslation */
    float arg2 = 0;       /** yTranslation */
    float arg3 = 0;       /** zTranslation */
    cocos2d::Mat4 *arg4 = nullptr;       /** dst */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_object(L, 4, &arg4, "cc.Mat4");

    // static void createTranslation(float xTranslation, float yTranslation, float zTranslation, cocos2d::Mat4 *dst)
    cocos2d::Mat4::createTranslation(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_createTranslation(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec3")) && (olua_is_object(L, 2, "cc.Mat4"))) {
            // static void createTranslation(const cocos2d::Vec3 &translation, cocos2d::Mat4 *dst)
            return _olua_fun_cocos2d_Mat4_createTranslation$1(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_object(L, 4, "cc.Mat4"))) {
            // static void createTranslation(float xTranslation, float yTranslation, float zTranslation, cocos2d::Mat4 *dst)
            return _olua_fun_cocos2d_Mat4_createTranslation$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Mat4::createTranslation' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_decompose(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Vec3 *arg1 = nullptr;       /** scale */
    cocos2d::Quaternion *arg2 = nullptr;       /** rotation */
    cocos2d::Vec3 *arg3 = nullptr;       /** translation */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Vec3");
    olua_check_object(L, 3, &arg2, "cc.Quaternion");
    olua_check_object(L, 4, &arg3, "cc.Vec3");

    // bool decompose(cocos2d::Vec3 *scale, cocos2d::Quaternion *rotation, cocos2d::Vec3 *translation)
    bool ret = self->decompose(arg1, arg2, arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Mat4_determinant(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Mat4");

    // float determinant()
    float ret = self->determinant();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Mat4_getBackVector(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Vec3 *arg1 = nullptr;       /** dst */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // void getBackVector(cocos2d::Vec3 *dst)
    self->getBackVector(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_getDownVector(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Vec3 *arg1 = nullptr;       /** dst */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // void getDownVector(cocos2d::Vec3 *dst)
    self->getDownVector(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_getForwardVector(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Vec3 *arg1 = nullptr;       /** dst */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // void getForwardVector(cocos2d::Vec3 *dst)
    self->getForwardVector(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_getInversed(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Mat4");

    // cocos2d::Mat4 getInversed()
    cocos2d::Mat4 ret = self->getInversed();
    int num_ret = olua_copy_object(L, ret, "cc.Mat4");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Mat4_getLeftVector(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Vec3 *arg1 = nullptr;       /** dst */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // void getLeftVector(cocos2d::Vec3 *dst)
    self->getLeftVector(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_getNegated(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Mat4");

    // cocos2d::Mat4 getNegated()
    cocos2d::Mat4 ret = self->getNegated();
    int num_ret = olua_copy_object(L, ret, "cc.Mat4");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Mat4_getRightVector(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Vec3 *arg1 = nullptr;       /** dst */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // void getRightVector(cocos2d::Vec3 *dst)
    self->getRightVector(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_getRotation(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Quaternion *arg1 = nullptr;       /** rotation */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Quaternion");

    // bool getRotation(cocos2d::Quaternion *rotation)
    bool ret = self->getRotation(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Mat4_getScale(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Vec3 *arg1 = nullptr;       /** scale */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // void getScale(cocos2d::Vec3 *scale)
    self->getScale(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_getTranslation(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Vec3 *arg1 = nullptr;       /** translation */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // void getTranslation(cocos2d::Vec3 *translation)
    self->getTranslation(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_getTransposed(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Mat4");

    // cocos2d::Mat4 getTransposed()
    cocos2d::Mat4 ret = self->getTransposed();
    int num_ret = olua_copy_object(L, ret, "cc.Mat4");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Mat4_getUpVector(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Vec3 *arg1 = nullptr;       /** dst */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // void getUpVector(cocos2d::Vec3 *dst)
    self->getUpVector(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_inverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Mat4");

    // bool inverse()
    bool ret = self->inverse();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Mat4_isIdentity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Mat4");

    // bool isIdentity()
    bool ret = self->isIdentity();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Mat4_multiply$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    float arg1 = 0;       /** scalar */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_number(L, 2, &arg1);

    // void multiply(float scalar)
    self->multiply(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_multiply$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    float arg1 = 0;       /** scalar */
    cocos2d::Mat4 *arg2 = nullptr;       /** dst */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_number(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "cc.Mat4");

    // void multiply(float scalar, cocos2d::Mat4 *dst)
    self->multiply(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_multiply$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *arg1;       /** mat */
    float arg2 = 0;       /** scalar */
    cocos2d::Mat4 *arg3 = nullptr;       /** dst */

    olua_check_object(L, 1, &arg1, "cc.Mat4");
    olua_check_number(L, 2, &arg2);
    olua_check_object(L, 3, &arg3, "cc.Mat4");

    // static void multiply(const cocos2d::Mat4 &mat, float scalar, cocos2d::Mat4 *dst)
    cocos2d::Mat4::multiply(*arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_multiply$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Mat4 *arg1;       /** mat */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Mat4");

    // void multiply(const cocos2d::Mat4 &mat)
    self->multiply(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_multiply$5(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *arg1;       /** m1 */
    cocos2d::Mat4 *arg2;       /** m2 */
    cocos2d::Mat4 *arg3 = nullptr;       /** dst */

    olua_check_object(L, 1, &arg1, "cc.Mat4");
    olua_check_object(L, 2, &arg2, "cc.Mat4");
    olua_check_object(L, 3, &arg3, "cc.Mat4");

    // static void multiply(const cocos2d::Mat4 &m1, const cocos2d::Mat4 &m2, cocos2d::Mat4 *dst)
    cocos2d::Mat4::multiply(*arg1, *arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_multiply(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_number(L, 2))) {
            // void multiply(float scalar)
            return _olua_fun_cocos2d_Mat4_multiply$1(L);
        }

        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Mat4"))) {
            // void multiply(const cocos2d::Mat4 &mat)
            return _olua_fun_cocos2d_Mat4_multiply$4(L);
        // }
    }

    if (num_args == 3) {
        if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_number(L, 2)) && (olua_is_object(L, 3, "cc.Mat4"))) {
            // void multiply(float scalar, cocos2d::Mat4 *dst)
            return _olua_fun_cocos2d_Mat4_multiply$2(L);
        }

        if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_number(L, 2)) && (olua_is_object(L, 3, "cc.Mat4"))) {
            // static void multiply(const cocos2d::Mat4 &mat, float scalar, cocos2d::Mat4 *dst)
            return _olua_fun_cocos2d_Mat4_multiply$3(L);
        }

        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Mat4")) && (olua_is_object(L, 3, "cc.Mat4"))) {
            // static void multiply(const cocos2d::Mat4 &m1, const cocos2d::Mat4 &m2, cocos2d::Mat4 *dst)
            return _olua_fun_cocos2d_Mat4_multiply$5(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Mat4::multiply' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_negate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Mat4");

    // void negate()
    self->negate();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_new$1(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::Mat4()
    cocos2d::Mat4 *ret = new cocos2d::Mat4();
    int num_ret = olua_push_object(L, ret, "cc.Mat4");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Mat4_new$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** m11 */
    float arg2 = 0;       /** m12 */
    float arg3 = 0;       /** m13 */
    float arg4 = 0;       /** m14 */
    float arg5 = 0;       /** m21 */
    float arg6 = 0;       /** m22 */
    float arg7 = 0;       /** m23 */
    float arg8 = 0;       /** m24 */
    float arg9 = 0;       /** m31 */
    float arg10 = 0;       /** m32 */
    float arg11 = 0;       /** m33 */
    float arg12 = 0;       /** m34 */
    float arg13 = 0;       /** m41 */
    float arg14 = 0;       /** m42 */
    float arg15 = 0;       /** m43 */
    float arg16 = 0;       /** m44 */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);
    olua_check_number(L, 5, &arg5);
    olua_check_number(L, 6, &arg6);
    olua_check_number(L, 7, &arg7);
    olua_check_number(L, 8, &arg8);
    olua_check_number(L, 9, &arg9);
    olua_check_number(L, 10, &arg10);
    olua_check_number(L, 11, &arg11);
    olua_check_number(L, 12, &arg12);
    olua_check_number(L, 13, &arg13);
    olua_check_number(L, 14, &arg14);
    olua_check_number(L, 15, &arg15);
    olua_check_number(L, 16, &arg16);

    // cocos2d::Mat4(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44)
    cocos2d::Mat4 *ret = new cocos2d::Mat4(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16);
    int num_ret = olua_push_object(L, ret, "cc.Mat4");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Mat4_new$3(lua_State *L)
{
    olua_startinvoke(L);

    float *arg1 = nullptr;       /** mat */

    olua_check_pointer(L, 1, &arg1, "olua.float");

    // cocos2d::Mat4(const float *mat)
    cocos2d::Mat4 *ret = new cocos2d::Mat4(arg1);
    int num_ret = olua_push_object(L, ret, "cc.Mat4");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Mat4_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // cocos2d::Mat4()
        return _olua_fun_cocos2d_Mat4_new$1(L);
    }

    if (num_args == 1) {
        // if ((olua_is_pointer(L, 1, "olua.float"))) {
            // cocos2d::Mat4(const float *mat)
            return _olua_fun_cocos2d_Mat4_new$3(L);
        // }
    }

    if (num_args == 16) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5)) && (olua_is_number(L, 6)) && (olua_is_number(L, 7)) && (olua_is_number(L, 8)) && (olua_is_number(L, 9)) && (olua_is_number(L, 10)) && (olua_is_number(L, 11)) && (olua_is_number(L, 12)) && (olua_is_number(L, 13)) && (olua_is_number(L, 14)) && (olua_is_number(L, 15)) && (olua_is_number(L, 16))) {
            // cocos2d::Mat4(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44)
            return _olua_fun_cocos2d_Mat4_new$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Mat4::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_rotate$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Quaternion *arg1;       /** q */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Quaternion");

    // void rotate(const cocos2d::Quaternion &q)
    self->rotate(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_rotate$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Quaternion *arg1;       /** q */
    cocos2d::Mat4 *arg2 = nullptr;       /** dst */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Quaternion");
    olua_check_object(L, 3, &arg2, "cc.Mat4");

    // void rotate(const cocos2d::Quaternion &q, cocos2d::Mat4 *dst)
    self->rotate(*arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_rotate$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Vec3 *arg1;       /** axis */
    float arg2 = 0;       /** angle */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Vec3");
    olua_check_number(L, 3, &arg2);

    // void rotate(const cocos2d::Vec3 &axis, float angle)
    self->rotate(*arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_rotate$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Vec3 *arg1;       /** axis */
    float arg2 = 0;       /** angle */
    cocos2d::Mat4 *arg3 = nullptr;       /** dst */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Vec3");
    olua_check_number(L, 3, &arg2);
    olua_check_object(L, 4, &arg3, "cc.Mat4");

    // void rotate(const cocos2d::Vec3 &axis, float angle, cocos2d::Mat4 *dst)
    self->rotate(*arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_rotate(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Quaternion"))) {
            // void rotate(const cocos2d::Quaternion &q)
            return _olua_fun_cocos2d_Mat4_rotate$1(L);
        // }
    }

    if (num_args == 3) {
        if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Vec3")) && (olua_is_number(L, 3))) {
            // void rotate(const cocos2d::Vec3 &axis, float angle)
            return _olua_fun_cocos2d_Mat4_rotate$3(L);
        }

        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Quaternion")) && (olua_is_object(L, 3, "cc.Mat4"))) {
            // void rotate(const cocos2d::Quaternion &q, cocos2d::Mat4 *dst)
            return _olua_fun_cocos2d_Mat4_rotate$2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Vec3")) && (olua_is_number(L, 3)) && (olua_is_object(L, 4, "cc.Mat4"))) {
            // void rotate(const cocos2d::Vec3 &axis, float angle, cocos2d::Mat4 *dst)
            return _olua_fun_cocos2d_Mat4_rotate$4(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Mat4::rotate' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_rotateX$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    float arg1 = 0;       /** angle */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_number(L, 2, &arg1);

    // void rotateX(float angle)
    self->rotateX(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_rotateX$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    float arg1 = 0;       /** angle */
    cocos2d::Mat4 *arg2 = nullptr;       /** dst */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_number(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "cc.Mat4");

    // void rotateX(float angle, cocos2d::Mat4 *dst)
    self->rotateX(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_rotateX(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_number(L, 2))) {
            // void rotateX(float angle)
            return _olua_fun_cocos2d_Mat4_rotateX$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_number(L, 2)) && (olua_is_object(L, 3, "cc.Mat4"))) {
            // void rotateX(float angle, cocos2d::Mat4 *dst)
            return _olua_fun_cocos2d_Mat4_rotateX$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Mat4::rotateX' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_rotateY$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    float arg1 = 0;       /** angle */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_number(L, 2, &arg1);

    // void rotateY(float angle)
    self->rotateY(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_rotateY$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    float arg1 = 0;       /** angle */
    cocos2d::Mat4 *arg2 = nullptr;       /** dst */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_number(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "cc.Mat4");

    // void rotateY(float angle, cocos2d::Mat4 *dst)
    self->rotateY(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_rotateY(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_number(L, 2))) {
            // void rotateY(float angle)
            return _olua_fun_cocos2d_Mat4_rotateY$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_number(L, 2)) && (olua_is_object(L, 3, "cc.Mat4"))) {
            // void rotateY(float angle, cocos2d::Mat4 *dst)
            return _olua_fun_cocos2d_Mat4_rotateY$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Mat4::rotateY' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_rotateZ$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    float arg1 = 0;       /** angle */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_number(L, 2, &arg1);

    // void rotateZ(float angle)
    self->rotateZ(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_rotateZ$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    float arg1 = 0;       /** angle */
    cocos2d::Mat4 *arg2 = nullptr;       /** dst */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_number(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "cc.Mat4");

    // void rotateZ(float angle, cocos2d::Mat4 *dst)
    self->rotateZ(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_rotateZ(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_number(L, 2))) {
            // void rotateZ(float angle)
            return _olua_fun_cocos2d_Mat4_rotateZ$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_number(L, 2)) && (olua_is_object(L, 3, "cc.Mat4"))) {
            // void rotateZ(float angle, cocos2d::Mat4 *dst)
            return _olua_fun_cocos2d_Mat4_rotateZ$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Mat4::rotateZ' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_scale$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    float arg1 = 0;       /** value */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_number(L, 2, &arg1);

    // void scale(float value)
    self->scale(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_scale$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    float arg1 = 0;       /** value */
    cocos2d::Mat4 *arg2 = nullptr;       /** dst */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_number(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "cc.Mat4");

    // void scale(float value, cocos2d::Mat4 *dst)
    self->scale(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_scale$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    float arg1 = 0;       /** xScale */
    float arg2 = 0;       /** yScale */
    float arg3 = 0;       /** zScale */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // void scale(float xScale, float yScale, float zScale)
    self->scale(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_scale$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    float arg1 = 0;       /** xScale */
    float arg2 = 0;       /** yScale */
    float arg3 = 0;       /** zScale */
    cocos2d::Mat4 *arg4 = nullptr;       /** dst */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_object(L, 5, &arg4, "cc.Mat4");

    // void scale(float xScale, float yScale, float zScale, cocos2d::Mat4 *dst)
    self->scale(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_scale$5(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Vec3 *arg1;       /** s */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // void scale(const cocos2d::Vec3 &s)
    self->scale(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_scale$6(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Vec3 *arg1;       /** s */
    cocos2d::Mat4 *arg2 = nullptr;       /** dst */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Vec3");
    olua_check_object(L, 3, &arg2, "cc.Mat4");

    // void scale(const cocos2d::Vec3 &s, cocos2d::Mat4 *dst)
    self->scale(*arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_scale(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Vec3"))) {
            // void scale(const cocos2d::Vec3 &s)
            return _olua_fun_cocos2d_Mat4_scale$5(L);
        }

        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_number(L, 2))) {
            // void scale(float value)
            return _olua_fun_cocos2d_Mat4_scale$1(L);
        // }
    }

    if (num_args == 3) {
        if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Vec3")) && (olua_is_object(L, 3, "cc.Mat4"))) {
            // void scale(const cocos2d::Vec3 &s, cocos2d::Mat4 *dst)
            return _olua_fun_cocos2d_Mat4_scale$6(L);
        }

        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_number(L, 2)) && (olua_is_object(L, 3, "cc.Mat4"))) {
            // void scale(float value, cocos2d::Mat4 *dst)
            return _olua_fun_cocos2d_Mat4_scale$2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4))) {
            // void scale(float xScale, float yScale, float zScale)
            return _olua_fun_cocos2d_Mat4_scale$3(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_object(L, 5, "cc.Mat4"))) {
            // void scale(float xScale, float yScale, float zScale, cocos2d::Mat4 *dst)
            return _olua_fun_cocos2d_Mat4_scale$4(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Mat4::scale' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_set$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    float arg1 = 0;       /** m11 */
    float arg2 = 0;       /** m12 */
    float arg3 = 0;       /** m13 */
    float arg4 = 0;       /** m14 */
    float arg5 = 0;       /** m21 */
    float arg6 = 0;       /** m22 */
    float arg7 = 0;       /** m23 */
    float arg8 = 0;       /** m24 */
    float arg9 = 0;       /** m31 */
    float arg10 = 0;       /** m32 */
    float arg11 = 0;       /** m33 */
    float arg12 = 0;       /** m34 */
    float arg13 = 0;       /** m41 */
    float arg14 = 0;       /** m42 */
    float arg15 = 0;       /** m43 */
    float arg16 = 0;       /** m44 */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);
    olua_check_number(L, 6, &arg5);
    olua_check_number(L, 7, &arg6);
    olua_check_number(L, 8, &arg7);
    olua_check_number(L, 9, &arg8);
    olua_check_number(L, 10, &arg9);
    olua_check_number(L, 11, &arg10);
    olua_check_number(L, 12, &arg11);
    olua_check_number(L, 13, &arg12);
    olua_check_number(L, 14, &arg13);
    olua_check_number(L, 15, &arg14);
    olua_check_number(L, 16, &arg15);
    olua_check_number(L, 17, &arg16);

    // void set(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44)
    self->set(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_set$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    float *arg1 = nullptr;       /** mat */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_pointer(L, 2, &arg1, "olua.float");

    // void set(const float *mat)
    self->set(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_set$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Mat4 *arg1;       /** mat */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Mat4");

    // void set(const cocos2d::Mat4 &mat)
    self->set(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_set(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_pointer(L, 2, "olua.float"))) {
            // void set(const float *mat)
            return _olua_fun_cocos2d_Mat4_set$2(L);
        }

        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Mat4"))) {
            // void set(const cocos2d::Mat4 &mat)
            return _olua_fun_cocos2d_Mat4_set$3(L);
        // }
    }

    if (num_args == 17) {
        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5)) && (olua_is_number(L, 6)) && (olua_is_number(L, 7)) && (olua_is_number(L, 8)) && (olua_is_number(L, 9)) && (olua_is_number(L, 10)) && (olua_is_number(L, 11)) && (olua_is_number(L, 12)) && (olua_is_number(L, 13)) && (olua_is_number(L, 14)) && (olua_is_number(L, 15)) && (olua_is_number(L, 16)) && (olua_is_number(L, 17))) {
            // void set(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44)
            return _olua_fun_cocos2d_Mat4_set$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Mat4::set' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_setIdentity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Mat4");

    // void setIdentity()
    self->setIdentity();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_setZero(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Mat4");

    // void setZero()
    self->setZero();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_subtract$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Mat4 *arg1;       /** mat */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Mat4");

    // void subtract(const cocos2d::Mat4 &mat)
    self->subtract(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_subtract$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *arg1;       /** m1 */
    cocos2d::Mat4 *arg2;       /** m2 */
    cocos2d::Mat4 *arg3 = nullptr;       /** dst */

    olua_check_object(L, 1, &arg1, "cc.Mat4");
    olua_check_object(L, 2, &arg2, "cc.Mat4");
    olua_check_object(L, 3, &arg3, "cc.Mat4");

    // static void subtract(const cocos2d::Mat4 &m1, const cocos2d::Mat4 &m2, cocos2d::Mat4 *dst)
    cocos2d::Mat4::subtract(*arg1, *arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_subtract(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Mat4"))) {
            // void subtract(const cocos2d::Mat4 &mat)
            return _olua_fun_cocos2d_Mat4_subtract$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Mat4")) && (olua_is_object(L, 3, "cc.Mat4"))) {
            // static void subtract(const cocos2d::Mat4 &m1, const cocos2d::Mat4 &m2, cocos2d::Mat4 *dst)
            return _olua_fun_cocos2d_Mat4_subtract$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Mat4::subtract' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_transform$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *arg1 = nullptr;       /** mat */
    cocos2d::Vec4 *arg2;       /** p */

    olua_check_object(L, 1, &arg1, "cc.Mat4");
    olua_check_object(L, 2, &arg2, "cc.Vec4");

    // @extend(cocos2d::Mat4Extend) static cocos2d::Vec4 transform(cocos2d::Mat4 *mat, const cocos2d::Vec4 &p)
    cocos2d::Vec4 ret = cocos2d::Mat4Extend::transform(arg1, *arg2);
    int num_ret = olua_copy_object(L, ret, "cc.Vec4");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Mat4_transform$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *arg1 = nullptr;       /** mat */
    cocos2d::Vec3 *arg2;       /** p */

    olua_check_object(L, 1, &arg1, "cc.Mat4");
    olua_check_object(L, 2, &arg2, "cc.Vec3");

    // @extend(cocos2d::Mat4Extend) static cocos2d::Vec3 transform(cocos2d::Mat4 *mat, const cocos2d::Vec3 &p)
    cocos2d::Vec3 ret = cocos2d::Mat4Extend::transform(arg1, *arg2);
    int num_ret = olua_copy_object(L, ret, "cc.Vec3");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Mat4_transform$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *arg1 = nullptr;       /** mat */
    cocos2d::Vec2 *arg2;       /** p */

    olua_check_object(L, 1, &arg1, "cc.Mat4");
    olua_check_object(L, 2, &arg2, "cc.Vec2");

    // @extend(cocos2d::Mat4Extend) static cocos2d::Vec2 transform(cocos2d::Mat4 *mat, const cocos2d::Vec2 &p)
    cocos2d::Vec2 ret = cocos2d::Mat4Extend::transform(arg1, *arg2);
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Mat4_transform$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *arg1 = nullptr;       /** mat */
    cocos2d::Vec4 arg2;       /** p */

    olua_check_object(L, 1, &arg1, "cc.Mat4");
    olua_pack_object(L, 2, &arg2);

    // @extend(cocos2d::Mat4Extend) @unpack static cocos2d::Vec4 transform(cocos2d::Mat4 *mat, @pack const cocos2d::Vec4 &p)
    cocos2d::Vec4 ret = cocos2d::Mat4Extend::transform(arg1, arg2);
    int num_ret = olua_unpack_object(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Mat4_transform$5(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *arg1 = nullptr;       /** mat */
    cocos2d::Vec3 arg2;       /** p */

    olua_check_object(L, 1, &arg1, "cc.Mat4");
    olua_pack_object(L, 2, &arg2);

    // @extend(cocos2d::Mat4Extend) @unpack static cocos2d::Vec3 transform(cocos2d::Mat4 *mat, @pack const cocos2d::Vec3 &p)
    cocos2d::Vec3 ret = cocos2d::Mat4Extend::transform(arg1, arg2);
    int num_ret = olua_unpack_object(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Mat4_transform$6(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *arg1 = nullptr;       /** mat */
    cocos2d::Vec2 arg2;       /** p */

    olua_check_object(L, 1, &arg1, "cc.Mat4");
    olua_pack_object(L, 2, &arg2);

    // @extend(cocos2d::Mat4Extend) @unpack static cocos2d::Vec2 transform(cocos2d::Mat4 *mat, @pack const cocos2d::Vec2 &p)
    cocos2d::Vec2 ret = cocos2d::Mat4Extend::transform(arg1, arg2);
    int num_ret = olua_unpack_object(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Mat4_transform(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Vec4"))) {
            // @extend(cocos2d::Mat4Extend) static cocos2d::Vec4 transform(cocos2d::Mat4 *mat, const cocos2d::Vec4 &p)
            return _olua_fun_cocos2d_Mat4_transform$1(L);
        }

        if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Vec3"))) {
            // @extend(cocos2d::Mat4Extend) static cocos2d::Vec3 transform(cocos2d::Mat4 *mat, const cocos2d::Vec3 &p)
            return _olua_fun_cocos2d_Mat4_transform$2(L);
        }

        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Vec2"))) {
            // @extend(cocos2d::Mat4Extend) static cocos2d::Vec2 transform(cocos2d::Mat4 *mat, const cocos2d::Vec2 &p)
            return _olua_fun_cocos2d_Mat4_transform$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_canpack_object(L, 2, (cocos2d::Vec2 *)nullptr))) {
            // @extend(cocos2d::Mat4Extend) @unpack static cocos2d::Vec2 transform(cocos2d::Mat4 *mat, @pack const cocos2d::Vec2 &p)
            return _olua_fun_cocos2d_Mat4_transform$6(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_canpack_object(L, 2, (cocos2d::Vec3 *)nullptr))) {
            // @extend(cocos2d::Mat4Extend) @unpack static cocos2d::Vec3 transform(cocos2d::Mat4 *mat, @pack const cocos2d::Vec3 &p)
            return _olua_fun_cocos2d_Mat4_transform$5(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_canpack_object(L, 2, (cocos2d::Vec4 *)nullptr))) {
            // @extend(cocos2d::Mat4Extend) @unpack static cocos2d::Vec4 transform(cocos2d::Mat4 *mat, @pack const cocos2d::Vec4 &p)
            return _olua_fun_cocos2d_Mat4_transform$4(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Mat4::transform' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_transformPoint$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Vec3 *arg1 = nullptr;       /** point */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // void transformPoint(cocos2d::Vec3 *point)
    self->transformPoint(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_transformPoint$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Vec3 *arg1;       /** point */
    cocos2d::Vec3 *arg2 = nullptr;       /** dst */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Vec3");
    olua_check_object(L, 3, &arg2, "cc.Vec3");

    // void transformPoint(const cocos2d::Vec3 &point, cocos2d::Vec3 *dst)
    self->transformPoint(*arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_transformPoint(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Vec3"))) {
            // void transformPoint(cocos2d::Vec3 *point)
            return _olua_fun_cocos2d_Mat4_transformPoint$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Vec3")) && (olua_is_object(L, 3, "cc.Vec3"))) {
            // void transformPoint(const cocos2d::Vec3 &point, cocos2d::Vec3 *dst)
            return _olua_fun_cocos2d_Mat4_transformPoint$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Mat4::transformPoint' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_transformVector$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Vec3 *arg1 = nullptr;       /** vector */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // void transformVector(cocos2d::Vec3 *vector)
    self->transformVector(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_transformVector$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Vec3 *arg1;       /** vector */
    cocos2d::Vec3 *arg2 = nullptr;       /** dst */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Vec3");
    olua_check_object(L, 3, &arg2, "cc.Vec3");

    // void transformVector(const cocos2d::Vec3 &vector, cocos2d::Vec3 *dst)
    self->transformVector(*arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_transformVector$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    float arg1 = 0;       /** x */
    float arg2 = 0;       /** y */
    float arg3 = 0;       /** z */
    float arg4 = 0;       /** w */
    cocos2d::Vec3 *arg5 = nullptr;       /** dst */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);
    olua_check_object(L, 6, &arg5, "cc.Vec3");

    // void transformVector(float x, float y, float z, float w, cocos2d::Vec3 *dst)
    self->transformVector(arg1, arg2, arg3, arg4, arg5);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_transformVector$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Vec4 *arg1 = nullptr;       /** vector */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Vec4");

    // void transformVector(cocos2d::Vec4 *vector)
    self->transformVector(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_transformVector$5(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Vec4 *arg1;       /** vector */
    cocos2d::Vec4 *arg2 = nullptr;       /** dst */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Vec4");
    olua_check_object(L, 3, &arg2, "cc.Vec4");

    // void transformVector(const cocos2d::Vec4 &vector, cocos2d::Vec4 *dst)
    self->transformVector(*arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_transformVector(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Vec4"))) {
            // void transformVector(cocos2d::Vec4 *vector)
            return _olua_fun_cocos2d_Mat4_transformVector$4(L);
        }

        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Vec3"))) {
            // void transformVector(cocos2d::Vec3 *vector)
            return _olua_fun_cocos2d_Mat4_transformVector$1(L);
        // }
    }

    if (num_args == 3) {
        if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Vec4")) && (olua_is_object(L, 3, "cc.Vec4"))) {
            // void transformVector(const cocos2d::Vec4 &vector, cocos2d::Vec4 *dst)
            return _olua_fun_cocos2d_Mat4_transformVector$5(L);
        }

        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Vec3")) && (olua_is_object(L, 3, "cc.Vec3"))) {
            // void transformVector(const cocos2d::Vec3 &vector, cocos2d::Vec3 *dst)
            return _olua_fun_cocos2d_Mat4_transformVector$2(L);
        // }
    }

    if (num_args == 6) {
        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5)) && (olua_is_object(L, 6, "cc.Vec3"))) {
            // void transformVector(float x, float y, float z, float w, cocos2d::Vec3 *dst)
            return _olua_fun_cocos2d_Mat4_transformVector$3(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Mat4::transformVector' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_translate$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    float arg1 = 0;       /** x */
    float arg2 = 0;       /** y */
    float arg3 = 0;       /** z */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);

    // void translate(float x, float y, float z)
    self->translate(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_translate$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    float arg1 = 0;       /** x */
    float arg2 = 0;       /** y */
    float arg3 = 0;       /** z */
    cocos2d::Mat4 *arg4 = nullptr;       /** dst */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_object(L, 5, &arg4, "cc.Mat4");

    // void translate(float x, float y, float z, cocos2d::Mat4 *dst)
    self->translate(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_translate$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Vec3 *arg1;       /** t */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // void translate(const cocos2d::Vec3 &t)
    self->translate(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_translate$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;
    cocos2d::Vec3 *arg1;       /** t */
    cocos2d::Mat4 *arg2 = nullptr;       /** dst */

    olua_to_object(L, 1, &self, "cc.Mat4");
    olua_check_object(L, 2, &arg1, "cc.Vec3");
    olua_check_object(L, 3, &arg2, "cc.Mat4");

    // void translate(const cocos2d::Vec3 &t, cocos2d::Mat4 *dst)
    self->translate(*arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_translate(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Vec3"))) {
            // void translate(const cocos2d::Vec3 &t)
            return _olua_fun_cocos2d_Mat4_translate$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_object(L, 2, "cc.Vec3")) && (olua_is_object(L, 3, "cc.Mat4"))) {
            // void translate(const cocos2d::Vec3 &t, cocos2d::Mat4 *dst)
            return _olua_fun_cocos2d_Mat4_translate$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4))) {
            // void translate(float x, float y, float z)
            return _olua_fun_cocos2d_Mat4_translate$1(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "cc.Mat4")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_object(L, 5, "cc.Mat4"))) {
            // void translate(float x, float y, float z, cocos2d::Mat4 *dst)
            return _olua_fun_cocos2d_Mat4_translate$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Mat4::translate' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Mat4_transpose(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Mat4");

    // void transpose()
    self->transpose();

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_cc_Mat4(lua_State *L)
{
    oluacls_class<cocos2d::Mat4>(L, "cc.Mat4");
    oluacls_func(L, "__add", _olua_fun_cocos2d_Mat4___add);
    oluacls_func(L, "__gc", _olua_fun_cocos2d_Mat4___gc);
    oluacls_func(L, "__mul", _olua_fun_cocos2d_Mat4___mul);
    oluacls_func(L, "__sub", _olua_fun_cocos2d_Mat4___sub);
    oluacls_func(L, "__unm", _olua_fun_cocos2d_Mat4___unm);
    oluacls_func(L, "add", _olua_fun_cocos2d_Mat4_add);
    oluacls_func(L, "createBillboard", _olua_fun_cocos2d_Mat4_createBillboard);
    oluacls_func(L, "createLookAt", _olua_fun_cocos2d_Mat4_createLookAt);
    oluacls_func(L, "createOrthographic", _olua_fun_cocos2d_Mat4_createOrthographic);
    oluacls_func(L, "createOrthographicOffCenter", _olua_fun_cocos2d_Mat4_createOrthographicOffCenter);
    oluacls_func(L, "createPerspective", _olua_fun_cocos2d_Mat4_createPerspective);
    oluacls_func(L, "createRotation", _olua_fun_cocos2d_Mat4_createRotation);
    oluacls_func(L, "createRotationX", _olua_fun_cocos2d_Mat4_createRotationX);
    oluacls_func(L, "createRotationY", _olua_fun_cocos2d_Mat4_createRotationY);
    oluacls_func(L, "createRotationZ", _olua_fun_cocos2d_Mat4_createRotationZ);
    oluacls_func(L, "createScale", _olua_fun_cocos2d_Mat4_createScale);
    oluacls_func(L, "createTranslation", _olua_fun_cocos2d_Mat4_createTranslation);
    oluacls_func(L, "decompose", _olua_fun_cocos2d_Mat4_decompose);
    oluacls_func(L, "determinant", _olua_fun_cocos2d_Mat4_determinant);
    oluacls_func(L, "getBackVector", _olua_fun_cocos2d_Mat4_getBackVector);
    oluacls_func(L, "getDownVector", _olua_fun_cocos2d_Mat4_getDownVector);
    oluacls_func(L, "getForwardVector", _olua_fun_cocos2d_Mat4_getForwardVector);
    oluacls_func(L, "getInversed", _olua_fun_cocos2d_Mat4_getInversed);
    oluacls_func(L, "getLeftVector", _olua_fun_cocos2d_Mat4_getLeftVector);
    oluacls_func(L, "getNegated", _olua_fun_cocos2d_Mat4_getNegated);
    oluacls_func(L, "getRightVector", _olua_fun_cocos2d_Mat4_getRightVector);
    oluacls_func(L, "getRotation", _olua_fun_cocos2d_Mat4_getRotation);
    oluacls_func(L, "getScale", _olua_fun_cocos2d_Mat4_getScale);
    oluacls_func(L, "getTranslation", _olua_fun_cocos2d_Mat4_getTranslation);
    oluacls_func(L, "getTransposed", _olua_fun_cocos2d_Mat4_getTransposed);
    oluacls_func(L, "getUpVector", _olua_fun_cocos2d_Mat4_getUpVector);
    oluacls_func(L, "inverse", _olua_fun_cocos2d_Mat4_inverse);
    oluacls_func(L, "isIdentity", _olua_fun_cocos2d_Mat4_isIdentity);
    oluacls_func(L, "multiply", _olua_fun_cocos2d_Mat4_multiply);
    oluacls_func(L, "negate", _olua_fun_cocos2d_Mat4_negate);
    oluacls_func(L, "new", _olua_fun_cocos2d_Mat4_new);
    oluacls_func(L, "rotate", _olua_fun_cocos2d_Mat4_rotate);
    oluacls_func(L, "rotateX", _olua_fun_cocos2d_Mat4_rotateX);
    oluacls_func(L, "rotateY", _olua_fun_cocos2d_Mat4_rotateY);
    oluacls_func(L, "rotateZ", _olua_fun_cocos2d_Mat4_rotateZ);
    oluacls_func(L, "scale", _olua_fun_cocos2d_Mat4_scale);
    oluacls_func(L, "set", _olua_fun_cocos2d_Mat4_set);
    oluacls_func(L, "setIdentity", _olua_fun_cocos2d_Mat4_setIdentity);
    oluacls_func(L, "setZero", _olua_fun_cocos2d_Mat4_setZero);
    oluacls_func(L, "subtract", _olua_fun_cocos2d_Mat4_subtract);
    oluacls_func(L, "transform", _olua_fun_cocos2d_Mat4_transform);
    oluacls_func(L, "transformPoint", _olua_fun_cocos2d_Mat4_transformPoint);
    oluacls_func(L, "transformVector", _olua_fun_cocos2d_Mat4_transformVector);
    oluacls_func(L, "translate", _olua_fun_cocos2d_Mat4_translate);
    oluacls_func(L, "transpose", _olua_fun_cocos2d_Mat4_transpose);
    oluacls_prop(L, "identity", _olua_fun_cocos2d_Mat4_isIdentity, _olua_fun_cocos2d_Mat4_setIdentity);
    oluacls_prop(L, "inversed", _olua_fun_cocos2d_Mat4_getInversed, nullptr);
    oluacls_prop(L, "negated", _olua_fun_cocos2d_Mat4_getNegated, nullptr);
    oluacls_prop(L, "transposed", _olua_fun_cocos2d_Mat4_getTransposed, nullptr);
    oluacls_const(L, "IDENTITY", &cocos2d::Mat4::IDENTITY);
    oluacls_const(L, "ZERO", &cocos2d::Mat4::ZERO);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cc_Mat4(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "cc.Mat4")) {
        luaL_error(L, "class not found: cocos2d::Mat4");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_Viewport___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Viewport *)olua_toobj(L, 1, "cc.Viewport");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Viewport_h$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Viewport *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Viewport");

    // unsigned int h
    unsigned int ret = self->h;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Viewport_h$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Viewport *self = nullptr;
    unsigned int arg1 = 0;       /** h */

    olua_to_object(L, 1, &self, "cc.Viewport");
    olua_check_integer(L, 2, &arg1);

    // unsigned int h
    self->h = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Viewport_h(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // unsigned int h
        return _olua_fun_cocos2d_Viewport_h$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Viewport")) && (olua_is_integer(L, 2))) {
            // unsigned int h
            return _olua_fun_cocos2d_Viewport_h$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Viewport::h' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Viewport_w$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Viewport *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Viewport");

    // unsigned int w
    unsigned int ret = self->w;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Viewport_w$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Viewport *self = nullptr;
    unsigned int arg1 = 0;       /** w */

    olua_to_object(L, 1, &self, "cc.Viewport");
    olua_check_integer(L, 2, &arg1);

    // unsigned int w
    self->w = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Viewport_w(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // unsigned int w
        return _olua_fun_cocos2d_Viewport_w$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Viewport")) && (olua_is_integer(L, 2))) {
            // unsigned int w
            return _olua_fun_cocos2d_Viewport_w$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Viewport::w' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Viewport_x$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Viewport *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Viewport");

    // int x
    int ret = self->x;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Viewport_x$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Viewport *self = nullptr;
    int arg1 = 0;       /** x */

    olua_to_object(L, 1, &self, "cc.Viewport");
    olua_check_integer(L, 2, &arg1);

    // int x
    self->x = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Viewport_x(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // int x
        return _olua_fun_cocos2d_Viewport_x$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Viewport")) && (olua_is_integer(L, 2))) {
            // int x
            return _olua_fun_cocos2d_Viewport_x$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Viewport::x' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Viewport_y$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Viewport *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Viewport");

    // int y
    int ret = self->y;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Viewport_y$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Viewport *self = nullptr;
    int arg1 = 0;       /** y */

    olua_to_object(L, 1, &self, "cc.Viewport");
    olua_check_integer(L, 2, &arg1);

    // int y
    self->y = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Viewport_y(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // int y
        return _olua_fun_cocos2d_Viewport_y$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Viewport")) && (olua_is_integer(L, 2))) {
            // int y
            return _olua_fun_cocos2d_Viewport_y$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Viewport::y' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_cc_Viewport(lua_State *L)
{
    oluacls_class<cocos2d::Viewport>(L, "cc.Viewport");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_Viewport___gc);
    oluacls_prop(L, "x", _olua_fun_cocos2d_Viewport_x, _olua_fun_cocos2d_Viewport_x);
    oluacls_prop(L, "y", _olua_fun_cocos2d_Viewport_y, _olua_fun_cocos2d_Viewport_y);
    oluacls_prop(L, "w", _olua_fun_cocos2d_Viewport_w, _olua_fun_cocos2d_Viewport_w);
    oluacls_prop(L, "h", _olua_fun_cocos2d_Viewport_h, _olua_fun_cocos2d_Viewport_h);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cc_Viewport(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "cc.Viewport")) {
        luaL_error(L, "class not found: cocos2d::Viewport");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ScissorRect___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ScissorRect *)olua_toobj(L, 1, "cc.ScissorRect");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ScissorRect_height$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ScissorRect *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ScissorRect");

    // float height
    float ret = self->height;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ScissorRect_height$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ScissorRect *self = nullptr;
    float arg1 = 0;       /** height */

    olua_to_object(L, 1, &self, "cc.ScissorRect");
    olua_check_number(L, 2, &arg1);

    // float height
    self->height = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ScissorRect_height(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float height
        return _olua_fun_cocos2d_ScissorRect_height$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.ScissorRect")) && (olua_is_number(L, 2))) {
            // float height
            return _olua_fun_cocos2d_ScissorRect_height$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ScissorRect::height' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ScissorRect_width$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ScissorRect *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ScissorRect");

    // float width
    float ret = self->width;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ScissorRect_width$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ScissorRect *self = nullptr;
    float arg1 = 0;       /** width */

    olua_to_object(L, 1, &self, "cc.ScissorRect");
    olua_check_number(L, 2, &arg1);

    // float width
    self->width = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ScissorRect_width(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float width
        return _olua_fun_cocos2d_ScissorRect_width$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.ScissorRect")) && (olua_is_number(L, 2))) {
            // float width
            return _olua_fun_cocos2d_ScissorRect_width$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ScissorRect::width' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ScissorRect_x$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ScissorRect *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ScissorRect");

    // float x
    float ret = self->x;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ScissorRect_x$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ScissorRect *self = nullptr;
    float arg1 = 0;       /** x */

    olua_to_object(L, 1, &self, "cc.ScissorRect");
    olua_check_number(L, 2, &arg1);

    // float x
    self->x = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ScissorRect_x(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float x
        return _olua_fun_cocos2d_ScissorRect_x$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.ScissorRect")) && (olua_is_number(L, 2))) {
            // float x
            return _olua_fun_cocos2d_ScissorRect_x$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ScissorRect::x' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ScissorRect_y$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ScissorRect *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ScissorRect");

    // float y
    float ret = self->y;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ScissorRect_y$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ScissorRect *self = nullptr;
    float arg1 = 0;       /** y */

    olua_to_object(L, 1, &self, "cc.ScissorRect");
    olua_check_number(L, 2, &arg1);

    // float y
    self->y = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ScissorRect_y(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float y
        return _olua_fun_cocos2d_ScissorRect_y$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.ScissorRect")) && (olua_is_number(L, 2))) {
            // float y
            return _olua_fun_cocos2d_ScissorRect_y$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ScissorRect::y' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_cc_ScissorRect(lua_State *L)
{
    oluacls_class<cocos2d::ScissorRect>(L, "cc.ScissorRect");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_ScissorRect___gc);
    oluacls_prop(L, "x", _olua_fun_cocos2d_ScissorRect_x, _olua_fun_cocos2d_ScissorRect_x);
    oluacls_prop(L, "y", _olua_fun_cocos2d_ScissorRect_y, _olua_fun_cocos2d_ScissorRect_y);
    oluacls_prop(L, "width", _olua_fun_cocos2d_ScissorRect_width, _olua_fun_cocos2d_ScissorRect_width);
    oluacls_prop(L, "height", _olua_fun_cocos2d_ScissorRect_height, _olua_fun_cocos2d_ScissorRect_height);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cc_ScissorRect(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "cc.ScissorRect")) {
        luaL_error(L, "class not found: cocos2d::ScissorRect");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_Quaternion___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Quaternion *)olua_toobj(L, 1, "cc.Quaternion");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Quaternion___mul$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *self = nullptr;
    cocos2d::Quaternion *arg1;       /** q */

    olua_to_object(L, 1, &self, "cc.Quaternion");
    olua_check_object(L, 2, &arg1, "cc.Quaternion");

    // @operator(operator*) cocos2d::Quaternion operator*(const cocos2d::Quaternion &q)
    cocos2d::Quaternion ret = (*self) * (*arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Quaternion");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Quaternion___mul$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *self = nullptr;
    cocos2d::Vec3 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.Quaternion");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // @operator(operator*) cocos2d::Vec3 operator*(const cocos2d::Vec3 &v)
    cocos2d::Vec3 ret = (*self) * (*arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Vec3");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Quaternion___mul(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "cc.Quaternion")) && (olua_is_object(L, 2, "cc.Vec3"))) {
            // @operator(operator*) cocos2d::Vec3 operator*(const cocos2d::Vec3 &v)
            return _olua_fun_cocos2d_Quaternion___mul$2(L);
        }

        // if ((olua_is_object(L, 1, "cc.Quaternion")) && (olua_is_object(L, 2, "cc.Quaternion"))) {
            // @operator(operator*) cocos2d::Quaternion operator*(const cocos2d::Quaternion &q)
            return _olua_fun_cocos2d_Quaternion___mul$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Quaternion::__mul' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Quaternion_conjugate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Quaternion");

    // void conjugate()
    self->conjugate();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Quaternion_createFromAxisAngle(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *arg1;       /** axis */
    float arg2 = 0;       /** angle */
    cocos2d::Quaternion *arg3 = nullptr;       /** dst */

    olua_check_object(L, 1, &arg1, "cc.Vec3");
    olua_check_number(L, 2, &arg2);
    olua_check_object(L, 3, &arg3, "cc.Quaternion");

    // static void createFromAxisAngle(const cocos2d::Vec3 &axis, float angle, cocos2d::Quaternion *dst)
    cocos2d::Quaternion::createFromAxisAngle(*arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Quaternion_createFromRotationMatrix(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *arg1;       /** m */
    cocos2d::Quaternion *arg2 = nullptr;       /** dst */

    olua_check_object(L, 1, &arg1, "cc.Mat4");
    olua_check_object(L, 2, &arg2, "cc.Quaternion");

    // static void createFromRotationMatrix(const cocos2d::Mat4 &m, cocos2d::Quaternion *dst)
    cocos2d::Quaternion::createFromRotationMatrix(*arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Quaternion_getConjugated(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Quaternion");

    // cocos2d::Quaternion getConjugated()
    cocos2d::Quaternion ret = self->getConjugated();
    int num_ret = olua_copy_object(L, ret, "cc.Quaternion");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Quaternion_getInversed(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Quaternion");

    // cocos2d::Quaternion getInversed()
    cocos2d::Quaternion ret = self->getInversed();
    int num_ret = olua_copy_object(L, ret, "cc.Quaternion");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Quaternion_getNormalized(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Quaternion");

    // cocos2d::Quaternion getNormalized()
    cocos2d::Quaternion ret = self->getNormalized();
    int num_ret = olua_copy_object(L, ret, "cc.Quaternion");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Quaternion_identity(lua_State *L)
{
    olua_startinvoke(L);

    // static const cocos2d::Quaternion &identity()
    const cocos2d::Quaternion &ret = cocos2d::Quaternion::identity();
    int num_ret = olua_push_object(L, ret, "cc.Quaternion");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Quaternion_inverse(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Quaternion");

    // bool inverse()
    bool ret = self->inverse();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Quaternion_isIdentity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Quaternion");

    // bool isIdentity()
    bool ret = self->isIdentity();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Quaternion_isZero(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Quaternion");

    // bool isZero()
    bool ret = self->isZero();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Quaternion_lerp(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *arg1;       /** q1 */
    cocos2d::Quaternion *arg2;       /** q2 */
    float arg3 = 0;       /** t */
    cocos2d::Quaternion *arg4 = nullptr;       /** dst */

    olua_check_object(L, 1, &arg1, "cc.Quaternion");
    olua_check_object(L, 2, &arg2, "cc.Quaternion");
    olua_check_number(L, 3, &arg3);
    olua_check_object(L, 4, &arg4, "cc.Quaternion");

    // static void lerp(const cocos2d::Quaternion &q1, const cocos2d::Quaternion &q2, float t, cocos2d::Quaternion *dst)
    cocos2d::Quaternion::lerp(*arg1, *arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Quaternion_multiply$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *self = nullptr;
    cocos2d::Quaternion *arg1;       /** q */

    olua_to_object(L, 1, &self, "cc.Quaternion");
    olua_check_object(L, 2, &arg1, "cc.Quaternion");

    // void multiply(const cocos2d::Quaternion &q)
    self->multiply(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Quaternion_multiply$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *arg1;       /** q1 */
    cocos2d::Quaternion *arg2;       /** q2 */
    cocos2d::Quaternion *arg3 = nullptr;       /** dst */

    olua_check_object(L, 1, &arg1, "cc.Quaternion");
    olua_check_object(L, 2, &arg2, "cc.Quaternion");
    olua_check_object(L, 3, &arg3, "cc.Quaternion");

    // static void multiply(const cocos2d::Quaternion &q1, const cocos2d::Quaternion &q2, cocos2d::Quaternion *dst)
    cocos2d::Quaternion::multiply(*arg1, *arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Quaternion_multiply(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Quaternion")) && (olua_is_object(L, 2, "cc.Quaternion"))) {
            // void multiply(const cocos2d::Quaternion &q)
            return _olua_fun_cocos2d_Quaternion_multiply$1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Quaternion")) && (olua_is_object(L, 2, "cc.Quaternion")) && (olua_is_object(L, 3, "cc.Quaternion"))) {
            // static void multiply(const cocos2d::Quaternion &q1, const cocos2d::Quaternion &q2, cocos2d::Quaternion *dst)
            return _olua_fun_cocos2d_Quaternion_multiply$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Quaternion::multiply' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Quaternion_new$1(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::Quaternion()
    cocos2d::Quaternion *ret = new cocos2d::Quaternion();
    int num_ret = olua_push_object(L, ret, "cc.Quaternion");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Quaternion_new$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** xx */
    float arg2 = 0;       /** yy */
    float arg3 = 0;       /** zz */
    float arg4 = 0;       /** ww */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // cocos2d::Quaternion(float xx, float yy, float zz, float ww)
    cocos2d::Quaternion *ret = new cocos2d::Quaternion(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.Quaternion");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Quaternion_new$3(lua_State *L)
{
    olua_startinvoke(L);

    float *arg1 = nullptr;       /** array */

    olua_check_pointer(L, 1, &arg1, "olua.float");

    // cocos2d::Quaternion(float *array)
    cocos2d::Quaternion *ret = new cocos2d::Quaternion(arg1);
    int num_ret = olua_push_object(L, ret, "cc.Quaternion");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Quaternion_new$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Mat4 *arg1;       /** m */

    olua_check_object(L, 1, &arg1, "cc.Mat4");

    // cocos2d::Quaternion(const cocos2d::Mat4 &m)
    cocos2d::Quaternion *ret = new cocos2d::Quaternion(*arg1);
    int num_ret = olua_push_object(L, ret, "cc.Quaternion");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Quaternion_new$5(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec3 *arg1;       /** axis */
    float arg2 = 0;       /** angle */

    olua_check_object(L, 1, &arg1, "cc.Vec3");
    olua_check_number(L, 2, &arg2);

    // cocos2d::Quaternion(const cocos2d::Vec3 &axis, float angle)
    cocos2d::Quaternion *ret = new cocos2d::Quaternion(*arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.Quaternion");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Quaternion_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // cocos2d::Quaternion()
        return _olua_fun_cocos2d_Quaternion_new$1(L);
    }

    if (num_args == 1) {
        if ((olua_is_pointer(L, 1, "olua.float"))) {
            // cocos2d::Quaternion(float *array)
            return _olua_fun_cocos2d_Quaternion_new$3(L);
        }

        // if ((olua_is_object(L, 1, "cc.Mat4"))) {
            // cocos2d::Quaternion(const cocos2d::Mat4 &m)
            return _olua_fun_cocos2d_Quaternion_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec3")) && (olua_is_number(L, 2))) {
            // cocos2d::Quaternion(const cocos2d::Vec3 &axis, float angle)
            return _olua_fun_cocos2d_Quaternion_new$5(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4))) {
            // cocos2d::Quaternion(float xx, float yy, float zz, float ww)
            return _olua_fun_cocos2d_Quaternion_new$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Quaternion::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Quaternion_normalize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Quaternion");

    // void normalize()
    self->normalize();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Quaternion_set$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *self = nullptr;
    float arg1 = 0;       /** xx */
    float arg2 = 0;       /** yy */
    float arg3 = 0;       /** zz */
    float arg4 = 0;       /** ww */

    olua_to_object(L, 1, &self, "cc.Quaternion");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // void set(float xx, float yy, float zz, float ww)
    self->set(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Quaternion_set$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *self = nullptr;
    float *arg1 = nullptr;       /** array */

    olua_to_object(L, 1, &self, "cc.Quaternion");
    olua_check_pointer(L, 2, &arg1, "olua.float");

    // void set(float *array)
    self->set(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Quaternion_set$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *self = nullptr;
    cocos2d::Mat4 *arg1;       /** m */

    olua_to_object(L, 1, &self, "cc.Quaternion");
    olua_check_object(L, 2, &arg1, "cc.Mat4");

    // void set(const cocos2d::Mat4 &m)
    self->set(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Quaternion_set$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *self = nullptr;
    cocos2d::Vec3 *arg1;       /** axis */
    float arg2 = 0;       /** angle */

    olua_to_object(L, 1, &self, "cc.Quaternion");
    olua_check_object(L, 2, &arg1, "cc.Vec3");
    olua_check_number(L, 3, &arg2);

    // void set(const cocos2d::Vec3 &axis, float angle)
    self->set(*arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Quaternion_set$5(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *self = nullptr;
    cocos2d::Quaternion *arg1;       /** q */

    olua_to_object(L, 1, &self, "cc.Quaternion");
    olua_check_object(L, 2, &arg1, "cc.Quaternion");

    // void set(const cocos2d::Quaternion &q)
    self->set(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Quaternion_set(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_object(L, 1, "cc.Quaternion")) && (olua_is_pointer(L, 2, "olua.float"))) {
            // void set(float *array)
            return _olua_fun_cocos2d_Quaternion_set$2(L);
        }

        if ((olua_is_object(L, 1, "cc.Quaternion")) && (olua_is_object(L, 2, "cc.Mat4"))) {
            // void set(const cocos2d::Mat4 &m)
            return _olua_fun_cocos2d_Quaternion_set$3(L);
        }

        // if ((olua_is_object(L, 1, "cc.Quaternion")) && (olua_is_object(L, 2, "cc.Quaternion"))) {
            // void set(const cocos2d::Quaternion &q)
            return _olua_fun_cocos2d_Quaternion_set$5(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.Quaternion")) && (olua_is_object(L, 2, "cc.Vec3")) && (olua_is_number(L, 3))) {
            // void set(const cocos2d::Vec3 &axis, float angle)
            return _olua_fun_cocos2d_Quaternion_set$4(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_object(L, 1, "cc.Quaternion")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4)) && (olua_is_number(L, 5))) {
            // void set(float xx, float yy, float zz, float ww)
            return _olua_fun_cocos2d_Quaternion_set$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Quaternion::set' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Quaternion_setIdentity(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Quaternion");

    // void setIdentity()
    self->setIdentity();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Quaternion_slerp(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *arg1;       /** q1 */
    cocos2d::Quaternion *arg2;       /** q2 */
    float arg3 = 0;       /** t */
    cocos2d::Quaternion *arg4 = nullptr;       /** dst */

    olua_check_object(L, 1, &arg1, "cc.Quaternion");
    olua_check_object(L, 2, &arg2, "cc.Quaternion");
    olua_check_number(L, 3, &arg3);
    olua_check_object(L, 4, &arg4, "cc.Quaternion");

    // static void slerp(const cocos2d::Quaternion &q1, const cocos2d::Quaternion &q2, float t, cocos2d::Quaternion *dst)
    cocos2d::Quaternion::slerp(*arg1, *arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Quaternion_squad(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *arg1;       /** q1 */
    cocos2d::Quaternion *arg2;       /** q2 */
    cocos2d::Quaternion *arg3;       /** s1 */
    cocos2d::Quaternion *arg4;       /** s2 */
    float arg5 = 0;       /** t */
    cocos2d::Quaternion *arg6 = nullptr;       /** dst */

    olua_check_object(L, 1, &arg1, "cc.Quaternion");
    olua_check_object(L, 2, &arg2, "cc.Quaternion");
    olua_check_object(L, 3, &arg3, "cc.Quaternion");
    olua_check_object(L, 4, &arg4, "cc.Quaternion");
    olua_check_number(L, 5, &arg5);
    olua_check_object(L, 6, &arg6, "cc.Quaternion");

    // static void squad(const cocos2d::Quaternion &q1, const cocos2d::Quaternion &q2, const cocos2d::Quaternion &s1, const cocos2d::Quaternion &s2, float t, cocos2d::Quaternion *dst)
    cocos2d::Quaternion::squad(*arg1, *arg2, *arg3, *arg4, arg5, arg6);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Quaternion_toAxisAngle(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *self = nullptr;
    cocos2d::Vec3 *arg1 = nullptr;       /** e */

    olua_to_object(L, 1, &self, "cc.Quaternion");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // float toAxisAngle(cocos2d::Vec3 *e)
    float ret = self->toAxisAngle(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Quaternion_w$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Quaternion");

    // float w
    float ret = self->w;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Quaternion_w$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *self = nullptr;
    float arg1 = 0;       /** w */

    olua_to_object(L, 1, &self, "cc.Quaternion");
    olua_check_number(L, 2, &arg1);

    // float w
    self->w = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Quaternion_w(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float w
        return _olua_fun_cocos2d_Quaternion_w$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Quaternion")) && (olua_is_number(L, 2))) {
            // float w
            return _olua_fun_cocos2d_Quaternion_w$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Quaternion::w' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Quaternion_x$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Quaternion");

    // float x
    float ret = self->x;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Quaternion_x$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *self = nullptr;
    float arg1 = 0;       /** x */

    olua_to_object(L, 1, &self, "cc.Quaternion");
    olua_check_number(L, 2, &arg1);

    // float x
    self->x = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Quaternion_x(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float x
        return _olua_fun_cocos2d_Quaternion_x$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Quaternion")) && (olua_is_number(L, 2))) {
            // float x
            return _olua_fun_cocos2d_Quaternion_x$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Quaternion::x' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Quaternion_y$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Quaternion");

    // float y
    float ret = self->y;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Quaternion_y$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *self = nullptr;
    float arg1 = 0;       /** y */

    olua_to_object(L, 1, &self, "cc.Quaternion");
    olua_check_number(L, 2, &arg1);

    // float y
    self->y = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Quaternion_y(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float y
        return _olua_fun_cocos2d_Quaternion_y$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Quaternion")) && (olua_is_number(L, 2))) {
            // float y
            return _olua_fun_cocos2d_Quaternion_y$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Quaternion::y' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Quaternion_z$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Quaternion");

    // float z
    float ret = self->z;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Quaternion_z$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quaternion *self = nullptr;
    float arg1 = 0;       /** z */

    olua_to_object(L, 1, &self, "cc.Quaternion");
    olua_check_number(L, 2, &arg1);

    // float z
    self->z = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Quaternion_z(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float z
        return _olua_fun_cocos2d_Quaternion_z$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Quaternion")) && (olua_is_number(L, 2))) {
            // float z
            return _olua_fun_cocos2d_Quaternion_z$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Quaternion::z' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Quaternion_zero(lua_State *L)
{
    olua_startinvoke(L);

    // static const cocos2d::Quaternion &zero()
    const cocos2d::Quaternion &ret = cocos2d::Quaternion::zero();
    int num_ret = olua_push_object(L, ret, "cc.Quaternion");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_cc_Quaternion(lua_State *L)
{
    oluacls_class<cocos2d::Quaternion>(L, "cc.Quaternion");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_Quaternion___gc);
    oluacls_func(L, "__mul", _olua_fun_cocos2d_Quaternion___mul);
    oluacls_func(L, "conjugate", _olua_fun_cocos2d_Quaternion_conjugate);
    oluacls_func(L, "createFromAxisAngle", _olua_fun_cocos2d_Quaternion_createFromAxisAngle);
    oluacls_func(L, "createFromRotationMatrix", _olua_fun_cocos2d_Quaternion_createFromRotationMatrix);
    oluacls_func(L, "getConjugated", _olua_fun_cocos2d_Quaternion_getConjugated);
    oluacls_func(L, "getInversed", _olua_fun_cocos2d_Quaternion_getInversed);
    oluacls_func(L, "getNormalized", _olua_fun_cocos2d_Quaternion_getNormalized);
    oluacls_func(L, "identity", _olua_fun_cocos2d_Quaternion_identity);
    oluacls_func(L, "inverse", _olua_fun_cocos2d_Quaternion_inverse);
    oluacls_func(L, "isIdentity", _olua_fun_cocos2d_Quaternion_isIdentity);
    oluacls_func(L, "isZero", _olua_fun_cocos2d_Quaternion_isZero);
    oluacls_func(L, "lerp", _olua_fun_cocos2d_Quaternion_lerp);
    oluacls_func(L, "multiply", _olua_fun_cocos2d_Quaternion_multiply);
    oluacls_func(L, "new", _olua_fun_cocos2d_Quaternion_new);
    oluacls_func(L, "normalize", _olua_fun_cocos2d_Quaternion_normalize);
    oluacls_func(L, "set", _olua_fun_cocos2d_Quaternion_set);
    oluacls_func(L, "setIdentity", _olua_fun_cocos2d_Quaternion_setIdentity);
    oluacls_func(L, "slerp", _olua_fun_cocos2d_Quaternion_slerp);
    oluacls_func(L, "squad", _olua_fun_cocos2d_Quaternion_squad);
    oluacls_func(L, "toAxisAngle", _olua_fun_cocos2d_Quaternion_toAxisAngle);
    oluacls_func(L, "zero", _olua_fun_cocos2d_Quaternion_zero);
    oluacls_prop(L, "conjugated", _olua_fun_cocos2d_Quaternion_getConjugated, nullptr);
    oluacls_prop(L, "inversed", _olua_fun_cocos2d_Quaternion_getInversed, nullptr);
    oluacls_prop(L, "normalized", _olua_fun_cocos2d_Quaternion_getNormalized, nullptr);
    oluacls_prop(L, "x", _olua_fun_cocos2d_Quaternion_x, _olua_fun_cocos2d_Quaternion_x);
    oluacls_prop(L, "y", _olua_fun_cocos2d_Quaternion_y, _olua_fun_cocos2d_Quaternion_y);
    oluacls_prop(L, "z", _olua_fun_cocos2d_Quaternion_z, _olua_fun_cocos2d_Quaternion_z);
    oluacls_prop(L, "w", _olua_fun_cocos2d_Quaternion_w, _olua_fun_cocos2d_Quaternion_w);
    oluacls_const(L, "ZERO", &cocos2d::Quaternion::ZERO);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cc_Quaternion(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "cc.Quaternion")) {
        luaL_error(L, "class not found: cocos2d::Quaternion");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_AffineTransform___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::AffineTransform *)olua_toobj(L, 1, "cc.AffineTransform");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_AffineTransform_a$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::AffineTransform *self = nullptr;

    olua_to_object(L, 1, &self, "cc.AffineTransform");

    // float a
    float ret = self->a;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_AffineTransform_a$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::AffineTransform *self = nullptr;
    float arg1 = 0;       /** a */

    olua_to_object(L, 1, &self, "cc.AffineTransform");
    olua_check_number(L, 2, &arg1);

    // float a
    self->a = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_AffineTransform_a(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float a
        return _olua_fun_cocos2d_AffineTransform_a$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.AffineTransform")) && (olua_is_number(L, 2))) {
            // float a
            return _olua_fun_cocos2d_AffineTransform_a$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::AffineTransform::a' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_AffineTransform_b$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::AffineTransform *self = nullptr;

    olua_to_object(L, 1, &self, "cc.AffineTransform");

    // float b
    float ret = self->b;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_AffineTransform_b$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::AffineTransform *self = nullptr;
    float arg1 = 0;       /** b */

    olua_to_object(L, 1, &self, "cc.AffineTransform");
    olua_check_number(L, 2, &arg1);

    // float b
    self->b = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_AffineTransform_b(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float b
        return _olua_fun_cocos2d_AffineTransform_b$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.AffineTransform")) && (olua_is_number(L, 2))) {
            // float b
            return _olua_fun_cocos2d_AffineTransform_b$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::AffineTransform::b' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_AffineTransform_c$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::AffineTransform *self = nullptr;

    olua_to_object(L, 1, &self, "cc.AffineTransform");

    // float c
    float ret = self->c;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_AffineTransform_c$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::AffineTransform *self = nullptr;
    float arg1 = 0;       /** c */

    olua_to_object(L, 1, &self, "cc.AffineTransform");
    olua_check_number(L, 2, &arg1);

    // float c
    self->c = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_AffineTransform_c(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float c
        return _olua_fun_cocos2d_AffineTransform_c$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.AffineTransform")) && (olua_is_number(L, 2))) {
            // float c
            return _olua_fun_cocos2d_AffineTransform_c$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::AffineTransform::c' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_AffineTransform_d$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::AffineTransform *self = nullptr;

    olua_to_object(L, 1, &self, "cc.AffineTransform");

    // float d
    float ret = self->d;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_AffineTransform_d$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::AffineTransform *self = nullptr;
    float arg1 = 0;       /** d */

    olua_to_object(L, 1, &self, "cc.AffineTransform");
    olua_check_number(L, 2, &arg1);

    // float d
    self->d = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_AffineTransform_d(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float d
        return _olua_fun_cocos2d_AffineTransform_d$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.AffineTransform")) && (olua_is_number(L, 2))) {
            // float d
            return _olua_fun_cocos2d_AffineTransform_d$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::AffineTransform::d' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_AffineTransform_tx$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::AffineTransform *self = nullptr;

    olua_to_object(L, 1, &self, "cc.AffineTransform");

    // float tx
    float ret = self->tx;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_AffineTransform_tx$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::AffineTransform *self = nullptr;
    float arg1 = 0;       /** tx */

    olua_to_object(L, 1, &self, "cc.AffineTransform");
    olua_check_number(L, 2, &arg1);

    // float tx
    self->tx = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_AffineTransform_tx(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float tx
        return _olua_fun_cocos2d_AffineTransform_tx$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.AffineTransform")) && (olua_is_number(L, 2))) {
            // float tx
            return _olua_fun_cocos2d_AffineTransform_tx$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::AffineTransform::tx' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_AffineTransform_ty$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::AffineTransform *self = nullptr;

    olua_to_object(L, 1, &self, "cc.AffineTransform");

    // float ty
    float ret = self->ty;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_AffineTransform_ty$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::AffineTransform *self = nullptr;
    float arg1 = 0;       /** ty */

    olua_to_object(L, 1, &self, "cc.AffineTransform");
    olua_check_number(L, 2, &arg1);

    // float ty
    self->ty = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_AffineTransform_ty(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float ty
        return _olua_fun_cocos2d_AffineTransform_ty$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.AffineTransform")) && (olua_is_number(L, 2))) {
            // float ty
            return _olua_fun_cocos2d_AffineTransform_ty$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::AffineTransform::ty' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_cc_AffineTransform(lua_State *L)
{
    oluacls_class<cocos2d::AffineTransform>(L, "cc.AffineTransform");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_AffineTransform___gc);
    oluacls_prop(L, "a", _olua_fun_cocos2d_AffineTransform_a, _olua_fun_cocos2d_AffineTransform_a);
    oluacls_prop(L, "b", _olua_fun_cocos2d_AffineTransform_b, _olua_fun_cocos2d_AffineTransform_b);
    oluacls_prop(L, "c", _olua_fun_cocos2d_AffineTransform_c, _olua_fun_cocos2d_AffineTransform_c);
    oluacls_prop(L, "d", _olua_fun_cocos2d_AffineTransform_d, _olua_fun_cocos2d_AffineTransform_d);
    oluacls_prop(L, "tx", _olua_fun_cocos2d_AffineTransform_tx, _olua_fun_cocos2d_AffineTransform_tx);
    oluacls_prop(L, "ty", _olua_fun_cocos2d_AffineTransform_ty, _olua_fun_cocos2d_AffineTransform_ty);
    oluacls_const(L, "IDENTITY", &cocos2d::AffineTransform::IDENTITY);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cc_AffineTransform(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "cc.AffineTransform")) {
        luaL_error(L, "class not found: cocos2d::AffineTransform");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_GLContextAttrs___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (GLContextAttrs *)olua_toobj(L, 1, "cc.GLContextAttrs");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_GLContextAttrs_alphaBits$1(lua_State *L)
{
    olua_startinvoke(L);

    GLContextAttrs *self = nullptr;

    olua_to_object(L, 1, &self, "cc.GLContextAttrs");

    // int alphaBits
    int ret = self->alphaBits;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_GLContextAttrs_alphaBits$2(lua_State *L)
{
    olua_startinvoke(L);

    GLContextAttrs *self = nullptr;
    int arg1 = 0;       /** alphaBits */

    olua_to_object(L, 1, &self, "cc.GLContextAttrs");
    olua_check_integer(L, 2, &arg1);

    // int alphaBits
    self->alphaBits = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_GLContextAttrs_alphaBits(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // int alphaBits
        return _olua_fun_GLContextAttrs_alphaBits$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.GLContextAttrs")) && (olua_is_integer(L, 2))) {
            // int alphaBits
            return _olua_fun_GLContextAttrs_alphaBits$2(L);
        // }
    }

    luaL_error(L, "method 'GLContextAttrs::alphaBits' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_GLContextAttrs_blueBits$1(lua_State *L)
{
    olua_startinvoke(L);

    GLContextAttrs *self = nullptr;

    olua_to_object(L, 1, &self, "cc.GLContextAttrs");

    // int blueBits
    int ret = self->blueBits;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_GLContextAttrs_blueBits$2(lua_State *L)
{
    olua_startinvoke(L);

    GLContextAttrs *self = nullptr;
    int arg1 = 0;       /** blueBits */

    olua_to_object(L, 1, &self, "cc.GLContextAttrs");
    olua_check_integer(L, 2, &arg1);

    // int blueBits
    self->blueBits = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_GLContextAttrs_blueBits(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // int blueBits
        return _olua_fun_GLContextAttrs_blueBits$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.GLContextAttrs")) && (olua_is_integer(L, 2))) {
            // int blueBits
            return _olua_fun_GLContextAttrs_blueBits$2(L);
        // }
    }

    luaL_error(L, "method 'GLContextAttrs::blueBits' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_GLContextAttrs_depthBits$1(lua_State *L)
{
    olua_startinvoke(L);

    GLContextAttrs *self = nullptr;

    olua_to_object(L, 1, &self, "cc.GLContextAttrs");

    // int depthBits
    int ret = self->depthBits;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_GLContextAttrs_depthBits$2(lua_State *L)
{
    olua_startinvoke(L);

    GLContextAttrs *self = nullptr;
    int arg1 = 0;       /** depthBits */

    olua_to_object(L, 1, &self, "cc.GLContextAttrs");
    olua_check_integer(L, 2, &arg1);

    // int depthBits
    self->depthBits = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_GLContextAttrs_depthBits(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // int depthBits
        return _olua_fun_GLContextAttrs_depthBits$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.GLContextAttrs")) && (olua_is_integer(L, 2))) {
            // int depthBits
            return _olua_fun_GLContextAttrs_depthBits$2(L);
        // }
    }

    luaL_error(L, "method 'GLContextAttrs::depthBits' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_GLContextAttrs_greenBits$1(lua_State *L)
{
    olua_startinvoke(L);

    GLContextAttrs *self = nullptr;

    olua_to_object(L, 1, &self, "cc.GLContextAttrs");

    // int greenBits
    int ret = self->greenBits;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_GLContextAttrs_greenBits$2(lua_State *L)
{
    olua_startinvoke(L);

    GLContextAttrs *self = nullptr;
    int arg1 = 0;       /** greenBits */

    olua_to_object(L, 1, &self, "cc.GLContextAttrs");
    olua_check_integer(L, 2, &arg1);

    // int greenBits
    self->greenBits = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_GLContextAttrs_greenBits(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // int greenBits
        return _olua_fun_GLContextAttrs_greenBits$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.GLContextAttrs")) && (olua_is_integer(L, 2))) {
            // int greenBits
            return _olua_fun_GLContextAttrs_greenBits$2(L);
        // }
    }

    luaL_error(L, "method 'GLContextAttrs::greenBits' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_GLContextAttrs_multisamplingCount$1(lua_State *L)
{
    olua_startinvoke(L);

    GLContextAttrs *self = nullptr;

    olua_to_object(L, 1, &self, "cc.GLContextAttrs");

    // int multisamplingCount
    int ret = self->multisamplingCount;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_GLContextAttrs_multisamplingCount$2(lua_State *L)
{
    olua_startinvoke(L);

    GLContextAttrs *self = nullptr;
    int arg1 = 0;       /** multisamplingCount */

    olua_to_object(L, 1, &self, "cc.GLContextAttrs");
    olua_check_integer(L, 2, &arg1);

    // int multisamplingCount
    self->multisamplingCount = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_GLContextAttrs_multisamplingCount(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // int multisamplingCount
        return _olua_fun_GLContextAttrs_multisamplingCount$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.GLContextAttrs")) && (olua_is_integer(L, 2))) {
            // int multisamplingCount
            return _olua_fun_GLContextAttrs_multisamplingCount$2(L);
        // }
    }

    luaL_error(L, "method 'GLContextAttrs::multisamplingCount' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_GLContextAttrs_redBits$1(lua_State *L)
{
    olua_startinvoke(L);

    GLContextAttrs *self = nullptr;

    olua_to_object(L, 1, &self, "cc.GLContextAttrs");

    // int redBits
    int ret = self->redBits;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_GLContextAttrs_redBits$2(lua_State *L)
{
    olua_startinvoke(L);

    GLContextAttrs *self = nullptr;
    int arg1 = 0;       /** redBits */

    olua_to_object(L, 1, &self, "cc.GLContextAttrs");
    olua_check_integer(L, 2, &arg1);

    // int redBits
    self->redBits = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_GLContextAttrs_redBits(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // int redBits
        return _olua_fun_GLContextAttrs_redBits$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.GLContextAttrs")) && (olua_is_integer(L, 2))) {
            // int redBits
            return _olua_fun_GLContextAttrs_redBits$2(L);
        // }
    }

    luaL_error(L, "method 'GLContextAttrs::redBits' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_GLContextAttrs_stencilBits$1(lua_State *L)
{
    olua_startinvoke(L);

    GLContextAttrs *self = nullptr;

    olua_to_object(L, 1, &self, "cc.GLContextAttrs");

    // int stencilBits
    int ret = self->stencilBits;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_GLContextAttrs_stencilBits$2(lua_State *L)
{
    olua_startinvoke(L);

    GLContextAttrs *self = nullptr;
    int arg1 = 0;       /** stencilBits */

    olua_to_object(L, 1, &self, "cc.GLContextAttrs");
    olua_check_integer(L, 2, &arg1);

    // int stencilBits
    self->stencilBits = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_GLContextAttrs_stencilBits(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // int stencilBits
        return _olua_fun_GLContextAttrs_stencilBits$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.GLContextAttrs")) && (olua_is_integer(L, 2))) {
            // int stencilBits
            return _olua_fun_GLContextAttrs_stencilBits$2(L);
        // }
    }

    luaL_error(L, "method 'GLContextAttrs::stencilBits' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_cc_GLContextAttrs(lua_State *L)
{
    oluacls_class<GLContextAttrs>(L, "cc.GLContextAttrs");
    oluacls_func(L, "__gc", _olua_fun_GLContextAttrs___gc);
    oluacls_prop(L, "redBits", _olua_fun_GLContextAttrs_redBits, _olua_fun_GLContextAttrs_redBits);
    oluacls_prop(L, "greenBits", _olua_fun_GLContextAttrs_greenBits, _olua_fun_GLContextAttrs_greenBits);
    oluacls_prop(L, "blueBits", _olua_fun_GLContextAttrs_blueBits, _olua_fun_GLContextAttrs_blueBits);
    oluacls_prop(L, "alphaBits", _olua_fun_GLContextAttrs_alphaBits, _olua_fun_GLContextAttrs_alphaBits);
    oluacls_prop(L, "depthBits", _olua_fun_GLContextAttrs_depthBits, _olua_fun_GLContextAttrs_depthBits);
    oluacls_prop(L, "stencilBits", _olua_fun_GLContextAttrs_stencilBits, _olua_fun_GLContextAttrs_stencilBits);
    oluacls_prop(L, "multisamplingCount", _olua_fun_GLContextAttrs_multisamplingCount, _olua_fun_GLContextAttrs_multisamplingCount);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cc_GLContextAttrs(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "cc.GLContextAttrs")) {
        luaL_error(L, "class not found: GLContextAttrs");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_Tex2F___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Tex2F *)olua_toobj(L, 1, "cc.Tex2F");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Tex2F_new$1(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** _u */
    float arg2 = 0;       /** _v */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // cocos2d::Tex2F(float _u, float _v)
    cocos2d::Tex2F *ret = new cocos2d::Tex2F(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.Tex2F");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Tex2F_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::Tex2F()
    cocos2d::Tex2F *ret = new cocos2d::Tex2F();
    int num_ret = olua_push_object(L, ret, "cc.Tex2F");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Tex2F_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // cocos2d::Tex2F()
        return _olua_fun_cocos2d_Tex2F_new$2(L);
    }

    if (num_args == 2) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2))) {
            // cocos2d::Tex2F(float _u, float _v)
            return _olua_fun_cocos2d_Tex2F_new$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Tex2F::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Tex2F_u$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Tex2F *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Tex2F");

    // float u
    float ret = self->u;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Tex2F_u$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Tex2F *self = nullptr;
    float arg1 = 0;       /** u */

    olua_to_object(L, 1, &self, "cc.Tex2F");
    olua_check_number(L, 2, &arg1);

    // float u
    self->u = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Tex2F_u(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float u
        return _olua_fun_cocos2d_Tex2F_u$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Tex2F")) && (olua_is_number(L, 2))) {
            // float u
            return _olua_fun_cocos2d_Tex2F_u$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Tex2F::u' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Tex2F_v$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Tex2F *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Tex2F");

    // float v
    float ret = self->v;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Tex2F_v$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Tex2F *self = nullptr;
    float arg1 = 0;       /** v */

    olua_to_object(L, 1, &self, "cc.Tex2F");
    olua_check_number(L, 2, &arg1);

    // float v
    self->v = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Tex2F_v(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float v
        return _olua_fun_cocos2d_Tex2F_v$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Tex2F")) && (olua_is_number(L, 2))) {
            // float v
            return _olua_fun_cocos2d_Tex2F_v$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Tex2F::v' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_cc_Tex2F(lua_State *L)
{
    oluacls_class<cocos2d::Tex2F>(L, "cc.Tex2F");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_Tex2F___gc);
    oluacls_func(L, "new", _olua_fun_cocos2d_Tex2F_new);
    oluacls_prop(L, "u", _olua_fun_cocos2d_Tex2F_u, _olua_fun_cocos2d_Tex2F_u);
    oluacls_prop(L, "v", _olua_fun_cocos2d_Tex2F_v, _olua_fun_cocos2d_Tex2F_v);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cc_Tex2F(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "cc.Tex2F")) {
        luaL_error(L, "class not found: cocos2d::Tex2F");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_T2F_Quad___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::T2F_Quad *)olua_toobj(L, 1, "cc.T2F_Quad");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_T2F_Quad_bl$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::T2F_Quad *self = nullptr;

    olua_to_object(L, 1, &self, "cc.T2F_Quad");

    // cocos2d::Tex2F bl
    cocos2d::Tex2F &ret = self->bl;
    int num_ret = olua_copy_object(L, ret, "cc.Tex2F");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_T2F_Quad_bl$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::T2F_Quad *self = nullptr;
    cocos2d::Tex2F *arg1;       /** bl */

    olua_to_object(L, 1, &self, "cc.T2F_Quad");
    olua_check_object(L, 2, &arg1, "cc.Tex2F");

    // cocos2d::Tex2F bl
    self->bl = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_T2F_Quad_bl(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::Tex2F bl
        return _olua_fun_cocos2d_T2F_Quad_bl$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.T2F_Quad")) && (olua_is_object(L, 2, "cc.Tex2F"))) {
            // cocos2d::Tex2F bl
            return _olua_fun_cocos2d_T2F_Quad_bl$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::T2F_Quad::bl' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_T2F_Quad_br$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::T2F_Quad *self = nullptr;

    olua_to_object(L, 1, &self, "cc.T2F_Quad");

    // cocos2d::Tex2F br
    cocos2d::Tex2F &ret = self->br;
    int num_ret = olua_copy_object(L, ret, "cc.Tex2F");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_T2F_Quad_br$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::T2F_Quad *self = nullptr;
    cocos2d::Tex2F *arg1;       /** br */

    olua_to_object(L, 1, &self, "cc.T2F_Quad");
    olua_check_object(L, 2, &arg1, "cc.Tex2F");

    // cocos2d::Tex2F br
    self->br = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_T2F_Quad_br(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::Tex2F br
        return _olua_fun_cocos2d_T2F_Quad_br$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.T2F_Quad")) && (olua_is_object(L, 2, "cc.Tex2F"))) {
            // cocos2d::Tex2F br
            return _olua_fun_cocos2d_T2F_Quad_br$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::T2F_Quad::br' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_T2F_Quad_tl$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::T2F_Quad *self = nullptr;

    olua_to_object(L, 1, &self, "cc.T2F_Quad");

    // cocos2d::Tex2F tl
    cocos2d::Tex2F &ret = self->tl;
    int num_ret = olua_copy_object(L, ret, "cc.Tex2F");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_T2F_Quad_tl$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::T2F_Quad *self = nullptr;
    cocos2d::Tex2F *arg1;       /** tl */

    olua_to_object(L, 1, &self, "cc.T2F_Quad");
    olua_check_object(L, 2, &arg1, "cc.Tex2F");

    // cocos2d::Tex2F tl
    self->tl = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_T2F_Quad_tl(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::Tex2F tl
        return _olua_fun_cocos2d_T2F_Quad_tl$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.T2F_Quad")) && (olua_is_object(L, 2, "cc.Tex2F"))) {
            // cocos2d::Tex2F tl
            return _olua_fun_cocos2d_T2F_Quad_tl$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::T2F_Quad::tl' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_T2F_Quad_tr$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::T2F_Quad *self = nullptr;

    olua_to_object(L, 1, &self, "cc.T2F_Quad");

    // cocos2d::Tex2F tr
    cocos2d::Tex2F &ret = self->tr;
    int num_ret = olua_copy_object(L, ret, "cc.Tex2F");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_T2F_Quad_tr$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::T2F_Quad *self = nullptr;
    cocos2d::Tex2F *arg1;       /** tr */

    olua_to_object(L, 1, &self, "cc.T2F_Quad");
    olua_check_object(L, 2, &arg1, "cc.Tex2F");

    // cocos2d::Tex2F tr
    self->tr = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_T2F_Quad_tr(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::Tex2F tr
        return _olua_fun_cocos2d_T2F_Quad_tr$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.T2F_Quad")) && (olua_is_object(L, 2, "cc.Tex2F"))) {
            // cocos2d::Tex2F tr
            return _olua_fun_cocos2d_T2F_Quad_tr$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::T2F_Quad::tr' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_cc_T2F_Quad(lua_State *L)
{
    oluacls_class<cocos2d::T2F_Quad>(L, "cc.T2F_Quad");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_T2F_Quad___gc);
    oluacls_prop(L, "bl", _olua_fun_cocos2d_T2F_Quad_bl, _olua_fun_cocos2d_T2F_Quad_bl);
    oluacls_prop(L, "br", _olua_fun_cocos2d_T2F_Quad_br, _olua_fun_cocos2d_T2F_Quad_br);
    oluacls_prop(L, "tl", _olua_fun_cocos2d_T2F_Quad_tl, _olua_fun_cocos2d_T2F_Quad_tl);
    oluacls_prop(L, "tr", _olua_fun_cocos2d_T2F_Quad_tr, _olua_fun_cocos2d_T2F_Quad_tr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cc_T2F_Quad(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "cc.T2F_Quad")) {
        luaL_error(L, "class not found: cocos2d::T2F_Quad");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ccBezierConfig___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ccBezierConfig *)olua_toobj(L, 1, "cc.ccBezierConfig");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ccBezierConfig_controlPoint_1$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ccBezierConfig *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ccBezierConfig");

    // cocos2d::Vec2 controlPoint_1
    cocos2d::Vec2 &ret = self->controlPoint_1;
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ccBezierConfig_controlPoint_1$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ccBezierConfig *self = nullptr;
    cocos2d::Vec2 *arg1;       /** controlPoint_1 */

    olua_to_object(L, 1, &self, "cc.ccBezierConfig");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // cocos2d::Vec2 controlPoint_1
    self->controlPoint_1 = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ccBezierConfig_controlPoint_1(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::Vec2 controlPoint_1
        return _olua_fun_cocos2d_ccBezierConfig_controlPoint_1$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.ccBezierConfig")) && (olua_is_object(L, 2, "cc.Vec2"))) {
            // cocos2d::Vec2 controlPoint_1
            return _olua_fun_cocos2d_ccBezierConfig_controlPoint_1$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ccBezierConfig::controlPoint_1' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ccBezierConfig_controlPoint_2$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ccBezierConfig *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ccBezierConfig");

    // cocos2d::Vec2 controlPoint_2
    cocos2d::Vec2 &ret = self->controlPoint_2;
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ccBezierConfig_controlPoint_2$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ccBezierConfig *self = nullptr;
    cocos2d::Vec2 *arg1;       /** controlPoint_2 */

    olua_to_object(L, 1, &self, "cc.ccBezierConfig");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // cocos2d::Vec2 controlPoint_2
    self->controlPoint_2 = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ccBezierConfig_controlPoint_2(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::Vec2 controlPoint_2
        return _olua_fun_cocos2d_ccBezierConfig_controlPoint_2$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.ccBezierConfig")) && (olua_is_object(L, 2, "cc.Vec2"))) {
            // cocos2d::Vec2 controlPoint_2
            return _olua_fun_cocos2d_ccBezierConfig_controlPoint_2$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ccBezierConfig::controlPoint_2' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ccBezierConfig_endPosition$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ccBezierConfig *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ccBezierConfig");

    // cocos2d::Vec2 endPosition
    cocos2d::Vec2 &ret = self->endPosition;
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ccBezierConfig_endPosition$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ccBezierConfig *self = nullptr;
    cocos2d::Vec2 *arg1;       /** endPosition */

    olua_to_object(L, 1, &self, "cc.ccBezierConfig");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // cocos2d::Vec2 endPosition
    self->endPosition = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ccBezierConfig_endPosition(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::Vec2 endPosition
        return _olua_fun_cocos2d_ccBezierConfig_endPosition$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.ccBezierConfig")) && (olua_is_object(L, 2, "cc.Vec2"))) {
            // cocos2d::Vec2 endPosition
            return _olua_fun_cocos2d_ccBezierConfig_endPosition$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ccBezierConfig::endPosition' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_cc_ccBezierConfig(lua_State *L)
{
    oluacls_class<cocos2d::ccBezierConfig>(L, "cc.ccBezierConfig");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_ccBezierConfig___gc);
    oluacls_prop(L, "endPosition", _olua_fun_cocos2d_ccBezierConfig_endPosition, _olua_fun_cocos2d_ccBezierConfig_endPosition);
    oluacls_prop(L, "controlPoint_1", _olua_fun_cocos2d_ccBezierConfig_controlPoint_1, _olua_fun_cocos2d_ccBezierConfig_controlPoint_1);
    oluacls_prop(L, "controlPoint_2", _olua_fun_cocos2d_ccBezierConfig_controlPoint_2, _olua_fun_cocos2d_ccBezierConfig_controlPoint_2);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cc_ccBezierConfig(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "cc.ccBezierConfig")) {
        luaL_error(L, "class not found: cocos2d::ccBezierConfig");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_TTFConfig___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::TTFConfig *)olua_toobj(L, 1, "cc.TTFConfig");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_TTFConfig_bold$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TTFConfig *self = nullptr;

    olua_to_object(L, 1, &self, "cc.TTFConfig");

    // bool bold
    bool ret = self->bold;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_TTFConfig_bold$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TTFConfig *self = nullptr;
    bool arg1 = false;       /** bold */

    olua_to_object(L, 1, &self, "cc.TTFConfig");
    olua_check_bool(L, 2, &arg1);

    // bool bold
    self->bold = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_TTFConfig_bold(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool bold
        return _olua_fun_cocos2d_TTFConfig_bold$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.TTFConfig")) && (olua_is_bool(L, 2))) {
            // bool bold
            return _olua_fun_cocos2d_TTFConfig_bold$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::TTFConfig::bold' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_TTFConfig_customGlyphs$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TTFConfig *self = nullptr;

    olua_to_object(L, 1, &self, "cc.TTFConfig");

    // const char *customGlyphs
    const char *ret = self->customGlyphs;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_TTFConfig_customGlyphs$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TTFConfig *self = nullptr;
    const char *arg1 = nullptr;       /** customGlyphs */

    olua_to_object(L, 1, &self, "cc.TTFConfig");
    olua_check_string(L, 2, &arg1);

    // const char *customGlyphs
    self->customGlyphs = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_TTFConfig_customGlyphs(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // const char *customGlyphs
        return _olua_fun_cocos2d_TTFConfig_customGlyphs$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.TTFConfig")) && (olua_is_string(L, 2))) {
            // const char *customGlyphs
            return _olua_fun_cocos2d_TTFConfig_customGlyphs$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::TTFConfig::customGlyphs' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_TTFConfig_distanceFieldEnabled$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TTFConfig *self = nullptr;

    olua_to_object(L, 1, &self, "cc.TTFConfig");

    // bool distanceFieldEnabled
    bool ret = self->distanceFieldEnabled;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_TTFConfig_distanceFieldEnabled$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TTFConfig *self = nullptr;
    bool arg1 = false;       /** distanceFieldEnabled */

    olua_to_object(L, 1, &self, "cc.TTFConfig");
    olua_check_bool(L, 2, &arg1);

    // bool distanceFieldEnabled
    self->distanceFieldEnabled = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_TTFConfig_distanceFieldEnabled(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool distanceFieldEnabled
        return _olua_fun_cocos2d_TTFConfig_distanceFieldEnabled$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.TTFConfig")) && (olua_is_bool(L, 2))) {
            // bool distanceFieldEnabled
            return _olua_fun_cocos2d_TTFConfig_distanceFieldEnabled$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::TTFConfig::distanceFieldEnabled' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_TTFConfig_fontFilePath$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TTFConfig *self = nullptr;

    olua_to_object(L, 1, &self, "cc.TTFConfig");

    // std::string fontFilePath
    std::string ret = self->fontFilePath;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_TTFConfig_fontFilePath$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TTFConfig *self = nullptr;
    std::string arg1;       /** fontFilePath */

    olua_to_object(L, 1, &self, "cc.TTFConfig");
    olua_check_string(L, 2, &arg1);

    // std::string fontFilePath
    self->fontFilePath = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_TTFConfig_fontFilePath(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::string fontFilePath
        return _olua_fun_cocos2d_TTFConfig_fontFilePath$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.TTFConfig")) && (olua_is_string(L, 2))) {
            // std::string fontFilePath
            return _olua_fun_cocos2d_TTFConfig_fontFilePath$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::TTFConfig::fontFilePath' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_TTFConfig_fontSize$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TTFConfig *self = nullptr;

    olua_to_object(L, 1, &self, "cc.TTFConfig");

    // float fontSize
    float ret = self->fontSize;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_TTFConfig_fontSize$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TTFConfig *self = nullptr;
    float arg1 = 0;       /** fontSize */

    olua_to_object(L, 1, &self, "cc.TTFConfig");
    olua_check_number(L, 2, &arg1);

    // float fontSize
    self->fontSize = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_TTFConfig_fontSize(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float fontSize
        return _olua_fun_cocos2d_TTFConfig_fontSize$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.TTFConfig")) && (olua_is_number(L, 2))) {
            // float fontSize
            return _olua_fun_cocos2d_TTFConfig_fontSize$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::TTFConfig::fontSize' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_TTFConfig_glyphs$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TTFConfig *self = nullptr;

    olua_to_object(L, 1, &self, "cc.TTFConfig");

    // cocos2d::GlyphCollection glyphs
    cocos2d::GlyphCollection ret = self->glyphs;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_TTFConfig_glyphs$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TTFConfig *self = nullptr;
    cocos2d::GlyphCollection arg1 = (cocos2d::GlyphCollection)0;       /** glyphs */

    olua_to_object(L, 1, &self, "cc.TTFConfig");
    olua_check_enum(L, 2, &arg1);

    // cocos2d::GlyphCollection glyphs
    self->glyphs = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_TTFConfig_glyphs(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::GlyphCollection glyphs
        return _olua_fun_cocos2d_TTFConfig_glyphs$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.TTFConfig")) && (olua_is_enum(L, 2))) {
            // cocos2d::GlyphCollection glyphs
            return _olua_fun_cocos2d_TTFConfig_glyphs$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::TTFConfig::glyphs' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_TTFConfig_italics$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TTFConfig *self = nullptr;

    olua_to_object(L, 1, &self, "cc.TTFConfig");

    // bool italics
    bool ret = self->italics;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_TTFConfig_italics$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TTFConfig *self = nullptr;
    bool arg1 = false;       /** italics */

    olua_to_object(L, 1, &self, "cc.TTFConfig");
    olua_check_bool(L, 2, &arg1);

    // bool italics
    self->italics = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_TTFConfig_italics(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool italics
        return _olua_fun_cocos2d_TTFConfig_italics$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.TTFConfig")) && (olua_is_bool(L, 2))) {
            // bool italics
            return _olua_fun_cocos2d_TTFConfig_italics$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::TTFConfig::italics' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_TTFConfig_outlineSize$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TTFConfig *self = nullptr;

    olua_to_object(L, 1, &self, "cc.TTFConfig");

    // int outlineSize
    int ret = self->outlineSize;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_TTFConfig_outlineSize$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TTFConfig *self = nullptr;
    int arg1 = 0;       /** outlineSize */

    olua_to_object(L, 1, &self, "cc.TTFConfig");
    olua_check_integer(L, 2, &arg1);

    // int outlineSize
    self->outlineSize = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_TTFConfig_outlineSize(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // int outlineSize
        return _olua_fun_cocos2d_TTFConfig_outlineSize$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.TTFConfig")) && (olua_is_integer(L, 2))) {
            // int outlineSize
            return _olua_fun_cocos2d_TTFConfig_outlineSize$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::TTFConfig::outlineSize' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_TTFConfig_strikethrough$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TTFConfig *self = nullptr;

    olua_to_object(L, 1, &self, "cc.TTFConfig");

    // bool strikethrough
    bool ret = self->strikethrough;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_TTFConfig_strikethrough$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TTFConfig *self = nullptr;
    bool arg1 = false;       /** strikethrough */

    olua_to_object(L, 1, &self, "cc.TTFConfig");
    olua_check_bool(L, 2, &arg1);

    // bool strikethrough
    self->strikethrough = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_TTFConfig_strikethrough(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool strikethrough
        return _olua_fun_cocos2d_TTFConfig_strikethrough$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.TTFConfig")) && (olua_is_bool(L, 2))) {
            // bool strikethrough
            return _olua_fun_cocos2d_TTFConfig_strikethrough$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::TTFConfig::strikethrough' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_TTFConfig_underline$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TTFConfig *self = nullptr;

    olua_to_object(L, 1, &self, "cc.TTFConfig");

    // bool underline
    bool ret = self->underline;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_TTFConfig_underline$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TTFConfig *self = nullptr;
    bool arg1 = false;       /** underline */

    olua_to_object(L, 1, &self, "cc.TTFConfig");
    olua_check_bool(L, 2, &arg1);

    // bool underline
    self->underline = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_TTFConfig_underline(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool underline
        return _olua_fun_cocos2d_TTFConfig_underline$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.TTFConfig")) && (olua_is_bool(L, 2))) {
            // bool underline
            return _olua_fun_cocos2d_TTFConfig_underline$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::TTFConfig::underline' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_cc_TTFConfig(lua_State *L)
{
    oluacls_class<cocos2d::TTFConfig>(L, "cc.TTFConfig");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_TTFConfig___gc);
    oluacls_prop(L, "fontFilePath", _olua_fun_cocos2d_TTFConfig_fontFilePath, _olua_fun_cocos2d_TTFConfig_fontFilePath);
    oluacls_prop(L, "fontSize", _olua_fun_cocos2d_TTFConfig_fontSize, _olua_fun_cocos2d_TTFConfig_fontSize);
    oluacls_prop(L, "glyphs", _olua_fun_cocos2d_TTFConfig_glyphs, _olua_fun_cocos2d_TTFConfig_glyphs);
    oluacls_prop(L, "customGlyphs", _olua_fun_cocos2d_TTFConfig_customGlyphs, _olua_fun_cocos2d_TTFConfig_customGlyphs);
    oluacls_prop(L, "distanceFieldEnabled", _olua_fun_cocos2d_TTFConfig_distanceFieldEnabled, _olua_fun_cocos2d_TTFConfig_distanceFieldEnabled);
    oluacls_prop(L, "outlineSize", _olua_fun_cocos2d_TTFConfig_outlineSize, _olua_fun_cocos2d_TTFConfig_outlineSize);
    oluacls_prop(L, "italics", _olua_fun_cocos2d_TTFConfig_italics, _olua_fun_cocos2d_TTFConfig_italics);
    oluacls_prop(L, "bold", _olua_fun_cocos2d_TTFConfig_bold, _olua_fun_cocos2d_TTFConfig_bold);
    oluacls_prop(L, "underline", _olua_fun_cocos2d_TTFConfig_underline, _olua_fun_cocos2d_TTFConfig_underline);
    oluacls_prop(L, "strikethrough", _olua_fun_cocos2d_TTFConfig_strikethrough, _olua_fun_cocos2d_TTFConfig_strikethrough);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cc_TTFConfig(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "cc.TTFConfig")) {
        luaL_error(L, "class not found: cocos2d::TTFConfig");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_BlendFunc___eq(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::BlendFunc *self = nullptr;
    cocos2d::BlendFunc *arg1;       /** a */

    olua_to_object(L, 1, &self, "cc.BlendFunc");
    olua_check_object(L, 2, &arg1, "cc.BlendFunc");

    // @operator(operator==) bool operator==(const cocos2d::BlendFunc &a)
    bool ret = (*self) == (*arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_BlendFunc___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::BlendFunc *)olua_toobj(L, 1, "cc.BlendFunc");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_BlendFunc___lt(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::BlendFunc *self = nullptr;
    cocos2d::BlendFunc *arg1;       /** a */

    olua_to_object(L, 1, &self, "cc.BlendFunc");
    olua_check_object(L, 2, &arg1, "cc.BlendFunc");

    // @operator(operator<) bool operator<(const cocos2d::BlendFunc &a)
    bool ret = (*self) < (*arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_BlendFunc_dst$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::BlendFunc *self = nullptr;

    olua_to_object(L, 1, &self, "cc.BlendFunc");

    // cocos2d::backend::BlendFactor dst
    cocos2d::backend::BlendFactor ret = self->dst;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_BlendFunc_dst$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::BlendFunc *self = nullptr;
    cocos2d::backend::BlendFactor arg1 = (cocos2d::backend::BlendFactor)0;       /** dst */

    olua_to_object(L, 1, &self, "cc.BlendFunc");
    olua_check_enum(L, 2, &arg1);

    // cocos2d::backend::BlendFactor dst
    self->dst = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_BlendFunc_dst(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::backend::BlendFactor dst
        return _olua_fun_cocos2d_BlendFunc_dst$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.BlendFunc")) && (olua_is_enum(L, 2))) {
            // cocos2d::backend::BlendFactor dst
            return _olua_fun_cocos2d_BlendFunc_dst$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::BlendFunc::dst' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_BlendFunc_src$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::BlendFunc *self = nullptr;

    olua_to_object(L, 1, &self, "cc.BlendFunc");

    // cocos2d::backend::BlendFactor src
    cocos2d::backend::BlendFactor ret = self->src;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_BlendFunc_src$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::BlendFunc *self = nullptr;
    cocos2d::backend::BlendFactor arg1 = (cocos2d::backend::BlendFactor)0;       /** src */

    olua_to_object(L, 1, &self, "cc.BlendFunc");
    olua_check_enum(L, 2, &arg1);

    // cocos2d::backend::BlendFactor src
    self->src = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_BlendFunc_src(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::backend::BlendFactor src
        return _olua_fun_cocos2d_BlendFunc_src$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.BlendFunc")) && (olua_is_enum(L, 2))) {
            // cocos2d::backend::BlendFactor src
            return _olua_fun_cocos2d_BlendFunc_src$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::BlendFunc::src' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_cc_BlendFunc(lua_State *L)
{
    oluacls_class<cocos2d::BlendFunc>(L, "cc.BlendFunc");
    oluacls_func(L, "__eq", _olua_fun_cocos2d_BlendFunc___eq);
    oluacls_func(L, "__gc", _olua_fun_cocos2d_BlendFunc___gc);
    oluacls_func(L, "__lt", _olua_fun_cocos2d_BlendFunc___lt);
    oluacls_prop(L, "src", _olua_fun_cocos2d_BlendFunc_src, _olua_fun_cocos2d_BlendFunc_src);
    oluacls_prop(L, "dst", _olua_fun_cocos2d_BlendFunc_dst, _olua_fun_cocos2d_BlendFunc_dst);
    oluacls_const(L, "ADDITIVE", &cocos2d::BlendFunc::ADDITIVE);
    oluacls_const(L, "ALPHA_NON_PREMULTIPLIED", &cocos2d::BlendFunc::ALPHA_NON_PREMULTIPLIED);
    oluacls_const(L, "ALPHA_PREMULTIPLIED", &cocos2d::BlendFunc::ALPHA_PREMULTIPLIED);
    oluacls_const(L, "DISABLE", &cocos2d::BlendFunc::DISABLE);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cc_BlendFunc(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "cc.BlendFunc")) {
        luaL_error(L, "class not found: cocos2d::BlendFunc");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ui_Margin___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ui::Margin *)olua_toobj(L, 1, "cc.ui.Margin");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Margin_bottom$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Margin *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ui.Margin");

    // float bottom
    float ret = self->bottom;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Margin_bottom$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Margin *self = nullptr;
    float arg1 = 0;       /** bottom */

    olua_to_object(L, 1, &self, "cc.ui.Margin");
    olua_check_number(L, 2, &arg1);

    // float bottom
    self->bottom = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Margin_bottom(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float bottom
        return _olua_fun_cocos2d_ui_Margin_bottom$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.ui.Margin")) && (olua_is_number(L, 2))) {
            // float bottom
            return _olua_fun_cocos2d_ui_Margin_bottom$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Margin::bottom' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Margin_equals(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Margin *self = nullptr;
    cocos2d::ui::Margin *arg1;       /** target */

    olua_to_object(L, 1, &self, "cc.ui.Margin");
    olua_check_object(L, 2, &arg1, "cc.ui.Margin");

    // bool equals(const cocos2d::ui::Margin &target)
    bool ret = self->equals(*arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Margin_left$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Margin *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ui.Margin");

    // float left
    float ret = self->left;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Margin_left$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Margin *self = nullptr;
    float arg1 = 0;       /** left */

    olua_to_object(L, 1, &self, "cc.ui.Margin");
    olua_check_number(L, 2, &arg1);

    // float left
    self->left = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Margin_left(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float left
        return _olua_fun_cocos2d_ui_Margin_left$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.ui.Margin")) && (olua_is_number(L, 2))) {
            // float left
            return _olua_fun_cocos2d_ui_Margin_left$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Margin::left' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Margin_new$1(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ui::Margin()
    cocos2d::ui::Margin *ret = new cocos2d::ui::Margin();
    int num_ret = olua_push_object(L, ret, "cc.ui.Margin");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Margin_new$2(lua_State *L)
{
    olua_startinvoke(L);

    float arg1 = 0;       /** l */
    float arg2 = 0;       /** t */
    float arg3 = 0;       /** r */
    float arg4 = 0;       /** b */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // cocos2d::ui::Margin(float l, float t, float r, float b)
    cocos2d::ui::Margin *ret = new cocos2d::ui::Margin(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "cc.ui.Margin");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Margin_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // cocos2d::ui::Margin()
        return _olua_fun_cocos2d_ui_Margin_new$1(L);
    }

    if (num_args == 4) {
        // if ((olua_is_number(L, 1)) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_number(L, 4))) {
            // cocos2d::ui::Margin(float l, float t, float r, float b)
            return _olua_fun_cocos2d_ui_Margin_new$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Margin::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Margin_right$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Margin *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ui.Margin");

    // float right
    float ret = self->right;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Margin_right$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Margin *self = nullptr;
    float arg1 = 0;       /** right */

    olua_to_object(L, 1, &self, "cc.ui.Margin");
    olua_check_number(L, 2, &arg1);

    // float right
    self->right = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Margin_right(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float right
        return _olua_fun_cocos2d_ui_Margin_right$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.ui.Margin")) && (olua_is_number(L, 2))) {
            // float right
            return _olua_fun_cocos2d_ui_Margin_right$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Margin::right' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ui_Margin_setMargin(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Margin *self = nullptr;
    float arg1 = 0;       /** l */
    float arg2 = 0;       /** t */
    float arg3 = 0;       /** r */
    float arg4 = 0;       /** b */

    olua_to_object(L, 1, &self, "cc.ui.Margin");
    olua_check_number(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);
    olua_check_number(L, 4, &arg3);
    olua_check_number(L, 5, &arg4);

    // void setMargin(float l, float t, float r, float b)
    self->setMargin(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Margin_top$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Margin *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ui.Margin");

    // float top
    float ret = self->top;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ui_Margin_top$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ui::Margin *self = nullptr;
    float arg1 = 0;       /** top */

    olua_to_object(L, 1, &self, "cc.ui.Margin");
    olua_check_number(L, 2, &arg1);

    // float top
    self->top = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ui_Margin_top(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float top
        return _olua_fun_cocos2d_ui_Margin_top$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.ui.Margin")) && (olua_is_number(L, 2))) {
            // float top
            return _olua_fun_cocos2d_ui_Margin_top$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ui::Margin::top' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_cc_ui_Margin(lua_State *L)
{
    oluacls_class<cocos2d::ui::Margin>(L, "cc.ui.Margin");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_ui_Margin___gc);
    oluacls_func(L, "equals", _olua_fun_cocos2d_ui_Margin_equals);
    oluacls_func(L, "new", _olua_fun_cocos2d_ui_Margin_new);
    oluacls_func(L, "setMargin", _olua_fun_cocos2d_ui_Margin_setMargin);
    oluacls_prop(L, "left", _olua_fun_cocos2d_ui_Margin_left, _olua_fun_cocos2d_ui_Margin_left);
    oluacls_prop(L, "top", _olua_fun_cocos2d_ui_Margin_top, _olua_fun_cocos2d_ui_Margin_top);
    oluacls_prop(L, "right", _olua_fun_cocos2d_ui_Margin_right, _olua_fun_cocos2d_ui_Margin_right);
    oluacls_prop(L, "bottom", _olua_fun_cocos2d_ui_Margin_bottom, _olua_fun_cocos2d_ui_Margin_bottom);
    oluacls_const(L, "ZERO", &cocos2d::ui::Margin::ZERO);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cc_ui_Margin(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "cc.ui.Margin")) {
        luaL_error(L, "class not found: cocos2d::ui::Margin");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_ResourceData___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::ResourceData *)olua_toobj(L, 1, "cc.ResourceData");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ResourceData_file$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ResourceData *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ResourceData");

    // std::string file
    std::string ret = self->file;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ResourceData_file$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ResourceData *self = nullptr;
    std::string arg1;       /** file */

    olua_to_object(L, 1, &self, "cc.ResourceData");
    olua_check_string(L, 2, &arg1);

    // std::string file
    self->file = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ResourceData_file(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::string file
        return _olua_fun_cocos2d_ResourceData_file$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.ResourceData")) && (olua_is_string(L, 2))) {
            // std::string file
            return _olua_fun_cocos2d_ResourceData_file$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ResourceData::file' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ResourceData_new$1(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::ResourceData()
    cocos2d::ResourceData *ret = new cocos2d::ResourceData();
    int num_ret = olua_push_object(L, ret, "cc.ResourceData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ResourceData_new$2(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** iType */
    std::string arg2;       /** sFile */
    std::string arg3;       /** sPlist */

    olua_check_integer(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_string(L, 3, &arg3);

    // cocos2d::ResourceData(int iType, std::string sFile, std::string sPlist)
    cocos2d::ResourceData *ret = new cocos2d::ResourceData(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.ResourceData");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ResourceData_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // cocos2d::ResourceData()
        return _olua_fun_cocos2d_ResourceData_new$1(L);
    }

    if (num_args == 3) {
        // if ((olua_is_integer(L, 1)) && (olua_is_string(L, 2)) && (olua_is_string(L, 3))) {
            // cocos2d::ResourceData(int iType, std::string sFile, std::string sPlist)
            return _olua_fun_cocos2d_ResourceData_new$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ResourceData::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ResourceData_plist$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ResourceData *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ResourceData");

    // std::string plist
    std::string ret = self->plist;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ResourceData_plist$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ResourceData *self = nullptr;
    std::string arg1;       /** plist */

    olua_to_object(L, 1, &self, "cc.ResourceData");
    olua_check_string(L, 2, &arg1);

    // std::string plist
    self->plist = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ResourceData_plist(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::string plist
        return _olua_fun_cocos2d_ResourceData_plist$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.ResourceData")) && (olua_is_string(L, 2))) {
            // std::string plist
            return _olua_fun_cocos2d_ResourceData_plist$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ResourceData::plist' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_ResourceData_type$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ResourceData *self = nullptr;

    olua_to_object(L, 1, &self, "cc.ResourceData");

    // int type
    int ret = self->type;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_ResourceData_type$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ResourceData *self = nullptr;
    int arg1 = 0;       /** type */

    olua_to_object(L, 1, &self, "cc.ResourceData");
    olua_check_integer(L, 2, &arg1);

    // int type
    self->type = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_ResourceData_type(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // int type
        return _olua_fun_cocos2d_ResourceData_type$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.ResourceData")) && (olua_is_integer(L, 2))) {
            // int type
            return _olua_fun_cocos2d_ResourceData_type$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::ResourceData::type' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_cc_ResourceData(lua_State *L)
{
    oluacls_class<cocos2d::ResourceData>(L, "cc.ResourceData");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_ResourceData___gc);
    oluacls_func(L, "new", _olua_fun_cocos2d_ResourceData_new);
    oluacls_prop(L, "type", _olua_fun_cocos2d_ResourceData_type, _olua_fun_cocos2d_ResourceData_type);
    oluacls_prop(L, "file", _olua_fun_cocos2d_ResourceData_file, _olua_fun_cocos2d_ResourceData_file);
    oluacls_prop(L, "plist", _olua_fun_cocos2d_ResourceData_plist, _olua_fun_cocos2d_ResourceData_plist);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cc_ResourceData(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "cc.ResourceData")) {
        luaL_error(L, "class not found: cocos2d::ResourceData");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_Quad3___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Quad3 *)olua_toobj(L, 1, "cc.Quad3");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Quad3_bl$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quad3 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Quad3");

    // cocos2d::Vec3 bl
    cocos2d::Vec3 &ret = self->bl;
    int num_ret = olua_copy_object(L, ret, "cc.Vec3");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Quad3_bl$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quad3 *self = nullptr;
    cocos2d::Vec3 *arg1;       /** bl */

    olua_to_object(L, 1, &self, "cc.Quad3");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // cocos2d::Vec3 bl
    self->bl = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Quad3_bl(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::Vec3 bl
        return _olua_fun_cocos2d_Quad3_bl$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Quad3")) && (olua_is_object(L, 2, "cc.Vec3"))) {
            // cocos2d::Vec3 bl
            return _olua_fun_cocos2d_Quad3_bl$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Quad3::bl' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Quad3_br$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quad3 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Quad3");

    // cocos2d::Vec3 br
    cocos2d::Vec3 &ret = self->br;
    int num_ret = olua_copy_object(L, ret, "cc.Vec3");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Quad3_br$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quad3 *self = nullptr;
    cocos2d::Vec3 *arg1;       /** br */

    olua_to_object(L, 1, &self, "cc.Quad3");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // cocos2d::Vec3 br
    self->br = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Quad3_br(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::Vec3 br
        return _olua_fun_cocos2d_Quad3_br$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Quad3")) && (olua_is_object(L, 2, "cc.Vec3"))) {
            // cocos2d::Vec3 br
            return _olua_fun_cocos2d_Quad3_br$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Quad3::br' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Quad3_tl$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quad3 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Quad3");

    // cocos2d::Vec3 tl
    cocos2d::Vec3 &ret = self->tl;
    int num_ret = olua_copy_object(L, ret, "cc.Vec3");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Quad3_tl$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quad3 *self = nullptr;
    cocos2d::Vec3 *arg1;       /** tl */

    olua_to_object(L, 1, &self, "cc.Quad3");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // cocos2d::Vec3 tl
    self->tl = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Quad3_tl(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::Vec3 tl
        return _olua_fun_cocos2d_Quad3_tl$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Quad3")) && (olua_is_object(L, 2, "cc.Vec3"))) {
            // cocos2d::Vec3 tl
            return _olua_fun_cocos2d_Quad3_tl$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Quad3::tl' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Quad3_tr$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quad3 *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Quad3");

    // cocos2d::Vec3 tr
    cocos2d::Vec3 &ret = self->tr;
    int num_ret = olua_copy_object(L, ret, "cc.Vec3");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Quad3_tr$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Quad3 *self = nullptr;
    cocos2d::Vec3 *arg1;       /** tr */

    olua_to_object(L, 1, &self, "cc.Quad3");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // cocos2d::Vec3 tr
    self->tr = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Quad3_tr(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::Vec3 tr
        return _olua_fun_cocos2d_Quad3_tr$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Quad3")) && (olua_is_object(L, 2, "cc.Vec3"))) {
            // cocos2d::Vec3 tr
            return _olua_fun_cocos2d_Quad3_tr$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Quad3::tr' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_cc_Quad3(lua_State *L)
{
    oluacls_class<cocos2d::Quad3>(L, "cc.Quad3");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_Quad3___gc);
    oluacls_prop(L, "bl", _olua_fun_cocos2d_Quad3_bl, _olua_fun_cocos2d_Quad3_bl);
    oluacls_prop(L, "br", _olua_fun_cocos2d_Quad3_br, _olua_fun_cocos2d_Quad3_br);
    oluacls_prop(L, "tl", _olua_fun_cocos2d_Quad3_tl, _olua_fun_cocos2d_Quad3_tl);
    oluacls_prop(L, "tr", _olua_fun_cocos2d_Quad3_tr, _olua_fun_cocos2d_Quad3_tr);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cc_Quad3(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "cc.Quad3")) {
        luaL_error(L, "class not found: cocos2d::Quad3");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_Texture2D_PixelFormatInfo___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Texture2D::PixelFormatInfo *)olua_toobj(L, 1, "cc.Texture2D.PixelFormatInfo");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Texture2D_PixelFormatInfo_alpha$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Texture2D::PixelFormatInfo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Texture2D.PixelFormatInfo");

    // bool alpha
    bool ret = self->alpha;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Texture2D_PixelFormatInfo_alpha$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Texture2D::PixelFormatInfo *self = nullptr;
    bool arg1 = false;       /** alpha */

    olua_to_object(L, 1, &self, "cc.Texture2D.PixelFormatInfo");
    olua_check_bool(L, 2, &arg1);

    // bool alpha
    self->alpha = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Texture2D_PixelFormatInfo_alpha(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool alpha
        return _olua_fun_cocos2d_Texture2D_PixelFormatInfo_alpha$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Texture2D.PixelFormatInfo")) && (olua_is_bool(L, 2))) {
            // bool alpha
            return _olua_fun_cocos2d_Texture2D_PixelFormatInfo_alpha$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Texture2D::PixelFormatInfo::alpha' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Texture2D_PixelFormatInfo_bpp$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Texture2D::PixelFormatInfo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Texture2D.PixelFormatInfo");

    // int bpp
    int ret = self->bpp;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Texture2D_PixelFormatInfo_bpp$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Texture2D::PixelFormatInfo *self = nullptr;
    int arg1 = 0;       /** bpp */

    olua_to_object(L, 1, &self, "cc.Texture2D.PixelFormatInfo");
    olua_check_integer(L, 2, &arg1);

    // int bpp
    self->bpp = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Texture2D_PixelFormatInfo_bpp(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // int bpp
        return _olua_fun_cocos2d_Texture2D_PixelFormatInfo_bpp$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Texture2D.PixelFormatInfo")) && (olua_is_integer(L, 2))) {
            // int bpp
            return _olua_fun_cocos2d_Texture2D_PixelFormatInfo_bpp$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Texture2D::PixelFormatInfo::bpp' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Texture2D_PixelFormatInfo_compressed$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Texture2D::PixelFormatInfo *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Texture2D.PixelFormatInfo");

    // bool compressed
    bool ret = self->compressed;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Texture2D_PixelFormatInfo_compressed$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Texture2D::PixelFormatInfo *self = nullptr;
    bool arg1 = false;       /** compressed */

    olua_to_object(L, 1, &self, "cc.Texture2D.PixelFormatInfo");
    olua_check_bool(L, 2, &arg1);

    // bool compressed
    self->compressed = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Texture2D_PixelFormatInfo_compressed(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool compressed
        return _olua_fun_cocos2d_Texture2D_PixelFormatInfo_compressed$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Texture2D.PixelFormatInfo")) && (olua_is_bool(L, 2))) {
            // bool compressed
            return _olua_fun_cocos2d_Texture2D_PixelFormatInfo_compressed$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Texture2D::PixelFormatInfo::compressed' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Texture2D_PixelFormatInfo_new(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** aBpp */
    bool arg2 = false;       /** aCompressed */
    bool arg3 = false;       /** anAlpha */

    olua_check_integer(L, 1, &arg1);
    olua_check_bool(L, 2, &arg2);
    olua_check_bool(L, 3, &arg3);

    // cocos2d::Texture2D::PixelFormatInfo(int aBpp, bool aCompressed, bool anAlpha)
    cocos2d::Texture2D::PixelFormatInfo *ret = new cocos2d::Texture2D::PixelFormatInfo(arg1, arg2, arg3);
    int num_ret = olua_push_object(L, ret, "cc.Texture2D.PixelFormatInfo");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_cls_cc_Texture2D_PixelFormatInfo(lua_State *L)
{
    oluacls_class<cocos2d::Texture2D::PixelFormatInfo>(L, "cc.Texture2D.PixelFormatInfo");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_Texture2D_PixelFormatInfo___gc);
    oluacls_func(L, "new", _olua_fun_cocos2d_Texture2D_PixelFormatInfo_new);
    oluacls_prop(L, "bpp", _olua_fun_cocos2d_Texture2D_PixelFormatInfo_bpp, _olua_fun_cocos2d_Texture2D_PixelFormatInfo_bpp);
    oluacls_prop(L, "compressed", _olua_fun_cocos2d_Texture2D_PixelFormatInfo_compressed, _olua_fun_cocos2d_Texture2D_PixelFormatInfo_compressed);
    oluacls_prop(L, "alpha", _olua_fun_cocos2d_Texture2D_PixelFormatInfo_alpha, _olua_fun_cocos2d_Texture2D_PixelFormatInfo_alpha);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cc_Texture2D_PixelFormatInfo(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "cc.Texture2D.PixelFormatInfo")) {
        luaL_error(L, "class not found: cocos2d::Texture2D::PixelFormatInfo");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_Controller_KeyStatus___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::Controller::KeyStatus *)olua_toobj(L, 1, "cc.Controller.KeyStatus");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Controller_KeyStatus_isAnalog$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Controller::KeyStatus *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Controller.KeyStatus");

    // bool isAnalog
    bool ret = self->isAnalog;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Controller_KeyStatus_isAnalog$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Controller::KeyStatus *self = nullptr;
    bool arg1 = false;       /** isAnalog */

    olua_to_object(L, 1, &self, "cc.Controller.KeyStatus");
    olua_check_bool(L, 2, &arg1);

    // bool isAnalog
    self->isAnalog = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Controller_KeyStatus_isAnalog(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool isAnalog
        return _olua_fun_cocos2d_Controller_KeyStatus_isAnalog$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Controller.KeyStatus")) && (olua_is_bool(L, 2))) {
            // bool isAnalog
            return _olua_fun_cocos2d_Controller_KeyStatus_isAnalog$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Controller::KeyStatus::isAnalog' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Controller_KeyStatus_isPressed$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Controller::KeyStatus *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Controller.KeyStatus");

    // bool isPressed
    bool ret = self->isPressed;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Controller_KeyStatus_isPressed$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Controller::KeyStatus *self = nullptr;
    bool arg1 = false;       /** isPressed */

    olua_to_object(L, 1, &self, "cc.Controller.KeyStatus");
    olua_check_bool(L, 2, &arg1);

    // bool isPressed
    self->isPressed = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Controller_KeyStatus_isPressed(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool isPressed
        return _olua_fun_cocos2d_Controller_KeyStatus_isPressed$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Controller.KeyStatus")) && (olua_is_bool(L, 2))) {
            // bool isPressed
            return _olua_fun_cocos2d_Controller_KeyStatus_isPressed$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Controller::KeyStatus::isPressed' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_Controller_KeyStatus_value$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Controller::KeyStatus *self = nullptr;

    olua_to_object(L, 1, &self, "cc.Controller.KeyStatus");

    // float value
    float ret = self->value;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_Controller_KeyStatus_value$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Controller::KeyStatus *self = nullptr;
    float arg1 = 0;       /** value */

    olua_to_object(L, 1, &self, "cc.Controller.KeyStatus");
    olua_check_number(L, 2, &arg1);

    // float value
    self->value = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_Controller_KeyStatus_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float value
        return _olua_fun_cocos2d_Controller_KeyStatus_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Controller.KeyStatus")) && (olua_is_number(L, 2))) {
            // float value
            return _olua_fun_cocos2d_Controller_KeyStatus_value$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::Controller::KeyStatus::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_cc_Controller_KeyStatus(lua_State *L)
{
    oluacls_class<cocos2d::Controller::KeyStatus>(L, "cc.Controller.KeyStatus");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_Controller_KeyStatus___gc);
    oluacls_prop(L, "isPressed", _olua_fun_cocos2d_Controller_KeyStatus_isPressed, _olua_fun_cocos2d_Controller_KeyStatus_isPressed);
    oluacls_prop(L, "value", _olua_fun_cocos2d_Controller_KeyStatus_value, _olua_fun_cocos2d_Controller_KeyStatus_value);
    oluacls_prop(L, "isAnalog", _olua_fun_cocos2d_Controller_KeyStatus_isAnalog, _olua_fun_cocos2d_Controller_KeyStatus_isAnalog);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cc_Controller_KeyStatus(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "cc.Controller.KeyStatus")) {
        luaL_error(L, "class not found: cocos2d::Controller::KeyStatus");
    }
    return 1;
}
OLUA_END_DECLS

#if CC_USE_NAVMESH
static int _olua_fun_cocos2d_NavMeshAgentParam___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::NavMeshAgentParam *)olua_toobj(L, 1, "cc.NavMeshAgentParam");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_collisionQueryRange$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::NavMeshAgentParam *self = nullptr;

    olua_to_object(L, 1, &self, "cc.NavMeshAgentParam");

    // float collisionQueryRange
    float ret = self->collisionQueryRange;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_collisionQueryRange$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::NavMeshAgentParam *self = nullptr;
    float arg1 = 0;       /** collisionQueryRange */

    olua_to_object(L, 1, &self, "cc.NavMeshAgentParam");
    olua_check_number(L, 2, &arg1);

    // float collisionQueryRange
    self->collisionQueryRange = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_collisionQueryRange(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float collisionQueryRange
        return _olua_fun_cocos2d_NavMeshAgentParam_collisionQueryRange$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.NavMeshAgentParam")) && (olua_is_number(L, 2))) {
            // float collisionQueryRange
            return _olua_fun_cocos2d_NavMeshAgentParam_collisionQueryRange$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::NavMeshAgentParam::collisionQueryRange' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_height$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::NavMeshAgentParam *self = nullptr;

    olua_to_object(L, 1, &self, "cc.NavMeshAgentParam");

    // float height
    float ret = self->height;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_height$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::NavMeshAgentParam *self = nullptr;
    float arg1 = 0;       /** height */

    olua_to_object(L, 1, &self, "cc.NavMeshAgentParam");
    olua_check_number(L, 2, &arg1);

    // float height
    self->height = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_height(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float height
        return _olua_fun_cocos2d_NavMeshAgentParam_height$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.NavMeshAgentParam")) && (olua_is_number(L, 2))) {
            // float height
            return _olua_fun_cocos2d_NavMeshAgentParam_height$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::NavMeshAgentParam::height' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_maxAcceleration$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::NavMeshAgentParam *self = nullptr;

    olua_to_object(L, 1, &self, "cc.NavMeshAgentParam");

    // float maxAcceleration
    float ret = self->maxAcceleration;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_maxAcceleration$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::NavMeshAgentParam *self = nullptr;
    float arg1 = 0;       /** maxAcceleration */

    olua_to_object(L, 1, &self, "cc.NavMeshAgentParam");
    olua_check_number(L, 2, &arg1);

    // float maxAcceleration
    self->maxAcceleration = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_maxAcceleration(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float maxAcceleration
        return _olua_fun_cocos2d_NavMeshAgentParam_maxAcceleration$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.NavMeshAgentParam")) && (olua_is_number(L, 2))) {
            // float maxAcceleration
            return _olua_fun_cocos2d_NavMeshAgentParam_maxAcceleration$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::NavMeshAgentParam::maxAcceleration' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_maxSpeed$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::NavMeshAgentParam *self = nullptr;

    olua_to_object(L, 1, &self, "cc.NavMeshAgentParam");

    // float maxSpeed
    float ret = self->maxSpeed;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_maxSpeed$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::NavMeshAgentParam *self = nullptr;
    float arg1 = 0;       /** maxSpeed */

    olua_to_object(L, 1, &self, "cc.NavMeshAgentParam");
    olua_check_number(L, 2, &arg1);

    // float maxSpeed
    self->maxSpeed = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_maxSpeed(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float maxSpeed
        return _olua_fun_cocos2d_NavMeshAgentParam_maxSpeed$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.NavMeshAgentParam")) && (olua_is_number(L, 2))) {
            // float maxSpeed
            return _olua_fun_cocos2d_NavMeshAgentParam_maxSpeed$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::NavMeshAgentParam::maxSpeed' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_new(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::NavMeshAgentParam()
    cocos2d::NavMeshAgentParam *ret = new cocos2d::NavMeshAgentParam();
    int num_ret = olua_push_object(L, ret, "cc.NavMeshAgentParam");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_obstacleAvoidanceType$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::NavMeshAgentParam *self = nullptr;

    olua_to_object(L, 1, &self, "cc.NavMeshAgentParam");

    // unsigned char obstacleAvoidanceType
    unsigned char ret = self->obstacleAvoidanceType;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_obstacleAvoidanceType$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::NavMeshAgentParam *self = nullptr;
    unsigned char arg1 = 0;       /** obstacleAvoidanceType */

    olua_to_object(L, 1, &self, "cc.NavMeshAgentParam");
    olua_check_integer(L, 2, &arg1);

    // unsigned char obstacleAvoidanceType
    self->obstacleAvoidanceType = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_obstacleAvoidanceType(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // unsigned char obstacleAvoidanceType
        return _olua_fun_cocos2d_NavMeshAgentParam_obstacleAvoidanceType$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.NavMeshAgentParam")) && (olua_is_integer(L, 2))) {
            // unsigned char obstacleAvoidanceType
            return _olua_fun_cocos2d_NavMeshAgentParam_obstacleAvoidanceType$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::NavMeshAgentParam::obstacleAvoidanceType' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_pathOptimizationRange$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::NavMeshAgentParam *self = nullptr;

    olua_to_object(L, 1, &self, "cc.NavMeshAgentParam");

    // float pathOptimizationRange
    float ret = self->pathOptimizationRange;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_pathOptimizationRange$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::NavMeshAgentParam *self = nullptr;
    float arg1 = 0;       /** pathOptimizationRange */

    olua_to_object(L, 1, &self, "cc.NavMeshAgentParam");
    olua_check_number(L, 2, &arg1);

    // float pathOptimizationRange
    self->pathOptimizationRange = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_pathOptimizationRange(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float pathOptimizationRange
        return _olua_fun_cocos2d_NavMeshAgentParam_pathOptimizationRange$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.NavMeshAgentParam")) && (olua_is_number(L, 2))) {
            // float pathOptimizationRange
            return _olua_fun_cocos2d_NavMeshAgentParam_pathOptimizationRange$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::NavMeshAgentParam::pathOptimizationRange' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_queryFilterType$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::NavMeshAgentParam *self = nullptr;

    olua_to_object(L, 1, &self, "cc.NavMeshAgentParam");

    // unsigned char queryFilterType
    unsigned char ret = self->queryFilterType;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_queryFilterType$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::NavMeshAgentParam *self = nullptr;
    unsigned char arg1 = 0;       /** queryFilterType */

    olua_to_object(L, 1, &self, "cc.NavMeshAgentParam");
    olua_check_integer(L, 2, &arg1);

    // unsigned char queryFilterType
    self->queryFilterType = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_queryFilterType(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // unsigned char queryFilterType
        return _olua_fun_cocos2d_NavMeshAgentParam_queryFilterType$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.NavMeshAgentParam")) && (olua_is_integer(L, 2))) {
            // unsigned char queryFilterType
            return _olua_fun_cocos2d_NavMeshAgentParam_queryFilterType$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::NavMeshAgentParam::queryFilterType' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_radius$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::NavMeshAgentParam *self = nullptr;

    olua_to_object(L, 1, &self, "cc.NavMeshAgentParam");

    // float radius
    float ret = self->radius;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_radius$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::NavMeshAgentParam *self = nullptr;
    float arg1 = 0;       /** radius */

    olua_to_object(L, 1, &self, "cc.NavMeshAgentParam");
    olua_check_number(L, 2, &arg1);

    // float radius
    self->radius = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_radius(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float radius
        return _olua_fun_cocos2d_NavMeshAgentParam_radius$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.NavMeshAgentParam")) && (olua_is_number(L, 2))) {
            // float radius
            return _olua_fun_cocos2d_NavMeshAgentParam_radius$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::NavMeshAgentParam::radius' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_separationWeight$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::NavMeshAgentParam *self = nullptr;

    olua_to_object(L, 1, &self, "cc.NavMeshAgentParam");

    // float separationWeight
    float ret = self->separationWeight;
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_separationWeight$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::NavMeshAgentParam *self = nullptr;
    float arg1 = 0;       /** separationWeight */

    olua_to_object(L, 1, &self, "cc.NavMeshAgentParam");
    olua_check_number(L, 2, &arg1);

    // float separationWeight
    self->separationWeight = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_separationWeight(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // float separationWeight
        return _olua_fun_cocos2d_NavMeshAgentParam_separationWeight$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.NavMeshAgentParam")) && (olua_is_number(L, 2))) {
            // float separationWeight
            return _olua_fun_cocos2d_NavMeshAgentParam_separationWeight$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::NavMeshAgentParam::separationWeight' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_updateFlags$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::NavMeshAgentParam *self = nullptr;

    olua_to_object(L, 1, &self, "cc.NavMeshAgentParam");

    // unsigned char updateFlags
    unsigned char ret = self->updateFlags;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_updateFlags$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::NavMeshAgentParam *self = nullptr;
    unsigned char arg1 = 0;       /** updateFlags */

    olua_to_object(L, 1, &self, "cc.NavMeshAgentParam");
    olua_check_integer(L, 2, &arg1);

    // unsigned char updateFlags
    self->updateFlags = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_NavMeshAgentParam_updateFlags(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // unsigned char updateFlags
        return _olua_fun_cocos2d_NavMeshAgentParam_updateFlags$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.NavMeshAgentParam")) && (olua_is_integer(L, 2))) {
            // unsigned char updateFlags
            return _olua_fun_cocos2d_NavMeshAgentParam_updateFlags$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::NavMeshAgentParam::updateFlags' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_cc_NavMeshAgentParam(lua_State *L)
{
    oluacls_class<cocos2d::NavMeshAgentParam>(L, "cc.NavMeshAgentParam");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_NavMeshAgentParam___gc);
    oluacls_func(L, "new", _olua_fun_cocos2d_NavMeshAgentParam_new);
    oluacls_prop(L, "radius", _olua_fun_cocos2d_NavMeshAgentParam_radius, _olua_fun_cocos2d_NavMeshAgentParam_radius);
    oluacls_prop(L, "height", _olua_fun_cocos2d_NavMeshAgentParam_height, _olua_fun_cocos2d_NavMeshAgentParam_height);
    oluacls_prop(L, "maxAcceleration", _olua_fun_cocos2d_NavMeshAgentParam_maxAcceleration, _olua_fun_cocos2d_NavMeshAgentParam_maxAcceleration);
    oluacls_prop(L, "maxSpeed", _olua_fun_cocos2d_NavMeshAgentParam_maxSpeed, _olua_fun_cocos2d_NavMeshAgentParam_maxSpeed);
    oluacls_prop(L, "collisionQueryRange", _olua_fun_cocos2d_NavMeshAgentParam_collisionQueryRange, _olua_fun_cocos2d_NavMeshAgentParam_collisionQueryRange);
    oluacls_prop(L, "pathOptimizationRange", _olua_fun_cocos2d_NavMeshAgentParam_pathOptimizationRange, _olua_fun_cocos2d_NavMeshAgentParam_pathOptimizationRange);
    oluacls_prop(L, "separationWeight", _olua_fun_cocos2d_NavMeshAgentParam_separationWeight, _olua_fun_cocos2d_NavMeshAgentParam_separationWeight);
    oluacls_prop(L, "updateFlags", _olua_fun_cocos2d_NavMeshAgentParam_updateFlags, _olua_fun_cocos2d_NavMeshAgentParam_updateFlags);
    oluacls_prop(L, "obstacleAvoidanceType", _olua_fun_cocos2d_NavMeshAgentParam_obstacleAvoidanceType, _olua_fun_cocos2d_NavMeshAgentParam_obstacleAvoidanceType);
    oluacls_prop(L, "queryFilterType", _olua_fun_cocos2d_NavMeshAgentParam_queryFilterType, _olua_fun_cocos2d_NavMeshAgentParam_queryFilterType);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cc_NavMeshAgentParam(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "cc.NavMeshAgentParam")) {
        luaL_error(L, "class not found: cocos2d::NavMeshAgentParam");
    }
    return 1;
}
OLUA_END_DECLS
#endif

#if CC_USE_NAVMESH
static int _olua_fun_cocos2d_OffMeshLinkData___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::OffMeshLinkData *)olua_toobj(L, 1, "cc.OffMeshLinkData");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_OffMeshLinkData_endPosition$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::OffMeshLinkData *self = nullptr;

    olua_to_object(L, 1, &self, "cc.OffMeshLinkData");

    // cocos2d::Vec3 endPosition
    cocos2d::Vec3 &ret = self->endPosition;
    int num_ret = olua_copy_object(L, ret, "cc.Vec3");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_OffMeshLinkData_endPosition$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::OffMeshLinkData *self = nullptr;
    cocos2d::Vec3 *arg1;       /** endPosition */

    olua_to_object(L, 1, &self, "cc.OffMeshLinkData");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // cocos2d::Vec3 endPosition
    self->endPosition = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_OffMeshLinkData_endPosition(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::Vec3 endPosition
        return _olua_fun_cocos2d_OffMeshLinkData_endPosition$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.OffMeshLinkData")) && (olua_is_object(L, 2, "cc.Vec3"))) {
            // cocos2d::Vec3 endPosition
            return _olua_fun_cocos2d_OffMeshLinkData_endPosition$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::OffMeshLinkData::endPosition' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_OffMeshLinkData_startPosition$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::OffMeshLinkData *self = nullptr;

    olua_to_object(L, 1, &self, "cc.OffMeshLinkData");

    // cocos2d::Vec3 startPosition
    cocos2d::Vec3 &ret = self->startPosition;
    int num_ret = olua_copy_object(L, ret, "cc.Vec3");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_OffMeshLinkData_startPosition$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::OffMeshLinkData *self = nullptr;
    cocos2d::Vec3 *arg1;       /** startPosition */

    olua_to_object(L, 1, &self, "cc.OffMeshLinkData");
    olua_check_object(L, 2, &arg1, "cc.Vec3");

    // cocos2d::Vec3 startPosition
    self->startPosition = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_OffMeshLinkData_startPosition(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::Vec3 startPosition
        return _olua_fun_cocos2d_OffMeshLinkData_startPosition$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.OffMeshLinkData")) && (olua_is_object(L, 2, "cc.Vec3"))) {
            // cocos2d::Vec3 startPosition
            return _olua_fun_cocos2d_OffMeshLinkData_startPosition$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::OffMeshLinkData::startPosition' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_cc_OffMeshLinkData(lua_State *L)
{
    oluacls_class<cocos2d::OffMeshLinkData>(L, "cc.OffMeshLinkData");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_OffMeshLinkData___gc);
    oluacls_prop(L, "startPosition", _olua_fun_cocos2d_OffMeshLinkData_startPosition, _olua_fun_cocos2d_OffMeshLinkData_startPosition);
    oluacls_prop(L, "endPosition", _olua_fun_cocos2d_OffMeshLinkData_endPosition, _olua_fun_cocos2d_OffMeshLinkData_endPosition);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cc_OffMeshLinkData(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "cc.OffMeshLinkData")) {
        luaL_error(L, "class not found: cocos2d::OffMeshLinkData");
    }
    return 1;
}
OLUA_END_DECLS
#endif

static int _olua_fun_cocos2d_backend_BlendDescriptor___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::backend::BlendDescriptor *)olua_toobj(L, 1, "ccb.BlendDescriptor");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_BlendDescriptor_alphaBlendOperation$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::BlendDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.BlendDescriptor");

    // cocos2d::backend::BlendOperation alphaBlendOperation
    cocos2d::backend::BlendOperation ret = self->alphaBlendOperation;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_BlendDescriptor_alphaBlendOperation$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::BlendDescriptor *self = nullptr;
    cocos2d::backend::BlendOperation arg1 = (cocos2d::backend::BlendOperation)0;       /** alphaBlendOperation */

    olua_to_object(L, 1, &self, "ccb.BlendDescriptor");
    olua_check_enum(L, 2, &arg1);

    // cocos2d::backend::BlendOperation alphaBlendOperation
    self->alphaBlendOperation = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_BlendDescriptor_alphaBlendOperation(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::backend::BlendOperation alphaBlendOperation
        return _olua_fun_cocos2d_backend_BlendDescriptor_alphaBlendOperation$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.BlendDescriptor")) && (olua_is_enum(L, 2))) {
            // cocos2d::backend::BlendOperation alphaBlendOperation
            return _olua_fun_cocos2d_backend_BlendDescriptor_alphaBlendOperation$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::BlendDescriptor::alphaBlendOperation' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_BlendDescriptor_blendEnabled$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::BlendDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.BlendDescriptor");

    // bool blendEnabled
    bool ret = self->blendEnabled;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_BlendDescriptor_blendEnabled$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::BlendDescriptor *self = nullptr;
    bool arg1 = false;       /** blendEnabled */

    olua_to_object(L, 1, &self, "ccb.BlendDescriptor");
    olua_check_bool(L, 2, &arg1);

    // bool blendEnabled
    self->blendEnabled = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_BlendDescriptor_blendEnabled(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool blendEnabled
        return _olua_fun_cocos2d_backend_BlendDescriptor_blendEnabled$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.BlendDescriptor")) && (olua_is_bool(L, 2))) {
            // bool blendEnabled
            return _olua_fun_cocos2d_backend_BlendDescriptor_blendEnabled$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::BlendDescriptor::blendEnabled' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_BlendDescriptor_destinationAlphaBlendFactor$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::BlendDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.BlendDescriptor");

    // cocos2d::backend::BlendFactor destinationAlphaBlendFactor
    cocos2d::backend::BlendFactor ret = self->destinationAlphaBlendFactor;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_BlendDescriptor_destinationAlphaBlendFactor$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::BlendDescriptor *self = nullptr;
    cocos2d::backend::BlendFactor arg1 = (cocos2d::backend::BlendFactor)0;       /** destinationAlphaBlendFactor */

    olua_to_object(L, 1, &self, "ccb.BlendDescriptor");
    olua_check_enum(L, 2, &arg1);

    // cocos2d::backend::BlendFactor destinationAlphaBlendFactor
    self->destinationAlphaBlendFactor = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_BlendDescriptor_destinationAlphaBlendFactor(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::backend::BlendFactor destinationAlphaBlendFactor
        return _olua_fun_cocos2d_backend_BlendDescriptor_destinationAlphaBlendFactor$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.BlendDescriptor")) && (olua_is_enum(L, 2))) {
            // cocos2d::backend::BlendFactor destinationAlphaBlendFactor
            return _olua_fun_cocos2d_backend_BlendDescriptor_destinationAlphaBlendFactor$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::BlendDescriptor::destinationAlphaBlendFactor' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_BlendDescriptor_destinationRGBBlendFactor$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::BlendDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.BlendDescriptor");

    // cocos2d::backend::BlendFactor destinationRGBBlendFactor
    cocos2d::backend::BlendFactor ret = self->destinationRGBBlendFactor;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_BlendDescriptor_destinationRGBBlendFactor$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::BlendDescriptor *self = nullptr;
    cocos2d::backend::BlendFactor arg1 = (cocos2d::backend::BlendFactor)0;       /** destinationRGBBlendFactor */

    olua_to_object(L, 1, &self, "ccb.BlendDescriptor");
    olua_check_enum(L, 2, &arg1);

    // cocos2d::backend::BlendFactor destinationRGBBlendFactor
    self->destinationRGBBlendFactor = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_BlendDescriptor_destinationRGBBlendFactor(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::backend::BlendFactor destinationRGBBlendFactor
        return _olua_fun_cocos2d_backend_BlendDescriptor_destinationRGBBlendFactor$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.BlendDescriptor")) && (olua_is_enum(L, 2))) {
            // cocos2d::backend::BlendFactor destinationRGBBlendFactor
            return _olua_fun_cocos2d_backend_BlendDescriptor_destinationRGBBlendFactor$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::BlendDescriptor::destinationRGBBlendFactor' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_BlendDescriptor_rgbBlendOperation$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::BlendDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.BlendDescriptor");

    // cocos2d::backend::BlendOperation rgbBlendOperation
    cocos2d::backend::BlendOperation ret = self->rgbBlendOperation;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_BlendDescriptor_rgbBlendOperation$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::BlendDescriptor *self = nullptr;
    cocos2d::backend::BlendOperation arg1 = (cocos2d::backend::BlendOperation)0;       /** rgbBlendOperation */

    olua_to_object(L, 1, &self, "ccb.BlendDescriptor");
    olua_check_enum(L, 2, &arg1);

    // cocos2d::backend::BlendOperation rgbBlendOperation
    self->rgbBlendOperation = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_BlendDescriptor_rgbBlendOperation(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::backend::BlendOperation rgbBlendOperation
        return _olua_fun_cocos2d_backend_BlendDescriptor_rgbBlendOperation$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.BlendDescriptor")) && (olua_is_enum(L, 2))) {
            // cocos2d::backend::BlendOperation rgbBlendOperation
            return _olua_fun_cocos2d_backend_BlendDescriptor_rgbBlendOperation$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::BlendDescriptor::rgbBlendOperation' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_BlendDescriptor_sourceAlphaBlendFactor$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::BlendDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.BlendDescriptor");

    // cocos2d::backend::BlendFactor sourceAlphaBlendFactor
    cocos2d::backend::BlendFactor ret = self->sourceAlphaBlendFactor;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_BlendDescriptor_sourceAlphaBlendFactor$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::BlendDescriptor *self = nullptr;
    cocos2d::backend::BlendFactor arg1 = (cocos2d::backend::BlendFactor)0;       /** sourceAlphaBlendFactor */

    olua_to_object(L, 1, &self, "ccb.BlendDescriptor");
    olua_check_enum(L, 2, &arg1);

    // cocos2d::backend::BlendFactor sourceAlphaBlendFactor
    self->sourceAlphaBlendFactor = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_BlendDescriptor_sourceAlphaBlendFactor(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::backend::BlendFactor sourceAlphaBlendFactor
        return _olua_fun_cocos2d_backend_BlendDescriptor_sourceAlphaBlendFactor$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.BlendDescriptor")) && (olua_is_enum(L, 2))) {
            // cocos2d::backend::BlendFactor sourceAlphaBlendFactor
            return _olua_fun_cocos2d_backend_BlendDescriptor_sourceAlphaBlendFactor$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::BlendDescriptor::sourceAlphaBlendFactor' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_BlendDescriptor_sourceRGBBlendFactor$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::BlendDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.BlendDescriptor");

    // cocos2d::backend::BlendFactor sourceRGBBlendFactor
    cocos2d::backend::BlendFactor ret = self->sourceRGBBlendFactor;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_BlendDescriptor_sourceRGBBlendFactor$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::BlendDescriptor *self = nullptr;
    cocos2d::backend::BlendFactor arg1 = (cocos2d::backend::BlendFactor)0;       /** sourceRGBBlendFactor */

    olua_to_object(L, 1, &self, "ccb.BlendDescriptor");
    olua_check_enum(L, 2, &arg1);

    // cocos2d::backend::BlendFactor sourceRGBBlendFactor
    self->sourceRGBBlendFactor = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_BlendDescriptor_sourceRGBBlendFactor(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::backend::BlendFactor sourceRGBBlendFactor
        return _olua_fun_cocos2d_backend_BlendDescriptor_sourceRGBBlendFactor$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.BlendDescriptor")) && (olua_is_enum(L, 2))) {
            // cocos2d::backend::BlendFactor sourceRGBBlendFactor
            return _olua_fun_cocos2d_backend_BlendDescriptor_sourceRGBBlendFactor$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::BlendDescriptor::sourceRGBBlendFactor' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_BlendDescriptor_writeMask$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::BlendDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.BlendDescriptor");

    // cocos2d::backend::ColorWriteMask writeMask
    cocos2d::backend::ColorWriteMask ret = self->writeMask;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_BlendDescriptor_writeMask$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::BlendDescriptor *self = nullptr;
    cocos2d::backend::ColorWriteMask arg1 = (cocos2d::backend::ColorWriteMask)0;       /** writeMask */

    olua_to_object(L, 1, &self, "ccb.BlendDescriptor");
    olua_check_enum(L, 2, &arg1);

    // cocos2d::backend::ColorWriteMask writeMask
    self->writeMask = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_BlendDescriptor_writeMask(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::backend::ColorWriteMask writeMask
        return _olua_fun_cocos2d_backend_BlendDescriptor_writeMask$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.BlendDescriptor")) && (olua_is_enum(L, 2))) {
            // cocos2d::backend::ColorWriteMask writeMask
            return _olua_fun_cocos2d_backend_BlendDescriptor_writeMask$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::BlendDescriptor::writeMask' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_ccb_BlendDescriptor(lua_State *L)
{
    oluacls_class<cocos2d::backend::BlendDescriptor>(L, "ccb.BlendDescriptor");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_backend_BlendDescriptor___gc);
    oluacls_prop(L, "writeMask", _olua_fun_cocos2d_backend_BlendDescriptor_writeMask, _olua_fun_cocos2d_backend_BlendDescriptor_writeMask);
    oluacls_prop(L, "blendEnabled", _olua_fun_cocos2d_backend_BlendDescriptor_blendEnabled, _olua_fun_cocos2d_backend_BlendDescriptor_blendEnabled);
    oluacls_prop(L, "rgbBlendOperation", _olua_fun_cocos2d_backend_BlendDescriptor_rgbBlendOperation, _olua_fun_cocos2d_backend_BlendDescriptor_rgbBlendOperation);
    oluacls_prop(L, "alphaBlendOperation", _olua_fun_cocos2d_backend_BlendDescriptor_alphaBlendOperation, _olua_fun_cocos2d_backend_BlendDescriptor_alphaBlendOperation);
    oluacls_prop(L, "sourceRGBBlendFactor", _olua_fun_cocos2d_backend_BlendDescriptor_sourceRGBBlendFactor, _olua_fun_cocos2d_backend_BlendDescriptor_sourceRGBBlendFactor);
    oluacls_prop(L, "destinationRGBBlendFactor", _olua_fun_cocos2d_backend_BlendDescriptor_destinationRGBBlendFactor, _olua_fun_cocos2d_backend_BlendDescriptor_destinationRGBBlendFactor);
    oluacls_prop(L, "sourceAlphaBlendFactor", _olua_fun_cocos2d_backend_BlendDescriptor_sourceAlphaBlendFactor, _olua_fun_cocos2d_backend_BlendDescriptor_sourceAlphaBlendFactor);
    oluacls_prop(L, "destinationAlphaBlendFactor", _olua_fun_cocos2d_backend_BlendDescriptor_destinationAlphaBlendFactor, _olua_fun_cocos2d_backend_BlendDescriptor_destinationAlphaBlendFactor);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_BlendDescriptor(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "ccb.BlendDescriptor")) {
        luaL_error(L, "class not found: cocos2d::backend::BlendDescriptor");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_backend_SamplerDescriptor___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::backend::SamplerDescriptor *)olua_toobj(L, 1, "ccb.SamplerDescriptor");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_SamplerDescriptor_magFilter$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::SamplerDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.SamplerDescriptor");

    // cocos2d::backend::SamplerFilter magFilter
    cocos2d::backend::SamplerFilter ret = self->magFilter;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_SamplerDescriptor_magFilter$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::SamplerDescriptor *self = nullptr;
    cocos2d::backend::SamplerFilter arg1 = (cocos2d::backend::SamplerFilter)0;       /** magFilter */

    olua_to_object(L, 1, &self, "ccb.SamplerDescriptor");
    olua_check_enum(L, 2, &arg1);

    // cocos2d::backend::SamplerFilter magFilter
    self->magFilter = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_SamplerDescriptor_magFilter(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::backend::SamplerFilter magFilter
        return _olua_fun_cocos2d_backend_SamplerDescriptor_magFilter$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.SamplerDescriptor")) && (olua_is_enum(L, 2))) {
            // cocos2d::backend::SamplerFilter magFilter
            return _olua_fun_cocos2d_backend_SamplerDescriptor_magFilter$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::SamplerDescriptor::magFilter' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_SamplerDescriptor_minFilter$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::SamplerDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.SamplerDescriptor");

    // cocos2d::backend::SamplerFilter minFilter
    cocos2d::backend::SamplerFilter ret = self->minFilter;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_SamplerDescriptor_minFilter$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::SamplerDescriptor *self = nullptr;
    cocos2d::backend::SamplerFilter arg1 = (cocos2d::backend::SamplerFilter)0;       /** minFilter */

    olua_to_object(L, 1, &self, "ccb.SamplerDescriptor");
    olua_check_enum(L, 2, &arg1);

    // cocos2d::backend::SamplerFilter minFilter
    self->minFilter = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_SamplerDescriptor_minFilter(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::backend::SamplerFilter minFilter
        return _olua_fun_cocos2d_backend_SamplerDescriptor_minFilter$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.SamplerDescriptor")) && (olua_is_enum(L, 2))) {
            // cocos2d::backend::SamplerFilter minFilter
            return _olua_fun_cocos2d_backend_SamplerDescriptor_minFilter$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::SamplerDescriptor::minFilter' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_SamplerDescriptor_new$1(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::backend::SamplerDescriptor()
    cocos2d::backend::SamplerDescriptor *ret = new cocos2d::backend::SamplerDescriptor();
    int num_ret = olua_push_object(L, ret, "ccb.SamplerDescriptor");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_SamplerDescriptor_new$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::SamplerFilter arg1 = (cocos2d::backend::SamplerFilter)0;       /** _magFilter */
    cocos2d::backend::SamplerFilter arg2 = (cocos2d::backend::SamplerFilter)0;       /** _minFilter */
    cocos2d::backend::SamplerAddressMode arg3 = (cocos2d::backend::SamplerAddressMode)0;       /** _sAddressMode */
    cocos2d::backend::SamplerAddressMode arg4 = (cocos2d::backend::SamplerAddressMode)0;       /** _tAddressMode */

    olua_check_enum(L, 1, &arg1);
    olua_check_enum(L, 2, &arg2);
    olua_check_enum(L, 3, &arg3);
    olua_check_enum(L, 4, &arg4);

    // cocos2d::backend::SamplerDescriptor(cocos2d::backend::SamplerFilter _magFilter, cocos2d::backend::SamplerFilter _minFilter, cocos2d::backend::SamplerAddressMode _sAddressMode, cocos2d::backend::SamplerAddressMode _tAddressMode)
    cocos2d::backend::SamplerDescriptor *ret = new cocos2d::backend::SamplerDescriptor(arg1, arg2, arg3, arg4);
    int num_ret = olua_push_object(L, ret, "ccb.SamplerDescriptor");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_SamplerDescriptor_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // cocos2d::backend::SamplerDescriptor()
        return _olua_fun_cocos2d_backend_SamplerDescriptor_new$1(L);
    }

    if (num_args == 4) {
        // if ((olua_is_enum(L, 1)) && (olua_is_enum(L, 2)) && (olua_is_enum(L, 3)) && (olua_is_enum(L, 4))) {
            // cocos2d::backend::SamplerDescriptor(cocos2d::backend::SamplerFilter _magFilter, cocos2d::backend::SamplerFilter _minFilter, cocos2d::backend::SamplerAddressMode _sAddressMode, cocos2d::backend::SamplerAddressMode _tAddressMode)
            return _olua_fun_cocos2d_backend_SamplerDescriptor_new$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::SamplerDescriptor::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_SamplerDescriptor_sAddressMode$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::SamplerDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.SamplerDescriptor");

    // cocos2d::backend::SamplerAddressMode sAddressMode
    cocos2d::backend::SamplerAddressMode ret = self->sAddressMode;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_SamplerDescriptor_sAddressMode$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::SamplerDescriptor *self = nullptr;
    cocos2d::backend::SamplerAddressMode arg1 = (cocos2d::backend::SamplerAddressMode)0;       /** sAddressMode */

    olua_to_object(L, 1, &self, "ccb.SamplerDescriptor");
    olua_check_enum(L, 2, &arg1);

    // cocos2d::backend::SamplerAddressMode sAddressMode
    self->sAddressMode = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_SamplerDescriptor_sAddressMode(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::backend::SamplerAddressMode sAddressMode
        return _olua_fun_cocos2d_backend_SamplerDescriptor_sAddressMode$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.SamplerDescriptor")) && (olua_is_enum(L, 2))) {
            // cocos2d::backend::SamplerAddressMode sAddressMode
            return _olua_fun_cocos2d_backend_SamplerDescriptor_sAddressMode$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::SamplerDescriptor::sAddressMode' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_SamplerDescriptor_tAddressMode$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::SamplerDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.SamplerDescriptor");

    // cocos2d::backend::SamplerAddressMode tAddressMode
    cocos2d::backend::SamplerAddressMode ret = self->tAddressMode;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_SamplerDescriptor_tAddressMode$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::SamplerDescriptor *self = nullptr;
    cocos2d::backend::SamplerAddressMode arg1 = (cocos2d::backend::SamplerAddressMode)0;       /** tAddressMode */

    olua_to_object(L, 1, &self, "ccb.SamplerDescriptor");
    olua_check_enum(L, 2, &arg1);

    // cocos2d::backend::SamplerAddressMode tAddressMode
    self->tAddressMode = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_SamplerDescriptor_tAddressMode(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::backend::SamplerAddressMode tAddressMode
        return _olua_fun_cocos2d_backend_SamplerDescriptor_tAddressMode$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.SamplerDescriptor")) && (olua_is_enum(L, 2))) {
            // cocos2d::backend::SamplerAddressMode tAddressMode
            return _olua_fun_cocos2d_backend_SamplerDescriptor_tAddressMode$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::SamplerDescriptor::tAddressMode' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_ccb_SamplerDescriptor(lua_State *L)
{
    oluacls_class<cocos2d::backend::SamplerDescriptor>(L, "ccb.SamplerDescriptor");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_backend_SamplerDescriptor___gc);
    oluacls_func(L, "new", _olua_fun_cocos2d_backend_SamplerDescriptor_new);
    oluacls_prop(L, "magFilter", _olua_fun_cocos2d_backend_SamplerDescriptor_magFilter, _olua_fun_cocos2d_backend_SamplerDescriptor_magFilter);
    oluacls_prop(L, "minFilter", _olua_fun_cocos2d_backend_SamplerDescriptor_minFilter, _olua_fun_cocos2d_backend_SamplerDescriptor_minFilter);
    oluacls_prop(L, "sAddressMode", _olua_fun_cocos2d_backend_SamplerDescriptor_sAddressMode, _olua_fun_cocos2d_backend_SamplerDescriptor_sAddressMode);
    oluacls_prop(L, "tAddressMode", _olua_fun_cocos2d_backend_SamplerDescriptor_tAddressMode, _olua_fun_cocos2d_backend_SamplerDescriptor_tAddressMode);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_SamplerDescriptor(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "ccb.SamplerDescriptor")) {
        luaL_error(L, "class not found: cocos2d::backend::SamplerDescriptor");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_backend_TextureInfo___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::backend::TextureInfo *)olua_toobj(L, 1, "ccb.TextureInfo");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_TextureInfo_new$1(lua_State *L)
{
    olua_startinvoke(L);

    std::vector<uint32_t> arg1;       /** _slots */
    std::vector<cocos2d::backend::TextureBackend *> arg2;       /** _textures */

    olua_check_array<uint32_t>(L, 1, arg1, [L](uint32_t *arg1) {
        olua_check_integer(L, -1, arg1);
    });
    olua_check_array<cocos2d::backend::TextureBackend *>(L, 2, arg2, [L](cocos2d::backend::TextureBackend **arg1) {
        olua_check_object(L, -1, arg1, "ccb.TextureBackend");
    });

    // cocos2d::backend::TextureInfo(const std::vector<uint32_t> &_slots, const std::vector<cocos2d::backend::TextureBackend *> _textures)
    cocos2d::backend::TextureInfo *ret = new cocos2d::backend::TextureInfo(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "ccb.TextureInfo");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_TextureInfo_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::backend::TextureInfo()
    cocos2d::backend::TextureInfo *ret = new cocos2d::backend::TextureInfo();
    int num_ret = olua_push_object(L, ret, "ccb.TextureInfo");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_TextureInfo_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // cocos2d::backend::TextureInfo()
        return _olua_fun_cocos2d_backend_TextureInfo_new$2(L);
    }

    if (num_args == 2) {
        // if ((olua_is_array(L, 1)) && (olua_is_array(L, 2))) {
            // cocos2d::backend::TextureInfo(const std::vector<uint32_t> &_slots, const std::vector<cocos2d::backend::TextureBackend *> _textures)
            return _olua_fun_cocos2d_backend_TextureInfo_new$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::TextureInfo::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_TextureInfo_releaseTextures(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureInfo *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.TextureInfo");

    // void releaseTextures()
    self->releaseTextures();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_TextureInfo_retainTextures(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureInfo *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.TextureInfo");

    // void retainTextures()
    self->retainTextures();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_TextureInfo_slot$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureInfo *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.TextureInfo");

    // std::vector<uint32_t> slot
    std::vector<uint32_t> &ret = self->slot;
    int num_ret = olua_push_array<uint32_t>(L, ret, [L](uint32_t &arg1) {
        olua_push_integer(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_TextureInfo_slot$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureInfo *self = nullptr;
    std::vector<uint32_t> arg1;       /** slot */

    olua_to_object(L, 1, &self, "ccb.TextureInfo");
    olua_check_array<uint32_t>(L, 2, arg1, [L](uint32_t *arg1) {
        olua_check_integer(L, -1, arg1);
    });

    // std::vector<uint32_t> slot
    self->slot = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_TextureInfo_slot(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::vector<uint32_t> slot
        return _olua_fun_cocos2d_backend_TextureInfo_slot$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.TextureInfo")) && (olua_is_array(L, 2))) {
            // std::vector<uint32_t> slot
            return _olua_fun_cocos2d_backend_TextureInfo_slot$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::TextureInfo::slot' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_TextureInfo_textures$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureInfo *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.TextureInfo");

    // std::vector<cocos2d::backend::TextureBackend *> textures
    std::vector<cocos2d::backend::TextureBackend *> &ret = self->textures;
    int num_ret = olua_push_array<cocos2d::backend::TextureBackend *>(L, ret, [L](cocos2d::backend::TextureBackend *arg1) {
        olua_push_object(L, arg1, "ccb.TextureBackend");
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_TextureInfo_textures$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureInfo *self = nullptr;
    std::vector<cocos2d::backend::TextureBackend *> arg1;       /** textures */

    olua_to_object(L, 1, &self, "ccb.TextureInfo");
    olua_check_array<cocos2d::backend::TextureBackend *>(L, 2, arg1, [L](cocos2d::backend::TextureBackend **arg1) {
        olua_check_object(L, -1, arg1, "ccb.TextureBackend");
    });

    // std::vector<cocos2d::backend::TextureBackend *> textures
    self->textures = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_TextureInfo_textures(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::vector<cocos2d::backend::TextureBackend *> textures
        return _olua_fun_cocos2d_backend_TextureInfo_textures$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.TextureInfo")) && (olua_is_array(L, 2))) {
            // std::vector<cocos2d::backend::TextureBackend *> textures
            return _olua_fun_cocos2d_backend_TextureInfo_textures$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::TextureInfo::textures' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_ccb_TextureInfo(lua_State *L)
{
    oluacls_class<cocos2d::backend::TextureInfo>(L, "ccb.TextureInfo");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_backend_TextureInfo___gc);
    oluacls_func(L, "new", _olua_fun_cocos2d_backend_TextureInfo_new);
    oluacls_func(L, "releaseTextures", _olua_fun_cocos2d_backend_TextureInfo_releaseTextures);
    oluacls_func(L, "retainTextures", _olua_fun_cocos2d_backend_TextureInfo_retainTextures);
    oluacls_prop(L, "slot", _olua_fun_cocos2d_backend_TextureInfo_slot, _olua_fun_cocos2d_backend_TextureInfo_slot);
    oluacls_prop(L, "textures", _olua_fun_cocos2d_backend_TextureInfo_textures, _olua_fun_cocos2d_backend_TextureInfo_textures);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_TextureInfo(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "ccb.TextureInfo")) {
        luaL_error(L, "class not found: cocos2d::backend::TextureInfo");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_backend_AttributeBindInfo___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::backend::AttributeBindInfo *)olua_toobj(L, 1, "ccb.AttributeBindInfo");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_AttributeBindInfo_attributeName$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::AttributeBindInfo *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.AttributeBindInfo");

    // std::string attributeName
    std::string ret = self->attributeName;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_AttributeBindInfo_attributeName$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::AttributeBindInfo *self = nullptr;
    std::string arg1;       /** attributeName */

    olua_to_object(L, 1, &self, "ccb.AttributeBindInfo");
    olua_check_string(L, 2, &arg1);

    // std::string attributeName
    self->attributeName = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_AttributeBindInfo_attributeName(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::string attributeName
        return _olua_fun_cocos2d_backend_AttributeBindInfo_attributeName$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.AttributeBindInfo")) && (olua_is_string(L, 2))) {
            // std::string attributeName
            return _olua_fun_cocos2d_backend_AttributeBindInfo_attributeName$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::AttributeBindInfo::attributeName' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_AttributeBindInfo_location$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::AttributeBindInfo *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.AttributeBindInfo");

    // int location
    int ret = self->location;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_AttributeBindInfo_location$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::AttributeBindInfo *self = nullptr;
    int arg1 = 0;       /** location */

    olua_to_object(L, 1, &self, "ccb.AttributeBindInfo");
    olua_check_integer(L, 2, &arg1);

    // int location
    self->location = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_AttributeBindInfo_location(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // int location
        return _olua_fun_cocos2d_backend_AttributeBindInfo_location$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.AttributeBindInfo")) && (olua_is_integer(L, 2))) {
            // int location
            return _olua_fun_cocos2d_backend_AttributeBindInfo_location$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::AttributeBindInfo::location' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_AttributeBindInfo_size$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::AttributeBindInfo *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.AttributeBindInfo");

    // int size
    int ret = self->size;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_AttributeBindInfo_size$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::AttributeBindInfo *self = nullptr;
    int arg1 = 0;       /** size */

    olua_to_object(L, 1, &self, "ccb.AttributeBindInfo");
    olua_check_integer(L, 2, &arg1);

    // int size
    self->size = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_AttributeBindInfo_size(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // int size
        return _olua_fun_cocos2d_backend_AttributeBindInfo_size$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.AttributeBindInfo")) && (olua_is_integer(L, 2))) {
            // int size
            return _olua_fun_cocos2d_backend_AttributeBindInfo_size$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::AttributeBindInfo::size' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_AttributeBindInfo_type$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::AttributeBindInfo *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.AttributeBindInfo");

    // int type
    int ret = self->type;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_AttributeBindInfo_type$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::AttributeBindInfo *self = nullptr;
    int arg1 = 0;       /** type */

    olua_to_object(L, 1, &self, "ccb.AttributeBindInfo");
    olua_check_integer(L, 2, &arg1);

    // int type
    self->type = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_AttributeBindInfo_type(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // int type
        return _olua_fun_cocos2d_backend_AttributeBindInfo_type$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.AttributeBindInfo")) && (olua_is_integer(L, 2))) {
            // int type
            return _olua_fun_cocos2d_backend_AttributeBindInfo_type$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::AttributeBindInfo::type' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_ccb_AttributeBindInfo(lua_State *L)
{
    oluacls_class<cocos2d::backend::AttributeBindInfo>(L, "ccb.AttributeBindInfo");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_backend_AttributeBindInfo___gc);
    oluacls_prop(L, "attributeName", _olua_fun_cocos2d_backend_AttributeBindInfo_attributeName, _olua_fun_cocos2d_backend_AttributeBindInfo_attributeName);
    oluacls_prop(L, "location", _olua_fun_cocos2d_backend_AttributeBindInfo_location, _olua_fun_cocos2d_backend_AttributeBindInfo_location);
    oluacls_prop(L, "size", _olua_fun_cocos2d_backend_AttributeBindInfo_size, _olua_fun_cocos2d_backend_AttributeBindInfo_size);
    oluacls_prop(L, "type", _olua_fun_cocos2d_backend_AttributeBindInfo_type, _olua_fun_cocos2d_backend_AttributeBindInfo_type);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_AttributeBindInfo(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "ccb.AttributeBindInfo")) {
        luaL_error(L, "class not found: cocos2d::backend::AttributeBindInfo");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_backend_UniformInfo___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::backend::UniformInfo *)olua_toobj(L, 1, "ccb.UniformInfo");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_UniformInfo_bufferOffset$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::UniformInfo *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.UniformInfo");

    // unsigned int bufferOffset
    unsigned int ret = self->bufferOffset;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_UniformInfo_bufferOffset$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::UniformInfo *self = nullptr;
    unsigned int arg1 = 0;       /** bufferOffset */

    olua_to_object(L, 1, &self, "ccb.UniformInfo");
    olua_check_integer(L, 2, &arg1);

    // unsigned int bufferOffset
    self->bufferOffset = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_UniformInfo_bufferOffset(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // unsigned int bufferOffset
        return _olua_fun_cocos2d_backend_UniformInfo_bufferOffset$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.UniformInfo")) && (olua_is_integer(L, 2))) {
            // unsigned int bufferOffset
            return _olua_fun_cocos2d_backend_UniformInfo_bufferOffset$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::UniformInfo::bufferOffset' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_UniformInfo_count$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::UniformInfo *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.UniformInfo");

    // int count
    int ret = self->count;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_UniformInfo_count$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::UniformInfo *self = nullptr;
    int arg1 = 0;       /** count */

    olua_to_object(L, 1, &self, "ccb.UniformInfo");
    olua_check_integer(L, 2, &arg1);

    // int count
    self->count = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_UniformInfo_count(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // int count
        return _olua_fun_cocos2d_backend_UniformInfo_count$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.UniformInfo")) && (olua_is_integer(L, 2))) {
            // int count
            return _olua_fun_cocos2d_backend_UniformInfo_count$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::UniformInfo::count' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_UniformInfo_isArray$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::UniformInfo *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.UniformInfo");

    // bool isArray
    bool ret = self->isArray;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_UniformInfo_isArray$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::UniformInfo *self = nullptr;
    bool arg1 = false;       /** isArray */

    olua_to_object(L, 1, &self, "ccb.UniformInfo");
    olua_check_bool(L, 2, &arg1);

    // bool isArray
    self->isArray = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_UniformInfo_isArray(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool isArray
        return _olua_fun_cocos2d_backend_UniformInfo_isArray$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.UniformInfo")) && (olua_is_bool(L, 2))) {
            // bool isArray
            return _olua_fun_cocos2d_backend_UniformInfo_isArray$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::UniformInfo::isArray' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_UniformInfo_isMatrix$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::UniformInfo *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.UniformInfo");

    // bool isMatrix
    bool ret = self->isMatrix;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_UniformInfo_isMatrix$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::UniformInfo *self = nullptr;
    bool arg1 = false;       /** isMatrix */

    olua_to_object(L, 1, &self, "ccb.UniformInfo");
    olua_check_bool(L, 2, &arg1);

    // bool isMatrix
    self->isMatrix = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_UniformInfo_isMatrix(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool isMatrix
        return _olua_fun_cocos2d_backend_UniformInfo_isMatrix$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.UniformInfo")) && (olua_is_bool(L, 2))) {
            // bool isMatrix
            return _olua_fun_cocos2d_backend_UniformInfo_isMatrix$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::UniformInfo::isMatrix' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_UniformInfo_location$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::UniformInfo *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.UniformInfo");

    // int location
    int ret = self->location;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_UniformInfo_location$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::UniformInfo *self = nullptr;
    int arg1 = 0;       /** location */

    olua_to_object(L, 1, &self, "ccb.UniformInfo");
    olua_check_integer(L, 2, &arg1);

    // int location
    self->location = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_UniformInfo_location(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // int location
        return _olua_fun_cocos2d_backend_UniformInfo_location$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.UniformInfo")) && (olua_is_integer(L, 2))) {
            // int location
            return _olua_fun_cocos2d_backend_UniformInfo_location$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::UniformInfo::location' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_UniformInfo_needConvert$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::UniformInfo *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.UniformInfo");

    // bool needConvert
    bool ret = self->needConvert;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_UniformInfo_needConvert$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::UniformInfo *self = nullptr;
    bool arg1 = false;       /** needConvert */

    olua_to_object(L, 1, &self, "ccb.UniformInfo");
    olua_check_bool(L, 2, &arg1);

    // bool needConvert
    self->needConvert = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_UniformInfo_needConvert(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool needConvert
        return _olua_fun_cocos2d_backend_UniformInfo_needConvert$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.UniformInfo")) && (olua_is_bool(L, 2))) {
            // bool needConvert
            return _olua_fun_cocos2d_backend_UniformInfo_needConvert$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::UniformInfo::needConvert' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_UniformInfo_size$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::UniformInfo *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.UniformInfo");

    // unsigned int size
    unsigned int ret = self->size;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_UniformInfo_size$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::UniformInfo *self = nullptr;
    unsigned int arg1 = 0;       /** size */

    olua_to_object(L, 1, &self, "ccb.UniformInfo");
    olua_check_integer(L, 2, &arg1);

    // unsigned int size
    self->size = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_UniformInfo_size(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // unsigned int size
        return _olua_fun_cocos2d_backend_UniformInfo_size$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.UniformInfo")) && (olua_is_integer(L, 2))) {
            // unsigned int size
            return _olua_fun_cocos2d_backend_UniformInfo_size$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::UniformInfo::size' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_UniformInfo_type$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::UniformInfo *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.UniformInfo");

    // unsigned int type
    unsigned int ret = self->type;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_UniformInfo_type$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::UniformInfo *self = nullptr;
    unsigned int arg1 = 0;       /** type */

    olua_to_object(L, 1, &self, "ccb.UniformInfo");
    olua_check_integer(L, 2, &arg1);

    // unsigned int type
    self->type = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_UniformInfo_type(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // unsigned int type
        return _olua_fun_cocos2d_backend_UniformInfo_type$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.UniformInfo")) && (olua_is_integer(L, 2))) {
            // unsigned int type
            return _olua_fun_cocos2d_backend_UniformInfo_type$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::UniformInfo::type' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_ccb_UniformInfo(lua_State *L)
{
    oluacls_class<cocos2d::backend::UniformInfo>(L, "ccb.UniformInfo");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_backend_UniformInfo___gc);
    oluacls_prop(L, "count", _olua_fun_cocos2d_backend_UniformInfo_count, _olua_fun_cocos2d_backend_UniformInfo_count);
    oluacls_prop(L, "location", _olua_fun_cocos2d_backend_UniformInfo_location, _olua_fun_cocos2d_backend_UniformInfo_location);
    oluacls_prop(L, "type", _olua_fun_cocos2d_backend_UniformInfo_type, _olua_fun_cocos2d_backend_UniformInfo_type);
    oluacls_prop(L, "isArray", _olua_fun_cocos2d_backend_UniformInfo_isArray, _olua_fun_cocos2d_backend_UniformInfo_isArray);
    oluacls_prop(L, "size", _olua_fun_cocos2d_backend_UniformInfo_size, _olua_fun_cocos2d_backend_UniformInfo_size);
    oluacls_prop(L, "bufferOffset", _olua_fun_cocos2d_backend_UniformInfo_bufferOffset, _olua_fun_cocos2d_backend_UniformInfo_bufferOffset);
    oluacls_prop(L, "isMatrix", _olua_fun_cocos2d_backend_UniformInfo_isMatrix, _olua_fun_cocos2d_backend_UniformInfo_isMatrix);
    oluacls_prop(L, "needConvert", _olua_fun_cocos2d_backend_UniformInfo_needConvert, _olua_fun_cocos2d_backend_UniformInfo_needConvert);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_UniformInfo(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "ccb.UniformInfo")) {
        luaL_error(L, "class not found: cocos2d::backend::UniformInfo");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_backend_TextureDescriptor___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::backend::TextureDescriptor *)olua_toobj(L, 1, "ccb.TextureDescriptor");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_TextureDescriptor_depth$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.TextureDescriptor");

    // uint32_t depth
    uint32_t ret = self->depth;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_TextureDescriptor_depth$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureDescriptor *self = nullptr;
    uint32_t arg1 = 0;       /** depth */

    olua_to_object(L, 1, &self, "ccb.TextureDescriptor");
    olua_check_integer(L, 2, &arg1);

    // uint32_t depth
    self->depth = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_TextureDescriptor_depth(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // uint32_t depth
        return _olua_fun_cocos2d_backend_TextureDescriptor_depth$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.TextureDescriptor")) && (olua_is_integer(L, 2))) {
            // uint32_t depth
            return _olua_fun_cocos2d_backend_TextureDescriptor_depth$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::TextureDescriptor::depth' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_TextureDescriptor_height$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.TextureDescriptor");

    // uint32_t height
    uint32_t ret = self->height;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_TextureDescriptor_height$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureDescriptor *self = nullptr;
    uint32_t arg1 = 0;       /** height */

    olua_to_object(L, 1, &self, "ccb.TextureDescriptor");
    olua_check_integer(L, 2, &arg1);

    // uint32_t height
    self->height = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_TextureDescriptor_height(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // uint32_t height
        return _olua_fun_cocos2d_backend_TextureDescriptor_height$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.TextureDescriptor")) && (olua_is_integer(L, 2))) {
            // uint32_t height
            return _olua_fun_cocos2d_backend_TextureDescriptor_height$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::TextureDescriptor::height' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_TextureDescriptor_sampleCount$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.TextureDescriptor");

    // int sampleCount
    int ret = self->sampleCount;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_TextureDescriptor_sampleCount$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureDescriptor *self = nullptr;
    int arg1 = 0;       /** sampleCount */

    olua_to_object(L, 1, &self, "ccb.TextureDescriptor");
    olua_check_integer(L, 2, &arg1);

    // int sampleCount
    self->sampleCount = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_TextureDescriptor_sampleCount(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // int sampleCount
        return _olua_fun_cocos2d_backend_TextureDescriptor_sampleCount$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.TextureDescriptor")) && (olua_is_integer(L, 2))) {
            // int sampleCount
            return _olua_fun_cocos2d_backend_TextureDescriptor_sampleCount$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::TextureDescriptor::sampleCount' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_TextureDescriptor_samplerDescriptor$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.TextureDescriptor");

    // cocos2d::backend::SamplerDescriptor samplerDescriptor
    cocos2d::backend::SamplerDescriptor &ret = self->samplerDescriptor;
    int num_ret = olua_copy_object(L, ret, "ccb.SamplerDescriptor");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_TextureDescriptor_samplerDescriptor$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureDescriptor *self = nullptr;
    cocos2d::backend::SamplerDescriptor *arg1;       /** samplerDescriptor */

    olua_to_object(L, 1, &self, "ccb.TextureDescriptor");
    olua_check_object(L, 2, &arg1, "ccb.SamplerDescriptor");

    // cocos2d::backend::SamplerDescriptor samplerDescriptor
    self->samplerDescriptor = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_TextureDescriptor_samplerDescriptor(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::backend::SamplerDescriptor samplerDescriptor
        return _olua_fun_cocos2d_backend_TextureDescriptor_samplerDescriptor$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.TextureDescriptor")) && (olua_is_object(L, 2, "ccb.SamplerDescriptor"))) {
            // cocos2d::backend::SamplerDescriptor samplerDescriptor
            return _olua_fun_cocos2d_backend_TextureDescriptor_samplerDescriptor$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::TextureDescriptor::samplerDescriptor' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_TextureDescriptor_textureFormat$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.TextureDescriptor");

    // cocos2d::backend::PixelFormat textureFormat
    cocos2d::backend::PixelFormat ret = self->textureFormat;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_TextureDescriptor_textureFormat$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureDescriptor *self = nullptr;
    cocos2d::backend::PixelFormat arg1 = (cocos2d::backend::PixelFormat)0;       /** textureFormat */

    olua_to_object(L, 1, &self, "ccb.TextureDescriptor");
    olua_check_enum(L, 2, &arg1);

    // cocos2d::backend::PixelFormat textureFormat
    self->textureFormat = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_TextureDescriptor_textureFormat(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::backend::PixelFormat textureFormat
        return _olua_fun_cocos2d_backend_TextureDescriptor_textureFormat$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.TextureDescriptor")) && (olua_is_enum(L, 2))) {
            // cocos2d::backend::PixelFormat textureFormat
            return _olua_fun_cocos2d_backend_TextureDescriptor_textureFormat$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::TextureDescriptor::textureFormat' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_TextureDescriptor_textureType$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.TextureDescriptor");

    // cocos2d::backend::TextureType textureType
    cocos2d::backend::TextureType ret = self->textureType;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_TextureDescriptor_textureType$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureDescriptor *self = nullptr;
    cocos2d::backend::TextureType arg1 = (cocos2d::backend::TextureType)0;       /** textureType */

    olua_to_object(L, 1, &self, "ccb.TextureDescriptor");
    olua_check_enum(L, 2, &arg1);

    // cocos2d::backend::TextureType textureType
    self->textureType = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_TextureDescriptor_textureType(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::backend::TextureType textureType
        return _olua_fun_cocos2d_backend_TextureDescriptor_textureType$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.TextureDescriptor")) && (olua_is_enum(L, 2))) {
            // cocos2d::backend::TextureType textureType
            return _olua_fun_cocos2d_backend_TextureDescriptor_textureType$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::TextureDescriptor::textureType' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_TextureDescriptor_textureUsage$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.TextureDescriptor");

    // cocos2d::backend::TextureUsage textureUsage
    cocos2d::backend::TextureUsage ret = self->textureUsage;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_TextureDescriptor_textureUsage$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureDescriptor *self = nullptr;
    cocos2d::backend::TextureUsage arg1 = (cocos2d::backend::TextureUsage)0;       /** textureUsage */

    olua_to_object(L, 1, &self, "ccb.TextureDescriptor");
    olua_check_enum(L, 2, &arg1);

    // cocos2d::backend::TextureUsage textureUsage
    self->textureUsage = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_TextureDescriptor_textureUsage(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::backend::TextureUsage textureUsage
        return _olua_fun_cocos2d_backend_TextureDescriptor_textureUsage$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.TextureDescriptor")) && (olua_is_enum(L, 2))) {
            // cocos2d::backend::TextureUsage textureUsage
            return _olua_fun_cocos2d_backend_TextureDescriptor_textureUsage$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::TextureDescriptor::textureUsage' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_TextureDescriptor_width$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.TextureDescriptor");

    // uint32_t width
    uint32_t ret = self->width;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_TextureDescriptor_width$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::TextureDescriptor *self = nullptr;
    uint32_t arg1 = 0;       /** width */

    olua_to_object(L, 1, &self, "ccb.TextureDescriptor");
    olua_check_integer(L, 2, &arg1);

    // uint32_t width
    self->width = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_TextureDescriptor_width(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // uint32_t width
        return _olua_fun_cocos2d_backend_TextureDescriptor_width$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.TextureDescriptor")) && (olua_is_integer(L, 2))) {
            // uint32_t width
            return _olua_fun_cocos2d_backend_TextureDescriptor_width$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::TextureDescriptor::width' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_ccb_TextureDescriptor(lua_State *L)
{
    oluacls_class<cocos2d::backend::TextureDescriptor>(L, "ccb.TextureDescriptor");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_backend_TextureDescriptor___gc);
    oluacls_prop(L, "textureType", _olua_fun_cocos2d_backend_TextureDescriptor_textureType, _olua_fun_cocos2d_backend_TextureDescriptor_textureType);
    oluacls_prop(L, "textureFormat", _olua_fun_cocos2d_backend_TextureDescriptor_textureFormat, _olua_fun_cocos2d_backend_TextureDescriptor_textureFormat);
    oluacls_prop(L, "textureUsage", _olua_fun_cocos2d_backend_TextureDescriptor_textureUsage, _olua_fun_cocos2d_backend_TextureDescriptor_textureUsage);
    oluacls_prop(L, "width", _olua_fun_cocos2d_backend_TextureDescriptor_width, _olua_fun_cocos2d_backend_TextureDescriptor_width);
    oluacls_prop(L, "height", _olua_fun_cocos2d_backend_TextureDescriptor_height, _olua_fun_cocos2d_backend_TextureDescriptor_height);
    oluacls_prop(L, "depth", _olua_fun_cocos2d_backend_TextureDescriptor_depth, _olua_fun_cocos2d_backend_TextureDescriptor_depth);
    oluacls_prop(L, "samplerDescriptor", _olua_fun_cocos2d_backend_TextureDescriptor_samplerDescriptor, _olua_fun_cocos2d_backend_TextureDescriptor_samplerDescriptor);
    oluacls_prop(L, "sampleCount", _olua_fun_cocos2d_backend_TextureDescriptor_sampleCount, _olua_fun_cocos2d_backend_TextureDescriptor_sampleCount);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_TextureDescriptor(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "ccb.TextureDescriptor")) {
        luaL_error(L, "class not found: cocos2d::backend::TextureDescriptor");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_backend_StencilDescriptor___eq(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::StencilDescriptor *self = nullptr;
    cocos2d::backend::StencilDescriptor *arg1;       /** rhs */

    olua_to_object(L, 1, &self, "ccb.StencilDescriptor");
    olua_check_object(L, 2, &arg1, "ccb.StencilDescriptor");

    // @operator(operator==) bool operator==(const cocos2d::backend::StencilDescriptor &rhs)
    bool ret = (*self) == (*arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_StencilDescriptor___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::backend::StencilDescriptor *)olua_toobj(L, 1, "ccb.StencilDescriptor");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_StencilDescriptor_depthFailureOperation$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::StencilDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.StencilDescriptor");

    // cocos2d::backend::StencilOperation depthFailureOperation
    cocos2d::backend::StencilOperation ret = self->depthFailureOperation;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_StencilDescriptor_depthFailureOperation$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::StencilDescriptor *self = nullptr;
    cocos2d::backend::StencilOperation arg1 = (cocos2d::backend::StencilOperation)0;       /** depthFailureOperation */

    olua_to_object(L, 1, &self, "ccb.StencilDescriptor");
    olua_check_enum(L, 2, &arg1);

    // cocos2d::backend::StencilOperation depthFailureOperation
    self->depthFailureOperation = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_StencilDescriptor_depthFailureOperation(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::backend::StencilOperation depthFailureOperation
        return _olua_fun_cocos2d_backend_StencilDescriptor_depthFailureOperation$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.StencilDescriptor")) && (olua_is_enum(L, 2))) {
            // cocos2d::backend::StencilOperation depthFailureOperation
            return _olua_fun_cocos2d_backend_StencilDescriptor_depthFailureOperation$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::StencilDescriptor::depthFailureOperation' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_StencilDescriptor_depthStencilPassOperation$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::StencilDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.StencilDescriptor");

    // cocos2d::backend::StencilOperation depthStencilPassOperation
    cocos2d::backend::StencilOperation ret = self->depthStencilPassOperation;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_StencilDescriptor_depthStencilPassOperation$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::StencilDescriptor *self = nullptr;
    cocos2d::backend::StencilOperation arg1 = (cocos2d::backend::StencilOperation)0;       /** depthStencilPassOperation */

    olua_to_object(L, 1, &self, "ccb.StencilDescriptor");
    olua_check_enum(L, 2, &arg1);

    // cocos2d::backend::StencilOperation depthStencilPassOperation
    self->depthStencilPassOperation = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_StencilDescriptor_depthStencilPassOperation(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::backend::StencilOperation depthStencilPassOperation
        return _olua_fun_cocos2d_backend_StencilDescriptor_depthStencilPassOperation$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.StencilDescriptor")) && (olua_is_enum(L, 2))) {
            // cocos2d::backend::StencilOperation depthStencilPassOperation
            return _olua_fun_cocos2d_backend_StencilDescriptor_depthStencilPassOperation$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::StencilDescriptor::depthStencilPassOperation' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_StencilDescriptor_readMask$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::StencilDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.StencilDescriptor");

    // unsigned int readMask
    unsigned int ret = self->readMask;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_StencilDescriptor_readMask$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::StencilDescriptor *self = nullptr;
    unsigned int arg1 = 0;       /** readMask */

    olua_to_object(L, 1, &self, "ccb.StencilDescriptor");
    olua_check_integer(L, 2, &arg1);

    // unsigned int readMask
    self->readMask = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_StencilDescriptor_readMask(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // unsigned int readMask
        return _olua_fun_cocos2d_backend_StencilDescriptor_readMask$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.StencilDescriptor")) && (olua_is_integer(L, 2))) {
            // unsigned int readMask
            return _olua_fun_cocos2d_backend_StencilDescriptor_readMask$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::StencilDescriptor::readMask' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_StencilDescriptor_stencilCompareFunction$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::StencilDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.StencilDescriptor");

    // cocos2d::backend::CompareFunction stencilCompareFunction
    cocos2d::backend::CompareFunction ret = self->stencilCompareFunction;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_StencilDescriptor_stencilCompareFunction$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::StencilDescriptor *self = nullptr;
    cocos2d::backend::CompareFunction arg1 = (cocos2d::backend::CompareFunction)0;       /** stencilCompareFunction */

    olua_to_object(L, 1, &self, "ccb.StencilDescriptor");
    olua_check_enum(L, 2, &arg1);

    // cocos2d::backend::CompareFunction stencilCompareFunction
    self->stencilCompareFunction = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_StencilDescriptor_stencilCompareFunction(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::backend::CompareFunction stencilCompareFunction
        return _olua_fun_cocos2d_backend_StencilDescriptor_stencilCompareFunction$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.StencilDescriptor")) && (olua_is_enum(L, 2))) {
            // cocos2d::backend::CompareFunction stencilCompareFunction
            return _olua_fun_cocos2d_backend_StencilDescriptor_stencilCompareFunction$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::StencilDescriptor::stencilCompareFunction' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_StencilDescriptor_stencilFailureOperation$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::StencilDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.StencilDescriptor");

    // cocos2d::backend::StencilOperation stencilFailureOperation
    cocos2d::backend::StencilOperation ret = self->stencilFailureOperation;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_StencilDescriptor_stencilFailureOperation$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::StencilDescriptor *self = nullptr;
    cocos2d::backend::StencilOperation arg1 = (cocos2d::backend::StencilOperation)0;       /** stencilFailureOperation */

    olua_to_object(L, 1, &self, "ccb.StencilDescriptor");
    olua_check_enum(L, 2, &arg1);

    // cocos2d::backend::StencilOperation stencilFailureOperation
    self->stencilFailureOperation = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_StencilDescriptor_stencilFailureOperation(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::backend::StencilOperation stencilFailureOperation
        return _olua_fun_cocos2d_backend_StencilDescriptor_stencilFailureOperation$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.StencilDescriptor")) && (olua_is_enum(L, 2))) {
            // cocos2d::backend::StencilOperation stencilFailureOperation
            return _olua_fun_cocos2d_backend_StencilDescriptor_stencilFailureOperation$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::StencilDescriptor::stencilFailureOperation' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_StencilDescriptor_writeMask$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::StencilDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.StencilDescriptor");

    // unsigned int writeMask
    unsigned int ret = self->writeMask;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_StencilDescriptor_writeMask$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::StencilDescriptor *self = nullptr;
    unsigned int arg1 = 0;       /** writeMask */

    olua_to_object(L, 1, &self, "ccb.StencilDescriptor");
    olua_check_integer(L, 2, &arg1);

    // unsigned int writeMask
    self->writeMask = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_StencilDescriptor_writeMask(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // unsigned int writeMask
        return _olua_fun_cocos2d_backend_StencilDescriptor_writeMask$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.StencilDescriptor")) && (olua_is_integer(L, 2))) {
            // unsigned int writeMask
            return _olua_fun_cocos2d_backend_StencilDescriptor_writeMask$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::StencilDescriptor::writeMask' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_ccb_StencilDescriptor(lua_State *L)
{
    oluacls_class<cocos2d::backend::StencilDescriptor>(L, "ccb.StencilDescriptor");
    oluacls_func(L, "__eq", _olua_fun_cocos2d_backend_StencilDescriptor___eq);
    oluacls_func(L, "__gc", _olua_fun_cocos2d_backend_StencilDescriptor___gc);
    oluacls_prop(L, "stencilFailureOperation", _olua_fun_cocos2d_backend_StencilDescriptor_stencilFailureOperation, _olua_fun_cocos2d_backend_StencilDescriptor_stencilFailureOperation);
    oluacls_prop(L, "depthFailureOperation", _olua_fun_cocos2d_backend_StencilDescriptor_depthFailureOperation, _olua_fun_cocos2d_backend_StencilDescriptor_depthFailureOperation);
    oluacls_prop(L, "depthStencilPassOperation", _olua_fun_cocos2d_backend_StencilDescriptor_depthStencilPassOperation, _olua_fun_cocos2d_backend_StencilDescriptor_depthStencilPassOperation);
    oluacls_prop(L, "stencilCompareFunction", _olua_fun_cocos2d_backend_StencilDescriptor_stencilCompareFunction, _olua_fun_cocos2d_backend_StencilDescriptor_stencilCompareFunction);
    oluacls_prop(L, "readMask", _olua_fun_cocos2d_backend_StencilDescriptor_readMask, _olua_fun_cocos2d_backend_StencilDescriptor_readMask);
    oluacls_prop(L, "writeMask", _olua_fun_cocos2d_backend_StencilDescriptor_writeMask, _olua_fun_cocos2d_backend_StencilDescriptor_writeMask);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_StencilDescriptor(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "ccb.StencilDescriptor")) {
        luaL_error(L, "class not found: cocos2d::backend::StencilDescriptor");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_backend_DepthStencilDescriptor___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::backend::DepthStencilDescriptor *)olua_toobj(L, 1, "ccb.DepthStencilDescriptor");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_DepthStencilDescriptor_backFaceStencil$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DepthStencilDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.DepthStencilDescriptor");

    // cocos2d::backend::StencilDescriptor backFaceStencil
    cocos2d::backend::StencilDescriptor &ret = self->backFaceStencil;
    int num_ret = olua_copy_object(L, ret, "ccb.StencilDescriptor");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_DepthStencilDescriptor_backFaceStencil$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DepthStencilDescriptor *self = nullptr;
    cocos2d::backend::StencilDescriptor *arg1;       /** backFaceStencil */

    olua_to_object(L, 1, &self, "ccb.DepthStencilDescriptor");
    olua_check_object(L, 2, &arg1, "ccb.StencilDescriptor");

    // cocos2d::backend::StencilDescriptor backFaceStencil
    self->backFaceStencil = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_DepthStencilDescriptor_backFaceStencil(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::backend::StencilDescriptor backFaceStencil
        return _olua_fun_cocos2d_backend_DepthStencilDescriptor_backFaceStencil$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.DepthStencilDescriptor")) && (olua_is_object(L, 2, "ccb.StencilDescriptor"))) {
            // cocos2d::backend::StencilDescriptor backFaceStencil
            return _olua_fun_cocos2d_backend_DepthStencilDescriptor_backFaceStencil$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::DepthStencilDescriptor::backFaceStencil' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_DepthStencilDescriptor_depthCompareFunction$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DepthStencilDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.DepthStencilDescriptor");

    // cocos2d::backend::CompareFunction depthCompareFunction
    cocos2d::backend::CompareFunction ret = self->depthCompareFunction;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_DepthStencilDescriptor_depthCompareFunction$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DepthStencilDescriptor *self = nullptr;
    cocos2d::backend::CompareFunction arg1 = (cocos2d::backend::CompareFunction)0;       /** depthCompareFunction */

    olua_to_object(L, 1, &self, "ccb.DepthStencilDescriptor");
    olua_check_enum(L, 2, &arg1);

    // cocos2d::backend::CompareFunction depthCompareFunction
    self->depthCompareFunction = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_DepthStencilDescriptor_depthCompareFunction(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::backend::CompareFunction depthCompareFunction
        return _olua_fun_cocos2d_backend_DepthStencilDescriptor_depthCompareFunction$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.DepthStencilDescriptor")) && (olua_is_enum(L, 2))) {
            // cocos2d::backend::CompareFunction depthCompareFunction
            return _olua_fun_cocos2d_backend_DepthStencilDescriptor_depthCompareFunction$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::DepthStencilDescriptor::depthCompareFunction' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_DepthStencilDescriptor_depthTestEnabled$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DepthStencilDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.DepthStencilDescriptor");

    // bool depthTestEnabled
    bool ret = self->depthTestEnabled;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_DepthStencilDescriptor_depthTestEnabled$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DepthStencilDescriptor *self = nullptr;
    bool arg1 = false;       /** depthTestEnabled */

    olua_to_object(L, 1, &self, "ccb.DepthStencilDescriptor");
    olua_check_bool(L, 2, &arg1);

    // bool depthTestEnabled
    self->depthTestEnabled = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_DepthStencilDescriptor_depthTestEnabled(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool depthTestEnabled
        return _olua_fun_cocos2d_backend_DepthStencilDescriptor_depthTestEnabled$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.DepthStencilDescriptor")) && (olua_is_bool(L, 2))) {
            // bool depthTestEnabled
            return _olua_fun_cocos2d_backend_DepthStencilDescriptor_depthTestEnabled$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::DepthStencilDescriptor::depthTestEnabled' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_DepthStencilDescriptor_depthWriteEnabled$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DepthStencilDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.DepthStencilDescriptor");

    // bool depthWriteEnabled
    bool ret = self->depthWriteEnabled;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_DepthStencilDescriptor_depthWriteEnabled$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DepthStencilDescriptor *self = nullptr;
    bool arg1 = false;       /** depthWriteEnabled */

    olua_to_object(L, 1, &self, "ccb.DepthStencilDescriptor");
    olua_check_bool(L, 2, &arg1);

    // bool depthWriteEnabled
    self->depthWriteEnabled = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_DepthStencilDescriptor_depthWriteEnabled(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool depthWriteEnabled
        return _olua_fun_cocos2d_backend_DepthStencilDescriptor_depthWriteEnabled$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.DepthStencilDescriptor")) && (olua_is_bool(L, 2))) {
            // bool depthWriteEnabled
            return _olua_fun_cocos2d_backend_DepthStencilDescriptor_depthWriteEnabled$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::DepthStencilDescriptor::depthWriteEnabled' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_DepthStencilDescriptor_frontFaceStencil$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DepthStencilDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.DepthStencilDescriptor");

    // cocos2d::backend::StencilDescriptor frontFaceStencil
    cocos2d::backend::StencilDescriptor &ret = self->frontFaceStencil;
    int num_ret = olua_copy_object(L, ret, "ccb.StencilDescriptor");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_DepthStencilDescriptor_frontFaceStencil$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DepthStencilDescriptor *self = nullptr;
    cocos2d::backend::StencilDescriptor *arg1;       /** frontFaceStencil */

    olua_to_object(L, 1, &self, "ccb.DepthStencilDescriptor");
    olua_check_object(L, 2, &arg1, "ccb.StencilDescriptor");

    // cocos2d::backend::StencilDescriptor frontFaceStencil
    self->frontFaceStencil = *arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_DepthStencilDescriptor_frontFaceStencil(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::backend::StencilDescriptor frontFaceStencil
        return _olua_fun_cocos2d_backend_DepthStencilDescriptor_frontFaceStencil$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.DepthStencilDescriptor")) && (olua_is_object(L, 2, "ccb.StencilDescriptor"))) {
            // cocos2d::backend::StencilDescriptor frontFaceStencil
            return _olua_fun_cocos2d_backend_DepthStencilDescriptor_frontFaceStencil$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::DepthStencilDescriptor::frontFaceStencil' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_DepthStencilDescriptor_stencilTestEnabled$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DepthStencilDescriptor *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.DepthStencilDescriptor");

    // bool stencilTestEnabled
    bool ret = self->stencilTestEnabled;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_DepthStencilDescriptor_stencilTestEnabled$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::DepthStencilDescriptor *self = nullptr;
    bool arg1 = false;       /** stencilTestEnabled */

    olua_to_object(L, 1, &self, "ccb.DepthStencilDescriptor");
    olua_check_bool(L, 2, &arg1);

    // bool stencilTestEnabled
    self->stencilTestEnabled = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_DepthStencilDescriptor_stencilTestEnabled(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool stencilTestEnabled
        return _olua_fun_cocos2d_backend_DepthStencilDescriptor_stencilTestEnabled$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.DepthStencilDescriptor")) && (olua_is_bool(L, 2))) {
            // bool stencilTestEnabled
            return _olua_fun_cocos2d_backend_DepthStencilDescriptor_stencilTestEnabled$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::DepthStencilDescriptor::stencilTestEnabled' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_ccb_DepthStencilDescriptor(lua_State *L)
{
    oluacls_class<cocos2d::backend::DepthStencilDescriptor>(L, "ccb.DepthStencilDescriptor");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_backend_DepthStencilDescriptor___gc);
    oluacls_prop(L, "depthCompareFunction", _olua_fun_cocos2d_backend_DepthStencilDescriptor_depthCompareFunction, _olua_fun_cocos2d_backend_DepthStencilDescriptor_depthCompareFunction);
    oluacls_prop(L, "depthWriteEnabled", _olua_fun_cocos2d_backend_DepthStencilDescriptor_depthWriteEnabled, _olua_fun_cocos2d_backend_DepthStencilDescriptor_depthWriteEnabled);
    oluacls_prop(L, "depthTestEnabled", _olua_fun_cocos2d_backend_DepthStencilDescriptor_depthTestEnabled, _olua_fun_cocos2d_backend_DepthStencilDescriptor_depthTestEnabled);
    oluacls_prop(L, "stencilTestEnabled", _olua_fun_cocos2d_backend_DepthStencilDescriptor_stencilTestEnabled, _olua_fun_cocos2d_backend_DepthStencilDescriptor_stencilTestEnabled);
    oluacls_prop(L, "backFaceStencil", _olua_fun_cocos2d_backend_DepthStencilDescriptor_backFaceStencil, _olua_fun_cocos2d_backend_DepthStencilDescriptor_backFaceStencil);
    oluacls_prop(L, "frontFaceStencil", _olua_fun_cocos2d_backend_DepthStencilDescriptor_frontFaceStencil, _olua_fun_cocos2d_backend_DepthStencilDescriptor_frontFaceStencil);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_DepthStencilDescriptor(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "ccb.DepthStencilDescriptor")) {
        luaL_error(L, "class not found: cocos2d::backend::DepthStencilDescriptor");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_backend_VertexLayout_Attribute___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cocos2d::backend::VertexLayout::Attribute *)olua_toobj(L, 1, "ccb.VertexLayout.Attribute");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_VertexLayout_Attribute_format$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::VertexLayout::Attribute *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.VertexLayout.Attribute");

    // cocos2d::backend::VertexFormat format
    cocos2d::backend::VertexFormat ret = self->format;
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_VertexLayout_Attribute_format$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::VertexLayout::Attribute *self = nullptr;
    cocos2d::backend::VertexFormat arg1 = (cocos2d::backend::VertexFormat)0;       /** format */

    olua_to_object(L, 1, &self, "ccb.VertexLayout.Attribute");
    olua_check_enum(L, 2, &arg1);

    // cocos2d::backend::VertexFormat format
    self->format = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_VertexLayout_Attribute_format(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // cocos2d::backend::VertexFormat format
        return _olua_fun_cocos2d_backend_VertexLayout_Attribute_format$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.VertexLayout.Attribute")) && (olua_is_enum(L, 2))) {
            // cocos2d::backend::VertexFormat format
            return _olua_fun_cocos2d_backend_VertexLayout_Attribute_format$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::VertexLayout::Attribute::format' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_VertexLayout_Attribute_index$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::VertexLayout::Attribute *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.VertexLayout.Attribute");

    // std::size_t index
    std::size_t ret = self->index;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_VertexLayout_Attribute_index$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::VertexLayout::Attribute *self = nullptr;
    std::size_t arg1 = 0;       /** index */

    olua_to_object(L, 1, &self, "ccb.VertexLayout.Attribute");
    olua_check_integer(L, 2, &arg1);

    // std::size_t index
    self->index = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_VertexLayout_Attribute_index(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::size_t index
        return _olua_fun_cocos2d_backend_VertexLayout_Attribute_index$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.VertexLayout.Attribute")) && (olua_is_integer(L, 2))) {
            // std::size_t index
            return _olua_fun_cocos2d_backend_VertexLayout_Attribute_index$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::VertexLayout::Attribute::index' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_VertexLayout_Attribute_name$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::VertexLayout::Attribute *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.VertexLayout.Attribute");

    // std::string name
    std::string ret = self->name;
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_VertexLayout_Attribute_name$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::VertexLayout::Attribute *self = nullptr;
    std::string arg1;       /** name */

    olua_to_object(L, 1, &self, "ccb.VertexLayout.Attribute");
    olua_check_string(L, 2, &arg1);

    // std::string name
    self->name = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_VertexLayout_Attribute_name(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::string name
        return _olua_fun_cocos2d_backend_VertexLayout_Attribute_name$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.VertexLayout.Attribute")) && (olua_is_string(L, 2))) {
            // std::string name
            return _olua_fun_cocos2d_backend_VertexLayout_Attribute_name$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::VertexLayout::Attribute::name' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_VertexLayout_Attribute_needToBeNormallized$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::VertexLayout::Attribute *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.VertexLayout.Attribute");

    // bool needToBeNormallized
    bool ret = self->needToBeNormallized;
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_VertexLayout_Attribute_needToBeNormallized$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::VertexLayout::Attribute *self = nullptr;
    bool arg1 = false;       /** needToBeNormallized */

    olua_to_object(L, 1, &self, "ccb.VertexLayout.Attribute");
    olua_check_bool(L, 2, &arg1);

    // bool needToBeNormallized
    self->needToBeNormallized = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_VertexLayout_Attribute_needToBeNormallized(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // bool needToBeNormallized
        return _olua_fun_cocos2d_backend_VertexLayout_Attribute_needToBeNormallized$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.VertexLayout.Attribute")) && (olua_is_bool(L, 2))) {
            // bool needToBeNormallized
            return _olua_fun_cocos2d_backend_VertexLayout_Attribute_needToBeNormallized$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::VertexLayout::Attribute::needToBeNormallized' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_VertexLayout_Attribute_new$1(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::backend::VertexLayout::Attribute()
    cocos2d::backend::VertexLayout::Attribute *ret = new cocos2d::backend::VertexLayout::Attribute();
    int num_ret = olua_push_object(L, ret, "ccb.VertexLayout.Attribute");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_VertexLayout_Attribute_new$2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** _name */
    std::size_t arg2 = 0;       /** _index */
    cocos2d::backend::VertexFormat arg3 = (cocos2d::backend::VertexFormat)0;       /** _format */
    std::size_t arg4 = 0;       /** _offset */
    bool arg5 = false;       /** needToBeNormallized */

    olua_check_string(L, 1, &arg1);
    olua_check_integer(L, 2, &arg2);
    olua_check_enum(L, 3, &arg3);
    olua_check_integer(L, 4, &arg4);
    olua_check_bool(L, 5, &arg5);

    // cocos2d::backend::VertexLayout::Attribute(const std::string &_name, std::size_t _index, cocos2d::backend::VertexFormat _format, std::size_t _offset, bool needToBeNormallized)
    cocos2d::backend::VertexLayout::Attribute *ret = new cocos2d::backend::VertexLayout::Attribute(arg1, arg2, arg3, arg4, arg5);
    int num_ret = olua_push_object(L, ret, "ccb.VertexLayout.Attribute");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_VertexLayout_Attribute_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // cocos2d::backend::VertexLayout::Attribute()
        return _olua_fun_cocos2d_backend_VertexLayout_Attribute_new$1(L);
    }

    if (num_args == 5) {
        // if ((olua_is_string(L, 1)) && (olua_is_integer(L, 2)) && (olua_is_enum(L, 3)) && (olua_is_integer(L, 4)) && (olua_is_bool(L, 5))) {
            // cocos2d::backend::VertexLayout::Attribute(const std::string &_name, std::size_t _index, cocos2d::backend::VertexFormat _format, std::size_t _offset, bool needToBeNormallized)
            return _olua_fun_cocos2d_backend_VertexLayout_Attribute_new$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::VertexLayout::Attribute::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_backend_VertexLayout_Attribute_offset$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::VertexLayout::Attribute *self = nullptr;

    olua_to_object(L, 1, &self, "ccb.VertexLayout.Attribute");

    // std::size_t offset
    std::size_t ret = self->offset;
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_backend_VertexLayout_Attribute_offset$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::backend::VertexLayout::Attribute *self = nullptr;
    std::size_t arg1 = 0;       /** offset */

    olua_to_object(L, 1, &self, "ccb.VertexLayout.Attribute");
    olua_check_integer(L, 2, &arg1);

    // std::size_t offset
    self->offset = arg1;

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_backend_VertexLayout_Attribute_offset(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // std::size_t offset
        return _olua_fun_cocos2d_backend_VertexLayout_Attribute_offset$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "ccb.VertexLayout.Attribute")) && (olua_is_integer(L, 2))) {
            // std::size_t offset
            return _olua_fun_cocos2d_backend_VertexLayout_Attribute_offset$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::backend::VertexLayout::Attribute::offset' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_ccb_VertexLayout_Attribute(lua_State *L)
{
    oluacls_class<cocos2d::backend::VertexLayout::Attribute>(L, "ccb.VertexLayout.Attribute");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_backend_VertexLayout_Attribute___gc);
    oluacls_func(L, "new", _olua_fun_cocos2d_backend_VertexLayout_Attribute_new);
    oluacls_prop(L, "name", _olua_fun_cocos2d_backend_VertexLayout_Attribute_name, _olua_fun_cocos2d_backend_VertexLayout_Attribute_name);
    oluacls_prop(L, "format", _olua_fun_cocos2d_backend_VertexLayout_Attribute_format, _olua_fun_cocos2d_backend_VertexLayout_Attribute_format);
    oluacls_prop(L, "offset", _olua_fun_cocos2d_backend_VertexLayout_Attribute_offset, _olua_fun_cocos2d_backend_VertexLayout_Attribute_offset);
    oluacls_prop(L, "index", _olua_fun_cocos2d_backend_VertexLayout_Attribute_index, _olua_fun_cocos2d_backend_VertexLayout_Attribute_index);
    oluacls_prop(L, "needToBeNormallized", _olua_fun_cocos2d_backend_VertexLayout_Attribute_needToBeNormallized, _olua_fun_cocos2d_backend_VertexLayout_Attribute_needToBeNormallized);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_ccb_VertexLayout_Attribute(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "ccb.VertexLayout.Attribute")) {
        luaL_error(L, "class not found: cocos2d::backend::VertexLayout::Attribute");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_types_VectorString___gc(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::VectorString *self = nullptr;

    olua_to_object(L, 1, &self, "cc.types.VectorString");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_cocos2d_types_VectorString___index(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::VectorString *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "cc.types.VectorString");
    olua_check_integer(L, 2, &arg1);

    // std::vector<std::string> __index(unsigned int idx)
    std::vector<std::string> ret = self->__index(arg1);
    int num_ret = olua_push_array<std::string>(L, ret, [L](std::string &arg1) {
        olua_push_string(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_VectorString___newindex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::VectorString *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    std::vector<std::string> arg2;       /** v */

    olua_to_object(L, 1, &self, "cc.types.VectorString");
    olua_check_integer(L, 2, &arg1);
    olua_check_array<std::string>(L, 3, arg2, [L](std::string *arg1) {
        olua_check_string(L, -1, arg1);
    });

    // void __newindex(unsigned int idx, const std::vector<std::string> &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_types_VectorString_buffer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::VectorString *self = nullptr;

    olua_to_object(L, 1, &self, "cc.types.VectorString");

    // @getter @type(void *) std::vector<std::string> *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_VectorString_length(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::VectorString *self = nullptr;

    olua_to_object(L, 1, &self, "cc.types.VectorString");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_VectorString_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // cocos2d::types::VectorString(@optional size_t len)
    cocos2d::types::VectorString *ret = new cocos2d::types::VectorString(arg1);
    int num_ret = olua_push_object(L, ret, "cc.types.VectorString");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_VectorString_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::types::VectorString()
    cocos2d::types::VectorString *ret = new cocos2d::types::VectorString();
    int num_ret = olua_push_object(L, ret, "cc.types.VectorString");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_VectorString_new$3(lua_State *L)
{
    olua_startinvoke(L);

    std::vector<std::string> *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_pointer(L, 1, &arg1, "cc.types.VectorString");
    olua_check_integer(L, 2, &arg2);

    // cocos2d::types::VectorString(std::vector<std::string> *v, @optional size_t len)
    cocos2d::types::VectorString *ret = new cocos2d::types::VectorString(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.types.VectorString");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_VectorString_new$4(lua_State *L)
{
    olua_startinvoke(L);

    std::vector<std::string> *arg1 = nullptr;       /** v */

    olua_check_pointer(L, 1, &arg1, "cc.types.VectorString");

    // cocos2d::types::VectorString(std::vector<std::string> *v)
    cocos2d::types::VectorString *ret = new cocos2d::types::VectorString(arg1);
    int num_ret = olua_push_object(L, ret, "cc.types.VectorString");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_VectorString_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // cocos2d::types::VectorString()
        return _olua_fun_cocos2d_types_VectorString_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // cocos2d::types::VectorString(@optional size_t len)
            return _olua_fun_cocos2d_types_VectorString_new$1(L);
        }

        // if ((olua_is_pointer(L, 1, "cc.types.VectorString"))) {
            // cocos2d::types::VectorString(std::vector<std::string> *v)
            return _olua_fun_cocos2d_types_VectorString_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_pointer(L, 1, "cc.types.VectorString")) && (olua_is_integer(L, 2))) {
            // cocos2d::types::VectorString(std::vector<std::string> *v, @optional size_t len)
            return _olua_fun_cocos2d_types_VectorString_new$3(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::types::VectorString::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_types_VectorString_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::VectorString *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "cc.types.VectorString");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew cocos2d::types::VectorString *slice(size_t from, @optional size_t to)
    cocos2d::types::VectorString *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.types.VectorString");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_VectorString_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::VectorString *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "cc.types.VectorString");
    olua_check_integer(L, 2, &arg1);

    // @postnew cocos2d::types::VectorString *slice(size_t from)
    cocos2d::types::VectorString *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "cc.types.VectorString");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_VectorString_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.types.VectorString")) && (olua_is_integer(L, 2))) {
            // @postnew cocos2d::types::VectorString *slice(size_t from)
            return _olua_fun_cocos2d_types_VectorString_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.types.VectorString")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew cocos2d::types::VectorString *slice(size_t from, @optional size_t to)
            return _olua_fun_cocos2d_types_VectorString_slice$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::types::VectorString::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_types_VectorString_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::VectorString *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "cc.types.VectorString");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew cocos2d::types::VectorString *sub(size_t from, @optional size_t to)
    cocos2d::types::VectorString *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.types.VectorString");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_VectorString_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::VectorString *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "cc.types.VectorString");
    olua_check_integer(L, 2, &arg1);

    // @postnew cocos2d::types::VectorString *sub(size_t from)
    cocos2d::types::VectorString *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "cc.types.VectorString");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_VectorString_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.types.VectorString")) && (olua_is_integer(L, 2))) {
            // @postnew cocos2d::types::VectorString *sub(size_t from)
            return _olua_fun_cocos2d_types_VectorString_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.types.VectorString")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew cocos2d::types::VectorString *sub(size_t from, @optional size_t to)
            return _olua_fun_cocos2d_types_VectorString_sub$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::types::VectorString::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_types_VectorString_take(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::VectorString *self = nullptr;

    olua_to_object(L, 1, &self, "cc.types.VectorString");

    // cocos2d::types::VectorString *take()
    cocos2d::types::VectorString *ret = self->take();
    int num_ret = olua_push_object(L, ret, "cc.types.VectorString");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_VectorString_tostring(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::VectorString *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "cc.types.VectorString");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_cocos2d_types_VectorString_value$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::VectorString *self = nullptr;

    olua_to_object(L, 1, &self, "cc.types.VectorString");

    // @getter const std::vector<std::string> &value()
    const std::vector<std::string> &ret = self->value();
    int num_ret = olua_push_array<std::string>(L, ret, [L](std::string &arg1) {
        olua_push_string(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_VectorString_value$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::VectorString *self = nullptr;
    std::vector<std::string> arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.types.VectorString");
    olua_check_array<std::string>(L, 2, arg1, [L](std::string *arg1) {
        olua_check_string(L, -1, arg1);
    });

    // @setter void value(const std::vector<std::string> &v)
    self->value(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_types_VectorString_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const std::vector<std::string> &value()
        return _olua_fun_cocos2d_types_VectorString_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.types.VectorString")) && (olua_is_array(L, 2))) {
            // @setter void value(const std::vector<std::string> &v)
            return _olua_fun_cocos2d_types_VectorString_value$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::types::VectorString::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_cc_types_VectorString(lua_State *L)
{
    oluacls_class<cocos2d::types::VectorString>(L, "cc.types.VectorString");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_types_VectorString___gc);
    oluacls_func(L, "__index", _olua_fun_cocos2d_types_VectorString___index);
    oluacls_func(L, "__newindex", _olua_fun_cocos2d_types_VectorString___newindex);
    oluacls_func(L, "new", _olua_fun_cocos2d_types_VectorString_new);
    oluacls_func(L, "slice", _olua_fun_cocos2d_types_VectorString_slice);
    oluacls_func(L, "sub", _olua_fun_cocos2d_types_VectorString_sub);
    oluacls_func(L, "take", _olua_fun_cocos2d_types_VectorString_take);
    oluacls_func(L, "tostring", _olua_fun_cocos2d_types_VectorString_tostring);
    oluacls_prop(L, "buffer", _olua_fun_cocos2d_types_VectorString_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_cocos2d_types_VectorString_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_cocos2d_types_VectorString_value, _olua_fun_cocos2d_types_VectorString_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cc_types_VectorString(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "cc.types.VectorString")) {
        luaL_error(L, "class not found: cocos2d::types::VectorString");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_types_VectorInt___gc(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::VectorInt *self = nullptr;

    olua_to_object(L, 1, &self, "cc.types.VectorInt");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_cocos2d_types_VectorInt___index(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::VectorInt *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "cc.types.VectorInt");
    olua_check_integer(L, 2, &arg1);

    // std::vector<int> __index(unsigned int idx)
    std::vector<int> ret = self->__index(arg1);
    int num_ret = olua_push_array<int>(L, ret, [L](int &arg1) {
        olua_push_integer(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_VectorInt___newindex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::VectorInt *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    std::vector<int> arg2;       /** v */

    olua_to_object(L, 1, &self, "cc.types.VectorInt");
    olua_check_integer(L, 2, &arg1);
    olua_check_array<int>(L, 3, arg2, [L](int *arg1) {
        olua_check_integer(L, -1, arg1);
    });

    // void __newindex(unsigned int idx, const std::vector<int> &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_types_VectorInt_buffer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::VectorInt *self = nullptr;

    olua_to_object(L, 1, &self, "cc.types.VectorInt");

    // @getter @type(void *) std::vector<int> *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_VectorInt_length(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::VectorInt *self = nullptr;

    olua_to_object(L, 1, &self, "cc.types.VectorInt");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_VectorInt_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // cocos2d::types::VectorInt(@optional size_t len)
    cocos2d::types::VectorInt *ret = new cocos2d::types::VectorInt(arg1);
    int num_ret = olua_push_object(L, ret, "cc.types.VectorInt");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_VectorInt_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::types::VectorInt()
    cocos2d::types::VectorInt *ret = new cocos2d::types::VectorInt();
    int num_ret = olua_push_object(L, ret, "cc.types.VectorInt");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_VectorInt_new$3(lua_State *L)
{
    olua_startinvoke(L);

    std::vector<int> *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_pointer(L, 1, &arg1, "cc.types.VectorInt");
    olua_check_integer(L, 2, &arg2);

    // cocos2d::types::VectorInt(std::vector<int> *v, @optional size_t len)
    cocos2d::types::VectorInt *ret = new cocos2d::types::VectorInt(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.types.VectorInt");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_VectorInt_new$4(lua_State *L)
{
    olua_startinvoke(L);

    std::vector<int> *arg1 = nullptr;       /** v */

    olua_check_pointer(L, 1, &arg1, "cc.types.VectorInt");

    // cocos2d::types::VectorInt(std::vector<int> *v)
    cocos2d::types::VectorInt *ret = new cocos2d::types::VectorInt(arg1);
    int num_ret = olua_push_object(L, ret, "cc.types.VectorInt");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_VectorInt_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // cocos2d::types::VectorInt()
        return _olua_fun_cocos2d_types_VectorInt_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // cocos2d::types::VectorInt(@optional size_t len)
            return _olua_fun_cocos2d_types_VectorInt_new$1(L);
        }

        // if ((olua_is_pointer(L, 1, "cc.types.VectorInt"))) {
            // cocos2d::types::VectorInt(std::vector<int> *v)
            return _olua_fun_cocos2d_types_VectorInt_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_pointer(L, 1, "cc.types.VectorInt")) && (olua_is_integer(L, 2))) {
            // cocos2d::types::VectorInt(std::vector<int> *v, @optional size_t len)
            return _olua_fun_cocos2d_types_VectorInt_new$3(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::types::VectorInt::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_types_VectorInt_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::VectorInt *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "cc.types.VectorInt");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew cocos2d::types::VectorInt *slice(size_t from, @optional size_t to)
    cocos2d::types::VectorInt *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.types.VectorInt");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_VectorInt_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::VectorInt *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "cc.types.VectorInt");
    olua_check_integer(L, 2, &arg1);

    // @postnew cocos2d::types::VectorInt *slice(size_t from)
    cocos2d::types::VectorInt *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "cc.types.VectorInt");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_VectorInt_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.types.VectorInt")) && (olua_is_integer(L, 2))) {
            // @postnew cocos2d::types::VectorInt *slice(size_t from)
            return _olua_fun_cocos2d_types_VectorInt_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.types.VectorInt")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew cocos2d::types::VectorInt *slice(size_t from, @optional size_t to)
            return _olua_fun_cocos2d_types_VectorInt_slice$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::types::VectorInt::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_types_VectorInt_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::VectorInt *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "cc.types.VectorInt");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew cocos2d::types::VectorInt *sub(size_t from, @optional size_t to)
    cocos2d::types::VectorInt *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.types.VectorInt");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_VectorInt_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::VectorInt *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "cc.types.VectorInt");
    olua_check_integer(L, 2, &arg1);

    // @postnew cocos2d::types::VectorInt *sub(size_t from)
    cocos2d::types::VectorInt *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "cc.types.VectorInt");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_VectorInt_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.types.VectorInt")) && (olua_is_integer(L, 2))) {
            // @postnew cocos2d::types::VectorInt *sub(size_t from)
            return _olua_fun_cocos2d_types_VectorInt_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.types.VectorInt")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew cocos2d::types::VectorInt *sub(size_t from, @optional size_t to)
            return _olua_fun_cocos2d_types_VectorInt_sub$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::types::VectorInt::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_types_VectorInt_take(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::VectorInt *self = nullptr;

    olua_to_object(L, 1, &self, "cc.types.VectorInt");

    // cocos2d::types::VectorInt *take()
    cocos2d::types::VectorInt *ret = self->take();
    int num_ret = olua_push_object(L, ret, "cc.types.VectorInt");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_VectorInt_tostring(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::VectorInt *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "cc.types.VectorInt");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_cocos2d_types_VectorInt_value$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::VectorInt *self = nullptr;

    olua_to_object(L, 1, &self, "cc.types.VectorInt");

    // @getter const std::vector<int> &value()
    const std::vector<int> &ret = self->value();
    int num_ret = olua_push_array<int>(L, ret, [L](int &arg1) {
        olua_push_integer(L, arg1);
    });

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_VectorInt_value$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::VectorInt *self = nullptr;
    std::vector<int> arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.types.VectorInt");
    olua_check_array<int>(L, 2, arg1, [L](int *arg1) {
        olua_check_integer(L, -1, arg1);
    });

    // @setter void value(const std::vector<int> &v)
    self->value(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_types_VectorInt_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const std::vector<int> &value()
        return _olua_fun_cocos2d_types_VectorInt_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.types.VectorInt")) && (olua_is_array(L, 2))) {
            // @setter void value(const std::vector<int> &v)
            return _olua_fun_cocos2d_types_VectorInt_value$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::types::VectorInt::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_cc_types_VectorInt(lua_State *L)
{
    oluacls_class<cocos2d::types::VectorInt>(L, "cc.types.VectorInt");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_types_VectorInt___gc);
    oluacls_func(L, "__index", _olua_fun_cocos2d_types_VectorInt___index);
    oluacls_func(L, "__newindex", _olua_fun_cocos2d_types_VectorInt___newindex);
    oluacls_func(L, "new", _olua_fun_cocos2d_types_VectorInt_new);
    oluacls_func(L, "slice", _olua_fun_cocos2d_types_VectorInt_slice);
    oluacls_func(L, "sub", _olua_fun_cocos2d_types_VectorInt_sub);
    oluacls_func(L, "take", _olua_fun_cocos2d_types_VectorInt_take);
    oluacls_func(L, "tostring", _olua_fun_cocos2d_types_VectorInt_tostring);
    oluacls_prop(L, "buffer", _olua_fun_cocos2d_types_VectorInt_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_cocos2d_types_VectorInt_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_cocos2d_types_VectorInt_value, _olua_fun_cocos2d_types_VectorInt_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cc_types_VectorInt(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "cc.types.VectorInt")) {
        luaL_error(L, "class not found: cocos2d::types::VectorInt");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_types_ValueMap___gc(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::ValueMap *self = nullptr;

    olua_to_object(L, 1, &self, "cc.types.ValueMap");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_cocos2d_types_ValueMap___index(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::ValueMap *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "cc.types.ValueMap");
    olua_check_integer(L, 2, &arg1);

    // cocos2d::ValueMap __index(unsigned int idx)
    cocos2d::ValueMap ret = self->__index(arg1);
    int num_ret = olua_push_cocos2d_ValueMap(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_ValueMap___newindex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::ValueMap *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    cocos2d::ValueMap arg2;       /** v */

    olua_to_object(L, 1, &self, "cc.types.ValueMap");
    olua_check_integer(L, 2, &arg1);
    olua_check_cocos2d_ValueMap(L, 3, &arg2);

    // void __newindex(unsigned int idx, const cocos2d::ValueMap &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_types_ValueMap_buffer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::ValueMap *self = nullptr;

    olua_to_object(L, 1, &self, "cc.types.ValueMap");

    // @getter @type(void *) cocos2d::ValueMap *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_ValueMap_length(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::ValueMap *self = nullptr;

    olua_to_object(L, 1, &self, "cc.types.ValueMap");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_ValueMap_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // cocos2d::types::ValueMap(@optional size_t len)
    cocos2d::types::ValueMap *ret = new cocos2d::types::ValueMap(arg1);
    int num_ret = olua_push_object(L, ret, "cc.types.ValueMap");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_ValueMap_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::types::ValueMap()
    cocos2d::types::ValueMap *ret = new cocos2d::types::ValueMap();
    int num_ret = olua_push_object(L, ret, "cc.types.ValueMap");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_ValueMap_new$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ValueMap *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_pointer(L, 1, &arg1, "cc.types.ValueMap");
    olua_check_integer(L, 2, &arg2);

    // cocos2d::types::ValueMap(cocos2d::ValueMap *v, @optional size_t len)
    cocos2d::types::ValueMap *ret = new cocos2d::types::ValueMap(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.types.ValueMap");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_ValueMap_new$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ValueMap *arg1 = nullptr;       /** v */

    olua_check_pointer(L, 1, &arg1, "cc.types.ValueMap");

    // cocos2d::types::ValueMap(cocos2d::ValueMap *v)
    cocos2d::types::ValueMap *ret = new cocos2d::types::ValueMap(arg1);
    int num_ret = olua_push_object(L, ret, "cc.types.ValueMap");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_ValueMap_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // cocos2d::types::ValueMap()
        return _olua_fun_cocos2d_types_ValueMap_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // cocos2d::types::ValueMap(@optional size_t len)
            return _olua_fun_cocos2d_types_ValueMap_new$1(L);
        }

        // if ((olua_is_pointer(L, 1, "cc.types.ValueMap"))) {
            // cocos2d::types::ValueMap(cocos2d::ValueMap *v)
            return _olua_fun_cocos2d_types_ValueMap_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_pointer(L, 1, "cc.types.ValueMap")) && (olua_is_integer(L, 2))) {
            // cocos2d::types::ValueMap(cocos2d::ValueMap *v, @optional size_t len)
            return _olua_fun_cocos2d_types_ValueMap_new$3(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::types::ValueMap::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_types_ValueMap_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::ValueMap *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "cc.types.ValueMap");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew cocos2d::types::ValueMap *slice(size_t from, @optional size_t to)
    cocos2d::types::ValueMap *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.types.ValueMap");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_ValueMap_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::ValueMap *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "cc.types.ValueMap");
    olua_check_integer(L, 2, &arg1);

    // @postnew cocos2d::types::ValueMap *slice(size_t from)
    cocos2d::types::ValueMap *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "cc.types.ValueMap");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_ValueMap_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.types.ValueMap")) && (olua_is_integer(L, 2))) {
            // @postnew cocos2d::types::ValueMap *slice(size_t from)
            return _olua_fun_cocos2d_types_ValueMap_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.types.ValueMap")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew cocos2d::types::ValueMap *slice(size_t from, @optional size_t to)
            return _olua_fun_cocos2d_types_ValueMap_slice$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::types::ValueMap::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_types_ValueMap_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::ValueMap *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "cc.types.ValueMap");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew cocos2d::types::ValueMap *sub(size_t from, @optional size_t to)
    cocos2d::types::ValueMap *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.types.ValueMap");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_ValueMap_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::ValueMap *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "cc.types.ValueMap");
    olua_check_integer(L, 2, &arg1);

    // @postnew cocos2d::types::ValueMap *sub(size_t from)
    cocos2d::types::ValueMap *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "cc.types.ValueMap");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_ValueMap_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.types.ValueMap")) && (olua_is_integer(L, 2))) {
            // @postnew cocos2d::types::ValueMap *sub(size_t from)
            return _olua_fun_cocos2d_types_ValueMap_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.types.ValueMap")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew cocos2d::types::ValueMap *sub(size_t from, @optional size_t to)
            return _olua_fun_cocos2d_types_ValueMap_sub$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::types::ValueMap::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_types_ValueMap_take(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::ValueMap *self = nullptr;

    olua_to_object(L, 1, &self, "cc.types.ValueMap");

    // cocos2d::types::ValueMap *take()
    cocos2d::types::ValueMap *ret = self->take();
    int num_ret = olua_push_object(L, ret, "cc.types.ValueMap");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_ValueMap_tostring(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::ValueMap *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "cc.types.ValueMap");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_cocos2d_types_ValueMap_value$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::ValueMap *self = nullptr;

    olua_to_object(L, 1, &self, "cc.types.ValueMap");

    // @getter const cocos2d::ValueMap &value()
    const cocos2d::ValueMap &ret = self->value();
    int num_ret = olua_push_cocos2d_ValueMap(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_ValueMap_value$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::ValueMap *self = nullptr;
    cocos2d::ValueMap arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.types.ValueMap");
    olua_check_cocos2d_ValueMap(L, 2, &arg1);

    // @setter void value(const cocos2d::ValueMap &v)
    self->value(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_types_ValueMap_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const cocos2d::ValueMap &value()
        return _olua_fun_cocos2d_types_ValueMap_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.types.ValueMap")) && (olua_is_cocos2d_ValueMap(L, 2))) {
            // @setter void value(const cocos2d::ValueMap &v)
            return _olua_fun_cocos2d_types_ValueMap_value$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::types::ValueMap::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_cc_types_ValueMap(lua_State *L)
{
    oluacls_class<cocos2d::types::ValueMap>(L, "cc.types.ValueMap");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_types_ValueMap___gc);
    oluacls_func(L, "__index", _olua_fun_cocos2d_types_ValueMap___index);
    oluacls_func(L, "__newindex", _olua_fun_cocos2d_types_ValueMap___newindex);
    oluacls_func(L, "new", _olua_fun_cocos2d_types_ValueMap_new);
    oluacls_func(L, "slice", _olua_fun_cocos2d_types_ValueMap_slice);
    oluacls_func(L, "sub", _olua_fun_cocos2d_types_ValueMap_sub);
    oluacls_func(L, "take", _olua_fun_cocos2d_types_ValueMap_take);
    oluacls_func(L, "tostring", _olua_fun_cocos2d_types_ValueMap_tostring);
    oluacls_prop(L, "buffer", _olua_fun_cocos2d_types_ValueMap_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_cocos2d_types_ValueMap_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_cocos2d_types_ValueMap_value, _olua_fun_cocos2d_types_ValueMap_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cc_types_ValueMap(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "cc.types.ValueMap")) {
        luaL_error(L, "class not found: cocos2d::types::ValueMap");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_types_TMXTileFlags___gc(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::TMXTileFlags *self = nullptr;

    olua_to_object(L, 1, &self, "cc.types.TMXTileFlags");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_cocos2d_types_TMXTileFlags___index(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::TMXTileFlags *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "cc.types.TMXTileFlags");
    olua_check_integer(L, 2, &arg1);

    // cocos2d::TMXTileFlags __index(unsigned int idx)
    cocos2d::TMXTileFlags ret = self->__index(arg1);
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_TMXTileFlags___newindex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::TMXTileFlags *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    cocos2d::TMXTileFlags arg2 = (cocos2d::TMXTileFlags)0;       /** v */

    olua_to_object(L, 1, &self, "cc.types.TMXTileFlags");
    olua_check_integer(L, 2, &arg1);
    olua_check_enum(L, 3, &arg2);

    // void __newindex(unsigned int idx, const cocos2d::TMXTileFlags &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_types_TMXTileFlags_buffer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::TMXTileFlags *self = nullptr;

    olua_to_object(L, 1, &self, "cc.types.TMXTileFlags");

    // @getter @type(void *) cocos2d::TMXTileFlags *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_TMXTileFlags_length(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::TMXTileFlags *self = nullptr;

    olua_to_object(L, 1, &self, "cc.types.TMXTileFlags");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_TMXTileFlags_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // cocos2d::types::TMXTileFlags(@optional size_t len)
    cocos2d::types::TMXTileFlags *ret = new cocos2d::types::TMXTileFlags(arg1);
    int num_ret = olua_push_object(L, ret, "cc.types.TMXTileFlags");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_TMXTileFlags_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::types::TMXTileFlags()
    cocos2d::types::TMXTileFlags *ret = new cocos2d::types::TMXTileFlags();
    int num_ret = olua_push_object(L, ret, "cc.types.TMXTileFlags");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_TMXTileFlags_new$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TMXTileFlags *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_pointer(L, 1, &arg1, "cc.types.TMXTileFlags");
    olua_check_integer(L, 2, &arg2);

    // cocos2d::types::TMXTileFlags(cocos2d::TMXTileFlags *v, @optional size_t len)
    cocos2d::types::TMXTileFlags *ret = new cocos2d::types::TMXTileFlags(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.types.TMXTileFlags");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_TMXTileFlags_new$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::TMXTileFlags *arg1 = nullptr;       /** v */

    olua_check_pointer(L, 1, &arg1, "cc.types.TMXTileFlags");

    // cocos2d::types::TMXTileFlags(cocos2d::TMXTileFlags *v)
    cocos2d::types::TMXTileFlags *ret = new cocos2d::types::TMXTileFlags(arg1);
    int num_ret = olua_push_object(L, ret, "cc.types.TMXTileFlags");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_TMXTileFlags_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // cocos2d::types::TMXTileFlags()
        return _olua_fun_cocos2d_types_TMXTileFlags_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // cocos2d::types::TMXTileFlags(@optional size_t len)
            return _olua_fun_cocos2d_types_TMXTileFlags_new$1(L);
        }

        // if ((olua_is_pointer(L, 1, "cc.types.TMXTileFlags"))) {
            // cocos2d::types::TMXTileFlags(cocos2d::TMXTileFlags *v)
            return _olua_fun_cocos2d_types_TMXTileFlags_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_pointer(L, 1, "cc.types.TMXTileFlags")) && (olua_is_integer(L, 2))) {
            // cocos2d::types::TMXTileFlags(cocos2d::TMXTileFlags *v, @optional size_t len)
            return _olua_fun_cocos2d_types_TMXTileFlags_new$3(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::types::TMXTileFlags::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_types_TMXTileFlags_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::TMXTileFlags *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "cc.types.TMXTileFlags");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew cocos2d::types::TMXTileFlags *slice(size_t from, @optional size_t to)
    cocos2d::types::TMXTileFlags *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.types.TMXTileFlags");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_TMXTileFlags_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::TMXTileFlags *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "cc.types.TMXTileFlags");
    olua_check_integer(L, 2, &arg1);

    // @postnew cocos2d::types::TMXTileFlags *slice(size_t from)
    cocos2d::types::TMXTileFlags *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "cc.types.TMXTileFlags");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_TMXTileFlags_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.types.TMXTileFlags")) && (olua_is_integer(L, 2))) {
            // @postnew cocos2d::types::TMXTileFlags *slice(size_t from)
            return _olua_fun_cocos2d_types_TMXTileFlags_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.types.TMXTileFlags")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew cocos2d::types::TMXTileFlags *slice(size_t from, @optional size_t to)
            return _olua_fun_cocos2d_types_TMXTileFlags_slice$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::types::TMXTileFlags::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_types_TMXTileFlags_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::TMXTileFlags *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "cc.types.TMXTileFlags");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew cocos2d::types::TMXTileFlags *sub(size_t from, @optional size_t to)
    cocos2d::types::TMXTileFlags *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.types.TMXTileFlags");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_TMXTileFlags_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::TMXTileFlags *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "cc.types.TMXTileFlags");
    olua_check_integer(L, 2, &arg1);

    // @postnew cocos2d::types::TMXTileFlags *sub(size_t from)
    cocos2d::types::TMXTileFlags *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "cc.types.TMXTileFlags");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_TMXTileFlags_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.types.TMXTileFlags")) && (olua_is_integer(L, 2))) {
            // @postnew cocos2d::types::TMXTileFlags *sub(size_t from)
            return _olua_fun_cocos2d_types_TMXTileFlags_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.types.TMXTileFlags")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew cocos2d::types::TMXTileFlags *sub(size_t from, @optional size_t to)
            return _olua_fun_cocos2d_types_TMXTileFlags_sub$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::types::TMXTileFlags::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_types_TMXTileFlags_take(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::TMXTileFlags *self = nullptr;

    olua_to_object(L, 1, &self, "cc.types.TMXTileFlags");

    // cocos2d::types::TMXTileFlags *take()
    cocos2d::types::TMXTileFlags *ret = self->take();
    int num_ret = olua_push_object(L, ret, "cc.types.TMXTileFlags");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_TMXTileFlags_tostring(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::TMXTileFlags *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "cc.types.TMXTileFlags");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_cocos2d_types_TMXTileFlags_value$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::TMXTileFlags *self = nullptr;

    olua_to_object(L, 1, &self, "cc.types.TMXTileFlags");

    // @getter const cocos2d::TMXTileFlags &value()
    const cocos2d::TMXTileFlags &ret = self->value();
    int num_ret = olua_push_enum(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_TMXTileFlags_value$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::TMXTileFlags *self = nullptr;
    cocos2d::TMXTileFlags arg1 = (cocos2d::TMXTileFlags)0;       /** v */

    olua_to_object(L, 1, &self, "cc.types.TMXTileFlags");
    olua_check_enum(L, 2, &arg1);

    // @setter void value(const cocos2d::TMXTileFlags &v)
    self->value(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_types_TMXTileFlags_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const cocos2d::TMXTileFlags &value()
        return _olua_fun_cocos2d_types_TMXTileFlags_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.types.TMXTileFlags")) && (olua_is_enum(L, 2))) {
            // @setter void value(const cocos2d::TMXTileFlags &v)
            return _olua_fun_cocos2d_types_TMXTileFlags_value$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::types::TMXTileFlags::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_cc_types_TMXTileFlags(lua_State *L)
{
    oluacls_class<cocos2d::types::TMXTileFlags>(L, "cc.types.TMXTileFlags");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_types_TMXTileFlags___gc);
    oluacls_func(L, "__index", _olua_fun_cocos2d_types_TMXTileFlags___index);
    oluacls_func(L, "__newindex", _olua_fun_cocos2d_types_TMXTileFlags___newindex);
    oluacls_func(L, "new", _olua_fun_cocos2d_types_TMXTileFlags_new);
    oluacls_func(L, "slice", _olua_fun_cocos2d_types_TMXTileFlags_slice);
    oluacls_func(L, "sub", _olua_fun_cocos2d_types_TMXTileFlags_sub);
    oluacls_func(L, "take", _olua_fun_cocos2d_types_TMXTileFlags_take);
    oluacls_func(L, "tostring", _olua_fun_cocos2d_types_TMXTileFlags_tostring);
    oluacls_prop(L, "buffer", _olua_fun_cocos2d_types_TMXTileFlags_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_cocos2d_types_TMXTileFlags_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_cocos2d_types_TMXTileFlags_value, _olua_fun_cocos2d_types_TMXTileFlags_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cc_types_TMXTileFlags(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "cc.types.TMXTileFlags")) {
        luaL_error(L, "class not found: cocos2d::types::TMXTileFlags");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_cocos2d_types_Vec2Array___gc(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::Vec2Array *self = nullptr;

    olua_to_object(L, 1, &self, "cc.types.Vec2Array");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_cocos2d_types_Vec2Array___index(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::Vec2Array *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "cc.types.Vec2Array");
    olua_check_integer(L, 2, &arg1);

    // cocos2d::Vec2 __index(unsigned int idx)
    cocos2d::Vec2 ret = self->__index(arg1);
    int num_ret = olua_copy_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_Vec2Array___newindex(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::Vec2Array *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    cocos2d::Vec2 *arg2;       /** v */

    olua_to_object(L, 1, &self, "cc.types.Vec2Array");
    olua_check_integer(L, 2, &arg1);
    olua_check_object(L, 3, &arg2, "cc.Vec2");

    // void __newindex(unsigned int idx, const cocos2d::Vec2 &v)
    self->__newindex(arg1, *arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_types_Vec2Array_buffer(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::Vec2Array *self = nullptr;

    olua_to_object(L, 1, &self, "cc.types.Vec2Array");

    // @getter @type(void *) cocos2d::Vec2 *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_Vec2Array_length(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::Vec2Array *self = nullptr;

    olua_to_object(L, 1, &self, "cc.types.Vec2Array");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_Vec2Array_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // cocos2d::types::Vec2Array(@optional size_t len)
    cocos2d::types::Vec2Array *ret = new cocos2d::types::Vec2Array(arg1);
    int num_ret = olua_push_object(L, ret, "cc.types.Vec2Array");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_Vec2Array_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // cocos2d::types::Vec2Array()
    cocos2d::types::Vec2Array *ret = new cocos2d::types::Vec2Array();
    int num_ret = olua_push_object(L, ret, "cc.types.Vec2Array");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_Vec2Array_new$3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_object(L, 1, &arg1, "cc.Vec2");
    olua_check_integer(L, 2, &arg2);

    // cocos2d::types::Vec2Array(cocos2d::Vec2 *v, @optional size_t len)
    cocos2d::types::Vec2Array *ret = new cocos2d::types::Vec2Array(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.types.Vec2Array");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_Vec2Array_new$4(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 *arg1 = nullptr;       /** v */

    olua_check_object(L, 1, &arg1, "cc.Vec2");

    // cocos2d::types::Vec2Array(cocos2d::Vec2 *v)
    cocos2d::types::Vec2Array *ret = new cocos2d::types::Vec2Array(arg1);
    int num_ret = olua_push_object(L, ret, "cc.types.Vec2Array");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_Vec2Array_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // cocos2d::types::Vec2Array()
        return _olua_fun_cocos2d_types_Vec2Array_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_object(L, 1, "cc.Vec2"))) {
            // cocos2d::types::Vec2Array(cocos2d::Vec2 *v)
            return _olua_fun_cocos2d_types_Vec2Array_new$4(L);
        }

        // if ((olua_is_integer(L, 1))) {
            // cocos2d::types::Vec2Array(@optional size_t len)
            return _olua_fun_cocos2d_types_Vec2Array_new$1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.Vec2")) && (olua_is_integer(L, 2))) {
            // cocos2d::types::Vec2Array(cocos2d::Vec2 *v, @optional size_t len)
            return _olua_fun_cocos2d_types_Vec2Array_new$3(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::types::Vec2Array::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_types_Vec2Array_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::Vec2Array *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "cc.types.Vec2Array");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew cocos2d::types::Vec2Array *slice(size_t from, @optional size_t to)
    cocos2d::types::Vec2Array *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.types.Vec2Array");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_Vec2Array_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::Vec2Array *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "cc.types.Vec2Array");
    olua_check_integer(L, 2, &arg1);

    // @postnew cocos2d::types::Vec2Array *slice(size_t from)
    cocos2d::types::Vec2Array *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "cc.types.Vec2Array");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_Vec2Array_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.types.Vec2Array")) && (olua_is_integer(L, 2))) {
            // @postnew cocos2d::types::Vec2Array *slice(size_t from)
            return _olua_fun_cocos2d_types_Vec2Array_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.types.Vec2Array")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew cocos2d::types::Vec2Array *slice(size_t from, @optional size_t to)
            return _olua_fun_cocos2d_types_Vec2Array_slice$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::types::Vec2Array::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_types_Vec2Array_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::Vec2Array *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "cc.types.Vec2Array");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew cocos2d::types::Vec2Array *sub(size_t from, @optional size_t to)
    cocos2d::types::Vec2Array *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "cc.types.Vec2Array");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_Vec2Array_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::Vec2Array *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "cc.types.Vec2Array");
    olua_check_integer(L, 2, &arg1);

    // @postnew cocos2d::types::Vec2Array *sub(size_t from)
    cocos2d::types::Vec2Array *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "cc.types.Vec2Array");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_Vec2Array_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.types.Vec2Array")) && (olua_is_integer(L, 2))) {
            // @postnew cocos2d::types::Vec2Array *sub(size_t from)
            return _olua_fun_cocos2d_types_Vec2Array_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "cc.types.Vec2Array")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew cocos2d::types::Vec2Array *sub(size_t from, @optional size_t to)
            return _olua_fun_cocos2d_types_Vec2Array_sub$1(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::types::Vec2Array::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cocos2d_types_Vec2Array_take(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::Vec2Array *self = nullptr;

    olua_to_object(L, 1, &self, "cc.types.Vec2Array");

    // cocos2d::types::Vec2Array *take()
    cocos2d::types::Vec2Array *ret = self->take();
    int num_ret = olua_push_object(L, ret, "cc.types.Vec2Array");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_Vec2Array_tostring(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::Vec2Array *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "cc.types.Vec2Array");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_cocos2d_types_Vec2Array_value$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::Vec2Array *self = nullptr;

    olua_to_object(L, 1, &self, "cc.types.Vec2Array");

    // @getter const cocos2d::Vec2 &value()
    const cocos2d::Vec2 &ret = self->value();
    int num_ret = olua_push_object(L, ret, "cc.Vec2");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cocos2d_types_Vec2Array_value$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::types::Vec2Array *self = nullptr;
    cocos2d::Vec2 *arg1;       /** v */

    olua_to_object(L, 1, &self, "cc.types.Vec2Array");
    olua_check_object(L, 2, &arg1, "cc.Vec2");

    // @setter void value(const cocos2d::Vec2 &v)
    self->value(*arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cocos2d_types_Vec2Array_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const cocos2d::Vec2 &value()
        return _olua_fun_cocos2d_types_Vec2Array_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "cc.types.Vec2Array")) && (olua_is_object(L, 2, "cc.Vec2"))) {
            // @setter void value(const cocos2d::Vec2 &v)
            return _olua_fun_cocos2d_types_Vec2Array_value$2(L);
        // }
    }

    luaL_error(L, "method 'cocos2d::types::Vec2Array::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_cc_types_Vec2Array(lua_State *L)
{
    oluacls_class<cocos2d::types::Vec2Array>(L, "cc.types.Vec2Array");
    oluacls_func(L, "__gc", _olua_fun_cocos2d_types_Vec2Array___gc);
    oluacls_func(L, "__index", _olua_fun_cocos2d_types_Vec2Array___index);
    oluacls_func(L, "__newindex", _olua_fun_cocos2d_types_Vec2Array___newindex);
    oluacls_func(L, "new", _olua_fun_cocos2d_types_Vec2Array_new);
    oluacls_func(L, "slice", _olua_fun_cocos2d_types_Vec2Array_slice);
    oluacls_func(L, "sub", _olua_fun_cocos2d_types_Vec2Array_sub);
    oluacls_func(L, "take", _olua_fun_cocos2d_types_Vec2Array_take);
    oluacls_func(L, "tostring", _olua_fun_cocos2d_types_Vec2Array_tostring);
    oluacls_prop(L, "buffer", _olua_fun_cocos2d_types_Vec2Array_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_cocos2d_types_Vec2Array_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_cocos2d_types_Vec2Array_value, _olua_fun_cocos2d_types_Vec2Array_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cc_types_Vec2Array(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);
    if (!olua_getclass(L, "cc.types.Vec2Array")) {
        luaL_error(L, "class not found: cocos2d::types::Vec2Array");
    }
    return 1;
}
OLUA_END_DECLS

int _olua_module_cocos2d_types(lua_State *L)
{
    olua_require(L, "cc.Vec2", _olua_cls_cc_Vec2);
    olua_require(L, "cc.Vec3", _olua_cls_cc_Vec3);
    olua_require(L, "cc.Vec4", _olua_cls_cc_Vec4);
    olua_require(L, "cc.Size", _olua_cls_cc_Size);
    olua_require(L, "cc.Rect", _olua_cls_cc_Rect);
    olua_require(L, "cc.Bounds", _olua_cls_cc_Bounds);
    olua_require(L, "cc.Mat4", _olua_cls_cc_Mat4);
    olua_require(L, "cc.Viewport", _olua_cls_cc_Viewport);
    olua_require(L, "cc.ScissorRect", _olua_cls_cc_ScissorRect);
    olua_require(L, "cc.Quaternion", _olua_cls_cc_Quaternion);
    olua_require(L, "cc.AffineTransform", _olua_cls_cc_AffineTransform);
    olua_require(L, "cc.GLContextAttrs", _olua_cls_cc_GLContextAttrs);
    olua_require(L, "cc.Tex2F", _olua_cls_cc_Tex2F);
    olua_require(L, "cc.T2F_Quad", _olua_cls_cc_T2F_Quad);
    olua_require(L, "cc.ccBezierConfig", _olua_cls_cc_ccBezierConfig);
    olua_require(L, "cc.TTFConfig", _olua_cls_cc_TTFConfig);
    olua_require(L, "cc.BlendFunc", _olua_cls_cc_BlendFunc);
    olua_require(L, "cc.ui.Margin", _olua_cls_cc_ui_Margin);
    olua_require(L, "cc.ResourceData", _olua_cls_cc_ResourceData);
    olua_require(L, "cc.Quad3", _olua_cls_cc_Quad3);
    olua_require(L, "cc.Texture2D.PixelFormatInfo", _olua_cls_cc_Texture2D_PixelFormatInfo);
    olua_require(L, "cc.Controller.KeyStatus", _olua_cls_cc_Controller_KeyStatus);
#if CC_USE_NAVMESH
    olua_require(L, "cc.NavMeshAgentParam", _olua_cls_cc_NavMeshAgentParam);
    olua_require(L, "cc.OffMeshLinkData", _olua_cls_cc_OffMeshLinkData);
#endif
    olua_require(L, "ccb.BlendDescriptor", _olua_cls_ccb_BlendDescriptor);
    olua_require(L, "ccb.SamplerDescriptor", _olua_cls_ccb_SamplerDescriptor);
    olua_require(L, "ccb.TextureInfo", _olua_cls_ccb_TextureInfo);
    olua_require(L, "ccb.AttributeBindInfo", _olua_cls_ccb_AttributeBindInfo);
    olua_require(L, "ccb.UniformInfo", _olua_cls_ccb_UniformInfo);
    olua_require(L, "ccb.TextureDescriptor", _olua_cls_ccb_TextureDescriptor);
    olua_require(L, "ccb.StencilDescriptor", _olua_cls_ccb_StencilDescriptor);
    olua_require(L, "ccb.DepthStencilDescriptor", _olua_cls_ccb_DepthStencilDescriptor);
    olua_require(L, "ccb.VertexLayout.Attribute", _olua_cls_ccb_VertexLayout_Attribute);
    olua_require(L, "cc.types.VectorString", _olua_cls_cc_types_VectorString);
    olua_require(L, "cc.types.VectorInt", _olua_cls_cc_types_VectorInt);
    olua_require(L, "cc.types.ValueMap", _olua_cls_cc_types_ValueMap);
    olua_require(L, "cc.types.TMXTileFlags", _olua_cls_cc_types_TMXTileFlags);
    olua_require(L, "cc.types.Vec2Array", _olua_cls_cc_types_Vec2Array);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cocos2d_types(lua_State *L)
{
    olua_require(L, "cocos2d_types",  _olua_module_cocos2d_types);

    return 0;
}
OLUA_END_DECLS
