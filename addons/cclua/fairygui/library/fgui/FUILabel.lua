---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.FUILabel

---
---@class fgui.FUILabel : cc.Label
---@field text string 
---@field textFormat fgui.TextFormat 
local FUILabel = {}

function FUILabel:applyTextFormat() end

---@return fgui.FUILabel
function FUILabel.create() end

---@return string
function FUILabel:getText() end

---@return fgui.TextFormat
function FUILabel:getTextFormat() end

---@return fgui.FUILabel
function FUILabel.new() end

---@param bmfontFilePath string
---@param imageOffset cc.Vec2
---@param fontSize number
---@return boolean
---@overload fun(self: fgui.FUILabel, bmfontFilePath: string, imageOffset: cc.Vec2): boolean
---@overload fun(self: fgui.FUILabel, bmfontFilePath: string, fontSize: number): boolean
---@overload fun(self: fgui.FUILabel, bmfontFilePath: string): boolean
---@overload fun(self: fgui.FUILabel, bmfontFilePath: string, imageRect: cc.Rect, imageRotated: boolean, fontSize: number): boolean
---@overload fun(self: fgui.FUILabel, bmfontFilePath: string, imageRect: cc.Rect, imageRotated: boolean): boolean
---@overload fun(self: fgui.FUILabel, bmfontFilePath: string, subTextureKey: string, fontSize: number): boolean
---@overload fun(self: fgui.FUILabel, bmfontFilePath: string, subTextureKey: string): boolean
function FUILabel:setBMFontFilePath(bmfontFilePath, imageOffset, fontSize) end

---@param value boolean
function FUILabel:setGrayed(value) end

---@param value string
function FUILabel:setText(value) end

---@param value any
function FUILabel:setUnderlineColor(value) end

return FUILabel