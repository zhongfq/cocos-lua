local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::Waves3D"
cls.LUACLS = "cc.Waves3D"
cls.SUPERCLS = "cc.Grid3DAction"
cls.funcs [[
    static Waves3D* create(float duration, const Size& gridSize, unsigned int waves, float amplitude)
    float getAmplitude()
    void setAmplitude(float amplitude)
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::FlipX3D"
cls.LUACLS = "cc.FlipX3D"
cls.SUPERCLS = "cc.Grid3DAction"
cls.funcs [[
    static FlipX3D* create(float duration)
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::FlipY3D"
cls.LUACLS = "cc.FlipY3D"
cls.SUPERCLS = "cc.FlipX3D"
cls.funcs [[
    static FlipY3D* create(float duration)
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::Lens3D"
cls.LUACLS = "cc.Lens3D"
cls.SUPERCLS = "cc.Grid3DAction"
cls.funcs [[
    static Lens3D* create(float duration, const Size& gridSize, const Vec2& position, float radius)
    float getLensEffect()
    void setLensEffect(float lensEffect)
    void setConcave(bool concave)
    const Vec2& getPosition()
    void setPosition(const Vec2& position)
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::Ripple3D"
cls.LUACLS = "cc.Ripple3D"
cls.SUPERCLS = "cc.Grid3DAction"
cls.funcs [[
    static Ripple3D* create(float duration, const Size& gridSize, const Vec2& position, float radius, unsigned int waves, float amplitude)
    const Vec2& getPosition()
    void setPosition(const Vec2& position)
    float getAmplitude()
    void setAmplitude(float fAmplitude)
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::Shaky3D"
cls.LUACLS = "cc.Shaky3D"
cls.SUPERCLS = "cc.Grid3DAction"
cls.funcs [[
    static Shaky3D* create(float initWithDuration, const Size& gridSize, int range, bool shakeZ)
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::Liquid"
cls.LUACLS = "cc.Liquid"
cls.SUPERCLS = "cc.Grid3DAction"
cls.funcs [[
    static Liquid* create(float duration, const Size& gridSize, unsigned int waves, float amplitude)
    float getAmplitude()
    void setAmplitude(float amplitude)
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::Waves"
cls.LUACLS = "cc.Waves"
cls.SUPERCLS = "cc.Grid3DAction"
cls.funcs [[
    static Waves* create(float duration, const Size& gridSize, unsigned int waves, float amplitude, bool horizontal, bool vertical)
    float getAmplitude()
    void setAmplitude(float amplitude)
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::Twirl"
cls.LUACLS = "cc.Twirl"
cls.SUPERCLS = "cc.Grid3DAction"
cls.funcs [[
    static Twirl* create(float duration, const Size& gridSize, const Vec2& position, unsigned int twirls, float amplitude)
    const Vec2& getPosition()
    void setPosition(const Vec2& position)
    float getAmplitude()
    void setAmplitude(float amplitude)
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::PageTurn3D"
cls.LUACLS = "cc.PageTurn3D"
cls.SUPERCLS = "cc.Grid3DAction"
cls.funcs [[
    static PageTurn3D* create(float duration, const Size& gridSize)
]]

return M