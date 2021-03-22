#include "WeChat.h"

#if defined(CCLUA_OS_ANDROID)
#include "cclua/jniutil.h"

NS_CCLUA_PLUGIN_BEGIN

#define JAVA_WECHAT_CLASS        "cclua/plugin/wechat/WeChat"

USING_NS_CC;
USING_NS_CCLUA;

Dispatcher WeChat::_dispatcher;

void WeChat::init(const std::string &appid, const std::string &universalLink)
{
    JniUtil::callStaticVoidMethod(JAVA_WECHAT_CLASS, "init", appid);
}

bool WeChat::isInstalled()
{
    return JniUtil::callStaticBooleanMethod(JAVA_WECHAT_CLASS, "isInstalled");
}

static int callback(const std::string &event) {
    return runtime::ref([=](const std::string &args){
        ValueMap data;
        parseJSONString(args, data);
        WeChat::dispatch(event, data);
    });
}

void WeChat::pay(const std::string &partnerId, const std::string &prepayId, const std::string &noncestr, const std::string &timestamp, const std::string &packageValue, const std::string &sign)
{
    JniUtil::callStaticVoidMethod(JAVA_WECHAT_CLASS, "pay", partnerId, prepayId, noncestr, timestamp, packageValue, sign, callback("pay"));
}

void WeChat::auth(const std::string &scope, const std::string &state)
{
    JniUtil::callStaticVoidMethod(JAVA_WECHAT_CLASS, "auth", scope, state, callback("auth"));
}

void WeChat::authQRCode(const std::string &appid, const std::string &nonceStr, const std::string &timestamp, const std::string &scope, const std::string &signature)
{
    JniUtil::callStaticVoidMethod(JAVA_WECHAT_CLASS, "authQRCode", appid, scope,
        nonceStr, timestamp, signature, callback("authQRCode"));
}

void WeChat::stopAuth()
{
    JniUtil::callStaticVoidMethod(JAVA_WECHAT_CLASS, "stopAuth");
}

void WeChat::share(ShareType type, cocos2d::ValueMap &value)
{
    JniUtil::callStaticVoidMethod(JAVA_WECHAT_CLASS, "share", toJSONString(value), callback("share"));
}

void WeChat::open(const std::string &username, const std::string path, ProgramType type)
{
    JniUtil::callStaticVoidMethod("open", username, path, (int)type, callback("open"));
}

NS_CCLUA_PLUGIN_END

#endif
