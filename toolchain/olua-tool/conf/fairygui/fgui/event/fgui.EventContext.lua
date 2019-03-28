local cls = class()
cls.CPPCLS = "fairygui::EventContext"
cls.LUACLS = "fgui.EventContext"
cls.funcs [[
    int getType()
    cocos2d::Ref* getSender()
    // InputEvent* getInput()
    void stopPropagation()
    void preventDefault()
    bool isDefaultPrevented()
    void captureTouch()
    void uncaptureTouch()
    const cocos2d::Value& getDataValue()
    void* getData()
]]

cls.props [[
    type
    sender
    defaultPrevented
    dataValue
    data
]]

return cls