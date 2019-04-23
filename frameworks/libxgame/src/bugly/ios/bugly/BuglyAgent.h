//
//  BuglyAgent.h
//  BuglyAgent
//
//  Created by Yeelik on 15/8/20.
//  Copyright (c) 2015年 Bugly. All rights reserved.
//
//  Version: 1.3.3
//

#import <Foundation/Foundation.h>

/**
 * 崩溃上报组件的类型
 */
typedef NS_ENUM(NSUInteger, CrashReporterType){
    CrashReporterTypeDefault = 0,
    CrashReporterTypeBugly = 1, // for Bugly v2.x
    CrashReporterTypeMSDK = 2,  // for Bugly in MSDK
    CrashReporterTypeIMSDK = 3, // for Bugly in IMSDK
};

/**
 *  日志级别
 *
 */
// formatter:off
typedef NS_ENUM(NSUInteger, BALogLevel){
    BALogLevelOff     = 0,
    BALogLevelError   = 1 << 0,
    BALogLevelWarning = 1 << 1,
    BALogLevelInfo    = 1 << 2,
    BALogLevelDebug   = 1 << 3,
    BALogLevelVerbose = 1 << 4,
};
// formatter:on

@interface BuglyAgent : NSObject

/**
 *  当前是否在使用BuglyAgentV2的接口
 *
 *  @return YES 如果 CrashReporterType是CrashReporterTypeBugly(1)则说明是BuglyAgentV2
 */
+ (BOOL)isBuglyAgentV2;

/**
 *    @brief  在SDK初始化之前，设置应用发布渠道标识
 *
 *    @param channel 自定义渠道标识
 */
+ (void)setAppChannel:(NSString *) channel;

/**
 *    @brief  在SDK初始化之前，设置版本信息
 *
 *    @param version 自定义应用版本
 */
+ (void)setAppVersion:(NSString *) version;

/**
 *    @brief  初始化SDK
 *
 *    @param appId 应用标识(Bugly网站注册应用分配的AppID)
 */
+ (void)initWithAppId:(NSString *) appId;

/**
 *    @brief  初始化SDK
 *
 *    @param appId 应用标识(Bugly网站注册应用分配的AppID)
 *    @param debug 是否在控制台打印SDK调试信息，默认不打印
 */
+ (void)initWithAppId:(NSString *)appId debugMode:(BOOL) debug;

/**
 *    @brief  初始化SDK
 *
 *    @param appId 应用标识(Bugly网站注册应用分配的AppID)
 *    @param debug 是否在控制台打印SDK调试信息，默认不打印
 *    @param level 自定义日志级别，默认LogLevelOff，即不记录且不上报
 */
+ (void)initWithAppId:(NSString *)appId debugMode:(BOOL)debug logger:(BALogLevel) level;

/**
 *    @brief  打印自定义日志
 *
 *    @param level 日志级别
 *    @param tag 日志标签
 *    @param msg 日志信息
 */
+ (void)level:(BALogLevel)level tag:(NSString *)tag log:(NSString *)msg;

/**
 *    @brief  设置用户标识
 *
 *    @param userId 应用的用户标识
 */
+ (void)setUserIdentifier:(NSString *) userId;

/**
 *    @brief  自定义异常上报
 *
 *    @param category    异常类别
 *    @param anName      异常名称
 *    @param aMessage    异常原因
 *    @param aStackTrace 异常堆栈
 *    @param userInfo    附加信息
 *    @param terminate   是否退出应用
 */
+ (void)reportException:(NSUInteger) category name:(NSString *) anName message:(NSString *) aMessage stackTrace:(NSString *) aStackTrace userInfo:(NSDictionary *) userInfo terminateApp:(BOOL) terminate;

/**
 *    @brief  设置标签
 *
 *    @param tag 标签唯一标识(在Bugly后台配置的标签才生效)
 */
+ (void)setSceneTag:(NSUInteger) tag;

/**
 *    @brief  设置标签场景的关键数据
 *
 *    @param value
 *    @param key
 */
+ (void)setSceneValue:(NSString *) value forKey:(NSString *) key;

/**
 *    @brief
 *
 *    @param key
 */
+ (void)removeSceneValueForKey:(NSString *) key;

/**
 *    @brief  在初始化SDK之前，设置自定义设备唯一标识
 *
 *    @param deviceId 自定义设备唯一标识
 */
+ (void)setDeviceIdentifier:(NSString *) deviceId;

/**
 *    @brief 设置CrashReporter的类别(SDK新旧版本或多渠道兼容)
 *
 *    @param type 崩溃上报组件的类别
 */
+ (void)configCrashReporterType:(CrashReporterType) type;

/**
 *    @brief  设置额外配置
 *
 *    @param value
 *    @param key
 */
+ (void)setSdkConfigValue:(NSString *) value forKey:(NSString *)key DEPRECATED_MSG_ATTRIBUTE("Not support in BuglyAgentV2");

/**
 *    @brief  设置第三方组件的唯一标识和版本信息
 *
 *    @param componentId
 *    @param version
 */
+ (void)setComponentIdentifier:(NSString *)componentId version:(NSString *)version;

@end
