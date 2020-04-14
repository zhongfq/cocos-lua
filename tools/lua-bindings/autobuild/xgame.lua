-- AUTO BUILD, DON'T MODIFY!

require "autobuild.xgame-types"

local olua = require "olua"
local typeconv = olua.typeconv
local typecls = olua.typecls
local cls = nil
local M = {}

M.NAME = "xgame"
M.PATH = "../../frameworks/libxgame/src/lua-bindings"
M.INCLUDES = [[
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
]]
M.CHUNK = [[

]]

M.CONVS = {
    typeconv {
        CPPCLS = 'xgame::downloader::FileTask',
        DEF = [[
            std::string url;
            std::string path;
            @optional std::string md5;
            @optional xgame::downloader::FileState state;
        ]],
    },
}

M.CLASSES = {}

cls = typecls 'xgame::SceneNoCamera'
cls.SUPERCLS = "cocos2d::Scene"
cls.funcs [[
    static xgame::SceneNoCamera *create()
    static xgame::SceneNoCamera *createWithSize(const cocos2d::Size &size)
    static xgame::SceneNoCamera *createWithPhysics()
    SceneNoCamera()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'xgame::Permission'
cls.enums [[
    AUDIO
    CAMERA
    PHOTO
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'xgame::PermissionStatus'
cls.enums [[
    NOT_DETERMINED
    RESTRICTED
    DENIED
    AUTHORIZED
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'xgame::runtime'
cls.funcs [[
    static void clearStorage()
    static bool launch(const std::string &scriptPath)
    static bool restart()
    static bool isRestarting()
    static bool isDebug()
    static float getTime()
    static void gc()
    static const std::string getVersion()
    static const std::string getPackageName()
    static const std::string getAppVersion()
    static const std::string getAppBuild()
    static const std::string getChannel()
    static const std::string getOS()
    static const std::string getDeviceInfo()
    static const std::string getLanguage()
    static const std::string getManifestVersion()
    static void setManifestVersion(const std::string &version)
    static const std::string getNetworkStatus()
    static cocos2d::RenderTexture *capture(cocos2d::Node *node, @optional cocos2d::backend::PixelFormat format, @optional cocos2d::backend::PixelFormat depthStencilFormat)
    static const xgame::PermissionStatus getPermissionStatus(xgame::Permission permission)
    static void setAudioSessionCatalog(const std::string &catalog)
    static const std::string getAudioSessionCatalog()
    static std::string getIDFA()
    static bool isAdvertisingTrackingEnabled()
    static bool canOpenURL(const std::string &uri)
    static void setLogPath(const std::string &path)
    static const std::string getLogPath()
    static void setSampleCount(unsigned int samples)
    static unsigned int getSampleCount()
    static bool support(const std::string &api)
    static void printSupport()
    static void disableReport()
]]
cls.func('testCrash', [[{
    xgame::runtime::log("test native crash!!!!");
    char *prt = NULL;
    *prt = 0;
    return 0;
}]])
cls.func('setDispatcher', [[{
    int handler = olua_reffunc(L, 1);
    xgame::runtime::setDispatcher([handler](const std::string &event, const std::string &args) {
        lua_State *L = olua_mainthread();
        int top = lua_gettop(L);
        olua_geterrorfunc(L);
        olua_getref(L, handler);
        if (lua_isfunction(L, -1)) {
            lua_pushstring(L, event.c_str());
            lua_pushstring(L, args.c_str());
            lua_pcall(L, 2, 0, top + 1);
        }
        lua_settop(L, top);
    });
    return 0;
}]])
cls.callback {
    FUNCS =  {
        'static void openURL(const std::string &uri, @local @optional const std::function<void (bool)> callback)'
    },
    TAG_MAKER = 'openURL',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = nil,
    TAG_SCOPE = 'once',
}
cls.callback {
    FUNCS =  {
        'static void requestPermission(xgame::Permission permission, @local const std::function<void (PermissionStatus)> callback)'
    },
    TAG_MAKER = 'requestPermission',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = nil,
    TAG_SCOPE = 'once',
}
cls.callback {
    FUNCS =  {
        'static void alert(const std::string &title, const std::string &message, const std::string &ok, const std::string &no, @local const std::function<void (bool)> callback)'
    },
    TAG_MAKER = 'alert',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = nil,
    TAG_SCOPE = 'once',
}
cls.props [[
    restarting
    debug
    time
    version
    packageName
    appVersion
    appBuild
    channel
    os
    deviceInfo
    language
    manifestVersion
    networkStatus
    audioSessionCatalog
    idfa
    advertisingTrackingEnabled
    logPath
    sampleCount
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'xgame::filesystem'
cls.funcs [[
    static const std::string getWritablePath()
    static const std::string getCacheDirectory()
    static const std::string getDocumentDirectory()
    static const std::string getTmpDirectory()
    static const std::string getBuiltinCacheDirectory()
    static const std::string getSDCardDirectory()
    static void addSearchPath(const std::string &path, @optional bool front)
    static const std::string shortPath(const std::string &path, @optional size_t limit)
    static const std::string fullPath(const std::string &path)
    static bool createDirectory(const std::string &path, @optional bool isFilePath)
    static bool remove(const std::string &path)
    static bool exist(const std::string &path)
    static bool isFile(const std::string &path)
    static bool isDirectory(const std::string &path)
    static bool rename(const std::string &oldPath, const std::string &newPath)
    static bool copy(const std::string &srcPath, const std::string &destPath)
    static cocos2d::Data read(const std::string &path)
    static bool unzip(const std::string &path, const std::string &dest)
]]
cls.func('write', [[{
    size_t len;
    std::string path = olua_tostring(L, 1);
    const char *data = olua_checklstring(L, 2, &len);
    bool ret = (bool)xgame::filesystem::write(path, data, len);
    olua_push_bool(L, ret);
    return 1;
}]])
cls.props [[
    writablePath
    cacheDirectory
    documentDirectory
    tmpDirectory
    builtinCacheDirectory
    sdCardDirectory
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'xgame::preferences'
cls.funcs [[
    static bool getBoolean(const char *key, @optional bool defaultValue)
    static void setBoolean(const char *key, bool value)
    static float getFloat(const char *key, @optional float defaultValue)
    static void setFloat(const char *key, float value)
    static double getDouble(const char *key, @optional double defaultValue)
    static void setDouble(const char *key, double value)
    static int getInteger(const char *key, @optional int defaultValue)
    static void setInteger(const char *key, int value)
    static std::string getString(const char *key, @optional const char *defaultValue)
    static void setString(const char *key, const char *value)
    static void deleteKey(const char *key)
    static void flush()
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'xgame::timer'
cls.CHUNK = [[
#define makeTimerDelayTag(tag) ("delayTag." + tag)
]]
cls.funcs [[
    static std::string createTag()
]]
cls.func('schedule', [[{
    float interval = (float)olua_checknumber(L, 1);
    uint32_t callback = olua_reffunc(L, 2);
    uint32_t id = xgame::timer::schedule(interval, [callback](float dt) {
        lua_State *L = olua_mainthread();
        int top = lua_gettop(L);
        olua_geterrorfunc(L);
        olua_getref(L, callback);
        if (lua_isfunction(L, -1)) {
            lua_pushnumber(L, dt);
            lua_pcall(L, 1, 0, top + 1);
        }
        lua_settop(L, top);
    });
    lua_pushinteger(L, ((uint64_t)callback << 32) | (uint64_t)id);
    return 1;
}]])
cls.func('unschedule', [[{
    uint64_t value = olua_checkinteger(L, 1);
    uint32_t callback = value >> 32;
    uint32_t id = value & 0xFFFFFFFF;
    olua_unref(L, callback);
    xgame::timer::unschedule(id);
    return 0;
}]])
cls.callback {
    FUNCS =  {
        'static void delayWithTag(float time, const std::string &tag, @local std::function<void ()> callback)'
    },
    TAG_MAKER = 'makeTimerDelayTag(#2)',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'once',
}
cls.callback {
    FUNCS =  {
        'static void killDelay(const std::string &tag)'
    },
    TAG_MAKER = 'makeTimerDelayTag(#1)',
    TAG_MODE = 'OLUA_TAG_SUBEQUAL',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
cls.callback {
    FUNCS =  {
        'static void delay(float time, @local const std::function<void ()> callback)'
    },
    TAG_MAKER = 'delay',
    TAG_MODE = 'OLUA_TAG_NEW',
    TAG_STORE = nil,
    TAG_SCOPE = 'once',
}
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'xgame::window'
cls.REG_LUATYPE = false
cls.funcs [[
]]
cls.func('getVisibleBounds', [[{
    auto rect = cocos2d::Director::getInstance()->getOpenGLView()->getVisibleRect();
    lua_pushinteger(L, rect.getMinX());
    lua_pushinteger(L, rect.getMaxX());
    lua_pushinteger(L, rect.getMaxY());
    lua_pushinteger(L, rect.getMinY());
    return 4;
}]])
cls.func('getVisibleSize', [[{
    auto rect = cocos2d::Director::getInstance()->getOpenGLView()->getVisibleRect();
    lua_pushinteger(L, rect.size.width);
    lua_pushinteger(L, rect.size.height);
    return 2;
}]])
cls.func('getFrameSize', [[{
    auto size = cocos2d::Director::getInstance()->getOpenGLView()->getFrameSize();
    lua_pushnumber(L, size.width);
    lua_pushnumber(L, size.height);
    return 2;
}]])
cls.func('setFrameSize', [[{
    auto glView = cocos2d::Director::getInstance()->getOpenGLView();
    float width = (float)olua_checknumber(L, 1);
    float height = (float)olua_checknumber(L, 2);
    xgame::preferences::setFloat(CONF_WINDOW_WIDTH, width);
    xgame::preferences::setFloat(CONF_WINDOW_HEIGHT, height);
    glView->setFrameSize(width, height);
    return 0;
}]])
cls.func('getDesignSize', [[{
    auto size = cocos2d::Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
    lua_pushnumber(L, size.width);
    lua_pushnumber(L, size.height);
    return 2;
}]])
cls.func('setDesignSize', [[{
    cocos2d::Director::getInstance()->getOpenGLView()->setDesignResolutionSize(
        (float)olua_checknumber(L, 1), (float)olua_checknumber(L, 2),
        (ResolutionPolicy)olua_checkinteger(L, 3));
    return 0;
}]])
cls.func('convertToCameraSpace', [[{
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
    return 2;
}]])
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'xgame::downloader::FileState'
cls.enums [[
    IOERROR
    LOADED
    PENDING
    INVALID
]]
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'xgame::downloader'
cls.funcs [[
    static void load(const xgame::downloader::FileTask &task)
    static void init()
    static void end()
]]
cls.callback {
    FUNCS =  {
        'static void setDispatcher(@local const std::function<void (const FileTask &)> callback)'
    },
    TAG_MAKER = 'Dispatcher',
    TAG_MODE = 'OLUA_TAG_REPLACE',
    TAG_STORE = nil,
    TAG_SCOPE = 'object',
}
M.CLASSES[#M.CLASSES + 1] = cls

cls = typecls 'xgame::MaskLayout'
cls.SUPERCLS = "cocos2d::ui::Layout"
cls.funcs [[
    static xgame::MaskLayout *create()
    cocos2d::DrawNode *getClippingNode()
]]
cls.props [[
    clippingNode
]]
M.CLASSES[#M.CLASSES + 1] = cls

return M
