---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Clonable

---Interface that defines how to clone an Ref.
---\lua NA
---\js NA
---@class cc.Clonable 
local Clonable = {}

---@return any
function Clonable:__gc() end

---Returns a copy of the Ref.
---@return cc.Clonable
function Clonable:clone() end

return Clonable