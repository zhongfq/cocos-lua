---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.ComAttribute

---
---@class ccs.ComAttribute : cc.Component
---@field COMPONENT_NAME string
local ComAttribute = {}

---@return ccs.ComAttribute
function ComAttribute.create() end

---@return cc.Ref
function ComAttribute.createInstance() end

---@param key string
---@param def boolean
---@return boolean
---@overload fun(self: ccs.ComAttribute, key: string): boolean
function ComAttribute:getBool(key, def) end

---@param key string
---@param def number
---@return number
---@overload fun(self: ccs.ComAttribute, key: string): number
function ComAttribute:getFloat(key, def) end

---@param key string
---@param def integer
---@return integer
---@overload fun(self: ccs.ComAttribute, key: string): integer
function ComAttribute:getInt(key, def) end

---@param key string
---@param def string
---@return string
---@overload fun(self: ccs.ComAttribute, key: string): string
function ComAttribute:getString(key, def) end

---\js ctor
---@return ccs.ComAttribute
function ComAttribute.new() end

---@param jsonFile string
---@return boolean
function ComAttribute:parse(jsonFile) end

---@param key string
---@param value boolean
function ComAttribute:setBool(key, value) end

---@param key string
---@param value number
function ComAttribute:setFloat(key, value) end

---@param key string
---@param value integer
function ComAttribute:setInt(key, value) end

---@param key string
---@param value string
function ComAttribute:setString(key, value) end

return ComAttribute