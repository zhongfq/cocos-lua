#ifndef __LUA_LAME_H__
#define __LUA_LAME_H__

#include "xgame/xlua.h"

#if defined(CCLUA_OS_ANDROID) || defined(CCLUA_OS_IOS)
int luaopen_lame(lua_State *L);
#else
#define luaopen_lame xlua_nonsupport
#endif

#endif /* lua_lame_h */
