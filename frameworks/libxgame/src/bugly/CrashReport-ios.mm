#import "CrashReport.h"

#import "cocos2d.h"
#import <string.h>

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

#define LOG_TAG "CrashReport"
#define LOG_BUFFER_SIZE 1024

#ifndef GAME_TYPE_COCOS
#define GAME_TYPE_COCOS 1
#endif

#import <Foundation/Foundation.h>
#import "Bugly.h"

#define NSStringMake(const_char_pointer) (const_char_pointer == NULL ? nil : @(const_char_pointer))
#define NSStringMakeNonnull(const_char_pointer) (const_char_pointer == NULL ? @"" : @(const_char_pointer))

#define LOGD(fmt, args...) CCLOG("[Debug] %s: " fmt, LOG_TAG, ##args)
#define LOGI(fmt, args...) CCLOG("[Info] %s: " fmt, LOG_TAG, ##args)
#define LOGW(fmt, args...) CCLOGERROR("[Warn] %s: " fmt, LOG_TAG, ##args)
#define LOGE(fmt, args...) CCLOGERROR("[Error] %s: " fmt, LOG_TAG, ##args)

const char *_channel = nullptr;
const char *_version = nullptr;

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
int CrashReport::crashReporterType = 0;

void CrashReport::initCrashReport(const char* appId, bool isDebug, CrashReport::CRLogLevel level)
{
    if (!initialized) {
        LOGI("Init the sdk with App ID: %s", appId);
        BuglyConfig *config = [[BuglyConfig alloc] init];
        config.channel = NSStringMake(_channel);
        config.version = NSStringMake(_version);
        config.reportLogLevel = BuglyLogLevelVerbose;
        [Bugly startWithAppId:NSStringMake(appId) developmentDevice:isDebug config:config];
        initialized = true;
    }
}

void CrashReport::setTag(int tag)
{
    if (tag < 0) {
        return;
    }
    [Bugly setTag:tag];
    LOGI("Set user scene tag id: %d", tag);
}

void CrashReport::addUserValue(const char* key, const char* value)
{
    LOGI("Set user Key-Value: [%s, %s]", key, value);
    [Bugly setUserValue:NSStringMakeNonnull(value) forKey:NSStringMakeNonnull(key)];
}

void CrashReport::removeUserValue(const char* key)
{
    //[BuglyAgent removeSceneValueForKey:NSStringMakeNonnull(key)];
}

void CrashReport::setUserId(const char* userId)
{
    [Bugly setUserIdentifier:NSStringMake(userId)];
    LOGI("Set user id: %s", userId);
}

void CrashReport::reportException(int category, const char* type, const char* msg, const char* traceback)
{
    reportException(category, type, msg, traceback, false);
}

void CrashReport::reportException(int category, const char* type, const char* msg, const char* traceback, bool quit)
{
    [Bugly reportExceptionWithCategory:category
                                  name:NSStringMake(type)
                                reason:NSStringMake(msg)
                             callStack:[NSArray arrayWithObjects:NSStringMake(traceback), nil]
                             extraInfo:@{}
                          terminateApp:quit ? YES : NO];
}

void CrashReport::setAppChannel(const char *channel)
{
    _channel = channel;
    LOGI("Set channel: %s", channel);
}

void CrashReport::setAppVersion(const char *version)
{
    _version = version;
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
    
    [BuglyLog level:(BuglyLogLevel)level tag:NSStringMake(tag) log:@"%s", msg];
}

void CrashReport::setGameType()
{
}

void CrashReport::setCrashReporterType(int type)
{
    crashReporterType = type;
    LOGI("Config crash reporter type: %d", type);
}

#endif
