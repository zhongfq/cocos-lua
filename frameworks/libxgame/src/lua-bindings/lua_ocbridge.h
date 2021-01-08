#ifndef __LUA_OCBRIDGE_H__
#define __LUA_OCBRIDGE_H__

#include "xgame/xlua.h"

#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_MAC)
int luaopen_ocbridge(lua_State *L);
#else
#define luaopen_ocbridge xlua_nonsupport
#endif

#endif
