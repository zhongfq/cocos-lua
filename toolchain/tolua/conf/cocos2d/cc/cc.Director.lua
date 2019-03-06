local cls = class()
cls.CPPCLS = "cocos2d::Director"
cls.LUACLS = "cc.Director"
cls.SUPERCLS = "cc.Ref"
cls.func(nil, "static Director *getInstance()")
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
cls.func(nil, 'void setViewport()')
return cls