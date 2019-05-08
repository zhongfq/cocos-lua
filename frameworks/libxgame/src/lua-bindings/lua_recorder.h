#ifndef _LUA_RECORDER_H__
#define _LUA_RECORDER_H__

#include "xgame/xlua.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
int luaopen_recorder(lua_State *L);
#else
#define luaopen_recorder xlua_nonsupport
#endif

#endif
