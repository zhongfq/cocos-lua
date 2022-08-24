#import "cclua/filesystem.h"
#import "cclua/filesystem-private.h"
#import "cocos2d.h"

#import <AVFoundation/AVFoundation.h>

USING_NS_CCLUA;

NS_CCLUA_BEGIN

#ifdef CCLUA_OS_IOS
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
    if (str[str.size() - 1] == '/') {
        return str.substr(0, str.size() - 1);
    }
    return str;
}
#elif defined(CCLUA_OS_MAC)
const std::string __filesystem_getAppDataDirectory()
{
    NSArray<NSString *> *paths = NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES);
    std::string str = [[paths objectAtIndex:0] UTF8String];
    return str + "/Containers/" + runtime::getPackageName();
}

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

NS_CCLUA_END
