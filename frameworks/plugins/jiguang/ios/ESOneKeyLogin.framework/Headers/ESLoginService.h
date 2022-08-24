//
//  ESLoginService.h
//  CTPocket
//
//  Created by Frank on 2019/1/14.
//  Copyright © 2019 广东亿迅科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ESLoginService : NSObject

/**
 *免密登录获取AccessCode
 *
 @param syscode 合作方编码
 @param successBlock 成功回调Block
 @param failureBlock 失败回调Block
 */
-(void)getAccessCodeWithSyscode:(NSString *)syscode Success:(void(^)(NSDictionary *dict))successBlock failure:(void (^)(NSError *error))failureBlock;

/**
 *取消一键登录连接
 */
- (void)cancelSocketConnect;


@end


