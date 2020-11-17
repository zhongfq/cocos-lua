#include "xgame/filesystem.h"
#include "xgame/filesystem-private.h"
#include "xgame/runtime.h"
#include "lua-bindings/lua_javabridge.h"

#include "cocos2d.h"
#include "unzip/unzip.h"

#include <stdio.h>

USING_NS_XGAME;
USING_NS_CC;

NS_XGAME_BEGIN

BufferReader::BufferReader()
:_capacity(0)
,_size(0)
,_data(nullptr)
{
}

BufferReader::~BufferReader()
{
    CC_SAFE_FREE(_data);
}

void BufferReader::resize(size_t size)
{
    if (size > _capacity) {
        while (_capacity < size) {
            _capacity = _capacity == 0 ? 1024 : (_capacity * 2);
        }
        _data = (unsigned char *)realloc(_data, _capacity);
    }
    _size = size;
}

BufferReader filesystem::s_reader;

#if CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
const std::string filesystem::getAppDataDirectory()
{
    return __filesystem_getAppDataDirectory();
}
#endif

const std::string filesystem::getDocumentDirectory()
{
    return __filesystem_getDocumentDirectory();
}

const std::string filesystem::getCacheDirectory()
{
    return __filesystem_getCacheDirectory();
}

const std::string filesystem::getTmpDirectory()
{
    return __filesystem_getTmpDirectory();
}

const std::string filesystem::getBuiltinCacheDirectory()
{
    return filesystem::getCacheDirectory() + "/builtin";
}

const std::string filesystem::getSDCardDirectory()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    return __filesystem_getSDCardDirectory();
#else
    return "/";
#endif
}

const std::string filesystem::getDirectory(const std::string &type)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    return __filesystem_getDir(type);
#else
    return "/";
#endif
}


const std::string filesystem::getWritablePath()
{
    std::string path = FileUtils::getInstance()->getWritablePath();
    auto sep = path.at(path.size() - 1);
    if (sep == '/' || sep == '\\') {
        return path.substr(0, path.size() - 1);
    } else {
        return path;
    }
}

void filesystem::addSearchPath(const std::string &path, bool front)
{
    if (path.size() > 0) {
        FileUtils::getInstance()->addSearchPath(path, front);
    }
}

const std::string filesystem::shortPath(const std::string &path, size_t limit)
{
    size_t len = path.size();
    if (len > limit) {
        return "..." + path.substr(len - limit + 3);
    } else {
        return path;
    }
}

const std::string filesystem::fullPath(const std::string &path)
{
    return FileUtils::getInstance()->fullPathForFilename(path);
}

bool filesystem::createDirectory(const std::string &path, bool isFilePath)
{
    std::string dir = path;
    if (isFilePath) {
        auto idx = path.find_last_of("/");
        if (idx != std::string::npos) {
            dir = path.substr(0, idx);
        }
    }
    if (filesystem::isDirectory(dir)) {
        return true;
    } else {
        bool status = FileUtils::getInstance()->createDirectory(dir);
        runtime::log("[%s] create dir: %s", BOOL_STR(status), filesystem::shortPath(dir).c_str());
        return status;
    }
}

bool filesystem::remove(const std::string &path)
{
    bool status = filesystem::isDirectory(path)
        ? FileUtils::getInstance()->removeDirectory(path)
        : FileUtils::getInstance()->removeFile(path);
    runtime::log("[%s] remove: %s", BOOL_STR(status), filesystem::shortPath(path).c_str());
    return status;
}

bool filesystem::exist(const std::string &path)
{
    auto fileUtils = FileUtils::getInstance();
    auto notify = fileUtils->isPopupNotify();
    fileUtils->setPopupNotify(false);
    auto exist = fileUtils->isFileExist(path);
    fileUtils->setPopupNotify(notify);
    return exist;
}

bool filesystem::isFile(const std::string &path)
{
    return FileUtils::getInstance()->isFileExist(path);
}

bool filesystem::isDirectory(const std::string &path)
{
    return FileUtils::getInstance()->isDirectoryExist(path);
}

bool filesystem::rename(const std::string &oldPath, const std::string &newPath)
{
    bool status = FileUtils::getInstance()->renameFile(oldPath, newPath);
    runtime::log("[%s] rename: %s => %s", BOOL_STR(status),
        filesystem::shortPath(oldPath).c_str(),
        filesystem::shortPath(newPath).c_str());
    return status;
}

bool filesystem::copy(const std::string &srcPath, const std::string &destPath)
{
    bool status = false;
    if (!strcaseequal(srcPath.c_str(), destPath.c_str())) {
        Data data = FileUtils::getInstance()->getDataFromFile(srcPath);
        if (!data.isNull()) {
            status = FileUtils::getInstance()->writeDataToFile(data, destPath);
        }
    }
    
    runtime::log("[%s] copy file: %s => %s", BOOL_STR(status),
        filesystem::shortPath(srcPath, 40).c_str(),
        filesystem::shortPath(destPath, 40).c_str());
    return status;
}

bool filesystem::write(const std::string &path, const char *data, size_t len)
{
    bool status = false;
    FILE *file = fopen(path.c_str(), "w");
    
    if (file != NULL) {
        fwrite(data, sizeof(char), len, file);
        fflush(file);
        fclose(file);
        status = true;
    }
    
    runtime::log("[%s] write file: %s", BOOL_STR(status), filesystem::shortPath(path).c_str());
    return status;
}

bool filesystem::write(const std::string &path, const cocos2d::Data &data)
{
    return filesystem::write(path, (const char *)data.getBytes(), (size_t)data.getSize());
}

Data filesystem::read(const std::string &path)
{
    Data data = FileUtils::getInstance()->getDataFromFile(path);
    runtime::log("[%s] read file: %s", BOOL_STR(!data.isNull()), filesystem::shortPath(path).c_str());
    return data;
}

static bool _doUnzip(const std::string &zipPath, const std::string &dest)
{
    ZipFile zipFile(zipPath);
    int numFiles = 0;
    
    if (!filesystem::createDirectory(dest)) {
        return false;
    }
    
    BufferReader *reader = filesystem::getBufferReader();
    
    while (true) {
        std::string filename;
        std::string fullPath;
        if (numFiles == 0) {
            filename = zipFile.getFirstFilename();
        } else {
            filename = zipFile.getNextFilename();
        }
        if (filename.length() == 0) {
            break;
        } else {
            numFiles++;
        }
        fullPath = dest + "/" + filename;
        if (filename[filename.length() - 1] == '/') {
            filesystem::createDirectory(fullPath);
        } else if (zipFile.getFileData(filename, reader)) {
            filesystem::write(fullPath, (const char *)reader->buffer(), (size_t)reader->size());
            runtime::log("[OK] unzip file: %s", fullPath.c_str());
        } else {
            runtime::log("[NO] unzip file: %s", fullPath.c_str());
            return false;
        }
    }
    
    return numFiles > 0;
}

bool filesystem::unzip(const std::string &path, const std::string &dest)
{
    bool status = _doUnzip(path, dest);
    runtime::log("[%s] unzip: %s => %s",
        BOOL_STR(status),
        filesystem::shortPath(path).c_str(),
        filesystem::shortPath(dest).c_str());
    return status;
}

NS_XGAME_END
