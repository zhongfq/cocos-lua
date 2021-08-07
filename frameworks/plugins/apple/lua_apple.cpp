//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_apple.h"

#ifdef CCLUA_BUILD_APPLE_AUTH
static int _cclua_plugin_AppleAuth___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::plugin::AppleAuth *)olua_toobj(L, 1, "cclua.plugin.AppleAuth");
    olua_push_cppobj(L, self, "cclua.plugin.AppleAuth");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_plugin_AppleAuth_auth(lua_State *L)
{
    olua_startinvoke(L);

    std::function<void(const cocos2d::ValueMap &)> arg1;       /** callback */

    olua_check_std_function(L, 1, &arg1);

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.plugin.AppleAuth");
    std::string cb_tag = "auth";
    std::string cb_name = olua_setcallback(L, cb_store,  1, cb_tag.c_str(), OLUA_TAG_REPLACE);
    lua_Integer cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](const cocos2d::ValueMap &arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (L != NULL && olua_context(L) == cb_ctx) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_cocos2d_ValueMap(L, &arg1);
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // static void auth(@local const std::function<void (const cocos2d::ValueMap &)> &callback)
    cclua::plugin::AppleAuth::auth(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_AppleAuth_canMakeAuth(lua_State *L)
{
    olua_startinvoke(L);

    // static bool canMakeAuth()
    bool ret = cclua::plugin::AppleAuth::canMakeAuth();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cclua_plugin_AppleAuth(lua_State *L)
{
    oluacls_class(L, "cclua.plugin.AppleAuth", nullptr);
    oluacls_func(L, "__move", _cclua_plugin_AppleAuth___move);
    oluacls_func(L, "auth", _cclua_plugin_AppleAuth_auth);
    oluacls_func(L, "canMakeAuth", _cclua_plugin_AppleAuth_canMakeAuth);

    olua_registerluatype<cclua::plugin::AppleAuth>(L, "cclua.plugin.AppleAuth");
    cclua::runtime::registerFeature("apple.auth.ios", true);

    return 1;
}
#endif

#ifdef CCLUA_BUILD_APPLE_IAP
static int _cclua_plugin_AppleIAP___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::plugin::AppleIAP *)olua_toobj(L, 1, "cclua.plugin.AppleIAP");
    olua_push_cppobj(L, self, "cclua.plugin.AppleIAP");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_plugin_AppleIAP_canMakePayments(lua_State *L)
{
    olua_startinvoke(L);

    // static bool canMakePayments()
    bool ret = cclua::plugin::AppleIAP::canMakePayments();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_plugin_AppleIAP_dispatch(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** event */
    cocos2d::Value arg2;       /** data */

    olua_check_std_string(L, 1, &arg1);
    olua_check_cocos2d_Value(L, 2, &arg2);

    // static void dispatch(const std::string &event, const cocos2d::Value &data)
    cclua::plugin::AppleIAP::dispatch(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_AppleIAP_finishTransaction(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** tid */

    olua_check_std_string(L, 1, &arg1);

    // static void finishTransaction(const std::string &tid)
    cclua::plugin::AppleIAP::finishTransaction(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_AppleIAP_getPendingTransactions(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ValueVector getPendingTransactions()
    cocos2d::ValueVector ret = cclua::plugin::AppleIAP::getPendingTransactions();
    int num_ret = olua_push_cocos2d_ValueVector(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_plugin_AppleIAP_purchase1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** product */
    lua_Unsigned arg2 = 0;       /** quantify */

    olua_check_std_string(L, 1, &arg1);
    olua_check_uint(L, 2, &arg2);

    // static void purchase(const std::string &product, @optional uint32_t quantify)
    cclua::plugin::AppleIAP::purchase(arg1, (uint32_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_AppleIAP_purchase2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** product */

    olua_check_std_string(L, 1, &arg1);

    // static void purchase(const std::string &product, @optional uint32_t quantify)
    cclua::plugin::AppleIAP::purchase(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_AppleIAP_purchase(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static void purchase(const std::string &product, @optional uint32_t quantify)
            return _cclua_plugin_AppleIAP_purchase2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_uint(L, 2))) {
            // static void purchase(const std::string &product, @optional uint32_t quantify)
            return _cclua_plugin_AppleIAP_purchase1(L);
        // }
    }

    luaL_error(L, "method 'cclua::plugin::AppleIAP::purchase' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_plugin_AppleIAP_requestProducts(lua_State *L)
{
    olua_startinvoke(L);

    std::set<std::string> arg1;       /** products */

    olua_check_std_set<std::string>(L, 1, &arg1, [L](std::string *value) {
        olua_check_std_string(L, -1, value);
    });

    // static void requestProducts(const std::set<std::string> &products)
    cclua::plugin::AppleIAP::requestProducts(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_AppleIAP_restoreCompletedTransactions(lua_State *L)
{
    olua_startinvoke(L);

    // static void restoreCompletedTransactions()
    cclua::plugin::AppleIAP::restoreCompletedTransactions();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_AppleIAP_setDispatcher(lua_State *L)
{
    olua_startinvoke(L);

    std::function<void(const std::string &, const cocos2d::Value &)> arg1;       /** dispatcher */

    olua_check_std_function(L, 1, &arg1);

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.plugin.AppleIAP");
    std::string cb_tag = "Dispatcher";
    std::string cb_name = olua_setcallback(L, cb_store,  1, cb_tag.c_str(), OLUA_TAG_REPLACE);
    lua_Integer cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](const std::string &arg1, const cocos2d::Value &arg2) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (L != NULL && olua_context(L) == cb_ctx) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_std_string(L, arg1);
            olua_push_cocos2d_Value(L, &arg2);
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 2);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // static void setDispatcher(@local const std::function<void (const std::string &, const cocos2d::Value &)> &dispatcher)
    cclua::plugin::AppleIAP::setDispatcher(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cclua_plugin_AppleIAP(lua_State *L)
{
    oluacls_class(L, "cclua.plugin.AppleIAP", nullptr);
    oluacls_func(L, "__move", _cclua_plugin_AppleIAP___move);
    oluacls_func(L, "canMakePayments", _cclua_plugin_AppleIAP_canMakePayments);
    oluacls_func(L, "dispatch", _cclua_plugin_AppleIAP_dispatch);
    oluacls_func(L, "finishTransaction", _cclua_plugin_AppleIAP_finishTransaction);
    oluacls_func(L, "getPendingTransactions", _cclua_plugin_AppleIAP_getPendingTransactions);
    oluacls_func(L, "purchase", _cclua_plugin_AppleIAP_purchase);
    oluacls_func(L, "requestProducts", _cclua_plugin_AppleIAP_requestProducts);
    oluacls_func(L, "restoreCompletedTransactions", _cclua_plugin_AppleIAP_restoreCompletedTransactions);
    oluacls_func(L, "setDispatcher", _cclua_plugin_AppleIAP_setDispatcher);
    oluacls_prop(L, "pendingTransactions", _cclua_plugin_AppleIAP_getPendingTransactions, nullptr);

    olua_registerluatype<cclua::plugin::AppleIAP>(L, "cclua.plugin.AppleIAP");
    cclua::runtime::registerFeature("apple.iap.ios", true);

    return 1;
}
#endif

int luaopen_apple(lua_State *L)
{
#ifdef CCLUA_BUILD_APPLE_AUTH
    olua_require(L, "cclua.plugin.AppleAuth", luaopen_cclua_plugin_AppleAuth);
#endif
#ifdef CCLUA_BUILD_APPLE_IAP
    olua_require(L, "cclua.plugin.AppleIAP", luaopen_cclua_plugin_AppleIAP);
#endif
    return 0;
}
