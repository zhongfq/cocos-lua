local cls = class()
cls.CPPCLS = "fairygui::GComboBox"
cls.LUACLS = "fgui.GComboBox"
cls.SUPERCLS = "fgui.GComponent"
cls.funcs [[
    static GComboBox *create()
    const std::string& getTitle()
    void setTitle(const std::string& value)
    const cocos2d::Color3B getTitleColor()
    void setTitleColor(const cocos2d::Color3B& value)
    int getTitleFontSize()
    void setTitleFontSize(int value)
    const std::string& getValue()
    void setValue(const std::string& value)
    int getSelectedIndex()
    void setSelectedIndex(int value)
    GController* getSelectionController()
    void setSelectionController(GController* value)
    std::vector<std::string>& getItems()
    std::vector<std::string>& getIcons()
    std::vector<std::string>& getValues()
    GObject* getDropdown()
    void refresh()
    GTextField* getTextField()
]]
cls.props [[
    title
    titleColor
    titleFontSize
    value
    selectedIndex
    selectionController
    items
    icons
    values
    dropdown
    textField
]]
return cls