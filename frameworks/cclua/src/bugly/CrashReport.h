#ifndef __CCLUA_BUGLY_H__
#define __CCLUA_BUGLY_H__

#include "cclua/plugin.h"

NS_CCLUA_BEGIN

class bugly
{
public:
	static void init(const char *appid);
    static void setUid(const char *uid);
	static void setTag(int tag);
    static void setUserValue(const char *key, const char *value);
    static void setChannel(const char *channel);
    static void setVersion(const char *version);
    
    static void reportException(const char *msg, const char *traceback);

    enum LogLevel {Off = 0, Error = 1, Warning = 2, Info = 3, Debug = 4, Verbose = 5};
    static void log(LogLevel level, const char *message);

private:
#ifdef CCLUA_OS_ANDROID
    static const char *JAVA_CLASS;
#endif
};

NS_CCLUA_END

#endif
