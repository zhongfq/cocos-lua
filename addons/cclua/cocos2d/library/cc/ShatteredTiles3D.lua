---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.ShatteredTiles3D

---ShatteredTiles3D action.
---\details This action make the target node shattered with many tiles.
---You can create the action by these parameters:
---duration, grid size, range, whether shatter on the z axis.
---@class cc.ShatteredTiles3D : cc.TiledGrid3DAction
local ShatteredTiles3D = {}

---Create the action with a range, whether of not to shatter Z vertices, grid size and duration.
---@param duration number # Specify the duration of the ShatteredTiles3D action. It's a value in seconds.
---@param gridSize cc.Size # Specify the size of the grid.
---@param range integer # Specify the range of the shatter effect.
---@param shatterZ boolean # Specify whether shatter on the z axis.
---@return cc.ShatteredTiles3D # If the creation success, return a pointer of ShatteredTiles3D action; otherwise, return nil.
function ShatteredTiles3D.create(duration, gridSize, range, shatterZ) end

return ShatteredTiles3D