---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.ScrollPane

---
---@class fgui.ScrollPane : cc.Ref
---@field bottomMost boolean 
---@field bouncebackEffect boolean 
---@field contentSize cc.Size 
---@field decelerationRate number 
---@field draggingPane fgui.ScrollPane 
---@field footer fgui.GComponent 
---@field header fgui.GComponent 
---@field hzScrollBar fgui.GScrollBar 
---@field inertiaDisabled boolean 
---@field mouseWheelEnabled boolean 
---@field owner fgui.GComponent 
---@field pageController fgui.GController 
---@field pageMode boolean 
---@field pageX integer 
---@field pageY integer 
---@field percX number 
---@field percY number 
---@field posX number 
---@field posY number 
---@field rightMost boolean 
---@field scrollStep number 
---@field scrollingPosX number 
---@field scrollingPosY number 
---@field snapToItem boolean 
---@field touchEffect boolean 
---@field viewSize cc.Size 
---@field vtScrollBar fgui.GScrollBar 
local ScrollPane = {}

function ScrollPane:cancelDragging() end

---@return cc.Size
function ScrollPane:getContentSize() end

---@return number
function ScrollPane:getDecelerationRate() end

---@return fgui.ScrollPane
function ScrollPane.getDraggingPane() end

---@return fgui.GComponent
function ScrollPane:getFooter() end

---@return fgui.GComponent
function ScrollPane:getHeader() end

---@return fgui.GScrollBar
function ScrollPane:getHzScrollBar() end

---@return fgui.GComponent
function ScrollPane:getOwner() end

---@return fgui.GController
function ScrollPane:getPageController() end

---@return integer
function ScrollPane:getPageX() end

---@return integer
function ScrollPane:getPageY() end

---@return number
function ScrollPane:getPercX() end

---@return number
function ScrollPane:getPercY() end

---@return number
function ScrollPane:getPosX() end

---@return number
function ScrollPane:getPosY() end

---@return number
function ScrollPane:getScrollStep() end

---@return number
function ScrollPane:getScrollingPosX() end

---@return number
function ScrollPane:getScrollingPosY() end

---@return cc.Size
function ScrollPane:getViewSize() end

---@return fgui.GScrollBar
function ScrollPane:getVtScrollBar() end

---@return boolean
function ScrollPane:isBottomMost() end

---@return boolean
function ScrollPane:isBouncebackEffect() end

---@param obj fgui.GObject
---@return boolean
function ScrollPane:isChildInView(obj) end

---@return boolean
function ScrollPane:isInertiaDisabled() end

---@return boolean
function ScrollPane:isMouseWheelEnabled() end

---@return boolean
function ScrollPane:isPageMode() end

---@return boolean
function ScrollPane:isRightMost() end

---@return boolean
function ScrollPane:isSnapToItem() end

---@return boolean
function ScrollPane:isTouchEffect() end

---@param size integer
function ScrollPane:lockFooter(size) end

---@param size integer
function ScrollPane:lockHeader(size) end

---@param owner fgui.GComponent
---@return fgui.ScrollPane
function ScrollPane.new(owner) end

---@param ani boolean
---@overload fun(self: fgui.ScrollPane)
function ScrollPane:scrollBottom(ani) end

---@param ratio number
---@param ani boolean
---@overload fun(self: fgui.ScrollPane)
---@overload fun(self: fgui.ScrollPane, ratio: number)
function ScrollPane:scrollDown(ratio, ani) end

---@param ratio number
---@param ani boolean
---@overload fun(self: fgui.ScrollPane)
---@overload fun(self: fgui.ScrollPane, ratio: number)
function ScrollPane:scrollLeft(ratio, ani) end

---@param ratio number
---@param ani boolean
---@overload fun(self: fgui.ScrollPane)
---@overload fun(self: fgui.ScrollPane, ratio: number)
function ScrollPane:scrollRight(ratio, ani) end

---@param obj fgui.GObject
---@param ani boolean
---@param setFirst boolean
---@overload fun(self: fgui.ScrollPane, obj: fgui.GObject)
---@overload fun(self: fgui.ScrollPane, obj: fgui.GObject, ani: boolean)
---@overload fun(self: fgui.ScrollPane, rect: cc.Rect, ani: boolean, setFirst: boolean)
---@overload fun(self: fgui.ScrollPane, rect: cc.Rect)
---@overload fun(self: fgui.ScrollPane, rect: cc.Rect, ani: boolean)
function ScrollPane:scrollToView(obj, ani, setFirst) end

---@param ani boolean
---@overload fun(self: fgui.ScrollPane)
function ScrollPane:scrollTop(ani) end

---@param ratio number
---@param ani boolean
---@overload fun(self: fgui.ScrollPane)
---@overload fun(self: fgui.ScrollPane, ratio: number)
function ScrollPane:scrollUp(ratio, ani) end

---@param value boolean
function ScrollPane:setBouncebackEffect(value) end

---@param value number
function ScrollPane:setDecelerationRate(value) end

---@param value boolean
function ScrollPane:setInertiaDisabled(value) end

---@param value boolean
function ScrollPane:setMouseWheelEnabled(value) end

---@param value fgui.GController
function ScrollPane:setPageController(value) end

---@param value boolean
function ScrollPane:setPageMode(value) end

---@param value integer
---@param ani boolean
---@overload fun(self: fgui.ScrollPane, value: integer)
function ScrollPane:setPageX(value, ani) end

---@param value integer
---@param ani boolean
---@overload fun(self: fgui.ScrollPane, value: integer)
function ScrollPane:setPageY(value, ani) end

---@param value number
---@param ani boolean
---@overload fun(self: fgui.ScrollPane, value: number)
function ScrollPane:setPercX(value, ani) end

---@param value number
---@param ani boolean
---@overload fun(self: fgui.ScrollPane, value: number)
function ScrollPane:setPercY(value, ani) end

---@param value number
---@param ani boolean
---@overload fun(self: fgui.ScrollPane, value: number)
function ScrollPane:setPosX(value, ani) end

---@param value number
---@param ani boolean
---@overload fun(self: fgui.ScrollPane, value: number)
function ScrollPane:setPosY(value, ani) end

---@param value number
function ScrollPane:setScrollStep(value) end

---@param value boolean
function ScrollPane:setSnapToItem(value) end

---@param value boolean
function ScrollPane:setTouchEffect(value) end

return ScrollPane