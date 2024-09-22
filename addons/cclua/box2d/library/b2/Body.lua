---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.Body

---A rigid body. These are created via b2World::CreateBody.
---@class b2.Body 
---@field angle number Get the angle in radians. \return the current world rotation angle in radians.
---@field angularDamping number Get the angular damping of the body.
---@field angularVelocity number Get the angular velocity. \return the angular velocity in radians/second.
---@field awake boolean Get the sleeping state of this body. \return true if the body is awake.
---@field bullet boolean Is this body treated like a bullet for continuous collision detection?
---@field contactList b2.ContactEdge Get the list of all contacts attached to this body. \warning this list changes during the time step and you may miss some collisions if you don't use b2ContactListener.
---@field enabled boolean Get the active state of the body.
---@field fixedRotation boolean Does this body have fixed rotation?
---@field fixtureList b2.Fixture Get the list of all fixtures attached to this body.
---@field gravityScale number Get the gravity scale of the body.
---@field inertia number Get the rotational inertia of the body about the local origin. \return the rotational inertia, usually in kg-m^2.
---@field jointList b2.JointEdge Get the list of all joints attached to this body.
---@field linearDamping number Get the linear damping of the body.
---@field linearVelocity b2.Vec2 Get the linear velocity of the center of mass. \return the linear velocity of the center of mass.
---@field localCenter b2.Vec2 Get the local position of the center of mass.
---@field mass number Get the total mass of the body. \return the mass, usually in kilograms (kg).
---@field massData b2.MassData Get the mass data of the body. \return a struct containing the mass, inertia and center of the body.
---@field next b2.Body Get the next body in the world's body list.
---@field position b2.Vec2 Get the world body origin position. \return the world position of the body's origin.
---@field sleepingAllowed boolean Is this body allowed to sleep
---@field type b2.BodyType Get the type of this body.
---@field userData b2.BodyUserData Get the user data pointer that was provided in the body definition.
---@field world b2.World Get the parent world of this body.
---@field worldCenter b2.Vec2 Get the world position of the center of mass.
local Body = {}

---Apply an angular impulse.
---@param impulse number # the angular impulse in units of kg*m*m/s
---@param wake boolean # also wake up the body
function Body:applyAngularImpulse(impulse, wake) end

---Apply a force at a world point. If the force is not
---applied at the center of mass, it will generate a torque and
---affect the angular velocity. This wakes up the body.
---@param force b2.Vec2 # the world force vector, usually in Newtons (N).
---@param point b2.Vec2 # the world position of the point of application.
---@param wake boolean # also wake up the body
function Body:applyForce(force, point, wake) end

---Apply a force to the center of mass. This wakes up the body.
---@param force b2.Vec2 # the world force vector, usually in Newtons (N).
---@param wake boolean # also wake up the body
function Body:applyForceToCenter(force, wake) end

---Apply an impulse at a point. This immediately modifies the velocity.
---It also modifies the angular velocity if the point of application
---is not at the center of mass. This wakes up the body.
---@param impulse b2.Vec2 # the world impulse vector, usually in N-seconds or kg-m/s.
---@param point b2.Vec2 # the world position of the point of application.
---@param wake boolean # also wake up the body
function Body:applyLinearImpulse(impulse, point, wake) end

---Apply an impulse to the center of mass. This immediately modifies the velocity.
---@param impulse b2.Vec2 # the world impulse vector, usually in N-seconds or kg-m/s.
---@param wake boolean # also wake up the body
function Body:applyLinearImpulseToCenter(impulse, wake) end

---Apply a torque. This affects the angular velocity
---without affecting the linear velocity of the center of mass.
---@param torque number # about the z-axis (out of the screen), usually in N-m.
---@param wake boolean # also wake up the body
function Body:applyTorque(torque, wake) end

---Creates a fixture and attach it to this body. Use this function if you need
---to set some fixture parameters, like friction. Otherwise you can create the
---fixture directly from a shape.
---If the density is non-zero, this function automatically updates the mass of the body.
---Contacts are not created until the next time step.
---@param def b2.FixtureDef # the fixture definition.
---\warning This function is locked during callbacks.
---@return b2.Fixture
---
---Creates a fixture from a shape and attach it to this body.
---This is a convenience function. Use b2FixtureDef if you need to set parameters
---like friction, restitution, user data, or filtering.
---If the density is non-zero, this function automatically updates the mass of the body.
---\param shape the shape to be cloned.
---\param density the shape density (set to zero for static bodies).
---\warning This function is locked during callbacks.
---@overload fun(self: b2.Body, shape: b2.Shape, density: number): b2.Fixture
function Body:createFixture(def) end

---Destroy a fixture. This removes the fixture from the broad-phase and
---destroys all contacts associated with this fixture. This will
---automatically adjust the mass of the body if the body is dynamic and the
---fixture has positive density.
---All fixtures attached to a body are implicitly destroyed when the body is destroyed.
---@param fixture b2.Fixture # the fixture to be removed.
---\warning This function is locked during callbacks.
function Body:destroyFixture(fixture) end

---Dump this body to a file
function Body:dump() end

---Get the angle in radians.
---@return number # the current world rotation angle in radians.
function Body:getAngle() end

---Get the angular damping of the body.
---@return number
function Body:getAngularDamping() end

---Get the angular velocity.
---@return number # the angular velocity in radians/second.
function Body:getAngularVelocity() end

---Get the list of all contacts attached to this body.
---\warning this list changes during the time step and you may
---miss some collisions if you don't use b2ContactListener.
---@return b2.ContactEdge
function Body:getContactList() end

---Get the list of all fixtures attached to this body.
---@return b2.Fixture
function Body:getFixtureList() end

---Get the gravity scale of the body.
---@return number
function Body:getGravityScale() end

---Get the rotational inertia of the body about the local origin.
---@return number # the rotational inertia, usually in kg-m^2.
function Body:getInertia() end

---Get the list of all joints attached to this body.
---@return b2.JointEdge
function Body:getJointList() end

---Get the linear damping of the body.
---@return number
function Body:getLinearDamping() end

---Get the linear velocity of the center of mass.
---@return b2.Vec2 # the linear velocity of the center of mass.
function Body:getLinearVelocity() end

---Get the world velocity of a local point.
---@param localPoint b2.Vec2 # a point in local coordinates.
---@return b2.Vec2 # the world velocity of a point.
function Body:getLinearVelocityFromLocalPoint(localPoint) end

---Get the world linear velocity of a world point attached to this body.
---@param worldPoint b2.Vec2 # a point in world coordinates.
---@return b2.Vec2 # the world velocity of a point.
function Body:getLinearVelocityFromWorldPoint(worldPoint) end

---Get the local position of the center of mass.
---@return b2.Vec2
function Body:getLocalCenter() end

---Gets a local point relative to the body's origin given a world point.
---@param worldPoint b2.Vec2 # a point in world coordinates.
---@return b2.Vec2 # the corresponding local point relative to the body's origin.
function Body:getLocalPoint(worldPoint) end

---Gets a local vector given a world vector.
---@param worldVector b2.Vec2 # a vector in world coordinates.
---@return b2.Vec2 # the corresponding local vector.
function Body:getLocalVector(worldVector) end

---Get the total mass of the body.
---@return number # the mass, usually in kilograms (kg).
function Body:getMass() end

---Get the mass data of the body.
---@return b2.MassData # a struct containing the mass, inertia and center of the body.
function Body:getMassData() end

---Get the next body in the world's body list.
---@return b2.Body
function Body:getNext() end

---Get the world body origin position.
---@return b2.Vec2 # the world position of the body's origin.
function Body:getPosition() end

---Get the body transform for the body's origin.
---@return b2.Transform # the world transform of the body's origin.
function Body:getTransform() end

---Get the type of this body.
---@return b2.BodyType
function Body:getType() end

---Get the user data pointer that was provided in the body definition.
---@return b2.BodyUserData
function Body:getUserData() end

---Get the parent world of this body.
---@return b2.World
function Body:getWorld() end

---Get the world position of the center of mass.
---@return b2.Vec2
function Body:getWorldCenter() end

---Get the world coordinates of a point given the local coordinates.
---@param localPoint b2.Vec2 # a point on the body measured relative the the body's origin.
---@return b2.Vec2 # the same point expressed in world coordinates.
function Body:getWorldPoint(localPoint) end

---Get the world coordinates of a vector given the local coordinates.
---@param localVector b2.Vec2 # a vector fixed in the body.
---@return b2.Vec2 # the same vector expressed in world coordinates.
function Body:getWorldVector(localVector) end

---Get the sleeping state of this body.
---@return boolean # true if the body is awake.
function Body:isAwake() end

---Is this body treated like a bullet for continuous collision detection?
---@return boolean
function Body:isBullet() end

---Get the active state of the body.
---@return boolean
function Body:isEnabled() end

---Does this body have fixed rotation?
---@return boolean
function Body:isFixedRotation() end

---Is this body allowed to sleep
---@return boolean
function Body:isSleepingAllowed() end

---This resets the mass properties to the sum of the mass properties of the fixtures.
---This normally does not need to be called unless you called SetMassData to override
---the mass and you later want to reset the mass.
function Body:resetMassData() end

---Set the angular damping of the body.
---@param angularDamping number
function Body:setAngularDamping(angularDamping) end

---Set the angular velocity.
---@param omega number # the new angular velocity in radians/second.
function Body:setAngularVelocity(omega) end

---Set the sleep state of the body. A sleeping body has very
---low CPU cost.
---@param flag boolean # set to true to wake the body, false to put it to sleep.
function Body:setAwake(flag) end

---Should this body be treated like a bullet for continuous collision detection?
---@param flag boolean
function Body:setBullet(flag) end

---Allow a body to be disabled. A disabled body is not simulated and cannot
---be collided with or woken up.
---If you pass a flag of true, all fixtures will be added to the broad-phase.
---If you pass a flag of false, all fixtures will be removed from the
---broad-phase and all contacts will be destroyed.
---Fixtures and joints are otherwise unaffected. You may continue
---to create/destroy fixtures and joints on disabled bodies.
---Fixtures on a disabled body are implicitly disabled and will
---not participate in collisions, ray-casts, or queries.
---Joints connected to a disabled body are implicitly disabled.
---An diabled body is still owned by a b2World object and remains
---in the body list.
---@param flag boolean
function Body:setEnabled(flag) end

---Set this body to have fixed rotation. This causes the mass
---to be reset.
---@param flag boolean
function Body:setFixedRotation(flag) end

---Set the gravity scale of the body.
---@param scale number
function Body:setGravityScale(scale) end

---Set the linear damping of the body.
---@param linearDamping number
function Body:setLinearDamping(linearDamping) end

---Set the linear velocity of the center of mass.
---@param v b2.Vec2 # the new linear velocity of the center of mass.
function Body:setLinearVelocity(v) end

---Set the mass properties to override the mass properties of the fixtures.
---Note that this changes the center of mass position.
---Note that creating or destroying fixtures can also alter the mass.
---This function has no effect if the body isn't dynamic.
---@param data b2.MassData # the mass properties.
function Body:setMassData(data) end

---You can disable sleeping on this body. If you disable sleeping, the
---body will be woken.
---@param flag boolean
function Body:setSleepingAllowed(flag) end

---Set the position of the body's origin and rotation.
---Manipulating a body's transform may cause non-physical behavior.
---Note: contacts are updated on the next call to b2World::Step.
---@param position b2.Vec2 # the world position of the body's local origin.
---@param angle number # the world rotation in radians.
function Body:setTransform(position, angle) end

---Set the type of this body. This may alter the mass and velocity.
---@param type b2.BodyType
function Body:setType(type) end

return Body