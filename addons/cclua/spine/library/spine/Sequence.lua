---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.Sequence

---
---@class spine.Sequence : spine.SpineObject
---@field digits integer 
---@field id integer 
---@field regions any 
---@field setupIndex integer 
---@field start integer 
local Sequence = {}

---@param slot spine.Slot
---@param attachment spine.Attachment
function Sequence:apply(slot, attachment) end

---@return spine.Sequence
function Sequence:copy() end

---@return integer
function Sequence:getDigits() end

---@return integer
function Sequence:getId() end

---@param basePath any
---@param index integer
---@return any
function Sequence:getPath(basePath, index) end

---@return any
function Sequence:getRegions() end

---@return integer
function Sequence:getSetupIndex() end

---@return integer
function Sequence:getStart() end

---@param count integer
---@return spine.Sequence
function Sequence.new(count) end

---@param digits integer
function Sequence:setDigits(digits) end

---@param id integer
function Sequence:setId(id) end

---@param setupIndex integer
function Sequence:setSetupIndex(setupIndex) end

---@param start integer
function Sequence:setStart(start) end

return Sequence