local cls = class()
cls.CPPCLS = "cocos2d::ui::AbstractCheckButton"
cls.LUACLS = "ccui.AbstractCheckButton"
cls.SUPERCLS = "ccui.Widget"
cls.funcs [[
    void loadTextures(const std::string& background,const std::string& backgroundSelected,const std::string& cross,const std::string& backgroundDisabled,const std::string& frontCrossDisabled,Widget::TextureResType texType = Widget::TextureResType::LOCAL)
    void loadTextureBackGround(const std::string& backGround,Widget::TextureResType type = Widget::TextureResType::LOCAL)
    void loadTextureBackGroundSelected(const std::string& backGroundSelected,Widget::TextureResType texType = Widget::TextureResType::LOCAL)
    void loadTextureFrontCross(const std::string& crossTextureName,Widget::TextureResType texType = Widget::TextureResType::LOCAL)
    void loadTextureBackGroundDisabled(const std::string& backGroundDisabled,Widget::TextureResType texType = Widget::TextureResType::LOCAL)
    void loadTextureFrontCrossDisabled(const std::string& frontCrossDisabled,Widget::TextureResType texType = Widget::TextureResType::LOCAL)
    bool isSelected()
    void setSelected(bool selected)
    void setZoomScale(float scale)
    float getZoomScale()
    @ref(map protectedChildren) Sprite* getRendererBackground()
    @ref(map protectedChildren) Sprite* getRendererBackgroundSelected()
    @ref(map protectedChildren) Sprite* getRendererFrontCross()
    @ref(map protectedChildren) Sprite* getRendererBackgroundDisabled()
    @ref(map protectedChildren) Sprite* getRendererFrontCrossDisabled()
    ResourceData getBackNormalFile()
    ResourceData getBackPressedFile()
    ResourceData getBackDisabledFile()
    ResourceData getCrossNormalFile()
    ResourceData getCrossDisabledFile()
]]

cls.props [[
    selected
    zoomScale
    rendererBackground
    rendererBackgroundSelected
    rendererFrontCross
    rendererBackgroundDisabled
    rendererFrontCrossDisabled
    backNormalFile
    backPressedFile
    backDisabledFile
    crossNormalFile
    crossDisabledFile
]]

return cls