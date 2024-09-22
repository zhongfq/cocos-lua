---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.types.ValueMap

---
---@class cc.types.ValueMap 
---@field buffer any 
---@field length integer 
---@field value any 
local ValueMap = {}

---@return any
function ValueMap:__gc() end

---@param idx integer
---@return any
function ValueMap:__index(idx) end

---@param idx integer
---@param v any
function ValueMap:__newindex(idx, v) end

---@param len integer
---@return cc.types.ValueMap
---@overload fun(): cc.types.ValueMap
---@overload fun(v: cc.types.ValueMap, len: integer): cc.types.ValueMap
---@overload fun(v: cc.types.ValueMap): cc.types.ValueMap
function ValueMap.new(len) end

---@param from integer
---@param to integer
---@return cc.types.ValueMap
---@overload fun(self: cc.types.ValueMap, from: integer): cc.types.ValueMap
function ValueMap:slice(from, to) end

---@param from integer
---@param to integer
---@return cc.types.ValueMap
---@overload fun(self: cc.types.ValueMap, from: integer): cc.types.ValueMap
function ValueMap:sub(from, to) end

---@return cc.types.ValueMap
function ValueMap:take() end

---@param len integer
---@return any
function ValueMap:tostring(len) end

return ValueMap