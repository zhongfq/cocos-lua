---AUTO GENERATED, DO NOT MODIFY!
---@meta olua.short

---
---@class olua.short 
---@field buffer any 
---@field length integer 
---@field value integer 
local short = {}

---@return any
function short:__gc() end

---@param idx integer
---@return integer
function short:__index(idx) end

---@param idx integer
---@param v integer
function short:__newindex(idx, v) end

---@param len integer
---@return olua.short
---@overload fun(): olua.short
---@overload fun(v: olua.short, len: integer): olua.short
---@overload fun(v: olua.short): olua.short
function short.new(len) end

---@param from integer
---@param to integer
---@return olua.short
---@overload fun(self: olua.short, from: integer): olua.short
function short:slice(from, to) end

---@param from integer
---@param to integer
---@return olua.short
---@overload fun(self: olua.short, from: integer): olua.short
function short:sub(from, to) end

---@return olua.short
function short:take() end

---@param len integer
---@return any
function short:tostring(len) end

return short