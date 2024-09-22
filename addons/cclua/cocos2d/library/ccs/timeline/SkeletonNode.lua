---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.timeline.SkeletonNode

---
---@class ccs.timeline.SkeletonNode : ccs.timeline.BoneNode
---@field allSubBonesMap any get All bones in this skeleton, <bone's name, BoneNode>
local SkeletonNode = {}

---: add a boneSkinNameMap as a SkinGroup named groupName
---\param: groupName, key
---\param: boneSkinNameMap, map <name of bone, name of skin to display which added to bone>
---@param groupName string
---@param boneSkinNameMap { [string]: string }
function SkeletonNode:addSkinGroup(groupName, boneSkinNameMap) end

---: change displays 
---\param: boneSkinNameMap, map <name of bone, name of skin to display which added to bone>
---@param boneSkinNameMap { [string]: string }
---
---: change displays
---\param: skinGroupName have
---@overload fun(self: ccs.timeline.SkeletonNode, skinGroupName: string)
function SkeletonNode:changeSkins(boneSkinNameMap) end

---@return ccs.timeline.SkeletonNode
function SkeletonNode.create() end

---get All bones in this skeleton, <bone's name, BoneNode>
---@return any
function SkeletonNode:getAllSubBonesMap() end

---get bonenode in skeleton node by bone name
---@param boneName string
---@return ccs.timeline.BoneNode
function SkeletonNode:getBoneNode(boneName) end

---@return ccs.timeline.SkeletonNode
function SkeletonNode.new() end

return SkeletonNode