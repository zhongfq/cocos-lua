---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TurnOffTiles

---TurnOffTiles action.
---\details Turn off the target node with many tiles in random order.
---@class cc.TurnOffTiles : cc.TiledGrid3DAction
local TurnOffTiles = {}

---Create the action with the grid size and the duration.
---@param duration number # Specify the duration of the TurnOffTiles action. It's a value in seconds.
---@param gridSize cc.Size # Specify the size of the grid.
---@return cc.TurnOffTiles # If the creation success, return a pointer of TurnOffTiles action; otherwise, return nil.
---
---Create the action with the grid size and the duration.
---\param duration Specify the duration of the TurnOffTiles action. It's a value in seconds.
---\param gridSize Specify the size of the grid.
---\param seed Specify the random seed.
---\return If the creation success, return a pointer of TurnOffTiles action; otherwise, return nil.
---@overload fun(duration: number, gridSize: cc.Size, seed: integer): cc.TurnOffTiles
function TurnOffTiles.create(duration, gridSize) end

---Shuffle the array specified.
---@param array olua.uint # The array will be shuffled.
---@param len integer # The size of the array.
function TurnOffTiles:shuffle(array, len) end

---Hide the tile at specified position.
---@param pos cc.Vec2 # The position index of the tile should be hide.
function TurnOffTiles:turnOffTile(pos) end

---Show the tile at specified position.
---@param pos cc.Vec2 # The position index of the tile should be shown.
function TurnOffTiles:turnOnTile(pos) end

return TurnOffTiles