#include "CrashReport.h"

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <android/log.h>
#include <string.h>

#define BUGLY_CLASS "kernel/plugins/bugly/Bugly"

static bool s_initialized = false;

void CrashReport::init(const char *appid)
{
	if (!s_initialized) {
        cocos2d::JniHelper::callStaticVoidMethod(BUGLY_CLASS, "init", appid, false);
        s_initialized = true;
    }
}

void CrashReport::setTag(int tag)
{
    cocos2d::JniHelper::callStaticVoidMethod(BUGLY_CLASS, "setTag", tag);
}

void CrashReport::setUserValue(const char *key, const char *value)
{
    cocos2d::JniHelper::callStaticVoidMethod(BUGLY_CLASS, "setUserValue", key, value);
}

void CrashReport::setUid(const char* userId)
{
    cocos2d::JniHelper::callStaticVoidMethod(BUGLY_CLASS, "setUid", userId);
}

void CrashReport::reportException(const char *msg, const char *traceback) {
    cocos2d::JniHelper::callStaticVoidMethod(BUGLY_CLASS, "reportException", 6, "", msg, traceback, false);
}

void CrashReport::setChannel(const char *channel)
{
    cocos2d::JniHelper::callStaticVoidMethod(BUGLY_CLASS, "setChannel", channel);
}

void CrashReport::setVersion(const char *version)
{
    cocos2d::JniHelper::callStaticVoidMethod(BUGLY_CLASS, "setVersion", version);
}

void CrashReport::log(LogLevel level, const char *msg) {
    cocos2d::JniHelper::callStaticVoidMethod(BUGLY_CLASS, "log", (int)level, "bugly", (const char *)msg);
}

#endif
