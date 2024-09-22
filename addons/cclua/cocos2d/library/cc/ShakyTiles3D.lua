---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.ShakyTiles3D

---ShakyTiles3D action.
---\details This action is make the target node shake with many tiles.
---You can create the action by these parameters:
---duration, grid size, range, whether shake on the z axis.
---@class cc.ShakyTiles3D : cc.TiledGrid3DAction
local ShakyTiles3D = {}

---Create the action with a range, shake Z vertices, a grid and duration.
---@param duration number # Specify the duration of the ShakyTiles3D action. It's a value in seconds.
---@param gridSize cc.Size # Specify the size of the grid.
---@param range integer # Specify the range of the shaky effect.
---@param shakeZ boolean # Specify whether shake on the z axis.
---@return cc.ShakyTiles3D # If the creation success, return a pointer of ShakyTiles3D action; otherwise, return nil.
function ShakyTiles3D.create(duration, gridSize, range, shakeZ) end

return ShakyTiles3D