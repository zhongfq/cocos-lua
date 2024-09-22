//
// AUTO GENERATED, DO NOT MODIFY!
//
#include "lua_types.h"
#include "cclua/olua-2dx.h"

static int _olua_module_types(lua_State *L);

static int _olua_fun_olua_bool___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;

    olua_to_object(L, 1, &self, "olua.bool");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_bool___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.bool");
    olua_check_integer(L, 2, &arg1);

    // bool __index(unsigned int idx)
    bool ret = self->__index(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_bool___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    bool arg2 = false;       /** v */

    olua_to_object(L, 1, &self, "olua.bool");
    olua_check_integer(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void __newindex(unsigned int idx, const bool &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_bool_buffer(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;

    olua_to_object(L, 1, &self, "olua.bool");

    // @getter @type(void *) bool *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_bool_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;

    olua_to_object(L, 1, &self, "olua.bool");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_bool_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // olua_bool(@optional size_t len)
    olua_bool *ret = new olua_bool(arg1);
    int num_ret = olua_push_object(L, ret, "olua.bool");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_bool_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // olua_bool()
    olua_bool *ret = new olua_bool();
    int num_ret = olua_push_object(L, ret, "olua.bool");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_bool_new$3(lua_State *L)
{
    olua_startinvoke(L);

    bool *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_pointer(L, 1, &arg1, "olua.bool");
    olua_check_integer(L, 2, &arg2);

    // olua_bool(bool *v, @optional size_t len)
    olua_bool *ret = new olua_bool(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.bool");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_bool_new$4(lua_State *L)
{
    olua_startinvoke(L);

    bool *arg1 = nullptr;       /** v */

    olua_check_pointer(L, 1, &arg1, "olua.bool");

    // olua_bool(bool *v)
    olua_bool *ret = new olua_bool(arg1);
    int num_ret = olua_push_object(L, ret, "olua.bool");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_bool_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // olua_bool()
        return _olua_fun_olua_bool_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // olua_bool(@optional size_t len)
            return _olua_fun_olua_bool_new$1(L);
        }

        // if ((olua_is_pointer(L, 1, "olua.bool"))) {
            // olua_bool(bool *v)
            return _olua_fun_olua_bool_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_pointer(L, 1, "olua.bool")) && (olua_is_integer(L, 2))) {
            // olua_bool(bool *v, @optional size_t len)
            return _olua_fun_olua_bool_new$3(L);
        // }
    }

    luaL_error(L, "method 'olua_bool::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_bool_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.bool");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_bool *slice(size_t from, @optional size_t to)
    olua_bool *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.bool");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_bool_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.bool");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_bool *slice(size_t from)
    olua_bool *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "olua.bool");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_bool_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.bool")) && (olua_is_integer(L, 2))) {
            // @postnew olua_bool *slice(size_t from)
            return _olua_fun_olua_bool_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.bool")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_bool *slice(size_t from, @optional size_t to)
            return _olua_fun_olua_bool_slice$1(L);
        // }
    }

    luaL_error(L, "method 'olua_bool::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_bool_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.bool");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_bool *sub(size_t from, @optional size_t to)
    olua_bool *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.bool");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_bool_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.bool");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_bool *sub(size_t from)
    olua_bool *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.bool");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_bool_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.bool")) && (olua_is_integer(L, 2))) {
            // @postnew olua_bool *sub(size_t from)
            return _olua_fun_olua_bool_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.bool")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_bool *sub(size_t from, @optional size_t to)
            return _olua_fun_olua_bool_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_bool::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_bool_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;

    olua_to_object(L, 1, &self, "olua.bool");

    // olua_bool *take()
    olua_bool *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.bool");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_bool_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.bool");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_bool_value$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;

    olua_to_object(L, 1, &self, "olua.bool");

    // @getter const bool &value()
    const bool &ret = self->value();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_bool_value$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;
    bool arg1 = false;       /** v */

    olua_to_object(L, 1, &self, "olua.bool");
    olua_check_bool(L, 2, &arg1);

    // @setter void value(const bool &v)
    self->value(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_bool_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const bool &value()
        return _olua_fun_olua_bool_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.bool")) && (olua_is_bool(L, 2))) {
            // @setter void value(const bool &v)
            return _olua_fun_olua_bool_value$2(L);
        // }
    }

    luaL_error(L, "method 'olua_bool::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_olua_bool(lua_State *L)
{
    oluacls_class<olua_bool>(L, "olua.bool");
    oluacls_func(L, "__gc", _olua_fun_olua_bool___gc);
    oluacls_func(L, "__index", _olua_fun_olua_bool___index);
    oluacls_func(L, "__newindex", _olua_fun_olua_bool___newindex);
    oluacls_func(L, "new", _olua_fun_olua_bool_new);
    oluacls_func(L, "slice", _olua_fun_olua_bool_slice);
    oluacls_func(L, "sub", _olua_fun_olua_bool_sub);
    oluacls_func(L, "take", _olua_fun_olua_bool_take);
    oluacls_func(L, "tostring", _olua_fun_olua_bool_tostring);
    oluacls_prop(L, "buffer", _olua_fun_olua_bool_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_olua_bool_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_olua_bool_value, _olua_fun_olua_bool_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_bool(lua_State *L)
{
    olua_require(L, "types",  _olua_module_types);
    if (!olua_getclass(L, "olua.bool")) {
        luaL_error(L, "class not found: olua_bool");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_olua_string___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;

    olua_to_object(L, 1, &self, "olua.string");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_string___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.string");
    olua_check_integer(L, 2, &arg1);

    // std::string __index(unsigned int idx)
    std::string ret = self->__index(arg1);
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_string___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    std::string arg2;       /** v */

    olua_to_object(L, 1, &self, "olua.string");
    olua_check_integer(L, 2, &arg1);
    olua_check_string(L, 3, &arg2);

    // void __newindex(unsigned int idx, const std::string &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_string_buffer(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;

    olua_to_object(L, 1, &self, "olua.string");

    // @getter @type(void *) std::string *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_string_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;

    olua_to_object(L, 1, &self, "olua.string");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_string_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // olua_string(@optional size_t len)
    olua_string *ret = new olua_string(arg1);
    int num_ret = olua_push_object(L, ret, "olua.string");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_string_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // olua_string()
    olua_string *ret = new olua_string();
    int num_ret = olua_push_object(L, ret, "olua.string");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_string_new$3(lua_State *L)
{
    olua_startinvoke(L);

    std::string *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_pointer(L, 1, &arg1, "olua.string");
    olua_check_integer(L, 2, &arg2);

    // olua_string(std::string *v, @optional size_t len)
    olua_string *ret = new olua_string(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.string");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_string_new$4(lua_State *L)
{
    olua_startinvoke(L);

    std::string *arg1 = nullptr;       /** v */

    olua_check_pointer(L, 1, &arg1, "olua.string");

    // olua_string(std::string *v)
    olua_string *ret = new olua_string(arg1);
    int num_ret = olua_push_object(L, ret, "olua.string");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_string_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // olua_string()
        return _olua_fun_olua_string_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // olua_string(@optional size_t len)
            return _olua_fun_olua_string_new$1(L);
        }

        // if ((olua_is_pointer(L, 1, "olua.string"))) {
            // olua_string(std::string *v)
            return _olua_fun_olua_string_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_pointer(L, 1, "olua.string")) && (olua_is_integer(L, 2))) {
            // olua_string(std::string *v, @optional size_t len)
            return _olua_fun_olua_string_new$3(L);
        // }
    }

    luaL_error(L, "method 'olua_string::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_string_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.string");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_string *slice(size_t from, @optional size_t to)
    olua_string *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.string");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_string_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.string");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_string *slice(size_t from)
    olua_string *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "olua.string");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_string_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.string")) && (olua_is_integer(L, 2))) {
            // @postnew olua_string *slice(size_t from)
            return _olua_fun_olua_string_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.string")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_string *slice(size_t from, @optional size_t to)
            return _olua_fun_olua_string_slice$1(L);
        // }
    }

    luaL_error(L, "method 'olua_string::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_string_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.string");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_string *sub(size_t from, @optional size_t to)
    olua_string *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.string");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_string_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.string");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_string *sub(size_t from)
    olua_string *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.string");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_string_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.string")) && (olua_is_integer(L, 2))) {
            // @postnew olua_string *sub(size_t from)
            return _olua_fun_olua_string_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.string")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_string *sub(size_t from, @optional size_t to)
            return _olua_fun_olua_string_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_string::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_string_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;

    olua_to_object(L, 1, &self, "olua.string");

    // olua_string *take()
    olua_string *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.string");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_string_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.string");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_string_value$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;

    olua_to_object(L, 1, &self, "olua.string");

    // @getter const std::string &value()
    const std::string &ret = self->value();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_string_value$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;
    std::string arg1;       /** v */

    olua_to_object(L, 1, &self, "olua.string");
    olua_check_string(L, 2, &arg1);

    // @setter void value(const std::string &v)
    self->value(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_string_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const std::string &value()
        return _olua_fun_olua_string_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.string")) && (olua_is_string(L, 2))) {
            // @setter void value(const std::string &v)
            return _olua_fun_olua_string_value$2(L);
        // }
    }

    luaL_error(L, "method 'olua_string::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_olua_string(lua_State *L)
{
    oluacls_class<olua_string>(L, "olua.string");
    oluacls_func(L, "__gc", _olua_fun_olua_string___gc);
    oluacls_func(L, "__index", _olua_fun_olua_string___index);
    oluacls_func(L, "__newindex", _olua_fun_olua_string___newindex);
    oluacls_func(L, "new", _olua_fun_olua_string_new);
    oluacls_func(L, "slice", _olua_fun_olua_string_slice);
    oluacls_func(L, "sub", _olua_fun_olua_string_sub);
    oluacls_func(L, "take", _olua_fun_olua_string_take);
    oluacls_func(L, "tostring", _olua_fun_olua_string_tostring);
    oluacls_prop(L, "buffer", _olua_fun_olua_string_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_olua_string_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_olua_string_value, _olua_fun_olua_string_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_string(lua_State *L)
{
    olua_require(L, "types",  _olua_module_types);
    if (!olua_getclass(L, "olua.string")) {
        luaL_error(L, "class not found: olua_string");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_olua_int8___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int8");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_int8___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.int8");
    olua_check_integer(L, 2, &arg1);

    // int8_t __index(unsigned int idx)
    int8_t ret = self->__index(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int8___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    int8_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.int8");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void __newindex(unsigned int idx, const int8_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_int8_buffer(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int8");

    // @getter @type(void *) int8_t *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int8_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int8");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int8_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // olua_int8(@optional size_t len)
    olua_int8 *ret = new olua_int8(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int8");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int8_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // olua_int8()
    olua_int8 *ret = new olua_int8();
    int num_ret = olua_push_object(L, ret, "olua.int8");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int8_new$3(lua_State *L)
{
    olua_startinvoke(L);

    int8_t *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_pointer(L, 1, &arg1, "olua.int8");
    olua_check_integer(L, 2, &arg2);

    // olua_int8(int8_t *v, @optional size_t len)
    olua_int8 *ret = new olua_int8(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.int8");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int8_new$4(lua_State *L)
{
    olua_startinvoke(L);

    int8_t *arg1 = nullptr;       /** v */

    olua_check_pointer(L, 1, &arg1, "olua.int8");

    // olua_int8(int8_t *v)
    olua_int8 *ret = new olua_int8(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int8");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int8_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // olua_int8()
        return _olua_fun_olua_int8_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // olua_int8(@optional size_t len)
            return _olua_fun_olua_int8_new$1(L);
        }

        // if ((olua_is_pointer(L, 1, "olua.int8"))) {
            // olua_int8(int8_t *v)
            return _olua_fun_olua_int8_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_pointer(L, 1, "olua.int8")) && (olua_is_integer(L, 2))) {
            // olua_int8(int8_t *v, @optional size_t len)
            return _olua_fun_olua_int8_new$3(L);
        // }
    }

    luaL_error(L, "method 'olua_int8::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_int8_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.int8");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_int8 *slice(size_t from, @optional size_t to)
    olua_int8 *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.int8");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int8_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.int8");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_int8 *slice(size_t from)
    olua_int8 *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int8");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int8_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.int8")) && (olua_is_integer(L, 2))) {
            // @postnew olua_int8 *slice(size_t from)
            return _olua_fun_olua_int8_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.int8")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_int8 *slice(size_t from, @optional size_t to)
            return _olua_fun_olua_int8_slice$1(L);
        // }
    }

    luaL_error(L, "method 'olua_int8::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_int8_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.int8");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_int8 *sub(size_t from, @optional size_t to)
    olua_int8 *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.int8");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int8_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.int8");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_int8 *sub(size_t from)
    olua_int8 *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int8");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int8_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.int8")) && (olua_is_integer(L, 2))) {
            // @postnew olua_int8 *sub(size_t from)
            return _olua_fun_olua_int8_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.int8")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_int8 *sub(size_t from, @optional size_t to)
            return _olua_fun_olua_int8_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_int8::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_int8_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int8");

    // olua_int8 *take()
    olua_int8 *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.int8");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int8_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.int8");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_int8_value$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int8");

    // @getter const int8_t &value()
    const int8_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int8_value$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;
    int8_t arg1 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.int8");
    olua_check_integer(L, 2, &arg1);

    // @setter void value(const int8_t &v)
    self->value(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_int8_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const int8_t &value()
        return _olua_fun_olua_int8_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.int8")) && (olua_is_integer(L, 2))) {
            // @setter void value(const int8_t &v)
            return _olua_fun_olua_int8_value$2(L);
        // }
    }

    luaL_error(L, "method 'olua_int8::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_olua_int8(lua_State *L)
{
    oluacls_class<olua_int8>(L, "olua.int8");
    oluacls_func(L, "__gc", _olua_fun_olua_int8___gc);
    oluacls_func(L, "__index", _olua_fun_olua_int8___index);
    oluacls_func(L, "__newindex", _olua_fun_olua_int8___newindex);
    oluacls_func(L, "new", _olua_fun_olua_int8_new);
    oluacls_func(L, "slice", _olua_fun_olua_int8_slice);
    oluacls_func(L, "sub", _olua_fun_olua_int8_sub);
    oluacls_func(L, "take", _olua_fun_olua_int8_take);
    oluacls_func(L, "tostring", _olua_fun_olua_int8_tostring);
    oluacls_prop(L, "buffer", _olua_fun_olua_int8_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_olua_int8_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_olua_int8_value, _olua_fun_olua_int8_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_int8(lua_State *L)
{
    olua_require(L, "types",  _olua_module_types);
    if (!olua_getclass(L, "olua.int8")) {
        luaL_error(L, "class not found: olua_int8");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_olua_int16___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int16");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_int16___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.int16");
    olua_check_integer(L, 2, &arg1);

    // int16_t __index(unsigned int idx)
    int16_t ret = self->__index(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int16___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    int16_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.int16");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void __newindex(unsigned int idx, const int16_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_int16_buffer(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int16");

    // @getter @type(void *) int16_t *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int16_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int16");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int16_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // olua_int16(@optional size_t len)
    olua_int16 *ret = new olua_int16(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int16");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int16_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // olua_int16()
    olua_int16 *ret = new olua_int16();
    int num_ret = olua_push_object(L, ret, "olua.int16");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int16_new$3(lua_State *L)
{
    olua_startinvoke(L);

    int16_t *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_pointer(L, 1, &arg1, "olua.int16");
    olua_check_integer(L, 2, &arg2);

    // olua_int16(int16_t *v, @optional size_t len)
    olua_int16 *ret = new olua_int16(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.int16");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int16_new$4(lua_State *L)
{
    olua_startinvoke(L);

    int16_t *arg1 = nullptr;       /** v */

    olua_check_pointer(L, 1, &arg1, "olua.int16");

    // olua_int16(int16_t *v)
    olua_int16 *ret = new olua_int16(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int16");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int16_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // olua_int16()
        return _olua_fun_olua_int16_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // olua_int16(@optional size_t len)
            return _olua_fun_olua_int16_new$1(L);
        }

        // if ((olua_is_pointer(L, 1, "olua.int16"))) {
            // olua_int16(int16_t *v)
            return _olua_fun_olua_int16_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_pointer(L, 1, "olua.int16")) && (olua_is_integer(L, 2))) {
            // olua_int16(int16_t *v, @optional size_t len)
            return _olua_fun_olua_int16_new$3(L);
        // }
    }

    luaL_error(L, "method 'olua_int16::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_int16_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.int16");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_int16 *slice(size_t from, @optional size_t to)
    olua_int16 *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.int16");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int16_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.int16");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_int16 *slice(size_t from)
    olua_int16 *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int16");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int16_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.int16")) && (olua_is_integer(L, 2))) {
            // @postnew olua_int16 *slice(size_t from)
            return _olua_fun_olua_int16_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.int16")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_int16 *slice(size_t from, @optional size_t to)
            return _olua_fun_olua_int16_slice$1(L);
        // }
    }

    luaL_error(L, "method 'olua_int16::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_int16_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.int16");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_int16 *sub(size_t from, @optional size_t to)
    olua_int16 *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.int16");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int16_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.int16");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_int16 *sub(size_t from)
    olua_int16 *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int16");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int16_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.int16")) && (olua_is_integer(L, 2))) {
            // @postnew olua_int16 *sub(size_t from)
            return _olua_fun_olua_int16_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.int16")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_int16 *sub(size_t from, @optional size_t to)
            return _olua_fun_olua_int16_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_int16::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_int16_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int16");

    // olua_int16 *take()
    olua_int16 *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.int16");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int16_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.int16");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_int16_value$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int16");

    // @getter const int16_t &value()
    const int16_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int16_value$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;
    int16_t arg1 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.int16");
    olua_check_integer(L, 2, &arg1);

    // @setter void value(const int16_t &v)
    self->value(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_int16_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const int16_t &value()
        return _olua_fun_olua_int16_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.int16")) && (olua_is_integer(L, 2))) {
            // @setter void value(const int16_t &v)
            return _olua_fun_olua_int16_value$2(L);
        // }
    }

    luaL_error(L, "method 'olua_int16::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_olua_int16(lua_State *L)
{
    oluacls_class<olua_int16>(L, "olua.int16");
    oluacls_func(L, "__gc", _olua_fun_olua_int16___gc);
    oluacls_func(L, "__index", _olua_fun_olua_int16___index);
    oluacls_func(L, "__newindex", _olua_fun_olua_int16___newindex);
    oluacls_func(L, "new", _olua_fun_olua_int16_new);
    oluacls_func(L, "slice", _olua_fun_olua_int16_slice);
    oluacls_func(L, "sub", _olua_fun_olua_int16_sub);
    oluacls_func(L, "take", _olua_fun_olua_int16_take);
    oluacls_func(L, "tostring", _olua_fun_olua_int16_tostring);
    oluacls_prop(L, "buffer", _olua_fun_olua_int16_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_olua_int16_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_olua_int16_value, _olua_fun_olua_int16_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_int16(lua_State *L)
{
    olua_require(L, "types",  _olua_module_types);
    if (!olua_getclass(L, "olua.int16")) {
        luaL_error(L, "class not found: olua_int16");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_olua_int32___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int32");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_int32___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.int32");
    olua_check_integer(L, 2, &arg1);

    // int32_t __index(unsigned int idx)
    int32_t ret = self->__index(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int32___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    int32_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.int32");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void __newindex(unsigned int idx, const int32_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_int32_buffer(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int32");

    // @getter @type(void *) int32_t *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int32_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int32");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int32_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // olua_int32(@optional size_t len)
    olua_int32 *ret = new olua_int32(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int32");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int32_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // olua_int32()
    olua_int32 *ret = new olua_int32();
    int num_ret = olua_push_object(L, ret, "olua.int32");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int32_new$3(lua_State *L)
{
    olua_startinvoke(L);

    int32_t *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_pointer(L, 1, &arg1, "olua.int32");
    olua_check_integer(L, 2, &arg2);

    // olua_int32(int32_t *v, @optional size_t len)
    olua_int32 *ret = new olua_int32(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.int32");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int32_new$4(lua_State *L)
{
    olua_startinvoke(L);

    int32_t *arg1 = nullptr;       /** v */

    olua_check_pointer(L, 1, &arg1, "olua.int32");

    // olua_int32(int32_t *v)
    olua_int32 *ret = new olua_int32(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int32");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int32_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // olua_int32()
        return _olua_fun_olua_int32_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // olua_int32(@optional size_t len)
            return _olua_fun_olua_int32_new$1(L);
        }

        // if ((olua_is_pointer(L, 1, "olua.int32"))) {
            // olua_int32(int32_t *v)
            return _olua_fun_olua_int32_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_pointer(L, 1, "olua.int32")) && (olua_is_integer(L, 2))) {
            // olua_int32(int32_t *v, @optional size_t len)
            return _olua_fun_olua_int32_new$3(L);
        // }
    }

    luaL_error(L, "method 'olua_int32::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_int32_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.int32");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_int32 *slice(size_t from, @optional size_t to)
    olua_int32 *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.int32");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int32_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.int32");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_int32 *slice(size_t from)
    olua_int32 *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int32");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int32_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.int32")) && (olua_is_integer(L, 2))) {
            // @postnew olua_int32 *slice(size_t from)
            return _olua_fun_olua_int32_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.int32")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_int32 *slice(size_t from, @optional size_t to)
            return _olua_fun_olua_int32_slice$1(L);
        // }
    }

    luaL_error(L, "method 'olua_int32::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_int32_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.int32");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_int32 *sub(size_t from, @optional size_t to)
    olua_int32 *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.int32");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int32_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.int32");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_int32 *sub(size_t from)
    olua_int32 *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int32");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int32_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.int32")) && (olua_is_integer(L, 2))) {
            // @postnew olua_int32 *sub(size_t from)
            return _olua_fun_olua_int32_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.int32")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_int32 *sub(size_t from, @optional size_t to)
            return _olua_fun_olua_int32_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_int32::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_int32_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int32");

    // olua_int32 *take()
    olua_int32 *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.int32");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int32_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.int32");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_int32_value$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int32");

    // @getter const int32_t &value()
    const int32_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int32_value$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;
    int32_t arg1 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.int32");
    olua_check_integer(L, 2, &arg1);

    // @setter void value(const int32_t &v)
    self->value(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_int32_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const int32_t &value()
        return _olua_fun_olua_int32_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.int32")) && (olua_is_integer(L, 2))) {
            // @setter void value(const int32_t &v)
            return _olua_fun_olua_int32_value$2(L);
        // }
    }

    luaL_error(L, "method 'olua_int32::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_olua_int32(lua_State *L)
{
    oluacls_class<olua_int32>(L, "olua.int32");
    oluacls_func(L, "__gc", _olua_fun_olua_int32___gc);
    oluacls_func(L, "__index", _olua_fun_olua_int32___index);
    oluacls_func(L, "__newindex", _olua_fun_olua_int32___newindex);
    oluacls_func(L, "new", _olua_fun_olua_int32_new);
    oluacls_func(L, "slice", _olua_fun_olua_int32_slice);
    oluacls_func(L, "sub", _olua_fun_olua_int32_sub);
    oluacls_func(L, "take", _olua_fun_olua_int32_take);
    oluacls_func(L, "tostring", _olua_fun_olua_int32_tostring);
    oluacls_prop(L, "buffer", _olua_fun_olua_int32_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_olua_int32_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_olua_int32_value, _olua_fun_olua_int32_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_int32(lua_State *L)
{
    olua_require(L, "types",  _olua_module_types);
    if (!olua_getclass(L, "olua.int32")) {
        luaL_error(L, "class not found: olua_int32");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_olua_int64___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int64");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_int64___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.int64");
    olua_check_integer(L, 2, &arg1);

    // int64_t __index(unsigned int idx)
    int64_t ret = self->__index(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int64___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    int64_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.int64");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void __newindex(unsigned int idx, const int64_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_int64_buffer(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int64");

    // @getter @type(void *) int64_t *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int64_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int64");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int64_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // olua_int64(@optional size_t len)
    olua_int64 *ret = new olua_int64(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int64");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int64_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // olua_int64()
    olua_int64 *ret = new olua_int64();
    int num_ret = olua_push_object(L, ret, "olua.int64");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int64_new$3(lua_State *L)
{
    olua_startinvoke(L);

    int64_t *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_pointer(L, 1, &arg1, "olua.int64");
    olua_check_integer(L, 2, &arg2);

    // olua_int64(int64_t *v, @optional size_t len)
    olua_int64 *ret = new olua_int64(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.int64");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int64_new$4(lua_State *L)
{
    olua_startinvoke(L);

    int64_t *arg1 = nullptr;       /** v */

    olua_check_pointer(L, 1, &arg1, "olua.int64");

    // olua_int64(int64_t *v)
    olua_int64 *ret = new olua_int64(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int64");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int64_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // olua_int64()
        return _olua_fun_olua_int64_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // olua_int64(@optional size_t len)
            return _olua_fun_olua_int64_new$1(L);
        }

        // if ((olua_is_pointer(L, 1, "olua.int64"))) {
            // olua_int64(int64_t *v)
            return _olua_fun_olua_int64_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_pointer(L, 1, "olua.int64")) && (olua_is_integer(L, 2))) {
            // olua_int64(int64_t *v, @optional size_t len)
            return _olua_fun_olua_int64_new$3(L);
        // }
    }

    luaL_error(L, "method 'olua_int64::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_int64_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.int64");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_int64 *slice(size_t from, @optional size_t to)
    olua_int64 *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.int64");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int64_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.int64");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_int64 *slice(size_t from)
    olua_int64 *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int64");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int64_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.int64")) && (olua_is_integer(L, 2))) {
            // @postnew olua_int64 *slice(size_t from)
            return _olua_fun_olua_int64_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.int64")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_int64 *slice(size_t from, @optional size_t to)
            return _olua_fun_olua_int64_slice$1(L);
        // }
    }

    luaL_error(L, "method 'olua_int64::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_int64_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.int64");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_int64 *sub(size_t from, @optional size_t to)
    olua_int64 *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.int64");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int64_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.int64");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_int64 *sub(size_t from)
    olua_int64 *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int64");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int64_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.int64")) && (olua_is_integer(L, 2))) {
            // @postnew olua_int64 *sub(size_t from)
            return _olua_fun_olua_int64_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.int64")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_int64 *sub(size_t from, @optional size_t to)
            return _olua_fun_olua_int64_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_int64::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_int64_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int64");

    // olua_int64 *take()
    olua_int64 *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.int64");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int64_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.int64");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_int64_value$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int64");

    // @getter const int64_t &value()
    const int64_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int64_value$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;
    int64_t arg1 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.int64");
    olua_check_integer(L, 2, &arg1);

    // @setter void value(const int64_t &v)
    self->value(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_int64_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const int64_t &value()
        return _olua_fun_olua_int64_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.int64")) && (olua_is_integer(L, 2))) {
            // @setter void value(const int64_t &v)
            return _olua_fun_olua_int64_value$2(L);
        // }
    }

    luaL_error(L, "method 'olua_int64::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_olua_int64(lua_State *L)
{
    oluacls_class<olua_int64>(L, "olua.int64");
    oluacls_func(L, "__gc", _olua_fun_olua_int64___gc);
    oluacls_func(L, "__index", _olua_fun_olua_int64___index);
    oluacls_func(L, "__newindex", _olua_fun_olua_int64___newindex);
    oluacls_func(L, "new", _olua_fun_olua_int64_new);
    oluacls_func(L, "slice", _olua_fun_olua_int64_slice);
    oluacls_func(L, "sub", _olua_fun_olua_int64_sub);
    oluacls_func(L, "take", _olua_fun_olua_int64_take);
    oluacls_func(L, "tostring", _olua_fun_olua_int64_tostring);
    oluacls_prop(L, "buffer", _olua_fun_olua_int64_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_olua_int64_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_olua_int64_value, _olua_fun_olua_int64_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_int64(lua_State *L)
{
    olua_require(L, "types",  _olua_module_types);
    if (!olua_getclass(L, "olua.int64")) {
        luaL_error(L, "class not found: olua_int64");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_olua_uint8___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint8");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_uint8___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.uint8");
    olua_check_integer(L, 2, &arg1);

    // uint8_t __index(unsigned int idx)
    uint8_t ret = self->__index(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint8___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    uint8_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.uint8");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void __newindex(unsigned int idx, const uint8_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_uint8_buffer(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint8");

    // @getter @type(void *) uint8_t *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint8_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint8");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint8_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // olua_uint8(@optional size_t len)
    olua_uint8 *ret = new olua_uint8(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint8");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint8_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // olua_uint8()
    olua_uint8 *ret = new olua_uint8();
    int num_ret = olua_push_object(L, ret, "olua.uint8");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint8_new$3(lua_State *L)
{
    olua_startinvoke(L);

    uint8_t *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_pointer(L, 1, &arg1, "olua.uint8");
    olua_check_integer(L, 2, &arg2);

    // olua_uint8(uint8_t *v, @optional size_t len)
    olua_uint8 *ret = new olua_uint8(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.uint8");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint8_new$4(lua_State *L)
{
    olua_startinvoke(L);

    uint8_t *arg1 = nullptr;       /** v */

    olua_check_pointer(L, 1, &arg1, "olua.uint8");

    // olua_uint8(uint8_t *v)
    olua_uint8 *ret = new olua_uint8(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint8");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint8_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // olua_uint8()
        return _olua_fun_olua_uint8_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // olua_uint8(@optional size_t len)
            return _olua_fun_olua_uint8_new$1(L);
        }

        // if ((olua_is_pointer(L, 1, "olua.uint8"))) {
            // olua_uint8(uint8_t *v)
            return _olua_fun_olua_uint8_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_pointer(L, 1, "olua.uint8")) && (olua_is_integer(L, 2))) {
            // olua_uint8(uint8_t *v, @optional size_t len)
            return _olua_fun_olua_uint8_new$3(L);
        // }
    }

    luaL_error(L, "method 'olua_uint8::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_uint8_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.uint8");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_uint8 *slice(size_t from, @optional size_t to)
    olua_uint8 *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.uint8");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint8_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.uint8");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_uint8 *slice(size_t from)
    olua_uint8 *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint8");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint8_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.uint8")) && (olua_is_integer(L, 2))) {
            // @postnew olua_uint8 *slice(size_t from)
            return _olua_fun_olua_uint8_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.uint8")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_uint8 *slice(size_t from, @optional size_t to)
            return _olua_fun_olua_uint8_slice$1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint8::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_uint8_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.uint8");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_uint8 *sub(size_t from, @optional size_t to)
    olua_uint8 *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.uint8");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint8_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.uint8");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_uint8 *sub(size_t from)
    olua_uint8 *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint8");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint8_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.uint8")) && (olua_is_integer(L, 2))) {
            // @postnew olua_uint8 *sub(size_t from)
            return _olua_fun_olua_uint8_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.uint8")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_uint8 *sub(size_t from, @optional size_t to)
            return _olua_fun_olua_uint8_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint8::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_uint8_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint8");

    // olua_uint8 *take()
    olua_uint8 *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.uint8");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint8_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.uint8");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_uint8_value$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint8");

    // @getter const uint8_t &value()
    const uint8_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint8_value$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;
    uint8_t arg1 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.uint8");
    olua_check_integer(L, 2, &arg1);

    // @setter void value(const uint8_t &v)
    self->value(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_uint8_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const uint8_t &value()
        return _olua_fun_olua_uint8_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.uint8")) && (olua_is_integer(L, 2))) {
            // @setter void value(const uint8_t &v)
            return _olua_fun_olua_uint8_value$2(L);
        // }
    }

    luaL_error(L, "method 'olua_uint8::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_olua_uint8(lua_State *L)
{
    oluacls_class<olua_uint8>(L, "olua.uint8");
    oluacls_func(L, "__gc", _olua_fun_olua_uint8___gc);
    oluacls_func(L, "__index", _olua_fun_olua_uint8___index);
    oluacls_func(L, "__newindex", _olua_fun_olua_uint8___newindex);
    oluacls_func(L, "new", _olua_fun_olua_uint8_new);
    oluacls_func(L, "slice", _olua_fun_olua_uint8_slice);
    oluacls_func(L, "sub", _olua_fun_olua_uint8_sub);
    oluacls_func(L, "take", _olua_fun_olua_uint8_take);
    oluacls_func(L, "tostring", _olua_fun_olua_uint8_tostring);
    oluacls_prop(L, "buffer", _olua_fun_olua_uint8_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_olua_uint8_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_olua_uint8_value, _olua_fun_olua_uint8_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_uint8(lua_State *L)
{
    olua_require(L, "types",  _olua_module_types);
    if (!olua_getclass(L, "olua.uint8")) {
        luaL_error(L, "class not found: olua_uint8");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_olua_uint16___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint16");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_uint16___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.uint16");
    olua_check_integer(L, 2, &arg1);

    // uint16_t __index(unsigned int idx)
    uint16_t ret = self->__index(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint16___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    uint16_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.uint16");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void __newindex(unsigned int idx, const uint16_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_uint16_buffer(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint16");

    // @getter @type(void *) uint16_t *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint16_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint16");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint16_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // olua_uint16(@optional size_t len)
    olua_uint16 *ret = new olua_uint16(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint16");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint16_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // olua_uint16()
    olua_uint16 *ret = new olua_uint16();
    int num_ret = olua_push_object(L, ret, "olua.uint16");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint16_new$3(lua_State *L)
{
    olua_startinvoke(L);

    uint16_t *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_pointer(L, 1, &arg1, "olua.uint16");
    olua_check_integer(L, 2, &arg2);

    // olua_uint16(uint16_t *v, @optional size_t len)
    olua_uint16 *ret = new olua_uint16(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.uint16");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint16_new$4(lua_State *L)
{
    olua_startinvoke(L);

    uint16_t *arg1 = nullptr;       /** v */

    olua_check_pointer(L, 1, &arg1, "olua.uint16");

    // olua_uint16(uint16_t *v)
    olua_uint16 *ret = new olua_uint16(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint16");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint16_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // olua_uint16()
        return _olua_fun_olua_uint16_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // olua_uint16(@optional size_t len)
            return _olua_fun_olua_uint16_new$1(L);
        }

        // if ((olua_is_pointer(L, 1, "olua.uint16"))) {
            // olua_uint16(uint16_t *v)
            return _olua_fun_olua_uint16_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_pointer(L, 1, "olua.uint16")) && (olua_is_integer(L, 2))) {
            // olua_uint16(uint16_t *v, @optional size_t len)
            return _olua_fun_olua_uint16_new$3(L);
        // }
    }

    luaL_error(L, "method 'olua_uint16::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_uint16_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.uint16");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_uint16 *slice(size_t from, @optional size_t to)
    olua_uint16 *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.uint16");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint16_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.uint16");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_uint16 *slice(size_t from)
    olua_uint16 *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint16");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint16_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.uint16")) && (olua_is_integer(L, 2))) {
            // @postnew olua_uint16 *slice(size_t from)
            return _olua_fun_olua_uint16_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.uint16")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_uint16 *slice(size_t from, @optional size_t to)
            return _olua_fun_olua_uint16_slice$1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint16::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_uint16_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.uint16");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_uint16 *sub(size_t from, @optional size_t to)
    olua_uint16 *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.uint16");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint16_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.uint16");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_uint16 *sub(size_t from)
    olua_uint16 *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint16");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint16_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.uint16")) && (olua_is_integer(L, 2))) {
            // @postnew olua_uint16 *sub(size_t from)
            return _olua_fun_olua_uint16_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.uint16")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_uint16 *sub(size_t from, @optional size_t to)
            return _olua_fun_olua_uint16_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint16::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_uint16_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint16");

    // olua_uint16 *take()
    olua_uint16 *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.uint16");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint16_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.uint16");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_uint16_value$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint16");

    // @getter const uint16_t &value()
    const uint16_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint16_value$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;
    uint16_t arg1 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.uint16");
    olua_check_integer(L, 2, &arg1);

    // @setter void value(const uint16_t &v)
    self->value(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_uint16_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const uint16_t &value()
        return _olua_fun_olua_uint16_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.uint16")) && (olua_is_integer(L, 2))) {
            // @setter void value(const uint16_t &v)
            return _olua_fun_olua_uint16_value$2(L);
        // }
    }

    luaL_error(L, "method 'olua_uint16::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_olua_uint16(lua_State *L)
{
    oluacls_class<olua_uint16>(L, "olua.uint16");
    oluacls_func(L, "__gc", _olua_fun_olua_uint16___gc);
    oluacls_func(L, "__index", _olua_fun_olua_uint16___index);
    oluacls_func(L, "__newindex", _olua_fun_olua_uint16___newindex);
    oluacls_func(L, "new", _olua_fun_olua_uint16_new);
    oluacls_func(L, "slice", _olua_fun_olua_uint16_slice);
    oluacls_func(L, "sub", _olua_fun_olua_uint16_sub);
    oluacls_func(L, "take", _olua_fun_olua_uint16_take);
    oluacls_func(L, "tostring", _olua_fun_olua_uint16_tostring);
    oluacls_prop(L, "buffer", _olua_fun_olua_uint16_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_olua_uint16_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_olua_uint16_value, _olua_fun_olua_uint16_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_uint16(lua_State *L)
{
    olua_require(L, "types",  _olua_module_types);
    if (!olua_getclass(L, "olua.uint16")) {
        luaL_error(L, "class not found: olua_uint16");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_olua_uint32___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint32");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_uint32___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.uint32");
    olua_check_integer(L, 2, &arg1);

    // uint32_t __index(unsigned int idx)
    uint32_t ret = self->__index(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint32___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    uint32_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.uint32");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void __newindex(unsigned int idx, const uint32_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_uint32_buffer(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint32");

    // @getter @type(void *) uint32_t *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint32_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint32");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint32_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // olua_uint32(@optional size_t len)
    olua_uint32 *ret = new olua_uint32(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint32");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint32_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // olua_uint32()
    olua_uint32 *ret = new olua_uint32();
    int num_ret = olua_push_object(L, ret, "olua.uint32");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint32_new$3(lua_State *L)
{
    olua_startinvoke(L);

    uint32_t *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_pointer(L, 1, &arg1, "olua.uint32");
    olua_check_integer(L, 2, &arg2);

    // olua_uint32(uint32_t *v, @optional size_t len)
    olua_uint32 *ret = new olua_uint32(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.uint32");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint32_new$4(lua_State *L)
{
    olua_startinvoke(L);

    uint32_t *arg1 = nullptr;       /** v */

    olua_check_pointer(L, 1, &arg1, "olua.uint32");

    // olua_uint32(uint32_t *v)
    olua_uint32 *ret = new olua_uint32(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint32");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint32_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // olua_uint32()
        return _olua_fun_olua_uint32_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // olua_uint32(@optional size_t len)
            return _olua_fun_olua_uint32_new$1(L);
        }

        // if ((olua_is_pointer(L, 1, "olua.uint32"))) {
            // olua_uint32(uint32_t *v)
            return _olua_fun_olua_uint32_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_pointer(L, 1, "olua.uint32")) && (olua_is_integer(L, 2))) {
            // olua_uint32(uint32_t *v, @optional size_t len)
            return _olua_fun_olua_uint32_new$3(L);
        // }
    }

    luaL_error(L, "method 'olua_uint32::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_uint32_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.uint32");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_uint32 *slice(size_t from, @optional size_t to)
    olua_uint32 *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.uint32");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint32_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.uint32");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_uint32 *slice(size_t from)
    olua_uint32 *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint32");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint32_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.uint32")) && (olua_is_integer(L, 2))) {
            // @postnew olua_uint32 *slice(size_t from)
            return _olua_fun_olua_uint32_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.uint32")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_uint32 *slice(size_t from, @optional size_t to)
            return _olua_fun_olua_uint32_slice$1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint32::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_uint32_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.uint32");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_uint32 *sub(size_t from, @optional size_t to)
    olua_uint32 *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.uint32");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint32_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.uint32");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_uint32 *sub(size_t from)
    olua_uint32 *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint32");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint32_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.uint32")) && (olua_is_integer(L, 2))) {
            // @postnew olua_uint32 *sub(size_t from)
            return _olua_fun_olua_uint32_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.uint32")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_uint32 *sub(size_t from, @optional size_t to)
            return _olua_fun_olua_uint32_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint32::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_uint32_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint32");

    // olua_uint32 *take()
    olua_uint32 *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.uint32");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint32_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.uint32");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_uint32_value$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint32");

    // @getter const uint32_t &value()
    const uint32_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint32_value$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;
    uint32_t arg1 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.uint32");
    olua_check_integer(L, 2, &arg1);

    // @setter void value(const uint32_t &v)
    self->value(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_uint32_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const uint32_t &value()
        return _olua_fun_olua_uint32_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.uint32")) && (olua_is_integer(L, 2))) {
            // @setter void value(const uint32_t &v)
            return _olua_fun_olua_uint32_value$2(L);
        // }
    }

    luaL_error(L, "method 'olua_uint32::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_olua_uint32(lua_State *L)
{
    oluacls_class<olua_uint32>(L, "olua.uint32");
    oluacls_func(L, "__gc", _olua_fun_olua_uint32___gc);
    oluacls_func(L, "__index", _olua_fun_olua_uint32___index);
    oluacls_func(L, "__newindex", _olua_fun_olua_uint32___newindex);
    oluacls_func(L, "new", _olua_fun_olua_uint32_new);
    oluacls_func(L, "slice", _olua_fun_olua_uint32_slice);
    oluacls_func(L, "sub", _olua_fun_olua_uint32_sub);
    oluacls_func(L, "take", _olua_fun_olua_uint32_take);
    oluacls_func(L, "tostring", _olua_fun_olua_uint32_tostring);
    oluacls_prop(L, "buffer", _olua_fun_olua_uint32_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_olua_uint32_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_olua_uint32_value, _olua_fun_olua_uint32_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_uint32(lua_State *L)
{
    olua_require(L, "types",  _olua_module_types);
    if (!olua_getclass(L, "olua.uint32")) {
        luaL_error(L, "class not found: olua_uint32");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_olua_uint64___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint64");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_uint64___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.uint64");
    olua_check_integer(L, 2, &arg1);

    // uint64_t __index(unsigned int idx)
    uint64_t ret = self->__index(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint64___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    uint64_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.uint64");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void __newindex(unsigned int idx, const uint64_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_uint64_buffer(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint64");

    // @getter @type(void *) uint64_t *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint64_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint64");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint64_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // olua_uint64(@optional size_t len)
    olua_uint64 *ret = new olua_uint64(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint64");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint64_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // olua_uint64()
    olua_uint64 *ret = new olua_uint64();
    int num_ret = olua_push_object(L, ret, "olua.uint64");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint64_new$3(lua_State *L)
{
    olua_startinvoke(L);

    uint64_t *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_pointer(L, 1, &arg1, "olua.uint64");
    olua_check_integer(L, 2, &arg2);

    // olua_uint64(uint64_t *v, @optional size_t len)
    olua_uint64 *ret = new olua_uint64(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.uint64");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint64_new$4(lua_State *L)
{
    olua_startinvoke(L);

    uint64_t *arg1 = nullptr;       /** v */

    olua_check_pointer(L, 1, &arg1, "olua.uint64");

    // olua_uint64(uint64_t *v)
    olua_uint64 *ret = new olua_uint64(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint64");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint64_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // olua_uint64()
        return _olua_fun_olua_uint64_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // olua_uint64(@optional size_t len)
            return _olua_fun_olua_uint64_new$1(L);
        }

        // if ((olua_is_pointer(L, 1, "olua.uint64"))) {
            // olua_uint64(uint64_t *v)
            return _olua_fun_olua_uint64_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_pointer(L, 1, "olua.uint64")) && (olua_is_integer(L, 2))) {
            // olua_uint64(uint64_t *v, @optional size_t len)
            return _olua_fun_olua_uint64_new$3(L);
        // }
    }

    luaL_error(L, "method 'olua_uint64::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_uint64_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.uint64");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_uint64 *slice(size_t from, @optional size_t to)
    olua_uint64 *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.uint64");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint64_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.uint64");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_uint64 *slice(size_t from)
    olua_uint64 *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint64");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint64_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.uint64")) && (olua_is_integer(L, 2))) {
            // @postnew olua_uint64 *slice(size_t from)
            return _olua_fun_olua_uint64_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.uint64")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_uint64 *slice(size_t from, @optional size_t to)
            return _olua_fun_olua_uint64_slice$1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint64::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_uint64_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.uint64");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_uint64 *sub(size_t from, @optional size_t to)
    olua_uint64 *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.uint64");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint64_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.uint64");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_uint64 *sub(size_t from)
    olua_uint64 *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint64");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint64_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.uint64")) && (olua_is_integer(L, 2))) {
            // @postnew olua_uint64 *sub(size_t from)
            return _olua_fun_olua_uint64_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.uint64")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_uint64 *sub(size_t from, @optional size_t to)
            return _olua_fun_olua_uint64_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint64::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_uint64_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint64");

    // olua_uint64 *take()
    olua_uint64 *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.uint64");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint64_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.uint64");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_uint64_value$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint64");

    // @getter const uint64_t &value()
    const uint64_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint64_value$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;
    uint64_t arg1 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.uint64");
    olua_check_integer(L, 2, &arg1);

    // @setter void value(const uint64_t &v)
    self->value(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_uint64_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const uint64_t &value()
        return _olua_fun_olua_uint64_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.uint64")) && (olua_is_integer(L, 2))) {
            // @setter void value(const uint64_t &v)
            return _olua_fun_olua_uint64_value$2(L);
        // }
    }

    luaL_error(L, "method 'olua_uint64::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_olua_uint64(lua_State *L)
{
    oluacls_class<olua_uint64>(L, "olua.uint64");
    oluacls_func(L, "__gc", _olua_fun_olua_uint64___gc);
    oluacls_func(L, "__index", _olua_fun_olua_uint64___index);
    oluacls_func(L, "__newindex", _olua_fun_olua_uint64___newindex);
    oluacls_func(L, "new", _olua_fun_olua_uint64_new);
    oluacls_func(L, "slice", _olua_fun_olua_uint64_slice);
    oluacls_func(L, "sub", _olua_fun_olua_uint64_sub);
    oluacls_func(L, "take", _olua_fun_olua_uint64_take);
    oluacls_func(L, "tostring", _olua_fun_olua_uint64_tostring);
    oluacls_prop(L, "buffer", _olua_fun_olua_uint64_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_olua_uint64_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_olua_uint64_value, _olua_fun_olua_uint64_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_uint64(lua_State *L)
{
    olua_require(L, "types",  _olua_module_types);
    if (!olua_getclass(L, "olua.uint64")) {
        luaL_error(L, "class not found: olua_uint64");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_olua_char___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_char *self = nullptr;

    olua_to_object(L, 1, &self, "olua.char");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_char___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_char *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.char");
    olua_check_integer(L, 2, &arg1);

    // olua_char_t __index(unsigned int idx)
    olua_char_t ret = self->__index(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_char___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_char *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    olua_char_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.char");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void __newindex(unsigned int idx, const olua_char_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_char_buffer(lua_State *L)
{
    olua_startinvoke(L);

    olua_char *self = nullptr;

    olua_to_object(L, 1, &self, "olua.char");

    // @getter @type(void *) olua_char_t *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_char_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_char *self = nullptr;

    olua_to_object(L, 1, &self, "olua.char");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_char_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // olua_char(@optional size_t len)
    olua_char *ret = new olua_char(arg1);
    int num_ret = olua_push_object(L, ret, "olua.char");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_char_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // olua_char()
    olua_char *ret = new olua_char();
    int num_ret = olua_push_object(L, ret, "olua.char");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_char_new$3(lua_State *L)
{
    olua_startinvoke(L);

    olua_char_t *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_pointer(L, 1, &arg1, "olua.char");
    olua_check_integer(L, 2, &arg2);

    // olua_char(olua_char_t *v, @optional size_t len)
    olua_char *ret = new olua_char(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.char");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_char_new$4(lua_State *L)
{
    olua_startinvoke(L);

    olua_char_t *arg1 = nullptr;       /** v */

    olua_check_pointer(L, 1, &arg1, "olua.char");

    // olua_char(olua_char_t *v)
    olua_char *ret = new olua_char(arg1);
    int num_ret = olua_push_object(L, ret, "olua.char");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_char_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // olua_char()
        return _olua_fun_olua_char_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // olua_char(@optional size_t len)
            return _olua_fun_olua_char_new$1(L);
        }

        // if ((olua_is_pointer(L, 1, "olua.char"))) {
            // olua_char(olua_char_t *v)
            return _olua_fun_olua_char_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_pointer(L, 1, "olua.char")) && (olua_is_integer(L, 2))) {
            // olua_char(olua_char_t *v, @optional size_t len)
            return _olua_fun_olua_char_new$3(L);
        // }
    }

    luaL_error(L, "method 'olua_char::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_char_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_char *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.char");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_char *slice(size_t from, @optional size_t to)
    olua_char *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.char");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_char_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_char *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.char");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_char *slice(size_t from)
    olua_char *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "olua.char");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_char_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.char")) && (olua_is_integer(L, 2))) {
            // @postnew olua_char *slice(size_t from)
            return _olua_fun_olua_char_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.char")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_char *slice(size_t from, @optional size_t to)
            return _olua_fun_olua_char_slice$1(L);
        // }
    }

    luaL_error(L, "method 'olua_char::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_char_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_char *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.char");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_char *sub(size_t from, @optional size_t to)
    olua_char *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.char");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_char_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_char *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.char");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_char *sub(size_t from)
    olua_char *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.char");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_char_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.char")) && (olua_is_integer(L, 2))) {
            // @postnew olua_char *sub(size_t from)
            return _olua_fun_olua_char_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.char")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_char *sub(size_t from, @optional size_t to)
            return _olua_fun_olua_char_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_char::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_char_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_char *self = nullptr;

    olua_to_object(L, 1, &self, "olua.char");

    // olua_char *take()
    olua_char *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.char");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_char_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_char *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.char");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_char_value$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_char *self = nullptr;

    olua_to_object(L, 1, &self, "olua.char");

    // @getter const olua_char_t &value()
    const olua_char_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_char_value$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_char *self = nullptr;
    olua_char_t arg1 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.char");
    olua_check_integer(L, 2, &arg1);

    // @setter void value(const olua_char_t &v)
    self->value(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_char_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const olua_char_t &value()
        return _olua_fun_olua_char_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.char")) && (olua_is_integer(L, 2))) {
            // @setter void value(const olua_char_t &v)
            return _olua_fun_olua_char_value$2(L);
        // }
    }

    luaL_error(L, "method 'olua_char::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_olua_char(lua_State *L)
{
    oluacls_class<olua_char>(L, "olua.char");
    oluacls_func(L, "__gc", _olua_fun_olua_char___gc);
    oluacls_func(L, "__index", _olua_fun_olua_char___index);
    oluacls_func(L, "__newindex", _olua_fun_olua_char___newindex);
    oluacls_func(L, "new", _olua_fun_olua_char_new);
    oluacls_func(L, "slice", _olua_fun_olua_char_slice);
    oluacls_func(L, "sub", _olua_fun_olua_char_sub);
    oluacls_func(L, "take", _olua_fun_olua_char_take);
    oluacls_func(L, "tostring", _olua_fun_olua_char_tostring);
    oluacls_prop(L, "buffer", _olua_fun_olua_char_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_olua_char_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_olua_char_value, _olua_fun_olua_char_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_char(lua_State *L)
{
    olua_require(L, "types",  _olua_module_types);
    if (!olua_getclass(L, "olua.char")) {
        luaL_error(L, "class not found: olua_char");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_olua_short___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;

    olua_to_object(L, 1, &self, "olua.short");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_short___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.short");
    olua_check_integer(L, 2, &arg1);

    // olua_short_t __index(unsigned int idx)
    olua_short_t ret = self->__index(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_short___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    olua_short_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.short");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void __newindex(unsigned int idx, const olua_short_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_short_buffer(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;

    olua_to_object(L, 1, &self, "olua.short");

    // @getter @type(void *) olua_short_t *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_short_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;

    olua_to_object(L, 1, &self, "olua.short");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_short_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // olua_short(@optional size_t len)
    olua_short *ret = new olua_short(arg1);
    int num_ret = olua_push_object(L, ret, "olua.short");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_short_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // olua_short()
    olua_short *ret = new olua_short();
    int num_ret = olua_push_object(L, ret, "olua.short");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_short_new$3(lua_State *L)
{
    olua_startinvoke(L);

    olua_short_t *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_pointer(L, 1, &arg1, "olua.short");
    olua_check_integer(L, 2, &arg2);

    // olua_short(olua_short_t *v, @optional size_t len)
    olua_short *ret = new olua_short(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.short");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_short_new$4(lua_State *L)
{
    olua_startinvoke(L);

    olua_short_t *arg1 = nullptr;       /** v */

    olua_check_pointer(L, 1, &arg1, "olua.short");

    // olua_short(olua_short_t *v)
    olua_short *ret = new olua_short(arg1);
    int num_ret = olua_push_object(L, ret, "olua.short");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_short_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // olua_short()
        return _olua_fun_olua_short_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // olua_short(@optional size_t len)
            return _olua_fun_olua_short_new$1(L);
        }

        // if ((olua_is_pointer(L, 1, "olua.short"))) {
            // olua_short(olua_short_t *v)
            return _olua_fun_olua_short_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_pointer(L, 1, "olua.short")) && (olua_is_integer(L, 2))) {
            // olua_short(olua_short_t *v, @optional size_t len)
            return _olua_fun_olua_short_new$3(L);
        // }
    }

    luaL_error(L, "method 'olua_short::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_short_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.short");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_short *slice(size_t from, @optional size_t to)
    olua_short *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.short");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_short_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.short");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_short *slice(size_t from)
    olua_short *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "olua.short");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_short_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.short")) && (olua_is_integer(L, 2))) {
            // @postnew olua_short *slice(size_t from)
            return _olua_fun_olua_short_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.short")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_short *slice(size_t from, @optional size_t to)
            return _olua_fun_olua_short_slice$1(L);
        // }
    }

    luaL_error(L, "method 'olua_short::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_short_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.short");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_short *sub(size_t from, @optional size_t to)
    olua_short *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.short");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_short_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.short");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_short *sub(size_t from)
    olua_short *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.short");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_short_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.short")) && (olua_is_integer(L, 2))) {
            // @postnew olua_short *sub(size_t from)
            return _olua_fun_olua_short_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.short")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_short *sub(size_t from, @optional size_t to)
            return _olua_fun_olua_short_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_short::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_short_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;

    olua_to_object(L, 1, &self, "olua.short");

    // olua_short *take()
    olua_short *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.short");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_short_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.short");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_short_value$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;

    olua_to_object(L, 1, &self, "olua.short");

    // @getter const olua_short_t &value()
    const olua_short_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_short_value$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;
    olua_short_t arg1 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.short");
    olua_check_integer(L, 2, &arg1);

    // @setter void value(const olua_short_t &v)
    self->value(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_short_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const olua_short_t &value()
        return _olua_fun_olua_short_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.short")) && (olua_is_integer(L, 2))) {
            // @setter void value(const olua_short_t &v)
            return _olua_fun_olua_short_value$2(L);
        // }
    }

    luaL_error(L, "method 'olua_short::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_olua_short(lua_State *L)
{
    oluacls_class<olua_short>(L, "olua.short");
    oluacls_func(L, "__gc", _olua_fun_olua_short___gc);
    oluacls_func(L, "__index", _olua_fun_olua_short___index);
    oluacls_func(L, "__newindex", _olua_fun_olua_short___newindex);
    oluacls_func(L, "new", _olua_fun_olua_short_new);
    oluacls_func(L, "slice", _olua_fun_olua_short_slice);
    oluacls_func(L, "sub", _olua_fun_olua_short_sub);
    oluacls_func(L, "take", _olua_fun_olua_short_take);
    oluacls_func(L, "tostring", _olua_fun_olua_short_tostring);
    oluacls_prop(L, "buffer", _olua_fun_olua_short_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_olua_short_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_olua_short_value, _olua_fun_olua_short_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_short(lua_State *L)
{
    olua_require(L, "types",  _olua_module_types);
    if (!olua_getclass(L, "olua.short")) {
        luaL_error(L, "class not found: olua_short");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_olua_int___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_int___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.int");
    olua_check_integer(L, 2, &arg1);

    // olua_int_t __index(unsigned int idx)
    olua_int_t ret = self->__index(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    olua_int_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.int");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void __newindex(unsigned int idx, const olua_int_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_int_buffer(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int");

    // @getter @type(void *) olua_int_t *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // olua_int(@optional size_t len)
    olua_int *ret = new olua_int(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // olua_int()
    olua_int *ret = new olua_int();
    int num_ret = olua_push_object(L, ret, "olua.int");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int_new$3(lua_State *L)
{
    olua_startinvoke(L);

    olua_int_t *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_pointer(L, 1, &arg1, "olua.int");
    olua_check_integer(L, 2, &arg2);

    // olua_int(olua_int_t *v, @optional size_t len)
    olua_int *ret = new olua_int(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.int");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int_new$4(lua_State *L)
{
    olua_startinvoke(L);

    olua_int_t *arg1 = nullptr;       /** v */

    olua_check_pointer(L, 1, &arg1, "olua.int");

    // olua_int(olua_int_t *v)
    olua_int *ret = new olua_int(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // olua_int()
        return _olua_fun_olua_int_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // olua_int(@optional size_t len)
            return _olua_fun_olua_int_new$1(L);
        }

        // if ((olua_is_pointer(L, 1, "olua.int"))) {
            // olua_int(olua_int_t *v)
            return _olua_fun_olua_int_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_pointer(L, 1, "olua.int")) && (olua_is_integer(L, 2))) {
            // olua_int(olua_int_t *v, @optional size_t len)
            return _olua_fun_olua_int_new$3(L);
        // }
    }

    luaL_error(L, "method 'olua_int::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_int_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.int");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_int *slice(size_t from, @optional size_t to)
    olua_int *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.int");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.int");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_int *slice(size_t from)
    olua_int *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.int")) && (olua_is_integer(L, 2))) {
            // @postnew olua_int *slice(size_t from)
            return _olua_fun_olua_int_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.int")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_int *slice(size_t from, @optional size_t to)
            return _olua_fun_olua_int_slice$1(L);
        // }
    }

    luaL_error(L, "method 'olua_int::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_int_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.int");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_int *sub(size_t from, @optional size_t to)
    olua_int *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.int");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.int");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_int *sub(size_t from)
    olua_int *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.int")) && (olua_is_integer(L, 2))) {
            // @postnew olua_int *sub(size_t from)
            return _olua_fun_olua_int_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.int")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_int *sub(size_t from, @optional size_t to)
            return _olua_fun_olua_int_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_int::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_int_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int");

    // olua_int *take()
    olua_int *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.int");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.int");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_int_value$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int");

    // @getter const olua_int_t &value()
    const olua_int_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_int_value$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;
    olua_int_t arg1 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.int");
    olua_check_integer(L, 2, &arg1);

    // @setter void value(const olua_int_t &v)
    self->value(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_int_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const olua_int_t &value()
        return _olua_fun_olua_int_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.int")) && (olua_is_integer(L, 2))) {
            // @setter void value(const olua_int_t &v)
            return _olua_fun_olua_int_value$2(L);
        // }
    }

    luaL_error(L, "method 'olua_int::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_olua_int(lua_State *L)
{
    oluacls_class<olua_int>(L, "olua.int");
    oluacls_func(L, "__gc", _olua_fun_olua_int___gc);
    oluacls_func(L, "__index", _olua_fun_olua_int___index);
    oluacls_func(L, "__newindex", _olua_fun_olua_int___newindex);
    oluacls_func(L, "new", _olua_fun_olua_int_new);
    oluacls_func(L, "slice", _olua_fun_olua_int_slice);
    oluacls_func(L, "sub", _olua_fun_olua_int_sub);
    oluacls_func(L, "take", _olua_fun_olua_int_take);
    oluacls_func(L, "tostring", _olua_fun_olua_int_tostring);
    oluacls_prop(L, "buffer", _olua_fun_olua_int_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_olua_int_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_olua_int_value, _olua_fun_olua_int_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_int(lua_State *L)
{
    olua_require(L, "types",  _olua_module_types);
    if (!olua_getclass(L, "olua.int")) {
        luaL_error(L, "class not found: olua_int");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_olua_long___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;

    olua_to_object(L, 1, &self, "olua.long");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_long___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.long");
    olua_check_integer(L, 2, &arg1);

    // olua_long_t __index(unsigned int idx)
    olua_long_t ret = self->__index(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_long___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    olua_long_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.long");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void __newindex(unsigned int idx, const olua_long_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_long_buffer(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;

    olua_to_object(L, 1, &self, "olua.long");

    // @getter @type(void *) olua_long_t *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_long_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;

    olua_to_object(L, 1, &self, "olua.long");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_long_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // olua_long(@optional size_t len)
    olua_long *ret = new olua_long(arg1);
    int num_ret = olua_push_object(L, ret, "olua.long");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_long_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // olua_long()
    olua_long *ret = new olua_long();
    int num_ret = olua_push_object(L, ret, "olua.long");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_long_new$3(lua_State *L)
{
    olua_startinvoke(L);

    olua_long_t *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_pointer(L, 1, &arg1, "olua.long");
    olua_check_integer(L, 2, &arg2);

    // olua_long(olua_long_t *v, @optional size_t len)
    olua_long *ret = new olua_long(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.long");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_long_new$4(lua_State *L)
{
    olua_startinvoke(L);

    olua_long_t *arg1 = nullptr;       /** v */

    olua_check_pointer(L, 1, &arg1, "olua.long");

    // olua_long(olua_long_t *v)
    olua_long *ret = new olua_long(arg1);
    int num_ret = olua_push_object(L, ret, "olua.long");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_long_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // olua_long()
        return _olua_fun_olua_long_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // olua_long(@optional size_t len)
            return _olua_fun_olua_long_new$1(L);
        }

        // if ((olua_is_pointer(L, 1, "olua.long"))) {
            // olua_long(olua_long_t *v)
            return _olua_fun_olua_long_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_pointer(L, 1, "olua.long")) && (olua_is_integer(L, 2))) {
            // olua_long(olua_long_t *v, @optional size_t len)
            return _olua_fun_olua_long_new$3(L);
        // }
    }

    luaL_error(L, "method 'olua_long::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_long_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.long");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_long *slice(size_t from, @optional size_t to)
    olua_long *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.long");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_long_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.long");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_long *slice(size_t from)
    olua_long *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "olua.long");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_long_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.long")) && (olua_is_integer(L, 2))) {
            // @postnew olua_long *slice(size_t from)
            return _olua_fun_olua_long_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.long")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_long *slice(size_t from, @optional size_t to)
            return _olua_fun_olua_long_slice$1(L);
        // }
    }

    luaL_error(L, "method 'olua_long::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_long_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.long");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_long *sub(size_t from, @optional size_t to)
    olua_long *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.long");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_long_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.long");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_long *sub(size_t from)
    olua_long *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.long");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_long_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.long")) && (olua_is_integer(L, 2))) {
            // @postnew olua_long *sub(size_t from)
            return _olua_fun_olua_long_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.long")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_long *sub(size_t from, @optional size_t to)
            return _olua_fun_olua_long_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_long::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_long_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;

    olua_to_object(L, 1, &self, "olua.long");

    // olua_long *take()
    olua_long *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.long");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_long_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.long");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_long_value$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;

    olua_to_object(L, 1, &self, "olua.long");

    // @getter const olua_long_t &value()
    const olua_long_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_long_value$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;
    olua_long_t arg1 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.long");
    olua_check_integer(L, 2, &arg1);

    // @setter void value(const olua_long_t &v)
    self->value(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_long_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const olua_long_t &value()
        return _olua_fun_olua_long_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.long")) && (olua_is_integer(L, 2))) {
            // @setter void value(const olua_long_t &v)
            return _olua_fun_olua_long_value$2(L);
        // }
    }

    luaL_error(L, "method 'olua_long::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_olua_long(lua_State *L)
{
    oluacls_class<olua_long>(L, "olua.long");
    oluacls_func(L, "__gc", _olua_fun_olua_long___gc);
    oluacls_func(L, "__index", _olua_fun_olua_long___index);
    oluacls_func(L, "__newindex", _olua_fun_olua_long___newindex);
    oluacls_func(L, "new", _olua_fun_olua_long_new);
    oluacls_func(L, "slice", _olua_fun_olua_long_slice);
    oluacls_func(L, "sub", _olua_fun_olua_long_sub);
    oluacls_func(L, "take", _olua_fun_olua_long_take);
    oluacls_func(L, "tostring", _olua_fun_olua_long_tostring);
    oluacls_prop(L, "buffer", _olua_fun_olua_long_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_olua_long_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_olua_long_value, _olua_fun_olua_long_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_long(lua_State *L)
{
    olua_require(L, "types",  _olua_module_types);
    if (!olua_getclass(L, "olua.long")) {
        luaL_error(L, "class not found: olua_long");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_olua_llong___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.llong");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_llong___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.llong");
    olua_check_integer(L, 2, &arg1);

    // olua_llong_t __index(unsigned int idx)
    olua_llong_t ret = self->__index(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_llong___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    olua_llong_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.llong");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void __newindex(unsigned int idx, const olua_llong_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_llong_buffer(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.llong");

    // @getter @type(void *) olua_llong_t *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_llong_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.llong");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_llong_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // olua_llong(@optional size_t len)
    olua_llong *ret = new olua_llong(arg1);
    int num_ret = olua_push_object(L, ret, "olua.llong");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_llong_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // olua_llong()
    olua_llong *ret = new olua_llong();
    int num_ret = olua_push_object(L, ret, "olua.llong");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_llong_new$3(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong_t *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_pointer(L, 1, &arg1, "olua.llong");
    olua_check_integer(L, 2, &arg2);

    // olua_llong(olua_llong_t *v, @optional size_t len)
    olua_llong *ret = new olua_llong(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.llong");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_llong_new$4(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong_t *arg1 = nullptr;       /** v */

    olua_check_pointer(L, 1, &arg1, "olua.llong");

    // olua_llong(olua_llong_t *v)
    olua_llong *ret = new olua_llong(arg1);
    int num_ret = olua_push_object(L, ret, "olua.llong");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_llong_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // olua_llong()
        return _olua_fun_olua_llong_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // olua_llong(@optional size_t len)
            return _olua_fun_olua_llong_new$1(L);
        }

        // if ((olua_is_pointer(L, 1, "olua.llong"))) {
            // olua_llong(olua_llong_t *v)
            return _olua_fun_olua_llong_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_pointer(L, 1, "olua.llong")) && (olua_is_integer(L, 2))) {
            // olua_llong(olua_llong_t *v, @optional size_t len)
            return _olua_fun_olua_llong_new$3(L);
        // }
    }

    luaL_error(L, "method 'olua_llong::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_llong_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.llong");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_llong *slice(size_t from, @optional size_t to)
    olua_llong *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.llong");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_llong_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.llong");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_llong *slice(size_t from)
    olua_llong *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "olua.llong");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_llong_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.llong")) && (olua_is_integer(L, 2))) {
            // @postnew olua_llong *slice(size_t from)
            return _olua_fun_olua_llong_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.llong")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_llong *slice(size_t from, @optional size_t to)
            return _olua_fun_olua_llong_slice$1(L);
        // }
    }

    luaL_error(L, "method 'olua_llong::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_llong_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.llong");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_llong *sub(size_t from, @optional size_t to)
    olua_llong *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.llong");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_llong_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.llong");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_llong *sub(size_t from)
    olua_llong *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.llong");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_llong_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.llong")) && (olua_is_integer(L, 2))) {
            // @postnew olua_llong *sub(size_t from)
            return _olua_fun_olua_llong_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.llong")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_llong *sub(size_t from, @optional size_t to)
            return _olua_fun_olua_llong_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_llong::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_llong_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.llong");

    // olua_llong *take()
    olua_llong *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.llong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_llong_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.llong");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_llong_value$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.llong");

    // @getter const olua_llong_t &value()
    const olua_llong_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_llong_value$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;
    olua_llong_t arg1 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.llong");
    olua_check_integer(L, 2, &arg1);

    // @setter void value(const olua_llong_t &v)
    self->value(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_llong_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const olua_llong_t &value()
        return _olua_fun_olua_llong_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.llong")) && (olua_is_integer(L, 2))) {
            // @setter void value(const olua_llong_t &v)
            return _olua_fun_olua_llong_value$2(L);
        // }
    }

    luaL_error(L, "method 'olua_llong::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_olua_llong(lua_State *L)
{
    oluacls_class<olua_llong>(L, "olua.llong");
    oluacls_func(L, "__gc", _olua_fun_olua_llong___gc);
    oluacls_func(L, "__index", _olua_fun_olua_llong___index);
    oluacls_func(L, "__newindex", _olua_fun_olua_llong___newindex);
    oluacls_func(L, "new", _olua_fun_olua_llong_new);
    oluacls_func(L, "slice", _olua_fun_olua_llong_slice);
    oluacls_func(L, "sub", _olua_fun_olua_llong_sub);
    oluacls_func(L, "take", _olua_fun_olua_llong_take);
    oluacls_func(L, "tostring", _olua_fun_olua_llong_tostring);
    oluacls_prop(L, "buffer", _olua_fun_olua_llong_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_olua_llong_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_olua_llong_value, _olua_fun_olua_llong_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_llong(lua_State *L)
{
    olua_require(L, "types",  _olua_module_types);
    if (!olua_getclass(L, "olua.llong")) {
        luaL_error(L, "class not found: olua_llong");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_olua_uchar___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_uchar *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uchar");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_uchar___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_uchar *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.uchar");
    olua_check_integer(L, 2, &arg1);

    // olua_uchar_t __index(unsigned int idx)
    olua_uchar_t ret = self->__index(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uchar___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_uchar *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    olua_uchar_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.uchar");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void __newindex(unsigned int idx, const olua_uchar_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_uchar_buffer(lua_State *L)
{
    olua_startinvoke(L);

    olua_uchar *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uchar");

    // @getter @type(void *) olua_uchar_t *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uchar_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_uchar *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uchar");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uchar_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // olua_uchar(@optional size_t len)
    olua_uchar *ret = new olua_uchar(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uchar");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uchar_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // olua_uchar()
    olua_uchar *ret = new olua_uchar();
    int num_ret = olua_push_object(L, ret, "olua.uchar");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uchar_new$3(lua_State *L)
{
    olua_startinvoke(L);

    olua_uchar_t *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_pointer(L, 1, &arg1, "olua.uchar");
    olua_check_integer(L, 2, &arg2);

    // olua_uchar(olua_uchar_t *v, @optional size_t len)
    olua_uchar *ret = new olua_uchar(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.uchar");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uchar_new$4(lua_State *L)
{
    olua_startinvoke(L);

    olua_uchar_t *arg1 = nullptr;       /** v */

    olua_check_pointer(L, 1, &arg1, "olua.uchar");

    // olua_uchar(olua_uchar_t *v)
    olua_uchar *ret = new olua_uchar(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uchar");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uchar_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // olua_uchar()
        return _olua_fun_olua_uchar_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // olua_uchar(@optional size_t len)
            return _olua_fun_olua_uchar_new$1(L);
        }

        // if ((olua_is_pointer(L, 1, "olua.uchar"))) {
            // olua_uchar(olua_uchar_t *v)
            return _olua_fun_olua_uchar_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_pointer(L, 1, "olua.uchar")) && (olua_is_integer(L, 2))) {
            // olua_uchar(olua_uchar_t *v, @optional size_t len)
            return _olua_fun_olua_uchar_new$3(L);
        // }
    }

    luaL_error(L, "method 'olua_uchar::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_uchar_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uchar *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.uchar");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_uchar *slice(size_t from, @optional size_t to)
    olua_uchar *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.uchar");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uchar_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uchar *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.uchar");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_uchar *slice(size_t from)
    olua_uchar *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uchar");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uchar_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.uchar")) && (olua_is_integer(L, 2))) {
            // @postnew olua_uchar *slice(size_t from)
            return _olua_fun_olua_uchar_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.uchar")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_uchar *slice(size_t from, @optional size_t to)
            return _olua_fun_olua_uchar_slice$1(L);
        // }
    }

    luaL_error(L, "method 'olua_uchar::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_uchar_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uchar *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.uchar");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_uchar *sub(size_t from, @optional size_t to)
    olua_uchar *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.uchar");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uchar_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uchar *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.uchar");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_uchar *sub(size_t from)
    olua_uchar *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uchar");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uchar_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.uchar")) && (olua_is_integer(L, 2))) {
            // @postnew olua_uchar *sub(size_t from)
            return _olua_fun_olua_uchar_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.uchar")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_uchar *sub(size_t from, @optional size_t to)
            return _olua_fun_olua_uchar_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_uchar::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_uchar_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_uchar *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uchar");

    // olua_uchar *take()
    olua_uchar *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.uchar");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uchar_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_uchar *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.uchar");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_uchar_value$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uchar *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uchar");

    // @getter const olua_uchar_t &value()
    const olua_uchar_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uchar_value$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uchar *self = nullptr;
    olua_uchar_t arg1 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.uchar");
    olua_check_integer(L, 2, &arg1);

    // @setter void value(const olua_uchar_t &v)
    self->value(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_uchar_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const olua_uchar_t &value()
        return _olua_fun_olua_uchar_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.uchar")) && (olua_is_integer(L, 2))) {
            // @setter void value(const olua_uchar_t &v)
            return _olua_fun_olua_uchar_value$2(L);
        // }
    }

    luaL_error(L, "method 'olua_uchar::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_olua_uchar(lua_State *L)
{
    oluacls_class<olua_uchar>(L, "olua.uchar");
    oluacls_func(L, "__gc", _olua_fun_olua_uchar___gc);
    oluacls_func(L, "__index", _olua_fun_olua_uchar___index);
    oluacls_func(L, "__newindex", _olua_fun_olua_uchar___newindex);
    oluacls_func(L, "new", _olua_fun_olua_uchar_new);
    oluacls_func(L, "slice", _olua_fun_olua_uchar_slice);
    oluacls_func(L, "sub", _olua_fun_olua_uchar_sub);
    oluacls_func(L, "take", _olua_fun_olua_uchar_take);
    oluacls_func(L, "tostring", _olua_fun_olua_uchar_tostring);
    oluacls_prop(L, "buffer", _olua_fun_olua_uchar_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_olua_uchar_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_olua_uchar_value, _olua_fun_olua_uchar_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_uchar(lua_State *L)
{
    olua_require(L, "types",  _olua_module_types);
    if (!olua_getclass(L, "olua.uchar")) {
        luaL_error(L, "class not found: olua_uchar");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_olua_ushort___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ushort");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_ushort___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.ushort");
    olua_check_integer(L, 2, &arg1);

    // olua_ushort_t __index(unsigned int idx)
    olua_ushort_t ret = self->__index(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ushort___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    olua_ushort_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.ushort");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void __newindex(unsigned int idx, const olua_ushort_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_ushort_buffer(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ushort");

    // @getter @type(void *) olua_ushort_t *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ushort_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ushort");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ushort_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // olua_ushort(@optional size_t len)
    olua_ushort *ret = new olua_ushort(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ushort");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ushort_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // olua_ushort()
    olua_ushort *ret = new olua_ushort();
    int num_ret = olua_push_object(L, ret, "olua.ushort");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ushort_new$3(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort_t *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_pointer(L, 1, &arg1, "olua.ushort");
    olua_check_integer(L, 2, &arg2);

    // olua_ushort(olua_ushort_t *v, @optional size_t len)
    olua_ushort *ret = new olua_ushort(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.ushort");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ushort_new$4(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort_t *arg1 = nullptr;       /** v */

    olua_check_pointer(L, 1, &arg1, "olua.ushort");

    // olua_ushort(olua_ushort_t *v)
    olua_ushort *ret = new olua_ushort(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ushort");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ushort_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // olua_ushort()
        return _olua_fun_olua_ushort_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // olua_ushort(@optional size_t len)
            return _olua_fun_olua_ushort_new$1(L);
        }

        // if ((olua_is_pointer(L, 1, "olua.ushort"))) {
            // olua_ushort(olua_ushort_t *v)
            return _olua_fun_olua_ushort_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_pointer(L, 1, "olua.ushort")) && (olua_is_integer(L, 2))) {
            // olua_ushort(olua_ushort_t *v, @optional size_t len)
            return _olua_fun_olua_ushort_new$3(L);
        // }
    }

    luaL_error(L, "method 'olua_ushort::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_ushort_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.ushort");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_ushort *slice(size_t from, @optional size_t to)
    olua_ushort *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.ushort");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ushort_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.ushort");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_ushort *slice(size_t from)
    olua_ushort *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ushort");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ushort_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.ushort")) && (olua_is_integer(L, 2))) {
            // @postnew olua_ushort *slice(size_t from)
            return _olua_fun_olua_ushort_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.ushort")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_ushort *slice(size_t from, @optional size_t to)
            return _olua_fun_olua_ushort_slice$1(L);
        // }
    }

    luaL_error(L, "method 'olua_ushort::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_ushort_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.ushort");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_ushort *sub(size_t from, @optional size_t to)
    olua_ushort *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.ushort");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ushort_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.ushort");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_ushort *sub(size_t from)
    olua_ushort *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ushort");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ushort_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.ushort")) && (olua_is_integer(L, 2))) {
            // @postnew olua_ushort *sub(size_t from)
            return _olua_fun_olua_ushort_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.ushort")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_ushort *sub(size_t from, @optional size_t to)
            return _olua_fun_olua_ushort_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_ushort::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_ushort_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ushort");

    // olua_ushort *take()
    olua_ushort *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.ushort");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ushort_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.ushort");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_ushort_value$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ushort");

    // @getter const olua_ushort_t &value()
    const olua_ushort_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ushort_value$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;
    olua_ushort_t arg1 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.ushort");
    olua_check_integer(L, 2, &arg1);

    // @setter void value(const olua_ushort_t &v)
    self->value(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_ushort_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const olua_ushort_t &value()
        return _olua_fun_olua_ushort_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.ushort")) && (olua_is_integer(L, 2))) {
            // @setter void value(const olua_ushort_t &v)
            return _olua_fun_olua_ushort_value$2(L);
        // }
    }

    luaL_error(L, "method 'olua_ushort::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_olua_ushort(lua_State *L)
{
    oluacls_class<olua_ushort>(L, "olua.ushort");
    oluacls_func(L, "__gc", _olua_fun_olua_ushort___gc);
    oluacls_func(L, "__index", _olua_fun_olua_ushort___index);
    oluacls_func(L, "__newindex", _olua_fun_olua_ushort___newindex);
    oluacls_func(L, "new", _olua_fun_olua_ushort_new);
    oluacls_func(L, "slice", _olua_fun_olua_ushort_slice);
    oluacls_func(L, "sub", _olua_fun_olua_ushort_sub);
    oluacls_func(L, "take", _olua_fun_olua_ushort_take);
    oluacls_func(L, "tostring", _olua_fun_olua_ushort_tostring);
    oluacls_prop(L, "buffer", _olua_fun_olua_ushort_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_olua_ushort_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_olua_ushort_value, _olua_fun_olua_ushort_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_ushort(lua_State *L)
{
    olua_require(L, "types",  _olua_module_types);
    if (!olua_getclass(L, "olua.ushort")) {
        luaL_error(L, "class not found: olua_ushort");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_olua_uint___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_uint___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.uint");
    olua_check_integer(L, 2, &arg1);

    // olua_uint_t __index(unsigned int idx)
    olua_uint_t ret = self->__index(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    olua_uint_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.uint");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void __newindex(unsigned int idx, const olua_uint_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_uint_buffer(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint");

    // @getter @type(void *) olua_uint_t *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // olua_uint(@optional size_t len)
    olua_uint *ret = new olua_uint(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // olua_uint()
    olua_uint *ret = new olua_uint();
    int num_ret = olua_push_object(L, ret, "olua.uint");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint_new$3(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint_t *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_pointer(L, 1, &arg1, "olua.uint");
    olua_check_integer(L, 2, &arg2);

    // olua_uint(olua_uint_t *v, @optional size_t len)
    olua_uint *ret = new olua_uint(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.uint");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint_new$4(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint_t *arg1 = nullptr;       /** v */

    olua_check_pointer(L, 1, &arg1, "olua.uint");

    // olua_uint(olua_uint_t *v)
    olua_uint *ret = new olua_uint(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // olua_uint()
        return _olua_fun_olua_uint_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // olua_uint(@optional size_t len)
            return _olua_fun_olua_uint_new$1(L);
        }

        // if ((olua_is_pointer(L, 1, "olua.uint"))) {
            // olua_uint(olua_uint_t *v)
            return _olua_fun_olua_uint_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_pointer(L, 1, "olua.uint")) && (olua_is_integer(L, 2))) {
            // olua_uint(olua_uint_t *v, @optional size_t len)
            return _olua_fun_olua_uint_new$3(L);
        // }
    }

    luaL_error(L, "method 'olua_uint::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_uint_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.uint");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_uint *slice(size_t from, @optional size_t to)
    olua_uint *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.uint");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.uint");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_uint *slice(size_t from)
    olua_uint *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.uint")) && (olua_is_integer(L, 2))) {
            // @postnew olua_uint *slice(size_t from)
            return _olua_fun_olua_uint_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.uint")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_uint *slice(size_t from, @optional size_t to)
            return _olua_fun_olua_uint_slice$1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_uint_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.uint");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_uint *sub(size_t from, @optional size_t to)
    olua_uint *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.uint");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.uint");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_uint *sub(size_t from)
    olua_uint *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.uint")) && (olua_is_integer(L, 2))) {
            // @postnew olua_uint *sub(size_t from)
            return _olua_fun_olua_uint_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.uint")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_uint *sub(size_t from, @optional size_t to)
            return _olua_fun_olua_uint_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_uint_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint");

    // olua_uint *take()
    olua_uint *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.uint");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.uint");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_uint_value$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint");

    // @getter const olua_uint_t &value()
    const olua_uint_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_uint_value$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;
    olua_uint_t arg1 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.uint");
    olua_check_integer(L, 2, &arg1);

    // @setter void value(const olua_uint_t &v)
    self->value(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_uint_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const olua_uint_t &value()
        return _olua_fun_olua_uint_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.uint")) && (olua_is_integer(L, 2))) {
            // @setter void value(const olua_uint_t &v)
            return _olua_fun_olua_uint_value$2(L);
        // }
    }

    luaL_error(L, "method 'olua_uint::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_olua_uint(lua_State *L)
{
    oluacls_class<olua_uint>(L, "olua.uint");
    oluacls_func(L, "__gc", _olua_fun_olua_uint___gc);
    oluacls_func(L, "__index", _olua_fun_olua_uint___index);
    oluacls_func(L, "__newindex", _olua_fun_olua_uint___newindex);
    oluacls_func(L, "new", _olua_fun_olua_uint_new);
    oluacls_func(L, "slice", _olua_fun_olua_uint_slice);
    oluacls_func(L, "sub", _olua_fun_olua_uint_sub);
    oluacls_func(L, "take", _olua_fun_olua_uint_take);
    oluacls_func(L, "tostring", _olua_fun_olua_uint_tostring);
    oluacls_prop(L, "buffer", _olua_fun_olua_uint_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_olua_uint_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_olua_uint_value, _olua_fun_olua_uint_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_uint(lua_State *L)
{
    olua_require(L, "types",  _olua_module_types);
    if (!olua_getclass(L, "olua.uint")) {
        luaL_error(L, "class not found: olua_uint");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_olua_ulong___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ulong");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_ulong___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.ulong");
    olua_check_integer(L, 2, &arg1);

    // olua_ulong_t __index(unsigned int idx)
    olua_ulong_t ret = self->__index(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ulong___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    olua_ulong_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.ulong");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void __newindex(unsigned int idx, const olua_ulong_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_ulong_buffer(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ulong");

    // @getter @type(void *) olua_ulong_t *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ulong_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ulong");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ulong_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // olua_ulong(@optional size_t len)
    olua_ulong *ret = new olua_ulong(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ulong");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ulong_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // olua_ulong()
    olua_ulong *ret = new olua_ulong();
    int num_ret = olua_push_object(L, ret, "olua.ulong");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ulong_new$3(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong_t *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_pointer(L, 1, &arg1, "olua.ulong");
    olua_check_integer(L, 2, &arg2);

    // olua_ulong(olua_ulong_t *v, @optional size_t len)
    olua_ulong *ret = new olua_ulong(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.ulong");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ulong_new$4(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong_t *arg1 = nullptr;       /** v */

    olua_check_pointer(L, 1, &arg1, "olua.ulong");

    // olua_ulong(olua_ulong_t *v)
    olua_ulong *ret = new olua_ulong(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ulong");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ulong_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // olua_ulong()
        return _olua_fun_olua_ulong_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // olua_ulong(@optional size_t len)
            return _olua_fun_olua_ulong_new$1(L);
        }

        // if ((olua_is_pointer(L, 1, "olua.ulong"))) {
            // olua_ulong(olua_ulong_t *v)
            return _olua_fun_olua_ulong_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_pointer(L, 1, "olua.ulong")) && (olua_is_integer(L, 2))) {
            // olua_ulong(olua_ulong_t *v, @optional size_t len)
            return _olua_fun_olua_ulong_new$3(L);
        // }
    }

    luaL_error(L, "method 'olua_ulong::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_ulong_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.ulong");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_ulong *slice(size_t from, @optional size_t to)
    olua_ulong *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.ulong");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ulong_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.ulong");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_ulong *slice(size_t from)
    olua_ulong *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ulong");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ulong_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.ulong")) && (olua_is_integer(L, 2))) {
            // @postnew olua_ulong *slice(size_t from)
            return _olua_fun_olua_ulong_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.ulong")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_ulong *slice(size_t from, @optional size_t to)
            return _olua_fun_olua_ulong_slice$1(L);
        // }
    }

    luaL_error(L, "method 'olua_ulong::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_ulong_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.ulong");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_ulong *sub(size_t from, @optional size_t to)
    olua_ulong *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.ulong");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ulong_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.ulong");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_ulong *sub(size_t from)
    olua_ulong *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ulong");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ulong_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.ulong")) && (olua_is_integer(L, 2))) {
            // @postnew olua_ulong *sub(size_t from)
            return _olua_fun_olua_ulong_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.ulong")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_ulong *sub(size_t from, @optional size_t to)
            return _olua_fun_olua_ulong_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_ulong::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_ulong_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ulong");

    // olua_ulong *take()
    olua_ulong *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.ulong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ulong_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.ulong");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_ulong_value$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ulong");

    // @getter const olua_ulong_t &value()
    const olua_ulong_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ulong_value$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;
    olua_ulong_t arg1 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.ulong");
    olua_check_integer(L, 2, &arg1);

    // @setter void value(const olua_ulong_t &v)
    self->value(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_ulong_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const olua_ulong_t &value()
        return _olua_fun_olua_ulong_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.ulong")) && (olua_is_integer(L, 2))) {
            // @setter void value(const olua_ulong_t &v)
            return _olua_fun_olua_ulong_value$2(L);
        // }
    }

    luaL_error(L, "method 'olua_ulong::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_olua_ulong(lua_State *L)
{
    oluacls_class<olua_ulong>(L, "olua.ulong");
    oluacls_func(L, "__gc", _olua_fun_olua_ulong___gc);
    oluacls_func(L, "__index", _olua_fun_olua_ulong___index);
    oluacls_func(L, "__newindex", _olua_fun_olua_ulong___newindex);
    oluacls_func(L, "new", _olua_fun_olua_ulong_new);
    oluacls_func(L, "slice", _olua_fun_olua_ulong_slice);
    oluacls_func(L, "sub", _olua_fun_olua_ulong_sub);
    oluacls_func(L, "take", _olua_fun_olua_ulong_take);
    oluacls_func(L, "tostring", _olua_fun_olua_ulong_tostring);
    oluacls_prop(L, "buffer", _olua_fun_olua_ulong_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_olua_ulong_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_olua_ulong_value, _olua_fun_olua_ulong_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_ulong(lua_State *L)
{
    olua_require(L, "types",  _olua_module_types);
    if (!olua_getclass(L, "olua.ulong")) {
        luaL_error(L, "class not found: olua_ulong");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_olua_ullong___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ullong");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_ullong___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.ullong");
    olua_check_integer(L, 2, &arg1);

    // olua_ullong_t __index(unsigned int idx)
    olua_ullong_t ret = self->__index(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ullong___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    olua_ullong_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.ullong");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void __newindex(unsigned int idx, const olua_ullong_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_ullong_buffer(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ullong");

    // @getter @type(void *) olua_ullong_t *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ullong_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ullong");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ullong_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // olua_ullong(@optional size_t len)
    olua_ullong *ret = new olua_ullong(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ullong");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ullong_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // olua_ullong()
    olua_ullong *ret = new olua_ullong();
    int num_ret = olua_push_object(L, ret, "olua.ullong");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ullong_new$3(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong_t *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_pointer(L, 1, &arg1, "olua.ullong");
    olua_check_integer(L, 2, &arg2);

    // olua_ullong(olua_ullong_t *v, @optional size_t len)
    olua_ullong *ret = new olua_ullong(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.ullong");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ullong_new$4(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong_t *arg1 = nullptr;       /** v */

    olua_check_pointer(L, 1, &arg1, "olua.ullong");

    // olua_ullong(olua_ullong_t *v)
    olua_ullong *ret = new olua_ullong(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ullong");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ullong_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // olua_ullong()
        return _olua_fun_olua_ullong_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // olua_ullong(@optional size_t len)
            return _olua_fun_olua_ullong_new$1(L);
        }

        // if ((olua_is_pointer(L, 1, "olua.ullong"))) {
            // olua_ullong(olua_ullong_t *v)
            return _olua_fun_olua_ullong_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_pointer(L, 1, "olua.ullong")) && (olua_is_integer(L, 2))) {
            // olua_ullong(olua_ullong_t *v, @optional size_t len)
            return _olua_fun_olua_ullong_new$3(L);
        // }
    }

    luaL_error(L, "method 'olua_ullong::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_ullong_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.ullong");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_ullong *slice(size_t from, @optional size_t to)
    olua_ullong *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.ullong");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ullong_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.ullong");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_ullong *slice(size_t from)
    olua_ullong *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ullong");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ullong_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.ullong")) && (olua_is_integer(L, 2))) {
            // @postnew olua_ullong *slice(size_t from)
            return _olua_fun_olua_ullong_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.ullong")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_ullong *slice(size_t from, @optional size_t to)
            return _olua_fun_olua_ullong_slice$1(L);
        // }
    }

    luaL_error(L, "method 'olua_ullong::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_ullong_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.ullong");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_ullong *sub(size_t from, @optional size_t to)
    olua_ullong *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.ullong");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ullong_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.ullong");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_ullong *sub(size_t from)
    olua_ullong *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ullong");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ullong_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.ullong")) && (olua_is_integer(L, 2))) {
            // @postnew olua_ullong *sub(size_t from)
            return _olua_fun_olua_ullong_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.ullong")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_ullong *sub(size_t from, @optional size_t to)
            return _olua_fun_olua_ullong_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_ullong::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_ullong_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ullong");

    // olua_ullong *take()
    olua_ullong *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.ullong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ullong_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.ullong");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_ullong_value$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ullong");

    // @getter const olua_ullong_t &value()
    const olua_ullong_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ullong_value$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;
    olua_ullong_t arg1 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.ullong");
    olua_check_integer(L, 2, &arg1);

    // @setter void value(const olua_ullong_t &v)
    self->value(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_ullong_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const olua_ullong_t &value()
        return _olua_fun_olua_ullong_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.ullong")) && (olua_is_integer(L, 2))) {
            // @setter void value(const olua_ullong_t &v)
            return _olua_fun_olua_ullong_value$2(L);
        // }
    }

    luaL_error(L, "method 'olua_ullong::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_olua_ullong(lua_State *L)
{
    oluacls_class<olua_ullong>(L, "olua.ullong");
    oluacls_func(L, "__gc", _olua_fun_olua_ullong___gc);
    oluacls_func(L, "__index", _olua_fun_olua_ullong___index);
    oluacls_func(L, "__newindex", _olua_fun_olua_ullong___newindex);
    oluacls_func(L, "new", _olua_fun_olua_ullong_new);
    oluacls_func(L, "slice", _olua_fun_olua_ullong_slice);
    oluacls_func(L, "sub", _olua_fun_olua_ullong_sub);
    oluacls_func(L, "take", _olua_fun_olua_ullong_take);
    oluacls_func(L, "tostring", _olua_fun_olua_ullong_tostring);
    oluacls_prop(L, "buffer", _olua_fun_olua_ullong_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_olua_ullong_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_olua_ullong_value, _olua_fun_olua_ullong_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_ullong(lua_State *L)
{
    olua_require(L, "types",  _olua_module_types);
    if (!olua_getclass(L, "olua.ullong")) {
        luaL_error(L, "class not found: olua_ullong");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_olua_float___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;

    olua_to_object(L, 1, &self, "olua.float");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_float___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.float");
    olua_check_integer(L, 2, &arg1);

    // olua_float_t __index(unsigned int idx)
    olua_float_t ret = self->__index(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_float___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    olua_float_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.float");
    olua_check_integer(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void __newindex(unsigned int idx, const olua_float_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_float_buffer(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;

    olua_to_object(L, 1, &self, "olua.float");

    // @getter @type(void *) olua_float_t *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_float_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;

    olua_to_object(L, 1, &self, "olua.float");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_float_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // olua_float(@optional size_t len)
    olua_float *ret = new olua_float(arg1);
    int num_ret = olua_push_object(L, ret, "olua.float");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_float_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // olua_float()
    olua_float *ret = new olua_float();
    int num_ret = olua_push_object(L, ret, "olua.float");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_float_new$3(lua_State *L)
{
    olua_startinvoke(L);

    olua_float_t *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_pointer(L, 1, &arg1, "olua.float");
    olua_check_integer(L, 2, &arg2);

    // olua_float(olua_float_t *v, @optional size_t len)
    olua_float *ret = new olua_float(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.float");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_float_new$4(lua_State *L)
{
    olua_startinvoke(L);

    olua_float_t *arg1 = nullptr;       /** v */

    olua_check_pointer(L, 1, &arg1, "olua.float");

    // olua_float(olua_float_t *v)
    olua_float *ret = new olua_float(arg1);
    int num_ret = olua_push_object(L, ret, "olua.float");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_float_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // olua_float()
        return _olua_fun_olua_float_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // olua_float(@optional size_t len)
            return _olua_fun_olua_float_new$1(L);
        }

        // if ((olua_is_pointer(L, 1, "olua.float"))) {
            // olua_float(olua_float_t *v)
            return _olua_fun_olua_float_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_pointer(L, 1, "olua.float")) && (olua_is_integer(L, 2))) {
            // olua_float(olua_float_t *v, @optional size_t len)
            return _olua_fun_olua_float_new$3(L);
        // }
    }

    luaL_error(L, "method 'olua_float::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_float_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.float");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_float *slice(size_t from, @optional size_t to)
    olua_float *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.float");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_float_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.float");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_float *slice(size_t from)
    olua_float *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "olua.float");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_float_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.float")) && (olua_is_integer(L, 2))) {
            // @postnew olua_float *slice(size_t from)
            return _olua_fun_olua_float_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.float")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_float *slice(size_t from, @optional size_t to)
            return _olua_fun_olua_float_slice$1(L);
        // }
    }

    luaL_error(L, "method 'olua_float::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_float_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.float");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_float *sub(size_t from, @optional size_t to)
    olua_float *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.float");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_float_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.float");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_float *sub(size_t from)
    olua_float *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.float");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_float_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.float")) && (olua_is_integer(L, 2))) {
            // @postnew olua_float *sub(size_t from)
            return _olua_fun_olua_float_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.float")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_float *sub(size_t from, @optional size_t to)
            return _olua_fun_olua_float_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_float::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_float_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;

    olua_to_object(L, 1, &self, "olua.float");

    // olua_float *take()
    olua_float *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.float");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_float_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.float");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_float_value$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;

    olua_to_object(L, 1, &self, "olua.float");

    // @getter const olua_float_t &value()
    const olua_float_t &ret = self->value();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_float_value$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;
    olua_float_t arg1 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.float");
    olua_check_number(L, 2, &arg1);

    // @setter void value(const olua_float_t &v)
    self->value(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_float_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const olua_float_t &value()
        return _olua_fun_olua_float_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.float")) && (olua_is_number(L, 2))) {
            // @setter void value(const olua_float_t &v)
            return _olua_fun_olua_float_value$2(L);
        // }
    }

    luaL_error(L, "method 'olua_float::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_olua_float(lua_State *L)
{
    oluacls_class<olua_float>(L, "olua.float");
    oluacls_func(L, "__gc", _olua_fun_olua_float___gc);
    oluacls_func(L, "__index", _olua_fun_olua_float___index);
    oluacls_func(L, "__newindex", _olua_fun_olua_float___newindex);
    oluacls_func(L, "new", _olua_fun_olua_float_new);
    oluacls_func(L, "slice", _olua_fun_olua_float_slice);
    oluacls_func(L, "sub", _olua_fun_olua_float_sub);
    oluacls_func(L, "take", _olua_fun_olua_float_take);
    oluacls_func(L, "tostring", _olua_fun_olua_float_tostring);
    oluacls_prop(L, "buffer", _olua_fun_olua_float_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_olua_float_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_olua_float_value, _olua_fun_olua_float_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_float(lua_State *L)
{
    olua_require(L, "types",  _olua_module_types);
    if (!olua_getclass(L, "olua.float")) {
        luaL_error(L, "class not found: olua_float");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_olua_double___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;

    olua_to_object(L, 1, &self, "olua.double");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_double___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.double");
    olua_check_integer(L, 2, &arg1);

    // olua_double_t __index(unsigned int idx)
    olua_double_t ret = self->__index(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_double___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    olua_double_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.double");
    olua_check_integer(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void __newindex(unsigned int idx, const olua_double_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_double_buffer(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;

    olua_to_object(L, 1, &self, "olua.double");

    // @getter @type(void *) olua_double_t *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_double_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;

    olua_to_object(L, 1, &self, "olua.double");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_double_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // olua_double(@optional size_t len)
    olua_double *ret = new olua_double(arg1);
    int num_ret = olua_push_object(L, ret, "olua.double");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_double_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // olua_double()
    olua_double *ret = new olua_double();
    int num_ret = olua_push_object(L, ret, "olua.double");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_double_new$3(lua_State *L)
{
    olua_startinvoke(L);

    olua_double_t *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_pointer(L, 1, &arg1, "olua.double");
    olua_check_integer(L, 2, &arg2);

    // olua_double(olua_double_t *v, @optional size_t len)
    olua_double *ret = new olua_double(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.double");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_double_new$4(lua_State *L)
{
    olua_startinvoke(L);

    olua_double_t *arg1 = nullptr;       /** v */

    olua_check_pointer(L, 1, &arg1, "olua.double");

    // olua_double(olua_double_t *v)
    olua_double *ret = new olua_double(arg1);
    int num_ret = olua_push_object(L, ret, "olua.double");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_double_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // olua_double()
        return _olua_fun_olua_double_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // olua_double(@optional size_t len)
            return _olua_fun_olua_double_new$1(L);
        }

        // if ((olua_is_pointer(L, 1, "olua.double"))) {
            // olua_double(olua_double_t *v)
            return _olua_fun_olua_double_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_pointer(L, 1, "olua.double")) && (olua_is_integer(L, 2))) {
            // olua_double(olua_double_t *v, @optional size_t len)
            return _olua_fun_olua_double_new$3(L);
        // }
    }

    luaL_error(L, "method 'olua_double::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_double_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.double");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_double *slice(size_t from, @optional size_t to)
    olua_double *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.double");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_double_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.double");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_double *slice(size_t from)
    olua_double *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "olua.double");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_double_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.double")) && (olua_is_integer(L, 2))) {
            // @postnew olua_double *slice(size_t from)
            return _olua_fun_olua_double_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.double")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_double *slice(size_t from, @optional size_t to)
            return _olua_fun_olua_double_slice$1(L);
        // }
    }

    luaL_error(L, "method 'olua_double::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_double_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.double");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_double *sub(size_t from, @optional size_t to)
    olua_double *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.double");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_double_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.double");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_double *sub(size_t from)
    olua_double *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.double");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_double_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.double")) && (olua_is_integer(L, 2))) {
            // @postnew olua_double *sub(size_t from)
            return _olua_fun_olua_double_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.double")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_double *sub(size_t from, @optional size_t to)
            return _olua_fun_olua_double_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_double::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_double_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;

    olua_to_object(L, 1, &self, "olua.double");

    // olua_double *take()
    olua_double *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.double");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_double_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.double");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_double_value$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;

    olua_to_object(L, 1, &self, "olua.double");

    // @getter const olua_double_t &value()
    const olua_double_t &ret = self->value();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_double_value$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;
    olua_double_t arg1 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.double");
    olua_check_number(L, 2, &arg1);

    // @setter void value(const olua_double_t &v)
    self->value(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_double_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const olua_double_t &value()
        return _olua_fun_olua_double_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.double")) && (olua_is_number(L, 2))) {
            // @setter void value(const olua_double_t &v)
            return _olua_fun_olua_double_value$2(L);
        // }
    }

    luaL_error(L, "method 'olua_double::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_olua_double(lua_State *L)
{
    oluacls_class<olua_double>(L, "olua.double");
    oluacls_func(L, "__gc", _olua_fun_olua_double___gc);
    oluacls_func(L, "__index", _olua_fun_olua_double___index);
    oluacls_func(L, "__newindex", _olua_fun_olua_double___newindex);
    oluacls_func(L, "new", _olua_fun_olua_double_new);
    oluacls_func(L, "slice", _olua_fun_olua_double_slice);
    oluacls_func(L, "sub", _olua_fun_olua_double_sub);
    oluacls_func(L, "take", _olua_fun_olua_double_take);
    oluacls_func(L, "tostring", _olua_fun_olua_double_tostring);
    oluacls_prop(L, "buffer", _olua_fun_olua_double_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_olua_double_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_olua_double_value, _olua_fun_olua_double_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_double(lua_State *L)
{
    olua_require(L, "types",  _olua_module_types);
    if (!olua_getclass(L, "olua.double")) {
        luaL_error(L, "class not found: olua_double");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_olua_ldouble___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ldouble");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_ldouble___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.ldouble");
    olua_check_integer(L, 2, &arg1);

    // olua_ldouble_t __index(unsigned int idx)
    olua_ldouble_t ret = self->__index(arg1);
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ldouble___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    olua_ldouble_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.ldouble");
    olua_check_integer(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void __newindex(unsigned int idx, const olua_ldouble_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_ldouble_buffer(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ldouble");

    // @getter @type(void *) olua_ldouble_t *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ldouble_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ldouble");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ldouble_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // olua_ldouble(@optional size_t len)
    olua_ldouble *ret = new olua_ldouble(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ldouble");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ldouble_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // olua_ldouble()
    olua_ldouble *ret = new olua_ldouble();
    int num_ret = olua_push_object(L, ret, "olua.ldouble");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ldouble_new$3(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble_t *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_pointer(L, 1, &arg1, "olua.ldouble");
    olua_check_integer(L, 2, &arg2);

    // olua_ldouble(olua_ldouble_t *v, @optional size_t len)
    olua_ldouble *ret = new olua_ldouble(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.ldouble");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ldouble_new$4(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble_t *arg1 = nullptr;       /** v */

    olua_check_pointer(L, 1, &arg1, "olua.ldouble");

    // olua_ldouble(olua_ldouble_t *v)
    olua_ldouble *ret = new olua_ldouble(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ldouble");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ldouble_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // olua_ldouble()
        return _olua_fun_olua_ldouble_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // olua_ldouble(@optional size_t len)
            return _olua_fun_olua_ldouble_new$1(L);
        }

        // if ((olua_is_pointer(L, 1, "olua.ldouble"))) {
            // olua_ldouble(olua_ldouble_t *v)
            return _olua_fun_olua_ldouble_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_pointer(L, 1, "olua.ldouble")) && (olua_is_integer(L, 2))) {
            // olua_ldouble(olua_ldouble_t *v, @optional size_t len)
            return _olua_fun_olua_ldouble_new$3(L);
        // }
    }

    luaL_error(L, "method 'olua_ldouble::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_ldouble_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.ldouble");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_ldouble *slice(size_t from, @optional size_t to)
    olua_ldouble *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.ldouble");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ldouble_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.ldouble");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_ldouble *slice(size_t from)
    olua_ldouble *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ldouble");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ldouble_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.ldouble")) && (olua_is_integer(L, 2))) {
            // @postnew olua_ldouble *slice(size_t from)
            return _olua_fun_olua_ldouble_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.ldouble")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_ldouble *slice(size_t from, @optional size_t to)
            return _olua_fun_olua_ldouble_slice$1(L);
        // }
    }

    luaL_error(L, "method 'olua_ldouble::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_ldouble_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.ldouble");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_ldouble *sub(size_t from, @optional size_t to)
    olua_ldouble *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.ldouble");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ldouble_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.ldouble");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_ldouble *sub(size_t from)
    olua_ldouble *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ldouble");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ldouble_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.ldouble")) && (olua_is_integer(L, 2))) {
            // @postnew olua_ldouble *sub(size_t from)
            return _olua_fun_olua_ldouble_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.ldouble")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_ldouble *sub(size_t from, @optional size_t to)
            return _olua_fun_olua_ldouble_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_ldouble::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_ldouble_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ldouble");

    // olua_ldouble *take()
    olua_ldouble *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.ldouble");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ldouble_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.ldouble");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_ldouble_value$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ldouble");

    // @getter const olua_ldouble_t &value()
    const olua_ldouble_t &ret = self->value();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ldouble_value$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;
    olua_ldouble_t arg1 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.ldouble");
    olua_check_number(L, 2, &arg1);

    // @setter void value(const olua_ldouble_t &v)
    self->value(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_ldouble_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const olua_ldouble_t &value()
        return _olua_fun_olua_ldouble_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.ldouble")) && (olua_is_number(L, 2))) {
            // @setter void value(const olua_ldouble_t &v)
            return _olua_fun_olua_ldouble_value$2(L);
        // }
    }

    luaL_error(L, "method 'olua_ldouble::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_olua_ldouble(lua_State *L)
{
    oluacls_class<olua_ldouble>(L, "olua.ldouble");
    oluacls_func(L, "__gc", _olua_fun_olua_ldouble___gc);
    oluacls_func(L, "__index", _olua_fun_olua_ldouble___index);
    oluacls_func(L, "__newindex", _olua_fun_olua_ldouble___newindex);
    oluacls_func(L, "new", _olua_fun_olua_ldouble_new);
    oluacls_func(L, "slice", _olua_fun_olua_ldouble_slice);
    oluacls_func(L, "sub", _olua_fun_olua_ldouble_sub);
    oluacls_func(L, "take", _olua_fun_olua_ldouble_take);
    oluacls_func(L, "tostring", _olua_fun_olua_ldouble_tostring);
    oluacls_prop(L, "buffer", _olua_fun_olua_ldouble_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_olua_ldouble_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_olua_ldouble_value, _olua_fun_olua_ldouble_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_ldouble(lua_State *L)
{
    olua_require(L, "types",  _olua_module_types);
    if (!olua_getclass(L, "olua.ldouble")) {
        luaL_error(L, "class not found: olua_ldouble");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_olua_size_t___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.size_t");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_size_t___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.size_t");
    olua_check_integer(L, 2, &arg1);

    // size_t __index(unsigned int idx)
    size_t ret = self->__index(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_size_t___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    size_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.size_t");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void __newindex(unsigned int idx, const size_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_size_t_buffer(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.size_t");

    // @getter @type(void *) size_t *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_size_t_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.size_t");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_size_t_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // olua_size_t(@optional size_t len)
    olua_size_t *ret = new olua_size_t(arg1);
    int num_ret = olua_push_object(L, ret, "olua.size_t");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_size_t_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // olua_size_t()
    olua_size_t *ret = new olua_size_t();
    int num_ret = olua_push_object(L, ret, "olua.size_t");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_size_t_new$3(lua_State *L)
{
    olua_startinvoke(L);

    size_t *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_pointer(L, 1, &arg1, "olua.size_t");
    olua_check_integer(L, 2, &arg2);

    // olua_size_t(size_t *v, @optional size_t len)
    olua_size_t *ret = new olua_size_t(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.size_t");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_size_t_new$4(lua_State *L)
{
    olua_startinvoke(L);

    size_t *arg1 = nullptr;       /** v */

    olua_check_pointer(L, 1, &arg1, "olua.size_t");

    // olua_size_t(size_t *v)
    olua_size_t *ret = new olua_size_t(arg1);
    int num_ret = olua_push_object(L, ret, "olua.size_t");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_size_t_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // olua_size_t()
        return _olua_fun_olua_size_t_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // olua_size_t(@optional size_t len)
            return _olua_fun_olua_size_t_new$1(L);
        }

        // if ((olua_is_pointer(L, 1, "olua.size_t"))) {
            // olua_size_t(size_t *v)
            return _olua_fun_olua_size_t_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_pointer(L, 1, "olua.size_t")) && (olua_is_integer(L, 2))) {
            // olua_size_t(size_t *v, @optional size_t len)
            return _olua_fun_olua_size_t_new$3(L);
        // }
    }

    luaL_error(L, "method 'olua_size_t::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_size_t_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.size_t");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_size_t *slice(size_t from, @optional size_t to)
    olua_size_t *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.size_t");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_size_t_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.size_t");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_size_t *slice(size_t from)
    olua_size_t *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "olua.size_t");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_size_t_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.size_t")) && (olua_is_integer(L, 2))) {
            // @postnew olua_size_t *slice(size_t from)
            return _olua_fun_olua_size_t_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.size_t")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_size_t *slice(size_t from, @optional size_t to)
            return _olua_fun_olua_size_t_slice$1(L);
        // }
    }

    luaL_error(L, "method 'olua_size_t::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_size_t_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.size_t");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_size_t *sub(size_t from, @optional size_t to)
    olua_size_t *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.size_t");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_size_t_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.size_t");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_size_t *sub(size_t from)
    olua_size_t *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.size_t");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_size_t_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.size_t")) && (olua_is_integer(L, 2))) {
            // @postnew olua_size_t *sub(size_t from)
            return _olua_fun_olua_size_t_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.size_t")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_size_t *sub(size_t from, @optional size_t to)
            return _olua_fun_olua_size_t_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_size_t::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_size_t_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.size_t");

    // olua_size_t *take()
    olua_size_t *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.size_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_size_t_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.size_t");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_size_t_value$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.size_t");

    // @getter const size_t &value()
    const size_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_size_t_value$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;
    size_t arg1 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.size_t");
    olua_check_integer(L, 2, &arg1);

    // @setter void value(const size_t &v)
    self->value(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_size_t_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const size_t &value()
        return _olua_fun_olua_size_t_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.size_t")) && (olua_is_integer(L, 2))) {
            // @setter void value(const size_t &v)
            return _olua_fun_olua_size_t_value$2(L);
        // }
    }

    luaL_error(L, "method 'olua_size_t::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_olua_size_t(lua_State *L)
{
    oluacls_class<olua_size_t>(L, "olua.size_t");
    oluacls_func(L, "__gc", _olua_fun_olua_size_t___gc);
    oluacls_func(L, "__index", _olua_fun_olua_size_t___index);
    oluacls_func(L, "__newindex", _olua_fun_olua_size_t___newindex);
    oluacls_func(L, "new", _olua_fun_olua_size_t_new);
    oluacls_func(L, "slice", _olua_fun_olua_size_t_slice);
    oluacls_func(L, "sub", _olua_fun_olua_size_t_sub);
    oluacls_func(L, "take", _olua_fun_olua_size_t_take);
    oluacls_func(L, "tostring", _olua_fun_olua_size_t_tostring);
    oluacls_prop(L, "buffer", _olua_fun_olua_size_t_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_olua_size_t_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_olua_size_t_value, _olua_fun_olua_size_t_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_size_t(lua_State *L)
{
    olua_require(L, "types",  _olua_module_types);
    if (!olua_getclass(L, "olua.size_t")) {
        luaL_error(L, "class not found: olua_size_t");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_olua_ssize_t___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ssize_t");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_ssize_t___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.ssize_t");
    olua_check_integer(L, 2, &arg1);

    // ssize_t __index(unsigned int idx)
    ssize_t ret = self->__index(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ssize_t___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    ssize_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.ssize_t");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void __newindex(unsigned int idx, const ssize_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_ssize_t_buffer(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ssize_t");

    // @getter @type(void *) ssize_t *buffer()
    void *ret = self->buffer();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ssize_t_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ssize_t");

    // @getter size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ssize_t_new$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // olua_ssize_t(@optional size_t len)
    olua_ssize_t *ret = new olua_ssize_t(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ssize_t");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ssize_t_new$2(lua_State *L)
{
    olua_startinvoke(L);

    // olua_ssize_t()
    olua_ssize_t *ret = new olua_ssize_t();
    int num_ret = olua_push_object(L, ret, "olua.ssize_t");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ssize_t_new$3(lua_State *L)
{
    olua_startinvoke(L);

    ssize_t *arg1 = nullptr;       /** v */
    size_t arg2 = 0;       /** len */

    olua_check_pointer(L, 1, &arg1, "olua.ssize_t");
    olua_check_integer(L, 2, &arg2);

    // olua_ssize_t(ssize_t *v, @optional size_t len)
    olua_ssize_t *ret = new olua_ssize_t(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.ssize_t");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ssize_t_new$4(lua_State *L)
{
    olua_startinvoke(L);

    ssize_t *arg1 = nullptr;       /** v */

    olua_check_pointer(L, 1, &arg1, "olua.ssize_t");

    // olua_ssize_t(ssize_t *v)
    olua_ssize_t *ret = new olua_ssize_t(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ssize_t");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ssize_t_new(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // olua_ssize_t()
        return _olua_fun_olua_ssize_t_new$2(L);
    }

    if (num_args == 1) {
        if ((olua_is_integer(L, 1))) {
            // olua_ssize_t(@optional size_t len)
            return _olua_fun_olua_ssize_t_new$1(L);
        }

        // if ((olua_is_pointer(L, 1, "olua.ssize_t"))) {
            // olua_ssize_t(ssize_t *v)
            return _olua_fun_olua_ssize_t_new$4(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_pointer(L, 1, "olua.ssize_t")) && (olua_is_integer(L, 2))) {
            // olua_ssize_t(ssize_t *v, @optional size_t len)
            return _olua_fun_olua_ssize_t_new$3(L);
        // }
    }

    luaL_error(L, "method 'olua_ssize_t::new' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_ssize_t_slice$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.ssize_t");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_ssize_t *slice(size_t from, @optional size_t to)
    olua_ssize_t *ret = self->slice(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.ssize_t");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ssize_t_slice$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.ssize_t");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_ssize_t *slice(size_t from)
    olua_ssize_t *ret = self->slice(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ssize_t");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ssize_t_slice(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.ssize_t")) && (olua_is_integer(L, 2))) {
            // @postnew olua_ssize_t *slice(size_t from)
            return _olua_fun_olua_ssize_t_slice$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.ssize_t")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_ssize_t *slice(size_t from, @optional size_t to)
            return _olua_fun_olua_ssize_t_slice$1(L);
        // }
    }

    luaL_error(L, "method 'olua_ssize_t::slice' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_ssize_t_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.ssize_t");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // @postnew olua_ssize_t *sub(size_t from, @optional size_t to)
    olua_ssize_t *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.ssize_t");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ssize_t_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.ssize_t");
    olua_check_integer(L, 2, &arg1);

    // @postnew olua_ssize_t *sub(size_t from)
    olua_ssize_t *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ssize_t");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ssize_t_sub(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.ssize_t")) && (olua_is_integer(L, 2))) {
            // @postnew olua_ssize_t *sub(size_t from)
            return _olua_fun_olua_ssize_t_sub$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_object(L, 1, "olua.ssize_t")) && (olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // @postnew olua_ssize_t *sub(size_t from, @optional size_t to)
            return _olua_fun_olua_ssize_t_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_ssize_t::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_olua_ssize_t_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ssize_t");

    // olua_ssize_t *take()
    olua_ssize_t *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.ssize_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ssize_t_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;
    size_t arg1 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.ssize_t");
    olua_check_integer(L, 2, &arg1);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg1);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_fun_olua_ssize_t_value$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ssize_t");

    // @getter const ssize_t &value()
    const ssize_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_olua_ssize_t_value$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;
    ssize_t arg1 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.ssize_t");
    olua_check_integer(L, 2, &arg1);

    // @setter void value(const ssize_t &v)
    self->value(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_olua_ssize_t_value(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @getter const ssize_t &value()
        return _olua_fun_olua_ssize_t_value$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "olua.ssize_t")) && (olua_is_integer(L, 2))) {
            // @setter void value(const ssize_t &v)
            return _olua_fun_olua_ssize_t_value$2(L);
        // }
    }

    luaL_error(L, "method 'olua_ssize_t::value' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_olua_ssize_t(lua_State *L)
{
    oluacls_class<olua_ssize_t>(L, "olua.ssize_t");
    oluacls_func(L, "__gc", _olua_fun_olua_ssize_t___gc);
    oluacls_func(L, "__index", _olua_fun_olua_ssize_t___index);
    oluacls_func(L, "__newindex", _olua_fun_olua_ssize_t___newindex);
    oluacls_func(L, "new", _olua_fun_olua_ssize_t_new);
    oluacls_func(L, "slice", _olua_fun_olua_ssize_t_slice);
    oluacls_func(L, "sub", _olua_fun_olua_ssize_t_sub);
    oluacls_func(L, "take", _olua_fun_olua_ssize_t_take);
    oluacls_func(L, "tostring", _olua_fun_olua_ssize_t_tostring);
    oluacls_prop(L, "buffer", _olua_fun_olua_ssize_t_buffer, nullptr);
    oluacls_prop(L, "length", _olua_fun_olua_ssize_t_length, nullptr);
    oluacls_prop(L, "value", _olua_fun_olua_ssize_t_value, _olua_fun_olua_ssize_t_value);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_ssize_t(lua_State *L)
{
    olua_require(L, "types",  _olua_module_types);
    if (!olua_getclass(L, "olua.ssize_t")) {
        luaL_error(L, "class not found: olua_ssize_t");
    }
    return 1;
}
OLUA_END_DECLS

int _olua_module_types(lua_State *L)
{
    olua_require(L, "olua.bool", _olua_cls_olua_bool);
    olua_require(L, "olua.string", _olua_cls_olua_string);
    olua_require(L, "olua.int8", _olua_cls_olua_int8);
    olua_require(L, "olua.int16", _olua_cls_olua_int16);
    olua_require(L, "olua.int32", _olua_cls_olua_int32);
    olua_require(L, "olua.int64", _olua_cls_olua_int64);
    olua_require(L, "olua.uint8", _olua_cls_olua_uint8);
    olua_require(L, "olua.uint16", _olua_cls_olua_uint16);
    olua_require(L, "olua.uint32", _olua_cls_olua_uint32);
    olua_require(L, "olua.uint64", _olua_cls_olua_uint64);
    olua_require(L, "olua.char", _olua_cls_olua_char);
    olua_require(L, "olua.short", _olua_cls_olua_short);
    olua_require(L, "olua.int", _olua_cls_olua_int);
    olua_require(L, "olua.long", _olua_cls_olua_long);
    olua_require(L, "olua.llong", _olua_cls_olua_llong);
    olua_require(L, "olua.uchar", _olua_cls_olua_uchar);
    olua_require(L, "olua.ushort", _olua_cls_olua_ushort);
    olua_require(L, "olua.uint", _olua_cls_olua_uint);
    olua_require(L, "olua.ulong", _olua_cls_olua_ulong);
    olua_require(L, "olua.ullong", _olua_cls_olua_ullong);
    olua_require(L, "olua.float", _olua_cls_olua_float);
    olua_require(L, "olua.double", _olua_cls_olua_double);
    olua_require(L, "olua.ldouble", _olua_cls_olua_ldouble);
    olua_require(L, "olua.size_t", _olua_cls_olua_size_t);
    olua_require(L, "olua.ssize_t", _olua_cls_olua_ssize_t);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_types(lua_State *L)
{
    olua_require(L, "types",  _olua_module_types);

    return 0;
}
OLUA_END_DECLS
