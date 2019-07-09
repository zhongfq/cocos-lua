#ifndef __LUA_LAME_H__
#define __LUA_LAME_H__

#include "xgame/xlua.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
int luaopen_lame(lua_State *L);
#else
#define luaopen_lame xlua_nonsupport
#endif

#endif /* lua_lame_h */
