---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.ArmatureData

---ArmatureData saved the Armature name and Bonedata needed for the CCBones in this Armature
---When we create a Armature, we need to get each Bone's BoneData as it's init information.
---So we can get a BoneData from the Dictionary saved in the ArmatureData.
---\js NA
---\lua NA
---@class ccs.ArmatureData : cc.Ref
---@field name string
---@field boneDataDic any
---@field dataVersion number
local ArmatureData = {}

---@param boneData ccs.BoneData
function ArmatureData:addBoneData(boneData) end

---@return ccs.ArmatureData
function ArmatureData.create() end

---@param boneName string
---@return ccs.BoneData
function ArmatureData:getBoneData(boneName) end

---@return boolean
function ArmatureData:init() end

---\js ctor
---@return ccs.ArmatureData
function ArmatureData.new() end

return ArmatureData