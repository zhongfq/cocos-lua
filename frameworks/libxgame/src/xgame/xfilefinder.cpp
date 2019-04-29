#include "xgame/xfilefinder.h"

NS_XGAME_BEGIN

FileFinder::FileFinder()
{
    init();
}

FileFinder::~FileFinder()
{
}

std::string FileFinder::fullPathForFilename(const std::string &filename) const
{
    return FileUtils::fullPathForFilename(filename);
}

NS_XGAME_END
