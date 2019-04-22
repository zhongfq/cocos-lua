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

#define BUGLY_APPID_IOS     "da940b4f6e" // d21353e4-26c8-4f94-b646-cf88a225f039
#define BUGLY_APPID_ANDROID "c082cf3ca0" // c332369f-17b2-4f8e-9481-5810319e8c46

USING_NS_CC;

static int _open_sdk(lua_State *L)
{
    return 0;
}

bool AppDelegate::applicationDidFinishLaunching()
{
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("cocos-lua", cocos2d::Rect(0, 0, 887, 500));
#else
        glview = GLViewImpl::create("cocos-lua");
#endif
        director->setOpenGLView(glview);
    }
    
#ifndef COCOS2D_DEBUG
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    CrashReport::initCrashReport(BUGLY_APPID_IOS, false, CrashReport::CRLogLevel::Verbose);
    runtime::log("init bugly for ios");
    runtime::set_log_reporter([](const char *msg) {
        CrashReport::log(CrashReport::Verbose, "bugly", msg);
    });
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    // CrashReport::initCrashReport(BUGLY_APPID_ANDROID, false, CrashReport::CRLogLevel::Verbose);
    // runtime::log("init bugly for android");
#endif
    runtime::setErrorReporter([](const char *err_msg, const char *traceback) {
        //CrashReport::reportException(CATEGORY_LUA_EXCEPTION, "", err_msg, traceback);
    });
#endif

    xgame::runtime::luaOpen(_open_sdk);
    
    return RuntimeContext::applicationDidFinishLaunching();
}
