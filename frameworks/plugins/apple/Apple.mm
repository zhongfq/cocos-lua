#import "Apple.h"
#import "cclua/plugin-ios.h"

#if defined(CCLUA_OS_IOS)

USING_NS_CCLUA;
USING_NS_CCLUA_PLUGIN;

#import <AuthenticationServices/AuthenticationServices.h>

@interface AppleDelegate : NSObject<ASAuthorizationControllerDelegate, ASAuthorizationControllerPresentationContextProviding>

@property AppleAuth::AuthCallback callback;

+ (instancetype) defaultDelegate;

- (void)authorizationController:(ASAuthorizationController *)controller didCompleteWithAuthorization:(ASAuthorization *)authorization API_AVAILABLE(ios(13.0));
- (void)authorizationController:(ASAuthorizationController *)controller didCompleteWithError:(NSError *)error API_AVAILABLE(ios(13.0));

- (ASPresentationAnchor)presentationAnchorForAuthorizationController:(ASAuthorizationController *)controller API_AVAILABLE(ios(13.0));
@end

static NSString *objectToJSONString(NSObject *obj)
{
    NSData *data = [NSJSONSerialization dataWithJSONObject:obj options:0 error:nil];
    return [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
}

@implementation AppleDelegate

+ (instancetype) defaultDelegate
{
    static AppleDelegate *inst = nil;
    if (inst == nil) {
        inst = [[AppleDelegate alloc] init];
    }
    return inst;
}

- (void)authorizationController:(ASAuthorizationController *)controller didCompleteWithAuthorization:(ASAuthorization *)authorization
{
     @autoreleasepool {
         cocos2d::ValueMap data;
         if ([authorization.provider isKindOfClass:[ASAuthorizationAppleIDProvider class]]) {
             ASAuthorizationAppleIDCredential *credential = authorization.credential;
             setValueMap(data, "user", toValue(credential.user));
             setValueMap(data, "state", toValue(credential.state));
             setValueMap(data, "email", toValue(credential.email));
             setValueMap(data, "identityToken", toValue(credential.identityToken));
             setValueMap(data, "authorizationCode", toValue(credential.authorizationCode));
             setValueMap(data, "nickname", toValue(credential.fullName ? credential.fullName.nickname : nil));
         } else if ([authorization.credential isKindOfClass:[ASAuthorizationPasswordProvider class]]) {
             ASPasswordCredential *credential = authorization.credential;
             setValueMap(data, "account", toValue(credential.user));
             setValueMap(data, "password", toValue(credential.password));
         }
         runtime::runOnCocosThread([=]() {
             if (self.callback) {
                 self.callback(data);
             }
         });
     }
}

- (void)authorizationController:(ASAuthorizationController *)controller didCompleteWithError:(NSError *)error
{
    @autoreleasepool {
        cclua::runtime::log("apple auth error: errcode=%d", (int)error.code);
        cocos2d::ValueMap data;
        data["errcode"] = cocos2d::Value((unsigned int)error.code);
        runtime::runOnCocosThread([=]() {
            if (self.callback) {
                self.callback(data);
            }
        });
    }
}

- (ASPresentationAnchor)presentationAnchorForAuthorizationController:(ASAuthorizationController *)controller
{
    return [[UIApplication sharedApplication] keyWindow];
}

@end

bool AppleAuth::canMakeAuth()
{
    if (@available(iOS 13.0, *)) {
        return true;
    } else {
        return false;
    }
}

void AppleAuth::auth(const AuthCallback &callback)
{
    if (@available(iOS 13.0, *)) {
        AppleDelegate *delegate = [AppleDelegate defaultDelegate];
        ASAuthorizationAppleIDProvider *provider = [ASAuthorizationAppleIDProvider new];
        ASAuthorizationAppleIDRequest *request = [provider createRequest];
        [request setRequestedScopes:@[ASAuthorizationScopeFullName, ASAuthorizationScopeEmail]];
        ASAuthorizationController *controller = [[ASAuthorizationController alloc] initWithAuthorizationRequests:@[request]];
        controller.delegate = delegate;
        controller.presentationContextProvider = delegate;
        delegate.callback = callback;
        [controller performRequests];
    } else {
        CCASSERT(false, "not support");
    }
}

#endif
