#import "JiGuang.h"

#ifdef CCLUA_OS_IOS

#import "cclua/AppContext-ios.h"
#import "cclua/plugin-ios.h"
#import "JPUSHService.h"
#import "JANALYTICSService.h"

#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>

USING_NS_CCLUA;

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
#ifdef CCLUA_FEATURE_IDFA
    idfa = [NSString stringWithUTF8String:runtime::getIDFA().c_str()];
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

NS_CCLUA_PLUGIN_BEGIN

void JPush::init(const std::string &appKey, const std::string &channel)
{
    @autoreleasepool {
        AppContext *context = (AppContext *)[UIApplication sharedApplication].delegate;
        JPushDelegate *delegate = [JPushDelegate defaultDelegate];
        delegate.appKey = toNSString(appKey);
        delegate.channel = toNSString(channel);
        [context addAppDelegate:delegate];
        runtime::registerFeature("jiguang.push.ios", true);
    }
}

void JPush::setAlias(const std::string &alias)
{
    @autoreleasepool {
        [JPUSHService setAlias:toNSString(alias) completion:^(NSInteger iResCode, NSString *iAlias, NSInteger seq) {
            runtime::log("[JPUSH] set alias: %d %s %d", (int)iResCode, [iAlias UTF8String], (int)seq);
        } seq:0];
    }
}

void JPush::deleteAlias()
{
    @autoreleasepool {
        [JPUSHService deleteAlias:^(NSInteger iResCode, NSString *iAlias, NSInteger seq) {
            runtime::log("[JPUSH] delete alias: %d %s %d", (int)iResCode, [iAlias UTF8String], (int)seq);
        } seq:0];
    }
}

void JPush::addTags(const std::set<std::string> &tags)
{
    @autoreleasepool {
        [JPUSHService addTags:toNSSetString(tags) completion:^(NSInteger iResCode, NSSet *iTags, NSInteger seq) {
            runtime::log("[JPUSH] add tags: %d %s %d", (int)iResCode, [[[iTags allObjects] componentsJoinedByString:@","] UTF8String], (int)seq);
        } seq:0];
    }
}

void JPush::setTags(const std::set<std::string> &tags)
{
    @autoreleasepool {
        [JPUSHService setTags:toNSSetString(tags) completion:^(NSInteger iResCode, NSSet *iTags, NSInteger seq) {
            runtime::log("[JPUSH] set tags: %d %s %d", (int)iResCode, [[[iTags allObjects] componentsJoinedByString:@","] UTF8String], (int)seq);
        } seq:0];
    }
}

void JPush::deleteTags(const std::set<std::string> &tags)
{
    @autoreleasepool {
        [JPUSHService deleteTags:toNSSetString(tags) completion:^(NSInteger iResCode, NSSet *iTags, NSInteger seq) {
            runtime::log("[JPUSH] delete tags: %d %s %d", (int)iResCode, [[[iTags allObjects] componentsJoinedByString:@","] UTF8String], (int)seq);
        } seq:0];
    }
}

void JPush::cleanTags()
{
    @autoreleasepool {
        [JPUSHService cleanTags:^(NSInteger iResCode, NSSet *iTags, NSInteger seq) {
            runtime::log("[JPUSH] clean tags: %d %s %d", (int)iResCode, [[[iTags allObjects] componentsJoinedByString:@","] UTF8String], (int)seq);
        } seq:0];
    }
}

void JPush::setDebug(bool enabled)
{
    @autoreleasepool {
        [JPUSHService setDebugMode];
    }
}

void JPush::setLogOFF()
{
    @autoreleasepool {
        [JPUSHService setLogOFF];
    }
}

void JPush::setBadge(int value)
{
    @autoreleasepool {
        [JPUSHService setBadge:value];
        [[UIApplication sharedApplication] setApplicationIconBadgeNumber:value];
    }
}

std::string JPush::getRegistrationID()
{
    @autoreleasepool {
        return [[JPUSHService registrationID] UTF8String];
    }
}

bool JPush::isEnabled()
{
    @autoreleasepool {
        return [[UIApplication sharedApplication] isRegisteredForRemoteNotifications];
    }
}

void JPush::requestPermission()
{
}

NS_CCLUA_PLUGIN_END

#endif // CCLUA_BUILD_JPUSH


#ifdef CCLUA_BUILD_JANALYTICS

@interface JAnalyticsDelegate : NSObject<UIApplicationDelegate>

@property(strong) NSString *channel;
@property(strong) NSString *appKey;

+ (instancetype) defaultDelegate;

#pragma mark -- UIApplicationDelegate --
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
@end

@implementation JAnalyticsDelegate

+ (instancetype) defaultDelegate
{
    static JAnalyticsDelegate *inst = nil;
    if (inst == nil) {
        inst = [[JAnalyticsDelegate alloc] init];
    }
    return inst;
}

#pragma mark -- UIApplicationDelegate --
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    JANALYTICSLaunchConfig *config = [[JANALYTICSLaunchConfig alloc] init];
    config.appKey = _appKey;
    config.channel = _channel;
    config.isProduction = YES;
#ifdef CCLUA_FEATURE_IDFA
    config.advertisingId = [NSString stringWithUTF8String:runtime::getIDFA().c_str()];
#endif
    [JANALYTICSService setupWithConfig:config];
    runtime::log("init janalytics");
    return YES;
}
@end

NS_CCLUA_PLUGIN_BEGIN
void JAnalytics::init(const std::string &appKey, const std::string &channel)
{
    @autoreleasepool {
        AppContext *context = (AppContext *)[UIApplication sharedApplication].delegate;
        JAnalyticsDelegate *delegate = [JAnalyticsDelegate defaultDelegate];
        delegate.appKey = toNSString(appKey);
        delegate.channel = toNSString(channel);
        [context addAppDelegate:delegate];
        
        runtime::registerFeature("janalytics.ios", true);
    }
}
void JAnalytics::startTrackPage(const std::string &pageName)
{
    @autoreleasepool {
        [JANALYTICSService startLogPageView:toNSString(pageName)];
    }
}

void JAnalytics::stopTrackPage(const std::string &pageName)
{
    @autoreleasepool {
        [JANALYTICSService stopLogPageView:toNSString(pageName)];
    }
}

static NSDictionary<NSString *, NSString *>* toExtra(cocos2d::Value &value)
{
    NSMutableDictionary<NSString *, NSString *> *extra = nil;
    
    if (value.getType() == cocos2d::Value::Type::MAP) {
        cocos2d::ValueMap &map = value.asValueMap();
        extra = [[NSMutableDictionary alloc] init];
        for (auto it = map.begin(); it != map.end(); ++it) {
            [extra setValue:toNSString(it->second.asString()) forKey:toNSString(it->first.c_str())];
        }
    }
    
    return extra;
}

void JAnalytics::trackEvent(EventType type, cocos2d::ValueMap &value)
{
    @autoreleasepool {
        switch (type) {
            case EventType::LOGIN:
            {
                JANALYTICSLoginEvent *event = [[JANALYTICSLoginEvent alloc] init];
                event.extra = toExtra(value["extra"]);
                event.method = toNSString(value["method"].asString());
                event.success = value["success"].asBool();
                [JANALYTICSService eventRecord:event];
                break;
            }
            case EventType::REGISTER:
            {
                JANALYTICSRegisterEvent *event = [[JANALYTICSRegisterEvent alloc] init];
                event.extra = toExtra(value["extra"]);
                event.method = toNSString(value["method"].asString());
                event.success = value["success"].asBool();
                [JANALYTICSService eventRecord:event];
                break;
            }
            case EventType::PURCHASE:
            {
                JANALYTICSPurchaseEvent *event = [[JANALYTICSPurchaseEvent alloc] init];
                event.extra = toExtra(value["extra"]);
                event.price = (CGFloat)value["price"].asFloat();
                event.success = value["success"].asBool();
                event.goodsID = toNSString(value["id"].asString());
                event.goodsName = toNSString(value["name"].asString());
                event.goodsType = toNSString(value["type"].asString());
                event.currency = value["currency"].asString() == "CNY" ? JANALYTICSCurrencyCNY : JANALYTICSCurrencyUSD;
                event.quantity = (NSInteger)value["quantity"].asInt();
                [JANALYTICSService eventRecord:event];
                break;
            }
            case EventType::BROWSE:
            {
                JANALYTICSBrowseEvent *event = [[JANALYTICSBrowseEvent alloc] init];
                event.extra = toExtra(value["extra"]);
                event.name = toNSString(value["name"].asString());
                event.contentID = toNSString(value["id"].asString());
                event.type = toNSString(value["type"].asString());
                event.duration = (CGFloat)value["duration"].asFloat();
                [JANALYTICSService eventRecord:event];
                break;
            }
            case EventType::COUNT:
            {
                JANALYTICSCountEvent *event = [[JANALYTICSCountEvent alloc] init];
                event.extra = toExtra(value["extra"]);
                event.eventID = toNSString(value["id"].asString());
                [JANALYTICSService eventRecord:event];
                break;
            }
            case EventType::CALCULATE:
            {
                JANALYTICSCalculateEvent *event = [[JANALYTICSCalculateEvent alloc] init];
                event.extra = toExtra(value["extra"]);
                event.eventID = toNSString(value["id"].asString());
                event.value = (CGFloat)value["value"].asFloat();
                [JANALYTICSService eventRecord:event];
                break;
            }
        }
    }
}

void JAnalytics::identifyAccount(cocos2d::ValueMap &value)
{
    @autoreleasepool {
        JANALYTICSUserInfo *userInfo = [[JANALYTICSUserInfo alloc] init];
        userInfo.accountID = toNSString(value["account"].asString());
        if (value.find("creationTime") != value.end()) {
            userInfo.creationTime = (NSTimeInterval)value["creationTime"].asDouble();
        }
        if (value.find("sex") != value.end()) {
            userInfo.sex = (JANALYTICSSex)value["sex"].asInt();
        }
        if (value.find("birthday") != value.end()) {
            userInfo.birthdate = toNSString(value["birthday"].asString());
        }
        if (value.find("paid") != value.end()) {
            userInfo.paid = (JANALYTICSPaid)value["paid"].asInt();
        }
        if (value.find("phone") != value.end()) {
            userInfo.phone = toNSString(value["phone"].asString());
        }
        if (value.find("email") != value.end()) {
            userInfo.email = toNSString(value["email"].asString());
        }
        if (value.find("name") != value.end()) {
            userInfo.name = toNSString(value["name"].asString());
        }
        if (value.find("wechat") != value.end()) {
            userInfo.wechatID = toNSString(value["wechat"].asString());
        }
        if (value.find("qq") != value.end()) {
            userInfo.qqID = toNSString(value["qq"].asString());
        }
        if (value.find("weibo") != value.end()) {
            userInfo.weiboID = toNSString(value["weibo"].asString());
        }
        if (value["extras"].getType() == cocos2d::Value::Type::MAP) {
            cocos2d::ValueMap &map = value["extras"].asValueMap();
            for (auto it = map.begin(); it != map.end(); ++it) {
                [userInfo setExtraObject:toNSObject(it->second) forKey:toNSString(it->first)];
            }
        }
        [JANALYTICSService identifyAccount:userInfo with:^(NSInteger err, NSString *msg) {
            runtime::log("identify account: %d %s", (int)err, [msg UTF8String]);
        }];
    }
}

void JAnalytics::detachAccount()
{
    @autoreleasepool {
        [JANALYTICSService detachAccount:^(NSInteger err, NSString *msg) {
            runtime::log("detach account: %d %s", (int)err, [msg UTF8String]);
        }];
    }
}

void JAnalytics::setFrequency(int frequency)
{
    @autoreleasepool {
        [JANALYTICSService setFrequency:(NSUInteger) frequency];
    }
}

void JAnalytics::setDebug(bool enable)
{
    @autoreleasepool {
        [JANALYTICSService setDebug:enable];
    }
}

NS_CCLUA_PLUGIN_END

#endif // CCLUA_BUILD_JANALYTICS

#endif // CCLUA_OS_IOS
