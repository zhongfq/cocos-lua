#ifndef __CCLUA_PLUGIN_JIGUANG_H__
#define __CCLUA_PLUGIN_JIGUANG_H__

#include "cclua/plugin.h"

NS_CCLUA_PLUGIN_BEGIN

class jpush {
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
private:
#ifdef CCLUA_OS_ANDROID
    static const char *JAVA_CLASS;
#endif
};

class jauth {
public:
    static void init(const std::string &appKey, const std::string &channel);
    static bool isInitSuccess();
    static void setDebug(bool enabled);
    static bool checkVerifyEnable();
    static void getToken(int timeout);
    static void preLogin(int timeout);
    static void clearPreLoginCache();
    static void loginAuth(int timeout);
    static void dismissLoginAuth(bool needCloseAnim = true);
    static void getSmsCode(const std::string &phonenum, const std::string &signid, const std::string &tempid);
    static void setSmsIntervalTime(int64_t intervalTime);
    static void configUI(cocos2d::ValueMap &value, bool landscape = true);
    
public:
    static void setDispatcher(const cclua::Callback &dispatcher)
    {
        _dispatcher = dispatcher;
#ifdef CCLUA_OS_ANDROID
        olua_Ref func = runtime::ref(dispatcher);
        Jni::callStaticVoidMethod(JAVA_CLASS, "setDispatcher", func);
#endif
    }
    
    static void dispatch(const std::string &event, const cocos2d::ValueMap &data)
    {
        cclua::runtime::runLater([=]() {
            if (_dispatcher) {
                _dispatcher(event, cocos2d::Value(data));
            }
        });
    }
    
private:
    static cclua::Callback _dispatcher;
#ifdef CCLUA_OS_ANDROID
    static const char *JAVA_CLASS;
#endif
};

class janalytics {
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

private:
#ifdef CCLUA_OS_ANDROID
    static const char *JAVA_CLASS;
#endif
};

NS_CCLUA_PLUGIN_END

#endif
