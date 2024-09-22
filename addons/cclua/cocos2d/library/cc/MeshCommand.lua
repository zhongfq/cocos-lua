---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.MeshCommand

---
---@class cc.MeshCommand : cc.CustomCommand
local MeshCommand = {}

---Init function. The render command will be in 2D mode.
---@param globalZOrder number # GlobalZOrder of the render command.
---@overload fun(self: cc.MeshCommand, globalZOrder: number, transform: cc.Mat4)
function MeshCommand:init(globalZOrder) end

---@return cc.MeshCommand
function MeshCommand.new() end

return MeshCommand