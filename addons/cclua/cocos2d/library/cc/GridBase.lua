---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.GridBase

---Base class for Other grid.
---@class cc.GridBase : cc.Ref
---@field active boolean \}*/ \{ Getter and setter of the active state of the grid.
---@field gridRect cc.Rect Get the effect grid rect. \return Return the effect grid rect.
---@field gridSize cc.Size Size of the grid.
---@field reuseGrid integer Get number of times that the grid will be reused.
---@field step cc.Vec2 Pixels between the grids.
---@field textureFlipped boolean is texture flipped.
local GridBase = {}

function GridBase:afterBlit() end

---@param target cc.Node
function GridBase:afterDraw(target) end

---\{
---Interface for custom action when before or after draw.
---\js NA
function GridBase:beforeBlit() end

---\{
---Init and reset the status when render effects by using the grid.
function GridBase:beforeDraw() end

---Interface used to blit the texture with grid to screen.
function GridBase:blit() end

---Interface, Calculate the vertices used for the blit.
function GridBase:calculateVertexPoints() end

---Get the effect grid rect.
---@return cc.Rect # Return the effect grid rect.
function GridBase:getGridRect() end

---Size of the grid.
---@return cc.Size
function GridBase:getGridSize() end

---Get number of times that the grid will be reused.
---@return integer
function GridBase:getReuseGrid() end

---Pixels between the grids.
---@return cc.Vec2
function GridBase:getStep() end

---\{
---Init the Grid base.
---@param gridSize cc.Size # the size of the grid.
---\param texture The texture used for grab.
---\param flipped whether or not the grab texture should be flip by Y or not.
---\param rect The effective grid rect.
---@return boolean
---@overload fun(self: cc.GridBase, gridSize: cc.Size, rect: cc.Rect): boolean
---@overload fun(self: cc.GridBase, gridSize: cc.Size, texture: cc.Texture2D, flipped: boolean): boolean
---@overload fun(self: cc.GridBase, gridSize: cc.Size, texture: cc.Texture2D, flipped: boolean, rect: cc.Rect): boolean
function GridBase:initWithSize(gridSize) end

---\}*/
---\{
---Getter and setter of the active state of the grid.
---@return boolean
function GridBase:isActive() end

---is texture flipped.
---@return boolean
function GridBase:isTextureFlipped() end

---Interface, Reuse the grid vertices.
function GridBase:reuse() end

---Change projection to 2D for grabbing.
function GridBase:set2DProjection() end

---@param active boolean
function GridBase:setActive(active) end

---Set the effect grid rect.
---@param rect cc.Rect # The effect grid rect.
function GridBase:setGridRect(rect) end

---Set the size of the grid.
---@param gridSize cc.Size
function GridBase:setGridSize(gridSize) end

---Set number of times that the grid will be reused.
---@param reuseGrid integer
function GridBase:setReuseGrid(reuseGrid) end

---Get the pixels between the grids.
---@param step cc.Vec2
function GridBase:setStep(step) end

---Set the texture flipped or not.
---@param flipped boolean
function GridBase:setTextureFlipped(flipped) end

return GridBase