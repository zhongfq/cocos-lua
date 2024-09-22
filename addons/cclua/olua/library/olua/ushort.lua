---AUTO GENERATED, DO NOT MODIFY!
---@meta olua.ushort

---
---@class olua.ushort 
---@field buffer any 
---@field length integer 
---@field value integer 
local ushort = {}

---@return any
function ushort:__gc() end

---@param idx integer
---@return integer
function ushort:__index(idx) end

---@param idx integer
---@param v integer
function ushort:__newindex(idx, v) end

---@param len integer
---@return olua.ushort
---@overload fun(): olua.ushort
---@overload fun(v: olua.ushort, len: integer): olua.ushort
---@overload fun(v: olua.ushort): olua.ushort
function ushort.new(len) end

---@param from integer
---@param to integer
---@return olua.ushort
---@overload fun(self: olua.ushort, from: integer): olua.ushort
function ushort:slice(from, to) end

---@param from integer
---@param to integer
---@return olua.ushort
---@overload fun(self: olua.ushort, from: integer): olua.ushort
function ushort:sub(from, to) end

---@return olua.ushort
function ushort:take() end

---@param len integer
---@return any
function ushort:tostring(len) end

return ushort