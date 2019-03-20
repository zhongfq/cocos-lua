local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::Layout::Type"
cls.LUACLS = "ccui.Layout.Type"
cls.enums [[
    ABSOLUTE
    VERTICAL
    HORIZONTAL
    RELATIVE
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::Layout::ClippingType"
cls.LUACLS = "ccui.Layout.ClippingType"
cls.enums [[
    STENCIL
    SCISSOR
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::Layout::BackGroundColorType"
cls.LUACLS = "ccui.Layout.BackGroundColorType"
cls.enums [[
    NONE
    SOLID
    GRADIENT
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::Layout"
cls.LUACLS = "ccui.Layout"
cls.SUPERCLS = "ccui.Widget"
cls.funcs [[
    static Layout* create()
    void setBackGroundImage(const std::string& fileName, Widget::TextureResType texType = Widget::TextureResType::LOCAL)
    void setBackGroundImageCapInsets(const Rect& capInsets)
    const Rect& getBackGroundImageCapInsets()
    void setBackGroundColorType(BackGroundColorType type)
    BackGroundColorType getBackGroundColorType()
    void setBackGroundImageScale9Enabled(bool enabled)
    bool isBackGroundImageScale9Enabled()
    void setBackGroundColor(const Color3B &color)
    const Color3B& getBackGroundColor()
    void setBackGroundColor(const Color3B &startColor, const Color3B &endColor)
    const Color3B& getBackGroundStartColor()
    const Color3B& getBackGroundEndColor()
    void setBackGroundColorOpacity(GLubyte opacity)
    GLubyte getBackGroundColorOpacity()
    void setBackGroundColorVector(Vec2 &vector)
    const Vec2& getBackGroundColorVector()
    void setBackGroundImageColor(const Color3B& color)
    void setBackGroundImageOpacity(GLubyte opacity)
    const Color3B& getBackGroundImageColor()
    GLubyte getBackGroundImageOpacity()
    void removeBackGroundImage()
    const Size& getBackGroundImageTextureSize()
    void setClippingEnabled(bool enabled)
    void setClippingType(ClippingType type)
    ClippingType getClippingType()
    bool isClippingEnabled()
    void setLayoutType(Type type)
    Type getLayoutType()
    void forceDoLayout()
    void requestDoLayout()
    void setLoopFocus(bool loop)
    bool isLoopFocus()
    void setPassFocusToChild(bool pass)
    bool isPassFocusToChild()
    ResourceData getRenderFile()
]]
cls.props [[
    backGroundImageCapInsets
    backGroundColorType
    backGroundImageScale9Enabled
    backGroundColor
    backGroundStartColor
    backGroundEndColor
    backGroundColorOpacity
    backGroundImageColor
    backGroundImageOpacity
    backGroundImageTextureSize
    clippingType
    clippingEnabled
    layoutType
    loopFocus
    passFocusToChild
    renderFile
]]
cls.vars [[
    @nullable std::function<int(Widget::FocusDirection, Widget*)> onPassFocusToChild;
]]

return M