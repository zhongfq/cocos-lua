---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.VectorString

---
---@class cc.VectorString 
---@field length integer 
---@field rawdata any 
---@field sizeof integer 
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

---@return any
function VectorString:__olua_move() end

---@param data string
---@param len integer
function VectorString:assign(data, len) end

---@param len integer
---@return cc.VectorString
---@overload fun(): cc.VectorString
function VectorString.new(len) end

---@param from integer
---@param to integer
---@return cc.VectorString
---@overload fun(self: cc.VectorString, from: integer): cc.VectorString
function VectorString:slice(from, to) end

---@param from integer
---@param to integer
---@return cc.VectorString
---@overload fun(self: cc.VectorString, from: integer): cc.VectorString
function VectorString:sub(from, to) end

---@return cc.VectorString
function VectorString:take() end

---@param len integer
---@return any
function VectorString:tostring(len) end

return VectorString