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

#ifndef __OLUA_H__
#define __OLUA_H__

// if define template function in the user header file, it should
// wrapped with 'ifdef __cplusplus'.
#ifdef OLUA_USER_H
#include OLUA_USER_H
#endif

#if defined(__cplusplus)
#define OLUA_BEGIN_DECLS   extern "C" {
#define OLUA_END_DECLS     }
#else
#define OLUA_BEGIN_DECLS
#define OLUA_END_DECLS
#endif

OLUA_BEGIN_DECLS
    
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
    
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>
#include <math.h>

#ifndef olua_assert
#ifdef OLUA_DEBUG
#define olua_assert(e, msg) assert((e) && (msg))
#else
#define olua_assert(e, msg) ((void)0)
#endif
#endif // olua_assert

#ifndef olua_debug_assert
#ifdef OLUA_DEBUG
#define olua_debug_assert(e, msg) assert((e) && (msg))
#else
#define olua_debug_assert(e, msg) ((void)0)
#endif
#endif // olua_debug_assert

#define olua_noapi(api) static_assert(false, #api" is not defined")

#if !defined(olua_likely)
#if defined(__GNUC__) || defined(__clang__)
#define olua_likely(x)      (__builtin_expect(!!(x), 1))
#define olua_unlikely(x)    (__builtin_expect(!!(x), 0))
#else
#define olua_likely(x)      (x)
#define olua_unlikely(x)    (x)
#endif
#endif // luai_likely

#ifndef OLUA_API
#define OLUA_API extern
#endif

#ifdef _WIN32
#define OLUA_LIB __declspec(dllexport)
#else
#define OLUA_LIB extern
#endif

// olua config file: https://codetypes.com/posts/c505b168/
#ifdef OLUA_AUTOCONF
#define OLUA_EXCLUDE        __attribute__((annotate("@exclude")))
#define OLUA_TYPE(name)     __attribute__((annotate("@type("#name")")))
#define OLUA_NAME(name)     __attribute__((annotate("@name("#name")")))
#define OLUA_ADDREF(...)    __attribute__((annotate("@addref("#__VA_ARGS__")")))
#define OLUA_DEFREF(...)    __attribute__((annotate("@delref("#__VA_ARGS__")")))
#define OLUA_PACK           __attribute__((annotate("@pack")))
#define OLUA_UNPACK         __attribute__((annotate("@unpack")))
#define OLUA_NULLABLE       __attribute__((annotate("@nullable")))
#define OLUA_POSTNEW        __attribute__((annotate("@postnew")))
#define OLUA_READONLY       __attribute__((annotate("@readonly")))
#define OLUA_OPTIONAL       __attribute__((annotate("@optional")))
#define OLUA_GETTER         __attribute__((annotate("@getter")))
#define OLUA_SETTER         __attribute__((annotate("@setter")))
#else
#define OLUA_EXCLUDE
#define OLUA_TYPE(name)
#define OLUA_NAME(name)
#define OLUA_ADDREF(...)
#define OLUA_DEFREF(...)
#define OLUA_PACK
#define OLUA_UNPACK
#define OLUA_NULLABLE
#define OLUA_POSTNEW
#define OLUA_READONLY
#define OLUA_OPTIONAL
#define OLUA_GETTER
#define OLUA_SETTER
#endif

// max cpp type size
#ifndef OLUA_MAX_CPPTYPE
#define OLUA_MAX_CPPTYPE 256
#endif
    
// object status
#define OLUA_OBJ_EXIST  0   // object exist
#define OLUA_OBJ_NEW    1   // object new create
#define OLUA_OBJ_UPDATE 2   // object exist but update object metatable

// default super class of object
#define OLUA_VOIDCLS "void *"

// any type
#define LUA_TANY (LUA_TNONE - 1000)

/** In 'gen-func.lua', when generate function binding, if function return
 *  type is 'olua_Return', it will pass 'L' as first arg.
 */
typedef int olua_Return;

// stat api
OLUA_API bool olua_isdebug(lua_State *L);
    
// compare raw type of value
#define olua_isfunction(L, i)       (lua_type(L, (i)) == LUA_TFUNCTION)
#define olua_istable(L, i)          (lua_type(L, (i)) == LUA_TTABLE)
#define olua_islightuserdata(L, i)  (lua_type(L, (i)) == LUA_TLIGHTUSERDATA)
#define olua_isuserdata(L, i)       (lua_type(L, (i)) == LUA_TUSERDATA)
#define olua_isnil(L, i)            (lua_type(L, (i)) == LUA_TNIL)
#define olua_isnoneornil(L, i)      (lua_type(L, (i)) <= 0)
#define olua_isbool(L, i)           (lua_type(L, (i)) == LUA_TBOOLEAN)
#define olua_isstring(L, i)         (lua_type(L, (i)) == LUA_TSTRING)
#define olua_isnumber(L, i)         (lua_type(L, (i)) == LUA_TNUMBER)
#define olua_isthread(L, i)         (lua_type(L, (i)) == LUA_TTHREAD)
OLUA_API bool olua_isinteger(lua_State *L, int idx);

#define olua_strequal(s1, s2)       (strcmp((s1), (s2)) == 0)
    
// push, check or get raw value
#define olua_pushbool(L, v)         (lua_pushboolean(L, (v)))
#define olua_pushinteger(L, v)      (lua_pushinteger(L, (v)))
#define olua_pushnumber(L, v)       (lua_pushnumber(L, (v)))
#define olua_pushstring(L, v)       (lua_pushstring(L, (v)))
#define olua_pushlstring(L, v, l)   (lua_pushlstring(L, (v), (l)))
#define olua_tonumber(L, i)         (lua_tonumber(L, (i)))
#define olua_tointeger(L, i)        (lua_tointeger(L, (i)))
#define olua_tostring(L, i)         (lua_tostring(L, (i)))
#define olua_tolstring(L, i, l)     (lua_tolstring(L, (i), (l)))
#define olua_tobool(L, i)           (lua_toboolean(L, (i)))
#define olua_checkstring(L, i)      (olua_checklstring(L, (i), NULL))
#define olua_optinteger(L, i, d)    (luaL_opt(L, olua_checkinteger, (i), (d)))
#define olua_optstring(L, i, d)     (luaL_opt(L, olua_checkstring, (i), (d)))
#define olua_optlstring(L, i, d, l) (luaL_opt(L, olua_checklstring, (i), (d), (l)))
#define olua_optnumber(L, i, d)     (luaL_opt(L, olua_checknumber, (i), (d)))
#define olua_optbool(L, i, d)       (olua_isnoneornil(L, (i)) ? (d) : olua_tobool(L, (i)) != 0)
OLUA_API lua_Integer olua_checkinteger(lua_State *L, int idx);
OLUA_API lua_Number olua_checknumber(lua_State *L, int idx);
OLUA_API const char *olua_checklstring (lua_State *L, int arg, size_t *len);
OLUA_API bool olua_checkbool(lua_State *L, int idx);

// raw set or get value with field
OLUA_API int olua_rawgetf(lua_State *L, int idx, const char *field);
OLUA_API void olua_rawsetf(lua_State *L, int idx, const char *field);

// call 'func' and store result in '_LOADED' table without change stack
OLUA_API void olua_require(lua_State *L, const char *name, lua_CFunction func);

#define olua_callfunc(L, fn) (lua_pushcfunction(L, (fn)), lua_call(L, 0, 0))
#define olua_import(L, fn) olua_callfunc(L, (fn))
OLUA_API void olua_pusherrorfunc(lua_State *L);
OLUA_API int olua_pcall(lua_State *L, int nargs, int nresults);
    
// new, get or set raw user data
#define olua_newrawobj(L, o)    (*(void **)lua_newuserdata(L, sizeof(void *)) = (o))
#define olua_torawobj(L, i)     (*(void **)lua_touserdata(L, (i)))
#define olua_setrawobj(L, i, o) (*(void **)lua_touserdata(L, (i)) = (o))
OLUA_API bool olua_getrawobj(lua_State *L, void *obj);

// manipulate userdata api
OLUA_API const char *olua_typename(lua_State *L, int idx);
OLUA_API bool olua_isa(lua_State *L, int idx, const char *cls);
OLUA_API void *olua_newobjstub(lua_State *L, const char *cls);
OLUA_API int olua_pushobjstub(lua_State *L, void *obj, void *stub, const char *cls);
OLUA_API int olua_pushobj(lua_State *L, void *obj, const char *cls);
OLUA_API void *olua_checkobj(lua_State *L, int idx, const char *cls);
OLUA_API void *olua_toobj(lua_State *L, int idx, const char *cls);
OLUA_API void olua_delobj(lua_State *L, void *obj);
OLUA_API const char *olua_objstring(lua_State *L, int idx);
OLUA_API int olua_indexerror(lua_State *L);
OLUA_API int olua_newindexerror(lua_State *L);

// ownership
#define OLUA_OWNERSHIP_NONE     0
#define OLUA_OWNERSHIP_VM       1   // gc: delete or free
#define OLUA_OWNERSHIP_USERDATA 2   // gc: obj->~T()
#define OLUA_OWNERSHIP_SLAVE    3   // skip gc
OLUA_API void olua_setownership(lua_State *L, int idx, int owner);
OLUA_API int olua_getownership(lua_State *L, int idx);
    
// optimize temporary userdata, used in push stack obj to lua inside the callback
OLUA_API void olua_enable_objpool(lua_State *L);
OLUA_API void olua_disable_objpool(lua_State *L);
OLUA_API size_t olua_push_objpool(lua_State *L);
OLUA_API void olua_pop_objpool(lua_State *L, size_t position);

/**
 * callback functions
 * obj.uservalue {
 *     |---id---|--class--|--tag--|
 *     .olua.cb#1$classname@onClick = lua_func
 *     .olua.cb#2$classname@onClick = lua_func
 *     .olua.cb#3$classname@update = lua_func
 *     .olua.cb#4$classname@onRemoved = lua_func
 *     ...
 * }
 */
// for olua_setcallback
#define OLUA_TAG_NEW        0
#define OLUA_TAG_REPLACE    1 // compare substring after '@'
// for olua_removecallback
#define OLUA_TAG_WHOLE      2 // compare whole tag string
#define OLUA_TAG_EQUAL      3 // compare substring after '@'
#define OLUA_TAG_STARTWITH  4 // compare substring after '@'
OLUA_API const char *olua_setcallback(lua_State *L, void *obj, int func, const char *tag, int tagmode);
OLUA_API int olua_getcallback(lua_State *L, void *obj, const char *tag, int tagmode);
OLUA_API void olua_removecallback(lua_State *L, void *obj, const char *tag, int tagmode);
OLUA_API int olua_callback(lua_State *L, void *obj, const char *func, int argc);
    
// class store, store static callback or other
OLUA_API void *olua_pushclassobj(lua_State *L, const char *cls);
OLUA_API bool olua_getclass(lua_State *L, const char *cls);

// get or set variable in userdata
OLUA_API int olua_getvariable(lua_State *L, int idx);
OLUA_API void olua_setvariable(lua_State *L, int idx);
    
// lua style ref
typedef int64_t olua_Ref;
OLUA_API olua_Ref olua_ref(lua_State *L, int idx, int type);
OLUA_API void olua_unref(lua_State *L, olua_Ref ref);
OLUA_API void olua_getref(lua_State *L, olua_Ref ref);
    
/**
 * ref chain, callback stored in the uservalue
 * ref layout:
 * obj.uservalue {
 *     .olua.ref.component = obj_component  -- OLUA_FLAG_SINGLE
 *     .olua.ref.children = {               -- OLUA_FLAG_MULTIPLE
 *         obj_child1 = true
 *         obj_child2 = true
 *         ...
 *     }
 * }
 */
#define OLUA_FLAG_SINGLE    (1 << 1) // add & remove: only ref one
#define OLUA_FLAG_MULTIPLE  (1 << 2) // add & remove: can ref one or more
#define OLUA_FLAG_TABLE     (1 << 3) // obj is table
#define OLUA_FLAG_REMOVE    (1 << 4) // internal use
#define OLUA_NOREFSTORE     INT_MIN
typedef bool (*olua_RefVisitor)(lua_State *L, int idx);
OLUA_API int olua_loadref(lua_State *L, int idx, const char *name);
OLUA_API void olua_addref(lua_State *L, int idx, const char *name, int obj, int flags);
OLUA_API void olua_delref(lua_State *L, int idx, const char *name, int obj, int flags);
OLUA_API void olua_delallrefs(lua_State *L, int idx, const char *name);
OLUA_API void olua_visitrefs(lua_State *L, int idx, const char *name, olua_RefVisitor walk);

/**
 * lua class model
 * class A = {
 *     class = class A
 *     classname = A
 *     classtype = native
 *     super = class B
 *     ...__gc = cls_metamethod    -- .func[..._gc]
 *
 *     .classobj = userdata        -- store static callback
 *     .isa = {
 *         copy(B['.isa'])
 *         A = true
 *     }
 *     .func = {
 *         __index = B['.func']    -- cache after access
 *         dosomething = func
 *         ...
 *     }
 *     .get = {
 *         __index = B['.get']     -- cache after access
 *         name = get_name(obj, name)
 *         ...
 *     }
 *     .set = {
 *         __index = B['.set']     -- cache after access
 *          name = set_name(obj, name, value)
 *          ...
 *      }
 * }
 */
OLUA_API void oluacls_class(lua_State *L, const char *cls, const char *supercls);
OLUA_API void oluacls_prop(lua_State *L, const char *name, lua_CFunction getter, lua_CFunction setter);
OLUA_API void oluacls_func(lua_State *L, const char *name, lua_CFunction func);
OLUA_API void oluacls_enum(lua_State *L, const char *name, lua_Integer value);
OLUA_API void oluacls_const(lua_State *L, const char *name);
    
// get or set value for table
OLUA_API const char *olua_checkfieldstring(lua_State *L, int idx, const char *field);
OLUA_API lua_Number olua_checkfieldnumber(lua_State *L, int idx, const char *field);
OLUA_API lua_Integer olua_checkfieldinteger(lua_State *L, int idx, const char *field);
OLUA_API bool olua_checkfieldbool(lua_State *L, int idx, const char *field);
OLUA_API void olua_setfieldnumber(lua_State *L, int idx, const char *field, lua_Number value);
OLUA_API void olua_setfieldinteger(lua_State *L, int idx, const char *field, lua_Integer value);
OLUA_API void olua_setfieldstring(lua_State *L, int idx, const char *field, const char *value);
OLUA_API void olua_setfieldbool(lua_State *L, int idx, const char *field, bool value);
OLUA_API const char *olua_optfieldstring(lua_State *L, int idx, const char *field, const char *def);
OLUA_API lua_Number olua_optfieldnumber(lua_State *L, int idx, const char *field, lua_Number def);
OLUA_API lua_Integer olua_optfieldinteger(lua_State *L, int idx, const char *field, lua_Integer def);
OLUA_API bool olua_optfieldbool(lua_State *L, int idx, const char *field, bool def);
OLUA_API bool olua_hasfield(lua_State *L, int idx, const char *field);
    
#if LUA_VERSION_NUM == 501
typedef unsigned long lua_Unsigned;
#define LUA_OK 0
#define LUA_RIDX_MAINTHREAD 1
#define LUA_RIDX_GLOBALS    2
#define LUA_PRELOAD_TABLE "_PRELOAD"
#define LUA_LOADED_TABLE "_LOADED"
#define LUA_LOADER_TABLE "loaders"
#define lua_rawlen(L, i) lua_objlen(L, (i))
#define luaL_newlib(L,l) {                              \
    lua_createtable(L, 0, sizeof(l)/sizeof((l)[0]) - 1);\
    luaL_setfuncs(L,(l),0);                             \
}
OLUA_API void lua_copy(lua_State *L, int fromidx, int toidx);
OLUA_API void lua_setuservalue(lua_State *L, int idx);
OLUA_API int lua_getuservalue(lua_State *L, int idx);
OLUA_API int lua_absindex(lua_State *L, int idx);
OLUA_API int luaL_getsubtable (lua_State *L, int idx, const char *fname);
OLUA_API void luaL_setfuncs(lua_State *L, const luaL_Reg *l, int nup);
OLUA_API void luaL_traceback(lua_State *L, lua_State *L1, const char *msg, int level);
OLUA_API void luaL_requiref(lua_State *L, const char *modname, lua_CFunction openf, int glb);
OLUA_API void *luaL_testudata(lua_State *L, int ud, const char *tname);

OLUA_API void olua_initcompat(lua_State *L);
OLUA_API void olua_rawsetp(lua_State *L, int idx, const void *p);
OLUA_API int olua_rawgetp(lua_State *L, int idx, const void *p);
#define olua_getglobal(L, k)        (lua_getglobal(L, (k)), lua_type(L, -1))
#define olua_setglobal(L, k)        (lua_setglobal(L, (k)))
#define olua_getmetatable(L, k)     (luaL_getmetatable(L, (k)), lua_type(L, -1))
#define olua_setmetatable(L, k)     (luaL_getmetatable(L, (k)), lua_setmetatable(L, -2))
#define olua_rawset(L, i)           (lua_rawset(L, (i)))
#define olua_rawget(L, i)           (lua_rawget(L, (i)), lua_type(L, -1))
#define olua_rawgeti(L, i, n)       (lua_rawgeti(L, (i), (int)(n)), lua_type(L, -1))
#define olua_rawseti(L, i, n)       (lua_rawseti(L, (i), (int)(n)))
#define olua_setfield(L, i, k)      (lua_setfield(L, (i), (k)))
#define olua_getfield(L, i, k)      (lua_getfield(L, (i), (k)), lua_type(L, -1))
#define olua_settable(L, i)         (lua_settable(L, (i)))
#define olua_gettable(L, i)         (lua_gettable(L, (i)), lua_type(L, -1))
#else
#define LUA_LOADER_TABLE "searchers"
#define olua_getglobal(L, k)        (lua_getglobal(L, (k)))
#define olua_setglobal(L, k)        (lua_setglobal(L, (k)))
#define olua_getmetatable(L, k)     (luaL_getmetatable(L, (k)))
#define olua_setmetatable(L, k)     (luaL_setmetatable(L, (k)))
#define olua_rawsetp(L, i, p)       (lua_rawsetp(L, (i), (p)))
#define olua_rawgetp(L, i, p)       (lua_rawgetp(L, (i), (p)))
#define olua_rawset(L, i)           (lua_rawset(L, (i)))
#define olua_rawget(L, i)           (lua_rawget(L, (i)))
#define olua_rawseti(L, idx, i)     (lua_rawseti(L, (idx), (i)))
#define olua_rawgeti(L, idx, i)     (lua_rawgeti(L, (idx), (i)))
#define olua_getfield(L, i, k)      (lua_getfield(L, (i), (k)))
#define olua_setfield(L, i, k)      (lua_setfield(L, (i), (k)))
#define olua_gettable(L, i)         (lua_gettable(L, (i)))
#define olua_settable(L, i)         (lua_settable(L, (i)))
#endif // LUA_VERSION_NUM

OLUA_END_DECLS


#ifdef __cplusplus
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
#endif //__cplusplus

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

#ifdef __cplusplus

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
void olua_postgc(lua_State *L, int idx);
#ifndef OLUA_HAVE_POSTGC
template <class T>
void olua_postgc(lua_State *L, int idx)
{
    int ownership = olua_getownership(L, idx);
    T *obj = olua_toobj<T>(L, idx);
    if (ownership == OLUA_OWNERSHIP_VM) {
        if (std::is_void<T>()) {
            free((void *)obj);
        } else {
            delete obj;
        }
    } else if (ownership == OLUA_OWNERSHIP_USERDATA) {
        obj->~T();
    }
    olua_setrawobj(L, idx, nullptr);
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
        const char *cls = olua_getluatype<T>(L);
        if (olua_unlikely(!cls || olua_getmetatable(L, cls) != LUA_TTABLE)) {
            luaL_error(L, "class metatable '%s' not found", cls ? cls : "NULL");
        }
        olua_newrawobj(L, (void *)value);
        lua_insert(L, -2);
        lua_setmetatable(L, -2);
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
        luaL_error(L, "expect enum '%s', got '%s'", olua_getluatype<olua::remove_cvrp_t<T>>(L),
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
    cls = olua_getluatype<T>(L, nullptr, cls);
    void *ptr = lua_newuserdata(L, sizeof(void *) + sizeof(T));
    Type *obj = new ((char *)ptr + sizeof(void *)) Type(value);
    *(void **)ptr = obj;
    olua_setmetatable(L, cls);
    olua_setownership(L, -1, OLUA_OWNERSHIP_USERDATA);
    return 1;
}

// std::shared_prt & std::weak_ptr
#define OLUA_SMART_PRT "smart_ptr"

template <template<class> class SmartPtr, class T>
int olua_smartptr_gc(lua_State *L)
{
    SmartPtr<T> *obj = olua_checkobj<SmartPtr<T>>(L, -1);
    olua_setrawobj(L, -1, nullptr);
    delete obj;
    return 0;
}

template <template<class> class SmartPtr, class T>
void oluacls_class_smartptr(lua_State *L)
{
    const char *smartptr_cls = olua_getluatype<SmartPtr<T>>(L);
    if (!smartptr_cls) {
        smartptr_cls = typeid(SmartPtr<T>).name();
        oluacls_class(L, smartptr_cls, nullptr);
        oluacls_func(L, "__gc", olua_smartptr_gc<SmartPtr, T>);
        olua_registerluatype<SmartPtr<T>>(L, smartptr_cls);
        lua_pop(L, 1);
    }
}

template <class T>
void olua_check_object(lua_State *L, int idx, std::shared_ptr<T> *value, const char *)
{
    idx = lua_absindex(L, idx);
    olua_loadref(L, idx, OLUA_SMART_PRT);
    *value = *olua_checkobj<std::shared_ptr<T>>(L, -1);
    lua_pop(L, 1);
}

template <class T>
int olua_push_object(lua_State *L, const std::shared_ptr<T> *value, const char *cls)
{
    if (!value->get()) {
        lua_pushnil(L);
        return 1;
    }
    
    oluacls_class_smartptr<std::shared_ptr, T>(L);
    
    std::shared_ptr<T> *newvalue = new std::shared_ptr<T>();
    *newvalue = *value;
    olua_pushobj<T>(L, newvalue->get(), cls);
    olua_setownership(L, -1, OLUA_OWNERSHIP_SLAVE); // skip gc, managed by smart ptr
    olua_pushobj<std::shared_ptr<T>>(L, newvalue);
    olua_addref(L, -2, OLUA_SMART_PRT, -1, OLUA_FLAG_SINGLE);
    lua_pop(L, 1);
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
    if (!value->lock().get()) {
        lua_pushnil(L);
        return 1;
    } else {
        std::shared_ptr<T> sp = value->lock();
        return olua_push_obj(L, &sp, cls);
    }
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
        olua_postgc<array<T>>(L, 1);
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
   
    array<T> *sub(size_t from, size_t to = -1)
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
        olua_postgc<pointer<T>>(L, 1);
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
#endif // __cplusplus

#endif
