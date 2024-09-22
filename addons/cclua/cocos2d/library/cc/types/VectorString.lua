---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.types.VectorString

---
---@class cc.types.VectorString 
---@field buffer any 
---@field length integer 
---@field value string[] 
local VectorString = {}

---@return any
function VectorString:__gc() end

---@param idx integer
---@return string[]
function VectorString:__index(idx) end

---@param idx integer
---@param v string[]
function VectorString:__newindex(idx, v) end

---@param len integer
---@return cc.types.VectorString
---@overload fun(): cc.types.VectorString
---@overload fun(v: cc.types.VectorString, len: integer): cc.types.VectorString
---@overload fun(v: cc.types.VectorString): cc.types.VectorString
function VectorString.new(len) end

---@param from integer
---@param to integer
---@return cc.types.VectorString
---@overload fun(self: cc.types.VectorString, from: integer): cc.types.VectorString
function VectorString:slice(from, to) end

---@param from integer
---@param to integer
---@return cc.types.VectorString
---@overload fun(self: cc.types.VectorString, from: integer): cc.types.VectorString
function VectorString:sub(from, to) end

---@return cc.types.VectorString
function VectorString:take() end

---@param len integer
---@return any
function VectorString:tostring(len) end

return VectorString