---AUTO GENERATED, DO NOT MODIFY!
---@meta olua.uint8

---
---@class olua.uint8 
---@field buffer any 
---@field length integer 
---@field value integer 
local uint8 = {}

---@return any
function uint8:__gc() end

---@param idx integer
---@return integer
function uint8:__index(idx) end

---@param idx integer
---@param v integer
function uint8:__newindex(idx, v) end

---@param len integer
---@return olua.uint8
---@overload fun(): olua.uint8
---@overload fun(v: olua.uint8, len: integer): olua.uint8
---@overload fun(v: olua.uint8): olua.uint8
function uint8.new(len) end

---@param from integer
---@param to integer
---@return olua.uint8
---@overload fun(self: olua.uint8, from: integer): olua.uint8
function uint8:slice(from, to) end

---@param from integer
---@param to integer
---@return olua.uint8
---@overload fun(self: olua.uint8, from: integer): olua.uint8
function uint8:sub(from, to) end

---@return olua.uint8
function uint8:take() end

---@param len integer
---@return any
function uint8:tostring(len) end

return uint8