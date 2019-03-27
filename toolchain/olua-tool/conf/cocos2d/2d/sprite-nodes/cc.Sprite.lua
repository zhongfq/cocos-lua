local cls = class()
cls.CPPCLS = "cocos2d::Sprite"
cls.LUACLS = "cc.Sprite"
cls.SUPERCLS = "cc.Node"
cls.funcs [[
    static Sprite* create()
    static Sprite* create(const std::string& filename)
    // static Sprite* create(const PolygonInfo& info)
    static Sprite* create(const std::string& filename, const Rect& rect)
    static Sprite* createWithTexture(Texture2D *texture)
    static Sprite* createWithTexture(Texture2D *texture, const Rect& rect, bool rotated=false)
    static Sprite* createWithSpriteFrame(SpriteFrame *spriteFrame)
    static Sprite* createWithSpriteFrameName(const std::string& spriteFrameName)
    SpriteBatchNode* getBatchNode()
    void setBatchNode(SpriteBatchNode *spriteBatchNode)
    void setTexture(const std::string &filename )
    void setTexture(Texture2D *texture)
    Texture2D* getTexture()
    void setTextureRect(const Rect& rect)
    void setTextureRect(const Rect& rect, bool rotated, const Size& untrimmedSize)
    void setVertexRect(const Rect& rect)
    void setCenterRectNormalized(const Rect& rect)
    Rect getCenterRectNormalized()
    void setCenterRect(const Rect& rect)
    Rect getCenterRect()
    void setSpriteFrame(const std::string &spriteFrameName)
    void setSpriteFrame(SpriteFrame* newFrame)
    bool isFrameDisplayed(SpriteFrame *frame)
    SpriteFrame* getSpriteFrame()
    void setDisplayFrameWithAnimationName(const std::string& animationName, ssize_t frameIndex)
    bool isDirty()
    void setDirty(bool dirty)
    // V3F_C4B_T2F_Quad getQuad()
    bool isTextureRectRotated()
    ssize_t getAtlasIndex()
    void setAtlasIndex(ssize_t atlasIndex)
    const Rect& getTextureRect()
    TextureAtlas* getTextureAtlas()
    void setTextureAtlas(TextureAtlas *textureAtlas)
    const Vec2& getOffsetPosition()
    bool isFlippedX()
    void setFlippedX(bool flippedX)
    bool isFlippedY()
    void setFlippedY(bool flippedY)
    // const PolygonInfo& getPolygonInfo()
    // void setPolygonInfo(const PolygonInfo& info)
    void setStretchEnabled(bool enabled)
    bool isStretchEnabled()
    void setBlendFunc(const BlendFunc &blendFunc)
    const BlendFunc& getBlendFunc()
    int getResourceType()
    const std::string& getResourceName()
]]

cls.props [[
    batchNode
    texture
    centerRectNormalized
    centerRect
    spriteFrame
    dirty
    textureRectRotated
    atlasIndex
    textureRect
    textureAtlas
    offsetPosition
    flippedX
    flippedY
    stretchEnabled
    blendFunc
    resourceType
    resourceName
]]
return cls