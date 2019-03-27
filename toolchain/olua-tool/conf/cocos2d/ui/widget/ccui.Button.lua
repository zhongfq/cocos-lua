local cls = class()
cls.CPPCLS = "cocos2d::ui::Button"
cls.LUACLS = "ccui.Button"
cls.SUPERCLS = "ccui.Widget"
cls.funcs [[
    static Button* create()
    static Button* create(const std::string& normalImage, const std::string& selectedImage = "", const std::string& disableImage = "", Widget::TextureResType texType = Widget::TextureResType::LOCAL)
    void loadTextures(const std::string& normal, const std::string& selected, const std::string& disabled = "", Widget::TextureResType texType = Widget::TextureResType::LOCAL)
    void loadTextureNormal(const std::string& normal, Widget::TextureResType texType = Widget::TextureResType::LOCAL)
    void loadTexturePressed(const std::string& selected, Widget::TextureResType texType = Widget::TextureResType::LOCAL)
    void loadTextureDisabled(const std::string& disabled, Widget::TextureResType texType = Widget::TextureResType::LOCAL)
    void setCapInsets(const Rect &capInsets)
    void setCapInsetsNormalRenderer(const Rect &capInsets)
    const Rect& getCapInsetsNormalRenderer()
    void setCapInsetsPressedRenderer(const Rect &capInsets)
    const Rect& getCapInsetsPressedRenderer()
    void setCapInsetsDisabledRenderer(const Rect &capInsets)
    const Rect& getCapInsetsDisabledRenderer()
    void setScale9Enabled(bool enable)
    bool isScale9Enabled()
    void setPressedActionEnabled(bool enabled)
    Label* getTitleRenderer()
    void setTitleText(const std::string& text)
    std::string getTitleText()
    void setTitleColor(const Color3B& color)
    Color3B getTitleColor()
    void setTitleFontSize(float size)
    float getTitleFontSize()
    void setTitleFontName(const std::string& fontName)
    std::string getTitleFontName()
    void setTitleAlignment(TextHAlignment hAlignment)
    void setTitleAlignment(TextHAlignment hAlignment, TextVAlignment vAlignment)
    void setTitleLabel(Label* label)
    Label* getTitleLabel()
    void setZoomScale(float scale)
    float getZoomScale()
    Scale9Sprite* getRendererNormal()
    Scale9Sprite* getRendererClicked()
    Scale9Sprite* getRendererDisabled()
    void resetNormalRender()
    void resetPressedRender()
    void resetDisabledRender()
    ResourceData getNormalFile()
    ResourceData getPressedFile()
    ResourceData getDisabledFile()
]]

cls.props [[
    capInsetsNormalRenderer
    capInsetsPressedRenderer
    capInsetsDisabledRenderer
    scale9Enabled
    titleRenderer
    titleText
    titleColor
    titleFontSize
    titleFontName
    titleLabel
    zoomScale
    rendererNormal
    rendererClicked
    rendererDisabled
    normalFile
    pressedFile
    disabledFile
]]

return cls