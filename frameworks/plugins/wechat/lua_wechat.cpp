//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_wechat.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "cclua/xlua.h"
#include "WeChat.h"

#ifdef CCLUA_BUILD_WECHAT
static int luaopen_cclua_plugin_WeChat_ShareType(lua_State *L)
{
    oluacls_class(L, "cclua.plugin.WeChat.ShareType", nullptr);
    oluacls_const_integer(L, "IMAGE", (lua_Integer)cclua::plugin::WeChat::ShareType::IMAGE);
    oluacls_const_integer(L, "MUSIC", (lua_Integer)cclua::plugin::WeChat::ShareType::MUSIC);
    oluacls_const_integer(L, "NONE", (lua_Integer)cclua::plugin::WeChat::ShareType::NONE);
    oluacls_const_integer(L, "TEXT", (lua_Integer)cclua::plugin::WeChat::ShareType::TEXT);
    oluacls_const_integer(L, "VIDEO", (lua_Integer)cclua::plugin::WeChat::ShareType::VIDEO);
    oluacls_const_integer(L, "WEB", (lua_Integer)cclua::plugin::WeChat::ShareType::WEB);

    olua_registerluatype<cclua::plugin::WeChat::ShareType>(L, "cclua.plugin.WeChat.ShareType");

    return 1;
}
#endif

#ifdef CCLUA_BUILD_WECHAT
static int luaopen_cclua_plugin_WeChat_ProgramType(lua_State *L)
{
    oluacls_class(L, "cclua.plugin.WeChat.ProgramType", nullptr);
    oluacls_const_integer(L, "PREVIEW", (lua_Integer)cclua::plugin::WeChat::ProgramType::PREVIEW);
    oluacls_const_integer(L, "RELEASE", (lua_Integer)cclua::plugin::WeChat::ProgramType::RELEASE);
    oluacls_const_integer(L, "TEST", (lua_Integer)cclua::plugin::WeChat::ProgramType::TEST);

    olua_registerluatype<cclua::plugin::WeChat::ProgramType>(L, "cclua.plugin.WeChat.ProgramType");

    return 1;
}
#endif

#ifdef CCLUA_BUILD_WECHAT
static int _cclua_plugin_WeChat___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::plugin::WeChat *)olua_toobj(L, 1, "cclua.plugin.WeChat");
    olua_push_cppobj(L, self, "cclua.plugin.WeChat");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_plugin_WeChat_auth(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** scope */
    std::string arg2;       /** state */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static void auth(const std::string &scope, const std::string &state)
    cclua::plugin::WeChat::auth(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_WeChat_authQRCode(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** appid */
    std::string arg2;       /** nonceStr */
    std::string arg3;       /** timestamp */
    std::string arg4;       /** scope */
    std::string arg5;       /** signature */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);
    olua_check_std_string(L, 4, &arg4);
    olua_check_std_string(L, 5, &arg5);

    // static void authQRCode(const std::string &appid, const std::string &nonceStr, const std::string &timestamp, const std::string &scope, const std::string &signature)
    cclua::plugin::WeChat::authQRCode(arg1, arg2, arg3, arg4, arg5);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_WeChat_init(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** appid */
    std::string arg2;       /** universalLink */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static void init(const std::string &appid, const std::string &universalLink)
    cclua::plugin::WeChat::init(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_WeChat_isInstalled(lua_State *L)
{
    olua_startinvoke(L);

    // static bool isInstalled()
    bool ret = cclua::plugin::WeChat::isInstalled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_plugin_WeChat_open1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** username */
    std::string arg2;       /** path */
    lua_Unsigned arg3 = 0;       /** type */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);

    // static void open(const std::string &username, @optional const std::string path, @optional cclua::plugin::WeChat::ProgramType type)
    cclua::plugin::WeChat::open(arg1, arg2, (cclua::plugin::WeChat::ProgramType)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_WeChat_open2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** username */

    olua_check_std_string(L, 1, &arg1);

    // static void open(const std::string &username, @optional const std::string path, @optional cclua::plugin::WeChat::ProgramType type)
    cclua::plugin::WeChat::open(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_WeChat_open3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** username */
    std::string arg2;       /** path */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static void open(const std::string &username, @optional const std::string path, @optional cclua::plugin::WeChat::ProgramType type)
    cclua::plugin::WeChat::open(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_WeChat_open(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static void open(const std::string &username, @optional const std::string path, @optional cclua::plugin::WeChat::ProgramType type)
            return _cclua_plugin_WeChat_open2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2))) {
            // static void open(const std::string &username, @optional const std::string path, @optional cclua::plugin::WeChat::ProgramType type)
            return _cclua_plugin_WeChat_open3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // static void open(const std::string &username, @optional const std::string path, @optional cclua::plugin::WeChat::ProgramType type)
            return _cclua_plugin_WeChat_open1(L);
        // }
    }

    luaL_error(L, "method 'cclua::plugin::WeChat::open' not support '%d' arguments", num_args);

    return 0;
}

#ifdef CCLUA_OS_ANDROID
static int _cclua_plugin_WeChat_pay(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** partnerId */
    std::string arg2;       /** prepayId */
    std::string arg3;       /** noncestr */
    std::string arg4;       /** timestamp */
    std::string arg5;       /** packageValue */
    std::string arg6;       /** sign */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);
    olua_check_std_string(L, 4, &arg4);
    olua_check_std_string(L, 5, &arg5);
    olua_check_std_string(L, 6, &arg6);

    // static void pay(const std::string &partnerId, const std::string &prepayId, const std::string &noncestr, const std::string &timestamp, const std::string &packageValue, const std::string &sign)
    cclua::plugin::WeChat::pay(arg1, arg2, arg3, arg4, arg5, arg6);

    olua_endinvoke(L);

    return 0;
}
#endif

static int _cclua_plugin_WeChat_setDispatcher(lua_State *L)
{
    olua_startinvoke(L);

    std::function<void(const std::string &, const cocos2d::ValueMap &)> arg1;       /** dispatcher */

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.plugin.WeChat");
    std::string cb_tag = "Dispatcher";
    std::string cb_name = olua_setcallback(L, cb_store, cb_tag.c_str(), 1, OLUA_TAG_REPLACE);
    lua_Integer cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](const std::string &arg1, const cocos2d::ValueMap &arg2) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (L != NULL && olua_context(L) == cb_ctx) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_std_string(L, arg1);
            manual_olua_push_cocos2d_ValueMap(L, &arg2);
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 2);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // static void setDispatcher(@local const std::function<void (const std::string &, const cocos2d::ValueMap &)> &dispatcher)
    cclua::plugin::WeChat::setDispatcher(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_WeChat_share(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** type */
    cocos2d::ValueMap arg2;       /** value */

    olua_check_uint(L, 1, &arg1);
    manual_olua_check_cocos2d_ValueMap(L, 2, &arg2);

    // static void share(cclua::plugin::WeChat::ShareType type, cocos2d::ValueMap &value)
    cclua::plugin::WeChat::share((cclua::plugin::WeChat::ShareType)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_WeChat_stopAuth(lua_State *L)
{
    olua_startinvoke(L);

    // static void stopAuth()
    cclua::plugin::WeChat::stopAuth();

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cclua_plugin_WeChat(lua_State *L)
{
    oluacls_class(L, "cclua.plugin.WeChat", nullptr);
    oluacls_func(L, "__move", _cclua_plugin_WeChat___move);
    oluacls_func(L, "auth", _cclua_plugin_WeChat_auth);
    oluacls_func(L, "authQRCode", _cclua_plugin_WeChat_authQRCode);
    oluacls_func(L, "init", _cclua_plugin_WeChat_init);
    oluacls_func(L, "isInstalled", _cclua_plugin_WeChat_isInstalled);
    oluacls_func(L, "open", _cclua_plugin_WeChat_open);
#ifdef CCLUA_OS_ANDROID
    oluacls_func(L, "pay", _cclua_plugin_WeChat_pay);
#endif
    oluacls_func(L, "setDispatcher", _cclua_plugin_WeChat_setDispatcher);
    oluacls_func(L, "share", _cclua_plugin_WeChat_share);
    oluacls_func(L, "stopAuth", _cclua_plugin_WeChat_stopAuth);
    oluacls_prop(L, "installed", _cclua_plugin_WeChat_isInstalled, nullptr);

    olua_registerluatype<cclua::plugin::WeChat>(L, "cclua.plugin.WeChat");
    cclua::runtime::registerFeature("wechat", true);

    return 1;
}
#endif

int luaopen_wechat(lua_State *L)
{
#ifdef CCLUA_BUILD_WECHAT
    olua_require(L, "cclua.plugin.WeChat.ShareType", luaopen_cclua_plugin_WeChat_ShareType);
#endif
#ifdef CCLUA_BUILD_WECHAT
    olua_require(L, "cclua.plugin.WeChat.ProgramType", luaopen_cclua_plugin_WeChat_ProgramType);
#endif
#ifdef CCLUA_BUILD_WECHAT
    olua_require(L, "cclua.plugin.WeChat", luaopen_cclua_plugin_WeChat);
#endif
    return 0;
}
