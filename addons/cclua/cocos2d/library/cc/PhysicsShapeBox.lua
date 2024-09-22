---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.PhysicsShapeBox

---A box shape.
---@class cc.PhysicsShapeBox : cc.PhysicsShapePolygon
---@field size cc.Size Get this box's width and height. <br><br>\return An Size object.
local PhysicsShapeBox = {}

---Creates a PhysicsShapeBox with specified value.
---
---@param size cc.Size # Size contains this box's width and height.
---@param material cc.PhysicsMaterial # A PhysicsMaterial object, the default value is PHYSICSSHAPE_MATERIAL_DEFAULT.
---@param offset cc.Vec2 # A Vec2 object, it is the offset from the body's center of gravity in body local coordinates.
---@return cc.PhysicsShapeBox # An autoreleased PhysicsShapeBox object pointer.
---@param radius number
---@overload fun(size: cc.Size): cc.PhysicsShapeBox
---@overload fun(size: cc.Size, material: cc.PhysicsMaterial): cc.PhysicsShapeBox
---@overload fun(size: cc.Size, material: cc.PhysicsMaterial, offset: cc.Vec2): cc.PhysicsShapeBox
function PhysicsShapeBox.create(size, material, offset, radius) end

---Get this box's width and height.
---
---@return cc.Size # An Size object.
function PhysicsShapeBox:getSize() end

return PhysicsShapeBox