#include "janalytics.h"

#if defined(CCLUA_BUILD_JANALYTICS) && defined(CCLUA_OS_ANDROID)

USING_NS_CCLUA;
USING_NS_CCLUA_PLUGIN;

const char *janalytics::JAVA_CLASS = "cclua/plugin/janalytics/JAnalytics";

void janalytics::init(const std::string &appKey, const std::string &channel)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "init", appKey, channel);
}

void janalytics::startTrackPage(const std::string &pageName)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "startTrackPage", pageName);
}

void janalytics::stopTrackPage(const std::string &pageName)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "stopTrackPage", pageName);
}

void janalytics::trackEvent(EventType type, const cocos2d::ValueMap &value)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "trackEvent", (int)type, toJSONString(value));
}

void janalytics::identifyAccount(const cocos2d::ValueMap &value)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "identifyAccount", toJSONString(value));
}

void janalytics::detachAccount()
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "detachAccount");
}

void janalytics::setFrequency(int frequency)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setFrequency", frequency);
}

void janalytics::setDebug(bool enable)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setDebug", enable);
}
#endif // CCLUA_BUILD_JANALYTICS
