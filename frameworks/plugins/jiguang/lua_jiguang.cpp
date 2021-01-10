//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_jiguang.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cclua/xlua.h"
#include "JiGuang.h"

#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)

#ifdef CCLUA_BUILD_JPUSH
static int _cclua_plugin_JPush___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::plugin::JPush *)olua_toobj(L, 1, "cclua.plugin.JPush");
    olua_push_cppobj(L, self, "cclua.plugin.JPush");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_plugin_JPush_addTags(lua_State *L)
{
    olua_startinvoke(L);

    std::set<std::string> arg1;       /** tags */

    luaL_checktype(L, 1, LUA_TTABLE);
    int arg1_total = (int)lua_rawlen(L, 1);
    for (int i = 1; i <= arg1_total; i++) {
        std::string obj;
        lua_rawgeti(L, 1, i);
        olua_check_std_string(L, -1, &obj);
        arg1.insert((std::string)obj);
        lua_pop(L, 1);
    }

    // static void addTags(const std::set<std::string> &tags)
    cclua::plugin::JPush::addTags(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_JPush_cleanTags(lua_State *L)
{
    olua_startinvoke(L);

    // static void cleanTags()
    cclua::plugin::JPush::cleanTags();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_JPush_deleteAlias(lua_State *L)
{
    olua_startinvoke(L);

    // static void deleteAlias()
    cclua::plugin::JPush::deleteAlias();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_JPush_deleteTags(lua_State *L)
{
    olua_startinvoke(L);

    std::set<std::string> arg1;       /** tags */

    luaL_checktype(L, 1, LUA_TTABLE);
    int arg1_total = (int)lua_rawlen(L, 1);
    for (int i = 1; i <= arg1_total; i++) {
        std::string obj;
        lua_rawgeti(L, 1, i);
        olua_check_std_string(L, -1, &obj);
        arg1.insert((std::string)obj);
        lua_pop(L, 1);
    }

    // static void deleteTags(const std::set<std::string> &tags)
    cclua::plugin::JPush::deleteTags(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_JPush_getRegistrationID(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string getRegistrationID()
    std::string ret = cclua::plugin::JPush::getRegistrationID();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_plugin_JPush_init(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** appKey */
    std::string arg2;       /** channel */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static void init(const std::string &appKey, const std::string &channel)
    cclua::plugin::JPush::init(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_JPush_isEnabled(lua_State *L)
{
    olua_startinvoke(L);

    // static bool isEnabled()
    bool ret = cclua::plugin::JPush::isEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_plugin_JPush_requestPermission(lua_State *L)
{
    olua_startinvoke(L);

    // static void requestPermission()
    cclua::plugin::JPush::requestPermission();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_JPush_setAlias(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** alias */

    olua_check_std_string(L, 1, &arg1);

    // static void setAlias(const std::string &alias)
    cclua::plugin::JPush::setAlias(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_JPush_setBadge(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** value */

    olua_check_int(L, 1, &arg1);

    // static void setBadge(int value)
    cclua::plugin::JPush::setBadge((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_JPush_setDebug(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** enabled */

    olua_check_bool(L, 1, &arg1);

    // static void setDebug(bool enabled)
    cclua::plugin::JPush::setDebug(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_JPush_setLogOFF(lua_State *L)
{
    olua_startinvoke(L);

    // static void setLogOFF()
    cclua::plugin::JPush::setLogOFF();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_JPush_setTags(lua_State *L)
{
    olua_startinvoke(L);

    std::set<std::string> arg1;       /** tags */

    luaL_checktype(L, 1, LUA_TTABLE);
    int arg1_total = (int)lua_rawlen(L, 1);
    for (int i = 1; i <= arg1_total; i++) {
        std::string obj;
        lua_rawgeti(L, 1, i);
        olua_check_std_string(L, -1, &obj);
        arg1.insert((std::string)obj);
        lua_pop(L, 1);
    }

    // static void setTags(const std::set<std::string> &tags)
    cclua::plugin::JPush::setTags(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cclua_plugin_JPush(lua_State *L)
{
    oluacls_class(L, "cclua.plugin.JPush", nullptr);
    oluacls_func(L, "__move", _cclua_plugin_JPush___move);
    oluacls_func(L, "addTags", _cclua_plugin_JPush_addTags);
    oluacls_func(L, "cleanTags", _cclua_plugin_JPush_cleanTags);
    oluacls_func(L, "deleteAlias", _cclua_plugin_JPush_deleteAlias);
    oluacls_func(L, "deleteTags", _cclua_plugin_JPush_deleteTags);
    oluacls_func(L, "getRegistrationID", _cclua_plugin_JPush_getRegistrationID);
    oluacls_func(L, "init", _cclua_plugin_JPush_init);
    oluacls_func(L, "isEnabled", _cclua_plugin_JPush_isEnabled);
    oluacls_func(L, "requestPermission", _cclua_plugin_JPush_requestPermission);
    oluacls_func(L, "setAlias", _cclua_plugin_JPush_setAlias);
    oluacls_func(L, "setBadge", _cclua_plugin_JPush_setBadge);
    oluacls_func(L, "setDebug", _cclua_plugin_JPush_setDebug);
    oluacls_func(L, "setLogOFF", _cclua_plugin_JPush_setLogOFF);
    oluacls_func(L, "setTags", _cclua_plugin_JPush_setTags);
    oluacls_prop(L, "enabled", _cclua_plugin_JPush_isEnabled, nullptr);
    oluacls_prop(L, "registrationID", _cclua_plugin_JPush_getRegistrationID, nullptr);

    olua_registerluatype<cclua::plugin::JPush>(L, "cclua.plugin.JPush");

    return 1;
}
#endif

#ifdef CCLUA_BUILD_JANALYTICS
static int luaopen_cclua_plugin_JAnalytics_EventType(lua_State *L)
{
    oluacls_class(L, "cclua.plugin.JAnalytics.EventType", nullptr);
    oluacls_const_integer(L, "BROWSE", (lua_Integer)cclua::plugin::JAnalytics::EventType::BROWSE);
    oluacls_const_integer(L, "CALCULATE", (lua_Integer)cclua::plugin::JAnalytics::EventType::CALCULATE);
    oluacls_const_integer(L, "COUNT", (lua_Integer)cclua::plugin::JAnalytics::EventType::COUNT);
    oluacls_const_integer(L, "LOGIN", (lua_Integer)cclua::plugin::JAnalytics::EventType::LOGIN);
    oluacls_const_integer(L, "PURCHASE", (lua_Integer)cclua::plugin::JAnalytics::EventType::PURCHASE);
    oluacls_const_integer(L, "REGISTER", (lua_Integer)cclua::plugin::JAnalytics::EventType::REGISTER);

    olua_registerluatype<cclua::plugin::JAnalytics::EventType>(L, "cclua.plugin.JAnalytics.EventType");

    return 1;
}
#endif

#ifdef CCLUA_BUILD_JANALYTICS
static int _cclua_plugin_JAnalytics___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::plugin::JAnalytics *)olua_toobj(L, 1, "cclua.plugin.JAnalytics");
    olua_push_cppobj(L, self, "cclua.plugin.JAnalytics");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_plugin_JAnalytics_detachAccount(lua_State *L)
{
    olua_startinvoke(L);

    // static void detachAccount()
    cclua::plugin::JAnalytics::detachAccount();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_JAnalytics_identifyAccount(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ValueMap arg1;       /** value */

    manual_olua_check_cocos2d_ValueMap(L, 1, &arg1);

    // static void identifyAccount(cocos2d::ValueMap &value)
    cclua::plugin::JAnalytics::identifyAccount(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_JAnalytics_init(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** appKey */
    std::string arg2;       /** channel */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static void init(const std::string &appKey, const std::string &channel)
    cclua::plugin::JAnalytics::init(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_JAnalytics_setDebug(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** enable */

    olua_check_bool(L, 1, &arg1);

    // static void setDebug(bool enable)
    cclua::plugin::JAnalytics::setDebug(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_JAnalytics_setFrequency(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** frequency */

    olua_check_int(L, 1, &arg1);

    // static void setFrequency(int frequency)
    cclua::plugin::JAnalytics::setFrequency((int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_JAnalytics_startTrackPage(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** pageName */

    olua_check_std_string(L, 1, &arg1);

    // static void startTrackPage(const std::string &pageName)
    cclua::plugin::JAnalytics::startTrackPage(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_JAnalytics_stopTrackPage(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** pageName */

    olua_check_std_string(L, 1, &arg1);

    // static void stopTrackPage(const std::string &pageName)
    cclua::plugin::JAnalytics::stopTrackPage(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_JAnalytics_trackEvent(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** type */
    cocos2d::ValueMap arg2;       /** value */

    olua_check_uint(L, 1, &arg1);
    manual_olua_check_cocos2d_ValueMap(L, 2, &arg2);

    // static void trackEvent(cclua::plugin::JAnalytics::EventType type, cocos2d::ValueMap &value)
    cclua::plugin::JAnalytics::trackEvent((cclua::plugin::JAnalytics::EventType)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cclua_plugin_JAnalytics(lua_State *L)
{
    oluacls_class(L, "cclua.plugin.JAnalytics", nullptr);
    oluacls_func(L, "__move", _cclua_plugin_JAnalytics___move);
    oluacls_func(L, "detachAccount", _cclua_plugin_JAnalytics_detachAccount);
    oluacls_func(L, "identifyAccount", _cclua_plugin_JAnalytics_identifyAccount);
    oluacls_func(L, "init", _cclua_plugin_JAnalytics_init);
    oluacls_func(L, "setDebug", _cclua_plugin_JAnalytics_setDebug);
    oluacls_func(L, "setFrequency", _cclua_plugin_JAnalytics_setFrequency);
    oluacls_func(L, "startTrackPage", _cclua_plugin_JAnalytics_startTrackPage);
    oluacls_func(L, "stopTrackPage", _cclua_plugin_JAnalytics_stopTrackPage);
    oluacls_func(L, "trackEvent", _cclua_plugin_JAnalytics_trackEvent);

    olua_registerluatype<cclua::plugin::JAnalytics>(L, "cclua.plugin.JAnalytics");

    return 1;
}
#endif

int luaopen_jiguang(lua_State *L)
{
#ifdef CCLUA_BUILD_JPUSH
    olua_require(L, "cclua.plugin.JPush", luaopen_cclua_plugin_JPush);
#endif
#ifdef CCLUA_BUILD_JANALYTICS
    olua_require(L, "cclua.plugin.JAnalytics.EventType", luaopen_cclua_plugin_JAnalytics_EventType);
#endif
#ifdef CCLUA_BUILD_JANALYTICS
    olua_require(L, "cclua.plugin.JAnalytics", luaopen_cclua_plugin_JAnalytics);
#endif
    return 0;
}

#endif