---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.SplitRows

---SplitRows action.
---\details Split the target node in many rows.
---Then move out some rows from left, move out the other rows from right.
---@class cc.SplitRows : cc.TiledGrid3DAction
local SplitRows = {}

---Create the action with the number of rows and the duration.
---@param duration number # Specify the duration of the SplitRows action. It's a value in seconds.
---@param rows integer # Specify the rows count should be split.
---@return cc.SplitRows # If the creation success, return a pointer of SplitRows action; otherwise, return nil.
function SplitRows.create(duration, rows) end

return SplitRows