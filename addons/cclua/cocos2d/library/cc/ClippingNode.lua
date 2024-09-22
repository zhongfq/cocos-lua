---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.ClippingNode

---\addtogroup _2d
---\{
---
---ClippingNode is a subclass of Node.
---It draws its content (children) clipped using a stencil.
---The stencil is an other Node that will not be drawn.
---The clipping is done using the alpha part of the stencil (adjusted with an alphaThreshold).
---@class cc.ClippingNode : cc.Node
---@field alphaThreshold number The alpha threshold. The content is drawn only where the stencil have pixel with alpha greater than the alphaThreshold. Should be a float between 0 and 1. This default to 1 (so alpha test is disabled). <br><br>\return The alpha threshold value,Should be a float between 0 and 1.
---@field inverted boolean Inverted. If this is set to true, the stencil is inverted, so the content is drawn where the stencil is NOT drawn. This default to false. <br><br>\return If the clippingNode is Inverted, it will be return true.
---@field stencil cc.Node The Node to use as a stencil to do the clipping. The stencil node will be retained. This default to nil. <br><br>\return The stencil node.
local ClippingNode = {}

---Creates and initializes a clipping node without a stencil.
---
---@return cc.ClippingNode # An autorelease ClippingNode.
---
---Creates and initializes a clipping node with an other node as its stencil.
---The stencil node will be retained.
---\param stencil The stencil node.
---@overload fun(stencil: cc.Node): cc.ClippingNode
function ClippingNode.create() end

---The alpha threshold.
---The content is drawn only where the stencil have pixel with alpha greater than the alphaThreshold.
---Should be a float between 0 and 1.
---This default to 1 (so alpha test is disabled).
---
---@return number # The alpha threshold value,Should be a float between 0 and 1.
function ClippingNode:getAlphaThreshold() end

---The Node to use as a stencil to do the clipping.
---The stencil node will be retained.
---This default to nil.
---
---@return cc.Node # The stencil node.
function ClippingNode:getStencil() end

---If stencil has no children it will not be drawn.
---If you have custom stencil-based node with stencil drawing mechanics other then children-based,
---then this method should return true every time you wish stencil to be visited.
---By default returns true if has any children attached.
---
---@return boolean # If you have custom stencil-based node with stencil drawing mechanics other then children-based,
---then this method should return true every time you wish stencil to be visited.
---By default returns true if has any children attached.
---\js NA
function ClippingNode:hasContent() end

---Initializes a clipping node without a stencil.
---@return boolean
---
---Initializes a clipping node with an other node as its stencil.
---The stencil node will be retained, and its parent will be set to this clipping node.
---@overload fun(self: cc.ClippingNode, stencil: cc.Node): boolean
function ClippingNode:init() end

---Inverted. If this is set to true,
---the stencil is inverted, so the content is drawn where the stencil is NOT drawn.
---This default to false.
---
---@return boolean # If the clippingNode is Inverted, it will be return true.
function ClippingNode:isInverted() end

---@return cc.ClippingNode
function ClippingNode.new() end

---Set the alpha threshold. 
---
---@param alphaThreshold number # The alpha threshold.
function ClippingNode:setAlphaThreshold(alphaThreshold) end

---Set the ClippingNode whether or not invert.
---
---@param inverted boolean # A bool Type,to set the ClippingNode whether or not invert.
function ClippingNode:setInverted(inverted) end

---Set the Node to use as a stencil to do the clipping.
---
---@param stencil cc.Node # The Node to use as a stencil to do the clipping.
function ClippingNode:setStencil(stencil) end

return ClippingNode