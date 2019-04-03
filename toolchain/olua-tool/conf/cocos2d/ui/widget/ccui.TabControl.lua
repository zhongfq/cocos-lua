local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::TabHeader::EventType"
cls.LUACLS = "ccui.TabHeader.EventType"
cls.enums [[
    SELECTED
    UNSELECTED
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::TabHeader"
cls.LUACLS = "ccui.TabHeader"
cls.SUPERCLS = "ccui.AbstractCheckButton"
cls.funcs [[
    static TabHeader* create()
    static TabHeader* create(const std::string& titleStr, const std::string& backGround, const std::string& cross, Widget::TextureResType texType = Widget::TextureResType::LOCAL)
    static TabHeader* create(const std::string& titleStr, const std::string& backGround, const std::string& backGroundSelected, const std::string& cross, const std::string& backGroundDisabled, const std::string& frontCrossDisabled, Widget::TextureResType texType = Widget::TextureResType::LOCAL)
    @ref(single titleRenderer) Label* getTitleRenderer()
    void setTitleText(const std::string& text)
    std::string getTitleText()
    void setTitleColor(const Color4B& color)
    const Color4B& getTitleColor()
    void setTitleFontSize(float size)
    float getTitleFontSize()
    void setTitleFontName(const std::string& fontName)
    std::string getTitleFontName()
    int   getIndexInTabControl()
]]

cls.props [[
    titleRenderer
    titleText
    titleColor
    titleFontSize
    titleFontName
    indexInTabControl
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::TabControl::Dock"
cls.LUACLS = "ccui.TabControl.Dock"
cls.enums [[
    TOP
    LEFT
    BOTTOM
    RIGHT
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::TabControl::EventType"
cls.LUACLS = "ccui.TabControl.EventType"
cls.enums [[
    SELECT_CHANGED
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::TabControl"
cls.LUACLS = "ccui.TabControl"
cls.SUPERCLS = "ccui.Widget"
cls.funcs [[
    static TabControl* create()
    @unref(cmp controls) void removeTab(int index)
    void setSelectTab(int index)
    void setSelectTab(TabHeader* tabHeader)
    @ref(map controls) TabHeader* getTabHeader(int index)
    @ref(map controls) Layout* getTabContainer(int index)
    void insertTab(int index, @ref(map controls) TabHeader* header, @ref(map controls) Layout* container)
    size_t    getTabCount()
    int getSelectedTabIndex()
    int indexOfTabHeader(const TabHeader* tabCell)
    void  setHeaderWidth(float headerWidth)
    float getHeaderWidth()
    void  setHeaderHeight(float headerHeight)
    int   getHeaderHeight()
    void  ignoreHeadersTextureSize(bool ignore)
    bool  isIgnoreHeadersTextureSize()
    void  setHeaderSelectedZoom(float zoom)
    float getHeaderSelectedZoom()
    void         setHeaderDockPlace(TabControl::Dock dockPlace)
    TabControl::Dock getHeaderDockPlace()
]]

cls.callbacks [[
    void setTabChangedEventListener(@nullable const std::function<void(int tabIndex, EventType)>& callback)
]]

cls.props [[
    tabCount
    selectedTabIndex
    headerWidth
    headerHeight
    ignoreHeadersTextureSize
    headerSelectedZoom
    headerDockPlace
]]

return M