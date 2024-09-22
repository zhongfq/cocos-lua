---AUTO GENERATED, DO NOT MODIFY!
---@meta spine.Slot

---
---@class spine.Slot : spine.SpineObject
---@field attachment spine.Attachment May be NULL.
---@field attachmentState integer 
---@field bone spine.Bone 
---@field color any 
---@field darkColor any 
---@field data spine.SlotData 
---@field deform any 
---@field sequenceIndex integer 
---@field skeleton spine.Skeleton 
local Slot = {}

---May be NULL.
---@return spine.Attachment
function Slot:getAttachment() end

---@return integer
function Slot:getAttachmentState() end

---@return spine.Bone
function Slot:getBone() end

---@return any
function Slot:getColor() end

---@return any
function Slot:getDarkColor() end

---@return spine.SlotData
function Slot:getData() end

---@return any
function Slot:getDeform() end

---@return integer
function Slot:getSequenceIndex() end

---@return spine.Skeleton
function Slot:getSkeleton() end

---@return boolean
function Slot:hasDarkColor() end

---@param data spine.SlotData
---@param bone spine.Bone
---@return spine.Slot
function Slot.new(data, bone) end

---@param inValue spine.Attachment
function Slot:setAttachment(inValue) end

---@param state integer
function Slot:setAttachmentState(state) end

---@param index integer
function Slot:setSequenceIndex(index) end

function Slot:setToSetupPose() end

return Slot