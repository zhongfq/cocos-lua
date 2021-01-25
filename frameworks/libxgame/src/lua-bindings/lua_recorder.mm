#import "lua_recorder.h"
#import "cclua/runtime.h"
#import "cclua/PluginConnector.h"
#import "cocos2d.h"

#ifdef CCLUA_OS_IOS
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>

USING_NS_CC;
USING_NS_CCLUA;

@interface RecorderConnector : PluginConnector
@property(readwrite, strong, nonatomic) NSString *filename;
@property(readwrite, strong, nonatomic) NSString *sessionCatalog;
@property(readwrite, strong, nonatomic) AVAudioRecorder *recorder;

- (instancetype)init;
- (void)startRecording:(NSString *)filename;
- (void)stopRecording;

@end

@implementation RecorderConnector

- (instancetype)init
{
    self.filename = nil;
    self.recorder = nil;
    return [super init];
}

- (void)startRecording:(NSString *)filename
{
    if (_recorder != nil)
    {
        runtime::log("only allow to run single instance");
        return;
    }
    
    self.filename = filename;
    self.sessionCatalog = [NSString stringWithUTF8String:runtime::getAudioSessionCatalog().c_str()];
    
    FileUtils::getInstance()->removeFile([self.filename UTF8String]);
    
    NSError *error;
    AVAudioSession *session = [AVAudioSession sharedInstance];
    [session setCategory:AVAudioSessionCategoryRecord error:&error];
    [session setActive:YES error:nil];
    
    NSMutableDictionary *recordSetting = [[NSMutableDictionary alloc] init];
    [recordSetting setValue:[NSNumber numberWithInt:kAudioFormatLinearPCM] forKey:AVFormatIDKey];
    [recordSetting setValue:[NSNumber numberWithFloat:44100.0] forKey:AVSampleRateKey];
    [recordSetting setValue:[NSNumber numberWithInt: 2] forKey:AVNumberOfChannelsKey];
    [recordSetting setValue:[NSNumber numberWithInt:AVAudioQualityHigh] forKey:AVEncoderAudioQualityKey];

    self.recorder = [[AVAudioRecorder alloc] initWithURL:[NSURL fileURLWithPath:self.filename] settings:recordSetting error:&error];
    
    if (self.recorder == nil)
    {
        [self dispatch:@"state" withMessage:@"ERR_CREATE_FILE"];
    }
    else
    {
        [self.recorder prepareToRecord];
        [_recorder setMeteringEnabled:YES];
        [self.recorder record];
        [self dispatch:@"state" withMessage:@"STARTED"];
    }
}

- (void)stopRecording
{
    if (self.recorder != nil)
    {
        [self.recorder stop];
        [self dispatch:@"state" withMessage:@"STOPPED"];
        self.recorder = nil;
        
        [[AVAudioSession sharedInstance] setCategory:self.sessionCatalog error:nil];
        runtime::setAudioSessionCatalog([self.sessionCatalog UTF8String]);
    }
}

@end

#define CLASS_CONNECTOR "RecorderConnector*"
#define olua_checkconnector(L, i) ((__bridge RecorderConnector *)olua_checkobj(L, i, CLASS_CONNECTOR))
#define NSStringMake(str) (str == NULL ? nil : @(str))

static int _gc(lua_State *L)
{
    @autoreleasepool {
        RecorderConnector *connector = olua_checkconnector(L, 1);
        CFBridgingRelease((__bridge CFTypeRef)connector);
    }
    
    return 0;
}

static int _set_callback(lua_State *L)
{
    @autoreleasepool {
        lua_settop(L, 2);
        RecorderConnector *connector = olua_checkconnector(L, 1);
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
    runtime::runOnCocosThread([handler, granted]() {
        lua_State *L = olua_mainthread(NULL);
        int top = lua_gettop(L);
        olua_pusherrorfunc(L);
        olua_getref(L, handler);
        if (lua_isfunction(L, -1)) {
            lua_pushboolean(L, granted);
            lua_pcall(L, 1, 0, top + 1);
            olua_unref(L, handler);
        }
        lua_settop(L, top);
    });
}

static int _request_permission(lua_State *L)
{
    @autoreleasepool {
        lua_settop(L, 2);
        int handler = olua_funcref(L, 2);
        PermissionStatus current = runtime::getPermissionStatus(Permission::AUDIO);
        runtime::requestPermission(Permission::AUDIO, [=](PermissionStatus status) {
            if (current == PermissionStatus::DENIED || status == PermissionStatus::RESTRICTED) {
                std::string appName = [[[[NSBundle mainBundle]infoDictionary] objectForKey:@"CFBundleDisplayName"] UTF8String];
                std::string title = "没有权限访问您的麦克风";
                std::string message = "请在iPhone的”设置-隐私-麦克风“选项中，允许" + appName + "访问您的麦克风";
                runtime::openAppSetting(title, message, [=]() {
                    did_request_permission(handler, status == PermissionStatus::AUTHORIZED);
                });
            } else {
                did_request_permission(handler, status == PermissionStatus::AUTHORIZED);
            }
        });
    }
    
    return 0;
}

static int _start(lua_State *L)
{
    @autoreleasepool {
        lua_settop(L, 2);
        RecorderConnector *connector = olua_checkconnector(L, 1);
        const char *filename = luaL_checkstring(L, 2);
        [connector startRecording:[NSString stringWithUTF8String:filename]];
    }
    return 0;
}

static int _stop(lua_State *L)
{
    @autoreleasepool {
        lua_settop(L, 1);
        RecorderConnector *connector = olua_checkconnector(L, 1);
        [connector stopRecording];
    }
    return 0;
}

int luaopen_recorder(lua_State *L)
{
    oluacls_class(L, CLASS_CONNECTOR, nullptr);
    oluacls_func(L, "__gc", _gc);
    oluacls_func(L, "setDispatcher", _set_callback);
    oluacls_func(L, "requestPermission", _request_permission);
    oluacls_func(L, "start", _start);
    oluacls_func(L, "stop", _stop);
    
    runtime::registerFeature("recorder.ios", true);
    
    @autoreleasepool {
        RecorderConnector *connector = [RecorderConnector new];
        olua_push_obj(L, (void *)CFBridgingRetain(connector), CLASS_CONNECTOR);
    }
    
    return 1;
}

#endif
