---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.PhysicsShapePolygon

---A polygon shape.
---@class cc.PhysicsShapePolygon : cc.PhysicsShape
---@field pointsCount integer Get this polygon's points array count. <br><br>\return An integer number.
local PhysicsShapePolygon = {}

---Calculate the area of a polygon with specified value.
---
---@param points cc.Vec2 # A Vec2 object pointer, it is an array of Vec2.
---@param count integer # An integer number, contains the count of the points array.
---@return number # A float number.
function PhysicsShapePolygon.calculateArea(points, count) end

---Calculate the moment of a polygon with specified value.
---
---@param mass number # A float number
---@param points cc.Vec2 # A Vec2 object pointer, it is an array of Vec2.
---@param count integer # An integer number, contains the count of the points array.
---@param offset cc.Vec2 # A Vec2 object, it is the offset from the body's center of gravity in body local coordinates.
---@return number # A float number
---@param radius number
---@overload fun(mass: number, points: cc.Vec2, count: integer): number
---@overload fun(mass: number, points: cc.Vec2, count: integer, offset: cc.Vec2): number
function PhysicsShapePolygon.calculateMoment(mass, points, count, offset, radius) end

---Creates a PhysicsShapePolygon with specified value.
---
---@param points cc.Vec2 # A Vec2 object pointer, it is an array of Vec2.
---@param count integer # An integer number, contains the count of the points array.
---@param material cc.PhysicsMaterial # A PhysicsMaterial object, the default value is PHYSICSSHAPE_MATERIAL_DEFAULT.
---@param offset cc.Vec2 # A Vec2 object, it is the offset from the body's center of gravity in body local coordinates.
---@return cc.PhysicsShapePolygon # An autoreleased PhysicsShapePolygon object pointer.
---@param radius number
---@overload fun(points: cc.Vec2, count: integer): cc.PhysicsShapePolygon
---@overload fun(points: cc.Vec2, count: integer, material: cc.PhysicsMaterial): cc.PhysicsShapePolygon
---@overload fun(points: cc.Vec2, count: integer, material: cc.PhysicsMaterial, offset: cc.Vec2): cc.PhysicsShapePolygon
function PhysicsShapePolygon.create(points, count, material, offset, radius) end

---Get a point of this polygon's points array.
---
---@param i integer # A index of this polygon's points array.
---@return cc.Vec2 # A point value.
function PhysicsShapePolygon:getPoint(i) end

---Get this polygon's points array.
---
---@param outPoints cc.Vec2 # A Vec2 array pointer.
function PhysicsShapePolygon:getPoints(outPoints) end

---Get this polygon's points array count.
---
---@return integer # An integer number.
function PhysicsShapePolygon:getPointsCount() end

return PhysicsShapePolygon