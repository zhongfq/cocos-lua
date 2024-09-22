---AUTO GENERATED, DO NOT MODIFY!
---@meta olua.string

---
---@class olua.string 
---@field buffer any 
---@field length integer 
---@field value string 
local string = {}

---@return any
function string:__gc() end

---@param idx integer
---@return string
function string:__index(idx) end

---@param idx integer
---@param v string
function string:__newindex(idx, v) end

---@param len integer
---@return olua.string
---@overload fun(): olua.string
---@overload fun(v: olua.string, len: integer): olua.string
---@overload fun(v: olua.string): olua.string
function string.new(len) end

---@param from integer
---@param to integer
---@return olua.string
---@overload fun(self: olua.string, from: integer): olua.string
function string:slice(from, to) end

---@param from integer
---@param to integer
---@return olua.string
---@overload fun(self: olua.string, from: integer): olua.string
function string:sub(from, to) end

---@return olua.string
function string:take() end

---@param len integer
---@return any
function string:tostring(len) end

return string