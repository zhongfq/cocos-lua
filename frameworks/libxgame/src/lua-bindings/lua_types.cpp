//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_types.h"
#include "cclua/olua-2dx.h"

static int _olua_bool___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.bool");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_bool___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */

    olua_to_obj(L, 1, &self, "olua.bool");
    olua_check_uint(L, 2, &arg1);

    // bool __index(unsigned int idx)
    bool ret = self->__index((unsigned int)arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_bool___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */
    bool arg2 = false;       /** v */

    olua_to_obj(L, 1, &self, "olua.bool");
    olua_check_uint(L, 2, &arg1);
    olua_check_bool(L, 3, &arg2);

    // void __newindex(unsigned int idx, const bool &v)
    self->__newindex((unsigned int)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_bool___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_bool *)olua_toobj(L, 1, "olua.bool");
    olua_push_obj(L, self, "olua.bool");

    olua_endinvoke(L);

    return 1;
}

static int _olua_bool_array(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // static olua::pointer<bool> *array(size_t len)
    olua::pointer<bool> *ret = olua_bool::array((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.bool");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_bool_copyfrom1(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;
    olua_bool *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */
    lua_Unsigned arg4 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.bool");
    olua_check_obj(L, 2, &arg1, "olua.bool");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void copyfrom(olua::pointer<bool> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<bool> *)arg1, (size_t)arg2, (size_t)arg3, (size_t)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_bool_copyfrom2(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;
    olua_bool *arg1 = nullptr;       /** obj */

    olua_to_obj(L, 1, &self, "olua.bool");
    olua_check_obj(L, 2, &arg1, "olua.bool");

    // void copyfrom(olua::pointer<bool> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<bool> *)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_bool_copyfrom3(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;
    olua_bool *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.bool");
    olua_check_obj(L, 2, &arg1, "olua.bool");
    olua_check_uint(L, 3, &arg2);

    // void copyfrom(olua::pointer<bool> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<bool> *)arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_bool_copyfrom4(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;
    olua_bool *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.bool");
    olua_check_obj(L, 2, &arg1, "olua.bool");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // void copyfrom(olua::pointer<bool> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<bool> *)arg1, (size_t)arg2, (size_t)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_bool_copyfrom(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_obj(L, 2, "olua.bool"))) {
            // void copyfrom(olua::pointer<bool> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_bool_copyfrom2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.bool")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<bool> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_bool_copyfrom3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.bool")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<bool> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_bool_copyfrom4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.bool")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<bool> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_bool_copyfrom1(L);
        // }
    }

    luaL_error(L, "method 'olua_bool::copyfrom' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_bool_fill(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.bool");
    olua_check_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void fill(const char *data, size_t len)
    self->fill(arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_bool_create(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** v */

    olua_check_bool(L, 1, &arg1);

    // @name(new) static olua::pointer<bool> *create(const bool &v)
    olua::pointer<bool> *ret = olua_bool::create(arg1);
    int num_ret = olua_push_obj(L, ret, "olua.bool");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_bool_sub1(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */
    lua_Unsigned arg2 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.bool");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // olua::pointer<bool> *sub(size_t from, @optional size_t to)
    olua::pointer<bool> *ret = self->sub((size_t)arg1, (size_t)arg2);
    int num_ret = olua_push_obj(L, ret, "olua.bool");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_bool_sub2(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.bool");
    olua_check_uint(L, 2, &arg1);

    // olua::pointer<bool> *sub(size_t from, @optional size_t to)
    olua::pointer<bool> *ret = self->sub((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.bool");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_bool_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua::pointer<bool> *sub(size_t from, @optional size_t to)
            return _olua_bool_sub2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<bool> *sub(size_t from, @optional size_t to)
            return _olua_bool_sub1(L);
        // }
    }

    luaL_error(L, "method 'olua_bool::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_bool_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.bool");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_bool_tostring1(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.bool");
    olua_check_uint(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L, (size_t)arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_bool_tostring2(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.bool");

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_bool_tostring(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // if () {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_bool_tostring2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_bool_tostring1(L);
        // }
    }

    luaL_error(L, "method 'olua_bool::tostring' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_bool_getLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.bool");

    // @getter @name(length) size_t getLength()
    size_t ret = self->getLength();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_bool_setLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;
    lua_Unsigned arg1 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.bool");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(length) void setLength(size_t len)
    self->setLength((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_bool_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.bool");

    // @getter const bool &value()
    const bool &ret = self->value();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_bool(lua_State *L)
{
    oluacls_class(L, "olua.bool", nullptr);
    oluacls_func(L, "__gc", _olua_bool___gc);
    oluacls_func(L, "__index", _olua_bool___index);
    oluacls_func(L, "__newindex", _olua_bool___newindex);
    oluacls_func(L, "__olua_move", _olua_bool___olua_move);
    oluacls_func(L, "array", _olua_bool_array);
    oluacls_func(L, "copyfrom", _olua_bool_copyfrom);
    oluacls_func(L, "fill", _olua_bool_fill);
    oluacls_func(L, "new", _olua_bool_create);
    oluacls_func(L, "sub", _olua_bool_sub);
    oluacls_func(L, "take", _olua_bool_take);
    oluacls_func(L, "tostring", _olua_bool_tostring);
    oluacls_prop(L, "length", _olua_bool_getLength, _olua_bool_setLength);
    oluacls_prop(L, "value", _olua_bool_value, nullptr);

    olua_registerluatype<olua_bool>(L, "olua.bool");

    return 1;
}
OLUA_END_DECLS

static int _olua_string___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.string");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_string___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */

    olua_to_obj(L, 1, &self, "olua.string");
    olua_check_uint(L, 2, &arg1);

    // std::string __index(unsigned int idx)
    std::string ret = self->__index((unsigned int)arg1);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_string___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */
    std::string arg2;       /** v */

    olua_to_obj(L, 1, &self, "olua.string");
    olua_check_uint(L, 2, &arg1);
    olua_check_std_string(L, 3, &arg2);

    // void __newindex(unsigned int idx, const std::string &v)
    self->__newindex((unsigned int)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_string___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_string *)olua_toobj(L, 1, "olua.string");
    olua_push_obj(L, self, "olua.string");

    olua_endinvoke(L);

    return 1;
}

static int _olua_string_array(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // static olua::pointer<std::string> *array(size_t len)
    olua::pointer<std::string> *ret = olua_string::array((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.string");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_string_copyfrom1(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;
    olua_string *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */
    lua_Unsigned arg4 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.string");
    olua_check_obj(L, 2, &arg1, "olua.string");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void copyfrom(olua::pointer<std::string> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<std::string> *)arg1, (size_t)arg2, (size_t)arg3, (size_t)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_string_copyfrom2(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;
    olua_string *arg1 = nullptr;       /** obj */

    olua_to_obj(L, 1, &self, "olua.string");
    olua_check_obj(L, 2, &arg1, "olua.string");

    // void copyfrom(olua::pointer<std::string> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<std::string> *)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_string_copyfrom3(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;
    olua_string *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.string");
    olua_check_obj(L, 2, &arg1, "olua.string");
    olua_check_uint(L, 3, &arg2);

    // void copyfrom(olua::pointer<std::string> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<std::string> *)arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_string_copyfrom4(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;
    olua_string *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.string");
    olua_check_obj(L, 2, &arg1, "olua.string");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // void copyfrom(olua::pointer<std::string> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<std::string> *)arg1, (size_t)arg2, (size_t)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_string_copyfrom(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_obj(L, 2, "olua.string"))) {
            // void copyfrom(olua::pointer<std::string> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_string_copyfrom2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.string")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<std::string> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_string_copyfrom3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.string")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<std::string> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_string_copyfrom4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.string")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<std::string> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_string_copyfrom1(L);
        // }
    }

    luaL_error(L, "method 'olua_string::copyfrom' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_string_fill(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.string");
    olua_check_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void fill(const char *data, size_t len)
    self->fill(arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_string_create(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** v */

    olua_check_std_string(L, 1, &arg1);

    // @name(new) static olua::pointer<std::string> *create(const std::string &v)
    olua::pointer<std::string> *ret = olua_string::create(arg1);
    int num_ret = olua_push_obj(L, ret, "olua.string");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_string_sub1(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */
    lua_Unsigned arg2 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.string");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // olua::pointer<std::string> *sub(size_t from, @optional size_t to)
    olua::pointer<std::string> *ret = self->sub((size_t)arg1, (size_t)arg2);
    int num_ret = olua_push_obj(L, ret, "olua.string");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_string_sub2(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.string");
    olua_check_uint(L, 2, &arg1);

    // olua::pointer<std::string> *sub(size_t from, @optional size_t to)
    olua::pointer<std::string> *ret = self->sub((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.string");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_string_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua::pointer<std::string> *sub(size_t from, @optional size_t to)
            return _olua_string_sub2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<std::string> *sub(size_t from, @optional size_t to)
            return _olua_string_sub1(L);
        // }
    }

    luaL_error(L, "method 'olua_string::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_string_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.string");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_string_tostring1(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.string");
    olua_check_uint(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L, (size_t)arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_string_tostring2(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.string");

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_string_tostring(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // if () {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_string_tostring2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_string_tostring1(L);
        // }
    }

    luaL_error(L, "method 'olua_string::tostring' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_string_getLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.string");

    // @getter @name(length) size_t getLength()
    size_t ret = self->getLength();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_string_setLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;
    lua_Unsigned arg1 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.string");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(length) void setLength(size_t len)
    self->setLength((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_string_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.string");

    // @getter const std::string &value()
    const std::string &ret = self->value();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_string(lua_State *L)
{
    oluacls_class(L, "olua.string", nullptr);
    oluacls_func(L, "__gc", _olua_string___gc);
    oluacls_func(L, "__index", _olua_string___index);
    oluacls_func(L, "__newindex", _olua_string___newindex);
    oluacls_func(L, "__olua_move", _olua_string___olua_move);
    oluacls_func(L, "array", _olua_string_array);
    oluacls_func(L, "copyfrom", _olua_string_copyfrom);
    oluacls_func(L, "fill", _olua_string_fill);
    oluacls_func(L, "new", _olua_string_create);
    oluacls_func(L, "sub", _olua_string_sub);
    oluacls_func(L, "take", _olua_string_take);
    oluacls_func(L, "tostring", _olua_string_tostring);
    oluacls_prop(L, "length", _olua_string_getLength, _olua_string_setLength);
    oluacls_prop(L, "value", _olua_string_value, nullptr);

    olua_registerluatype<olua_string>(L, "olua.string");

    return 1;
}
OLUA_END_DECLS

static int _olua_int8___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int8");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_int8___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */

    olua_to_obj(L, 1, &self, "olua.int8");
    olua_check_uint(L, 2, &arg1);

    // int8_t __index(unsigned int idx)
    int8_t ret = self->__index((unsigned int)arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int8___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */
    lua_Integer arg2 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.int8");
    olua_check_uint(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // void __newindex(unsigned int idx, const int8_t &v)
    self->__newindex((unsigned int)arg1, (int8_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int8___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_int8 *)olua_toobj(L, 1, "olua.int8");
    olua_push_obj(L, self, "olua.int8");

    olua_endinvoke(L);

    return 1;
}

static int _olua_int8_array(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // static olua::pointer<int8_t> *array(size_t len)
    olua::pointer<int8_t> *ret = olua_int8::array((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.int8");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int8_copyfrom1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;
    olua_int8 *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */
    lua_Unsigned arg4 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.int8");
    olua_check_obj(L, 2, &arg1, "olua.int8");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void copyfrom(olua::pointer<int8_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<int8_t> *)arg1, (size_t)arg2, (size_t)arg3, (size_t)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int8_copyfrom2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;
    olua_int8 *arg1 = nullptr;       /** obj */

    olua_to_obj(L, 1, &self, "olua.int8");
    olua_check_obj(L, 2, &arg1, "olua.int8");

    // void copyfrom(olua::pointer<int8_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<int8_t> *)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int8_copyfrom3(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;
    olua_int8 *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.int8");
    olua_check_obj(L, 2, &arg1, "olua.int8");
    olua_check_uint(L, 3, &arg2);

    // void copyfrom(olua::pointer<int8_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<int8_t> *)arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int8_copyfrom4(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;
    olua_int8 *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.int8");
    olua_check_obj(L, 2, &arg1, "olua.int8");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // void copyfrom(olua::pointer<int8_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<int8_t> *)arg1, (size_t)arg2, (size_t)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int8_copyfrom(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_obj(L, 2, "olua.int8"))) {
            // void copyfrom(olua::pointer<int8_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int8_copyfrom2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.int8")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<int8_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int8_copyfrom3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.int8")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<int8_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int8_copyfrom4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.int8")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<int8_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int8_copyfrom1(L);
        // }
    }

    luaL_error(L, "method 'olua_int8::copyfrom' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int8_fill(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.int8");
    olua_check_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void fill(const char *data, size_t len)
    self->fill(arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int8_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** v */

    olua_check_int(L, 1, &arg1);

    // @name(new) static olua::pointer<int8_t> *create(const int8_t &v)
    olua::pointer<int8_t> *ret = olua_int8::create((int8_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.int8");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int8_sub1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */
    lua_Unsigned arg2 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.int8");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // olua::pointer<int8_t> *sub(size_t from, @optional size_t to)
    olua::pointer<int8_t> *ret = self->sub((size_t)arg1, (size_t)arg2);
    int num_ret = olua_push_obj(L, ret, "olua.int8");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int8_sub2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.int8");
    olua_check_uint(L, 2, &arg1);

    // olua::pointer<int8_t> *sub(size_t from, @optional size_t to)
    olua::pointer<int8_t> *ret = self->sub((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.int8");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int8_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua::pointer<int8_t> *sub(size_t from, @optional size_t to)
            return _olua_int8_sub2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<int8_t> *sub(size_t from, @optional size_t to)
            return _olua_int8_sub1(L);
        // }
    }

    luaL_error(L, "method 'olua_int8::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int8_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int8");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_int8_tostring1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.int8");
    olua_check_uint(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L, (size_t)arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_int8_tostring2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int8");

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_int8_tostring(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // if () {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_int8_tostring2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_int8_tostring1(L);
        // }
    }

    luaL_error(L, "method 'olua_int8::tostring' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int8_getLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int8");

    // @getter @name(length) size_t getLength()
    size_t ret = self->getLength();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int8_setLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.int8");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(length) void setLength(size_t len)
    self->setLength((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int8_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int8");

    // @getter const int8_t &value()
    const int8_t &ret = self->value();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_int8(lua_State *L)
{
    oluacls_class(L, "olua.int8", nullptr);
    oluacls_func(L, "__gc", _olua_int8___gc);
    oluacls_func(L, "__index", _olua_int8___index);
    oluacls_func(L, "__newindex", _olua_int8___newindex);
    oluacls_func(L, "__olua_move", _olua_int8___olua_move);
    oluacls_func(L, "array", _olua_int8_array);
    oluacls_func(L, "copyfrom", _olua_int8_copyfrom);
    oluacls_func(L, "fill", _olua_int8_fill);
    oluacls_func(L, "new", _olua_int8_create);
    oluacls_func(L, "sub", _olua_int8_sub);
    oluacls_func(L, "take", _olua_int8_take);
    oluacls_func(L, "tostring", _olua_int8_tostring);
    oluacls_prop(L, "length", _olua_int8_getLength, _olua_int8_setLength);
    oluacls_prop(L, "value", _olua_int8_value, nullptr);

    olua_registerluatype<olua_int8>(L, "olua.int8");

    return 1;
}
OLUA_END_DECLS

static int _olua_uint8___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint8");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_uint8___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */

    olua_to_obj(L, 1, &self, "olua.uint8");
    olua_check_uint(L, 2, &arg1);

    // uint8_t __index(unsigned int idx)
    uint8_t ret = self->__index((unsigned int)arg1);
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint8___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */
    lua_Unsigned arg2 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.uint8");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void __newindex(unsigned int idx, const uint8_t &v)
    self->__newindex((unsigned int)arg1, (uint8_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint8___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_uint8 *)olua_toobj(L, 1, "olua.uint8");
    olua_push_obj(L, self, "olua.uint8");

    olua_endinvoke(L);

    return 1;
}

static int _olua_uint8_array(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // static olua::pointer<uint8_t> *array(size_t len)
    olua::pointer<uint8_t> *ret = olua_uint8::array((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.uint8");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint8_copyfrom1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;
    olua_uint8 *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */
    lua_Unsigned arg4 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.uint8");
    olua_check_obj(L, 2, &arg1, "olua.uint8");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void copyfrom(olua::pointer<uint8_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<uint8_t> *)arg1, (size_t)arg2, (size_t)arg3, (size_t)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint8_copyfrom2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;
    olua_uint8 *arg1 = nullptr;       /** obj */

    olua_to_obj(L, 1, &self, "olua.uint8");
    olua_check_obj(L, 2, &arg1, "olua.uint8");

    // void copyfrom(olua::pointer<uint8_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<uint8_t> *)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint8_copyfrom3(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;
    olua_uint8 *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.uint8");
    olua_check_obj(L, 2, &arg1, "olua.uint8");
    olua_check_uint(L, 3, &arg2);

    // void copyfrom(olua::pointer<uint8_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<uint8_t> *)arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint8_copyfrom4(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;
    olua_uint8 *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.uint8");
    olua_check_obj(L, 2, &arg1, "olua.uint8");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // void copyfrom(olua::pointer<uint8_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<uint8_t> *)arg1, (size_t)arg2, (size_t)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint8_copyfrom(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_obj(L, 2, "olua.uint8"))) {
            // void copyfrom(olua::pointer<uint8_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint8_copyfrom2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.uint8")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<uint8_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint8_copyfrom3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.uint8")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<uint8_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint8_copyfrom4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.uint8")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<uint8_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint8_copyfrom1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint8::copyfrom' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint8_fill(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.uint8");
    olua_check_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void fill(const char *data, size_t len)
    self->fill(arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint8_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** v */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<uint8_t> *create(const uint8_t &v)
    olua::pointer<uint8_t> *ret = olua_uint8::create((uint8_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.uint8");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint8_sub1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */
    lua_Unsigned arg2 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.uint8");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // olua::pointer<uint8_t> *sub(size_t from, @optional size_t to)
    olua::pointer<uint8_t> *ret = self->sub((size_t)arg1, (size_t)arg2);
    int num_ret = olua_push_obj(L, ret, "olua.uint8");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint8_sub2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.uint8");
    olua_check_uint(L, 2, &arg1);

    // olua::pointer<uint8_t> *sub(size_t from, @optional size_t to)
    olua::pointer<uint8_t> *ret = self->sub((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.uint8");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint8_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua::pointer<uint8_t> *sub(size_t from, @optional size_t to)
            return _olua_uint8_sub2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<uint8_t> *sub(size_t from, @optional size_t to)
            return _olua_uint8_sub1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint8::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint8_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint8");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint8_tostring1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.uint8");
    olua_check_uint(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L, (size_t)arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_uint8_tostring2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint8");

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_uint8_tostring(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // if () {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_uint8_tostring2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_uint8_tostring1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint8::tostring' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint8_getLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint8");

    // @getter @name(length) size_t getLength()
    size_t ret = self->getLength();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint8_setLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.uint8");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(length) void setLength(size_t len)
    self->setLength((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint8_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint8");

    // @getter const uint8_t &value()
    const uint8_t &ret = self->value();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_uint8(lua_State *L)
{
    oluacls_class(L, "olua.uint8", nullptr);
    oluacls_func(L, "__gc", _olua_uint8___gc);
    oluacls_func(L, "__index", _olua_uint8___index);
    oluacls_func(L, "__newindex", _olua_uint8___newindex);
    oluacls_func(L, "__olua_move", _olua_uint8___olua_move);
    oluacls_func(L, "array", _olua_uint8_array);
    oluacls_func(L, "copyfrom", _olua_uint8_copyfrom);
    oluacls_func(L, "fill", _olua_uint8_fill);
    oluacls_func(L, "new", _olua_uint8_create);
    oluacls_func(L, "sub", _olua_uint8_sub);
    oluacls_func(L, "take", _olua_uint8_take);
    oluacls_func(L, "tostring", _olua_uint8_tostring);
    oluacls_prop(L, "length", _olua_uint8_getLength, _olua_uint8_setLength);
    oluacls_prop(L, "value", _olua_uint8_value, nullptr);

    olua_registerluatype<olua_uint8>(L, "olua.uint8");

    return 1;
}
OLUA_END_DECLS

static int _olua_int16___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int16");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_int16___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */

    olua_to_obj(L, 1, &self, "olua.int16");
    olua_check_uint(L, 2, &arg1);

    // int16_t __index(unsigned int idx)
    int16_t ret = self->__index((unsigned int)arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int16___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */
    lua_Integer arg2 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.int16");
    olua_check_uint(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // void __newindex(unsigned int idx, const int16_t &v)
    self->__newindex((unsigned int)arg1, (int16_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int16___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_int16 *)olua_toobj(L, 1, "olua.int16");
    olua_push_obj(L, self, "olua.int16");

    olua_endinvoke(L);

    return 1;
}

static int _olua_int16_array(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // static olua::pointer<int16_t> *array(size_t len)
    olua::pointer<int16_t> *ret = olua_int16::array((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.int16");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int16_copyfrom1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;
    olua_int16 *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */
    lua_Unsigned arg4 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.int16");
    olua_check_obj(L, 2, &arg1, "olua.int16");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void copyfrom(olua::pointer<int16_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<int16_t> *)arg1, (size_t)arg2, (size_t)arg3, (size_t)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int16_copyfrom2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;
    olua_int16 *arg1 = nullptr;       /** obj */

    olua_to_obj(L, 1, &self, "olua.int16");
    olua_check_obj(L, 2, &arg1, "olua.int16");

    // void copyfrom(olua::pointer<int16_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<int16_t> *)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int16_copyfrom3(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;
    olua_int16 *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.int16");
    olua_check_obj(L, 2, &arg1, "olua.int16");
    olua_check_uint(L, 3, &arg2);

    // void copyfrom(olua::pointer<int16_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<int16_t> *)arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int16_copyfrom4(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;
    olua_int16 *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.int16");
    olua_check_obj(L, 2, &arg1, "olua.int16");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // void copyfrom(olua::pointer<int16_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<int16_t> *)arg1, (size_t)arg2, (size_t)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int16_copyfrom(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_obj(L, 2, "olua.int16"))) {
            // void copyfrom(olua::pointer<int16_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int16_copyfrom2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.int16")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<int16_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int16_copyfrom3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.int16")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<int16_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int16_copyfrom4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.int16")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<int16_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int16_copyfrom1(L);
        // }
    }

    luaL_error(L, "method 'olua_int16::copyfrom' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int16_fill(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.int16");
    olua_check_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void fill(const char *data, size_t len)
    self->fill(arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int16_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** v */

    olua_check_int(L, 1, &arg1);

    // @name(new) static olua::pointer<int16_t> *create(const int16_t &v)
    olua::pointer<int16_t> *ret = olua_int16::create((int16_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.int16");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int16_sub1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */
    lua_Unsigned arg2 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.int16");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // olua::pointer<int16_t> *sub(size_t from, @optional size_t to)
    olua::pointer<int16_t> *ret = self->sub((size_t)arg1, (size_t)arg2);
    int num_ret = olua_push_obj(L, ret, "olua.int16");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int16_sub2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.int16");
    olua_check_uint(L, 2, &arg1);

    // olua::pointer<int16_t> *sub(size_t from, @optional size_t to)
    olua::pointer<int16_t> *ret = self->sub((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.int16");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int16_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua::pointer<int16_t> *sub(size_t from, @optional size_t to)
            return _olua_int16_sub2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<int16_t> *sub(size_t from, @optional size_t to)
            return _olua_int16_sub1(L);
        // }
    }

    luaL_error(L, "method 'olua_int16::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int16_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int16");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_int16_tostring1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.int16");
    olua_check_uint(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L, (size_t)arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_int16_tostring2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int16");

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_int16_tostring(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // if () {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_int16_tostring2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_int16_tostring1(L);
        // }
    }

    luaL_error(L, "method 'olua_int16::tostring' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int16_getLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int16");

    // @getter @name(length) size_t getLength()
    size_t ret = self->getLength();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int16_setLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.int16");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(length) void setLength(size_t len)
    self->setLength((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int16_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int16");

    // @getter const int16_t &value()
    const int16_t &ret = self->value();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_int16(lua_State *L)
{
    oluacls_class(L, "olua.int16", nullptr);
    oluacls_func(L, "__gc", _olua_int16___gc);
    oluacls_func(L, "__index", _olua_int16___index);
    oluacls_func(L, "__newindex", _olua_int16___newindex);
    oluacls_func(L, "__olua_move", _olua_int16___olua_move);
    oluacls_func(L, "array", _olua_int16_array);
    oluacls_func(L, "copyfrom", _olua_int16_copyfrom);
    oluacls_func(L, "fill", _olua_int16_fill);
    oluacls_func(L, "new", _olua_int16_create);
    oluacls_func(L, "sub", _olua_int16_sub);
    oluacls_func(L, "take", _olua_int16_take);
    oluacls_func(L, "tostring", _olua_int16_tostring);
    oluacls_prop(L, "length", _olua_int16_getLength, _olua_int16_setLength);
    oluacls_prop(L, "value", _olua_int16_value, nullptr);

    olua_registerluatype<olua_int16>(L, "olua.int16");

    return 1;
}
OLUA_END_DECLS

static int _olua_uint16___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint16");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_uint16___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */

    olua_to_obj(L, 1, &self, "olua.uint16");
    olua_check_uint(L, 2, &arg1);

    // uint16_t __index(unsigned int idx)
    uint16_t ret = self->__index((unsigned int)arg1);
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint16___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */
    lua_Unsigned arg2 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.uint16");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void __newindex(unsigned int idx, const uint16_t &v)
    self->__newindex((unsigned int)arg1, (uint16_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint16___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_uint16 *)olua_toobj(L, 1, "olua.uint16");
    olua_push_obj(L, self, "olua.uint16");

    olua_endinvoke(L);

    return 1;
}

static int _olua_uint16_array(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // static olua::pointer<uint16_t> *array(size_t len)
    olua::pointer<uint16_t> *ret = olua_uint16::array((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.uint16");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint16_copyfrom1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;
    olua_uint16 *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */
    lua_Unsigned arg4 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.uint16");
    olua_check_obj(L, 2, &arg1, "olua.uint16");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void copyfrom(olua::pointer<uint16_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<uint16_t> *)arg1, (size_t)arg2, (size_t)arg3, (size_t)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint16_copyfrom2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;
    olua_uint16 *arg1 = nullptr;       /** obj */

    olua_to_obj(L, 1, &self, "olua.uint16");
    olua_check_obj(L, 2, &arg1, "olua.uint16");

    // void copyfrom(olua::pointer<uint16_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<uint16_t> *)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint16_copyfrom3(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;
    olua_uint16 *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.uint16");
    olua_check_obj(L, 2, &arg1, "olua.uint16");
    olua_check_uint(L, 3, &arg2);

    // void copyfrom(olua::pointer<uint16_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<uint16_t> *)arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint16_copyfrom4(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;
    olua_uint16 *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.uint16");
    olua_check_obj(L, 2, &arg1, "olua.uint16");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // void copyfrom(olua::pointer<uint16_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<uint16_t> *)arg1, (size_t)arg2, (size_t)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint16_copyfrom(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_obj(L, 2, "olua.uint16"))) {
            // void copyfrom(olua::pointer<uint16_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint16_copyfrom2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.uint16")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<uint16_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint16_copyfrom3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.uint16")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<uint16_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint16_copyfrom4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.uint16")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<uint16_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint16_copyfrom1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint16::copyfrom' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint16_fill(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.uint16");
    olua_check_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void fill(const char *data, size_t len)
    self->fill(arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint16_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** v */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<uint16_t> *create(const uint16_t &v)
    olua::pointer<uint16_t> *ret = olua_uint16::create((uint16_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.uint16");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint16_sub1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */
    lua_Unsigned arg2 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.uint16");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // olua::pointer<uint16_t> *sub(size_t from, @optional size_t to)
    olua::pointer<uint16_t> *ret = self->sub((size_t)arg1, (size_t)arg2);
    int num_ret = olua_push_obj(L, ret, "olua.uint16");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint16_sub2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.uint16");
    olua_check_uint(L, 2, &arg1);

    // olua::pointer<uint16_t> *sub(size_t from, @optional size_t to)
    olua::pointer<uint16_t> *ret = self->sub((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.uint16");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint16_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua::pointer<uint16_t> *sub(size_t from, @optional size_t to)
            return _olua_uint16_sub2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<uint16_t> *sub(size_t from, @optional size_t to)
            return _olua_uint16_sub1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint16::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint16_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint16");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint16_tostring1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.uint16");
    olua_check_uint(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L, (size_t)arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_uint16_tostring2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint16");

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_uint16_tostring(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // if () {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_uint16_tostring2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_uint16_tostring1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint16::tostring' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint16_getLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint16");

    // @getter @name(length) size_t getLength()
    size_t ret = self->getLength();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint16_setLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.uint16");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(length) void setLength(size_t len)
    self->setLength((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint16_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint16");

    // @getter const uint16_t &value()
    const uint16_t &ret = self->value();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_uint16(lua_State *L)
{
    oluacls_class(L, "olua.uint16", nullptr);
    oluacls_func(L, "__gc", _olua_uint16___gc);
    oluacls_func(L, "__index", _olua_uint16___index);
    oluacls_func(L, "__newindex", _olua_uint16___newindex);
    oluacls_func(L, "__olua_move", _olua_uint16___olua_move);
    oluacls_func(L, "array", _olua_uint16_array);
    oluacls_func(L, "copyfrom", _olua_uint16_copyfrom);
    oluacls_func(L, "fill", _olua_uint16_fill);
    oluacls_func(L, "new", _olua_uint16_create);
    oluacls_func(L, "sub", _olua_uint16_sub);
    oluacls_func(L, "take", _olua_uint16_take);
    oluacls_func(L, "tostring", _olua_uint16_tostring);
    oluacls_prop(L, "length", _olua_uint16_getLength, _olua_uint16_setLength);
    oluacls_prop(L, "value", _olua_uint16_value, nullptr);

    olua_registerluatype<olua_uint16>(L, "olua.uint16");

    return 1;
}
OLUA_END_DECLS

static int _olua_int32___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int32");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_int32___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */

    olua_to_obj(L, 1, &self, "olua.int32");
    olua_check_uint(L, 2, &arg1);

    // int32_t __index(unsigned int idx)
    int32_t ret = self->__index((unsigned int)arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int32___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */
    lua_Integer arg2 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.int32");
    olua_check_uint(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // void __newindex(unsigned int idx, const int32_t &v)
    self->__newindex((unsigned int)arg1, (int32_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int32___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_int32 *)olua_toobj(L, 1, "olua.int32");
    olua_push_obj(L, self, "olua.int32");

    olua_endinvoke(L);

    return 1;
}

static int _olua_int32_array(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // static olua::pointer<int32_t> *array(size_t len)
    olua::pointer<int32_t> *ret = olua_int32::array((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.int32");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int32_copyfrom1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;
    olua_int32 *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */
    lua_Unsigned arg4 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.int32");
    olua_check_obj(L, 2, &arg1, "olua.int32");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void copyfrom(olua::pointer<int32_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<int32_t> *)arg1, (size_t)arg2, (size_t)arg3, (size_t)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int32_copyfrom2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;
    olua_int32 *arg1 = nullptr;       /** obj */

    olua_to_obj(L, 1, &self, "olua.int32");
    olua_check_obj(L, 2, &arg1, "olua.int32");

    // void copyfrom(olua::pointer<int32_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<int32_t> *)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int32_copyfrom3(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;
    olua_int32 *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.int32");
    olua_check_obj(L, 2, &arg1, "olua.int32");
    olua_check_uint(L, 3, &arg2);

    // void copyfrom(olua::pointer<int32_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<int32_t> *)arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int32_copyfrom4(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;
    olua_int32 *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.int32");
    olua_check_obj(L, 2, &arg1, "olua.int32");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // void copyfrom(olua::pointer<int32_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<int32_t> *)arg1, (size_t)arg2, (size_t)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int32_copyfrom(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_obj(L, 2, "olua.int32"))) {
            // void copyfrom(olua::pointer<int32_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int32_copyfrom2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.int32")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<int32_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int32_copyfrom3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.int32")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<int32_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int32_copyfrom4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.int32")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<int32_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int32_copyfrom1(L);
        // }
    }

    luaL_error(L, "method 'olua_int32::copyfrom' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int32_fill(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.int32");
    olua_check_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void fill(const char *data, size_t len)
    self->fill(arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int32_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** v */

    olua_check_int(L, 1, &arg1);

    // @name(new) static olua::pointer<int32_t> *create(const int32_t &v)
    olua::pointer<int32_t> *ret = olua_int32::create((int32_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.int32");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int32_sub1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */
    lua_Unsigned arg2 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.int32");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // olua::pointer<int32_t> *sub(size_t from, @optional size_t to)
    olua::pointer<int32_t> *ret = self->sub((size_t)arg1, (size_t)arg2);
    int num_ret = olua_push_obj(L, ret, "olua.int32");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int32_sub2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.int32");
    olua_check_uint(L, 2, &arg1);

    // olua::pointer<int32_t> *sub(size_t from, @optional size_t to)
    olua::pointer<int32_t> *ret = self->sub((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.int32");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int32_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua::pointer<int32_t> *sub(size_t from, @optional size_t to)
            return _olua_int32_sub2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<int32_t> *sub(size_t from, @optional size_t to)
            return _olua_int32_sub1(L);
        // }
    }

    luaL_error(L, "method 'olua_int32::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int32_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int32");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_int32_tostring1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.int32");
    olua_check_uint(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L, (size_t)arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_int32_tostring2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int32");

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_int32_tostring(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // if () {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_int32_tostring2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_int32_tostring1(L);
        // }
    }

    luaL_error(L, "method 'olua_int32::tostring' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int32_getLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int32");

    // @getter @name(length) size_t getLength()
    size_t ret = self->getLength();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int32_setLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.int32");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(length) void setLength(size_t len)
    self->setLength((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int32_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int32");

    // @getter const int32_t &value()
    const int32_t &ret = self->value();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_int32(lua_State *L)
{
    oluacls_class(L, "olua.int32", nullptr);
    oluacls_func(L, "__gc", _olua_int32___gc);
    oluacls_func(L, "__index", _olua_int32___index);
    oluacls_func(L, "__newindex", _olua_int32___newindex);
    oluacls_func(L, "__olua_move", _olua_int32___olua_move);
    oluacls_func(L, "array", _olua_int32_array);
    oluacls_func(L, "copyfrom", _olua_int32_copyfrom);
    oluacls_func(L, "fill", _olua_int32_fill);
    oluacls_func(L, "new", _olua_int32_create);
    oluacls_func(L, "sub", _olua_int32_sub);
    oluacls_func(L, "take", _olua_int32_take);
    oluacls_func(L, "tostring", _olua_int32_tostring);
    oluacls_prop(L, "length", _olua_int32_getLength, _olua_int32_setLength);
    oluacls_prop(L, "value", _olua_int32_value, nullptr);

    olua_registerluatype<olua_int32>(L, "olua.int32");

    return 1;
}
OLUA_END_DECLS

static int _olua_uint32___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint32");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_uint32___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */

    olua_to_obj(L, 1, &self, "olua.uint32");
    olua_check_uint(L, 2, &arg1);

    // uint32_t __index(unsigned int idx)
    uint32_t ret = self->__index((unsigned int)arg1);
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint32___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */
    lua_Unsigned arg2 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.uint32");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void __newindex(unsigned int idx, const uint32_t &v)
    self->__newindex((unsigned int)arg1, (uint32_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint32___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_uint32 *)olua_toobj(L, 1, "olua.uint32");
    olua_push_obj(L, self, "olua.uint32");

    olua_endinvoke(L);

    return 1;
}

static int _olua_uint32_array(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // static olua::pointer<uint32_t> *array(size_t len)
    olua::pointer<uint32_t> *ret = olua_uint32::array((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.uint32");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint32_copyfrom1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;
    olua_uint32 *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */
    lua_Unsigned arg4 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.uint32");
    olua_check_obj(L, 2, &arg1, "olua.uint32");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void copyfrom(olua::pointer<uint32_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<uint32_t> *)arg1, (size_t)arg2, (size_t)arg3, (size_t)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint32_copyfrom2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;
    olua_uint32 *arg1 = nullptr;       /** obj */

    olua_to_obj(L, 1, &self, "olua.uint32");
    olua_check_obj(L, 2, &arg1, "olua.uint32");

    // void copyfrom(olua::pointer<uint32_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<uint32_t> *)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint32_copyfrom3(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;
    olua_uint32 *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.uint32");
    olua_check_obj(L, 2, &arg1, "olua.uint32");
    olua_check_uint(L, 3, &arg2);

    // void copyfrom(olua::pointer<uint32_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<uint32_t> *)arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint32_copyfrom4(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;
    olua_uint32 *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.uint32");
    olua_check_obj(L, 2, &arg1, "olua.uint32");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // void copyfrom(olua::pointer<uint32_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<uint32_t> *)arg1, (size_t)arg2, (size_t)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint32_copyfrom(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_obj(L, 2, "olua.uint32"))) {
            // void copyfrom(olua::pointer<uint32_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint32_copyfrom2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.uint32")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<uint32_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint32_copyfrom3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.uint32")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<uint32_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint32_copyfrom4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.uint32")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<uint32_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint32_copyfrom1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint32::copyfrom' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint32_fill(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.uint32");
    olua_check_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void fill(const char *data, size_t len)
    self->fill(arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint32_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** v */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<uint32_t> *create(const uint32_t &v)
    olua::pointer<uint32_t> *ret = olua_uint32::create((uint32_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.uint32");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint32_sub1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */
    lua_Unsigned arg2 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.uint32");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // olua::pointer<uint32_t> *sub(size_t from, @optional size_t to)
    olua::pointer<uint32_t> *ret = self->sub((size_t)arg1, (size_t)arg2);
    int num_ret = olua_push_obj(L, ret, "olua.uint32");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint32_sub2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.uint32");
    olua_check_uint(L, 2, &arg1);

    // olua::pointer<uint32_t> *sub(size_t from, @optional size_t to)
    olua::pointer<uint32_t> *ret = self->sub((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.uint32");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint32_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua::pointer<uint32_t> *sub(size_t from, @optional size_t to)
            return _olua_uint32_sub2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<uint32_t> *sub(size_t from, @optional size_t to)
            return _olua_uint32_sub1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint32::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint32_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint32");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint32_tostring1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.uint32");
    olua_check_uint(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L, (size_t)arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_uint32_tostring2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint32");

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_uint32_tostring(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // if () {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_uint32_tostring2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_uint32_tostring1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint32::tostring' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint32_getLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint32");

    // @getter @name(length) size_t getLength()
    size_t ret = self->getLength();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint32_setLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.uint32");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(length) void setLength(size_t len)
    self->setLength((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint32_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint32");

    // @getter const uint32_t &value()
    const uint32_t &ret = self->value();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_uint32(lua_State *L)
{
    oluacls_class(L, "olua.uint32", nullptr);
    oluacls_func(L, "__gc", _olua_uint32___gc);
    oluacls_func(L, "__index", _olua_uint32___index);
    oluacls_func(L, "__newindex", _olua_uint32___newindex);
    oluacls_func(L, "__olua_move", _olua_uint32___olua_move);
    oluacls_func(L, "array", _olua_uint32_array);
    oluacls_func(L, "copyfrom", _olua_uint32_copyfrom);
    oluacls_func(L, "fill", _olua_uint32_fill);
    oluacls_func(L, "new", _olua_uint32_create);
    oluacls_func(L, "sub", _olua_uint32_sub);
    oluacls_func(L, "take", _olua_uint32_take);
    oluacls_func(L, "tostring", _olua_uint32_tostring);
    oluacls_prop(L, "length", _olua_uint32_getLength, _olua_uint32_setLength);
    oluacls_prop(L, "value", _olua_uint32_value, nullptr);

    olua_registerluatype<olua_uint32>(L, "olua.uint32");

    return 1;
}
OLUA_END_DECLS

static int _olua_int64___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int64");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_int64___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */

    olua_to_obj(L, 1, &self, "olua.int64");
    olua_check_uint(L, 2, &arg1);

    // int64_t __index(unsigned int idx)
    int64_t ret = self->__index((unsigned int)arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int64___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */
    lua_Integer arg2 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.int64");
    olua_check_uint(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // void __newindex(unsigned int idx, const int64_t &v)
    self->__newindex((unsigned int)arg1, (int64_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int64___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_int64 *)olua_toobj(L, 1, "olua.int64");
    olua_push_obj(L, self, "olua.int64");

    olua_endinvoke(L);

    return 1;
}

static int _olua_int64_array(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // static olua::pointer<int64_t> *array(size_t len)
    olua::pointer<int64_t> *ret = olua_int64::array((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.int64");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int64_copyfrom1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;
    olua_int64 *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */
    lua_Unsigned arg4 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.int64");
    olua_check_obj(L, 2, &arg1, "olua.int64");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void copyfrom(olua::pointer<int64_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<int64_t> *)arg1, (size_t)arg2, (size_t)arg3, (size_t)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int64_copyfrom2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;
    olua_int64 *arg1 = nullptr;       /** obj */

    olua_to_obj(L, 1, &self, "olua.int64");
    olua_check_obj(L, 2, &arg1, "olua.int64");

    // void copyfrom(olua::pointer<int64_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<int64_t> *)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int64_copyfrom3(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;
    olua_int64 *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.int64");
    olua_check_obj(L, 2, &arg1, "olua.int64");
    olua_check_uint(L, 3, &arg2);

    // void copyfrom(olua::pointer<int64_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<int64_t> *)arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int64_copyfrom4(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;
    olua_int64 *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.int64");
    olua_check_obj(L, 2, &arg1, "olua.int64");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // void copyfrom(olua::pointer<int64_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<int64_t> *)arg1, (size_t)arg2, (size_t)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int64_copyfrom(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_obj(L, 2, "olua.int64"))) {
            // void copyfrom(olua::pointer<int64_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int64_copyfrom2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.int64")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<int64_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int64_copyfrom3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.int64")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<int64_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int64_copyfrom4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.int64")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<int64_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int64_copyfrom1(L);
        // }
    }

    luaL_error(L, "method 'olua_int64::copyfrom' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int64_fill(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.int64");
    olua_check_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void fill(const char *data, size_t len)
    self->fill(arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int64_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** v */

    olua_check_int(L, 1, &arg1);

    // @name(new) static olua::pointer<int64_t> *create(const int64_t &v)
    olua::pointer<int64_t> *ret = olua_int64::create((int64_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.int64");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int64_sub1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */
    lua_Unsigned arg2 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.int64");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // olua::pointer<int64_t> *sub(size_t from, @optional size_t to)
    olua::pointer<int64_t> *ret = self->sub((size_t)arg1, (size_t)arg2);
    int num_ret = olua_push_obj(L, ret, "olua.int64");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int64_sub2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.int64");
    olua_check_uint(L, 2, &arg1);

    // olua::pointer<int64_t> *sub(size_t from, @optional size_t to)
    olua::pointer<int64_t> *ret = self->sub((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.int64");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int64_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua::pointer<int64_t> *sub(size_t from, @optional size_t to)
            return _olua_int64_sub2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<int64_t> *sub(size_t from, @optional size_t to)
            return _olua_int64_sub1(L);
        // }
    }

    luaL_error(L, "method 'olua_int64::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int64_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int64");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_int64_tostring1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.int64");
    olua_check_uint(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L, (size_t)arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_int64_tostring2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int64");

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_int64_tostring(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // if () {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_int64_tostring2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_int64_tostring1(L);
        // }
    }

    luaL_error(L, "method 'olua_int64::tostring' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int64_getLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int64");

    // @getter @name(length) size_t getLength()
    size_t ret = self->getLength();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int64_setLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.int64");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(length) void setLength(size_t len)
    self->setLength((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int64_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int64");

    // @getter const int64_t &value()
    const int64_t &ret = self->value();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_int64(lua_State *L)
{
    oluacls_class(L, "olua.int64", nullptr);
    oluacls_func(L, "__gc", _olua_int64___gc);
    oluacls_func(L, "__index", _olua_int64___index);
    oluacls_func(L, "__newindex", _olua_int64___newindex);
    oluacls_func(L, "__olua_move", _olua_int64___olua_move);
    oluacls_func(L, "array", _olua_int64_array);
    oluacls_func(L, "copyfrom", _olua_int64_copyfrom);
    oluacls_func(L, "fill", _olua_int64_fill);
    oluacls_func(L, "new", _olua_int64_create);
    oluacls_func(L, "sub", _olua_int64_sub);
    oluacls_func(L, "take", _olua_int64_take);
    oluacls_func(L, "tostring", _olua_int64_tostring);
    oluacls_prop(L, "length", _olua_int64_getLength, _olua_int64_setLength);
    oluacls_prop(L, "value", _olua_int64_value, nullptr);

    olua_registerluatype<olua_int64>(L, "olua.int64");

    return 1;
}
OLUA_END_DECLS

static int _olua_uint64___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint64");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_uint64___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */

    olua_to_obj(L, 1, &self, "olua.uint64");
    olua_check_uint(L, 2, &arg1);

    // uint64_t __index(unsigned int idx)
    uint64_t ret = self->__index((unsigned int)arg1);
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint64___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */
    lua_Unsigned arg2 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.uint64");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void __newindex(unsigned int idx, const uint64_t &v)
    self->__newindex((unsigned int)arg1, (uint64_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint64___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_uint64 *)olua_toobj(L, 1, "olua.uint64");
    olua_push_obj(L, self, "olua.uint64");

    olua_endinvoke(L);

    return 1;
}

static int _olua_uint64_array(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // static olua::pointer<uint64_t> *array(size_t len)
    olua::pointer<uint64_t> *ret = olua_uint64::array((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.uint64");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint64_copyfrom1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;
    olua_uint64 *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */
    lua_Unsigned arg4 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.uint64");
    olua_check_obj(L, 2, &arg1, "olua.uint64");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void copyfrom(olua::pointer<uint64_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<uint64_t> *)arg1, (size_t)arg2, (size_t)arg3, (size_t)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint64_copyfrom2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;
    olua_uint64 *arg1 = nullptr;       /** obj */

    olua_to_obj(L, 1, &self, "olua.uint64");
    olua_check_obj(L, 2, &arg1, "olua.uint64");

    // void copyfrom(olua::pointer<uint64_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<uint64_t> *)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint64_copyfrom3(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;
    olua_uint64 *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.uint64");
    olua_check_obj(L, 2, &arg1, "olua.uint64");
    olua_check_uint(L, 3, &arg2);

    // void copyfrom(olua::pointer<uint64_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<uint64_t> *)arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint64_copyfrom4(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;
    olua_uint64 *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.uint64");
    olua_check_obj(L, 2, &arg1, "olua.uint64");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // void copyfrom(olua::pointer<uint64_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<uint64_t> *)arg1, (size_t)arg2, (size_t)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint64_copyfrom(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_obj(L, 2, "olua.uint64"))) {
            // void copyfrom(olua::pointer<uint64_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint64_copyfrom2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.uint64")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<uint64_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint64_copyfrom3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.uint64")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<uint64_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint64_copyfrom4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.uint64")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<uint64_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint64_copyfrom1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint64::copyfrom' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint64_fill(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.uint64");
    olua_check_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void fill(const char *data, size_t len)
    self->fill(arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint64_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** v */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<uint64_t> *create(const uint64_t &v)
    olua::pointer<uint64_t> *ret = olua_uint64::create((uint64_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.uint64");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint64_sub1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */
    lua_Unsigned arg2 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.uint64");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // olua::pointer<uint64_t> *sub(size_t from, @optional size_t to)
    olua::pointer<uint64_t> *ret = self->sub((size_t)arg1, (size_t)arg2);
    int num_ret = olua_push_obj(L, ret, "olua.uint64");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint64_sub2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.uint64");
    olua_check_uint(L, 2, &arg1);

    // olua::pointer<uint64_t> *sub(size_t from, @optional size_t to)
    olua::pointer<uint64_t> *ret = self->sub((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.uint64");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint64_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua::pointer<uint64_t> *sub(size_t from, @optional size_t to)
            return _olua_uint64_sub2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<uint64_t> *sub(size_t from, @optional size_t to)
            return _olua_uint64_sub1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint64::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint64_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint64");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint64_tostring1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.uint64");
    olua_check_uint(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L, (size_t)arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_uint64_tostring2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint64");

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_uint64_tostring(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // if () {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_uint64_tostring2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_uint64_tostring1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint64::tostring' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint64_getLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint64");

    // @getter @name(length) size_t getLength()
    size_t ret = self->getLength();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint64_setLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.uint64");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(length) void setLength(size_t len)
    self->setLength((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint64_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint64");

    // @getter const uint64_t &value()
    const uint64_t &ret = self->value();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_uint64(lua_State *L)
{
    oluacls_class(L, "olua.uint64", nullptr);
    oluacls_func(L, "__gc", _olua_uint64___gc);
    oluacls_func(L, "__index", _olua_uint64___index);
    oluacls_func(L, "__newindex", _olua_uint64___newindex);
    oluacls_func(L, "__olua_move", _olua_uint64___olua_move);
    oluacls_func(L, "array", _olua_uint64_array);
    oluacls_func(L, "copyfrom", _olua_uint64_copyfrom);
    oluacls_func(L, "fill", _olua_uint64_fill);
    oluacls_func(L, "new", _olua_uint64_create);
    oluacls_func(L, "sub", _olua_uint64_sub);
    oluacls_func(L, "take", _olua_uint64_take);
    oluacls_func(L, "tostring", _olua_uint64_tostring);
    oluacls_prop(L, "length", _olua_uint64_getLength, _olua_uint64_setLength);
    oluacls_prop(L, "value", _olua_uint64_value, nullptr);

    olua_registerluatype<olua_uint64>(L, "olua.uint64");

    return 1;
}
OLUA_END_DECLS

static int _olua_short___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.short");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_short___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */

    olua_to_obj(L, 1, &self, "olua.short");
    olua_check_uint(L, 2, &arg1);

    // short __index(unsigned int idx)
    short ret = self->__index((unsigned int)arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_short___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */
    lua_Integer arg2 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.short");
    olua_check_uint(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // void __newindex(unsigned int idx, const short &v)
    self->__newindex((unsigned int)arg1, (short)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_short___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_short *)olua_toobj(L, 1, "olua.short");
    olua_push_obj(L, self, "olua.short");

    olua_endinvoke(L);

    return 1;
}

static int _olua_short_array(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // static olua::pointer<short> *array(size_t len)
    olua::pointer<short> *ret = olua_short::array((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.short");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_short_copyfrom1(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;
    olua_short *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */
    lua_Unsigned arg4 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.short");
    olua_check_obj(L, 2, &arg1, "olua.short");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void copyfrom(olua::pointer<short> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<short> *)arg1, (size_t)arg2, (size_t)arg3, (size_t)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_short_copyfrom2(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;
    olua_short *arg1 = nullptr;       /** obj */

    olua_to_obj(L, 1, &self, "olua.short");
    olua_check_obj(L, 2, &arg1, "olua.short");

    // void copyfrom(olua::pointer<short> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<short> *)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_short_copyfrom3(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;
    olua_short *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.short");
    olua_check_obj(L, 2, &arg1, "olua.short");
    olua_check_uint(L, 3, &arg2);

    // void copyfrom(olua::pointer<short> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<short> *)arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_short_copyfrom4(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;
    olua_short *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.short");
    olua_check_obj(L, 2, &arg1, "olua.short");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // void copyfrom(olua::pointer<short> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<short> *)arg1, (size_t)arg2, (size_t)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_short_copyfrom(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_obj(L, 2, "olua.short"))) {
            // void copyfrom(olua::pointer<short> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_short_copyfrom2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.short")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<short> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_short_copyfrom3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.short")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<short> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_short_copyfrom4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.short")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<short> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_short_copyfrom1(L);
        // }
    }

    luaL_error(L, "method 'olua_short::copyfrom' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_short_fill(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.short");
    olua_check_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void fill(const char *data, size_t len)
    self->fill(arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_short_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** v */

    olua_check_int(L, 1, &arg1);

    // @name(new) static olua::pointer<short> *create(const short &v)
    olua::pointer<short> *ret = olua_short::create((short)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.short");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_short_sub1(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */
    lua_Unsigned arg2 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.short");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // olua::pointer<short> *sub(size_t from, @optional size_t to)
    olua::pointer<short> *ret = self->sub((size_t)arg1, (size_t)arg2);
    int num_ret = olua_push_obj(L, ret, "olua.short");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_short_sub2(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.short");
    olua_check_uint(L, 2, &arg1);

    // olua::pointer<short> *sub(size_t from, @optional size_t to)
    olua::pointer<short> *ret = self->sub((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.short");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_short_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua::pointer<short> *sub(size_t from, @optional size_t to)
            return _olua_short_sub2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<short> *sub(size_t from, @optional size_t to)
            return _olua_short_sub1(L);
        // }
    }

    luaL_error(L, "method 'olua_short::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_short_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.short");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_short_tostring1(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.short");
    olua_check_uint(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L, (size_t)arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_short_tostring2(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.short");

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_short_tostring(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // if () {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_short_tostring2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_short_tostring1(L);
        // }
    }

    luaL_error(L, "method 'olua_short::tostring' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_short_getLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.short");

    // @getter @name(length) size_t getLength()
    size_t ret = self->getLength();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_short_setLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;
    lua_Unsigned arg1 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.short");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(length) void setLength(size_t len)
    self->setLength((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_short_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.short");

    // @getter const short &value()
    const short &ret = self->value();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_short(lua_State *L)
{
    oluacls_class(L, "olua.short", nullptr);
    oluacls_func(L, "__gc", _olua_short___gc);
    oluacls_func(L, "__index", _olua_short___index);
    oluacls_func(L, "__newindex", _olua_short___newindex);
    oluacls_func(L, "__olua_move", _olua_short___olua_move);
    oluacls_func(L, "array", _olua_short_array);
    oluacls_func(L, "copyfrom", _olua_short_copyfrom);
    oluacls_func(L, "fill", _olua_short_fill);
    oluacls_func(L, "new", _olua_short_create);
    oluacls_func(L, "sub", _olua_short_sub);
    oluacls_func(L, "take", _olua_short_take);
    oluacls_func(L, "tostring", _olua_short_tostring);
    oluacls_prop(L, "length", _olua_short_getLength, _olua_short_setLength);
    oluacls_prop(L, "value", _olua_short_value, nullptr);

    olua_registerluatype<olua_short>(L, "olua.short");

    return 1;
}
OLUA_END_DECLS

static int _olua_ushort___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ushort");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_ushort___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */

    olua_to_obj(L, 1, &self, "olua.ushort");
    olua_check_uint(L, 2, &arg1);

    // unsigned short __index(unsigned int idx)
    unsigned short ret = self->__index((unsigned int)arg1);
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ushort___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */
    lua_Unsigned arg2 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.ushort");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void __newindex(unsigned int idx, const unsigned short &v)
    self->__newindex((unsigned int)arg1, (unsigned short)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ushort___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_ushort *)olua_toobj(L, 1, "olua.ushort");
    olua_push_obj(L, self, "olua.ushort");

    olua_endinvoke(L);

    return 1;
}

static int _olua_ushort_array(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // static olua::pointer<unsigned short> *array(size_t len)
    olua::pointer<unsigned short> *ret = olua_ushort::array((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.ushort");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ushort_copyfrom1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;
    olua_ushort *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */
    lua_Unsigned arg4 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.ushort");
    olua_check_obj(L, 2, &arg1, "olua.ushort");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void copyfrom(olua::pointer<unsigned short> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<unsigned short> *)arg1, (size_t)arg2, (size_t)arg3, (size_t)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ushort_copyfrom2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;
    olua_ushort *arg1 = nullptr;       /** obj */

    olua_to_obj(L, 1, &self, "olua.ushort");
    olua_check_obj(L, 2, &arg1, "olua.ushort");

    // void copyfrom(olua::pointer<unsigned short> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<unsigned short> *)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ushort_copyfrom3(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;
    olua_ushort *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.ushort");
    olua_check_obj(L, 2, &arg1, "olua.ushort");
    olua_check_uint(L, 3, &arg2);

    // void copyfrom(olua::pointer<unsigned short> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<unsigned short> *)arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ushort_copyfrom4(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;
    olua_ushort *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.ushort");
    olua_check_obj(L, 2, &arg1, "olua.ushort");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // void copyfrom(olua::pointer<unsigned short> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<unsigned short> *)arg1, (size_t)arg2, (size_t)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ushort_copyfrom(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_obj(L, 2, "olua.ushort"))) {
            // void copyfrom(olua::pointer<unsigned short> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ushort_copyfrom2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.ushort")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<unsigned short> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ushort_copyfrom3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.ushort")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<unsigned short> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ushort_copyfrom4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.ushort")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<unsigned short> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ushort_copyfrom1(L);
        // }
    }

    luaL_error(L, "method 'olua_ushort::copyfrom' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ushort_fill(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.ushort");
    olua_check_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void fill(const char *data, size_t len)
    self->fill(arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ushort_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** v */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<unsigned short> *create(const unsigned short &v)
    olua::pointer<unsigned short> *ret = olua_ushort::create((unsigned short)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.ushort");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ushort_sub1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */
    lua_Unsigned arg2 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.ushort");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // olua::pointer<unsigned short> *sub(size_t from, @optional size_t to)
    olua::pointer<unsigned short> *ret = self->sub((size_t)arg1, (size_t)arg2);
    int num_ret = olua_push_obj(L, ret, "olua.ushort");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ushort_sub2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.ushort");
    olua_check_uint(L, 2, &arg1);

    // olua::pointer<unsigned short> *sub(size_t from, @optional size_t to)
    olua::pointer<unsigned short> *ret = self->sub((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.ushort");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ushort_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua::pointer<unsigned short> *sub(size_t from, @optional size_t to)
            return _olua_ushort_sub2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<unsigned short> *sub(size_t from, @optional size_t to)
            return _olua_ushort_sub1(L);
        // }
    }

    luaL_error(L, "method 'olua_ushort::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ushort_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ushort");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_ushort_tostring1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.ushort");
    olua_check_uint(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L, (size_t)arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_ushort_tostring2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ushort");

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_ushort_tostring(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // if () {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_ushort_tostring2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_ushort_tostring1(L);
        // }
    }

    luaL_error(L, "method 'olua_ushort::tostring' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ushort_getLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ushort");

    // @getter @name(length) size_t getLength()
    size_t ret = self->getLength();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ushort_setLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;
    lua_Unsigned arg1 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.ushort");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(length) void setLength(size_t len)
    self->setLength((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ushort_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ushort");

    // @getter const unsigned short &value()
    const unsigned short &ret = self->value();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_ushort(lua_State *L)
{
    oluacls_class(L, "olua.ushort", nullptr);
    oluacls_func(L, "__gc", _olua_ushort___gc);
    oluacls_func(L, "__index", _olua_ushort___index);
    oluacls_func(L, "__newindex", _olua_ushort___newindex);
    oluacls_func(L, "__olua_move", _olua_ushort___olua_move);
    oluacls_func(L, "array", _olua_ushort_array);
    oluacls_func(L, "copyfrom", _olua_ushort_copyfrom);
    oluacls_func(L, "fill", _olua_ushort_fill);
    oluacls_func(L, "new", _olua_ushort_create);
    oluacls_func(L, "sub", _olua_ushort_sub);
    oluacls_func(L, "take", _olua_ushort_take);
    oluacls_func(L, "tostring", _olua_ushort_tostring);
    oluacls_prop(L, "length", _olua_ushort_getLength, _olua_ushort_setLength);
    oluacls_prop(L, "value", _olua_ushort_value, nullptr);

    olua_registerluatype<olua_ushort>(L, "olua.ushort");

    return 1;
}
OLUA_END_DECLS

static int _olua_int___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_int___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */

    olua_to_obj(L, 1, &self, "olua.int");
    olua_check_uint(L, 2, &arg1);

    // int __index(unsigned int idx)
    int ret = self->__index((unsigned int)arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */
    lua_Integer arg2 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.int");
    olua_check_uint(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // void __newindex(unsigned int idx, const int &v)
    self->__newindex((unsigned int)arg1, (int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_int *)olua_toobj(L, 1, "olua.int");
    olua_push_obj(L, self, "olua.int");

    olua_endinvoke(L);

    return 1;
}

static int _olua_int_array(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // static olua::pointer<int> *array(size_t len)
    olua::pointer<int> *ret = olua_int::array((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.int");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int_copyfrom1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;
    olua_int *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */
    lua_Unsigned arg4 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.int");
    olua_check_obj(L, 2, &arg1, "olua.int");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void copyfrom(olua::pointer<int> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<int> *)arg1, (size_t)arg2, (size_t)arg3, (size_t)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int_copyfrom2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;
    olua_int *arg1 = nullptr;       /** obj */

    olua_to_obj(L, 1, &self, "olua.int");
    olua_check_obj(L, 2, &arg1, "olua.int");

    // void copyfrom(olua::pointer<int> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<int> *)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int_copyfrom3(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;
    olua_int *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.int");
    olua_check_obj(L, 2, &arg1, "olua.int");
    olua_check_uint(L, 3, &arg2);

    // void copyfrom(olua::pointer<int> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<int> *)arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int_copyfrom4(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;
    olua_int *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.int");
    olua_check_obj(L, 2, &arg1, "olua.int");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // void copyfrom(olua::pointer<int> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<int> *)arg1, (size_t)arg2, (size_t)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int_copyfrom(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_obj(L, 2, "olua.int"))) {
            // void copyfrom(olua::pointer<int> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int_copyfrom2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.int")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<int> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int_copyfrom3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.int")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<int> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int_copyfrom4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.int")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<int> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int_copyfrom1(L);
        // }
    }

    luaL_error(L, "method 'olua_int::copyfrom' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int_fill(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.int");
    olua_check_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void fill(const char *data, size_t len)
    self->fill(arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** v */

    olua_check_int(L, 1, &arg1);

    // @name(new) static olua::pointer<int> *create(const int &v)
    olua::pointer<int> *ret = olua_int::create((int)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.int");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int_sub1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */
    lua_Unsigned arg2 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.int");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // olua::pointer<int> *sub(size_t from, @optional size_t to)
    olua::pointer<int> *ret = self->sub((size_t)arg1, (size_t)arg2);
    int num_ret = olua_push_obj(L, ret, "olua.int");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int_sub2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.int");
    olua_check_uint(L, 2, &arg1);

    // olua::pointer<int> *sub(size_t from, @optional size_t to)
    olua::pointer<int> *ret = self->sub((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.int");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua::pointer<int> *sub(size_t from, @optional size_t to)
            return _olua_int_sub2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<int> *sub(size_t from, @optional size_t to)
            return _olua_int_sub1(L);
        // }
    }

    luaL_error(L, "method 'olua_int::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_int_tostring1(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.int");
    olua_check_uint(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L, (size_t)arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_int_tostring2(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int");

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_int_tostring(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // if () {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_int_tostring2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_int_tostring1(L);
        // }
    }

    luaL_error(L, "method 'olua_int::tostring' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int_getLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int");

    // @getter @name(length) size_t getLength()
    size_t ret = self->getLength();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int_setLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;
    lua_Unsigned arg1 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.int");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(length) void setLength(size_t len)
    self->setLength((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_int_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int");

    // @getter const int &value()
    const int &ret = self->value();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_int(lua_State *L)
{
    oluacls_class(L, "olua.int", nullptr);
    oluacls_func(L, "__gc", _olua_int___gc);
    oluacls_func(L, "__index", _olua_int___index);
    oluacls_func(L, "__newindex", _olua_int___newindex);
    oluacls_func(L, "__olua_move", _olua_int___olua_move);
    oluacls_func(L, "array", _olua_int_array);
    oluacls_func(L, "copyfrom", _olua_int_copyfrom);
    oluacls_func(L, "fill", _olua_int_fill);
    oluacls_func(L, "new", _olua_int_create);
    oluacls_func(L, "sub", _olua_int_sub);
    oluacls_func(L, "take", _olua_int_take);
    oluacls_func(L, "tostring", _olua_int_tostring);
    oluacls_prop(L, "length", _olua_int_getLength, _olua_int_setLength);
    oluacls_prop(L, "value", _olua_int_value, nullptr);

    olua_registerluatype<olua_int>(L, "olua.int");

    return 1;
}
OLUA_END_DECLS

static int _olua_uint___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_uint___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */

    olua_to_obj(L, 1, &self, "olua.uint");
    olua_check_uint(L, 2, &arg1);

    // unsigned int __index(unsigned int idx)
    unsigned int ret = self->__index((unsigned int)arg1);
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */
    lua_Unsigned arg2 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.uint");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void __newindex(unsigned int idx, const unsigned int &v)
    self->__newindex((unsigned int)arg1, (unsigned int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_uint *)olua_toobj(L, 1, "olua.uint");
    olua_push_obj(L, self, "olua.uint");

    olua_endinvoke(L);

    return 1;
}

static int _olua_uint_array(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // static olua::pointer<unsigned int> *array(size_t len)
    olua::pointer<unsigned int> *ret = olua_uint::array((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.uint");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint_copyfrom1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;
    olua_uint *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */
    lua_Unsigned arg4 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.uint");
    olua_check_obj(L, 2, &arg1, "olua.uint");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void copyfrom(olua::pointer<unsigned int> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<unsigned int> *)arg1, (size_t)arg2, (size_t)arg3, (size_t)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint_copyfrom2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;
    olua_uint *arg1 = nullptr;       /** obj */

    olua_to_obj(L, 1, &self, "olua.uint");
    olua_check_obj(L, 2, &arg1, "olua.uint");

    // void copyfrom(olua::pointer<unsigned int> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<unsigned int> *)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint_copyfrom3(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;
    olua_uint *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.uint");
    olua_check_obj(L, 2, &arg1, "olua.uint");
    olua_check_uint(L, 3, &arg2);

    // void copyfrom(olua::pointer<unsigned int> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<unsigned int> *)arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint_copyfrom4(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;
    olua_uint *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.uint");
    olua_check_obj(L, 2, &arg1, "olua.uint");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // void copyfrom(olua::pointer<unsigned int> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<unsigned int> *)arg1, (size_t)arg2, (size_t)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint_copyfrom(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_obj(L, 2, "olua.uint"))) {
            // void copyfrom(olua::pointer<unsigned int> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint_copyfrom2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.uint")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<unsigned int> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint_copyfrom3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.uint")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<unsigned int> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint_copyfrom4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.uint")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<unsigned int> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint_copyfrom1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint::copyfrom' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint_fill(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.uint");
    olua_check_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void fill(const char *data, size_t len)
    self->fill(arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** v */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<unsigned int> *create(const unsigned int &v)
    olua::pointer<unsigned int> *ret = olua_uint::create((unsigned int)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.uint");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint_sub1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */
    lua_Unsigned arg2 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.uint");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // olua::pointer<unsigned int> *sub(size_t from, @optional size_t to)
    olua::pointer<unsigned int> *ret = self->sub((size_t)arg1, (size_t)arg2);
    int num_ret = olua_push_obj(L, ret, "olua.uint");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint_sub2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.uint");
    olua_check_uint(L, 2, &arg1);

    // olua::pointer<unsigned int> *sub(size_t from, @optional size_t to)
    olua::pointer<unsigned int> *ret = self->sub((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.uint");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua::pointer<unsigned int> *sub(size_t from, @optional size_t to)
            return _olua_uint_sub2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<unsigned int> *sub(size_t from, @optional size_t to)
            return _olua_uint_sub1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint_tostring1(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.uint");
    olua_check_uint(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L, (size_t)arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_uint_tostring2(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint");

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_uint_tostring(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // if () {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_uint_tostring2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_uint_tostring1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint::tostring' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint_getLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint");

    // @getter @name(length) size_t getLength()
    size_t ret = self->getLength();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint_setLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;
    lua_Unsigned arg1 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.uint");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(length) void setLength(size_t len)
    self->setLength((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint");

    // @getter const unsigned int &value()
    const unsigned int &ret = self->value();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_uint(lua_State *L)
{
    oluacls_class(L, "olua.uint", nullptr);
    oluacls_func(L, "__gc", _olua_uint___gc);
    oluacls_func(L, "__index", _olua_uint___index);
    oluacls_func(L, "__newindex", _olua_uint___newindex);
    oluacls_func(L, "__olua_move", _olua_uint___olua_move);
    oluacls_func(L, "array", _olua_uint_array);
    oluacls_func(L, "copyfrom", _olua_uint_copyfrom);
    oluacls_func(L, "fill", _olua_uint_fill);
    oluacls_func(L, "new", _olua_uint_create);
    oluacls_func(L, "sub", _olua_uint_sub);
    oluacls_func(L, "take", _olua_uint_take);
    oluacls_func(L, "tostring", _olua_uint_tostring);
    oluacls_prop(L, "length", _olua_uint_getLength, _olua_uint_setLength);
    oluacls_prop(L, "value", _olua_uint_value, nullptr);

    olua_registerluatype<olua_uint>(L, "olua.uint");

    return 1;
}
OLUA_END_DECLS

static int _olua_long___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.long");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_long___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */

    olua_to_obj(L, 1, &self, "olua.long");
    olua_check_uint(L, 2, &arg1);

    // long __index(unsigned int idx)
    long ret = self->__index((unsigned int)arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_long___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */
    lua_Integer arg2 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.long");
    olua_check_uint(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // void __newindex(unsigned int idx, const long &v)
    self->__newindex((unsigned int)arg1, (long)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_long___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_long *)olua_toobj(L, 1, "olua.long");
    olua_push_obj(L, self, "olua.long");

    olua_endinvoke(L);

    return 1;
}

static int _olua_long_array(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // static olua::pointer<long> *array(size_t len)
    olua::pointer<long> *ret = olua_long::array((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.long");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_long_copyfrom1(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;
    olua_long *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */
    lua_Unsigned arg4 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.long");
    olua_check_obj(L, 2, &arg1, "olua.long");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void copyfrom(olua::pointer<long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<long> *)arg1, (size_t)arg2, (size_t)arg3, (size_t)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_long_copyfrom2(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;
    olua_long *arg1 = nullptr;       /** obj */

    olua_to_obj(L, 1, &self, "olua.long");
    olua_check_obj(L, 2, &arg1, "olua.long");

    // void copyfrom(olua::pointer<long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<long> *)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_long_copyfrom3(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;
    olua_long *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.long");
    olua_check_obj(L, 2, &arg1, "olua.long");
    olua_check_uint(L, 3, &arg2);

    // void copyfrom(olua::pointer<long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<long> *)arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_long_copyfrom4(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;
    olua_long *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.long");
    olua_check_obj(L, 2, &arg1, "olua.long");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // void copyfrom(olua::pointer<long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<long> *)arg1, (size_t)arg2, (size_t)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_long_copyfrom(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_obj(L, 2, "olua.long"))) {
            // void copyfrom(olua::pointer<long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_long_copyfrom2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.long")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_long_copyfrom3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.long")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_long_copyfrom4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.long")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_long_copyfrom1(L);
        // }
    }

    luaL_error(L, "method 'olua_long::copyfrom' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_long_fill(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.long");
    olua_check_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void fill(const char *data, size_t len)
    self->fill(arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_long_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** v */

    olua_check_int(L, 1, &arg1);

    // @name(new) static olua::pointer<long> *create(const long &v)
    olua::pointer<long> *ret = olua_long::create((long)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.long");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_long_sub1(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */
    lua_Unsigned arg2 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.long");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // olua::pointer<long> *sub(size_t from, @optional size_t to)
    olua::pointer<long> *ret = self->sub((size_t)arg1, (size_t)arg2);
    int num_ret = olua_push_obj(L, ret, "olua.long");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_long_sub2(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.long");
    olua_check_uint(L, 2, &arg1);

    // olua::pointer<long> *sub(size_t from, @optional size_t to)
    olua::pointer<long> *ret = self->sub((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.long");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_long_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua::pointer<long> *sub(size_t from, @optional size_t to)
            return _olua_long_sub2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<long> *sub(size_t from, @optional size_t to)
            return _olua_long_sub1(L);
        // }
    }

    luaL_error(L, "method 'olua_long::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_long_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.long");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_long_tostring1(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.long");
    olua_check_uint(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L, (size_t)arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_long_tostring2(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.long");

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_long_tostring(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // if () {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_long_tostring2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_long_tostring1(L);
        // }
    }

    luaL_error(L, "method 'olua_long::tostring' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_long_getLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.long");

    // @getter @name(length) size_t getLength()
    size_t ret = self->getLength();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_long_setLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;
    lua_Unsigned arg1 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.long");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(length) void setLength(size_t len)
    self->setLength((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_long_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.long");

    // @getter const long &value()
    const long &ret = self->value();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_long(lua_State *L)
{
    oluacls_class(L, "olua.long", nullptr);
    oluacls_func(L, "__gc", _olua_long___gc);
    oluacls_func(L, "__index", _olua_long___index);
    oluacls_func(L, "__newindex", _olua_long___newindex);
    oluacls_func(L, "__olua_move", _olua_long___olua_move);
    oluacls_func(L, "array", _olua_long_array);
    oluacls_func(L, "copyfrom", _olua_long_copyfrom);
    oluacls_func(L, "fill", _olua_long_fill);
    oluacls_func(L, "new", _olua_long_create);
    oluacls_func(L, "sub", _olua_long_sub);
    oluacls_func(L, "take", _olua_long_take);
    oluacls_func(L, "tostring", _olua_long_tostring);
    oluacls_prop(L, "length", _olua_long_getLength, _olua_long_setLength);
    oluacls_prop(L, "value", _olua_long_value, nullptr);

    olua_registerluatype<olua_long>(L, "olua.long");

    return 1;
}
OLUA_END_DECLS

static int _olua_ulong___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ulong");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_ulong___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */

    olua_to_obj(L, 1, &self, "olua.ulong");
    olua_check_uint(L, 2, &arg1);

    // unsigned long __index(unsigned int idx)
    unsigned long ret = self->__index((unsigned int)arg1);
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ulong___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */
    lua_Unsigned arg2 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.ulong");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void __newindex(unsigned int idx, const unsigned long &v)
    self->__newindex((unsigned int)arg1, (unsigned long)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ulong___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_ulong *)olua_toobj(L, 1, "olua.ulong");
    olua_push_obj(L, self, "olua.ulong");

    olua_endinvoke(L);

    return 1;
}

static int _olua_ulong_array(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // static olua::pointer<unsigned long> *array(size_t len)
    olua::pointer<unsigned long> *ret = olua_ulong::array((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.ulong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ulong_copyfrom1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;
    olua_ulong *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */
    lua_Unsigned arg4 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.ulong");
    olua_check_obj(L, 2, &arg1, "olua.ulong");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void copyfrom(olua::pointer<unsigned long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<unsigned long> *)arg1, (size_t)arg2, (size_t)arg3, (size_t)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ulong_copyfrom2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;
    olua_ulong *arg1 = nullptr;       /** obj */

    olua_to_obj(L, 1, &self, "olua.ulong");
    olua_check_obj(L, 2, &arg1, "olua.ulong");

    // void copyfrom(olua::pointer<unsigned long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<unsigned long> *)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ulong_copyfrom3(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;
    olua_ulong *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.ulong");
    olua_check_obj(L, 2, &arg1, "olua.ulong");
    olua_check_uint(L, 3, &arg2);

    // void copyfrom(olua::pointer<unsigned long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<unsigned long> *)arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ulong_copyfrom4(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;
    olua_ulong *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.ulong");
    olua_check_obj(L, 2, &arg1, "olua.ulong");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // void copyfrom(olua::pointer<unsigned long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<unsigned long> *)arg1, (size_t)arg2, (size_t)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ulong_copyfrom(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_obj(L, 2, "olua.ulong"))) {
            // void copyfrom(olua::pointer<unsigned long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ulong_copyfrom2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.ulong")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<unsigned long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ulong_copyfrom3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.ulong")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<unsigned long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ulong_copyfrom4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.ulong")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<unsigned long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ulong_copyfrom1(L);
        // }
    }

    luaL_error(L, "method 'olua_ulong::copyfrom' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ulong_fill(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.ulong");
    olua_check_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void fill(const char *data, size_t len)
    self->fill(arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ulong_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** v */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<unsigned long> *create(const unsigned long &v)
    olua::pointer<unsigned long> *ret = olua_ulong::create((unsigned long)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.ulong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ulong_sub1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */
    lua_Unsigned arg2 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.ulong");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // olua::pointer<unsigned long> *sub(size_t from, @optional size_t to)
    olua::pointer<unsigned long> *ret = self->sub((size_t)arg1, (size_t)arg2);
    int num_ret = olua_push_obj(L, ret, "olua.ulong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ulong_sub2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.ulong");
    olua_check_uint(L, 2, &arg1);

    // olua::pointer<unsigned long> *sub(size_t from, @optional size_t to)
    olua::pointer<unsigned long> *ret = self->sub((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.ulong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ulong_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua::pointer<unsigned long> *sub(size_t from, @optional size_t to)
            return _olua_ulong_sub2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<unsigned long> *sub(size_t from, @optional size_t to)
            return _olua_ulong_sub1(L);
        // }
    }

    luaL_error(L, "method 'olua_ulong::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ulong_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ulong");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_ulong_tostring1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.ulong");
    olua_check_uint(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L, (size_t)arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_ulong_tostring2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ulong");

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_ulong_tostring(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // if () {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_ulong_tostring2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_ulong_tostring1(L);
        // }
    }

    luaL_error(L, "method 'olua_ulong::tostring' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ulong_getLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ulong");

    // @getter @name(length) size_t getLength()
    size_t ret = self->getLength();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ulong_setLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;
    lua_Unsigned arg1 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.ulong");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(length) void setLength(size_t len)
    self->setLength((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ulong_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ulong");

    // @getter const unsigned long &value()
    const unsigned long &ret = self->value();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_ulong(lua_State *L)
{
    oluacls_class(L, "olua.ulong", nullptr);
    oluacls_func(L, "__gc", _olua_ulong___gc);
    oluacls_func(L, "__index", _olua_ulong___index);
    oluacls_func(L, "__newindex", _olua_ulong___newindex);
    oluacls_func(L, "__olua_move", _olua_ulong___olua_move);
    oluacls_func(L, "array", _olua_ulong_array);
    oluacls_func(L, "copyfrom", _olua_ulong_copyfrom);
    oluacls_func(L, "fill", _olua_ulong_fill);
    oluacls_func(L, "new", _olua_ulong_create);
    oluacls_func(L, "sub", _olua_ulong_sub);
    oluacls_func(L, "take", _olua_ulong_take);
    oluacls_func(L, "tostring", _olua_ulong_tostring);
    oluacls_prop(L, "length", _olua_ulong_getLength, _olua_ulong_setLength);
    oluacls_prop(L, "value", _olua_ulong_value, nullptr);

    olua_registerluatype<olua_ulong>(L, "olua.ulong");

    return 1;
}
OLUA_END_DECLS

static int _olua_llong___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.llong");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_llong___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */

    olua_to_obj(L, 1, &self, "olua.llong");
    olua_check_uint(L, 2, &arg1);

    // long long __index(unsigned int idx)
    long long ret = self->__index((unsigned int)arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_llong___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */
    lua_Integer arg2 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.llong");
    olua_check_uint(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // void __newindex(unsigned int idx, const long long &v)
    self->__newindex((unsigned int)arg1, (long long)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_llong___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_llong *)olua_toobj(L, 1, "olua.llong");
    olua_push_obj(L, self, "olua.llong");

    olua_endinvoke(L);

    return 1;
}

static int _olua_llong_array(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // static olua::pointer<long long> *array(size_t len)
    olua::pointer<long long> *ret = olua_llong::array((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.llong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_llong_copyfrom1(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;
    olua_llong *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */
    lua_Unsigned arg4 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.llong");
    olua_check_obj(L, 2, &arg1, "olua.llong");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void copyfrom(olua::pointer<long long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<long long> *)arg1, (size_t)arg2, (size_t)arg3, (size_t)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_llong_copyfrom2(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;
    olua_llong *arg1 = nullptr;       /** obj */

    olua_to_obj(L, 1, &self, "olua.llong");
    olua_check_obj(L, 2, &arg1, "olua.llong");

    // void copyfrom(olua::pointer<long long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<long long> *)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_llong_copyfrom3(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;
    olua_llong *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.llong");
    olua_check_obj(L, 2, &arg1, "olua.llong");
    olua_check_uint(L, 3, &arg2);

    // void copyfrom(olua::pointer<long long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<long long> *)arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_llong_copyfrom4(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;
    olua_llong *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.llong");
    olua_check_obj(L, 2, &arg1, "olua.llong");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // void copyfrom(olua::pointer<long long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<long long> *)arg1, (size_t)arg2, (size_t)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_llong_copyfrom(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_obj(L, 2, "olua.llong"))) {
            // void copyfrom(olua::pointer<long long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_llong_copyfrom2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.llong")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<long long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_llong_copyfrom3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.llong")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<long long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_llong_copyfrom4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.llong")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<long long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_llong_copyfrom1(L);
        // }
    }

    luaL_error(L, "method 'olua_llong::copyfrom' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_llong_fill(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.llong");
    olua_check_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void fill(const char *data, size_t len)
    self->fill(arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_llong_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** v */

    olua_check_int(L, 1, &arg1);

    // @name(new) static olua::pointer<long long> *create(const long long &v)
    olua::pointer<long long> *ret = olua_llong::create((long long)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.llong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_llong_sub1(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */
    lua_Unsigned arg2 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.llong");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // olua::pointer<long long> *sub(size_t from, @optional size_t to)
    olua::pointer<long long> *ret = self->sub((size_t)arg1, (size_t)arg2);
    int num_ret = olua_push_obj(L, ret, "olua.llong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_llong_sub2(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.llong");
    olua_check_uint(L, 2, &arg1);

    // olua::pointer<long long> *sub(size_t from, @optional size_t to)
    olua::pointer<long long> *ret = self->sub((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.llong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_llong_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua::pointer<long long> *sub(size_t from, @optional size_t to)
            return _olua_llong_sub2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<long long> *sub(size_t from, @optional size_t to)
            return _olua_llong_sub1(L);
        // }
    }

    luaL_error(L, "method 'olua_llong::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_llong_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.llong");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_llong_tostring1(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.llong");
    olua_check_uint(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L, (size_t)arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_llong_tostring2(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.llong");

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_llong_tostring(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // if () {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_llong_tostring2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_llong_tostring1(L);
        // }
    }

    luaL_error(L, "method 'olua_llong::tostring' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_llong_getLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.llong");

    // @getter @name(length) size_t getLength()
    size_t ret = self->getLength();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_llong_setLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;
    lua_Unsigned arg1 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.llong");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(length) void setLength(size_t len)
    self->setLength((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_llong_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.llong");

    // @getter const long long &value()
    const long long &ret = self->value();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_llong(lua_State *L)
{
    oluacls_class(L, "olua.llong", nullptr);
    oluacls_func(L, "__gc", _olua_llong___gc);
    oluacls_func(L, "__index", _olua_llong___index);
    oluacls_func(L, "__newindex", _olua_llong___newindex);
    oluacls_func(L, "__olua_move", _olua_llong___olua_move);
    oluacls_func(L, "array", _olua_llong_array);
    oluacls_func(L, "copyfrom", _olua_llong_copyfrom);
    oluacls_func(L, "fill", _olua_llong_fill);
    oluacls_func(L, "new", _olua_llong_create);
    oluacls_func(L, "sub", _olua_llong_sub);
    oluacls_func(L, "take", _olua_llong_take);
    oluacls_func(L, "tostring", _olua_llong_tostring);
    oluacls_prop(L, "length", _olua_llong_getLength, _olua_llong_setLength);
    oluacls_prop(L, "value", _olua_llong_value, nullptr);

    olua_registerluatype<olua_llong>(L, "olua.llong");

    return 1;
}
OLUA_END_DECLS

static int _olua_ullong___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ullong");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_ullong___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */

    olua_to_obj(L, 1, &self, "olua.ullong");
    olua_check_uint(L, 2, &arg1);

    // unsigned long long __index(unsigned int idx)
    unsigned long long ret = self->__index((unsigned int)arg1);
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ullong___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */
    lua_Unsigned arg2 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.ullong");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void __newindex(unsigned int idx, const unsigned long long &v)
    self->__newindex((unsigned int)arg1, (unsigned long long)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ullong___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_ullong *)olua_toobj(L, 1, "olua.ullong");
    olua_push_obj(L, self, "olua.ullong");

    olua_endinvoke(L);

    return 1;
}

static int _olua_ullong_array(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // static olua::pointer<unsigned long long> *array(size_t len)
    olua::pointer<unsigned long long> *ret = olua_ullong::array((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.ullong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ullong_copyfrom1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;
    olua_ullong *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */
    lua_Unsigned arg4 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.ullong");
    olua_check_obj(L, 2, &arg1, "olua.ullong");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void copyfrom(olua::pointer<unsigned long long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<unsigned long long> *)arg1, (size_t)arg2, (size_t)arg3, (size_t)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ullong_copyfrom2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;
    olua_ullong *arg1 = nullptr;       /** obj */

    olua_to_obj(L, 1, &self, "olua.ullong");
    olua_check_obj(L, 2, &arg1, "olua.ullong");

    // void copyfrom(olua::pointer<unsigned long long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<unsigned long long> *)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ullong_copyfrom3(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;
    olua_ullong *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.ullong");
    olua_check_obj(L, 2, &arg1, "olua.ullong");
    olua_check_uint(L, 3, &arg2);

    // void copyfrom(olua::pointer<unsigned long long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<unsigned long long> *)arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ullong_copyfrom4(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;
    olua_ullong *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.ullong");
    olua_check_obj(L, 2, &arg1, "olua.ullong");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // void copyfrom(olua::pointer<unsigned long long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<unsigned long long> *)arg1, (size_t)arg2, (size_t)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ullong_copyfrom(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_obj(L, 2, "olua.ullong"))) {
            // void copyfrom(olua::pointer<unsigned long long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ullong_copyfrom2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.ullong")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<unsigned long long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ullong_copyfrom3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.ullong")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<unsigned long long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ullong_copyfrom4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.ullong")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<unsigned long long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ullong_copyfrom1(L);
        // }
    }

    luaL_error(L, "method 'olua_ullong::copyfrom' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ullong_fill(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.ullong");
    olua_check_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void fill(const char *data, size_t len)
    self->fill(arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ullong_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** v */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<unsigned long long> *create(const unsigned long long &v)
    olua::pointer<unsigned long long> *ret = olua_ullong::create((unsigned long long)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.ullong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ullong_sub1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */
    lua_Unsigned arg2 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.ullong");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // olua::pointer<unsigned long long> *sub(size_t from, @optional size_t to)
    olua::pointer<unsigned long long> *ret = self->sub((size_t)arg1, (size_t)arg2);
    int num_ret = olua_push_obj(L, ret, "olua.ullong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ullong_sub2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.ullong");
    olua_check_uint(L, 2, &arg1);

    // olua::pointer<unsigned long long> *sub(size_t from, @optional size_t to)
    olua::pointer<unsigned long long> *ret = self->sub((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.ullong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ullong_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua::pointer<unsigned long long> *sub(size_t from, @optional size_t to)
            return _olua_ullong_sub2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<unsigned long long> *sub(size_t from, @optional size_t to)
            return _olua_ullong_sub1(L);
        // }
    }

    luaL_error(L, "method 'olua_ullong::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ullong_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ullong");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_ullong_tostring1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.ullong");
    olua_check_uint(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L, (size_t)arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_ullong_tostring2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ullong");

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_ullong_tostring(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // if () {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_ullong_tostring2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_ullong_tostring1(L);
        // }
    }

    luaL_error(L, "method 'olua_ullong::tostring' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ullong_getLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ullong");

    // @getter @name(length) size_t getLength()
    size_t ret = self->getLength();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ullong_setLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;
    lua_Unsigned arg1 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.ullong");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(length) void setLength(size_t len)
    self->setLength((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ullong_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ullong");

    // @getter const unsigned long long &value()
    const unsigned long long &ret = self->value();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_ullong(lua_State *L)
{
    oluacls_class(L, "olua.ullong", nullptr);
    oluacls_func(L, "__gc", _olua_ullong___gc);
    oluacls_func(L, "__index", _olua_ullong___index);
    oluacls_func(L, "__newindex", _olua_ullong___newindex);
    oluacls_func(L, "__olua_move", _olua_ullong___olua_move);
    oluacls_func(L, "array", _olua_ullong_array);
    oluacls_func(L, "copyfrom", _olua_ullong_copyfrom);
    oluacls_func(L, "fill", _olua_ullong_fill);
    oluacls_func(L, "new", _olua_ullong_create);
    oluacls_func(L, "sub", _olua_ullong_sub);
    oluacls_func(L, "take", _olua_ullong_take);
    oluacls_func(L, "tostring", _olua_ullong_tostring);
    oluacls_prop(L, "length", _olua_ullong_getLength, _olua_ullong_setLength);
    oluacls_prop(L, "value", _olua_ullong_value, nullptr);

    olua_registerluatype<olua_ullong>(L, "olua.ullong");

    return 1;
}
OLUA_END_DECLS

static int _olua_float___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.float");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_float___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */

    olua_to_obj(L, 1, &self, "olua.float");
    olua_check_uint(L, 2, &arg1);

    // float __index(unsigned int idx)
    float ret = self->__index((unsigned int)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_float___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */
    lua_Number arg2 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.float");
    olua_check_uint(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void __newindex(unsigned int idx, const float &v)
    self->__newindex((unsigned int)arg1, (float)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_float___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_float *)olua_toobj(L, 1, "olua.float");
    olua_push_obj(L, self, "olua.float");

    olua_endinvoke(L);

    return 1;
}

static int _olua_float_array(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // static olua::pointer<float> *array(size_t len)
    olua::pointer<float> *ret = olua_float::array((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.float");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_float_copyfrom1(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;
    olua_float *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */
    lua_Unsigned arg4 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.float");
    olua_check_obj(L, 2, &arg1, "olua.float");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void copyfrom(olua::pointer<float> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<float> *)arg1, (size_t)arg2, (size_t)arg3, (size_t)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_float_copyfrom2(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;
    olua_float *arg1 = nullptr;       /** obj */

    olua_to_obj(L, 1, &self, "olua.float");
    olua_check_obj(L, 2, &arg1, "olua.float");

    // void copyfrom(olua::pointer<float> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<float> *)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_float_copyfrom3(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;
    olua_float *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.float");
    olua_check_obj(L, 2, &arg1, "olua.float");
    olua_check_uint(L, 3, &arg2);

    // void copyfrom(olua::pointer<float> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<float> *)arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_float_copyfrom4(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;
    olua_float *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.float");
    olua_check_obj(L, 2, &arg1, "olua.float");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // void copyfrom(olua::pointer<float> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<float> *)arg1, (size_t)arg2, (size_t)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_float_copyfrom(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_obj(L, 2, "olua.float"))) {
            // void copyfrom(olua::pointer<float> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_float_copyfrom2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.float")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<float> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_float_copyfrom3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.float")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<float> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_float_copyfrom4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.float")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<float> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_float_copyfrom1(L);
        // }
    }

    luaL_error(L, "method 'olua_float::copyfrom' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_float_fill(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.float");
    olua_check_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void fill(const char *data, size_t len)
    self->fill(arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_float_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** v */

    olua_check_number(L, 1, &arg1);

    // @name(new) static olua::pointer<float> *create(const float &v)
    olua::pointer<float> *ret = olua_float::create((float)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.float");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_float_sub1(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */
    lua_Unsigned arg2 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.float");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // olua::pointer<float> *sub(size_t from, @optional size_t to)
    olua::pointer<float> *ret = self->sub((size_t)arg1, (size_t)arg2);
    int num_ret = olua_push_obj(L, ret, "olua.float");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_float_sub2(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.float");
    olua_check_uint(L, 2, &arg1);

    // olua::pointer<float> *sub(size_t from, @optional size_t to)
    olua::pointer<float> *ret = self->sub((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.float");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_float_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua::pointer<float> *sub(size_t from, @optional size_t to)
            return _olua_float_sub2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<float> *sub(size_t from, @optional size_t to)
            return _olua_float_sub1(L);
        // }
    }

    luaL_error(L, "method 'olua_float::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_float_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.float");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_float_tostring1(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.float");
    olua_check_uint(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L, (size_t)arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_float_tostring2(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.float");

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_float_tostring(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // if () {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_float_tostring2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_float_tostring1(L);
        // }
    }

    luaL_error(L, "method 'olua_float::tostring' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_float_getLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.float");

    // @getter @name(length) size_t getLength()
    size_t ret = self->getLength();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_float_setLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;
    lua_Unsigned arg1 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.float");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(length) void setLength(size_t len)
    self->setLength((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_float_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.float");

    // @getter const float &value()
    const float &ret = self->value();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_float(lua_State *L)
{
    oluacls_class(L, "olua.float", nullptr);
    oluacls_func(L, "__gc", _olua_float___gc);
    oluacls_func(L, "__index", _olua_float___index);
    oluacls_func(L, "__newindex", _olua_float___newindex);
    oluacls_func(L, "__olua_move", _olua_float___olua_move);
    oluacls_func(L, "array", _olua_float_array);
    oluacls_func(L, "copyfrom", _olua_float_copyfrom);
    oluacls_func(L, "fill", _olua_float_fill);
    oluacls_func(L, "new", _olua_float_create);
    oluacls_func(L, "sub", _olua_float_sub);
    oluacls_func(L, "take", _olua_float_take);
    oluacls_func(L, "tostring", _olua_float_tostring);
    oluacls_prop(L, "length", _olua_float_getLength, _olua_float_setLength);
    oluacls_prop(L, "value", _olua_float_value, nullptr);

    olua_registerluatype<olua_float>(L, "olua.float");

    return 1;
}
OLUA_END_DECLS

static int _olua_double___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.double");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_double___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */

    olua_to_obj(L, 1, &self, "olua.double");
    olua_check_uint(L, 2, &arg1);

    // double __index(unsigned int idx)
    double ret = self->__index((unsigned int)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_double___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */
    lua_Number arg2 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.double");
    olua_check_uint(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void __newindex(unsigned int idx, const double &v)
    self->__newindex((unsigned int)arg1, (double)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_double___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_double *)olua_toobj(L, 1, "olua.double");
    olua_push_obj(L, self, "olua.double");

    olua_endinvoke(L);

    return 1;
}

static int _olua_double_array(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // static olua::pointer<double> *array(size_t len)
    olua::pointer<double> *ret = olua_double::array((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.double");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_double_copyfrom1(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;
    olua_double *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */
    lua_Unsigned arg4 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.double");
    olua_check_obj(L, 2, &arg1, "olua.double");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void copyfrom(olua::pointer<double> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<double> *)arg1, (size_t)arg2, (size_t)arg3, (size_t)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_double_copyfrom2(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;
    olua_double *arg1 = nullptr;       /** obj */

    olua_to_obj(L, 1, &self, "olua.double");
    olua_check_obj(L, 2, &arg1, "olua.double");

    // void copyfrom(olua::pointer<double> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<double> *)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_double_copyfrom3(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;
    olua_double *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.double");
    olua_check_obj(L, 2, &arg1, "olua.double");
    olua_check_uint(L, 3, &arg2);

    // void copyfrom(olua::pointer<double> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<double> *)arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_double_copyfrom4(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;
    olua_double *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.double");
    olua_check_obj(L, 2, &arg1, "olua.double");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // void copyfrom(olua::pointer<double> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<double> *)arg1, (size_t)arg2, (size_t)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_double_copyfrom(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_obj(L, 2, "olua.double"))) {
            // void copyfrom(olua::pointer<double> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_double_copyfrom2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.double")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<double> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_double_copyfrom3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.double")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<double> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_double_copyfrom4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.double")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<double> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_double_copyfrom1(L);
        // }
    }

    luaL_error(L, "method 'olua_double::copyfrom' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_double_fill(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.double");
    olua_check_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void fill(const char *data, size_t len)
    self->fill(arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_double_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** v */

    olua_check_number(L, 1, &arg1);

    // @name(new) static olua::pointer<double> *create(const double &v)
    olua::pointer<double> *ret = olua_double::create((double)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.double");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_double_sub1(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */
    lua_Unsigned arg2 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.double");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // olua::pointer<double> *sub(size_t from, @optional size_t to)
    olua::pointer<double> *ret = self->sub((size_t)arg1, (size_t)arg2);
    int num_ret = olua_push_obj(L, ret, "olua.double");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_double_sub2(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.double");
    olua_check_uint(L, 2, &arg1);

    // olua::pointer<double> *sub(size_t from, @optional size_t to)
    olua::pointer<double> *ret = self->sub((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.double");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_double_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua::pointer<double> *sub(size_t from, @optional size_t to)
            return _olua_double_sub2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<double> *sub(size_t from, @optional size_t to)
            return _olua_double_sub1(L);
        // }
    }

    luaL_error(L, "method 'olua_double::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_double_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.double");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_double_tostring1(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.double");
    olua_check_uint(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L, (size_t)arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_double_tostring2(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.double");

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_double_tostring(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // if () {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_double_tostring2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_double_tostring1(L);
        // }
    }

    luaL_error(L, "method 'olua_double::tostring' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_double_getLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.double");

    // @getter @name(length) size_t getLength()
    size_t ret = self->getLength();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_double_setLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;
    lua_Unsigned arg1 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.double");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(length) void setLength(size_t len)
    self->setLength((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_double_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.double");

    // @getter const double &value()
    const double &ret = self->value();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_double(lua_State *L)
{
    oluacls_class(L, "olua.double", nullptr);
    oluacls_func(L, "__gc", _olua_double___gc);
    oluacls_func(L, "__index", _olua_double___index);
    oluacls_func(L, "__newindex", _olua_double___newindex);
    oluacls_func(L, "__olua_move", _olua_double___olua_move);
    oluacls_func(L, "array", _olua_double_array);
    oluacls_func(L, "copyfrom", _olua_double_copyfrom);
    oluacls_func(L, "fill", _olua_double_fill);
    oluacls_func(L, "new", _olua_double_create);
    oluacls_func(L, "sub", _olua_double_sub);
    oluacls_func(L, "take", _olua_double_take);
    oluacls_func(L, "tostring", _olua_double_tostring);
    oluacls_prop(L, "length", _olua_double_getLength, _olua_double_setLength);
    oluacls_prop(L, "value", _olua_double_value, nullptr);

    olua_registerluatype<olua_double>(L, "olua.double");

    return 1;
}
OLUA_END_DECLS

static int _olua_ldouble___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ldouble");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_ldouble___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */

    olua_to_obj(L, 1, &self, "olua.ldouble");
    olua_check_uint(L, 2, &arg1);

    // long double __index(unsigned int idx)
    long double ret = self->__index((unsigned int)arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ldouble___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */
    lua_Number arg2 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.ldouble");
    olua_check_uint(L, 2, &arg1);
    olua_check_number(L, 3, &arg2);

    // void __newindex(unsigned int idx, const long double &v)
    self->__newindex((unsigned int)arg1, (long double)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ldouble___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_ldouble *)olua_toobj(L, 1, "olua.ldouble");
    olua_push_obj(L, self, "olua.ldouble");

    olua_endinvoke(L);

    return 1;
}

static int _olua_ldouble_array(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // static olua::pointer<long double> *array(size_t len)
    olua::pointer<long double> *ret = olua_ldouble::array((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.ldouble");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ldouble_copyfrom1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;
    olua_ldouble *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */
    lua_Unsigned arg4 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.ldouble");
    olua_check_obj(L, 2, &arg1, "olua.ldouble");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void copyfrom(olua::pointer<long double> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<long double> *)arg1, (size_t)arg2, (size_t)arg3, (size_t)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ldouble_copyfrom2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;
    olua_ldouble *arg1 = nullptr;       /** obj */

    olua_to_obj(L, 1, &self, "olua.ldouble");
    olua_check_obj(L, 2, &arg1, "olua.ldouble");

    // void copyfrom(olua::pointer<long double> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<long double> *)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ldouble_copyfrom3(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;
    olua_ldouble *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.ldouble");
    olua_check_obj(L, 2, &arg1, "olua.ldouble");
    olua_check_uint(L, 3, &arg2);

    // void copyfrom(olua::pointer<long double> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<long double> *)arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ldouble_copyfrom4(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;
    olua_ldouble *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.ldouble");
    olua_check_obj(L, 2, &arg1, "olua.ldouble");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // void copyfrom(olua::pointer<long double> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<long double> *)arg1, (size_t)arg2, (size_t)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ldouble_copyfrom(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_obj(L, 2, "olua.ldouble"))) {
            // void copyfrom(olua::pointer<long double> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ldouble_copyfrom2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.ldouble")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<long double> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ldouble_copyfrom3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.ldouble")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<long double> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ldouble_copyfrom4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.ldouble")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<long double> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ldouble_copyfrom1(L);
        // }
    }

    luaL_error(L, "method 'olua_ldouble::copyfrom' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ldouble_fill(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.ldouble");
    olua_check_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void fill(const char *data, size_t len)
    self->fill(arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ldouble_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** v */

    olua_check_number(L, 1, &arg1);

    // @name(new) static olua::pointer<long double> *create(const long double &v)
    olua::pointer<long double> *ret = olua_ldouble::create((long double)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.ldouble");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ldouble_sub1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */
    lua_Unsigned arg2 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.ldouble");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // olua::pointer<long double> *sub(size_t from, @optional size_t to)
    olua::pointer<long double> *ret = self->sub((size_t)arg1, (size_t)arg2);
    int num_ret = olua_push_obj(L, ret, "olua.ldouble");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ldouble_sub2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.ldouble");
    olua_check_uint(L, 2, &arg1);

    // olua::pointer<long double> *sub(size_t from, @optional size_t to)
    olua::pointer<long double> *ret = self->sub((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.ldouble");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ldouble_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua::pointer<long double> *sub(size_t from, @optional size_t to)
            return _olua_ldouble_sub2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<long double> *sub(size_t from, @optional size_t to)
            return _olua_ldouble_sub1(L);
        // }
    }

    luaL_error(L, "method 'olua_ldouble::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ldouble_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ldouble");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_ldouble_tostring1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.ldouble");
    olua_check_uint(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L, (size_t)arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_ldouble_tostring2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ldouble");

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_ldouble_tostring(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // if () {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_ldouble_tostring2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_ldouble_tostring1(L);
        // }
    }

    luaL_error(L, "method 'olua_ldouble::tostring' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ldouble_getLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ldouble");

    // @getter @name(length) size_t getLength()
    size_t ret = self->getLength();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ldouble_setLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;
    lua_Unsigned arg1 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.ldouble");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(length) void setLength(size_t len)
    self->setLength((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ldouble_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ldouble");

    // @getter const long double &value()
    const long double &ret = self->value();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_ldouble(lua_State *L)
{
    oluacls_class(L, "olua.ldouble", nullptr);
    oluacls_func(L, "__gc", _olua_ldouble___gc);
    oluacls_func(L, "__index", _olua_ldouble___index);
    oluacls_func(L, "__newindex", _olua_ldouble___newindex);
    oluacls_func(L, "__olua_move", _olua_ldouble___olua_move);
    oluacls_func(L, "array", _olua_ldouble_array);
    oluacls_func(L, "copyfrom", _olua_ldouble_copyfrom);
    oluacls_func(L, "fill", _olua_ldouble_fill);
    oluacls_func(L, "new", _olua_ldouble_create);
    oluacls_func(L, "sub", _olua_ldouble_sub);
    oluacls_func(L, "take", _olua_ldouble_take);
    oluacls_func(L, "tostring", _olua_ldouble_tostring);
    oluacls_prop(L, "length", _olua_ldouble_getLength, _olua_ldouble_setLength);
    oluacls_prop(L, "value", _olua_ldouble_value, nullptr);

    olua_registerluatype<olua_ldouble>(L, "olua.ldouble");

    return 1;
}
OLUA_END_DECLS

static int _olua_size_t___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.size_t");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_size_t___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */

    olua_to_obj(L, 1, &self, "olua.size_t");
    olua_check_uint(L, 2, &arg1);

    // size_t __index(unsigned int idx)
    size_t ret = self->__index((unsigned int)arg1);
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_size_t___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */
    lua_Unsigned arg2 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.size_t");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void __newindex(unsigned int idx, const size_t &v)
    self->__newindex((unsigned int)arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_size_t___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_size_t *)olua_toobj(L, 1, "olua.size_t");
    olua_push_obj(L, self, "olua.size_t");

    olua_endinvoke(L);

    return 1;
}

static int _olua_size_t_array(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // static olua::pointer<size_t> *array(size_t len)
    olua::pointer<size_t> *ret = olua_size_t::array((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.size_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_size_t_copyfrom1(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;
    olua_size_t *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */
    lua_Unsigned arg4 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.size_t");
    olua_check_obj(L, 2, &arg1, "olua.size_t");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void copyfrom(olua::pointer<size_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<size_t> *)arg1, (size_t)arg2, (size_t)arg3, (size_t)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_size_t_copyfrom2(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;
    olua_size_t *arg1 = nullptr;       /** obj */

    olua_to_obj(L, 1, &self, "olua.size_t");
    olua_check_obj(L, 2, &arg1, "olua.size_t");

    // void copyfrom(olua::pointer<size_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<size_t> *)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_size_t_copyfrom3(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;
    olua_size_t *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.size_t");
    olua_check_obj(L, 2, &arg1, "olua.size_t");
    olua_check_uint(L, 3, &arg2);

    // void copyfrom(olua::pointer<size_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<size_t> *)arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_size_t_copyfrom4(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;
    olua_size_t *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.size_t");
    olua_check_obj(L, 2, &arg1, "olua.size_t");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // void copyfrom(olua::pointer<size_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<size_t> *)arg1, (size_t)arg2, (size_t)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_size_t_copyfrom(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_obj(L, 2, "olua.size_t"))) {
            // void copyfrom(olua::pointer<size_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_size_t_copyfrom2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.size_t")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<size_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_size_t_copyfrom3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.size_t")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<size_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_size_t_copyfrom4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.size_t")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<size_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_size_t_copyfrom1(L);
        // }
    }

    luaL_error(L, "method 'olua_size_t::copyfrom' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_size_t_fill(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.size_t");
    olua_check_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void fill(const char *data, size_t len)
    self->fill(arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_size_t_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** v */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<size_t> *create(const size_t &v)
    olua::pointer<size_t> *ret = olua_size_t::create((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.size_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_size_t_sub1(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */
    lua_Unsigned arg2 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.size_t");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // olua::pointer<size_t> *sub(size_t from, @optional size_t to)
    olua::pointer<size_t> *ret = self->sub((size_t)arg1, (size_t)arg2);
    int num_ret = olua_push_obj(L, ret, "olua.size_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_size_t_sub2(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.size_t");
    olua_check_uint(L, 2, &arg1);

    // olua::pointer<size_t> *sub(size_t from, @optional size_t to)
    olua::pointer<size_t> *ret = self->sub((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.size_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_size_t_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua::pointer<size_t> *sub(size_t from, @optional size_t to)
            return _olua_size_t_sub2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<size_t> *sub(size_t from, @optional size_t to)
            return _olua_size_t_sub1(L);
        // }
    }

    luaL_error(L, "method 'olua_size_t::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_size_t_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.size_t");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_size_t_tostring1(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.size_t");
    olua_check_uint(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L, (size_t)arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_size_t_tostring2(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.size_t");

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_size_t_tostring(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // if () {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_size_t_tostring2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_size_t_tostring1(L);
        // }
    }

    luaL_error(L, "method 'olua_size_t::tostring' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_size_t_getLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.size_t");

    // @getter @name(length) size_t getLength()
    size_t ret = self->getLength();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_size_t_setLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;
    lua_Unsigned arg1 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.size_t");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(length) void setLength(size_t len)
    self->setLength((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_size_t_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.size_t");

    // @getter const size_t &value()
    const size_t &ret = self->value();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_size_t(lua_State *L)
{
    oluacls_class(L, "olua.size_t", nullptr);
    oluacls_func(L, "__gc", _olua_size_t___gc);
    oluacls_func(L, "__index", _olua_size_t___index);
    oluacls_func(L, "__newindex", _olua_size_t___newindex);
    oluacls_func(L, "__olua_move", _olua_size_t___olua_move);
    oluacls_func(L, "array", _olua_size_t_array);
    oluacls_func(L, "copyfrom", _olua_size_t_copyfrom);
    oluacls_func(L, "fill", _olua_size_t_fill);
    oluacls_func(L, "new", _olua_size_t_create);
    oluacls_func(L, "sub", _olua_size_t_sub);
    oluacls_func(L, "take", _olua_size_t_take);
    oluacls_func(L, "tostring", _olua_size_t_tostring);
    oluacls_prop(L, "length", _olua_size_t_getLength, _olua_size_t_setLength);
    oluacls_prop(L, "value", _olua_size_t_value, nullptr);

    olua_registerluatype<olua_size_t>(L, "olua.size_t");

    return 1;
}
OLUA_END_DECLS

static int _olua_ssize_t___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ssize_t");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_ssize_t___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */

    olua_to_obj(L, 1, &self, "olua.ssize_t");
    olua_check_uint(L, 2, &arg1);

    // ssize_t __index(unsigned int idx)
    ssize_t ret = self->__index((unsigned int)arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ssize_t___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */
    lua_Integer arg2 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.ssize_t");
    olua_check_uint(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // void __newindex(unsigned int idx, const ssize_t &v)
    self->__newindex((unsigned int)arg1, (ssize_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ssize_t___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_ssize_t *)olua_toobj(L, 1, "olua.ssize_t");
    olua_push_obj(L, self, "olua.ssize_t");

    olua_endinvoke(L);

    return 1;
}

static int _olua_ssize_t_array(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // static olua::pointer<ssize_t> *array(size_t len)
    olua::pointer<ssize_t> *ret = olua_ssize_t::array((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.ssize_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ssize_t_copyfrom1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;
    olua_ssize_t *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */
    lua_Unsigned arg4 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.ssize_t");
    olua_check_obj(L, 2, &arg1, "olua.ssize_t");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void copyfrom(olua::pointer<ssize_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<ssize_t> *)arg1, (size_t)arg2, (size_t)arg3, (size_t)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ssize_t_copyfrom2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;
    olua_ssize_t *arg1 = nullptr;       /** obj */

    olua_to_obj(L, 1, &self, "olua.ssize_t");
    olua_check_obj(L, 2, &arg1, "olua.ssize_t");

    // void copyfrom(olua::pointer<ssize_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<ssize_t> *)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ssize_t_copyfrom3(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;
    olua_ssize_t *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.ssize_t");
    olua_check_obj(L, 2, &arg1, "olua.ssize_t");
    olua_check_uint(L, 3, &arg2);

    // void copyfrom(olua::pointer<ssize_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<ssize_t> *)arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ssize_t_copyfrom4(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;
    olua_ssize_t *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.ssize_t");
    olua_check_obj(L, 2, &arg1, "olua.ssize_t");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // void copyfrom(olua::pointer<ssize_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<ssize_t> *)arg1, (size_t)arg2, (size_t)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ssize_t_copyfrom(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_obj(L, 2, "olua.ssize_t"))) {
            // void copyfrom(olua::pointer<ssize_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ssize_t_copyfrom2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.ssize_t")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<ssize_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ssize_t_copyfrom3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.ssize_t")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<ssize_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ssize_t_copyfrom4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.ssize_t")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<ssize_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ssize_t_copyfrom1(L);
        // }
    }

    luaL_error(L, "method 'olua_ssize_t::copyfrom' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ssize_t_fill(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.ssize_t");
    olua_check_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void fill(const char *data, size_t len)
    self->fill(arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ssize_t_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** v */

    olua_check_int(L, 1, &arg1);

    // @name(new) static olua::pointer<ssize_t> *create(const ssize_t &v)
    olua::pointer<ssize_t> *ret = olua_ssize_t::create((ssize_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.ssize_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ssize_t_sub1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */
    lua_Unsigned arg2 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.ssize_t");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // olua::pointer<ssize_t> *sub(size_t from, @optional size_t to)
    olua::pointer<ssize_t> *ret = self->sub((size_t)arg1, (size_t)arg2);
    int num_ret = olua_push_obj(L, ret, "olua.ssize_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ssize_t_sub2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.ssize_t");
    olua_check_uint(L, 2, &arg1);

    // olua::pointer<ssize_t> *sub(size_t from, @optional size_t to)
    olua::pointer<ssize_t> *ret = self->sub((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.ssize_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ssize_t_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua::pointer<ssize_t> *sub(size_t from, @optional size_t to)
            return _olua_ssize_t_sub2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<ssize_t> *sub(size_t from, @optional size_t to)
            return _olua_ssize_t_sub1(L);
        // }
    }

    luaL_error(L, "method 'olua_ssize_t::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ssize_t_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ssize_t");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_ssize_t_tostring1(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.ssize_t");
    olua_check_uint(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L, (size_t)arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_ssize_t_tostring2(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ssize_t");

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_ssize_t_tostring(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // if () {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_ssize_t_tostring2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_ssize_t_tostring1(L);
        // }
    }

    luaL_error(L, "method 'olua_ssize_t::tostring' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ssize_t_getLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ssize_t");

    // @getter @name(length) size_t getLength()
    size_t ret = self->getLength();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ssize_t_setLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;
    lua_Unsigned arg1 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.ssize_t");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(length) void setLength(size_t len)
    self->setLength((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_ssize_t_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ssize_t");

    // @getter const ssize_t &value()
    const ssize_t &ret = self->value();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_ssize_t(lua_State *L)
{
    oluacls_class(L, "olua.ssize_t", nullptr);
    oluacls_func(L, "__gc", _olua_ssize_t___gc);
    oluacls_func(L, "__index", _olua_ssize_t___index);
    oluacls_func(L, "__newindex", _olua_ssize_t___newindex);
    oluacls_func(L, "__olua_move", _olua_ssize_t___olua_move);
    oluacls_func(L, "array", _olua_ssize_t_array);
    oluacls_func(L, "copyfrom", _olua_ssize_t_copyfrom);
    oluacls_func(L, "fill", _olua_ssize_t_fill);
    oluacls_func(L, "new", _olua_ssize_t_create);
    oluacls_func(L, "sub", _olua_ssize_t_sub);
    oluacls_func(L, "take", _olua_ssize_t_take);
    oluacls_func(L, "tostring", _olua_ssize_t_tostring);
    oluacls_prop(L, "length", _olua_ssize_t_getLength, _olua_ssize_t_setLength);
    oluacls_prop(L, "value", _olua_ssize_t_value, nullptr);

    olua_registerluatype<olua_ssize_t>(L, "olua.ssize_t");

    return 1;
}
OLUA_END_DECLS

static int _olua_time_t___gc(lua_State *L)
{
    olua_startinvoke(L);

    olua_time_t *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.time_t");

    // olua_Return __gc(lua_State *L)
    olua_Return ret = self->__gc(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_time_t___index(lua_State *L)
{
    olua_startinvoke(L);

    olua_time_t *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */

    olua_to_obj(L, 1, &self, "olua.time_t");
    olua_check_uint(L, 2, &arg1);

    // time_t __index(unsigned int idx)
    time_t ret = self->__index((unsigned int)arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_time_t___newindex(lua_State *L)
{
    olua_startinvoke(L);

    olua_time_t *self = nullptr;
    lua_Unsigned arg1 = 0;       /** idx */
    lua_Integer arg2 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.time_t");
    olua_check_uint(L, 2, &arg1);
    olua_check_int(L, 3, &arg2);

    // void __newindex(unsigned int idx, const time_t &v)
    self->__newindex((unsigned int)arg1, (time_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_time_t___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (olua_time_t *)olua_toobj(L, 1, "olua.time_t");
    olua_push_obj(L, self, "olua.time_t");

    olua_endinvoke(L);

    return 1;
}

static int _olua_time_t_array(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // static olua::pointer<time_t> *array(size_t len)
    olua::pointer<time_t> *ret = olua_time_t::array((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.time_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_time_t_copyfrom1(lua_State *L)
{
    olua_startinvoke(L);

    olua_time_t *self = nullptr;
    olua_time_t *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */
    lua_Unsigned arg4 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.time_t");
    olua_check_obj(L, 2, &arg1, "olua.time_t");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);
    olua_check_uint(L, 5, &arg4);

    // void copyfrom(olua::pointer<time_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<time_t> *)arg1, (size_t)arg2, (size_t)arg3, (size_t)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _olua_time_t_copyfrom2(lua_State *L)
{
    olua_startinvoke(L);

    olua_time_t *self = nullptr;
    olua_time_t *arg1 = nullptr;       /** obj */

    olua_to_obj(L, 1, &self, "olua.time_t");
    olua_check_obj(L, 2, &arg1, "olua.time_t");

    // void copyfrom(olua::pointer<time_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<time_t> *)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_time_t_copyfrom3(lua_State *L)
{
    olua_startinvoke(L);

    olua_time_t *self = nullptr;
    olua_time_t *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.time_t");
    olua_check_obj(L, 2, &arg1, "olua.time_t");
    olua_check_uint(L, 3, &arg2);

    // void copyfrom(olua::pointer<time_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<time_t> *)arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_time_t_copyfrom4(lua_State *L)
{
    olua_startinvoke(L);

    olua_time_t *self = nullptr;
    olua_time_t *arg1 = nullptr;       /** obj */
    lua_Unsigned arg2 = 0;       /** from */
    lua_Unsigned arg3 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.time_t");
    olua_check_obj(L, 2, &arg1, "olua.time_t");
    olua_check_uint(L, 3, &arg2);
    olua_check_uint(L, 4, &arg3);

    // void copyfrom(olua::pointer<time_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
    self->copyfrom((olua::pointer<time_t> *)arg1, (size_t)arg2, (size_t)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_time_t_copyfrom(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_obj(L, 2, "olua.time_t"))) {
            // void copyfrom(olua::pointer<time_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_time_t_copyfrom2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.time_t")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<time_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_time_t_copyfrom3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.time_t")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<time_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_time_t_copyfrom4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.time_t")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<time_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_time_t_copyfrom1(L);
        // }
    }

    luaL_error(L, "method 'olua_time_t::copyfrom' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_time_t_fill(lua_State *L)
{
    olua_startinvoke(L);

    olua_time_t *self = nullptr;
    const char *arg1 = nullptr;       /** data */
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.time_t");
    olua_check_string(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // void fill(const char *data, size_t len)
    self->fill(arg1, (size_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_time_t_create(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** v */

    olua_check_int(L, 1, &arg1);

    // @name(new) static olua::pointer<time_t> *create(const time_t &v)
    olua::pointer<time_t> *ret = olua_time_t::create((time_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.time_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_time_t_sub1(lua_State *L)
{
    olua_startinvoke(L);

    olua_time_t *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */
    lua_Unsigned arg2 = 0;       /** to */

    olua_to_obj(L, 1, &self, "olua.time_t");
    olua_check_uint(L, 2, &arg1);
    olua_check_uint(L, 3, &arg2);

    // olua::pointer<time_t> *sub(size_t from, @optional size_t to)
    olua::pointer<time_t> *ret = self->sub((size_t)arg1, (size_t)arg2);
    int num_ret = olua_push_obj(L, ret, "olua.time_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_time_t_sub2(lua_State *L)
{
    olua_startinvoke(L);

    olua_time_t *self = nullptr;
    lua_Unsigned arg1 = 0;       /** from */

    olua_to_obj(L, 1, &self, "olua.time_t");
    olua_check_uint(L, 2, &arg1);

    // olua::pointer<time_t> *sub(size_t from, @optional size_t to)
    olua::pointer<time_t> *ret = self->sub((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.time_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_time_t_sub(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua::pointer<time_t> *sub(size_t from, @optional size_t to)
            return _olua_time_t_sub2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<time_t> *sub(size_t from, @optional size_t to)
            return _olua_time_t_sub1(L);
        // }
    }

    luaL_error(L, "method 'olua_time_t::sub' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_time_t_take(lua_State *L)
{
    olua_startinvoke(L);

    olua_time_t *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.time_t");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_time_t_tostring1(lua_State *L)
{
    olua_startinvoke(L);

    olua_time_t *self = nullptr;
    lua_Unsigned arg2 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.time_t");
    olua_check_uint(L, 2, &arg2);

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L, (size_t)arg2);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_time_t_tostring2(lua_State *L)
{
    olua_startinvoke(L);

    olua_time_t *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.time_t");

    // olua_Return tostring(lua_State *L, @optional size_t len)
    olua_Return ret = self->tostring(L);

    olua_endinvoke(L);

    return (int)ret;
}

static int _olua_time_t_tostring(lua_State *L)
{
    int num_args = lua_gettop(L) - 1;

    if (num_args == 0) {
        // if () {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_time_t_tostring2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_time_t_tostring1(L);
        // }
    }

    luaL_error(L, "method 'olua_time_t::tostring' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_time_t_getLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_time_t *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.time_t");

    // @getter @name(length) size_t getLength()
    size_t ret = self->getLength();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_time_t_setLength(lua_State *L)
{
    olua_startinvoke(L);

    olua_time_t *self = nullptr;
    lua_Unsigned arg1 = 0;       /** len */

    olua_to_obj(L, 1, &self, "olua.time_t");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(length) void setLength(size_t len)
    self->setLength((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_time_t_value(lua_State *L)
{
    olua_startinvoke(L);

    olua_time_t *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.time_t");

    // @getter const time_t &value()
    const time_t &ret = self->value();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_time_t(lua_State *L)
{
    oluacls_class(L, "olua.time_t", nullptr);
    oluacls_func(L, "__gc", _olua_time_t___gc);
    oluacls_func(L, "__index", _olua_time_t___index);
    oluacls_func(L, "__newindex", _olua_time_t___newindex);
    oluacls_func(L, "__olua_move", _olua_time_t___olua_move);
    oluacls_func(L, "array", _olua_time_t_array);
    oluacls_func(L, "copyfrom", _olua_time_t_copyfrom);
    oluacls_func(L, "fill", _olua_time_t_fill);
    oluacls_func(L, "new", _olua_time_t_create);
    oluacls_func(L, "sub", _olua_time_t_sub);
    oluacls_func(L, "take", _olua_time_t_take);
    oluacls_func(L, "tostring", _olua_time_t_tostring);
    oluacls_prop(L, "length", _olua_time_t_getLength, _olua_time_t_setLength);
    oluacls_prop(L, "value", _olua_time_t_value, nullptr);

    olua_registerluatype<olua_time_t>(L, "olua.time_t");

    return 1;
}
OLUA_END_DECLS

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_types(lua_State *L)
{
    olua_require(L, "olua.bool", luaopen_olua_bool);
    olua_require(L, "olua.string", luaopen_olua_string);
    olua_require(L, "olua.int8", luaopen_olua_int8);
    olua_require(L, "olua.uint8", luaopen_olua_uint8);
    olua_require(L, "olua.int16", luaopen_olua_int16);
    olua_require(L, "olua.uint16", luaopen_olua_uint16);
    olua_require(L, "olua.int32", luaopen_olua_int32);
    olua_require(L, "olua.uint32", luaopen_olua_uint32);
    olua_require(L, "olua.int64", luaopen_olua_int64);
    olua_require(L, "olua.uint64", luaopen_olua_uint64);
    olua_require(L, "olua.short", luaopen_olua_short);
    olua_require(L, "olua.ushort", luaopen_olua_ushort);
    olua_require(L, "olua.int", luaopen_olua_int);
    olua_require(L, "olua.uint", luaopen_olua_uint);
    olua_require(L, "olua.long", luaopen_olua_long);
    olua_require(L, "olua.ulong", luaopen_olua_ulong);
    olua_require(L, "olua.llong", luaopen_olua_llong);
    olua_require(L, "olua.ullong", luaopen_olua_ullong);
    olua_require(L, "olua.float", luaopen_olua_float);
    olua_require(L, "olua.double", luaopen_olua_double);
    olua_require(L, "olua.ldouble", luaopen_olua_ldouble);
    olua_require(L, "olua.size_t", luaopen_olua_size_t);
    olua_require(L, "olua.ssize_t", luaopen_olua_ssize_t);
    olua_require(L, "olua.time_t", luaopen_olua_time_t);

    return 0;
}
OLUA_END_DECLS
