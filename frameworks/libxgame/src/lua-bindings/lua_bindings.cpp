#include "lua_bindings.h"
#include "lua_crypto.h"
#include "lua_javabridge.h"
#include "lua_xgame.h"
#include "lua_cocos2d.h"
#include "lua_cocos2d_action.h"
#include "lua_cocos2d_backend.h"
#include "lua_cocos2d_physics.h"
#include "lua_cocos2d_ui.h"
#include "lua_xml_http_request.h"
#include "lua_photo.h"
#include "lua_iap.h"
#include "lua_recorder.h"
#include "lua_keychain.h"
#include "lua_socket.h"
#include "cjson/lua_cjson.h"
#include "xgame/runtime.h"
#include "xgame/xlua.h"
#include "md5/md5.h"

#ifdef CCLUA_BUILD_LUASOCKET
#include "luasocket/luasocket.h"
#include "luasocket/luasocket_scripts.h"
#include "luasocket/mime.h"
#endif // CCLUA_BUILD_LUASOCKET

#ifdef CCLUA_BUILD_BUGLY
#include "bugly/lua_bugly.h"
#endif //CCLUA_BUILD_BUGLY

#ifdef CCLUA_BUILD_PBC
#include "pbc/pbc.h"
#endif // CCLUA_BUILD_PBC

#ifdef CCLUA_BUILD_SPROTO
#include "sproto/lsproto.h"
#endif // CCLUA_BUILD_SPROTO

#ifdef CCLUA_BUILD_LPEG
#include "lpeg/lptree.h"
#endif //CCLUA_BUILD_LPEG

#ifdef CCLUA_BUILD_LAME
#include "lame/lua_lame.h"
#endif

#ifdef CCLUA_BUILD_QRCODE
#include "qrencode/lua_qrcode.h"
#endif //CCLUA_BUILD_QRCODE

int luaopen_bindings(lua_State *L)
{
    olua_dofunc(L, luaopen_cocos2d);
    olua_dofunc(L, luaopen_cocos2d_action);
    olua_dofunc(L, luaopen_cocos2d_backend);
    olua_dofunc(L, luaopen_cocos2d_physics);
    olua_dofunc(L, luaopen_cocos2d_ui);
    olua_dofunc(L, luaopen_xgame);
    olua_dofunc(L, luaopen_xml_http_request);
    
    olua_require(L, "olua", luaopen_olua);

#ifdef CCLUA_BUILD_LUASOCKET
    olua_require(L, "socket.core", luaopen_socket_core);
    olua_require(L, "mime.core", luaopen_mime_core);
    olua_require(L, "luasocket.scripts", luaopen_luasocket_scripts);
#endif // CCLUA_BUILD_LUASOCKET

#ifdef CCLUA_BUILD_SPROTO
    olua_require(L, "sproto.core", luaopen_sproto_core);
#endif //CCLUA_BUILD_SPROTO

#ifdef CCLUA_BUILD_LPEG
    olua_require(L, "lpeg", luaopen_lpeg);
#endif // CCLUA_BUILD_LPEG

#ifdef CCLUA_BUILD_PBC
    olua_require(L, "protobuf.c", luaopen_protobuf_c);
#endif // CCLUA_BUILD_PBC

    olua_require(L, "cjson", luaopen_cjson);
    olua_require(L, "cjson.safe", luaopen_cjson_safe);
    olua_require(L, "base64", luaopen_base64);
    olua_require(L, "xxtea", luaopen_xxtea);
    olua_require(L, "openssl", luaopen_openssl);
    olua_require(L, "md5" , luaopen_md5);

#ifdef CCLUA_BUILD_QRCODE
    olua_require(L, "kernel.qrcode", luaopen_qrcode);
    olua_require(L, "kernel.QRSprite", luaopen_qrsprite);
#endif //CCLUA_BUILD_QRCODE

#ifdef CCLUA_BUILD_LAME
    olua_require(L, "kernel.lame", luaopen_lame);
#endif //CCLUA_BUILD_LAME

#ifdef CCLUA_BUILD_BUGLY
    olua_require(L, "kernel.bugly", luaopen_bugly);
#endif // CCLUA_BUILD_BUGLY

    olua_require(L, "kernel.Socket", luaopen_socket);
    olua_require(L, "kernel.luaj", luaopen_javabridge);
    olua_require(L, "kernel.keychain", luaopen_keychain);
    olua_require(L, "kernel.plugins.photo", luaopen_photo);
    olua_require(L, "kernel.plugins.recorder", luaopen_recorder);
    olua_require(L, "kernel.plugins.iap", luaopen_iap);

    return 0;
}
