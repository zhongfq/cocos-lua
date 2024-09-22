---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.Bone

---Stores a bone's current pose.
---
---A bone has a local transform which is used to compute its world transform. A bone also has an applied transform, which is a
---local transform that can be applied to compute the world transform. The local transform and applied transform may differ if a
---constraint or application code modifies the world transform after it was computed from the local transform.
---@class spine.Bone : spine.Updatable
---@field a number 
---@field aScaleX number The applied local scaleX.
---@field aScaleY number The applied local scaleY.
---@field aShearX number The applied local shearX.
---@field aShearY number The applied local shearY.
---@field appliedRotation number The rotation, as calculated by any constraints.
---@field ax number The applied local x translation.
---@field ay number The applied local y translation.
---@field b number 
---@field c number 
---@field children any 
---@field d number 
---@field data spine.BoneData 
---@field inherit spine.Inherit 
---@field parent spine.Bone 
---@field rotation number The local rotation.
---@field scaleX number The local scaleX.
---@field scaleY number The local scaleY.
---@field shearX number The local shearX.
---@field shearY number The local shearY.
---@field skeleton spine.Skeleton 
---@field worldRotationX number 
---@field worldRotationY number 
---@field worldScaleX number Returns the magnitide (always positive) of the world scale X.
---@field worldScaleY number Returns the magnitide (always positive) of the world scale Y.
---@field worldToLocalRotationX number 
---@field worldToLocalRotationY number 
---@field worldX number 
---@field worldY number 
---@field x number The local X translation.
---@field y number The local Y translation.
---@field yDown boolean 
local Bone = {}

---@return number
function Bone:getA() end

---The applied local scaleX.
---@return number
function Bone:getAScaleX() end

---The applied local scaleY.
---@return number
function Bone:getAScaleY() end

---The applied local shearX.
---@return number
function Bone:getAShearX() end

---The applied local shearY.
---@return number
function Bone:getAShearY() end

---The applied local x translation.
---@return number
function Bone:getAX() end

---The applied local y translation.
---@return number
function Bone:getAY() end

---The rotation, as calculated by any constraints.
---@return number
function Bone:getAppliedRotation() end

---@return number
function Bone:getB() end

---@return number
function Bone:getC() end

---@return any
function Bone:getChildren() end

---@return number
function Bone:getD() end

---@return spine.BoneData
function Bone:getData() end

---@return spine.Inherit
function Bone:getInherit() end

---@return spine.Bone
function Bone:getParent() end

---The local rotation.
---@return number
function Bone:getRotation() end

---The local scaleX.
---@return number
function Bone:getScaleX() end

---The local scaleY.
---@return number
function Bone:getScaleY() end

---The local shearX.
---@return number
function Bone:getShearX() end

---The local shearY.
---@return number
function Bone:getShearY() end

---@return spine.Skeleton
function Bone:getSkeleton() end

---@return number
function Bone:getWorldRotationX() end

---@return number
function Bone:getWorldRotationY() end

---Returns the magnitide (always positive) of the world scale X.
---@return number
function Bone:getWorldScaleX() end

---Returns the magnitide (always positive) of the world scale Y.
---@return number
function Bone:getWorldScaleY() end

---@return number
function Bone:getWorldToLocalRotationX() end

---@return number
function Bone:getWorldToLocalRotationY() end

---@return number
function Bone:getWorldX() end

---@return number
function Bone:getWorldY() end

---The local X translation.
---@return number
function Bone:getX() end

---The local Y translation.
---@return number
function Bone:getY() end

---@return boolean
function Bone.isYDown() end

---@param localRotation number
---@return number
function Bone:localToWorldRotation(localRotation) end

---@param parent spine.Bone # May be NULL.
---@param data spine.BoneData
---@param skeleton spine.Skeleton
---@return spine.Bone
---@overload fun(data: spine.BoneData, skeleton: spine.Skeleton): spine.Bone
function Bone.new(data, skeleton, parent) end

---@param worldX number
---@param worldY number
---@param outX olua.float
---@param outY olua.float
function Bone:parentToWorld(worldX, worldY, outX, outY) end

---Rotates the world transform the specified amount and sets isAppliedValid to false.
---@param degrees number # Degrees.
function Bone:rotateWorld(degrees) end

---@param inValue number
function Bone:setA(inValue) end

---@param inValue number
function Bone:setAScaleX(inValue) end

---@param inValue number
function Bone:setAScaleY(inValue) end

---@param inValue number
function Bone:setAShearX(inValue) end

---@param inValue number
function Bone:setAShearY(inValue) end

---@param inValue number
function Bone:setAX(inValue) end

---@param inValue number
function Bone:setAY(inValue) end

---@param inValue number
function Bone:setAppliedRotation(inValue) end

---@param inValue number
function Bone:setB(inValue) end

---@param inValue number
function Bone:setC(inValue) end

---@param inValue number
function Bone:setD(inValue) end

---@param inValue spine.Inherit
function Bone:setInherit(inValue) end

---@param inValue number
function Bone:setRotation(inValue) end

---@param inValue number
function Bone:setScaleX(inValue) end

---@param inValue number
function Bone:setScaleY(inValue) end

---@param inValue number
function Bone:setShearX(inValue) end

---@param inValue number
function Bone:setShearY(inValue) end

function Bone:setToSetupPose() end

---@param inValue number
function Bone:setWorldX(inValue) end

---@param inValue number
function Bone:setWorldY(inValue) end

---@param inValue number
function Bone:setX(inValue) end

---@param inValue number
function Bone:setY(inValue) end

---@param inValue boolean
function Bone.setYDown(inValue) end

---Computes the individual applied transform values from the world transform. This can be useful to perform processing using
---the applied transform after the world transform has been modified directly (eg, by a constraint)..
---
---Some information is ambiguous in the world transform, such as -1,-1 scale versus 180 rotation.
function Bone:updateAppliedTransform() end

---Computes the world transform using the parent bone and this bone's local transform.
---
---Computes the world transform using the parent bone and the specified local transform.
---@overload fun(self: spine.Bone, x: number, y: number, rotation: number, scaleX: number, scaleY: number, shearX: number, shearY: number)
function Bone:updateWorldTransform() end

---@param worldRotation number
---@return number
function Bone:worldToLocalRotation(worldRotation) end

---@param worldX number
---@param worldY number
---@param outParentX olua.float
---@param outParentY olua.float
function Bone:worldToParent(worldX, worldY, outParentX, outParentY) end

return Bone