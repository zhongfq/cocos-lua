---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.ActionObject

---\js NA
---\lua NA
---@class ccs.ActionObject : cc.Ref
---@field currentTime number Gets the current time of frame. <br><br>\return the current time of frame
---@field loop boolean Gets if the action will loop play. <br><br>\return   that if the action will loop play
---@field name string Gets name of object <br><br>\return name of object
---@field playing boolean Return if the action is playing. <br><br>\return true if the action is playing, false the otherwise
---@field totalTime number Gets the total time of frame. <br><br>\return the total time of frame
---@field unitTime number Gets the time interval of frame. <br><br>\return the time interval of frame
local ActionObject = {}

---Adds a ActionNode to play the action.
---
---@param node ccs.ActionNode # the ActionNode which will play the action
function ActionObject:addActionNode(node) end

---Gets the current time of frame.
---
---@return number # the current time of frame
function ActionObject:getCurrentTime() end

---Gets if the action will loop play.
---
---@return boolean # that if the action will loop play
function ActionObject:getLoop() end

---Gets name of object
---
---@return string # name of object
function ActionObject:getName() end

---Gets the total time of frame.
---
---@return number # the total time of frame
function ActionObject:getTotalTime() end

---Gets the time interval of frame.
---
---@return number # the time interval of frame
function ActionObject:getUnitTime() end

---Return if the action is playing.
---
---@return boolean # true if the action is playing, false the otherwise
function ActionObject:isPlaying() end

---Default constructor
---@return ccs.ActionObject
function ActionObject.new() end

---Pause the action.
function ActionObject:pause() end

---Play the action.
---
---Play the action.
---
---\param func Action Call Back
---@overload fun(self: ccs.ActionObject, func: cc.CallFunc)
function ActionObject:play() end

---Removes a ActionNode which play the action.
---
---@param node ccs.ActionNode # the ActionNode which play the action
function ActionObject:removeActionNode(node) end

---Sets the current time of frame.
---
---@param fTime number # the current time of frame
function ActionObject:setCurrentTime(fTime) end

---Sets if the action will loop play.
---
---@param bLoop boolean # that if the action will loop play
function ActionObject:setLoop(bLoop) end

---Sets name for object
---
---@param name string # name of object
function ActionObject:setName(name) end

---Sets the time interval of frame.
---
---@param fTime number # the time interval of frame
function ActionObject:setUnitTime(fTime) end

---@param dt number
function ActionObject:simulationActionUpdate(dt) end

---Stop the action.
function ActionObject:stop() end

---@param fTime number
function ActionObject:updateToFrameByTime(fTime) end

return ActionObject