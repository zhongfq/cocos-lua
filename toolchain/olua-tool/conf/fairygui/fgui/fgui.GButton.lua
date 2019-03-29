local cls = class()
cls.CPPCLS = "fairygui::GButton"
cls.LUACLS = "fgui.GButton"
cls.SUPERCLS = "fgui.GComponent"
cls.funcs [[
    static GButton *create()
    const std::string& getTitle()
    void setTitle(const std::string& value)
    const std::string& getSelectedTitle()
    void setSelectedTitle(const std::string& value)
    const std::string& getSelectedIcon()
    void setSelectedIcon(const std::string& value)
    cocos2d::Color3B getTitleColor()
    void setTitleColor(const cocos2d::Color3B& value)
    int getTitleFontSize()
    void setTitleFontSize(int value)
    bool isSelected()
    void setSelected(bool value)
    GController* getRelatedController()
    void setRelatedController(GController* c)
    bool isChangeStateOnClick()
    void setChangeStateOnClick(bool value)
    GTextField* getTextField()
]]

cls.props [[
    title
    selectedTitle
    selectedIcon
    titleColor
    titleFontSize
    selected
    relatedController
    changeStateOnClick
    textField
]]

return cls