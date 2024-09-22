---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.CSLoader

---
---@class cc.CSLoader 
---@field instance cc.CSLoader 
---@field jsonPath string 
---@field recordJsonPath boolean 
local CSLoader = {}

---@return any
function CSLoader:__gc() end

---@param callbackName string
---@param callbackType string
---@param sender ccui.Widget
---@param handler cc.Node
---@return boolean
function CSLoader:bindCallback(callbackName, callbackType, sender, handler) end

---@param filename string
---@return cc.Node
---@overload fun(filename: string, callback: fun(arg1: cc.Ref)): cc.Node
---@overload fun(data: any): cc.Node
---@overload fun(data: any, callback: fun(arg1: cc.Ref)): cc.Node
function CSLoader.createNode(filename) end

---@param filename string
---@return cc.Node
function CSLoader:createNodeFromJson(filename) end

---@param filename string
---@return cc.Node
function CSLoader:createNodeWithFlatBuffersFile(filename) end

---@param filename string
---@return cc.Node
function CSLoader:createNodeWithFlatBuffersForSimulator(filename) end

---@param filename string
---@return cc.Node
---@overload fun(filename: string, callback: fun(arg1: cc.Ref)): cc.Node
function CSLoader.createNodeWithVisibleSize(filename) end

---@param filename string
---@return ccs.timeline.ActionTimeline
---@overload fun(data: any, filename: string): ccs.timeline.ActionTimeline
function CSLoader.createTimeline(filename) end

function CSLoader.destroyInstance() end

---@return cc.CSLoader
function CSLoader.getInstance() end

---@return string
function CSLoader:getJsonPath() end

function CSLoader:init() end

---@return boolean
function CSLoader:isRecordJsonPath() end

---@param content string
---@return cc.Node
function CSLoader:loadNodeWithContent(content) end

---@param fileName string
---@return cc.Node
function CSLoader:loadNodeWithFile(fileName) end

---@return cc.CSLoader
function CSLoader.new() end

---@param fileName string
---@return cc.Node
function CSLoader:nodeWithFlatBuffersFile(fileName) end

---@param jsonPath string
function CSLoader:setJsonPath(jsonPath) end

---@param record boolean
function CSLoader:setRecordJsonPath(record) end

return CSLoader