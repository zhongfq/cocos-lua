#ifndef __CCLUA_RUNTIME_PRIVATE_H__
#define __CCLUA_RUNTIME_PRIVATE_H__

#include "platform/CCPlatformConfig.h"
#include "cclua/runtime.h"

#include <string>
#include <functional>

NS_CCLUA_BEGIN

std::string __runtime_getPackageName();
std::string __runtime_getAppName();
std::string __runtime_getAppVersion();
std::string __runtime_getAppBuild();
std::string __runtime_getChannel();
std::string __runtime_getDeviceInfo();
std::string __runtime_getLanguage();
std::string __runtime_getNetworkStatus();
void __runtime_openURL(const std::string &uri, const std::function<void (bool)> callback);
bool __runtime_canOpenURL(const std::string &uri);

#ifdef CCLUA_OS_IOS
void __runtime_alert(const std::string &title, const std::string &message, const std::string &ok, const std::string &no, const std::function<void (bool)> callback);
#else
void __runtime_alert(const std::string &title, const std::string &message, const std::string &ok, const std::string &no, const std::function<void (bool)> &callback);
#endif

uint32_t __runtime_getMaxFrameRate();

#ifdef CCLUA_OS_IOS
void __runtime_setAudioSessionCatalog(const std::string &catalog);
std::string __runtime_getAudioSessionCatalog();
#endif

#if defined(CCLUA_OS_IOS) || defined(CCLUA_OS_ANDROID)
std::string __runtime_getPermission(const std::string &permission);
void __runtime_requestPermission(const std::string &permission, const std::function<void (const std::string &)> callback);
#endif

#ifdef CCLUA_OS_ANDROID
void __runtime_installAPK(const std::string &path);
void __runtime_pullAllFeatures();
#endif

#ifdef CCLUA_OS_WIN32
void __runtime_setPackageName(const std::string &packageName);
void __runtime_setAppName(const std::string &appName);
#endif

std::string __runtime_getPaste();
void __runtime_setPaste(const std::string &text);

NS_CCLUA_END

#endif
