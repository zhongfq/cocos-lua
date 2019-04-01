local cls = class()
cls.CPPCLS = "fairygui::GList"
cls.LUACLS = "fui.GList"
cls.SUPERCLS = "fui.GComponent"
cls.funcs [[
    static GList *create()
    const std::string& getDefaultItem()
    void setDefaultItem(const std::string& value)
    ListLayoutType getLayout()
    void setLayout(ListLayoutType value)
    int getLineCount()
    void setLineCount(int value)
    int getColumnCount()
    void setColumnCount(int value)
    int getColumnGap()
    void setColumnGap(int value)
    int getLineGap()
    void setLineGap(int value)
    cocos2d::TextHAlignment getAlign()
    void setAlign(cocos2d::TextHAlignment value)
    cocos2d::TextVAlignment getVerticalAlign()
    void setVerticalAlign(cocos2d::TextVAlignment value)
    bool getAutoResizeItem()
    void setAutoResizeItem(bool value)
    ListSelectionMode getSelectionMode()
    void setSelectionMode(ListSelectionMode value)
    GObject* getFromPool()
    GObject* getFromPool(const std::string& url)
    void returnToPool(GObject *obj)
    GObject* addItemFromPool()
    GObject* addItemFromPool(const std::string& url)
    void removeChildToPoolAt(int index)
    void removeChildToPool(GObject *child)
    void removeChildrenToPool()
    void removeChildrenToPool(int beginIndex, int endIndex)
    int getSelectedIndex()
    void setSelectedIndex(int value)
    void getSelection(std::vector<int>& result)
    void addSelection(int index, bool scrollItToView)
    void removeSelection(int index)
    void clearSelection()
    void selectAll()
    void selectReverse()
    void handleArrowKey(int dir)
    void resizeToFit(int itemCount)
    void resizeToFit(int itemCount, int minSize)
    void scrollToView(int index, bool ani = false, bool setFirst = false)
    GController* getSelectionController()
    void setSelectionController(GController* value)
    void setVirtual()
    void setVirtualAndLoop()
    bool isVirtual()
    void refreshVirtualList()
    int getNumItems()
    void setNumItems(int value)
    int childIndexToItemIndex(int index)
    int itemIndexToChildIndex(int index)
]]

cls.vars [[
    std::function<void(int, GObject*)> itemRenderer;
    std::function<std::string(int)> itemProvider;
    bool scrollItemToViewOnClick;
    bool foldInvisibleItems;
]]

cls.props [[
    defaultItem
    layout
    lineCount
    columnCount
    columnGap
    lineGap
    align
    verticalAlign
    autoResizeItem
    selectionMode
    selectedIndex
    selectionController
    numItems
]]

return cls