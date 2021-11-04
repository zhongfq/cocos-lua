#ifndef __CCLUA_DOWNLOADER_H__
#define __CCLUA_DOWNLOADER_H__

#include "cclua/runtime.h"

#include <string>
#include <functional>

NS_CCLUA_BEGIN

class downloader
{
public:
    enum class TaskState {
        INVALID = 0,
        IOERROR,
        PENDING,
        SUCCESS,
    };
    
    struct Task {
        std::string uri;
        std::string path;
        std::string md5;
        TaskState state = TaskState::INVALID;
        
        std::string url;
        int64_t size = 0;
    };
    
    typedef std::function<void(const std::string &state, const std::string &uri)> EventDispatcher;
    typedef std::function<std::string(const std::string &uri)> URIResolver;
        
    static void load(const std::string &uri, const std::string &path, const std::string &md5 = "");
    static void setDispatcher(const EventDispatcher &dispatcher);
    static void setURIResolver(const URIResolver &resolver);

    static void init();
    static void end();
private:
    static void start();
};
    
NS_CCLUA_END

#endif
