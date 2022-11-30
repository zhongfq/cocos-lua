#include "lua_bindings.h"
#include "lua_crypto.h"
#include "lua_javabridge.h"
#include "lua_ocbridge.h"
#include "lua_xgame.h"
#include "lua_cocos2d.h"
#include "lua_cocos2d_types.h"
#include "lua_cocos2d_physics.h"
#include "lua_cocos2d_ui.h"
#include "lua_manual.h"
#include "lua_socket.h"
#include "lua_types.h"
#include "cjson/lua_cjson.h"
#include "md5/lua_md5.h"
#include "lfs/lfs.h"
#include "xxtea/lua_xxtea.h"

#if COCOS2D_VERSION >= 0x00040000
#include "lua_cocos2d_action.h"
#include "lua_cocos2d_backend.h"
#endif

#ifdef CCLUA_BUILD_BUGLY
#include "bugly/lua_bugly.h"
#endif //CCLUA_BUILD_BUGLY

int luaopen_bindings(lua_State *L)
{
    olua_import(L, luaopen_types);
    olua_import(L, luaopen_cocos2d_types);
    olua_import(L, luaopen_cocos2d);
#if COCOS2D_VERSION >= 0x00040000
    olua_import(L, luaopen_cocos2d_action);
    olua_import(L, luaopen_cocos2d_backend);
#endif
    olua_import(L, luaopen_cocos2d_physics);
    olua_import(L, luaopen_cocos2d_ui);
    olua_import(L, luaopen_xgame);
    olua_import(L, luaopen_manual);
    
    olua_require(L, "lfs", luaopen_lfs);
    olua_require(L, "cjson", luaopen_cjson);
    olua_require(L, "cjson.safe", luaopen_cjson_safe);
    olua_require(L, "base64", luaopen_base64);
    olua_require(L, "xxtea", luaopen_xxtea);
    olua_require(L, "md5" , luaopen_md5);

#ifdef CCLUA_BUILD_BUGLY
    olua_import(L, luaopen_bugly);
#endif // CCLUA_BUILD_BUGLY

    olua_require(L, "cclua.Socket", luaopen_socket);
    
#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_MAC)
    olua_require(L, "cclua.luaoc", luaopen_ocbridge);
#endif
    
#ifdef CCLUA_OS_ANDROID
    olua_require(L, "cclua.luaj", luaopen_javabridge);
#endif

    return 0;
}
