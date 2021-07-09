//
// AUTO BUILD, DON'T MODIFY!
//
#include "lua_xgame.h"

int olua_unpack_cclua_window_Bounds(lua_State *L, const cclua::window::Bounds *value)
{
    if (value) {
        lua_pushnumber(L, (lua_Number)value->getMinX());
        lua_pushnumber(L, (lua_Number)value->getMaxX());
        lua_pushnumber(L, (lua_Number)value->getMaxY());
        lua_pushnumber(L, (lua_Number)value->getMinY());
    } else {
        lua_pushnumber(L, 0);
        lua_pushnumber(L, 0);
        lua_pushnumber(L, 0);
        lua_pushnumber(L, 0);
    }
    return 4;
}

int olua_push_cclua_downloader_FileTask(lua_State *L, const cclua::downloader::FileTask *value)
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

void olua_check_cclua_downloader_FileTask(lua_State *L, int idx, cclua::downloader::FileTask *value)
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
        value->state = (cclua::downloader::FileState)arg4;
    }
    lua_pop(L, 1);
}

bool olua_is_cclua_downloader_FileTask(lua_State *L, int idx)
{
    return olua_istable(L, idx) && olua_hasfield(L, idx, "path") && olua_hasfield(L, idx, "url");
}

void olua_pack_cclua_downloader_FileTask(lua_State *L, int idx, cclua::downloader::FileTask *value)
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
    value->state = (cclua::downloader::FileState)arg4;
}

int olua_unpack_cclua_downloader_FileTask(lua_State *L, const cclua::downloader::FileTask *value)
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

bool olua_ispack_cclua_downloader_FileTask(lua_State *L, int idx)
{
    return olua_is_std_string(L, idx + 0) && olua_is_std_string(L, idx + 1) && olua_is_std_string(L, idx + 2) && olua_is_uint(L, idx + 3);
}

static int _cclua_SceneNoCamera___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::SceneNoCamera *)olua_toobj(L, 1, "cclua.SceneNoCamera");
    olua_push_cppobj(L, self, "cclua.SceneNoCamera");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_SceneNoCamera_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cclua::SceneNoCamera *create()
    cclua::SceneNoCamera *ret = cclua::SceneNoCamera::create();
    int num_ret = olua_push_cppobj(L, ret, "cclua.SceneNoCamera");

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_SceneNoCamera_createWithPhysics(lua_State *L)
{
    olua_startinvoke(L);

    // static cclua::SceneNoCamera *createWithPhysics()
    cclua::SceneNoCamera *ret = cclua::SceneNoCamera::createWithPhysics();
    int num_ret = olua_push_cppobj(L, ret, "cclua.SceneNoCamera");

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_SceneNoCamera_createWithSize(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */

    olua_check_cocos2d_Size(L, 1, &arg1);

    // static cclua::SceneNoCamera *createWithSize(const cocos2d::Size &size)
    cclua::SceneNoCamera *ret = cclua::SceneNoCamera::createWithSize(arg1);
    int num_ret = olua_push_cppobj(L, ret, "cclua.SceneNoCamera");

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_SceneNoCamera_new(lua_State *L)
{
    olua_startinvoke(L);

    // SceneNoCamera()
    cclua::SceneNoCamera *ret = new cclua::SceneNoCamera();
    int num_ret = olua_push_cppobj(L, ret, "cclua.SceneNoCamera");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int luaopen_cclua_SceneNoCamera(lua_State *L)
{
    oluacls_class(L, "cclua.SceneNoCamera", "cc.Scene");
    oluacls_func(L, "__move", _cclua_SceneNoCamera___move);
    oluacls_func(L, "create", _cclua_SceneNoCamera_create);
    oluacls_func(L, "createWithPhysics", _cclua_SceneNoCamera_createWithPhysics);
    oluacls_func(L, "createWithSize", _cclua_SceneNoCamera_createWithSize);
    oluacls_func(L, "new", _cclua_SceneNoCamera_new);

    olua_registerluatype<cclua::SceneNoCamera>(L, "cclua.SceneNoCamera");

    return 1;
}

static int luaopen_cclua_Permission(lua_State *L)
{
    oluacls_class(L, "cclua.Permission", nullptr);
    oluacls_const_integer(L, "AUDIO", (lua_Integer)cclua::Permission::AUDIO);
    oluacls_const_integer(L, "CAMERA", (lua_Integer)cclua::Permission::CAMERA);
    oluacls_const_integer(L, "IDFA", (lua_Integer)cclua::Permission::IDFA);
    oluacls_const_integer(L, "PHOTO", (lua_Integer)cclua::Permission::PHOTO);

    olua_registerluatype<cclua::Permission>(L, "cclua.Permission");

    return 1;
}

static int luaopen_cclua_PermissionStatus(lua_State *L)
{
    oluacls_class(L, "cclua.PermissionStatus", nullptr);
    oluacls_const_integer(L, "AUTHORIZED", (lua_Integer)cclua::PermissionStatus::AUTHORIZED);
    oluacls_const_integer(L, "DENIED", (lua_Integer)cclua::PermissionStatus::DENIED);
    oluacls_const_integer(L, "NOT_DETERMINED", (lua_Integer)cclua::PermissionStatus::NOT_DETERMINED);
    oluacls_const_integer(L, "RESTRICTED", (lua_Integer)cclua::PermissionStatus::RESTRICTED);

    olua_registerluatype<cclua::PermissionStatus>(L, "cclua.PermissionStatus");

    return 1;
}

static int _cclua_runtime___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::runtime *)olua_toobj(L, 1, "cclua.runtime");
    olua_push_cppobj(L, self, "cclua.runtime");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_runtime_alert(lua_State *L)
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
    olua_check_std_function(L, 5, &arg5);

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.runtime");
    std::string cb_tag = "alert";
    std::string cb_name = olua_setcallback(L, cb_store, cb_tag.c_str(), 5, OLUA_TAG_NEW);
    lua_Integer cb_ctx = olua_context(L);
    arg5 = [cb_store, cb_name, cb_ctx](bool arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (L != NULL && olua_context(L) == cb_ctx) {
            int top = lua_gettop(L);
            olua_push_bool(L, arg1);

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            olua_removecallback(L, cb_store, cb_name.c_str(), OLUA_TAG_WHOLE);

            lua_settop(L, top);
        }
    };

    // static void alert(const std::string &title, const std::string &message, const std::string &ok, const std::string &no, @local const std::function<void (bool)> callback)
    cclua::runtime::alert(arg1, arg2, arg3, arg4, arg5);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_canOpenURL(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** uri */

    olua_check_std_string(L, 1, &arg1);

    // static bool canOpenURL(const std::string &uri)
    bool ret = cclua::runtime::canOpenURL(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_capture1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Node *arg1 = nullptr;       /** node */
    lua_Number arg2 = 0;       /** width */
    lua_Number arg3 = 0;       /** height */
    lua_Unsigned arg4 = 0;       /** format */
    lua_Unsigned arg5 = 0;       /** depthStencilFormat */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Node");
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_uint(L, 4, &arg4);
    olua_check_uint(L, 5, &arg5);

    // static cocos2d::RenderTexture *capture(cocos2d::Node *node, float width, float height, @optional cocos2d::backend::PixelFormat format, @optional cocos2d::backend::PixelFormat depthStencilFormat)
    cocos2d::RenderTexture *ret = cclua::runtime::capture(arg1, (float)arg2, (float)arg3, (cocos2d::backend::PixelFormat)arg4, (cocos2d::backend::PixelFormat)arg5);
    int num_ret = olua_push_cppobj(L, ret, "cc.RenderTexture");

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_capture2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Node *arg1 = nullptr;       /** node */
    lua_Number arg2 = 0;       /** width */
    lua_Number arg3 = 0;       /** height */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Node");
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);

    // static cocos2d::RenderTexture *capture(cocos2d::Node *node, float width, float height, @optional cocos2d::backend::PixelFormat format, @optional cocos2d::backend::PixelFormat depthStencilFormat)
    cocos2d::RenderTexture *ret = cclua::runtime::capture(arg1, (float)arg2, (float)arg3);
    int num_ret = olua_push_cppobj(L, ret, "cc.RenderTexture");

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_capture3(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Node *arg1 = nullptr;       /** node */
    lua_Number arg2 = 0;       /** width */
    lua_Number arg3 = 0;       /** height */
    lua_Unsigned arg4 = 0;       /** format */

    olua_check_cppobj(L, 1, (void **)&arg1, "cc.Node");
    olua_check_number(L, 2, &arg2);
    olua_check_number(L, 3, &arg3);
    olua_check_uint(L, 4, &arg4);

    // static cocos2d::RenderTexture *capture(cocos2d::Node *node, float width, float height, @optional cocos2d::backend::PixelFormat format, @optional cocos2d::backend::PixelFormat depthStencilFormat)
    cocos2d::RenderTexture *ret = cclua::runtime::capture(arg1, (float)arg2, (float)arg3, (cocos2d::backend::PixelFormat)arg4);
    int num_ret = olua_push_cppobj(L, ret, "cc.RenderTexture");

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_capture(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 3) {
        // if ((olua_is_cppobj(L, 1, "cc.Node")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3))) {
            // static cocos2d::RenderTexture *capture(cocos2d::Node *node, float width, float height, @optional cocos2d::backend::PixelFormat format, @optional cocos2d::backend::PixelFormat depthStencilFormat)
            return _cclua_runtime_capture2(L);
        // }
    }

    if (num_args == 4) {
        // if ((olua_is_cppobj(L, 1, "cc.Node")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_uint(L, 4))) {
            // static cocos2d::RenderTexture *capture(cocos2d::Node *node, float width, float height, @optional cocos2d::backend::PixelFormat format, @optional cocos2d::backend::PixelFormat depthStencilFormat)
            return _cclua_runtime_capture3(L);
        // }
    }

    if (num_args == 5) {
        // if ((olua_is_cppobj(L, 1, "cc.Node")) && (olua_is_number(L, 2)) && (olua_is_number(L, 3)) && (olua_is_uint(L, 4)) && (olua_is_uint(L, 5))) {
            // static cocos2d::RenderTexture *capture(cocos2d::Node *node, float width, float height, @optional cocos2d::backend::PixelFormat format, @optional cocos2d::backend::PixelFormat depthStencilFormat)
            return _cclua_runtime_capture1(L);
        // }
    }

    luaL_error(L, "method 'cclua::runtime::capture' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_runtime_clearStorage(lua_State *L)
{
    olua_startinvoke(L);

    // static void clearStorage()
    cclua::runtime::clearStorage();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_disableReport(lua_State *L)
{
    olua_startinvoke(L);

    // static void disableReport()
    cclua::runtime::disableReport();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_gc(lua_State *L)
{
    olua_startinvoke(L);

    // static void gc()
    cclua::runtime::gc();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_getAppBuild(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getAppBuild()
    const std::string ret = cclua::runtime::getAppBuild();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getAppVersion(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getAppVersion()
    const std::string ret = cclua::runtime::getAppVersion();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getAudioSessionCatalog(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getAudioSessionCatalog()
    const std::string ret = cclua::runtime::getAudioSessionCatalog();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getChannel(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getChannel()
    const std::string ret = cclua::runtime::getChannel();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getCocosVersion(lua_State *L)
{
    olua_startinvoke(L);

    // static const uint64_t getCocosVersion()
    const uint64_t ret = cclua::runtime::getCocosVersion();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getDeviceInfo(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getDeviceInfo()
    const std::string ret = cclua::runtime::getDeviceInfo();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getLanguage(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getLanguage()
    const std::string ret = cclua::runtime::getLanguage();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getLogPath(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getLogPath()
    const std::string ret = cclua::runtime::getLogPath();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getManifestVersion(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getManifestVersion()
    const std::string ret = cclua::runtime::getManifestVersion();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getNetworkStatus(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getNetworkStatus()
    const std::string ret = cclua::runtime::getNetworkStatus();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getOS(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getOS()
    const std::string ret = cclua::runtime::getOS();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getPackageName(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getPackageName()
    const std::string ret = cclua::runtime::getPackageName();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getPaste(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getPaste()
    const std::string ret = cclua::runtime::getPaste();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getPermissionStatus(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** permission */

    olua_check_uint(L, 1, &arg1);

    // static const cclua::PermissionStatus getPermissionStatus(cclua::Permission permission)
    const cclua::PermissionStatus ret = cclua::runtime::getPermissionStatus((cclua::Permission)arg1);
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getSampleCount(lua_State *L)
{
    olua_startinvoke(L);

    // static unsigned int getSampleCount()
    unsigned int ret = cclua::runtime::getSampleCount();
    int num_ret = olua_push_uint(L, (lua_Unsigned)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getTime(lua_State *L)
{
    olua_startinvoke(L);

    // static float getTime()
    float ret = cclua::runtime::getTime();
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_getVersion(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getVersion()
    const std::string ret = cclua::runtime::getVersion();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_isCocosThread(lua_State *L)
{
    olua_startinvoke(L);

    // static bool isCocosThread()
    bool ret = cclua::runtime::isCocosThread();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_isDebug(lua_State *L)
{
    olua_startinvoke(L);

    // static bool isDebug()
    bool ret = cclua::runtime::isDebug();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_isRestarting(lua_State *L)
{
    olua_startinvoke(L);

    // static bool isRestarting()
    bool ret = cclua::runtime::isRestarting();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_launch(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** scriptPath */

    olua_check_std_string(L, 1, &arg1);

    // static bool launch(const std::string &scriptPath)
    bool ret = cclua::runtime::launch(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_openURL1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** uri */
    std::function<void(bool)> arg2;       /** callback */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_function(L, 2, &arg2);

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.runtime");
    std::string cb_tag = "openURL";
    std::string cb_name;
    if (olua_is_std_function(L, 2)) {
        cb_name = olua_setcallback(L, cb_store, cb_tag.c_str(), 2, OLUA_TAG_NEW);
        lua_Integer cb_ctx = olua_context(L);
        arg2 = [cb_store, cb_name, cb_ctx](bool arg1) {
            lua_State *L = olua_mainthread(NULL);
            olua_checkhostthread();

            if (L != NULL && olua_context(L) == cb_ctx) {
                int top = lua_gettop(L);
                olua_push_bool(L, arg1);

                olua_callback(L, cb_store, cb_name.c_str(), 1);

                olua_removecallback(L, cb_store, cb_name.c_str(), OLUA_TAG_WHOLE);

                lua_settop(L, top);
            }
        };
    } else {
        arg2 = nullptr;
    }

    // static void openURL(const std::string &uri, @local @optional const std::function<void (bool)> callback)
    cclua::runtime::openURL(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_openURL2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** uri */

    olua_check_std_string(L, 1, &arg1);

    // static void openURL(const std::string &uri, @local @optional const std::function<void (bool)> callback)
    cclua::runtime::openURL(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_openURL(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static void openURL(const std::string &uri, @local @optional const std::function<void (bool)> callback)
            return _cclua_runtime_openURL2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_std_function(L, 2))) {
            // static void openURL(const std::string &uri, @local @optional const std::function<void (bool)> callback)
            return _cclua_runtime_openURL1(L);
        // }
    }

    luaL_error(L, "method 'cclua::runtime::openURL' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_runtime_printSupport(lua_State *L)
{
    olua_startinvoke(L);

    // static void printSupport()
    cclua::runtime::printSupport();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_requestPermission(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** permission */
    std::function<void(cclua::PermissionStatus)> arg2;       /** callback */

    olua_check_uint(L, 1, &arg1);
    olua_check_std_function(L, 2, &arg2);

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.runtime");
    std::string cb_tag = "requestPermission";
    std::string cb_name = olua_setcallback(L, cb_store, cb_tag.c_str(), 2, OLUA_TAG_NEW);
    lua_Integer cb_ctx = olua_context(L);
    arg2 = [cb_store, cb_name, cb_ctx](cclua::PermissionStatus arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (L != NULL && olua_context(L) == cb_ctx) {
            int top = lua_gettop(L);
            olua_push_uint(L, (lua_Unsigned)arg1);

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            olua_removecallback(L, cb_store, cb_name.c_str(), OLUA_TAG_WHOLE);

            lua_settop(L, top);
        }
    };

    // static void requestPermission(cclua::Permission permission, @local const std::function<void (cclua::PermissionStatus)> callback)
    cclua::runtime::requestPermission((cclua::Permission)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_restart(lua_State *L)
{
    olua_startinvoke(L);

    // static bool restart()
    bool ret = cclua::runtime::restart();
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_setAudioSessionCatalog(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** catalog */

    olua_check_std_string(L, 1, &arg1);

    // static void setAudioSessionCatalog(const std::string &catalog)
    cclua::runtime::setAudioSessionCatalog(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_setDispatcher(lua_State *L)
{
    olua_startinvoke(L);

    std::function<void(const std::string &, const std::string &)> arg1;       /** dispatcher */

    olua_check_std_function(L, 1, &arg1);

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.runtime");
    std::string cb_tag = "Dispatcher";
    std::string cb_name = olua_setcallback(L, cb_store, cb_tag.c_str(), 1, OLUA_TAG_REPLACE);
    lua_Integer cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](const std::string &arg1, const std::string &arg2) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (L != NULL && olua_context(L) == cb_ctx) {
            int top = lua_gettop(L);
            olua_push_std_string(L, arg1);
            olua_push_std_string(L, arg2);

            olua_callback(L, cb_store, cb_name.c_str(), 2);

            lua_settop(L, top);
        }
    };

    // static void setDispatcher(@local const std::function<void (const std::string &, const std::string &)> &dispatcher)
    cclua::runtime::setDispatcher(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_setLogPath(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static void setLogPath(const std::string &path)
    cclua::runtime::setLogPath(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_setManifestVersion(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** version */

    olua_check_std_string(L, 1, &arg1);

    // static void setManifestVersion(const std::string &version)
    cclua::runtime::setManifestVersion(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_setPaste(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** text */

    olua_check_std_string(L, 1, &arg1);

    // static void setPaste(const std::string &text)
    cclua::runtime::setPaste(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_setSampleCount(lua_State *L)
{
    olua_startinvoke(L);

    lua_Unsigned arg1 = 0;       /** samples */

    olua_check_uint(L, 1, &arg1);

    // static void setSampleCount(unsigned int samples)
    cclua::runtime::setSampleCount((unsigned int)arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_support(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** api */

    olua_check_std_string(L, 1, &arg1);

    // static bool support(const std::string &api)
    bool ret = cclua::runtime::support(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_runtime_testCrash(lua_State *L)
{
    olua_startinvoke(L);

    cclua::runtime::log("test native crash!!!!");
    char *prt = NULL;
    *prt = 0;

    olua_endinvoke(L);

    return 0;
}

static int _cclua_runtime_useSystemFrameRate(lua_State *L)
{
    olua_startinvoke(L);

    bool arg1 = false;       /** use */

    olua_check_bool(L, 1, &arg1);

    // static void useSystemFrameRate(bool use)
    cclua::runtime::useSystemFrameRate(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cclua_runtime(lua_State *L)
{
    oluacls_class(L, "cclua.runtime", nullptr);
    oluacls_func(L, "__move", _cclua_runtime___move);
    oluacls_func(L, "alert", _cclua_runtime_alert);
    oluacls_func(L, "canOpenURL", _cclua_runtime_canOpenURL);
    oluacls_func(L, "capture", _cclua_runtime_capture);
    oluacls_func(L, "clearStorage", _cclua_runtime_clearStorage);
    oluacls_func(L, "disableReport", _cclua_runtime_disableReport);
    oluacls_func(L, "gc", _cclua_runtime_gc);
    oluacls_func(L, "getAppBuild", _cclua_runtime_getAppBuild);
    oluacls_func(L, "getAppVersion", _cclua_runtime_getAppVersion);
    oluacls_func(L, "getAudioSessionCatalog", _cclua_runtime_getAudioSessionCatalog);
    oluacls_func(L, "getChannel", _cclua_runtime_getChannel);
    oluacls_func(L, "getCocosVersion", _cclua_runtime_getCocosVersion);
    oluacls_func(L, "getDeviceInfo", _cclua_runtime_getDeviceInfo);
    oluacls_func(L, "getLanguage", _cclua_runtime_getLanguage);
    oluacls_func(L, "getLogPath", _cclua_runtime_getLogPath);
    oluacls_func(L, "getManifestVersion", _cclua_runtime_getManifestVersion);
    oluacls_func(L, "getNetworkStatus", _cclua_runtime_getNetworkStatus);
    oluacls_func(L, "getOS", _cclua_runtime_getOS);
    oluacls_func(L, "getPackageName", _cclua_runtime_getPackageName);
    oluacls_func(L, "getPaste", _cclua_runtime_getPaste);
    oluacls_func(L, "getPermissionStatus", _cclua_runtime_getPermissionStatus);
    oluacls_func(L, "getSampleCount", _cclua_runtime_getSampleCount);
    oluacls_func(L, "getTime", _cclua_runtime_getTime);
    oluacls_func(L, "getVersion", _cclua_runtime_getVersion);
    oluacls_func(L, "isCocosThread", _cclua_runtime_isCocosThread);
    oluacls_func(L, "isDebug", _cclua_runtime_isDebug);
    oluacls_func(L, "isRestarting", _cclua_runtime_isRestarting);
    oluacls_func(L, "launch", _cclua_runtime_launch);
    oluacls_func(L, "openURL", _cclua_runtime_openURL);
    oluacls_func(L, "printSupport", _cclua_runtime_printSupport);
    oluacls_func(L, "requestPermission", _cclua_runtime_requestPermission);
    oluacls_func(L, "restart", _cclua_runtime_restart);
    oluacls_func(L, "setAudioSessionCatalog", _cclua_runtime_setAudioSessionCatalog);
    oluacls_func(L, "setDispatcher", _cclua_runtime_setDispatcher);
    oluacls_func(L, "setLogPath", _cclua_runtime_setLogPath);
    oluacls_func(L, "setManifestVersion", _cclua_runtime_setManifestVersion);
    oluacls_func(L, "setPaste", _cclua_runtime_setPaste);
    oluacls_func(L, "setSampleCount", _cclua_runtime_setSampleCount);
    oluacls_func(L, "support", _cclua_runtime_support);
    oluacls_func(L, "testCrash", _cclua_runtime_testCrash);
    oluacls_func(L, "useSystemFrameRate", _cclua_runtime_useSystemFrameRate);
    oluacls_prop(L, "appBuild", _cclua_runtime_getAppBuild, nullptr);
    oluacls_prop(L, "appVersion", _cclua_runtime_getAppVersion, nullptr);
    oluacls_prop(L, "audioSessionCatalog", _cclua_runtime_getAudioSessionCatalog, _cclua_runtime_setAudioSessionCatalog);
    oluacls_prop(L, "channel", _cclua_runtime_getChannel, nullptr);
    oluacls_prop(L, "cocosThread", _cclua_runtime_isCocosThread, nullptr);
    oluacls_prop(L, "cocosVersion", _cclua_runtime_getCocosVersion, nullptr);
    oluacls_prop(L, "debug", _cclua_runtime_isDebug, nullptr);
    oluacls_prop(L, "deviceInfo", _cclua_runtime_getDeviceInfo, nullptr);
    oluacls_prop(L, "language", _cclua_runtime_getLanguage, nullptr);
    oluacls_prop(L, "logPath", _cclua_runtime_getLogPath, _cclua_runtime_setLogPath);
    oluacls_prop(L, "manifestVersion", _cclua_runtime_getManifestVersion, _cclua_runtime_setManifestVersion);
    oluacls_prop(L, "networkStatus", _cclua_runtime_getNetworkStatus, nullptr);
    oluacls_prop(L, "os", _cclua_runtime_getOS, nullptr);
    oluacls_prop(L, "packageName", _cclua_runtime_getPackageName, nullptr);
    oluacls_prop(L, "paste", _cclua_runtime_getPaste, _cclua_runtime_setPaste);
    oluacls_prop(L, "restarting", _cclua_runtime_isRestarting, nullptr);
    oluacls_prop(L, "sampleCount", _cclua_runtime_getSampleCount, _cclua_runtime_setSampleCount);
    oluacls_prop(L, "time", _cclua_runtime_getTime, nullptr);
    oluacls_prop(L, "version", _cclua_runtime_getVersion, nullptr);

    olua_registerluatype<cclua::runtime>(L, "cclua.runtime");

    return 1;
}

static int _cclua_filesystem___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::filesystem *)olua_toobj(L, 1, "cclua.filesystem");
    olua_push_cppobj(L, self, "cclua.filesystem");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_filesystem_addSearchPath1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */
    bool arg2 = false;       /** front */

    olua_check_std_string(L, 1, &arg1);
    olua_check_bool(L, 2, &arg2);

    // static void addSearchPath(const std::string &path, @optional bool front)
    cclua::filesystem::addSearchPath(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_filesystem_addSearchPath2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static void addSearchPath(const std::string &path, @optional bool front)
    cclua::filesystem::addSearchPath(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_filesystem_addSearchPath(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static void addSearchPath(const std::string &path, @optional bool front)
            return _cclua_filesystem_addSearchPath2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_bool(L, 2))) {
            // static void addSearchPath(const std::string &path, @optional bool front)
            return _cclua_filesystem_addSearchPath1(L);
        // }
    }

    luaL_error(L, "method 'cclua::filesystem::addSearchPath' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_filesystem_copy(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** srcPath */
    std::string arg2;       /** destPath */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static bool copy(const std::string &srcPath, const std::string &destPath)
    bool ret = cclua::filesystem::copy(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_createDirectory1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */
    bool arg2 = false;       /** isFilePath */

    olua_check_std_string(L, 1, &arg1);
    olua_check_bool(L, 2, &arg2);

    // static bool createDirectory(const std::string &path, @optional bool isFilePath)
    bool ret = cclua::filesystem::createDirectory(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_createDirectory2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static bool createDirectory(const std::string &path, @optional bool isFilePath)
    bool ret = cclua::filesystem::createDirectory(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_createDirectory(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static bool createDirectory(const std::string &path, @optional bool isFilePath)
            return _cclua_filesystem_createDirectory2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_bool(L, 2))) {
            // static bool createDirectory(const std::string &path, @optional bool isFilePath)
            return _cclua_filesystem_createDirectory1(L);
        // }
    }

    luaL_error(L, "method 'cclua::filesystem::createDirectory' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_filesystem_exist(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static bool exist(const std::string &path)
    bool ret = cclua::filesystem::exist(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_fullPath(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static const std::string fullPath(const std::string &path)
    const std::string ret = cclua::filesystem::fullPath(arg1);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_getBuiltinCacheDirectory(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getBuiltinCacheDirectory()
    const std::string ret = cclua::filesystem::getBuiltinCacheDirectory();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_getCacheDirectory(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getCacheDirectory()
    const std::string ret = cclua::filesystem::getCacheDirectory();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_getDocumentDirectory(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getDocumentDirectory()
    const std::string ret = cclua::filesystem::getDocumentDirectory();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_getSDCardDirectory(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getSDCardDirectory()
    const std::string ret = cclua::filesystem::getSDCardDirectory();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_getTmpDirectory(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getTmpDirectory()
    const std::string ret = cclua::filesystem::getTmpDirectory();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_getWritablePath(lua_State *L)
{
    olua_startinvoke(L);

    // static const std::string getWritablePath()
    const std::string ret = cclua::filesystem::getWritablePath();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_isDirectory(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static bool isDirectory(const std::string &path)
    bool ret = cclua::filesystem::isDirectory(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_isFile(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static bool isFile(const std::string &path)
    bool ret = cclua::filesystem::isFile(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_read(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static cocos2d::Data read(const std::string &path)
    cocos2d::Data ret = cclua::filesystem::read(arg1);
    int num_ret = olua_push_cocos2d_Data(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_remove(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static bool remove(const std::string &path)
    bool ret = cclua::filesystem::remove(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_rename(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** oldPath */
    std::string arg2;       /** newPath */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static bool rename(const std::string &oldPath, const std::string &newPath)
    bool ret = cclua::filesystem::rename(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_shortPath1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */
    lua_Unsigned arg2 = 0;       /** limit */

    olua_check_std_string(L, 1, &arg1);
    olua_check_uint(L, 2, &arg2);

    // static const std::string shortPath(const std::string &path, @optional size_t limit)
    const std::string ret = cclua::filesystem::shortPath(arg1, (size_t)arg2);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_shortPath2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */

    olua_check_std_string(L, 1, &arg1);

    // static const std::string shortPath(const std::string &path, @optional size_t limit)
    const std::string ret = cclua::filesystem::shortPath(arg1);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_shortPath(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_std_string(L, 1))) {
            // static const std::string shortPath(const std::string &path, @optional size_t limit)
            return _cclua_filesystem_shortPath2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_uint(L, 2))) {
            // static const std::string shortPath(const std::string &path, @optional size_t limit)
            return _cclua_filesystem_shortPath1(L);
        // }
    }

    luaL_error(L, "method 'cclua::filesystem::shortPath' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_filesystem_unzip(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */
    std::string arg2;       /** dest */

    olua_check_std_string(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);

    // static bool unzip(const std::string &path, const std::string &dest)
    bool ret = cclua::filesystem::unzip(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_write1(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */
    const char *arg2 = nullptr;       /** data */
    lua_Unsigned arg3 = 0;       /** len */

    olua_check_std_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);
    olua_check_uint(L, 3, &arg3);

    // static bool write(const std::string &path, const char *data, size_t len)
    bool ret = cclua::filesystem::write(arg1, arg2, (size_t)arg3);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_write2(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** path */
    cocos2d::Data arg2;       /** data */

    olua_check_std_string(L, 1, &arg1);
    olua_check_cocos2d_Data(L, 2, &arg2);

    // static bool write(const std::string &path, const cocos2d::Data &data)
    bool ret = cclua::filesystem::write(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_filesystem_write(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_cocos2d_Data(L, 2))) {
            // static bool write(const std::string &path, const cocos2d::Data &data)
            return _cclua_filesystem_write2(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_is_std_string(L, 1)) && (olua_is_string(L, 2)) && (olua_is_uint(L, 3))) {
            // static bool write(const std::string &path, const char *data, size_t len)
            return _cclua_filesystem_write1(L);
        // }
    }

    luaL_error(L, "method 'cclua::filesystem::write' not support '%d' arguments", num_args);

    return 0;
}

static int luaopen_cclua_filesystem(lua_State *L)
{
    oluacls_class(L, "cclua.filesystem", nullptr);
    oluacls_func(L, "__move", _cclua_filesystem___move);
    oluacls_func(L, "addSearchPath", _cclua_filesystem_addSearchPath);
    oluacls_func(L, "copy", _cclua_filesystem_copy);
    oluacls_func(L, "createDirectory", _cclua_filesystem_createDirectory);
    oluacls_func(L, "exist", _cclua_filesystem_exist);
    oluacls_func(L, "fullPath", _cclua_filesystem_fullPath);
    oluacls_func(L, "getBuiltinCacheDirectory", _cclua_filesystem_getBuiltinCacheDirectory);
    oluacls_func(L, "getCacheDirectory", _cclua_filesystem_getCacheDirectory);
    oluacls_func(L, "getDocumentDirectory", _cclua_filesystem_getDocumentDirectory);
    oluacls_func(L, "getSDCardDirectory", _cclua_filesystem_getSDCardDirectory);
    oluacls_func(L, "getTmpDirectory", _cclua_filesystem_getTmpDirectory);
    oluacls_func(L, "getWritablePath", _cclua_filesystem_getWritablePath);
    oluacls_func(L, "isDirectory", _cclua_filesystem_isDirectory);
    oluacls_func(L, "isFile", _cclua_filesystem_isFile);
    oluacls_func(L, "read", _cclua_filesystem_read);
    oluacls_func(L, "remove", _cclua_filesystem_remove);
    oluacls_func(L, "rename", _cclua_filesystem_rename);
    oluacls_func(L, "shortPath", _cclua_filesystem_shortPath);
    oluacls_func(L, "unzip", _cclua_filesystem_unzip);
    oluacls_func(L, "write", _cclua_filesystem_write);
    oluacls_prop(L, "builtinCacheDirectory", _cclua_filesystem_getBuiltinCacheDirectory, nullptr);
    oluacls_prop(L, "cacheDirectory", _cclua_filesystem_getCacheDirectory, nullptr);
    oluacls_prop(L, "documentDirectory", _cclua_filesystem_getDocumentDirectory, nullptr);
    oluacls_prop(L, "sdCardDirectory", _cclua_filesystem_getSDCardDirectory, nullptr);
    oluacls_prop(L, "tmpDirectory", _cclua_filesystem_getTmpDirectory, nullptr);
    oluacls_prop(L, "writablePath", _cclua_filesystem_getWritablePath, nullptr);

    olua_registerluatype<cclua::filesystem>(L, "cclua.filesystem");

    return 1;
}

static int _cclua_preferences___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::preferences *)olua_toobj(L, 1, "cclua.preferences");
    olua_push_cppobj(L, self, "cclua.preferences");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_preferences_deleteKey(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */

    olua_check_string(L, 1, &arg1);

    // static void deleteKey(const char *key)
    cclua::preferences::deleteKey(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_preferences_flush(lua_State *L)
{
    olua_startinvoke(L);

    // static void flush()
    cclua::preferences::flush();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_preferences_getBoolean1(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */
    bool arg2 = false;       /** defaultValue */

    olua_check_string(L, 1, &arg1);
    olua_check_bool(L, 2, &arg2);

    // static bool getBoolean(const char *key, @optional bool defaultValue)
    bool ret = cclua::preferences::getBoolean(arg1, arg2);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_preferences_getBoolean2(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */

    olua_check_string(L, 1, &arg1);

    // static bool getBoolean(const char *key, @optional bool defaultValue)
    bool ret = cclua::preferences::getBoolean(arg1);
    int num_ret = olua_push_bool(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_preferences_getBoolean(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_string(L, 1))) {
            // static bool getBoolean(const char *key, @optional bool defaultValue)
            return _cclua_preferences_getBoolean2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_string(L, 1)) && (olua_is_bool(L, 2))) {
            // static bool getBoolean(const char *key, @optional bool defaultValue)
            return _cclua_preferences_getBoolean1(L);
        // }
    }

    luaL_error(L, "method 'cclua::preferences::getBoolean' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_preferences_getDouble1(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */
    lua_Number arg2 = 0;       /** defaultValue */

    olua_check_string(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static double getDouble(const char *key, @optional double defaultValue)
    double ret = cclua::preferences::getDouble(arg1, (double)arg2);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_preferences_getDouble2(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */

    olua_check_string(L, 1, &arg1);

    // static double getDouble(const char *key, @optional double defaultValue)
    double ret = cclua::preferences::getDouble(arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_preferences_getDouble(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_string(L, 1))) {
            // static double getDouble(const char *key, @optional double defaultValue)
            return _cclua_preferences_getDouble2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_string(L, 1)) && (olua_is_number(L, 2))) {
            // static double getDouble(const char *key, @optional double defaultValue)
            return _cclua_preferences_getDouble1(L);
        // }
    }

    luaL_error(L, "method 'cclua::preferences::getDouble' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_preferences_getFloat1(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */
    lua_Number arg2 = 0;       /** defaultValue */

    olua_check_string(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static float getFloat(const char *key, @optional float defaultValue)
    float ret = cclua::preferences::getFloat(arg1, (float)arg2);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_preferences_getFloat2(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */

    olua_check_string(L, 1, &arg1);

    // static float getFloat(const char *key, @optional float defaultValue)
    float ret = cclua::preferences::getFloat(arg1);
    int num_ret = olua_push_number(L, (lua_Number)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_preferences_getFloat(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_string(L, 1))) {
            // static float getFloat(const char *key, @optional float defaultValue)
            return _cclua_preferences_getFloat2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_string(L, 1)) && (olua_is_number(L, 2))) {
            // static float getFloat(const char *key, @optional float defaultValue)
            return _cclua_preferences_getFloat1(L);
        // }
    }

    luaL_error(L, "method 'cclua::preferences::getFloat' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_preferences_getInteger1(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */
    lua_Integer arg2 = 0;       /** defaultValue */

    olua_check_string(L, 1, &arg1);
    olua_check_int(L, 2, &arg2);

    // static int getInteger(const char *key, @optional int defaultValue)
    int ret = cclua::preferences::getInteger(arg1, (int)arg2);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_preferences_getInteger2(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */

    olua_check_string(L, 1, &arg1);

    // static int getInteger(const char *key, @optional int defaultValue)
    int ret = cclua::preferences::getInteger(arg1);
    int num_ret = olua_push_int(L, (lua_Integer)ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_preferences_getInteger(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_string(L, 1))) {
            // static int getInteger(const char *key, @optional int defaultValue)
            return _cclua_preferences_getInteger2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_string(L, 1)) && (olua_is_int(L, 2))) {
            // static int getInteger(const char *key, @optional int defaultValue)
            return _cclua_preferences_getInteger1(L);
        // }
    }

    luaL_error(L, "method 'cclua::preferences::getInteger' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_preferences_getString1(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */
    const char *arg2 = nullptr;       /** defaultValue */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // static std::string getString(const char *key, @optional const char *defaultValue)
    std::string ret = cclua::preferences::getString(arg1, arg2);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_preferences_getString2(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */

    olua_check_string(L, 1, &arg1);

    // static std::string getString(const char *key, @optional const char *defaultValue)
    std::string ret = cclua::preferences::getString(arg1);
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_preferences_getString(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_string(L, 1))) {
            // static std::string getString(const char *key, @optional const char *defaultValue)
            return _cclua_preferences_getString2(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_string(L, 1)) && (olua_is_string(L, 2))) {
            // static std::string getString(const char *key, @optional const char *defaultValue)
            return _cclua_preferences_getString1(L);
        // }
    }

    luaL_error(L, "method 'cclua::preferences::getString' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_preferences_setBoolean(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */
    bool arg2 = false;       /** value */

    olua_check_string(L, 1, &arg1);
    olua_check_bool(L, 2, &arg2);

    // static void setBoolean(const char *key, bool value)
    cclua::preferences::setBoolean(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_preferences_setDouble(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */
    lua_Number arg2 = 0;       /** value */

    olua_check_string(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static void setDouble(const char *key, double value)
    cclua::preferences::setDouble(arg1, (double)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_preferences_setFloat(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */
    lua_Number arg2 = 0;       /** value */

    olua_check_string(L, 1, &arg1);
    olua_check_number(L, 2, &arg2);

    // static void setFloat(const char *key, float value)
    cclua::preferences::setFloat(arg1, (float)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_preferences_setInteger(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */
    lua_Integer arg2 = 0;       /** value */

    olua_check_string(L, 1, &arg1);
    olua_check_int(L, 2, &arg2);

    // static void setInteger(const char *key, int value)
    cclua::preferences::setInteger(arg1, (int)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_preferences_setString(lua_State *L)
{
    olua_startinvoke(L);

    const char *arg1 = nullptr;       /** key */
    const char *arg2 = nullptr;       /** value */

    olua_check_string(L, 1, &arg1);
    olua_check_string(L, 2, &arg2);

    // static void setString(const char *key, const char *value)
    cclua::preferences::setString(arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cclua_preferences(lua_State *L)
{
    oluacls_class(L, "cclua.preferences", nullptr);
    oluacls_func(L, "__move", _cclua_preferences___move);
    oluacls_func(L, "deleteKey", _cclua_preferences_deleteKey);
    oluacls_func(L, "flush", _cclua_preferences_flush);
    oluacls_func(L, "getBoolean", _cclua_preferences_getBoolean);
    oluacls_func(L, "getDouble", _cclua_preferences_getDouble);
    oluacls_func(L, "getFloat", _cclua_preferences_getFloat);
    oluacls_func(L, "getInteger", _cclua_preferences_getInteger);
    oluacls_func(L, "getString", _cclua_preferences_getString);
    oluacls_func(L, "setBoolean", _cclua_preferences_setBoolean);
    oluacls_func(L, "setDouble", _cclua_preferences_setDouble);
    oluacls_func(L, "setFloat", _cclua_preferences_setFloat);
    oluacls_func(L, "setInteger", _cclua_preferences_setInteger);
    oluacls_func(L, "setString", _cclua_preferences_setString);

    olua_registerluatype<cclua::preferences>(L, "cclua.preferences");

    return 1;
}

#define makeTimerDelayTag(tag) ("delayTag." + tag)

static int _cclua_timer___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::timer *)olua_toobj(L, 1, "cclua.timer");
    olua_push_cppobj(L, self, "cclua.timer");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_timer_createTag(lua_State *L)
{
    olua_startinvoke(L);

    // static std::string createTag()
    std::string ret = cclua::timer::createTag();
    int num_ret = olua_push_std_string(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_timer_delay(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */
    std::function<void()> arg2;       /** callback */

    olua_check_number(L, 1, &arg1);
    olua_check_std_function(L, 2, &arg2);

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.timer");
    std::string cb_tag = "delay";
    std::string cb_name = olua_setcallback(L, cb_store, cb_tag.c_str(), 2, OLUA_TAG_NEW);
    lua_Integer cb_ctx = olua_context(L);
    arg2 = [cb_store, cb_name, cb_ctx]() {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (L != NULL && olua_context(L) == cb_ctx) {
            int top = lua_gettop(L);

            olua_callback(L, cb_store, cb_name.c_str(), 0);

            olua_removecallback(L, cb_store, cb_name.c_str(), OLUA_TAG_WHOLE);

            lua_settop(L, top);
        }
    };

    // static void delay(float time, @local const std::function<void ()> callback)
    cclua::timer::delay((float)arg1, arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_timer_delayWithTag(lua_State *L)
{
    olua_startinvoke(L);

    lua_Number arg1 = 0;       /** time */
    std::string arg2;       /** tag */
    std::function<void()> arg3;       /** callback */

    olua_check_number(L, 1, &arg1);
    olua_check_std_string(L, 2, &arg2);
    olua_check_std_function(L, 3, &arg3);

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.timer");
    std::string cb_tag = makeTimerDelayTag(arg2);
    std::string cb_name = olua_setcallback(L, cb_store, cb_tag.c_str(), 3, OLUA_TAG_REPLACE);
    lua_Integer cb_ctx = olua_context(L);
    arg3 = [cb_store, cb_name, cb_ctx]() {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (L != NULL && olua_context(L) == cb_ctx) {
            int top = lua_gettop(L);

            olua_callback(L, cb_store, cb_name.c_str(), 0);

            olua_removecallback(L, cb_store, cb_name.c_str(), OLUA_TAG_WHOLE);

            lua_settop(L, top);
        }
    };

    // static void delayWithTag(float time, const std::string &tag, @local std::function<void ()> callback)
    cclua::timer::delayWithTag((float)arg1, arg2, arg3);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_timer_killDelay(lua_State *L)
{
    olua_startinvoke(L);

    std::string arg1;       /** tag */

    olua_check_std_string(L, 1, &arg1);

    std::string cb_tag = makeTimerDelayTag(arg1);
    void *cb_store = (void *)olua_pushclassobj(L, "cclua.timer");
    olua_removecallback(L, cb_store, cb_tag.c_str(), OLUA_TAG_SUBEQUAL);

    // static void killDelay(const std::string &tag)
    cclua::timer::killDelay(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_timer_schedule(lua_State *L)
{
    olua_startinvoke(L);

    float interval = (float)olua_checknumber(L, 1);
    uint32_t callback = olua_funcref(L, 2);
    uint32_t id = cclua::timer::schedule(interval, [callback](float dt) {
        lua_State *L = olua_mainthread(NULL);
        if (L != NULL) {
            int top = lua_gettop(L);
            olua_pusherrorfunc(L);
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

static int _cclua_timer_unschedule(lua_State *L)
{
    olua_startinvoke(L);

    uint64_t value = olua_checkinteger(L, 1);
    uint32_t callback = value >> 32;
    uint32_t id = value & 0xFFFFFFFF;
    olua_unref(L, callback);
    cclua::timer::unschedule(id);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cclua_timer(lua_State *L)
{
    oluacls_class(L, "cclua.timer", nullptr);
    oluacls_func(L, "__move", _cclua_timer___move);
    oluacls_func(L, "createTag", _cclua_timer_createTag);
    oluacls_func(L, "delay", _cclua_timer_delay);
    oluacls_func(L, "delayWithTag", _cclua_timer_delayWithTag);
    oluacls_func(L, "killDelay", _cclua_timer_killDelay);
    oluacls_func(L, "schedule", _cclua_timer_schedule);
    oluacls_func(L, "unschedule", _cclua_timer_unschedule);

    olua_registerluatype<cclua::timer>(L, "cclua.timer");

    return 1;
}

static int _cclua_window___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::window *)olua_toobj(L, 1, "cclua.window");
    olua_push_cppobj(L, self, "cclua.window");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_window_convertToCameraSpace1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 arg1;       /** position */

    olua_check_cocos2d_Vec2(L, 1, &arg1);

    // static cocos2d::Vec2 convertToCameraSpace(const cocos2d::Vec2 &position)
    cocos2d::Vec2 ret = cclua::window::convertToCameraSpace(arg1);
    int num_ret = olua_push_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_window_convertToCameraSpace2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Vec2 arg1;       /** position */

    olua_pack_cocos2d_Vec2(L, 1, &arg1);

    // static cocos2d::Vec2 convertToCameraSpace(@pack const cocos2d::Vec2 &position)
    cocos2d::Vec2 ret = cclua::window::convertToCameraSpace(arg1);
    int num_ret = olua_unpack_cocos2d_Vec2(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_window_convertToCameraSpace(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_cocos2d_Vec2(L, 1))) {
            // static cocos2d::Vec2 convertToCameraSpace(const cocos2d::Vec2 &position)
            return _cclua_window_convertToCameraSpace1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_ispack_cocos2d_Vec2(L, 1))) {
            // static cocos2d::Vec2 convertToCameraSpace(@pack const cocos2d::Vec2 &position)
            return _cclua_window_convertToCameraSpace2(L);
        // }
    }

    luaL_error(L, "method 'cclua::window::convertToCameraSpace' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_window_getDesignSize(lua_State *L)
{
    olua_startinvoke(L);

    // @unpack static cocos2d::Size getDesignSize()
    cocos2d::Size ret = cclua::window::getDesignSize();
    int num_ret = olua_unpack_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_window_getFrameSize(lua_State *L)
{
    olua_startinvoke(L);

    // @unpack static cocos2d::Size getFrameSize()
    cocos2d::Size ret = cclua::window::getFrameSize();
    int num_ret = olua_unpack_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_window_getVisibleBounds(lua_State *L)
{
    olua_startinvoke(L);

    // @unpack static cclua::window::Bounds getVisibleBounds()
    cclua::window::Bounds ret = cclua::window::getVisibleBounds();
    int num_ret = olua_unpack_cclua_window_Bounds(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_window_getVisibleSize(lua_State *L)
{
    olua_startinvoke(L);

    // @unpack static cocos2d::Size getVisibleSize()
    cocos2d::Size ret = cclua::window::getVisibleSize();
    int num_ret = olua_unpack_cocos2d_Size(L, &ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_window_setDesignSize1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    lua_Unsigned arg2 = 0;       /** resolutionPolicy */

    olua_check_cocos2d_Size(L, 1, &arg1);
    olua_check_uint(L, 2, &arg2);

    // static void setDesignSize(const cocos2d::Size &size, ResolutionPolicy resolutionPolicy)
    cclua::window::setDesignSize(arg1, (ResolutionPolicy)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_window_setDesignSize2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */
    lua_Unsigned arg2 = 0;       /** resolutionPolicy */

    olua_pack_cocos2d_Size(L, 1, &arg1);
    olua_check_uint(L, 3, &arg2);

    // static void setDesignSize(@pack const cocos2d::Size &size, ResolutionPolicy resolutionPolicy)
    cclua::window::setDesignSize(arg1, (ResolutionPolicy)arg2);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_window_setDesignSize(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 2) {
        // if ((olua_is_cocos2d_Size(L, 1)) && (olua_is_uint(L, 2))) {
            // static void setDesignSize(const cocos2d::Size &size, ResolutionPolicy resolutionPolicy)
            return _cclua_window_setDesignSize1(L);
        // }
    }

    if (num_args == 3) {
        // if ((olua_ispack_cocos2d_Size(L, 1)) && (olua_is_uint(L, 3))) {
            // static void setDesignSize(@pack const cocos2d::Size &size, ResolutionPolicy resolutionPolicy)
            return _cclua_window_setDesignSize2(L);
        // }
    }

    luaL_error(L, "method 'cclua::window::setDesignSize' not support '%d' arguments", num_args);

    return 0;
}

static int _cclua_window_setFrameSize1(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */

    olua_check_cocos2d_Size(L, 1, &arg1);

    // static void setFrameSize(const cocos2d::Size &size)
    cclua::window::setFrameSize(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_window_setFrameSize2(lua_State *L)
{
    olua_startinvoke(L);

    cocos2d::Size arg1;       /** size */

    olua_pack_cocos2d_Size(L, 1, &arg1);

    // static void setFrameSize(@pack const cocos2d::Size &size)
    cclua::window::setFrameSize(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_window_setFrameSize(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_cocos2d_Size(L, 1))) {
            // static void setFrameSize(const cocos2d::Size &size)
            return _cclua_window_setFrameSize1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_ispack_cocos2d_Size(L, 1))) {
            // static void setFrameSize(@pack const cocos2d::Size &size)
            return _cclua_window_setFrameSize2(L);
        // }
    }

    luaL_error(L, "method 'cclua::window::setFrameSize' not support '%d' arguments", num_args);

    return 0;
}

static int luaopen_cclua_window(lua_State *L)
{
    oluacls_class(L, "cclua.window", nullptr);
    oluacls_func(L, "__move", _cclua_window___move);
    oluacls_func(L, "convertToCameraSpace", _cclua_window_convertToCameraSpace);
    oluacls_func(L, "getDesignSize", _cclua_window_getDesignSize);
    oluacls_func(L, "getFrameSize", _cclua_window_getFrameSize);
    oluacls_func(L, "getVisibleBounds", _cclua_window_getVisibleBounds);
    oluacls_func(L, "getVisibleSize", _cclua_window_getVisibleSize);
    oluacls_func(L, "setDesignSize", _cclua_window_setDesignSize);
    oluacls_func(L, "setFrameSize", _cclua_window_setFrameSize);
    oluacls_prop(L, "designSize", _cclua_window_getDesignSize, _cclua_window_setDesignSize);
    oluacls_prop(L, "frameSize", _cclua_window_getFrameSize, _cclua_window_setFrameSize);
    oluacls_prop(L, "visibleBounds", _cclua_window_getVisibleBounds, nullptr);
    oluacls_prop(L, "visibleSize", _cclua_window_getVisibleSize, nullptr);

    olua_registerluatype<cclua::window>(L, "cclua.window");

    return 1;
}

static int luaopen_cclua_downloader_FileState(lua_State *L)
{
    oluacls_class(L, "cclua.downloader.FileState", nullptr);
    oluacls_const_integer(L, "INVALID", (lua_Integer)cclua::downloader::FileState::INVALID);
    oluacls_const_integer(L, "IOERROR", (lua_Integer)cclua::downloader::FileState::IOERROR);
    oluacls_const_integer(L, "LOADED", (lua_Integer)cclua::downloader::FileState::LOADED);
    oluacls_const_integer(L, "PENDING", (lua_Integer)cclua::downloader::FileState::PENDING);

    olua_registerluatype<cclua::downloader::FileState>(L, "cclua.downloader.FileState");

    return 1;
}

static int _cclua_downloader___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::downloader *)olua_toobj(L, 1, "cclua.downloader");
    olua_push_cppobj(L, self, "cclua.downloader");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_downloader_end(lua_State *L)
{
    olua_startinvoke(L);

    // static void end()
    cclua::downloader::end();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_downloader_init(lua_State *L)
{
    olua_startinvoke(L);

    // static void init()
    cclua::downloader::init();

    olua_endinvoke(L);

    return 0;
}

static int _cclua_downloader_load(lua_State *L)
{
    olua_startinvoke(L);

    cclua::downloader::FileTask arg1;       /** task */

    olua_check_cclua_downloader_FileTask(L, 1, &arg1);

    // static void load(const cclua::downloader::FileTask &task)
    cclua::downloader::load(arg1);

    olua_endinvoke(L);

    return 0;
}

static int _cclua_downloader_setDispatcher(lua_State *L)
{
    olua_startinvoke(L);

    std::function<void(const cclua::downloader::FileTask &)> arg1;       /** callback */

    olua_check_std_function(L, 1, &arg1);

    void *cb_store = (void *)olua_pushclassobj(L, "cclua.downloader");
    std::string cb_tag = "Dispatcher";
    std::string cb_name = olua_setcallback(L, cb_store, cb_tag.c_str(), 1, OLUA_TAG_REPLACE);
    lua_Integer cb_ctx = olua_context(L);
    arg1 = [cb_store, cb_name, cb_ctx](const cclua::downloader::FileTask &arg1) {
        lua_State *L = olua_mainthread(NULL);
        olua_checkhostthread();

        if (L != NULL && olua_context(L) == cb_ctx) {
            int top = lua_gettop(L);
            size_t last = olua_push_objpool(L);
            olua_enable_objpool(L);
            olua_push_cclua_downloader_FileTask(L, &arg1);
            olua_disable_objpool(L);

            olua_callback(L, cb_store, cb_name.c_str(), 1);

            //pop stack value
            olua_pop_objpool(L, last);
            lua_settop(L, top);
        }
    };

    // static void setDispatcher(@local const std::function<void (const cclua::downloader::FileTask &)> callback)
    cclua::downloader::setDispatcher(arg1);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cclua_downloader(lua_State *L)
{
    oluacls_class(L, "cclua.downloader", nullptr);
    oluacls_func(L, "__move", _cclua_downloader___move);
    oluacls_func(L, "end", _cclua_downloader_end);
    oluacls_func(L, "init", _cclua_downloader_init);
    oluacls_func(L, "load", _cclua_downloader_load);
    oluacls_func(L, "setDispatcher", _cclua_downloader_setDispatcher);

    olua_registerluatype<cclua::downloader>(L, "cclua.downloader");

    return 1;
}

static int _cclua_MaskLayout___move(lua_State *L)
{
    olua_startinvoke(L);

    auto self = (cclua::MaskLayout *)olua_toobj(L, 1, "cclua.MaskLayout");
    olua_push_cppobj(L, self, "cclua.MaskLayout");

    olua_endinvoke(L);

    return 1;
}

static int _cclua_MaskLayout_create(lua_State *L)
{
    olua_startinvoke(L);

    // static cclua::MaskLayout *create()
    cclua::MaskLayout *ret = cclua::MaskLayout::create();
    int num_ret = olua_push_cppobj(L, ret, "cclua.MaskLayout");

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MaskLayout_getClippingNode(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MaskLayout *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cclua.MaskLayout");

    // cocos2d::DrawNode *getClippingNode()
    cocos2d::DrawNode *ret = self->getClippingNode();
    int num_ret = olua_push_cppobj(L, ret, "cc.DrawNode");

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MaskLayout_getFilter(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MaskLayout *self = nullptr;

    olua_to_cppobj(L, 1, (void **)&self, "cclua.MaskLayout");

    // @addref(filter ^) cocos2d::Node *getFilter()
    cocos2d::Node *ret = self->getFilter();
    int num_ret = olua_push_cppobj(L, ret, "cc.Node");

    // insert code after call
    olua_addref(L, 1, "filter", -1, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MaskLayout_new(lua_State *L)
{
    olua_startinvoke(L);

    // MaskLayout()
    cclua::MaskLayout *ret = new cclua::MaskLayout();
    int num_ret = olua_push_cppobj(L, ret, "cclua.MaskLayout");
    olua_postnew(L, ret);

    olua_endinvoke(L);

    return num_ret;
}

static int _cclua_MaskLayout_setFilter(lua_State *L)
{
    olua_startinvoke(L);

    cclua::MaskLayout *self = nullptr;
    cocos2d::Node *arg1 = nullptr;       /** value */

    olua_to_cppobj(L, 1, (void **)&self, "cclua.MaskLayout");
    if (!olua_isnoneornil(L, 2)) {
        olua_check_cppobj(L, 2, (void **)&arg1, "cc.Node");
    }

    // void setFilter(@nullable@addref(filter ^) cocos2d::Node *value)
    self->setFilter(arg1);

    // insert code after call
    olua_addref(L, 1, "filter", 2, OLUA_MODE_SINGLE);

    olua_endinvoke(L);

    return 0;
}

static int luaopen_cclua_MaskLayout(lua_State *L)
{
    oluacls_class(L, "cclua.MaskLayout", "ccui.Layout");
    oluacls_func(L, "__move", _cclua_MaskLayout___move);
    oluacls_func(L, "create", _cclua_MaskLayout_create);
    oluacls_func(L, "getClippingNode", _cclua_MaskLayout_getClippingNode);
    oluacls_func(L, "getFilter", _cclua_MaskLayout_getFilter);
    oluacls_func(L, "new", _cclua_MaskLayout_new);
    oluacls_func(L, "setFilter", _cclua_MaskLayout_setFilter);
    oluacls_prop(L, "clippingNode", _cclua_MaskLayout_getClippingNode, nullptr);
    oluacls_prop(L, "filter", _cclua_MaskLayout_getFilter, _cclua_MaskLayout_setFilter);

    olua_registerluatype<cclua::MaskLayout>(L, "cclua.MaskLayout");

    return 1;
}

int luaopen_xgame(lua_State *L)
{
    olua_require(L, "cclua.SceneNoCamera", luaopen_cclua_SceneNoCamera);
    olua_require(L, "cclua.Permission", luaopen_cclua_Permission);
    olua_require(L, "cclua.PermissionStatus", luaopen_cclua_PermissionStatus);
    olua_require(L, "cclua.runtime", luaopen_cclua_runtime);
    olua_require(L, "cclua.filesystem", luaopen_cclua_filesystem);
    olua_require(L, "cclua.preferences", luaopen_cclua_preferences);
    olua_require(L, "cclua.timer", luaopen_cclua_timer);
    olua_require(L, "cclua.window", luaopen_cclua_window);
    olua_require(L, "cclua.downloader.FileState", luaopen_cclua_downloader_FileState);
    olua_require(L, "cclua.downloader", luaopen_cclua_downloader);
    olua_require(L, "cclua.MaskLayout", luaopen_cclua_MaskLayout);
    return 0;
}
