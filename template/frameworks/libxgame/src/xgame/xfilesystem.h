#ifndef __XFILESYSTEM_H__
#define __XFILESYSTEM_H__

#include "xgame/xdef.h"

#include <string>

NS_XGAME_BEGIN

class filesystem {
public:
    static const std::string getWritablePath();
    static const std::string getCacheDirectory();
    static const std::string getDocumentDirectory();
    static const std::string getTmpDirectory();
    static const std::string getSDCardDirectory();  // android only
    static const char *shortPath(const std::string &path, size_t limit = 60); // for log
    static bool createDirectory(const std::string &path);
    static bool remove(const std::string &path);
    static bool exist(const std::string &path);
};

NS_XGAME_END

#endif
