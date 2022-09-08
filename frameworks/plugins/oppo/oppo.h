#ifndef __CCLUA_PLUGIN_OPPO_H__
#define __CCLUA_PLUGIN_OPPO_H__

#include "cclua/plugin.h"

NS_CCLUA_PLUGIN_BEGIN

class oppo {
public:
    static void init();
    static void pay(const std::string &orderNo, const std::string &attach, int price, 
        const std::string &name, const std::string &desc, const std::string &url);
    
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

#endif // __CCLUA_PLUGIN_OPPO_H__
