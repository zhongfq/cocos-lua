#include "xgame/xlua-conv.h"
#include "xgame/xlua.h"

int xluacv_push_bool(lua_State *L, bool value)
{
    lua_pushboolean(L, value);
    return 1;
}

void xluacv_to_bool(lua_State *L, int idx, bool *value)
{
    *value = xlua_checkboolean(L, idx);
}

void xluacv_opt_bool(lua_State *L, int idx, bool *value, bool default_value)
{
    *value = xlua_optboolean(L, idx, default_value);
}

bool xluacv_is_bool(lua_State *L, int idx)
{
    return lua_isboolean(L, idx);
}

int xluacv_push_std_string(lua_State *L, const std::string &value)
{
    lua_pushstring(L, value.c_str());
    return 1;
}

void xluacv_to_std_string(lua_State *L, int idx, std::string *value)
{
    luaL_checktype(L, idx, LUA_TSTRING);
    *value = lua_tostring(L, idx);
}

void xluacv_opt_std_string(lua_State *L, int idx, std::string *value, const std::string &default_value)
{
    *value = luaL_optstring(L, idx, default_value.c_str());
}

bool xluacv_is_std_string(lua_State *L, int idx)
{
    return lua_isstring(L, idx);
}

int xluacv_push_string(lua_State *L, const char *value)
{
    lua_pushstring(L, value);
    return 1;
}

void xluacv_to_string(lua_State *L, int idx, const char **value)
{
    luaL_checktype(L, idx, LUA_TSTRING);
    *value = lua_tostring(L, idx);
}

void xluacv_opt_string(lua_State *L, int idx, const char **value, const char *default_value)
{
    *value = luaL_optstring(L, idx, default_value);
}

bool xluacv_is_string(lua_State *L, int idx)
{
    return lua_isstring(L, idx);
}

int xluacv_push_number(lua_State *L, lua_Number value)
{
    lua_pushnumber(L, value);
    return 1;
}

void xluacv_to_number(lua_State *L, int idx, lua_Number *value)
{
    *value = luaL_checknumber(L, idx);
}

void xluacv_opt_number(lua_State *L, int idx, lua_Number *value, lua_Number default_value)
{
    *value = luaL_optnumber(L, idx, default_value);
}

bool xluacv_is_number(lua_State *L, int idx)
{
    return lua_isnumber(L, idx);
}

int xluacv_push_int(lua_State *L, lua_Integer value)
{
    lua_pushinteger(L, value);
    return 1;
}

void xluacv_to_int(lua_State *L, int idx, lua_Integer *value)
{
    *value = luaL_checkinteger(L, idx);
}

bool xluacv_is_int(lua_State *L, int idx)
{
    return lua_isinteger(L, idx);
}

void xluacv_opt_int(lua_State *L, int idx, lua_Integer *value, lua_Integer default_value)
{
    *value = luaL_optinteger(L, idx, default_value);
}

int xluacv_push_uint(lua_State *L, lua_Unsigned value)
{
    return xluacv_push_int(L, (lua_Integer)value);
}

void xluacv_to_uint(lua_State *L, int idx, lua_Unsigned *value)
{
    *value = (lua_Unsigned)luaL_checkinteger(L, idx);
}

void xluacv_opt_uint(lua_State *L, int idx, lua_Unsigned *value, lua_Unsigned default_value)
{
    *value = (lua_Unsigned)luaL_optinteger(L, idx, (lua_Integer)default_value);
}

bool xluacv_is_uint(lua_State *L, int idx)
{
    return lua_isinteger(L, idx);
}

int xluacv_push_ccdata(lua_State *L, const cocos2d::Data &value)
{
    if (value.isNull()) {
        lua_pushnil(L);
    } else {
        lua_pushlstring(L, (const char *)value.getBytes(), (size_t)value.getSize());
    }
    return 1;
}

int xluacv_push_obj(lua_State *L, void *obj, const char *classname)
{
    xluacls_pushobj(L, obj, classname);
    return 1;
}

void xluacv_to_obj(lua_State *L, int idx, void **value, const char *classname)
{
    *value = xluacls_checkobj(L, idx, classname);
}

bool xluacv_is_obj(lua_State *L, int idx, const char *classname)
{
    return xluacls_isa(L, idx, classname);
}

int xluacv_push_ccobj(lua_State *L, cocos2d::Ref *obj, const char *classname)
{
    xluacls_pushccobj(L, obj, classname);
    return 1;
}

void xluacv_to_ccobj(lua_State *L, int idx, void **value, const char *classname)
{
    *value = xluacls_checkobj(L, idx, classname);
}

bool xluacv_is_ccobj(lua_State *L, int idx, const char *classname)
{
    return xluacls_isa(L, idx, classname);
}
