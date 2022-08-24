#include "CrashReport.h"

#ifdef CCLUA_OS_ANDROID

USING_NS_CCLUA;

const char *bugly::JAVA_CLASS = "cclua/plugin/bugly/Bugly";

static bool s_initialized = false;

void bugly::init(const char *appid)
{
	if (!s_initialized) {
        runtime::log("init bugly");
        Jni::callStaticVoidMethod(JAVA_CLASS, "init", appid, false);
        s_initialized = true;
    }
}

void bugly::setTag(int tag)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setTag", tag);
}

void bugly::setUserValue(const char *key, const char *value)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setUserValue", key, value);
}

void bugly::setUid(const char* userId)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setUid", userId);
}

void bugly::reportException(const char *msg, const char *traceback) {
    Jni::callStaticVoidMethod(JAVA_CLASS, "reportException", 6, "", msg, traceback, false);
}

void bugly::setChannel(const char *channel)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setChannel", channel);
}

void bugly::setVersion(const char *version)
{
    Jni::callStaticVoidMethod(JAVA_CLASS, "setVersion", version);
}

void bugly::log(LogLevel level, const char *msg) {
    Jni::callStaticVoidMethod(JAVA_CLASS, "log", (int)level, "bugly", (const char *)msg);
}

#endif
