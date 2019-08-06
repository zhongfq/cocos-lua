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
    
// callback status
#define OLUA_OK     0
#define OLUA_MISS   1
#define OLUA_ERR    2
    
// object status
#define OLUA_EXIST  0
#define OLUA_NEW    1
    
#define OLUA_VOIDCLS "void *"
    
#ifndef olua_mainthread
#define olua_mainthread() assert(false && "not define olua_mainthread")
#endif
    
#ifndef olua_startcmpunref
#define olua_startcmpunref(L, i, n) assert(false && "not define olua_startcmpunref")
#define olua_endcmpunref(L, i, n) assert(false && "not define olua_endcmpunref")
#endif
    
#ifndef olua_startinvoke
#define olua_startinvoke(L) ((void)L)
#define olua_endinvoke(L)   ((void)L)
#endif
    
// compare the value raw type
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
    
// check or get the raw value
#define olua_newuserdata(L, obj, T) (*(T*)lua_newuserdata(L, sizeof(T)) = (obj))
#define olua_touserdata(L, n, T)    (*(T*)lua_touserdata(L, (n)))
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
    size_t sizepool;
    bool usingpool;
} olua_metadata_t;

// metadata point must treat olua_metadata_t as first member
LUALIB_API lua_State *olua_newstate(olua_metadata_t *mt);
#define olua_getmetadata(L, T) (*(T*)lua_getextraspace(L))
    
#define olua_addobjcount(L)  olua_changeobjcount(L, 1)
#define olua_subobjcount(L)  olua_changeobjcount(L, -1)
#define olua_objcount(L)     olua_changeobjcount(L, 0)
    
LUALIB_API lua_Integer olua_checkinteger(lua_State *L, int idx);
LUALIB_API lua_Number olua_checknumber(lua_State *L, int idx);
LUALIB_API const char *olua_checklstring (lua_State *L, int arg, size_t *len);
LUALIB_API bool olua_checkboolean(lua_State *L, int idx);
LUALIB_API int olua_rawgetf(lua_State *L, int idx, const char *field);
LUALIB_API void olua_rawsetf(lua_State *L, int idx, const char *field);
LUALIB_API size_t olua_changeobjcount(lua_State *L, int add);
LUALIB_API void olua_require(lua_State *L, const char *name, lua_CFunction func);
LUALIB_API void olua_preload(lua_State *L, const char *name, lua_CFunction func);
LUALIB_API int olua_geterrorfunc(lua_State *L);
    
// manipulate userdata api
LUALIB_API const char *olua_typename(lua_State *L, int idx);
LUALIB_API bool olua_isa(lua_State *L, int idx, const char *cls);
LUALIB_API int olua_pushobj(lua_State *L, void *obj, const char *cls);
LUALIB_API bool olua_getobj(lua_State *L, void *obj);
LUALIB_API void *olua_checkobj(lua_State *L, int idx, const char *cls);
LUALIB_API void *olua_toobj(lua_State *L, int idx, const char *cls);
LUALIB_API const char *olua_objstring(lua_State *L, int idx);
    
// optimize temporary userdata
LUALIB_API void olua_enable_objpool(lua_State *L);
LUALIB_API void olua_disable_objpool(lua_State *L);
LUALIB_API size_t olua_push_objpool(lua_State *L);
LUALIB_API void olua_pop_objpool(lua_State *L, size_t level);
    
typedef enum {
    // for olua_setcallback
    OLUA_TAG_NEW,
    OLUA_TAG_REPLACE,
    // for olua_removecallback
    OLUA_TAG_EQUAL,
    OLUA_TAG_ENDWITH,
    OLUA_TAG_WILDCARD
} olua_tag_mode;

// callback functions
LUALIB_API const char *olua_setcallback(lua_State *L, void *obj, const char *tag, int func, olua_tag_mode mode);
LUALIB_API void olua_getcallback(lua_State *L, void *obj, const char *tag, olua_tag_mode mode);
LUALIB_API void olua_removecallback(lua_State *L, void *obj, const char *tag, olua_tag_mode mode);
LUALIB_API int olua_callback(lua_State *L, void *obj, const char *func, int argc);
#define olua_makecallbacktag(tag) (tag)
    
// class store, store static callback or other
LUALIB_API void olua_getstore(lua_State *L, const char *cls);
LUALIB_API void *olua_getstoreobj(lua_State *L, const char *cls);

// get or set variable in userdata
LUALIB_API int olua_getvariable(lua_State *L, int idx);
LUALIB_API void olua_setvariable(lua_State *L, int idx);
    
// lua style ref
LUALIB_API int olua_ref(lua_State *L, int idx);
LUALIB_API int olua_reffunc(lua_State *L, int idx);
LUALIB_API void olua_unref(lua_State *L, int ref);
LUALIB_API void olua_getref(lua_State *L, int ref);
    
// for ref chain, if callback store in userdata, it will keep callback available
typedef bool (*olua_WalkFunction)(lua_State *L, int idx);
LUALIB_API void olua_getreftable(lua_State *L, int idx, const char *name);
LUALIB_API void olua_singleref(lua_State *L, int idx, const char *name, int obj);
LUALIB_API void olua_singleunref(lua_State *L, int idx, const char *name);
LUALIB_API void olua_mapref(lua_State *L, int idx, const char *name, int obj);
LUALIB_API void olua_maprefarray(lua_State *L, int idx, const char *name, int obj);
LUALIB_API void olua_mapunref(lua_State *L, int idx, const char *name, int obj);
LUALIB_API void olua_mapwalkunref(lua_State *L, int idx, const char *name, olua_WalkFunction walk);
LUALIB_API void olua_unrefall(lua_State *L, int idx, const char *name);

//
// lua class model
//  class A = {
//      classname = 'A'
//      super = B
//      .isa = {
//          copy(B['.isa'])
//          A.classname = true
//      }
//      .func = {
//          copy(B['.func'])
//          dosomething = func,
//      }
//      .get = {
//          copy(B['.get'])
//          classname = const_get(obj, "classname")
//          super = const_get(obj, "super")
//          name = get_name(obj, name)
//      }
//      .set = {
//          copy(['B.set'])
//          name = set_name(obj, name, value)
//      }
//      __metafunc
//  }
//
LUALIB_API void oluacls_class(lua_State *L, const char *cls, const char *supercls);
LUALIB_API void oluacls_createclassproxy(lua_State *L);
LUALIB_API void oluacls_prop(lua_State *L, const char *name, lua_CFunction getter, lua_CFunction setter);
LUALIB_API void oluacls_func(lua_State *L, const char *name, lua_CFunction func);
LUALIB_API void oluacls_const(lua_State *L, const char *name);
#define oluacls_const_bool(L, k, v) {       \
    lua_pushboolean(L, (v));                \
    oluacls_const(L, (k));                  \
}
#define oluacls_const_number(L, k, v) {     \
    lua_pushnumber(L, (v));                 \
    oluacls_const(L, (k));                  \
}
#define oluacls_const_integer(L, k, v) {    \
    lua_pushinteger(L, (v));                \
    oluacls_const(L, (k));                  \
}
#define oluacls_const_string(L, k, v) {     \
    lua_pushstring(L, (v));                 \
    oluacls_const(L, (k));                  \
}
    
#define olua_push_bool(L, v)        (lua_pushboolean(L, (v)), 1)
#define olua_check_bool(L, i, v)    (*(v) = olua_checkboolean(L, (i)))
#define olua_opt_bool(L, i, v, d)   (*(v) = olua_optboolean(L, (i), (d)))
#define olua_is_bool(L, i)          (olua_isboolean(L, (i)))

#define olua_push_string(L, v)      (lua_pushstring(L, (v)), 1)
#define olua_check_string(L, i, v)  (*(v) = olua_checkstring(L, (i)))
#define olua_opt_string(L, i, v, d) (*(v) = olua_optstring(L, (i), (d)))
#define olua_is_string(L, i)        (olua_isstring(L, (i)))

#define olua_push_number(L, v)      (lua_pushnumber(L, (v)), 1)
#define olua_check_number(L, i, v)  (*(v) = olua_checknumber(L, (i)))
#define olua_opt_number(L, i, v, d) (*(v) = olua_optnumber(L, (i), (d)))
#define olua_is_number(L, i)        (olua_isnumber(L, (i)))

#define olua_push_int(L, v)         (lua_pushinteger(L, (v)), 1)
#define olua_check_int(L, i, v)     (*(v) = olua_checkinteger(L, (i)))
#define olua_opt_int(L, i, v, d)    (*(v) = olua_optinteger(L, (i), (d)))
#define olua_is_int(L, i)           (olua_isinteger(L, (i)))

#define olua_push_uint(L, v)        (lua_pushinteger(L, (lua_Integer)(v)), 1)
#define olua_check_uint(L, i, v)    (*(v) = (lua_Unsigned)olua_checkinteger(L, (i)))
#define olua_opt_uint(L, i, v, d)   (*(v) = (lua_Unsigned)olua_optinteger(L, (i), (lua_Integer)(d)))
#define olua_is_uint(L, i)          (olua_isinteger(L, (i)))

#define olua_push_obj(L, o, c)      (olua_pushobj(L, (o), (c)), 1)
#define olua_check_obj(L, i, v, c)  (*(v) = olua_checkobj(L, (i), (c)))
#define olua_opt_obj(L, i, v, c, d) (olua_isnil(L, (i)) ? (*(v) = (d)) : olua_check_obj(L, (i), (v), (c)))
#define olua_to_obj(L, i, v, c)     (*(v) = olua_toobj(L, (i), (c)))
#define olua_is_obj(L, i, c)        (olua_isa(L, (i), (c)))
    
// get or set value for table
LUALIB_API const char *olua_checkfieldstring(lua_State *L, int idx, const char *field);
LUALIB_API lua_Number olua_checkfieldnumber(lua_State *L, int idx, const char *field);
LUALIB_API lua_Integer olua_checkfieldinteger(lua_State *L, int idx, const char *field);
LUALIB_API bool olua_checkfieldboolean(lua_State *L, int idx, const char *field);
LUALIB_API void olua_setfieldnumber(lua_State *L, int idx, const char *field, lua_Number value);
LUALIB_API void olua_setfieldinteger(lua_State *L, int idx, const char *field, lua_Integer value);
LUALIB_API void olua_setfieldstring(lua_State *L, int idx, const char *field, const char *value);
LUALIB_API void olua_setfieldboolean(lua_State *L, int idx, const char *field, bool value);
LUALIB_API const char *olua_optfieldstring(lua_State *L, int idx, const char *field, const char *def);
LUALIB_API lua_Number olua_optfieldnumber(lua_State *L, int idx, const char *field, lua_Number def);
LUALIB_API lua_Integer olua_optfieldinteger(lua_State *L, int idx, const char *field, lua_Integer def);
LUALIB_API bool olua_optfieldboolean(lua_State *L, int idx, const char *field, bool def);
LUALIB_API bool olua_hasfield(lua_State *L, int idx, const char *field);
    
LUALIB_API int luaopen_olua(lua_State *L);
    
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
LUALIB_API void *lua_getextraspace(lua_State *L);
LUALIB_API void lua_setuservalue(lua_State *L, int idx);
LUALIB_API int lua_getuservalue(lua_State *L, int idx);
LUALIB_API int lua_absindex(lua_State *L, int idx);
LUALIB_API int lua_isinteger(lua_State *L, int idx);
LUALIB_API int olua_getsubtable (lua_State *L, int idx, const char *fname);
LUALIB_API void olua_setfuncs(lua_State *L, const luaL_Reg *l, int nup);
LUALIB_API void olua_traceback(lua_State *L, lua_State *L1, const char *msg, int level);
LUALIB_API void olua_requiref(lua_State *L, const char *modname, lua_CFunction openf, int glb);
LUALIB_API void *olua_testudata(lua_State *L, int ud, const char *tname);
LUALIB_API void olua_rawsetp(lua_State *L, int idx, const void *p);
LUALIB_API int olua_rawgetp(lua_State *L, int idx, const void *p);
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
