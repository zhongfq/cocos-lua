#include "huawei.h"

#if defined(CCLUA_BUILD_HUAWEI) && defined(CCLUA_OS_ANDROID)

USING_NS_CCLUA;
USING_NS_CCLUA_PLUGIN;

const char *huawei::JAVA_CLASS = "cclua/plugin/huawei/Huawei";
Callback huawei::_dispatcher;

void huawei::init()
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "init");
}

void huawei::revokeAccess()
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "revokeAccess");
}

void huawei::logout()
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "logout");
}

void huawei::login()
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "login");
}

void huawei::pay(const std::string &appid, const std::string &cpid, const std::string &cp,
        const std::string &orderNo, const std::string &pid, const std::string &url,
        const std::string &serviceCatalog, const std::string &extReserved, const std::string &sign)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "pay", appid, cpid, cp, orderNo, pid, url, serviceCatalog,
        extReserved, sign);
}

#endif