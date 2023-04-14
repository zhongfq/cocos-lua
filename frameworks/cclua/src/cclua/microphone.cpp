#include "microphone.h"

#if defined(CCLUA_OS_ANDROID)

USING_NS_CCLUA;
USING_NS_CCLUA_PLUGIN;

Callback microphone::_dispatcher;
const char *microphone::JAVA_CLASS = "cclua/Microphone";

void microphone::start(const std::string &path)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "start", path);
}

void microphone::stop()
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "stop");
}

bool microphone::isRunning()
{
    return Jni::callStaticBooleanMethod(JAVA_CLASS, "isRunning");
}

#endif
