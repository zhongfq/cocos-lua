local cls = class()
cls.CPPCLS = "cocos2d::Node"
cls.LUACLS = "cc.Node"
cls.SUPERCLS = "cc.Ref"
cls.funcs([[
    static Node * create()
    static int getAttachedNodeCount()
    std::string getDescription()
    void setLocalZOrder(std::int32_t localZOrder)
    void updateOrderOfArrival()
    std::int32_t getLocalZOrder()
    void setGlobalZOrder(float globalZOrder)
    float getGlobalZOrder()
    void setScaleX(float scaleX)
    float getScaleX()
    void setScaleY(float scaleY)
    float getScaleY()
    void setScaleZ(float scaleZ)
    float getScaleZ()
    void setScale(float scale)
    float getScale()
    void setPosition(const Vec2 &position)
    void setPositionNormalized(@pack const Vec2 &position)
    @unpack const Vec2& getPosition()
    @unpack const Vec2& getPositionNormalized()
    void setPosition(float x, float y)
    void  setPositionX(float x)
    float getPositionX(void)
    void  setPositionY(float y)
    float getPositionY(void)
    void setPosition3D(@pack const Vec3& position)
    @unpack Vec3 getPosition3D()
    void setPositionZ(float positionZ)
    float getPositionZ()
    void setSkewX(float skewX)
    float getSkewX()
    void setSkewY(float skewY)
    float getSkewY()
    void setAnchorPoint(@pack const Vec2& anchorPoint)
    @unpack const Vec2& getAnchorPoint()
    @unpack const Vec2& getAnchorPointInPoints()
    void setContentSize(@pack const Size& contentSize)
    @unpack const Size& getContentSize()
    void setVisible(bool visible)
    bool isVisible()
    void setRotation(float rotation)
    float getRotation()
    void setRotation3D(@pack const Vec3& rotation)
    @unpack Vec3 getRotation3D()
    void setRotationQuat(const Quaternion& quat)
    Quaternion getRotationQuat()
    void setRotationSkewX(float rotationX)
    float getRotationSkewX()
    void setRotationSkewY(float rotationY)
    float getRotationSkewY()
    void setIgnoreAnchorPointForPosition(bool ignore)
    bool isIgnoreAnchorPointForPosition()
    void addChild(Node * child)
    void addChild(Node * child, int localZOrder)
    void addChild(Node* child, int localZOrder, int tag)
    void addChild(Node* child, int localZOrder, const std::string &name)
    Node * getChildByTag(int tag)
    Node* getChildByName(const std::string& name)
    const Vector<Node*>& getChildren()
    ssize_t getChildrenCount()
    void setParent(Node* parent)
    Node* getParent()
    void removeFromParent()
    void removeFromParentAndCleanup(bool cleanup)
    void removeChild(Node* child, bool cleanup = true)
    void removeChildByTag(int tag, bool cleanup = true)
    void removeChildByName(const std::string &name, bool cleanup = true)
    void removeAllChildren()
    void removeAllChildrenWithCleanup(bool cleanup)
    void reorderChild(Node * child, int localZOrder)
    void sortAllChildren()
    int getTag()
    void setTag(int tag)
    const std::string& getName()
    void setName(const std::string& name)
    void* getUserData()
    void setUserData(void *userData)
    Ref* getUserObject()
    void setUserObject(Ref *userObject)
    @ref(single glProgram) GLProgram* getGLProgram()
    void setGLProgram(@ref(single glProgram) GLProgram *glprogram)
    @ref(single glProgramState) GLProgramState *getGLProgramState()
    void setGLProgramState(@ref(single glProgramState) GLProgramState *glProgramState)
    bool isRunning()
    void onEnter()
    void onEnterTransitionDidFinish()
    void onExit()
    void onExitTransitionDidStart()
    void cleanup()
    void draw(Renderer *renderer, const Mat4& transform, uint32_t flags)
    void draw()
    void visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags)
    void visit()
    Scene* getScene()
    @unpack Rect getBoundingBox()
    void setEventDispatcher(EventDispatcher* dispatcher)
    EventDispatcher* getEventDispatcher()
    void setActionManager(ActionManager* actionManager)
    ActionManager* getActionManager()
    Action* runAction(Action* action)
    void stopAllActions()
    void stopAction(Action* action)
    void stopActionByTag(int tag)
    void stopAllActionsByTag(int tag)
    void stopActionsByFlags(unsigned int flags)
    Action* getActionByTag(int tag)
    ssize_t getNumberOfRunningActions()
    ssize_t getNumberOfRunningActionsByTag(int tag)
    void setScheduler(Scheduler* scheduler)
    Scheduler* getScheduler()
    bool isScheduled(const std::string &key)
    void scheduleUpdate(void)
    void scheduleUpdateWithPriority(int priority)
    void unscheduleUpdate(void)
    void resume(void)
    void pause(void)
    void update(float delta)
    void updateTransform()
    const Mat4& getNodeToParentTransform()
    AffineTransform getNodeToParentAffineTransform()
    Mat4 getNodeToParentTransform(Node* ancestor)
    AffineTransform getNodeToParentAffineTransform(Node* ancestor)
    void setNodeToParentTransform(const Mat4& transform)
    const Mat4& getParentToNodeTransform()
    AffineTransform getParentToNodeAffineTransform()
    Mat4 getNodeToWorldTransform()
    AffineTransform getNodeToWorldAffineTransform()
    Mat4 getWorldToNodeTransform()
    AffineTransform getWorldToNodeAffineTransform()
    @unpack Vec2 convertToNodeSpace(@pack const Vec2& worldPoint)
    @unpack Vec2 convertToWorldSpace(@pack const Vec2& nodePoint)
    @unpack Vec2 convertToNodeSpaceAR(@pack const Vec2& worldPoint)
    @unpack Vec2 convertToWorldSpaceAR(@pack const Vec2& nodePoint)
    @unapck Vec2 convertTouchToNodeSpace(Touch * touch)
    @unpack Vec2 convertTouchToNodeSpaceAR(Touch * touch)
    void setAdditionalTransform(const Mat4& additionalTransform)
    void setAdditionalTransform(const AffineTransform& additionalTransform)
    Component* getComponent(const std::string& name)
    bool addComponent(Component *component)
    bool removeComponent(const std::string& name)
    bool removeComponent(Component *component)
    void removeAllComponents()
    GLubyte getOpacity()
    GLubyte getDisplayedOpacity()
    void setOpacity(GLubyte opacity)
    void updateDisplayedOpacity(GLubyte parentOpacity)
    bool isCascadeOpacityEnabled()
    void setCascadeOpacityEnabled(bool cascadeOpacityEnabled)
    const Color3B& getColor()
    const Color3B& getDisplayedColor()
    void setColor(const Color3B& color)
    void updateDisplayedColor(const Color3B& parentColor)
    bool isCascadeColorEnabled()
    void setCascadeColorEnabled(bool cascadeColorEnabled)
    void setOpacityModifyRGB(bool value)
    bool isOpacityModifyRGB()
    unsigned short getCameraMask()
    void setCameraMask(unsigned short mask, bool applyChildren = true)
]])

-- void setOnEnterCallback(const std::function<void()>& callback = nullptr)
-- const std::function<void()>& getOnEnterCallback()
cls.callback(nil, {
        CALLBACK_MAKER = 'olua_makecallbacktag("onEnterCallback")',
        CALLBACK_MODE = "OLUA_CALLBACK_TAG_ENDWITH",
        CALLBACK_REPLACE = true,
    },
    'void setOnEnterCallback(const std::function<void()>& callback = nullptr)'
)
cls.callback(nil, {
        CALLBACK_MAKER = 'olua_makecallbacktag("onEnterCallback")',
        CALLBACK_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
    },
    'const std::function<void()>& getOnEnterCallback()'
)

-- void setOnExitCallback(const std::function<void()>& callback = nullptr)
-- const std::function<void()>& getOnExitCallback()
cls.callback(nil, {
        CALLBACK_MAKER = 'olua_makecallbacktag("onExitCallback")',
        CALLBACK_MODE = "OLUA_CALLBACK_TAG_ENDWITH",
        CALLBACK_REPLACE = true,
    },
    'void setOnExitCallback(const std::function<void()>& callback = nullptr)'
)
cls.callback(nil, {
        CALLBACK_MAKER = 'olua_makecallbacktag("onExitCallback")',
        CALLBACK_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
    },
    'const std::function<void()>& getOnExitCallback()'
)

-- void setonEnterTransitionDidFinishCallback(const std::function<void()>& callback)
-- const std::function<void()>& getonEnterTransitionDidFinishCallback()
cls.callback('setOnEnterTransitionDidFinishCallback', {
        CALLBACK_MAKER = 'olua_makecallbacktag("onEnterTransitionDidFinishCallback")',
        CALLBACK_MODE = "OLUA_CALLBACK_TAG_ENDWITH",
        CALLBACK_REPLACE = true,
    },
    'void setonEnterTransitionDidFinishCallback(const std::function<void()>& callback = nullptr)'
)
cls.callback('getOnEnterTransitionDidFinishCallback', {
        CALLBACK_MAKER = 'olua_makecallbacktag("onEnterTransitionDidFinishCallback")',
        CALLBACK_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
    },
    'const std::function<void()>& getonEnterTransitionDidFinishCallback()'
)

-- void setonExitTransitionDidStartCallback(const std::function<void()>& callback)
-- const std::function<void()>& getonExitTransitionDidStartCallback()
cls.callback('setOnExitTransitionDidStartCallback', {
        CALLBACK_MAKER = 'olua_makecallbacktag("onExitTransitionDidStartCallback")',
        CALLBACK_MODE = "OLUA_CALLBACK_TAG_ENDWITH",
        CALLBACK_REPLACE = true,
    },
    'void setonExitTransitionDidStartCallback(const std::function<void()>& callback = nullptr)'
)
cls.callback('getOnExitTransitionDidStartCallback', {
        CALLBACK_MAKER = 'olua_makecallbacktag("onExitTransitionDidStartCallback")',
        CALLBACK_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
    },
    'const std::function<void()>& getonExitTransitionDidStartCallback()'
)

cls.callback(nil, {
        CALLBACK_MAKER = "makeScheduleCallbackTag(#-1)",
        CALLBACK_REPLACE = true,
        CALLBACK_CALLONCE = true,
        CALLBACK_MODE = "OLUA_CALLBACK_TAG_EQUAL",
    },
    'void scheduleOnce(const std::function<void(float)>& callback, float delay, const std::string &key)'
)
cls.callback(nil, {
        CALLBACK_MAKER = "makeScheduleCallbackTag(#-1)",
        CALLBACK_REPLACE = true,
    },
    'void schedule(const std::function<void(float)>& callback, const std::string &key)',
    'void schedule(const std::function<void(float)>& callback, float interval, const std::string &key)',
    'void schedule(const std::function<void(float)>& callback, float interval, unsigned int repeat, float delay, const std::string &key)'
)
cls.callback(nil, {
        CALLBACK_MAKER = "makeScheduleCallbackTag(#1)",
        CALLBACK_MODE = "OLUA_CALLBACK_TAG_ENDWITH",
        CALLBACK_REMOVE = true,
    },
    'void unschedule(const std::string &key)'
)
cls.callback(nil, {
        CALLBACK_MAKER = "makeScheduleCallbackTag()",
        CALLBACK_MODE = "OLUA_CALLBACK_TAG_WILDCARD",
        CALLBACK_REMOVE = true,
    },
    'void unscheduleAllCallbacks()'
)
cls.prop('attachedNodeCount')
cls.prop('description')
cls.prop('localZOrder')
cls.prop('globalZOrder')
cls.prop('scaleX')
cls.prop('scaleY')
cls.prop('scaleZ')
cls.prop('scale')
cls.prop('x', 'float getPositionX()', 'void setPositionX(float x)')
cls.prop('y', 'float getPositionY()', 'void setPositionY(float y)')
cls.prop('z', 'float getPositionZ()', 'void setPositionZ(float z)')
cls.prop('skewX')
cls.prop('skewY')
cls.prop('visible')
cls.prop('rotation')
cls.prop('rotationSkewX')
cls.prop('rotationSkewY')
cls.prop('ignoreAnchorPointForPosition')
cls.prop('children')
cls.prop('childrenCount')
cls.prop('parent')
cls.prop('tag')
cls.prop('name')
cls.prop('userData')
cls.prop('userObject')
cls.prop('glProgram')
cls.prop('glProgramState')
cls.prop('running')
cls.prop('scene')
cls.prop('eventDispatcher')
cls.prop('actionManager')
cls.prop('numberOfRunningActions')
cls.prop('scheduler')
cls.prop('opacity')
cls.prop('displayedOpacity')
cls.prop('cascadeOpacityEnabled')
cls.prop('color')
cls.prop('displayedColor')
cls.prop('cascadeColorEnabled')
cls.prop('opacityModifyRGB')
cls.prop('anchorX', [[
{
    lua_settop(L, 1);
    cocos2d::Node *self = (cocos2d::Node *)olua_toobj(L, 1, "cc.Node");
    lua_pushnumber(L, self->getAnchorPoint().x);
    return 1;
}
]], [[
{
    lua_settop(L, 2);
    cocos2d::Node *self = (cocos2d::Node *)olua_toobj(L, 1, "cc.Node");
    cocos2d::Vec2 anchor = self->getAnchorPoint();
    anchor.x = olua_checknumber(L, 2);
    self->setAnchorPoint(anchor);
    return 0;   
}]])
cls.prop('anchorY', [[
{
    lua_settop(L, 1);
    cocos2d::Node *self = (cocos2d::Node *)olua_toobj(L, 1, "cc.Node");
    lua_pushnumber(L, self->getAnchorPoint().y);
    return 1;
}
]], [[
{
    lua_settop(L, 2);
    cocos2d::Node *self = (cocos2d::Node *)olua_toobj(L, 1, "cc.Node");
    cocos2d::Vec2 anchor = self->getAnchorPoint();
    anchor.y = olua_checknumber(L, 2);
    self->setAnchorPoint(anchor);
    return 0;   
}]])
cls.prop('width', [[
{
    lua_settop(L, 1);
    cocos2d::Node *self = (cocos2d::Node *)olua_toobj(L, 1, "cc.Node");
    lua_pushnumber(L, self->getContentSize().width);
    return 1;
}
]], [[
{
    lua_settop(L, 2);
    cocos2d::Node *self = (cocos2d::Node *)olua_toobj(L, 1, "cc.Node");
    cocos2d::Size size = self->getContentSize();
    size.width = olua_checknumber(L, 2);
    self->setContentSize(size);
    return 0;   
}]])
cls.prop('heigh', [[
{
    lua_settop(L, 1);
    cocos2d::Node *self = (cocos2d::Node *)olua_toobj(L, 1, "cc.Node");
    lua_pushnumber(L, self->getContentSize().height);
    return 1;
}
]], [[
{
    lua_settop(L, 2);
    cocos2d::Node *self = (cocos2d::Node *)olua_toobj(L, 1, "cc.Node");
    cocos2d::Size size = self->getContentSize();
    size.height = olua_checknumber(L, 2);
    self->setContentSize(size);
    return 0;   
}]])
cls.prop('alpha', [[
{
    lua_settop(L, 1);
    cocos2d::Node *self = (cocos2d::Node *)olua_toobj(L, 1, "cc.Node");
    lua_pushnumber(L, self->getOpacity() / 255.0f);
    return 1;
}
]], [[
{
    lua_settop(L, 2);
    cocos2d::Node *self = (cocos2d::Node *)olua_toobj(L, 1, "cc.Node");
    self->setOpacity(olua_checknumber(L, 2) * 255.0f);
    return 0;   
}]])
return cls
