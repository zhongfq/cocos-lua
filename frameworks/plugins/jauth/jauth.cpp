#include "jauth.h"

#if defined(CCLUA_BUILD_JAUTH) && defined(CCLUA_OS_ANDROID)

USING_NS_CCLUA;
USING_NS_CCLUA_PLUGIN;

const char *jauth::JAVA_CLASS = "cclua/plugin/jauth/JAuth";
Callback jauth::_dispatcher;

void jauth::init(const std::string &appKey, const std::string &channel)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "init", appKey, channel);
}

bool jauth::isInitSuccess()
{
    return Jni::callStaticBooleanMethod(JAVA_CLASS, "isInitSuccess");
}

void jauth::setDebug(bool enabled)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setDebug", enabled);
}

bool jauth::checkVerifyEnable()
{
    return Jni::callStaticBooleanMethod(JAVA_CLASS, "checkVerifyEnable");
}

void jauth::getToken(int timeout)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "getToken", timeout);
}

void jauth::preLogin(int timeout)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "preLogin", timeout);
}

void jauth::clearPreLoginCache()
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "clearPreLoginCache");
}

void jauth::loginAuth(int timeout)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "loginAuth", timeout);
}

void jauth::dismissLoginAuth(bool needCloseAnim)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "dismissLoginAuth", needCloseAnim);
}

void jauth::getSmsCode(const std::string &phonenum, const std::string &signid, const std::string &tempid)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "getSmsCode", phonenum, signid, tempid);
}

void jauth::setSmsIntervalTime(int64_t intervalTime)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setSmsIntervalTime", intervalTime);
}

void jauth::configUI(const cocos2d::ValueMap &value, bool landscape)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "configUI", toJSONString(value), landscape);
}
#endif // CCLUA_BUILD_JAUTH
