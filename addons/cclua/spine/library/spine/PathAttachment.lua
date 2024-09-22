---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.PathAttachment

---
---@class spine.PathAttachment : spine.VertexAttachment
---@field closed boolean 
---@field color any 
---@field constantSpeed boolean 
---@field lengths any The length in the setup pose from the start of the path to the end of each curve.
local PathAttachment = {}

---@return any
function PathAttachment:getColor() end

---The length in the setup pose from the start of the path to the end of each curve.
---@return any
function PathAttachment:getLengths() end

---@return boolean
function PathAttachment:isClosed() end

---@return boolean
function PathAttachment:isConstantSpeed() end

---@param name any
---@return spine.PathAttachment
function PathAttachment.new(name) end

---@param inValue boolean
function PathAttachment:setClosed(inValue) end

---@param inValue boolean
function PathAttachment:setConstantSpeed(inValue) end

return PathAttachment