#import "cclua/runtime.h"
#import "cclua/runtime-private.h"
#import "cocos2d.h"

#import <sys/utsname.h>
#import <AVFoundation/AVFoundation.h>

#ifdef CCLUA_OS_IOS
#import "AppContext-ios.h"
#import <UIKit/UIKit.h>
#import <Photos/Photos.h>
#ifdef CCLUA_FEATURE_IDFA
#import <AdSupport/AdSupport.h>
#import <AppTrackingTransparency/AppTrackingTransparency.h>
#endif
#endif

USING_NS_CC;

NS_CCLUA_BEGIN

static std::string _deviceInfo;
static std::string _channel;
static std::string _audioSessionCatalog;

const std::string __runtime_getPackageName()
{
    return [[[NSBundle mainBundle] bundleIdentifier] UTF8String];
}

const std::string __runtime_getAppVersion()
{
    NSDictionary *infoDictionary = [[NSBundle mainBundle] infoDictionary];
    return [[infoDictionary objectForKey:@"CFBundleShortVersionString"] UTF8String];
}

const std::string __runtime_getAppBuild()
{
    NSDictionary *infoDictionary = [[NSBundle mainBundle] infoDictionary];
    return [[infoDictionary objectForKey:@"CFBundleVersion"] UTF8String];
}

const std::string __runtime_getChannel()
{
    if (_channel.size() == 0) {
#ifdef CCLUA_OS_IOS
        _channel = "AppStore";
#else
        _channel = "dev";
#endif
    }
    return _channel;
}

const std::string __runtime_getDeviceInfo()
{
    if (_deviceInfo.size() == 0) {
#ifdef CCLUA_OS_IOS
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

#ifdef CCLUA_OS_IOS
static PermissionStatus convertToPermissionStatus(AVAuthorizationStatus status)
{
    if (status == AVAuthorizationStatusNotDetermined) {
        return PermissionStatus::NOT_DETERMINED;
    } else if (status == AVAuthorizationStatusRestricted) {
        return PermissionStatus::RESTRICTED;
    } else if (status == AVAuthorizationStatusDenied) {
        return PermissionStatus::DENIED;
    } else {
        return PermissionStatus::AUTHORIZED;
    }
}

static PermissionStatus convertToPermissionStatus(PHAuthorizationStatus status)
{
    if (status == PHAuthorizationStatusNotDetermined) {
        return PermissionStatus::NOT_DETERMINED;
    } else if (status == PHAuthorizationStatusRestricted) {
        return PermissionStatus::RESTRICTED;
    } else if (status == PHAuthorizationStatusDenied) {
        return PermissionStatus::DENIED;
    } else {
        return PermissionStatus::AUTHORIZED;
    }
}

#ifdef CCLUA_FEATURE_IDFA
API_AVAILABLE(ios(14))
static PermissionStatus convertToPermissionStatus(ATTrackingManagerAuthorizationStatus status)
{
    if (status == ATTrackingManagerAuthorizationStatusNotDetermined) {
        return PermissionStatus::NOT_DETERMINED;
    } else if (status == ATTrackingManagerAuthorizationStatusRestricted) {
        return PermissionStatus::RESTRICTED;
    } else if (status == ATTrackingManagerAuthorizationStatusDenied) {
        return PermissionStatus::DENIED;
    } else {
        return PermissionStatus::AUTHORIZED;
    }
}
#endif

PermissionStatus __runtime_getPermissionStatus(Permission permission)
{
    if (permission == Permission::AUDIO) {
        return convertToPermissionStatus([AVCaptureDevice authorizationStatusForMediaType:AVMediaTypeAudio]);
    } else if (permission == Permission::CAMERA) {
        return convertToPermissionStatus([AVCaptureDevice authorizationStatusForMediaType:AVMediaTypeVideo]);
    } else if (permission == Permission::PHOTO) {
        return convertToPermissionStatus([PHPhotoLibrary authorizationStatus]);
    } else if (permission == Permission::IDFA) {
#ifdef CCLUA_FEATURE_IDFA
        if (@available(iOS 14_0, *)) {
            return convertToPermissionStatus([ATTrackingManager trackingAuthorizationStatus]);
        } else if ([[ASIdentifierManager sharedManager] isAdvertisingTrackingEnabled]) {
            return PermissionStatus::AUTHORIZED;
        } else {
            return PermissionStatus::RESTRICTED;
        }
#else
        return PermissionStatus::RESTRICTED;
#endif
    } else {
        return PermissionStatus::NOT_DETERMINED;
    }
}

static void requestAVCaptureDevicePermission(AVMediaType type, const std::function<void (PermissionStatus)> callback)
{
    [AVCaptureDevice requestAccessForMediaType:type completionHandler:^(BOOL granted) {
        PermissionStatus status = granted ? PermissionStatus::AUTHORIZED : PermissionStatus::DENIED;
        runtime::runOnCocosThread([callback, status](){
            callback(status);
        });
    }];
}

static void requestPHAuthorization(const std::function<void (PermissionStatus)> callback)
{
    [PHPhotoLibrary requestAuthorization:^(PHAuthorizationStatus result) {
        PermissionStatus status = convertToPermissionStatus(result);
        runtime::runOnCocosThread([callback, status](){
            callback(status);
        });
    }];
}

static void requestTrackingAuthorization(const std::function<void (PermissionStatus)> callback)
{
#ifdef CCLUA_FEATURE_IDFA
    if (@available(iOS 14_0, *)) {
        [ATTrackingManager requestTrackingAuthorizationWithCompletionHandler:^(ATTrackingManagerAuthorizationStatus result) {
            PermissionStatus status = convertToPermissionStatus(result);
            runtime::runOnCocosThread([callback, status]() {
                callback(status);
            });
        }];
    } else {
        callback(__runtime_getPermissionStatus(Permission::IDFA));
    }
#else
    callback(PermissionStatus::DENIED);
#endif
}

void __runtime_requestPermission(Permission permission, const std::function<void (PermissionStatus)> callback)
{
    if (permission == Permission::AUDIO) {
        requestAVCaptureDevicePermission(AVMediaTypeAudio, callback);
    } else if (permission == Permission::CAMERA) {
        requestAVCaptureDevicePermission(AVMediaTypeVideo, callback);
    } else if (permission == Permission::PHOTO) {
        requestPHAuthorization(callback);
    } else if (permission == Permission::IDFA) {
        requestTrackingAuthorization(callback);
    } else {
        callback(PermissionStatus::DENIED);
    }
}

void __runtime_setAudioSessionCatalog(const std::string &catalog)
{
    _audioSessionCatalog = catalog;
    BOOL status = [[AVAudioSession sharedInstance] setCategory:[NSString stringWithUTF8String:catalog.c_str()] error:nil];
    runtime::log("[%s] set session catalog: %s", status ? "OK" : "NO", catalog.c_str());
}

const std::string __runtime_getAudioSessionCatalog()
{
    return _audioSessionCatalog;
}

void __runtime_alert(const std::string title, const std::string message, const std::string ok, const std::string no, const std::function<void (bool)> callback)
{
    
    UIAlertController *alert = [UIAlertController
                                alertControllerWithTitle:[NSString stringWithUTF8String:title.c_str()]
                                message:[NSString stringWithUTF8String:message.c_str()]
                                preferredStyle:UIAlertControllerStyleAlert];
    [alert addAction:[UIAlertAction
                      actionWithTitle:[NSString stringWithUTF8String:ok.c_str()]
                      style:UIAlertActionStyleDefault
                      handler:^(UIAlertAction * _Nonnull action) {
                          runtime::runOnCocosThread([callback](){
                              callback(true);
                          });
                      }]];
    [alert addAction:[UIAlertAction
                      actionWithTitle:[NSString stringWithUTF8String:no.c_str()]
                      style:UIAlertActionStyleCancel
                      handler:^(UIAlertAction * _Nonnull action) {
                          runtime::runOnCocosThread([callback](){
                              callback(false);
                          });
                      }]];
    UIViewController *rootViewController = [[UIApplication sharedApplication] keyWindow].rootViewController;
    [rootViewController presentViewController:alert animated:YES completion:nil];
}

void __runtime_openAppSetting(const std::string &title, const std::string &message, const std::function<void()> callback)
{
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:[NSString stringWithUTF8String:title.c_str()] message:[NSString stringWithUTF8String:message.c_str()] preferredStyle:UIAlertControllerStyleAlert];
    [alert addAction:[UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
        callback();
    }]];
    [alert addAction:[UIAlertAction actionWithTitle:@"去设置" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:UIApplicationOpenSettingsURLString] options:@{@"url":@""} completionHandler: ^(BOOL success){
            // 如果在设置界面启用了权限，那么应用程序会重启
            callback();
        }];
    }]];
    UIViewController *rootViewController = [[UIApplication sharedApplication] keyWindow].rootViewController;
    [rootViewController presentViewController:alert animated:YES completion:nil];
}

#endif

void __runtime_openURL(const std::string uri, const std::function<void (bool)> callback)
{
#ifdef CCLUA_OS_IOS
    NSURL *url;
    if (strstartwith(uri.c_str(), "app-settings")) {
        url = [NSURL URLWithString:UIApplicationOpenSettingsURLString];
    } else {
        url = [NSURL URLWithString:[NSString stringWithUTF8String:uri.c_str()]];
    }
    [[UIApplication sharedApplication] openURL:url options:@{} completionHandler: ^(BOOL success){
        runtime::runOnCocosThread([callback, success](){
            if (callback != nullptr) {
                callback(success);
            }
        });
    }];
#else
    bool success = Application::getInstance()->openURL(uri);
    if (callback != nullptr) {
        callback(success);
    }
#endif
}

bool __runtime_canOpenURL(const std::string uri)
{
#ifdef CCLUA_OS_IOS
    return [[UIApplication sharedApplication] canOpenURL:[NSURL URLWithString:[NSString stringWithUTF8String:uri.c_str()]]];
#else
    return true;
#endif
}

uint32_t __runtime_getMaxFrameRate()
{
#ifdef CCLUA_OS_IOS
    return (uint32_t)[UIScreen mainScreen].maximumFramesPerSecond;
#else
    return 60;
#endif
}

const std::string __runtime_getLanguage()
{
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    NSArray *languages = [defaults objectForKey:@"AppleLanguages"];
    NSString *currentLanguage = [languages objectAtIndex:0];
    return [currentLanguage UTF8String];
}

const std::string __runtime_getNetworkStatus()
{
#ifdef CCLUA_OS_IOS
    AppContext *context = (AppContext *)[UIApplication sharedApplication].delegate;
    return [[context getNetworkStatus] UTF8String];
#else
    return "WIFI";
#endif
}

const std::string __runtime_getPaste()
{
#ifdef CCLUA_OS_IOS
    @autoreleasepool {
        UIPasteboard *pasteboard = [UIPasteboard generalPasteboard];
        NSString *string = pasteboard.string;
        return string ? [string UTF8String] : "";
    }
#else
    return "";
#endif
}

void __runtime_setPaste(const std::string &text)
{
#ifdef CCLUA_OS_IOS
    @autoreleasepool {
        UIPasteboard *pasteboard = [UIPasteboard generalPasteboard];
        pasteboard.string = [NSString stringWithUTF8String:text.c_str()];
    }
#endif
}

NS_CCLUA_END
