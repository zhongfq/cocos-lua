---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.SpriteFrameCacheHelper

---\js NA
---\lua NA
---@class ccs.SpriteFrameCacheHelper 
---@field instance ccs.SpriteFrameCacheHelper 
local SpriteFrameCacheHelper = {}

---Add sprite frame to CCSpriteFrameCache, it will save display name and it's relative image name
---@param plistPath string
---@param imagePath string
function SpriteFrameCacheHelper:addSpriteFrameFromFile(plistPath, imagePath) end

---@return ccs.SpriteFrameCacheHelper
function SpriteFrameCacheHelper.getInstance() end

function SpriteFrameCacheHelper.purge() end

---@param plistPath string
function SpriteFrameCacheHelper:removeSpriteFrameFromFile(plistPath) end

return SpriteFrameCacheHelper