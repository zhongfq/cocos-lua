---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.ScrollViewBar

---Scroll bar being attached to ScrollView layout container.
---@class ccui.ScrollViewBar : cc.ProtectedNode
---@field autoHideEnabled boolean Query scroll bar auto hide state <br><br>\return True if scroll bar auto hide is enabled, false otherwise.
---@field autoHideTime number Get the scroll bar's auto hide time <br><br>\return the scroll bar's auto hide time
---@field positionFromCorner cc.Vec2 Get the scroll bar position from the left-bottom corner (horizontal) or right-top corner (vertical). <br><br>\return positionFromCorner
---@field width number Get the scroll bar's width <br><br>\return the scroll bar's width
local ScrollViewBar = {}

---Create a scroll bar with its parent scroll view and direction.
---@return ccui.ScrollViewBar # A scroll bar instance.
---@param parent ccui.ScrollView
---@param direction ccui.ScrollView.Direction
function ScrollViewBar.create(parent, direction) end

---Get the scroll bar's auto hide time
---
---@return number # the scroll bar's auto hide time
function ScrollViewBar:getAutoHideTime() end

---Get the scroll bar position from the left-bottom corner (horizontal) or right-top corner (vertical).
---
---@return cc.Vec2 # positionFromCorner
function ScrollViewBar:getPositionFromCorner() end

---Get the scroll bar's width
---
---@return number # the scroll bar's width
function ScrollViewBar:getWidth() end

---Query scroll bar auto hide state
---
---@return boolean # True if scroll bar auto hide is enabled, false otherwise.
function ScrollViewBar:isAutoHideEnabled() end

---Default constructor
---\js ctor
---\lua new
---@param parent ccui.ScrollView
---@param direction ccui.ScrollView.Direction
---@return ccui.ScrollViewBar
function ScrollViewBar.new(parent, direction) end

---This is called by parent ScrollView when the parent is scrolled. Don't call this directly.
---
---\param amount how much the inner container of ScrollView is out of boundary
---@param outOfBoundary cc.Vec2
function ScrollViewBar:onScrolled(outOfBoundary) end

---This is called by parent ScrollView when a touch is began. Don't call this directly.
function ScrollViewBar:onTouchBegan() end

---This is called by parent ScrollView when a touch is ended. Don't call this directly.
function ScrollViewBar:onTouchEnded() end

---Set scroll bar auto hide state
---
---\param scroll bar auto hide state
---@param autoHideEnabled boolean
function ScrollViewBar:setAutoHideEnabled(autoHideEnabled) end

---Set scroll bar auto hide time
---
---\param scroll bar auto hide time
---@param autoHideTime number
function ScrollViewBar:setAutoHideTime(autoHideTime) end

---Set the scroll bar position from the left-bottom corner (horizontal) or right-top corner (vertical).
---
---@param positionFromCorner cc.Vec2 # The position from the left-bottom corner (horizontal) or right-top corner (vertical).
function ScrollViewBar:setPositionFromCorner(positionFromCorner) end

---Set the scroll bar's width
---
---@param width number # The scroll bar's width
function ScrollViewBar:setWidth(width) end

return ScrollViewBar