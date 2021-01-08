#import "lua_wechat.h"
#import "xgame/runtime.h"
#import "xgame/filesystem.h"
#import "xgame/PluginConnector.h"
#import "cocos2d.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#import "WXApi.h"
#import "WechatAuthSDK.h"
#import <TargetConditionals.h>

@interface WeChatConnector : PluginConnector<WXApiDelegate, WechatAuthAPIDelegate>

// wechat sdk
- (void)onReq:(BaseReq*)req;
- (void)onResp:(BaseResp*)resp;

- (void)onAuthGotQrcode:(UIImage *)image;
- (void)onQrcodeScanned;
- (void)onAuthFinish:(int)errCode AuthCode:(nullable NSString *)authCode;

- (instancetype)init;

@property(nonatomic, strong) WechatAuthSDK *authSDK;

@end

@implementation WeChatConnector

- (instancetype)init
{
    self.authSDK = [[WechatAuthSDK alloc] init];
    [self.authSDK setDelegate:self];
    return [super init];
}

- (void)onReq:(BaseReq*)req
{
}

- (void)onResp:(BaseResp*)resp
{
    @autoreleasepool {
        NSString *message = nil;
        NSString *event = nil;
        if ([resp isKindOfClass:[SendAuthResp class]]) {
            SendAuthResp *authResp = (SendAuthResp *)resp;
            NSMutableDictionary *dict = [[NSMutableDictionary alloc] init];
            [dict setValue:[NSNumber numberWithInt:authResp.errCode] forKey:@"errcode"];
            [dict setValue:authResp.code forKey:@"code"];
            [dict setValue:authResp.state forKey:@"state"];
            [dict setValue:authResp.lang forKey:@"lang"];
            [dict setValue:authResp.country forKey:@"country"];
            message = [self objectToString:dict];
            event = @"auth";
        } else if ([resp isKindOfClass:[SendMessageToWXResp class]]) {
            event = @"share";
            NSMutableDictionary *dict = [[NSMutableDictionary alloc] init];
            [dict setValue:[NSNumber numberWithInt:resp.errCode] forKey:@"errcode"];
            message = [self objectToString:dict];
        }
        
        if (event != nil) {
            [self dispatch:event withMessage:message];
        }
    }
}

- (void)onAuthGotQrcode:(UIImage *)image
{
    @autoreleasepool {
        auto path = xgame::filesystem::getTmpDirectory() + "/wechat_auth_qrcode.jpg";
        NSData *data = UIImageJPEGRepresentation(image, 1.0f);
        [data writeToFile:[NSString stringWithUTF8String:path.c_str()] atomically:YES];
        
        NSMutableDictionary *dict = [[NSMutableDictionary alloc] init];
        [dict setValue:[NSNumber numberWithInt:0] forKey:@"errcode"];
        [dict setValue:[NSString stringWithUTF8String:path.c_str()] forKey:@"path"];
        
        [self dispatch:@"authQrcode" withMessage:[self objectToString:dict]];
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
        NSMutableDictionary *dict = [[NSMutableDictionary alloc] init];
        [dict setValue:[NSNumber numberWithInt:errCode] forKey:@"errcode"];
        [dict setValue:authCode forKey:@"code"];
        [self dispatch:@"authQrcode" withMessage:[self objectToString:dict]];
    }
}

@end

#define CLASS_CONNECTOR "WeChatConnector*"
#define olua_checkconnector(L, i) ((__bridge WeChatConnector *)olua_checkobj(L, i, CLASS_CONNECTOR))
#define NSStringMake(str) (str == NULL ? nil : @(str))

static int l_gc(lua_State *L)
{
    @autoreleasepool {
        WeChatConnector *connector = olua_checkconnector(L, 1);
        CFBridgingRelease((__bridge CFTypeRef)connector);
    }
    return 0;
}

static int l_init(lua_State *L)
{
    @autoreleasepool {
        if (!TARGET_IPHONE_SIMULATOR) {
            const char *appid = olua_checkstring(L, 2);
            const char *universalLink = olua_checkstring(L, 3);
            [WXApi registerApp:NSStringMake(appid) universalLink:NSStringMake(universalLink)];
            xgame::runtime::log("init wechat oath %s", appid);
        }
    }
    
    return 0;
}

static int l_handleOpenURL(lua_State *L)
{
    @autoreleasepool {
        WeChatConnector *connector = olua_checkconnector(L, 1);
        NSURL *url = [NSURL URLWithString:NSStringMake(olua_checkstring(L, 2))];
        [WXApi handleOpenURL:url delegate:connector];
    }
    
    return 0;
}

static int l_isInstalled(lua_State *L)
{
    @autoreleasepool {
        lua_pushboolean(L, [WXApi isWXAppInstalled]);
    }
    return 1;
}

static int l_auth(lua_State *L)
{
    @autoreleasepool {
        xgame::runtime::log("send wechat auth request");
        WeChatConnector *connector = olua_checkconnector(L, 1);
        SendAuthReq *req = [[SendAuthReq alloc] init];
        req.scope = NSStringMake(olua_checkstring(L, 2));
        req.state = NSStringMake(olua_checkstring(L, 3));
        [WXApi sendAuthReq:req
            viewController:[[[UIApplication sharedApplication] keyWindow] rootViewController]
                  delegate:connector
                completion:nil];
    }
    
    return 0;
}

static int l_authQRCode(lua_State *L)
{
    @autoreleasepool {
        WeChatConnector *connector = olua_checkconnector(L, 1);
        [connector.authSDK setDelegate:nil];
        [connector.authSDK StopAuth];
        [connector.authSDK setDelegate:connector];
        BOOL status = [connector.authSDK Auth:NSStringMake(olua_checkstring(L, 2))
                       nonceStr:NSStringMake(olua_checkstring(L, 3))
                      timeStamp:NSStringMake(olua_checkstring(L, 4))
                          scope:NSStringMake(olua_checkstring(L, 5))
                      signature:NSStringMake(olua_checkstring(L, 6))
                     schemeData:NSStringMake(olua_checkstring(L, 7))];
        xgame::runtime::log("[%s] send wechat qrcode auth request", BOOL_STR(status));
    }
    return 0;
}

static int l_setDispatcher(lua_State *L)
{
    @autoreleasepool {
        WeChatConnector *connector = olua_checkconnector(L, 1);
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

typedef enum {
    kMessageTypeNode,
    kMessageTypeText,
    kMessageTypePicture,
    kMessageTypeMusic,
    kMessageTypeVideo,
    kMessageTypeWeb
} MessageType;

#define checkstring(L, idx, field) [NSString stringWithUTF8String:luaext_checkstring(L, idx, field)]
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

static int l_share(lua_State *L)
{
    @autoreleasepool {
        luaL_checktype(L, 2, LUA_TTABLE);
        MessageType type = (MessageType)olua_optfieldinteger(L, 2, "type", kMessageTypeNode);
        SendMessageToWXReq *req = [[SendMessageToWXReq alloc] init];
        req.scene = (int)olua_checkfieldinteger(L, 2, "scene");
        switch (type) {
            case kMessageTypeText: {
                req.text = NSStringMake(olua_checkfieldstring(L, 2, "text"));
                req.bText = YES;
                break;
            }
            case kMessageTypePicture: {
                WXMediaMessage *message = [WXMediaMessage message];
                [message setThumbImage:_create_thumb(NSStringMake(olua_checkfieldstring(L, 2, "thumb")))];
                message.title = NSStringMake(olua_checkfieldstring(L, 2, "title"));
                message.description = NSStringMake(olua_checkfieldstring(L, 2, "description"));
                
                WXImageObject *image = [WXImageObject object];
                image.imageData = [NSData dataWithContentsOfFile:NSStringMake(olua_checkfieldstring(L, 2, "url"))];
                message.mediaObject = image;
                
                req.bText = NO;
                req.message = message;
                break;
            }
            case kMessageTypeMusic: {
                WXMediaMessage *message = [WXMediaMessage message];
                [message setThumbImage:_create_thumb(NSStringMake(olua_checkfieldstring(L, 2, "thumb")))];
                message.title = NSStringMake(olua_checkfieldstring(L, 2, "title"));
                message.description = NSStringMake(olua_checkfieldstring(L, 2, "description"));
                
                WXMusicObject *music = [WXMusicObject object];
                music.musicUrl = NSStringMake(olua_checkfieldstring(L, 2, "url"));
                music.musicDataUrl = NSStringMake(olua_checkfieldstring(L, 2, "data_url"));
                message.mediaObject = music;
                
                req.bText = NO;
                req.message = message;
                break;
            }
            case kMessageTypeVideo: {
                WXMediaMessage *message = [WXMediaMessage message];
                [message setThumbImage:_create_thumb(NSStringMake(olua_checkfieldstring(L, 2, "thumb")))];
                message.title = NSStringMake(olua_checkfieldstring(L, 2, "title"));
                message.description = NSStringMake(olua_checkfieldstring(L, 2, "description"));
                
                WXVideoObject *video = [WXVideoObject object];
                video.videoUrl = NSStringMake(olua_checkfieldstring(L, 2, "url"));
                
                req.bText = NO;
                req.message = message;
                break;
            }
            case kMessageTypeWeb: {
                WXMediaMessage *message = [WXMediaMessage message];
                [message setThumbImage:_create_thumb(NSStringMake(olua_checkfieldstring(L, 2, "thumb")))];
                message.title = NSStringMake(olua_checkfieldstring(L, 2, "title"));
                message.description = NSStringMake(olua_checkfieldstring(L, 2, "description"));
                
                WXWebpageObject *web = [WXWebpageObject object];
                web.webpageUrl = NSStringMake(olua_checkfieldstring(L, 2, "url"));
                message.mediaObject = web;
                
                req.bText = NO;
                req.message = message;
                break;
            }
            default:
                luaL_error(L, "unsupport message type: %d", (int)type);
                break;
        }
        [WXApi sendReq:req completion:nil];
    }
    return 0;
}

static int l_open(lua_State *L)
{
    @autoreleasepool {
        WXLaunchMiniProgramReq *req = [[WXLaunchMiniProgramReq alloc] init];
        req.userName = [NSString stringWithUTF8String:luaL_checkstring(L, 2)];
        req.path = [NSString stringWithUTF8String:luaL_checkstring(L, 3)];
        req.miniProgramType = (WXMiniProgramType)luaL_checkinteger(L, 4);
        [WXApi sendReq:req completion:nil];

    }
    return 0;
}

int luaopen_wechat(lua_State *L)
{
    oluacls_class(L, CLASS_CONNECTOR, nullptr);
    oluacls_func(L, "__gc", l_gc);
    oluacls_func(L, "init", l_init);
    oluacls_func(L, "handleOpenURL", l_handleOpenURL);
    oluacls_func(L, "isInstalled", l_isInstalled);
    oluacls_func(L, "setDispatcher", l_setDispatcher);
    oluacls_func(L, "auth", l_auth);
    oluacls_func(L, "authQRCode", l_authQRCode);
    oluacls_func(L, "share", l_share);
    oluacls_func(L, "open", l_open);
    
    xgame::runtime::registerFeature("wechat.ios", true);
    
    @autoreleasepool {
        WeChatConnector *connector = [WeChatConnector new];
        olua_push_obj(L, (void *)CFBridgingRetain(connector), CLASS_CONNECTOR);
    }
    
    return 1;
}

#endif
