/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 codetypes@gmail.com
 *
 * https://github.com/zhongfq/olua
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef __OLUA_HPP__
#define __OLUA_HPP__

#include "olua.h"

#include <string>
#include <functional>
#include <set>
#include <vector>

#ifndef olua_handlestatus
#define olua_handlestatus(L, i, n) assert(false && "not define olua_handlestatus")
#endif

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
    const char *preferred = nullptr;
    if (obj) {
        lua_pushstring(L, typeid(*obj).name());
        if (lua_rawget(L, LUA_REGISTRYINDEX) == LUA_TSTRING) {
            preferred = olua_tostring(L, -1);
        }
        lua_pop(L, 1);
    }
    if (!preferred) {
        lua_pushstring(L, typeid(T).name());
        if (lua_rawget(L, LUA_REGISTRYINDEX) == LUA_TSTRING) {
            preferred = olua_tostring(L, -1);
        }
        lua_pop(L, 1);
    }
    cls = preferred ? preferred : cls;
    if (!cls) {
        luaL_error(L, "object lua class not found: %s", typeid(T).name());
    }
    
    return cls;
}

template <typename T> const char *olua_getluatype(lua_State *L)
{
    return olua_getluatype<T>(L, nullptr, nullptr);
}

static inline const char *olua_getluatype(lua_State *L, void *obj, const char *cls)
{
    return cls;
}

template <typename T> T *olua_toobj(lua_State *L, int idx)
{
    const char *cls = olua_getluatype<T>(L, nullptr, nullptr);
    return (T *)olua_toobj(L, idx, cls);
}

template <typename T> T *olua_checkobj(lua_State *L, int idx)
{
    const char *cls = olua_getluatype<T>(L, nullptr, nullptr);
    return (T *)olua_checkobj(L, idx, cls);
}

template <typename T> int olua_push_cppobj(lua_State *L, T* value, const char *cls)
{
    cls = olua_getluatype(L, value, cls);
    olua_handlestatus(L, value, olua_pushobj(L, value, cls));
    return 1;
}

template <typename T> int olua_push_cppobj(lua_State *L, T* value)
{
    const char *cls = olua_getluatype(L, value, nullptr);
    olua_handlestatus(L, value, olua_pushobj(L, value, cls));
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

static inline void olua_opt_cppobj(lua_State *L, int idx, void **value, const char *cls, void *def)
{
    olua_opt_obj(L, idx, value, cls, def);
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
    return olua_istable(L, idx);
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
    return olua_istable(L, idx);
}

static inline int olua_push_std_string(lua_State *L, const std::string &value)
{
    lua_pushstring(L, value.c_str());
    return 1;
}

static inline void olua_check_std_string(lua_State *L, int idx, std::string *value)
{
    *value = olua_checkstring(L, idx);
}

static inline void olua_opt_std_string(lua_State *L, int idx, std::string *value, const std::string &def)
{
    *value = olua_optstring(L, idx, def.c_str());
}

static inline bool olua_is_std_string(lua_State *L, int idx)
{
    return olua_isstring(L, idx);
}

template <typename T> int olua_push_std_function(lua_State *L, const std::function<T> value)
{
    if (!(olua_isfunction(L, -1) || olua_isnil(L, -1))) {
        luaL_error(L, "execpt 'function' or 'nil'");
    }
    return 1;
}

static inline bool olua_is_std_function(lua_State *L, int idx)
{
    return olua_isfunction(L, idx);
}

#endif
