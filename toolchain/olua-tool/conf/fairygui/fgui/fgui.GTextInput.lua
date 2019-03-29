local cls = class(M)
cls.CPPCLS = "fairygui::GTextInput"
cls.LUACLS = "fgui.GTextInput"
cls.SUPERCLS = "fgui.GTextField"
cls.funcs [[
    static GTextInput *create()
    void setPrompt(const std::string& value)
    void setPassword(bool value)
    void setKeyboardType(int value)
    void setMaxLength(int value)
    void setRestrict(const std::string& value)
]]

return cls