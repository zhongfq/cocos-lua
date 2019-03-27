local M = {}


local cls = class(M)
cls.CPPCLS = "cocos2d::ui::LayoutComponent::HorizontalEdge"
cls.LUACLS = "ccui.LayoutComponent.HorizontalEdge"
cls.enums [[
    None
    Left
    Right
    Center
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::LayoutComponent::VerticalEdge"
cls.LUACLS = "ccui.LayoutComponent.VerticalEdge"
cls.enums [[
    None
    Bottom
    Top
    Center
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::LayoutComponent"
cls.LUACLS = "ccui.LayoutComponent"
cls.SUPERCLS = "cc.Component"
cls.funcs [[
    static LayoutComponent* create()
    static LayoutComponent* bindLayoutComponent(Node* node)
    void setUsingPercentContentSize(bool isUsed)
    bool getUsingPercentContentSize()
    void setPercentContentSize(const Vec2 &percent)
    Vec2 getPercentContentSize()
    const Point& getAnchorPosition()
    void setAnchorPosition(const Point& point)
    const Point& getPosition()
    void setPosition(const Point& position)
    bool isPositionPercentXEnabled()
    void setPositionPercentXEnabled(bool isUsed)
    float getPositionPercentX()
    void setPositionPercentX(float percentMargin)
    bool isPositionPercentYEnabled()
    void setPositionPercentYEnabled(bool isUsed)
    float getPositionPercentY()
    void setPositionPercentY(float percentMargin)
    HorizontalEdge getHorizontalEdge()
    void setHorizontalEdge(HorizontalEdge hEage)
    VerticalEdge getVerticalEdge()
    void setVerticalEdge(VerticalEdge vEage)
    float getLeftMargin()
    void setLeftMargin(float margin)
    float getRightMargin()
    void setRightMargin(float margin)
    float getTopMargin()
    void setTopMargin(float margin)
    float getBottomMargin()
    void setBottomMargin(float margin)
    const Size& getSize()
    void setSize(const Size& size)
    bool isPercentWidthEnabled()
    void setPercentWidthEnabled(bool isUsed)
    float getSizeWidth()
    void setSizeWidth(float width)
    float getPercentWidth()
    void setPercentWidth(float percentWidth)
    bool isPercentHeightEnabled()
    void setPercentHeightEnabled(bool isUsed)
    float getSizeHeight()
    void setSizeHeight(float height)
    float getPercentHeight()
    void setPercentHeight(float percentHeight)
    bool isStretchWidthEnabled()
    void setStretchWidthEnabled(bool isUsed)
    bool isStretchHeightEnabled()
    void setStretchHeightEnabled(bool isUsed)
    void setPercentOnlyEnabled(bool enable)
    void setActiveEnabled(bool enable)
    void refreshLayout()
]]
cls.props [[
    usingPercentContentSize
    percentContentSize
    anchorPosition
    position
    positionPercentXEnabled
    positionPercentX
    positionPercentYEnabled
    positionPercentY
    horizontalEdge
    verticalEdge
    leftMargin
    rightMargin
    topMargin
    bottomMargin
    size
    percentWidthEnabled
    sizeWidth
    percentWidth
    percentHeightEnabled
    sizeHeight
    percentHeight
    stretchWidthEnabled
    stretchHeightEnabled
]]

return M