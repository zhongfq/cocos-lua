#include "xgame/xfilesystem.h"
#include "xgame/xfilesystem-private.h"
#include "xgame/xruntime.h"
#include "xgame/lua_javabridge.h"

#include "cocos2d.h"
#include "unzip/unzip.h"

#include <stdio.h>

USING_NS_XGAME;
USING_NS_CC;

NS_XGAME_BEGIN

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

const std::string filesystem::getSDCardDirectory()
{
    return __filesystem_getSDCardDirectory();
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

const std::string filesystem::shortPath(const std::string &path, size_t limit)
{
    size_t len = path.size();
    if (len > limit) {
        return "..." + path.substr(len - limit + 3);
    } else {
        return path;
    }
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
    bool status = FileUtils::getInstance()->createDirectory(path);
    runtime::log("[%s] create dir: %s", BOOL_STR(status), filesystem::shortPath(path).c_str());
    return status;
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
    return FileUtils::getInstance()->isFileExist(path);
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
    if (!strcaseequal(srcPath.c_str(), destPath.c_str()))
    {
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
    return false;
}

Data filesystem::read(const std::string &path)
{
    Data data = FileUtils::getInstance()->getDataFromFile(path);
    runtime::log("[%s] read file: %s", BOOL_STR(!data.isNull()), filesystem::shortPath(path).c_str());
    return data;
}

static bool _doUnzip(const std::string &zipPath, const std::string &dest)
{
    unzFile zip = unzOpen(zipPath.c_str());
    
    if (!filesystem::createDirectory(dest)) {
        return false;
    }
    
    if (zip == nullptr) {
        return false;
    }
    
    unz_global_info global_info;
    if (unzGetGlobalInfo(zip, &global_info) != UNZ_OK) {
        unzClose(zip);
        return false;
    }
    
    for (uLong i = 0; i < global_info.number_entry; i++) {
        char namebuff[FILENAME_MAX];
        unz_file_info file;
        if (unzGetCurrentFileInfo(zip, &file, namebuff, FILENAME_MAX, nullptr, 0, nullptr, 0) != UNZ_OK) {
            unzClose(zip);
            return false;
        }
        
        char fullPath[FILENAME_MAX];
        snprintf(fullPath, FILENAME_MAX, "%s/%s", dest.c_str(), namebuff);
        
        if (!filesystem::createDirectory(fullPath, true)) {
            unzClose(zip);
            return false;
        }
        
        if (namebuff[file.size_filename - 1] != '/')
        {
            if (unzOpenCurrentFile(zip) != UNZ_OK) {
                unzClose(zip);
                return false;
            }
            
            FILE *localFile = fopen(fullPath, "wb");
            if (localFile == nullptr) {
                unzClose(zip);
                return false;
            }
            
            int len = 0;
            char contentbuff[BUFSIZ];
            while ((len = unzReadCurrentFile(zip, contentbuff, BUFSIZ)) > 0) {
                fwrite(contentbuff, sizeof(char), len, localFile);
            }
            
            fclose(localFile);
            
            if (len < 0) {
                unzClose(zip);
                return false;
            }
            
            runtime::log("[OK] unzip file: %s", fullPath);
            
            unzCloseCurrentFile(zip);
        }
        
        if (i < global_info.number_entry - 1) {
            if (unzGoToNextFile(zip) != UNZ_OK) {
                unzClose(zip);
                return false;
            }
        }
    }
    
    unzClose(zip);
    
    return true;
}

bool filesystem::unzip(const std::string &path, const std::string &dest)
{
    bool status = _doUnzip(path, dest);
    runtime::log("[%s] unzip: %s => %s",
        filesystem::shortPath(path).c_str(),
        filesystem::shortPath(dest).c_str());
    return status;
}

NS_XGAME_END
