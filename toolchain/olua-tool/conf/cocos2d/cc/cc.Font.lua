local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::Font"
cls.LUACLS = "cc.Font"
cls.SUPERCLS = "cc.Ref"
cls.funcs([[
    int getFontMaxHeight()
]])

local cls = class(M)
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
    const Font* getFont()
    // void listenRendererRecreated(EventCustom *event)
    void purgeTexturesAtlas()
    void setAntiAliasTexParameters()
    void setAliasTexParameters()
]])
cls.props [[
    lineHeight
    font
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::FontAtlasCache"
cls.LUACLS = "cc.FontAtlasCache"
cls.funcs([[
    // static FontAtlas* getFontAtlasTTF(const _ttfConfig* config)
    static FontAtlas* getFontAtlasFNT(const std::string& fontFileName, const Vec2& imageOffset = Vec2::ZERO)
    static FontAtlas* getFontAtlasCharMap(const std::string& charMapFile, int itemWidth, int itemHeight, int startCharMap)
    static FontAtlas* getFontAtlasCharMap(Texture2D* texture, int itemWidth, int itemHeight, int startCharMap)
    static FontAtlas* getFontAtlasCharMap(const std::string& plistFile)
    static bool releaseFontAtlas(FontAtlas *atlas)
    static void purgeCachedData()
    static void reloadFontAtlasFNT(const std::string& fontFileName, const Vec2& imageOffset = Vec2::ZERO)
    static void unloadFontAtlasTTF(const std::string& fontFileName)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::FontCharMap"
cls.LUACLS = "cc.FontCharMap"
cls.SUPERCLS = "cc.Font"
cls.funcs([[
    static FontCharMap * create(const std::string& charMapFile, int itemWidth, int itemHeight, int startCharMap)
    static FontCharMap * create(Texture2D* texture, int itemWidth, int itemHeight, int startCharMap)
    static FontCharMap * create(const std::string& plistFile)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::FontFNT"
cls.LUACLS = "cc.FontFNT"
cls.SUPERCLS = "cc.Font"
cls.funcs([[
    static FontFNT * create(const std::string& fntFilePath, const Vec2& imageOffset = Vec2::ZERO)
    static void purgeCachedData()
    void setFontSize(float fontSize)
    int getOriginalFontSize()
    static void reloadBMFontResource(const std::string& fntFilePath)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::FontFreeType"
cls.LUACLS = "cc.FontFreeType"
cls.SUPERCLS = "cc.Font"
cls.funcs([[
    static void shutdownFreeType()
    bool isDistanceFieldEnabled()
    float getOutlineSize()
    // void renderCharAt(unsigned char *dest,int posX, int posY, unsigned char* bitmap,long bitmapWidth,long bitmapHeight)
    // FT_Encoding getEncoding()
    const unsigned char* getGlyphBitmap(uint64_t theChar, long &outWidth, long &outHeight, Rect &outRect,int &xAdvance)
    int getFontAscender()
    const char* getFontFamily()
    static void releaseFont(const std::string &fontName)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::AtlasNode"
cls.LUACLS = "cc.AtlasNode"
cls.SUPERCLS = "cc.Node"
cls.funcs([[
    static AtlasNode * create(const std::string& filename, int tileWidth, int tileHeight, int itemsToRender)
    void updateAtlasValues()
    void setTextureAtlas(TextureAtlas* textureAtlas)
    TextureAtlas* getTextureAtlas()
    void setQuadsToDraw(ssize_t quadsToDraw)
    ssize_t getQuadsToDraw()
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::LabelAtlas"
cls.LUACLS = "cc.LabelAtlas"
cls.SUPERCLS = "cc.AtlasNode"
cls.funcs([[
    static LabelAtlas* create()
    static LabelAtlas* create(const std::string& string, const std::string& charMapFile, int itemWidth, int itemHeight, int startCharMap)
    static LabelAtlas* create(const std::string& string, const std::string& fntFile)
]])

return M