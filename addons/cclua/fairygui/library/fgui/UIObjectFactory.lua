---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.UIObjectFactory

---
---@class fgui.UIObjectFactory 
local UIObjectFactory = {}

---@return any
function UIObjectFactory:__gc() end

---@param pi fgui.PackageItem
---@return fgui.GObject
---@overload fun(type: fgui.ObjectType): fgui.GObject
function UIObjectFactory.newObject(pi) end

---@param creator fgui.UIObjectFactory.GLoaderCreator
function UIObjectFactory.setLoaderExtension(creator) end

---@param url string
---@param creator fgui.UIObjectFactory.GComponentCreator
function UIObjectFactory.setPackageItemExtension(url, creator) end

return UIObjectFactory