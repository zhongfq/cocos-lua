local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::experimental::ui::VideoPlayer::EventType"
cls.LUACLS = "ccui.VideoPlayer.EventType"
cls.DEFIF = '#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_TIZEN) && !defined(CC_PLATFORM_OS_TVOS)'
cls.enums [[
    PLAYING
    PAUSED
    STOPPED
    COMPLETED
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::experimental::ui::VideoPlayer::StyleType"
cls.LUACLS = "ccui.VideoPlayer.StyleType"
cls.DEFIF = '#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_TIZEN) && !defined(CC_PLATFORM_OS_TVOS)'
cls.enums [[
    DEFAULT
    NONE
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::experimental::ui::VideoPlayer"
cls.LUACLS = "ccui.VideoPlayer"
cls.SUPERCLS = "ccui.Widget"
cls.DEFIF = '#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_TIZEN) && !defined(CC_PLATFORM_OS_TVOS)'
cls.funcs [[
    static VideoPlayer* create()
    void setFileName(const std::string& videoPath)
    const std::string& getFileName()
    void setURL(const std::string& _videoURL)
    const std::string& getURL()
    void setLooping(bool looping)
    void setUserInputEnabled(bool enableInput)
    void setStyle(StyleType style)
    void play()
    void stop()
    void seekTo(float sec)
    bool isPlaying()
    bool isLooping()
    bool isUserInputEnabled()
    void setKeepAspectRatioEnabled(bool enable)
    bool isKeepAspectRatioEnabled()
    void setFullScreenEnabled(bool fullscreen)
    bool isFullScreenEnabled()
    void onPlayEvent(int event)
]]
cls.callback(
    'void addEventListener(@nullable const std::function<void(Ref*,VideoPlayer::EventType)>& callback)',
    {
        CALLBACK_MAKER = 'olua_makecallbacktag("VideoPlayerCallback")',
        CALLBACK_REPLACE = true,
        CALLBACK_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
    }
)
cls.props [[
    fileName
    url
    playing
    looping
    userInputEnabled
    keepAspectRatioEnabled
    fullScreenEnabled
]]

return M