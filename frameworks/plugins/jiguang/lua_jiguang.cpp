//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_jiguang.h"

#ifdef CCLUA_BUILD_JPUSH
static int _cclua_plugin_JPush___olua_move(lua_State *L)
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

    olua_check_std_set<std::string>(L, 1, &arg1, [L](std::string *value) {
        olua_check_std_string(L, -1, value);
    });

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

    olua_check_std_set<std::string>(L, 1, &arg1, [L](std::string *value) {
        olua_check_std_string(L, -1, value);
    });

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

    olua_check_std_set<std::string>(L, 1, &arg1, [L](std::string *value) {
        olua_check_std_string(L, -1, value);
    });

    // static void setTags(const std::set<std::string> &tags)
    cclua::plugin::JPush::setTags(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cclua_plugin_JPush(lua_State *L)
{
    oluacls_class(L, "cclua.plugin.JPush", nullptr);
    oluacls_func(L, "__olua_move", _cclua_plugin_JPush___olua_move);
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
    cclua::runtime::registerFeature("jpush", true);

    return 1;
}
#endif

#ifdef CCLUA_BUILD_JAUTH
static int _cclua_plugin_JAuth___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::plugin::JAuth *)olua_toobj(L, 1, "cclua.plugin.JAuth");
    olua_push_cppobj(L, self, "cclua.plugin.JAuth");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_plugin_JAuth_checkVerifyEnable(lua_State *L)
{
    olua_startinvoke(L);

    // static bool checkVerifyEnable()
    bool ret = cclua::plugin::JAuth::checkVerifyEnable();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_plugin_JAuth_clearPreLoginCache(lua_State *L)
{
    olua_startinvoke(L);

    // static void clearPreLoginCache()
    cclua::plugin::JAuth::clearPreLoginCache();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_JAuth_configUI1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ValueMap arg1;       /** value */
    bool arg2 = false;       /** landscape */

    olua_check_cocos2d_ValueMap(L, 1, &arg1);
    olua_check_bool(L, 2, &arg2);

    // static void configUI(cocos2d::ValueMap &value, @optional bool landscape)
    cclua::plugin::JAuth::configUI(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_JAuth_configUI2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ValueMap arg1;       /** value */

    olua_check_cocos2d_ValueMap(L, 1, &arg1);

    // static void configUI(cocos2d::ValueMap &value, @optional bool landscape)
    cclua::plugin::JAuth::configUI(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_JAuth_configUI(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_cocos2d_ValueMap(L, 1))) {
            // static void configUI(cocos2d::ValueMap &value, @optional bool landscape)
            return _cclua_plugin_JAuth_configUI2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_cocos2d_ValueMap(L, 1)) && (olua_is_bool(L, 2))) {
            // static void configUI(cocos2d::ValueMap &value, @optional bool landscape)
            return _cclua_plugin_JAuth_configUI1(L);
        // }
    }

    luaL_error(L, "method 'cclua::plugin::JAuth::configUI' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_plugin_JAuth_dismissLoginAuth1(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** needCloseAnim */

    olua_check_bool(L, 1, &arg1);

    // static void dismissLoginAuth(@optional bool needCloseAnim)
    cclua::plugin::JAuth::dismissLoginAuth(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_JAuth_dismissLoginAuth2(lua_State *L)
{
    olua_startinvoke(L);

    // static void dismissLoginAuth(@optional bool needCloseAnim)
    cclua::plugin::JAuth::dismissLoginAuth();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_JAuth_dismissLoginAuth(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static void dismissLoginAuth(@optional bool needCloseAnim)
        return _cclua_plugin_JAuth_dismissLoginAuth2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_bool(L, 1))) {
            // static void dismissLoginAuth(@optional bool needCloseAnim)
            return _cclua_plugin_JAuth_dismissLoginAuth1(L);
        // }
    }

    luaL_error(L, "method 'cclua::plugin::JAuth::dismissLoginAuth' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_plugin_JAuth_getSmsCode(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** phonenum */
    std::string arg2;       /** signid */
    std::string arg3;       /** tempid */
    std::function<void(const cocos2d::Value &)> arg4;       /** callback */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);
    olua_check_std_function(L, 4, &arg4);

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.plugin.JAuth");
    std::string cb_tag = "SmsCode";
    std::string cb_name = olua_setcallback(L, cb_store,  4, cb_tag.c_str(), OLUA_TAG_NEW);
    lua_Integer cb_ctx = olua_context(L);
    arg4 = [cb_store, cb_name, cb_ctx](const cocos2d::Value &arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (L != NULL && olua_context(L) == cb_ctx) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_cocos2d_Value(L, &arg1);
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            olua_removecallback(L, cb_store, cb_name.c_str(), OLUA_TAG_WHOLE);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // static void getSmsCode(const std::string &phonenum, const std::string &signid, const std::string &tempid, @local const std::function<void (const cocos2d::Value &)> callback)
    cclua::plugin::JAuth::getSmsCode(arg1, arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_JAuth_getToken(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** timeout */
    std::function<void(const cocos2d::Value &)> arg2;       /** callback */

    olua_check_int(L, 1, &arg1);
    olua_check_std_function(L, 2, &arg2);

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.plugin.JAuth");
    std::string cb_tag = "Token";
    std::string cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_NEW);
    lua_Integer cb_ctx = olua_context(L);
    arg2 = [cb_store, cb_name, cb_ctx](const cocos2d::Value &arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (L != NULL && olua_context(L) == cb_ctx) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_cocos2d_Value(L, &arg1);
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            olua_removecallback(L, cb_store, cb_name.c_str(), OLUA_TAG_WHOLE);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // static void getToken(int timeout, @local const std::function<void (const cocos2d::Value &)> callback)
    cclua::plugin::JAuth::getToken((int)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_JAuth_init(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** appKey */
    std::string arg2;       /** channel */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static void init(const std::string &appKey, const std::string &channel)
    cclua::plugin::JAuth::init(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_JAuth_isInitSuccess(lua_State *L)
{
    olua_startinvoke(L);

    // static bool isInitSuccess()
    bool ret = cclua::plugin::JAuth::isInitSuccess();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_plugin_JAuth_loginAuth(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** timeout */
    std::function<void(const cocos2d::Value &)> arg2;       /** callback */

    olua_check_int(L, 1, &arg1);
    olua_check_std_function(L, 2, &arg2);

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.plugin.JAuth");
    std::string cb_tag = "loginAuth";
    std::string cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_NEW);
    lua_Integer cb_ctx = olua_context(L);
    arg2 = [cb_store, cb_name, cb_ctx](const cocos2d::Value &arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (L != NULL && olua_context(L) == cb_ctx) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_cocos2d_Value(L, &arg1);
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            olua_removecallback(L, cb_store, cb_name.c_str(), OLUA_TAG_WHOLE);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // static void loginAuth(int timeout, @local const std::function<void (const cocos2d::Value &)> callback)
    cclua::plugin::JAuth::loginAuth((int)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_JAuth_preLogin(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** timeout */
    std::function<void(const cocos2d::Value &)> arg2;       /** callback */

    olua_check_int(L, 1, &arg1);
    olua_check_std_function(L, 2, &arg2);

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.plugin.JAuth");
    std::string cb_tag = "preLogin";
    std::string cb_name = olua_setcallback(L, cb_store,  2, cb_tag.c_str(), OLUA_TAG_NEW);
    lua_Integer cb_ctx = olua_context(L);
    arg2 = [cb_store, cb_name, cb_ctx](const cocos2d::Value &arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (L != NULL && olua_context(L) == cb_ctx) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_cocos2d_Value(L, &arg1);
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            olua_removecallback(L, cb_store, cb_name.c_str(), OLUA_TAG_WHOLE);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // static void preLogin(int timeout, @local const std::function<void (const cocos2d::Value &)> callback)
    cclua::plugin::JAuth::preLogin((int)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_JAuth_setDebug(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** enabled */

    olua_check_bool(L, 1, &arg1);

    // static void setDebug(bool enabled)
    cclua::plugin::JAuth::setDebug(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_JAuth_setSmsIntervalTime(lua_State *L)
{
    olua_startinvoke(L);

    lua_Integer arg1 = 0;       /** intervalTime */

    olua_check_int(L, 1, &arg1);

    // static void setSmsIntervalTime(long intervalTime)
    cclua::plugin::JAuth::setSmsIntervalTime((long)arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cclua_plugin_JAuth(lua_State *L)
{
    oluacls_class(L, "cclua.plugin.JAuth", nullptr);
    oluacls_func(L, "__olua_move", _cclua_plugin_JAuth___olua_move);
    oluacls_func(L, "checkVerifyEnable", _cclua_plugin_JAuth_checkVerifyEnable);
    oluacls_func(L, "clearPreLoginCache", _cclua_plugin_JAuth_clearPreLoginCache);
    oluacls_func(L, "configUI", _cclua_plugin_JAuth_configUI);
    oluacls_func(L, "dismissLoginAuth", _cclua_plugin_JAuth_dismissLoginAuth);
    oluacls_func(L, "getSmsCode", _cclua_plugin_JAuth_getSmsCode);
    oluacls_func(L, "getToken", _cclua_plugin_JAuth_getToken);
    oluacls_func(L, "init", _cclua_plugin_JAuth_init);
    oluacls_func(L, "isInitSuccess", _cclua_plugin_JAuth_isInitSuccess);
    oluacls_func(L, "loginAuth", _cclua_plugin_JAuth_loginAuth);
    oluacls_func(L, "preLogin", _cclua_plugin_JAuth_preLogin);
    oluacls_func(L, "setDebug", _cclua_plugin_JAuth_setDebug);
    oluacls_func(L, "setSmsIntervalTime", _cclua_plugin_JAuth_setSmsIntervalTime);
    oluacls_prop(L, "initSuccess", _cclua_plugin_JAuth_isInitSuccess, nullptr);

    olua_registerluatype<cclua::plugin::JAuth>(L, "cclua.plugin.JAuth");
    cclua::runtime::registerFeature("jauth", true);

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
static int _cclua_plugin_JAnalytics___olua_move(lua_State *L)
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

    olua_check_cocos2d_ValueMap(L, 1, &arg1);

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
    olua_check_cocos2d_ValueMap(L, 2, &arg2);

    // static void trackEvent(cclua::plugin::JAnalytics::EventType type, cocos2d::ValueMap &value)
    cclua::plugin::JAnalytics::trackEvent((cclua::plugin::JAnalytics::EventType)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cclua_plugin_JAnalytics(lua_State *L)
{
    oluacls_class(L, "cclua.plugin.JAnalytics", nullptr);
    oluacls_func(L, "__olua_move", _cclua_plugin_JAnalytics___olua_move);
    oluacls_func(L, "detachAccount", _cclua_plugin_JAnalytics_detachAccount);
    oluacls_func(L, "identifyAccount", _cclua_plugin_JAnalytics_identifyAccount);
    oluacls_func(L, "init", _cclua_plugin_JAnalytics_init);
    oluacls_func(L, "setDebug", _cclua_plugin_JAnalytics_setDebug);
    oluacls_func(L, "setFrequency", _cclua_plugin_JAnalytics_setFrequency);
    oluacls_func(L, "startTrackPage", _cclua_plugin_JAnalytics_startTrackPage);
    oluacls_func(L, "stopTrackPage", _cclua_plugin_JAnalytics_stopTrackPage);
    oluacls_func(L, "trackEvent", _cclua_plugin_JAnalytics_trackEvent);

    olua_registerluatype<cclua::plugin::JAnalytics>(L, "cclua.plugin.JAnalytics");
    cclua::runtime::registerFeature("janalytics", true);

    return 1;
}
#endif

int luaopen_jiguang(lua_State *L)
{
#ifdef CCLUA_BUILD_JPUSH
    olua_require(L, "cclua.plugin.JPush", luaopen_cclua_plugin_JPush);
#endif
#ifdef CCLUA_BUILD_JAUTH
    olua_require(L, "cclua.plugin.JAuth", luaopen_cclua_plugin_JAuth);
#endif
#ifdef CCLUA_BUILD_JANALYTICS
    olua_require(L, "cclua.plugin.JAnalytics.EventType", luaopen_cclua_plugin_JAnalytics_EventType);
#endif
#ifdef CCLUA_BUILD_JANALYTICS
    olua_require(L, "cclua.plugin.JAnalytics", luaopen_cclua_plugin_JAnalytics);
#endif
    return 0;
}
