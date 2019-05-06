#ifndef __XFILESYSTEM_H__
#define __XFILESYSTEM_H__

#include "xgame/xdef.h"

#include "base/CCData.h"

#include <string>

NS_XGAME_BEGIN

class filesystem {
public:
#if CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
    static const std::string getAppDataDirectory();
#endif
    
    static const std::string getWritablePath();
    static const std::string getCacheDirectory();
    static const std::string getDocumentDirectory();
    static const std::string getTmpDirectory();

    // android only
    static const std::string getSDCardDirectory();
    static const std::string getDirectory(const std::string &type);

    static const std::string shortPath(const std::string &path, size_t limit = 60); // for log
    static const std::string fullPath(const std::string &path);
    static bool createDirectory(const std::string &path, bool isFilePath = false);
    static bool remove(const std::string &path);
    static bool exist(const std::string &path);
    static bool isFile(const std::string &path);
    static bool isDirectory(const std::string &path);
    static bool rename(const std::string &oldPath, const std::string &newPath);
    static bool copy(const std::string &srcPath, const std::string &destPath);
    static bool write(const std::string &path, const char *data, size_t len);
    static cocos2d::Data read(const std::string &path);
    static bool unzip(const std::string &path, const std::string &dest);
};

NS_XGAME_END

#endif
