---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.TiledGrid3D

---TiledGrid3D is a 3D grid implementation. It differs from Grid3D in that
---the tiles can be separated from the grid.
---@class cc.TiledGrid3D : cc.GridBase
local TiledGrid3D = {}

---Create one Grid.
---@param gridSize cc.Size
---@return cc.TiledGrid3D
---@overload fun(gridSize: cc.Size, rect: cc.Rect): cc.TiledGrid3D
---@overload fun(gridSize: cc.Size, texture: cc.Texture2D, flipped: boolean): cc.TiledGrid3D
---@overload fun(gridSize: cc.Size, texture: cc.Texture2D, flipped: boolean, rect: cc.Rect): cc.TiledGrid3D
function TiledGrid3D.create(gridSize) end

---Returns the original tile (untransformed) at the given position.
---\js NA
---\lua NA
---@param pos cc.Vec2
---@return cc.Quad3
function TiledGrid3D:getOriginalTile(pos) end

---Returns the tile at the given position.
---\js NA
---\lua NA
---@param pos cc.Vec2
---@return cc.Quad3
function TiledGrid3D:getTile(pos) end

---Sets a new tile.
---\lua NA
---@param pos cc.Vec2
---@param coords cc.Quad3
function TiledGrid3D:setTile(pos, coords) end

return TiledGrid3D