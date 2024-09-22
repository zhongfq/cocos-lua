---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.JumpTo

---\class JumpTo
---Moves a Node object to a parabolic position simulating a jump movement by modifying it's position attribute.
---@class cc.JumpTo : cc.JumpBy
local JumpTo = {}

---Creates the action.
---@param duration number # Duration time, in seconds.
---@param position cc.Vec2 # The jumping destination position.
---@param height number # The jumping height.
---@param jumps integer # The jumping times.
---@return cc.JumpTo # An autoreleased JumpTo object.
---@overload fun(duration: number, x: number, y: number, height: number, jumps: integer): cc.JumpTo
function JumpTo.create(duration, position, height, jumps) end

return JumpTo