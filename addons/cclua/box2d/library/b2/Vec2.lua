---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.Vec2

---A 2D column vector.
---@class b2.Vec2 
---@field valid boolean Does this vector contain finite coordinates?
---@field x number
---@field y number
---@operator add(b2.Vec2):b2.Vec2
---@operator sub(b2.Vec2):b2.Vec2
---@operator unm:b2.Vec2
local Vec2 = {}

---Add two vectors component-wise.
---@param a b2.Vec2
---@param b b2.Vec2
---@return b2.Vec2
function Vec2.__add(a, b) end

---@param a b2.Vec2
---@param b b2.Vec2
---@return boolean
function Vec2.__eq(a, b) end

---@return any
function Vec2:__gc() end

---Subtract two vectors component-wise.
---@param a b2.Vec2
---@param b b2.Vec2
---@return b2.Vec2
function Vec2.__sub(a, b) end

---Negate this vector.
---@return b2.Vec2
function Vec2:__unm() end

---Does this vector contain finite coordinates?
---@return boolean
function Vec2:isValid() end

---Get the length of this vector (the norm).
---@return number
function Vec2:length() end

---Get the length squared. For performance, use this instead of
---b2Vec2::Length (if possible).
---@return number
function Vec2:lengthSquared() end

---Default constructor does nothing (for performance).
---@return b2.Vec2
---
---Construct using coordinates.
---@overload fun(xIn: number, yIn: number): b2.Vec2
function Vec2.new() end

---Convert this vector into a unit vector. Returns the length.
---@return number
function Vec2:normalize() end

---Set this vector to some specified coordinates.
---@param x_ number
---@param y_ number
function Vec2:set(x_, y_) end

---Set this vector to all zeros.
function Vec2:setZero() end

---Get the skew vector such that dot(skew_vec, other) == cross(vec, other)
---@return b2.Vec2
function Vec2:skew() end

return Vec2