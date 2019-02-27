#ifndef __XLUA_CONV_H__
#define __XLUA_CONV_H__

#include "xgame/xdef.h"
#include "lua.hpp"

#include "base/CCRef.h"

static void xluacv_push_bool(lua_State *L, bool value)
{
    lua_pushboolean(L, value);
}

static bool xluacv_to_bool(lua_State *L, int idx)
{
    return lua_toboolean(L, idx);
}

static void xluacv_push_std_string(lua_State *L, const std::string &value)
{
    lua_pushstring(L, value.c_str());
}

static const std::string xluacv_to_std_string(lua_State *L, int idx)
{
    return luaL_checkstring(L, idx);
}

static void xluacv_push_string(lua_State *L, const char *value)
{
    lua_pushstring(L, value);
}

static const char *xluacv_to_string(lua_State *L, int idx)
{
    return luaL_checkstring(L, idx);
}

static void xluacv_push_number(lua_State *L, lua_Number value)
{
    lua_pushnumber(L, value);
}

static void xluacv_push_int(lua_State *L, lua_Integer value)
{
    lua_pushinteger(L, value);
}

static void xluacv_push_uint(lua_State *L, lua_Unsigned value)
{
    lua_pushinteger(L, (lua_Integer)value);
}

#endif
