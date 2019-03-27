local cls = class()
cls.CPPCLS = "cocos2d::SpriteBatchNode"
cls.LUACLS = "cc.SpriteBatchNode"
cls.SUPERCLS = "cc.Node"
cls.funcs [[
    static SpriteBatchNode* createWithTexture(Texture2D* tex, ssize_t capacity = 29)
    static SpriteBatchNode* create(const std::string& fileImage, ssize_t capacity = 29)
    TextureAtlas* getTextureAtlas()
    void setTextureAtlas(TextureAtlas* textureAtlas)
    const std::vector<Sprite*>& getDescendants()
    void increaseAtlasCapacity()
    void removeChildAtIndex(ssize_t index, bool doCleanup)
    void appendChild(Sprite* sprite)
    void removeSpriteFromAtlas(Sprite *sprite)
    ssize_t rebuildIndexInOrder(Sprite *parent, ssize_t index)
    ssize_t highestAtlasIndexInChild(Sprite *sprite)
    ssize_t lowestAtlasIndexInChild(Sprite *sprite)
    ssize_t atlasIndexForChild(Sprite *sprite, int z)
    void reorderBatch(bool reorder)
    Texture2D* getTexture()
    void setTexture(Texture2D *texture)
    void setBlendFunc(const BlendFunc &blendFunc)
    const BlendFunc& getBlendFunc()
    void insertQuadFromSprite(Sprite *sprite, ssize_t index)
    SpriteBatchNode * addSpriteWithoutQuad(Sprite *child, int z, int aTag)
    void reserveCapacity(ssize_t newCapacity)
]]
cls.props [[
    textureAtlas
    descendants
    texture
    blendFunc
]]

return cls