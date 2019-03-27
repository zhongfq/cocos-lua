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
    void setPositionNormalized(Vec2 &position)
    const Vec2& getPosition()
    const Vec2& getPositionNormalized()
    void setPosition(float x, float y)
    void  setPositionX(float x)
    float getPositionX(void)
    void  setPositionY(float y)
    float getPositionY(void)
    void setPosition3D(Vec3& position)
    Vec3 getPosition3D()
    void setPositionZ(float positionZ)
    float getPositionZ()
    void setSkewX(float skewX)
    float getSkewX()
    void setSkewY(float skewY)
    float getSkewY()
    void setAnchorPoint(Vec2& anchorPoint)
    const Vec2& getAnchorPoint()
    const Vec2& getAnchorPointInPoints()
    void setContentSize(Size& contentSize)
    const Size& getContentSize()
    void setVisible(bool visible)
    bool isVisible()
    void setRotation(float rotation)
    float getRotation()
    void setRotation3D(Vec3& rotation)
    Vec3 getRotation3D()
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
    Rect getBoundingBox()
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
    Vec2 convertToNodeSpace(@pack Vec2& worldPoint)
    Vec2 convertToWorldSpace(@pack Vec2& nodePoint)
    Vec2 convertToNodeSpaceAR(@pack Vec2& worldPoint)
    Vec2 convertToWorldSpaceAR(@pack Vec2& nodePoint)
    Vec2 convertTouchToNodeSpace(Touch * touch)
    Vec2 convertTouchToNodeSpaceAR(Touch * touch)
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

cls.callbacks [[
    void setOnEnterCallback(@nullable const std::function<void()>& callback)
    const std::function<void()>& getOnEnterCallback()
    void setOnExitCallback(@nullable const std::function<void()>& callback)
    const std::function<void()>& getOnExitCallback()
    void setonEnterTransitionDidFinishCallback(@nullable const std::function<void()>& callback)
    const std::function<void()>& getonEnterTransitionDidFinishCallback()
    void setonExitTransitionDidStartCallback(@nullable const std::function<void()>& callback)
    const std::function<void()>& getonExitTransitionDidStartCallback()
]]

cls.alias('setonEnterTransitionDidFinishCallback', 'setOnEnterTransitionDidFinishCallback')
cls.alias('getonEnterTransitionDidFinishCallback', 'getOnEnterTransitionDidFinishCallback')
cls.alias('setonExitTransitionDidStartCallback', 'setOnExitTransitionDidStartCallback')
cls.alias('getonExitTransitionDidStartCallback', 'getOnExitTransitionDidStartCallback')

cls.callback(
    'void scheduleOnce(const std::function<void(float)>& callback, float delay, const std::string &key)',
    {
        CALLBACK_MAKER = "makeScheduleCallbackTag(#-1)",
        CALLBACK_REPLACE = true,
        CALLBACK_CALLONCE = true,
        CALLBACK_MODE = "OLUA_CALLBACK_TAG_EQUAL",
    }
)
cls.callback(
    'void schedule(const std::function<void(float)>& callback, const std::string &key)',
    'void schedule(const std::function<void(float)>& callback, float interval, const std::string &key)',
    'void schedule(const std::function<void(float)>& callback, float interval, unsigned int repeat, float delay, const std::string &key)',
    {
        CALLBACK_MAKER = "makeScheduleCallbackTag(#-1)",
        CALLBACK_REPLACE = true,
    }
)
cls.callback(
    'void unschedule(const std::string &key)', 
    {
        CALLBACK_MAKER = "makeScheduleCallbackTag(#1)",
        CALLBACK_MODE = "OLUA_CALLBACK_TAG_ENDWITH",
        CALLBACK_REMOVE = true,
    }
)
cls.callback(
    'void unscheduleAllCallbacks()',
    {
        CALLBACK_MAKER = "makeScheduleCallbackTag()",
        CALLBACK_MODE = "OLUA_CALLBACK_TAG_WILDCARD",
        CALLBACK_REMOVE = true,
    }
)
cls.props [[
    attachedNodeCount
    description
    localZOrder
    globalZOrder
    scaleX
    scaleY
    scaleZ
    scale
    skewX
    skewY
    visible
    rotation
    rotationSkewX
    rotationSkewY
    ignoreAnchorPointForPosition
    children
    childrenCount
    parent
    tag
    name
    userData
    userObject
    glProgram
    glProgramState
    running
    scene
    eventDispatcher
    actionManager
    numberOfRunningActions
    scheduler
    opacity
    displayedOpacity
    cascadeOpacityEnabled
    color
    displayedColor
    cascadeColorEnabled
    opacityModifyRGB
    onEnterCallback
    onExitCallback
    onEnterTransitionDidFinishCallback
    onExitTransitionDidStartCallback
]]
cls.prop('x', 'float getPositionX()', 'void setPositionX(float x)')
cls.prop('y', 'float getPositionY()', 'void setPositionY(float y)')
cls.prop('z', 'float getPositionZ()', 'void setPositionZ(float z)')
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
cls.prop('height', [[
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

--
-- ref
--
local REMOVE_FROM_PARENT = {
    BEFORE = [[
        cocos2d::Node *parent = self->getParent();
        if (olua_getobj(L, parent)) {
            olua_mapunref(L, -1, "children", 1);
            lua_pop(L, 1);
        }
    ]]
}
local REMOVE_BY_NAME = {
    BEFORE = [[
        cocos2d::Node *child = self->getChildByName(arg1);
        if (olua_getobj(L, child)) {
            olua_mapunref(L, 1, "children", -1);
            lua_pop(L, 1);
        }
    ]]
}
local REMOVE_BY_TAG = {
    BEFORE = [[
        cocos2d::Node *child = self->getChildByTag((int)arg1);
        if (olua_getobj(L, child)) {
            olua_mapunref(L, 1, "children", -1);
            lua_pop(L, 1);
        }
    ]]
}
-- void addChild(Node * child)
-- void addChild(Node * child, int localZOrder)
-- void addChild(Node* child, int localZOrder, int tag)
-- void addChild(Node* child, int localZOrder, const std::string &name)
-- Node *getChildByName(const std::string& name)
-- Node *getChildByTag(int tag) const
-- void removeFromParent()
-- void removeFromParentAndCleanup(bool cleanup)
-- void removeChildByName(const std::string &name, bool cleanup = true)
-- void removeChildByTag(int tag, bool cleanup = true)
-- void removeChild(Node* child, bool cleanup = true)
-- void removeAllChildren()
-- void removeAllChildrenWithCleanup(bool cleanup)
cls.inject('addChild',                      mapref_arg_value('children'))
cls.inject('getChildByName',                mapref_return_value('children'))
cls.inject('getChildByTag',                 mapref_return_value('children'))
cls.inject('removeFromParent',              REMOVE_FROM_PARENT)
cls.inject('removeFromParentAndCleanup',    REMOVE_FROM_PARENT)
cls.inject('removeChildByName',             REMOVE_BY_NAME)
cls.inject('removeChildByTag',              REMOVE_BY_TAG)
cls.inject('removeChild',                   mapunref_arg_value('children'))
cls.inject('removeAllChildren',             mapunref_all('children'))
cls.inject('removeAllChildrenWithCleanup',  mapunref_all('children'))

-- Action* runAction(Action* action)
-- void stopAllActions()
-- void stopAction(Action* action)
-- void stopActionByTag(int tag)
-- void stopAllActionsByTag(int tag)
-- void stopActionsByFlags(unsigned int flags)
-- Action* getActionByTag(int tag)
cls.inject("runAction",             mapref_arg_value_and_mapunef_by_compare('actions'))
cls.inject("stopAllActions",        mapunef_by_compare('actions'))
cls.inject("stopAction",            mapunef_by_compare('actions'))
cls.inject("stopActionByTag",       mapunef_by_compare('actions'))
cls.inject("stopAllActionsByTag",   mapunef_by_compare('actions'))
cls.inject("stopActionsByFlags",    mapunef_by_compare('actions'))
cls.inject("getActionByTag",        mapref_return_value('actions'))

-- Component* getComponent(const std::string& name)
-- bool addComponent(Component *component)
-- bool removeComponent(const std::string& name)
-- bool removeComponent(Component *component)
-- void removeAllComponents()
cls.inject("getComponent",          mapref_return_value('components'))
cls.inject("addComponent",          mapref_arg_value('components'))
cls.inject("removeComponent",       mapunef_by_compare('components'))
cls.inject("removeAllComponents",   mapunref_all('components'))

return cls
