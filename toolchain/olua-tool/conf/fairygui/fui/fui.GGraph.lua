local cls = class()
cls.CPPCLS = "fairygui::GGraph"
cls.LUACLS = "fui.GGraph"
cls.SUPERCLS = "fui.GObject"
cls.funcs [[
    static GGraph* create()
    void drawRect(float aWidth, float aHeight, int lineSize, const cocos2d::Color4F& lineColor, const cocos2d::Color4F& fillColor)
    void drawEllipse(float aWidth, float aHeight, int lineSize, const cocos2d::Color4F& lineColor, const cocos2d::Color4F& fillColor)
    bool isEmpty()
    cocos2d::Color3B getColor()
    void setColor(const cocos2d::Color3B& value)
]]

cls.props [[
    empty
    color
]]

return cls