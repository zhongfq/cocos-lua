---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.ColliderDetector

---
---@class ccs.ColliderDetector : cc.Ref
---@field active boolean 
---@field bone ccs.Bone 
---@field colliderBodyList any 
local ColliderDetector = {}

---@param contourData ccs.ContourData
function ColliderDetector:addContourData(contourData) end

---@param contourDataList any
function ColliderDetector:addContourDataList(contourDataList) end

---@return ccs.ColliderDetector
---@overload fun(bone: ccs.Bone): ccs.ColliderDetector
function ColliderDetector.create() end

---@return boolean
function ColliderDetector:getActive() end

---@return ccs.Bone
function ColliderDetector:getBone() end

---@return any
function ColliderDetector:getColliderBodyList() end

---@return boolean
---@overload fun(self: ccs.ColliderDetector, bone: ccs.Bone): boolean
function ColliderDetector:init() end

---\js ctor
---@return ccs.ColliderDetector
function ColliderDetector.new() end

function ColliderDetector:removeAll() end

---@param contourData ccs.ContourData
function ColliderDetector:removeContourData(contourData) end

---@param active boolean
function ColliderDetector:setActive(active) end

---@param bone ccs.Bone
function ColliderDetector:setBone(bone) end

---@param t cc.Mat4
function ColliderDetector:updateTransform(t) end

return ColliderDetector