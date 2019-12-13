#include "xfilefinder.h"
#include "xfilesystem.h"

NS_XGAME_BEGIN

FileFinder *FileFinder::create()
{
    auto fs = new FileFinder();
    fs->init();
    return fs;
}

FileFinder::FileFinder()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_MAC
    std::string path = filesystem::getAppDataDirectory();
    setWritablePath(path + "/");
#endif
}

FileFinder::~FileFinder()
{
}

bool FileFinder::init()
{
    SuperFileUtils::init();
    
    _builtinAssets.init("builtin.assets");
    
    return true;
}

cocos2d::FileUtils::Status FileFinder::getContents(const std::string& filename, cocos2d::ResizableBuffer* buffer) const
{
    if (SuperFileUtils::getContents(filename, buffer) == FileUtils::Status::OK) {
        return FileUtils::Status::OK;
    } else {
        return _builtinAssets.getContents(filename, buffer);
    }
}

std::string FileFinder::getFullPathForFilenameWithinDirectory(const std::string& directory, const std::string& filename) const
{
    std::string fullPath = SuperFileUtils::getFullPathForFilenameWithinDirectory(directory, filename);
    if (fullPath.size() == 0) {
        fullPath.append(directory).append(filename);
        if (_builtinAssets.exist(fullPath)) {
            return fullPath;
        } else {
            return "";
        }
    } else {
        return fullPath;
    }
}

NS_XGAME_END
