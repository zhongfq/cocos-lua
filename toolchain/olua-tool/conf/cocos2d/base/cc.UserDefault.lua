local cls = class()
cls.CPPCLS = "cocos2d::UserDefault"
cls.LUACLS = "cc.UserDefault"
cls.funcs [[
    bool getBoolForKey(const char *key)
    bool getBoolForKey(const char *key, bool defaultValue)
    int getIntegerForKey(const char *key)
    int getIntegerForKey(const char *key, int defaultValue)
    float getFloatForKey(const char *key)
    float getFloatForKey(const char *key, float defaultValue)
    double getDoubleForKey(const char *key)
    double getDoubleForKey(const char *key, double defaultValue)
    std::string getStringForKey(const char *key)
    std::string getStringForKey(const char *key, const std::string & defaultValue)
    void setBoolForKey(const char *key, bool value)
    void setIntegerForKey(const char *key, int value)
    void setFloatForKey(const char *key, float value)
    void setDoubleForKey(const char *key, double value)
    void setStringForKey(const char *key, const std::string & value)
    void flush()
    void deleteValueForKey(const char *key)
    static cocos2d::UserDefault *getInstance()
    static const std::string& getXMLFilePath()
    static bool isXMLFileExist()
]]
return cls