#import "PluginConnector.h"

#include "cclua/xlua.h"
#include "cclua/runtime.h"

@implementation PluginConnector

- (instancetype)init
{
    _dispatcher = nullptr;
    return [super init];
}

- (void)dispatch:(NSString *)event withMessage:(NSString *)message
{
    std::string eventString([event UTF8String]);
    std::string messageString([message UTF8String]);
    cclua::runtime::runOnCocosThread([=]() {
        if (_dispatcher) {
            _dispatcher(eventString, messageString);
        }
    });
}

- (NSString *)objectToString:(NSObject *)obj
{
    NSData *data = [NSJSONSerialization dataWithJSONObject:obj options:0 error:nil];
    return [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
}

@end
