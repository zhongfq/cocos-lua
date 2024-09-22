---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.JointEdge

---A joint edge is used to connect bodies and joints together
---in a joint graph where each body is a node and each joint
---is an edge. A joint edge belongs to a doubly linked list
---maintained in each attached body. Each joint has two joint
---nodes, one for each attached body.
---@class b2.JointEdge 
---@field other b2.Body
---@field joint b2.Joint
---@field prev b2.JointEdge
---@field next b2.JointEdge
local JointEdge = {}

---@return any
function JointEdge:__gc() end

return JointEdge