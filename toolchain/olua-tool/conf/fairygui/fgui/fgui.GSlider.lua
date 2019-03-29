local cls = class()
cls.CPPCLS = "fairygui::GSlider"
cls.LUACLS = "fgui.GSlider"
cls.SUPERCLS = "fgui.GComponent"
cls.funcs [[
    static GSlider *create()
    ProgressTitleType getTitleType()
    void setTitleType(ProgressTitleType value)
    double getMax()
    void setMax(double value)
    double getValue()
    void setValue(double value)
]]

cls.vars [[
    bool changeOnClick;
    bool canDrag;
]]

cls.props [[
    titleType
    max
    value
]]

return cls