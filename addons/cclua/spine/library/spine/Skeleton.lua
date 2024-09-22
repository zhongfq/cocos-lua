---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.Skeleton

---
---@class spine.Skeleton : spine.SpineObject
---@field bones any 
---@field color any 
---@field data spine.SkeletonData 
---@field drawOrder any 
---@field ikConstraints any 
---@field pathConstraints any 
---@field physicsConstraints any 
---@field rootBone spine.Bone 
---@field scaleX number 
---@field scaleY number 
---@field skin spine.Skin 
---@field slots any 
---@field time number 
---@field transformConstraints any 
---@field updateCacheList any 
---@field x number 
---@field y number 
local Skeleton = {}

---@return spine.Bone # May be NULL.
---@param boneName any
function Skeleton:findBone(boneName) end

---@return spine.IkConstraint # May be NULL.
---@param constraintName any
function Skeleton:findIkConstraint(constraintName) end

---@return spine.PathConstraint # May be NULL.
---@param constraintName any
function Skeleton:findPathConstraint(constraintName) end

---@return spine.PhysicsConstraint # May be NULL.
---@param constraintName any
function Skeleton:findPhysicsConstraint(constraintName) end

---@return spine.Slot # May be NULL.
---@param slotName any
function Skeleton:findSlot(slotName) end

---@return spine.TransformConstraint # May be NULL.
---@param constraintName any
function Skeleton:findTransformConstraint(constraintName) end

---@return spine.Attachment # May be NULL.
---@param slotName any
---@param attachmentName any
---@overload fun(self: spine.Skeleton, slotIndex: integer, attachmentName: any): spine.Attachment
function Skeleton:getAttachment(slotName, attachmentName) end

---@return any
function Skeleton:getBones() end

---@return any
function Skeleton:getColor() end

---@return spine.SkeletonData
function Skeleton:getData() end

---@return any
function Skeleton:getDrawOrder() end

---@return any
function Skeleton:getIkConstraints() end

---@return any
function Skeleton:getPathConstraints() end

---@return any
function Skeleton:getPhysicsConstraints() end

---@return spine.Bone
function Skeleton:getRootBone() end

---@return number
function Skeleton:getScaleX() end

---@return number
function Skeleton:getScaleY() end

---@return spine.Skin
function Skeleton:getSkin() end

---@return any
function Skeleton:getSlots() end

---@return number
function Skeleton:getTime() end

---@return any
function Skeleton:getTransformConstraints() end

---@return any
function Skeleton:getUpdateCacheList() end

---@return number
function Skeleton:getX() end

---@return number
function Skeleton:getY() end

---@param skeletonData spine.SkeletonData
---@return spine.Skeleton
function Skeleton.new(skeletonData) end

---Calls {@link PhysicsConstraint#rotate(float, float, float)} for each physics constraint.
---@param x number
---@param y number
---@param degrees number
function Skeleton:physicsRotate(x, y, degrees) end

---Rotates the physics constraint so next {@link #update(Physics)} forces are applied as if the bone rotated around the
---specified point in world space.
---@param x number
---@param y number
function Skeleton:physicsTranslate(x, y) end

function Skeleton:printUpdateCache() end

---@param attachmentName any # May be empty.
---@param slotName any
function Skeleton:setAttachment(slotName, attachmentName) end

---Sets the bones and constraints to their setup pose values.
function Skeleton:setBonesToSetupPose() end

---@param x number
---@param y number
function Skeleton:setPosition(x, y) end

---@param inValue number
function Skeleton:setScaleX(inValue) end

---@param inValue number
function Skeleton:setScaleY(inValue) end

---Sets a skin by name (see setSkin).
---@param skinName any
---
---Attachments from the new skin are attached if the corresponding attachment from the old skin was attached.
---If there was no old skin, each slot's setup mode attachment is attached from the new skin.
---After changing the skin, the visible attachments can be reset to those attached in the setup pose by calling
---See Skeleton::setSlotsToSetupPose()
---Also, often AnimationState::apply(Skeleton&) is called before the next time the
---skeleton is rendered to allow any attachment keys in the current animation(s) to hide or show attachments from the new skin.
---\param newSkin May be NULL.
---@overload fun(self: spine.Skeleton, newSkin: spine.Skin)
function Skeleton:setSkin(skinName) end

function Skeleton:setSlotsToSetupPose() end

---@param time number
function Skeleton:setTime(time) end

---Sets the bones, constraints, and slots to their setup pose values.
function Skeleton:setToSetupPose() end

---@param inValue number
function Skeleton:setX(inValue) end

---@param inValue number
function Skeleton:setY(inValue) end

---@param delta number
function Skeleton:update(delta) end

---Caches information about bones and constraints. Must be called if bones, constraints or weighted path attachments are added
---or removed.
function Skeleton:updateCache() end

---Updates the world transform for each bone and applies all constraints.
---
---See [World transforms](http://esotericsoftware.com/spine-runtime-skeletons#World-transforms) in the Spine
---Runtimes Guide.
---@param physics spine.Physics
---@overload fun(self: spine.Skeleton, physics: spine.Physics, parent: spine.Bone)
function Skeleton:updateWorldTransform(physics) end

return Skeleton