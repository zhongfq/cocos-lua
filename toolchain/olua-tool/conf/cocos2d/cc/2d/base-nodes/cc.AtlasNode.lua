local cls = class()
cls.CPPCLS = "cocos2d::AtlasNode"
cls.LUACLS = "cc.AtlasNode"
cls.SUPERCLS = "cc.Node"
cls.funcs([[
    static AtlasNode * create(const std::string& filename, int tileWidth, int tileHeight, int itemsToRender)
    void updateAtlasValues()
    void setTextureAtlas(TextureAtlas* textureAtlas)
    TextureAtlas* getTextureAtlas()
    void setQuadsToDraw(ssize_t quadsToDraw)
    ssize_t getQuadsToDraw()
]])

return cls