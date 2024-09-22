---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.SplitCols

---SplitCols action.
---\details Split the target node in many columns.
---Then move out some columns from top, move out the other columns from bottom.
---@class cc.SplitCols : cc.TiledGrid3DAction
local SplitCols = {}

---Create the action with the number of columns and the duration.
---@param duration number # Specify the duration of the SplitCols action. It's a value in seconds.
---@param cols integer # Specify the columns count should be split.
---@return cc.SplitCols # If the creation success, return a pointer of SplitCols action; otherwise, return nil.
function SplitCols.create(duration, cols) end

return SplitCols