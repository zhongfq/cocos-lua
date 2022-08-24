//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_wechat.h"

#ifdef CCLUA_BUILD_WECHAT
OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_plugin_wechat_ShareType(lua_State *L)
{
    oluacls_class(L, "cclua.plugin.wechat.ShareType", nullptr);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_const_integer(L, "IMAGE", (lua_Integer)cclua::plugin::wechat::ShareType::IMAGE);
    oluacls_const_integer(L, "MUSIC", (lua_Integer)cclua::plugin::wechat::ShareType::MUSIC);
    oluacls_const_integer(L, "NONE", (lua_Integer)cclua::plugin::wechat::ShareType::NONE);
    oluacls_const_integer(L, "TEXT", (lua_Integer)cclua::plugin::wechat::ShareType::TEXT);
    oluacls_const_integer(L, "VIDEO", (lua_Integer)cclua::plugin::wechat::ShareType::VIDEO);
    oluacls_const_integer(L, "WEB", (lua_Integer)cclua::plugin::wechat::ShareType::WEB);

    olua_registerluatype<cclua::plugin::wechat::ShareType>(L, "cclua.plugin.wechat.ShareType");

    return 1;
}
OLUA_END_DECLS
#endif

#ifdef CCLUA_BUILD_WECHAT
OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_plugin_wechat_ProgramType(lua_State *L)
{
    oluacls_class(L, "cclua.plugin.wechat.ProgramType", nullptr);
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_const_integer(L, "PREVIEW", (lua_Integer)cclua::plugin::wechat::ProgramType::PREVIEW);
    oluacls_const_integer(L, "RELEASE", (lua_Integer)cclua::plugin::wechat::ProgramType::RELEASE);
    oluacls_const_integer(L, "TEST", (lua_Integer)cclua::plugin::wechat::ProgramType::TEST);

    olua_registerluatype<cclua::plugin::wechat::ProgramType>(L, "cclua.plugin.wechat.ProgramType");

    return 1;
}
OLUA_END_DECLS
#endif

#ifdef CCLUA_BUILD_WECHAT
static int _cclua_plugin_wechat___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::plugin::wechat *)olua_toobj(L, 1, "cclua.plugin.wechat");
    olua_push_cppobj(L, self, "cclua.plugin.wechat");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_plugin_wechat_auth(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** scope */
    std::string arg2;       /** state */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static void auth(const std::string &scope, const std::string &state)
    cclua::plugin::wechat::auth(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_wechat_authQRCode(lua_State *L)
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
    cclua::plugin::wechat::authQRCode(arg1, arg2, arg3, arg4, arg5);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_wechat_dispatch(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** event */
    cocos2d::ValueMap arg2;       /** data */

    olua_check_std_string(L, 1, &arg1);
    olua_check_cocos2d_ValueMap(L, 2, &arg2);

    // static void dispatch(const std::string &event, const cocos2d::ValueMap &data)
    cclua::plugin::wechat::dispatch(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_wechat_init(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** appid */
    std::string arg2;       /** universalLink */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static void init(const std::string &appid, const std::string &universalLink)
    cclua::plugin::wechat::init(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_wechat_isInstalled(lua_State *L)
{
    olua_startinvoke(L);

    // static bool isInstalled()
    bool ret = cclua::plugin::wechat::isInstalled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_plugin_wechat_open1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** username */
    std::string arg2;       /** path */
    lua_Unsigned arg3 = 0;       /** type */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);

    // static void open(const std::string &username, @optional const std::string &path, @optional cclua::plugin::wechat::ProgramType type)
    cclua::plugin::wechat::open(arg1, arg2, (cclua::plugin::wechat::ProgramType)arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_wechat_open2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** username */

    olua_check_std_string(L, 1, &arg1);

    // static void open(const std::string &username, @optional const std::string &path, @optional cclua::plugin::wechat::ProgramType type)
    cclua::plugin::wechat::open(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_wechat_open3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** username */
    std::string arg2;       /** path */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static void open(const std::string &username, @optional const std::string &path, @optional cclua::plugin::wechat::ProgramType type)
    cclua::plugin::wechat::open(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_wechat_open(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static void open(const std::string &username, @optional const std::string &path, @optional cclua::plugin::wechat::ProgramType type)
            return _cclua_plugin_wechat_open2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2))) {
            // static void open(const std::string &username, @optional const std::string &path, @optional cclua::plugin::wechat::ProgramType type)
            return _cclua_plugin_wechat_open3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_string(L, 2)) && (olua_is_uint(L, 3))) {
            // static void open(const std::string &username, @optional const std::string &path, @optional cclua::plugin::wechat::ProgramType type)
            return _cclua_plugin_wechat_open1(L);
        // }
    }

    luaL_error(L, "method 'cclua::plugin::wechat::open' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_plugin_wechat_openCustomerService(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** corpid */
    std::string arg2;       /** url */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static void openCustomerService(const std::string &corpid, const std::string &url)
    cclua::plugin::wechat::openCustomerService(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

#ifdef CCLUA_OS_ANDROID
static int _cclua_plugin_wechat_pay(lua_State *L)
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
    cclua::plugin::wechat::pay(arg1, arg2, arg3, arg4, arg5, arg6);

    olua_endinvoke(L);

    return 0;
}
#endif

static int _cclua_plugin_wechat_setDispatcher(lua_State *L)
{
    olua_startinvoke(L);

    cclua::Callback arg1;       /** dispatcher */

    olua_check_callback(L, 1, &arg1, "cclua.Callback");

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.plugin.wechat");
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
    cclua::plugin::wechat::setDispatcher(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_wechat_share(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** type */
    cocos2d::ValueMap arg2;       /** value */

    olua_check_uint(L, 1, &arg1);
    olua_check_cocos2d_ValueMap(L, 2, &arg2);

    // static void share(cclua::plugin::wechat::ShareType type, cocos2d::ValueMap &value)
    cclua::plugin::wechat::share((cclua::plugin::wechat::ShareType)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_wechat_stopAuth(lua_State *L)
{
    olua_startinvoke(L);

    std::string cb_tag = "authQRCode";
    void *cb_store = (void *)olua_pushclassobj(L, "cclua.plugin.wechat");
    olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);

    // static void stopAuth()
    cclua::plugin::wechat::stopAuth();

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_plugin_wechat(lua_State *L)
{
    oluacls_class(L, "cclua.plugin.wechat", nullptr);
    oluacls_func(L, "__olua_move", _cclua_plugin_wechat___olua_move);
    oluacls_func(L, "auth", _cclua_plugin_wechat_auth);
    oluacls_func(L, "authQRCode", _cclua_plugin_wechat_authQRCode);
    oluacls_func(L, "dispatch", _cclua_plugin_wechat_dispatch);
    oluacls_func(L, "init", _cclua_plugin_wechat_init);
    oluacls_func(L, "isInstalled", _cclua_plugin_wechat_isInstalled);
    oluacls_func(L, "open", _cclua_plugin_wechat_open);
    oluacls_func(L, "openCustomerService", _cclua_plugin_wechat_openCustomerService);
#ifdef CCLUA_OS_ANDROID
    oluacls_func(L, "pay", _cclua_plugin_wechat_pay);
#endif
    oluacls_func(L, "setDispatcher", _cclua_plugin_wechat_setDispatcher);
    oluacls_func(L, "share", _cclua_plugin_wechat_share);
    oluacls_func(L, "stopAuth", _cclua_plugin_wechat_stopAuth);
    oluacls_prop(L, "installed", _cclua_plugin_wechat_isInstalled, nullptr);

    olua_registerluatype<cclua::plugin::wechat>(L, "cclua.plugin.wechat");
    cclua::runtime::registerFeature("cclua.plugin.wechat.ios", true);

    return 1;
}
OLUA_END_DECLS
#endif

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_wechat(lua_State *L)
{
#ifdef CCLUA_BUILD_WECHAT
    olua_require(L, "cclua.plugin.wechat.ShareType", luaopen_cclua_plugin_wechat_ShareType);
#endif
#ifdef CCLUA_BUILD_WECHAT
    olua_require(L, "cclua.plugin.wechat.ProgramType", luaopen_cclua_plugin_wechat_ProgramType);
#endif
#ifdef CCLUA_BUILD_WECHAT
    olua_require(L, "cclua.plugin.wechat", luaopen_cclua_plugin_wechat);
#endif

    return 0;
}
OLUA_END_DECLS
