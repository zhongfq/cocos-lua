#ifndef __CCLUA_PREFERENCES_H__
#define __CCLUA_PREFERENCES_H__

#include "cclua/runtime.h"

#include <stdio.h>
#include <string>

NS_CCLUA_BEGIN

class preferences {
public:
    static bool getBoolean(const std::string &key, bool defaultValue = false);
    static void setBoolean(const std::string &key, bool value);
    static float getFloat(const std::string &key, float defaultValue = 0);
    static void setFloat(const std::string &key, float value);
    static double getDouble(const std::string &key, double defaultValue = 0);
    static void setDouble(const std::string &key, double value);
    static int getInteger(const std::string &key, int defaultValue = 0);
    static void setInteger(const std::string &key, int value);
    static std::string getString(const std::string &key, const std::string &defaultValue = "");
    static void setString(const std::string &key, const std::string &value);
    static void deleteKey(const std::string &key);
    static void flush();
private:
    static void delayFlush();
};

NS_CCLUA_END

#endif
