#include "cclua/downloader.h"
#include "cclua/filesystem.h"
#include "md5/md5util.h"

#include "platform/CCFileUtils.h"
#include "network/CCDownloader.h"

#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <regex>
#include <condition_variable>

using namespace cocos2d;
using namespace cocos2d::network;

NS_CCLUA_BEGIN

static cocos2d::network::Downloader *_loader = nullptr;
static downloader::EventDispatcher _dispatcher = nullptr;
static downloader::URIResolver _resolver = nullptr;
static std::unordered_map<std::string, downloader::Task> _uri2Tasks;
static std::vector<downloader::Task> _tasks;
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
        std::lock_guard<std::mutex> lck(_mutex);
        Task t = _uri2Tasks[task.identifier];
        t.state = TaskState::IOERROR;
        _uri2Tasks.erase(task.identifier);
        _tasks.push_back(t);
        _cond.notify_one();
    };
    _loader->onFileTaskSuccess = [](const DownloadTask &task) {
        std::lock_guard<std::mutex> lck(_mutex);
        Task t = _uri2Tasks[task.identifier];
        _uri2Tasks.erase(task.identifier);
        if (FileUtils::getInstance()->getFileSize(t.path) != t.size || t.size == 0) {
            t.state = TaskState::IOERROR;
        } else {
            t.state = TaskState::PENDING;
        }
        _tasks.push_back(t);
        _cond.notify_one();
    };
    _loader->onTaskProgress = [](const DownloadTask& task, int64_t bytesReceived, int64_t totalBytesReceived, int64_t totalBytesExpected) {
        std::lock_guard<std::mutex> lck(_mutex);
        Task &t = _uri2Tasks[task.identifier];
        t.size = totalBytesExpected;
    };
}

void downloader::load(const std::string &uri, const std::string &path, const std::string &md5)
{
    const std::string tmp = path + ".tmp";
    filesystem::createDirectory(path, true);
    if (filesystem::exist(tmp)) {
        filesystem::remove(tmp);
    }
    Task task;
    task.uri = uri;
    task.path = path;
    task.md5 = md5;
    task.state = TaskState::INVALID;
    task.size = 0;
    if (std::regex_search(task.uri, std::regex("^https?://"))) {
        task.url = task.uri;
    } else {
        CCASSERT(_resolver != nullptr, "uri resolver not set");
        task.url = _resolver(task.uri);
    }
    
    std::lock_guard<std::mutex> lck(_mutex);
    _uri2Tasks[task.uri] = task;
    _loader->createDownloadFileTask(task.url, task.path, task.uri);
}

void downloader::setDispatcher(const EventDispatcher &dispatcher)
{
    _dispatcher = dispatcher;
}

void downloader::setURIResolver(const URIResolver &resolver)
{
    _resolver = resolver;
}
    
static bool verifyFile(const downloader::Task &task)
{
    unsigned char result[MD5_STR_LEN];
    return md5f(result, task.path.c_str()) &&
        strcaseequal((const char *)result, task.md5.c_str());
}

void downloader::start()
{
    static const char *const state[] = {"invalid", "ioerror", "pending", "success"};
    while (!_quit) {
        _mutex.lock();
        if (_tasks.size() > 0) {
            Task task = _tasks.back();
            _tasks.pop_back();
            _mutex.unlock();
            
            if (task.state == TaskState::PENDING) {
                if (task.md5.size() > 0) {
                    task.state = verifyFile(task) ? TaskState::SUCCESS : TaskState::INVALID;
                } else {
                    task.state = TaskState::SUCCESS;
                }
            }
            
            if (task.state != TaskState::SUCCESS && filesystem::exist(task.path)) {
                filesystem::remove(task.path);
            }
            
            runtime::runOnCocosThread([task] {
                if (_dispatcher) {
                    _dispatcher(state[(int)task.state], task.uri);
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
    
NS_CCLUA_END
