#ifndef __CCLUA_PLUGIN_JANALYTICS_H__
#define __CCLUA_PLUGIN_JANALYTICS_H__

#include "cclua/plugin.h"

NS_CCLUA_PLUGIN_BEGIN

class janalytics {
public:
    enum class EventType {
        LOGIN, REGISTER, PURCHASE, BROWSE, COUNT, CALCULATE
    };
    
    static void init(const std::string &appKey, const std::string &channel);
    static void startTrackPage(const std::string &pageName);
    static void stopTrackPage(const std::string &pageName);
    static void trackEvent(EventType type, const cocos2d::ValueMap &value);
    static void identifyAccount(const cocos2d::ValueMap &value);
    static void detachAccount();
    static void setFrequency(int frequency);
    static void setDebug(bool enable);

private:
#ifdef CCLUA_OS_ANDROID
    static const char *JAVA_CLASS;
#endif
};

NS_CCLUA_PLUGIN_END

#endif
