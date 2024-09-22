---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.IkConstraintData

---
---@class spine.IkConstraintData : spine.ConstraintData
---@field bendDirection integer Controls the bend direction of the IK bones, either 1 or -1.
---@field bones any The bones that are constrained by this IK Constraint.
---@field compress boolean 
---@field mix number 
---@field softness number 
---@field stretch boolean 
---@field target spine.BoneData The bone that is the IK target.
---@field uniform boolean 
local IkConstraintData = {}

---Controls the bend direction of the IK bones, either 1 or -1.
---@return integer
function IkConstraintData:getBendDirection() end

---The bones that are constrained by this IK Constraint.
---@return any
function IkConstraintData:getBones() end

---@return boolean
function IkConstraintData:getCompress() end

---@return number
function IkConstraintData:getMix() end

---@return number
function IkConstraintData:getSoftness() end

---@return boolean
function IkConstraintData:getStretch() end

---The bone that is the IK target.
---@return spine.BoneData
function IkConstraintData:getTarget() end

---@return boolean
function IkConstraintData:getUniform() end

---@param name any
---@return spine.IkConstraintData
function IkConstraintData.new(name) end

---@param inValue integer
function IkConstraintData:setBendDirection(inValue) end

---@param inValue boolean
function IkConstraintData:setCompress(inValue) end

---@param inValue number
function IkConstraintData:setMix(inValue) end

---@param inValue number
function IkConstraintData:setSoftness(inValue) end

---@param inValue boolean
function IkConstraintData:setStretch(inValue) end

---@param inValue spine.BoneData
function IkConstraintData:setTarget(inValue) end

---@param inValue boolean
function IkConstraintData:setUniform(inValue) end

return IkConstraintData