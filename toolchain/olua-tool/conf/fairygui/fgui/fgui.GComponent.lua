local cls = class()
cls.CPPCLS = "fairygui::GComponent"
cls.LUACLS = "fgui.GComponent"
cls.SUPERCLS = "fgui.GObject"
cls.funcs [[
    static GComponent* create()
    GObject* addChild(GObject* child)
    GObject* addChildAt(GObject* child, int index)
    void removeChild(GObject * child)
    void removeChildAt(int index)
    void removeChildren()
    void removeChildren(int beginIndex, int endIndex)
    GObject * getChildAt(int index)
    GObject * getChild(const std::string& name)
    GObject * getChildInGroup(const GGroup * group, const std::string& name)
    GObject * getChildById(const std::string& id)
    const cocos2d::Vector<GObject*>& getChildren()
    int getChildIndex(const GObject* child)
    void setChildIndex(GObject* child, int index)
    int setChildIndexBefore(GObject* child, int index)
    void swapChildren(GObject* child1, GObject* child2)
    void swapChildrenAt(int index1, int index2)
    int numChildren()
    bool isAncestorOf(const GObject* obj)
    bool isChildInView(GObject* child)
    int getFirstChildInView()
    void addController(GController* c)
    GController* getControllerAt(int index)
    GController* getController(const std::string& name)
    const cocos2d::Vector<GController*>& getControllers()
    void removeController(GController* c)
    void applyController(GController* c)
    void applyAllControllers()
    Transition* getTransition(const std::string& name)
    Transition* getTransitionAt(int index)
    const cocos2d::Vector<Transition*>& getTransitions()
    bool getOpaque()
    void setOpaque(bool value)
    const Margin& getMargin()
    void setMargin(const Margin& value)
    ChildrenRenderOrder getChildrenRenderOrder()
    void setChildrenRenderOrder(ChildrenRenderOrder value)
    int getApexIndex()
    void setApexIndex(int value)
    cocos2d::Node* getMask()
    void setMask(cocos2d::Node* value, bool inverted = false)
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

-- ref
local REFNAME = 'children'
-- GObject* addChild(GObject* child)
-- GObject* addChildAt(GObject* child, int index)
-- void removeChild(GObject * child);
-- void removeChildAt(int index);
-- void removeChildren() { removeChildren(0, -1); }
-- void removeChildren(int beginIndex, int endIndex);
-- GObject *getChildAt(int index) const;
-- GObject *getChild(const std::string& name) const;
-- GObject *getChildInGroup(const GGroup * group, const std::string& name) const;
-- GObject *getChildById(const std::string& id) const;
-- const cocos2d::Vector<GObject*>& getChildren() const { return _children; }
local CHECK_RANGE = {
    BEFORE = format_snippet [[
        if (!(arg1 >= 0 && arg1 < self->numChildren())) {
            luaL_error(L, "index out of range");
        }
    ]]
}
local CHECK_ADD_RANGE = {
    BEFORE = format_snippet [[
        if (!(arg2 >= 0 && arg2 <= self->numChildren())) {
            luaL_error(L, "index out of range");
        }
    ]]
}
local REMOVE_BY_INDEX = {
    BEFORE = format_snippet [[
        fairygui::GObject *child = self->getChildAt((int)arg1);
        if (olua_getobj(L, child)) {
            olua_mapunref(L, 1, "${REFNAME}", -1);
            lua_pop(L, 1);
        }
    ]]
}
cls.inject('addChild',      mapref_arg_value(REFNAME))
cls.inject('addChildAt',    mapref_combo(CHECK_ADD_RANGE, mapref_arg_value(REFNAME)))
cls.inject('removeChild',   mapunref_arg_value(REFNAME))
cls.inject('removeChildAt', mapref_combo(CHECK_RANGE, REMOVE_BY_INDEX))

return cls