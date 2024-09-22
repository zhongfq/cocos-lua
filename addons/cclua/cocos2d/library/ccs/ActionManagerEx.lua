---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.ActionManagerEx

---
---@class ccs.ActionManagerEx : cc.Ref
---@field instance ccs.ActionManagerEx Gets the static instance of ActionManager. \js getInstance \lua getInstance
---@field studioVersionNumber integer 
local ActionManagerEx = {}

---Purges ActionManager point.
---\js purge
---\lua destroyActionManager
function ActionManagerEx.destroyInstance() end

---Gets an ActionObject with a name.
---
---@param jsonName string # UI file name
---
---@param actionName string # action name in the UI file.
---
---@return ccs.ActionObject # ActionObject which named as the param name
function ActionManagerEx:getActionByName(jsonName, actionName) end

---Gets the static instance of ActionManager.
---\js getInstance
---\lua getInstance
---@return ccs.ActionManagerEx
function ActionManagerEx.getInstance() end

---@return integer
function ActionManagerEx:getStudioVersionNumber() end

---Default constructor
---\js ctor
---@return ccs.ActionManagerEx
function ActionManagerEx.new() end

---Play an Action with a name.
---
---@param jsonName string # UI file name
---
---@param actionName string # action name in the UIfile.
---
---@return ccs.ActionObject # ActionObject which named as the param name
---
---Play an Action with a name.
---
---\param jsonName  UI file name
---
---\param actionName  action name in the UIfile.
---
---\param func ui action call back
---@overload fun(self: ccs.ActionManagerEx, jsonName: string, actionName: string, func: cc.CallFunc): ccs.ActionObject
function ActionManagerEx:playActionByName(jsonName, actionName) end

---Release all actions.
function ActionManagerEx:releaseActions() end

---Stop an Action with a name.
---
---@param jsonName string # UI file name
---
---@param actionName string # action name in the UIfile.
---
---@return ccs.ActionObject # ActionObject which named as the param name
function ActionManagerEx:stopActionByName(jsonName, actionName) end

return ActionManagerEx