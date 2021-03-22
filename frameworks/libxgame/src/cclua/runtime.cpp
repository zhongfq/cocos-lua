#include "cclua/runtime.h"
#include "cclua/runtime-private.h"
#include "cclua/filesystem.h"
#include "cclua/FileFinder.h"
#include "cclua/downloader.h"
#include "cclua/preferences.h"
#include "cclua/RootScene.h"
#include "cclua/timer.h"
#include "cclua/xlua.h"
#include "lua-bindings/lua_bindings.h"

#if defined(CCLUA_OS_ANDROID) || defined(CCLUA_OS_IOS)
#include "bugly/CrashReport.h"
#endif

#include "audio/include/AudioEngine.h"

#include <time.h>
#include <stdarg.h>
#include <thread>
#include <deque>

USING_NS_CC;

NS_CCLUA_BEGIN
static bool _restarting = false;
static lua_State *_luaVM = nullptr;
static std::vector<lua_CFunction> _luaLibs;
static runtime::EventDispatcher _dispatcher = nullptr;
static std::vector<std::pair<std::string, std::string>> _suspendedEvents;
static std::string _openURI;
static std::unordered_map<std::string, bool> _supportedFeatures;
static std::unordered_map<std::string, bool> _tracebackCaches;
static int _sampleCount = 1;
static std::unordered_map<int, runtime::RefCallback> _refCallbacks;
static int _refCount = -1;

static char _logBuf[MAX_LOG_LENGTH];
static float _time = 0;
static std::string _timestamp;
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
        if (strequal(argv[i], "-workdir") && i < argc - 1) {
            _workdir = argv[++i];
        }
    }
}

void runtime::init()
{
    FileFinder::setDelegate(FileFinder::create());
    filesystem::addSearchPath(filesystem::getDocumentDirectory() + "/assets", true);
    filesystem::addSearchPath(_workdir, true);
    filesystem::remove(filesystem::getBuiltinCacheDirectory());
    Director::getInstance()->setAnimationInterval(1.0f / 60);
    Director::getInstance()->setDisplayStats(runtime::isDebug());
    
#ifdef CCLUA_OS_ANDROID
    __runtime_pullAllFeatures();
    runtime::setLogPath(filesystem::getDirectory("external.cache") + "/console.log");
    runtime::getPackageName();
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
    filesystem::createDirectory(filesystem::getBuiltinCacheDirectory());
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
    
    timer::schedule(1, [](float dt){ updateTimestamp(); });
    timer::schedule(0, [](float dt){ _time += dt; });
    
#if COCOS2D_VERSION >= 0x00040000
    Texture2D::setDefaultAlphaPixelFormat(backend::PixelFormat::AUTO);
#else
    Texture2D::setDefaultAlphaPixelFormat(Texture2D::PixelFormat::AUTO);
#endif
    AudioEngine::lazyInit();
    
    // cocos event
    runtime::on(Director::EVENT_BEFORE_UPDATE, []() {
        runtime::dispatchEvent("runtimeUpdate", "");
    });
    runtime::on(Director::EVENT_PROJECTION_CHANGED, []() {
        runtime::dispatchEvent("runtimeResize", "");
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
    runtime::dispatchEvent("runtimeGC", "");
    lua_gc(L, LUA_GCCOLLECT, 0);
    runtime::log("lua mem: %.3fM", lua_gc(L, LUA_GCCOUNT, 0) / 1024.0f);
}

void runtime::clearStorage()
{
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
        runtime::runOnCocosThread([scriptPath]() {
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
        _luaVM = xlua_new();
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

//
// app info
//
const std::string runtime::getVersion()
{
    return "2.2.0";
}

const uint64_t runtime::getCocosVersion()
{
    return COCOS2D_VERSION;
}

const std::string runtime::getPackageName()
{
    return __runtime_getPackageName();
}

const std::string runtime::getAppVersion()
{
    return __runtime_getAppVersion();
}

const std::string runtime::getAppBuild()
{
    return __runtime_getAppBuild();
}

const std::string runtime::getChannel()
{
    return __runtime_getChannel();
}

const std::string runtime::getOS()
{
    return CCLUA_OS_NAME;
}

const std::string runtime::getDeviceInfo()
{
    return __runtime_getDeviceInfo();
}

const std::string runtime::getLanguage()
{
    return __runtime_getLanguage();
}

const std::string runtime::getManifestVersion()
{
    return preferences::getString(CONF_MANIFEST_VERSION, "0.0.0");
}

void runtime::setManifestVersion(const std::string &version)
{
    preferences::setString(CONF_MANIFEST_VERSION, version.c_str());
}

const std::string runtime::getNetworkStatus()
{
    return __runtime_getNetworkStatus();
}

#if COCOS2D_VERSION >= 0x00040000
RenderTexture *runtime::capture(Node *node, float width, float height, backend::PixelFormat format, backend::PixelFormat depthStencilFormat)
{
    auto director = Director::getInstance();
    auto image = RenderTexture::create((int)width, (int)height, format, depthStencilFormat);
    image->getSprite()->setIgnoreAnchorPointForPosition(true);
    image->retain();
    node->retain();
    
    runtime::once(Director::EVENT_BEFORE_DRAW, [=]() {
        bool savedVisible = node->isVisible();
        Point savedPos = node->getPosition();
        Point anchor;
        if (!node->isIgnoreAnchorPointForPosition()) {
            anchor = node->getAnchorPoint();
        }
        node->setVisible(true);
        node->setPosition(Point(width * anchor.x, height * anchor.y));
        image->begin();
        node->visit();
        image->end();
        node->setPosition(savedPos);
        node->setVisible(savedVisible);
    
        runtime::once(Director::EVENT_AFTER_DRAW, [=]() {
            image->release();
            node->release();
        });
    });
    
    return image;
}
#else
RenderTexture *runtime::capture(Node *node, float width, float height, Texture2D::PixelFormat format, GLuint depthStencilFormat)
{
    auto director = Director::getInstance();
    auto image = RenderTexture::create((int)width, (int)height, format, depthStencilFormat);
    image->getSprite()->setIgnoreAnchorPointForPosition(true);
    director->setNextDeltaTimeZero(true);

    bool savedVisible = node->isVisible();
    Point savedPos = node->getPosition();
    Point anchor;
    if (!node->isIgnoreAnchorPointForPosition()) {
        anchor = node->getAnchorPoint();
    }
    node->setVisible(true);
    node->setPosition(Point(width * anchor.x, height * anchor.y));
    image->begin();
    node->visit();
    image->end();
    node->setPosition(savedPos);
    node->setVisible(savedVisible);
    director->getRenderer()->render();
    return image;
}
#endif

void runtime::setAudioSessionCatalog(const std::string &catalog)
{
#ifdef CCLUA_OS_IOS
    __runtime_setAudioSessionCatalog(catalog);
#endif
}

const std::string runtime::getAudioSessionCatalog()
{
#ifdef CCLUA_OS_IOS
    return __runtime_getAudioSessionCatalog();
#else
    return "";
#endif
}

const PermissionStatus runtime::getPermissionStatus(Permission permission)
{
#ifdef CCLUA_OS_IOS
    return __runtime_getPermissionStatus(permission);
#else
    return PermissionStatus::NOT_DETERMINED;
#endif
}

void runtime::requestPermission(Permission permission, const std::function<void (PermissionStatus)> callback)
{
#ifdef CCLUA_OS_IOS
    __runtime_requestPermission(permission, callback);
#else
    callback(PermissionStatus::DENIED);
#endif
}

void runtime::alert(const std::string &title, const std::string &message, const std::string &ok, const std::string &no, const std::function<void (bool)> callback)
{
#ifdef CCLUA_OS_IOS
    __runtime_alert(title, message, ok, no, callback);
#else
    callback(false);
#endif
}

#ifdef CCLUA_OS_IOS
void runtime::openAppSetting(const std::string &title, const std::string &message, const std::function<void()> &callback)
{
    __runtime_openAppSetting(title, message, callback);
}
#endif

//
// event dispatch
//
void runtime::setDispatcher(const EventDispatcher &dispatcher)
{
    _dispatcher = dispatcher;
    if (_dispatcher) {
        auto events = _suspendedEvents;
        _suspendedEvents.clear();
        for (auto &it : events) {
            runtime::dispatchEvent(it.first, it.second);
        }
    }
}

void runtime::dispatchEvent(const std::string &event, const std::string &args)
{
    if (runtime::isCocosThread()) {
        if (_dispatcher) {
            _dispatcher(event, args);
        } else {
            _suspendedEvents.push_back(std::make_pair(event, args));
        }
    } else {
        runtime::runOnCocosThread([event, args]() {
            runtime::dispatchEvent(event, args);
        });
    }
}

void runtime::runOnCocosThread(const std::function<void ()> &callback)
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
    runtime::dispatchEvent("openURL", uri);
}

bool runtime::canOpenURL(const std::string &uri)
{
    return __runtime_canOpenURL(uri);
}

void runtime::callref(int func, const std::string &args, bool once)
{
    if (!cclua::runtime::isRestarting()) {
        runtime::runOnCocosThread([func, args, once]() {
            if (func < 0) {
                RefCallback callback = _refCallbacks[func];
                if (callback) {
                    callback(args);
                    if (once) {
                        _refCallbacks.erase(func);
                    }
                }
            } else {
                lua_State *L = olua_mainthread(NULL);
                int top = lua_gettop(L);
                olua_pusherrorfunc(L);
                olua_getref(L, func);
                if (!lua_isnil(L, -1)) {
                    lua_pushstring(L, args.c_str());
                    lua_pcall(L, 1, 0, top + 1);
                } else {
                    cclua::runtime::log("attempt to call nil: %d %s", func, args.c_str());
                }
                if (once) {
                    olua_unref(L, func);
                }
                lua_settop(L, top);
            }
        });
    }
}

int runtime::ref(const RefCallback callback)
{
    _refCount--;
    _refCallbacks[_refCount] = std::move(callback);
    return _refCount;
}

void runtime::once(const std::string &event, const std::function<void()> callback)
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

void runtime::on(const std::string &event, const std::function<void()> callback)
{
    auto director = Director::getInstance();
    director->getEventDispatcher()->addCustomEventListener(event, [=](EventCustom *) {
        callback();
    });
}

//
// log
//
const std::string &runtime::getTimestamp()
{
    return _timestamp;
}

void runtime::updateTimestamp()
{
    char buf[64];
    time_t t = time(NULL);
    struct tm *stm = localtime(&t);
    sprintf(buf, "%02d:%02d:%02d", stm->tm_hour, stm->tm_min, stm->tm_sec);
    _timestamp.assign(buf);
}

void runtime::setLogPath(const std::string &path)
{
    if (_logFile) {
        fclose(_logFile);
        _logFile = nullptr;
    }
    
    _logPath = path;
    _logFile = fopen(path.c_str(), "w");
    
    runtime::log("[%s] set log path: %s", BOOL_STR(_logFile), filesystem::shortPath(path).c_str());
}

const std::string runtime::getLogPath()
{
    return _logPath;
}

void _writeLogToFile(const char *error)
{
    static std::string cache;
    if (_logFile) {
        if (cache.size() > 0) {
            fwrite(cache.c_str(), sizeof(char), (size_t)cache.size(), _logFile);
            cache.clear();
        }
        fwrite(error, sizeof(char), strlen(error), _logFile);
        fwrite("\n", 1, 1, _logFile);
        fflush(_logFile);
    } else {
        cache.append(error);
        cache.append("\n");
    }
}

void runtime::log(const char *fmt, ...)
{
    std::lock_guard<std::mutex> lock(_logMutex);
    
    va_list args;
    va_start(args, fmt);
    
    if (_timestamp.size() == 0) {
        updateTimestamp();
    }
    
    int maxLen = MAX_LOG_LENGTH - 4;
    int len = sprintf(_logBuf, "[%s] ", _timestamp.c_str());
    // cocos2d::log has a bug when log length > MAX_LOG_LEGNTH - 3
    maxLen -= len;
    len = vsnprintf(_logBuf + len, maxLen, fmt, args);
    if (len >= maxLen) {
        _logBuf[maxLen] = '\0';
    }
    _writeLogToFile(_logBuf);
    
    va_end(args);
    
#if defined(CCLUA_OS_ANDROID) || defined(CCLUA_OS_IOS)
    if (_reportError) {
        if (runtime::isCocosThread()) {
            CrashReport::log(CrashReport::Verbose, _logBuf);
        } else {
            std::string msg = _logBuf;
            runtime::runOnCocosThread([msg]() {
                CrashReport::log(CrashReport::Verbose, msg.c_str());
            });
        }
    }
#endif

#ifdef COCOS2D_DEBUG
    cocos2d::log("%s", _logBuf);
#endif
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
bool runtime::support(const std::string &api) {
    auto itor = _supportedFeatures.find(api);
    if (itor == _supportedFeatures.end()) {
        itor = _supportedFeatures.find(api + "." + runtime::getOS());
    }
    return itor != _supportedFeatures.end() && itor->second;
}

void runtime::printSupport()
{
    for (auto &it : _supportedFeatures) {
        runtime::log("api support: %s = %s", it.first.c_str(), it.second ? "true" : "false");
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
    CrashReport::init(appid);
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
            CrashReport::reportException(err, traceback);
        }
    }
#endif
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
    
    glContextAttrs.multisamplingCount = runtime::getSampleCount();
    
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
    runtime::dispatchEvent("runtimePause", "");
}

void RuntimeContext::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();
    runtime::dispatchEvent("runtimeResume", "");
}

void RuntimeContext::applicationWillTerminate()
{
    auto director = Director::getInstance();
    director->retain();
    
#ifndef CCLUA_OS_MAC
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
#ifndef CCLUA_OS_MAC
    director->end();
    director->mainLoop();
#endif
}

NS_CCLUA_END
