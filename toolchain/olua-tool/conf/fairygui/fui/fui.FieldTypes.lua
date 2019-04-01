local M = {}

local cls = class(M)
cls.CPPCLS = "fairygui::PackageItemType"
cls.LUACLS = "fui.PackageItemType"
cls.enums [[
    IMAGE
    MOVIECLIP
    SOUND
    COMPONENT
    ATLAS
    FONT
    SWF
    MISC
    UNKNOWN
]]

local cls = class(M)
cls.CPPCLS = "fairygui::ObjectType"
cls.LUACLS = "fui.ObjectType"
cls.enums [[
    IMAGE
    MOVIECLIP
    SWF
    GRAPH
    LOADER
    GROUP
    TEXT
    RICHTEXT
    INPUTTEXT
    COMPONENT
    LIST
    LABEL
    BUTTON
    COMBOBOX
    PROGRESSBAR
    SLIDER
    SCROLLBAR
]]

local cls = class(M)
cls.CPPCLS = "fairygui::ButtonMode"
cls.LUACLS = "fui.ButtonMode"
cls.enums [[
    COMMON
    CHECK
    RADIO
]]

local cls = class(M)
cls.CPPCLS = "fairygui::ChildrenRenderOrder"
cls.LUACLS = "fui.ChildrenRenderOrder"
cls.enums [[
    ASCENT
    DESCENT
    ARCH
]]

local cls = class(M)
cls.CPPCLS = "fairygui::OverflowType"
cls.LUACLS = "fui.OverflowType"
cls.enums [[
    VISIBLE
    HIDDEN
    SCROLL
]]

local cls = class(M)
cls.CPPCLS = "fairygui::ScrollType"
cls.LUACLS = "fui.ScrollType"
cls.enums [[
    HORIZONTAL
    VERTICAL
    BOTH
]]

local cls = class(M)
cls.CPPCLS = "fairygui::ScrollBarDisplayType"
cls.LUACLS = "fui.ScrollBarDisplayType"
cls.enums [[
    DEFAULT
    VISIBLE
    AUTO
    HIDDEN
]]

local cls = class(M)
cls.CPPCLS = "fairygui::LoaderFillType"
cls.LUACLS = "fui.LoaderFillType"
cls.enums [[
    NONE
    SCALE
    SCALE_MATCH_HEIGHT
    SCALE_MATCH_WIDTH
    SCALE_FREE
    SCALE_NO_BORDER
]]

local cls = class(M)
cls.CPPCLS = "fairygui::ProgressTitleType"
cls.LUACLS = "fui.ProgressTitleType"
cls.enums [[
    PERCENT
    VALUE_MAX
    VALUE
    MAX
]]

local cls = class(M)
cls.CPPCLS = "fairygui::ListLayoutType"
cls.LUACLS = "fui.ListLayoutType"
cls.enums [[
    SINGLE_COLUMN
    SINGLE_ROW
    FLOW_HORIZONTAL
    FLOW_VERTICAL
    PAGINATION
]]

local cls = class(M)
cls.CPPCLS = "fairygui::ListSelectionMode"
cls.LUACLS = "fui.ListSelectionMode"
cls.enums [[
    SINGLE
    MULTIPLE
    MULTIPLE_SINGLECLICK
    NONE
]]

local cls = class(M)
cls.CPPCLS = "fairygui::GroupLayoutType"
cls.LUACLS = "fui.GroupLayoutType"
cls.enums [[
    NONE
    HORIZONTAL
    VERTICAL
]]

local cls = class(M)
cls.CPPCLS = "fairygui::PopupDirection"
cls.LUACLS = "fui.PopupDirection"
cls.enums [[
    AUTO
    UP
    DOWN
]]

local cls = class(M)
cls.CPPCLS = "fairygui::AutoSizeType"
cls.LUACLS = "fui.AutoSizeType"
cls.enums [[
    NONE
    BOTH
    HEIGHT
    SHRINK
]]

local cls = class(M)
cls.CPPCLS = "fairygui::FlipType"
cls.LUACLS = "fui.FlipType"
cls.enums [[
    NONE
    HORIZONTAL
    VERTICAL
    BOTH
]]

local cls = class(M)
cls.CPPCLS = "fairygui::TransitionActionType"
cls.LUACLS = "fui.TransitionActionType"
cls.enums [[
    XY
    Size
    Scale
    Pivot
    Alpha
    Rotation
    Color
    Animation
    Visible
    Sound
    Transition
    Shake
    ColorFilter
    Skew
    Text
    Icon
    Unknown
]]

local cls = class(M)
cls.CPPCLS = "fairygui::FillMethod"
cls.LUACLS = "fui.FillMethod"
cls.enums [[
    None
    Horizontal
    Vertical
    Radial90
    Radial180
    Radial360
]]

local cls = class(M)
cls.CPPCLS = "fairygui::FillOrigin"
cls.LUACLS = "fui.FillOrigin"
cls.enums [[
    Top
    Bottom
    Left
    Right
]]

return M