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

#include "xgame/xlua.h"
#include "xgame/preferences.h"
#include "xgame/FileFinder.h"
//#include "wechat/lua_wechat.h"

#include "lua-bindings/lua_cocos2d_3d.h"

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

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#define BUGLY_APPID "546f1cf279" // d21353e4-26c8-4f94-b646-cf88a225f039
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#define BUGLY_APPID "c082cf3ca0" // c332369f-17b2-4f8e-9481-5810319e8c46
#else
#define BUGLY_APPID "<no appid>"
#endif

USING_NS_CC;

static int _open_plugins(lua_State *L)
{
    olua_callfunc(L, luaopen_cocos2d_3d);
    
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
    
//    olua_require(L, "kernel.plugins.wechat", luaopen_wechat);
    return 0;
}

void AppDelegate::initGLContextAttrs()
{
#ifdef CCLUA_FEATURE_MSAA
    xgame::runtime::setSampleCount(4);
#else
    xgame::runtime::setSampleCount(1);
#endif
    RuntimeContext::initGLContextAttrs();
}

bool AppDelegate::applicationDidFinishLaunching()
{
    /**
     *  xgame::FileFinder::setProivder([]() {
     *      return MyFileFinder::create();
     *  });
     */
    
    initGLView("cocos-lua");
    xgame::runtime::initBugly(BUGLY_APPID);
    xgame::runtime::luaOpen(_open_plugins);
    
    return RuntimeContext::applicationDidFinishLaunching();
}
