---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Vec3

---Defines a 3-element floating point vector.
---
---When using a vector to represent a surface normal,
---the vector should typically be normalized.
---Other uses of directional vectors may wish to leave
---the magnitude of the vector intact. When used as a point,
---the elements of the vector represent a position in 3D space.
---@class cc.Vec3 
---@field normalized cc.Vec3 Get the normalized vector.
---@field one boolean Indicates whether this vector contains all ones. <br><br>\return true if this vector contains all ones, false otherwise.
---@field zero boolean Indicates whether this vector contains all zeros. <br><br>\return true if this vector contains all zeros, false otherwise.
---@field x number
---@field y number
---@field z number
---@field ONE cc.Vec3
---@field UNIT_X cc.Vec3
---@field UNIT_Y cc.Vec3
---@field UNIT_Z cc.Vec3
---@field ZERO cc.Vec3
---@operator add(cc.Vec3):cc.Vec3
---@operator div(number):cc.Vec3
---@operator mul(number):cc.Vec3
---@operator sub(cc.Vec3):cc.Vec3
---@operator unm:cc.Vec3
local Vec3 = {}

---Calculates the sum of this vector with the given vector.
---
---Note: this does not modify this vector.
---
---@param v cc.Vec3 # The vector to add.
---@return cc.Vec3 # The vector sum.
function Vec3:__add(v) end

---Returns the components of this vector divided by the given constant
---
---Note: this does not modify this vector.
---
---@param s number # the constant to divide this vector with
---@return cc.Vec3 # a smaller vector
function Vec3:__div(s) end

---Determines if this vector is equal to the given vector.
---
---@param v cc.Vec3 # The vector to compare against.
---
---@return boolean # True if this vector is equal to the given vector, false otherwise.
function Vec3:__eq(v) end

---@return any
function Vec3:__gc() end

---Returns true if the vector's scalar components are all greater
---that the ones of the vector it is compared against.
---@param rhs cc.Vec3
---@return boolean
function Vec3:__lt(rhs) end

---Calculates the scalar product of this vector with the given value.
---
---Note: this does not modify this vector.
---
---@param s number # The value to scale by.
---@return cc.Vec3 # The scaled vector.
function Vec3:__mul(s) end

---Calculates the difference of this vector with the given vector.
---
---Note: this does not modify this vector.
---
---@param v cc.Vec3 # The vector to subtract.
---@return cc.Vec3 # The vector difference.
function Vec3:__sub(v) end

---Calculates the negation of this vector.
---
---Note: this does not modify this vector.
---
---@return cc.Vec3 # The negation of this vector.
function Vec3:__unm() end

---Adds the elements of the specified vector to this one.
---
---@param v cc.Vec3 # The vector to add.
---
---Adds the elements of this vector to the specified values.
---
---\param xx The add x coordinate.
---\param yy The add y coordinate.
---\param zz The add z coordinate.
---@overload fun(self: cc.Vec3, xx: number, yy: number, zz: number)
---
---Adds the specified vectors and stores the result in dst.
---
---\param v1 The first vector.
---\param v2 The second vector.
---\param dst A vector to store the result in.
---@overload fun(v1: cc.Vec3, v2: cc.Vec3, dst: cc.Vec3)
function Vec3:add(v) end

---Returns the angle (in radians) between the specified vectors.
---
---@param v1 cc.Vec3 # The first vector.
---@param v2 cc.Vec3 # The second vector.
---
---@return number # The angle between the two vectors (in radians).
function Vec3.angle(v1, v2) end

---Clamps this vector within the specified range.
---
---@param min cc.Vec3 # The minimum value.
---@param max cc.Vec3 # The maximum value.
---
---Clamps the specified vector within the specified range and returns it in dst.
---
---\param v The vector to clamp.
---\param min The minimum value.
---\param max The maximum value.
---\param dst A vector to store the result in.
---@overload fun(v: cc.Vec3, min: cc.Vec3, max: cc.Vec3, dst: cc.Vec3)
function Vec3:clamp(min, max) end

---Sets this vector to the cross product between itself and the specified vector.
---
---@param v cc.Vec3 # The vector to compute the cross product with.
---
---Computes the cross product of the specified vectors and stores the result in dst.
---
---\param v1 The first vector.
---\param v2 The second vector.
---\param dst A vector to store the result in.
---@overload fun(v1: cc.Vec3, v2: cc.Vec3, dst: cc.Vec3)
function Vec3:cross(v) end

---Returns the distance between this vector and v.
---
---@param v cc.Vec3 # The other vector.
---
---@return number # The distance between this vector and v.
---
---\see distanceSquared
function Vec3:distance(v) end

---Returns the squared distance between this vector and v.
---
---When it is not necessary to get the exact distance between
---two vectors (for example, when simply comparing the
---distance between different vectors), it is advised to use
---this method instead of distance.
---
---@param v cc.Vec3 # The other vector.
---
---@return number # The squared distance between this vector and v.
---
---\see distance
function Vec3:distanceSquared(v) end

---Returns the dot product of this vector and the specified vector.
---
---@param v cc.Vec3 # The vector to compute the dot product with.
---
---@return number # The dot product.
---
---Returns the dot product between the specified vectors.
---
---\param v1 The first vector.
---\param v2 The second vector.
---
---\return The dot product between the vectors.
---@overload fun(v1: cc.Vec3, v2: cc.Vec3): number
function Vec3:dot(v) end

---Creates a new vector from an integer interpreted as an RGB value.
---E.g. 0xff0000 represents red or the vector (1, 0, 0).
---
---@param color integer # The integer to interpret as an RGB value.
---
---@return cc.Vec3 # A vector corresponding to the interpreted RGB color.
function Vec3.fromColor(color) end

---Get the normalized vector.
---@return cc.Vec3
function Vec3:getNormalized() end

---Indicates whether this vector contains all ones.
---
---@return boolean # true if this vector contains all ones, false otherwise.
function Vec3:isOne() end

---Indicates whether this vector contains all zeros.
---
---@return boolean # true if this vector contains all zeros, false otherwise.
function Vec3:isZero() end

---Computes the length of this vector.
---
---@return number # The length of the vector.
---
---\see lengthSquared
function Vec3:length() end

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
function Vec3:lengthSquared() end

---Linear interpolation between two vectors A and B by alpha which
---is in the range [0,1]
---@param target cc.Vec3
---@param alpha number
---@return cc.Vec3
function Vec3:lerp(target, alpha) end

---Negates this vector.
function Vec3:negate() end

---Constructs a new vector initialized to all zeros.
---@return cc.Vec3
---
---Constructs a new vector initialized to the specified values.
---
---\param xx The x coordinate.
---\param yy The y coordinate.
---\param zz The z coordinate.
---@overload fun(xx: number, yy: number, zz: number): cc.Vec3
---
---Constructs a new vector from the values in the specified array.
---
---\param array An array containing the elements of the vector in the order x, y, z.
---@overload fun(array: olua.float): cc.Vec3
---
---Constructs a vector that describes the direction between the specified points.
---
---\param p1 The first point.
---\param p2 The second point.
---@overload fun(p1: cc.Vec3, p2: cc.Vec3): cc.Vec3
function Vec3.new() end

---Normalizes this vector.
---
---This method normalizes this Vec3 so that it is of
---unit length (in other words, the length of the vector
---after calling this method will be 1.0f). If the vector
---already has unit length or if the length of the vector
---is zero, this method does nothing.
---
---\return This vector, after the normalization occurs.
function Vec3:normalize() end

---Scales all elements of this vector by the specified value.
---
---@param scalar number # The scalar value.
function Vec3:scale(scalar) end

---Sets the elements of this vector to the specified values.
---
---@param xx number # The new x coordinate.
---@param yy number # The new y coordinate.
---@param zz number # The new z coordinate.
---
---Sets the elements of this vector from the values in the specified array.
---
---\param array An array containing the elements of the vector in the order x, y, z.
---@overload fun(self: cc.Vec3, array: olua.float)
---
---Sets the elements of this vector to those in the specified vector.
---
---\param v The vector to copy.
---@overload fun(self: cc.Vec3, v: cc.Vec3)
---
---Sets this vector to the directional vector between the specified points.
---@overload fun(self: cc.Vec3, p1: cc.Vec3, p2: cc.Vec3)
function Vec3:set(xx, yy, zz) end

---Sets the elements of this vector to zero.
function Vec3:setZero() end

---Updates this vector towards the given target using a smoothing function.
---The given response time determines the amount of smoothing (lag). A longer
---response time yields a smoother result and more lag. To force this vector to
---follow the target closely, provide a response time that is very small relative
---to the given elapsed time.
---
---@param target cc.Vec3 # target value.
---@param elapsedTime number # elapsed time between calls.
---@param responseTime number # response time (in the same units as elapsedTime).
function Vec3:smooth(target, elapsedTime, responseTime) end

---Subtracts this vector and the specified vector as (this - v)
---and stores the result in this vector.
---
---@param v cc.Vec3 # The vector to subtract.
---
---Subtracts the specified vectors and stores the result in dst.
---The resulting vector is computed as (v1 - v2).
---
---\param v1 The first vector.
---\param v2 The second vector.
---\param dst The destination vector.
---@overload fun(v1: cc.Vec3, v2: cc.Vec3, dst: cc.Vec3)
function Vec3:subtract(v) end

return Vec3