---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.TransformConstraintData

---
---@class spine.TransformConstraintData : spine.ConstraintData
---@field bones any 
---@field local boolean 
---@field mixRotate number 
---@field mixScaleX number 
---@field mixScaleY number 
---@field mixShearY number 
---@field mixX number 
---@field mixY number 
---@field offsetRotation number 
---@field offsetScaleX number 
---@field offsetScaleY number 
---@field offsetShearY number 
---@field offsetX number 
---@field offsetY number 
---@field relative boolean 
---@field target spine.BoneData 
local TransformConstraintData = {}

---@return any
function TransformConstraintData:getBones() end

---@return number
function TransformConstraintData:getMixRotate() end

---@return number
function TransformConstraintData:getMixScaleX() end

---@return number
function TransformConstraintData:getMixScaleY() end

---@return number
function TransformConstraintData:getMixShearY() end

---@return number
function TransformConstraintData:getMixX() end

---@return number
function TransformConstraintData:getMixY() end

---@return number
function TransformConstraintData:getOffsetRotation() end

---@return number
function TransformConstraintData:getOffsetScaleX() end

---@return number
function TransformConstraintData:getOffsetScaleY() end

---@return number
function TransformConstraintData:getOffsetShearY() end

---@return number
function TransformConstraintData:getOffsetX() end

---@return number
function TransformConstraintData:getOffsetY() end

---@return spine.BoneData
function TransformConstraintData:getTarget() end

---@return boolean
function TransformConstraintData:isLocal() end

---@return boolean
function TransformConstraintData:isRelative() end

---@param name any
---@return spine.TransformConstraintData
function TransformConstraintData.new(name) end

---@param isLocal boolean
function TransformConstraintData:setLocal(isLocal) end

---@param mixRotate number
function TransformConstraintData:setMixRotate(mixRotate) end

---@param mixScaleX number
function TransformConstraintData:setMixScaleX(mixScaleX) end

---@param mixScaleY number
function TransformConstraintData:setMixScaleY(mixScaleY) end

---@param mixShearY number
function TransformConstraintData:setMixShearY(mixShearY) end

---@param mixX number
function TransformConstraintData:setMixX(mixX) end

---@param mixY number
function TransformConstraintData:setMixY(mixY) end

---@param offsetRotation number
function TransformConstraintData:setOffsetRotation(offsetRotation) end

---@param offsetScaleX number
function TransformConstraintData:setOffsetScaleX(offsetScaleX) end

---@param offsetScaleY number
function TransformConstraintData:setOffsetScaleY(offsetScaleY) end

---@param offsetShearY number
function TransformConstraintData:setOffsetShearY(offsetShearY) end

---@param offsetX number
function TransformConstraintData:setOffsetX(offsetX) end

---@param offsetY number
function TransformConstraintData:setOffsetY(offsetY) end

---@param isRelative boolean
function TransformConstraintData:setRelative(isRelative) end

---@param target spine.BoneData
function TransformConstraintData:setTarget(target) end

return TransformConstraintData