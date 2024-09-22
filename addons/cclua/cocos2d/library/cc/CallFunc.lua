---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.CallFunc

---\class CallFunc
---Calls a 'callback'.
---@class cc.CallFunc : cc.ActionInstant
local CallFunc = {}

---Creates the action with the callback of type std::function<void()>.
---This is the preferred way to create the callback.
---When this function bound in js or lua ,the input param will be changed.
---In js: var create(var func, var this, var [data]) or var create(var func).
---In lua:local create(local funcID).
---
---@param func fun() # A callback function need to be executed.
---@return cc.CallFunc # An autoreleased CallFunc object.
function CallFunc.create(func) end

---Executes the callback.
function CallFunc:execute() end

return CallFunc