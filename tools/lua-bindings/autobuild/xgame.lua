-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/xgame-types.lua"

NAME = "xgame"
PATH = "../../frameworks/libxgame/src/lua-bindings"
HEADERS = [[
    #include "lua-bindings/lua_conv.h"
    #include "lua-bindings/lua_conv_manual.h"
    #include "cclua/filesystem.h"
    #include "cclua/xlua.h"
    #include "cclua/preferences.h"
    #include "cclua/downloader.h"
    #include "cclua/runtime.h"
    #include "cclua/RootScene.h"
    #include "cclua/timer.h"
    #include "cclua/window.h"
    #include "olua/olua.hpp"
]]
CHUNK = [[
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
]]

typeconv 'cclua::downloader::FileTask'
    .var('url', 'std::string url')
    .var('path', 'std::string path')
    .var('md5', '@optional std::string md5')
    .var('state', '@optional cclua::downloader::FileState state')


typeconf 'cclua::SceneNoCamera'
    .supercls('cocos2d::Scene')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cclua::SceneNoCamera *create()')
    .func(nil, 'static cclua::SceneNoCamera *createWithSize(const cocos2d::Size &size)')
    .func(nil, 'static cclua::SceneNoCamera *createWithPhysics()')
    .func(nil, 'SceneNoCamera()')

typeconf 'cclua::Permission'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('AUDIO', 'cclua::Permission::AUDIO')
    .enum('CAMERA', 'cclua::Permission::CAMERA')
    .enum('PHOTO', 'cclua::Permission::PHOTO')
    .enum('IDFA', 'cclua::Permission::IDFA')

typeconf 'cclua::PermissionStatus'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('NOT_DETERMINED', 'cclua::PermissionStatus::NOT_DETERMINED')
    .enum('RESTRICTED', 'cclua::PermissionStatus::RESTRICTED')
    .enum('DENIED', 'cclua::PermissionStatus::DENIED')
    .enum('AUTHORIZED', 'cclua::PermissionStatus::AUTHORIZED')

typeconf 'cclua::runtime'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func('testCrash', [[
        {
            cclua::runtime::log("test native crash!!!!");
            char *prt = NULL;
            *prt = 0;
            return 0;
        }
    ]])
    .func(nil, 'static void clearStorage()')
    .func(nil, 'static bool launch(const std::string &scriptPath)')
    .func(nil, 'static bool restart()')
    .func(nil, 'static bool isRestarting()')
    .func(nil, 'static bool isDebug()')
    .func(nil, 'static bool isCocosThread()')
    .func(nil, 'static float getTime()')
    .func(nil, 'static void gc()')
    .func(nil, 'static const std::string getVersion()')
    .func(nil, 'static const uint64_t getCocosVersion()')
    .func(nil, 'static const std::string getPackageName()')
    .func(nil, 'static const std::string getAppVersion()')
    .func(nil, 'static const std::string getAppBuild()')
    .func(nil, 'static const std::string getChannel()')
    .func(nil, 'static const std::string getOS()')
    .func(nil, 'static const std::string getDeviceInfo()')
    .func(nil, 'static const std::string getLanguage()')
    .func(nil, 'static const std::string getManifestVersion()')
    .func(nil, 'static void setManifestVersion(const std::string &version)')
    .func(nil, 'static const std::string getNetworkStatus()')
    .func(nil, 'static const std::string getPaste()')
    .func(nil, 'static void setPaste(const std::string &text)')
    .func(nil, 'static cocos2d::RenderTexture *capture(cocos2d::Node *node, float width, float height, @optional cocos2d::backend::PixelFormat format, @optional cocos2d::backend::PixelFormat depthStencilFormat)')
    .func(nil, 'static uint32_t getMaxFrameRate()')
    .func(nil, 'static uint32_t getFrameRate()')
    .func(nil, 'static void setFrameRate(uint32_t frameRate)')
    .func(nil, 'static const cclua::PermissionStatus getPermissionStatus(cclua::Permission permission)')
    .func(nil, 'static void setAudioSessionCatalog(const std::string &catalog)')
    .func(nil, 'static const std::string getAudioSessionCatalog()')
    .func(nil, 'static bool canOpenURL(const std::string &uri)')
    .func(nil, 'static void setLogPath(const std::string &path)')
    .func(nil, 'static const std::string getLogPath()')
    .func(nil, 'static void setSampleCount(unsigned int samples)')
    .func(nil, 'static unsigned int getSampleCount()')
    .func(nil, 'static bool support(const std::string &api)')
    .func(nil, 'static void printSupport()')
    .func(nil, 'static void disableReport()')
    .callback {
        FUNCS =  {
            'static void setDispatcher(@local const std::function<void (const std::string &, const std::string &)> &dispatcher)'
        },
        TAG_MAKER = 'Dispatcher',
        TAG_MODE = 'OLUA_TAG_REPLACE',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'static void openURL(const std::string &uri, @local @optional const std::function<void (bool)> callback)'
        },
        TAG_MAKER = 'openURL',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_STORE = nil,
        TAG_SCOPE = 'once',
    }
    .callback {
        FUNCS =  {
            'static void requestPermission(cclua::Permission permission, @local const std::function<void (cclua::PermissionStatus)> callback)'
        },
        TAG_MAKER = 'requestPermission',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_STORE = nil,
        TAG_SCOPE = 'once',
    }
    .callback {
        FUNCS =  {
            'static void alert(const std::string &title, const std::string &message, const std::string &ok, const std::string &no, @local const std::function<void (bool)> callback)'
        },
        TAG_MAKER = 'alert',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_STORE = nil,
        TAG_SCOPE = 'once',
    }
    .prop('restarting', nil, nil)
    .prop('debug', nil, nil)
    .prop('cocosThread', nil, nil)
    .prop('time', nil, nil)
    .prop('version', nil, nil)
    .prop('cocosVersion', nil, nil)
    .prop('packageName', nil, nil)
    .prop('appVersion', nil, nil)
    .prop('appBuild', nil, nil)
    .prop('channel', nil, nil)
    .prop('os', nil, nil)
    .prop('deviceInfo', nil, nil)
    .prop('language', nil, nil)
    .prop('manifestVersion', nil, nil)
    .prop('networkStatus', nil, nil)
    .prop('paste', nil, nil)
    .prop('maxFrameRate', nil, nil)
    .prop('frameRate', nil, nil)
    .prop('audioSessionCatalog', nil, nil)
    .prop('logPath', nil, nil)
    .prop('sampleCount', nil, nil)

typeconf 'cclua::filesystem'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static const std::string getWritablePath()')
    .func(nil, 'static const std::string getCacheDirectory()')
    .func(nil, 'static const std::string getDocumentDirectory()')
    .func(nil, 'static const std::string getTmpDirectory()')
    .func(nil, 'static const std::string getBuiltinCacheDirectory()')
    .func(nil, 'static const std::string getSDCardDirectory()')
    .func(nil, 'static void addSearchPath(const std::string &path, @optional bool front)')
    .func(nil, 'static const std::string shortPath(const std::string &path, @optional size_t limit)')
    .func(nil, 'static const std::string fullPath(const std::string &path)')
    .func(nil, 'static bool createDirectory(const std::string &path, @optional bool isFilePath)')
    .func(nil, 'static bool remove(const std::string &path)')
    .func(nil, 'static bool exist(const std::string &path)')
    .func(nil, 'static bool isFile(const std::string &path)')
    .func(nil, 'static bool isDirectory(const std::string &path)')
    .func(nil, 'static bool rename(const std::string &oldPath, const std::string &newPath)')
    .func(nil, 'static bool copy(const std::string &srcPath, const std::string &destPath)')
    .func(nil, 'static bool write(const std::string &path, const char *data, size_t len)', 'static bool write(const std::string &path, const cocos2d::Data &data)')
    .func(nil, 'static cocos2d::Data read(const std::string &path)')
    .func(nil, 'static bool unzip(const std::string &path, const std::string &dest)')
    .prop('writablePath', nil, nil)
    .prop('cacheDirectory', nil, nil)
    .prop('documentDirectory', nil, nil)
    .prop('tmpDirectory', nil, nil)
    .prop('builtinCacheDirectory', nil, nil)
    .prop('sdCardDirectory', nil, nil)

typeconf 'cclua::preferences'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static bool getBoolean(const char *key, @optional bool defaultValue)')
    .func(nil, 'static void setBoolean(const char *key, bool value)')
    .func(nil, 'static float getFloat(const char *key, @optional float defaultValue)')
    .func(nil, 'static void setFloat(const char *key, float value)')
    .func(nil, 'static double getDouble(const char *key, @optional double defaultValue)')
    .func(nil, 'static void setDouble(const char *key, double value)')
    .func(nil, 'static int getInteger(const char *key, @optional int defaultValue)')
    .func(nil, 'static void setInteger(const char *key, int value)')
    .func(nil, 'static std::string getString(const char *key, @optional const char *defaultValue)')
    .func(nil, 'static void setString(const char *key, const char *value)')
    .func(nil, 'static void deleteKey(const char *key)')
    .func(nil, 'static void flush()')

typeconf 'cclua::timer'
    .supercls(nil)
    .reg_luatype(true)
    .chunk([[#define makeTimerDelayTag(tag) ("delayTag." + tag)]])
    .require(nil)
    .func('schedule', [[
        {
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
            return 1;
        }
    ]])
    .func('unschedule', [[
        {
            uint64_t value = olua_checkinteger(L, 1);
            uint32_t callback = value >> 32;
            uint32_t id = value & 0xFFFFFFFF;
            olua_unref(L, callback);
            cclua::timer::unschedule(id);
            return 0;
        }
    ]])
    .func(nil, 'static std::string createTag()')
    .callback {
        FUNCS =  {
            'static void delayWithTag(float time, const std::string &tag, @local std::function<void ()> callback)'
        },
        TAG_MAKER = 'makeTimerDelayTag(#2)',
        TAG_MODE = 'OLUA_TAG_REPLACE',
        TAG_STORE = nil,
        TAG_SCOPE = 'once',
    }
    .callback {
        FUNCS =  {
            'static void killDelay(const std::string &tag)'
        },
        TAG_MAKER = 'makeTimerDelayTag(#1)',
        TAG_MODE = 'OLUA_TAG_SUBEQUAL',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }
    .callback {
        FUNCS =  {
            'static void delay(float time, @local const std::function<void ()> callback)'
        },
        TAG_MAKER = 'delay',
        TAG_MODE = 'OLUA_TAG_NEW',
        TAG_STORE = nil,
        TAG_SCOPE = 'once',
    }

typeconf 'cclua::window'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, '@unpack static cclua::window::Bounds getVisibleBounds()')
    .func(nil, '@unpack static cocos2d::Size getVisibleSize()')
    .func(nil, '@unpack static cocos2d::Size getFrameSize()')
    .func(nil, 'static void setFrameSize(@pack const cocos2d::Size &size)')
    .func(nil, '@unpack static cocos2d::Size getDesignSize()')
    .func(nil, 'static void setDesignSize(@pack const cocos2d::Size &size, ResolutionPolicy resolutionPolicy)')
    .func(nil, 'static cocos2d::Vec2 convertToCameraSpace(@pack const cocos2d::Vec2 &position)')
    .prop('visibleBounds', nil, nil)
    .prop('visibleSize', nil, nil)
    .prop('frameSize', nil, nil)
    .prop('designSize', nil, nil)

typeconf 'cclua::downloader::FileState'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .enum('IOERROR', 'cclua::downloader::FileState::IOERROR')
    .enum('LOADED', 'cclua::downloader::FileState::LOADED')
    .enum('PENDING', 'cclua::downloader::FileState::PENDING')
    .enum('INVALID', 'cclua::downloader::FileState::INVALID')

typeconf 'cclua::downloader'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static void load(const cclua::downloader::FileTask &task)')
    .func(nil, 'static void init()')
    .func(nil, 'static void end()')
    .callback {
        FUNCS =  {
            'static void setDispatcher(@local const std::function<void (const cclua::downloader::FileTask &)> callback)'
        },
        TAG_MAKER = 'Dispatcher',
        TAG_MODE = 'OLUA_TAG_REPLACE',
        TAG_STORE = nil,
        TAG_SCOPE = 'object',
    }

typeconf 'cclua::MaskLayout'
    .supercls('cocos2d::ui::Layout')
    .reg_luatype(true)
    .chunk(nil)
    .require(nil)
    .func(nil, 'static cclua::MaskLayout *create()')
    .func(nil, 'MaskLayout()')
    .func(nil, 'cocos2d::DrawNode *getClippingNode()')
    .func(nil, 'void setFilter(@nullable@addref(filter ^) cocos2d::Node *value)')
    .func(nil, '@addref(filter ^) cocos2d::Node *getFilter()')
    .prop('clippingNode', nil, nil)
    .prop('filter', nil, nil)
