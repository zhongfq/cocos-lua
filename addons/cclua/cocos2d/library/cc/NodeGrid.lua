---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.NodeGrid

---Base class for Grid Node.
---@class cc.NodeGrid : cc.Node
---@field grid cc.GridBase Get a Grid Node.  <br><br>\return Return a GridBase.
---@field gridRect cc.Rect Get the effect grid rect. \return Return the effect grid rect.
local NodeGrid = {}

---Create a Grid Node.
---
---@return cc.NodeGrid # An autorelease Grid Node.
---@overload fun(rect: cc.Rect): cc.NodeGrid
function NodeGrid.create() end

---Get a Grid Node. 
---
---@return cc.GridBase # Return a GridBase.
function NodeGrid:getGrid() end

---Get the effect grid rect.
---@return cc.Rect # Return the effect grid rect.
function NodeGrid:getGridRect() end

---Changes a grid object that is used when applying effects.
---
---@param grid cc.GridBase # A Grid object that is used when applying effects.
function NodeGrid:setGrid(grid) end

---Set the effect grid rect.
---@param gridRect cc.Rect # The effect grid rect.
function NodeGrid:setGridRect(gridRect) end

---Set the Grid Target. 
---
---@param target cc.Node # A Node is used to set the Grid Target.
function NodeGrid:setTarget(target) end

return NodeGrid