local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::ProgressTimer::Type"
cls.LUACLS = "cc.ProgressTimer.Type"
cls.enums [[
    RADIAL
    BAR
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ProgressTimer"
cls.LUACLS = "cc.ProgressTimer"
cls.SUPERCLS = "cc.Node"
cls.funcs [[
    static ProgressTimer* create(Sprite* sp)
    Type getType()
    float getPercentage()
    Sprite* getSprite()
    void setPercentage(float percentage)
    void setSprite(Sprite *sprite)
    void setType(Type type)
    bool isReverseDirection()
    void setReverseDirection(bool value)
    void setMidpoint(const Vec2& point)
    Vec2 getMidpoint()
    void setBarChangeRate(const Vec2& barChangeRate )
    Vec2 getBarChangeRate()
]]

cls.props [[
    type
    percentage
    sprite
    reverseDirection
    midpoint
    barChangeRate
]]

return M