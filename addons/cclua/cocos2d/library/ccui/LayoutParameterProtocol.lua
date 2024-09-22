---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.LayoutParameterProtocol

---Protocol for getting a LayoutParameter.
---Every element want to have layout parameter should inherit from this class.
---@class ccui.LayoutParameterProtocol 
---@field layoutParameter ccui.LayoutParameter \return A LayoutParameter and its descendant pointer.
local LayoutParameterProtocol = {}

---@return any
function LayoutParameterProtocol:__gc() end

---@return ccui.LayoutParameter # A LayoutParameter and its descendant pointer.
function LayoutParameterProtocol:getLayoutParameter() end

return LayoutParameterProtocol