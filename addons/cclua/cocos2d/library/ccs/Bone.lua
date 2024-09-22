---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.Bone

---
---@class ccs.Bone : cc.Node
---@field armature ccs.Armature 
---@field blendDirty boolean 
---@field blendFunc cc.BlendFunc 
---@field boneData ccs.BoneData 
---@field childArmature ccs.Armature 
---@field colliderDetector ccs.ColliderDetector 
---@field displayManager ccs.DisplayManager 
---@field displayRenderNode cc.Node 
---@field displayRenderNodeType ccs.DisplayType 
---@field ignoreMovementBoneData boolean 
---@field nodeToArmatureTransform cc.Mat4 
---@field parentBone ccs.Bone Get parent bone \return parent bone
---@field transformDirty boolean 
---@field tween ccs.Tween 
---@field tweenData ccs.FrameData 
---@field worldInfo ccs.BaseData 
local Bone = {}

---Add a child to this bone, and it will let this child call setParent(Bone *parent) function to set self to it's parent
---@param child ccs.Bone # the child you want to add
function Bone:addChildBone(child) end

---Add display and use displayData to init the display.
---If index already have a display, then replace it.
---If index is current display index, then also change display to _index
---
---@param displayData ccs.DisplayData # it include the display information, like DisplayType.
---If you want to create a sprite display, then create a SpriteDisplayData param
---
---@param index integer # the index of the display you want to replace or add to
----1 : append display from back
---@overload fun(self: ccs.Bone, display: cc.Node, index: integer)
function Bone:addDisplay(displayData, index) end

---@param index integer
---@param force boolean
function Bone:changeDisplayWithIndex(index, force) end

---@param name string
---@param force boolean
function Bone:changeDisplayWithName(name, force) end

---Allocates and initializes a bone.
---@return ccs.Bone # A initialized bone which is marked as "autorelease".
---
---Allocates and initializes a bone.
---
---\param  name If name is not null, then set name to the bone's name
---\return A initialized bone which is marked as "autorelease".
---@overload fun(name: string): ccs.Bone
function Bone.create() end

---@return ccs.Armature
function Bone:getArmature() end

---@return cc.BlendFunc
function Bone:getBlendFunc() end

---@return ccs.BoneData
function Bone:getBoneData() end

---@return ccs.Armature
function Bone:getChildArmature() end

---@return ccs.ColliderDetector
function Bone:getColliderDetector() end

---@return ccs.DisplayManager
function Bone:getDisplayManager() end

---@return cc.Node
function Bone:getDisplayRenderNode() end

---@return ccs.DisplayType
function Bone:getDisplayRenderNodeType() end

---@return cc.Mat4
function Bone:getNodeToArmatureTransform() end

---Get parent bone
---@return ccs.Bone # parent bone
function Bone:getParentBone() end

---@return ccs.Tween
function Bone:getTween() end

---@return ccs.FrameData
function Bone:getTweenData() end

---@return ccs.BaseData
function Bone:getWorldInfo() end

---Initializes an empty Bone with nothing init.
---@return boolean
---
---Initializes a Bone with the specified name
---\param name Bone's name.
---@overload fun(self: ccs.Bone, name: string): boolean
function Bone:init() end

---@return boolean
function Bone:isBlendDirty() end

---@return boolean
function Bone:isIgnoreMovementBoneData() end

---@return boolean
function Bone:isTransformDirty() end

---\js ctor
---@return ccs.Bone
function Bone.new() end

---Removes a child Bone
---@param bone ccs.Bone # the bone you want to remove
---@param recursion boolean
function Bone:removeChildBone(bone, recursion) end

---@param index integer
function Bone:removeDisplay(index) end

---Remove itself from its parent.
---@param recursion boolean # whether or not to remove childBone's display
---
---Removes this node itself from its parent node with a cleanup.
---If the node orphan, then nothing happens.
---\see `removeFromParentAndCleanup(bool)`
---@overload fun(self: ccs.Bone)
function Bone:removeFromParent(recursion) end

---@param armature ccs.Armature
function Bone:setArmature(armature) end

---@param dirty boolean
function Bone:setBlendDirty(dirty) end

---@param blendFunc cc.BlendFunc
function Bone:setBlendFunc(blendFunc) end

---@param boneData ccs.BoneData
function Bone:setBoneData(boneData) end

---@param childArmature ccs.Armature
function Bone:setChildArmature(childArmature) end

---\lua NA
---@param ignore boolean
function Bone:setIgnoreMovementBoneData(ignore) end

---@param zOrder integer
function Bone:setLocalZOrder(zOrder) end

---Set parent bone.
---If parent is null, then also remove this bone from armature.
---It will not set the Armature, if you want to add the bone to a Armature, you should use Armature::addBone(Bone *bone, const char* parentName).
---
---@param parent ccs.Bone # the parent bone.
---nullptr : remove this bone from armature
function Bone:setParentBone(parent) end

---@param dirty boolean
function Bone:setTransformDirty(dirty) end

---! Update color to render display
function Bone:updateColor() end

---! Update zorder
function Bone:updateZOrder() end

return Bone