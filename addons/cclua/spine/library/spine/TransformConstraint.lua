---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.TransformConstraint

---
---@class spine.TransformConstraint : spine.Updatable
---@field bones any 
---@field data spine.TransformConstraintData 
---@field mixRotate number 
---@field mixScaleX number 
---@field mixScaleY number 
---@field mixShearY number 
---@field mixX number 
---@field mixY number 
---@field order integer 
---@field target spine.Bone 
local TransformConstraint = {}

---@return any
function TransformConstraint:getBones() end

---@return spine.TransformConstraintData
function TransformConstraint:getData() end

---@return number
function TransformConstraint:getMixRotate() end

---@return number
function TransformConstraint:getMixScaleX() end

---@return number
function TransformConstraint:getMixScaleY() end

---@return number
function TransformConstraint:getMixShearY() end

---@return number
function TransformConstraint:getMixX() end

---@return number
function TransformConstraint:getMixY() end

---@return integer
function TransformConstraint:getOrder() end

---@return spine.Bone
function TransformConstraint:getTarget() end

---@param data spine.TransformConstraintData
---@param skeleton spine.Skeleton
---@return spine.TransformConstraint
function TransformConstraint.new(data, skeleton) end

---@param inValue number
function TransformConstraint:setMixRotate(inValue) end

---@param inValue number
function TransformConstraint:setMixScaleX(inValue) end

---@param inValue number
function TransformConstraint:setMixScaleY(inValue) end

---@param inValue number
function TransformConstraint:setMixShearY(inValue) end

---@param inValue number
function TransformConstraint:setMixX(inValue) end

---@param inValue number
function TransformConstraint:setMixY(inValue) end

---@param inValue spine.Bone
function TransformConstraint:setTarget(inValue) end

function TransformConstraint:setToSetupPose() end

return TransformConstraint