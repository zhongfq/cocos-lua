---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.AnimationFrame

---\class AnimationFrame
---
---A frame of the animation. It contains information like:
---- sprite frame name.
---- # of delay units.
---- offset
---
---\since v2.0
---@class cc.AnimationFrame : cc.Ref
---@field delayUnits number Gets the units of time the frame takes. <br><br>\return The units of time the frame takes.
---@field spriteFrame cc.SpriteFrame Return a SpriteFrameName to be used. <br><br>\return a SpriteFrameName to be used.
---@field userInfo any Gets user information A AnimationFrameDisplayedNotification notification will be broadcast when the frame is displayed with this dictionary as UserInfo.  If UserInfo is nil, then no notification will be broadcast. <br><br>\return A dictionary as UserInfo
local AnimationFrame = {}

---@param cls string
---@return any
function AnimationFrame:as(cls) end

---@return cc.AnimationFrame
function AnimationFrame:clone() end

---Creates the animation frame with a spriteframe, number of delay units and a notification user info.
---
---@param spriteFrame cc.SpriteFrame # The animation frame with a spriteframe.
---@param delayUnits number # Number of delay units.
---@param userInfo any # A notification user info.
---\since 3.0
---@return cc.AnimationFrame
function AnimationFrame.create(spriteFrame, delayUnits, userInfo) end

---Gets the units of time the frame takes.
---
---@return number # The units of time the frame takes.
function AnimationFrame:getDelayUnits() end

---Return a SpriteFrameName to be used.
---
---@return cc.SpriteFrame # a SpriteFrameName to be used.
function AnimationFrame:getSpriteFrame() end

---Gets user information
---A AnimationFrameDisplayedNotification notification will be broadcast when the frame is displayed with this dictionary as UserInfo. 
---If UserInfo is nil, then no notification will be broadcast.
---
---@return any # A dictionary as UserInfo
function AnimationFrame:getUserInfo() end

---initializes the animation frame with a spriteframe, number of delay units and a notification user info
---@param spriteFrame cc.SpriteFrame
---@param delayUnits number
---@param userInfo any
---@return boolean
function AnimationFrame:initWithSpriteFrame(spriteFrame, delayUnits, userInfo) end

---\js ctor
---@return cc.AnimationFrame
function AnimationFrame.new() end

---Sets the units of time the frame takes.
---
---@param delayUnits number # The units of time the frame takes.
function AnimationFrame:setDelayUnits(delayUnits) end

---Set the SpriteFrame.
---
---@param frame cc.SpriteFrame # A SpriteFrame will be used.
function AnimationFrame:setSpriteFrame(frame) end

---Sets user information.
---@param userInfo any # A dictionary as UserInfo.
function AnimationFrame:setUserInfo(userInfo) end

return AnimationFrame