local cls = class()
cls.CPPCLS = "fairygui::PopupMenu"
cls.LUACLS = "fui.PopupMenu"
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
    @singleref(contentPane) GComponent* getContentPane()
    @singleref(list) GList* getList()
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

    fairygui::PopupMenu *self = (fairygui::PopupMenu *)olua_toobj(L, 1, "fui.PopupMenu");
    std::string caption = olua_checkstring(L, 2);
    fairygui::GButton *ret = (fairygui::GButton *)self->addItem(caption, nullptr);

    ${INJECT_BEFORE}

    void *callback_store_obj = (void *)ret;
    std::string tag = makeListenerTag(L, fairygui::UIEventType::ClickMenu, 0);
    std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 3, OLUA_CALLBACK_TAG_NEW);
    std::function<void(fairygui::EventContext *)> callback = [callback_store_obj, func, tag](fairygui::EventContext *event) {
        lua_State *L = olua_mainthread();
        int top = lua_gettop(L);

        olua_push_cppobj<fairygui::EventContext>(L, event, "fui.EventContext");
        olua_callback(L, callback_store_obj, func.c_str(), 1);
        
        // stack value
        olua_push_cppobj<fairygui::EventContext>(L, event, "fui.EventContext");
        olua_callgc(L, -1, false);

        lua_settop(L, top);
    };

    ret->addEventListener(fairygui::UIEventType::ClickMenu, callback);

    olua_push_cppobj<fairygui::GButton>(L, ret, "fui.GButton");

    ${INJECT_AFTER}

    return 1;
}]])

cls.func('addItemAt', [[
{
    lua_settop(L, 4);

    fairygui::PopupMenu *self = (fairygui::PopupMenu *)olua_toobj(L, 1, "fui.PopupMenu");
    std::string caption = olua_checkstring(L, 2);
    int index = (int)olua_checkinteger(L, 3);
    fairygui::GButton *ret = (fairygui::GButton *)self->addItemAt(caption, index, nullptr);

    ${INJECT_BEFORE}

    void *callback_store_obj = (void *)ret;
    std::string tag = makeListenerTag(L, fairygui::UIEventType::ClickMenu, 0);
    std::string func = olua_setcallback(L, callback_store_obj, tag.c_str(), 4, OLUA_CALLBACK_TAG_NEW);
    std::function<void(fairygui::EventContext *)> callback = [callback_store_obj, func, tag](fairygui::EventContext *event) {
        lua_State *L = olua_mainthread();
        int top = lua_gettop(L);
        
        olua_push_cppobj<fairygui::EventContext>(L, event, "fui.EventContext");
        olua_callback(L, callback_store_obj, func.c_str(), 1);
        
        // stack value
        olua_push_cppobj<fairygui::EventContext>(L, event, "fui.EventContext");
        olua_callgc(L, -1, false);
        
        lua_settop(L, top);
    };
    
    ret->addEventListener(fairygui::UIEventType::ClickMenu, callback);
    
    olua_push_cppobj<fairygui::GButton>(L, ret, "fui.GButton");

    ${INJECT_AFTER}

    return 1;
}]])

-- ref
local REFNAME = 'children'
-- void show()
-- void show(GObject* target, PopupDirection dir)
local SHOW = {
    AFTER = format_snippet [[
        olua_push_cppobj<fairygui::GComponent>(L, self->getContentPane()->getParent(), "fui.GComponent");
        olua_mapref(L, -1, "${REFNAME}", -2);
        lua_pop(L, 1);
    ]]
}
cls.inject('show', SHOW)

-- GButton* addItem(const std::string& caption, EventCallback callback);
-- GButton* addItemAt(const std::string& caption, int index, EventCallback callback);
local ADD_ITEM = {
    AFTER = format_snippet [[
        olua_push_cppobj<fairygui::GComponent>(L, ret->getParent(), "fui.GComponent");
        olua_mapref(L, -1, "${REFNAME}", -2);
        lua_pop(L, 1);
    ]]
}
cls.inject('addItem',   ADD_ITEM)
cls.inject('addItemAt', ADD_ITEM)

-- bool removeItem(const std::string& name)
-- void clearItems()
local REMOVE_ITEM = {
    BEFORE = format_snippet [[
        olua_push_cppobj<fairygui::GList>(L, self->getList(), "fui.GList");
        xlua_startcmpunref(L, -1, "${REFNAME}");
    ]],
    AFTER = format_snippet [[
        xlua_endcmpunref(L, -1, "${REFNAME}");
    ]],
}
cls.inject('removeItem', REMOVE_ITEM)
cls.inject('clearItems', REMOVE_ITEM)

return cls