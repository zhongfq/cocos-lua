#ifndef __XGAME_FILESYSTEM_PRIVATE_H__
#define __XGAME_FILESYSTEM_PRIVATE_H__

#include "xgame/runtime.h"

#include <string>

NS_XGAME_BEGIN

const std::string __filesystem_getCacheDirectory();
const std::string __filesystem_getDocumentDirectory();
const std::string __filesystem_getTmpDirectory();

#if defined(CCLUA_OS_MAC) || defined(CCLUA_OS_WIN32)
const std::string __filesystem_getAppDataDirectory();
#endif

#ifdef CCLUA_OS_ANDROID
const std::string __filesystem_getSDCardDirectory();
const std::string __filesystem_getDir(const std::string &type);
#endif

NS_XGAME_END

#endif
