#ifndef __LUA_JAVABRIDGE_H__
#define __LUA_JAVABRIDGE_H__

#include "xgame/xlua.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
int luaopen_javabridge(lua_State *L);
#else
#define luaopen_javabridge xlua_nonsupport
#endif

#endif
