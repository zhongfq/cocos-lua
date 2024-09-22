---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Quaternion

---Defines a 4-element quaternion that represents the orientation of an object in space.
---
---Quaternions are typically used as a replacement for euler angles and rotation matrices as a way to achieve smooth interpolation and avoid gimbal lock.
---
---Note that this quaternion class does not automatically keep the quaternion normalized. Therefore, care must be taken to normalize the quaternion when necessary, by calling the normalize method.
---This class provides three methods for doing quaternion interpolation: lerp, slerp, and squad.
---
---lerp (linear interpolation): the interpolation curve gives a straight line in quaternion space. It is simple and fast to compute. The only problem is that it does not provide constant angular velocity. Note that a constant velocity is not necessarily a requirement for a curve;
---slerp (spherical linear interpolation): the interpolation curve forms a great arc on the quaternion unit sphere. Slerp provides constant angular velocity;
---squad (spherical spline interpolation): interpolating between a series of rotations using slerp leads to the following problems:
---- the curve is not smooth at the control points;
---- the angular velocity is not constant;
---- the angular velocity is not continuous at the control points.
---
---Since squad is continuously differentiable, it remedies the first and third problems mentioned above.
---The slerp method provided here is intended for interpolation of principal rotations. It treats +q and -q as the same principal rotation and is at liberty to use the negative of either input. The resulting path is always the shorter arc.
---
---The lerp method provided here interpolates strictly in quaternion space. Note that the resulting path may pass through the origin if interpolating between a quaternion and its exact negative.
---
---As an example, consider the following quaternions:
---
---q1 = (0.6, 0.8, 0.0, 0.0),
---q2 = (0.0, 0.6, 0.8, 0.0),
---q3 = (0.6, 0.0, 0.8, 0.0), and
---q4 = (-0.8, 0.0, -0.6, 0.0).
---For the point p = (1.0, 1.0, 1.0), the following figures show the trajectories of p using lerp, slerp, and squad.
---@class cc.Quaternion 
---@field conjugated cc.Quaternion Gets the conjugate of this quaternion.
---@field inversed cc.Quaternion Gets the inverse of this quaternion. <br><br>Note that the inverse of a quaternion is equal to its conjugate when the quaternion is unit-length. For this reason, it is more efficient to use the conjugate method directly when you know your quaternion is already unit-length.
---@field normalized cc.Quaternion Get the normalized quaternion. <br><br>If the quaternion already has unit length or if the length of the quaternion is zero, this method simply copies this vector.
---@field x number
---@field y number
---@field z number
---@field w number
---@field ZERO cc.Quaternion
---@operator mul(cc.Quaternion):cc.Quaternion
local Quaternion = {}

---@return any
function Quaternion:__gc() end

---Calculates the quaternion product of this quaternion with the given quaternion.
---
---Note: this does not modify this quaternion.
---
---@param q cc.Quaternion # The quaternion to multiply.
---@return cc.Quaternion # The quaternion product.
---
---Calculates the quaternion product of this quaternion with the given vec3.
---\param v The vec3 to multiply.
---\return The vec3 product.
---@overload fun(self: cc.Quaternion, v: cc.Vec3): cc.Vec3
function Quaternion:__mul(q) end

---Sets this quaternion to the conjugate of itself.
function Quaternion:conjugate() end

---Creates this quaternion equal to the rotation from the specified axis and angle
---and stores the result in dst.
---
---@param axis cc.Vec3 # A vector describing the axis of rotation.
---@param angle number # The angle of rotation (in radians).
---@param dst cc.Quaternion # A quaternion to store the conjugate in.
function Quaternion.createFromAxisAngle(axis, angle, dst) end

---Creates a quaternion equal to the rotational part of the specified matrix
---and stores the result in dst.
---
---@param m cc.Mat4 # The matrix.
---@param dst cc.Quaternion # A quaternion to store the conjugate in.
function Quaternion.createFromRotationMatrix(m, dst) end

---Gets the conjugate of this quaternion.
---@return cc.Quaternion
function Quaternion:getConjugated() end

---Gets the inverse of this quaternion.
---
---Note that the inverse of a quaternion is equal to its conjugate
---when the quaternion is unit-length. For this reason, it is more
---efficient to use the conjugate method directly when you know your
---quaternion is already unit-length.
---@return cc.Quaternion
function Quaternion:getInversed() end

---Get the normalized quaternion.
---
---If the quaternion already has unit length or if the length
---of the quaternion is zero, this method simply copies
---this vector.
---@return cc.Quaternion
function Quaternion:getNormalized() end

---Returns the identity quaternion.
---
---@return cc.Quaternion # The identity quaternion.
function Quaternion.identity() end

---Sets this quaternion to the inverse of itself.
---
---Note that the inverse of a quaternion is equal to its conjugate
---when the quaternion is unit-length. For this reason, it is more
---efficient to use the conjugate method directly when you know your
---quaternion is already unit-length.
---
---@return boolean # true if the inverse can be computed, false otherwise.
function Quaternion:inverse() end

---Determines if this quaternion is equal to the identity quaternion.
---
---@return boolean # true if it is the identity quaternion, false otherwise.
function Quaternion:isIdentity() end

---Determines if this quaternion is all zeros.
---
---@return boolean # true if this quaternion is all zeros, false otherwise.
function Quaternion:isZero() end

---Interpolates between two quaternions using linear interpolation.
---
---The interpolation curve for linear interpolation between
---quaternions gives a straight line in quaternion space.
---
---@param q1 cc.Quaternion # The first quaternion.
---@param q2 cc.Quaternion # The second quaternion.
---@param t number # The interpolation coefficient.
---@param dst cc.Quaternion # A quaternion to store the result in.
function Quaternion.lerp(q1, q2, t, dst) end

---Multiplies this quaternion by the specified one and stores the result in this quaternion.
---
---@param q cc.Quaternion # The quaternion to multiply.
---
---Multiplies the specified quaternions and stores the result in dst.
---
---\param q1 The first quaternion.
---\param q2 The second quaternion.
---\param dst A quaternion to store the result in.
---@overload fun(q1: cc.Quaternion, q2: cc.Quaternion, dst: cc.Quaternion)
function Quaternion:multiply(q) end

---Constructs a quaternion initialized to (0, 0, 0, 1).
---@return cc.Quaternion
---
---Constructs a quaternion initialized to (0, 0, 0, 1).
---
---\param xx The x component of the quaternion.
---\param yy The y component of the quaternion.
---\param zz The z component of the quaternion.
---\param ww The w component of the quaternion.
---@overload fun(xx: number, yy: number, zz: number, ww: number): cc.Quaternion
---
---Constructs a new quaternion from the values in the specified array.
---
---\param array The values for the new quaternion.
---@overload fun(array: olua.float): cc.Quaternion
---
---Constructs a quaternion equal to the rotational part of the specified matrix.
---
---\param m The matrix.
---@overload fun(m: cc.Mat4): cc.Quaternion
---
---Constructs a quaternion equal to the rotation from the specified axis and angle.
---
---\param axis A vector describing the axis of rotation.
---\param angle The angle of rotation (in radians).
---@overload fun(axis: cc.Vec3, angle: number): cc.Quaternion
function Quaternion.new() end

---Normalizes this quaternion to have unit length.
---
---If the quaternion already has unit length or if the length
---of the quaternion is zero, this method does nothing.
function Quaternion:normalize() end

---Sets the elements of the quaternion to the specified values.
---
---@param xx number # The new x-value.
---@param yy number # The new y-value.
---@param zz number # The new z-value.
---@param ww number # The new w-value.
---
---Sets the elements of the quaternion from the values in the specified array.
---
---\param array An array containing the elements of the quaternion in the order x, y, z, w.
---@overload fun(self: cc.Quaternion, array: olua.float)
---
---Sets the quaternion equal to the rotational part of the specified matrix.
---
---\param m The matrix.
---@overload fun(self: cc.Quaternion, m: cc.Mat4)
---
---Sets the quaternion equal to the rotation from the specified axis and angle.
---
---\param axis The axis of rotation.
---\param angle The angle of rotation (in radians).
---@overload fun(self: cc.Quaternion, axis: cc.Vec3, angle: number)
---
---Sets the elements of this quaternion to a copy of the specified quaternion.
---
---\param q The quaternion to copy.
---@overload fun(self: cc.Quaternion, q: cc.Quaternion)
function Quaternion:set(xx, yy, zz, ww) end

---Sets this quaternion to be equal to the identity quaternion.
function Quaternion:setIdentity() end

---Interpolates between two quaternions using spherical linear interpolation.
---
---Spherical linear interpolation provides smooth transitions between different
---orientations and is often useful for animating models or cameras in 3D.
---
---Note: For accurate interpolation, the input quaternions must be at (or close to) unit length.
---This method does not automatically normalize the input quaternions, so it is up to the
---caller to ensure they call normalize beforehand, if necessary.
---
---@param q1 cc.Quaternion # The first quaternion.
---@param q2 cc.Quaternion # The second quaternion.
---@param t number # The interpolation coefficient.
---@param dst cc.Quaternion # A quaternion to store the result in.
function Quaternion.slerp(q1, q2, t, dst) end

---Interpolates over a series of quaternions using spherical spline interpolation.
---
---Spherical spline interpolation provides smooth transitions between different
---orientations and is often useful for animating models or cameras in 3D.
---
---Note: For accurate interpolation, the input quaternions must be unit.
---This method does not automatically normalize the input quaternions,
---so it is up to the caller to ensure they call normalize beforehand, if necessary.
---
---@param q1 cc.Quaternion # The first quaternion.
---@param q2 cc.Quaternion # The second quaternion.
---@param s1 cc.Quaternion # The first control point.
---@param s2 cc.Quaternion # The second control point.
---@param t number # The interpolation coefficient.
---@param dst cc.Quaternion # A quaternion to store the result in.
function Quaternion.squad(q1, q2, s1, s2, t, dst) end

---Converts this Quaternion4f to axis-angle notation. The axis is normalized.
---
---@param e cc.Vec3 # The Vec3f which stores the axis.
---
---@return number # The angle (in radians).
function Quaternion:toAxisAngle(e) end

---Returns the quaternion with all zeros.
---
---@return cc.Quaternion # The quaternion.
function Quaternion.zero() end

return Quaternion