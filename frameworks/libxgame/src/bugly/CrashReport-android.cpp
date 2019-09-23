#include "CrashReport.h"

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <android/log.h>
#include <string.h>

#define LOG_TAG "CrashReport"
#define LOG_BUFFER_SIZE 1024

#ifndef GAME_TYPE_COCOS
#define GAME_TYPE_COCOS 1
#endif

#define LOGD(fmt, args...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, fmt, ##args)
#define LOGI(fmt, args...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, fmt, ##args)
#define LOGW(fmt, args...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, fmt, ##args)
#define LOGE(fmt, args...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, fmt, ##args)

#define BUGLY_CLASS "kernel/plugins/bugly/Bugly"

CrashReport::CrashReport(){
    LOGD("%s", __FUNCTION__);
}

void CrashReport::initCrashReport(const char* appId) {
    CrashReport::initCrashReport(appId, false);
}

void CrashReport::initCrashReport(const char* appId, bool isDebug) {
    CrashReport::initCrashReport(appId, isDebug, CrashReport::CRLogLevel::Off);
}

bool CrashReport::initialized = false;
bool CrashReport::hasSetGameType = false;
int CrashReport::crashReporterType = 0;

void CrashReport::initCrashReport(const char* appId, bool isDebug, CrashReport::CRLogLevel level)
{
	if (!initialized) {
        // call init
        LOGI("[cocos2d-x] init Bugly by game agent.");
        cocos2d::JniHelper::callStaticVoidMethod(BUGLY_CLASS, "initCrashReport", appId, isDebug);
        initialized = true;
    }
}

void CrashReport::setTag(int tag)
{
	LOGI("[cocos2d-x] set user scene tag: %d", tag);
    cocos2d::JniHelper::callStaticVoidMethod(BUGLY_CLASS, "setTag", tag);
}

void CrashReport::addUserValue(const char* key, const char* value)
{
    setGameType();
	LOGI("[cocos2d-x] put user data: %s:%s", key, value);
    cocos2d::JniHelper::callStaticVoidMethod(BUGLY_CLASS, "addUserValue", key, value);
}

void CrashReport::removeUserValue(const char* key)
{
    setGameType();
	LOGI("[cocos2d-x] remove user data: %s", key);
    cocos2d::JniHelper::callStaticVoidMethod(BUGLY_CLASS, "removeUserValue", key);
}

void CrashReport::setUserId(const char* userId)
{
    setGameType();
    LOGI("[cocos2d-x] set user ID: %s", userId);
    cocos2d::JniHelper::callStaticVoidMethod(BUGLY_CLASS, "setUserId", userId);
}

void CrashReport::reportException(int category, const char* type, const char* msg, const char* traceback) {
    reportException(category, type, msg, traceback, false);
}

void CrashReport::reportException(int category, const char* type, const char* msg, const char* traceback, bool quit) {
    LOGI("[cocos2d-x] post a exception.");
    cocos2d::JniHelper::callStaticVoidMethod(BUGLY_CLASS, "reportException", category, type, msg, traceback, quit);
}

void CrashReport::setAppChannel(const char * channel)
{
    setGameType();
    LOGI("[cocos2d-x] set App channel: %s", channel);
    cocos2d::JniHelper::callStaticVoidMethod(BUGLY_CLASS, "setAppChannel", channel);
}

void CrashReport::setAppVersion(const char * version)
{
    setGameType();
    cocos2d::JniHelper::callStaticVoidMethod(BUGLY_CLASS, "setAppVersion", version);
}

void CrashReport::log(CrashReport::CRLogLevel level, const char * tag, const char * fmts, ...) {
    static char msg[LOG_BUFFER_SIZE];
    va_list args;
    va_start(args, fmts);
    int size = vsnprintf(msg, LOG_BUFFER_SIZE, fmts, args);
    va_end(args);
    if (size > LOG_BUFFER_SIZE) {
        LOGW("The length[%d] of string is out of the buffer size[%d]", size, LOG_BUFFER_SIZE);
    }

    int logLevel = -1;
    if (CrashReport::CRLogLevel::Verbose == level) {
       logLevel = 0;
    } else if (CrashReport::CRLogLevel::Debug == level) {
        logLevel = 1;
    } else if (CrashReport::CRLogLevel::Info == level) {
        logLevel = 2;
    } else if (CrashReport::CRLogLevel::Warning == level) {
        logLevel = 3;
    } else if (CrashReport::CRLogLevel::Error == level) {
        logLevel = 4;
    }

    if (tag == NULL || strlen(tag) == 0) {
        tag = "Bugly";
    }

    cocos2d::JniHelper::callStaticVoidMethod(BUGLY_CLASS, "log", logLevel, tag, (const char *)msg);
}

void CrashReport::setGameType() {
}

void CrashReport::setCrashReporterType(int type) {
    crashReporterType = type;
}

#endif
