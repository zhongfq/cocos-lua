#ifndef __LUA_CRYPTO_H__
#define __LUA_CRYPTO_H__

#include "xgame/xlua.h"

int luaopen_md5(lua_State *L);
int luaopen_base64(lua_State *L);
int luaopen_xxtea(lua_State *L);

#endif
