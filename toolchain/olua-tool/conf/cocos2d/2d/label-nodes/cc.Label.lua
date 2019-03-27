local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::TextHAlignment"
cls.LUACLS = "cc.TextHAlignment"
cls.enums [[
    LEFT
    CENTER
    RIGHT
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::TextVAlignment"
cls.LUACLS = "cc.TextVAlignment"
cls.enums [[
    TOP
    CENTER
    BOTTOM
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::GlyphCollection"
cls.LUACLS = "cc.GlyphCollection"
cls.enums [[
    DYNAMIC
    NEHE
    ASCII
    CUSTOM
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::LabelEffect"
cls.LUACLS = "cc.LabelEffect"
cls.enums [[
    NORMAL
    OUTLINE
    SHADOW
    GLOW
    ITALICS
    BOLD
    UNDERLINE
    STRIKETHROUGH
    ALL
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::Label::LabelType"
cls.LUACLS = "cc.Label.LabelType"
cls.enums [[
    TTF
    BMFONT
    CHARMAP
    STRING_TEXTURE
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::Label::Overflow"
cls.LUACLS = "cc.Label.Overflow"
cls.enums [[
    NONE
    CLAMP
    SHRINK
    RESIZE_HEIGHT
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::Label"
cls.LUACLS = "cc.Label"
cls.SUPERCLS = "cc.Node"
cls.funcs [[
    static Label* create()
    static Label* createWithSystemFont(const std::string& text, const std::string& font, float fontSize, const Size& dimensions = Size::ZERO, TextHAlignment hAlignment = TextHAlignment::LEFT, TextVAlignment vAlignment = TextVAlignment::TOP)
    static Label* createWithTTF(const std::string& text, const std::string& fontFilePath, float fontSize, const Size& dimensions = Size::ZERO, TextHAlignment hAlignment = TextHAlignment::LEFT, TextVAlignment vAlignment = TextVAlignment::TOP)
    static Label* createWithTTF(const TTFConfig& ttfConfig, const std::string& text, TextHAlignment hAlignment = TextHAlignment::LEFT, int maxLineWidth = 0)
    static Label* createWithBMFont(const std::string& bmfontPath, const std::string& text, const TextHAlignment& hAlignment = TextHAlignment::LEFT, int maxLineWidth = 0, const Vec2& imageOffset = Vec2::ZERO)
    static Label* createWithCharMap(const std::string& charMapFile, int itemWidth, int itemHeight, int startCharMap)
    static Label* createWithCharMap(Texture2D* texture, int itemWidth, int itemHeight, int startCharMap)
    static Label* createWithCharMap(const std::string& plistFile)
    bool setTTFConfig(const TTFConfig& ttfConfig)
    const TTFConfig& getTTFConfig()
    bool setBMFontFilePath(const std::string& bmfontFilePath, const Vec2& imageOffset = Vec2::ZERO, float fontSize = 0)
    const std::string& getBMFontFilePath()
    bool setCharMap(const std::string& charMapFile, int itemWidth, int itemHeight, int startCharMap)
    bool setCharMap(Texture2D* texture, int itemWidth, int itemHeight, int startCharMap)
    bool setCharMap(const std::string& plistFile)
    void setSystemFontName(const std::string& font)
    const std::string& getSystemFontName()
    void setSystemFontSize(float fontSize)
    float getSystemFontSize()
    void requestSystemFontRefresh()
    void setString(const std::string& text)
    const std::string& getString()
    int getStringNumLines()
    int getStringLength()
    void setTextColor(const Color4B &color)
    const Color4B& getTextColor()
    void enableShadow(const Color4B& shadowColor = Color4B::BLACK,const Size &offset = Size(2,-2), int blurRadius = 0)
    void enableOutline(const Color4B& outlineColor,int outlineSize = -1)
    void enableGlow(const Color4B& glowColor)
    void enableItalics()
    void enableBold()
    void enableUnderline()
    void enableStrikethrough()
    void disableEffect()
    void disableEffect(LabelEffect effect)
    bool isShadowEnabled()
    Size getShadowOffset()
    float getShadowBlurRadius()
    Color4F getShadowColor()
    float getOutlineSize()
    LabelEffect getLabelEffectType()
    Color4F getEffectColor()
    void setAlignment(TextHAlignment hAlignment)
    TextHAlignment getTextAlignment()
    void setAlignment(TextHAlignment hAlignment,TextVAlignment vAlignment)
    void setHorizontalAlignment(TextHAlignment hAlignment)
    TextHAlignment getHorizontalAlignment()
    void setVerticalAlignment(TextVAlignment vAlignment)
    TextVAlignment getVerticalAlignment()
    void setLineBreakWithoutSpace(bool breakWithoutSpace)
    void setMaxLineWidth(float maxLineWidth)
    float getMaxLineWidth()
    void setBMFontSize(float fontSize)
    float getBMFontSize()
    void enableWrap(bool enable)
    bool isWrapEnabled()
    void setOverflow(Overflow overflow)
    Overflow getOverflow()
    void setWidth(float width)
    float getWidth()
    void setHeight(float height)
    float getHeight()
    void setDimensions(float width, float height)
    const Size& getDimensions()
    void updateContent()
    Sprite * getLetter(int lettetIndex)
    void setClipMarginEnabled(bool clipEnabled)
    bool isClipMarginEnabled()
    void setLineHeight(float height)
    float getLineHeight()
    void setLineSpacing(float height)
    float getLineSpacing()
    void setAdditionalKerning(float space)
    float getAdditionalKerning()
    FontAtlas* getFontAtlas()
    const BlendFunc& getBlendFunc()
    void setBlendFunc(const BlendFunc &blendFunc)
]]

cls.props [[
    ttfConfig
    bmFontFilePath
    systemFontName
    systemFontSize
    string
    stringNumLines
    stringLength
    textColor
    shadowEnabled
    shadowOffset
    shadowBlurRadius
    shadowColor
    outlineSize
    labelEffectType
    effectColor
    textAlignment
    horizontalAlignment
    verticalAlignment
    maxLineWidth
    bmFontSize
    wrapEnabled
    overflow
    width
    height
    dimensions
    clipMarginEnabled
    lineHeight
    lineSpacing
    additionalKerning
    fontAtlas
    blendFunc
]]

return M