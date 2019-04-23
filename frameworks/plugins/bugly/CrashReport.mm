
#include "CrashReport.h"
#include "BuglyAgent.h"

#include "cocos2d.h"
#include <string.h>

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

#define LOG_TAG "CrashReport"
#define LOG_BUFFER_SIZE 1024

#ifndef GAME_TYPE_COCOS
#define GAME_TYPE_COCOS 1
#endif

#import <Foundation/Foundation.h>

#define NSStringMake(const_char_pointer) (const_char_pointer == NULL ? nil : @(const_char_pointer))
#define NSStringMakeNonnull(const_char_pointer) (const_char_pointer == NULL ? @"" : @(const_char_pointer))

#define LOGD(fmt, args...) CCLOG("[Debug] %s: " fmt, LOG_TAG, ##args)
#define LOGI(fmt, args...) CCLOG("[Info] %s: " fmt, LOG_TAG, ##args)
#define LOGW(fmt, args...) CCLOGERROR("[Warn] %s: " fmt, LOG_TAG, ##args)
#define LOGE(fmt, args...) CCLOGERROR("[Error] %s: " fmt, LOG_TAG, ##args)

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
        LOGI("Init the sdk with App ID: %s", appId);
        [BuglyAgent initWithAppId: NSStringMake(appId) debugMode:isDebug logger:(BALogLevel)level];
        initialized = true;
    }
}

void CrashReport::setTag(int tag)
{
    setGameType();
    if (tag < 0) {
        return;
    }
    [BuglyAgent setSceneTag:tag];
    LOGI("Set user scene tag id: %d", tag);
}

void CrashReport::addUserValue(const char* key, const char* value)
{
    setGameType();
    LOGI("Set user Key-Value: [%s, %s]", key, value);
    [BuglyAgent setSceneValue:NSStringMakeNonnull(value) forKey:NSStringMakeNonnull(key)];
}

void CrashReport::removeUserValue(const char* key)
{
    setGameType();
    [BuglyAgent removeSceneValueForKey:NSStringMakeNonnull(key)];
}

void CrashReport::setUserId(const char* userId)
{
    setGameType();
    [BuglyAgent setUserIdentifier:NSStringMake(userId)];
    LOGI("Set user id: %s", userId);
}

void CrashReport::reportException(int category, const char* type, const char* msg, const char* traceback)
{
    reportException(category, type, msg, traceback, false);
}

void CrashReport::reportException(int category, const char* type, const char* msg, const char* traceback, bool quit)
{
    [BuglyAgent reportException:category
                           name:NSStringMake(type)
                        message:NSStringMake(msg)
                     stackTrace:NSStringMake(traceback)
                       userInfo:nil
                   terminateApp:quit ? YES : NO];
}

void CrashReport::setAppChannel(const char * channel)
{
    setGameType();
    [BuglyAgent setAppChannel:NSStringMake(channel)];
    LOGI("Set channel: %s", channel);
}

void CrashReport::setAppVersion(const char * version)
{
    setGameType();
    [BuglyAgent setAppVersion:NSStringMake(version)];
    LOGI("Set version: %s", version);
}

void CrashReport::log(CrashReport::CRLogLevel level, const char * tag, const char * fmts, ...)
{
    if (NULL == fmts) {
        return;
    }

    static char msg[LOG_BUFFER_SIZE];
    va_list args;
    
    va_start(args, fmts);
    int size = vsnprintf(msg, LOG_BUFFER_SIZE, fmts, args);
    va_end(args);
    
    if (size > LOG_BUFFER_SIZE) {
        LOGW("The length[%d] of string is out of the buffer size[%d]", size, LOG_BUFFER_SIZE);
    }
    
    NSInteger pLevel = (level >= 4 ? 1 : (level == 3 ? 2 : (level == 2 ? 4 : (level == 1 ? 8 : (level == 0 ? 16 : 0)))));
    [BuglyAgent level:(BALogLevel)pLevel tag:NSStringMake(tag) log:NSStringMake(msg)];
}

void CrashReport::setGameType()
{
    if (hasSetGameType) {
        return;
    }
}

void CrashReport::setCrashReporterType(int type)
{
    crashReporterType = type;
    [BuglyAgent configCrashReporterType:(CrashReporterType)type];
    LOGI("Config crash reporter type: %d", type);
}

#endif
