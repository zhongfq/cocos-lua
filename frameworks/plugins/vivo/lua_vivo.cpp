//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_vivo.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "vivo/vivo.h"

#ifdef CCLUA_BUILD_VIVO
static int _cclua_plugin_vivo___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::plugin::vivo *)olua_toobj(L, 1, "cclua.plugin.vivo");
    olua_push_obj(L, self, "cclua.plugin.vivo");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_plugin_vivo_dispatch(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** event */
    cocos2d::ValueMap arg2;       /** data */

    olua_check_std_string(L, 1, &arg1);
    olua_check_cocos2d_ValueMap(L, 2, &arg2);

    // static void dispatch(const std::string &event, const cocos2d::ValueMap &data)
    cclua::plugin::vivo::dispatch(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_vivo_init(lua_State *L)
{
    olua_startinvoke(L);

    // static void init()
    cclua::plugin::vivo::init();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_vivo_pay(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** appid */
    std::string arg2;       /** orderNo */
    std::string arg3;       /** url */
    std::string arg4;       /** price */
    std::string arg5;       /** name */
    std::string arg6;       /** desc */
    std::string arg7;       /** sign */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);
    olua_check_std_string(L, 4, &arg4);
    olua_check_std_string(L, 5, &arg5);
    olua_check_std_string(L, 6, &arg6);
    olua_check_std_string(L, 7, &arg7);

    // static void pay(const std::string &appid, const std::string &orderNo, const std::string &url, const std::string &price, const std::string &name, const std::string &desc, const std::string &sign)
    cclua::plugin::vivo::pay(arg1, arg2, arg3, arg4, arg5, arg6, arg7);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_vivo_setDispatcher(lua_State *L)
{
    olua_startinvoke(L);

    cclua::Callback arg1;       /** dispatcher */

    olua_check_callback(L, 1, &arg1, "cclua.Callback");

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.plugin.vivo");
    std::string cb_tag = "Dispatcher";
    std::string cb_name = olua_setcallback(L, cb_store,  1, cb_tag.c_str(), OLUA_TAG_REPLACE);
    olua_Context cb_ctx = olua_context(L);
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
    cclua::plugin::vivo::setDispatcher(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_plugin_vivo(lua_State *L)
{
    oluacls_class(L, "cclua.plugin.vivo", nullptr);
    oluacls_func(L, "__olua_move", _cclua_plugin_vivo___olua_move);
    oluacls_func(L, "dispatch", _cclua_plugin_vivo_dispatch);
    oluacls_func(L, "init", _cclua_plugin_vivo_init);
    oluacls_func(L, "pay", _cclua_plugin_vivo_pay);
    oluacls_func(L, "setDispatcher", _cclua_plugin_vivo_setDispatcher);

    olua_registerluatype<cclua::plugin::vivo>(L, "cclua.plugin.vivo");

    return 1;
}
OLUA_END_DECLS
#endif

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_vivo(lua_State *L)
{
#ifdef CCLUA_BUILD_VIVO
    olua_require(L, "cclua.plugin.vivo", luaopen_cclua_plugin_vivo);
#endif

    return 0;
}
OLUA_END_DECLS
