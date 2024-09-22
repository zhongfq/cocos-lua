---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.LayoutComponent

---A component class used for layout.
---The LayoutComponent holds all the data for layouting.
---@class ccui.LayoutComponent : cc.Component
---@field anchorPosition cc.Vec2 Query the anchor position. \return Anchor position to it's parent
---@field bottomMargin number Query the bottom margin of owner relative to its parent. \return Bottom margin in float.
---@field horizontalEdge ccui.LayoutComponent.HorizontalEdge Query element horizontal dock type. \return Horizontal dock type.
---@field leftMargin number Query left margin of owner relative to its parent. \return Left margin in float.
---@field percentContentSize cc.Vec2 Query the percent content size value. \return Percent (x,y) in Vec2.
---@field percentHeight number Query percent height of owner.          \return Percent height in float.
---@field percentHeightEnabled boolean Query whether percent height is enabled or not. \return True if percent height is enabled, false otherwise.
---@field percentWidth number Query percent width of owner. \return percent width in float.
---@field percentWidthEnabled boolean Query whether percent width is enabled or not. \return True if percent width is enabled, false, otherwise.
---@field position cc.Vec2 Query the owner's position. \return The owner's position.
---@field positionPercentX number Query the position percent X value. \return Position percent X value in float.
---@field positionPercentXEnabled boolean Whether position percentX is enabled or not.  \return True if position percentX is enable, false otherwise.
---@field positionPercentY number Query the position percentY Y value. \return Position percent Y value in float.
---@field positionPercentYEnabled boolean Whether position percentY is enabled or not. \see `setPositionPercentYEnabled` \return True if position percentY is enabled, false otherwise.
---@field rightMargin number Query the right margin of owner relative to its parent. \return Right margin in float.
---@field size cc.Size Query owner's content size. \return Owner's content size.
---@field sizeHeight number Query size height of owner. \return Size height in float.
---@field sizeWidth number Query content size width of owner. \return Content size width in float.
---@field stretchHeightEnabled boolean Query whether stretch height is enabled or not. \return True if stretch height is enabled, false otherwise.
---@field stretchWidthEnabled boolean Query whether stretch width is enabled or not. \return True if stretch width is enabled, false otherwise.
---@field topMargin number Query the top margin of owner relative to its parent. \return Top margin in float.
---@field usingPercentContentSize boolean Query whether use percent content size or not. \return True if using percent content size, false otherwise.
---@field verticalEdge ccui.LayoutComponent.VerticalEdge Query element vertical dock type. \return Vertical dock type.
local LayoutComponent = {}

---Bind a LayoutComponent to a specified node.
---If the node has already binded a LayoutComponent named __LAYOUT_COMPONENT_NAME, just return the LayoutComponent.
---Otherwise, create a new LayoutComponent and bind the LayoutComponent to the node.
---@param node cc.Node # A Node* instance pointer.
---@return ccui.LayoutComponent # The binded LayoutComponent instance pointer.
function LayoutComponent.bindLayoutComponent(node) end

---Create a LayoutComponent instance with default settings.
---@return ccui.LayoutComponent
function LayoutComponent.create() end

---Query the anchor position.
---@return cc.Vec2 # Anchor position to it's parent
function LayoutComponent:getAnchorPosition() end

---Query the bottom margin of owner relative to its parent.
---@return number # Bottom margin in float.
function LayoutComponent:getBottomMargin() end

---Query element horizontal dock type.
---@return ccui.LayoutComponent.HorizontalEdge # Horizontal dock type.
function LayoutComponent:getHorizontalEdge() end

---Query left margin of owner relative to its parent.
---@return number # Left margin in float.
function LayoutComponent:getLeftMargin() end

---Query the percent content size value.
---@return cc.Vec2 # Percent (x,y) in Vec2.
function LayoutComponent:getPercentContentSize() end

---Query percent height of owner.         
---@return number # Percent height in float.
function LayoutComponent:getPercentHeight() end

---Query percent width of owner.
---@return number # percent width in float.
function LayoutComponent:getPercentWidth() end

---Query the owner's position.
---@return cc.Vec2 # The owner's position.
function LayoutComponent:getPosition() end

---Query the position percent X value.
---@return number # Position percent X value in float.
function LayoutComponent:getPositionPercentX() end

---Query the position percentY Y value.
---@return number # Position percent Y value in float.
function LayoutComponent:getPositionPercentY() end

---Query the right margin of owner relative to its parent.
---@return number # Right margin in float.
function LayoutComponent:getRightMargin() end

---Query owner's content size.
---@return cc.Size # Owner's content size.
function LayoutComponent:getSize() end

---Query size height of owner.
---@return number # Size height in float.
function LayoutComponent:getSizeHeight() end

---Query content size width of owner.
---@return number # Content size width in float.
function LayoutComponent:getSizeWidth() end

---Query the top margin of owner relative to its parent.
---@return number # Top margin in float.
function LayoutComponent:getTopMargin() end

---Query whether use percent content size or not.
---@return boolean # True if using percent content size, false otherwise.
function LayoutComponent:getUsingPercentContentSize() end

---Query element vertical dock type.
---@return ccui.LayoutComponent.VerticalEdge # Vertical dock type.
function LayoutComponent:getVerticalEdge() end

---Query whether percent height is enabled or not.
---@return boolean # True if percent height is enabled, false otherwise.
function LayoutComponent:isPercentHeightEnabled() end

---Query whether percent width is enabled or not.
---@return boolean # True if percent width is enabled, false, otherwise.
function LayoutComponent:isPercentWidthEnabled() end

---Whether position percentX is enabled or not. 
---@return boolean # True if position percentX is enable, false otherwise.
function LayoutComponent:isPositionPercentXEnabled() end

---Whether position percentY is enabled or not.
---\see `setPositionPercentYEnabled`
---@return boolean # True if position percentY is enabled, false otherwise.
function LayoutComponent:isPositionPercentYEnabled() end

---Query whether stretch height is enabled or not.
---@return boolean # True if stretch height is enabled, false otherwise.
function LayoutComponent:isStretchHeightEnabled() end

---Query whether stretch width is enabled or not.
---@return boolean # True if stretch width is enabled, false otherwise.
function LayoutComponent:isStretchWidthEnabled() end

---Default constructor
---
---\lua new
---@return ccui.LayoutComponent
function LayoutComponent.new() end

---Refresh layout of the owner.
function LayoutComponent:refreshLayout() end

---Toggle active enabled of LayoutComponent's owner.
---@param enable boolean # True if active layout component, false otherwise.
function LayoutComponent:setActiveEnabled(enable) end

---Change the anchor position to it's parent.
---@param point cc.Vec2 # A value in (x,y) format.
function LayoutComponent:setAnchorPosition(point) end

---Change the bottom margin of owner relative to its parent.
---@param margin number # in float.
function LayoutComponent:setBottomMargin(margin) end

---Change element's horizontal dock type.
---@param hEage ccui.LayoutComponent.HorizontalEdge # Horizontal dock type @see `HorizontalEdge`
function LayoutComponent:setHorizontalEdge(hEage) end

---Change left margin of owner relative to its parent.
---@param margin number # Margin in float.
function LayoutComponent:setLeftMargin(margin) end

---Set percent content size.
---The value should be [0-1], 0 means the child's content size will be 0
---and 1 means the child's content size is the same as its parents.
---@param percent cc.Vec2 # The percent (x,y) of the node in [0-1] scope.
function LayoutComponent:setPercentContentSize(percent) end

---Change percent height value of owner.
---@param percentHeight number # Percent height in float.
function LayoutComponent:setPercentHeight(percentHeight) end

---Toggle enable percent height.
---@param isUsed boolean # True if percent height is enabled, false otherwise.
function LayoutComponent:setPercentHeightEnabled(isUsed) end

---Toggle enable percent only.
---@param enable boolean # True if percent only is enabled, false otherwise.
function LayoutComponent:setPercentOnlyEnabled(enable) end

---Change percent width of owner.
---@param percentWidth number # Percent Width in float.
function LayoutComponent:setPercentWidth(percentWidth) end

---Toggle enable percent width.
---@param isUsed boolean # True if percent width is enabled, false otherwise.
function LayoutComponent:setPercentWidthEnabled(isUsed) end

---Change the position of component owner.
---@param position cc.Vec2 # A position in (x,y)
function LayoutComponent:setPosition(position) end

---Change position percent X value.
---@param percentMargin number # Margin in float.
function LayoutComponent:setPositionPercentX(percentMargin) end

---Toggle position percentX enabled.
---@param isUsed boolean # True if enable position percentX, false otherwise.
function LayoutComponent:setPositionPercentXEnabled(isUsed) end

---Change position percentY value.
---@param percentMargin number # Margin in float.
function LayoutComponent:setPositionPercentY(percentMargin) end

---Toggle position percentY enabled.
---@param isUsed boolean # True if position percentY is enabled, false otherwise.
function LayoutComponent:setPositionPercentYEnabled(isUsed) end

---Change right margin of owner relative to its parent.
---@param margin number # Margin in float.
function LayoutComponent:setRightMargin(margin) end

---Change the content size of owner.
---@param size cc.Size # Content size in @see `Size`.
function LayoutComponent:setSize(size) end

---Change size height of owner.
---@param height number # Size height in float.
function LayoutComponent:setSizeHeight(height) end

---Change content size width of owner.
---@param width number # Content size width in float.
function LayoutComponent:setSizeWidth(width) end

---Toggle enable stretch height.
---@param isUsed boolean # True if stretch height is enabled, false otherwise.
function LayoutComponent:setStretchHeightEnabled(isUsed) end

---Toggle enable stretch width.
---@param isUsed boolean # True if enable stretch width, false otherwise.
function LayoutComponent:setStretchWidthEnabled(isUsed) end

---Change the top margin of owner relative to its parent.
---@param margin number # Margin in float.
function LayoutComponent:setTopMargin(margin) end

---Percent content size is used to adapt node's content size based on parent's content size.
---If set to true then node's content size will be changed based on the value set by @see setPercentContentSize
---@param isUsed boolean # True to enable percent content size, false otherwise.
function LayoutComponent:setUsingPercentContentSize(isUsed) end

---Change element's vertical dock type.
---@param vEage ccui.LayoutComponent.VerticalEdge # Vertical dock type @see `VerticalEdge`.
function LayoutComponent:setVerticalEdge(vEage) end

return LayoutComponent