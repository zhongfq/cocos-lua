---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.PhysicsBody

---A body affect by physics.
---
---It can attach one or more shapes.
---If you create body with createXXX, it will automatically compute mass and moment with density your specified(which is PHYSICSBODY_MATERIAL_DEFAULT by default, and the density value is 0.1f), and it based on the formula: mass = density * area.
---If you create body with createEdgeXXX, the mass and moment will be PHYSICS_INFINITY by default. And it's a static body.
---You can change mass and moment with setMass() and setMoment(). And you can change the body to be dynamic or static by use function setDynamic().
---@class cc.PhysicsBody : cc.Component
---@field angularDamping number Get angular damping.
---@field angularVelocity number get the angular velocity of a body
---@field angularVelocityLimit number get the max of angular velocity
---@field categoryBitmask integer Return bitmask of first shape. <br><br>\return If there is no shape in body, return default value.(0xFFFFFFFF)
---@field collisionBitmask integer Return bitmask of first shape. <br><br>\return If there is no shape in body, return default value.(0xFFFFFFFF)
---@field contactTestBitmask integer Return bitmask of first shape. <br><br>\return If there is no shape in body, return default value.(0x00000000)
---@field dynamic boolean Test the body is dynamic or not. <br><br>A dynamic body will effect with gravity.
---@field firstShape cc.PhysicsShape Get the first shape of the body shapes. <br><br>\return The first shape in this body.
---@field gravityEnabled boolean Whether this physics body is affected by the physics world's gravitational force.
---@field group integer Return group of first shape. <br><br>\return If there is no shape in body, return default value.(0)
---@field joints cc.PhysicsJoint[] get all joints the body have
---@field linearDamping number get linear damping.
---@field mass number Get the body mass.
---@field moment number Get the body moment of inertia.
---@field node cc.Node get the node the body set to.
---@field position cc.Vec2 get the body position.
---@field positionOffset cc.Vec2 get body position offset.
---@field resting boolean Whether the body is at rest.
---@field rotation number get the body rotation.
---@field rotationEnabled boolean Whether the body can rotation.
---@field rotationOffset number set the body rotation offset
---@field shapes any Get the body shapes. <br><br>\return A Vector<PhysicsShape*> object contains PhysicsShape pointer.
---@field tag integer Get the body's tag.
---@field velocity cc.Vec2 Get the velocity of a body.
---@field velocityLimit number get the max of velocity
---@field world cc.PhysicsWorld get the world body added to.
---@field COMPONENT_NAME string
local PhysicsBody = {}

---Add mass to body.
---
---@param mass number # If _mass(mass of the body) == PHYSICS_INFINITY, it remains.
---if mass == PHYSICS_INFINITY, _mass will be PHYSICS_INFINITY.
---if mass == -PHYSICS_INFINITY, _mass will not change.
---if mass + _mass <= 0, _mass will equal to MASS_DEFAULT(1.0)
---other wise, mass = mass + _mass;
function PhysicsBody:addMass(mass) end

---Add moment of inertia to body.
---
---@param moment number # If _moment(moment of the body) == PHYSICS_INFINITY, it remains.
---if moment == PHYSICS_INFINITY, _moment will be PHYSICS_INFINITY.
---if moment == -PHYSICS_INFINITY, _moment will not change.
---if moment + _moment <= 0, _moment will equal to MASS_DEFAULT(1.0)
---other wise, moment = moment + _moment;
function PhysicsBody:addMoment(moment) end

---Add a shape to body.
---@param shape cc.PhysicsShape # The shape to be added.
---@param addMassAndMoment boolean # If this is true, the shape's mass and moment will be added to body. The default is true.
---@return cc.PhysicsShape # This shape's pointer if added success or nullptr if failed.
---@overload fun(self: cc.PhysicsBody, shape: cc.PhysicsShape): cc.PhysicsShape
function PhysicsBody:addShape(shape, addMassAndMoment) end

---Applies a continuous force to body.
---
---@param force cc.Vec2 # The force is applies to this body.
---@param offset cc.Vec2 # A Vec2 object, it is the offset from the body's center of gravity in world coordinates.
---@overload fun(self: cc.PhysicsBody, force: cc.Vec2)
function PhysicsBody:applyForce(force, offset) end

---Applies a immediate force to body.
---
---@param impulse cc.Vec2 # The impulse is applies to this body.
---@param offset cc.Vec2 # A Vec2 object, it is the offset from the body's center of gravity in world coordinates.
---@overload fun(self: cc.PhysicsBody, impulse: cc.Vec2)
function PhysicsBody:applyImpulse(impulse, offset) end

---Applies a torque force to body.
---
---@param torque number # The torque is applies to this body.
function PhysicsBody:applyTorque(torque) end

---Create a body with default mass and moment.
---
---This default mass value is 1.0.
---This default moment value is 200.
---@return cc.PhysicsBody # An autoreleased PhysicsBody object pointer.
---
---Create a body with mass and default moment.
---
---\param mass This body's mass.
---\return  An autoreleased PhysicsBody object pointer.
---@overload fun(mass: number): cc.PhysicsBody
---
---Create a body with mass and moment.
---
---\param mass This body's mass.
---\param moment This body's moment.
---\return  An autoreleased PhysicsBody object pointer.
---@overload fun(mass: number, moment: number): cc.PhysicsBody
function PhysicsBody.create() end

---Create a body contains a box shape.
---
---@param size cc.Size # Size contains this box's width and height.
---@param material cc.PhysicsMaterial # A PhysicsMaterial object, the default value is PHYSICSSHAPE_MATERIAL_DEFAULT.
---@param offset cc.Vec2 # A Vec2 object, it is the offset from the body's center of gravity in body local coordinates.
---@return cc.PhysicsBody # An autoreleased PhysicsBody object pointer.
---@overload fun(size: cc.Size): cc.PhysicsBody
---@overload fun(size: cc.Size, material: cc.PhysicsMaterial): cc.PhysicsBody
function PhysicsBody.createBox(size, material, offset) end

---Create a body contains a circle.
---
---@param radius number # A float number, it is the circle's radius.
---@param material cc.PhysicsMaterial # A PhysicsMaterial object, the default value is PHYSICSSHAPE_MATERIAL_DEFAULT.
---@param offset cc.Vec2 # A Vec2 object, it is the offset from the body's center of gravity in body local coordinates.
---@return cc.PhysicsBody # An autoreleased PhysicsBody object pointer.
---@overload fun(radius: number): cc.PhysicsBody
---@overload fun(radius: number, material: cc.PhysicsMaterial): cc.PhysicsBody
function PhysicsBody.createCircle(radius, material, offset) end

---Create a body contains a EdgeBox shape.
---@param size cc.Size # Size contains this box's width and height.
---@param material cc.PhysicsMaterial # A PhysicsMaterial object, the default value is PHYSICSSHAPE_MATERIAL_DEFAULT.
---@param border number # It's a edge's border width.
---@param offset cc.Vec2 # A Vec2 object, it is the offset from the body's center of gravity in body local coordinates.
---@return cc.PhysicsBody # An autoreleased PhysicsBody object pointer.
---@overload fun(size: cc.Size): cc.PhysicsBody
---@overload fun(size: cc.Size, material: cc.PhysicsMaterial): cc.PhysicsBody
---@overload fun(size: cc.Size, material: cc.PhysicsMaterial, border: number): cc.PhysicsBody
function PhysicsBody.createEdgeBox(size, material, border, offset) end

---Create a body contains a EdgeChain shape.
---
---@param points cc.Vec2 # A Vec2 object pointer, it contains an array of points.
---@param count integer # An integer number, contains the count of the points array.
---@param material cc.PhysicsMaterial # A PhysicsMaterial object, the default value is PHYSICSSHAPE_MATERIAL_DEFAULT.
---@param border number # It's a edge's border width.
---@return cc.PhysicsBody # An autoreleased PhysicsBody object pointer.
---@overload fun(points: cc.Vec2, count: integer): cc.PhysicsBody
---@overload fun(points: cc.Vec2, count: integer, material: cc.PhysicsMaterial): cc.PhysicsBody
function PhysicsBody.createEdgeChain(points, count, material, border) end

---Create a body contains a EdgePolygon shape.
---
---@param points cc.Vec2 # Points is an array of Vec2 structs defining a convex hull with a clockwise winding.
---@param count integer # An integer number, contains the count of the points array.
---@param material cc.PhysicsMaterial # A PhysicsMaterial object, the default value is PHYSICSSHAPE_MATERIAL_DEFAULT.
---@param border number # It's a edge's border width.
---@return cc.PhysicsBody # An autoreleased PhysicsBody object pointer.
---@overload fun(points: cc.Vec2, count: integer): cc.PhysicsBody
---@overload fun(points: cc.Vec2, count: integer, material: cc.PhysicsMaterial): cc.PhysicsBody
function PhysicsBody.createEdgePolygon(points, count, material, border) end

---Create a body contains a EdgeSegment shape.
---
---@param a cc.Vec2 # It's the edge's begin position.
---@param b cc.Vec2 # It's the edge's end position.
---@param material cc.PhysicsMaterial # A PhysicsMaterial object, the default value is PHYSICSSHAPE_MATERIAL_DEFAULT.
---@param border number # It's a edge's border width.
---@return cc.PhysicsBody # An autoreleased PhysicsBody object pointer.
---@overload fun(a: cc.Vec2, b: cc.Vec2): cc.PhysicsBody
---@overload fun(a: cc.Vec2, b: cc.Vec2, material: cc.PhysicsMaterial): cc.PhysicsBody
function PhysicsBody.createEdgeSegment(a, b, material, border) end

---Create a body contains a polygon shape.
---
---@param points cc.Vec2 # Points is an array of Vec2 structs defining a convex hull with a clockwise winding.
---@param count integer # An integer number, contains the count of the points array.
---@param material cc.PhysicsMaterial # A PhysicsMaterial object, the default value is PHYSICSSHAPE_MATERIAL_DEFAULT.
---@param offset cc.Vec2 # A Vec2 object, it is the offset from the body's center of gravity in body local coordinates.
---@return cc.PhysicsBody # An autoreleased PhysicsBody object pointer.
---@overload fun(points: cc.Vec2, count: integer): cc.PhysicsBody
---@overload fun(points: cc.Vec2, count: integer, material: cc.PhysicsMaterial): cc.PhysicsBody
function PhysicsBody.createPolygon(points, count, material, offset) end

---Get angular damping.
---@return number
function PhysicsBody:getAngularDamping() end

---get the angular velocity of a body
---@return number
function PhysicsBody:getAngularVelocity() end

---get the max of angular velocity
---@return number
function PhysicsBody:getAngularVelocityLimit() end

---Return bitmask of first shape.
---
---@return integer # If there is no shape in body, return default value.(0xFFFFFFFF)
function PhysicsBody:getCategoryBitmask() end

---Return bitmask of first shape.
---
---@return integer # If there is no shape in body, return default value.(0xFFFFFFFF)
function PhysicsBody:getCollisionBitmask() end

---Return bitmask of first shape.
---
---@return integer # If there is no shape in body, return default value.(0x00000000)
function PhysicsBody:getContactTestBitmask() end

---Get the first shape of the body shapes.
---
---@return cc.PhysicsShape # The first shape in this body.
function PhysicsBody:getFirstShape() end

---Return group of first shape.
---
---@return integer # If there is no shape in body, return default value.(0)
function PhysicsBody:getGroup() end

---get all joints the body have
---@return cc.PhysicsJoint[]
function PhysicsBody:getJoints() end

---get linear damping.
---@return number
function PhysicsBody:getLinearDamping() end

---Get the body mass.
---@return number
function PhysicsBody:getMass() end

---Get the body moment of inertia.
---@return number
function PhysicsBody:getMoment() end

---get the node the body set to.
---@return cc.Node
function PhysicsBody:getNode() end

---get the body position.
---@return cc.Vec2
function PhysicsBody:getPosition() end

---get body position offset.
---@return cc.Vec2
function PhysicsBody:getPositionOffset() end

---get the body rotation.
---@return number
function PhysicsBody:getRotation() end

---set the body rotation offset
---@return number
function PhysicsBody:getRotationOffset() end

---get the shape of the body.
---
---@param tag integer # An integer number that identifies a PhysicsShape object.
---@return cc.PhysicsShape # A PhysicsShape object pointer or nullptr if no shapes were found.
function PhysicsBody:getShape(tag) end

---Get the body shapes.
---
---@return any # A Vector<PhysicsShape*> object contains PhysicsShape pointer.
function PhysicsBody:getShapes() end

---Get the body's tag.
---@return integer
function PhysicsBody:getTag() end

---Get the velocity of a body.
---@return cc.Vec2
function PhysicsBody:getVelocity() end

---Get the angular velocity of a body at a local point.
---@param point cc.Vec2
---@return cc.Vec2
function PhysicsBody:getVelocityAtLocalPoint(point) end

---get the angular velocity of a body at a world point
---@param point cc.Vec2
---@return cc.Vec2
function PhysicsBody:getVelocityAtWorldPoint(point) end

---get the max of velocity
---@return number
function PhysicsBody:getVelocityLimit() end

---get the world body added to.
---@return cc.PhysicsWorld
function PhysicsBody:getWorld() end

---Test the body is dynamic or not.
---
---A dynamic body will effect with gravity.
---@return boolean
function PhysicsBody:isDynamic() end

---Whether this physics body is affected by the physics world's gravitational force.
---@return boolean
function PhysicsBody:isGravityEnabled() end

---Whether the body is at rest.
---@return boolean
function PhysicsBody:isResting() end

---Whether the body can rotation.
---@return boolean
function PhysicsBody:isRotationEnabled() end

---Convert the local point to world.
---@param point cc.Vec2
---@return cc.Vec2
function PhysicsBody:local2World(point) end

---Remove all shapes.
---
---@param reduceMassAndMoment boolean # If this is true, the body mass and moment will be reduced by shape. The default is true.
---@overload fun(self: cc.PhysicsBody)
function PhysicsBody:removeAllShapes(reduceMassAndMoment) end

---remove the body from the world it added to
function PhysicsBody:removeFromWorld() end

---Remove a shape from body.
---@param shape cc.PhysicsShape # Shape the shape to be removed.
---@param reduceMassAndMoment boolean # If this is true, the body mass and moment will be reduced by shape. The default is true.
---@overload fun(self: cc.PhysicsBody, shape: cc.PhysicsShape)
---
---Remove a shape from body.
---\param tag The tag of the shape to be removed.
---\param reduceMassAndMoment If this is true, the body mass and moment will be reduced by shape. The default is true.
---@overload fun(self: cc.PhysicsBody, tag: integer, reduceMassAndMoment: boolean)
---
---Remove a shape from body.
---\param tag The tag of the shape to be removed.
---\param reduceMassAndMoment If this is true, the body mass and moment will be reduced by shape. The default is true.
---@overload fun(self: cc.PhysicsBody, tag: integer)
function PhysicsBody:removeShape(shape, reduceMassAndMoment) end

---reset all the force applied to body.
function PhysicsBody:resetForces() end

---Set angular damping.
---
---It is used to simulate fluid or air friction forces on the body.
---@param damping number # The value is 0.0f to 1.0f.
function PhysicsBody:setAngularDamping(damping) end

---Set the angular velocity of a body.
---
---@param velocity number # The angular velocity is set to this body.
function PhysicsBody:setAngularVelocity(velocity) end

---set the max of angular velocity
---@param limit number
function PhysicsBody:setAngularVelocityLimit(limit) end

---A mask that defines which categories this physics body belongs to.
---
---Every physics body in a scene can be assigned to up to 32 different categories, each corresponding to a bit in the bit mask. You define the mask values used in your game. In conjunction with the collisionBitMask and contactTestBitMask properties, you define which physics bodies interact with each other and when your game is notified of these interactions.
---@param bitmask integer # An integer number, the default value is 0xFFFFFFFF (all bits set).
function PhysicsBody:setCategoryBitmask(bitmask) end

---A mask that defines which categories of physics bodies can collide with this physics body.
---
---When two physics bodies contact each other, a collision may occur. This body's collision mask is compared to the other body's category mask by performing a logical AND operation. If the result is a non-zero value, then this body is affected by the collision. Each body independently chooses whether it wants to be affected by the other body. For example, you might use this to avoid collision calculations that would make negligible changes to a body's velocity.
---@param bitmask integer # An integer number, the default value is 0xFFFFFFFF (all bits set).
function PhysicsBody:setCollisionBitmask(bitmask) end

---A mask that defines which categories of bodies cause intersection notifications with this physics body.
---
---When two bodies share the same space, each body's category mask is tested against the other body's contact mask by performing a logical AND operation. If either comparison results in a non-zero value, an PhysicsContact object is created and passed to the physics world’s delegate. For best performance, only set bits in the contacts mask for interactions you are interested in.
---@param bitmask integer # An integer number, the default value is 0x00000000 (all bits cleared).
function PhysicsBody:setContactTestBitmask(bitmask) end

---Set dynamic to body.
---
---A dynamic body will effect with gravity.
---@param dynamic boolean
function PhysicsBody:setDynamic(dynamic) end

---Set the body is affected by the physics world's gravitational force or not.
---@param enable boolean
function PhysicsBody:setGravityEnable(enable) end

---Set the group of body.
---
---Collision groups let you specify an integral group index. You can have all fixtures with the same group index always collide (positive index) or never collide (negative index).
---It have high priority than bit masks.
---@param group integer
function PhysicsBody:setGroup(group) end

---Set linear damping.
---
---it is used to simulate fluid or air friction forces on the body.
---@param damping number # The value is 0.0f to 1.0f.
function PhysicsBody:setLinearDamping(damping) end

---Set the body mass.
---
---\attention If you need add/subtract mass to body, don't use setMass(getMass() +/- mass), because the mass of body may be equal to PHYSICS_INFINITY, it will cause some unexpected result, please use addMass() instead.
---@param mass number
function PhysicsBody:setMass(mass) end

---Set the body moment of inertia.
---
---\note If you need add/subtract moment to body, don't use setMoment(getMoment() +/- moment), because the moment of body may be equal to PHYSICS_INFINITY, it will cause some unexpected result, please use addMoment() instead.
---@param moment number
function PhysicsBody:setMoment(moment) end

---set body position offset, it's the position witch relative to node
---@param position cc.Vec2
function PhysicsBody:setPositionOffset(position) end

---set body to rest
---@param rest boolean
function PhysicsBody:setResting(rest) end

---Set the body is allow rotation or not
---@param enable boolean
function PhysicsBody:setRotationEnable(enable) end

---set body rotation offset, it's the rotation witch relative to node
---@param rotation number
function PhysicsBody:setRotationOffset(rotation) end

---set the body's tag.
---@param tag integer
function PhysicsBody:setTag(tag) end

---Set the velocity of a body.
---
---@param velocity cc.Vec2 # The velocity is set to this body.
function PhysicsBody:setVelocity(velocity) end

---set the max of velocity
---@param limit number
function PhysicsBody:setVelocityLimit(limit) end

---Convert the world point to local.
---@param point cc.Vec2
---@return cc.Vec2
function PhysicsBody:world2Local(point) end

return PhysicsBody