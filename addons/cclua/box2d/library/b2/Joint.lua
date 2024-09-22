---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.Joint

---The base joint class. Joints are used to constraint two bodies together in
---various fashions. Some joints also feature limits and motors.
---@class b2.Joint 
---@field anchorA b2.Vec2 Get the anchor point on bodyA in world coordinates.
---@field anchorB b2.Vec2 Get the anchor point on bodyB in world coordinates.
---@field bodyA b2.Body Get the first body attached to this joint.
---@field bodyB b2.Body Get the second body attached to this joint.
---@field collideConnected boolean Get collide connected. Note: modifying the collide connect flag won't work correctly because the flag is only checked when fixture AABBs begin to overlap.
---@field enabled boolean Short-cut function to determine if either body is enabled.
---@field next b2.Joint Get the next joint the world joint list.
---@field type b2.JointType Get the type of the concrete joint.
---@field userData b2.JointUserData Get the user data pointer.
local Joint = {}

---Debug draw this joint
---@param draw b2.interface.Draw
function Joint:draw(draw) end

---Dump this joint to the log file.
function Joint:dump() end

---Get the anchor point on bodyA in world coordinates.
---@return b2.Vec2
function Joint:getAnchorA() end

---Get the anchor point on bodyB in world coordinates.
---@return b2.Vec2
function Joint:getAnchorB() end

---Get the first body attached to this joint.
---@return b2.Body
function Joint:getBodyA() end

---Get the second body attached to this joint.
---@return b2.Body
function Joint:getBodyB() end

---Get collide connected.
---Note: modifying the collide connect flag won't work correctly because
---the flag is only checked when fixture AABBs begin to overlap.
---@return boolean
function Joint:getCollideConnected() end

---Get the next joint the world joint list.
---@return b2.Joint
function Joint:getNext() end

---Get the reaction force on bodyB at the joint anchor in Newtons.
---@param inv_dt number
---@return b2.Vec2
function Joint:getReactionForce(inv_dt) end

---Get the reaction torque on bodyB in N*m.
---@param inv_dt number
---@return number
function Joint:getReactionTorque(inv_dt) end

---Get the type of the concrete joint.
---@return b2.JointType
function Joint:getType() end

---Get the user data pointer.
---@return b2.JointUserData
function Joint:getUserData() end

---Short-cut function to determine if either body is enabled.
---@return boolean
function Joint:isEnabled() end

---Shift the origin for any points stored in world coordinates.
---@param newOrigin b2.Vec2
function Joint:shiftOrigin(newOrigin) end

return Joint