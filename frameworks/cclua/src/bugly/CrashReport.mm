#import "CrashReport.h"

#import "cocos2d.h"
#import <string.h>

#ifdef CCLUA_OS_IOS

#import <Foundation/Foundation.h>
#import <Bugly/Bugly.h>

NS_CCLUA_BEGIN

#define NSStringMake(str) (str == NULL ? nil : @(str))
#define NSStringMakeNonnull(str) (str == NULL ? @"" : @(str))

static std::string s_channel;
static std::string s_version;
static bool s_initialized = false;

void bugly::init(const char *appid)
{
    @autoreleasepool {
        if (!s_initialized) {
            runtime::log("init bugly: appid=%s", appid);
            BuglyConfig *config = [[BuglyConfig alloc] init];
            config.channel = NSStringMake(s_channel.c_str());
            config.version = NSStringMake(s_version.c_str());
            config.reportLogLevel = BuglyLogLevelVerbose;
            [Bugly startWithAppId:NSStringMake(appid) developmentDevice:NO config:config];
            s_initialized = true;
        }
    }
}

void bugly::setTag(int tag)
{
    @autoreleasepool {
        if (tag < 0) {
            return;
        }
        [Bugly setTag:tag];
    }
}

void bugly::setUserValue(const char *key, const char *value)
{
    @autoreleasepool {
        [Bugly setUserValue:NSStringMakeNonnull(value) forKey:NSStringMakeNonnull(key)];
    }
}

void bugly::setUid(const char *uid)
{
    @autoreleasepool {
        [Bugly setUserIdentifier:NSStringMake(uid)];
    }
}

void bugly::reportException(const char *msg, const char *traceback)
{
    @autoreleasepool {
        [Bugly reportExceptionWithCategory:6
                                         name:@""
                                       reason:NSStringMake(msg)
                                    callStack:[NSArray arrayWithObjects:NSStringMake(traceback), nil]
                                    extraInfo:@{}
                                 terminateApp:NO];
    }
}

void bugly::setChannel(const char *channel)
{
    s_channel = channel;
}

void bugly::setVersion(const char *version)
{
    s_version = version;
}

void bugly::log(LogLevel level, const char *msg)
{
    @autoreleasepool {
        if (!msg) {
            return;
        }
        [BuglyLog level:(BuglyLogLevel)level tag:@"bugly" log:@"%s", msg];
    }
}

NS_CCLUA_END

#endif
