---AUTO GENERATED, DO NOT MODIFY!
---@meta olua.int16

---
---@class olua.int16 
---@field buffer any 
---@field length integer 
---@field value integer 
local int16 = {}

---@return any
function int16:__gc() end

---@param idx integer
---@return integer
function int16:__index(idx) end

---@param idx integer
---@param v integer
function int16:__newindex(idx, v) end

---@param len integer
---@return olua.int16
---@overload fun(): olua.int16
---@overload fun(v: olua.int16, len: integer): olua.int16
---@overload fun(v: olua.int16): olua.int16
function int16.new(len) end

---@param from integer
---@param to integer
---@return olua.int16
---@overload fun(self: olua.int16, from: integer): olua.int16
function int16:slice(from, to) end

---@param from integer
---@param to integer
---@return olua.int16
---@overload fun(self: olua.int16, from: integer): olua.int16
function int16:sub(from, to) end

---@return olua.int16
function int16:take() end

---@param len integer
---@return any
function int16:tostring(len) end

return int16