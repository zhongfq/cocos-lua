//
// AUTO GENERATED, DO NOT MODIFY!
//
#include "lua_wechat.h"
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "wechat/wechat.h"

static int _olua_module_wechat(lua_State *L);

#ifdef CCLUA_BUILD_WECHAT
static int _olua_cls_cclua_plugin_wechat_ShareType(lua_State *L)
{
    oluacls_class<cclua::plugin::wechat::ShareType>(L, "cclua.plugin.wechat.ShareType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "IMAGE", (lua_Integer)cclua::plugin::wechat::ShareType::IMAGE);
    oluacls_enum(L, "MUSIC", (lua_Integer)cclua::plugin::wechat::ShareType::MUSIC);
    oluacls_enum(L, "NONE", (lua_Integer)cclua::plugin::wechat::ShareType::NONE);
    oluacls_enum(L, "TEXT", (lua_Integer)cclua::plugin::wechat::ShareType::TEXT);
    oluacls_enum(L, "VIDEO", (lua_Integer)cclua::plugin::wechat::ShareType::VIDEO);
    oluacls_enum(L, "WEB", (lua_Integer)cclua::plugin::wechat::ShareType::WEB);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_plugin_wechat_ShareType(lua_State *L)
{
    olua_require(L, "wechat",  _olua_module_wechat);
    if (!olua_getclass(L, "cclua.plugin.wechat.ShareType")) {
        luaL_error(L, "class not found: cclua::plugin::wechat::ShareType");
    }
    return 1;
}
OLUA_END_DECLS
#endif

#ifdef CCLUA_BUILD_WECHAT
static int _olua_cls_cclua_plugin_wechat_ProgramType(lua_State *L)
{
    oluacls_class<cclua::plugin::wechat::ProgramType>(L, "cclua.plugin.wechat.ProgramType");
    oluacls_func(L, "__index", olua_indexerror);
    oluacls_func(L, "__newindex", olua_newindexerror);
    oluacls_enum(L, "PREVIEW", (lua_Integer)cclua::plugin::wechat::ProgramType::PREVIEW);
    oluacls_enum(L, "RELEASE", (lua_Integer)cclua::plugin::wechat::ProgramType::RELEASE);
    oluacls_enum(L, "TEST", (lua_Integer)cclua::plugin::wechat::ProgramType::TEST);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_plugin_wechat_ProgramType(lua_State *L)
{
    olua_require(L, "wechat",  _olua_module_wechat);
    if (!olua_getclass(L, "cclua.plugin.wechat.ProgramType")) {
        luaL_error(L, "class not found: cclua::plugin::wechat::ProgramType");
    }
    return 1;
}
OLUA_END_DECLS
#endif

#ifdef CCLUA_BUILD_WECHAT
static int _olua_fun_cclua_plugin_wechat___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::plugin::wechat *)olua_toobj(L, 1, "cclua.plugin.wechat");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cclua_plugin_wechat_auth(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** scope */
    std::string arg2;       /** state */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // static void auth(const std::string &scope, const std::string &state)
    cclua::plugin::wechat::auth(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cclua_plugin_wechat_authQRCode(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** appid */
    std::string arg2;       /** nonceStr */
    std::string arg3;       /** timestamp */
    std::string arg4;       /** scope */
    std::string arg5;       /** signature */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_string(L, 3, &arg3);
    olua_check_string(L, 4, &arg4);
    olua_check_string(L, 5, &arg5);

    // static void authQRCode(const std::string &appid, const std::string &nonceStr, const std::string &timestamp, const std::string &scope, const std::string &signature)
    cclua::plugin::wechat::authQRCode(arg1, arg2, arg3, arg4, arg5);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cclua_plugin_wechat_dispatch(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** event */
    cocos2d::ValueMap arg2;       /** data */

    olua_check_string(L, 1, &arg1);
    olua_check_cocos2d_ValueMap(L, 2, &arg2);

    // static void dispatch(const std::string &event, const cocos2d::ValueMap &data)
    cclua::plugin::wechat::dispatch(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cclua_plugin_wechat_init(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** appid */
    std::string arg2;       /** universalLink */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // static void init(const std::string &appid, const std::string &universalLink)
    cclua::plugin::wechat::init(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cclua_plugin_wechat_isInstalled(lua_State *L)
{
    olua_startinvoke(L);

    // static bool isInstalled()
    bool ret = cclua::plugin::wechat::isInstalled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _olua_fun_cclua_plugin_wechat_open$1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** username */
    std::string arg2;       /** path */
    cclua::plugin::wechat::ProgramType arg3 = (cclua::plugin::wechat::ProgramType)0;       /** type */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_enum(L, 3, &arg3);

    // static void open(const std::string &username, @optional const std::string &path, @optional cclua::plugin::wechat::ProgramType type)
    cclua::plugin::wechat::open(arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cclua_plugin_wechat_open$2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** username */

    olua_check_string(L, 1, &arg1);

    // static void open(const std::string &username)
    cclua::plugin::wechat::open(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cclua_plugin_wechat_open$3(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** username */
    std::string arg2;       /** path */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // static void open(const std::string &username, @optional const std::string &path)
    cclua::plugin::wechat::open(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cclua_plugin_wechat_open(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_string(L, 1))) {
            // static void open(const std::string &username)
            return _olua_fun_cclua_plugin_wechat_open$2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2))) {
            // static void open(const std::string &username, @optional const std::string &path)
            return _olua_fun_cclua_plugin_wechat_open$3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2)) && (olua_is_enum(L, 3))) {
            // static void open(const std::string &username, @optional const std::string &path, @optional cclua::plugin::wechat::ProgramType type)
            return _olua_fun_cclua_plugin_wechat_open$1(L);
        // }
    }

    luaL_error(L, "method 'cclua::plugin::wechat::open' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_cclua_plugin_wechat_openCustomerService(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** corpid */
    std::string arg2;       /** url */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // static void openCustomerService(const std::string &corpid, const std::string &url)
    cclua::plugin::wechat::openCustomerService(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

#ifdef CCLUA_OS_ANDROID
static int _olua_fun_cclua_plugin_wechat_pay(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** partnerId */
    std::string arg2;       /** prepayId */
    std::string arg3;       /** noncestr */
    std::string arg4;       /** timestamp */
    std::string arg5;       /** packageValue */
    std::string arg6;       /** sign */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_string(L, 3, &arg3);
    olua_check_string(L, 4, &arg4);
    olua_check_string(L, 5, &arg5);
    olua_check_string(L, 6, &arg6);

    // static void pay(const std::string &partnerId, const std::string &prepayId, const std::string &noncestr, const std::string &timestamp, const std::string &packageValue, const std::string &sign)
    cclua::plugin::wechat::pay(arg1, arg2, arg3, arg4, arg5, arg6);

    olua_endinvoke(L);

    return 0;
}
#endif

static int _olua_fun_cclua_plugin_wechat_setDispatcher(lua_State *L)
{
    olua_startinvoke(L);

    cclua::Callback arg1;       /** dispatcher */

    olua_check_callback(L, 1, &arg1, "cclua.Callback");

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.plugin.wechat");
    std::string cb_tag = "Dispatcher";
    std::string cb_name = olua_setcallback(L, cb_store, 1, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
    // lua_State *ML = olua_mainthread(L);
    arg1 = [cb_store, cb_name, cb_ctx /*, ML */](const std::string &cb_arg1, const cocos2d::Value &cb_arg2) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (olua_contextequal(L, cb_ctx)) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_string(L, cb_arg1);
            olua_push_cocos2d_Value(L, cb_arg2);
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 2);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // static void setDispatcher(const cclua::Callback &dispatcher)
    cclua::plugin::wechat::setDispatcher(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cclua_plugin_wechat_share(lua_State *L)
{
    olua_startinvoke(L);

    cclua::plugin::wechat::ShareType arg1 = (cclua::plugin::wechat::ShareType)0;       /** type */
    cocos2d::ValueMap *arg2 = nullptr;       /** value */

    olua_check_enum(L, 1, &arg1);
    olua_check_pointer(L, 2, &arg2, "cc.types.ValueMap");

    // static void share(cclua::plugin::wechat::ShareType type, cocos2d::ValueMap &value)
    cclua::plugin::wechat::share(arg1, *arg2);

    olua_endinvoke(L);

    return 0;
}

static int _olua_fun_cclua_plugin_wechat_stopAuth(lua_State *L)
{
    olua_startinvoke(L);

    std::string cb_tag = "authQRCode";
    void *cb_store = (void *)olua_pushclassobj(L, "cclua.plugin.wechat");
    olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_EQUAL);

    // static void stopAuth()
    cclua::plugin::wechat::stopAuth();

    olua_endinvoke(L);

    return 0;
}

static int _olua_cls_cclua_plugin_wechat(lua_State *L)
{
    oluacls_class<cclua::plugin::wechat>(L, "cclua.plugin.wechat");
    oluacls_func(L, "__gc", _olua_fun_cclua_plugin_wechat___gc);
    oluacls_func(L, "auth", _olua_fun_cclua_plugin_wechat_auth);
    oluacls_func(L, "authQRCode", _olua_fun_cclua_plugin_wechat_authQRCode);
    oluacls_func(L, "dispatch", _olua_fun_cclua_plugin_wechat_dispatch);
    oluacls_func(L, "init", _olua_fun_cclua_plugin_wechat_init);
    oluacls_func(L, "isInstalled", _olua_fun_cclua_plugin_wechat_isInstalled);
    oluacls_func(L, "open", _olua_fun_cclua_plugin_wechat_open);
    oluacls_func(L, "openCustomerService", _olua_fun_cclua_plugin_wechat_openCustomerService);
#ifdef CCLUA_OS_ANDROID
    oluacls_func(L, "pay", _olua_fun_cclua_plugin_wechat_pay);
#endif
    oluacls_func(L, "setDispatcher", _olua_fun_cclua_plugin_wechat_setDispatcher);
    oluacls_func(L, "share", _olua_fun_cclua_plugin_wechat_share);
    oluacls_func(L, "stopAuth", _olua_fun_cclua_plugin_wechat_stopAuth);
    oluacls_prop(L, "installed", _olua_fun_cclua_plugin_wechat_isInstalled, nullptr);

    cclua::runtime::registerFeature("cclua.plugin.wechat.ios", true);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_plugin_wechat(lua_State *L)
{
    olua_require(L, "wechat",  _olua_module_wechat);
    if (!olua_getclass(L, "cclua.plugin.wechat")) {
        luaL_error(L, "class not found: cclua::plugin::wechat");
    }
    return 1;
}
OLUA_END_DECLS
#endif

int _olua_module_wechat(lua_State *L)
{
#ifdef CCLUA_BUILD_WECHAT
    olua_require(L, "cclua.plugin.wechat.ShareType", _olua_cls_cclua_plugin_wechat_ShareType);
    olua_require(L, "cclua.plugin.wechat.ProgramType", _olua_cls_cclua_plugin_wechat_ProgramType);
    olua_require(L, "cclua.plugin.wechat", _olua_cls_cclua_plugin_wechat);
#endif

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_wechat(lua_State *L)
{
    olua_require(L, "wechat",  _olua_module_wechat);

    return 0;
}
OLUA_END_DECLS
