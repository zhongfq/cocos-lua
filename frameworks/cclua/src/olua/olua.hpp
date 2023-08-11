/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2019-2022 codetypes@gmail.com
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
#include <limits>
#include <numeric>
#include <type_traits>
#include <map>
#include <memory>
#include <unordered_map>

/**
 * New and close lua_State for several times, sometimes may got same
 * memory address for lua_State, this because the malloc reuse memory.
 * olua_context can return different id for each main lua_State.
 * Define OLUA_HAVE_CONTEXT when you has implemention
 */
#ifndef OLUA_HAVE_CONTEXT
typedef int64_t olua_Context;
#endif
OLUA_BEGIN_DECLS
OLUA_API olua_Context olua_context(lua_State *L);
OLUA_API bool olua_contextequal(lua_State *L, olua_Context ctx);
OLUA_END_DECLS

/**
 * Got lua main thread.
 * Define OLUA_HAVE_MAINTHREAD when you has implemention
 */
OLUA_BEGIN_DECLS
OLUA_API lua_State *olua_mainthread(lua_State *L);
OLUA_END_DECLS

/**
 * Help to check whether callback is run on the host thread of lua vm.
 * It would be inserted into the start of callback block.
 */
#ifndef OLUA_HAVE_CHECKHOSTTHREAD
#define olua_checkhostthread() ((void)0)
#endif

/**
 * Help you to delete ref when the function prototype don't provide enough
 * information. You can record some information in olua_startcmpref and
 * delete ref in olua_endcmpref by compare.
 *
 * prototype:
 *  void olua_startcmpref(lua_State *L, int idx, const char *refname);
 *  void olua_endcmpref(lua_State *L, int idx, const char *refname);
 *
 * example:
 *  static int func(lua_State *L)
 *  {
 *      ...
 *      olua_startcmpref(L);
 *      self->removeChildren();
 *      olua_endcmpref(L);
 *      ...
 *  }
 */

#ifndef OLUA_HAVE_CMPREF
#define olua_startcmpref(L, i, name) olua_noapi(olua_startcmpref)
#define olua_endcmpref(L, i, name)   olua_noapi(olua_endcmpref)
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
#ifndef OLUA_HAVE_TRACEINVOKING
#define olua_startinvoke(L) ((void)L)
#define olua_endinvoke(L)   ((void)L)
#endif

template <class T> inline T *olua_toobj(lua_State *L, int idx);

/**
 * Handle the status of object after push, you can do some jobs
 * according to the object status. For example, retain object in push and
 * release object in __gc method.
 *
 *  #define OLUA_HAVE_POSTPUSH
 *  template <class T> void olua_postpush(lua_State *L, T* obj, int status)
 *  {
 *      if (std::is_base_of<Object, T>::value && (status == OLUA_OBJ_NEW
 *          || status == OLUA_OBJ_UPDATE)) {
 *          ((Object *)obj)->retain();
 *      }
 *  }
 */
template <class T>
void olua_postpush(lua_State *L, T* obj, int status);
#ifndef OLUA_HAVE_POSTPUSH
template <class T>
void olua_postpush(lua_State *L, T* obj, int status) {}
#endif

/**
 * Handle the status of object after new.
 *
 * example:
 *  static int Object_new(lua_State *L)
 *  {
 *      olua_startinvoke(L);
 *      Object *obj = new Object();
 *      olua_push_obj(L, obj, "Object");
 *      olua_postnew(L, obj);
 *      olua_endinvoke(L);
 *      return 1;
 *  }
 *
 *  #define OLUA_HAVE_POSTNEW
 *  template <class T> void olua_postnew(lua_State *L, T *obj)
 *  {
 *      if (std::is_base_of<Object, T>::value) {
 *          ((Object *)obj)->autorelease();
 *      } else if (olua_getrawobj(L, obj)) {
 *          olua_setownership(L, -1, OLUA_OWNERSHIP_VM);
 *          lua_pop(L, 1);
 *      }
 *  }
 *
 */
template <class T>
void olua_postnew(lua_State *L, T *obj);
#ifndef OLUA_HAVE_POSTNEW
template <class T>
void olua_postnew(lua_State *L, T *obj)
{
    if (olua_getrawobj(L, obj)) {
        olua_setownership(L, -1, OLUA_OWNERSHIP_VM);
        lua_pop(L, 1);
    }
}
#endif

/**
 * delete object which belong to lua vm.
 */
template <class T>
void olua_postgc(lua_State *L, T *obj);
#ifndef OLUA_HAVE_POSTGC
template <class T>
void olua_postgc(lua_State *L, T *obj)
{
    T *self = olua_checkobj<T>(L, -1);
    if (self == obj) {
        int ownership = olua_getownership(L, -1);
        if (ownership == OLUA_OWNERSHIP_VM) {
            if (std::is_void<T>()) {
                free((void *)obj);
            } else {
                delete obj;
            }
        } else if (ownership == OLUA_OWNERSHIP_USERDATA) {
            obj->~T();
        }
        olua_setrawobj(L, -1, nullptr);
    } else {
        luaL_error(L, "object error");
    }
}
#endif

/**
 * register or get lua type for c++ class.
 * Define OLUA_HAVE_LUATYPE when you has implemention
 */
OLUA_BEGIN_DECLS
OLUA_API void olua_registerluatype(lua_State *L, const char *cpptype, const char *cls);
OLUA_API const char *olua_getluatype(lua_State *L, const char *cpptype);
OLUA_END_DECLS

template <class T> inline
void olua_registerluatype(lua_State *L, const char *cls)
{
    olua_registerluatype(L, typeid(T).name(), cls);
}

template <class T>
const char *olua_getluatype(lua_State *L, const T *obj, const char *cls)
{
    const char *preferred;
    
    // try obj RTTI
    if (olua_likely(obj)) {
        preferred = olua_getluatype(L, typeid(*obj).name());
        if (olua_likely(preferred)) {
            return preferred;
        }
    }
    
    // try class RTTI
    preferred = olua_getluatype(L, typeid(T).name());
    if (olua_likely(preferred)) {
        return preferred;
    }
    
    return cls;
}

template <> inline
const char *olua_getluatype<void>(lua_State *L, const void *obj, const char *cls)
{
    return cls == NULL ? OLUA_VOIDCLS : cls;
}

template <class T> inline
const char *olua_getluatype(lua_State *L)
{
    return olua_getluatype(L, typeid(T).name());
}

template <class T> inline
bool olua_isa(lua_State *L, int idx)
{
    return olua_isa(L, idx, olua_getluatype<T>(L));
}

template <class T> inline
void *olua_pushclassobj(lua_State *L)
{
    return olua_pushclassobj(L, olua_getluatype<T>(L));
}

template <class T> inline
T *olua_toobj(lua_State *L, int idx)
{
    return (T *)olua_toobj(L, idx, olua_getluatype<T>(L));
}

template <class T> inline
T *olua_checkobj(lua_State *L, int idx)
{
    return (T *)olua_checkobj(L, idx, olua_getluatype<T>(L));
}

template <class T>
int olua_pushobj(lua_State *L, const T *value, const char *cls)
{
    cls = olua_getluatype(L, value, cls);
    if (!cls) {
        luaL_error(L, "lua class not found: %s", typeid(T).name());
    }
    olua_postpush(L, (T *)value, olua_pushobj(L, (void *)value, cls));
    return 1;
}

template <class T> inline
int olua_pushobj(lua_State *L, const T *value)
{
    return olua_pushobj<T>(L, value, nullptr);
}

template <class T>
int olua_pushobj_as(lua_State *L, int idx, const T *value, const char *ref)
{
    idx = lua_absindex(L, idx);
    if (olua_loadref(L, idx, ref) != LUA_TUSERDATA) {
        lua_pop(L, 1);
        olua_pushobj(L, (void *)value, olua_getluatype<T>(L));
        olua_setownership(L, -1, OLUA_OWNERSHIP_SLAVE);
        olua_addref(L, idx, ref, -1, OLUA_FLAG_SINGLE);
        olua_addref(L, -1, "as.self", idx, OLUA_FLAG_SINGLE);
    }
    return 1;
}

template <class T> inline
void *olua_newobjstub(lua_State *L)
{
    return olua_newobjstub(L, olua_getluatype<T>(L));
}

template <class T> inline 
int olua_pushobjstub(lua_State *L, T *value, void *stub)
{
    const char *cls = olua_getluatype<T>(L, value, NULL);
    return olua_pushobjstub(L, (void *)value, stub, cls);
}

// type traits
namespace std {
#if __cplusplus < 201402L
template< bool B, class T = void >
using enable_if_t = typename enable_if<B,T>::type;
template< class T >
using remove_cv_t = typename remove_cv<T>::type;
template< class T >
using remove_reference_t = typename remove_reference<T>::type;
template< class T >
using remove_pointer_t = typename remove_pointer<T>::type;
#endif
#if __cplusplus < 201703L
template <bool B>
using bool_constant = integral_constant<bool, B>;
#endif
}

namespace olua {
template <class T>
using remove_cvr_t = std::remove_cv_t<std::remove_reference_t<T>>;
template <class T>
using remove_cvrp_t = std::remove_pointer_t<olua::remove_cvr_t<T>>;
template <class T>
using is_integral = std::bool_constant<std::is_integral<remove_cvr_t<T>>::value>;
template <class T>
using is_enum = std::bool_constant<std::is_enum<remove_cvr_t<T>>::value>;
template <class T>
using is_floating = std::bool_constant<std::is_floating_point<remove_cvr_t<T>>::value>;
template <class T>
using is_pointer = std::bool_constant<std::is_pointer<remove_cvr_t<T>>::value>;
template <class T>
using is_reference = std::bool_constant<std::is_reference<std::remove_cv_t<T>>::value>;
}

// class
template <class T, class S = void>
void oluacls_class(lua_State *L, const char *cls)
{
    oluacls_class(L, cls, olua_getluatype<S>(L));
    olua_registerluatype<T>(L, cls);
}

// const value
template <class T, std::enable_if_t<olua::is_integral<T>::value, bool> = true> inline
void oluacls_const(lua_State *L, const char *name, const T value)
{
    if (std::is_same<T, bool>::value) {
        lua_pushboolean(L, (bool)value);
    } else {
        lua_pushinteger(L, (lua_Integer)value);
    }
    oluacls_const(L, name);
}

template <class T, std::enable_if_t<olua::is_floating<T>::value, bool> = true> inline
void oluacls_const(lua_State *L, const char *name, const T value)
{
    lua_pushnumber(L, (lua_Number)value);
    oluacls_const(L, name);
}

template <class T, std::enable_if_t<olua::is_enum<T>::value, bool> = true> inline
void oluacls_const(lua_State *L, const char *name, const T value)
{
    lua_pushlightuserdata(L, (void *)(intptr_t)value);
    oluacls_const(L, name);
}

static inline
void oluacls_const(lua_State *L, const char *name, const std::string &value)
{
    olua_pushlstring(L, value.c_str(), value.size());
    oluacls_const(L, name);
}

static inline
void oluacls_const(lua_State *L, const char *name, const char *value)
{
    olua_pushstring(L, value);
    oluacls_const(L, name);
}

template <class T> inline
void oluacls_const(lua_State *L, const char *name, const T *value)
{
    olua_pushobj<T>(L, value);
    oluacls_const(L, name);
}

// convertor between c++ and lua, use for code generation

// bool
static inline
bool olua_is_bool(lua_State *L, int idx)
{
    return olua_isbool(L, idx);
}

template <class T, std::enable_if_t<olua::is_integral<T>::value, bool> = true> inline
void olua_check_bool(lua_State *L, int idx, T *value)
{
    *value = (T)olua_checkbool(L, idx);
}

template <class T, std::enable_if_t<olua::is_integral<T>::value, bool> = true> inline
int olua_push_bool(lua_State *L, T value)
{
    olua_pushbool(L, (bool)value);
    return 1;
}

// integer
static inline
bool olua_is_integer(lua_State *L, int idx)
{
    return olua_isinteger(L, idx);
}

template <class T, std::enable_if_t<olua::is_integral<T>::value, bool> = true> inline
void olua_check_integer(lua_State *L, int idx, T *value)
{
    *value = (T)olua_checkinteger(L, idx);
}

template <class T, std::enable_if_t<olua::is_integral<T>::value, bool> = true> inline
int olua_push_integer(lua_State *L, T value)
{
    olua_pushinteger(L, (lua_Integer)value);
    return 1;
}

// number
static inline
bool olua_is_number(lua_State *L, int idx)
{
    return olua_isnumber(L, idx);
}

template <class T, std::enable_if_t<olua::is_floating<T>::value, bool> = true> inline
void olua_check_number(lua_State *L, int idx, T *value)
{
    *value = (T)olua_checknumber(L, idx);
}

template <class T, std::enable_if_t<olua::is_floating<T>::value, bool> = true> inline
int olua_push_number(lua_State *L, T value)
{
    olua_pushnumber(L, (lua_Number)value);
    return 1;
}

// string
static inline
bool olua_is_string(lua_State *L, int idx)
{
    return olua_isstring(L, idx);
}

template <class T> inline
void olua_check_string(lua_State *L, int idx, T *value)
{
    static_assert(sizeof(olua::remove_cvrp_t<T>) == sizeof(char), "only support char type");
    *value = (T)olua_checkstring(L, idx);
}

template <class T> inline
int olua_push_string(lua_State *L, const T &value)
{
    static_assert(sizeof(olua::remove_cvrp_t<T>) == sizeof(char), "only support char type");
    olua_pushstring(L, (const char *)value);
    return 1;
}

template <> inline
void olua_check_string<std::string>(lua_State *L, int idx, std::string *value)
{
    size_t len;
    const char *str = olua_checklstring(L, idx, &len);
    *value = std::string(str, len);
}

template <> inline
int olua_push_string<std::string>(lua_State *L, const std::string &value)
{
    lua_pushlstring(L, value.data(), value.size());
    return 1;
}

#if __cplusplus >= 201703L
#include <string_view>

template <> inline
void olua_check_string<std::string_view>(lua_State *L, int idx, std::string_view *value)
{
    size_t len;
    const char *str = olua_checklstring(L, idx, &len);
    *value = std::string_view(str, len);
}

template <> inline
int olua_push_string<std::string_view>(lua_State *L, const std::string_view &value)
{
    lua_pushlstring(L, value.data(), value.size());
    return 1;
}
#endif

// enum
static inline
bool olua_is_enum(lua_State *L, int idx)
{
    return olua_islightuserdata(L, idx);
}

template <class T, std::enable_if_t<olua::is_enum<T>::value, bool> = true> inline
void olua_check_enum(lua_State *L, int idx, T *value)
{
    if (!olua_islightuserdata(L, idx)) {
        luaL_error(L, "expect enum '%s', got '%s'", 
            olua_getluatype<olua::remove_cvrp_t<T>>(L),
            lua_typename(L, lua_type(L, idx)));
    }
    *value = (T)(intptr_t)lua_touserdata(L, idx);
}

template <class T, std::enable_if_t<olua::is_enum<T>::value, bool> = true> inline
int olua_push_enum(lua_State *L, T value)
{
    lua_pushlightuserdata(L, (void *)(intptr_t)value);
    return 1;
}

// object
static inline
bool olua_is_object(lua_State *L, int idx, const char *cls)
{
    olua_debug_assert(cls, "cls is null");
    return olua_isa(L, idx, cls);
}

template <class T> inline
void olua_check_object(lua_State *L, int idx, T **value, const char *cls)
{
    olua_debug_assert(cls, "cls is null");
    *value = (T *)olua_checkobj(L, idx, cls);
}

template <class T> inline
void olua_to_object(lua_State *L, int idx, T **value, const char *cls)
{
    olua_debug_assert(cls, "cls is null");
    *value = (T *)olua_toobj(L, idx, cls);
}

template <class T> inline
void olua_check_object(lua_State *L, int idx, T *value, const char *cls)
{
    olua_debug_assert(cls, "cls is null");
    *value = *(T *)olua_checkobj(L, idx, cls);
}

template <class T> inline
int olua_push_object(lua_State *L, const T *value, const char *cls)
{
    olua_debug_assert(cls, "cls is null");
    return olua_pushobj<T>(L, value, cls);
}

template <class T, std::enable_if_t<!olua::is_pointer<T>::value, bool> = true> inline
int olua_push_object(lua_State *L, const T &value, const char *cls)
{
    olua_debug_assert(cls, "cls is null");
    return olua_pushobj<T>(L, &value, cls);
}

template <class T, std::enable_if_t<!olua::is_pointer<T>::value, bool> = true> inline
int olua_pushcopy_object(lua_State *L, T &value, const char *cls)
{
    using Type = typename std::remove_const<T>::type;
    olua_debug_assert(cls, "cls is null");
    void *ptr = lua_newuserdata(L, sizeof(void *) + sizeof(T));
    Type *obj = new ((char *)ptr + sizeof(void *)) Type(value);
    *(void **)ptr = obj;
    olua_pushobj(L, (void *)obj, olua_getluatype<T>(L, nullptr, cls));
    olua_setownership(L, -1, OLUA_OWNERSHIP_USERDATA);
    return 1;
}

// std::shared_prt & std::weak_ptr
#define OLUA_SMART_PRT "smart_ptr"

template <template<class> class SmartPtr, class T>
int olua_smartptr_gc(lua_State *L)
{
    SmartPtr<T> *obj = olua_checkobj<SmartPtr<T>>(L, 1);
    olua_setrawobj(L, 1, nullptr);
    delete obj;
    return 0;
}

template <template<class> class SmartPtr, class T>
int olua_smartptr_name(lua_State *L)
{
    olua_pushobj<T>(L, olua_toobj<SmartPtr<T>>(L, 1)->get());
    olua_getfield(L, -1, "name");
    return 1;
}

template <template<class> class SmartPtr, class T>
int olua_smartptr_get(lua_State *L)
{
    olua_pushobj<T>(L, olua_toobj<SmartPtr<T>>(L, 1)->get());
    return 1;
}

template <template<class> class SmartPtr, class T>
void oluacls_class_smartptr(lua_State *L)
{
    const char *smartptr_cls = olua_getluatype<SmartPtr<T>>(L);
    if (!smartptr_cls) {
        smartptr_cls = typeid(SmartPtr<T>).name();
        oluacls_class<SmartPtr<T>>(L, smartptr_cls);
        oluacls_func(L, "__gc", olua_smartptr_gc<SmartPtr, T>);
        oluacls_func(L, "get", olua_smartptr_get<SmartPtr, T>);
        oluacls_prop(L, "name", olua_smartptr_name<SmartPtr, T>, nullptr);
        lua_pop(L, 1);
    }
}

template <class T>
void olua_check_object(lua_State *L, int idx, std::shared_ptr<T> *value, const char *)
{
    idx = lua_absindex(L, idx);
    olua_checkobj<T>(L, idx);
    olua_loadref(L, idx, OLUA_SMART_PRT);
    *value = *olua_checkobj<std::shared_ptr<T>>(L, -1);
    lua_pop(L, 1);
}

template <class T>
int olua_push_object(lua_State *L, const std::shared_ptr<T> *value, const char *cls)
{
    oluacls_class_smartptr<std::shared_ptr, T>(L);

    if (!value->get()) {
        lua_pushnil(L);
        return 1;
    }

    olua_pushobj<T>(L, value->get(), cls);
    if (olua_loadref(L, -1, OLUA_SMART_PRT)) {
        lua_pop(L, 1);
        return 1;
    }
    
    olua_setownership(L, -2, OLUA_OWNERSHIP_SLAVE); // skip gc, managed by smart ptr
    olua_pushobj<std::shared_ptr<T>>(L, new std::shared_ptr<T>(*value));
    olua_addref(L, -3, OLUA_SMART_PRT, -1, OLUA_FLAG_SINGLE);
    lua_pop(L, 2); // pop nil and smartptr
    return 1;
}

template <class T>
void olua_check_object(lua_State *L, int idx, std::weak_ptr<T> *value, const char *)
{
    idx = lua_absindex(L, idx);
    olua_loadref(L, idx, OLUA_SMART_PRT);
    *value = *olua_checkobj<std::shared_ptr<T>>(L, -1);
    lua_pop(L, 1);
}

template <class T>
int olua_push_object(lua_State *L, const std::weak_ptr<T> *value, const char *cls)
{
    std::shared_ptr<T> sp = value->lock();
    return olua_push_obj(L, &sp, cls);
}

// map
static inline
bool olua_is_map(lua_State *L, int idx)
{
    return olua_istable(L, idx);
}

template <class K, class V, template<class ...> class Map, class ...Ts>
void olua_insert_map(Map<K, V, Ts...> &map, const K &key, const V &value)
{
    map.insert(std::make_pair(key, value));
}

template <class K, class V, template<class ...> class Map, class ...Ts>
void olua_foreach_map(const Map<K, V, Ts...> &map, const std::function<void(K &, V &)> &callback)
{
    for (auto itor : map) {
        callback(const_cast<K &>(itor.first), itor.second);
    }
}

template <class K, class V, template<class ...> class Map, class ...Ts>
int olua_push_map(lua_State *L, const Map<K, V, Ts...> &map, const std::function<void(K &, V &)> &push)
{
    lua_newtable(L);
    olua_foreach_map<K, V>(map, [=](K &key, V &value) {
        push(key, value);
        olua_rawset(L, -3);
    });
    return 1;
}

template <class K, class V, template<class ...> class Map, class ...Ts>
void olua_check_map(lua_State *L, int idx, Map<K, V, Ts...> &map, const std::function<void(K *, V *)> &check)
{
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);
    lua_pushnil(L);
    while (lua_next(L, idx)) {
        K key;
        V value;
        check(&key, &value);
        olua_insert_map<K, V>(map, key, value);
        lua_pop(L, 1);
    }
}

// array
template <class T>
void olua_insert_vector(std::vector<T> &array, const T &value)
{
    array.push_back(value);
}

template <class T>
void olua_insert_vector(std::set<T> &array, const T &value)
{
    array.insert(value);
}

template <class T, template<class ...> class Vector, class ...Ts>
void olua_foreach_vector(const Vector<T, Ts...> &array, const std::function<void(T &)> &callback)
{
    for (auto &itor : array) {
        callback(const_cast<T &>(itor));
    }
}

template <> inline
void olua_foreach_vector<bool>(const std::vector<bool> &array, const std::function<void(bool &)> &callback)
{
    for (auto itor : array) {
        bool v = itor;
        callback(v);
    }
}

static inline
bool olua_is_vector(lua_State *L, int idx)
{
    return olua_istable(L, idx);
}

template <class T, template<class ...> class Vector, class ...Ts>
int olua_push_vector(lua_State *L, const Vector<T, Ts...> &array, const std::function<void(T &)> &push)
{
    int idx = 0;
    lua_newtable(L);
    olua_foreach_vector<T>(array, [=](T &value) mutable {
        push(value);
        lua_rawseti(L, -2, ++idx);
    });
    return 1;
}

template <class T, template<class ...> class Vector, class ...Ts>
void olua_check_vector(lua_State *L, int idx, Vector<T, Ts...> &array, const std::function<void(T *)> &check)
{
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);
    int total = (int)lua_rawlen(L, idx);
    for (int i = 1; i <= total; i++) {
        T obj;
        lua_rawgeti(L, idx, i);
        check(&obj);
        olua_insert_vector<T>(array, obj);
        lua_pop(L, 1);
    }
}

template <class T, template<class ...> class Vector, class ...Ts>
void olua_pack_vector(lua_State *L, int idx, Vector<T, Ts...> &array, const std::function<void(T *)> &check)
{
    idx = lua_absindex(L, idx);
    int total = (int)(lua_gettop(L) - (idx - 1));
    for (int i = 0; i < total; i++) {
        T obj;
        lua_pushvalue(L, idx + i);
        check(&obj);
        olua_insert_vector<T>(array, obj);
        lua_pop(L, 1);
    }
}

// callback
OLUA_BEGIN_DECLS
OLUA_API bool olua_is_callback(lua_State *L, int idx, const char *cls);
OLUA_API int olua_push_callback(lua_State *L, const char *cls);
OLUA_END_DECLS

template <class T>
int olua_push_callback(lua_State *L, const T *value, const char *cls)
{
    return olua_push_callback(L, olua_getluatype(L, value, cls));
}

template <class T> inline 
void olua_check_callback(lua_State *L, int idx, T *value, const char *cls)
{
    luaL_checktype(L, idx, LUA_TFUNCTION);
}

// pinter type
#if defined(_MSC_VER) && !defined(_SSIZE_T)
#include <BaseTsd.h>
#define _SSIZE_T
typedef SSIZE_T ssize_t;
#endif

namespace olua {
template<class T>
class array {
public:
    array(const array &) = delete;
    array &operator=(const array &) = delete;
    
    array() {}
    ~array()
    {
        if (_owner) {
            delete[] _data;
        }
    }
    
    array(T *v)
    :_len(0)
    ,_owner(false)
    ,_data(v)
    {}

    OLUA_POSTNEW OLUA_NAME(new) static array<T> *create(size_t len = 1)
    {
        array<T> *ret = new array<T>();
        ret->_len = len;
        ret->_data = new T[len]();
        return ret;
    }
    
    T __index(unsigned idx)
    {
         olua_assert(idx >= 1 && idx <= _len, "index out of range");
         return _data[idx - 1];
    }
    
    void __newindex(unsigned idx, const T &v)
    {
        olua_assert(idx >= 1 && idx <= _len, "newindex out of range");
        _data[idx - 1] = v;
    }

    olua_Return __gc(lua_State *L)
    {
        olua_postgc<array<T>>(L, this);
        return 0;
    }

    olua_Return tostring(lua_State *L, size_t len)
    {
        olua_assert(_len > 0 && len <= _len, "invalid length");
        lua_pushlstring(L, (const char*)_data, len * sizeof(T));
        return 1;
    }

    void setstring(const char *data, size_t len)
    {
        olua_assert(sizeof(T) == sizeof(char), "expect char type");
        olua_assert(len <= _len, "data too long");
        strncpy((char *)_data, data, len);
    }

    array<T> *take()
    {
        _owner = false;
        return this;
    }
   
    OLUA_POSTNEW array<T> *sub(size_t from, size_t to = -1)
    {
        if (to == -1) {
            to = _len;
        }
        olua_assert(from <= _len && from <= to, "invalid 'from' position");
        olua_assert(to <= _len, "invalid 'to' position");
        array<T> *ret = create(to - from + 1);
        for (size_t i = 0; i < ret->_len; i++) {
            ret->_data[i] = _data[from + i - 1];
        }
        return ret;
    }
    
    OLUA_GETTER OLUA_NAME(data) T *data() {return _data;}
    OLUA_GETTER OLUA_NAME(rawdata) void *rawdata() {return _data;}
    OLUA_GETTER OLUA_NAME(sizeof) size_t size() {return sizeof(T);}
    OLUA_GETTER OLUA_NAME(value) const T &value() {return *_data;}
    OLUA_SETTER OLUA_NAME(value) void value(const T &v) {*_data = v;}
    OLUA_GETTER OLUA_NAME(length) size_t length() {return _len;}
    OLUA_SETTER OLUA_NAME(length) void length(size_t len)
    {
        olua_assert(!_owner, "not allow set length when own the data");
        _len = len;
    }
private:
    T *_data = nullptr;
    size_t _len = 0;
    bool _owner = true;
};

template<class T>
class pointer {
public:
    pointer(const pointer &) = delete;
    pointer &operator=(const pointer &) = delete;
    
    pointer() {}
    
    pointer(T *v)
    :_owner(false)
    ,_data(v)
    {}
    
    ~pointer()
    {
        if (_owner) {
            delete _data;
        }
    }

    OLUA_POSTNEW OLUA_NAME(new) static pointer<T> *create()
    {
        pointer<T> *ret = new pointer<T>();
        ret->_owner = true;
        ret->_data = new T();
        return ret;
    }
    
    OLUA_POSTNEW OLUA_NAME(new) static pointer<T> *create(const T &v)
    {
        pointer<T> *ret = create();
        *ret->_data = v;
        return ret;
    }

    olua_Return __gc(lua_State *L)
    {
        olua_postgc<pointer<T>>(L, this);
        return 0;
    }
    
    pointer<T> *take()
    {
        _owner = false;
        return this;
    }
    
    OLUA_GETTER OLUA_NAME(data) T *data() {return _data;}
    OLUA_GETTER OLUA_NAME(rawdata) void *rawdata() {return _data;}
    OLUA_GETTER OLUA_NAME(sizeof) size_t size() {return sizeof(T);}
    OLUA_GETTER OLUA_NAME(value) const T &value() {return *_data;}
    OLUA_SETTER OLUA_NAME(value) void value(const T &v) {*_data = v;}
private:
    T *_data = nullptr;
    bool _owner = true;
};
}

typedef char olua_char_t;
typedef short olua_short_t;
typedef int olua_int_t;
typedef long olua_long_t;
typedef long long olua_llong_t;
typedef unsigned char olua_uchar_t;
typedef unsigned short olua_ushort_t;
typedef unsigned int olua_uint_t;
typedef unsigned long olua_ulong_t;
typedef unsigned long long olua_ullong_t;
typedef float olua_float_t;
typedef double olua_double_t;
typedef long double olua_ldouble_t;

typedef olua::array<bool> olua_bool;
typedef olua::array<int8_t> olua_int8_t;
typedef olua::array<uint8_t> olua_uint8_t;
typedef olua::array<int16_t> olua_int16_t;
typedef olua::array<uint16_t> olua_uint16_t;
typedef olua::array<int32_t> olua_int32_t;
typedef olua::array<uint32_t> olua_uint32_t;
typedef olua::array<int64_t> olua_int64_t;
typedef olua::array<uint64_t> olua_uint64_t;
typedef olua::array<olua_char_t> olua_char;
typedef olua::array<olua_short_t> olua_short;
typedef olua::array<olua_int_t> olua_int;
typedef olua::array<olua_long_t> olua_long;
typedef olua::array<olua_llong_t> olua_llong;
typedef olua::array<olua_uchar_t> olua_uchar;
typedef olua::array<olua_ushort_t> olua_ushort;
typedef olua::array<olua_uint_t> olua_uint;
typedef olua::array<olua_ulong_t> olua_ulong;
typedef olua::array<olua_ullong_t> olua_ullong;
typedef olua::array<olua_float_t> olua_float;
typedef olua::array<olua_double_t> olua_double;
typedef olua::array<olua_ldouble_t> olua_ldouble;
typedef olua::array<size_t> olua_size_t;
typedef olua::array<ssize_t> olua_ssize_t;
typedef olua::pointer<std::string> olua_string;

template <class T> inline
int olua_pushobj(lua_State *L, const olua::array<T> *value, const char *cls)
{
    olua_postpush(L, (olua::array<T> *)value, olua_pushobj(L, (void *)value, cls));
    return 1;
}

template <class T> inline
int olua_pushobj(lua_State *L, const olua::array<T> *value)
{
    static_assert(sizeof(T) == 0, "push olua::array object must specify the lua class");
    return 0;
}

template <class T> inline
int olua_push_object(lua_State *L, const olua::array<T> *value, const char *cls)
{
    return olua_pushobj<T>(L, value, cls);
}

// array
static inline 
int olua_is_array(lua_State *L, int idx, const char *cls)
{
    return olua_isa(L, idx, cls);
}

template <class T> inline
void olua_check_array(lua_State *L, int idx, T **value, const char *cls)
{
    olua::array<T> *obj = (olua::array<T> *)olua_checkobj(L, idx, cls);
    *value = obj->data();
}

template <class T>
int olua_push_array(lua_State *L, T *value, const char *cls)
{
    if (value) {
        olua::array<T> *obj = new olua::array<T>(value);
        olua_pushobj<olua::array<T>>(L, obj, cls);
        olua_postnew(L, obj);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

// pointer
template <class T> inline
int olua_pushobj(lua_State *L, const olua::pointer<T> *value, const char *cls)
{
    olua_postpush(L, (olua::pointer<T> *)value, olua_pushobj(L, (void *)value, cls));
    return 1;
}

template <class T> inline
int olua_pushobj(lua_State *L, const olua::pointer<T> *value)
{
    static_assert(sizeof(T) == 0, "push olua::pointer object must specify the lua class");
    return 0;
}

template <class T> inline
int olua_push_object(lua_State *L, const olua::pointer<T> *value, const char *cls)
{
    return olua_pushobj<T>(L, value, cls);
}

static inline
int olua_is_pointer(lua_State *L, int idx, const char *cls)
{
    return olua_isa(L, idx, cls);
}

template <class T> inline
void olua_check_pointer(lua_State *L, int idx, T **value, const char *cls)
{
    olua::pointer<T> *obj = (olua::pointer<T> *)olua_checkobj(L, idx, cls);
    *value = obj->data();
}

template <class T>
int olua_push_pointer(lua_State *L, T *value, const char *cls)
{
    if (value) {
        olua::pointer<T> *obj = new olua::pointer<T>(value);
        olua_pushobj<olua::pointer<T>>(L, obj, cls);
        olua_postnew(L, obj);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

#endif
