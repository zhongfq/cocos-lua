local M = {}

local cls = class(M)
cls.CPPCLS = "ResolutionPolicy"
cls.LUACLS = "cc.ResolutionPolicy"
cls.enums [[
    EXACT_FIT
    NO_BORDER
    SHOW_ALL
    FIXED_HEIGHT
    FIXED_WIDTH
    UNKNOWN
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::GLView"
cls.LUACLS = "cc.GLView"
cls.SUPERCLS = "cc.Ref"
cls.funcs([[
    static void setGLContextAttrs(GLContextAttrs& glContextAttrs)
    static GLContextAttrs getGLContextAttrs()
    void end();
    bool isOpenGLReady()
    void swapBuffers()
    void setIMEKeyboardState(bool open)
    bool windowShouldClose()
    void pollEvents()
    Size getFrameSize()
    void setFrameSize(float width, float height)
    void setFrameZoomFactor(float zoomFactor) 
    float getFrameZoomFactor()
    void setCursorVisible(bool isVisible)
    int getRetinaFactor()
    bool setContentScaleFactor(float scaleFactor)
    float getContentScaleFactor()
    bool isRetinaDisplay()
    Size getVisibleSize()
    Vec2 getVisibleOrigin()
    Rect getVisibleRect()
    Rect getSafeAreaRect()
    void setDesignResolutionSize(float width, float height, ResolutionPolicy resolutionPolicy)
    const Size&  getDesignResolutionSize() const;
    void setViewPortInPoints(float x , float y , float w , float h)
    void setScissorInPoints(float x , float y , float w , float h)
    bool isScissorEnabled()
    Rect getScissorRect()
    void setViewName(const std::string& viewname)
    const std::string& getViewName()
    const Rect& getViewPortRect()
    std::vector<Touch*> getAllTouches()
    float getScaleX()
    float getScaleY()
    ResolutionPolicy getResolutionPolicy()
    void renderScene(Scene* scene, Renderer* renderer)
    void setVR(VRIRenderer* vrrenderer)
    VRIRenderer* getVR()
]])
cls.props [[
    glContextAttrs
    openGLReady
    frameZoomFactor
    retinaFactor
    contentScaleFactor
    retinaDisplay
    scissorEnabled
    viewName
    scaleX
    scaleY
    resolutionPolicy
    vr
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::GLViewImpl"
cls.LUACLS = "cc.GLViewImpl"
cls.SUPERCLS = "cc.GLView"
cls.funcs([[
    static GLViewImpl* create(const std::string& viewName);
    // static GLViewImpl* createWithRect(const std::string& viewName, Rect size, float frameZoomFactor = 1.0f, bool resizable = false);
    static GLViewImpl* createWithFullScreen(const std::string& viewName);
]])

return M