local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::RichElement::Type"
cls.LUACLS = "ccui.RichElement.Type"
cls.enums [[
    TEXT
    IMAGE
    CUSTOM
    NEWLINE
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::RichElement"
cls.LUACLS = "ccui.RichElement"
cls.SUPERCLS = "cc.Ref"
cls.funcs [[
    bool equalType(Type type)
    void setColor(const Color3B& color)
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::RichElementText"
cls.LUACLS = "ccui.RichElementText"
cls.SUPERCLS = "ccui.RichElement"
cls.funcs [[
    static RichElementText* create(int tag, const Color3B& color, GLubyte opacity, const std::string& text, const std::string& fontName, float fontSize, uint32_t flags=0, const std::string& url="", const Color3B& outlineColor = Color3B::WHITE, int outlineSize = -1, const Color3B& shadowColor = Color3B::BLACK, const cocos2d::Size& shadowOffset = Size(2.0, -2.0), int shadowBlurRadius = 0, const Color3B& glowColor = Color3B::WHITE);
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::RichElementImage"
cls.LUACLS = "ccui.RichElementImage"
cls.SUPERCLS = "ccui.RichElement"
cls.funcs [[
    static RichElementImage* create(int tag, const Color3B& color, GLubyte opacity, const std::string& filePath, const std::string& url = "", Widget::TextureResType texType = Widget::TextureResType::LOCAL)
    void setWidth(int width)
    void setHeight(int height)
    void setUrl(const std::string& url)
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::RichElementCustomNode"
cls.LUACLS = "ccui.RichElementCustomNode"
cls.SUPERCLS = "ccui.RichElement"
cls.funcs [[
    static RichElementCustomNode* create(int tag, const Color3B& color, GLubyte opacity, Node* customNode)
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::RichElementNewLine"
cls.LUACLS = "ccui.RichElementNewLine"
cls.SUPERCLS = "ccui.RichElement"
cls.funcs [[
    static RichElementNewLine* create(int tag, const Color3B& color, GLubyte opacity)
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::RichText::WrapMode"
cls.LUACLS = "ccui.RichText.WrapMode"
cls.enums [[
    WRAP_PER_WORD
    WRAP_PER_CHAR
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::RichText::HorizontalAlignment"
cls.LUACLS = "ccui.RichText.HorizontalAlignment"
cls.enums [[
    LEFT
    CENTER
    RIGHT
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::RichText"
cls.LUACLS = "ccui.RichText"
cls.SUPERCLS = "ccui.Widget"
cls.funcs [[
    static RichText* create()
    void insertElement(RichElement* element, int index)
    void pushBackElement(RichElement* element)
    void removeElement(int index)
    void removeElement(RichElement* element)
    void setVerticalSpace(float space)
    void formatText()
    void setWrapMode(WrapMode wrapMode)
    WrapMode getWrapMode()
    void setHorizontalAlignment(HorizontalAlignment a)
    HorizontalAlignment getHorizontalAlignment()
    void setFontColor(const std::string& color)
    std::string getFontColor()
    Color3B getFontColor3B()
    void setFontSize(float size)
    float getFontSize()
    void setFontFace(const std::string& face)
    std::string getFontFace()
    void setAnchorFontColor(const std::string& color)
    std::string getAnchorFontColor()
    cocos2d::Color3B getAnchorFontColor3B()
    void setAnchorTextBold(bool enable)
    bool isAnchorTextBoldEnabled()
    void setAnchorTextItalic(bool enable)
    bool isAnchorTextItalicEnabled()
    void setAnchorTextDel(bool enable)
    bool isAnchorTextDelEnabled()
    void setAnchorTextUnderline(bool enable)
    bool isAnchorTextUnderlineEnabled()
    void setAnchorTextOutline(bool enable, const Color3B& outlineColor = Color3B::WHITE, int outlineSize = -1)
    bool isAnchorTextOutlineEnabled()
    Color3B getAnchorTextOutlineColor3B()
    int getAnchorTextOutlineSize()
    void setAnchorTextShadow(bool enable, const Color3B& shadowColor = Color3B::BLACK, const Size& offset = Size(2.0, -2.0), int blurRadius = 0)
    bool isAnchorTextShadowEnabled()
    Color3B getAnchorTextShadowColor3B()
    Size getAnchorTextShadowOffset()
    int getAnchorTextShadowBlurRadius()
    void setAnchorTextGlow(bool enable, const Color3B& glowColor = Color3B::WHITE)
    bool isAnchorTextGlowEnabled()
    Color3B getAnchorTextGlowColor3B()
    void setDefaults(const ValueMap& defaults)
    ValueMap getDefaults()
    cocos2d::Color3B color3BWithString(const std::string& color)
    std::string stringWithColor3B(const cocos2d::Color3B& color3b)
    std::string stringWithColor4B(const cocos2d::Color4B& color4b)
    static void removeTagDescription(const std::string& tag)
    void openUrl(const std::string& url)
]]

cls.callback(
    'static RichText* createWithXML(const std::string& xml)',
    'static RichText* createWithXML(const std::string& xml, const ValueMap& defaults)',
    'static RichText* createWithXML(const std::string& xml, const ValueMap& defaults, const std::function<void(const std::string& url)>& handleOpenUrl)',
    {
        CALLBACK_MAKER = 'olua_makecallbacktag("handleOpenUrl")',
        CALLBACK_INITFUNC = 'initWithXML',
    }
)

cls.callbacks [[
    void setOpenUrlHandler(const std::function<void(const std::string& url)>& handleOpenUrl)
    // static void setTagDescription(const std::string& tag, bool isFontElement, std::function<std::pair<ValueMap, RichElement*>(const ValueMap& tagAttrValueMap)> handleVisitEnter)
]]

cls.props [[
    wrapMode
    horizontalAlignment
    fontColor
    fontColor3B
    fontSize
    fontFace
    anchorFontColor
    anchorFontColor3B
    anchorTextBoldEnabled
    anchorTextItalicEnabled
    anchorTextDelEnabled
    anchorTextUnderlineEnabled
    anchorTextOutlineEnabled
    anchorTextOutlineColor3B
    anchorTextOutlineSize
    anchorTextShadowEnabled
    anchorTextShadowColor3B
    anchorTextShadowOffset
    anchorTextShadowBlurRadius
    anchorTextGlowEnabled
    anchorTextGlowColor3B
    defaults
]]

return M