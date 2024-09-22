---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.NavMesh

---NavMesh: The NavMesh information container, include mesh, tileCache, and so on.
---@class cc.NavMesh : cc.Ref
---@field debugDrawEnabled boolean Check enabled debug draw.
local NavMesh = {}

---add a agent to navmesh.
---@param agent cc.NavMeshAgent
function NavMesh:addNavMeshAgent(agent) end

---add a obstacle to navmesh.
---@param obstacle cc.NavMeshObstacle
function NavMesh:addNavMeshObstacle(obstacle) end

---Create navmesh
---@param navFilePath string # The NavMesh File path.
---@param geomFilePath string # The geometry File Path,include offmesh information,etc.
---@return cc.NavMesh
function NavMesh.create(navFilePath, geomFilePath) end

---Internal method, the updater of debug drawing, need called each frame.
---@param renderer cc.Renderer
function NavMesh:debugDraw(renderer) end

---find a path on navmesh
---@param start cc.Vec3 # The start search position in world coordinate system.
---\param end The end search position in world coordinate system.
---@param pathPoints cc.Vec3[] # the key points of path.
---@param end_ cc.Vec3
function NavMesh:findPath(start, end_, pathPoints) end

---Check enabled debug draw.
---@return boolean
function NavMesh:isDebugDrawEnabled() end

---@return cc.NavMesh
function NavMesh.new() end

---remove a agent from navmesh.
---@param agent cc.NavMeshAgent
function NavMesh:removeNavMeshAgent(agent) end

---remove a obstacle from navmesh.
---@param obstacle cc.NavMeshObstacle
function NavMesh:removeNavMeshObstacle(obstacle) end

---Enable debug draw or disable.
---@param enable boolean
function NavMesh:setDebugDrawEnable(enable) end

---update navmesh.
---@param dt number
function NavMesh:update(dt) end

return NavMesh