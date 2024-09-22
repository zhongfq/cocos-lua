---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.JumpBy

---\class JumpBy
---Moves a Node object simulating a parabolic jump movement by modifying it's position attribute.
---@class cc.JumpBy : cc.ActionInterval
local JumpBy = {}

---Creates the action.
---@param duration number # Duration time, in seconds.
---@param position cc.Vec2 # The jumping distance.
---@param height number # The jumping height.
---@param jumps integer # The jumping times.
---@return cc.JumpBy # An autoreleased JumpBy object.
---@overload fun(duration: number, x: number, y: number, height: number, jumps: integer): cc.JumpBy
function JumpBy.create(duration, position, height, jumps) end

return JumpBy