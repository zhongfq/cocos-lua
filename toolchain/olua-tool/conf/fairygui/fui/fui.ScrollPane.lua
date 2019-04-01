local cls = class()
cls.CPPCLS = "fairygui::ScrollPane"
cls.LUACLS = "fui.ScrollPane"
cls.SUPERCLS = "cc.Ref"
cls.funcs [[
    GComponent* getOwner()
    GComponent* getHeader()
    GComponent* getFooter()
    GScrollBar* getVtScrollBar()
    GScrollBar* getHzScrollBar()
    bool isBouncebackEffect()
    void setBouncebackEffect(bool value)
    bool isTouchEffect()
    void setTouchEffect(bool value)
    bool isInertiaDisabled()
    void setInertiaDisabled(bool value)
    float getScrollStep()
    void setScrollStep(float value)
    bool isSnapToItem()
    void setSnapToItem(bool value)
    bool isPageMode()
    void setPageMode(bool value)
    GController* getPageController()
    void setPageController(GController* value)
    bool isMouseWheelEnabled()
    void setMouseWheelEnabled(bool value)
    float getDecelerationRate()
    void setDecelerationRate(float value)
    float getPosX()
    void setPosX(float value, bool ani = false)
    float getPosY()
    void setPosY(float value, bool ani = false)
    float getPercX()
    void setPercX(float value, bool ani = false)
    float getPercY()
    void setPercY(float value, bool ani = false)
    bool isBottomMost()
    bool isRightMost()
    void scrollLeft(float ratio = 1, bool ani = false)
    void scrollRight(float ratio = 1, bool ani = false)
    void scrollUp(float ratio = 1, bool ani = false)
    void scrollDown(float ratio = 1, bool ani = false)
    void scrollTop(bool ani = false)
    void scrollBottom(bool ani = false)
    void scrollToView(GObject* obj, bool ani = false, bool setFirst = false)
    void scrollToView(const cocos2d::Rect& rect, bool ani = false, bool setFirst = false)
    bool isChildInView(GObject* obj)
    int getPageX()
    void setPageX(int value, bool ani = false)
    int getPageY()
    void setPageY(int value, bool ani = false)
    float getScrollingPosX()
    float getScrollingPosY()
    const cocos2d::Size& getContentSize()
    const cocos2d::Size& getViewSize()
    void lockHeader(int size)
    void lockFooter(int size)
    void cancelDragging()
    static ScrollPane* getDraggingPane()
]]
cls.props [[
    owner
    header
    footer
    vtScrollBar
    hzScrollBar
    bouncebackEffect
    touchEffect
    inertiaDisabled
    scrollStep
    snapToItem
    pageMode
    pageController
    mouseWheelEnabled
    decelerationRate
    posX
    posY
    percX
    percY
    bottomMost
    rightMost
    pageX
    pageY
    scrollingPosX
    scrollingPosY
    contentSize
    viewSize
    draggingPane
]]

return cls