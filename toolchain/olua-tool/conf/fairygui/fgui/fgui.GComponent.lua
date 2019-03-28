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

return cls