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

#ifdef OLUA_DEBUG
#define olua_assert(e, msg) assert((e) && (msg))
#else
#define olua_assert(e, msg) ((void)0)
#endif

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
#define OLUA_EXCLUDE        __attribute__((annotate("exclude")))
#define OLUA_ADDREF(...)    __attribute__((annotate("@addref("#__VA_ARGS__")")))
#define OLUA_DEFREF(...)    __attribute__((annotate("@delref("#__VA_ARGS__")")))
#define OLUA_PACK           __attribute__((annotate("@pack")))
#define OLUA_UNPACK         __attribute__((annotate("@unpack")))
#define OLUA_NULLABLE       __attribute__((annotate("@nullable")))
#define OLUA_POSTNEW        __attribute__((annotate("@postnew")))
#define OLUA_READONLY       __attribute__((annotate("@readonly")))
#define OLUA_OPTIONAL       __attribute__((annotate("@optional")))
#define OLUA_RET            __attribute__((annotate("@ret")))
#else
#define OLUA_EXCLUDE
#define OLUA_ADDREF(...)
#define OLUA_DEFREF(...)
#define OLUA_PACK
#define OLUA_UNPACK
#define OLUA_NULLABLE
#define OLUA_POSTNEW
#define OLUA_READONLY
#define OLUA_OPTIONAL
#define OLUA_RET
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
OLUA_API size_t olua_objcount(lua_State *L);
OLUA_API bool olua_isdebug(lua_State *L);
    
// compare raw type of value
#define olua_isfunction(L,n)        (lua_type(L, (n)) == LUA_TFUNCTION)
#define olua_istable(L,n)           (lua_type(L, (n)) == LUA_TTABLE)
#define olua_islightuserdata(L,n)   (lua_type(L, (n)) == LUA_TLIGHTUSERDATA)
#define olua_isuserdata(L,n)        (lua_type(L, (n)) == LUA_TUSERDATA)
#define olua_isnil(L,n)             (lua_type(L, (n)) == LUA_TNIL)
#define olua_isnoneornil(L, n)      (lua_type(L, (n)) <= 0)
#define olua_isboolean(L,n)         (lua_type(L, (n)) == LUA_TBOOLEAN)
#define olua_isstring(L,n)          (lua_type(L, (n)) == LUA_TSTRING)
#define olua_isnumber(L,n)          (lua_type(L, (n)) == LUA_TNUMBER)
#define olua_isthread(L,n)          (lua_type(L, (n)) == LUA_TTHREAD)
OLUA_API bool olua_isinteger(lua_State *L, int idx);

#define olua_strequal(s1, s2)       (strcmp((s1), (s2)) == 0)
    
// check or get raw value
#define olua_tonumber(L, i)         (lua_tonumber(L, (i)))
#define olua_tointeger(L, i)        (lua_tointeger(L, (i)))
#define olua_tostring(L, i)         (lua_tostring(L, (i)))
#define olua_tolstring(L, i, l)     (lua_tolstring(L, (i), (l)))
#define olua_toboolean(L, i)        (lua_toboolean(L, (i)))
#define olua_checkstring(L, i)      (olua_checklstring(L, (i), NULL))
#define olua_optinteger(L, i, d)    (luaL_opt(L, olua_checkinteger, (i), (d)))
#define olua_optstring(L, i, d)     (luaL_opt(L, olua_checkstring, (i), (d)))
#define olua_optlstring(L, i, d, l) (luaL_opt(L, olua_checklstring, (i), (d), (l)))
#define olua_optnumber(L, i, d)     (luaL_opt(L, olua_checknumber, (i), (d)))
#define olua_optboolean(L, i, d)    (olua_isnoneornil(L, (i)) ? (d) : olua_toboolean(L, (i)) != 0)
OLUA_API lua_Integer olua_checkinteger(lua_State *L, int idx);
OLUA_API lua_Number olua_checknumber(lua_State *L, int idx);
OLUA_API const char *olua_checklstring (lua_State *L, int arg, size_t *len);
OLUA_API bool olua_checkboolean(lua_State *L, int idx);

// raw set or get value with field
OLUA_API int olua_rawgetf(lua_State *L, int idx, const char *field);
OLUA_API void olua_rawsetf(lua_State *L, int idx, const char *field);

// call 'func' and store result in '_LOADED' table without change stack
OLUA_API void olua_require(lua_State *L, const char *name, lua_CFunction func);

#define olua_callfunc(L, fn) (lua_pushcfunction(L, (fn)), lua_call(L, 0, 0))
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
OLUA_API const char *olua_objstring(lua_State *L, int idx);
OLUA_API int olua_indexerror(lua_State *L);
OLUA_API int olua_newindexerror(lua_State *L);

// ownership
#define OLUA_OWNERSHIP_NONE 0
#define OLUA_OWNERSHIP_VM   1
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
OLUA_API void olua_getreftable(lua_State *L, int idx, const char *name);
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
OLUA_API void oluacls_const(lua_State *L, const char *name);
#define oluacls_const_value(L, k, v)    (lua_pushvalue(L, (v)), oluacls_const(L, (k)))
#define oluacls_const_bool(L, k, v)     (lua_pushboolean(L, (v)), oluacls_const(L, (k)))
#define oluacls_const_number(L, k, v)   (lua_pushnumber(L, (v)), oluacls_const(L, (k)))
#define oluacls_const_integer(L, k, v)  (lua_pushinteger(L, (v)), oluacls_const(L, (k)))
#define oluacls_const_string(L, k, v)   (lua_pushstring(L, (v)), oluacls_const(L, (k)))
    
// get or set value for table
OLUA_API const char *olua_checkfieldstring(lua_State *L, int idx, const char *field);
OLUA_API lua_Number olua_checkfieldnumber(lua_State *L, int idx, const char *field);
OLUA_API lua_Integer olua_checkfieldinteger(lua_State *L, int idx, const char *field);
OLUA_API bool olua_checkfieldboolean(lua_State *L, int idx, const char *field);
OLUA_API void olua_setfieldnumber(lua_State *L, int idx, const char *field, lua_Number value);
OLUA_API void olua_setfieldinteger(lua_State *L, int idx, const char *field, lua_Integer value);
OLUA_API void olua_setfieldstring(lua_State *L, int idx, const char *field, const char *value);
OLUA_API void olua_setfieldboolean(lua_State *L, int idx, const char *field, bool value);
OLUA_API const char *olua_optfieldstring(lua_State *L, int idx, const char *field, const char *def);
OLUA_API lua_Number olua_optfieldnumber(lua_State *L, int idx, const char *field, lua_Number def);
OLUA_API lua_Integer olua_optfieldinteger(lua_State *L, int idx, const char *field, lua_Integer def);
OLUA_API bool olua_optfieldboolean(lua_State *L, int idx, const char *field, bool def);
OLUA_API bool olua_hasfield(lua_State *L, int idx, const char *field);
    
OLUA_API int luaopen_olua(lua_State *L);
    
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
#include <map>
#include <unordered_map>

#if __cplusplus >= 201703L
#include <string_view>
#endif

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
template <typename T> inline T *olua_toobj(lua_State *L, int idx);

/**
 * Handle the status of object after push, you can do some jobs
 * according to the object status. For example, retain object in push and
 * release object in __gc method.
 *
 *  #define OLUA_HAVE_POSTPUSH
 *  template <typename T> void olua_postpush(lua_State *L, T* obj, int status)
 *  {
 *      if (std::is_base_of<Object, T>::value && (status == OLUA_OBJ_NEW
 *          || status == OLUA_OBJ_UPDATE)) {
 *          ((Object *)obj)->retain();
 *      }
 *  }
 */
template <typename T>
void olua_postpush(lua_State *L, T* obj, int status);
#ifndef OLUA_HAVE_POSTPUSH
template <typename T>
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
 *      olua_push_cppobj(L, obj, "Object");
 *      olua_postnew(L, obj);
 *      olua_endinvoke(L);
 *      return 1;
 *  }
 *
 *  #define OLUA_HAVE_POSTNEW
 *  template <typename T> void olua_postnew(lua_State *L, T *obj)
 *  {
 *      if (std::is_base_of<Object, T>::value) {
 *          ((Object *)obj)->autorelease();
 *      } else {
 *          olua_assert(obj == olua_toobj<T>(L, -1), "must be same object");
 *          olua_setownership(L, -1, OLUA_OWNERSHIP_VM);
 *      }
 *  }
 *
 */
template <typename T>
void olua_postnew(lua_State *L, T *obj);
#ifndef OLUA_HAVE_POSTNEW
template <typename T>
void olua_postnew(lua_State *L, T *obj)
{
    olua_assert(obj == olua_toobj<T>(L, -1), "must be same object");
    olua_setownership(L, -1, OLUA_OWNERSHIP_VM);
}
#endif

/**
 * delete object which belong to lua vm.
 */
template <typename T>
void olua_postgc(lua_State *L, int idx);
#ifndef OLUA_HAVE_POSTGC
template <typename T>
void olua_postgc(lua_State *L, int idx)
{
    if (olua_getownership(L, idx) == OLUA_OWNERSHIP_VM) {
        T *obj = olua_toobj<T>(L, idx);
        olua_setrawobj(L, idx, nullptr);
        if (std::is_void<T>()) {
            free(obj);
        } else {
            delete obj;
        }
    }
}
#endif

/**
 * register or get lua type for c++ class.
 * Define OLUA_HAVE_LUATYPE when you has implemention
 */
OLUA_BEGIN_DECLS
OLUA_API void olua_registerluatype(lua_State *L, const char *type, const char *cls);
OLUA_API const char *olua_getluatype(lua_State *L, const char *cls);
OLUA_END_DECLS

template <typename T>
inline void olua_registerluatype(lua_State *L, const char *cls)
{
    olua_registerluatype(L, typeid(T).name(), cls);
}

template <typename T>
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

template <>
inline const char *olua_getluatype<void>(lua_State *L, const void *obj, const char *cls)
{
    return cls == NULL ? OLUA_VOIDCLS : cls;
}

template <typename T>
inline const char *olua_getluatype(lua_State *L)
{
    return olua_getluatype<T>(L, nullptr, nullptr);
}

template <typename T>
inline bool olua_isa(lua_State *L, int idx)
{
    return olua_isa(L, idx, olua_getluatype<T>(L));
}

template <typename T>
inline void *olua_pushclassobj(lua_State *L)
{
    return olua_pushclassobj(L, olua_getluatype<T>(L));
}

template <typename T>
inline T *olua_toobj(lua_State *L, int idx)
{
    return (T *)olua_toobj(L, idx, olua_getluatype<T>(L));
}

template <typename T>
inline T *olua_checkobj(lua_State *L, int idx)
{
    return (T *)olua_checkobj(L, idx, olua_getluatype<T>(L));
}

template <typename T>
int olua_pushobj(lua_State *L, const T *value, const char *cls)
{
    cls = olua_getluatype(L, value, cls);
    olua_postpush(L, (T *)value, olua_pushobj(L, (void *)value, cls));
    return 1;
}

template <typename T>
inline int olua_pushobj(lua_State *L, const T *value)
{
    return olua_pushobj<T>(L, value, nullptr);
}

template <typename T>
inline int olua_pushobj_as(lua_State *L, const T *value)
{
    const char *cls = olua_getluatype<T>(L);
    olua_postpush(L, (T *)value, olua_pushobj(L, (void *)value, cls));
    return 1;
}

template <typename T>
inline void *olua_newobjstub(lua_State *L)
{
    return olua_newobjstub(L, olua_getluatype<T>(L));
}

template <typename T>
inline int olua_pushobjstub(lua_State *L, T *value, void *stub, const char *cls)
{
    cls = olua_getluatype(L, value, cls);
    return olua_pushobjstub(L, (void *)value, stub, cls);
}

template <typename T>
inline int olua_pushobjstub(lua_State *L, T *value, void *stub)
{
    return olua_pushobjstub<T>(L, value, stub, nullptr);
}
#endif // __cplusplus


// convertor between c and lua, use for code generation
#define olua_push_bool(L, v)        (lua_pushboolean(L, (v)), 1)
#define olua_check_bool(L, i, v)    (*(v) = olua_checkboolean(L, (i)))
#define olua_is_bool(L, i)          (olua_isboolean(L, (i)))

#define olua_push_string(L, v)      (lua_pushstring(L, (v)), 1)
#define olua_check_string(L, i, v)  (*(v) = olua_checkstring(L, (i)))
#define olua_is_string(L, i)        (olua_isstring(L, (i)))

#define olua_push_number(L, v)      (lua_pushnumber(L, (v)), 1)
#define olua_check_number(L, i, v)  (*(v) = olua_checknumber(L, (i)))
#define olua_is_number(L, i)        (olua_isnumber(L, (i)))

#define olua_push_int(L, v)         (lua_pushinteger(L, (v)), 1)
#define olua_check_int(L, i, v)     (*(v) = olua_checkinteger(L, (i)))
#define olua_is_int(L, i)           (olua_isinteger(L, (i)))

#define olua_push_uint(L, v)        (lua_pushinteger(L, (lua_Integer)(v)), 1)
#define olua_check_uint(L, i, v)    (*(v) = (lua_Unsigned)olua_checkinteger(L, (i)))
#define olua_is_uint(L, i)          (olua_isinteger(L, (i)))

#define olua_push_obj(L, o, c)      (olua_pushobj(L, (o), (c)), 1)
#define olua_check_obj(L, i, v, c)  (*(v) = olua_checkobj(L, (i), (c)))
#define olua_to_obj(L, i, v, c)     (*(v) = olua_toobj(L, (i), (c)))
#define olua_is_obj(L, i, c)        (olua_isa(L, (i), (c)))

// convertor between c++ and lua, use for code generation
#ifdef __cplusplus

// c++ object
#define olua_to_cppobj(L, i, v, c)      (olua_to_obj(L, (i), (v), (c)))
#define olua_check_cppobj(L, i, v, c)   (olua_check_obj(L, (i), (v), (c)))
#define olua_is_cppobj(L, i, c)         (olua_is_obj(L, (i), (c)))

template <typename T> inline
int olua_push_cppobj(lua_State *L, const T *value, const char *cls)
{
    return olua_pushobj<T>(L, value, cls);
}

template <typename T> inline
int olua_push_cppobj(lua_State *L, const T *value)
{
    return olua_pushobj<T>(L, value, nullptr);
}

// std::string
#define olua_is_std_string(L, i)    (olua_isstring(L, (i)))
#define olua_push_std_string(L, v)  (lua_pushlstring(L, (v).c_str(), (v).length()), 1)

static inline void olua_check_std_string(lua_State *L, int idx, std::string *value)
{
    size_t len;
    const char *str = olua_checklstring(L, idx, &len);
    *value = std::string(str, len);
}

#if __cplusplus >= 201703L
#define olua_is_std_string_view(L, i)    (olua_isstring(L, (i)))
#define olua_push_std_string_view(L, v)  (lua_pushlstring(L, (v).data(), (v).size()), 1)

static inline void olua_check_std_string_view(lua_State *L, int idx, std::string_view *value)
{
    size_t len;
    const char *str = olua_checklstring(L, idx, &len);
    *value = std::string_view(str, len);
}
#endif

// map
#define olua_is_map(L, i)   (olua_istable(L, (i)))

template <class K, class V, class Map>
void olua_insert_map(Map *map, K key, V value)
{
    map->insert(std::make_pair(key, value));
}

template <class K, class V, class Map>
void olua_foreach_map(const Map *map, const std::function<void(K, V)> &callback)
{
    for (auto itor : (*map)) {
        callback(itor.first, itor.second);
    }
}

template <class K,  class V, class Map>
int olua_push_map(lua_State *L, const Map *map, const std::function<void(K, V)> &push)
{
    lua_newtable(L);
    olua_foreach_map<K, V>(map, [=](K key, V value) {
        push(key, value);
        lua_rawset(L, -3);
    });
    return 1;
}

template <class K,  class V, class Map>
void olua_check_map(lua_State *L, int idx, Map *map, const std::function<void(K *, V *)> &check)
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
void olua_insert_array(std::vector<T> *array, T value)
{
    array->push_back(value);
}

template <class T>
void olua_insert_array(std::set<T> *array, T value)
{
    array->insert(value);
}

template <class T, class Array>
void olua_foreach_array(const Array *array, const std::function<void(T)> &callback)
{
    for (auto itor : (*array)) {
        callback(itor);
    }
}

#define olua_is_array(L, i)     (olua_istable(L, (i)))

template <class T, class Array>
int olua_push_array(lua_State *L, const Array *array, const std::function<void(T)> &push)
{
    int idx = 0;
    lua_newtable(L);
    olua_foreach_array<T>(array, [=](T value) mutable {
        push(value);
        lua_rawseti(L, -2, ++idx);
    });
    return 1;
}

template <class T, class Array>
void olua_check_array(lua_State *L, int idx, Array *array, const std::function<void(T *)> &check)
{
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);
    int total = (int)lua_rawlen(L, idx);
    for (int i = 1; i <= total; i++) {
        T obj;
        lua_rawgeti(L, idx, i);
        check(&obj);
        olua_insert_array<T>(array, obj);
        lua_pop(L, 1);
    }
}

template <typename T, class Array>
void olua_pack_array(lua_State *L, int idx, Array *array, const std::function<void(T *)> &check)
{
    idx = lua_absindex(L, idx);
    int total = (int)(lua_gettop(L) - (idx - 1));
    for (int i = 0; i < total; i++) {
        T obj;
        lua_pushvalue(L, idx + i);
        check(&obj);
        olua_insert_array<T>(array, obj);
        lua_pop(L, 1);
    }
}

// callback
OLUA_BEGIN_DECLS
OLUA_API int olua_callback_wrapper(lua_State *L);
OLUA_API bool olua_is_callback(lua_State *L, int idx, const char *cls);
OLUA_API int olua_push_callback(lua_State *L, const char *cls);
OLUA_END_DECLS

template <typename T>
int olua_push_callback(lua_State *L, const T *value, const char *cls)
{
    return olua_push_callback(L, olua_getluatype(L, value, cls));
}

template <typename T> inline
void olua_check_callback(lua_State *L, int idx, T *value, const char *cls)
{
    luaL_checktype(L, idx, LUA_TFUNCTION);
}
#endif // __cplusplus

#endif
