#include "TalkingData.h"

#if defined(CCLUA_OS_ANDROID)
#include "cclua/jniutil.h"

USING_NS_CC;
USING_NS_CCLUA;
USING_NS_CCLUA_PLUGIN;

#define TDCLASS "cclua/plugin/talkingdata/TalkingData"

void TCAgent::setLogEnabled(bool value)
{
    Jni::callStaticVoidMethod(TDCLASS, "setLogEnabled", value);
}

void TCAgent::init(const std::string &appkey, const std::string &channel)
{
    Jni::callStaticBooleanMethod(TDCLASS, "init", appkey, channel);
}

void TCAgent::onRegister(const std::string &uid, int type, const std::string &name)
{
    Jni::callStaticVoidMethod(TDCLASS, "onRegister", uid, type, name);
}

void TCAgent::onLogin(const std::string &uid, int type, const std::string &name)
{
    Jni::callStaticVoidMethod(TDCLASS, "onLogin", uid, type, name);
}

void TCAgent::setReportUncaughtExceptions(bool value)
{
    Jni::callStaticVoidMethod(TDCLASS, "setReportUncaughtExceptions", value);
}

void TCAgent::trackPageBegin(const std::string &name)
{
    Jni::callStaticVoidMethod(TDCLASS, "trackPageBegin", name);
}

void TCAgent::trackPageEnd(const std::string &name)
{
    Jni::callStaticVoidMethod(TDCLASS, "trackPageEnd", name);
}

void TCAgent::trackEvent(const std::string &event)
{
    Jni::callStaticVoidMethod(TDCLASS, "trackEvent", event);
}

void TCAgent::trackEvent(const std::string &event, const std::string &label)
{
    Jni::callStaticVoidMethod(TDCLASS, "trackEvent", event, label);
}

void TCAgent::trackEvent(const std::string &event, const std::string &label, const cocos2d::ValueMap &map)
{
    Jni::callStaticVoidMethod(TDCLASS, "trackEvent", event, label, toJSONString(map));
}

void TCAgent::trackEvent(const std::string &event, const std::string &label, const cocos2d::ValueMap &map, double value)
{
    Jni::callStaticVoidMethod(TDCLASS, "trackEvent", event, label, toJSONString(map), value);
}

void TCAgent::setGlobalKV(const std::string &key, bool value)
{
    Jni::callStaticVoidMethod(TDCLASS, "setGlobalKV", key, value);
}

void TCAgent::setGlobalKV(const std::string &key, const std::string &value)
{
    Jni::callStaticVoidMethod(TDCLASS, "setGlobalKV", key, value);
}

void TCAgent::setGlobalKV(const std::string &key, long value)
{
    Jni::callStaticVoidMethod(TDCLASS, "setGlobalKV", key, value);
}

void TCAgent::setGlobalKV(const std::string &key, double value)
{
    Jni::callStaticVoidMethod(TDCLASS, "setGlobalKV", key, value);
}

void TCAgent::removeGlobalKV(const std::string &key)
{
    Jni::callStaticVoidMethod(TDCLASS, "removeGlobalKV", key);
}

void TCAgent::placeOrder(const std::string &orderId, int amount, const std::string &currencyType)
{
    Jni::callStaticVoidMethod(TDCLASS, "placeOrder", orderId, amount, currencyType);
}

void TCAgent::payOrder(const std::string &orderId, int amount, const std::string &currencyType, const std::string &paymentType)
{
    Jni::callStaticVoidMethod(TDCLASS, "payOrder", orderId, amount, currencyType, paymentType);
}

void TCAgent::cancelOrder(const std::string &orderId, int amount, const std::string &currencyType)
{
    Jni::callStaticVoidMethod(TDCLASS, "cancelOrder", orderId, amount, currencyType);
}

void TCAgent::viewItem(const std::string &itemId, const std::string &category, const std::string &name, int unitPrice)
{
    Jni::callStaticVoidMethod(TDCLASS, "viewItem", itemId, category, name, unitPrice);
}

#endif
