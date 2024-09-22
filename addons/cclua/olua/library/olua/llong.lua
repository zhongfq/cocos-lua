---AUTO GENERATED, DO NOT MODIFY!
---@meta olua.llong

---
---@class olua.llong 
---@field buffer any 
---@field length integer 
---@field value integer 
local llong = {}

---@return any
function llong:__gc() end

---@param idx integer
---@return integer
function llong:__index(idx) end

---@param idx integer
---@param v integer
function llong:__newindex(idx, v) end

---@param len integer
---@return olua.llong
---@overload fun(): olua.llong
---@overload fun(v: olua.llong, len: integer): olua.llong
---@overload fun(v: olua.llong): olua.llong
function llong.new(len) end

---@param from integer
---@param to integer
---@return olua.llong
---@overload fun(self: olua.llong, from: integer): olua.llong
function llong:slice(from, to) end

---@param from integer
---@param to integer
---@return olua.llong
---@overload fun(self: olua.llong, from: integer): olua.llong
function llong:sub(from, to) end

---@return olua.llong
function llong:take() end

---@param len integer
---@return any
function llong:tostring(len) end

return llong