local cls = class()
cls.CPPCLS = "fairygui::PopupMenu"
cls.LUACLS = "fgui.PopupMenu"
cls.SUPERCLS = "cc.Ref"
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
    bool removeItem(const std::string& name)
    void clearItems()
    int getItemCount()
    GComponent* getContentPane()
    GList* getList()
    void show()
    void show(GObject* target, PopupDirection dir)
]]

cls.props [[
    contentPane
    list
]]

cls.func('addItem', [[
{
    lua_settop(L, 3);

    fairygui::PopupMenu *self = (fairygui::PopupMenu *)olua_toobj(L, 1, "fgui.PopupMenu");
    std::string caption = olua_checkstring(L, 2);
    fairygui::GButton *ret = (fairygui::GButton *)self->addItem(caption, nullptr);

    void *callback_store_obj = (void *)ret;
    std::string tag = makeListenerTag(L, fairygui::UIEventType::ClickMenu, 0);
    std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 3, OLUA_CALLBACK_TAG_NEW);
    std::function<void(fairygui::EventContext *)> callback = [callback_store_obj, func, tag](fairygui::EventContext *event) {
        lua_State *L = olua_mainthread();
        int top = lua_gettop(L);

        olua_push_cppobj<fairygui::EventContext>(L, event, "fgui.EventContext");
        olua_callback(L, callback_store_obj, func.c_str(), 1);
        
        // stack value
        olua_push_cppobj<fairygui::EventContext>(L, event, "fgui.EventContext");
        olua_callgc(L, -1, false);

        lua_settop(L, top);
    };

    ret->addEventListener(fairygui::UIEventType::ClickMenu, callback);

    return olua_push_cppobj<fairygui::GButton>(L, ret, "fgui.GButton");
}]])

cls.func('addItemAt', [[
{
    lua_settop(L, 4);

    fairygui::PopupMenu *self = (fairygui::PopupMenu *)olua_toobj(L, 1, "fgui.PopupMenu");
    std::string caption = olua_checkstring(L, 2);
    int index = (int)olua_checkinteger(L, 3);
    fairygui::GButton *ret = (fairygui::GButton *)self->addItemAt(caption, index, nullptr);

    void *callback_store_obj = (void *)ret;
    std::string tag = makeListenerTag(L, fairygui::UIEventType::ClickMenu, 0);
    std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 4, OLUA_CALLBACK_TAG_NEW);
    std::function<void(fairygui::EventContext *)> callback = [callback_store_obj, func, tag](fairygui::EventContext *event) {
        lua_State *L = olua_mainthread();
        int top = lua_gettop(L);
        
        olua_push_cppobj<fairygui::EventContext>(L, event, "fgui.EventContext");
        olua_callback(L, callback_store_obj, func.c_str(), 1);
        
        // stack value
        olua_push_cppobj<fairygui::EventContext>(L, event, "fgui.EventContext");
        olua_callgc(L, -1, false);
        
        lua_settop(L, top);
    };
    
    ret->addEventListener(fairygui::UIEventType::ClickMenu, callback);
    
    return olua_push_cppobj<fairygui::GButton>(L, ret, "fgui.GButton");
}]])

return cls