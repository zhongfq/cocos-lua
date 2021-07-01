#include "JiGuang.h"

#ifdef CCLUA_OS_ANDROID
#include "cclua/jniutil.h"

NS_CCLUA_PLUGIN_BEGIN

#define JAVA_JPUSH_CLASS        "cclua/plugin/jiguang/JPush"
#define JAVA_JAUTH_CLASS        "cclua/plugin/jiguang/JAuth"
#define JAVA_JANALYTICS_CLASS   "cclua/plugin/jiguang/JAnalytics"

USING_NS_CC;

#ifdef CCLUA_BUILD_JPUSH

void JPush::init(const std::string &appKey, const std::string &channel)
{
    Jni::callStaticVoidMethod(JAVA_JPUSH_CLASS, "init", appKey, channel);
}

void JPush::setAlias(const std::string &alias)
{
    Jni::callStaticVoidMethod(JAVA_JPUSH_CLASS, "setAlias", alias);
}

void JPush::deleteAlias()
{
    Jni::callStaticVoidMethod(JAVA_JPUSH_CLASS, "deleteAlias");
}

void JPush::addTags(const std::set<std::string> &tags)
{
    Jni::callStaticVoidMethod(JAVA_JPUSH_CLASS, "addTags", toJSONString(tags));
}

void JPush::setTags(const std::set<std::string> &tags)
{
    Jni::callStaticVoidMethod(JAVA_JPUSH_CLASS, "setTags", toJSONString(tags));
}

void JPush::deleteTags(const std::set<std::string> &tags)
{
    Jni::callStaticVoidMethod(JAVA_JPUSH_CLASS, "deleteTags", toJSONString(tags));
}

void JPush::cleanTags()
{
    Jni::callStaticVoidMethod(JAVA_JPUSH_CLASS, "cleanTags");
}

void JPush::setDebug(bool enabled)
{
    Jni::callStaticVoidMethod(JAVA_JPUSH_CLASS, "setDebugMode", enabled);
}

void JPush::setLogOFF()
{
    Jni::callStaticVoidMethod(JAVA_JPUSH_CLASS, "setLogOFF");
}

void JPush::setBadge(int value)
{
    Jni::callStaticVoidMethod(JAVA_JPUSH_CLASS, "setBadge", value);
}

bool JPush::isEnabled()
{
    return Jni::callStaticBooleanMethod(JAVA_JPUSH_CLASS, "isEnabled");
}

void JPush::requestPermission()
{
    Jni::callStaticVoidMethod(JAVA_JPUSH_CLASS, "requestPermission");
}

std::string JPush::getRegistrationID()
{
    return Jni::callStaticStringMethod(JAVA_JPUSH_CLASS, "getRegistrationID");
}
#endif // CCLUA_BUILD_JPUSH

#ifdef CCLUA_BUILD_JAUTH
void JAuth::init(const std::string &appKey, const std::string &channel)
{
    Jni::callStaticVoidMethod(JAVA_JAUTH_CLASS, "init", appKey, channel);
}

bool JAuth::isInitSuccess()
{
    return Jni::callStaticBooleanMethod(JAVA_JAUTH_CLASS, "isInitSuccess");
}

void JAuth::setDebug(bool enabled)
{
    Jni::callStaticVoidMethod(JAVA_JAUTH_CLASS, "setDebug", enabled);
}

bool JAuth::checkVerifyEnable()
{
    return Jni::callStaticBooleanMethod(JAVA_JAUTH_CLASS, "checkVerifyEnable");
}

static int ref(const Callback callback) {
    return runtime::ref([=](const std::string &args){
        ValueMap data;
        parseJSONString(args, data);
        callback(data);
    });
}

void JAuth::getToken(int timeout, const Callback callback)
{
    Jni::callStaticVoidMethod(JAVA_JAUTH_CLASS, "getToken", timeout, ref(callback));
}

void JAuth::preLogin(int timeout, const Callback callback)
{
    Jni::callStaticVoidMethod(JAVA_JAUTH_CLASS, "preLogin", timeout, ref(callback));
}

void JAuth::clearPreLoginCache()
{
    Jni::callStaticVoidMethod(JAVA_JAUTH_CLASS, "clearPreLoginCache");
}

void JAuth::loginAuth(int timeout, const Callback callback)
{
    Jni::callStaticVoidMethod(JAVA_JAUTH_CLASS, "loginAuth", timeout, ref(callback));
}

void JAuth::dismissLoginAuth(bool needCloseAnim)
{
    Jni::callStaticVoidMethod(JAVA_JAUTH_CLASS, "dismissLoginAuth", needCloseAnim);
}

void JAuth::getSmsCode(const std::string &phonenum, const std::string &signid, const std::string &tempid, const Callback callback)
{
    Jni::callStaticVoidMethod(JAVA_JAUTH_CLASS, "getSmsCode", phonenum, signid, tempid, ref(callback));
}

void JAuth::setSmsIntervalTime(long intervalTime)
{
    Jni::callStaticVoidMethod(JAVA_JAUTH_CLASS, "setSmsIntervalTime", intervalTime);
}

void JAuth::configUI(cocos2d::ValueMap &value, bool landscape)
{
    Jni::callStaticVoidMethod(JAVA_JAUTH_CLASS, "configUI", toJSONString(value), landscape);
}

#endif

#ifdef CCLUA_BUILD_JANALYTICS
void JAnalytics::init(const std::string &appKey, const std::string &channel)
{
    Jni::callStaticVoidMethod(JAVA_JANALYTICS_CLASS, "init", appKey, channel);
}

void JAnalytics::startTrackPage(const std::string &pageName)
{
    Jni::callStaticVoidMethod(JAVA_JANALYTICS_CLASS, "startTrackPage", pageName);
}

void JAnalytics::stopTrackPage(const std::string &pageName)
{
    Jni::callStaticVoidMethod(JAVA_JANALYTICS_CLASS, "stopTrackPage", pageName);
}

void JAnalytics::trackEvent(EventType type, cocos2d::ValueMap &value)
{
    Jni::callStaticVoidMethod(JAVA_JANALYTICS_CLASS, "trackEvent", (int)type, toJSONString(value));
}

void JAnalytics::identifyAccount(cocos2d::ValueMap &value)
{
    Jni::callStaticVoidMethod(JAVA_JANALYTICS_CLASS, "identifyAccount", toJSONString(value));
}

void JAnalytics::detachAccount()
{
    Jni::callStaticVoidMethod(JAVA_JANALYTICS_CLASS, "detachAccount");
}

void JAnalytics::setFrequency(int frequency)
{
    Jni::callStaticVoidMethod(JAVA_JANALYTICS_CLASS, "setFrequency", frequency);
}

void JAnalytics::setDebug(bool enable)
{
    Jni::callStaticVoidMethod(JAVA_JANALYTICS_CLASS, "setDebug", enable);
}

#endif // CCLUA_BUILD_JANALYTICS

NS_CCLUA_PLUGIN_END

#endif
