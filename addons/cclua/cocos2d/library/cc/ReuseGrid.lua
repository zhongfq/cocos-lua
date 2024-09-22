---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.ReuseGrid

---ReuseGrid action.
---@class cc.ReuseGrid : cc.ActionInstant
local ReuseGrid = {}

---Create an action with the number of times that the current grid will be reused.
---@param times integer # Specify times the grid will be reused.
---@return cc.ReuseGrid # Return a pointer of ReuseGrid. When the creation failed, return nil.
function ReuseGrid.create(times) end

---Initializes an action with the number of times that the current grid will be reused.
---@param times integer # Specify times the grid will be reused.
---@return boolean # If the initialization success, return true; otherwise, return false.
function ReuseGrid:initWithTimes(times) end

return ReuseGrid