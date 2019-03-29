local cls = class()
cls.CPPCLS = "fairygui::InputProcessor"
cls.LUACLS = "fgui.InputProcessor"
cls.funcs [[
    InputEvent* getRecentInput()
    static bool isTouchOnUI()
    cocos2d::Vec2 getTouchPosition(int touchId)
    void addTouchMonitor(int touchId, GObject* target)
    void removeTouchMonitor(GObject* target)
    void cancelClick(int touchId)
    void simulateClick(GObject* target, int touchId = -1)
]]
cls.callbacks [[
    void setCaptureCallback(@nullable std::function<void(int eventType)> value)
]]
cls.props [[
    recentInput
    touchOnUI
]]
return cls