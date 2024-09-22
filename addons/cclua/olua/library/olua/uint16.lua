---AUTO GENERATED, DO NOT MODIFY!
---@meta olua.uint16

---
---@class olua.uint16 
---@field buffer any 
---@field length integer 
---@field value integer 
local uint16 = {}

---@return any
function uint16:__gc() end

---@param idx integer
---@return integer
function uint16:__index(idx) end

---@param idx integer
---@param v integer
function uint16:__newindex(idx, v) end

---@param len integer
---@return olua.uint16
---@overload fun(): olua.uint16
---@overload fun(v: olua.uint16, len: integer): olua.uint16
---@overload fun(v: olua.uint16): olua.uint16
function uint16.new(len) end

---@param from integer
---@param to integer
---@return olua.uint16
---@overload fun(self: olua.uint16, from: integer): olua.uint16
function uint16:slice(from, to) end

---@param from integer
---@param to integer
---@return olua.uint16
---@overload fun(self: olua.uint16, from: integer): olua.uint16
function uint16:sub(from, to) end

---@return olua.uint16
function uint16:take() end

---@param len integer
---@return any
function uint16:tostring(len) end

return uint16