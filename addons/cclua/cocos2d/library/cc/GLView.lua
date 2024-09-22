---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.GLView

---\addtogroup platform
---\{
---
---
---By GLView you can operate the frame information of EGL view through some function.
---@class cc.GLView : cc.Ref
---@field allTouches cc.Touch[] Get list of all active touches. <br><br>\return A list of all active touches.
---@field contentScaleFactor number Only works on ios platform. Get Content Scale of the Factor.
---@field frameZoomFactor number Get zoom factor for frame. This methods are for debugging big resolution (e.g.new ipad) app on desktop. <br><br>\return The zoom factor for frame.
---@field glContextAttrs cc.GLContextAttrs Return the OpenGL context attrs.  <br><br>\return Return the OpenGL context attrs.
---@field openGLReady boolean Get whether opengl render system is ready, subclass must implement this method.
---@field resolutionPolicy cc.ResolutionPolicy Returns the current Resolution policy. <br><br>\return The current Resolution policy.
---@field retinaDisplay boolean Returns whether or not the view is in Retina Display mode. <br><br>\return Returns whether or not the view is in Retina Display mode.
---@field retinaFactor integer Get retina factor. <br><br>\return The retina factor.
---@field safeAreaRect cc.Rect Gets safe area rectangle
---@field scaleX number Get scale factor of the horizontal direction. <br><br>\return Scale factor of the horizontal direction.
---@field scaleY number Get scale factor of the vertical direction. <br><br>\return Scale factor of the vertical direction.
---@field scissorEnabled boolean Get whether GL_SCISSOR_TEST is enable. <br><br>\return Whether GL_SCISSOR_TEST is enable.
---@field scissorRect cc.Rect Get the current scissor rectangle. <br><br>\return The current scissor rectangle.
---@field viewName string Get the view name. <br><br>\return The view name.
---@field viewPortRect cc.Rect Get the opengl view port rectangle. <br><br>\return Return the opengl view port rectangle.
---@field visibleOrigin cc.Vec2 Get the visible origin point of opengl viewport. <br><br>\return The visible origin point of opengl viewport.
---@field visibleRect cc.Rect Get the visible rectangle of opengl viewport. <br><br>\return The visible rectangle of opengl viewport.
---@field visibleSize cc.Size Get the visible area size of opengl viewport. <br><br>\return The visible area size of opengl viewport.
local GLView = {}

---Force destroying EGL view, subclass must implement this method. 
---
---\lua endToLua
function GLView:end_() end

---Get list of all active touches.
---
---@return cc.Touch[] # A list of all active touches.
function GLView:getAllTouches() end

---Only works on ios platform. Get Content Scale of the Factor.
---@return number
function GLView:getContentScaleFactor() end

---Get design resolution size.
---Default resolution size is the same as 'getFrameSize'.
---
---@return cc.Size # The design resolution size.
function GLView:getDesignResolutionSize() end

---Get the frame size of EGL view.
---In general, it returns the screen size since the EGL view is a fullscreen view.
---
---@return cc.Size # The frame size of EGL view.
function GLView:getFrameSize() end

---Get zoom factor for frame. This methods are for
---debugging big resolution (e.g.new ipad) app on desktop.
---
---@return number # The zoom factor for frame.
function GLView:getFrameZoomFactor() end

---Return the OpenGL context attrs. 
---
---@return cc.GLContextAttrs # Return the OpenGL context attrs.
function GLView.getGLContextAttrs() end

---Returns the current Resolution policy.
---
---@return cc.ResolutionPolicy # The current Resolution policy.
function GLView:getResolutionPolicy() end

---Get retina factor.
---
---@return integer # The retina factor.
function GLView:getRetinaFactor() end

---Gets safe area rectangle
---@return cc.Rect
function GLView:getSafeAreaRect() end

---Get scale factor of the horizontal direction.
---
---@return number # Scale factor of the horizontal direction.
function GLView:getScaleX() end

---Get scale factor of the vertical direction.
---
---@return number # Scale factor of the vertical direction.
function GLView:getScaleY() end

---Get the current scissor rectangle.
---
---@return cc.Rect # The current scissor rectangle.
function GLView:getScissorRect() end

---Get the view name.
---
---@return string # The view name.
function GLView:getViewName() end

---Get the opengl view port rectangle.
---
---@return cc.Rect # Return the opengl view port rectangle.
function GLView:getViewPortRect() end

---Get the visible origin point of opengl viewport.
---
---@return cc.Vec2 # The visible origin point of opengl viewport.
function GLView:getVisibleOrigin() end

---Get the visible rectangle of opengl viewport.
---
---@return cc.Rect # The visible rectangle of opengl viewport.
function GLView:getVisibleRect() end

---Get the visible area size of opengl viewport.
---
---@return cc.Size # The visible area size of opengl viewport.
function GLView:getVisibleSize() end

---Get whether opengl render system is ready, subclass must implement this method.
---@return boolean
function GLView:isOpenGLReady() end

---Returns whether or not the view is in Retina Display mode.
---
---@return boolean # Returns whether or not the view is in Retina Display mode.
function GLView:isRetinaDisplay() end

---Get whether GL_SCISSOR_TEST is enable.
---
---@return boolean # Whether GL_SCISSOR_TEST is enable.
function GLView:isScissorEnabled() end

---Polls the events.
function GLView:pollEvents() end

---Renders a Scene with a Renderer
---This method is called directly by the Director
---@param scene cc.Scene
---@param renderer cc.Renderer
function GLView:renderScene(scene, renderer) end

---Only works on ios platform. Set Content Scale of the Factor.
---@param arg1 number
---@return boolean
function GLView:setContentScaleFactor(arg1) end

---Hide or Show the mouse cursor if there is one.
---
---\param isVisible Hide or Show the mouse cursor if there is one.
---@param arg1 boolean
function GLView:setCursorVisible(arg1) end

---Set default window icon (implemented for windows and linux).
---On windows it will use icon from .exe file (if included).
---On linux it will use default window icon.
function GLView:setDefaultIcon() end

---Set the design resolution size.
---@param width number # Design resolution width.
---@param height number # Design resolution height.
---@param resolutionPolicy cc.ResolutionPolicy # The resolution policy desired, you may choose:
---[1] EXACT_FIT Fill screen by stretch-to-fit: if the design resolution ratio of width to height is different from the screen resolution ratio, your game view will be stretched.
---[2] NO_BORDER Full screen without black border: if the design resolution ratio of width to height is different from the screen resolution ratio, two areas of your game view will be cut.
---[3] SHOW_ALL  Full screen with black border: if the design resolution ratio of width to height is different from the screen resolution ratio, two black borders will be shown.
function GLView:setDesignResolutionSize(width, height, resolutionPolicy) end

---Set the frame size of EGL view.
---
---@param width number # The width of the fram size.
---@param height number # The height of the fram size.
function GLView:setFrameSize(width, height) end

---Set zoom factor for frame. This methods are for
---debugging big resolution (e.g.new ipad) app on desktop.
---
---\param zoomFactor The zoom factor for frame.
---@param arg1 number
function GLView:setFrameZoomFactor(arg1) end

---Static method and member so that we can modify it on all platforms before create OpenGL context. 
---
---@param glContextAttrs cc.GLContextAttrs # The OpenGL context attrs.
function GLView.setGLContextAttrs(glContextAttrs) end

---Open or close IME keyboard , subclass must implement this method. 
---
---@param open boolean # Open or close IME keyboard.
function GLView:setIMEKeyboardState(open) end

---Set window icon (implemented for windows and linux).
---
---@param filename string # A path to image file, e.g., "icons/cusom.png".
---
---Set window icon (implemented for windows and linux).
---Best icon (based on size) will be auto selected.
---
---\param filelist The array contains icons.
---@overload fun(self: cc.GLView, filelist: string[])
function GLView:setIcon(filename) end

---Set Scissor rectangle with points.
---
---@param x number # Set the points of x.
---@param y number # Set the points of y.
---@param w number # Set the width of  the view port
---@param h number # Set the Height of the view port.
function GLView:setScissorInPoints(x, y, w, h) end

---Set the view name. 
---
---@param viewname string # A string will be set to the view as name.
function GLView:setViewName(viewname) end

---Set opengl view port rectangle with points.
---
---@param x number # Set the points of x.
---@param y number # Set the points of y.
---@param w number # Set the width of  the view port
---@param h number # Set the Height of the view port.
function GLView:setViewPortInPoints(x, y, w, h) end

---Exchanges the front and back buffers, subclass must implement this method.
function GLView:swapBuffers() end

---When the window is closed, it will return false if the platforms is Ios or Android.
---If the platforms is windows or Mac,it will return true.
---
---@return boolean # In ios and android it will return false,if in windows or Mac it will return true.
function GLView:windowShouldClose() end

return GLView