#import <Foundation/Foundation.h>

#import "cclua/runtime.h"
#import "cclua/xlua.h"

#define olua_checknsstring(L, idx) ([NSString stringWithUTF8String:olua_checkstring(L, idx)])

@interface PluginConnector : NSObject

@property std::function<void(const std::string &event, const std::string &data)> dispatcher;

- (instancetype)init;
- (void)dispatch:(NSString *)event withMessage:(NSString *)message;

- (NSString *)objectToString:(NSObject *)obj;

@end
