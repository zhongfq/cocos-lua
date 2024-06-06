//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_jpush.h"
#include "lua-bindings/lua_cocos2d_types.h"
#include "lua-bindings/lua_conv_manual.h"
#include "jpush/jpush.h"

#ifdef CCLUA_BUILD_JPUSH
static int _cclua_plugin_jpush___gc(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::plugin::jpush *)olua_toobj(L, 1, "cclua.plugin.jpush");
    olua_postgc(L, self);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jpush___olua_move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::plugin::jpush *)olua_toobj(L, 1, "cclua.plugin.jpush");
    olua_push_object(L, self, "cclua.plugin.jpush");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_plugin_jpush_addTags(lua_State *L)
{
    olua_startinvoke(L);

    std::set<std::string> arg1;       /** tags */

    olua_check_array<std::string>(L, 1, arg1, [L](std::string *arg1) {
        olua_check_string(L, -1, arg1);
    });

    // static void addTags(const std::set<std::string> &tags)
    cclua::plugin::jpush::addTags(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jpush_cleanTags(lua_State *L)
{
    olua_startinvoke(L);

    // static void cleanTags()
    cclua::plugin::jpush::cleanTags();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jpush_deleteAlias(lua_State *L)
{
    olua_startinvoke(L);

    // static void deleteAlias()
    cclua::plugin::jpush::deleteAlias();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jpush_deleteTags(lua_State *L)
{
    olua_startinvoke(L);

    std::set<std::string> arg1;       /** tags */

    olua_check_array<std::string>(L, 1, arg1, [L](std::string *arg1) {
        olua_check_string(L, -1, arg1);
    });

    // static void deleteTags(const std::set<std::string> &tags)
    cclua::plugin::jpush::deleteTags(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jpush_getRegistrationID(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string getRegistrationID()
    std::string ret = cclua::plugin::jpush::getRegistrationID();
    int num_ret = olua_push_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_plugin_jpush_init(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** appKey */
    std::string arg2;       /** channel */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // static void init(const std::string &appKey, const std::string &channel)
    cclua::plugin::jpush::init(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jpush_isEnabled(lua_State *L)
{
    olua_startinvoke(L);

    // static bool isEnabled()
    bool ret = cclua::plugin::jpush::isEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_plugin_jpush_requestPermission(lua_State *L)
{
    olua_startinvoke(L);

    // static void requestPermission()
    cclua::plugin::jpush::requestPermission();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jpush_setAlias(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** alias */

    olua_check_string(L, 1, &arg1);

    // static void setAlias(const std::string &alias)
    cclua::plugin::jpush::setAlias(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jpush_setBadge(lua_State *L)
{
    olua_startinvoke(L);

    int arg1 = 0;       /** value */

    olua_check_integer(L, 1, &arg1);

    // static void setBadge(int value)
    cclua::plugin::jpush::setBadge(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jpush_setDebug(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** enabled */

    olua_check_bool(L, 1, &arg1);

    // static void setDebug(bool enabled)
    cclua::plugin::jpush::setDebug(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jpush_setLogOFF(lua_State *L)
{
    olua_startinvoke(L);

    // static void setLogOFF()
    cclua::plugin::jpush::setLogOFF();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_plugin_jpush_setTags(lua_State *L)
{
    olua_startinvoke(L);

    std::set<std::string> arg1;       /** tags */

    olua_check_array<std::string>(L, 1, arg1, [L](std::string *arg1) {
        olua_check_string(L, -1, arg1);
    });

    // static void setTags(const std::set<std::string> &tags)
    cclua::plugin::jpush::setTags(arg1);

    olua_endinvoke(L);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_cclua_plugin_jpush(lua_State *L)
{
    oluacls_class<cclua::plugin::jpush>(L, "cclua.plugin.jpush");
    oluacls_func(L, "__gc", _cclua_plugin_jpush___gc);
    oluacls_func(L, "__olua_move", _cclua_plugin_jpush___olua_move);
    oluacls_func(L, "addTags", _cclua_plugin_jpush_addTags);
    oluacls_func(L, "cleanTags", _cclua_plugin_jpush_cleanTags);
    oluacls_func(L, "deleteAlias", _cclua_plugin_jpush_deleteAlias);
    oluacls_func(L, "deleteTags", _cclua_plugin_jpush_deleteTags);
    oluacls_func(L, "getRegistrationID", _cclua_plugin_jpush_getRegistrationID);
    oluacls_func(L, "init", _cclua_plugin_jpush_init);
    oluacls_func(L, "isEnabled", _cclua_plugin_jpush_isEnabled);
    oluacls_func(L, "requestPermission", _cclua_plugin_jpush_requestPermission);
    oluacls_func(L, "setAlias", _cclua_plugin_jpush_setAlias);
    oluacls_func(L, "setBadge", _cclua_plugin_jpush_setBadge);
    oluacls_func(L, "setDebug", _cclua_plugin_jpush_setDebug);
    oluacls_func(L, "setLogOFF", _cclua_plugin_jpush_setLogOFF);
    oluacls_func(L, "setTags", _cclua_plugin_jpush_setTags);
    oluacls_prop(L, "enabled", _cclua_plugin_jpush_isEnabled, nullptr);
    oluacls_prop(L, "registrationID", _cclua_plugin_jpush_getRegistrationID, nullptr);

    cclua::runtime::registerFeature("cclua.plugin.jpush.ios", true);

    return 1;
}
OLUA_END_DECLS
#endif

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_jpush(lua_State *L)
{
#ifdef CCLUA_BUILD_JPUSH
    olua_require(L, "cclua.plugin.jpush", luaopen_cclua_plugin_jpush);
#endif

    return 0;
}
OLUA_END_DECLS
