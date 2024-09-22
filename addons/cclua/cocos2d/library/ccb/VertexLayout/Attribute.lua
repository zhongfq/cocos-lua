---AUTO GENERATED, DO NOT MODIFY!
---@meta ccb.VertexLayout.Attribute

---
---@class ccb.VertexLayout.Attribute 
---@field name string
---@field format ccb.VertexFormat
---@field offset integer
---@field index integer
---@field needToBeNormallized boolean
local Attribute = {}

---@return any
function Attribute:__gc() end

---@return ccb.VertexLayout.Attribute
---@overload fun(_name: string, _index: integer, _format: ccb.VertexFormat, _offset: integer, needToBeNormallized: boolean): ccb.VertexLayout.Attribute
function Attribute.new() end

return Attribute