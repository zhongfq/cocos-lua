---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Node

---\class Node
---Node is the base element of the Scene Graph. Elements of the Scene Graph must be Node objects or subclasses of it.
---The most common Node objects are: Scene, Layer, Sprite, Menu, Label.
---The main features of a Node are:
---- They can contain other Node objects (`addChild`, `getChildByTag`, `removeChild`, etc)
---- They can schedule periodic callback (`schedule`, `unschedule`, etc)
---- They can execute actions (`runAction`, `stopAction`, etc)
---Subclassing a Node usually means (one/all) of:
---- overriding init to initialize resources and schedule callbacks
---- create callbacks to handle the advancement of time
---- overriding `draw` to render the node
---Properties of Node:
---- position (default: x=0, y=0)
---- scale (default: x=1, y=1)
---- rotation (in degrees, clockwise) (default: 0)
---- anchor point (default: x=0, y=0)
---- contentSize (default: width=0, height=0)
---- visible (default: true)
---Limitations:
---- A Node is a "void" object. If you want to draw something on the screen, you should use a Sprite instead. Or subclass Node and override `draw`.
---@class cc.Node : cc.Ref
---@field actionManager cc.ActionManager Gets the ActionManager object that is used by all actions. \see setActionManager(ActionManager*) \return A ActionManager object.
---@field alpha number 
---@field anchorPoint cc.Vec2 Returns the anchor point in percent. <br><br>\see `setAnchorPoint(const Vec2&)` <br><br>\return The anchor point of node.
---@field anchorPointInPoints cc.Vec2 Returns the anchorPoint in absolute pixels. <br><br>\warning You can only read it. If you wish to modify it, use anchorPoint instead. \see `getAnchorPoint()` <br><br>\return The anchor point in absolute pixels.
---@field anchorX number 
---@field anchorY number 
---@field attachedNodeCount integer Gets count of nodes those are attached to scene graph.
---@field boundingBox cc.Rect Returns an AABB (axis-aligned bounding-box) in its parent's coordinate system. <br><br>\return An AABB (axis-aligned bounding-box) in its parent's coordinate system
---@field cameraMask integer get & set camera mask, the node is visible by the camera whose camera flag & node's camera mask is true
---@field cascadeColorEnabled boolean Query whether cascadeColor is enabled or not. \return Whether cascadeColor is enabled or not.
---@field cascadeOpacityEnabled boolean Whether cascadeOpacity is enabled or not. \return A boolean value.
---@field children any Returns the array of the node's children. <br><br>\return the array the node's children.
---@field childrenCount integer Returns the amount of children. <br><br>\return The amount of children.
---@field color any Query node's color value. \return A Color3B color value.
---@field contentSize cc.Size Returns the untransformed size of the node. <br><br>\see `setContentSize(const Size&)` <br><br>\return The untransformed size of the node.
---@field description string Gets the description string. It makes debugging easier. \return A string \js NA \lua NA
---@field displayedColor any Query node's displayed color. \return A Color3B color value.
---@field displayedOpacity integer Return the node's display opacity. The difference between opacity and displayedOpacity is: The displayedOpacity is what's the final rendering opacity of node. \return A GLubyte value.
---@field eventDispatcher cc.EventDispatcher Get the event dispatcher of scene. <br><br>\return The event dispatcher of scene.
---@field globalZOrder number Returns the Node's Global Z Order. <br><br>\see `setGlobalZOrder(int)` <br><br>\return The node's global Z order
---@field height number 
---@field ignoreAnchorPointForPosition boolean Gets whether the anchor point will be (0,0) when you position this node. <br><br>\see `setIgnoreAnchorPointForPosition(bool)` <br><br>\return true if the anchor point will be (0,0) when you position this node.
---@field localZOrder integer Gets the local Z order of this node. <br><br>\see `setLocalZOrder(int)` <br><br>\return The local (relative to its siblings) Z order.
---@field name string Returns a string that is used to identify the node. \return A string that identifies the node. <br><br>\since v3.2
---@field nodeToWorldAffineTransform cc.AffineTransform 
---@field nodeToWorldTransform cc.Mat4 Returns the world affine transform matrix. The matrix is in Pixels. <br><br>\return transformation matrix, in pixels.
---@field normalizedPosition cc.Vec2 
---@field numberOfRunningActions integer Returns the numbers of actions that are running plus the ones that are schedule to run (actions in actionsToAdd and actions arrays). <br><br>Composable actions are counted as 1 action. Example: If you are running 1 Sequence of 7 actions, it will return 1. If you are running 7 Sequences of 2 actions, it will return 7. <br><br>\return The number of actions that are running plus the ones that are schedule to run.
---@field onEnterCallback fun() Get the callback of event onEnter. \return A std:function<void()> callback.
---@field onEnterTransitionDidFinishCallback fun() Get the callback of event EnterTransitionDidFinish. \return std::function<void()>
---@field onExitCallback fun() Get the callback of event onExit. \return A std::function<void()>.
---@field onExitTransitionDidStartCallback fun() Get the callback of event ExitTransitionDidStart. \return std::function<void()>
---@field opacity integer Return the node's opacity. \return A GLubyte value.
---@field opacityModifyRGB boolean If node opacity will modify the RGB color value, then you should override this method and return true. \return A boolean value, true indicates that opacity will modify color; false otherwise.
---@field parent cc.Node Returns a pointer to the parent node. <br><br>\see `setParent(Node*)` <br><br>\returns A pointer to the parent node.
---@field parentToNodeAffineTransform cc.AffineTransform 
---@field parentToNodeTransform cc.Mat4 Returns the matrix that transform parent's space coordinates to the node's (local) space coordinates. The matrix is in Pixels. <br><br>\return The transformation matrix.
---@field physicsBody cc.PhysicsBody 
---@field position3D cc.Vec3 Returns the position (X,Y,Z) in its parent's coordinate system. <br><br>\return The position (X, Y, and Z) in its parent's coordinate system. \js NA
---@field positionNormalized cc.Vec2 Returns the normalized position. <br><br>\return The normalized position.
---@field positionX number Gets the x coordinate of the node in its parent's coordinate system. <br><br>\return The x coordinate of the node.
---@field positionY number Gets the y coordinate of the node in its parent's coordinate system. <br><br>\return The y coordinate of the node.
---@field positionZ number Gets position Z coordinate of this node. <br><br>\see setPositionZ(float) <br><br>\return The position Z coordinate of this node. \js getVertexZ
---@field programState ccb.ProgramState 
---@field rotation number Returns the rotation of the node in degrees. <br><br>\see `setRotation(float)` <br><br>\return The rotation of the node in degrees.
---@field rotation3D cc.Vec3 Returns the rotation (X,Y,Z) in degrees. <br><br>\return The rotation of the node in 3d. \js NA
---@field rotationQuat cc.Quaternion Return the rotation by quaternion, Note that when _rotationZ_X == _rotationZ_Y, the returned quaternion equals to RotationZ_X * RotationY * RotationX, it equals to RotationY * RotationX otherwise. <br><br>\return The rotation in quaternion. \js NA
---@field rotationSkewX number Gets the X rotation (angle) of the node in degrees which performs a horizontal rotation skew. <br><br>\see `setRotationSkewX(float)` <br><br>\return The X rotation in degrees. \js getRotationX
---@field rotationSkewY number Gets the Y rotation (angle) of the node in degrees which performs a vertical rotational skew. <br><br>\see `setRotationSkewY(float)` <br><br>\return The Y rotation in degrees. \js getRotationY
---@field running boolean Returns whether or not the node is "running". <br><br>If the node is running it will accept event callbacks like onEnter(), onExit(), update(). <br><br>\return Whether or not the node is running.
---@field scale number Gets the scale factor of the node,  when X and Y have the same scale factor. <br><br>\warning Assert when `_scaleX != _scaleY` \see setScale(float) <br><br>\return The scale factor of the node.
---@field scaleX number Returns the scale factor on X axis of this node <br><br>\see setScaleX(float) <br><br>\return The scale factor on X axis.
---@field scaleY number Returns the scale factor on Y axis of this node <br><br>\see `setScaleY(float)` <br><br>\return The scale factor on Y axis.
---@field scaleZ number Returns the scale factor on Z axis of this node <br><br>\see `setScaleZ(float)` <br><br>\return The scale factor on Z axis.
---@field scene cc.Scene Returns the Scene that contains the Node. It returns `nullptr` if the node doesn't belong to any Scene. This function recursively calls parent->getScene() until parent is a Scene object. The results are not cached. It is that the user caches the results in case this functions is being used inside a loop. <br><br>\return The Scene that contains the node.
---@field scheduler cc.Scheduler Gets a Scheduler object. <br><br>\see setScheduler(Scheduler*) \return A Scheduler object.
---@field skewX number Returns the X skew angle of the node in degrees. <br><br>\see `setSkewX(float)` <br><br>\return The X skew angle of the node in degrees.
---@field skewY number Returns the Y skew angle of the node in degrees. <br><br>\see `setSkewY(float)` <br><br>\return The Y skew angle of the node in degrees.
---@field tag integer Returns a tag that is used to identify the node easily. <br><br>\return An integer that identifies the node. <br><br>Please use `getTag()` instead.
---@field userData any Returns a custom user data pointer. <br><br>You can set everything in UserData pointer, a data block, a structure or an object. <br><br>\return A custom user data pointer. \lua NA
---@field userObject cc.Ref Returns a user assigned Object. <br><br>Similar to userData, but instead of holding a void* it holds an object. <br><br>\return A user assigned Object. \lua NA
---@field visible boolean Determines if the node is visible. <br><br>\see `setVisible(bool)` <br><br>\return true if the node is visible, false if the node is hidden.
---@field width number 
---@field worldToNodeAffineTransform cc.AffineTransform 
---@field worldToNodeTransform cc.Mat4 Returns the inverse world affine transform matrix. The matrix is in Pixels. <br><br>\return The transformation matrix.
---@field x number Gets the x coordinate of the node in its parent's coordinate system. <br><br>\return The x coordinate of the node.
---@field y number Gets the y coordinate of the node in its parent's coordinate system. <br><br>\return The y coordinate of the node.
---@field z number Gets position Z coordinate of this node. <br><br>\see setPositionZ(float) <br><br>\return The position Z coordinate of this node. \js getVertexZ
---@field INVALID_TAG integer
local Node = {}

---@return any
function Node.__index() end

---Adds a child to the container with z-order as 0.
---
---If the child is added to a 'running' node, then 'onEnter' and 'onEnterTransitionDidFinish' will be called immediately.
---
---@param child cc.Node # A child node.
---
---Adds a child to the container with a local z-order.
---
---If the child is added to a 'running' node, then 'onEnter' and 'onEnterTransitionDidFinish' will be called immediately.
---
---\param child     A child node.
---\param localZOrder    Z order for drawing priority. Please refer to `setLocalZOrder(int)`.
---@overload fun(self: cc.Node, child: cc.Node, localZOrder: integer)
---
---Adds a child to the container with z order and tag.
---
---If the child is added to a 'running' node, then 'onEnter' and 'onEnterTransitionDidFinish' will be called immediately.
---
---\param child         A child node.
---\param localZOrder   Z order for drawing priority. Please refer to `setLocalZOrder(int)`.
---\param tag           An integer to identify the node easily. Please refer to `setTag(int)`.
---
---Please use `addChild(Node* child, int localZOrder, const std::string &name)` instead.
---@overload fun(self: cc.Node, child: cc.Node, localZOrder: integer, tag: integer)
---
---Adds a child to the container with z order and tag
---
---If the child is added to a 'running' node, then 'onEnter' and 'onEnterTransitionDidFinish' will be called immediately.
---
---\param child     A child node.
---\param localZOrder    Z order for drawing priority. Please refer to `setLocalZOrder(int)`.
---\param name      A string to identify the node easily. Please refer to `setName(int)`.
---@overload fun(self: cc.Node, child: cc.Node, localZOrder: integer, name: string)
function Node:addChild(child) end

---Adds a component.
---
---@param component cc.Component # A given component.
---@return boolean # True if added success.
function Node:addComponent(component) end

---Stops all running actions and schedulers
function Node:cleanup() end

---Converts a Vec2 to node (local) space coordinates. The result is in Points.
---
---@param worldPoint cc.Vec2 # A given coordinate.
---@return cc.Vec2 # A point in node (local) space coordinates.
---@overload fun(self: cc.Node, x: number, y: number): number, number
function Node:convertToNodeSpace(worldPoint) end

---Converts a Vec2 to node (local) space coordinates. The result is in Points.
---treating the returned/received node point as anchor relative.
---
---@param worldPoint cc.Vec2 # A given coordinate.
---@return cc.Vec2 # A point in node (local) space coordinates, anchor relative.
---@overload fun(self: cc.Node, x: number, y: number): number, number
function Node:convertToNodeSpaceAR(worldPoint) end

---Converts a Vec2 to world space coordinates. The result is in Points.
---
---@param nodePoint cc.Vec2 # A given coordinate.
---@return cc.Vec2 # A point in world space coordinates.
---@overload fun(self: cc.Node, x: number, y: number): number, number
function Node:convertToWorldSpace(nodePoint) end

---Converts a local Vec2 to world space coordinates.The result is in Points.
---treating the returned/received node point as anchor relative.
---
---@param nodePoint cc.Vec2 # A given coordinate.
---@return cc.Vec2 # A point in world space coordinates, anchor relative.
---@overload fun(self: cc.Node, x: number, y: number): number, number
function Node:convertToWorldSpaceAR(nodePoint) end

---convenience methods which take a Touch instead of Vec2.
---
---@param touch cc.Touch # A given touch.
---@return cc.Vec2 # A point in world space coordinates.
function Node:convertTouchToNodeSpace(touch) end

---converts a Touch (world coordinates) into a local coordinate. This method is AR (Anchor Relative).
---
---@param touch cc.Touch # A given touch.
---@return cc.Vec2 # A point in world space coordinates, anchor relative.
function Node:convertTouchToNodeSpaceAR(touch) end

---Allocates and initializes a node.
---@return cc.Node # A initialized node which is marked as "autorelease".
function Node.create() end

---Override this method to draw your own node.
---The following GL states will be enabled by default:
---- `glEnableClientState(GL_VERTEX_ARRAY);`
---- `glEnableClientState(GL_COLOR_ARRAY);`
---- `glEnableClientState(GL_TEXTURE_COORD_ARRAY);`
---- `glEnable(GL_TEXTURE_2D);`
---AND YOU SHOULD NOT DISABLE THEM AFTER DRAWING YOUR NODE
---But if you enable any other GL state, you should disable it after drawing your node.
---
---@param renderer cc.Renderer # A given renderer.
---@param transform cc.Mat4 # A transform matrix.
---@param flags integer # Renderer flag.
---@overload fun(self: cc.Node)
function Node:draw(renderer, transform, flags) end

---Search the children of the receiving node to perform processing for nodes which share a name.
---
---@param name string # The name to search for, supports c++11 regular expression.
---Search syntax options:
---`//`: Can only be placed at the begin of the search string. This indicates that it will search recursively.
---`/..`: The search should move up to the node's parent. Can only be placed at the end of string.
---`/` : When placed anywhere but the start of the search string, this indicates that the search should move to the node's children.
---
---\code
---enumerateChildren("//MyName", ...): This searches the children recursively and matches any node with the name `MyName`.
---enumerateChildren("[[:alnum:]]+", ...): This search string matches every node of its children.
---enumerateChildren("A[[:digit:]]", ...): This searches the node's children and returns any child named `A0`, `A1`, ..., `A9`.
---enumerateChildren("Abby/Normal", ...): This searches the node's grandchildren and returns any node whose name is `Normal`
---and whose parent is named `Abby`.
---enumerateChildren("//Abby/Normal", ...): This searches recursively and returns any node whose name is `Normal` and whose
---parent is named `Abby`.
---\endcode
---
---\warning Only support alpha or number for name, and not support unicode.
---
---@param callback fun(arg1: cc.Node): boolean # A callback function to execute on nodes that match the `name` parameter. The function takes the following arguments:
---`node` 
---A node that matches the name
---And returns a boolean result. Your callback can return `true` to terminate the enumeration.
---
---\since v3.2
function Node:enumerateChildren(name, callback) end

---Gets an action from the running action list by its tag.
---
---\see `setTag(int)`, `getTag()`.
---
---@return cc.Action # The action object with the given tag.
---@param tag integer
function Node:getActionByTag(tag) end

---Gets the ActionManager object that is used by all actions.
---\see setActionManager(ActionManager*)
---@return cc.ActionManager # A ActionManager object.
function Node:getActionManager() end

---@param obj cc.Node
---@return number
function Node.getAlpha(obj) end

---Returns the anchor point in percent.
---
---\see `setAnchorPoint(const Vec2&)`
---
---@return cc.Vec2 # The anchor point of node.
function Node:getAnchorPoint() end

---Returns the anchorPoint in absolute pixels.
---
---\warning You can only read it. If you wish to modify it, use anchorPoint instead.
---\see `getAnchorPoint()`
---
---@return cc.Vec2 # The anchor point in absolute pixels.
function Node:getAnchorPointInPoints() end

---@param obj cc.Node
---@return number
function Node.getAnchorX(obj) end

---@param obj cc.Node
---@return number
function Node.getAnchorY(obj) end

---Gets count of nodes those are attached to scene graph.
---@return integer
function Node.getAttachedNodeCount() end

---Returns an AABB (axis-aligned bounding-box) in its parent's coordinate system.
---
---@return cc.Rect # An AABB (axis-aligned bounding-box) in its parent's coordinate system
function Node:getBoundingBox() end

---@param obj cc.Node
---@param target cc.Node
---@param left number
---@param right number
---@param top number
---@param bottom number
---@return number, number, number, number
function Node.getBounds(obj, target, left, right, top, bottom) end

---get & set camera mask, the node is visible by the camera whose camera flag & node's camera mask is true
---@return integer
function Node:getCameraMask() end

---Gets a child from the container with its name.
---
---@param name string # An identifier to find the child node.
---
---@return cc.Node # a Node object whose name equals to the input parameter.
---
---\since v3.2
function Node:getChildByName(name) end

---Gets a child from the container with its tag.
---
---@param tag integer # An identifier to find the child node.
---
---@return cc.Node # a Node object whose tag equals to the input parameter.
---
---Please use `getChildByName()` instead.
function Node:getChildByTag(tag) end

---Returns the array of the node's children.
---
---@return any # the array the node's children.
function Node:getChildren() end

---Returns the amount of children.
---
---@return integer # The amount of children.
function Node:getChildrenCount() end

---Query node's color value.
---@return any # A Color3B color value.
function Node:getColor() end

---\{
---\name component functions
---
---Gets a component by its name.
---
---@param name string # A given name of component.
---@return cc.Component # The Component by name.
function Node:getComponent(name) end

---Returns the untransformed size of the node.
---
---\see `setContentSize(const Size&)`
---
---@return cc.Size # The untransformed size of the node.
function Node:getContentSize() end

---Gets the description string. It makes debugging easier.
---@return string # A string
---\js NA
---\lua NA
function Node:getDescription() end

---Query node's displayed color.
---@return any # A Color3B color value.
function Node:getDisplayedColor() end

---Return the node's display opacity.
---The difference between opacity and displayedOpacity is:
---The displayedOpacity is what's the final rendering opacity of node.
---@return integer # A GLubyte value.
function Node:getDisplayedOpacity() end

---Get the event dispatcher of scene.
---
---@return cc.EventDispatcher # The event dispatcher of scene.
function Node:getEventDispatcher() end

---Returns the Node's Global Z Order.
---
---\see `setGlobalZOrder(int)`
---
---@return number # The node's global Z order
function Node:getGlobalZOrder() end

---@param obj cc.Node
---@return number
function Node.getHeight(obj) end

---Gets the local Z order of this node.
---
---\see `setLocalZOrder(int)`
---
---@return integer # The local (relative to its siblings) Z order.
function Node:getLocalZOrder() end

---Returns a string that is used to identify the node.
---@return string # A string that identifies the node.
---
---\since v3.2
function Node:getName() end

---@return cc.AffineTransform
---
---Returns the affine transform matrix that transform the node's (local) space coordinates into the parent's space coordinates.
---The matrix is in Pixels.
---
---Note: If ancestor is not a valid ancestor of the node, the API would return the same value as @see getNodeToWorldAffineTransform
---
---\param ancestor The parent's node pointer.
---\since v3.7
---\return The affine transformation matrix.
---@overload fun(self: cc.Node, ancestor: cc.Node): cc.AffineTransform
function Node:getNodeToParentAffineTransform() end

---Returns the matrix that transform the node's (local) space coordinates into the parent's space coordinates.
---The matrix is in Pixels.
---
---@return cc.Mat4 # The transformation matrix.
---
---Returns the matrix that transform the node's (local) space coordinates into the parent's space coordinates.
---The matrix is in Pixels.
---Note: If ancestor is not a valid ancestor of the node, the API would return the same value as @see getNodeToWorldTransform
---
---\param ancestor The parent's node pointer.
---\since v3.7
---\return The transformation matrix.
---@overload fun(self: cc.Node, ancestor: cc.Node): cc.Mat4
function Node:getNodeToParentTransform() end

---@return cc.AffineTransform
function Node:getNodeToWorldAffineTransform() end

---Returns the world affine transform matrix. The matrix is in Pixels.
---
---@return cc.Mat4 # transformation matrix, in pixels.
function Node:getNodeToWorldTransform() end

---@return cc.Vec2
function Node:getNormalizedPosition() end

---Returns the numbers of actions that are running plus the ones that are schedule to run (actions in actionsToAdd and actions arrays).
---
---Composable actions are counted as 1 action. Example:
---If you are running 1 Sequence of 7 actions, it will return 1.
---If you are running 7 Sequences of 2 actions, it will return 7.
---
---@return integer # The number of actions that are running plus the ones that are schedule to run.
function Node:getNumberOfRunningActions() end

---Returns the numbers of actions that are running plus the ones that are
---schedule to run (actions in actionsToAdd and actions arrays) with a
---specific tag.
---
---Composable actions are counted as 1 action. Example:
---If you are running 1 Sequence of 7 actions, it will return 1.
---If you are running 7 Sequences of 2 actions, it will return 7.
---
---@param tag integer # The tag that will be searched.
---
---@return integer # The number of actions that are running plus the
---ones that are schedule to run with specific tag.
function Node:getNumberOfRunningActionsByTag(tag) end

---Get the callback of event onEnter.
---@return fun() # A std:function<void()> callback.
function Node:getOnEnterCallback() end

---Get the callback of event EnterTransitionDidFinish.
---@return fun() # std::function<void()>
function Node:getOnEnterTransitionDidFinishCallback() end

---Get the callback of event onExit.
---@return fun() # A std::function<void()>.
function Node:getOnExitCallback() end

---Get the callback of event ExitTransitionDidStart.
---@return fun() # std::function<void()>
function Node:getOnExitTransitionDidStartCallback() end

---Return the node's opacity.
---@return integer # A GLubyte value.
function Node:getOpacity() end

---Returns a pointer to the parent node.
---
---\see `setParent(Node*)`
---
---@return cc.Node # s A pointer to the parent node.
function Node:getParent() end

---@return cc.AffineTransform
function Node:getParentToNodeAffineTransform() end

---Returns the matrix that transform parent's space coordinates to the node's (local) space coordinates.
---The matrix is in Pixels.
---
---@return cc.Mat4 # The transformation matrix.
function Node:getParentToNodeTransform() end

---@return cc.PhysicsBody
function Node:getPhysicsBody() end

---Gets the position (x,y) of the node in its parent's coordinate system.
---
---\see setPosition(const Vec2&)
---
---@return cc.Vec2 # The position (x,y) of the node in OpenGL coordinates.
---\code
---In js and lua return value is table which contains x,y.
---\endcode
---
---Gets position in a more efficient way, returns two number instead of a Vec2 object.
---
---\see `setPosition(float, float)`
---In js,out value not return.
---
---\param x To receive x coordinate for position.
---\param y To receive y coordinate for position.
---@overload fun(self: cc.Node, x: olua.float, y: olua.float)
function Node:getPosition() end

---Returns the position (X,Y,Z) in its parent's coordinate system.
---
---@return cc.Vec3 # The position (X, Y, and Z) in its parent's coordinate system.
---\js NA
function Node:getPosition3D() end

---Returns the normalized position.
---
---@return cc.Vec2 # The normalized position.
function Node:getPositionNormalized() end

---Gets the x coordinate of the node in its parent's coordinate system.
---
---@return number # The x coordinate of the node.
function Node:getPositionX() end

---Gets the y coordinate of the node in its parent's coordinate system.
---
---@return number # The y coordinate of the node.
function Node:getPositionY() end

---Gets position Z coordinate of this node.
---
---\see setPositionZ(float)
---
---@return number # The position Z coordinate of this node.
---\js getVertexZ
function Node:getPositionZ() end

---@return ccb.ProgramState
function Node:getProgramState() end

---Returns the rotation of the node in degrees.
---
---\see `setRotation(float)`
---
---@return number # The rotation of the node in degrees.
function Node:getRotation() end

---Returns the rotation (X,Y,Z) in degrees.
---
---@return cc.Vec3 # The rotation of the node in 3d.
---\js NA
function Node:getRotation3D() end

---Return the rotation by quaternion, Note that when _rotationZ_X == _rotationZ_Y, the returned quaternion equals to RotationZ_X * RotationY * RotationX,
---it equals to RotationY * RotationX otherwise.
---
---@return cc.Quaternion # The rotation in quaternion.
---\js NA
function Node:getRotationQuat() end

---Gets the X rotation (angle) of the node in degrees which performs a horizontal rotation skew.
---
---\see `setRotationSkewX(float)`
---
---@return number # The X rotation in degrees.
---\js getRotationX
function Node:getRotationSkewX() end

---Gets the Y rotation (angle) of the node in degrees which performs a vertical rotational skew.
---
---\see `setRotationSkewY(float)`
---
---@return number # The Y rotation in degrees.
---\js getRotationY
function Node:getRotationSkewY() end

---Gets the scale factor of the node,  when X and Y have the same scale factor.
---
---\warning Assert when `_scaleX != _scaleY`
---\see setScale(float)
---
---@return number # The scale factor of the node.
function Node:getScale() end

---Returns the scale factor on X axis of this node
---
---\see setScaleX(float)
---
---@return number # The scale factor on X axis.
function Node:getScaleX() end

---Returns the scale factor on Y axis of this node
---
---\see `setScaleY(float)`
---
---@return number # The scale factor on Y axis.
function Node:getScaleY() end

---Returns the scale factor on Z axis of this node
---
---\see `setScaleZ(float)`
---
---@return number # The scale factor on Z axis.
function Node:getScaleZ() end

---Returns the Scene that contains the Node.
---It returns `nullptr` if the node doesn't belong to any Scene.
---This function recursively calls parent->getScene() until parent is a Scene object. The results are not cached. It is that the user caches the results in case this functions is being used inside a loop.
---
---@return cc.Scene # The Scene that contains the node.
function Node:getScene() end

---Gets a Scheduler object.
---
---\see setScheduler(Scheduler*)
---@return cc.Scheduler # A Scheduler object.
function Node:getScheduler() end

---Returns the X skew angle of the node in degrees.
---
---\see `setSkewX(float)`
---
---@return number # The X skew angle of the node in degrees.
function Node:getSkewX() end

---Returns the Y skew angle of the node in degrees.
---
---\see `setSkewY(float)`
---
---@return number # The Y skew angle of the node in degrees.
function Node:getSkewY() end

---Returns a tag that is used to identify the node easily.
---
---@return integer # An integer that identifies the node.
---
---Please use `getTag()` instead.
function Node:getTag() end

---Returns a custom user data pointer.
---
---You can set everything in UserData pointer, a data block, a structure or an object.
---
---@return any # A custom user data pointer.
---\lua NA
function Node:getUserData() end

---Returns a user assigned Object.
---
---Similar to userData, but instead of holding a void* it holds an object.
---
---@return cc.Ref # A user assigned Object.
---\lua NA
function Node:getUserObject() end

---@param obj cc.Node
---@return number
function Node.getWidth(obj) end

---@return cc.AffineTransform
function Node:getWorldToNodeAffineTransform() end

---Returns the inverse world affine transform matrix. The matrix is in Pixels.
---
---@return cc.Mat4 # The transformation matrix.
function Node:getWorldToNodeTransform() end

---@return boolean
function Node:init() end

---Query whether cascadeColor is enabled or not.
---@return boolean # Whether cascadeColor is enabled or not.
function Node:isCascadeColorEnabled() end

---Whether cascadeOpacity is enabled or not.
---@return boolean # A boolean value.
function Node:isCascadeOpacityEnabled() end

---Gets whether the anchor point will be (0,0) when you position this node.
---
---\see `setIgnoreAnchorPointForPosition(bool)`
---
---@return boolean # true if the anchor point will be (0,0) when you position this node.
function Node:isIgnoreAnchorPointForPosition() end

---If node opacity will modify the RGB color value, then you should override this method and return true.
---@return boolean # A boolean value, true indicates that opacity will modify color; false otherwise.
function Node:isOpacityModifyRGB() end

---Returns whether or not the node is "running".
---
---If the node is running it will accept event callbacks like onEnter(), onExit(), update().
---
---@return boolean # Whether or not the node is running.
function Node:isRunning() end

---Checks whether a lambda function is scheduled.
---
---@param key string # key of the callback
---@return boolean # Whether the lambda function selector is scheduled.
---\js NA
---\lua NA
function Node:isScheduled(key) end

---Determines if the node is visible.
---
---\see `setVisible(bool)`
---
---@return boolean # true if the node is visible, false if the node is hidden.
function Node:isVisible() end

---@return cc.Node
function Node.new() end

---Event callback that is invoked every time when Node enters the 'stage'.
---If the Node enters the 'stage' with a transition, this event is called when the transition starts.
---During onEnter you can't access a "sister/brother" node.
---If you override onEnter, you shall call its parent's one, e.g., Node::onEnter().
---\lua NA
function Node:onEnter() end

---Event callback that is invoked when the Node enters in the 'stage'.
---If the Node enters the 'stage' with a transition, this event is called when the transition finishes.
---If you override onEnterTransitionDidFinish, you shall call its parent's one, e.g. Node::onEnterTransitionDidFinish()
---\lua NA
function Node:onEnterTransitionDidFinish() end

---Event callback that is invoked every time the Node leaves the 'stage'.
---If the Node leaves the 'stage' with a transition, this event is called when the transition finishes.
---During onExit you can't access a sibling node.
---If you override onExit, you shall call its parent's one, e.g., Node::onExit().
---\lua NA
function Node:onExit() end

---Event callback that is called every time the Node leaves the 'stage'.
---If the Node leaves the 'stage' with a transition, this callback is called when the transition starts.
---\lua NA
function Node:onExitTransitionDidStart() end

---Pauses all scheduled selectors, actions and event listeners.
---This method is called internally by onExit.
function Node:pause() end

---Removes all children from the container with a cleanup.
---
---\see `removeAllChildrenWithCleanup(bool)`
function Node:removeAllChildren() end

---Removes all children from the container, and do a cleanup to all running actions depending on the cleanup parameter.
---
---@param cleanup boolean # True if all running actions on all children nodes should be cleanup, false otherwise.
---\js removeAllChildren
---\lua removeAllChildren
function Node:removeAllChildrenWithCleanup(cleanup) end

---Removes all components
function Node:removeAllComponents() end

---Removes a child from the container. It will also cleanup all running actions depending on the cleanup parameter.
---
---@param child cc.Node # The child node which will be removed.
---@param cleanup boolean # True if all running actions and callbacks on the child node will be cleanup, false otherwise.
---@overload fun(self: cc.Node, child: cc.Node)
function Node:removeChild(child, cleanup) end

---Removes a child from the container by tag value. It will also cleanup all running actions depending on the cleanup parameter.
---
---@param name string # A string that identifies a child node.
---@param cleanup boolean # True if all running actions and callbacks on the child node will be cleanup, false otherwise.
---@overload fun(self: cc.Node, name: string)
function Node:removeChildByName(name, cleanup) end

---Removes a child from the container by tag value. It will also cleanup all running actions depending on the cleanup parameter.
---
---@param tag integer # An integer number that identifies a child node.
---@param cleanup boolean # True if all running actions and callbacks on the child node will be cleanup, false otherwise.
---
---Please use `removeChildByName` instead.
---@overload fun(self: cc.Node, tag: integer)
function Node:removeChildByTag(tag, cleanup) end

---Removes a component by its name.
---
---@param name string # A given name of component.
---@return boolean # True if removed success.
---
---Removes a component by its pointer.
---
---\param component A given component.
---\return True if removed success.
---@overload fun(self: cc.Node, component: cc.Component): boolean
function Node:removeComponent(name) end

---Removes this node itself from its parent node with a cleanup.
---If the node orphan, then nothing happens.
---\see `removeFromParentAndCleanup(bool)`
function Node:removeFromParent() end

---Removes this node itself from its parent node.
---If the node orphan, then nothing happens.
---@param cleanup boolean # true if all actions and callbacks on this node should be removed, false otherwise.
---\js removeFromParent
---\lua removeFromParent
function Node:removeFromParentAndCleanup(cleanup) end

---Reorders a child according to a new z value.
---
---@param child cc.Node # An already added child node. It MUST be already added.
---@param localZOrder integer # Z order for drawing priority. Please refer to setLocalZOrder(int).
function Node:reorderChild(child, localZOrder) end

---Resumes all scheduled selectors, actions and event listeners.
---This method is called internally by onEnter.
function Node:resume() end

---Executes an action, and returns the action that is executed.
---
---This node becomes the action's target. Refer to Action::getTarget().
---\warning Actions don't retain their target.
---
---@param action cc.Action # An Action pointer.
---@return cc.Action
function Node:runAction(action) end

---Schedules a lambda function. The scheduled lambda function will be called every frame.
---
---@param callback fun(arg1: number) # The lambda function to be scheduled.
---@param key string # The key of the lambda function. To be used if you want to unschedule it.
---\lua NA
---
---Schedules a lambda function. The scheduled lambda function will be called every "interval" seconds
---
---\param callback      The lambda function to be scheduled
---\param interval      Callback interval time in seconds. 0 means every frame,
---\param key           The key of the lambda function. To be used if you want to unschedule it
---\lua NA
---@overload fun(self: cc.Node, callback: fun(arg1: number), interval: number, key: string)
---
---Schedules a lambda function.
---
---\param callback  The lambda function to be schedule.
---\param interval  Tick interval in seconds. 0 means tick every frame.
---\param repeat    The selector will be executed (repeat + 1) times, you can use CC_REPEAT_FOREVER for tick infinitely.
---\param delay     The amount of time that the first tick will wait before execution.
---\param key       The key of the lambda function. To be used if you want to unschedule it.
---\lua NA
---@overload fun(self: cc.Node, callback: fun(arg1: number), interval: number, repeat_: integer, delay: number, key: string)
function Node:schedule(callback, key) end

---Schedules a lambda function that runs only once, with a delay of 0 or larger
---
---@param callback fun(arg1: number) # The lambda function to be scheduled.
---@param delay number # The amount of time that the first tick will wait before execution.
---@param key string # The key of the lambda function. To be used if you want to unschedule it.
---\lua NA
function Node:scheduleOnce(callback, delay, key) end

---Schedules the "update" method.
---
---It will use the order number 0. This method will be called every frame.
---Scheduled methods with a lower order value will be called before the ones that have a higher order value.
---Only one "update" method could be scheduled per node.
---\lua NA
function Node:scheduleUpdate() end

---Schedules the "update" method with a custom priority.
---
---This selector will be called every frame.
---Scheduled methods with a lower priority will be called before the ones that have a higher value.
---Only one "update" selector could be scheduled per node (You can't have 2 'update' selectors).
---\lua NA
---
---@param priority integer # A given priority value.
function Node:scheduleUpdateWithPriority(priority) end

---Sets the ActionManager object that is used by all actions.
---
---\warning If you set a new ActionManager, then previously created actions will be removed.
---
---@param actionManager cc.ActionManager # A ActionManager object that is used by all actions.
function Node:setActionManager(actionManager) end

---Sets an additional transform matrix to the node.
---
---In order to remove it, call it again with the argument `nullptr`.
---
---\note The additional transform will be concatenated at the end of getNodeToParentTransform.
---It could be used to simulate `parent-child` relationship between two nodes (e.g. one is in BatchNode, another isn't).
---
---@param additionalTransform cc.Mat4 # An additional transform matrix.
---@overload fun(self: cc.Node, additionalTransform: cc.Mat4)
---@overload fun(self: cc.Node, additionalTransform: cc.AffineTransform)
function Node:setAdditionalTransform(additionalTransform) end

---@param obj cc.Node
---@param value number
function Node.setAlpha(obj, value) end

---Sets the anchor point in percent.
---
---anchorPoint is the point around which all transformations and positioning manipulations take place.
---It's like a pin in the node where it is "attached" to its parent.
---The anchorPoint is normalized, like a percentage. (0,0) means the bottom-left corner and (1,1) means the top-right corner.
---But you can use values higher than (1,1) and lower than (0,0) too.
---The default anchorPoint is (0,0), so it starts in the lower left corner of the node.
---\note If node has a physics body, the anchor must be in the middle, you can't change this to other value.
---
---@param anchorPoint cc.Vec2 # The anchor point of node.
function Node:setAnchorPoint(anchorPoint) end

---@param obj cc.Node
---@param value number
function Node.setAnchorX(obj, value) end

---@param obj cc.Node
---@param value number
function Node.setAnchorY(obj, value) end

---Modify the camera mask for current node.
---If applyChildren is true, then it will modify the camera mask of its children recursively.
---@param mask integer # A unsigned short bit for mask.
---@param applyChildren boolean # A boolean value to determine whether the mask bit should apply to its children or not.
---@overload fun(self: cc.Node, mask: integer)
function Node:setCameraMask(mask, applyChildren) end

---If you want node's color affect the children node's color, then set it to true.
---Otherwise, set it to false.
---@param cascadeColorEnabled boolean # A boolean value.
function Node:setCascadeColorEnabled(cascadeColorEnabled) end

---Change node's cascadeOpacity property.
---@param cascadeOpacityEnabled boolean # True to enable cascadeOpacity, false otherwise.
function Node:setCascadeOpacityEnabled(cascadeOpacityEnabled) end

---Change the color of node.
---@param color any # A Color3B color value.
function Node:setColor(color) end

---Sets the untransformed size of the node.
---
---The contentSize remains the same no matter the node is scaled or rotated.
---All nodes has a size. Layer and Scene has the same size of the screen.
---
---@param contentSize cc.Size # The untransformed size of the node.
function Node:setContentSize(contentSize) end

---Set event dispatcher for scene.
---
---@param dispatcher cc.EventDispatcher # The event dispatcher of scene.
function Node:setEventDispatcher(dispatcher) end

---Defines the order in which the nodes are renderer.
---Nodes that have a Global Z Order lower, are renderer first.
---
---In case two or more nodes have the same Global Z Order, the order is not guaranteed.
---The only exception if the Nodes have a Global Z Order == 0. In that case, the Scene Graph order is used.
---
---By default, all nodes have a Global Z Order = 0. That means that by default, the Scene Graph order is used to render the nodes.
---
---Global Z Order is useful when you need to render nodes in an order different than the Scene Graph order.
---
---Limitations: Global Z Order can't be used by Nodes that have SpriteBatchNode as one of their ancestors.
---And if ClippingNode is one of the ancestors, then "global Z order" will be relative to the ClippingNode.
---\see `setLocalZOrder()`
---\see `setVertexZ()`
---\since v3.0
---
---@param globalZOrder number # The global Z order value.
function Node:setGlobalZOrder(globalZOrder) end

---@param obj cc.Node
---@param value number
function Node.setHeight(obj, value) end

---Sets whether the anchor point will be (0,0) when you position this node.
---
---This is an internal method, only used by Layer and Scene. Don't call it outside framework.
---The default value is false, while in Layer and Scene are true.
---
---@param ignore boolean # true if anchor point will be (0,0) when you position this node.
function Node:setIgnoreAnchorPointForPosition(ignore) end

---LocalZOrder is the 'key' used to sort the node relative to its siblings.
---The Node's parent will sort all its children based on the LocalZOrder value.
---If two nodes have the same LocalZOrder, then the node that was added first to the children's array will be in front of the other node in the array.
---
---Also, the Scene Graph is traversed using the "In-Order" tree traversal algorithm ( http://en.wikipedia.org/wiki/Tree_traversal#In-order )
---And Nodes that have LocalZOrder values < 0 are the "left" subtree
---While Nodes with LocalZOrder >=0 are the "right" subtree.
---
---\see `setGlobalZOrder`
---\see `setVertexZ`
---
---@param localZOrder integer # The local Z order value.
function Node:setLocalZOrder(localZOrder) end

---Changes the name that is used to identify the node easily.
---@param name string # A string that identifies the node.
---
---\since v3.2
function Node:setName(name) end

---Sets the transformation matrix manually.
---
---@param transform cc.Mat4 # A given transformation matrix.
function Node:setNodeToParentTransform(transform) end

---@param position cc.Vec2
function Node:setNormalizedPosition(position) end

---Set the callback of event onEnter.
---@param callback fun() # A std::function<void()> callback.
function Node:setOnEnterCallback(callback) end

---Set the callback of event EnterTransitionDidFinish.
---@param callback fun() # A std::function<void()> callback.
function Node:setOnEnterTransitionDidFinishCallback(callback) end

---Set the callback of event onExit.
---@param callback fun() # A std::function<void()> callback.
function Node:setOnExitCallback(callback) end

---Set the callback of event ExitTransitionDidStart.
---@param callback fun() # A std::function<void()> callback.
function Node:setOnExitTransitionDidStartCallback(callback) end

---Change node opacity.
---@param opacity integer # A GLubyte opacity value.
function Node:setOpacity(opacity) end

---If you want the opacity affect the color property, then set to true.
---@param value boolean # A boolean value.
function Node:setOpacityModifyRGB(value) end

---Sets the parent node.
---
---@param parent cc.Node # A pointer to the parent node.
function Node:setParent(parent) end

---@param physicsBody cc.PhysicsBody
function Node:setPhysicsBody(physicsBody) end

---Sets the position (x,y) of the node in its parent's coordinate system.
---
---Usually we use `Vec2(x,y)` to compose Vec2 object.
---This code snippet sets the node in the center of screen.
---\code
---Size size = Director::getInstance()->getWinSize();
---node->setPosition(size.width/2, size.height/2);
---\endcode
---
---@param position cc.Vec2 # The position (x,y) of the node in OpenGL coordinates.
---
---Sets the position (x,y) of the node in its parent's coordinate system.
---
---Passing two numbers (x,y) is much efficient than passing Vec2 object.
---This method is bound to Lua and JavaScript.
---Passing a number is 10 times faster than passing a object from Lua to c++.
---
---\code
---sample code in Lua
---local pos  = node::getPosition()  -- returns Vec2 object from C++.
---node:setPosition(x, y)            -- pass x, y coordinate to C++.
---\endcode
---
---\param x     X coordinate for position.
---\param y     Y coordinate for position.
---@overload fun(self: cc.Node, x: number, y: number)
function Node:setPosition(position) end

---Sets the position (X, Y, and Z) in its parent's coordinate system.
---
---@param position cc.Vec3 # The position (X, Y, and Z) in its parent's coordinate system.
---\js NA
function Node:setPosition3D(position) end

---Sets the position (x,y) using values between 0 and 1.
---The positions in pixels is calculated like the following:
---\code
---pseudo code
---void setNormalizedPosition(Vec2 pos) {
---Size s = getParent()->getContentSize();
---_position = pos * s;
---}
---\endcode
---
---@param position cc.Vec2 # The normalized position (x,y) of the node, using value between 0 and 1.
function Node:setPositionNormalized(position) end

---Gets/Sets x or y coordinate individually for position.
---These methods are used in Lua and Javascript Bindings
---
---Sets the x coordinate of the node in its parent's coordinate system.
---
---@param x number # The x coordinate of the node.
function Node:setPositionX(x) end

---Sets the y coordinate of the node in its parent's coordinate system.
---
---@param y number # The y coordinate of the node.
function Node:setPositionY(y) end

---Sets the 'z' coordinate in the position. It is the OpenGL Z vertex value.
---
---The OpenGL depth buffer and depth testing are disabled by default. You need to turn them on.
---In order to use this property correctly.
---
---`setPositionZ()` also sets the `setGlobalZValue()` with the positionZ as value.
---
---\see `setGlobalZValue()`
---
---@param positionZ number # OpenGL Z vertex of this node.
---\js setVertexZ
function Node:setPositionZ(positionZ) end

---@param programState ccb.ProgramState
function Node:setProgramState(programState) end

---Sets the rotation (angle) of the node in degrees.
---
---0 is the default rotation angle.
---Positive values rotate node clockwise, and negative values for anti-clockwise.
---
---@param rotation number # The rotation of the node in degrees.
function Node:setRotation(rotation) end

---Sets the rotation (X,Y,Z) in degrees.
---Useful for 3d rotations.
---
---\warning The physics body doesn't support this.
---
---@param rotation cc.Vec3 # The rotation of the node in 3d.
---\js NA
function Node:setRotation3D(rotation) end

---Set rotation by quaternion. You should make sure the quaternion is normalized.
---
---@param quat cc.Quaternion # The rotation in quaternion, note that the quat must be normalized.
---\js NA
function Node:setRotationQuat(quat) end

---Sets the X rotation (angle) of the node in degrees which performs a horizontal rotational skew.
---
---The difference between `setRotationalSkew()` and `setSkew()` is that the first one simulate Flash's skew functionality,
---while the second one uses the real skew function.
---
---0 is the default rotation angle.
---Positive values rotate node clockwise, and negative values for anti-clockwise.
---
---@param rotationX number # The X rotation in degrees which performs a horizontal rotational skew.
---
---\warning The physics body doesn't support this.
---\js setRotationX
function Node:setRotationSkewX(rotationX) end

---Sets the Y rotation (angle) of the node in degrees which performs a vertical rotational skew.
---
---The difference between `setRotationalSkew()` and `setSkew()` is that the first one simulate Flash's skew functionality,
---while the second one uses the real skew function.
---
---0 is the default rotation angle.
---Positive values rotate node clockwise, and negative values for anti-clockwise.
---
---@param rotationY number # The Y rotation in degrees.
---
---\warning The physics body doesn't support this.
---\js setRotationY
function Node:setRotationSkewY(rotationY) end

---Sets the scale (x,y,z) of the node.
---
---It is a scaling factor that multiplies the width, height and depth of the node and its children.
---
---@param scale number # The scale factor for both X and Y axis.
---
---\warning The physics body doesn't support this.
---
---Sets the scale (x,y) of the node.
---
---It is a scaling factor that multiplies the width and height of the node and its children.
---
---\param scaleX     The scale factor on X axis.
---\param scaleY     The scale factor on Y axis.
---
---\warning The physics body doesn't support this.
---@overload fun(self: cc.Node, scaleX: number, scaleY: number)
function Node:setScale(scale) end

---Sets the scale (x) of the node.
---
---It is a scaling factor that multiplies the width of the node and its children.
---
---@param scaleX number # The scale factor on X axis.
---
---\warning The physics body doesn't support this.
function Node:setScaleX(scaleX) end

---Sets the scale (y) of the node.
---
---It is a scaling factor that multiplies the height of the node and its children.
---
---@param scaleY number # The scale factor on Y axis.
---
---\warning The physics body doesn't support this.
function Node:setScaleY(scaleY) end

---Changes the scale factor on Z axis of this node
---
---The Default value is 1.0 if you haven't changed it before.
---
---@param scaleZ number # The scale factor on Z axis.
---
---\warning The physics body doesn't support this.
function Node:setScaleZ(scaleZ) end

---Sets a Scheduler object that is used to schedule all "updates" and timers.
---
---\warning If you set a new Scheduler, then previously created timers/update are going to be removed.
---@param scheduler cc.Scheduler # A Scheduler object that is used to schedule all "update" and timers.
function Node:setScheduler(scheduler) end

---Changes the X skew angle of the node in degrees.
---
---The difference between `setRotationalSkew()` and `setSkew()` is that the first one simulate Flash's skew functionality
---while the second one uses the real skew function.
---
---This angle describes the shear distortion in the X direction.
---Thus, it is the angle between the Y coordinate and the left edge of the shape
---The default skewX angle is 0. Positive values distort the node in a CW direction.
---
---@param skewX number # The X skew angle of the node in degrees.
---
---\warning The physics body doesn't support this.
function Node:setSkewX(skewX) end

---Changes the Y skew angle of the node in degrees.
---
---The difference between `setRotationalSkew()` and `setSkew()` is that the first one simulate Flash's skew functionality
---while the second one uses the real skew function.
---
---This angle describes the shear distortion in the Y direction.
---Thus, it is the angle between the X coordinate and the bottom edge of the shape.
---The default skewY angle is 0. Positive values distort the node in a CCW direction.
---
---@param skewY number # The Y skew angle of the node in degrees.
---
---\warning The physics body doesn't support this.
function Node:setSkewY(skewY) end

---Changes the tag that is used to identify the node easily.
---
---Please refer to getTag for the sample code.
---
---@param tag integer # A integer that identifies the node.
---
---Please use `setName()` instead.
function Node:setTag(tag) end

---Sets a custom user data pointer.
---
---You can set everything in UserData pointer, a data block, a structure or an object, etc.
---\warning Don't forget to release the memory manually,
---especially before you change this data pointer, and before this node is autoreleased.
---
---@param userData any # A custom user data pointer.
---\lua NA
function Node:setUserData(userData) end

---Returns a user assigned Object.
---
---Similar to UserData, but instead of holding a void* it holds an object.
---The UserObject will be retained once in this method,
---and the previous UserObject (if existed) will be released.
---The UserObject will be released in Node's destructor.
---
---@param userObject cc.Ref # A user assigned Object.
function Node:setUserObject(userObject) end

---Sets whether the node is visible.
---
---The default value is true, a node is default to visible.
---
---@param visible boolean # true if the node is visible, false if the node is hidden.
function Node:setVisible(visible) end

---@param obj cc.Node
---@param value number
function Node.setWidth(obj, value) end

---Sorts the children array once before drawing, instead of every time when a child is added or reordered.
---This approach can improve the performance massively.
---\note Don't call this manually unless a child added needs to be removed in the same frame.
function Node:sortAllChildren() end

---Stops and removes an action from the running action list.
---
---@param action cc.Action # The action object to be removed.
function Node:stopAction(action) end

---Removes an action from the running action list by its tag.
---
---@param tag integer # A tag that indicates the action to be removed.
function Node:stopActionByTag(tag) end

---Removes all actions from the running action list by its flags.
---
---@param flags integer # A flag field that removes actions based on bitwise AND.
function Node:stopActionsByFlags(flags) end

---Stops and removes all actions from the running action list .
function Node:stopAllActions() end

---Removes all actions from the running action list by its tag.
---
---@param tag integer # A tag that indicates the action to be removed.
function Node:stopAllActionsByTag(tag) end

---Unschedules a lambda function.
---
---@param key string # The key of the lambda function to be unscheduled.
---\lua NA
function Node:unschedule(key) end

---Unschedule all scheduled selectors and lambda functions: custom selectors, and the 'update' selector and lambda functions.
---Actions are not affected by this method.
---\lua NA
function Node:unscheduleAllCallbacks() end

function Node:unscheduleUpdate() end

---Update method will be called automatically every frame if "scheduleUpdate" is called, and the node is "live".
---@param delta number # In seconds.
function Node:update(delta) end

---Update node's displayed color with its parent color.
---@param parentColor any # A Color3B color value.
function Node:updateDisplayedColor(parentColor) end

---Update the displayed opacity of node with it's parent opacity;
---@param parentOpacity integer # The opacity of parent node.
function Node:updateDisplayedOpacity(parentOpacity) end

---!!! ONLY FOR INTERNAL USE
---Sets the arrival order when this node has a same ZOrder with other children.
---
---A node which called addChild subsequently will take a larger arrival order,
---If two children have the same Z order, the child with larger arrival order will be drawn later.
---
---\warning This method is used internally for localZOrder sorting, don't change this manually
---
---\param orderOfArrival   The arrival order.
function Node:updateOrderOfArrival() end

---Calls children's updateTransform() method recursively.
---
---This method is moved from Sprite, so it's no longer specific to Sprite.
---As the result, you apply SpriteBatchNode's optimization on your customed Node.
---e.g., `batchNode->addChild(myCustomNode)`, while you can only addChild(sprite) before.
function Node:updateTransform() end

---Visits this node's children and draw them recursively.
---
---@param renderer cc.Renderer # A given renderer.
---@param parentTransform cc.Mat4 # A transform matrix.
---@param parentFlags integer # Renderer flag.
---@overload fun(self: cc.Node)
function Node:visit(renderer, parentTransform, parentFlags) end

return Node