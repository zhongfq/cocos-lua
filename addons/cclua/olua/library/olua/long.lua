---AUTO GENERATED, DO NOT MODIFY!
---@meta olua.long

---
---@class olua.long 
---@field buffer any 
---@field length integer 
---@field value integer 
local long = {}

---@return any
function long:__gc() end

---@param idx integer
---@return integer
function long:__index(idx) end

---@param idx integer
---@param v integer
function long:__newindex(idx, v) end

---@param len integer
---@return olua.long
---@overload fun(): olua.long
---@overload fun(v: olua.long, len: integer): olua.long
---@overload fun(v: olua.long): olua.long
function long.new(len) end

---@param from integer
---@param to integer
---@return olua.long
---@overload fun(self: olua.long, from: integer): olua.long
function long:slice(from, to) end

---@param from integer
---@param to integer
---@return olua.long
---@overload fun(self: olua.long, from: integer): olua.long
function long:sub(from, to) end

---@return olua.long
function long:take() end

---@param len integer
---@return any
function long:tostring(len) end

return long