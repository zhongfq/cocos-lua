---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.types.Vec2Array

---
---@class cc.types.Vec2Array 
---@field buffer any 
---@field length integer 
---@field value cc.Vec2 
local Vec2Array = {}

---@return any
function Vec2Array:__gc() end

---@param idx integer
---@return cc.Vec2
function Vec2Array:__index(idx) end

---@param idx integer
---@param v cc.Vec2
function Vec2Array:__newindex(idx, v) end

---@param len integer
---@return cc.types.Vec2Array
---@overload fun(): cc.types.Vec2Array
---@overload fun(v: cc.Vec2, len: integer): cc.types.Vec2Array
---@overload fun(v: cc.Vec2): cc.types.Vec2Array
function Vec2Array.new(len) end

---@param from integer
---@param to integer
---@return cc.types.Vec2Array
---@overload fun(self: cc.types.Vec2Array, from: integer): cc.types.Vec2Array
function Vec2Array:slice(from, to) end

---@param from integer
---@param to integer
---@return cc.types.Vec2Array
---@overload fun(self: cc.types.Vec2Array, from: integer): cc.types.Vec2Array
function Vec2Array:sub(from, to) end

---@return cc.types.Vec2Array
function Vec2Array:take() end

---@param len integer
---@return any
function Vec2Array:tostring(len) end

return Vec2Array