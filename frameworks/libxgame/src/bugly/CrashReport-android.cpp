#include "CrashReport.h"

#include "cocos2d.h"

#ifdef CCLUA_OS_ANDROID

#include "cclua/jniutil.h"

#include <android/log.h>
#include <string.h>

USING_NS_CCLUA;

#define BUGLY_CLASS "cclua/plugin/bugly/Bugly"

static bool s_initialized = false;

void CrashReport::init(const char *appid)
{
	if (!s_initialized) {
        runtime::log("init bugly");
        Jni::callStaticVoidMethod(BUGLY_CLASS, "init", appid, false);
        s_initialized = true;
    }
}

void CrashReport::setTag(int tag)
{
    Jni::callStaticVoidMethod(BUGLY_CLASS, "setTag", tag);
}

void CrashReport::setUserValue(const char *key, const char *value)
{
    Jni::callStaticVoidMethod(BUGLY_CLASS, "setUserValue", key, value);
}

void CrashReport::setUid(const char* userId)
{
    Jni::callStaticVoidMethod(BUGLY_CLASS, "setUid", userId);
}

void CrashReport::reportException(const char *msg, const char *traceback) {
    Jni::callStaticVoidMethod(BUGLY_CLASS, "reportException", 6, "", msg, traceback, false);
}

void CrashReport::setChannel(const char *channel)
{
    Jni::callStaticVoidMethod(BUGLY_CLASS, "setChannel", channel);
}

void CrashReport::setVersion(const char *version)
{
    Jni::callStaticVoidMethod(BUGLY_CLASS, "setVersion", version);
}

void CrashReport::log(LogLevel level, const char *msg) {
    Jni::callStaticVoidMethod(BUGLY_CLASS, "log", (int)level, "bugly", (const char *)msg);
}

#endif
