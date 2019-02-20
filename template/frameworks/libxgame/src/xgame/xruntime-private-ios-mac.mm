#import "xgame/xruntime.h"
#import "xgame/xruntime-private.h"
#import "cocos2d.h"

#import <sys/utsname.h>
#import <AVFoundation/AVFoundation.h>

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#import <UIKit/UIKit.h>
#endif

USING_NS_CC;
USING_NS_XGAME;

static std::string _deviceInfo;
static std::string _channel;

const std::string __runtime_getPackageName()
{
    return [[[NSBundle mainBundle] bundleIdentifier] UTF8String];
}

const std::string __runtime_getVersion()
{
    NSDictionary *infoDictionary = [[NSBundle mainBundle] infoDictionary];
    return [[infoDictionary objectForKey:@"CFBundleShortVersionString"] UTF8String];
}

const std::string __runtime_getVersionCode()
{
    NSDictionary *infoDictionary = [[NSBundle mainBundle] infoDictionary];
    return [[infoDictionary objectForKey:@"CFBundleVersion"] UTF8String];
}

const std::string __runtime_getChannel()
{
    if (_channel.size() == 0) {
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
        _channel = "AppStore";
#else
        _channel = "dev";
#endif
    }
    return _channel;
}

const std::string __runtime_getDeviceInfo()
{
    if (_deviceInfo.size() == 0)
    {
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
        struct utsname systemInfo;
        uname(&systemInfo);
        _deviceInfo.append([[NSString stringWithCString:systemInfo.machine encoding:NSASCIIStringEncoding] UTF8String]);
        _deviceInfo.append(", ");
        _deviceInfo.append([[[UIDevice currentDevice] systemName] UTF8String]);
        _deviceInfo.append(" ");
        _deviceInfo.append([[[UIDevice currentDevice] systemVersion] UTF8String]);
#else
        _deviceInfo = runtime::getOS();
#endif
    }
    return _deviceInfo;
}
