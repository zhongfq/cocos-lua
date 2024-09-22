---AUTO GENERATED, DO NOT MODIFY!
---@meta olua.int

---
---@class olua.int 
---@field buffer any 
---@field length integer 
---@field value integer 
local int = {}

---@return any
function int:__gc() end

---@param idx integer
---@return integer
function int:__index(idx) end

---@param idx integer
---@param v integer
function int:__newindex(idx, v) end

---@param len integer
---@return olua.int
---@overload fun(): olua.int
---@overload fun(v: olua.int, len: integer): olua.int
---@overload fun(v: olua.int): olua.int
function int.new(len) end

---@param from integer
---@param to integer
---@return olua.int
---@overload fun(self: olua.int, from: integer): olua.int
function int:slice(from, to) end

---@param from integer
---@param to integer
---@return olua.int
---@overload fun(self: olua.int, from: integer): olua.int
function int:sub(from, to) end

---@return olua.int
function int:take() end

---@param len integer
---@return any
function int:tostring(len) end

return int