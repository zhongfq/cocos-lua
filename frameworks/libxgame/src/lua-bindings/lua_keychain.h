#ifndef __LUA_KEYCHAIN_H__
#define __LUA_KEYCHAIN_H__

#include "xgame/xlua.h"
    
#ifdef CCLUA_OS_IOS
int luaopen_keychain(lua_State *L);
#else
#define luaopen_keychain xlua_nonsupport
#endif

#endif
