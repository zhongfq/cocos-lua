local cls = class()
cls.CPPCLS = "fairygui::GComponent"
cls.LUACLS = "fui.GComponent"
cls.SUPERCLS = "fui.GObject"
cls.funcs [[
    static GComponent* create()

    GObject* addChild(@ref(map children) GObject* child)
    GObject* addChildAt(@ref(map children) GObject* child, int index)
    void removeChild(@unref(map children) GObject * child)
    @unref(cmp children) void removeChildAt(int index)
    @unref(cmp children) void removeChildren()
    @unref(cmp children) void removeChildren(int beginIndex, int endIndex)
    @ref(map children) GObject * getChildAt(int index)
    @ref(map children) GObject * getChild(const std::string& name)
    @ref(map children) GObject * getChildInGroup(const GGroup * group, const std::string& name)
    @ref(map children) GObject * getChildById(const std::string& id)
    @ref(map children) const cocos2d::Vector<GObject*>& getChildren()

    int getChildIndex(const GObject* child)
    void setChildIndex(GObject* child, int index)
    int setChildIndexBefore(GObject* child, int index)
    void swapChildren(GObject* child1, GObject* child2)
    void swapChildrenAt(int index1, int index2)
    int numChildren()
    bool isAncestorOf(const GObject* obj)
    bool isChildInView(GObject* child)
    int getFirstChildInView()

    void addController(@ref(map controllers) GController* c)
    @ref(map controllers) GController* getControllerAt(int index)
    @ref(map controllers) GController* getController(const std::string& name)
    @ref(map controllers) const cocos2d::Vector<GController*>& getControllers()
    void removeController(@unref(map controllers) GController* c)
    void applyController(GController* c)
    void applyAllControllers()

    @ref(map transitions) Transition* getTransition(const std::string& name)
    @ref(map transitions) Transition* getTransitionAt(int index)
    @ref(map transitions) const cocos2d::Vector<Transition*>& getTransitions()

    bool getOpaque()
    void setOpaque(bool value)
    const Margin& getMargin()
    void setMargin(const Margin& value)
    ChildrenRenderOrder getChildrenRenderOrder()
    void setChildrenRenderOrder(ChildrenRenderOrder value)
    int getApexIndex()
    void setApexIndex(int value)

    @ref(single mask) cocos2d::Node* getMask()
    void setMask(@ref(single mask) cocos2d::Node* value, bool inverted = false)

    IHitTest* getHitArea()
    void setHitArea(IHitTest* value)
    ScrollPane* getScrollPane()
    float getViewWidth()
    void setViewWidth(float value)
    float getViewHeight()
    void setViewHeight(float value)
    void setBoundsChangedFlag()
    void ensureBoundsCorrect()
    cocos2d::Vec2 getSnappingPosition(const cocos2d::Vec2& pt)
]]
cls.props [[
    children
    firstChildInView
    controllers
    transitions
    opaque
    margin
    childrenRenderOrder
    apexIndex
    mask
    hitArea
    scrollPane
    viewWidth
    viewHeight
]]
cls.prop('numChildren', 'int numChildren()')

-- api check
cls.inject('addChildAt', {
    BEFORE = format_snippet [[
        if (!(arg2 >= 0 && arg2 <= self->numChildren())) {
            luaL_error(L, "index out of range");
        }
    ]]
})
cls.inject('removeChildren', {
    BEFORE = format_snippet [[
        if (lua_gettop(L) == 3) {
            int arg1 = (int)olua_checkinteger(L, 2);
            int arg2 = (int)olua_checkinteger(L, 3);
            if (!(arg1 >= 0 && arg1 < self->numChildren())) {
                luaL_error(L, "beginIndex index out of range");
            }
            if (!(arg2 == -1 || (arg2 >= 0 && arg2 < self->numChildren()))) {
                luaL_error(L, "endIndex index out of range");
            }
        }
    ]]
})
cls.inject('removeChildAt', {
    BEFORE = format_snippet [[
        if (!(arg1 >= 0 && arg1 < self->numChildren())) {
            luaL_error(L, "index out of range");
        }
    ]]
})
cls.inject('getChildAt', {
    BEFORE = format_snippet [[
        if (!(arg1 >= 0 && arg1 < self->numChildren())) {
            luaL_error(L, "index out of range");
        }
    ]]
})

cls.inject('getTransitionAt', {
    BEFORE = [[
        if (!(arg1 >= 0 && arg1 < self->getTransitions().size())) {
            luaL_error(L, "index out of range");
        }
    ]]
})
cls.inject('getControllerAt', {
     BEFORE = [[
        if (!(arg1 >= 0 && arg1 < self->getControllers().size())) {
            luaL_error(L, "index out of range");
        }
    ]]
})

return cls