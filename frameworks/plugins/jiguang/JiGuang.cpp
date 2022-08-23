#include "jiguang.h"

#if defined(CCLUA_BUILD_JPUSH) && defined(CCLUA_OS_ANDROID)

USING_NS_CCLUA;
USING_NS_CCLUA_PLUGIN;

const char *jpush::JAVA_CLASS = "cclua/plugin/jiguang/JPush";

void jpush::init(const std::string &appKey, const std::string &channel)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "init", appKey, channel);
}

void jpush::setAlias(const std::string &alias)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setAlias", alias);
}

void jpush::deleteAlias()
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "deleteAlias");
}

void jpush::addTags(const std::set<std::string> &tags)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "addTags", toJSONString(tags));
}

void jpush::setTags(const std::set<std::string> &tags)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setTags", toJSONString(tags));
}

void jpush::deleteTags(const std::set<std::string> &tags)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "deleteTags", toJSONString(tags));
}

void jpush::cleanTags()
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "cleanTags");
}

void jpush::setDebug(bool enabled)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setDebugMode", enabled);
}

void jpush::setLogOFF()
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setLogOFF");
}

void jpush::setBadge(int value)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setBadge", value);
}

bool jpush::isEnabled()
{
    return Jni::callStaticBooleanMethod(JAVA_CLASS, "isEnabled");
}

void jpush::requestPermission()
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "requestPermission");
}

std::string jpush::getRegistrationID()
{
    return Jni::callStaticStringMethod(JAVA_CLASS, "getRegistrationID");
}

#endif // CCLUA_BUILD_JPUSH

#if defined(CCLUA_BUILD_JAUTH) && defined(CCLUA_OS_ANDROID)

USING_NS_CCLUA;
USING_NS_CCLUA_PLUGIN;

const char *jauth::JAVA_CLASS = "cclua/plugin/jiguang/JAuth";
Callback jauth::_dispatcher;

void jauth::init(const std::string &appKey, const std::string &channel)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "init", appKey, channel);
}

bool jauth::isInitSuccess()
{
    return Jni::callStaticBooleanMethod(JAVA_CLASS, "isInitSuccess");
}

void jauth::setDebug(bool enabled)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setDebug", enabled);
}

bool jauth::checkVerifyEnable()
{
    return Jni::callStaticBooleanMethod(JAVA_CLASS, "checkVerifyEnable");
}

void jauth::getToken(int timeout)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "getToken", timeout);
}

void jauth::preLogin(int timeout)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "preLogin", timeout);
}

void jauth::clearPreLoginCache()
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "clearPreLoginCache");
}

void jauth::loginAuth(int timeout)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "loginAuth", timeout);
}

void jauth::dismissLoginAuth(bool needCloseAnim)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "dismissLoginAuth", needCloseAnim);
}

void jauth::getSmsCode(const std::string &phonenum, const std::string &signid, const std::string &tempid)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "getSmsCode", phonenum, signid, tempid);
}

void jauth::setSmsIntervalTime(int64_t intervalTime)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setSmsIntervalTime", intervalTime);
}

void jauth::configUI(cocos2d::ValueMap &value, bool landscape)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "configUI", toJSONString(value), landscape);
}
#endif // CCLUA_BUILD_JAUTH

#if defined(CCLUA_BUILD_JANALYTICS) && defined(CCLUA_OS_ANDROID)

USING_NS_CCLUA;
USING_NS_CCLUA_PLUGIN;

const char *janalytics::JAVA_CLASS = "cclua/plugin/jiguang/JAnalytics";

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

void janalytics::trackEvent(EventType type, cocos2d::ValueMap &value)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "trackEvent", (int)type, toJSONString(value));
}

void janalytics::identifyAccount(cocos2d::ValueMap &value)
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
