---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.NavMeshAgent

---NavMeshAgent: The code wrapping of dtCrowdAgent, use component mode.
---@class cc.NavMeshAgent : cc.Component
---@field currentOffMeshLinkData cc.OffMeshLinkData Get current OffMeshLink information
---@field currentVelocity cc.Vec3 get current velocity
---@field height number get agent height
---@field maxAcceleration number get maximal acceleration of agent
---@field maxSpeed number get maximal speed of agent
---@field navMeshAgentComponentName string 
---@field obstacleAvoidanceType integer get obstacle avoidance type
---@field onOffMeshLink boolean Check agent arrived OffMeshLink
---@field radius number get agent radius
---@field separationWeight number get separation weight
---@field syncFlag cc.NavMeshAgent.NavMeshAgentSyncFlag 
---@field userData any 
---@field velocity cc.Vec3 get current velocity
local NavMeshAgent = {}

---Traverse OffMeshLink manually
function NavMeshAgent:completeOffMeshLink() end

---Create agent
---@param param cc.NavMeshAgentParam # The parameters of agent.
---@return cc.NavMeshAgent
function NavMeshAgent.create(param) end

---Get current OffMeshLink information
---@return cc.OffMeshLinkData
function NavMeshAgent:getCurrentOffMeshLinkData() end

---get current velocity
---@return cc.Vec3
function NavMeshAgent:getCurrentVelocity() end

---get agent height
---@return number
function NavMeshAgent:getHeight() end

---get maximal acceleration of agent
---@return number
function NavMeshAgent:getMaxAcceleration() end

---get maximal speed of agent
---@return number
function NavMeshAgent:getMaxSpeed() end

---@return string
function NavMeshAgent.getNavMeshAgentComponentName() end

---get obstacle avoidance type
---@return integer
function NavMeshAgent:getObstacleAvoidanceType() end

---get agent radius
---@return number
function NavMeshAgent:getRadius() end

---get separation weight
---@return number
function NavMeshAgent:getSeparationWeight() end

---@return cc.NavMeshAgent.NavMeshAgentSyncFlag
function NavMeshAgent:getSyncFlag() end

---@return any
function NavMeshAgent:getUserData() end

---get current velocity
---@return cc.Vec3
function NavMeshAgent:getVelocity() end

---Check agent arrived OffMeshLink
---@return boolean
function NavMeshAgent:isOnOffMeshLink() end

---Move agent to a destination
---@param destination cc.Vec3 # The position in world coordinate system.
---@param callback fun(arg1: cc.NavMeshAgent, arg2: number) # Use this function can catch movement state.
---@overload fun(self: cc.NavMeshAgent, destination: cc.Vec3)
function NavMeshAgent:move(destination, callback) end

---@return cc.NavMeshAgent
function NavMeshAgent.new() end

---pause movement
function NavMeshAgent:pause() end

---resume movement
function NavMeshAgent:resume() end

---Set automatic Orientation
---@param isAuto boolean
function NavMeshAgent:setAutoOrientation(isAuto) end

---Set automatic Traverse OffMeshLink
---@param isAuto boolean
function NavMeshAgent:setAutoTraverseOffMeshLink(isAuto) end

---set agent height
---@param height number
function NavMeshAgent:setHeight(height) end

---set maximal acceleration of agent
---@param maxAcceleration number
function NavMeshAgent:setMaxAcceleration(maxAcceleration) end

---set maximal speed of agent
---@param maxSpeed number
function NavMeshAgent:setMaxSpeed(maxSpeed) end

---set obstacle avoidance type
---@param type integer
function NavMeshAgent:setObstacleAvoidanceType(type) end

---Set the reference axes of agent's orientation
---@param rotRefAxes cc.Vec3 # The value of reference axes in local coordinate system.
function NavMeshAgent:setOrientationRefAxes(rotRefAxes) end

---set agent radius
---@param radius number
function NavMeshAgent:setRadius(radius) end

---set separation weight
---@param weight number
function NavMeshAgent:setSeparationWeight(weight) end

---synchronization between node and agent is time consuming, you can skip some synchronization using this function
---@param flag cc.NavMeshAgent.NavMeshAgentSyncFlag
function NavMeshAgent:setSyncFlag(flag) end

---@param data any
function NavMeshAgent:setUserData(data) end

---stop movement
function NavMeshAgent:stop() end

---synchronize parameter to agent.
function NavMeshAgent:syncToAgent() end

---synchronize parameter to node.
function NavMeshAgent:syncToNode() end

return NavMeshAgent