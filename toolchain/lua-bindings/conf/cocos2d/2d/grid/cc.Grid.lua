local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::GridBase"
cls.LUACLS = "cc.GridBase"
cls.SUPERCLS = "cc.Ref"
cls.funcs [[
    static GridBase* create(const Size& gridSize, Texture2D *texture, bool flipped)
    static GridBase* create(const Size& gridSize)
    bool initWithSize(const Size& gridSize)
    bool initWithSize(const Size& gridSize, const Rect& rect)
    bool initWithSize(const Size& gridSize, Texture2D *texture, bool flipped)
    bool initWithSize(const Size& gridSize, Texture2D *texture, bool flipped, const Rect& rect)
    bool isActive()
    void setActive(bool active)
    int getReuseGrid()
    void setReuseGrid(int reuseGrid)
    const Size& getGridSize()
    void setGridSize(const Size& gridSize)
    const Vec2& getStep()
    void setStep(const Vec2& step)
    bool isTextureFlipped()
    void setTextureFlipped(bool flipped)
    void beforeDraw(void)
    void afterDraw(Node *target)
    void beforeBlit()
    void afterBlit()
    void blit(void)
    void reuse(void)
    void calculateVertexPoints(void)
    void set2DProjection(void)
    void setGridRect(const Rect& rect)
    const Rect& getGridRect()
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::Grid3D"
cls.LUACLS = "cc.Grid3D"
cls.SUPERCLS = "cc.GridBase"
cls.funcs [[
    static Grid3D* create(const Size& gridSize)
    static Grid3D* create(const Size& gridSize, const Rect& rect)
    static Grid3D* create(const Size& gridSize, Texture2D *texture, bool flipped)
    static Grid3D* create(const Size& gridSize, Texture2D *texture, bool flipped, const Rect& rect)
    Vec3 getVertex(const Vec2& pos)
    Vec3 getOriginalVertex(const Vec2& pos)
    void setVertex(const Vec2& pos, const Vec3& vertex)
]]


local cls = class(M)
cls.CPPCLS = "cocos2d::TiledGrid3D"
cls.LUACLS = "cc.TiledGrid3D"
cls.SUPERCLS = "cc.GridBase"
cls.funcs [[
    static TiledGrid3D* create(const Size& gridSize)
    static TiledGrid3D* create(const Size& gridSize, const Rect& rect)
    static TiledGrid3D* create(const Size& gridSize, Texture2D *texture, bool flipped)
    static TiledGrid3D* create(const Size& gridSize, Texture2D *texture, bool flipped, const Rect& rect)
    Quad3 getTile(const Vec2& pos)
    Quad3 getOriginalTile(const Vec2& pos)
    void setTile(const Vec2& pos, const Quad3& coords)
]]

return M