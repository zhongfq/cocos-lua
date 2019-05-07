#include "xgame/xruntime.h"
#include "xgame/xruntime-private.h"
#include "cocos2d.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

USING_NS_CC;

#define JAVA_RUNTIME_CLASS "kernel/Runtime"

const std::string __runtime_getPackageName()
{
    static std::string value;

    if (value.size() == 0) {
        value = JniHelper::callStaticStringMethod(JAVA_RUNTIME_CLASS, "getPackageName");
    }

    return value;
}

const std::string __runtime_getVersion()
{
    static std::string value;

    if (value.size() == 0) {
        value = JniHelper::callStaticStringMethod(JAVA_RUNTIME_CLASS, "getVersion");
    }

    return value;
}

const std::string __runtime_getVersionBuild()
{
    static std::string value;

    if (value.size() == 0) {
        value = JniHelper::callStaticStringMethod(JAVA_RUNTIME_CLASS, "getVersionCode");
    }

    return value;
}

const std::string __runtime_getChannel()
{
    static std::string value;

    if (value.size() == 0) {
        value = JniHelper::callStaticStringMethod(JAVA_RUNTIME_CLASS, "getChannel");
    }

    return value;
}

const std::string __runtime_getDeviceInfo()
{
    static std::string value;

    if (value.size() == 0) {
        value = JniHelper::callStaticStringMethod(JAVA_RUNTIME_CLASS, "getDeviceInfo");
    }

    return value;
}

const std::string __runtime_getNativeStackTrace()
{
    static std::string value;

    if (value.size() == 0) {
        value = JniHelper::callStaticStringMethod(JAVA_RUNTIME_CLASS, "getStackTrace");
    }

    return value;
}

void __runtime_openURL(const std::string &uri, const std::function<void (bool)> callback)
{
    bool ret = JniHelper::callStaticBooleanMethod(JAVA_RUNTIME_CLASS, "openURL", uri);
    callback(ret);
}

bool __runtime_canOpenURL(const std::string &uri)
{
    return JniHelper::callStaticBooleanMethod(JAVA_RUNTIME_CLASS, "canOpenURL", uri);
}

const std::string __runtime_getLanguage()
{
    // TODO:
    return "zh-CN";
}

void __runtime_pullAllFeatures()
{
    JniHelper::callStaticVoidMethod(JAVA_RUNTIME_CLASS, "pullAllFeatures");
}

#endif