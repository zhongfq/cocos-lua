#include "photo.h"

#if defined(CCLUA_OS_ANDROID)

USING_NS_CCLUA;
USING_NS_CCLUA_PLUGIN;

const char *photo::JAVA_CLASS = "cclua/Photo";
Callback photo::_dispatcher;

void photo::selectAvatar(const std::string &cachePath, int width, int height)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "selectAvatar", cachePath, width, height);
}

void photo::takeAvatar(const std::string &cachePath, int width, int height)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "takeAvatar", cachePath, width, height);
}

void photo::select(const std::string &cachePath)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "select", cachePath);
}

#endif
