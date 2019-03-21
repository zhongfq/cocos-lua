local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::ListView::Gravity"
cls.LUACLS = "ccui.ListView.Gravity"
cls.enums [[
    LEFT
    RIGHT
    CENTER_HORIZONTAL
    TOP
    BOTTOM
    CENTER_VERTICAL
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::ListView::EventType"
cls.LUACLS = "ccui.ListView.EventType"
cls.enums [[
    ON_SELECTED_ITEM_START
    ON_SELECTED_ITEM_END
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::ListView::MagneticType"
cls.LUACLS = "ccui.ListView.MagneticType"
cls.enums [[
    NONE
    CENTER
    BOTH_END
    LEFT
    RIGHT
    TOP
    BOTTOM
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::ListView"
cls.LUACLS = "ccui.ListView"
cls.SUPERCLS = "ccui.ScrollView"
cls.funcs [[
    static ListView* create()
    void setItemModel(Widget* model)
    void pushBackDefaultItem()
    void insertDefaultItem(ssize_t index)
    void pushBackCustomItem(Widget* item)
    void insertCustomItem(Widget* item, ssize_t index)
    void removeLastItem()
    void removeItem(ssize_t index)
    void removeAllItems()
    Widget* getItem(ssize_t index)
    Vector<Widget*>& getItems()
    ssize_t getIndex(Widget* item)
    void setGravity(Gravity gravity)
    void setMagneticType(MagneticType magneticType)
    MagneticType getMagneticType()
    void setMagneticAllowedOutOfBoundary(bool magneticAllowedOutOfBoundary)
    bool getMagneticAllowedOutOfBoundary()
    void setItemsMargin(float margin)
    float getItemsMargin()
    void setPadding(float l, float t, float r, float b)
    void setLeftPadding(float l)
    void setTopPadding(float t)
    void setRightPadding(float r)
    void setBottomPadding(float b)
    float getLeftPadding()
    float getTopPadding()
    float getRightPadding()
    float getBottomPadding()
    void  setScrollDuration(float time)
    float getScrollDuration()
    Widget* getClosestItemToPosition(const Vec2& targetPosition, const Vec2& itemAnchorPoint)
    Widget* getClosestItemToPositionInCurrentView(const Vec2& positionRatioInView, const Vec2& itemAnchorPoint)
    Widget* getCenterItemInCurrentView()
    Widget* getLeftmostItemInCurrentView()
    Widget* getRightmostItemInCurrentView()
    Widget* getTopmostItemInCurrentView()
    Widget* getBottommostItemInCurrentView()
    void jumpToItem(ssize_t itemIndex, const Vec2& positionRatioInView, const Vec2& itemAnchorPoint)
    void scrollToItem(ssize_t itemIndex, const Vec2& positionRatioInView, const Vec2& itemAnchorPoint)
    void scrollToItem(ssize_t itemIndex, const Vec2& positionRatioInView, const Vec2& itemAnchorPoint, float timeInSec)
    ssize_t getCurSelectedIndex()
    void setCurSelectedIndex(int itemIndex)
]]

cls.callback('addEventListener', {
    CALLBACK_MAKER = 'olua_makecallbacktag("ListViewCallback")',
    CALLBACK_REPLACE = true,
    CALLBACK_MODE = 'OLUA_CALLBACK_TAG_ENDWITH',
}, 'void addEventListener(@nullable const std::function<void(Ref*, EventType)>& callback)')

return M