#include "xgame/lua_module.h"
#include "xgame/lua_crypto.h"
#include "xgame/lua_javabridge.h"
#include "xgame/xruntime.h"
#include "xgame/xlua.h"
#include "xgame/lua-bindings/lua_xgame.h"
#include "xgame/lua-bindings/lua_cocos2d.h"
#include "xgame/lua-bindings/lua_cocos2d_ui.h"
#include "xgame/lua-bindings/lua_cocos2d_ref_chain.h"
#include "xgame/lua-bindings/lua_spine.h"
#include "cjson/lua_cjson.h"
#include "md5/md5.h"
#include "pbc/pbc.h"
#include "cocos2d.h"

int luaopen_module(lua_State *L)
{
    olua_preload(L, "protobuf.c", luaopen_protobuf_c);
    olua_preload(L, "kernel.crypto.md5" , luaopen_md5);
    olua_preload(L, "kernel.crypto.base64", luaopen_base64);
    olua_preload(L, "kernel.crypto.xxtea", luaopen_xxtea);
    olua_preload(L, "kernel.crypto.cjson", luaopen_cjson);
    olua_preload(L, "kernel.crypto.cjson.safe", luaopen_cjson_safe);
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    xlua_preload(L, "kernel.luaj", luaopen_javabridge);
#endif
    
    xlua_call(L, luaopen_cocos2d);
    xlua_call(L, luaopen_cocos2d_ui);
    xlua_call(L, luaopen_cocos2d_ref_chain);
    xlua_call(L, luaopen_spine);
    xlua_call(L, luaopen_xgame);
    
    return 0;
}
