---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.Vec2Array

---
---@class b2.Vec2Array 
---@field buffer any 
---@field length integer 
---@field value b2.Vec2 
local Vec2Array = {}

---@return any
function Vec2Array:__gc() end

---@param idx integer
---@return b2.Vec2
function Vec2Array:__index(idx) end

---@param idx integer
---@param v b2.Vec2
function Vec2Array:__newindex(idx, v) end

---@param len integer
---@return b2.Vec2Array
---@overload fun(): b2.Vec2Array
---@overload fun(v: b2.Vec2, len: integer): b2.Vec2Array
---@overload fun(v: b2.Vec2): b2.Vec2Array
function Vec2Array.new(len) end

---@param from integer
---@param to integer
---@return b2.Vec2Array
---@overload fun(self: b2.Vec2Array, from: integer): b2.Vec2Array
function Vec2Array:slice(from, to) end

---@param from integer
---@param to integer
---@return b2.Vec2Array
---@overload fun(self: b2.Vec2Array, from: integer): b2.Vec2Array
function Vec2Array:sub(from, to) end

---@return b2.Vec2Array
function Vec2Array:take() end

---@param len integer
---@return any
function Vec2Array:tostring(len) end

return Vec2Array