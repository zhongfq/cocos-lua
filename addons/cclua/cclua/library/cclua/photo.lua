---AUTO GENERATED, DO NOT MODIFY!
---@meta cclua.photo

---
---@class cclua.photo 
local photo = {}

---@return any
function photo:__gc() end

---@param event string
---@param data any
function photo.dispatch(event, data) end

---@param cachePath string
function photo.select(cachePath) end

---@param cachePath string
---@param width integer
---@param height integer
function photo.selectAvatar(cachePath, width, height) end

---@param dispatcher cclua.Callback
function photo.setDispatcher(dispatcher) end

---@param cachePath string
---@param width integer
---@param height integer
function photo.takeAvatar(cachePath, width, height) end

return photo