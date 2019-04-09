#ifndef __XPREFERENCES_H__
#define __XPREFERENCES_H__

#include "xgame/xdef.h"

#include <stdio.h>
#include <string>

NS_XGAME_BEGIN

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

NS_XGAME_END

#endif
