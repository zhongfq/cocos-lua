---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.VertexAttachment

---An attachment with vertices that are transformed by one or more bones and can be deformed by a slot's vertices.
---@class spine.VertexAttachment : spine.Attachment
---@field bones any 
---@field id integer Gets a unique ID for this attachment.
---@field timelineAttachment spine.Attachment 
---@field vertices any 
---@field worldVerticesLength integer 
local VertexAttachment = {}

---@param slot spine.Slot
---@param worldVertices olua.float
---@overload fun(self: spine.VertexAttachment, slot: spine.Slot, worldVertices: any)
---
---Transforms local vertices to world coordinates.
---\param start The index of the first Vertices value to transform. Each vertex has 2 values, x and y.
---\param count The number of world vertex values to output. Must be less than or equal to WorldVerticesLength - start.
---\param worldVertices The output world vertices. Must have a length greater than or equal to offset + count.
---\param offset The worldVertices index to begin writing values.
---\param stride The number of worldVertices entries between the value pairs written.
---@overload fun(self: spine.VertexAttachment, slot: spine.Slot, start: integer, count: integer, worldVertices: olua.float, offset: integer, stride: integer)
---
---Transforms local vertices to world coordinates.
---\param start The index of the first Vertices value to transform. Each vertex has 2 values, x and y.
---\param count The number of world vertex values to output. Must be less than or equal to WorldVerticesLength - start.
---\param worldVertices The output world vertices. Must have a length greater than or equal to offset + count.
---\param offset The worldVertices index to begin writing values.
---\param stride The number of worldVertices entries between the value pairs written.
---@overload fun(self: spine.VertexAttachment, slot: spine.Slot, start: integer, count: integer, worldVertices: olua.float, offset: integer)
---@overload fun(self: spine.VertexAttachment, slot: spine.Slot, start: integer, count: integer, worldVertices: any, offset: integer, stride: integer)
---@overload fun(self: spine.VertexAttachment, slot: spine.Slot, start: integer, count: integer, worldVertices: any, offset: integer)
function VertexAttachment:computeWorldVertices(slot, worldVertices) end

---@param other spine.VertexAttachment
function VertexAttachment:copyTo(other) end

---@return any
function VertexAttachment:getBones() end

---Gets a unique ID for this attachment.
---@return integer
function VertexAttachment:getId() end

---@return spine.Attachment
function VertexAttachment:getTimelineAttachment() end

---@return any
function VertexAttachment:getVertices() end

---@return integer
function VertexAttachment:getWorldVerticesLength() end

---@param attachment spine.Attachment
function VertexAttachment:setTimelineAttachment(attachment) end

---@param inValue integer
function VertexAttachment:setWorldVerticesLength(inValue) end

return VertexAttachment