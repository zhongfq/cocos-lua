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
    void returnToPool(@unref(map children) GObject *obj)
    @ref(map children) GObject* addItemFromPool()
    @ref(map children) GObject* addItemFromPool(const std::string& url)
    @unref(cmp children) void removeChildToPoolAt(int index)
    void removeChildToPool(@unref(map children) GObject *child)
    @unref(cmp children) void removeChildrenToPool()
    @unref(cmp children) void removeChildrenToPool(int beginIndex, int endIndex)

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

    @ref(single selectionController) GController* getSelectionController()
    void setSelectionController(@ref(single selectionController) GController* value)

    @unref(cmp children) void setVirtual()
    @unref(cmp children) void setVirtualAndLoop()
    bool isVirtual()

    void refreshVirtualList()

    int getNumItems()
    @unref(cmp children) void setNumItems(int value)

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
    virtual
    numItems
]]

-- check api

-- void removeChildToPoolAt(int index);
cls.inject('removeChildToPoolAt', {
    BEFORE = format_snippet [[
        if (!(arg1 >= 0 && arg1 < self->numChildren())) {
            luaL_error(L, "index out of range");
        }
    ]]
})

-- void removeChildrenToPool()
-- void removeChildrenToPool(int beginIndex, int endIndex)
cls.inject('removeChildrenToPool', {
    BEFORE = format_snippet [[
        if (lua_gettop(L) == 3) {
            int arg1 = (int)olua_checkinteger(L, 2);
            int arg2 = (int)olua_checkinteger(L, 3);
            if (!(arg1 >= 0 && arg1 < self->numChildren())) {
                luaL_error(L, "beginIndex index out of range");
            }
            if (!(arg2 == -1 || (arg2 >= 0 && arg2 < self->numChildren()))) {
                luaL_error(L, "endIndex index out of range");
            }
        }
    ]]
})

-- std::function<void(int, GObject*)> itemRenderer;
cls.inject('itemRenderer', {
    CALLBACK_BEFORE = format_snippet [[
        if (arg2->getParent()) {
            olua_push_cppobj<fairygui::GComponent>(L, arg2->getParent(), "fui.GComponent");
            olua_mapref(L, -1, "children", -2);
            lua_pop(L, 1);
        }
    ]]
})

return cls