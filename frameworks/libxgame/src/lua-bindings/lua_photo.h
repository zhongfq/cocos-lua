#ifndef _LUA_CAMERAROLL_H__
#define _LUA_CAMERAROLL_H__

#include "xgame/xlua.h"

#ifdef CCLUA_OS_IOS
int luaopen_photo(lua_State *L);
#else
#define luaopen_photo xlua_nonsupport
#endif

#endif
