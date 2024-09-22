---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.IkConstraint

---
---@class spine.IkConstraint : spine.Updatable
---@field bendDirection integer 
---@field bones any 
---@field compress boolean 
---@field data spine.IkConstraintData 
---@field mix number 
---@field order integer 
---@field softness number 
---@field stretch boolean 
---@field target spine.Bone 
local IkConstraint = {}

---Adjusts the bone rotation so the tip is as close to the target position as possible. The target is specified
---in the world coordinate system.
---@param bone spine.Bone
---@param targetX number
---@param targetY number
---@param compress boolean
---@param stretch boolean
---@param uniform boolean
---@param alpha number
---
---Adjusts the parent and child bone rotations so the tip of the child is as close to the target position as
---possible. The target is specified in the world coordinate system.
---\param child A direct descendant of the parent bone.
---@overload fun(parent: spine.Bone, child: spine.Bone, targetX: number, targetY: number, bendDir: integer, stretch: boolean, uniform: boolean, softness: number, alpha: number)
function IkConstraint.apply(bone, targetX, targetY, compress, stretch, uniform, alpha) end

---@return integer
function IkConstraint:getBendDirection() end

---@return any
function IkConstraint:getBones() end

---@return boolean
function IkConstraint:getCompress() end

---@return spine.IkConstraintData
function IkConstraint:getData() end

---@return number
function IkConstraint:getMix() end

---@return integer
function IkConstraint:getOrder() end

---@return number
function IkConstraint:getSoftness() end

---@return boolean
function IkConstraint:getStretch() end

---@return spine.Bone
function IkConstraint:getTarget() end

---@param data spine.IkConstraintData
---@param skeleton spine.Skeleton
---@return spine.IkConstraint
function IkConstraint.new(data, skeleton) end

---@param inValue integer
function IkConstraint:setBendDirection(inValue) end

---@param inValue boolean
function IkConstraint:setCompress(inValue) end

---@param inValue number
function IkConstraint:setMix(inValue) end

---@param inValue number
function IkConstraint:setSoftness(inValue) end

---@param inValue boolean
function IkConstraint:setStretch(inValue) end

---@param inValue spine.Bone
function IkConstraint:setTarget(inValue) end

function IkConstraint:setToSetupPose() end

return IkConstraint