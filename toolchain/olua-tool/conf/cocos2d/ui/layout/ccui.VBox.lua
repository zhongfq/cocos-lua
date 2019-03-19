local cls = class()
cls.CPPCLS = "cocos2d::ui::VBox"
cls.LUACLS = "ccui.VBox"
cls.SUPERCLS = "ccui.Layout"
cls.funcs [[
    static VBox* create()
    static VBox* create(@pack const Size& size)
]]
return cls