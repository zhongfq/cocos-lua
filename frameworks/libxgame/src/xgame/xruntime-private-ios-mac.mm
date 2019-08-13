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
static std::string _audioSessionCatalog;

const std::string __runtime_getPackageName()
{
    return [[[NSBundle mainBundle] bundleIdentifier] UTF8String];
}

const std::string __runtime_getVersion()
{
    NSDictionary *infoDictionary = [[NSBundle mainBundle] infoDictionary];
    return [[infoDictionary objectForKey:@"CFBundleShortVersionString"] UTF8String];
}

const std::string __runtime_getVersionBuild()
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

void __runtime_openURL(const std::string &uri, const std::function<void (bool)> callback)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    NSURL *url;
    if (strstartwith(uri.c_str(), "app-settings")) {
        url = [NSURL URLWithString:UIApplicationOpenSettingsURLString];
    } else {
        url = [NSURL URLWithString:[NSString stringWithUTF8String:uri.c_str()]];
    }
    if (@available(iOS 10_0, *)) {
        [[UIApplication sharedApplication] openURL:url options:@{} completionHandler: ^(BOOL success){
            runtime::runOnCocosThread([callback, success](){
                callback(success);
            });
        }];
    } else {
        bool success = [[UIApplication sharedApplication] openURL:url];
        callback(success);
    }
#else
    callback(Application::getInstance()->openURL(uri));
#endif
}

bool __runtime_canOpenURL(const std::string &uri)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    return [[UIApplication sharedApplication] canOpenURL:[NSURL URLWithString:[NSString stringWithUTF8String:uri.c_str()]]];
#else
    return true;
#endif
}

const std::string __runtime_getLanguage()
{
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    NSArray *languages = [defaults objectForKey:@"AppleLanguages"];
    NSString *currentLanguage = [languages objectAtIndex:0];
    return [currentLanguage UTF8String];
}


void __runtime_setAudioSessionCatalog(const std::string &catalog)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    _audioSessionCatalog = catalog;
    BOOL status = [[AVAudioSession sharedInstance] setCategory:[NSString stringWithUTF8String:catalog.c_str()] error:nil];
    runtime::log("[%s] set session catalog: %s", status ? "OK" : "NO", catalog.c_str());
#endif
}

const std::string __runtime_getAudioSessionCatalog()
{
    return _audioSessionCatalog;
}
