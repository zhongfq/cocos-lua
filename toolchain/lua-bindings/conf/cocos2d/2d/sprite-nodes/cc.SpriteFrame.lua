local cls = class()
cls.CPPCLS = "cocos2d::SpriteFrame"
cls.LUACLS = "cc.SpriteFrame"
cls.SUPERCLS = "cc.Ref"
cls.func("new", new_ccobj(cls))
cls.funcs([[
    static SpriteFrame* create(const std::string& filename, const Rect& rect)
    static SpriteFrame* create(const std::string& filename, const Rect& rect, bool rotated, const Vec2& offset, const Size& originalSize)
    static SpriteFrame* createWithTexture(Texture2D* pobTexture, const Rect& rect)
    static SpriteFrame* createWithTexture(Texture2D* pobTexture, const Rect& rect, bool rotated, const Vec2& offset, const Size& originalSize)
    const Rect& getRectInPixels()
    void setRectInPixels(const Rect& rectInPixels)
    bool isRotated()
    void setRotated(bool rotated)
    const Rect& getRect()
    void setRect(const Rect& rect)
    const Rect& getCenterRect()
    void setCenterRectInPixels(const Rect& centerRect)
    bool hasCenterRect()
    const Vec2& getOffsetInPixels()
    void setOffsetInPixels(const Vec2& offsetInPixels)
    const Size& getOriginalSizeInPixels()
    void setOriginalSizeInPixels(const Size& sizeInPixels)
    const Size& getOriginalSize()
    void setOriginalSize(const Size& sizeInPixels)
    Texture2D* getTexture()
    void setTexture(Texture2D* pobTexture)
    const Vec2& getOffset()
    void setOffset(const Vec2& offsets)
    const Vec2& getAnchorPoint()
    void setAnchorPoint(const Vec2& anchorPoint)
    bool hasAnchorPoint()
    SpriteFrame *clone()
    // void setPolygonInfo(const PolygonInfo &polygonInfo)
    // const PolygonInfo& getPolygonInfo()
    bool hasPolygonInfo()
    bool initWithTexture(Texture2D* pobTexture, const Rect& rect)
    bool initWithTextureFilename(const std::string& filename, const Rect& rect)
    bool initWithTexture(Texture2D* pobTexture, const Rect& rect, bool rotated, const Vec2& offset, const Size& originalSize)
    bool initWithTextureFilename(const std::string& filename, const Rect& rect, bool rotated, const Vec2& offset, const Size& originalSize)
]])

cls.props [[
    rotated
    texture
]]

return cls