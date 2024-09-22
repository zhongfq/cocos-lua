---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.types.VectorInt

---
---@class cc.types.VectorInt 
---@field buffer any 
---@field length integer 
---@field value integer[] 
local VectorInt = {}

---@return any
function VectorInt:__gc() end

---@param idx integer
---@return integer[]
function VectorInt:__index(idx) end

---@param idx integer
---@param v integer[]
function VectorInt:__newindex(idx, v) end

---@param len integer
---@return cc.types.VectorInt
---@overload fun(): cc.types.VectorInt
---@overload fun(v: cc.types.VectorInt, len: integer): cc.types.VectorInt
---@overload fun(v: cc.types.VectorInt): cc.types.VectorInt
function VectorInt.new(len) end

---@param from integer
---@param to integer
---@return cc.types.VectorInt
---@overload fun(self: cc.types.VectorInt, from: integer): cc.types.VectorInt
function VectorInt:slice(from, to) end

---@param from integer
---@param to integer
---@return cc.types.VectorInt
---@overload fun(self: cc.types.VectorInt, from: integer): cc.types.VectorInt
function VectorInt:sub(from, to) end

---@return cc.types.VectorInt
function VectorInt:take() end

---@param len integer
---@return any
function VectorInt:tostring(len) end

return VectorInt