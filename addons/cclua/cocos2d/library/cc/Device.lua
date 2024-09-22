---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Device

---\class Device
---
---@class cc.Device 
---@field dpi integer Gets the DPI of device \return The DPI of device.
local Device = {}

---@return any
function Device:__gc() end

---Gets the DPI of device
---@return integer # The DPI of device.
function Device.getDPI() end

---To enable or disable accelerometer.
---@param isEnabled boolean
function Device.setAccelerometerEnabled(isEnabled) end

---Sets the interval of accelerometer.
---@param interval number
function Device.setAccelerometerInterval(interval) end

---Controls whether the screen should remain on.
---
---@param keepScreenOn boolean # One flag indicating that the screen should remain on.
function Device.setKeepScreenOn(keepScreenOn) end

---Vibrate for the specified amount of time.
---If vibrate is not supported, then invoking this method has no effect.
---Some platforms limit to a maximum duration of 5 seconds.
---Duration is ignored on iOS due to API limitations.
---@param duration number # The duration in seconds.
function Device.vibrate(duration) end

return Device