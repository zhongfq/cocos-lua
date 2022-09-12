#ifndef __CCLUA_RUNTIME_H__
#define __CCLUA_RUNTIME_H__

#include "olua-2dx.h"
#include "cocos2d.h"

#ifndef CCLUA_VERSION
#define CCLUA_VERSION "1.0.0"
#endif

#ifndef APP_NAME
#define APP_NAME "cclua"
#endif

#ifndef APP_PACKAGE_NAME
#define APP_PACKAGE_NAME "com.codetypes.hellolua"
#endif


#if COCOS2D_VERSION >= 0x00040000
#include "renderer/backend/ProgramCache.h"
#endif

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
    return pos != nullptr && (src + strlen(src) == pos + strlen(suffix));
}

NS_CCLUA_BEGIN

typedef std::function<void(const std::string &event, const cocos2d::Value &data)> Callback;

class runtime
{
public:
    // parse launch args(for lua debug)
    static void parseLaunchArgs(int argc, char *argv[]) OLUA_EXCLUDE;
    
    // lua vm & init
    static void init() OLUA_EXCLUDE;
    static void clearStorage();
    static bool launch(const std::string &scriptPath);
    static bool restart();
    static bool isRestarting();
    static bool isDebug();
    static bool isCocosThread() OLUA_EXCLUDE;
    static float getTime();
    static void gc();
    static void testCrash();
    static lua_State *luaVM() OLUA_EXCLUDE;
    static void luaOpen(lua_CFunction libfunc) OLUA_EXCLUDE;
    
    // app info
    static std::string getVersion();
    static uint64_t getCocosVersion();
    static std::string getPackageName();
    static std::string getAppName();
    static std::string getAppVersion();
    static std::string getAppBuild();
    static std::string getChannel();
    static std::string getOS();
    static std::string getDeviceInfo();
    static std::string getLanguage();
    static std::string getManifestVersion();
    static void setManifestVersion(const std::string &version);
    static std::string getNetworkStatus();
    
    // environment value
    static std::string getEnv(const std::string &key);
    static void setEnv(const std::string &key, const std::string &value, bool save = false);
    
    static std::string getPaste();
    static void setPaste(const std::string &text);
    
#if COCOS2D_VERSION >= 0x00040000
    static cocos2d::Sprite *capture(cocos2d::Node *node, float width, float height, float scale = 1, cocos2d::backend::PixelFormat format = cocos2d::backend::PixelFormat::RGBA8888, cocos2d::backend::PixelFormat depthStencilFormat = cocos2d::backend::PixelFormat::D24S8);
#else
    static cocos2d::Sprite *capture(cocos2d::Node *node, float width, float height, float scale = 1, cocos2d::Texture2D::PixelFormat format = cocos2d::Texture2D::PixelFormat::RGBA8888, GLuint depthStencilFormat = 0x88f0);
#endif
    
    static uint32_t getMaxFrameRate();
    static uint32_t getFrameRate();
    static void setFrameRate(uint32_t frameRate);
    
    static std::string getPermission(const std::string &permission);
    static void requestPermission(const std::string &permission, const std::function<void (const std::string &)> &callback);
    static void alert(const std::string &title, const std::string &message, const std::string &ok, const std::string &no, const std::function<void (bool)> &callback);
    
    // ios only
    static void setAudioSessionCatalog(const std::string &catalog);
    static std::string getAudioSessionCatalog();
    
    // event dispatch
    static void setDispatcher(const Callback &dispatcher);
    static void dispatch(const std::string &event, const cocos2d::Value &args) OLUA_EXCLUDE;
    static void dispatch(const std::string &event, const std::string &args = "") OLUA_EXCLUDE;
    static void runLater(const std::function<void ()> &callback) OLUA_EXCLUDE;
    static void openURL(const std::string &uri, const std::function<void (bool)> callback = nullptr);
    static void handleOpenURL(const std::string &uri) OLUA_EXCLUDE;
    static bool canOpenURL(const std::string &uri);
    
    // for java and objc bridge
    static void installAPK(const std::string &path);
    static void callref(olua_Ref func, const std::string &status, const std::string &data, bool once) OLUA_EXCLUDE;
    static olua_Ref ref(const Callback &callback) OLUA_EXCLUDE;
    static void unref(olua_Ref func) OLUA_EXCLUDE;
    
    // log
    static void setLogPath(const std::string &path);
    static std::string getLogPath();
    static void log(const char *format, ...) OLUA_EXCLUDE;
    static void showLog();
    
    // msaa antialias for vector graphics
    static void setSampleCount(unsigned int samples);
    static unsigned int getSampleCount();
    
    // feature
    static bool hasFeature(const std::string &api);
    static void registerFeature(const std::string &api, bool enabled) OLUA_EXCLUDE;
    static void printFeatures();
    static olua_Return load(lua_State *L, const std::string &name);
    static olua_Return load(lua_State *L, const std::string &name, const std::string &feature);
    
    // error
    static void initBugly(const char* appid) OLUA_EXCLUDE;
    static void disableReport();
    static void reportError(const char *err, const char *traceback) OLUA_EXCLUDE;
    
    // Director api
    static int pushdirector(lua_State *L) OLUA_EXCLUDE;
#if COCOS2D_VERSION >= 0x00040000
    static OLUA_ADDREF(^ ::pushdirector) cocos2d::backend::ProgramCache *getProgramCache();
#else
    static OLUA_ADDREF(^ ::pushdirector) cocos2d::GLProgramCache *getProgramCache();
#endif
    static OLUA_ADDREF(^ ::pushdirector) cocos2d::FileUtils *getFileUtils();
    static OLUA_ADDREF(^ ::pushdirector) cocos2d::SpriteFrameCache *getSpriteFrameCache();
    static OLUA_ADDREF(^ ::pushdirector) cocos2d::TextureCache *getTextureCache();
    static OLUA_ADDREF(^ ::pushdirector) cocos2d::Scheduler *getScheduler();
    static OLUA_ADDREF(^ ::pushdirector) cocos2d::ActionManager *getActionManager();
    static OLUA_ADDREF(^ ::pushdirector) cocos2d::EventDispatcher *getEventDispatcher();
    static bool isDisplayStats();
    static void setDisplayStats(bool displayStats);
    static OLUA_ADDREF(scenes | ::pushdirector) cocos2d::Scene *getRunningScene();
    static void pushScene(OLUA_ADDREF(scenes | ::pushdirector) cocos2d::Scene *scene);
    static OLUA_DEFREF(scenes ~ ::pushdirector) void replaceScene(OLUA_ADDREF(scenes | ::pushdirector) cocos2d::Scene *scene);
    static OLUA_DEFREF(scenes ~ ::pushdirector) void popScene();
    static OLUA_DEFREF(scenes ~ ::pushdirector) void popToRootScene();
    static void purgeCachedData();
    static void exit();
private:
    static void once(const std::string &event, const std::function<void()> &callback);
    static void on(const std::string &event, const std::function<void()> &callback);
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
