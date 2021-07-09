#ifndef __CCLUA_PLUGIN_TALKINGDATA_H__
#define __CCLUA_PLUGIN_TALKINGDATA_H__

#include "cclua/plugin.h"

#include <string>

#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)

NS_CCLUA_PLUGIN_BEGIN

// lua class name is TalkingData
class TCAgent {
public:
    static void setLogEnabled(bool value);
    static void init(const std::string &appkey, const std::string &channel);
    static void onRegister(const std::string &uid, int type, const std::string &name);
    static void onLogin(const std::string &uid, int type, const std::string &name);
    static void setReportUncaughtExceptions(bool value);
    static void trackPageBegin(const std::string &name);
    static void trackPageEnd(const std::string &name);
    static void trackEvent(const std::string &event);
    static void trackEvent(const std::string &event, const std::string &label);
    static void trackEvent(const std::string &event, const std::string &label, const cocos2d::ValueMap &map);
    static void trackEvent(const std::string &event, const std::string &label, const cocos2d::ValueMap &map, double value);
    static void setGlobalKV(const std::string &key, bool value);
    static void setGlobalKV(const std::string &key, const std::string &value);
    static void setGlobalKV(const std::string &key, long value);
    static void setGlobalKV(const std::string &key, double value);
    static void removeGlobalKV(const std::string &key);
    static void placeOrder(const std::string &orderId, int amount, const std::string &currencyType);
    static void payOrder(const std::string &orderId, int amount, const std::string &currencyType, const std::string &paymentType);
    static void cancelOrder(const std::string &orderId, int amount, const std::string &currencyType);
    static void viewItem(const std::string &itemId, const std::string &category, const std::string &name, int unitPrice);
};

NS_CCLUA_PLUGIN_END

#endif

#endif //__CCLUA_PLUGIN_TALKINGDATA_H__
