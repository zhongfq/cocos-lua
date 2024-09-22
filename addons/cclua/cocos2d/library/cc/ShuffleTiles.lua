---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.ShuffleTiles

---ShuffleTiles action.
---\details This action make the target node shuffle with many tiles in random order.
---You can create the action by these parameters:
---duration, grid size, the random seed.
---@class cc.ShuffleTiles : cc.TiledGrid3DAction
local ShuffleTiles = {}

---Create the action with grid size, random seed and duration.
---@param duration number # Specify the duration of the ShuffleTiles action. It's a value in seconds.
---@param gridSize cc.Size # Specify the size of the grid.
---@param seed integer # Specify the random seed.
---@return cc.ShuffleTiles # If the creation success, return a pointer of ShuffleTiles action; otherwise, return nil.
function ShuffleTiles.create(duration, gridSize, seed) end

---@param pos cc.Size
---@return cc.Size
function ShuffleTiles:getDelta(pos) end

---@param array olua.uint
---@param len integer
function ShuffleTiles:shuffle(array, len) end

return ShuffleTiles