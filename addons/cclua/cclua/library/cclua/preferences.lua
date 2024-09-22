---AUTO GENERATED, DO NOT MODIFY!
---@meta cclua.preferences

---
---@class cclua.preferences 
local preferences = {}

---@return any
function preferences:__gc() end

---@param key string
function preferences.deleteKey(key) end

function preferences.flush() end

---@param key string
---@param defaultValue boolean
---@return boolean
---@overload fun(key: string): boolean
function preferences.getBoolean(key, defaultValue) end

---@param key string
---@param defaultValue number
---@return number
---@overload fun(key: string): number
function preferences.getDouble(key, defaultValue) end

---@param key string
---@param defaultValue number
---@return number
---@overload fun(key: string): number
function preferences.getFloat(key, defaultValue) end

---@param key string
---@param defaultValue integer
---@return integer
---@overload fun(key: string): integer
function preferences.getInteger(key, defaultValue) end

---@param key string
---@param defaultValue string
---@return string
---@overload fun(key: string): string
function preferences.getString(key, defaultValue) end

---@param key string
---@param value boolean
function preferences.setBoolean(key, value) end

---@param key string
---@param value number
function preferences.setDouble(key, value) end

---@param key string
---@param value number
function preferences.setFloat(key, value) end

---@param key string
---@param value integer
function preferences.setInteger(key, value) end

---@param key string
---@param value string
function preferences.setString(key, value) end

return preferences