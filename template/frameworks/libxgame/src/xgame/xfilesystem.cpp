#include "xgame/xfilesystem.h"
#include "xgame/xfilesystem-private.h"
#include "xgame/xruntime.h"
#include "xgame/lua_javabridge.h"

#include "cocos2d.h"

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

const char *filesystem::shortPath(const std::string &path, size_t limit)
{
#define MAX_LEN 256
    static char buf[MAX_LEN];
    
    limit = fmin(limit, MAX_LEN);
    
    size_t len = path.size();
    if (len > limit) {
        snprintf(buf, limit, "...%s", path.c_str() + (len - limit + 3));
    } else {
        strcpy(buf, path.c_str());
    }
    
    return buf;
}

bool filesystem::createDirectory(const std::string &path)
{
    bool status = FileUtils::getInstance()->createDirectory(path);
    runtime::log("[%s] create dir: %s", BOOL_STR(status), filesystem::shortPath(path));
    return status;
}

bool filesystem::remove(const std::string &path)
{
    bool status = FileUtils::getInstance()->isDirectoryExist(path)
        ? FileUtils::getInstance()->removeDirectory(path)
        : FileUtils::getInstance()->removeFile(path);
    runtime::log("[%s] remove: %s", BOOL_STR(status), filesystem::shortPath(path));
    return status;
}

bool filesystem::exist(const std::string &path)
{
    return FileUtils::getInstance()->isFileExist(path);
}

NS_XGAME_END
