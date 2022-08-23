#include "wechat.h"

#if defined(CCLUA_BUILD_WECHAT) && defined(CCLUA_OS_ANDROID)

USING_NS_CCLUA;
USING_NS_CCLUA_PLUGIN;

Callback wechat::_dispatcher;
const char *wechat::JAVA_CLASS = "cclua/plugin/wechat/WeChat";

void wechat::init(const std::string &appid, const std::string &universalLink)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "init", appid);
}

bool wechat::isInstalled()
{
    return Jni::callStaticBooleanMethod(JAVA_CLASS, "isInstalled");
}

void wechat::pay(const std::string &partnerId, const std::string &prepayId, const std::string &noncestr, const std::string &timestamp, const std::string &packageValue, const std::string &sign)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "pay", partnerId, prepayId, noncestr, timestamp, packageValue, sign);
}

void wechat::auth(const std::string &scope, const std::string &state)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "auth", scope, state);
}

void wechat::authQRCode(const std::string &appid, const std::string &nonceStr, const std::string &timestamp, const std::string &scope, const std::string &signature)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "authQRCode", appid, scope, nonceStr, timestamp, signature);
}

void wechat::stopAuth()
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "stopAuth");
}

void wechat::share(ShareType type, cocos2d::ValueMap &value)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "share", toJSONString(value));
}

void wechat::open(const std::string &username, const std::string &path, ProgramType type)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "open", username, path, (int)type);
}

void wechat::openCustomerService(const std::string &corpid, const std::string &url)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "openCustomerService", corpid, url);
}

#endif
