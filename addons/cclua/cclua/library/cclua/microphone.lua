---AUTO GENERATED, DO NOT MODIFY!
---@meta cclua.microphone

---
---@class cclua.microphone 
---@field running boolean 
local microphone = {}

---@return any
function microphone:__gc() end

---@param event string
---@param data any
function microphone.dispatch(event, data) end

---@return boolean
function microphone.isRunning() end

---@param dispatcher cclua.Callback
function microphone.setDispatcher(dispatcher) end

---@param path string
function microphone.start(path) end

function microphone.stop() end

return microphone