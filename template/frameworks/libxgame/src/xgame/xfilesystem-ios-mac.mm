#import "xgame/xfilesystem.h"
#import "xgame/xruntime.h"
#import "cocos2d.h"

#import <AVFoundation/AVFoundation.h>

NS_XGAME_BEGIN

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
const std::string filesystem::getDocumentDirectory()
{
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    std::string str = [[paths objectAtIndex:0] UTF8String];
    return str;
}

const std::string filesystem::getCacheDirectory()
{
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES);
    std::string str = [[paths objectAtIndex:0] UTF8String];
    return str;
}

const std::string filesystem::getTmpDirectory()
{
    std::string str = [NSTemporaryDirectory() UTF8String];
    if (str[str.size() - 1] == '/')
    {
        return str.substr(0, str.size() - 1);
    }
    return str;
}

#elif CC_TARGET_PLATFORM == CC_PLATFORM_MAC
const std::string filesystem::getDocumentDirectory()
{
    return filesystem::getWritablePath() + "/Documents";
}

const std::string filesystem::getCacheDirectory()
{
    return filesystem::getWritablePath() + "/Cache";
}

const std::string filesystem::getTmpDirectory()
{
    return filesystem::getWritablePath() + "/Tmp";
}
#endif

NS_XGAME_END
