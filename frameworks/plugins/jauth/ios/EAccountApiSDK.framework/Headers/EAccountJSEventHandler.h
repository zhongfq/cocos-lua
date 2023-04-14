//
//  EAccountJSEventHandler.h
//  EAccountApiSDK
//
//  Created by Reticence Lee on 2020/6/9.
//  Copyright © 2020 21CN. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <webkit/webkit.h>

static NSString * const EAccountJSEventName = @"EAccountJsBridge";

NS_ASSUME_NONNULL_BEGIN

@protocol EAccountJSEventDelegate <NSObject>

@required
- (void)EAccountJSCallBackWithScript:(NSString *)jScript;

@end

@interface EAccountJSEventHandler : NSObject<WKScriptMessageHandler>

@property (nonatomic, strong) WKWebView *wkWebView;
@property (nonatomic, weak) id <EAccountJSEventDelegate> delegate;

- (void)EAccountHandleJsEvents:(WKScriptMessage *)message credt:(id)credt;

@end

NS_ASSUME_NONNULL_END
