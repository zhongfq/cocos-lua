local cls = class()
cls.CPPCLS = "fairygui::GRoot"
cls.LUACLS = "fui.GRoot"
cls.SUPERCLS = "fui.GComponent"
cls.funcs [[
    static GRoot* create(cocos2d::Scene* scene, int zOrder = 1000)
    static GRoot* getInstance()
    void showWindow(Window* win)
    void hideWindow(Window* win)
    void hideWindowImmediately(Window* win)
    void bringToFront(Window* win)
    void showModalWait()
    void closeModalWait()
    void closeAllExceptModals()
    void closeAllWindows()
    Window* getTopWindow()
    GObject* getModalWaitingPane()
    GGraph* getModalLayer()
    bool hasModalWindow()
    bool isModalWaiting()
    InputProcessor* getInputProcessor()
    cocos2d::Vec2 getTouchPosition(int touchId)
    GObject* getTouchTarget()
    void showPopup(GObject* popup)
    void showPopup(GObject* popup, GObject* target, PopupDirection dir)
    void togglePopup(GObject* popup)
    void togglePopup(GObject* popup, GObject* target, PopupDirection dir)
    void hidePopup()
    void hidePopup(GObject* popup)
    bool hasAnyPopup()
    cocos2d::Vec2 getPoupPosition(GObject* popup, GObject* target, PopupDirection dir)
    void showTooltips(const std::string& msg)
    void showTooltipsWin(GObject* tooltipWin)
    void hideTooltips()
    void playSound(const std::string& url, float volumeScale = 1)
    bool isSoundEnabled()
    void setSoundEnabled(bool value)
    float getSoundVolumeScale()
    void setSoundVolumeScale(float value)
]]
cls.props [[
    instance
    topWindow
    modalWaitingPane
    modalLayer
    modalWaiting
    inputProcessor
    touchTarget
    soundEnabled
    soundVolumeScale
]]

-- ref
cls.inject('create', {
    AFTER = [[
        olua_push_cppobj<cocos2d::Node>(L, ret->displayObject(), "cc.Node");
        olua_singleref(L, -1, "fui.root", -2);
        olua_mapref(L, 1, "children", -1);
        lua_pop(L, 1);
    ]]
})

do
    local REFNAME = 'children'
    -- void showWindow(Window* win)
    cls.inject('showWindow', mapref_arg_value(REFNAME), mapunef_by_compare(REFNAME))

    -- void hideWindow(Window* win)
    -- void hideWindowImmediately(Window* win)
    local HIDE_WINDOW = {
        BEFORE = format_snippet [[
            if (arg1->getParent()) {
                olua_push_cppobj<fairygui::GComponent>(L, arg1->getParent(), "fui.GComponent");
                xlua_startcmpunref(L, -1, "children");
            } else {
                lua_pushnil(L);
            }
        ]],
        AFTER = format_snippet [[
            if (!olua_isnil(L, -1)) {
                xlua_endcmpunref(L, -1, "children");
            }
        ]]
    }
    cls.inject('hideWindow',            HIDE_WINDOW)
    cls.inject('hideWindowImmediately', HIDE_WINDOW)

    -- Window* getTopWindow()
    -- GObject* getModalWaitingPane()
    -- GGraph* getModalLayer()
    cls.inject('getTopWindow',          mapref_return_value(REFNAME))
    cls.inject('getModalWaitingPane',   mapref_return_value(REFNAME))
    cls.inject('getModalLayer',         mapref_return_value(REFNAME))

    -- void showPopup(GObject* popup)
    -- void showPopup(GObject* popup, GObject* target, PopupDirection dir)
    -- void togglePopup(GObject* popup)
    -- void togglePopup(GObject* popup, GObject* target, PopupDirection dir)
    cls.inject('showPopup',     mapref_arg_value(REFNAME))
    cls.inject('togglePopup',   mapref_arg_value(REFNAME))

    -- void hidePopup()
    -- void hidePopup(GObject* popup)
    cls.inject('hidePopup',     mapunef_by_compare(REFNAME))
end

return cls