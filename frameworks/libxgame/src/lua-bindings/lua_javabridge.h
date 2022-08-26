#ifndef __LUA_JAVABRIDGE_H__
#define __LUA_JAVABRIDGE_H__

#include "cclua/cclua.h"

#ifdef CCLUA_OS_ANDROID
int luaopen_javabridge(lua_State *L);
#endif

#endif
