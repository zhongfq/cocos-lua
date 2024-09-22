---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.GearJointDef

---Gear joint definition. This definition requires two existing
---revolute or prismatic joints (any combination will work).
---\warning bodyB on the input joints must both be dynamic
---@class b2.GearJointDef : b2.JointDef
---@field joint1 b2.Joint
---@field joint2 b2.Joint
---@field ratio number
local GearJointDef = {}

---@return b2.GearJointDef
function GearJointDef.new() end

return GearJointDef