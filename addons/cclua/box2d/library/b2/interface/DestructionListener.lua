---AUTO GENERATED, DO NOT MODIFY!
---@meta b2.interface.DestructionListener

---Joints and fixtures are destroyed when their associated
---body is destroyed. Implement this listener so that you
---may nullify references to these joints and shapes.
---@class b2.interface.DestructionListener 
local DestructionListener = {}

---@return any
function DestructionListener:__gc() end

return DestructionListener