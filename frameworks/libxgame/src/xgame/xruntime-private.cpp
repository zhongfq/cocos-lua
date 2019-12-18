#include "xgame/xruntime.h"
#include "xgame/xruntime-private.h"
#include "cocos2d.h"

USING_NS_CC;

NS_XGAME_BEGIN

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
const std::string __runtime_getPackageName()
{
    static std::string value;
    if (value.size() == 0) {
        value = JniHelper::callStaticStringMethod(JAVA_APPCONTEXT_CLASS, "getPackage");
    }
    return value;
}

const std::string __runtime_getAppVersion()
{
    static std::string value;
    if (value.size() == 0) {
        value = JniHelper::callStaticStringMethod(JAVA_APPCONTEXT_CLASS, "getVersion");
    }
    return value;
}

const std::string __runtime_getAppBuild()
{
    static std::string value;
    if (value.size() == 0) {
        value = JniHelper::callStaticStringMethod(JAVA_APPCONTEXT_CLASS, "getVersionCode");
    }
    return value;
}

const std::string __runtime_getChannel()
{
    static std::string value;
    if (value.size() == 0) {
        value = JniHelper::callStaticStringMethod(JAVA_APPCONTEXT_CLASS, "getChannel");
    }
    return value;
}

const std::string __runtime_getDeviceInfo()
{
    static std::string value;
    if (value.size() == 0) {
        value = JniHelper::callStaticStringMethod(JAVA_APPCONTEXT_CLASS, "getDeviceInfo");
    }
    return value;
}

void __runtime_openURL(const std::string uri, const std::function<void (bool)> callback)
{
    bool ret = JniHelper::callStaticBooleanMethod(JAVA_APPCONTEXT_CLASS, "openURL", uri);
    if (callback != nullptr) {
        callback(ret);
    }
}

bool __runtime_canOpenURL(const std::string uri)
{
    return JniHelper::callStaticBooleanMethod(JAVA_APPCONTEXT_CLASS, "canOpenURL", uri);
}

const std::string __runtime_getLanguage()
{
    static std::string value;
    if (value.size() == 0) {
        value = JniHelper::callStaticStringMethod(JAVA_APPCONTEXT_CLASS, "getLanguage");
    }
    return value;
}

const std::string __runtime_getNetworkStatus()
{
    return JniHelper::callStaticStringMethod(JAVA_APPCONTEXT_CLASS, "getNetworkStatus");
}

void __runtime_pullAllFeatures()
{
    JniHelper::callStaticVoidMethod(JAVA_APPCONTEXT_CLASS, "pullAllFeatures");
}
#elif CC_TARGET_PLATFORM == CC_PLATFORM_WIN32

static std::string _packageName;

const std::string __runtime_getPackageName()
{
	return _packageName;
}

void __runtime_setPackageName(const std::string &packageName)
{
	_packageName = packageName;
}


const std::string __runtime_getAppVersion()
{
	return "1.0.0";
}

const std::string __runtime_getAppBuild()
{
	return "100";
}

const std::string __runtime_getChannel()
{
	return "win";
}

const std::string __runtime_getDeviceInfo()
{
	return "win32";
}

const std::string __runtime_getLanguage()
{
	return "zh-CN";
}

const std::string __runtime_getNetworkStatus()
{
    return "WIFI";
}

void __runtime_openURL(const std::string uri, const std::function<void(bool)> callback)
{
    if (callback != nullptr) {
        callback(false);
    }
}

bool __runtime_canOpenURL(const std::string uri)
{
	return false;
}

#endif

NS_XGAME_END
