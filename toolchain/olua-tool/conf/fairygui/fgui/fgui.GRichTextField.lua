local cls = class()
cls.CPPCLS = "fairygui::GRichTextField"
cls.LUACLS = "fgui.GRichTextField"
cls.SUPERCLS = "fgui.GTextField"
cls.funcs [[
    static GRichTextField *create()
]]

return cls