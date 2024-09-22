---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.LayerGradient

---\class LayerGradient
---LayerGradient is a subclass of LayerColor that draws gradients across the background.
---
---All features from LayerColor are valid, plus the following new features:
---- direction
---- final color
---- interpolation mode
---
---Color is interpolated between the startColor and endColor along the given
---vector (starting at the origin, ending at the terminus).  If no vector is
---supplied, it defaults to (0, -1) -- a fade from top to bottom.
---
---If 'compressedInterpolation' is disabled, you will not see either the start or end color for
---non-cardinal vectors; a smooth gradient implying both end points will be still
---be drawn, however.
---
---If ' compressedInterpolation' is enabled (default mode) you will see both the start and end colors of the gradient.
---
---\since v0.99.5
---@class cc.LayerGradient : cc.LayerColor
---@field compressedInterpolation boolean Get the compressedInterpolation <br><br>\return The interpolation will be compressed if true.
---@field endColor any Returns the end color of the gradient. <br><br>\return The end color.
---@field endOpacity integer Returns the end opacity of the gradient. <br><br>\return The end opacity.
---@field startColor any Returns the start color of the gradient. <br><br>\return The start color.
---@field startOpacity integer Returns the start opacity of the gradient. <br><br>\return The start opacity.
---@field vector cc.Vec2 Returns the directional vector used for the gradient. <br><br>\return The direction of gradient.
local LayerGradient = {}

---Creates a fullscreen black layer.
---
---@return cc.LayerGradient # An autoreleased LayerGradient object.
---
---Creates a full-screen Layer with a gradient between start and end.
---
---\param start The start color.
---\param end The end color.
---\return An autoreleased LayerGradient object.
---@overload fun(start: any, end_: any): cc.LayerGradient
---
---Creates a full-screen Layer with a gradient between start and end in the direction of v.
---
---\param start The start color.
---\param end The end color.
---\param v The direction of gradient color.
---\return An autoreleased LayerGradient object.
---@overload fun(start: any, end_: any, v: cc.Vec2): cc.LayerGradient
function LayerGradient.create() end

---Returns the end color of the gradient.
---
---@return any # The end color.
function LayerGradient:getEndColor() end

---Returns the end opacity of the gradient.
---
---@return integer # The end opacity.
function LayerGradient:getEndOpacity() end

---Returns the start color of the gradient.
---
---@return any # The start color.
function LayerGradient:getStartColor() end

---Returns the start opacity of the gradient.
---
---@return integer # The start opacity.
function LayerGradient:getStartOpacity() end

---Returns the directional vector used for the gradient.
---
---@return cc.Vec2 # The direction of gradient.
function LayerGradient:getVector() end

---Initializes the Layer with a gradient between start and end.
---\js init
---\lua init
---@param start any
---@param end_ any
---@return boolean
---
---Initializes the Layer with a gradient between start and end in the direction of v.
---\js init
---\lua init
---@overload fun(self: cc.LayerGradient, start: any, end_: any, v: cc.Vec2): boolean
function LayerGradient:initWithColor(start, end_) end

---Get the compressedInterpolation
---
---@return boolean # The interpolation will be compressed if true.
function LayerGradient:isCompressedInterpolation() end

---@return cc.LayerGradient
function LayerGradient.new() end

---Whether or not the interpolation will be compressed in order to display all the colors of the gradient both in canonical and non canonical vectors.
---Default: true.
---
---@param compressedInterpolation boolean # The interpolation will be compressed if true.
function LayerGradient:setCompressedInterpolation(compressedInterpolation) end

---Sets the end color of the gradient.
---
---@param endColor any # The end color.
function LayerGradient:setEndColor(endColor) end

---Returns the end opacity of the gradient.
---
---@param endOpacity integer # The end opacity, from 0 to 255.
function LayerGradient:setEndOpacity(endOpacity) end

---Sets the start color of the gradient.
---
---@param startColor any # The start color.
function LayerGradient:setStartColor(startColor) end

---Returns the start opacity of the gradient.
---
---@param startOpacity integer # The start opacity, from 0 to 255.
function LayerGradient:setStartOpacity(startOpacity) end

---Sets the directional vector that will be used for the gradient.
---The default value is vertical direction (0,-1). 
---
---@param alongVector cc.Vec2 # The direction of gradient.
function LayerGradient:setVector(alongVector) end

return LayerGradient