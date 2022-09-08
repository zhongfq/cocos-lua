//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_apple.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "apple/apple.h"

#ifdef CCLUA_OS_IOS
static int _cclua_plugin_apple___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::plugin::apple *)olua_toobj(L, 1, "cclua.plugin.apple");
    olua_push_cppobj(L, self, "cclua.plugin.apple");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_plugin_apple_auth(lua_State *L)
{
    olua_startinvoke(L);

    // static void auth()
    cclua::plugin::apple::auth();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_apple_canMakeAuth(lua_State *L)
{
    olua_startinvoke(L);

    // static bool canMakeAuth()
    bool ret = cclua::plugin::apple::canMakeAuth();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_plugin_apple_canMakePayments(lua_State *L)
{
    olua_startinvoke(L);

    // static bool canMakePayments()
    bool ret = cclua::plugin::apple::canMakePayments();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_plugin_apple_dispatch(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** event */
    cocos2d::ValueMap arg2;       /** data */

    olua_check_std_string(L, 1, &arg1);
    olua_check_cocos2d_ValueMap(L, 2, &arg2);

    // static void dispatch(const std::string &event, const cocos2d::ValueMap &data)
    cclua::plugin::apple::dispatch(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_apple_finishTransaction(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** tid */

    olua_check_std_string(L, 1, &arg1);

    // static void finishTransaction(const std::string &tid)
    cclua::plugin::apple::finishTransaction(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_apple_getPendingTransactions(lua_State *L)
{
    olua_startinvoke(L);

    // static cocos2d::ValueVector getPendingTransactions()
    cocos2d::ValueVector ret = cclua::plugin::apple::getPendingTransactions();
    int num_ret = olua_push_cocos2d_ValueVector(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_plugin_apple_purchase1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** product */
    lua_Unsigned arg2 = 0;       /** quantify */

    olua_check_std_string(L, 1, &arg1);
    olua_check_uint(L, 2, &arg2);

    // static void purchase(const std::string &product, @optional uint32_t quantify)
    cclua::plugin::apple::purchase(arg1, (uint32_t)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_apple_purchase2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** product */

    olua_check_std_string(L, 1, &arg1);

    // static void purchase(const std::string &product, @optional uint32_t quantify)
    cclua::plugin::apple::purchase(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_apple_purchase(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static void purchase(const std::string &product, @optional uint32_t quantify)
            return _cclua_plugin_apple_purchase2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_uint(L, 2))) {
            // static void purchase(const std::string &product, @optional uint32_t quantify)
            return _cclua_plugin_apple_purchase1(L);
        // }
    }

    luaL_error(L, "method 'cclua::plugin::apple::purchase' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_plugin_apple_requestProducts(lua_State *L)
{
    olua_startinvoke(L);

    std::set<std::string> arg1;       /** products */

    olua_check_array<std::string>(L, 1, &arg1, [L](std::string *value) {
        olua_check_std_string(L, -1, value);
    });

    // static void requestProducts(const std::set<std::string> &products)
    cclua::plugin::apple::requestProducts(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_apple_restoreTransactions1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** appUsername */

    olua_check_std_string(L, 1, &arg1);

    // static void restoreTransactions(@optional const std::string &appUsername)
    cclua::plugin::apple::restoreTransactions(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_apple_restoreTransactions2(lua_State *L)
{
    olua_startinvoke(L);

    // static void restoreTransactions(@optional const std::string &appUsername)
    cclua::plugin::apple::restoreTransactions();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_apple_restoreTransactions(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 0) {
        // static void restoreTransactions(@optional const std::string &appUsername)
        return _cclua_plugin_apple_restoreTransactions2(L);
    }

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static void restoreTransactions(@optional const std::string &appUsername)
            return _cclua_plugin_apple_restoreTransactions1(L);
        // }
    }

    luaL_error(L, "method 'cclua::plugin::apple::restoreTransactions' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_plugin_apple_setDispatcher(lua_State *L)
{
    olua_startinvoke(L);

    cclua::Callback arg1;       /** dispatcher */

    olua_check_callback(L, 1, &arg1, "cclua.Callback");

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.plugin.apple");
    std::string cb_tag = "Dispatcher";
    std::string cb_name = olua_setcallback(L, cb_store,  1, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_context_t cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](const std::string &arg1, const cocos2d::Value &arg2) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
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

    // static void setDispatcher(@localvar const cclua::Callback &dispatcher)
    cclua::plugin::apple::setDispatcher(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_plugin_apple(lua_State *L)
{
    oluacls_class(L, "cclua.plugin.apple", nullptr);
    oluacls_func(L, "__olua_move", _cclua_plugin_apple___olua_move);
    oluacls_func(L, "auth", _cclua_plugin_apple_auth);
    oluacls_func(L, "canMakeAuth", _cclua_plugin_apple_canMakeAuth);
    oluacls_func(L, "canMakePayments", _cclua_plugin_apple_canMakePayments);
    oluacls_func(L, "dispatch", _cclua_plugin_apple_dispatch);
    oluacls_func(L, "finishTransaction", _cclua_plugin_apple_finishTransaction);
    oluacls_func(L, "getPendingTransactions", _cclua_plugin_apple_getPendingTransactions);
    oluacls_func(L, "purchase", _cclua_plugin_apple_purchase);
    oluacls_func(L, "requestProducts", _cclua_plugin_apple_requestProducts);
    oluacls_func(L, "restoreTransactions", _cclua_plugin_apple_restoreTransactions);
    oluacls_func(L, "setDispatcher", _cclua_plugin_apple_setDispatcher);
    oluacls_prop(L, "pendingTransactions", _cclua_plugin_apple_getPendingTransactions, nullptr);

    olua_registerluatype<cclua::plugin::apple>(L, "cclua.plugin.apple");
    cclua::runtime::registerFeature("cclua.plugin.apple.ios", true);

    return 1;
}
OLUA_END_DECLS
#endif

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_apple(lua_State *L)
{
#ifdef CCLUA_OS_IOS
    olua_require(L, "cclua.plugin.apple", luaopen_cclua_plugin_apple);
#endif

    return 0;
}
OLUA_END_DECLS
