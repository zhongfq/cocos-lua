#ifndef __XGAME_FILESYSTEM_PRIVATE_H__
#define __XGAME_FILESYSTEM_PRIVATE_H__

#include "xgame/runtime.h"

#include <string>

NS_XGAME_BEGIN

const std::string __filesystem_getCacheDirectory();
const std::string __filesystem_getDocumentDirectory();
const std::string __filesystem_getTmpDirectory();

#if CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
const std::string __filesystem_getAppDataDirectory();
#endif

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
const std::string __filesystem_getSDCardDirectory();
const std::string __filesystem_getDir(const std::string &type);
#endif

NS_XGAME_END

#endif
