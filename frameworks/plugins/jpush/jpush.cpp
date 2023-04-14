#include "jpush.h"

#if defined(CCLUA_BUILD_JPUSH) && defined(CCLUA_OS_ANDROID)

USING_NS_CCLUA;
USING_NS_CCLUA_PLUGIN;

const char *jpush::JAVA_CLASS = "cclua/plugin/jpush/JPush";

void jpush::init(const std::string &appKey, const std::string &channel)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "init", appKey, channel);
}

void jpush::setAlias(const std::string &alias)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setAlias", alias);
}

void jpush::deleteAlias()
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "deleteAlias");
}

void jpush::addTags(const std::set<std::string> &tags)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "addTags", toJSONString(tags));
}

void jpush::setTags(const std::set<std::string> &tags)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setTags", toJSONString(tags));
}

void jpush::deleteTags(const std::set<std::string> &tags)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "deleteTags", toJSONString(tags));
}

void jpush::cleanTags()
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "cleanTags");
}

void jpush::setDebug(bool enabled)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setDebugMode", enabled);
}

void jpush::setLogOFF()
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setLogOFF");
}

void jpush::setBadge(int value)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setBadge", value);
}

bool jpush::isEnabled()
{
    return Jni::callStaticBooleanMethod(JAVA_CLASS, "isEnabled");
}

void jpush::requestPermission()
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "requestPermission");
}

std::string jpush::getRegistrationID()
{
    return Jni::callStaticStringMethod(JAVA_CLASS, "getRegistrationID");
}

#endif // CCLUA_BUILD_JPUSH
