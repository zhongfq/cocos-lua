#include "lua_crypto.h"
#include "platform/CCFileUtils.h"
#include "base/base64.h"
#include "crypto/md5util.h"
#include "crypto/xxtea.h"
#include "openssl/sha.h"

using namespace cocos2d;

static int _md5_sumhexa(lua_State *L)
{
    size_t len = 0;
    const char *str = luaL_checklstring(L, 1, &len);
    unsigned char result[MD5_STR_LEN];
    bool isfile = olua_optboolean(L, 2, false);
    if (isfile) {
        if (md5f(result, FileUtils::getInstance()->fullPathForFilename(str).c_str())) {
            lua_pushstring(L, (const char *)result);
        } else {
            lua_pushnil(L);
        }
    } else {
        md5str(result, str, len);
        lua_pushstring(L, (const char *)result);
    }
    return 1;
}

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

static int _xxtea_encrypt(lua_State *L)
{
    size_t data_len, key_len;
    unsigned char *data = (unsigned char *)luaL_checklstring(L, 1, &data_len);
    unsigned char *key = (unsigned char *)luaL_checklstring(L, 2, &key_len);
    
    if (data_len > 0 && key_len > 0) {
        xxtea_long res_data_len;
        unsigned char *res_data = xxtea_encrypt(data, (xxtea_long)data_len, key,
                                                (xxtea_long)key_len, &res_data_len);
        
        if (res_data) {
            lua_pushlstring(L, (const char *)res_data, (int)res_data_len);
            free(res_data);
        }
    } else {
        lua_pushnil(L);
    }
    
    return 1;
}

static int _xxtea_decrypt(lua_State *L)
{
    size_t data_len, key_len;
    unsigned char *data = (unsigned char *)luaL_checklstring(L, 1, &data_len);
    unsigned char *key = (unsigned char *)luaL_checklstring(L, 2, &key_len);
    
    if (data_len > 0 && key_len > 0) {
        xxtea_long res_data_len;
        unsigned char *res_data = xxtea_decrypt(data, (xxtea_long)data_len, key,
                                                (xxtea_long)key_len, &res_data_len);
        
        if (res_data) {
            lua_pushlstring(L, (const char *)res_data, (int)res_data_len);
            free(res_data);
        }
    } else {
        lua_pushnil(L);
    }
    
    return 1;

}

int luaopen_md5(lua_State *L)
{
    static luaL_Reg lib[] = {
        {"sumhexa", _md5_sumhexa},
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

static const char *tohex(unsigned char *result, unsigned char *digest, size_t len)
{
    static const unsigned char HEX[16] = {
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
    };
    
    size_t i;
    unsigned char *r = result;
    for (i = 0; i < len; ++i) {
        int t = digest[i];
        *result++ = HEX[t / 16];
        *result++ = HEX[t % 16];
    }
    *result = '\0';
    return (const char *)r;
}

static int _openssl_sha1(lua_State *L)
{
    size_t len;
    const unsigned char *data = (const unsigned char *)olua_checklstring(L, 1, &len);
    bool isfile = olua_optboolean(L, 2, false);
    unsigned char md[SHA_DIGEST_LENGTH];
    unsigned char result[SHA_DIGEST_LENGTH * 2];
    if (!isfile) {
        SHA1(data, len, md);
        lua_pushstring(L, tohex(result, md, SHA_DIGEST_LENGTH));
    } else {
        char buf[1024];
        FILE *f = fopen((const char *)data, "r");
        if (f) {
            SHA_CTX ctx;
            SHA1_Init(&ctx);
            while ((len = fread(buf, sizeof(char), sizeof(buf), f)) > 0) {
                SHA1_Update(&ctx, buf, len);
            }
            SHA1_Final(md, &ctx);
            lua_pushstring(L, tohex(result, md, SHA_DIGEST_LENGTH));
        } else {
            lua_pushnil(L);
        }
    }
    
    return 1;
}

static int _openssl_sha224(lua_State *L)
{
    size_t len;
    const unsigned char *data = (const unsigned char *)olua_checklstring(L, 1, &len);
    bool isfile = olua_optboolean(L, 2, false);
    unsigned char md[SHA224_DIGEST_LENGTH];
    unsigned char result[SHA224_DIGEST_LENGTH * 2];
    if (!isfile) {
        SHA224(data, len, md);
        lua_pushstring(L, tohex(result, md, SHA224_DIGEST_LENGTH));
    } else {
        char buf[1024];
        FILE *f = fopen((const char *)data, "r");
        if (f) {
            SHA256_CTX ctx;
            SHA224_Init(&ctx);
            while ((len = fread(buf, sizeof(char), sizeof(buf), f)) > 0) {
                SHA224_Update(&ctx, buf, len);
            }
            SHA224_Final(md, &ctx);
            lua_pushstring(L, tohex(result, md, SHA224_DIGEST_LENGTH));
        } else {
            lua_pushnil(L);
        }
    }
    
    return 1;
}

static int _openssl_sha256(lua_State *L)
{
    size_t len;
    const unsigned char *data = (const unsigned char *)olua_checklstring(L, 1, &len);
    bool isfile = olua_optboolean(L, 2, false);
    unsigned char md[SHA256_DIGEST_LENGTH];
    unsigned char result[SHA256_DIGEST_LENGTH * 2];
    if (!isfile) {
        SHA256(data, len, md);
        lua_pushstring(L, tohex(result, md, SHA256_DIGEST_LENGTH));
    } else {
        char buf[1024];
        FILE *f = fopen((const char *)data, "r");
        if (f) {
            SHA256_CTX ctx;
            SHA256_Init(&ctx);
            while ((len = fread(buf, sizeof(char), sizeof(buf), f)) > 0) {
                SHA256_Update(&ctx, buf, len);
            }
            SHA256_Final(md, &ctx);
            lua_pushstring(L, tohex(result, md, SHA256_DIGEST_LENGTH));
        } else {
            lua_pushnil(L);
        }
    }
    
    return 1;
}

static int _openssl_sha384(lua_State *L)
{
    size_t len;
    const unsigned char *data = (const unsigned char *)olua_checklstring(L, 1, &len);
    bool isfile = olua_optboolean(L, 2, false);
    unsigned char md[SHA384_DIGEST_LENGTH];
    unsigned char result[SHA384_DIGEST_LENGTH * 2];
    if (!isfile) {
        SHA384(data, len, md);
        lua_pushstring(L, tohex(result, md, SHA384_DIGEST_LENGTH));
    } else {
        char buf[1024];
        FILE *f = fopen((const char *)data, "r");
        if (f) {
            SHA512_CTX ctx;
            SHA384_Init(&ctx);
            while ((len = fread(buf, sizeof(char), sizeof(buf), f)) > 0) {
                SHA512_Update(&ctx, buf, len);
            }
            SHA384_Final(md, &ctx);
            lua_pushstring(L, tohex(result, md, SHA384_DIGEST_LENGTH));
        } else {
            lua_pushnil(L);
        }
    }
    
    return 1;
}

static int _openssl_sha512(lua_State *L)
{
    size_t len;
    const unsigned char *data = (const unsigned char *)olua_checklstring(L, 1, &len);
    bool isfile = olua_optboolean(L, 2, false);
    unsigned char md[SHA512_DIGEST_LENGTH];
    unsigned char result[SHA512_DIGEST_LENGTH * 2];
    if (!isfile) {
        SHA512(data, len, md);
        lua_pushstring(L, tohex(result, md, SHA512_DIGEST_LENGTH));
    } else {
        char buf[1024];
        FILE *f = fopen((const char *)data, "r");
        if (f) {
            SHA512_CTX ctx;
            SHA512_Init(&ctx);
            while ((len = fread(buf, sizeof(char), sizeof(buf), f)) > 0) {
                SHA512_Update(&ctx, buf, len);
            }
            SHA512_Final(md, &ctx);
            lua_pushstring(L, tohex(result, md, SHA512_DIGEST_LENGTH));
        } else {
            lua_pushnil(L);
        }
    }
    
    return 1;
}

int luaopen_openssl(lua_State *L)
{
    static luaL_Reg lib[] = {
        {"sha1", _openssl_sha1},
        {"sha224", _openssl_sha224},
        {"sha256", _openssl_sha256},
        {"sha384", _openssl_sha384},
        {"sha512", _openssl_sha512},
        {NULL, NULL}
    };
    
    luaL_newlib(L, lib);
    return 1;
}
