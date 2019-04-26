#import "lua_wechat.h"
#import "xgame/xruntime.h"
#import "cocos2d.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#import "WXApi.h"
#import <TargetConditionals.h>

@interface WeChatConnector : NSObject<WXApiDelegate>

// wechat sdk
- (void)onReq:(BaseReq*)req;
- (void)onResp:(BaseResp*)resp;

- (instancetype)init;

@property std::function<void(const std::string &event, const std::string &data)> callback;

@end

static NSString *objectToString(NSObject *obj)
{
    NSData *data = [NSJSONSerialization dataWithJSONObject:obj options:0 error:nil];
    return [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
}

@implementation WeChatConnector

- (instancetype)init
{
    _callback = nullptr;
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
            message = objectToString(dict);
            event = @"auth";
        } else if ([resp isKindOfClass:[SendMessageToWXResp class]]) {
            event = @"share";
            NSMutableDictionary *dict = [[NSMutableDictionary alloc] init];
            [dict setValue:[NSNumber numberWithInt:resp.errCode] forKey:@"errcode"];
            message = objectToString(dict);
        }
        
        if (event != nil && _callback != nullptr) {
            _callback([event UTF8String], [message UTF8String]);
        }
    }
}

@end

#define CLASS_CONNECTOR "WeChatConnector*"
#define olua_checkconnector(L, i) ((__bridge WeChatConnector *)olua_checkobj(L, i, CLASS_CONNECTOR))
#define NSStringMake(str) (str == NULL ? nil : @(str))

static int _gc(lua_State *L)
{
    WeChatConnector *connector = olua_checkconnector(L, 1);
    CFBridgingRelease((__bridge CFTypeRef)connector);
    return 0;
}

static int _init(lua_State *L)
{
    @autoreleasepool {
        if (!TARGET_IPHONE_SIMULATOR) {
            const char *appid = olua_checkstring(L, 2);
            [WXApi registerApp:NSStringMake(appid)];
            xgame::runtime::log("init wechat oath %s", appid);
        }
    }
    
    return 0;
}

static int _handle_open_url(lua_State *L)
{
    @autoreleasepool {
        WeChatConnector *connector = olua_checkconnector(L, 1);
        NSURL *url = [NSURL URLWithString:NSStringMake(olua_checkstring(L, 2))];
        [WXApi handleOpenURL:url delegate:connector];
    }
    
    return 0;
}

static int _is_installed(lua_State *L)
{
    @autoreleasepool {
        lua_pushboolean(L, [WXApi isWXAppInstalled]);
    }
    return 1;
}

static int _authorize(lua_State *L)
{
    @autoreleasepool {
        xgame::runtime::log("send wechat auth request");

        WeChatConnector *connector = olua_checkconnector(L, 1);
        SendAuthReq *req = [[SendAuthReq alloc] init];
        req.scope = NSStringMake(olua_checkstring(L, 2));
        req.state = NSStringMake(olua_checkstring(L, 3));
        [WXApi sendAuthReq:req
            viewController:[[[UIApplication sharedApplication] keyWindow] rootViewController]
                  delegate:connector];
    }
    
    return 0;
}

static int _set_callback(lua_State *L)
{
    @autoreleasepool {
        WeChatConnector *connector = olua_checkconnector(L, 1);
        void *cb_store = (void *)connector;
        std::string func = olua_setcallback(L, cb_store, "dispatcher", 2, OLUA_CALLBACK_TAG_REPLACE);
        connector.callback = [cb_store, func] (const std::string &event, const std::string &data) {
            lua_State *L = olua_mainthread();
            int top = lua_gettop(L);
            lua_pushstring(L, event.c_str());
            lua_pushstring(L, data.c_str());
            olua_callback(L, cb_store, func.c_str(), 2);
            lua_settop(L, top);
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

static int _share(lua_State *L)
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
        [WXApi sendReq:req];
    }
    return 0;
}

int luaopen_wechat(lua_State *L)
{
    oluacls_class(L, CLASS_CONNECTOR, nullptr);
    oluacls_setfunc(L, "__gc", _gc);
    oluacls_setfunc(L, "init", _init);
    oluacls_setfunc(L, "handleOpenURL", _handle_open_url);
    oluacls_setfunc(L, "isInstalled", _is_installed);
    oluacls_setfunc(L, "setDispatcher", _set_callback);
    oluacls_setfunc(L, "auth", _authorize);
    oluacls_setfunc(L, "share", _share);
    
    xgame::runtime::registerFeature("wechat.ios", true);
    
    WeChatConnector *connector = [[WeChatConnector alloc] init];
    olua_push_obj(L, (void *)CFBridgingRetain(connector), CLASS_CONNECTOR);
    
    return 1;
}

#endif
