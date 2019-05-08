#ifndef __XRUNTIME_PRIVATE_H__
#define __XRUNTIME_PRIVATE_H__

#include "platform/CCPlatformConfig.h"

#include <string>

const std::string __runtime_getPackageName();
const std::string __runtime_getVersion();
const std::string __runtime_getVersionBuild();
const std::string __runtime_getChannel();
const std::string __runtime_getDeviceInfo();
const std::string __runtime_getNativeStackTrace();
const std::string __runtime_getLanguage();
void __runtime_openURL(const std::string &uri, const std::function<void (bool)> callback);
bool __runtime_canOpenURL(const std::string &uri);

void __runtime_setAudioSessionCatalog(const std::string &catalog);
const std::string __runtime_getAudioSessionCatalog();

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
void __runtime_pullAllFeatures();
#endif

#endif
