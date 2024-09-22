---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.HtmlElement

---
---@class fgui.HtmlElement 
---@field type fgui.HtmlElement.Type
---@field text string
---@field format fgui.TextFormat
---@field link fgui.HtmlElement
---@field obj fgui.HtmlObject
---@field space integer
---@field attrs any
local HtmlElement = {}

---@return any
function HtmlElement:__gc() end

---@param attrName string
---@return any
function HtmlElement:getArray(attrName) end

---@param attrName string
---@param defValue integer
---@return integer
---@overload fun(self: fgui.HtmlElement, attrName: string): integer
function HtmlElement:getInt(attrName, defValue) end

---@param attrName string
---@param defValue string
---@return string
---@overload fun(self: fgui.HtmlElement, attrName: string): string
function HtmlElement:getString(attrName, defValue) end

---@param type fgui.HtmlElement.Type
---@return fgui.HtmlElement
function HtmlElement.new(type) end

return HtmlElement