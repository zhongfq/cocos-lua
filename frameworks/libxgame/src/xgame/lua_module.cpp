#include "xgame/lua_module.h"
#include "xgame/lua_crypto.h"
#include "xgame/lua_javabridge.h"
#include "xgame/xruntime.h"
#include "xgame/xlua.h"
#include "xgame/lua-bindings/lua_xgame.h"
#include "xgame/lua-bindings/lua_cocos2d.h"
#include "xgame/lua-bindings/lua_cocos2d_ui.h"
#include "xgame/lua-bindings/lua_spine.h"
#include "xgame/lua-bindings/lua_fairygui.h"
#include "cjson/lua_cjson.h"
#include "md5/md5.h"
#include "pbc/pbc.h"
#include "lame/lua_lame.h"
#include "qrencode/lua_qrcode.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "bugly/lua_bugly.h"
#endif

int luaopen_module(lua_State *L)
{
    xlua_call(L, luaopen_cocos2d);
    xlua_call(L, luaopen_cocos2d_ui);
    xlua_call(L, luaopen_spine);
    xlua_call(L, luaopen_fairygui);
    xlua_call(L, luaopen_xgame);
    
    olua_require(L, "kernel.crypto.protobuf.c", luaopen_protobuf_c);
    olua_require(L, "kernel.crypto.md5" , luaopen_md5);
    olua_require(L, "kernel.crypto.base64", luaopen_base64);
    olua_require(L, "kernel.crypto.xxtea", luaopen_xxtea);
    olua_require(L, "kernel.crypto.openssl", luaopen_openssl);
    olua_require(L, "kernel.crypto.cjson", luaopen_cjson);
    olua_require(L, "kernel.crypto.cjson.safe", luaopen_cjson_safe);
    olua_require(L, "kernel.crypto.qrcode", luaopen_qrcode);
    olua_require(L, "kernel.crypto.qrcode.QRSprite", luaopen_qrsprite);
    olua_require(L, "kernel.audio.lame", luaopen_lame);
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    olua_require(L, "kernel.plugins.bugly", luaopen_bugly);
#endif
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    olua_preload(L, "kernel.luaj", luaopen_javabridge);
#endif
    return 0;
}
