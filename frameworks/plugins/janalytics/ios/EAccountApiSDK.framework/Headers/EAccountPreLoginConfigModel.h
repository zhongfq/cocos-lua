//
//  EAccountPreLoginConfigModel.h
//  EAccountApiSDK
//
//  Created by Reticence Lee on 2019/12/12.
//  Copyright © 2019 21CN. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface EAccountPreLoginConfigModel : NSObject

/**
 NSURLRequest的最大空闲时间 默认3s
 */
@property (nonatomic, assign) NSTimeInterval  timeoutIntervalForRequest;

/**
 NSURLSession资源获取超时时间 默认3s
 */
@property (nonatomic, assign) NSTimeInterval  timeoutIntervalForResource;

/**
 socket连接超时时间 默认3s
 */
@property (nonatomic, assign) NSTimeInterval  socketConnectTimeoutInterval;

/**
 socket请求总超时时间 默认6s 建议设置比 socket连接超时时间 长
 */
@property (nonatomic, assign) NSTimeInterval  socketTotalTimeoutInterval;

#pragma -mark 初始化方法

/**
 初始化方法  请调用该方法进行初始化
 */
- (instancetype)initWithDefaultConfig;

@end

NS_ASSUME_NONNULL_END
