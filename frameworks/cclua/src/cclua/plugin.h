#ifndef __CCLUA_PLUGIN_H__
#define __CCLUA_PLUGIN_H__

#include "cclua/runtime.h"
#include "cjson/cJSON.h"

#ifdef CCLUA_OS_ANDROID
#include "cclua/jniutil.h"
#endif

#include <set>

NS_CCLUA_PLUGIN_BEGIN

std::string toJSONString(const cocos2d::ValueMap &value);
std::string toJSONString(const std::set<std::string> &tags);
void parseJSONString(const std::string &value, cocos2d::ValueMap &result);

NS_CCLUA_PLUGIN_END

#endif
