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
    std::string cb_name = olua_setcallback(L, cb_store, cb_tag.c_str(), 1, OLUA_TAG_REPLACE);
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

int luaopen_apple(lua_State *L)
{
#ifdef CCLUA_BUILD_APPLE_AUTH
    olua_require(L, "cclua.plugin.AppleAuth", luaopen_cclua_plugin_AppleAuth);
#endif
    return 0;
}
