//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_huawei.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "huawei/huawei.h"

#ifdef CCLUA_BUILD_HUAWEI
static int _cclua_plugin_huawei___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::plugin::huawei *)olua_toobj(L, 1, "cclua.plugin.huawei");
    olua_push_cppobj(L, self, "cclua.plugin.huawei");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_plugin_huawei_dispatch(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** event */
    cocos2d::ValueMap arg2;       /** data */

    olua_check_std_string(L, 1, &arg1);
    olua_check_cocos2d_ValueMap(L, 2, &arg2);

    // static void dispatch(const std::string &event, const cocos2d::ValueMap &data)
    cclua::plugin::huawei::dispatch(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_huawei_init(lua_State *L)
{
    olua_startinvoke(L);

    // static void init()
    cclua::plugin::huawei::init();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_huawei_login(lua_State *L)
{
    olua_startinvoke(L);

    // static void login()
    cclua::plugin::huawei::login();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_huawei_logout(lua_State *L)
{
    olua_startinvoke(L);

    // static void logout()
    cclua::plugin::huawei::logout();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_huawei_pay(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** appid */
    std::string arg2;       /** cpid */
    std::string arg3;       /** cp */
    std::string arg4;       /** orderNo */
    std::string arg5;       /** pid */
    std::string arg6;       /** url */
    std::string arg7;       /** serviceCatalog */
    std::string arg8;       /** extReserved */
    std::string arg9;       /** sign */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);
    olua_check_std_string(L, 4, &arg4);
    olua_check_std_string(L, 5, &arg5);
    olua_check_std_string(L, 6, &arg6);
    olua_check_std_string(L, 7, &arg7);
    olua_check_std_string(L, 8, &arg8);
    olua_check_std_string(L, 9, &arg9);

    // static void pay(const std::string &appid, const std::string &cpid, const std::string &cp, const std::string &orderNo, const std::string &pid, const std::string &url, const std::string &serviceCatalog, const std::string &extReserved, const std::string &sign)
    cclua::plugin::huawei::pay(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_huawei_revokeAccess(lua_State *L)
{
    olua_startinvoke(L);

    // static void revokeAccess()
    cclua::plugin::huawei::revokeAccess();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_huawei_setDispatcher(lua_State *L)
{
    olua_startinvoke(L);

    cclua::Callback arg1;       /** dispatcher */

    olua_check_callback(L, 1, &arg1, "cclua.Callback");

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.plugin.huawei");
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
    cclua::plugin::huawei::setDispatcher(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_plugin_huawei(lua_State *L)
{
    oluacls_class(L, "cclua.plugin.huawei", nullptr);
    oluacls_func(L, "__olua_move", _cclua_plugin_huawei___olua_move);
    oluacls_func(L, "dispatch", _cclua_plugin_huawei_dispatch);
    oluacls_func(L, "init", _cclua_plugin_huawei_init);
    oluacls_func(L, "login", _cclua_plugin_huawei_login);
    oluacls_func(L, "logout", _cclua_plugin_huawei_logout);
    oluacls_func(L, "pay", _cclua_plugin_huawei_pay);
    oluacls_func(L, "revokeAccess", _cclua_plugin_huawei_revokeAccess);
    oluacls_func(L, "setDispatcher", _cclua_plugin_huawei_setDispatcher);

    olua_registerluatype<cclua::plugin::huawei>(L, "cclua.plugin.huawei");

    return 1;
}
OLUA_END_DECLS
#endif

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_huawei(lua_State *L)
{
#ifdef CCLUA_BUILD_HUAWEI
    olua_require(L, "cclua.plugin.huawei", luaopen_cclua_plugin_huawei);
#endif

    return 0;
}
OLUA_END_DECLS
