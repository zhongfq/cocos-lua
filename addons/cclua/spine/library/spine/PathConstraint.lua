---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.PathConstraint

---
---@class spine.PathConstraint : spine.Updatable
---@field bones any 
---@field data spine.PathConstraintData 
---@field mixRotate number 
---@field mixX number 
---@field mixY number 
---@field order integer 
---@field position number 
---@field spacing number 
---@field target spine.Slot 
local PathConstraint = {}

---@return any
function PathConstraint:getBones() end

---@return spine.PathConstraintData
function PathConstraint:getData() end

---@return number
function PathConstraint:getMixRotate() end

---@return number
function PathConstraint:getMixX() end

---@return number
function PathConstraint:getMixY() end

---@return integer
function PathConstraint:getOrder() end

---@return number
function PathConstraint:getPosition() end

---@return number
function PathConstraint:getSpacing() end

---@return spine.Slot
function PathConstraint:getTarget() end

---@param data spine.PathConstraintData
---@param skeleton spine.Skeleton
---@return spine.PathConstraint
function PathConstraint.new(data, skeleton) end

---@param inValue number
function PathConstraint:setMixRotate(inValue) end

---@param inValue number
function PathConstraint:setMixX(inValue) end

---@param inValue number
function PathConstraint:setMixY(inValue) end

---@param inValue number
function PathConstraint:setPosition(inValue) end

---@param inValue number
function PathConstraint:setSpacing(inValue) end

---@param inValue spine.Slot
function PathConstraint:setTarget(inValue) end

function PathConstraint:setToSetupPose() end

return PathConstraint