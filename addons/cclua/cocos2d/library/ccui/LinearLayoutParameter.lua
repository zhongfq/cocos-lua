---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.LinearLayoutParameter

---Linear layout parameter.
---It is used by linear layout manager for arranging elements linearly.
---@class ccui.LinearLayoutParameter : ccui.LayoutParameter
---@field gravity ccui.LinearLayoutParameter.LinearGravity Gets LinearGravity parameter for LayoutParameter. <br><br>\see LinearGravity \return LinearGravity
local LinearLayoutParameter = {}

---Create a empty LinearLayoutParameter instance.
---@return ccui.LinearLayoutParameter # A initialized LayoutParameter which is marked as "autorelease".
function LinearLayoutParameter.create() end

---Gets LinearGravity parameter for LayoutParameter.
---
---\see LinearGravity
---@return ccui.LinearLayoutParameter.LinearGravity # LinearGravity
function LinearLayoutParameter:getGravity() end

---Default constructor.
---
---\lua new
---@return ccui.LinearLayoutParameter
function LinearLayoutParameter.new() end

---Sets LinearGravity parameter for LayoutParameter.
---
---\see LinearGravity
---@param gravity ccui.LinearLayoutParameter.LinearGravity # Gravity in LinearGravity.
function LinearLayoutParameter:setGravity(gravity) end

return LinearLayoutParameter