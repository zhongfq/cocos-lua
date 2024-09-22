---AUTO GENERATED, DO NOT MODIFY!
---@meta ccb.VertexLayout

---Store vertex attribute layout.
---@class ccb.VertexLayout 
---@field attributes { [string]: ccb.VertexLayout.Attribute } Get attribute informations \return Atrribute informations.
---@field stride integer Get the distance between the data of two vertices, in bytes. \return The distance between the data of two vertices, in bytes.
---@field valid boolean Check if vertex layout has been set.
---@field vertexStepMode ccb.VertexStepMode Get vertex step function. Default value is VERTEX. \return Vertex step function. \note Used in metal.
local VertexLayout = {}

---@return any
function VertexLayout:__gc() end

---Get attribute informations
---@return { [string]: ccb.VertexLayout.Attribute } # Atrribute informations.
function VertexLayout:getAttributes() end

---Get the distance between the data of two vertices, in bytes.
---@return integer # The distance between the data of two vertices, in bytes.
function VertexLayout:getStride() end

---Get vertex step function. Default value is VERTEX.
---@return ccb.VertexStepMode # Vertex step function.
---\note Used in metal.
function VertexLayout:getVertexStepMode() end

---Check if vertex layout has been set.
---@return boolean
function VertexLayout:isValid() end

---@return ccb.VertexLayout
function VertexLayout.new() end

---Set attribute values to name.
---@param name string # Specifies the attribute name.
---@param index integer # Specifies the index of the generic vertex attribute to be modified.
---@param format ccb.VertexFormat # Specifies how the vertex attribute data is laid out in memory.
---@param offset integer # Specifies the byte offset to the first component of the first generic vertex attribute.
---@param needToBeNormallized boolean # Specifies whether fixed-point data values should be normalized (true) or converted directly as fixed-point values (false) when they are accessed.
function VertexLayout:setAttribute(name, index, format, offset, needToBeNormallized) end

---Set stride of vertices.
---@param stride integer # Specifies the distance between the data of two vertices, in bytes.
function VertexLayout:setLayout(stride) end

return VertexLayout