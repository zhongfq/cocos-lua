#include "lua_bugly.h"
#include "CrashReport.h"
#include "xgame/runtime.h"

#include "cocos2d.h"

static int l_reportException(lua_State *L) {
    const char *msg = olua_checkstring(L, 1);
    const char *traceback = olua_checkstring(L, 2);
    CrashReport::reportException(msg, traceback);
    return 0;
}

static int l_setUid(lua_State *L) {
    CrashReport::setUid(olua_checkstring(L, 1));
    return 0;
}

static int l_setTag(lua_State *L) {
    CrashReport::setTag((int)olua_checkinteger(L, 1));
    return 0;
}

static int l_setUserValue(lua_State *L) {
    const char *key = olua_checkstring(L, 1);
    const char *value = olua_checkstring(L, 2);
    CrashReport::setUserValue(key, value);
    return 0;
}

static int l_log(lua_State *L) {
    int level = (int)olua_checkinteger(L, 1);
    const char *msg = olua_checkstring(L, 2);
    CrashReport::log((CrashReport::LogLevel)level, msg);
    return 0;
}

int luaopen_bugly(lua_State *L)
{
    static luaL_Reg lib[] = {
        {"reportException", l_reportException},
        {"setUid", l_setUid},
        {"setTag", l_setTag},
        {"setUserValue", l_setUserValue},
        {"log", l_log},
        {NULL, NULL}
    };
    
    xgame::runtime::support("kernel.plugins.bugly");
    
    luaL_newlib(L, lib);
    
    return 1;
}
