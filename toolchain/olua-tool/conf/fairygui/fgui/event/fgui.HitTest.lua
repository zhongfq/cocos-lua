local cls = class()
cls.CPPCLS = "fairygui::IHitTest"
cls.LUACLS = "fgui.IHitTest"
cls.funcs [[
    bool hitTest(GComponent* obj, const cocos2d::Vec2& localPoint)
]]
return cls