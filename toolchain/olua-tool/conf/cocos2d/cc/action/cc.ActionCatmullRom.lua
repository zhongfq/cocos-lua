local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::PointArray"
cls.LUACLS = "cc.PointArray"
cls.SUPERCLS = "cc.Ref"
cls.funcs([[
    static PointArray* create(ssize_t capacity)
    void addControlPoint(const Vec2& controlPoint)
    void insertControlPoint(const Vec2& controlPoint, ssize_t index)
    void replaceControlPoint(const Vec2& controlPoint, ssize_t index)
    const Vec2& getControlPointAtIndex(ssize_t index)
    void removeControlPointAtIndex(ssize_t index)
    ssize_t count()
    void reverseInline()
    // const std::vector<Vec2>& getControlPoints()
    // void setControlPoints(std::vector<Vec2> controlPoints)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::CardinalSplineTo"
cls.LUACLS = "cc.CardinalSplineTo"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs([[
    static CardinalSplineTo* create(float duration, PointArray* points, float tension)
    PointArray* getPoints()
    void setPoints(PointArray* points)
]])
cls.prop('points')

local cls = class(M)
cls.CPPCLS = "cocos2d::CardinalSplineBy"
cls.LUACLS = "cc.CardinalSplineBy"
cls.SUPERCLS = "cc.CardinalSplineTo"
cls.funcs([[
    static CardinalSplineBy* create(float duration, PointArray* points, float tension)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::CatmullRomTo"
cls.LUACLS = "cc.CatmullRomTo"
cls.SUPERCLS = "cc.CardinalSplineTo"
cls.funcs([[
    static CatmullRomTo* create(float dt, PointArray* points)
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::CatmullRomBy"
cls.LUACLS = "cc.CatmullRomBy"
cls.SUPERCLS = "cc.CardinalSplineBy"
cls.funcs([[
    static CatmullRomBy* create(float dt, PointArray* points)
]])

return M