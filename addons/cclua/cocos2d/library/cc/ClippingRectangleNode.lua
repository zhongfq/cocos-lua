---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.ClippingRectangleNode

---Clipping Rectangle Node.
---\details A node that clipped with specified rectangle.
---The region of ClippingRectangleNode doesn't support any transform except scale.
---\js NA
---@class cc.ClippingRectangleNode : cc.Node
---@field clippingEnabled boolean Get whether the clipping is enabled or not. \return Whether the clipping is enabled or not. Default is true.
---@field clippingRegion cc.Rect Get the clipping rectangle. \return The clipping rectangle.
local ClippingRectangleNode = {}

---Create node with specified clipping region.
---@param clippingRegion cc.Rect # Specify the clipping rectangle.
---@return cc.ClippingRectangleNode # If the creation success, return a pointer of ClippingRectangleNode; otherwise return nil.
---
---Create a clipping rectangle node.
---\return If the creation success, return a pointer of ClippingRectangleNode; otherwise return nil.
---@overload fun(): cc.ClippingRectangleNode
function ClippingRectangleNode.create(clippingRegion) end

---Get the clipping rectangle.
---@return cc.Rect # The clipping rectangle.
function ClippingRectangleNode:getClippingRegion() end

---Get whether the clipping is enabled or not.
---@return boolean # Whether the clipping is enabled or not. Default is true.
function ClippingRectangleNode:isClippingEnabled() end

---Enable/Disable the clipping.
---@param enabled boolean # Pass true to enable clipping. Pass false to disable clipping.
function ClippingRectangleNode:setClippingEnabled(enabled) end

---Set the clipping rectangle.
---@param clippingRegion cc.Rect # Specify the clipping rectangle.
function ClippingRectangleNode:setClippingRegion(clippingRegion) end

return ClippingRectangleNode