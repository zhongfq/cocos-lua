#ifndef __LUA_OCBRIDGE_H__
#define __LUA_OCBRIDGE_H__

#include "xgame/xlua.h"
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC
int luaopen_ocbridge(lua_State *L);
#else
#define luaopen_ocbridge xlua_nonsupport
#endif

#endif
