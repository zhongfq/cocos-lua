#include "alipay.h"

#if defined(CCLUA_BUILD_ALIPAY) && defined(CCLUA_OS_ANDROID)

USING_NS_CCLUA;
USING_NS_CCLUA_PLUGIN;

const char *alipay::JAVA_CLASS = "cclua/plugin/alipay/Alipay";
Callback alipay::_dispatcher;

void alipay::pay(const std::string &order)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "pay", order);
}

#endif