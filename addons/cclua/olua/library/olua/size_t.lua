---AUTO GENERATED, DO NOT MODIFY!
---@meta olua.size_t

---
---@class olua.size_t 
---@field buffer any 
---@field length integer 
---@field value integer 
local size_t = {}

---@return any
function size_t:__gc() end

---@param idx integer
---@return integer
function size_t:__index(idx) end

---@param idx integer
---@param v integer
function size_t:__newindex(idx, v) end

---@param len integer
---@return olua.size_t
---@overload fun(): olua.size_t
---@overload fun(v: olua.size_t, len: integer): olua.size_t
---@overload fun(v: olua.size_t): olua.size_t
function size_t.new(len) end

---@param from integer
---@param to integer
---@return olua.size_t
---@overload fun(self: olua.size_t, from: integer): olua.size_t
function size_t:slice(from, to) end

---@param from integer
---@param to integer
---@return olua.size_t
---@overload fun(self: olua.size_t, from: integer): olua.size_t
function size_t:sub(from, to) end

---@return olua.size_t
function size_t:take() end

---@param len integer
---@return any
function size_t:tostring(len) end

return size_t