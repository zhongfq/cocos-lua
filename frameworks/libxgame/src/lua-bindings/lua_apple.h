#ifndef __LUA_APPLE_H__
#define __LUA_APPLE_H__

#include "xgame/xlua.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
LUALIB_API int luaopen_apple(lua_State *L);
#else
#define luaopen_apple xlua_nonsupport
#endif

#endif
