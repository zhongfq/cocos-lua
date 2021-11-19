#ifndef __CCLUA_PLUGIN_WECHAT_H__
#define __CCLUA_PLUGIN_WECHAT_H__

#include "cclua/plugin.h"

#include <string>

#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)

NS_CCLUA_PLUGIN_BEGIN

class WeChat {
public:
    enum class ShareType {NONE, TEXT, IMAGE, MUSIC, VIDEO, WEB};
    enum class ProgramType {RELEASE = 0, TEST = 1, PREVIEW = 2};

#ifdef CCLUA_OS_ANDROID
    static void pay(const std::string &partnerId, const std::string &prepayId, const std::string &noncestr, const std::string &timestamp, const std::string &packageValue, const std::string &sign);
#endif
    
    static void init(const std::string &appid, const std::string &universalLink);
    static bool isInstalled();
    static void auth(const std::string &scope, const std::string &state);
    static void authQRCode(const std::string &appid, const std::string &nonceStr, const std::string &timestamp, const std::string &scope, const std::string &signature);
    static void stopAuth();
    static void share(ShareType type, cocos2d::ValueMap &value);
    static void open(const std::string &username, const std::string path = "", ProgramType type = ProgramType::RELEASE);
    static void openCustomerService(const std::string &corpid, const std::string &url);

    DISPATCHER_IMPL
};

NS_CCLUA_PLUGIN_END

#endif

#endif //__CCLUA_PLUGIN_WECHAT_H__
