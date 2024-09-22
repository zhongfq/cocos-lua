---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.PhysicsWorld

---\class PhysicsWorld CCPhysicsWorld.h
---An PhysicsWorld object simulates collisions and other physical properties. You do not create PhysicsWorld objects directly; instead, you can get it from an Scene object.
---@class cc.PhysicsWorld 
---@field allBodies any Get all the bodies that in this physics world. <br><br>\return A Vector<PhysicsBody*>& object contains all bodies in this physics world.
---@field autoStep boolean Get the auto step of this physics world. <br><br>\return A bool object.
---@field debugDrawMask integer Get the debug draw mask. <br><br>\return An integer number.
---@field fixedUpdateRate integer get the number of substeps
---@field gravity cc.Vec2 Get the gravity value of this physics world. <br><br>\return A Vec2 object.
---@field scene cc.Scene Get a scene contain this physics world. <br><br>\attention This value is initialized in constructor \return A Scene object reference.
---@field speed number Get the speed of this physics world. <br><br>\return A float number.
---@field substeps integer Get the number of substeps of this physics world. <br><br>\return An integer number.
---@field updateRate integer Get the update rate of this physics world. <br><br>\return An integer number.
---@field DEBUGDRAW_ALL integer
---@field DEBUGDRAW_CONTACT integer
---@field DEBUGDRAW_JOINT integer
---@field DEBUGDRAW_NONE integer
---@field DEBUGDRAW_SHAPE integer
local PhysicsWorld = {}

---Adds a joint to this physics world.
---
---This joint will be added to this physics world at next frame.
---\attention If this joint is already added to another physics world, it will be removed from that world first and then add to this world.
---@param joint cc.PhysicsJoint # A pointer to an existing PhysicsJoint object.
function PhysicsWorld:addJoint(joint) end

---Get all the bodies that in this physics world.
---
---@return any # A Vector<PhysicsBody*>& object contains all bodies in this physics world.
function PhysicsWorld:getAllBodies() end

---Get a body by tag. 
---
---@param tag integer # An integer number that identifies a PhysicsBody object. 
---@return cc.PhysicsBody # A PhysicsBody object pointer or nullptr if no shapes were found.
function PhysicsWorld:getBody(tag) end

---Get the debug draw mask.
---
---@return integer # An integer number.
function PhysicsWorld:getDebugDrawMask() end

---get the number of substeps
---@return integer
function PhysicsWorld:getFixedUpdateRate() end

---Get the gravity value of this physics world.
---
---@return cc.Vec2 # A Vec2 object.
function PhysicsWorld:getGravity() end

---Get a scene contain this physics world.
---
---\attention This value is initialized in constructor
---@return cc.Scene # A Scene object reference.
function PhysicsWorld:getScene() end

---Get the nearest physics shape that contains the point. 
---
---Query this physics world at point and return the closest shape.
---@param point cc.Vec2 # A Vec2 object contains the position of the point.
---@return cc.PhysicsShape # A PhysicsShape object pointer or nullptr if no shapes were found
function PhysicsWorld:getShape(point) end

---Get physics shapes that contains the point. 
---
---All shapes contains the point will be pushed in a Vector<PhysicsShape*> object.
---\attention The point must lie inside a shape.
---@param point cc.Vec2 # A Vec2 object contains the position of the point.
---@return any # A Vector<PhysicsShape*> object contains all found PhysicsShape pointer.
function PhysicsWorld:getShapes(point) end

---Get the speed of this physics world.
---
---@return number # A float number.
function PhysicsWorld:getSpeed() end

---Get the number of substeps of this physics world.
---
---@return integer # An integer number.
function PhysicsWorld:getSubsteps() end

---Get the update rate of this physics world.
---
---@return integer # An integer number.
function PhysicsWorld:getUpdateRate() end

---Get the auto step of this physics world.
---
---@return boolean # A bool object.
function PhysicsWorld:isAutoStep() end

---Searches for physics shapes that contains the point. 
---
---\attention The point must lie inside a shape.
---@param func cc.PhysicsQueryPointCallbackFunc # Func is called for each shape contains the point.
---@param point cc.Vec2 # A Vec2 object contains the position of the point.
---@param data any # User defined data, it is passed to func.
function PhysicsWorld:queryPoint(func, point, data) end

---Searches for physics shapes that contains in the rect. 
---
---Query this physics world to find all shapes overlap rect.
---@param func cc.PhysicsQueryRectCallbackFunc # Func is called for each shape whose bounding box overlaps rect. 
---@param rect cc.Rect # A Rect object contains a rectangle's x, y, width and height.
---@param data any # User defined data, it is passed to func.
function PhysicsWorld:queryRect(func, rect, data) end

---Searches for physics shapes that intersects the ray. 
---
---Query this physics world along the line segment from start to end.
---@param func cc.PhysicsRayCastCallbackFunc # Func is called for each shape found.
---@param start cc.Vec2 # A Vec2 object contains the begin position of the ray.
---\param   end   A Vec2 object contains the end position of the ray.
---@param data any # User defined data, it is passed to func.
---@param end_ cc.Vec2
function PhysicsWorld:rayCast(func, start, end_, data) end

---Remove all bodies from physics world. 
---
---If this world is not locked, those body are removed immediately, otherwise at next frame.
function PhysicsWorld:removeAllBodies() end

---Remove all joints from this physics world.
---
---\attention This function is invoked in the destructor of this physics world, you do not use this api in common.
---@param destroy boolean # true all joints will be destroyed after remove from this world, false otherwise.
---@overload fun(self: cc.PhysicsWorld)
function PhysicsWorld:removeAllJoints(destroy) end

---Remove a body from this physics world. 
---
---If this world is not locked, the body is removed immediately, otherwise at next frame.
---\attention If this body has joints, those joints will be removed also.
---@param body cc.PhysicsBody # A pointer to an existing PhysicsBody object.
---
---Remove body by tag. 
---
---If this world is not locked, the object is removed immediately, otherwise at next frame.
---\attention If this body has joints, those joints will be removed also.    
---\param   tag   An integer number that identifies a PhysicsBody object.
---@overload fun(self: cc.PhysicsWorld, tag: integer)
function PhysicsWorld:removeBody(body) end

---Remove a joint from this physics world.
---
---If this world is not locked, the joint is removed immediately, otherwise at next frame. 
---If this joint is connected with a body, it will be removed from the body also.
---@param joint cc.PhysicsJoint # A pointer to an existing PhysicsJoint object.
---@param destroy boolean # true this joint will be destroyed after remove from this world, false otherwise.
---@overload fun(self: cc.PhysicsWorld, joint: cc.PhysicsJoint)
function PhysicsWorld:removeJoint(joint, destroy) end

---To control the step of physics.
---
---If you want control it by yourself( fixed-timestep for example ), you can set this to false and call step by yourself.
---\attention If you set auto step to false, setSpeed setSubsteps and setUpdateRate won't work, you need to control the time step by yourself.
---@param autoStep boolean # A bool object, default value is true.
function PhysicsWorld:setAutoStep(autoStep) end

---Set the debug draw mask of this physics world.
---
---This physics world will draw shapes and joints by DrawNode according to mask.
---@param mask integer # Mask has four value:DEBUGDRAW_NONE, DEBUGDRAW_SHAPE, DEBUGDRAW_JOINT, DEBUGDRAW_CONTACT and DEBUGDRAW_ALL, default is DEBUGDRAW_NONE
function PhysicsWorld:setDebugDrawMask(mask) end

---set the number of update of the physics world in a second.
---0 - disable fixed step system
---default value is 0
---@param updatesPerSecond integer
function PhysicsWorld:setFixedUpdateRate(updatesPerSecond) end

---set the gravity value of this physics world.
---
---@param gravity cc.Vec2 # A gravity value of this physics world.
function PhysicsWorld:setGravity(gravity) end

---set the callback which invoked after update of each object in physics world.
---@param callback fun()
function PhysicsWorld:setPostUpdateCallback(callback) end

---set the callback which invoked before update of each object in physics world.
---@param callback fun()
function PhysicsWorld:setPreUpdateCallback(callback) end

---Set the speed of this physics world.
---
---\attention if you setAutoStep(false), this won't work.
---@param speed number # A float number. Speed is the rate at which the simulation executes. default value is 1.0.
function PhysicsWorld:setSpeed(speed) end

---set the number of substeps in an update of the physics world.
---
---One physics update will be divided into several substeps to increase its accuracy.
---@param steps integer # An integer number, default value is 1.
function PhysicsWorld:setSubsteps(steps) end

---Set the update rate of this physics world
---
---Update rate is the value of EngineUpdateTimes/PhysicsWorldUpdateTimes.
---Set it higher can improve performance, set it lower can improve accuracy of physics world simulation.
---\attention if you setAutoStep(false), this won't work.
---@param rate integer # An integer number, default value is 1.0.
function PhysicsWorld:setUpdateRate(rate) end

---The step for physics world.
---
---The times passing for simulate the physics.
---\attention You need to setAutoStep(false) first before it can work.
---@param delta number # A float number.
function PhysicsWorld:step(delta) end

return PhysicsWorld