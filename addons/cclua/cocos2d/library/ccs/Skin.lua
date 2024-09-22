---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.Skin

---
---@class ccs.Skin : cc.Sprite
---@field bone ccs.Bone 
---@field displayName string 
---@field nodeToWorldTransformAR cc.Mat4 
---@field skinData ccs.BaseData \js NA \lua NA
local Skin = {}

---@return ccs.Skin
---@overload fun(pszFileName: string): ccs.Skin
function Skin.create() end

---@param pszSpriteFrameName string
---@return ccs.Skin
function Skin.createWithSpriteFrameName(pszSpriteFrameName) end

---@return ccs.Bone
function Skin:getBone() end

---@return string
function Skin:getDisplayName() end

---@return cc.Mat4
function Skin:getNodeToWorldTransformAR() end

---\js NA
---\lua NA
---@return ccs.BaseData
function Skin:getSkinData() end

---\js ctor
---@return ccs.Skin
function Skin.new() end

---@param bone ccs.Bone
function Skin:setBone(bone) end

---\js NA
---\lua NA
---@param data ccs.BaseData
function Skin:setSkinData(data) end

function Skin:updateArmatureTransform() end

return Skin