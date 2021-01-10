#ifndef __CCLUA_PREFERENCES_H__
#define __CCLUA_PREFERENCES_H__

#include "cclua/runtime.h"

#include <stdio.h>
#include <string>

NS_CCLUA_BEGIN

class preferences {
public:
    static bool getBoolean(const char *key, bool defaultValue = false);
    static void setBoolean(const char *key, bool value);
    static float getFloat(const char *key, float defaultValue = 0);
    static void setFloat(const char *key, float value);
    static double getDouble(const char *key, double defaultValue = 0);
    static void setDouble(const char *key, double value);
    static int getInteger(const char *key, int defaultValue = 0);
    static void setInteger(const char *key, int value);
    static std::string getString(const char *key, const char *defaultValue = "");
    static void setString(const char *key, const char *value);
    static void deleteKey(const char *key);
    static void flush();
private:
    static void delayFlush();
};

NS_CCLUA_END

#endif
