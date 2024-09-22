---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Vec2Array

---
---@class cc.Vec2Array 
---@field length integer 
---@field rawdata any 
---@field sizeof integer 
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

---@return any
function Vec2Array:__olua_move() end

---@param data string
---@param len integer
function Vec2Array:assign(data, len) end

---@param len integer
---@return cc.Vec2Array
---@overload fun(): cc.Vec2Array
function Vec2Array.new(len) end

---@param from integer
---@param to integer
---@return cc.Vec2Array
---@overload fun(self: cc.Vec2Array, from: integer): cc.Vec2Array
function Vec2Array:slice(from, to) end

---@param from integer
---@param to integer
---@return cc.Vec2Array
---@overload fun(self: cc.Vec2Array, from: integer): cc.Vec2Array
function Vec2Array:sub(from, to) end

---@return cc.Vec2Array
function Vec2Array:take() end

---@param len integer
---@return any
function Vec2Array:tostring(len) end

return Vec2Array