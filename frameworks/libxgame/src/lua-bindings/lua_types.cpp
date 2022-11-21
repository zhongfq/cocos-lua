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

static int _olua_bool_copyfrom$1(lua_State *L)
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

static int _olua_bool_copyfrom$2(lua_State *L)
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

static int _olua_bool_copyfrom$3(lua_State *L)
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

static int _olua_bool_copyfrom$4(lua_State *L)
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
            return _olua_bool_copyfrom$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.bool")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<bool> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_bool_copyfrom$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.bool")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<bool> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_bool_copyfrom$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.bool")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<bool> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_bool_copyfrom$1(L);
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

static int _olua_bool_create$1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<bool> *create(@optional size_t len)
    olua::pointer<bool> *ret = olua_bool::create((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.bool");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_bool_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @name(new) static olua::pointer<bool> *create(@optional size_t len)
    olua::pointer<bool> *ret = olua_bool::create();
    int num_ret = olua_push_obj(L, ret, "olua.bool");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_bool_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @name(new) static olua::pointer<bool> *create(@optional size_t len)
        return _olua_bool_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 1))) {
            // @name(new) static olua::pointer<bool> *create(@optional size_t len)
            return _olua_bool_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_bool::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_bool_sub$1(lua_State *L)
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

static int _olua_bool_sub$2(lua_State *L)
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
            return _olua_bool_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<bool> *sub(size_t from, @optional size_t to)
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

    olua_to_obj(L, 1, &self, "olua.bool");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_bool_tostring$1(lua_State *L)
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

static int _olua_bool_tostring$2(lua_State *L)
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
            return _olua_bool_tostring$2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_bool_tostring$1(L);
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

static int _olua_bool_getValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.bool");

    // @getter @name(value) const bool &getValue()
    const bool &ret = self->getValue();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_bool_setValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_bool *self = nullptr;
    bool arg1 = false;       /** v */

    olua_to_obj(L, 1, &self, "olua.bool");
    olua_check_bool(L, 2, &arg1);

    // @setter @name(value) void setValue(const bool &v)
    self->setValue(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_bool(lua_State *L)
{
    oluacls_class(L, "olua.bool", nullptr);
    oluacls_func(L, "__gc", _olua_bool___gc);
    oluacls_func(L, "__index", _olua_bool___index);
    oluacls_func(L, "__newindex", _olua_bool___newindex);
    oluacls_func(L, "__olua_move", _olua_bool___olua_move);
    oluacls_func(L, "copyfrom", _olua_bool_copyfrom);
    oluacls_func(L, "fill", _olua_bool_fill);
    oluacls_func(L, "new", _olua_bool_create);
    oluacls_func(L, "sub", _olua_bool_sub);
    oluacls_func(L, "take", _olua_bool_take);
    oluacls_func(L, "tostring", _olua_bool_tostring);
    oluacls_prop(L, "length", _olua_bool_getLength, _olua_bool_setLength);
    oluacls_prop(L, "value", _olua_bool_getValue, _olua_bool_setValue);

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

static int _olua_string_copyfrom$1(lua_State *L)
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

static int _olua_string_copyfrom$2(lua_State *L)
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

static int _olua_string_copyfrom$3(lua_State *L)
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

static int _olua_string_copyfrom$4(lua_State *L)
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
            return _olua_string_copyfrom$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.string")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<std::string> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_string_copyfrom$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.string")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<std::string> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_string_copyfrom$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.string")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<std::string> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_string_copyfrom$1(L);
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

static int _olua_string_create$1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<std::string> *create(@optional size_t len)
    olua::pointer<std::string> *ret = olua_string::create((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.string");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_string_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @name(new) static olua::pointer<std::string> *create(@optional size_t len)
    olua::pointer<std::string> *ret = olua_string::create();
    int num_ret = olua_push_obj(L, ret, "olua.string");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_string_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @name(new) static olua::pointer<std::string> *create(@optional size_t len)
        return _olua_string_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 1))) {
            // @name(new) static olua::pointer<std::string> *create(@optional size_t len)
            return _olua_string_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_string::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_string_sub$1(lua_State *L)
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

static int _olua_string_sub$2(lua_State *L)
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
            return _olua_string_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<std::string> *sub(size_t from, @optional size_t to)
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

    olua_to_obj(L, 1, &self, "olua.string");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_string_tostring$1(lua_State *L)
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

static int _olua_string_tostring$2(lua_State *L)
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
            return _olua_string_tostring$2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_string_tostring$1(L);
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

static int _olua_string_getValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.string");

    // @getter @name(value) const std::string &getValue()
    const std::string &ret = self->getValue();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_string_setValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_string *self = nullptr;
    std::string arg1;       /** v */

    olua_to_obj(L, 1, &self, "olua.string");
    olua_check_std_string(L, 2, &arg1);

    // @setter @name(value) void setValue(const std::string &v)
    self->setValue(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_string(lua_State *L)
{
    oluacls_class(L, "olua.string", nullptr);
    oluacls_func(L, "__gc", _olua_string___gc);
    oluacls_func(L, "__index", _olua_string___index);
    oluacls_func(L, "__newindex", _olua_string___newindex);
    oluacls_func(L, "__olua_move", _olua_string___olua_move);
    oluacls_func(L, "copyfrom", _olua_string_copyfrom);
    oluacls_func(L, "fill", _olua_string_fill);
    oluacls_func(L, "new", _olua_string_create);
    oluacls_func(L, "sub", _olua_string_sub);
    oluacls_func(L, "take", _olua_string_take);
    oluacls_func(L, "tostring", _olua_string_tostring);
    oluacls_prop(L, "length", _olua_string_getLength, _olua_string_setLength);
    oluacls_prop(L, "value", _olua_string_getValue, _olua_string_setValue);

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

static int _olua_int8_copyfrom$1(lua_State *L)
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

static int _olua_int8_copyfrom$2(lua_State *L)
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

static int _olua_int8_copyfrom$3(lua_State *L)
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

static int _olua_int8_copyfrom$4(lua_State *L)
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
            return _olua_int8_copyfrom$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.int8")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<int8_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int8_copyfrom$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.int8")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<int8_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int8_copyfrom$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.int8")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<int8_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int8_copyfrom$1(L);
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

static int _olua_int8_create$1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<int8_t> *create(@optional size_t len)
    olua::pointer<int8_t> *ret = olua_int8::create((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.int8");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int8_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @name(new) static olua::pointer<int8_t> *create(@optional size_t len)
    olua::pointer<int8_t> *ret = olua_int8::create();
    int num_ret = olua_push_obj(L, ret, "olua.int8");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int8_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @name(new) static olua::pointer<int8_t> *create(@optional size_t len)
        return _olua_int8_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 1))) {
            // @name(new) static olua::pointer<int8_t> *create(@optional size_t len)
            return _olua_int8_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_int8::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int8_sub$1(lua_State *L)
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

static int _olua_int8_sub$2(lua_State *L)
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
            return _olua_int8_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<int8_t> *sub(size_t from, @optional size_t to)
            return _olua_int8_sub$1(L);
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

static int _olua_int8_tostring$1(lua_State *L)
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

static int _olua_int8_tostring$2(lua_State *L)
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
            return _olua_int8_tostring$2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_int8_tostring$1(L);
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

static int _olua_int8_getValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int8");

    // @getter @name(value) const int8_t &getValue()
    const int8_t &ret = self->getValue();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int8_setValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_int8 *self = nullptr;
    lua_Integer arg1 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.int8");
    olua_check_int(L, 2, &arg1);

    // @setter @name(value) void setValue(const int8_t &v)
    self->setValue((int8_t)arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_int8(lua_State *L)
{
    oluacls_class(L, "olua.int8", nullptr);
    oluacls_func(L, "__gc", _olua_int8___gc);
    oluacls_func(L, "__index", _olua_int8___index);
    oluacls_func(L, "__newindex", _olua_int8___newindex);
    oluacls_func(L, "__olua_move", _olua_int8___olua_move);
    oluacls_func(L, "copyfrom", _olua_int8_copyfrom);
    oluacls_func(L, "fill", _olua_int8_fill);
    oluacls_func(L, "new", _olua_int8_create);
    oluacls_func(L, "sub", _olua_int8_sub);
    oluacls_func(L, "take", _olua_int8_take);
    oluacls_func(L, "tostring", _olua_int8_tostring);
    oluacls_prop(L, "length", _olua_int8_getLength, _olua_int8_setLength);
    oluacls_prop(L, "value", _olua_int8_getValue, _olua_int8_setValue);

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

static int _olua_uint8_copyfrom$1(lua_State *L)
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

static int _olua_uint8_copyfrom$2(lua_State *L)
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

static int _olua_uint8_copyfrom$3(lua_State *L)
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

static int _olua_uint8_copyfrom$4(lua_State *L)
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
            return _olua_uint8_copyfrom$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.uint8")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<uint8_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint8_copyfrom$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.uint8")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<uint8_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint8_copyfrom$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.uint8")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<uint8_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint8_copyfrom$1(L);
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

static int _olua_uint8_create$1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<uint8_t> *create(@optional size_t len)
    olua::pointer<uint8_t> *ret = olua_uint8::create((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.uint8");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint8_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @name(new) static olua::pointer<uint8_t> *create(@optional size_t len)
    olua::pointer<uint8_t> *ret = olua_uint8::create();
    int num_ret = olua_push_obj(L, ret, "olua.uint8");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint8_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @name(new) static olua::pointer<uint8_t> *create(@optional size_t len)
        return _olua_uint8_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 1))) {
            // @name(new) static olua::pointer<uint8_t> *create(@optional size_t len)
            return _olua_uint8_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint8::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint8_sub$1(lua_State *L)
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

static int _olua_uint8_sub$2(lua_State *L)
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
            return _olua_uint8_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<uint8_t> *sub(size_t from, @optional size_t to)
            return _olua_uint8_sub$1(L);
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

static int _olua_uint8_tostring$1(lua_State *L)
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

static int _olua_uint8_tostring$2(lua_State *L)
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
            return _olua_uint8_tostring$2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_uint8_tostring$1(L);
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

static int _olua_uint8_getValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint8");

    // @getter @name(value) const uint8_t &getValue()
    const uint8_t &ret = self->getValue();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint8_setValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint8 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.uint8");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(value) void setValue(const uint8_t &v)
    self->setValue((uint8_t)arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_uint8(lua_State *L)
{
    oluacls_class(L, "olua.uint8", nullptr);
    oluacls_func(L, "__gc", _olua_uint8___gc);
    oluacls_func(L, "__index", _olua_uint8___index);
    oluacls_func(L, "__newindex", _olua_uint8___newindex);
    oluacls_func(L, "__olua_move", _olua_uint8___olua_move);
    oluacls_func(L, "copyfrom", _olua_uint8_copyfrom);
    oluacls_func(L, "fill", _olua_uint8_fill);
    oluacls_func(L, "new", _olua_uint8_create);
    oluacls_func(L, "sub", _olua_uint8_sub);
    oluacls_func(L, "take", _olua_uint8_take);
    oluacls_func(L, "tostring", _olua_uint8_tostring);
    oluacls_prop(L, "length", _olua_uint8_getLength, _olua_uint8_setLength);
    oluacls_prop(L, "value", _olua_uint8_getValue, _olua_uint8_setValue);

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

static int _olua_int16_copyfrom$1(lua_State *L)
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

static int _olua_int16_copyfrom$2(lua_State *L)
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

static int _olua_int16_copyfrom$3(lua_State *L)
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

static int _olua_int16_copyfrom$4(lua_State *L)
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
            return _olua_int16_copyfrom$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.int16")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<int16_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int16_copyfrom$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.int16")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<int16_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int16_copyfrom$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.int16")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<int16_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int16_copyfrom$1(L);
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

static int _olua_int16_create$1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<int16_t> *create(@optional size_t len)
    olua::pointer<int16_t> *ret = olua_int16::create((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.int16");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int16_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @name(new) static olua::pointer<int16_t> *create(@optional size_t len)
    olua::pointer<int16_t> *ret = olua_int16::create();
    int num_ret = olua_push_obj(L, ret, "olua.int16");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int16_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @name(new) static olua::pointer<int16_t> *create(@optional size_t len)
        return _olua_int16_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 1))) {
            // @name(new) static olua::pointer<int16_t> *create(@optional size_t len)
            return _olua_int16_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_int16::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int16_sub$1(lua_State *L)
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

static int _olua_int16_sub$2(lua_State *L)
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
            return _olua_int16_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<int16_t> *sub(size_t from, @optional size_t to)
            return _olua_int16_sub$1(L);
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

static int _olua_int16_tostring$1(lua_State *L)
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

static int _olua_int16_tostring$2(lua_State *L)
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
            return _olua_int16_tostring$2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_int16_tostring$1(L);
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

static int _olua_int16_getValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int16");

    // @getter @name(value) const int16_t &getValue()
    const int16_t &ret = self->getValue();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int16_setValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_int16 *self = nullptr;
    lua_Integer arg1 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.int16");
    olua_check_int(L, 2, &arg1);

    // @setter @name(value) void setValue(const int16_t &v)
    self->setValue((int16_t)arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_int16(lua_State *L)
{
    oluacls_class(L, "olua.int16", nullptr);
    oluacls_func(L, "__gc", _olua_int16___gc);
    oluacls_func(L, "__index", _olua_int16___index);
    oluacls_func(L, "__newindex", _olua_int16___newindex);
    oluacls_func(L, "__olua_move", _olua_int16___olua_move);
    oluacls_func(L, "copyfrom", _olua_int16_copyfrom);
    oluacls_func(L, "fill", _olua_int16_fill);
    oluacls_func(L, "new", _olua_int16_create);
    oluacls_func(L, "sub", _olua_int16_sub);
    oluacls_func(L, "take", _olua_int16_take);
    oluacls_func(L, "tostring", _olua_int16_tostring);
    oluacls_prop(L, "length", _olua_int16_getLength, _olua_int16_setLength);
    oluacls_prop(L, "value", _olua_int16_getValue, _olua_int16_setValue);

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

static int _olua_uint16_copyfrom$1(lua_State *L)
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

static int _olua_uint16_copyfrom$2(lua_State *L)
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

static int _olua_uint16_copyfrom$3(lua_State *L)
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

static int _olua_uint16_copyfrom$4(lua_State *L)
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
            return _olua_uint16_copyfrom$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.uint16")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<uint16_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint16_copyfrom$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.uint16")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<uint16_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint16_copyfrom$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.uint16")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<uint16_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint16_copyfrom$1(L);
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

static int _olua_uint16_create$1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<uint16_t> *create(@optional size_t len)
    olua::pointer<uint16_t> *ret = olua_uint16::create((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.uint16");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint16_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @name(new) static olua::pointer<uint16_t> *create(@optional size_t len)
    olua::pointer<uint16_t> *ret = olua_uint16::create();
    int num_ret = olua_push_obj(L, ret, "olua.uint16");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint16_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @name(new) static olua::pointer<uint16_t> *create(@optional size_t len)
        return _olua_uint16_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 1))) {
            // @name(new) static olua::pointer<uint16_t> *create(@optional size_t len)
            return _olua_uint16_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint16::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint16_sub$1(lua_State *L)
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

static int _olua_uint16_sub$2(lua_State *L)
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
            return _olua_uint16_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<uint16_t> *sub(size_t from, @optional size_t to)
            return _olua_uint16_sub$1(L);
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

static int _olua_uint16_tostring$1(lua_State *L)
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

static int _olua_uint16_tostring$2(lua_State *L)
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
            return _olua_uint16_tostring$2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_uint16_tostring$1(L);
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

static int _olua_uint16_getValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint16");

    // @getter @name(value) const uint16_t &getValue()
    const uint16_t &ret = self->getValue();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint16_setValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint16 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.uint16");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(value) void setValue(const uint16_t &v)
    self->setValue((uint16_t)arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_uint16(lua_State *L)
{
    oluacls_class(L, "olua.uint16", nullptr);
    oluacls_func(L, "__gc", _olua_uint16___gc);
    oluacls_func(L, "__index", _olua_uint16___index);
    oluacls_func(L, "__newindex", _olua_uint16___newindex);
    oluacls_func(L, "__olua_move", _olua_uint16___olua_move);
    oluacls_func(L, "copyfrom", _olua_uint16_copyfrom);
    oluacls_func(L, "fill", _olua_uint16_fill);
    oluacls_func(L, "new", _olua_uint16_create);
    oluacls_func(L, "sub", _olua_uint16_sub);
    oluacls_func(L, "take", _olua_uint16_take);
    oluacls_func(L, "tostring", _olua_uint16_tostring);
    oluacls_prop(L, "length", _olua_uint16_getLength, _olua_uint16_setLength);
    oluacls_prop(L, "value", _olua_uint16_getValue, _olua_uint16_setValue);

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

static int _olua_int32_copyfrom$1(lua_State *L)
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

static int _olua_int32_copyfrom$2(lua_State *L)
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

static int _olua_int32_copyfrom$3(lua_State *L)
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

static int _olua_int32_copyfrom$4(lua_State *L)
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
            return _olua_int32_copyfrom$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.int32")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<int32_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int32_copyfrom$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.int32")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<int32_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int32_copyfrom$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.int32")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<int32_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int32_copyfrom$1(L);
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

static int _olua_int32_create$1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<int32_t> *create(@optional size_t len)
    olua::pointer<int32_t> *ret = olua_int32::create((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.int32");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int32_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @name(new) static olua::pointer<int32_t> *create(@optional size_t len)
    olua::pointer<int32_t> *ret = olua_int32::create();
    int num_ret = olua_push_obj(L, ret, "olua.int32");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int32_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @name(new) static olua::pointer<int32_t> *create(@optional size_t len)
        return _olua_int32_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 1))) {
            // @name(new) static olua::pointer<int32_t> *create(@optional size_t len)
            return _olua_int32_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_int32::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int32_sub$1(lua_State *L)
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

static int _olua_int32_sub$2(lua_State *L)
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
            return _olua_int32_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<int32_t> *sub(size_t from, @optional size_t to)
            return _olua_int32_sub$1(L);
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

static int _olua_int32_tostring$1(lua_State *L)
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

static int _olua_int32_tostring$2(lua_State *L)
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
            return _olua_int32_tostring$2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_int32_tostring$1(L);
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

static int _olua_int32_getValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int32");

    // @getter @name(value) const int32_t &getValue()
    const int32_t &ret = self->getValue();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int32_setValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_int32 *self = nullptr;
    lua_Integer arg1 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.int32");
    olua_check_int(L, 2, &arg1);

    // @setter @name(value) void setValue(const int32_t &v)
    self->setValue((int32_t)arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_int32(lua_State *L)
{
    oluacls_class(L, "olua.int32", nullptr);
    oluacls_func(L, "__gc", _olua_int32___gc);
    oluacls_func(L, "__index", _olua_int32___index);
    oluacls_func(L, "__newindex", _olua_int32___newindex);
    oluacls_func(L, "__olua_move", _olua_int32___olua_move);
    oluacls_func(L, "copyfrom", _olua_int32_copyfrom);
    oluacls_func(L, "fill", _olua_int32_fill);
    oluacls_func(L, "new", _olua_int32_create);
    oluacls_func(L, "sub", _olua_int32_sub);
    oluacls_func(L, "take", _olua_int32_take);
    oluacls_func(L, "tostring", _olua_int32_tostring);
    oluacls_prop(L, "length", _olua_int32_getLength, _olua_int32_setLength);
    oluacls_prop(L, "value", _olua_int32_getValue, _olua_int32_setValue);

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

static int _olua_uint32_copyfrom$1(lua_State *L)
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

static int _olua_uint32_copyfrom$2(lua_State *L)
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

static int _olua_uint32_copyfrom$3(lua_State *L)
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

static int _olua_uint32_copyfrom$4(lua_State *L)
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
            return _olua_uint32_copyfrom$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.uint32")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<uint32_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint32_copyfrom$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.uint32")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<uint32_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint32_copyfrom$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.uint32")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<uint32_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint32_copyfrom$1(L);
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

static int _olua_uint32_create$1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<uint32_t> *create(@optional size_t len)
    olua::pointer<uint32_t> *ret = olua_uint32::create((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.uint32");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint32_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @name(new) static olua::pointer<uint32_t> *create(@optional size_t len)
    olua::pointer<uint32_t> *ret = olua_uint32::create();
    int num_ret = olua_push_obj(L, ret, "olua.uint32");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint32_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @name(new) static olua::pointer<uint32_t> *create(@optional size_t len)
        return _olua_uint32_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 1))) {
            // @name(new) static olua::pointer<uint32_t> *create(@optional size_t len)
            return _olua_uint32_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint32::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint32_sub$1(lua_State *L)
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

static int _olua_uint32_sub$2(lua_State *L)
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
            return _olua_uint32_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<uint32_t> *sub(size_t from, @optional size_t to)
            return _olua_uint32_sub$1(L);
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

static int _olua_uint32_tostring$1(lua_State *L)
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

static int _olua_uint32_tostring$2(lua_State *L)
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
            return _olua_uint32_tostring$2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_uint32_tostring$1(L);
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

static int _olua_uint32_getValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint32");

    // @getter @name(value) const uint32_t &getValue()
    const uint32_t &ret = self->getValue();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint32_setValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint32 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.uint32");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(value) void setValue(const uint32_t &v)
    self->setValue((uint32_t)arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_uint32(lua_State *L)
{
    oluacls_class(L, "olua.uint32", nullptr);
    oluacls_func(L, "__gc", _olua_uint32___gc);
    oluacls_func(L, "__index", _olua_uint32___index);
    oluacls_func(L, "__newindex", _olua_uint32___newindex);
    oluacls_func(L, "__olua_move", _olua_uint32___olua_move);
    oluacls_func(L, "copyfrom", _olua_uint32_copyfrom);
    oluacls_func(L, "fill", _olua_uint32_fill);
    oluacls_func(L, "new", _olua_uint32_create);
    oluacls_func(L, "sub", _olua_uint32_sub);
    oluacls_func(L, "take", _olua_uint32_take);
    oluacls_func(L, "tostring", _olua_uint32_tostring);
    oluacls_prop(L, "length", _olua_uint32_getLength, _olua_uint32_setLength);
    oluacls_prop(L, "value", _olua_uint32_getValue, _olua_uint32_setValue);

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

static int _olua_int64_copyfrom$1(lua_State *L)
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

static int _olua_int64_copyfrom$2(lua_State *L)
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

static int _olua_int64_copyfrom$3(lua_State *L)
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

static int _olua_int64_copyfrom$4(lua_State *L)
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
            return _olua_int64_copyfrom$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.int64")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<int64_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int64_copyfrom$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.int64")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<int64_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int64_copyfrom$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.int64")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<int64_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int64_copyfrom$1(L);
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

static int _olua_int64_create$1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<int64_t> *create(@optional size_t len)
    olua::pointer<int64_t> *ret = olua_int64::create((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.int64");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int64_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @name(new) static olua::pointer<int64_t> *create(@optional size_t len)
    olua::pointer<int64_t> *ret = olua_int64::create();
    int num_ret = olua_push_obj(L, ret, "olua.int64");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int64_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @name(new) static olua::pointer<int64_t> *create(@optional size_t len)
        return _olua_int64_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 1))) {
            // @name(new) static olua::pointer<int64_t> *create(@optional size_t len)
            return _olua_int64_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_int64::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int64_sub$1(lua_State *L)
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

static int _olua_int64_sub$2(lua_State *L)
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
            return _olua_int64_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<int64_t> *sub(size_t from, @optional size_t to)
            return _olua_int64_sub$1(L);
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

static int _olua_int64_tostring$1(lua_State *L)
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

static int _olua_int64_tostring$2(lua_State *L)
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
            return _olua_int64_tostring$2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_int64_tostring$1(L);
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

static int _olua_int64_getValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int64");

    // @getter @name(value) const int64_t &getValue()
    const int64_t &ret = self->getValue();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int64_setValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_int64 *self = nullptr;
    lua_Integer arg1 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.int64");
    olua_check_int(L, 2, &arg1);

    // @setter @name(value) void setValue(const int64_t &v)
    self->setValue((int64_t)arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_int64(lua_State *L)
{
    oluacls_class(L, "olua.int64", nullptr);
    oluacls_func(L, "__gc", _olua_int64___gc);
    oluacls_func(L, "__index", _olua_int64___index);
    oluacls_func(L, "__newindex", _olua_int64___newindex);
    oluacls_func(L, "__olua_move", _olua_int64___olua_move);
    oluacls_func(L, "copyfrom", _olua_int64_copyfrom);
    oluacls_func(L, "fill", _olua_int64_fill);
    oluacls_func(L, "new", _olua_int64_create);
    oluacls_func(L, "sub", _olua_int64_sub);
    oluacls_func(L, "take", _olua_int64_take);
    oluacls_func(L, "tostring", _olua_int64_tostring);
    oluacls_prop(L, "length", _olua_int64_getLength, _olua_int64_setLength);
    oluacls_prop(L, "value", _olua_int64_getValue, _olua_int64_setValue);

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

static int _olua_uint64_copyfrom$1(lua_State *L)
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

static int _olua_uint64_copyfrom$2(lua_State *L)
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

static int _olua_uint64_copyfrom$3(lua_State *L)
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

static int _olua_uint64_copyfrom$4(lua_State *L)
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
            return _olua_uint64_copyfrom$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.uint64")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<uint64_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint64_copyfrom$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.uint64")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<uint64_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint64_copyfrom$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.uint64")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<uint64_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint64_copyfrom$1(L);
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

static int _olua_uint64_create$1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<uint64_t> *create(@optional size_t len)
    olua::pointer<uint64_t> *ret = olua_uint64::create((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.uint64");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint64_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @name(new) static olua::pointer<uint64_t> *create(@optional size_t len)
    olua::pointer<uint64_t> *ret = olua_uint64::create();
    int num_ret = olua_push_obj(L, ret, "olua.uint64");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint64_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @name(new) static olua::pointer<uint64_t> *create(@optional size_t len)
        return _olua_uint64_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 1))) {
            // @name(new) static olua::pointer<uint64_t> *create(@optional size_t len)
            return _olua_uint64_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint64::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint64_sub$1(lua_State *L)
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

static int _olua_uint64_sub$2(lua_State *L)
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
            return _olua_uint64_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<uint64_t> *sub(size_t from, @optional size_t to)
            return _olua_uint64_sub$1(L);
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

static int _olua_uint64_tostring$1(lua_State *L)
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

static int _olua_uint64_tostring$2(lua_State *L)
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
            return _olua_uint64_tostring$2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_uint64_tostring$1(L);
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

static int _olua_uint64_getValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint64");

    // @getter @name(value) const uint64_t &getValue()
    const uint64_t &ret = self->getValue();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint64_setValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint64 *self = nullptr;
    lua_Unsigned arg1 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.uint64");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(value) void setValue(const uint64_t &v)
    self->setValue((uint64_t)arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_uint64(lua_State *L)
{
    oluacls_class(L, "olua.uint64", nullptr);
    oluacls_func(L, "__gc", _olua_uint64___gc);
    oluacls_func(L, "__index", _olua_uint64___index);
    oluacls_func(L, "__newindex", _olua_uint64___newindex);
    oluacls_func(L, "__olua_move", _olua_uint64___olua_move);
    oluacls_func(L, "copyfrom", _olua_uint64_copyfrom);
    oluacls_func(L, "fill", _olua_uint64_fill);
    oluacls_func(L, "new", _olua_uint64_create);
    oluacls_func(L, "sub", _olua_uint64_sub);
    oluacls_func(L, "take", _olua_uint64_take);
    oluacls_func(L, "tostring", _olua_uint64_tostring);
    oluacls_prop(L, "length", _olua_uint64_getLength, _olua_uint64_setLength);
    oluacls_prop(L, "value", _olua_uint64_getValue, _olua_uint64_setValue);

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

static int _olua_short_copyfrom$1(lua_State *L)
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

static int _olua_short_copyfrom$2(lua_State *L)
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

static int _olua_short_copyfrom$3(lua_State *L)
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

static int _olua_short_copyfrom$4(lua_State *L)
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
            return _olua_short_copyfrom$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.short")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<short> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_short_copyfrom$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.short")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<short> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_short_copyfrom$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.short")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<short> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_short_copyfrom$1(L);
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

static int _olua_short_create$1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<short> *create(@optional size_t len)
    olua::pointer<short> *ret = olua_short::create((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.short");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_short_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @name(new) static olua::pointer<short> *create(@optional size_t len)
    olua::pointer<short> *ret = olua_short::create();
    int num_ret = olua_push_obj(L, ret, "olua.short");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_short_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @name(new) static olua::pointer<short> *create(@optional size_t len)
        return _olua_short_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 1))) {
            // @name(new) static olua::pointer<short> *create(@optional size_t len)
            return _olua_short_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_short::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_short_sub$1(lua_State *L)
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

static int _olua_short_sub$2(lua_State *L)
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
            return _olua_short_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<short> *sub(size_t from, @optional size_t to)
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

    olua_to_obj(L, 1, &self, "olua.short");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_short_tostring$1(lua_State *L)
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

static int _olua_short_tostring$2(lua_State *L)
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
            return _olua_short_tostring$2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_short_tostring$1(L);
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

static int _olua_short_getValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.short");

    // @getter @name(value) const short &getValue()
    const short &ret = self->getValue();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_short_setValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_short *self = nullptr;
    lua_Integer arg1 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.short");
    olua_check_int(L, 2, &arg1);

    // @setter @name(value) void setValue(const short &v)
    self->setValue((short)arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_short(lua_State *L)
{
    oluacls_class(L, "olua.short", nullptr);
    oluacls_func(L, "__gc", _olua_short___gc);
    oluacls_func(L, "__index", _olua_short___index);
    oluacls_func(L, "__newindex", _olua_short___newindex);
    oluacls_func(L, "__olua_move", _olua_short___olua_move);
    oluacls_func(L, "copyfrom", _olua_short_copyfrom);
    oluacls_func(L, "fill", _olua_short_fill);
    oluacls_func(L, "new", _olua_short_create);
    oluacls_func(L, "sub", _olua_short_sub);
    oluacls_func(L, "take", _olua_short_take);
    oluacls_func(L, "tostring", _olua_short_tostring);
    oluacls_prop(L, "length", _olua_short_getLength, _olua_short_setLength);
    oluacls_prop(L, "value", _olua_short_getValue, _olua_short_setValue);

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

static int _olua_ushort_copyfrom$1(lua_State *L)
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

static int _olua_ushort_copyfrom$2(lua_State *L)
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

static int _olua_ushort_copyfrom$3(lua_State *L)
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

static int _olua_ushort_copyfrom$4(lua_State *L)
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
            return _olua_ushort_copyfrom$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.ushort")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<unsigned short> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ushort_copyfrom$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.ushort")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<unsigned short> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ushort_copyfrom$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.ushort")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<unsigned short> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ushort_copyfrom$1(L);
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

static int _olua_ushort_create$1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<unsigned short> *create(@optional size_t len)
    olua::pointer<unsigned short> *ret = olua_ushort::create((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.ushort");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ushort_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @name(new) static olua::pointer<unsigned short> *create(@optional size_t len)
    olua::pointer<unsigned short> *ret = olua_ushort::create();
    int num_ret = olua_push_obj(L, ret, "olua.ushort");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ushort_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @name(new) static olua::pointer<unsigned short> *create(@optional size_t len)
        return _olua_ushort_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 1))) {
            // @name(new) static olua::pointer<unsigned short> *create(@optional size_t len)
            return _olua_ushort_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_ushort::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ushort_sub$1(lua_State *L)
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

static int _olua_ushort_sub$2(lua_State *L)
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
            return _olua_ushort_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<unsigned short> *sub(size_t from, @optional size_t to)
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

    olua_to_obj(L, 1, &self, "olua.ushort");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_ushort_tostring$1(lua_State *L)
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

static int _olua_ushort_tostring$2(lua_State *L)
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
            return _olua_ushort_tostring$2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_ushort_tostring$1(L);
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

static int _olua_ushort_getValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ushort");

    // @getter @name(value) const unsigned short &getValue()
    const unsigned short &ret = self->getValue();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ushort_setValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_ushort *self = nullptr;
    lua_Unsigned arg1 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.ushort");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(value) void setValue(const unsigned short &v)
    self->setValue((unsigned short)arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_ushort(lua_State *L)
{
    oluacls_class(L, "olua.ushort", nullptr);
    oluacls_func(L, "__gc", _olua_ushort___gc);
    oluacls_func(L, "__index", _olua_ushort___index);
    oluacls_func(L, "__newindex", _olua_ushort___newindex);
    oluacls_func(L, "__olua_move", _olua_ushort___olua_move);
    oluacls_func(L, "copyfrom", _olua_ushort_copyfrom);
    oluacls_func(L, "fill", _olua_ushort_fill);
    oluacls_func(L, "new", _olua_ushort_create);
    oluacls_func(L, "sub", _olua_ushort_sub);
    oluacls_func(L, "take", _olua_ushort_take);
    oluacls_func(L, "tostring", _olua_ushort_tostring);
    oluacls_prop(L, "length", _olua_ushort_getLength, _olua_ushort_setLength);
    oluacls_prop(L, "value", _olua_ushort_getValue, _olua_ushort_setValue);

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

static int _olua_int_copyfrom$1(lua_State *L)
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

static int _olua_int_copyfrom$2(lua_State *L)
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

static int _olua_int_copyfrom$3(lua_State *L)
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

static int _olua_int_copyfrom$4(lua_State *L)
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
            return _olua_int_copyfrom$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.int")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<int> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int_copyfrom$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.int")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<int> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int_copyfrom$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.int")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<int> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_int_copyfrom$1(L);
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

static int _olua_int_create$1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<int> *create(@optional size_t len)
    olua::pointer<int> *ret = olua_int::create((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.int");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @name(new) static olua::pointer<int> *create(@optional size_t len)
    olua::pointer<int> *ret = olua_int::create();
    int num_ret = olua_push_obj(L, ret, "olua.int");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @name(new) static olua::pointer<int> *create(@optional size_t len)
        return _olua_int_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 1))) {
            // @name(new) static olua::pointer<int> *create(@optional size_t len)
            return _olua_int_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_int::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_int_sub$1(lua_State *L)
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

static int _olua_int_sub$2(lua_State *L)
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
            return _olua_int_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<int> *sub(size_t from, @optional size_t to)
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

    olua_to_obj(L, 1, &self, "olua.int");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_int_tostring$1(lua_State *L)
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

static int _olua_int_tostring$2(lua_State *L)
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
            return _olua_int_tostring$2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_int_tostring$1(L);
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

static int _olua_int_getValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.int");

    // @getter @name(value) const int &getValue()
    const int &ret = self->getValue();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_int_setValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_int *self = nullptr;
    lua_Integer arg1 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.int");
    olua_check_int(L, 2, &arg1);

    // @setter @name(value) void setValue(const int &v)
    self->setValue((int)arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_int(lua_State *L)
{
    oluacls_class(L, "olua.int", nullptr);
    oluacls_func(L, "__gc", _olua_int___gc);
    oluacls_func(L, "__index", _olua_int___index);
    oluacls_func(L, "__newindex", _olua_int___newindex);
    oluacls_func(L, "__olua_move", _olua_int___olua_move);
    oluacls_func(L, "copyfrom", _olua_int_copyfrom);
    oluacls_func(L, "fill", _olua_int_fill);
    oluacls_func(L, "new", _olua_int_create);
    oluacls_func(L, "sub", _olua_int_sub);
    oluacls_func(L, "take", _olua_int_take);
    oluacls_func(L, "tostring", _olua_int_tostring);
    oluacls_prop(L, "length", _olua_int_getLength, _olua_int_setLength);
    oluacls_prop(L, "value", _olua_int_getValue, _olua_int_setValue);

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

static int _olua_uint_copyfrom$1(lua_State *L)
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

static int _olua_uint_copyfrom$2(lua_State *L)
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

static int _olua_uint_copyfrom$3(lua_State *L)
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

static int _olua_uint_copyfrom$4(lua_State *L)
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
            return _olua_uint_copyfrom$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.uint")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<unsigned int> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint_copyfrom$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.uint")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<unsigned int> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint_copyfrom$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.uint")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<unsigned int> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_uint_copyfrom$1(L);
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

static int _olua_uint_create$1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<unsigned int> *create(@optional size_t len)
    olua::pointer<unsigned int> *ret = olua_uint::create((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.uint");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @name(new) static olua::pointer<unsigned int> *create(@optional size_t len)
    olua::pointer<unsigned int> *ret = olua_uint::create();
    int num_ret = olua_push_obj(L, ret, "olua.uint");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @name(new) static olua::pointer<unsigned int> *create(@optional size_t len)
        return _olua_uint_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 1))) {
            // @name(new) static olua::pointer<unsigned int> *create(@optional size_t len)
            return _olua_uint_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_uint::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_uint_sub$1(lua_State *L)
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

static int _olua_uint_sub$2(lua_State *L)
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
            return _olua_uint_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<unsigned int> *sub(size_t from, @optional size_t to)
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

    olua_to_obj(L, 1, &self, "olua.uint");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_uint_tostring$1(lua_State *L)
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

static int _olua_uint_tostring$2(lua_State *L)
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
            return _olua_uint_tostring$2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_uint_tostring$1(L);
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

static int _olua_uint_getValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.uint");

    // @getter @name(value) const unsigned int &getValue()
    const unsigned int &ret = self->getValue();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_uint_setValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_uint *self = nullptr;
    lua_Unsigned arg1 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.uint");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(value) void setValue(const unsigned int &v)
    self->setValue((unsigned int)arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_uint(lua_State *L)
{
    oluacls_class(L, "olua.uint", nullptr);
    oluacls_func(L, "__gc", _olua_uint___gc);
    oluacls_func(L, "__index", _olua_uint___index);
    oluacls_func(L, "__newindex", _olua_uint___newindex);
    oluacls_func(L, "__olua_move", _olua_uint___olua_move);
    oluacls_func(L, "copyfrom", _olua_uint_copyfrom);
    oluacls_func(L, "fill", _olua_uint_fill);
    oluacls_func(L, "new", _olua_uint_create);
    oluacls_func(L, "sub", _olua_uint_sub);
    oluacls_func(L, "take", _olua_uint_take);
    oluacls_func(L, "tostring", _olua_uint_tostring);
    oluacls_prop(L, "length", _olua_uint_getLength, _olua_uint_setLength);
    oluacls_prop(L, "value", _olua_uint_getValue, _olua_uint_setValue);

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

static int _olua_long_copyfrom$1(lua_State *L)
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

static int _olua_long_copyfrom$2(lua_State *L)
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

static int _olua_long_copyfrom$3(lua_State *L)
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

static int _olua_long_copyfrom$4(lua_State *L)
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
            return _olua_long_copyfrom$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.long")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_long_copyfrom$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.long")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_long_copyfrom$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.long")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_long_copyfrom$1(L);
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

static int _olua_long_create$1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<long> *create(@optional size_t len)
    olua::pointer<long> *ret = olua_long::create((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.long");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_long_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @name(new) static olua::pointer<long> *create(@optional size_t len)
    olua::pointer<long> *ret = olua_long::create();
    int num_ret = olua_push_obj(L, ret, "olua.long");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_long_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @name(new) static olua::pointer<long> *create(@optional size_t len)
        return _olua_long_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 1))) {
            // @name(new) static olua::pointer<long> *create(@optional size_t len)
            return _olua_long_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_long::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_long_sub$1(lua_State *L)
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

static int _olua_long_sub$2(lua_State *L)
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
            return _olua_long_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<long> *sub(size_t from, @optional size_t to)
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

    olua_to_obj(L, 1, &self, "olua.long");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_long_tostring$1(lua_State *L)
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

static int _olua_long_tostring$2(lua_State *L)
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
            return _olua_long_tostring$2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_long_tostring$1(L);
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

static int _olua_long_getValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.long");

    // @getter @name(value) const long &getValue()
    const long &ret = self->getValue();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_long_setValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_long *self = nullptr;
    lua_Integer arg1 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.long");
    olua_check_int(L, 2, &arg1);

    // @setter @name(value) void setValue(const long &v)
    self->setValue((long)arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_long(lua_State *L)
{
    oluacls_class(L, "olua.long", nullptr);
    oluacls_func(L, "__gc", _olua_long___gc);
    oluacls_func(L, "__index", _olua_long___index);
    oluacls_func(L, "__newindex", _olua_long___newindex);
    oluacls_func(L, "__olua_move", _olua_long___olua_move);
    oluacls_func(L, "copyfrom", _olua_long_copyfrom);
    oluacls_func(L, "fill", _olua_long_fill);
    oluacls_func(L, "new", _olua_long_create);
    oluacls_func(L, "sub", _olua_long_sub);
    oluacls_func(L, "take", _olua_long_take);
    oluacls_func(L, "tostring", _olua_long_tostring);
    oluacls_prop(L, "length", _olua_long_getLength, _olua_long_setLength);
    oluacls_prop(L, "value", _olua_long_getValue, _olua_long_setValue);

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

static int _olua_ulong_copyfrom$1(lua_State *L)
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

static int _olua_ulong_copyfrom$2(lua_State *L)
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

static int _olua_ulong_copyfrom$3(lua_State *L)
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

static int _olua_ulong_copyfrom$4(lua_State *L)
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
            return _olua_ulong_copyfrom$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.ulong")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<unsigned long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ulong_copyfrom$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.ulong")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<unsigned long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ulong_copyfrom$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.ulong")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<unsigned long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ulong_copyfrom$1(L);
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

static int _olua_ulong_create$1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<unsigned long> *create(@optional size_t len)
    olua::pointer<unsigned long> *ret = olua_ulong::create((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.ulong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ulong_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @name(new) static olua::pointer<unsigned long> *create(@optional size_t len)
    olua::pointer<unsigned long> *ret = olua_ulong::create();
    int num_ret = olua_push_obj(L, ret, "olua.ulong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ulong_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @name(new) static olua::pointer<unsigned long> *create(@optional size_t len)
        return _olua_ulong_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 1))) {
            // @name(new) static olua::pointer<unsigned long> *create(@optional size_t len)
            return _olua_ulong_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_ulong::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ulong_sub$1(lua_State *L)
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

static int _olua_ulong_sub$2(lua_State *L)
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
            return _olua_ulong_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<unsigned long> *sub(size_t from, @optional size_t to)
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

    olua_to_obj(L, 1, &self, "olua.ulong");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_ulong_tostring$1(lua_State *L)
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

static int _olua_ulong_tostring$2(lua_State *L)
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
            return _olua_ulong_tostring$2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_ulong_tostring$1(L);
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

static int _olua_ulong_getValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ulong");

    // @getter @name(value) const unsigned long &getValue()
    const unsigned long &ret = self->getValue();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ulong_setValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_ulong *self = nullptr;
    lua_Unsigned arg1 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.ulong");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(value) void setValue(const unsigned long &v)
    self->setValue((unsigned long)arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_ulong(lua_State *L)
{
    oluacls_class(L, "olua.ulong", nullptr);
    oluacls_func(L, "__gc", _olua_ulong___gc);
    oluacls_func(L, "__index", _olua_ulong___index);
    oluacls_func(L, "__newindex", _olua_ulong___newindex);
    oluacls_func(L, "__olua_move", _olua_ulong___olua_move);
    oluacls_func(L, "copyfrom", _olua_ulong_copyfrom);
    oluacls_func(L, "fill", _olua_ulong_fill);
    oluacls_func(L, "new", _olua_ulong_create);
    oluacls_func(L, "sub", _olua_ulong_sub);
    oluacls_func(L, "take", _olua_ulong_take);
    oluacls_func(L, "tostring", _olua_ulong_tostring);
    oluacls_prop(L, "length", _olua_ulong_getLength, _olua_ulong_setLength);
    oluacls_prop(L, "value", _olua_ulong_getValue, _olua_ulong_setValue);

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

static int _olua_llong_copyfrom$1(lua_State *L)
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

static int _olua_llong_copyfrom$2(lua_State *L)
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

static int _olua_llong_copyfrom$3(lua_State *L)
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

static int _olua_llong_copyfrom$4(lua_State *L)
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
            return _olua_llong_copyfrom$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.llong")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<long long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_llong_copyfrom$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.llong")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<long long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_llong_copyfrom$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.llong")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<long long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_llong_copyfrom$1(L);
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

static int _olua_llong_create$1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<long long> *create(@optional size_t len)
    olua::pointer<long long> *ret = olua_llong::create((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.llong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_llong_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @name(new) static olua::pointer<long long> *create(@optional size_t len)
    olua::pointer<long long> *ret = olua_llong::create();
    int num_ret = olua_push_obj(L, ret, "olua.llong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_llong_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @name(new) static olua::pointer<long long> *create(@optional size_t len)
        return _olua_llong_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 1))) {
            // @name(new) static olua::pointer<long long> *create(@optional size_t len)
            return _olua_llong_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_llong::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_llong_sub$1(lua_State *L)
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

static int _olua_llong_sub$2(lua_State *L)
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
            return _olua_llong_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<long long> *sub(size_t from, @optional size_t to)
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

    olua_to_obj(L, 1, &self, "olua.llong");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_llong_tostring$1(lua_State *L)
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

static int _olua_llong_tostring$2(lua_State *L)
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
            return _olua_llong_tostring$2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_llong_tostring$1(L);
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

static int _olua_llong_getValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.llong");

    // @getter @name(value) const long long &getValue()
    const long long &ret = self->getValue();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_llong_setValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_llong *self = nullptr;
    lua_Integer arg1 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.llong");
    olua_check_int(L, 2, &arg1);

    // @setter @name(value) void setValue(const long long &v)
    self->setValue((long long)arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_llong(lua_State *L)
{
    oluacls_class(L, "olua.llong", nullptr);
    oluacls_func(L, "__gc", _olua_llong___gc);
    oluacls_func(L, "__index", _olua_llong___index);
    oluacls_func(L, "__newindex", _olua_llong___newindex);
    oluacls_func(L, "__olua_move", _olua_llong___olua_move);
    oluacls_func(L, "copyfrom", _olua_llong_copyfrom);
    oluacls_func(L, "fill", _olua_llong_fill);
    oluacls_func(L, "new", _olua_llong_create);
    oluacls_func(L, "sub", _olua_llong_sub);
    oluacls_func(L, "take", _olua_llong_take);
    oluacls_func(L, "tostring", _olua_llong_tostring);
    oluacls_prop(L, "length", _olua_llong_getLength, _olua_llong_setLength);
    oluacls_prop(L, "value", _olua_llong_getValue, _olua_llong_setValue);

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

static int _olua_ullong_copyfrom$1(lua_State *L)
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

static int _olua_ullong_copyfrom$2(lua_State *L)
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

static int _olua_ullong_copyfrom$3(lua_State *L)
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

static int _olua_ullong_copyfrom$4(lua_State *L)
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
            return _olua_ullong_copyfrom$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.ullong")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<unsigned long long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ullong_copyfrom$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.ullong")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<unsigned long long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ullong_copyfrom$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.ullong")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<unsigned long long> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ullong_copyfrom$1(L);
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

static int _olua_ullong_create$1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<unsigned long long> *create(@optional size_t len)
    olua::pointer<unsigned long long> *ret = olua_ullong::create((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.ullong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ullong_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @name(new) static olua::pointer<unsigned long long> *create(@optional size_t len)
    olua::pointer<unsigned long long> *ret = olua_ullong::create();
    int num_ret = olua_push_obj(L, ret, "olua.ullong");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ullong_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @name(new) static olua::pointer<unsigned long long> *create(@optional size_t len)
        return _olua_ullong_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 1))) {
            // @name(new) static olua::pointer<unsigned long long> *create(@optional size_t len)
            return _olua_ullong_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_ullong::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ullong_sub$1(lua_State *L)
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

static int _olua_ullong_sub$2(lua_State *L)
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
            return _olua_ullong_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<unsigned long long> *sub(size_t from, @optional size_t to)
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

    olua_to_obj(L, 1, &self, "olua.ullong");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_ullong_tostring$1(lua_State *L)
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

static int _olua_ullong_tostring$2(lua_State *L)
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
            return _olua_ullong_tostring$2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_ullong_tostring$1(L);
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

static int _olua_ullong_getValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ullong");

    // @getter @name(value) const unsigned long long &getValue()
    const unsigned long long &ret = self->getValue();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ullong_setValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_ullong *self = nullptr;
    lua_Unsigned arg1 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.ullong");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(value) void setValue(const unsigned long long &v)
    self->setValue((unsigned long long)arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_ullong(lua_State *L)
{
    oluacls_class(L, "olua.ullong", nullptr);
    oluacls_func(L, "__gc", _olua_ullong___gc);
    oluacls_func(L, "__index", _olua_ullong___index);
    oluacls_func(L, "__newindex", _olua_ullong___newindex);
    oluacls_func(L, "__olua_move", _olua_ullong___olua_move);
    oluacls_func(L, "copyfrom", _olua_ullong_copyfrom);
    oluacls_func(L, "fill", _olua_ullong_fill);
    oluacls_func(L, "new", _olua_ullong_create);
    oluacls_func(L, "sub", _olua_ullong_sub);
    oluacls_func(L, "take", _olua_ullong_take);
    oluacls_func(L, "tostring", _olua_ullong_tostring);
    oluacls_prop(L, "length", _olua_ullong_getLength, _olua_ullong_setLength);
    oluacls_prop(L, "value", _olua_ullong_getValue, _olua_ullong_setValue);

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

static int _olua_float_copyfrom$1(lua_State *L)
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

static int _olua_float_copyfrom$2(lua_State *L)
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

static int _olua_float_copyfrom$3(lua_State *L)
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

static int _olua_float_copyfrom$4(lua_State *L)
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
            return _olua_float_copyfrom$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.float")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<float> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_float_copyfrom$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.float")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<float> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_float_copyfrom$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.float")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<float> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_float_copyfrom$1(L);
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

static int _olua_float_create$1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<float> *create(@optional size_t len)
    olua::pointer<float> *ret = olua_float::create((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.float");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_float_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @name(new) static olua::pointer<float> *create(@optional size_t len)
    olua::pointer<float> *ret = olua_float::create();
    int num_ret = olua_push_obj(L, ret, "olua.float");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_float_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @name(new) static olua::pointer<float> *create(@optional size_t len)
        return _olua_float_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 1))) {
            // @name(new) static olua::pointer<float> *create(@optional size_t len)
            return _olua_float_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_float::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_float_sub$1(lua_State *L)
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

static int _olua_float_sub$2(lua_State *L)
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
            return _olua_float_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<float> *sub(size_t from, @optional size_t to)
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

    olua_to_obj(L, 1, &self, "olua.float");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_float_tostring$1(lua_State *L)
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

static int _olua_float_tostring$2(lua_State *L)
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
            return _olua_float_tostring$2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_float_tostring$1(L);
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

static int _olua_float_getValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.float");

    // @getter @name(value) const float &getValue()
    const float &ret = self->getValue();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_float_setValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_float *self = nullptr;
    lua_Number arg1 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.float");
    olua_check_number(L, 2, &arg1);

    // @setter @name(value) void setValue(const float &v)
    self->setValue((float)arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_float(lua_State *L)
{
    oluacls_class(L, "olua.float", nullptr);
    oluacls_func(L, "__gc", _olua_float___gc);
    oluacls_func(L, "__index", _olua_float___index);
    oluacls_func(L, "__newindex", _olua_float___newindex);
    oluacls_func(L, "__olua_move", _olua_float___olua_move);
    oluacls_func(L, "copyfrom", _olua_float_copyfrom);
    oluacls_func(L, "fill", _olua_float_fill);
    oluacls_func(L, "new", _olua_float_create);
    oluacls_func(L, "sub", _olua_float_sub);
    oluacls_func(L, "take", _olua_float_take);
    oluacls_func(L, "tostring", _olua_float_tostring);
    oluacls_prop(L, "length", _olua_float_getLength, _olua_float_setLength);
    oluacls_prop(L, "value", _olua_float_getValue, _olua_float_setValue);

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

static int _olua_double_copyfrom$1(lua_State *L)
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

static int _olua_double_copyfrom$2(lua_State *L)
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

static int _olua_double_copyfrom$3(lua_State *L)
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

static int _olua_double_copyfrom$4(lua_State *L)
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
            return _olua_double_copyfrom$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.double")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<double> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_double_copyfrom$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.double")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<double> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_double_copyfrom$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.double")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<double> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_double_copyfrom$1(L);
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

static int _olua_double_create$1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<double> *create(@optional size_t len)
    olua::pointer<double> *ret = olua_double::create((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.double");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_double_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @name(new) static olua::pointer<double> *create(@optional size_t len)
    olua::pointer<double> *ret = olua_double::create();
    int num_ret = olua_push_obj(L, ret, "olua.double");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_double_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @name(new) static olua::pointer<double> *create(@optional size_t len)
        return _olua_double_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 1))) {
            // @name(new) static olua::pointer<double> *create(@optional size_t len)
            return _olua_double_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_double::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_double_sub$1(lua_State *L)
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

static int _olua_double_sub$2(lua_State *L)
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
            return _olua_double_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<double> *sub(size_t from, @optional size_t to)
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

    olua_to_obj(L, 1, &self, "olua.double");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_double_tostring$1(lua_State *L)
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

static int _olua_double_tostring$2(lua_State *L)
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
            return _olua_double_tostring$2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_double_tostring$1(L);
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

static int _olua_double_getValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.double");

    // @getter @name(value) const double &getValue()
    const double &ret = self->getValue();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_double_setValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_double *self = nullptr;
    lua_Number arg1 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.double");
    olua_check_number(L, 2, &arg1);

    // @setter @name(value) void setValue(const double &v)
    self->setValue((double)arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_double(lua_State *L)
{
    oluacls_class(L, "olua.double", nullptr);
    oluacls_func(L, "__gc", _olua_double___gc);
    oluacls_func(L, "__index", _olua_double___index);
    oluacls_func(L, "__newindex", _olua_double___newindex);
    oluacls_func(L, "__olua_move", _olua_double___olua_move);
    oluacls_func(L, "copyfrom", _olua_double_copyfrom);
    oluacls_func(L, "fill", _olua_double_fill);
    oluacls_func(L, "new", _olua_double_create);
    oluacls_func(L, "sub", _olua_double_sub);
    oluacls_func(L, "take", _olua_double_take);
    oluacls_func(L, "tostring", _olua_double_tostring);
    oluacls_prop(L, "length", _olua_double_getLength, _olua_double_setLength);
    oluacls_prop(L, "value", _olua_double_getValue, _olua_double_setValue);

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

static int _olua_ldouble_copyfrom$1(lua_State *L)
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

static int _olua_ldouble_copyfrom$2(lua_State *L)
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

static int _olua_ldouble_copyfrom$3(lua_State *L)
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

static int _olua_ldouble_copyfrom$4(lua_State *L)
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
            return _olua_ldouble_copyfrom$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.ldouble")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<long double> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ldouble_copyfrom$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.ldouble")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<long double> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ldouble_copyfrom$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.ldouble")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<long double> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ldouble_copyfrom$1(L);
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

static int _olua_ldouble_create$1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<long double> *create(@optional size_t len)
    olua::pointer<long double> *ret = olua_ldouble::create((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.ldouble");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ldouble_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @name(new) static olua::pointer<long double> *create(@optional size_t len)
    olua::pointer<long double> *ret = olua_ldouble::create();
    int num_ret = olua_push_obj(L, ret, "olua.ldouble");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ldouble_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @name(new) static olua::pointer<long double> *create(@optional size_t len)
        return _olua_ldouble_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 1))) {
            // @name(new) static olua::pointer<long double> *create(@optional size_t len)
            return _olua_ldouble_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_ldouble::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ldouble_sub$1(lua_State *L)
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

static int _olua_ldouble_sub$2(lua_State *L)
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
            return _olua_ldouble_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<long double> *sub(size_t from, @optional size_t to)
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

    olua_to_obj(L, 1, &self, "olua.ldouble");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_ldouble_tostring$1(lua_State *L)
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

static int _olua_ldouble_tostring$2(lua_State *L)
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
            return _olua_ldouble_tostring$2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_ldouble_tostring$1(L);
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

static int _olua_ldouble_getValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ldouble");

    // @getter @name(value) const long double &getValue()
    const long double &ret = self->getValue();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ldouble_setValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_ldouble *self = nullptr;
    lua_Number arg1 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.ldouble");
    olua_check_number(L, 2, &arg1);

    // @setter @name(value) void setValue(const long double &v)
    self->setValue((long double)arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_ldouble(lua_State *L)
{
    oluacls_class(L, "olua.ldouble", nullptr);
    oluacls_func(L, "__gc", _olua_ldouble___gc);
    oluacls_func(L, "__index", _olua_ldouble___index);
    oluacls_func(L, "__newindex", _olua_ldouble___newindex);
    oluacls_func(L, "__olua_move", _olua_ldouble___olua_move);
    oluacls_func(L, "copyfrom", _olua_ldouble_copyfrom);
    oluacls_func(L, "fill", _olua_ldouble_fill);
    oluacls_func(L, "new", _olua_ldouble_create);
    oluacls_func(L, "sub", _olua_ldouble_sub);
    oluacls_func(L, "take", _olua_ldouble_take);
    oluacls_func(L, "tostring", _olua_ldouble_tostring);
    oluacls_prop(L, "length", _olua_ldouble_getLength, _olua_ldouble_setLength);
    oluacls_prop(L, "value", _olua_ldouble_getValue, _olua_ldouble_setValue);

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

static int _olua_size_t_copyfrom$1(lua_State *L)
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

static int _olua_size_t_copyfrom$2(lua_State *L)
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

static int _olua_size_t_copyfrom$3(lua_State *L)
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

static int _olua_size_t_copyfrom$4(lua_State *L)
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
            return _olua_size_t_copyfrom$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.size_t")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<size_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_size_t_copyfrom$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.size_t")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<size_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_size_t_copyfrom$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.size_t")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<size_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_size_t_copyfrom$1(L);
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

static int _olua_size_t_create$1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<size_t> *create(@optional size_t len)
    olua::pointer<size_t> *ret = olua_size_t::create((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.size_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_size_t_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @name(new) static olua::pointer<size_t> *create(@optional size_t len)
    olua::pointer<size_t> *ret = olua_size_t::create();
    int num_ret = olua_push_obj(L, ret, "olua.size_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_size_t_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @name(new) static olua::pointer<size_t> *create(@optional size_t len)
        return _olua_size_t_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 1))) {
            // @name(new) static olua::pointer<size_t> *create(@optional size_t len)
            return _olua_size_t_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_size_t::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_size_t_sub$1(lua_State *L)
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

static int _olua_size_t_sub$2(lua_State *L)
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
            return _olua_size_t_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<size_t> *sub(size_t from, @optional size_t to)
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

    olua_to_obj(L, 1, &self, "olua.size_t");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_size_t_tostring$1(lua_State *L)
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

static int _olua_size_t_tostring$2(lua_State *L)
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
            return _olua_size_t_tostring$2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_size_t_tostring$1(L);
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

static int _olua_size_t_getValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.size_t");

    // @getter @name(value) const size_t &getValue()
    const size_t &ret = self->getValue();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_size_t_setValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_size_t *self = nullptr;
    lua_Unsigned arg1 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.size_t");
    olua_check_uint(L, 2, &arg1);

    // @setter @name(value) void setValue(const size_t &v)
    self->setValue((size_t)arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_size_t(lua_State *L)
{
    oluacls_class(L, "olua.size_t", nullptr);
    oluacls_func(L, "__gc", _olua_size_t___gc);
    oluacls_func(L, "__index", _olua_size_t___index);
    oluacls_func(L, "__newindex", _olua_size_t___newindex);
    oluacls_func(L, "__olua_move", _olua_size_t___olua_move);
    oluacls_func(L, "copyfrom", _olua_size_t_copyfrom);
    oluacls_func(L, "fill", _olua_size_t_fill);
    oluacls_func(L, "new", _olua_size_t_create);
    oluacls_func(L, "sub", _olua_size_t_sub);
    oluacls_func(L, "take", _olua_size_t_take);
    oluacls_func(L, "tostring", _olua_size_t_tostring);
    oluacls_prop(L, "length", _olua_size_t_getLength, _olua_size_t_setLength);
    oluacls_prop(L, "value", _olua_size_t_getValue, _olua_size_t_setValue);

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

static int _olua_ssize_t_copyfrom$1(lua_State *L)
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

static int _olua_ssize_t_copyfrom$2(lua_State *L)
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

static int _olua_ssize_t_copyfrom$3(lua_State *L)
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

static int _olua_ssize_t_copyfrom$4(lua_State *L)
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
            return _olua_ssize_t_copyfrom$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.ssize_t")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<ssize_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ssize_t_copyfrom$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.ssize_t")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<ssize_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ssize_t_copyfrom$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.ssize_t")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<ssize_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_ssize_t_copyfrom$1(L);
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

static int _olua_ssize_t_create$1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<ssize_t> *create(@optional size_t len)
    olua::pointer<ssize_t> *ret = olua_ssize_t::create((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.ssize_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ssize_t_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @name(new) static olua::pointer<ssize_t> *create(@optional size_t len)
    olua::pointer<ssize_t> *ret = olua_ssize_t::create();
    int num_ret = olua_push_obj(L, ret, "olua.ssize_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ssize_t_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @name(new) static olua::pointer<ssize_t> *create(@optional size_t len)
        return _olua_ssize_t_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 1))) {
            // @name(new) static olua::pointer<ssize_t> *create(@optional size_t len)
            return _olua_ssize_t_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_ssize_t::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_ssize_t_sub$1(lua_State *L)
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

static int _olua_ssize_t_sub$2(lua_State *L)
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
            return _olua_ssize_t_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<ssize_t> *sub(size_t from, @optional size_t to)
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

    olua_to_obj(L, 1, &self, "olua.ssize_t");

    // void take()
    self->take();

    olua_endinvoke(L);

    return 0;
}

static int _olua_ssize_t_tostring$1(lua_State *L)
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

static int _olua_ssize_t_tostring$2(lua_State *L)
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
            return _olua_ssize_t_tostring$2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_ssize_t_tostring$1(L);
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

static int _olua_ssize_t_getValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.ssize_t");

    // @getter @name(value) const ssize_t &getValue()
    const ssize_t &ret = self->getValue();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_ssize_t_setValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_ssize_t *self = nullptr;
    lua_Integer arg1 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.ssize_t");
    olua_check_int(L, 2, &arg1);

    // @setter @name(value) void setValue(const ssize_t &v)
    self->setValue((ssize_t)arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_ssize_t(lua_State *L)
{
    oluacls_class(L, "olua.ssize_t", nullptr);
    oluacls_func(L, "__gc", _olua_ssize_t___gc);
    oluacls_func(L, "__index", _olua_ssize_t___index);
    oluacls_func(L, "__newindex", _olua_ssize_t___newindex);
    oluacls_func(L, "__olua_move", _olua_ssize_t___olua_move);
    oluacls_func(L, "copyfrom", _olua_ssize_t_copyfrom);
    oluacls_func(L, "fill", _olua_ssize_t_fill);
    oluacls_func(L, "new", _olua_ssize_t_create);
    oluacls_func(L, "sub", _olua_ssize_t_sub);
    oluacls_func(L, "take", _olua_ssize_t_take);
    oluacls_func(L, "tostring", _olua_ssize_t_tostring);
    oluacls_prop(L, "length", _olua_ssize_t_getLength, _olua_ssize_t_setLength);
    oluacls_prop(L, "value", _olua_ssize_t_getValue, _olua_ssize_t_setValue);

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

static int _olua_time_t_copyfrom$1(lua_State *L)
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

static int _olua_time_t_copyfrom$2(lua_State *L)
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

static int _olua_time_t_copyfrom$3(lua_State *L)
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

static int _olua_time_t_copyfrom$4(lua_State *L)
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
            return _olua_time_t_copyfrom$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_obj(L, 2, "olua.time_t")) && (olua_is_uint(L, 3))) {
            // void copyfrom(olua::pointer<time_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_time_t_copyfrom$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_obj(L, 2, "olua.time_t")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4))) {
            // void copyfrom(olua::pointer<time_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_time_t_copyfrom$4(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_obj(L, 2, "olua.time_t")) && (olua_is_uint(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // void copyfrom(olua::pointer<time_t> *obj, @optional size_t from, @optional size_t len, @optional size_t to)
            return _olua_time_t_copyfrom$1(L);
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

static int _olua_time_t_create$1(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** len */

    olua_check_uint(L, 1, &arg1);

    // @name(new) static olua::pointer<time_t> *create(@optional size_t len)
    olua::pointer<time_t> *ret = olua_time_t::create((size_t)arg1);
    int num_ret = olua_push_obj(L, ret, "olua.time_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_time_t_create$2(lua_State *L)
{
    olua_startinvoke(L);

    // @name(new) static olua::pointer<time_t> *create(@optional size_t len)
    olua::pointer<time_t> *ret = olua_time_t::create();
    int num_ret = olua_push_obj(L, ret, "olua.time_t");

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_time_t_create(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // @name(new) static olua::pointer<time_t> *create(@optional size_t len)
        return _olua_time_t_create$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 1))) {
            // @name(new) static olua::pointer<time_t> *create(@optional size_t len)
            return _olua_time_t_create$1(L);
        // }
    }

    luaL_error(L, "method 'olua_time_t::create' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_time_t_sub$1(lua_State *L)
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

static int _olua_time_t_sub$2(lua_State *L)
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
            return _olua_time_t_sub$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // olua::pointer<time_t> *sub(size_t from, @optional size_t to)
            return _olua_time_t_sub$1(L);
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

static int _olua_time_t_tostring$1(lua_State *L)
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

static int _olua_time_t_tostring$2(lua_State *L)
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
            return _olua_time_t_tostring$2(L);
        // }
    }

    if (num_args == 1) {
        // if ((olua_is_uint(L, 2))) {
            // olua_Return tostring(lua_State *L, @optional size_t len)
            return _olua_time_t_tostring$1(L);
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

static int _olua_time_t_getValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_time_t *self = nullptr;

    olua_to_obj(L, 1, &self, "olua.time_t");

    // @getter @name(value) const time_t &getValue()
    const time_t &ret = self->getValue();
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_time_t_setValue(lua_State *L)
{
    olua_startinvoke(L);

    olua_time_t *self = nullptr;
    lua_Integer arg1 = 0;       /** v */

    olua_to_obj(L, 1, &self, "olua.time_t");
    olua_check_int(L, 2, &arg1);

    // @setter @name(value) void setValue(const time_t &v)
    self->setValue((time_t)arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_olua_time_t(lua_State *L)
{
    oluacls_class(L, "olua.time_t", nullptr);
    oluacls_func(L, "__gc", _olua_time_t___gc);
    oluacls_func(L, "__index", _olua_time_t___index);
    oluacls_func(L, "__newindex", _olua_time_t___newindex);
    oluacls_func(L, "__olua_move", _olua_time_t___olua_move);
    oluacls_func(L, "copyfrom", _olua_time_t_copyfrom);
    oluacls_func(L, "fill", _olua_time_t_fill);
    oluacls_func(L, "new", _olua_time_t_create);
    oluacls_func(L, "sub", _olua_time_t_sub);
    oluacls_func(L, "take", _olua_time_t_take);
    oluacls_func(L, "tostring", _olua_time_t_tostring);
    oluacls_prop(L, "length", _olua_time_t_getLength, _olua_time_t_setLength);
    oluacls_prop(L, "value", _olua_time_t_getValue, _olua_time_t_setValue);

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
