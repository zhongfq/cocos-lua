---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.ContactImpulse

---Contact impulses for reporting. Impulses are used instead of forces because
---sub-step forces may approach infinity for rigid body collisions. These
---match up one-to-one with the contact points in b2Manifold.
---@class b2.ContactImpulse 
---@field count integer
local ContactImpulse = {}

---@return any
function ContactImpulse:__gc() end

return ContactImpulse