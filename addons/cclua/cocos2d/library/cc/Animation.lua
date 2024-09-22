---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Animation

---\class Animation
---A Animation object is used to perform animations on the Sprite objects.
---The Animation object contains AnimationFrame objects, and a possible delay between the frames.
---You can animate a Animation object by using the Animate action. Example:
---\code
---sprite->runAction(Animate::create(animation));
---\endcode
---@class cc.Animation : cc.Ref
---@field delayPerUnit number Gets the delay in seconds of the "delay unit". <br><br>\return The delay in seconds of the "delay unit".
---@field duration number Gets the duration in seconds of the whole animation. It is the result of totalDelayUnits * delayPerUnit. <br><br>\return Result of totalDelayUnits * delayPerUnit.
---@field frames any Gets the array of AnimationFrames. <br><br>\return The array of AnimationFrames.
---@field loops integer Gets the times the animation is going to loop. 0 means animation is not animated. 1, animation is executed one time, ...  <br><br>\return The times the animation is going to loop.
---@field restoreOriginalFrame boolean Checks whether to restore the original frame when animation finishes.  <br><br>\return Restore the original frame when animation finishes.
---@field totalDelayUnits number Gets the total Delay units of the Animation.  <br><br>\return The total Delay units of the Animation.
local Animation = {}

---Adds a SpriteFrame to a Animation.
---
---@param frame cc.SpriteFrame # The frame will be added with one "delay unit".
function Animation:addSpriteFrame(frame) end

---Adds a frame with an image filename. Internally it will create a SpriteFrame and it will add it.
---The frame will be added with one "delay unit".
---Added to facilitate the migration from v0.8 to v0.9.
---@param filename string # The path of SpriteFrame.
function Animation:addSpriteFrameWithFile(filename) end

---Adds a frame with a texture and a rect. Internally it will create a SpriteFrame and it will add it.
---The frame will be added with one "delay unit".
---Added to facilitate the migration from v0.8 to v0.9.
---@param pobTexture cc.Texture2D # A frame with a texture.
---@param rect cc.Rect # The Texture of rect.
function Animation:addSpriteFrameWithTexture(pobTexture, rect) end

---@param cls string
---@return any
function Animation:as(cls) end

---@return cc.Animation
function Animation:clone() end

---Creates an animation.
---\since v0.99.5
---@return cc.Animation
---@overload fun(arrayOfAnimationFrameNames: any, delayPerUnit: number, loops: integer): cc.Animation
---@overload fun(arrayOfAnimationFrameNames: any, delayPerUnit: number): cc.Animation
function Animation.create() end

---@param arrayOfSpriteFrameNames any
---@param delay number
---@param loops integer
---@return cc.Animation
---@overload fun(arrayOfSpriteFrameNames: any): cc.Animation
---@overload fun(arrayOfSpriteFrameNames: any, delay: number): cc.Animation
function Animation.createWithSpriteFrames(arrayOfSpriteFrameNames, delay, loops) end

---Gets the delay in seconds of the "delay unit".
---
---@return number # The delay in seconds of the "delay unit".
function Animation:getDelayPerUnit() end

---Gets the duration in seconds of the whole animation. It is the result of totalDelayUnits * delayPerUnit.
---
---@return number # Result of totalDelayUnits * delayPerUnit.
function Animation:getDuration() end

---Gets the array of AnimationFrames.
---
---@return any # The array of AnimationFrames.
function Animation:getFrames() end

---Gets the times the animation is going to loop. 0 means animation is not animated. 1, animation is executed one time, ... 
---
---@return integer # The times the animation is going to loop.
function Animation:getLoops() end

---Checks whether to restore the original frame when animation finishes. 
---
---@return boolean # Restore the original frame when animation finishes.
function Animation:getRestoreOriginalFrame() end

---Gets the total Delay units of the Animation. 
---
---@return number # The total Delay units of the Animation.
function Animation:getTotalDelayUnits() end

---Initializes a Animation.
---@return boolean
function Animation:init() end

---Initializes a Animation with AnimationFrame.
---\since v2.0
---@param arrayOfAnimationFrameNames any
---@param delayPerUnit number
---@param loops integer
---@return boolean
function Animation:initWithAnimationFrames(arrayOfAnimationFrameNames, delayPerUnit, loops) end

---Initializes a Animation with frames and a delay between frames.
---\since v0.99.5
---@param arrayOfSpriteFrameNames any
---@param delay number
---@param loops integer
---@return boolean
---@overload fun(self: cc.Animation, arrayOfSpriteFrameNames: any): boolean
---@overload fun(self: cc.Animation, arrayOfSpriteFrameNames: any, delay: number): boolean
function Animation:initWithSpriteFrames(arrayOfSpriteFrameNames, delay, loops) end

---@return cc.Animation
function Animation.new() end

---Sets the delay in seconds of the "delay unit".
---
---@param delayPerUnit number # The delay in seconds of the "delay unit".
function Animation:setDelayPerUnit(delayPerUnit) end

---Sets the array of AnimationFrames. 
---
---@param frames any # The array of AnimationFrames.
function Animation:setFrames(frames) end

---Sets the times the animation is going to loop. 0 means animation is not animated. 1, animation is executed one time, ... 
---
---@param loops integer # The times the animation is going to loop.
function Animation:setLoops(loops) end

---Sets whether to restore the original frame when animation finishes. 
---
---@param restoreOriginalFrame boolean # Whether to restore the original frame when animation finishes.
function Animation:setRestoreOriginalFrame(restoreOriginalFrame) end

return Animation