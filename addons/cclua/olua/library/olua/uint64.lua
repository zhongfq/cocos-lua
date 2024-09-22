---AUTO GENERATED, DO NOT MODIFY!
---@meta olua.uint64

---
---@class olua.uint64 
---@field buffer any 
---@field length integer 
---@field value integer 
local uint64 = {}

---@return any
function uint64:__gc() end

---@param idx integer
---@return integer
function uint64:__index(idx) end

---@param idx integer
---@param v integer
function uint64:__newindex(idx, v) end

---@param len integer
---@return olua.uint64
---@overload fun(): olua.uint64
---@overload fun(v: olua.uint64, len: integer): olua.uint64
---@overload fun(v: olua.uint64): olua.uint64
function uint64.new(len) end

---@param from integer
---@param to integer
---@return olua.uint64
---@overload fun(self: olua.uint64, from: integer): olua.uint64
function uint64:slice(from, to) end

---@param from integer
---@param to integer
---@return olua.uint64
---@overload fun(self: olua.uint64, from: integer): olua.uint64
function uint64:sub(from, to) end

---@return olua.uint64
function uint64:take() end

---@param len integer
---@return any
function uint64:tostring(len) end

return uint64