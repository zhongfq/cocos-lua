//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_talkingdata.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "talkingdata/talkingdata.h"

#ifdef CCLUA_BUILD_TALKINGDATA
static int _cclua_plugin_talkingdata___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::plugin::talkingdata *)olua_toobj(L, 1, "cclua.plugin.talkingdata");
    olua_push_obj(L, self, "cclua.plugin.talkingdata");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_plugin_talkingdata_backgroundSessionEnabled(lua_State *L)
{
    olua_startinvoke(L);

    // static void backgroundSessionEnabled()
    cclua::plugin::talkingdata::backgroundSessionEnabled();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_getDeviceId(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string getDeviceId()
    std::string ret = cclua::plugin::talkingdata::getDeviceId();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_plugin_talkingdata_init$1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** appkey */
    std::string arg2;       /** channel */
    std::string arg3;       /** custom */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);

    // static void init(const std::string &appkey, const std::string &channel, @optional const std::string &custom)
    cclua::plugin::talkingdata::init(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_init$2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** appkey */
    std::string arg2;       /** channel */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static void init(const std::string &appkey, const std::string &channel, @optional const std::string &custom)
    cclua::plugin::talkingdata::init(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_init(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2))) {
            // static void init(const std::string &appkey, const std::string &channel, @optional const std::string &custom)
            return _cclua_plugin_talkingdata_init$2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_std_string(L, 3))) {
            // static void init(const std::string &appkey, const std::string &channel, @optional const std::string &custom)
            return _cclua_plugin_talkingdata_init$1(L);
        // }
    }

    luaL_error(L, "method 'cclua::plugin::talkingdata::init' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_plugin_talkingdata_onCreateCard(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** uid */
    std::string arg2;       /** method */
    std::string arg3;       /** content */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);

    // static void onCreateCard(const std::string &uid, const std::string &method, const std::string &content)
    cclua::plugin::talkingdata::onCreateCard(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_onEvent(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** event */
    lua_Number arg2 = 0;       /** value */
    cocos2d::ValueMap arg3;       /** data */

    olua_check_std_string(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);
    olua_check_cocos2d_ValueMap(L, 3, &arg3);

    // static void onEvent(const std::string &event, double value, const cocos2d::ValueMap &data)
    cclua::plugin::talkingdata::onEvent(arg1, (double)arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_onFavorite(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** category */
    std::string arg2;       /** content */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static void onFavorite(const std::string &category, const std::string &content)
    cclua::plugin::talkingdata::onFavorite(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_onLogin(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** uid */
    cocos2d::ValueMap arg2;       /** data */

    olua_check_std_string(L, 1, &arg1);
    olua_check_cocos2d_ValueMap(L, 2, &arg2);

    // static void onLogin(const std::string &uid, cocos2d::ValueMap &data)
    cclua::plugin::talkingdata::onLogin(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_onPageBegin(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** name */

    olua_check_std_string(L, 1, &arg1);

    // static void onPageBegin(const std::string &name)
    cclua::plugin::talkingdata::onPageBegin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_onPageEnd(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** name */

    olua_check_std_string(L, 1, &arg1);

    // static void onPageEnd(const std::string &name)
    cclua::plugin::talkingdata::onPageEnd(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_onProfileUpdate(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ValueMap arg1;       /** data */

    olua_check_cocos2d_ValueMap(L, 1, &arg1);

    // static void onProfileUpdate(cocos2d::ValueMap &data)
    cclua::plugin::talkingdata::onProfileUpdate(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_onPunch(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** uid */
    std::string arg2;       /** punchid */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static void onPunch(const std::string &uid, const std::string &punchid)
    cclua::plugin::talkingdata::onPunch(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_onReceiveDeepLink(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** link */

    olua_check_std_string(L, 1, &arg1);

    // static void onReceiveDeepLink(const std::string &link)
    cclua::plugin::talkingdata::onReceiveDeepLink(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_onRegister(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** uid */
    cocos2d::ValueMap arg2;       /** data */
    std::string arg3;       /** invitationCode */

    olua_check_std_string(L, 1, &arg1);
    olua_check_cocos2d_ValueMap(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);

    // static void onRegister(const std::string &uid, cocos2d::ValueMap &data, const std::string &invitationCode)
    cclua::plugin::talkingdata::onRegister(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_onSearch(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::ValueMap arg1;       /** data */

    olua_check_cocos2d_ValueMap(L, 1, &arg1);

    // static void onSearch(cocos2d::ValueMap &data)
    cclua::plugin::talkingdata::onSearch(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_onShare(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** uid */
    std::string arg2;       /** content */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static void onShare(const std::string &uid, const std::string &content)
    cclua::plugin::talkingdata::onShare(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_removeGlobalKV(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** key */

    olua_check_std_string(L, 1, &arg1);

    // static void removeGlobalKV(const std::string &key)
    cclua::plugin::talkingdata::removeGlobalKV(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_setConfigurationDisable(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** options */

    olua_check_uint(L, 1, &arg1);

    // static void setConfigurationDisable(uint64_t options)
    cclua::plugin::talkingdata::setConfigurationDisable((uint64_t)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_setExceptionReportEnabled(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** value */

    olua_check_bool(L, 1, &arg1);

    // static void setExceptionReportEnabled(bool value)
    cclua::plugin::talkingdata::setExceptionReportEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_setGlobalKV(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** key */
    cocos2d::Value arg2;       /** value */

    olua_check_std_string(L, 1, &arg1);
    olua_check_cocos2d_Value(L, 2, &arg2);

    // static void setGlobalKV(const std::string &key, cocos2d::Value &value)
    cclua::plugin::talkingdata::setGlobalKV(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_setLocation(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** latitude */
    lua_Number arg2 = 0;       /** longitude */

    olua_check_number(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static void setLocation(double latitude, double longitude)
    cclua::plugin::talkingdata::setLocation((double)arg1, (double)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_setSignalReportEnabled(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** value */

    olua_check_bool(L, 1, &arg1);

    // static void setSignalReportEnabled(bool value)
    cclua::plugin::talkingdata::setSignalReportEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_setVendorId(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** vendorId */
    lua_Integer arg2 = 0;       /** type */

    olua_check_std_string(L, 1, &arg1);
    olua_check_int(L, 2, &arg2);

    // static void setVendorId(const std::string &vendorId, int type)
    cclua::plugin::talkingdata::setVendorId(arg1, (int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_setVerboseLogDisable(lua_State *L)
{
    olua_startinvoke(L);

    // static void setVerboseLogDisable()
    cclua::plugin::talkingdata::setVerboseLogDisable();

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_plugin_talkingdata(lua_State *L)
{
    oluacls_class(L, "cclua.plugin.talkingdata", nullptr);
    oluacls_func(L, "__olua_move", _cclua_plugin_talkingdata___olua_move);
    oluacls_func(L, "backgroundSessionEnabled", _cclua_plugin_talkingdata_backgroundSessionEnabled);
    oluacls_func(L, "getDeviceId", _cclua_plugin_talkingdata_getDeviceId);
    oluacls_func(L, "init", _cclua_plugin_talkingdata_init);
    oluacls_func(L, "onCreateCard", _cclua_plugin_talkingdata_onCreateCard);
    oluacls_func(L, "onEvent", _cclua_plugin_talkingdata_onEvent);
    oluacls_func(L, "onFavorite", _cclua_plugin_talkingdata_onFavorite);
    oluacls_func(L, "onLogin", _cclua_plugin_talkingdata_onLogin);
    oluacls_func(L, "onPageBegin", _cclua_plugin_talkingdata_onPageBegin);
    oluacls_func(L, "onPageEnd", _cclua_plugin_talkingdata_onPageEnd);
    oluacls_func(L, "onProfileUpdate", _cclua_plugin_talkingdata_onProfileUpdate);
    oluacls_func(L, "onPunch", _cclua_plugin_talkingdata_onPunch);
    oluacls_func(L, "onReceiveDeepLink", _cclua_plugin_talkingdata_onReceiveDeepLink);
    oluacls_func(L, "onRegister", _cclua_plugin_talkingdata_onRegister);
    oluacls_func(L, "onSearch", _cclua_plugin_talkingdata_onSearch);
    oluacls_func(L, "onShare", _cclua_plugin_talkingdata_onShare);
    oluacls_func(L, "removeGlobalKV", _cclua_plugin_talkingdata_removeGlobalKV);
    oluacls_func(L, "setConfigurationDisable", _cclua_plugin_talkingdata_setConfigurationDisable);
    oluacls_func(L, "setExceptionReportEnabled", _cclua_plugin_talkingdata_setExceptionReportEnabled);
    oluacls_func(L, "setGlobalKV", _cclua_plugin_talkingdata_setGlobalKV);
    oluacls_func(L, "setLocation", _cclua_plugin_talkingdata_setLocation);
    oluacls_func(L, "setSignalReportEnabled", _cclua_plugin_talkingdata_setSignalReportEnabled);
    oluacls_func(L, "setVendorId", _cclua_plugin_talkingdata_setVendorId);
    oluacls_func(L, "setVerboseLogDisable", _cclua_plugin_talkingdata_setVerboseLogDisable);
    oluacls_prop(L, "deviceId", _cclua_plugin_talkingdata_getDeviceId, nullptr);

    olua_registerluatype<cclua::plugin::talkingdata>(L, "cclua.plugin.talkingdata");
    cclua::runtime::registerFeature("cclua.plugin.talkingdata.ios", true);

    return 1;
}
OLUA_END_DECLS
#endif

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_talkingdata(lua_State *L)
{
#ifdef CCLUA_BUILD_TALKINGDATA
    olua_require(L, "cclua.plugin.talkingdata", luaopen_cclua_plugin_talkingdata);
#endif

    return 0;
}
OLUA_END_DECLS
