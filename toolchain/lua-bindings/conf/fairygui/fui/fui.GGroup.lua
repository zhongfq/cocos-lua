local cls = class()
cls.CPPCLS = "fairygui::GGroup"
cls.LUACLS = "fui.GGroup"
cls.SUPERCLS = "fui.GObject"
cls.funcs [[
    static GGroup* create()
    GroupLayoutType getLayout()
    void setLayout(GroupLayoutType value)
    int getColumnGap()
    void setColumnGap(int value)
    int getLineGap()
    void setLineGap(int value)
    void setBoundsChangedFlag(bool childSizeChanged = false)
    void moveChildren(float dx, float dy)
    void resizeChildren(float dw, float dh)
]]

cls.props [[
    layout
    columnGap
    lineGap
]]

return cls