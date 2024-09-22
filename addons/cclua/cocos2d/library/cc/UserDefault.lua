---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.UserDefault

---UserDefault acts as a tiny database. You can save and get base type values by it.
---For example, setBoolForKey("played", true) will add a bool value true into the database.
---Its key is "played". You can get the value of the key by getBoolForKey("played").
---
---It supports the following base types:
---bool, int, float, double, string
---
---\warning: On windows, linux, use XML to store data, which means there are some limitations of
---the key string, for example, `/` is not valid.
---@class cc.UserDefault 
---@field instance cc.UserDefault Returns the singleton. \js NA \lua NA
---@field xmlFileExist boolean All supported platforms other iOS & Android use xml file to save values. This function checks whether the xml file exists or not. \return True if the xml file exists, false if not. \js NA
---@field xmlFilePath string All supported platforms other iOS & Android use xml file to save values. This function is return the file path of the xml path. \js NA
local UserDefault = {}

---delete any value by key,
---@param key string # The key to delete value.
---\js NA
function UserDefault:deleteValueForKey(key) end

---\js NA
function UserDefault.destroyInstance() end

---You should invoke this function to save values set by setXXXForKey().
---\js NA
function UserDefault:flush() end

---Get bool value by key, if the key doesn't exist, will return false.
---You can set the default value, or it is false.
---@param key string # The key to get value.
---@return boolean # Bool value by `key`.
---\js NA
---
---Get bool value by key, if the key doesn't exist, will return passed default value.
---\param key The key to get value.
---\param defaultValue The default value to return if the key doesn't exist.
---\js NA
---@overload fun(self: cc.UserDefault, key: string, defaultValue: boolean): boolean
function UserDefault:getBoolForKey(key) end

---Get Data value by key, if the key doesn't exist, will return an empty Data.
---@param key string # The key to get value.
---@return any # Data value of the key.
---\js NA
---
---Get Data value by key, if the key doesn't exist, will return an empty Data.
---\param key The key to get value.
---\param defaultValue The default value to return if the key doesn't exist.
---\return Data value of the key.
---\js NA
---@overload fun(self: cc.UserDefault, key: string, defaultValue: any): any
function UserDefault:getDataForKey(key) end

---Get double value by key, if the key doesn't exist, will return 0.0.
---@param key string # The key to get value.
---@return number # Double value of the key.
---\js NA
---
---Get double value by key, if the key doesn't exist, will return passed default value.
---\param key The key to get value.
---\param defaultValue The default value to return if the key doesn't exist.
---\return Double value of the key.
---\js NA
---@overload fun(self: cc.UserDefault, key: string, defaultValue: number): number
function UserDefault:getDoubleForKey(key) end

---Get float value by key, if the key doesn't exist, will return 0.0.
---@param key string # The key to get value.
---@return number # Float value of the key.
---\js NA
---
---Get float value by key, if the key doesn't exist, will return passed default value.
---\param key The key to get value.
---\param defaultValue The default value to return if the key doesn't exist.
---\return Float value of the key.
---\js NA
---@overload fun(self: cc.UserDefault, key: string, defaultValue: number): number
function UserDefault:getFloatForKey(key) end

---Returns the singleton.
---\js NA
---\lua NA
---@return cc.UserDefault
function UserDefault.getInstance() end

---Get integer value by key, if the key doesn't exist, will return 0.
---You can set the default value, or it is 0.
---@param key string # The key to get value.
---@return integer # Integer value of the key.
---\js NA
---
---Get bool value by key, if the key doesn't exist, will return passed default value.
---\param key The key to get value.
---\param defaultValue The default value to return if the key doesn't exist.
---\return Integer value of the key.
---\js NA
---@overload fun(self: cc.UserDefault, key: string, defaultValue: integer): integer
function UserDefault:getIntegerForKey(key) end

---Get string value by key, if the key doesn't exist, will return an empty string.
---@param key string # The key to get value.
---@return string # String value of the key.
---\js NA
---
---Get string value by key, if the key doesn't exist, will return passed default value.
---\param key The key to get value.
---\param defaultValue The default value to return if the key doesn't exist.
---\return String value of the key.
---\js NA
---@overload fun(self: cc.UserDefault, key: string, defaultValue: string): string
function UserDefault:getStringForKey(key) end

---All supported platforms other iOS & Android use xml file to save values. This function is return the file path of the xml path.
---\js NA
---@return string
function UserDefault.getXMLFilePath() end

---All supported platforms other iOS & Android use xml file to save values. This function checks whether the xml file exists or not.
---@return boolean # True if the xml file exists, false if not.
---\js NA
function UserDefault.isXMLFileExist() end

---Set bool value by key.
---@param key string # The key to set.
---@param value boolean # A bool value to set to the key.
---\js NA
function UserDefault:setBoolForKey(key, value) end

---Set Data value by key.
---@param key string # The key to set.
---@param value any # A Data value to set to the key.
---\js NA
function UserDefault:setDataForKey(key, value) end

---Set double value by key.
---@param key string # The key to set.
---@param value number # A double value to set to the key.
---\js NA
function UserDefault:setDoubleForKey(key, value) end

---Set float value by key.
---@param key string # The key to set.
---@param value number # A float value to set to the key.
---\js NA
function UserDefault:setFloatForKey(key, value) end

---Set integer value by key.
---@param key string # The key to set.
---@param value integer # A integer value to set to the key.
---\js NA
function UserDefault:setIntegerForKey(key, value) end

---Set string value by key.
---@param key string # The key to set.
---@param value string # A string value to set to the key.
---\js NA
function UserDefault:setStringForKey(key, value) end

return UserDefault