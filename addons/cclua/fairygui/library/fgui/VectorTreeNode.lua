---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.VectorTreeNode

---
---@class fgui.VectorTreeNode 
---@field buffer any 
---@field length integer 
---@field value fgui.GTreeNode[] 
local VectorTreeNode = {}

---@return any
function VectorTreeNode:__gc() end

---@param idx integer
---@return fgui.GTreeNode[]
function VectorTreeNode:__index(idx) end

---@param idx integer
---@param v fgui.GTreeNode[]
function VectorTreeNode:__newindex(idx, v) end

---@param len integer
---@return fgui.VectorTreeNode
---@overload fun(): fgui.VectorTreeNode
---@overload fun(v: fgui.VectorTreeNode, len: integer): fgui.VectorTreeNode
---@overload fun(v: fgui.VectorTreeNode): fgui.VectorTreeNode
function VectorTreeNode.new(len) end

---@param from integer
---@param to integer
---@return fgui.VectorTreeNode
---@overload fun(self: fgui.VectorTreeNode, from: integer): fgui.VectorTreeNode
function VectorTreeNode:slice(from, to) end

---@param from integer
---@param to integer
---@return fgui.VectorTreeNode
---@overload fun(self: fgui.VectorTreeNode, from: integer): fgui.VectorTreeNode
function VectorTreeNode:sub(from, to) end

---@return fgui.VectorTreeNode
function VectorTreeNode:take() end

---@param len integer
---@return any
function VectorTreeNode:tostring(len) end

return VectorTreeNode