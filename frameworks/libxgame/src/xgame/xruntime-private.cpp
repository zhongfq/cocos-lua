#include "xgame/xruntime.h"
#include "xgame/xruntime-private.h"
#include "cocos2d.h"

USING_NS_CC;
USING_NS_XGAME;

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
const std::string __runtime_getPackageName()
{
    static std::string value;
    if (value.size() == 0) {
        value = JniHelper::callStaticStringMethod(JAVA_APPCONTEXT_CLASS, "getPackage");
    }
    return value;
}

const std::string __runtime_getVersion()
{
    static std::string value;
    if (value.size() == 0) {
        value = JniHelper::callStaticStringMethod(JAVA_APPCONTEXT_CLASS, "getVersion");
    }
    return value;
}

const std::string __runtime_getBuild()
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
    callback(ret);
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


const std::string __runtime_getVersion()
{
	return "1.0.0";
}

const std::string __runtime_getBuild()
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

void __runtime_openURL(const std::string uri, const std::function<void(bool)> callback)
{
	callback(false);
}

bool __runtime_canOpenURL(const std::string uri)
{
	return false;
}
#endif
