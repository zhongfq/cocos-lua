#include "xgame/runtime.h"
#include "xgame/runtime-private.h"
#include "xgame/filesystem.h"
#include "xgame/FileFinder.h"
#include "xgame/downloader.h"
#include "xgame/preferences.h"
#include "xgame/RootScene.h"
#include "xgame/timer.h"
#include "lua-bindings/lua_bindings.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "bugly/CrashReport.h"
#endif

#include "audio/include/AudioEngine.h"

#include <time.h>
#include <stdarg.h>
#include <thread>
#include <deque>

USING_NS_CC;

NS_XGAME_BEGIN
static bool _restarting = false;
static lua_State *_luaVM = nullptr;
static std::vector<lua_CFunction> _luaLibs;
static runtime::EventDispatcher _dispatcher = nullptr;
static std::vector<std::pair<std::string, std::string>> _suspendedEvents;
static std::string _openURI;
static std::map<std::string, bool> _supportedFeatures;
static std::unordered_map<std::string, bool> _tracebackCaches;
static int _sampleCount = 1;

static char _logBuf[MAX_LOG_LENGTH];
static float _time = 0;
static std::string _timestamp;
static FILE *_logFile = NULL;
static std::mutex _logMutex;
static std::string _logPath;
static std::string _logCache;
static std::string _workdir;

#ifdef CCLUA_BUILD_BUGLY
static std::deque<std::string> _logBugly;
#endif

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
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
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
    
    Texture2D::setDefaultAlphaPixelFormat(backend::PixelFormat::AUTO);
    AudioEngine::lazyInit();
    
    // cocos event
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    dispatcher->addCustomEventListener(Director::EVENT_AFTER_UPDATE, [](EventCustom *e) {
        runtime::dispatchEvent("runtimeUpdate", "");
    });
    dispatcher->addCustomEventListener(Director::EVENT_PROJECTION_CHANGED, [](EventCustom *e) {
        runtime::dispatchEvent("runtimeResize", "");
    });
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
            olua_dofunc(_luaVM, func);
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
    return "1.13.4";
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
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    return "ios";
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    return "android";
#elif CC_TARGET_PLATFORM == CC_PLATFORM_MAC
    return "mac";
#elif CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
    return "win32";
#elif CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
    return "linux";
#else
    return "unknown";
#endif
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

RenderTexture *runtime::capture(Node *node, backend::PixelFormat format, backend::PixelFormat depthStencilFormat)
{
    auto director = Director::getInstance();
    auto size = node->getContentSize();
    auto image = RenderTexture::create(size.width, size.height, format, depthStencilFormat);
    image->getSprite()->setIgnoreAnchorPointForPosition(true);
    image->retain();
    node->retain();
    
    EventListenerCustom *listener = new EventListenerCustom();
    listener->init(Director::EVENT_BEFORE_DRAW, [=](EventCustom *) {
        director->getEventDispatcher()->removeEventListener(listener);
        director->setNextDeltaTimeZero(true);

        bool savedVisible = node->isVisible();
        Point savedPos = node->getPosition();
        Point anchor;
        if (!node->isIgnoreAnchorPointForPosition()) {
            anchor = node->getAnchorPoint();
        }
        node->setVisible(true);
        node->setPosition(Point(size.width * anchor.x, size.height * anchor.y));
        image->begin();
        node->visit();
        image->end();
        node->setPosition(savedPos);
        node->setVisible(savedVisible);
        
        listener->release();
        image->release();
        node->release();
    });
    
    director->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);
    
    return image;
}

void runtime::setAudioSessionCatalog(const std::string &catalog)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    __runtime_setAudioSessionCatalog(catalog);
#endif
}

const std::string runtime::getAudioSessionCatalog()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    return __runtime_getAudioSessionCatalog();
#else
    return "";
#endif
}

const PermissionStatus runtime::getPermissionStatus(Permission permission)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    return __runtime_getPermissionStatus(permission);
#else
    return PermissionStatus::NOT_DETERMINED;
#endif
}

void runtime::requestPermission(Permission permission, const std::function<void (PermissionStatus)> callback)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    __runtime_requestPermission(permission, callback);
#else
    callback(PermissionStatus::DENIED);
#endif
}

void runtime::alert(const std::string &title, const std::string &message, const std::string &ok, const std::string &no, const std::function<void (bool)> callback)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    __runtime_alert(title, message, ok, no, callback);
#else
    callback(false);
#endif
}

std::string runtime::getIDFA()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    return __runtime_getIDFA();
#else
    return "";
#endif
}

bool runtime::isAdvertisingTrackingEnabled()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    return __runtime_isAdvertisingTrackingEnabled();
#else
    return false;
#endif
}

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
    if (Director::getInstance()->getCocos2dThreadId() == std::this_thread::get_id()) {
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
    if (!xgame::runtime::isRestarting()) {
        auto listener = new EventListenerCustom();
        listener->autorelease();
        listener->init(Director::EVENT_BEFORE_UPDATE, [func, args, once, listener](EventCustom *event){
            lua_State *L = olua_mainthread(NULL);
            int top = lua_gettop(L);
            olua_geterrorfunc(L);
            olua_getref(L, func);
            if (!lua_isnil(L, -1)) {
                lua_pushstring(L, args.c_str());
                lua_pcall(L, 1, 0, top + 1);
            } else {
                xgame::runtime::log("attempt to call nil: %d %s", func, args.c_str());
            }
            if (once) {
                olua_unref(L, func);
            }
            lua_settop(L, top);
            Director::getInstance()->getEventDispatcher()->removeEventListener(listener);
        });
        Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);
    }
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
    if (_logFile) {
        if (_logCache.size() > 0) {
            fwrite(_logCache.c_str(), sizeof(char), (size_t)_logCache.size(), _logFile);
            _logCache.clear();
        }
        fwrite(error, sizeof(char), strlen(error), _logFile);
        fwrite("\n", 1, 1, _logFile);
        fflush(_logFile);
    } else {
        _logCache.append(error);
        _logCache.append("\n");
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
    
#ifdef CCLUA_BUILD_BUGLY
    if (_logBugly.size() >= 200) {
        _logBugly.pop_front();
    }
    _logBugly.push_back(_logBuf);
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
    CrashReport::initCrashReport(appid, false, CrashReport::CRLogLevel::Verbose);
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
        for (auto &msg : _logBugly) {
            CrashReport::log(CrashReport::CRLogLevel::Verbose, "bugly", msg.c_str());
        }
        _logBugly.clear();
        std::string errmsg;
        errmsg.append(err).append(traceback);
        if (_tracebackCaches.find(errmsg) == _tracebackCaches.end()) {
            _tracebackCaches[errmsg] = true;
            CrashReport::reportException(CATEGORY_LUA_EXCEPTION, "", err, traceback);
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
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
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
    
#if CC_TARGET_PLATFORM != CC_PLATFORM_MAC
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
#if CC_TARGET_PLATFORM != CC_PLATFORM_MAC
    director->end();
    director->mainLoop();
#endif
}

NS_XGAME_END
