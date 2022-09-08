#include "cclua/runtime.h"
#include "cclua/runtime-private.h"
#include "cclua/plugin.h"
#include "cocos2d.h"

USING_NS_CC;

NS_CCLUA_BEGIN

#ifdef CCLUA_OS_ANDROID
std::string __runtime_getPackageName()
{
    static std::string value;
    if (value.empty()) {
        value = Jni::callStaticStringMethod(JAVA_APPCONTEXT_CLASS, "getAppInfo", "packageName");
    }
    return value;
}

std::string __runtime_getAppName()
{
    static std::string value;
    if (value.empty()) {
        value = Jni::callStaticStringMethod(JAVA_APPCONTEXT_CLASS, "getAppInfo", "appName");
    }
    return value;
}

std::string __runtime_getAppVersion()
{
    static std::string value;
    if (value.empty()) {
        value = Jni::callStaticStringMethod(JAVA_APPCONTEXT_CLASS, "getAppInfo", "appVersion");
    }
    return value;
}

std::string __runtime_getAppBuild()
{
    static std::string value;
    if (value.empty()) {
        value = Jni::callStaticStringMethod(JAVA_APPCONTEXT_CLASS, "getAppInfo", "appBuild");
    }
    return value;
}

std::string __runtime_getChannel()
{
    static std::string value;
    if (value.empty()) {
        value = Jni::callStaticStringMethod(JAVA_APPCONTEXT_CLASS, "getAppInfo", "channel");
    }
    return value;
}

std::string __runtime_getLanguage()
{
    static std::string value;
    if (value.empty()) {
        value = Jni::callStaticStringMethod(JAVA_APPCONTEXT_CLASS, "getAppInfo", "language");
    }
    return value;
}

std::string __runtime_getDeviceInfo()
{
    static std::string value;
    if (value.empty()) {
        value = Jni::callStaticStringMethod(JAVA_APPCONTEXT_CLASS, "getAppInfo", "deviceInfo");
    }
    return value;
}

void __runtime_openURL(const std::string &uri, const std::function<void (bool)> &callback)
{
    bool ret = Jni::callStaticBooleanMethod(JAVA_APPCONTEXT_CLASS, "openURL", uri);
    if (callback != nullptr) {
        callback(ret);
    }
}

bool __runtime_canOpenURL(const std::string &uri)
{
    return Jni::callStaticBooleanMethod(JAVA_APPCONTEXT_CLASS, "canOpenURL", uri);
}

void __runtime_alert(const std::string &title, const std::string &message, const std::string &ok,
                     const std::string &no, const std::function<void (bool)> &callback)
{
    olua_ref_t func = runtime::ref([=] (const std::string &status, const cocos2d::Value &data) {
        callback(status == "true");
    });
    Jni::callStaticVoidMethod(JAVA_APPCONTEXT_CLASS, "alert", title, message, ok, no, func);
}

uint32_t __runtime_getMaxFrameRate()
{
    return Jni::callStaticIntMethod(JAVA_APPCONTEXT_CLASS, "getMaxFrameRate");
}

std::string __runtime_getNetworkStatus()
{
    return Jni::callStaticStringMethod(JAVA_APPCONTEXT_CLASS, "getNetworkStatus");
}

std::string __runtime_getPermission(const std::string &permission)
{
    return Jni::callStaticStringMethod(JAVA_APPCONTEXT_CLASS, "getPermission", permission);
}

void __runtime_requestPermission(const std::string &permission, const std::function<void (const std::string &)> &callback)
{
    olua_ref_t func = runtime::ref([=] (const std::string &status, const cocos2d::Value &data) {
        callback(status);
    });
    Jni::callStaticVoidMethod(JAVA_APPCONTEXT_CLASS, "requestPermission", permission, func);
}

void __runtime_installAPK(const std::string &path)
{
    Jni::callStaticVoidMethod(JAVA_APPCONTEXT_CLASS, "installAPK", path);
}

void __runtime_pullAllFeatures()
{
    Jni::callStaticVoidMethod(JAVA_APPCONTEXT_CLASS, "pullAllFeatures");
}

std::string __runtime_getPaste()
{
    return Jni::callStaticStringMethod(JAVA_APPCONTEXT_CLASS, "getPaste");
}

void __runtime_setPaste(const std::string &text)
{
    Jni::callStaticVoidMethod(JAVA_APPCONTEXT_CLASS, "setPaste", text);
}
#elif defined(CCLUA_OS_WIN32)

static std::string _packageName;
static std::string _appName;

std::string __runtime_getPackageName()
{
	return _packageName;
}

void __runtime_setPackageName(const std::string &packageName)
{
	_packageName = packageName;
}

std::string __runtime_getAppName()
{
    return _appName;
}

void __runtime_setAppName(const std::string &appName)
{
    _appName = appName;
}

std::string __runtime_getAppVersion()
{
	return "1.0.0";
}

std::string __runtime_getAppBuild()
{
	return "100";
}

std::string __runtime_getChannel()
{
	return "win";
}

std::string __runtime_getDeviceInfo()
{
	return "win32";
}

std::string __runtime_getLanguage()
{
	return "zh-CN";
}

std::string __runtime_getNetworkStatus()
{
    return "WIFI";
}

void __runtime_openURL(const std::string &uri, const std::function<void(bool)> &callback)
{
    if (callback != nullptr) {
        callback(false);
    }
}

bool __runtime_canOpenURL(const std::string &uri)
{
	return false;
}

uint32_t __runtime_getMaxFrameRate()
{
    return 60;
}

std::string __runtime_getPaste()
{
    return "";
}

void __runtime_setPaste(const std::string &text)
{
    runtime::log("unsupport set paste");
}

#endif

NS_CCLUA_END
