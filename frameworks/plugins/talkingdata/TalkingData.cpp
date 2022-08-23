#include "talkingdata.h"

#if defined(CCLUA_BUILD_TALKINGDATA) && defined(CCLUA_OS_ANDROID)

USING_NS_CCLUA;
USING_NS_CCLUA_PLUGIN;

const char *talkingdata::JAVA_CLASS = "cclua/plugin/talkingdata/TalkingData";

void talkingdata::setLogEnabled(bool value)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setLogEnabled", value);
}

void talkingdata::init(const std::string &appkey, const std::string &channel)
{
    Jni::callStaticBooleanMethod(JAVA_CLASS, "init", appkey, channel);
}

void talkingdata::onRegister(const std::string &uid, int type, const std::string &name)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "onRegister", uid, type, name);
}

void talkingdata::onLogin(const std::string &uid, int type, const std::string &name)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "onLogin", uid, type, name);
}

void talkingdata::setReportUncaughtExceptions(bool value)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setReportUncaughtExceptions", value);
}

void talkingdata::trackPageBegin(const std::string &name)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "trackPageBegin", name);
}

void talkingdata::trackPageEnd(const std::string &name)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "trackPageEnd", name);
}

void talkingdata::trackEvent(const std::string &event)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "trackEvent", event);
}

void talkingdata::trackEvent(const std::string &event, const std::string &label)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "trackEvent", event, label);
}

void talkingdata::trackEvent(const std::string &event, const std::string &label, const cocos2d::ValueMap &map)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "trackEvent", event, label, toJSONString(map));
}

void talkingdata::trackEvent(const std::string &event, const std::string &label, const cocos2d::ValueMap &map, double value)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "trackEvent", event, label, toJSONString(map), value);
}

void talkingdata::setGlobalKV(const std::string &key, bool value)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setGlobalKV", key, value);
}

void talkingdata::setGlobalKV(const std::string &key, const std::string &value)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setGlobalKV", key, value);
}

void talkingdata::setGlobalKV(const std::string &key, long value)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setGlobalKV", key, value);
}

void talkingdata::setGlobalKV(const std::string &key, double value)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setGlobalKV", key, value);
}

void talkingdata::removeGlobalKV(const std::string &key)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "removeGlobalKV", key);
}

void talkingdata::placeOrder(const std::string &orderId, int amount, const std::string &currencyType)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "placeOrder", orderId, amount, currencyType);
}

void talkingdata::payOrder(const std::string &orderId, int amount, const std::string &currencyType, const std::string &paymentType)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "payOrder", orderId, amount, currencyType, paymentType);
}

void talkingdata::cancelOrder(const std::string &orderId, int amount, const std::string &currencyType)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "cancelOrder", orderId, amount, currencyType);
}

void talkingdata::viewItem(const std::string &itemId, const std::string &category, const std::string &name, int unitPrice)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "viewItem", itemId, category, name, unitPrice);
}

#endif
