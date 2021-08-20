/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "AppDelegate.h"

#include "cclua/xlua.h"
#include "cclua/preferences.h"
#include "cclua/FileFinder.h"

#include "lua-bindings/lua_cocos2d_3d.h"

extern "C" {
#include "luaopenssl/openssl.h"
}

#ifdef CCLUA_BUILD_COCOSSTUDIO
#include "lua-bindings/lua_cocos2d_studio.h"
#endif //CCLUA_BUILD_COCOSSTUDIO

#ifdef CCLUA_BUILD_DRAGONBONES
#include "lua-bindings/lua_dragonbones.h"
#endif // CCLUA_BUILD_DRAGONBONES


#ifdef CCLUA_BUILD_FAIRYGUI
#include "lua-bindings/lua_fairygui.h"
#endif // CCLUA_BUILD_FAIRYGUI

#ifdef CCLUA_BUILD_SPINE
#include "lua-bindings/lua_spine.h"
#endif // CCLUA_BUILD_SPINE

#ifdef CCLUA_BUILD_SWF
#include "lua_swf.h"
#endif // CCLUA_BUILD_SWF

#ifdef CCLUA_BUILD_SQLITE3
#include "sqlite3/lsqlite3.h"
#endif // CCLUA_BUILD_SQLITE3

#ifdef CCLUA_BUILD_LUASOCKET
extern "C" {
#include "luasocket/luasocket.h"
#include "luasocket/luasocket_scripts.h"
#include "luasocket/mime.h"
}
#endif // CCLUA_BUILD_LUASOCKET

#ifdef CCLUA_BUILD_PBC
#include "pbc/pbc.h"
#endif // CCLUA_BUILD_PBC

#ifdef CCLUA_BUILD_SPROTO
#include "sproto/lsproto.h"
#endif // CCLUA_BUILD_SPROTO

#ifdef CCLUA_BUILD_LPEG
#include "lpeg/lptree.h"
#endif //CCLUA_BUILD_LPEG

#if defined(CCLUA_BUILD_JPUSH) || defined(CCLUA_BUILD_JANALYTICS) || defined(CCLUA_BUILD_JAUTH)
#include "jiguang/lua_jiguang.h"
#include "jiguang/JiGuang.h"
#endif

#ifdef CCLUA_BUILD_TALKINGDATA
#include "talkingdata/lua_talkingdata.h"
#endif

#ifdef CCLUA_BUILD_WECHAT
#include "wechat/WeChat.h"
#include "wechat/lua_wechat.h"
#endif

#if defined(CCLUA_BUILD_APPLE_AUTH) || defined(CCLUA_BUILD_APPLE_IAP)
#include "apple/lua_apple.h"
#endif

#ifdef CCLUA_OS_WIN32
#include "cclua/runtime-private.h"
#endif

USING_NS_CC;
USING_NS_CCLUA;

static int _open_plugins(lua_State *L)
{
    olua_callfunc(L, luaopen_cocos2d_3d);
    
#ifdef CCLUA_BUILD_COCOSSTUDIO
    olua_callfunc(L, luaopen_cocos2d_studio);
#endif
    
#ifdef CCLUA_BUILD_DRAGONBONES
    olua_callfunc(L, luaopen_dragonbones);
#endif

#ifdef CCLUA_BUILD_FAIRYGUI
    olua_callfunc(L, luaopen_fairygui);
#endif

#ifdef CCLUA_BUILD_SPINE
	olua_callfunc(L, luaopen_spine);
#endif
    
#ifdef CCLUA_BUILD_SWF
    olua_callfunc(L, luaopen_swf);
#endif
    
    olua_require(L, "openssl", luaopen_openssl);
    
#ifdef CCLUA_BUILD_SQLITE3
    olua_require(L, "sqlite3", luaopen_lsqlite3);
#endif
    
#ifdef CCLUA_BUILD_LUASOCKET
    olua_require(L, "socket.core", luaopen_socket_core);
    olua_require(L, "mime.core", luaopen_mime_core);
    olua_callfunc(L, luaopen_luasocket_scripts);
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
    
#if defined(CCLUA_BUILD_JPUSH) || defined(CCLUA_BUILD_JANALYTICS) || defined(CCLUA_BUILD_JAUTH)
    olua_callfunc(L, luaopen_jiguang);
#endif
    
#ifdef CCLUA_BUILD_TALKINGDATA
    olua_callfunc(L, luaopen_talkingdata);
#endif
    
#ifdef CCLUA_BUILD_WECHAT
    olua_callfunc(L, luaopen_wechat);
#endif
    
#if defined(CCLUA_BUILD_APPLE_AUTH) || defined(CCLUA_BUILD_APPLE_IAP)
    olua_callfunc(L, luaopen_apple);
#endif
    return 0;
}

void AppDelegate::initGLContextAttrs()
{
#ifdef CCLUA_FEATURE_MSAA
#if CC_TARGET_PLATFORM != CC_PLATFORM_MAC
    runtime::setSampleCount(4);
#endif
#else
    runtime::setSampleCount(1);
#endif
    RuntimeContext::initGLContextAttrs();
}

bool AppDelegate::applicationDidFinishLaunching()
{
    /**
     *  FileFinder::setProivder([]() {
     *      return MyFileFinder::create();
     *  });
     */

#ifdef CCLUA_OS_WIN32
    cclua::__runtime_setPackageName(APP_PACKAGE_NAME);
#endif
    
    // runtime::setProperty("cclua.metadata.key", "hello");
    
    initGLView(APP_NAME);
    runtime::luaOpen(_open_plugins);
    
    return RuntimeContext::applicationDidFinishLaunching();
}
