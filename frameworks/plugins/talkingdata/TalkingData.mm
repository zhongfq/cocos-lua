#import "talkingdata.h"

#if defined(CCLUA_BUILD_TALKINGDATA) && defined(CCLUA_OS_IOS)

#import "ios/TalkingDataSDK.h"
#import "cclua/AppContext-ios.h"
#import "cclua/plugin-ios.h"

USING_NS_CCLUA;
USING_NS_CCLUA_PLUGIN;

#define setValue(OBJ, NAME, DATA, FUNC) do {            \
    if (DATA.find(#NAME) != DATA.end()) {               \
        OBJ.NAME = FUNC(DATA[#NAME]);                   \
    }                                                   \
} while (0)

#define setEnum(OBJ, NAME, DATA, ENUM) do {             \
    if (DATA.find(#NAME) != DATA.end()) {               \
        OBJ.NAME = (ENUM)DATA[#NAME].asInt();           \
    }                                                   \
} while (0)

#define setNumber(OBJ, NAME, DATA, ASNUM) do {          \
    if (DATA.find(#NAME) != DATA.end()) {               \
        OBJ.NAME = DATA[#NAME].ASNUM();                 \
    }                                                   \
} while (0)

#define setProperty(OBJ, NAME, DATA) do {               \
    if (DATA.find(#NAME) != DATA.end()) {               \
        auto &value = DATA[#NAME];                      \
        OBJ.NAME = toNSObject(value);                   \
    }                                                   \
} while (0)

static TalkingDataProfile *toProfile(const cocos2d::ValueMap &value)
{
    cocos2d::ValueMap &data = *const_cast<cocos2d::ValueMap *>(&value);
    TalkingDataProfile *profile = [TalkingDataProfile createProfile];
    setValue(profile, name, data, toNSString);
    setEnum(profile, type, data, TalkingDataProfileType);
    setEnum(profile, gender, data, TalkingDataGender);
    setNumber(profile, age, data, asInt);
    setProperty(profile, property1, data);
    setProperty(profile, property2, data);
    setProperty(profile, property3, data);
    setProperty(profile, property4, data);
    setProperty(profile, property5, data);
    setProperty(profile, property6, data);
    setProperty(profile, property7, data);
    setProperty(profile, property8, data);
    setProperty(profile, property9, data);
    setProperty(profile, property10, data);
    
    return profile;
}

@interface TalkingDataDelegate : NSObject<UIApplicationDelegate>

@property(nonatomic, strong) NSString *appkey;
@property(nonatomic, strong) NSString *channel;
@property(nonatomic, strong) NSString *custom;

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
        [TalkingDataSDK init:self.appkey channelId:self.channel custom:self.custom];
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

std::string talkingdata::getDeviceId()
{
    @autoreleasepool {
        return std::string([[TalkingDataSDK getDeviceId] UTF8String]);
    }
}

void talkingdata::setVerboseLogDisable()
{
    @autoreleasepool {
        [TalkingDataSDK setVerboseLogDisable];
    }
}

void talkingdata::setConfigurationDisable(uint64_t options)
{
    @autoreleasepool {
        [TalkingDataSDK setConfigurationDisable:(TalkingDataDisable)options];
    }
}

void talkingdata::backgroundSessionEnabled()
{
    @autoreleasepool {
        [TalkingDataSDK backgroundSessionEnabled];
    }
}

void talkingdata::init(const std::string &appkey, const std::string &channel, const std::string &custom)
{
    @autoreleasepool {
        TalkingDataDelegate *delegate = [TalkingDataDelegate defaultDelegate];
        delegate.appkey = toNSString(appkey);
        delegate.channel = toNSString(channel);
        if (custom.size() > 0) {
            delegate.custom = toNSString(custom);
        }
    }
}

void talkingdata::setVendorId(const std::string &vendorId, int type)
{
    @autoreleasepool {
        [TalkingDataSDK setVendorId:toNSString(vendorId) ofType:(TalkingDataVendorIdType)type];
    }
}

void talkingdata::setLocation(double latitude, double longitude)
{
    @autoreleasepool {
        [TalkingDataSDK setLatitude:latitude longitude:longitude];
    }
}

void talkingdata::setExceptionReportEnabled(bool value)
{
    @autoreleasepool {
        [TalkingDataSDK setExceptionReportEnabled:value];
    }
}

void talkingdata::setSignalReportEnabled(bool value)
{
    @autoreleasepool {
        [TalkingDataSDK setSignalReportEnabled:value];
    }
}

void talkingdata::onPageBegin(const std::string &name)
{
    @autoreleasepool {
        [TalkingDataSDK onPageBegin:toNSString(name)];
    }
}

void talkingdata::onPageEnd(const std::string &name)
{
    @autoreleasepool {
        [TalkingDataSDK onPageEnd:toNSString(name)];
    }
}

void talkingdata::onReceiveDeepLink(const std::string &link)
{
    @autoreleasepool {
        [TalkingDataSDK onReceiveDeepLink:[NSURL URLWithString:toNSString(link)]];
    }
}

void talkingdata::onRegister(const std::string &uid, const cocos2d::ValueMap &data, const std::string &invitationCode)
{
    @autoreleasepool {
        [TalkingDataSDK onRegister:toNSString(uid) profile:toProfile(data) invitationCode:toNSString(invitationCode)];
    }
}

void talkingdata::onLogin(const std::string &uid, const cocos2d::ValueMap &data)
{
    @autoreleasepool {
        [TalkingDataSDK onLogin:toNSString(uid) profile:toProfile(data)];
    }
}

void talkingdata::onProfileUpdate(const cocos2d::ValueMap &data)
{
    @autoreleasepool {
        [TalkingDataSDK onProfileUpdate:toProfile(data)];
    }
}

void talkingdata::onCreateCard(const std::string &uid, const std::string &method, const std::string &content)
{
    @autoreleasepool {
        [TalkingDataSDK onCreateCard:toNSString(uid) method:toNSString(method) content:toNSString(content)];
    }
}

void talkingdata::onFavorite(const std::string &category, const std::string &content)
{
    @autoreleasepool {
        [TalkingDataSDK onFavorite:toNSString(category) content:toNSString(content)];
    }
}

void talkingdata::onShare(const std::string &uid, const std::string &content)
{
    @autoreleasepool {
        [TalkingDataSDK onShare:toNSString(uid) content:toNSString(content)];
    }
}

void talkingdata::onPunch(const std::string &uid, const std::string &punchid)
{
    @autoreleasepool {
        [TalkingDataSDK onPunch:toNSString(uid) punchId:toNSString(punchid)];
    }
}

void talkingdata::onSearch(const cocos2d::ValueMap &value)
{
    @autoreleasepool {
        TalkingDataSearch *search = [TalkingDataSearch createSearch];
        cocos2d::ValueMap &data = *const_cast<cocos2d::ValueMap *>(&value);
        setValue(search, content, data, toNSString);
        setValue(search, category, data, toNSString);
        [TalkingDataSDK onSearch:search];
    }
}

void talkingdata::onEvent(const std::string &event, double value, const cocos2d::ValueMap &data)
{
    @autoreleasepool {
        [TalkingDataSDK onEvent:toNSString(event) value:value parameters:toNSDictionary(data)];
    }
}

void talkingdata::setGlobalKV(const std::string &key, const cocos2d::Value &value)
{
    @autoreleasepool {
        [TalkingDataSDK setGlobalKV:toNSString(key) value:toNSObject(value)];
    }
}

void talkingdata::removeGlobalKV(const std::string &key)
{
    @autoreleasepool {
        [TalkingDataSDK removeGlobalKV:toNSString(key)];
    }
}

#endif
