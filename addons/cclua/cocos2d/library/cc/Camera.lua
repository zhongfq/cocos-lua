---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Camera

---Defines a camera .
---@class cc.Camera : cc.Node
---@field backgroundBrush cc.CameraBackgroundBrush Get clear brush
---@field brushValid boolean 
---@field cameraFlag cc.CameraFlag get & set Camera flag
---@field defaultCamera cc.Camera Get the default camera of the current running scene.
---@field defaultViewport cc.Viewport 
---@field depth integer get depth, camera with larger depth is drawn on top of camera with smaller depth, the depth of camera with CameraFlag::DEFAULT is 0, user defined camera is -1 by default
---@field farPlane number Get the frustum's far plane.
---@field nearPlane number Get the frustum's near plane.
---@field projectionMatrix cc.Mat4 Gets the camera's projection matrix. <br><br>\return The camera projection matrix.
---@field renderOrder integer get rendered order
---@field type cc.Camera.Type Gets the type of camera. <br><br>\return The camera type.
---@field viewMatrix cc.Mat4 Gets the camera's view matrix. <br><br>\return The camera view matrix.
---@field viewProjectionMatrix cc.Mat4 get view projection matrix
---@field viewProjectionUpdated boolean Whether or not the viewprojection matrix was updated since the last frame. \return True if the viewprojection matrix was updated since the last frame.
---@field visitingCamera cc.Camera Get the visiting camera , the visiting camera shall be set on Scene::render
local Camera = {}

---Apply the FBO, RenderTargets and viewport.
function Camera:apply() end

function Camera:applyViewport() end

---Before rendering scene with this camera, the background need to be cleared. It clears the depth buffer with max depth by default. Use setBackgroundBrush to modify the default behavior
function Camera:clearBackground() end

---create default camera, the camera type depends on Director::getProjection, the depth of the default camera is 0
---@return cc.Camera
function Camera.create() end

---Creates an orthographic camera.
---
---@param zoomX number # The zoom factor along the X-axis of the orthographic projection (the width of the ortho projection).
---@param zoomY number # The zoom factor along the Y-axis of the orthographic projection (the height of the ortho projection).
---@param nearPlane number # The near plane distance.
---@param farPlane number # The far plane distance.
---@return cc.Camera
function Camera.createOrthographic(zoomX, zoomY, nearPlane, farPlane) end

---Creates a perspective camera.
---
---@param fieldOfView number # The field of view for the perspective camera (normally in the range of 40-60 degrees).
---@param aspectRatio number # The aspect ratio of the camera (normally the width of the viewport divided by the height of the viewport).
---@param nearPlane number # The near plane distance.
---@param farPlane number # The far plane distance.
---@return cc.Camera
function Camera.createPerspective(fieldOfView, aspectRatio, nearPlane, farPlane) end

---Get clear brush
---@return cc.CameraBackgroundBrush
function Camera:getBackgroundBrush() end

---get & set Camera flag
---@return cc.CameraFlag
function Camera:getCameraFlag() end

---Get the default camera of the current running scene.
---@return cc.Camera
function Camera.getDefaultCamera() end

---@return cc.Viewport
function Camera.getDefaultViewport() end

---get depth, camera with larger depth is drawn on top of camera with smaller depth, the depth of camera with CameraFlag::DEFAULT is 0, user defined camera is -1 by default
---@return integer
function Camera:getDepth() end

---Get object depth towards camera
---@param transform cc.Mat4
---@return number
function Camera:getDepthInView(transform) end

---Get the frustum's far plane.
---@return number
function Camera:getFarPlane() end

---Get the frustum's near plane.
---@return number
function Camera:getNearPlane() end

---Gets the camera's projection matrix.
---
---@return cc.Mat4 # The camera projection matrix.
function Camera:getProjectionMatrix() end

---get rendered order
---@return integer
function Camera:getRenderOrder() end

---Gets the type of camera.
---
---@return cc.Camera.Type # The camera type.
function Camera:getType() end

---Gets the camera's view matrix.
---
---@return cc.Mat4 # The camera view matrix.
function Camera:getViewMatrix() end

---get view projection matrix
---@return cc.Mat4
function Camera:getViewProjectionMatrix() end

---Get the visiting camera , the visiting camera shall be set on Scene::render
---@return cc.Camera
function Camera.getVisitingCamera() end

---init camera
---@return boolean
function Camera:initDefault() end

---@param zoomX number
---@param zoomY number
---@param nearPlane number
---@param farPlane number
---@return boolean
function Camera:initOrthographic(zoomX, zoomY, nearPlane, farPlane) end

---@param fieldOfView number
---@param aspectRatio number
---@param nearPlane number
---@param farPlane number
---@return boolean
function Camera:initPerspective(fieldOfView, aspectRatio, nearPlane, farPlane) end

---@return boolean
function Camera:isBrushValid() end

---Whether or not the viewprojection matrix was updated since the last frame.
---@return boolean # True if the viewprojection matrix was updated since the last frame.
function Camera:isViewProjectionUpdated() end

---Make Camera looks at target
---
---@param target cc.Vec3 # The target camera is point at
---@param up cc.Vec3 # The up vector, usually it's Y axis
---@overload fun(self: cc.Camera, target: cc.Vec3)
function Camera:lookAt(target, up) end

---@return cc.Camera
function Camera.new() end

---@param src cc.Vec3
---@return cc.Vec2
function Camera:project(src) end

---@param src cc.Vec3
---@return cc.Vec2
function Camera:projectGL(src) end

---set additional matrix for the projection matrix, it multiplies mat to projection matrix when called, used by WP8
---@param mat cc.Mat4
function Camera:setAdditionalProjection(mat) end

---set the background brush. See CameraBackgroundBrush for more information.
---@param clearBrush cc.CameraBackgroundBrush # Brush used to clear the background
function Camera:setBackgroundBrush(clearBrush) end

---@param flag cc.CameraFlag
function Camera:setCameraFlag(flag) end

---@param vp cc.Viewport
function Camera.setDefaultViewport(vp) end

---set depth, camera with larger depth is drawn on top of camera with smaller depth, the depth of camera with CameraFlag::DEFAULT is 0, user defined camera is -1 by default
---@param depth integer
function Camera:setDepth(depth) end

---Set the scene,this method shall not be invoke manually
---@param scene cc.Scene
function Camera:setScene(scene) end

---Convert the specified point of screen-space coordinate into the 3D world-space coordinate.
---
---Origin point at left top corner in screen-space.
---@param src cc.Vec3 # The screen-space position.
---@return cc.Vec3 # The 3D world-space position.
---
---Convert the specified point of screen-space coordinate into the 3D world-space coordinate.
---
---Origin point at left top corner in screen-space.
---\param size The window size to use.
---\param src  The screen-space position.
---\param dst  The 3D world-space position.
---@overload fun(self: cc.Camera, size: cc.Size, src: cc.Vec3, dst: cc.Vec3)
function Camera:unproject(src) end

---Convert the specified point of GL-screen-space coordinate into the 3D world-space coordinate.
---
---Origin point at left bottom corner in GL-screen-space.
---@param src cc.Vec3 # The GL-screen-space position.
---@return cc.Vec3 # The 3D world-space position.
---
---Convert the specified point of GL-screen-space coordinate into the 3D world-space coordinate.
---
---Origin point at left bottom corner in GL-screen-space.
---\param size The window size to use.
---\param src  The GL-screen-space position.
---\param dst  The 3D world-space position.
---@overload fun(self: cc.Camera, size: cc.Size, src: cc.Vec3, dst: cc.Vec3)
function Camera:unprojectGL(src) end

return Camera