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
    void play()
    void stop()
    void seekTo(float sec)
    bool isPlaying()
    void setKeepAspectRatioEnabled(bool enable)
    bool isKeepAspectRatioEnabled()
    void setFullScreenEnabled(bool fullscreen)
    bool isFullScreenEnabled()
    void onPlayEvent(int event)
]]
cls.callbacks([[
    void addEventListener(@nullable const std::function<void(Ref*,VideoPlayer::EventType)>& callback)
]], function (name)
    return 'olua_makecallbacktag("VideoPlayerCallback")'
end)
cls.props [[
    fileName
    url
    playing
    keepAspectRatioEnabled
    fullScreenEnabled
]]

return M