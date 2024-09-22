---AUTO GENERATED, DO NOT MODIFY!
---@meta fgui.GObject

---
---@class fgui.GObject : fgui.UIEventDispatcher
---@field alpha number 
---@field customData any 
---@field data any 
---@field displayObject cc.Node 
---@field dragBounds cc.Rect 
---@field draggable boolean 
---@field draggingObject fgui.GObject 
---@field grayed boolean 
---@field group fgui.GGroup 
---@field height number 
---@field icon string 
---@field packageItem fgui.PackageItem 
---@field parent fgui.GComponent 
---@field pivot cc.Vec2 
---@field pivotAsAnchor boolean 
---@field pixelSnapping boolean 
---@field relations fgui.Relations 
---@field resourceURL string 
---@field root fgui.GRoot 
---@field rotation number 
---@field scaleX number 
---@field scaleY number 
---@field size cc.Size 
---@field skewX number 
---@field skewY number 
---@field sortingOrder integer 
---@field text string 
---@field tooltips string 
---@field touchable boolean 
---@field visible boolean 
---@field width number 
---@field x number 
---@field xMin number 
---@field y number 
---@field yMin number 
---@field id string
---@field name string
---@field sourceSize cc.Size
---@field initSize cc.Size
---@field minSize cc.Size
---@field maxSize cc.Size
local GObject = {}

---@param callback fgui.EventCallback
---@overload fun(self: fgui.GObject, callback: fgui.EventCallback, tag: any)
function GObject:addClickListener(callback) end

---@return integer
function GObject:addDisplayLock() end

---@param target fgui.GObject
---@param relationType fgui.RelationType
---@param usePercent boolean
---@overload fun(self: fgui.GObject, target: fgui.GObject, relationType: fgui.RelationType)
function GObject:addRelation(target, relationType, usePercent) end

---@param restraint boolean
---@overload fun(self: fgui.GObject)
function GObject:center(restraint) end

---@param index integer
---@param c fgui.GController
---@return boolean
function GObject:checkGearController(index, c) end

---@return fgui.GObject
function GObject.create() end

---@return fgui.GObject
function GObject:findParent() end

---@return number
function GObject:getAlpha() end

---@return any
function GObject:getCustomData() end

---@return any
function GObject:getData() end

---@return cc.Rect
function GObject:getDragBounds() end

---@return fgui.GObject
function GObject.getDraggingObject() end

---@param index integer
---@return fgui.GearBase
function GObject:getGear(index) end

---@return fgui.GGroup
function GObject:getGroup() end

---@return number
function GObject:getHeight() end

---@return string
function GObject:getIcon() end

---@return fgui.PackageItem
function GObject:getPackageItem() end

---@return fgui.GComponent
function GObject:getParent() end

---@return cc.Vec2
function GObject:getPivot() end

---@return cc.Vec2
function GObject:getPosition() end

---@param propId fgui.ObjectPropID
---@return any
function GObject:getProp(propId) end

---@return string
function GObject:getResourceURL() end

---@return fgui.GRoot
function GObject:getRoot() end

---@return number
function GObject:getRotation() end

---@return cc.Vec2
function GObject:getScale() end

---@return number
function GObject:getScaleX() end

---@return number
function GObject:getScaleY() end

---@return cc.Size
function GObject:getSize() end

---@return number
function GObject:getSkewX() end

---@return number
function GObject:getSkewY() end

---@return integer
function GObject:getSortingOrder() end

---@return string
function GObject:getText() end

---@return string
function GObject:getTooltips() end

---@return number
function GObject:getWidth() end

---@return number
function GObject:getX() end

---@return number
function GObject:getXMin() end

---@return number
function GObject:getY() end

---@return number
function GObject:getYMin() end

---@param pt cc.Vec2
---@return cc.Vec2
---@overload fun(self: fgui.GObject, rect: cc.Rect): cc.Rect
---@overload fun(self: fgui.GObject, x: number, y: number): number, number
---@overload fun(self: fgui.GObject, origin: cc.Vec2, size: cc.Size): cc.Vec2, cc.Size
function GObject:globalToLocal(pt) end

---@param worldPoint cc.Vec2
---@param camera cc.Camera
---@return fgui.GObject
function GObject:hitTest(worldPoint, camera) end

---@return boolean
function GObject:isDraggable() end

---@return boolean
function GObject:isGrayed() end

---@return boolean
function GObject:isPivotAsAnchor() end

---@return boolean
function GObject:isPixelSnapping() end

---@return boolean
function GObject:isTouchable() end

---@return boolean
function GObject:isVisible() end

---@param pt cc.Vec2
---@return cc.Vec2
---@overload fun(self: fgui.GObject, rect: cc.Rect): cc.Rect
---@overload fun(self: fgui.GObject, x: number, y: number): number, number
---@overload fun(self: fgui.GObject, origin: cc.Vec2, size: cc.Size): cc.Vec2, cc.Size
function GObject:localToGlobal(pt) end

function GObject:makeFullScreen() end

---@return fgui.GObject
function GObject.new() end

---@return boolean
function GObject:onStage() end

---@param token integer
function GObject:releaseDisplayLock(token) end

---@param tag any
function GObject:removeClickListener(tag) end

function GObject:removeFromParent() end

---@param target fgui.GObject
---@param relationType fgui.RelationType
function GObject:removeRelation(target, relationType) end

---@param value number
function GObject:setAlpha(value) end

---@param value any
function GObject:setCustomData(value) end

---@param value any
function GObject:setData(value) end

---@param value cc.Rect
function GObject:setDragBounds(value) end

---@param value boolean
function GObject:setDraggable(value) end

---@param value boolean
function GObject:setGrayed(value) end

---@param value fgui.GGroup
function GObject:setGroup(value) end

---@param value number
function GObject:setHeight(value) end

---@param text string
function GObject:setIcon(text) end

---@param xv number
---@param yv number
---@param asAnchor boolean
---@overload fun(self: fgui.GObject, xv: number, yv: number)
function GObject:setPivot(xv, yv, asAnchor) end

---@param value boolean
function GObject:setPixelSnapping(value) end

---@param xv number
---@param yv number
function GObject:setPosition(xv, yv) end

---@param propId fgui.ObjectPropID
---@param value any
function GObject:setProp(propId, value) end

---@param value number
function GObject:setRotation(value) end

---@param xv number
---@param yv number
function GObject:setScale(xv, yv) end

---@param value number
function GObject:setScaleX(value) end

---@param value number
function GObject:setScaleY(value) end

---@param wv number
---@param hv number
---@param ignorePivot boolean
---@overload fun(self: fgui.GObject, wv: number, hv: number)
function GObject:setSize(wv, hv, ignorePivot) end

---@param value number
function GObject:setSkewX(value) end

---@param value number
function GObject:setSkewY(value) end

---@param value integer
function GObject:setSortingOrder(value) end

---@param text string
function GObject:setText(text) end

---@param value string
function GObject:setTooltips(value) end

---@param value boolean
function GObject:setTouchable(value) end

---@param value boolean
function GObject:setVisible(value) end

---@param value number
function GObject:setWidth(value) end

---@param value number
function GObject:setX(value) end

---@param value number
function GObject:setXMin(value) end

---@param value number
function GObject:setY(value) end

---@param value number
function GObject:setYMin(value) end

---@param touchId integer
---@overload fun(self: fgui.GObject)
function GObject:startDrag(touchId) end

function GObject:stopDrag() end

---@param rect cc.Rect
---@param targetSpace fgui.GObject
---@return cc.Rect
---@overload fun(self: fgui.GObject, origin: cc.Vec2, size: cc.Size, targetSpace: fgui.GObject): cc.Vec2, cc.Size
function GObject:transformRect(rect, targetSpace) end

---@return fgui.GTreeNode
function GObject:treeNode() end

return GObject