---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.SceneReader

---
---@class ccs.SceneReader 
---@field attachComponentType ccs.SceneReader.AttachComponentType 
---@field instance ccs.SceneReader 
local SceneReader = {}

---@return any
function SceneReader:__gc() end

---@param fileName string
---@param attachComponent ccs.SceneReader.AttachComponentType
---@return cc.Node
---@overload fun(self: ccs.SceneReader, fileName: string): cc.Node
function SceneReader:createNodeWithSceneFile(fileName, attachComponent) end

---\js purge
---\lua destroySceneReader
function SceneReader.destroyInstance() end

---@return ccs.SceneReader.AttachComponentType
function SceneReader:getAttachComponentType() end

---@return ccs.SceneReader
function SceneReader.getInstance() end

---@param nTag integer
---@return cc.Node
function SceneReader:getNodeByTag(nTag) end

---@return ccs.SceneReader
function SceneReader.new() end

---@return string
function SceneReader.sceneReaderVersion() end

---@param selector fun(arg1: cc.Ref, arg2: any)
function SceneReader:setTarget(selector) end

return SceneReader