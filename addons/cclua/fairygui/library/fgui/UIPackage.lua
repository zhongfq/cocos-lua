---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.UIPackage

---
---@class fgui.UIPackage : cc.Ref
---@field branch string 
---@field emptyTexture cc.Texture2D 
---@field id string 
---@field name string 
---@field URL_PREFIX string
local UIPackage = {}

---@param descFilePath string
---@return fgui.UIPackage
function UIPackage.addPackage(descFilePath) end

---@param pkgName string
---@param resName string
---@return fgui.GObject
function UIPackage.createObject(pkgName, resName) end

---@param url string
---@return fgui.GObject
function UIPackage.createObjectFromURL(url) end

---@return string
function UIPackage.getBranch() end

---@param id string
---@return fgui.UIPackage
function UIPackage.getById(id) end

---@param name string
---@return fgui.UIPackage
function UIPackage.getByName(name) end

---@return cc.Texture2D
function UIPackage.getEmptyTexture() end

---@return string
function UIPackage:getId() end

---@param itemId string
---@return fgui.PackageItem
function UIPackage:getItem(itemId) end

---@param pkgName string
---@param resName string
---@param type fgui.PackageItemType
---@return any
---@overload fun(pkgName: string, resName: string): any
---@overload fun(self: fgui.UIPackage, item: fgui.PackageItem): any
function UIPackage.getItemAsset(pkgName, resName, type) end

---@param url string
---@param type fgui.PackageItemType
---@return any
---@overload fun(url: string): any
function UIPackage.getItemAssetByURL(url, type) end

---@param itemName string
---@return fgui.PackageItem
function UIPackage:getItemByName(itemName) end

---@param url string
---@return fgui.PackageItem
function UIPackage.getItemByURL(url) end

---@param pkgName string
---@param resName string
---@return string
function UIPackage.getItemURL(pkgName, resName) end

---@return string
function UIPackage:getName() end

---@param key string
---@return string
function UIPackage.getVar(key) end

---@return fgui.UIPackage
function UIPackage.new() end

---@param url string
---@return string
function UIPackage.normalizeURL(url) end

function UIPackage.removeAllPackages() end

---@param packageIdOrName string
function UIPackage.removePackage(packageIdOrName) end

---@param value string
function UIPackage.setBranch(value) end

---@param key string
---@param value string
function UIPackage.setVar(key, value) end

return UIPackage