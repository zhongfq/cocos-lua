#ifndef __TOLUA_H__
#define __TOLUA_H__

#ifdef __cplusplus
extern "C" {
#endif
    
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
    
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

LUALIB_API int tolua_rawgetfield(lua_State *L, int idx, const char *field);
LUALIB_API void tolua_rawsetfield(lua_State *L, int idx, const char *field);
    
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
LUALIB_API const char *toluacls_typename(lua_State *L, int idx);
LUALIB_API void toluacls_class(lua_State *L, const char *cls, const char *supercls);
LUALIB_API void toluacls_createclassproxy(lua_State *L);
LUALIB_API void toluacls_initmetafunc(lua_State *L);
LUALIB_API void toluacls_property(lua_State *L, const char *field, lua_CFunction getter, lua_CFunction setter);
LUALIB_API void toluacls_setfunc(lua_State *L, const char *funcname, lua_CFunction func);
LUALIB_API void toluacls_const(lua_State *L, const char *field);
LUALIB_API void toluacls_const_bool(lua_State *L, const char *field, bool value);
LUALIB_API void toluacls_const_number(lua_State *L, const char *field, lua_Number value);
LUALIB_API void toluacls_const_integer(lua_State *L, const char *field, lua_Integer value);
LUALIB_API void toluacls_const_string(lua_State *L, const char *field, const char *value);
LUALIB_API bool toluacls_isa(lua_State *L, int idx, const char *cls);
LUALIB_API bool toluacls_pushobj(lua_State *L, void *obj, const char *cls);
LUALIB_API void *toluacls_checkobj(lua_State *L, int idx, const char *cls);
    
LUALIB_API int tolua_push_bool(lua_State *L, bool value);
LUALIB_API void tolua_to_bool(lua_State *L, int idx, bool *value);
LUALIB_API void tolua_opt_bool(lua_State *L, int idx, bool *value, bool def);
LUALIB_API bool tolua_is_bool(lua_State *L, int idx);

LUALIB_API int tolua_push_string(lua_State *L, const char *value);
LUALIB_API void tolua_to_string(lua_State *L, int idx, const char **value);
LUALIB_API void tolua_opt_string(lua_State *L, int idx, const char **value, const char *def);
LUALIB_API bool tolua_is_string(lua_State *L, int idx);

LUALIB_API int tolua_push_number(lua_State *L, lua_Number value);
LUALIB_API void tolua_to_number(lua_State *L, int idx, lua_Number *value);
LUALIB_API void tolua_opt_number(lua_State *L, int idx, lua_Number *value, lua_Number def);
LUALIB_API bool tolua_is_number(lua_State *L, int idx);

LUALIB_API int tolua_push_int(lua_State *L, lua_Integer value);
LUALIB_API void tolua_to_int(lua_State *L, int idx, lua_Integer *value);
LUALIB_API void tolua_opt_int(lua_State *L, int idx, lua_Integer *value, lua_Integer def);
LUALIB_API bool tolua_is_int(lua_State *L, int idx);

LUALIB_API int tolua_push_uint(lua_State *L, lua_Unsigned value);
LUALIB_API void tolua_to_uint(lua_State *L, int idx, lua_Unsigned *value);
LUALIB_API void tolua_opt_uint(lua_State *L, int idx, lua_Unsigned *value, lua_Unsigned def);
LUALIB_API bool tolua_is_uint(lua_State *L, int idx);

LUALIB_API int tolua_push_obj(lua_State *L, void *obj, const char *cls);
LUALIB_API void tolua_to_obj(lua_State *L, int idx, void **value, const char *cls);
LUALIB_API bool tolua_is_obj(lua_State *L, int idx, const char *cls);
    
#ifdef __cplusplus
}
#endif

#endif
