local cls = class()
cls.CPPCLS = "cocos2d::FontAtlas"
cls.LUACLS = "cc.FontAtlas"
cls.SUPERCLS = "cc.Ref"
cls.funcs([[
    // void addLetterDefinition(char32_t utf32Char, const FontLetterDefinition &letterDefinition)
    // bool getLetterDefinitionForChar(char32_t utf32Char, FontLetterDefinition &letterDefinition)
    // bool prepareLetterDefinitions(const std::u32string& utf16String)
    // const std::unordered_map<ssize_t, Texture2D*>& getTextures()
    // void  addTexture(Texture2D *texture, int slot)
    float getLineHeight()
    void  setLineHeight(float newHeight)
    // Texture2D* getTexture(int slot)
    // const Font* getFont()
    // void listenRendererRecreated(EventCustom *event)
    void purgeTexturesAtlas()
    void setAntiAliasTexParameters()
    void setAliasTexParameters()
]])
cls.props [[
    lineHeight
]]

return cls