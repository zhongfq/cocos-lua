local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::Widget::FocusDirection"
cls.LUACLS = "ccui.Widget.FocusDirection"
cls.enums [[
    LEFT
    RIGHT
    UP
    DOWN
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::Widget::PositionType"
cls.LUACLS = "ccui.Widget.PositionType"
cls.enums [[
    ABSOLUTE
    PERCENT
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::Widget::SizeType"
cls.LUACLS = "ccui.Widget.SizeType"
cls.enums [[
    ABSOLUTE
    PERCENT
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::Widget::TouchEventType"
cls.LUACLS = "ccui.Widget.TouchEventType"
cls.enums [[
    BEGAN
    MOVED
    ENDED
    CANCELED
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::Widget::TextureResType"
cls.LUACLS = "ccui.Widget.TextureResType"
cls.enums [[
    LOCAL
    PLIST
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::Widget::BrightStyle"
cls.LUACLS = "ccui.Widget.BrightStyle"
cls.enums [[
    NONE
    NORMAL
    HIGHLIGHT
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::Widget"
cls.LUACLS = "ccui.Widget"
cls.SUPERCLS = "cc.ProtectedNode"
cls.funcs [[
    static Widget* create()
    void setEnabled(bool enabled)
    bool isEnabled()
    void setBright(bool bright)
    bool isBright()
    void setTouchEnabled(bool enabled)
    void setBrightStyle(BrightStyle style)
    bool isTouchEnabled()
    bool isHighlighted()
    void setHighlighted(bool highlight)
    float getLeftBoundary()
    float getBottomBoundary()
    float getRightBoundary()
    float getTopBoundary()
    // void addTouchEventListener(const ccWidgetTouchCallback& callback)
    // void addClickEventListener(const ccWidgetClickCallback& callback)
    // void addCCSEventListener(const ccWidgetEventCallback& callback)
    void setPositionPercent(@pack const Vec2 &percent)
    @unpack const Vec2& getPositionPercent()
    void setPositionType(PositionType type)
    PositionType getPositionType()
    void setFlippedX(bool flippedX)
    bool isFlippedX()
    void setFlippedY(bool flippedY)
    bool isFlippedY()
    bool isClippingParentContainsPoint(@pack const Vec2& pt)
    @unpack const Vec2& getTouchBeganPosition()
    @unpack const Vec2& getTouchMovePosition()
    @unpack const Vec2& getTouchEndPosition()
    void setSizePercent(@pack const Vec2 &percent)
    void setSizeType(SizeType type)
    SizeType getSizeType()
    @unpack const Size& getCustomSize()
    @unpack const Size& getLayoutSize()
    @unpack const Vec2& getSizePercent()
    bool hitTest(const Vec2 &pt, const Camera* camera, @nullable Vec3 *p)
    bool onTouchBegan(Touch *touch, Event *unusedEvent)
    void onTouchMoved(Touch *touch, Event *unusedEvent)
    void onTouchEnded(Touch *touch, Event *unusedEvent)
    void onTouchCancelled(Touch *touch, Event *unusedEvent)
    // void setLayoutParameter(LayoutParameter* parameter)
    // LayoutParameter* getLayoutParameter()
    void ignoreContentAdaptWithSize(bool ignore)
    bool isIgnoreContentAdaptWithSize()
    @unpack Vec2 getWorldPosition()
    Node* getVirtualRenderer()
    @unpack Size getVirtualRendererSize()
    Widget* clone()
    void updateSizeAndPosition()
    void updateSizeAndPosition(@pack const Size& parentSize)
    void setActionTag(int tag)
    int getActionTag()
    void setPropagateTouchEvents(bool isPropagate)
    bool isPropagateTouchEvents()
    void setSwallowTouches(bool swallow)
    bool isSwallowTouches()
    bool isFocused()
    void setFocused(bool focus)
    bool isFocusEnabled()
    void setFocusEnabled(bool enable)
    Widget* findNextFocusedWidget(FocusDirection direction, Widget* current)
    void requestFocus()
    static Widget* getCurrentFocusedWidget()
    static void enableDpadNavigation(bool enable)
    void setUnifySizeEnabled(bool enable)
    bool isUnifySizeEnabled()
    void setCallbackName(const std::string& callbackName)
    const std::string& getCallbackName()
    void setCallbackType(const std::string& callbackType)
    const std::string& getCallbackType()
    void setLayoutComponentEnabled(bool enable)
    bool isLayoutComponentEnabled()
]]
-- cls.vars [[
--     @nullable std::function<void(Widget*,Widget*)> onFocusChanged
--     @nullable std::function<Widget*(FocusDirection)> onNextFocusedWidget
-- ]]

return M