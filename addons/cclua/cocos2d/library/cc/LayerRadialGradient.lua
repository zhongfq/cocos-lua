---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.LayerRadialGradient

---\class LayerRadialGradient
---LayerRadialGradient is a subclass of Layer that draws radial gradients across the background.
---\since v3.16
---@class cc.LayerRadialGradient : cc.Layer
---@field blendFunc cc.BlendFunc 
---@field center cc.Vec2 
---@field endColor any 
---@field endColor3B any 
---@field endOpacity integer 
---@field expand number 
---@field radius number 
---@field startColor any 
---@field startColor3B any 
---@field startOpacity integer 
local LayerRadialGradient = {}

---Create a LayerRadialGradient
---@param startColor any # the inner color of the gradient
---@param endColor any # the out color of the gradient
---@param radius number # the radius of the gradient(length from center of gradient to outer color)
---@param center cc.Vec2 # the position of the center of the gradient
---@param expand number # an alpha value(0.f-1.f) that specifies how much of that radius in only inner color(the gradient
---starts outside of that amount)
---@return cc.LayerRadialGradient
---@overload fun(): cc.LayerRadialGradient
function LayerRadialGradient.create(startColor, endColor, radius, center, expand) end

---@return cc.BlendFunc
function LayerRadialGradient:getBlendFunc() end

---@return cc.Vec2
function LayerRadialGradient:getCenter() end

---@return any
function LayerRadialGradient:getEndColor() end

---@return any
function LayerRadialGradient:getEndColor3B() end

---@return integer
function LayerRadialGradient:getEndOpacity() end

---@return number
function LayerRadialGradient:getExpand() end

---@return number
function LayerRadialGradient:getRadius() end

---@return any
function LayerRadialGradient:getStartColor() end

---@return any
function LayerRadialGradient:getStartColor3B() end

---@return integer
function LayerRadialGradient:getStartOpacity() end

---@param startColor any
---@param endColor any
---@param radius number
---@param center cc.Vec2
---@param expand number
---@return boolean
function LayerRadialGradient:initWithColor(startColor, endColor, radius, center, expand) end

---@return cc.LayerRadialGradient
function LayerRadialGradient.new() end

---@param blendFunc cc.BlendFunc
function LayerRadialGradient:setBlendFunc(blendFunc) end

---@param center cc.Vec2
function LayerRadialGradient:setCenter(center) end

---@param color any
---@overload fun(self: cc.LayerRadialGradient, color: any)
function LayerRadialGradient:setEndColor(color) end

---@param opacity integer
function LayerRadialGradient:setEndOpacity(opacity) end

---@param expand number
function LayerRadialGradient:setExpand(expand) end

---@param radius number
function LayerRadialGradient:setRadius(radius) end

---@param color any
---@overload fun(self: cc.LayerRadialGradient, color: any)
function LayerRadialGradient:setStartColor(color) end

---@param opacity integer
function LayerRadialGradient:setStartOpacity(opacity) end

return LayerRadialGradient