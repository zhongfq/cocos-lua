local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::Layer"
cls.LUACLS = "cc.Layer"
cls.SUPERCLS = "cc.Node"
cls.funcs([[
    static Layer *create()
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::LayerColor"
cls.LUACLS = "cc.LayerColor"
cls.SUPERCLS = "cc.Layer"
cls.funcs [[
    static LayerColor* create()
    static LayerColor * create(const Color4B& color, GLfloat width, GLfloat height)
    static LayerColor * create(const Color4B& color)
    void changeWidth(GLfloat w)
    void changeHeight(GLfloat h)
    void changeWidthAndHeight(GLfloat w ,GLfloat h)
    const BlendFunc& getBlendFunc()
    void setBlendFunc(const BlendFunc& blendFunc)
]]
cls.props [[
    blendFunc
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::LayerGradient"
cls.LUACLS = "cc.LayerGradient"
cls.SUPERCLS = "cc.LayerColor"
cls.funcs [[
    static LayerGradient* create()
    static LayerGradient* create(const Color4B& start, const Color4B& end)
    static LayerGradient* create(const Color4B& start, const Color4B& end, const Vec2& v)
    void setCompressedInterpolation(bool compressedInterpolation)
    bool isCompressedInterpolation()
    void setStartColor( const Color3B& startColor )
    const Color3B& getStartColor()
    void setEndColor( const Color3B& endColor )
    const Color3B& getEndColor()
    void setStartOpacity( GLubyte startOpacity )
    GLubyte getStartOpacity()
    void setEndOpacity( GLubyte endOpacity )
    GLubyte getEndOpacity()
    void setVector(const Vec2& alongVector)
    @unapck const Vec2& getVector()
]]
cls.props [[
    compressedInterpolation
    startColor
    endColor
    startOpacity
    endOpacity
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::LayerRadialGradient"
cls.LUACLS = "cc.LayerRadialGradient"
cls.SUPERCLS = "cc.Layer"
cls.funcs([[
    static LayerRadialGradient* create(const Color4B& startColor, const Color4B& endColor, float radius, const Vec2& center, float expand)
    static LayerRadialGradient* create()
    void setStartOpacity(GLubyte opacity)
    GLubyte getStartOpacity()
    void setEndOpacity(GLubyte opacity)
    GLubyte getEndOpacity()
    void setRadius(float radius)
    float getRadius()
    void setCenter(const Vec2& center)
    Vec2 getCenter()
    void setExpand(float expand)
    float getExpand()
    void setStartColor(const Color4B& color)
    Color4B getStartColor()
    void setEndColor(const Color4B& color)
    Color4B getEndColor()
    void setBlendFunc(const BlendFunc& blendFunc)
    BlendFunc getBlendFunc()
]])
cls.props [[
    startOpacity
    endOpacity
    radius
    expand
    startColor
    endColor
    blendFunc
]]

return M