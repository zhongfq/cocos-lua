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
    void addPage(Widget* page)
    void insertPage(Widget* page, int idx)
    void removePage(Widget* page)
    void removePageAtIndex(ssize_t index)
    void removeAllPages()
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

-- ref
-- void addPage(Widget* page)
-- void insertPage(Widget* page, int idx)
-- void removePage(Widget* page)
-- void removePageAtIndex(ssize_t index)
-- void removeAllPages()
local REFNAME = 'pages'
cls.inject('addPage',           mapref_arg_value(REFNAME))
cls.inject('insertPage',        mapref_arg_value(REFNAME))
cls.inject('removePage',        mapunref_arg_value(REFNAME))
cls.inject('removePageAtIndex', mapunef_by_compare(REFNAME))
cls.inject('removeAllPages',    mapunref_all(REFNAME))

return M