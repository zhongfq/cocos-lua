#ifndef __XFILESYSTEM_PRIVATE_H__
#define __XFILESYSTEM_PRIVATE_H__

#include "xgame/xdef.h"

#include <string>

const std::string __filesystem_getCacheDirectory();
const std::string __filesystem_getDocumentDirectory();
const std::string __filesystem_getTmpDirectory();

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
const std::string __filesystem_getSDCardDirectory();
const std::string __filesystem_getDir(const std::string &type);
#endif

#endif
