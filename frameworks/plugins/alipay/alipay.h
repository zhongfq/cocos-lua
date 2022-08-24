#ifndef __CCLUA_PLUGIN_ALIPAY_H__
#define __CCLUA_PLUGIN_ALIPAY_H__

#include "cclua/plugin.h"

NS_CCLUA_PLUGIN_BEGIN

class alipay {
public:
    static void pay(const std::string &order);
    
public:
    static void setDispatcher(const cclua::Callback &dispatcher)
    {
#ifdef CCLUA_OS_ANDROID
        callback_t func = runtime::ref(dispatcher);
        Jni::callStaticVoidMethod(JAVA_CLASS, "setDispatcher", func);
#else
        _dispatcher = dispatcher;
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

#endif // __CCLUA_PLUGIN_ALIPAY_H__
