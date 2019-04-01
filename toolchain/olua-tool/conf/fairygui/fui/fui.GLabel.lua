local cls = class()
cls.CPPCLS = "fairygui::GLabel"
cls.LUACLS = "fui.GLabel"
cls.SUPERCLS = "fui.GComponent"
cls.funcs [[
    static GLabel *create()
    const std::string& getTitle()
    void setTitle(const std::string& value)
    cocos2d::Color3B getTitleColor()
    void setTitleColor(const cocos2d::Color3B& value)
    int getTitleFontSize()
    void setTitleFontSize(int value)
    GTextField* getTextField()
]]

cls.props [[
    title
    titleColor
    titleFontSize
    textField
]]

return cls