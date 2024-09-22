---AUTO GENERATED, DO NOT MODIFY!
---@meta ccs.ActionNode

---\js NA
---\lua NA
---@class ccs.ActionNode : cc.Ref
---@field actionDoneOnce boolean Gets if the action is done once time. <br><br>\return   that if the action is done once time
---@field actionTag integer Gets tag for ActionNode <br><br>\return tag    tag of ActionNode
---@field firstFrameIndex integer Gets index of first ActionFrame. <br><br>\return  index of first ActionFrame
---@field lastFrameIndex integer Gets index of last ActionFrame. <br><br>\return  index of last ActionFrame
---@field object cc.Ref Gets node which will run a action. <br><br>\return  node which will run a action
---@field unitTime number Gets the time interval of frame. <br><br>\return fTime   the time interval of frame
local ActionNode = {}

---Pushes back a ActionFrame to ActionNode.
---
---@param frame ccs.ActionFrame # the ActionFrame which will be added
function ActionNode:addFrame(frame) end

---Remove all ActionFrames from ActionNode.
function ActionNode:clearAllFrame() end

---Remove a ActionFrame from ActionNode.
---
---@param frame ccs.ActionFrame # the ActionFrame which will be removed
function ActionNode:deleteFrame(frame) end

---Gets tag for ActionNode
---
---@return integer # tag    tag of ActionNode
function ActionNode:getActionTag() end

---Gets index of first ActionFrame.
---
---@return integer # index of first ActionFrame
function ActionNode:getFirstFrameIndex() end

---Gets index of last ActionFrame.
---
---@return integer # index of last ActionFrame
function ActionNode:getLastFrameIndex() end

---Gets node which will run a action.
---
---@return cc.Ref # node which will run a action
function ActionNode:getObject() end

---Gets the time interval of frame.
---
---@return number # fTime   the time interval of frame
function ActionNode:getUnitTime() end

---Insets a ActionFrame to ActionNode.
---
---@param index integer # the index of ActionFrame
---
---@param frame ccs.ActionFrame # the ActionFrame which will be inserted
function ActionNode:insertFrame(index, frame) end

---Gets if the action is done once time.
---
---@return boolean # that if the action is done once time
function ActionNode:isActionDoneOnce() end

---Default constructor
---@return ccs.ActionNode
function ActionNode.new() end

---Play the action.
function ActionNode:playAction() end

---Sets tag for ActionNode
---
---@param tag integer # tag of ActionNode
function ActionNode:setActionTag(tag) end

---Sets node which will run a action.
---
---@param node cc.Ref # which will run a action
function ActionNode:setObject(node) end

---Sets the time interval of frame.
---
---@param fTime number # the time interval of frame
function ActionNode:setUnitTime(fTime) end

---Stop the action.
function ActionNode:stopAction() end

---Updates action states to some time.
---
---@param fTime number # the time when need to update
---@return boolean
function ActionNode:updateActionToTimeLine(fTime) end

return ActionNode