local cls = class()
cls.CPPCLS = "fairygui::InputEvent"
cls.LUACLS = "fui.InputEvent"
cls.funcs [[
    GObject* getTarget()
    const int getX()
    const int getY()
    const cocos2d::Vec2& getPosition()
    cocos2d::Touch* getTouch()
    int getTouchId()
    int isDoubleClick()
    cocos2d::EventMouse::MouseButton getButton()
    cocos2d::EventKeyboard::KeyCode getKeyCode()
    bool isCtrlDown()
    bool isAltDown()
    bool isShiftDown()
    int getMouseWheelDelta()
    InputProcessor* getProcessor()
]]
cls.props [[
    target
    x
    y
    position
    touch
    touchId
    doubleClick
    button
    keyCode
    ctrlDown
    altDown
    shiftDown
    mouseWheelDelta
    processor
]]
return cls