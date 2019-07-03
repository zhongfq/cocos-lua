local cls = class()
cls.CPPCLS = "fairygui::PopupMenu"
cls.LUACLS = "fui.PopupMenu"
cls.SUPERCLS = "cc.Ref"
cls.CHUNK = [[
static int _fairygui_PopupMenu_addItemAt(lua_State *L);
]]
cls.funcs [[
    static PopupMenu* create(const std::string& resourceURL)
    static PopupMenu* create()
    void addSeperator()
    const std::string& getItemName(int index)
    void setItemText(const std::string& name, const std::string& caption)
    void setItemVisible(const std::string& name, bool visible)
    void setItemGrayed(const std::string& name, bool grayed)
    void setItemCheckable(const std::string& name, bool checkable)
    void setItemChecked(const std::string& name, bool check)
    bool isItemChecked(const std::string& name)

    @unref(cmp children parent) bool removeItem(const std::string& name)
    @unref(cmp children parent) void clearItems()

    int getItemCount()

    @ref(single contentPane) GComponent* getContentPane()
    @ref(single list) GList* getList()

    @unref(cmp children parent)@ref(map children parent) void show()
    @unref(cmp children parent)@ref(map children parent) void show(GObject* target, PopupDirection dir)
]]

cls.props [[
    contentPane
    list
]]

cls.func('addItemAt', [[
{
    lua_settop(L, 4);

    fairygui::PopupMenu *self = (fairygui::PopupMenu *)olua_toobj(L, 1, "fui.PopupMenu");
    std::string caption = olua_checkstring(L, 2);
    int index = (int)olua_checkinteger(L, 3);
    fairygui::GButton *ret = (fairygui::GButton *)self->addItemAt(caption, index, nullptr);

    void *callback_store_obj = (void *)ret;
    std::string tag = makeListenerTag(L, fairygui::UIEventType::ClickMenu, 0);
    std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 4, OLUA_CALLBACK_TAG_NEW);
    std::function<void(fairygui::EventContext *)> callback = [callback_store_obj, func, tag](fairygui::EventContext *event) {
        lua_State *L = olua_mainthread();
        int top = lua_gettop(L);
        size_t last = olua_push_objpool(L);
        olua_enable_objpool(L);
        olua_push_cppobj<fairygui::EventContext>(L, event, "fui.EventContext");
        olua_disable_objpool(L);
        olua_callback(L, callback_store_obj, func.c_str(), 1);
        
        //pop stack value
        olua_pop_objpool(L, last);
        
        lua_settop(L, top);
    };
    
    ret->addEventListener(fairygui::UIEventType::ClickMenu, callback);
    
    olua_push_cppobj<fairygui::GButton>(L, ret, "fui.GButton");
    olua_push_cppobj<fairygui::GComponent>(L, ret->getParent(), "fui.GComponent");
    olua_mapref(L, -1, "children", -2);
    lua_pop(L, 1);

    return 1;
}]])

cls.func('addItem', [[
{
    lua_settop(L, 3);

    fairygui::PopupMenu *self = (fairygui::PopupMenu *)olua_toobj(L, 1, "fui.PopupMenu");
    lua_pushinteger(L, self->getList()->numChildren());
    lua_insert(L, -2);
    return _fairygui_PopupMenu_addItemAt(L);
}]])

-- void show()
-- void show(GObject* target, PopupDirection dir)
cls.inject('show', {
    BEFORE = [[
        fairygui::GRoot *root = fairygui::UIRoot;
        if (lua_gettop(L) > 1) {
            fairygui::GObject *target = (fairygui::GObject *)olua_checkobj(L, 2, "fui.GObject");
            root = target->getRoot();
        }
        if (!root) {
            luaL_error(L, "no root to add 'PopupMenu'");
        }
        olua_push_cppobj<fairygui::GRoot>(L, root, "fui.GRoot");
        int parent = lua_gettop(L);
    ]]
})

-- bool removeItem(const std::string& name)
-- void clearItems()
cls.inject({'removeItem', 'clearItems'}, {
    BEFORE = format_snippet [[
        olua_push_cppobj<fairygui::GList>(L, self->getList(), "fui.GList");
        int parent = lua_gettop(L);
    ]]
})

return cls