local cls = class()
cls.CPPCLS = "fairygui::GRoot"
cls.LUACLS = "fui.GRoot"
cls.SUPERCLS = "fui.GComponent"
cls.funcs [[
    static GRoot* create(cocos2d::Scene* scene, int zOrder = 1000)
    static GRoot* getInstance()

    @unref(cmp children) void showWindow(@ref(map children) Window* win)
    @unref(cmp children parent) void hideWindow(Window* win)
    @unref(cmp children parent) void hideWindowImmediately(Window* win)

    void bringToFront(Window* win)
    void showModalWait()
    void closeModalWait()
    void closeAllExceptModals()
    void closeAllWindows()

    @ref(map children) Window* getTopWindow()
    @ref(map children) GObject* getModalWaitingPane()
    @ref(map children) GGraph* getModalLayer()

    bool hasModalWindow()
    bool isModalWaiting()
    InputProcessor* getInputProcessor()
    cocos2d::Vec2 getTouchPosition(int touchId)
    GObject* getTouchTarget()

    @unref(cmp children) void showPopup(@ref(map children) GObject* popup)
    @unref(cmp children) void showPopup(@ref(map children) GObject* popup, GObject* target, PopupDirection dir)
    @unref(cmp children) void togglePopup(@ref(map children) GObject* popup)
    @unref(cmp children) void togglePopup(@ref(map children) GObject* popup, GObject* target, PopupDirection dir)
    @unref(cmp children) void hidePopup()
    @unref(cmp children) void hidePopup(GObject* popup)

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
cls.prop('UIRoot', 'static GRoot* getInstance()')

-- ref
cls.inject('create', {
    AFTER = [[
        olua_push_cppobj<cocos2d::Node>(L, ret->displayObject(), "cc.Node");
        olua_singleref(L, -1, "fui.root", -2);
        olua_mapref(L, 1, "children", -1);
        lua_pop(L, 1);
    ]]
})

cls.inject({'hideWindow', 'hideWindowImmediately'}, {
    BEFORE = [[
        int parent = 1;
        if (arg1->getParent()) {
            olua_push_cppobj<fairygui::GComponent>(L, arg1->getParent(), "fui.GComponent");
            parent = lua_gettop(L);
        }
    ]]
})

return cls