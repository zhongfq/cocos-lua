---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Director

---Class that creates and handles the main Window and manages how
---and when to execute the Scenes.
---
---The Director is also responsible for:
---- initializing the OpenGL context
---- setting the OpenGL buffer depth (default one is 0-bit)
---- setting the projection (default one is 3D)
---
---Since the Director is a singleton, the standard way to use it is by calling:
---_ Director::getInstance()->methodName();
---@class cc.Director : cc.Ref
---@field actionManager cc.ActionManager Gets the ActionManager associated with this director. \since v2.0
---@field animationInterval number Gets the FPS value.
---@field console cc.Console Returns the Console associated with this director. \since v3.0 \js NA
---@field contentScaleFactor number Gets content scale factor. \see Director::setContentScaleFactor()
---@field deltaTime number 
---@field displayStats boolean Whether or not displaying the FPS on the bottom-left corner of the screen.
---@field eventDispatcher cc.EventDispatcher Gets the EventDispatcher associated with this director. \since v3.0 \js NA
---@field frameRate number Gets Frame Rate. \js NA
---@field instance cc.Director Returns a shared instance of the director.  \js _getInstance
---@field nextDeltaTimeZero boolean Whether or not `_nextDeltaTimeZero` is set to 0.
---@field notificationNode cc.Node This object will be visited after the main scene is visited. This object MUST implement the "visit" function. Useful to hook a notification object, like Notifications (http://github.com/manucorporat/CCNotifications) \since v0.99.5
---@field openGLView cc.GLView Get the GLView. \lua NA
---@field paused boolean Whether or not the Director is paused.
---@field projection cc.Director.Projection Gets an OpenGL projection. \since v0.8.2 \lua NA
---@field renderer cc.Renderer Returns the Renderer associated with this director. \since v3.0
---@field runningScene cc.Scene Gets current running Scene. Director can only run one Scene at a time.
---@field safeAreaRect cc.Rect Returns safe area rectangle of the OpenGL view in points.
---@field scheduler cc.Scheduler Gets the Scheduler associated with this director. \since v2.0
---@field secondsPerFrame number Get seconds per frame.
---@field sendCleanupToScene boolean Whether or not the replaced scene will receive the cleanup message. If the new scene is pushed, then the old scene won't receive the "cleanup" message. If the new scene replaces the old one, the it will receive the "cleanup" message. \since v0.99.0
---@field textureCache cc.TextureCache 
---@field totalFrames integer How many frames were called since the director started
---@field valid boolean returns whether or not the Director is in a valid state
---@field visibleOrigin cc.Vec2 Returns visible origin coordinate of the OpenGL view in points.
---@field visibleSize cc.Size Returns visible size of the OpenGL view in points. The value is equal to `Director::getWinSize()` if don't invoke `GLView::setDesignResolutionSize()`.
---@field winSize cc.Size Returns the size of the OpenGL view in points.
---@field winSizeInPixels cc.Size Returns the size of the OpenGL view in pixels.
---@field zEye number Gets the distance between camera and near clipping frame. It is correct for default camera that near clipping frame is same as the screen.
---@field EVENT_BEFORE_SET_NEXT_SCENE string
---@field EVENT_AFTER_SET_NEXT_SCENE string
---@field EVENT_PROJECTION_CHANGED string
---@field EVENT_BEFORE_UPDATE string
---@field EVENT_AFTER_UPDATE string
---@field EVENT_RESET string
---@field EVENT_AFTER_VISIT string
---@field EVENT_AFTER_DRAW string
---@field EVENT_BEFORE_DRAW string
local Director = {}

---Converts a screen coordinate to an OpenGL coordinate.
---Useful to convert (multi) touch coordinates to the current layout (portrait or landscape).
---@param point cc.Vec2
---@return cc.Vec2
---@overload fun(self: cc.Director, x: number, y: number): number, number
function Director:convertToGL(point) end

---Converts an OpenGL coordinate to a screen coordinate.
---Useful to convert node points to window points for calls such as glScissor.
---@param point cc.Vec2
---@return cc.Vec2
---@overload fun(self: cc.Director, x: number, y: number): number, number
function Director:convertToUI(point) end

---Draw the scene.
---This method is called every frame. Don't call it manually.
function Director:drawScene() end

---Ends the execution, releases the running scene.
---\lua endToLua
function Director:end_() end

---Gets the ActionManager associated with this director.
---\since v2.0
---@return cc.ActionManager
function Director:getActionManager() end

---Gets the FPS value.
---@return number
function Director:getAnimationInterval() end

---Returns the Console associated with this director.
---\since v3.0
---\js NA
---@return cc.Console
function Director:getConsole() end

---Gets content scale factor.
---\see Director::setContentScaleFactor()
---@return number
function Director:getContentScaleFactor() end

---@return number
function Director:getDeltaTime() end

---Gets the EventDispatcher associated with this director.
---\since v3.0
---\js NA
---@return cc.EventDispatcher
function Director:getEventDispatcher() end

---Gets Frame Rate.
---\js NA
---@return number
function Director:getFrameRate() end

---Returns a shared instance of the director. 
---\js _getInstance
---@return cc.Director
function Director.getInstance() end

---Gets the top matrix of specified type of matrix stack.
---\js NA
---@param type cc.MATRIX_STACK_TYPE
---@return cc.Mat4
function Director:getMatrix(type) end

---This object will be visited after the main scene is visited.
---This object MUST implement the "visit" function.
---Useful to hook a notification object, like Notifications (http://github.com/manucorporat/CCNotifications)
---\since v0.99.5
---@return cc.Node
function Director:getNotificationNode() end

---Get the GLView.
---\lua NA
---@return cc.GLView
function Director:getOpenGLView() end

---Gets an OpenGL projection.
---\since v0.8.2
---\lua NA
---@return cc.Director.Projection
function Director:getProjection() end

---Returns the Renderer associated with this director.
---\since v3.0
---@return cc.Renderer
function Director:getRenderer() end

---Gets current running Scene. Director can only run one Scene at a time.
---@return cc.Scene
function Director:getRunningScene() end

---Returns safe area rectangle of the OpenGL view in points.
---@return cc.Rect
function Director:getSafeAreaRect() end

---Gets the Scheduler associated with this director.
---\since v2.0
---@return cc.Scheduler
function Director:getScheduler() end

---Get seconds per frame.
---@return number
function Director:getSecondsPerFrame() end

---@return cc.TextureCache
function Director:getTextureCache() end

---How many frames were called since the director started
---@return integer
function Director:getTotalFrames() end

---Returns visible origin coordinate of the OpenGL view in points.
---@return cc.Vec2
function Director:getVisibleOrigin() end

---Returns visible size of the OpenGL view in points.
---The value is equal to `Director::getWinSize()` if don't invoke `GLView::setDesignResolutionSize()`.
---@return cc.Size
function Director:getVisibleSize() end

---Returns the size of the OpenGL view in points.
---@return cc.Size
function Director:getWinSize() end

---Returns the size of the OpenGL view in pixels.
---@return cc.Size
function Director:getWinSizeInPixels() end

---Gets the distance between camera and near clipping frame.
---It is correct for default camera that near clipping frame is same as the screen.
---@return number
function Director:getZEye() end

---@return boolean
function Director:init() end

---Whether or not displaying the FPS on the bottom-left corner of the screen.
---@return boolean
function Director:isDisplayStats() end

---Whether or not `_nextDeltaTimeZero` is set to 0.
---@return boolean
function Director:isNextDeltaTimeZero() end

---Whether or not the Director is paused.
---@return boolean
function Director:isPaused() end

---Whether or not the replaced scene will receive the cleanup message.
---If the new scene is pushed, then the old scene won't receive the "cleanup" message.
---If the new scene replaces the old one, the it will receive the "cleanup" message.
---\since v0.99.0
---@return boolean
function Director:isSendCleanupToScene() end

---returns whether or not the Director is in a valid state
---@return boolean
function Director:isValid() end

---Adds an identity matrix to the top of specified type of matrix stack.
---\js NA
---@param type cc.MATRIX_STACK_TYPE
function Director:loadIdentityMatrix(type) end

---Adds a matrix to the top of specified type of matrix stack.
---
---@param type cc.MATRIX_STACK_TYPE # Matrix type.
---@param mat cc.Mat4 # The matrix that to be added.
---\js NA
function Director:loadMatrix(type, mat) end

---
---Invoke main loop with delta time. Then `calculateDeltaTime` can just use the delta time directly.
---The delta time paseed may include vsync time. See issue #17806
---\since 3.16
---@overload fun(self: cc.Director, dt: number)
function Director:mainLoop() end

---Multiplies a matrix to the top of specified type of matrix stack.
---
---@param type cc.MATRIX_STACK_TYPE # Matrix type.
---@param mat cc.Mat4 # The matrix that to be multiplied.
---\js NA
function Director:multiplyMatrix(type, mat) end

---\js ctor
---@return cc.Director
function Director.new() end

---Pauses the running scene.
---The running scene will be _drawed_ but all scheduled timers will be paused.
---While paused, the draw rate will be 4 FPS to reduce CPU consumption.
function Director:pause() end

---Pops the top matrix of the specified type of matrix stack.
---\js NA
---@param type cc.MATRIX_STACK_TYPE
function Director:popMatrix(type) end

---Pops out a scene from the stack.
---This scene will replace the running one.
---The running scene will be deleted. If there are no more scenes in the stack the execution is terminated.
---ONLY call it if there is a running scene.
function Director:popScene() end

---Pops out all scenes from the stack until the root scene in the queue.
---This scene will replace the running one.
---Internally it will call `popToSceneStackLevel(1)`.
function Director:popToRootScene() end

---Pops out all scenes from the stack until it reaches `level`.
---If level is 0, it will end the director.
---If level is 1, it will pop all scenes until it reaches to root scene.
---If level is <= than the current stack level, it won't do anything.
---@param level integer
function Director:popToSceneStackLevel(level) end

---Removes all cocos2d cached data.
---It will purge the TextureCache, SpriteFrameCache, LabelBMFont cache
---\since v0.99.3
function Director:purgeCachedData() end

---Clones a specified type matrix and put it to the top of specified type of matrix stack.
---\js NA
---@param type cc.MATRIX_STACK_TYPE
function Director:pushMatrix(type) end

---Suspends the execution of the running scene, pushing it on the stack of suspended scenes.
---The new scene will be executed.
---Try to avoid big stacks of pushed scenes to reduce memory allocation. 
---ONLY call it if there is a running scene.
---@param scene cc.Scene
function Director:pushScene(scene) end

---Replaces the running scene with a new one. The running scene is terminated.
---ONLY call it if there is a running scene.
---\js NA
---@param scene cc.Scene
function Director:replaceScene(scene) end

---Clear all types of matrix stack, and add identity matrix to these matrix stacks.
---\js NA
function Director:resetMatrixStack() end

function Director:restart() end

---Resumes the paused scene.
---The scheduled timers will be activated again.
---The "delta time" will be 0 (as if the game wasn't paused).
function Director:resume() end

---Enters the Director's main loop with the given Scene.
---Call it to run only your FIRST scene.
---Don't call it if there is already a running scene.
---
---It will call pushScene: and then it will call startAnimation
---\js NA
---@param scene cc.Scene
function Director:runWithScene(scene) end

---Sets the ActionManager associated with this director.
---\since v2.0
---@param actionManager cc.ActionManager
function Director:setActionManager(actionManager) end

---Sets the FPS value. FPS = 1/interval.
---@param interval number
function Director:setAnimationInterval(interval) end

---Sets clear values for the color buffers,
---value range of each element is [0.0, 1.0].
---\js NA
---@param clearColor any
function Director:setClearColor(clearColor) end

---The size in pixels of the surface. It could be different than the screen size.
---High-res devices might have a higher surface size than the screen size.
---Only available when compiled using SDK >= 4.0.
---\since v0.99.4
---@param scaleFactor number
function Director:setContentScaleFactor(scaleFactor) end

---Sets the default values based on the Configuration info.
function Director:setDefaultValues() end

---Display the FPS on the bottom-left corner of the screen.
---@param displayStats boolean
function Director:setDisplayStats(displayStats) end

---Sets the EventDispatcher associated with this director.
---\since v3.0
---\js NA
---@param dispatcher cc.EventDispatcher
function Director:setEventDispatcher(dispatcher) end

---Sets the OpenGL default values.
---It will enable alpha blending, disable depth test.
---\js NA
function Director:setGLDefaultValues() end

---Sets the delta time between current frame and next frame is 0.
---This value will be used in Schedule, and will affect all functions that are using frame delta time, such as Actions.
---This value will take effect only one time.
---@param nextDeltaTimeZero boolean
function Director:setNextDeltaTimeZero(nextDeltaTimeZero) end

---Sets the notification node.
---\see Director::getNotificationNode()
---@param node cc.Node
function Director:setNotificationNode(node) end

---Sets the GLView. 
---\lua NA
---@param openGLView cc.GLView
function Director:setOpenGLView(openGLView) end

---Sets OpenGL projection.
---@param projection cc.Director.Projection
function Director:setProjection(projection) end

---Sets the Scheduler associated with this director.
---\since v2.0
---@param scheduler cc.Scheduler
function Director:setScheduler(scheduler) end

---Sets the glViewport.
function Director:setViewport() end

---The main loop is triggered again.
---Call this function only if [stopAnimation] was called earlier.
---\warning Don't call this function to start the main loop. To run the main loop call runWithScene.
function Director:startAnimation() end

---Stops the animation. Nothing will be drawn. The main loop won't be triggered anymore.
---If you don't want to pause your animation call [pause] instead.
function Director:stopAnimation() end

return Director