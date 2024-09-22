---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.MeshSkin

---MeshSkin, A class maintain a collection of bones that affect Mesh vertex.
---And it is responsible for computing matrix palettes that used by skin mesh rendering.
---\js NA
---\lua NA
---@class cc.MeshSkin : cc.Ref
---@field boneCount integer get total bone count, skin bone + node bone
---@field matrixPalette cc.Vec4 compute matrix palette used by gpu skin
---@field matrixPaletteSize integer getSkinBoneCount() * 3
---@field matrixPaletteSizeInBytes integer getSkinBoneCount() * 3 * sizeof(Vec4)
---@field rootBone cc.Bone3D get root bone of the skin
local MeshSkin = {}

---add skin bone
---@param bone cc.Bone3D
function MeshSkin:addSkinBone(bone) end

---get bone
---@param index integer
---@return cc.Bone3D
function MeshSkin:getBoneByIndex(index) end

---@param id string
---@return cc.Bone3D
function MeshSkin:getBoneByName(id) end

---get total bone count, skin bone + node bone
---@return integer
function MeshSkin:getBoneCount() end

---get bone index
---@param bone cc.Bone3D
---@return integer
function MeshSkin:getBoneIndex(bone) end

---get inverse bind pose
---@param bone cc.Bone3D
---@return cc.Mat4
function MeshSkin:getInvBindPose(bone) end

---compute matrix palette used by gpu skin
---@return cc.Vec4
function MeshSkin:getMatrixPalette() end

---getSkinBoneCount() * 3
---@return integer
function MeshSkin:getMatrixPaletteSize() end

---getSkinBoneCount() * 3 * sizeof(Vec4)
---@return integer
function MeshSkin:getMatrixPaletteSizeInBytes() end

---get root bone of the skin
---@return cc.Bone3D
function MeshSkin:getRootBone() end

---@return cc.MeshSkin
function MeshSkin.new() end

---remove all bones
function MeshSkin:removeAllBones() end

return MeshSkin