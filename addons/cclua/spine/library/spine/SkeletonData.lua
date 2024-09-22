---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.SkeletonData

---Stores the setup pose and all of the stateless data for a skeleton.
---@class spine.SkeletonData : spine.SpineObject
---@field animations any 
---@field audioPath any 
---@field bones any The skeleton's bones, sorted parent first. The root bone is always the first bone.
---@field defaultSkin spine.Skin The skeleton's default skin. By default this skin contains all attachments that were not in a skin in Spine. \return May be NULL.
---@field events any 
---@field fps number The dopesheet FPS in Spine. Available only when nonessential data was exported.
---@field hash any 
---@field height number 
---@field ikConstraints any 
---@field imagesPath any 
---@field name any 
---@field pathConstraints any 
---@field physicsConstraints any 
---@field referenceScale number 
---@field skins any All skins, including the default skin.
---@field slots any 
---@field transformConstraints any 
---@field version any The Spine version used to export this data, or NULL.
---@field width number 
---@field x number 
---@field y number 
local SkeletonData = {}

---@return any
function SkeletonData.__gc() end

---@param skelPath string
---@param atlasPath string
---@param scale number
---@return any
---@overload fun(skelPath: string, atlasPath: string): any
function SkeletonData.create(skelPath, atlasPath, scale) end

---@return any
function SkeletonData.dispose() end

---@return spine.Animation # May be NULL.
---@param animationName any
function SkeletonData:findAnimation(animationName) end

---Finds a bone by comparing each bone's name.
---It is more efficient to cache the results of this method than to call it multiple times.
---@return spine.BoneData # May be NULL.
---@param boneName any
function SkeletonData:findBone(boneName) end

---@return spine.EventData # May be NULL.
---@param eventDataName any
function SkeletonData:findEvent(eventDataName) end

---@return spine.IkConstraintData # May be NULL.
---@param constraintName any
function SkeletonData:findIkConstraint(constraintName) end

---@return spine.PathConstraintData # May be NULL.
---@param constraintName any
function SkeletonData:findPathConstraint(constraintName) end

---@return spine.PhysicsConstraintData # May be NULL.
---@param constraintName any
function SkeletonData:findPhysicsConstraint(constraintName) end

---@return spine.Skin # May be NULL.
---@param skinName any
function SkeletonData:findSkin(skinName) end

---@return spine.SlotData # May be NULL.
---@param slotName any
function SkeletonData:findSlot(slotName) end

---@return spine.TransformConstraintData # May be NULL.
---@param constraintName any
function SkeletonData:findTransformConstraint(constraintName) end

---@return any
function SkeletonData:getAnimations() end

---@return any
function SkeletonData:getAudioPath() end

---The skeleton's bones, sorted parent first. The root bone is always the first bone.
---@return any
function SkeletonData:getBones() end

---The skeleton's default skin.
---By default this skin contains all attachments that were not in a skin in Spine.
---@return spine.Skin # May be NULL.
function SkeletonData:getDefaultSkin() end

---@return any
function SkeletonData:getEvents() end

---The dopesheet FPS in Spine. Available only when nonessential data was exported.
---@return number
function SkeletonData:getFps() end

---@return any
function SkeletonData:getHash() end

---@return number
function SkeletonData:getHeight() end

---@return any
function SkeletonData:getIkConstraints() end

---@return any
function SkeletonData:getImagesPath() end

---@return any
function SkeletonData:getName() end

---@return any
function SkeletonData:getPathConstraints() end

---@return any
function SkeletonData:getPhysicsConstraints() end

---@return number
function SkeletonData:getReferenceScale() end

---All skins, including the default skin.
---@return any
function SkeletonData:getSkins() end

---@return any
function SkeletonData:getSlots() end

---@return any
function SkeletonData:getTransformConstraints() end

---The Spine version used to export this data, or NULL.
---@return any
function SkeletonData:getVersion() end

---@return number
function SkeletonData:getWidth() end

---@return number
function SkeletonData:getX() end

---@return number
function SkeletonData:getY() end

---@param inValue any
function SkeletonData:setAudioPath(inValue) end

---@param inValue spine.Skin
function SkeletonData:setDefaultSkin(inValue) end

---@param inValue number
function SkeletonData:setFps(inValue) end

---@param inValue any
function SkeletonData:setHash(inValue) end

---@param inValue number
function SkeletonData:setHeight(inValue) end

---@param inValue any
function SkeletonData:setImagesPath(inValue) end

---@param inValue any
function SkeletonData:setName(inValue) end

---@param inValue number
function SkeletonData:setReferenceScale(inValue) end

---@param inValue any
function SkeletonData:setVersion(inValue) end

---@param inValue number
function SkeletonData:setWidth(inValue) end

---@param inValue number
function SkeletonData:setX(inValue) end

---@param inValue number
function SkeletonData:setY(inValue) end

return SkeletonData