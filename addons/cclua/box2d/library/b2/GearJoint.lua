---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.GearJoint

---A gear joint is used to connect two joints together. Either joint
---can be a revolute or prismatic joint. You specify a gear ratio
---to bind the motions together:
---coordinate1 + ratio * coordinate2 = constant
---The ratio can be negative or positive. If one joint is a revolute joint
---and the other joint is a prismatic joint, then the ratio will have units
---of length or units of 1/length.
---\warning You have to manually destroy the gear joint if joint1 or joint2
---is destroyed.
---@class b2.GearJoint : b2.Joint
---@field joint1 b2.Joint Get the first joint.
---@field joint2 b2.Joint Get the second joint.
---@field ratio number 
local GearJoint = {}

---@return any
function GearJoint:__gc() end

---Get the first joint.
---@return b2.Joint
function GearJoint:getJoint1() end

---Get the second joint.
---@return b2.Joint
function GearJoint:getJoint2() end

---@return number
function GearJoint:getRatio() end

---Set/Get the gear ratio.
---@param ratio number
function GearJoint:setRatio(ratio) end

return GearJoint