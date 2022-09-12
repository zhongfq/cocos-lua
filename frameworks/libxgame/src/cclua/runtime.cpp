#include "cclua/runtime.h"
#include "cclua/runtime-private.h"
#include "cclua/filesystem.h"
#include "cclua/FileFinder.h"
#include "cclua/downloader.h"
#include "cclua/preferences.h"
#include "cclua/permission.h"
#include "cclua/RootScene.h"
#include "cclua/timer.h"
#include "cclua/window.h"
#include "cclua/plugin.h"
#include "lua-bindings/lua_bindings.h"
#include "lua-bindings/lua_conv_manual.h"
#include "ui/CocosGUI.h"

#if defined(CCLUA_OS_ANDROID) || defined(CCLUA_OS_IOS)
#include "bugly/CrashReport.h"
#endif

#include "audio/include/AudioEngine.h"

#include <time.h>
#include <stdarg.h>
#include <thread>
#include <deque>
#include <map>

USING_NS_CC;
USING_NS_CCLUA;

#define CCLUA_ENV_PREFIX "cclua-env."

static bool _restarting = false;
static lua_State *_luaVM = nullptr;
static std::vector<lua_CFunction> _luaLibs;
static Callback _dispatcher = nullptr;
static std::vector<std::pair<std::string, cocos2d::Value>> _suspendedEvents;
static std::string _openURI;
static std::map<std::string, bool> _supportedFeatures;
static std::unordered_map<std::string, bool> _tracebackCaches;
static std::unordered_map<std::string, std::string> _envs;
static int _sampleCount = 1;
static std::unordered_map<olua_Ref, Callback> _refCallbacks;
static olua_Ref _refCount = -2;

static float _time = 0;
static FILE *_logFile = NULL;
static std::mutex _logMutex;
static std::string _logPath;
static std::string _workdir;
static bool _reportError = true;

void runtime::parseLaunchArgs(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++) {
        runtime::log("launch args: %s", argv[i]);
    }
    for (int i = 0; i < argc; i++) {
        if (strequal(argv[i], "--workdir") && i < argc - 1) {
            _workdir = argv[++i];
        }
    }
}

void runtime::init()
{
    FileFinder::setDelegate(FileFinder::create());
    filesystem::addSearchPath(filesystem::getDocumentDirectory() + "/assets", true);
    filesystem::addSearchPath(_workdir, true);
    runtime::setFrameRate(60);
    Director::getInstance()->setDisplayStats(runtime::isDebug());
    
#ifdef CCLUA_OS_ANDROID
    __runtime_pullAllFeatures();
    runtime::setLogPath(filesystem::getDirectory("external.cache") + "/console.log");
    runtime::getPackageName();
    runtime::getAppName();
    runtime::getDeviceInfo();
    runtime::getLanguage();
    filesystem::getDocumentDirectory();
    filesystem::getCacheDirectory();
    filesystem::getTmpDirectory();
    filesystem::getSDCardDirectory();
#else
    runtime::setLogPath(filesystem::getCacheDirectory() + "/console.log");
#endif
    
    // create paths
    filesystem::createDirectory(filesystem::getCacheDirectory());
    filesystem::createDirectory(filesystem::getTmpDirectory());
    filesystem::createDirectory(filesystem::getDocumentDirectory() + "/assets");
    
    // clean cache if version changed
    std::string appVersion = preferences::getString(CONF_APP_VERSION);
    std::string appBuild = preferences::getString(CONF_APP_BUILD);
    if (appBuild != runtime::getAppBuild() || appVersion != runtime::getAppVersion()) {
        runtime::clearStorage();
        runtime::log("app update to version: %s(%s)", runtime::getAppVersion().c_str(),
            runtime::getAppBuild().c_str());
    }
    preferences::setString(CONF_APP_VERSION, runtime::getAppVersion().c_str());
    preferences::setString(CONF_APP_BUILD, runtime::getAppBuild().c_str());
    preferences::flush();
    
    timer::schedule(0, timer::createTag(), [](float dt){ _time += dt; });
    
#if COCOS2D_VERSION >= 0x00040000
    Texture2D::setDefaultAlphaPixelFormat(backend::PixelFormat::AUTO);
#else
    Texture2D::setDefaultAlphaPixelFormat(Texture2D::PixelFormat::AUTO);
#endif
    AudioEngine::lazyInit();
    
    // cocos event
    runtime::on(Director::EVENT_BEFORE_UPDATE, []() {
        runtime::dispatch("runtimeUpdate");
    });
    runtime::on(Director::EVENT_PROJECTION_CHANGED, []() {
        runtime::dispatch("runtimeResize");
    });
}

bool runtime::isCocosThread()
{
    static std::thread::id unknow;
    const std::thread::id &current = Director::getInstance()->getCocos2dThreadId();
    return current == unknow || current == std::this_thread::get_id();
}

float runtime::getTime()
{
    return _time;
}

void runtime::gc()
{
    lua_State *L = runtime::luaVM();
    runtime::dispatch("runtimeGC");
    lua_gc(L, LUA_GCCOLLECT, 0);
    runtime::log("lua mem: %.3fM", lua_gc(L, LUA_GCCOUNT, 0) / 1024.0f);
}

void runtime::clearStorage()
{
    filesystem::remove(filesystem::getBuiltinCacheDirectory());
    filesystem::remove(filesystem::getDocumentDirectory() + "/assets");
    filesystem::createDirectory(filesystem::getDocumentDirectory() + "/assets");
    runtime::log("app clean version: %s(%s)", runtime::getAppVersion().c_str(),
        runtime::getAppBuild().c_str());
    
    preferences::deleteKey(CONF_APP_VERSION);
    preferences::deleteKey(CONF_APP_BUILD);
    preferences::flush();
}

class RestartImpl : public Node {
public:
    RestartImpl(const std::string &scriptPath):_scriptPath(scriptPath) {};
    virtual ~RestartImpl() {
        std::string scriptPath = _scriptPath;
        runtime::runLater([scriptPath]() {
            lua_close(_luaVM);
            _luaVM = nullptr;
            _restarting = false;
            _refCallbacks.clear();
            AudioEngine::end();
            runtime::init();
            runtime::launch(scriptPath);
        });
    };
private:
    std::string _scriptPath;
};

bool runtime::launch(const std::string &scriptPath)
{
    auto director = Director::getInstance();
    
    if (director->getRunningScene() == nullptr) {
        runtime::log("launch '%s'", scriptPath.c_str());
        auto scene = RootScene::create(scriptPath);
        director->replaceScene(scene);
        return true;
    } else if (!_restarting) {
        _restarting = true;
        _dispatcher = nullptr;
        _openURI = "";
        
        AudioEngine::stopAll();
        director->restart();
        
        auto imp = new RestartImpl(scriptPath);
        director->setNotificationNode(imp);
        imp->release();
        return true;
    } else {
        return false;
    }
}

bool runtime::isRestarting()
{
    return _restarting;
}

bool runtime::isDebug()
{
#ifdef COCOS2D_DEBUG
    return true;
#else
    return false;
#endif
}

bool runtime::restart()
{
    if (runtime::launch("bootstrap.lua")) {
        runtime::log("runtime restart!!!");
        return true;
    } else {
        runtime::log("runtime already in restarting!!!");
        return false;
    }
}

lua_State *runtime::luaVM()
{
    if (_luaVM == nullptr) {
        _luaVM = cclua_new();
        luaopen_bindings(_luaVM);
        for (auto func : _luaLibs) {
            olua_callfunc(_luaVM, func);
        }
        olua_pushobj<cocos2d::Director>(_luaVM, cocos2d::Director::getInstance());
        lua_setfield(_luaVM, LUA_REGISTRYINDEX, "__cocos2d_ref_chain__");
    }
    return _luaVM;
}

void runtime::luaOpen(lua_CFunction libfunc)
{
    bool exist = false;
    for (auto func : _luaLibs) {
        if (func == libfunc) {
            exist = true;
            break;
        }
    }
    if (!exist) {
        _luaLibs.push_back(libfunc);
    }
}

void runtime::testCrash()
{
    runtime::log("test native crash!!!!");
    char *prt = NULL;
    *prt = 0;
}

static int index_func(lua_State *L)
{
    if (olua_isstring(L, lua_upvalueindex(2))) {
        const char *name = olua_tostring(L, lua_upvalueindex(1));
        const char *func = olua_tostring(L, lua_upvalueindex(2));
        cclua::runtime::log("function '%s.%s' not supported", name, func);
        return 0;
    } else {
        const char *func = olua_tostring(L, 2);
        lua_pushvalue(L, lua_upvalueindex(1));
        lua_pushstring(L, func);
        lua_pushcclosure(L, index_func, 2);
        return 1;
    }
}

olua_Return runtime::load(lua_State *L, const std::string &name)
{
    return runtime::load(L, name, name);
}

olua_Return runtime::load(lua_State *L, const std::string &name, const std::string &feature)
{
    if (cclua::runtime::hasFeature(feature)) {
        lua_getfield(L, LUA_REGISTRYINDEX, LUA_LOADED_TABLE);
        if (olua_rawgetf(L, -1, name.c_str()) == LUA_TTABLE) {
            return 1;
        }
    }

    cclua::runtime::log("module '%s' is not available", name.c_str());
    lua_newtable(L);
    lua_newtable(L);
    lua_pushvalue(L, 1);
    lua_pushcclosure(L, index_func, 1);
    olua_rawsetf(L, -2, "__index");
    lua_setmetatable(L, -2);
    lua_getfield(L, LUA_REGISTRYINDEX, LUA_LOADED_TABLE);
    lua_pushvalue(L, 1);
    lua_pushvalue(L, -3);
    lua_rawset(L, -3);
    lua_pop(L, 1);
    return 1;
}

//
// app info
//
std::string runtime::getVersion()
{
    return CCLUA_VERSION;
}

uint64_t runtime::getCocosVersion()
{
    return COCOS2D_VERSION;
}

std::string runtime::getPackageName()
{
    return __runtime_getPackageName();
}

std::string runtime::getAppName()
{
    return __runtime_getAppName();
}

std::string runtime::getAppVersion()
{
    return __runtime_getAppVersion();
}

std::string runtime::getAppBuild()
{
    return __runtime_getAppBuild();
}

std::string runtime::getChannel()
{
    return __runtime_getChannel();
}

std::string runtime::getOS()
{
    return CCLUA_OS_NAME;
}

std::string runtime::getDeviceInfo()
{
    return __runtime_getDeviceInfo();
}

std::string runtime::getLanguage()
{
    return __runtime_getLanguage();
}

std::string runtime::getManifestVersion()
{
    return preferences::getString(CONF_MANIFEST_VERSION, "0.0.0");
}

void runtime::setManifestVersion(const std::string &version)
{
    preferences::setString(CONF_MANIFEST_VERSION, version.c_str());
}

std::string runtime::getNetworkStatus()
{
    return __runtime_getNetworkStatus();
}

std::string runtime::getEnv(const std::string &key)
{
    if (_envs.find(key) != _envs.end()) {
        return _envs[key];
    }
    return preferences::getString(CCLUA_ENV_PREFIX + key);
}

void runtime::setEnv(const std::string &key, const std::string &value, bool save)
{
    if (save) {
        if (value == "") {
            preferences::deleteKey(CCLUA_ENV_PREFIX + key);
        } else {
            preferences::setString(CCLUA_ENV_PREFIX + key, value);
        }
    }
    if (value == "") {
        _envs.erase(key);
    } else {
        _envs[key] = value;
    }
}

std::string runtime::getPaste()
{
    return __runtime_getPaste();
}

void runtime::setPaste(const std::string &text)
{
    __runtime_setPaste(text);
}

#if COCOS2D_VERSION >= 0x00040000
Sprite *runtime::capture(Node *node, float width, float height, float scale, backend::PixelFormat format, backend::PixelFormat depthStencilFormat)
#else
Sprite *runtime::capture(Node *node, float width, float height, float scale, Texture2D::PixelFormat format, GLuint depthStencilFormat)
#endif
{
    width *= scale;
    height *= scale;
    auto director = Director::getInstance();
    auto rt = RenderTexture::create((int)width, (int)height, format, depthStencilFormat);
    auto image = rt->getSprite();
    image->setIgnoreAnchorPointForPosition(true);
    image->setScale(1.0f / scale);
    image->setAnchorPoint(Vec2::ZERO);
    image->retain();
    image->removeFromParent();
    rt->retain();
    node->retain();
    
#if COCOS2D_VERSION >= 0x00040000
    runtime::once(Director::EVENT_BEFORE_DRAW, [=]() {
#endif
        bool lastVisible = node->isVisible();
        Vec2 lastPosition = node->getPosition();
        Vec2 lastAnchor = node->getAnchorPoint();
        Vec2 lastScale = Vec2(node->getScaleX(), node->getScaleY());
        node->setVisible(true);
        node->setAnchorPoint(Vec2::ZERO);
        node->setPosition(Vec2::ZERO);
        node->setScale(node->getScaleX() * scale, node->getScaleY() * scale);
        rt->begin();
        node->visit();
        rt->end();
        node->setAnchorPoint(lastAnchor);
        node->setScale(lastScale.x, lastScale.y);
        node->setPosition(lastPosition);
        node->setVisible(lastVisible);
        
        runtime::once(Director::EVENT_AFTER_DRAW, [=]() {
            rt->release();
            image->release();
            node->release();
        });
#if COCOS2D_VERSION >= 0x00040000
    });
#else
    director->getRenderer()->render();
#endif
    
    return image;
}

void runtime::setAudioSessionCatalog(const std::string &catalog)
{
#ifdef CCLUA_OS_IOS
    __runtime_setAudioSessionCatalog(catalog);
#else
    runtime::log("runtime::setAudioSessionCatalog not support on '%s'", runtime::getOS().c_str());
#endif
}

std::string runtime::getAudioSessionCatalog()
{
#ifdef CCLUA_OS_IOS
    return __runtime_getAudioSessionCatalog();
#else
    return "";
#endif
}

uint32_t runtime::getMaxFrameRate()
{
    return __runtime_getMaxFrameRate();
}

uint32_t runtime::getFrameRate()
{
    return (uint32_t)round(1.0 / Director::getInstance()->getAnimationInterval());
}

void runtime::setFrameRate(uint32_t frameRate)
{
    if (runtime::getFrameRate() != frameRate) {
        CCASSERT(frameRate > 0, "frameRate > 0");
        Director::getInstance()->setAnimationInterval(1.0f / (float)frameRate);
    }
}

std::string runtime::getPermission(const std::string &permission)
{
#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)
    return __runtime_getPermission(permission);
#else
    return permission::status::NOT_DETERMINED;
#endif
}

void runtime::requestPermission(const std::string &permission, const std::function<void (const std::string &)> &callback)
{
#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)
    __runtime_requestPermission(permission, callback);
#else
    callback(permission::status::DENIED);
#endif
}

void runtime::alert(const std::string &title, const std::string &message, const std::string &ok, const std::string &no, const std::function<void (bool)> &callback)
{
#ifdef CCLUA_OS_IOS
    __runtime_alert(title, message, ok, no, callback);
#else
    callback(false);
#endif
}

//
// event dispatch
//
void runtime::setDispatcher(const Callback &dispatcher)
{
    _dispatcher = dispatcher;
    if (_dispatcher) {
        auto events = _suspendedEvents;
        _suspendedEvents.clear();
        for (auto &it : events) {
            runtime::dispatch(it.first, it.second);
        }
    }
}

void runtime::dispatch(const std::string &event, const cocos2d::Value &args)
{
    if (runtime::isCocosThread()) {
        if (_dispatcher) {
            _dispatcher(event, args);
        } else {
            _suspendedEvents.push_back(std::make_pair(event, args));
        }
    } else {
        runtime::runLater([event, args]() {
            runtime::dispatch(event, args);
        });
    }
}

void runtime::dispatch(const std::string &event, const std::string &args)
{
    runtime::dispatch(event, cocos2d::Value(args));
}

void runtime::runLater(const std::function<void ()> &callback)
{
    Director::getInstance()->getScheduler()->performFunctionInCocosThread(callback);
}

void runtime::openURL(const std::string &uri, const std::function<void (bool)> callback)
{
    __runtime_openURL(uri, callback);
}

void runtime::handleOpenURL(const std::string &uri)
{
    _openURI = uri;
    runtime::dispatch("openURL", uri);
}

bool runtime::canOpenURL(const std::string &uri)
{
    return __runtime_canOpenURL(uri);
}

void runtime::installAPK(const std::string &path)
{
#ifdef CCLUA_OS_ANDROID
    __runtime_installAPK(path);
#else
    runtime::log("runtime::installAPK not support on '%s'", runtime::getOS().c_str());
#endif
}

void runtime::callref(olua_Ref func, const std::string &status, const std::string &data, bool once)
{
    if (!cclua::runtime::isRestarting()) {
        runtime::runLater([=]() {
            ValueMap args;
            plugin::parseJSONString(data, args);
            if (func < 0) {
                Callback callback = _refCallbacks[func];
                if (callback) {
                    callback(status, Value(args));
                    if (once) {
                        runtime::unref(func);
                    }
                }
            } else {
                lua_State *L = olua_mainthread(NULL);
                int top = lua_gettop(L);
                olua_pusherrorfunc(L);
                olua_getref(L, (int)func);
                if (!lua_isnil(L, -1)) {
                    lua_pushstring(L, status.c_str());
                    olua_push_cocos2d_ValueMap(L, &args);
                    lua_pcall(L, 2, 0, top + 1);
                } else {
                    cclua::runtime::log("attempt to call nil: %d %s", (int)func, data.c_str());
                }
                if (once) {
                    olua_unref(L, (int)func);
                }
                lua_settop(L, top);
            }
        });
    }
}

olua_Ref runtime::ref(const Callback &callback)
{
    _refCount--;
    _refCallbacks[_refCount] = callback;
    return _refCount;
}

void runtime::unref(olua_Ref func)
{
    _refCallbacks.erase(func);
}

void runtime::once(const std::string &event, const std::function<void()> &callback)
{
    auto director = Director::getInstance();
    EventListenerCustom *listener = new EventListenerCustom();
    listener->init(event, [=](EventCustom *) {
        callback();
        director->getEventDispatcher()->removeEventListener(listener);
        listener->release();
    });
    director->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);
}

void runtime::on(const std::string &event, const std::function<void()> &callback)
{
    auto director = Director::getInstance();
    director->getEventDispatcher()->addCustomEventListener(event, [=](EventCustom *) {
        callback();
    });
}

//
// log
//
void runtime::setLogPath(const std::string &path)
{
    if (_logFile) {
        fclose(_logFile);
        _logFile = nullptr;
    }
    
    _logPath = path;
    _logFile = fopen(path.c_str(), "w");
    
    runtime::log("[%s] set log path: %s", BOOL_STR(_logFile), filesystem::trimPath(path).c_str());
}

std::string runtime::getLogPath()
{
    return _logPath;
}

#if defined(CCLUA_OS_WIN32)
void SendLogToWindow(const char *log)
{
    static const int CCLOG_STRING_TAG = 1;
    // Send data as a message
    COPYDATASTRUCT myCDS;
    myCDS.dwData = CCLOG_STRING_TAG;
    myCDS.cbData = (DWORD)strlen(log) + 1;
    myCDS.lpData = (PVOID)log;
    if (Director::getInstance()->getOpenGLView())
    {
        HWND hwnd = Director::getInstance()->getOpenGLView()->getWin32Window();
        // use non-block version of SendMessage 
        PostMessage(hwnd,
            WM_COPYDATA,
            (WPARAM)(HWND)hwnd,
            (LPARAM)(LPVOID)&myCDS);

    }
}
#endif

void runtime::log(const char *fmt, ...)
{
    std::lock_guard<std::mutex> lock(_logMutex);

    static char s_buf[MAX_LOG_LENGTH] = {0};
    
    va_list args;
    int bufsize = MAX_LOG_LENGTH;
    char* buf = nullptr;
    int buflen = 0;
    do {
        if (bufsize > MAX_LOG_LENGTH) {
            buf = (char*)malloc(bufsize * sizeof(char));
        } else {
            buf = s_buf;
        }
        if (buf == nullptr)
            return;

        time_t t = time(NULL);
        struct tm* stm = localtime(&t);
        int tlen = snprintf(buf, bufsize, "[%02d:%02d:%02d] ", stm->tm_hour, stm->tm_min, stm->tm_sec);
        
        va_start(args, fmt);
        buflen = vsnprintf(buf + tlen, bufsize - (3 + tlen), fmt, args);
        va_end(args);

        if (buflen >= 0) {
            if (buflen <= bufsize - (3 + tlen)) {
                buflen += tlen;
                break;
            } else {
                bufsize = buflen + (3 + tlen);
                if (buf != s_buf) {
                    free(buf);
                }
            }
        } else {
            bufsize *= 2;
            if (buf != s_buf) {
                free(buf);
            }
        }
    } while (true);
    buf[buflen] = '\n';
    buf[++buflen] = '\0';

    // write to file
    static std::string s_cache;
    if (_logFile) {
        if (!s_cache.empty()) {
            fwrite(s_cache.c_str(), sizeof(char), (size_t)s_cache.size(), _logFile);
            s_cache.clear();
        }
        fwrite(buf, sizeof(char), buflen, _logFile);
        fflush(_logFile);
    }
    else {
        s_cache.append(buf);
    }
    
#if defined(CCLUA_OS_ANDROID) || defined(CCLUA_OS_IOS)
    if (_reportError) {
        if (runtime::isCocosThread()) {
            bugly::log(bugly::Verbose, buf);
        } else {
            std::string msg = buf;
            runtime::runLater([msg]() {
                bugly::log(bugly::Verbose, msg.c_str());
            });
        }
    }
#endif
    
#if defined(CCLUA_OS_ANDROID)
    __android_log_print(ANDROID_LOG_DEBUG, "cclua debug info", "%s", buf);
#elif defined(CCLUA_OS_WIN32)
    int pos = 0;
    int len = buflen;
    char tempBuf[MAX_LOG_LENGTH + 1] = { 0 };
    WCHAR wszBuf[MAX_LOG_LENGTH + 1] = { 0 };
    do
    {
        std::copy(buf + pos, buf + pos + MAX_LOG_LENGTH, tempBuf);
        tempBuf[MAX_LOG_LENGTH] = 0;
        MultiByteToWideChar(CP_UTF8, 0, tempBuf, -1, wszBuf, sizeof(wszBuf));
        OutputDebugStringW(wszBuf);
        WideCharToMultiByte(CP_ACP, 0, wszBuf, -1, tempBuf, sizeof(tempBuf), nullptr, FALSE);
        printf("%s", tempBuf);
        pos += MAX_LOG_LENGTH;
    } while (pos < len);
    SendLogToWindow(buf);
    fflush(stdout);
#else
    // Linux, Mac, iOS, etc
    fprintf(stdout, "%s", buf);
    fflush(stdout);
#endif

    if (buf != s_buf) {
        free(buf);
    }
}

void runtime::showLog()
{
    Size frameSize = window::getFrameSize();
    window::setDesignSize(Size(750 * frameSize.width / frameSize.height, 750), ResolutionPolicy::NO_BORDER);
    
    Rect rect = window::getVisibleBounds();
    Size size = window::getVisibleSize();
    Scene *scene = Scene::create();
    scene->setIgnoreAnchorPointForPosition(true);
    
    ui::Layout *view = ui::Layout::create();
    view->setIgnoreAnchorPointForPosition(true);
    view->setBackGroundColor(Color3B::BLACK);
    view->setBackGroundColorType(ui::Layout::BackGroundColorType::SOLID);
    view->setContentSize(size);
    view->setPosition(rect.origin);
    
    cocos2d::Data log = filesystem::read(runtime::getLogPath());
    ui::Text *label = ui::Text::create();
    label->setFontSize(25);
    label->setString((const char *)log.getBytes());
    label->setTextColor(Color4B::WHITE);
    label->setIgnoreAnchorPointForPosition(true);
    label->setTouchEnabled(false);
    
    ui::ScrollView *scroll = ui::ScrollView::create();
    scroll->setIgnoreAnchorPointForPosition(true);
    scroll->addChild(label);
    scroll->setContentSize(size);
    scroll->setInnerContainerSize(label->getContentSize());
    view->addChild(scroll);
    
    ui::Button *btn = ui::Button::create();
    btn->setContentSize(Size(120, 80));
    btn->setTitleText("Restart");
    btn->getTitleLabel()->setSystemFontSize(40);
    btn->setIgnoreAnchorPointForPosition(true);
    btn->setPosition(Vec2(size.width - 150, 0));
    btn->addClickEventListener([](Ref *target) {
        runtime::restart();
    });
    view->addChild(btn);
    view->setAnchorPoint(Vec2(0.5f, 0.5f));
    view->setScale(0.9f, 0.9f);
    runtime::getRunningScene()->addChild(view);
}

//
// msaa antialias
//

void runtime::setSampleCount(unsigned int samples)
{
    _sampleCount = samples > 0 ? samples : 1;
}

unsigned int runtime::getSampleCount()
{
    return _sampleCount;
}

//
// feature
//
bool runtime::hasFeature(const std::string &api) {
    auto itor = _supportedFeatures.find(api);
    if (itor == _supportedFeatures.end()) {
        itor = _supportedFeatures.find(api + "." + runtime::getOS());
    }
    return itor != _supportedFeatures.end() && itor->second;
}

void runtime::printFeatures()
{
    for (auto &it : _supportedFeatures) {
        runtime::log("supported feature: %s = %s", it.first.c_str(), it.second ? "true" : "false");
    }
}

void runtime::registerFeature(const std::string &api, bool enabled)
{
    _supportedFeatures[api] = enabled;
}

//
// error
//
void runtime::initBugly(const char* appid)
{
#ifdef CCLUA_BUILD_BUGLY
    runtime::log("init bugly: appid=%s", appid);
    bugly::init(appid);
#endif //CCLUA_BUILD_BUGLY

#ifdef COCOS2D_DEBUG
    runtime::disableReport();
#endif
}

void runtime::disableReport()
{
    _reportError = false;
}

void runtime::reportError(const char *err, const char *traceback)
{
#if CCLUA_BUILD_BUGLY
    if (_reportError) {
        std::string errmsg;
        errmsg.append(err).append(traceback);
        if (_tracebackCaches.find(errmsg) == _tracebackCaches.end()) {
            _tracebackCaches[errmsg] = true;
            bugly::reportException(err, traceback);
        }
    }
#endif
}

int runtime::pushdirector(lua_State *L)
{
    olua_push_cppobj<cocos2d::Director>(L, cocos2d::Director::getInstance());
    return lua_gettop(L);
}

#if COCOS2D_VERSION >= 0x00040000
cocos2d::backend::ProgramCache *runtime::getProgramCache()
{
    return backend::ProgramCache::getInstance();
}
#else
cocos2d::GLProgramCache *runtime::getProgramCache()
{
    return GLProgramCache::getInstance();
}
#endif

cocos2d::FileUtils *runtime::getFileUtils()
{
    return FileFinder::getInstance();
}

cocos2d::SpriteFrameCache *runtime::getSpriteFrameCache()
{
    return SpriteFrameCache::getInstance();
}

cocos2d::TextureCache *runtime::getTextureCache()
{
    return Director::getInstance()->getTextureCache();
}

cocos2d::Scheduler *runtime::getScheduler()
{
    return Director::getInstance()->getScheduler();
}

cocos2d::ActionManager *runtime::getActionManager()
{
    return Director::getInstance()->getActionManager();
}

cocos2d::EventDispatcher *runtime::getEventDispatcher()
{
    return Director::getInstance()->getEventDispatcher();
}

bool runtime::isDisplayStats()
{
    return Director::getInstance()->isDisplayStats();
}

void runtime::setDisplayStats(bool displayStats)
{
    Director::getInstance()->setDisplayStats(displayStats);
}

cocos2d::Scene *runtime::getRunningScene()
{
    return Director::getInstance()->getRunningScene();
}

void runtime::pushScene(cocos2d::Scene *scene)
{
    Director::getInstance()->pushScene(scene);
}

void runtime::replaceScene(cocos2d::Scene *scene)
{
    Director::getInstance()->replaceScene(scene);
}

void runtime::popScene()
{
    Director::getInstance()->popScene();
}

void runtime::popToRootScene()
{
    Director::getInstance()->popToRootScene();
}

void runtime::purgeCachedData()
{
    Director::getInstance()->purgeCachedData();
}

void runtime::exit()
{
    Director::getInstance()->end();
}

//
// RuntimeContext
//
RuntimeContext::RuntimeContext()
:_scheduler(nullptr)
{
}

RuntimeContext::~RuntimeContext()
{
}

void RuntimeContext::initGLView(const std::string &title)
{
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    cocos2d::Rect rect(0, 0, 1134, 750);
    rect.size.width = preferences::getFloat(CONF_WINDOW_WIDTH, rect.size.width);
    rect.size.height = preferences::getFloat(CONF_WINDOW_HEIGHT, rect.size.height);
    if(!glview) {
#if defined(CCLUA_OS_WIN32) || defined(CCLUA_OS_MAC) || defined(CCLUA_OS_LINUX)
        glview = GLViewImpl::createWithRect(title, rect);
#else
        glview = GLViewImpl::create(title);
#endif
        director->setOpenGLView(glview);
    }
    glview->setDesignResolutionSize(rect.size.width, rect.size.height, ResolutionPolicy::NO_BORDER);
}

void RuntimeContext::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8, 0};
    
    glContextAttrs.multisamplingCount = (int)runtime::getSampleCount();
    
    GLView::setGLContextAttrs(glContextAttrs);
}

bool RuntimeContext::applicationDidFinishLaunching()
{
    _scheduler = Director::getInstance()->getScheduler();
    CC_SAFE_RETAIN(_scheduler);
    downloader::init();
    runtime::init();
    runtime::launch("bootstrap.lua");
    return true;
}

void RuntimeContext::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();
    runtime::dispatch("runtimePause");
}

void RuntimeContext::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();
    runtime::dispatch("runtimeResume");
}

void RuntimeContext::applicationWillTerminate()
{
    auto director = Director::getInstance();
    director->retain();
    
#if !defined(CCLUA_OS_MAC) && !defined(CCLUA_OS_WIN32)
    director->popToRootScene();
    director->mainLoop();
    if (director->getRunningScene()) {
        director->getRunningScene()->removeAllChildren();
    }
#endif
    
    _scheduler->unscheduleAll();
    lua_close(_luaVM);
    _luaVM = nullptr;
    
    downloader::end();
    AudioEngine::uncacheAll();
    AudioEngine::end();

    PoolManager::destroyInstance();
    CC_SAFE_RELEASE(_scheduler);
    
    director->release();
#if !defined(CCLUA_OS_MAC) && !defined(CCLUA_OS_WIN32)
    director->end();
    director->mainLoop();
#endif
}
