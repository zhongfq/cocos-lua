local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::GridAction"
cls.LUACLS = "cc.GridAction"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs [[
    GridBase* getGrid()
    GridAction * clone()
    GridAction* reverse()
    void startWithTarget(Node *target)
    bool initWithDuration(float duration, const Size& gridSize)
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::Grid3DAction"
cls.LUACLS = "cc.Grid3DAction"
cls.SUPERCLS = "cc.GridAction"
cls.funcs [[
    GridBase* getGrid()
    Vec3 getVertex(const Vec2& position)
    Vec3 getOriginalVertex(const Vec2& position)
    void setVertex(const Vec2& position, const Vec3& vertex)
    Grid3DAction * clone()
    Rect getGridRect()
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::TiledGrid3DAction"
cls.LUACLS = "cc.TiledGrid3DAction"
cls.SUPERCLS = "cc.GridAction"
cls.funcs [[
    static TiledGrid3DAction* create(float duration, const Size& gridSize)
    Quad3 getTile(const Vec2& position)
    Quad3 getOriginalTile(const Vec2& position)
    void setTile(const Vec2& position, const Quad3& coords)
    GridBase* getGrid()
    TiledGrid3DAction * clone()
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::AccelDeccelAmplitude"
cls.LUACLS = "cc.AccelDeccelAmplitude"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs [[
    static AccelDeccelAmplitude* create(Action *action, float duration)
    float getRate()
    void setRate(float rate)
    void startWithTarget(Node *target)
    void update(float time)
    AccelDeccelAmplitude* clone()
    AccelDeccelAmplitude* reverse()
    bool initWithAction(Action *action, float duration)
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::AccelAmplitude"
cls.LUACLS = "cc.AccelAmplitude"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs [[
    static AccelAmplitude* create(Action *action, float duration)
    float getRate()
    void setRate(float rate)
    void startWithTarget(Node *target)
    void update(float time)
    AccelAmplitude* clone()
    AccelAmplitude* reverse()
    bool initWithAction(Action *action, float duration)
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::DeccelAmplitude"
cls.LUACLS = "cc.DeccelAmplitude"
cls.SUPERCLS = "cc.ActionInterval"
cls.funcs [[
    static DeccelAmplitude* create(Action *action, float duration)
    float getRate()
    void setRate(float rate)
    void startWithTarget(Node *target)
    void update(float time)
    DeccelAmplitude* clone()
    DeccelAmplitude* reverse()
    bool initWithAction(Action *action, float duration)
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::StopGrid"
cls.LUACLS = "cc.StopGrid"
cls.SUPERCLS = "cc.ActionInstant"
cls.funcs [[
    static StopGrid* create()
    void startWithTarget(Node *target)
    StopGrid* clone()
    StopGrid* reverse()
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ReuseGrid"
cls.LUACLS = "cc.ReuseGrid"
cls.SUPERCLS = "cc.ActionInstant"
cls.funcs [[
    static ReuseGrid* create(int times)
    void startWithTarget(Node *target)
    ReuseGrid* clone()
    ReuseGrid* reverse()
    bool initWithTimes(int times)
]]

return M