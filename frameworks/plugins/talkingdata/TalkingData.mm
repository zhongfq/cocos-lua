#import "talkingdata.h"

#if defined(CCLUA_BUILD_TALKINGDATA) && defined(CCLUA_OS_IOS)

#import "ios/TalkingData.h"
#import "cclua/AppContext-ios.h"
#import "cclua/plugin-ios.h"

USING_NS_CCLUA;
USING_NS_CCLUA_PLUGIN;

@interface TalkingDataDelegate : NSObject<UIApplicationDelegate>

@property(nonatomic, strong) NSString *appkey;
@property(nonatomic, strong) NSString *channel;

- (instancetype)init;
+ (instancetype) defaultDelegate;

#pragma mark -- UIApplicationDelegate --
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

@end

@implementation TalkingDataDelegate

- (instancetype)init
{
    return [super init];
}

+ (instancetype) defaultDelegate
{
    static TalkingDataDelegate *inst = nil;
    if (inst == nil) {
        inst = [[TalkingDataDelegate alloc] init];
    }
    return inst;
}

#pragma mark -- UIApplicationDelegate --
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    @autoreleasepool {
        runtime::log("init talkingdata %s", [self.appkey UTF8String]);
        [TalkingData sessionStarted:self.appkey withChannelId:self.channel];
        return YES;
    }
}

@end

static NSDictionary<NSString *, NSObject *> *toNSDictionary(const cocos2d::ValueMap &value)
{
    NSMutableDictionary<NSString *, NSObject *> *map = [[NSMutableDictionary alloc] init];
    for (auto it = value.begin(); it != value.end(); ++it) {
        [map setValue:toNSObject(it->second) forKey:toNSString(it->first)];
    }
    return map;
}

void talkingdata::setLogEnabled(bool value)
{
    @autoreleasepool {
        [TalkingData setLogEnabled:value];
    }
}

void talkingdata::init(const std::string &appkey, const std::string &channel)
{
    @autoreleasepool {
        TalkingDataDelegate *delegate = [TalkingDataDelegate defaultDelegate];
        delegate.appkey = toNSString(appkey);
        delegate.channel = toNSString(channel);
    }
}

void talkingdata::onRegister(const std::string &uid, int type, const std::string &name)
{
    @autoreleasepool {
        [TalkingData onRegister:toNSString(uid) type:(TDProfileType)type name:toNSString(name)];
    }
}

void talkingdata::onLogin(const std::string &uid, int type, const std::string &name)
{
    @autoreleasepool {
        [TalkingData onLogin:toNSString(uid) type:(TDProfileType)type name:toNSString(name)];
    }
}

void talkingdata::setReportUncaughtExceptions(bool value)
{
    @autoreleasepool {
        [TalkingData setExceptionReportEnabled:value];
    }
}

void talkingdata::trackPageBegin(const std::string &name)
{
    @autoreleasepool {
        [TalkingData trackPageBegin:toNSString(name)];
    }
}

void talkingdata::trackPageEnd(const std::string &name)
{
    @autoreleasepool {
        [TalkingData trackPageEnd:toNSString(name)];
    }
}

void talkingdata::trackEvent(const std::string &event)
{
    @autoreleasepool {
        [TalkingData trackEvent:toNSString(event)];
    }
}

void talkingdata::trackEvent(const std::string &event, const std::string &label)
{
    @autoreleasepool {
        [TalkingData trackEvent:toNSString(event) label:toNSString(label)];
    }
}

void talkingdata::trackEvent(const std::string &event, const std::string &label, const cocos2d::ValueMap &map)
{
    @autoreleasepool {
        [TalkingData trackEvent:toNSString(event) label:toNSString(label) parameters:toNSDictionary(map)];
    }
}

void talkingdata::trackEvent(const std::string &event, const std::string &label, const cocos2d::ValueMap &map, double value)
{
    @autoreleasepool {
        [TalkingData trackEvent:toNSString(event) label:toNSString(label) parameters:toNSDictionary(map) value: value];
    }
}

void talkingdata::setGlobalKV(const std::string &key, bool value)
{
    @autoreleasepool {
        [TalkingData setGlobalKV:toNSString(key) value:[NSNumber numberWithBool:value]];
    }
}

void talkingdata::setGlobalKV(const std::string &key, const std::string &value)
{
    @autoreleasepool {
        [TalkingData setGlobalKV:toNSString(key) value:toNSString(value)];
    }
}

void talkingdata::setGlobalKV(const std::string &key, long value)
{
    @autoreleasepool {
        [TalkingData setGlobalKV:toNSString(key) value:[NSNumber numberWithLong:value]];
    }
}

void talkingdata::setGlobalKV(const std::string &key, double value)
{
    @autoreleasepool {
        [TalkingData setGlobalKV:toNSString(key) value:[NSNumber numberWithDouble:value]];
    }
}

void talkingdata::removeGlobalKV(const std::string &key)
{
    @autoreleasepool {
        [TalkingData removeGlobalKV:toNSString(key)];
    }
}

void talkingdata::placeOrder(const std::string &orderId, int amount, const std::string &currencyType)
{
    @autoreleasepool {
        [TalkingData onPlaceOrder:toNSString(orderId) amount:amount currencyType:toNSString(currencyType)];
    }
}

void talkingdata::payOrder(const std::string &orderId, int amount, const std::string &currencyType, const std::string &paymentType)
{
    @autoreleasepool {
        [TalkingData onOrderPaySucc:toNSString(orderId) amount:amount currencyType:toNSString(currencyType) paymentType:toNSString(paymentType)];
    }
}

void talkingdata::cancelOrder(const std::string &orderId, int amount, const std::string &currencyType)
{
    @autoreleasepool {
        [TalkingData onCancelOrder:toNSString(orderId) amount:amount currencyType:toNSString(currencyType)];
    }
}

void talkingdata::viewItem(const std::string &itemId, const std::string &category, const std::string &name, int unitPrice)
{
    @autoreleasepool {
        [TalkingData onViewItem:toNSString(itemId) category:toNSString(category) name:toNSString(name) unitPrice:unitPrice];
    }
}

#endif
