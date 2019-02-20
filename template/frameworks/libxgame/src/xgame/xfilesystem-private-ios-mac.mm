#import "xgame/xfilesystem.h"
#import "xgame/xfilesystem-private.h"
#import "xgame/xruntime.h"
#import "cocos2d.h"

#import <AVFoundation/AVFoundation.h>

USING_NS_XGAME;

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
const std::string __filesystem_getDocumentDirectory()
{
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    std::string str = [[paths objectAtIndex:0] UTF8String];
    return str;
}

const std::string __filesystem_getCacheDirectory()
{
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES);
    std::string str = [[paths objectAtIndex:0] UTF8String];
    return str;
}

const std::string __filesystem_getTmpDirectory()
{
    std::string str = [NSTemporaryDirectory() UTF8String];
    if (str[str.size() - 1] == '/')
    {
        return str.substr(0, str.size() - 1);
    }
    return str;
}
#elif CC_TARGET_PLATFORM == CC_PLATFORM_MAC
const std::string __filesystem_getDocumentDirectory()
{
    return filesystem::getWritablePath() + "/Documents";
}

const std::string __filesystem_getCacheDirectory()
{
    return filesystem::getWritablePath() + "/Cache";
}

const std::string __filesystem_getTmpDirectory()
{
    return filesystem::getWritablePath() + "/Tmp";
}
#endif

const std::string __filesystem_getSDCardDirectory()
{
    runtime::log("filesystem::getSDCardDirectory only support android");
    return "/";
}
