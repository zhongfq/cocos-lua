local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::Text::Type"
cls.LUACLS = "ccui.Text.Type"
cls.enums [[
    SYSTEM
    TTF
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::Text"
cls.LUACLS = "ccui.Text"
cls.SUPERCLS = "ccui.Widget"
cls.funcs [[
    static Text* create()
    static Text* create(const std::string& textContent, const std::string& fontName, float fontSize)
    void setString(const std::string& text)
    const std::string& getString()
    ssize_t getStringLength()
    void setFontSize(float size)
    float getFontSize()
    void setFontName(const std::string& name)
    const std::string& getFontName()
    Type getType()
    void setTouchScaleChangeEnabled(bool enabled)
    bool isTouchScaleChangeEnabled()
    Size getAutoRenderSize()
    void setTextAreaSize(const Size &size)
    const Size& getTextAreaSize()
    void setTextHorizontalAlignment(TextHAlignment alignment)
    TextHAlignment getTextHorizontalAlignment()
    void setTextVerticalAlignment(TextVAlignment alignment)
    TextVAlignment getTextVerticalAlignment()
    void setTextColor(const Color4B color)
    const Color4B& getTextColor()
    void enableShadow(const Color4B& shadowColor = Color4B::BLACK, const Size &offset = Size(2,-2), int blurRadius = 0);
    void enableOutline(const Color4B& outlineColor,int outlineSize = 1)
    void enableGlow(const Color4B& glowColor)
    void disableEffect()
    void disableEffect(LabelEffect effect)
    bool isShadowEnabled()
    Size getShadowOffset()
    float getShadowBlurRadius()
    Color4B getShadowColor()
    int getOutlineSize()
    LabelEffect getLabelEffectType()
    Color4B getEffectColor()
    Sprite * getLetter(int lettetIndex)
    void setBlendFunc(const BlendFunc &blendFunc)
    const BlendFunc &getBlendFunc()
]]

cls.props [[
    string
    stringLength
    fontSize
    fontName
    type
    touchScaleChangeEnabled
    autoRenderSize
    textAreaSize
    textHorizontalAlignment
    textVerticalAlignment
    textColor
    shadowEnabled
    shadowOffset
    shadowBlurRadius
    shadowColor
    outlineSize
    labelEffectType
    effectColor
    blendFunc
]]

return M