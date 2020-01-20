#ifndef __XGAME_XML_HTTP_REQUEST_H__
#define __XGAME_XML_HTTP_REQUEST_H__

#include "cocos2d.h"
#include "network/HttpClient.h"

#include <functional>

NS_CC_BEGIN

class XMLHttpRequest : public cocos2d::Ref
{
public:
    enum class ResponseType
    {
        STRING,
        ARRAY_BUFFER,
        BLOB,
        DOCUMENT,
        JSON
    };
    
    // Ready States (http://www.w3.org/TR/XMLHttpRequest/#interface-xmlhttprequest)
    static const unsigned short UNSENT = 0;
    static const unsigned short OPENED = 1;
    static const unsigned short HEADERS_RECEIVED = 2;
    static const unsigned short LOADING = 3;
    static const unsigned short DONE = 4;
    
    XMLHttpRequest();
    virtual ~XMLHttpRequest();
    
    // request
    const std::string& getURL() { return _url; }
    int getReadyState() const { return _readyState; }
    void open(const std::string &method, const std::string &url);
    void setRequestHeader(const std::string &name, const std::string &value);
    void setTimeout(unsigned int value);
    unsigned int getTimeout() const { return _timeout; }
    void setWithCredentials(bool value) { _withCredentialsValue = value; }
    bool getWithCredentials() const { return _withCredentialsValue; }
    void send(const char *data = nullptr, size_t len = 0);
    void abort();
    bool isAborted() const { return _aborted; }
    
    const std::string getResponseURL();
    void setResponseType(ResponseType value) { _responseType = value; }
    ResponseType getResponseType() const { return _responseType; }
    int getStatus() { return _status; }
    const std::string &getStatusText() const { return _statusText; };
    const std::string getResponseHeader(const std::string &name) const;
    const std::unordered_map<std::string, std::string>& getAllResponseHeaders() const { return _responseHeaders;}
    
    inline const std::string& getDataStr() const { return _data; }
    inline size_t getDataSize() const { return _dataSize; }
    inline void setErrorFlag(bool errorFlag) { _errorFlag = errorFlag; }
    inline bool getErrorFlag() const { return _errorFlag; }
    
    void setResponseCallback(std::function<void(XMLHttpRequest *)> handler) { _callback = handler; }
    
    inline cocos2d::network::HttpRequest* getHttpRequest() const { return _httpRequest; }
    
private:
    void doSendRequest();
    void parseResponseHeader(const std::string& header);
    
    std::string _url;
    std::string _data;
    size_t _dataSize;
    int _readyState;
    int _status;
    std::string _statusText;
    ResponseType _responseType;
    unsigned int _timeout;
    cocos2d::network::HttpRequest* _httpRequest;
    bool _withCredentialsValue;
    std::unordered_map<std::string, std::string> _responseHeaders;
    std::unordered_map<std::string, std::string> _requestHeaders;
    bool _errorFlag;
    bool _aborted;
    std::function<void(XMLHttpRequest *)> _callback;
};

NS_CC_END

#endif
