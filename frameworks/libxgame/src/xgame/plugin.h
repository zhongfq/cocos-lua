#ifndef __XGAME_PLUGIN_H__
#define __XGAME_PLUGIN_H__

#include "xgame/runtime.h"

NS_XPLUGIN_BEGIN

typedef std::function<void(const std::string &event, const cocos2d::ValueMap &data)> Dispatcher;

NS_XPLUGIN_END

#endif
