---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.PackageItem

---
---@class fgui.PackageItem : cc.Ref
---@field branch fgui.PackageItem 
---@field highResolution fgui.PackageItem 
---@field owner fgui.UIPackage
---@field type fgui.PackageItemType
---@field objectType fgui.ObjectType
---@field id string
---@field name string
---@field width integer
---@field height integer
---@field file string
---@field branches cc.types.VectorString
---@field texture cc.Texture2D
---@field scaleByTile boolean
---@field tileGridIndice integer
---@field spriteFrame cc.SpriteFrame
---@field animation cc.Animation
---@field delayPerUnit number
---@field repeatDelay number
---@field swing boolean
---@field translated boolean
---@field skeletonAnchor cc.Vec2
local PackageItem = {}

---@return fgui.PackageItem
function PackageItem:getBranch() end

---@return fgui.PackageItem
function PackageItem:getHighResolution() end

function PackageItem:load() end

---@return fgui.PackageItem
function PackageItem.new() end

return PackageItem