#import "cclua/runtime.h"
#import "cclua/runtime-private.h"
#import "cclua/permission.h"
#import "cocos2d.h"

#import <sys/utsname.h>
#import <AVFoundation/AVFoundation.h>

#ifdef CCLUA_OS_IOS
#import "AppContext-ios.h"
#import <UIKit/UIKit.h>
#import <Photos/Photos.h>
#ifdef CCLUA_FEATURE_TRACKING
#import <AdSupport/AdSupport.h>
#import <AppTrackingTransparency/AppTrackingTransparency.h>
#endif
#endif

USING_NS_CC;

NS_CCLUA_BEGIN

static std::string _deviceInfo;
static std::string _channel;
static std::string _audioSessionCatalog;

std::string __runtime_getPackageName()
{
    return [[[NSBundle mainBundle] bundleIdentifier] UTF8String];
}

std::string __runtime_getAppName()
{
    return [[[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleDisplayName"] UTF8String];
}

std::string __runtime_getAppVersion()
{
    NSDictionary *infoDictionary = [[NSBundle mainBundle] infoDictionary];
    return [[infoDictionary objectForKey:@"CFBundleShortVersionString"] UTF8String];
}

std::string __runtime_getAppBuild()
{
    NSDictionary *infoDictionary = [[NSBundle mainBundle] infoDictionary];
    return [[infoDictionary objectForKey:@"CFBundleVersion"] UTF8String];
}

std::string __runtime_getChannel()
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

std::string __runtime_getDeviceInfo()
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
static std::string convertToPermissionStatus(AVAuthorizationStatus status)
{
    switch (status) {
        case AVAuthorizationStatusNotDetermined:
            return permission::status::NOT_DETERMINED;
        case AVAuthorizationStatusRestricted:
            return permission::status::RESTRICTED;
        case AVAuthorizationStatusDenied:
            return permission::status::DENIED;
        case AVAuthorizationStatusAuthorized:
            return permission::status::AUTHORIZED;
    }
    return permission::status::UNKNOWN;
}

static std::string convertToPermissionStatus(PHAuthorizationStatus status)
{
    switch (status) {
        case PHAuthorizationStatusNotDetermined:
            return permission::status::NOT_DETERMINED;
        case PHAuthorizationStatusRestricted:
            return permission::status::RESTRICTED;
        case PHAuthorizationStatusDenied:
            return permission::status::DENIED;
        case PHAuthorizationStatusAuthorized:
            return permission::status::AUTHORIZED;
        case PHAuthorizationStatusLimited:
            return permission::status::LIMITED;
    }
    return permission::status::UNKNOWN;
}

#ifdef CCLUA_FEATURE_TRACKING
API_AVAILABLE(ios(14))
static std::string convertToPermissionStatus(ATTrackingManagerAuthorizationStatus status)
{
    switch (status) {
        case ATTrackingManagerAuthorizationStatusNotDetermined:
            return permission::status::NOT_DETERMINED;
        case ATTrackingManagerAuthorizationStatusRestricted:
            return permission::status::RESTRICTED;
        case ATTrackingManagerAuthorizationStatusDenied:
            return permission::status::DENIED;
        case ATTrackingManagerAuthorizationStatusAuthorized:
            return permission::status::AUTHORIZED;
    }
    return permission::status::UNKNOWN;
}
#endif

std::string __runtime_getPermission(const std::string &permission)
{
    if (permission == permission::MICROPHONE) {
        return convertToPermissionStatus([AVCaptureDevice authorizationStatusForMediaType:AVMediaTypeAudio]);
    } else if (permission == permission::CAMERA) {
        return convertToPermissionStatus([AVCaptureDevice authorizationStatusForMediaType:AVMediaTypeVideo]);
    } else if (permission == permission::PHOTO) {
        return convertToPermissionStatus([PHPhotoLibrary authorizationStatus]);
    } else if (permission == permission::TRACKING) {
#ifdef CCLUA_FEATURE_TRACKING
        if (@available(iOS 14_0, *)) {
            return convertToPermissionStatus([ATTrackingManager trackingAuthorizationStatus]);
        } else if ([[ASIdentifierManager sharedManager] isAdvertisingTrackingEnabled]) {
            return permission::status::AUTHORIZED;
        } else {
            return permission::status::RESTRICTED;
        }
#else
        return permission::status::RESTRICTED;
#endif
    } else {
        return permission::status::NOT_DETERMINED;
    }
}

static void requestAVCaptureDevicePermission(AVMediaType type, const std::function<void (const std::string &)> callback)
{
    [AVCaptureDevice requestAccessForMediaType:type completionHandler:^(BOOL granted) {
        std::string status = granted ? permission::status::AUTHORIZED : permission::status::DENIED;
        runtime::runLater([callback, status](){
            callback(status);
        });
    }];
}

static void requestPHAuthorization(const std::function<void (const std::string &)> callback)
{
    [PHPhotoLibrary requestAuthorization:^(PHAuthorizationStatus result) {
        std::string status = convertToPermissionStatus(result);
        runtime::runLater([callback, status](){
            callback(status);
        });
    }];
}

static void requestTrackingAuthorization(const std::function<void (const std::string &)> callback)
{
#ifdef CCLUA_FEATURE_TRACKING
    if (@available(iOS 14_0, *)) {
        [ATTrackingManager requestTrackingAuthorizationWithCompletionHandler:^(ATTrackingManagerAuthorizationStatus result) {
            std::string status = convertToPermissionStatus(result);
            runtime::runLater([callback, status]() {
                callback(status);
            });
        }];
    } else {
        callback(__runtime_getPermission(permission::TRACKING));
    }
#else
    callback(permission::status::DENIED);
#endif
}

void __runtime_requestPermission(const std::string &permission, const std::function<void (const std::string &)> callback)
{
    if (permission == permission::MICROPHONE) {
        requestAVCaptureDevicePermission(AVMediaTypeAudio, callback);
    } else if (permission == permission::CAMERA) {
        requestAVCaptureDevicePermission(AVMediaTypeVideo, callback);
    } else if (permission == permission::PHOTO) {
        requestPHAuthorization(callback);
    } else if (permission == permission::TRACKING) {
        requestTrackingAuthorization(callback);
    } else {
        runtime::log("request permission not available: %s");
        callback(permission::status::DENIED);
    }
}

void __runtime_setAudioSessionCatalog(const std::string &catalog)
{
    _audioSessionCatalog = catalog;
    BOOL status = [[AVAudioSession sharedInstance] setCategory:[NSString stringWithUTF8String:catalog.c_str()] error:nil];
    runtime::log("[%s] set session catalog: %s", status ? "OK" : "NO", catalog.c_str());
}

std::string __runtime_getAudioSessionCatalog()
{
    return _audioSessionCatalog;
}

void __runtime_alert(const std::string &title, const std::string &message, const std::string &ok, const std::string &no, const std::function<void (bool)> callback)
{
    
    UIAlertController *alert = [UIAlertController
                                alertControllerWithTitle:[NSString stringWithUTF8String:title.c_str()]
                                message:[NSString stringWithUTF8String:message.c_str()]
                                preferredStyle:UIAlertControllerStyleAlert];
    [alert addAction:[UIAlertAction
                      actionWithTitle:[NSString stringWithUTF8String:ok.c_str()]
                      style:UIAlertActionStyleDefault
                      handler:^(UIAlertAction * _Nonnull action) {
                          runtime::runLater([callback](){
                              callback(true);
                          });
                      }]];
    [alert addAction:[UIAlertAction
                      actionWithTitle:[NSString stringWithUTF8String:no.c_str()]
                      style:UIAlertActionStyleCancel
                      handler:^(UIAlertAction * _Nonnull action) {
                          runtime::runLater([callback](){
                              callback(false);
                          });
                      }]];
    UIViewController *rootViewController = [[UIApplication sharedApplication] keyWindow].rootViewController;
    [rootViewController presentViewController:alert animated:YES completion:nil];
}
#endif

void __runtime_openURL(const std::string &uri, const std::function<void (bool)> callback)
{
#ifdef CCLUA_OS_IOS
    NSURL *url;
    if (strstartwith(uri.c_str(), "app-settings")) {
        url = [NSURL URLWithString:UIApplicationOpenSettingsURLString];
    } else {
        url = [NSURL URLWithString:[NSString stringWithUTF8String:uri.c_str()]];
    }
    [[UIApplication sharedApplication] openURL:url options:@{} completionHandler: ^(BOOL success){
        runtime::runLater([callback, success](){
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

bool __runtime_canOpenURL(const std::string &uri)
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

std::string __runtime_getLanguage()
{
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    NSArray *languages = [defaults objectForKey:@"AppleLanguages"];
    NSString *currentLanguage = [languages objectAtIndex:0];
    return [currentLanguage UTF8String];
}

std::string __runtime_getNetworkStatus()
{
#ifdef CCLUA_OS_IOS
    AppContext *context = (AppContext *)[UIApplication sharedApplication].delegate;
    return [[context getNetworkStatus] UTF8String];
#else
    return "WIFI";
#endif
}

std::string __runtime_getPaste()
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
