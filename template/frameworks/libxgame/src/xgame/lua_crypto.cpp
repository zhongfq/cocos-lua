#include "xgame/lua_crypto.h"
#include "platform/CCFileUtils.h"
#include "base/base64.h"
#include "crypto/md5util.h"
#include "crypto/xxtea.h"

using namespace cocos2d;

static int _md5_sumhexa(lua_State *L)
{
    size_t len = 0;
    const char *str = luaL_checklstring(L, 1, &len);
    unsigned char result[MD5_STR_LEN];
    md5str(result, str, len);
    lua_pushstring(L, (const char *)result);
    return 1;
}

static int _md5_file(lua_State *L)
{
    const char *path = luaL_checkstring(L, 1);
    unsigned char result[MD5_STR_LEN];
    
    if (md5f(result, FileUtils::getInstance()->fullPathForFilename(path).c_str()))
        lua_pushstring(L, (const char *)result);
    else
        lua_pushnil(L);
    
    return 1;
}

static int _base64_encode(lua_State *L)
{
    size_t len = 0;
    const unsigned char *str = (const unsigned char *)luaL_checklstring(L, 1, &len);
    char *data = nullptr;
    int data_len = base64Encode(str, (unsigned int)len, &data);
    if (data)
    {
        lua_pushlstring(L, data, data_len);
        free(data);
    }
    else
    {
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
    if (data)
    {
        lua_pushlstring(L, (const char *)data, data_len);
        free(data);
    }
    else
    {
        lua_pushnil(L);
    }
    return 1;
}

static int _xxtea_encrypt(lua_State *L)
{
    size_t data_len, key_len;
    unsigned char *data = (unsigned char *)luaL_checklstring(L, 1, &data_len);
    unsigned char *key = (unsigned char *)luaL_checklstring(L, 2, &key_len);
    
    if (data_len > 0 && key_len > 0)
    {
        xxtea_long res_data_len;
        unsigned char *res_data = xxtea_encrypt(data, (xxtea_long)data_len, key,
                                                (xxtea_long)key_len, &res_data_len);
        
        if (res_data)
        {
            lua_pushlstring(L, (const char *)res_data, (int)res_data_len);
            free(res_data);
        }
    }
    else
    {
        lua_pushnil(L);
    }
    
    return 1;
}

static int _xxtea_decrypt(lua_State *L)
{
    size_t data_len, key_len;
    unsigned char *data = (unsigned char *)luaL_checklstring(L, 1, &data_len);
    unsigned char *key = (unsigned char *)luaL_checklstring(L, 2, &key_len);
    
    if (data_len > 0 && key_len > 0)
    {
        xxtea_long res_data_len;
        unsigned char *res_data = xxtea_decrypt(data, (xxtea_long)data_len, key,
                                                (xxtea_long)key_len, &res_data_len);
        
        if (res_data)
        {
            lua_pushlstring(L, (const char *)res_data, (int)res_data_len);
            free(res_data);
        }
    }
    else
    {
        lua_pushnil(L);
    }
    
    return 1;

}

int luaopen_md5(lua_State *L)
{
    static luaL_Reg lib[] = {
        {"str", _md5_sumhexa},
        {"sumhexa", _md5_sumhexa},
        {"file", _md5_file},
        {NULL, NULL}
    };

    luaL_newlib(L, lib);
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

int luaopen_xxtea(lua_State *L)
{
    static luaL_Reg lib[] = {
        {"encrypt", _xxtea_encrypt},
        {"decrypt", _xxtea_decrypt},
        {NULL, NULL}
    };

    luaL_newlib(L, lib);
    return 1;
}
