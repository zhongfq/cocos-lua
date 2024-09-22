---AUTO GENERATED, DO NOT MODIFY!
---@meta olua.ssize_t

---
---@class olua.ssize_t 
---@field buffer any 
---@field length integer 
---@field value integer 
local ssize_t = {}

---@return any
function ssize_t:__gc() end

---@param idx integer
---@return integer
function ssize_t:__index(idx) end

---@param idx integer
---@param v integer
function ssize_t:__newindex(idx, v) end

---@param len integer
---@return olua.ssize_t
---@overload fun(): olua.ssize_t
---@overload fun(v: olua.ssize_t, len: integer): olua.ssize_t
---@overload fun(v: olua.ssize_t): olua.ssize_t
function ssize_t.new(len) end

---@param from integer
---@param to integer
---@return olua.ssize_t
---@overload fun(self: olua.ssize_t, from: integer): olua.ssize_t
function ssize_t:slice(from, to) end

---@param from integer
---@param to integer
---@return olua.ssize_t
---@overload fun(self: olua.ssize_t, from: integer): olua.ssize_t
function ssize_t:sub(from, to) end

---@return olua.ssize_t
function ssize_t:take() end

---@param len integer
---@return any
function ssize_t:tostring(len) end

return ssize_t