---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.TabControl

---TabControl, use header button switch container
---@class ccui.TabControl : ccui.Widget
---@field headerDockPlace ccui.TabControl.Dock 
---@field headerHeight integer get tab header's height \return header's height
---@field headerSelectedZoom number get the delta zoom of selected tab \return zoom, the delta zoom
---@field headerWidth number get tab header's width \return header's width
---@field selectedTabIndex integer get current selected tab's index \return the current selected tab index
---@field tabCount integer get the count of tabs in this TabControl \return the count of tabs
local TabControl = {}

---@return ccui.TabControl
function TabControl.create() end

---@return ccui.TabControl.Dock
function TabControl:getHeaderDockPlace() end

---get tab header's height
---@return integer # header's height
function TabControl:getHeaderHeight() end

---get the delta zoom of selected tab
---@return number # zoom, the delta zoom
function TabControl:getHeaderSelectedZoom() end

---get tab header's width
---@return number # header's width
function TabControl:getHeaderWidth() end

---get current selected tab's index
---@return integer # the current selected tab index
function TabControl:getSelectedTabIndex() end

---get Container
---@param index integer # The index of tab
---@return ccui.Layout
function TabControl:getTabContainer(index) end

---get the count of tabs in this TabControl
---@return integer # the count of tabs
function TabControl:getTabCount() end

---get TabHeader
---@param index integer # The index of tab
---@return ccui.TabHeader
function TabControl:getTabHeader(index) end

---ignore the textures' size in header, scale them with _headerWidth and _headerHeight
---@param ignore boolean # is `true`, the header's texture scale with _headerWidth and _headerHeight
---ignore is `false`, use the texture's size, do not scale them
function TabControl:ignoreHeadersTextureSize(ignore) end

---get the index of tabCell in TabView, return -1 if not exists in.
---@return integer # the index of tabCell in TabView, `-1` means not exists in.
---@param tabCell ccui.TabHeader
function TabControl:indexOfTabHeader(tabCell) end

---insert tab, and init the position of header and container
---@param index integer # The index tab should be
---@param header ccui.TabHeader # The header Button, will be a protected child in TabControl
---@param container ccui.Layout # The container, will be a protected child in TabControl
function TabControl:insertTab(index, header, container) end

---get whether ignore the textures' size in header, scale them with _headerWidth and _headerHeight
---@return boolean # whether ignore the textures' size in header
function TabControl:isIgnoreHeadersTextureSize() end

---remove the tab from this TabControl
---@param index integer # The index of tab
function TabControl:removeTab(index) end

---the header dock place of header in TabControl
---@param dockPlace ccui.TabControl.Dock # The strip place
function TabControl:setHeaderDockPlace(dockPlace) end

---set header height, affect all tab
---@param headerHeight number # each tab header's height
function TabControl:setHeaderHeight(headerHeight) end

---set the delta zoom of selected tab
---@param zoom number # The delta zoom
function TabControl:setHeaderSelectedZoom(zoom) end

---set header width, affect all tab
---@param headerWidth number # each tab header's width
function TabControl:setHeaderWidth(headerWidth) end

---set tab selected, switch the current selected tab and visible container
---@param index integer # The index of tab
---
---set tab selected, switch the current selected tab and visible container
---\param tabHeader The tab instance
---@overload fun(self: ccui.TabControl, tabHeader: ccui.TabHeader)
function TabControl:setSelectTab(index) end

---Add a callback function which would be called when selected tab changed
---@param callback ccui.TabControl.ccTabControlCallback # A std::function with type @see `ccTabControlCallback`
function TabControl:setTabChangedEventListener(callback) end

return TabControl