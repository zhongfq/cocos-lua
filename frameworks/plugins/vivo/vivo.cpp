#include "vivo.h"

#if defined(CCLUA_BUILD_VIVO) && defined(CCLUA_OS_ANDROID)

USING_NS_CCLUA;
USING_NS_CCLUA_PLUGIN;

const char *vivo::JAVA_CLASS = "cclua/plugin/vivo/Vivo";
Callback vivo::_dispatcher;

void vivo::init()
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "init");
}
void vivo::pay(const std::string &appid, const std::string &orderNo, const std::string &url,
    const std::string &price, const std::string &name, const std::string &desc, 
    const std::string &sign)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "pay", appid, orderNo, url, price, name, desc, sign);
}

#endif