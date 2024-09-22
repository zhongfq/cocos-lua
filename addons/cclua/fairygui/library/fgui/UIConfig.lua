---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.UIConfig

---
---@class fgui.UIConfig 
---@field defaultFont string
---@field buttonSound string
---@field buttonSoundVolumeScale number
---@field defaultScrollStep integer
---@field defaultScrollDecelerationRate number
---@field defaultScrollTouchEffect boolean
---@field defaultScrollBounceEffect boolean
---@field defaultScrollBarDisplay fgui.ScrollBarDisplayType
---@field verticalScrollBar string
---@field horizontalScrollBar string
---@field touchDragSensitivity integer
---@field clickDragSensitivity integer
---@field touchScrollSensitivity integer
---@field defaultComboBoxVisibleItemCount integer
---@field globalModalWaiting string
---@field modalLayerColor any
---@field tooltipsWin string
---@field bringWindowToFrontOnClick boolean
---@field windowModalWaiting string
---@field popupMenu string
---@field popupMenu_seperator string
local UIConfig = {}

---@return any
function UIConfig:__gc() end

---@param aliasName string
---@param isTTF olua.bool
---@return string
---@overload fun(aliasName: string): string
function UIConfig.getRealFontName(aliasName, isTTF) end

---@param aliasName string
---@param realName string
function UIConfig.registerFont(aliasName, realName) end

return UIConfig