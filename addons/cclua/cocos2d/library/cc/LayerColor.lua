---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.LayerColor

---\class LayerColor
---LayerColor is a subclass of Layer that implements the RGBAProtocol protocol.
---
---All features from Layer are valid, plus the following new features:
---- opacity
---- RGB colors
---@class cc.LayerColor : cc.Layer
---@field blendFunc cc.BlendFunc BlendFunction. Conforms to BlendProtocol protocol */ <br><br>\lua NA
local LayerColor = {}

---@param cls string
---@return any
function LayerColor:as(cls) end

---Change height in Points.
---
---@param h number # The height of layer.
function LayerColor:changeHeight(h) end

---Change width in Points.
---
---@param w number # The width of layer.
function LayerColor:changeWidth(w) end

---Change width and height in Points.
---
---@param w number # The width of layer.
---@param h number # The Height of layer.
---\since v0.8
function LayerColor:changeWidthAndHeight(w, h) end

---Creates a fullscreen black layer.
---
---@return cc.LayerColor # An autoreleased LayerColor object.
---
---Creates a Layer with color, width and height in Points.
---
---\param color The color of layer.
---\param width The width of layer.
---\param height The height of layer.
---\return An autoreleased LayerColor object.
---@overload fun(color: any, width: number, height: number): cc.LayerColor
---
---Creates a Layer with color. Width and height are the window size.
---
---\param color The color of layer.
---\return An autoreleased LayerColor object.
---@overload fun(color: any): cc.LayerColor
function LayerColor.create() end

---BlendFunction. Conforms to BlendProtocol protocol */
---
---\lua NA
---@return cc.BlendFunc
function LayerColor:getBlendFunc() end

---@param color any
---@param width number
---@param height number
---@return boolean
---@overload fun(self: cc.LayerColor, color: any): boolean
function LayerColor:initWithColor(color, width, height) end

---@return cc.LayerColor
function LayerColor.new() end

---\code
---When this function bound into js or lua,the parameter will be changed
---In js: var setBlendFunc(var src, var dst)
---In lua: local setBlendFunc(local src, local dst)
---\endcode
---@param blendFunc cc.BlendFunc
function LayerColor:setBlendFunc(blendFunc) end

return LayerColor