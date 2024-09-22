---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Animate

---\class Animate
---Animates a sprite given the name of an Animation.
---@class cc.Animate : cc.ActionInterval
---@field animation cc.Animation returns the Animation object that is being animated  <br><br>\return Gets the animation object that is being animated.
---@field currentFrameIndex integer Gets the index of sprite frame currently displayed. \return int  the index of sprite frame currently displayed.
local Animate = {}

---Creates the action with an Animation and will restore the original frame when the animation is over.
---
---@param animation cc.Animation # A certain animation.
---@return cc.Animate # An autoreleased Animate object.
function Animate.create(animation) end

---returns the Animation object that is being animated 
---
---@return cc.Animation # Gets the animation object that is being animated.
function Animate:getAnimation() end

---Gets the index of sprite frame currently displayed.
---@return integer # int  the index of sprite frame currently displayed.
function Animate:getCurrentFrameIndex() end

---Sets the Animation object to be animated 
---
---@param animation cc.Animation # certain animation.
function Animate:setAnimation(animation) end

return Animate