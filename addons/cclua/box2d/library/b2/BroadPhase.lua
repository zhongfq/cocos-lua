---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.BroadPhase

---The broad-phase is used for computing pairs and performing volume queries and ray casts.
---This broad-phase does not persist pairs. Instead, this reports potentially new pairs.
---It is up to the client to consume the new pairs and to track subsequent overlap.
---@class b2.BroadPhase 
---@field proxyCount integer Get the number of proxies.
---@field treeBalance integer Get the balance of the embedded tree.
---@field treeHeight integer Get the height of the embedded tree.
---@field treeQuality number Get the quality metric of the embedded tree.
local BroadPhase = {}

---@return any
function BroadPhase:__gc() end

---Create a proxy with an initial AABB. Pairs are not reported until
---UpdatePairs is called.
---@param aabb b2.AABB
---@param userData any
---@return integer
function BroadPhase:createProxy(aabb, userData) end

---Destroy a proxy. It is up to the client to remove any pairs.
---@param proxyId integer
function BroadPhase:destroyProxy(proxyId) end

---Get the fat AABB for a proxy.
---@param proxyId integer
---@return b2.AABB
function BroadPhase:getFatAABB(proxyId) end

---Get the number of proxies.
---@return integer
function BroadPhase:getProxyCount() end

---Get the balance of the embedded tree.
---@return integer
function BroadPhase:getTreeBalance() end

---Get the height of the embedded tree.
---@return integer
function BroadPhase:getTreeHeight() end

---Get the quality metric of the embedded tree.
---@return number
function BroadPhase:getTreeQuality() end

---Get user data from a proxy. Returns nullptr if the id is invalid.
---@param proxyId integer
---@return any
function BroadPhase:getUserData(proxyId) end

---Call MoveProxy as many times as you like, then when you are done
---call UpdatePairs to finalized the proxy pairs (for your time step).
---@param proxyId integer
---@param aabb b2.AABB
---@param displacement b2.Vec2
function BroadPhase:moveProxy(proxyId, aabb, displacement) end

---@return b2.BroadPhase
function BroadPhase.new() end

---Shift the world origin. Useful for large worlds.
---The shift formula is: position -= newOrigin
---@param newOrigin b2.Vec2 # the new origin with respect to the old origin
function BroadPhase:shiftOrigin(newOrigin) end

---Test overlap of fat AABBs.
---@param proxyIdA integer
---@param proxyIdB integer
---@return boolean
function BroadPhase:testOverlap(proxyIdA, proxyIdB) end

---Call to trigger a re-processing of it's pairs on the next call to UpdatePairs.
---@param proxyId integer
function BroadPhase:touchProxy(proxyId) end

return BroadPhase