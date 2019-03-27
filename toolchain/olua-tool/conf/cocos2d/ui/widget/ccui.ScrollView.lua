local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::ScrollView::Direction"
cls.LUACLS = "ccui.ScrollView.Direction"
cls.enums [[
    NONE
    VERTICAL
    HORIZONTAL
    BOTH
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::ScrollView::EventType"
cls.LUACLS = "ccui.ScrollView.EventType"
cls.enums [[
    SCROLL_TO_TOP
    SCROLL_TO_BOTTOM
    SCROLL_TO_LEFT
    SCROLL_TO_RIGHT
    SCROLLING
    BOUNCE_TOP
    BOUNCE_BOTTOM
    BOUNCE_LEFT
    BOUNCE_RIGHT
    CONTAINER_MOVED
    SCROLLING_BEGAN
    SCROLLING_ENDED
    AUTOSCROLL_ENDED
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::ScrollView"
cls.LUACLS = "ccui.ScrollView"
cls.SUPERCLS = "ccui.Layout"
cls.funcs [[
    static ScrollView* create()
    void setDirection(Direction dir)
    Direction getDirection()
    Layout* getInnerContainer()
    void stopScroll()
    void stopAutoScroll()
    void stopOverallScroll()
    void scrollToBottom(float timeInSec, bool attenuated)
    void scrollToTop(float timeInSec, bool attenuated)
    void scrollToLeft(float timeInSec, bool attenuated)
    void scrollToRight(float timeInSec, bool attenuated)
    void scrollToTopLeft(float timeInSec, bool attenuated)
    void scrollToTopRight(float timeInSec, bool attenuated)
    void scrollToBottomLeft(float timeInSec, bool attenuated)
    void scrollToBottomRight(float timeInSec, bool attenuated)
    void scrollToPercentVertical(float percent, float timeInSec, bool attenuated)
    void scrollToPercentHorizontal(float percent, float timeInSec, bool attenuated)
    void scrollToPercentBothDirection(const Vec2& percent, float timeInSec, bool attenuated)
    float getScrolledPercentVertical()
    float getScrolledPercentHorizontal()
    Vec2 getScrolledPercentBothDirection()
    void jumpToBottom()
    void jumpToTop()
    void jumpToLeft()
    void jumpToRight()
    void jumpToTopLeft()
    void jumpToTopRight()
    void jumpToBottomLeft()
    void jumpToBottomRight()
    void jumpToPercentVertical(float percent)
    void jumpToPercentHorizontal(float percent)
    void jumpToPercentBothDirection(const Vec2& percent)
    void setInnerContainerSize(const Size &size)
    const Size& getInnerContainerSize()
    void setInnerContainerPosition(const Vec2 &pos)
    const Vec2& getInnerContainerPosition()
    Vector<Node*>& getChildren()
    void setBounceEnabled(bool enabled)
    bool isBounceEnabled()
    void setInertiaScrollEnabled(bool enabled)
    bool isInertiaScrollEnabled()
    void setScrollBarEnabled(bool enabled)
    bool isScrollBarEnabled()
    void setScrollBarPositionFromCorner(const Vec2& positionFromCorner)
    void setScrollBarPositionFromCornerForVertical(const Vec2& positionFromCorner)
    Vec2 getScrollBarPositionFromCornerForVertical()
    void setScrollBarPositionFromCornerForHorizontal(const Vec2& positionFromCorner)
    Vec2 getScrollBarPositionFromCornerForHorizontal()
    void setScrollBarWidth(float width)
    float getScrollBarWidth()
    void setScrollBarColor(const Color3B& color)
    const Color3B& getScrollBarColor()
    void setScrollBarOpacity(GLubyte opacity)
    GLubyte getScrollBarOpacity()
    void setScrollBarAutoHideEnabled(bool autoHideEnabled)
    bool isScrollBarAutoHideEnabled()
    void setScrollBarAutoHideTime(float autoHideTime)
    float getScrollBarAutoHideTime()
    void setTouchTotalTimeThreshold(float touchTotalTimeThreshold)
    float getTouchTotalTimeThreshold()
    bool isScrolling()
    bool isAutoScrolling()
]]

cls.callback('addEventListener',
    'void addEventListener(@nullable const std::function<void(Ref*, EventType)>& callback)',
    {
        CALLBACK_MAKER = 'olua_makecallbacktag("ScrollCallback")',
        CALLBACK_REPLACE = true,
        CALLBACK_MODE = 'OLUA_CALLBACK_TAG_ENDWITH'
    }
)
cls.alias('addEventListener', 'addScrollEventListener')

cls.props [[
    direction
    innerContainer
    scrolledPercentVertical
    scrolledPercentHorizontal
    scrolledPercentBothDirection
    innerContainerSize
    innerContainerPosition
    children
    bounceEnabled
    inertiaScrollEnabled
    scrollBarEnabled
    scrollBarWidth
    scrollBarColor
    scrollBarOpacity
    scrollBarAutoHideEnabled
    scrollBarAutoHideTime
    touchTotalTimeThreshold
    scrolling
    autoScrolling
]]

return M