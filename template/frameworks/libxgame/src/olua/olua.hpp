#ifndef __OLUA_HPP__
#define __OLUA_HPP__

#include "olua/olua.h"

#include <string>
#include <functional>
#include <set>
#include <vector>

template <typename T> void olua_registerluatype(lua_State *L, const char *cls)
{
    const char *type = typeid(T).name();
    lua_pushstring(L, type);                            // L: type
    lua_pushstring(L, cls);                             // L: type cls
    lua_pushvalue(L, -2);                               // L: type cls type
    if (lua_rawget(L, LUA_REGISTRYINDEX) == LUA_TNIL) { // L: type cls value
        lua_pop(L, 1);                                  // L: type cls
        lua_rawset(L, LUA_REGISTRYINDEX);               // L:                 REGISTRY[type] = cls
    } else {                                            // L: type cls value
        if (!lua_rawequal(L, -1, -2)) {
            luaL_error(L, "lua type conflict: %s=%s", type, cls);
        }
        lua_pop(L, 3);
    }
}

template <typename T> const char *olua_getluatype(lua_State *L, T *obj, const char *cls)
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

static inline const char *olua_getluatype(lua_State *L, void *obj, const char *cls)
{
    return cls;
}

template <typename T> int olua_push_cppobj(lua_State *L, T* value, const char *cls)
{
    cls = olua_getluatype(L, value, cls);
#ifdef TOLUA_REPORT_PUSH_STATUS
    int status = olua_pushobj(L, value, cls);
    TOLUA_REPORT_PUSH_STATUS(L, value, status);
#else
    olua_pushobj(L, value, cls);
#endif
    return 1;
}

static inline void olua_to_cppobj(lua_State *L, int idx, void **value, const char *cls)
{
    olua_to_obj(L, idx, value, cls);
}

static inline void olua_check_cppobj(lua_State *L, int idx, void **value, const char *cls)
{
    olua_check_obj(L, idx, value, cls);
}

static inline bool olua_is_cppobj(lua_State *L, int idx, const char *cls)
{
    return olua_is_obj(L, idx, cls);
}

template <typename T> int olua_push_std_set(lua_State *L, const std::set<T*> &value, const char *cls)
{
    int i = 1;
    lua_createtable(L, (int)value.size(), 0);
    for (const auto obj : value) {
        if (obj) {
            olua_push_cppobj(L, obj, cls);
            lua_rawseti(L, -2, i++);
        }
    }
    return 1;
}

template <typename T> void olua_check_std_set(lua_State *L, int idx, std::set<T*> &value, const char *cls)
{
    luaL_checktype(L, idx, LUA_TTABLE);
    size_t total = lua_rawlen(L, idx);
    for (int i = 1; i <= total; i++) {
        T* obj;
        lua_rawgeti(L, idx, i);
        olua_check_cppobj(L, -1, (void **)&obj, cls);
        value.insert(obj);
        lua_pop(L, 1);
    }
}

static inline bool olua_is_std_set(lua_State *L, int idx)
{
    return lua_istable(L, idx);
}

template <typename T> int olua_push_std_vector(lua_State *L, const std::vector<T*> &v, const char *cls)
{
    lua_newtable(L);
    int i = 1;
    for (const auto obj : v) {
        if (obj) {
            olua_push_cppobj(L, obj, cls);
            lua_rawseti(L, -2, i++);
        }
    }
    return 1;
}

template <typename T> void olua_check_std_vector(lua_State *L, int idx, std::vector<T*> &v, const char *cls)
{
    luaL_checktype(L, idx, LUA_TTABLE);
    size_t total = lua_rawlen(L, idx);
    v.reserve(total);
    for (int i = 1; i <= total; i++) {
        T* obj;
        lua_rawgeti(L, idx, i);
        olua_check_cppobj(L, -1, (void **)&obj, cls);
        v.push_back(obj);
        lua_pop(L, 1);
    }
}

static inline bool olua_is_std_vector(lua_State *L, int idx)
{
    return lua_istable(L, idx);
}

static inline int olua_push_std_string(lua_State *L, const std::string &value)
{
    lua_pushstring(L, value.c_str());
    return 1;
}

static inline void olua_check_std_string(lua_State *L, int idx, std::string *value)
{
    luaL_checktype(L, idx, LUA_TSTRING);
    *value = lua_tostring(L, idx);
}

static inline void olua_opt_std_string(lua_State *L, int idx, std::string *value, const std::string &def)
{
    *value = luaL_optstring(L, idx, def.c_str());
}

static inline bool olua_is_std_string(lua_State *L, int idx)
{
    return lua_isstring(L, idx);
}

template <typename T> int olua_push_std_function(lua_State *L, const std::function<T> value)
{
    // TODO: return lua func
    lua_pushnil(L);
    return 1;
}

static inline bool olua_is_std_function(lua_State *L, int idx)
{
    return lua_isfunction(L, idx);
}

#endif
