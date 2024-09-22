---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.GUIReader

---
---@class ccs.GUIReader : cc.Ref
---@field filePath string 
---@field instance ccs.GUIReader 
local GUIReader = {}

function GUIReader.destroyInstance() end

---\js NA
---@param fileName string
---@return cc.Size
function GUIReader:getFileDesignSize(fileName) end

---@return string
function GUIReader:getFilePath() end

---@return ccs.GUIReader
function GUIReader.getInstance() end

---@param str string
---@return integer
function GUIReader:getVersionInteger(str) end

---@param strFilePath string
function GUIReader:setFilePath(strFilePath) end

---\js NA
---@param fileName string
---@param size cc.Size
function GUIReader:storeFileDesignSize(fileName, size) end

---@param fileName string
---@return ccui.Widget
function GUIReader:widgetFromBinaryFile(fileName) end

---@param fileName string
---@return ccui.Widget
function GUIReader:widgetFromJsonFile(fileName) end

return GUIReader