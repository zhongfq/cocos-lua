---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Vec2

---Defines a 2-element floating point vector.
---@class cc.Vec2 
---@field lengthSq number Calculates the square length of a Vec2 (not calling sqrt() ) \return float \since v2.1.4 \js NA \lua NA
---@field normalized cc.Vec2 Get the normalized vector.
---@field one boolean Indicates whether this vector contains all ones. <br><br>\return true if this vector contains all ones, false otherwise.
---@field perp cc.Vec2 Calculates perpendicular of v, rotated 90 degrees counter-clockwise -- cross(v, perp(v)) >= 0 \return Vec2 \since v2.1.4 \js NA \lua NA
---@field rPerp cc.Vec2 Calculates perpendicular of v, rotated 90 degrees clockwise -- cross(v, rperp(v)) <= 0 \return Vec2 \since v2.1.4 \js NA \lua NA
---@field zero boolean Indicates whether this vector contains all zeros. <br><br>\return true if this vector contains all zeros, false otherwise.
---@field x number
---@field y number
---@field ANCHOR_BOTTOM_LEFT cc.Vec2
---@field ANCHOR_BOTTOM_RIGHT cc.Vec2
---@field ANCHOR_MIDDLE cc.Vec2
---@field ANCHOR_MIDDLE_BOTTOM cc.Vec2
---@field ANCHOR_MIDDLE_LEFT cc.Vec2
---@field ANCHOR_MIDDLE_RIGHT cc.Vec2
---@field ANCHOR_MIDDLE_TOP cc.Vec2
---@field ANCHOR_TOP_LEFT cc.Vec2
---@field ANCHOR_TOP_RIGHT cc.Vec2
---@field ONE cc.Vec2
---@field UNIT_X cc.Vec2
---@field UNIT_Y cc.Vec2
---@field ZERO cc.Vec2
---@operator add(cc.Vec2):cc.Vec2
---@operator div(number):cc.Vec2
---@operator mul(number):cc.Vec2
---@operator sub(cc.Vec2):cc.Vec2
---@operator unm:cc.Vec2
local Vec2 = {}

---Calculates the sum of this vector with the given vector.
---
---Note: this does not modify this vector.
---
---@param v cc.Vec2 # The vector to add.
---@return cc.Vec2 # The vector sum.
function Vec2:__add(v) end

---Returns the components of this vector divided by the given constant
---
---Note: this does not modify this vector.
---
---@param s number # the constant to divide this vector with
---@return cc.Vec2 # a smaller vector
function Vec2:__div(s) end

---Determines if this vector is equal to the given vector.
---
---@param v cc.Vec2 # The vector to compare against.
---
---@return boolean # True if this vector is equal to the given vector, false otherwise.
function Vec2:__eq(v) end

---@return any
function Vec2:__gc() end

---Determines if this vector is less than the given vector.
---
---@param v cc.Vec2 # The vector to compare against.
---
---@return boolean # True if this vector is less than the given vector, false otherwise.
function Vec2:__lt(v) end

---Calculates the scalar product of this vector with the given value.
---
---Note: this does not modify this vector.
---
---@param s number # The value to scale by.
---@return cc.Vec2 # The scaled vector.
function Vec2:__mul(s) end

---Calculates the sum of this vector with the given vector.
---
---Note: this does not modify this vector.
---
---@param v cc.Vec2 # The vector to add.
---@return cc.Vec2 # The vector sum.
function Vec2:__sub(v) end

---Calculates the negation of this vector.
---
---Note: this does not modify this vector.
---
---@return cc.Vec2 # The negation of this vector.
function Vec2:__unm() end

---Adds the elements of the specified vector to this one.
---
---@param v cc.Vec2 # The vector to add.
---
---Adds the specified vectors and stores the result in dst.
---
---\param v1 The first vector.
---\param v2 The second vector.
---\param dst A vector to store the result in.
---@overload fun(v1: cc.Vec2, v2: cc.Vec2, dst: cc.Vec2)
function Vec2:add(v) end

---Returns the angle (in radians) between the specified vectors.
---
---@param v1 cc.Vec2 # The first vector.
---@param v2 cc.Vec2 # The second vector.
---
---@return number # The angle between the two vectors (in radians).
function Vec2.angle(v1, v2) end

---Clamps this vector within the specified range.
---
---@param min cc.Vec2 # The minimum value.
---@param max cc.Vec2 # The maximum value.
---
---Clamps the specified vector within the specified range and returns it in dst.
---
---\param v The vector to clamp.
---\param min The minimum value.
---\param max The maximum value.
---\param dst A vector to store the result in.
---@overload fun(v: cc.Vec2, min: cc.Vec2, max: cc.Vec2, dst: cc.Vec2)
function Vec2:clamp(min, max) end

---Run a math operation function on each point component
---absf, floorf, ceilf, roundf
---any function that has the signature: float func(float);
---For example: let's try to take the floor of x,y
---p.compOp(floorf);
---\since v3.0
---\js NA
---\lua NA
---@param function_ fun(arg1: number): number
---@return cc.Vec2
function Vec2:compOp(function_) end

---Calculates cross product of two points.
---@return number # float
---\since v2.1.4
---\js NA
---\lua NA
---@param other cc.Vec2
function Vec2:cross(other) end

---Returns the distance between this vector and v.
---
---@param v cc.Vec2 # The other vector.
---
---@return number # The distance between this vector and v.
---
---\see distanceSquared
function Vec2:distance(v) end

---Returns the squared distance between this vector and v.
---
---When it is not necessary to get the exact distance between
---two vectors (for example, when simply comparing the
---distance between different vectors), it is advised to use
---this method instead of distance.
---
---@param v cc.Vec2 # The other vector.
---
---@return number # The squared distance between this vector and v.
---
---\see distance
function Vec2:distanceSquared(v) end

---Returns the dot product of this vector and the specified vector.
---
---@param v cc.Vec2 # The vector to compute the dot product with.
---
---@return number # The dot product.
---
---Returns the dot product between the specified vectors.
---
---\param v1 The first vector.
---\param v2 The second vector.
---
---\return The dot product between the vectors.
---@overload fun(v1: cc.Vec2, v2: cc.Vec2): number
function Vec2:dot(v) end

---\js NA
---@param target cc.Vec2
---@return boolean
function Vec2:equals(target) end

---\js NA
---\lua NA
---@param a number
---@return cc.Vec2
function Vec2.forAngle(a) end

---@return boolean # s if points have fuzzy equality which means equal with some degree of variance.
---\since v2.1.4
---\js NA
---\lua NA
---@param target cc.Vec2
---@param variance number
function Vec2:fuzzyEquals(target, variance) end

---@return number # s the angle in radians between this vector and the x axis
---\since v2.1.4
---\js NA
---\lua NA
---
---\returns the angle in radians between two vector directions
---\since v2.1.4
---\js NA
---\lua NA
---@overload fun(self: cc.Vec2, other: cc.Vec2): number
function Vec2:getAngle() end

---Clamp a point between from and to.
---\since v3.0
---\js NA
---\lua NA
---@param min_inclusive cc.Vec2
---@param max_inclusive cc.Vec2
---@return cc.Vec2
function Vec2:getClampPoint(min_inclusive, max_inclusive) end

---Calculates the distance between two points
---@return number # float
---\since v2.1.4
---\js NA
---\lua NA
---@param other cc.Vec2
function Vec2:getDistance(other) end

---Calculates the square distance between two points (not calling sqrt() )
---@return number # float
---\since v2.1.4
---\js NA
---\lua NA
---@param other cc.Vec2
function Vec2:getDistanceSq(other) end

---returns the intersection point of line A-B, C-D
---\since v3.0
---\js NA
---\lua NA
---@param A cc.Vec2
---@param B cc.Vec2
---@param C cc.Vec2
---@param D cc.Vec2
---@return cc.Vec2
function Vec2.getIntersectPoint(A, B, C, D) end

---Calculates distance between point an origin
---@return number # float
---\since v2.1.4
---\js NA
---\lua NA
function Vec2:getLength() end

---Calculates the square length of a Vec2 (not calling sqrt() )
---@return number # float
---\since v2.1.4
---\js NA
---\lua NA
function Vec2:getLengthSq() end

---Calculates midpoint between two points.
---@return cc.Vec2 # Vec2
---\since v3.0
---\js NA
---\lua NA
---@param other cc.Vec2
function Vec2:getMidpoint(other) end

---Get the normalized vector.
---@return cc.Vec2
function Vec2:getNormalized() end

---Calculates perpendicular of v, rotated 90 degrees counter-clockwise -- cross(v, perp(v)) >= 0
---@return cc.Vec2 # Vec2
---\since v2.1.4
---\js NA
---\lua NA
function Vec2:getPerp() end

---Calculates perpendicular of v, rotated 90 degrees clockwise -- cross(v, rperp(v)) <= 0
---@return cc.Vec2 # Vec2
---\since v2.1.4
---\js NA
---\lua NA
function Vec2:getRPerp() end

---A general line-line intersection test
---@param A cc.Vec2 # the startpoint for the first line L1 = (A - B)
---@param B cc.Vec2 # the endpoint for the first line L1 = (A - B)
---@param C cc.Vec2 # the startpoint for the second line L2 = (C - D)
---@param D cc.Vec2 # the endpoint for the second line L2 = (C - D)
---@param S olua.float # the range for a hitpoint in L1 (p = A + S*(B - A))
---@param T olua.float # the range for a hitpoint in L2 (p = C + T*(D - C))
---@return boolean # whether these two lines intersects.
---Note that to truly test intersection for segments we have to make
---sure that S & T lie within [0..1] and for rays, make sure S & T > 0
---the hit point is        C + T * (D - C);
---the hit point also is   A + S * (B - A);
---\since 3.0
---\js NA
---\lua NA
---@overload fun(A: cc.Vec2, B: cc.Vec2, C: cc.Vec2, D: cc.Vec2): boolean
---@overload fun(A: cc.Vec2, B: cc.Vec2, C: cc.Vec2, D: cc.Vec2, S: olua.float): boolean
function Vec2.isLineIntersect(A, B, C, D, S, T) end

---returns true if Line A-B overlap with segment C-D
---\since v3.0
---\js NA
---\lua NA
---@param A cc.Vec2
---@param B cc.Vec2
---@param C cc.Vec2
---@param D cc.Vec2
---@return boolean
function Vec2.isLineOverlap(A, B, C, D) end

---returns true if Line A-B parallel with segment C-D
---\since v3.0
---\js NA
---\lua NA
---@param A cc.Vec2
---@param B cc.Vec2
---@param C cc.Vec2
---@param D cc.Vec2
---@return boolean
function Vec2.isLineParallel(A, B, C, D) end

---Indicates whether this vector contains all ones.
---
---@return boolean # true if this vector contains all ones, false otherwise.
function Vec2:isOne() end

---returns true if Segment A-B intersects with segment C-D
---\since v3.0
---\js NA
---\lua NA
---@param A cc.Vec2
---@param B cc.Vec2
---@param C cc.Vec2
---@param D cc.Vec2
---@return boolean
function Vec2.isSegmentIntersect(A, B, C, D) end

---returns true if Segment A-B overlap with segment C-D
---\since v3.0
---\js NA
---\lua NA
---@param A cc.Vec2
---@param B cc.Vec2
---@param C cc.Vec2
---@param D cc.Vec2
---@param S cc.Vec2
---@param E cc.Vec2
---@return boolean
---@overload fun(A: cc.Vec2, B: cc.Vec2, C: cc.Vec2, D: cc.Vec2): boolean
---@overload fun(A: cc.Vec2, B: cc.Vec2, C: cc.Vec2, D: cc.Vec2, S: cc.Vec2): boolean
function Vec2.isSegmentOverlap(A, B, C, D, S, E) end

---Indicates whether this vector contains all zeros.
---
---@return boolean # true if this vector contains all zeros, false otherwise.
function Vec2:isZero() end

---Computes the length of this vector.
---
---@return number # The length of the vector.
---
---\see lengthSquared
function Vec2:length() end

---Returns the squared length of this vector.
---
---When it is not necessary to get the exact length of a
---vector (for example, when simply comparing the lengths of
---different vectors), it is advised to use this method
---instead of length.
---
---@return number # The squared length of the vector.
---
---\see length
function Vec2:lengthSquared() end

---Linear Interpolation between two points a and b
---@return cc.Vec2 # s
---alpha == 0 ? a
---alpha == 1 ? b
---otherwise a value between a..b
---\since v2.1.4
---\js NA
---\lua NA
---@param other cc.Vec2
---@param alpha number
function Vec2:lerp(other, alpha) end

---Negates this vector.
function Vec2:negate() end

---Constructs a new vector initialized to all zeros.
---@return cc.Vec2
---
---Constructs a new vector initialized to the specified values.
---
---\param xx The x coordinate.
---\param yy The y coordinate.
---@overload fun(xx: number, yy: number): cc.Vec2
---
---Constructs a new vector from the values in the specified array.
---
---\param array An array containing the elements of the vector in the order x, y.
---@overload fun(array: olua.float): cc.Vec2
---
---Constructs a vector that describes the direction between the specified points.
---
---\param p1 The first point.
---\param p2 The second point.
---@overload fun(p1: cc.Vec2, p2: cc.Vec2): cc.Vec2
function Vec2.new() end

---Normalizes this vector.
---
---This method normalizes this Vec2 so that it is of
---unit length (in other words, the length of the vector
---after calling this method will be 1.0f). If the vector
---already has unit length or if the length of the vector
---is zero, this method does nothing.
---
---\return This vector, after the normalization occurs.
function Vec2:normalize() end

---Calculates the projection of this over other.
---@return cc.Vec2 # Vec2
---\since v2.1.4
---\js NA
---\lua NA
---@param other cc.Vec2
function Vec2:project(other) end

---Rotates this vector by angle (specified in radians) around the given point.
---
---@param point cc.Vec2 # The point to rotate around.
---@param angle number # The angle to rotate by (in radians).
---
---Complex multiplication of two points ("rotates" two points).
---\return Vec2 vector with an angle of this.getAngle() + other.getAngle(),
---and a length of this.getLength() * other.getLength().
---\since v2.1.4
---\js NA
---\lua NA
---@overload fun(self: cc.Vec2, other: cc.Vec2): cc.Vec2
function Vec2:rotate(point, angle) end

---Rotates a point counter clockwise by the angle around a pivot
---@param pivot cc.Vec2 # is the pivot, naturally
---@param angle number # is the angle of rotation ccw in radians
---@return cc.Vec2 # s the rotated point
---\since v2.1.4
---\js NA
---\lua NA
function Vec2:rotateByAngle(pivot, angle) end

---Scales all elements of this vector by the specified value.
---
---@param scalar number # The scalar value.
---
---Scales each element of this vector by the matching component of scale.
---
---\param scale The vector to scale by.
---@overload fun(self: cc.Vec2, scale: cc.Vec2)
function Vec2:scale(scalar) end

---Sets the elements of this vector to the specified values.
---
---@param xx number # The new x coordinate.
---@param yy number # The new y coordinate.
---
---Sets the elements of this vector from the values in the specified array.
---
---\param array An array containing the elements of the vector in the order x, y.
---@overload fun(self: cc.Vec2, array: olua.float)
---
---Sets the elements of this vector to those in the specified vector.
---
---\param v The vector to copy.
---@overload fun(self: cc.Vec2, v: cc.Vec2)
---
---Sets this vector to the directional vector between the specified points.
---
---\param p1 The first point.
---\param p2 The second point.
---@overload fun(self: cc.Vec2, p1: cc.Vec2, p2: cc.Vec2)
function Vec2:set(xx, yy) end

---\js NA
---\lua NA
---@param xx number
---@param yy number
function Vec2:setPoint(xx, yy) end

---Sets the elements of this vector to zero.
function Vec2:setZero() end

---Updates this vector towards the given target using a smoothing function.
---The given response time determines the amount of smoothing (lag). A longer
---response time yields a smoother result and more lag. To force this vector to
---follow the target closely, provide a response time that is very small relative
---to the given elapsed time.
---
---@param target cc.Vec2 # target value.
---@param elapsedTime number # elapsed time between calls.
---@param responseTime number # response time (in the same units as elapsedTime).
function Vec2:smooth(target, elapsedTime, responseTime) end

---Subtracts this vector and the specified vector as (this - v)
---and stores the result in this vector.
---
---@param v cc.Vec2 # The vector to subtract.
---
---Subtracts the specified vectors and stores the result in dst.
---The resulting vector is computed as (v1 - v2).
---
---\param v1 The first vector.
---\param v2 The second vector.
---\param dst The destination vector.
---@overload fun(v1: cc.Vec2, v2: cc.Vec2, dst: cc.Vec2)
function Vec2:subtract(v) end

---Unrotates two points.
---@return cc.Vec2 # Vec2 vector with an angle of this.getAngle() - other.getAngle(),
---and a length of this.getLength() * other.getLength().
---\since v2.1.4
---\js NA
---\lua NA
---@param other cc.Vec2
function Vec2:unrotate(other) end

return Vec2