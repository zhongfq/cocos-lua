#include "lua_apple.h"

#ifdef CCLUA_OS_IOS
#import "cclua/PluginConnector.h"
#import <AuthenticationServices/AuthenticationServices.h>

#ifdef CCLUA_FEATURE_IDFA
#import <AdSupport/AdSupport.h>
#import <AppTrackingTransparency/AppTrackingTransparency.h>
#endif

@interface AppleConnector : PluginConnector<ASAuthorizationControllerDelegate, ASAuthorizationControllerPresentationContextProviding>

- (void)authorizationController:(ASAuthorizationController *)controller didCompleteWithAuthorization:(ASAuthorization *)authorization API_AVAILABLE(ios(13.0));
- (void)authorizationController:(ASAuthorizationController *)controller didCompleteWithError:(NSError *)error API_AVAILABLE(ios(13.0));

- (ASPresentationAnchor)presentationAnchorForAuthorizationController:(ASAuthorizationController *)controller API_AVAILABLE(ios(13.0));
@end

static NSString *objectToJSONString(NSObject *obj)
{
    NSData *data = [NSJSONSerialization dataWithJSONObject:obj options:0 error:nil];
    return [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
}

@implementation AppleConnector

- (void)authorizationController:(ASAuthorizationController *)controller didCompleteWithAuthorization:(ASAuthorization *)authorization
{
     @autoreleasepool {
         if ([authorization.provider isKindOfClass:[ASAuthorizationAppleIDProvider class]]) {
             ASAuthorizationAppleIDCredential *credential = authorization.credential;
             NSMutableDictionary *info = [NSMutableDictionary new];
             [info setValue:credential.user forKey:@"user"];
             [info setValue:credential.state forKey:@"state"];
             [info setValue:credential.email forKey:@"email"];
             [info setValue:[[NSString alloc] initWithData:credential.identityToken encoding:NSUTF8StringEncoding] forKey:@"identityToken"];
             [info setValue:[[NSString alloc] initWithData:credential.authorizationCode encoding:NSUTF8StringEncoding] forKey:@"authorizationCode"];
             [self dispatch:@"auth" withMessage:objectToJSONString(info)];
         } else if ([authorization.credential isKindOfClass:[ASAuthorizationPasswordProvider class]]) {
             ASPasswordCredential *credential = authorization.credential;
             NSString *account = credential.user;
             NSString *password = credential.password;
             [self dispatch:@"auth" withMessage:objectToJSONString(@{
                 @"account": account,
                 @"password": password
             })];
         }
     }
}

- (void)authorizationController:(ASAuthorizationController *)controller didCompleteWithError:(NSError *)error
{
    @autoreleasepool {
        cclua::runtime::log("apple auth error: errcode=%d", (int)error.code);
        [self dispatch:@"auth" withMessage:objectToJSONString(@{@"errcode":[NSNumber numberWithInteger:error.code]})];
    }
}

- (ASPresentationAnchor)presentationAnchorForAuthorizationController:(ASAuthorizationController *)controller
{
    return [[UIApplication sharedApplication] keyWindow];
}

@end

#define CLASS_CONNECTOR "AppleConnector*"
#define olua_checkconnector(L, i) ((__bridge AppleConnector *)olua_checkobj(L, i, CLASS_CONNECTOR))
#define NSStringMake(str) (str == NULL ? nil : @(str))

static int l__gc(lua_State *L)
{
    @autoreleasepool {
        AppleConnector *connector = olua_checkconnector(L, 1);
        CFBridgingRelease((__bridge CFTypeRef)connector);
    }
    return 0;
}

static int l_setDispatcher(lua_State *L)
{
    @autoreleasepool {
        lua_settop(L, 2);
        AppleConnector *connector = olua_checkconnector(L, 1);
        void *cb_store = (__bridge void *)connector;
        std::string func = olua_setcallback(L, cb_store, 2, "dispatcher", OLUA_TAG_REPLACE);
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

static int l_auth(lua_State *L)
{
    @autoreleasepool {
        AppleConnector *connector = olua_checkconnector(L, 1);
        if (@available(iOS 13.0, *)) {
            ASAuthorizationAppleIDProvider *provider = [ASAuthorizationAppleIDProvider new];
            ASAuthorizationAppleIDRequest *request = [provider createRequest];
            [request setRequestedScopes:@[ASAuthorizationScopeFullName, ASAuthorizationScopeEmail]];
            
            ASAuthorizationController *controller = [[ASAuthorizationController alloc] initWithAuthorizationRequests:@[request]];
            controller.delegate = connector;
            controller.presentationContextProvider = connector;
            [controller performRequests];
        } else {
            luaL_error(L, "apple auth only support ios 13");
        }
    }
    return 0;
}

static int l_canMakeAuth(lua_State *L)
{
    if (@available(iOS 13.0, *)) {
        lua_pushboolean(L, true);
    } else {
        lua_pushboolean(L, false);
    }
    return 1;
}

static int l_idfa(lua_State *L)
{
#ifdef CCLUA_FEATURE_IDFA
    NSString *idfa = [[[ASIdentifierManager sharedManager] advertisingIdentifier] UUIDString];
    lua_pushstring(L, [idfa UTF8String]);
#else
    lua_pushstring(L, "00000000-0000-0000-0000-000000000000");
#endif
    return 1;
}

LUALIB_API int luaopen_apple(lua_State *L)
{
    oluacls_class(L, CLASS_CONNECTOR, nullptr);
    oluacls_func(L, "__gc", l__gc);
    oluacls_func(L, "setDispatcher", l_setDispatcher);
    oluacls_func(L, "canMakeAuth", l_canMakeAuth);
    oluacls_func(L, "auth", l_auth);
    oluacls_prop(L, "idfa", l_idfa, NULL);
    
    if (@available(iOS 13.0, *)) {
        cclua::runtime::registerFeature("apple.ios", true);
        @autoreleasepool {
            AppleConnector *connector = [AppleConnector new];
            olua_push_obj(L, (void *)CFBridgingRetain(connector), CLASS_CONNECTOR);
        }
    } else {
         luaL_requiref(L, lua_tostring(L, 1), xlua_nonsupport, false);
    }
    
    return 1;
}
#endif
