---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.PhysicsShapeEdgeChain

---A chain shape.
---@class cc.PhysicsShapeEdgeChain : cc.PhysicsShape
---@field pointsCount integer Get this chain's points array count. <br><br>\return An integer number.
local PhysicsShapeEdgeChain = {}

---Creates a PhysicsShapeEdgeChain with specified value.
---
---@param points cc.Vec2 # A Vec2 object pointer, it contains an array of points.
---@param count integer # An integer number, contains the count of the points array.
---@param material cc.PhysicsMaterial # A PhysicsMaterial object, the default value is PHYSICSSHAPE_MATERIAL_DEFAULT.
---@param border number # It's a edge's border width.
---@return cc.PhysicsShapeEdgeChain # An autoreleased PhysicsShapeEdgeChain object pointer.
---@overload fun(points: cc.Vec2, count: integer): cc.PhysicsShapeEdgeChain
---@overload fun(points: cc.Vec2, count: integer, material: cc.PhysicsMaterial): cc.PhysicsShapeEdgeChain
function PhysicsShapeEdgeChain.create(points, count, material, border) end

---Get this chain's points array.
---
---@param outPoints cc.Vec2 # A Vec2 array pointer.
function PhysicsShapeEdgeChain:getPoints(outPoints) end

---Get this chain's points array count.
---
---@return integer # An integer number.
function PhysicsShapeEdgeChain:getPointsCount() end

return PhysicsShapeEdgeChain