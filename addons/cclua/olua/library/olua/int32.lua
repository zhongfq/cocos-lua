---AUTO GENERATED, DO NOT MODIFY!
---@meta olua.int32

---
---@class olua.int32 
---@field buffer any 
---@field length integer 
---@field value integer 
local int32 = {}

---@return any
function int32:__gc() end

---@param idx integer
---@return integer
function int32:__index(idx) end

---@param idx integer
---@param v integer
function int32:__newindex(idx, v) end

---@param len integer
---@return olua.int32
---@overload fun(): olua.int32
---@overload fun(v: olua.int32, len: integer): olua.int32
---@overload fun(v: olua.int32): olua.int32
function int32.new(len) end

---@param from integer
---@param to integer
---@return olua.int32
---@overload fun(self: olua.int32, from: integer): olua.int32
function int32:slice(from, to) end

---@param from integer
---@param to integer
---@return olua.int32
---@overload fun(self: olua.int32, from: integer): olua.int32
function int32:sub(from, to) end

---@return olua.int32
function int32:take() end

---@param len integer
---@return any
function int32:tostring(len) end

return int32