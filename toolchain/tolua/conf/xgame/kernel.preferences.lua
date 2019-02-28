local cls = class()
cls.NATIVE = "xgame::preferences"
cls.CLASS = "kernel.preferences"
cls.STATIC = true
cls.func(nil, 'static bool getBoolean(const char *key, bool defaultValue = false)')
cls.func(nil, 'static void setBoolean(const char *key, bool value)')
cls.func(nil, 'static float getFloat(const char *key, float defaultValue = 0)')
cls.func(nil, 'static void setFloat(const char *key, float value)')
cls.func(nil, 'static double getDouble(const char *key, double defaultValue = 0)')
cls.func(nil, 'static void setDouble(const char *key, double value)')
cls.func(nil, 'static int getInteger(const char *key, int defaultValue = 0)')
cls.func(nil, 'static void setInteger(const char *key, int value)')
cls.func(nil, 'static std::string getString(const char *key, const char *defaultValue = "")')
cls.func(nil, 'static void setString(const char *key, const char *value)')
cls.func(nil, 'static void deleteKey(const char *key)')
cls.func(nil, 'static void flush()')
return cls