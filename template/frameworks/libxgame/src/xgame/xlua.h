#ifndef __XLUA_H__
#define __XLUA_H__

#include "xgame/xdef.h"
#include "lua.hpp"

#include "base/CCRef.h"

LUALIB_API lua_State *xlua_new();
LUALIB_API lua_State *xlua_mainthread(lua_State *L);
LUALIB_API lua_State *xlua_cocosthread();

LUALIB_API bool xlua_optboolean(lua_State *L, int idx, bool default_value);
LUALIB_API bool xlua_checkboolean(lua_State *L, int idx);
LUALIB_API void xlua_setnilfield(lua_State *L, const char *field);
LUALIB_API int xlua_rawgetfield(lua_State *L, int idx, const char *field);
LUALIB_API void xlua_rawsetfield(lua_State *L, int idx, const char *field);
LUALIB_API void xlua_setfunc(lua_State *L, const char *field, lua_CFunction func);
LUALIB_API void xlua_preload(lua_State *L, const char *name, lua_CFunction func);
LUALIB_API void xlua_require(lua_State *L, const char *name, lua_CFunction func);
LUALIB_API int xlua_errorfunc(lua_State *L);
LUALIB_API int xlua_pcall(lua_State *L, int n, int r);
LUALIB_API void xlua_call(lua_State *L, lua_CFunction func);
LUALIB_API int xlua_dofile(lua_State *L, const char *filename);

LUALIB_API int xlua_ref(lua_State *L, int idx);
LUALIB_API int xlua_reffunc(lua_State *L, int idx);
LUALIB_API void xlua_unref(lua_State *L, int ref);
LUALIB_API void xlua_getref(lua_State *L, int ref);

// check table key value
LUALIB_API const char *xluaf_getstring(lua_State *L, int idx, const char *field, const char *default_value);
LUALIB_API bool xluaf_getboolean(lua_State *L, int idx, const char *field, bool default_value);
LUALIB_API lua_Number xluaf_getnumber(lua_State *L, int idx, const char *field, lua_Number default_value);
LUALIB_API lua_Integer xluaf_getinteger(lua_State *L, int idx, const char *field, lua_Integer default_value);
LUALIB_API const char *xluaf_checkstring(lua_State *L, int idx, const char *field);
LUALIB_API lua_Number xluaf_checknumber(lua_State *L, int idx, const char *field);
LUALIB_API lua_Integer xluaf_checkinteger(lua_State *L, int idx, const char *field);

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
//  }
//
LUALIB_API void xluacls_class(lua_State *L, const char *classname, const char *super_class);
LUALIB_API void xluacls_newclassproxy(lua_State *L);
LUALIB_API void xluacls_initmetafunc(lua_State *L);
LUALIB_API void xluacls_property(lua_State *L, const char *field, lua_CFunction getter, lua_CFunction setter);
LUALIB_API void xluacls_setfunc(lua_State *L, const char *funcname, lua_CFunction func);
LUALIB_API void xluacls_const(lua_State *L, const char *field);
LUALIB_API void xluacls_const_bool(lua_State *L, const char *field, bool value);
LUALIB_API void xluacls_const_number(lua_State *L, const char *field, lua_Number value);
LUALIB_API void xluacls_const_integer(lua_State *L, const char *field, lua_Integer value);
LUALIB_API void xluacls_const_string(lua_State *L, const char *field, const char *value);
LUALIB_API bool xluacls_isa(lua_State *L, int idx, const char *classname);
LUALIB_API void xluacls_pushobj(lua_State *L, void *obj, const char *classname);
LUALIB_API void xluacls_pushccobj(lua_State *L, cocos2d::Ref *obj, const char *classname);
LUALIB_API int xluacls_ccobjgc(lua_State *L);
LUALIB_API int xluacls_ccobjcount(lua_State *L);
LUALIB_API void *xluacls_checkobj(lua_State *L, int idx, const char *classname);

// store in uservalue
LUALIB_API void xluacls_setvalue(lua_State *L, int idx, const char *field, int vidx);

#endif
