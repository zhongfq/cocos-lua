#import "WeChat.h"

USING_NS_CCLUA;
USING_NS_CCLUA_PLUGIN;

#if defined(CCLUA_OS_IOS)
#import "ios/WXApi.h"
#import "ios/WechatAuthSDK.h"
#import "cclua/AppContext-ios.h"
#import "cclua/plugin-ios.h"
#import "cclua/filesystem.h"

@interface WeChatDelegate : NSObject<WXApiDelegate, WechatAuthAPIDelegate, UIApplicationDelegate>

@property(nonatomic, strong) WechatAuthSDK *authSDK;
@property(nonatomic, strong) NSString *universalLink;
@property(nonatomic, strong) NSString *appid;

- (instancetype)init;
+ (instancetype) defaultDelegate;

// wechat sdk
- (void)onReq:(BaseReq*)req;
- (void)onResp:(BaseResp*)resp;

- (void)onAuthGotQrcode:(UIImage *)image;
- (void)onQrcodeScanned;
- (void)onAuthFinish:(int)errCode AuthCode:(nullable NSString *)authCode;

#pragma mark -- UIApplicationDelegate --
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;

@end

@implementation WeChatDelegate

- (instancetype)init
{
    self.authSDK = [[WechatAuthSDK alloc] init];
    [self.authSDK setDelegate:self];
    return [super init];
}

+ (instancetype) defaultDelegate
{
    static WeChatDelegate *inst = nil;
    if (inst == nil) {
        inst = [[WeChatDelegate alloc] init];
    }
    return inst;
}

- (void)onReq:(BaseReq*)req
{
}

- (void)onResp:(BaseResp*)resp
{
    @autoreleasepool {
        if ([resp isKindOfClass:[SendAuthResp class]]) {
            SendAuthResp *authResp = (SendAuthResp *)resp;
            cocos2d::ValueMap data;
            data["errcode"] = authResp.errCode;
            data["code"] = [authResp.code UTF8String];
            data["state"] = [authResp.state UTF8String];
            data["lang"] = [authResp.lang UTF8String];
            data["country"] = [authResp.country UTF8String];
            WeChat::dispatch("auth", data);
        } else if ([resp isKindOfClass:[SendMessageToWXResp class]]) {
            cocos2d::ValueMap data;
            data["errcode"] = resp.errCode;
            WeChat::dispatch("share", data);
        }
    }
}

- (void)onAuthGotQrcode:(UIImage *)image
{
    @autoreleasepool {
        auto path = cclua::filesystem::getTmpDirectory() + "/wechat_auth_qrcode.jpg";
        NSData *imgData = UIImageJPEGRepresentation(image, 1.0f);
        [imgData writeToFile:[NSString stringWithUTF8String:path.c_str()] atomically:YES];
        
        cocos2d::ValueMap data;
        data["errcode"] = 0;
        data["path"] = path;
        WeChat::dispatch("authQRCode", data);
    }
}

- (void)onQrcodeScanned
{
    @autoreleasepool {
    }
}

- (void)onAuthFinish:(int)errCode AuthCode:(nullable NSString *)authCode
{
    @autoreleasepool {
        cocos2d::ValueMap data;
        data["errcode"] = errCode;
        data["code"] = [authCode UTF8String];
        WeChat::dispatch("authQRCode", data);
    }
}

#pragma mark -- UIApplicationDelegate --
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    @autoreleasepool {
        cclua::runtime::log("init wechat oath %s", [_appid UTF8String]);
        [WXApi registerApp:_appid universalLink:_universalLink];
        return YES;
    }
}

- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options
{
    @autoreleasepool {
        return [WXApi handleOpenURL:url delegate:[WeChatDelegate defaultDelegate]];
    }
}

@end

NS_CCLUA_PLUGIN_BEGIN

Dispatcher WeChat::_dispatcher;

void WeChat::init(const std::string &appid, const std::string &universalLink)
{
    @autoreleasepool {
        if (!TARGET_IPHONE_SIMULATOR) {
            AppContext *context = (AppContext *)[UIApplication sharedApplication].delegate;
            WeChatDelegate *delegate = [WeChatDelegate defaultDelegate];
            delegate.appid = toNSString(appid);
            delegate.universalLink = toNSString(universalLink);
            [context addAppDelegate:delegate];
        }
    }
}

bool WeChat::isInstalled()
{
    @autoreleasepool {
        return [WXApi isWXAppInstalled];
    }
}

void WeChat::auth(const std::string &scope, const std::string &state)
{
    @autoreleasepool {
        cclua::runtime::log("send wechat auth request");
        SendAuthReq *req = [[SendAuthReq alloc] init];
        req.scope = toNSString(scope);
        req.state = toNSString(state);
        [WXApi sendAuthReq:req
            viewController:[[[UIApplication sharedApplication] keyWindow] rootViewController]
                  delegate:[WeChatDelegate defaultDelegate]
                completion:nil];
    }
}

void WeChat::authQRCode(const std::string &appid, const std::string &nonceStr, const std::string &timestamp, const std::string &scope, const std::string &signature)
{
    @autoreleasepool {
        WeChatDelegate *delegate = [WeChatDelegate defaultDelegate];
        [delegate.authSDK setDelegate:nil];
        [delegate.authSDK StopAuth];
        [delegate.authSDK setDelegate:delegate];
        BOOL status = [delegate.authSDK Auth:toNSString(appid)
                       nonceStr:toNSString(nonceStr)
                      timeStamp:toNSString(timestamp)
                          scope:toNSString(scope)
                      signature:toNSString(signature)
                     schemeData:nil];
        cclua::runtime::log("[%s] send wechat qrcode auth request", BOOL_STR(status));
    }
}

void WeChat::stopAuth()
{
    @autoreleasepool {
        WeChatDelegate *delegate = [WeChatDelegate defaultDelegate];
        [delegate.authSDK StopAuth];
    }
}

#define THUMB_SIZE 150
static UIImage *_create_thumb(NSString *path)
{
    UIImage *image = [UIImage imageWithContentsOfFile:path];
    UIGraphicsBeginImageContextWithOptions(CGSizeMake(THUMB_SIZE, THUMB_SIZE), false, 1);
    [image drawInRect:CGRectMake(0, 0, THUMB_SIZE, THUMB_SIZE)];
    UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return newImage;
}

void WeChat::share(ShareType type, cocos2d::ValueMap &value)
{
    @autoreleasepool {
        SendMessageToWXReq *req = [[SendMessageToWXReq alloc] init];
        req.scene = value["scene"].asInt();
        switch (type) {
            case ShareType::TEXT: {
                req.text = toNSString(value["text"].asString());
                req.bText = YES;
                break;
            }
            case ShareType::IMAGE: {
                WXMediaMessage *message = [WXMediaMessage message];
                [message setThumbImage:_create_thumb(toNSString(value["thumb"]))];
                message.title = toNSString(value["title"]);
                message.description = toNSString(value["description"]);
                
                WXImageObject *image = [WXImageObject object];
                image.imageData = [NSData dataWithContentsOfFile:toNSString(value["url"])];
                message.mediaObject = image;
                
                req.bText = NO;
                req.message = message;
                break;
            }
            case ShareType::MUSIC: {
                WXMediaMessage *message = [WXMediaMessage message];
                [message setThumbImage:_create_thumb(toNSString(value["thumb"]))];
                message.title = toNSString(value["title"]);
                message.description = toNSString(value["description"]);
                
                WXMusicObject *music = [WXMusicObject object];
                music.musicUrl = toNSString(value["url"]);
                music.musicDataUrl = toNSString(value["data_url"]);
                message.mediaObject = music;
                
                req.bText = NO;
                req.message = message;
                break;
            }
            case ShareType::VIDEO: {
                WXMediaMessage *message = [WXMediaMessage message];
                [message setThumbImage:_create_thumb(toNSString(value["thumb"]))];
                message.title = toNSString(value["title"]);
                message.description = toNSString(value["description"]);
                
                WXVideoObject *video = [WXVideoObject object];
                video.videoUrl = toNSString(value["url"]);
                
                req.bText = NO;
                req.message = message;
                break;
            }
            case ShareType::WEB: {
                WXMediaMessage *message = [WXMediaMessage message];
                [message setThumbImage:_create_thumb(toNSString(value["thumb"]))];
                message.title = toNSString(value["title"]);
                message.description = toNSString(value["description"]);
                
                WXWebpageObject *web = [WXWebpageObject object];
                web.webpageUrl = toNSString(value["url"]);
                message.mediaObject = web;
                
                req.bText = NO;
                req.message = message;
                break;
            }
            default:
                CCASSERT(false, "message type error");
                break;
        }
        [WXApi sendReq:req completion:nil];
    }
}

void WeChat::open(const std::string &username, const std::string path, ProgramType type)
{
    @autoreleasepool {
        WXLaunchMiniProgramReq *req = [[WXLaunchMiniProgramReq alloc] init];
        req.userName = toNSString(username);
        req.path = toNSString(path);
        req.miniProgramType = (WXMiniProgramType)type;
        [WXApi sendReq:req completion:nil];
    }
}

NS_CCLUA_PLUGIN_END

#endif
