local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::Application::Platform"
cls.LUACLS = "cc.Application.Platform"
cls.enums [[
    OS_WINDOWS
    OS_LINUX
    OS_MAC
    OS_ANDROID
    OS_IPHONE
    OS_IPAD
    OS_BLACKBERRY
    OS_NACL
    OS_EMSCRIPTEN
    OS_TIZEN
    OS_WINRT
    OS_WP8
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::LanguageType"
cls.LUACLS = "cc.LanguageType"
cls.enums [[
    ENGLISH
    CHINESE
    FRENCH
    ITALIAN
    GERMAN
    SPANISH
    DUTCH
    RUSSIAN
    KOREAN
    JAPANESE
    HUNGARIAN
    PORTUGUESE
    ARABIC
    NORWEGIAN
    POLISH
    TURKISH
    UKRAINIAN
    ROMANIAN
    BULGARIAN
    BELARUSIAN
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::Application"
cls.LUACLS = "cc.Application"
cls.funcs([[
    void setAnimationInterval(float interval)
    void setAnimationInterval(float interval, SetIntervalReason reason)
    static Application* getInstance()
    LanguageType getCurrentLanguage()
    const char * getCurrentLanguageCode()
    Platform getTargetPlatform()
    std::string getVersion()
    bool openURL(const std::string &url)
]])
return M