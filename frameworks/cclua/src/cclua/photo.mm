#import "photo.h"
#import "cclua/plugin-ios.h"
#import "cclua/filesystem.h"

#if defined(CCLUA_OS_IOS)

#import <AssetsLibrary/AssetsLibrary.h>
#import <AVFoundation/AVFoundation.h>
#import <Photos/Photos.h>
#import <UIKit/UIKit.h>

USING_NS_CCLUA;
USING_NS_CCLUA_PLUGIN;

Callback photo::_dispatcher;

static UIImage *resizeImage(UIImage *image, int width, int height)
{
    CGSize size = image.size;
    CGFloat scale = std::max(width / size.width, height / size.height);
    size.width *= scale;
    size.height *= scale;
    UIGraphicsBeginImageContext(size);
    [image drawInRect:CGRectMake(0, 0, size.width, size.height)];
    image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    CGImageRef sourceImageRef = [image CGImage];
    CGRect rect = CGRectMake((size.width - width) / 2, (size.height - height) / 2, width, height);
    CGImageRef newImageRef = CGImageCreateWithImageInRect(sourceImageRef, rect);
    return [UIImage imageWithCGImage:newImageRef];
}


typedef enum {
    kCameraRollModeAvatar,
    kCameraRollModeImage,
} CameraRollMode;

@interface PhotoDelegate : NSObject<UIImagePickerControllerDelegate, UINavigationControllerDelegate>
@property(readwrite, strong, nonatomic) UIImagePickerController *imagePicker;
@property(readwrite, strong, nonatomic) NSString *cachePath;
@property(readwrite, assign, nonatomic) CGSize size;
@property(readwrite, assign, nonatomic) CameraRollMode mode;
@property std::string event;

+ (instancetype)defaultDelegate;

- (instancetype)init;
- (void)openSelector;
- (void)selectImage:(NSString *)cachePath;
- (void)selectAvatarFromCamera:(NSString *)cachePath withSize:(CGSize)size;
- (void)selectAvatarFromPhotoLibrary:(NSString *)cachePath withSize:(CGSize)size;
- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary<NSString *,id> *)info;
- (void)imagePickerControllerDidCancel:(UIImagePickerController *)picker;

@end

@implementation PhotoDelegate

+ (instancetype)defaultDelegate
{
    static PhotoDelegate *inst = nil;
    if (inst == nil) {
        inst = [[PhotoDelegate alloc] init];
    }
    return inst;
}

- (instancetype)init
{
    self.imagePicker = [[UIImagePickerController alloc] init];
    self.imagePicker.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
    self.imagePicker.delegate = self;
    
    return [super init];
}

- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary<NSString *,id> *)info
{
    @autoreleasepool {
        [self.imagePicker dismissViewControllerAnimated:YES completion:nil];
        NSString *type = [info objectForKey:UIImagePickerControllerMediaType];
        if ([type isEqualToString:@"public.image"]) {
            UIImage *image = nil;
            bool ok = NO;
            if (self.mode == kCameraRollModeAvatar) {
                image = resizeImage([info objectForKey:UIImagePickerControllerEditedImage], self.size.width, self.size.height);
            } else {
                image = [info objectForKey:UIImagePickerControllerOriginalImage];
            }
            
            if (image) {
                if (strendwith([self.cachePath UTF8String], ".png")) {
                    ok = [UIImagePNGRepresentation(image) writeToFile:self.cachePath atomically:YES];
                } else {
                    ok = [UIImageJPEGRepresentation(image, 1.0f) writeToFile:self.cachePath atomically:YES];
                }
            }
            cocos2d::ValueMap data;
            if (ok) {
                data["status"] = "complete";
                data["path"] = [self.cachePath UTF8String];
            } else {
                data["status"] = "ioerror";
            }
            photo::dispatch(self.event, data);
        } else {
            cocos2d::ValueMap data;
            data["status"] = "typeerror";
            photo::dispatch(self.event, data);
        }
    }
}

- (void)imagePickerControllerDidCancel:(UIImagePickerController *)picker
{
    @autoreleasepool {
        [self.imagePicker dismissViewControllerAnimated:YES completion:nil];
        cocos2d::ValueMap data;
        data["status"] = "cancel";
        photo::dispatch(self.event, data);
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
    self.event = "select";
    [self openSelector];
}

- (void)selectAvatarFromCamera:(NSString *)cachePath withSize:(CGSize)size
{
    self.imagePicker.sourceType = UIImagePickerControllerSourceTypeCamera;
    self.imagePicker.allowsEditing = true;
    self.mode = kCameraRollModeAvatar;
    self.cachePath = cachePath;
    self.size = size;
    self.event = "takeAvatar";
    [self openSelector];
}

- (void)selectAvatarFromPhotoLibrary:(NSString *)cachePath withSize:(CGSize)size
{
    self.imagePicker.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
    self.imagePicker.allowsEditing = true;
    self.mode = kCameraRollModeAvatar;
    self.cachePath = cachePath;
    self.size = size;
    self.event = "selectAvatar";
    [self openSelector];
}

@end

void photo::selectAvatar(const std::string &cachePath, int width, int height)
{
    @autoreleasepool {
        PhotoDelegate *inst = [PhotoDelegate defaultDelegate];
        [inst selectAvatarFromPhotoLibrary:toNSString(cachePath) withSize:CGSizeMake((float)width, (float)height)];
    }
}

void photo::takeAvatar(const std::string &cachePath, int width, int height)
{
    @autoreleasepool {
        PhotoDelegate *inst = [PhotoDelegate defaultDelegate];
        [inst selectAvatarFromCamera:toNSString(cachePath) withSize:CGSizeMake((float)width, (float)height)];
    }
}

void photo::select(const std::string &cachePath)
{
    @autoreleasepool {
        PhotoDelegate *inst = [PhotoDelegate defaultDelegate];
        [inst selectImage:toNSString(cachePath)];
    }
}

#endif // CCLUA_OS_IOS
