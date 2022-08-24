//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_talkingdata.h"

#ifdef CCLUA_BUILD_TALKINGDATA
static int _cclua_plugin_talkingdata___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::plugin::talkingdata *)olua_toobj(L, 1, "cclua.plugin.talkingdata");
    olua_push_cppobj(L, self, "cclua.plugin.talkingdata");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_plugin_talkingdata_cancelOrder(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** orderId */
    lua_Integer arg2 = 0;       /** amount */
    std::string arg3;       /** currencyType */

    olua_check_std_string(L, 1, &arg1);
    olua_check_int(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);

    // static void cancelOrder(const std::string &orderId, int amount, const std::string &currencyType)
    cclua::plugin::talkingdata::cancelOrder(arg1, (int)arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_init(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** appkey */
    std::string arg2;       /** channel */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static void init(const std::string &appkey, const std::string &channel)
    cclua::plugin::talkingdata::init(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_onLogin(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** uid */
    lua_Integer arg2 = 0;       /** type */
    std::string arg3;       /** name */

    olua_check_std_string(L, 1, &arg1);
    olua_check_int(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);

    // static void onLogin(const std::string &uid, int type, const std::string &name)
    cclua::plugin::talkingdata::onLogin(arg1, (int)arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_onRegister(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** uid */
    lua_Integer arg2 = 0;       /** type */
    std::string arg3;       /** name */

    olua_check_std_string(L, 1, &arg1);
    olua_check_int(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);

    // static void onRegister(const std::string &uid, int type, const std::string &name)
    cclua::plugin::talkingdata::onRegister(arg1, (int)arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_payOrder(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** orderId */
    lua_Integer arg2 = 0;       /** amount */
    std::string arg3;       /** currencyType */
    std::string arg4;       /** paymentType */

    olua_check_std_string(L, 1, &arg1);
    olua_check_int(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);
    olua_check_std_string(L, 4, &arg4);

    // static void payOrder(const std::string &orderId, int amount, const std::string &currencyType, const std::string &paymentType)
    cclua::plugin::talkingdata::payOrder(arg1, (int)arg2, arg3, arg4);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_placeOrder(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** orderId */
    lua_Integer arg2 = 0;       /** amount */
    std::string arg3;       /** currencyType */

    olua_check_std_string(L, 1, &arg1);
    olua_check_int(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);

    // static void placeOrder(const std::string &orderId, int amount, const std::string &currencyType)
    cclua::plugin::talkingdata::placeOrder(arg1, (int)arg2, arg3);

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

static int _cclua_plugin_talkingdata_setGlobalKV1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** key */
    bool arg2 = false;       /** value */

    olua_check_std_string(L, 1, &arg1);
    olua_check_bool(L, 2, &arg2);

    // static void setGlobalKV(const std::string &key, bool value)
    cclua::plugin::talkingdata::setGlobalKV(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_setGlobalKV2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** key */
    std::string arg2;       /** value */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static void setGlobalKV(const std::string &key, const std::string &value)
    cclua::plugin::talkingdata::setGlobalKV(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_setGlobalKV3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** key */
    lua_Integer arg2 = 0;       /** value */

    olua_check_std_string(L, 1, &arg1);
    olua_check_int(L, 2, &arg2);

    // static void setGlobalKV(const std::string &key, long value)
    cclua::plugin::talkingdata::setGlobalKV(arg1, (long)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_setGlobalKV4(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** key */
    lua_Number arg2 = 0;       /** value */

    olua_check_std_string(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static void setGlobalKV(const std::string &key, double value)
    cclua::plugin::talkingdata::setGlobalKV(arg1, (double)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_setGlobalKV(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        if ((olua_is_std_string(L, 1)) && (olua_is_bool(L, 2))) {
            // static void setGlobalKV(const std::string &key, bool value)
            return _cclua_plugin_talkingdata_setGlobalKV1(L);
        }

        if ((olua_is_std_string(L, 1)) && (olua_is_int(L, 2))) {
            // static void setGlobalKV(const std::string &key, long value)
            return _cclua_plugin_talkingdata_setGlobalKV3(L);
        }

        if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2))) {
            // static void setGlobalKV(const std::string &key, const std::string &value)
            return _cclua_plugin_talkingdata_setGlobalKV2(L);
        }

        // if ((olua_is_std_string(L, 1)) && (olua_is_number(L, 2))) {
            // static void setGlobalKV(const std::string &key, double value)
            return _cclua_plugin_talkingdata_setGlobalKV4(L);
        // }
    }

    luaL_error(L, "method 'cclua::plugin::talkingdata::setGlobalKV' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_plugin_talkingdata_setLogEnabled(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** value */

    olua_check_bool(L, 1, &arg1);

    // static void setLogEnabled(bool value)
    cclua::plugin::talkingdata::setLogEnabled(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_setReportUncaughtExceptions(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** value */

    olua_check_bool(L, 1, &arg1);

    // static void setReportUncaughtExceptions(bool value)
    cclua::plugin::talkingdata::setReportUncaughtExceptions(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_trackEvent1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** event */

    olua_check_std_string(L, 1, &arg1);

    // static void trackEvent(const std::string &event)
    cclua::plugin::talkingdata::trackEvent(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_trackEvent2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** event */
    std::string arg2;       /** label */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static void trackEvent(const std::string &event, const std::string &label)
    cclua::plugin::talkingdata::trackEvent(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_trackEvent3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** event */
    std::string arg2;       /** label */
    cocos2d::ValueMap arg3;       /** map */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_cocos2d_ValueMap(L, 3, &arg3);

    // static void trackEvent(const std::string &event, const std::string &label, const cocos2d::ValueMap &map)
    cclua::plugin::talkingdata::trackEvent(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_trackEvent4(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** event */
    std::string arg2;       /** label */
    cocos2d::ValueMap arg3;       /** map */
    lua_Number arg4 = 0;       /** value */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_cocos2d_ValueMap(L, 3, &arg3);
    olua_check_number(L, 4, &arg4);

    // static void trackEvent(const std::string &event, const std::string &label, const cocos2d::ValueMap &map, double value)
    cclua::plugin::talkingdata::trackEvent(arg1, arg2, arg3, (double)arg4);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_trackEvent(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static void trackEvent(const std::string &event)
            return _cclua_plugin_talkingdata_trackEvent1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2))) {
            // static void trackEvent(const std::string &event, const std::string &label)
            return _cclua_plugin_talkingdata_trackEvent2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_cocos2d_ValueMap(L, 3))) {
            // static void trackEvent(const std::string &event, const std::string &label, const cocos2d::ValueMap &map)
            return _cclua_plugin_talkingdata_trackEvent3(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_cocos2d_ValueMap(L, 3)) && (olua_is_number(L, 4))) {
            // static void trackEvent(const std::string &event, const std::string &label, const cocos2d::ValueMap &map, double value)
            return _cclua_plugin_talkingdata_trackEvent4(L);
        // }
    }

    luaL_error(L, "method 'cclua::plugin::talkingdata::trackEvent' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_plugin_talkingdata_trackPageBegin(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** name */

    olua_check_std_string(L, 1, &arg1);

    // static void trackPageBegin(const std::string &name)
    cclua::plugin::talkingdata::trackPageBegin(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_trackPageEnd(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** name */

    olua_check_std_string(L, 1, &arg1);

    // static void trackPageEnd(const std::string &name)
    cclua::plugin::talkingdata::trackPageEnd(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_talkingdata_viewItem(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** itemId */
    std::string arg2;       /** category */
    std::string arg3;       /** name */
    lua_Integer arg4 = 0;       /** unitPrice */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);
    olua_check_int(L, 4, &arg4);

    // static void viewItem(const std::string &itemId, const std::string &category, const std::string &name, int unitPrice)
    cclua::plugin::talkingdata::viewItem(arg1, arg2, arg3, (int)arg4);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_plugin_talkingdata(lua_State *L)
{
    oluacls_class(L, "cclua.plugin.talkingdata", nullptr);
    oluacls_func(L, "__olua_move", _cclua_plugin_talkingdata___olua_move);
    oluacls_func(L, "cancelOrder", _cclua_plugin_talkingdata_cancelOrder);
    oluacls_func(L, "init", _cclua_plugin_talkingdata_init);
    oluacls_func(L, "onLogin", _cclua_plugin_talkingdata_onLogin);
    oluacls_func(L, "onRegister", _cclua_plugin_talkingdata_onRegister);
    oluacls_func(L, "payOrder", _cclua_plugin_talkingdata_payOrder);
    oluacls_func(L, "placeOrder", _cclua_plugin_talkingdata_placeOrder);
    oluacls_func(L, "removeGlobalKV", _cclua_plugin_talkingdata_removeGlobalKV);
    oluacls_func(L, "setGlobalKV", _cclua_plugin_talkingdata_setGlobalKV);
    oluacls_func(L, "setLogEnabled", _cclua_plugin_talkingdata_setLogEnabled);
    oluacls_func(L, "setReportUncaughtExceptions", _cclua_plugin_talkingdata_setReportUncaughtExceptions);
    oluacls_func(L, "trackEvent", _cclua_plugin_talkingdata_trackEvent);
    oluacls_func(L, "trackPageBegin", _cclua_plugin_talkingdata_trackPageBegin);
    oluacls_func(L, "trackPageEnd", _cclua_plugin_talkingdata_trackPageEnd);
    oluacls_func(L, "viewItem", _cclua_plugin_talkingdata_viewItem);

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
