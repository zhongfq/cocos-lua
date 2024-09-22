---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.DataReaderHelper

---\js NA
---\lua NA
---@class ccs.DataReaderHelper 
---@field instance ccs.DataReaderHelper 
---@field positionReadScale number 
local DataReaderHelper = {}

---@return any
function DataReaderHelper:__gc() end

---@param dt number
function DataReaderHelper:addDataAsyncCallBack(dt) end

---@param filePath string
function DataReaderHelper:addDataFromFile(filePath) end

---@return ccs.DataReaderHelper
function DataReaderHelper.getInstance() end

---@return number
function DataReaderHelper.getPositionReadScale() end

---\js ctor
---@return ccs.DataReaderHelper
function DataReaderHelper.new() end

function DataReaderHelper.purge() end

---@param configFile string
function DataReaderHelper:removeConfigFile(configFile) end

---Scale the position data, used for multiresolution adapter
---It won't effect the data already read.
---@param scale number
function DataReaderHelper.setPositionReadScale(scale) end

return DataReaderHelper