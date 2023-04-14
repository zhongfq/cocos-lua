#ifndef __CCLUA_FILEFINDER_H__
#define __CCLUA_FILEFINDER_H__

#include "cclua/runtime.h"
#include "cclua/AssetsBundle.h"

#include <unordered_map>

#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_MAC)
#include "platform/apple/CCFileUtils-apple.h"
#define SuperFileUtils cocos2d::FileUtilsApple
#elif defined(CCLUA_OS_ANDROID)
#include "platform/android/CCFileUtils-android.h"
#define SuperFileUtils cocos2d::FileUtilsAndroid
#elif defined(CCLUA_OS_WIN32)
#include "platform/win32/CCFileUtils-win32.h"
#define SuperFileUtils cocos2d::FileUtilsWin32
#endif

NS_CCLUA_BEGIN

class FileFinder : public SuperFileUtils {
public:
    static FileFinder *create();

    virtual ~FileFinder();
    virtual cocos2d::FileUtils::Status getContents(const std::string& filename, cocos2d::ResizableBuffer* buffer) const override;
    
    virtual void addCacheFileType(const std::string &type);
protected:
    FileFinder();
    virtual bool init() override;
    virtual AssetsBundle *createAssetsBundle();
    virtual std::string getFullPathForFilenameWithinDirectory(const std::string& directory, const std::string& filename) const override;
protected:
    AssetsBundle *_builtinAssets = nullptr;
    std::unordered_map<std::string, bool> _cacheFileTypes;
    
public:
    typedef std::function<FileFinder *()> FileFinderProvider;
    static void setProivder(const FileFinderProvider &provider) { s_provider = provider; }
private:
    static FileFinderProvider s_provider;
};

NS_CCLUA_END

#endif
