//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_bugly.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "xgame/xlua.h"
#include "bugly/CrashReport.h"

#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)

static int luaopen_xgame_CrashReport_LogLevel(lua_State *L)
{
    oluacls_class(L, "kernel.CrashReport.LogLevel", nullptr);
    oluacls_const_integer(L, "Debug", (lua_Integer)xgame::CrashReport::LogLevel::Debug);
    oluacls_const_integer(L, "Error", (lua_Integer)xgame::CrashReport::LogLevel::Error);
    oluacls_const_integer(L, "Info", (lua_Integer)xgame::CrashReport::LogLevel::Info);
    oluacls_const_integer(L, "Off", (lua_Integer)xgame::CrashReport::LogLevel::Off);
    oluacls_const_integer(L, "Verbose", (lua_Integer)xgame::CrashReport::LogLevel::Verbose);
    oluacls_const_integer(L, "Warning", (lua_Integer)xgame::CrashReport::LogLevel::Warning);

    olua_registerluatype<xgame::CrashReport::LogLevel>(L, "kernel.CrashReport.LogLevel");

    return 1;
}

static int _xgame_CrashReport___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (xgame::CrashReport *)olua_toobj(L, 1, "kernel.CrashReport");
    olua_push_cppobj(L, self, "kernel.CrashReport");

    olua_endinvoke(L);

    return 1;
}

static int _xgame_CrashReport_init(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** appid */

    olua_check_string(L, 1, &arg1);

    // static void init(const char *appid)
    xgame::CrashReport::init(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _xgame_CrashReport_log(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** level */
    const char *arg2 = nullptr;       /** message */

    olua_check_uint(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // static void log(xgame::CrashReport::LogLevel level, const char *message)
    xgame::CrashReport::log((xgame::CrashReport::LogLevel)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _xgame_CrashReport_reportException(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** msg */
    const char *arg2 = nullptr;       /** traceback */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // static void reportException(const char *msg, const char *traceback)
    xgame::CrashReport::reportException(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _xgame_CrashReport_setChannel(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** channel */

    olua_check_string(L, 1, &arg1);

    // static void setChannel(const char *channel)
    xgame::CrashReport::setChannel(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _xgame_CrashReport_setTag(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** tag */

    olua_check_int(L, 1, &arg1);

    // static void setTag(int tag)
    xgame::CrashReport::setTag((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _xgame_CrashReport_setUid(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** uid */

    olua_check_string(L, 1, &arg1);

    // static void setUid(const char *uid)
    xgame::CrashReport::setUid(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _xgame_CrashReport_setUserValue(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */
    const char *arg2 = nullptr;       /** value */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // static void setUserValue(const char *key, const char *value)
    xgame::CrashReport::setUserValue(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _xgame_CrashReport_setVersion(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** version */

    olua_check_string(L, 1, &arg1);

    // static void setVersion(const char *version)
    xgame::CrashReport::setVersion(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_xgame_CrashReport(lua_State *L)
{
    oluacls_class(L, "kernel.CrashReport", nullptr);
    oluacls_func(L, "__move", _xgame_CrashReport___move);
    oluacls_func(L, "init", _xgame_CrashReport_init);
    oluacls_func(L, "log", _xgame_CrashReport_log);
    oluacls_func(L, "reportException", _xgame_CrashReport_reportException);
    oluacls_func(L, "setChannel", _xgame_CrashReport_setChannel);
    oluacls_func(L, "setTag", _xgame_CrashReport_setTag);
    oluacls_func(L, "setUid", _xgame_CrashReport_setUid);
    oluacls_func(L, "setUserValue", _xgame_CrashReport_setUserValue);
    oluacls_func(L, "setVersion", _xgame_CrashReport_setVersion);

    olua_registerluatype<xgame::CrashReport>(L, "kernel.CrashReport");

    return 1;
}

int luaopen_bugly(lua_State *L)
{
    olua_require(L, "kernel.CrashReport.LogLevel", luaopen_xgame_CrashReport_LogLevel);
    olua_require(L, "kernel.CrashReport", luaopen_xgame_CrashReport);
    return 0;
}

#endif