#import "lua_wechat.h"
#import "xgame/runtime.h"
#import "xgame/filesystem.h"
#import "xgame/PluginConnector.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#import "WXVoiceRecognizer.h"

@interface WXVoiceConnector : PluginConnector<WXVoiceDelegate, WXRecorderDataDelegate>

// WXVoiceDelegate
- (void)voiceInputResultArray:(NSArray *)array;
- (void)voiceInputMakeError:(NSInteger)errorCode;
- (void)voiceInputWaitForResult;
- (void)voiceInputDidCancel;
- (void)voiceInputVolumn:(float)volumn;
- (BOOL)shouldSendData:(NSData *)data withUrlArgs:(NSString *)args delegate:(id<WXNetDelegate>)delegate;

// WXRecorderDataDelegate
- (void)recorderData:(NSData*)data withSampleRate:(int)sampleRate isEnd:(BOOL)end;

@end

@implementation WXVoiceConnector

- (void)voiceInputResultArray:(NSArray *)array
{
    @autoreleasepool {
        if (array && array.count > 0) {
            NSMutableArray *list = [[NSMutableArray alloc] init];
            for (int i = 0; i < array.count; i++) {
                WXVoiceResult *result = [array objectAtIndex:i];
                NSMutableDictionary *dict = [[NSMutableDictionary alloc] init];
                [dict setValue:result.text forKey:@"text"];
                [dict setValue:result.voice_id forKey:@"voiceId"];
                [dict setValue:[NSNumber numberWithInteger:result.startOffset] forKey:@"startOffset"];
                [dict setValue:[NSNumber numberWithInteger:result.endOffset] forKey:@"endOffset"];
                [dict setValue:[NSNumber numberWithBool:result.isEnd] forKey:@"isEnd"];
                [list addObject:dict];
            }
            [self dispatch:@"inputResultArray" withMessage:[self objectToString:list]];
        }
    }
}

- (void)voiceInputMakeError:(NSInteger)errorCode
{
    @autoreleasepool {
        NSMutableDictionary *dict = [[NSMutableDictionary alloc] init];
        [dict setValue:[NSNumber numberWithInteger:errorCode] forKey:@"errorCode"];
        [self dispatch:@"inputMakeError" withMessage:[self objectToString:dict]];
    }
}

- (void)voiceInputWaitForResult
{
    @autoreleasepool {
        [self dispatch:@"inputWaitForResult" withMessage:@""];
    }
}

- (void)voiceInputDidCancel
{
    @autoreleasepool {
        [self dispatch:@"inputDidCancel" withMessage:@""];
    }
}

- (void)voiceInputVolumn:(float)volumn
{
}

- (BOOL)shouldSendData:(NSData *)data withUrlArgs:(NSString *)args delegate:(id<WXNetDelegate>)delegate
{
    return NO;
}

- (void)recorderData:(NSData*)data withSampleRate:(int)sampleRate isEnd:(BOOL)end
{
}

@end

#define CLASS_CONNECTOR "WXVoiceConnector*"
#define olua_checkconnector(L, i) ((__bridge WXVoiceConnector *)olua_checkobj(L, i, CLASS_CONNECTOR))
#define NSStringMake(str) (str == NULL ? nil : @(str))

static int l_gc(lua_State *L)
{
    @autoreleasepool {
        lua_settop(L, 1);
        WXVoiceConnector *connector = olua_checkconnector(L, 1);
        [WXVoiceRecognizer releaseWXVoice];
        CFBridgingRelease((__bridge CFTypeRef)connector);
    }
    return 0;
}

static int l_init(lua_State *L)
{
    @autoreleasepool {
        lua_settop(L, 2);
        WXVoiceConnector *connector = olua_checkconnector(L, 1);
        [[WXVoiceRecognizer sharedWXVoice] setAppID:NSStringMake(olua_checkstring(L, 2))];
        [WXVoiceRecognizer sharedWXVoice].delegate = connector;
        [WXVoiceRecognizer sharedWXVoice].recorderDataDelegate = connector;
    }
    return 0;
}

static int l_setDispatcher(lua_State *L)
{
    lua_settop(L, 2);
    WXVoiceConnector *connector = olua_checkconnector(L, 1);
    void *cb_store = (void *)connector;
    std::string func = olua_setcallback(L, cb_store, "dispatcher", 2, OLUA_TAG_REPLACE);
    connector.dispatcher = [cb_store, func] (const std::string &event, const std::string &data) {
        lua_State *L = olua_mainthread(NULL);
        int top = lua_gettop(L);
        lua_pushstring(L, event.c_str());
        lua_pushstring(L, data.c_str());
        olua_callback(L, cb_store, func.c_str(), 2);
        lua_settop(L, top);
    };
    return 0;
}

static int l_setContinuousMode(lua_State *L)
{
    @autoreleasepool {
        lua_settop(L, 2);
        [[WXVoiceRecognizer sharedWXVoice] setContinuousMode: olua_checkboolean(L, 2)];
    }
    return 0;
}

static int l_setLanguageType(lua_State *L)
{
    @autoreleasepool {
        lua_settop(L, 2);
        [[WXVoiceRecognizer sharedWXVoice] setLanguageType: (LanguageType)olua_checkinteger(L, 2)];
    }
    return 0;
}

static int l_startOnce(lua_State *L)
{
    @autoreleasepool {
        bool ret = [[WXVoiceRecognizer sharedWXVoice] startOnce];
        lua_pushboolean(L, ret);
    }
    return 0;
}

static int l_startOnceWithGrammarString(lua_State *L)
{
    @autoreleasepool {
        lua_settop(L, 3);
        bool ret = [[WXVoiceRecognizer sharedWXVoice] startOnceWithGrammarString: NSStringMake(olua_checkstring(L, 2)) andType:(WXGrammarType)olua_checkinteger(L, 3)];
        lua_pushboolean(L, ret);
    }
    return 0;
}

static int l_finish(lua_State *L)
{
    @autoreleasepool {
        [[WXVoiceRecognizer sharedWXVoice] finish];
    }
    return 0;
}

static int l_cancel(lua_State *L)
{
    @autoreleasepool {
        [[WXVoiceRecognizer sharedWXVoice] cancel];
    }
    return 0;
}

static int l_startContinusMode(lua_State *L)
{
    @autoreleasepool {
        bool ret = [[WXVoiceRecognizer sharedWXVoice] startContinusMode];
        lua_pushboolean(L, ret);
    }
    return 0;
}

static int l_stopContinusMode(lua_State *L)
{
    @autoreleasepool {
        bool ret = [[WXVoiceRecognizer sharedWXVoice] stopContinusMode];
        lua_pushboolean(L, ret);
    }
    return 0;
}

static int l_setResultType(lua_State *L)
{
    @autoreleasepool {
        lua_settop(L, 2);
        [[WXVoiceRecognizer sharedWXVoice] setResultType: (NSInteger)olua_checkinteger(L, 2)];
    }
    return 0;
}

static int l_startWith16bitPCMData(lua_State *L)
{
    @autoreleasepool {
        bool ret = [[WXVoiceRecognizer sharedWXVoice] startWith16bitPCMData];
        lua_pushboolean(L, ret);
    }
    return 0;
}

static int l_Add16bitPCMData(lua_State *L)
{
    @autoreleasepool {
        size_t len;
        lua_settop(L, 4);
        const char *data = olua_checklstring(L, 2, &len);
        int sample_rate = (int)olua_checkinteger(L, 3);
        bool is_end = olua_optboolean(L, 4, false);
        bool ret = [[WXVoiceRecognizer sharedWXVoice] Add16bitPCMData:[NSData dataWithBytes:(const void *)data length:(NSInteger)len] sampleRate:sample_rate isEnd:is_end];
        lua_pushboolean(L, ret);
    }
    return 0;
}

static int l_finishWith16bitPCMData(lua_State *L)
{
    @autoreleasepool {
        [[WXVoiceRecognizer sharedWXVoice] finishWith16bitPCMData];
    }
    return 0;
}

static int l_startOnceWith16bitPCMData(lua_State *L)
{
    @autoreleasepool {
        size_t len;
        lua_settop(L, 4);
        const char *data = olua_checklstring(L, 2, &len);
        int sample_rate = (int)olua_checkinteger(L, 3);
        bool ret = [[WXVoiceRecognizer sharedWXVoice] startOnceWith16bitPCMData:[NSData dataWithBytes:(const void *)data length:(NSInteger)len] sampleRate:sample_rate];
        lua_pushboolean(L, ret);
    }
    return 0;
}

static int l_get_silTime(lua_State *L)
{
    @autoreleasepool {
        lua_pushnumber(L, [WXVoiceRecognizer sharedWXVoice].silTime);
    }
    return 1;
}

static int l_set_silTime(lua_State *L)
{
    @autoreleasepool {
        lua_settop(L, 2);
        [WXVoiceRecognizer sharedWXVoice].silTime = (float)olua_checknumber(L, 2);
    }
    return 0;
}

static int l_get_domain(lua_State *L)
{
    @autoreleasepool {
        lua_pushinteger(L, [WXVoiceRecognizer sharedWXVoice].domain);
    }
    return 1;
}

static int l_set_domain(lua_State *L)
{
    @autoreleasepool {
        lua_settop(L, 2);
        [WXVoiceRecognizer sharedWXVoice].domain = (int)olua_checkinteger(L, 2);
    }
    return 0;
}

int luaopen_wxvoice(lua_State *L)
{
    oluacls_class(L, CLASS_CONNECTOR, nullptr);
    oluacls_func(L, "__gc", l_gc);
    oluacls_func(L, "init", l_init);
    oluacls_func(L, "setDispatcher", l_setDispatcher);
    oluacls_func(L, "setContinuousMode", l_setContinuousMode);
    oluacls_func(L, "setLanguageType", l_setLanguageType);
    oluacls_func(L, "startOnce", l_startOnce);
    oluacls_func(L, "startOnceWithGrammarString", l_startOnceWithGrammarString);
    oluacls_func(L, "finish", l_finish);
    oluacls_func(L, "cancel", l_cancel);
    oluacls_func(L, "startContinusMode", l_startContinusMode);
    oluacls_func(L, "stopContinusMode", l_stopContinusMode);
    oluacls_func(L, "setResultType", l_setResultType);
    oluacls_func(L, "startWith16bitPCMData", l_startWith16bitPCMData);
    oluacls_func(L, "Add16bitPCMData", l_Add16bitPCMData);
    oluacls_func(L, "finishWith16bitPCMData", l_finishWith16bitPCMData);
    oluacls_func(L, "startOnceWith16bitPCMData", l_startOnceWith16bitPCMData);
    oluacls_prop(L, "silTime", l_get_silTime, l_set_silTime);
    oluacls_prop(L, "domain", l_get_domain, l_set_domain);
    
    xgame::runtime::registerFeature("wxvoice.ios", true);
    
    @autoreleasepool {
        WXVoiceConnector *connector = [[WXVoiceConnector alloc] init];
        olua_push_obj(L, (void *)CFBridgingRetain(connector), CLASS_CONNECTOR);
    }
    return 1;
}
#endif
