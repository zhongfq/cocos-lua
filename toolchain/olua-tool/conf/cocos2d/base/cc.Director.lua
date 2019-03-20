local M = {}
local cls = class(M)
cls.CPPCLS = "cocos2d::MATRIX_STACK_TYPE"
cls.LUACLS = "cc.MATRIX_STACK_TYPE"
cls.enum('MATRIX_STACK_MODELVIEW')
cls.enum('MATRIX_STACK_PROJECTION')
cls.enum('MATRIX_STACK_TEXTURE')

local cls = class(M)
cls.CPPCLS = "cocos2d::Director"
cls.LUACLS = "cc.Director"
cls.SUPERCLS = "cc.Ref"
cls.funcs([[
    static Director *getInstance()
    Scene* getRunningScene()
    float getAnimationInterval()
    void setAnimationInterval(float interval)
    bool isDisplayStats()
    void setDisplayStats(bool displayStats)
    float getSecondsPerFrame()
    GLView* getOpenGLView()
    void setOpenGLView(GLView *openGLView)
    @ref(single textureCache) TextureCache* getTextureCache()
    bool isNextDeltaTimeZero()
    void setNextDeltaTimeZero(bool nextDeltaTimeZero)
    bool isPaused()
    unsigned int getTotalFrames()
    Projection getProjection()
    void setProjection(Projection projection)
    void setViewport()
    bool isSendCleanupToScene()
    @ref(single notificationNode) Node* getNotificationNode()
    void setNotificationNode(@ref(single notificationNode) Node *node)
    const Size& getWinSize()
    Size getWinSizeInPixels()
    Size getVisibleSize()
    Vec2 getVisibleOrigin()
    Rect getSafeAreaRect()
    Vec2 convertToGL(@pack const Vec2& point)
    Vec2 convertToUI(@pack const Vec2& point)
    float getZEye()
    void runWithScene(Scene *scene)
    void pushScene(Scene *scene)
    void popScene()
    void popToRootScene()
    void popToSceneStackLevel(int level)
    void replaceScene(Scene *scene)
    void end()
    void pause()
    void resume()
    void restart()
    void stopAnimation()
    void startAnimation()
    void drawScene()
    void purgeCachedData()
    void setDefaultValues()
    void setGLDefaultValues()
    void setAlphaBlending(bool on)
    void setClearColor(const Color4F& clearColor)
    void setDepthTest(bool on);
    void mainLoop()
    void mainLoop(float dt)
    void setContentScaleFactor(float scaleFactor)
    float getContentScaleFactor()
    @ref(single scheduler) Scheduler* getScheduler()
    void setScheduler(@ref(single scheduler) Scheduler* scheduler)
    @ref(single actionManager) ActionManager* getActionManager()
    void setActionManager(@ref(single actionManager) ActionManager* actionManager)
    @ref(single eventDispatcher) EventDispatcher* getEventDispatcher()
    void setEventDispatcher(@ref(single eventDispatcher) EventDispatcher* dispatcher)
    @ref(single renderer) Renderer* getRenderer()
    float getDeltaTime()
    float getFrameRate()
    void pushMatrix(MATRIX_STACK_TYPE type)
    void pushProjectionMatrix(size_t index)
    void popMatrix(MATRIX_STACK_TYPE type)
    void popProjectionMatrix(size_t index)
    void loadIdentityMatrix(MATRIX_STACK_TYPE type)
    void loadProjectionIdentityMatrix(size_t index)
    void loadMatrix(MATRIX_STACK_TYPE type, const Mat4& mat)
    void loadProjectionMatrix(const Mat4& mat, size_t index)
    void multiplyMatrix(MATRIX_STACK_TYPE type, const Mat4& mat)
    void multiplyProjectionMatrix(const Mat4& mat, size_t index)
    const Mat4& getMatrix(MATRIX_STACK_TYPE type)
    const Mat4& getProjectionMatrix(size_t index)
    void resetMatrixStack()
    void initProjectionMatrixStack(size_t stackCount)
    size_t getProjectionMatrixStackSize()
    bool isValid()
]])
cls.props [[
    instance
    runningScene
    animationInterval
    displayStats
    secondsPerFrame
    openGLView
    textureCache
    nextDeltaTimeZero
    paused
    totalFrames
    projection
    sendCleanupToScene
    notificationNode
    zEye
    contentScaleFactor
    scheduler
    actionManager
    renderer
    eventDispatcher
    deltaTime
    frameRate
    valid
]]
return M
