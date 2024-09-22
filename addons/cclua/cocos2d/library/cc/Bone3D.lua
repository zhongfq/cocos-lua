---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Bone3D

---Defines a basic hierarchical structure of transformation spaces.
---\lua NA
---@class cc.Bone3D : cc.Ref
---@field childBoneCount integer get child bone count
---@field inverseBindPose cc.Mat4 Returns the inverse bind pose matrix for this joint. <br><br>\return Inverse bind pose matrix.
---@field name string get bone name
---@field parentBone cc.Bone3D bone tree, we do not inherit from Node, Node has too many properties that we do not need. A clean Node is needed.
---@field worldMat cc.Mat4 get world matrix
local Bone3D = {}

---add child bone
---@param bone cc.Bone3D
function Bone3D:addChildBone(bone) end

---clear bone blend states
function Bone3D:clearBoneBlendState() end

---Creates C3DBone.
---@param id string
---@return cc.Bone3D
function Bone3D.create(id) end

---get child bone by index
---@param index integer
---@return cc.Bone3D
function Bone3D:getChildBoneByIndex(index) end

---get child bone count
---@return integer
function Bone3D:getChildBoneCount() end

---Returns the inverse bind pose matrix for this joint.
---
---@return cc.Mat4 # Inverse bind pose matrix.
function Bone3D:getInverseBindPose() end

---get bone name
---@return string
function Bone3D:getName() end

---bone tree, we do not inherit from Node, Node has too many properties that we do not need. A clean Node is needed.
---@return cc.Bone3D
function Bone3D:getParentBone() end

---get world matrix
---@return cc.Mat4
function Bone3D:getWorldMat() end

---remove all child bone
function Bone3D:removeAllChildBone() end

---remove child bone
---@param bone cc.Bone3D
function Bone3D:removeChildBone(bone) end

---remove child bone by index
---@param index integer
function Bone3D:removeChildBoneByIndex(index) end

---reset pose to origin
function Bone3D:resetPose() end

---set animation value
---@param trans olua.float # translate vec3
---@param rot olua.float # rotation quaternion
---@param scale olua.float # scale vec3
---@param tag any # unique tag, only blend animation between different tags
---@param weight number # blend weight
---@overload fun(self: cc.Bone3D, trans: olua.float, rot: olua.float, scale: olua.float)
---@overload fun(self: cc.Bone3D, trans: olua.float, rot: olua.float, scale: olua.float, tag: any)
function Bone3D:setAnimationValue(trans, rot, scale, tag, weight) end

---Sets the inverse bind pose matrix.
---
---@param m cc.Mat4 # Mat4 representing the inverse bind pose for this Bone.
function Bone3D:setInverseBindPose(m) end

---Sets the bone's original pose.
---
---@param m cc.Mat4 # Mat4 representing the original pose for this Bone.
function Bone3D:setOriPose(m) end

---Updates the joint matrix.
---
---@param matrixPalette cc.Vec4 # The matrix palette to update.
function Bone3D:updateJointMatrix(matrixPalette) end

---update own world matrix and children's
function Bone3D:updateWorldMat() end

return Bone3D