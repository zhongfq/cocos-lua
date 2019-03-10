local cls = class()
cls.CPPCLS = "cocos2d::Director"
cls.LUACLS = "cc.Director"
cls.SUPERCLS = "cc.Ref"
cls.prop("runningScene", 'Scene *getRunningScene()')
cls.prop('animationInterval', 'float getAnimationInterval()', 'void setAnimationInterval(float interval)')
cls.prop('displayStats', 'bool isDisplayStats()', 'void setDisplayStats(bool displayStats)')
cls.prop('secondsPerFrame', 'float getSecondsPerFrame()')
cls.prop('openGLView', 'GLView* getOpenGLView()', 'void setOpenGLView(GLView *openGLView)')
cls.prop('textureCache', 'TextureCache* getTextureCache()')
cls.prop('nextDeltaTimeZero', 'bool isNextDeltaTimeZero()', 'void setNextDeltaTimeZero(bool nextDeltaTimeZero)')
cls.prop('paused', 'bool isPaused()')
cls.prop('totalFrames', 'unsigned int getTotalFrames()')
cls.prop('projection', 'Projection getProjection()', 'void setProjection(Projection projection)')
cls.prop('sendCleanupToScene', 'bool isSendCleanupToScene()')
cls.prop('notificationNode', 'Node* getNotificationNode()', 'void setNotificationNode(Node *node)')
cls.prop('eventDispatcher', 'EventDispatcher* getEventDispatcher()', 'void setEventDispatcher(EventDispatcher* dispatcher)')
cls.funcs([[
    static Director *getInstance()
    void setViewport()
    @unpack Vec2 convertToGL(@pack const Vec2& point)
    @unpack Vec2 convertToUI(@pack const Vec2& point)
    @unpack const Size& getWinSize()
    @unpack Size getWinSizeInPixels()
    EventDispatcher* getEventDispatcher()
    void setEventDispatcher(EventDispatcher* dispatcher)
]])
return cls