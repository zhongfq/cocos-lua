#ifndef __XDOWNLOADER_H__
#define __XDOWNLOADER_H__

#include "xgame/xdef.h"

#include <string>
#include <functional>

NS_XGAME_BEGIN

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
        std::string md5;
        FileState state;
    };
    
    static void load(const FileTask &task);
    static void setDispatcher(const std::function<void(const FileTask &)> callback);
    static void init();
    static void end();
private:
    static void start();
public:
};
    
NS_XGAME_END

#endif
