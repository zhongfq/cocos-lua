#ifndef __LUA_KEYCHAIN_H__
#define __LUA_KEYCHAIN_H__

#include "xgame/xlua.h"
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
int luaopen_keychain(lua_State *L);
#else
#define luaopen_keychain xlua_nonsupport
#endif

#endif
