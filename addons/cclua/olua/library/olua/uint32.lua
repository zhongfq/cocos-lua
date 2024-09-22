---AUTO GENERATED, DO NOT MODIFY!
---@meta olua.uint32

---
---@class olua.uint32 
---@field buffer any 
---@field length integer 
---@field value integer 
local uint32 = {}

---@return any
function uint32:__gc() end

---@param idx integer
---@return integer
function uint32:__index(idx) end

---@param idx integer
---@param v integer
function uint32:__newindex(idx, v) end

---@param len integer
---@return olua.uint32
---@overload fun(): olua.uint32
---@overload fun(v: olua.uint32, len: integer): olua.uint32
---@overload fun(v: olua.uint32): olua.uint32
function uint32.new(len) end

---@param from integer
---@param to integer
---@return olua.uint32
---@overload fun(self: olua.uint32, from: integer): olua.uint32
function uint32:slice(from, to) end

---@param from integer
---@param to integer
---@return olua.uint32
---@overload fun(self: olua.uint32, from: integer): olua.uint32
function uint32:sub(from, to) end

---@return olua.uint32
function uint32:take() end

---@param len integer
---@return any
function uint32:tostring(len) end

return uint32