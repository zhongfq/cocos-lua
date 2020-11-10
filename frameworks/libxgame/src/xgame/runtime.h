#ifndef __XGAME_RUNTIME_H__
#define __XGAME_RUNTIME_H__

#include "xgame/config.h"
#include "xgame/xlua.h"

#include "cocos2d.h"

NS_XGAME_BEGIN

enum class PermissionStatus {
    NOT_DETERMINED,
    RESTRICTED,
    DENIED,
    AUTHORIZED
};

enum class Permission {
    AUDIO,
    CAMERA,
    PHOTO,
};

class runtime
{
public:
    // parse launch args(for lua debug)
    static void parseLaunchArgs(int argc, char *argv[]);
    
    // lua vm & init
    static void init();
    static void clearStorage();
    static bool launch(const std::string &scriptPath);
    static bool restart();
    static bool isRestarting();
    static bool isDebug();
    static float getTime();
    static void gc();
    static lua_State *luaVM();
    static void luaOpen(lua_CFunction libfunc);
    
    // app info
    static const std::string getVersion();
    static const std::string getPackageName();
    static const std::string getAppVersion();
    static const std::string getAppBuild();
    static const std::string getChannel();
    static const std::string getOS();
    static const std::string getDeviceInfo();
    static const std::string getLanguage();
    static const std::string getManifestVersion();
    static void setManifestVersion(const std::string &version);
    static const std::string getNetworkStatus();
    
    static cocos2d::RenderTexture *capture(cocos2d::Node *node, float width, float height, cocos2d::backend::PixelFormat format = cocos2d::backend::PixelFormat::RGBA8888, cocos2d::backend::PixelFormat depthStencilFormat = cocos2d::backend::PixelFormat::D24S8);
    
    // ios only
    static const PermissionStatus getPermissionStatus(Permission permission);
    static void requestPermission(Permission permission, const std::function<void (PermissionStatus)> callback);
    static void setAudioSessionCatalog(const std::string &catalog);
    static const std::string getAudioSessionCatalog();
    static void alert(const std::string &title, const std::string &message, const std::string &ok, const std::string &no, const std::function<void (bool)> callback);
    static std::string getIDFA();
    static bool isAdvertisingTrackingEnabled();
    
    // event dispatch
    typedef std::function<void (const std::string &event, const std::string &args)> EventDispatcher;
    static void setDispatcher(const EventDispatcher &dispatcher);
    static void dispatchEvent(const std::string &event, const std::string &args);
    static void runOnCocosThread(const std::function<void ()> &callback);
    static void openURL(const std::string &uri, const std::function<void (bool)> callback = nullptr);
    static void handleOpenURL(const std::string &uri);
    static bool canOpenURL(const std::string &uri);
    
    // for java and objc bridge
    static void callref(int func, const std::string &args, bool once);
    
    // log
    static const std::string &getTimestamp();
    static void updateTimestamp();
    static void setLogPath(const std::string &path);
    static const std::string getLogPath();
    static void log(const char *format, ...);
    
    // msaa antialias for vector graphics
    static void setSampleCount(unsigned int samples);
    static unsigned int getSampleCount();
    
    // feature
    static bool support(const std::string &api);
    static void registerFeature(const std::string &api, bool enabled);
    static void printSupport();
    
    // error
    static void initBugly(const char* appid);
    static void disableReport();
    static void reportError(const char *err, const char *traceback);
};

class RuntimeContext : public cocos2d::Application
{
public:
    RuntimeContext();
    virtual ~RuntimeContext();
    
    virtual void initGLView(const std::string &title);
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
