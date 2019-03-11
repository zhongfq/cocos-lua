local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::Renderer"
cls.LUACLS = "cc.Renderer"
cls.funcs([[
    void render()
    void clean()
    void clear()
    // void setClearColor(const Color4F& clearColor)
    // ssize_t getDrawnBatches()
    // ssize_t getDrawnVertices()
    // void clearDrawStats()
    // void setDepthTest(bool enable)
]])

return M