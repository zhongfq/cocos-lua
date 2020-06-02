#include "lua_xml_http_request.h"
#include "xgame/XMLHttpRequest.h"
#include "cjson/lua_cjson.h"

static int luaopen_cocos2d_XMLHttpRequest_ResponseType(lua_State *L)
{
    oluacls_class(L, "cc.XMLHttpRequest.ResponseType", nullptr);
    oluacls_const_integer(L, "STRING", (lua_Integer)cocos2d::XMLHttpRequest::ResponseType::STRING);
    oluacls_const_integer(L, "ARRAY_BUFFER", (lua_Integer)cocos2d::XMLHttpRequest::ResponseType::ARRAY_BUFFER);
    oluacls_const_integer(L, "BLOB", (lua_Integer)cocos2d::XMLHttpRequest::ResponseType::BLOB);
    oluacls_const_integer(L, "DOCUMENT", (lua_Integer)cocos2d::XMLHttpRequest::ResponseType::DOCUMENT);
    oluacls_const_integer(L, "JSON", (lua_Integer)cocos2d::XMLHttpRequest::ResponseType::JSON);
    
    return 1;
}

static int _cocos2d_XMLHttpRequest_new(lua_State *L)
{
    auto self = new cocos2d::XMLHttpRequest();
    self->autorelease();
    olua_push_cppobj<cocos2d::XMLHttpRequest>(L, self, nullptr);
    return 1;
}

static int _cocos2d_XMLHttpRequest_open(lua_State *L)
{
    auto self = olua_checkobj<cocos2d::XMLHttpRequest>(L, 1);
    const std::string method = olua_checkstring(L, 2);
    const std::string url = olua_checkstring(L, 3);
    self->open(method, url);
    return 0;
}

static int _cocos2d_XMLHttpRequest_setRequestHeader(lua_State *L)
{
    auto self = olua_checkobj<cocos2d::XMLHttpRequest>(L, 1);
    const std::string name = olua_checkstring(L, 2);
    const std::string value = olua_checkstring(L, 3);
    self->setRequestHeader(name, value);
    return 0;
}

static int _cocos2d_XMLHttpRequest_getAllResponseHeaders(lua_State *L)
{
    auto self = olua_checkobj<cocos2d::XMLHttpRequest>(L, 1);
    const auto headers = self->getAllResponseHeaders();
    lua_createtable(L, 0, (int)headers.size());
    for (auto it : headers) {
        lua_pushstring(L, it.first.c_str());
        lua_pushstring(L, it.second.c_str());
        lua_rawset(L, -3);
    }
    return 1;
}

static int _cocos2d_XMLHttpRequest_setResponseCallback(lua_State *L)
{
    auto self = olua_checkobj<cocos2d::XMLHttpRequest>(L, 1);
    void *cb_store = self;
    std::string func = olua_setcallback(L, cb_store, "responseCallback", 2, OLUA_TAG_REPLACE);
    int ref = olua_ref(L, 1);
    lua_Unsigned ctx = olua_context(L);
    self->setResponseCallback([cb_store, func, ref, ctx] (cocos2d::XMLHttpRequest *request) mutable {
        lua_State *L = olua_mainthread(NULL);
        if (L != NULL && (olua_context(L) == ctx)) {
            int top = lua_gettop(L);
            ctx = 0;
            olua_push_cppobj<cocos2d::XMLHttpRequest>(L, request, nullptr);
            olua_callback(L, cb_store, func.c_str(), 1);
            lua_settop(L, top);
            olua_unref(L, ref);
        }
    });
    return 0;
}

static int _cocos2d_XMLHttpRequest_send(lua_State *L)
{
    auto self = olua_checkobj<cocos2d::XMLHttpRequest>(L, 1);
    const char *data = nullptr;
    size_t len = 0;
    if (olua_isstring(L, 2)) {
        data = olua_checklstring(L, 2, &len);
    }
    self->send(data, len);
    return 1;
}

static int _cocos2d_XMLHttpRequest_abort(lua_State *L)
{
    auto self = olua_checkobj<cocos2d::XMLHttpRequest>(L, 1);
    self->abort();
    return 1;
}

static int _cocos2d_XMLHttpRequest_getResponseHeader(lua_State *L)
{
    auto self = olua_checkobj<cocos2d::XMLHttpRequest>(L, 1);
    const std::string name = olua_checkstring(L, 1);
    const std::string value = self->getResponseHeader(name);
    if (value.size() > 0) {
        lua_pushstring(L, value.c_str());
    } else {
        lua_pushnil(L);
    }
    return 1;
}

static int _cocos2d_XMLHttpRequest_isAborted(lua_State *L)
{
    auto self = olua_checkobj<cocos2d::XMLHttpRequest>(L, 1);
    olua_push_bool(L, self->isAborted());
    return 1;
}

static int _cocos2d_XMLHttpRequest_getReadyState(lua_State *L)
{
    auto self = olua_checkobj<cocos2d::XMLHttpRequest>(L, 1);
    olua_push_uint(L, self->getReadyState());
    return 1;
}

static int _cocos2d_XMLHttpRequest_getTimeout(lua_State *L)
{
    auto self = olua_checkobj<cocos2d::XMLHttpRequest>(L, 1);
    olua_push_uint(L, self->getTimeout());
    return 1;
}

static int _cocos2d_XMLHttpRequest_setTimeout(lua_State *L)
{
    auto self = olua_checkobj<cocos2d::XMLHttpRequest>(L, 1);
    unsigned int timeout = (unsigned int)olua_checkinteger(L, 2);
    self->setTimeout(timeout);
    return 0;
}

static int _cocos2d_XMLHttpRequest_getWithCredentials(lua_State *L)
{
    auto self = olua_checkobj<cocos2d::XMLHttpRequest>(L, 1);
    olua_push_bool(L, self->getWithCredentials());
    return 1;
}

static int _cocos2d_XMLHttpRequest_setWithCredentials(lua_State *L)
{
    auto self = olua_checkobj<cocos2d::XMLHttpRequest>(L, 1);
    bool value = olua_checkboolean(L, 2);
    self->setWithCredentials(value);
    return 0;
}

static int _cocos2d_XMLHttpRequest_getResponseURL(lua_State *L)
{
    auto self = olua_checkobj<cocos2d::XMLHttpRequest>(L, 1);
    lua_pushstring(L, self->getResponseURL().c_str());
    return 1;
}

static int _cocos2d_XMLHttpRequest_getResponseType(lua_State *L)
{
    auto self = olua_checkobj<cocos2d::XMLHttpRequest>(L, 1);
    lua_pushinteger(L, (lua_Integer)self->getResponseType());
    return 1;
}

static int _cocos2d_XMLHttpRequest_setResponseType(lua_State *L)
{
    auto self = olua_checkobj<cocos2d::XMLHttpRequest>(L, 1);
    auto type = (cocos2d::XMLHttpRequest::ResponseType)olua_checkinteger(L, 2);
    self->setResponseType(type);
    return 1;
}

static int _cocos2d_XMLHttpRequest_getStatus(lua_State *L)
{
    auto self = olua_checkobj<cocos2d::XMLHttpRequest>(L, 1);
    lua_pushinteger(L, self->getStatus());
    return 1;
}

static int _cocos2d_XMLHttpRequest_getStatusText(lua_State *L)
{
    auto self = olua_checkobj<cocos2d::XMLHttpRequest>(L, 1);
    lua_pushstring(L, self->getStatusText().c_str());
    return 1;
}

static int _cocos2d_XMLHttpRequest_getResponse(lua_State *L)
{
    auto self = olua_checkobj<cocos2d::XMLHttpRequest>(L, 1);
    if (self->getResponseType() == cocos2d::XMLHttpRequest::ResponseType::JSON) {
        olua_requiref(L, "__private_cjson_safe", luaopen_cjson_safe, false);
        lua_getfield(L, -1, "decode");
        luaL_checktype(L, -1, LUA_TFUNCTION);
        lua_pushlstring(L, self->getDataStr().c_str(), self->getDataSize());
        lua_pcall(L, 1, 1, 0);
    } else if (self->getResponseType() == cocos2d::XMLHttpRequest::ResponseType::ARRAY_BUFFER) {
        int len = (int)self->getDataSize();
        lua_createtable(L, 0, len);
        const char *str = self->getDataStr().c_str();
        for (int i = 0; i < len; i++) {
            lua_pushinteger(L, str[i]);
            lua_rawseti(L, -2, i + 1);
        }
    } else {
        lua_pushlstring(L, self->getDataStr().c_str(), self->getDataSize());
    }
    return 1;
}

static int _cocos2d_XMLHttpRequest_getResponseText(lua_State *L)
{
    auto self = olua_checkobj<cocos2d::XMLHttpRequest>(L, 1);
    lua_pushlstring(L, self->getDataStr().c_str(), self->getDataSize());
    return 1;
}

static int luaopen_cocos2d_XMLHttpRequest(lua_State *L)
{
    oluacls_class(L, "cc.XMLHttpRequest", "cc.Ref");
    oluacls_func(L, "new", _cocos2d_XMLHttpRequest_new);
    oluacls_func(L, "open", _cocos2d_XMLHttpRequest_open);
    oluacls_func(L, "setRequestHeader", _cocos2d_XMLHttpRequest_setRequestHeader);
    oluacls_func(L, "send", _cocos2d_XMLHttpRequest_send);
    oluacls_func(L, "abort", _cocos2d_XMLHttpRequest_abort);
    oluacls_func(L, "getResponseHeader", _cocos2d_XMLHttpRequest_getResponseHeader);
    oluacls_func(L, "getAllResponseHeaders", _cocos2d_XMLHttpRequest_getAllResponseHeaders);
    oluacls_func(L, "setResponseCallback", _cocos2d_XMLHttpRequest_setResponseCallback);
    oluacls_prop(L, "aborted", _cocos2d_XMLHttpRequest_isAborted, nullptr);
    oluacls_prop(L, "readyState", _cocos2d_XMLHttpRequest_getReadyState, nullptr);
    oluacls_prop(L, "timeout", _cocos2d_XMLHttpRequest_getTimeout, _cocos2d_XMLHttpRequest_setTimeout);
    oluacls_prop(L, "withCredentials", _cocos2d_XMLHttpRequest_getWithCredentials, _cocos2d_XMLHttpRequest_setWithCredentials);
    oluacls_prop(L, "responseURL", _cocos2d_XMLHttpRequest_getResponseURL, nullptr);
    oluacls_prop(L, "responseType", _cocos2d_XMLHttpRequest_getResponseType, _cocos2d_XMLHttpRequest_setResponseType);
    oluacls_prop(L, "status", _cocos2d_XMLHttpRequest_getStatus, nullptr);
    oluacls_prop(L, "statusText", _cocos2d_XMLHttpRequest_getStatusText, nullptr);
    oluacls_prop(L, "response", _cocos2d_XMLHttpRequest_getResponse, nullptr);
    oluacls_prop(L, "responseText", _cocos2d_XMLHttpRequest_getResponseText, nullptr);
    
    olua_registerluatype<cocos2d::XMLHttpRequest>(L, "cc.XMLHttpRequest");
    
    return 1;
}

int luaopen_xml_http_request(lua_State *L)
{
    olua_require(L, "cc.XMLHttpRequest.ResponseType", luaopen_cocos2d_XMLHttpRequest_ResponseType);
    olua_require(L, "cc.XMLHttpRequest", luaopen_cocos2d_XMLHttpRequest);
    
    return 0;
}
