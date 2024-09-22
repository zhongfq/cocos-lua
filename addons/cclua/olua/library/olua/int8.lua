---AUTO GENERATED, DO NOT MODIFY!
---@meta olua.int8

---
---@class olua.int8 
---@field buffer any 
---@field length integer 
---@field value integer 
local int8 = {}

---@return any
function int8:__gc() end

---@param idx integer
---@return integer
function int8:__index(idx) end

---@param idx integer
---@param v integer
function int8:__newindex(idx, v) end

---@param len integer
---@return olua.int8
---@overload fun(): olua.int8
---@overload fun(v: olua.int8, len: integer): olua.int8
---@overload fun(v: olua.int8): olua.int8
function int8.new(len) end

---@param from integer
---@param to integer
---@return olua.int8
---@overload fun(self: olua.int8, from: integer): olua.int8
function int8:slice(from, to) end

---@param from integer
---@param to integer
---@return olua.int8
---@overload fun(self: olua.int8, from: integer): olua.int8
function int8:sub(from, to) end

---@return olua.int8
function int8:take() end

---@param len integer
---@return any
function int8:tostring(len) end

return int8