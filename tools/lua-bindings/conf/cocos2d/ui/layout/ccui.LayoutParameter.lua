local M = {}

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::LayoutParameter::Type"
cls.LUACLS = "ccui.LayoutParameter.Type"
cls.enums [[
    NONE
    LINEAR
    RELATIVE
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::LayoutParameter"
cls.LUACLS = "ccui.LayoutParameter"
cls.SUPERCLS = "cc.Ref"
cls.funcs [[
    static LayoutParameter* create()
    void setMargin(const Margin& margin)
    const Margin& getMargin()
    Type getLayoutType()
    LayoutParameter* clone()
    LayoutParameter* createCloneInstance()
    void copyProperties(LayoutParameter* model)
]]
cls.props [[
    margin
    layoutType
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::LinearLayoutParameter::LinearGravity"
cls.LUACLS = "ccui.LinearLayoutParameter.LinearGravity"
cls.enums [[
    NONE
    LEFT
    TOP
    RIGHT
    BOTTOM
    CENTER_VERTICAL
    CENTER_HORIZONTAL
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::LinearLayoutParameter"
cls.LUACLS = "ccui.LinearLayoutParameter"
cls.SUPERCLS = "ccui.LayoutParameter"
cls.funcs [[
    static LinearLayoutParameter* create()
    void setGravity(LinearGravity gravity)
    LinearGravity getGravity()
]]
cls.props [[
    gravity
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::RelativeLayoutParameter::RelativeAlign"
cls.LUACLS = "ccui.RelativeLayoutParameter.RelativeAlign"
cls.enums [[
    NONE
    PARENT_TOP_LEFT
    PARENT_TOP_CENTER_HORIZONTAL
    PARENT_TOP_RIGHT
    PARENT_LEFT_CENTER_VERTICAL
    CENTER_IN_PARENT
    PARENT_RIGHT_CENTER_VERTICAL
    PARENT_LEFT_BOTTOM
    PARENT_BOTTOM_CENTER_HORIZONTAL
    PARENT_RIGHT_BOTTOM
    LOCATION_ABOVE_LEFTALIGN
    LOCATION_ABOVE_CENTER
    LOCATION_ABOVE_RIGHTALIGN
    LOCATION_LEFT_OF_TOPALIGN
    LOCATION_LEFT_OF_CENTER
    LOCATION_LEFT_OF_BOTTOMALIGN
    LOCATION_RIGHT_OF_TOPALIGN
    LOCATION_RIGHT_OF_CENTER
    LOCATION_RIGHT_OF_BOTTOMALIGN
    LOCATION_BELOW_LEFTALIGN
    LOCATION_BELOW_CENTER
    LOCATION_BELOW_RIGHTALIGN
]]

local cls = class(M)
cls.CPPCLS = "cocos2d::ui::RelativeLayoutParameter"
cls.LUACLS = "ccui.RelativeLayoutParameter"
cls.SUPERCLS = "ccui.LayoutParameter"
cls.funcs [[
    static RelativeLayoutParameter* create()
    void setAlign(RelativeAlign align)
    RelativeAlign getAlign()
    void setRelativeToWidgetName(const std::string& name)
    const std::string& getRelativeToWidgetName()
    void setRelativeName(const std::string& name)
    const std::string& getRelativeName()
]]
cls.props [[
    align
    relativeToWidgetName
    relativeName
]]

return M