---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.ValueMap

---
---@class cc.ValueMap 
---@field length integer 
---@field rawdata any 
---@field sizeof integer 
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

---@return any
function ValueMap:__olua_move() end

---@param data string
---@param len integer
function ValueMap:assign(data, len) end

---@param len integer
---@return cc.ValueMap
---@overload fun(): cc.ValueMap
function ValueMap.new(len) end

---@param from integer
---@param to integer
---@return cc.ValueMap
---@overload fun(self: cc.ValueMap, from: integer): cc.ValueMap
function ValueMap:slice(from, to) end

---@param from integer
---@param to integer
---@return cc.ValueMap
---@overload fun(self: cc.ValueMap, from: integer): cc.ValueMap
function ValueMap:sub(from, to) end

---@return cc.ValueMap
function ValueMap:take() end

---@param len integer
---@return any
function ValueMap:tostring(len) end

return ValueMap