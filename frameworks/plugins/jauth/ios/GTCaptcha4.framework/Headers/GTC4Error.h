//
//  GTC4Error.h
//  GTCaptcha4
//
//  Created by NikoXu on 2020/9/30.
//  Copyright © 2020 GT. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 不合法的参数。请检查输入的参数。
/// Illegal parameter. Please check the parameters you entered.
FOUNDATION_EXPORT NSString * const GTC4ErrorCodeInvalidParameter;
/// 操作失败。详细查看描述。
/// Operation failed. Check the description in detail.
FOUNDATION_EXPORT NSString * const GTC4ErrorCodeOperationFail;
/// 资源缺失。请检查 GTCaptcha4.bundle 文件是否完整。
/// Lack of resources. Please check if the `GTCaptcha4.bundle` file is imported correctly.
FOUNDATION_EXPORT NSString * const GTC4ErrorCodeMissedResource;

/// 用户取消了验证。
/// Verification is canceled by the user.
FOUNDATION_EXPORT NSString * const GTC4ErrorCodeUserDidCancel;

/// 加载文件失败。请检查是否导入了完整的 GTCaptcha4.bundle 文件或者配置的远程静态资源是否可访问。
/// Failed to load file. Please check if the `GTCaptcha4.bundle` file
/// is complete or if the configured remote static resource is accessible.
FOUNDATION_EXPORT NSString * const GTC4ErrorCodeLoadFileFailure;
/// 加载超时。
/// Request timeout.
FOUNDATION_EXPORT NSString * const GTC4ErrorCodeTimeout;
/// 执行 Javascript 脚本失败。
/// Evaluating javascript script fail.
FOUNDATION_EXPORT NSString * const GTC4ErrorCodeEvaluatingJavascriptFail;
/// Javascript 返回错误。
/// Javascript returns an error.
FOUNDATION_EXPORT NSString * const GTC4ErrorCodeJavascriptError;
/// WebView 内存警告。
/// WebView memory warning.
FOUNDATION_EXPORT NSString * const GTC4ErrorCodeWebViewMemoryWarning;

/// 未知错误。
/// Unknown error.
FOUNDATION_EXPORT NSString * const GTC4ErrorCodeUnknown;

/// 错误描述对象
/// Error description object
@interface GTC4Error : NSObject

/// 错误码, 可用于匹配并进行相应处理
/// Error code, and can be used for matching processing.
@property (readonly, nonatomic, strong) NSString *code;
/// 错误信息，可用于用户界面展示。
/// Error message. can be used for user interface display.
@property (readonly, nonatomic, strong) NSString *msg;
/// 错误详细描述，用于详细排查问题。
/// 建议可以记录为排查日志。
/// Detailed description of the error,
/// which is used to troubleshoot problems in detail.
@property (readonly, nonatomic, strong) NSDictionary *desc;

@end

NS_ASSUME_NONNULL_END
