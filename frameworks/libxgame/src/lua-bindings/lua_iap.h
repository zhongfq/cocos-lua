#ifndef _LUA_IAP_H__
#define _LUA_IAP_H__

#include "xgame/xlua.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
int luaopen_iap(lua_State *L);
#else
#define luaopen_iap xlua_nonsupport
#endif

#endif
