#import "lua_photo.h"
#import "xgame/PluginConnector.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

#import <AssetsLibrary/AssetsLibrary.h>
#import <AVFoundation/AVFoundation.h>
#import <Photos/Photos.h>
#import <UIKit/UIKit.h>

static UIImage *image_resize_to(UIImage *image, int width, int height)
{
    UIGraphicsBeginImageContext(CGSizeMake(width, height));
    [image drawInRect:CGRectMake(0, 0, width, height)];
    UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return newImage;
}


typedef enum {
    kCameraRollModeAvatar,
    kCameraRollModeImage,
} CameraRollMode;

@interface PhotoConnector : PluginConnector<UIImagePickerControllerDelegate, UINavigationControllerDelegate>
@property(readwrite, strong, nonatomic) UIImagePickerController *imagePicker;
@property(readwrite, strong, nonatomic) NSString *cachePath;
@property(readwrite, assign, nonatomic) CGSize size;
@property(readwrite, assign, nonatomic) float quality;
@property(readwrite, assign, nonatomic) CameraRollMode mode;

- (instancetype)init;
- (void)openSelector;
- (void)selectImage:(NSString *)cachePath;
- (void)selectAvatarFromCamera:(NSString *)cachePath withSize:(CGSize)size;
- (void)selectAvatarFromPhotoLibrary:(NSString *)cachePath withSize:(CGSize)size;
- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary<NSString *,id> *)info;
- (void)imagePickerControllerDidCancel:(UIImagePickerController *)picker;

@end

@implementation PhotoConnector

- (instancetype)init
{
    self.imagePicker = [[UIImagePickerController alloc] init];
    self.imagePicker.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
    self.imagePicker.delegate = self;
    self.quality = 0.85f;
    
    return [super init];
}

- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary<NSString *,id> *)info
{
    @autoreleasepool {
        [self.imagePicker dismissViewControllerAnimated:YES completion:nil];
        NSString *type = [info objectForKey:UIImagePickerControllerMediaType];
        if ([type isEqualToString:@"public.image"])
        {
            UIImage *image = nil;
            bool ok = NO;
            if (self.mode == kCameraRollModeAvatar)
            {
                image = image_resize_to([info objectForKey:UIImagePickerControllerEditedImage], self.size.width, self.size.height);
            }
            else
            {
                image = [info objectForKey:UIImagePickerControllerOriginalImage];
            }
            
            if (image) {
                if (strendwith([self.cachePath UTF8String], ".png")) {
                    ok = [UIImagePNGRepresentation(image) writeToFile:self.cachePath atomically:YES];
                } else {
                    ok = [UIImageJPEGRepresentation(image, self.quality) writeToFile:self.cachePath atomically:YES];
                }
            }
            
            [self dispatch:@"selectImage" withMessage: ok ? @"complete" : @"ioerror"];
        }
        else
        {
            [self dispatch:@"selectImage" withMessage:@"typeerror"];
        }
    }
}

- (void)imagePickerControllerDidCancel:(UIImagePickerController *)picker
{
    @autoreleasepool {
        [self.imagePicker dismissViewControllerAnimated:YES completion:nil];
        [self dispatch:@"selectImage" withMessage:@"cancel"];
    }
}

- (void)openSelector
{
    dispatch_async(dispatch_get_main_queue(), ^{
        if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad) {
            UIViewController *rootViewController = [[UIApplication sharedApplication] keyWindow].rootViewController;
            self.imagePicker.modalPresentationStyle = UIModalPresentationPopover;
            UIPopoverPresentationController *popPC = self.imagePicker.popoverPresentationController;
            popPC.sourceView = rootViewController.view;
            popPC.sourceRect = self.imagePicker.view.bounds;
            popPC.permittedArrowDirections = 0;
            [rootViewController presentViewController:self.imagePicker animated:YES completion:nil];
            
        } else {
            UIViewController *rootViewController = [[UIApplication sharedApplication] keyWindow].rootViewController;
            [rootViewController presentViewController:self.imagePicker animated:YES completion:nil];
        }
    });
}

- (void)selectImage:(NSString *)cachePath
{
    self.imagePicker.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
    self.imagePicker.allowsEditing = false;
    self.mode = kCameraRollModeImage;
    self.cachePath = cachePath;
    [self openSelector];
}

- (void)selectAvatarFromCamera:(NSString *)cachePath withSize:(CGSize)size
{
    self.imagePicker.sourceType = UIImagePickerControllerSourceTypeCamera;
    self.imagePicker.allowsEditing = true;
    self.mode = kCameraRollModeAvatar;
    self.cachePath = cachePath;
    self.size = size;
    [self openSelector];
}

- (void)selectAvatarFromPhotoLibrary:(NSString *)cachePath withSize:(CGSize)size
{
    self.imagePicker.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
    self.imagePicker.allowsEditing = true;
    self.mode = kCameraRollModeAvatar;
    self.cachePath = cachePath;
    self.size = size;
    [self openSelector];
}

@end

#define CLASS_CONNECTOR "PhotoConnector*"
#define olua_checkconnector(L, i) ((__bridge PhotoConnector *)olua_checkobj(L, i, CLASS_CONNECTOR))
#define NSStringMake(str) (str == NULL ? nil : @(str))

static int _gc(lua_State *L)
{
    @autoreleasepool {
        PhotoConnector *connector = olua_checkconnector(L, 1);
        CFBridgingRelease((__bridge CFTypeRef)connector);
    }
    return 0;
}

static int _set_callback(lua_State *L)
{
    @autoreleasepool {
        lua_settop(L, 2);
        PhotoConnector *connector = olua_checkconnector(L, 1);
        void *cb_store = (__bridge void *)connector;
        std::string func = olua_setcallback(L, cb_store, "dispatcher", 2, OLUA_TAG_REPLACE);
        lua_Unsigned ctx = olua_context(L);
        connector.dispatcher = [cb_store, func, ctx] (const std::string &event, const std::string &data) {
            lua_State *L = olua_mainthread(NULL);
            if (L != NULL && (olua_context(L) == ctx)) {
                int top = lua_gettop(L);
                lua_pushstring(L, event.c_str());
                lua_pushstring(L, data.c_str());
                olua_callback(L, cb_store, func.c_str(), 2);
                lua_settop(L, top);
            }
        };
    }
    return 0;
}

static void did_request_permission(int handler, bool granted)
{
    xgame::runtime::runOnCocosThread([handler, granted]() {
        lua_State *L = olua_mainthread(NULL);
        int top = lua_gettop(L);
        lua_pushcfunction(L, olua_geterrorfunc);
        olua_getref(L, handler);
        if (lua_isfunction(L, -1)) {
            lua_pushboolean(L, granted);
            lua_pcall(L, 1, 0, top + 1);
            olua_unref(L, handler);
        }
        lua_settop(L, top);
    });
}

static void request_photolibray_permission(lua_State *L)
{
    int handler = olua_reffunc(L, 3);
    PHAuthorizationStatus current_status = [PHPhotoLibrary authorizationStatus];
    [PHPhotoLibrary requestAuthorization:^(PHAuthorizationStatus status) {
        if (current_status == PHAuthorizationStatusDenied || status == PHAuthorizationStatusRestricted)
        {
            dispatch_async(dispatch_get_main_queue(), ^{
                NSString *appName = [[[NSBundle mainBundle]infoDictionary] objectForKey:@"CFBundleDisplayName"];
                NSString *title = @"没有权限访问您的照片";
                NSString *message = [NSString stringWithFormat:@"请在iPhone的”设置-隐私-照片“选项中，允许%@访问您的照片", appName];
                UIAlertController *alert = [UIAlertController alertControllerWithTitle:title message:message preferredStyle:UIAlertControllerStyleAlert];
                [alert addAction:[UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
                    did_request_permission(handler, false);
                }]];
                [alert addAction:[UIAlertAction actionWithTitle:@"去设置" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
                    if (@available(iOS 10_0, *)) {
                        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:UIApplicationOpenSettingsURLString] options:@{@"url":@""} completionHandler: ^(BOOL success){
                            // 如果在设置界面启用了权限，那么应用程序会重启
                            did_request_permission(handler, false);
                        }];
                    } else {
                        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:UIApplicationOpenSettingsURLString]];
                    }
                }]];
                UIViewController *rootViewController = [[UIApplication sharedApplication] keyWindow].rootViewController;
                [rootViewController presentViewController:alert animated:YES completion:nil];
            });
        }
        else
        {
            did_request_permission(handler, status == PHAuthorizationStatusAuthorized);
        }
    }];
}

static void request_camera_permission(lua_State *L)
{
    int handler = olua_reffunc(L, 3);
    AVAuthorizationStatus status = [AVCaptureDevice authorizationStatusForMediaType:AVMediaTypeVideo];
    [AVCaptureDevice requestAccessForMediaType:AVMediaTypeVideo completionHandler:^(BOOL granted) {
        if (granted || status != AVAuthorizationStatusDenied)
        {
            did_request_permission(handler, granted);
        }
        else
        {
            dispatch_async(dispatch_get_main_queue(), ^{
                NSString *appName = [[[NSBundle mainBundle]infoDictionary] objectForKey:@"CFBundleDisplayName"];
                NSString *title = @"没有权限访问您的相机";
                NSString *message = [NSString stringWithFormat:@"请在iPhone的”设置-隐私-相机“选项中，允许%@访问您的相机", appName];
                UIAlertController *alert = [UIAlertController alertControllerWithTitle:title message:message preferredStyle:UIAlertControllerStyleAlert];
                [alert addAction:[UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
                    did_request_permission(handler, granted);
                }]];
                [alert addAction:[UIAlertAction actionWithTitle:@"去设置" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
                    if (@available(iOS 10_0, *)) {
                        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:UIApplicationOpenSettingsURLString] options:@{@"url":@""} completionHandler: ^(BOOL success){
                            // 如果在设置界面启用了权限，那么应用程序会重启
                            did_request_permission(handler, granted);
                        }];
                    } else {
                        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:UIApplicationOpenSettingsURLString]];
                    }
                }]];
                UIViewController *rootViewController = [[UIApplication sharedApplication] keyWindow].rootViewController;
                [rootViewController presentViewController:alert animated:YES completion:nil];
            });
        }
    }];
}

static int _request_permission(lua_State *L)
{
    @autoreleasepool {
        lua_settop(L, 3);
        const char *type = luaL_checkstring(L, 2);
        if (strequal(type, "PHOTO")) {
            request_photolibray_permission(L);
        } else {
            request_camera_permission(L);
        }
    }
    return 0;
}

static int _select_image(lua_State *L)
{
    @autoreleasepool {
        lua_settop(L, 3);
        PhotoConnector *connector = olua_checkconnector(L, 1);
        connector.quality = olua_optnumber(L, 3, 0.85f);
        [connector selectImage:[NSString stringWithUTF8String:luaL_checkstring(L, 2)]];
    }
    return 0;
}

static int _select_avatar(lua_State *L)
{
    @autoreleasepool {
        lua_settop(L, 6);
        PhotoConnector *connector = olua_checkconnector(L, 1);
        NSString *cachePath = [NSString stringWithUTF8String:luaL_checkstring(L, 2)];
        CGSize size = CGSizeMake((int)luaL_checkinteger(L, 3), (int)luaL_checkinteger(L, 4));
        connector.quality = olua_optnumber(L, 5, 0.85f);
        [connector selectAvatarFromPhotoLibrary:cachePath withSize:size];

    }
    return 0;
}

static int _take_avatar(lua_State *L)
{
    @autoreleasepool {
        lua_settop(L, 6);
        PhotoConnector *connector = olua_checkconnector(L, 1);
        NSString *cachePath = [NSString stringWithUTF8String:luaL_checkstring(L, 2)];
        CGSize size = CGSizeMake((int)luaL_checkinteger(L, 3), (int)luaL_checkinteger(L, 4));
        connector.quality = olua_optnumber(L, 5, 0.85f);
        [connector selectAvatarFromCamera:cachePath withSize:size];
    }
    return 0;
}

int luaopen_photo(lua_State *L)
{
    oluacls_class(L, CLASS_CONNECTOR, nullptr);
    oluacls_func(L, "gc", _gc);
    oluacls_func(L, "setDispatcher", _set_callback);
    oluacls_func(L, "requestPermission", _request_permission);
    oluacls_func(L, "selectAvatar", _select_avatar);
    oluacls_func(L, "takeAvatar", _take_avatar);
    oluacls_func(L, "select", _select_image);
    
    xgame::runtime::registerFeature("photo.ios", true);
    
    @autoreleasepool {
        PhotoConnector *connector = [PhotoConnector new];
        olua_push_obj(L, (void *)CFBridgingRetain(connector), CLASS_CONNECTOR);
    }
    
    return 1;
}

#endif
