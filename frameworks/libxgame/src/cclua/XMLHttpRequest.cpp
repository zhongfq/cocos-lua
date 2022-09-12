#include "cclua/XMLHttpRequest.h"
#include "cclua/runtime.h"
#include "cclua/timer.h"
#include "cjson/lua_cjson.h"

USING_NS_CCLUA;
USING_NS_CC;

XMLHttpRequest::XMLHttpRequest()
:_url("")
,_dataSize(0)
,_readyState(UNSENT)
,_status(0)
,_statusText("")
,_responseType(ResponseType::STRING)
,_timeout(0)
,_withCredentialsValue(true)
,_errorFlag(false)
,_aborted(false)
,_callback(nullptr)
{
    _responseHeaders.clear();
    _requestHeaders.clear();
    _httpRequest = new (std::nothrow)cocos2d::network::HttpRequest();
}

XMLHttpRequest::~XMLHttpRequest()
{
    _responseHeaders.clear();
    _requestHeaders.clear();
    CC_SAFE_RELEASE_NULL(_httpRequest);
}

void XMLHttpRequest::open(const std::string &method, const std::string &url)
{
    _readyState = OPENED;
    _url = url;
    _status = 0;
    
    _httpRequest->setUrl(url);
    
    if (strcaseequal(method.c_str(), "post")) {
        _httpRequest->setRequestType(network::HttpRequest::Type::POST);
    } else if (strcaseequal(method.c_str(), "get")) {
        _httpRequest->setRequestType(network::HttpRequest::Type::GET);
    } else if (strcaseequal(method.c_str(), "put")) {
        _httpRequest->setRequestType(network::HttpRequest::Type::PUT);
    } else if (strcaseequal(method.c_str(), "delete")) {
        _httpRequest->setRequestType(network::HttpRequest::Type::DELETE);
    }
}

void XMLHttpRequest::setRequestHeader(const std::string &name, const std::string &value)
{
    std::stringstream value_s;
    auto iter = _requestHeaders.find(name);
    if (iter != _requestHeaders.end()) {
        value_s << iter->second << "," << value;
    } else {
        value_s << value;
    }
    _requestHeaders[name] = value_s.str();
}

void XMLHttpRequest::setTimeout(unsigned int value)
{
    _timeout = value;
}

void XMLHttpRequest::send(const cocos2d::Data &data)
{
    if (_httpRequest->getCallback()) {
        return;
    }
    
    if (data.getSize() > 0) {
        _httpRequest->setRequestData((const char *)data.getBytes(), (size_t)data.getSize());
    }
    
    _responseHeaders.clear();
    
    if (_requestHeaders.size() > 0) {
        std::vector<std::string> headers;
        for (auto it = _requestHeaders.begin(); it != _requestHeaders.end(); ++it) {
            headers.push_back(it->first + ": " + it->second);
        }
        _httpRequest->setHeaders(headers);
    }
    
    retain();
    
    doSendRequest();
    
    if (_timeout > 0) {
        auto scheduler = cocos2d::Director::getInstance()->getScheduler();
        scheduler->schedule([this, scheduler](float dt) {
            scheduler->unscheduleAllForTarget(this);
            _httpRequest->setResponseCallback(nullptr);
            _aborted = true;
            _status = 408; // timeout
            if (_callback) {
                _callback(_status);
            }
            release();
        }, this, (float)_timeout, false, "timeout");
    }
}

void XMLHttpRequest::send()
{
    Data data;
    send(data);
}

void XMLHttpRequest::abort()
{
    _aborted = true;
}

const std::string &XMLHttpRequest::getResponseURL()
{
    return _url;
}

const char *XMLHttpRequest::getResponseHeader(const std::string &name) const
{
    auto it = _responseHeaders.find(name);
    if (it != _responseHeaders.end()) {
        return it->second.c_str();
    } else {
        return nullptr;
    }
}

void XMLHttpRequest::doSendRequest()
{
    _httpRequest->setResponseCallback([this](cocos2d::network::HttpClient* sender, cocos2d::network::HttpResponse* response) {
        auto scheduler = cocos2d::Director::getInstance()->getScheduler();
        scheduler->unscheduleAllForTarget(this);
        
        if (_aborted) {
            if (_callback) {
                _callback(_status);
            }
            release();
            return;
        }
        
        long statusCode = response->getResponseCode();
        if (!response->isSucceed()) {
            CCLOG("Response failed, error buffer: %s", response->getErrorBuffer());
            if(statusCode == 0) {
                _errorFlag = true;
                _status = 0;
                _statusText.clear();
            }
            
            if (_callback) {
                _callback(_status);
            }
            release();
            return;
        }
        
        // set header
        std::vector<char> *headers = response->getResponseHeader();
        
        std::string header(headers->begin(), headers->end());
        std::istringstream stream(header);
        std::string line;
        while(std::getline(stream, line)) {
            parseResponseHeader(line);
        }
        
        std::vector<char> *buffer = response->getResponseData();
        
        if (statusCode == 200) {
            _status = (int)statusCode;
            _readyState = DONE;
            _data.assign(buffer->begin(), buffer->end());
            _dataSize = buffer->size();
        } else {
            _status = (int)statusCode;
        }
        
        if (_callback) {
            _callback(_status);
        }
        
        release();
    });
    network::HttpClient::getInstance()->sendImmediate(_httpRequest);
}

void XMLHttpRequest::parseResponseHeader(const std::string& header)
{
    size_t idx = header.find_first_of(":");
    if (idx != std::string::npos) {
        std::string name = header.substr(0, idx);
        std::string value = header.substr(idx + 1, header.length());
        while (value.length() > 0 && value[value.size() - 1] == '\n') {
            value.erase(value.size() - 1);
        }
        _responseHeaders[name] = value;
    } else {
        const char *str = header.c_str();
        str = strstr(str, "HTTP");
        if (str && (str = strstr(str, " ")) != nullptr) {
            str++;
            _statusText = std::string(str);
            while (_statusText.length() > 0 && _statusText[_statusText.size() - 1] == '\n') {
                _statusText.erase(_statusText.size() - 1);
            }
        }
    }
}

olua_Return XMLHttpRequest::Extend::getResponse(lua_State *L)
{
    XMLHttpRequest *request = olua_toobj<XMLHttpRequest>(L, 1);
    if (request->getResponseType() == XMLHttpRequest::ResponseType::JSON) {
        luaL_requiref(L, "__private_cjson_safe", luaopen_cjson_safe, false);
        lua_getfield(L, -1, "decode");
        luaL_checktype(L, -1, LUA_TFUNCTION);
        lua_pushlstring(L, request->getDataStr().c_str(), request->getDataSize());
        lua_pcall(L, 1, 1, 0);
    } else if (request->getResponseType() == XMLHttpRequest::ResponseType::ARRAY_BUFFER) {
        int len = (int)request->getDataSize();
        lua_createtable(L, 0, len);
        const char *str = request->getDataStr().c_str();
        for (int i = 0; i < len; i++) {
            lua_pushinteger(L, str[i]);
            lua_rawseti(L, -2, i + 1);
        }
    } else {
        lua_pushlstring(L, request->getDataStr().c_str(), request->getDataSize());
    }
    return 1;
}
