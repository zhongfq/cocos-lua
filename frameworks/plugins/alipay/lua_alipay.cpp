//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_alipay.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "alipay/alipay.h"

#ifdef CCLUA_BUILD_ALIPAY
static int _cclua_plugin_alipay___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::plugin::alipay *)olua_toobj(L, 1, "cclua.plugin.alipay");
    olua_push_cppobj(L, self, "cclua.plugin.alipay");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_plugin_alipay_dispatch(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** event */
    cocos2d::ValueMap arg2;       /** data */

    olua_check_std_string(L, 1, &arg1);
    olua_check_cocos2d_ValueMap(L, 2, &arg2);

    // static void dispatch(const std::string &event, const cocos2d::ValueMap &data)
    cclua::plugin::alipay::dispatch(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_alipay_pay(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** order */

    olua_check_std_string(L, 1, &arg1);

    // static void pay(const std::string &order)
    cclua::plugin::alipay::pay(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_alipay_setDispatcher(lua_State *L)
{
    olua_startinvoke(L);

    cclua::Callback arg1;       /** dispatcher */

    olua_check_callback(L, 1, &arg1, "cclua.Callback");

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.plugin.alipay");
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

    // static void setDispatcher(@localvar const cclua::Callback &dispatcher)
    cclua::plugin::alipay::setDispatcher(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_plugin_alipay(lua_State *L)
{
    oluacls_class(L, "cclua.plugin.alipay", nullptr);
    oluacls_func(L, "__olua_move", _cclua_plugin_alipay___olua_move);
    oluacls_func(L, "dispatch", _cclua_plugin_alipay_dispatch);
    oluacls_func(L, "pay", _cclua_plugin_alipay_pay);
    oluacls_func(L, "setDispatcher", _cclua_plugin_alipay_setDispatcher);

    olua_registerluatype<cclua::plugin::alipay>(L, "cclua.plugin.alipay");

    return 1;
}
OLUA_END_DECLS
#endif

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_alipay(lua_State *L)
{
#ifdef CCLUA_BUILD_ALIPAY
    olua_require(L, "cclua.plugin.alipay", luaopen_cclua_plugin_alipay);
#endif

    return 0;
}
OLUA_END_DECLS
