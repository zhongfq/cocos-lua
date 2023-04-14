#include "cclua/FileFinder.h"
#include "cclua/filesystem.h"

NS_CCLUA_BEGIN

FileFinder::FileFinderProvider FileFinder::s_provider = nullptr;

FileFinder *FileFinder::create()
{
    if (s_provider) {
        return s_provider();
    } else {
        auto fs = new FileFinder();
        fs->init();
        return fs;
    }
}

FileFinder::FileFinder()
{
#ifdef CCLUA_OS_MAC
    std::string path = filesystem::getAppDataDirectory();
    setWritablePath(path + "/");
#endif
}

FileFinder::~FileFinder()
{
    delete _builtinAssets;
}

bool FileFinder::init()
{
    SuperFileUtils::init();
    
    _builtinAssets = createAssetsBundle();
    
    addCacheFileType(".html");
    addCacheFileType(".ogg");
    addCacheFileType(".wav");
    addCacheFileType(".mp3");
    addCacheFileType(".mp4");
    
    return true;
}

AssetsBundle *FileFinder::createAssetsBundle()
{
    AssetsBundle *bundle = new AssetsBundle();
    bundle->init("assets.bundle");
    return bundle;
}

void FileFinder::addCacheFileType(const std::string &type)
{
    if (type.size() > 0) {
        _cacheFileTypes[type] = true;
    }
}

cocos2d::FileUtils::Status FileFinder::getContents(const std::string& filename, cocos2d::ResizableBuffer* buffer) const
{
    if (SuperFileUtils::getContents(filename, buffer) == FileUtils::Status::OK) {
        return FileUtils::Status::OK;
    } else {
        return _builtinAssets->getContents(filename, buffer);
    }
}

std::string FileFinder::getFullPathForFilenameWithinDirectory(const std::string& directory, const std::string& filename) const
{
    std::string fullPath = SuperFileUtils::getFullPathForFilenameWithinDirectory(directory, filename);
    if (fullPath.size() > 0) {
        return fullPath;
    }
    
    fullPath.append(directory).append(filename);
    if (!_builtinAssets->exist(fullPath)) {
        return "";
    }
    
    std::size_t dot = fullPath.find_last_of('.');
    std::string ext = dot != std::string::npos ? fullPath.substr(dot) : "";
    if (_cacheFileTypes.find(ext) != _cacheFileTypes.end()) {
        std::string realPath = filesystem::getBuiltinCacheDirectory() + "/" + fullPath;
        if (!filesystem::exist(realPath)) {
            BufferReader *reader = filesystem::getBufferReader();
            if (_builtinAssets->getContents(fullPath, reader) == FileUtils::Status::OK) {
                filesystem::createDirectory(realPath, true);
                cocos2d::Data data;
                data.fastSet((unsigned char *)reader->buffer(), reader->size());
                writeDataToFile(data, realPath);
                data.fastSet(nullptr, 0);
            }
        }
        return realPath;
    }
    return fullPath;
}

NS_CCLUA_END
