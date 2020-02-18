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

#ifndef __OLUA_H__
#define __OLUA_H__

#ifdef __cplusplus
extern "C" {
#endif
    
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
    
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

#ifndef OLUA_API
#define OLUA_API LUALIB_API
#endif

#define olua_noapi(api) static_assert(false, #api" is not defined")
    
#ifndef olua_mainthread
#define olua_mainthread() olua_noapi(olua_mainthread)
#endif

#ifndef olua_postpush
#define olua_postpush(L, obj, n) olua_noapi(olua_postpush)
#endif

#ifndef olua_postnew
#define olua_postnew(L, obj) olua_noapi(olua_postnew)
#endif
    
#ifndef olua_startcmpdelref
#define olua_startcmpdelref(L, i, n) olua_noapi(olua_startcmpdelref)
#define olua_endcmpdelref(L, i, n)   olua_noapi(olua_endcmpdelref)
#endif
    
#ifndef olua_startinvoke
#define olua_startinvoke(L) ((void)L)
#define olua_endinvoke(L)   ((void)L)
#endif

// callback status
#define OLUA_CALL_OK     0
#define OLUA_CALL_MISS   1
#define OLUA_CALL_ERR    2
    
// object status
#define OLUA_OBJ_EXIST  0
#define OLUA_OBJ_NEW    1
    
#define OLUA_VOIDCLS "void *"
    
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
#define olua_isinteger(L,n)         (lua_isinteger(L, (n)))
#define olua_isthread(L,n)          (lua_type(L, (n)) == LUA_TTHREAD)
    
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

typedef struct {
    size_t objcount;
    size_t poolsize;
    bool poolenabled;
    bool debug;
} olua_vmstatus_t;

OLUA_API olua_vmstatus_t *olua_vmstatus(lua_State *L);

#define olua_addobjcount(L)  (++olua_vmstatus(L)->objcount)
#define olua_subobjcount(L)  (--olua_vmstatus(L)->objcount)
#define olua_objcount(L)     (olua_vmstatus(L)->objcount)
    
OLUA_API lua_Integer olua_checkinteger(lua_State *L, int idx);
OLUA_API lua_Number olua_checknumber(lua_State *L, int idx);
OLUA_API const char *olua_checklstring (lua_State *L, int arg, size_t *len);
OLUA_API bool olua_checkboolean(lua_State *L, int idx);
OLUA_API int olua_rawgetf(lua_State *L, int idx, const char *field);
OLUA_API void olua_rawsetf(lua_State *L, int idx, const char *field);
OLUA_API void olua_require(lua_State *L, const char *name, lua_CFunction func);

#define olua_dofunc(L, fn) (lua_pushcfunction(L, (fn)), lua_call(L, 0, 0))
OLUA_API int olua_geterrorfunc(lua_State *L);
OLUA_API int olua_pcall(lua_State *L, int nargs, int nresults);
OLUA_API int olua_pcallref(lua_State *L, int funcref, int nargs, int nresults);
    
// manipulate userdata api
#define olua_newuserdata(L, obj, T)  (*(T *)lua_newuserdata(L, sizeof(T)) = (obj))
#define olua_touserdata(L, i, T)     (*(T *)lua_touserdata(L, (i)))
#define olua_setuserdata(L, i, o)    (*(void **)lua_touserdata(L, (i)) = (o))
OLUA_API bool olua_getuserdata(lua_State *L, void *obj);
OLUA_API const char *olua_typename(lua_State *L, int idx);
OLUA_API bool olua_isa(lua_State *L, int idx, const char *cls);
OLUA_API int olua_pushobj(lua_State *L, void *obj, const char *cls);
OLUA_API void *olua_checkobj(lua_State *L, int idx, const char *cls);
OLUA_API void *olua_toobj(lua_State *L, int idx, const char *cls);
OLUA_API const char *olua_objstring(lua_State *L, int idx);
    
// optimize temporary userdata
#define olua_enable_objpool(L)  (olua_vmstatus(L)->poolenabled = true)
#define olua_disable_objpool(L) (olua_vmstatus(L)->poolenabled = false)
#define olua_push_objpool(L)    (olua_vmstatus(L)->poolsize)
OLUA_API void olua_pop_objpool(lua_State *L, size_t level);

// callback functions
// for olua_setcallback
#define OLUA_TAG_NEW          0
#define OLUA_TAG_REPLACE      1
// for olua_removecallback, tag format: .callback#%d$cls@%s
#define OLUA_TAG_WHOLE        2 // compare whole tag string
#define OLUA_TAG_SUBEQUAL     3 // compare substring after '@'
#define OLUA_TAG_SUBSTARTWITH 4 // compare substring after '@'
OLUA_API const char *olua_setcallback(lua_State *L, void *obj, const char *tag, int func, int mode);
OLUA_API int olua_getcallback(lua_State *L, void *obj, const char *tag, int mode);
OLUA_API void olua_removecallback(lua_State *L, void *obj, const char *tag, int mode);
OLUA_API int olua_callback(lua_State *L, void *obj, const char *func, int argc);
    
// class store, store static callback or other
OLUA_API void *olua_pushclassobj(lua_State *L, const char *cls);

// get or set variable in userdata
OLUA_API int olua_getvariable(lua_State *L, int idx);
OLUA_API void olua_setvariable(lua_State *L, int idx);
    
// lua style ref
OLUA_API int olua_ref(lua_State *L, int idx);
OLUA_API int olua_reffunc(lua_State *L, int idx);
OLUA_API void olua_unref(lua_State *L, int ref);
OLUA_API void olua_getref(lua_State *L, int ref);
    
// for ref chain, callback store in the uservalue of userdata
#define OLUA_FLAG_EXCLUSIVE (1 << 1) // add & remove: only ref one
#define OLUA_FLAG_COEXIST   (1 << 2) // add & remove: can ref one or more
#define OLUA_FLAG_ARRAY     (1 << 3) // add & remove:
#define OLUA_FLAG_REMOVE    (1 << 4) // internal use
typedef bool (*olua_DelRefVisitor)(lua_State *L, int idx);
OLUA_API void olua_getreftable(lua_State *L, int idx, const char *name);
OLUA_API void olua_addref(lua_State *L, int idx, const char *name, int obj, int flags);
OLUA_API void olua_delref(lua_State *L, int idx, const char *name, int obj, int flags);
OLUA_API void olua_delallrefs(lua_State *L, int idx, const char *name);
OLUA_API void olua_visitrefs(lua_State *L, int idx, const char *name, olua_DelRefVisitor walk);

//
// lua class model
//  class A = {
//      __name = 'A'
//      .agent = class A agent      -- set funcs, props and consts
//      .isa = {
//          copy(B['.isa'])
//          A = true
//      }
//      .func = {
//          __index = B['.func']    -- cache after access
//          dosomething = func
//      }
//      .get = {
//          __index = B['.get']     -- cache after access
//          classname = const_get(obj, "A")
//          super = const_get(obj, B)
//          name = get_name(obj, name)
//      }
//      .set = {
//          __index = B['.set']     -- cache after access
//          name = set_name(obj, name, value)
//      }
//      ...__gc = cls_metamethod    -- .func[..._gc]
//  }
//
OLUA_API void oluacls_class(lua_State *L, const char *cls, const char *supercls);
OLUA_API void oluacls_prop(lua_State *L, const char *name, lua_CFunction getter, lua_CFunction setter);
OLUA_API void oluacls_func(lua_State *L, const char *name, lua_CFunction func);
OLUA_API void oluacls_const(lua_State *L, const char *name);
#define oluacls_const_value(L, k, v)    (lua_pushvalue(L, (v)), oluacls_const(L, (k)))
#define oluacls_const_bool(L, k, v)     (lua_pushboolean(L, (v)), oluacls_const(L, (k)))
#define oluacls_const_number(L, k, v)   (lua_pushnumber(L, (v)), oluacls_const(L, (k)))
#define oluacls_const_integer(L, k, v)  (lua_pushinteger(L, (v)), oluacls_const(L, (k)))
#define oluacls_const_string(L, k, v)   (lua_pushstring(L, (v)), oluacls_const(L, (k)))
    
// object convertor for c++/c lua
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
typedef lua_Integer lua_Unsigned;
#define LUA_OK 0
#define LUA_PRELOAD_TABLE "_PRELOAD"
#define LUA_LOADED_TABLE "_LOADED"
#define LUA_LOADER_TABLE "loaders"
#define lua_rawlen(L, i) lua_objlen(L, (i))
#define olua_newlib(L,l) {                              \
    lua_createtable(L, 0, sizeof(l)/sizeof((l)[0]) - 1);\
    olua_setfuncs(L,(l),0);                             \
}
OLUA_API void lua_setuservalue(lua_State *L, int idx);
OLUA_API int lua_getuservalue(lua_State *L, int idx);
OLUA_API int lua_absindex(lua_State *L, int idx);
OLUA_API int lua_isinteger(lua_State *L, int idx);
OLUA_API int olua_getsubtable (lua_State *L, int idx, const char *fname);
OLUA_API void olua_setfuncs(lua_State *L, const luaL_Reg *l, int nup);
OLUA_API void olua_traceback(lua_State *L, lua_State *L1, const char *msg, int level);
OLUA_API void olua_requiref(lua_State *L, const char *modname, lua_CFunction openf, int glb);
OLUA_API void *olua_testudata(lua_State *L, int ud, const char *tname);
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
#define olua_newlib(L, l)           (luaL_newlib(L, (l)))
#define olua_requiref(L, mn, f, g)  (luaL_requiref(L, (mn), (f), (g)))
#define olua_setfuncs(L, l, nup)    (luaL_setfuncs(L, (l), (nup)))
#define olua_testudata(L, ud, tn)   (luaL_testudata(L, (ud), (tn)))
#define olua_getsubtable(L, i, fn)  (luaL_getsubtable(L, (i), (fn)))
#define olua_traceback(L, L1, m, l) (luaL_traceback(L, L1, (m), (l)))
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
#endif
    
// for debug
#ifdef OLUA_DEBUG
#define olua_assert(e) assert(e)
#else
#define olua_assert(e) ((void)0)
#endif

#ifdef __cplusplus
}
#endif

#endif
