local cls = class()
cls.CPPCLS = "cocos2d::LabelAtlas"
cls.LUACLS = "cc.LabelAtlas"
cls.SUPERCLS = "cc.AtlasNode"
cls.funcs([[
    static LabelAtlas* create()
    static LabelAtlas* create(const std::string& string, const std::string& charMapFile, int itemWidth, int itemHeight, int startCharMap)
    static LabelAtlas* create(const std::string& string, const std::string& fntFile)
]])

return cls