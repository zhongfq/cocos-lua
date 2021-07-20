#ifndef __LUA_CRYPTO_H__
#define __LUA_CRYPTO_H__

#include "cclua/xlua.h"

int luaopen_base64(lua_State *L);
int luaopen_openssl(lua_State *L);

#endif
