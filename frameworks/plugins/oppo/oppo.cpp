#include "oppo.h"

#if defined(CCLUA_BUILD_OPPO) && defined(CCLUA_OS_ANDROID)

USING_NS_CCLUA;
USING_NS_CCLUA_PLUGIN;

const char *oppo::JAVA_CLASS = "cclua/plugin/oppo/Oppo";
Callback oppo::_dispatcher;

void oppo::init()
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "init");
}

void oppo::pay(const std::string &orderNo, const std::string &attach, int price, 
        const std::string &name, const std::string &desc, const std::string &url)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "pay", orderNo, attach, price, name, desc, url);
}

#endif