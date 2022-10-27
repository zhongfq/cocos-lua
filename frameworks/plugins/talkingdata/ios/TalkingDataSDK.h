//
//  TalkingDataSDK.h
//  TalkingData
//
//  Created by liweiqiang on 21-03-16.
//  Copyright (c) 2021年 TendCloud. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef NS_OPTIONS(NSUInteger, TalkingDataDisable) {
    TalkingDataDisablePreciseArea           = 1 << 0,
    TalkingDataDisableAnalyticsIntellignet  = 1 << 1,
    TalkingDataDisableDeviceIdentification  = 1 << 2,
    TalkingDataDisableAntiCheating          = 1 << 3,
};

typedef NS_ENUM(NSUInteger, TalkingDataVendorIdType) {
    TalkingDataVendorIdTypeZX           = 1,    // 卓信
    TalkingDataVendorIdTypeGX           = 2,    // 广协
};

typedef NS_ENUM(NSUInteger, TalkingDataProfileType) {
    TalkingDataProfileTypeAnonymous     = 0,    // 匿名账户
    TalkingDataProfileTypeRegistered    = 1,    // 显性注册账户
    TalkingDataProfileTypeSinaWeibo     = 2,    // 新浪微博
    TalkingDataProfileTypeQQ            = 3,    // QQ账户
    TalkingDataProfileTypeQQWeibo       = 4,    // 腾讯微博
    TalkingDataProfileTypeND91          = 5,    // 91账户
    TalkingDataProfileTypeWeiXin        = 6,    // 微信
    TalkingDataProfileTypeType1         = 11,   // 自定义类型1
    TalkingDataProfileTypeType2         = 12,   // 自定义类型2
    TalkingDataProfileTypeType3         = 13,   // 自定义类型3
    TalkingDataProfileTypeType4         = 14,   // 自定义类型4
    TalkingDataProfileTypeType5         = 15,   // 自定义类型5
    TalkingDataProfileTypeType6         = 16,   // 自定义类型6
    TalkingDataProfileTypeType7         = 17,   // 自定义类型7
    TalkingDataProfileTypeType8         = 18,   // 自定义类型8
    TalkingDataProfileTypeType9         = 19,   // 自定义类型9
    TalkingDataProfileTypeType10        = 20,   // 自定义类型10
};

typedef NS_ENUM(NSUInteger, TalkingDataGender) {
    TalkingDataGenderUnknown            = 0,    // 未知
    TalkingDataGenderMale               = 1,    // 男
    TalkingDataGenderFemale             = 2,    // 女
};


@interface TalkingDataProfile : NSObject

+ (TalkingDataProfile *)createProfile;

// 账户名称
@property (nonatomic, strong) NSString *name;
// 账户类型
@property (nonatomic, assign) TalkingDataProfileType type;
// 用户性别
@property (nonatomic, assign) TalkingDataGender gender;
// 用户年龄
@property (nonatomic, assign) int age;

// 自定义属性1-10，类型为NSString或NSNumber
@property (nonatomic, strong) id property1;
@property (nonatomic, strong) id property2;
@property (nonatomic, strong) id property3;
@property (nonatomic, strong) id property4;
@property (nonatomic, strong) id property5;
@property (nonatomic, strong) id property6;
@property (nonatomic, strong) id property7;
@property (nonatomic, strong) id property8;
@property (nonatomic, strong) id property9;
@property (nonatomic, strong) id property10;

@end


@interface TalkingDataSearch : NSObject

+ (TalkingDataSearch *)createSearch;

// 搜索类别
@property (nonatomic, strong) NSString *category;
// 搜索内容
@property (nonatomic, strong) NSString *content;



@end






@interface TalkingDataSDK : NSObject

/**
 *  获取TalkingData分配的设备ID
 *  @return deviceId        设备的ID
 */
+ (NSString *)getDeviceId;

/**
 *  设置不显示日志。如发布时不需显示日志，应当最先调用该方法。
 */
+ (void)setVerboseLogDisable;

/**
 *  设置关闭配置
 */
+ (void)setConfigurationDisable:(TalkingDataDisable)options;

/**
 *  开启后台使用时长统计，需在SDK初始化之前调用。
 */
+ (void)backgroundSessionEnabled;

#if TARGET_OS_IOS
/**
 *  用于精准的追踪以Safari作为资源载体的广告来源，如果需要使用应当在init方法之前调用。
 */
+ (void)enableSFSafariViewControllerTracking API_DEPRECATED("此方法会影响到用户交互，使用前请确保和产品、业务沟通清楚!", ios(1, 1));
#endif

/**
 *  TalkingData SDK初始化方法。请在application:didFinishLaunchingWithOptions:方法里调用
 *  @param  appId           应用的唯一标识，统计后台注册得到
 *  @param  channelId       渠道名（可选）。如“AppStore”
 *  @param  custom          自定义参数（可选）。
 */
+ (void)init:(NSString *)appId channelId:(NSString *)channelId custom:(NSString *)custom;

/**
 *  设置第三方的ID
 *  @param  vendorId        第三方的ID
 *  @param  type            ID的提供方
 */
+ (void)setVendorId:(NSString *)vendorId ofType:(TalkingDataVendorIdType)type;

/**
 *  设置位置信息
 *  @param  latitude        纬度
 *  @param  longitude       经度
 */
+ (void)setLatitude:(double)latitude longitude:(double)longitude;

#if TARGET_OS_IOS
/**
 *  是否捕捉程序崩溃记录
 *  如果需要记录程序崩溃日志，请将值设成YES，并且在初始化后尽早调用
 *  @param  enable          默认NO
 */
+ (void)setExceptionReportEnabled:(BOOL)enable;

/**
 *  是否捕捉异常信号
 *  如果需要开启异常信号捕捉功能，请将值设成YES，并且在初始化后尽早调用
 *  @param  enable          默认NO
 */
+ (void)setSignalReportEnabled:(BOOL)enable;
#endif

/**
 *  开始跟踪某一页面，记录页面打开时间
 *  建议在viewWillAppear或者viewDidAppear方法里调用
 *  @param  pageName        页面名称
 */
+ (void)onPageBegin:(NSString *)pageName;

/**
 *  结束某一页面的跟踪，记录页面的关闭时间
 *  此方法与onPageBegin方法结对使用
 *  建议在viewWillDisappear或者viewDidDisappear方法里调用
 *  @param  pageName        页面名称，请跟onPageBegin方法的页面名称保持一致
 */
+ (void)onPageEnd:(NSString *)pageName;

/**
 *  唤醒事件
 *  @param  link            唤醒链接
 */
+ (void)onReceiveDeepLink:(NSURL *)link;

/**
 *  注册
 *  @param  profileId       账户ID
 *  @param  profile         账户属性
 *  @param  invitationCode  邀请码
 */
+ (void)onRegister:(NSString *)profileId profile:(TalkingDataProfile *)profile invitationCode:(NSString *)invitationCode;

/**
 *  登录
 *  @param  profileId       账户ID
 *  @param  profile         账户属性
 */
+ (void)onLogin:(NSString *)profileId profile:(TalkingDataProfile *)profile;

/**
 *  更新账户信息
 *  @param  profile         账户属性
 */
+ (void)onProfileUpdate:(TalkingDataProfile *)profile;

/**
 *  添加支付信息
 *  @param  profileId       账户ID
 *  @param  method          支付方式
 *  @param  content         支付信息
 */
+ (void)onCreateCard:(NSString *)profileId method:(NSString *)method content:(NSString *)content;

/**
 *  收藏
 *  @param  category        收藏类别
 *  @param  content         收藏内容
 */
+ (void)onFavorite:(NSString *)category content:(NSString *)content;

/**
 *  分享
 *  @param  profileId       账户ID
 *  @param  content         分享内容
 */
+ (void)onShare:(NSString *)profileId content:(NSString *)content;

/**
 *  签到打卡
 *  @param  profileId       账户ID
 *  @param  punchId         签到打卡ID
 */
+ (void)onPunch:(NSString *)profileId punchId:(NSString *)punchId;

/**
 *  搜索事件
 *  @param  search          搜索信息详情
 */
+ (void)onSearch:(TalkingDataSearch *)search;


















/**
 *  自定义事件
 *  @param  eventId         事件名称
 *  @param  eventValue      事件数值
 *  @param  parameters      事件参数 (key只支持NSString, value支持NSString和NSNumber)
 */
+ (void)onEvent:(NSString *)eventId value:(double)eventValue parameters:(NSDictionary *)parameters;

/**
 *  添加自定义事件全局参数
 *  @param  key             参数的key
 *  @param  value           参数的value，NSString或NSNumber类型
 */
+ (void)setGlobalKV:(NSString *)key value:(id)value;

/**
 *  删除自定义事件全局参数
 *  @param  key             参数的key
 */
+ (void)removeGlobalKV:(NSString *)key;


@end
