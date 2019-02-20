#include "xgame/xruntime.h"
#include "xgame/xfilesystem.h"
#include "xgame/xpreferences.h"
#include "xgame/xtimer.h"

#include "audio/include/AudioEngine.h"

#include <time.h>
#include <stdarg.h>

USING_NS_CC;
USING_NS_CC_EXP;

NS_XGAME_BEGIN

static runtime::EventDispatcher _dispatcher = nullptr;
static std::vector<std::pair<std::string, std::string>> _suspendedEvents;
static std::string _openURL;

static char _logBuf[MAX_LOG_LENGTH];
static char _logTimestamp[64];
static FILE *_logFile = NULL;
static std::mutex _logMutex;
static std::string _logPath;
static std::string _logCache;

void runtime::init()
{
    timer::schedule(0, [](float dt){ updateLogTimestamp(); });
}

bool runtime::launch(const std::string &scriptPath)
{
    return true;
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
        for (auto itor = events.begin(); itor != events.end(); ++itor) {
            runtime::dispatchEvent(itor->first, itor->second);
        }
    }
}

void runtime::dispatchEvent(const std::string &event, const std::string &args)
{
    if (event == "openURL") {
        _openURL = args;
    }
    
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
    if (_logPath == path && _logFile) {
        return;
    }
    
    if (_logFile) {
        fclose(_logFile);
    }
    
    _logPath = path;
    _logFile = fopen(path.c_str(), "w");
    
    runtime::log("[%s] set logger path: %s", _logFile ? "OK" : "NO", filesystem::shortPath(path).c_str());
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
    runtime::init();
    runtime::launch("bootstrap.lua");
    return true;
}

void RuntimeContext::applicationDidEnterBackground()
{
    runtime::log("application did enter background");
    Director::getInstance()->stopAnimation();
    runtime::dispatchEvent("runtimePause", "");
}

void RuntimeContext::applicationWillEnterForeground()
{
    runtime::log("application will enter foreground");
    Director::getInstance()->startAnimation();
    runtime::dispatchEvent("runtimeResume", "");
}

void RuntimeContext::applicationWillTerminate()
{
    AudioEngine::uncacheAll();
    AudioEngine::end();
    Director::getInstance()->end();
    Director::getInstance()->mainLoop();
    PoolManager::destroyInstance();
    CC_SAFE_RELEASE(_scheduler);
}

NS_XGAME_END
