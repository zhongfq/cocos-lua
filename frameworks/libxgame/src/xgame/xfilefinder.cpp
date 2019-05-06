#include "xfilefinder.h"
#include "xfilesystem.h"

NS_XGAME_BEGIN

FileFinder::FileFinder()
{
    init();
#if CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
    std::string path = filesystem::getAppDataDirectory();
    setWritablePath(path + "/");
#endif
}

FileFinder::~FileFinder()
{
}

std::string FileFinder::fullPathForFilename(const std::string &filename) const
{
    return FileUtils::fullPathForFilename(filename);
}

NS_XGAME_END
