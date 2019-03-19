local cls = class()
cls.CPPCLS = "cocos2d::Device"
cls.LUACLS = "cc.Device"
cls.funcs([[
    static int getDPI()
    static void setAccelerometerEnabled(bool isEnabled)
    static void setAccelerometerInterval(float interval)
    static void setKeepScreenOn(bool keepScreenOn)
    static void vibrate(float duration)
    // static Data getTextureDataForText(const char * text, const FontDefinition& textDefinition, TextAlign align, int &width, int &height, bool& hasPremultipliedAlpha)
]])
return cls