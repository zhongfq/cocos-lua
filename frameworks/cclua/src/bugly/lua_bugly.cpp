//
// AUTO GENERATED, DO NOT MODIFY!
//
#include "lua_bugly.h"
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "bugly/CrashReport.h"

static int _olua_module_bugly(lua_State *L);

#ifdef CCLUA_BUILD_BUGLY
static int _olua_cls_cclua_bugly_LogLevel(lua_State *L)
{
    oluacls_class<cclua::bugly::LogLevel>(L, "cclua.bugly.LogLevel");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "Debug", (lua_Integer)cclua::bugly::LogLevel::Debug);
    oluacls_enum(L, "Error", (lua_Integer)cclua::bugly::LogLevel::Error);
    oluacls_enum(L, "Info", (lua_Integer)cclua::bugly::LogLevel::Info);
    oluacls_enum(L, "Off", (lua_Integer)cclua::bugly::LogLevel::Off);
    oluacls_enum(L, "Verbose", (lua_Integer)cclua::bugly::LogLevel::Verbose);
    oluacls_enum(L, "Warning", (lua_Integer)cclua::bugly::LogLevel::Warning);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_bugly_LogLevel(lua_State *L)
{
    olua_require(L, "bugly",  _olua_module_bugly);
    if (!olua_getclass(L, "cclua.bugly.LogLevel")) {
        luaL_error(L, "class not found: cclua::bugly::LogLevel");
    }
    return 1;
}
OLUA_END_DECLS
#endif

#ifdef CCLUA_BUILD_BUGLY
static int _olua_fun_cclua_bugly___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::bugly *)olua_toobj(L, 1, "cclua.bugly");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cclua_bugly_init(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** appid */

    olua_check_string(L, 1, &arg1);

    // static void init(const char *appid)
    cclua::bugly::init(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cclua_bugly_log(lua_State *L)
{
    olua_startinvoke(L);

    cclua::bugly::LogLevel arg1 = (cclua::bugly::LogLevel)0;       /** level */
    const char *arg2 = nullptr;       /** message */

    olua_check_enum(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // static void log(cclua::bugly::LogLevel level, const char *message)
    cclua::bugly::log(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cclua_bugly_reportException(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** msg */
    const char *arg2 = nullptr;       /** traceback */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // static void reportException(const char *msg, const char *traceback)
    cclua::bugly::reportException(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cclua_bugly_setChannel(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** channel */

    olua_check_string(L, 1, &arg1);

    // static void setChannel(const char *channel)
    cclua::bugly::setChannel(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cclua_bugly_setTag(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** tag */

    olua_check_integer(L, 1, &arg1);

    // static void setTag(int tag)
    cclua::bugly::setTag(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cclua_bugly_setUid(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** uid */

    olua_check_string(L, 1, &arg1);

    // static void setUid(const char *uid)
    cclua::bugly::setUid(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cclua_bugly_setUserValue(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */
    const char *arg2 = nullptr;       /** value */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // static void setUserValue(const char *key, const char *value)
    cclua::bugly::setUserValue(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cclua_bugly_setVersion(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** version */

    olua_check_string(L, 1, &arg1);

    // static void setVersion(const char *version)
    cclua::bugly::setVersion(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_cclua_bugly(lua_State *L)
{
    oluacls_class<cclua::bugly>(L, "cclua.bugly");
    oluacls_func(L, "__gc", _olua_fun_cclua_bugly___gc);
    oluacls_func(L, "init", _olua_fun_cclua_bugly_init);
    oluacls_func(L, "log", _olua_fun_cclua_bugly_log);
    oluacls_func(L, "reportException", _olua_fun_cclua_bugly_reportException);
    oluacls_func(L, "setChannel", _olua_fun_cclua_bugly_setChannel);
    oluacls_func(L, "setTag", _olua_fun_cclua_bugly_setTag);
    oluacls_func(L, "setUid", _olua_fun_cclua_bugly_setUid);
    oluacls_func(L, "setUserValue", _olua_fun_cclua_bugly_setUserValue);
    oluacls_func(L, "setVersion", _olua_fun_cclua_bugly_setVersion);

    cclua::runtime::registerFeature("cclua.bugly", true);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_bugly(lua_State *L)
{
    olua_require(L, "bugly",  _olua_module_bugly);
    if (!olua_getclass(L, "cclua.bugly")) {
        luaL_error(L, "class not found: cclua::bugly");
    }
    return 1;
}
OLUA_END_DECLS
#endif

int _olua_module_bugly(lua_State *L)
{
#ifdef CCLUA_BUILD_BUGLY
    olua_require(L, "cclua.bugly.LogLevel", _olua_cls_cclua_bugly_LogLevel);
    olua_require(L, "cclua.bugly", _olua_cls_cclua_bugly);
#endif

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_bugly(lua_State *L)
{
    olua_require(L, "bugly",  _olua_module_bugly);

    return 0;
}
OLUA_END_DECLS
