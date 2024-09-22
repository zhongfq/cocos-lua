---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.PhysicsShapeEdgePolygon

---An edge polygon shape.
---@class cc.PhysicsShapeEdgePolygon : cc.PhysicsShape
---@field pointsCount integer Get this polygon's points array count. <br><br>\return An integer number.
local PhysicsShapeEdgePolygon = {}

---Creates a PhysicsShapeEdgePolygon with specified value.
---
---@param points cc.Vec2 # A Vec2 object pointer, it contains an array of points.
---@param count integer # An integer number, contains the count of the points array.
---@param material cc.PhysicsMaterial # A PhysicsMaterial object, the default value is PHYSICSSHAPE_MATERIAL_DEFAULT.
---@param border number # It's a edge's border width.
---@return cc.PhysicsShapeEdgePolygon # An autoreleased PhysicsShapeEdgePolygon object pointer.
---@overload fun(points: cc.Vec2, count: integer): cc.PhysicsShapeEdgePolygon
---@overload fun(points: cc.Vec2, count: integer, material: cc.PhysicsMaterial): cc.PhysicsShapeEdgePolygon
function PhysicsShapeEdgePolygon.create(points, count, material, border) end

---Get this polygon's points array.
---
---@param outPoints cc.Vec2 # A Vec2 array pointer.
function PhysicsShapeEdgePolygon:getPoints(outPoints) end

---Get this polygon's points array count.
---
---@return integer # An integer number.
function PhysicsShapeEdgePolygon:getPointsCount() end

return PhysicsShapeEdgePolygon