#ifndef __CCLUA_RUNTIME_PRIVATE_H__
#define __CCLUA_RUNTIME_PRIVATE_H__

#include "platform/CCPlatformConfig.h"
#include "cclua/runtime.h"

#include <string>
#include <functional>

NS_CCLUA_BEGIN

const std::string __runtime_getPackageName();
const std::string __runtime_getAppVersion();
const std::string __runtime_getAppBuild();
const std::string __runtime_getChannel();
const std::string __runtime_getDeviceInfo();
const std::string __runtime_getLanguage();
const std::string __runtime_getNetworkStatus();
void __runtime_openURL(const std::string uri, const std::function<void (bool)> callback);
bool __runtime_canOpenURL(const std::string uri);

#ifdef CCLUA_OS_IOS
void __runtime_setAudioSessionCatalog(const std::string &catalog);
const std::string __runtime_getAudioSessionCatalog();
void __runtime_alert(const std::string title, const std::string message, const std::string ok, const std::string no, const std::function<void (bool)> callback);
cclua::PermissionStatus __runtime_getPermissionStatus(cclua::Permission permission);
void __runtime_requestPermission(cclua::Permission permission, const std::function<void (cclua::PermissionStatus)> callback);
#endif

#ifdef CCLUA_OS_ANDROID
void __runtime_pullAllFeatures();
#endif

#ifdef CCLUA_OS_WIN32
void __runtime_setPackageName(const std::string &packageName);
#endif

NS_CCLUA_END

#endif
