---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.ConstraintData

---The interface for all constraints.
---@class spine.ConstraintData : spine.SpineObject
---@field name any The IK constraint's name, which is unique within the skeleton.
---@field order integer The ordinal for the order a skeleton's constraints will be applied.
---@field skinRequired boolean Whether the constraint is only active for a specific skin.
local ConstraintData = {}

---The IK constraint's name, which is unique within the skeleton.
---@return any
function ConstraintData:getName() end

---The ordinal for the order a skeleton's constraints will be applied.
---@return integer
function ConstraintData:getOrder() end

---Whether the constraint is only active for a specific skin.
---@return boolean
function ConstraintData:isSkinRequired() end

---@param name any
---@return spine.ConstraintData
function ConstraintData.new(name) end

---@param inValue integer
function ConstraintData:setOrder(inValue) end

---@param inValue boolean
function ConstraintData:setSkinRequired(inValue) end

return ConstraintData