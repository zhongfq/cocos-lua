---AUTO GENERATED, DO NOT MODIFY!
---@meta ccb.DeviceInfo

---Used to query features and implementation limits
---@class ccb.DeviceInfo 
---@field extension string get extensions. \return Extension supported by device.
---@field maxAttributes integer Get maximum attribute counts. \return Maximum attribute counts.
---@field maxSamplesAllowed integer Get maximum sampler count. \return Maximum sampler count.
---@field maxTextureSize integer Get maximum texture size. \return Maximum texture size.
---@field maxTextureUnits integer Get maximum texture unit. \return Maximum texture unit.
---@field renderer string Get the full name of the vendor device. \return The full name of the vendor device.
---@field vendor string Get vendor device name. \return Vendor device name.
---@field version string Get version name. \return Version name.
local DeviceInfo = {}

---@return any
function DeviceInfo:__gc() end

---Check if feature supported by device.
---@param feature ccb.FeatureType # Specify feature to be query.
---@return boolean # true if the feature is supported, false otherwise.
function DeviceInfo:checkForFeatureSupported(feature) end

---get extensions.
---@return string # Extension supported by device.
function DeviceInfo:getExtension() end

---Get maximum attribute counts.
---@return integer # Maximum attribute counts.
function DeviceInfo:getMaxAttributes() end

---Get maximum sampler count.
---@return integer # Maximum sampler count.
function DeviceInfo:getMaxSamplesAllowed() end

---Get maximum texture size.
---@return integer # Maximum texture size.
function DeviceInfo:getMaxTextureSize() end

---Get maximum texture unit.
---@return integer # Maximum texture unit.
function DeviceInfo:getMaxTextureUnits() end

---Get the full name of the vendor device.
---@return string # The full name of the vendor device.
function DeviceInfo:getRenderer() end

---Get vendor device name.
---@return string # Vendor device name.
function DeviceInfo:getVendor() end

---Get version name.
---@return string # Version name.
function DeviceInfo:getVersion() end

---Gather features and implementation limits
---@return boolean
function DeviceInfo:init() end

return DeviceInfo