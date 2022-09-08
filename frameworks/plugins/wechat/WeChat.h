#ifndef __CCLUA_PLUGIN_WECHAT_H__
#define __CCLUA_PLUGIN_WECHAT_H__

#include "cclua/plugin.h"

NS_CCLUA_PLUGIN_BEGIN

class wechat {
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
    static void open(const std::string &username, const std::string &path = "", ProgramType type = ProgramType::RELEASE);
    static void openCustomerService(const std::string &corpid, const std::string &url);

public:
    static void setDispatcher(const cclua::Callback &dispatcher)
    {
        _dispatcher = dispatcher;
#ifdef CCLUA_OS_ANDROID
        olua_ref_t func = runtime::ref(dispatcher);
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

NS_CCLUA_PLUGIN_END

#endif //__CCLUA_PLUGIN_WECHAT_H__
