#ifndef __CCLUA_RUNTIME_H__
#define __CCLUA_RUNTIME_H__

#include "lua.hpp"
#include "cocos2d.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#define CCLUA_OS_ANDROID
#define CCLUA_OS_NAME "android"
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#define CCLUA_OS_IOS
#define CCLUA_OS_NAME "ios"
#elif CC_TARGET_PLATFORM == CC_PLATFORM_MAC
#define CCLUA_OS_MAC
#define CCLUA_OS_NAME "mac"
#elif CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#define CCLUA_OS_WIN32
#define CCLUA_OS_NAME "win32"
#elif CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
#define CCLUA_OS_LINUX
#define CCLUA_OS_NAME "linux"
#else
#define CCLUA_OS_NAME "unknown"
#endif

#define NS_CCLUA_BEGIN  namespace cclua {
#define NS_CCLUA_END    }
#define USING_NS_CCLUA using namespace cclua

#define NS_CCLUA_PLUGIN_BEGIN  namespace cclua { namespace plugin {
#define NS_CCLUA_PLUGIN_END    }}
#define USING_NS_CCLUA_PLUGIN using namespace cclua::plugin

#define strequal(str1, str2)           (strcmp(str1, str2) == 0)
#define strnequal(str1, str2, len)     (strncmp(str1, str2, len) == 0)

#ifdef _WIN32
#define strcaseequal(str1, str2) (_stricmp(str1, str2) == 0)
#define strncaseequal(str1, str2, len) (_strnicmp(str1, str2) == 0)
#else
#define strcaseequal(str1, str2)       (strcasecmp(str1, str2) == 0)
#define strncaseequal(str1, str2, len) (strncasecmp(str1, str2) == 0)
#endif

#define BOOL_STR(b) ((b) ? "OK" : "NO")

#define CONF_APP_VERSION        "conf.version.app"
#define CONF_APP_BUILD          "conf.version.build"
#define CONF_MANIFEST_VERSION   "conf.version.manifest"
#define CONF_WINDOW_WIDTH       "conf.window.width"
#define CONF_WINDOW_HEIGHT      "conf.window.height"

#define JAVA_APPCONTEXT_CLASS   "cclua/AppContext"

inline bool strstartwith(const char *src, const char *prefix)
{
    const char *pos = strstr(src, prefix);
    return pos == src;
}

inline bool strendwith(const char *src, const char *suffix)
{
    const char *pos = strstr(src, suffix);
    return !pos ? false : (src + strlen(src) == pos + strlen(suffix));
}

NS_CCLUA_BEGIN

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
    IDFA,
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
    static bool isCocosThread();
    static float getTime();
    static void gc();
    static lua_State *luaVM();
    static void luaOpen(lua_CFunction libfunc);
    
    // app info
    static const std::string getVersion();
    static const uint64_t getCocosVersion();
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
    
    static const std::string getPaste();
    static void setPaste(const std::string &text);
    
#if COCOS2D_VERSION >= 0x00040000
    static cocos2d::RenderTexture *capture(cocos2d::Node *node, float width, float height, cocos2d::backend::PixelFormat format = cocos2d::backend::PixelFormat::RGBA8888, cocos2d::backend::PixelFormat depthStencilFormat = cocos2d::backend::PixelFormat::D24S8);
#else
    static cocos2d::RenderTexture *capture(cocos2d::Node *node, float width, float height, cocos2d::Texture2D::PixelFormat format = cocos2d::Texture2D::PixelFormat::RGBA8888, GLuint depthStencilFormat = 0x88f0);
#endif
    
    // ios only
    static const PermissionStatus getPermissionStatus(Permission permission);
    static void requestPermission(Permission permission, const std::function<void (PermissionStatus)> callback);
    static void setAudioSessionCatalog(const std::string &catalog);
    static const std::string getAudioSessionCatalog();
    static void alert(const std::string &title, const std::string &message, const std::string &ok, const std::string &no, const std::function<void (bool)> callback);
    
#ifdef CCLUA_OS_IOS
    static void openAppSetting(const std::string &title, const std::string &message, const std::function<void()> &callback);
#endif
    
    // event dispatch
    typedef std::function<void (const std::string &event, const std::string &args)> EventDispatcher;
    static void setDispatcher(const EventDispatcher &dispatcher);
    static void dispatchEvent(const std::string &event, const std::string &args);
    static void runOnCocosThread(const std::function<void ()> &callback);
    static void openURL(const std::string &uri, const std::function<void (bool)> callback = nullptr);
    static void handleOpenURL(const std::string &uri);
    static bool canOpenURL(const std::string &uri);
    
    // for java and objc bridge
    typedef std::function<void(const std::string &args)> RefCallback;
    static void callref(int func, const std::string &args, bool once);
    static int ref(const RefCallback callback);
    
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
    
private:
    static void once(const std::string &event, const std::function<void()> callback);
    static void on(const std::string &event, const std::function<void()> callback);
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

NS_CCLUA_END

#endif
