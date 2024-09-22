---AUTO GENERATED, DO NOT MODIFY!
---@meta olua.ldouble

---
---@class olua.ldouble 
---@field buffer any 
---@field length integer 
---@field value number 
local ldouble = {}

---@return any
function ldouble:__gc() end

---@param idx integer
---@return number
function ldouble:__index(idx) end

---@param idx integer
---@param v number
function ldouble:__newindex(idx, v) end

---@param len integer
---@return olua.ldouble
---@overload fun(): olua.ldouble
---@overload fun(v: olua.ldouble, len: integer): olua.ldouble
---@overload fun(v: olua.ldouble): olua.ldouble
function ldouble.new(len) end

---@param from integer
---@param to integer
---@return olua.ldouble
---@overload fun(self: olua.ldouble, from: integer): olua.ldouble
function ldouble:slice(from, to) end

---@param from integer
---@param to integer
---@return olua.ldouble
---@overload fun(self: olua.ldouble, from: integer): olua.ldouble
function ldouble:sub(from, to) end

---@return olua.ldouble
function ldouble:take() end

---@param len integer
---@return any
function ldouble:tostring(len) end

return ldouble