#ifndef __XFILEFINDER_H__
#define __XFILEFINDER_H__

#include "xgame/xdef.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
#include "platform/apple/CCFileUtils-apple.h"
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "platform/android/CCFileUtils-android.h"
#elif CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include "platform/win32/CCFileUtils-win32.h"
#endif

NS_XGAME_BEGIN

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
class FileFinder : public cocos2d::FileUtilsApple {
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
class FileFinder : public cocos2d::FileUtilsAndroid {
#elif CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
class FileFinder : public cocos2d::FileUtilsWin32 {
#endif
public:
    FileFinder();
    virtual ~FileFinder();
    
    virtual std::string fullPathForFilename(const std::string &filename) const override;
};

NS_XGAME_END

#endif
