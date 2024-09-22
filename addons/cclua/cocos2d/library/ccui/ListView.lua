---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.ListView

---ListView is a view group that displays a list of scrollable items.
---The list items are inserted to the list by using `addChild` or  `insertDefaultItem`.
---\warning The list item in ListView doesn't support cell reuse at the moment, if you have a large amount of data need to be displayed, use  `TableView` instead.
---ListView is a subclass of  `ScrollView`, so it shares many features of ScrollView.
---@class ccui.ListView : ccui.ScrollView
---@field bottomPadding number Get the bottom padding in ListView \return Bottom padding in float
---@field bottommostItemInCurrentView ccui.Widget Query the bottommost item in horizontal list \return An item instance.
---@field centerItemInCurrentView ccui.Widget Query the center item \return An item instance.
---@field curSelectedIndex integer Query current selected widget's index. <br><br> \return An index of a selected item.
---@field items any Return all items in a ListView. \returns A vector of widget pointers.
---@field itemsMargin number Query margin between each item in ListView. <br><br> \return A margin in float.
---@field leftPadding number Get the left padding in ListView \return Left padding in float
---@field leftmostItemInCurrentView ccui.Widget Query the leftmost item in horizontal list \return An item instance.
---@field magneticAllowedOutOfBoundary boolean Query whether the magnetic out of boundary is allowed.
---@field magneticType ccui.ListView.MagneticType Get magnetic type of ListView.
---@field rightPadding number Get the right padding in ListView \return Right padding in float
---@field rightmostItemInCurrentView ccui.Widget Query the rightmost item in horizontal list \return An item instance.
---@field scrollDuration number Get the time in seconds to scroll between items. \return The time in seconds to scroll between items \see setScrollDuration(float)
---@field topPadding number Get the top padding in ListView \return Top padding in float
---@field topmostItemInCurrentView ccui.Widget Query the topmost item in horizontal list \return An item instance.
local ListView = {}

---Add an event click callback to ListView, then one item of Listview is clicked, the callback will be called.
---@param callback ccui.ListView.ccListViewCallback # A callback function with type of `ccListViewCallback`.
---
---Add callback function which will be called  when scrollview event triggered.
---\param callback A callback function with type of `ccScrollViewCallback`.
---@overload fun(self: ccui.ListView, callback: ccui.ScrollView.ccScrollViewCallback)
function ListView:addEventListener(callback) end

---Create an empty ListView.
---@return ccui.ListView # A ListView instance.
function ListView.create() end

---@return cc.Ref
function ListView.createInstance() end

function ListView:doLayout() end

---Get the bottom padding in ListView
---@return number # Bottom padding in float
function ListView:getBottomPadding() end

---Query the bottommost item in horizontal list
---@return ccui.Widget # An item instance.
function ListView:getBottommostItemInCurrentView() end

---Query the center item
---@return ccui.Widget # An item instance.
function ListView:getCenterItemInCurrentView() end

---Query the closest item to a specific position in inner container.
---
---@param targetPosition cc.Vec2 # Specifies the target position in inner container's coordinates.
---@param itemAnchorPoint cc.Vec2 # Specifies an anchor point of each item for position to calculate distance.
---@return ccui.Widget # An item instance if list view is not empty. Otherwise, returns null.
function ListView:getClosestItemToPosition(targetPosition, itemAnchorPoint) end

---Query the closest item to a specific position in current view.
---For instance, to find the item in the center of view, call 'getClosestItemToPositionInCurrentView(Vec2::ANCHOR_MIDDLE, Vec2::ANCHOR_MIDDLE)'.
---
---@param positionRatioInView cc.Vec2 # Specifies the target position with ratio in list view's content size.
---@param itemAnchorPoint cc.Vec2 # Specifies an anchor point of each item for position to calculate distance.
---@return ccui.Widget # An item instance if list view is not empty. Otherwise, returns null.
function ListView:getClosestItemToPositionInCurrentView(positionRatioInView, itemAnchorPoint) end

---Query current selected widget's index.
---
---
---@return integer # An index of a selected item.
function ListView:getCurSelectedIndex() end

---Return the index of specified widget.
---
---@param item ccui.Widget # A widget pointer.
---@return integer # The index of a given widget in ListView.
function ListView:getIndex(item) end

---Return an item at a given index.
---
---@param index integer # A given index in ssize_t.
---@return ccui.Widget # A widget instance.
function ListView:getItem(index) end

---Return all items in a ListView.
---@return any # s A vector of widget pointers.
function ListView:getItems() end

---Query margin between each item in ListView.
---
---
---@return number # A margin in float.
function ListView:getItemsMargin() end

---Get the left padding in ListView
---@return number # Left padding in float
function ListView:getLeftPadding() end

---Query the leftmost item in horizontal list
---@return ccui.Widget # An item instance.
function ListView:getLeftmostItemInCurrentView() end

---Query whether the magnetic out of boundary is allowed.
---@return boolean
function ListView:getMagneticAllowedOutOfBoundary() end

---Get magnetic type of ListView.
---@return ccui.ListView.MagneticType
function ListView:getMagneticType() end

---Get the right padding in ListView
---@return number # Right padding in float
function ListView:getRightPadding() end

---Query the rightmost item in horizontal list
---@return ccui.Widget # An item instance.
function ListView:getRightmostItemInCurrentView() end

---Get the time in seconds to scroll between items.
---@return number # The time in seconds to scroll between items
---\see setScrollDuration(float)
function ListView:getScrollDuration() end

---Get the top padding in ListView
---@return number # Top padding in float
function ListView:getTopPadding() end

---Query the topmost item in horizontal list
---@return ccui.Widget # An item instance.
function ListView:getTopmostItemInCurrentView() end

---Insert a custom widget into ListView at a given index.
---
---@param item ccui.Widget # A widget pointer to be inserted.
---@param index integer # A given index in ssize_t.
function ListView:insertCustomItem(item, index) end

---Insert a default item(create by cloning model) into listview at a give index.
---@param index integer # An index in ssize_t.
function ListView:insertDefaultItem(index) end

---Jump to specific item
---@param itemIndex integer # Specifies the item's index
---@param positionRatioInView cc.Vec2 # Specifies the position with ratio in list view's content size.
---@param itemAnchorPoint cc.Vec2 # Specifies an anchor point of each item for position to calculate distance.
function ListView:jumpToItem(itemIndex, positionRatioInView, itemAnchorPoint) end

---Default constructor
---\js ctor
---\lua new
---@return ccui.ListView
function ListView.new() end

---Insert a  custom item into the end of ListView.
---@param item ccui.Widget # An item in `Widget*`.
function ListView:pushBackCustomItem(item) end

---Insert a default item(create by a cloned model) at the end of the listview.
function ListView:pushBackDefaultItem() end

---Remove all items in current ListView.
function ListView:removeAllItems() end

---Remove an item at given index.
---
---@param index integer # A given index in ssize_t.
function ListView:removeItem(index) end

---Removes the last item of ListView.
function ListView:removeLastItem() end

---Scroll to specific item
---@param positionRatioInView cc.Vec2 # Specifies the position with ratio in list view's content size.
---@param itemAnchorPoint cc.Vec2 # Specifies an anchor point of each item for position to calculate distance.
---\param timeInSec Scroll time
---@param itemIndex integer
---@overload fun(self: ccui.ListView, itemIndex: integer, positionRatioInView: cc.Vec2, itemAnchorPoint: cc.Vec2, timeInSec: number)
function ListView:scrollToItem(itemIndex, positionRatioInView, itemAnchorPoint) end

---Change padding with bottom padding
---@param b number # Bottom padding in float
function ListView:setBottomPadding(b) end

---Set current selected widget's index and call TouchEventType::ENDED event.
---@param itemIndex integer # A index of a selected item.
function ListView:setCurSelectedIndex(itemIndex) end

---Set the gravity of ListView.
---\see `ListViewGravity`
---@param gravity ccui.ListView.Gravity
function ListView:setGravity(gravity) end

---Set an item model for listview.
---
---When calling `pushBackDefaultItem`, the model will be used as a blueprint and new model copy will be inserted into ListView.
---@param model ccui.Widget # Model in `Widget*`.
function ListView:setItemModel(model) end

---Set the margin between each item in ListView.
---
---@param margin number # A margin in float.
function ListView:setItemsMargin(margin) end

---Change padding with left padding
---@param l number # Left padding in float.
function ListView:setLeftPadding(l) end

---Set magnetic allowed out of boundary.
---@param magneticAllowedOutOfBoundary boolean
function ListView:setMagneticAllowedOutOfBoundary(magneticAllowedOutOfBoundary) end

---Set magnetic type of ListView.
---\see `MagneticType`
---@param magneticType ccui.ListView.MagneticType
function ListView:setMagneticType(magneticType) end

---Change padding with left, top, right, and bottom padding.
---@param l number # Left padding in float.
---@param t number # Top margin in float.
---@param r number # Right margin in float.
---@param b number # Bottom margin in float.
function ListView:setPadding(l, t, r, b) end

---Change padding with right padding
---@param r number # Right padding in float
function ListView:setRightPadding(r) end

---Set the time in seconds to scroll between items.
---Subsequent calls of function 'scrollToItem', will take 'time' seconds for scrolling.
---@param time number # The seconds needed to scroll between two items. 'time' must be >= 0
---\see scrollToItem(ssize_t, const Vec2&, const Vec2&)
function ListView:setScrollDuration(time) end

---Change padding with top padding
---@param t number # Top padding in float
function ListView:setTopPadding(t) end

return ListView