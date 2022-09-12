#ifndef __CCLUA_PLUGIN_HUAWEI_H__
#define __CCLUA_PLUGIN_HUAWEI_H__

#include "cclua/plugin.h"

NS_CCLUA_PLUGIN_BEGIN

class huawei {
public:
    static void init();
    static void revokeAccess();
    static void logout();
    static void login();
    static void pay(const std::string &appid, const std::string &cpid, const std::string &cp,
        const std::string &orderNo, const std::string &pid, const std::string &url,
        const std::string &serviceCatalog, const std::string &extReserved, const std::string &sign);

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

NS_CCLUA_PLUGIN_END

#endif // __CCLUA_PLUGIN_HUAWEI_H__
