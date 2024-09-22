---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Controller

---\class Controller
---A Controller object represents a connected physical game controller.
---\js NA
---@class cc.Controller 
---@field allController cc.Controller[] Gets all Controller objects.
---@field connected boolean Indicates whether the Controller is connected.
---@field deviceId integer Gets the Controller id.
---@field deviceName string Gets the name of this Controller object.
---@field tag integer Returns a tag that is used to identify the controller easily. <br><br>\return An integer that identifies the controller.
---@field TAG_UNSET integer
local Controller = {}

---Gets all Controller objects.
---@return cc.Controller[]
function Controller.getAllController() end

---Gets a Controller object with device ID.
---
---@param deviceId integer # A unique identifier to find the controller.
---@return cc.Controller # A Controller object.
function Controller.getControllerByDeviceId(deviceId) end

---Gets a Controller object with tag.
---
---@param tag integer # An identifier to find the controller.
---@return cc.Controller # A Controller object.
function Controller.getControllerByTag(tag) end

---Gets the Controller id.
---@return integer
function Controller:getDeviceId() end

---Gets the name of this Controller object.
---@return string
function Controller:getDeviceName() end

---@param keyCode integer
---@return cc.Controller.KeyStatus
function Controller:getKeyStatus(keyCode) end

---Returns a tag that is used to identify the controller easily.
---
---@return integer # An integer that identifies the controller.
function Controller:getTag() end

---Indicates whether the Controller is connected.
---@return boolean
function Controller:isConnected() end

---Changes the tag that is used to identify the controller easily.
---@param tag integer # A integer that identifies the controller.
function Controller:setTag(tag) end

---Start discovering new controllers.
---
---\warning The API has an empty implementation on Android.
function Controller.startDiscoveryController() end

---Stop the discovery process.
---
---\warning The API has an empty implementation on Android.
function Controller.stopDiscoveryController() end

return Controller