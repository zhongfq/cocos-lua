#include "lua_bugly.h"
#include "CrashReport.h"
#include "xgame/xruntime.h"

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

#ifndef CATEGORY_LUA_EXCEPTION
#define CATEGORY_LUA_EXCEPTION 6
#endif

static int _reportLuaException(lua_State *L) {
    const char* type = "";
    const char* msg = lua_tostring(L, 1);
    const char* traceback = lua_tostring(L, 2);
    bool quit = lua_toboolean(L, 3);
    
    CrashReport::reportException(CATEGORY_LUA_EXCEPTION, type, msg, traceback, quit);
    
    return 0;
}

static int _setUserId(lua_State *L) {
    const char* userId = lua_tostring(L, 1);
    
    CrashReport::setUserId(userId);
    
    return 0;
}

static int _setTag(lua_State *L) {
    int tag = lua_tonumber(L, 1);
    CrashReport::setTag(tag);
    
    return 0;
}

static int _addUserValue(lua_State *L) {
    const char* key = lua_tostring(L, 1);
    const char* value = lua_tostring(L, 2);
    
    CrashReport::addUserValue(key, value);
    
    return 0;
}

static int _removeUserValue(lua_State *L) {
    const char* key = lua_tostring(L, 1);
    
    CrashReport::removeUserValue(key);
    return 0;
}

static int _printLog(lua_State *L) {
    int level = lua_tonumber(L, 1);
    const char* tag = lua_tostring(L, 2);
    const char* log = lua_tostring(L, 3);
    
    CrashReport::CRLogLevel crLevel = CrashReport::CRLogLevel::Off;
    switch (level) {
        case -1:
            crLevel = CrashReport::CRLogLevel::Off;
            break;
        case 0:
            crLevel = CrashReport::CRLogLevel::Verbose;
            break;
        case 1:
            crLevel = CrashReport::CRLogLevel::Debug;
            break;
        case 2:
            crLevel = CrashReport::CRLogLevel::Info;
            break;
        case 3:
            crLevel = CrashReport::CRLogLevel::Warning;
            break;
        case 4:
            crLevel = CrashReport::CRLogLevel::Error;
            break;
    }
    
    CrashReport::log(crLevel, tag, log);
    
    return 0;
}

int luaopen_bugly(lua_State *L)
{
    static luaL_Reg lib[] = {
        {"reportLuaException", _reportLuaException},
        {"setUserId", _setUserId},
        {"setTag", _setTag},
        {"addUserValue", _addUserValue},
        {"removeUserValue", _removeUserValue},
        {"log", _printLog},
        {NULL, NULL}
    };
    
    xgame::runtime::support("kernel.plugins.bugly");
    
    olua_newlib(L, lib);
    
    return 1;
}

#endif