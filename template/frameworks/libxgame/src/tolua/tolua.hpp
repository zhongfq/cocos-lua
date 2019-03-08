#ifndef __TOLUA_HPP__
#define __TOLUA_HPP__

#include "tolua/tolua.h"

#include <string>
#include <functional>

static inline int tolua_push_std_string(lua_State *L, const std::string &value)
{
    lua_pushstring(L, value.c_str());
    return 1;
}

static inline void tolua_check_std_string(lua_State *L, int idx, std::string *value)
{
    luaL_checktype(L, idx, LUA_TSTRING);
    *value = lua_tostring(L, idx);
}

static inline void tolua_opt_std_string(lua_State *L, int idx, std::string *value, const std::string &def)
{
    *value = luaL_optstring(L, idx, def.c_str());
}

static inline bool tolua_is_std_string(lua_State *L, int idx)
{
    return lua_isstring(L, idx);
}

static inline bool tolua_is_std_function(lua_State *L, int idx)
{
    return lua_isfunction(L, idx);
}

template <typename T> void tolua_registerluatype(lua_State *L, const char *cls)
{
    const char *type = typeid(T).name();
    lua_pushstring(L, type);                            // L: type
    lua_pushstring(L, cls);                             // L: type cls
    lua_pushvalue(L, -2);                               // L: type cls type
    if (lua_rawget(L, LUA_REGISTRYINDEX) == LUA_TNIL) { // L: type cls value
        lua_pop(L, 1);                                  // L: type cls
        lua_rawset(L, LUA_REGISTRYINDEX);               // L:
    } else {                                            // L: type cls value
        if (!lua_rawequal(L, -1, -2)) {
            luaL_error(L, "lua type conflict: %s=%s", type, cls);
        }
        lua_pop(L, 3);
    }
}

template <typename T> const char *tolua_getluatype(lua_State *L, T *obj, const char *cls)
{
    if (obj) {
        const char *type = typeid(*obj).name();
        lua_pushstring(L, type);
        if (lua_rawget(L, LUA_REGISTRYINDEX) == LUA_TSTRING) {
            cls = lua_tostring(L, -1);
        }
        lua_pop(L, 1);
    }
    
    return cls;
}

#endif
