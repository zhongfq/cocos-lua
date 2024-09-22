---AUTO GENERATED, DO NOT MODIFY!
---@meta olua.int64

---
---@class olua.int64 
---@field buffer any 
---@field length integer 
---@field value integer 
local int64 = {}

---@return any
function int64:__gc() end

---@param idx integer
---@return integer
function int64:__index(idx) end

---@param idx integer
---@param v integer
function int64:__newindex(idx, v) end

---@param len integer
---@return olua.int64
---@overload fun(): olua.int64
---@overload fun(v: olua.int64, len: integer): olua.int64
---@overload fun(v: olua.int64): olua.int64
function int64.new(len) end

---@param from integer
---@param to integer
---@return olua.int64
---@overload fun(self: olua.int64, from: integer): olua.int64
function int64:slice(from, to) end

---@param from integer
---@param to integer
---@return olua.int64
---@overload fun(self: olua.int64, from: integer): olua.int64
function int64:sub(from, to) end

---@return olua.int64
function int64:take() end

---@param len integer
---@return any
function int64:tostring(len) end

return int64