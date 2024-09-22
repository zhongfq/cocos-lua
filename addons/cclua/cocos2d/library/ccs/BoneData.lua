---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.BoneData

---BoneData used to init a Bone.
---BoneData keeps a DisplayData list, a Bone can have many display to change.
---The display information saved in the DisplayData
---\js NA
---\lua NA
---@class ccs.BoneData : ccs.BaseData
---@field name string
---@field parentName string
---@field displayDataList any
---@field boneDataTransform cc.AffineTransform
local BoneData = {}

---@param displayData ccs.DisplayData
function BoneData:addDisplayData(displayData) end

---@return ccs.BoneData
function BoneData.create() end

---@param index integer
---@return ccs.DisplayData
function BoneData:getDisplayData(index) end

---@return boolean
function BoneData:init() end

---\js ctor
---@return ccs.BoneData
function BoneData.new() end

return BoneData