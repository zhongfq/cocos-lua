#ifndef __XDOWNLOADER_H__
#define __XDOWNLOADER_H__

#include "xgame/xdef.h"

#include "network/CCDownloader.h"

#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

NS_XGAME_BEGIN

enum file_state {
    IOERROR = 0,
    LOADED,
    VALID,
    INVALID,
};

class file_task {
public:
    std::string url;
    std::string storage_path;
    std::string md5;
    file_state state;
};

class downloader
{
public:
    downloader();
    ~downloader();
    
    void load(file_task task);
    std::vector<file_task> receive();
private:
    void init();
    void start();
private:
    cocos2d::network::Downloader *_loader;
    std::vector<file_task> _tasks;
    std::mutex _mutex;
    std::vector<file_task> _done_tasks;
    std::mutex _done_mutex;
    std::thread *_verify_thread;
    std::condition_variable _cond;
    bool _quit;
};
    
NS_XGAME_END

#endif
