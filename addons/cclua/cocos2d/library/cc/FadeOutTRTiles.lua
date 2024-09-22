---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.FadeOutTRTiles

---FadeOutTRTiles action.
---\details Fades out the target node with many tiles from Bottom-Left to Top-Right.
---@class cc.FadeOutTRTiles : cc.TiledGrid3DAction
local FadeOutTRTiles = {}

---Create the action with the grid size and the duration.
---@param duration number # Specify the duration of the FadeOutTRTiles action. It's a value in seconds.
---@param gridSize cc.Size # Specify the size of the grid.
---@return cc.FadeOutTRTiles # If the creation success, return a pointer of FadeOutTRTiles action; otherwise, return nil.
function FadeOutTRTiles.create(duration, gridSize) end

---Calculate the percentage a tile should be shown.
---@param pos cc.Size # The position index of the tile.
---@param time number # The current percentage of the action.
---@return number # Return the percentage the tile should be shown.
function FadeOutTRTiles:testFunc(pos, time) end

---Show part of the tile.
---@param pos cc.Vec2 # The position index of the tile should be shown.
---@param distance number # The percentage that the tile should be shown.
function FadeOutTRTiles:transformTile(pos, distance) end

---Hide the tile at specified position.
---@param pos cc.Vec2 # The position index of the tile should be hide.
function FadeOutTRTiles:turnOffTile(pos) end

---Show the tile at specified position.
---@param pos cc.Vec2 # The position index of the tile should be shown.
function FadeOutTRTiles:turnOnTile(pos) end

return FadeOutTRTiles