local cls = class(M)
cls.CPPCLS = "fairygui::GMovieClip"
cls.LUACLS = "fui.GMovieClip"
cls.SUPERCLS = "fui.GObject"
cls.funcs [[
    static GMovieClip *create()
    bool isPlaying()
    void setPlaying(bool value)
    int getFrame()
    void setFrame(int value)
    float getTimeScale()
    void setTimeScale(float value)
    void advance(float time)
    FlipType getFlip()
    void setFlip(FlipType value)
    cocos2d::Color3B getColor()
    void setColor(const cocos2d::Color3B& value)
]]

cls.callbacks [[
    void setPlaySettings(int start = 0, int end = -1, int times = 0, int endAt = -1, std::function<void()> completeCallback = nullptr)
]]

cls.props [[
    playing
    frame
    timeScale
    flip
    color
]]

return cls