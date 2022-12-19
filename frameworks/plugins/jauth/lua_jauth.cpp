//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_jauth.h"
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "jauth/jauth.h"

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

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_jauth(lua_State *L)
{
#ifdef CCLUA_BUILD_JAUTH
    olua_require(L, "cclua.plugin.jauth", luaopen_cclua_plugin_jauth);
#endif

    return 0;
}
OLUA_END_DECLS
