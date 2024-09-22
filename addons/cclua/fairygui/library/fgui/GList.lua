---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.GList

---
---@class fgui.GList : fgui.GComponent
---@field align cc.TextHAlignment 
---@field autoResizeItem boolean 
---@field columnCount integer 
---@field columnGap integer 
---@field defaultItem string 
---@field layout fgui.ListLayoutType 
---@field lineCount integer 
---@field lineGap integer 
---@field numItems integer 
---@field selectedIndex integer 
---@field selectionController fgui.GController 
---@field selectionMode fgui.ListSelectionMode 
---@field verticalAlign cc.TextVAlignment 
---@field virtual boolean 
---@field itemRenderer fgui.GList.ListItemRenderer
---@field itemProvider fgui.GList.ListItemProvider
---@field scrollItemToViewOnClick boolean
---@field foldInvisibleItems boolean
local GList = {}

---@return fgui.GObject
---@overload fun(self: fgui.GList, url: string): fgui.GObject
function GList:addItemFromPool() end

---@param index integer
---@param scrollItToView boolean
function GList:addSelection(index, scrollItToView) end

---@param index integer
---@return integer
function GList:childIndexToItemIndex(index) end

function GList:clearSelection() end

---@return fgui.GList
function GList.create() end

---@return cc.TextHAlignment
function GList:getAlign() end

---@return boolean
function GList:getAutoResizeItem() end

---@return integer
function GList:getColumnCount() end

---@return integer
function GList:getColumnGap() end

---@return string
function GList:getDefaultItem() end

---@return fgui.GObject
---@overload fun(self: fgui.GList, url: string): fgui.GObject
function GList:getFromPool() end

---@return fgui.ListLayoutType
function GList:getLayout() end

---@return integer
function GList:getLineCount() end

---@return integer
function GList:getLineGap() end

---@return integer
function GList:getNumItems() end

---@return integer
function GList:getSelectedIndex() end

---@param result cc.types.VectorInt
function GList:getSelection(result) end

---@return fgui.GController
function GList:getSelectionController() end

---@return fgui.ListSelectionMode
function GList:getSelectionMode() end

---@return cc.TextVAlignment
function GList:getVerticalAlign() end

---@param dir integer
function GList:handleArrowKey(dir) end

---@return boolean
function GList:isVirtual() end

---@param index integer
---@return integer
function GList:itemIndexToChildIndex(index) end

---@return fgui.GList
function GList.new() end

function GList:refreshVirtualList() end

---@param child fgui.GObject
function GList:removeChildToPool(child) end

---@param index integer
function GList:removeChildToPoolAt(index) end

---@overload fun(self: fgui.GList, beginIndex: integer, endIndex: integer)
function GList:removeChildrenToPool() end

---@param index integer
function GList:removeSelection(index) end

---@param itemCount integer
---@overload fun(self: fgui.GList, itemCount: integer, minSize: integer)
function GList:resizeToFit(itemCount) end

---@param obj fgui.GObject
function GList:returnToPool(obj) end

---@param index integer
---@param ani boolean
---@param setFirst boolean
---@overload fun(self: fgui.GList, index: integer)
---@overload fun(self: fgui.GList, index: integer, ani: boolean)
function GList:scrollToView(index, ani, setFirst) end

function GList:selectAll() end

function GList:selectReverse() end

---@param value cc.TextHAlignment
function GList:setAlign(value) end

---@param value boolean
function GList:setAutoResizeItem(value) end

---@param value integer
function GList:setColumnCount(value) end

---@param value integer
function GList:setColumnGap(value) end

---@param value string
function GList:setDefaultItem(value) end

---@param value fgui.ListLayoutType
function GList:setLayout(value) end

---@param value integer
function GList:setLineCount(value) end

---@param value integer
function GList:setLineGap(value) end

---@param value integer
function GList:setNumItems(value) end

---@param value integer
function GList:setSelectedIndex(value) end

---@param value fgui.GController
function GList:setSelectionController(value) end

---@param value fgui.ListSelectionMode
function GList:setSelectionMode(value) end

---@param value cc.TextVAlignment
function GList:setVerticalAlign(value) end

function GList:setVirtual() end

function GList:setVirtualAndLoop() end

return GList