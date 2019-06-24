local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::PageView::EventType"
cls.LUACLS = "ccui.PageView.EventType"
cls.enums [[
    TURNING
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::PageView::TouchDirection"
cls.LUACLS = "ccui.PageView.TouchDirection"
cls.enums [[
    LEFT
    RIGHT
    UP
    DOWN
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::PageView"
cls.LUACLS = "ccui.PageView"
cls.SUPERCLS = "ccui.ListView"
cls.funcs [[
    static PageView* create()

    void addPage(@ref(map children) Widget* page)
    void insertPage(@ref(map children) Widget* page, int idx)
    void removePage(@unref(map children) Widget* page)
    @unref(cmp children) void removePageAtIndex(ssize_t index)
    @unref(all children) void removeAllPages()

    void scrollToPage(ssize_t idx)
    void scrollToPage(ssize_t idx, float time)
    void scrollToItem(ssize_t itemIndex)
    void scrollToItem(ssize_t idx, float time)
    ssize_t getCurrentPageIndex()
    void setCurrentPageIndex(ssize_t index)
    void setIndicatorEnabled(bool enabled)
    bool getIndicatorEnabled()
    void setIndicatorPositionAsAnchorPoint(const Vec2& positionAsAnchorPoint)
    const Vec2& getIndicatorPositionAsAnchorPoint()
    void setIndicatorPosition(const Vec2& position)
    const Vec2& getIndicatorPosition()
    void setIndicatorSpaceBetweenIndexNodes(float spaceBetweenIndexNodes)
    float getIndicatorSpaceBetweenIndexNodes()
    void setIndicatorSelectedIndexColor(const Color3B& color)
    const Color3B& getIndicatorSelectedIndexColor()
    void setIndicatorIndexNodesColor(const Color3B& color)
    const Color3B& getIndicatorIndexNodesColor()
    void setIndicatorSelectedIndexOpacity(GLubyte opacity)
    GLubyte getIndicatorSelectedIndexOpacity()
    void setIndicatorIndexNodesOpacity(GLubyte opacity)
    GLubyte getIndicatorIndexNodesOpacity()
    void setIndicatorIndexNodesScale(float indexNodesScale)
    void setIndicatorIndexNodesTexture(const std::string& texName,Widget::TextureResType texType = Widget::TextureResType::LOCAL)
    float getIndicatorIndexNodesScale()
    void setAutoScrollStopEpsilon(float epsilon)
]]

cls.callback(
    'void addEventListener(@nullable const std::function<void(Ref*, PageView::EventType)>& callback)',
    {
        CALLBACK_MAKER = 'olua_makecallbacktag("PageViewCallback")',
        CALLBACK_REPLACE = true,
        CALLBACK_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
    }
)
cls.alias('addEventListener', 'addPageViewEventListener')

cls.props [[
    currentPageIndex
    indicatorEnabled
    indicatorPositionAsAnchorPoint
    indicatorPosition
    indicatorSpaceBetweenIndexNodes
    indicatorSelectedIndexColor
    indicatorIndexNodesColor
    indicatorSelectedIndexOpacity
    indicatorIndexNodesOpacity
    indicatorIndexNodesScale
]]

return M