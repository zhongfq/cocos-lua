---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.Margin

---
---@class fgui.Margin 
---@field left number
---@field top number
---@field right number
---@field bottom number
---@field ZERO fgui.Margin
local Margin = {}

---@return any
function Margin:__gc() end

---Test equality of two margins.
---@param target fgui.Margin # A Margin instance.
---@return boolean # True if two margins are equal, false otherwise.
function Margin:equals(target) end

---Default constructor.
---@return fgui.Margin
---
---Construct a Margin instance with left, top, right and bottom margins.
---\param l Left margin in float.
---\param t Top margin in float.
---\param r Right margin in float.
---\param b Bottom margin in float.
---@overload fun(l: number, t: number, r: number, b: number): fgui.Margin
function Margin.new() end

---Change margin with left, top, right and bottom margin.
---@param l number # Left margin in float.
---@param t number # Top margin in float.
---@param r number # Right margin in float.
---@param b number # Bottom margin in float.
function Margin:setMargin(l, t, r, b) end

return Margin