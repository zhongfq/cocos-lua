#import <Foundation/Foundation.h>

#import "xgame/xruntime.h"

@interface PluginConnector : NSObject

@property std::function<void(const std::string &event, const std::string &data)> dispatcher;

- (instancetype)init;
- (void)dispatch:(NSString *)event withMessage:(NSString *)message;

- (NSString *)objectToString:(NSObject *)obj;

@end
