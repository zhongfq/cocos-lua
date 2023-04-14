//
//  UniAuthHelper.h
//  account_verify_sdk_core
//
//  Created by zhuof on 2018/3/8.
//  Copyright © 2018年 xiaowo. All rights reserved.
//  4.1.3IR01B0320 1. 优化token获取流程。 减少交互。 使用者自行缓存accessCode（具备有效期）。
//  4.3.0IR01B0615 1. socket通讯优化（GCD方案）
//  4.4.0IR01B0715 1. 预取号流程修改 2.增加读取idfa的功能 3.降低打点频率。
//  4.5.0IR01B1020 1. 关闭日志 2.错误码细化
//  4.6.0IR01B0105 1. http1.1规范 header部分头域兼容大小写，兼容http链接中缺少80端口问题。
//                 2. socket请求时，host头域追加端口号
//                 3. 仅数据网络开通和wifi双开时，都启动预取号计时器。
//                 4. 按照阿里建议， 超时时间可以设置x.x秒样式
//  4.7.0IR01B0331 1. 减少体积
//                 2. 解决苹果appstore审核时，可能会对getaddrinfo域名解析接口触发本地设备连接授权弹窗进行驳回处理。
//  5.0.0IR01B0420 全https 5g取号支持
//  5.1.0IR01B0701 ipv6网络支持
//                 开启缓存模式支持
//                 解决偶发的1002验签错误bug
//                 未确保兼容性，建议讲wostore.cn  10010.com域名及其子域名加入到http通信白名单中。
//                 解决不符合url规范的特殊url地址的socket网络访问bug
//  5.1.0IR01B0712 删除缓存相关代码

#import <Foundation/Foundation.h>

typedef void (^UniResultListener)(NSDictionary * _Nonnull data);

@interface UniAuthHelper : NSObject

+(UniAuthHelper *_Nonnull) getInstance;

/**
 sdk初始化，每个app只能执行一次初始化调用。
 注意：某些使用者尝试在同一个app中使用多个appid初始化sdk，这可能导致未知隐患发生。
 */
-(void) initWithAppId:(NSString* _Nonnull) appId appSecret:(NSString* _Nonnull) appSecret;

/**
 预取号接口。
  timeout：超时时间，单位秒（网络环境复杂，建议设置5-8秒以上，过低的超时时间可能导致取号成功率下降）。
  listener：回调接口 resultCode 为 0时，表示预取号成功。 其他值都是错误码。
 
 成功调用有以下前提：
 1. 需要保证手机终端有联通sim卡，并且保证联通数据网络是开启状态。
 2. 手机本地时间正确（北京时间）
 3. 如果手机数据网络开启，但是预取号失败，可以尝试手动飞行模式开关一下，尝试让数据网络恢复正常。
 4. 物联网卡无法取号
 5. 海外，港澳地区无法取号
 6. 确保APN接入点设置正确，目前只支持3gnet接入点。
 
 预取号获得的accessCode具有效期，请在有效期内使用accesscode换取用户信息。
 */
-(void) getAccessCode:(double)timeout listener:(UniResultListener _Nonnull) listener;

/**
 获取号码认证用的accessCode，与getAccessCode接口的区别是：回调中不会带有脱敏手机号码。
 */
-(void) mobileAuth:(double)timeout listener:(UniResultListener _Nonnull) listener;

/**
 日志默认开启。正式发布时，可选择关闭。
 */
-(void) printConsoleEnable:(BOOL)enable;


/**
 获取sdk的版本号
 */
-(NSString*_Nonnull) getSdkVersion;

@end
