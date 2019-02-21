#ifndef __XRUNTIME_H__
#define __XRUNTIME_H__

#include "xgame/xdef.h"
#include "xgame/xlua.h"

#include "cocos2d.h"

NS_XGAME_BEGIN

class runtime
{
public:
    // lua vm & init
    static void init();
    static void clearStorage();
    static bool launch(const std::string &scriptPath);
    static bool restart();
    static bool isRestarting();
    static lua_State *luaVM();
    static void luaOpen(lua_CFunction libfunc);
    
    // app info
    static const std::string getPackageName();
    static const std::string getVersion();
    static const std::string getVersionBuild();
    static const std::string getChannel();
    static const std::string getOS();
    static const std::string getDeviceInfo();
    static const std::string getNativeStackTrace();
    
    // event dispatch
    typedef std::function<void (const std::string &event, const std::string &args)> EventDispatcher;
    static void setDispatcher(const EventDispatcher &dispatcher);
    static void dispatchEvent(const std::string &event, const std::string &args);
    static void runOnCocosThread(const std::function<void ()> &callback);
    static void openURL(const std::string &uri, const std::function<void (bool)> callback);
    static void handleOpenURL(const std::string &uri);
    static bool canOpenURL(const std::string &uri);
    
    // log
    static void updateLogTimestamp();
    static void setLogPath(const std::string &path);
    static const std::string getLogPath();
    static void log(const char *format, ...);
    
    // msaa antialias for vector graphics
    static void setAntialias(bool enabled, unsigned int numSamples);
    static bool isAntialias();
    static unsigned int getNumSamples();
    
    // feature
    static bool support(const std::string &api);
    static void registerFeature(const std::string &api, bool enabled);
    static void printSupport();
    
    // error
    typedef std::function<void (const char *err, const char *traceback)> ErrorReporter;
    typedef std::function<void (const char *msg)> LogReporter;
    static void disableReport();
    static void setErrorReporter(const ErrorReporter &callback);
    static void reportError(const char *err, const char *traceback);
    static void setLogReporter(const LogReporter &callback);
    static void reportLog(const char *msg);
};

class RuntimeContext : public cocos2d::Application
{
public:
    RuntimeContext();
    virtual ~RuntimeContext();
    
    virtual void initGLContextAttrs();
    virtual bool applicationDidFinishLaunching();
    virtual void applicationDidEnterBackground();
    virtual void applicationWillEnterForeground();
    virtual void applicationWillTerminate();
private:
    cocos2d::Scheduler *_scheduler;
};

NS_XGAME_END

#endif
