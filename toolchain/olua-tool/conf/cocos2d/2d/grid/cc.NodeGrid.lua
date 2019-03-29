local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::NodeGrid"
cls.LUACLS = "cc.NodeGrid"
cls.SUPERCLS = "cc.Node"
cls.funcs [[
    static NodeGrid* create()
    static NodeGrid* create(const Rect& rect)
    GridBase* getGrid()
    // const GridBase* getGrid()
    void setGrid(GridBase *grid)
    void setTarget(Node *target)
    void setGridRect(const Rect& gridRect)
    const Rect& getGridRect()
    void visit(Renderer *renderer, const Mat4 &parentTransform, uint32_t parentFlags)
]]

return M