---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.VectorInt

---
---@class cc.VectorInt 
---@field length integer 
---@field rawdata any 
---@field sizeof integer 
---@field value integer[] 
local VectorInt = {}


---@return any
function VectorInt:__gc() end

---@param idx integer
---@return integer[]
function VectorInt:__index(idx) end

---@param idx integer
---@param v integer[]
function VectorInt:__newindex(idx, v) end

---@return any
function VectorInt:__olua_move() end

---@param data string
---@param len integer
function VectorInt:assign(data, len) end

---@param len integer
---@return cc.VectorInt
---@overload fun(): cc.VectorInt
function VectorInt.new(len) end

---@param from integer
---@param to integer
---@return cc.VectorInt
---@overload fun(self: cc.VectorInt, from: integer): cc.VectorInt
function VectorInt:slice(from, to) end

---@param from integer
---@param to integer
---@return cc.VectorInt
---@overload fun(self: cc.VectorInt, from: integer): cc.VectorInt
function VectorInt:sub(from, to) end

---@return cc.VectorInt
function VectorInt:take() end

---@param len integer
---@return any
function VectorInt:tostring(len) end

return VectorInt