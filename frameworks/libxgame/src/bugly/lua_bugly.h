#ifndef __LUA_BUGLY_H__
#define __LUA_BUGLY_H__

#include "xgame/xlua.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
int luaopen_bugly(lua_State *L);
#else
#define luaopen_bugly xlua_nonsupport
#endif

#endif
