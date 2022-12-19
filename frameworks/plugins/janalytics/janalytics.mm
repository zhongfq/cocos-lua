#import "janalytics.h"

#ifdef CCLUA_OS_IOS

#import "cclua/AppContext-ios.h"
#import "cclua/plugin-ios.h"
#import "ios/JPUSHService.h"
#import "ios/JANALYTICSService.h"
#import "ios/JVERIFICATIONService.h"

#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>

#ifdef CCLUA_FEATURE_TRACKING
#import <AdSupport/AdSupport.h>
#import <AppTrackingTransparency/AppTrackingTransparency.h>
#endif

USING_NS_CCLUA;
USING_NS_CCLUA_PLUGIN;

#pragma mark -- janalytics --
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
#ifdef CCLUA_FEATURE_TRACKING
    config.advertisingId = [[[ASIdentifierManager sharedManager] advertisingIdentifier] UUIDString];
#endif
    [JANALYTICSService setupWithConfig:config];
    runtime::log("init janalytics");
    return YES;
}
@end

void janalytics::init(const std::string &appKey, const std::string &channel)
{
    @autoreleasepool {
        AppContext *context = (AppContext *)[UIApplication sharedApplication].delegate;
        JAnalyticsDelegate *delegate = [JAnalyticsDelegate defaultDelegate];
        delegate.appKey = toNSString(appKey);
        delegate.channel = toNSString(channel);
        [context addAppDelegate:delegate];
    }
}
void janalytics::startTrackPage(const std::string &pageName)
{
    @autoreleasepool {
        [JANALYTICSService startLogPageView:toNSString(pageName)];
    }
}

void janalytics::stopTrackPage(const std::string &pageName)
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

void janalytics::trackEvent(EventType type, const cocos2d::ValueMap &data)
{
    cocos2d::ValueMap &value = *const_cast<cocos2d::ValueMap *>(&data);
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

void janalytics::identifyAccount(const cocos2d::ValueMap &data)
{
    @autoreleasepool {
        cocos2d::ValueMap &value = *const_cast<cocos2d::ValueMap *>(&data);
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

void janalytics::detachAccount()
{
    @autoreleasepool {
        [JANALYTICSService detachAccount:^(NSInteger err, NSString *msg) {
            runtime::log("detach account: %d %s", (int)err, [msg UTF8String]);
        }];
    }
}

void janalytics::setFrequency(int frequency)
{
    @autoreleasepool {
        [JANALYTICSService setFrequency:(NSUInteger) frequency];
    }
}

void janalytics::setDebug(bool enable)
{
    @autoreleasepool {
        [JANALYTICSService setDebug:enable];
    }
}
#endif // CCLUA_BUILD_JANALYTICS

#endif // CCLUA_OS_IOS
