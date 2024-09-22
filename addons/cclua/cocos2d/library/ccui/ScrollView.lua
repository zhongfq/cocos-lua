---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.ScrollView

---Layout container for a view hierarchy that can be scrolled by the user, allowing it to be larger than the physical display.
---It holds a inner `Layout` container for storing child items horizontally or vertically.
---@class ccui.ScrollView : ccui.Layout
---@field autoScrolling boolean   * @return Whether the ScrollView is currently scrolling because of a bounceback or inertia slowdown.
---@field bounceEnabled boolean Query bounce state. <br><br>\return True if bounce is enabled, false otherwise.
---@field direction ccui.ScrollView.Direction Query scroll direction of scrollview. <br><br>\see `Direction`      Direction::VERTICAL means vertical scroll, Direction::HORIZONTAL means horizontal scroll <br><br>\return Scrollview scroll direction.
---@field inertiaScrollEnabled boolean Query inertia scroll state. <br><br>\return True if inertia is enabled, false otherwise.
---@field innerContainer ccui.Layout Get inner container of scrollview. <br><br>Inner container is a child of scrollview. <br><br>\return Inner container pointer.
---@field innerContainerPosition cc.Vec2 Get inner container position <br><br>\return The inner container position.
---@field innerContainerSize cc.Size Get inner container size of scrollview. <br><br>Inner container size must be larger than or equal scrollview's size. <br><br>\return The inner container size.
---@field scrollBarAutoHideEnabled boolean Query scroll bar auto hide state <br><br>\return True if scroll bar auto hide is enabled, false otherwise.
---@field scrollBarAutoHideTime number Get the scroll bar's auto hide time <br><br>\return the scroll bar's auto hide time
---@field scrollBarColor any Get the scroll bar's color <br><br>\return the scroll bar's color
---@field scrollBarEnabled boolean Query scroll bar state. <br><br>\return True if scroll bar is enabled, false otherwise.
---@field scrollBarOpacity integer Get the scroll bar's opacity <br><br>\return the scroll bar's opacity
---@field scrollBarPositionFromCornerForHorizontal cc.Vec2 Get the horizontal scroll bar's position from right-top corner. <br><br>\return positionFromCorner
---@field scrollBarPositionFromCornerForVertical cc.Vec2 Get the vertical scroll bar's position from right-top corner. <br><br>\return positionFromCorner
---@field scrollBarWidth number Get the scroll bar's width <br><br>\return the scroll bar's width
---@field scrolledPercentBothDirection cc.Vec2   * @return How far the scroll view is scrolled in both axes, combined as a Vec2
---@field scrolledPercentHorizontal number   * @return How far the scroll view is scrolled in the horizontal axis
---@field scrolledPercentVertical number   * @return How far the scroll view is scrolled in the vertical axis
---@field scrolling boolean   * @return Whether the user is currently dragging the ScrollView to scroll it
---@field touchTotalTimeThreshold number Get the touch total time threshold <br><br>\return the touch total time threshold
local ScrollView = {}

---Add callback function which will be called  when scrollview event triggered.
---@param callback ccui.ScrollView.ccScrollViewCallback # A callback function with type of `ccScrollViewCallback`.
function ScrollView:addEventListener(callback) end

---Create an empty ScrollView.
---@return ccui.ScrollView # A ScrollView instance.
function ScrollView.create() end

---@return cc.Ref
function ScrollView.createInstance() end

---Query scroll direction of scrollview.
---
---\see `Direction`      Direction::VERTICAL means vertical scroll, Direction::HORIZONTAL means horizontal scroll
---
---@return ccui.ScrollView.Direction # Scrollview scroll direction.
function ScrollView:getDirection() end

---Get inner container of scrollview.
---
---Inner container is a child of scrollview.
---
---@return ccui.Layout # Inner container pointer.
function ScrollView:getInnerContainer() end

---Get inner container position
---
---@return cc.Vec2 # The inner container position.
function ScrollView:getInnerContainerPosition() end

---Get inner container size of scrollview.
---
---Inner container size must be larger than or equal scrollview's size.
---
---@return cc.Size # The inner container size.
function ScrollView:getInnerContainerSize() end

---Get the scroll bar's auto hide time
---
---@return number # the scroll bar's auto hide time
function ScrollView:getScrollBarAutoHideTime() end

---Get the scroll bar's color
---
---@return any # the scroll bar's color
function ScrollView:getScrollBarColor() end

---Get the scroll bar's opacity
---
---@return integer # the scroll bar's opacity
function ScrollView:getScrollBarOpacity() end

---Get the horizontal scroll bar's position from right-top corner.
---
---@return cc.Vec2 # positionFromCorner
function ScrollView:getScrollBarPositionFromCornerForHorizontal() end

---Get the vertical scroll bar's position from right-top corner.
---
---@return cc.Vec2 # positionFromCorner
function ScrollView:getScrollBarPositionFromCornerForVertical() end

---Get the scroll bar's width
---
---@return number # the scroll bar's width
function ScrollView:getScrollBarWidth() end

---  * @return How far the scroll view is scrolled in both axes, combined as a Vec2
---@return cc.Vec2
function ScrollView:getScrolledPercentBothDirection() end

---  * @return How far the scroll view is scrolled in the horizontal axis
---@return number
function ScrollView:getScrolledPercentHorizontal() end

---  * @return How far the scroll view is scrolled in the vertical axis
---@return number
function ScrollView:getScrolledPercentVertical() end

---Get the touch total time threshold
---
---@return number # the touch total time threshold
function ScrollView:getTouchTotalTimeThreshold() end

---  * @return Whether the ScrollView is currently scrolling because of a bounceback or inertia slowdown.
---@return boolean
function ScrollView:isAutoScrolling() end

---Query bounce state.
---
---@return boolean # True if bounce is enabled, false otherwise.
function ScrollView:isBounceEnabled() end

---Query inertia scroll state.
---
---@return boolean # True if inertia is enabled, false otherwise.
function ScrollView:isInertiaScrollEnabled() end

---Query scroll bar auto hide state
---
---@return boolean # True if scroll bar auto hide is enabled, false otherwise.
function ScrollView:isScrollBarAutoHideEnabled() end

---Query scroll bar state.
---
---@return boolean # True if scroll bar is enabled, false otherwise.
function ScrollView:isScrollBarEnabled() end

---  * @return Whether the user is currently dragging the ScrollView to scroll it
---@return boolean
function ScrollView:isScrolling() end

---Move inner container to bottom boundary of scrollview.
function ScrollView:jumpToBottom() end

---Move inner container to bottom and left boundary of scrollview.
function ScrollView:jumpToBottomLeft() end

---Move inner container to bottom and right boundary of scrollview.
function ScrollView:jumpToBottomRight() end

---Move inner container to left boundary of scrollview.
function ScrollView:jumpToLeft() end

---Move inner container to both direction percent position of scrollview.
---@param percent cc.Vec2 # A value between 0 and 100.
function ScrollView:jumpToPercentBothDirection(percent) end

---Move inner container to horizontal percent position of scrollview.
---@param percent number # A value between 0 and 100.
function ScrollView:jumpToPercentHorizontal(percent) end

---Move inner container to vertical percent position of scrollview.
---@param percent number # A value between 0 and 100.
function ScrollView:jumpToPercentVertical(percent) end

---Move inner container to right boundary of scrollview.
function ScrollView:jumpToRight() end

---Move inner container to top boundary of scrollview.
function ScrollView:jumpToTop() end

---Move inner container to top and left boundary of scrollview.
function ScrollView:jumpToTopLeft() end

---Move inner container to top and right boundary of scrollview.
function ScrollView:jumpToTopRight() end

---Default constructor
---\js ctor
---\lua new
---@return ccui.ScrollView
function ScrollView.new() end

---Scroll inner container to bottom boundary of scrollview.
---@param timeInSec number # Time in seconds.
---@param attenuated boolean # Whether scroll speed attenuate or not.
function ScrollView:scrollToBottom(timeInSec, attenuated) end

---Scroll inner container to bottom and left boundary of scrollview.
---@param timeInSec number # Time in seconds.
---@param attenuated boolean # Whether scroll speed attenuate or not.
function ScrollView:scrollToBottomLeft(timeInSec, attenuated) end

---Scroll inner container to bottom and right boundary of scrollview.
---@param timeInSec number # Time in seconds
---@param attenuated boolean # Whether scroll speed attenuate or not.
function ScrollView:scrollToBottomRight(timeInSec, attenuated) end

---Scroll inner container to left boundary of scrollview.
---@param timeInSec number # Time in seconds.
---@param attenuated boolean # Whether scroll speed attenuate or not.
function ScrollView:scrollToLeft(timeInSec, attenuated) end

---Scroll inner container to both direction percent position of scrollview.
---@param percent cc.Vec2 # A value between 0 and 100.
---@param timeInSec number # Time in seconds.
---@param attenuated boolean # Whether scroll speed attenuate or not.
function ScrollView:scrollToPercentBothDirection(percent, timeInSec, attenuated) end

---Scroll inner container to horizontal percent position of scrollview.
---@param percent number # A value between 0 and 100.
---@param timeInSec number # Time in seconds.
---@param attenuated boolean # Whether scroll speed attenuate or not.
function ScrollView:scrollToPercentHorizontal(percent, timeInSec, attenuated) end

---Scroll inner container to vertical percent position of scrollview.
---@param percent number # A value between 0 and 100.
---@param timeInSec number # Time in seconds.
---@param attenuated boolean # Whether scroll speed attenuate or not.
function ScrollView:scrollToPercentVertical(percent, timeInSec, attenuated) end

---Scroll inner container to right boundary of scrollview.
---@param timeInSec number # Time in seconds.
---@param attenuated boolean # Whether scroll speed attenuate or not.
function ScrollView:scrollToRight(timeInSec, attenuated) end

---Scroll inner container to top boundary of scrollview.
---@param timeInSec number # Time in seconds.
---@param attenuated boolean # Whether scroll speed attenuate or not.
function ScrollView:scrollToTop(timeInSec, attenuated) end

---Scroll inner container to top and left boundary of scrollview.
---@param timeInSec number # Time in seconds.
---@param attenuated boolean # Whether scroll speed attenuate or not.
function ScrollView:scrollToTopLeft(timeInSec, attenuated) end

---Scroll inner container to top and right boundary of scrollview.
---@param timeInSec number # Time in seconds.
---@param attenuated boolean # Whether scroll speed attenuate or not.
function ScrollView:scrollToTopRight(timeInSec, attenuated) end

---Toggle bounce enabled when scroll to the edge.
---
---@param enabled boolean # True if enable bounce, false otherwise.
function ScrollView:setBounceEnabled(enabled) end

---Changes scroll direction of scrollview.
---
---\see `Direction`
---@param dir ccui.ScrollView.Direction # Scroll direction enum.
function ScrollView:setDirection(dir) end

---Toggle whether enable scroll inertia while scrolling.
---
---@param enabled boolean # True if enable inertia, false otherwise.
function ScrollView:setInertiaScrollEnabled(enabled) end

---Set inner container position
---
---@param pos cc.Vec2 # Inner container position.
function ScrollView:setInnerContainerPosition(pos) end

---Change inner container size of scrollview.
---
---Inner container size must be larger than or equal scrollview's size.
---
---@param size cc.Size # Inner container size.
function ScrollView:setInnerContainerSize(size) end

---Set scroll bar auto hide state
---
---\param scroll bar auto hide state
---@param autoHideEnabled boolean
function ScrollView:setScrollBarAutoHideEnabled(autoHideEnabled) end

---Set scroll bar auto hide time
---
---\param scroll bar auto hide time
---@param autoHideTime number
function ScrollView:setScrollBarAutoHideTime(autoHideTime) end

---Set the scroll bar's color
---
---\param the scroll bar's color
---@param color any
function ScrollView:setScrollBarColor(color) end

---Toggle scroll bar enabled.
---
---@param enabled boolean # True if enable scroll bar, false otherwise.
function ScrollView:setScrollBarEnabled(enabled) end

---Set the scroll bar's opacity
---
---\param the scroll bar's opacity
---@param opacity integer
function ScrollView:setScrollBarOpacity(opacity) end

---Set the scroll bar positions from the left-bottom corner (horizontal) and right-top corner (vertical).
---
---@param positionFromCorner cc.Vec2 # The position from the left-bottom corner (horizontal) and right-top corner (vertical).
function ScrollView:setScrollBarPositionFromCorner(positionFromCorner) end

---Set the horizontal scroll bar position from left-bottom corner.
---
---@param positionFromCorner cc.Vec2 # The position from left-bottom corner
function ScrollView:setScrollBarPositionFromCornerForHorizontal(positionFromCorner) end

---Set the vertical scroll bar position from right-top corner.
---
---@param positionFromCorner cc.Vec2 # The position from right-top corner
function ScrollView:setScrollBarPositionFromCornerForVertical(positionFromCorner) end

---Set the scroll bar's width
---
---@param width number # The scroll bar's width
function ScrollView:setScrollBarWidth(width) end

---Set the touch total time threshold
---
---\param the touch total time threshold
---@param touchTotalTimeThreshold number
function ScrollView:setTouchTotalTimeThreshold(touchTotalTimeThreshold) end

---Immediately stops inner container scroll initiated by any of the "scrollTo*" member functions
function ScrollView:stopAutoScroll() end

---Immediately stops inner container scroll if any.
function ScrollView:stopOverallScroll() end

---Immediately stops inner container scroll (auto scrolling is not affected).
function ScrollView:stopScroll() end

return ScrollView