#include "lua_qrcode.h"
#include "QRSprite.h"

#include <stdlib.h>

extern "C" {
#include "qrencode.h"
}

static QRcode *qrcode_create(lua_State *L)
{
    static const QRencodeMode mode[] = {QR_MODE_NUL, QR_MODE_NUM, QR_MODE_AN,
        QR_MODE_8, QR_MODE_KANJI, QR_MODE_STRUCTURE};
    static const char *const modename[] = {"MODE_NUL", "MODE_NUM", "MODE_AN",
        "MODE_8", "MODE_KANJI", "MODE_STRUCTURE", NULL};
    
    static const QRecLevel level[] = {QR_ECLEVEL_L, QR_ECLEVEL_M, QR_ECLEVEL_Q, QR_ECLEVEL_H};
    static const char *const levelname[] = {"ECLEVEL_L", "ECLEVEL_M", "ECLEVEL_Q", "ECLEVEL_H", NULL};
    
    const char *string = luaL_checkstring(L, 1);
    int version = (int)luaL_checkinteger(L, 2);
    int level_op = luaL_checkoption(L, 3, "QR_ECLEVEL_H", levelname);
    int mode_op = luaL_checkoption(L, 4, "MODE_8", modename);
    int casesensitive = lua_toboolean(L, 5);
    
    return QRcode_encodeString(string, version, level[level_op], mode[mode_op], casesensitive);
}

static int qrcode_encode_as_rgba(lua_State *L)
{
    QRcode *qrcode = qrcode_create(L);
    
    if (qrcode != NULL)
    {
        int data_len = qrcode->width * qrcode->width;
        int bpp = 4;
        unsigned char *data = (unsigned char *)malloc(data_len * bpp); // RGB
        unsigned char *buf = data;
        int i;
        for (i = 0; i < data_len; i++)
        {
            if ((qrcode->data[i] & 1) == 0)
            {
                *buf++ = 255;
                *buf++ = 255;
                *buf++ = 255;
                *buf++ = 255;
            }
            else
            {
                *buf++ = 0;
                *buf++ = 0;
                *buf++ = 0;
                *buf++ = 255;
            }
        }
        
        lua_pushinteger(L, qrcode->version);
        lua_pushinteger(L, qrcode->width);
        lua_pushlstring(L, (const char *)data, data_len * bpp);
        
        QRcode_free(qrcode);
        free(data);
    }
    else
    {
        lua_pushnil(L);
        lua_pushnil(L);
        lua_pushnil(L);
    }

    return 3;
}

static int qrcode_encode_as_rgb(lua_State *L)
{
    QRcode *qrcode = qrcode_create(L);
    
    if (qrcode != NULL)
    {
        lua_pushinteger(L, qrcode->version);
        lua_pushinteger(L, qrcode->width);
        lua_pushlstring(L, (const char *)qrcode->data, qrcode->width * qrcode->width);
        
        QRcode_free(qrcode);
    }
    else
    {
        lua_pushnil(L);
        lua_pushnil(L);
        lua_pushnil(L);
    }
    
    return 3;
}

static int qrcode_encode(lua_State *L)
{
    lua_settop(L, 6);
    lua_pushstring(L, "RGBA");
    if (lua_rawequal(L, -1, -2)) {
        return qrcode_encode_as_rgba(L);
    } else {
        return qrcode_encode_as_rgb(L);
    }
}

static const luaL_Reg lib[] = {
    {"encode", qrcode_encode},
    {NULL, NULL}
};

int luaopen_qrcode(lua_State *L)
{
    luaL_newlib(L, lib);
    
    return 1;
}

int _qrsprite_create(lua_State *L)
{
    lua_settop(L, 1);
    auto ret = QRSprite::create(olua_checkstring(L, 1));
    olua_push_cppobj<QRSprite>(L, ret, "QRSprite*");
    return 1;
}

int luaopen_qrsprite(lua_State *L)
{
    oluacls_class(L, "QRSprite*", "cc.Sprite");
    oluacls_func(L, "create", _qrsprite_create);
    
    olua_registerluatype<QRSprite>(L, "QRSprite*");
    
    return 1;
}
