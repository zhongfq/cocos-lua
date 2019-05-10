local cls = class()
cls.CPPCLS = "fairygui::GRichTextField"
cls.LUACLS = "fui.GRichTextField"
cls.SUPERCLS = "fui.GTextField"
cls.funcs [[
    static GRichTextField *create()
]]

return cls