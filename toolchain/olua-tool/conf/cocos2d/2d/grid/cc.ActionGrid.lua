local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::GridAction"
cls.LUACLS = "cc.GridAction"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs [[
    GridBase* getGrid()
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::Grid3DAction"
cls.LUACLS = "cc.Grid3DAction"
cls.SUPERCLS = "cc.GridAction"
cls.funcs [[
    Vec3 getVertex(const Vec2& position)
    Vec3 getOriginalVertex(const Vec2& position)
    void setVertex(const Vec2& position, const Vec3& vertex)
    Rect getGridRect()
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::TiledGrid3DAction"
cls.LUACLS = "cc.TiledGrid3DAction"
cls.SUPERCLS = "cc.GridAction"
cls.DEFCHUNK = [[
NS_CC_BEGIN
TiledGrid3DAction* TiledGrid3DAction::create(float duration, const Size& gridSize)
{
    TiledGrid3DAction* ret = new TiledGrid3DAction();
    ret->autorelease();
    ret->initWithDuration(duration, gridSize);
    return ret;
}
NS_CC_END
]]
cls.funcs [[
    static TiledGrid3DAction* create(float duration, const Size& gridSize)
    Quad3 getTile(const Vec2& position)
    Quad3 getOriginalTile(const Vec2& position)
    void setTile(const Vec2& position, const Quad3& coords)
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::AccelDeccelAmplitude"
cls.LUACLS = "cc.AccelDeccelAmplitude"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs [[
    static AccelDeccelAmplitude* create(Action *action, float duration)
    float getRate()
    void setRate(float rate)
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::AccelAmplitude"
cls.LUACLS = "cc.AccelAmplitude"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs [[
    static AccelAmplitude* create(Action *action, float duration)
    float getRate()
    void setRate(float rate)
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::DeccelAmplitude"
cls.LUACLS = "cc.DeccelAmplitude"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs [[
    static DeccelAmplitude* create(Action *action, float duration)
    float getRate()
    void setRate(float rate)
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::StopGrid"
cls.LUACLS = "cc.StopGrid"
cls.SUPERCLS = "cc.ActionInstant"
cls.funcs [[
    static StopGrid* create()
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ReuseGrid"
cls.LUACLS = "cc.ReuseGrid"
cls.SUPERCLS = "cc.ActionInstant"
cls.funcs [[
    static ReuseGrid* create(int times)
]]

return M