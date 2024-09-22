---AUTO GENERATED, DO NOT MODIFY!
---@meta olua.float

---
---@class olua.float 
---@field buffer any 
---@field length integer 
---@field value number 
local float = {}

---@return any
function float:__gc() end

---@param idx integer
---@return number
function float:__index(idx) end

---@param idx integer
---@param v number
function float:__newindex(idx, v) end

---@param len integer
---@return olua.float
---@overload fun(): olua.float
---@overload fun(v: olua.float, len: integer): olua.float
---@overload fun(v: olua.float): olua.float
function float.new(len) end

---@param from integer
---@param to integer
---@return olua.float
---@overload fun(self: olua.float, from: integer): olua.float
function float:slice(from, to) end

---@param from integer
---@param to integer
---@return olua.float
---@overload fun(self: olua.float, from: integer): olua.float
function float:sub(from, to) end

---@return olua.float
function float:take() end

---@param len integer
---@return any
function float:tostring(len) end

return float