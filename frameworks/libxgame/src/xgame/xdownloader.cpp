#include "xgame/xdownloader.h"
#include "xgame/xruntime.h"
#include "xgame/xfilesystem.h"
#include "crypto/md5util.h"

#include "platform/CCFileUtils.h"
#include "network/CCDownloader.h"

#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace cocos2d;
using namespace cocos2d::network;

NS_XGAME_BEGIN

static cocos2d::network::Downloader *_loader = nullptr;
static std::function<void(const downloader::FileTask &)> _callback = nullptr;
static std::vector<downloader::FileTask> _tasks;
static std::mutex _mutex;
static std::thread *_verifyThread = nullptr;
static std::condition_variable _cond;
static bool _quit = false;

void downloader::end()
{
    if (_loader) {
        _quit = true;
        _cond.notify_one();
        _verifyThread->join();
        delete _verifyThread;
        delete _loader;
        _verifyThread = nullptr;
        _loader = nullptr;
        _quit = false;
    }
}

void downloader::init()
{
    if (_loader) {
        return;
    }
    
    _verifyThread = new std::thread(&downloader::start);
    
    DownloaderHints hints = {6, 10, ".tmp"};
    _loader = new Downloader(hints);
    _loader->onTaskError = [](const DownloadTask &task, int errorCode, int errorCodeInternal, const std::string &errorStr) {
        FileTask file;
        file.md5 = task.identifier;
        file.url = task.requestURL;
        file.storagePath = task.storagePath;
        file.state = FileState::IOERROR;
        
        std::lock_guard<std::mutex> lck(_mutex);
        _tasks.push_back(file);
        _cond.notify_one();
    };
    _loader->onFileTaskSuccess = [](const DownloadTask &task) {
        FileTask file;
        file.md5 = task.identifier;
        file.url = task.requestURL;
        file.storagePath = task.storagePath;
        file.state = FileState::LOADED;
        
        std::lock_guard<std::mutex> lck(_mutex);
        _tasks.push_back(file);
        _cond.notify_one();
    };
}

void downloader::setDispatcher(const std::function<void(const FileTask &)> callback)
{
    _callback = callback;
}
    
static bool verifyFile(const downloader::FileTask &task)
{
    unsigned char result[MD5_STR_LEN];
    return md5f(result, task.storagePath.c_str()) &&
        strcaseequal((const char *)result, task.md5.c_str());
}

void downloader::load(const FileTask &task)
{
    auto path = task.storagePath;
    auto pos = path.find_last_of("/");
    
    if (pos != std::string::npos) {
        path = path.substr(0, pos);
    }
    
    filesystem::createDirectory(path);
    filesystem::remove(task.storagePath + ".tmp");
    _loader->createDownloadFileTask(task.url, task.storagePath, task.md5);
}

void downloader::start()
{
    while (!_quit) {
        _mutex.lock();
        if (_tasks.size() > 0) {
            FileTask task = _tasks.back();
            _tasks.pop_back();
            _mutex.unlock();
            
            if (task.state == FileState::LOADED) {
                if (task.md5.size() > 0) {
                    task.state = verifyFile(task) ? FileState::VALID : FileState::INVALID;
                } else {
                    task.state = FileState::VALID;
                }
            }
            
            if (task.state != FileState::VALID) {
                filesystem::remove(task.storagePath);
            }
            
            cocos2d::Director::getInstance()->getScheduler()->performFunctionInCocosThread([task]() {
                if (_callback) {
                    _callback(task);
                }
            });
            
            continue;
        } else {
            _mutex.unlock();
        }
        
        std::unique_lock<std::mutex> lck(_mutex);
        _cond.wait(lck);
    }
}
    
NS_XGAME_END
