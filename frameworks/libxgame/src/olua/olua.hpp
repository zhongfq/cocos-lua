/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2019-2020 codetypes@gmail.com
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

#define olua_noapi(api) static_assert(false, #api" is not defined")

/**
 * Handle the status of object after push, you can do some jobs
 * according to the object status. For example, retain object in push and
 * release object in __gc method.
 *
 *  #define olua_postpush mylua_postpush
 *  template <typename T> void mylua_postpush(lua_State *L, T* obj, int status)
 *  {
 *      if (std::is_base_of<Object, T>::value && (status == OLUA_OBJ_NEW
 *              || status == OLUA_OBJ_UPDATE)) {
 *          ((Object *)obj)->retain();
 *      }
 *  }
 */
#ifndef olua_postpush
#define olua_postpush(L, obj, status) ((void)L)
#endif

/**
 * Would be inserted after push object which created by operator new.
 *
 * example:
 *  static int Object_new(lua_State *L)
 *  {
 *      olua_startinvoke(L);
 *      Object *obj = new Object();
 *      olua_push_cppobj(L, obj, "Object");
 *      olua_postnew(L, obj);
 *      olua_endinvoke(L);
 *      return 1;
 *  }
 *
 *  #define olua_postnew mylua_postnew
 *  template <typename T> void mylua_postnew(lua_State *L, T *obj)
 *  {
 *      if (std::is_base_of<Object, T>::value) {
 *          ((Object *)obj)->autorelease();
 *      } else {
 *          lua_pushstring(L, ".ownership");
 *          lua_pushboolean(L, true);
 *          olua_setvariable(L, -3);
 *      }
 *  }
 *
 */
#ifndef olua_postnew
#define olua_postnew(L, obj) ((void)L)
#endif

/**
 * Help you to delete ref when the function prototype don't provide enough
 * information. You can record some information in olua_startcmpdelref and
 * delete ref in olua_endcmpdelref by compare.
 *
 * exmaple:
 *  static int func(lua_State *L)
 *  {
 *      ...
 *      olua_startcmpdelref(L);
 *      self->removeChildren();
 *      olua_endcmpdelref(L);
 *      ...
 *  }
 */
#ifndef olua_startcmpdelref
#define olua_startcmpdelref(L, i, name) olua_noapi(olua_startcmpdelref)
#define olua_endcmpdelref(L, i, name)   olua_noapi(olua_endcmpdelref)
#endif

/**
 * Help you to get calling stack when thow lua error in c++ internal
 * implementation. olua_startinvoke would be inserted into the start of
 * function block and olua_endinvoke would be inserted before each
 * return expression.
 *
 * example:
 *  static int func(lua_State *L)
 *  {
 *      olua_startinvoke(L);
 *      ...
 *      ...
 *      if (cond) {
 *          olua_endinvoke(L);
 *          return 2;
 *      }
 *      ...
 *      olua_endinvoke(L);
 *      return 1;
 *  }
 */
#ifndef olua_startinvoke
#define olua_startinvoke(L) ((void)L)
#define olua_endinvoke(L)   ((void)L)
#endif

#ifndef oluai_registerluatype
#define oluai_registerluatype(L, t, c) {\
    lua_pushstring(L, (t));             \
    lua_pushstring(L, (c));             \
    lua_rawset(L, LUA_REGISTRYINDEX);   \
}
#endif

#ifndef oluai_getluatype
#define oluai_getluatype(L, t) olua_optfieldstring(L, LUA_REGISTRYINDEX, (t), nullptr)
#endif

template <typename T> void olua_registerluatype(lua_State *L, const char *cls)
{
    oluai_registerluatype(L, typeid(T).name(), cls);
}

template <typename T> const char *olua_getluatype(lua_State *L, const T *obj, const char *cls)
{
    const char *preferred;
    
    // try obj RTTI
    if (olua_likely(obj)) {
        preferred = oluai_getluatype(L, typeid(*obj).name());
        if (olua_likely(preferred)) {
            return preferred;
        }
    }
    
    // try class RTTI
    preferred = oluai_getluatype(L, typeid(T).name());
    if (olua_likely(preferred)) {
        return preferred;
    }
    
    return cls;
}

template <typename T> inline const char *olua_getluatype(lua_State *L)
{
    return olua_getluatype<T>(L, nullptr, nullptr);
}

template <> inline const char *olua_getluatype<void>(lua_State *L, const void *obj, const char *cls)
{
    return cls == NULL ? OLUA_VOIDCLS : cls;
}

template <typename T> inline bool olua_isa(lua_State *L, int idx)
{
    return olua_isa(L, idx, olua_getluatype<T>(L));
}

template <typename T> inline void *olua_pushclassobj(lua_State *L)
{
    return olua_pushclassobj(L, olua_getluatype<T>(L));
}

template <typename T> inline T *olua_toobj(lua_State *L, int idx)
{
    return (T *)olua_toobj(L, idx, olua_getluatype<T>(L));
}

template <typename T> inline T *olua_checkobj(lua_State *L, int idx)
{
    return (T *)olua_checkobj(L, idx, olua_getluatype<T>(L));
}

template <typename T> int olua_pushobj(lua_State *L, const T *value, const char *cls)
{
    cls = olua_getluatype(L, value, cls);
    olua_postpush(L, (T *)value, olua_pushobj(L, (void *)value, cls));
    return 1;
}

template <typename T> inline int olua_pushobj(lua_State *L, const T *value)
{
    return olua_pushobj<T>(L, value, nullptr);
}

// convertor between c++ and lua, use for code generation
#define olua_push_std_string(L, v)      ((lua_pushstring(L, (v).c_str())), 1)
#define olua_check_std_string(L, i, v)  (*(v) = olua_checkstring(L, (i)))
#define olua_is_std_string(L, i)        (olua_isstring(L, (i)))

#define olua_to_cppobj(L, i, v, c)      (olua_to_obj(L, (i), (v), (c)))
#define olua_check_cppobj(L, i, v, c)   (olua_check_obj(L, (i), (v), (c)))
#define olua_is_cppobj(L, i, c)         (olua_is_obj(L, (i), (c)))

template <typename T> inline int olua_push_cppobj(lua_State *L, const T *value, const char *cls)
{
    return olua_pushobj<T>(L, value, cls);
}

template <typename T> inline int olua_push_cppobj(lua_State *L, const T *value)
{
    return olua_pushobj<T>(L, value, nullptr);
}

template <typename T> int olua_push_std_set(lua_State *L, const std::set<T*> &value, const char *cls)
{
    int i = 1;
    lua_createtable(L, (int)value.size(), 0);
    for (const auto obj : value) {
        if (olua_likely(obj)) {
            olua_push_cppobj(L, obj, cls);
            lua_rawseti(L, -2, i++);
        }
    }
    return 1;
}

template <typename T> void olua_check_std_set(lua_State *L, int idx, std::set<T*> &value, const char *cls)
{
    luaL_checktype(L, idx, LUA_TTABLE);
    int total = (int)lua_rawlen(L, idx);
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
        if (olua_likely(obj)) {
            olua_push_cppobj(L, obj, cls);
            lua_rawseti(L, -2, i++);
        }
    }
    return 1;
}

template <typename T> void olua_check_std_vector(lua_State *L, int idx, std::vector<T*> &v, const char *cls)
{
    luaL_checktype(L, idx, LUA_TTABLE);
    int total = (int)lua_rawlen(L, idx);
    v.reserve((size_t)total);
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

template <typename T> int olua_push_std_function(lua_State *L, const std::function<T> *value)
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
