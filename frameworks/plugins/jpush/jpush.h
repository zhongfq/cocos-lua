#ifndef __CCLUA_PLUGIN_JPUSH_H__
#define __CCLUA_PLUGIN_JPUSH_H__

#include "cclua/plugin.h"

NS_CCLUA_PLUGIN_BEGIN

class jpush {
public:
    static void init(const std::string &appKey, const std::string &channel);
    static void setAlias(const std::string &alias);
    static void deleteAlias();
    static void addTags(const std::set<std::string> &tags);
    static void setTags(const std::set<std::string> &tags);
    static void deleteTags(const std::set<std::string> &tags);
    static void cleanTags();
    static void setDebug(bool enabled);
    static void setLogOFF();
    static void setBadge(int value);
    static bool isEnabled();
    static void requestPermission();
    static std::string getRegistrationID();
private:
#ifdef CCLUA_OS_ANDROID
    static const char *JAVA_CLASS;
#endif
};

NS_CCLUA_PLUGIN_END

#endif
