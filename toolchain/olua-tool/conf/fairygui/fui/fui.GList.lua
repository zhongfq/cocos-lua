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
    @singleref(selectionController) GController* getSelectionController()
    void setSelectionController(@singleref(selectionController) GController* value)
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
    virtual
    numItems
]]

-- ref
-- ref
do
    local REFNAME = 'children'
    local CHECK_RANGE = {
        BEFORE = format_snippet [[
            if (!(arg1 >= 0 && arg1 < self->numChildren())) {
                luaL_error(L, "index out of range");
            }
        ]]
    }
    local UNREF_BY_INDEX = {
        BEFORE = format_snippet [[
            fairygui::GObject *child = self->getChildAt((int)arg1);
            if (olua_getobj(L, child)) {
                olua_mapunref(L, 1, "${REFNAME}", -1);
                lua_pop(L, 1);
            }
        ]]
    }
    local CHECK_REMOVE_CHILDREN_RANGE = {
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
    }
    -- GObject* addItemFromPool()
    -- GObject* addItemFromPool(const std::string& url)
    cls.inject('addItemFromPool',       mapref_return_value(REFNAME))

    -- void removeChildToPool(GObject *child)
    cls.inject('removeChildToPool',     mapunref_arg_value(REFNAME))

    -- void removeChildToPoolAt(int index);
    cls.inject('removeChildToPoolAt',   CHECK_RANGE, UNREF_BY_INDEX)

    -- void removeChildrenToPool()
    -- void removeChildrenToPool(int beginIndex, int endIndex)
    cls.inject('removeChildrenToPool',  CHECK_REMOVE_CHILDREN_RANGE, mapunef_by_compare(REFNAME))

    -- void setNumItems(int value)
    -- void setVirtual()
    -- void setVirtualAndLoop()
    cls.inject('setNumItems', mapunef_by_compare(REFNAME))
    cls.inject('setVirtual', mapunef_by_compare(REFNAME))
    cls.inject('setVirtualAndLoop', mapunef_by_compare(REFNAME))

    -- std::function<void(int, GObject*)> itemRenderer;
    cls.inject('itemRenderer', {
        CALLBACK_BEFORE = format_snippet [[
            if (arg2->getParent()) {
                olua_push_cppobj<fairygui::GComponent>(L, arg2->getParent(), "fui.GComponent");
                olua_mapref(L, -1, "${REFNAME}", -2);
                lua_pop(L, 1);
            }
        ]]
    })
end

return cls