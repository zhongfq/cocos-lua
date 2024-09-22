---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TiledGrid3DAction

---Base class for TiledGrid3D actions.
---@class cc.TiledGrid3DAction : cc.GridAction
local TiledGrid3DAction = {}

---Create the action with size and duration.
---@param duration number # The duration of the action. It's a value in seconds.
---@param gridSize cc.Size # Specify the grid size of the action.
---@return cc.TiledGrid3DAction # A pointer of TiledGrid3DAction. If creation failed, return nil.
---\lua NA
function TiledGrid3DAction.create(duration, gridSize) end

---Get the non-transformed tile that belongs to a certain position of the grid.
---@param position cc.Vec2 # The position of the tile want to get.
---@return cc.Quad3 # A quadrilateral of the tile. 
---\js originalTile
---\lua NA
function TiledGrid3DAction:getOriginalTile(position) end

---Get the tile that belongs to a certain position of the grid.
---@param position cc.Vec2 # The position of the tile want to get.
---@return cc.Quad3 # A quadrilateral of the tile. 
---\js tile
---\lua NA
function TiledGrid3DAction:getTile(position) end

---Set a new tile to a certain position of the grid.
---@param position cc.Vec2 # The position of the tile.
---@param coords cc.Quad3 # The quadrilateral of the new tile.
---\lua NA
function TiledGrid3DAction:setTile(position, coords) end

return TiledGrid3DAction