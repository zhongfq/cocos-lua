local cls = class()
cls.CPPCLS = "cocos2d::ui::ImageView"
cls.LUACLS = "ccui.ImageView"
cls.SUPERCLS = "ccui.Widget"
cls.funcs [[
    static ImageView* create()
    static ImageView* create(const std::string& imageFileName, Widget::TextureResType texType = Widget::TextureResType::LOCAL)
    void loadTexture(const std::string& fileName,Widget::TextureResType texType = Widget::TextureResType::LOCAL)
    void setTextureRect(const Rect& rect)
    void setScale9Enabled(bool enabled)
    bool isScale9Enabled()
    void setCapInsets(const Rect &capInsets)
    const Rect& getCapInsets()
    void setBlendFunc(const BlendFunc &blendFunc)
    const BlendFunc &getBlendFunc()
    ResourceData getRenderFile()
]]

cls.props [[
    scale9Enabled
    capInsets
    blendFunc
    renderFile
]]

return cls