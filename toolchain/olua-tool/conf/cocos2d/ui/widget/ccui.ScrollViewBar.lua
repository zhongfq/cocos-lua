local cls = class()
cls.CPPCLS = "cocos2d::ui::ScrollViewBar"
cls.LUACLS = "ccui.ScrollViewBar"
cls.SUPERCLS = "cc.ProtectedNode"
cls.funcs [[
    static ScrollViewBar* create(ScrollView* parent, ScrollView::Direction direction)
    void setPositionFromCorner(const Vec2& positionFromCorner)
    Vec2 getPositionFromCorner()
    void setWidth(float width)
    float getWidth()
    void setAutoHideEnabled(bool autoHideEnabled)
    bool isAutoHideEnabled()
    void setAutoHideTime(float autoHideTime)
    float getAutoHideTime()
    void onScrolled(const Vec2& outOfBoundary)
    void onTouchBegan()
    void onTouchEnded()
]]

cls.props [[
    positionFromCorner
    width
    autoHideEnabled
    autoHideTime
]]

return cls