---AUTO GENERATED, DO NOT MODIFY!
---@meta olua.uchar

---
---@class olua.uchar 
---@field buffer any 
---@field length integer 
---@field value integer 
local uchar = {}

---@return any
function uchar:__gc() end

---@param idx integer
---@return integer
function uchar:__index(idx) end

---@param idx integer
---@param v integer
function uchar:__newindex(idx, v) end

---@param len integer
---@return olua.uchar
---@overload fun(): olua.uchar
---@overload fun(v: olua.uchar, len: integer): olua.uchar
---@overload fun(v: olua.uchar): olua.uchar
function uchar.new(len) end

---@param from integer
---@param to integer
---@return olua.uchar
---@overload fun(self: olua.uchar, from: integer): olua.uchar
function uchar:slice(from, to) end

---@param from integer
---@param to integer
---@return olua.uchar
---@overload fun(self: olua.uchar, from: integer): olua.uchar
function uchar:sub(from, to) end

---@return olua.uchar
function uchar:take() end

---@param len integer
---@return any
function uchar:tostring(len) end

return uchar