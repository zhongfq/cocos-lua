local M = {}

local cls = class(M)
cls.CPPCLS = "fairygui::PackageItemType"
cls.LUACLS = "fgui.PackageItemType"
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
cls.LUACLS = "fgui.ObjectType"
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
cls.LUACLS = "fgui.ButtonMode"
cls.enums [[
    COMMON
    CHECK
    RADIO
]]

local cls = class(M)
cls.CPPCLS = "fairygui::ChildrenRenderOrder"
cls.LUACLS = "fgui.ChildrenRenderOrder"
cls.enums [[
    ASCENT
    DESCENT
    ARCH
]]

local cls = class(M)
cls.CPPCLS = "fairygui::OverflowType"
cls.LUACLS = "fgui.OverflowType"
cls.enums [[
    VISIBLE
    HIDDEN
    SCROLL
]]

local cls = class(M)
cls.CPPCLS = "fairygui::ScrollType"
cls.LUACLS = "fgui.ScrollType"
cls.enums [[
    HORIZONTAL
    VERTICAL
    BOTH
]]

local cls = class(M)
cls.CPPCLS = "fairygui::ScrollBarDisplayType"
cls.LUACLS = "fgui.ScrollBarDisplayType"
cls.enums [[
    DEFAULT
    VISIBLE
    AUTO
    HIDDEN
]]

local cls = class(M)
cls.CPPCLS = "fairygui::LoaderFillType"
cls.LUACLS = "fgui.LoaderFillType"
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
cls.LUACLS = "fgui.ProgressTitleType"
cls.enums [[
    PERCENT
    VALUE_MAX
    VALUE
    MAX
]]

local cls = class(M)
cls.CPPCLS = "fairygui::ListLayoutType"
cls.LUACLS = "fgui.ListLayoutType"
cls.enums [[
    SINGLE_COLUMN
    SINGLE_ROW
    FLOW_HORIZONTAL
    FLOW_VERTICAL
    PAGINATION
]]

local cls = class(M)
cls.CPPCLS = "fairygui::ListSelectionMode"
cls.LUACLS = "fgui.ListSelectionMode"
cls.enums [[
    SINGLE
    MULTIPLE
    MULTIPLE_SINGLECLICK
    NONE
]]

local cls = class(M)
cls.CPPCLS = "fairygui::GroupLayoutType"
cls.LUACLS = "fgui.GroupLayoutType"
cls.enums [[
    NONE
    HORIZONTAL
    VERTICAL
]]

local cls = class(M)
cls.CPPCLS = "fairygui::PopupDirection"
cls.LUACLS = "fgui.PopupDirection"
cls.enums [[
    AUTO
    UP
    DOWN
]]

local cls = class(M)
cls.CPPCLS = "fairygui::AutoSizeType"
cls.LUACLS = "fgui.AutoSizeType"
cls.enums [[
    NONE
    BOTH
    HEIGHT
    SHRINK
]]

local cls = class(M)
cls.CPPCLS = "fairygui::FlipType"
cls.LUACLS = "fgui.FlipType"
cls.enums [[
    NONE
    HORIZONTAL
    VERTICAL
    BOTH
]]

local cls = class(M)
cls.CPPCLS = "fairygui::TransitionActionType"
cls.LUACLS = "fgui.TransitionActionType"
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
cls.LUACLS = "fgui.FillMethod"
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
cls.LUACLS = "fgui.FillOrigin"
cls.enums [[
    Top
    Bottom
    Left
    Right
]]

return M