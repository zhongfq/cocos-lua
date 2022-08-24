#include "lua_crypto.h"
#include "platform/CCFileUtils.h"
#include "base/base64.h"
#include "openssl/sha.h"

using namespace cocos2d;

static int _base64_encode(lua_State *L)
{
    size_t len = 0;
    const unsigned char *str = (const unsigned char *)luaL_checklstring(L, 1, &len);
    char *data = nullptr;
    int data_len = base64Encode(str, (unsigned int)len, &data);
    if (data) {
        lua_pushlstring(L, data, data_len);
        free(data);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

static int _base64_decode(lua_State *L)
{
    size_t len = 0;
    const unsigned char *str = (const unsigned char *)luaL_checklstring(L, 1, &len);
    unsigned char *data = nullptr;
    int data_len = base64Decode(str, (unsigned int)len, &data);
    if (data) {
        lua_pushlstring(L, (const char *)data, data_len);
        free(data);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

int luaopen_base64(lua_State *L)
{
    static luaL_Reg lib[] = {
        {"encode", _base64_encode},
        {"decode", _base64_decode},
        {NULL, NULL}
    };
    
    luaL_newlib(L, lib);
    return 1;
}
