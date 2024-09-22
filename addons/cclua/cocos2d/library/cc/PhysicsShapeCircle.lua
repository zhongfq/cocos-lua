---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.PhysicsShapeCircle

---A circle shape.
---@class cc.PhysicsShapeCircle : cc.PhysicsShape
---@field radius number Get the circle's radius. <br><br>\return A float number.
local PhysicsShapeCircle = {}

---Calculate the area of a circle with specified radius.
---
---@param radius number # A float number
---@return number # A float number
function PhysicsShapeCircle.calculateArea(radius) end

---Calculate the moment of a circle with specified value.
---
---@param mass number # A float number
---@param radius number # A float number
---@param offset cc.Vec2 # A Vec2 object, it is the offset from the body's center of gravity in body local coordinates.
---@return number # A float number
---@overload fun(mass: number, radius: number): number
function PhysicsShapeCircle.calculateMoment(mass, radius, offset) end

---Creates a PhysicsShapeCircle with specified value.
---
---@param radius number # A float number, it is the circle's radius.
---@param material cc.PhysicsMaterial # A PhysicsMaterial object, the default value is PHYSICSSHAPE_MATERIAL_DEFAULT.
---@param offset cc.Vec2 # A Vec2 object, it is the offset from the body's center of gravity in body local coordinates.
---@return cc.PhysicsShapeCircle # An autoreleased PhysicsShapeCircle object pointer.
---@overload fun(radius: number): cc.PhysicsShapeCircle
---@overload fun(radius: number, material: cc.PhysicsMaterial): cc.PhysicsShapeCircle
function PhysicsShapeCircle.create(radius, material, offset) end

---Get the circle's radius.
---
---@return number # A float number.
function PhysicsShapeCircle:getRadius() end

return PhysicsShapeCircle