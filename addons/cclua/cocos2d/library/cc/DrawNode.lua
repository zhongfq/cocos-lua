---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.DrawNode

---\class DrawNode
---Node that draws dots, segments and polygons.
---Faster than the "drawing primitives" since they draws everything in one single batch.
---\since v2.1
---@class cc.DrawNode : cc.Node
---@field blendFunc cc.BlendFunc Get the color mixed mode. \lua NA
---@field isolated boolean 
---@field lineWidth number 
local DrawNode = {}

---Clear the geometry in the node's buffer.
function DrawNode:clear() end

---creates and initialize a DrawNode node.
---
---@return cc.DrawNode # Return an autorelease object.
---@param defaultLineWidth number
---@overload fun(): cc.DrawNode
function DrawNode.create(defaultLineWidth) end

---Draws a Cardinal Spline path.
---
---@param config cc.PointArray # A array point.
---@param tension number # The tension of the spline.
---@param segments integer # The number of segments.
---@param color any # Set the Spline color.
function DrawNode:drawCardinalSpline(config, tension, segments, color) end

---Draws a Catmull Rom path.
---
---@param points cc.PointArray # A point array  of control point.
---@param segments integer # The number of segments.
---@param color any # The Catmull Rom color.
function DrawNode:drawCatmullRom(points, segments, color) end

---Draws a circle given the center, radius and number of segments.
---
---@param center cc.Vec2 # The circle center point.
---@param radius number # The circle rotate of radius.
---@param angle number # The circle angle.
---@param segments integer # The number of segments.
---@param drawLineToCenter boolean # Whether or not draw the line from the origin to center.
---@param scaleX number # The scale value in x.
---@param scaleY number # The scale value in y.
---@param color any # Set the circle color.
---
---Draws a circle given the center, radius and number of segments.
---
---\param center The circle center point.
---\param radius The circle rotate of radius.
---\param angle  The circle angle.
---\param segments The number of segments.
---\param drawLineToCenter Whether or not draw the line from the origin to center.
---\param color Set the circle color.
---@overload fun(self: cc.DrawNode, center: cc.Vec2, radius: number, angle: number, segments: integer, drawLineToCenter: boolean, color: any)
function DrawNode:drawCircle(center, radius, angle, segments, drawLineToCenter, scaleX, scaleY, color) end

---Draw a cubic bezier curve with color and number of segments
---
---@param origin cc.Vec2 # The origin of the bezier path.
---@param control1 cc.Vec2 # The first control of the bezier path.
---@param control2 cc.Vec2 # The second control of the bezier path.
---@param destination cc.Vec2 # The destination of the bezier path.
---@param segments integer # The number of segments.
---@param color any # Set the cubic bezier color.
function DrawNode:drawCubicBezier(origin, control1, control2, destination, segments, color) end

---draw a dot at a position, with a given radius and color. 
---
---@param pos cc.Vec2 # The dot center.
---@param radius number # The dot radius.
---@param color any # The dot color.
function DrawNode:drawDot(pos, radius, color) end

---Draw an line from origin to destination with color. 
---
---@param origin cc.Vec2 # The line origin.
---@param destination cc.Vec2 # The line destination.
---@param color any # The line color.
---\js NA
function DrawNode:drawLine(origin, destination, color) end

---Draw a point.
---
---@param point cc.Vec2 # A Vec2 used to point.
---@param pointSize number # The point size.
---@param color any # The point color.
---\js NA
function DrawNode:drawPoint(point, pointSize, color) end

---Draw a group point.
---
---@param position cc.Vec2 # A Vec2 pointer.
---@param numberOfPoints integer # The number of points.
---@param color any # The point color.
---\js NA
---
---Draw a group point.
---
---\param position A Vec2 pointer.
---\param numberOfPoints The number of points.
---\param pointSize The point size.
---\param color The point color.
---\js NA
---@overload fun(self: cc.DrawNode, position: cc.Vec2, numberOfPoints: integer, pointSize: number, color: any)
function DrawNode:drawPoints(position, numberOfPoints, color) end

---Draws a polygon given a pointer to point coordinates and the number of vertices measured in points.
---The polygon can be closed or open.
---
---@param poli cc.Vec2 # A pointer to point coordinates.
---@param numberOfPoints integer # The number of vertices measured in points.
---@param closePolygon boolean # The polygon can be closed or open.
---@param color any # The polygon color.
function DrawNode:drawPoly(poli, numberOfPoints, closePolygon, color) end

---draw a polygon with a fill color and line color
---\code
---When this function bound into js or lua,the parameter will be changed
---In js: var drawPolygon(var Arrayofpoints, var fillColor, var width, var borderColor)
---In lua:local drawPolygon(local pointTable,local tableCount,local fillColor,local width,local borderColor)
---\endcode
---@param verts cc.Vec2 # A pointer to point coordinates.
---@param count integer # The number of verts measured in points.
---@param fillColor any # The color will fill in polygon.
---@param borderWidth number # The border of line width.
---@param borderColor any # The border of line color.
---\js NA
function DrawNode:drawPolygon(verts, count, fillColor, borderWidth, borderColor) end

---Draws a quad bezier path.
---
---@param origin cc.Vec2 # The origin of the bezier path.
---@param control cc.Vec2 # The control of the bezier path.
---@param destination cc.Vec2 # The destination of the bezier path.
---@param segments integer # The number of segments.
---@param color any # Set the quad bezier color.
function DrawNode:drawQuadBezier(origin, control, destination, segments, color) end

---Draws a rectangle given the origin and destination point measured in points.
---The origin and the destination can not have the same x and y coordinate.
---
---@param origin cc.Vec2 # The rectangle origin.
---@param destination cc.Vec2 # The rectangle destination.
---@param color any # The rectangle color.
---
---Draws a rectangle with 4 points.
---
---\param p1 The rectangle vertex point.
---\param p2 The rectangle vertex point.
---\param p3 The rectangle vertex point.
---\param p4 The rectangle vertex point.
---\param color The rectangle color.
---@overload fun(self: cc.DrawNode, p1: cc.Vec2, p2: cc.Vec2, p3: cc.Vec2, p4: cc.Vec2, color: any)
function DrawNode:drawRect(origin, destination, color) end

---draw a segment with a radius and color. 
---
---@param from cc.Vec2 # The segment origin.
---@param to cc.Vec2 # The segment destination.
---@param radius number # The segment radius.
---@param color any # The segment color.
function DrawNode:drawSegment(from, to, radius, color) end

---Draws a solid circle given the center, radius and number of segments.
---@param center cc.Vec2 # The circle center point.
---@param radius number # The circle rotate of radius.
---@param angle number # The circle angle.
---@param segments integer # The number of segments.
---@param scaleX number # The scale value in x.
---@param scaleY number # The scale value in y.
---@param color any # The solid circle color.
---\js NA
---
---Draws a solid circle given the center, radius and number of segments.
---\param center The circle center point.
---\param radius The circle rotate of radius.
---\param angle  The circle angle.
---\param segments The number of segments.
---\param color The solid circle color.
---\js NA
---@overload fun(self: cc.DrawNode, center: cc.Vec2, radius: number, angle: number, segments: integer, color: any)
function DrawNode:drawSolidCircle(center, radius, angle, segments, scaleX, scaleY, color) end

---Draws a solid polygon given a pointer to CGPoint coordinates, the number of vertices measured in points, and a color.
---
---@param poli cc.Vec2 # A solid polygon given a pointer to CGPoint coordinates.
---@param numberOfPoints integer # The number of vertices measured in points.
---@param color any # The solid polygon color.
---\js NA
function DrawNode:drawSolidPoly(poli, numberOfPoints, color) end

---Draws a solid rectangle given the origin and destination point measured in points.
---The origin and the destination can not have the same x and y coordinate.
---
---@param origin cc.Vec2 # The rectangle origin.
---@param destination cc.Vec2 # The rectangle destination.
---@param color any # The rectangle color.
---\js NA
function DrawNode:drawSolidRect(origin, destination, color) end

---draw a triangle with color. 
---
---@param p1 cc.Vec2 # The triangle vertex point.
---@param p2 cc.Vec2 # The triangle vertex point.
---@param p3 cc.Vec2 # The triangle vertex point.
---@param color any # The triangle color.
---\js NA
function DrawNode:drawTriangle(p1, p2, p3, color) end

---Get the color mixed mode.
---\lua NA
---@return cc.BlendFunc
function DrawNode:getBlendFunc() end

---@return number
function DrawNode:getLineWidth() end

---@return boolean
function DrawNode:isIsolated() end

---@param lineWidth number
---@return cc.DrawNode
---@overload fun(): cc.DrawNode
function DrawNode.new(lineWidth) end

---Set the color mixed mode.
---\code
---When this function bound into js or lua,the parameter will be changed
---In js: var setBlendFunc(var src, var dst)
---\endcode
---\lua NA
---@param blendFunc cc.BlendFunc
function DrawNode:setBlendFunc(blendFunc) end

---When isolated is set, the position of the node is no longer affected by parent nodes.
---Which means it will be drawn just like a root node.
---@param isolated boolean
function DrawNode:setIsolated(isolated) end

---@param lineWidth number
function DrawNode:setLineWidth(lineWidth) end

return DrawNode