local cls = class()
cls.CPPCLS = "cocos2d::ui::TextAtlas"
cls.LUACLS = "ccui.TextAtlas"
cls.SUPERCLS = "ccui.Widget"
cls.funcs [[
    static TextAtlas* create()
    static TextAtlas* create(const std::string& stringValue,const std::string& charMapFile,int itemWidth, int itemHeight, const std::string& startCharMap)
    void setProperty(const std::string& stringValue,const std::string& charMapFile,int itemWidth,int itemHeight,const std::string& startCharMap)
    void setString(const std::string& value)
    const std::string& getString()
    ssize_t getStringLength()
    void adaptRenderers()
    ResourceData getRenderFile()
]]

cls.props [[
    string
    stringLength
    renderFile
]]

return cls