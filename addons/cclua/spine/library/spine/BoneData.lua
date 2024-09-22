---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.BoneData

---
---@class spine.BoneData : spine.SpineObject
---@field color any 
---@field icon any 
---@field index integer The index of the bone in Skeleton.Bones
---@field inherit spine.Inherit The transform mode for how parent world transforms affect this bone.
---@field length number 
---@field name any The name of the bone, which is unique within the skeleton.
---@field parent spine.BoneData May be NULL.
---@field rotation number Local rotation.
---@field scaleX number Local scaleX.
---@field scaleY number Local scaleY.
---@field shearX number Local shearX.
---@field shearY number Local shearY.
---@field skinRequired boolean 
---@field visible boolean 
---@field x number Local X translation.
---@field y number Local Y translation.
local BoneData = {}

---@return any
function BoneData:getColor() end

---@return any
function BoneData:getIcon() end

---The index of the bone in Skeleton.Bones
---@return integer
function BoneData:getIndex() end

---The transform mode for how parent world transforms affect this bone.
---@return spine.Inherit
function BoneData:getInherit() end

---@return number
function BoneData:getLength() end

---The name of the bone, which is unique within the skeleton.
---@return any
function BoneData:getName() end

---May be NULL.
---@return spine.BoneData
function BoneData:getParent() end

---Local rotation.
---@return number
function BoneData:getRotation() end

---Local scaleX.
---@return number
function BoneData:getScaleX() end

---Local scaleY.
---@return number
function BoneData:getScaleY() end

---Local shearX.
---@return number
function BoneData:getShearX() end

---Local shearY.
---@return number
function BoneData:getShearY() end

---Local X translation.
---@return number
function BoneData:getX() end

---Local Y translation.
---@return number
function BoneData:getY() end

---@return boolean
function BoneData:isSkinRequired() end

---@return boolean
function BoneData:isVisible() end

---@param index integer
---@param name any
---@param parent spine.BoneData
---@return spine.BoneData
---@overload fun(index: integer, name: any): spine.BoneData
function BoneData.new(index, name, parent) end

---@param icon any
function BoneData:setIcon(icon) end

---@param inValue spine.Inherit
function BoneData:setInherit(inValue) end

---@param inValue number
function BoneData:setLength(inValue) end

---@param inValue number
function BoneData:setRotation(inValue) end

---@param inValue number
function BoneData:setScaleX(inValue) end

---@param inValue number
function BoneData:setScaleY(inValue) end

---@param inValue number
function BoneData:setShearX(inValue) end

---@param inValue number
function BoneData:setShearY(inValue) end

---@param inValue boolean
function BoneData:setSkinRequired(inValue) end

---@param inValue boolean
function BoneData:setVisible(inValue) end

---@param inValue number
function BoneData:setX(inValue) end

---@param inValue number
function BoneData:setY(inValue) end

return BoneData