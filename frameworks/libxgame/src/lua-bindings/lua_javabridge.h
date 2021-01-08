#ifndef __LUA_JAVABRIDGE_H__
#define __LUA_JAVABRIDGE_H__

#include "xgame/xlua.h"

#ifdef CCLUA_OS_ANDROID
int luaopen_javabridge(lua_State *L);
#else
#define luaopen_javabridge xlua_nonsupport
#endif

#endif
