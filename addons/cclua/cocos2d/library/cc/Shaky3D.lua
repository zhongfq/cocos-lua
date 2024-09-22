---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Shaky3D

---Shaky3D action.
---\details This action is used for take effect on the target node as shaky.
---You can create the action by these parameters:
---duration, grid size, range, whether shake on the z axis.
---@class cc.Shaky3D : cc.Grid3DAction
local Shaky3D = {}

---Create the action with a range, shake Z vertices, a grid and duration.
---@param initWithDuration number # Specify the duration of the Shaky3D action. It's a value in seconds.
---@param gridSize cc.Size # Specify the size of the grid.
---@param range integer # Specify the range of the shaky effect.
---@param shakeZ boolean # Specify whether shake on the z axis.
---@return cc.Shaky3D # If the creation success, return a pointer of Shaky3D action; otherwise, return nil.
function Shaky3D.create(initWithDuration, gridSize, range, shakeZ) end

return Shaky3D