---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.World

---The world class manages all physics entities, dynamic simulation,
---and asynchronous queries. The world also contains efficient memory
---management facilities.
---@class b2.World 
---@field allowSleeping boolean 
---@field autoClearForces boolean Get the flag that controls automatic clearing of forces after each time step.
---@field bodyCount integer Get the number of bodies.
---@field bodyList b2.Body Get the world body list. With the returned body, use b2Body::GetNext to get the next body in the world list. A nullptr body indicates the end of the list. \return the head of the world body list.
---@field contactCount integer Get the number of contacts (each may have 0 or more contact points).
---@field contactList b2.Contact Get the world contact list. With the returned contact, use b2Contact::GetNext to get the next contact in the world list. A nullptr contact indicates the end of the list. \return the head of the world contact list. \warning contacts are created and destroyed in the middle of a time step. Use b2ContactListener to avoid missing contacts.
---@field contactManager b2.ContactManager Get the contact manager for testing.
---@field continuousPhysics boolean 
---@field gravity b2.Vec2 Get the global gravity vector.
---@field jointCount integer Get the number of joints.
---@field jointList b2.Joint Get the world joint list. With the returned joint, use b2Joint::GetNext to get the next joint in the world list. A nullptr joint indicates the end of the list. \return the head of the world joint list.
---@field locked boolean Is the world locked (in the middle of a time step).
---@field profile b2.Profile Get the current profile.
---@field proxyCount integer Get the number of broad-phase proxies.
---@field subStepping boolean 
---@field treeBalance integer Get the balance of the dynamic tree.
---@field treeHeight integer Get the height of the dynamic tree.
---@field treeQuality number Get the quality metric of the dynamic tree. The smaller the better. The minimum is 1.
---@field warmStarting boolean 
local World = {}

---@return any
function World:__gc() end

---Manually clear the force buffer on all bodies. By default, forces are cleared automatically
---after each call to Step. The default behavior is modified by calling SetAutoClearForces.
---The purpose of this function is to support sub-stepping. Sub-stepping is often used to maintain
---a fixed sized time step under a variable frame-rate.
---When you perform sub-stepping you will disable auto clearing of forces and instead call
---ClearForces after all sub-steps are complete in one pass of your game loop.
---\see SetAutoClearForces
function World:clearForces() end

---Create a rigid body given a definition. No reference to the definition
---is retained.
---\warning This function is locked during callbacks.
---@param def b2.BodyDef
---@return b2.Body
function World:createBody(def) end

---Create a joint to constrain bodies together. No reference to the definition
---is retained. This may cause the connected bodies to cease colliding.
---\warning This function is locked during callbacks.
---@param def b2.JointDef
---@return b2.Joint
function World:createJoint(def) end

---Call this to draw shapes and other debug draw data. This is intentionally non-const.
function World:debugDraw() end

---Destroy a rigid body given a definition. No reference to the definition
---is retained. This function is locked during callbacks.
---\warning This automatically deletes all associated shapes and joints.
---\warning This function is locked during callbacks.
---@param body b2.Body
function World:destroyBody(body) end

---Destroy a joint. This may cause the connected bodies to begin colliding.
---\warning This function is locked during callbacks.
---@param joint b2.Joint
function World:destroyJoint(joint) end

---Dump the world into the log file.
---\warning this should be called outside of a time step.
function World:dump() end

---@return boolean
function World:getAllowSleeping() end

---Get the flag that controls automatic clearing of forces after each time step.
---@return boolean
function World:getAutoClearForces() end

---Get the number of bodies.
---@return integer
function World:getBodyCount() end

---Get the world body list. With the returned body, use b2Body::GetNext to get
---the next body in the world list. A nullptr body indicates the end of the list.
---@return b2.Body # the head of the world body list.
function World:getBodyList() end

---Get the number of contacts (each may have 0 or more contact points).
---@return integer
function World:getContactCount() end

---Get the world contact list. With the returned contact, use b2Contact::GetNext to get
---the next contact in the world list. A nullptr contact indicates the end of the list.
---@return b2.Contact # the head of the world contact list.
---\warning contacts are created and destroyed in the middle of a time step.
---Use b2ContactListener to avoid missing contacts.
function World:getContactList() end

---Get the contact manager for testing.
---@return b2.ContactManager
function World:getContactManager() end

---@return boolean
function World:getContinuousPhysics() end

---Get the global gravity vector.
---@return b2.Vec2
function World:getGravity() end

---Get the number of joints.
---@return integer
function World:getJointCount() end

---Get the world joint list. With the returned joint, use b2Joint::GetNext to get
---the next joint in the world list. A nullptr joint indicates the end of the list.
---@return b2.Joint # the head of the world joint list.
function World:getJointList() end

---Get the current profile.
---@return b2.Profile
function World:getProfile() end

---Get the number of broad-phase proxies.
---@return integer
function World:getProxyCount() end

---@return boolean
function World:getSubStepping() end

---Get the balance of the dynamic tree.
---@return integer
function World:getTreeBalance() end

---Get the height of the dynamic tree.
---@return integer
function World:getTreeHeight() end

---Get the quality metric of the dynamic tree. The smaller the better.
---The minimum is 1.
---@return number
function World:getTreeQuality() end

---@return boolean
function World:getWarmStarting() end

---Is the world locked (in the middle of a time step).
---@return boolean
function World:isLocked() end

---Construct a world object.
---@param gravity b2.Vec2 # the world gravity vector.
---@return b2.World
function World.new(gravity) end

---Query the world for all fixtures that potentially overlap the
---provided AABB.
---@param callback b2.interface.QueryCallback # a user implemented callback class.
---@param aabb b2.AABB # the query box.
function World:queryAABB(callback, aabb) end

---Ray-cast the world for all fixtures in the path of the ray. Your callback
---controls whether you get the closest point, any point, or n-points.
---The ray-cast ignores shapes that contain the starting point.
---@param callback b2.interface.RayCastCallback # a user implemented callback class.
---@param point1 b2.Vec2 # the ray starting point
---@param point2 b2.Vec2 # the ray ending point
function World:rayCast(callback, point1, point2) end

---Enable/disable sleep.
---@param flag boolean
function World:setAllowSleeping(flag) end

---Set flag to control automatic clearing of forces after each time step.
---@param flag boolean
function World:setAutoClearForces(flag) end

---Register a contact filter to provide specific control over collision.
---Otherwise the default filter is used (b2_defaultFilter). The listener is
---owned by you and must remain in scope.
---@param filter b2.interface.ContactFilter
function World:setContactFilter(filter) end

---Register a contact event listener. The listener is owned by you and must
---remain in scope.
---@param listener b2.interface.ContactListener
function World:setContactListener(listener) end

---Enable/disable continuous physics. For testing.
---@param flag boolean
function World:setContinuousPhysics(flag) end

---Register a routine for debug drawing. The debug draw functions are called
---inside with b2World::DebugDraw method. The debug draw object is owned
---by you and must remain in scope.
---@param debugDraw b2.interface.Draw
function World:setDebugDraw(debugDraw) end

---Register a destruction listener. The listener is owned by you and must
---remain in scope.
---@param listener b2.interface.DestructionListener
function World:setDestructionListener(listener) end

---Change the global gravity vector.
---@param gravity b2.Vec2
function World:setGravity(gravity) end

---Enable/disable single stepped continuous physics. For testing.
---@param flag boolean
function World:setSubStepping(flag) end

---Enable/disable warm starting. For testing.
---@param flag boolean
function World:setWarmStarting(flag) end

---Shift the world origin. Useful for large worlds.
---The body shift formula is: position -= newOrigin
---@param newOrigin b2.Vec2 # the new origin with respect to the old origin
function World:shiftOrigin(newOrigin) end

---Take a time step. This performs collision detection, integration,
---and constraint solution.
---@param timeStep number # the amount of time to simulate, this should not vary.
---@param velocityIterations integer # for the velocity constraint solver.
---@param positionIterations integer # for the position constraint solver.
function World:step(timeStep, velocityIterations, positionIterations) end

return World