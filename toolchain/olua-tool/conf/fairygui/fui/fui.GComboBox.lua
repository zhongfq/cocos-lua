local cls = class()
cls.CPPCLS = "fairygui::GComboBox"
cls.LUACLS = "fui.GComboBox"
cls.SUPERCLS = "fui.GComponent"
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
    @ref(singleref selectionController) GController* getSelectionController()
    void setSelectionController(@ref(singleref selectionController) GController* value)
    std::vector<std::string>& getItems()
    std::vector<std::string>& getIcons()
    std::vector<std::string>& getValues()
    @ref(singleref dropdown) GObject* getDropdown()
    void refresh()
    @ref(singleref textField) GTextField* getTextField()
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