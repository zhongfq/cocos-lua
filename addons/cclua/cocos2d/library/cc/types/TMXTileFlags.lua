---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.types.TMXTileFlags

---
---@class cc.types.TMXTileFlags 
---@field buffer any 
---@field length integer 
---@field value cc.TMXTileFlags 
local TMXTileFlags = {}

---@return any
function TMXTileFlags:__gc() end

---@param idx integer
---@return cc.TMXTileFlags
function TMXTileFlags:__index(idx) end

---@param idx integer
---@param v cc.TMXTileFlags
function TMXTileFlags:__newindex(idx, v) end

---@param len integer
---@return cc.types.TMXTileFlags
---@overload fun(): cc.types.TMXTileFlags
---@overload fun(v: cc.types.TMXTileFlags, len: integer): cc.types.TMXTileFlags
---@overload fun(v: cc.types.TMXTileFlags): cc.types.TMXTileFlags
function TMXTileFlags.new(len) end

---@param from integer
---@param to integer
---@return cc.types.TMXTileFlags
---@overload fun(self: cc.types.TMXTileFlags, from: integer): cc.types.TMXTileFlags
function TMXTileFlags:slice(from, to) end

---@param from integer
---@param to integer
---@return cc.types.TMXTileFlags
---@overload fun(self: cc.types.TMXTileFlags, from: integer): cc.types.TMXTileFlags
function TMXTileFlags:sub(from, to) end

---@return cc.types.TMXTileFlags
function TMXTileFlags:take() end

---@param len integer
---@return any
function TMXTileFlags:tostring(len) end

return TMXTileFlags