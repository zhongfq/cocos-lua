local cls = class()
cls.CPPCLS = "fairygui::GComponent"
cls.LUACLS = "fui.GComponent"
cls.SUPERCLS = "fui.GObject"
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

-- ref
do
    local REFNAME = 'children'
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
    local UNREF_BY_INDEX = {
        BEFORE = format_snippet [[
            fairygui::GObject *child = self->getChildAt((int)arg1);
            if (olua_getobj(L, child)) {
                olua_mapunref(L, 1, "${REFNAME}", -1);
                lua_pop(L, 1);
            }
        ]]
    }
    local CHECK_REMOVE_CHILDREN_RANGE = {
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
    }
    -- GObject* addChild(GObject* child)
    -- GObject* addChildAt(GObject* child, int index)
    cls.inject('addChild',          mapref_arg_value(REFNAME))
    cls.inject('addChildAt',        CHECK_ADD_RANGE, mapref_arg_value(REFNAME))

    -- void removeChild(GObject * child);
    cls.inject('removeChild',       mapunref_arg_value(REFNAME))

    -- void removeChildAt(int index);
    cls.inject('removeChildAt',     CHECK_RANGE, UNREF_BY_INDEX)

    -- void removeChildren() { removeChildren(0, -1); }
    -- void removeChildren(int beginIndex, int endIndex);
    cls.inject('removeChildren',    CHECK_REMOVE_CHILDREN_RANGE, mapunef_by_compare(REFNAME))

    -- GObject *getChildAt(int index) const;
    cls.inject('getChildAt',        CHECK_RANGE, mapref_return_value(REFNAME))

    -- GObject *getChild(const std::string& name) const;
    -- GObject *getChildInGroup(const GGroup * group, const std::string& name) const;
    -- GObject *getChildById(const std::string& id) const;
    cls.inject('getChild',          mapref_return_value(REFNAME))
    cls.inject('getChildInGroup',   mapref_return_value(REFNAME))
    cls.inject('getChildById',      mapref_return_value(REFNAME))

    -- const cocos2d::Vector<GObject*>& getChildren() const { return _children; }
    cls.inject('getChildren',       mapref_return_value(REFNAME, 1, true))
end

do
    local REFNAME = 'transitions'
    -- Transition* getTransition(const std::string& name)
    -- Transition* getTransitionAt(int index)
    -- const cocos2d::Vector<Transition*>& getTransitions()
    local CHECK_RANGE = {
        BEFORE = format_snippet [[
            if (!(arg1 >= 0 && arg1 < self->getTransitions().size())) {
                luaL_error(L, "index out of range");
            }
        ]]
    }
    cls.inject('getTransition',     mapref_return_value(REFNAME))
    cls.inject('getTransitionAt',   CHECK_RANGE, mapref_return_value(REFNAME))
    cls.inject('getTransitions',    mapref_return_value(REFNAME, 1, true))
end

do
    local REFNAME = 'controllers'
    -- void addController(GController* c)
    -- GController* getControllerAt(int index)
    -- GController* getController(const std::string& name)
    -- const cocos2d::Vector<GController*>& getControllers()
    -- void removeController(GController* c)
    local CHECK_RANGE = {
        BEFORE = format_snippet [[
            if (!(arg1 >= 0 && arg1 < self->getControllers().size())) {
                luaL_error(L, "index out of range");
            }
        ]]
    }
    cls.inject('getControllerAt',   CHECK_RANGE, mapref_return_value(REFNAME))
    cls.inject('getController',     mapref_return_value(REFNAME))
    cls.inject('getControllers',    mapref_return_value(REFNAME, 1, true))
    cls.inject('removeController',  mapunref_arg_value(REFNAME))
end

return cls