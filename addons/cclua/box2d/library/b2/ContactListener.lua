---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.ContactListener

---
---@class b2.ContactListener : b2.interface.ContactListener
---@field beginContact fun(arg1: b2.Contact)
---@field endContact fun(arg1: b2.Contact)
---@field preSolve fun(arg1: b2.Contact, arg2: b2.Manifold)
---@field postSolve fun(arg1: b2.Contact, arg2: b2.ContactImpulse)
local ContactListener = {}

---@return b2.ContactListener
function ContactListener.new() end

return ContactListener