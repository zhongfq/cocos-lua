---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Mat4

---\addtogroup base
---\{
---@class cc.Mat4 
---@field identity boolean Determines if this matrix is equal to the identity matrix. <br><br>\return true if the matrix is an identity matrix, false otherwise.
---@field inversed cc.Mat4 Get the inversed matrix.
---@field negated cc.Mat4 Get the Negated matrix.
---@field transposed cc.Mat4 Get the Transposed matrix.
---@field IDENTITY cc.Mat4
---@field ZERO cc.Mat4
---@operator add(cc.Mat4):cc.Mat4
---@operator mul(cc.Mat4):cc.Mat4
---@operator sub(cc.Mat4):cc.Mat4
---@operator unm:cc.Mat4
local Mat4 = {}

---Calculates the sum of this matrix with the given matrix.
---
---Note: this does not modify this matrix.
---
---@param mat cc.Mat4 # The matrix to add.
---@return cc.Mat4 # The matrix sum.
---@overload fun(mat1: cc.Mat4, mat2: cc.Mat4): cc.Mat4
function Mat4:__add(mat) end

---@return any
function Mat4:__gc() end

---Calculates the matrix product of this matrix with the given matrix.
---
---Note: this does not modify this matrix.
---
---@param mat cc.Mat4 # The matrix to multiply by.
---@return cc.Mat4 # The matrix product.
---
---Transforms the given vector by the given matrix.
---
---Note: this treats the given vector as a vector and not as a point.
---
---\param m The matrix to transform by.
---\param v The vector to transform.
---\return The resulting transformed vector.
---@overload fun(m: cc.Mat4, v: cc.Vec3): cc.Vec3
---
---Transforms the given vector by the given matrix.
---
---Note: this treats the given vector as a vector and not as a point.
---
---\param m The matrix to transform by.
---\param v The vector to transform.
---\return The resulting transformed vector.
---@overload fun(m: cc.Mat4, v: cc.Vec4): cc.Vec4
---@overload fun(mat1: cc.Mat4, mat2: cc.Mat4): cc.Mat4
function Mat4:__mul(mat) end

---Calculates the difference of this matrix with the given matrix.
---
---Note: this does not modify this matrix.
---
---@param mat cc.Mat4 # The matrix to subtract.
---@return cc.Mat4 # The matrix difference.
---@overload fun(mat1: cc.Mat4, mat2: cc.Mat4): cc.Mat4
function Mat4:__sub(mat) end

---Calculates the negation of this matrix.
---
---Note: this does not modify this matrix.
---
---@return cc.Mat4 # The negation of this matrix.
function Mat4:__unm() end

---Adds a scalar value to each component of this matrix.
---
---@param scalar number # The scalar to add.
---
---Adds a scalar value to each component of this matrix and stores the result in dst.
---
---\param scalar The scalar value to add.
---\param dst A matrix to store the result in.
---@overload fun(self: cc.Mat4, scalar: number, dst: cc.Mat4)
---
---Adds the specified matrix to this matrix.
---
---\param mat The matrix to add.
---@overload fun(self: cc.Mat4, mat: cc.Mat4)
---
---Adds the specified matrices and stores the result in dst.
---
---\param m1 The first matrix.
---\param m2 The second matrix.
---\param dst The destination matrix to add to.
---@overload fun(m1: cc.Mat4, m2: cc.Mat4, dst: cc.Mat4)
function Mat4:add(scalar) end

---Creates a spherical billboard that rotates around a specified object position.
---
---This method computes the facing direction of the billboard from the object position
---and camera position. When the object and camera positions are too close, the matrix
---will not be accurate. To avoid this problem, this method defaults to the identity
---rotation if the positions are too close. (See the other overload of createBillboard
---for an alternative approach).
---
---@param objectPosition cc.Vec3 # The position of the object the billboard will rotate around.
---@param cameraPosition cc.Vec3 # The position of the camera.
---@param cameraUpVector cc.Vec3 # The up vector of the camera.
---@param dst cc.Mat4 # A matrix to store the result in.
---
---Creates a spherical billboard that rotates around a specified object position with
---provision for a safe default orientation.
---
---This method computes the facing direction of the billboard from the object position
---and camera position. When the object and camera positions are too close, the matrix
---will not be accurate. To avoid this problem, this method uses the specified camera
---forward vector if the positions are too close. (See the other overload of createBillboard
---for an alternative approach).
---
---\param objectPosition The position of the object the billboard will rotate around.
---\param cameraPosition The position of the camera.
---\param cameraUpVector The up vector of the camera.
---\param cameraForwardVector The forward vector of the camera, used if the positions are too close.
---\param dst A matrix to store the result in.
---@overload fun(objectPosition: cc.Vec3, cameraPosition: cc.Vec3, cameraUpVector: cc.Vec3, cameraForwardVector: cc.Vec3, dst: cc.Mat4)
function Mat4.createBillboard(objectPosition, cameraPosition, cameraUpVector, dst) end

---Creates a view matrix based on the specified input parameters.
---
---@param eyePosition cc.Vec3 # The eye position.
---@param targetPosition cc.Vec3 # The target's center position.
---@param up cc.Vec3 # The up vector.
---@param dst cc.Mat4 # A matrix to store the result in.
---
---Creates a view matrix based on the specified input parameters.
---
---\param eyePositionX The eye x-coordinate position.
---\param eyePositionY The eye y-coordinate position.
---\param eyePositionZ The eye z-coordinate position.
---\param targetCenterX The target's center x-coordinate position.
---\param targetCenterY The target's center y-coordinate position.
---\param targetCenterZ The target's center z-coordinate position.
---\param upX The up vector x-coordinate value.
---\param upY The up vector y-coordinate value.
---\param upZ The up vector z-coordinate value.
---\param dst A matrix to store the result in.
---@overload fun(eyePositionX: number, eyePositionY: number, eyePositionZ: number, targetCenterX: number, targetCenterY: number, targetCenterZ: number, upX: number, upY: number, upZ: number, dst: cc.Mat4)
function Mat4.createLookAt(eyePosition, targetPosition, up, dst) end

---Creates an orthographic projection matrix.
---
---@param width number # The width of the view.
---@param height number # The height of the view.
---@param zNearPlane number # The minimum z-value of the view volume.
---@param zFarPlane number # The maximum z-value of the view volume.
---@param dst cc.Mat4 # A matrix to store the result in.
function Mat4.createOrthographic(width, height, zNearPlane, zFarPlane, dst) end

---Creates an orthographic projection matrix.
---
---Projection space refers to the space after applying
---projection transformation from view space. After the
---projection transformation, visible content has
---x and y coordinates ranging from -1 to 1, and z coordinates
---ranging from 0 to 1.
---
---Unlike perspective projection, in orthographic projection
---there is no perspective foreshortening.
---
---The viewable area of this orthographic projection extends
---from left to right on the x-axis, bottom to top on the y-axis,
---and zNearPlane to zFarPlane on the z-axis. These values are
---relative to the position and x, y, and z-axes of the view.
---To obtain the viewable area (in world space) of a scene,
---create a BoundingFrustum and pass the combined view and
---projection matrix to the constructor.
---
---@param left number # The minimum x-value of the view volume.
---@param right number # The maximum x-value of the view volume.
---@param bottom number # The minimum y-value of the view volume.
---@param top number # The maximum y-value of the view volume.
---@param zNearPlane number # The minimum z-value of the view volume.
---@param zFarPlane number # The maximum z-value of the view volume.
---@param dst cc.Mat4 # A matrix to store the result in.
function Mat4.createOrthographicOffCenter(left, right, bottom, top, zNearPlane, zFarPlane, dst) end

---Builds a perspective projection matrix based on a field of view and returns by value.
---
---Projection space refers to the space after applying projection transformation from view space.
---After the projection transformation, visible content has x- and y-coordinates ranging from -1 to 1,
---and a z-coordinate ranging from 0 to 1. To obtain the viewable area (in world space) of a scene,
---create a BoundingFrustum and pass the combined view and projection matrix to the constructor.
---
---@param fieldOfView number # The field of view in the y direction (in degrees).
---@param aspectRatio number # The aspect ratio, defined as view space width divided by height.
---@param zNearPlane number # The distance to the near view plane.
---@param zFarPlane number # The distance to the far view plane.
---@param dst cc.Mat4 # A matrix to store the result in.
function Mat4.createPerspective(fieldOfView, aspectRatio, zNearPlane, zFarPlane, dst) end

---Creates a rotation matrix from the specified quaternion.
---
---@param quat cc.Quaternion # A quaternion describing a 3D orientation.
---@param dst cc.Mat4 # A matrix to store the result in.
---
---Creates a rotation matrix from the specified axis and angle.
---
---\param axis A vector describing the axis to rotate about.
---\param angle The angle (in radians).
---\param dst A matrix to store the result in.
---@overload fun(axis: cc.Vec3, angle: number, dst: cc.Mat4)
function Mat4.createRotation(quat, dst) end

---Creates a matrix describing a rotation around the x-axis.
---
---@param angle number # The angle of rotation (in radians).
---@param dst cc.Mat4 # A matrix to store the result in.
function Mat4.createRotationX(angle, dst) end

---Creates a matrix describing a rotation around the y-axis.
---
---@param angle number # The angle of rotation (in radians).
---@param dst cc.Mat4 # A matrix to store the result in.
function Mat4.createRotationY(angle, dst) end

---Creates a matrix describing a rotation around the z-axis.
---
---@param angle number # The angle of rotation (in radians).
---@param dst cc.Mat4 # A matrix to store the result in.
function Mat4.createRotationZ(angle, dst) end

---Creates a scale matrix.
---
---@param scale cc.Vec3 # The amount to scale.
---@param dst cc.Mat4 # A matrix to store the result in.
---
---Creates a scale matrix.
---
---\param xScale The amount to scale along the x-axis.
---\param yScale The amount to scale along the y-axis.
---\param zScale The amount to scale along the z-axis.
---\param dst A matrix to store the result in.
---@overload fun(xScale: number, yScale: number, zScale: number, dst: cc.Mat4)
function Mat4.createScale(scale, dst) end

---Creates a translation matrix.
---
---@param translation cc.Vec3 # The translation.
---@param dst cc.Mat4 # A matrix to store the result in.
---
---Creates a translation matrix.
---
---\param xTranslation The translation on the x-axis.
---\param yTranslation The translation on the y-axis.
---\param zTranslation The translation on the z-axis.
---\param dst A matrix to store the result in.
---@overload fun(xTranslation: number, yTranslation: number, zTranslation: number, dst: cc.Mat4)
function Mat4.createTranslation(translation, dst) end

---Decomposes the scale, rotation and translation components of this matrix.
---
---@param scale cc.Vec3 # The scale.
---@param rotation cc.Quaternion # The rotation.
---@param translation cc.Vec3 # The translation.
---@return boolean
function Mat4:decompose(scale, rotation, translation) end

---Computes the determinant of this matrix.
---
---@return number # The determinant.
function Mat4:determinant() end

---Gets the backward vector of this matrix.
---
---@param dst cc.Vec3 # The destination vector.
function Mat4:getBackVector(dst) end

---Gets the down vector of this matrix.
---
---@param dst cc.Vec3 # The destination vector.
function Mat4:getDownVector(dst) end

---Gets the forward vector of this matrix.
---
---@param dst cc.Vec3 # The destination vector.
function Mat4:getForwardVector(dst) end

---Get the inversed matrix.
---@return cc.Mat4
function Mat4:getInversed() end

---Gets the left vector of this matrix.
---
---@param dst cc.Vec3 # The destination vector.
function Mat4:getLeftVector(dst) end

---Get the Negated matrix.
---@return cc.Mat4
function Mat4:getNegated() end

---Gets the right vector of this matrix.
---
---@param dst cc.Vec3 # The destination vector.
function Mat4:getRightVector(dst) end

---Gets the rotational component of this matrix in the specified quaternion.
---
---@param rotation cc.Quaternion # A quaternion to receive the rotation.
---
---@return boolean # true if the rotation is successfully extracted, false otherwise.
function Mat4:getRotation(rotation) end

---Gets the scalar component of this matrix in the specified vector.
---
---If the scalar component of this matrix has negative parts,
---it is not possible to always extract the exact scalar component;
---instead, a scale vector that is mathematically equivalent to the
---original scale vector is extracted and returned.
---
---@param scale cc.Vec3 # A vector to receive the scale.
function Mat4:getScale(scale) end

---Gets the translational component of this matrix in the specified vector.
---
---@param translation cc.Vec3 # A vector to receive the translation.
function Mat4:getTranslation(translation) end

---Get the Transposed matrix.
---@return cc.Mat4
function Mat4:getTransposed() end

---Gets the up vector of this matrix.
---
---@param dst cc.Vec3 # The destination vector.
function Mat4:getUpVector(dst) end

---Inverts this matrix.
---
---@return boolean # true if the matrix can be inverted, false otherwise.
function Mat4:inverse() end

---Determines if this matrix is equal to the identity matrix.
---
---@return boolean # true if the matrix is an identity matrix, false otherwise.
function Mat4:isIdentity() end

---Multiplies the components of this matrix by the specified scalar.
---
---@param scalar number # The scalar value.
---
---Multiplies the components of this matrix by a scalar and stores the result in dst.
---
---\param scalar The scalar value.
---\param dst A matrix to store the result in.
---@overload fun(self: cc.Mat4, scalar: number, dst: cc.Mat4)
---
---Multiplies the components of the specified matrix by a scalar and stores the result in dst.
---
---\param mat The matrix.
---\param scalar The scalar value.
---\param dst A matrix to store the result in.
---@overload fun(mat: cc.Mat4, scalar: number, dst: cc.Mat4)
---
---Multiplies this matrix by the specified one.
---
---\param mat The matrix to multiply.
---@overload fun(self: cc.Mat4, mat: cc.Mat4)
---
---Multiplies m1 by m2 and stores the result in dst.
---
---\param m1 The first matrix to multiply.
---\param m2 The second matrix to multiply.
---\param dst A matrix to store the result in.
---@overload fun(m1: cc.Mat4, m2: cc.Mat4, dst: cc.Mat4)
function Mat4:multiply(scalar) end

---Negates this matrix.
function Mat4:negate() end

---Default constructor.
---Constructs a matrix initialized to the identity matrix:
---
---1  0  0  0
---0  1  0  0
---0  0  1  0
---0  0  0  1
---@return cc.Mat4
---
---Constructs a matrix initialized to the specified value.
---
---\param m11 The first element of the first row.
---\param m12 The second element of the first row.
---\param m13 The third element of the first row.
---\param m14 The fourth element of the first row.
---\param m21 The first element of the second row.
---\param m22 The second element of the second row.
---\param m23 The third element of the second row.
---\param m24 The fourth element of the second row.
---\param m31 The first element of the third row.
---\param m32 The second element of the third row.
---\param m33 The third element of the third row.
---\param m34 The fourth element of the third row.
---\param m41 The first element of the fourth row.
---\param m42 The second element of the fourth row.
---\param m43 The third element of the fourth row.
---\param m44 The fourth element of the fourth row.
---@overload fun(m11: number, m12: number, m13: number, m14: number, m21: number, m22: number, m23: number, m24: number, m31: number, m32: number, m33: number, m34: number, m41: number, m42: number, m43: number, m44: number): cc.Mat4
---
---Creates a matrix initialized to the specified column-major array.
---
---The passed-in array is in column-major order, so the memory layout of the array is as follows:
---
---0   4   8   12
---1   5   9   13
---2   6   10  14
---3   7   11  15
---
---\param mat An array containing 16 elements in column-major order.
---@overload fun(mat: olua.float): cc.Mat4
function Mat4.new() end

---Post-multiplies this matrix by the matrix corresponding to the
---specified quaternion rotation.
---
---@param q cc.Quaternion # The quaternion to rotate by.
---
---Post-multiplies this matrix by the matrix corresponding to the
---specified quaternion rotation and stores the result in dst.
---
---\param q The quaternion to rotate by.
---\param dst A matrix to store the result in.
---@overload fun(self: cc.Mat4, q: cc.Quaternion, dst: cc.Mat4)
---
---Post-multiplies this matrix by the matrix corresponding to the
---specified rotation about the specified axis.
---
---\param axis The axis to rotate about.
---\param angle The angle (in radians).
---@overload fun(self: cc.Mat4, axis: cc.Vec3, angle: number)
---
---Post-multiplies this matrix by the matrix corresponding to the specified
---rotation about the specified axis and stores the result in dst.
---
---\param axis The axis to rotate about.
---\param angle The angle (in radians).
---\param dst A matrix to store the result in.
---@overload fun(self: cc.Mat4, axis: cc.Vec3, angle: number, dst: cc.Mat4)
function Mat4:rotate(q) end

---Post-multiplies this matrix by the matrix corresponding to the
---specified rotation around the x-axis.
---
---@param angle number # The angle (in radians).
---
---Post-multiplies this matrix by the matrix corresponding to the
---specified rotation around the x-axis and stores the result in dst.
---
---\param angle The angle (in radians).
---\param dst A matrix to store the result in.
---@overload fun(self: cc.Mat4, angle: number, dst: cc.Mat4)
function Mat4:rotateX(angle) end

---Post-multiplies this matrix by the matrix corresponding to the
---specified rotation around the y-axis.
---
---@param angle number # The angle (in radians).
---
---Post-multiplies this matrix by the matrix corresponding to the
---specified rotation around the y-axis and stores the result in dst.
---
---\param angle The angle (in radians).
---\param dst A matrix to store the result in.
---@overload fun(self: cc.Mat4, angle: number, dst: cc.Mat4)
function Mat4:rotateY(angle) end

---Post-multiplies this matrix by the matrix corresponding to the
---specified rotation around the z-axis.
---
---@param angle number # The angle (in radians).
---
---Post-multiplies this matrix by the matrix corresponding to the
---specified rotation around the z-axis and stores the result in dst.
---
---\param angle The angle (in radians).
---\param dst A matrix to store the result in.
---@overload fun(self: cc.Mat4, angle: number, dst: cc.Mat4)
function Mat4:rotateZ(angle) end

---Post-multiplies this matrix by the matrix corresponding to the
---specified scale transformation.
---
---@param value number # The amount to scale along all axes.
---
---Post-multiplies this matrix by the matrix corresponding to the
---specified scale transformation and stores the result in dst.
---
---\param value The amount to scale along all axes.
---\param dst A matrix to store the result in.
---@overload fun(self: cc.Mat4, value: number, dst: cc.Mat4)
---
---Post-multiplies this matrix by the matrix corresponding to the
---specified scale transformation.
---
---\param xScale The amount to scale along the x-axis.
---\param yScale The amount to scale along the y-axis.
---\param zScale The amount to scale along the z-axis.
---@overload fun(self: cc.Mat4, xScale: number, yScale: number, zScale: number)
---
---Post-multiplies this matrix by the matrix corresponding to the
---specified scale transformation and stores the result in dst.
---
---\param xScale The amount to scale along the x-axis.
---\param yScale The amount to scale along the y-axis.
---\param zScale The amount to scale along the z-axis.
---\param dst A matrix to store the result in.
---@overload fun(self: cc.Mat4, xScale: number, yScale: number, zScale: number, dst: cc.Mat4)
---
---Post-multiplies this matrix by the matrix corresponding to the
---specified scale transformation.
---
---\param s The scale values along the x, y and z axes.
---@overload fun(self: cc.Mat4, s: cc.Vec3)
---
---Post-multiplies this matrix by the matrix corresponding to the
---specified scale transformation and stores the result in dst.
---
---\param s The scale values along the x, y and z axes.
---\param dst A matrix to store the result in.
---@overload fun(self: cc.Mat4, s: cc.Vec3, dst: cc.Mat4)
function Mat4:scale(value) end

---Sets the values of this matrix.
---
---@param m11 number # The first element of the first row.
---@param m12 number # The second element of the first row.
---@param m13 number # The third element of the first row.
---@param m14 number # The fourth element of the first row.
---@param m21 number # The first element of the second row.
---@param m22 number # The second element of the second row.
---@param m23 number # The third element of the second row.
---@param m24 number # The fourth element of the second row.
---@param m31 number # The first element of the third row.
---@param m32 number # The second element of the third row.
---@param m33 number # The third element of the third row.
---@param m34 number # The fourth element of the third row.
---@param m41 number # The first element of the fourth row.
---@param m42 number # The second element of the fourth row.
---@param m43 number # The third element of the fourth row.
---@param m44 number # The fourth element of the fourth row.
---
---Sets the values of this matrix to those in the specified column-major array.
---
---\param mat An array containing 16 elements in column-major format.
---@overload fun(self: cc.Mat4, mat: olua.float)
---
---Sets the values of this matrix to those of the specified matrix.
---
---\param mat The source matrix.
---@overload fun(self: cc.Mat4, mat: cc.Mat4)
function Mat4:set(m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44) end

---Sets this matrix to the identity matrix.
function Mat4:setIdentity() end

---Sets all elements of the current matrix to zero.
function Mat4:setZero() end

---Subtracts the specified matrix from the current matrix.
---
---@param mat cc.Mat4 # The matrix to subtract.
---
---Subtracts the specified matrix from the current matrix.
---
---\param m1 The first matrix.
---\param m2 The second matrix.
---\param dst A matrix to store the result in.
---@overload fun(m1: cc.Mat4, m2: cc.Mat4, dst: cc.Mat4)
function Mat4:subtract(mat) end

---@param mat cc.Mat4
---@param p cc.Vec4
---@return cc.Vec4
---@overload fun(mat: cc.Mat4, p: cc.Vec3): cc.Vec3
---@overload fun(mat: cc.Mat4, p: cc.Vec2): cc.Vec2
---@overload fun(mat: cc.Mat4, x: number, y: number, z: number, w: number): number, number, number, number
---@overload fun(mat: cc.Mat4, x: number, y: number, z: number): number, number, number
---@overload fun(mat: cc.Mat4, x: number, y: number): number, number
function Mat4.transform(mat, p) end

---Transforms the specified point by this matrix.
---
---The result of the transformation is stored directly into point.
---
---@param point cc.Vec3 # The point to transform and also a vector to hold the result in.
---
---Transforms the specified point by this matrix, and stores
---the result in dst.
---
---\param point The point to transform.
---\param dst A vector to store the transformed point in.
---@overload fun(self: cc.Mat4, point: cc.Vec3, dst: cc.Vec3)
function Mat4:transformPoint(point) end

---Transforms the specified vector by this matrix by
---treating the fourth (w) coordinate as zero.
---
---The result of the transformation is stored directly into vector.
---
---@param vector cc.Vec3 # The vector to transform and also a vector to hold the result in.
---
---Transforms the specified vector by this matrix by
---treating the fourth (w) coordinate as zero, and stores the
---result in dst.
---
---\param vector The vector to transform.
---\param dst A vector to store the transformed vector in.
---@overload fun(self: cc.Mat4, vector: cc.Vec3, dst: cc.Vec3)
---
---Transforms the specified vector by this matrix.
---
---\param x The vector x-coordinate to transform by.
---\param y The vector y-coordinate to transform by.
---\param z The vector z-coordinate to transform by.
---\param w The vector w-coordinate to transform by.
---\param dst A vector to store the transformed point in.
---@overload fun(self: cc.Mat4, x: number, y: number, z: number, w: number, dst: cc.Vec3)
---
---Transforms the specified vector by this matrix.
---
---The result of the transformation is stored directly into vector.
---
---\param vector The vector to transform.
---@overload fun(self: cc.Mat4, vector: cc.Vec4)
---
---Transforms the specified vector by this matrix.
---
---\param vector The vector to transform.
---\param dst A vector to store the transformed point in.
---@overload fun(self: cc.Mat4, vector: cc.Vec4, dst: cc.Vec4)
function Mat4:transformVector(vector) end

---Post-multiplies this matrix by the matrix corresponding to the
---specified translation.
---
---@param x number # The amount to translate along the x-axis.
---@param y number # The amount to translate along the y-axis.
---@param z number # The amount to translate along the z-axis.
---
---Post-multiplies this matrix by the matrix corresponding to the
---specified translation and stores the result in dst.
---
---\param x The amount to translate along the x-axis.
---\param y The amount to translate along the y-axis.
---\param z The amount to translate along the z-axis.
---\param dst A matrix to store the result in.
---@overload fun(self: cc.Mat4, x: number, y: number, z: number, dst: cc.Mat4)
---
---Post-multiplies this matrix by the matrix corresponding to the
---specified translation.
---
---\param t The translation values along the x, y and z axes.
---@overload fun(self: cc.Mat4, t: cc.Vec3)
---
---Post-multiplies this matrix by the matrix corresponding to the
---specified translation and stores the result in dst.
---
---\param t The translation values along the x, y and z axes.
---\param dst A matrix to store the result in.
---@overload fun(self: cc.Mat4, t: cc.Vec3, dst: cc.Mat4)
function Mat4:translate(x, y, z) end

---Transposes this matrix.
function Mat4:transpose() end

return Mat4