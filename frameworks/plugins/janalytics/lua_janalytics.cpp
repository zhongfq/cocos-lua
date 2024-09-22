//
// AUTO GENERATED, DO NOT MODIFY!
//
#include "lua_janalytics.h"
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "janalytics/janalytics.h"

static int _olua_module_janalytics(lua_State *L);

#ifdef CCLUA_BUILD_JANALYTICS
static int _olua_cls_cclua_plugin_janalytics_EventType(lua_State *L)
{
    oluacls_class<cclua::plugin::janalytics::EventType>(L, "cclua.plugin.janalytics.EventType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "BROWSE", (lua_Integer)cclua::plugin::janalytics::EventType::BROWSE);
    oluacls_enum(L, "CALCULATE", (lua_Integer)cclua::plugin::janalytics::EventType::CALCULATE);
    oluacls_enum(L, "COUNT", (lua_Integer)cclua::plugin::janalytics::EventType::COUNT);
    oluacls_enum(L, "LOGIN", (lua_Integer)cclua::plugin::janalytics::EventType::LOGIN);
    oluacls_enum(L, "PURCHASE", (lua_Integer)cclua::plugin::janalytics::EventType::PURCHASE);
    oluacls_enum(L, "REGISTER", (lua_Integer)cclua::plugin::janalytics::EventType::REGISTER);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_plugin_janalytics_EventType(lua_State *L)
{
    olua_require(L, "janalytics",  _olua_module_janalytics);
    if (!olua_getclass(L, "cclua.plugin.janalytics.EventType")) {
        luaL_error(L, "class not found: cclua::plugin::janalytics::EventType");
    }
    return 1;
}
OLUA_END_DECLS
#endif

#ifdef CCLUA_BUILD_JANALYTICS
static int _olua_fun_cclua_plugin_janalytics___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::plugin::janalytics *)olua_toobj(L, 1, "cclua.plugin.janalytics");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cclua_plugin_janalytics_detachAccount(lua_State *L)
{
    olua_startinvoke(L);

    // static void detachAccount()
    cclua::plugin::janalytics::detachAccount();

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cclua_plugin_janalytics_identifyAccount(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ValueMap arg1;       /** value */

    olua_check_cocos2d_ValueMap(L, 1, &arg1);

    // static void identifyAccount(const cocos2d::ValueMap &value)
    cclua::plugin::janalytics::identifyAccount(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cclua_plugin_janalytics_init(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** appKey */
    std::string arg2;       /** channel */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // static void init(const std::string &appKey, const std::string &channel)
    cclua::plugin::janalytics::init(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cclua_plugin_janalytics_setDebug(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** enable */

    olua_check_bool(L, 1, &arg1);

    // static void setDebug(bool enable)
    cclua::plugin::janalytics::setDebug(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cclua_plugin_janalytics_setFrequency(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** frequency */

    olua_check_integer(L, 1, &arg1);

    // static void setFrequency(int frequency)
    cclua::plugin::janalytics::setFrequency(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cclua_plugin_janalytics_startTrackPage(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** pageName */

    olua_check_string(L, 1, &arg1);

    // static void startTrackPage(const std::string &pageName)
    cclua::plugin::janalytics::startTrackPage(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cclua_plugin_janalytics_stopTrackPage(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** pageName */

    olua_check_string(L, 1, &arg1);

    // static void stopTrackPage(const std::string &pageName)
    cclua::plugin::janalytics::stopTrackPage(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cclua_plugin_janalytics_trackEvent(lua_State *L)
{
    olua_startinvoke(L);

    cclua::plugin::janalytics::EventType arg1 = (cclua::plugin::janalytics::EventType)0;       /** type */
    cocos2d::ValueMap arg2;       /** value */

    olua_check_enum(L, 1, &arg1);
    olua_check_cocos2d_ValueMap(L, 2, &arg2);

    // static void trackEvent(cclua::plugin::janalytics::EventType type, const cocos2d::ValueMap &value)
    cclua::plugin::janalytics::trackEvent(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_cclua_plugin_janalytics(lua_State *L)
{
    oluacls_class<cclua::plugin::janalytics>(L, "cclua.plugin.janalytics");
    oluacls_func(L, "__gc", _olua_fun_cclua_plugin_janalytics___gc);
    oluacls_func(L, "detachAccount", _olua_fun_cclua_plugin_janalytics_detachAccount);
    oluacls_func(L, "identifyAccount", _olua_fun_cclua_plugin_janalytics_identifyAccount);
    oluacls_func(L, "init", _olua_fun_cclua_plugin_janalytics_init);
    oluacls_func(L, "setDebug", _olua_fun_cclua_plugin_janalytics_setDebug);
    oluacls_func(L, "setFrequency", _olua_fun_cclua_plugin_janalytics_setFrequency);
    oluacls_func(L, "startTrackPage", _olua_fun_cclua_plugin_janalytics_startTrackPage);
    oluacls_func(L, "stopTrackPage", _olua_fun_cclua_plugin_janalytics_stopTrackPage);
    oluacls_func(L, "trackEvent", _olua_fun_cclua_plugin_janalytics_trackEvent);

    cclua::runtime::registerFeature("cclua.plugin.janalytics.ios", true);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_plugin_janalytics(lua_State *L)
{
    olua_require(L, "janalytics",  _olua_module_janalytics);
    if (!olua_getclass(L, "cclua.plugin.janalytics")) {
        luaL_error(L, "class not found: cclua::plugin::janalytics");
    }
    return 1;
}
OLUA_END_DECLS
#endif

int _olua_module_janalytics(lua_State *L)
{
#ifdef CCLUA_BUILD_JANALYTICS
    olua_require(L, "cclua.plugin.janalytics.EventType", _olua_cls_cclua_plugin_janalytics_EventType);
    olua_require(L, "cclua.plugin.janalytics", _olua_cls_cclua_plugin_janalytics);
#endif

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_janalytics(lua_State *L)
{
    olua_require(L, "janalytics",  _olua_module_janalytics);

    return 0;
}
OLUA_END_DECLS
