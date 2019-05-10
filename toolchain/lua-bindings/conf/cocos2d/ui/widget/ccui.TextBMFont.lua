local cls = class()
cls.CPPCLS = "cocos2d::ui::TextBMFont"
cls.LUACLS = "ccui.TextBMFont"
cls.SUPERCLS = "ccui.Widget"
cls.funcs [[
    static TextBMFont* create()
    static TextBMFont* create(const std::string& text, const std::string& filename)
    void setFntFile(const std::string& fileName)
    void setString(const std::string& value)
    const std::string& getString()
    ssize_t getStringLength()
    ResourceData getRenderFile()
    void resetRender()
]]

cls.props [[
    string
    stringLength
    renderFile
]]

return cls