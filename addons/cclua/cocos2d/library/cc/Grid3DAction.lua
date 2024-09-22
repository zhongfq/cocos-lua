---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Grid3DAction

---Base class for Grid3D actions.
---\details Grid3D actions can modify a non-tiled grid.
---@class cc.Grid3DAction : cc.GridAction
---@field gridRect cc.Rect Get the effect grid rect. \return Return the effect grid rect.
local Grid3DAction = {}

---Get the effect grid rect.
---@return cc.Rect # Return the effect grid rect.
function Grid3DAction:getGridRect() end

---Get the non-transformed vertex that belongs to certain position in the grid.
---@param position cc.Vec2 # The position of the grid.
---@return cc.Vec3 # Return a pointer of vertex.
---\js originalVertex
---\lua NA
function Grid3DAction:getOriginalVertex(position) end

---Get the vertex that belongs to certain position in the grid.
---@param position cc.Vec2 # The position of the grid.
---@return cc.Vec3 # Return a pointer of vertex.
---\js vertex
---\lua NA
function Grid3DAction:getVertex(position) end

---Set a new vertex to a certain position of the grid.
---@param position cc.Vec2 # The position of the grid.
---@param vertex cc.Vec3 # The vertex will be used on the certain position of grid.
---\js setVertex
---\lua NA
function Grid3DAction:setVertex(position, vertex) end

return Grid3DAction