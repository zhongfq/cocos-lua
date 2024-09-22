---AUTO GENERATED, DO NOT MODIFY!
---@meta olua.uint

---
---@class olua.uint 
---@field buffer any 
---@field length integer 
---@field value integer 
local uint = {}

---@return any
function uint:__gc() end

---@param idx integer
---@return integer
function uint:__index(idx) end

---@param idx integer
---@param v integer
function uint:__newindex(idx, v) end

---@param len integer
---@return olua.uint
---@overload fun(): olua.uint
---@overload fun(v: olua.uint, len: integer): olua.uint
---@overload fun(v: olua.uint): olua.uint
function uint.new(len) end

---@param from integer
---@param to integer
---@return olua.uint
---@overload fun(self: olua.uint, from: integer): olua.uint
function uint:slice(from, to) end

---@param from integer
---@param to integer
---@return olua.uint
---@overload fun(self: olua.uint, from: integer): olua.uint
function uint:sub(from, to) end

---@return olua.uint
function uint:take() end

---@param len integer
---@return any
function uint:tostring(len) end

return uint