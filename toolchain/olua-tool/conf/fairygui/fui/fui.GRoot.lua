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

return cls