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
#include "luasocket/luasocket.h"
#include "luasocket/luasocket_scripts.h"
#include "luasocket/mime.h"
#include "xgame/xruntime.h"
#include "xgame/xlua.h"
#include "cjson/lua_cjson.h"
#include "md5/md5.h"
#include "pbc/pbc.h"
#include "lame/lua_lame.h"
#include "qrencode/lua_qrcode.h"
#include "bugly/lua_bugly.h"
#include "sproto/lsproto.h"
#include "lpeg/lptree.h"

#ifndef _WIN32
#include "libpdebug.h"
#endif

int luaopen_bindings(lua_State *L)
{
    olua_dofunc(L, luaopen_cocos2d);
    olua_dofunc(L, luaopen_cocos2d_action);
    olua_dofunc(L, luaopen_cocos2d_backend);
    olua_dofunc(L, luaopen_cocos2d_physics);
    olua_dofunc(L, luaopen_cocos2d_ui);
    olua_dofunc(L, luaopen_xgame);
    olua_dofunc(L, luaopen_xml_http_request);
    
#ifndef _WIN32
    //pdebug_init(L);
#endif
    
    // luasocket
    olua_require(L, "socket.core", luaopen_socket_core);
    olua_require(L, "mime.core", luaopen_mime_core);
    olua_require(L, "luasocket.scripts", luaopen_luasocket_scripts);
    
    olua_require(L, "olua", luaopen_olua);
    olua_require(L, "sproto.core", luaopen_sproto_core);
    olua_require(L, "protobuf.c", luaopen_protobuf_c);
    olua_require(L, "lpeg", luaopen_lpeg);
    olua_require(L, "base64", luaopen_base64);
    olua_require(L, "xxtea", luaopen_xxtea);
    olua_require(L, "openssl", luaopen_openssl);
    olua_require(L, "cjson", luaopen_cjson);
    olua_require(L, "cjson.safe", luaopen_cjson_safe);
    olua_require(L, "md5" , luaopen_md5);
    olua_require(L, "kernel.qrcode", luaopen_qrcode);
    olua_require(L, "kernel.QRSprite", luaopen_qrsprite);
    olua_require(L, "kernel.Socket", luaopen_socket);
    olua_require(L, "kernel.luaj", luaopen_javabridge);
    olua_require(L, "kernel.lame", luaopen_lame);
    olua_require(L, "kernel.keychain", luaopen_keychain);
    olua_require(L, "kernel.bugly", luaopen_bugly);
    olua_require(L, "kernel.plugins.photo", luaopen_photo);
    olua_require(L, "kernel.plugins.recorder", luaopen_recorder);
    olua_require(L, "kernel.plugins.iap", luaopen_iap);

    return 0;
}
