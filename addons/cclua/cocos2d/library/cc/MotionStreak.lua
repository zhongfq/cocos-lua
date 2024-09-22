---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.MotionStreak

---\class MotionStreak.
---Creates a trailing path.
---@class cc.MotionStreak : cc.Node
---@field blendFunc cc.BlendFunc \js NA \lua NA
---@field fastMode boolean When fast mode is enabled, new points are added faster but with lower precision.  <br><br>\return True if fast mode is enabled.
---@field startingPositionInitialized boolean Is the starting position initialized or not. <br><br>\return True if the starting position is initialized.
---@field stroke number Get stroke. <br><br>\return float stroke.
---@field texture cc.Texture2D 
local MotionStreak = {}

---@param cls string
---@return any
function MotionStreak:as(cls) end

---Creates and initializes a motion streak with fade in seconds, minimum segments, stroke's width, color, texture filename.
---
---@param timeToFade number # The fade time, in seconds.
---@param minSeg number # The minimum segments.
---@param strokeWidth number # The width of stroke.
---@param strokeColor any # The color of stroke.
---@param imagePath string # The texture file name of stoke.
---@return cc.MotionStreak # An autoreleased MotionStreak object.
---
---Creates and initializes a motion streak with fade in seconds, minimum segments, stroke's width, color, texture.
---
---\param timeToFade The fade time, in seconds.
---\param minSeg The minimum segments.
---\param strokeWidth The width of stroke.
---\param strokeColor The color of stroke.
---\param texture The texture name of stoke.
---\return An autoreleased MotionStreak object.
---@overload fun(timeToFade: number, minSeg: number, strokeWidth: number, strokeColor: any, texture: cc.Texture2D): cc.MotionStreak
function MotionStreak.create(timeToFade, minSeg, strokeWidth, strokeColor, imagePath) end

---\js NA
---\lua NA
---@return cc.BlendFunc
function MotionStreak:getBlendFunc() end

---Get stroke.
---
---@return number # float stroke.
function MotionStreak:getStroke() end

---@return cc.Texture2D
function MotionStreak:getTexture() end

---initializes a motion streak with fade in seconds, minimum segments, stroke's width, color and texture filename
---@param fade number
---@param minSeg number
---@param stroke number
---@param color any
---@param path string
---@return boolean
---
---initializes a motion streak with fade in seconds, minimum segments, stroke's width, color and texture
---@overload fun(self: cc.MotionStreak, fade: number, minSeg: number, stroke: number, color: any, texture: cc.Texture2D): boolean
function MotionStreak:initWithFade(fade, minSeg, stroke, color, path) end

---When fast mode is enabled, new points are added faster but with lower precision. 
---
---@return boolean # True if fast mode is enabled.
function MotionStreak:isFastMode() end

---Is the starting position initialized or not.
---
---@return boolean # True if the starting position is initialized.
function MotionStreak:isStartingPositionInitialized() end

---@return cc.MotionStreak
function MotionStreak.new() end

---Remove all living segments of the ribbon.
function MotionStreak:reset() end

---\js NA
---\lua NA
---@param blendFunc cc.BlendFunc
function MotionStreak:setBlendFunc(blendFunc) end

---Sets fast mode or not.
---
---@param bFastMode boolean # True if enabled fast mode.
function MotionStreak:setFastMode(bFastMode) end

---Sets the starting position initialized or not.
---
---@param bStartingPositionInitialized boolean # True if initialized the starting position.
function MotionStreak:setStartingPositionInitialized(bStartingPositionInitialized) end

---Set stroke.
---
---@param stroke number # The width of stroke.
function MotionStreak:setStroke(stroke) end

---@param texture cc.Texture2D
function MotionStreak:setTexture(texture) end

---Color used for the tint.
---
---@param colors any # The color used for the tint.
function MotionStreak:tintWithColor(colors) end

return MotionStreak