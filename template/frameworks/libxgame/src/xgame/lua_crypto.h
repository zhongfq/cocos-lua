//
// $id: lua_crypto.h O $
//

#ifndef __LUA_CRYPTO_H__
#define __LUA_CRYPTO_H__

#include "lua/lua.hpp"

int luaopen_md5(lua_State *L);
int luaopen_base64(lua_State *L);
int luaopen_xxtea(lua_State *L);

#endif
