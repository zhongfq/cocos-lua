---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.MeshAttachment

---Attachment that displays a texture region using a mesh.
---@class spine.MeshAttachment : spine.VertexAttachment
---@field color any 
---@field edges any 
---@field height number 
---@field hullLength integer 
---@field parentMesh spine.MeshAttachment 
---@field path any 
---@field region spine.TextureRegion 
---@field regionUVs any 
---@field sequence spine.Sequence 
---@field triangles any 
---@field uvs any The UV pair for each vertex, normalized within the entire texture. See also MeshAttachment::updateRegion
---@field width number 
local MeshAttachment = {}

---@return any
function MeshAttachment:getColor() end

---@return any
function MeshAttachment:getEdges() end

---@return number
function MeshAttachment:getHeight() end

---@return integer
function MeshAttachment:getHullLength() end

---@return spine.MeshAttachment
function MeshAttachment:getParentMesh() end

---@return any
function MeshAttachment:getPath() end

---@return spine.TextureRegion
function MeshAttachment:getRegion() end

---@return any
function MeshAttachment:getRegionUVs() end

---@return spine.Sequence
function MeshAttachment:getSequence() end

---@return any
function MeshAttachment:getTriangles() end

---The UV pair for each vertex, normalized within the entire texture. See also MeshAttachment::updateRegion
---@return any
function MeshAttachment:getUVs() end

---@return number
function MeshAttachment:getWidth() end

---@param name any
---@return spine.MeshAttachment
function MeshAttachment.new(name) end

---@return spine.MeshAttachment
function MeshAttachment:newLinkedMesh() end

---@param inValue number
function MeshAttachment:setHeight(inValue) end

---@param inValue integer
function MeshAttachment:setHullLength(inValue) end

---@param inValue spine.MeshAttachment
function MeshAttachment:setParentMesh(inValue) end

---@param inValue any
function MeshAttachment:setPath(inValue) end

---@param region spine.TextureRegion
function MeshAttachment:setRegion(region) end

---@param sequence spine.Sequence
function MeshAttachment:setSequence(sequence) end

---@param inValue number
function MeshAttachment:setWidth(inValue) end

function MeshAttachment:updateRegion() end

return MeshAttachment