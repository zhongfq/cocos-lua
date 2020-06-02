//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua-bindings/lua_xgame.h"
#include "lua-bindings/lua_conv.h"
#include "lua-bindings/lua_conv_manual.h"
#include "xgame/filesystem.h"
#include "xgame/xlua.h"
#include "xgame/preferences.h"
#include "xgame/downloader.h"
#include "xgame/runtime.h"
#include "xgame/RootScene.h"
#include "xgame/timer.h"
#include "olua/olua.hpp"



int auto_olua_push_xgame_downloader_FileTask(lua_State *L, const xgame::downloader::FileTask *value)
{
    if (value) {
        lua_createtable(L, 0, 4);

        olua_push_std_string(L, value->url);
        olua_setfield(L, -2, "url");

        olua_push_std_string(L, value->path);
        olua_setfield(L, -2, "path");

        olua_push_std_string(L, value->md5);
        olua_setfield(L, -2, "md5");

        olua_push_uint(L, (lua_Unsigned)value->state);
        olua_setfield(L, -2, "state");
    } else {
        lua_pushnil(L);
    }

    return 1;
}

void auto_olua_check_xgame_downloader_FileTask(lua_State *L, int idx, xgame::downloader::FileTask *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);
    luaL_checktype(L, idx, LUA_TTABLE);

    std::string arg1;       /** url */
    std::string arg2;       /** path */
    std::string arg3;       /** md5 */
    lua_Unsigned arg4 = 0;       /** state */

    olua_getfield(L, idx, "url");
    olua_check_std_string(L, -1, &arg1);
    value->url = (std::string)arg1;
    lua_pop(L, 1);

    olua_getfield(L, idx, "path");
    olua_check_std_string(L, -1, &arg2);
    value->path = (std::string)arg2;
    lua_pop(L, 1);

    olua_getfield(L, idx, "md5");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_std_string(L, -1, &arg3);
        value->md5 = (std::string)arg3;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "state");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_uint(L, -1, &arg4);
        value->state = (xgame::downloader::FileState)arg4;
    }
    lua_pop(L, 1);
}

bool auto_olua_is_xgame_downloader_FileTask(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "path") && olua_hasfield(L, idx, "url");
}

void auto_olua_pack_xgame_downloader_FileTask(lua_State *L, int idx, xgame::downloader::FileTask *value)
{
    if (!value) {
        luaL_error(L, "value is NULL");
    }
    idx = lua_absindex(L, idx);

    std::string arg1;       /** url */
    std::string arg2;       /** path */
    std::string arg3;       /** md5 */
    lua_Unsigned arg4 = 0;       /** state */

    olua_check_std_string(L, idx + 0, &arg1);
    value->url = (std::string)arg1;

    olua_check_std_string(L, idx + 1, &arg2);
    value->path = (std::string)arg2;

    olua_check_std_string(L, idx + 2, &arg3);
    value->md5 = (std::string)arg3;

    olua_check_uint(L, idx + 3, &arg4);
    value->state = (xgame::downloader::FileState)arg4;
}

int auto_olua_unpack_xgame_downloader_FileTask(lua_State *L, const xgame::downloader::FileTask *value)
{
    if (value) {
        olua_push_std_string(L, value->url);
        olua_push_std_string(L, value->path);
        olua_push_std_string(L, value->md5);
        olua_push_uint(L, (lua_Unsigned)value->state);
    } else {
        for (int i = 0; i < 4; i++) {
            lua_pushnil(L);
        }
    }

    return 4;
}

bool auto_olua_ispack_xgame_downloader_FileTask(lua_State *L, int idx)
{
    return olua_is_std_string(L, idx + 0) && olua_is_std_string(L, idx + 1) && olua_is_std_string(L, idx + 2) && olua_is_uint(L, idx + 3);
}

static int _xgame_SceneNoCamera___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (xgame::SceneNoCamera *)olua_toobj(L, 1, "kernel.SceneNoCamera");
    olua_push_cppobj(L, self, "kernel.SceneNoCamera");

    olua_endinvoke(L);

    return 1;
}

static int _xgame_SceneNoCamera_create(lua_State *L)
{
    olua_startinvoke(L);

    // static xgame::SceneNoCamera *create()
    xgame::SceneNoCamera *ret = (xgame::SceneNoCamera *)xgame::SceneNoCamera::create();
    int num_ret = olua_push_cppobj(L, ret, "kernel.SceneNoCamera");

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_SceneNoCamera_createWithPhysics(lua_State *L)
{
    olua_startinvoke(L);

    // static xgame::SceneNoCamera *createWithPhysics()
    xgame::SceneNoCamera *ret = (xgame::SceneNoCamera *)xgame::SceneNoCamera::createWithPhysics();
    int num_ret = olua_push_cppobj(L, ret, "kernel.SceneNoCamera");

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_SceneNoCamera_createWithSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */

    auto_olua_check_cocos2d_Size(L, 1, &arg1);

    // static xgame::SceneNoCamera *createWithSize(const cocos2d::Size &size)
    xgame::SceneNoCamera *ret = (xgame::SceneNoCamera *)xgame::SceneNoCamera::createWithSize(arg1);
    int num_ret = olua_push_cppobj(L, ret, "kernel.SceneNoCamera");

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_SceneNoCamera_new(lua_State *L)
{
    olua_startinvoke(L);

    // SceneNoCamera()
    xgame::SceneNoCamera *ret = (xgame::SceneNoCamera *)new xgame::SceneNoCamera();
    int num_ret = olua_push_cppobj(L, ret, "kernel.SceneNoCamera");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_xgame_SceneNoCamera(lua_State *L)
{
    oluacls_class(L, "kernel.SceneNoCamera", "cc.Scene");
    oluacls_func(L, "__move", _xgame_SceneNoCamera___move);
    oluacls_func(L, "create", _xgame_SceneNoCamera_create);
    oluacls_func(L, "createWithPhysics", _xgame_SceneNoCamera_createWithPhysics);
    oluacls_func(L, "createWithSize", _xgame_SceneNoCamera_createWithSize);
    oluacls_func(L, "new", _xgame_SceneNoCamera_new);

    olua_registerluatype<xgame::SceneNoCamera>(L, "kernel.SceneNoCamera");

    return 1;
}

static int luaopen_xgame_Permission(lua_State *L)
{
    oluacls_class(L, "kernel.Permission", nullptr);
    oluacls_const_integer(L, "AUDIO", (lua_Integer)xgame::Permission::AUDIO);
    oluacls_const_integer(L, "CAMERA", (lua_Integer)xgame::Permission::CAMERA);
    oluacls_const_integer(L, "PHOTO", (lua_Integer)xgame::Permission::PHOTO);

    olua_registerluatype<xgame::Permission>(L, "kernel.Permission");

    return 1;
}

static int luaopen_xgame_PermissionStatus(lua_State *L)
{
    oluacls_class(L, "kernel.PermissionStatus", nullptr);
    oluacls_const_integer(L, "AUTHORIZED", (lua_Integer)xgame::PermissionStatus::AUTHORIZED);
    oluacls_const_integer(L, "DENIED", (lua_Integer)xgame::PermissionStatus::DENIED);
    oluacls_const_integer(L, "NOT_DETERMINED", (lua_Integer)xgame::PermissionStatus::NOT_DETERMINED);
    oluacls_const_integer(L, "RESTRICTED", (lua_Integer)xgame::PermissionStatus::RESTRICTED);

    olua_registerluatype<xgame::PermissionStatus>(L, "kernel.PermissionStatus");

    return 1;
}

static int _xgame_runtime___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (xgame::runtime *)olua_toobj(L, 1, "kernel.runtime");
    olua_push_cppobj(L, self, "kernel.runtime");

    olua_endinvoke(L);

    return 1;
}

static int _xgame_runtime_alert(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** title */
    std::string arg2;       /** message */
    std::string arg3;       /** ok */
    std::string arg4;       /** no */
    std::function<void(bool)> arg5;       /** callback */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_std_string(L, 3, &arg3);
    olua_check_std_string(L, 4, &arg4);

    void *self_obj = (void *)olua_pushclassobj(L, "kernel.runtime");
    std::string tag = "alert";
    std::string func = olua_setcallback(L, self_obj, tag.c_str(), 5, OLUA_TAG_NEW);
    lua_Unsigned ctx = olua_context(L);
    arg5 = [self_obj, func, ctx](bool arg1) {
        lua_State *L = olua_mainthread(NULL);

        if (L != NULL && (olua_context(L) == ctx)) {
            int top = lua_gettop(L);
            olua_push_bool(L, arg1);

            olua_callback(L, self_obj, func.c_str(), 1);

            olua_removecallback(L, self_obj, func.c_str(), OLUA_TAG_WHOLE);

            lua_settop(L, top);
        }
    };

    // static void alert(const std::string &title, const std::string &message, const std::string &ok, const std::string &no, @local const std::function<void (bool)> callback)
    xgame::runtime::alert(arg1, arg2, arg3, arg4, arg5);

    olua_endinvoke(L);

    return 0;
}

static int _xgame_runtime_canOpenURL(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** uri */

    olua_check_std_string(L, 1, &arg1);

    // static bool canOpenURL(const std::string &uri)
    bool ret = (bool)xgame::runtime::canOpenURL(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_runtime_capture1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Node *arg1 = nullptr;       /** node */
    lua_Unsigned arg2 = 0;       /** format */
    lua_Unsigned arg3 = 0;       /** depthStencilFormat */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Node");
    olua_check_uint(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);

    // static cocos2d::RenderTexture *capture(cocos2d::Node *node, @optional cocos2d::backend::PixelFormat format, @optional cocos2d::backend::PixelFormat depthStencilFormat)
    cocos2d::RenderTexture *ret = (cocos2d::RenderTexture *)xgame::runtime::capture(arg1, (cocos2d::backend::PixelFormat)arg2, (cocos2d::backend::PixelFormat)arg3);
    int num_ret = olua_push_cppobj(L, ret, "cc.RenderTexture");

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_runtime_capture2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Node *arg1 = nullptr;       /** node */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Node");

    // static cocos2d::RenderTexture *capture(cocos2d::Node *node, @optional cocos2d::backend::PixelFormat format, @optional cocos2d::backend::PixelFormat depthStencilFormat)
    cocos2d::RenderTexture *ret = (cocos2d::RenderTexture *)xgame::runtime::capture(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cc.RenderTexture");

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_runtime_capture3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Node *arg1 = nullptr;       /** node */
    lua_Unsigned arg2 = 0;       /** format */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Node");
    olua_check_uint(L, 2, &arg2);

    // static cocos2d::RenderTexture *capture(cocos2d::Node *node, @optional cocos2d::backend::PixelFormat format, @optional cocos2d::backend::PixelFormat depthStencilFormat)
    cocos2d::RenderTexture *ret = (cocos2d::RenderTexture *)xgame::runtime::capture(arg1, (cocos2d::backend::PixelFormat)arg2);
    int num_ret = olua_push_cppobj(L, ret, "cc.RenderTexture");

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_runtime_capture(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_cppobj(L, 1, "cc.Node"))) {
            // static cocos2d::RenderTexture *capture(cocos2d::Node *node, @optional cocos2d::backend::PixelFormat format, @optional cocos2d::backend::PixelFormat depthStencilFormat)
            return _xgame_runtime_capture2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_cppobj(L, 1, "cc.Node")) && (olua_is_uint(L, 2))) {
            // static cocos2d::RenderTexture *capture(cocos2d::Node *node, @optional cocos2d::backend::PixelFormat format, @optional cocos2d::backend::PixelFormat depthStencilFormat)
            return _xgame_runtime_capture3(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_cppobj(L, 1, "cc.Node")) && (olua_is_uint(L, 2)) && (olua_is_uint(L, 3))) {
            // static cocos2d::RenderTexture *capture(cocos2d::Node *node, @optional cocos2d::backend::PixelFormat format, @optional cocos2d::backend::PixelFormat depthStencilFormat)
            return _xgame_runtime_capture1(L);
        // }
    }

    luaL_error(L, "method 'xgame::runtime::capture' not support '%d' arguments", num_args);

    return 0;
}

static int _xgame_runtime_clearStorage(lua_State *L)
{
    olua_startinvoke(L);

    // static void clearStorage()
    xgame::runtime::clearStorage();

    olua_endinvoke(L);

    return 0;
}

static int _xgame_runtime_disableReport(lua_State *L)
{
    olua_startinvoke(L);

    // static void disableReport()
    xgame::runtime::disableReport();

    olua_endinvoke(L);

    return 0;
}

static int _xgame_runtime_gc(lua_State *L)
{
    olua_startinvoke(L);

    // static void gc()
    xgame::runtime::gc();

    olua_endinvoke(L);

    return 0;
}

static int _xgame_runtime_getAppBuild(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getAppBuild()
    const std::string ret = (const std::string)xgame::runtime::getAppBuild();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_runtime_getAppVersion(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getAppVersion()
    const std::string ret = (const std::string)xgame::runtime::getAppVersion();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_runtime_getAudioSessionCatalog(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getAudioSessionCatalog()
    const std::string ret = (const std::string)xgame::runtime::getAudioSessionCatalog();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_runtime_getChannel(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getChannel()
    const std::string ret = (const std::string)xgame::runtime::getChannel();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_runtime_getDeviceInfo(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getDeviceInfo()
    const std::string ret = (const std::string)xgame::runtime::getDeviceInfo();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_runtime_getIDFA(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string getIDFA()
    std::string ret = (std::string)xgame::runtime::getIDFA();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_runtime_getLanguage(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getLanguage()
    const std::string ret = (const std::string)xgame::runtime::getLanguage();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_runtime_getLogPath(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getLogPath()
    const std::string ret = (const std::string)xgame::runtime::getLogPath();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_runtime_getManifestVersion(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getManifestVersion()
    const std::string ret = (const std::string)xgame::runtime::getManifestVersion();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_runtime_getNetworkStatus(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getNetworkStatus()
    const std::string ret = (const std::string)xgame::runtime::getNetworkStatus();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_runtime_getOS(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getOS()
    const std::string ret = (const std::string)xgame::runtime::getOS();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_runtime_getPackageName(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getPackageName()
    const std::string ret = (const std::string)xgame::runtime::getPackageName();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_runtime_getPermissionStatus(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** permission */

    olua_check_uint(L, 1, &arg1);

    // static const xgame::PermissionStatus getPermissionStatus(xgame::Permission permission)
    const xgame::PermissionStatus ret = (const xgame::PermissionStatus)xgame::runtime::getPermissionStatus((xgame::Permission)arg1);
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_runtime_getSampleCount(lua_State *L)
{
    olua_startinvoke(L);

    // static unsigned int getSampleCount()
    unsigned int ret = (unsigned int)xgame::runtime::getSampleCount();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_runtime_getTime(lua_State *L)
{
    olua_startinvoke(L);

    // static float getTime()
    float ret = (float)xgame::runtime::getTime();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_runtime_getVersion(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getVersion()
    const std::string ret = (const std::string)xgame::runtime::getVersion();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_runtime_isAdvertisingTrackingEnabled(lua_State *L)
{
    olua_startinvoke(L);

    // static bool isAdvertisingTrackingEnabled()
    bool ret = (bool)xgame::runtime::isAdvertisingTrackingEnabled();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_runtime_isDebug(lua_State *L)
{
    olua_startinvoke(L);

    // static bool isDebug()
    bool ret = (bool)xgame::runtime::isDebug();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_runtime_isRestarting(lua_State *L)
{
    olua_startinvoke(L);

    // static bool isRestarting()
    bool ret = (bool)xgame::runtime::isRestarting();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_runtime_launch(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** scriptPath */

    olua_check_std_string(L, 1, &arg1);

    // static bool launch(const std::string &scriptPath)
    bool ret = (bool)xgame::runtime::launch(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_runtime_openURL1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** uri */
    std::function<void(bool)> arg2;       /** callback */

    olua_check_std_string(L, 1, &arg1);

    if (olua_is_std_function(L, 2)) {
        void *self_obj = (void *)olua_pushclassobj(L, "kernel.runtime");
        std::string tag = "openURL";
        std::string func = olua_setcallback(L, self_obj, tag.c_str(), 2, OLUA_TAG_NEW);
        lua_Unsigned ctx = olua_context(L);
        arg2 = [self_obj, func, ctx](bool arg1) {
            lua_State *L = olua_mainthread(NULL);

            if (L != NULL && (olua_context(L) == ctx)) {
                int top = lua_gettop(L);
                olua_push_bool(L, arg1);

                olua_callback(L, self_obj, func.c_str(), 1);

                olua_removecallback(L, self_obj, func.c_str(), OLUA_TAG_WHOLE);

                lua_settop(L, top);
            }
        };
    } else {
        arg2 = nullptr;
    }

    // static void openURL(const std::string &uri, @local @optional const std::function<void (bool)> callback)
    xgame::runtime::openURL(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _xgame_runtime_openURL2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** uri */

    olua_check_std_string(L, 1, &arg1);

    // static void openURL(const std::string &uri, @local @optional const std::function<void (bool)> callback)
    xgame::runtime::openURL(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _xgame_runtime_openURL(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static void openURL(const std::string &uri, @local @optional const std::function<void (bool)> callback)
            return _xgame_runtime_openURL2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_function(L, 2))) {
            // static void openURL(const std::string &uri, @local @optional const std::function<void (bool)> callback)
            return _xgame_runtime_openURL1(L);
        // }
    }

    luaL_error(L, "method 'xgame::runtime::openURL' not support '%d' arguments", num_args);

    return 0;
}

static int _xgame_runtime_printSupport(lua_State *L)
{
    olua_startinvoke(L);

    // static void printSupport()
    xgame::runtime::printSupport();

    olua_endinvoke(L);

    return 0;
}

static int _xgame_runtime_requestPermission(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** permission */
    std::function<void(xgame::PermissionStatus)> arg2;       /** callback */

    olua_check_uint(L, 1, &arg1);

    void *self_obj = (void *)olua_pushclassobj(L, "kernel.runtime");
    std::string tag = "requestPermission";
    std::string func = olua_setcallback(L, self_obj, tag.c_str(), 2, OLUA_TAG_NEW);
    lua_Unsigned ctx = olua_context(L);
    arg2 = [self_obj, func, ctx](xgame::PermissionStatus arg1) {
        lua_State *L = olua_mainthread(NULL);

        if (L != NULL && (olua_context(L) == ctx)) {
            int top = lua_gettop(L);
            olua_push_uint(L, (lua_Unsigned)arg1);

            olua_callback(L, self_obj, func.c_str(), 1);

            olua_removecallback(L, self_obj, func.c_str(), OLUA_TAG_WHOLE);

            lua_settop(L, top);
        }
    };

    // static void requestPermission(xgame::Permission permission, @local const std::function<void (PermissionStatus)> callback)
    xgame::runtime::requestPermission((xgame::Permission)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _xgame_runtime_restart(lua_State *L)
{
    olua_startinvoke(L);

    // static bool restart()
    bool ret = (bool)xgame::runtime::restart();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_runtime_setAudioSessionCatalog(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** catalog */

    olua_check_std_string(L, 1, &arg1);

    // static void setAudioSessionCatalog(const std::string &catalog)
    xgame::runtime::setAudioSessionCatalog(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _xgame_runtime_setDispatcher(lua_State *L)
{
    olua_startinvoke(L);

    int handler = olua_reffunc(L, 1);
    xgame::runtime::setDispatcher([handler](const std::string &event, const std::string &args) {
        lua_State *L = olua_mainthread(NULL);
        if (L != NULL) {
            int top = lua_gettop(L);
            olua_geterrorfunc(L);
            olua_getref(L, handler);
            if (lua_isfunction(L, -1)) {
                lua_pushstring(L, event.c_str());
                lua_pushstring(L, args.c_str());
                lua_pcall(L, 2, 0, top + 1);
            }
            lua_settop(L, top);
        }
    });

    olua_endinvoke(L);

    return 0;
}

static int _xgame_runtime_setLogPath(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static void setLogPath(const std::string &path)
    xgame::runtime::setLogPath(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _xgame_runtime_setManifestVersion(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** version */

    olua_check_std_string(L, 1, &arg1);

    // static void setManifestVersion(const std::string &version)
    xgame::runtime::setManifestVersion(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _xgame_runtime_setSampleCount(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** samples */

    olua_check_uint(L, 1, &arg1);

    // static void setSampleCount(unsigned int samples)
    xgame::runtime::setSampleCount((unsigned int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _xgame_runtime_support(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** api */

    olua_check_std_string(L, 1, &arg1);

    // static bool support(const std::string &api)
    bool ret = (bool)xgame::runtime::support(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_runtime_testCrash(lua_State *L)
{
    olua_startinvoke(L);

    xgame::runtime::log("test native crash!!!!");
    char *prt = NULL;
    *prt = 0;

    olua_endinvoke(L);

    return 0;
}

static int luaopen_xgame_runtime(lua_State *L)
{
    oluacls_class(L, "kernel.runtime", nullptr);
    oluacls_func(L, "__move", _xgame_runtime___move);
    oluacls_func(L, "alert", _xgame_runtime_alert);
    oluacls_func(L, "canOpenURL", _xgame_runtime_canOpenURL);
    oluacls_func(L, "capture", _xgame_runtime_capture);
    oluacls_func(L, "clearStorage", _xgame_runtime_clearStorage);
    oluacls_func(L, "disableReport", _xgame_runtime_disableReport);
    oluacls_func(L, "gc", _xgame_runtime_gc);
    oluacls_func(L, "getAppBuild", _xgame_runtime_getAppBuild);
    oluacls_func(L, "getAppVersion", _xgame_runtime_getAppVersion);
    oluacls_func(L, "getAudioSessionCatalog", _xgame_runtime_getAudioSessionCatalog);
    oluacls_func(L, "getChannel", _xgame_runtime_getChannel);
    oluacls_func(L, "getDeviceInfo", _xgame_runtime_getDeviceInfo);
    oluacls_func(L, "getIDFA", _xgame_runtime_getIDFA);
    oluacls_func(L, "getLanguage", _xgame_runtime_getLanguage);
    oluacls_func(L, "getLogPath", _xgame_runtime_getLogPath);
    oluacls_func(L, "getManifestVersion", _xgame_runtime_getManifestVersion);
    oluacls_func(L, "getNetworkStatus", _xgame_runtime_getNetworkStatus);
    oluacls_func(L, "getOS", _xgame_runtime_getOS);
    oluacls_func(L, "getPackageName", _xgame_runtime_getPackageName);
    oluacls_func(L, "getPermissionStatus", _xgame_runtime_getPermissionStatus);
    oluacls_func(L, "getSampleCount", _xgame_runtime_getSampleCount);
    oluacls_func(L, "getTime", _xgame_runtime_getTime);
    oluacls_func(L, "getVersion", _xgame_runtime_getVersion);
    oluacls_func(L, "isAdvertisingTrackingEnabled", _xgame_runtime_isAdvertisingTrackingEnabled);
    oluacls_func(L, "isDebug", _xgame_runtime_isDebug);
    oluacls_func(L, "isRestarting", _xgame_runtime_isRestarting);
    oluacls_func(L, "launch", _xgame_runtime_launch);
    oluacls_func(L, "openURL", _xgame_runtime_openURL);
    oluacls_func(L, "printSupport", _xgame_runtime_printSupport);
    oluacls_func(L, "requestPermission", _xgame_runtime_requestPermission);
    oluacls_func(L, "restart", _xgame_runtime_restart);
    oluacls_func(L, "setAudioSessionCatalog", _xgame_runtime_setAudioSessionCatalog);
    oluacls_func(L, "setDispatcher", _xgame_runtime_setDispatcher);
    oluacls_func(L, "setLogPath", _xgame_runtime_setLogPath);
    oluacls_func(L, "setManifestVersion", _xgame_runtime_setManifestVersion);
    oluacls_func(L, "setSampleCount", _xgame_runtime_setSampleCount);
    oluacls_func(L, "support", _xgame_runtime_support);
    oluacls_func(L, "testCrash", _xgame_runtime_testCrash);
    oluacls_prop(L, "advertisingTrackingEnabled", _xgame_runtime_isAdvertisingTrackingEnabled, nullptr);
    oluacls_prop(L, "appBuild", _xgame_runtime_getAppBuild, nullptr);
    oluacls_prop(L, "appVersion", _xgame_runtime_getAppVersion, nullptr);
    oluacls_prop(L, "audioSessionCatalog", _xgame_runtime_getAudioSessionCatalog, _xgame_runtime_setAudioSessionCatalog);
    oluacls_prop(L, "channel", _xgame_runtime_getChannel, nullptr);
    oluacls_prop(L, "debug", _xgame_runtime_isDebug, nullptr);
    oluacls_prop(L, "deviceInfo", _xgame_runtime_getDeviceInfo, nullptr);
    oluacls_prop(L, "idfa", _xgame_runtime_getIDFA, nullptr);
    oluacls_prop(L, "language", _xgame_runtime_getLanguage, nullptr);
    oluacls_prop(L, "logPath", _xgame_runtime_getLogPath, _xgame_runtime_setLogPath);
    oluacls_prop(L, "manifestVersion", _xgame_runtime_getManifestVersion, _xgame_runtime_setManifestVersion);
    oluacls_prop(L, "networkStatus", _xgame_runtime_getNetworkStatus, nullptr);
    oluacls_prop(L, "os", _xgame_runtime_getOS, nullptr);
    oluacls_prop(L, "packageName", _xgame_runtime_getPackageName, nullptr);
    oluacls_prop(L, "restarting", _xgame_runtime_isRestarting, nullptr);
    oluacls_prop(L, "sampleCount", _xgame_runtime_getSampleCount, _xgame_runtime_setSampleCount);
    oluacls_prop(L, "time", _xgame_runtime_getTime, nullptr);
    oluacls_prop(L, "version", _xgame_runtime_getVersion, nullptr);

    olua_registerluatype<xgame::runtime>(L, "kernel.runtime");

    return 1;
}

static int _xgame_filesystem___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (xgame::filesystem *)olua_toobj(L, 1, "kernel.filesystem");
    olua_push_cppobj(L, self, "kernel.filesystem");

    olua_endinvoke(L);

    return 1;
}

static int _xgame_filesystem_addSearchPath1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */
    bool arg2 = false;       /** front */

    olua_check_std_string(L, 1, &arg1);
    olua_check_bool(L, 2, &arg2);

    // static void addSearchPath(const std::string &path, @optional bool front)
    xgame::filesystem::addSearchPath(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _xgame_filesystem_addSearchPath2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static void addSearchPath(const std::string &path, @optional bool front)
    xgame::filesystem::addSearchPath(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _xgame_filesystem_addSearchPath(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static void addSearchPath(const std::string &path, @optional bool front)
            return _xgame_filesystem_addSearchPath2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_bool(L, 2))) {
            // static void addSearchPath(const std::string &path, @optional bool front)
            return _xgame_filesystem_addSearchPath1(L);
        // }
    }

    luaL_error(L, "method 'xgame::filesystem::addSearchPath' not support '%d' arguments", num_args);

    return 0;
}

static int _xgame_filesystem_copy(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** srcPath */
    std::string arg2;       /** destPath */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static bool copy(const std::string &srcPath, const std::string &destPath)
    bool ret = (bool)xgame::filesystem::copy(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_filesystem_createDirectory1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */
    bool arg2 = false;       /** isFilePath */

    olua_check_std_string(L, 1, &arg1);
    olua_check_bool(L, 2, &arg2);

    // static bool createDirectory(const std::string &path, @optional bool isFilePath)
    bool ret = (bool)xgame::filesystem::createDirectory(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_filesystem_createDirectory2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static bool createDirectory(const std::string &path, @optional bool isFilePath)
    bool ret = (bool)xgame::filesystem::createDirectory(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_filesystem_createDirectory(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static bool createDirectory(const std::string &path, @optional bool isFilePath)
            return _xgame_filesystem_createDirectory2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_bool(L, 2))) {
            // static bool createDirectory(const std::string &path, @optional bool isFilePath)
            return _xgame_filesystem_createDirectory1(L);
        // }
    }

    luaL_error(L, "method 'xgame::filesystem::createDirectory' not support '%d' arguments", num_args);

    return 0;
}

static int _xgame_filesystem_exist(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static bool exist(const std::string &path)
    bool ret = (bool)xgame::filesystem::exist(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_filesystem_fullPath(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static const std::string fullPath(const std::string &path)
    const std::string ret = (const std::string)xgame::filesystem::fullPath(arg1);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_filesystem_getBuiltinCacheDirectory(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getBuiltinCacheDirectory()
    const std::string ret = (const std::string)xgame::filesystem::getBuiltinCacheDirectory();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_filesystem_getCacheDirectory(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getCacheDirectory()
    const std::string ret = (const std::string)xgame::filesystem::getCacheDirectory();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_filesystem_getDocumentDirectory(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getDocumentDirectory()
    const std::string ret = (const std::string)xgame::filesystem::getDocumentDirectory();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_filesystem_getSDCardDirectory(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getSDCardDirectory()
    const std::string ret = (const std::string)xgame::filesystem::getSDCardDirectory();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_filesystem_getTmpDirectory(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getTmpDirectory()
    const std::string ret = (const std::string)xgame::filesystem::getTmpDirectory();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_filesystem_getWritablePath(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getWritablePath()
    const std::string ret = (const std::string)xgame::filesystem::getWritablePath();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_filesystem_isDirectory(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static bool isDirectory(const std::string &path)
    bool ret = (bool)xgame::filesystem::isDirectory(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_filesystem_isFile(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static bool isFile(const std::string &path)
    bool ret = (bool)xgame::filesystem::isFile(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_filesystem_read(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static cocos2d::Data read(const std::string &path)
    cocos2d::Data ret = (cocos2d::Data)xgame::filesystem::read(arg1);
    int num_ret = manual_olua_push_cocos2d_Data(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_filesystem_remove(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static bool remove(const std::string &path)
    bool ret = (bool)xgame::filesystem::remove(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_filesystem_rename(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** oldPath */
    std::string arg2;       /** newPath */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static bool rename(const std::string &oldPath, const std::string &newPath)
    bool ret = (bool)xgame::filesystem::rename(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_filesystem_shortPath1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */
    lua_Unsigned arg2 = 0;       /** limit */

    olua_check_std_string(L, 1, &arg1);
    olua_check_uint(L, 2, &arg2);

    // static const std::string shortPath(const std::string &path, @optional size_t limit)
    const std::string ret = (const std::string)xgame::filesystem::shortPath(arg1, (size_t)arg2);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_filesystem_shortPath2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static const std::string shortPath(const std::string &path, @optional size_t limit)
    const std::string ret = (const std::string)xgame::filesystem::shortPath(arg1);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_filesystem_shortPath(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static const std::string shortPath(const std::string &path, @optional size_t limit)
            return _xgame_filesystem_shortPath2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_uint(L, 2))) {
            // static const std::string shortPath(const std::string &path, @optional size_t limit)
            return _xgame_filesystem_shortPath1(L);
        // }
    }

    luaL_error(L, "method 'xgame::filesystem::shortPath' not support '%d' arguments", num_args);

    return 0;
}

static int _xgame_filesystem_unzip(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */
    std::string arg2;       /** dest */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static bool unzip(const std::string &path, const std::string &dest)
    bool ret = (bool)xgame::filesystem::unzip(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_filesystem_write(lua_State *L)
{
    olua_startinvoke(L);

    size_t len;
    std::string path = olua_tostring(L, 1);
    const char *data = olua_checklstring(L, 2, &len);
    bool ret = (bool)xgame::filesystem::write(path, data, len);
    olua_push_bool(L, ret);

    olua_endinvoke(L);

    return 1;
}

static int luaopen_xgame_filesystem(lua_State *L)
{
    oluacls_class(L, "kernel.filesystem", nullptr);
    oluacls_func(L, "__move", _xgame_filesystem___move);
    oluacls_func(L, "addSearchPath", _xgame_filesystem_addSearchPath);
    oluacls_func(L, "copy", _xgame_filesystem_copy);
    oluacls_func(L, "createDirectory", _xgame_filesystem_createDirectory);
    oluacls_func(L, "exist", _xgame_filesystem_exist);
    oluacls_func(L, "fullPath", _xgame_filesystem_fullPath);
    oluacls_func(L, "getBuiltinCacheDirectory", _xgame_filesystem_getBuiltinCacheDirectory);
    oluacls_func(L, "getCacheDirectory", _xgame_filesystem_getCacheDirectory);
    oluacls_func(L, "getDocumentDirectory", _xgame_filesystem_getDocumentDirectory);
    oluacls_func(L, "getSDCardDirectory", _xgame_filesystem_getSDCardDirectory);
    oluacls_func(L, "getTmpDirectory", _xgame_filesystem_getTmpDirectory);
    oluacls_func(L, "getWritablePath", _xgame_filesystem_getWritablePath);
    oluacls_func(L, "isDirectory", _xgame_filesystem_isDirectory);
    oluacls_func(L, "isFile", _xgame_filesystem_isFile);
    oluacls_func(L, "read", _xgame_filesystem_read);
    oluacls_func(L, "remove", _xgame_filesystem_remove);
    oluacls_func(L, "rename", _xgame_filesystem_rename);
    oluacls_func(L, "shortPath", _xgame_filesystem_shortPath);
    oluacls_func(L, "unzip", _xgame_filesystem_unzip);
    oluacls_func(L, "write", _xgame_filesystem_write);
    oluacls_prop(L, "builtinCacheDirectory", _xgame_filesystem_getBuiltinCacheDirectory, nullptr);
    oluacls_prop(L, "cacheDirectory", _xgame_filesystem_getCacheDirectory, nullptr);
    oluacls_prop(L, "documentDirectory", _xgame_filesystem_getDocumentDirectory, nullptr);
    oluacls_prop(L, "sdCardDirectory", _xgame_filesystem_getSDCardDirectory, nullptr);
    oluacls_prop(L, "tmpDirectory", _xgame_filesystem_getTmpDirectory, nullptr);
    oluacls_prop(L, "writablePath", _xgame_filesystem_getWritablePath, nullptr);

    olua_registerluatype<xgame::filesystem>(L, "kernel.filesystem");

    return 1;
}

static int _xgame_preferences___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (xgame::preferences *)olua_toobj(L, 1, "kernel.preferences");
    olua_push_cppobj(L, self, "kernel.preferences");

    olua_endinvoke(L);

    return 1;
}

static int _xgame_preferences_deleteKey(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */

    olua_check_string(L, 1, &arg1);

    // static void deleteKey(const char *key)
    xgame::preferences::deleteKey(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _xgame_preferences_flush(lua_State *L)
{
    olua_startinvoke(L);

    // static void flush()
    xgame::preferences::flush();

    olua_endinvoke(L);

    return 0;
}

static int _xgame_preferences_getBoolean1(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */
    bool arg2 = false;       /** defaultValue */

    olua_check_string(L, 1, &arg1);
    olua_check_bool(L, 2, &arg2);

    // static bool getBoolean(const char *key, @optional bool defaultValue)
    bool ret = (bool)xgame::preferences::getBoolean(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_preferences_getBoolean2(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */

    olua_check_string(L, 1, &arg1);

    // static bool getBoolean(const char *key, @optional bool defaultValue)
    bool ret = (bool)xgame::preferences::getBoolean(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_preferences_getBoolean(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_string(L, 1))) {
            // static bool getBoolean(const char *key, @optional bool defaultValue)
            return _xgame_preferences_getBoolean2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_string(L, 1)) && (olua_is_bool(L, 2))) {
            // static bool getBoolean(const char *key, @optional bool defaultValue)
            return _xgame_preferences_getBoolean1(L);
        // }
    }

    luaL_error(L, "method 'xgame::preferences::getBoolean' not support '%d' arguments", num_args);

    return 0;
}

static int _xgame_preferences_getDouble1(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */
    lua_Number arg2 = 0;       /** defaultValue */

    olua_check_string(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static double getDouble(const char *key, @optional double defaultValue)
    double ret = (double)xgame::preferences::getDouble(arg1, (double)arg2);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_preferences_getDouble2(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */

    olua_check_string(L, 1, &arg1);

    // static double getDouble(const char *key, @optional double defaultValue)
    double ret = (double)xgame::preferences::getDouble(arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_preferences_getDouble(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_string(L, 1))) {
            // static double getDouble(const char *key, @optional double defaultValue)
            return _xgame_preferences_getDouble2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_string(L, 1)) && (olua_is_number(L, 2))) {
            // static double getDouble(const char *key, @optional double defaultValue)
            return _xgame_preferences_getDouble1(L);
        // }
    }

    luaL_error(L, "method 'xgame::preferences::getDouble' not support '%d' arguments", num_args);

    return 0;
}

static int _xgame_preferences_getFloat1(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */
    lua_Number arg2 = 0;       /** defaultValue */

    olua_check_string(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static float getFloat(const char *key, @optional float defaultValue)
    float ret = (float)xgame::preferences::getFloat(arg1, (float)arg2);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_preferences_getFloat2(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */

    olua_check_string(L, 1, &arg1);

    // static float getFloat(const char *key, @optional float defaultValue)
    float ret = (float)xgame::preferences::getFloat(arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_preferences_getFloat(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_string(L, 1))) {
            // static float getFloat(const char *key, @optional float defaultValue)
            return _xgame_preferences_getFloat2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_string(L, 1)) && (olua_is_number(L, 2))) {
            // static float getFloat(const char *key, @optional float defaultValue)
            return _xgame_preferences_getFloat1(L);
        // }
    }

    luaL_error(L, "method 'xgame::preferences::getFloat' not support '%d' arguments", num_args);

    return 0;
}

static int _xgame_preferences_getInteger1(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */
    lua_Integer arg2 = 0;       /** defaultValue */

    olua_check_string(L, 1, &arg1);
    olua_check_int(L, 2, &arg2);

    // static int getInteger(const char *key, @optional int defaultValue)
    int ret = (int)xgame::preferences::getInteger(arg1, (int)arg2);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_preferences_getInteger2(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */

    olua_check_string(L, 1, &arg1);

    // static int getInteger(const char *key, @optional int defaultValue)
    int ret = (int)xgame::preferences::getInteger(arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_preferences_getInteger(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_string(L, 1))) {
            // static int getInteger(const char *key, @optional int defaultValue)
            return _xgame_preferences_getInteger2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_string(L, 1)) && (olua_is_int(L, 2))) {
            // static int getInteger(const char *key, @optional int defaultValue)
            return _xgame_preferences_getInteger1(L);
        // }
    }

    luaL_error(L, "method 'xgame::preferences::getInteger' not support '%d' arguments", num_args);

    return 0;
}

static int _xgame_preferences_getString1(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */
    const char *arg2 = nullptr;       /** defaultValue */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // static std::string getString(const char *key, @optional const char *defaultValue)
    std::string ret = (std::string)xgame::preferences::getString(arg1, arg2);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_preferences_getString2(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */

    olua_check_string(L, 1, &arg1);

    // static std::string getString(const char *key, @optional const char *defaultValue)
    std::string ret = (std::string)xgame::preferences::getString(arg1);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_preferences_getString(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_string(L, 1))) {
            // static std::string getString(const char *key, @optional const char *defaultValue)
            return _xgame_preferences_getString2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2))) {
            // static std::string getString(const char *key, @optional const char *defaultValue)
            return _xgame_preferences_getString1(L);
        // }
    }

    luaL_error(L, "method 'xgame::preferences::getString' not support '%d' arguments", num_args);

    return 0;
}

static int _xgame_preferences_setBoolean(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */
    bool arg2 = false;       /** value */

    olua_check_string(L, 1, &arg1);
    olua_check_bool(L, 2, &arg2);

    // static void setBoolean(const char *key, bool value)
    xgame::preferences::setBoolean(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _xgame_preferences_setDouble(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */
    lua_Number arg2 = 0;       /** value */

    olua_check_string(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static void setDouble(const char *key, double value)
    xgame::preferences::setDouble(arg1, (double)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _xgame_preferences_setFloat(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */
    lua_Number arg2 = 0;       /** value */

    olua_check_string(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static void setFloat(const char *key, float value)
    xgame::preferences::setFloat(arg1, (float)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _xgame_preferences_setInteger(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */
    lua_Integer arg2 = 0;       /** value */

    olua_check_string(L, 1, &arg1);
    olua_check_int(L, 2, &arg2);

    // static void setInteger(const char *key, int value)
    xgame::preferences::setInteger(arg1, (int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _xgame_preferences_setString(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */
    const char *arg2 = nullptr;       /** value */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // static void setString(const char *key, const char *value)
    xgame::preferences::setString(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_xgame_preferences(lua_State *L)
{
    oluacls_class(L, "kernel.preferences", nullptr);
    oluacls_func(L, "__move", _xgame_preferences___move);
    oluacls_func(L, "deleteKey", _xgame_preferences_deleteKey);
    oluacls_func(L, "flush", _xgame_preferences_flush);
    oluacls_func(L, "getBoolean", _xgame_preferences_getBoolean);
    oluacls_func(L, "getDouble", _xgame_preferences_getDouble);
    oluacls_func(L, "getFloat", _xgame_preferences_getFloat);
    oluacls_func(L, "getInteger", _xgame_preferences_getInteger);
    oluacls_func(L, "getString", _xgame_preferences_getString);
    oluacls_func(L, "setBoolean", _xgame_preferences_setBoolean);
    oluacls_func(L, "setDouble", _xgame_preferences_setDouble);
    oluacls_func(L, "setFloat", _xgame_preferences_setFloat);
    oluacls_func(L, "setInteger", _xgame_preferences_setInteger);
    oluacls_func(L, "setString", _xgame_preferences_setString);

    olua_registerluatype<xgame::preferences>(L, "kernel.preferences");

    return 1;
}

#define makeTimerDelayTag(tag) ("delayTag." + tag)

static int _xgame_timer___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (xgame::timer *)olua_toobj(L, 1, "kernel.timer");
    olua_push_cppobj(L, self, "kernel.timer");

    olua_endinvoke(L);

    return 1;
}

static int _xgame_timer_createTag(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string createTag()
    std::string ret = (std::string)xgame::timer::createTag();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_timer_delay(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */
    std::function<void()> arg2;       /** callback */

    olua_check_number(L, 1, &arg1);

    void *self_obj = (void *)olua_pushclassobj(L, "kernel.timer");
    std::string tag = "delay";
    std::string func = olua_setcallback(L, self_obj, tag.c_str(), 2, OLUA_TAG_NEW);
    lua_Unsigned ctx = olua_context(L);
    arg2 = [self_obj, func, ctx]() {
        lua_State *L = olua_mainthread(NULL);

        if (L != NULL && (olua_context(L) == ctx)) {
            int top = lua_gettop(L);

            olua_callback(L, self_obj, func.c_str(), 0);

            olua_removecallback(L, self_obj, func.c_str(), OLUA_TAG_WHOLE);

            lua_settop(L, top);
        }
    };

    // static void delay(float time, @local const std::function<void ()> callback)
    xgame::timer::delay((float)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _xgame_timer_delayWithTag(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */
    std::string arg2;       /** tag */
    std::function<void()> arg3;       /** callback */

    olua_check_number(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    void *self_obj = (void *)olua_pushclassobj(L, "kernel.timer");
    std::string tag = makeTimerDelayTag(arg2);
    std::string func = olua_setcallback(L, self_obj, tag.c_str(), 3, OLUA_TAG_REPLACE);
    lua_Unsigned ctx = olua_context(L);
    arg3 = [self_obj, func, ctx]() {
        lua_State *L = olua_mainthread(NULL);

        if (L != NULL && (olua_context(L) == ctx)) {
            int top = lua_gettop(L);

            olua_callback(L, self_obj, func.c_str(), 0);

            olua_removecallback(L, self_obj, func.c_str(), OLUA_TAG_WHOLE);

            lua_settop(L, top);
        }
    };

    // static void delayWithTag(float time, const std::string &tag, @local std::function<void ()> callback)
    xgame::timer::delayWithTag((float)arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _xgame_timer_killDelay(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** tag */

    olua_check_std_string(L, 1, &arg1);

    std::string tag = makeTimerDelayTag(arg1);
    void *self_obj = (void *)olua_pushclassobj(L, "kernel.timer");
    olua_removecallback(L, self_obj, tag.c_str(), OLUA_TAG_SUBEQUAL);

    // static void killDelay(const std::string &tag)
    xgame::timer::killDelay(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _xgame_timer_schedule(lua_State *L)
{
    olua_startinvoke(L);

    float interval = (float)olua_checknumber(L, 1);
    uint32_t callback = olua_reffunc(L, 2);
    uint32_t id = xgame::timer::schedule(interval, [callback](float dt) {
        lua_State *L = olua_mainthread(NULL);
        if (L != NULL) {
            int top = lua_gettop(L);
            olua_geterrorfunc(L);
            olua_getref(L, callback);
            if (lua_isfunction(L, -1)) {
                lua_pushnumber(L, dt);
                lua_pcall(L, 1, 0, top + 1);
            }
            lua_settop(L, top);
        }
    });
    lua_pushinteger(L, ((uint64_t)callback << 32) | (uint64_t)id);

    olua_endinvoke(L);

    return 1;
}

static int _xgame_timer_unschedule(lua_State *L)
{
    olua_startinvoke(L);

    uint64_t value = olua_checkinteger(L, 1);
    uint32_t callback = value >> 32;
    uint32_t id = value & 0xFFFFFFFF;
    olua_unref(L, callback);
    xgame::timer::unschedule(id);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_xgame_timer(lua_State *L)
{
    oluacls_class(L, "kernel.timer", nullptr);
    oluacls_func(L, "__move", _xgame_timer___move);
    oluacls_func(L, "createTag", _xgame_timer_createTag);
    oluacls_func(L, "delay", _xgame_timer_delay);
    oluacls_func(L, "delayWithTag", _xgame_timer_delayWithTag);
    oluacls_func(L, "killDelay", _xgame_timer_killDelay);
    oluacls_func(L, "schedule", _xgame_timer_schedule);
    oluacls_func(L, "unschedule", _xgame_timer_unschedule);

    olua_registerluatype<xgame::timer>(L, "kernel.timer");

    return 1;
}

static int _xgame_window_convertToCameraSpace(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Rect rect;
    cocos2d::Vec3 out;
    auto director = cocos2d::Director::getInstance();
    auto pt = cocos2d::Vec2(olua_checknumber(L, 1), olua_checknumber(L, 2));
    auto runningScene = director->getRunningScene();
    auto w2l = runningScene->getWorldToNodeTransform();
    rect.size = director->getOpenGLView()->getDesignResolutionSize();
    cocos2d::isScreenPointInRect(pt, runningScene->getDefaultCamera(), w2l, rect, &out);
    lua_pushnumber(L, out.x);
    lua_pushnumber(L, out.y);

    olua_endinvoke(L);

    return 2;
}

static int _xgame_window_getDesignSize(lua_State *L)
{
    olua_startinvoke(L);

    auto size = cocos2d::Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
    lua_pushnumber(L, size.width);
    lua_pushnumber(L, size.height);

    olua_endinvoke(L);

    return 2;
}

static int _xgame_window_getFrameSize(lua_State *L)
{
    olua_startinvoke(L);

    auto size = cocos2d::Director::getInstance()->getOpenGLView()->getFrameSize();
    lua_pushnumber(L, size.width);
    lua_pushnumber(L, size.height);

    olua_endinvoke(L);

    return 2;
}

static int _xgame_window_getVisibleBounds(lua_State *L)
{
    olua_startinvoke(L);

    auto rect = cocos2d::Director::getInstance()->getOpenGLView()->getVisibleRect();
    lua_pushinteger(L, rect.getMinX());
    lua_pushinteger(L, rect.getMaxX());
    lua_pushinteger(L, rect.getMaxY());
    lua_pushinteger(L, rect.getMinY());

    olua_endinvoke(L);

    return 4;
}

static int _xgame_window_getVisibleSize(lua_State *L)
{
    olua_startinvoke(L);

    auto rect = cocos2d::Director::getInstance()->getOpenGLView()->getVisibleRect();
    lua_pushinteger(L, rect.size.width);
    lua_pushinteger(L, rect.size.height);

    olua_endinvoke(L);

    return 2;
}

static int _xgame_window_setDesignSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Director::getInstance()->getOpenGLView()->setDesignResolutionSize(
        (float)olua_checknumber(L, 1), (float)olua_checknumber(L, 2),
        (ResolutionPolicy)olua_checkinteger(L, 3));

    olua_endinvoke(L);

    return 0;
}

static int _xgame_window_setFrameSize(lua_State *L)
{
    olua_startinvoke(L);

    auto glView = cocos2d::Director::getInstance()->getOpenGLView();
    float width = (float)olua_checknumber(L, 1);
    float height = (float)olua_checknumber(L, 2);
    xgame::preferences::setFloat(CONF_WINDOW_WIDTH, width);
    xgame::preferences::setFloat(CONF_WINDOW_HEIGHT, height);
    glView->setFrameSize(width, height);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_xgame_window(lua_State *L)
{
    oluacls_class(L, "kernel.window", nullptr);
    oluacls_func(L, "convertToCameraSpace", _xgame_window_convertToCameraSpace);
    oluacls_func(L, "getDesignSize", _xgame_window_getDesignSize);
    oluacls_func(L, "getFrameSize", _xgame_window_getFrameSize);
    oluacls_func(L, "getVisibleBounds", _xgame_window_getVisibleBounds);
    oluacls_func(L, "getVisibleSize", _xgame_window_getVisibleSize);
    oluacls_func(L, "setDesignSize", _xgame_window_setDesignSize);
    oluacls_func(L, "setFrameSize", _xgame_window_setFrameSize);

    return 1;
}

static int luaopen_xgame_downloader_FileState(lua_State *L)
{
    oluacls_class(L, "kernel.downloader.FileState", nullptr);
    oluacls_const_integer(L, "INVALID", (lua_Integer)xgame::downloader::FileState::INVALID);
    oluacls_const_integer(L, "IOERROR", (lua_Integer)xgame::downloader::FileState::IOERROR);
    oluacls_const_integer(L, "LOADED", (lua_Integer)xgame::downloader::FileState::LOADED);
    oluacls_const_integer(L, "PENDING", (lua_Integer)xgame::downloader::FileState::PENDING);

    olua_registerluatype<xgame::downloader::FileState>(L, "kernel.downloader.FileState");

    return 1;
}

static int _xgame_downloader___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (xgame::downloader *)olua_toobj(L, 1, "kernel.downloader");
    olua_push_cppobj(L, self, "kernel.downloader");

    olua_endinvoke(L);

    return 1;
}

static int _xgame_downloader_end(lua_State *L)
{
    olua_startinvoke(L);

    // static void end()
    xgame::downloader::end();

    olua_endinvoke(L);

    return 0;
}

static int _xgame_downloader_init(lua_State *L)
{
    olua_startinvoke(L);

    // static void init()
    xgame::downloader::init();

    olua_endinvoke(L);

    return 0;
}

static int _xgame_downloader_load(lua_State *L)
{
    olua_startinvoke(L);

    xgame::downloader::FileTask arg1;       /** task */

    auto_olua_check_xgame_downloader_FileTask(L, 1, &arg1);

    // static void load(const xgame::downloader::FileTask &task)
    xgame::downloader::load(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _xgame_downloader_setDispatcher(lua_State *L)
{
    olua_startinvoke(L);

    std::function<void(const xgame::downloader::FileTask &)> arg1;       /** callback */

    void *self_obj = (void *)olua_pushclassobj(L, "kernel.downloader");
    std::string tag = "Dispatcher";
    std::string func = olua_setcallback(L, self_obj, tag.c_str(), 1, OLUA_TAG_REPLACE);
    lua_Unsigned ctx = olua_context(L);
    arg1 = [self_obj, func, ctx](const xgame::downloader::FileTask &arg1) {
        lua_State *L = olua_mainthread(NULL);

        if (L != NULL && (olua_context(L) == ctx)) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            auto_olua_push_xgame_downloader_FileTask(L, &arg1);
            olua_disable_objpool(L);

            olua_callback(L, self_obj, func.c_str(), 1);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // static void setDispatcher(@local const std::function<void (const FileTask &)> callback)
    xgame::downloader::setDispatcher(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_xgame_downloader(lua_State *L)
{
    oluacls_class(L, "kernel.downloader", nullptr);
    oluacls_func(L, "__move", _xgame_downloader___move);
    oluacls_func(L, "end", _xgame_downloader_end);
    oluacls_func(L, "init", _xgame_downloader_init);
    oluacls_func(L, "load", _xgame_downloader_load);
    oluacls_func(L, "setDispatcher", _xgame_downloader_setDispatcher);

    olua_registerluatype<xgame::downloader>(L, "kernel.downloader");

    return 1;
}

static int _xgame_MaskLayout___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (xgame::MaskLayout *)olua_toobj(L, 1, "kernel.MaskLayout");
    olua_push_cppobj(L, self, "kernel.MaskLayout");

    olua_endinvoke(L);

    return 1;
}

static int _xgame_MaskLayout_create(lua_State *L)
{
    olua_startinvoke(L);

    // static xgame::MaskLayout *create()
    xgame::MaskLayout *ret = (xgame::MaskLayout *)xgame::MaskLayout::create();
    int num_ret = olua_push_cppobj(L, ret, "kernel.MaskLayout");

    olua_endinvoke(L);

    return num_ret;
}

static int _xgame_MaskLayout_getClippingNode(lua_State *L)
{
    olua_startinvoke(L);

    xgame::MaskLayout *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "kernel.MaskLayout");

    // cocos2d::DrawNode *getClippingNode()
    cocos2d::DrawNode *ret = (cocos2d::DrawNode *)self->getClippingNode();
    int num_ret = olua_push_cppobj(L, ret, "cc.DrawNode");

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_xgame_MaskLayout(lua_State *L)
{
    oluacls_class(L, "kernel.MaskLayout", "ccui.Layout");
    oluacls_func(L, "__move", _xgame_MaskLayout___move);
    oluacls_func(L, "create", _xgame_MaskLayout_create);
    oluacls_func(L, "getClippingNode", _xgame_MaskLayout_getClippingNode);
    oluacls_prop(L, "clippingNode", _xgame_MaskLayout_getClippingNode, nullptr);

    olua_registerluatype<xgame::MaskLayout>(L, "kernel.MaskLayout");

    return 1;
}

int luaopen_xgame(lua_State *L)
{
    olua_require(L, "kernel.SceneNoCamera", luaopen_xgame_SceneNoCamera);
    olua_require(L, "kernel.Permission", luaopen_xgame_Permission);
    olua_require(L, "kernel.PermissionStatus", luaopen_xgame_PermissionStatus);
    olua_require(L, "kernel.runtime", luaopen_xgame_runtime);
    olua_require(L, "kernel.filesystem", luaopen_xgame_filesystem);
    olua_require(L, "kernel.preferences", luaopen_xgame_preferences);
    olua_require(L, "kernel.timer", luaopen_xgame_timer);
    olua_require(L, "kernel.window", luaopen_xgame_window);
    olua_require(L, "kernel.downloader.FileState", luaopen_xgame_downloader_FileState);
    olua_require(L, "kernel.downloader", luaopen_xgame_downloader);
    olua_require(L, "kernel.MaskLayout", luaopen_xgame_MaskLayout);
    return 0;
}
