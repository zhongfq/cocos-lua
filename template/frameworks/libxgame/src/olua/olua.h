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
    
#define OLUA_OBJ_EXIST  0
#define OLUA_OBJ_NEW    1
#define OLUA_OBJ_UPDATE 2
    
#define OLUA_VOIDCLS "void *"
    
#ifdef OLUA_MAINTHREAD
#define olua_mainthread() OLUA_MAINTHREAD()
#else
#define olua_mainthread (static_assert(false), NULL)
#endif
    
#define olua_isfunction(L,n)        (lua_type(L, (n)) == LUA_TFUNCTION)
#define olua_istable(L,n)           (lua_type(L, (n)) == LUA_TTABLE)
#define olua_islightuserdata(L,n)   (lua_type(L, (n)) == LUA_TLIGHTUSERDATA)
#define olua_isuserdata(L,n)        (lua_type(L, (n)) == LUA_TUSERDATA)
#define olua_isnil(L,n)             (lua_type(L, (n)) == LUA_TNIL)
#define olua_isnoneornil(L, n)      (lua_type(L, (n)) <= 0)
#define olua_isboolean(L,n)         (lua_type(L, (n)) == LUA_TBOOLEAN)
#define olua_isstring(L,n)          (lua_type(L, (n)) == LUA_TSTRING)
#define olua_isnumber(L,n)          (lua_type(L, (n)) == LUA_TNUMBER)
#define olua_isinteger(L,n)         (lua_isinteger(L, n))
#define olua_isthread(L,n)          (lua_type(L, (n)) == LUA_TTHREAD)
    
#define olua_newuserdata(L, obj, t) (*(t*)lua_newuserdata(L, sizeof(t)) = (obj))
#define olua_touserdata(L, n, t)    (*(t*)lua_touserdata(L, (n)))
#define olua_tonumber(L, i)         lua_tonumber(L, i)
#define olua_tointeger(L, i)        lua_tointeger(L, i)
#define olua_tostring(L, i)         lua_tostring(L, i)
#define olua_tolstring(L, i, l)     lua_tolstring(L, i, l)
#define olua_toboolean(L, i)        lua_toboolean(L, i)
#define olua_checkstring(L, i)      olua_checklstring(L, i, NULL)
#define olua_optinteger(L, i, d)    luaL_opt(L, olua_checkinteger, i, d)
#define olua_optstring(L, i, d)     luaL_opt(L, olua_checkstring, i, d)
#define olua_optlstring(L, i, d, l) luaL_opt(L, olua_checklstring, i, d, l)
#define olua_optnumber(L, i, d)     luaL_opt(L, olua_checknumber, i, d)
#define olua_optboolean(L, i, d)    (olua_isnoneornil(L, i) ? (d) : olua_toboolean(L, i) != 0)
    
#define olua_addobjcount()  olua_changeobjcount(1)
#define olua_subobjcount()  olua_changeobjcount(-1)
#define olua_objcount()     olua_changeobjcount(0)
    
LUALIB_API lua_Integer olua_checkinteger(lua_State *L, int idx);
LUALIB_API lua_Number olua_checknumber(lua_State *L, int idx);
LUALIB_API const char *olua_checklstring (lua_State *L, int arg, size_t *len);
LUALIB_API bool olua_checkboolean(lua_State *L, int idx);
LUALIB_API int olua_rawgetfield(lua_State *L, int idx, const char *field);
LUALIB_API void olua_rawsetfield(lua_State *L, int idx, const char *field);
LUALIB_API void olua_seterrfunc(lua_CFunction errfunc);
LUALIB_API const char *olua_typename(lua_State *L, int idx);
LUALIB_API const char *olua_objtostring(lua_State *L, int idx);
LUALIB_API int olua_changeobjcount(int add);
LUALIB_API void olua_require(lua_State *L, const char *name, lua_CFunction func);
LUALIB_API void olua_preload(lua_State *L, const char *name, lua_CFunction func);
LUALIB_API bool olua_isa(lua_State *L, int idx, const char *cls);
LUALIB_API int olua_pushobj(lua_State *L, void *obj, const char *cls);
LUALIB_API bool olua_getobj(lua_State *L, void *obj);
LUALIB_API void *olua_checkobj(lua_State *L, int idx, const char *cls);
LUALIB_API void *olua_toobj(lua_State *L, int idx, const char *cls);
LUALIB_API void olua_callgc(lua_State *L, int idx, bool isarrary);
    
typedef enum {
    // for olua_setcallback
    OLUA_CALLBACK_TAG_NEW,
    OLUA_CALLBACK_TAG_REPLACE,
    // for olua_removecallback
    OLUA_CALLBACK_TAG_EQUAL,
    OLUA_CALLBACK_TAG_ENDWITH,
    OLUA_CALLBACK_TAG_WILDCARD
} olua_callback_tag_t;
    
#define OLUA_CALLBACK_OK    0
#define OLUA_CALLBACK_MISS  1
#define OLUA_CALLBACK_ERR   2

LUALIB_API const char *olua_setcallback(lua_State *L, void *obj, const char *tag, int func, olua_callback_tag_t mode);
LUALIB_API void olua_getcallback(lua_State *L, void *obj, const char *tag, olua_callback_tag_t mode);
LUALIB_API void olua_removecallback(lua_State *L, void *obj, const char *tag, olua_callback_tag_t mode);
LUALIB_API int olua_callback(lua_State *L, void *obj, const char *field, int num_args);
#define olua_makecallbacktag(tag) (tag)
    
LUALIB_API void olua_getstore(lua_State *L, const char *cls);
LUALIB_API void *olua_getstoreobj(lua_State *L, const char *cls);

LUALIB_API int olua_getvariable(lua_State *L, int idx);
LUALIB_API void olua_setvariable(lua_State *L, int idx);
    
// for ref chain
LUALIB_API void olua_getreftable(lua_State *L, int idx, const char *field);
LUALIB_API void olua_singleref(lua_State *L, int obj, const char *field, int vidx);
LUALIB_API void olua_singleunref(lua_State *L, int obj, const char *field);
LUALIB_API void olua_mapref(lua_State *L, int obj, const char *t, int vidx);
LUALIB_API void olua_maprefarray(lua_State *L, int obj, const char *t, int vidx);
LUALIB_API void olua_mapunref(lua_State *L, int obj, const char *t, int vidx);
LUALIB_API void olua_mapwalkunref(lua_State *L, int obj, const char *t, lua_CFunction walk);
LUALIB_API void olua_unrefall(lua_State *L, int obj, const char *t);
LUALIB_API void olua_arrayref(lua_State *L, int obj, const char *t, int vidx);
LUALIB_API void olua_arrayunref(lua_State *L, int obj, const char *t, int idx);
LUALIB_API size_t olua_arraylen(lua_State *L, int obj, const char *t);

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
LUALIB_API void oluacls_property(lua_State *L, const char *field, lua_CFunction getter, lua_CFunction setter);
LUALIB_API void oluacls_setfunc(lua_State *L, const char *funcname, lua_CFunction func);
LUALIB_API void oluacls_const(lua_State *L, const char *field);
#define oluacls_const_bool(L, field, value) {lua_pushboolean(L, value); oluacls_const(L, field);}
#define oluacls_const_number(L, field, value) {lua_pushnumber(L, value); oluacls_const(L, field);}
#define oluacls_const_integer(L, field, value) {lua_pushinteger(L, value); oluacls_const(L, field);}
#define oluacls_const_string(L, field, value) {lua_pushstring(L, value); oluacls_const(L, field);}
    
LUALIB_API int olua_push_bool(lua_State *L, bool value);
LUALIB_API void olua_check_bool(lua_State *L, int idx, bool *value);
LUALIB_API void olua_opt_bool(lua_State *L, int idx, bool *value, bool def);
#define olua_is_bool(L, idx) olua_isboolean(L, idx)

LUALIB_API int olua_push_string(lua_State *L, const char *value);
LUALIB_API void olua_check_string(lua_State *L, int idx, const char **value);
LUALIB_API void olua_opt_string(lua_State *L, int idx, const char **value, const char *def);
#define olua_is_string(L, idx) olua_isstring(L, idx)

LUALIB_API int olua_push_number(lua_State *L, lua_Number value);
LUALIB_API void olua_check_number(lua_State *L, int idx, lua_Number *value);
LUALIB_API void olua_opt_number(lua_State *L, int idx, lua_Number *value, lua_Number def);
#define olua_is_number(L, idx) olua_isnumber(L, idx)

LUALIB_API int olua_push_int(lua_State *L, lua_Integer value);
LUALIB_API void olua_check_int(lua_State *L, int idx, lua_Integer *value);
LUALIB_API void olua_opt_int(lua_State *L, int idx, lua_Integer *value, lua_Integer def);
#define olua_is_int(L, idx) olua_isinteger(L, idx)

LUALIB_API int olua_push_uint(lua_State *L, lua_Unsigned value);
LUALIB_API void olua_check_uint(lua_State *L, int idx, lua_Unsigned *value);
LUALIB_API void olua_opt_uint(lua_State *L, int idx, lua_Unsigned *value, lua_Unsigned def);
#define olua_is_uint(L, idx) olua_isinteger(L, idx)

LUALIB_API int olua_push_obj(lua_State *L, void *obj, const char *cls);
LUALIB_API void olua_check_obj(lua_State *L, int idx, void **value, const char *cls);
LUALIB_API void olua_opt_obj(lua_State *L, int idx, void **value, const char *cls, void *def);
LUALIB_API void olua_to_obj(lua_State *L, int idx, void **value, const char *cls);
#define olua_is_obj(L, idx, cls) olua_isa(L, idx, cls)
    
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
    
// for debug
#ifdef OLUA_DEBUG
#define olua_assert assert
#else
#define olua_assert
#endif

#ifdef __cplusplus
}
#endif

#endif
