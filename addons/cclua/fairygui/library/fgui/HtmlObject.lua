---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.HtmlObject

---
---@class fgui.HtmlObject 
---@field element fgui.HtmlElement 
---@field hidden boolean 
---@field ui fgui.GObject 
---@field buttonResource string
---@field inputResource string
---@field selectResource string
---@field usePool boolean
---@field loaderPool any
local HtmlObject = {}

---@return any
function HtmlObject:__gc() end

---@param owner fgui.FUIRichText
---@param element fgui.HtmlElement
function HtmlObject:create(owner, element) end

function HtmlObject:destroy() end

---@return fgui.HtmlElement
function HtmlObject:getElement() end

---@return fgui.GObject
function HtmlObject:getUI() end

---@return boolean
function HtmlObject:isHidden() end

---@return fgui.HtmlObject
function HtmlObject.new() end

return HtmlObject