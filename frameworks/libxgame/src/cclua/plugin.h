#ifndef __CCLUA_PLUGIN_H__
#define __CCLUA_PLUGIN_H__

#include "cclua/runtime.h"

NS_CCLUA_PLUGIN_BEGIN

typedef std::function<void(const std::string &event, const cocos2d::ValueMap &data)> Dispatcher;

NS_CCLUA_PLUGIN_END

#endif
