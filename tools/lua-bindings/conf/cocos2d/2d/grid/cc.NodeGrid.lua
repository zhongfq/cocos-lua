local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::NodeGrid"
cls.LUACLS = "cc.NodeGrid"
cls.SUPERCLS = "cc.Node"
cls.funcs [[
    static NodeGrid* create()
    static NodeGrid* create(const Rect& rect)
    GridBase* getGrid()
    void setGrid(GridBase *grid)
    void setTarget(Node *target)
    void setGridRect(const Rect& gridRect)
    const Rect& getGridRect()
]]

cls.props [[
    grid
    gridRect
]]

return M