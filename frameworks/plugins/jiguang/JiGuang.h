#ifndef __JIGUANG_H__
#define __JIGUANG_H__

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
