#ifndef _LUA_RECORDER_H__
#define _LUA_RECORDER_H__

#include "xgame/xlua.h"

#ifdef CCLUA_OS_IOS
int luaopen_recorder(lua_State *L);
#else
#define luaopen_recorder xlua_nonsupport
#endif

#endif
