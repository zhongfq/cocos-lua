local cls = class()
cls.CPPCLS = "fairygui::GLoader"
cls.LUACLS = "fui.GLoader"
cls.SUPERCLS = "fui.GObject"
cls.funcs [[
    static GLoader *create()
    const std::string& getURL()
    void setURL(const std::string& value)
    cocos2d::TextHAlignment getAlign()
    void setAlign(cocos2d::TextHAlignment value)
    cocos2d::TextVAlignment getVerticalAlign()
    void setVerticalAlign(cocos2d::TextVAlignment value)
    bool getAutoSize()
    void setAutoSize(bool value)
    LoaderFillType getFill()
    void setFill(LoaderFillType value)
    bool isShrinkOnly()
    void setShrinkOnly(bool value)
    const cocos2d::Size& getContentSize()
    cocos2d::Color3B getColor()
    void setColor(const cocos2d::Color3B& value)
    bool isPlaying()
    void setPlaying(bool value)
    int getFrame()
    void setFrame(int value)
    float getTimeScale()
    void setTimeScale(float value)
    void advance(float time)
    FillMethod getFillMethod()
    void setFillMethod(FillMethod value)
    FillOrigin getFillOrigin()
    void setFillOrigin(FillOrigin value)
    bool isFillClockwise()
    void setFillClockwise(bool value)
    float getFillAmount()
    void setFillAmount(float value)
    @ref(singleref component) GComponent* getComponent()
]]
cls.props [[
    url
    align
    verticalAlign
    autoSize
    fill
    shrinkOnly
    contentSize
    color
    playing
    frame
    timeScale
    fillMethod
    fillOrigin
    fillClockwise
    fillAmount
    component
]]
return cls