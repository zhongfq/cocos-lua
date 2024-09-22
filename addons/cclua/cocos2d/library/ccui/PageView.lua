---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.PageView

---Layout manager that allows the user to flip left & right and up & down through pages of data.
---@class ccui.PageView : ccui.ListView
---@field currentPageIndex integer Gets current displayed page index. \return current page index.
---@field indicatorEnabled boolean Query page indicator state. <br><br>\return True if page indicator is enabled, false otherwise.
---@field indicatorIndexNodesColor any Get the color of page indicator's index nodes. <br><br>\return color
---@field indicatorIndexNodesOpacity integer Get the opacity of page indicator's index nodes. <br><br>\return opacity
---@field indicatorIndexNodesScale number Get scale of page indicator's index nodes. <br><br>\return indexNodesScale
---@field indicatorPosition cc.Vec2 Get the page indicator's position. <br><br>\return positionAsAnchorPoint
---@field indicatorPositionAsAnchorPoint cc.Vec2 Get the page indicator's position as anchor point. <br><br>\return positionAsAnchorPoint
---@field indicatorSelectedIndexColor any Get the color of page indicator's selected index. <br><br>\return color
---@field indicatorSelectedIndexOpacity integer Get the opacity of page indicator's selected index. <br><br>\return opacity
---@field indicatorSpaceBetweenIndexNodes number Get the space between page indicator's index nodes. <br><br>\return spaceBetweenIndexNodes
local PageView = {}

---Add a page turn callback to PageView, then when one page is turning, the callback will be called.
---
---@param callback ccui.PageView.ccPageViewCallback # A page turning callback.
---
---Add callback function which will be called  when scrollview event triggered.
---\param callback A callback function with type of `ccScrollViewCallback`.
---@overload fun(self: ccui.PageView, callback: ccui.ScrollView.ccScrollViewCallback)
function PageView:addEventListener(callback) end

---Insert a page into the end of PageView.
---
---@param page ccui.Widget # Page to be inserted.
function PageView:addPage(page) end

---Create an empty PageView.
---@return ccui.PageView # A PageView instance.
function PageView.create() end

---@return cc.Ref
function PageView.createInstance() end

---Gets current displayed page index.
---@return integer # current page index.
function PageView:getCurrentPageIndex() end

---Query page indicator state.
---
---@return boolean # True if page indicator is enabled, false otherwise.
function PageView:getIndicatorEnabled() end

---Get the color of page indicator's index nodes.
---
---@return any # color
function PageView:getIndicatorIndexNodesColor() end

---Get the opacity of page indicator's index nodes.
---
---@return integer # opacity
function PageView:getIndicatorIndexNodesOpacity() end

---Get scale of page indicator's index nodes.
---
---@return number # indexNodesScale
function PageView:getIndicatorIndexNodesScale() end

---Get the page indicator's position.
---
---@return cc.Vec2 # positionAsAnchorPoint
function PageView:getIndicatorPosition() end

---Get the page indicator's position as anchor point.
---
---@return cc.Vec2 # positionAsAnchorPoint
function PageView:getIndicatorPositionAsAnchorPoint() end

---Get the color of page indicator's selected index.
---
---@return any # color
function PageView:getIndicatorSelectedIndexColor() end

---Get the opacity of page indicator's selected index.
---
---@return integer # opacity
function PageView:getIndicatorSelectedIndexOpacity() end

---Get the space between page indicator's index nodes.
---
---@return number # spaceBetweenIndexNodes
function PageView:getIndicatorSpaceBetweenIndexNodes() end

---Insert a page into PageView at a given index.
---
---@param page ccui.Widget # Page to be inserted.
---@param idx integer # A given index.
function PageView:insertPage(page, idx) end

---Default constructor
---\js ctor
---\lua new
---@return ccui.PageView
function PageView.new() end

---Remove all pages of the PageView.
function PageView:removeAllPages() end

---Remove a page of PageView.
---
---@param page ccui.Widget # Page to be removed.
function PageView:removePage(page) end

---Remove a page at a given index of PageView.
---
---@param index integer # A given index.
function PageView:removePageAtIndex(index) end

---Scroll to a page with a given index.
---
---@param itemIndex integer # A given index in the PageView. Index start from 0 to pageCount -1.
---
---Scroll to a item with a given index and with a given scroll time.
---
---\param idx   A given index in the PageView. Index start from 0 to pageCount -1.
---\param time  Scroll time must be >= 0. Otherwise last set scrolltime will be used.
---@overload fun(self: ccui.PageView, idx: integer, time: number)
function PageView:scrollToItem(itemIndex) end

---Scroll to a page with a given index.
---
---@param idx integer # A given index in the PageView. Index start from 0 to pageCount -1.
---
---Scroll to a page with a given index and with a given scroll time.
---
---\param idx   A given index in the PageView. Index start from 0 to pageCount -1.
---\param time  Scroll time must be >= 0. Otherwise last set scroll time will be used.
---@overload fun(self: ccui.PageView, idx: integer, time: number)
function PageView:scrollToPage(idx) end

---@param epsilon number
function PageView:setAutoScrollStopEpsilon(epsilon) end

---Jump to a page with a given index without scrolling.
---This is the different between scrollToPage.
---
---@param index integer # A given index in PageView. Index start from 0 to pageCount -1.
function PageView:setCurrentPageIndex(index) end

---Toggle page indicator enabled.
---
---@param enabled boolean # True if enable page indicator, false otherwise.
function PageView:setIndicatorEnabled(enabled) end

---Set color of page indicator's index nodes.
---
---@param color any # New indicator node color.
function PageView:setIndicatorIndexNodesColor(color) end

---Set opacity of page indicator's index nodes.
---
---@param opacity integer # New indicator node opacity.
function PageView:setIndicatorIndexNodesOpacity(opacity) end

---Set scale of page indicator's index nodes.
---
---@param indexNodesScale number # Scale of index nodes.
function PageView:setIndicatorIndexNodesScale(indexNodesScale) end

---sets texture for index nodes.
---
---\param fileName   File name of texture.
---\param resType    @see TextureResType .
---@param texName string
---@param texType ccui.Widget.TextureResType
---@overload fun(self: ccui.PageView, texName: string)
function PageView:setIndicatorIndexNodesTexture(texName, texType) end

---Set the page indicator's position in page view.
---
---@param position cc.Vec2 # The position in page view
function PageView:setIndicatorPosition(position) end

---Set the page indicator's position using anchor point.
---
---@param positionAsAnchorPoint cc.Vec2 # The position as anchor point.
function PageView:setIndicatorPositionAsAnchorPoint(positionAsAnchorPoint) end

---Set color of page indicator's selected index.
---
---@param color any # New color for selected (current) index.
function PageView:setIndicatorSelectedIndexColor(color) end

---Set opacity of page indicator's selected index.
---
---\param color New opacity for selected (current) index.
---@param opacity integer
function PageView:setIndicatorSelectedIndexOpacity(opacity) end

---Set space between page indicator's index nodes.
---
---@param spaceBetweenIndexNodes number # Space between nodes in pixel.
function PageView:setIndicatorSpaceBetweenIndexNodes(spaceBetweenIndexNodes) end

return PageView