#include "lua_bindings.h"
#include "lua_crypto.h"
#include "lua_javabridge.h"
#include "lua_xgame.h"
#include "lua_cocos2d.h"
#include "lua_cocos2d_physics.h"
#include "lua_cocos2d_ui.h"
#include "lua_xml_http_request.h"
#include "lua_photo.h"
#include "lua_iap.h"
#include "lua_recorder.h"
#include "lua_keychain.h"
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

int luaopen_bindings(lua_State *L)
{
    xlua_call(L, luaopen_cocos2d);
    xlua_call(L, luaopen_cocos2d_physics);
    xlua_call(L, luaopen_cocos2d_ui);
    xlua_call(L, luaopen_xgame);
    xlua_call(L, luaopen_xml_http_request);
    
    // luasocket
    olua_require(L, "socket.core", luaopen_socket_core);
    olua_require(L, "mime.core", luaopen_mime_core);
    olua_require(L, "ltn12", luaopen_lua_m_ltn12);
    olua_require(L, "mime", luaopen_lua_m_mime);
    olua_require(L, "socket.ftp", luaopen_lua_m_socket_ftp);
    olua_require(L, "socket.headers", luaopen_lua_m_socket_headers);
    olua_require(L, "socket.http", luaopen_lua_m_socket_http);
    olua_require(L, "socket.mbox", luaopen_lua_m_socket_mbox);
    olua_require(L, "socket.smtp", luaopen_lua_m_socket_smtp);
    olua_require(L, "socket.tp", luaopen_lua_m_socket_tp);
    olua_require(L, "socket.url", luaopen_lua_m_socket_url);
    olua_require(L, "socket", luaopen_lua_m_socket);
    
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
    olua_require(L, "kernel.luaj", luaopen_javabridge);
    olua_require(L, "kernel.lame", luaopen_lame);
    olua_require(L, "kernel.keychain", luaopen_keychain);
    olua_require(L, "kernel.bugly", luaopen_bugly);
    olua_require(L, "kernel.plugins.photo", luaopen_photo);
    olua_require(L, "kernel.plugins.recorder", luaopen_recorder);
    olua_require(L, "kernel.plugins.iap", luaopen_iap);

    return 0;
}
