local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::Scale9Sprite::State"
cls.LUACLS = "ccui.Scale9Sprite.State"
cls.enums [[
    NORMAL
    GRAY
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::Scale9Sprite::RenderingType"
cls.LUACLS = "ccui.Scale9Sprite.RenderingType"
cls.enums [[
    SIMPLE
    SLICE
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::Scale9Sprite"
cls.LUACLS = "ccui.Scale9Sprite"
cls.SUPERCLS = "cc.Sprite"
cls.funcs [[
    static Scale9Sprite* create()
    static Scale9Sprite* create(const std::string& file, const Rect& rect,  const Rect& capInsets)
    static Scale9Sprite* create(const Rect& capInsets, const std::string& file)
    static Scale9Sprite* create(const std::string& file, const Rect& rect)
    static Scale9Sprite* create(const std::string& file)
    static Scale9Sprite* createWithSpriteFrame(SpriteFrame* spriteFrame)
    static Scale9Sprite* createWithSpriteFrame(SpriteFrame* spriteFrame, const Rect& capInsets)
    static Scale9Sprite* createWithSpriteFrameName(const std::string& spriteFrameName)
    static Scale9Sprite* createWithSpriteFrameName(const std::string& spriteFrameName, const Rect& capInsets)
    Scale9Sprite* resizableSpriteWithCapInsets(const Rect& capInsets)
    bool updateWithSprite(Sprite* sprite, const Rect& rect, bool rotated, const Rect& capInsets)
    bool updateWithSprite(Sprite* sprite, const Rect& rect, bool rotated, const Vec2 &offset, const Size &originalSize, const Rect& capInsets)
    void setSpriteFrame(SpriteFrame * spriteFrame, const Rect& capInsets)
    void setState(State state)
    State getState()
    Size getOriginalSize()
    void setPreferredSize(Size& size)
    Size getPreferredSize()
    void setInsetLeft(float leftInset)
    float getInsetLeft()
    void setInsetTop(float topInset)
    float getInsetTop()
    void setInsetRight(float rightInset)
    float getInsetRight()
    void setInsetBottom(float bottomInset)
    float getInsetBottom()
    void setScale9Enabled(bool enabled)
    bool isScale9Enabled()
    Sprite* getSprite()
    void copyTo(Scale9Sprite* copy)
    void setRenderingType(RenderingType type)
    RenderingType getRenderingType()
    void setCapInsets(const Rect& insets)
    Rect getCapInsets()
    void resetRender()
]]
cls.props [[
    state
    originalSize
    preferredSize
    insetLeft
    insetTop
    insetRight
    insetBottom
    scale9Enabled
    sprite
    renderingType
    capInsets
]]

return M