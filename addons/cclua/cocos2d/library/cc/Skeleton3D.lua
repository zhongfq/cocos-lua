---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Skeleton3D

---Skeleton
---@class cc.Skeleton3D : cc.Ref
---@field boneCount integer get total bone count
---@field rootCount integer get & set root bone
local Skeleton3D = {}

---add bone
---@param bone cc.Bone3D
function Skeleton3D:addBone(bone) end

---get bone
---@param index integer
---@return cc.Bone3D
function Skeleton3D:getBoneByIndex(index) end

---@param id string
---@return cc.Bone3D
function Skeleton3D:getBoneByName(id) end

---get total bone count
---@return integer
function Skeleton3D:getBoneCount() end

---get bone index
---@param bone cc.Bone3D
---@return integer
function Skeleton3D:getBoneIndex(bone) end

---@param index integer
---@return cc.Bone3D
function Skeleton3D:getRootBone(index) end

---get & set root bone
---@return integer
function Skeleton3D:getRootCount() end

---@return cc.Skeleton3D
function Skeleton3D.new() end

---remove all bones
function Skeleton3D:removeAllBones() end

---refresh bone world matrix
function Skeleton3D:updateBoneMatrix() end

return Skeleton3D