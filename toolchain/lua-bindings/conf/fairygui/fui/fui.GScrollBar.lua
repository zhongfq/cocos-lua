local cls = class()
cls.CPPCLS = "fairygui::GScrollBar"
cls.LUACLS = "fui.GScrollBar"
cls.SUPERCLS = "fui.GComponent"
cls.funcs [[
    static GScrollBar* create()
    void setScrollPane(ScrollPane* target, bool vertical)
    void setDisplayPerc(float value)
    void setScrollPerc(float value)
    float getMinSize()
]]
cls.props [[
    minSize
]]

return cls