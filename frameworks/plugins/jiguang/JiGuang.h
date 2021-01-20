#ifndef __CCLUA_PLUGIN_JIGUANG_H__
#define __CCLUA_PLUGIN_JIGUANG_H__

#include "cclua/plugin.h"

#include <string>
#include <set>
#include <functional>
#include <unordered_map>

#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)

NS_CCLUA_PLUGIN_BEGIN

#ifdef CCLUA_BUILD_JPUSH
class JPush {
public:
    static void init(const std::string &appKey, const std::string &channel);
    static void setAlias(const std::string &alias);
    static void deleteAlias();
    static void addTags(const std::set<std::string> &tags);
    static void setTags(const std::set<std::string> &tags);
    static void deleteTags(const std::set<std::string> &tags);
    static void cleanTags();
    static void setDebug(bool enabled);
    static void setLogOFF();
    static void setBadge(int value);
    static bool isEnabled();
    static void requestPermission();
    static std::string getRegistrationID();
};
#endif

#ifdef CCLUA_BUILD_JAUTH
class JAuth {
public:
    static void init(const std::string &appKey, const std::string &channel);
    static bool isInitSuccess();
    static void setDebug(bool enabled);
    static bool checkVerifyEnable();
    static void getToken(int timeout, const Callback callback);
    static void preLogin(int timeout, const Callback callback);
    static void clearPreLoginCache();
    static void loginAuth(int timeout, const Callback callback);
    static void dismissLoginAuth(bool needCloseAnim = true);
    static void getSmsCode(const std::string &phonenum, const std::string &signid, const std::string &tempid, const Callback callback);
    static void setSmsIntervalTime(long intervalTime);
    static void configUI(cocos2d::ValueMap &value);
};
#endif

#ifdef CCLUA_BUILD_JANALYTICS
class JAnalytics {
public:
    enum class EventType {
        LOGIN, REGISTER, PURCHASE, BROWSE, COUNT, CALCULATE
    };
    
    static void init(const std::string &appKey, const std::string &channel);
    static void startTrackPage(const std::string &pageName);
    static void stopTrackPage(const std::string &pageName);
    static void trackEvent(EventType type, cocos2d::ValueMap &value);
    static void identifyAccount(cocos2d::ValueMap &value);
    static void detachAccount();
    static void setFrequency(int frequency);
    static void setDebug(bool enable);
};
#endif

NS_CCLUA_PLUGIN_END

#endif

#endif
