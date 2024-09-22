---AUTO GENERATED, DO NOT MODIFY!
---@meta olua.bool

---
---@class olua.bool 
---@field buffer any 
---@field length integer 
---@field value boolean 
local bool = {}

---@return any
function bool:__gc() end

---@param idx integer
---@return boolean
function bool:__index(idx) end

---@param idx integer
---@param v boolean
function bool:__newindex(idx, v) end

---@param len integer
---@return olua.bool
---@overload fun(): olua.bool
---@overload fun(v: olua.bool, len: integer): olua.bool
---@overload fun(v: olua.bool): olua.bool
function bool.new(len) end

---@param from integer
---@param to integer
---@return olua.bool
---@overload fun(self: olua.bool, from: integer): olua.bool
function bool:slice(from, to) end

---@param from integer
---@param to integer
---@return olua.bool
---@overload fun(self: olua.bool, from: integer): olua.bool
function bool:sub(from, to) end

---@return olua.bool
function bool:take() end

---@param len integer
---@return any
function bool:tostring(len) end

return bool