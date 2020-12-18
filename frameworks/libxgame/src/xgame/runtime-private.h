#ifndef __XGAME_RUNTIME_PRIVATE_H__
#define __XGAME_RUNTIME_PRIVATE_H__

#include "platform/CCPlatformConfig.h"
#include "xgame/runtime.h"

#include <string>
#include <functional>

NS_XGAME_BEGIN

const std::string __runtime_getPackageName();
const std::string __runtime_getAppVersion();
const std::string __runtime_getAppBuild();
const std::string __runtime_getChannel();
const std::string __runtime_getDeviceInfo();
const std::string __runtime_getLanguage();
const std::string __runtime_getNetworkStatus();
void __runtime_openURL(const std::string uri, const std::function<void (bool)> callback);
bool __runtime_canOpenURL(const std::string uri);

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
void __runtime_setAudioSessionCatalog(const std::string &catalog);
const std::string __runtime_getAudioSessionCatalog();
void __runtime_alert(const std::string title, const std::string message, const std::string ok, const std::string no, const std::function<void (bool)> callback);
xgame::PermissionStatus __runtime_getPermissionStatus(xgame::Permission permission);
void __runtime_requestPermission(xgame::Permission permission, const std::function<void (xgame::PermissionStatus)> callback);
std::string __runtime_getIDFA();
bool __runtime_isAdvertisingTrackingEnabled();
#endif

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
void __runtime_pullAllFeatures();
#endif

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
void __runtime_setPackageName(const std::string &packageName);
#endif

NS_XGAME_END

#endif
