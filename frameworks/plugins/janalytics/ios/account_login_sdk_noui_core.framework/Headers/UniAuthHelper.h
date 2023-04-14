//
//  UniAuthHelper.h
//  account_verify_sdk_core
//
//  Created by zhuof on 2018/3/8.
//  Copyright © 2018年 xiaowo. All rights reserved.
//  4.1.3IR01B0320 优化token获取流程。 减少交互。 使用者自行缓存accessCode（具备有效期）。
//

#import <Foundation/Foundation.h>

typedef void (^UniResultListener)(NSDictionary *data);

@interface UniAuthHelper : NSObject

+(UniAuthHelper *) getInstance;

-(void) initWithAppId:(NSString*) appId appSecret:(NSString*) appSecret;

//-(void) login :(double)timeout listener:(UniResultListener) listener;

-(void) getAccessCode :(double)timeout listener:(UniResultListener) listener;

//20200320 yangzc36 token优化，删除该接口
//-(void) getAccessToken :(double)timeout accessCode:(NSString *)accessCode listener:(UniResultListener) listener;

-(void) mobileAuth :(double)timeout listener:(UniResultListener) listener;

-(void) printConsoleEnable:(BOOL)enable;

-(NSString*) getSdkVersion;

@end
