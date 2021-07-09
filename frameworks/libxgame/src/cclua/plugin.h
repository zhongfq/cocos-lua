#ifndef __CCLUA_PLUGIN_H__
#define __CCLUA_PLUGIN_H__

#include "cclua/runtime.h"
#include "cjson/cJSON.h"

NS_CCLUA_PLUGIN_BEGIN

typedef std::function<void(const std::string &event, const cocos2d::ValueMap &data)> Dispatcher;
typedef std::function<void(const cocos2d::ValueMap &data)> Callback;

#define DISPATCHER_IMPL                                                                 \
static void setDispatcher(const Dispatcher &dispatcher) { _dispatcher = dispatcher; }   \
static void dispatch(const std::string &event, cocos2d::ValueMap &data)                 \
{                                                                                       \
    cclua::runtime::runOnCocosThread([=]() {                                            \
        if (_dispatcher) {                                                              \
            _dispatcher(event, data);                                                   \
        }                                                                               \
    });                                                                                 \
}                                                                                       \
private:                                                                                \
    static Dispatcher _dispatcher;

std::string toJSONString(const cocos2d::ValueMap &value);
std::string toJSONString(const std::set<std::string> &tags);
void parseJSONString(const std::string &value, cocos2d::ValueMap &result);

NS_CCLUA_PLUGIN_END

#endif
