#ifndef _LUA_IAP_H__
#define _LUA_IAP_H__

#include "cclua/xlua.h"

#ifdef CCLUA_OS_IOS
int luaopen_iap(lua_State *L);
#else
#define luaopen_iap xlua_nonsupport
#endif

#endif
