//
//  WKQuickLogin.h
//  QuickLogin
//
//  Created by bitlib on 2020/10/1.
//  SDKVERSION @"2.0.7.2"

#import <Foundation/Foundation.h>
@class WKCustomModel;

NS_ASSUME_NONNULL_BEGIN

typedef void (^LoginResultListener)(NSDictionary * _Nonnull data);

typedef NS_ENUM(NSUInteger, OperatorType) {
    OperatorTypeUnkonw   = 0, //未知
    OperatorTypeCMCC     = 1, //移动
    OperatorTypeCUCC     = 2, //联通
    OperatorTypeCTCC     = 3  //电信
};

@interface WKQuickLogin : NSObject

/// 单例
+ (WKQuickLogin *_Nonnull) getInstance;

/// 获取当前流量卡运营商
+ (OperatorType) getOperatorType;

/// 初始化SDK
/// @param appKey 平台分配的appKey
/// @param complete 回调监听
- (void)initWithKey:(NSString *)appKey complete:(void (^)(NSDictionary *resultDic))complete;

/// 预取号
/// @param listener 回调监听
- (void)preLogin:(double)timeout listener:(LoginResultListener) listener;

/// 预授权获取token
/// @param timeout 超时时间
/// @param listener 回调监听
- (void)getAccessCode:(double)timeout listener:(LoginResultListener) listener;

/// 获取指定运营商token（指定错误则无法正确返回token）
/// @param timeout 超时时间
/// @param type 运营商
/// @param listener 回调监听
- (void)getAccessCode:(double)timeout withOperator:(OperatorType)type listener:(LoginResultListener) listener;

/// 显式获取token
/// @param model 需要配置的model属性（控制器必传）
/// @param timeout 超时时间
/// @param listener 回调监听
- (void)getAuthorizationWithModel:(WKCustomModel* )model timeout:(double)timeout listener:(LoginResultListener _Nonnull) listener;

/// 关闭授权页面
/// @param flag 是否开启动画
/// @param completion 回调监听
- (void)wk_dismissViewControllerAnimated: (BOOL)flag completion: (void (^ __nullable)(void))completion;

/// 删除取号缓存数据
/// @return YES：有缓存已执行删除操作，NO：无缓存不执行删除操作
- (BOOL)deleteScrip;

@end

NS_ASSUME_NONNULL_END
