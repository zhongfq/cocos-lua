---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.AnimationData

---AnimationData include all movement information for the Armature
---The struct is AnimationData -> MovementData -> MovementBoneData -> FrameData
----> MovementFrameData
---\js NA
---\lua NA
---@class ccs.AnimationData : cc.Ref
---@field movementCount integer 
---@field name string
---@field movementDataDic any
---@field movementNames string[]
local AnimationData = {}

---@param movData ccs.MovementData
function AnimationData:addMovement(movData) end

---@return ccs.AnimationData
function AnimationData.create() end

---@param movementName string
---@return ccs.MovementData
function AnimationData:getMovement(movementName) end

---@return integer
function AnimationData:getMovementCount() end

---\js ctor
---@return ccs.AnimationData
function AnimationData.new() end

return AnimationData