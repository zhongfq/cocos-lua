//
//  UAFSDKErrorCode.h
//  TYRZSDK
//
//  Created by 谢鸿标 on 2018/10/24.
//  Copyright © 2018 com.CMCC.iOS. All rights reserved.
//

#ifndef UASDKErrorCode_h
#define UASDKErrorCode_h

#import <Foundation/Foundation.h>

typedef NSString *UAFSDKErrorCode;

//成功
static UAFSDKErrorCode const UASDKErrorCodeSuccess                = @"103000";
//数据解析异常
static UAFSDKErrorCode const UASDKErrorCodeProcessException       = @"200021";
//无网络
static UAFSDKErrorCode const UASDKErrorCodeNoNetwork              = @"200022";
//请求超时
static UAFSDKErrorCode const UASDKErrorCodeRequestTimeout         = @"200023";
//未知错误
static UAFSDKErrorCode const UASDKErrorCodeUnknownError           = @"200025";
//蜂窝未开启或不稳定
static UAFSDKErrorCode const UASDKErrorCodeNonCellularNetwork     = @"200027";
//网络请求出错(HTTP Code 非200)
static UAFSDKErrorCode const UASDKErrorCodeRequestError           = @"200028";
//非移动网关重定向失败
static UAFSDKErrorCode const UASDKErrorCodeWAPRedirectFailed      = @"200038";
//无SIM卡
static UAFSDKErrorCode const UASDKErrorCodePhoneWithoutSIM        = @"200048";
//Socket创建或发送接收数据失败
static UAFSDKErrorCode const UASDKErrorCodeSocketError            = @"200050";
//用户点击了“账号切换”按钮（自定义短信页面customSMS为YES才会返回）
static UAFSDKErrorCode const UASDKErrorCodeCustomSMSVC            = @"200060";
//显示登录"授权页面"被拦截（hooked）
static UAFSDKErrorCode const UASDKErrorCodeAutoVCisHooked         = @"200061";
////预取号不支持联通
//static UAFSDKErrorCode const UASDKErrorCodeNOSupportUnicom        = @"200062";
////预取号不支持电信
//static UAFSDKErrorCode const UASDKErrorCodeNOSupportTelecom       = @"200063";
//服务端返回数据异常
static UAFSDKErrorCode const UASDKErrorCodeExceptionData          = @"200064";
//CA根证书校验失败
static UAFSDKErrorCode const UASDKErrorCodeCAAuthFailed           = @"200072";
//本机号码校验仅支持移动手机号
static UAFSDKErrorCode const UASDKErrorCodeGetMoblieOnlyCMCC      = @"200080";
//服务器繁忙
static UAFSDKErrorCode const UASDKErrorCodeServerBusy             = @"200082";
//ppLocation为空
static UAFSDKErrorCode const UASDKErrorCodeLocationError          = @"200086";
//监听授权界面成功弹起
static UAFSDKErrorCode const UASDKSuccessGetAuthVCCode            = @"200087";
//当前网络不支持取号
static UAFSDKErrorCode const UASDKErrorCodeUnsupportedNetwork     = @"200096";

/**
 获取错误码描述

 @param code 错误码
 @return 返回对应描述
 */
FOUNDATION_EXPORT NSString *UASDKErrorDescription(UAFSDKErrorCode code);

#endif /* UASDKErrorCode_h */
