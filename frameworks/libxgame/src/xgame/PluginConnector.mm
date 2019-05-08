#import "PluginConnector.h"

#include "xgame/xlua.h"
#include "xgame/xruntime.h"

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
    xgame::runtime::runOnCocosThread([=]() {
        if (_dispatcher) {
            _dispatcher(eventString, messageString);
        }
    });
}
@end
