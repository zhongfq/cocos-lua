#ifndef __LUA_OCBRIDGE_H__
#define __LUA_OCBRIDGE_H__

#include "cclua/cclua.h"

#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_MAC)
int luaopen_ocbridge(lua_State *L);
#endif

#endif
