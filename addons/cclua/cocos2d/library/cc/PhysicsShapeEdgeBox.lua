---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.PhysicsShapeEdgeBox

---An edge box shape.
---@class cc.PhysicsShapeEdgeBox : cc.PhysicsShapeEdgePolygon
local PhysicsShapeEdgeBox = {}

---Creates a PhysicsShapeEdgeBox with specified value.
---
---@param size cc.Size # Size contains this box's width and height.
---@param material cc.PhysicsMaterial # A PhysicsMaterial object, the default value is PHYSICSSHAPE_MATERIAL_DEFAULT.
---@param border number # It's a edge's border width.
---@param offset cc.Vec2 # A Vec2 object, it is the offset from the body's center of gravity in body local coordinates.
---@return cc.PhysicsShapeEdgeBox # An autoreleased PhysicsShapeEdgeBox object pointer.
---@overload fun(size: cc.Size): cc.PhysicsShapeEdgeBox
---@overload fun(size: cc.Size, material: cc.PhysicsMaterial): cc.PhysicsShapeEdgeBox
---@overload fun(size: cc.Size, material: cc.PhysicsMaterial, border: number): cc.PhysicsShapeEdgeBox
function PhysicsShapeEdgeBox.create(size, material, border, offset) end

return PhysicsShapeEdgeBox