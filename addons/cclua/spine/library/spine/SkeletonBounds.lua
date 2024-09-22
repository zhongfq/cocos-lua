---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.SkeletonBounds

---Collects each BoundingBoxAttachment that is visible and computes the world vertices for its polygon.
---The polygon vertices are provided along with convenience methods for doing hit detection.
---@class spine.SkeletonBounds : spine.SpineObject
---@field boundingBoxes any Returns all bounding boxes. Requires a call to update() first.
---@field height number 
---@field polygons any Returns all polygons or an empty vector. Requires a call to update() first.
---@field width number 
local SkeletonBounds = {}

---Returns true if the axis aligned bounding box intersects the axis aligned bounding box of the specified bounds.
---@param bounds spine.SkeletonBounds
---@return boolean
function SkeletonBounds:aabbIntersectsSkeleton(bounds) end

---Returns true if the axis aligned bounding box contains the point.
---@param x number
---@param y number
---@return boolean
function SkeletonBounds:aabbcontainsPoint(x, y) end

---Returns true if the axis aligned bounding box intersects the line segment.
---@param x1 number
---@param y1 number
---@param x2 number
---@param y2 number
---@return boolean
function SkeletonBounds:aabbintersectsSegment(x1, y1, x2, y2) end

---Returns true if the polygon contains the point.
---@param polygon spine.Polygon
---@param x number
---@param y number
---@return boolean
---
---Returns the first bounding box attachment that contains the point, or NULL. When doing many checks, it is usually more
---efficient to only call this method if {@link #aabbcontainsPoint(float, float)} returns true.
---@overload fun(self: spine.SkeletonBounds, x: number, y: number): spine.BoundingBoxAttachment
function SkeletonBounds:containsPoint(polygon, x, y) end

---Returns the bounding box for the given polygon or null. Requires a call to update() first.
---@param polygon spine.Polygon
---@return spine.BoundingBoxAttachment
function SkeletonBounds:getBoundingBox(polygon) end

---Returns all bounding boxes. Requires a call to update() first.
---@return any
function SkeletonBounds:getBoundingBoxes() end

---@return number
function SkeletonBounds:getHeight() end

---Returns the polygon for the given bounding box attachment or null if no
---polygon can be found for the attachment. Requires a call to update() first.
---@param attachment spine.BoundingBoxAttachment
---@return spine.Polygon
function SkeletonBounds:getPolygon(attachment) end

---Returns all polygons or an empty vector. Requires a call to update() first.
---@return any
function SkeletonBounds:getPolygons() end

---@return number
function SkeletonBounds:getWidth() end

---Returns the first bounding box attachment that contains the line segment, or NULL. When doing many checks, it is usually
---more efficient to only call this method if {@link #aabbintersectsSegment(float, float, float, float)} returns true.
---@param x1 number
---@param y1 number
---@param x2 number
---@param y2 number
---@return spine.BoundingBoxAttachment
---
---Returns true if the polygon contains the line segment.
---@overload fun(self: spine.SkeletonBounds, polygon: spine.Polygon, x1: number, y1: number, x2: number, y2: number): boolean
function SkeletonBounds:intersectsSegment(x1, y1, x2, y2) end

---@return spine.SkeletonBounds
function SkeletonBounds.new() end

---Clears any previous polygons, finds all visible bounding box attachments,
---and computes the world vertices for each bounding box's polygon.
---@param skeleton spine.Skeleton # The skeleton.
---@param updateAabb boolean # 
---If true, the axis aligned bounding box containing all the polygons is computed.
---If false, the SkeletonBounds AABB methods will always return true.
function SkeletonBounds:update(skeleton, updateAabb) end

return SkeletonBounds