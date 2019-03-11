local M = {}

local cls = class(M)
cls.CPPCLS = "ResolutionPolicy"
cls.LUACLS = "cc.ResolutionPolicy"
cls.enum('EXACT_FIT', 'ResolutionPolicy::EXACT_FIT')
cls.enum('NO_BORDER', 'ResolutionPolicy::NO_BORDER')
cls.enum('SHOW_ALL', 'ResolutionPolicy::SHOW_ALL')
cls.enum('FIXED_HEIGHT', 'ResolutionPolicy::FIXED_HEIGHT')
cls.enum('FIXED_WIDTH', 'ResolutionPolicy::FIXED_WIDTH')
cls.enum('UNKNOWN', 'ResolutionPolicy::UNKNOWN')

local cls = class(M)
cls.CPPCLS = "cocos2d::GLView"
cls.LUACLS = "cc.GLView"
cls.SUPERCLS = "cc.Ref"
cls.prop('glContextAttrs', 'static GLContextAttrs getGLContextAttrs()', 'static void setGLContextAttrs(GLContextAttrs& glContextAttrs)')
cls.prop('openGLReady', 'bool isOpenGLReady()')
cls.prop('frameZoomFactor', 'float getFrameZoomFactor()', 'void setFrameZoomFactor(float zoomFactor)')
cls.prop('retinaFactor', 'int getRetinaFactor()')
cls.prop('contentScaleFactor', 'bool setContentScaleFactor(float scaleFactor)', 'void setContentScaleFactor(float scaleFactor)')
cls.prop('retinaDisplay', 'bool isRetinaDisplay()')
cls.prop('scissorEnabled', 'bool isScissorEnabled()')
cls.prop('viewName', 'const std::string& getViewName()', 'void setViewName(const std::string& viewname)')
cls.prop('scaleX', 'float getScaleX()')
cls.prop('scaleY', 'float getScaleY()')
cls.prop('resolutionPolicy', 'ResolutionPolicy getResolutionPolicy()')
cls.prop('vr', 'VRIRenderer* getVR()', 'void setVR(VRIRenderer* vrrenderer)')
cls.funcs([[
    static void setGLContextAttrs(GLContextAttrs& glContextAttrs)
    static GLContextAttrs getGLContextAttrs()
    void end();
    bool isOpenGLReady()
    void swapBuffers()
    void setIMEKeyboardState(bool open)
    bool windowShouldClose()
    void pollEvents()
    @unpack Size getFrameSize()
    void setFrameSize(float width, float height)
    void setFrameZoomFactor(float zoomFactor) 
    float getFrameZoomFactor()
    void setCursorVisible(bool isVisible)
    int getRetinaFactor()
    bool setContentScaleFactor(float scaleFactor)
    float getContentScaleFactor()
    bool isRetinaDisplay()
    @unpack Size getVisibleSize()
    @unpack Vec2 getVisibleOrigin()
    @unpack Rect getVisibleRect()
    @unpack Rect getSafeAreaRect()
    void setDesignResolutionSize(float width, float height, ResolutionPolicy resolutionPolicy)
    @unpack const Size&  getDesignResolutionSize() const;
    void setViewPortInPoints(float x , float y , float w , float h)
    void setScissorInPoints(float x , float y , float w , float h)
    bool isScissorEnabled()
    @unpack Rect getScissorRect()
    void setViewName(const std::string& viewname)
    const std::string& getViewName()
    @unpack const Rect& getViewPortRect()
    std::vector<Touch*> getAllTouches()
    float getScaleX()
    float getScaleY()
    ResolutionPolicy getResolutionPolicy()
    void renderScene(Scene* scene, Renderer* renderer)
    void setVR(VRIRenderer* vrrenderer)
    VRIRenderer* getVR()
]])

local cls = class(M)
cls.CPPCLS = "cocos2d::GLViewImpl"
cls.LUACLS = "cc.GLViewImpl"
cls.SUPERCLS = "cc.GLView"
cls.funcs([[
    static GLViewImpl* create(const std::string& viewName);
    static GLViewImpl* createWithRect(const std::string& viewName, Rect size, float frameZoomFactor = 1.0f, bool resizable = false);
    static GLViewImpl* createWithFullScreen(const std::string& viewName);
]])

return M