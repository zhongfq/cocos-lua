---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.LayoutProtocol

---Layout interface for creating LayoutManger and do actual layout.
---\js NA
---@class ccui.LayoutProtocol 
---@field layoutContentSize cc.Size Return the content size of layout. <br><br>\return A content size in Size.
---@field layoutElements any Get all elements of the layout. <br><br>\return A vector of Node pointers.
local LayoutProtocol = {}

---@return any
function LayoutProtocol:__gc() end

---Create a custom layout manager.
---
---@return ccui.LayoutManager # A LayoutManager descendants instance.
function LayoutProtocol:createLayoutManager() end

---The main function to do the layout job.
---Different layout manager should implement its own layout algorithm.
function LayoutProtocol:doLayout() end

---Return the content size of layout.
---
---@return cc.Size # A content size in Size.
function LayoutProtocol:getLayoutContentSize() end

---Get all elements of the layout.
---
---@return any # A vector of Node pointers.
function LayoutProtocol:getLayoutElements() end

return LayoutProtocol