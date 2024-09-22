---AUTO GENERATED, DO NOT MODIFY!
---@meta cc.Ref

---\addtogroup base
---\{
---@class cc.Ref 
---@field referenceCount integer Returns the Ref's current reference count. <br><br>\returns The Ref's reference count. \js NA
local Ref = {}

---@return any
function Ref:__gc() end

---Returns the Ref's current reference count.
---
---@return integer # s The Ref's reference count.
---\js NA
function Ref:getReferenceCount() end

return Ref