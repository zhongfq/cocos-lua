-- AUTO BUILD, DON'T MODIFY!

dofile "autobuild/xgame-types.lua"

name = "xgame"
path = "../../frameworks/libxgame/src/lua-bindings"
headers = [[
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
chunk = [[
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
luaopen = nil


typeconf 'cclua::SceneNoCamera'
    .supercls('cocos2d::Scene')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cclua::SceneNoCamera *create()')
    .func(nil, 'static cclua::SceneNoCamera *createWithSize(const cocos2d::Size &size)')
    .func(nil, 'static cclua::SceneNoCamera *createWithPhysics()')
    .func(nil, 'SceneNoCamera()')

typeconf 'cclua::Permission'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .enum('AUDIO', 'cclua::Permission::AUDIO')
    .enum('CAMERA', 'cclua::Permission::CAMERA')
    .enum('PHOTO', 'cclua::Permission::PHOTO')
    .enum('IDFA', 'cclua::Permission::IDFA')

typeconf 'cclua::PermissionStatus'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .enum('NOT_DETERMINED', 'cclua::PermissionStatus::NOT_DETERMINED')
    .enum('RESTRICTED', 'cclua::PermissionStatus::RESTRICTED')
    .enum('DENIED', 'cclua::PermissionStatus::DENIED')
    .enum('AUTHORIZED', 'cclua::PermissionStatus::AUTHORIZED')

typeconf 'cclua::runtime'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
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
    .func(nil, 'static std::string getEnv(const std::string &key)')
    .func(nil, 'static void setEnv(const std::string &key, const std::string &value, @optional bool save)')
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
    .func(nil, 'static void showLog()')
    .func(nil, 'static void setSampleCount(unsigned int samples)')
    .func(nil, 'static unsigned int getSampleCount()')
    .func(nil, 'static bool support(const std::string &api)')
    .func(nil, 'static void printSupport()')
    .func(nil, 'static void disableReport()')
    .func(nil, '@addref(programCache ^ director) static cocos2d::backend::ProgramCache *getProgramCache()')
    .func(nil, '@addref(fileUtils ^ director) static cocos2d::FileUtils *getFileUtils()')
    .func(nil, '@addref(spriteFrameCache ^ director) static cocos2d::SpriteFrameCache *getSpriteFrameCache()')
    .func(nil, '@addref(textureCache ^ director) static cocos2d::TextureCache *getTextureCache()')
    .func(nil, '@addref(scheduler ^ director) static cocos2d::Scheduler *getScheduler()')
    .func(nil, '@addref(actionManager ^ director) static cocos2d::ActionManager *getActionManager()')
    .func(nil, '@addref(eventDispatcher ^ director) static cocos2d::EventDispatcher *getEventDispatcher()')
    .func(nil, 'static bool isDisplayStats()')
    .func(nil, 'static void setDisplayStats(bool displayStats)')
    .func(nil, '@addref(scenes | director) static cocos2d::Scene *getRunningScene()')
    .func(nil, 'static void pushScene(@addref(scenes | director) cocos2d::Scene *scene)')
    .func(nil, '@delref(scenes ~ director) static void replaceScene(@addref(scenes | director) cocos2d::Scene *scene)')
    .func(nil, '@delref(scenes ~ director) static void popScene()')
    .func(nil, '@delref(scenes ~ director) static void popToRootScene()')
    .func(nil, 'static void purgeCachedData()')
    .func(nil, 'static void exit()')
    .callback {
        funcs =  {
            'static void setDispatcher(@localvar const std::function<void (const std::string &, const std::string &)> &dispatcher)'
        },
        tag_maker = 'Dispatcher',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }
    .callback {
        funcs =  {
            'static void openURL(const std::string &uri, @localvar @optional const std::function<void (bool)> callback)'
        },
        tag_maker = 'openURL',
        tag_mode = 'new',
        tag_store = 0,
        tag_scope = 'once',
    }
    .callback {
        funcs =  {
            'static void requestPermission(cclua::Permission permission, @localvar const std::function<void (cclua::PermissionStatus)> callback)'
        },
        tag_maker = 'requestPermission',
        tag_mode = 'new',
        tag_store = 0,
        tag_scope = 'once',
    }
    .callback {
        funcs =  {
            'static void alert(const std::string &title, const std::string &message, const std::string &ok, const std::string &no, @localvar const std::function<void (bool)> callback)'
        },
        tag_maker = 'alert',
        tag_mode = 'new',
        tag_store = 0,
        tag_scope = 'once',
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
    .prop('programCache', nil, nil)
    .prop('fileUtils', nil, nil)
    .prop('spriteFrameCache', nil, nil)
    .prop('textureCache', nil, nil)
    .prop('scheduler', nil, nil)
    .prop('actionManager', nil, nil)
    .prop('eventDispatcher', nil, nil)
    .prop('displayStats', nil, nil)
    .prop('runningScene', nil, nil)
    .insert('getProgramCache', {
        before = [[
            olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance());
            int director = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('getFileUtils', {
        before = [[
            olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance());
            int director = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('getSpriteFrameCache', {
        before = [[
            olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance());
            int director = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('getTextureCache', {
        before = [[
            olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance());
            int director = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('getScheduler', {
        before = [[
            olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance());
            int director = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('getActionManager', {
        before = [[
            olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance());
            int director = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('getEventDispatcher', {
        before = [[
            olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance());
            int director = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('getRunningScene', {
        before = [[
            olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance());
            int director = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('pushScene', {
        before = [[
            olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance());
            int director = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('replaceScene', {
        before = [[
            olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance());
            int director = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('popScene', {
        before = [[
            olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance());
            int director = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })
    .insert('popToRootScene', {
        before = [[
            olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance());
            int director = lua_gettop(L);
        ]],
        after = nil,
        cbefore = nil,
        cafter = nil,
    })

typeconf 'cclua::filesystem'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
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
    .luaopen(nil)
    .func(nil, 'static bool getBoolean(const std::string &key, @optional bool defaultValue)')
    .func(nil, 'static void setBoolean(const std::string &key, bool value)')
    .func(nil, 'static float getFloat(const std::string &key, @optional float defaultValue)')
    .func(nil, 'static void setFloat(const std::string &key, float value)')
    .func(nil, 'static double getDouble(const std::string &key, @optional double defaultValue)')
    .func(nil, 'static void setDouble(const std::string &key, double value)')
    .func(nil, 'static int getInteger(const std::string &key, @optional int defaultValue)')
    .func(nil, 'static void setInteger(const std::string &key, int value)')
    .func(nil, 'static std::string getString(const std::string &key, @optional const std::string &defaultValue)')
    .func(nil, 'static void setString(const std::string &key, const std::string &value)')
    .func(nil, 'static void deleteKey(const std::string &key)')
    .func(nil, 'static void flush()')

typeconf 'cclua::timer'
    .supercls(nil)
    .reg_luatype(true)
    .chunk([[#define makeTimerDelayTag(tag) ("delayTag." + tag)]])
    .luaopen(nil)
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
        funcs =  {
            'static void delayWithTag(float time, const std::string &tag, @localvar std::function<void ()> callback)'
        },
        tag_maker = 'makeTimerDelayTag(#2)',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'once',
    }
    .callback {
        funcs =  {
            'static void killDelay(const std::string &tag)'
        },
        tag_maker = 'makeTimerDelayTag(#1)',
        tag_mode = 'subequal',
        tag_store = 0,
        tag_scope = 'object',
    }
    .callback {
        funcs =  {
            'static void delay(float time, @localvar const std::function<void ()> callback)'
        },
        tag_maker = 'delay',
        tag_mode = 'new',
        tag_store = 0,
        tag_scope = 'once',
    }

typeconf 'cclua::window'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
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

typeconf 'cclua::downloader'
    .supercls(nil)
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static void load(const std::string &uri, const std::string &path, @optional const std::string &md5)')
    .func(nil, 'static void init()')
    .func(nil, 'static void end()')
    .callback {
        funcs =  {
            'static void setDispatcher(@localvar const std::function<void (const std::string &, const std::string &)> &dispatcher)'
        },
        tag_maker = 'Dispatcher',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }
    .callback {
        funcs =  {
            'static void setURIResolver(@localvar const std::function<std::string (const std::string &)> &resolver)'
        },
        tag_maker = 'URIResolver',
        tag_mode = 'replace',
        tag_store = 0,
        tag_scope = 'object',
    }

typeconf 'cclua::MaskLayout'
    .supercls('cocos2d::ui::Layout')
    .reg_luatype(true)
    .chunk(nil)
    .luaopen(nil)
    .func(nil, 'static cclua::MaskLayout *create()')
    .func(nil, 'MaskLayout()')
    .func(nil, 'cocos2d::DrawNode *getClippingNode()')
    .func(nil, 'void setFilter(@nullable@addref(filter ^) cocos2d::Node *value)')
    .func(nil, '@addref(filter ^) cocos2d::Node *getFilter()')
    .prop('clippingNode', nil, nil)
    .prop('filter', nil, nil)
