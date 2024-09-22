---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Grid3D

---Grid3D is a 3D grid implementation. Each vertex has 3 dimensions: x,y,z
---@class cc.Grid3D : cc.GridBase
---@field needDepthTestForBlit boolean 
local Grid3D = {}

---create one Grid.
---@param gridSize cc.Size
---@return cc.Grid3D
---@overload fun(gridSize: cc.Size, rect: cc.Rect): cc.Grid3D
---@overload fun(gridSize: cc.Size, texture: cc.Texture2D, flipped: boolean): cc.Grid3D
---@overload fun(gridSize: cc.Size, texture: cc.Texture2D, flipped: boolean, rect: cc.Rect): cc.Grid3D
function Grid3D.create(gridSize) end

---@return boolean
function Grid3D:getNeedDepthTestForBlit() end

---Returns the original (non-transformed) vertex at a given position.
---\js NA
---\lua NA
---@param pos cc.Vec2
---@return cc.Vec3
function Grid3D:getOriginalVertex(pos) end

---Returns the vertex at a given position.
---\js NA
---\lua NA
---@param pos cc.Vec2
---@return cc.Vec3
function Grid3D:getVertex(pos) end

---\{
---Getter and Setter for depth test state when blit.
---\js NA
---@param neededDepthTest boolean
function Grid3D:setNeedDepthTestForBlit(neededDepthTest) end

---Sets a new vertex at a given position.
---\lua NA
---@param pos cc.Vec2
---@param vertex cc.Vec3
function Grid3D:setVertex(pos, vertex) end

return Grid3D