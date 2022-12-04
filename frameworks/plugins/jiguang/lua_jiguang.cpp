//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_jiguang.h"
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "jiguang/jiguang.h"

#ifdef CCLUA_BUILD_JPUSH
static int _cclua_plugin_jpush___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::plugin::jpush *)olua_toobj(L, 1, "cclua.plugin.jpush");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jpush___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::plugin::jpush *)olua_toobj(L, 1, "cclua.plugin.jpush");
    olua_push_object(L, self, "cclua.plugin.jpush");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_plugin_jpush_addTags(lua_State *L)
{
    olua_startinvoke(L);

    std::set<std::string> arg1;       /** tags */

    olua_check_vector<std::string>(L, 1, arg1, [L](std::string *arg1) {
        olua_check_string(L, -1, arg1);
    });

    // static void addTags(const std::set<std::string> &tags)
    cclua::plugin::jpush::addTags(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jpush_cleanTags(lua_State *L)
{
    olua_startinvoke(L);

    // static void cleanTags()
    cclua::plugin::jpush::cleanTags();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jpush_deleteAlias(lua_State *L)
{
    olua_startinvoke(L);

    // static void deleteAlias()
    cclua::plugin::jpush::deleteAlias();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jpush_deleteTags(lua_State *L)
{
    olua_startinvoke(L);

    std::set<std::string> arg1;       /** tags */

    olua_check_vector<std::string>(L, 1, arg1, [L](std::string *arg1) {
        olua_check_string(L, -1, arg1);
    });

    // static void deleteTags(const std::set<std::string> &tags)
    cclua::plugin::jpush::deleteTags(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jpush_getRegistrationID(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string getRegistrationID()
    std::string ret = cclua::plugin::jpush::getRegistrationID();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_plugin_jpush_init(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** appKey */
    std::string arg2;       /** channel */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // static void init(const std::string &appKey, const std::string &channel)
    cclua::plugin::jpush::init(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jpush_isEnabled(lua_State *L)
{
    olua_startinvoke(L);

    // static bool isEnabled()
    bool ret = cclua::plugin::jpush::isEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_plugin_jpush_requestPermission(lua_State *L)
{
    olua_startinvoke(L);

    // static void requestPermission()
    cclua::plugin::jpush::requestPermission();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jpush_setAlias(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** alias */

    olua_check_string(L, 1, &arg1);

    // static void setAlias(const std::string &alias)
    cclua::plugin::jpush::setAlias(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jpush_setBadge(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** value */

    olua_check_integer(L, 1, &arg1);

    // static void setBadge(int value)
    cclua::plugin::jpush::setBadge(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jpush_setDebug(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** enabled */

    olua_check_bool(L, 1, &arg1);

    // static void setDebug(bool enabled)
    cclua::plugin::jpush::setDebug(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jpush_setLogOFF(lua_State *L)
{
    olua_startinvoke(L);

    // static void setLogOFF()
    cclua::plugin::jpush::setLogOFF();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jpush_setTags(lua_State *L)
{
    olua_startinvoke(L);

    std::set<std::string> arg1;       /** tags */

    olua_check_vector<std::string>(L, 1, arg1, [L](std::string *arg1) {
        olua_check_string(L, -1, arg1);
    });

    // static void setTags(const std::set<std::string> &tags)
    cclua::plugin::jpush::setTags(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_plugin_jpush(lua_State *L)
{
    oluacls_class<cclua::plugin::jpush>(L, "cclua.plugin.jpush");
    oluacls_func(L, "__gc", _cclua_plugin_jpush___gc);
    oluacls_func(L, "__olua_move", _cclua_plugin_jpush___olua_move);
    oluacls_func(L, "addTags", _cclua_plugin_jpush_addTags);
    oluacls_func(L, "cleanTags", _cclua_plugin_jpush_cleanTags);
    oluacls_func(L, "deleteAlias", _cclua_plugin_jpush_deleteAlias);
    oluacls_func(L, "deleteTags", _cclua_plugin_jpush_deleteTags);
    oluacls_func(L, "getRegistrationID", _cclua_plugin_jpush_getRegistrationID);
    oluacls_func(L, "init", _cclua_plugin_jpush_init);
    oluacls_func(L, "isEnabled", _cclua_plugin_jpush_isEnabled);
    oluacls_func(L, "requestPermission", _cclua_plugin_jpush_requestPermission);
    oluacls_func(L, "setAlias", _cclua_plugin_jpush_setAlias);
    oluacls_func(L, "setBadge", _cclua_plugin_jpush_setBadge);
    oluacls_func(L, "setDebug", _cclua_plugin_jpush_setDebug);
    oluacls_func(L, "setLogOFF", _cclua_plugin_jpush_setLogOFF);
    oluacls_func(L, "setTags", _cclua_plugin_jpush_setTags);
    oluacls_prop(L, "enabled", _cclua_plugin_jpush_isEnabled, nullptr);
    oluacls_prop(L, "registrationID", _cclua_plugin_jpush_getRegistrationID, nullptr);

    cclua::runtime::registerFeature("cclua.plugin.jpush.ios", true);

    return 1;
}
OLUA_END_DECLS
#endif

#ifdef CCLUA_BUILD_JAUTH
static int _cclua_plugin_jauth___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::plugin::jauth *)olua_toobj(L, 1, "cclua.plugin.jauth");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jauth___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::plugin::jauth *)olua_toobj(L, 1, "cclua.plugin.jauth");
    olua_push_object(L, self, "cclua.plugin.jauth");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_plugin_jauth_checkVerifyEnable(lua_State *L)
{
    olua_startinvoke(L);

    // static bool checkVerifyEnable()
    bool ret = cclua::plugin::jauth::checkVerifyEnable();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_plugin_jauth_clearPreLoginCache(lua_State *L)
{
    olua_startinvoke(L);

    // static void clearPreLoginCache()
    cclua::plugin::jauth::clearPreLoginCache();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jauth_configUI$1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ValueMap arg1;       /** value */
    bool arg2 = false;       /** landscape */

    olua_check_cocos2d_ValueMap(L, 1, &arg1);
    olua_check_bool(L, 2, &arg2);

    // static void configUI(const cocos2d::ValueMap &value, @optional bool landscape)
    cclua::plugin::jauth::configUI(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jauth_configUI$2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ValueMap arg1;       /** value */

    olua_check_cocos2d_ValueMap(L, 1, &arg1);

    // static void configUI(const cocos2d::ValueMap &value, @optional bool landscape)
    cclua::plugin::jauth::configUI(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jauth_configUI(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_cocos2d_ValueMap(L, 1))) {
            // static void configUI(const cocos2d::ValueMap &value, @optional bool landscape)
            return _cclua_plugin_jauth_configUI$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_cocos2d_ValueMap(L, 1)) && (olua_is_bool(L, 2))) {
            // static void configUI(const cocos2d::ValueMap &value, @optional bool landscape)
            return _cclua_plugin_jauth_configUI$1(L);
        // }
    }

    luaL_error(L, "method 'cclua::plugin::jauth::configUI' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_plugin_jauth_dismissLoginAuth$1(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** needCloseAnim */

    olua_check_bool(L, 1, &arg1);

    // static void dismissLoginAuth(@optional bool needCloseAnim)
    cclua::plugin::jauth::dismissLoginAuth(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jauth_dismissLoginAuth$2(lua_State *L)
{
    olua_startinvoke(L);

    // static void dismissLoginAuth(@optional bool needCloseAnim)
    cclua::plugin::jauth::dismissLoginAuth();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jauth_dismissLoginAuth(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static void dismissLoginAuth(@optional bool needCloseAnim)
        return _cclua_plugin_jauth_dismissLoginAuth$2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_bool(L, 1))) {
            // static void dismissLoginAuth(@optional bool needCloseAnim)
            return _cclua_plugin_jauth_dismissLoginAuth$1(L);
        // }
    }

    luaL_error(L, "method 'cclua::plugin::jauth::dismissLoginAuth' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_plugin_jauth_dispatch(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** event */
    cocos2d::ValueMap arg2;       /** data */

    olua_check_string(L, 1, &arg1);
    olua_check_cocos2d_ValueMap(L, 2, &arg2);

    // static void dispatch(const std::string &event, const cocos2d::ValueMap &data)
    cclua::plugin::jauth::dispatch(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jauth_getSmsCode(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** phonenum */
    std::string arg2;       /** signid */
    std::string arg3;       /** tempid */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_string(L, 3, &arg3);

    // static void getSmsCode(const std::string &phonenum, const std::string &signid, const std::string &tempid)
    cclua::plugin::jauth::getSmsCode(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jauth_getToken(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** timeout */

    olua_check_integer(L, 1, &arg1);

    // static void getToken(int timeout)
    cclua::plugin::jauth::getToken(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jauth_init(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** appKey */
    std::string arg2;       /** channel */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // static void init(const std::string &appKey, const std::string &channel)
    cclua::plugin::jauth::init(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jauth_isInitSuccess(lua_State *L)
{
    olua_startinvoke(L);

    // static bool isInitSuccess()
    bool ret = cclua::plugin::jauth::isInitSuccess();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_plugin_jauth_loginAuth(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** timeout */

    olua_check_integer(L, 1, &arg1);

    // static void loginAuth(int timeout)
    cclua::plugin::jauth::loginAuth(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jauth_preLogin(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** timeout */

    olua_check_integer(L, 1, &arg1);

    // static void preLogin(int timeout)
    cclua::plugin::jauth::preLogin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jauth_setDebug(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** enabled */

    olua_check_bool(L, 1, &arg1);

    // static void setDebug(bool enabled)
    cclua::plugin::jauth::setDebug(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jauth_setDispatcher(lua_State *L)
{
    olua_startinvoke(L);

    cclua::Callback arg1;       /** dispatcher */

    olua_check_callback(L, 1, &arg1, "cclua.Callback");

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.plugin.jauth");
    std::string cb_tag = "Dispatcher";
    std::string cb_name = olua_setcallback(L, cb_store,  1, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](const std::string &arg1, const cocos2d::Value &arg2) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_string(L, arg1);
            olua_push_cocos2d_Value(L, arg2);
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 2);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // static void setDispatcher(@localvar const cclua::Callback &dispatcher)
    cclua::plugin::jauth::setDispatcher(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jauth_setSmsIntervalTime(lua_State *L)
{
    olua_startinvoke(L);

    int64_t arg1 = 0;       /** intervalTime */

    olua_check_integer(L, 1, &arg1);

    // static void setSmsIntervalTime(int64_t intervalTime)
    cclua::plugin::jauth::setSmsIntervalTime(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_plugin_jauth(lua_State *L)
{
    oluacls_class<cclua::plugin::jauth>(L, "cclua.plugin.jauth");
    oluacls_func(L, "__gc", _cclua_plugin_jauth___gc);
    oluacls_func(L, "__olua_move", _cclua_plugin_jauth___olua_move);
    oluacls_func(L, "checkVerifyEnable", _cclua_plugin_jauth_checkVerifyEnable);
    oluacls_func(L, "clearPreLoginCache", _cclua_plugin_jauth_clearPreLoginCache);
    oluacls_func(L, "configUI", _cclua_plugin_jauth_configUI);
    oluacls_func(L, "dismissLoginAuth", _cclua_plugin_jauth_dismissLoginAuth);
    oluacls_func(L, "dispatch", _cclua_plugin_jauth_dispatch);
    oluacls_func(L, "getSmsCode", _cclua_plugin_jauth_getSmsCode);
    oluacls_func(L, "getToken", _cclua_plugin_jauth_getToken);
    oluacls_func(L, "init", _cclua_plugin_jauth_init);
    oluacls_func(L, "isInitSuccess", _cclua_plugin_jauth_isInitSuccess);
    oluacls_func(L, "loginAuth", _cclua_plugin_jauth_loginAuth);
    oluacls_func(L, "preLogin", _cclua_plugin_jauth_preLogin);
    oluacls_func(L, "setDebug", _cclua_plugin_jauth_setDebug);
    oluacls_func(L, "setDispatcher", _cclua_plugin_jauth_setDispatcher);
    oluacls_func(L, "setSmsIntervalTime", _cclua_plugin_jauth_setSmsIntervalTime);
    oluacls_prop(L, "initSuccess", _cclua_plugin_jauth_isInitSuccess, nullptr);

    cclua::runtime::registerFeature("cclua.plugin.jauth.ios", true);

    return 1;
}
OLUA_END_DECLS
#endif

#ifdef CCLUA_BUILD_JANALYTICS
OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_plugin_janalytics_EventType(lua_State *L)
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
OLUA_END_DECLS
#endif

#ifdef CCLUA_BUILD_JANALYTICS
static int _cclua_plugin_janalytics___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::plugin::janalytics *)olua_toobj(L, 1, "cclua.plugin.janalytics");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_janalytics___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::plugin::janalytics *)olua_toobj(L, 1, "cclua.plugin.janalytics");
    olua_push_object(L, self, "cclua.plugin.janalytics");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_plugin_janalytics_detachAccount(lua_State *L)
{
    olua_startinvoke(L);

    // static void detachAccount()
    cclua::plugin::janalytics::detachAccount();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_janalytics_identifyAccount(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ValueMap arg1;       /** value */

    olua_check_cocos2d_ValueMap(L, 1, &arg1);

    // static void identifyAccount(const cocos2d::ValueMap &value)
    cclua::plugin::janalytics::identifyAccount(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_janalytics_init(lua_State *L)
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

static int _cclua_plugin_janalytics_setDebug(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** enable */

    olua_check_bool(L, 1, &arg1);

    // static void setDebug(bool enable)
    cclua::plugin::janalytics::setDebug(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_janalytics_setFrequency(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** frequency */

    olua_check_integer(L, 1, &arg1);

    // static void setFrequency(int frequency)
    cclua::plugin::janalytics::setFrequency(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_janalytics_startTrackPage(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** pageName */

    olua_check_string(L, 1, &arg1);

    // static void startTrackPage(const std::string &pageName)
    cclua::plugin::janalytics::startTrackPage(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_janalytics_stopTrackPage(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** pageName */

    olua_check_string(L, 1, &arg1);

    // static void stopTrackPage(const std::string &pageName)
    cclua::plugin::janalytics::stopTrackPage(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_janalytics_trackEvent(lua_State *L)
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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_plugin_janalytics(lua_State *L)
{
    oluacls_class<cclua::plugin::janalytics>(L, "cclua.plugin.janalytics");
    oluacls_func(L, "__gc", _cclua_plugin_janalytics___gc);
    oluacls_func(L, "__olua_move", _cclua_plugin_janalytics___olua_move);
    oluacls_func(L, "detachAccount", _cclua_plugin_janalytics_detachAccount);
    oluacls_func(L, "identifyAccount", _cclua_plugin_janalytics_identifyAccount);
    oluacls_func(L, "init", _cclua_plugin_janalytics_init);
    oluacls_func(L, "setDebug", _cclua_plugin_janalytics_setDebug);
    oluacls_func(L, "setFrequency", _cclua_plugin_janalytics_setFrequency);
    oluacls_func(L, "startTrackPage", _cclua_plugin_janalytics_startTrackPage);
    oluacls_func(L, "stopTrackPage", _cclua_plugin_janalytics_stopTrackPage);
    oluacls_func(L, "trackEvent", _cclua_plugin_janalytics_trackEvent);

    cclua::runtime::registerFeature("cclua.plugin.janalytics.ios", true);

    return 1;
}
OLUA_END_DECLS
#endif

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_jiguang(lua_State *L)
{
#ifdef CCLUA_BUILD_JPUSH
    olua_require(L, "cclua.plugin.jpush", luaopen_cclua_plugin_jpush);
#endif
#ifdef CCLUA_BUILD_JAUTH
    olua_require(L, "cclua.plugin.jauth", luaopen_cclua_plugin_jauth);
#endif
#ifdef CCLUA_BUILD_JANALYTICS
    olua_require(L, "cclua.plugin.janalytics.EventType", luaopen_cclua_plugin_janalytics_EventType);
    olua_require(L, "cclua.plugin.janalytics", luaopen_cclua_plugin_janalytics);
#endif

    return 0;
}
OLUA_END_DECLS
