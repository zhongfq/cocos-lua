#ifndef _LUA_WECHAT_H__
#define _LUA_WECHAT_H__

#include "xgame/xlua.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
int luaopen_wechat(lua_State *L);
int luaopen_wxvoice(lua_State *L);
#else
#define luaopen_wechat xlua_nonsupport
#define luaopen_wxvoice xlua_nonsupport
#endif

#endif
