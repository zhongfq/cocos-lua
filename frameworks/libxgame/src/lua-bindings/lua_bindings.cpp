#include "lua_bindings.h"
#include "lua_crypto.h"
#include "lua_javabridge.h"
#include "lua_ocbridge.h"
#include "lua_xgame.h"
#include "lua_cocos2d.h"
#include "lua_cocos2d_action.h"
#include "lua_cocos2d_backend.h"
#include "lua_cocos2d_physics.h"
#include "lua_cocos2d_ui.h"
#include "lua_manual.h"
#include "lua_xml_http_request.h"
#include "lua_photo.h"
#include "lua_recorder.h"
#include "lua_socket.h"
#include "cjson/lua_cjson.h"
#include "cclua/runtime.h"
#include "cclua/xlua.h"
#include "md5/md5.h"
#include "lfs/lfs.h"

#ifdef CCLUA_BUILD_BUGLY
#include "bugly/lua_bugly.h"
#endif //CCLUA_BUILD_BUGLY

#ifdef CCLUA_BUILD_LAME
#include "lame/lua_lame.h"
#endif

#ifdef CCLUA_BUILD_QRCODE
#include "qrencode/lua_qrcode.h"
#endif //CCLUA_BUILD_QRCODE

int luaopen_bindings(lua_State *L)
{
    olua_callfunc(L, luaopen_cocos2d);
    olua_callfunc(L, luaopen_cocos2d_action);
    olua_callfunc(L, luaopen_cocos2d_backend);
    olua_callfunc(L, luaopen_cocos2d_physics);
    olua_callfunc(L, luaopen_cocos2d_ui);
    olua_callfunc(L, luaopen_xgame);
    olua_callfunc(L, luaopen_xml_http_request);
    olua_callfunc(L, luaopen_manual);
    
    olua_require(L, "olua", luaopen_olua);
    olua_require(L, "lfs", luaopen_lfs);
    olua_require(L, "cjson", luaopen_cjson);
    olua_require(L, "cjson.safe", luaopen_cjson_safe);
    olua_require(L, "base64", luaopen_base64);
    olua_require(L, "xxtea", luaopen_xxtea);
    olua_require(L, "openssl", luaopen_openssl);
    olua_require(L, "md5" , luaopen_md5);

#ifdef CCLUA_BUILD_QRCODE
    olua_require(L, "cclua.qrcode", luaopen_qrcode);
    olua_require(L, "cclua.QRSprite", luaopen_qrsprite);
#endif //CCLUA_BUILD_QRCODE

#ifdef CCLUA_BUILD_LAME
    olua_require(L, "cclua.lame", luaopen_lame);
#endif //CCLUA_BUILD_LAME

#ifdef CCLUA_BUILD_BUGLY
    olua_callfunc(L, luaopen_bugly);
#endif // CCLUA_BUILD_BUGLY

    olua_require(L, "cclua.Socket", luaopen_socket);
    olua_require(L, "cclua.luaoc", luaopen_ocbridge);
    olua_require(L, "cclua.luaj", luaopen_javabridge);
    olua_require(L, "cclua.plugin.photo", luaopen_photo);
    olua_require(L, "cclua.plugin.recorder", luaopen_recorder);

    return 0;
}
