//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_bugly.h"

#ifdef CCLUA_BUILD_BUGLY
static int _cclua_CrashReport_LogLevel___index(lua_State *L)
{
    olua_startinvoke(L);

    const char *cls = olua_checkfieldstring(L, 1, "classname");
    const char *key = olua_tostring(L, 2);
    luaL_error(L, "enum '%s.%s' not found", cls, key);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cclua_CrashReport_LogLevel(lua_State *L)
{
    oluacls_class(L, "cclua.CrashReport.LogLevel", nullptr);
    oluacls_func(L, "__index", _cclua_CrashReport_LogLevel___index);
    oluacls_const_integer(L, "Debug", (lua_Integer)cclua::CrashReport::LogLevel::Debug);
    oluacls_const_integer(L, "Error", (lua_Integer)cclua::CrashReport::LogLevel::Error);
    oluacls_const_integer(L, "Info", (lua_Integer)cclua::CrashReport::LogLevel::Info);
    oluacls_const_integer(L, "Off", (lua_Integer)cclua::CrashReport::LogLevel::Off);
    oluacls_const_integer(L, "Verbose", (lua_Integer)cclua::CrashReport::LogLevel::Verbose);
    oluacls_const_integer(L, "Warning", (lua_Integer)cclua::CrashReport::LogLevel::Warning);

    olua_registerluatype<cclua::CrashReport::LogLevel>(L, "cclua.CrashReport.LogLevel");

    return 1;
}
#endif

#ifdef CCLUA_BUILD_BUGLY
static int _cclua_CrashReport___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::CrashReport *)olua_toobj(L, 1, "cclua.CrashReport");
    olua_push_cppobj(L, self, "cclua.CrashReport");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_CrashReport_init(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** appid */

    olua_check_string(L, 1, &arg1);

    // static void init(const char *appid)
    cclua::CrashReport::init(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_CrashReport_log(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** level */
    const char *arg2 = nullptr;       /** message */

    olua_check_uint(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // static void log(cclua::CrashReport::LogLevel level, const char *message)
    cclua::CrashReport::log((cclua::CrashReport::LogLevel)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_CrashReport_reportException(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** msg */
    const char *arg2 = nullptr;       /** traceback */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // static void reportException(const char *msg, const char *traceback)
    cclua::CrashReport::reportException(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_CrashReport_setChannel(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** channel */

    olua_check_string(L, 1, &arg1);

    // static void setChannel(const char *channel)
    cclua::CrashReport::setChannel(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_CrashReport_setTag(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** tag */

    olua_check_int(L, 1, &arg1);

    // static void setTag(int tag)
    cclua::CrashReport::setTag((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_CrashReport_setUid(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** uid */

    olua_check_string(L, 1, &arg1);

    // static void setUid(const char *uid)
    cclua::CrashReport::setUid(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_CrashReport_setUserValue(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */
    const char *arg2 = nullptr;       /** value */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // static void setUserValue(const char *key, const char *value)
    cclua::CrashReport::setUserValue(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_CrashReport_setVersion(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** version */

    olua_check_string(L, 1, &arg1);

    // static void setVersion(const char *version)
    cclua::CrashReport::setVersion(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cclua_CrashReport(lua_State *L)
{
    oluacls_class(L, "cclua.CrashReport", nullptr);
    oluacls_func(L, "__olua_move", _cclua_CrashReport___olua_move);
    oluacls_func(L, "init", _cclua_CrashReport_init);
    oluacls_func(L, "log", _cclua_CrashReport_log);
    oluacls_func(L, "reportException", _cclua_CrashReport_reportException);
    oluacls_func(L, "setChannel", _cclua_CrashReport_setChannel);
    oluacls_func(L, "setTag", _cclua_CrashReport_setTag);
    oluacls_func(L, "setUid", _cclua_CrashReport_setUid);
    oluacls_func(L, "setUserValue", _cclua_CrashReport_setUserValue);
    oluacls_func(L, "setVersion", _cclua_CrashReport_setVersion);

    olua_registerluatype<cclua::CrashReport>(L, "cclua.CrashReport");
    cclua::runtime::registerFeature("bugly", true);

    return 1;
}
#endif

int luaopen_bugly(lua_State *L)
{
#ifdef CCLUA_BUILD_BUGLY
    olua_require(L, "cclua.CrashReport.LogLevel", luaopen_cclua_CrashReport_LogLevel);
#endif
#ifdef CCLUA_BUILD_BUGLY
    olua_require(L, "cclua.CrashReport", luaopen_cclua_CrashReport);
#endif
    return 0;
}
