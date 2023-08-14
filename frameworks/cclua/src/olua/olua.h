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

#define olua_strequal(s1, s2)       (strcmp((s1), (s2)) == 0)
#define olua_strstartwith(s1, s2)   (strstr((s1), (s2)) == s1)
    
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
OLUA_API void olua_import(lua_State *L, lua_CFunction m);
OLUA_API void olua_pusherrorfunc(lua_State *L);
OLUA_API int olua_pcall(lua_State *L, int nargs, int nresults);
    
// new, get or set raw user data
OLUA_API void *olua_newrawobj(lua_State *L, void *obj, size_t extra);
OLUA_API void olua_setrawobj(lua_State *L, int idx, void *obj);
OLUA_API void *olua_torawobj(lua_State *L, int idx);
OLUA_API bool olua_getrawobj(lua_State *L, void *obj);

// object status flag
#define OLUA_FLAG_DEL       1 << 0 // delete by user
#define OLUA_FLAG_GC        1 << 1 // gc
#define OLUA_FLAG_GC_DONE   1 << 2 // gc done
#define OLUA_FLAG_SKIP_GC   1 << 3 // skip gc
#define OLUA_FLAG_IN_HEAP      1 << 4 // object in heap, gc: delete or free
#define OLUA_FLAG_IN_USERDATA     1 << 5 // object in userdata, gc: obj->~T()
#define OLUA_FLAG_IN_POOL   1 << 6 // object in pool
OLUA_API void olua_setobjflag(lua_State *L, int idx, int flag);
OLUA_API bool olua_hasobjflag(lua_State *L, int idx, int flag);

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
OLUA_API void olua_print(lua_State *L, const char *fmt, ...);
OLUA_API void olua_printobj(lua_State *L, const char *tag, int idx);
OLUA_API int olua_indexerror(lua_State *L);
OLUA_API int olua_newindexerror(lua_State *L);
    
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
 *     .olua.ref.component = obj_component  -- OLUA_REF_ALONE
 *     .olua.ref.children = {               -- OLUA_REF_MULTI
 *         obj_child1 = true
 *         obj_child2 = true
 *         ...
 *     }
 * }
 */
#define OLUA_REF_ALONE  (1 << 1) // add & remove: only ref one
#define OLUA_REF_MULTI  (1 << 2) // add & remove: can ref one or more
#define OLUA_REF_TABLE  (1 << 3) // obj is table
#define OLUA_REF_REMOVE (1 << 4) // internal use
#define OLUA_NOREFSTORE INT_MIN
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
OLUA_API void olua_setfieldfunc(lua_State *L, int idx, const char *field, lua_CFunction fn);
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

#endif
