---AUTO GENERATED, DO NOT MODIFY!
---@meta olua.ulong

---
---@class olua.ulong 
---@field buffer any 
---@field length integer 
---@field value integer 
local ulong = {}

---@return any
function ulong:__gc() end

---@param idx integer
---@return integer
function ulong:__index(idx) end

---@param idx integer
---@param v integer
function ulong:__newindex(idx, v) end

---@param len integer
---@return olua.ulong
---@overload fun(): olua.ulong
---@overload fun(v: olua.ulong, len: integer): olua.ulong
---@overload fun(v: olua.ulong): olua.ulong
function ulong.new(len) end

---@param from integer
---@param to integer
---@return olua.ulong
---@overload fun(self: olua.ulong, from: integer): olua.ulong
function ulong:slice(from, to) end

---@param from integer
---@param to integer
---@return olua.ulong
---@overload fun(self: olua.ulong, from: integer): olua.ulong
function ulong:sub(from, to) end

---@return olua.ulong
function ulong:take() end

---@param len integer
---@return any
function ulong:tostring(len) end

return ulong