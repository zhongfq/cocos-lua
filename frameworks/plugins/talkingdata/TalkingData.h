#ifndef __CCLUA_PLUGIN_TALKINGDATA_H__
#define __CCLUA_PLUGIN_TALKINGDATA_H__

#include "cclua/plugin.h"

NS_CCLUA_PLUGIN_BEGIN

class talkingdata {
public:
    static std::string getDeviceId();
    static void setVerboseLogDisable();
    static void setConfigurationDisable(uint64_t options);
    static void backgroundSessionEnabled();
    static void init(const std::string &appkey, const std::string &channel, const std::string &custom = "");
    static void setVendorId(const std::string &vendorId, int type);
    static void setLocation(double latitude, double longitude);
    static void setExceptionReportEnabled(bool value);
    static void setSignalReportEnabled(bool value);
    static void onPageBegin(const std::string &name);
    static void onPageEnd(const std::string &name);
    static void onReceiveDeepLink(const std::string &link);
    static void onRegister(const std::string &uid, const cocos2d::ValueMap &data, const std::string &invitationCode);
    static void onLogin(const std::string &uid, const cocos2d::ValueMap &data);
    static void onProfileUpdate(const cocos2d::ValueMap &data);
    static void onCreateCard(const std::string &uid, const std::string &method, const std::string &content);
    static void onFavorite(const std::string &category, const std::string &content);
    static void onShare(const std::string &uid, const std::string &content);
    static void onPunch(const std::string &uid, const std::string &punchid);
    static void onSearch(const cocos2d::ValueMap &data);
    static void onEvent(const std::string &event, double value, const cocos2d::ValueMap &data);
    static void setGlobalKV(const std::string &key, const cocos2d::Value &value);    
    static void removeGlobalKV(const std::string &key);
private:
#ifdef CCLUA_OS_ANDROID
    static const char *JAVA_CLASS;
#endif
};

NS_CCLUA_PLUGIN_END

#endif //__CCLUA_PLUGIN_TALKINGDATA_H__
