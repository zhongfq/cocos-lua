---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.PhysicsShape

---A shape for body. You do not create PhysicsWorld objects directly, instead, you can view PhysicsBody to see how to create it.
---@class cc.PhysicsShape : cc.Ref
---@field area number Return this shape's area. <br><br>\return A float number.
---@field body cc.PhysicsBody Get the body that this shape attaches. <br><br>\return A PhysicsBody object pointer.
---@field categoryBitmask integer Get a mask that defines which categories this physics body belongs to. <br><br>\return An integer number.
---@field center cc.Vec2 Get this shape's center position. <br><br>This function should be overridden in inherit classes. \return A Vec2 object.
---@field collisionBitmask integer Get a mask that defines which categories of physics bodies can collide with this physics body. <br><br>\return An integer number.
---@field contactTestBitmask integer Get a mask that defines which categories of bodies cause intersection notifications with this physics body. <br><br>\return An integer number.
---@field density number Get this shape's density. <br><br>\return A float number.
---@field friction number Get this shape's friction. <br><br>\return A float number.
---@field group integer Get the group of body. <br><br>\return An integer number.
---@field mass number Get the mass of this shape. <br><br>\return A float number.
---@field material cc.PhysicsMaterial Get this shape's PhysicsMaterial object. <br><br>\return A PhysicsMaterial object reference.
---@field moment number Get this shape's moment. <br><br>\return A float number.
---@field offset cc.Vec2 Get this shape's position offset. <br><br>This function should be overridden in inherit classes. \return A Vec2 object.
---@field restitution number Get this shape's restitution. <br><br>\return A float number.
---@field sensor boolean 
---@field tag integer Get this shape's tag. <br><br>\return An integer number.
---@field type cc.PhysicsShape.Type Return this shape's type. <br><br>\return A Type object.
local PhysicsShape = {}

---Calculate the default moment value.
---
---This function should be overridden in inherit classes.
---@return number # A float number, equals 0.0.
function PhysicsShape:calculateDefaultMoment() end

---Test point is inside this shape or not.
---
---@param point cc.Vec2 # A Vec2 object.
---@return boolean # A bool object.
function PhysicsShape:containsPoint(point) end

---Return this shape's area.
---
---@return number # A float number.
function PhysicsShape:getArea() end

---Get the body that this shape attaches.
---
---@return cc.PhysicsBody # A PhysicsBody object pointer.
function PhysicsShape:getBody() end

---Get a mask that defines which categories this physics body belongs to.
---
---@return integer # An integer number.
function PhysicsShape:getCategoryBitmask() end

---Get this shape's center position.
---
---This function should be overridden in inherit classes.
---@return cc.Vec2 # A Vec2 object.
function PhysicsShape:getCenter() end

---Get a mask that defines which categories of physics bodies can collide with this physics body.
---
---@return integer # An integer number.
function PhysicsShape:getCollisionBitmask() end

---Get a mask that defines which categories of bodies cause intersection notifications with this physics body.
---
---@return integer # An integer number.
function PhysicsShape:getContactTestBitmask() end

---Get this shape's density.
---
---@return number # A float number.
function PhysicsShape:getDensity() end

---Get this shape's friction.
---
---@return number # A float number.
function PhysicsShape:getFriction() end

---Get the group of body.
---
---@return integer # An integer number.
function PhysicsShape:getGroup() end

---Get the mass of this shape.
---
---@return number # A float number.
function PhysicsShape:getMass() end

---Get this shape's PhysicsMaterial object.
---
---@return cc.PhysicsMaterial # A PhysicsMaterial object reference.
function PhysicsShape:getMaterial() end

---Get this shape's moment.
---
---@return number # A float number.
function PhysicsShape:getMoment() end

---Get this shape's position offset.
---
---This function should be overridden in inherit classes.
---@return cc.Vec2 # A Vec2 object.
function PhysicsShape:getOffset() end

---Get center of the polygon points.
---
---@param points cc.Vec2 # A Vec2 object pointer.
---@param count integer # An integer number.
---@return cc.Vec2 # A Vec2 object.
function PhysicsShape.getPolygonCenter(points, count) end

---Get this shape's restitution.
---
---@return number # A float number.
function PhysicsShape:getRestitution() end

---Get this shape's tag.
---
---@return integer # An integer number.
function PhysicsShape:getTag() end

---Return this shape's type.
---
---@return cc.PhysicsShape.Type # A Type object.
function PhysicsShape:getType() end

---@return boolean
function PhysicsShape:isSensor() end

---Move the points to the center.
---
---@param points cc.Vec2 # A Vec2 object pointer.
---@param count integer # An integer number.
---@param center cc.Vec2 # A Vec2 object, default value is Vec2(0,0).
---@overload fun(points: cc.Vec2, count: integer)
function PhysicsShape.recenterPoints(points, count, center) end

---Set a mask that defines which categories this physics body belongs to.
---
---Every physics body in a scene can be assigned to up to 32 different categories, each corresponding to a bit in the bit mask. You define the mask values used in your game. In conjunction with the collisionBitMask and contactTestBitMask properties, you define which physics bodies interact with each other and when your game is notified of these interactions.
---@param bitmask integer # An integer number, the default value is 0xFFFFFFFF (all bits set).
function PhysicsShape:setCategoryBitmask(bitmask) end

---A mask that defines which categories of physics bodies can collide with this physics body.
---
---When two physics bodies contact each other, a collision may occur. This body's collision mask is compared to the other body's category mask by performing a logical AND operation. If the result is a non-zero value, then this body is affected by the collision. Each body independently chooses whether it wants to be affected by the other body. For example, you might use this to avoid collision calculations that would make negligible changes to a body's velocity.
---@param bitmask integer # An integer number, the default value is 0xFFFFFFFF (all bits set).
function PhysicsShape:setCollisionBitmask(bitmask) end

---A mask that defines which categories of bodies cause intersection notifications with this physics body.
---
---When two bodies share the same space, each body's category mask is tested against the other body's contact mask by performing a logical AND operation. If either comparison results in a non-zero value, an PhysicsContact object is created and passed to the physics world’s delegate. For best performance, only set bits in the contacts mask for interactions you are interested in.
---@param bitmask integer # An integer number, the default value is 0x00000000 (all bits cleared).
function PhysicsShape:setContactTestBitmask(bitmask) end

---Set this shape's density.
---
---It will change the body's mass this shape attaches.
---
---@param density number # A float number.
function PhysicsShape:setDensity(density) end

---Set this shape's friction.
---
---It will change the shape's friction.
---
---@param friction number # A float number.
function PhysicsShape:setFriction(friction) end

---Set the group of body.
---
---Collision groups let you specify an integral group index. You can have all fixtures with the same group index always collide (positive index) or never collide (negative index).
---@param group integer # An integer number, it have high priority than bit masks.
function PhysicsShape:setGroup(group) end

---Set this shape's mass.
---
---It will change the body's mass this shape attaches.
---
---@param mass number # A float number.
function PhysicsShape:setMass(mass) end

---Set this shape's material.
---
---It will change the shape's mass, elasticity and friction.
---
---@param material cc.PhysicsMaterial # A PhysicsMaterial object.
function PhysicsShape:setMaterial(material) end

---Set this shape's moment.
---
---It will change the body's moment this shape attaches.
---
---@param moment number # A float number.
function PhysicsShape:setMoment(moment) end

---Set this shape's restitution.
---
---It will change the shape's elasticity.
---
---@param restitution number # A float number.
function PhysicsShape:setRestitution(restitution) end

---@param sensor boolean
function PhysicsShape:setSensor(sensor) end

---Set this shape's tag.
---
---@param tag integer # An integer number that identifies a shape object.
function PhysicsShape:setTag(tag) end

return PhysicsShape