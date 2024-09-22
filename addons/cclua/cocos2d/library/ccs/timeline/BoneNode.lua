---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.timeline.BoneNode

---
---@class ccs.timeline.BoneNode : cc.Node
---@field allSubBones any : get all bones in this bone tree
---@field allSubSkins any : get all skins in this bone tree
---@field blendFunc cc.BlendFunc 
---@field childBones any 
---@field debugDrawColor any 
---@field debugDrawEnabled boolean 
---@field debugDrawLength number 
---@field debugDrawWidth number 
---@field rootSkeletonNode ccs.timeline.SkeletonNode 
---@field skins any get skins in this bone's children
---@field visibleSkins any 
---@field visibleSkinsRect cc.Rect get displayings rect in self transform
local BoneNode = {}

---: add a skin
---\param: display, whether display this skin
---@param skin cc.Node
---@param display boolean
---
---: add a skin
---\param: display, whether display this skin
---\param: hideOthers, whether hide other skins added to this bone
---@overload fun(self: ccs.timeline.BoneNode, skin: cc.Node, display: boolean, hideOthers: boolean)
function BoneNode:addSkin(skin, display) end

---@param cls string
---@return any
function BoneNode:as(cls) end

---@return ccs.timeline.BoneNode
---@overload fun(length: integer): ccs.timeline.BoneNode
function BoneNode.create() end

---: display skin
---\param: hideOthers, set other skins invisible
---@param skin cc.Node
---@param hideOthers boolean
---
---: display all skins named skinName, if hide display only one skin,
---prefer to use display(SkinNode* skin, bool hideOthers = false)
---\param: hideOthers, set other skins invisible
---@overload fun(self: ccs.timeline.BoneNode, skinName: string, hideOthers: boolean)
function BoneNode:displaySkin(skin, hideOthers) end

---: get all bones in this bone tree
---@return any
function BoneNode:getAllSubBones() end

---: get all skins in this bone tree
---@return any
function BoneNode:getAllSubSkins() end

---@return cc.BlendFunc
function BoneNode:getBlendFunc() end

---@return any
function BoneNode:getChildBones() end

---@return any
function BoneNode:getDebugDrawColor() end

---@return number
function BoneNode:getDebugDrawLength() end

---@return number
function BoneNode:getDebugDrawWidth() end

---@return ccs.timeline.SkeletonNode
function BoneNode:getRootSkeletonNode() end

---get skins in this bone's children
---@return any
function BoneNode:getSkins() end

---@return any
function BoneNode:getVisibleSkins() end

---get displayings rect in self transform
---@return cc.Rect
function BoneNode:getVisibleSkinsRect() end

---@return boolean
function BoneNode:isDebugDrawEnabled() end

---@return ccs.timeline.BoneNode
function BoneNode.new() end

---@param blendFunc cc.BlendFunc
function BoneNode:setBlendFunc(blendFunc) end

---@param color any
function BoneNode:setDebugDrawColor(color) end

---@param isDebugDraw boolean
function BoneNode:setDebugDrawEnabled(isDebugDraw) end

---@param length number
function BoneNode:setDebugDrawLength(length) end

---@param width number
function BoneNode:setDebugDrawWidth(width) end

---@param localZOrder integer
function BoneNode:setLocalZOrder(localZOrder) end

return BoneNode