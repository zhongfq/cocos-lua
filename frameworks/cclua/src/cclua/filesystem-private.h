#ifndef __CCLUA_FILESYSTEM_PRIVATE_H__
#define __CCLUA_FILESYSTEM_PRIVATE_H__

#include "cclua/runtime.h"

#include <string>

NS_CCLUA_BEGIN

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

NS_CCLUA_END

#endif
