#ifndef __CCLUA_DOWNLOADER_H__
#define __CCLUA_DOWNLOADER_H__

#include "cclua/runtime.h"

#include <string>
#include <functional>

NS_CCLUA_BEGIN

class downloader
{
public:
    enum FileState {
        IOERROR = 0,
        LOADED,
        PENDING,
        INVALID,
    };
    
    struct FileTask {
        std::string url;
        std::string path;
        std::string md5 = "";
        FileState state = FileState::INVALID;
    };
    
    static void load(const FileTask &task);
    static void setDispatcher(const std::function<void(const FileTask &)> callback);
    static void init();
    static void end();
private:
    static void start();
public:
};
    
NS_CCLUA_END

#endif
