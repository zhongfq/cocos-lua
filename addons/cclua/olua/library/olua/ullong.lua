---AUTO GENERATED, DO NOT MODIFY!
---@meta olua.ullong

---
---@class olua.ullong 
---@field buffer any 
---@field length integer 
---@field value integer 
local ullong = {}

---@return any
function ullong:__gc() end

---@param idx integer
---@return integer
function ullong:__index(idx) end

---@param idx integer
---@param v integer
function ullong:__newindex(idx, v) end

---@param len integer
---@return olua.ullong
---@overload fun(): olua.ullong
---@overload fun(v: olua.ullong, len: integer): olua.ullong
---@overload fun(v: olua.ullong): olua.ullong
function ullong.new(len) end

---@param from integer
---@param to integer
---@return olua.ullong
---@overload fun(self: olua.ullong, from: integer): olua.ullong
function ullong:slice(from, to) end

---@param from integer
---@param to integer
---@return olua.ullong
---@overload fun(self: olua.ullong, from: integer): olua.ullong
function ullong:sub(from, to) end

---@return olua.ullong
function ullong:take() end

---@param len integer
---@return any
function ullong:tostring(len) end

return ullong