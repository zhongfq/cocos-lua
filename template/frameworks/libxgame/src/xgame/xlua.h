#ifndef __XLUA_H__
#define __XLUA_H__

#include "xgame/xdef.h"
#include "lua.hpp"

LUALIB_API lua_State *xlua_new();
LUALIB_API lua_State *xlua_mainthread(lua_State *L);
LUALIB_API lua_State *xlua_cocosthread();

LUALIB_API bool xlua_optboolean(lua_State *L, int idx, bool default_value);
LUALIB_API void xlua_setnilfield(lua_State *L, const char *field);
LUALIB_API void xlua_setfunc(lua_State *L, const char *field, lua_CFunction func);
LUALIB_API void xlua_preload(lua_State *L, const char *name, lua_CFunction func);
LUALIB_API int xlua_errorfunc(lua_State *L);
LUALIB_API int xlua_pcall(lua_State *L, int n, int r);
LUALIB_API void xlua_call(lua_State *L, lua_CFunction func);
LUALIB_API int xlua_dofile(lua_State *L, const char *filename);

LUALIB_API int xlua_ref(lua_State *L, int idx);
LUALIB_API int xlua_reffunc(lua_State *L, int idx);
LUALIB_API void xlua_unref(lua_State *L, int ref);
LUALIB_API void xlua_getref(lua_State *L, int ref);

LUALIB_API const char *xluaf_getstring(lua_State *L, int idx, const char *field, const char *default_value);
LUALIB_API bool xluaf_getboolean(lua_State *L, int idx, const char *field, bool default_value);
LUALIB_API lua_Number xluaf_getnumber(lua_State *L, int idx, const char *field, lua_Number default_value);
LUALIB_API lua_Integer xluaf_getinteger(lua_State *L, int idx, const char *field, lua_Integer default_value);
LUALIB_API const char *xluaf_checkstring(lua_State *L, int idx, const char *field);
LUALIB_API lua_Number xluaf_checknumber(lua_State *L, int idx, const char *field);
LUALIB_API lua_Integer xluaf_checkinteger(lua_State *L, int idx, const char *field);

#endif
