---AUTO GENERATED, DO NOT MODIFY!
---@meta olua.char

---
---@class olua.char 
---@field buffer any 
---@field length integer 
---@field value integer 
local char = {}

---@return any
function char:__gc() end

---@param idx integer
---@return integer
function char:__index(idx) end

---@param idx integer
---@param v integer
function char:__newindex(idx, v) end

---@param len integer
---@return olua.char
---@overload fun(): olua.char
---@overload fun(v: olua.char, len: integer): olua.char
---@overload fun(v: olua.char): olua.char
function char.new(len) end

---@param from integer
---@param to integer
---@return olua.char
---@overload fun(self: olua.char, from: integer): olua.char
function char:slice(from, to) end

---@param from integer
---@param to integer
---@return olua.char
---@overload fun(self: olua.char, from: integer): olua.char
function char:sub(from, to) end

---@return olua.char
function char:take() end

---@param len integer
---@return any
function char:tostring(len) end

return char