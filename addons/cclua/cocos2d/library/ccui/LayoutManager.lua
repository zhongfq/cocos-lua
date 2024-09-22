---AUTO GENERATED, DO NOT MODIFY!
---@meta ccui.LayoutManager

---Base class for managing layout.
---All the concrete layout manager should inherit from this class.
---@class ccui.LayoutManager : cc.Ref
local LayoutManager = {}

---The interface does the actual layouting work.
---@param layout ccui.LayoutProtocol
function LayoutManager:doLayout(layout) end

return LayoutManager