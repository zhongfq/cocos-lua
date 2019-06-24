local cls = class()
cls.CPPCLS = "fairygui::DragDropManager"
cls.LUACLS = "fui.DragDropManager"
cls.funcs [[
    static DragDropManager* getInstance()
    GLoader* getAgent()
    bool isDragging()
    void startDrag(const std::string& icon, const cocos2d::Value& sourceData = cocos2d::Value::Null, int touchPointID = -1)
    void cancel()
]]

cls.props [[
    instance
    agent
    dragging
]]

return cls