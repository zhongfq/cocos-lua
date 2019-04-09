#include "xgame/xruntime.h"
#include "xgame/xruntime-private.h"
#include "xgame/xfilesystem.h"
#include "xgame/xfilefinder.h"
#include "xgame/xdownloader.h"
#include "xgame/xpreferences.h"
#include "xgame/xrootscene.h"
#include "xgame/xtimer.h"
#include "xgame/lua_module.h"

#include "audio/include/AudioEngine.h"

#include <time.h>
#include <stdarg.h>

USING_NS_CC;
USING_NS_CC_EXP;

NS_XGAME_BEGIN
static bool _restarting = false;
static lua_State *_luaVM = nullptr;
static std::vector<lua_CFunction> _luaLibs;
static runtime::EventDispatcher _dispatcher = nullptr;
static std::vector<std::pair<std::string, std::string>> _suspendedEvents;
static std::string _openURI;
static std::map<std::string, bool> _supportedFeatures;

static char _logBuf[MAX_LOG_LENGTH];
static char _logTimestamp[64];
static FILE *_logFile = NULL;
static std::mutex _logMutex;
static std::string _logPath;
static std::string _logCache;

static runtime::ErrorReporter _errorReporter = nullptr;
static runtime::LogReporter _logReporter = nullptr;

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
static std::string StringWideCharToUtf8(const std::wstring &strWideChar)
{
    std::string ret;
    if (!strWideChar.empty()) {
        int nNum = WideCharToMultiByte(CP_UTF8, 0, strWideChar.c_str(), -1, nullptr, 0, nullptr, FALSE);
        if (nNum) {
            char* utf8String = new char[nNum + 1];
            utf8String[0] = 0;
            
            nNum = WideCharToMultiByte(CP_UTF8, 0, strWideChar.c_str(), -1, utf8String, nNum + 1, nullptr, FALSE);
            
            ret = utf8String;
            delete[] utf8String;
        } else {
            CCLOG("Wrong convert to Utf8 code:0x%x", GetLastError());
        }
    }
    
    return ret;
}

static inline std::string convertPathFormatToUnixStyle(const std::string &path)
{
    std::string ret = path;
    int len = ret.length();
    for (int i = 0; i < len; ++i) {
        if (ret[i] == '\\') {
            ret[i] = '/';
        }
    }
    return ret;
}
#endif // CC_TARGET_PLATFORM == CC_PLATFORM_WIN32

void runtime::init()
{
    FileFinder::setDelegate(new FileFinder());
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_MAC
    std::string path = FileUtils::getInstance()->getWritablePath();
    path = path.substr(0, path.size() - 1);
    path = path.substr(0, path.find_last_of('/'));
    FileUtils::getInstance()->setWritablePath(path + "/Library/Containers/" + runtime::getPackageName() + "/");
#elif CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#define CC_MAX_PATH  512
    WCHAR app_path[CC_MAX_PATH + 1] = { 0 };
    ::GetModuleFileName(nullptr, app_path, CC_MAX_PATH + 1);
    std::string path = convertPathFormatToUnixStyle(StringWideCharToUtf8(app_path));
    path = path.substr(0, path.find_last_of('/') + 1);
    FileUtils::getInstance()->setWritablePath(path);
    FileUtils::getInstance()->addSearchPath(path + "../../assets");
#endif
    
    FileUtils::getInstance()->addSearchPath(filesystem::getDocumentDirectory() + "/assets", true);
    Director::getInstance()->setAnimationInterval(1.0f / 60);
#ifdef COCOS2D_DEBUG
    Director::getInstance()->setDisplayStats(true);
#else
    Director::getInstance()->setDisplayStats(false);
#endif
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    runtime::setLogPath(filesystem::getDirectory("external.cache") + "/console.log");
    runtime::getPackageName();
    runtime::getDeviceInfo();
    filesystem::getDocumentDirectory();
    filesystem::getCacheDirectory();
    filesystem::getTmpDirectory();
    filesystem::getSDCardDirectory();
#else
    runtime::setLogPath(filesystem::getCacheDirectory() + "/console.log");
#endif
    
    // 创建所需路径
    filesystem::createDirectory(filesystem::getCacheDirectory());
    filesystem::createDirectory(filesystem::getTmpDirectory());
    filesystem::createDirectory(filesystem::getDocumentDirectory() + "/assets");
    
    // 版本清理
    std::string versionRuntime = preferences::getString(CONF_VERSION_RUNTIME);
    std::string versionBuild = preferences::getString(CONF_VERSION_BUILD);
    if (versionBuild != runtime::getVersionBuild() ||
        versionRuntime != runtime::getVersion()) {
        runtime::clearStorage();
        runtime::log("app update to version: %s(%s)", runtime::getVersion().c_str(), runtime::getVersionBuild().c_str());
    }
    preferences::setString(CONF_VERSION_RUNTIME, runtime::getVersion().c_str());
    preferences::setString(CONF_VERSION_BUILD, runtime::getVersionBuild().c_str());
    preferences::flush();
    
    timer::schedule(1, [](float dt){ updateLogTimestamp(); });
    
    Texture2D::setDefaultAlphaPixelFormat(Texture2D::PixelFormat::AUTO);
    AudioEngine::lazyInit();
}

void runtime::clearStorage()
{
    filesystem::remove(filesystem::getDocumentDirectory() + "/assets");
    filesystem::createDirectory(filesystem::getDocumentDirectory() + "/assets");
    runtime::log("app clean version: %s(%s)", runtime::getVersion().c_str(), runtime::getVersionBuild().c_str());
    
    preferences::deleteKey(CONF_VERSION_RUNTIME);
    preferences::deleteKey(CONF_VERSION_BUILD);
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
        luaopen_module(_luaVM);
        for (auto func : _luaLibs) {
            xlua_call(_luaVM, func);
        }
        olua_push_cppobj<cocos2d::Director>(_luaVM, cocos2d::Director::getInstance(), "cc.Director");
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
const std::string runtime::getPackageName()
{
    return __runtime_getPackageName();
}

const std::string runtime::getVersion()
{
    return __runtime_getVersion();
}

const std::string runtime::getVersionBuild()
{
    return __runtime_getVersionBuild();
}

const std::string runtime::getChannel()
{
    return __runtime_getChannel();
}

const std::string runtime::getOS()
{
    static const char *const os[] = {"unknown", "ios", "android", "win32",
        "marmalade", "linux", "bada", "blackberry", "mac", "nacl",
        "emscripten", "tizen", "qt5", "winrt"};
    return os[CC_TARGET_PLATFORM];
}

const std::string runtime::getDeviceInfo()
{
    return __runtime_getDeviceInfo();
}

const std::string runtime::getNativeStackTrace()
{
    return __runtime_getNativeStackTrace();
}

const std::string runtime::getLanguage()
{
    return __runtime_getLanguage();
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
    runtime::runOnCocosThread([event, args]() {
        if (_dispatcher) {
            _dispatcher(event, args);
        } else {
            _suspendedEvents.push_back(std::make_pair(event, args));
        }
    });
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

//
// log
//
void runtime::updateLogTimestamp()
{
    // TODO: 获取本地时间
    time_t t = time(NULL);
    int sec = t % (3600 * 24);
    int h = sec / 3600 + 8;
    int m = sec % 3600 / 60;
    int s = sec % 60;
    sprintf(_logTimestamp, "%02d:%02d:%02d", h, m, s);
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
    } else if (_logCache.size() < MAX_LOG_LENGTH) {
        _logCache.append(error);
        _logCache.append("\n");
    }
}

void runtime::log(const char *fmt, ...)
{
    std::lock_guard<std::mutex> lock(_logMutex);
    
    va_list args;
    va_start(args, fmt);
    
    if (strlen(_logTimestamp) == 0) {
        updateLogTimestamp();
    }
    
    int maxLen = MAX_LOG_LENGTH - 4;
    int len = sprintf(_logBuf, "[%s] ", _logTimestamp);
    // cocos2d::log has a bug when log length > MAX_LOG_LEGNTH - 3
    maxLen -= len;
    len = vsnprintf(_logBuf + len, maxLen, fmt, args);
    if (len >= maxLen) {
        _logBuf[maxLen] = '\0';
    }
    _writeLogToFile(_logBuf);
    
    va_end(args);

#ifdef COCOS2D_DEBUG
    cocos2d::log("%s", _logBuf);
#endif
    
    runtime::reportLog(_logBuf);
}

//
// msaa antialias
//
void runtime::setAntialias(bool enabled, unsigned int numSamples)
{
    preferences::setBoolean(CONF_ANTIALIAS_ENABLED, enabled);
    preferences::setInteger(CONF_ANTIALIAS_SAMPLES, numSamples);
}

bool runtime::isAntialias()
{
    return preferences::getBoolean(CONF_ANTIALIAS_ENABLED, false);
}

unsigned int runtime::getNumSamples()
{
    return (unsigned int)preferences::getInteger(CONF_ANTIALIAS_SAMPLES, 4);
}

//
// feature
//
bool runtime::support(const std::string &api)
{
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
void runtime::disableReport()
{
    _errorReporter = nullptr;
    _logReporter = nullptr;
}

void runtime::setErrorReporter(const ErrorReporter &callback)
{
    _errorReporter = callback;
}

void runtime::reportError(const char *err, const char *traceback)
{
    if (_errorReporter) {
        _errorReporter(err, traceback);
    }
}

void runtime::setLogReporter(const LogReporter &callback)
{
    _logReporter = callback;
}

void runtime::reportLog(const char *msg)
{
    if (_logReporter) {
        _logReporter(msg);
    }
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

void RuntimeContext::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8, 0};
    
    if (runtime::isAntialias()) {
        glContextAttrs.multisamplingCount = runtime::getNumSamples();
    }
    
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
    lua_close(_luaVM);
    _luaVM = nullptr;
    
    downloader::end();
    AudioEngine::uncacheAll();
    AudioEngine::end();
    Director::getInstance()->end();
    Director::getInstance()->mainLoop();
    PoolManager::destroyInstance();
    CC_SAFE_RELEASE(_scheduler);
}

NS_XGAME_END
