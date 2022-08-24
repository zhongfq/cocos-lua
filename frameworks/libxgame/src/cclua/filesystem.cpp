#include "cclua/filesystem.h"
#include "cclua/filesystem-private.h"
#include "lua-bindings/lua_javabridge.h"

#include "cocos2d.h"
#include "unzip/unzip.h"

#include <stdio.h>

USING_NS_CCLUA;
USING_NS_CC;

NS_CCLUA_BEGIN

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

#if defined(CCLUA_OS_WIN32) || defined(CCLUA_OS_MAC)
std::string filesystem::getAppDataDirectory()
{
    return __filesystem_getAppDataDirectory();
}
#endif

std::string filesystem::getDocumentDirectory()
{
    return __filesystem_getDocumentDirectory();
}

std::string filesystem::getCacheDirectory()
{
    return __filesystem_getCacheDirectory();
}

std::string filesystem::getTmpDirectory()
{
    return __filesystem_getTmpDirectory();
}

std::string filesystem::getBuiltinCacheDirectory()
{
    return filesystem::getCacheDirectory() + "/builtin";
}

std::string filesystem::getSDCardDirectory()
{
#ifdef CCLUA_OS_ANDROID
    return __filesystem_getSDCardDirectory();
#else
    return "/";
#endif
}

std::string filesystem::getDirectory(const std::string &type)
{
#ifdef CCLUA_OS_ANDROID
    return __filesystem_getDir(type);
#else
    return "/";
#endif
}


std::string filesystem::getWritablePath()
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

std::string filesystem::trimPath(const std::string &path, size_t limit)
{
    size_t len = path.size();
    if (len > limit) {
        return "..." + path.substr(len - limit + 3);
    } else {
        return path;
    }
}

std::string filesystem::fullPath(const std::string &path)
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
        runtime::log("[%s] create dir: %s", BOOL_STR(status), filesystem::trimPath(dir).c_str());
        return status;
    }
}

bool filesystem::remove(const std::string &path)
{
    bool status = filesystem::isDirectory(path)
        ? FileUtils::getInstance()->removeDirectory(path)
        : FileUtils::getInstance()->removeFile(path);
    runtime::log("[%s] remove: %s", BOOL_STR(status), filesystem::trimPath(path).c_str());
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

bool filesystem::isAbsolutePath(const std::string& path)
{
    return FileUtils::getInstance()->isAbsolutePath(path);
}

bool filesystem::rename(const std::string &oldPath, const std::string &newPath)
{
    bool status = FileUtils::getInstance()->renameFile(oldPath, newPath);
    runtime::log("[%s] rename: %s => %s", BOOL_STR(status),
        filesystem::trimPath(oldPath).c_str(),
        filesystem::trimPath(newPath).c_str());
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
        filesystem::trimPath(srcPath, 40).c_str(),
        filesystem::trimPath(destPath, 40).c_str());
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
    
    runtime::log("[%s] write file: %s", BOOL_STR(status), filesystem::trimPath(path).c_str());
    return status;
}

bool filesystem::write(const std::string &path, const cocos2d::Data &data)
{
    return filesystem::write(path, (const char *)data.getBytes(), (size_t)data.getSize());
}

Data filesystem::read(const std::string &path)
{
    Data data = FileUtils::getInstance()->getDataFromFile(path);
    runtime::log("[%s] read file: %s", BOOL_STR(!data.isNull()), filesystem::trimPath(path).c_str());
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
        filesystem::trimPath(path).c_str(),
        filesystem::trimPath(dest).c_str());
    return status;
}

NS_CCLUA_END
