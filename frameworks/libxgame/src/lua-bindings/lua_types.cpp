//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_types.h"
#include "cclua/olua-2dx.h"

static int _olua_bool___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;

    olua_to_object(L, 1, &self, "olua.bool");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_bool___index(lua_State *L)
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

static int _olua_bool___newindex(lua_State *L)
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

static int _olua_bool___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_bool *)olua_toobj(L, 1, "olua.bool");
    olua_push_object(L, self, "olua.bool");

    olua_endinvoke(L);

    return 1;
}

static int _olua_bool_create$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // @postnew @name(new) static olua_bool *create(@optional size_t len)
    olua_bool *ret = olua_bool::create(arg1);
    int num_ret = olua_push_object(L, ret, "olua.bool");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_bool_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @postnew @name(new) static olua_bool *create(@optional size_t len)
    olua_bool *ret = olua_bool::create();
    int num_ret = olua_push_object(L, ret, "olua.bool");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_bool_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @postnew @name(new) static olua_bool *create(@optional size_t len)
        return _olua_bool_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 1))) {
            // @postnew @name(new) static olua_bool *create(@optional size_t len)
            return _olua_bool_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_bool::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_bool_setstring(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.bool");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setstring(const char *data, size_t len)
    self->setstring(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_bool_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.bool");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // olua_bool *sub(size_t from, @optional size_t to)
    olua_bool *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.bool");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_bool_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.bool");
    olua_check_integer(L, 2, &arg1);

    // olua_bool *sub(size_t from, @optional size_t to)
    olua_bool *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.bool");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_bool_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // olua_bool *sub(size_t from, @optional size_t to)
            return _olua_bool_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // olua_bool *sub(size_t from, @optional size_t to)
            return _olua_bool_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_bool::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_bool_take(lua_State *L)
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

static int _olua_bool_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.bool");
    olua_check_integer(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_bool_data(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;

    olua_to_object(L, 1, &self, "olua.bool");

    // @getter @name(data) bool *data()
    bool *ret = self->data();
    int num_ret = olua_push_array(L, ret, "olua.bool");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_bool_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;

    olua_to_object(L, 1, &self, "olua.bool");

    // @getter @name(length) size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_bool_rawdata(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;

    olua_to_object(L, 1, &self, "olua.bool");

    // @getter @name(rawdata) void *rawdata()
    void *ret = self->rawdata();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_bool_size(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;

    olua_to_object(L, 1, &self, "olua.bool");

    // @getter @name(sizeof) size_t size()
    size_t ret = self->size();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_bool_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;

    olua_to_object(L, 1, &self, "olua.bool");

    // @getter @name(value) const bool &value()
    const bool &ret = self->value();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_bool(lua_State *L)
{
    oluacls_class<olua_bool>(L, "olua.bool");
    oluacls_func(L, "__gc", _olua_bool___gc);
    oluacls_func(L, "__index", _olua_bool___index);
    oluacls_func(L, "__newindex", _olua_bool___newindex);
    oluacls_func(L, "__olua_move", _olua_bool___olua_move);
    oluacls_func(L, "new", _olua_bool_create);
    oluacls_func(L, "setstring", _olua_bool_setstring);
    oluacls_func(L, "sub", _olua_bool_sub);
    oluacls_func(L, "take", _olua_bool_take);
    oluacls_func(L, "tostring", _olua_bool_tostring);
    oluacls_prop(L, "data", _olua_bool_data, nullptr);
    oluacls_prop(L, "length", _olua_bool_length, _olua_bool_length);
    oluacls_prop(L, "rawdata", _olua_bool_rawdata, nullptr);
    oluacls_prop(L, "sizeof", _olua_bool_size, nullptr);
    oluacls_prop(L, "value", _olua_bool_value, _olua_bool_value);

    return 1;
}
OLUA_END_DECLS

static int _olua_string___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;

    olua_to_object(L, 1, &self, "olua.string");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_string___index(lua_State *L)
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

static int _olua_string___newindex(lua_State *L)
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

static int _olua_string___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_string *)olua_toobj(L, 1, "olua.string");
    olua_push_object(L, self, "olua.string");

    olua_endinvoke(L);

    return 1;
}

static int _olua_string_create$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // @postnew @name(new) static olua_string *create(@optional size_t len)
    olua_string *ret = olua_string::create(arg1);
    int num_ret = olua_push_object(L, ret, "olua.string");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_string_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @postnew @name(new) static olua_string *create(@optional size_t len)
    olua_string *ret = olua_string::create();
    int num_ret = olua_push_object(L, ret, "olua.string");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_string_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @postnew @name(new) static olua_string *create(@optional size_t len)
        return _olua_string_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 1))) {
            // @postnew @name(new) static olua_string *create(@optional size_t len)
            return _olua_string_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_string::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_string_setstring(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.string");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setstring(const char *data, size_t len)
    self->setstring(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_string_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.string");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // olua_string *sub(size_t from, @optional size_t to)
    olua_string *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.string");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_string_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.string");
    olua_check_integer(L, 2, &arg1);

    // olua_string *sub(size_t from, @optional size_t to)
    olua_string *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.string");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_string_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // olua_string *sub(size_t from, @optional size_t to)
            return _olua_string_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // olua_string *sub(size_t from, @optional size_t to)
            return _olua_string_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_string::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_string_take(lua_State *L)
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

static int _olua_string_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.string");
    olua_check_integer(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_string_data(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;

    olua_to_object(L, 1, &self, "olua.string");

    // @getter @name(data) std::string *data()
    std::string *ret = self->data();
    int num_ret = olua_push_array(L, ret, "olua.string");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_string_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;

    olua_to_object(L, 1, &self, "olua.string");

    // @getter @name(length) size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_string_rawdata(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;

    olua_to_object(L, 1, &self, "olua.string");

    // @getter @name(rawdata) void *rawdata()
    void *ret = self->rawdata();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_string_size(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;

    olua_to_object(L, 1, &self, "olua.string");

    // @getter @name(sizeof) size_t size()
    size_t ret = self->size();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_string_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;

    olua_to_object(L, 1, &self, "olua.string");

    // @getter @name(value) const std::string &value()
    const std::string &ret = self->value();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_string(lua_State *L)
{
    oluacls_class<olua_string>(L, "olua.string");
    oluacls_func(L, "__gc", _olua_string___gc);
    oluacls_func(L, "__index", _olua_string___index);
    oluacls_func(L, "__newindex", _olua_string___newindex);
    oluacls_func(L, "__olua_move", _olua_string___olua_move);
    oluacls_func(L, "new", _olua_string_create);
    oluacls_func(L, "setstring", _olua_string_setstring);
    oluacls_func(L, "sub", _olua_string_sub);
    oluacls_func(L, "take", _olua_string_take);
    oluacls_func(L, "tostring", _olua_string_tostring);
    oluacls_prop(L, "data", _olua_string_data, nullptr);
    oluacls_prop(L, "length", _olua_string_length, _olua_string_length);
    oluacls_prop(L, "rawdata", _olua_string_rawdata, nullptr);
    oluacls_prop(L, "sizeof", _olua_string_size, nullptr);
    oluacls_prop(L, "value", _olua_string_value, _olua_string_value);

    return 1;
}
OLUA_END_DECLS

static int _olua_int8_t___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int8_t");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_int8_t___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8_t *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.int8_t");
    olua_check_integer(L, 2, &arg1);

    // int8_t __index(unsigned int idx)
    int8_t ret = self->__index(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int8_t___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8_t *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    int8_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.int8_t");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void __newindex(unsigned int idx, const int8_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int8_t___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_int8_t *)olua_toobj(L, 1, "olua.int8_t");
    olua_push_object(L, self, "olua.int8_t");

    olua_endinvoke(L);

    return 1;
}

static int _olua_int8_t_create$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // @postnew @name(new) static olua_int8_t *create(@optional size_t len)
    olua_int8_t *ret = olua_int8_t::create(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int8_t");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int8_t_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @postnew @name(new) static olua_int8_t *create(@optional size_t len)
    olua_int8_t *ret = olua_int8_t::create();
    int num_ret = olua_push_object(L, ret, "olua.int8_t");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int8_t_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @postnew @name(new) static olua_int8_t *create(@optional size_t len)
        return _olua_int8_t_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 1))) {
            // @postnew @name(new) static olua_int8_t *create(@optional size_t len)
            return _olua_int8_t_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_int8_t::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int8_t_setstring(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8_t *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.int8_t");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setstring(const char *data, size_t len)
    self->setstring(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int8_t_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8_t *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.int8_t");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // olua_int8_t *sub(size_t from, @optional size_t to)
    olua_int8_t *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.int8_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int8_t_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8_t *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.int8_t");
    olua_check_integer(L, 2, &arg1);

    // olua_int8_t *sub(size_t from, @optional size_t to)
    olua_int8_t *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int8_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int8_t_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // olua_int8_t *sub(size_t from, @optional size_t to)
            return _olua_int8_t_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // olua_int8_t *sub(size_t from, @optional size_t to)
            return _olua_int8_t_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_int8_t::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int8_t_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int8_t");

    // olua_int8_t *take()
    olua_int8_t *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.int8_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int8_t_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8_t *self = nullptr;
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.int8_t");
    olua_check_integer(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_int8_t_data(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int8_t");

    // @getter @name(data) int8_t *data()
    int8_t *ret = self->data();
    int num_ret = olua_push_array(L, ret, "olua.int8_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int8_t_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int8_t");

    // @getter @name(length) size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int8_t_rawdata(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int8_t");

    // @getter @name(rawdata) void *rawdata()
    void *ret = self->rawdata();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int8_t_size(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int8_t");

    // @getter @name(sizeof) size_t size()
    size_t ret = self->size();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int8_t_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int8_t");

    // @getter @name(value) const int8_t &value()
    const int8_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_int8_t(lua_State *L)
{
    oluacls_class<olua_int8_t>(L, "olua.int8_t");
    oluacls_func(L, "__gc", _olua_int8_t___gc);
    oluacls_func(L, "__index", _olua_int8_t___index);
    oluacls_func(L, "__newindex", _olua_int8_t___newindex);
    oluacls_func(L, "__olua_move", _olua_int8_t___olua_move);
    oluacls_func(L, "new", _olua_int8_t_create);
    oluacls_func(L, "setstring", _olua_int8_t_setstring);
    oluacls_func(L, "sub", _olua_int8_t_sub);
    oluacls_func(L, "take", _olua_int8_t_take);
    oluacls_func(L, "tostring", _olua_int8_t_tostring);
    oluacls_prop(L, "data", _olua_int8_t_data, nullptr);
    oluacls_prop(L, "length", _olua_int8_t_length, _olua_int8_t_length);
    oluacls_prop(L, "rawdata", _olua_int8_t_rawdata, nullptr);
    oluacls_prop(L, "sizeof", _olua_int8_t_size, nullptr);
    oluacls_prop(L, "value", _olua_int8_t_value, _olua_int8_t_value);

    return 1;
}
OLUA_END_DECLS

static int _olua_int16_t___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int16_t");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_int16_t___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16_t *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.int16_t");
    olua_check_integer(L, 2, &arg1);

    // int16_t __index(unsigned int idx)
    int16_t ret = self->__index(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int16_t___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16_t *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    int16_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.int16_t");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void __newindex(unsigned int idx, const int16_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int16_t___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_int16_t *)olua_toobj(L, 1, "olua.int16_t");
    olua_push_object(L, self, "olua.int16_t");

    olua_endinvoke(L);

    return 1;
}

static int _olua_int16_t_create$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // @postnew @name(new) static olua_int16_t *create(@optional size_t len)
    olua_int16_t *ret = olua_int16_t::create(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int16_t");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int16_t_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @postnew @name(new) static olua_int16_t *create(@optional size_t len)
    olua_int16_t *ret = olua_int16_t::create();
    int num_ret = olua_push_object(L, ret, "olua.int16_t");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int16_t_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @postnew @name(new) static olua_int16_t *create(@optional size_t len)
        return _olua_int16_t_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 1))) {
            // @postnew @name(new) static olua_int16_t *create(@optional size_t len)
            return _olua_int16_t_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_int16_t::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int16_t_setstring(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16_t *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.int16_t");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setstring(const char *data, size_t len)
    self->setstring(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int16_t_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16_t *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.int16_t");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // olua_int16_t *sub(size_t from, @optional size_t to)
    olua_int16_t *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.int16_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int16_t_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16_t *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.int16_t");
    olua_check_integer(L, 2, &arg1);

    // olua_int16_t *sub(size_t from, @optional size_t to)
    olua_int16_t *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int16_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int16_t_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // olua_int16_t *sub(size_t from, @optional size_t to)
            return _olua_int16_t_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // olua_int16_t *sub(size_t from, @optional size_t to)
            return _olua_int16_t_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_int16_t::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int16_t_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int16_t");

    // olua_int16_t *take()
    olua_int16_t *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.int16_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int16_t_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16_t *self = nullptr;
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.int16_t");
    olua_check_integer(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_int16_t_data(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int16_t");

    // @getter @name(data) int16_t *data()
    int16_t *ret = self->data();
    int num_ret = olua_push_array(L, ret, "olua.int16_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int16_t_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int16_t");

    // @getter @name(length) size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int16_t_rawdata(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int16_t");

    // @getter @name(rawdata) void *rawdata()
    void *ret = self->rawdata();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int16_t_size(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int16_t");

    // @getter @name(sizeof) size_t size()
    size_t ret = self->size();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int16_t_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int16_t");

    // @getter @name(value) const int16_t &value()
    const int16_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_int16_t(lua_State *L)
{
    oluacls_class<olua_int16_t>(L, "olua.int16_t");
    oluacls_func(L, "__gc", _olua_int16_t___gc);
    oluacls_func(L, "__index", _olua_int16_t___index);
    oluacls_func(L, "__newindex", _olua_int16_t___newindex);
    oluacls_func(L, "__olua_move", _olua_int16_t___olua_move);
    oluacls_func(L, "new", _olua_int16_t_create);
    oluacls_func(L, "setstring", _olua_int16_t_setstring);
    oluacls_func(L, "sub", _olua_int16_t_sub);
    oluacls_func(L, "take", _olua_int16_t_take);
    oluacls_func(L, "tostring", _olua_int16_t_tostring);
    oluacls_prop(L, "data", _olua_int16_t_data, nullptr);
    oluacls_prop(L, "length", _olua_int16_t_length, _olua_int16_t_length);
    oluacls_prop(L, "rawdata", _olua_int16_t_rawdata, nullptr);
    oluacls_prop(L, "sizeof", _olua_int16_t_size, nullptr);
    oluacls_prop(L, "value", _olua_int16_t_value, _olua_int16_t_value);

    return 1;
}
OLUA_END_DECLS

static int _olua_int32_t___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int32_t");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_int32_t___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32_t *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.int32_t");
    olua_check_integer(L, 2, &arg1);

    // int32_t __index(unsigned int idx)
    int32_t ret = self->__index(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int32_t___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32_t *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    int32_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.int32_t");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void __newindex(unsigned int idx, const int32_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int32_t___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_int32_t *)olua_toobj(L, 1, "olua.int32_t");
    olua_push_object(L, self, "olua.int32_t");

    olua_endinvoke(L);

    return 1;
}

static int _olua_int32_t_create$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // @postnew @name(new) static olua_int32_t *create(@optional size_t len)
    olua_int32_t *ret = olua_int32_t::create(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int32_t");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int32_t_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @postnew @name(new) static olua_int32_t *create(@optional size_t len)
    olua_int32_t *ret = olua_int32_t::create();
    int num_ret = olua_push_object(L, ret, "olua.int32_t");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int32_t_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @postnew @name(new) static olua_int32_t *create(@optional size_t len)
        return _olua_int32_t_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 1))) {
            // @postnew @name(new) static olua_int32_t *create(@optional size_t len)
            return _olua_int32_t_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_int32_t::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int32_t_setstring(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32_t *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.int32_t");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setstring(const char *data, size_t len)
    self->setstring(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int32_t_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32_t *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.int32_t");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // olua_int32_t *sub(size_t from, @optional size_t to)
    olua_int32_t *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.int32_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int32_t_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32_t *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.int32_t");
    olua_check_integer(L, 2, &arg1);

    // olua_int32_t *sub(size_t from, @optional size_t to)
    olua_int32_t *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int32_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int32_t_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // olua_int32_t *sub(size_t from, @optional size_t to)
            return _olua_int32_t_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // olua_int32_t *sub(size_t from, @optional size_t to)
            return _olua_int32_t_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_int32_t::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int32_t_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int32_t");

    // olua_int32_t *take()
    olua_int32_t *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.int32_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int32_t_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32_t *self = nullptr;
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.int32_t");
    olua_check_integer(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_int32_t_data(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int32_t");

    // @getter @name(data) int32_t *data()
    int32_t *ret = self->data();
    int num_ret = olua_push_array(L, ret, "olua.int32_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int32_t_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int32_t");

    // @getter @name(length) size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int32_t_rawdata(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int32_t");

    // @getter @name(rawdata) void *rawdata()
    void *ret = self->rawdata();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int32_t_size(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int32_t");

    // @getter @name(sizeof) size_t size()
    size_t ret = self->size();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int32_t_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int32_t");

    // @getter @name(value) const int32_t &value()
    const int32_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_int32_t(lua_State *L)
{
    oluacls_class<olua_int32_t>(L, "olua.int32_t");
    oluacls_func(L, "__gc", _olua_int32_t___gc);
    oluacls_func(L, "__index", _olua_int32_t___index);
    oluacls_func(L, "__newindex", _olua_int32_t___newindex);
    oluacls_func(L, "__olua_move", _olua_int32_t___olua_move);
    oluacls_func(L, "new", _olua_int32_t_create);
    oluacls_func(L, "setstring", _olua_int32_t_setstring);
    oluacls_func(L, "sub", _olua_int32_t_sub);
    oluacls_func(L, "take", _olua_int32_t_take);
    oluacls_func(L, "tostring", _olua_int32_t_tostring);
    oluacls_prop(L, "data", _olua_int32_t_data, nullptr);
    oluacls_prop(L, "length", _olua_int32_t_length, _olua_int32_t_length);
    oluacls_prop(L, "rawdata", _olua_int32_t_rawdata, nullptr);
    oluacls_prop(L, "sizeof", _olua_int32_t_size, nullptr);
    oluacls_prop(L, "value", _olua_int32_t_value, _olua_int32_t_value);

    return 1;
}
OLUA_END_DECLS

static int _olua_int64_t___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int64_t");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_int64_t___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64_t *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.int64_t");
    olua_check_integer(L, 2, &arg1);

    // int64_t __index(unsigned int idx)
    int64_t ret = self->__index(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int64_t___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64_t *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    int64_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.int64_t");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void __newindex(unsigned int idx, const int64_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int64_t___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_int64_t *)olua_toobj(L, 1, "olua.int64_t");
    olua_push_object(L, self, "olua.int64_t");

    olua_endinvoke(L);

    return 1;
}

static int _olua_int64_t_create$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // @postnew @name(new) static olua_int64_t *create(@optional size_t len)
    olua_int64_t *ret = olua_int64_t::create(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int64_t");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int64_t_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @postnew @name(new) static olua_int64_t *create(@optional size_t len)
    olua_int64_t *ret = olua_int64_t::create();
    int num_ret = olua_push_object(L, ret, "olua.int64_t");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int64_t_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @postnew @name(new) static olua_int64_t *create(@optional size_t len)
        return _olua_int64_t_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 1))) {
            // @postnew @name(new) static olua_int64_t *create(@optional size_t len)
            return _olua_int64_t_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_int64_t::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int64_t_setstring(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64_t *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.int64_t");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setstring(const char *data, size_t len)
    self->setstring(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int64_t_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64_t *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.int64_t");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // olua_int64_t *sub(size_t from, @optional size_t to)
    olua_int64_t *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.int64_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int64_t_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64_t *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.int64_t");
    olua_check_integer(L, 2, &arg1);

    // olua_int64_t *sub(size_t from, @optional size_t to)
    olua_int64_t *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int64_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int64_t_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // olua_int64_t *sub(size_t from, @optional size_t to)
            return _olua_int64_t_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // olua_int64_t *sub(size_t from, @optional size_t to)
            return _olua_int64_t_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_int64_t::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int64_t_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int64_t");

    // olua_int64_t *take()
    olua_int64_t *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.int64_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int64_t_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64_t *self = nullptr;
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.int64_t");
    olua_check_integer(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_int64_t_data(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int64_t");

    // @getter @name(data) int64_t *data()
    int64_t *ret = self->data();
    int num_ret = olua_push_array(L, ret, "olua.int64_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int64_t_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int64_t");

    // @getter @name(length) size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int64_t_rawdata(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int64_t");

    // @getter @name(rawdata) void *rawdata()
    void *ret = self->rawdata();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int64_t_size(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int64_t");

    // @getter @name(sizeof) size_t size()
    size_t ret = self->size();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int64_t_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int64_t");

    // @getter @name(value) const int64_t &value()
    const int64_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_int64_t(lua_State *L)
{
    oluacls_class<olua_int64_t>(L, "olua.int64_t");
    oluacls_func(L, "__gc", _olua_int64_t___gc);
    oluacls_func(L, "__index", _olua_int64_t___index);
    oluacls_func(L, "__newindex", _olua_int64_t___newindex);
    oluacls_func(L, "__olua_move", _olua_int64_t___olua_move);
    oluacls_func(L, "new", _olua_int64_t_create);
    oluacls_func(L, "setstring", _olua_int64_t_setstring);
    oluacls_func(L, "sub", _olua_int64_t_sub);
    oluacls_func(L, "take", _olua_int64_t_take);
    oluacls_func(L, "tostring", _olua_int64_t_tostring);
    oluacls_prop(L, "data", _olua_int64_t_data, nullptr);
    oluacls_prop(L, "length", _olua_int64_t_length, _olua_int64_t_length);
    oluacls_prop(L, "rawdata", _olua_int64_t_rawdata, nullptr);
    oluacls_prop(L, "sizeof", _olua_int64_t_size, nullptr);
    oluacls_prop(L, "value", _olua_int64_t_value, _olua_int64_t_value);

    return 1;
}
OLUA_END_DECLS

static int _olua_uint8_t___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint8_t");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_uint8_t___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8_t *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.uint8_t");
    olua_check_integer(L, 2, &arg1);

    // uint8_t __index(unsigned int idx)
    uint8_t ret = self->__index(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint8_t___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8_t *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    uint8_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.uint8_t");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void __newindex(unsigned int idx, const uint8_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint8_t___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_uint8_t *)olua_toobj(L, 1, "olua.uint8_t");
    olua_push_object(L, self, "olua.uint8_t");

    olua_endinvoke(L);

    return 1;
}

static int _olua_uint8_t_create$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // @postnew @name(new) static olua_uint8_t *create(@optional size_t len)
    olua_uint8_t *ret = olua_uint8_t::create(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint8_t");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint8_t_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @postnew @name(new) static olua_uint8_t *create(@optional size_t len)
    olua_uint8_t *ret = olua_uint8_t::create();
    int num_ret = olua_push_object(L, ret, "olua.uint8_t");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint8_t_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @postnew @name(new) static olua_uint8_t *create(@optional size_t len)
        return _olua_uint8_t_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 1))) {
            // @postnew @name(new) static olua_uint8_t *create(@optional size_t len)
            return _olua_uint8_t_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint8_t::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint8_t_setstring(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8_t *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.uint8_t");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setstring(const char *data, size_t len)
    self->setstring(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint8_t_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8_t *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.uint8_t");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // olua_uint8_t *sub(size_t from, @optional size_t to)
    olua_uint8_t *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.uint8_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint8_t_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8_t *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.uint8_t");
    olua_check_integer(L, 2, &arg1);

    // olua_uint8_t *sub(size_t from, @optional size_t to)
    olua_uint8_t *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint8_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint8_t_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // olua_uint8_t *sub(size_t from, @optional size_t to)
            return _olua_uint8_t_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // olua_uint8_t *sub(size_t from, @optional size_t to)
            return _olua_uint8_t_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint8_t::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint8_t_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint8_t");

    // olua_uint8_t *take()
    olua_uint8_t *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.uint8_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint8_t_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8_t *self = nullptr;
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.uint8_t");
    olua_check_integer(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_uint8_t_data(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint8_t");

    // @getter @name(data) uint8_t *data()
    uint8_t *ret = self->data();
    int num_ret = olua_push_array(L, ret, "olua.uint8_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint8_t_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint8_t");

    // @getter @name(length) size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint8_t_rawdata(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint8_t");

    // @getter @name(rawdata) void *rawdata()
    void *ret = self->rawdata();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint8_t_size(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint8_t");

    // @getter @name(sizeof) size_t size()
    size_t ret = self->size();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint8_t_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint8_t");

    // @getter @name(value) const uint8_t &value()
    const uint8_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_uint8_t(lua_State *L)
{
    oluacls_class<olua_uint8_t>(L, "olua.uint8_t");
    oluacls_func(L, "__gc", _olua_uint8_t___gc);
    oluacls_func(L, "__index", _olua_uint8_t___index);
    oluacls_func(L, "__newindex", _olua_uint8_t___newindex);
    oluacls_func(L, "__olua_move", _olua_uint8_t___olua_move);
    oluacls_func(L, "new", _olua_uint8_t_create);
    oluacls_func(L, "setstring", _olua_uint8_t_setstring);
    oluacls_func(L, "sub", _olua_uint8_t_sub);
    oluacls_func(L, "take", _olua_uint8_t_take);
    oluacls_func(L, "tostring", _olua_uint8_t_tostring);
    oluacls_prop(L, "data", _olua_uint8_t_data, nullptr);
    oluacls_prop(L, "length", _olua_uint8_t_length, _olua_uint8_t_length);
    oluacls_prop(L, "rawdata", _olua_uint8_t_rawdata, nullptr);
    oluacls_prop(L, "sizeof", _olua_uint8_t_size, nullptr);
    oluacls_prop(L, "value", _olua_uint8_t_value, _olua_uint8_t_value);

    return 1;
}
OLUA_END_DECLS

static int _olua_uint16_t___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint16_t");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_uint16_t___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16_t *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.uint16_t");
    olua_check_integer(L, 2, &arg1);

    // uint16_t __index(unsigned int idx)
    uint16_t ret = self->__index(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint16_t___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16_t *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    uint16_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.uint16_t");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void __newindex(unsigned int idx, const uint16_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint16_t___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_uint16_t *)olua_toobj(L, 1, "olua.uint16_t");
    olua_push_object(L, self, "olua.uint16_t");

    olua_endinvoke(L);

    return 1;
}

static int _olua_uint16_t_create$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // @postnew @name(new) static olua_uint16_t *create(@optional size_t len)
    olua_uint16_t *ret = olua_uint16_t::create(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint16_t");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint16_t_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @postnew @name(new) static olua_uint16_t *create(@optional size_t len)
    olua_uint16_t *ret = olua_uint16_t::create();
    int num_ret = olua_push_object(L, ret, "olua.uint16_t");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint16_t_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @postnew @name(new) static olua_uint16_t *create(@optional size_t len)
        return _olua_uint16_t_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 1))) {
            // @postnew @name(new) static olua_uint16_t *create(@optional size_t len)
            return _olua_uint16_t_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint16_t::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint16_t_setstring(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16_t *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.uint16_t");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setstring(const char *data, size_t len)
    self->setstring(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint16_t_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16_t *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.uint16_t");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // olua_uint16_t *sub(size_t from, @optional size_t to)
    olua_uint16_t *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.uint16_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint16_t_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16_t *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.uint16_t");
    olua_check_integer(L, 2, &arg1);

    // olua_uint16_t *sub(size_t from, @optional size_t to)
    olua_uint16_t *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint16_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint16_t_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // olua_uint16_t *sub(size_t from, @optional size_t to)
            return _olua_uint16_t_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // olua_uint16_t *sub(size_t from, @optional size_t to)
            return _olua_uint16_t_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint16_t::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint16_t_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint16_t");

    // olua_uint16_t *take()
    olua_uint16_t *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.uint16_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint16_t_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16_t *self = nullptr;
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.uint16_t");
    olua_check_integer(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_uint16_t_data(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint16_t");

    // @getter @name(data) uint16_t *data()
    uint16_t *ret = self->data();
    int num_ret = olua_push_array(L, ret, "olua.uint16_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint16_t_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint16_t");

    // @getter @name(length) size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint16_t_rawdata(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint16_t");

    // @getter @name(rawdata) void *rawdata()
    void *ret = self->rawdata();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint16_t_size(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint16_t");

    // @getter @name(sizeof) size_t size()
    size_t ret = self->size();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint16_t_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint16_t");

    // @getter @name(value) const uint16_t &value()
    const uint16_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_uint16_t(lua_State *L)
{
    oluacls_class<olua_uint16_t>(L, "olua.uint16_t");
    oluacls_func(L, "__gc", _olua_uint16_t___gc);
    oluacls_func(L, "__index", _olua_uint16_t___index);
    oluacls_func(L, "__newindex", _olua_uint16_t___newindex);
    oluacls_func(L, "__olua_move", _olua_uint16_t___olua_move);
    oluacls_func(L, "new", _olua_uint16_t_create);
    oluacls_func(L, "setstring", _olua_uint16_t_setstring);
    oluacls_func(L, "sub", _olua_uint16_t_sub);
    oluacls_func(L, "take", _olua_uint16_t_take);
    oluacls_func(L, "tostring", _olua_uint16_t_tostring);
    oluacls_prop(L, "data", _olua_uint16_t_data, nullptr);
    oluacls_prop(L, "length", _olua_uint16_t_length, _olua_uint16_t_length);
    oluacls_prop(L, "rawdata", _olua_uint16_t_rawdata, nullptr);
    oluacls_prop(L, "sizeof", _olua_uint16_t_size, nullptr);
    oluacls_prop(L, "value", _olua_uint16_t_value, _olua_uint16_t_value);

    return 1;
}
OLUA_END_DECLS

static int _olua_uint32_t___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint32_t");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_uint32_t___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32_t *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.uint32_t");
    olua_check_integer(L, 2, &arg1);

    // uint32_t __index(unsigned int idx)
    uint32_t ret = self->__index(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint32_t___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32_t *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    uint32_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.uint32_t");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void __newindex(unsigned int idx, const uint32_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint32_t___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_uint32_t *)olua_toobj(L, 1, "olua.uint32_t");
    olua_push_object(L, self, "olua.uint32_t");

    olua_endinvoke(L);

    return 1;
}

static int _olua_uint32_t_create$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // @postnew @name(new) static olua_uint32_t *create(@optional size_t len)
    olua_uint32_t *ret = olua_uint32_t::create(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint32_t");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint32_t_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @postnew @name(new) static olua_uint32_t *create(@optional size_t len)
    olua_uint32_t *ret = olua_uint32_t::create();
    int num_ret = olua_push_object(L, ret, "olua.uint32_t");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint32_t_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @postnew @name(new) static olua_uint32_t *create(@optional size_t len)
        return _olua_uint32_t_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 1))) {
            // @postnew @name(new) static olua_uint32_t *create(@optional size_t len)
            return _olua_uint32_t_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint32_t::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint32_t_setstring(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32_t *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.uint32_t");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setstring(const char *data, size_t len)
    self->setstring(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint32_t_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32_t *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.uint32_t");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // olua_uint32_t *sub(size_t from, @optional size_t to)
    olua_uint32_t *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.uint32_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint32_t_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32_t *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.uint32_t");
    olua_check_integer(L, 2, &arg1);

    // olua_uint32_t *sub(size_t from, @optional size_t to)
    olua_uint32_t *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint32_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint32_t_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // olua_uint32_t *sub(size_t from, @optional size_t to)
            return _olua_uint32_t_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // olua_uint32_t *sub(size_t from, @optional size_t to)
            return _olua_uint32_t_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint32_t::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint32_t_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint32_t");

    // olua_uint32_t *take()
    olua_uint32_t *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.uint32_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint32_t_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32_t *self = nullptr;
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.uint32_t");
    olua_check_integer(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_uint32_t_data(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint32_t");

    // @getter @name(data) uint32_t *data()
    uint32_t *ret = self->data();
    int num_ret = olua_push_array(L, ret, "olua.uint32_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint32_t_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint32_t");

    // @getter @name(length) size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint32_t_rawdata(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint32_t");

    // @getter @name(rawdata) void *rawdata()
    void *ret = self->rawdata();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint32_t_size(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint32_t");

    // @getter @name(sizeof) size_t size()
    size_t ret = self->size();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint32_t_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint32_t");

    // @getter @name(value) const uint32_t &value()
    const uint32_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_uint32_t(lua_State *L)
{
    oluacls_class<olua_uint32_t>(L, "olua.uint32_t");
    oluacls_func(L, "__gc", _olua_uint32_t___gc);
    oluacls_func(L, "__index", _olua_uint32_t___index);
    oluacls_func(L, "__newindex", _olua_uint32_t___newindex);
    oluacls_func(L, "__olua_move", _olua_uint32_t___olua_move);
    oluacls_func(L, "new", _olua_uint32_t_create);
    oluacls_func(L, "setstring", _olua_uint32_t_setstring);
    oluacls_func(L, "sub", _olua_uint32_t_sub);
    oluacls_func(L, "take", _olua_uint32_t_take);
    oluacls_func(L, "tostring", _olua_uint32_t_tostring);
    oluacls_prop(L, "data", _olua_uint32_t_data, nullptr);
    oluacls_prop(L, "length", _olua_uint32_t_length, _olua_uint32_t_length);
    oluacls_prop(L, "rawdata", _olua_uint32_t_rawdata, nullptr);
    oluacls_prop(L, "sizeof", _olua_uint32_t_size, nullptr);
    oluacls_prop(L, "value", _olua_uint32_t_value, _olua_uint32_t_value);

    return 1;
}
OLUA_END_DECLS

static int _olua_uint64_t___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint64_t");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_uint64_t___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64_t *self = nullptr;
    unsigned int arg1 = 0;       /** idx */

    olua_to_object(L, 1, &self, "olua.uint64_t");
    olua_check_integer(L, 2, &arg1);

    // uint64_t __index(unsigned int idx)
    uint64_t ret = self->__index(arg1);
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint64_t___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64_t *self = nullptr;
    unsigned int arg1 = 0;       /** idx */
    uint64_t arg2 = 0;       /** v */

    olua_to_object(L, 1, &self, "olua.uint64_t");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void __newindex(unsigned int idx, const uint64_t &v)
    self->__newindex(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint64_t___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_uint64_t *)olua_toobj(L, 1, "olua.uint64_t");
    olua_push_object(L, self, "olua.uint64_t");

    olua_endinvoke(L);

    return 1;
}

static int _olua_uint64_t_create$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // @postnew @name(new) static olua_uint64_t *create(@optional size_t len)
    olua_uint64_t *ret = olua_uint64_t::create(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint64_t");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint64_t_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @postnew @name(new) static olua_uint64_t *create(@optional size_t len)
    olua_uint64_t *ret = olua_uint64_t::create();
    int num_ret = olua_push_object(L, ret, "olua.uint64_t");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint64_t_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @postnew @name(new) static olua_uint64_t *create(@optional size_t len)
        return _olua_uint64_t_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 1))) {
            // @postnew @name(new) static olua_uint64_t *create(@optional size_t len)
            return _olua_uint64_t_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint64_t::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint64_t_setstring(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64_t *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.uint64_t");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setstring(const char *data, size_t len)
    self->setstring(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint64_t_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64_t *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.uint64_t");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // olua_uint64_t *sub(size_t from, @optional size_t to)
    olua_uint64_t *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.uint64_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint64_t_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64_t *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.uint64_t");
    olua_check_integer(L, 2, &arg1);

    // olua_uint64_t *sub(size_t from, @optional size_t to)
    olua_uint64_t *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint64_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint64_t_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // olua_uint64_t *sub(size_t from, @optional size_t to)
            return _olua_uint64_t_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // olua_uint64_t *sub(size_t from, @optional size_t to)
            return _olua_uint64_t_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint64_t::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint64_t_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint64_t");

    // olua_uint64_t *take()
    olua_uint64_t *ret = self->take();
    int num_ret = olua_push_object(L, ret, "olua.uint64_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint64_t_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64_t *self = nullptr;
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.uint64_t");
    olua_check_integer(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_uint64_t_data(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint64_t");

    // @getter @name(data) uint64_t *data()
    uint64_t *ret = self->data();
    int num_ret = olua_push_array(L, ret, "olua.uint64_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint64_t_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint64_t");

    // @getter @name(length) size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint64_t_rawdata(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint64_t");

    // @getter @name(rawdata) void *rawdata()
    void *ret = self->rawdata();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint64_t_size(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint64_t");

    // @getter @name(sizeof) size_t size()
    size_t ret = self->size();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint64_t_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint64_t");

    // @getter @name(value) const uint64_t &value()
    const uint64_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_uint64_t(lua_State *L)
{
    oluacls_class<olua_uint64_t>(L, "olua.uint64_t");
    oluacls_func(L, "__gc", _olua_uint64_t___gc);
    oluacls_func(L, "__index", _olua_uint64_t___index);
    oluacls_func(L, "__newindex", _olua_uint64_t___newindex);
    oluacls_func(L, "__olua_move", _olua_uint64_t___olua_move);
    oluacls_func(L, "new", _olua_uint64_t_create);
    oluacls_func(L, "setstring", _olua_uint64_t_setstring);
    oluacls_func(L, "sub", _olua_uint64_t_sub);
    oluacls_func(L, "take", _olua_uint64_t_take);
    oluacls_func(L, "tostring", _olua_uint64_t_tostring);
    oluacls_prop(L, "data", _olua_uint64_t_data, nullptr);
    oluacls_prop(L, "length", _olua_uint64_t_length, _olua_uint64_t_length);
    oluacls_prop(L, "rawdata", _olua_uint64_t_rawdata, nullptr);
    oluacls_prop(L, "sizeof", _olua_uint64_t_size, nullptr);
    oluacls_prop(L, "value", _olua_uint64_t_value, _olua_uint64_t_value);

    return 1;
}
OLUA_END_DECLS

static int _olua_char___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_char *self = nullptr;

    olua_to_object(L, 1, &self, "olua.char");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_char___index(lua_State *L)
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

static int _olua_char___newindex(lua_State *L)
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

static int _olua_char___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_char *)olua_toobj(L, 1, "olua.char");
    olua_push_object(L, self, "olua.char");

    olua_endinvoke(L);

    return 1;
}

static int _olua_char_create$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // @postnew @name(new) static olua_char *create(@optional size_t len)
    olua_char *ret = olua_char::create(arg1);
    int num_ret = olua_push_object(L, ret, "olua.char");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_char_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @postnew @name(new) static olua_char *create(@optional size_t len)
    olua_char *ret = olua_char::create();
    int num_ret = olua_push_object(L, ret, "olua.char");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_char_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @postnew @name(new) static olua_char *create(@optional size_t len)
        return _olua_char_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 1))) {
            // @postnew @name(new) static olua_char *create(@optional size_t len)
            return _olua_char_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_char::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_char_setstring(lua_State *L)
{
    olua_startinvoke(L);

    olua_char *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.char");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setstring(const char *data, size_t len)
    self->setstring(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_char_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_char *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.char");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // olua_char *sub(size_t from, @optional size_t to)
    olua_char *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.char");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_char_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_char *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.char");
    olua_check_integer(L, 2, &arg1);

    // olua_char *sub(size_t from, @optional size_t to)
    olua_char *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.char");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_char_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // olua_char *sub(size_t from, @optional size_t to)
            return _olua_char_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // olua_char *sub(size_t from, @optional size_t to)
            return _olua_char_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_char::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_char_take(lua_State *L)
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

static int _olua_char_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_char *self = nullptr;
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.char");
    olua_check_integer(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_char_data(lua_State *L)
{
    olua_startinvoke(L);

    olua_char *self = nullptr;

    olua_to_object(L, 1, &self, "olua.char");

    // @getter @name(data) olua_char_t *data()
    olua_char_t *ret = self->data();
    int num_ret = olua_push_array(L, ret, "olua.char");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_char_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_char *self = nullptr;

    olua_to_object(L, 1, &self, "olua.char");

    // @getter @name(length) size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_char_rawdata(lua_State *L)
{
    olua_startinvoke(L);

    olua_char *self = nullptr;

    olua_to_object(L, 1, &self, "olua.char");

    // @getter @name(rawdata) void *rawdata()
    void *ret = self->rawdata();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_char_size(lua_State *L)
{
    olua_startinvoke(L);

    olua_char *self = nullptr;

    olua_to_object(L, 1, &self, "olua.char");

    // @getter @name(sizeof) size_t size()
    size_t ret = self->size();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_char_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_char *self = nullptr;

    olua_to_object(L, 1, &self, "olua.char");

    // @getter @name(value) const olua_char_t &value()
    const olua_char_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_char(lua_State *L)
{
    oluacls_class<olua_char>(L, "olua.char");
    oluacls_func(L, "__gc", _olua_char___gc);
    oluacls_func(L, "__index", _olua_char___index);
    oluacls_func(L, "__newindex", _olua_char___newindex);
    oluacls_func(L, "__olua_move", _olua_char___olua_move);
    oluacls_func(L, "new", _olua_char_create);
    oluacls_func(L, "setstring", _olua_char_setstring);
    oluacls_func(L, "sub", _olua_char_sub);
    oluacls_func(L, "take", _olua_char_take);
    oluacls_func(L, "tostring", _olua_char_tostring);
    oluacls_prop(L, "data", _olua_char_data, nullptr);
    oluacls_prop(L, "length", _olua_char_length, _olua_char_length);
    oluacls_prop(L, "rawdata", _olua_char_rawdata, nullptr);
    oluacls_prop(L, "sizeof", _olua_char_size, nullptr);
    oluacls_prop(L, "value", _olua_char_value, _olua_char_value);

    return 1;
}
OLUA_END_DECLS

static int _olua_short___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;

    olua_to_object(L, 1, &self, "olua.short");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_short___index(lua_State *L)
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

static int _olua_short___newindex(lua_State *L)
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

static int _olua_short___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_short *)olua_toobj(L, 1, "olua.short");
    olua_push_object(L, self, "olua.short");

    olua_endinvoke(L);

    return 1;
}

static int _olua_short_create$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // @postnew @name(new) static olua_short *create(@optional size_t len)
    olua_short *ret = olua_short::create(arg1);
    int num_ret = olua_push_object(L, ret, "olua.short");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_short_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @postnew @name(new) static olua_short *create(@optional size_t len)
    olua_short *ret = olua_short::create();
    int num_ret = olua_push_object(L, ret, "olua.short");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_short_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @postnew @name(new) static olua_short *create(@optional size_t len)
        return _olua_short_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 1))) {
            // @postnew @name(new) static olua_short *create(@optional size_t len)
            return _olua_short_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_short::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_short_setstring(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.short");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setstring(const char *data, size_t len)
    self->setstring(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_short_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.short");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // olua_short *sub(size_t from, @optional size_t to)
    olua_short *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.short");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_short_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.short");
    olua_check_integer(L, 2, &arg1);

    // olua_short *sub(size_t from, @optional size_t to)
    olua_short *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.short");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_short_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // olua_short *sub(size_t from, @optional size_t to)
            return _olua_short_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // olua_short *sub(size_t from, @optional size_t to)
            return _olua_short_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_short::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_short_take(lua_State *L)
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

static int _olua_short_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.short");
    olua_check_integer(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_short_data(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;

    olua_to_object(L, 1, &self, "olua.short");

    // @getter @name(data) olua_short_t *data()
    olua_short_t *ret = self->data();
    int num_ret = olua_push_array(L, ret, "olua.short");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_short_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;

    olua_to_object(L, 1, &self, "olua.short");

    // @getter @name(length) size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_short_rawdata(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;

    olua_to_object(L, 1, &self, "olua.short");

    // @getter @name(rawdata) void *rawdata()
    void *ret = self->rawdata();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_short_size(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;

    olua_to_object(L, 1, &self, "olua.short");

    // @getter @name(sizeof) size_t size()
    size_t ret = self->size();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_short_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;

    olua_to_object(L, 1, &self, "olua.short");

    // @getter @name(value) const olua_short_t &value()
    const olua_short_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_short(lua_State *L)
{
    oluacls_class<olua_short>(L, "olua.short");
    oluacls_func(L, "__gc", _olua_short___gc);
    oluacls_func(L, "__index", _olua_short___index);
    oluacls_func(L, "__newindex", _olua_short___newindex);
    oluacls_func(L, "__olua_move", _olua_short___olua_move);
    oluacls_func(L, "new", _olua_short_create);
    oluacls_func(L, "setstring", _olua_short_setstring);
    oluacls_func(L, "sub", _olua_short_sub);
    oluacls_func(L, "take", _olua_short_take);
    oluacls_func(L, "tostring", _olua_short_tostring);
    oluacls_prop(L, "data", _olua_short_data, nullptr);
    oluacls_prop(L, "length", _olua_short_length, _olua_short_length);
    oluacls_prop(L, "rawdata", _olua_short_rawdata, nullptr);
    oluacls_prop(L, "sizeof", _olua_short_size, nullptr);
    oluacls_prop(L, "value", _olua_short_value, _olua_short_value);

    return 1;
}
OLUA_END_DECLS

static int _olua_int___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_int___index(lua_State *L)
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

static int _olua_int___newindex(lua_State *L)
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

static int _olua_int___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_int *)olua_toobj(L, 1, "olua.int");
    olua_push_object(L, self, "olua.int");

    olua_endinvoke(L);

    return 1;
}

static int _olua_int_create$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // @postnew @name(new) static olua_int *create(@optional size_t len)
    olua_int *ret = olua_int::create(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @postnew @name(new) static olua_int *create(@optional size_t len)
    olua_int *ret = olua_int::create();
    int num_ret = olua_push_object(L, ret, "olua.int");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @postnew @name(new) static olua_int *create(@optional size_t len)
        return _olua_int_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 1))) {
            // @postnew @name(new) static olua_int *create(@optional size_t len)
            return _olua_int_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_int::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int_setstring(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.int");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setstring(const char *data, size_t len)
    self->setstring(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.int");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // olua_int *sub(size_t from, @optional size_t to)
    olua_int *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.int");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.int");
    olua_check_integer(L, 2, &arg1);

    // olua_int *sub(size_t from, @optional size_t to)
    olua_int *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.int");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // olua_int *sub(size_t from, @optional size_t to)
            return _olua_int_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // olua_int *sub(size_t from, @optional size_t to)
            return _olua_int_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_int::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int_take(lua_State *L)
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

static int _olua_int_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.int");
    olua_check_integer(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_int_data(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int");

    // @getter @name(data) olua_int_t *data()
    olua_int_t *ret = self->data();
    int num_ret = olua_push_array(L, ret, "olua.int");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int");

    // @getter @name(length) size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int_rawdata(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int");

    // @getter @name(rawdata) void *rawdata()
    void *ret = self->rawdata();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int_size(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int");

    // @getter @name(sizeof) size_t size()
    size_t ret = self->size();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;

    olua_to_object(L, 1, &self, "olua.int");

    // @getter @name(value) const olua_int_t &value()
    const olua_int_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_int(lua_State *L)
{
    oluacls_class<olua_int>(L, "olua.int");
    oluacls_func(L, "__gc", _olua_int___gc);
    oluacls_func(L, "__index", _olua_int___index);
    oluacls_func(L, "__newindex", _olua_int___newindex);
    oluacls_func(L, "__olua_move", _olua_int___olua_move);
    oluacls_func(L, "new", _olua_int_create);
    oluacls_func(L, "setstring", _olua_int_setstring);
    oluacls_func(L, "sub", _olua_int_sub);
    oluacls_func(L, "take", _olua_int_take);
    oluacls_func(L, "tostring", _olua_int_tostring);
    oluacls_prop(L, "data", _olua_int_data, nullptr);
    oluacls_prop(L, "length", _olua_int_length, _olua_int_length);
    oluacls_prop(L, "rawdata", _olua_int_rawdata, nullptr);
    oluacls_prop(L, "sizeof", _olua_int_size, nullptr);
    oluacls_prop(L, "value", _olua_int_value, _olua_int_value);

    return 1;
}
OLUA_END_DECLS

static int _olua_long___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;

    olua_to_object(L, 1, &self, "olua.long");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_long___index(lua_State *L)
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

static int _olua_long___newindex(lua_State *L)
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

static int _olua_long___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_long *)olua_toobj(L, 1, "olua.long");
    olua_push_object(L, self, "olua.long");

    olua_endinvoke(L);

    return 1;
}

static int _olua_long_create$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // @postnew @name(new) static olua_long *create(@optional size_t len)
    olua_long *ret = olua_long::create(arg1);
    int num_ret = olua_push_object(L, ret, "olua.long");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_long_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @postnew @name(new) static olua_long *create(@optional size_t len)
    olua_long *ret = olua_long::create();
    int num_ret = olua_push_object(L, ret, "olua.long");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_long_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @postnew @name(new) static olua_long *create(@optional size_t len)
        return _olua_long_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 1))) {
            // @postnew @name(new) static olua_long *create(@optional size_t len)
            return _olua_long_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_long::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_long_setstring(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.long");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setstring(const char *data, size_t len)
    self->setstring(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_long_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.long");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // olua_long *sub(size_t from, @optional size_t to)
    olua_long *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.long");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_long_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.long");
    olua_check_integer(L, 2, &arg1);

    // olua_long *sub(size_t from, @optional size_t to)
    olua_long *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.long");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_long_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // olua_long *sub(size_t from, @optional size_t to)
            return _olua_long_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // olua_long *sub(size_t from, @optional size_t to)
            return _olua_long_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_long::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_long_take(lua_State *L)
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

static int _olua_long_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.long");
    olua_check_integer(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_long_data(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;

    olua_to_object(L, 1, &self, "olua.long");

    // @getter @name(data) olua_long_t *data()
    olua_long_t *ret = self->data();
    int num_ret = olua_push_array(L, ret, "olua.long");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_long_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;

    olua_to_object(L, 1, &self, "olua.long");

    // @getter @name(length) size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_long_rawdata(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;

    olua_to_object(L, 1, &self, "olua.long");

    // @getter @name(rawdata) void *rawdata()
    void *ret = self->rawdata();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_long_size(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;

    olua_to_object(L, 1, &self, "olua.long");

    // @getter @name(sizeof) size_t size()
    size_t ret = self->size();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_long_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;

    olua_to_object(L, 1, &self, "olua.long");

    // @getter @name(value) const olua_long_t &value()
    const olua_long_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_long(lua_State *L)
{
    oluacls_class<olua_long>(L, "olua.long");
    oluacls_func(L, "__gc", _olua_long___gc);
    oluacls_func(L, "__index", _olua_long___index);
    oluacls_func(L, "__newindex", _olua_long___newindex);
    oluacls_func(L, "__olua_move", _olua_long___olua_move);
    oluacls_func(L, "new", _olua_long_create);
    oluacls_func(L, "setstring", _olua_long_setstring);
    oluacls_func(L, "sub", _olua_long_sub);
    oluacls_func(L, "take", _olua_long_take);
    oluacls_func(L, "tostring", _olua_long_tostring);
    oluacls_prop(L, "data", _olua_long_data, nullptr);
    oluacls_prop(L, "length", _olua_long_length, _olua_long_length);
    oluacls_prop(L, "rawdata", _olua_long_rawdata, nullptr);
    oluacls_prop(L, "sizeof", _olua_long_size, nullptr);
    oluacls_prop(L, "value", _olua_long_value, _olua_long_value);

    return 1;
}
OLUA_END_DECLS

static int _olua_llong___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.llong");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_llong___index(lua_State *L)
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

static int _olua_llong___newindex(lua_State *L)
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

static int _olua_llong___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_llong *)olua_toobj(L, 1, "olua.llong");
    olua_push_object(L, self, "olua.llong");

    olua_endinvoke(L);

    return 1;
}

static int _olua_llong_create$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // @postnew @name(new) static olua_llong *create(@optional size_t len)
    olua_llong *ret = olua_llong::create(arg1);
    int num_ret = olua_push_object(L, ret, "olua.llong");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_llong_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @postnew @name(new) static olua_llong *create(@optional size_t len)
    olua_llong *ret = olua_llong::create();
    int num_ret = olua_push_object(L, ret, "olua.llong");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_llong_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @postnew @name(new) static olua_llong *create(@optional size_t len)
        return _olua_llong_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 1))) {
            // @postnew @name(new) static olua_llong *create(@optional size_t len)
            return _olua_llong_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_llong::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_llong_setstring(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.llong");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setstring(const char *data, size_t len)
    self->setstring(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_llong_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.llong");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // olua_llong *sub(size_t from, @optional size_t to)
    olua_llong *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.llong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_llong_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.llong");
    olua_check_integer(L, 2, &arg1);

    // olua_llong *sub(size_t from, @optional size_t to)
    olua_llong *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.llong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_llong_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // olua_llong *sub(size_t from, @optional size_t to)
            return _olua_llong_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // olua_llong *sub(size_t from, @optional size_t to)
            return _olua_llong_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_llong::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_llong_take(lua_State *L)
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

static int _olua_llong_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.llong");
    olua_check_integer(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_llong_data(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.llong");

    // @getter @name(data) olua_llong_t *data()
    olua_llong_t *ret = self->data();
    int num_ret = olua_push_array(L, ret, "olua.llong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_llong_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.llong");

    // @getter @name(length) size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_llong_rawdata(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.llong");

    // @getter @name(rawdata) void *rawdata()
    void *ret = self->rawdata();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_llong_size(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.llong");

    // @getter @name(sizeof) size_t size()
    size_t ret = self->size();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_llong_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.llong");

    // @getter @name(value) const olua_llong_t &value()
    const olua_llong_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_llong(lua_State *L)
{
    oluacls_class<olua_llong>(L, "olua.llong");
    oluacls_func(L, "__gc", _olua_llong___gc);
    oluacls_func(L, "__index", _olua_llong___index);
    oluacls_func(L, "__newindex", _olua_llong___newindex);
    oluacls_func(L, "__olua_move", _olua_llong___olua_move);
    oluacls_func(L, "new", _olua_llong_create);
    oluacls_func(L, "setstring", _olua_llong_setstring);
    oluacls_func(L, "sub", _olua_llong_sub);
    oluacls_func(L, "take", _olua_llong_take);
    oluacls_func(L, "tostring", _olua_llong_tostring);
    oluacls_prop(L, "data", _olua_llong_data, nullptr);
    oluacls_prop(L, "length", _olua_llong_length, _olua_llong_length);
    oluacls_prop(L, "rawdata", _olua_llong_rawdata, nullptr);
    oluacls_prop(L, "sizeof", _olua_llong_size, nullptr);
    oluacls_prop(L, "value", _olua_llong_value, _olua_llong_value);

    return 1;
}
OLUA_END_DECLS

static int _olua_uchar___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_uchar *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uchar");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_uchar___index(lua_State *L)
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

static int _olua_uchar___newindex(lua_State *L)
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

static int _olua_uchar___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_uchar *)olua_toobj(L, 1, "olua.uchar");
    olua_push_object(L, self, "olua.uchar");

    olua_endinvoke(L);

    return 1;
}

static int _olua_uchar_create$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // @postnew @name(new) static olua_uchar *create(@optional size_t len)
    olua_uchar *ret = olua_uchar::create(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uchar");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uchar_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @postnew @name(new) static olua_uchar *create(@optional size_t len)
    olua_uchar *ret = olua_uchar::create();
    int num_ret = olua_push_object(L, ret, "olua.uchar");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uchar_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @postnew @name(new) static olua_uchar *create(@optional size_t len)
        return _olua_uchar_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 1))) {
            // @postnew @name(new) static olua_uchar *create(@optional size_t len)
            return _olua_uchar_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_uchar::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uchar_setstring(lua_State *L)
{
    olua_startinvoke(L);

    olua_uchar *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.uchar");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setstring(const char *data, size_t len)
    self->setstring(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uchar_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uchar *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.uchar");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // olua_uchar *sub(size_t from, @optional size_t to)
    olua_uchar *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.uchar");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uchar_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uchar *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.uchar");
    olua_check_integer(L, 2, &arg1);

    // olua_uchar *sub(size_t from, @optional size_t to)
    olua_uchar *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uchar");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uchar_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // olua_uchar *sub(size_t from, @optional size_t to)
            return _olua_uchar_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // olua_uchar *sub(size_t from, @optional size_t to)
            return _olua_uchar_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_uchar::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uchar_take(lua_State *L)
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

static int _olua_uchar_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_uchar *self = nullptr;
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.uchar");
    olua_check_integer(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_uchar_data(lua_State *L)
{
    olua_startinvoke(L);

    olua_uchar *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uchar");

    // @getter @name(data) olua_uchar_t *data()
    olua_uchar_t *ret = self->data();
    int num_ret = olua_push_array(L, ret, "olua.uchar");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uchar_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_uchar *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uchar");

    // @getter @name(length) size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uchar_rawdata(lua_State *L)
{
    olua_startinvoke(L);

    olua_uchar *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uchar");

    // @getter @name(rawdata) void *rawdata()
    void *ret = self->rawdata();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uchar_size(lua_State *L)
{
    olua_startinvoke(L);

    olua_uchar *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uchar");

    // @getter @name(sizeof) size_t size()
    size_t ret = self->size();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uchar_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_uchar *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uchar");

    // @getter @name(value) const olua_uchar_t &value()
    const olua_uchar_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_uchar(lua_State *L)
{
    oluacls_class<olua_uchar>(L, "olua.uchar");
    oluacls_func(L, "__gc", _olua_uchar___gc);
    oluacls_func(L, "__index", _olua_uchar___index);
    oluacls_func(L, "__newindex", _olua_uchar___newindex);
    oluacls_func(L, "__olua_move", _olua_uchar___olua_move);
    oluacls_func(L, "new", _olua_uchar_create);
    oluacls_func(L, "setstring", _olua_uchar_setstring);
    oluacls_func(L, "sub", _olua_uchar_sub);
    oluacls_func(L, "take", _olua_uchar_take);
    oluacls_func(L, "tostring", _olua_uchar_tostring);
    oluacls_prop(L, "data", _olua_uchar_data, nullptr);
    oluacls_prop(L, "length", _olua_uchar_length, _olua_uchar_length);
    oluacls_prop(L, "rawdata", _olua_uchar_rawdata, nullptr);
    oluacls_prop(L, "sizeof", _olua_uchar_size, nullptr);
    oluacls_prop(L, "value", _olua_uchar_value, _olua_uchar_value);

    return 1;
}
OLUA_END_DECLS

static int _olua_ushort___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ushort");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_ushort___index(lua_State *L)
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

static int _olua_ushort___newindex(lua_State *L)
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

static int _olua_ushort___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_ushort *)olua_toobj(L, 1, "olua.ushort");
    olua_push_object(L, self, "olua.ushort");

    olua_endinvoke(L);

    return 1;
}

static int _olua_ushort_create$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // @postnew @name(new) static olua_ushort *create(@optional size_t len)
    olua_ushort *ret = olua_ushort::create(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ushort");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ushort_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @postnew @name(new) static olua_ushort *create(@optional size_t len)
    olua_ushort *ret = olua_ushort::create();
    int num_ret = olua_push_object(L, ret, "olua.ushort");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ushort_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @postnew @name(new) static olua_ushort *create(@optional size_t len)
        return _olua_ushort_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 1))) {
            // @postnew @name(new) static olua_ushort *create(@optional size_t len)
            return _olua_ushort_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_ushort::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ushort_setstring(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.ushort");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setstring(const char *data, size_t len)
    self->setstring(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ushort_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.ushort");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // olua_ushort *sub(size_t from, @optional size_t to)
    olua_ushort *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.ushort");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ushort_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.ushort");
    olua_check_integer(L, 2, &arg1);

    // olua_ushort *sub(size_t from, @optional size_t to)
    olua_ushort *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ushort");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ushort_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // olua_ushort *sub(size_t from, @optional size_t to)
            return _olua_ushort_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // olua_ushort *sub(size_t from, @optional size_t to)
            return _olua_ushort_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_ushort::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ushort_take(lua_State *L)
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

static int _olua_ushort_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.ushort");
    olua_check_integer(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_ushort_data(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ushort");

    // @getter @name(data) olua_ushort_t *data()
    olua_ushort_t *ret = self->data();
    int num_ret = olua_push_array(L, ret, "olua.ushort");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ushort_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ushort");

    // @getter @name(length) size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ushort_rawdata(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ushort");

    // @getter @name(rawdata) void *rawdata()
    void *ret = self->rawdata();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ushort_size(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ushort");

    // @getter @name(sizeof) size_t size()
    size_t ret = self->size();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ushort_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ushort");

    // @getter @name(value) const olua_ushort_t &value()
    const olua_ushort_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_ushort(lua_State *L)
{
    oluacls_class<olua_ushort>(L, "olua.ushort");
    oluacls_func(L, "__gc", _olua_ushort___gc);
    oluacls_func(L, "__index", _olua_ushort___index);
    oluacls_func(L, "__newindex", _olua_ushort___newindex);
    oluacls_func(L, "__olua_move", _olua_ushort___olua_move);
    oluacls_func(L, "new", _olua_ushort_create);
    oluacls_func(L, "setstring", _olua_ushort_setstring);
    oluacls_func(L, "sub", _olua_ushort_sub);
    oluacls_func(L, "take", _olua_ushort_take);
    oluacls_func(L, "tostring", _olua_ushort_tostring);
    oluacls_prop(L, "data", _olua_ushort_data, nullptr);
    oluacls_prop(L, "length", _olua_ushort_length, _olua_ushort_length);
    oluacls_prop(L, "rawdata", _olua_ushort_rawdata, nullptr);
    oluacls_prop(L, "sizeof", _olua_ushort_size, nullptr);
    oluacls_prop(L, "value", _olua_ushort_value, _olua_ushort_value);

    return 1;
}
OLUA_END_DECLS

static int _olua_uint___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_uint___index(lua_State *L)
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

static int _olua_uint___newindex(lua_State *L)
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

static int _olua_uint___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_uint *)olua_toobj(L, 1, "olua.uint");
    olua_push_object(L, self, "olua.uint");

    olua_endinvoke(L);

    return 1;
}

static int _olua_uint_create$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // @postnew @name(new) static olua_uint *create(@optional size_t len)
    olua_uint *ret = olua_uint::create(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @postnew @name(new) static olua_uint *create(@optional size_t len)
    olua_uint *ret = olua_uint::create();
    int num_ret = olua_push_object(L, ret, "olua.uint");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @postnew @name(new) static olua_uint *create(@optional size_t len)
        return _olua_uint_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 1))) {
            // @postnew @name(new) static olua_uint *create(@optional size_t len)
            return _olua_uint_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint_setstring(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.uint");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setstring(const char *data, size_t len)
    self->setstring(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.uint");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // olua_uint *sub(size_t from, @optional size_t to)
    olua_uint *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.uint");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.uint");
    olua_check_integer(L, 2, &arg1);

    // olua_uint *sub(size_t from, @optional size_t to)
    olua_uint *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.uint");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // olua_uint *sub(size_t from, @optional size_t to)
            return _olua_uint_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // olua_uint *sub(size_t from, @optional size_t to)
            return _olua_uint_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint_take(lua_State *L)
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

static int _olua_uint_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.uint");
    olua_check_integer(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_uint_data(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint");

    // @getter @name(data) olua_uint_t *data()
    olua_uint_t *ret = self->data();
    int num_ret = olua_push_array(L, ret, "olua.uint");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint");

    // @getter @name(length) size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint_rawdata(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint");

    // @getter @name(rawdata) void *rawdata()
    void *ret = self->rawdata();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint_size(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint");

    // @getter @name(sizeof) size_t size()
    size_t ret = self->size();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;

    olua_to_object(L, 1, &self, "olua.uint");

    // @getter @name(value) const olua_uint_t &value()
    const olua_uint_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_uint(lua_State *L)
{
    oluacls_class<olua_uint>(L, "olua.uint");
    oluacls_func(L, "__gc", _olua_uint___gc);
    oluacls_func(L, "__index", _olua_uint___index);
    oluacls_func(L, "__newindex", _olua_uint___newindex);
    oluacls_func(L, "__olua_move", _olua_uint___olua_move);
    oluacls_func(L, "new", _olua_uint_create);
    oluacls_func(L, "setstring", _olua_uint_setstring);
    oluacls_func(L, "sub", _olua_uint_sub);
    oluacls_func(L, "take", _olua_uint_take);
    oluacls_func(L, "tostring", _olua_uint_tostring);
    oluacls_prop(L, "data", _olua_uint_data, nullptr);
    oluacls_prop(L, "length", _olua_uint_length, _olua_uint_length);
    oluacls_prop(L, "rawdata", _olua_uint_rawdata, nullptr);
    oluacls_prop(L, "sizeof", _olua_uint_size, nullptr);
    oluacls_prop(L, "value", _olua_uint_value, _olua_uint_value);

    return 1;
}
OLUA_END_DECLS

static int _olua_ulong___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ulong");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_ulong___index(lua_State *L)
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

static int _olua_ulong___newindex(lua_State *L)
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

static int _olua_ulong___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_ulong *)olua_toobj(L, 1, "olua.ulong");
    olua_push_object(L, self, "olua.ulong");

    olua_endinvoke(L);

    return 1;
}

static int _olua_ulong_create$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // @postnew @name(new) static olua_ulong *create(@optional size_t len)
    olua_ulong *ret = olua_ulong::create(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ulong");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ulong_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @postnew @name(new) static olua_ulong *create(@optional size_t len)
    olua_ulong *ret = olua_ulong::create();
    int num_ret = olua_push_object(L, ret, "olua.ulong");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ulong_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @postnew @name(new) static olua_ulong *create(@optional size_t len)
        return _olua_ulong_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 1))) {
            // @postnew @name(new) static olua_ulong *create(@optional size_t len)
            return _olua_ulong_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_ulong::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ulong_setstring(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.ulong");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setstring(const char *data, size_t len)
    self->setstring(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ulong_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.ulong");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // olua_ulong *sub(size_t from, @optional size_t to)
    olua_ulong *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.ulong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ulong_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.ulong");
    olua_check_integer(L, 2, &arg1);

    // olua_ulong *sub(size_t from, @optional size_t to)
    olua_ulong *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ulong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ulong_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // olua_ulong *sub(size_t from, @optional size_t to)
            return _olua_ulong_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // olua_ulong *sub(size_t from, @optional size_t to)
            return _olua_ulong_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_ulong::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ulong_take(lua_State *L)
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

static int _olua_ulong_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.ulong");
    olua_check_integer(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_ulong_data(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ulong");

    // @getter @name(data) olua_ulong_t *data()
    olua_ulong_t *ret = self->data();
    int num_ret = olua_push_array(L, ret, "olua.ulong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ulong_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ulong");

    // @getter @name(length) size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ulong_rawdata(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ulong");

    // @getter @name(rawdata) void *rawdata()
    void *ret = self->rawdata();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ulong_size(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ulong");

    // @getter @name(sizeof) size_t size()
    size_t ret = self->size();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ulong_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ulong");

    // @getter @name(value) const olua_ulong_t &value()
    const olua_ulong_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_ulong(lua_State *L)
{
    oluacls_class<olua_ulong>(L, "olua.ulong");
    oluacls_func(L, "__gc", _olua_ulong___gc);
    oluacls_func(L, "__index", _olua_ulong___index);
    oluacls_func(L, "__newindex", _olua_ulong___newindex);
    oluacls_func(L, "__olua_move", _olua_ulong___olua_move);
    oluacls_func(L, "new", _olua_ulong_create);
    oluacls_func(L, "setstring", _olua_ulong_setstring);
    oluacls_func(L, "sub", _olua_ulong_sub);
    oluacls_func(L, "take", _olua_ulong_take);
    oluacls_func(L, "tostring", _olua_ulong_tostring);
    oluacls_prop(L, "data", _olua_ulong_data, nullptr);
    oluacls_prop(L, "length", _olua_ulong_length, _olua_ulong_length);
    oluacls_prop(L, "rawdata", _olua_ulong_rawdata, nullptr);
    oluacls_prop(L, "sizeof", _olua_ulong_size, nullptr);
    oluacls_prop(L, "value", _olua_ulong_value, _olua_ulong_value);

    return 1;
}
OLUA_END_DECLS

static int _olua_ullong___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ullong");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_ullong___index(lua_State *L)
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

static int _olua_ullong___newindex(lua_State *L)
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

static int _olua_ullong___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_ullong *)olua_toobj(L, 1, "olua.ullong");
    olua_push_object(L, self, "olua.ullong");

    olua_endinvoke(L);

    return 1;
}

static int _olua_ullong_create$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // @postnew @name(new) static olua_ullong *create(@optional size_t len)
    olua_ullong *ret = olua_ullong::create(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ullong");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ullong_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @postnew @name(new) static olua_ullong *create(@optional size_t len)
    olua_ullong *ret = olua_ullong::create();
    int num_ret = olua_push_object(L, ret, "olua.ullong");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ullong_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @postnew @name(new) static olua_ullong *create(@optional size_t len)
        return _olua_ullong_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 1))) {
            // @postnew @name(new) static olua_ullong *create(@optional size_t len)
            return _olua_ullong_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_ullong::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ullong_setstring(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.ullong");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setstring(const char *data, size_t len)
    self->setstring(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ullong_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.ullong");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // olua_ullong *sub(size_t from, @optional size_t to)
    olua_ullong *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.ullong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ullong_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.ullong");
    olua_check_integer(L, 2, &arg1);

    // olua_ullong *sub(size_t from, @optional size_t to)
    olua_ullong *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ullong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ullong_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // olua_ullong *sub(size_t from, @optional size_t to)
            return _olua_ullong_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // olua_ullong *sub(size_t from, @optional size_t to)
            return _olua_ullong_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_ullong::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ullong_take(lua_State *L)
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

static int _olua_ullong_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.ullong");
    olua_check_integer(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_ullong_data(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ullong");

    // @getter @name(data) olua_ullong_t *data()
    olua_ullong_t *ret = self->data();
    int num_ret = olua_push_array(L, ret, "olua.ullong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ullong_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ullong");

    // @getter @name(length) size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ullong_rawdata(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ullong");

    // @getter @name(rawdata) void *rawdata()
    void *ret = self->rawdata();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ullong_size(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ullong");

    // @getter @name(sizeof) size_t size()
    size_t ret = self->size();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ullong_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ullong");

    // @getter @name(value) const olua_ullong_t &value()
    const olua_ullong_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_ullong(lua_State *L)
{
    oluacls_class<olua_ullong>(L, "olua.ullong");
    oluacls_func(L, "__gc", _olua_ullong___gc);
    oluacls_func(L, "__index", _olua_ullong___index);
    oluacls_func(L, "__newindex", _olua_ullong___newindex);
    oluacls_func(L, "__olua_move", _olua_ullong___olua_move);
    oluacls_func(L, "new", _olua_ullong_create);
    oluacls_func(L, "setstring", _olua_ullong_setstring);
    oluacls_func(L, "sub", _olua_ullong_sub);
    oluacls_func(L, "take", _olua_ullong_take);
    oluacls_func(L, "tostring", _olua_ullong_tostring);
    oluacls_prop(L, "data", _olua_ullong_data, nullptr);
    oluacls_prop(L, "length", _olua_ullong_length, _olua_ullong_length);
    oluacls_prop(L, "rawdata", _olua_ullong_rawdata, nullptr);
    oluacls_prop(L, "sizeof", _olua_ullong_size, nullptr);
    oluacls_prop(L, "value", _olua_ullong_value, _olua_ullong_value);

    return 1;
}
OLUA_END_DECLS

static int _olua_float___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;

    olua_to_object(L, 1, &self, "olua.float");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_float___index(lua_State *L)
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

static int _olua_float___newindex(lua_State *L)
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

static int _olua_float___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_float *)olua_toobj(L, 1, "olua.float");
    olua_push_object(L, self, "olua.float");

    olua_endinvoke(L);

    return 1;
}

static int _olua_float_create$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // @postnew @name(new) static olua_float *create(@optional size_t len)
    olua_float *ret = olua_float::create(arg1);
    int num_ret = olua_push_object(L, ret, "olua.float");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_float_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @postnew @name(new) static olua_float *create(@optional size_t len)
    olua_float *ret = olua_float::create();
    int num_ret = olua_push_object(L, ret, "olua.float");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_float_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @postnew @name(new) static olua_float *create(@optional size_t len)
        return _olua_float_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 1))) {
            // @postnew @name(new) static olua_float *create(@optional size_t len)
            return _olua_float_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_float::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_float_setstring(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.float");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setstring(const char *data, size_t len)
    self->setstring(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_float_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.float");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // olua_float *sub(size_t from, @optional size_t to)
    olua_float *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.float");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_float_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.float");
    olua_check_integer(L, 2, &arg1);

    // olua_float *sub(size_t from, @optional size_t to)
    olua_float *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.float");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_float_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // olua_float *sub(size_t from, @optional size_t to)
            return _olua_float_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // olua_float *sub(size_t from, @optional size_t to)
            return _olua_float_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_float::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_float_take(lua_State *L)
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

static int _olua_float_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.float");
    olua_check_integer(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_float_data(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;

    olua_to_object(L, 1, &self, "olua.float");

    // @getter @name(data) olua_float_t *data()
    olua_float_t *ret = self->data();
    int num_ret = olua_push_array(L, ret, "olua.float");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_float_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;

    olua_to_object(L, 1, &self, "olua.float");

    // @getter @name(length) size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_float_rawdata(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;

    olua_to_object(L, 1, &self, "olua.float");

    // @getter @name(rawdata) void *rawdata()
    void *ret = self->rawdata();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_float_size(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;

    olua_to_object(L, 1, &self, "olua.float");

    // @getter @name(sizeof) size_t size()
    size_t ret = self->size();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_float_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;

    olua_to_object(L, 1, &self, "olua.float");

    // @getter @name(value) const olua_float_t &value()
    const olua_float_t &ret = self->value();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_float(lua_State *L)
{
    oluacls_class<olua_float>(L, "olua.float");
    oluacls_func(L, "__gc", _olua_float___gc);
    oluacls_func(L, "__index", _olua_float___index);
    oluacls_func(L, "__newindex", _olua_float___newindex);
    oluacls_func(L, "__olua_move", _olua_float___olua_move);
    oluacls_func(L, "new", _olua_float_create);
    oluacls_func(L, "setstring", _olua_float_setstring);
    oluacls_func(L, "sub", _olua_float_sub);
    oluacls_func(L, "take", _olua_float_take);
    oluacls_func(L, "tostring", _olua_float_tostring);
    oluacls_prop(L, "data", _olua_float_data, nullptr);
    oluacls_prop(L, "length", _olua_float_length, _olua_float_length);
    oluacls_prop(L, "rawdata", _olua_float_rawdata, nullptr);
    oluacls_prop(L, "sizeof", _olua_float_size, nullptr);
    oluacls_prop(L, "value", _olua_float_value, _olua_float_value);

    return 1;
}
OLUA_END_DECLS

static int _olua_double___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;

    olua_to_object(L, 1, &self, "olua.double");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_double___index(lua_State *L)
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

static int _olua_double___newindex(lua_State *L)
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

static int _olua_double___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_double *)olua_toobj(L, 1, "olua.double");
    olua_push_object(L, self, "olua.double");

    olua_endinvoke(L);

    return 1;
}

static int _olua_double_create$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // @postnew @name(new) static olua_double *create(@optional size_t len)
    olua_double *ret = olua_double::create(arg1);
    int num_ret = olua_push_object(L, ret, "olua.double");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_double_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @postnew @name(new) static olua_double *create(@optional size_t len)
    olua_double *ret = olua_double::create();
    int num_ret = olua_push_object(L, ret, "olua.double");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_double_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @postnew @name(new) static olua_double *create(@optional size_t len)
        return _olua_double_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 1))) {
            // @postnew @name(new) static olua_double *create(@optional size_t len)
            return _olua_double_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_double::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_double_setstring(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.double");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setstring(const char *data, size_t len)
    self->setstring(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_double_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.double");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // olua_double *sub(size_t from, @optional size_t to)
    olua_double *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.double");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_double_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.double");
    olua_check_integer(L, 2, &arg1);

    // olua_double *sub(size_t from, @optional size_t to)
    olua_double *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.double");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_double_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // olua_double *sub(size_t from, @optional size_t to)
            return _olua_double_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // olua_double *sub(size_t from, @optional size_t to)
            return _olua_double_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_double::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_double_take(lua_State *L)
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

static int _olua_double_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.double");
    olua_check_integer(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_double_data(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;

    olua_to_object(L, 1, &self, "olua.double");

    // @getter @name(data) olua_double_t *data()
    olua_double_t *ret = self->data();
    int num_ret = olua_push_array(L, ret, "olua.double");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_double_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;

    olua_to_object(L, 1, &self, "olua.double");

    // @getter @name(length) size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_double_rawdata(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;

    olua_to_object(L, 1, &self, "olua.double");

    // @getter @name(rawdata) void *rawdata()
    void *ret = self->rawdata();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_double_size(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;

    olua_to_object(L, 1, &self, "olua.double");

    // @getter @name(sizeof) size_t size()
    size_t ret = self->size();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_double_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;

    olua_to_object(L, 1, &self, "olua.double");

    // @getter @name(value) const olua_double_t &value()
    const olua_double_t &ret = self->value();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_double(lua_State *L)
{
    oluacls_class<olua_double>(L, "olua.double");
    oluacls_func(L, "__gc", _olua_double___gc);
    oluacls_func(L, "__index", _olua_double___index);
    oluacls_func(L, "__newindex", _olua_double___newindex);
    oluacls_func(L, "__olua_move", _olua_double___olua_move);
    oluacls_func(L, "new", _olua_double_create);
    oluacls_func(L, "setstring", _olua_double_setstring);
    oluacls_func(L, "sub", _olua_double_sub);
    oluacls_func(L, "take", _olua_double_take);
    oluacls_func(L, "tostring", _olua_double_tostring);
    oluacls_prop(L, "data", _olua_double_data, nullptr);
    oluacls_prop(L, "length", _olua_double_length, _olua_double_length);
    oluacls_prop(L, "rawdata", _olua_double_rawdata, nullptr);
    oluacls_prop(L, "sizeof", _olua_double_size, nullptr);
    oluacls_prop(L, "value", _olua_double_value, _olua_double_value);

    return 1;
}
OLUA_END_DECLS

static int _olua_ldouble___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ldouble");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_ldouble___index(lua_State *L)
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

static int _olua_ldouble___newindex(lua_State *L)
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

static int _olua_ldouble___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_ldouble *)olua_toobj(L, 1, "olua.ldouble");
    olua_push_object(L, self, "olua.ldouble");

    olua_endinvoke(L);

    return 1;
}

static int _olua_ldouble_create$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // @postnew @name(new) static olua_ldouble *create(@optional size_t len)
    olua_ldouble *ret = olua_ldouble::create(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ldouble");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ldouble_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @postnew @name(new) static olua_ldouble *create(@optional size_t len)
    olua_ldouble *ret = olua_ldouble::create();
    int num_ret = olua_push_object(L, ret, "olua.ldouble");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ldouble_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @postnew @name(new) static olua_ldouble *create(@optional size_t len)
        return _olua_ldouble_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 1))) {
            // @postnew @name(new) static olua_ldouble *create(@optional size_t len)
            return _olua_ldouble_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_ldouble::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ldouble_setstring(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.ldouble");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setstring(const char *data, size_t len)
    self->setstring(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ldouble_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.ldouble");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // olua_ldouble *sub(size_t from, @optional size_t to)
    olua_ldouble *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.ldouble");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ldouble_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.ldouble");
    olua_check_integer(L, 2, &arg1);

    // olua_ldouble *sub(size_t from, @optional size_t to)
    olua_ldouble *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ldouble");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ldouble_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // olua_ldouble *sub(size_t from, @optional size_t to)
            return _olua_ldouble_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // olua_ldouble *sub(size_t from, @optional size_t to)
            return _olua_ldouble_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_ldouble::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ldouble_take(lua_State *L)
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

static int _olua_ldouble_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.ldouble");
    olua_check_integer(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_ldouble_data(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ldouble");

    // @getter @name(data) olua_ldouble_t *data()
    olua_ldouble_t *ret = self->data();
    int num_ret = olua_push_array(L, ret, "olua.ldouble");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ldouble_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ldouble");

    // @getter @name(length) size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ldouble_rawdata(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ldouble");

    // @getter @name(rawdata) void *rawdata()
    void *ret = self->rawdata();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ldouble_size(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ldouble");

    // @getter @name(sizeof) size_t size()
    size_t ret = self->size();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ldouble_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ldouble");

    // @getter @name(value) const olua_ldouble_t &value()
    const olua_ldouble_t &ret = self->value();
    int num_ret = olua_push_number(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_ldouble(lua_State *L)
{
    oluacls_class<olua_ldouble>(L, "olua.ldouble");
    oluacls_func(L, "__gc", _olua_ldouble___gc);
    oluacls_func(L, "__index", _olua_ldouble___index);
    oluacls_func(L, "__newindex", _olua_ldouble___newindex);
    oluacls_func(L, "__olua_move", _olua_ldouble___olua_move);
    oluacls_func(L, "new", _olua_ldouble_create);
    oluacls_func(L, "setstring", _olua_ldouble_setstring);
    oluacls_func(L, "sub", _olua_ldouble_sub);
    oluacls_func(L, "take", _olua_ldouble_take);
    oluacls_func(L, "tostring", _olua_ldouble_tostring);
    oluacls_prop(L, "data", _olua_ldouble_data, nullptr);
    oluacls_prop(L, "length", _olua_ldouble_length, _olua_ldouble_length);
    oluacls_prop(L, "rawdata", _olua_ldouble_rawdata, nullptr);
    oluacls_prop(L, "sizeof", _olua_ldouble_size, nullptr);
    oluacls_prop(L, "value", _olua_ldouble_value, _olua_ldouble_value);

    return 1;
}
OLUA_END_DECLS

static int _olua_size_t___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.size_t");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_size_t___index(lua_State *L)
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

static int _olua_size_t___newindex(lua_State *L)
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

static int _olua_size_t___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_size_t *)olua_toobj(L, 1, "olua.size_t");
    olua_push_object(L, self, "olua.size_t");

    olua_endinvoke(L);

    return 1;
}

static int _olua_size_t_create$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // @postnew @name(new) static olua_size_t *create(@optional size_t len)
    olua_size_t *ret = olua_size_t::create(arg1);
    int num_ret = olua_push_object(L, ret, "olua.size_t");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_size_t_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @postnew @name(new) static olua_size_t *create(@optional size_t len)
    olua_size_t *ret = olua_size_t::create();
    int num_ret = olua_push_object(L, ret, "olua.size_t");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_size_t_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @postnew @name(new) static olua_size_t *create(@optional size_t len)
        return _olua_size_t_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 1))) {
            // @postnew @name(new) static olua_size_t *create(@optional size_t len)
            return _olua_size_t_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_size_t::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_size_t_setstring(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.size_t");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setstring(const char *data, size_t len)
    self->setstring(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_size_t_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.size_t");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // olua_size_t *sub(size_t from, @optional size_t to)
    olua_size_t *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.size_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_size_t_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.size_t");
    olua_check_integer(L, 2, &arg1);

    // olua_size_t *sub(size_t from, @optional size_t to)
    olua_size_t *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.size_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_size_t_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // olua_size_t *sub(size_t from, @optional size_t to)
            return _olua_size_t_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // olua_size_t *sub(size_t from, @optional size_t to)
            return _olua_size_t_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_size_t::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_size_t_take(lua_State *L)
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

static int _olua_size_t_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.size_t");
    olua_check_integer(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_size_t_data(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.size_t");

    // @getter @name(data) size_t *data()
    size_t *ret = self->data();
    int num_ret = olua_push_array(L, ret, "olua.size_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_size_t_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.size_t");

    // @getter @name(length) size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_size_t_rawdata(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.size_t");

    // @getter @name(rawdata) void *rawdata()
    void *ret = self->rawdata();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_size_t_size(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.size_t");

    // @getter @name(sizeof) size_t size()
    size_t ret = self->size();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_size_t_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.size_t");

    // @getter @name(value) const size_t &value()
    const size_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_size_t(lua_State *L)
{
    oluacls_class<olua_size_t>(L, "olua.size_t");
    oluacls_func(L, "__gc", _olua_size_t___gc);
    oluacls_func(L, "__index", _olua_size_t___index);
    oluacls_func(L, "__newindex", _olua_size_t___newindex);
    oluacls_func(L, "__olua_move", _olua_size_t___olua_move);
    oluacls_func(L, "new", _olua_size_t_create);
    oluacls_func(L, "setstring", _olua_size_t_setstring);
    oluacls_func(L, "sub", _olua_size_t_sub);
    oluacls_func(L, "take", _olua_size_t_take);
    oluacls_func(L, "tostring", _olua_size_t_tostring);
    oluacls_prop(L, "data", _olua_size_t_data, nullptr);
    oluacls_prop(L, "length", _olua_size_t_length, _olua_size_t_length);
    oluacls_prop(L, "rawdata", _olua_size_t_rawdata, nullptr);
    oluacls_prop(L, "sizeof", _olua_size_t_size, nullptr);
    oluacls_prop(L, "value", _olua_size_t_value, _olua_size_t_value);

    return 1;
}
OLUA_END_DECLS

static int _olua_ssize_t___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ssize_t");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_ssize_t___index(lua_State *L)
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

static int _olua_ssize_t___newindex(lua_State *L)
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

static int _olua_ssize_t___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_ssize_t *)olua_toobj(L, 1, "olua.ssize_t");
    olua_push_object(L, self, "olua.ssize_t");

    olua_endinvoke(L);

    return 1;
}

static int _olua_ssize_t_create$1(lua_State *L)
{
    olua_startinvoke(L);

    size_t arg1 = 0;       /** len */

    olua_check_integer(L, 1, &arg1);

    // @postnew @name(new) static olua_ssize_t *create(@optional size_t len)
    olua_ssize_t *ret = olua_ssize_t::create(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ssize_t");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ssize_t_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @postnew @name(new) static olua_ssize_t *create(@optional size_t len)
    olua_ssize_t *ret = olua_ssize_t::create();
    int num_ret = olua_push_object(L, ret, "olua.ssize_t");

    // insert code after call
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ssize_t_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @postnew @name(new) static olua_ssize_t *create(@optional size_t len)
        return _olua_ssize_t_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_integer(L, 1))) {
            // @postnew @name(new) static olua_ssize_t *create(@optional size_t len)
            return _olua_ssize_t_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_ssize_t::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ssize_t_setstring(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.ssize_t");
    olua_check_string(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // void setstring(const char *data, size_t len)
    self->setstring(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ssize_t_sub$1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;
    size_t arg1 = 0;       /** from */
    size_t arg2 = 0;       /** to */

    olua_to_object(L, 1, &self, "olua.ssize_t");
    olua_check_integer(L, 2, &arg1);
    olua_check_integer(L, 3, &arg2);

    // olua_ssize_t *sub(size_t from, @optional size_t to)
    olua_ssize_t *ret = self->sub(arg1, arg2);
    int num_ret = olua_push_object(L, ret, "olua.ssize_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ssize_t_sub$2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;
    size_t arg1 = 0;       /** from */

    olua_to_object(L, 1, &self, "olua.ssize_t");
    olua_check_integer(L, 2, &arg1);

    // olua_ssize_t *sub(size_t from, @optional size_t to)
    olua_ssize_t *ret = self->sub(arg1);
    int num_ret = olua_push_object(L, ret, "olua.ssize_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ssize_t_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_integer(L, 2))) {
            // olua_ssize_t *sub(size_t from, @optional size_t to)
            return _olua_ssize_t_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_integer(L, 2)) && (olua_is_integer(L, 3))) {
            // olua_ssize_t *sub(size_t from, @optional size_t to)
            return _olua_ssize_t_sub$1(L);
        // }
    }

    luaL_error(L, "method 'olua_ssize_t::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ssize_t_take(lua_State *L)
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

static int _olua_ssize_t_tostring(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;
    size_t arg2 = 0;       /** len */

    olua_to_object(L, 1, &self, "olua.ssize_t");
    olua_check_integer(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, size_t len)
    olua_Return ret = self->tostring(L, arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_ssize_t_data(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ssize_t");

    // @getter @name(data) ssize_t *data()
    ssize_t *ret = self->data();
    int num_ret = olua_push_array(L, ret, "olua.ssize_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ssize_t_length(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ssize_t");

    // @getter @name(length) size_t length()
    size_t ret = self->length();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ssize_t_rawdata(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ssize_t");

    // @getter @name(rawdata) void *rawdata()
    void *ret = self->rawdata();
    int num_ret = olua_push_object(L, ret, "void *");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ssize_t_size(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ssize_t");

    // @getter @name(sizeof) size_t size()
    size_t ret = self->size();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ssize_t_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;

    olua_to_object(L, 1, &self, "olua.ssize_t");

    // @getter @name(value) const ssize_t &value()
    const ssize_t &ret = self->value();
    int num_ret = olua_push_integer(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_ssize_t(lua_State *L)
{
    oluacls_class<olua_ssize_t>(L, "olua.ssize_t");
    oluacls_func(L, "__gc", _olua_ssize_t___gc);
    oluacls_func(L, "__index", _olua_ssize_t___index);
    oluacls_func(L, "__newindex", _olua_ssize_t___newindex);
    oluacls_func(L, "__olua_move", _olua_ssize_t___olua_move);
    oluacls_func(L, "new", _olua_ssize_t_create);
    oluacls_func(L, "setstring", _olua_ssize_t_setstring);
    oluacls_func(L, "sub", _olua_ssize_t_sub);
    oluacls_func(L, "take", _olua_ssize_t_take);
    oluacls_func(L, "tostring", _olua_ssize_t_tostring);
    oluacls_prop(L, "data", _olua_ssize_t_data, nullptr);
    oluacls_prop(L, "length", _olua_ssize_t_length, _olua_ssize_t_length);
    oluacls_prop(L, "rawdata", _olua_ssize_t_rawdata, nullptr);
    oluacls_prop(L, "sizeof", _olua_ssize_t_size, nullptr);
    oluacls_prop(L, "value", _olua_ssize_t_value, _olua_ssize_t_value);

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_types(lua_State *L)
{
    olua_require(L, "olua.bool", luaopen_olua_bool);
    olua_require(L, "olua.string", luaopen_olua_string);
    olua_require(L, "olua.int8_t", luaopen_olua_int8_t);
    olua_require(L, "olua.int16_t", luaopen_olua_int16_t);
    olua_require(L, "olua.int32_t", luaopen_olua_int32_t);
    olua_require(L, "olua.int64_t", luaopen_olua_int64_t);
    olua_require(L, "olua.uint8_t", luaopen_olua_uint8_t);
    olua_require(L, "olua.uint16_t", luaopen_olua_uint16_t);
    olua_require(L, "olua.uint32_t", luaopen_olua_uint32_t);
    olua_require(L, "olua.uint64_t", luaopen_olua_uint64_t);
    olua_require(L, "olua.char", luaopen_olua_char);
    olua_require(L, "olua.short", luaopen_olua_short);
    olua_require(L, "olua.int", luaopen_olua_int);
    olua_require(L, "olua.long", luaopen_olua_long);
    olua_require(L, "olua.llong", luaopen_olua_llong);
    olua_require(L, "olua.uchar", luaopen_olua_uchar);
    olua_require(L, "olua.ushort", luaopen_olua_ushort);
    olua_require(L, "olua.uint", luaopen_olua_uint);
    olua_require(L, "olua.ulong", luaopen_olua_ulong);
    olua_require(L, "olua.ullong", luaopen_olua_ullong);
    olua_require(L, "olua.float", luaopen_olua_float);
    olua_require(L, "olua.double", luaopen_olua_double);
    olua_require(L, "olua.ldouble", luaopen_olua_ldouble);
    olua_require(L, "olua.size_t", luaopen_olua_size_t);
    olua_require(L, "olua.ssize_t", luaopen_olua_ssize_t);

    return 0;
}
OLUA_END_DECLS
