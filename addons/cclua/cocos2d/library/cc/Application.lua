---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Application

---
---@class cc.Application : cc.ApplicationProtocol
---@field instance cc.Application Get current application instance. \return Current application instance pointer.
local Application = {}

---Get current application instance.
---@return cc.Application # Current application instance pointer.
function Application.getInstance() end

---Run the message loop.
---@return integer
function Application:run() end

return Application