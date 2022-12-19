//
//  GTCaptcha4Session.h
//  GTCaptcha4.h
//
//  Created by NikoXu on 2020/9/29.
//  Copyright © 2020 GT. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class GTCaptcha4SessionConfiguration, GTC4Error;

@protocol GTCaptcha4SessionTaskDelegate;

/// 验证会话(Captcha session)
@interface GTCaptcha4Session : NSObject

/// 验证会话任务的代理(Captcha session task delegate)
@property (nullable, nonatomic, weak) id<GTCaptcha4SessionTaskDelegate> delegate;

/// 当前验证会话的验证ID(The captcha ID of the current captcha session)
@property (nonnull, readonly, nonatomic, strong) NSString *captchaID;
/// 当前验证会话的流水号(The serial number of the current captcha session)
@property (nullable, readonly, nonatomic, strong) NSString *challenge;
/// 当前验证会话的配置(The configuration of the current captcha session)
@property (nonnull, readonly, nonatomic, strong) GTCaptcha4SessionConfiguration *configuration;

/// 创建一个新的验证会话实例(Create a new captcha session instance)
/// @param captchaID 验证ID(The captcha ID)
+ (instancetype)sessionWithCaptchaID:(NSString *)captchaID;

/// 创建一个新的验证会话实例(Create a new captcha session instance.)
/// @param captchaID 验证ID(The captcha ID)
/// @param configuration 会话配置(The configuration of session)
+ (instancetype)sessionWithCaptchaID:(NSString *)captchaID
                       configuration:(nullable GTCaptcha4SessionConfiguration *)configuration;

/// 初始化一个新的验证会话实例(Create a new captcha session instance)
/// @param captchaID 验证ID(The captcha ID)
- (instancetype)initWithCaptchaID:(NSString *)captchaID;

/// 初始化一个新的验证会话实例(Create a new captcha session instance)
/// @param captchaID 验证ID(The captcha ID)
/// @param configuration 会话配置(The configuration of session)
- (instancetype)initWithCaptchaID:(NSString *)captchaID
                    configuration:(nullable GTCaptcha4SessionConfiguration *)configuration;

/// 开始验证(Start verification)
- (void)verify;

/// 取消验证(Cancel verification)
- (void)cancel;

/// SDK 版本号(Obtain the SDK version)
+ (NSString *)sdkVersion;

@end

/// 验证会话任务代理协议(Captcha Session Task Delegate)
@protocol GTCaptcha4SessionTaskDelegate <NSObject>

@required

/// 回调验证会话的结果参数(Callback result parameters of captcha session)
/// @discussion 拿到验证结果的参数后，需要提交到业务服务端，
///             完成参数的校验
///             After getting the parameters of verification results,
///             they need to be submitted to the business server to
///             complete the verification of parameters.
/// @param captchaSession 验证会话(Captcha session)
/// @param status 状态码。@"0"/@"1": 未完成/完成。当 status 为 @"1"
///                     时，则为成功，需要对结果进行二次校验。
///               Status code. @ “0”/@ “1”: Not finished/finished.
///               When status is @ “1”, it is successful, and the
///               result needs to be secondary validated.
/// @param result 结果校验参数(Result verification parameters.)。示例(Example):
///               ```
///               {
///                 challenge = "19080ae5-fe79-4431-9c78-4ee8e0dec798";
///                 captcha_id = "c62d0f270240799b3113b0a5787ead55";
///               }
///               ```
- (void)gtCaptchaSession:(GTCaptcha4Session *)captchaSession
              didReceive:(NSString *)status
                  result:(nullable NSDictionary *)result;

/// 回调验证会话中发生的错误(Callback errors that occurred in the captcha session)
/// @param captchaSession 验证会话(Captcha session)
/// @param error 错误描述对象(Error description object)
- (void)gtCaptchaSession:(GTCaptcha4Session *)captchaSession
         didReceiveError:(GTC4Error *)error;

@optional

/// 通知验证界面将要展现
/// @param captchaSession 验证会话
- (void)gtCaptchaSessionWillShow:(GTCaptcha4Session *)captchaSession;

@end

NS_ASSUME_NONNULL_END
