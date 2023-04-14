#import "jpush.h"

#ifdef CCLUA_OS_IOS

#import "cclua/AppContext-ios.h"
#import "cclua/plugin-ios.h"
#import "ios/JPUSHService.h"

#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>

#ifdef CCLUA_FEATURE_TRACKING
#import <AdSupport/AdSupport.h>
#import <AppTrackingTransparency/AppTrackingTransparency.h>
#endif

USING_NS_CCLUA;
USING_NS_CCLUA_PLUGIN;

#pragma mark -- jpush --
#ifdef CCLUA_BUILD_JPUSH
@interface JPushDelegate : NSObject<JPUSHRegisterDelegate, UIApplicationDelegate>

@property(strong) NSString *channel;
@property(strong) NSString *appKey;

+ (instancetype) defaultDelegate;

- (void)jpushNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification withCompletionHandler:(void (^)(NSInteger options))completionHandler;
- (void)jpushNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void(^)(void))completionHandler;
- (void)jpushNotificationCenter:(UNUserNotificationCenter *)center openSettingsForNotification:(UNNotification *)notification NS_AVAILABLE_IOS(12.0);
- (void)jpushNotificationAuthorization:(JPAuthorizationStatus)status withInfo:(NSDictionary *)info;

#pragma mark -- UIApplicationDelegate --
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;
- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;
- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error;
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult result))completionHandler;
@end

@implementation JPushDelegate

+ (instancetype) defaultDelegate
{
    static JPushDelegate *inst = nil;
    if (inst == nil) {
        inst = [[JPushDelegate alloc] init];
    }
    return inst;
}

- (void)jpushNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification withCompletionHandler:(void (^)(NSInteger options))completionHandler
{
    if ([notification.request.trigger isKindOfClass:[UNPushNotificationTrigger class]]) {
        [JPUSHService handleRemoteNotification:notification.request.content.userInfo];
    }
    if (@available(iOS 14.0, *)) {
        completionHandler(UNNotificationPresentationOptionList|UNNotificationPresentationOptionBanner);
    } else {
        completionHandler(UNNotificationPresentationOptionAlert);
    }
}

- (void)jpushNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void(^)(void))completionHandler
{
    if ([response.notification.request.trigger isKindOfClass:[UNPushNotificationTrigger class]]) {
        [JPUSHService handleRemoteNotification:response.notification.request.content.userInfo];
    }
    completionHandler();
}

- (void)jpushNotificationCenter:(UNUserNotificationCenter *)center openSettingsForNotification:(UNNotification *)notification
{
}

- (void)jpushNotificationAuthorization:(JPAuthorizationStatus)status withInfo:(NSDictionary *)info
{
}

#pragma mark -- UIApplicationDelegate --
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    JPUSHRegisterEntity *entiry = [[JPUSHRegisterEntity alloc] init];
    entiry.types = JPAuthorizationOptionAlert | JPAuthorizationOptionBadge | JPAuthorizationOptionSound;
    if (@available(iOS 12_0, *)) {
        entiry.types |= JPAuthorizationOptionProvidesAppNotificationSettings;
    }
    [JPUSHService registerForRemoteNotificationConfig:entiry delegate:[JPushDelegate defaultDelegate]];
    NSString *idfa = nil;
#ifdef CCLUA_FEATURE_TRACKING
    idfa = [[[ASIdentifierManager sharedManager] advertisingIdentifier] UUIDString];
#endif
    [JPUSHService setupWithOption:launchOptions appKey:_appKey channel:_channel apsForProduction:YES advertisingIdentifier:idfa];
    runtime::log("init jpush");
    return YES;
}

- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;
{
    return YES;
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken
{
    [JPUSHService registerDeviceToken:deviceToken];
}

- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error
{
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult result))completionHandler
{
    [JPUSHService handleRemoteNotification:userInfo];
    completionHandler(UIBackgroundFetchResultNewData);
}

@end

void jpush::init(const std::string &appKey, const std::string &channel)
{
    @autoreleasepool {
        AppContext *context = (AppContext *)[UIApplication sharedApplication].delegate;
        JPushDelegate *delegate = [JPushDelegate defaultDelegate];
        delegate.appKey = toNSString(appKey);
        delegate.channel = toNSString(channel);
        [context addAppDelegate:delegate];
    }
}

void jpush::setAlias(const std::string &alias)
{
    @autoreleasepool {
        [JPUSHService setAlias:toNSString(alias) completion:^(NSInteger iResCode, NSString *iAlias, NSInteger seq) {
            runtime::log("[JPUSH] set alias: %d %s %d", (int)iResCode, [iAlias UTF8String], (int)seq);
        } seq:0];
    }
}

void jpush::deleteAlias()
{
    @autoreleasepool {
        [JPUSHService deleteAlias:^(NSInteger iResCode, NSString *iAlias, NSInteger seq) {
            runtime::log("[JPUSH] delete alias: %d %s %d", (int)iResCode, [iAlias UTF8String], (int)seq);
        } seq:0];
    }
}

void jpush::addTags(const std::set<std::string> &tags)
{
    @autoreleasepool {
        [JPUSHService addTags:toNSSetString(tags) completion:^(NSInteger iResCode, NSSet *iTags, NSInteger seq) {
            runtime::log("[JPUSH] add tags: %d %s %d", (int)iResCode, [[[iTags allObjects] componentsJoinedByString:@","] UTF8String], (int)seq);
        } seq:0];
    }
}

void jpush::setTags(const std::set<std::string> &tags)
{
    @autoreleasepool {
        [JPUSHService setTags:toNSSetString(tags) completion:^(NSInteger iResCode, NSSet *iTags, NSInteger seq) {
            runtime::log("[JPUSH] set tags: %d %s %d", (int)iResCode, [[[iTags allObjects] componentsJoinedByString:@","] UTF8String], (int)seq);
        } seq:0];
    }
}

void jpush::deleteTags(const std::set<std::string> &tags)
{
    @autoreleasepool {
        [JPUSHService deleteTags:toNSSetString(tags) completion:^(NSInteger iResCode, NSSet *iTags, NSInteger seq) {
            runtime::log("[JPUSH] delete tags: %d %s %d", (int)iResCode, [[[iTags allObjects] componentsJoinedByString:@","] UTF8String], (int)seq);
        } seq:0];
    }
}

void jpush::cleanTags()
{
    @autoreleasepool {
        [JPUSHService cleanTags:^(NSInteger iResCode, NSSet *iTags, NSInteger seq) {
            runtime::log("[JPUSH] clean tags: %d %s %d", (int)iResCode, [[[iTags allObjects] componentsJoinedByString:@","] UTF8String], (int)seq);
        } seq:0];
    }
}

void jpush::setDebug(bool enabled)
{
    @autoreleasepool {
        [JPUSHService setDebugMode];
    }
}

void jpush::setLogOFF()
{
    @autoreleasepool {
        [JPUSHService setLogOFF];
    }
}

void jpush::setBadge(int value)
{
    @autoreleasepool {
        [JPUSHService setBadge:value];
        [[UIApplication sharedApplication] setApplicationIconBadgeNumber:value];
    }
}

std::string jpush::getRegistrationID()
{
    @autoreleasepool {
        return [[JPUSHService registrationID] UTF8String];
    }
}

bool jpush::isEnabled()
{
    @autoreleasepool {
        return [[UIApplication sharedApplication] isRegisteredForRemoteNotifications];
    }
}

void jpush::requestPermission()
{
}

#endif // CCLUA_BUILD_JPUSH


#pragma mark -- jauth --
#ifdef CCLUA_BUILD_JAUTH

Callback jauth::_dispatcher;

@interface JAuthDelegate : NSObject<UIApplicationDelegate>

+ (instancetype) defaultDelegate;

@property(strong) NSString *channel;
@property(strong) NSString *appKey;

#pragma mark -- UIApplicationDelegate --
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

@end

@implementation JAuthDelegate

+ (instancetype) defaultDelegate
{
    static JAuthDelegate *inst = nil;
    if (inst == nil) {
        inst = [[JAuthDelegate alloc] init];
    }
    return inst;
}

#pragma mark -- UIApplicationDelegate --
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    JVAuthConfig *config = [[JVAuthConfig alloc] init];
    config.appKey = _appKey;
    config.channel = _channel;
#ifdef CCLUA_FEATURE_TRACKING
    config.advertisingId = [[[ASIdentifierManager sharedManager] advertisingIdentifier] UUIDString];
#endif
    config.isProduction = YES;
    config.authBlock = ^(NSDictionary *result) {
        NSLog(@"init jauth result:%@", result);
    };
    [JVERIFICATIONService setupWithConfig:config];
    return YES;
}

@end

void jauth::init(const std::string &appKey, const std::string &channel)
{
    @autoreleasepool {
        AppContext *context = (AppContext *)[UIApplication sharedApplication].delegate;
        JAuthDelegate *delegate = [JAuthDelegate defaultDelegate];
        delegate.appKey = toNSString(appKey);
        delegate.channel = toNSString(channel);
        [context addAppDelegate:delegate];
    }
}

bool jauth::isInitSuccess()
{
    @autoreleasepool {
        return [JVERIFICATIONService isSetupClient];
    }
}

void jauth::setDebug(bool enabled)
{
    @autoreleasepool {
        [JVERIFICATIONService setDebug:enabled];
    }
}

bool jauth::checkVerifyEnable()
{
    @autoreleasepool {
        return [JVERIFICATIONService checkVerifyEnable];
    }
}

void jauth::getToken(int timeout)
{
    @autoreleasepool {
        [JVERIFICATIONService getToken:timeout completion:^(NSDictionary *result) {
            cocos2d::ValueMap data;
            data["code"] = (int64_t)[[result objectForKey:@"code"] intValue];
            if ([[result allKeys] containsObject:@"token"]) {
                data["success"] = true;
                data["token"] = [[result objectForKey:@"token"] UTF8String];
                data["operator"] = [[result objectForKey:@"operator"] UTF8String];
            } else {
                data["content"] = [[result objectForKey:@"content"] UTF8String];
            }
            jauth::dispatch("getToken", data);
        }];
    }
}

void jauth::preLogin(int timeout)
{
    @autoreleasepool {
        [JVERIFICATIONService preLogin:timeout completion:^(NSDictionary *result) {
            cocos2d::ValueMap data;
            std::string status;
            data["code"] = (int64_t)[[result objectForKey:@"code"] intValue];
            data["success"] = data["code"].asInt() == 7000;
            data["content"] = [[result objectForKey:@"message"] UTF8String];
            jauth::dispatch("preLogin", data);
        }];
    }
}

void jauth::clearPreLoginCache()
{
    @autoreleasepool {
        [JVERIFICATIONService clearPreLoginCache];
    }
}

void jauth::loginAuth(int timeout)
{
    @autoreleasepool {
        [JVERIFICATIONService getAuthorizationWithController:[[[UIApplication sharedApplication] keyWindow] rootViewController] hide:YES animated:YES timeout:timeout completion:^(NSDictionary *result) {
            cocos2d::ValueMap data;
            data["code"] = (int64_t)[[result objectForKey:@"code"] intValue];
            if ([[result allKeys] containsObject:@"loginToken"]) {
                data["success"] = true;
                data["token"] = [[result objectForKey:@"loginToken"] UTF8String];
                data["operator"] = [[result objectForKey:@"operator"] UTF8String];
            } else {
                data["content"] = [[result objectForKey:@"content"] UTF8String];
            }
            jauth::dispatch("loginAuth", data);
        } actionBlock:^(NSInteger type, NSString *content) {
            NSLog(@"loginAuth actionBlock :%ld %@", (long)type , content);
        }];
    }
}

void jauth::dismissLoginAuth(bool needCloseAnim)
{
    @autoreleasepool {
        [JVERIFICATIONService dismissLoginControllerAnimated:needCloseAnim completion:^{
        }];
    }
}

void jauth::getSmsCode(const std::string &phonenum, const std::string &signid, const std::string &tempid)
{
    @autoreleasepool {
        [JVERIFICATIONService getSMSCode:toNSString(phonenum) templateID:toNSString(tempid) signID:toNSString(signid) completionHandler:^(NSDictionary * _Nonnull result) {
            cocos2d::ValueMap data;
            data["code"] = (int64_t)[[result objectForKey:@"code"] intValue];
            data["success"] = data["code"].asInt() == 3000;
            data["content"] = [[result objectForKey:@"msg"] UTF8String];
            if (data["success"].asBool()) {
                data["uuid"] = [[result objectForKey:@"uuid"] UTF8String];
            }
            jauth::dispatch("getSmsCode", data);
        }];
    }
}

void jauth::setSmsIntervalTime(int64_t intervalTime)
{
    @autoreleasepool {
        [JVERIFICATIONService setGetCodeInternal:intervalTime];
    }
}

static UIColor *toUIColor(cocos2d::Value &value)
{
    UInt32 color = (UInt32)value.asInt();
    return [UIColor colorWithRed:(color >> 24 & 0xff) / 255.0f
                           green:(color >> 16 & 0xff) / 255.0f
                            blue:(color >> 8 & 0xff) / 255.0f
                           alpha:(color & 0xff) / 255.0f];
}

static inline NSAttributedString *toNSAttributedString(cocos2d::Value &value)
{
    return [[NSAttributedString alloc] initWithString:toNSString(value)];
}

static inline UIImage* toUIImage(cocos2d::Value &value)
{
    UIImage *img = [UIImage imageWithContentsOfFile:toNSString(value)];
    if (!img) {
        img = [UIImage imageNamed:toNSString(value)];
    }
    return img;
}

static inline BOOL toBool(cocos2d::Value &value)
{
    return value.asBool();
}

static inline CGFloat toCGFloat(cocos2d::Value &value)
{
    return (CGFloat)value.asFloat();
}

static UIEdgeInsets toUIEdgeInsets(cocos2d::Value &value)
{
    cocos2d::ValueMap &map = value.asValueMap();
    return UIEdgeInsetsMake(toCGFloat(map["top"]), toCGFloat(map["left"]), toCGFloat(map["bottom"]), toCGFloat(map["right"]));
}

static NSArray *toPrivacyColor(cocos2d::Value &value)
{
    cocos2d::ValueVector &arr = value.asValueVector();
    CCASSERT(arr.size() >= 2, "privacy color error");
    return [NSArray arrayWithObjects:toUIColor(arr[0]), toUIColor(arr[1]), nil];
}

static NSArray *toImages(cocos2d::Value &value)
{
    NSMutableArray *arr = [[NSMutableArray alloc] init];
    for (auto &v : value.asValueVector()) {
        [arr addObject:toUIImage(v)];
    }
    return arr;
}

static NSArray *toStrings(cocos2d::Value &value)
{
    NSMutableArray *arr = [[NSMutableArray alloc] init];
    for (auto &v : value.asValueVector()) {
        [arr addObject:toNSString(v)];
    }
    return arr;
}

static NSArray *toConstraints(cocos2d::Value &value)
{
    NSMutableArray *arr = [[NSMutableArray alloc] init];
    for (auto &v : value.asValueVector()) {
        cocos2d::ValueVector &args = v.asValueVector();
        args.resize(6);
        JVLayoutConstraint *c = [JVLayoutConstraint constraintWithAttribute:(NSLayoutAttribute)args[0].asInt() relatedBy:(NSLayoutRelation)args[1].asInt() toItem:(JVLayoutItem)args[2].asInt() attribute:(NSLayoutAttribute)args[3].asInt() multiplier:(CGFloat)args[4].asFloat() constant:(CGFloat)args[5].asFloat()];
        [arr addObject:c];
    }
    return arr;
}

#define setValue(NAME, FUNC) do {                   \
    if (value.find(#NAME) != value.end())           \
        config.NAME = FUNC(value[#NAME]);           \
} while (0)

#define setEnum(NAME, ENUM) do {                    \
    if (value.find(#NAME) != value.end())           \
        config.NAME = (ENUM)value[#NAME].asInt();   \
} while (0)

static CGFloat getCGFloat(cocos2d::ValueMap &value, const std::string &key, CGFloat defaultValue)
{
    if (value.find(key) != value.end()) {
        return toCGFloat(value[key]);
    } else {
        return defaultValue;
    }
}

static JVUIConfig *getFullScreenLandscapeConfig(cocos2d::ValueMap &value)
{
    UIView *view = [[[[UIApplication sharedApplication] keyWindow] rootViewController] view];
    JVUIConfig *config = [[JVUIConfig alloc] init];
    config.navReturnImg = [UIImage imageNamed:@"back"];
    config.agreementNavReturnImage = [UIImage imageNamed:@"close"];
    config.autoLayout = YES;
    config.navText = [[NSAttributedString alloc] initWithString:@""];
    config.navDividingLineHidden = YES;
    config.prefersStatusBarHidden = NO;
    config.privacyComponents = @[@"同意《",@"",@"",@"》并授权此应用获取本机号码"];

    config.navColor = [UIColor whiteColor];
    config.sloganTextColor = [UIColor colorWithRed:187/255.0 green:188/255.0 blue:197/255.0 alpha:1/1.0];
    //logo
    config.logoImg = [UIImage imageNamed:@"logo_icon"];
    CGFloat logoWidth = 76;
    CGFloat logoHeight = logoWidth;
    CGFloat windowW = view.frame.size.width;
    JVLayoutConstraint *logoConstraintX = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeCenterX relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSuper attribute:NSLayoutAttributeCenterX multiplier:1 constant:0];
    JVLayoutConstraint *logoConstraintY = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeTop relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSuper attribute:NSLayoutAttributeTop multiplier:1 constant:76];
    JVLayoutConstraint *logoConstraintW = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeWidth relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeWidth multiplier:1 constant:logoWidth];
    JVLayoutConstraint *logoConstraintH = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeHeight relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeHeight multiplier:1 constant:logoHeight];
    config.logoConstraints = @[logoConstraintX,logoConstraintY,logoConstraintW,logoConstraintH];
    
    //横屏
    JVLayoutConstraint *logoConstraintY1 = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeTop relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSuper attribute:NSLayoutAttributeTop multiplier:1 constant:20];

    config.logoHorizontalConstraints = @[logoConstraintX,logoConstraintY1,logoConstraintH,logoConstraintW];
    
    
    //号码栏
    JVLayoutConstraint *numberConstraintX = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeCenterX relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSuper attribute:NSLayoutAttributeCenterX multiplier:1 constant:0];
    JVLayoutConstraint *numberConstraintY = [JVLayoutConstraint constraintWithAttribute: NSLayoutAttributeTop relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemLogo attribute:NSLayoutAttributeBottom multiplier:1 constant:16];
    JVLayoutConstraint *numberConstraintW = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeWidth relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeWidth multiplier:1 constant:130];
    JVLayoutConstraint *numberConstraintH = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeHeight relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeHeight multiplier:1 constant:25];

    config.numberConstraints = @[numberConstraintX,numberConstraintY,numberConstraintW,numberConstraintH];
    
    //slogan展示
    JVLayoutConstraint *sloganConstraintX = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeCenterX relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSuper attribute:NSLayoutAttributeCenterX multiplier:1 constant:0];
    JVLayoutConstraint *sloganConstraintY = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeTop relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNumber attribute:NSLayoutAttributeBottom   multiplier:1 constant:8];
    JVLayoutConstraint *sloganConstraintW = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeWidth relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeWidth multiplier:1 constant:130];
    JVLayoutConstraint *sloganConstraintH = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeHeight relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeHeight multiplier:1 constant:20];
    
    config.sloganConstraints = @[sloganConstraintX,sloganConstraintY,sloganConstraintW,sloganConstraintH];
    
    
    //登录按钮
    UIImage *login_nor_image = [UIImage imageNamed:@"btn_42px"];
    UIImage *login_dis_image = [UIImage imageNamed:@"btn_42px_null"];
    UIImage *login_hig_image = [UIImage imageNamed:@"btn_42px"];
    if (login_nor_image && login_dis_image && login_hig_image) {
        config.logBtnImgs = @[login_nor_image, login_dis_image, login_hig_image];
    }
    config.logBtnText = @"一键登录";
    CGFloat loginButtonWidth = 260;
    CGFloat loginButtonHeight = 42;
    JVLayoutConstraint *loginConstraintX = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeCenterX relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSuper attribute:NSLayoutAttributeCenterX multiplier:1 constant:0];
    JVLayoutConstraint *loginConstraintY = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeTop relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSlogan attribute:NSLayoutAttributeBottom multiplier:1 constant:22];
    JVLayoutConstraint *loginConstraintW = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeWidth relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeWidth multiplier:1 constant:loginButtonWidth];
    JVLayoutConstraint *loginConstraintH = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeHeight relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeHeight multiplier:1 constant:loginButtonHeight];
    config.logBtnConstraints = @[loginConstraintX,loginConstraintY,loginConstraintW,loginConstraintH];
    
    //勾选框
    
    UIImage * uncheckedImg = [UIImage imageNamed:@"checkBox_unSelected"];
    UIImage * checkedImg = [UIImage imageNamed:@"checkBox_selected"];
    CGFloat checkViewWidth = 11;
    CGFloat checkViewHeight = 11;
    CGFloat spacing = (windowW - 300)/2;

    config.uncheckedImg = uncheckedImg;
    config.checkedImg = checkedImg;
    JVLayoutConstraint *checkViewConstraintX = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeLeft relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSuper attribute:NSLayoutAttributeRight multiplier:1 constant:spacing];
    JVLayoutConstraint *checkViewConstraintY = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeBottom relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemPrivacy attribute:NSLayoutAttributeBottom multiplier:1 constant:-20];
    
    JVLayoutConstraint *checkViewConstraintW = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeWidth relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeWidth multiplier:1 constant:checkViewWidth];
    JVLayoutConstraint *checkViewConstraintH = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeHeight relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeHeight multiplier:1 constant:checkViewHeight];
    config.checkViewConstraints = @[checkViewConstraintX,checkViewConstraintY,checkViewConstraintW,checkViewConstraintH];
    //隐私
    config.privacyState = YES;
    config.privacyTextFontSize = 11;
    config.privacyTextAlignment = NSTextAlignmentCenter;
    config.appPrivacyColor = @[[UIColor colorWithRed:187/255.0 green:188/255.0 blue:197/255.0 alpha:1/1.0],[UIColor colorWithRed:137/255.0 green:152/255.0 blue:255/255.0 alpha:1/1.0]];
    
    JVLayoutConstraint *privacyConstraintX = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeCenterX relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSuper attribute:NSLayoutAttributeCenterX multiplier:1 constant:0];
    JVLayoutConstraint *privacyConstraintW = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeWidth relatedBy:NSLayoutRelationGreaterThanOrEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeWidth multiplier:1 constant:400];

    JVLayoutConstraint *privacyConstraintY = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeBottom relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSuper attribute:NSLayoutAttributeBottom multiplier:1 constant:-25];
    JVLayoutConstraint *privacyConstraintH = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeHeight relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeHeight multiplier:1 constant:14];
    
    
    config.privacyConstraints = @[privacyConstraintX,privacyConstraintW,privacyConstraintY,privacyConstraintH];
    
    JVLayoutConstraint *privacyConstraintY1 = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeBottom relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSuper attribute:NSLayoutAttributeBottom multiplier:1 constant:-16];

    config.privacyHorizontalConstraints = @[privacyConstraintX,privacyConstraintW,privacyConstraintH,privacyConstraintY1];
    
    //loading
    JVLayoutConstraint *loadingConstraintX = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeCenterX relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSuper attribute:NSLayoutAttributeCenterX multiplier:1 constant:0];
    JVLayoutConstraint *loadingConstraintY = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeCenterY relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSuper attribute:NSLayoutAttributeCenterY multiplier:1 constant:0];
    JVLayoutConstraint *loadingConstraintW = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeWidth relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeWidth multiplier:1 constant:30];
    JVLayoutConstraint *loadingConstraintH = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeHeight relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeHeight multiplier:1 constant:30];
    config.loadingConstraints = @[loadingConstraintX,loadingConstraintY,loadingConstraintW,loadingConstraintH];
    return config;
}

static JVUIConfig *getDialogPortraitConfig(cocos2d::ValueMap &value)
{
    JVUIConfig *config = [[JVUIConfig alloc] init];
    config.navCustom = YES;
    config.autoLayout = YES;
    config.modalTransitionStyle =  UIModalTransitionStyleCrossDissolve;
    config.agreementNavReturnImage = [UIImage imageNamed:@"close"];

    //弹框
    config.showWindow = YES;

    config.windowBackgroundAlpha = 0.3;
    config.windowCornerRadius = 6;

    config.sloganTextColor = [UIColor colorWithRed:187/255.0 green:188/255.0 blue:197/255.0 alpha:1/1.0];
    config.privacyComponents = @[@"同意《",@"",@"",@"》并授权此应用获取本机号码"];
    CGFloat windowW = getCGFloat(value, "windowWidth", 320);
    CGFloat windowH = getCGFloat(value, "windowHeight", 260);
    JVLayoutConstraint *windowConstraintX = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeCenterX relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSuper attribute:NSLayoutAttributeCenterX multiplier:1 constant:0];
    JVLayoutConstraint *windowConstraintY = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeCenterY relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSuper attribute:NSLayoutAttributeCenterY multiplier:1 constant:0];

    JVLayoutConstraint *windowConstraintW = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeWidth relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeWidth multiplier:1 constant:windowW];
    JVLayoutConstraint *windowConstraintH = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeHeight relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeHeight multiplier:1 constant:windowH];
    config.windowConstraints = @[windowConstraintY,windowConstraintH,windowConstraintX,windowConstraintW];
    
    JVLayoutConstraint *windowConstraintW1 = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeWidth relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeWidth multiplier:1 constant:480];
    JVLayoutConstraint *windowConstraintH1 = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeHeight relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeHeight multiplier:1 constant:250];

    
    config.windowHorizontalConstraints =@[windowConstraintY,windowConstraintH1,windowConstraintX,windowConstraintW1];
    
    //弹窗close按钮
    UIImage *window_close_nor_image = [UIImage imageNamed:@"close_icon"];
    UIImage *window_close_hig_image = [UIImage imageNamed:@"close_icon"];
    if (window_close_nor_image && window_close_hig_image) {
        config.windowCloseBtnImgs = @[window_close_nor_image, window_close_hig_image];
    }
    CGFloat windowCloseBtnWidth = 30;
    CGFloat windowCloseBtnHeight = 30;
    JVLayoutConstraint *windowCloseBtnConstraintX = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeRight relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSuper attribute:NSLayoutAttributeRight multiplier:1 constant:-5];
    JVLayoutConstraint *windowCloseBtnConstraintY = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeTop relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSuper attribute:NSLayoutAttributeTop multiplier:1 constant:5];
    JVLayoutConstraint *windowCloseBtnConstraintW = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeWidth relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeWidth multiplier:1 constant:windowCloseBtnWidth];
    JVLayoutConstraint *windowCloseBtnConstraintH = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeHeight relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeHeight multiplier:1 constant:windowCloseBtnHeight];
    config.windowCloseBtnConstraints = @[windowCloseBtnConstraintX,windowCloseBtnConstraintY,windowCloseBtnConstraintW,windowCloseBtnConstraintH];
    
    
    //logo
    config.logoImg = [UIImage imageNamed:@"logo_icon"];
    CGFloat logoWidth = 105;
    CGFloat logoHeight = 26;
    JVLayoutConstraint *logoConstraintX = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeCenterX relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSuper attribute:NSLayoutAttributeCenterX multiplier:1 constant:0];
    JVLayoutConstraint *logoConstraintY = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeTop relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSuper attribute:NSLayoutAttributeTop multiplier:1 constant:40];
    JVLayoutConstraint *logoConstraintW = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeWidth relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeWidth multiplier:1 constant:logoWidth];
    JVLayoutConstraint *logoConstraintH = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeHeight relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeHeight multiplier:1 constant:logoHeight];
    config.logoConstraints = @[logoConstraintX,logoConstraintY,logoConstraintW,logoConstraintH];
    
    JVLayoutConstraint *logoConstraintLeft = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeLeft relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSuper attribute:NSLayoutAttributeLeft multiplier:1 constant:16];
    
    JVLayoutConstraint *logoConstraintTop = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeTop relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSuper attribute:NSLayoutAttributeTop multiplier:1 constant:11];
    
    config.logoHorizontalConstraints = @[logoConstraintLeft,logoConstraintTop,logoConstraintW,logoConstraintH];
    
    
    //号码栏
    JVLayoutConstraint *numberConstraintX = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeCenterX relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSuper attribute:NSLayoutAttributeCenterX multiplier:1 constant:0];
    JVLayoutConstraint *numberConstraintY = [JVLayoutConstraint constraintWithAttribute: NSLayoutAttributeTop relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemLogo attribute:NSLayoutAttributeBottom multiplier:1 constant:14];

    JVLayoutConstraint *numberConstraintH = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeHeight relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeHeight multiplier:1 constant:28];
    JVLayoutConstraint *numberConstraintW = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeWidth relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeWidth multiplier:1 constant:200];

    JVLayoutConstraint *numberConstraintY1 = [JVLayoutConstraint constraintWithAttribute: NSLayoutAttributeTop relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemLogo attribute:NSLayoutAttributeBottom multiplier:1 constant:39];

    config.numberConstraints = @[numberConstraintX,numberConstraintY,numberConstraintH,numberConstraintW];
    config.numberHorizontalConstraints = @[numberConstraintX,numberConstraintY1,numberConstraintH,numberConstraintW];

    //slogan展示
    JVLayoutConstraint *sloganConstraintX = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeCenterX relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSuper attribute:NSLayoutAttributeCenterX multiplier:1 constant:0];
    JVLayoutConstraint *sloganConstraintY = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeTop relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNumber attribute:NSLayoutAttributeBottom   multiplier:1 constant:4];
    JVLayoutConstraint *sloganConstraintH = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeHeight relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeHeight multiplier:1 constant:17];
    JVLayoutConstraint *sloganConstraintW = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeWidth relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeWidth multiplier:1 constant:200];

    config.sloganConstraints = @[sloganConstraintX,sloganConstraintY,sloganConstraintW,sloganConstraintH];
    
    //登录按钮
    UIImage *login_nor_image = [UIImage imageNamed:@"btn_38px"];
    UIImage *login_dis_image = [UIImage imageNamed:@"btn_38px_ull"];
    UIImage *login_hig_image = [UIImage imageNamed:@"btn_38px"];
    if (login_nor_image && login_dis_image && login_hig_image) {
        config.logBtnImgs = @[login_nor_image, login_dis_image, login_hig_image];
    }
    config.logBtnText = @"一键登录";
    CGFloat loginButtonWidth = 220;
    CGFloat loginButtonHeight = 38;
    JVLayoutConstraint *loginConstraintX = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeCenterX relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSuper attribute:NSLayoutAttributeCenterX multiplier:1 constant:0];
    JVLayoutConstraint *loginConstraintY = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeTop relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSlogan attribute:NSLayoutAttributeBottom multiplier:1 constant:10];
    JVLayoutConstraint *loginConstraintW = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeWidth relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeWidth multiplier:1 constant:loginButtonWidth];
    JVLayoutConstraint *loginConstraintH = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeHeight relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeHeight multiplier:1 constant:loginButtonHeight];
    JVLayoutConstraint *loginConstraintY1 = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeTop relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSlogan attribute:NSLayoutAttributeBottom multiplier:1 constant:13];
    config.logBtnConstraints = @[loginConstraintX,loginConstraintY,loginConstraintW,loginConstraintH];
    config.logBtnHorizontalConstraints = @[loginConstraintX,loginConstraintY1,loginConstraintW,loginConstraintH];
    //勾选框
    config.checkViewHidden = YES;
    //隐私
    config.privacyState = YES;
    config.privacyTextFontSize = 10;
    config.privacyTextAlignment = NSTextAlignmentCenter;
    config.appPrivacyColor = @[[UIColor colorWithRed:187/255.0 green:188/255.0 blue:197/255.0 alpha:1/1.0],[UIColor colorWithRed:137/255.0 green:152/255.0 blue:255/255.0 alpha:1/1.0]];
    JVLayoutConstraint *privacyConstraintX = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeCenterX relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSuper attribute:NSLayoutAttributeCenterX multiplier:1 constant:0];
    JVLayoutConstraint *privacyConstraintW = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeWidth relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeWidth multiplier:1 constant:180];
    JVLayoutConstraint *privacyConstraintY = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeBottom relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSuper attribute:NSLayoutAttributeBottom multiplier:1 constant:-21];
    JVLayoutConstraint *privacyConstraintH = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeHeight relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeHeight multiplier:1 constant:32];
    JVLayoutConstraint *privacyConstraintY1 = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeBottom relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSuper attribute:NSLayoutAttributeBottom multiplier:1 constant:-23];
    JVLayoutConstraint *privacyConstraintH1 = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeHeight relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeHeight multiplier:1 constant:14];
    JVLayoutConstraint *privacyConstraintW1 = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeWidth relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeWidth multiplier:1 constant:400];
    config.privacyConstraints = @[privacyConstraintX,privacyConstraintY,privacyConstraintH,privacyConstraintW];
    config.privacyHorizontalConstraints = @[privacyConstraintX,privacyConstraintY1,privacyConstraintH1,privacyConstraintW1];
    //loading
    JVLayoutConstraint *loadingConstraintX = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeCenterX relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSuper attribute:NSLayoutAttributeCenterX multiplier:1 constant:0];
    JVLayoutConstraint *loadingConstraintY = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeCenterY relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemSuper attribute:NSLayoutAttributeCenterY multiplier:1 constant:0];
    JVLayoutConstraint *loadingConstraintW = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeWidth relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeWidth multiplier:1 constant:30];
    JVLayoutConstraint *loadingConstraintH = [JVLayoutConstraint constraintWithAttribute:NSLayoutAttributeHeight relatedBy:NSLayoutRelationEqual toItem:JVLayoutItemNone attribute:NSLayoutAttributeHeight multiplier:1 constant:30];
    config.loadingConstraints = @[loadingConstraintX,loadingConstraintY,loadingConstraintW,loadingConstraintH];
    
    [JVERIFICATIONService customUIWithConfig:config customViews:^(UIView *customAreaView) {
        
    }];
    return config;
}

void jauth::configUI(const cocos2d::ValueMap &data, bool landscape)
{
    @autoreleasepool {
        cocos2d::ValueMap &value = *const_cast<cocos2d::ValueMap *>(&data);
        JVUIConfig *config = landscape ? getFullScreenLandscapeConfig(value) : getDialogPortraitConfig(value);
        setValue(authPageBackgroundImage, toUIImage);
        setValue(authPageGifImagePath, toNSString);
        setValue(autoLayout, toBool);
        setValue(shouldAutorotate, toBool);
        setEnum(orientation, UIInterfaceOrientation);
        setEnum(modalTransitionStyle, UIModalTransitionStyle);
        setValue(dismissAnimationFlag, toBool);
        setValue(navCustom, toBool);
        setValue(navColor, toUIColor);
        setEnum(preferredStatusBarStyle, UIStatusBarStyle);
        setValue(navText, toNSAttributedString);
        setValue(navReturnImg, toUIImage);
        setValue(prefersStatusBarHidden, toBool);
        setValue(navTransparent, toBool);
        setValue(navReturnHidden, toBool);
        setValue(navReturnImageEdgeInsets, toUIEdgeInsets);
        setValue(navDividingLineHidden, toBool);
        setValue(navBarBackGroundImage, toUIImage);
        setValue(logoImg, toUIImage);
        setValue(logoConstraints, toConstraints);
        setValue(logoHorizontalConstraints, toConstraints);
        setValue(logoHidden, toBool);
        setValue(logBtnText, toNSString);
        setValue(logBtnConstraints, toConstraints);
        setValue(logBtnHorizontalConstraints, toConstraints);
        setValue(logBtnTextColor, toUIColor);
        setValue(logBtnImgs, toImages);
        setValue(numberColor, toUIColor);
        setValue(numberSize, toCGFloat);
        setValue(numberConstraints, toConstraints);
        setValue(numberHorizontalConstraints, toConstraints);
        setValue(uncheckedImg, toUIImage);
        setValue(checkedImg, toUIImage);
        setValue(checkViewHidden, toBool);
        setValue(checkViewConstraints, toConstraints);
        setValue(checkViewHorizontalConstraints, toConstraints);
        setValue(privacyState, toBool);
        setValue(appPrivacyOne, toStrings);
        setValue(appPrivacyTwo, toStrings);
        setValue(appPrivacyColor, toPrivacyColor);
        setValue(privacyTextFontSize, toCGFloat);
        setValue(privacyComponents, toStrings);
        setValue(privacyTextFontSize, toCGFloat);
        setValue(privacyShowBookSymbol, toBool);
        setValue(privacyLineSpacing, toCGFloat);
        setValue(privacyConstraints, toConstraints);
        setValue(privacyHorizontalConstraints, toConstraints);
        setValue(agreementNavBackgroundColor, toUIColor);
        setValue(agreementNavText, toNSAttributedString);
        setValue(firstPrivacyAgreementNavText, toNSAttributedString);
        setValue(secondPrivacyAgreementNavText, toNSAttributedString);
        setValue(agreementNavReturnImage, toUIImage);
        setEnum(agreementPreferredStatusBarStyle, UIStatusBarStyle);
        setValue(sloganTextColor, toUIColor);
        setValue(sloganConstraints, toConstraints);
        setValue(sloganHorizontalConstraints, toConstraints);
        setValue(loadingConstraints, toConstraints);
        setValue(loadingHorizontalConstraints, toConstraints);
        setValue(showWindow, toBool);
        setValue(windowBackgroundImage, toUIImage);
        setValue(windowBackgroundAlpha, toCGFloat);
        setValue(windowCornerRadius, toCGFloat);
        setValue(windowCloseBtnImgs, toImages);
        setValue(windowConstraints, toConstraints);
        setValue(windowHorizontalConstraints, toConstraints);
        setValue(windowCloseBtnConstraints, toConstraints);
        setValue(windowCloseBtnHorizontalConstraints, toConstraints);
        [JVERIFICATIONService customUIWithConfig:config];
    }
}

#endif // CCLUA_BUILD_JAUTH

#endif // CCLUA_OS_IOS
