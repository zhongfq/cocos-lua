#ifndef __XRUNTIME_H__
#define __XRUNTIME_H__

#include "xgame/xdef.h"

#include "cocos2d.h"

NS_XGAME_BEGIN

class runtime
{
public:
    static void init();
    static bool launch(const std::string &scriptPath);
    
    // app info
    static const std::string getPackageName();
    static const std::string getVersion();
    static const std::string getVersionCode();
    static const std::string getChannel();
    static const std::string getOS();
    static const std::string getDeviceInfo();
    
    // event dispatch
    typedef std::function<void (const std::string &event, const std::string &args)> EventDispatcher;
    static void setDispatcher(const EventDispatcher &dispatcher);
    static void dispatchEvent(const std::string &event, const std::string &args);
    static void runOnCocosThread(const std::function<void ()> &callback);
    
    // log
    static void updateLogTimestamp();
    static void setLogPath(const std::string &path);
    static const std::string getLogPath();
    static void log(const char *format, ...);
    
    // msaa antialias for vector graphics
    static void setAntialias(bool enabled, unsigned int numSamples);
    static bool isAntialias();
    static unsigned int getNumSamples();
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
