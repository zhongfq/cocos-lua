#include "talkingdata.h"

#if defined(CCLUA_BUILD_TALKINGDATA) && defined(CCLUA_OS_ANDROID)

USING_NS_CCLUA;
USING_NS_CCLUA_PLUGIN;

const char *talkingdata::JAVA_CLASS = "cclua/plugin/talkingdata/TalkingData";

std::string talkingdata::getDeviceId()
{
    return Jni::callStaticStringMethod(JAVA_CLASS, "getDeviceId");
}

void talkingdata::setVerboseLogDisable()
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setVerboseLogDisable");
}

void talkingdata::setConfigurationDisable(uint64_t options)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setConfigurationDisable", (int64_t)options);
}

void talkingdata::backgroundSessionEnabled()
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "backgroundSessionEnabled");
}

void talkingdata::init(const std::string &appkey, const std::string &channel, const std::string &custom)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "init", appkey, channel, custom);
}

void talkingdata::setVendorId(const std::string &vendorId, int type)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setVendorId", vendorId, type);
}

void talkingdata::setLocation(double latitude, double longitude)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setLocation", latitude, longitude);
}

void talkingdata::setExceptionReportEnabled(bool value)
{
   Jni::callStaticVoidMethod(JAVA_CLASS, "setExceptionReportEnabled", value);
}

void talkingdata::setSignalReportEnabled(bool value)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setSignalReportEnabled", value);
}

void talkingdata::onPageBegin(const std::string &name)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "onPageBegin", name);
}

void talkingdata::onPageEnd(const std::string &name)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "onPageEnd", name);
}

void talkingdata::onReceiveDeepLink(const std::string &link)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "onReceiveDeepLink", link);
}

void talkingdata::onRegister(const std::string &uid, cocos2d::ValueMap &data, const std::string &invitationCode)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "onRegister", uid, toJSONString(data), invitationCode);
}

void talkingdata::onLogin(const std::string &uid, cocos2d::ValueMap &data)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "onLogin", uid, toJSONString(data));
}

void talkingdata::onProfileUpdate(cocos2d::ValueMap &data)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "onProfileUpdate", toJSONString(data));
}

void talkingdata::onCreateCard(const std::string &uid, const std::string &method, const std::string &content)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "onCreateCard", uid, method, content);
}

void talkingdata::onFavorite(const std::string &category, const std::string &content)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "onFavorite", category, content);
}

void talkingdata::onShare(const std::string &uid, const std::string &content)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "onShare", uid, content);
}

void talkingdata::onPunch(const std::string &uid, const std::string &punchid)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "onPunch", uid, punchid);
}

void talkingdata::onSearch(cocos2d::ValueMap &data)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "onSearch", toJSONString(data));
}

void talkingdata::onEvent(const std::string &event, double value, const cocos2d::ValueMap &data)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "onEvent", event, value, toJSONString(data));
}

void talkingdata::setGlobalKV(const std::string &key, cocos2d::Value &value)
{
    auto type = value.getType();
    if (type == cocos2d::Value::Type::STRING) {
        Jni::callStaticVoidMethod(JAVA_CLASS, "setGlobalKV", key, value.asString());
    } else if (type == cocos2d::Value::Type::INTEGER) {
        Jni::callStaticVoidMethod(JAVA_CLASS, "setGlobalKV", key, value.asInt64());
    } else {
        Jni::callStaticVoidMethod(JAVA_CLASS, "setGlobalKV", key, value.asDouble());
    }
}

void talkingdata::removeGlobalKV(const std::string &key)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "removeGlobalKV", key);
}

#endif
