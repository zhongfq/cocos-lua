local cls = class()
cls.CPPCLS = "fairygui::GImage"
cls.LUACLS = "fgui.GImage"
cls.SUPERCLS = "fgui.GObject"
cls.funcs [[
    static GImage *create()
    FlipType getFlip()
    void setFlip(FlipType value)
    cocos2d::Color3B getColor()
    void setColor(const cocos2d::Color3B& value)
    FillMethod getFillMethod()
    void setFillMethod(FillMethod value)
    FillOrigin getFillOrigin()
    void setFillOrigin(FillOrigin value)
    bool isFillClockwise()
    void setFillClockwise(bool value)
    float getFillAmount()
    void setFillAmount(float value)
]]

cls.props [[
    flip
    color
    fillMethod
    fillOrigin
    fillClockwise
    fillAmount
]]

return cls