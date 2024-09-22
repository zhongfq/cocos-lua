---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.Contact

---The class manages contact between two shapes. A contact exists for each overlapping
---AABB in the broad-phase (except if filtered). Therefore a contact object may exist
---that has no contact points.
---@class b2.Contact 
---@field childIndexA integer Get the child primitive index for fixture A.
---@field childIndexB integer Get the child primitive index for fixture B.
---@field enabled boolean Has this contact been disabled?
---@field fixtureA b2.Fixture Get fixture A in this contact.
---@field fixtureB b2.Fixture Get fixture B in this contact.
---@field friction number Get the friction.
---@field manifold b2.Manifold Get the contact manifold. Do not modify the manifold unless you understand the internals of Box2D.
---@field next b2.Contact Get the next contact in the world's contact list.
---@field restitution number Get the restitution.
---@field restitutionThreshold number Get the restitution threshold.
---@field tangentSpeed number Get the desired tangent speed. In meters per second.
---@field touching boolean Is this contact touching?
local Contact = {}

---Evaluate this contact with your own manifold and transforms.
---@param manifold b2.Manifold
---@param xfA b2.Transform
---@param xfB b2.Transform
function Contact:evaluate(manifold, xfA, xfB) end

---Get the child primitive index for fixture A.
---@return integer
function Contact:getChildIndexA() end

---Get the child primitive index for fixture B.
---@return integer
function Contact:getChildIndexB() end

---Get fixture A in this contact.
---@return b2.Fixture
function Contact:getFixtureA() end

---Get fixture B in this contact.
---@return b2.Fixture
function Contact:getFixtureB() end

---Get the friction.
---@return number
function Contact:getFriction() end

---Get the contact manifold. Do not modify the manifold unless you understand the
---internals of Box2D.
---@return b2.Manifold
function Contact:getManifold() end

---Get the next contact in the world's contact list.
---@return b2.Contact
function Contact:getNext() end

---Get the restitution.
---@return number
function Contact:getRestitution() end

---Get the restitution threshold.
---@return number
function Contact:getRestitutionThreshold() end

---Get the desired tangent speed. In meters per second.
---@return number
function Contact:getTangentSpeed() end

---Get the world manifold.
---@param worldManifold b2.WorldManifold
function Contact:getWorldManifold(worldManifold) end

---Has this contact been disabled?
---@return boolean
function Contact:isEnabled() end

---Is this contact touching?
---@return boolean
function Contact:isTouching() end

---Reset the friction mixture to the default value.
function Contact:resetFriction() end

---Reset the restitution to the default value.
function Contact:resetRestitution() end

---Reset the restitution threshold to the default value.
function Contact:resetRestitutionThreshold() end

---Enable/disable this contact. This can be used inside the pre-solve
---contact listener. The contact is only disabled for the current
---time step (or sub-step in continuous collisions).
---@param flag boolean
function Contact:setEnabled(flag) end

---Override the default friction mixture. You can call this in b2ContactListener::PreSolve.
---This value persists until set or reset.
---@param friction number
function Contact:setFriction(friction) end

---Override the default restitution mixture. You can call this in b2ContactListener::PreSolve.
---The value persists until you set or reset.
---@param restitution number
function Contact:setRestitution(restitution) end

---Override the default restitution velocity threshold mixture. You can call this in b2ContactListener::PreSolve.
---The value persists until you set or reset.
---@param threshold number
function Contact:setRestitutionThreshold(threshold) end

---Set the desired tangent speed for a conveyor belt behavior. In meters per second.
---@param speed number
function Contact:setTangentSpeed(speed) end

return Contact