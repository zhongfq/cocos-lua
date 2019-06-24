local cls = class()
cls.CPPCLS = "cocos2d::ui::HBox"
cls.LUACLS = "ccui.HBox"
cls.SUPERCLS = "ccui.Layout"
cls.funcs [[
    static HBox* create()
    static HBox* create(Size& size)
]]
return cls