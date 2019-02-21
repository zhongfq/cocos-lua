#include "xgame/xdownloader.h"
#include "xgame/xruntime.h"
#include "xgame/xfilesystem.h"
#include "crypto/md5util.h"

#include "platform/CCFileUtils.h"

using namespace cocos2d;
using namespace cocos2d::network;

NS_XGAME_BEGIN

downloader::downloader()
:_quit(false)
{
    init();
}

downloader::~downloader()
{
    _quit = true;
    _cond.notify_one();
    _verify_thread->join();
    delete _verify_thread;
    delete _loader;
}

void downloader::init()
{
    _verify_thread = new std::thread(&downloader::start, this);
    
    DownloaderHints hints = {6, 10, ".tmp"};
    _loader = new Downloader(hints);
    _loader->onTaskError = [this](const DownloadTask &task,
        int errorCode,
        int errorCodeInternal,
        const std::string &errorStr) {
        file_task file;
        file.md5 = task.identifier;
        file.url = task.requestURL;
        file.storage_path = task.storagePath;
        file.state = file_state::IOERROR;
        
        std::lock_guard<std::mutex> lck(_mutex);
        _tasks.push_back(file);
        _cond.notify_one();
    };
    _loader->onFileTaskSuccess = [this](const DownloadTask &task) {
        file_task file;
        file.md5 = task.identifier;
        file.url = task.requestURL;
        file.storage_path = task.storagePath;
        file.state = file_state::LOADED;
        
        std::lock_guard<std::mutex> lck(_mutex);
        _tasks.push_back(file);
        _cond.notify_one();
    };
}
    
static bool verify_file(const file_task &task)
{
    unsigned char result[MD5_STR_LEN];
    return md5f(result, task.storage_path.c_str()) &&
        strcaseequal((const char *)result, task.md5.c_str());
}

void downloader::load(file_task task)
{
    auto path = task.storage_path;
    auto pos = path.find_last_of("/");
    
    if (pos != std::string::npos)
        path = path.substr(0, pos);
    
    filesystem::createDirectory(path);
    filesystem::remove(task.storage_path + ".tmp");
    _loader->createDownloadFileTask(task.url, task.storage_path, task.md5);
}

std::vector<file_task> downloader::receive()
{
    std::lock_guard<std::mutex> lck(_done_mutex);
    std::vector<file_task> ret(_done_tasks);
    _done_tasks.clear();
    return ret;
}

void downloader::start()
{
    while (!_quit)
    {
        _mutex.lock();
        if (_tasks.size() > 0)
        {
            file_task task = _tasks.back();
            _tasks.pop_back();
            _mutex.unlock();
            
            if (task.state == file_state::LOADED)
            {
                if (task.md5.size() > 0)
                    task.state = verify_file(task) ? file_state::VALID : file_state::INVALID;
                else
                    task.state = file_state::VALID;
            }
            
            if (task.state != file_state::VALID)
            {
                filesystem::remove(task.storage_path);
            }
            
            _done_mutex.lock();
            _done_tasks.push_back(task);
            _done_mutex.unlock();
            
            continue;
        }
        else
        {
            _mutex.unlock();
        }
        
        std::unique_lock<std::mutex> lck(_mutex);
        _cond.wait(lck);
    }
}
    
NS_XGAME_END
