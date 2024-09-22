---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.PhysicsShapeEdgeSegment

---A segment shape.
---@class cc.PhysicsShapeEdgeSegment : cc.PhysicsShape
---@field pointA cc.Vec2 Get this edge's begin position. <br><br>\return A Vec2 object.
---@field pointB cc.Vec2 Get this edge's end position. <br><br>\return A Vec2 object.
local PhysicsShapeEdgeSegment = {}

---Creates a PhysicsShapeEdgeSegment with specified value.
---
---@param a cc.Vec2 # It's the edge's begin position.
---@param b cc.Vec2 # It's the edge's end position.
---@param material cc.PhysicsMaterial # A PhysicsMaterial object, the default value is PHYSICSSHAPE_MATERIAL_DEFAULT.
---@param border number # It's a edge's border width.
---@return cc.PhysicsShapeEdgeSegment # An autoreleased PhysicsShapeEdgeSegment object pointer.
---@overload fun(a: cc.Vec2, b: cc.Vec2): cc.PhysicsShapeEdgeSegment
---@overload fun(a: cc.Vec2, b: cc.Vec2, material: cc.PhysicsMaterial): cc.PhysicsShapeEdgeSegment
function PhysicsShapeEdgeSegment.create(a, b, material, border) end

---Get this edge's begin position.
---
---@return cc.Vec2 # A Vec2 object.
function PhysicsShapeEdgeSegment:getPointA() end

---Get this edge's end position.
---
---@return cc.Vec2 # A Vec2 object.
function PhysicsShapeEdgeSegment:getPointB() end

return PhysicsShapeEdgeSegment