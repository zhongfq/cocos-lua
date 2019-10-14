#import "xruntime.h"
#import "xruntime-private.h"
#import "AppContext-ios.h"
#import "cocos2d.h"

#import <sys/utsname.h>
#import <AVFoundation/AVFoundation.h>

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#import <UIKit/UIKit.h>
#import <Photos/Photos.h>
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
    if (_deviceInfo.size() == 0) {
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

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
PermissionStatus getAVCaptureDevicePermissionStatus(AVMediaType type)
{
    AVAuthorizationStatus status = [AVCaptureDevice authorizationStatusForMediaType:type];
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

static PermissionStatus getPHAuthorizationStatus()
{
    PHAuthorizationStatus status = [PHPhotoLibrary authorizationStatus];
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

PermissionStatus __runtime_getPermissionStatus(Permission permission)
{
    if (permission == Permission::AUDIO) {
        return getAVCaptureDevicePermissionStatus(AVMediaTypeAudio);
    } else if (permission == Permission::CAMERA) {
        return getAVCaptureDevicePermissionStatus(AVMediaTypeVideo);
    } else if (permission == Permission::PHOTO) {
        return getPHAuthorizationStatus();
    } else {
        return PermissionStatus::NOT_DETERMINED;
    }
}

static void requestAVCaptureDevicePermission(AVMediaType type, const std::function<void (PermissionStatus)> callback)
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [AVCaptureDevice requestAccessForMediaType:type completionHandler:^(BOOL granted) {
            PermissionStatus status = granted ? PermissionStatus::AUTHORIZED : PermissionStatus::DENIED;
            runtime::runOnCocosThread([callback, status](){
                callback(status);
            });
        }];
    });
}

static void requestPHAuthorization(const std::function<void (PermissionStatus)> callback)
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [PHPhotoLibrary requestAuthorization:^(PHAuthorizationStatus status) {
            runtime::runOnCocosThread([callback, status](){
                if (status == PHAuthorizationStatusNotDetermined) {
                    callback(PermissionStatus::NOT_DETERMINED);
                } else if (status == PHAuthorizationStatusRestricted) {
                    callback(PermissionStatus::RESTRICTED);
                } else if (status == PHAuthorizationStatusDenied) {
                    callback(PermissionStatus::DENIED);
                } else {
                    callback(PermissionStatus::AUTHORIZED);
                }
            });
        }];
    });
}

void __runtime_requestPermission(Permission permission, const std::function<void (PermissionStatus)> callback)
{
    if (permission == Permission::AUDIO) {
        requestAVCaptureDevicePermission(AVMediaTypeAudio, callback);
    } else if (permission == Permission::CAMERA) {
        requestAVCaptureDevicePermission(AVMediaTypeVideo, callback);
    } else if (permission == Permission::PHOTO) {
        requestPHAuthorization(callback);
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
    dispatch_async(dispatch_get_main_queue(), ^{
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
    });
}
#endif

void __runtime_openURL(const std::string uri, const std::function<void (bool)> callback)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    dispatch_async(dispatch_get_main_queue(), ^{
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
    });
#else
    callback(Application::getInstance()->openURL(uri));
#endif
}

bool __runtime_canOpenURL(const std::string uri)
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

const std::string __runtime_getNetworkStatus()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    AppContext *context = (AppContext *)[UIApplication sharedApplication].delegate;
    return [[context getNetworkStatus] UTF8String];
#else
    return "WIFI";
#endif
}
