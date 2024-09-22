---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.GComponent

---
---@class fgui.GComponent : fgui.GObject
---@field apexIndex integer 
---@field baseUserData string 
---@field children any 
---@field childrenRenderOrder fgui.ChildrenRenderOrder 
---@field controllers any 
---@field firstChildInView integer 
---@field hitArea fgui.IHitTest 
---@field margin fgui.Margin 
---@field mask cc.Node 
---@field numChildren integer 
---@field opaque boolean 
---@field scrollPane fgui.ScrollPane 
---@field transitions any 
---@field viewHeight number 
---@field viewWidth number 
local GComponent = {}

---@return any
function GComponent:__index() end

---@param child fgui.GObject
---@return fgui.GObject
function GComponent:addChild(child) end

---@param child fgui.GObject
---@param index integer
---@return fgui.GObject
function GComponent:addChildAt(child, index) end

---@param c fgui.GController
function GComponent:addController(c) end

---@param obj fgui.GObject
---@param c fgui.GController
function GComponent:adjustRadioGroupDepth(obj, c) end

function GComponent:applyAllControllers() end

---@param c fgui.GController
function GComponent:applyController(c) end

---@param child fgui.GObject
---@param oldValue integer
---@param newValue integer
function GComponent:childSortingOrderChanged(child, oldValue, newValue) end

---@param child fgui.GObject
function GComponent:childStateChanged(child) end

---@return fgui.GComponent
function GComponent.create() end

function GComponent:ensureBoundsCorrect() end

---@return integer
function GComponent:getApexIndex() end

---@return string
function GComponent:getBaseUserData() end

---@param name string
---@return fgui.GObject
function GComponent:getChild(name) end

---@param index integer
---@return fgui.GObject
function GComponent:getChildAt(index) end

---@param id string
---@return fgui.GObject
function GComponent:getChildById(id) end

---@param path string
---@return fgui.GObject
function GComponent:getChildByPath(path) end

---@param group fgui.GGroup
---@param name string
---@return fgui.GObject
function GComponent:getChildInGroup(group, name) end

---@param child fgui.GObject
---@return integer
function GComponent:getChildIndex(child) end

---@return any
function GComponent:getChildren() end

---@return fgui.ChildrenRenderOrder
function GComponent:getChildrenRenderOrder() end

---@param name string
---@return fgui.GController
function GComponent:getController(name) end

---@param index integer
---@return fgui.GController
function GComponent:getControllerAt(index) end

---@return any
function GComponent:getControllers() end

---@return integer
function GComponent:getFirstChildInView() end

---@return fgui.IHitTest
function GComponent:getHitArea() end

---@return fgui.Margin
function GComponent:getMargin() end

---@return cc.Node
function GComponent:getMask() end

---@return boolean
function GComponent:getOpaque() end

---@return fgui.ScrollPane
function GComponent:getScrollPane() end

---@param pt cc.Vec2
---@return cc.Vec2
function GComponent:getSnappingPosition(pt) end

---@param name string
---@return fgui.Transition
function GComponent:getTransition(name) end

---@param index integer
---@return fgui.Transition
function GComponent:getTransitionAt(index) end

---@return any
function GComponent:getTransitions() end

---@return number
function GComponent:getViewHeight() end

---@return number
function GComponent:getViewWidth() end

---@param obj fgui.GObject
---@return boolean
function GComponent:isAncestorOf(obj) end

---@param child fgui.GObject
---@return boolean
function GComponent:isChildInView(child) end

---@return fgui.GComponent
function GComponent.new() end

---@param child fgui.GObject
function GComponent:removeChild(child) end

---@param index integer
function GComponent:removeChildAt(index) end

---@overload fun(self: fgui.GComponent, beginIndex: integer, endIndex: integer)
function GComponent:removeChildren() end

---@param c fgui.GController
function GComponent:removeController(c) end

---@param name string
---@return unknown
function GComponent:resolve(name) end

---@param value integer
function GComponent:setApexIndex(value) end

function GComponent:setBoundsChangedFlag() end

---@param child fgui.GObject
---@param index integer
function GComponent:setChildIndex(child, index) end

---@param child fgui.GObject
---@param index integer
---@return integer
function GComponent:setChildIndexBefore(child, index) end

---@param value fgui.ChildrenRenderOrder
function GComponent:setChildrenRenderOrder(value) end

---@param value fgui.IHitTest
function GComponent:setHitArea(value) end

---@param value fgui.Margin
function GComponent:setMargin(value) end

---@param value cc.Node
---@param inverted boolean
---@overload fun(self: fgui.GComponent, value: cc.Node)
function GComponent:setMask(value, inverted) end

---@param value boolean
function GComponent:setOpaque(value) end

---@param value number
function GComponent:setViewHeight(value) end

---@param value number
function GComponent:setViewWidth(value) end

---@param child1 fgui.GObject
---@param child2 fgui.GObject
function GComponent:swapChildren(child1, child2) end

---@param index1 integer
---@param index2 integer
function GComponent:swapChildrenAt(index1, index2) end

return GComponent