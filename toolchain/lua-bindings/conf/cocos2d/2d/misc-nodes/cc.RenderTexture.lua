local cls = class()
cls.CPPCLS = "cocos2d::RenderTexture"
cls.LUACLS = "cc.RenderTexture"
cls.SUPERCLS = "cc.Node"
cls.funcs [[
    static RenderTexture * create(int w ,int h, Texture2D::PixelFormat format, GLuint depthStencilFormat)
    static RenderTexture * create(int w, int h, Texture2D::PixelFormat format)
    static RenderTexture * create(int w, int h)
    void begin()
    void beginWithClear(float r, float g, float b, float a)
    void beginWithClear(float r, float g, float b, float a, float depthValue)
    void beginWithClear(float r, float g, float b, float a, float depthValue, int stencilValue)
    void end()
    void clear(float r, float g, float b, float a)
    void clearDepth(float depthValue)
    void clearStencil(int stencilValue)
    Image* newImage(bool flipImage = true)
    void listenToBackground(EventCustom *event)
    void listenToForeground(EventCustom *event)
    unsigned int getClearFlags()
    void setClearFlags(unsigned int clearFlags)
    const Color4F& getClearColor()
    void setClearColor(const Color4F &clearColor)
    float getClearDepth()
    void setClearDepth(float clearDepth)
    int getClearStencil()
    void setClearStencil(int clearStencil)
    bool isAutoDraw()
    void setAutoDraw(bool isAutoDraw)
    Sprite* getSprite()
    void setSprite(Sprite* sprite)
    void setKeepMatrix(bool keepMatrix)
    void setVirtualViewport(const Vec2& rtBegin, const Rect& fullRect, const Rect& fullViewport)
]]

cls.callback(
    'bool saveToFile(const std::string& filename, bool isRGBA = true, std::function<void (RenderTexture*, const std::string&)> callback = nullptr)',
    'bool saveToFile(const std::string& filename, Image::Format format, bool isRGBA = true, std::function<void (RenderTexture*, const std::string&)> callback = nullptr)',
    {
        CALLBACK_MAKER = 'olua_makecallbacktag("saveToFile")',
        CALLBACK_REPLACE = false,
        CALLBACK_CALLONCE = true,
        CALLBACK_MODE = "OLUA_CALLBACK_TAG_EQUAL",
    }
)

return cls