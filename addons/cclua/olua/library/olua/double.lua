---AUTO GENERATED, DO NOT MODIFY!
---@meta olua.double

---
---@class olua.double 
---@field buffer any 
---@field length integer 
---@field value number 
local double = {}

---@return any
function double:__gc() end

---@param idx integer
---@return number
function double:__index(idx) end

---@param idx integer
---@param v number
function double:__newindex(idx, v) end

---@param len integer
---@return olua.double
---@overload fun(): olua.double
---@overload fun(v: olua.double, len: integer): olua.double
---@overload fun(v: olua.double): olua.double
function double.new(len) end

---@param from integer
---@param to integer
---@return olua.double
---@overload fun(self: olua.double, from: integer): olua.double
function double:slice(from, to) end

---@param from integer
---@param to integer
---@return olua.double
---@overload fun(self: olua.double, from: integer): olua.double
function double:sub(from, to) end

---@return olua.double
function double:take() end

---@param len integer
---@return any
function double:tostring(len) end

return double