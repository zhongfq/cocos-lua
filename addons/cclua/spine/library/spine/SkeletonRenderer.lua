---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.SkeletonRenderer

---
---@class spine.SkeletonRenderer : cc.Node
---@field blendFunc cc.BlendFunc 
---@field debugBonesEnabled boolean 
---@field debugBoundingRectEnabled boolean 
---@field debugMeshesEnabled boolean 
---@field debugSlotsEnabled boolean 
---@field skeleton spine.Skeleton 
---@field timeScale number 
---@field twoColorTint boolean 
local SkeletonRenderer = {}

---@param cls string
---@return any
function SkeletonRenderer:as(cls) end

---@return spine.SkeletonRenderer
function SkeletonRenderer.create() end

---@param skeletonData spine.SkeletonData
---@param ownsSkeletonData boolean
---@return spine.SkeletonRenderer
---@overload fun(skeletonData: spine.SkeletonData): spine.SkeletonRenderer
function SkeletonRenderer.createWithData(skeletonData, ownsSkeletonData) end

---@param skeletonDataFile string
---@param atlas spine.Atlas
---@param scale number
---@return spine.SkeletonRenderer
---@overload fun(skeletonDataFile: string, atlas: spine.Atlas): spine.SkeletonRenderer
---@overload fun(skeletonDataFile: string, atlasFile: string, scale: number): spine.SkeletonRenderer
---@overload fun(skeletonDataFile: string, atlasFile: string): spine.SkeletonRenderer
function SkeletonRenderer.createWithFile(skeletonDataFile, atlas, scale) end

---@param skeleton spine.Skeleton
---@param ownsSkeleton boolean
---@param ownsSkeletonData boolean
---@return spine.SkeletonRenderer
---@overload fun(skeleton: spine.Skeleton): spine.SkeletonRenderer
---@overload fun(skeleton: spine.Skeleton, ownsSkeleton: boolean): spine.SkeletonRenderer
function SkeletonRenderer.createWithSkeleton(skeleton, ownsSkeleton, ownsSkeletonData) end

---@param boneName string
---@return spine.Bone
function SkeletonRenderer:findBone(boneName) end

---@param slotName string
---@return spine.Slot
function SkeletonRenderer:findSlot(slotName) end

---@param slotName string
---@param attachmentName string
---@return spine.Attachment
function SkeletonRenderer:getAttachment(slotName, attachmentName) end

---@return cc.BlendFunc
function SkeletonRenderer:getBlendFunc() end

---@return boolean
function SkeletonRenderer:getDebugBonesEnabled() end

---@return boolean
function SkeletonRenderer:getDebugBoundingRectEnabled() end

---@return boolean
function SkeletonRenderer:getDebugMeshesEnabled() end

---@return boolean
function SkeletonRenderer:getDebugSlotsEnabled() end

---@return spine.Skeleton
function SkeletonRenderer:getSkeleton() end

---@return number
function SkeletonRenderer:getTimeScale() end

---@param skeletonDataFile string
---@param atlas spine.Atlas
---@param scale number
---@overload fun(self: spine.SkeletonRenderer, skeletonDataFile: string, atlas: spine.Atlas)
---@overload fun(self: spine.SkeletonRenderer, skeletonDataFile: string, atlasFile: string, scale: number)
---@overload fun(self: spine.SkeletonRenderer, skeletonDataFile: string, atlasFile: string)
function SkeletonRenderer:initWithBinaryFile(skeletonDataFile, atlas, scale) end

---@param skeletonData spine.SkeletonData
---@param ownsSkeletonData boolean
---@overload fun(self: spine.SkeletonRenderer, skeletonData: spine.SkeletonData)
function SkeletonRenderer:initWithData(skeletonData, ownsSkeletonData) end

---@param skeletonDataFile string
---@param atlas spine.Atlas
---@param scale number
---@overload fun(self: spine.SkeletonRenderer, skeletonDataFile: string, atlas: spine.Atlas)
---@overload fun(self: spine.SkeletonRenderer, skeletonDataFile: string, atlasFile: string, scale: number)
---@overload fun(self: spine.SkeletonRenderer, skeletonDataFile: string, atlasFile: string)
function SkeletonRenderer:initWithJsonFile(skeletonDataFile, atlas, scale) end

---@param skeleton spine.Skeleton
---@param ownsSkeleton boolean
---@param ownsSkeletonData boolean
---@param ownsAtlas boolean
---@overload fun(self: spine.SkeletonRenderer, skeleton: spine.Skeleton)
---@overload fun(self: spine.SkeletonRenderer, skeleton: spine.Skeleton, ownsSkeleton: boolean)
---@overload fun(self: spine.SkeletonRenderer, skeleton: spine.Skeleton, ownsSkeleton: boolean, ownsSkeletonData: boolean)
function SkeletonRenderer:initWithSkeleton(skeleton, ownsSkeleton, ownsSkeletonData, ownsAtlas) end

function SkeletonRenderer:initialize() end

---@return boolean
function SkeletonRenderer:isTwoColorTint() end

---@return spine.SkeletonRenderer
---@overload fun(skeleton: spine.Skeleton, ownsSkeleton: boolean, ownsSkeletonData: boolean, ownsAtlas: boolean): spine.SkeletonRenderer
---@overload fun(skeleton: spine.Skeleton): spine.SkeletonRenderer
---@overload fun(skeleton: spine.Skeleton, ownsSkeleton: boolean): spine.SkeletonRenderer
---@overload fun(skeleton: spine.Skeleton, ownsSkeleton: boolean, ownsSkeletonData: boolean): spine.SkeletonRenderer
---@overload fun(skeletonData: spine.SkeletonData, ownsSkeletonData: boolean): spine.SkeletonRenderer
---@overload fun(skeletonData: spine.SkeletonData): spine.SkeletonRenderer
---@overload fun(skeletonDataFile: string, atlas: spine.Atlas, scale: number): spine.SkeletonRenderer
---@overload fun(skeletonDataFile: string, atlas: spine.Atlas): spine.SkeletonRenderer
---@overload fun(skeletonDataFile: string, atlasFile: string, scale: number): spine.SkeletonRenderer
---@overload fun(skeletonDataFile: string, atlasFile: string): spine.SkeletonRenderer
function SkeletonRenderer.new() end

---@param slotName string
---@param attachmentName string
---@return boolean
---@overload fun(self: spine.SkeletonRenderer, slotName: string, attachmentName: string): boolean
function SkeletonRenderer:setAttachment(slotName, attachmentName) end

---@param blendFunc cc.BlendFunc
function SkeletonRenderer:setBlendFunc(blendFunc) end

function SkeletonRenderer:setBonesToSetupPose() end

---@param enabled boolean
function SkeletonRenderer:setDebugBonesEnabled(enabled) end

---@param enabled boolean
function SkeletonRenderer:setDebugBoundingRectEnabled(enabled) end

---@param enabled boolean
function SkeletonRenderer:setDebugMeshesEnabled(enabled) end

---@param enabled boolean
function SkeletonRenderer:setDebugSlotsEnabled(enabled) end

---@param skinName string
---
---\param skin May be 0 for no skin.
---@overload fun(self: spine.SkeletonRenderer, skinName: string)
function SkeletonRenderer:setSkin(skinName) end

---@param startSlotIndex integer
---@param endSlotIndex integer
function SkeletonRenderer:setSlotsRange(startSlotIndex, endSlotIndex) end

function SkeletonRenderer:setSlotsToSetupPose() end

---@param scale number
function SkeletonRenderer:setTimeScale(scale) end

function SkeletonRenderer:setToSetupPose() end

---@param enabled boolean
function SkeletonRenderer:setTwoColorTint(enabled) end

---@param physics spine.Physics
function SkeletonRenderer:updateWorldTransform(physics) end

return SkeletonRenderer