---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Scene

---\class Scene
---Scene is a subclass of Node that is used only as an abstract concept.
---
---Scene and Node are almost identical with the difference that Scene has its
---anchor point (by default) at the center of the screen.
---
---For the moment Scene has no other logic than that, but in future releases it might have
---additional logic.
---
---It is a good practice to use a Scene as the parent of all your nodes.
---
---Scene will create a default camera for you.
---@class cc.Scene : cc.Node
---@field cameras cc.Camera[] Get all cameras. <br><br>\return The vector of all cameras, ordered by camera depth. \js NA
---@field defaultCamera cc.Camera Get the default camera. \js NA \return The default camera of scene.
---@field lights cc.BaseLight[] Get lights. \return The vector of lights. \js NA
---@field navMesh cc.NavMesh get navigation mesh
---@field physicsWorld cc.PhysicsWorld Get the physics world of the scene. \return The physics world of the scene. \js NA
local Scene = {}

---Creates a new Scene object. 
---
---@return cc.Scene # An autoreleased Scene object.
function Scene.create() end

---Create a scene with physics.
---@return cc.Scene # An autoreleased Scene object with physics.
---\js NA
function Scene.createWithPhysics() end

---Creates a new Scene object with a predefined Size. 
---
---@param size cc.Size # The predefined size of scene.
---@return cc.Scene # An autoreleased Scene object.
---\js NA
function Scene.createWithSize(size) end

---Get all cameras.
---
---@return cc.Camera[] # The vector of all cameras, ordered by camera depth.
---\js NA
function Scene:getCameras() end

---Get the default camera.
---\js NA
---@return cc.Camera # The default camera of scene.
function Scene:getDefaultCamera() end

---Get lights.
---@return cc.BaseLight[] # The vector of lights.
---\js NA
function Scene:getLights() end

---get navigation mesh
---@return cc.NavMesh
function Scene:getNavMesh() end

---Get the physics world of the scene.
---@return cc.PhysicsWorld # The physics world of the scene.
---\js NA
function Scene:getPhysicsWorld() end

---@param size cc.Size
---@return boolean
function Scene:initWithSize(size) end

---@return cc.Scene
function Scene.new() end

---@param event cc.EventCustom
function Scene:onProjectionChanged(event) end

---Render the scene.
---@param renderer cc.Renderer # The renderer use to render the scene.
---@param eyeTransform cc.Mat4 # The AdditionalTransform of camera.
---@param eyeProjection cc.Mat4 # The projection matrix of camera.
---\js NA
---@overload fun(self: cc.Scene, renderer: cc.Renderer, eyeTransform: cc.Mat4)
function Scene:render(renderer, eyeTransform, eyeProjection) end

function Scene:setCameraOrderDirty() end

---set navigation mesh
---@param navMesh cc.NavMesh
function Scene:setNavMesh(navMesh) end

---Set NavMesh debug draw camera.
---@param camera cc.Camera
function Scene:setNavMeshDebugCamera(camera) end

---Set Physics3D debug draw camera.
---@param camera cc.Camera
function Scene:setPhysics3DDebugCamera(camera) end

---@param deltaTime number
function Scene:stepPhysicsAndNavigation(deltaTime) end

return Scene