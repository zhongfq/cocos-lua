---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.RegionAttachment

---Attachment that displays a texture region.
---@class spine.RegionAttachment : spine.Attachment
---@field color any 
---@field height number 
---@field offset any 
---@field path any 
---@field region spine.TextureRegion 
---@field rotation number 
---@field scaleX number 
---@field scaleY number 
---@field sequence spine.Sequence 
---@field uvs any 
---@field width number 
---@field x number 
---@field y number 
local RegionAttachment = {}

---Transforms the attachment's four vertices to world coordinates.
---@param slot spine.Slot # The parent slot.
---@param worldVertices olua.float # The output world vertices. Must have a length greater than or equal to offset + 8.
---@param offset integer # The worldVertices index to begin writing values.
---@param stride integer # The number of worldVertices entries between the value pairs written.
---@overload fun(self: spine.RegionAttachment, slot: spine.Slot, worldVertices: olua.float, offset: integer)
---@overload fun(self: spine.RegionAttachment, slot: spine.Slot, worldVertices: any, offset: integer, stride: integer)
---@overload fun(self: spine.RegionAttachment, slot: spine.Slot, worldVertices: any, offset: integer)
function RegionAttachment:computeWorldVertices(slot, worldVertices, offset, stride) end

---@return any
function RegionAttachment:getColor() end

---@return number
function RegionAttachment:getHeight() end

---@return any
function RegionAttachment:getOffset() end

---@return any
function RegionAttachment:getPath() end

---@return spine.TextureRegion
function RegionAttachment:getRegion() end

---@return number
function RegionAttachment:getRotation() end

---@return number
function RegionAttachment:getScaleX() end

---@return number
function RegionAttachment:getScaleY() end

---@return spine.Sequence
function RegionAttachment:getSequence() end

---@return any
function RegionAttachment:getUVs() end

---@return number
function RegionAttachment:getWidth() end

---@return number
function RegionAttachment:getX() end

---@return number
function RegionAttachment:getY() end

---@param name any
---@return spine.RegionAttachment
function RegionAttachment.new(name) end

---@param inValue number
function RegionAttachment:setHeight(inValue) end

---@param inValue any
function RegionAttachment:setPath(inValue) end

---@param region spine.TextureRegion
function RegionAttachment:setRegion(region) end

---@param inValue number
function RegionAttachment:setRotation(inValue) end

---@param inValue number
function RegionAttachment:setScaleX(inValue) end

---@param inValue number
function RegionAttachment:setScaleY(inValue) end

---@param sequence spine.Sequence
function RegionAttachment:setSequence(sequence) end

---@param inValue number
function RegionAttachment:setWidth(inValue) end

---@param inValue number
function RegionAttachment:setX(inValue) end

---@param inValue number
function RegionAttachment:setY(inValue) end

function RegionAttachment:updateRegion() end

return RegionAttachment