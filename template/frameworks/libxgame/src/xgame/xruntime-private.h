#ifndef __XRUNTIME_PRIVATE_H__
#define __XRUNTIME_PRIVATE_H__

#include <string>

const std::string __runtime_getPackageName();
const std::string __runtime_getVersion();
const std::string __runtime_getVersionCode();
const std::string __runtime_getChannel();
const std::string __runtime_getDeviceInfo();

#endif
