//
//  BuglyAgentV2.h
//  BuglyAgent
//
//  Copyright © 2016年 Bugly. All rights reserved.
//
//  Version: 2.0
//

#import <Foundation/Foundation.h>

#import "BuglyAgent.h"

/**
 *  支持Bugly 2.x的接口类
 */
@interface BuglyAgentV2 : NSObject

/**
 *  初始化SDK
 *
 *  @param appId 应用标识(Bugly网站注册应用分配的AppID)
 */
+ (void)startWithAppId:(NSString *)appId;

/**
 *  初始化SDK
 *
 *  @param appId 应用标识(Bugly网站注册应用分配的AppID)
 *  @param debug 是否在控制台打印SDK调试信息，默认不打印
 */
+ (void)startWithAppId:(NSString *)appId inDebugMode:(BOOL)debug;

/**
 *  初始化SDK
 *
 *  @param appId 应用标识(Bugly网站注册应用分配的AppID)
 *  @param debug 是否在控制台打印SDK调试信息，默认不打印
 *  @param level 自定义日志级别控制，默认LogLevelOff，即不记录不上报
 */
+ (void)startWithAppId:(NSString *)appId inDebugMode:(BOOL)debug reportLogLevel:(BALogLevel)level;

/**
 *  设置用户标识
 *
 *  @param userId App的用户标识
 */
+ (void)setUserIdentifier:(NSString *)userId;

/**
 *  设置标签
 *
 *  @param tag 标签唯一标识(在Bugly后台配置的标签才生效)
 */
+ (void)setTag:(NSUInteger)tag;

/**
 *  设置关键场景的关键数据(崩溃时一起上报)
 *
 *  @param value
 *  @param key
 */
+ (void)setUserValue:(NSString *)value forKey:(NSString *)key;

/**
 *  删除指定Key的关键数据
 *
 *  @param key
 */
+ (void)removeUserValueForKey:(NSString *)key;

/**
 *  自定义错误上报
 *
 *  @param category    错误类别
 *  @param anName      错误名称
 *  @param aMessage    错误原因
 *  @param aStackTrace 错误堆栈
 *  @param userInfo    附加信息
 *  @param terminate   上报后是否退出应用
 */
+ (void)reportException:(NSUInteger) category name:(NSString *) anName message:(NSString *) aMessage stackTrace:(NSString *) aStackTrace userInfo:(NSDictionary *) userInfo terminateApp:(BOOL) terminate;

/**
 *  自定义日志打印
 *
 *  @param level   日志级别
 *  @param tag     日志类别
 *  @param message 日志信息
 */
+ (void)level:(BALogLevel) level tag:(NSString *)tag log:(NSString *)message;

/**
 *  设置App的版本信息
 *
 *  @param version App的版本信息
 */
+ (void)setAppVersion:(NSString *)version;

/**
 *  设置自定义渠道标识，在初始化方法之前调用
 *
 *  @param channel App自定义渠道标识
 */
+ (void)setAppChannel:(NSString *)channel;

/**
 *  设置自定义设备唯一标识，在初始化方法之前调用
 *
 *  @param deviceId App的自定义设备唯一标识
 */
+ (void)setDeviceIdentifier:(NSString *)deviceId;

+ (void)setComponentIdentifier:(NSString *)componentId version:(NSString *)version;

+ (instancetype)sharedInstance;

+ (BOOL)hasInitialized;

@end
