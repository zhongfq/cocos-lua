---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.Widget

---Base class for all ui widgets.
---This class inherent from `ProtectedNode` and `LayoutParameterProtocol`.
---If you want to implements your own ui widget, you should subclass it.
---@class ccui.Widget : cc.ProtectedNode
---@field actionTag integer Get the action tag. \return Action tag.
---@field bottomBoundary number Gets the bottom boundary position of this widget in parent's coordination system. \return The bottom boundary position of this widget.
---@field bright boolean Determines if the widget is bright <br><br>\return true if the widget is bright, false if the widget is dark.
---@field callbackName string Query callback name. \return The callback name.
---@field callbackType string Query callback type. \return Callback type string.
---@field currentFocusedWidget ccui.Widget Return a current focused widget in your UI scene. No matter what widget object you call this method on , it will return you the exact one focused widget.
---@field customSize cc.Size Get the user defined widget size. \return User defined size.
---@field enabled boolean Determines if the widget is enabled or not. <br><br>\return true if the widget is enabled, false if the widget is disabled.
---@field flippedX boolean Returns the flag which indicates whether the widget is flipped horizontally or not. <br><br>It not only flips the texture of the widget, but also the texture of the widget's children. Also, flipping relies on widget's anchor point. Internally, it just use setScaleX(-1) to flip the widget. <br><br>\return true if the widget is flipped horizontally, false otherwise.
---@field flippedY boolean Return the flag which indicates whether the widget is flipped vertically or not. <br><br>It not only flips the texture of the widget, but also the texture of the widget's children. Also, flipping relies on widget's anchor point. Internally, it just use setScaleY(-1) to flip the widget. <br><br>\return true if the widget is flipped vertically, false otherwise.
---@field focusEnabled boolean Query widget's focus enable state. \return true represent the widget could accept focus, false represent the widget couldn't accept focus
---@field focused boolean Query whether widget is focused or not. \return  whether the widget is focused or not
---@field highlighted boolean Determines if the widget is highlighted <br><br>\return true if the widget is highlighted, false if the widget is not highlighted.
---@field layoutComponentEnabled boolean Query whether layout component is enabled or not.  \return true represent the widget use Layout Component, false represent the widget couldn't use Layout Component.
---@field layoutParameter ccui.LayoutParameter Gets LayoutParameter of widget. <br><br>\see LayoutParameter \return LayoutParameter
---@field layoutSize cc.Size Get the content size of widget. \warning This API exists mainly for keeping back compatibility. \return
---@field leftBoundary number Gets the left boundary position of this widget in parent's coordination system. \return The left boundary position of this widget.
---@field positionPercent cc.Vec2 Gets the percent (x,y) of the widget in OpenGL coordinates <br><br>\see setPosition(const Vec2&) <br><br>\return The percent (x,y) of the widget in OpenGL coordinates
---@field positionType ccui.Widget.PositionType Gets the position type of the widget <br><br>\see `PositionType` <br><br>\return type  the position type of widget
---@field propagateTouchEvents boolean Return whether the widget is propagate touch events to its parents or not \return whether touch event propagation is allowed or not. \since v3.3
---@field rightBoundary number Gets the right boundary position of this widget in parent's coordination system. \return The right boundary position of this widget.
---@field sizePercent cc.Vec2 Get size percent of widget. <br><br>\return Percent size.
---@field sizeType ccui.Widget.SizeType Gets the size type of widget. <br><br>\see `SizeType`
---@field swallowTouches boolean Return whether the widget is swallowing touch or not \return Whether touch is swallowed. \since v3.3
---@field topBoundary number Gets the top boundary position of this widget in parent's coordination system. \return The top boundary position of this widget.
---@field touchBeganPosition cc.Vec2 Gets the touch began point of widget when widget is selected. \return the touch began point.
---@field touchEnabled boolean Determines if the widget is touch enabled <br><br>\return true if the widget is touch enabled, false if the widget is touch disabled.
---@field touchEndPosition cc.Vec2 
---@field touchMovePosition cc.Vec2 
---@field unifySizeEnabled boolean Query whether unify size enable state.  \return true represent the widget use Unify Size, false represent the widget couldn't use Unify Size
---@field virtualRenderer cc.Node Gets the inner Renderer node of widget. <br><br>For example, a button's Virtual Renderer is it's texture renderer. <br><br>\return Node pointer.
---@field virtualRendererSize cc.Size Get the virtual renderer's size \return Widget virtual renderer size.
---@field worldPosition cc.Vec2 Gets position of widget in world space. <br><br>\return Position of widget in world space.
---@field onFocusChanged fun(arg1: ccui.Widget, arg2: ccui.Widget)
---@field onNextFocusedWidget fun(arg1: ccui.Widget.FocusDirection): ccui.Widget
local Widget = {}

---Set a event handler to the widget in order to use cocostudio editor and framework
---@param callback ccui.Widget.ccWidgetEventCallback # The callback in `ccWidgetEventCallback`.
---\lua NA
function Widget:addCCSEventListener(callback) end

---Set a click event handler to the widget.
---@param callback ccui.Widget.ccWidgetClickCallback # The callback in `ccWidgetClickCallback`.
function Widget:addClickEventListener(callback) end

---Set a callback to touch vent listener.
---@param callback ccui.Widget.ccWidgetTouchCallback # The callback in `ccWidgetEventCallback.`
function Widget:addTouchEventListener(callback) end

---@param cls string
---@return any
function Widget:as(cls) end

---Create a new widget copy of the original one.
---@return ccui.Widget # A cloned widget copy of original.
function Widget:clone() end

---Create and return a empty Widget instance pointer.
---@return ccui.Widget
function Widget.create() end

---Dispatch a EventFocus through a EventDispatcher
---@param widgetLoseFocus ccui.Widget # The widget which lose its focus
---@param widgetGetFocus ccui.Widget # he widget which get its focus
function Widget:dispatchFocusEvent(widgetLoseFocus, widgetGetFocus) end

---@param enable boolean
function Widget.enableDpadNavigation(enable) end

---When a widget is in a layout, you could call this method to get the next focused widget within a specified direction. 
---If the widget is not in a layout, it will return itself
---@param direction ccui.Widget.FocusDirection # the direction to look for the next focused widget in a layout
---@param current ccui.Widget # the current focused widget
---@return ccui.Widget # the next focused widget in a layout
function Widget:findNextFocusedWidget(direction, current) end

---Get the action tag.
---@return integer # Action tag.
function Widget:getActionTag() end

---Gets the bottom boundary position of this widget in parent's coordination system.
---@return number # The bottom boundary position of this widget.
function Widget:getBottomBoundary() end

---Query callback name.
---@return string # The callback name.
function Widget:getCallbackName() end

---Query callback type.
---@return string # Callback type string.
function Widget:getCallbackType() end

---Return a current focused widget in your UI scene.
---No matter what widget object you call this method on , it will return you the exact one focused widget.
---@return ccui.Widget
function Widget.getCurrentFocusedWidget() end

---Get the user defined widget size.
---@return cc.Size # User defined size.
function Widget:getCustomSize() end

---Gets LayoutParameter of widget.
---
---\see LayoutParameter
---@return ccui.LayoutParameter # LayoutParameter
function Widget:getLayoutParameter() end

---Get the content size of widget.
---\warning This API exists mainly for keeping back compatibility.
---@return cc.Size # 
function Widget:getLayoutSize() end

---Gets the left boundary position of this widget in parent's coordination system.
---@return number # The left boundary position of this widget.
function Widget:getLeftBoundary() end

---Gets the percent (x,y) of the widget in OpenGL coordinates
---
---\see setPosition(const Vec2&)
---
---@return cc.Vec2 # The percent (x,y) of the widget in OpenGL coordinates
function Widget:getPositionPercent() end

---Gets the position type of the widget
---
---\see `PositionType`
---
---@return ccui.Widget.PositionType # type  the position type of widget
function Widget:getPositionType() end

---Gets the right boundary position of this widget in parent's coordination system.
---@return number # The right boundary position of this widget.
function Widget:getRightBoundary() end

---Get size percent of widget.
---
---@return cc.Vec2 # Percent size.
function Widget:getSizePercent() end

---Gets the size type of widget.
---
---\see `SizeType`
---@return ccui.Widget.SizeType
function Widget:getSizeType() end

---Gets the top boundary position of this widget in parent's coordination system.
---@return number # The top boundary position of this widget.
function Widget:getTopBoundary() end

---Gets the touch began point of widget when widget is selected.
---@return cc.Vec2 # the touch began point.
function Widget:getTouchBeganPosition() end

---@return cc.Vec2
function Widget:getTouchEndPosition() end

---@return cc.Vec2
function Widget:getTouchMovePosition() end

---Gets the inner Renderer node of widget.
---
---For example, a button's Virtual Renderer is it's texture renderer.
---
---@return cc.Node # Node pointer.
function Widget:getVirtualRenderer() end

---Get the virtual renderer's size
---@return cc.Size # Widget virtual renderer size.
function Widget:getVirtualRendererSize() end

---Gets position of widget in world space.
---
---@return cc.Vec2 # Position of widget in world space.
function Widget:getWorldPosition() end

---Checks a point is in widget's content space.
---This function is used for determining touch area of widget.
---
---@param pt cc.Vec2 # The point in `Vec2`.
---@param camera cc.Camera # The camera look at widget, used to convert GL screen point to near/far plane.
---@param p cc.Vec3 # Point to a Vec3 for store the intersect point, if don't need them set to nullptr.
---@return boolean # true if the point is in widget's content space, false otherwise.
function Widget:hitTest(pt, camera, p) end

---Toggle whether ignore user defined content size for widget.
---Set true will ignore user defined content size which means 
---the widget size is always equal to the return value of `getVirtualRendererSize`.
---
---@param ignore boolean # set member variable _ignoreSize to ignore
function Widget:ignoreContentAdaptWithSize(ignore) end

---@param event ccui.Widget.TouchEventType
---@param sender ccui.Widget
---@param touch cc.Touch
function Widget:interceptTouchEvent(event, sender, touch) end

---Determines if the widget is bright
---
---@return boolean # true if the widget is bright, false if the widget is dark.
function Widget:isBright() end

---Checks a point if in parent's area.
---
---@param pt cc.Vec2 # A point in `Vec2`.
---@return boolean # true if the point is in parent's area, false otherwise.
function Widget:isClippingParentContainsPoint(pt) end

---Determines if the widget is enabled or not.
---
---@return boolean # true if the widget is enabled, false if the widget is disabled.
function Widget:isEnabled() end

---Returns the flag which indicates whether the widget is flipped horizontally or not.
---
---It not only flips the texture of the widget, but also the texture of the widget's children.
---Also, flipping relies on widget's anchor point.
---Internally, it just use setScaleX(-1) to flip the widget.
---
---@return boolean # true if the widget is flipped horizontally, false otherwise.
function Widget:isFlippedX() end

---Return the flag which indicates whether the widget is flipped vertically or not.
---
---It not only flips the texture of the widget, but also the texture of the widget's children.
---Also, flipping relies on widget's anchor point.
---Internally, it just use setScaleY(-1) to flip the widget.
---
---@return boolean # true if the widget is flipped vertically, false otherwise.
function Widget:isFlippedY() end

---Query widget's focus enable state.
---@return boolean # true represent the widget could accept focus, false represent the widget couldn't accept focus
function Widget:isFocusEnabled() end

---Query whether widget is focused or not.
---@return boolean # whether the widget is focused or not
function Widget:isFocused() end

---Determines if the widget is highlighted
---
---@return boolean # true if the widget is highlighted, false if the widget is not highlighted.
function Widget:isHighlighted() end

---Query whether the widget ignores user defined content size or not
---
---@return boolean # True means ignore user defined content size, false otherwise.
function Widget:isIgnoreContentAdaptWithSize() end

---Query whether layout component is enabled or not. 
---@return boolean # true represent the widget use Layout Component, false represent the widget couldn't use Layout Component.
function Widget:isLayoutComponentEnabled() end

---Return whether the widget is propagate touch events to its parents or not
---@return boolean # whether touch event propagation is allowed or not.
---\since v3.3
function Widget:isPropagateTouchEvents() end

---Return whether the widget is swallowing touch or not
---@return boolean # Whether touch is swallowed.
---\since v3.3
function Widget:isSwallowTouches() end

---Determines if the widget is touch enabled
---
---@return boolean # true if the widget is touch enabled, false if the widget is touch disabled.
function Widget:isTouchEnabled() end

---Query whether unify size enable state. 
---@return boolean # true represent the widget use Unify Size, false represent the widget couldn't use Unify Size
function Widget:isUnifySizeEnabled() end

---Default constructor
---\js ctor
---\lua new
---@return ccui.Widget
function Widget.new() end

---This method is called when a focus change event happens
---@param widgetLostFocus ccui.Widget # The widget which lose its focus
---@param widgetGetFocus ccui.Widget # The widget which get its focus
function Widget:onFocusChange(widgetLostFocus, widgetGetFocus) end

---A callback which will be called when touch began event is issued.
---@param touch cc.Touch # The touch info.
---@param unusedEvent cc.Event # The touch event info.
---@return boolean # True if user want to handle touches, false otherwise.
function Widget:onTouchBegan(touch, unusedEvent) end

---A callback which will be called when touch cancelled event is issued.
---@param touch cc.Touch # The touch info.
---@param unusedEvent cc.Event # The touch event info.
function Widget:onTouchCancelled(touch, unusedEvent) end

---A callback which will be called when touch ended event is issued.
---@param touch cc.Touch # The touch info.
---@param unusedEvent cc.Event # The touch event info.
function Widget:onTouchEnded(touch, unusedEvent) end

---A callback which will be called when touch moved event is issued.
---@param touch cc.Touch # The touch info.
---@param unusedEvent cc.Event # The touch event info.
function Widget:onTouchMoved(touch, unusedEvent) end

---Propagate touch events to its parents
---@param event ccui.Widget.TouchEventType
---@param sender ccui.Widget
---@param touch cc.Touch
function Widget:propagateTouchEvent(event, sender, touch) end

---when a widget calls this method, it will get focus immediately.
function Widget:requestFocus() end

---Set the tag of action.
---@param tag integer # A integer tag value.
function Widget:setActionTag(tag) end

---Sets whether the widget is bright
---
---The default value is true, a widget is default to bright
---
---@param bright boolean # true if the widget is bright, false if the widget is dark.
function Widget:setBright(bright) end

---To set the bright style of widget.
---
---\see BrightStyle
---
---@param style ccui.Widget.BrightStyle # BrightStyle::NORMAL means the widget is in normal state, BrightStyle::HIGHLIGHT means the widget is in highlight state.
function Widget:setBrightStyle(style) end

---Set callback name.
---@param callbackName string # A string representation of callback name.
function Widget:setCallbackName(callbackName) end

---Set callback type.
---@param callbackType string # A string representation of callback type.
function Widget:setCallbackType(callbackType) end

---Sets whether the widget is enabled
---
---true if the widget is enabled, widget may be touched , false if the widget is disabled, widget cannot be touched.
---
---Note: If you want to change the widget's appearance  to disabled state, you should also call  `setBright(false)`.
---
---The default value is true, a widget is default to enable touch.
---
---@param enabled boolean # Set to true to enable touch, false otherwise.
function Widget:setEnabled(enabled) end

---Sets whether the widget should be flipped horizontally or not.
---
---@param flippedX boolean # true if the widget should be flipped horizontally, false otherwise.
function Widget:setFlippedX(flippedX) end

---Sets whether the widget should be flipped vertically or not.
---
---@param flippedY boolean # true if the widget should be flipped vertically, false otherwise.
function Widget:setFlippedY(flippedY) end

---Allow widget to accept focus.
---@param enable boolean # pass true/false to enable/disable the focus ability of a widget
function Widget:setFocusEnabled(enable) end

---Toggle widget focus status.
---@param focus boolean # pass true to let the widget get focus or pass false to let the widget lose focus
function Widget:setFocused(focus) end

---Sets whether the widget is highlighted
---
---The default value is false, a widget is default to not highlighted
---
---@param highlight boolean # true if the widget is highlighted, false if the widget is not highlighted.
function Widget:setHighlighted(highlight) end

---Toggle layout component enable.
---@param enable boolean # Layout Component of a widget
function Widget:setLayoutComponentEnabled(enable) end

---Sets a LayoutParameter to widget.
---
---\see LayoutParameter
---@param parameter ccui.LayoutParameter # LayoutParameter pointer
function Widget:setLayoutParameter(parameter) end

---Set the percent(x,y) of the widget in OpenGL coordinates
---
---@param percent cc.Vec2 # The percent (x,y) of the widget in OpenGL coordinates
function Widget:setPositionPercent(percent) end

---Changes the position type of the widget
---
---\see `PositionType`
---
---@param type ccui.Widget.PositionType # the position type of widget
function Widget:setPositionType(type) end

---Allow widget touch events to propagate to its parents. Set false will disable propagation
---@param isPropagate boolean # True to allow propagation, false otherwise.
---\since v3.3
function Widget:setPropagateTouchEvents(isPropagate) end

---Changes the percent that is widget's percent size
---
---@param percent cc.Vec2 # that is widget's percent size
function Widget:setSizePercent(percent) end

---Changes the size type of widget.
---
---\see `SizeType`
---
---@param type ccui.Widget.SizeType # that is widget's size type
function Widget:setSizeType(type) end

---Toggle widget swallow touch option.
---Specify widget to swallow touches or not
---@param swallow boolean # True to swallow touch, false otherwise.
---\since v3.3
function Widget:setSwallowTouches(swallow) end

---Sets whether the widget is touch enabled.
---
---The default value is false, a widget is default to touch disabled.
---
---@param enabled boolean # True if the widget is touch enabled, false if the widget is touch disabled.
function Widget:setTouchEnabled(enabled) end

---Toggle use unify size.
---@param enable boolean # True to use unify size, false otherwise.
function Widget:setUnifySizeEnabled(enable) end

---Update all children's contents size and position recursively.
---\see `updateSizeAndPosition(const Size&)`
---
---Update all children's contents size and position recursively.
---@overload fun(self: ccui.Widget, parentSize: cc.Size)
function Widget:updateSizeAndPosition() end

return Widget