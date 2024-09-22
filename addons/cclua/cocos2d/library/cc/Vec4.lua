---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Vec4

---Defines 4-element floating point vector.
---@class cc.Vec4 
---@field normalized cc.Vec4 Get the normalized vector.
---@field one boolean Indicates whether this vector contains all ones. <br><br>\return true if this vector contains all ones, false otherwise.
---@field zero boolean Indicates whether this vector contains all zeros. <br><br>\return true if this vector contains all zeros, false otherwise.
---@field x number
---@field y number
---@field z number
---@field w number
---@field ONE cc.Vec4
---@field UNIT_W cc.Vec4
---@field UNIT_X cc.Vec4
---@field UNIT_Y cc.Vec4
---@field UNIT_Z cc.Vec4
---@field ZERO cc.Vec4
---@operator add(cc.Vec4):cc.Vec4
---@operator div(number):cc.Vec4
---@operator mul(number):cc.Vec4
---@operator sub(cc.Vec4):cc.Vec4
---@operator unm:cc.Vec4
local Vec4 = {}

---Calculates the sum of this vector with the given vector.
---
---Note: this does not modify this vector.
---
---@param v cc.Vec4 # The vector to add.
---@return cc.Vec4 # The vector sum.
function Vec4:__add(v) end

---Returns the components of this vector divided by the given constant
---
---Note: this does not modify this vector.
---
---@param s number # the constant to divide this vector with
---@return cc.Vec4 # a smaller vector
function Vec4:__div(s) end

---Determines if this vector is equal to the given vector.
---
---@param v cc.Vec4 # The vector to compare against.
---
---@return boolean # True if this vector is equal to the given vector, false otherwise.
function Vec4:__eq(v) end

---@return any
function Vec4:__gc() end

---Determines if this vector is less than the given vector.
---
---@param v cc.Vec4 # The vector to compare against.
---
---@return boolean # True if this vector is less than the given vector, false otherwise.
function Vec4:__lt(v) end

---Calculates the scalar product of this vector with the given value.
---
---Note: this does not modify this vector.
---
---@param s number # The value to scale by.
---@return cc.Vec4 # The scaled vector.
function Vec4:__mul(s) end

---Calculates the sum of this vector with the given vector.
---
---Note: this does not modify this vector.
---
---@param v cc.Vec4 # The vector to add.
---@return cc.Vec4 # The vector sum.
function Vec4:__sub(v) end

---Calculates the negation of this vector.
---
---Note: this does not modify this vector.
---
---@return cc.Vec4 # The negation of this vector.
function Vec4:__unm() end

---Adds the elements of the specified vector to this one.
---
---@param v cc.Vec4 # The vector to add.
---
---Adds the specified vectors and stores the result in dst.
---
---\param v1 The first vector.
---\param v2 The second vector.
---\param dst A vector to store the result in.
---@overload fun(v1: cc.Vec4, v2: cc.Vec4, dst: cc.Vec4)
function Vec4:add(v) end

---Returns the angle (in radians) between the specified vectors.
---
---@param v1 cc.Vec4 # The first vector.
---@param v2 cc.Vec4 # The second vector.
---
---@return number # The angle between the two vectors (in radians).
function Vec4.angle(v1, v2) end

---Clamps this vector within the specified range.
---
---@param min cc.Vec4 # The minimum value.
---@param max cc.Vec4 # The maximum value.
---
---Clamps the specified vector within the specified range and returns it in dst.
---
---\param v The vector to clamp.
---\param min The minimum value.
---\param max The maximum value.
---\param dst A vector to store the result in.
---@overload fun(v: cc.Vec4, min: cc.Vec4, max: cc.Vec4, dst: cc.Vec4)
function Vec4:clamp(min, max) end

---Returns the distance between this vector and v.
---
---@param v cc.Vec4 # The other vector.
---
---@return number # The distance between this vector and v.
---
---\see distanceSquared
function Vec4:distance(v) end

---Returns the squared distance between this vector and v.
---
---When it is not necessary to get the exact distance between
---two vectors (for example, when simply comparing the
---distance between different vectors), it is advised to use
---this method instead of distance.
---
---@param v cc.Vec4 # The other vector.
---
---@return number # The squared distance between this vector and v.
---
---\see distance
function Vec4:distanceSquared(v) end

---Returns the dot product of this vector and the specified vector.
---
---@param v cc.Vec4 # The vector to compute the dot product with.
---
---@return number # The dot product.
---
---Returns the dot product between the specified vectors.
---
---\param v1 The first vector.
---\param v2 The second vector.
---
---\return The dot product between the vectors.
---@overload fun(v1: cc.Vec4, v2: cc.Vec4): number
function Vec4:dot(v) end

---Creates a new vector from an integer interpreted as an RGBA value.
---E.g. 0xff0000ff represents opaque red or the vector (1, 0, 0, 1).
---
---@param color integer # The integer to interpret as an RGBA value.
---
---@return cc.Vec4 # A vector corresponding to the interpreted RGBA color.
function Vec4.fromColor(color) end

---Get the normalized vector.
---@return cc.Vec4
function Vec4:getNormalized() end

---Indicates whether this vector contains all ones.
---
---@return boolean # true if this vector contains all ones, false otherwise.
function Vec4:isOne() end

---Indicates whether this vector contains all zeros.
---
---@return boolean # true if this vector contains all zeros, false otherwise.
function Vec4:isZero() end

---Computes the length of this vector.
---
---@return number # The length of the vector.
---
---\see lengthSquared
function Vec4:length() end

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
function Vec4:lengthSquared() end

---Negates this vector.
function Vec4:negate() end

---Constructs a new vector initialized to all zeros.
---@return cc.Vec4
---
---Constructs a new vector initialized to the specified values.
---
---\param xx The x coordinate.
---\param yy The y coordinate.
---\param zz The z coordinate.
---\param ww The w coordinate.
---@overload fun(xx: number, yy: number, zz: number, ww: number): cc.Vec4
---
---Constructs a new vector from the values in the specified array.
---
---\param array An array containing the elements of the vector in the order x, y, z, w.
---@overload fun(array: olua.float): cc.Vec4
---
---Constructs a vector that describes the direction between the specified points.
---
---\param p1 The first point.
---\param p2 The second point.
---@overload fun(p1: cc.Vec4, p2: cc.Vec4): cc.Vec4
function Vec4.new() end

---Normalizes this vector.
---
---This method normalizes this Vec4 so that it is of
---unit length (in other words, the length of the vector
---after calling this method will be 1.0f). If the vector
---already has unit length or if the length of the vector
---is zero, this method does nothing.
---
---\return This vector, after the normalization occurs.
function Vec4:normalize() end

---Scales all elements of this vector by the specified value.
---
---@param scalar number # The scalar value.
function Vec4:scale(scalar) end

---Sets the elements of this vector to the specified values.
---
---@param xx number # The new x coordinate.
---@param yy number # The new y coordinate.
---@param zz number # The new z coordinate.
---@param ww number # The new w coordinate.
---
---Sets the elements of this vector from the values in the specified array.
---
---\param array An array containing the elements of the vector in the order x, y, z, w.
---@overload fun(self: cc.Vec4, array: olua.float)
---
---Sets the elements of this vector to those in the specified vector.
---
---\param v The vector to copy.
---@overload fun(self: cc.Vec4, v: cc.Vec4)
---
---Sets this vector to the directional vector between the specified points.
---
---\param p1 The first point.
---\param p2 The second point.
---@overload fun(self: cc.Vec4, p1: cc.Vec4, p2: cc.Vec4)
function Vec4:set(xx, yy, zz, ww) end

---Subtracts this vector and the specified vector as (this - v)
---and stores the result in this vector.
---
---@param v cc.Vec4 # The vector to subtract.
---
---Subtracts the specified vectors and stores the result in dst.
---The resulting vector is computed as (v1 - v2).
---
---\param v1 The first vector.
---\param v2 The second vector.
---\param dst The destination vector.
---@overload fun(v1: cc.Vec4, v2: cc.Vec4, dst: cc.Vec4)
function Vec4:subtract(v) end

return Vec4