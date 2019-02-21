#ifndef __XLUA_H__
#define __XLUA_H__

#include "xgame/xdef.h"
#include "lua.hpp"

LUALIB_API lua_State *xlua_new();
LUALIB_API lua_State *xlua_mainthread(lua_State *L);
LUALIB_API lua_State *xlua_cocosthread();

LUALIB_API int xlua_errorfunc(lua_State *L);
LUALIB_API int xlua_pcall(lua_State *L, int n, int r);
LUALIB_API void xlua_call(lua_State *L, lua_CFunction func);
LUALIB_API int xlua_dofile(lua_State *L, const char *filename);

LUALIB_API int xlua_ref(lua_State *L, int idx);
LUALIB_API int xlua_reffunc(lua_State *L, int idx);
LUALIB_API void xlua_unref(lua_State *L, int ref);
LUALIB_API void xlua_getref(lua_State *L, int ref);

#endif
