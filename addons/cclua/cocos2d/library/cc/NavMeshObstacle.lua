---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.NavMeshObstacle

---NavMeshObstacle: The code wrapping of dtTileCacheObstacle, use component mode.
---@class cc.NavMeshObstacle : cc.Component
---@field height number Get height of obstacle
---@field navMeshObstacleComponentName string 
---@field radius number Get radius of obstacle
---@field syncFlag cc.NavMeshObstacle.NavMeshObstacleSyncFlag 
local NavMeshObstacle = {}

---Create obstacle, shape is cylinder
---@param radius number # The radius of obstacle.
---@param height number # The height of obstacle.
---@return cc.NavMeshObstacle
function NavMeshObstacle.create(radius, height) end

---Get height of obstacle
---@return number
function NavMeshObstacle:getHeight() end

---@return string
function NavMeshObstacle.getNavMeshObstacleComponentName() end

---Get radius of obstacle
---@return number
function NavMeshObstacle:getRadius() end

---@return cc.NavMeshObstacle.NavMeshObstacleSyncFlag
function NavMeshObstacle:getSyncFlag() end

---@param radius number
---@param height number
---@return boolean
function NavMeshObstacle:initWith(radius, height) end

---@return cc.NavMeshObstacle
function NavMeshObstacle.new() end

---Set height of obstacle
---@param height number
function NavMeshObstacle:setHeight(height) end

---Set radius of obstacle
---@param radius number
function NavMeshObstacle:setRadius(radius) end

---synchronization between node and obstacle is time consuming, you can skip some synchronization using this function
---@param flag cc.NavMeshObstacle.NavMeshObstacleSyncFlag
function NavMeshObstacle:setSyncFlag(flag) end

---synchronize parameter to node.
function NavMeshObstacle:syncToNode() end

---synchronize parameter to obstacle.
function NavMeshObstacle:syncToObstacle() end

return NavMeshObstacle