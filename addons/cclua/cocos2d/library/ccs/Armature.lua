---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.Armature

---
---@class ccs.Armature : cc.Node
---@field animation ccs.ArmatureAnimation 
---@field armatureData ccs.ArmatureData 
---@field armatureTransformDirty boolean 
---@field batchNode ccs.BatchNode 
---@field blendFunc cc.BlendFunc \js NA \lua NA
---@field boneDic any Get Armature's bone dictionary \return Armature's bone dictionary
---@field offsetPoints cc.Vec2 
---@field parentBone ccs.Bone 
---@field version number 
local Armature = {}

---Add a Bone to this Armature,
---
---@param bone ccs.Bone # The Bone you want to add to Armature
---@param parentName string # The parent Bone's name you want to add to . If it's  nullptr, then set Armature to its parent
function Armature:addBone(bone, parentName) end

---@param cls string
---@return any
function Armature:as(cls) end

---Change a bone's parent with the specified parent name.
---
---@param bone ccs.Bone # The bone you want to change parent
---@param parentName string # The new parent's name.
function Armature:changeBoneParent(bone, parentName) end

---Allocates and initializes an armature.
---@return ccs.Armature # An initialized armature which is marked as "autorelease".
---
---Allocates an armature, and use the ArmatureData named name in ArmatureDataManager to initializes the armature.
---
---\param  name Armature will use the name to find the ArmatureData to initializes it.
---\return A initialized armature which is marked as "autorelease".
---@overload fun(name: string): ccs.Armature
---@overload fun(name: string, parentBone: ccs.Bone): ccs.Armature
function Armature.create() end

---@return ccs.ArmatureAnimation
function Armature:getAnimation() end

---@return ccs.ArmatureData
function Armature:getArmatureData() end

---@return boolean
function Armature:getArmatureTransformDirty() end

---@return ccs.BatchNode
function Armature:getBatchNode() end

---\js NA
---\lua NA
---@return cc.BlendFunc
function Armature:getBlendFunc() end

---Get a bone with the specified name
---
---@param name string # The bone's name you want to get
---@return ccs.Bone
function Armature:getBone(name) end

---@param x number
---@param y number
---@return ccs.Bone
function Armature:getBoneAtPoint(x, y) end

---Get Armature's bone dictionary
---@return any # Armature's bone dictionary
function Armature:getBoneDic() end

---@return cc.Vec2
function Armature:getOffsetPoints() end

---@return ccs.Bone
function Armature:getParentBone() end

---@return number
function Armature:getVersion() end

---Init the empty armature
---@return boolean
---
---Init an armature with specified name
---\param name Armature name
---@overload fun(self: ccs.Armature, name: string): boolean
---@overload fun(self: ccs.Armature, name: string, parentBone: ccs.Bone): boolean
function Armature:init() end

---\js ctor
---@return ccs.Armature
function Armature.new() end

---Remove a bone with the specified name. If recursion it will also remove child Bone recursionly.
---
---@param bone ccs.Bone # The bone you want to remove
---@param recursion boolean # Determine whether remove the bone's child  recursion.
function Armature:removeBone(bone, recursion) end

---@param animation ccs.ArmatureAnimation
function Armature:setAnimation(animation) end

---@param armatureData ccs.ArmatureData
function Armature:setArmatureData(armatureData) end

---@param batchNode ccs.BatchNode
function Armature:setBatchNode(batchNode) end

---\js NA
---\lua NA
---@param blendFunc cc.BlendFunc
function Armature:setBlendFunc(blendFunc) end

---@param parentBone ccs.Bone
function Armature:setParentBone(parentBone) end

---@param version number
function Armature:setVersion(version) end

---Set contentsize and Calculate anchor point.
function Armature:updateOffsetPoint() end

return Armature